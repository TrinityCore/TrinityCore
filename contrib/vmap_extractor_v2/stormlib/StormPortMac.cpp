/********************************************************************
*
* Description:  implementation for StormLib - Macintosh port
*        
*   these are function wraps to execute Windows API calls
*   as native Macintosh file calls (open/close/read/write/...)
*   requires Mac OS X
*
* Derived from Marko Friedemann <marko.friedemann@bmx-chemnitz.de>
* StormPort.cpp for Linux
*
* Author: Daniel Chiaramello <daniel@chiaramello.net>
*
* Carbonized by: Sam Wilkins <swilkins1337@gmail.com>
*
********************************************************************/

#ifndef _WIN32
#include "StormPort.h"
#include "StormLib.h"

// FUNCTIONS EXTRACTED FROM MOREFILE PACKAGE!!!
// FEEL FREE TO REMOVE THEM AND TO ADD THE ORIGINAL ONES!

/*****************************************************************************
* BEGIN OF MOREFILES COPY-PASTE
*****************************************************************************/

#ifdef    __USEPRAGMAINTERNAL
    #ifdef __MWERKS__
        #pragma internal on
    #endif
#endif

union TLongAnd4Bytes
{
    unsigned char bytes[4];
    unsigned long uvalue;
    signed long svalue;
};


static OSErr FSGetFullPath(const FSRef *ref, UInt8 *fullPath, UInt32 fullPathLength)
{
    OSErr       result;

    result = FSRefMakePath(ref, fullPath, fullPathLength);
    
    return result;
}

static OSErr FSLocationFromFullPath(const void *fullPath, FSRef *ref)
{
    OSErr       result;
    
    result = FSPathMakeRef((UInt8 *)fullPath, ref, NULL); // Create an FSRef from the path
    return result;
}

/*****************************************************************************/

/*****************************************************************************/

static OSErr FSCreateCompat(const FSRef *parentRef, OSType creator, OSType fileType, const UniChar *fileName, 
                            UniCharCount nameLength, FSRef *ref)
{
    FSCatalogInfo theCatInfo;
    OSErr theErr;
    ((FileInfo *)&theCatInfo.finderInfo)->fileCreator = creator;
    ((FileInfo *)&theCatInfo.finderInfo)->fileType = fileType;
    ((FileInfo *)&theCatInfo.finderInfo)->finderFlags = 0;
    SetPt(&((FileInfo *)&theCatInfo.finderInfo)->location, 0, 0);
    ((FileInfo *)&theCatInfo.finderInfo)->reservedField = 0;
        
    theErr = FSCreateFileUnicode(parentRef, nameLength, fileName, kFSCatInfoFinderInfo, &theCatInfo, ref, NULL);
    return theErr;
}


/*****************************************************************************/

static OSErr FSOpenDFCompat(FSRef *ref, char permission, short *refNum)
{
    HFSUniStr255 forkName;
    OSErr theErr;
    Boolean isFolder, wasChanged;
    
    theErr = FSResolveAliasFile(ref, TRUE, &isFolder, &wasChanged);
    if (theErr != noErr)
        return theErr;
    
    FSGetDataForkName(&forkName);
    theErr = FSOpenFork(ref, forkName.length, forkName.unicode, permission, refNum);
    return theErr;
}

/*****************************************************************************
* END OF MOREFILES COPY-PASTE
*****************************************************************************/

#pragma mark -

int globalerr;

/********************************************************************
*    SwapLong
********************************************************************/

unsigned long SwapULong(unsigned long data)
{
    // Apple provided function
    uint32_t result;

    __asm__("lwbrx %0,0,%1" : "=r" (result) : "r" (&data), "m" (data));
    return result;

/*
    TLongAnd4Bytes Work;
    unsigned char * value_as_4bytes = (unsigned char *)&value;

    Work.bytes[0] = value_as_4bytes[3];
    Work.bytes[1] = value_as_4bytes[2];
    Work.bytes[2] = value_as_4bytes[1];
    Work.bytes[3] = value_as_4bytes[0];

    return Work.uvalue;
*/
}

long SwapLong(unsigned long data)
{
    // Apple provided function
    uint32_t result;

    __asm__("lwbrx %0,0,%1" : "=r" (result) : "r" (&data), "m" (data));
    return (long)result;

/*
    TLongAnd4Bytes Work;
    unsigned char * value_as_4bytes = (unsigned char *)&value;

    Work.bytes[0] = value_as_4bytes[3];
    Work.bytes[1] = value_as_4bytes[2];
    Work.bytes[2] = value_as_4bytes[1];
    Work.bytes[3] = value_as_4bytes[0];

    return Work.svalue;
*/
}

/********************************************************************
*    SwapShort
********************************************************************/
unsigned short SwapUShort(unsigned short data)
{
    // Apple provided function
    uint16_t result;
    __asm__("lhbrx %0,0,%1" : "=r" (result) : "r" (&data), "m" (data));
    return result;
}

short SwapShort(unsigned short data)
{
    // Apple provided function
    uint16_t result;
    __asm__("lhbrx %0,0,%1" : "=r" (result) : "r" (&data), "m" (data));
    return (short)result;
}

/********************************************************************
*    ConvertUnsignedLongBuffer
********************************************************************/
void ConvertUnsignedLongBuffer(unsigned long *buffer, unsigned long nbLongs)
{
    while (nbLongs-- > 0)
    {
        *buffer = SwapLong(*buffer);
        buffer++;
    }
}

/********************************************************************
*    ConvertUnsignedShortBuffer
********************************************************************/
void ConvertUnsignedShortBuffer(unsigned short *buffer, unsigned long nbShorts)
{
    while (nbShorts-- > 0)
    {
        *buffer = SwapShort(*buffer);
        buffer++;
    }
}

/********************************************************************
*    ConvertTMPQShunt
********************************************************************/
void ConvertTMPQShunt(void *shunt)
{
    TMPQShunt * theShunt = (TMPQShunt *)shunt;

    theShunt->dwID = SwapULong(theShunt->dwID);
    theShunt->dwUnknown = SwapULong(theShunt->dwUnknown);
    theShunt->dwHeaderPos = SwapULong(theShunt->dwHeaderPos);
}

/********************************************************************
*    ConvertTMPQHeader
********************************************************************/
void ConvertTMPQHeader(void *header)
{
    TMPQHeader2 * theHeader = (TMPQHeader2 *)header;
    
    theHeader->dwID = SwapULong(theHeader->dwID);
    theHeader->dwHeaderSize = SwapULong(theHeader->dwHeaderSize);
    theHeader->dwArchiveSize = SwapULong(theHeader->dwArchiveSize);
    theHeader->wFormatVersion = SwapUShort(theHeader->wFormatVersion);
    theHeader->wBlockSize = SwapUShort(theHeader->wBlockSize);
    theHeader->dwHashTablePos = SwapULong(theHeader->dwHashTablePos);
    theHeader->dwBlockTablePos = SwapULong(theHeader->dwBlockTablePos);
    theHeader->dwHashTableSize = SwapULong(theHeader->dwHashTableSize);
    theHeader->dwBlockTableSize = SwapULong(theHeader->dwBlockTableSize);

    if(theHeader->wFormatVersion >= MPQ_FORMAT_VERSION_2)
    {
        DWORD dwTemp = theHeader->ExtBlockTablePos.LowPart;
        theHeader->ExtBlockTablePos.LowPart = theHeader->ExtBlockTablePos.HighPart;
        theHeader->ExtBlockTablePos.HighPart = dwTemp;
        theHeader->ExtBlockTablePos.LowPart = SwapULong(theHeader->ExtBlockTablePos.LowPart);
        theHeader->ExtBlockTablePos.HighPart = SwapULong(theHeader->ExtBlockTablePos.HighPart);
        theHeader->wHashTablePosHigh = SwapUShort(theHeader->wHashTablePosHigh);
        theHeader->wBlockTablePosHigh = SwapUShort(theHeader->wBlockTablePosHigh);
    }
}

/********************************************************************
*    ConvertTMPQHash
********************************************************************/
void ConvertHashTable(void *hashtable, DWORD nHashEntries)
{
    TMPQHash * theHash = (TMPQHash *)hashtable;
    USHORT lcLocale;

    for(DWORD i = 0; i < nHashEntries; i++, theHash++)
    {
        lcLocale = theHash->lcLocale;
        theHash->lcLocale = theHash->wPlatform;
        theHash->wPlatform = lcLocale;
    }
}

#pragma mark -

/********************************************************************
*    SetLastError
********************************************************************/
void SetLastError(int err)
{
    globalerr = err;
}

/********************************************************************
*    GetLastError
********************************************************************/
int GetLastError()
{
    return globalerr;
}

/********************************************************************
*    ErrString
********************************************************************/
char *ErrString(int err)
{
    switch (err) 
    {
        case ERROR_INVALID_FUNCTION:
            return "function not implemented";
        case ERROR_FILE_NOT_FOUND:
            return "file not found";
        case ERROR_ACCESS_DENIED:
            return "access denied";
        case ERROR_NOT_ENOUGH_MEMORY:
            return "not enough memory";
        case ERROR_BAD_FORMAT:
            return "bad format";
        case ERROR_NO_MORE_FILES:
            return "no more files";
        case ERROR_HANDLE_EOF:
            return "access beyound EOF";
        case ERROR_HANDLE_DISK_FULL:
            return "no space left on device";
        case ERROR_INVALID_PARAMETER:
            return "invalid parameter";
        case ERROR_DISK_FULL:
            return "no space left on device";
        case ERROR_ALREADY_EXISTS:
            return "file exists";
        case ERROR_CAN_NOT_COMPLETE:
            return "operation cannot be completed";
        case ERROR_INSUFFICIENT_BUFFER:
            return "insufficient buffer";
        default:
            return "unknown error";
    }
}

#pragma mark -

/********************************************************************
*    GetTempPath - returns a '/' or ':'-terminated path
*        szTempLength: length for path
*        szTemp: file path
********************************************************************/
void GetTempPath(DWORD szTempLength, char * szTemp)  // I think I'll change this to use FSRefs.
{
    FSRef   theFSRef;
    OSErr theErr = FSFindFolder(kOnAppropriateDisk, kTemporaryFolderType, kCreateFolder, &theFSRef);
    if (theErr == noErr)
    {
        theErr = FSGetFullPath(&theFSRef, (UInt8 *)szTemp, MAX_PATH);
        if (theErr != noErr)
            szTemp[0] = '\0';
    }
    else
        szTemp[0] = '\0';
    strcat(szTemp, "/");
    
    SetLastError(theErr);
}

/********************************************************************
*    GetTempFileName
*        lpTempFolderPath: the temporary folder path, terminated by "/"
*        lpFileName: a file name base
*        something: unknown
*        szLFName: the final path, built from the path, the file name and a random pattern
********************************************************************/
void GetTempFileName(const char * lpTempFolderPath, const char * lpFileName, DWORD something, char * szLFName)
{
#pragma unused (something)
    char    tmp[2] = "A";

    while (true)
    {
        HANDLE  fHandle;

        strcpy(szLFName, lpTempFolderPath);
        strcat(szLFName, lpFileName);
        strcat(szLFName, tmp);
        
        if ((fHandle = CreateFile(szLFName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0)) == INVALID_HANDLE_VALUE)
            // OK we found it!
            break;
        CloseHandle(fHandle);
        tmp[0]++;
    }
}

/********************************************************************
*    DeleteFile
*        lpFileName: file path
********************************************************************/
BOOL DeleteFile(const char * lpFileName)
{
    OSErr   theErr;
    FSRef   theFileRef;
    
    theErr = FSLocationFromFullPath(lpFileName, &theFileRef);
    if (theErr != noErr)
    {
        SetLastError(theErr);
        return FALSE;
    }
    
    theErr = FSDeleteObject(&theFileRef);
    
    SetLastError(theErr);

    return theErr == noErr;
}

/********************************************************************
*    MoveFile
*        lpFromFileName: old file path
*        lpToFileName: new file path
********************************************************************/
BOOL MoveFile(const char * lpFromFileName, const char * lpToFileName)
{
    OSErr theErr;
    FSRef fromFileRef;
    FSRef toFileRef;
    FSRef parentFolderRef;
    
    // Get the path to the old file
    theErr = FSLocationFromFullPath(lpFromFileName, &fromFileRef);
    if (theErr != noErr)
    {
        SetLastError(theErr);
        return false;
    }
    
    // Get the path to the new folder for the file
    char folderName[strlen(lpToFileName)];
    CFStringRef folderPathCFString = CFStringCreateWithCString(NULL, lpToFileName, kCFStringEncodingUTF8);
    CFURLRef fileURL = CFURLCreateWithFileSystemPath(NULL, folderPathCFString, kCFURLPOSIXPathStyle, FALSE);
    CFURLRef folderURL = CFURLCreateCopyDeletingLastPathComponent(NULL, fileURL);
    CFURLGetFileSystemRepresentation(folderURL, TRUE, (UInt8 *)folderName, strlen(lpToFileName));
    theErr = FSLocationFromFullPath(folderName, &parentFolderRef);
    CFRelease(fileURL);
    CFRelease(folderURL);
    CFRelease(folderPathCFString);
    
    // Move the old file
    theErr = FSMoveObject(&fromFileRef, &parentFolderRef, &toFileRef);
    if (theErr != noErr)
    {
        SetLastError(theErr);
        return false;
    }
    
    // Get a CFString for the new file name
    CFStringRef newFileNameCFString = CFStringCreateWithCString(NULL, lpToFileName, kCFStringEncodingUTF8);
    fileURL = CFURLCreateWithFileSystemPath(NULL, newFileNameCFString, kCFURLPOSIXPathStyle, FALSE);
    CFRelease(newFileNameCFString);
    newFileNameCFString = CFURLCopyLastPathComponent(fileURL);
    CFRelease(fileURL);
    
    // Convert CFString to Unicode and rename the file
    UniChar unicodeFileName[256]; 
    CFStringGetCharacters(newFileNameCFString, CFRangeMake(0, CFStringGetLength(newFileNameCFString)), 
                          unicodeFileName);
    theErr = FSRenameUnicode(&toFileRef, CFStringGetLength(newFileNameCFString), unicodeFileName, 
                             kTextEncodingUnknown, NULL);
    if (theErr != noErr)
    {
        SetLastError(theErr);
        CFRelease(newFileNameCFString);
        return false;
    }
    
    CFRelease(newFileNameCFString);
    
    SetLastError(theErr);
    return true;
}

/********************************************************************
*    CreateFile
*        ulMode: GENERIC_READ | GENERIC_WRITE
*        ulSharing: FILE_SHARE_READ
*        pSecAttrib: NULL
*        ulCreation: OPEN_EXISTING, OPEN_ALWAYS, CREATE_NEW
*        ulFlags: 0
*        hFile: NULL
********************************************************************/
HANDLE CreateFile(  const char *sFileName,          /* file name */
                    DWORD ulMode,                   /* access mode */
                    DWORD ulSharing,                /* share mode */
                    void *pSecAttrib,               /* SD */
                    DWORD ulCreation,               /* how to create */
                    DWORD ulFlags,                  /* file attributes */
                    HANDLE hFile    )               /* handle to template file */
{
#pragma unused (ulSharing, pSecAttrib, ulFlags, hFile)

    OSErr   theErr;
    FSRef   theFileRef;
    FSRef   theParentRef;
    short   fileRef;
    char    permission;
    static OSType   gCreator;
    static OSType   gType;
    
    theErr = FSLocationFromFullPath(sFileName, &theFileRef);
    if (theErr == fnfErr)
    {   // Create the FSRef for the parent directory.
        memset(&theFileRef, 0, sizeof(FSRef));
        UInt8 folderName[MAX_PATH];
        CFStringRef folderPathCFString = CFStringCreateWithCString(NULL, sFileName, kCFStringEncodingUTF8);
        CFURLRef fileURL = CFURLCreateWithFileSystemPath(NULL, folderPathCFString, kCFURLPOSIXPathStyle, FALSE);
        CFURLRef folderURL = CFURLCreateCopyDeletingLastPathComponent(NULL, fileURL);
        CFURLGetFileSystemRepresentation(folderURL, TRUE, folderName, MAX_PATH);
        theErr = FSLocationFromFullPath(folderName, &theParentRef);
        CFRelease(fileURL);
        CFRelease(folderURL);
        CFRelease(folderPathCFString);
    }         
    if (theErr != noErr)
    {
        SetLastError(theErr);
        if (ulCreation == OPEN_EXISTING || theErr != fnfErr)
            return INVALID_HANDLE_VALUE;
    }
    
    if (ulCreation != OPEN_EXISTING)
    {   /* We create the file */
        UniChar unicodeFileName[256];
        CFStringRef filePathCFString = CFStringCreateWithCString(NULL, sFileName, kCFStringEncodingUTF8);
        CFURLRef fileURL = CFURLCreateWithFileSystemPath(NULL, filePathCFString, kCFURLPOSIXPathStyle, FALSE);
        CFStringRef fileNameCFString = CFURLCopyLastPathComponent(fileURL);
        CFStringGetCharacters(fileNameCFString, CFRangeMake(0, CFStringGetLength(fileNameCFString)), 
                              unicodeFileName);
        theErr = FSCreateCompat(&theParentRef, gCreator, gType, unicodeFileName, 
                                CFStringGetLength(fileNameCFString), &theFileRef);
        CFRelease(fileNameCFString);
        CFRelease(filePathCFString);
        CFRelease(fileURL);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return INVALID_HANDLE_VALUE;
        }
    }

    if (ulMode == GENERIC_READ)
        permission = fsRdPerm;
    else
    {
        if (ulMode == GENERIC_WRITE)
            permission = fsWrPerm;
        else
            permission = fsRdWrPerm;
    }
    theErr = FSOpenDFCompat(&theFileRef, permission, &fileRef);
    
    SetLastError(theErr);

    if (theErr == noErr)
        return (HANDLE)(int)fileRef;
    else
        return INVALID_HANDLE_VALUE;
}

/********************************************************************
*    CloseHandle
********************************************************************/
BOOL CloseHandle(   HANDLE hFile    )    /* handle to object */
{
    OSErr theErr;
    
    if ((hFile == NULL) || (hFile == INVALID_HANDLE_VALUE))
        return FALSE;

    theErr = FSCloseFork((short)(int)hFile);
    
    SetLastError(theErr);
    
    return theErr != noErr;
}

/********************************************************************
*    GetFileSize
********************************************************************/
DWORD GetFileSize(  HANDLE hFile,           /* handle to file */
                    DWORD *ulOffSetHigh )   /* high-order word of file size */
{
    SInt64  fileLength;
    OSErr   theErr;

    if ((hFile == NULL) || (hFile == INVALID_HANDLE_VALUE))
    {
        SetLastError(theErr);
        return -1u;
    }
    
    theErr = FSGetForkSize((short)(int)hFile, &fileLength);
    if (theErr != noErr)
    {
        SetLastError(theErr);
        return -1u;
    }
    
    if (ulOffSetHigh != NULL)
        *ulOffSetHigh = fileLength >> 32;

    SetLastError(theErr);
    
    return fileLength;
}

/********************************************************************
*    SetFilePointer
*        pOffSetHigh: NULL
*        ulMethod: FILE_BEGIN, FILE_CURRENT
********************************************************************/
DWORD SetFilePointer(   HANDLE hFile,           /* handle to file */
                        LONG lOffSetLow,        /* bytes to move pointer */
                        LONG *pOffSetHigh,      /* bytes to move pointer */
                        DWORD ulMethod  )       /* starting point */
{
    OSErr theErr;

    if (ulMethod == FILE_CURRENT)
    {
        SInt64  bytesToMove;
        
        if (pOffSetHigh != NULL)
            bytesToMove = ((SInt64)*pOffSetHigh << 32) + lOffSetLow;
        else
            bytesToMove = lOffSetLow;
        
        SInt64  newPos;
        
        theErr = FSSetForkPosition((short)(int)hFile, fsFromMark, bytesToMove);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return -1u;
        }
        
        theErr = FSGetForkPosition((short)(int)hFile, &newPos);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return -1u;
        }
        
        if (pOffSetHigh != NULL)
            *pOffSetHigh = newPos >> 32;
        
        SetLastError(theErr);
        return newPos;
    }
    else if (ulMethod == FILE_BEGIN)
    {
        SInt64  bytesToMove;
        
        if (pOffSetHigh != NULL)
            bytesToMove = ((SInt64)*pOffSetHigh << 32) + lOffSetLow;
        else
            bytesToMove = lOffSetLow;
        
        theErr = FSSetForkPosition((short)(int)hFile, fsFromStart, bytesToMove);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return -1u;
        }
        
        SetLastError(theErr);
        return lOffSetLow;
    }
    else
    {
        SInt64  bytesToMove;
        
        if (pOffSetHigh != NULL)
            bytesToMove = ((SInt64)*pOffSetHigh << 32) + lOffSetLow;
        else
            bytesToMove = lOffSetLow;
        
        SInt64  newPos;
        
        theErr = FSSetForkPosition((short)(int)hFile, fsFromLEOF, bytesToMove);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return -1u;
        }
        
        theErr = FSGetForkPosition((short)(int)hFile, &newPos);
        if (theErr != noErr)
        {
            SetLastError(theErr);
            return -1u;
        }
        
        if (pOffSetHigh != NULL)
            *pOffSetHigh = newPos >> 32;
        
        SetLastError(theErr);
        return newPos;
    }
}

/********************************************************************
*    SetEndOfFile
********************************************************************/
BOOL SetEndOfFile(  HANDLE hFile    )   /* handle to file */
{
    OSErr theErr;
    
    theErr = FSSetForkSize((short)(int)hFile, fsAtMark, 0);
    
    SetLastError(theErr);
    
    return theErr == noErr;
}

/********************************************************************
*    ReadFile
*        pOverLapped: NULL
********************************************************************/
BOOL ReadFile(  HANDLE hFile,           /* handle to file */
                void *pBuffer,          /* data buffer */
                DWORD ulLen,            /* number of bytes to read */
                DWORD *ulRead,          /* number of bytes read */
                void *pOverLapped   )   /* overlapped buffer */
{
#pragma unused (pOverLapped)

    ByteCount   nbCharsRead;
    OSErr       theErr;
    
    nbCharsRead = ulLen;
    theErr = FSReadFork((short)(int)hFile, fsAtMark, 0, nbCharsRead, pBuffer, &nbCharsRead);
    *ulRead = nbCharsRead;
    
    SetLastError(theErr);
    
    return theErr == noErr;
}

/********************************************************************
*    WriteFile
*        pOverLapped: NULL
********************************************************************/
BOOL WriteFile( HANDLE hFile,           /* handle to file */
                const void *pBuffer,    /* data buffer */
                DWORD ulLen,            /* number of bytes to write */
                DWORD *ulWritten,       /* number of bytes written */
                void *pOverLapped   )   /* overlapped buffer */
{
#pragma unused (pOverLapped)

    ByteCount   nbCharsToWrite;
    OSErr       theErr;
    
    nbCharsToWrite = ulLen; 
    theErr = FSWriteFork((short)(int)hFile, fsAtMark, 0, nbCharsToWrite, pBuffer, &nbCharsToWrite);
    *ulWritten = nbCharsToWrite;
    
    SetLastError(theErr);
        
    return theErr == noErr;
}

// Check if a memory block is accessible for reading. It's probably too
// hard to check on Mac, so sorry, we'll just have to crash
BOOL IsBadReadPtr(const void * ptr, int size)
{
#pragma unused (ptr, size)

    return FALSE;
}

// Returns attributes of a file. Actually, it doesn't, it just checks if 
// the file exists, since that's all StormLib uses it for
DWORD GetFileAttributes(const char * szFileName)
{
    FSRef       theRef;
    OSErr       theErr;
    
    theErr = FSLocationFromFullPath(szFileName, &theRef);
    
    if (theErr != noErr)
        return -1u;
    else
        return 0;
}

#endif
