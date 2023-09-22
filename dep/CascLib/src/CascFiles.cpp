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

#ifdef _MSC_VER
#pragma comment(lib, "ws2_32.lib")          // Internet functions for HTTP stream
#endif

//-----------------------------------------------------------------------------
// Local defines

#define MAX_VAR_NAME 80

typedef DWORD (*PARSE_CSV_FILE)(TCascStorage * hs, CASC_CSV & Csv);
typedef DWORD (*PARSE_TEXT_FILE)(TCascStorage * hs, void * pvListFile);
typedef DWORD (*PARSE_VARIABLE)(TCascStorage * hs, const char * szVariableName, const char * szDataBegin, const char * szDataEnd, void * pvParam);
typedef DWORD (*PARSE_REGION_LINE)(TCascStorage * hs, CASC_CSV & Csv, size_t nLine);

static DWORD RibbitDownloadFile(LPCTSTR szCdnHostUrl, LPCTSTR szProduct, LPCTSTR szFileName, CASC_PATH<TCHAR> & LocalPath, CASC_BLOB & FileData);

//-----------------------------------------------------------------------------
// Local structures

struct TBuildFileInfo
{
    LPCTSTR szFileName;
    size_t  nLength;
    CBLD_TYPE BuildFileType;
};

struct TGameLocaleString
{
    const char * szLocale;
    DWORD dwLocale;
};

static const TBuildFileInfo BuildTypes[] =
{
    {_T(".build.info"), 11, CascBuildInfo},         // Since HOTS build 30027, the game uses .build.info file for storage info
    {_T(".build.db"),   9,  CascBuildDb},           // Older CASC storages
    {_T("versions"),    8,  CascVersions},          // Online/cached CASC storages
};

static LPCTSTR DataDirs[] =
{
    _T("data") _T(PATH_SEP_STRING) _T("casc"),      // Overwatch. This item must be the first in the list
    _T("data"),                                     // TACT casc (for Linux systems)
    _T("Data"),                                     // World of Warcraft, Diablo
    _T("SC2Data"),                                  // Starcraft II (Legacy of the Void) build 38749
    _T("HeroesData"),                               // Heroes of the Storm
    _T("BNTData"),                                  // Heroes of the Storm, until build 30414
    NULL,
};

static const LPCTSTR szDefaultCDN = _T("ribbit://us.version.battle.net/v1/products");
static const ULONGLONG ValueOne64 = 1;

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

static LPCTSTR GetSubFolder(CPATH_TYPE PathType)
{
    switch(PathType)
    {
        case PathTypeConfig: return _T("config");
        case PathTypeData:   return _T("data");
        case PathTypePatch:  return _T("patch");
        
        default:
            assert(false);
            return _T("");
    }
}

static bool CheckForTwoDigitFolder(LPCTSTR szPathName, void * pvContext)
{
    BYTE Binary[8];

    // Must be a two-digit hexa string (the first two digits of the CKey)
    if(_tcslen(szPathName) == 2)
    {
        if(BinaryFromString(szPathName, 2, Binary) == ERROR_SUCCESS)
        {
            *(bool *)pvContext = true;
            return false;
        }
    }
    
    // Keep searching
    return true;
}

static bool ReplaceVersionsWithCdns(LPTSTR szBuffer, size_t ccBuffer, LPCTSTR szVersions)
{
    LPCTSTR szVersions0 = _T("versions");
    LPCTSTR szCdns0 = _T("cdns");
    size_t nLength;

    // Copy the existing file name into new buffer
    CascStrCopy(szBuffer, ccBuffer, GetPlainFileName(szVersions));

    // Find the ending "versions" string
    if((nLength = _tcslen(szBuffer)) >= 8)
    {
        szBuffer = szBuffer + nLength - 8;
        if(!_tcsicmp(szBuffer, szVersions0))
        {
            CascStrCopy(szBuffer, 5, szCdns0);
            return true;
        }
    }
    return false;
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
        if(!IsCharDigit(szDataPtr[0]))
            break;

        // Get the next value and verify overflow
        AddValue = szDataPtr[0] - '0';
        if((TotalValue + AddValue) < TotalValue)
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
    for(size_t i = 0; i < HashStringLength; i++)
    {
        if(szDataPtr >= szDataEnd || isxdigit(szDataPtr[0]) == 0)
            return NULL;
        szDataPtr++;
    }

    // There must be a separator or end-of-string
    if(szDataPtr > szDataEnd || IsWhiteSpace(szDataPtr) == false)
        return NULL;

    // Give the values
    BinaryFromString(szHashString, HashStringLength, HashValue);
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
        if(szDataPtr == NULL)
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
        default:         return CASC_LOCALE_NONE;
    }
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
    if(szLinePtr == NULL)
        return false;

    // Verify whether this is the variable
    if(!CascCheckWildCard(szVariableName, szVarName))
        return false;

    // Skip the spaces and '='
    while (szLinePtr < szLineEnd && (IsWhiteSpace(szLinePtr) || szLinePtr[0] == '='))
        szLinePtr++;

    // Call the parsing function only if there is some data
    if(szLinePtr >= szLineEnd)
        return false;

    return (PfnParseProc(hs, szVariableName, szLinePtr, szLineEnd, pvParseParam) == ERROR_SUCCESS);
}

static DWORD LoadHashArray(
    PCASC_BLOB pBlob,
    const char * szLinePtr,
    const char * szLineEnd,
    size_t HashCount)
{
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the blob buffer
    pBlob->cbData = (DWORD)(HashCount * MD5_HASH_SIZE);
    pBlob->pbData = CASC_ALLOC<BYTE>(pBlob->cbData);
    if(pBlob->pbData != NULL)
    {
        LPBYTE pbBuffer = pBlob->pbData;

        for(size_t i = 0; i < HashCount; i++)
        {
            // Capture the hash value
            szLinePtr = CaptureSingleHash(szLinePtr, szLineEnd, pbBuffer, MD5_HASH_SIZE);
            if(szLinePtr == NULL)
                return ERROR_BAD_FORMAT;

            // Move buffer
            pbBuffer += MD5_HASH_SIZE;
        }
        
        dwErrCode = ERROR_SUCCESS;
    }

    return dwErrCode;
}

static DWORD LoadMultipleHashes(PCASC_BLOB pBlob, const char * szLineBegin, const char * szLineEnd)
{
    size_t HashCount = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Retrieve the hash count
    if(CaptureHashCount(szLineBegin, szLineEnd, &HashCount) == NULL)
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
    return LoadMultipleHashes((PCASC_BLOB)pvParam, szDataBegin, szDataEnd);
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
    if(!strncmp(szVariableName, "vfs-", 4))
    {
        // Then, there must be a decimal number as index
        if((szVarPtr = CaptureDecimalInteger(szVarPtr + 4, szVarEnd, &VfsRootIndex)) != NULL)
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
// "WOW-45779patch10.0.2_Beta"
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
        // If the character is a digit, we include it into the built number
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

    // If we don't have a build number yet, take the max value, if any
    if(hs->dwBuildNumber == 0 && dwMaxValue >= 100)
    {
        hs->dwBuildNumber = dwMaxValue;
        return ERROR_SUCCESS;
    }
    return ERROR_BAD_FORMAT;
}

static int LoadQueryKey(const CASC_CSV_COLUMN & Column, CASC_BLOB & Key)
{
    // Check the input data
    if(Column.szValue == NULL)
        return ERROR_BUFFER_OVERFLOW;
    if(Column.nLength != MD5_STRING_SIZE)
        return ERROR_BAD_FORMAT;

    return LoadHashArray(&Key, Column.szValue, Column.szValue + Column.nLength, 1);
}

static void SetProductCodeName(TCascStorage * hs, LPCSTR szCodeName)
{
    if(hs->szCodeName == NULL && szCodeName != NULL)
    {
        hs->szCodeName = CascNewStrA2T(szCodeName);
    }
}

static DWORD GetDefaultCdnServers(TCascStorage * hs, const CASC_CSV_COLUMN & Column)
{
    if(hs->szCdnServers == NULL && Column.nLength != 0)
        hs->szCdnServers = CascNewStrA2T(Column.szValue);
    return ERROR_SUCCESS;
}

static DWORD GetDefaultCdnPath(TCascStorage * hs, const CASC_CSV_COLUMN & Column)
{
    if(hs->szCdnPath == NULL && Column.nLength != 0)
        hs->szCdnPath = CascNewStrA2T(Column.szValue);
    return ERROR_SUCCESS;
}

static DWORD GetDefaultLocaleByRegion(LPCSTR szRegion)
{
    #define CASC_REGION_INT(hi, lo) (((DWORD)(hi) << 0x08) | lo)

    // Setup the default locale
    switch(CASC_REGION_INT(szRegion[0], szRegion[1]))
    {
        case CASC_REGION_INT('u', 's'): return CASC_LOCALE_ENUS;
        case CASC_REGION_INT('e', 'u'): return CASC_LOCALE_ENGB;
        case CASC_REGION_INT('c', 'n'): return CASC_LOCALE_ZHCN;
        case CASC_REGION_INT('k', 'r'): return CASC_LOCALE_KOKR;
        case CASC_REGION_INT('t', 'w'): return CASC_LOCALE_ZHTW;
//      case CASC_REGION_INT('s', 'g'): return CASC_LOCALE_????;
        default: return CASC_LOCALE_ENUS;
    }
}

static DWORD GetDefaultLocaleMask(const CASC_CSV_COLUMN & Column)
{
    LPCSTR szTagEnd = Column.szValue + Column.nLength - 4;
    LPCSTR szTagPtr;
    DWORD dwLocaleValue;
    DWORD dwLocaleMask = 0;

    // Go through the whole tag string
    for(szTagPtr = Column.szValue; szTagPtr <= szTagEnd; szTagPtr++)
    {
        // Try to recognize the 4-char locale code
        if((dwLocaleValue = GetLocaleValue(szTagPtr)) != CASC_LOCALE_NONE)
        {
            dwLocaleMask |= dwLocaleValue;
            szTagPtr += 3;  // Will be moved by 1 more at the end of the loop
        }
    }
    return dwLocaleMask;
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
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Extract the CDN config key
        dwErrCode = LoadQueryKey(Csv[nSelected]["CDN Key!HEX:16"], hs->CdnConfigKey);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // If we found tags, we can extract language build from it
        hs->dwDefaultLocale = GetDefaultLocaleMask(Csv[nSelected]["Tags!STRING:0"]);

        // Get the CDN servers and hosts
        if(hs->dwFeatures & CASC_FEATURE_ONLINE)
        {
            GetDefaultCdnServers(hs, Csv[nSelected]["CDN Hosts!STRING:0"]);
            GetDefaultCdnPath(hs, Csv[nSelected]["CDN Path!STRING:0"]);
        }

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

static DWORD ParseRegionLine_Versions(TCascStorage * hs, CASC_CSV & Csv, size_t nLine)
{
    DWORD dwErrCode;

    // If the region line is not there yet, supply default one
    if(hs->szRegion == NULL)
        hs->szRegion = CascNewStr(Csv[nLine]["Region!STRING:0"].szValue);

    // Get the default locale mask based on the region
    hs->dwDefaultLocale = GetDefaultLocaleByRegion(hs->szRegion);

    // Extract the CDN build key
    dwErrCode = LoadQueryKey(Csv[nLine]["BuildConfig!HEX:16"], hs->CdnBuildKey);
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Extract the CDN config key
    dwErrCode = LoadQueryKey(Csv[nLine]["CDNConfig!HEX:16"], hs->CdnConfigKey);
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    const CASC_CSV_COLUMN & VerColumn = Csv[nLine]["VersionsName!String:0"];
    if(VerColumn.szValue && VerColumn.nLength)
    {
        LoadBuildNumber(hs, NULL, VerColumn.szValue, VerColumn.szValue + VerColumn.nLength, NULL);
    }

    // Verify all variables
    if(hs->CdnBuildKey.pbData != NULL && hs->CdnConfigKey.pbData != NULL)
    {
        // If we have manually given build key, override the value
        if(hs->szBuildKey != NULL)
            dwErrCode = BinaryFromString(hs->szBuildKey, MD5_STRING_SIZE, hs->CdnBuildKey.pbData);
        return dwErrCode;
    }

    return ERROR_BAD_FORMAT;
}

static DWORD ParseRegionLine_Cdns(TCascStorage * hs, CASC_CSV & Csv, size_t nLine)
{
    hs->szCdnServers = CascNewStrA2T(Csv[nLine]["Hosts!STRING:0"].szValue);
    hs->szCdnPath = CascNewStrA2T(Csv[nLine]["Path!STRING:0"].szValue);
    return (hs->szCdnServers && hs->szCdnPath) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
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
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Extract tags
    hs->dwDefaultLocale = GetDefaultLocaleMask(Csv[CSV_ZERO][2]);

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
    if(dwErrCode != ERROR_SUCCESS)
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

// Loads a local CSV file
static DWORD LoadCsvFile(TCascStorage * hs, LPCTSTR szFileName, PARSE_CSV_FILE PfnParseProc, bool bHasHeader)
{
    CASC_CSV Csv(0x40, bHasHeader);
    DWORD dwErrCode;

    // Load the external file to memory
    if((dwErrCode = Csv.Load(szFileName)) == ERROR_SUCCESS)
        dwErrCode = PfnParseProc(hs, Csv);
    return dwErrCode;
}

// Loading an online file (VERSIONS or CDNS)
static DWORD LoadCsvFile(TCascStorage * hs, PARSE_REGION_LINE PfnParseRegionLine, LPCTSTR szFileName, LPCSTR szColumnName, bool bForceDownload)
{
    CASC_PATH<TCHAR> LocalPath;
    CASC_BLOB FileData;
    DWORD dwErrCode = ERROR_SUCCESS;
    char szFileNameA[0x20];

    // Prepare the loading / downloading
    LocalPath.SetPathRoot(hs->szRootPath);
    LocalPath.AppendString(szFileName, true);
    LocalPath.SetLocalCaching(bForceDownload == false);

    // If the storage is defined as online, we can download the file, if it doesn't exist
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        // Inform the user that we are downloading something
        CascStrCopy(szFileNameA, _countof(szFileNameA), szFileName);
        if(InvokeProgressCallback(hs, "Downloading the \"%s\" file", szFileNameA, 0, 0))
            return ERROR_CANCELLED;

        // Download the file using Ribbit/HTTP protocol
        dwErrCode = RibbitDownloadFile(hs->szCdnHostUrl, hs->szCodeName, szFileName, LocalPath, FileData);
    }
    else
    {
        // Load the local file
        dwErrCode = LoadFileToMemory(LocalPath, FileData);
    }

    // Load the VERSIONS file
    if(dwErrCode == ERROR_SUCCESS)
    {
        CASC_CSV Csv(0x40, true);

        // Load the external file to memory
        if((dwErrCode = Csv.Load(FileData.pbData, FileData.cbData)) == ERROR_SUCCESS)
        {
            size_t nLineCount = Csv.GetLineCount();
            size_t nRegionXX = CASC_INVALID_SIZE_T;
            size_t nRegionUS = CASC_INVALID_SIZE_T;
            size_t nRegionEU = CASC_INVALID_SIZE_T;

            // Find a matching config
            for(size_t i = 0; i < nLineCount; i++)
            {
                const char * szRegion = Csv[i][szColumnName].szValue;

                if(hs->szRegion && szRegion && !strcmp(hs->szRegion, szRegion))
                    return PfnParseRegionLine(hs, Csv, i);

                if(szRegion != NULL)
                {
                    if(!strcmp(szRegion, "xx"))
                    {
                        nRegionXX = i;
                        continue;
                    }

                    if(!strcmp(szRegion, "us"))
                    {
                        nRegionUS = i;
                        continue;
                    }

                    if(!strcmp(szRegion, "eu"))
                    {
                        nRegionEU = i;
                        continue;
                    }
                }
            }

            // Now load the regions in this order:
            // 1) US region
            // 2. EU region
            // 3. XX region
            // 4. The first line
            if(nRegionUS != CASC_INVALID_SIZE_T)
                return PfnParseRegionLine(hs, Csv, nRegionUS);
            if(nRegionEU != CASC_INVALID_SIZE_T)
                return PfnParseRegionLine(hs, Csv, nRegionEU);
            if(nRegionXX != CASC_INVALID_SIZE_T)
                return PfnParseRegionLine(hs, Csv, nRegionXX);
            if(nLineCount != 0)
                return PfnParseRegionLine(hs, Csv, 0);
            dwErrCode = ERROR_FILE_NOT_FOUND;
        }
    }
    return dwErrCode;
}

static DWORD ForcePathExist(LPCTSTR szFileName, bool bIsFileName)
{
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
    bool bFirstSeparator = false;

    // Sanity checks
    if(szFileName && szFileName[0])
    {
        CASC_PATH<TCHAR> LocalPath(szFileName, NULL);

        // Get the end of search
        if(bIsFileName)
            LocalPath.CutLastPart();

        // Check whether the path exists
        if(_taccess(LocalPath, 0) != 0)
        {
            LPTSTR szLocalPath = (LPTSTR)(LPCTSTR)LocalPath;

            // Search the entire path
            for(size_t nIndex = 0; nIndex < LocalPath.Length(); nIndex++)
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
    }

    return dwErrCode;
}

static DWORD SaveLocalFile(LPCTSTR szLocalName, LPBYTE pbFileData, size_t cbFileData)
{
    TFileStream * pLocStream;
    DWORD dwErrCode = ERROR_DISK_FULL;

    // Make sure that the path exists
    ForcePathExist(szLocalName, true);

    // Create local file
    pLocStream = FileStream_CreateFile(szLocalName, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
    if(pLocStream != NULL)
    {
        if(FileStream_Write(pLocStream, NULL, pbFileData, (DWORD)(cbFileData)))
            dwErrCode = ERROR_SUCCESS;

        FileStream_Close(pLocStream);
    }
    else
        dwErrCode = GetCascError();

    return dwErrCode;
}

static LPCTSTR ExtractCdnServerName(LPTSTR szServerName, size_t cchServerName, LPCTSTR szCdnServers)
{
    LPCTSTR szSeparator;

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

static bool FileAlreadyExists(LPCTSTR szFileName)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;

    // The file open must succeed and also must be of non-zero size
    if((pStream = FileStream_OpenFile(szFileName, 0)) != NULL)
    {
        FileStream_GetSize(pStream, &FileSize);
        FileStream_Close(pStream);
    }

    return (FileSize != 0);
}

static DWORD RibbitDownloadFile(LPCTSTR szCdnHostUrl, LPCTSTR szProduct, LPCTSTR szFileName, CASC_PATH<TCHAR> & LocalPath, CASC_BLOB & FileData)
{
    CASC_PATH<TCHAR> LocalFile;
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    TCHAR szRemoteUrl[256];
    DWORD dwErrCode = ERROR_CAN_NOT_COMPLETE;

    // If required, try to load the local name first
    if(LocalPath.Length() && LocalPath.LocalCaching())
    {
        // Load the local file into memory
        if((dwErrCode = LoadFileToMemory(LocalPath, FileData)) == ERROR_SUCCESS)
        {
            // Pass the file data to the caller
            return ERROR_SUCCESS;
        }
    }

    // Supply the default CDN URL, if not present
    if(szCdnHostUrl == NULL || szCdnHostUrl[0] == 0)
        szCdnHostUrl = szDefaultCDN;

    // Construct the full URL (https://wowdev.wiki/Ribbit)
    // Old (HTTP) download: wget http://us.patch.battle.net:1119/wow_classic/cdns
    CascStrPrintf(szRemoteUrl, _countof(szRemoteUrl), _T("%s/%s/%s"), szCdnHostUrl, szProduct, szFileName);

    // Open the file stream
    if((pStream = FileStream_OpenFile(szRemoteUrl, 0)) != NULL)
    {
        if(FileStream_GetSize(pStream, &FileSize) && FileSize <= 0x04000000)
        {
            // Fill-in the file pointer and size
            if((dwErrCode = FileData.SetSize((size_t)FileSize)) == ERROR_SUCCESS)
            {
                if(FileStream_Read(pStream, NULL, FileData.pbData, (DWORD)FileSize))
                {
                    dwErrCode = ERROR_SUCCESS;
                }
                else
                {
                    dwErrCode = GetCascError();
                    FileData.Free();
                }
            }
        }
        else
        {
            dwErrCode = GetCascError();
        }

        // Close the remote stream
        FileStream_Close(pStream);
    }
    else
    {
        dwErrCode = GetCascError();
    }

    // Save the file to the local cache
    if(LocalPath.Length() && FileData.pbData && FileData.cbData && dwErrCode == ERROR_SUCCESS)
        SaveLocalFile(LocalPath, FileData.pbData, FileData.cbData);
    return dwErrCode;
}

static DWORD HttpDownloadFile(
    LPCTSTR szRemoteName,
    LPCTSTR szLocalName,
    PULONGLONG PtrByteOffset,
    DWORD cbReadSize,
    DWORD dwPortFlags)
{
    TFileStream * pRemStream;
    LPBYTE pbFileData;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Open the remote stream
    pRemStream = FileStream_OpenFile(szRemoteName, BASE_PROVIDER_HTTP | STREAM_PROVIDER_FLAT | dwPortFlags);
    if(pRemStream != NULL)
    {
        // Will we download the entire file or just a part of it?
        if(PtrByteOffset == NULL)
        {
            ULONGLONG FileSize = 0;

            // Retrieve the file size, but not longer than 1 GB
            if(FileStream_GetSize(pRemStream, &FileSize))
            {
                // Verify valid size
                if(0 < FileSize && FileSize < CASC_MAX_ONLINE_FILE_SIZE)
                {
                    cbReadSize = (DWORD)FileSize;
                    dwErrCode = ERROR_SUCCESS;
                }
                else
                {
                    dwErrCode = ERROR_BAD_FORMAT;
                }
            }
            else
            {
                dwErrCode = GetCascError();
            }
        }

        // Shall we read something?
        if((dwErrCode == ERROR_SUCCESS) && (cbReadSize != 0) && (pbFileData = CASC_ALLOC<BYTE>(cbReadSize)) != NULL)
        {
            // Read all required data from the remote file
            if(FileStream_Read(pRemStream, PtrByteOffset, pbFileData, cbReadSize))
                dwErrCode = SaveLocalFile(szLocalName, pbFileData, cbReadSize);

            // Free the data buffer
            CASC_FREE(pbFileData);
        }

        // Close the remote stream
        FileStream_Close(pRemStream);
    }
    else
    {
        dwErrCode = GetCascError();
    }

    return dwErrCode;
}

DWORD FetchCascFile(
    TCascStorage * hs,
    LPCTSTR szRootPath,
    CPATH_TYPE PathType,
    LPBYTE pbEKey,
    LPCTSTR szExtension,
    CASC_PATH<TCHAR> & LocalPath)
{
    LPCTSTR szCdnServers = hs->szCdnServers;
    DWORD dwErrCode = ERROR_SUCCESS;
    TCHAR szCdnServer[MAX_PATH] = _T("");

    // First, construct the local path
    LocalPath.Create(szRootPath, GetSubFolder(PathType), NULL);
    LocalPath.AppendEKey(pbEKey);
    LocalPath.AppendString(szExtension, false);

    // Check whether the file already exists
    if(!FileAlreadyExists(LocalPath))
    {
        // If this is not an online version, do nothing and return error
        if(!(hs->dwFeatures & CASC_FEATURE_ONLINE))
            return ERROR_FILE_NOT_FOUND;

        // Force-create the local path
        if((dwErrCode = ForcePathExist(LocalPath, true)) != ERROR_SUCCESS)
            return dwErrCode;

        // Try all download servers
        while((szCdnServers = ExtractCdnServerName(szCdnServer, _countof(szCdnServer), szCdnServers)) != NULL)
        {
            CASC_PATH<TCHAR> RemotePath(URL_SEP_CHAR);

            // Construct the full remote URL path
            RemotePath.Create(szCdnServer, hs->szCdnPath, GetSubFolder(PathType), NULL);
            RemotePath.AppendEKey(pbEKey);
            RemotePath.AppendString(szExtension, false);

            // Attempt to download the file
            dwErrCode = HttpDownloadFile(RemotePath, LocalPath, NULL, 0, 0);

            // Stop on low memory condition, as it will most likely
            // end up with low memory on next download
            if(dwErrCode == ERROR_SUCCESS || dwErrCode == ERROR_NOT_ENOUGH_MEMORY)
                return dwErrCode;
        }
        
        // Sorry, the file was not found
        dwErrCode = ERROR_FILE_NOT_FOUND;
    }
    return dwErrCode;
}

DWORD FetchCascFile(TCascStorage * hs, CPATH_TYPE PathType, LPBYTE pbEKey, LPCTSTR szExtension, CASC_PATH<TCHAR> & LocalPath, PCASC_ARCHIVE_INFO pArchiveInfo)
{
    PCASC_EKEY_ENTRY pEKeyEntry;
    LPBYTE pbArchiveKey;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Data files may be stored in archives, therefore we need to check
    if((pbEKey != NULL) && (pEKeyEntry = (PCASC_EKEY_ENTRY)hs->IndexMap.FindObject(pbEKey)) != NULL)
    {
        // Can't complete if the caller doesn't know the archive info
        if(pArchiveInfo != NULL)
        {
            // Fill-in the archive info
            pArchiveInfo->ArchiveIndex = (DWORD)(pEKeyEntry->StorageOffset >> hs->FileOffsetBits);
            pArchiveInfo->ArchiveOffs = (DWORD)(pEKeyEntry->StorageOffset & ((ValueOne64 << hs->FileOffsetBits) - 1));
            pArchiveInfo->EncodedSize = pEKeyEntry->EncodedSize;

            // Fill-in the archive key
            pbArchiveKey = pbEKey = hs->ArchivesKey.pbData + (MD5_HASH_SIZE * pArchiveInfo->ArchiveIndex);
            memcpy(pArchiveInfo->ArchiveKey, pbArchiveKey, MD5_HASH_SIZE);
            
            // Remap the path type to "data"
            PathType = PathTypeData;
        }
        else
        {
            dwErrCode = ERROR_CAN_NOT_COMPLETE;
        }
    }

    if(dwErrCode == ERROR_SUCCESS)
    {
        // Try the local archives
        if(hs->dwFeatures & CASC_FEATURE_DATA_ARCHIVES)
        {
            dwErrCode = FetchCascFile(hs, hs->szDataPath, PathType, pbEKey, szExtension, LocalPath);
            if(dwErrCode == ERROR_SUCCESS)
                return ERROR_SUCCESS;
        }

        // Try to download the file into the "data/<type>" path
        if(hs->szDataPath != NULL)
        {
            dwErrCode = FetchCascFile(hs, hs->szDataPath, PathType, pbEKey, szExtension, LocalPath);
            if(dwErrCode == ERROR_SUCCESS)
                return ERROR_SUCCESS;
        }

        // Try to download the file into the "<type>" path
        if(hs->szRootPath != NULL)
        {
            dwErrCode = FetchCascFile(hs, hs->szRootPath, PathType, pbEKey, szExtension, LocalPath);
            if(dwErrCode == ERROR_SUCCESS)
                return ERROR_SUCCESS;
        }
    }
    return dwErrCode;
}

static DWORD FetchAndLoadConfigFile(TCascStorage * hs, PCASC_BLOB pFileKey, PARSE_TEXT_FILE PfnParseProc)
{
    CASC_PATH<TCHAR> LocalPath;
    void * pvListFile = NULL;
    DWORD dwErrCode;

    // Make sure there is a local copy of the file
    dwErrCode = FetchCascFile(hs, PathTypeConfig, pFileKey->pbData, NULL, LocalPath);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Load and verify the external listfile
        pvListFile = ListFile_OpenExternal(LocalPath);
        if(pvListFile != NULL)
        {
            if(ListFile_VerifyMD5(pvListFile, pFileKey->pbData))
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
    }
    return dwErrCode;
}

static LPTSTR CheckForDirectory(LPCTSTR szParentFolder, LPCTSTR szSubFolder)
{
    CASC_PATH<TCHAR> LocalPath(szParentFolder, szSubFolder, NULL);
    LPTSTR szLocalPath = NULL;

    // Check whether the path exists
    if(DirectoryExists(LocalPath))
        szLocalPath = LocalPath.New();
    return szLocalPath;
}

static LPTSTR CheckForDirectories(LPCTSTR szParentFolder, ...)
{
    LPCTSTR szSubDir;
    va_list argList;
    LPTSTR szFolder = NULL;

    va_start(argList, szParentFolder);
    while((szSubDir = va_arg(argList, LPCTSTR)) != NULL)
    {
        if((szFolder = CheckForDirectory(szParentFolder, szSubDir)) != NULL)
            break;
    }
    va_end(argList);

    return szFolder;
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

DWORD CheckCascBuildFileExact(CASC_BUILD_FILE & BuildFile, LPCTSTR szLocalPath)
{
    // Calculate the length of the local path
    TFileStream * pStream;
    LPCTSTR szFileType;
    size_t nLength = _tcslen(szLocalPath);

    // Clear the build file structure
    memset(&BuildFile, 0, sizeof(CASC_BUILD_FILE));

    // Check every type of the build file
    for(size_t i = 0; i < _countof(BuildTypes); i++)
    {
        // We support any file name with the appropriate ending,
        // for example wow-19342.build.info or wow-47186.versions
        szFileType = szLocalPath + nLength - BuildTypes[i].nLength;
        if(!_tcsicmp(BuildTypes[i].szFileName, szFileType))
        {
            // We also try to open the file
            if((pStream = FileStream_OpenFile(szLocalPath, 0)) != NULL)
            {
                CascStrCopy(BuildFile.szFullPath, _countof(BuildFile.szFullPath), szLocalPath);
                BuildFile.szPlainName = GetPlainFileName(BuildFile.szFullPath);
                BuildFile.BuildFileType = BuildTypes[i].BuildFileType;
                FileStream_Close(pStream);
                return ERROR_SUCCESS;
            }
        }
    }

    // Unrecognized file name
    return ERROR_BAD_FORMAT;
}

DWORD CheckCascBuildFileDirs(CASC_BUILD_FILE & BuildFile, LPCTSTR szLocalPath)
{
    CASC_PATH<TCHAR> WorkPath(szLocalPath, NULL);
    DWORD dwErrCode = ERROR_FILE_NOT_FOUND;

    // Clear the build file structure
    memset(&BuildFile, 0, sizeof(CASC_BUILD_FILE));

    for(;;)
    {
        // Try all supported build file types
        for(size_t i = 0; i < _countof(BuildTypes); i++)
        {
            CASC_PATH<TCHAR> FilePath(WorkPath, BuildTypes[i].szFileName, NULL);

            // If the file exists there, we found it
            if(CheckCascBuildFileExact(BuildFile, FilePath) == ERROR_SUCCESS)
            {
                return ERROR_SUCCESS;
            }
        }

        // Try to cut off one path path
        if(!WorkPath.CutLastPart())
        {
            dwErrCode = ERROR_PATH_NOT_FOUND;
            break;
        }
    }

    // Unrecognized file name
    return dwErrCode;
}

DWORD CheckOnlineStorage(PCASC_OPEN_STORAGE_ARGS pArgs, CASC_BUILD_FILE & BuildFile, bool bOnlineStorage)
{
    // If the online storage is required, we try to extract the product code
    if((bOnlineStorage) && (pArgs->szCodeName != NULL))
    {
        CASC_PATH<TCHAR> FilePath(pArgs->szLocalPath, _T("versions"), NULL);

        FilePath.CopyTo(BuildFile.szFullPath, _countof(BuildFile.szFullPath));
        BuildFile.szPlainName = GetPlainFileName(BuildFile.szFullPath);
        BuildFile.BuildFileType = CascVersions;
        return ERROR_SUCCESS;
    }
    return ERROR_FILE_NOT_FOUND;
}

DWORD CheckArchiveFilesDirectories(TCascStorage * hs)
{
    // Sanity checks
    assert((hs->dwFeatures & CASC_FEATURE_DATA_ARCHIVES) != 0);
    assert(hs->szRootPath != NULL);
    assert(hs->szDataPath == NULL);
    assert(hs->szIndexPath == NULL);

    LPTSTR szDataPath = NULL;
    LPTSTR szConfigPath = NULL;
    LPTSTR szIndexPath = NULL;

    // Try all known subdirectories for the game data sub dirs
    for(size_t i = 0; i < _countof(DataDirs); i++)
    {
        if((szDataPath = CheckForDirectory(hs->szRootPath, DataDirs[i])) != NULL)
        {
            // Check the config folder
            if((szConfigPath = CheckForDirectory(szDataPath, _T("config"))) != NULL)
            {
                // First, check for more common "data" subdirectory
                // Second, try the "darch" subdirectory (older builds of HOTS - Alpha)
                if((szIndexPath = CheckForDirectories(szDataPath, _T("data"), _T("darch"), NULL)) != NULL)
                {
                    hs->szDataPath = szDataPath;
                    hs->szConfigPath = szConfigPath;
                    hs->szIndexPath = szIndexPath;
                    return ERROR_SUCCESS;
                }
                CASC_FREE(szConfigPath);
            }
            CASC_FREE(szDataPath);
        }
    }

    // One of the paths was not found
    return ERROR_FILE_NOT_FOUND;
}

DWORD CheckDataFilesDirectory(TCascStorage * hs)
{
    CASC_PATH<TCHAR> DataPath(hs->szRootPath, _T("data"), NULL);
    bool bTwoDigitFolderFound = false;

    // When CASC_FEATURE_ONLINE is not set, then the folder must exist
    if((hs->dwFeatures & CASC_FEATURE_ONLINE) == 0)
    {
        // Check if there are subfolders at all. If not, do not bother
        // the file system with open requests into data files folder
        if(ScanDirectory(DataPath, CheckForTwoDigitFolder, NULL, &bTwoDigitFolderFound) != ERROR_SUCCESS)
            return ERROR_PATH_NOT_FOUND;

        if(bTwoDigitFolderFound == false)
            return ERROR_PATH_NOT_FOUND;
    }

    // Create the path for raw files
    if((hs->szFilesPath = DataPath.New()) == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;
    return ERROR_SUCCESS;
}

DWORD LoadBuildFile_Versions_Cdns(TCascStorage * hs)
{
    LPCTSTR szVersions = _T("versions");
    DWORD dwErrCode;
    TCHAR szBuffer[MAX_PATH];
    bool bForceDownload = (hs->dwFeatures & CASC_FEATURE_FORCE_DOWNLOAD) ? true : false;

    // The default name of the build file is "versions". However, the caller may select different file
    if(hs->szMainFile && hs->szMainFile[0])
        szVersions = GetPlainFileName(hs->szMainFile);
    dwErrCode = LoadCsvFile(hs, ParseRegionLine_Versions, szVersions, "Region!STRING:0", bForceDownload);

    // We also need to load the "cdns" file
    if(dwErrCode == ERROR_SUCCESS)
    {
        // The default CDNS file is "cdns". However, if the build file is different, we change "cdns" as well
        // Example: If the build file name is "hearthstone-25.0.3.160183.159202.versions", then we want "hearthstone-25.0.3.160183.159202.cdns"
        if(hs->szMainFile && hs->szMainFile[0])
        {
            if(ReplaceVersionsWithCdns(szBuffer, _countof(szBuffer), hs->szMainFile))
            {
                dwErrCode = LoadCsvFile(hs, ParseRegionLine_Cdns, szBuffer, "Name!STRING:0", bForceDownload);
                if(dwErrCode == ERROR_SUCCESS)
                    return dwErrCode;
            }
        }

        // Fall back to the default "cdns" file
        dwErrCode = LoadCsvFile(hs, ParseRegionLine_Cdns, _T("cdns"), "Name!STRING:0", bForceDownload);
    }
    return dwErrCode;
}

DWORD LoadMainFile(TCascStorage * hs)
{
    DWORD dwErrCode = ERROR_NOT_SUPPORTED;

    // The build file must be known at this point, even for online storage
    // that are to bo created
    assert(hs->szMainFile != NULL);

    // Perform support for each build file type
    switch(hs->BuildFileType)
    {
        case CascBuildDb:       // Older storages have "build.db"
            dwErrCode = LoadCsvFile(hs, hs->szMainFile, ParseFile_BuildDb, false);
            break;

        case CascBuildInfo:     // Current storages have "build.db"
            dwErrCode = LoadCsvFile(hs, hs->szMainFile, ParseFile_BuildInfo, true);
            break;

        case CascVersions:      // Online storages have "versions+cdns"
            dwErrCode = LoadBuildFile_Versions_Cdns(hs);
            break;

        default:
            assert(false);
            break;
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

DWORD LoadInternalFileToMemory(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, CASC_BLOB & FileData)
{
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
            if((dwErrCode = FileData.SetSize(cbFileData)) == ERROR_SUCCESS)
            {
                // Read the entire file to memory
                CascReadFile(hFile, FileData.pbData, cbFileData, &dwBytesRead);
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
        dwErrCode = GetCascError();
    }

    // Handle errors
    if(dwErrCode != ERROR_SUCCESS)
        FileData.Free();
    return dwErrCode;
}

DWORD LoadFileToMemory(LPCTSTR szFileName, CASC_BLOB & FileData)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Open the stream for read-only access and read the file
    pStream = FileStream_OpenFile(szFileName, STREAM_FLAG_READ_ONLY | STREAM_FLAG_WRITE_SHARE | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        // Retrieve the file size
        FileStream_GetSize(pStream, &FileSize);

        // Do not load zero files or too large files
        if(0 < FileSize && FileSize <= 0x2000000)
        {
            // Allocate file data buffer. Make it 1 byte longer
            // so string functions can put '\0' there
            dwErrCode = FileData.SetSize((size_t)(FileSize));
            if(dwErrCode == ERROR_SUCCESS)
            {
                if(FileStream_Read(pStream, NULL, FileData.pbData, (DWORD)(FileData.cbData)))
                {
                    // Terminate the data with zero so various string-based functions can process it
                    FileData.pbData[FileData.cbData] = 0;
                }
                else
                {
                    dwErrCode = GetCascError();
                }
            }
            else
            {
                dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
            }
        }
        else
        {
            dwErrCode = ERROR_BAD_FORMAT;
        }

        // Close the file stream
        FileStream_Close(pStream);
    }
    else
    {
        dwErrCode = GetCascError();
    }
    
    return dwErrCode;
}

//-----------------------------------------------------------------------------
// Public CDN functions

LPCTSTR WINAPI CascCdnGetDefault()
{
    return szDefaultCDN;
}

LPBYTE WINAPI CascCdnDownload(LPCTSTR szCdnHostUrl, LPCTSTR szProduct, LPCTSTR szFileName, DWORD * PtrSize)
{
    CASC_PATH<TCHAR> LocalPath;
    CASC_BLOB FileData;
    LPBYTE pbFileData = NULL;
    size_t cbFileData = 0;
    DWORD dwErrCode;

    // Download the file
    dwErrCode = RibbitDownloadFile(szCdnHostUrl, szProduct, szFileName, LocalPath, FileData);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Create copy of the buffer
        if((pbFileData = CASC_ALLOC<BYTE>(FileData.cbData + 1)) != NULL)
        {
            memcpy(pbFileData, FileData.pbData, FileData.cbData);
            pbFileData[FileData.cbData] = 0;
            cbFileData = FileData.cbData;
        }
        else
        {
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Give the results
    if(dwErrCode != ERROR_SUCCESS)
        SetCascError(dwErrCode);
    if(PtrSize != NULL)
        PtrSize[0] = (DWORD)cbFileData;
    return pbFileData;
}

void WINAPI CascCdnFree(void * buffer)
{
    CASC_FREE(buffer);
}

