/*****************************************************************************/
/* CascBuildCfg.cpp                       Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Build configuration for CascLib                                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascBuildCfg.cpp                */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static bool inline IsValueSeparator(LPBYTE pbVarValue)
{
    return ((0 <= pbVarValue[0] && pbVarValue[0] <= 0x20) || (pbVarValue[0] == '|'));
}

static bool IsCharDigit(BYTE OneByte)
{
    return ('0' <= OneByte && OneByte <= '9');
}

static void FreeCascBlob(PQUERY_KEY pBlob)
{
    if(pBlob != NULL)
    {
        if(pBlob->pbData != NULL)
            CASC_FREE(pBlob->pbData);

        pBlob->pbData = NULL;
        pBlob->cbData = 0;
    }
}

static bool IsInfoVariable(const char * szLineBegin, const char * szLineEnd, const char * szVarName, const char * szVarType)
{
    size_t nLength;

    // Check the variable name
    nLength = strlen(szVarName);
    if((size_t)(szLineEnd - szLineBegin) > nLength)
    {
        // Check the variable name
        if(!_strnicmp(szLineBegin, szVarName, nLength))
        {
            // Skip variable name and the exclamation mark
            szLineBegin += nLength;
            if(szLineBegin < szLineEnd && szLineBegin[0] == '!')
            {
                // Skip the exclamation mark
                szLineBegin++;

                // Check the variable type
                nLength = strlen(szVarType);
                if((size_t)(szLineEnd - szLineBegin) > nLength)
                {
                    // Check the variable name
                    if(!_strnicmp(szLineBegin, szVarType, nLength))
                    {
                        // Skip variable type and the doublecolon
                        szLineBegin += nLength;
                        return (szLineBegin < szLineEnd && szLineBegin[0] == ':');
                    }
                }
            }
        }
    }

    return false;
}

static const char * SkipInfoVariable(const char * szLineBegin, const char * szLineEnd)
{
    while(szLineBegin < szLineEnd)
    {
        if(szLineBegin[0] == '|')
            return szLineBegin + 1;

        szLineBegin++;
    }

    return NULL;
}

static TCHAR * CheckForIndexDirectory(TCascStorage * hs, const TCHAR * szSubDir)
{
    TCHAR * szIndexPath;

    // Cpmbine the index path
    szIndexPath = CombinePath(hs->szDataPath, szSubDir);
    if(DirectoryExists(szIndexPath))
    {
        hs->szIndexPath = szIndexPath;
        return hs->szIndexPath;
    }

    delete [] szIndexPath;
    return NULL;
}

TCHAR * AppendBlobText(TCHAR * szBuffer, LPBYTE pbData, DWORD cbData, TCHAR chSeparator)
{
    // Put the separator, if any
    if(chSeparator != 0)
        *szBuffer++ = chSeparator;

    // Copy the blob data as text
    for(DWORD i = 0; i < cbData; i++)
    {
        *szBuffer++ = IntToHexChar[pbData[0] >> 0x04];
        *szBuffer++ = IntToHexChar[pbData[0] & 0x0F];
        pbData++;
    }

    // Terminate the string
    *szBuffer = 0;

    // Return new buffer position
    return szBuffer;
}

static int StringBlobToBinaryBlob(
    PQUERY_KEY pBlob,
    LPBYTE pbBlobBegin, 
    LPBYTE pbBlobEnd)
{
    // Sanity checks
    assert(pBlob != NULL && pBlob->pbData != NULL);

    // Reset the blob length
    pBlob->cbData = 0;

    // Convert the blob
    while(pbBlobBegin < pbBlobEnd)
    {
        BYTE DigitOne;
        BYTE DigitTwo;

        DigitOne = (BYTE)(AsciiToUpperTable[pbBlobBegin[0]] - '0');
        if(DigitOne > 9)
            DigitOne -= 'A' - '9' - 1;

        DigitTwo = (BYTE)(AsciiToUpperTable[pbBlobBegin[1]] - '0');
        if(DigitTwo > 9)
            DigitTwo -= 'A' - '9' - 1;

        if(DigitOne > 0x0F || DigitTwo > 0x0F || pBlob->cbData >= MAX_CASC_KEY_LENGTH)
            return ERROR_BAD_FORMAT;

        pBlob->pbData[pBlob->cbData++] = (DigitOne << 0x04) | DigitTwo;
        pbBlobBegin += 2;
    }

    return ERROR_SUCCESS;
}


static LPBYTE FindNextSeparator(PQUERY_KEY pFileBlob, LPBYTE pbFilePtr)
{
    LPBYTE pbFileBegin = pFileBlob->pbData;
    LPBYTE pbFileEnd = pFileBlob->pbData + pFileBlob->cbData;

    if(pbFileBegin <= pbFilePtr && pbFilePtr < pbFileEnd)
    {
        while(pbFilePtr < pbFileEnd && pbFilePtr[0] != '|')
            pbFilePtr++;

        return pbFilePtr;
    }

    return NULL;
}

static bool GetNextFileLine(PQUERY_KEY pFileBlob, LPBYTE * ppbLineBegin, LPBYTE * ppbLineEnd)
{
    LPBYTE pbLineBegin = *ppbLineBegin;
    LPBYTE pbLineEnd = *ppbLineEnd;
    LPBYTE pbFileEnd = pFileBlob->pbData + pFileBlob->cbData;

    // If there was a previous line, skip all end-of-line chars
    if(pbLineEnd != NULL)
    {
        // Go to the next line
        while(pbLineEnd < pbFileEnd && (pbLineEnd[0] == 0x0A || pbLineEnd[0] == 0x0D))
            pbLineEnd++;
        pbLineBegin = pbLineEnd;

        // If there is no more data, return false
        if(pbLineEnd >= pbFileEnd)
            return false;
    }

    // Skip all spaces before the line begins
    while(pbLineBegin < pbFileEnd && (pbLineBegin[0] == 0x09 || pbLineBegin[0] == 0x20))
        pbLineBegin++;
    pbLineEnd = pbLineBegin;

    // Go to the end of the line
    while(pbLineEnd < pbFileEnd && pbLineEnd[0] != 0x0A && pbLineEnd[0] != 0x0D)
        pbLineEnd++;

    // Give the results to the caller
    *ppbLineBegin = pbLineBegin;
    *ppbLineEnd = pbLineEnd;
    return true;
}

static LPBYTE CheckLineVariable(LPBYTE pbLineBegin, LPBYTE pbLineEnd, const char * szVarName)
{
    size_t nLineLength = (size_t)(pbLineEnd - pbLineBegin);
    size_t nNameLength = strlen(szVarName);

    // If the line longer than the variable name?
    if(nLineLength > nNameLength)
    {
        if(!_strnicmp((const char *)pbLineBegin, szVarName, nNameLength))
        {
            // Skip the variable name
            pbLineBegin += nNameLength;

            // Skip the separator(s)
            while(pbLineBegin < pbLineEnd && IsValueSeparator(pbLineBegin))
                pbLineBegin++;

            // Check if there is "="
            if(pbLineBegin >= pbLineEnd || pbLineBegin[0] != '=')
                return NULL;
            pbLineBegin++;

            // Skip the separator(s)
            while(pbLineBegin < pbLineEnd && IsValueSeparator(pbLineBegin))
                pbLineBegin++;

            // Check if there is "="
            if(pbLineBegin >= pbLineEnd)
                return NULL;

            // Return the begin of the variable
            return pbLineBegin;
        }
    }

    return NULL;
}

static int LoadInfoVariable(PQUERY_KEY pVarBlob, const char * szLineBegin, const char * szLineEnd, bool bHexaValue)
{
    const char * szLinePtr = szLineBegin;

    // Sanity checks
    assert(pVarBlob->pbData == NULL);
    assert(pVarBlob->cbData == 0);

    // Check length of the variable
    while(szLinePtr < szLineEnd && szLinePtr[0] != '|')
        szLinePtr++;

    // Allocate space for the blob
    if(bHexaValue)
    {
        // Initialize the blob
        pVarBlob->pbData = CASC_ALLOC(BYTE, (szLinePtr - szLineBegin) / 2);
        return StringBlobToBinaryBlob(pVarBlob, (LPBYTE)szLineBegin, (LPBYTE)szLinePtr);
    }

    // Initialize the blob
    pVarBlob->pbData = CASC_ALLOC(BYTE, (szLinePtr - szLineBegin) + 1);
    pVarBlob->cbData = (size_t)(szLinePtr - szLineBegin);

    // Check for success
    if(pVarBlob->pbData == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Copy the string
    memcpy(pVarBlob->pbData, szLineBegin, pVarBlob->cbData);
    pVarBlob->pbData[pVarBlob->cbData] = 0;
    return ERROR_SUCCESS;
}


static void AppendConfigFilePath(TCHAR * szFileName, PQUERY_KEY pFileKey)
{
    // Get to the end of the file name
    szFileName = szFileName + _tcslen(szFileName);

    // Append the "config" directory
    _tcscat(szFileName, _T("/config"));
    szFileName += 7;

    // Append the first level directory
    szFileName = AppendBlobText(szFileName, pFileKey->pbData, 1, _T('/'));
    szFileName = AppendBlobText(szFileName, pFileKey->pbData + 1, 1, _T('/'));
    szFileName = AppendBlobText(szFileName, pFileKey->pbData, pFileKey->cbData, _T('/'));
}

static DWORD GetBlobCount(LPBYTE pbLineBegin, LPBYTE pbLineEnd)
{
    DWORD dwBlobCount = 0;

    // Until we find an end of the line
    while(pbLineBegin < pbLineEnd)
    {
        // Skip the blob
        while(pbLineBegin < pbLineEnd && IsValueSeparator(pbLineBegin) == false)
            pbLineBegin++;

        // Increment the number of blobs
        dwBlobCount++;

        // Skip the separator
        while(pbLineBegin < pbLineEnd && IsValueSeparator(pbLineBegin))
            pbLineBegin++;
    }

    return dwBlobCount;
}

static int LoadBlobArray(
    PQUERY_KEY pBlob,
    DWORD dwMaxBlobs,
    LPBYTE pbLineBegin,
    LPBYTE pbLineEnd,
    LPBYTE pbBuffer,
    DWORD dwBufferSize)
{
    LPBYTE pbBlobBegin = pbLineBegin;
    LPBYTE pbBlobEnd = pbLineBegin;
    int nError = ERROR_SUCCESS;

    // Sanity check
    assert(pbBuffer != NULL);

    // Until we find an end of the line
    while(pbBlobBegin < pbLineEnd)
    {
        // Convert the blob from string to binary
        if(dwBufferSize < MAX_CASC_KEY_LENGTH)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Find the end of the text blob
        while(pbBlobEnd < pbLineEnd && IsValueSeparator(pbBlobEnd) == false)
            pbBlobEnd++;

        // Convert the blob from ANSI to binary
        pBlob->pbData = pbBuffer;
        nError = StringBlobToBinaryBlob(pBlob, pbBlobBegin, pbBlobEnd);
        if(nError != ERROR_SUCCESS || dwMaxBlobs == 1)
            break;

        // Move the blob, buffer, and limits
        dwBufferSize -= MAX_CASC_KEY_LENGTH;
        pbBuffer += MAX_CASC_KEY_LENGTH;
        dwMaxBlobs--;
        pBlob++;

        // Skip the separator
        while(pbBlobEnd < pbLineEnd && IsValueSeparator(pbBlobEnd))
            pbBlobEnd++;
        pbBlobBegin = pbBlobEnd;
    }

    return nError;
}

static int LoadSingleBlob(PQUERY_KEY pBlob, LPBYTE pbBlobBegin, LPBYTE pbBlobEnd)
{
    LPBYTE pbBuffer;
    size_t nLength = (pbBlobEnd - pbBlobBegin) / 2;

    // Check maximum size
    if(nLength > MAX_CASC_KEY_LENGTH)
        return ERROR_INVALID_PARAMETER;

    // Allocate the blob buffer
    pbBuffer = CASC_ALLOC(BYTE, MAX_CASC_KEY_LENGTH);
    if(pbBuffer == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    return LoadBlobArray(pBlob, 1, pbBlobBegin, pbBlobEnd, pbBuffer, MAX_CASC_KEY_LENGTH);
}

static PQUERY_KEY LoadMultipleBlobs(LPBYTE pbLineBegin, LPBYTE pbLineEnd, DWORD * pdwBlobCount)
{
    PQUERY_KEY pBlobArray = NULL;
    LPBYTE pbBuffer = NULL;
    DWORD dwBlobCount = GetBlobCount(pbLineBegin, pbLineEnd);
    int nError;

    // Only if there is at least 1 blob
    if(dwBlobCount != 0)
    {
        // Allocate the array of blobs
        pBlobArray = CASC_ALLOC(QUERY_KEY, dwBlobCount);
        if(pBlobArray != NULL)
        {
            // Zero the blob array
            memset(pBlobArray, 0, dwBlobCount * sizeof(QUERY_KEY));

            // Allocate buffer for the blobs
            pbBuffer = CASC_ALLOC(BYTE, dwBlobCount * MAX_CASC_KEY_LENGTH);
            if(pbBuffer != NULL)
            {
                // Zero the buffer
                memset(pbBuffer, 0, dwBlobCount * MAX_CASC_KEY_LENGTH);

                // Load the entire blob array
                nError = LoadBlobArray(pBlobArray, dwBlobCount, pbLineBegin, pbLineEnd, pbBuffer, dwBlobCount * MAX_CASC_KEY_LENGTH);
                if(nError == ERROR_SUCCESS)
                {
                    *pdwBlobCount = dwBlobCount;
                    return pBlobArray;
                }

                // Free the buffer
                CASC_FREE(pbBuffer);
            }

            // Free the array of blobs
            CASC_FREE(pBlobArray);
            pBlobArray = NULL;
        }

        // Reset the blob count
        dwBlobCount = 0;
    }

    *pdwBlobCount = dwBlobCount;
    return pBlobArray;
}

static int LoadTextFile(const TCHAR * szFileName, PQUERY_KEY pFileBlob)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    int nError = ERROR_SUCCESS;

    // Open the agent file
    pStream = FileStream_OpenFile(szFileName, STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        // Retrieve its size
        FileStream_GetSize(pStream, &FileSize);

        // Load the file to memory
        if(0 < FileSize && FileSize < 0x100000)
        {
            // Initialize the blob
            pFileBlob->cbData = (DWORD)FileSize;
            pFileBlob->pbData = CASC_ALLOC(BYTE, pFileBlob->cbData + 1);

            // Load the file data into the blob
            if(pFileBlob->pbData != NULL)
            {
                FileStream_Read(pStream, NULL, pFileBlob->pbData, (DWORD)FileSize);
                pFileBlob->pbData[pFileBlob->cbData] = 0;
            }
            else
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }
        else
            nError = ERROR_INVALID_PARAMETER;

        FileStream_Close(pStream);
    }
    else
        nError = GetLastError();

    return nError;
}

static int GetGameType(TCascStorage * hs, LPBYTE pbVarBegin, LPBYTE pbLineEnd)
{
    // Alpha build of Heroes of the Storm
    if((pbLineEnd - pbVarBegin) == 4 && !_strnicmp((const char *)pbVarBegin, "Hero", 4))
    {
        hs->dwGameInfo = CASC_GAME_HOTS;
        return ERROR_SUCCESS;
    }

    // Alpha build of World of Warcraft - Warlords of Draenor
    if((pbLineEnd - pbVarBegin) == 3 && !_strnicmp((const char *)pbVarBegin, "WoW", 3))
    {
        hs->dwGameInfo = CASC_GAME_WOW6;
        return ERROR_SUCCESS;
    }

    // An unknown game
    assert(false);
    return ERROR_BAD_FORMAT;
}

// "B29049"
// "WOW-18125patch6.0.1"
static int GetBuildNumber(TCascStorage * hs, LPBYTE pbVarBegin, LPBYTE pbLineEnd)
{
    DWORD dwBuildNumber = 0;

    // Skip all non-digit characters
    while(pbVarBegin < pbLineEnd && IsCharDigit(pbVarBegin[0]) == false)
        pbVarBegin++;

    // Convert the build number
    while(pbVarBegin < pbLineEnd && IsCharDigit(pbVarBegin[0]))
        dwBuildNumber = (dwBuildNumber * 10) + (*pbVarBegin++ - '0');

    assert(dwBuildNumber != 0);
    hs->dwBuildNumber = dwBuildNumber;
    return (dwBuildNumber != 0) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static int FetchAndVerifyConfigFile(TCascStorage * hs, PQUERY_KEY pFileKey, PQUERY_KEY pFileBlob)
{
    TCHAR * szFileName;
    int nError;

    // Construct the local file name
    szFileName = NewStr(hs->szDataPath, 8 + 3 + 3 + 32);
    if(szFileName == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Add the part where the config file path is
    AppendConfigFilePath(szFileName, pFileKey);
    
    // Load the config file
    nError = LoadTextFile(szFileName, pFileBlob);
    if(nError == ERROR_SUCCESS)
    {
        // Verify the blob's MD5
        if(!VerifyDataBlockHash(pFileBlob->pbData, pFileBlob->cbData, pFileKey->pbData))
        {
            FreeCascBlob(pFileBlob);
            nError = ERROR_BAD_FORMAT;
        }
    }

    CASC_FREE(szFileName);
    return nError;
}

static int ParseInfoFile(TCascStorage * hs, PQUERY_KEY pFileBlob)
{
    QUERY_KEY CdnHost = {NULL, 0};
    QUERY_KEY CdnPath = {NULL, 0};
    const char * szLineBegin1 = NULL;
    const char * szLineBegin2 = NULL;
    const char * szLineEnd1 = NULL;
    const char * szLineEnd2 = NULL;
    const char * szFileEnd = (const char *)(pFileBlob->pbData + pFileBlob->cbData);
    const char * szFilePtr = (const char *)pFileBlob->pbData;
    int nError = ERROR_BAD_FORMAT;

    // Find the first line
    szLineBegin1 = szFilePtr;
    while(szFilePtr < szFileEnd)
    {
        // Check for the end of the line
        if(szFilePtr[0] == 0x0D || szFilePtr[0] == 0x0A)
        {
            szLineEnd1 = szFilePtr;
            break;
        }

        szFilePtr++;
    }

    // Skip the newline character(s)
    while(szFilePtr < szFileEnd && (szFilePtr[0] == 0x0D || szFilePtr[0] == 0x0A))
        szFilePtr++;

    // Find the second line
    szLineBegin2 = szFilePtr;
    while(szFilePtr < szFileEnd)
    {
        // Check for the end of the line
        if(szFilePtr[0] == 0x0D || szFilePtr[0] == 0x0A)
        {
            szLineEnd2 = szFilePtr;
            break;
        }

        szFilePtr++;
    }

    // Find the build key, CDN config key and the URL path
    while(szLineBegin1 < szLineEnd1)
    {
        // Check for variables we need
        if(IsInfoVariable(szLineBegin1, szLineEnd1, "Build Key", "HEX"))
            LoadInfoVariable(&hs->CdnBuildKey, szLineBegin2, szLineEnd2, true);
        if(IsInfoVariable(szLineBegin1, szLineEnd1, "CDN Key", "HEX"))
            LoadInfoVariable(&hs->CdnConfigKey, szLineBegin2, szLineEnd2, true);
        if(IsInfoVariable(szLineBegin1, szLineEnd1, "CDN Hosts", "STRING"))
            LoadInfoVariable(&CdnHost, szLineBegin2, szLineEnd2, false);
        if(IsInfoVariable(szLineBegin1, szLineEnd1, "CDN Path", "STRING"))
            LoadInfoVariable(&CdnPath, szLineBegin2, szLineEnd2, false);

        // Move both line pointers
        szLineBegin1 = SkipInfoVariable(szLineBegin1, szLineEnd1);
        if(szLineBegin1 == NULL)
            break;

        szLineBegin2 = SkipInfoVariable(szLineBegin2, szLineEnd2);
        if(szLineBegin2 == NULL)
            break;
    }

    // All four must be present
    if(hs->CdnBuildKey.pbData != NULL &&
       hs->CdnConfigKey.pbData != NULL &&
       CdnHost.pbData != NULL &&
       CdnPath.pbData != NULL)
    {
        // Merge the CDN host and CDN path
        hs->szUrlPath = CASC_ALLOC(TCHAR, CdnHost.cbData + CdnPath.cbData + 1);
        if(hs->szUrlPath != NULL)
        {
            CopyString(hs->szUrlPath, (char *)CdnHost.pbData, CdnHost.cbData);
            CopyString(hs->szUrlPath + CdnHost.cbData, (char *)CdnPath.pbData, CdnPath.cbData);
            nError = ERROR_SUCCESS;
        }
    }

    FreeCascBlob(&CdnHost);
    FreeCascBlob(&CdnPath);
    return nError;
}

static int ParseAgentFile(TCascStorage * hs, PQUERY_KEY pFileBlob)
{
    LPBYTE pbBlobBegin = pFileBlob->pbData;
    LPBYTE pbBlobEnd;
    int nError = ERROR_SUCCESS;

    // Extract the CDN build hash
    pbBlobEnd = FindNextSeparator(pFileBlob, pbBlobBegin);
    if(pbBlobEnd != NULL)
    {
        // Convert the string to a blob
        nError = LoadSingleBlob(&hs->CdnBuildKey, pbBlobBegin, pbBlobEnd);
        
        // Move to the next part
        if(pbBlobEnd[0] == _T('|'))
            pbBlobEnd++;
        pbBlobBegin = pbBlobEnd;
    }

    // Extract the CDN config hash
    pbBlobEnd = FindNextSeparator(pFileBlob, pbBlobBegin);
    if(pbBlobEnd != NULL)
    {
        // Convert the string to a blob
        nError = LoadSingleBlob(&hs->CdnConfigKey, pbBlobBegin, pbBlobEnd);
        
        // Move to the next part
        if(pbBlobEnd[0] == _T('|'))
            pbBlobEnd++;
        pbBlobBegin = pbBlobEnd;
    }

    // Skip the intermediate part
    pbBlobEnd = FindNextSeparator(pFileBlob, pbBlobBegin);
    if(pbBlobEnd != NULL)
    {
        // Move to the next part
        if(pbBlobEnd[0] == _T('|'))
            pbBlobEnd++;
        pbBlobBegin = pbBlobEnd;
    }

    // Extract the URL config hash
    pbBlobEnd = FindNextSeparator(pFileBlob, pbBlobBegin);
    if(pbBlobEnd != NULL)
    {
        // Convert the string to a blob
        hs->szUrlPath = NewStrFromAnsi(pbBlobBegin, pbBlobEnd);
    }

    // Verify all variables
    if(hs->CdnBuildKey.pbData == NULL || hs->CdnConfigKey.pbData == NULL || hs->szUrlPath == NULL)
        nError = ERROR_BAD_FORMAT;
    return nError;
}

static int LoadCdnConfigFile(TCascStorage * hs, PQUERY_KEY pFileBlob)
{
    LPBYTE pbLineBegin = pFileBlob->pbData;
    LPBYTE pbVarBegin;
    LPBYTE pbLineEnd = NULL;
    int nError;

    while(pbLineBegin != NULL)
    {
        // Get the next line
        if(!GetNextFileLine(pFileBlob, &pbLineBegin, &pbLineEnd))
            break;

        // Archive group
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "archive-group");
        if(pbVarBegin != NULL)
        {
            nError = LoadSingleBlob(&hs->ArchiveGroup, pbVarBegin, pbLineEnd);
            if(nError != ERROR_SUCCESS)
                return nError;
            continue;
        }

        // Archives
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "archives");
        if(pbVarBegin != NULL)
        {
            hs->pArchiveArray = LoadMultipleBlobs(pbVarBegin, pbLineEnd, &hs->ArchiveCount);
            if(hs->pArchiveArray == NULL || hs->ArchiveCount == 0)
                return ERROR_BAD_FORMAT;
            continue;
        }

        // Patch archive group
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "patch-archive-group");
        if(pbVarBegin != NULL)
        {
            LoadSingleBlob(&hs->PatchArchiveGroup, pbVarBegin, pbLineEnd);
            continue;
        }

        // Patch archives
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "patch-archives");
        if(pbVarBegin != NULL)
        {
            hs->pPatchArchiveArray = LoadMultipleBlobs(pbVarBegin, pbLineEnd, &hs->PatchArchiveCount);
            continue;
        }
    }

    // Check if all required fields are present
    if(hs->ArchiveGroup.pbData == NULL || hs->ArchiveGroup.cbData == 0 || hs->pArchiveArray == NULL || hs->ArchiveCount == 0)
        return ERROR_BAD_FORMAT;

    return ERROR_SUCCESS;
}

static int LoadCdnBuildFile(TCascStorage * hs, PQUERY_KEY pFileBlob)
{
    LPBYTE pbLineBegin = pFileBlob->pbData;
    LPBYTE pbVarBegin;
    LPBYTE pbLineEnd = NULL;

    while(pbLineBegin != NULL)
    {
        // Get the next line
        if(!GetNextFileLine(pFileBlob, &pbLineBegin, &pbLineEnd))
            break;

        // Game name
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "build-product");
        if(pbVarBegin != NULL)
        {
            GetGameType(hs, pbVarBegin, pbLineEnd);
            continue;
        }

        // Game build number
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "build-name");
        if(pbVarBegin != NULL)
        {
            GetBuildNumber(hs, pbVarBegin, pbLineEnd);
            continue;
        }

        // Root
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "root");
        if(pbVarBegin != NULL)
        {
            LoadSingleBlob(&hs->RootKey, pbVarBegin, pbLineEnd);
            continue;
        }

        // Patch
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "patch");
        if(pbVarBegin != NULL)
        {
            LoadSingleBlob(&hs->PatchKey, pbVarBegin, pbLineEnd);
            continue;
        }

        // Download
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "download");
        if(pbVarBegin != NULL)
        {
            LoadSingleBlob(&hs->DownloadKey, pbVarBegin, pbLineEnd);
            continue;
        }

        // Install
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "install");
        if(pbVarBegin != NULL)
        {
            LoadSingleBlob(&hs->InstallKey, pbVarBegin, pbLineEnd);
            continue;
        }

        // Encoding keys
        pbVarBegin = CheckLineVariable(pbLineBegin, pbLineEnd, "encoding");
        if(pbVarBegin != NULL)
        {
            hs->pEncodingKeys = LoadMultipleBlobs(pbVarBegin, pbLineEnd, &hs->EncodingKeys);
            if(hs->pEncodingKeys == NULL || hs->EncodingKeys != 2)
                return ERROR_BAD_FORMAT;

            hs->EncodingKey = hs->pEncodingKeys[0];
            hs->EncodingEKey = hs->pEncodingKeys[1];
            continue;
        }
    }

    // Check the encoding keys
    if(hs->pEncodingKeys == NULL || hs->EncodingKeys == 0)
        return ERROR_BAD_FORMAT;
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Public functions

int LoadBuildConfiguration(TCascStorage * hs)
{
    QUERY_KEY InfoFile = {NULL, 0};
    QUERY_KEY FileData = {NULL, 0};
    TCHAR * szAgentFile;
    TCHAR * szInfoFile;
    bool bBuildConfigComplete = false;
    int nError = ERROR_SUCCESS;

    // Since HOTS build 30027, the game uses build.info file for storage info
    if(bBuildConfigComplete == false)
    {
        szInfoFile = CombinePath(hs->szRootPath, _T(".build.info"));
        if(szInfoFile != NULL)
        {
            nError = LoadTextFile(szInfoFile, &InfoFile);
            if(nError == ERROR_SUCCESS)
            {
                // Parse the info file
                nError = ParseInfoFile(hs, &InfoFile);
                if(nError == ERROR_SUCCESS)
                    bBuildConfigComplete = true;
                
                // Free the loaded blob
                FreeCascBlob(&InfoFile);
            }

            CASC_FREE(szInfoFile);
        }
    }

    // If the info file has not been loaded, try the legacy .build.db
    if(bBuildConfigComplete == false)
    {
        szAgentFile = CombinePath(hs->szRootPath, _T(".build.db"));
        if(szAgentFile != NULL)
        {
            nError = LoadTextFile(szAgentFile, &FileData);
            if(nError == ERROR_SUCCESS)
            {
                nError = ParseAgentFile(hs, &FileData);
                if(nError == ERROR_SUCCESS)
                    bBuildConfigComplete = true;

                FreeCascBlob(&FileData);
            }
            CASC_FREE(szAgentFile);
        }
    }

    // If the .build.info and .build.db file hasn't been loaded, 
    if(nError == ERROR_SUCCESS && bBuildConfigComplete == false)
    {
        nError = ERROR_FILE_CORRUPT;
    }

    // Load the configuration file
    if(nError == ERROR_SUCCESS)
    {
        nError = FetchAndVerifyConfigFile(hs, &hs->CdnConfigKey, &FileData);
        if(nError == ERROR_SUCCESS)
        {
            nError = LoadCdnConfigFile(hs, &FileData);
            FreeCascBlob(&FileData);
        }
    }

    // Load the build file
    if(nError == ERROR_SUCCESS)
    {
        nError = FetchAndVerifyConfigFile(hs, &hs->CdnBuildKey, &FileData);
        if(nError == ERROR_SUCCESS)
        {
            nError = LoadCdnBuildFile(hs, &FileData);
            FreeCascBlob(&FileData);
        }
    }

    // Fill the index directory
    if(nError == ERROR_SUCCESS)
    {
        // First, check for more common "data" subdirectory
        if((hs->szIndexPath = CheckForIndexDirectory(hs, _T("data"))) != NULL)
            return ERROR_SUCCESS;

        // Second, try the "darch" subdirectory (older builds of HOTS - Alpha)
        if((hs->szIndexPath = CheckForIndexDirectory(hs, _T("darch"))) != NULL)
            return ERROR_SUCCESS;

        nError = ERROR_FILE_NOT_FOUND;
    }

    return nError;
}
