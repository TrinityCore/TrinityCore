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

//-----------------------------------------------------------------------------
// Structure definitions for CMF files

#define MAX_LINE_ELEMENTS   8

typedef struct _CMF_HEADER_V3
{
    DWORD BuildVersion;
    DWORD Unknown0;
    DWORD Unknown1;
    DWORD Unknown2;
    DWORD Unknown3;
    DWORD DataCount;
    DWORD Unknown4;
    DWORD EntryCount;
    DWORD Magic;
} CMF_HEADER_V3, *PCMF_HEADER_V3;

typedef struct _CMF_HEADER_V2
{
    DWORD BuildVersion;
    DWORD Unknown0;
    DWORD Unknown1;
    DWORD Unknown2;
    DWORD DataCount;
    DWORD Unknown3;
    DWORD EntryCount;
    DWORD Magic;
} CMF_HEADER_V2, *PCMF_HEADER_V2;

typedef struct _CMF_HEADER_V1
{
    DWORD BuildVersion;
    DWORD Unknown0;
    DWORD DataCount;
    DWORD Unknown1;
    DWORD EntryCount;
    DWORD Magic;
} CMF_HEADER_V1, *PCMF_HEADER_V1;

//-----------------------------------------------------------------------------
// Structure definitions for APM files

// In-memory format
typedef struct _APM_ENTRY
{
    DWORD     Index;
    ULONGLONG HashA;
    ULONGLONG HashB;
} APM_ENTRY, *PAPM_ENTRY;

// On-disk format, size = 0x14
typedef struct _APM_ENTRY_V2
{
    DWORD     Index;
    DWORD     HashA_Lo;                     // Must split the hashes in order to make this structure properly aligned
    DWORD     HashA_Hi;
    DWORD     HashB_Lo;
    DWORD     HashB_Hi;
} APM_ENTRY_V2, *PAPM_ENTRY_V2;

// On-disk format, size = 0x0C
typedef struct _APM_ENTRY_V1
{
    DWORD     Index;
    DWORD     HashA_Lo;                     // Must split the hashes in order to make this structure properly aligned
    DWORD     HashA_Hi;
} APM_ENTRY_V1, *PAPM_ENTRY_V1;

// In-memory format
typedef struct _APM_PACKAGE_ENTRY
{
    ULONGLONG PackageGUID;                  // 077 file
    ULONGLONG Unknown1;
    DWORD Unknown2;
    DWORD Unknown3;
    ULONGLONG Unknown4;
} APM_PACKAGE_ENTRY, *PAPM_PACKAGE_ENTRY;

// On-disk format
typedef struct _APM_PACKAGE_ENTRY_V2
{
    ULONGLONG PackageGUID;                  // 077 file
    ULONGLONG Unknown1;
    DWORD Unknown2;
    DWORD Unknown3;
    ULONGLONG Unknown4;
} APM_PACKAGE_ENTRY_V2, *PAPM_PACKAGE_ENTRY_V2;

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
} APM_PACKAGE_ENTRY_V1, *PAPM_PACKAGE_ENTRY_V1;

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

} APM_HEADER_V3, *PAPM_HEADER_V3;

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

} APM_HEADER_V2, *PAPM_HEADER_V2;

typedef struct _APM_HEADER_V1
{
    ULONGLONG BuildNumber;              // Build number of the game
    DWORD BuildVersion;
    DWORD PackageCount;
    DWORD EntryCount;
    DWORD Checksum;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

} APM_HEADER_V1, *PAPM_HEADER_V1;

//-----------------------------------------------------------------------------
// Handler classes

/*
struct TCmfFile
{
    TCmfFile()
    {
        memset(this, 0, sizeof(TCmfFile));
    }

    LPBYTE CaptureHeader(LPBYTE pbCmfData, LPBYTE pbCmfEnd)
    {
        DWORD BuildNumber = *(PDWORD)pbCmfData;

        // Check the newest header version
        if(BuildNumber >= 45104 && BuildNumber != 45214)
        {
            PCMF_HEADER_V3 pHeader3 = (PCMF_HEADER_V3)pbCmfData;
            
            if ((LPBYTE)(pHeader3 + 1) > pbCmfEnd)
                return NULL;

            BuildVersion = pHeader3->BuildVersion;
            DataCount = pHeader3->DataCount;
            EntryCount = pHeader3->EntryCount;
            Magic = pHeader3->Magic;
            return (LPBYTE)(pHeader3 + 1);
        }

        else if(BuildNumber >= 39028)
        {
            // TODO
            assert(false);
            return NULL;
        }

        else
        {
            // TODO
            assert(false);
            return NULL;
        }
    }

    DWORD BuildVersion;
    DWORD DataCount;
    DWORD EntryCount;
    DWORD Magic;
};

struct TApmFile
{
    TApmFile()
    {
        memset(this, 0, sizeof(TApmFile));
    }

    ~TApmFile()
    {
        CASC_FREE(pApmPackages);
        CASC_FREE(pApmEntries);
    }

    LPBYTE CaptureHeader(LPBYTE pbApmData, LPBYTE pbApmEnd)
    {
        // Check the data size for the largest possible header size
        if((pbApmData + sizeof(APM_HEADER_V3)) < pbApmEnd)
        {
            // Try the version 3
            PAPM_HEADER_V3 pApmFile3 = (PAPM_HEADER_V3)(pbApmData);
            if(pApmFile3->ZeroValue1 == 0 && pApmFile3->ZeroValue2 == 0 && pApmFile3->PackageCount && pApmFile3->EntryCount && pApmFile3->Checksum)
            {
                BuildNumber  = pApmFile3->BuildNumber;
                PackageCount = pApmFile3->PackageCount;
                EntryCount   = pApmFile3->EntryCount;
                Checksum     = pApmFile3->Checksum;
                return pbApmData + 0x24;
            }

            // Try the version 2
            PAPM_HEADER_V2 pApmFile2 = (PAPM_HEADER_V2)(pbApmData);
            if(pApmFile2->ZeroValue1 == 0 && pApmFile2->PackageCount && pApmFile2->EntryCount && pApmFile2->Checksum)
            {
                BuildNumber  = pApmFile2->BuildNumber;
                PackageCount = pApmFile2->PackageCount;
                EntryCount   = pApmFile2->EntryCount;
                Checksum     = pApmFile2->Checksum;
                return pbApmData + 0x20;
            }

            // Try the version 1 (build 24919)
            PAPM_HEADER_V1 pApmHeader1 = (PAPM_HEADER_V1)(pbApmData);
            if(pApmHeader1->BuildVersion != 0 && pApmHeader1->PackageCount && pApmHeader1->EntryCount && pApmHeader1->Checksum)
            {
                BuildNumber  = pApmHeader1->BuildNumber;
                PackageCount = pApmHeader1->PackageCount;
                EntryCount   = pApmHeader1->EntryCount;
                Checksum     = pApmHeader1->Checksum;
                return pbApmData + 0x18;
            }
        }

        return NULL;
    }

    LPBYTE CaptureArrayOfEntries(LPBYTE pbArrayOfEntries, LPBYTE pbApmEnd)
    {
        // Allocate array of entries
        pApmEntries = CASC_ALLOC<APM_ENTRY>(EntryCount);
        if(pApmEntries != NULL)
        {
            // The newest format
            if(BuildNumber > 45104 && BuildNumber != 45214)
            {
                PAPM_ENTRY_V2 pEntry2 = (PAPM_ENTRY_V2)pbArrayOfEntries;
                LPBYTE pbEntriesEnd = (LPBYTE)(pEntry2 + EntryCount);

                if(pbEntriesEnd <= pbApmEnd)
                {
                    for(DWORD i = 0; i < EntryCount; i++)
                    {
                        pApmEntries[i].Index = pEntry2->Index;
                        pApmEntries[i].HashA = MAKE_OFFSET64(pEntry2->HashA_Hi, pEntry2->HashA_Lo);
                        pApmEntries[i].HashB = MAKE_OFFSET64(pEntry2->HashB_Hi, pEntry2->HashB_Lo);
                    }

                    return pbEntriesEnd;
                }
            }
            else
            {
                PAPM_ENTRY_V1 pEntry1 = (PAPM_ENTRY_V1)pbArrayOfEntries;
                LPBYTE pbEntriesEnd = (LPBYTE)(pEntry1 + EntryCount);

                if(pbEntriesEnd <= pbApmEnd)
                {
                    for(DWORD i = 0; i < EntryCount; i++)
                    {
                        pApmEntries[i].Index = pEntry1->Index;
                        pApmEntries[i].HashA = MAKE_OFFSET64(pEntry1->HashA_Hi, pEntry1->HashA_Lo);
                        pApmEntries[i].HashB = 0;
                    }

                    return pbEntriesEnd;
                }
            }
        }

        return NULL;
    }

    LPBYTE CapturePackageEntries(LPBYTE pbArrayOfEntries, LPBYTE pbApmEnd)
    {
        // Allocate array of entries
        pApmPackages = CASC_ALLOC_ZERO<APM_PACKAGE_ENTRY>(PackageCount);
        if(pApmPackages != NULL)
        {
            // The newest format
            if(BuildNumber > 45104 && BuildNumber != 45214)
            {
                PAPM_PACKAGE_ENTRY_V2 pEntry2 = (PAPM_PACKAGE_ENTRY_V2)pbArrayOfEntries;
                LPBYTE pbEntriesEnd = (LPBYTE)(pEntry2 + PackageCount);

                if(pbEntriesEnd <= pbApmEnd)
                {
                    for(DWORD i = 0; i < PackageCount; i++)
                    {
                        pApmPackages[i].PackageGUID = pEntry2[i].PackageGUID;
                        pApmPackages[i].Unknown1 = pEntry2[i].Unknown1;
                        pApmPackages[i].Unknown2 = pEntry2[i].Unknown2;
                        pApmPackages[i].Unknown3 = pEntry2[i].Unknown3;
                        pApmPackages[i].Unknown4 = pEntry2[i].Unknown4;
                    }

                    return pbEntriesEnd;
                }
            }
            else
            {
                PAPM_PACKAGE_ENTRY_V1 pEntry1 = (PAPM_PACKAGE_ENTRY_V1)pbArrayOfEntries;
                LPBYTE pbEntriesEnd = (LPBYTE)(pEntry1 + PackageCount);

                if(pbEntriesEnd <= pbApmEnd)
                {
                    for(DWORD i = 0; i < PackageCount; i++)
                    {
                        // TODO!!!
                        pApmPackages[i].PackageGUID = pEntry1->PackageGUID;
                    }

                    return pbEntriesEnd;
                }
            }
        }

        return NULL;
    }

    PAPM_ENTRY pApmEntries;
    PAPM_PACKAGE_ENTRY pApmPackages;
    ULONGLONG BuildNumber;
    DWORD PackageCount;
    DWORD EntryCount;
    DWORD Checksum;
    size_t HeaderSize;

    // Followed by the array of APM_ENTRY (count is in "EntryCount")
    // Followed by the array of APM_PACKAGE (count is in "PackageCount")

};
*/

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
/*
    bool IsManifestFolderName(const char * szFileName, const char * szManifestFolder, size_t nLength)
    {
        if(!_strnicmp(szFileName, szManifestFolder, nLength))
        {
            return (szFileName[nLength] == '\\' || szFileName[nLength] == '/');
        }
        return false;
    }

    bool IsApmFileName(const char * szFileName)
    {
        const char * szExtension;

        if(IsManifestFolderName(szFileName, "Manifest", 8) || IsManifestFolderName(szFileName, "TactManifest", 12))
        {
            szExtension = GetFileExtension(szFileName);
            if(!_stricmp(szExtension, ".apm"))
            {
                return true;
            }
        }

        return false;
    }

    DWORD LoadApmFile(TCascStorage * hs, CONTENT_KEY & CKey, const char * szFileName)
    {
        TApmFile ApmFile;
        LPBYTE pbApmData;
        DWORD cbApmData = 0;
        DWORD dwErrCode = ERROR_BAD_FORMAT;

        pbApmData = LoadInternalFileToMemory(hs, CKey.Value, CASC_OPEN_BY_CKEY, &cbApmData);
        if(pbApmData != NULL)
        {
            LPBYTE pbApmEnd = pbApmData + cbApmData;
            LPBYTE pbApmPtr = pbApmData;
            
            pbApmPtr = ApmFile.CaptureHeader(pbApmPtr, pbApmEnd);
            if(pbApmPtr == NULL)
                return ERROR_BAD_FORMAT;

            // Read the array of entries
            pbApmPtr = ApmFile.CaptureArrayOfEntries(pbApmPtr, pbApmEnd);
            if(pbApmPtr == NULL)
                return ERROR_BAD_FORMAT;

            // Read the array of package entries
            pbApmPtr = ApmFile.CapturePackageEntries(pbApmPtr, pbApmEnd);
            if(pbApmPtr == NULL)
                return ERROR_BAD_FORMAT;

            CASC_FREE(pbApmData);
        }

        return dwErrCode;
    }

    static DWORD LoadCmfFile(TCascStorage * hs, CONTENT_KEY & CKey, const char * szFileName)
    {
        TCmfFile CmfFile;
        LPBYTE pbCmfData;
        DWORD cbCmfData = 0;
        DWORD dwErrCode = ERROR_BAD_FORMAT;

        pbCmfData = LoadInternalFileToMemory(hs, CKey.Value, CASC_OPEN_BY_CKEY, &cbCmfData);
        if(pbCmfData != NULL)
        {
            LPBYTE pbCmfEnd = pbCmfData + cbCmfData;
            LPBYTE pbCmfPtr = pbCmfData;

            // Capture the CMF header
            pbCmfPtr = CmfFile.CaptureHeader(pbCmfPtr, pbCmfEnd);
            if(pbCmfPtr == NULL)
                return ERROR_BAD_FORMAT;

//          if(CmfFile.Magic >= 0x636D6614)
//              DecryptCmfFile(

            CASC_FREE(pbCmfData);
        }

        return dwErrCode;
    }
*/
    int Load(TCascStorage * hs, CASC_CSV & Csv, size_t nFileNameIndex, size_t nCKeyIndex)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
//      size_t ApmFiles[0x80];
//      size_t nApmFiles = 0;
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

                        // If the file name is actually an asset, we need to parse that asset and load files in it
//                      if(IsApmFileName(szFileName))
//                      {
//                          ApmFiles[nApmFiles++] = FileTree_IndexOf(&pRootHandler->FileTree, pFileNode1);
//                      }
                    }
                }
            }
        }
/*
        // Load all CMF+APM files
        if(dwErrCode == ERROR_SUCCESS)
        {
            for(size_t i = 0; i < nApmFiles; i++)
            {
                char szApmFile[MAX_PATH + 1];
                char szCmfFile[MAX_PATH + 1];

                // Get the n-th item and its name
                pFileNode1 = (PCASC_FILE_NODE)FileTree_PathAt(&pRootHandler->FileTree, szApmFile, MAX_PATH, ApmFiles[i]);
                if(pFileNode1 == NULL)
                    break;

                if(strcmp(szApmFile, "TactManifest\\Win_SPWin_RDEV_LenUS_EExt.apm"))
                    continue;

                // Get the name of thew CMF file
                CascStrCopy(szCmfFile, _countof(szCmfFile), szApmFile);
                CascStrCopy((char *)GetFileExtension(szCmfFile), 5, ".cmf");
                pFileNode2 = (PCASC_FILE_NODE)FileTree_Find(&pRootHandler->FileTree, szCmfFile);
                if(pFileNode2 == NULL)
                    break;

                // Create the map of CMF entries
                dwErrCode = LoadCmfFile(hs, pFileNode2->CKey, szCmfFile);
                if(dwErrCode != ERROR_SUCCESS)
                    break;

            }
        }
*/
        return ERROR_SUCCESS;
    }
};

//-----------------------------------------------------------------------------
// Public functions

// TODO: There is way more files in the Overwatch CASC storage than present in the ROOT file.
DWORD RootHandler_CreateOverwatch(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_OW * pRootHandler = NULL;
    CASC_CSV Csv(0, true);
    size_t Indices[2];
    DWORD dwErrCode;

    // Load the ROOT file
    dwErrCode = Csv.Load(pbRootFile, cbRootFile);
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Retrieve the indices of the file name and MD5 columns
        Indices[0] = Csv.GetColumnIndex("FILENAME");
        Indices[1] = Csv.GetColumnIndex("MD5");

        // If both indices were found OK, then load the root file
        if(Indices[0] != CSV_INVALID_INDEX && Indices[1] != CSV_INVALID_INDEX)
        {
            pRootHandler = new TRootHandler_OW();
            if (pRootHandler != NULL)
            {
                // Load the root directory. If load failed, we free the object
                dwErrCode = pRootHandler->Load(hs, Csv, Indices[0], Indices[1]);
                if (dwErrCode != ERROR_SUCCESS)
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
