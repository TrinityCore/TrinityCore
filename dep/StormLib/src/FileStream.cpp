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
#include "FileStream.h"

#ifdef _MSC_VER
#pragma comment(lib, "wininet.lib")
#endif

//-----------------------------------------------------------------------------
// Local defines

#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE ((HANDLE)-1)
#endif

#ifdef _MSC_VER
#pragma warning(disable: 4800)                  // 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
#endif

//-----------------------------------------------------------------------------
// Local functions - platform-specific functions

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

#ifndef PLATFORM_LITTLE_ENDIAN
void ConvertPartHeader(void * partHeader)
{
    PPART_FILE_HEADER theHeader = (PPART_FILE_HEADER)partHeader;

    theHeader->PartialVersion = SwapUInt32(theHeader->PartialVersion);
    theHeader->Flags          = SwapUInt32(theHeader->Flags);
    theHeader->FileSizeLo     = SwapUInt32(theHeader->FileSizeLo);
    theHeader->FileSizeHi     = SwapUInt32(theHeader->FileSizeHi);
    theHeader->BlockSize      = SwapUInt32(theHeader->BlockSize);
}
#endif

//-----------------------------------------------------------------------------
// Preparing file bitmap for a complete file of a given size

#define DEFAULT_BLOCK_SIZE 0x4000

static bool Dummy_GetBitmap(
    TFileStream * pStream,
    TFileBitmap * pBitmap,
    DWORD Length,
    LPDWORD LengthNeeded)
{
    ULONGLONG FileSize = 0;
    DWORD TotalLength;
    DWORD BlockCount;
    DWORD BitmapSize;
    DWORD LastByte;
    bool bResult = false;

    // Get file size and calculate bitmap length
    FileStream_GetSize(pStream, FileSize);
    BlockCount = (DWORD)(((FileSize - 1) / DEFAULT_BLOCK_SIZE) + 1);
    BitmapSize = (DWORD)(((BlockCount - 1) / 8) + 1);

    // Calculate and give the total length
    TotalLength = sizeof(TFileBitmap) + BitmapSize;
    if(LengthNeeded != NULL)
        *LengthNeeded = TotalLength;

    // Has the caller given enough space for storing the structure?
    if(Length >= sizeof(TFileBitmap))
    {
        memset(pBitmap, 0, sizeof(TFileBitmap));
        pBitmap->EndOffset  = FileSize;
        pBitmap->IsComplete = 1;
        pBitmap->BitmapSize = BitmapSize;
        pBitmap->BlockSize  = DEFAULT_BLOCK_SIZE;
        bResult = true;
    }

    // Do we have enough space to fill the bitmap as well?
    if(Length >= TotalLength)
    {
        LPBYTE pbBitmap = (LPBYTE)(pBitmap + 1);

        // Fill the full blocks
        memset(pbBitmap, 0xFF, (BlockCount / 8));
        pbBitmap += (BlockCount / 8);
        bResult = true;

        // Supply the last block
        if(BlockCount & 7)
        {
            LastByte = (1 << (BlockCount & 7)) - 1;
            pbBitmap[0] = (BYTE)LastByte;
        }
    }

    return bResult;
}

//-----------------------------------------------------------------------------
// Local functions - base file support

static bool BaseFile_Read(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.File.FilePos;
    DWORD dwBytesRead = 0;                  // Must be set by platform-specific code

#ifdef PLATFORM_WINDOWS
    {
        // Note: StormLib no longer supports Windows 9x.
        // Thus, we can use the OVERLAPPED structure to specify
        // file offset to read from file. This allows us to skip
        // one system call to SetFilePointer

        // Update the byte offset
        pStream->Base.File.FilePos = ByteOffset;

        // Read the data
        if(dwBytesToRead != 0)
        {
            OVERLAPPED Overlapped;

            Overlapped.OffsetHigh = (DWORD)(ByteOffset >> 32);
            Overlapped.Offset = (DWORD)ByteOffset;
            Overlapped.hEvent = NULL;
            if(!ReadFile(pStream->Base.File.hFile, pvBuffer, dwBytesToRead, &dwBytesRead, &Overlapped))
                return false;
        }
/*
        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(ByteOffset != pStream->Base.File.FilePos)
        {
            LONG ByteOffsetHi = (LONG)(ByteOffset >> 32);

            SetFilePointer(pStream->Base.File.hFile, (LONG)ByteOffset, &ByteOffsetHi, FILE_BEGIN);
            pStream->Base.File.FilePos = ByteOffset;
        }

        // Read the data
        if(dwBytesToRead != 0)
        {
            if(!ReadFile(pStream->Base.File.hFile, pvBuffer, dwBytesToRead, &dwBytesRead, NULL))
                return false;
        }
*/
    }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        ssize_t bytes_read;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(ByteOffset != pStream->Base.File.FilePos)
        {
            lseek((intptr_t)pStream->Base.File.hFile, (off_t)(ByteOffset), SEEK_SET);
            pStream->Base.File.FilePos = ByteOffset;
        }

        // Perform the read operation
        if(dwBytesToRead != 0)
        {
            bytes_read = read((intptr_t)pStream->Base.File.hFile, pvBuffer, (size_t)dwBytesToRead);
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
    pStream->Base.File.FilePos = ByteOffset + dwBytesRead;
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

static bool BaseFile_Write(TFileStream * pStream, ULONGLONG * pByteOffset, const void * pvBuffer, DWORD dwBytesToWrite)
{
    ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.File.FilePos;
    DWORD dwBytesWritten = 0;               // Must be set by platform-specific code

#ifdef PLATFORM_WINDOWS
    {
        // Note: StormLib no longer supports Windows 9x.
        // Thus, we can use the OVERLAPPED structure to specify
        // file offset to read from file. This allows us to skip
        // one system call to SetFilePointer

        // Update the byte offset
        pStream->Base.File.FilePos = ByteOffset;

        // Read the data
        if(dwBytesToWrite != 0)
        {
            OVERLAPPED Overlapped;

            Overlapped.OffsetHigh = (DWORD)(ByteOffset >> 32);
            Overlapped.Offset = (DWORD)ByteOffset;
            Overlapped.hEvent = NULL;
            if(!WriteFile(pStream->Base.File.hFile, pvBuffer, dwBytesToWrite, &dwBytesWritten, &Overlapped))
                return false;
        }
/*
        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(ByteOffset != pStream->Base.File.FilePos)
        {
            LONG ByteOffsetHi = (LONG)(ByteOffset >> 32);

            SetFilePointer(pStream->Base.File.hFile, (LONG)ByteOffset, &ByteOffsetHi, FILE_BEGIN);
            pStream->Base.File.FilePos = ByteOffset;
        }

        // Read the data
        if(dwBytesToWrite != 0)
        {
        if(!WriteFile(pStream->Base.File.hFile, pvBuffer, dwBytesToWrite, &dwBytesWritten, NULL))
            return false;
    }
*/
    }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        ssize_t bytes_written;

        // If the byte offset is different from the current file position,
        // we have to update the file position
        if(ByteOffset != pStream->Base.File.FilePos)
        {
            lseek((intptr_t)pStream->Base.File.hFile, (off_t)(ByteOffset), SEEK_SET);
            pStream->Base.File.FilePos = ByteOffset;
        }

        // Perform the read operation
        bytes_written = write((intptr_t)pStream->Base.File.hFile, pvBuffer, (size_t)dwBytesToWrite);
        if(bytes_written == -1)
        {
            nLastError = errno;
            return false;
        }
        
        dwBytesWritten = (DWORD)(size_t)bytes_written;
    }
#endif

    // Increment the current file position by number of bytes read
    pStream->Base.File.FilePos = ByteOffset + dwBytesWritten;

    // Also modify the file size, if needed
    if(pStream->Base.File.FilePos > pStream->Base.File.FileSize)
        pStream->Base.File.FileSize = pStream->Base.File.FilePos;

    if(dwBytesWritten != dwBytesToWrite)
        SetLastError(ERROR_DISK_FULL);
    return (dwBytesWritten == dwBytesToWrite);
}

static bool BaseFile_GetPos(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & ByteOffset)                 // Pointer to file byte offset
{
    ByteOffset = pStream->Base.File.FilePos;
    return true;
}

static bool BaseFile_GetSize(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
    FileSize = pStream->Base.File.FileSize;
    return true;
}

/**
 * \a pStream Pointer to an open stream
 * \a NewFileSize New size of the file
 */
static bool BaseFile_SetSize(TFileStream * pStream, ULONGLONG NewFileSize)
{
#ifdef PLATFORM_WINDOWS
    {
        LONG FileSizeHi = (LONG)(NewFileSize >> 32);
        LONG FileSizeLo;
        DWORD dwNewPos;
        bool bResult;

        // Set the position at the new file size
        dwNewPos = SetFilePointer(pStream->Base.File.hFile, (LONG)NewFileSize, &FileSizeHi, FILE_BEGIN);
        if(dwNewPos == INVALID_SET_FILE_POINTER && GetLastError() != ERROR_SUCCESS)
            return false;

        // Set the current file pointer as the end of the file
        bResult = (bool)SetEndOfFile(pStream->Base.File.hFile);

        // Restore the file position
        FileSizeHi = (LONG)(pStream->Base.File.FilePos >> 32);
        FileSizeLo = (LONG)(pStream->Base.File.FilePos);
        SetFilePointer(pStream->Base.File.hFile, FileSizeLo, &FileSizeHi, FILE_BEGIN);
        return bResult;
    }
#endif
    
#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        if(ftruncate((intptr_t)pStream->Base.File.hFile, (off_t)NewFileSize) == -1)
        {
            nLastError = errno;
            return false;
        }
        
        return true;
    }
#endif
}

static bool BaseFile_GetTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
    *pFileTime = pStream->Base.File.FileTime;
    return true;
}

// Renames the file pointed by pStream so that it contains data from pNewStream
static bool BaseFile_Switch(TFileStream * pStream, TFileStream * pNewStream)
{
#ifdef PLATFORM_WINDOWS
    // Delete the original stream file. Don't check the result value,
    // because if the file doesn't exist, it would fail
    DeleteFile(pStream->szFileName);

    // Rename the new file to the old stream's file
    return (bool)MoveFile(pNewStream->szFileName, pStream->szFileName);
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    // "rename" on Linux also works if the target file exists
    if(rename(pNewStream->szFileName, pStream->szFileName) == -1)
    {
        nLastError = errno;
        return false;
    }
    
    return true;
#endif
}

static void BaseFile_Close(TFileStream * pStream)
{
    if(pStream->Base.File.hFile != INVALID_HANDLE_VALUE)
    {
#ifdef PLATFORM_WINDOWS
        CloseHandle(pStream->Base.File.hFile);
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
        close((intptr_t)pStream->Base.File.hFile);
#endif
    }

    // Also invalidate the handle
    pStream->Base.File.hFile = INVALID_HANDLE_VALUE;
}

static bool BaseFile_Create(
    TFileStream * pStream,
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS
    {
        DWORD dwWriteShare = (dwStreamFlags & STREAM_FLAG_WRITE_SHARE) ? FILE_SHARE_WRITE : 0;

        pStream->Base.File.hFile = CreateFile(szFileName,
                                              GENERIC_READ | GENERIC_WRITE,
                                              dwWriteShare | FILE_SHARE_READ,
                                              NULL,
                                              CREATE_ALWAYS,
                                              0,
                                              NULL);
        if(pStream->Base.File.hFile == INVALID_HANDLE_VALUE)
            return false;
    }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        intptr_t handle;
        
        handle = open(szFileName, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if(handle == -1)
        {
            nLastError = errno;
            return false;
        }
        
        pStream->Base.File.hFile = (HANDLE)handle;
    }
#endif

    // Fill-in the entry points
    pStream->BaseRead    = BaseFile_Read;
    pStream->BaseWrite   = BaseFile_Write;
    pStream->BaseGetPos  = BaseFile_GetPos;
    pStream->BaseGetSize = BaseFile_GetSize;
    pStream->BaseSetSize = BaseFile_SetSize;
    pStream->BaseSetSize = BaseFile_SetSize;
    pStream->BaseGetTime = BaseFile_GetTime;
    pStream->BaseClose   = BaseFile_Close;

    // Reset the file position
    pStream->Base.File.FileSize = 0;
    pStream->Base.File.FilePos = 0;
    pStream->dwFlags = dwStreamFlags;
    return true;
}

static bool BaseFile_Open(
    TFileStream * pStream,
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS
    {
        ULARGE_INTEGER FileSize;
        DWORD dwDesiredAccess = (dwStreamFlags & STREAM_FLAG_READ_ONLY) ? GENERIC_READ : GENERIC_ALL;
        DWORD dwWriteShare = (dwStreamFlags & STREAM_FLAG_WRITE_SHARE) ? FILE_SHARE_WRITE : 0;

        // Open the file
        pStream->Base.File.hFile = CreateFile(szFileName,
                                              dwDesiredAccess,
                                              dwWriteShare | FILE_SHARE_READ,
                                              NULL,
                                              OPEN_EXISTING,
                                              0,
                                              NULL);
        if(pStream->Base.File.hFile == INVALID_HANDLE_VALUE)
            return false;

        // Query the file size
        FileSize.LowPart = GetFileSize(pStream->Base.File.hFile, &FileSize.HighPart);
        pStream->Base.File.FileSize = FileSize.QuadPart;

        // Query last write time
        GetFileTime(pStream->Base.File.hFile, NULL, NULL, (LPFILETIME)&pStream->Base.File.FileTime);
    }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        struct stat fileinfo;
        int oflag = (dwStreamFlags & STREAM_FLAG_READ_ONLY) ? O_RDONLY : O_RDWR;
        intptr_t handle;

        // Open the file
        handle = open(szFileName, oflag);
        if(handle == -1)
        {
            nLastError = errno;
            return false;
        }

        // Get the file size
        if(fstat(handle, &fileinfo) == -1)
        {
            nLastError = errno;
            return false;
        }

        // time_t is number of seconds since 1.1.1970, UTC.
        // 1 second = 10000000 (decimal) in FILETIME
        // Set the start to 1.1.1970 00:00:00
        pStream->Base.File.FileTime = 0x019DB1DED53E8000ULL + (10000000 * fileinfo.st_mtime);
        pStream->Base.File.FileSize = (ULONGLONG)fileinfo.st_size;
        pStream->Base.File.hFile = (HANDLE)handle;
    }
#endif

    // Fill-in the entry points
    pStream->BaseRead    = BaseFile_Read;
    pStream->BaseWrite   = BaseFile_Write;
    pStream->BaseGetPos  = BaseFile_GetPos;
    pStream->BaseGetSize = BaseFile_GetSize;
    pStream->BaseSetSize = BaseFile_SetSize;
    pStream->BaseGetTime = BaseFile_GetTime;
    pStream->BaseClose   = BaseFile_Close;

    // Reset the file position
    pStream->Base.File.FilePos = 0;
    pStream->dwFlags = dwStreamFlags;
    return true;
}

//-----------------------------------------------------------------------------
// Local functions - base memory-mapped file support

static bool BaseMap_Read(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.Map.FilePos;

    // Do we have to read anything at all?
    if(dwBytesToRead != 0)
    {
        // Don't allow reading past file size
        if((ByteOffset + dwBytesToRead) > pStream->Base.Map.FileSize)
            return false;

        // Copy the required data
        memcpy(pvBuffer, pStream->Base.Map.pbFile + (size_t)ByteOffset, dwBytesToRead);
    }

    // Move the current file position
    pStream->Base.Map.FilePos += dwBytesToRead;
    return true;
}

static bool BaseMap_GetPos(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & ByteOffset)                 // Pointer to file byte offset
{
    ByteOffset = pStream->Base.Map.FilePos;
    return true;
}

static bool BaseMap_GetSize(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
    FileSize = pStream->Base.Map.FileSize;
    return true;
}

static bool BaseMap_GetTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
    *pFileTime = pStream->Base.Map.FileTime;
    return true;
}

static void BaseMap_Close(TFileStream * pStream)
{
#ifdef PLATFORM_WINDOWS
    if(pStream->Base.Map.pbFile != NULL)
        UnmapViewOfFile(pStream->Base.Map.pbFile);
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    if(pStream->Base.Map.pbFile != NULL)
        munmap(pStream->Base.Map.pbFile, (size_t )pStream->Base.Map.FileSize);
#endif

    pStream->Base.Map.pbFile = NULL;
}

static bool BaseMap_Open(
    TFileStream * pStream,
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS

    ULARGE_INTEGER FileSize;
    HANDLE hFile;
    HANDLE hMap;
    bool bResult = false;

    // Open the file for read access
    hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if(hFile != NULL)
    {
        // Retrieve file size. Don't allow mapping file of a zero size.
        FileSize.LowPart = GetFileSize(hFile, &FileSize.HighPart);
        if(FileSize.QuadPart != 0)
        {
            // Retrieve file time
            GetFileTime(hFile, NULL, NULL, (LPFILETIME)&pStream->Base.Map.FileTime);

            // Now create mapping object
            hMap = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
            if(hMap != NULL)
            {
                // Map the entire view into memory
                // Note that this operation will fail if the file can't fit
                // into usermode address space
                pStream->Base.Map.pbFile = (LPBYTE)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
                if(pStream->Base.Map.pbFile != NULL)
                {
                    pStream->Base.Map.FileSize = FileSize.QuadPart;
                    pStream->Base.Map.FilePos = 0;
                    bResult = true;
                }

                // Close the map handle
                CloseHandle(hMap);
            }
        }

        // Close the file handle
        CloseHandle(hFile);
    }

    // If the file is not there and is not available for random access,
    // report error
    if(bResult == false)
        return false;
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    struct stat fileinfo;
    intptr_t handle;
    bool bResult = false;

    // Open the file
    handle = open(szFileName, O_RDONLY);
    if(handle != -1)
    {
        // Get the file size
        if(fstat(handle, &fileinfo) != -1)
        {
            pStream->Base.Map.pbFile = (LPBYTE)mmap(NULL, (size_t)fileinfo.st_size, PROT_READ, MAP_PRIVATE, handle, 0);
            if(pStream->Base.Map.pbFile != NULL)
            {
                // time_t is number of seconds since 1.1.1970, UTC.
                // 1 second = 10000000 (decimal) in FILETIME
                // Set the start to 1.1.1970 00:00:00
                pStream->Base.Map.FileTime = 0x019DB1DED53E8000ULL + (10000000 * fileinfo.st_mtime);
                pStream->Base.Map.FileSize = (ULONGLONG)fileinfo.st_size;
                pStream->Base.Map.FilePos = 0;
                bResult = true;
            }
        }
        close(handle);
    }

    // Did the mapping fail?
    if(bResult == false)
    {
        nLastError = errno;
        return false;
    }
#endif

    // Fill-in entry points
    pStream->BaseRead    = BaseMap_Read;
    pStream->BaseGetPos  = BaseMap_GetPos;
    pStream->BaseGetSize = BaseMap_GetSize;
    pStream->BaseGetTime = BaseMap_GetTime;
    pStream->BaseClose   = BaseMap_Close;
    pStream->dwFlags = dwStreamFlags;
    return true;
}

//-----------------------------------------------------------------------------
// Local functions - base HTTP file support

static const TCHAR * BaseHttp_ExtractServerName(const TCHAR * szFileName, TCHAR * szServerName)
{
    // Check for HTTP
    if(!_tcsnicmp(szFileName, _T("http://"), 7))
        szFileName += 7;

    // Cut off the server name
    if(szServerName != NULL)
    {
        while(szFileName[0] != 0 && szFileName[0] != _T('/'))
            *szServerName++ = *szFileName++;
        *szServerName = 0;
    }
    else
    {
        while(szFileName[0] != 0 && szFileName[0] != _T('/'))
            *szFileName++;
    }

    // Return the remainder
    return szFileName;
}

static bool BaseHttp_Read(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
#ifdef PLATFORM_WINDOWS
    ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.Http.FilePos;
    DWORD dwTotalBytesRead = 0;

    // Do we have to read anything at all?
    if(dwBytesToRead != 0)
    {
        HINTERNET hRequest;
        LPCTSTR szFileName;
        LPBYTE pbBuffer = (LPBYTE)pvBuffer;
        TCHAR szRangeRequest[0x80];
        DWORD dwStartOffset = (DWORD)ByteOffset;
        DWORD dwEndOffset = dwStartOffset + dwBytesToRead;
        BYTE Buffer[0x200];

        // Open HTTP request to the file
        szFileName = BaseHttp_ExtractServerName(pStream->szFileName, NULL);
        hRequest = HttpOpenRequest(pStream->Base.Http.hConnect, _T("GET"), szFileName, NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if(hRequest != NULL)
        {
            // Add range request to the HTTP headers
            // http://www.clevercomponents.com/articles/article015/resuming.asp
            _stprintf(szRangeRequest, _T("Range: bytes=%d-%d"), dwStartOffset, dwEndOffset);
            HttpAddRequestHeaders(hRequest, szRangeRequest, 0xFFFFFFFF, HTTP_ADDREQ_FLAG_ADD_IF_NEW); 

            // Send the request to the server
            if(HttpSendRequest(hRequest, NULL, 0, NULL, 0))
            {
                while(dwTotalBytesRead < dwBytesToRead)
                {
                    DWORD dwBlockBytesToRead = dwBytesToRead - dwTotalBytesRead;
                    DWORD dwBlockBytesRead = 0;

                    // Read the block from the file
                    if(dwBlockBytesToRead > sizeof(Buffer))
                        dwBlockBytesToRead = sizeof(Buffer);
                    InternetReadFile(hRequest, pbBuffer, dwBlockBytesToRead, &dwBlockBytesRead);

                    // Check for end
                    if(dwBlockBytesRead == 0)
                        break;

                    // Move buffers
                    dwTotalBytesRead += dwBlockBytesRead;
                    pbBuffer += dwBlockBytesRead;
                }
            }
            InternetCloseHandle(hRequest);
        }
    }

    // Increment the current file position by number of bytes read
    pStream->Base.Http.FilePos = ByteOffset + dwTotalBytesRead;

    // If the number of bytes read doesn't match the required amount, return false
    if(dwTotalBytesRead != dwBytesToRead)
        SetLastError(ERROR_HANDLE_EOF);
    return (dwTotalBytesRead == dwBytesToRead);

#else

    // Not supported
    pStream = pStream;
    pByteOffset = pByteOffset;
    pvBuffer = pvBuffer;
    dwBytesToRead = dwBytesToRead;
    SetLastError(ERROR_NOT_SUPPORTED);
    return false;

#endif
}

static bool BaseHttp_GetPos(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & ByteOffset)                 // Pointer to file byte offset
{
    ByteOffset = pStream->Base.Http.FilePos;
    return true;
}

static bool BaseHttp_GetSize(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
    FileSize = pStream->Base.Http.FileSize;
    return true;
}

static bool BaseHttp_GetTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
    *pFileTime = pStream->Base.Http.FileTime;
    return true;
}

static void BaseHttp_Close(TFileStream * pStream)
{
#ifdef PLATFORM_WINDOWS
    if(pStream->Base.Http.hConnect != NULL)
        InternetCloseHandle(pStream->Base.Http.hConnect);
    pStream->Base.Http.hConnect = NULL;

    if(pStream->Base.Http.hInternet != NULL)
        InternetCloseHandle(pStream->Base.Http.hInternet);
    pStream->Base.Http.hInternet = NULL;
#else
    pStream = pStream;
#endif
}

static bool BaseHttp_Open(
    TFileStream * pStream,
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS

    HINTERNET hRequest;
    DWORD dwTemp = 0;
    bool bFileAvailable = false;
    int nError = ERROR_SUCCESS;

    // Don't connect to the internet
    if(!InternetGetConnectedState(&dwTemp, 0))
        nError = GetLastError();

    // Initiate the connection to the internet
    if(nError == ERROR_SUCCESS)
    {
        pStream->Base.Http.hInternet = InternetOpen(_T("StormLib HTTP MPQ reader"),
                                                    INTERNET_OPEN_TYPE_PRECONFIG,
                                                    NULL,
                                                    NULL,
                                                    0);
        if(pStream->Base.Http.hInternet == NULL)
            nError = GetLastError();
    }

    // Connect to the server
    if(nError == ERROR_SUCCESS)
    {
        TCHAR szServerName[MAX_PATH];
        DWORD dwFlags = INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_UI | INTERNET_FLAG_NO_CACHE_WRITE;

        // Initiate connection with the server
        szFileName = BaseHttp_ExtractServerName(szFileName, szServerName);
        pStream->Base.Http.hConnect = InternetConnect(pStream->Base.Http.hInternet,
                                                      szServerName,
                                                      INTERNET_DEFAULT_HTTP_PORT,
                                                      NULL,
                                                      NULL,
                                                      INTERNET_SERVICE_HTTP,
                                                      dwFlags,
                                                      0);
        if(pStream->Base.Http.hConnect == NULL)
            nError = GetLastError();
    }

    // Now try to query the file size
    if(nError == ERROR_SUCCESS)
    {
        // Open HTTP request to the file
        hRequest = HttpOpenRequest(pStream->Base.Http.hConnect, _T("GET"), szFileName, NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if(hRequest != NULL)
        {
            if(HttpSendRequest(hRequest, NULL, 0, NULL, 0))
            {
                ULONGLONG FileTime = 0;
                DWORD dwFileSize = 0;
                DWORD dwDataSize;
                DWORD dwIndex = 0;

                // Check if the MPQ has Last Modified field
                dwDataSize = sizeof(ULONGLONG);
                if(HttpQueryInfo(hRequest, HTTP_QUERY_LAST_MODIFIED | HTTP_QUERY_FLAG_SYSTEMTIME, &FileTime, &dwDataSize, &dwIndex))
                    pStream->Base.Http.FileTime = FileTime;

                // Verify if the server supports random access
                dwDataSize = sizeof(DWORD);
                if(HttpQueryInfo(hRequest, HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER, &dwFileSize, &dwDataSize, &dwIndex))
                {
                    if(dwFileSize != 0)
                    {
                        pStream->Base.Http.FileSize = dwFileSize;
                        pStream->Base.Http.FilePos = 0;
                        bFileAvailable = true;
                    }
                }
            }
            InternetCloseHandle(hRequest);
        }
    }

    // If the file is not there and is not available for random access,
    // report error
    if(bFileAvailable == false)
    {
        BaseHttp_Close(pStream);
        return false;
    }

    // Fill-in entry points
    pStream->BaseRead    = BaseHttp_Read;
    pStream->BaseGetPos  = BaseHttp_GetPos;
    pStream->BaseGetSize = BaseHttp_GetSize;
    pStream->BaseGetTime = BaseHttp_GetTime;
    pStream->BaseClose   = BaseHttp_Close;
    pStream->dwFlags = dwStreamFlags;
    return true;

#else

    // Not supported
    pStream = pStream;
    szFileName = szFileName;
    SetLastError(ERROR_NOT_SUPPORTED);
    return false;

#endif
}

//-----------------------------------------------------------------------------
// Local functions - linear stream support

static bool LinearStream_Read(
    TLinearStream * pStream,                // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    ULONGLONG ByteOffset;
    ULONGLONG EndOffset;
    LPBYTE pbBitmap;
    DWORD BlockIndex;
    DWORD ByteIndex;
    DWORD BitMask;

    // At this point, we must have a bitmap set
    assert(pStream->pBitmap != NULL);

    // If we have data map, we must check if the data block is present in the MPQ
    if(dwBytesToRead != 0)
    {
        DWORD BlockSize = pStream->pBitmap->BlockSize;

        // Get the offset where we read it from
        if(pByteOffset == NULL)
            pStream->BaseGetPos(pStream, ByteOffset);
        else
            ByteOffset = *pByteOffset;
        EndOffset = ByteOffset + dwBytesToRead;

        // If the start of the area is within the region
        // protected by data map, check each block
        if(ByteOffset < pStream->pBitmap->EndOffset)
        {
            // Cut the end of the stream protected by the data map
            EndOffset = STORMLIB_MIN(EndOffset, pStream->pBitmap->EndOffset);

            // Calculate the initial block index
            BlockIndex = (DWORD)(ByteOffset / BlockSize);
            pbBitmap = (LPBYTE)(pStream->pBitmap + 1);

            // Parse each block
            while(ByteOffset < EndOffset)
            {
                // Prepare byte index and bit mask
                ByteIndex = BlockIndex / 8;
                BitMask = 1 << (BlockIndex & 0x07);

                // If that bit is not set, it means that the block is not present
                if((pbBitmap[ByteIndex] & BitMask) == 0)
                {
                    SetLastError(ERROR_FILE_CORRUPT);
                    return false;
                }

                // Move to tne next block
                ByteOffset += BlockSize;
                BlockIndex++;
            }
        }
    }

    // Now if all tests passed, we can call the base read function
    return pStream->BaseRead(pStream, pByteOffset, pvBuffer, dwBytesToRead);
}

static bool LinearStream_Switch(TLinearStream * pStream, TLinearStream * pNewStream)
{
    // Sanity checks
    assert((pNewStream->dwFlags & STREAM_PROVIDER_MASK) == STREAM_PROVIDER_LINEAR);
    assert((pNewStream->dwFlags & BASE_PROVIDER_MASK) == BASE_PROVIDER_FILE);
    assert((pStream->dwFlags & STREAM_PROVIDER_MASK) == STREAM_PROVIDER_LINEAR);
    assert((pStream->dwFlags & BASE_PROVIDER_MASK) == BASE_PROVIDER_FILE);

    // Close the new stream
    pNewStream->BaseClose(pNewStream);

    // Close the source stream
    pStream->BaseClose(pStream);

    // Rename the new data source file to the existing file
    if(!BaseFile_Switch(pStream, pNewStream))
        return false;

    // Now we have to open the "pStream" again
    if(!BaseFile_Open(pStream, pStream->szFileName, pNewStream->dwFlags))
        return false;

    // We need to cleanup the new data stream
    FileStream_Close(pNewStream);
    return true;
}

static bool LinearStream_GetBitmap(
    TLinearStream * pStream,
    TFileBitmap * pBitmap,
    DWORD Length,
    LPDWORD LengthNeeded)
{
    DWORD TotalLength;
    bool bResult = false;

    // Assumed that we have bitmap now
    assert(pStream->pBitmap != NULL);

    // Give the bitmap length
    TotalLength = sizeof(TFileBitmap) + pStream->pBitmap->BitmapSize;
    if(LengthNeeded != NULL)
        *LengthNeeded = TotalLength;

    // Do we have enough space to fill at least the bitmap structure?
    if(Length >= sizeof(TFileBitmap))
    {
        // Enough space for complete bitmap?
        if(Length >= TotalLength)
        {
            memcpy(pBitmap, pStream->pBitmap, TotalLength);
            bResult = true;
        }
        else
        {
            memcpy(pBitmap, pStream->pBitmap, sizeof(TFileBitmap));
            bResult = true;
        }
    }

    return bResult;
}

static void LinearStream_Close(TLinearStream * pStream)
{
    // Free the data map, if any
    if(pStream->pBitmap != NULL)
        STORM_FREE(pStream->pBitmap);
    pStream->pBitmap = NULL;
    
    // Call the base class for closing the stream
    return pStream->BaseClose(pStream);
}

static bool LinearStream_Open(TLinearStream * pStream)
{
    // No extra work here really; just set entry points
    pStream->StreamRead    = pStream->BaseRead;
    pStream->StreamWrite   = pStream->BaseWrite;
    pStream->StreamGetPos  = pStream->BaseGetPos;
    pStream->StreamGetSize = pStream->BaseGetSize;
    pStream->StreamSetSize = pStream->BaseSetSize;
    pStream->StreamGetTime = pStream->BaseGetTime;
    pStream->StreamGetBmp  = (STREAM_GETBMP)Dummy_GetBitmap;
    pStream->StreamSwitch  = (STREAM_SWITCH)LinearStream_Switch;
    pStream->StreamClose   = (STREAM_CLOSE)LinearStream_Close;
    return true;
}

//-----------------------------------------------------------------------------
// Local functions - partial stream support

static bool IsPartHeader(PPART_FILE_HEADER pPartHdr)
{
    // Version number must be 2
    if(pPartHdr->PartialVersion == 2)
    {
        // GameBuildNumber must be an ASCII number
        if(isdigit(pPartHdr->GameBuildNumber[0]) && isdigit(pPartHdr->GameBuildNumber[1]) && isdigit(pPartHdr->GameBuildNumber[2]))
        {
            // Block size must be power of 2
            if((pPartHdr->BlockSize & (pPartHdr->BlockSize - 1)) == 0)
                return true;
        }
    }

    return false;
}

static bool PartialStream_Read(
    TPartialStream * pStream,
    ULONGLONG * pByteOffset,
    void * pvBuffer,
    DWORD dwBytesToRead)
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
            nFailReason = ERROR_FILE_CORRUPT;
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
            nFailReason = ERROR_FILE_CORRUPT;
            bResult = false;
            break;
        }

        // If the number of bytes in part is too big, cut it
        if(dwBytesInPart > dwBytesRemaining)
            dwBytesInPart = dwBytesRemaining;

        // Append the offset within the part
        RawByteOffset += dwPartOffset;
        if(!pStream->BaseRead(pStream, &RawByteOffset, pbBuffer, dwBytesInPart))
        {
            nFailReason = ERROR_FILE_CORRUPT;
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

static bool PartialStream_GetPos(
    TPartialStream * pStream,
    ULONGLONG & ByteOffset)
{
    ByteOffset = pStream->VirtualPos;
    return true;
}

static bool PartialStream_GetSize(
    TPartialStream * pStream,               // Pointer to an open stream
    ULONGLONG & FileSize)                   // Pointer where to store file size
{
    FileSize = pStream->VirtualSize;
    return true;
}

static bool PartialStream_GetBitmap(
    TPartialStream * pStream,
    TFileBitmap * pBitmap,
    DWORD Length,
    LPDWORD LengthNeeded)
{
    LPBYTE pbBitmap;
    DWORD TotalLength;
    DWORD BitmapSize = 0;
    DWORD ByteOffset;
    DWORD BitMask;
    bool bResult = false;

    // Do we have stream bitmap?
    BitmapSize = ((pStream->BlockCount - 1) / 8) + 1;

    // Give the bitmap length
    TotalLength = sizeof(TFileBitmap) + BitmapSize;
    if(LengthNeeded != NULL)
        *LengthNeeded = TotalLength;

    // Do we have enough to fill at least the header?
    if(Length >= sizeof(TFileBitmap))
    {
        // Fill the bitmap header
        pBitmap->StartOffset = 0;
        pBitmap->EndOffset  = pStream->VirtualSize;
        pBitmap->IsComplete = 1;
        pBitmap->BitmapSize = BitmapSize;
        pBitmap->BlockSize = pStream->BlockSize;
        pBitmap->Reserved = 0;
        
        // Is there at least one incomplete block?
        for(DWORD i = 0; i < pStream->BlockCount; i++)
        {
            if(pStream->PartMap[i].Flags != 3)
            {
                pBitmap->IsComplete = 0;
                break;
            }
        }

        bResult = true;
    }
    
    // Do we have enough space for supplying the bitmap?
    if(Length >= TotalLength)
    {
        // Fill the file bitmap
        pbBitmap = (LPBYTE)(pBitmap + 1);
        for(DWORD i = 0; i < pStream->BlockCount; i++)
        {
            // Is the block there?
            if(pStream->PartMap[i].Flags == 3)
            {
                ByteOffset = i / 8;
                BitMask = 1 << (i & 7);
                pbBitmap[ByteOffset] |= BitMask;
            }
        }
        bResult = true;
    }

    return bResult;
}

static void PartialStream_Close(TPartialStream * pStream)
{
    // Free the part map
    if(pStream->PartMap != NULL)
        STORM_FREE(pStream->PartMap);
    pStream->PartMap = NULL;

    // Clear variables
    pStream->VirtualSize = 0;
    pStream->VirtualPos = 0;

    // Close the base stream
    assert(pStream->BaseClose != NULL);
    pStream->BaseClose(pStream);
}

static bool PartialStream_Open(TPartialStream * pStream)
{
    PART_FILE_HEADER PartHdr;
    ULONGLONG VirtualSize;                  // Size of the file stored in part file
    ULONGLONG ByteOffset = {0};
    DWORD BlockCount;

    // Sanity check
    assert(pStream->BaseRead != NULL);

    // Attempt to read PART file header
    if(pStream->BaseRead(pStream, &ByteOffset, &PartHdr, sizeof(PART_FILE_HEADER)))
    {
        // We need to swap PART file header on big-endian platforms
        BSWAP_PART_HEADER(&PartHdr);

        // Verify the PART file header
        if(IsPartHeader(&PartHdr))
        {
            // Calculate the number of parts in the file
            VirtualSize = MAKE_OFFSET64(PartHdr.FileSizeHi, PartHdr.FileSizeLo);
            assert(VirtualSize != 0);
            BlockCount = (DWORD)((VirtualSize + PartHdr.BlockSize - 1) / PartHdr.BlockSize);

            // Allocate the map entry array
            pStream->PartMap = STORM_ALLOC(PART_FILE_MAP_ENTRY, BlockCount);
            if(pStream->PartMap != NULL)
            {
                // Load the block map
                if(pStream->BaseRead(pStream, NULL, pStream->PartMap, BlockCount * sizeof(PART_FILE_MAP_ENTRY)))
                {
                    // Swap the array of file map entries
                    BSWAP_ARRAY32_UNSIGNED(pStream->PartMap, BlockCount * sizeof(PART_FILE_MAP_ENTRY));

                    // Fill the members of PART file stream
                    pStream->VirtualSize   = ((ULONGLONG)PartHdr.FileSizeHi) + PartHdr.FileSizeLo;
                    pStream->VirtualPos    = 0;
                    pStream->BlockCount    = BlockCount;
                    pStream->BlockSize     = PartHdr.BlockSize;

                    // Set new function pointers
                    pStream->StreamRead    = (STREAM_READ)PartialStream_Read;
                    pStream->StreamGetPos  = (STREAM_GETPOS)PartialStream_GetPos;
                    pStream->StreamGetSize = (STREAM_GETSIZE)PartialStream_GetSize;
                    pStream->StreamGetTime = pStream->BaseGetTime;
                    pStream->StreamGetTime = pStream->BaseGetTime;
                    pStream->StreamGetBmp  = (STREAM_GETBMP)PartialStream_GetBitmap;
                    pStream->StreamClose   = (STREAM_CLOSE)PartialStream_Close;
                    return true;
                }

                // Free the part map
                STORM_FREE(pStream->PartMap);
                pStream->PartMap = NULL;
            }
        }
    }

    SetLastError(ERROR_BAD_FORMAT);
    return false;
}

//-----------------------------------------------------------------------------
// Local functions - encrypted stream support

// Note: Starcraft II - Installer.exe (4.1.1.4219):                    Suffix derived from battle.net auth. code
// Address of decryption routine: 0053A3D0                             http://us.battle.net/static/mediakey/sc2-authenticationcode-enUS.txt
// Pointer to decryptor object: ECX                                    Numbers mean offset of 4-char group of auth code (follows in comment)
// Pointer to key: ECX+0x5C                                            -0C-    -1C--08-    -18--04-    -14--00-    -10-
static const char * MpqeKey_Starcraft2_Install_deDE = "expand 32-byte kSSXH00004XFXK4KX00008EKJD3CA0000Y64ZY45M0000YD9V";   // Y45MD3CAK4KXSSXHYD9VY64Z8EKJ4XFX
static const char * MpqeKey_Starcraft2_Install_enGB = "expand 32-byte kANGY000029ZH6NA20000HRGF8UDG0000NY82G8MN00006A3D";   // G8MN8UDG6NA2ANGY6A3DNY82HRGF29ZH
static const char * MpqeKey_Starcraft2_Install_enSG = "expand 32-byte kWW5B0000F7HWFDU90000FWZSHLB20000BLRSW9RR00003ECE";   // W9RRHLB2FDU9WW5B3ECEBLRSFWZSF7HW
static const char * MpqeKey_Starcraft2_Install_enUS = "expand 32-byte kTFD80000ETR5VM5G0000K859RE5N0000WT6F3DH500005LXG";   // 3DH5RE5NVM5GTFD85LXGWT6FK859ETR5
static const char * MpqeKey_Starcraft2_Install_esES = "expand 32-byte kQU4Y0000XKTQ94PF0000N4R4UAXE0000AZ248WLK0000249P";   // 8WLKUAXE94PFQU4Y249PAZ24N4R4XKTQ
static const char * MpqeKey_Starcraft2_Install_esMX = "expand 32-byte kSQBR00004G54HGGX0000MF9GXX3V0000FFDXA34D0000FE5U";   // A34DXX3VHGGXSQBRFE5UFFDXMF9G4G54
static const char * MpqeKey_Starcraft2_Install_frFR = "expand 32-byte kFWPQ00006EAJ8HJE0000PFER9K9300008MA2ZG7J0000UA76";   // ZG7J9K938HJEFWPQUA768MA2PFER6EAJ
static const char * MpqeKey_Starcraft2_Install_itIT = "expand 32-byte kXV7E00008BL2TVAP0000GVMWUNNN0000SVBWNE7C00003G2B";   // NE7CUNNNTVAPXV7E3G2BSVBWGVMW8BL2
static const char * MpqeKey_Starcraft2_Install_koKR = "expand 32-byte kQWK70000838FBM9Q0000WQDB2FTM0000MWAZ3V9E0000U6MA";   // 3V9E2FTMBM9QQWK7U6MAMWAZWQDB838F
static const char * MpqeKey_Starcraft2_Install_plPL = "expand 32-byte k83U6000048L6LULJ00004MQDB8ME0000UP6K2NSF0000YHA3";   // 2NSFB8MELULJ83U6YHA3UP6K4MQD48L6
static const char * MpqeKey_Starcraft2_Install_ptBR = "expand 32-byte kU8BM0000SW4EZ4CU00005F9CZ9EW0000CTY6QA2T0000B5WX";   // QA2TZ9EWZ4CUU8BMB5WXCTY65F9CSW4E
static const char * MpqeKey_Starcraft2_Install_ruRU = "expand 32-byte k9SH70000YEGT4BAT0000QDK978W60000V9NLVHB30000D68V";   // VHB378W64BAT9SH7D68VV9NLQDK9YEGT
static const char * MpqeKey_Starcraft2_Install_zhTW = "expand 32-byte k7KBN0000D9NEM6GC0000N3PLQJV400003BRDU3NF00009XQJ";   // U3NFQJV4M6GC7KBN9XQJ3BRDN3PLD9NE

// Note: Diablo III: Agent.exe (1.0.0.954):                            Suffix derived from battle.net auth. code
// Address of decryption routine: 00502b00                             http://dist.blizzard.com/mediakey/d3-authenticationcode-enGB.txt
// Pointer to decryptor object: ECX                                    Numbers mean offset of 4-char group of auth code (follows in comment)
// Pointer to key: ECX+0x5C                                            -0C-    -1C--08-    -18--04-    -14--00-    -10-
static const char * MpqeKey_Diablo3_Install_deDE    = "expand 32-byte kEFH40000QRZKY3520000XC9MF6EJ0000CFH2UCMX0000XFRX";   // UCMXF6EJY352EFH4XFRXCFH2XC9MQRZK
static const char * MpqeKey_Diablo3_Install_enGB    = "expand 32-byte kXP4G0000PHBPRP7W0000J9UNHY4800007SL9MMKV0000HYBQ";   // MMKVHY48RP7WXP4GHYBQ7SL9J9UNPHBP
static const char * MpqeKey_Diablo3_Install_enSG    = "expand 32-byte kTZ9M00003CPPVGGL0000JYETWHQ70000FDCL8MXL0000QZQS";   // 8MXLWHQ7VGGLTZ9MQZQSFDCLJYET3CPP
static const char * MpqeKey_Diablo3_Install_enUS    = "expand 32-byte kGUNG0000WZSZXFE20000UAKP5TM60000HKQ9EJ2R00005QDG";   // EJ2R5TM6XFE2GUNG5QDGHKQ9UAKPWZSZ
static const char * MpqeKey_Diablo3_Install_esES    = "expand 32-byte kK65U0000HQQTZ6LN0000CLP4BE420000WZVMPBGF0000GJQ3";   // PBGFBE42Z6LNK65UGJQ3WZVMCLP4HQQT
static const char * MpqeKey_Diablo3_Install_esMX    = "expand 32-byte kW5P200008VU2TSGC0000JPEYJJS90000C47AX7SE00008EBS";   // X7SEJJS9TSGCW5P28EBSC47AJPEY8VU2
static const char * MpqeKey_Diablo3_Install_frFR    = "expand 32-byte kRY3D00007YA2YE6X0000XS4PQA8V0000ZDE45KVB0000LGC5";   // 5KVBQA8VYE6XRY3DLGC5ZDE4XS4P7YA2
static const char * MpqeKey_Diablo3_Install_itIT    = "expand 32-byte kVVY40000B2546EVN00005B8KD2K50000DWYT478J0000XX8T";   // 478JD2K56EVNVVY4XX8TDWYT5B8KB254
static const char * MpqeKey_Diablo3_Install_koKR    = "expand 32-byte k6YWH0000474ARZTN0000NVWDVNFQ0000VDH98TS40000E9CH";   // 8TS4VNFQRZTN6YWHE9CHVDH9NVWD474A
static const char * MpqeKey_Diablo3_Install_plPL    = "expand 32-byte k4ZJJ0000BLJBF4LZ0000A6GAZ32D00003AZQLJ520000XVKK";   // LJ52Z32DF4LZ4ZJJXVKK3AZQA6GABLJB
static const char * MpqeKey_Diablo3_Install_ptBR    = "expand 32-byte k545Y0000XYAGCUE20000WHE7HY2E0000JPVYK6BD0000KNLB";   // K6BDHY2ECUE2545YKNLBJPVYWHE7XYAG
static const char * MpqeKey_Diablo3_Install_ruRU    = "expand 32-byte kXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";   // 
static const char * MpqeKey_Diablo3_Install_zhTW    = "expand 32-byte kMRUC0000AA8HV3ZZ0000UX2TQTN80000A8CG6VWC0000ZXV8";   // 6VWCQTN8V3ZZMRUCZXV8A8CGUX2TAA8H
static const char * MpqeKey_Diablo3_Install_zhCN    = "expand 32-byte kXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";   // 
                                                                      
static const char * MpqKeyArray[] =
{
    MpqeKey_Starcraft2_Install_deDE,
    MpqeKey_Starcraft2_Install_enGB,
    MpqeKey_Starcraft2_Install_enSG,
    MpqeKey_Starcraft2_Install_enUS,
    MpqeKey_Starcraft2_Install_esES,
    MpqeKey_Starcraft2_Install_esMX,
    MpqeKey_Starcraft2_Install_frFR,
    MpqeKey_Starcraft2_Install_itIT,
    MpqeKey_Starcraft2_Install_koKR,
    MpqeKey_Starcraft2_Install_plPL,
    MpqeKey_Starcraft2_Install_ptBR,
    MpqeKey_Starcraft2_Install_ruRU,
    MpqeKey_Starcraft2_Install_zhTW,

    MpqeKey_Diablo3_Install_deDE,
    MpqeKey_Diablo3_Install_enGB,
    MpqeKey_Diablo3_Install_enSG,
    MpqeKey_Diablo3_Install_enUS,
    MpqeKey_Diablo3_Install_esES,
    MpqeKey_Diablo3_Install_esMX,
    MpqeKey_Diablo3_Install_frFR,
    MpqeKey_Diablo3_Install_itIT,
    MpqeKey_Diablo3_Install_koKR,
    MpqeKey_Diablo3_Install_plPL,
    MpqeKey_Diablo3_Install_ptBR,
//  MpqeKey_Diablo3_Install_ruRU,
    MpqeKey_Diablo3_Install_zhTW,
//  MpqeKey_Diablo3_Install_zhCN,

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

static const char * DetectFileKey(LPBYTE pbEncryptedHeader)
{
    ULONGLONG ByteOffset = 0;
    BYTE FileHeader[MPQE_CHUNK_SIZE];
    BYTE Key[MPQE_CHUNK_SIZE];

    // We just try all known keys one by one
    for(int i = 0; MpqKeyArray[i] != NULL; i++)
    {
        // Copy the key there
        memcpy(Key, MpqKeyArray[i], MPQE_CHUNK_SIZE);
        BSWAP_ARRAY32_UNSIGNED(Key, MPQE_CHUNK_SIZE);

        // Try to decrypt with the given key 
        memcpy(FileHeader, pbEncryptedHeader, MPQE_CHUNK_SIZE);
        DecryptFileChunk((LPDWORD)FileHeader, Key, ByteOffset, MPQE_CHUNK_SIZE);

        // We check the decrypted data
        // All known encrypted MPQs have header at the begin of the file,
        // so we check for MPQ signature there.
        if(FileHeader[0] == 'M' && FileHeader[1] == 'P' && FileHeader[2] == 'Q')
            return MpqKeyArray[i];
    }

    // Key not found, sorry
    return NULL;
}

static bool EncryptedStream_Read(
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
    if(pByteOffset == NULL)
        pStream->BaseGetPos(pStream, ByteOffset);
    else
        ByteOffset = *pByteOffset;

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
        if(pStream->BaseRead(pStream, &StartOffset, pbMpqData, dwBytesToDecrypt))
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

static bool EncryptedStream_Open(TEncryptedStream * pStream)
{
    ULONGLONG ByteOffset = 0;
    BYTE EncryptedHeader[MPQE_CHUNK_SIZE];
    const char * szKey;

    // Sanity check
    assert(pStream->BaseRead != NULL);

    // Load one MPQE chunk and try to detect the file key
    if(pStream->BaseRead(pStream, &ByteOffset, EncryptedHeader, sizeof(EncryptedHeader)))
    {
        // Attempt to decrypt the MPQ header with all known keys
        szKey = DetectFileKey(EncryptedHeader);
        if(szKey != NULL)
        {
            // Copy the key for the file
            memcpy(pStream->Key, szKey, MPQE_CHUNK_SIZE);
            BSWAP_ARRAY32_UNSIGNED(pStream->Key, MPQE_CHUNK_SIZE);

            // Assign functions
            pStream->StreamRead    = (STREAM_READ)EncryptedStream_Read;
            pStream->StreamGetPos  = pStream->BaseGetPos;
            pStream->StreamGetSize = pStream->BaseGetSize;
            pStream->StreamGetTime = pStream->BaseGetTime;
            pStream->StreamGetBmp  = (STREAM_GETBMP)Dummy_GetBitmap;
            pStream->StreamClose   = pStream->BaseClose;

            // We need to reset the position back to the begin of the file
            pStream->BaseRead(pStream, &ByteOffset, EncryptedHeader, 0);
            return true;
        }

        // An unknown key
        SetLastError(ERROR_UNKNOWN_FILE_KEY);
    }
    return false;
}

//-----------------------------------------------------------------------------
// Public functions

/**
 * This function creates a new file for read-write access
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
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
    TFileStream * pStream;

    // We only support creation of linear, local file
    if((dwStreamFlags & (STREAM_PROVIDER_MASK | BASE_PROVIDER_MASK)) != (STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE))
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return NULL;
    }

    // Allocate file stream structure for linear stream
    pStream = STORM_ALLOC(TFileStream, 1);
    if(pStream != NULL)
    {
        // Reset entire structure to zero
        memset(pStream, 0, sizeof(TFileStream));
        _tcscpy(pStream->szFileName, szFileName);

        // Attempt to create the disk file
        if(BaseFile_Create(pStream, szFileName, dwStreamFlags))
        {
            // Fill the stream provider functions
            pStream->StreamRead    = pStream->BaseRead;
            pStream->StreamWrite   = pStream->BaseWrite;
            pStream->StreamGetPos  = pStream->BaseGetPos;
            pStream->StreamGetSize = pStream->BaseGetSize;
            pStream->StreamSetSize = pStream->BaseSetSize;
            pStream->StreamGetTime = pStream->BaseGetTime;
            pStream->StreamGetBmp  = (STREAM_GETBMP)Dummy_GetBitmap;;
            pStream->StreamSwitch  = (STREAM_SWITCH)LinearStream_Switch;
            pStream->StreamClose   = pStream->BaseClose;
            return pStream;
        }

        // File create failed, delete the stream
        STORM_FREE(pStream);
        pStream = NULL;
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
 *   and create TPartialStream object if so.
 * - The function must initialize all stream function pointers in TFileStream
 * - If the function fails from any reason, it must close all handles
 *   and free all memory that has been allocated in the process of stream creation,
 *   including the TFileStream structure itself
 *
 * \a szFileName Name of the file to open
 * \a dwStreamFlags specifies the provider and base storage type
 */

TFileStream * FileStream_OpenFile(
    const TCHAR * szFileName,
    DWORD dwStreamFlags)
{
    TFileStream * pStream = NULL;
    size_t StreamSize = 0;
    bool bStreamResult = false;
    bool bBaseResult = false;

    // Allocate file stream for each stream provider
    switch(dwStreamFlags & STREAM_PROVIDER_MASK)
    {
        case STREAM_PROVIDER_LINEAR:    // Allocate structure for linear stream 
            StreamSize = sizeof(TLinearStream);
            break;

        case STREAM_PROVIDER_PARTIAL:
            dwStreamFlags |= STREAM_FLAG_READ_ONLY;
            StreamSize = sizeof(TPartialStream);
            break;

        case STREAM_PROVIDER_ENCRYPTED:
            dwStreamFlags |= STREAM_FLAG_READ_ONLY;
            StreamSize = sizeof(TEncryptedStream);
            break;

        default:
            return NULL;
    }

    // Allocate the stream for each type
    pStream = (TFileStream *)STORM_ALLOC(BYTE, StreamSize);
    if(pStream == NULL)
        return NULL;

    // Fill the stream structure with zeros
    memset(pStream, 0, StreamSize);
    _tcscpy(pStream->szFileName, szFileName);

    // Now initialize the respective base provider
    switch(dwStreamFlags & BASE_PROVIDER_MASK)
    {
        case BASE_PROVIDER_FILE:
            bBaseResult = BaseFile_Open(pStream, szFileName, dwStreamFlags);
            break;

        case BASE_PROVIDER_MAP:
            dwStreamFlags |= STREAM_FLAG_READ_ONLY;
            bBaseResult = BaseMap_Open(pStream, szFileName, dwStreamFlags);
            break;

        case BASE_PROVIDER_HTTP:
            dwStreamFlags |= STREAM_FLAG_READ_ONLY;
            bBaseResult = BaseHttp_Open(pStream, szFileName, dwStreamFlags);
            break;
    }

    // If we failed to open the base storage, fail the operation
    if(bBaseResult == false)
    {
        STORM_FREE(pStream);
        return NULL;
    }

    // Now initialize the stream provider
    switch(dwStreamFlags & STREAM_PROVIDER_MASK)
    {
        case STREAM_PROVIDER_LINEAR:
            bStreamResult = LinearStream_Open((TLinearStream *)pStream);
            break;

        case STREAM_PROVIDER_PARTIAL:
            bStreamResult = PartialStream_Open((TPartialStream *)pStream);
            break;

        case STREAM_PROVIDER_ENCRYPTED:
            bStreamResult = EncryptedStream_Open((TEncryptedStream *)pStream);
            break;
    }

    // If the operation failed, free the stream and set it to NULL
    if(bStreamResult == false)
    {
        // Only close the base stream
        pStream->BaseClose(pStream);
        STORM_FREE(pStream);
        pStream = NULL;
    }

    return pStream;
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
    if(pStream->dwFlags & STREAM_FLAG_READ_ONLY)
        return false;

    assert(pStream->StreamWrite != NULL);
    return pStream->StreamWrite(pStream, pByteOffset, pvBuffer, dwBytesToWrite);
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
    if(pStream->dwFlags & STREAM_FLAG_READ_ONLY)
        return false;

    assert(pStream->StreamSetSize != NULL);
    return pStream->StreamSetSize(pStream, NewFileSize);
}

/**
 * Returns the last write time of a file
 *
 * \a pStream Pointer to an open stream
 * \a pFileType Pointer where to store the file last write time
 */
bool FileStream_GetTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
    assert(pStream->StreamGetTime != NULL);
    return pStream->StreamGetTime(pStream, pFileTime);
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
bool FileStream_Switch(TFileStream * pStream, TFileStream * pNewStream)
{
    if(pStream->dwFlags & STREAM_FLAG_READ_ONLY)
        return false;

    assert(pStream->StreamSwitch != NULL);
    return pStream->StreamSwitch(pStream, pNewStream);
}

/**
 * Returns the file name of the stream
 *
 * \a pStream Pointer to an open stream
 */
TCHAR * FileStream_GetFileName(TFileStream * pStream)
{
    assert(pStream != NULL);
    return pStream->szFileName;
}

/**
 * Returns true if the stream is read-only
 *
 * \a pStream Pointer to an open stream
 */
bool FileStream_IsReadOnly(TFileStream * pStream)
{
    return (pStream->dwFlags & STREAM_FLAG_READ_ONLY) ? true : false;
}

/**
 * This function enabled a linear stream to include data bitmap.
 * Used by MPQs v 4.0 from WoW. Each file block is represented by
 * a bit in the bitmap. 1 means the block is present, 0 means it's not.
 *
 * \a pStream Pointer to an open stream
 * \a pBitmap Pointer to file bitmap
 */

bool FileStream_SetBitmap(TFileStream * pStream, TFileBitmap * pBitmap)
{
    TLinearStream * pLinearStream;

    // It must be a linear stream.
    if((pStream->dwFlags & STREAM_PROVIDER_MASK) != STREAM_PROVIDER_LINEAR)
        return false;
    pLinearStream = (TLinearStream *)pStream;

    // Two bitmaps are not allowed
    if(pLinearStream->pBitmap != NULL)
        return false;

    // We need to change some entry points
    pLinearStream->StreamRead   = (STREAM_READ)LinearStream_Read;
    pLinearStream->StreamGetBmp = (STREAM_GETBMP)LinearStream_GetBitmap;

    // Using data bitmap renders the stream to be read only.
    pLinearStream->dwFlags |= STREAM_FLAG_READ_ONLY;
    pLinearStream->pBitmap = pBitmap;
    return true;
}

/**
 * This function retrieves the file bitmap. A file bitmap is an array
 * of bits, each bit representing one file block. A value of 1 means
 * that the block is present in the file, a value of 0 means that the
 * block is not present.
 *
 * \a pStream Pointer to an open stream
 * \a pBitmap Pointer to buffer where to store the file bitmap
 * \a Length  Size of buffer pointed by pBitmap, in bytes
 * \a LengthNeeded If non-NULL, the function supplies the necessary byte size of the buffer
 */
bool FileStream_GetBitmap(TFileStream * pStream, TFileBitmap * pBitmap, DWORD Length, LPDWORD LengthNeeded)
{
    assert(pStream->StreamGetBmp != NULL);
    return pStream->StreamGetBmp(pStream, pBitmap, Length, LengthNeeded);
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
        // Close the stream provider.
        // This will also close the base stream
        assert(pStream->StreamClose != NULL);
        pStream->StreamClose(pStream);

        // Free the stream itself
        STORM_FREE(pStream);
    }
}

//-----------------------------------------------------------------------------
// main - for testing purposes

#ifdef __STORMLIB_TEST__
int FileStream_Test(const TCHAR * szFileName, DWORD dwStreamFlags)
{
    TFileStream * pStream;
    TMPQHeader MpqHeader;
    ULONGLONG FilePos;
    TMPQBlock * pBlock;
    TMPQHash * pHash;

    InitializeMpqCryptography();

    pStream = FileStream_OpenFile(szFileName, dwStreamFlags);
    if(pStream == NULL)
        return GetLastError();

    // Read the MPQ header
    FileStream_Read(pStream, NULL, &MpqHeader, MPQ_HEADER_SIZE_V2);
    if(MpqHeader.dwID != ID_MPQ)
        return ERROR_FILE_CORRUPT;

    // Read the hash table
    pHash = STORM_ALLOC(TMPQHash, MpqHeader.dwHashTableSize);
    if(pHash != NULL)
    {
        FilePos = MpqHeader.dwHashTablePos;
        FileStream_Read(pStream, &FilePos, pHash, MpqHeader.dwHashTableSize * sizeof(TMPQHash));
        DecryptMpqBlock(pHash, MpqHeader.dwHashTableSize * sizeof(TMPQHash), MPQ_KEY_HASH_TABLE);
        STORM_FREE(pHash);
    }

    // Read the block table
    pBlock = STORM_ALLOC(TMPQBlock, MpqHeader.dwBlockTableSize);
    if(pBlock != NULL)
    {
        FilePos = MpqHeader.dwBlockTablePos;
        FileStream_Read(pStream, &FilePos, pBlock, MpqHeader.dwBlockTableSize * sizeof(TMPQBlock));
        DecryptMpqBlock(pBlock, MpqHeader.dwBlockTableSize * sizeof(TMPQBlock), MPQ_KEY_BLOCK_TABLE);
        STORM_FREE(pBlock);
    }

    FileStream_Close(pStream);
    return ERROR_SUCCESS;
}
#endif

/*
int FileStream_Test()
{
    TFileStream * pStream;

    InitializeMpqCryptography();

    //
    // Test 1: Write to a stream
    //

    pStream = FileStream_CreateFile("E:\\Stream.bin", 0);
    if(pStream != NULL)
    {
        char szString1[100] = "This is a single line\n\r";
        DWORD dwLength = strlen(szString1);

        for(int i = 0; i < 10; i++)
        {
            if(!FileStream_Write(pStream, NULL, szString1, dwLength))
            {
                printf("Failed to write to the stream\n");
                return ERROR_CAN_NOT_COMPLETE;
            }
        }
        FileStream_Close(pStream);
    }

    //
    // Test2: Read from the stream
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        char szString1[100] = "This is a single line\n\r";
        char szString2[100];
        DWORD dwLength = strlen(szString1);

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
    }

    //
    // Test3: Open the temp stream, write some data and switch it to the original stream
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        TFileStream * pTempStream;
        ULONGLONG FileSize;

        pTempStream = FileStream_CreateFile("E:\\TempStream.bin", 0);
        if(pTempStream == NULL)
        {
            printf("Failed to create temp stream\n");
            return -1;
        }

        // Copy the original stream to the temp
        if(!FileStream_GetSize(pStream, FileSize))
        {
            printf("Failed to get the file size\n");
            return -1;
        }

        while(FileSize != 0)
        {
            DWORD dwBytesToRead = (DWORD)FileSize;
            char Buffer[0x80];

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

            FileSize -= dwBytesToRead;
        }

        // Switch the streams
        // Note that the pTempStream is closed by the operation
        FileStream_Switch(pStream, pTempStream);
        FileStream_Close(pStream);
    }

    //
    // Test4: Read from the stream again
    //

    pStream = FileStream_OpenFile("E:\\Stream.bin", STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        char szString1[100] = "This is a single line\n\r";
        char szString2[100];
        DWORD dwLength = strlen(szString1);

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
    }

    return 0;
}
*/

