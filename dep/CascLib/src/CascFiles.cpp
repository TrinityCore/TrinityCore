/*****************************************************************************/
/* CascFiles.cpp                          Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Various text file parsers                                                 */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascBuildCfg.cpp                */
/* 30.10.15  1.00  Lad  Renamed to CascFiles.cpp                             */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

typedef int (*PARSEINFOFILE)(TCascStorage * hs, void * pvListFile);

//-----------------------------------------------------------------------------
// Local structures

struct TBuildFileInfo
{
    const TCHAR * szFileName;
    CBLD_TYPE BuildFileType;
};

struct TGameIdString
{
    const char * szGameInfo;
    size_t cchGameInfo;
    DWORD dwGameInfo;
};

static const TBuildFileInfo BuildTypes[] =
{
    {_T(".build.info"), CascBuildInfo},             // Since HOTS build 30027, the game uses .build.info file for storage info
    {_T(".build.db"),   CascBuildDb},               // Older CASC storages
    {NULL, CascBuildNone}
};

static const TCHAR * DataDirs[] =
{
    _T("SC2Data"),                                  // Starcraft II (Legacy of the Void) build 38749
    _T("Data\\Casc"),                               // Overwatch
    _T("Data"),                                     // World of Warcraft, Diablo
    _T("HeroesData"),                               // Heroes of the Storm
    _T("BNTData"),                                  // Heroes of the Storm, until build 30414
    NULL,
};

static const TGameIdString GameIds[] =
{
    {"Hero",       0x04, CASC_GAME_HOTS},           // Alpha build of Heroes of the Storm
    {"WoW",        0x03, CASC_GAME_WOW6},           // Alpha build of World of Warcraft - Warlords of Draenor
    {"Diablo3",    0x07, CASC_GAME_DIABLO3},        // Diablo III BETA 2.2.0
    {"Prometheus", 0x0A, CASC_GAME_OVERWATCH},      // Overwatch BETA since build 24919
    {"SC2",        0x03, CASC_GAME_STARCRAFT2},     // Starcraft II - Legacy of the Void
    {"Starcraft1", 0x0A, CASC_GAME_STARCRAFT1},     // Starcraft 1 (remake)
    {NULL, 0, 0},
};

//-----------------------------------------------------------------------------
// Local functions

static bool inline IsValueSeparator(const char * szVarValue)
{
    return ((0 <= szVarValue[0] && szVarValue[0] <= 0x20) || (szVarValue[0] == '|'));
}

static bool IsCharDigit(BYTE OneByte)
{
    return ('0' <= OneByte && OneByte <= '9');
}

static DWORD GetLocaleMask(const char * szTag)
{
    if(!strcmp(szTag, "enUS"))
        return CASC_LOCALE_ENUS;

    if(!strcmp(szTag, "koKR"))
        return CASC_LOCALE_KOKR;

    if(!strcmp(szTag, "frFR"))
        return CASC_LOCALE_FRFR;

    if(!strcmp(szTag, "deDE"))
        return CASC_LOCALE_DEDE;

    if(!strcmp(szTag, "zhCN"))
        return CASC_LOCALE_ZHCN;

    if(!strcmp(szTag, "esES"))
        return CASC_LOCALE_ESES;

    if(!strcmp(szTag, "zhTW"))
        return CASC_LOCALE_ZHTW;

    if(!strcmp(szTag, "enGB"))
        return CASC_LOCALE_ENGB;

    if(!strcmp(szTag, "enCN"))
        return CASC_LOCALE_ENCN;

    if(!strcmp(szTag, "enTW"))
        return CASC_LOCALE_ENTW;

    if(!strcmp(szTag, "esMX"))
        return CASC_LOCALE_ESMX;

    if(!strcmp(szTag, "ruRU"))
        return CASC_LOCALE_RURU;

    if(!strcmp(szTag, "ptBR"))
        return CASC_LOCALE_PTBR;

    if(!strcmp(szTag, "itIT"))
        return CASC_LOCALE_ITIT;

    if(!strcmp(szTag, "ptPT"))
        return CASC_LOCALE_PTPT;

    return 0;
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

    CASC_FREE(szIndexPath);
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

static const char * CheckLineVariable(const char * szLineBegin, const char * szLineEnd, const char * szVarName)
{
    size_t nLineLength = (size_t)(szLineEnd - szLineBegin);
    size_t nNameLength = strlen(szVarName);

    // If the line longer than the variable name?
    if(nLineLength > nNameLength)
    {
        if(!_strnicmp((const char *)szLineBegin, szVarName, nNameLength))
        {
            // Skip the variable name
            szLineBegin += nNameLength;

            // Skip the separator(s)
            while(szLineBegin < szLineEnd && IsValueSeparator(szLineBegin))
                szLineBegin++;

            // Check if there is "="
            if(szLineBegin >= szLineEnd || szLineBegin[0] != '=')
                return NULL;
            szLineBegin++;

            // Skip the separator(s)
            while(szLineBegin < szLineEnd && IsValueSeparator(szLineBegin))
                szLineBegin++;

            // Check if there is "="
            if(szLineBegin >= szLineEnd)
                return NULL;

            // Return the begin of the variable
            return szLineBegin;
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
        pVarBlob->cbData = (DWORD)((szLinePtr - szLineBegin) / 2);
        return ConvertStringToBinary(szLineBegin, (size_t)(szLinePtr - szLineBegin), pVarBlob->pbData);
    }

    // Initialize the blob
    pVarBlob->pbData = CASC_ALLOC(BYTE, (szLinePtr - szLineBegin) + 1);
    pVarBlob->cbData = (DWORD)(szLinePtr - szLineBegin);

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
    size_t nLength = _tcslen(szFileName);

    // If there is no slash, append if
    if(nLength > 0 && szFileName[nLength - 1] != '\\' && szFileName[nLength - 1] != '/')
        szFileName[nLength++] = _T('/');

    // Get to the end of the file name
    szFileName = szFileName + nLength;

    // Append the "config" directory
    _tcscpy(szFileName, _T("config"));
    szFileName += 6;

    // Append the first level directory
    szFileName = AppendBlobText(szFileName, pFileKey->pbData, 1, _T('/'));
    szFileName = AppendBlobText(szFileName, pFileKey->pbData + 1, 1, _T('/'));
    szFileName = AppendBlobText(szFileName, pFileKey->pbData, pFileKey->cbData, _T('/'));
}

static DWORD GetBlobCount(const char * szLineBegin, const char * szLineEnd)
{
    DWORD dwBlobCount = 0;

    // Until we find an end of the line
    while(szLineBegin < szLineEnd)
    {
        // Skip the blob
        while(szLineBegin < szLineEnd && IsValueSeparator(szLineBegin) == false)
            szLineBegin++;

        // Increment the number of blobs
        dwBlobCount++;

        // Skip the separator
        while(szLineBegin < szLineEnd && IsValueSeparator(szLineBegin))
            szLineBegin++;
    }

    return dwBlobCount;
}

static int LoadBlobArray(
    PQUERY_KEY pBlob,
    const char * szLineBegin,
    const char * szLineEnd,
    DWORD dwMaxBlobs)
{
    LPBYTE pbBufferEnd = pBlob->pbData + pBlob->cbData;
    LPBYTE pbBuffer = pBlob->pbData;
    int nError = ERROR_SUCCESS;

    // Sanity check
    assert(pBlob->pbData != NULL);
    assert(pBlob->cbData != 0);

    // Until we find an end of the line
    while(szLineBegin < szLineEnd && dwMaxBlobs > 0)
    {
        const char * szBlobEnd = szLineBegin;

        // Find the end of the text blob
        while(szBlobEnd < szLineEnd && IsValueSeparator(szBlobEnd) == false)
            szBlobEnd++;

        // Verify the length of the found blob
        if((szBlobEnd - szLineBegin) != MD5_STRING_SIZE)
            return ERROR_BAD_FORMAT;

        // Verify if there is enough space in the buffer
        if((pbBufferEnd - pbBuffer) < MD5_HASH_SIZE)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Perform the conversion
        nError = ConvertStringToBinary(szLineBegin, MD5_STRING_SIZE, pbBuffer);
        if(nError != ERROR_SUCCESS)
            return nError;

        // Move pointers
        pbBuffer += MD5_HASH_SIZE;
        dwMaxBlobs--;

        // Skip the separator
        while(szBlobEnd < szLineEnd && IsValueSeparator(szBlobEnd))
            szBlobEnd++;
        szLineBegin = szBlobEnd;
    }

    return nError;
}

static int LoadMultipleBlobs(PQUERY_KEY pBlob, const char * szLineBegin, const char * szLineEnd, DWORD dwBlobCount)
{
    size_t nLength = (szLineEnd - szLineBegin);

    // We expect each blob to have length of the encoding key and one space between
    if(nLength > (dwBlobCount * MD5_STRING_SIZE) + ((dwBlobCount - 1) * sizeof(char)))
        return ERROR_INVALID_PARAMETER;

    // Allocate the blob buffer
    pBlob->pbData = CASC_ALLOC(BYTE, dwBlobCount * MD5_HASH_SIZE);
    if(pBlob->pbData == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Set the buffer size and load the blob array
    pBlob->cbData = dwBlobCount * MD5_HASH_SIZE;
    return LoadBlobArray(pBlob, szLineBegin, szLineEnd, dwBlobCount);
}

static int LoadMultipleBlobs(PQUERY_KEY pBlob, const char * szLineBegin, const char * szLineEnd)
{
    return LoadMultipleBlobs(pBlob, szLineBegin, szLineEnd, GetBlobCount(szLineBegin, szLineEnd));
}

static int LoadSingleBlob(PQUERY_KEY pBlob, const char * szLineBegin, const char * szLineEnd)
{
    return LoadMultipleBlobs(pBlob, szLineBegin, szLineEnd, 1);
}

static int GetGameType(TCascStorage * hs, const char * szVarBegin, const char * szLineEnd)
{
    // Go through all games that we support
    for(size_t i = 0; GameIds[i].szGameInfo != NULL; i++)
    {
        // Check the length of the variable
        if((size_t)(szLineEnd - szVarBegin) == GameIds[i].cchGameInfo)
        {
            // Check the string
            if(!_strnicmp(szVarBegin, GameIds[i].szGameInfo, GameIds[i].cchGameInfo))
            {
                hs->dwGameInfo = GameIds[i].dwGameInfo;
                return ERROR_SUCCESS;
            }
        }
    }

    // Unknown/unsupported game
    assert(false);
    return ERROR_BAD_FORMAT;
}

// "B29049"
// "WOW-18125patch6.0.1"
// "30013_Win32_2_2_0_Ptr_ptr"
// "prometheus-0_8_0_0-24919"
static int GetBuildNumber(TCascStorage * hs, const char * szVarBegin, const char * szLineEnd)
{
    DWORD dwBuildNumber = 0;

    // Skip all non-digit characters
    while(szVarBegin < szLineEnd)
    {
        // There must be at least three digits (build 99 anyone?)
        if(IsCharDigit(szVarBegin[0]) && IsCharDigit(szVarBegin[1]) && IsCharDigit(szVarBegin[2]))
        {
            // Convert the build number string to value
            while(szVarBegin < szLineEnd && IsCharDigit(szVarBegin[0]))
                dwBuildNumber = (dwBuildNumber * 10) + (*szVarBegin++ - '0');
            break;
        }

        // Move to the next
        szVarBegin++;
    }

    assert(dwBuildNumber != 0);
    hs->dwBuildNumber = dwBuildNumber;
    return (dwBuildNumber != 0) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static int GetDefaultLocaleMask(TCascStorage * hs, PQUERY_KEY pTagsString)
{
    char * szTagEnd = (char *)pTagsString->pbData + pTagsString->cbData;
    char * szTagPtr = (char *)pTagsString->pbData;
    char * szNext;
    DWORD dwLocaleMask = 0;

    while(szTagPtr < szTagEnd)
    {
        // Get the next part
        szNext = strchr(szTagPtr, ' ');
        if(szNext != NULL)
            *szNext++ = 0;

        // Check whether the current tag is a language identifier
        dwLocaleMask = dwLocaleMask | GetLocaleMask(szTagPtr);

        // Get the next part
        if(szNext == NULL)
            break;

        // Skip spaces
        while(szNext < szTagEnd && szNext[0] == ' ')
            szNext++;
        szTagPtr = szNext;
    }

    hs->dwDefaultLocale = dwLocaleMask;
    return ERROR_SUCCESS;
}

static void * FetchAndVerifyConfigFile(TCascStorage * hs, PQUERY_KEY pFileKey)
{
    TCHAR * szFileName;
    void * pvListFile = NULL;

    // Construct the local file name
    szFileName = CascNewStr(hs->szDataPath, 8 + 3 + 3 + 32);
    if(szFileName != NULL)
    {
        // Add the part where the config file path is
        AppendConfigFilePath(szFileName, pFileKey);

        // Load and verify the external listfile
        pvListFile = ListFile_OpenExternal(szFileName);
        if(pvListFile != NULL)
        {
            if(!ListFile_VerifyMD5(pvListFile, pFileKey->pbData))
            {
                ListFile_Free(pvListFile);
                pvListFile = NULL;
            }
        }

        // Free the file name
        CASC_FREE(szFileName);
    }

    return pvListFile;
}

static int ParseFile_BuildInfo(TCascStorage * hs, void * pvListFile)
{
    QUERY_KEY Active = {NULL, 0};
    QUERY_KEY TagString = {NULL, 0};
    QUERY_KEY CdnHost = {NULL, 0};
    QUERY_KEY CdnPath = {NULL, 0};
    const char * szLinePtr1;
    const char * szLineEnd1;
    const char * szLinePtr2;
    const char * szLineEnd2;
    size_t nLength1;
    size_t nLength2;
    int nError = ERROR_BAD_FORMAT;

    // Extract the first line, cotaining the headers
    nLength1 = ListFile_GetNextLine(pvListFile, &szLinePtr1, &szLineEnd1);
    if(nLength1 == 0)
        return ERROR_BAD_FORMAT;

    // Now parse the second and the next lines. We are looking for line
    // with "Active" set to 1
    for(;;)
    {
        // Read the next line
        nLength2 = ListFile_GetNextLine(pvListFile, &szLinePtr2, &szLineEnd2);
        if(nLength2 == 0)
            break;

        // Parse all variables
        while(szLinePtr1 < szLineEnd1)
        {
            // Check for variables we need
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "Active", "DEC"))
                LoadInfoVariable(&Active, szLinePtr2, szLineEnd2, false);
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "Build Key", "HEX"))
                LoadInfoVariable(&hs->CdnBuildKey, szLinePtr2, szLineEnd2, true);
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "CDN Key", "HEX"))
                LoadInfoVariable(&hs->CdnConfigKey, szLinePtr2, szLineEnd2, true);
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "CDN Hosts", "STRING"))
                LoadInfoVariable(&CdnHost, szLinePtr2, szLineEnd2, false);
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "CDN Path", "STRING"))
                LoadInfoVariable(&CdnPath, szLinePtr2, szLineEnd2, false);
            if(IsInfoVariable(szLinePtr1, szLineEnd1, "Tags", "STRING"))
                LoadInfoVariable(&TagString, szLinePtr2, szLineEnd2, false);

            // Move both line pointers
            szLinePtr1 = SkipInfoVariable(szLinePtr1, szLineEnd1);
            if(szLinePtr1 == NULL)
                break;

            szLinePtr2 = SkipInfoVariable(szLinePtr2, szLineEnd2);
            if(szLinePtr2 == NULL)
                break;
        }

        // Stop parsing if found active config
        if(Active.pbData != NULL && *Active.pbData == '1')
            break;

        // Free the blobs
        FreeCascBlob(&Active);
        FreeCascBlob(&hs->CdnBuildKey);
        FreeCascBlob(&hs->CdnConfigKey);
        FreeCascBlob(&CdnHost);
        FreeCascBlob(&CdnPath);
        FreeCascBlob(&TagString);

        // Rewind column names pointer back to start of line
        szLinePtr1 = szLineEnd1 - nLength1;
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

    // If we found tags, we can extract language build from it
    if(TagString.pbData != NULL)
        GetDefaultLocaleMask(hs, &TagString);

    FreeCascBlob(&CdnHost);
    FreeCascBlob(&CdnPath);
    FreeCascBlob(&TagString);
    FreeCascBlob(&Active);
    return nError;
}

static int ParseFile_BuildDb(TCascStorage * hs, void * pvListFile)
{
    const char * szLinePtr;
    const char * szLineEnd;
    char szOneLine[0x200];
    size_t nLength;
    int nError;

    // Load the single line from the text file
    nLength = ListFile_GetNextLine(pvListFile, szOneLine, _maxchars(szOneLine));
    if(nLength == 0)
        return ERROR_BAD_FORMAT;

    // Set the line range
    szLinePtr = szOneLine;
    szLineEnd = szOneLine + nLength;

    // Extract the CDN build key
    nError = LoadInfoVariable(&hs->CdnBuildKey, szLinePtr, szLineEnd, true);
    if(nError == ERROR_SUCCESS)
    {
        // Skip the variable
        szLinePtr = SkipInfoVariable(szLinePtr, szLineEnd);

        // Load the CDN config hash
        nError = LoadInfoVariable(&hs->CdnConfigKey, szLinePtr, szLineEnd, true);
        if(nError == ERROR_SUCCESS)
        {
            // Skip the variable
            szLinePtr = SkipInfoVariable(szLinePtr, szLineEnd);

            // Skip the Locale/OS/code variable
            szLinePtr = SkipInfoVariable(szLinePtr, szLineEnd);

            // Load the URL
            hs->szUrlPath = CascNewStrFromAnsi(szLinePtr, szLineEnd);
            if(hs->szUrlPath == NULL)
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Verify all variables
    if(hs->CdnBuildKey.pbData == NULL || hs->CdnConfigKey.pbData == NULL || hs->szUrlPath == NULL)
        nError = ERROR_BAD_FORMAT;
    return nError;
}

static int LoadCdnConfigFile(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szVarBegin;
    const char * szLineEnd;
    int nError = ERROR_SUCCESS;

    // Keep parsing the listfile while there is something in there
    for(;;)
    {
        // Get the next line
        if(!ListFile_GetNextLine(pvListFile, &szLineBegin, &szLineEnd))
            break;

        // Archive group
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "archive-group");
        if(szVarBegin != NULL)
        {
            nError = LoadSingleBlob(&hs->ArchivesGroup, szVarBegin, szLineEnd);
            continue;
        }

        // Archives
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "archives");
        if(szVarBegin != NULL)
        {
            nError = LoadMultipleBlobs(&hs->ArchivesKey, szVarBegin, szLineEnd);
            continue;
        }

        // Patch archive group
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "patch-archive-group");
        if(szVarBegin != NULL)
        {
            LoadSingleBlob(&hs->PatchArchivesGroup, szVarBegin, szLineEnd);
            continue;
        }

        // Patch archives
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "patch-archives");
        if(szVarBegin != NULL)
        {
            nError = LoadMultipleBlobs(&hs->PatchArchivesKey, szVarBegin, szLineEnd);
            continue;
        }
    }

    // Check if all required fields are present
    if(hs->ArchivesKey.pbData == NULL || hs->ArchivesKey.cbData == 0)
        return ERROR_BAD_FORMAT;

    return nError;
}

static int LoadCdnBuildFile(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szVarBegin;
    const char * szLineEnd = NULL;
    int nError = ERROR_SUCCESS;

    for(;;)
    {
        // Get the next line
        if(!ListFile_GetNextLine(pvListFile, &szLineBegin, &szLineEnd))
            break;

        // Game name
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "build-product");
        if(szVarBegin != NULL)
        {
            GetGameType(hs, szVarBegin, szLineEnd);
            continue;
        }

        // Game build number
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "build-name");
        if(szVarBegin != NULL)
        {
            GetBuildNumber(hs, szVarBegin, szLineEnd);
            continue;
        }

        // Root
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "root");
        if(szVarBegin != NULL)
        {
            LoadSingleBlob(&hs->RootKey, szVarBegin, szLineEnd);
            continue;
        }

        // Patch
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "patch");
        if(szVarBegin != NULL)
        {
            LoadSingleBlob(&hs->PatchKey, szVarBegin, szLineEnd);
            continue;
        }

        // Download
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "download");
        if(szVarBegin != NULL)
        {
            LoadSingleBlob(&hs->DownloadKey, szVarBegin, szLineEnd);
            continue;
        }

        // Install
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "install");
        if(szVarBegin != NULL)
        {
            LoadSingleBlob(&hs->InstallKey, szVarBegin, szLineEnd);
            continue;
        }

        // Encoding keys
        szVarBegin = CheckLineVariable(szLineBegin, szLineEnd, "encoding");
        if(szVarBegin != NULL)
        {
            nError = LoadMultipleBlobs(&hs->EncodingKey, szVarBegin, szLineEnd, 2);
            continue;
        }
    }

    // Check the encoding keys
    if(hs->EncodingKey.pbData == NULL || hs->EncodingKey.cbData != MD5_HASH_SIZE * 2)
        return ERROR_BAD_FORMAT;
    return nError;
}

static int CheckDataDirectory(TCascStorage * hs, TCHAR * szDirectory)
{
    TCHAR * szDataPath;
    int nError = ERROR_FILE_NOT_FOUND;

    // Try all known subdirectories
    for(size_t i = 0; DataDirs[i] != NULL; i++)
    {
        // Create the eventual data path
        szDataPath = CombinePath(szDirectory, DataDirs[i]);
        if(szDataPath != NULL)
        {
            // Does that directory exist?
            if(DirectoryExists(szDataPath))
            {
                hs->szDataPath = szDataPath;
                return ERROR_SUCCESS;
            }

            // Free the data path
            CASC_FREE(szDataPath);
        }
    }

    return nError;
}


//-----------------------------------------------------------------------------
// Public functions

int LoadBuildInfo(TCascStorage * hs)
{
    PARSEINFOFILE PfnParseProc = NULL;
    void * pvListFile;
    int nError = ERROR_SUCCESS;

    switch(hs->BuildFileType)
    {
        case CascBuildInfo:
            PfnParseProc = ParseFile_BuildInfo;
            break;

        case CascBuildDb:
            PfnParseProc = ParseFile_BuildDb;
            break;

        default:
            nError = ERROR_NOT_SUPPORTED;
            break;
    }

    // Parse the appropriate build file
    if(nError == ERROR_SUCCESS)
    {
        pvListFile = ListFile_OpenExternal(hs->szBuildFile);
        if(pvListFile != NULL)
        {
            // Parse the info file
            nError = PfnParseProc(hs, pvListFile);
            ListFile_Free(pvListFile);
        }
        else
            nError = ERROR_FILE_NOT_FOUND;
    }

    // If the .build.info OR .build.db file has been loaded,
    // proceed with loading the CDN config file and CDN build file
    if(nError == ERROR_SUCCESS)
    {
        // Load the configuration file. Note that we don't
        // need it for anything, really, so we don't care if it fails
        pvListFile = FetchAndVerifyConfigFile(hs, &hs->CdnConfigKey);
        if(pvListFile != NULL)
        {
            nError = LoadCdnConfigFile(hs, pvListFile);
            ListFile_Free(pvListFile);
        }
    }

    // Load the build file
    if(nError == ERROR_SUCCESS)
    {
        pvListFile = FetchAndVerifyConfigFile(hs, &hs->CdnBuildKey);
        if(pvListFile != NULL)
        {
            nError = LoadCdnBuildFile(hs, pvListFile);
            ListFile_Free(pvListFile);
        }
        else
            nError = ERROR_FILE_NOT_FOUND;
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

// Checks whether there is a ".build.info" or ".build.db".
// If yes, the function sets "szRootPath" and "szDataPath"
// in the storage structure and returns ERROR_SUCCESS
int CheckGameDirectory(TCascStorage * hs, TCHAR * szDirectory)
{
    TFileStream * pStream;
    TCHAR * szBuildFile;
    int nError = ERROR_FILE_NOT_FOUND;

    // Try to find any of the root files used in the history
    for(size_t i = 0; BuildTypes[i].szFileName != NULL; i++)
    {
        // Create the full name of the .agent.db file
        szBuildFile = CombinePath(szDirectory, BuildTypes[i].szFileName);
        if(szBuildFile != NULL)
        {
            // Attempt to open the file
            pStream = FileStream_OpenFile(szBuildFile, STREAM_FLAG_READ_ONLY);
            if(pStream != NULL)
            {
                // Free the stream
                FileStream_Close(pStream);

                // Check for the data directory
                nError = CheckDataDirectory(hs, szDirectory);
                if(nError == ERROR_SUCCESS)
                {
                    hs->szBuildFile = szBuildFile;
                    hs->BuildFileType = BuildTypes[i].BuildFileType;
                    return ERROR_SUCCESS;
                }
            }

            CASC_FREE(szBuildFile);
        }
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Helpers for a config files that have multiple variables separated by "|"
// The line structure is (Overwatch 24919): "#MD5|CHUNK_ID|FILENAME|INSTALLPATH"
// The line structure is (Overwatch 27759): "#MD5|CHUNK_ID|PRIORITY|MPRIORITY|FILENAME|INSTALLPATH"
// The line has all preceding spaces removed

// Retrieves the index of a variable from the initial line
int GetRootVariableIndex(const char * szLinePtr, const char * szLineEnd, const char * szVariableName, int * PtrIndex)
{
    size_t nLength = strlen(szVariableName);
    int nIndex = 0;
    
    while(szLinePtr < szLineEnd)
    {
        // Check the variable there
        if(!_strnicmp(szLinePtr, szVariableName, nLength))
        {
            // Does the length match?
            if(szLinePtr[nLength] == '|' || szLinePtr[nLength] == '0')
            {
                PtrIndex[0] = nIndex;
                return ERROR_SUCCESS;
            }
        }

        // Get the next variable
        szLinePtr = SkipInfoVariable(szLinePtr, szLineEnd);
        if(szLinePtr == NULL)
            break;
        nIndex++;
    }

    return ERROR_BAD_FORMAT;
}

// Parses single line from Overwatch.
int ParseRootFileLine(const char * szLinePtr, const char * szLineEnd, int nFileNameIndex, PQUERY_KEY PtrEncodingKey, char * szFileName, size_t nMaxChars)
{
    int nIndex = 0;
    int nError;

    // Extract the MD5 (aka encoding key)
    if(szLinePtr[MD5_STRING_SIZE] != '|')
        return ERROR_BAD_FORMAT;

    // Convert the encoding key to binary
    PtrEncodingKey->cbData = MD5_HASH_SIZE;
    nError = ConvertStringToBinary(szLinePtr, MD5_STRING_SIZE, PtrEncodingKey->pbData);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Skip the variable
    szLinePtr += MD5_STRING_SIZE + 1;
    nIndex = 1;

    // Skip the variables until we find the file name
    while(szLinePtr < szLineEnd && nIndex < nFileNameIndex)
    {
        if(szLinePtr[0] == '|')
            nIndex++;
        szLinePtr++;
    }

    // Extract the file name
    while(szLinePtr < szLineEnd && szLinePtr[0] != '|' && nMaxChars > 1)
    {
        *szFileName++ = *szLinePtr++;
        nMaxChars--;
    }

    *szFileName = 0;
    return ERROR_SUCCESS;
}
