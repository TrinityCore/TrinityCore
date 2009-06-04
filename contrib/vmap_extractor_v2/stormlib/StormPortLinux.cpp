/********************************************************************
*
* Description:  implementation for StormLib - linux port
*       intended to be used in GLdiablo
*
*   ---->   StormLib was originally developed for Windows by
*       Ladislav Zezula (www.zezula.net), and he did
*       a _great_ job! Thanks Ladislav!
*
*   this is currently a quick and dirty hack to get it working
*    don't expect beauty and/or miracles :)
*
*   these are function wraps to execute Windows API calls
*        as native Macintosh file calls (open/close/read/write/...)
*
*   continue you work: added some wrapping functions for GNU/Linux  by XPinguin
*
* Author: Marko Friedemann <marko.friedemann@bmx-chemnitz.de>
* Created at: Mon Jan 29 19:01:37 CEST 2001
* Computer: whiplash.flachland-chemnitz.de
* System: Linux 2.4.0 on i686
*
* Copyright (c) 2001 BMX-Chemnitz.DE All rights reserved.
*
********************************************************************/

#ifndef _WIN32
#include "StormPort.h"

int globalerr;

void SetLastError(int err)
{
    globalerr = err;
}

int GetLastError()
{
    return(globalerr);
}

char *ErrString(int err)
{
    switch (err) {
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
    default:
        return "unknown error";
    }
}

HANDLE CreateFile(const char *sFileName, DWORD ulMode, DWORD ulSharing, void *pSecAttrib, DWORD ulCreation, DWORD ulFlags, HANDLE hFile)
{
    switch (ulCreation) {
    case OPEN_EXISTING:
        return (HANDLE)open(sFileName, O_RDONLY | O_LARGEFILE);
    case OPEN_ALWAYS:
        return (HANDLE)open(sFileName, O_RDWR | O_CREAT);
    case CREATE_NEW:
        return (HANDLE)open(sFileName, O_RDWR | O_CREAT | O_TRUNC);
    default:
        return INVALID_HANDLE_VALUE;
    }
}

BOOL CloseHandle(HANDLE hFile)
{
    return (close((int)hFile) == 0);
}

DWORD GetFileSize(HANDLE hFile, DWORD *ulOffSetHigh)
{
    if ((hFile == NULL) || (hFile == INVALID_HANDLE_VALUE))
        return 0xffffffff;

    struct stat fileinfo;
    fstat((int)hFile, &fileinfo);
    
    return fileinfo.st_size;
}

DWORD SetFilePointer(HANDLE hFile, LONG lOffSetLow, LONG *pOffSetHigh, DWORD ulMethod)
{
    return lseek64((int)hFile, (off64_t)(*pOffSetHigh) << 32 | (DWORD)lOffSetLow, ulMethod);
}

BOOL SetEndOfFile(HANDLE hFile)
{
    return (ftruncate((int)hFile, lseek((int)hFile, 0, SEEK_CUR)) == 0);
}

BOOL ReadFile(HANDLE hFile, void *pBuffer, DWORD ulLen, DWORD *ulRead, void *pOverLapped)
{
    ssize_t count;
    if ((count = read((int)hFile, pBuffer, ulLen)) == -1) {
        *ulRead = 0;
        return false;
    }
    *ulRead = count;
    return true;
}

BOOL WriteFile(HANDLE hFile, const void *pBuffer, DWORD ulLen, DWORD *ulWritten, void *pOverLapped)
{
    ssize_t count;
    if ((count = write((int)hFile, pBuffer, ulLen)) == -1) {
        *ulWritten = 0;
        return false;
    }
    *ulWritten = count;
    return true;
}

// Check if a memory block is accessible for reading
BOOL IsBadReadPtr(const void * ptr, int size)
{
    return FALSE;
}

// Returns attributes of a file
DWORD GetFileAttributes(const char * szFileName)
{
    return 0;
}

void GetTempPath(DWORD szTempLength, char * szTemp)
{
    strncpy(szTemp, P_tmpdir, szTempLength);
}

void GetTempFileName(const char * lpTempFolderPath, const char * lpFileName, DWORD something, char * szLFName)
{
    strcpy(szLFName, tempnam(lpTempFolderPath, lpFileName));
}

BOOL DeleteFile(const char *lpFileName)
{
    return (BOOL)remove(lpFileName);
}

BOOL MoveFile(const char *lpExistingFileName, const char *lpNewFileName)
{
    return rename(lpExistingFileName, lpNewFileName);
}

#endif
