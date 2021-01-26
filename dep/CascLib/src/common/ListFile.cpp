/*****************************************************************************/
/* ListFile.cpp                           Copyright (c) Ladislav Zezula 2004 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 12.06.04  1.00  Lad  The first version of ListFile.cpp                    */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Listfile cache structure

#define LISTFILE_FLAG_USES_FILEDATAID   0x0001   // A new CSV format, containing FileDataId; FullFileName

typedef struct _LISTFILE_CACHE
{
    char * pBegin;                              // The begin of the listfile cache
    char * pPos;                                // Current position in the cache
    char * pEnd;                                // The last character in the file cache
    DWORD Flags;

    // Followed by the cache (variable length)

} LISTFILE_CACHE, *PLISTFILE_CACHE;

//-----------------------------------------------------------------------------
// Creating the listfile cache for the given amount of data

static PLISTFILE_CACHE ListFile_CreateCache(DWORD dwFileSize)
{
    PLISTFILE_CACHE pCache;

    // Allocate cache for one file block
    pCache = (PLISTFILE_CACHE)CASC_ALLOC<BYTE>(sizeof(LISTFILE_CACHE) + dwFileSize);
    if(pCache != NULL)
    {
        // Set the initial pointers
        pCache->pBegin =
        pCache->pPos   = (char *)(pCache + 1);
        pCache->pEnd   = pCache->pBegin + dwFileSize;
        pCache->Flags  = 0;
    }

    // Return the cache
    return pCache;
}

static char * ListFile_SkipSpaces(PLISTFILE_CACHE pCache)
{
    // Skip newlines, spaces, tabs and another non-printable stuff
    while(pCache->pPos < pCache->pEnd && pCache->pPos[0] <= 0x20)
        pCache->pPos++;

    // Remember the begin of the line
    return pCache->pPos;
}

static void ListFile_CheckFormat(PLISTFILE_CACHE pCache)
{
    // Only if the listfile is greatger than 2 MB
    if((pCache->pEnd - pCache->pBegin) > 0x100000)
    {
        char * szPtr = pCache->pBegin;
        size_t nDigitCount = 0;

        // Calculate the amount of digits
        while(nDigitCount <= 20 && '0' <= szPtr[nDigitCount] && szPtr[nDigitCount] <= '9')
            nDigitCount++;

        // There must be a semicolon after
        if(nDigitCount <= 10 && szPtr[nDigitCount] == ';')
        {
            pCache->Flags |= LISTFILE_FLAG_USES_FILEDATAID;
        }
    }
}

static int ListFile_GetFileDataId(PLISTFILE_CACHE pCache, PDWORD PtrFileDataId)
{
    char * szLineBegin = ListFile_SkipSpaces(pCache);
    char * szLineEnd;
    DWORD dwNewInt32 = 0;
    DWORD dwInt32 = 0;

    // Set the limit for loading the number
    szLineEnd = CASCLIB_MIN((szLineBegin + 20), pCache->pEnd);

    // Extract decimal digits from the string
    while(szLineBegin < szLineEnd && '0' <= szLineBegin[0] && szLineBegin[0] <= '9')
    {
        // Check integer overflow
        dwNewInt32 = (dwInt32 * 10) + (szLineBegin[0] - '0');
        if(dwNewInt32 < dwInt32)
            return ERROR_BAD_FORMAT;

        dwInt32 = dwNewInt32;
        szLineBegin++;
    }

    // There must still be some space
    if(szLineBegin < szLineEnd)
    {
        // There must be a semicolon after the decimal integer
        // The decimal integer must be smaller than 10 MB (files)
        if(szLineBegin[0] != ';' || dwInt32 >= 0xA00000)
            return ERROR_BAD_FORMAT;

        pCache->pPos = szLineBegin + 1;
        PtrFileDataId[0] = dwInt32;
        return ERROR_SUCCESS;
    }

    return ERROR_NO_MORE_FILES;
}

//-----------------------------------------------------------------------------
// Functions for parsing an external listfile

void * ListFile_OpenExternal(LPCTSTR szListFile)
{
    PLISTFILE_CACHE pCache = NULL;
    TFileStream * pStream;
    ULONGLONG FileSize = 0;

    // Open the external listfile
    pStream = FileStream_OpenFile(szListFile, STREAM_FLAG_READ_ONLY);
    if(pStream != NULL)
    {
        // Retrieve the size of the external listfile
        FileStream_GetSize(pStream, &FileSize);
        if(0 < FileSize && FileSize <= 0x30000000)
        {
            // Create the in-memory cache for the entire listfile
            // The listfile does not have any data loaded yet
            pCache = ListFile_CreateCache((DWORD)FileSize);
            if(pCache != NULL)
            {
                if(FileStream_Read(pStream, NULL, pCache->pBegin, (DWORD)FileSize))
                {
                    ListFile_CheckFormat(pCache);
                }
                else
                {
                    CASC_FREE(pCache);
                }
            }
        }

        // Close the file stream
        FileStream_Close(pStream);
    }

    return pCache;
}

void * ListFile_FromBuffer(LPBYTE pbBuffer, DWORD cbBuffer)
{
    PLISTFILE_CACHE pCache = NULL;

    // Create the in-memory cache for the entire listfile
    // The listfile does not have any data loaded yet
    pCache = ListFile_CreateCache(cbBuffer);
    if(pCache != NULL)
        memcpy(pCache->pBegin, pbBuffer, cbBuffer);

    return pCache;
}

// Performs the MD5-based check on the listfile
bool ListFile_VerifyMD5(void * pvListFile, LPBYTE pbHashMD5)
{
    PLISTFILE_CACHE pCache = (PLISTFILE_CACHE)pvListFile;

    // Must be at the beginning
    assert(pCache->pPos == pCache->pBegin);

    // Verify the MD5 hash for the entire block
    return CascVerifyDataBlockHash(pCache->pBegin, (DWORD)(pCache->pEnd - pCache->pBegin), pbHashMD5);
}

size_t ListFile_GetNextLine(void * pvListFile, const char ** pszLineBegin, const char ** pszLineEnd)
{
    PLISTFILE_CACHE pCache = (PLISTFILE_CACHE)pvListFile;
    char * szExtraString = NULL;
    char * szLineBegin;
    char * szLineEnd;

    // Skip newlines, spaces, tabs and another non-printable stuff
    // Remember the begin of the line
    szLineBegin = ListFile_SkipSpaces(pCache);

    // Copy the remaining characters
    while(pCache->pPos < pCache->pEnd)
    {
        // If we have found a newline, stop loading
        // Note: the 0x85 char came from Overwatch build 24919
        if(pCache->pPos[0] == '\x0A' || pCache->pPos[0] == '\x0D' || pCache->pPos[0] == '\x85')
            break;

        // Blizzard listfiles can also contain information about patch:
        // Pass1\Files\MacOS\unconditional\user\Background Downloader.app\Contents\Info.plist~Patch(Data#frFR#base-frFR,1326)
        if(pCache->pPos[0] == '~')
            szExtraString = pCache->pPos;

        // Move the position by one character forward
        pCache->pPos++;
    }

    // Remember the end of the line
    szLineEnd = (szExtraString != NULL && szExtraString[0] == '~' && szExtraString[1] == 'P') ? szExtraString : pCache->pPos;

    // Give the caller the positions of the begin and end of the line
    pszLineBegin[0] = szLineBegin;
    pszLineEnd[0] = szLineEnd;
    return (size_t)(szLineEnd - szLineBegin);
}

size_t ListFile_GetNextLine(void * pvListFile, char * szBuffer, size_t nMaxChars)
{
    const char * szLineBegin = NULL;
    const char * szLineEnd = NULL;
    size_t nLength;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Retrieve the next line
    nLength = ListFile_GetNextLine(pvListFile, &szLineBegin, &szLineEnd);

    // Check the length
    if(nLength < nMaxChars)
    {
        // Copy the line to the user buffer
        memcpy(szBuffer, szLineBegin, nLength);
        szBuffer[nLength] = 0;
    }
    else
    {
        dwErrCode = ERROR_INSUFFICIENT_BUFFER;
        nLength = 0;
    }

    // If we didn't read anything, set the error code
    if(nLength == 0)
        SetCascError(dwErrCode);
    return nLength;
}

size_t ListFile_GetNext(void * pvListFile, char * szBuffer, size_t nMaxChars, PDWORD PtrFileDataId)
{
    PLISTFILE_CACHE pCache = (PLISTFILE_CACHE)pvListFile;
    const char * szTemp;
    size_t nLength = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Check for parameters
    for(;;)
    {
        DWORD FileDataId = CASC_INVALID_ID;

        // If this is a CSV-format listfile, we need to extract the FileDataId
        // Lines that contain bogus data, invalid numbers or too big values will be skipped
        if(pCache->Flags & LISTFILE_FLAG_USES_FILEDATAID)
        {
            // Retrieve the data ID from the current position
            dwErrCode = ListFile_GetFileDataId(pCache, &FileDataId);
            if(dwErrCode == ERROR_NO_MORE_FILES)
                break;
            
            // If there was an error, skip the current line
            if(dwErrCode != ERROR_SUCCESS || FileDataId == CASC_INVALID_ID)
            {
                ListFile_GetNextLine(pvListFile, &szTemp, &szTemp);
                continue;
            }
        }

        // Read the (next) line
        nLength = ListFile_GetNextLine(pvListFile, szBuffer, nMaxChars);
        if(nLength == 0)
        {
            dwErrCode = GetCascError();
            break;
        }

        // Give the file data id and return true
        PtrFileDataId[0] = FileDataId;
        return nLength;
    }

    if(dwErrCode != ERROR_SUCCESS)
        SetCascError(dwErrCode);
    return nLength;
}

LPBYTE ListFile_GetData(void * pvListFile, PDWORD PtrDataSize)
{
    PLISTFILE_CACHE pCache = (PLISTFILE_CACHE)pvListFile;
    LPBYTE pbData = NULL;
    DWORD cbData = 0;

    // Get data from the list file cache
    if (pvListFile != NULL)
    {
        pbData = (LPBYTE)pCache->pBegin;
        cbData = (DWORD)(pCache->pEnd - pCache->pBegin);
    }

    // Give the data to the caller
    if (PtrDataSize != NULL)
        PtrDataSize[0] = cbData;
    return pbData;
}

