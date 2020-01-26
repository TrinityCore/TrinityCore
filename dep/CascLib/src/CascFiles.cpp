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

typedef DWORD (*PARSECSVFILE)(TCascStorage * hs, CASC_CSV & Csv);
typedef DWORD (*PARSETEXTFILE)(TCascStorage * hs, void * pvListFile);
typedef DWORD (*PARSE_VARIABLE)(TCascStorage * hs, const char * szVariableName, const char * szDataBegin, const char * szDataEnd, void * pvParam);

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

static bool StringEndsWith(LPCSTR szString, size_t nLength, LPCSTR szSuffix, size_t nSuffixLength)
{
    return ((nLength > nSuffixLength) && !strcmp(szString + nLength - nSuffixLength, szSuffix));
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

static DWORD GetLocaleValue(LPCSTR szTag)
{
    DWORD Language = 0;

    // Convert the string language to integer
    Language = (Language << 0x08) | szTag[0];
    Language = (Language << 0x08) | szTag[1];
    Language = (Language << 0x08) | szTag[2];
    Language = (Language << 0x08) | szTag[3];

    // Language-specific action
    switch(Language)
    {
        case 0x656e5553: return CASC_LOCALE_ENUS;
        case 0x656e4742: return CASC_LOCALE_ENGB;
        case 0x656e434e: return CASC_LOCALE_ENCN;
        case 0x656e5457: return CASC_LOCALE_ENTW;
        case 0x65734553: return CASC_LOCALE_ESES;
        case 0x65734d58: return CASC_LOCALE_ESMX;
        case 0x70744252: return CASC_LOCALE_PTBR;
        case 0x70745054: return CASC_LOCALE_PTPT;
        case 0x7a68434e: return CASC_LOCALE_ZHCN;
        case 0x7a685457: return CASC_LOCALE_ZHTW;
        case 0x6b6f4b52: return CASC_LOCALE_KOKR;
        case 0x66724652: return CASC_LOCALE_FRFR;
        case 0x64654445: return CASC_LOCALE_DEDE;
        case 0x72755255: return CASC_LOCALE_RURU;
        case 0x69744954: return CASC_LOCALE_ITIT;
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

static DWORD LoadHashArray(
    PQUERY_KEY pBlob,
    const char * szLinePtr,
    const char * szLineEnd,
    size_t HashCount)
{
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the blob buffer
    pBlob->cbData = (DWORD)(HashCount * MD5_HASH_SIZE);
    pBlob->pbData = CASC_ALLOC<BYTE>(pBlob->cbData);
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
        
        dwErrCode = ERROR_SUCCESS;
    }

    return dwErrCode;
}

static DWORD LoadMultipleHashes(PQUERY_KEY pBlob, const char * szLineBegin, const char * szLineEnd)
{
    size_t HashCount = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Retrieve the hash count
    if (CaptureHashCount(szLineBegin, szLineEnd, &HashCount) == NULL)
        return ERROR_BAD_FORMAT;

    // Do nothing if there is no data
    if(HashCount != 0)
    {
        dwErrCode = LoadHashArray(pBlob, szLineBegin, szLineEnd, HashCount);
    }

    return dwErrCode;
}

// Loads a query key from the text form
// A QueryKey is an array of "ContentKey EncodedKey1 ... EncodedKeyN"
static DWORD LoadQueryKey(TCascStorage * /* hs */, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * pvParam)
{
    return LoadMultipleHashes((PQUERY_KEY)pvParam, szDataBegin, szDataEnd);
}

static DWORD LoadCKeyEntry(TCascStorage * hs, const char * szVariableName, const char * szDataPtr, const char * szDataEnd, void * pvParam)
{
    PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)pvParam;
    size_t nLength = strlen(szVariableName);
    size_t HashCount = 0;

    // Ignore "xxx-config" items
    if(StringEndsWith(szVariableName, nLength, "-config", 7))
        return ERROR_SUCCESS;

    // If the variable ends at "-size", it means we need to capture the size
    if(StringEndsWith(szVariableName, nLength, "-size", 5))
    {
        DWORD ContentSize = CASC_INVALID_SIZE;
        DWORD EncodedSize = CASC_INVALID_SIZE;

        // Load the content size
        szDataPtr = CaptureDecimalInteger(szDataPtr, szDataEnd, &ContentSize);
        if(szDataPtr == NULL)
            return ERROR_BAD_FORMAT;

        CaptureDecimalInteger(szDataPtr, szDataEnd, &EncodedSize);
        pCKeyEntry->ContentSize = ContentSize;
        pCKeyEntry->EncodedSize = EncodedSize;
        return ERROR_SUCCESS;
    }

    // If the string doesn't end with "-config", assume it's the CKey/EKey
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

// For files like PATCH, which only contain EKey in the build file
static DWORD LoadEKeyEntry(TCascStorage * hs, const char * szVariableName, const char * szDataPtr, const char * szDataEnd, void * pvParam)
{
    PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)pvParam;
    DWORD dwErrCode;

    // Load the entry as if it was a CKey. Then move CKey into EKey and adjust flags
    if((dwErrCode = LoadCKeyEntry(hs, szVariableName, szDataPtr, szDataEnd, pvParam)) == ERROR_SUCCESS)
    {
        if((pCKeyEntry->Flags & (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY | CASC_CE_HAS_EKEY_PARTIAL)) == CASC_CE_HAS_CKEY)
        {
            // Move the CKey into EKey
            CopyMemory16(pCKeyEntry->EKey, pCKeyEntry->CKey);
            ZeroMemory16(pCKeyEntry->CKey);

            // Adjust flags
            pCKeyEntry->Flags = (pCKeyEntry->Flags & ~CASC_CE_HAS_CKEY) | CASC_CE_HAS_EKEY;
        }
    }

    return dwErrCode;
}

static DWORD LoadVfsRootEntry(TCascStorage * hs, const char * szVariableName, const char * szDataPtr, const char * szDataEnd, void * pvParam)
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

static DWORD LoadBuildProductId(TCascStorage * hs, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * /* pvParam */)
{
    size_t nLength = (szDataEnd - szDataBegin);

    if(hs->szCodeName == NULL)
    {
        if((hs->szCodeName = CASC_ALLOC<TCHAR>(nLength + 1)) != NULL)
        {
            CascStrCopy(hs->szCodeName, nLength + 1, szDataBegin, nLength);
        }
    }

    return ERROR_SUCCESS;
}

// "B29049"
// "WOW-18125patch6.0.1"
// "30013_Win32_2_2_0_Ptr_ptr"
// "prometheus-0_8_0_0-24919"
static DWORD LoadBuildNumber(TCascStorage * hs, const char * /* szVariableName */, const char * szDataBegin, const char * szDataEnd, void * /* pvParam */)
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

static void SetProductCodeName(TCascStorage * hs, LPCSTR szCodeName)
{
    TCHAR szCodeNameT[0x40];

    if(hs->szCodeName == NULL && szCodeName != NULL)
    {
        CascStrCopy(szCodeNameT, _countof(szCodeNameT), szCodeName);
        hs->szCodeName = CascNewStr(szCodeNameT);
    }
}

static DWORD GetDefaultCdnPath(TCascStorage * hs, const CASC_CSV_COLUMN & Column)
{
    TCHAR szCdnPath[MAX_PATH];

    if(hs->szCdnPath == NULL && Column.nLength != 0)
    {
        CascStrCopy(szCdnPath, _countof(szCdnPath), Column.szValue);
        hs->szCdnPath = CascNewStr(szCdnPath);
    }

    return ERROR_SUCCESS;
}

static DWORD GetDefaultLocaleMask(TCascStorage * hs, const CASC_CSV_COLUMN & Column)
{
    LPCSTR szTagEnd = Column.szValue + Column.nLength - 4;
    LPCSTR szTagPtr = Column.szValue;
    DWORD dwLocaleMask = 0;

    while(szTagPtr < szTagEnd)
    {
        DWORD dwLocaleValue = GetLocaleValue(szTagPtr);

        if(dwLocaleValue != 0)
        {
            dwLocaleMask = dwLocaleMask | GetLocaleValue(szTagPtr);
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

static DWORD ParseFile_CDNS(TCascStorage * hs, CASC_CSV & Csv)
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

static DWORD ParseFile_BuildInfo(TCascStorage * hs, CASC_CSV & Csv)
{
    PFNPRODUCTCALLBACK PfnProductCallback = hs->pArgs->PfnProductCallback;
    LPCSTR szProductColumn = "Product!STRING:0";
    LPCSTR szCodeName;
    void * PtrProductParam = hs->pArgs->PtrProductParam;
    size_t nProductColumnIndex = Csv.GetColumnIndex(szProductColumn);
    size_t nLineCount = Csv.GetLineCount();
    size_t nSelected = CASC_INVALID_INDEX;
    DWORD dwErrCode;

    //
    // Find the configuration that we're gonna load.
    //

    // If the product is not specified and there is product callback, we use the callback to specify the product
    if(hs->szCodeName == NULL && nProductColumnIndex != CASC_INVALID_INDEX && PfnProductCallback != NULL)
    {
        LPCSTR ProductsList[0x40] = {NULL};
        size_t nProductCount = 0;
        size_t nChoiceIndex = CASC_INVALID_INDEX;
        size_t nDefault = CASC_INVALID_INDEX;

        // Load all products to the array
        for(size_t i = 0; i < nLineCount; i++)
        {
            // Ignore anything that is not marked "active"
            if(!strcmp(Csv[i]["Active!DEC:1"].szValue, "1"))
            {
                ProductsList[nProductCount] = Csv[i]["Product!STRING:0"].szValue;
                nProductCount++;
                nDefault = i;
            }
        }
        
        // Only if there is more than one active products
        if(nProductCount > 1)
        {
            // Ask the callback to choose the product
            if(!PfnProductCallback(PtrProductParam, ProductsList, nProductCount, &nChoiceIndex) || (nChoiceIndex >= nProductCount))
                return ERROR_CANCELLED;

            // We now have preferred product to open
            SetProductCodeName(hs, ProductsList[nChoiceIndex]);
        }
        else if(nProductCount == 1)
        {
            // We now have preferred product to open
            SetProductCodeName(hs, ProductsList[nDefault]);
        }
        else
        {
            return ERROR_FILE_NOT_FOUND;
        }
    }

    // Parse all lines in the CSV file. Either take the first that is active
    // or take the one that has been selected by the callback
    for(size_t i = 0; i < nLineCount; i++)
    {
        // Ignore anything that is not marked "active"
        if(!strcmp(Csv[i]["Active!DEC:1"].szValue, "1"))
        {
            // If the product code is specified and exists in the build file, we need to check it
            if(hs->szCodeName != NULL && (szCodeName = Csv[i]["Product!STRING:0"].szValue) != NULL)
            {
                TCHAR szBuffer[0x20];

                // Skip if they are not equal
                CascStrCopy(szBuffer, _countof(szBuffer), szCodeName);
                if(_tcsicmp(hs->szCodeName, szBuffer))
                    continue;

                // Save the code name of the selected product
                SetProductCodeName(hs, Csv[i]["Product!STRING:0"].szValue);
                nSelected = i;
                break;
            }

            // If the caller didn't specify the product code name, pick the first active
            nSelected = i;
            break;
        }
    }

    // Load the selected product
    if(nSelected < nLineCount)
    {
        // Extract the CDN build key
        dwErrCode = LoadQueryKey(Csv[nSelected]["Build Key!HEX:16"], hs->CdnBuildKey);
        if (dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Extract the CDN config key
        dwErrCode = LoadQueryKey(Csv[nSelected]["CDN Key!HEX:16"], hs->CdnConfigKey);
        if (dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Get the CDN path
        GetDefaultCdnPath(hs, Csv[nSelected]["CDN Path!STRING:0"]);

        // If we found tags, we can extract language build from it
        GetDefaultLocaleMask(hs, Csv[nSelected]["Tags!STRING:0"]);

        // If we found version, extract a build number
        const CASC_CSV_COLUMN & VerColumn = Csv[nSelected]["Version!STRING:0"];
        if(VerColumn.szValue && VerColumn.nLength)
        {
            LoadBuildNumber(hs, NULL, VerColumn.szValue, VerColumn.szValue + VerColumn.nLength, NULL);
        }

        // Verify all variables
        return (hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
    }

    return ERROR_FILE_NOT_FOUND;
}

static DWORD ParseFile_VersionsDb(TCascStorage * hs, CASC_CSV & Csv)
{
    size_t nLineCount = Csv.GetLineCount();
    DWORD dwErrCode;

    // Find the active config
    for (size_t i = 0; i < nLineCount; i++)
    {
        // Either take the version required or take the first one
        if (hs->szRegion == NULL || !strcmp(Csv[i]["Region!STRING:0"].szValue, hs->szRegion))
        {
            // Extract the CDN build key
            dwErrCode = LoadQueryKey(Csv[i]["BuildConfig!HEX:16"], hs->CdnBuildKey);
            if (dwErrCode != ERROR_SUCCESS)
                return dwErrCode;

            // Extract the CDN config key
            dwErrCode = LoadQueryKey(Csv[i]["CDNConfig!HEX:16"], hs->CdnConfigKey);
            if (dwErrCode != ERROR_SUCCESS)
                return dwErrCode;

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

static DWORD ParseFile_BuildDb(TCascStorage * hs, CASC_CSV & Csv)
{
    DWORD dwErrCode;

    // Extract the CDN build key
    dwErrCode = LoadQueryKey(Csv[CSV_ZERO][CSV_ZERO], hs->CdnBuildKey);
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Extract the CDN config key
    dwErrCode = LoadQueryKey(Csv[CSV_ZERO][1], hs->CdnConfigKey);
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Verify all variables
    return (hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static DWORD ParseFile_CdnConfig(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szLineEnd;
    DWORD dwErrCode = ERROR_SUCCESS;

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

    return dwErrCode;
}

static DWORD ParseFile_CdnBuild(TCascStorage * hs, void * pvListFile)
{
    const char * szLineBegin;
    const char * szLineEnd = NULL;
    DWORD dwErrCode;

    // Initialize the empty VFS array
    dwErrCode = hs->VfsRootList.Create<CASC_CKEY_ENTRY>(0x10);
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

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
        if(CheckConfigFileVariable(hs, szLineBegin, szLineEnd, "patch*", LoadEKeyEntry, &hs->PatchFile))
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
    if(hs->szCodeName == NULL && hs->szCdnPath != NULL)
    {
        hs->szCodeName = CascNewStr(GetPlainFileName(hs->szCdnPath));
    }

    // Both CKey and EKey of ENCODING file is required
    if((hs->EncodingCKey.Flags & (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY)) != (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY))
        dwErrCode = ERROR_BAD_FORMAT;
    return dwErrCode;
}

static DWORD CheckDataDirectory(TCascStorage * hs, TCHAR * szDirectory)
{
    TCHAR * szDataPath;
    DWORD dwErrCode = ERROR_FILE_NOT_FOUND;

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

    return dwErrCode;
}

static DWORD LoadCsvFile(TCascStorage * hs, const TCHAR * szFileName, PARSECSVFILE PfnParseProc, bool bHasHeader)
{
    CASC_CSV Csv(0x40, bHasHeader);
    DWORD dwErrCode;

    // Load the external file to memory
    if ((dwErrCode = Csv.Load(szFileName)) == ERROR_SUCCESS)
        dwErrCode = PfnParseProc(hs, Csv);
    return dwErrCode;
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

static void CreateRemoteAndLocalPath(TCascStorage * hs, CASC_CDN_DOWNLOAD & CdnsInfo, CASC_PATH<TCHAR> & RemotePath, CASC_PATH<TCHAR> & LocalPath)
{
    PCASC_EKEY_ENTRY pEKeyEntry;
    ULONGLONG ByteMask = 1;
    DWORD ArchiveIndex;

    // Append the CDN host / root folder
    RemotePath.SetPathRoot(CdnsInfo.szCdnsHost);
    RemotePath.AppendString(CdnsInfo.szCdnsPath, true);
    LocalPath.SetPathRoot(hs->szRootPath);

    // If there is an EKey, take EKey
    if(CdnsInfo.pbEKey != NULL)
    {
        // The file is given by EKey. It's either a loose file, or it's stored in an archive.
        // We check that using the EKey map
        if ((pEKeyEntry = (PCASC_EKEY_ENTRY)hs->IndexMap.FindObject(CdnsInfo.pbEKey)) != NULL)
        {
            // Change the path type to "data"
            RemotePath.AppendString(_T("data"), true);
            LocalPath.AppendString(_T("data"), true);

            // Append the EKey of the archive instead of the file itself
            ArchiveIndex = (DWORD)(pEKeyEntry->StorageOffset >> hs->FileOffsetBits);
            CdnsInfo.pbArchiveKey = hs->ArchivesKey.pbData + (MD5_HASH_SIZE * ArchiveIndex);
            RemotePath.AppendEKey(CdnsInfo.pbArchiveKey);
            LocalPath.AppendEKey(CdnsInfo.pbArchiveKey);

            // Get the archive index and archive offset
            CdnsInfo.ArchiveIndex = ArchiveIndex;
            CdnsInfo.ArchiveOffs = pEKeyEntry->StorageOffset & ((ByteMask << hs->FileOffsetBits) - 1);
            CdnsInfo.EncodedSize = pEKeyEntry->EncodedSize;
        }
        else
        {
            // Append the path type
            RemotePath.AppendString(CdnsInfo.szPathType, true);
            LocalPath.AppendString((CdnsInfo.szLoPaType != NULL) ? CdnsInfo.szLoPaType : CdnsInfo.szPathType, true);

            // Append the EKey
            RemotePath.AppendEKey(CdnsInfo.pbEKey);
            LocalPath.AppendEKey(CdnsInfo.pbEKey);
        }
    }
    else
    {
        assert(CdnsInfo.szFileName != NULL);
        RemotePath.AppendString(CdnsInfo.szFileName, true);
        LocalPath.AppendString(CdnsInfo.szFileName, true);
    }

    // Append extension
    RemotePath.AppendString(CdnsInfo.szExtension, false);
    LocalPath.AppendString(CdnsInfo.szExtension, false);
}

static DWORD ForcePathExist(const TCHAR * szFileName, bool bIsFileName)
{
    TCHAR * szLocalPath;
    size_t nIndex;
    bool bFirstSeparator = false;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

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
                                dwErrCode = ERROR_PATH_NOT_FOUND;
                                break;
                            }
                        }

                        // Restore the character
                        szLocalPath[nIndex] = PATH_SEP_CHAR;
                        bFirstSeparator = true;
                        dwErrCode = ERROR_SUCCESS;
                    }
                }

                // Now check the final path
                if(DirectoryExists(szLocalPath) || MakeDirectory(szLocalPath))
                {
                    dwErrCode = ERROR_SUCCESS;
                }
            }
            else
            {
                dwErrCode = ERROR_SUCCESS;
            }

            CASC_FREE(szLocalPath);
        }
    }

    return dwErrCode;
}

static DWORD DownloadFile(
    LPCTSTR szRemoteName,
    LPCTSTR szLocalName,
    PULONGLONG PtrByteOffset,
    DWORD cbReadSize,
    DWORD dwPortFlags)
{
    TFileStream * pRemStream;
    TFileStream * pLocStream;
    LPBYTE pbFileData;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Open the remote stream
    pRemStream = FileStream_OpenFile(szRemoteName, BASE_PROVIDER_HTTP | STREAM_PROVIDER_FLAT | dwPortFlags);
    if (pRemStream != NULL)
    {
        // Will we download the entire file or just a part of it?
        if (PtrByteOffset == NULL)
        {
            ULONGLONG FileSize = 0;

            // Retrieve the file size, but not longer than 1 GB
            if (FileStream_GetSize(pRemStream, &FileSize) && 0 < FileSize && FileSize < 0x40000000)
            {
                // Cut the file size down to 32 bits
                cbReadSize = (DWORD)FileSize;
            }
        }

        // Shall we read something?
        if ((cbReadSize != 0) && (pbFileData = CASC_ALLOC<BYTE>(cbReadSize)) != NULL)
        {
            // Read all required data from the remote file
            if (FileStream_Read(pRemStream, PtrByteOffset, pbFileData, cbReadSize))
            {
                pLocStream = FileStream_CreateFile(szLocalName, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
                if (pLocStream != NULL)
                {
                    if (FileStream_Write(pLocStream, NULL, pbFileData, cbReadSize))
                        dwErrCode = ERROR_SUCCESS;

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
        dwErrCode = GetLastError();
    }

    return dwErrCode;
}

static DWORD DownloadFileFromCDN2(TCascStorage * hs, CASC_CDN_DOWNLOAD & CdnsInfo)
{
    CASC_PATH<TCHAR> RemotePath(URL_SEP_CHAR);
    CASC_PATH<TCHAR> LocalPath(PATH_SEP_CHAR);
    DWORD dwPortFlags = (CdnsInfo.Flags & CASC_CDN_FLAG_PORT1119) ? STREAM_FLAG_USE_PORT_1119 : 0;
    DWORD dwErrCode;

    // Assemble both the remote and local path
    assert(CdnsInfo.szCdnsHost != NULL && CdnsInfo.szCdnsHost[0] != 0);
    CreateRemoteAndLocalPath(hs, CdnsInfo, RemotePath, LocalPath);

    // Check whether the local file exists
    if((CdnsInfo.Flags & CASC_CDN_FORCE_DOWNLOAD) || (_taccess(LocalPath, 0) == -1))
    {
        // Make sure that the path exists
        dwErrCode = ForcePathExist(LocalPath, true);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Attempt to download the file
        dwErrCode = DownloadFile(RemotePath, LocalPath, NULL, 0, dwPortFlags);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
    }

    // Give the path to the caller, if any
    LocalPath.Copy(CdnsInfo.szLocalPath, CdnsInfo.ccLocalPath);
    return ERROR_SUCCESS;
}

DWORD DownloadFileFromCDN(TCascStorage * hs, CASC_CDN_DOWNLOAD & CdnsInfo)
{
    LPCTSTR szCdnServers = hs->szCdnServers;
    TCHAR szCdnHost[MAX_PATH] = _T("");
    DWORD dwErrCode = ERROR_CAN_NOT_COMPLETE;

    // If we have a given CDN server, use it. If not, try all CDNs
    // from the storage's configuration
    if(CdnsInfo.szCdnsHost == NULL)
    {
        // Try all download servers
        while((szCdnServers = ExtractCdnServerName(szCdnHost, _countof(szCdnHost), szCdnServers)) != NULL)
        {
            CdnsInfo.szCdnsHost = szCdnHost;
            if((dwErrCode = DownloadFileFromCDN2(hs, CdnsInfo)) == ERROR_SUCCESS)
                return ERROR_SUCCESS;
        }
    }
    else
    {
        dwErrCode = DownloadFileFromCDN2(hs, CdnsInfo);
    }

    return dwErrCode;
}

static DWORD FetchAndLoadConfigFile(TCascStorage * hs, PQUERY_KEY pFileKey, PARSETEXTFILE PfnParseProc)
{
    LPCTSTR szPathType = _T("config");
    TCHAR szLocalPath[MAX_PATH];
    TCHAR szSubDir[0x80] = _T("");
    void * pvListFile = NULL;
    DWORD dwErrCode = ERROR_CAN_NOT_COMPLETE;

    // If online storage, we download the file. Otherwise, create a local path
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        CASC_CDN_DOWNLOAD CdnsInfo = {0};

        // Prepare the download structure for "%CDNS_HOST%/%CDNS_PATH%/##/##/EKey" file
        CdnsInfo.szCdnsPath = hs->szCdnPath;
        CdnsInfo.szPathType = szPathType;
        CdnsInfo.pbEKey = pFileKey->pbData;
        CdnsInfo.szLocalPath = szLocalPath;
        CdnsInfo.ccLocalPath = _countof(szLocalPath);

        // Download the config file
        dwErrCode = DownloadFileFromCDN(hs, CdnsInfo);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
    }
    else
    {
        CASC_PATH<TCHAR> Path;

        Path.AppendString(hs->szDataPath, false);
        Path.AppendString(szSubDir, true);
        Path.AppendString(szPathType, true);
        Path.AppendEKey(pFileKey->pbData);
        Path.Copy(szLocalPath, _countof(szLocalPath));
    }

    // Load and verify the external listfile
    pvListFile = ListFile_OpenExternal(szLocalPath);
    if (pvListFile != NULL)
    {
        if (ListFile_VerifyMD5(pvListFile, pFileKey->pbData))
        {
            dwErrCode = PfnParseProc(hs, pvListFile);
        }
        else
        {
            dwErrCode = ERROR_FILE_CORRUPT;
        }
        CASC_FREE(pvListFile);
    }
    else
    {
        dwErrCode = ERROR_FILE_NOT_FOUND;
    }

    return dwErrCode;
}

//-----------------------------------------------------------------------------
// Public functions

bool InvokeProgressCallback(TCascStorage * hs, LPCSTR szMessage, LPCSTR szObject, DWORD CurrentValue, DWORD TotalValue)
{
    PCASC_OPEN_STORAGE_ARGS pArgs = hs->pArgs;
    bool bResult = false;

    if(pArgs && pArgs->PfnProgressCallback)
        bResult = pArgs->PfnProgressCallback(pArgs->PtrProgressParam, szMessage, szObject, CurrentValue, TotalValue);
    return bResult;
}

DWORD GetFileSpanInfo(PCASC_CKEY_ENTRY pCKeyEntry, PULONGLONG PtrContentSize, PULONGLONG PtrEncodedSize)
{
    ULONGLONG ContentSize = 0;
    ULONGLONG EncodedSize = 0;
    DWORD dwSpanCount = pCKeyEntry->SpanCount;
    bool bContentSizeError = false;
    bool bEncodedSizeError = false;

    // Sanity check
    assert(pCKeyEntry->SpanCount != 0);

    // Sum the file size over all file spans
    // Note: The first file span, if referenced by the ROOT folder, gets the same size
    // like the entire file (example: zone\base.xpak, zone\base.xpak_1)
    for(DWORD i = 0; i < dwSpanCount; i++, pCKeyEntry++)
    {
        if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
            bContentSizeError = true;
        if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
            bEncodedSizeError = true;

        ContentSize = ContentSize + pCKeyEntry->ContentSize;
        EncodedSize = EncodedSize + pCKeyEntry->EncodedSize;
    }

    // Reset the sizes if there was an error
    PtrContentSize[0] = (bContentSizeError == false) ? ContentSize : CASC_INVALID_SIZE64;
    PtrEncodedSize[0] = (bEncodedSizeError == false) ? EncodedSize : CASC_INVALID_SIZE64;
    return dwSpanCount;
}

// Checks whether there is a ".build.info" or ".build.db".
// If yes, the function sets "szDataPath" and "szIndexPath"
// in the storage structure and returns ERROR_SUCCESS
DWORD CheckGameDirectory(TCascStorage * hs, TCHAR * szDirectory)
{
    TFileStream * pStream;
    TCHAR * szBuildFile;
    DWORD dwErrCode = ERROR_FILE_NOT_FOUND;

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
                dwErrCode = CheckDataDirectory(hs, szDirectory);
                if (dwErrCode == ERROR_SUCCESS)
                {
                    hs->szBuildFile = szBuildFile;
                    hs->BuildFileType = BuildTypes[i].BuildFileType;
                    return ERROR_SUCCESS;
                }
            }

            CASC_FREE(szBuildFile);
        }
    }

    return dwErrCode;
}

DWORD LoadBuildInfo(TCascStorage * hs)
{
    PARSECSVFILE PfnParseProc = NULL;
    DWORD dwErrCode;
    bool bHasHeader = true;

    // If the storage is online storage, we need to download "versions"
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        CASC_CDN_DOWNLOAD CdnsInfo = {0};
        TCHAR szLocalFile[MAX_PATH];

        // Inform the user about loading the build.info/build.db/versions
        if(InvokeProgressCallback(hs, "Downloading the \"versions\" file", NULL, 0, 0))
            return ERROR_CANCELLED;

        // Prepare the download structure for "us.patch.battle.net/%CODENAME%/versions" file
        CdnsInfo.szCdnsHost = _T("us.patch.battle.net");
        CdnsInfo.szCdnsPath = hs->szCodeName;
        CdnsInfo.szPathType = _T("");
        CdnsInfo.szFileName = _T("versions");
        CdnsInfo.szLocalPath = szLocalFile;
        CdnsInfo.ccLocalPath = _countof(szLocalFile);
        CdnsInfo.Flags = CASC_CDN_FLAG_PORT1119 | CASC_CDN_FORCE_DOWNLOAD;

        // Attempt to download the "versions" file
        dwErrCode = DownloadFileFromCDN(hs, CdnsInfo);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Retrieve the name of the "versions" file
        if((hs->szBuildFile = CascNewStr(szLocalFile)) == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;
    }

    // We support ".build.info", ".build.db" or "versions"
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

    assert(hs->szBuildFile != NULL);
    return LoadCsvFile(hs, hs->szBuildFile, PfnParseProc, bHasHeader);
}

DWORD LoadCdnsFile(TCascStorage * hs)
{
    CASC_CDN_DOWNLOAD CdnsInfo = {0};
    TCHAR szLocalPath[MAX_PATH];
    DWORD dwErrCode = ERROR_SUCCESS;

    // Sanity checks
    assert(hs->dwFeatures & CASC_FEATURE_ONLINE);

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Downloading the \"cdns\" file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Prepare the download structure
    CdnsInfo.szCdnsHost = _T("us.patch.battle.net");
    CdnsInfo.szCdnsPath = hs->szCodeName;
    CdnsInfo.szPathType = _T("");
    CdnsInfo.szFileName = _T("cdns");
    CdnsInfo.szLocalPath = szLocalPath;
    CdnsInfo.ccLocalPath = _countof(szLocalPath);
    CdnsInfo.Flags = CASC_CDN_FLAG_PORT1119 | CASC_CDN_FORCE_DOWNLOAD;

    // Download file and parse it
    if((dwErrCode = DownloadFileFromCDN(hs, CdnsInfo)) == ERROR_SUCCESS)
    {
        dwErrCode = LoadCsvFile(hs, szLocalPath, ParseFile_CDNS, true);
    }

    return dwErrCode;
}

DWORD LoadCdnConfigFile(TCascStorage * hs)
{
    // The CKey for the CDN config should have been loaded already
    assert(hs->CdnConfigKey.pbData != NULL && hs->CdnConfigKey.cbData == MD5_HASH_SIZE);

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading CDN config file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the CDN config file
    return FetchAndLoadConfigFile(hs, &hs->CdnConfigKey, ParseFile_CdnConfig);
}

DWORD LoadCdnBuildFile(TCascStorage * hs)
{
    // The CKey for the CDN config should have been loaded already
    assert(hs->CdnBuildKey.pbData != NULL && hs->CdnBuildKey.cbData == MD5_HASH_SIZE);

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading CDN build file", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the CDN config file. Note that we don't
    // need it for anything, really, so we don't care if it fails
    return FetchAndLoadConfigFile(hs, &hs->CdnBuildKey, ParseFile_CdnBuild);
}

LPBYTE LoadInternalFileToMemory(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, DWORD * pcbFileData)
{
    LPBYTE pbFileData = NULL;
    HANDLE hFile = NULL;
    DWORD dwFileSizeHi = 0;
    DWORD cbFileData = 0;
    DWORD dwBytesRead = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Open the file either by CKey or by EKey
    if(OpenFileByCKeyEntry(hs, pCKeyEntry, CASC_STRICT_DATA_CHECK, &hFile))
    {
        // Make the file not cached. We always load the entire file to memory,
        // so no need to cache (and needlessly copy from one buffer to another)
        SetCacheStrategy(hFile, CascCacheNothing);

        // Retrieve the size of the file. Note that the caller might specify
        // the real size of the file, in case the file size is not retrievable
        // or if the size is wrong. Example: ENCODING file has size specified in BUILD
        if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
        {
            cbFileData = CascGetFileSize(hFile, &dwFileSizeHi);
            if(cbFileData == CASC_INVALID_SIZE || dwFileSizeHi != 0)
                dwErrCode = ERROR_FILE_CORRUPT;
        }
        else
        {
            cbFileData = pCKeyEntry->ContentSize;
        }

        // Load the entire file to memory
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Allocate space for the ENCODING file
            pbFileData = CASC_ALLOC<BYTE>(cbFileData);
            if(pbFileData != NULL)
            {
                // Read the entire file to memory
                CascReadFile(hFile, pbFileData, cbFileData, &dwBytesRead);
                if(dwBytesRead != cbFileData)
                {
                    dwErrCode = ERROR_FILE_CORRUPT;
                }
            }
            else
            {
                dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
            }
        }

        // Close the file
        CascCloseFile(hFile);
    }
    else
    {
        dwErrCode = GetLastError();
    }

    // Handle errors
    if(dwErrCode != ERROR_SUCCESS)
    {
        // Free the file data
        CASC_FREE(pbFileData);
        cbFileData = 0;

        // Set the last error
        SetLastError(dwErrCode);
    }

    // Give the loaded file length
    if(pcbFileData != NULL)
        *pcbFileData = cbFileData;
    return pbFileData;
}

LPBYTE LoadFileToMemory(LPCTSTR szFileName, DWORD * pcbFileData)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    LPBYTE pbFileData = NULL;
    DWORD cbFileData = 0;

    // Open the stream for read-only access and read the file
    // Note that this fails when the game is running (sharing violation).
    pStream = FileStream_OpenFile(szFileName, STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        // Retrieve the file size
        FileStream_GetSize(pStream, &FileSize);
        cbFileData = (DWORD)FileSize;

        // Do not load zero files or too larget files
        if(0 < FileSize && FileSize <= 0x2000000)
        {
            // Allocate file data buffer. Make it 1 byte longer
            // so string functions can put '\0' there
            pbFileData = CASC_ALLOC<BYTE>(cbFileData + 1);
            if(pbFileData != NULL)
            {
                if(!FileStream_Read(pStream, NULL, pbFileData, cbFileData))
                {
                    CASC_FREE(pbFileData);
                    cbFileData = 0;
                }
            }
            else
            {
                SetLastError(ERROR_NOT_ENOUGH_MEMORY);
                cbFileData = 0;
            }
        }
        else
        {
            SetLastError(ERROR_BAD_FORMAT);
            cbFileData = 0;
            assert(false);
        }

        // Close the file stream
        FileStream_Close(pStream);
    }

    // Give out values
    if(pcbFileData != NULL)
        pcbFileData[0] = cbFileData;
    return pbFileData;
}

