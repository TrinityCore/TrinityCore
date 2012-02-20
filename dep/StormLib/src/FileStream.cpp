/*****************************************************************************/
/* FileStream.cpp                         Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* File stream support for StormLib                                          */
/*                                                                           */
/* Windows support: Written by Ladislav Zezula                               */
/* Mac support:     Written by Sam Wilkins                                   */
/* Linux support:   Written by Sam Wilkins and Ivan Komissarov               */
/* Big-endian:      Written & debugged by Sam Wilkins                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 11.06.10  1.00  Lad  Derived from StormPortMac.cpp and StormPortLinux.cpp */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE ((HANDLE)-1)
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4800)              // 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
#endif

//-----------------------------------------------------------------------------
// Local structures

// Structure describing the PART file header
typedef struct _PART_FILE_HEADER
{
    DWORD PartialVersion;                   // Always set to 2
    char  GameBuildNumber[8];               // Minimum build number of the game that can use this MPQ
    DWORD Unknown0C;
    DWORD Unknown10;
    DWORD Unknown14;                        // Often contains 0x1C (size of the rest of the header ?)
    DWORD Unknown18;
    DWORD ZeroValue1C;                      // Seems to always be zero
    DWORD ZeroValue20;                      // Seems to always be zero
    DWORD ZeroValue24;                      // Seems to always be zero
    DWORD FileSizeLo;                       // Low 32 bits of the file size
    DWORD FileSizeHi;                       // High 32 bits of the file size
    DWORD BlockSize;                        // Size of one file block, in bytes

} PART_FILE_HEADER, *PPART_FILE_HEADER;

// Structure describing the block-to-file map entry
typedef struct _PART_FILE_MAP_ENTRY
{
    DWORD Flags;                            // 3 = the block is present in the file
    DWORD BlockOffsLo;                      // Low 32 bits of the block position in the file
    DWORD BlockOffsHi;                      // High 32 bits of the block position in the file
    DWORD Unknown0C;
    DWORD Unknown10;

} PART_FILE_MAP_ENTRY, *PPART_FILE_MAP_ENTRY;

struct TPartFileStream : public TFileStream
{
    ULONGLONG VirtualSize;                  // Virtual size of the file
    ULONGLONG VirtualPos;                   // Virtual position in the file
    DWORD     BlockCount;                   // Number of file blocks. Used by partial file stream
    DWORD     BlockSize;                    // Size of one block. Used by partial file stream

    PART_FILE_MAP_ENTRY PartMap[1];         // File map, variable length
};

#define MPQE_CHUNK_SIZE 0x40                // Size of one chunk to be decrypted

struct TEncryptedStream : public TFileStream
{
    BYTE Key[MPQE_CHUNK_SIZE];              // File key
};

static bool IsPartHeader(PPART_FILE_HEADER pPartHdr)
{
    // Version number must be 2
    if(pPartHdr->PartialVersion == 2)
    {
        // GameBuildNumber must be anm ASCII number
        if(isdigit(pPartHdr->GameBuildNumber[0]) && isdigit(pPartHdr->GameBuildNumber[1]) && isdigit(pPartHdr->GameBuildNumber[2]))
        {
            // Block size must be power of 2
            if((pPartHdr->BlockSize & (pPartHdr->BlockSize - 1)) == 0)
                return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
// Non-Windows support for LastError

#ifndef PLATFORM_WINDOWS
static int nLastError = ERROR_SUCCESS;

int GetLastError()
{
    return nLastError;
}

void SetLastError(int nError)
{
    nLastError = nError;
}
#endif

//-----------------------------------------------------------------------------
// Local functions - platform-specific functions

#ifndef PLATFORM_LITTLE_ENDIAN
void ConvertPartHeader(void * partHeader)
{
    PPART_FILE_HEADER theHeader = (PPART_FILE_HEADER)partHeader;

    theHeader->PartialVersion = SwapUInt32(theHeader->PartialVersion);
    theHeader->Unknown0C      = SwapUInt32(theHeader->Unknown0C);
    theHeader->Unknown10      = SwapUInt32(theHeader->Unknown10);
    theHeader->Unknown14      = SwapUInt32(theHeader->Unknown14);
    theHeader->Unknown18      = SwapUInt32(theHeader->Unknown18);
    theHeader->Unknown1C      = SwapUInt32(theHeader->Unknown1C);
    theHeader->Unknown20      = SwapUInt32(theHeader->Unknown20);
    theHeader->ZeroValue      = SwapUInt32(theHeader->ZeroValue);
    theHeader->FileSizeLo     = SwapUInt32(theHeader->FileSizeLo);
    theHeader->FileSizeHi     = SwapUInt32(theHeader->FileSizeHi);
    theHeader->BlockSize      = SwapUInt32(theHeader->BlockSize);
}
#endif

#ifdef PLATFORM_MAC
static void ConvertUTCDateTimeToFileTime(const UTCDateTimePtr inTime, ULONGLONG * pFT)
{
	UInt64 intTime = ((UInt64)inTime->highSeconds << 32) + inTime->lowSeconds;
	intTime *= 10000000;
	intTime += 0x0153b281e0fb4000ull;

    *pFT = intTime;
}

static OSErr FSOpenDFCompat(FSRef *ref, char permission, short *refNum)
{
    HFSUniStr255 forkName;
    OSErr theErr;
    Boolean isFolder, wasChanged;
    
    theErr = FSResolveAliasFile(ref, true, &isFolder, &wasChanged);
    if (theErr != noErr)
    {
        return theErr;
    }
    
    FSGetDataForkName(&forkName);
#ifdef PLATFORM_64BIT
    theErr = FSOpenFork(ref, forkName.length, forkName.unicode, permission, (FSIORefNum *)refNum);
#else
    theErr = FSOpenFork(ref, forkName.length, forkName.unicode, permission, refNum);
#endif
    return theErr;
}
#endif

#ifdef PLATFORM_LINUX
// time_t is number of seconds since 1.1.1970, UTC.
// 1 second = 10000000 (decimal) in FILETIME
static void ConvertTimeTToFileTime(ULONGLONG * pFileTime, time_t crt_time)
{
    // Set the start to 1.1.1970 00:00:00
    *pFileTime = 0x019DB1DED53E8000ULL + (10000000 * crt_time);
}
#endif

static HANDLE CreateNewFile(
    const TCHAR * szFileName)               // Name of the file to open
{
    HANDLE hFile = INVALID_HANDLE_VALUE;    // Pre-set the file handle to INVALID_HANDLE_VALUE

#ifdef PLATFORM_WINDOWS
    {
        DWORD dwShareMode = FILE_SHARE_READ;

        if(dwGlobalFlags & SFILE_FLAG_ALLOW_WRITE_SHARE)
            dwShareMode |= FILE_SHARE_WRITE;

        hFile = CreateFile(szFileName,
                           GENERIC_READ | GENERIC_WRITE,
                           dwShareMode,
                           NULL,
                           CREATE_ALWAYS,
                           0,
                           NULL);
    }
#endif

#ifdef PLATFORM_MAC
    {
        FSRef   theParentRef;
        FSRef   theFileRef;
        OSErr   theErr;
        short   fileRef;
        
        theErr = FSPathMakeRef((const UInt8 *)szFileName, &theFileRef, NULL);
        
        if (theErr == noErr)
            FSDeleteObject(&theFileRef);
        
        // Create the FSRef for the parent directory.
        UInt8 folderName[MAX_PATH];
        memset(&theFileRef, 0, sizeof(FSRef));
        CFStringRef filePathCFString = CFStringCreateWithCString(NULL, szFileName, kCFStringEncodingUTF8);
        CFURLRef fileURL = CFURLCreateWithFileSystemPath(NULL, filePathCFString, kCFURLPOSIXPathStyle, false);
        CFURLRef folderURL = CFURLCreateCopyDeletingLastPathComponent(NULL, fileURL);
        CFURLGetFileSystemRepresentation(folderURL, true, folderName, MAX_PATH);
        theErr = FSPathMakeRef(folderName, &theParentRef, NULL);
        CFRelease(fileURL);
        CFRelease(folderURL);
        
        if (theErr != noErr)
        {
            nLastError = theErr;
            return INVALID_HANDLE_VALUE;
        }
        
        // Create the file
        UniChar unicodeFileName[256];
        fileURL = CFURLCreateWithFileSystemPath(NULL, filePathCFString, kCFURLPOSIXPathStyle, false);
        CFStringRef fileNameCFString = CFURLCopyLastPathComponent(fileURL);
        CFStringGetCharacters(fileNameCFString, CFRangeMake(0, CFStringGetLength(fileNameCFString)), 
                              unicodeFileName);
        theErr = FSCreateFileUnicode(&theParentRef, CFStringGetLength(fileNameCFString), unicodeFileName, 
                                     kFSCatInfoNone, NULL, &theFileRef, NULL);
        CFRelease(fileNameCFString);
        CFRelease(filePathCFString);
        CFRelease(fileURL);
        if (theErr != noErr)
        {
            nLastError = theErr;
            return INVALID_HANDLE_VALUE;
        }

        theErr = FSOpenDFCompat(&theFileRef, fsRdWrPerm, &fileRef);
        if(theErr != noErr)
        {
            nLastError = theErr;
            return INVALID_HANDLE_VALUE;
        }

        hFile = (HANDLE)(int)fileRef;
    }
#endif

#ifdef PLATFORM_LINUX
    {
        intptr_t handle;

        handle = open(szFileName, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if(handle == -1)
        {
            nLastError = errno;
            return INVALID_HANDLE_VALUE;
        }

        hFile = (HANDLE)handle;
    }
#endif

    // Return the file handle
    return hFile;
}

static HANDLE OpenExistingFile(
    const TCHAR * szFileName,               // Name of the file to open
    bool bWriteAccess)                      // false = read-only, true = read/write
{
    HANDLE hFile = INVALID_HANDLE_VALUE;    // Pre-set the file handle to INVALID_HANDLE_VALUE

#ifdef PLATFORM_WINDOWS
    {
        DWORD dwShareMode = FILE_SHARE_READ;

        if(dwGlobalFlags & SFILE_FLAG_ALLOW_WRITE_SHARE)
            dwShareMode |= FILE_SHARE_WRITE;

        hFile = CreateFile(szFileName,
                           bWriteAccess ? (GENERIC_READ | GENERIC_WRITE) : GENERIC_READ,
                           dwShareMode,
                           NULL,
                           OPEN_EXISTING,
                           0,
                           NULL);
    }
#endif

#ifdef PLATFORM_MAC
    {
        FSRef theFileRef;
        OSErr theErr;
        short fileRef;
        char permission = bWriteAccess ? fsRdWrPerm : fsRdPerm;

        theErr = FSPathMakeRef((const UInt8 *)szFileName, &theFileRef, NULL);
        if(theErr != noErr)
        {
            nLastError = theErr;
            return INVALID_HANDLE_VALUE;
        }

        theErr = FSOpenDFCompat(&theFileRef, permission, &fileRef);
        if (theErr != noErr)
        {
            nLastError = theErr;
            return INVALID_HANDLE_VALUE;
        }

        hFile = (HANDLE)(int)fileRef;
    }
#endif

#ifdef PLATFORM_LINUX
    {
        int oflag = bWriteAccess ? O_RDWR : O_RDONLY;
        intptr_t handle;

        handle = open(szFileName, oflag | O_LARGEFILE);
        if(handle == -1)
        {
            nLastError = errno;
            return INVALID_HANDLE_VALUE;
        }

        hFile = (HANDLE)handle;
    }
#endif

    // Return the file handle
    return hFile;
}

static void CloseTheFile(HANDLE hFile)
{
#ifdef PLATFORM_WINDOWS
    CloseHandle(hFile);
#endif

#ifdef PLATFORM_MAC
    FSCloseFork((short)(long)hFile);
#endif

#ifdef PLATFORM_LINUX
    close((intptr_t)hFile);
#endif
}

/**
 * Renames a file to another name.
 * Note that the "szNewFile" file usually exists when this function is called,
 * so the function must deal with it properly
 */
static bool RenameFile(const TCHAR * szExistingFile, const TCHAR * szNewFile)
{
#ifdef PLATFORM_WINDOWS
    // Delete the original stream file. Don't check the result value,
    // because if the file doesn't exist, it would fail
    DeleteFile(szNewFile);

    // Rename the new file to the old stream's file
    return (bool)MoveFile(szExistingFile, szNewFile);
#endif

#ifdef PLATFORM_MAC
    OSErr theErr;
    FSRef fromFileRef;
    FSRef toFileRef;
    
    if (FSPathMakeRef((const UInt8 *)szNewFile, &toFileRef, NULL) == noErr)
        FSDeleteObject(&toFileRef);
    
    // Get the path to the old file
    theErr = FSPathMakeRef((const UInt8 *)szExistingFile, &fromFileRef, NULL);
    if (theErr != noErr)
    {
        nLastError = theErr;
        return false;
    }
    
    // Get a CFString for the new file name
    CFStringRef newFileNameCFString = CFStringCreateWithCString(NULL, szNewFile, kCFStringEncodingUTF8);
    CFURLRef fileURL = CFURLCreateWithFileSystemPath(NULL, newFileNameCFString, kCFURLPOSIXPathStyle, false);
    CFRelease(newFileNameCFString);
    newFileNameCFString = CFURLCopyLastPathComponent(fileURL);
    CFRelease(fileURL);
    
    // Convert CFString to Unicode and rename the file
    UniChar unicodeFileName[256];
    CFStringGetCharacters(newFileNameCFString, CFRangeMake(0, CFStringGetLength(newFileNameCFString)), 
                          unicodeFileName);
    theErr = FSRenameUnicode(&fromFileRef, CFStringGetLength(newFileNameCFString), unicodeFileName, 
                             kTextEncodingUnknown, NULL);
    if (theErr != noErr)
    {
        CFRelease(newFileNameCFString);
        nLastError = theErr;
        return false;
    }
    
    CFRelease(newFileNameCFString);
    
    return true;
#endif

#ifdef PLATFORM_LINUX
    // "rename" on Linux also works if the target file exists
    if(rename(szExistingFile, szNewFile) == -1)
    {
        nLastError = errno;
        return false;
    }

    return true;
#endif
}

//-----------------------------------------------------------------------------
// Stream functions - normal file stream

static bool File_GetPos(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & ByteOffset)                 // Pointer to file byte offset
{
    ByteOffset = pStream->RawFilePos;
    return true;
}

static bool File_Read(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    DWORD dwBytesRead = 0;                  // Must be set by platform-specific code

    // If the byte offset is not entered, use the current position
    if(pByteOffset == NULL)
        pByteOffset = &pStream->RawFilePos;

#ifdef PLATFORM_WINDOWS
    {
        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            LONG ByteOffsetHi = (LONG)(*pByteOffset >> 32);
            LONG ByteOffsetLo = (LONG)(*pByteOffset);

            SetFilePointer(pStream->hFile, ByteOffsetLo, &ByteOffsetHi, FILE_BEGIN);
            pStream->RawFilePos = *pByteOffset;
        }

        // Read the data
        if(dwBytesToRead != 0)
        {
            if(!ReadFile(pStream->hFile, pvBuffer, dwBytesToRead, &dwBytesRead, NULL))
                return false;
        }
    }
#endif

#ifdef PLATFORM_MAC
    {
        ByteCount nBytesToRead = (ByteCount)dwBytesToRead;
        ByteCount nBytesRead = 0;
        OSErr theErr;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            FSSetForkPosition((short)(long)pStream->hFile, fsFromStart, (SInt64)(*pByteOffset));
            pStream->RawFilePos = *pByteOffset;
        }

        // Read the data
        if(nBytesToRead != 0)
        {
            theErr = FSReadFork((short)(long)pStream->hFile, fsAtMark, 0, nBytesToRead, pvBuffer, &nBytesRead);
            if (theErr != noErr && theErr != eofErr)
            {
                nLastError = theErr;
                return false;
            }
            dwBytesRead = (DWORD)nBytesRead;
        }
    }
#endif

#ifdef PLATFORM_LINUX
    {
        ssize_t bytes_read;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            lseek64((intptr_t)pStream->hFile, (off64_t)(*pByteOffset), SEEK_SET);
            pStream->RawFilePos = *pByteOffset;
        }

        // Perform the read operation
        if(dwBytesToRead != 0)
        {
            bytes_read = read((intptr_t)pStream->hFile, pvBuffer, (size_t)dwBytesToRead);
            if(bytes_read == -1)
            {
                nLastError = errno;
                return false;
            }

            dwBytesRead = (DWORD)(size_t)bytes_read;
        }
    }
#endif                    

    // Increment the current file position by number of bytes read
    // If the number of bytes read doesn't match to required amount, return false
    pStream->RawFilePos = *pByteOffset + dwBytesRead;
    if(dwBytesRead != dwBytesToRead)
        SetLastError(ERROR_HANDLE_EOF);
    return (dwBytesRead == dwBytesToRead);
}

/**
 * \a pStream Pointer to an open stream
 * \a pByteOffset Pointer to file byte offset. If NULL, writes to current position
 * \a pvBuffer Pointer to data to be written
 * \a dwBytesToWrite Number of bytes to write to the file
 */

static bool File_Write(TFileStream * pStream, ULONGLONG * pByteOffset, const void * pvBuffer, DWORD dwBytesToWrite)
{
    DWORD dwBytesWritten = 0;               // Must be set by platform-specific code

    // If the byte offset is not entered, use the current position
    if(pByteOffset == NULL)
        pByteOffset = &pStream->RawFilePos;

#ifdef PLATFORM_WINDOWS
    {
        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            LONG ByteOffsetHi = (LONG)(*pByteOffset >> 32);
            LONG ByteOffsetLo = (LONG)(*pByteOffset);

            SetFilePointer(pStream->hFile, ByteOffsetLo, &ByteOffsetHi, FILE_BEGIN);
            pStream->RawFilePos = *pByteOffset;
        }

        // Read the data
        if(!WriteFile(pStream->hFile, pvBuffer, dwBytesToWrite, &dwBytesWritten, NULL))
            return false;
    }
#endif

#ifdef PLATFORM_MAC
    {
        ByteCount nBytesToWrite = (ByteCount)dwBytesToWrite;
        ByteCount nBytesWritten = 0;
        OSErr theErr;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            FSSetForkPosition((short)(long)pStream->hFile, fsFromStart, (SInt64)(*pByteOffset));
            pStream->RawFilePos = *pByteOffset;
        }

        theErr = FSWriteFork((short)(long)pStream->hFile, fsAtMark, 0, nBytesToWrite, pvBuffer, &nBytesWritten);
        if (theErr != noErr)
        {
            nLastError = theErr;
            return false;
        }
        dwBytesWritten = (DWORD)nBytesWritten;
    }
#endif

#ifdef PLATFORM_LINUX
    {
        ssize_t bytes_written;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(*pByteOffset != pStream->RawFilePos)
        {
            lseek64((intptr_t)pStream->hFile, (off64_t)(*pByteOffset), SEEK_SET);
            pStream->RawFilePos = *pByteOffset;
        }

        // Perform the read operation
        bytes_written = write((intptr_t)pStream->hFile, pvBuffer, (size_t)dwBytesToWrite);
        if(bytes_written == -1)
        {
            nLastError = errno;
            return false;
        }

        dwBytesWritten = (DWORD)(size_t)bytes_written;
    }
#endif

    // Increment the current file position by number of bytes read
    pStream->RawFilePos = *pByteOffset + dwBytesWritten;
    if(dwBytesWritten != dwBytesToWrite)
        SetLastError(ERROR_DISK_FULL);
    return (dwBytesWritten == dwBytesToWrite);
}

static bool File_GetSize(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
#ifdef PLATFORM_WINDOWS
    DWORD FileSizeHi = 0;
    DWORD FileSizeLo;
    
    FileSizeLo = GetFileSize(pStream->hFile, &FileSizeHi);
    if(FileSizeLo == INVALID_FILE_SIZE && GetLastError() != ERROR_SUCCESS)
        return false;

    FileSize = MAKE_OFFSET64(FileSizeHi, FileSizeLo);
    return true;
#endif

#ifdef PLATFORM_MAC
	SInt64 fileLength = 0;
    OSErr theErr;

    theErr = FSGetForkSize((short)(long)pStream->hFile, &fileLength);
    if(theErr != noErr)
    {
        nLastError = theErr;
        return false;
    }

    FileSize = (ULONGLONG)fileLength;
    return true;
#endif

#ifdef PLATFORM_LINUX
    struct stat64 fileinfo;

    if(fstat64((intptr_t)pStream->hFile, &fileinfo) == -1)
    {
        nLastError = errno;
        return false;
    }

    FileSize = (ULONGLONG)fileinfo.st_size;
    return true;
#endif
}

/**
 * \a pStream Pointer to an open stream
 * \a NewFileSize New size of the file
 */
static bool File_SetSize(TFileStream * pStream, ULONGLONG NewFileSize)
{
#ifdef PLATFORM_WINDOWS
    {
        LONG FileSizeHi = (LONG)(NewFileSize >> 32);
        LONG FileSizeLo = (LONG)(NewFileSize);
        DWORD dwNewPos;
        bool bResult;

        // Set the position at the new file size
        dwNewPos = SetFilePointer(pStream->hFile, FileSizeLo, &FileSizeHi, FILE_BEGIN);
        if(dwNewPos == INVALID_SET_FILE_POINTER && GetLastError() != ERROR_SUCCESS)
            return false;

        // Set the current file pointer as the end of the file
        bResult = (bool)SetEndOfFile(pStream->hFile);

        // Restore the file position
        FileSizeHi = (LONG)(pStream->RawFilePos >> 32);
        FileSizeLo = (LONG)(pStream->RawFilePos);
        SetFilePointer(pStream->hFile, FileSizeLo, &FileSizeHi, FILE_BEGIN);
        return bResult;
    }
#endif
    
#ifdef PLATFORM_MAC
    {
        OSErr theErr;

        theErr = FSSetForkSize((short)(long)pStream->hFile, fsFromStart, (SInt64)NewFileSize);
        if(theErr != noErr)
        {
            nLastError = theErr;
            return false;
        }
        
        return true;
    }
#endif

#ifdef PLATFORM_LINUX
    {
        if(ftruncate((intptr_t)pStream->hFile, (off_t)NewFileSize) == -1)
        {
            nLastError = errno;
            return false;
        }

        return true;
    }
#endif
}

//-----------------------------------------------------------------------------
// Stream functions - partial normal file stream

/**
 * \a pStream Pointer to an open stream
 * \a ByteOffset File byte offset
 */
static bool PartFile_GetPos(TPartFileStream * pStream, ULONGLONG & ByteOffset)
{
    ByteOffset = pStream->VirtualPos;
    return true;
}

/**
 * \a pStream Pointer to an open stream
 * \a pByteOffset Pointer to file byte offset. If NULL, reads from the current position
 * \a pvBuffer Pointer to data to be read
 * \a dwBytesToRead Number of bytes to read from the file
 */
static bool PartFile_Read(TPartFileStream * pStream, ULONGLONG * pByteOffset, void * pvBuffer, DWORD dwBytesToRead)
{
    ULONGLONG RawByteOffset;
    LPBYTE pbBuffer = (LPBYTE)pvBuffer;
    DWORD dwBytesRemaining = dwBytesToRead;
    DWORD dwPartOffset;
    DWORD dwPartIndex;
    DWORD dwBytesRead = 0;
    DWORD dwBlockSize = pStream->BlockSize;
    bool bResult = false;
    int nFailReason = ERROR_HANDLE_EOF;             // Why it failed if not enough bytes was read

    // If the byte offset is not entered, use the current position
    if(pByteOffset == NULL)
        pByteOffset = &pStream->VirtualPos;

    // Check if the file position is not at or beyond end of the file
    if(*pByteOffset >= pStream->VirtualSize)
    {
        SetLastError(ERROR_HANDLE_EOF);
        return false;
    }

    // Get the part index where the read offset is
    // Note that the part index should now be within the range,
    // as read requests beyond-EOF are handled by the previous test
    dwPartIndex = (DWORD)(*pByteOffset / pStream->BlockSize);
    assert(dwPartIndex < pStream->BlockCount);

    // If the number of bytes remaining goes past
    // the end of the file, cut them
    if((*pByteOffset + dwBytesRemaining) > pStream->VirtualSize)
        dwBytesRemaining = (DWORD)(pStream->VirtualSize - *pByteOffset);

    // Calculate the offset in the current part
    dwPartOffset = (DWORD)(*pByteOffset) & (pStream->BlockSize - 1);

    // Read all data, one part at a time
    while(dwBytesRemaining != 0)
    {
        PPART_FILE_MAP_ENTRY PartMap = pStream->PartMap + dwPartIndex;
        DWORD dwBytesInPart;

        // If the part is not present in the file, we fail the read
        if((PartMap->Flags & 3) == 0)
        {
            nFailReason = ERROR_CAN_NOT_COMPLETE;
            bResult = false;
            break;
        }

        // If we are in the last part, we have to cut the number of bytes in the last part
        if(dwPartIndex == pStream->BlockCount - 1)
            dwBlockSize = (DWORD)pStream->VirtualSize & (pStream->BlockSize - 1);

        // Get the number of bytes reamining in the current part
        dwBytesInPart = dwBlockSize - dwPartOffset;

        // Compute the raw file offset of the file part
        RawByteOffset = MAKE_OFFSET64(PartMap->BlockOffsHi, PartMap->BlockOffsLo);
        if(RawByteOffset == 0)
        {
            nFailReason = ERROR_CAN_NOT_COMPLETE;
            bResult = false;
            break;
        }

        // If the number of bytes in part is too big, cut it
        if(dwBytesInPart > dwBytesRemaining)
            dwBytesInPart = dwBytesRemaining;

        // Append the offset within the part
        RawByteOffset += dwPartOffset;
        if(!File_Read(pStream, &RawByteOffset, pbBuffer, dwBytesInPart))
        {
            nFailReason = ERROR_CAN_NOT_COMPLETE;
            bResult = false;
            break;
        }

        // Increment the file position
        dwBytesRemaining -= dwBytesInPart;
        dwBytesRead += dwBytesInPart;
        pbBuffer += dwBytesInPart;

        // Move to the next file part
        dwPartOffset = 0;
        dwPartIndex++;
    }

    // Move the file position by the number of bytes read
    pStream->VirtualPos = *pByteOffset + dwBytesRead;
    if(dwBytesRead != dwBytesToRead)
        SetLastError(nFailReason);
    return (dwBytesRead == dwBytesToRead);
}

static bool PartFile_Write(
    TPartFileStream * pStream,              // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    const void * pvBuffer,                  // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    // Keep compiler happy
    dwBytesToRead = dwBytesToRead;
    pByteOffset = pByteOffset;
    pvBuffer = pvBuffer;
    pStream = pStream;

    // Not allowed
    return false;
}

static bool PartFile_GetSize(
    TPartFileStream * pStream,              // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
    FileSize = pStream->VirtualSize;
    return true;
}

static bool PartFile_SetSize(
    TPartFileStream * pStream,              // Pointer to an open stream
    ULONGLONG NewSize)                      // new size of the file
{
    // Keep compiler happy
    pStream = pStream;
    NewSize = NewSize;

    // Not allowed
    return false;
}

/*
 * Stream functions - encrypted stream
 *
 * Note: In original Starcraft II Installer.exe:                       Suffix derived from battle.net auth. code
 * Address of decryption routine: 0053A3D0                             http://us.battle.net/static/mediakey/sc2-authenticationcode-enUS.txt
 * Pointer to decryptor object: ECX                                    Numbers mean offset of 4-char group of auth code
 * Pointer to key: ECX+0x5C                                            -0C-    -1C--08-    -18--04-    -14--00-    -10-
 */
static const char * MpqeKey_Starcraft2_Install_enUS = "expand 32-byte kTFD80000ETR5VM5G0000K859RE5N0000WT6F3DH500005LXG";
static const char * MpqeKey_Starcraft2_Install_enGB = "expand 32-byte kANGY000029ZH6NA20000HRGF8UDG0000NY82G8MN00006A3D";
static const char * MpqeKey_Starcraft2_Install_deDE = "expand 32-byte kSSXH00004XFXK4KX00008EKJD3CA0000Y64ZY45M0000YD9V";
static const char * MpqeKey_Starcraft2_Install_esES = "expand 32-byte kQU4Y0000XKTQ94PF0000N4R4UAXE0000AZ248WLK0000249P";
static const char * MpqeKey_Starcraft2_Install_frFR = "expand 32-byte kFWPQ00006EAJ8HJE0000PFER9K9300008MA2ZG7J0000UA76";
static const char * MpqeKey_Starcraft2_Install_itIT = "expand 32-byte kXV7E00008BL2TVAP0000GVMWUNNN0000SVBWNE7C00003G2B";
static const char * MpqeKey_Starcraft2_Install_plPL = "expand 32-byte k83U6000048L6LULJ00004MQDB8ME0000UP6K2NSF0000YHA3";
static const char * MpqeKey_Starcraft2_Install_ruRU = "expand 32-byte k9SH70000YEGT4BAT0000QDK978W60000V9NLVHB30000D68V";

static const char * MpqKeyArray[] =
{
    MpqeKey_Starcraft2_Install_enUS,
    MpqeKey_Starcraft2_Install_enGB,
    MpqeKey_Starcraft2_Install_deDE,
    MpqeKey_Starcraft2_Install_esES,
    MpqeKey_Starcraft2_Install_frFR,
    MpqeKey_Starcraft2_Install_itIT,
    MpqeKey_Starcraft2_Install_plPL,
    MpqeKey_Starcraft2_Install_ruRU,
    NULL
};

static DWORD Rol32(DWORD dwValue, DWORD dwRolCount)
{
    DWORD dwShiftRight = 32 - dwRolCount;

    return (dwValue << dwRolCount) | (dwValue >> dwShiftRight);
}

static void DecryptFileChunk(
    DWORD * MpqData,
    LPBYTE pbKey,
    ULONGLONG ByteOffset,
    DWORD dwLength)
{
    ULONGLONG ChunkOffset;
    DWORD KeyShuffled[0x10];
    DWORD KeyMirror[0x10];
    DWORD RoundCount = 0x14;

    // Prepare the key
    ChunkOffset = ByteOffset / MPQE_CHUNK_SIZE;
    memcpy(KeyMirror, pbKey, MPQE_CHUNK_SIZE);
    BSWAP_ARRAY32_UNSIGNED(KeyMirror, MPQE_CHUNK_SIZE);
    KeyMirror[0x05] = (DWORD)(ChunkOffset >> 32);
    KeyMirror[0x08] = (DWORD)(ChunkOffset);

    while(dwLength >= MPQE_CHUNK_SIZE)
    {
        // Shuffle the key - part 1
        KeyShuffled[0x0E] = KeyMirror[0x00];
        KeyShuffled[0x0C] = KeyMirror[0x01];
        KeyShuffled[0x05] = KeyMirror[0x02];
        KeyShuffled[0x0F] = KeyMirror[0x03];
        KeyShuffled[0x0A] = KeyMirror[0x04];
        KeyShuffled[0x07] = KeyMirror[0x05];
        KeyShuffled[0x0B] = KeyMirror[0x06];
        KeyShuffled[0x09] = KeyMirror[0x07];
        KeyShuffled[0x03] = KeyMirror[0x08];
        KeyShuffled[0x06] = KeyMirror[0x09];
        KeyShuffled[0x08] = KeyMirror[0x0A];
        KeyShuffled[0x0D] = KeyMirror[0x0B];
        KeyShuffled[0x02] = KeyMirror[0x0C];
        KeyShuffled[0x04] = KeyMirror[0x0D];
        KeyShuffled[0x01] = KeyMirror[0x0E];
        KeyShuffled[0x00] = KeyMirror[0x0F];
        
        // Shuffle the key - part 2
        for(DWORD i = 0; i < RoundCount; i += 2)
        {
            KeyShuffled[0x0A] = KeyShuffled[0x0A] ^ Rol32((KeyShuffled[0x0E] + KeyShuffled[0x02]), 0x07);
            KeyShuffled[0x03] = KeyShuffled[0x03] ^ Rol32((KeyShuffled[0x0A] + KeyShuffled[0x0E]), 0x09);
            KeyShuffled[0x02] = KeyShuffled[0x02] ^ Rol32((KeyShuffled[0x03] + KeyShuffled[0x0A]), 0x0D);
            KeyShuffled[0x0E] = KeyShuffled[0x0E] ^ Rol32((KeyShuffled[0x02] + KeyShuffled[0x03]), 0x12);

            KeyShuffled[0x07] = KeyShuffled[0x07] ^ Rol32((KeyShuffled[0x0C] + KeyShuffled[0x04]), 0x07);
            KeyShuffled[0x06] = KeyShuffled[0x06] ^ Rol32((KeyShuffled[0x07] + KeyShuffled[0x0C]), 0x09);
            KeyShuffled[0x04] = KeyShuffled[0x04] ^ Rol32((KeyShuffled[0x06] + KeyShuffled[0x07]), 0x0D);
            KeyShuffled[0x0C] = KeyShuffled[0x0C] ^ Rol32((KeyShuffled[0x04] + KeyShuffled[0x06]), 0x12);

            KeyShuffled[0x0B] = KeyShuffled[0x0B] ^ Rol32((KeyShuffled[0x05] + KeyShuffled[0x01]), 0x07);
            KeyShuffled[0x08] = KeyShuffled[0x08] ^ Rol32((KeyShuffled[0x0B] + KeyShuffled[0x05]), 0x09);
            KeyShuffled[0x01] = KeyShuffled[0x01] ^ Rol32((KeyShuffled[0x08] + KeyShuffled[0x0B]), 0x0D);
            KeyShuffled[0x05] = KeyShuffled[0x05] ^ Rol32((KeyShuffled[0x01] + KeyShuffled[0x08]), 0x12);

            KeyShuffled[0x09] = KeyShuffled[0x09] ^ Rol32((KeyShuffled[0x0F] + KeyShuffled[0x00]), 0x07);
            KeyShuffled[0x0D] = KeyShuffled[0x0D] ^ Rol32((KeyShuffled[0x09] + KeyShuffled[0x0F]), 0x09);
            KeyShuffled[0x00] = KeyShuffled[0x00] ^ Rol32((KeyShuffled[0x0D] + KeyShuffled[0x09]), 0x0D);
            KeyShuffled[0x0F] = KeyShuffled[0x0F] ^ Rol32((KeyShuffled[0x00] + KeyShuffled[0x0D]), 0x12);

            KeyShuffled[0x04] = KeyShuffled[0x04] ^ Rol32((KeyShuffled[0x0E] + KeyShuffled[0x09]), 0x07);
            KeyShuffled[0x08] = KeyShuffled[0x08] ^ Rol32((KeyShuffled[0x04] + KeyShuffled[0x0E]), 0x09);
            KeyShuffled[0x09] = KeyShuffled[0x09] ^ Rol32((KeyShuffled[0x08] + KeyShuffled[0x04]), 0x0D);
            KeyShuffled[0x0E] = KeyShuffled[0x0E] ^ Rol32((KeyShuffled[0x09] + KeyShuffled[0x08]), 0x12);

            KeyShuffled[0x01] = KeyShuffled[0x01] ^ Rol32((KeyShuffled[0x0C] + KeyShuffled[0x0A]), 0x07);
            KeyShuffled[0x0D] = KeyShuffled[0x0D] ^ Rol32((KeyShuffled[0x01] + KeyShuffled[0x0C]), 0x09);
            KeyShuffled[0x0A] = KeyShuffled[0x0A] ^ Rol32((KeyShuffled[0x0D] + KeyShuffled[0x01]), 0x0D);
            KeyShuffled[0x0C] = KeyShuffled[0x0C] ^ Rol32((KeyShuffled[0x0A] + KeyShuffled[0x0D]), 0x12);

            KeyShuffled[0x00] = KeyShuffled[0x00] ^ Rol32((KeyShuffled[0x05] + KeyShuffled[0x07]), 0x07);
            KeyShuffled[0x03] = KeyShuffled[0x03] ^ Rol32((KeyShuffled[0x00] + KeyShuffled[0x05]), 0x09);
            KeyShuffled[0x07] = KeyShuffled[0x07] ^ Rol32((KeyShuffled[0x03] + KeyShuffled[0x00]), 0x0D);
            KeyShuffled[0x05] = KeyShuffled[0x05] ^ Rol32((KeyShuffled[0x07] + KeyShuffled[0x03]), 0x12);

            KeyShuffled[0x02] = KeyShuffled[0x02] ^ Rol32((KeyShuffled[0x0F] + KeyShuffled[0x0B]), 0x07);
            KeyShuffled[0x06] = KeyShuffled[0x06] ^ Rol32((KeyShuffled[0x02] + KeyShuffled[0x0F]), 0x09);
            KeyShuffled[0x0B] = KeyShuffled[0x0B] ^ Rol32((KeyShuffled[0x06] + KeyShuffled[0x02]), 0x0D);
            KeyShuffled[0x0F] = KeyShuffled[0x0F] ^ Rol32((KeyShuffled[0x0B] + KeyShuffled[0x06]), 0x12);
        }

        // Decrypt one data chunk
        BSWAP_ARRAY32_UNSIGNED(MpqData, MPQE_CHUNK_SIZE);
        MpqData[0x00] = MpqData[0x00] ^ (KeyShuffled[0x0E] + KeyMirror[0x00]);
        MpqData[0x01] = MpqData[0x01] ^ (KeyShuffled[0x04] + KeyMirror[0x0D]);
        MpqData[0x02] = MpqData[0x02] ^ (KeyShuffled[0x08] + KeyMirror[0x0A]);
        MpqData[0x03] = MpqData[0x03] ^ (KeyShuffled[0x09] + KeyMirror[0x07]);
        MpqData[0x04] = MpqData[0x04] ^ (KeyShuffled[0x0A] + KeyMirror[0x04]);
        MpqData[0x05] = MpqData[0x05] ^ (KeyShuffled[0x0C] + KeyMirror[0x01]);
        MpqData[0x06] = MpqData[0x06] ^ (KeyShuffled[0x01] + KeyMirror[0x0E]);
        MpqData[0x07] = MpqData[0x07] ^ (KeyShuffled[0x0D] + KeyMirror[0x0B]);
        MpqData[0x08] = MpqData[0x08] ^ (KeyShuffled[0x03] + KeyMirror[0x08]);
        MpqData[0x09] = MpqData[0x09] ^ (KeyShuffled[0x07] + KeyMirror[0x05]);
        MpqData[0x0A] = MpqData[0x0A] ^ (KeyShuffled[0x05] + KeyMirror[0x02]);
        MpqData[0x0B] = MpqData[0x0B] ^ (KeyShuffled[0x00] + KeyMirror[0x0F]);
        MpqData[0x0C] = MpqData[0x0C] ^ (KeyShuffled[0x02] + KeyMirror[0x0C]);
        MpqData[0x0D] = MpqData[0x0D] ^ (KeyShuffled[0x06] + KeyMirror[0x09]);
        MpqData[0x0E] = MpqData[0x0E] ^ (KeyShuffled[0x0B] + KeyMirror[0x06]);
        MpqData[0x0F] = MpqData[0x0F] ^ (KeyShuffled[0x0F] + KeyMirror[0x03]);
        BSWAP_ARRAY32_UNSIGNED(MpqData, MPQE_CHUNK_SIZE);

        // Update byte offset in the key
        KeyMirror[0x08]++;
        if(KeyMirror[0x08] == 0)
            KeyMirror[0x05]++;

        // Move pointers and decrease number of bytes to decrypt
        MpqData  += (MPQE_CHUNK_SIZE / sizeof(DWORD));
        dwLength -= MPQE_CHUNK_SIZE;
    }
}


static bool DetectFileKey(TEncryptedStream * pStream)
{
    ULONGLONG ByteOffset = 0;
    BYTE EncryptedHeader[MPQE_CHUNK_SIZE];
    BYTE FileHeader[MPQE_CHUNK_SIZE];

    // Load the chunk from the file
    if(!FileStream_Read(pStream, &ByteOffset, EncryptedHeader, sizeof(EncryptedHeader)))
        return false;

    // We just try all known keys one by one
    for(int i = 0; MpqKeyArray[i] != NULL; i++)
    {
        // Copy the key there
        memcpy(pStream->Key, MpqKeyArray[i], MPQE_CHUNK_SIZE);
        BSWAP_ARRAY32_UNSIGNED(pStream->Key, MPQE_CHUNK_SIZE);

        // Try to decrypt with the given key 
        memcpy(FileHeader, EncryptedHeader, MPQE_CHUNK_SIZE);
        DecryptFileChunk((LPDWORD)FileHeader, pStream->Key, ByteOffset, MPQE_CHUNK_SIZE);

        // We check the decrypoted data
        // All known encrypted MPQs have header at the begin of the file,
        // so we check for MPQ signature there.
        if(FileHeader[0] == 'M' && FileHeader[1] == 'P' && FileHeader[2] == 'Q')
            return true;
    }

    // Key not found, sorry
    return false;
}

static bool EncryptedFile_Read(
    TEncryptedStream * pStream,             // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    ULONGLONG StartOffset;                  // Offset of the first byte to be read from the file
    ULONGLONG ByteOffset;                   // Offset that the caller wants
    ULONGLONG EndOffset;                    // End offset that is to be read from the file
    DWORD dwBytesToAllocate;
    DWORD dwBytesToDecrypt;
    DWORD dwOffsetInCache;
    LPBYTE pbMpqData = NULL;
    bool bResult = false;

    // Get the byte offset
    if(pByteOffset != NULL)
        ByteOffset = *pByteOffset;
    else
        ByteOffset = pStream->RawFilePos;

    // Cut it down to MPQE chunk size
    StartOffset = ByteOffset;
    StartOffset = StartOffset & ~(MPQE_CHUNK_SIZE - 1);
    EndOffset = ByteOffset + dwBytesToRead;

    // Calculate number of bytes to decrypt
    dwBytesToDecrypt = (DWORD)(EndOffset - StartOffset);
    dwBytesToAllocate = (dwBytesToDecrypt + (MPQE_CHUNK_SIZE - 1)) & ~(MPQE_CHUNK_SIZE - 1);

    // Allocate buffers for encrypted and decrypted data
    pbMpqData = STORM_ALLOC(BYTE, dwBytesToAllocate);
    if(pbMpqData)
    {
        // Get the offset of the desired data in the cache
        dwOffsetInCache = (DWORD)(ByteOffset - StartOffset);

        // Read the file from the stream as-is
        if(File_Read(pStream, &StartOffset, pbMpqData, dwBytesToDecrypt))
        {
            // Decrypt the data
            DecryptFileChunk((LPDWORD)pbMpqData, pStream->Key, StartOffset, dwBytesToAllocate);

            // Copy the decrypted data
            memcpy(pvBuffer, pbMpqData + dwOffsetInCache, dwBytesToRead);
            bResult = true;
        }
        else
        {
            assert(false);
        }

        // Free decryption buffer        
        STORM_FREE(pbMpqData);
    }

    // Free buffers and exit
    return bResult;
}

static bool EncryptedFile_Write(
    TEncryptedStream * pStream,             // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    const void * pvBuffer,                  // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    // Keep compiler happy
    dwBytesToRead = dwBytesToRead;
    pByteOffset = pByteOffset;
    pvBuffer = pvBuffer;
    pStream = pStream;

    // Not allowed
    return false;
}

static bool EncryptedFile_SetSize(
    TEncryptedStream * pStream,             // Pointer to an open stream
    ULONGLONG NewSize)                      // new size of the file
{
    // Keep compiler happy
    pStream = pStream;
    NewSize = NewSize;

    // Not allowed
    return false;
}

//-----------------------------------------------------------------------------
// Public functions

/**
 * This function creates a new file for read or read-write access
 *
 * - If the current platform supports file sharing,
 *   the file must be created for read sharing (i.e. another application
 *   can open the file for read, but not for write)
 * - If the file does not exist, the function must create new one
 * - If the file exists, the function must rewrite it and set to zero size
 * - The parameters of the function must be validate by the caller
 * - The function must initialize all stream function pointers in TFileStream
 * - If the function fails from any reason, it must close all handles
 *   and free all memory that has been allocated in the process of stream creation,
 *   including the TFileStream structure itself
 *
 * \a szFileName Name of the file to create
 */

TFileStream * FileStream_CreateFile(
    const TCHAR * szFileName)           // Name of the file to create
{
    TFileStream * pStream = NULL;
    HANDLE hFile;

    // Create the file
    hFile = CreateNewFile(szFileName); 
    if(hFile != INVALID_HANDLE_VALUE)
    {
        // Allocate the FileStream structure and fill it
        pStream = STORM_ALLOC(TFileStream, 1);
        if(pStream != NULL)
        {
            // Reset entire structure to zero
            memset(pStream, 0, sizeof(TFileStream));

            // Save file name and set function pointers
            _tcscpy(pStream->szFileName, szFileName);
            pStream->StreamGetPos  = File_GetPos;
            pStream->StreamRead    = File_Read;
            pStream->StreamWrite   = File_Write;
            pStream->StreamGetSize = File_GetSize;
            pStream->StreamSetSize = File_SetSize;
            pStream->hFile = hFile;
        }
        else
        {
            CloseTheFile(hFile);
        }
    }

    // Return the stream
    return pStream;
}

/**
 * This function opens an existing file for read or read-write access
 * - If the current platform supports file sharing,
 *   the file must be open for read sharing (i.e. another application
 *   can open the file for read, but not for write)
 * - If the file does not exist, the function must return NULL
 * - If the file exists but cannot be open, then function must return NULL
 * - The parameters of the function must be validate by the caller
 * - The function must check if the file is a PART file,
 *   and create TPartFileStream object if so.
 * - The function must initialize all stream function pointers in TFileStream
 * - If the function fails from any reason, it must close all handles
 *   and free all memory that has been allocated in the process of stream creation,
 *   including the TFileStream structure itself
 *
 * \a szFileName Name of the file to open
 * \a bWriteAccess false for read only, true for read+write
 */

TFileStream * FileStream_OpenRawFile(
    const TCHAR * szFileName,               // Name of the file to create
    bool bWriteAccess)                      // false = read-only, true = read+write
{
    TFileStream * pStream;
    HANDLE hFile;

    // Create the file
    hFile = OpenExistingFile(szFileName, bWriteAccess); 
    if(hFile == INVALID_HANDLE_VALUE)
        return NULL;

    // Initialize the file as normal file stream
    pStream = STORM_ALLOC(TFileStream, 1);
    if(pStream != NULL)
    {
        // Reset entire structure to zero
        memset(pStream, 0, sizeof(TFileStream));

        // Save file name and set function pointers
        _tcscpy(pStream->szFileName, szFileName);
        pStream->StreamGetPos  = File_GetPos;
        pStream->StreamRead    = File_Read;
        pStream->StreamWrite   = File_Write;
        pStream->StreamGetSize = File_GetSize;
        pStream->StreamSetSize = File_SetSize;
        if(bWriteAccess == false)
            pStream->StreamFlags |= STREAM_FLAG_READ_ONLY;
        pStream->hFile = hFile;
        return pStream;
    }

    CloseTheFile(hFile);
    return NULL;
}

/**
 * Opens a file
 *
 * \a szFileName Name of the file to open
 * \a bWriteAccess false for read only, true for read+write
 */

TFileStream * FileStream_OpenFile(const TCHAR * szFileName, bool bWriteAccess)
{
    PART_FILE_HEADER PartHdr;
    ULONGLONG VirtualSize;                  // Size of the file stored in part file
    ULONGLONG ByteOffset = {0};
    TFileStream * pStream;
    size_t nStructLength;
    DWORD BlockCount;

    // Open the file as normal stream
    pStream = FileStream_OpenRawFile(szFileName, bWriteAccess);
    if(pStream == NULL)
        return NULL;

    // Attempt to read PART file header
    if(FileStream_Read(pStream, &ByteOffset, &PartHdr, sizeof(PART_FILE_HEADER)))
    {
        // We need to swap PART file header on big-endian platforms
        BSWAP_PART_HEADER(&PartHdr);

        // Verify the PART file header
        if(IsPartHeader(&PartHdr))
        {
            TPartFileStream * pPartStream;

            // Calculate the number of parts in the file
            VirtualSize = MAKE_OFFSET64(PartHdr.FileSizeHi, PartHdr.FileSizeLo);
            BlockCount = (DWORD)((VirtualSize + PartHdr.BlockSize - 1) / PartHdr.BlockSize);

            // Calculate the size of the entire structure
            // Note that we decrement number of parts by one,
            // because there already is one entry in the TPartFileStream structure
            nStructLength = sizeof(TPartFileStream) + (BlockCount - 1) * sizeof(PART_FILE_MAP_ENTRY);
            pPartStream = (TPartFileStream *)STORM_ALLOC(char, nStructLength);
            if(pPartStream != NULL)
            {
                // Initialize the part file stream
                memset(pPartStream, 0, nStructLength);
                memcpy(pPartStream, pStream, sizeof(TFileStream));

                // Load the block map
                if(!FileStream_Read(pPartStream, NULL, pPartStream->PartMap, BlockCount * sizeof(PART_FILE_MAP_ENTRY)))
                {
                    FileStream_Close(pStream);
                    STORM_FREE(pPartStream);
                    return NULL;
                }

                // Swap the array of file map entries
                BSWAP_ARRAY32_UNSIGNED(pPartStream->PartMap, BlockCount * sizeof(PART_FILE_MAP_ENTRY));

                // Set new function pointers
                pPartStream->StreamGetPos  = (STREAM_GETPOS)PartFile_GetPos;
                pPartStream->StreamRead    = (STREAM_READ)PartFile_Read;
                pPartStream->StreamWrite   = (STREAM_WRITE)PartFile_Write;
                pPartStream->StreamGetSize = (STREAM_GETSIZE)PartFile_GetSize;
                pPartStream->StreamSetSize = (STREAM_SETSIZE)PartFile_SetSize;
                pPartStream->StreamFlags  |= (STREAM_FLAG_READ_ONLY | STREAM_FLAG_PART_FILE);

                // Fill the members of PART file stream
                pPartStream->VirtualSize = ((ULONGLONG)PartHdr.FileSizeHi) + PartHdr.FileSizeLo;
                pPartStream->VirtualPos = 0;
                pPartStream->BlockCount = BlockCount;
                pPartStream->BlockSize = PartHdr.BlockSize;

                STORM_FREE(pStream);
            }
            return pPartStream;
        }
    }

    // If the file doesn't contain PART file header,
    // reset the file position to begin of the file
    FileStream_Read(pStream, &ByteOffset, NULL, 0);
    return pStream;
}

TFileStream * FileStream_OpenEncrypted(const TCHAR * szFileName)
{
    TEncryptedStream * pEncryptedStream;
    TFileStream * pStream;

    // Open the file as raw stream
    pStream = FileStream_OpenRawFile(szFileName, false);
    if(pStream)
    {
        // Allocate new stream for handling encryption
        pEncryptedStream = STORM_ALLOC(TEncryptedStream, 1);
        if(pEncryptedStream != NULL)
        {
            // Copy the file stream to the encrypted stream
            memset(pEncryptedStream, 0, sizeof(TEncryptedStream));
            memcpy(pEncryptedStream, pStream, sizeof(TFileStream));

            // Assign functions
            pEncryptedStream->StreamRead    = (STREAM_READ)EncryptedFile_Read;
            pEncryptedStream->StreamWrite   = (STREAM_WRITE)EncryptedFile_Write;
            pEncryptedStream->StreamSetSize = (STREAM_SETSIZE)EncryptedFile_SetSize;
            pEncryptedStream->StreamFlags  |= (STREAM_FLAG_READ_ONLY | STREAM_FLAG_ENCRYPTED_FILE);

            // Get the file key
            if(DetectFileKey(pEncryptedStream))
                return pEncryptedStream;

            // Close the encrypted stream
            STORM_FREE(pEncryptedStream);
            pEncryptedStream = NULL;
        }

        FileStream_Close(pStream);
        pStream = NULL;
    }

    SetLastError(ERROR_UNKNOWN_FILE_KEY);
    return NULL;
}

/**
 * This function returns the current file position
 * \a pStream
 * \a ByteOffset
 */
bool FileStream_GetPos(TFileStream * pStream, ULONGLONG & ByteOffset)
{
    assert(pStream->StreamGetPos != NULL);
    return pStream->StreamGetPos(pStream, ByteOffset);
}

/**
 * Reads data from the stream
 *
 * - Returns true if the read operation succeeded and all bytes have been read
 * - Returns false if either read failed or not all bytes have been read
 * - If the pByteOffset is NULL, the function must read the data from the current file position
 * - The function can be called with dwBytesToRead = 0. In that case, pvBuffer is ignored
 *   and the function just adjusts file pointer.
 *
 * \a pStream Pointer to an open stream
 * \a pByteOffset Pointer to file byte offset. If NULL, it reads from the current position
 * \a pvBuffer Pointer to data to be read
 * \a dwBytesToRead Number of bytes to read from the file
 *
 * \returns
 * - If the function reads the required amount of bytes, it returns true.
 * - If the function reads less than required bytes, it returns false and GetLastError() returns ERROR_HANDLE_EOF
 * - If the function fails, it reads false and GetLastError() returns an error code different from ERROR_HANDLE_EOF
 */
bool FileStream_Read(TFileStream * pStream, ULONGLONG * pByteOffset, void * pvBuffer, DWORD dwBytesToRead)
{
    assert(pStream->StreamRead != NULL);
    return pStream->StreamRead(pStream, pByteOffset, pvBuffer, dwBytesToRead);
}

/**
 * This function writes data to the stream
 *
 * - Returns true if the write operation succeeded and all bytes have been written
 * - Returns false if either write failed or not all bytes have been written
 * - If the pByteOffset is NULL, the function must write the data to the current file position
 *
 * \a pStream Pointer to an open stream
 * \a pByteOffset Pointer to file byte offset. If NULL, it reads from the current position
 * \a pvBuffer Pointer to data to be written
 * \a dwBytesToWrite Number of bytes to write to the file
 */
bool FileStream_Write(TFileStream * pStream, ULONGLONG * pByteOffset, const void * pvBuffer, DWORD dwBytesToWrite)
{
    if(pStream->StreamFlags & STREAM_FLAG_READ_ONLY)
        return false;
    assert(pStream->StreamWrite != NULL);

    return pStream->StreamWrite(pStream, pByteOffset, pvBuffer, dwBytesToWrite);
}


/**
 * Returns the last write time of a file
 *
 * \a pStream Pointer to an open stream
 * \a pFileType Pointer where to store the file last write time
 */
bool FileStream_GetLastWriteTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
#ifdef PLATFORM_WINDOWS
    FILETIME ft;

    if(!GetFileTime(pStream->hFile, NULL, NULL, &ft))
        return false;

    *pFileTime = MAKE_OFFSET64(ft.dwHighDateTime, ft.dwLowDateTime);
    return true;
#endif

#ifdef PLATFORM_MAC
	OSErr theErr;
	FSRef theFileRef;
	FSCatalogInfo theCatInfo;
	
    theErr = FSGetForkCBInfo((short)(long)pStream->hFile, 0, NULL, NULL, NULL, &theFileRef, NULL);
    if(theErr != noErr)
    {
        nLastError = theErr;
        return false;
    }
	
    theErr = FSGetCatalogInfo(&theFileRef, kFSCatInfoContentMod, &theCatInfo, NULL, NULL, NULL);
    if(theErr != noErr)
    {
        nLastError = theErr;
        return false;
    }

    ConvertUTCDateTimeToFileTime(&theCatInfo.contentModDate, pFileTime);
    return true;
#endif

#ifdef PLATFORM_LINUX
    struct stat file_stats;

    if(fstat((int)(size_t)pStream->hFile, &file_stats) == -1)
    {
        nLastError = errno;
        return false;
    }

    ConvertTimeTToFileTime(pFileTime, file_stats.st_mtime);
    return true;
#endif
}

/**
 * Returns the size of a file
 *
 * \a pStream Pointer to an open stream
 * \a FileSize Pointer where to store the file size
 */
bool FileStream_GetSize(TFileStream * pStream, ULONGLONG & FileSize)
{
    assert(pStream->StreamGetSize != NULL);
    return pStream->StreamGetSize(pStream, FileSize);
}

/**
 * Sets the size of a file
 *
 * \a pStream Pointer to an open stream
 * \a NewFileSize File size to set
 */
bool FileStream_SetSize(TFileStream * pStream, ULONGLONG NewFileSize)
{                                 
    if(pStream->StreamFlags & STREAM_FLAG_READ_ONLY)
        return false;
    assert(pStream->StreamSetSize != NULL);

    return pStream->StreamSetSize(pStream, NewFileSize);
}

/**
 * Switches a stream with another. Used for final phase of archive compacting.
 * Performs these steps:
 *
 * 1) Closes the handle to the existing MPQ
 * 2) Renames the temporary MPQ to the original MPQ, overwrites existing one
 * 3) Opens the MPQ stores the handle and stream position to the new stream structure
 *
 * \a pStream Pointer to an open stream
 * \a pTempStream Temporary ("working") stream (created during archive compacting)
 */
bool FileStream_MoveFile(TFileStream * pStream, TFileStream * pTempStream)
{
    bool bWriteAccess;

    // Close the handle to the temporary file
    CloseTheFile(pTempStream->hFile);
    pTempStream->hFile = INVALID_HANDLE_VALUE;

    // Close the handle to the source file
    CloseTheFile(pStream->hFile);
    pStream->hFile = INVALID_HANDLE_VALUE;

    // Rename the temp file to the final file
    if(!RenameFile(pTempStream->szFileName, pStream->szFileName))
        return false;

    // Now open the renamed file again, and store its handle to the old stream
    bWriteAccess = (pStream->StreamFlags & STREAM_FLAG_READ_ONLY) ? false : true;
    pStream->hFile = OpenExistingFile(pStream->szFileName, bWriteAccess);
    if(pStream->hFile == INVALID_HANDLE_VALUE)
        return false;

    // Delete the temporary file stream
    FileStream_Close(pTempStream);

    // The file position has been reset to zero by reopening the file
    pStream->RawFilePos = 0;
    return true;
}

/**
 * This function closes an archive file and frees any data buffers
 * that have been allocated for stream management. The function must also
 * support partially allocated structure, i.e. one or more buffers
 * can be NULL, if there was an allocation failure during the process
 *
 * \a pStream Pointer to an open stream
 */
void FileStream_Close(TFileStream * pStream)
{
    // Check if the stream structure is allocated at all
    if(pStream != NULL)
    {
        // Close the file handle
        if(pStream->hFile != INVALID_HANDLE_VALUE)
            CloseTheFile(pStream->hFile);

        // Free the stream itself
        STORM_FREE(pStream);
    }
}

//-----------------------------------------------------------------------------
// main - for testing purposes
/*
int main(void)
{
    ULONGLONG FilePos;
    ULONGLONG FileSize;
    TMPQFileTime * pFT;
    TFileStream * pTempStream;
    TFileStream * pStream;
    TMPQBlock * pBlock;
    TMPQHash * pHash;
    TMPQHeader2 MpqHeader;
    char szString1[100] = "This is a single line\n\r";
    char szString2[100];
    char Buffer[0x80];
    DWORD dwLength = strlen(szString1);

    //
    // Test 1: Write to a stream
    //

    pStream = FileStream_CreateFile("E:\\Stream.bin");
    if(pStream == NULL)
    {
        printf("Failed to create new file\n");
        return -1;
    }

    for(int i = 0; i < 10; i++)
    {
        if(!FileStream_Write(pStream, NULL, szString1, dwLength))
        {
            printf("Failed to write to the stream\n");
            return -1;
        }
    }
    FileStream_Close(pStream);

    //
    // Test2: Read from the stream
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", false);
    if(pStream == NULL)
    {
        printf("Failed to open existing file\n");
        return -1;
    }

    // This call must end with an error
    if(FileStream_Write(pStream, NULL, "aaa", 3))
    {
        printf("Write succeeded while it should fail\n");
        return -1;
    }

    for(int i = 0; i < 10; i++)
    {
        if(!FileStream_Read(pStream, NULL, szString2, dwLength))
        {
            printf("Failed to read from the stream\n");
            return -1;
        }

        szString2[dwLength] = 0;
        if(strcmp(szString1, szString2))
        {
            printf("Data read from file are different from data written\n");
            return -1;
        }
    }
    FileStream_Close(pStream);

    //
    // Test3: Open the temp stream, write some data and switch it to the original stream
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", false);
    if(pStream == NULL)
    {
        printf("Failed to open existing file\n");
        return -1;
    }

    pTempStream = FileStream_CreateFile("E:\\TempStream.bin");
    if(pTempStream == NULL)
    {
        printf("Failed to create temp stream\n");
        return -1;
    }

    // Copy the original stream to the temp
    if(!FileStream_GetSize(pStream, &FileSize))
    {
        printf("Failed to get the file size\n");
        return -1;
    }

    while(FileSize.QuadPart != 0)
    {
        DWORD dwBytesToRead = FileSize.LowPart;

        if(dwBytesToRead > sizeof(Buffer))
            dwBytesToRead = sizeof(Buffer);

        if(!FileStream_Read(pStream, NULL, Buffer, dwBytesToRead))
        {
            printf("CopyStream: Read source file failed\n");
            return -1;
        }

        if(!FileStream_Write(pTempStream, NULL, Buffer, dwBytesToRead))
        {
            printf("CopyStream: Write target file failed\n");
            return -1;
        }

        FileSize.QuadPart -= dwBytesToRead;
    }

    // Switch the streams
    // Note that the pTempStream is closed by the operation
    FileStream_MoveFile(pStream, pTempStream);
    FileStream_Close(pStream);

    //
    // Test4: Read from the stream again
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", false);
    if(pStream == NULL)
    {
        printf("Failed to open existing file\n");
        return -1;
    }

    for(int i = 0; i < 10; i++)
    {
        if(!FileStream_Read(pStream, NULL, szString2, dwLength))
        {
            printf("Failed to read from the stream\n");
            return -1;
        }

        szString2[dwLength] = 0;
        if(strcmp(szString1, szString2))
        {
            printf("Data read from file are different from data written\n");
            return -1;
        }
    }
    FileStream_Close(pStream);

    //
    // Test5: Open partial MPQ stream
    //

//  InitializeMpqCryptography();
    pStream = FileStream_OpenFile("e:\\Multimedia\\MPQs\\PartialMPQs\\patch.MPQ.part", false);
    if(pStream != NULL)
    {
        // Read the MPQ header
        FileStream_Read(pStream, NULL, &MpqHeader, MPQ_HEADER_SIZE_V2);

        // Read the hash table
        pHash = STORM_ALLOC(TMPQHash, MpqHeader.dwHashTableSize);
        FilePos.HighPart = 0;
        FilePos.LowPart = MpqHeader.dwHashTablePos;
        FileStream_Read(pStream, &FilePos, pHash, MpqHeader.dwHashTableSize * sizeof(TMPQHash));

        //
        // At this point, the encrypted hash table should be like this:
        //
        // 416c7175 5ddfb61b 84bb75c8 c0399515
        // a9793eca 9ec773d7 ed8a54d6 74fb2adf
        // 6acd4ae5 b13816b5 ffad2341 2f2b2a54
        // 614339c7 5fd0adf0 62434e91 d62439e3
        // 8f317aa5 f12706d6 bd83d2ca 97d7f108
        // 7586d373 51d85b05 8540beca f37ef3d7
        // d931d4d6 d592aadf 9044e960 c4592e92
        // 47dc03f7 0982dea4 afb31943 7c3c7cec
        // 0c28fd0d bcbfb7df 4d13b6e4 b5b0ef31
        // e1a33b70 ec30e4b9 7aaa5e7a fb6d46ec
        // 61732791 55fe757e 8ba18b5d d5f93246
        // 6d275f38 a89b5781 c34189a9 654c6472
        // 07e1d4e1 814bc8ee c72d2730 815afd43
        // 40bd2a92 640a9391 d868f813 0f61b73d
        // 6d202746 2c5124ca 65db3ad0 5b1c3e39
        // b731013c 73776405 eac0c746 6e50c938
        // a4a7fd00 56db3805 6d6dbab7 44fed28a
        // 2383394b bf617bdd a3edfaa2 e7d3aaaf
        //

        // Decrypt the hash table
//      DecryptMpqBlock(pHash, MpqHeader.dwHashTableSize * sizeof(TMPQHash), MPQ_KEY_HASH_TABLE);

        //
        // At this point, the hash table should be like this:
        //
        // c750beb9 72c2538a 00000000 00000466
        // ffffffff ffffffff ffffffff ffffffff
        // 898fdc7a 18963b5d 00000000 000005e1
        // ffffffff ffffffff ffffffff ffffffff
        // e3c6fc32 d8afff2b 00000000 000001ea
        // ffffffff ffffffff ffffffff ffffffff
        // ffffffff ffffffff ffffffff ffffffff
        // ffffffff ffffffff ffffffff ffffffff
        // ffffffff ffffffff ffffffff ffffffff
        // ffffffff ffffffff ffffffff ffffffff
        // ffffffff ffffffff ffffffff ffffffff
        // 0fa4fd60 3fbe8626 00000000 0000076f
        // 9ee5bccf 031b277b 00000000 0000095c
        // f4e154c5 0aadd1c1 00000000 00000876
        // 9e1ce9e7 e12d575d 00000000 0000071d
        //

        // Read the block table
        pBlock = STORM_ALLOC(TMPQBlock, MpqHeader.dwBlockTableSize);
        FilePos.HighPart = 0;
        FilePos.LowPart = MpqHeader.dwBlockTablePos;
        FileStream_Read(pStream, &FilePos, pBlock, MpqHeader.dwBlockTableSize * sizeof(TMPQBlock));

        //
        // At this point, the encrypted block table should be like this:
        //
        // 3d4867a7 ca0f533e f82c54d6 ed3c9dec
        // d8d607dc d9ad13ab f4588b46 8d058704
        // e8084fc8 63bc8064 b058c777 3683e9e3
        // 6c0da998 7703be0d 91ce3607 c14e29b9
        // 481b5c0d 42d902d2 8302acb7 e8f3e715
        // c9cdfc91 7cc38c15 ea3dfd22 ad20c856
        // b6450c7f 08522866 4cedb064 e03e3a86
        // 4509c7cc ddffbfc3 82fc8c66 e82a4424
        // afc4a982 23169037 5af6a3e2 34e1d24e
        // 362c9e34 846cfc3d 4c611fcd d645fe8f
        // f4061640 6d08d196 f330a975 66e30993
        // fd96a033 2b16def6 62ff30af 3e190b0b
        // 664a5b91 b8558235 fd631825 a7807be7
        // ec906b9b 76d8b32e 36f3ea0b 1b0f5391
        //

        // Decrypt the block table
//      DecryptMpqBlock(pBlock, MpqHeader.dwBlockTableSize * sizeof(TMPQBlock), MPQ_KEY_BLOCK_TABLE);

        //
        // At this point, the block table should be like this:
        //
        // 0000002c 00078093 00116824 84000200
        // 000780bf 000002d5 00008044 84000200
        // 00078394 00001516 0000874c 84000200
        // 000798aa 00003797 0000af4e 84000200
        // 0007d041 000001db 00008044 84000200
        // 0007d21c 0000005e 0000005e 84000200
        // 0007d27a 000022fb 00009674 84000200
        // 0007f575 00002389 00009c64 84000200
        // 000818fe 000023cb 00009d58 84000200
        // 00083cc9 000024d9 0000a0d8 84000200
        // 000861a2 00002356 00009c70 84000200
        // 000884f8 000023d3 00009da4 84000200
        // 0008a8cb 000022d6 00009cd4 84000200
        // 0008cba1 00002339 00009714 84000200
        // 0008eeda 000023dc 00009b24 84000200
        // 000912b6 00002481 00009eac 84000200
        // 00093737 00002444 0000a028 84000200
        // 00095b7b 00002440 00009fc4 84000200
        //

        FileStream_Close(pStream);
    }

    return 0;
}
*/
