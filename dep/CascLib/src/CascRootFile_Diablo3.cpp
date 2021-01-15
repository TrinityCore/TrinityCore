/*****************************************************************************/
/* CascRootFile_Diablo3.cpp               Copyright (c) Ladislav Zezula 2015 */
/*---------------------------------------------------------------------------*/
/* Support for loading Diablo 3 ROOT file                                    */
/* Note: D3 offsets refer to Diablo III.exe 2.2.0.30013 (32-bit)             */
/* SHA1: e4f17eca8aad8dde70870bf932ac3f5b85f17a1f                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 04.03.15  1.00  Lad  The first version of CascRootFile_Diablo3.cpp        */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local structures

#define DIABLO3_SUBDIR_SIGNATURE   0xEAF1FE87
#define DIABLO3_PACKAGES_SIGNATURE 0xAABB0002
#define DIABLO3_MAX_SUBDIRS        0x20
#define DIABLO3_MAX_ASSETS         70               // Maximum possible number of assets
#define DIABLO3_MAX_ROOT_FOLDERS   0x20             // Maximum count of root directory named entries

// On-disk structure for a file given by file number
typedef struct _DIABLO3_ASSET_ENTRY
{
    CONTENT_KEY CKey;                              // Content key for the file
    DWORD FileIndex;                               // File index
} DIABLO3_ASSET_ENTRY, *PDIABLO3_ASSET_ENTRY;

// On-disk structure for a file given by file number and suffix
typedef struct _DIABLO3_ASSETIDX_ENTRY
{
    CONTENT_KEY CKey;                              // Content key for the file
    DWORD FileIndex;                               // File index
    DWORD SubIndex;                                // File subindex, like "SoundBank\3D Ambience\0000.smp"
} DIABLO3_ASSETIDX_ENTRY, *PDIABLO3_ASSETIDX_ENTRY;

// In-memory structure of the named entry
typedef struct _DIABLO3_NAMED_ENTRY
{
    PCONTENT_KEY pCKey;                             // Pointer to the content key
    const char * szFileName;                        // Pointer to the zero-terminated file name
    const char * szFileEnd;                         // Position of the zero terminator (aka end of the file name)
} DIABLO3_NAMED_ENTRY, *PDIABLO3_NAMED_ENTRY;

// On-disk structure of CoreToc.dat header
typedef struct _DIABLO3_CORE_TOC_HEADER
{
    DWORD EntryCounts[DIABLO3_MAX_ASSETS];          // Array of number of entries (files) for each asset
    DWORD EntryOffsets[DIABLO3_MAX_ASSETS];         // Array of offsets of each DIABLO3_CORE_TOC_ENTRY, relative to data after header
    DWORD Unknowns[DIABLO3_MAX_ASSETS];             // Unknown
    DWORD Alignment;
} DIABLO3_CORE_TOC_HEADER, *PDIABLO3_CORE_TOC_HEADER;

// On-disk structure of the entry in CoreToc.dat
typedef struct _DIABLO3_CORE_TOC_ENTRY
{
    DWORD AssetIndex;                               // Index of the Diablo3 asset (aka directory)
    DWORD FileIndex;                                // File index
    DWORD NameOffset;                               // Offset of the plain file name

} DIABLO3_CORE_TOC_ENTRY, *PDIABLO3_CORE_TOC_ENTRY;

// In-memory structure of parsed directory data
typedef struct _DIABLO3_DIRECTORY
{
    LPBYTE pbDirectoryData;                         // The begin of the directory data block
    LPBYTE pbDirectoryEnd;                          // The end of the directory data block
    LPBYTE pbAssetEntries;                          // Pointer to asset entries without subitem number. Example: "SoundBank\SoundFile.smp"
    LPBYTE pbAssetIdxEntries;                       // Pointer to asset entries with subitem number
    LPBYTE pbNamedEntries;                          // Pointer to named entries. These are for files with arbitrary names, and they do not belong to an asset
    DWORD dwAssetEntries;                           // Number of asset entries without subitem number
    DWORD dwAssetIdxEntries;
    DWORD dwNamedEntries;
    DWORD dwNodeIndex;                              // Index of file node for this folder
} DIABLO3_DIRECTORY, *PDIABLO3_DIRECTORY;

// Structure for conversion DirectoryID -> Directory name
typedef struct _DIABLO3_ASSET_INFO
{
    const char * szDirectoryName;                   // Directory name
    const char * szExtension;

} DIABLO3_ASSET_INFO;
typedef const DIABLO3_ASSET_INFO * PDIABLO3_ASSET_INFO;

//-----------------------------------------------------------------------------
// Local variables

static const DIABLO3_ASSET_INFO Assets[] =
{
//   DIR-NAME               EXTENSION
//   ==========             =========
    {NULL,                  NULL},         // 0x00
    {"Actor",               "acr"},        // 0x01
    {"Adventure",           "adv"},        // 0x02
    {NULL,                  NULL},         // 0x03
    {NULL,                  NULL},         // 0x04
    {"AmbientSound",        "ams"},        // 0x05
    {"Anim",                "ani"},        // 0x06
    {"Anim2D",              "an2"},        // 0x07
    {"AnimSet",             "ans"},        // 0x08
    {"Appearance",          "app"},        // 0x09
    {NULL,                  NULL},         // 0x0A
    {"Cloth",               "clt"},        // 0x0B
    {"Conversation",        "cnv"},        // 0x0C
    {NULL,                  NULL},         // 0x0D
    {"EffectGroup",         "efg"},        // 0x0E
    {"Encounter",           "enc"},        // 0x0F
    {NULL,                  NULL},         // 0x10
    {"Explosion",           "xpl"},        // 0x11
    {NULL,                  NULL},         // 0x12
    {"Font",                "fnt"},        // 0x13
    {"GameBalance",         "gam"},        // 0x14
    {"Globals",             "glo"},        // 0x15
    {"LevelArea",           "lvl"},        // 0x16
    {"Light",               "lit"},        // 0x17
    {"MarkerSet",           "mrk"},        // 0x18
    {"Monster",             "mon"},        // 0x19
    {"Observer",            "obs"},        // 0x1A
    {"Particle",            "prt"},        // 0x1B
    {"Physics",             "phy"},        // 0x1C
    {"Power",               "pow"},        // 0x1D
    {NULL,                  NULL},         // 0x1E
    {"Quest",               "qst"},        // 0x1F
    {"Rope",                "rop"},        // 0x20
    {"Scene",               "scn"},        // 0x21
    {"SceneGroup",          "scg"},        // 0x22
    {NULL,                  NULL},         // 0x23
    {"ShaderMap",           "shm"},        // 0x24
    {"Shaders",             "shd"},        // 0x25
    {"Shakes",              "shk"},        // 0x26
    {"SkillKit",            "skl"},        // 0x27
    {"Sound",               "snd"},        // 0x28
    {"SoundBank",           "sbk"},        // 0x29
    {"StringList",          "stl"},        // 0x2A
    {"Surface",             "srf"},        // 0x2B
    {"Textures",            "tex"},        // 0x2C
    {"Trail",               "trl"},        // 0x2D
    {"UI",                  "ui"},         // 0x2E
    {"Weather",             "wth"},        // 0x2F
    {"Worlds",              "wrl"},        // 0x30
    {"Recipe",              "rcp"},        // 0x31
    {NULL,                  NULL},         // 0x32
    {"Condition",           "cnd"},        // 0x33
    {NULL,                  NULL},         // 0x34
    {NULL,                  NULL},         // 0x35
    {NULL,                  NULL},         // 0x36
    {NULL,                  NULL},         // 0x37
    {"Act",                 "act"},        // 0x38
    {"Material",            "mat"},        // 0x39
    {"QuestRange",          "qsr"},        // 0x3A
    {"Lore",                "lor"},        // 0x3B
    {"Reverb",              "rev"},        // 0x3C
    {"PhysMesh",            "phm"},        // 0x3D
    {"Music",               "mus"},        // 0x3E
    {"Tutorial",            "tut"},        // 0x3F
    {"BossEncounter",       "bos"},        // 0x40
    {NULL,                  NULL},         // 0x41
    {"Accolade",            "aco"},        // 0x42
};

#define DIABLO3_ASSET_COUNT (sizeof(Assets) / sizeof(Assets[0]))

//-----------------------------------------------------------------------------
// Handler definitions for Diablo3 root file

struct TDiabloRoot : public TFileTreeRoot
{
    public:

    TDiabloRoot() : TFileTreeRoot(0)
    {
        memset(RootFolders, 0, sizeof(RootFolders));
        pFileIndices = NULL;
        pbCoreTocFile = NULL;
        pbCoreTocData = NULL;
        nFileIndices = 0;
        cbCoreTocFile = 0;

        // Map for searching a real file extension
        memset(&PackagesMap, 0, sizeof(CASC_MAP));
        pbPackagesDat = NULL;
        cbPackagesDat = 0;

        // We have file names and return CKey as result of search
        dwFeatures |= (CASC_FEATURE_FILE_NAMES | CASC_FEATURE_ROOT_CKEY);
    }

    ~TDiabloRoot()
    {
        FreeLoadingStuff();
    }

    PDIABLO3_ASSET_INFO GetAssetInfo(DWORD dwAssetIndex)
    {
        if(dwAssetIndex < DIABLO3_ASSET_COUNT && Assets[dwAssetIndex].szDirectoryName != NULL)
            return &Assets[dwAssetIndex];
        return NULL;
    }

    char * FindPackageName(const char * szAssetName, const char * szPlainName)
    {
        char szFileName[MAX_PATH+1];
        size_t nLength;

        // Construct the name without extension and find it in the map
        nLength = CascStrPrintf(szFileName, _countof(szFileName), "%s\\%s", szAssetName, szPlainName);
        return (char *)PackagesMap.FindString(szFileName, szFileName + nLength);
    }

    LPBYTE LoadFileToMemory(TCascStorage * hs, const char * szFileName, DWORD * pcbFileData)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        LPBYTE pbFileData = NULL;

        // Try to find CKey for the file
        pCKeyEntry = GetFile(hs, szFileName);
        if(pCKeyEntry != NULL)
            pbFileData = LoadInternalFileToMemory(hs, pCKeyEntry, pcbFileData);

        return pbFileData;
    }

    static LPBYTE CaptureDirectoryData(
        DIABLO3_DIRECTORY & DirHeader,
        LPBYTE pbDirectory,
        DWORD cbDirectory)
    {
        LPBYTE pbDirectoryData = pbDirectory;
        LPBYTE pbDataEnd = pbDirectory + cbDirectory;
        DWORD Signature = 0;

        //
        // Structure of a Diablo3 directory header
        // 1) Signature (4 bytes)
        // 2) Number of DIABLO3_ASSET_ENTRY entries (4 bytes)
        // 3) Array of DIABLO3_ASSET_ENTRY entries
        // 4) Number of DIABLO3_ASSETIDX_ENTRY entries (4 bytes)
        // 5) Array of DIABLO3_ASSETIDX_ENTRY entries
        // 6) Number of DIABLO3_NAMED_ENTRY entries (4 bytes)
        // 7) Array of DIABLO3_NAMED_ENTRY entries
        //

        // Prepare the header signature
        memset(&DirHeader, 0, sizeof(DIABLO3_DIRECTORY));

        // Get the header signature
        pbDirectory = CaptureInteger32(pbDirectory, pbDataEnd, &Signature);
        if((pbDirectory == NULL) || (Signature != CASC_DIABLO3_ROOT_SIGNATURE && Signature != DIABLO3_SUBDIR_SIGNATURE))
            return NULL;

        // Subdirectories have extra two arrays
        if(Signature == DIABLO3_SUBDIR_SIGNATURE)
        {
            // Capture the number of DIABLO3_ASSET_ENTRY items
            pbDirectory = CaptureInteger32(pbDirectory, pbDataEnd, &DirHeader.dwAssetEntries);
            if(pbDirectory == NULL)
                return NULL;

            // Capture the array of DIABLO3_ASSET_ENTRY
            pbDirectory = CaptureArray(pbDirectory, pbDataEnd, &DirHeader.pbAssetEntries, DIABLO3_ASSET_ENTRY, DirHeader.dwAssetEntries);
            if(pbDirectory == NULL)
                return NULL;

            // Capture the number of DIABLO3_ASSETIDX_ENTRY items
            pbDirectory = CaptureInteger32(pbDirectory, pbDataEnd, &DirHeader.dwAssetIdxEntries);
            if(pbDirectory == NULL)
                return NULL;

            // Capture the array of DIABLO3_ASSETIDX_ENTRY
            pbDirectory = CaptureArray(pbDirectory, pbDataEnd, &DirHeader.pbAssetIdxEntries, DIABLO3_ASSETIDX_ENTRY, DirHeader.dwAssetIdxEntries);
            if(pbDirectory == NULL)
                return NULL;
        }

        // Capture the number of DIABLO3_NAMED_ENTRY array
        pbDirectory = CaptureInteger32(pbDirectory, pbDataEnd, &DirHeader.dwNamedEntries);
        if(pbDirectory == NULL)
            return NULL;

        // Note: Do not capture the array here. We will do that later,
        // when we will be parsing the directory
        DirHeader.pbNamedEntries = pbDirectory;

        // Put the directory range
        DirHeader.pbDirectoryData = pbDirectoryData;
        DirHeader.pbDirectoryEnd = pbDirectoryData + cbDirectory;
        return pbDirectory;
    }

    LPBYTE CaptureCoreTocHeader(
        PDIABLO3_CORE_TOC_HEADER * PtrHeader,
        PDWORD PtrMaxIndex,
        LPBYTE pbDataPtr,
        LPBYTE pbDataEnd)
    {
        PDIABLO3_CORE_TOC_HEADER pTocHeader = (PDIABLO3_CORE_TOC_HEADER)pbDataPtr;
        DWORD dwMaxFileIndex = 0;

        // Check the space for header
        if((pbDataPtr + sizeof(DIABLO3_CORE_TOC_HEADER)) > pbDataEnd)
            return NULL;
        pbDataPtr += sizeof(DIABLO3_CORE_TOC_HEADER);

        // Verify all asset arrays
        for(size_t i = 0; i < DIABLO3_MAX_ASSETS; i++)
        {
            PDIABLO3_CORE_TOC_ENTRY pTocEntry = (PDIABLO3_CORE_TOC_ENTRY)(pbDataPtr + pTocHeader->EntryOffsets[i]);
            DWORD EntryOffset = pTocHeader->EntryOffsets[i];
            DWORD EntryCount = pTocHeader->EntryCounts[i];

            // Verify file range
            if((pbDataPtr + EntryOffset + EntryCount * sizeof(DIABLO3_CORE_TOC_ENTRY)) > pbDataEnd)
                return NULL;

            // Find out the entry with the maximum index
            for(DWORD n = 0; n < EntryCount; n++)
            {
                if(pTocEntry->FileIndex >= dwMaxFileIndex)
                    dwMaxFileIndex = pTocEntry->FileIndex;
                pTocEntry++;
            }
        }

        // Give data and return
        PtrMaxIndex[0] = dwMaxFileIndex;
        PtrHeader[0] = pTocHeader;
        return pbDataPtr;
    }

    LPBYTE CaptureNamedEntry(
        LPBYTE pbDataPtr,
        LPBYTE pbDataEnd,
        PDIABLO3_NAMED_ENTRY pEntry)
    {
        // Capture the content key
        pbDataPtr = CaptureContentKey(pbDataPtr, pbDataEnd, &pEntry->pCKey);
        if(pbDataPtr == NULL)
            return NULL;

        // Capture file name. Must be ASCIIZ file name
        pEntry->szFileName = (const char *)pbDataPtr;
        while(pbDataPtr < pbDataEnd && pbDataPtr[0] != 0)
            pbDataPtr++;

        // Did we find a zero char?
        if(pbDataPtr < pbDataEnd && pbDataPtr[0] == 0)
        {
            pEntry->szFileEnd = (const char *)pbDataPtr;
            return pbDataPtr + 1;
        }

        return NULL;
    }

    int LoadDirectoryFile(TCascStorage * hs, DIABLO3_DIRECTORY & DirHeader, PCASC_CKEY_ENTRY pCKeyEntry)
    {
        LPBYTE pbData;
        DWORD cbData = 0;

        // Load the n-th folder
        pbData = LoadInternalFileToMemory(hs, pCKeyEntry, &cbData);
        if(pbData && cbData)
        {
            if(CaptureDirectoryData(DirHeader, pbData, cbData) == NULL)
            {
                // Clear the directory
                CASC_FREE(pbData);
                return ERROR_BAD_FORMAT;
            }
        }
        return ERROR_SUCCESS;
    }

    bool CreateAssetFileName(
        CASC_PATH<char> & PathBuffer,
        DWORD FileIndex,
        DWORD SubIndex)
    {
        PDIABLO3_CORE_TOC_ENTRY pTocEntry;
        PDIABLO3_ASSET_INFO pAssetInfo;
        LPCSTR szPackageName = NULL;
        LPCSTR szPlainName;
        LPCSTR szFormat;
        char szBuffer[MAX_PATH];

        // Find and check the entry
        pTocEntry = pFileIndices + FileIndex;
        if(pTocEntry->FileIndex == FileIndex)
        {
            // Retrieve the asset information
            szPlainName = (LPCSTR)(pbCoreTocData + pTocEntry->NameOffset);
            pAssetInfo = GetAssetInfo(pTocEntry->AssetIndex);

            // Construct the file name, up to the extension. Don't include the '.'
            szFormat = (SubIndex != CASC_INVALID_INDEX) ? "%s\\%04u" : "%s";
            CascStrPrintf(szBuffer, _countof(szBuffer), szFormat, szPlainName, SubIndex);

            // Try to fixup the file extension from the package name.
            // File extensions are not predictable because for subitems,
            // they are not always equal to the main items:
            //
            //  SoundBank\3D Ambience.sbk
            //  SoundBank\3D Ambience\0000.smp
            //  SoundBank\3D Ambience\0002.smp
            //  ...
            //  SoundBank\Angel.sbk
            //  SoundBank\Angel\0000.fsb
            //  SoundBank\Angel\0002.fsb
            //
            // We use the Base\Data_D3\PC\Misc\Packages.dat for real file extensions, where possible
            //

            if(pAssetInfo != NULL)
            {
                // Retrieve the asset name
                szPackageName = FindPackageName(pAssetInfo->szDirectoryName, szBuffer);
                if(szPackageName != NULL)
                {
                    PathBuffer.AppendString(szPackageName, false);
                    return true;
                }

                // Append the directory name
                PathBuffer.AppendString(pAssetInfo->szDirectoryName, false);
            }
            else
            {
                // Append generic name "Asset##" and continue
                PathBuffer.AppendString("Asset", false);
                PathBuffer.AppendChar((char)('0' + (pTocEntry->AssetIndex / 10)));
                PathBuffer.AppendChar((char)('0' + (pTocEntry->AssetIndex % 10)));
            }

            // Append the content of the buffer
            PathBuffer.AppendString(szBuffer, true);

            // If we have an extension, use it. Otherwise, supply "a##"
            if(pAssetInfo != NULL && pAssetInfo->szExtension != NULL)
            {
                PathBuffer.AppendChar('.');
                PathBuffer.AppendString(pAssetInfo->szExtension, false);
            }
            else
            {
                CascStrPrintf(szBuffer, _countof(szBuffer), ".a%02u", pTocEntry->AssetIndex);
                PathBuffer.AppendString(szBuffer, false);
            }
            return true;
        }

        return false;
    }

    // Parse the asset entries
    DWORD ParseAssetEntries(
        TCascStorage * hs,
        DIABLO3_DIRECTORY & Directory,
        CASC_PATH<char> & PathBuffer)
    {
        PDIABLO3_ASSET_ENTRY pEntry = (PDIABLO3_ASSET_ENTRY)Directory.pbAssetEntries;
        PCASC_CKEY_ENTRY pCKeyEntry;
        size_t nSavePos = PathBuffer.Save();
        DWORD dwEntries = Directory.dwAssetEntries;

        // Do nothing if there is no entries
        if(pEntry != NULL && dwEntries != 0)
        {
            // Insert all asset entries to the file tree
            for(DWORD i = 0; i < dwEntries; i++, pEntry++)
            {
                pCKeyEntry = FindCKeyEntry_CKey(hs, pEntry->CKey.Value);
                if(pCKeyEntry != NULL)
                {
                    // Construct the full path name of the entry
                    if(CreateAssetFileName(PathBuffer, pEntry->FileIndex, CASC_INVALID_INDEX))
                    {
                        // Insert the entry to the file tree
                        FileTree.InsertByName(pCKeyEntry, PathBuffer);
                    }

                    // Restore the path buffer position
                    PathBuffer.Restore(nSavePos);
                }
            }
        }

        return ERROR_SUCCESS;
    }

    DWORD ParseAssetAndIdxEntries(
        TCascStorage * hs,
        DIABLO3_DIRECTORY & Directory,
        CASC_PATH<char> & PathBuffer)
    {
        PDIABLO3_ASSETIDX_ENTRY pEntry = (PDIABLO3_ASSETIDX_ENTRY)Directory.pbAssetIdxEntries;
        PCASC_CKEY_ENTRY pCKeyEntry;
        size_t nSavePos = PathBuffer.Save();
        DWORD dwEntries = Directory.dwAssetIdxEntries;

        // Do nothing if there is no entries
        if(pEntry != NULL && dwEntries != 0)
        {
            // Insert all asset entries to the file tree
            for(DWORD i = 0; i < dwEntries; i++, pEntry++)
            {
                pCKeyEntry = FindCKeyEntry_CKey(hs, pEntry->CKey.Value);
                if(pCKeyEntry != NULL)
                {
                    // Construct the full path name of the entry
                    if(CreateAssetFileName(PathBuffer, pEntry->FileIndex, pEntry->SubIndex))
                    {
                        // Insert the entry to the file tree
//                      fprintf(fp, "%08u %04u %s\n", pEntry->FileIndex, pEntry->SubIndex, PathBuffer.szBegin);
                        FileTree.InsertByName(pCKeyEntry, PathBuffer);
                    }

                    // Restore the path buffer position
                    PathBuffer.Restore(nSavePos);
                }
            }
        }

        return ERROR_SUCCESS;
    }

    // Parse the named entries of all folders
    DWORD ParseDirectory_Phase1(
        TCascStorage * hs, 
        DIABLO3_DIRECTORY & Directory,
        CASC_PATH<char> & PathBuffer,
        bool bIsRootDirectory)
    {
        DIABLO3_NAMED_ENTRY NamedEntry;
        size_t nFolderIndex = 0;
        size_t nSavePos = PathBuffer.Save();
        DWORD dwErrCode = ERROR_SUCCESS;

        // Do nothing if there is no named headers
        if(Directory.pbNamedEntries && Directory.dwNamedEntries)
        {
            PCASC_CKEY_ENTRY pCKeyEntry;
            PCASC_FILE_NODE pFileNode;
            LPBYTE pbDataPtr = Directory.pbNamedEntries;
            LPBYTE pbDataEnd = Directory.pbDirectoryEnd;
            DWORD dwNodeIndex;

            // Parse all entries
            while(pbDataPtr < pbDataEnd)
            {
                // Capture the named entry
                pbDataPtr = CaptureNamedEntry(pbDataPtr, pbDataEnd, &NamedEntry);
                if(pbDataPtr == NULL)
                    return ERROR_BAD_FORMAT;

                // Append the path fragment to the total path
                PathBuffer.AppendStringN(NamedEntry.szFileName, (NamedEntry.szFileEnd - NamedEntry.szFileName), true);

                // Check whether the file exists in the storage
                pCKeyEntry = FindCKeyEntry_CKey(hs, NamedEntry.pCKey->Value);
                if(pCKeyEntry != NULL)
                {
                    // Create file node belonging to this folder
                    pFileNode = FileTree.InsertByName(pCKeyEntry, PathBuffer);
                    dwNodeIndex = (DWORD)FileTree.IndexOf(pFileNode);

                    // If we are parsing root folder, we also need to load the data of the sub-folder file
                    if(bIsRootDirectory)
                    {
                        // Mark the node as directory
                        pCKeyEntry->Flags |= CASC_CE_FOLDER_ENTRY;
                        pFileNode->Flags |= CFN_FLAG_FOLDER;

                        // Load the sub-directory file
                        dwErrCode = LoadDirectoryFile(hs, RootFolders[nFolderIndex], pCKeyEntry);
                        if(dwErrCode != ERROR_SUCCESS)
                            return dwErrCode;

                        // Parse the sub-directory file
                        dwErrCode = ParseDirectory_Phase1(hs, RootFolders[nFolderIndex], PathBuffer, false);
                        if(dwErrCode != ERROR_SUCCESS)
                            return dwErrCode;

                        // Also save the item pointer and increment the folder index
                        RootFolders[nFolderIndex].dwNodeIndex = dwNodeIndex;
                        nFolderIndex++;
                    }

                    // Restore the path pointer
                    PathBuffer.Restore(nSavePos);
                }
            }
        }

        return dwErrCode;
    }

    // Parse the nameless entries of all folders
    int ParseDirectory_Phase2(TCascStorage * hs)
    {
        CASC_PATH<char> PathBuffer;
        char szBuffer[MAX_PATH];

        // Parse each root subdirectory
        for(size_t i = 0; i < DIABLO3_MAX_ROOT_FOLDERS; i++)
        {
            // Is this root folder loaded?
            if(RootFolders[i].pbDirectoryData != NULL)
            {
                // Retrieve the parent name
                if(RootFolders[i].dwNodeIndex != 0)
                {
                    FileTree.PathAt(szBuffer, _countof(szBuffer), RootFolders[i].dwNodeIndex);
                    PathBuffer.SetPathRoot(szBuffer);
                }

                // Array of DIABLO3_ASSET_ENTRY entries.
                // These are for files belonging to an asset, without subitem number.
                // Example: "SoundBank\SoundFile.smp"
                ParseAssetEntries(hs, RootFolders[i], PathBuffer);

                // Array of DIABLO3_ASSETIDX_ENTRY entries.
                // These are for files belonging to an asset, with a subitem number.
                // Example: "SoundBank\SoundFile\0001.smp"
                ParseAssetAndIdxEntries(hs, RootFolders[i], PathBuffer);
            }
        }

        return ERROR_SUCCESS;
    }

    // Creates an array of DIABLO3_CORE_TOC_ENTRY entries indexed by FileIndex
    // Used as lookup table when we have FileIndex and need Asset+PlainName
    DWORD CreateMapOfFileIndices(TCascStorage * hs, const char * szFileName)
    {
        PDIABLO3_CORE_TOC_HEADER pTocHeader = NULL;
        LPBYTE pbCoreTocPtr = pbCoreTocFile;
        DWORD dwMaxFileIndex = 0;
        DWORD dwErrCode = ERROR_CAN_NOT_COMPLETE;

        // Load the entire file to memory
        pbCoreTocFile = pbCoreTocPtr = LoadFileToMemory(hs, szFileName, &cbCoreTocFile);
        if(pbCoreTocFile && cbCoreTocFile)
        {
            LPBYTE pbCoreTocEnd = pbCoreTocFile + cbCoreTocFile;

            // Capture the header
            if((pbCoreTocPtr = CaptureCoreTocHeader(&pTocHeader, &dwMaxFileIndex, pbCoreTocPtr, pbCoreTocEnd)) == NULL)
                return ERROR_BAD_FORMAT;

            // If there are no indices, return NULL
            if(dwMaxFileIndex == 0)
                return ERROR_SUCCESS;

            // Allocate and populate the array of DIABLO3_CORE_TOC_ENTRYs
            pFileIndices = CASC_ALLOC<DIABLO3_CORE_TOC_ENTRY>(dwMaxFileIndex + 1);
            if(pFileIndices != NULL)
            {
                // Initialize all entries to invalid
                memset(pFileIndices, 0xFF, (dwMaxFileIndex + 1) * sizeof(DIABLO3_CORE_TOC_ENTRY));

                // Populate the linear array with the file indices
                for(size_t i = 0; i < DIABLO3_MAX_ASSETS; i++)
                {
                    PDIABLO3_CORE_TOC_ENTRY pTocEntry = (PDIABLO3_CORE_TOC_ENTRY)(pbCoreTocPtr + pTocHeader->EntryOffsets[i]);
                    LPBYTE pbCoreTocNames = (LPBYTE)(pTocEntry + pTocHeader->EntryCounts[i]);

                    // Setup the entries
                    for(DWORD n = 0; n < pTocHeader->EntryCounts[i]; n++)
                    {
                        DWORD dwFileIndex = pTocEntry->FileIndex;

                        pFileIndices[dwFileIndex].AssetIndex = pTocEntry->AssetIndex;
                        pFileIndices[dwFileIndex].FileIndex  = pTocEntry->FileIndex;
                        pFileIndices[dwFileIndex].NameOffset = (DWORD)(pbCoreTocNames - pbCoreTocPtr) + pTocEntry->NameOffset;
                        pTocEntry++;
                    }
                }

                // Save the file to the root handler
                pbCoreTocData = pbCoreTocPtr;
                nFileIndices = dwMaxFileIndex;
                dwErrCode = ERROR_SUCCESS;
            }
        }
        return dwErrCode;
    }

    // Packages.dat contains a list of full file names (without locale prefix).
    // They are not sorted, nor they correspond to file IDs.
    // Does the sort order mean something? Perhaps we could use them as listfile?
    int CreateMapOfRealNames(TCascStorage * hs, const char * szFileName)
    {
        DWORD Signature = 0;
        DWORD NumberOfNames = 0;

        // Load the entire file to memory
        pbPackagesDat = LoadFileToMemory(hs, szFileName, &cbPackagesDat);
        if(pbPackagesDat && cbPackagesDat)
        {
            LPBYTE pbPackagesPtr = pbPackagesDat;
            LPBYTE pbPackagesEnd = pbPackagesDat + cbPackagesDat;

            // Get the header. There is just Signature + NumberOfNames
            if((pbPackagesPtr = CaptureInteger32(pbPackagesPtr, pbPackagesEnd, &Signature)) == NULL)
                return ERROR_BAD_FORMAT;
            if((pbPackagesPtr = CaptureInteger32(pbPackagesPtr, pbPackagesEnd, &NumberOfNames)) == NULL)
                return ERROR_BAD_FORMAT;
            if(Signature != DIABLO3_PACKAGES_SIGNATURE || NumberOfNames == 0)
                return ERROR_BAD_FORMAT;

            // Create the map for fast search of the file name
            if(PackagesMap.Create(NumberOfNames, 0, 0, KeyIsString) == ERROR_SUCCESS)
            {
                const char * szPackageName = (const char *)pbPackagesPtr;

                // Go as long as there is something
                for(DWORD i = 0; i < NumberOfNames; i++)
                {
                    // Get the file extension
                    if((LPBYTE)szPackageName >= pbPackagesEnd)
                        break;

                    // Insert the file name to the map. The file extension is not included
                    PackagesMap.InsertString(szPackageName, true);
                    szPackageName = szPackageName + strlen(szPackageName) + 1;
                }
            }
        }

        return ERROR_SUCCESS;
    }

    DWORD Load(TCascStorage * hs, DIABLO3_DIRECTORY & RootDirectory)
    {
        CASC_PATH<char> PathBuffer;
        DWORD dwErrCode;

        // Always parse the named entries first. They always point to a file.
        // These are entries with arbitrary names, and they do not belong to an asset
        dwErrCode = ParseDirectory_Phase1(hs, RootDirectory, PathBuffer, true);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // The asset entries in the ROOT file don't contain file names, but indices.
            // To convert a file index to a file name, we need to load and parse the "Base\\CoreTOC.dat" file.
            dwErrCode = CreateMapOfFileIndices(hs, "Base\\CoreTOC.dat");
            if(dwErrCode == ERROR_SUCCESS)
            {
                // The file "Base\Data_D3\PC\Misc\Packages.dat" contains the file names
                // (without level-0 and level-1 directory).
                // We can use these names for supplying the missing extensions
                CreateMapOfRealNames(hs, "Base\\Data_D3\\PC\\Misc\\Packages.dat");

                // Now parse all folders and resolve the full names
                ParseDirectory_Phase2(hs);
            }

            // Free all stuff that was used during loading of the ROOT file
            FreeLoadingStuff();
        }

        return dwErrCode;
    }

    void FreeLoadingStuff()
    {
        // Free the captured root sub-directories
        for(size_t i = 0; i < DIABLO3_MAX_SUBDIRS; i++)
            CASC_FREE(RootFolders[i].pbDirectoryData);

        // Free the package map
        PackagesMap.Free();

        // Free the array of file indices
        CASC_FREE(pFileIndices);

        // Free the loaded CoreTOC.dat file
        CASC_FREE(pbCoreTocFile);

        // Free the loaded Packages.dat file
        CASC_FREE(pbPackagesDat);
    }

    // Array of root directory subdirectories
    DIABLO3_DIRECTORY RootFolders[DIABLO3_MAX_ROOT_FOLDERS];

    // Array of DIABLO3_TOC_ENTRY structures, sorted by the file index
    // Used for converting FileIndex -> Asset+PlainName during loading
    PDIABLO3_CORE_TOC_ENTRY pFileIndices;
    LPBYTE pbCoreTocFile;
    LPBYTE pbCoreTocData;
    size_t nFileIndices;
    DWORD cbCoreTocFile;

    // Map for searching a real file extension
    CASC_MAP PackagesMap;
    LPBYTE pbPackagesDat;
    DWORD cbPackagesDat;
};

//-----------------------------------------------------------------------------
// Public functions

DWORD RootHandler_CreateDiablo3(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TDiabloRoot * pRootHandler = NULL;
    DIABLO3_DIRECTORY RootDirectory;
    DWORD dwErrCode = ERROR_BAD_FORMAT;

    // Verify the header of the ROOT file
    if(TDiabloRoot::CaptureDirectoryData(RootDirectory, pbRootFile, cbRootFile) != NULL)
    {
        // Allocate the root handler object
        pRootHandler = new TDiabloRoot();
        if(pRootHandler != NULL)
        {
            // Load the root directory. If load failed, we free the object
            dwErrCode = pRootHandler->Load(hs, RootDirectory);
            if(dwErrCode != ERROR_SUCCESS)
            {
                delete pRootHandler;
                pRootHandler = NULL;
            }
        }
    }

    // Assign the root directory (or NULL) and return error
    hs->pRootHandler = pRootHandler;
    return dwErrCode;
}
