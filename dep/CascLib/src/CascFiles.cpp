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
// Local defines

typedef int (*PARSETEXTFILE)(TCascStorage * hs, void * pvListFile);
typedef int (*PARSECSVFILE)(TCascStorage * hs, CASC_CSV & Csv);
typedef int (*PARSE_VARIABLE)(TCascStorage * hs, const char * szVariableName, const char * szDataBegin, const char * szDataEnd, void * pvParam);

#define MAX_VAR_NAME 80

//-----------------------------------------------------------------------------
// Local structures

struct TBuildFileInfo
{
    const TCHAR * szFileName;
    CBLD_TYPE BuildFileType;
};

struct TGameLocaleString
{
    const char * szLocale;
    DWORD dwLocale;
};

static const TBuildFileInfo BuildTypes[] =
{
    {_T(".build.info"), CascBuildInfo},             // Since HOTS build 30027, the game uses .build.info file for storage info
    {_T(".build.db"),   CascBuildDb},               // Older CASC storages
    {_T("versions"),    CascVersionsDb},            // Older CASC storages
    {NULL, CascBuildNone}
};

static const TCHAR * DataDirs[] =
{
    _T("data") _T(PATH_SEP_STRING) _T("casc"),      // Overwatch
    _T("data"),                                     // TACT casc (for Linux systems)
    _T("Data"),                                     // World of Warcraft, Diablo
    _T("SC2Data"),                                  // Starcraft II (Legacy of the Void) build 38749
    _T("HeroesData"),                               // Heroes of the Storm
    _T("BNTData"),                                  // Heroes of the Storm, until build 30414
    NULL,
};

static const TGameLocaleString LocaleStrings[] = 
{
    {"enUS", CASC_LOCALE_ENUS},
    {"koKR", CASC_LOCALE_KOKR},
    {"frFR", CASC_LOCALE_FRFR},
    {"deDE", CASC_LOCALE_DEDE},
    {"zhCN", CASC_LOCALE_ZHCN},
    {"esES", CASC_LOCALE_ESES},
    {"zhTW", CASC_LOCALE_ZHTW},
    {"enGB", CASC_LOCALE_ENGB},
    {"enCN", CASC_LOCALE_ENCN},
    {"enTW", CASC_LOCALE_ENTW},
    {"esMX", CASC_LOCALE_ESMX},
    {"ruRU", CASC_LOCALE_RURU},
    {"ptBR", CASC_LOCALE_PTBR},
    {"itIT", CASC_LOCALE_ITIT},
    {"ptPT", CASC_LOCALE_PTPT},
    {NULL, 0}
};

//-----------------------------------------------------------------------------
// Local functions

static bool inline IsWhiteSpace(const char * szVarValue)
{
    return (0 <= szVarValue[0] && szVarValue[0] <= 0x20);
}

static bool inline IsValueSeparator(const char * szVarValue)
{
    return (IsWhiteSpace(szVarValue) || (szVarValue[0] == '|'));
}

static bool IsCharDigit(BYTE OneByte)
{
    return ('0' <= OneByte && OneByte <= '9');
}

static const char * CaptureDecimalInteger(const char * szDataPtr, const char * szDataEnd, PDWORD PtrValue)
{
    const char * szSaveDataPtr = szDataPtr;
    DWORD TotalValue = 0;
    DWORD AddValue = 0;

    // Skip all spaces
    while (szDataPtr < szDataEnd && szDataPtr[0] == ' ')
        szDataPtr++;

    // Load the number
    while (szDataPtr < szDataEnd && szDataPtr[0] != ' ')
    {
        // Must only contain decimal digits ('0' - '9')
        if (!IsCharDigit(szDataPtr[0]))
            break;

        // Get the next value and verify overflow
        AddValue = szDataPtr[0] - '0';
        if ((TotalValue + AddValue) < TotalValue)
            return NULL;

        TotalValue = (TotalValue * 10) + AddValue;
        szDataPtr++;
    }

    // If there were no decimal digits, we consider it failure
    if(szDataPtr == szSaveDataPtr)
        return NULL;

    // Give the result
    PtrValue[0] = TotalValue;
    return szDataPtr;
}

static const char * CaptureSingleString(const char * szDataPtr, const char * szDataEnd, char * szBuffer, size_t ccBuffer)
{
    char * szBufferEnd = szBuffer + ccBuffer - 1;

    // Skip all whitespaces
    while (szDataPtr < szDataEnd && IsWhiteSpace(szDataPtr))
        szDataPtr++;

    // Copy the string
    while (szDataPtr < szDataEnd && szBuffer < szBufferEnd && !IsWhiteSpace(szDataPtr) && szDataPtr[0] != '=')
        *szBuffer++ = *szDataPtr++;

    szBuffer[0] = 0;
    return szDataPtr;
}

static const char * CaptureSingleHash(const char * szDataPtr, const char * szDataEnd, LPBYTE HashValue, size_t HashLength)
{
    const char * szHashString;
    size_t HashStringLength = HashLength * 2;

    // Skip all whitespaces
    while (szDataPtr < szDataEnd && IsWhiteSpace(szDataPtr))
        szDataPtr++;
    szHashString = szDataPtr;

    // Count all hash characters
    for (size_t i = 0; i < HashStringLength; i++)
    {
        if (szDataPtr >= szDataEnd || isxdigit(szDataPtr[0]) == 0)
            return NULL;
        szDataPtr++;
    }

    // There must be a separator or end-of-string
    if (szDataPtr > szDataEnd || IsWhiteSpace(szDataPtr) == false)
        return NULL;

    // Give the values
    ConvertStringToBinary(szHashString, HashStringLength, HashValue);
    return szDataPtr;
}

static const char * CaptureHashCount(const char * szDataPtr, const char * szDataEnd, size_t * PtrHashCount)
{
    BYTE HashValue[MD5_HASH_SIZE];
    size_t HashCount = 0;

    // Capculate the hash count
    while (szDataPtr < szDataEnd)
    {
        // Check one hash
        szDataPtr = CaptureSingleHash(szDataPtr, szDataEnd, HashValue, MD5_HASH_SIZE);
        if (szDataPtr == NULL)
            return NULL;

        // Skip all whitespaces
        while (szDataPtr < szDataEnd && IsWhiteSpace(szDataPtr))
            szDataPtr++;

        HashCount++;
    }

    // Give results
    PtrHashCount[0] = HashCount;
    return szDataPtr;
}

static DWORD GetLocaleMask(const char * szTag)
{
    for(size_t i = 0; LocaleStrings[i].szLocale != NULL; i++)
    {
        if(!strncmp(LocaleStrings[i].szLocale, szTag, 4))
        {
            return LocaleStrings[i].dwLocale;
        }
    }

    return 0;
}

static bool CheckConfigFileVariable(
    TCascStorage * hs,                  // Pointer to storage structure
    const char * szLinePtr,             // Pointer to the begin of the line
    const char * szLineEnd,             // Pointer to the end of the line
    const char * szVarName,             // Pointer to the variable to check
    PARSE_VARIABLE PfnParseProc,        // Pointer to the parsing function
    void * pvParseParam)                // Pointer to the parameter passed to parsing function
{
    char szVariableName[MAX_VAR_NAME];

    // Capture the variable from the line
    szLinePtr = CaptureSingleString(szLinePtr, szLineEnd, szVariableName, sizeof(szVariableName));
    if (szLinePtr == NULL)
        return false;

    // Verify whether this is the variable
    if (!CascCheckWildCard(szVariableName, szVarName))
        return false;

    // Skip the spaces and '='
    while (szLinePtr < szLineEnd && (IsWhiteSpace(szLinePtr) || szLinePtr[0] == '='))
        szLinePtr++;

    // Call the parsing function only if there is some data
    if (szLinePtr >= szLineEnd)
        return false;

    return (PfnParseProc(hs, szVariableName, szLinePtr, szLineEnd, pvParseParam) == ERROR_SUCCESS);
}

static int LoadHashArray(
    PQUERY_KEY pBlob,
    const char * szLinePtr,
    const char * szLineEnd,
    size_t HashCount)
{
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the blob buffer
    pBlob->cbData = (DWORD)(HashCount * MD5_HASH_SIZE);
    pBlob->pbData = CASC_ALLOC(BYTE, pBlob->cbData);
    if (pBlob->pbData != NULL)
    {
        LPBYTE pbBuffer = pBlob->pbData;

        for (size_t i = 0; i < HashCount; i++)
        {
            // Capture the hash value
            szLinePtr = CaptureSingleHash(szLinePtr, szLineEnd, pbBuffer, MD5_HASH_SIZE);
            if (szLinePtr == NULL)
                return ERROR_BAD_FORMAT;

            // Move buffer
            pbBuffer += MD5_HASH_SIZE;
        }
        
        nError = ERROR_SUCCESS;
    }

    return nError;
}

static int LoadMultipleHashes(PQUERY_KEY pBlob, const char * szLineBegin, const char * szLineEnd)
{
    size_t HashCount = 0;
    int nError = ERROR_SUCCESS;

    // Retrieve the hash count
    if (CaptureHashCount(szLineBegin, szLineEnd, &HashCount) == NULL)
        return ERROR_BAD_FORMAT;

    // Do nothing if there is no data
    if(HashCount != 0)
    {
        nError = LoadHashArray(pBlob, szLineBegin, szLineEnd, HashCount);
    }

    return nError;
}

// Loads a query key from the text form
// A QueryKey is an array of "ContentKey EncodedKey1 ... EncodedKeyN"
static int LoadQueryKey(TCascStorage * /* hs */, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * pvParam)
{
    return LoadMultipleHashes((PQUERY_KEY)pvParam, szDataBegin, szDataEnd);
}

static int LoadCKeyEntry(TCascStorage * hs, const char * szVariableName, const char * szDataPtr, const char * szDataEnd, void * pvParam)
{
    PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)pvParam;
    size_t nLength = strlen(szVariableName);
    size_t HashCount = 0;

    // If the variable ends at "-size", it means we need to capture the size
    if((nLength > 5) && !strcmp(szVariableName + nLength - 5, "-size"))
    {
        DWORD ContentSize = CASC_INVALID_SIZE;
        DWORD EncodedSize = CASC_INVALID_SIZE;

        // Load the content size
        szDataPtr = CaptureDecimalInteger(szDataPtr, szDataEnd, &ContentSize);
        if(szDataPtr != NULL)
        {
            CaptureDecimalInteger(szDataPtr, szDataEnd, &EncodedSize);
            pCKeyEntry->ContentSize = ContentSize;
            pCKeyEntry->EncodedSize = EncodedSize;
            return ERROR_SUCCESS;
        }
    }
    else
    {
        // Get the number of hashes. It is expected to be 1 or 2
        if(CaptureHashCount(szDataPtr, szDataEnd, &HashCount) != NULL)
        {
            // Capture the CKey
            if(HashCount >= 1)
            {
                // Load the CKey. This should alway be there
                szDataPtr = CaptureSingleHash(szDataPtr, szDataEnd, pCKeyEntry->CKey, MD5_HASH_SIZE);
                if(szDataPtr == NULL)
                    return ERROR_BAD_FORMAT;
                pCKeyEntry->Flags |= CASC_CE_HAS_CKEY;
            }

            // Capture EKey, if any
            if(HashCount == 2)
            {
                // Load the EKey into the structure
                szDataPtr = CaptureSingleHash(szDataPtr, szDataEnd, pCKeyEntry->EKey, MD5_HASH_SIZE);
                if(szDataPtr == NULL)
                    return ERROR_BAD_FORMAT;
                pCKeyEntry->Flags |= CASC_CE_HAS_EKEY;

                // Increment the number of EKey entries loaded from text build file
                hs->EKeyEntries++;
            }

            return (HashCount == 1 || HashCount == 2) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
        }
    }

    // Unrecognized
    return ERROR_BAD_FORMAT;
}

static int LoadVfsRootEntry(TCascStorage * hs, const char * szVariableName, const char * szDataPtr, const char * szDataEnd, void * pvParam)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    CASC_ARRAY * pArray = (CASC_ARRAY *)pvParam;
    const char * szVarPtr = szVariableName;
    const char * szVarEnd = szVarPtr + strlen(szVarPtr);
    DWORD VfsRootIndex = CASC_INVALID_INDEX;

    // Skip the "vfs-" part
    if (!strncmp(szVariableName, "vfs-", 4))
    {
        // Then, there must be a decimal number as index
        if ((szVarPtr = CaptureDecimalInteger(szVarPtr + 4, szVarEnd, &VfsRootIndex)) != NULL)
        {
            // We expect the array to be initialized
            assert(pArray->IsInitialized());

            // The index of the key must not be NULL
            if(VfsRootIndex != 0)
            {
                // Make sure that he entry is in the array
                pCKeyEntry = (PCASC_CKEY_ENTRY)pArray->ItemAt(VfsRootIndex - 1);
                if(pCKeyEntry == NULL)
                {
                    // Insert a new entry
                    pCKeyEntry = (PCASC_CKEY_ENTRY)pArray->InsertAt(VfsRootIndex - 1);
                    if(pCKeyEntry == NULL)
                        return ERROR_NOT_ENOUGH_MEMORY;
                    
                    // Initialize the new entry
                    pCKeyEntry->Init();
                }

                // Call just a normal parse function
                return LoadCKeyEntry(hs, szVariableName, szDataPtr, szDataEnd, pCKeyEntry);
            }
        }
    }

    return ERROR_SUCCESS;
}

static int LoadBuildProductId(TCascStorage * hs, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * /* pvParam */)
{
    DWORD dwBuildUid = 0;

    // Convert up to 4 chars to DWORD
    for(size_t i = 0; i < 4 && szDataBegin < szDataEnd; i++)
    {
        dwBuildUid = (dwBuildUid << 0x08) | (BYTE)szDataBegin[0];
        szDataBegin++;
    }

    // Product-specific. See https://wowdev.wiki/TACT#Products
    switch(dwBuildUid)
    {
        case 0x00006433:    // 'd3'
        case 0x00643364:    // 'd3b': Diablo 3 Beta (2013) 
        case 0x6433636e:    // 'd3cn': Diablo 3 China
        case 0x00643374:    // 'd3t': Diablo 3 Test
            hs->szProductName = "Diablo 3";
            hs->Product = Diablo3;
            break;

        case 0x64737432:     // 'dst2':
            hs->szProductName = "Destiny 2";
            hs->Product = Destiny2;
            break;

        case 0x00626e74:    // 'bnt': Heroes of the Storm Alpha 
        case 0x6865726f:    // 'hero': Heroes of the Storm Retail
        case 0x73746f72:    // 'stor': Heroes of the Storm (deprecated)
            hs->szProductName = "Heroes Of The Storm";
            hs->Product = HeroesOfTheStorm;
            break;

        case 0x0070726f:    // 'pro':
        case 0x70726f63:    // 'proc':
        case 0x70726f64:    // 'prod': "prodev": Overwatch Dev
        case 0x70726f65:    // 'proe': Not on public CDNs
        case 0x70726f74:    // 'prot': Overwatch Test
        case 0x70726f76:    // 'prov': Overwatch Vendor
        case 0x70726f6d:    // 'prom': "proms": Overwatch World Cup Viewer
            hs->szProductName = "Overwatch";
            hs->Product = Overwatch;
            break;

        case 0x00007331:    // 's1': StarCraft 1
        case 0x00733161:    // 's1a': Starcraft 1 Alpha
        case 0x00733174:    // 's1t': StarCraft 1 Test
            hs->szProductName = "Starcraft 1";
            hs->Product = StarCraft1;
            break;

        case 0x00007332:    // 's2': StarCraft 2
        case 0x00733262:    // 's2b': Starcraft 2 Beta
        case 0x00733274:    // 's2t': StarCraft 2 Test
        case 0x00736332:    // 'sc2': StarCraft 2 (deprecated)
            hs->szProductName = "Starcraft 2";
            hs->Product = StarCraft2;
            break;

        case 0x76697065:    // "viper", "viperdev", "viperv1": Call of Duty Black Ops 4
            hs->szProductName = "Call Of Duty Black Ops 4";
            hs->Product = CallOfDutyBlackOps4;
            break;

        case 0x00007733:    // 'w3': Warcraft III
        case 0x00773374:    // 'w3t': Warcraft III Public Test
        case 0x77617233:    // 'war3': Warcraft III (old)
            hs->szProductName = "WarCraft 3";
            hs->Product = WarCraft3;
            break;

        case 0x00776f77:    // 'wow': World of Warcraft
        case 0x776f775f:    // "wow_beta", "wow_classic", "wow_classic_beta"
        case 0x776f7764:    // "wowdev", "wowdemo"
        case 0x776f7765:    // "wowe1", "wowe3", "wowe3"
        case 0x776f7774:    // 'wowt': World of Warcraft Test
        case 0x776f7776:    // 'wowv': World of Warcraft Vendor
        case 0x776f777a:    // 'wowz': World of Warcraft Submission (previously Vendor)
            hs->szProductName = "World Of Warcraft";
            hs->Product = WorldOfWarcraft;
            break;

        default:
            hs->szProductName = "Unknown Product";
            hs->Product = UnknownProduct;
            break;
    }

    return ERROR_SUCCESS;
}

// "B29049"
// "WOW-18125patch6.0.1"
// "30013_Win32_2_2_0_Ptr_ptr"
// "prometheus-0_8_0_0-24919"
static int LoadBuildNumber(TCascStorage * hs, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * /* pvParam */)
{
    DWORD dwBuildNumber = 0;
    DWORD dwMaxValue = 0;

    // Parse the string and take the largest decimal numeric value
    // "build-name = 1.21.5.4037-retail"
    while(szDataBegin < szDataEnd)
    {
        // There must be at least three digits (build 99 anyone?)
        if(IsCharDigit(szDataBegin[0]))
        {
            dwBuildNumber = (dwBuildNumber * 10) + (szDataBegin[0] - '0');
            dwMaxValue = CASCLIB_MAX(dwBuildNumber, dwMaxValue);
        }
        else
        {
            // Reset build number when we find non-digit char
            dwBuildNumber = 0;
        }

        // Move to the next
        szDataBegin++;
    }

    // If not there, just take value from build file
    if((hs->dwBuildNumber = dwMaxValue) == 0)
        hs->dwBuildNumber = hs->CdnBuildKey.pbData[0] % 100;
    return ERROR_BAD_FORMAT;
}

static int LoadQueryKey(const CASC_CSV_COLUMN & Column, QUERY_KEY & Key)
{
    // Check the input data
    if (Column.szValue == NULL)
        return ERROR_BUFFER_OVERFLOW;
    if (Column.nLength != MD5_STRING_SIZE)
        return ERROR_BAD_FORMAT;

    return LoadHashArray(&Key, Column.szValue, Column.szValue + Column.nLength, 1);
}

static int GetDefaultLocaleMask(TCascStorage * hs, const CASC_CSV_COLUMN & Column)
{
    const char * szTagEnd = Column.szValue + Column.nLength;
    const char * szTagPtr = Column.szValue;
    DWORD dwLocaleMask = 0;

    while(szTagPtr < szTagEnd)
    {
        // Could this be a locale string?
        if((szTagPtr + 4) <= szTagEnd && (szTagPtr[4] == ',' ||  szTagPtr[4] == ' '))
        {
            // Check whether the current tag is a language identifier
            dwLocaleMask = dwLocaleMask | GetLocaleMask(szTagPtr);
            szTagPtr += 4;
        }
        else
        {
            szTagPtr++;
        }
    }

    hs->dwDefaultLocale = dwLocaleMask;
    return ERROR_SUCCESS;
}

static int ParseFile_CDNS(TCascStorage * hs, CASC_CSV & Csv)
{
    const char * szWantedRegion = hs->szRegion;
    TCHAR szCdnServers[MAX_PATH];
    TCHAR szCdnPath[MAX_PATH];
    size_t nLineCount;

    // Fix the region
    if(szWantedRegion == NULL || !_stricmp(szWantedRegion, "beta") || !_stricmp(szWantedRegion, "xx"))
        szWantedRegion = "us";

    // Determine the row count
    nLineCount = Csv.GetLineCount();

    // Find the active config
    for (size_t i = 0; i < nLineCount; i++)
    {
        // Is it the version we are looking for?
        if(!strcmp(Csv[i]["Name!STRING:0"].szValue, szWantedRegion))
        {
            // Save the list of CDN servers
            CascStrCopy(szCdnServers, _countof(szCdnServers), Csv[i]["Hosts!STRING:0"].szValue);
            hs->szCdnServers = CascNewStr(szCdnServers);

            // Save the CDN subpath
            CascStrCopy(szCdnPath, _countof(szCdnPath), Csv[i]["Path!STRING:0"].szValue);
            hs->szCdnPath = CascNewStr(szCdnPath);

            // Check and return result
            return (hs->szCdnServers && hs->szCdnPath) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
        }
    }

    return ERROR_FILE_NOT_FOUND;
}

static int ParseFile_BuildInfo(TCascStorage * hs, CASC_CSV & Csv)
{
    size_t nLineCount = Csv.GetLineCount();
    int nError;

    // Find the active config
    for(size_t i = 0; i < nLineCount; i++)
    {
        // Is that build config active?
        if (!strcmp(Csv[i]["Active!DEC:1"].szValue, "1"))
        {
            // Extract the CDN build key
            nError = LoadQueryKey(Csv[i]["Build Key!HEX:16"], hs->CdnBuildKey);
            if (nError != ERROR_SUCCESS)
                return nError;

            // Extract the CDN config key
            nError = LoadQueryKey(Csv[i]["CDN Key!HEX:16"], hs->CdnConfigKey);
            if (nError != ERROR_SUCCESS)
                return nError;

            // If we found tags, we can extract language build from it
            GetDefaultLocaleMask(hs, Csv[i]["Tags!STRING:0"]);

            // If we found version, extract a build number
            const CASC_CSV_COLUMN & VerColumn = Csv[i]["Version!STRING:0"];
            if(VerColumn.szValue && VerColumn.nLength)
            {
                LoadBuildNumber(hs, NULL, VerColumn.szValue, VerColumn.szValue + VerColumn.nLength, NULL);
            }

            // Verify all variables
            return (hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
        }
    }

    return ERROR_FILE_NOT_FOUND;
}

static int ParseFile_VersionsDb(TCascStorage * hs, CASC_CSV & Csv)
{
    size_t nLineCount = Csv.GetLineCount();
    int nError;

    // Find the active config
    for (size_t i = 0; i < nLineCount; i++)
    {
        // Either take the version required or take the first one
        if (hs->szRegion == NULL || !strcmp(Csv[i]["Region!STRING:0"].szValue, hs->szRegion))
        {
            // Extract the CDN build key
            nError = LoadQueryKey(Csv[i]["BuildConfig!HEX:16"], hs->CdnBuildKey);
            if (nError != ERROR_SUCCESS)
                return nError;

            // Extract the CDN config key
            nError = LoadQueryKey(Csv[i]["CDNConfig!HEX:16"], hs->CdnConfigKey);
            if (nError != ERROR_SUCCESS)
                return nError;

            const CASC_CSV_COLUMN & VerColumn = Csv[i]["VersionsName!String:0"];
            if (VerColumn.szValue && VerColumn.nLength)
            {
                LoadBuildNumber(hs, NULL, VerColumn.szValue, VerColumn.szValue + VerColumn.nLength, NULL);
            }

            // Verify all variables
            return (hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
        }
    }

    return ERROR_FILE_NOT_FOUND;
}

static int ParseFile_BuildDb(TCascStorage * hs, CASC_CSV & Csv)
{
    int nError;

    // Extract the CDN build key
    nError = LoadQueryKey(Csv[CSV_ZERO][CSV_ZERO], hs->CdnBuildKey);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Extract the CDN config key
    nError = LoadQueryKey(Csv[CSV_ZERO][1], hs->CdnConfigKey);
    if (nError != ERROR_SUCCESS)
        return nError;

    // Load the the tags
    GetDefaultLocaleMask(hs, Csv[CSV_ZERO][2]);

    // Verify all variables
    return (hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static int ParseFile_CdnConfig(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szLineEnd;
    int nError = ERROR_SUCCESS;

    // Keep parsing the listfile while there is something in there
    for(;;)
    {
        // Get the next line
        if(!ListFile_GetNextLine(pvListFile, &szLineBegin, &szLineEnd))
            break;

        // CDN key of ARCHIVE-GROUP. Archive-group is actually a very special '.index' file.
        // It is essentially a merger of all .index files, with a structure change
        // When ".index" added after the ARCHIVE-GROUP, we get file name in "indices" folder
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "archive-group", LoadQueryKey, &hs->ArchiveGroup))
            continue;

        // CDN key of all archives. When ".index" added to the string, we get file name in "indices" folder
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "archives", LoadQueryKey, &hs->ArchivesKey))
            continue;

        // CDN keys of patch archives (needs research) 
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "patch-archives", LoadQueryKey, &hs->PatchArchivesKey))
            continue;

        // CDN key of probably the combined patch index file (needs research)
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "patch-archive-group", LoadQueryKey, &hs->PatchArchivesGroup))
            continue;

        // List of build configs this config supports (optional)
        // Points to file: "data\config\%02X\%02X\%s
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "builds", LoadQueryKey, &hs->BuildFiles))
            continue;
    }

    // Check if all required fields are present
    if(hs->ArchivesKey.pbData == NULL || hs->ArchivesKey.cbData == 0)
        return ERROR_BAD_FORMAT;

    return nError;
}

static int ParseFile_CdnBuild(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szLineEnd = NULL;
    int nError;

    // Initialize the empty VFS array
    nError = hs->VfsRootList.Create<CASC_CKEY_ENTRY>(0x10);
    if (nError != ERROR_SUCCESS)
        return nError;

    // Parse all variables
    while(ListFile_GetNextLine(pvListFile, &szLineBegin, &szLineEnd) != 0)
    {
        // Product name and build name
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "build-uid", LoadBuildProductId, NULL))
            continue;
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "build-name", LoadBuildNumber, NULL))
            continue;

        // Content key of the ROOT file. Look this up in ENCODING to get the encoded key
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "root*", LoadCKeyEntry, &hs->RootFile))
            continue;

        // Content key [+ encoded key] of the INSTALL file
        // If EKey is absent, you need to query the ENCODING file for it
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "install*", LoadCKeyEntry, &hs->InstallCKey))
            continue;

        // Content key [+ encoded key] of the DOWNLOAD file
        // If EKey is absent, you need to query the ENCODING file for it
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "download*", LoadCKeyEntry, &hs->DownloadCKey))
            continue;

        // Content key + encoded key of the ENCODING file. Contains CKey+EKey
        // If either none or 1 is found, the game (at least Wow) switches to plain-data(?). Seen in build 20173 
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "encoding*", LoadCKeyEntry, &hs->EncodingCKey))
            continue;

        // PATCH file
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "patch*", LoadCKeyEntry, &hs->PatchFile))
            continue;

        // SIZE file
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "size*", LoadCKeyEntry, &hs->SizeFile))
            continue;

        // VFS root file (the root file of the storage VFS)
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "vfs-root*", LoadCKeyEntry, &hs->VfsRoot))
            continue;

        // Load a directory entry to the VFS
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "vfs-*", LoadVfsRootEntry, &hs->VfsRootList))
            continue;
    }

    // Special case: Some builds of WoW (22267) don't have the variable in the build file
    if(hs->szProductName == NULL || hs->Product == UnknownProduct)
    {
        if(hs->szCdnPath != NULL)
        {
            TCHAR * szPlainName = (TCHAR *)GetPlainFileName(hs->szCdnPath);

            if(szPlainName[0] == 'w' && szPlainName[1] == 'o' && szPlainName[2] == 'w')
            {
                hs->szProductName = "World Of Warcraft";
                hs->Product = WorldOfWarcraft;
            }
        }
    }

    // Both CKey and EKey of ENCODING file is required
    if((hs->EncodingCKey.Flags & (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY)) != (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY))
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
                hs->szRootPath = CascNewStr(szDirectory);
                hs->szDataPath = szDataPath;
                return ERROR_SUCCESS;
            }

            // Free the data path
            CASC_FREE(szDataPath);
        }
    }

    return nError;
}

static int LoadCsvFile(TCascStorage * hs, const TCHAR * szFileName, PARSECSVFILE PfnParseProc, bool bHasHeader)
{
    CASC_CSV Csv(0x40, bHasHeader);
    int nError = Csv.Load(szFileName);

    // Load the external file to memory
    if (nError == ERROR_SUCCESS)
        nError = PfnParseProc(hs, Csv);
    return nError;
}

static const TCHAR * ExtractCdnServerName(TCHAR * szServerName, size_t cchServerName, const TCHAR * szCdnServers)
{
    const TCHAR * szSeparator;

    if(szCdnServers[0] != 0)
    {
        szSeparator = _tcschr(szCdnServers, _T(' '));
        if(szSeparator != NULL)
        {
            // Copy one server name
            CascStrCopy(szServerName, cchServerName, szCdnServers, (szSeparator - szCdnServers));

            // Skip all separators
            while(szSeparator[0] == ' ' || szSeparator[0] == 0x09)
                szSeparator++;
            return szSeparator;
        }
        else
        {
            CascStrCopy(szServerName, MAX_PATH, szCdnServers);
            return szCdnServers + _tcslen(szCdnServers);
        }
    }

    return NULL;
}

static int ForcePathExist(const TCHAR * szFileName, bool bIsFileName)
{
    TCHAR * szLocalPath;
    size_t nIndex;
    bool bFirstSeparator = false;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Sanity checks
    if(szFileName && szFileName[0])
    {
        szLocalPath = CascNewStr(szFileName);
        if(szLocalPath != NULL)
        {
            // Get the end of search
            if(bIsFileName)
                CutLastPathPart(szLocalPath);

            // Check the entire path
            if(_taccess(szLocalPath, 0) != 0)
            {
                // Searth the entire path
                for(nIndex = 0; szLocalPath[nIndex] != 0; nIndex++)
                {
                    if(szLocalPath[nIndex] == '\\' || szLocalPath[nIndex] == '/')
                    {
                        // Cut the path and verify whether the folder/file exists
                        szLocalPath[nIndex] = 0;

                        // Skip the very first separator
                        if(bFirstSeparator == true)
                        {
                            // Is it there?
                            if(DirectoryExists(szLocalPath) == false && MakeDirectory(szLocalPath) == false)
                            {
                                nError = ERROR_PATH_NOT_FOUND;
                                break;
                            }
                        }

                        // Restore the character
                        szLocalPath[nIndex] = PATH_SEP_CHAR;
                        bFirstSeparator = true;
                        nError = ERROR_SUCCESS;
                    }
                }

                // Now check the final path
                if(DirectoryExists(szLocalPath) || MakeDirectory(szLocalPath))
                {
                    nError = ERROR_SUCCESS;
                }
            }
            else
            {
                nError = ERROR_SUCCESS;
            }

            CASC_FREE(szLocalPath);
        }
    }

    return nError;
}

static int DownloadFile(
    const TCHAR * szRemoteName,
    const TCHAR * szLocalName,
    PULONGLONG PtrByteOffset,
    DWORD cbReadSize,
    DWORD dwPortFlags)
{
    TFileStream * pRemStream;
    TFileStream * pLocStream;
    LPBYTE pbFileData;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Open the remote stream
    pRemStream = FileStream_OpenFile(szRemoteName, BASE_PROVIDER_HTTP | STREAM_PROVIDER_FLAT | dwPortFlags);
    if (pRemStream != NULL)
    {
        // Will we download the entire file or just a part of it?
        if (PtrByteOffset == NULL)
        {
            ULONGLONG FileSize = 0;

            // Retrieve the file size
            if (FileStream_GetSize(pRemStream, &FileSize) && 0 < FileSize && FileSize < 0x10000000)
            {
                // Cut the file size down to 32 bits
                cbReadSize = (DWORD)FileSize;
            }
        }

        // Shall we read something?
        if ((cbReadSize != 0) && (pbFileData = CASC_ALLOC(BYTE, cbReadSize)) != NULL)
        {
            // Read all required data from the remote file
            if (FileStream_Read(pRemStream, PtrByteOffset, pbFileData, cbReadSize))
            {
                pLocStream = FileStream_CreateFile(szLocalName, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
                if (pLocStream != NULL)
                {
                    if (FileStream_Write(pLocStream, NULL, pbFileData, cbReadSize))
                        nError = ERROR_SUCCESS;

                    FileStream_Close(pLocStream);
                }
            }

            // Free the data buffer
            CASC_FREE(pbFileData);
        }

        // Close the remote stream
        FileStream_Close(pRemStream);
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

static int DownloadFile(
    TCascStorage * hs,
    const TCHAR * szServerName,
    const TCHAR * szServerPath1,
    const TCHAR * szServerPath2,
    const TCHAR * szLocalPath2,
    PULONGLONG PtrByteOffset,
    DWORD cbReadSize,
    TCHAR * szOutLocalPath,
    size_t cchOutLocalPath,
    DWORD dwPortFlags,
    bool bAlwaysDownload,
    bool bWowClassicRedirect)
{
    TCHAR szRemotePath[MAX_PATH];
    TCHAR szLocalPath[MAX_PATH];
    size_t nLength;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Format the target URL
    if(bWowClassicRedirect && !_tcsicmp(szServerPath1, _T("wow_classic_beta")))
        szServerPath1 = _T("wow");
    if (szLocalPath2 == NULL)
        szLocalPath2 = szServerPath2;

    // Create remote path
    CombineUrlPath(szRemotePath, _countof(szRemotePath), szServerName, szServerPath1, szServerPath2);
    CombineFilePath(szLocalPath, _countof(szLocalPath), hs->szRootPath, NULL, szLocalPath2);

    // Make sure that the path exists
    ForcePathExist(szLocalPath, true);

    // If we are not forced to download a new one, try if local file exists.
    if ((bAlwaysDownload == false) && (_taccess(szLocalPath, 0) == 0))
    {
        nError = ERROR_SUCCESS;
    }
    else
    {
        nError = DownloadFile(szRemotePath, szLocalPath, PtrByteOffset, cbReadSize, dwPortFlags);
    }

    // If succeeded, give the local path
    if(nError == ERROR_SUCCESS)
    {
        // If the caller wanted local path, give it to him
        if (szOutLocalPath && cchOutLocalPath)
        {
            nLength = _tcslen(szLocalPath);
            if ((nLength + 1) <= cchOutLocalPath)
            {
                CascStrCopy(szOutLocalPath, cchOutLocalPath, szLocalPath);
            }
        }
    }

    return nError;
}

static int FetchAndLoadConfigFile(TCascStorage * hs, PQUERY_KEY pFileKey, PARSETEXTFILE PfnParseProc)
{
    const TCHAR * szPathType = _T("config");
    TCHAR szLocalPath[MAX_PATH];
    TCHAR szSubDir[0x80] = _T("");
    void * pvListFile = NULL;
    int nError = ERROR_CAN_NOT_COMPLETE;

    // If online storage, we download the file. Otherwise, create a local path
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        nError = DownloadFileFromCDN(hs, szPathType, pFileKey->pbData, NULL, szLocalPath, _countof(szLocalPath));
        if(nError != ERROR_SUCCESS)
            return nError;
    }
    else
    {
        CreateCascSubdirectoryName(szSubDir, _countof(szSubDir), szPathType, NULL, pFileKey->pbData);
        CombineFilePath(szLocalPath, _countof(szLocalPath), hs->szDataPath, szSubDir);
    }

    // Load and verify the external listfile
    pvListFile = ListFile_OpenExternal(szLocalPath);
    if (pvListFile != NULL)
    {
        if (ListFile_VerifyMD5(pvListFile, pFileKey->pbData))
        {
            nError = PfnParseProc(hs, pvListFile);
        }
        else
        {
            nError = ERROR_FILE_CORRUPT;
        }
        CASC_FREE(pvListFile);
    }
    else
    {
        nError = ERROR_FILE_NOT_FOUND;
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Public functions

int DownloadFileFromCDN(TCascStorage * hs, const TCHAR * szSubDir, LPBYTE pbEKey, const TCHAR * szExtension, TCHAR * szOutLocalPath, size_t cchOutLocalPath)
{
    PCASC_ARCINDEX_ENTRY pIndexEntry;
    const TCHAR * szCdnServers = hs->szCdnServers;
    TCHAR szRemoteFolder[MAX_PATH];
    TCHAR szLocalFolder[MAX_PATH];
    TCHAR szServerName[MAX_PATH];
    int nError = ERROR_CAN_NOT_COMPLETE;

    // Try all download servers
    while((szCdnServers = ExtractCdnServerName(szServerName, _countof(szServerName), szCdnServers)) != NULL)
    {
        // Create the local subdirectory
        CreateCascSubdirectoryName(szLocalFolder, _countof(szLocalFolder), szSubDir, szExtension, pbEKey);

        // If the EKey is in an archive, we need to change the source
        if ((pIndexEntry = (PCASC_ARCINDEX_ENTRY)hs->ArcIndexMap.FindObject(pbEKey)) != NULL)
        {
            ULONGLONG ByteOffset;

            // Change the subpath to an archive
            CreateCascSubdirectoryName(szRemoteFolder, _countof(szRemoteFolder), szSubDir, szExtension, pIndexEntry->IndexHash);
            ByteOffset = pIndexEntry->ArchiveOffset;
            nError = DownloadFile(hs,
                                  szServerName,
                                  hs->szCdnPath,
                                  szRemoteFolder,
                                  szLocalFolder,
                                 &ByteOffset,
                                  pIndexEntry->EncodedSize,
                                  szOutLocalPath,
                                  cchOutLocalPath, 0, false, false);
        }
        else
        {
            nError = DownloadFile(hs,
                                  szServerName,
                                  hs->szCdnPath,
                                  szLocalFolder,
                                  szLocalFolder,
                                  NULL,
                                  0,
                                  szOutLocalPath,
                                  cchOutLocalPath, 0, false, false);
        }

        if (nError == ERROR_SUCCESS)
            break;
    }

    return nError;
}

// Checks whether there is a ".build.info" or ".build.db".
// If yes, the function sets "szDataPath" and "szIndexPath"
// in the storage structure and returns ERROR_SUCCESS
int CheckGameDirectory(TCascStorage * hs, TCHAR * szDirectory)
{
    TFileStream * pStream;
    TCHAR * szBuildFile;
    int nError = ERROR_FILE_NOT_FOUND;

    // Try to find any of the root files used in the history
    for (size_t i = 0; BuildTypes[i].szFileName != NULL; i++)
    {
        // Create the full name of the .agent.db file
        szBuildFile = CombinePath(szDirectory, BuildTypes[i].szFileName);
        if (szBuildFile != NULL)
        {
            // Attempt to open the file
            pStream = FileStream_OpenFile(szBuildFile, STREAM_FLAG_READ_ONLY);
            if (pStream != NULL)
            {
                // Free the stream
                FileStream_Close(pStream);

                // Check for the data directory
                nError = CheckDataDirectory(hs, szDirectory);
                if (nError == ERROR_SUCCESS)
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

int LoadBuildInfo(TCascStorage * hs)
{
    PARSECSVFILE PfnParseProc = NULL;
    bool bHasHeader = true;
    int nError;

    // If the storage is online storage, we need to download "versions"
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        // Inform the user about loading the build.info/build.db/versions
        if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Downloading the \"versions\" file", NULL, 0, 0))
            return ERROR_CANCELLED;

        // Attempt to download the "versions" file
        nError = DownloadFile(hs, _T("us.patch.battle.net"), hs->szCodeName, _T("versions"), NULL, NULL, 0, NULL, 0, STREAM_FLAG_USE_PORT_1119, true, false);
        if(nError != ERROR_SUCCESS)
        {
            return nError;
        }
    }

    // We support either ".build.info" or ".build.db"
    switch (hs->BuildFileType)
    {
        case CascBuildInfo:
            PfnParseProc = ParseFile_BuildInfo;
            break;

        case CascVersionsDb:
            PfnParseProc = ParseFile_VersionsDb;
            break;

        case CascBuildDb:
            PfnParseProc = ParseFile_BuildDb;
            bHasHeader = false;
            break;

        default:
            return ERROR_NOT_SUPPORTED;
    }

    return LoadCsvFile(hs, hs->szBuildFile, PfnParseProc, bHasHeader);
}

int LoadCdnsInfo(TCascStorage * hs)
{
    TCHAR szLocalPath[MAX_PATH];
    int nError = ERROR_SUCCESS;

    // Sanity checks
    assert(hs->dwFeatures & CASC_FEATURE_ONLINE);

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Downloading the \"cdns\" file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Download file and parse it
    nError = DownloadFile(hs, _T("us.patch.battle.net"), hs->szCodeName, _T("cdns"), NULL, NULL, 0, szLocalPath, _countof(szLocalPath), STREAM_FLAG_USE_PORT_1119, false, true);
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadCsvFile(hs, szLocalPath, ParseFile_CDNS, true);
    }

    return nError;
}

int LoadCdnConfigFile(TCascStorage * hs)
{
    // The CKey for the CDN config should have been loaded already
    assert(hs->CdnConfigKey.pbData != NULL && hs->CdnConfigKey.cbData == MD5_HASH_SIZE);

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Downloading CDN config file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the CDN config file
    return FetchAndLoadConfigFile(hs, &hs->CdnConfigKey, ParseFile_CdnConfig);
}

int LoadCdnBuildFile(TCascStorage * hs)
{
    // The CKey for the CDN config should have been loaded already
    assert(hs->CdnBuildKey.pbData != NULL && hs->CdnBuildKey.cbData == MD5_HASH_SIZE);

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Downloading CDN build file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the CDN config file. Note that we don't
    // need it for anything, really, so we don't care if it fails
    return FetchAndLoadConfigFile(hs, &hs->CdnBuildKey, ParseFile_CdnBuild);
}
