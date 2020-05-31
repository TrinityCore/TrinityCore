/*****************************************************************************/
/* FileStream.cpp                         Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* File stream support                                                       */
/*                                                                           */
/* Windows support: Written by Ladislav Zezula                               */
/* Mac support:     Written by Sam Wilkins                                   */
/* Linux support:   Written by Sam Wilkins and Ivan Komissarov               */
/* Big-endian:      Written & debugged by Sam Wilkins                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.04.14  1.00  Lad  Copied from StormLib                                 */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

#ifdef _MSC_VER
#pragma comment(lib, "wininet.lib")             // Internet functions for HTTP stream
#pragma warning(disable: 4800)                  // 'BOOL' : forcing value to bool 'true' or 'false' (performance warning)
#endif

//-----------------------------------------------------------------------------
// Local functions - platform-specific functions

static DWORD StringToInt(const char * szString)
{
    DWORD dwValue = 0;

    while('0' <= szString[0] && szString[0] <= '9')
    {
        dwValue = (dwValue * 10) + (szString[0] - '9');
        szString++;
    }

    return dwValue;
}

//-----------------------------------------------------------------------------
// Dummy init function

static void BaseNone_Init(TFileStream *)
{
    // Nothing here
}

//-----------------------------------------------------------------------------
// Local functions - base file support

static bool BaseFile_Create(TFileStream * pStream)
{
#ifdef PLATFORM_WINDOWS
    {
        DWORD dwWriteShare = (pStream->dwFlags & STREAM_FLAG_WRITE_SHARE) ? FILE_SHARE_WRITE : 0;

        pStream->Base.File.hFile = CreateFile(pStream->szFileName,
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

        handle = open(pStream->szFileName, O_RDWR | O_CREAT | O_TRUNC | O_LARGEFILE, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if(handle == -1)
        {
            pStream->Base.File.hFile = INVALID_HANDLE_VALUE;
            SetLastError(errno);
            return false;
        }

        pStream->Base.File.hFile = (HANDLE)handle;
    }
#endif

    // Reset the file size and position
    pStream->Base.File.FileSize = 0;
    pStream->Base.File.FilePos = 0;
    return true;
}

static bool BaseFile_Open(TFileStream * pStream, LPCTSTR szFileName, DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS
    {
        ULARGE_INTEGER FileSize;
        DWORD dwWriteAccess = (dwStreamFlags & STREAM_FLAG_READ_ONLY) ? 0 : FILE_WRITE_DATA | FILE_APPEND_DATA | FILE_WRITE_ATTRIBUTES;
        DWORD dwWriteShare = (dwStreamFlags & STREAM_FLAG_WRITE_SHARE) ? FILE_SHARE_WRITE : 0;

        // Open the file
        pStream->Base.File.hFile = CreateFile(szFileName,
                                              FILE_READ_DATA | FILE_READ_ATTRIBUTES | dwWriteAccess,
                                              FILE_SHARE_READ | dwWriteShare,
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
        struct stat64 fileinfo;
        int oflag = (dwStreamFlags & STREAM_FLAG_READ_ONLY) ? O_RDONLY : O_RDWR;
        intptr_t handle;

        // Open the file
        pStream->Base.File.hFile = INVALID_HANDLE_VALUE;
        handle = open(szFileName, oflag | O_LARGEFILE);
        if(handle == -1)
        {
            SetLastError(errno);
            return false;
        }

        // Get the file size
        if(fstat64(handle, &fileinfo) == -1)
        {
            SetLastError(errno);
            close(handle);
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

    // Reset the file position
    pStream->Base.File.FilePos = 0;
    return true;
}

static bool BaseFile_Read(
    TFileStream * pStream,                  // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    DWORD dwBytesRead = 0;                  // Must be set by platform-specific code

    // Synchronize the access to the TFileStream structure
    CascLock(pStream->Lock);
    {
        ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.File.FilePos;

#ifdef PLATFORM_WINDOWS
        {
            // Note: We no longer support Windows 9x.
            // Thus, we can use the OVERLAPPED structure to specify
            // file offset to read from file. This allows us to skip
            // one system call to SetFilePointer

            // Update the byte offset
            pStream->Base.File.FilePos = ByteOffset;

            // Read the data
            if (dwBytesToRead != 0)
            {
                OVERLAPPED Overlapped;

                Overlapped.OffsetHigh = (DWORD)(ByteOffset >> 32);
                Overlapped.Offset = (DWORD)ByteOffset;
                Overlapped.hEvent = NULL;
                if (!ReadFile(pStream->Base.File.hFile, pvBuffer, dwBytesToRead, &dwBytesRead, &Overlapped))
                    return false;
            }
        }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
        {
            ssize_t bytes_read;

            // If the byte offset is different from the current file position,
            // we have to update the file position
            if (ByteOffset != pStream->Base.File.FilePos)
            {
                if (lseek64((intptr_t)pStream->Base.File.hFile, (off64_t)(ByteOffset), SEEK_SET) == (off64_t)-1)
                {
                    SetLastError(errno);
                    return false;
                }
                pStream->Base.File.FilePos = ByteOffset;
            }

            // Perform the read operation
            if (dwBytesToRead != 0)
            {
                bytes_read = read((intptr_t)pStream->Base.File.hFile, pvBuffer, (size_t)dwBytesToRead);
                if (bytes_read == -1)
                {
                    SetLastError(errno);
                    return false;
                }

                dwBytesRead = (DWORD)(size_t)bytes_read;
            }
        }
#endif

        // Increment the current file position by number of bytes read
        pStream->Base.File.FilePos = ByteOffset + dwBytesRead;
    }
    CascUnlock(pStream->Lock);

    // If the number of bytes read doesn't match to required amount, return false
    // However, Blizzard's CASC handlers read encoded data so that if less than expected
    // was read, then they fill the rest with zeros
    if(dwBytesRead < dwBytesToRead)
    {
        if(pStream->dwFlags & STREAM_FLAG_FILL_MISSING)
        {
            memset((LPBYTE)pvBuffer + dwBytesRead, 0, (dwBytesToRead - dwBytesRead));
            dwBytesRead = dwBytesToRead;
        }
        else
        {
            SetLastError(ERROR_HANDLE_EOF);
        }
    }
        
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
    DWORD dwBytesWritten = 0;               // Must be set by platform-specific code

    // Synchronize the access to the TFileStream structure
    CascLock(pStream->Lock);
    {
        ULONGLONG ByteOffset = (pByteOffset != NULL) ? *pByteOffset : pStream->Base.File.FilePos;

#ifdef PLATFORM_WINDOWS
        {
            // Note: We no longer support Windows 9x.
            // Thus, we can use the OVERLAPPED structure to specify
            // file offset to read from file. This allows us to skip
            // one system call to SetFilePointer

            // Update the byte offset
            pStream->Base.File.FilePos = ByteOffset;

            // Read the data
            if (dwBytesToWrite != 0)
            {
                OVERLAPPED Overlapped;

                Overlapped.OffsetHigh = (DWORD)(ByteOffset >> 32);
                Overlapped.Offset = (DWORD)ByteOffset;
                Overlapped.hEvent = NULL;
                if (!WriteFile(pStream->Base.File.hFile, pvBuffer, dwBytesToWrite, &dwBytesWritten, &Overlapped))
                    return false;
            }
        }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
        {
            ssize_t bytes_written;

            // If the byte offset is different from the current file position,
            // we have to update the file position
            if (ByteOffset != pStream->Base.File.FilePos)
            {
                if (lseek64((intptr_t)pStream->Base.File.hFile, (off64_t)(ByteOffset), SEEK_SET) == (off64_t)-1)
                {
                    SetLastError(errno);
                    return false;
                }
                pStream->Base.File.FilePos = ByteOffset;
            }

            // Perform the read operation
            bytes_written = write((intptr_t)pStream->Base.File.hFile, pvBuffer, (size_t)dwBytesToWrite);
            if (bytes_written == -1)
            {
                SetLastError(errno);
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
    }
    CascUnlock(pStream->Lock);

    if(dwBytesWritten != dwBytesToWrite)
        SetLastError(ERROR_DISK_FULL);
    return (dwBytesWritten == dwBytesToWrite);
}

/**
 * \a pStream Pointer to an open stream
 * \a NewFileSize New size of the file
 */
static bool BaseFile_Resize(TFileStream * pStream, ULONGLONG NewFileSize)
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
        if(bResult)
            pStream->Base.File.FileSize = NewFileSize;

        // Restore the file position
        FileSizeHi = (LONG)(pStream->Base.File.FilePos >> 32);
        FileSizeLo = (LONG)(pStream->Base.File.FilePos);
        SetFilePointer(pStream->Base.File.hFile, FileSizeLo, &FileSizeHi, FILE_BEGIN);
        return bResult;
    }
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    {
        if(ftruncate64((intptr_t)pStream->Base.File.hFile, (off64_t)NewFileSize) == -1)
        {
            SetLastError(errno);
            return false;
        }

        pStream->Base.File.FileSize = NewFileSize;
        return true;
    }
#endif
}

// Gives the current file size
static bool BaseFile_GetSize(TFileStream * pStream, ULONGLONG * pFileSize)
{
    // Note: Used by all thre base providers.
    // Requires the TBaseData union to have the same layout for all three base providers
    *pFileSize = pStream->Base.File.FileSize;
    return true;
}

// Gives the current file position
static bool BaseFile_GetPos(TFileStream * pStream, ULONGLONG * pByteOffset)
{
    // Note: Used by all thre base providers.
    // Requires the TBaseData union to have the same layout for all three base providers
    *pByteOffset = pStream->Base.File.FilePos;
    return true;
}

// Renames the file pointed by pStream so that it contains data from pNewStream
static bool BaseFile_Replace(TFileStream * pStream, TFileStream * pNewStream)
{
#ifdef PLATFORM_WINDOWS
    // Rename the new file to the old stream's file
    return (bool)MoveFileEx(pNewStream->szFileName, pStream->szFileName, MOVEFILE_COPY_ALLOWED | MOVEFILE_REPLACE_EXISTING);
#endif

#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX)
    // "rename" on Linux also works if the target file exists
    if(rename(pNewStream->szFileName, pStream->szFileName) == -1)
    {
        SetLastError(errno);
        return false;
    }

    return true;
#endif
}

static void BaseFile_Close(TFileStream * pStream)
{
    // Synchronize the access to multiple threads
    CascLock(pStream->Lock);
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
    CascUnlock(pStream->Lock);
}

// Initializes base functions for the disk file
static void BaseFile_Init(TFileStream * pStream)
{
    pStream->BaseCreate  = BaseFile_Create;
    pStream->BaseOpen    = BaseFile_Open;
    pStream->BaseRead    = BaseFile_Read;
    pStream->BaseWrite   = BaseFile_Write;
    pStream->BaseResize  = BaseFile_Resize;
    pStream->BaseGetSize = BaseFile_GetSize;
    pStream->BaseGetPos  = BaseFile_GetPos;
    pStream->BaseClose   = BaseFile_Close;
}

//-----------------------------------------------------------------------------
// Local functions - base memory-mapped file support

static bool BaseMap_Open(TFileStream * pStream, LPCTSTR szFileName, DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS

    ULARGE_INTEGER FileSize;
    HANDLE hFile;
    HANDLE hMap;
    bool bResult = false;

    // Keep compiler happy
    dwStreamFlags = dwStreamFlags;

    // Open the file for read access
    hFile = CreateFile(szFileName, FILE_READ_DATA, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if(hFile != INVALID_HANDLE_VALUE)
    {
        // Retrieve file size. Don't allow mapping file of a zero size.
        FileSize.LowPart = GetFileSize(hFile, &FileSize.HighPart);
        if(FileSize.QuadPart != 0)
        {
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
                    // Retrieve file time
                    GetFileTime(hFile, NULL, NULL, (LPFILETIME)&pStream->Base.Map.FileTime);

                    // Retrieve file size and position
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
    struct stat64 fileinfo;
    intptr_t handle;
    bool bResult = false;

    // Open the file
    handle = open(szFileName, O_RDONLY);
    if(handle != -1)
    {
        // Get the file size
        if(fstat64(handle, &fileinfo) != -1)
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
        SetLastError(errno);
        return false;
    }
#endif

    return true;
}

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

// Initializes base functions for the mapped file
static void BaseMap_Init(TFileStream * pStream)
{
    // Supply the file stream functions
    pStream->BaseOpen    = BaseMap_Open;
    pStream->BaseRead    = BaseMap_Read;
    pStream->BaseGetSize = BaseFile_GetSize;    // Reuse BaseFile function
    pStream->BaseGetPos  = BaseFile_GetPos;     // Reuse BaseFile function
    pStream->BaseClose   = BaseMap_Close;

    // Mapped files are read-only
    pStream->dwFlags |= STREAM_FLAG_READ_ONLY;
}

//-----------------------------------------------------------------------------
// Local functions - base HTTP file support

static LPCTSTR BaseHttp_ExtractServerName(LPCTSTR szFileName, LPTSTR szServerName)
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
            szFileName++;
    }

    // Return the remainder
    return szFileName;
}

static bool BaseHttp_Open(TFileStream * pStream, LPCTSTR szFileName, DWORD dwStreamFlags)
{
#ifdef PLATFORM_WINDOWS

    INTERNET_PORT ServerPort = INTERNET_DEFAULT_HTTP_PORT;
    HINTERNET hRequest;
    DWORD dwTemp = 0;
    bool bFileAvailable = false;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Check alternate ports
    if(dwStreamFlags & STREAM_FLAG_USE_PORT_1119)
    {
        ServerPort = 1119;
    }

    // Don't download if we are not connected to the internet
    if(!InternetGetConnectedState(&dwTemp, 0))
        dwErrCode = GetLastError();

    // Initiate the connection to the internet
    if(dwErrCode == ERROR_SUCCESS)
    {
        pStream->Base.Http.hInternet = InternetOpen(_T("agent/2.17.2.6700"),
                                                    INTERNET_OPEN_TYPE_PRECONFIG,
                                                    NULL,
                                                    NULL,
                                                    0);
        if(pStream->Base.Http.hInternet == NULL)
            dwErrCode = GetLastError();
    }

    // Connect to the server
    if(dwErrCode == ERROR_SUCCESS)
    {
        TCHAR szServerName[MAX_PATH];
        DWORD dwFlags = INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_UI | INTERNET_FLAG_NO_CACHE_WRITE;

        // Initiate connection with the server
        szFileName = BaseHttp_ExtractServerName(szFileName, szServerName);
        pStream->Base.Http.hConnect = InternetConnect(pStream->Base.Http.hInternet,
                                                      szServerName,
                                                      ServerPort,
                                                      NULL,
                                                      NULL,
                                                      INTERNET_SERVICE_HTTP,
                                                      dwFlags,
                                                      0);
        if(pStream->Base.Http.hConnect == NULL)
            dwErrCode = GetLastError();
    }

    // Now try to query the file size
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Open HTTP request to the file
        hRequest = HttpOpenRequest(pStream->Base.Http.hConnect, _T("GET"), szFileName, NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if(hRequest != NULL)
        {
            if(HttpSendRequest(hRequest, NULL, 0, NULL, 0))
            {
                ULONGLONG FileTime = 0;
                LPTSTR szEndPtr;
                TCHAR szStatusCode[0x10];
                DWORD dwStatusCode = 404;
                DWORD dwFileSize = 0;
                DWORD dwDataSize = sizeof(szStatusCode);
                DWORD dwIndex = 0;

                // Check whether the file exists
                if (HttpQueryInfo(hRequest, HTTP_QUERY_STATUS_CODE, szStatusCode, &dwDataSize, &dwIndex))
                    dwStatusCode = _tcstoul(szStatusCode, &szEndPtr, 10);

                // Compare the status code
                if (dwStatusCode == 200)
                {
                    // Check if the archive has Last Modified field
                    dwDataSize = sizeof(ULONGLONG);
                    if (HttpQueryInfo(hRequest, HTTP_QUERY_LAST_MODIFIED | HTTP_QUERY_FLAG_SYSTEMTIME, &FileTime, &dwDataSize, &dwIndex))
                        pStream->Base.Http.FileTime = FileTime;

                    // Verify if the server supports random access
                    dwDataSize = sizeof(DWORD);
                    if (HttpQueryInfo(hRequest, HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER, &dwFileSize, &dwDataSize, &dwIndex))
                    {
                        if (dwFileSize != 0)
                        {
                            pStream->Base.Http.FileSize = dwFileSize;
                            pStream->Base.Http.FilePos = 0;
                            bFileAvailable = true;
                        }
                    }
                }
                else
                {
                    dwErrCode = ERROR_FILE_NOT_FOUND;
                }
            }
            InternetCloseHandle(hRequest);
        }
    }

    // If the file is not there and is not available for random access,
    // report error
    if(bFileAvailable == false)
    {
        pStream->BaseClose(pStream);
        SetLastError(dwErrCode);
        return false;
    }

    return true;

#else

    // Not supported
    SetLastError(ERROR_NOT_SUPPORTED);
    pStream = pStream;
    return false;

#endif
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

        // Open HTTP request to the file
        szFileName = BaseHttp_ExtractServerName(pStream->szFileName, NULL);
        hRequest = HttpOpenRequest(pStream->Base.Http.hConnect, _T("GET"), szFileName, NULL, NULL, NULL, INTERNET_FLAG_NO_CACHE_WRITE, 0);
        if(hRequest != NULL)
        {
            // Add range request to the HTTP headers
            // http://www.clevercomponents.com/articles/article015/resuming.asp
            CascStrPrintf(szRangeRequest, _countof(szRangeRequest), _T("Range: bytes=%u-%u"), (unsigned int)dwStartOffset, (unsigned int)dwEndOffset);
            HttpAddRequestHeaders(hRequest, szRangeRequest, 0xFFFFFFFF, HTTP_ADDREQ_FLAG_ADD_IF_NEW);

            // Send the request to the server
            if(HttpSendRequest(hRequest, NULL, 0, NULL, 0))
            {
                while(dwTotalBytesRead < dwBytesToRead)
                {
                    DWORD dwBlockBytesToRead = dwBytesToRead - dwTotalBytesRead;
                    DWORD dwBlockBytesRead = 0;

                    // Read the block from the file
                    if(dwBlockBytesToRead > 0x200)
                        dwBlockBytesToRead = 0x200;
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

// Initializes base functions for the mapped file
static void BaseHttp_Init(TFileStream * pStream)
{
    // Supply the stream functions
    pStream->BaseOpen    = BaseHttp_Open;
    pStream->BaseRead    = BaseHttp_Read;
    pStream->BaseGetSize = BaseFile_GetSize;    // Reuse BaseFile function
    pStream->BaseGetPos  = BaseFile_GetPos;     // Reuse BaseFile function
    pStream->BaseClose   = BaseHttp_Close;

    // HTTP files are read-only
    pStream->dwFlags |= STREAM_FLAG_READ_ONLY;
}

//-----------------------------------------------------------------------------
// Local functions - base block-based support

// Generic function that loads blocks from the file
// The function groups the block with the same availability,
// so the called BlockRead can finish the request in a single system call
static bool BlockStream_Read(
    TBlockStream * pStream,                 // Pointer to an open stream
    ULONGLONG * pByteOffset,                // Pointer to file byte offset. If NULL, it reads from the current position
    void * pvBuffer,                        // Pointer to data to be read
    DWORD dwBytesToRead)                    // Number of bytes to read from the file
{
    ULONGLONG BlockOffset0;
    ULONGLONG BlockOffset;
    ULONGLONG ByteOffset;
    ULONGLONG EndOffset;
    LPBYTE TransferBuffer;
    LPBYTE BlockBuffer;
    DWORD BlockBufferOffset;                // Offset of the desired data in the block buffer
    DWORD BytesNeeded;                      // Number of bytes that really need to be read
    DWORD BlockSize = pStream->BlockSize;
    DWORD BlockCount;
    bool bPrevBlockAvailable;
    bool bCallbackCalled = false;
    bool bBlockAvailable;
    bool bResult = true;

    // The base block read function must be present
    assert(pStream->BlockRead != NULL);

    // NOP reading of zero bytes
    if(dwBytesToRead == 0)
        return true;

    // Get the current position in the stream
    ByteOffset = (pByteOffset != NULL) ? pByteOffset[0] : pStream->StreamPos;
    EndOffset = ByteOffset + dwBytesToRead;
    if(EndOffset > pStream->StreamSize)
    {
        SetLastError(ERROR_HANDLE_EOF);
        return false;
    }

    // Calculate the block parameters
    BlockOffset0 = BlockOffset = ByteOffset & ~((ULONGLONG)BlockSize - 1);
    BlockCount  = (DWORD)(((EndOffset - BlockOffset) + (BlockSize - 1)) / BlockSize);
    BytesNeeded = (DWORD)(EndOffset - BlockOffset);

    // Remember where we have our data
    assert((BlockSize & (BlockSize - 1)) == 0);
    BlockBufferOffset = (DWORD)(ByteOffset & (BlockSize - 1));

    // Allocate buffer for reading blocks
    TransferBuffer = BlockBuffer = CASC_ALLOC<BYTE>(BlockCount * BlockSize);
    if(TransferBuffer == NULL)
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return false;
    }

    // If all blocks are available, just read all blocks at once
    if(pStream->IsComplete == 0)
    {
        // Now parse the blocks and send the block read request
        // to all blocks with the same availability
        assert(pStream->BlockCheck != NULL);
        bPrevBlockAvailable = pStream->BlockCheck(pStream, BlockOffset);

        // Loop as long as we have something to read
        while(BlockOffset < EndOffset)
        {
            // Determine availability of the next block
            bBlockAvailable = pStream->BlockCheck(pStream, BlockOffset);

            // If the availability has changed, read all blocks up to this one
            if(bBlockAvailable != bPrevBlockAvailable)
            {
                // Call the file stream callback, if the block is not available
                if(pStream->pMaster && pStream->pfnCallback && bPrevBlockAvailable == false)
                {
                    pStream->pfnCallback(pStream->UserData, BlockOffset0, (DWORD)(BlockOffset - BlockOffset0));
                    bCallbackCalled = true;
                }

                // Load the continuous blocks with the same availability
                assert(BlockOffset > BlockOffset0);
                bResult = pStream->BlockRead(pStream, BlockOffset0, BlockOffset, BlockBuffer, BytesNeeded, bPrevBlockAvailable);
                if(!bResult)
                    break;

                // Move the block offset
                BlockBuffer += (DWORD)(BlockOffset - BlockOffset0);
                BytesNeeded -= (DWORD)(BlockOffset - BlockOffset0);
                bPrevBlockAvailable = bBlockAvailable;
                BlockOffset0 = BlockOffset;
            }

            // Move to the block offset in the stream
            BlockOffset += BlockSize;
        }

        // If there is a block(s) remaining to be read, do it
        if(BlockOffset > BlockOffset0)
        {
            // Call the file stream callback, if the block is not available
            if(pStream->pMaster && pStream->pfnCallback && bPrevBlockAvailable == false)
            {
                pStream->pfnCallback(pStream->UserData, BlockOffset0, (DWORD)(BlockOffset - BlockOffset0));
                bCallbackCalled = true;
            }

            // Read the complete blocks from the file
            if(BlockOffset > pStream->StreamSize)
                BlockOffset = pStream->StreamSize;
            bResult = pStream->BlockRead(pStream, BlockOffset0, BlockOffset, BlockBuffer, BytesNeeded, bPrevBlockAvailable);
        }
    }
    else
    {
        // Read the complete blocks from the file
        if(EndOffset > pStream->StreamSize)
            EndOffset = pStream->StreamSize;
        bResult = pStream->BlockRead(pStream, BlockOffset, EndOffset, BlockBuffer, BytesNeeded, true);
    }

    // Now copy the data to the user buffer
    if(bResult)
    {
        memcpy(pvBuffer, TransferBuffer + BlockBufferOffset, dwBytesToRead);
        pStream->StreamPos = ByteOffset + dwBytesToRead;
    }
    else
    {
        // If the block read failed, set the last error
        SetLastError(ERROR_FILE_INCOMPLETE);
    }

    // Call the callback to indicate we are done
    if(bCallbackCalled)
        pStream->pfnCallback(pStream->UserData, 0, 0);

    // Free the block buffer and return
    CASC_FREE(TransferBuffer);
    return bResult;
}

static bool BlockStream_GetSize(TFileStream * pStream, ULONGLONG * pFileSize)
{
    *pFileSize = pStream->StreamSize;
    return true;
}

static bool BlockStream_GetPos(TFileStream * pStream, ULONGLONG * pByteOffset)
{
    *pByteOffset = pStream->StreamPos;
    return true;
}

static void BlockStream_Close(TBlockStream * pStream)
{
    // Free the data map, if any
    CASC_FREE(pStream->FileBitmap);

    // Call the base class for closing the stream
    pStream->BaseClose(pStream);
}

//-----------------------------------------------------------------------------
// File stream allocation function

static STREAM_INIT StreamBaseInit[4] =
{
    BaseFile_Init,
    BaseMap_Init,
    BaseHttp_Init,
    BaseNone_Init
};

// This function allocates an empty structure for the file stream
// The stream structure is created as flat block, variable length
// The file name is placed after the end of the stream structure data
static TFileStream * AllocateFileStream(
    LPCTSTR szFileName,
    size_t StreamSize,
    DWORD dwStreamFlags)
{
    TFileStream * pMaster = NULL;
    TFileStream * pStream;
    LPCTSTR szNextFile = szFileName;
    size_t FileNameSize;

    // Sanity check
    assert(StreamSize != 0);

    // The caller can specify chain of files in the following form:
    // C:\archive.MPQ*http://www.server.com/MPQs/archive-server.MPQ
    // In that case, we use the part after "*" as master file name
    while(szNextFile[0] != 0 && szNextFile[0] != _T('*'))
        szNextFile++;
    FileNameSize = (size_t)((szNextFile - szFileName) * sizeof(TCHAR));

    // If we have a next file, we need to open it as master stream
    // Note that we don't care if the master stream exists or not,
    // If it doesn't, later attempts to read missing file block will fail
    if(szNextFile[0] == _T('*'))
    {
        // Don't allow another master file in the string
        if(_tcschr(szNextFile + 1, _T('*')) != NULL)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return NULL;
        }

        // Open the master file
        pMaster = FileStream_OpenFile(szNextFile + 1, STREAM_FLAG_READ_ONLY);
    }

    // Allocate the stream structure for the given stream type
    pStream = (TFileStream *)CASC_ALLOC<BYTE>(StreamSize + FileNameSize + sizeof(TCHAR));
    if(pStream != NULL)
    {
        // Zero the entire structure
        memset(pStream, 0, StreamSize + FileNameSize + sizeof(TCHAR));
        pStream->pMaster = pMaster;
        pStream->dwFlags = dwStreamFlags;

        // Initialize the file name
        pStream->szFileName = (LPTSTR)((BYTE *)pStream + StreamSize);
        memcpy(pStream->szFileName, szFileName, FileNameSize);
        pStream->szFileName[FileNameSize / sizeof(TCHAR)] = 0;

        // Initialize the stream lock
        CascInitLock(pStream->Lock);

        // Initialize the stream functions
        StreamBaseInit[dwStreamFlags & 0x03](pStream);
    }

    return pStream;
}

//-----------------------------------------------------------------------------
// Local functions - flat stream support

static DWORD FlatStream_CheckFile(TBlockStream * pStream)
{
    LPBYTE FileBitmap = (LPBYTE)pStream->FileBitmap;
    DWORD WholeByteCount = (pStream->BlockCount / 8);
    DWORD ExtraBitsCount = (pStream->BlockCount & 7);
    BYTE ExpectedValue;

    // Verify the whole bytes - their value must be 0xFF
    for(DWORD i = 0; i < WholeByteCount; i++)
    {
        if(FileBitmap[i] != 0xFF)
            return 0;
    }

    // If there are extra bits, calculate the mask
    if(ExtraBitsCount != 0)
    {
        ExpectedValue = (BYTE)((1 << ExtraBitsCount) - 1);
        if(FileBitmap[WholeByteCount] != ExpectedValue)
            return 0;
    }

    // Yes, the file is complete
    return 1;
}

static bool FlatStream_LoadBitmap(TBlockStream * pStream)
{
    FILE_BITMAP_FOOTER Footer;
    ULONGLONG ByteOffset;
    LPBYTE FileBitmap;
    DWORD BlockCount;
    DWORD BitmapSize;

    // Do not load the bitmap if we should not have to
    if(!(pStream->dwFlags & STREAM_FLAG_USE_BITMAP))
        return false;

    // Only if the size is greater than size of bitmap footer
    if(pStream->Base.File.FileSize > sizeof(FILE_BITMAP_FOOTER))
    {
        // Load the bitmap footer
        ByteOffset = pStream->Base.File.FileSize - sizeof(FILE_BITMAP_FOOTER);
        if(pStream->BaseRead(pStream, &ByteOffset, &Footer, sizeof(FILE_BITMAP_FOOTER)))
        {
            // Make sure that the array is properly BSWAP-ed
            BSWAP_ARRAY32_UNSIGNED((PDWORD)(&Footer), sizeof(FILE_BITMAP_FOOTER));

            // Verify if there is actually a footer
            if(Footer.Signature == ID_FILE_BITMAP_FOOTER && Footer.Version == 0x03)
            {
                // Get the offset of the bitmap, number of blocks and size of the bitmap
                ByteOffset = MAKE_OFFSET64(Footer.MapOffsetHi, Footer.MapOffsetLo);
                BlockCount = (DWORD)(((ByteOffset - 1) / Footer.BlockSize) + 1);
                BitmapSize = ((BlockCount + 7) / 8);

                // Check if the sizes match
                if(ByteOffset + BitmapSize + sizeof(FILE_BITMAP_FOOTER) == pStream->Base.File.FileSize)
                {
                    // Allocate space for the bitmap
                    FileBitmap = CASC_ALLOC<BYTE>(BitmapSize);
                    if(FileBitmap != NULL)
                    {
                        // Load the bitmap bits
                        if(!pStream->BaseRead(pStream, &ByteOffset, FileBitmap, BitmapSize))
                        {
                            CASC_FREE(FileBitmap);
                            return false;
                        }

                        // Update the stream size
                        pStream->BuildNumber = Footer.BuildNumber;
                        pStream->StreamSize = ByteOffset;

                        // Fill the bitmap information
                        pStream->FileBitmap = FileBitmap;
                        pStream->BitmapSize = BitmapSize;
                        pStream->BlockSize  = Footer.BlockSize;
                        pStream->BlockCount = BlockCount;
                        pStream->IsComplete = FlatStream_CheckFile(pStream);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

static void FlatStream_UpdateBitmap(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG StartOffset,
    ULONGLONG EndOffset)
{
    LPBYTE FileBitmap = (LPBYTE)pStream->FileBitmap;
    DWORD BlockIndex;
    DWORD BlockSize = pStream->BlockSize;
    DWORD ByteIndex;
    BYTE BitMask;

    // Sanity checks
    assert((StartOffset & (BlockSize - 1)) == 0);
    assert(FileBitmap != NULL);

    // Calculate the index of the block
    BlockIndex = (DWORD)(StartOffset / BlockSize);
    ByteIndex = (BlockIndex / 0x08);
    BitMask = (BYTE)(1 << (BlockIndex & 0x07));

    // Set all bits for the specified range
    while(StartOffset < EndOffset)
    {
        // Set the bit
        FileBitmap[ByteIndex] |= BitMask;

        // Move all
        StartOffset += BlockSize;
        ByteIndex += (BitMask >> 0x07);
        BitMask = (BitMask >> 0x07) | (BitMask << 0x01);
    }

    // Increment the bitmap update count
    pStream->IsModified = 1;
}

static bool FlatStream_BlockCheck(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG BlockOffset)
{
    LPBYTE FileBitmap = (LPBYTE)pStream->FileBitmap;
    DWORD BlockIndex;
    BYTE BitMask;

    // Sanity checks
    assert((BlockOffset & (pStream->BlockSize - 1)) == 0);
    assert(FileBitmap != NULL);

    // Calculate the index of the block
    BlockIndex = (DWORD)(BlockOffset / pStream->BlockSize);
    BitMask = (BYTE)(1 << (BlockIndex & 0x07));

    // Check if the bit is present
    return (FileBitmap[BlockIndex / 0x08] & BitMask) ? true : false;
}

static bool FlatStream_BlockRead(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG StartOffset,
    ULONGLONG EndOffset,
    LPBYTE BlockBuffer,
    DWORD BytesNeeded,
    bool bAvailable)
{
    DWORD BytesToRead = (DWORD)(EndOffset - StartOffset);

    // The starting offset must be aligned to size of the block
    assert(pStream->FileBitmap != NULL);
    assert((StartOffset & (pStream->BlockSize - 1)) == 0);
    assert(StartOffset < EndOffset);

    // If the blocks are not available, we need to load them from the master
    // and then save to the mirror
    if(bAvailable == false)
    {
        // If we have no master, we cannot satisfy read request
        if(pStream->pMaster == NULL)
            return false;

        // Load the blocks from the master stream
        // Note that we always have to read complete blocks
        // so they get properly stored to the mirror stream
        if(!FileStream_Read(pStream->pMaster, &StartOffset, BlockBuffer, BytesToRead))
            return false;

        // Store the loaded blocks to the mirror file.
        // Note that this operation is not required to succeed
        if(pStream->BaseWrite(pStream, &StartOffset, BlockBuffer, BytesToRead))
            FlatStream_UpdateBitmap(pStream, StartOffset, EndOffset);

        return true;
    }
    else
    {
        if(BytesToRead > BytesNeeded)
            BytesToRead = BytesNeeded;
        return pStream->BaseRead(pStream, &StartOffset, BlockBuffer, BytesToRead);
    }
}

static void FlatStream_Close(TBlockStream * pStream)
{
    FILE_BITMAP_FOOTER Footer;

    if(pStream->FileBitmap && pStream->IsModified)
    {
        // Write the file bitmap
        pStream->BaseWrite(pStream, &pStream->StreamSize, pStream->FileBitmap, pStream->BitmapSize);

        // Prepare and write the file footer
        Footer.Signature   = ID_FILE_BITMAP_FOOTER;
        Footer.Version     = 3;
        Footer.BuildNumber = pStream->BuildNumber;
        Footer.MapOffsetLo = (DWORD)(pStream->StreamSize & 0xFFFFFFFF);
        Footer.MapOffsetHi = (DWORD)(pStream->StreamSize >> 0x20);
        Footer.BlockSize   = pStream->BlockSize;
        BSWAP_ARRAY32_UNSIGNED(&Footer, sizeof(FILE_BITMAP_FOOTER));
        pStream->BaseWrite(pStream, NULL, &Footer, sizeof(FILE_BITMAP_FOOTER));
    }

    // Close the base class
    BlockStream_Close(pStream);
}

static bool FlatStream_CreateMirror(TBlockStream * pStream)
{
    ULONGLONG MasterSize = 0;
    ULONGLONG MirrorSize = 0;
    LPBYTE FileBitmap = NULL;
    DWORD dwBitmapSize;
    DWORD dwBlockCount;
    bool bNeedCreateMirrorStream = true;
    bool bNeedResizeMirrorStream = true;

    // Do we have master function and base creation function?
    if(pStream->pMaster == NULL || pStream->BaseCreate == NULL)
        return false;

    // Retrieve the master file size, block count and bitmap size
    FileStream_GetSize(pStream->pMaster, &MasterSize);
    dwBlockCount = (DWORD)((MasterSize + DEFAULT_BLOCK_SIZE - 1) / DEFAULT_BLOCK_SIZE);
    dwBitmapSize = (DWORD)((dwBlockCount + 7) / 8);

    // Setup stream size and position
    pStream->BuildNumber = DEFAULT_BUILD_NUMBER;        // BUGBUG: Really???
    pStream->StreamSize = MasterSize;
    pStream->StreamPos = 0;

    // Open the base stream for write access
    if(pStream->BaseOpen(pStream, pStream->szFileName, 0))
    {
        // If the file open succeeded, check if the file size matches required size
        pStream->BaseGetSize(pStream, &MirrorSize);
        if(MirrorSize == MasterSize + dwBitmapSize + sizeof(FILE_BITMAP_FOOTER))
        {
            // Attempt to load an existing file bitmap
            if(FlatStream_LoadBitmap(pStream))
                return true;

            // We need to create new file bitmap
            bNeedResizeMirrorStream = false;
        }

        // We need to create mirror stream
        bNeedCreateMirrorStream = false;
    }

    // Create a new stream, if needed
    if(bNeedCreateMirrorStream)
    {
        if(!pStream->BaseCreate(pStream))
            return false;
    }

    // If we need to, then resize the mirror stream
    if(bNeedResizeMirrorStream)
    {
        if(!pStream->BaseResize(pStream, MasterSize + dwBitmapSize + sizeof(FILE_BITMAP_FOOTER)))
            return false;
    }

    // Allocate the bitmap array
    FileBitmap = CASC_ALLOC_ZERO<BYTE>(dwBitmapSize);
    if(FileBitmap == NULL)
        return false;

    // Initialize the bitmap
    pStream->FileBitmap = FileBitmap;
    pStream->BitmapSize = dwBitmapSize;
    pStream->BlockSize  = DEFAULT_BLOCK_SIZE;
    pStream->BlockCount = dwBlockCount;
    pStream->IsComplete = 0;
    pStream->IsModified = 1;

    // Note: Don't write the stream bitmap right away.
    // Doing so would cause sparse file resize on NTFS,
    // which would take long time on larger files.
    return true;
}

static TFileStream * FlatStream_Open(LPCTSTR szFileName, DWORD dwStreamFlags)
{
    TBlockStream * pStream;
    ULONGLONG ByteOffset = 0;

    // Create new empty stream
    pStream = (TBlockStream *)AllocateFileStream(szFileName, sizeof(TBlockStream), dwStreamFlags);
    if(pStream == NULL)
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        return NULL;
    }

    // Do we have a master stream?
    if(pStream->pMaster != NULL)
    {
        if(!FlatStream_CreateMirror(pStream))
        {
            FileStream_Close(pStream);
            SetLastError(ERROR_FILE_NOT_FOUND);
            return NULL;
        }
    }
    else
    {
        // Attempt to open the base stream
        if(!pStream->BaseOpen(pStream, pStream->szFileName, dwStreamFlags))
        {
            FileStream_Close(pStream);
            return NULL;
        }

        // Load the bitmap, if required to
        if(dwStreamFlags & STREAM_FLAG_USE_BITMAP)
            FlatStream_LoadBitmap(pStream);
    }

    // If we have a stream bitmap, set the reading functions
    // which check presence of each file block
    if(pStream->FileBitmap != NULL)
    {
        // Set the stream position to zero. Stream size is already set
        assert(pStream->StreamSize != 0);
        pStream->StreamPos = 0;
        pStream->dwFlags |= STREAM_FLAG_READ_ONLY;

        // Supply the stream functions
        pStream->StreamRead    = (STREAM_READ)BlockStream_Read;
        pStream->StreamGetSize = BlockStream_GetSize;
        pStream->StreamGetPos  = BlockStream_GetPos;
        pStream->StreamClose   = (STREAM_CLOSE)FlatStream_Close;

        // Supply the block functions
        pStream->BlockCheck    = (BLOCK_CHECK)FlatStream_BlockCheck;
        pStream->BlockRead     = (BLOCK_READ)FlatStream_BlockRead;
    }
    else
    {
        // Reset the base position to zero
        pStream->BaseRead(pStream, &ByteOffset, NULL, 0);

        // Setup stream size and position
        pStream->StreamSize = pStream->Base.File.FileSize;
        pStream->StreamPos = 0;

        // Set the base functions
        pStream->StreamRead    = pStream->BaseRead;
        pStream->StreamWrite   = pStream->BaseWrite;
        pStream->StreamResize  = pStream->BaseResize;
        pStream->StreamGetSize = pStream->BaseGetSize;
        pStream->StreamGetPos  = pStream->BaseGetPos;
        pStream->StreamClose   = pStream->BaseClose;
    }

    return pStream;
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

static DWORD PartStream_CheckFile(TBlockStream * pStream)
{
    PPART_FILE_MAP_ENTRY FileBitmap = (PPART_FILE_MAP_ENTRY)pStream->FileBitmap;
    DWORD dwBlockCount;

    // Get the number of blocks
    dwBlockCount = (DWORD)((pStream->StreamSize + pStream->BlockSize - 1) / pStream->BlockSize);

    // Check all blocks
    for(DWORD i = 0; i < dwBlockCount; i++, FileBitmap++)
    {
        // Few sanity checks
        assert(FileBitmap->LargeValueHi == 0);
        assert(FileBitmap->LargeValueLo == 0);
        assert(FileBitmap->Flags == 0 || FileBitmap->Flags == 3);

        // Check if this block is present
        if(FileBitmap->Flags != 3)
            return 0;
    }

    // Yes, the file is complete
    return 1;
}

static bool PartStream_LoadBitmap(TBlockStream * pStream)
{
    PPART_FILE_MAP_ENTRY FileBitmap;
    PART_FILE_HEADER PartHdr;
    ULONGLONG ByteOffset = 0;
    ULONGLONG StreamSize = 0;
    DWORD BlockCount;
    DWORD BitmapSize;

    // Only if the size is greater than size of the bitmap header
    if(pStream->Base.File.FileSize > sizeof(PART_FILE_HEADER))
    {
        // Attempt to read PART file header
        if(pStream->BaseRead(pStream, &ByteOffset, &PartHdr, sizeof(PART_FILE_HEADER)))
        {
            // We need to swap PART file header on big-endian platforms
            BSWAP_ARRAY32_UNSIGNED(&PartHdr, sizeof(PART_FILE_HEADER));

            // Verify the PART file header
            if(IsPartHeader(&PartHdr))
            {
                // Get the number of blocks and size of one block
                StreamSize = MAKE_OFFSET64(PartHdr.FileSizeHi, PartHdr.FileSizeLo);
                ByteOffset = sizeof(PART_FILE_HEADER);
                BlockCount = (DWORD)((StreamSize + PartHdr.BlockSize - 1) / PartHdr.BlockSize);
                BitmapSize = BlockCount * sizeof(PART_FILE_MAP_ENTRY);

                // Check if sizes match
                if((ByteOffset + BitmapSize) < pStream->Base.File.FileSize)
                {
                    // Allocate space for the array of PART_FILE_MAP_ENTRY
                    FileBitmap = CASC_ALLOC<PART_FILE_MAP_ENTRY>(BlockCount);
                    if(FileBitmap != NULL)
                    {
                        // Load the block map
                        if(!pStream->BaseRead(pStream, &ByteOffset, FileBitmap, BitmapSize))
                        {
                            CASC_FREE(FileBitmap);
                            return false;
                        }

                        // Make sure that the byte order is correct
                        BSWAP_ARRAY32_UNSIGNED(FileBitmap, BitmapSize);

                        // Update the stream size
                        pStream->BuildNumber = StringToInt(PartHdr.GameBuildNumber);
                        pStream->StreamSize = StreamSize;

                        // Fill the bitmap information
                        pStream->FileBitmap = FileBitmap;
                        pStream->BitmapSize = BitmapSize;
                        pStream->BlockSize  = PartHdr.BlockSize;
                        pStream->BlockCount = BlockCount;
                        pStream->IsComplete = PartStream_CheckFile(pStream);
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

static void PartStream_UpdateBitmap(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG StartOffset,
    ULONGLONG EndOffset,
    ULONGLONG RealOffset)
{
    PPART_FILE_MAP_ENTRY FileBitmap;
    DWORD BlockSize = pStream->BlockSize;

    // Sanity checks
    assert((StartOffset & (BlockSize - 1)) == 0);
    assert(pStream->FileBitmap != NULL);

    // Calculate the first entry in the block map
    FileBitmap = (PPART_FILE_MAP_ENTRY)pStream->FileBitmap + (StartOffset / BlockSize);

    // Set all bits for the specified range
    while(StartOffset < EndOffset)
    {
        // Set the bit
        FileBitmap->BlockOffsHi = (DWORD)(RealOffset >> 0x20);
        FileBitmap->BlockOffsLo = (DWORD)(RealOffset & 0xFFFFFFFF);
        FileBitmap->Flags = 3;

        // Move all
        StartOffset += BlockSize;
        RealOffset += BlockSize;
        FileBitmap++;
    }

    // Increment the bitmap update count
    pStream->IsModified = 1;
}

static bool PartStream_BlockCheck(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG BlockOffset)
{
    PPART_FILE_MAP_ENTRY FileBitmap;

    // Sanity checks
    assert((BlockOffset & (pStream->BlockSize - 1)) == 0);
    assert(pStream->FileBitmap != NULL);

    // Calculate the block map entry
    FileBitmap = (PPART_FILE_MAP_ENTRY)pStream->FileBitmap + (BlockOffset / pStream->BlockSize);

    // Check if the flags are present
    return (FileBitmap->Flags & 0x03) ? true : false;
}

static bool PartStream_BlockRead(
    TBlockStream * pStream,
    ULONGLONG StartOffset,
    ULONGLONG EndOffset,
    LPBYTE BlockBuffer,
    DWORD BytesNeeded,
    bool bAvailable)
{
    PPART_FILE_MAP_ENTRY FileBitmap;
    ULONGLONG ByteOffset;
    DWORD BytesToRead;
    DWORD BlockIndex = (DWORD)(StartOffset / pStream->BlockSize);

    // The starting offset must be aligned to size of the block
    assert(pStream->FileBitmap != NULL);
    assert((StartOffset & (pStream->BlockSize - 1)) == 0);
    assert(StartOffset < EndOffset);

    // If the blocks are not available, we need to load them from the master
    // and then save to the mirror
    if(bAvailable == false)
    {
        // If we have no master, we cannot satisfy read request
        if(pStream->pMaster == NULL)
            return false;

        // Load the blocks from the master stream
        // Note that we always have to read complete blocks
        // so they get properly stored to the mirror stream
        BytesToRead = (DWORD)(EndOffset - StartOffset);
        if(!FileStream_Read(pStream->pMaster, &StartOffset, BlockBuffer, BytesToRead))
            return false;

        // The loaded blocks are going to be stored to the end of the file
        // Note that this operation is not required to succeed
        if(pStream->BaseGetSize(pStream, &ByteOffset))
        {
            // Store the loaded blocks to the mirror file.
            if(pStream->BaseWrite(pStream, &ByteOffset, BlockBuffer, BytesToRead))
            {
                PartStream_UpdateBitmap(pStream, StartOffset, EndOffset, ByteOffset);
            }
        }
    }
    else
    {
        // Get the file map entry
        FileBitmap = (PPART_FILE_MAP_ENTRY)pStream->FileBitmap + BlockIndex;

        // Read all blocks
        while(StartOffset < EndOffset)
        {
            // Get the number of bytes to be read
            BytesToRead = (DWORD)(EndOffset - StartOffset);
            if(BytesToRead > pStream->BlockSize)
                BytesToRead = pStream->BlockSize;
            if(BytesToRead > BytesNeeded)
                BytesToRead = BytesNeeded;

            // Read the block
            ByteOffset = MAKE_OFFSET64(FileBitmap->BlockOffsHi, FileBitmap->BlockOffsLo);
            if(!pStream->BaseRead(pStream, &ByteOffset, BlockBuffer, BytesToRead))
                return false;

            // Move the pointers
            StartOffset += pStream->BlockSize;
            BlockBuffer += pStream->BlockSize;
            BytesNeeded -= pStream->BlockSize;
            FileBitmap++;
        }
    }

    return true;
}

static void PartStream_Close(TBlockStream * pStream)
{
    PART_FILE_HEADER PartHeader;
    ULONGLONG ByteOffset = 0;

    if(pStream->FileBitmap && pStream->IsModified)
    {
        // Prepare the part file header
        memset(&PartHeader, 0, sizeof(PART_FILE_HEADER));
        PartHeader.PartialVersion = 2;
        PartHeader.FileSizeHi     = (DWORD)(pStream->StreamSize >> 0x20);
        PartHeader.FileSizeLo     = (DWORD)(pStream->StreamSize & 0xFFFFFFFF);
        PartHeader.BlockSize      = pStream->BlockSize;

        // Make sure that the header is properly BSWAPed
        BSWAP_ARRAY32_UNSIGNED(&PartHeader, sizeof(PART_FILE_HEADER));
        CascStrPrintf(PartHeader.GameBuildNumber, _countof(PartHeader.GameBuildNumber), "%u", (unsigned int)pStream->BuildNumber);

        // Write the part header
        pStream->BaseWrite(pStream, &ByteOffset, &PartHeader, sizeof(PART_FILE_HEADER));

        // Write the block bitmap
        BSWAP_ARRAY32_UNSIGNED(pStream->FileBitmap, pStream->BitmapSize);
        pStream->BaseWrite(pStream, NULL, pStream->FileBitmap, pStream->BitmapSize);
    }

    // Close the base class
    BlockStream_Close(pStream);
}

static bool PartStream_CreateMirror(TBlockStream * pStream)
{
    ULONGLONG RemainingSize;
    ULONGLONG MasterSize = 0;
    ULONGLONG MirrorSize = 0;
    LPBYTE FileBitmap = NULL;
    DWORD dwBitmapSize;
    DWORD dwBlockCount;
    bool bNeedCreateMirrorStream = true;
    bool bNeedResizeMirrorStream = true;

    // Do we have master function and base creation function?
    if(pStream->pMaster == NULL || pStream->BaseCreate == NULL)
        return false;

    // Retrieve the master file size, block count and bitmap size
    FileStream_GetSize(pStream->pMaster, &MasterSize);
    dwBlockCount = (DWORD)((MasterSize + DEFAULT_BLOCK_SIZE - 1) / DEFAULT_BLOCK_SIZE);
    dwBitmapSize = (DWORD)(dwBlockCount * sizeof(PART_FILE_MAP_ENTRY));

    // Setup stream size and position
    pStream->BuildNumber = DEFAULT_BUILD_NUMBER;        // BUGBUG: Really???
    pStream->StreamSize = MasterSize;
    pStream->StreamPos = 0;

    // Open the base stream for write access
    if(pStream->BaseOpen(pStream, pStream->szFileName, 0))
    {
        // If the file open succeeded, check if the file size matches required size
        pStream->BaseGetSize(pStream, &MirrorSize);
        if(MirrorSize >= sizeof(PART_FILE_HEADER) + dwBitmapSize)
        {
            // Check if the remaining size is aligned to block
            RemainingSize = MirrorSize - sizeof(PART_FILE_HEADER) - dwBitmapSize;
            if((RemainingSize & (DEFAULT_BLOCK_SIZE - 1)) == 0 || RemainingSize == MasterSize)
            {
                // Attempt to load an existing file bitmap
                if(PartStream_LoadBitmap(pStream))
                    return true;
            }
        }

        // We need to create mirror stream
        bNeedCreateMirrorStream = false;
    }

    // Create a new stream, if needed
    if(bNeedCreateMirrorStream)
    {
        if(!pStream->BaseCreate(pStream))
            return false;
    }

    // If we need to, then resize the mirror stream
    if(bNeedResizeMirrorStream)
    {
        if(!pStream->BaseResize(pStream, sizeof(PART_FILE_HEADER) + dwBitmapSize))
            return false;
    }

    // Allocate the bitmap array
    FileBitmap = CASC_ALLOC_ZERO<BYTE>(dwBitmapSize);
    if(FileBitmap == NULL)
        return false;

    // Initialize the bitmap
    pStream->FileBitmap = FileBitmap;
    pStream->BitmapSize = dwBitmapSize;
    pStream->BlockSize  = DEFAULT_BLOCK_SIZE;
    pStream->BlockCount = dwBlockCount;
    pStream->IsComplete = 0;
    pStream->IsModified = 1;

    // Note: Don't write the stream bitmap right away.
    // Doing so would cause sparse file resize on NTFS,
    // which would take long time on larger files.
    return true;
}

static TFileStream * PartStream_Open(LPCTSTR szFileName, DWORD dwStreamFlags)
{
    TBlockStream * pStream;

    // Create new empty stream
    pStream = (TBlockStream *)AllocateFileStream(szFileName, sizeof(TBlockStream), dwStreamFlags);
    if(pStream == NULL)
        return NULL;

    // Do we have a master stream?
    if(pStream->pMaster != NULL)
    {
        if(!PartStream_CreateMirror(pStream))
        {
            FileStream_Close(pStream);
            SetLastError(ERROR_FILE_NOT_FOUND);
            return NULL;
        }
    }
    else
    {
        // Attempt to open the base stream
        if(!pStream->BaseOpen(pStream, pStream->szFileName, dwStreamFlags))
        {
            FileStream_Close(pStream);
            return NULL;
        }

        // Load the part stream block map
        if(!PartStream_LoadBitmap(pStream))
        {
            FileStream_Close(pStream);
            SetLastError(ERROR_BAD_FORMAT);
            return NULL;
        }
    }

    // Set the stream position to zero. Stream size is already set
    assert(pStream->StreamSize != 0);
    pStream->StreamPos = 0;
    pStream->dwFlags |= STREAM_FLAG_READ_ONLY;

    // Set new function pointers
    pStream->StreamRead    = (STREAM_READ)BlockStream_Read;
    pStream->StreamGetPos  = BlockStream_GetPos;
    pStream->StreamGetSize = BlockStream_GetSize;
    pStream->StreamClose   = (STREAM_CLOSE)PartStream_Close;

    // Supply the block functions
    pStream->BlockCheck    = (BLOCK_CHECK)PartStream_BlockCheck;
    pStream->BlockRead     = (BLOCK_READ)PartStream_BlockRead;
    return pStream;
}

//-----------------------------------------------------------------------------
// Local functions - encrypted stream support

static const char * szKeyTemplate = "expand 32-byte k000000000000000000000000000000000000000000000000";

static const char * AuthCodeArray[] =
{
    // Starcraft II (Heart of the Swarm)
    // Authentication code URL: http://dist.blizzard.com/mediakey/hots-authenticationcode-bgdl.txt
    //                                                                                          -0C-    -1C--08-    -18--04-    -14--00-    -10-
    "S48B6CDTN5XEQAKQDJNDLJBJ73FDFM3U",         // SC2 Heart of the Swarm-all : "expand 32-byte kQAKQ0000FM3UN5XE000073FD6CDT0000LJBJS48B0000DJND"

    // Diablo III: Agent.exe (1.0.0.954)
    // Address of decryption routine: 00502b00
    // Pointer to decryptor object: ECX
    // Pointer to key: ECX+0x5C
    // Authentication code URL: http://dist.blizzard.com/mediakey/d3-authenticationcode-enGB.txt
    //                                                                                           -0C-    -1C--08-    -18--04-    -14--00-    -10-
    "UCMXF6EJY352EFH4XFRXCFH2XC9MQRZK",         // Diablo III Installer (deDE): "expand 32-byte kEFH40000QRZKY3520000XC9MF6EJ0000CFH2UCMX0000XFRX"
    "MMKVHY48RP7WXP4GHYBQ7SL9J9UNPHBP",         // Diablo III Installer (enGB): "expand 32-byte kXP4G0000PHBPRP7W0000J9UNHY4800007SL9MMKV0000HYBQ"
    "8MXLWHQ7VGGLTZ9MQZQSFDCLJYET3CPP",         // Diablo III Installer (enSG): "expand 32-byte kTZ9M00003CPPVGGL0000JYETWHQ70000FDCL8MXL0000QZQS"
    "EJ2R5TM6XFE2GUNG5QDGHKQ9UAKPWZSZ",         // Diablo III Installer (enUS): "expand 32-byte kGUNG0000WZSZXFE20000UAKP5TM60000HKQ9EJ2R00005QDG"
    "PBGFBE42Z6LNK65UGJQ3WZVMCLP4HQQT",         // Diablo III Installer (esES): "expand 32-byte kK65U0000HQQTZ6LN0000CLP4BE420000WZVMPBGF0000GJQ3"
    "X7SEJJS9TSGCW5P28EBSC47AJPEY8VU2",         // Diablo III Installer (esMX): "expand 32-byte kW5P200008VU2TSGC0000JPEYJJS90000C47AX7SE00008EBS"
    "5KVBQA8VYE6XRY3DLGC5ZDE4XS4P7YA2",         // Diablo III Installer (frFR): "expand 32-byte kRY3D00007YA2YE6X0000XS4PQA8V0000ZDE45KVB0000LGC5"
    "478JD2K56EVNVVY4XX8TDWYT5B8KB254",         // Diablo III Installer (itIT): "expand 32-byte kVVY40000B2546EVN00005B8KD2K50000DWYT478J0000XX8T"
    "8TS4VNFQRZTN6YWHE9CHVDH9NVWD474A",         // Diablo III Installer (koKR): "expand 32-byte k6YWH0000474ARZTN0000NVWDVNFQ0000VDH98TS40000E9CH"
    "LJ52Z32DF4LZ4ZJJXVKK3AZQA6GABLJB",         // Diablo III Installer (plPL): "expand 32-byte k4ZJJ0000BLJBF4LZ0000A6GAZ32D00003AZQLJ520000XVKK"
    "K6BDHY2ECUE2545YKNLBJPVYWHE7XYAG",         // Diablo III Installer (ptBR): "expand 32-byte k545Y0000XYAGCUE20000WHE7HY2E0000JPVYK6BD0000KNLB"
    "NDVW8GWLAYCRPGRNY8RT7ZZUQU63VLPR",         // Diablo III Installer (ruRU): "expand 32-byte kXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    "6VWCQTN8V3ZZMRUCZXV8A8CGUX2TAA8H",         // Diablo III Installer (zhTW): "expand 32-byte kMRUC0000AA8HV3ZZ0000UX2TQTN80000A8CG6VWC0000ZXV8"
//  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",         // Diablo III Installer (zhCN): "expand 32-byte kXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"

    // Starcraft II (Wings of Liberty): Installer.exe (4.1.1.4219)
    // Address of decryption routine: 0053A3D0
    // Pointer to decryptor object: ECX
    // Pointer to key: ECX+0x5C
    // Authentication code URL: http://dist.blizzard.com/mediakey/sc2-authenticationcode-enUS.txt
    //                                                                                          -0C-    -1C--08-    -18--04-    -14--00-    -10-
    "Y45MD3CAK4KXSSXHYD9VY64Z8EKJ4XFX",         // SC2 Wings of Liberty (deDE): "expand 32-byte kSSXH00004XFXK4KX00008EKJD3CA0000Y64ZY45M0000YD9V"
    "G8MN8UDG6NA2ANGY6A3DNY82HRGF29ZH",         // SC2 Wings of Liberty (enGB): "expand 32-byte kANGY000029ZH6NA20000HRGF8UDG0000NY82G8MN00006A3D"
    "W9RRHLB2FDU9WW5B3ECEBLRSFWZSF7HW",         // SC2 Wings of Liberty (enSG): "expand 32-byte kWW5B0000F7HWFDU90000FWZSHLB20000BLRSW9RR00003ECE"
    "3DH5RE5NVM5GTFD85LXGWT6FK859ETR5",         // SC2 Wings of Liberty (enUS): "expand 32-byte kTFD80000ETR5VM5G0000K859RE5N0000WT6F3DH500005LXG"
    "8WLKUAXE94PFQU4Y249PAZ24N4R4XKTQ",         // SC2 Wings of Liberty (esES): "expand 32-byte kQU4Y0000XKTQ94PF0000N4R4UAXE0000AZ248WLK0000249P"
    "A34DXX3VHGGXSQBRFE5UFFDXMF9G4G54",         // SC2 Wings of Liberty (esMX): "expand 32-byte kSQBR00004G54HGGX0000MF9GXX3V0000FFDXA34D0000FE5U"
    "ZG7J9K938HJEFWPQUA768MA2PFER6EAJ",         // SC2 Wings of Liberty (frFR): "expand 32-byte kFWPQ00006EAJ8HJE0000PFER9K9300008MA2ZG7J0000UA76"
    "NE7CUNNNTVAPXV7E3G2BSVBWGVMW8BL2",         // SC2 Wings of Liberty (itIT): "expand 32-byte kXV7E00008BL2TVAP0000GVMWUNNN0000SVBWNE7C00003G2B"
    "3V9E2FTMBM9QQWK7U6MAMWAZWQDB838F",         // SC2 Wings of Liberty (koKR): "expand 32-byte kQWK70000838FBM9Q0000WQDB2FTM0000MWAZ3V9E0000U6MA"
    "2NSFB8MELULJ83U6YHA3UP6K4MQD48L6",         // SC2 Wings of Liberty (plPL): "expand 32-byte k83U6000048L6LULJ00004MQDB8ME0000UP6K2NSF0000YHA3"
    "QA2TZ9EWZ4CUU8BMB5WXCTY65F9CSW4E",         // SC2 Wings of Liberty (ptBR): "expand 32-byte kU8BM0000SW4EZ4CU00005F9CZ9EW0000CTY6QA2T0000B5WX"
    "VHB378W64BAT9SH7D68VV9NLQDK9YEGT",         // SC2 Wings of Liberty (ruRU): "expand 32-byte k9SH70000YEGT4BAT0000QDK978W60000V9NLVHB30000D68V"
    "U3NFQJV4M6GC7KBN9XQJ3BRDN3PLD9NE",         // SC2 Wings of Liberty (zhTW): "expand 32-byte k7KBN0000D9NEM6GC0000N3PLQJV400003BRDU3NF00009XQJ"

    NULL
};

static void CreateKeyFromAuthCode(
    LPBYTE pbKeyBuffer,
    const char * szAuthCode)
{
    PDWORD KeyPosition = (PDWORD)(pbKeyBuffer + 0x10);
    PDWORD AuthCode32 = (PDWORD)szAuthCode;

    memcpy(pbKeyBuffer, szKeyTemplate, ENCRYPTED_CHUNK_SIZE);
    KeyPosition[0x00] = AuthCode32[0x03];
    KeyPosition[0x02] = AuthCode32[0x07];
    KeyPosition[0x03] = AuthCode32[0x02];
    KeyPosition[0x05] = AuthCode32[0x06];
    KeyPosition[0x06] = AuthCode32[0x01];
    KeyPosition[0x08] = AuthCode32[0x05];
    KeyPosition[0x09] = AuthCode32[0x00];
    KeyPosition[0x0B] = AuthCode32[0x04];
    BSWAP_ARRAY32_UNSIGNED(pbKeyBuffer, ENCRYPTED_CHUNK_SIZE);
}

static void DecryptFileChunk(
    DWORD * ChunkData,
    LPBYTE pbKey,
    ULONGLONG ByteOffset,
    DWORD dwLength)
{
    ULONGLONG ChunkOffset;
    DWORD KeyShuffled[0x10];
    DWORD KeyMirror[0x10];
    DWORD RoundCount = 0x14;

    // Prepare the key
    ChunkOffset = ByteOffset / ENCRYPTED_CHUNK_SIZE;
    memcpy(KeyMirror, pbKey, ENCRYPTED_CHUNK_SIZE);
    BSWAP_ARRAY32_UNSIGNED(KeyMirror, ENCRYPTED_CHUNK_SIZE);
    KeyMirror[0x05] = (DWORD)(ChunkOffset >> 32);
    KeyMirror[0x08] = (DWORD)(ChunkOffset);

    while(dwLength >= ENCRYPTED_CHUNK_SIZE)
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
        BSWAP_ARRAY32_UNSIGNED(ChunkData, ENCRYPTED_CHUNK_SIZE);
        ChunkData[0x00] = ChunkData[0x00] ^ (KeyShuffled[0x0E] + KeyMirror[0x00]);
        ChunkData[0x01] = ChunkData[0x01] ^ (KeyShuffled[0x04] + KeyMirror[0x0D]);
        ChunkData[0x02] = ChunkData[0x02] ^ (KeyShuffled[0x08] + KeyMirror[0x0A]);
        ChunkData[0x03] = ChunkData[0x03] ^ (KeyShuffled[0x09] + KeyMirror[0x07]);
        ChunkData[0x04] = ChunkData[0x04] ^ (KeyShuffled[0x0A] + KeyMirror[0x04]);
        ChunkData[0x05] = ChunkData[0x05] ^ (KeyShuffled[0x0C] + KeyMirror[0x01]);
        ChunkData[0x06] = ChunkData[0x06] ^ (KeyShuffled[0x01] + KeyMirror[0x0E]);
        ChunkData[0x07] = ChunkData[0x07] ^ (KeyShuffled[0x0D] + KeyMirror[0x0B]);
        ChunkData[0x08] = ChunkData[0x08] ^ (KeyShuffled[0x03] + KeyMirror[0x08]);
        ChunkData[0x09] = ChunkData[0x09] ^ (KeyShuffled[0x07] + KeyMirror[0x05]);
        ChunkData[0x0A] = ChunkData[0x0A] ^ (KeyShuffled[0x05] + KeyMirror[0x02]);
        ChunkData[0x0B] = ChunkData[0x0B] ^ (KeyShuffled[0x00] + KeyMirror[0x0F]);
        ChunkData[0x0C] = ChunkData[0x0C] ^ (KeyShuffled[0x02] + KeyMirror[0x0C]);
        ChunkData[0x0D] = ChunkData[0x0D] ^ (KeyShuffled[0x06] + KeyMirror[0x09]);
        ChunkData[0x0E] = ChunkData[0x0E] ^ (KeyShuffled[0x0B] + KeyMirror[0x06]);
        ChunkData[0x0F] = ChunkData[0x0F] ^ (KeyShuffled[0x0F] + KeyMirror[0x03]);
        BSWAP_ARRAY32_UNSIGNED(ChunkData, ENCRYPTED_CHUNK_SIZE);

        // Update byte offset in the key
        KeyMirror[0x08]++;
        if(KeyMirror[0x08] == 0)
            KeyMirror[0x05]++;

        // Move pointers and decrease number of bytes to decrypt
        ChunkData += (ENCRYPTED_CHUNK_SIZE / sizeof(DWORD));
        dwLength -= ENCRYPTED_CHUNK_SIZE;
    }
}

static bool EncrStream_DetectFileKey(TEncryptedStream * pStream)
{
    ULONGLONG ByteOffset = 0;
    BYTE EncryptedHeader[ENCRYPTED_CHUNK_SIZE];
    BYTE FileHeader[ENCRYPTED_CHUNK_SIZE];

    // Read the first file chunk
    if(pStream->BaseRead(pStream, &ByteOffset, EncryptedHeader, sizeof(EncryptedHeader)))
    {
        // We just try all known keys one by one
        for(int i = 0; AuthCodeArray[i] != NULL; i++)
        {
            // Prepare they decryption key from game serial number
            CreateKeyFromAuthCode(pStream->Key, AuthCodeArray[i]);

            // Try to decrypt with the given key
            memcpy(FileHeader, EncryptedHeader, ENCRYPTED_CHUNK_SIZE);
            DecryptFileChunk((PDWORD)FileHeader, pStream->Key, ByteOffset, ENCRYPTED_CHUNK_SIZE);

            // We check the decrypted data
            // All known encrypted archives have header at the begin of the file,
            // so we check for archive signature there.
            if(FileHeader[0] == 'M' && FileHeader[1] == 'P' && FileHeader[2] == 'Q')
            {
                // Update the stream size
                pStream->StreamSize = pStream->Base.File.FileSize;

                // Fill the block information
                pStream->BlockSize  = ENCRYPTED_CHUNK_SIZE;
                pStream->BlockCount = (DWORD)(pStream->Base.File.FileSize + ENCRYPTED_CHUNK_SIZE - 1) / ENCRYPTED_CHUNK_SIZE;
                pStream->IsComplete = 1;
                return true;
            }
        }
    }

    // Key not found, sorry
    return false;
}

static bool EncrStream_BlockRead(
    TEncryptedStream * pStream,
    ULONGLONG StartOffset,
    ULONGLONG EndOffset,
    LPBYTE BlockBuffer,
    DWORD BytesNeeded,
    bool bAvailable)
{
    DWORD dwBytesToRead;

    assert((StartOffset & (pStream->BlockSize - 1)) == 0);
    assert(StartOffset < EndOffset);
    assert(bAvailable != false);
    BytesNeeded = BytesNeeded;
    bAvailable = bAvailable;

    // Read the file from the stream as-is
    // Limit the reading to number of blocks really needed
    dwBytesToRead = (DWORD)(EndOffset - StartOffset);
    if(!pStream->BaseRead(pStream, &StartOffset, BlockBuffer, dwBytesToRead))
        return false;

    // Decrypt the data
    dwBytesToRead = (dwBytesToRead + ENCRYPTED_CHUNK_SIZE - 1) & ~(ENCRYPTED_CHUNK_SIZE - 1);
    DecryptFileChunk((PDWORD)BlockBuffer, pStream->Key, StartOffset, dwBytesToRead);
    return true;
}

static TFileStream * EncrStream_Open(LPCTSTR szFileName, DWORD dwStreamFlags)
{
    TEncryptedStream * pStream;

    // Create new empty stream
    pStream = (TEncryptedStream *)AllocateFileStream(szFileName, sizeof(TEncryptedStream), dwStreamFlags);
    if(pStream == NULL)
        return NULL;

    // Attempt to open the base stream
    assert(pStream->BaseOpen != NULL);
    if(!pStream->BaseOpen(pStream, pStream->szFileName, dwStreamFlags))
        return NULL;

    // Determine the encryption key for the archive
    if(EncrStream_DetectFileKey(pStream))
    {
        // Set the stream position and size
        assert(pStream->StreamSize != 0);
        pStream->StreamPos = 0;
        pStream->dwFlags |= STREAM_FLAG_READ_ONLY;

        // Set new function pointers
        pStream->StreamRead    = (STREAM_READ)BlockStream_Read;
        pStream->StreamGetPos  = BlockStream_GetPos;
        pStream->StreamGetSize = BlockStream_GetSize;
        pStream->StreamClose   = pStream->BaseClose;

        // Supply the block functions
        pStream->BlockRead     = (BLOCK_READ)EncrStream_BlockRead;
        return pStream;
    }

    // Cleanup the stream and return
    FileStream_Close(pStream);
    SetLastError(ERROR_FILE_ENCRYPTED);
    return NULL;
}

//-----------------------------------------------------------------------------
// Local functions - Block4 stream support

#define BLOCK4_BLOCK_SIZE   0x4000          // Size of one block
#define BLOCK4_HASH_SIZE    0x20            // Size of MD5 hash that is after each block
#define BLOCK4_MAX_BLOCKS   0x00002000      // Maximum amount of blocks per file
#define BLOCK4_MAX_FSIZE    0x08040000      // Max size of one file

static bool Block4Stream_BlockRead(
    TBlockStream * pStream,                // Pointer to an open stream
    ULONGLONG StartOffset,
    ULONGLONG EndOffset,
    LPBYTE BlockBuffer,
    DWORD BytesNeeded,
    bool bAvailable)
{
    TBaseProviderData * BaseArray = (TBaseProviderData *)pStream->FileBitmap;
    ULONGLONG ByteOffset;
    DWORD BytesToRead;
    DWORD StreamIndex;
    DWORD BlockIndex;
    bool bResult;

    // The starting offset must be aligned to size of the block
    assert(pStream->FileBitmap != NULL);
    assert((StartOffset & (pStream->BlockSize - 1)) == 0);
    assert(StartOffset < EndOffset);
    assert(bAvailable == true);

    // Keep compiler happy
    bAvailable = bAvailable;
    EndOffset = EndOffset;

    while(BytesNeeded != 0)
    {
        // Calculate the block index and the file index
        StreamIndex = (DWORD)((StartOffset / pStream->BlockSize) / BLOCK4_MAX_BLOCKS);
        BlockIndex  = (DWORD)((StartOffset / pStream->BlockSize) % BLOCK4_MAX_BLOCKS);
        if(StreamIndex > pStream->BitmapSize)
            return false;

        // Calculate the block offset
        ByteOffset = ((ULONGLONG)BlockIndex * (BLOCK4_BLOCK_SIZE + BLOCK4_HASH_SIZE));
        BytesToRead = CASCLIB_MIN(BytesNeeded, BLOCK4_BLOCK_SIZE);

        // Read from the base stream
        pStream->Base = BaseArray[StreamIndex];
        bResult = pStream->BaseRead(pStream, &ByteOffset, BlockBuffer, BytesToRead);
        BaseArray[StreamIndex] = pStream->Base;

        // Did the result succeed?
        if(bResult == false)
            return false;

        // Move pointers
        StartOffset += BytesToRead;
        BlockBuffer += BytesToRead;
        BytesNeeded -= BytesToRead;
    }

    return true;
}


static void Block4Stream_Close(TBlockStream * pStream)
{
    TBaseProviderData * BaseArray = (TBaseProviderData *)pStream->FileBitmap;

    // If we have a non-zero count of base streams,
    // we have to close them all
    if(BaseArray != NULL)
    {
        // Close all base streams
        for(DWORD i = 0; i < pStream->BitmapSize; i++)
        {
            memcpy(&pStream->Base, BaseArray + i, sizeof(TBaseProviderData));
            pStream->BaseClose(pStream);
        }
    }

    // Free the data map, if any
    CASC_FREE(pStream->FileBitmap);

    // Do not call the BaseClose function,
    // we closed all handles already
    return;
}

static TFileStream * Block4Stream_Open(LPCTSTR szFileName, DWORD dwStreamFlags)
{
    TBaseProviderData * NewBaseArray = NULL;
    ULONGLONG RemainderBlock;
    ULONGLONG BlockCount;
    ULONGLONG FileSize;
    TBlockStream * pStream;
    LPTSTR szNameBuff;
    size_t nNameLength;
    DWORD dwBaseFiles = 0;
    DWORD dwBaseFlags;

    // Create new empty stream
    pStream = (TBlockStream *)AllocateFileStream(szFileName, sizeof(TBlockStream), dwStreamFlags);
    if(pStream == NULL)
        return NULL;

    // Sanity check
    assert(pStream->BaseOpen != NULL);

    // Get the length of the file name without numeric suffix
    nNameLength = _tcslen(pStream->szFileName);
    if(pStream->szFileName[nNameLength - 2] == '.' && pStream->szFileName[nNameLength - 1] == '0')
        nNameLength -= 2;
    pStream->szFileName[nNameLength] = 0;

    // Supply the stream functions
    pStream->StreamRead    = (STREAM_READ)BlockStream_Read;
    pStream->StreamGetSize = BlockStream_GetSize;
    pStream->StreamGetPos  = BlockStream_GetPos;
    pStream->StreamClose   = (STREAM_CLOSE)Block4Stream_Close;
    pStream->BlockRead     = (BLOCK_READ)Block4Stream_BlockRead;

    // Allocate work space for numeric names
    szNameBuff = CASC_ALLOC<TCHAR>(nNameLength + 4);
    if(szNameBuff != NULL)
    {
        // Set the base flags
        dwBaseFlags = (dwStreamFlags & STREAM_PROVIDERS_MASK) | STREAM_FLAG_READ_ONLY;

        // Go all suffixes from 0 to 30
        for(int nSuffix = 0; nSuffix < 30; nSuffix++)
        {
            // Open the n-th file
            CascStrPrintf(szNameBuff, (nNameLength + 4), _T("%s.%u"), pStream->szFileName, nSuffix);
            if(!pStream->BaseOpen(pStream, szNameBuff, dwBaseFlags))
                break;

            // If the open succeeded, we re-allocate the base provider array
            NewBaseArray = CASC_ALLOC<TBaseProviderData>(dwBaseFiles + 1);
            if(NewBaseArray == NULL)
            {
                SetLastError(ERROR_NOT_ENOUGH_MEMORY);
                return NULL;
            }

            // Copy the old base data array to the new base data array
            if(pStream->FileBitmap != NULL)
            {
                memcpy(NewBaseArray, pStream->FileBitmap, sizeof(TBaseProviderData) * dwBaseFiles);
                CASC_FREE(pStream->FileBitmap);
            }

            // Also copy the opened base array
            memcpy(NewBaseArray + dwBaseFiles, &pStream->Base, sizeof(TBaseProviderData));
            pStream->FileBitmap = NewBaseArray;
            dwBaseFiles++;

            // Get the size of the base stream
            pStream->BaseGetSize(pStream, &FileSize);
            assert(FileSize <= BLOCK4_MAX_FSIZE);
            RemainderBlock = FileSize % (BLOCK4_BLOCK_SIZE + BLOCK4_HASH_SIZE);
            BlockCount = FileSize / (BLOCK4_BLOCK_SIZE + BLOCK4_HASH_SIZE);

            // Increment the stream size and number of blocks
            pStream->StreamSize += (BlockCount * BLOCK4_BLOCK_SIZE);
            pStream->BlockCount += (DWORD)BlockCount;

            // Is this the last file?
            if(FileSize < BLOCK4_MAX_FSIZE)
            {
                if(RemainderBlock)
                {
                    pStream->StreamSize += (RemainderBlock - BLOCK4_HASH_SIZE);
                    pStream->BlockCount++;
                }
                break;
            }
        }

        // Fill the remainining block stream variables
        pStream->BitmapSize = dwBaseFiles;
        pStream->BlockSize  = BLOCK4_BLOCK_SIZE;
        pStream->IsComplete = 1;
        pStream->IsModified = 0;

        // Fill the remaining stream variables
        pStream->StreamPos = 0;
        pStream->dwFlags |= STREAM_FLAG_READ_ONLY;

        CASC_FREE(szNameBuff);
    }

    // If we opened something, return success
    if(dwBaseFiles == 0)
    {
        FileStream_Close(pStream);
        SetLastError(ERROR_FILE_NOT_FOUND);
        pStream = NULL;
    }

    return pStream;
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
    LPCTSTR szFileName,
    DWORD dwStreamFlags)
{
    TFileStream * pStream;

    // We only support creation of flat, local file
    if((dwStreamFlags & (STREAM_PROVIDERS_MASK)) != (STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE))
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return NULL;
    }

    // Allocate file stream structure for flat stream
    pStream = AllocateFileStream(szFileName, sizeof(TBlockStream), dwStreamFlags);
    if(pStream != NULL)
    {
        // Attempt to create the disk file
        if(BaseFile_Create(pStream))
        {
            // Fill the stream provider functions
            pStream->StreamRead    = pStream->BaseRead;
            pStream->StreamWrite   = pStream->BaseWrite;
            pStream->StreamResize  = pStream->BaseResize;
            pStream->StreamGetSize = pStream->BaseGetSize;
            pStream->StreamGetPos  = pStream->BaseGetPos;
            pStream->StreamClose   = pStream->BaseClose;
            return pStream;
        }

        // File create failed, delete the stream
        CASC_FREE(pStream);
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
 * - The function must initialize all stream function pointers in TFileStream
 * - If the function fails from any reason, it must close all handles
 *   and free all memory that has been allocated in the process of stream creation,
 *   including the TFileStream structure itself
 *
 * \a szFileName Name of the file to open
 * \a dwStreamFlags specifies the provider and base storage type
 */

TFileStream * FileStream_OpenFile(
    LPCTSTR szFileName,
    DWORD dwStreamFlags)
{
    DWORD dwProvider = dwStreamFlags & STREAM_PROVIDERS_MASK;
    size_t nPrefixLength = FileStream_Prefix(szFileName, &dwProvider);

    // Re-assemble the stream flags
    dwStreamFlags = (dwStreamFlags & STREAM_OPTIONS_MASK) | dwProvider;
    szFileName += nPrefixLength;

    // Perform provider-specific open
    switch(dwStreamFlags & STREAM_PROVIDER_MASK)
    {
        case STREAM_PROVIDER_FLAT:
            return FlatStream_Open(szFileName, dwStreamFlags);

        case STREAM_PROVIDER_PARTIAL:
            return PartStream_Open(szFileName, dwStreamFlags);

        case STREAM_PROVIDER_ENCRYPTED:
            return EncrStream_Open(szFileName, dwStreamFlags);

        case STREAM_PROVIDER_BLOCK4:
            return Block4Stream_Open(szFileName, dwStreamFlags);

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return NULL;
    }
}

/**
 * Returns the file name of the stream
 *
 * \a pStream Pointer to an open stream
 */
LPCTSTR FileStream_GetFileName(TFileStream * pStream)
{
    assert(pStream != NULL);
    return pStream->szFileName;
}

/**
 * Returns the length of the provider prefix. Returns zero if no prefix
 *
 * \a szFileName Pointer to a stream name (file, mapped file, URL)
 * \a pdwStreamProvider Pointer to a DWORD variable that receives stream provider (STREAM_PROVIDER_XXX)
 */

size_t FileStream_Prefix(LPCTSTR szFileName, DWORD * pdwProvider)
{
    size_t nPrefixLength1 = 0;
    size_t nPrefixLength2 = 0;
    DWORD dwProvider = 0;

    if(szFileName != NULL)
    {
        //
        // Determine the stream provider
        //

        if(!_tcsnicmp(szFileName, _T("flat-"), 5))
        {
            dwProvider |= STREAM_PROVIDER_FLAT;
            nPrefixLength1 = 5;
        }

        else if(!_tcsnicmp(szFileName, _T("part-"), 5))
        {
            dwProvider |= STREAM_PROVIDER_PARTIAL;
            nPrefixLength1 = 5;
        }

        else if(!_tcsnicmp(szFileName, _T("mpqe-"), 5))
        {
            dwProvider |= STREAM_PROVIDER_ENCRYPTED;
            nPrefixLength1 = 5;
        }

        else if(!_tcsnicmp(szFileName, _T("blk4-"), 5))
        {
            dwProvider |= STREAM_PROVIDER_BLOCK4;
            nPrefixLength1 = 5;
        }

        //
        // Determine the base provider
        //

        if(!_tcsnicmp(szFileName+nPrefixLength1, _T("file:"), 5))
        {
            dwProvider |= BASE_PROVIDER_FILE;
            nPrefixLength2 = 5;
        }

        else if(!_tcsnicmp(szFileName+nPrefixLength1, _T("map:"), 4))
        {
            dwProvider |= BASE_PROVIDER_MAP;
            nPrefixLength2 = 4;
        }

        else if(!_tcsnicmp(szFileName+nPrefixLength1, _T("http:"), 5))
        {
            dwProvider |= BASE_PROVIDER_HTTP;
            nPrefixLength2 = 5;
        }

        // Only accept stream provider if we recognized the base provider
        if(nPrefixLength2 != 0)
        {
            // It is also allowed to put "//" after the base provider, e.g. "file://", "http://"
            if(szFileName[nPrefixLength1+nPrefixLength2] == '/' && szFileName[nPrefixLength1+nPrefixLength2+1] == '/')
                nPrefixLength2 += 2;

            if(pdwProvider != NULL)
                *pdwProvider = dwProvider;
            return nPrefixLength1 + nPrefixLength2;
        }
    }

    return 0;
}

/**
 * Sets a download callback. Whenever the stream needs to download one or more blocks
 * from the server, the callback is called
 *
 * \a pStream Pointer to an open stream
 * \a pfnCallback Pointer to callback function
 * \a pvUserData Arbitrary user pointer passed to the download callback
 */

bool FileStream_SetCallback(TFileStream * pStream, STREAM_DOWNLOAD_CALLBACK pfnCallback, void * pvUserData)
{
    TBlockStream * pBlockStream = (TBlockStream *)pStream;

    if(pStream->BlockRead == NULL)
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return false;
    }

    pBlockStream->pfnCallback = pfnCallback;
    pBlockStream->UserData = pvUserData;
    return true;
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
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    assert(pStream->StreamWrite != NULL);
    return pStream->StreamWrite(pStream, pByteOffset, pvBuffer, dwBytesToWrite);
}

/**
 * Returns the size of a file
 *
 * \a pStream Pointer to an open stream
 * \a FileSize Pointer where to store the file size
 */
bool FileStream_GetSize(TFileStream * pStream, ULONGLONG * pFileSize)
{
    assert(pStream->StreamGetSize != NULL);
    return pStream->StreamGetSize(pStream, pFileSize);
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
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    assert(pStream->StreamResize != NULL);
    return pStream->StreamResize(pStream, NewFileSize);
}

/**
 * This function returns the current file position
 * \a pStream
 * \a pByteOffset
 */
bool FileStream_GetPos(TFileStream * pStream, ULONGLONG * pByteOffset)
{
    assert(pStream->StreamGetPos != NULL);
    return pStream->StreamGetPos(pStream, pByteOffset);
}

/**
 * Returns the last write time of a file
 *
 * \a pStream Pointer to an open stream
 * \a pFileType Pointer where to store the file last write time
 */
bool FileStream_GetTime(TFileStream * pStream, ULONGLONG * pFileTime)
{
    // Just use the saved filetime value
    *pFileTime = pStream->Base.File.FileTime;
    return true;
}

/**
 * Returns the stream flags
 *
 * \a pStream Pointer to an open stream
 * \a pdwStreamFlags Pointer where to store the stream flags
 */
bool FileStream_GetFlags(TFileStream * pStream, PDWORD pdwStreamFlags)
{
    *pdwStreamFlags = pStream->dwFlags;
    return true;
}

/**
 * Switches a stream with another. Used for final phase of archive compacting.
 * Performs these steps:
 *
 * 1) Closes the handle to the existing file
 * 2) Renames the temporary file to the original file, overwrites existing one
 * 3) Opens the file stores the handle and stream position to the new stream structure
 *
 * \a pStream Pointer to an open stream
 * \a pNewStream Temporary ("working") stream (created during archive compacting)
 */
bool FileStream_Replace(TFileStream * pStream, TFileStream * pNewStream)
{
    // Only supported on flat files
    if((pStream->dwFlags & STREAM_PROVIDERS_MASK) != (STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE))
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return false;
    }

    // Not supported on read-only streams
    if(pStream->dwFlags & STREAM_FLAG_READ_ONLY)
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    // Close both stream's base providers
    pNewStream->BaseClose(pNewStream);
    pStream->BaseClose(pStream);

    // Now we have to delete the (now closed) old file and rename the new file
    if(!BaseFile_Replace(pStream, pNewStream))
        return false;

    // Now open the base file again
    if(!BaseFile_Open(pStream, pStream->szFileName, pStream->dwFlags))
        return false;

    // Cleanup the new stream
    FileStream_Close(pNewStream);
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
        // Free the master stream, if any
        if(pStream->pMaster != NULL)
            FileStream_Close(pStream->pMaster);
        pStream->pMaster = NULL;

        // Close the stream provider.
        if(pStream->StreamClose != NULL)
            pStream->StreamClose(pStream);

        // Also close base stream, if any
        else if(pStream->BaseClose != NULL)
            pStream->BaseClose(pStream);

        // Free the stream lock
        CascFreeLock(pStream->Lock);

        // Free the stream itself
        CASC_FREE(pStream);
    }
}
