/*****************************************************************************/
/* CascRootFile_Text.cpp                  Copyright (c) Ladislav Zezula 2017 */
/*---------------------------------------------------------------------------*/
/* Support for loading ROOT files in plain text                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.10.15  1.00  Lad  The first version of CascRootFile_Text.cpp           */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

// Implemented in "overwatch/apm.cpp"
DWORD LoadApplicationPackageManifestFile(TCascStorage * hs, CASC_FILE_TREE & FileTree, PCASC_CKEY_ENTRY pCKeyEntry, const char * szApmFileName);

// Implemented in "overwatch/cmf.cpp"
DWORD LoadContentManifestFile(TCascStorage * hs, CASC_FILE_TREE & FileTree, PCASC_CKEY_ENTRY pCKeyEntry, const char * szFileName);

//-----------------------------------------------------------------------------
// Structure definitions for APM files

typedef struct _APM_HEADER_V3
{
    ULONGLONG BuildNumber;              // Build number of the game
    ULONGLONG ZeroValue1;
    DWORD ZeroValue2;
    DWORD PackageCount;
    DWORD ZeroValue3;
    DWORD EntryCount;
    DWORD Checksum;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} APM_HEADER_V3, * PAPM_HEADER_V3;

typedef struct _APM_HEADER_V2
{
    ULONGLONG BuildNumber;              // Build number of the game
    ULONGLONG ZeroValue1;
    DWORD PackageCount;
    DWORD ZeroValue2;
    DWORD EntryCount;
    DWORD Checksum;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} APM_HEADER_V2, * PAPM_HEADER_V2;

typedef struct _APM_HEADER_V1
{
    ULONGLONG BuildNumber;              // Build number of the game
    DWORD BuildVersion;
    DWORD PackageCount;
    DWORD EntryCount;
    DWORD Checksum;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} APM_HEADER_V1, * PAPM_HEADER_V1;

// On-disk format, size = 0x0C
typedef struct _APM_ENTRY_V1
{
    DWORD     Index;
    DWORD     HashA_Lo;                     // Must split the hashes in order to make this structure properly aligned
    DWORD     HashA_Hi;
} APM_ENTRY_V1, * PAPM_ENTRY_V1;

// On-disk format, size = 0x14
typedef struct _APM_ENTRY_V2
{
    DWORD     Index;
    DWORD     HashA_Lo;                     // Must split the hashes in order to make this structure properly aligned
    DWORD     HashA_Hi;
    DWORD     HashB_Lo;
    DWORD     HashB_Hi;
} APM_ENTRY_V2, *PAPM_ENTRY_V2;

// On-disk format
typedef struct _APM_PACKAGE_ENTRY_V1
{
    ULONGLONG EntryPointGUID;               // virtual most likely
    ULONGLONG PrimaryGUID;                  // real
    ULONGLONG SecondaryGUID;                // real
    ULONGLONG Key;                          // encryption
    ULONGLONG PackageGUID;                  // 077 file
    ULONGLONG Unknown1;
    DWORD Unknown2;
} APM_PACKAGE_ENTRY_V1, * PAPM_PACKAGE_ENTRY_V1;

// On-disk format
typedef struct _APM_PACKAGE_ENTRY_V2
{
    ULONGLONG PackageGUID;                  // 077 file
    ULONGLONG Unknown1;
    DWORD Unknown2;
    DWORD Unknown3;
    ULONGLONG Unknown4;
} APM_PACKAGE_ENTRY_V2, *PAPM_PACKAGE_ENTRY_V2;

//-----------------------------------------------------------------------------
// Local functions (non-class)

static bool IsManifestFolderName(const char * szFileName, const char * szManifestFolder, size_t nLength)
{
    if(!_strnicmp(szFileName, szManifestFolder, nLength))
    {
        return (szFileName[nLength] == '\\' || szFileName[nLength] == '/');
    }
    return false;
}

//-----------------------------------------------------------------------------
// Public functions (non-class)

static void BinaryReverse64(LPBYTE GuidReversed, LPBYTE pbGuid)
{
    GuidReversed[0] = pbGuid[7];
    GuidReversed[1] = pbGuid[6];
    GuidReversed[2] = pbGuid[5];
    GuidReversed[3] = pbGuid[4];
    GuidReversed[4] = pbGuid[3];
    GuidReversed[5] = pbGuid[2];
    GuidReversed[6] = pbGuid[1];
    GuidReversed[7] = pbGuid[0];
}

static const char * ExtractAssetSubString(char * szBuffer, size_t ccBuffer, const char * szPlainName)
{
    char * szBufferEnd = szBuffer + ccBuffer - 1;

    while(szBuffer < szBufferEnd && szPlainName[0] != 0 && szPlainName[0] != '.' && szPlainName[0] != '_')
        *szBuffer++ = *szPlainName++;

    if(szBuffer <= szBufferEnd)
        szBuffer[0] = 0;
    return szPlainName;
}

static const char * AppendAssetSubString(char * szBuffer, size_t ccBuffer, const char * szPlainName)
{
    char * szBufferPtr = szBuffer + strlen(szBuffer);
    char * szBufferEnd = szBuffer + ccBuffer - 1;

    if(szBufferPtr < szBufferEnd)
        *szBufferPtr++ = '-';

    while(szBufferPtr < szBufferEnd && szPlainName[0] != '_')
        *szBufferPtr++ = *szPlainName++;

    szBufferPtr[0] = 0;
    return szPlainName;
}

size_t BuildAssetFileNameTemplate(
    char * szNameTemplate,
    size_t ccNameTemplate,
    const char * szPrefix,
    const char * szAssetName)
{
    const char * szFileName = "0000000000000000";           // Base name for 64-bit GUID
    const char * szFileExt = NULL;
    char * szBufferEnd = szNameTemplate + ccNameTemplate;
    char * szBufferPtr = szNameTemplate;
    char * szPlainName;
    char szPlatform[64] = {0};
    char szLocale[64] = {0};
    char szAsset[64] = {0};

    // Parse the plain name
    while(szAssetName[0] != '.')
    {
        // Watch start of the new field
        if(szAssetName[0] == '_')
        {
            // Extract platform from "_SP"
            if(szAssetName[1] == 'S' && szAssetName[2] == 'P' && !_strnicmp(szAssetName, "_SPWin_", 7))
            {
                CascStrCopy(szPlatform, _countof(szPlatform), "Windows");
                szAssetName += 6;
                continue;
            }

            // Extract "RDEV" or "RCN"
            if(szAssetName[1] == 'R')
            {
                szAssetName = AppendAssetSubString(szPlatform, _countof(szPlatform), szAssetName + 1);
                continue;
            }

            // Extract locale
            if(szAssetName[1] == 'L')
            {
                szAssetName = ExtractAssetSubString(szLocale, _countof(szLocale), szAssetName + 2);
                continue;
            }

            // Ignore "_EExt"
            if(szAssetName[1] == 'E' && szAssetName[2] == 'E')
            {
                szAssetName += 5;
                continue;
            }

            // Extract the asset name
            szAssetName = ExtractAssetSubString(szAsset, _countof(szAsset), szAssetName + 1);

            // Extract a possible extension
            //if(!_stricmp(szAsset, "speech"))
            //    szFileExt = ".wav";
            //if(!_stricmp(szAsset, "text"))
            //    szFileExt = ".text";
            continue;
        }
        szAssetName++;
    }

    // Combine the path like "%PREFIX%\\%PLATFORM%-%DEV%\\%LOCALE%\\%ASSET%\\%PLAIN_NAME%.%EXTENSSION%"
    if(szPrefix && szPrefix[0])
        szBufferPtr += CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s\\", szPrefix);
    if(szPlatform[0])
        szBufferPtr += CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s\\", szPlatform);
    if(szLocale[0])
        szBufferPtr += CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s\\", szLocale);
    if(szAsset[0])
        szBufferPtr += CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s\\", szAsset);
    szPlainName = szBufferPtr;

    // Append file name and extension
    if(szFileName && szFileName[0])
        szBufferPtr += CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s", szFileName);
    if(szFileExt && szFileExt[0])
        CascStrPrintf(szBufferPtr, (szBufferEnd - szBufferPtr), "%s", szFileExt);

    // Return the length of the path
    return (szPlainName - szNameTemplate);
}

DWORD InsertAssetFile(
    TCascStorage * hs,
    CASC_FILE_TREE & FileTree,
    char * szFileName,
    size_t nPlainName,              // Offset of the plain name in the name template
    LPBYTE pbCKey,
    LPBYTE pbGuid)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    DWORD dwErrCode = ERROR_SUCCESS;
    BYTE GuidReversed[8];

    // Try to find the CKey
    if((pCKeyEntry = FindCKeyEntry_CKey(hs, pbCKey)) != NULL)
    {
        // Save the character at the end of the name (dot or EOS)
        char chSaveChar = szFileName[nPlainName + 16];

        // Imprint the GUID as binary value
        BinaryReverse64(GuidReversed, pbGuid);
        StringFromBinary(GuidReversed, sizeof(GuidReversed), szFileName + nPlainName);
        szFileName[nPlainName + 16] = chSaveChar;

        // Insert the asset to the file tree
        if(FileTree.InsertByName(pCKeyEntry, szFileName) == NULL)
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
    }
    return dwErrCode;
}

//-----------------------------------------------------------------------------
// Handler definition for OVERWATCH root file
//
// -------------------------------------
// Overwatch ROOT file (build 24919):
// -------------------------------------
// #MD5|CHUNK_ID|FILENAME|INSTALLPATH
// FE3AD8A77EEF77B383DF4929AED816FD|0|RetailClient/GameClientApp.exe|GameClientApp.exe
// 5EDDEFECA544B6472C5CD52BE63BC02F|0|RetailClient/Overwatch Launcher.exe|Overwatch Launcher.exe
// 6DE09F0A67F33F874F2DD8E2AA3B7AAC|0|RetailClient/ca-bundle.crt|ca-bundle.crt
// 99FE9EB6A4BB20209202F8C7884859D9|0|RetailClient/ortp_x64.dll|ortp_x64.dll
//
// -------------------------------------
// Overwatch ROOT file (build 47161):
// -------------------------------------
// #FILEID|MD5|CHUNK_ID|PRIORITY|MPRIORITY|FILENAME|INSTALLPATH
// RetailClient/Overwatch.exe|807F96661280C07E762A8C129FEBDA6F|0|0|255|RetailClient/Overwatch.exe|Overwatch.exe
// RetailClient/Overwatch Launcher.exe|5EDDEFECA544B6472C5CD52BE63BC02F|0|0|255|RetailClient/Overwatch Launcher.exe|Overwatch Launcher.exe
// RetailClient/ortp_x64.dll|7D1B5DEC267480F3E8DAD6B95143A59C|0|0|255|RetailClient/ortp_x64.dll|ortp_x64.dll
//

struct TRootHandler_OW : public TFileTreeRoot
{
    TRootHandler_OW() : TFileTreeRoot(0)
    {
        // We have file names and return CKey as result of search
        dwFeatures |= (CASC_FEATURE_FILE_NAMES | CASC_FEATURE_ROOT_CKEY);
    }

    DWORD Load(TCascStorage * hs, CASC_CSV & Csv, size_t nFileNameIndex, size_t nCKeyIndex)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        size_t nFileCount;
        DWORD dwErrCode = ERROR_SUCCESS;
        BYTE CKey[MD5_HASH_SIZE];

        CASCLIB_UNUSED(hs);

        // Keep loading every line until there is something
        while(Csv.LoadNextLine())
        {
            const CASC_CSV_COLUMN & FileName = Csv[CSV_ZERO][nFileNameIndex];
            const CASC_CSV_COLUMN & CKeyStr = Csv[CSV_ZERO][nCKeyIndex];

            // Retrieve the file name and the content key
            if(FileName.szValue && CKeyStr.szValue && CKeyStr.nLength == MD5_STRING_SIZE)
            {
                // Convert the string CKey to binary
                if(BinaryFromString(CKeyStr.szValue, MD5_STRING_SIZE, CKey) == ERROR_SUCCESS)
                {
                    // Find the item in the tree
                    if((pCKeyEntry = FindCKeyEntry_CKey(hs, CKey)) != NULL)
                    {
                        // Insert the file name and the CKey into the tree
                        FileTree.InsertByName(pCKeyEntry, FileName.szValue);
                    }
                }
            }
        }

        // Get the total file count that we loaded so far
        nFileCount = FileTree.GetCount();

        // Parse Content Manifest Files (.cmf)
        for(size_t i = 0; i < nFileCount && dwErrCode == ERROR_SUCCESS; i++)
        {
            PCASC_FILE_NODE pFileNode;
            const char * szExtension;
            char szFileName[MAX_PATH];

            // Get the n-th file
            pFileNode = (PCASC_FILE_NODE)FileTree.PathAt(szFileName, _countof(szFileName), i);
            if(pFileNode != NULL)
            {
                if(IsManifestFolderName(szFileName, "Manifest", 8) || IsManifestFolderName(szFileName, "TactManifest", 12))
                {
                    // Retrieve the file extension
                    szExtension = GetFileExtension(szFileName);

                    // Check for content manifest files
                    if(!_stricmp(szExtension, ".cmf"))
                    {
                        dwErrCode = LoadContentManifestFile(hs, FileTree, pFileNode->pCKeyEntry, szFileName);
                    }
                    else if(!_stricmp(szExtension, ".apm"))
                    {
                        dwErrCode = LoadApplicationPackageManifestFile(hs, FileTree, pFileNode->pCKeyEntry, szFileName);
                    }
                }
            }
        }
        return dwErrCode;
    }
};

//-----------------------------------------------------------------------------
// Public functions

// TODO: There is way more files in the Overwatch CASC storage than present in the ROOT file.
DWORD RootHandler_CreateOverwatch(TCascStorage * hs, CASC_BLOB & RootFile)
{
    TRootHandler_OW * pRootHandler = NULL;
    CASC_CSV Csv(0, true);
    size_t Indices[2];
    DWORD dwErrCode;

    // Load the ROOT file
    dwErrCode = Csv.Load(RootFile.pbData, RootFile.cbData);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Retrieve the indices of the file name and MD5 columns
        Indices[0] = Csv.GetColumnIndex("FILENAME");
        Indices[1] = Csv.GetColumnIndex("MD5");

        // If both indices were found OK, then load the root file
        if(Indices[0] != CSV_INVALID_INDEX && Indices[1] != CSV_INVALID_INDEX)
        {
            pRootHandler = new TRootHandler_OW();
            if(pRootHandler != NULL)
            {
                // Load the root directory. If load failed, we free the object
                dwErrCode = pRootHandler->Load(hs, Csv, Indices[0], Indices[1]);
                if(dwErrCode != ERROR_SUCCESS)
                {
                    delete pRootHandler;
                    pRootHandler = NULL;
                }
            }
        }
        else
        {
            dwErrCode = ERROR_BAD_FORMAT;
        }
    }

    // Assign the root directory (or NULL) and return error
    hs->pRootHandler = pRootHandler;
    return dwErrCode;
}
