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

#define DIABLO3_INVALID_INDEX      0xFFFFFFFF
#define DIABLO3_INVALID_FILE       0xFFFFFFFF
#define DIABLO3_MAX_ASSETS         70               // Maximum possible number of assets
#define DIABLO3_MAX_LEVEL0_LENGTH  0x10             // Maximum length of the level-0 directory name

#define INVALID_FILE_INDEX          0xFFFFFFFF
#define INVALID_ASSET_INDEX         0xFF

#define ENTRY_FLAG_DIRECTORY_ENTRY   0x80           // The file is actually a directory entry
#define ENTRY_FLAG_PLAIN_NAME        0x01           // If set, the file entry contains offset of the plain file name
#define ENTRY_FLAG_FULL_NAME         0x02           // If set, the file entry contains offset of the full name
#define ENTRY_FLAG_FLAGS_MASK        0xF0           // Mask for the entry flags
#define ENTRY_FLAG_NAME_MASK         0x0F           // Mask for the entry file name type

// Values for CASC_FILE_ENTRY::dwFlags
#define CASC_ENTRY_SHORT_NAME       0x000000001     // If set, the name is in format XXYYplain-name[\sub-index].ext
#define CASC_ENTRY_HAS_SUBINDEX     0x000000002     // If set, the subitem is present in the file name (i.e. XXYYplain-name\sub-index.ext)

#define SEARCH_PHASE_NAMES         0                // Searching named entry
#define SEARCH_PHASE_FILE_IDS      1                // Searching filed by ID

// Macro for constructing 64-bit integer from root-index, file-index and sub-index
// The result value is RRAAAAAAAASSSSSS
#define MAKE_INDEX64(ri, fi, si)  (((ULONGLONG)ri << 0x38) | ((ULONGLONG)fi << 0x18) | ((ULONGLONG)si))
#define INDEX64_ROOT_INDEX(hash)  (DWORD)((hash >> 0x38) & 0x000000FF)
#define INDEX64_FILE_INDEX(hash)  (DWORD)((hash >> 0x18) & 0xFFFFFFFF)
#define INDEX64_SUB_INDEX(hash)   (DWORD)((hash >> 0x00) & 0x00FFFFFF)

// On-disk structure for a file given by file number
typedef struct _DIABLO3_FILEID1_ENTRY
{
    ENCODING_KEY EncodingKey;                       // Encoding key for the file
    DWORD FileIndex;                                // File index
} DIABLO3_FILEID1_ENTRY, *PDIABLO3_FILEID1_ENTRY;

// On-disk structure for a file given by file number and suffix
typedef struct _DIABLO3_FILEID2_ENTRY
{
    ENCODING_KEY EncodingKey;                       // Encoding key for the file
    DWORD FileIndex;                                // File index
    DWORD SubIndex;                                 // File subindex, like "SoundBank\3D Ambience\0000.smp"
} DIABLO3_FILEID2_ENTRY, *PDIABLO3_FILEID2_ENTRY;

// On-disk structure of the named entry
typedef struct _DIABLO3_NAMED_ENTRY
{
    ENCODING_KEY EncodingKey;                       // Encoding key for the file
    BYTE szFileName[1];                             // ASCIIZ file name (variable length)
} DIABLO3_NAMED_ENTRY, *PDIABLO3_NAMED_ENTRY;

// On-disk structure of CoreToc.dat header
typedef struct _DIABLO3_CORE_TOC_HEADER
{
    DWORD EntryCounts[DIABLO3_MAX_ASSETS];          // Array of number of entries (files) for each asset (level-1 directory)
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

// In-memory structure of parsed directory header
typedef struct _DIABLO3_DIR_HEADER
{
    LPBYTE pbEntries1;
    LPBYTE pbEntries2;
    LPBYTE pbEntries3;
    DWORD dwEntries1;
    DWORD dwEntries2;
    DWORD dwEntries3;
} DIABLO3_DIR_HEADER, *PDIABLO3_DIR_HEADER;

// In-memory structure of loaded CoreTOC.dat
typedef struct _DIABLO3_CORE_TOC
{
    DIABLO3_CORE_TOC_HEADER Hdr;                    // Header of CoreTOC.dat

    LPBYTE pbCoreToc;                               // Content of the CoreTOC.dat file
    DIABLO3_CORE_TOC_ENTRY Entries[1];              // Buffer for storing the entries (variable length)

} DIABLO3_CORE_TOC, *PDIABLO3_CORE_TOC;

// On-disk structure of Packages.dat header
typedef struct _DIABLO3_PACKAGES_DAT_HEADER
{
    DWORD Signature;
    DWORD NumberOfNames;
} DIABLO3_PACKAGES_DAT_HEADER, *PDIABLO3_PACKAGES_DAT_HEADER;

// Structure for conversion DirectoryID -> Directory name
typedef struct _DIABLO3_ASSET_INFO
{
    const char * szDirectoryName;                   // Directory name
    const char * szExtension;

} DIABLO3_ASSET_INFO;
typedef const DIABLO3_ASSET_INFO * PDIABLO3_ASSET_INFO;

// In-memory structure of a file entry in the linear file list
typedef struct _CASC_FILE_ENTRY
{
    ENCODING_KEY EncodingKey;                       // Encoding key
    ULONGLONG FileNameHash;                         // Hash of the full file name
    DWORD  dwFileName;                              // Offset of the name (in name's dynamic array)
    DWORD  dwFlags;                                 // Entry flags (see CASC_ENTRY_XXXX)

    DWORD  NameOffset;                              // Offset of the name (in name's dynamic array)
    USHORT SubIndex;                                // File\SubFile index
    BYTE   AssetIndex;                              // Asset index (aka directory index)
    BYTE   EntryFlags;                              // Entry flags
} CASC_FILE_ENTRY, *PCASC_FILE_ENTRY;

//-----------------------------------------------------------------------------
// Structure definitions for Diablo3 root file

struct TRootHandler_Diablo3 : public TRootHandler
{
    // Linear global list of all files
    DYNAMIC_ARRAY FileTable;

    // Linear global list of names
    DYNAMIC_ARRAY FileNames;

    // Global map of FileName -> FileEntry
    PCASC_MAP pRootMap;
};

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

static const DIABLO3_ASSET_INFO UnknownAsset = {"Unknown", "xxx"};

#define DIABLO3_ASSET_COUNT (sizeof(Assets) / sizeof(Assets[0]))

//-----------------------------------------------------------------------------
// Local functions

static PDIABLO3_ASSET_INFO GetAssetInfo(DWORD dwAssetIndex)
{
    if(dwAssetIndex < DIABLO3_ASSET_COUNT && Assets[dwAssetIndex].szDirectoryName != NULL)
        return &Assets[dwAssetIndex];
    return &UnknownAsset;
}

static DWORD VerifyNamedFileEntry(LPBYTE pbNamedEntry, LPBYTE pbFileEnd)
{
    LPBYTE pbFileName = ((PDIABLO3_NAMED_ENTRY)pbNamedEntry)->szFileName;

    // Find the end of the name
    while(pbFileName < pbFileEnd && pbFileName[0] != 0)
        pbFileName++;

    // Did we get past the end of the root file?
    if(pbFileName >= pbFileEnd)
        return 0;
    pbFileName++;

    // Return the length of the structure
    return (DWORD)(pbFileName - pbNamedEntry);
}

static char * FindPackageName(
    PCASC_MAP pPackageMap,
    const char * szAssetName,
    const char * szPlainName)
{
    char szFileName[MAX_PATH+1];
    size_t nLength;

    // Construct the name without extension and find it in the map
    nLength = sprintf(szFileName, "%s\\%s", szAssetName, szPlainName);
    return (char *)Map_FindString(pPackageMap, szFileName, szFileName + nLength);
}

static size_t CreateShortName(
    PCASC_MAP pPackageMap,
    DWORD dwRootIndex,                      // Level-0-dir: Index of the root subdirectory
    DWORD dwAssetIndex,                     // Level-1-dir: Index of the asset name
    const char * szPlainName,               // Plain name of the file, without extension
    DWORD dwSubIndex,
    char * szBuffer)
{
    PDIABLO3_ASSET_INFO pAssetInfo = GetAssetInfo(dwAssetIndex);
    const char * szPackageName = NULL;
    const char * szFormat;
    size_t nLength;

    // Write the level-0 directory index as 2-digit hexa number
    assert(dwRootIndex < 0x100);
    *szBuffer++ = IntToHexChar[dwRootIndex >> 0x04];
    *szBuffer++ = IntToHexChar[dwRootIndex & 0x0F];

    // Write the level-1 directory index as 2-digit hexa number
    assert(dwAssetIndex < 0x100);
    *szBuffer++ = IntToHexChar[dwAssetIndex >> 0x04];
    *szBuffer++ = IntToHexChar[dwAssetIndex & 0x0F];

    // Construct the file name with ending "." for extension
    szFormat = (dwSubIndex != DIABLO3_INVALID_INDEX) ? "%s\\%04u." : "%s.";
    nLength = sprintf(szBuffer, szFormat, szPlainName, dwSubIndex);

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
    if(pPackageMap != NULL)
    {
        // Retrieve the asset name
        szPackageName = FindPackageName(pPackageMap, pAssetInfo->szDirectoryName, szBuffer);
        if(szPackageName != NULL)
        {
            strcpy(szBuffer, szPackageName + strlen(pAssetInfo->szDirectoryName) + 1);
            nLength = strlen(szBuffer);
        }
    }

    // If we havent't found the package, we either use the default asset extension or "xxx"
    if(szPackageName == NULL)
    {
        if(dwSubIndex == DIABLO3_INVALID_INDEX)
        {
            strcpy(szBuffer + nLength, pAssetInfo->szExtension);
            nLength += strlen(pAssetInfo->szExtension);
        }
        else
        {
            strcpy(szBuffer + nLength, "xxx");
            nLength += 3;
        }
    }

    // Return the length of the short file name
    return nLength + 4;
}

static size_t CreateFileName(
    TRootHandler_Diablo3 * pRootHandler,
    const char * szShortName,               // Short file name of the file
    char * szBuffer)
{
    PCASC_FILE_ENTRY pRootEntry;
    const char * szNameLevel0;
    const char * szNameLevel1 = NULL;
    DWORD dwRootIndex0 = 0;
    DWORD dwAssetIndex = 0;

    // Retrieve the level-0 and level-1 directory indexes
    ConvertStringToInt08(szShortName+0, &dwRootIndex0);
    ConvertStringToInt08(szShortName+2, &dwAssetIndex);

    // Retrieve the name of the level-0 directory (aka root subdirectory)
    pRootEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, dwRootIndex0);
    szNameLevel0 = (char *)Array_ItemAt(&pRootHandler->FileNames, pRootEntry->dwFileName);

    // Retrieve the name of the level-1 directory (aka asset name)
    if(dwAssetIndex < DIABLO3_ASSET_COUNT)
        szNameLevel1 = Assets[dwAssetIndex].szDirectoryName;
    if(szNameLevel1 == NULL)
        szNameLevel1 = UnknownAsset.szDirectoryName;

    // Copy the rest of the name as-is
    return sprintf(szBuffer, "%s\\%s\\%s", szNameLevel0, szNameLevel1, szShortName + 4);
}


// Creates a map of String -> Pointer
static PCASC_MAP CreatePackageMap(
    LPBYTE pbPackagesDat,
    LPBYTE pbPackagesEnd)
{
    PDIABLO3_PACKAGES_DAT_HEADER pDatHeader = (PDIABLO3_PACKAGES_DAT_HEADER)pbPackagesDat;
    PCASC_MAP pPackageMap;

    // Get the header
    if((pbPackagesDat + sizeof(DIABLO3_PACKAGES_DAT_HEADER)) >= pbPackagesEnd)
        return NULL;
    pbPackagesDat += sizeof(DIABLO3_PACKAGES_DAT_HEADER);

    // Check the signature and name count
    if(pDatHeader->Signature != DIABLO3_PACKAGES_SIGNATURE)
        return NULL;

    // Create the map for fast search of the file name
    pPackageMap = Map_Create(pDatHeader->NumberOfNames, KEY_LENGTH_STRING, 0);
    if(pPackageMap != NULL)
    {
        char * szFileName = (char *)pbPackagesDat;

        // Go as long as there is something
        for(DWORD i = 0; i < pDatHeader->NumberOfNames; i++)
        {
            // Get the file extension
            if((LPBYTE)szFileName >= pbPackagesEnd)
                break;

            // Insert the file name to the map. The file extension is not included
            Map_InsertString(pPackageMap, szFileName, true);
            szFileName = szFileName + strlen(szFileName) + 1;
        }
    }

    return pPackageMap;
}

// Insert an entry with file name as-is
static int InsertFileEntry(
    TRootHandler_Diablo3 * pRootHandler,
    ENCODING_KEY & EncodingKey,
    const char * szFileName,
    size_t cchFileName)
{
    PCASC_FILE_ENTRY pFileEntry;

    // We must not allow the file name array to be reallocated.
    // Reallocating the array would cause pointers in TRootHandler_Diablo3::pRootMap
    // become invalid
    if(pRootHandler->FileTable.ItemCount >= pRootHandler->FileTable.ItemCountMax)
    {
        assert(false);
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    // Insert the plain name to the root handler's global name list
    szFileName = (const char *)Array_Insert(&pRootHandler->FileNames, szFileName, cchFileName);
    if(szFileName == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Make sure that we don't exceed the file limit at this phase
    pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);
    assert(pFileEntry != NULL);

    // Store the info into the file entry
    pFileEntry->EncodingKey  = EncodingKey;
    pFileEntry->FileNameHash = CalcFileNameHash(szFileName);
    pFileEntry->dwFileName   = (DWORD)Array_IndexOf(&pRootHandler->FileNames, szFileName);
    pFileEntry->dwFlags      = 0;

    // Verify collisions (debug version only)
    assert(Map_FindObject(pRootHandler->pRootMap, &pFileEntry->FileNameHash, NULL) == NULL);

    // Calculate the file name hash
    Map_InsertObject(pRootHandler->pRootMap, pFileEntry, &pFileEntry->FileNameHash);

    // Success
    return ERROR_SUCCESS;
}

static int ParseDirEntries_FileId1(
    TRootHandler_Diablo3 * pRootHandler,
    LPBYTE pbFileEntries,
    DWORD dwFileEntries,
    DWORD dwRootDirIndex)
{
    PDIABLO3_FILEID1_ENTRY pEntry = (PDIABLO3_FILEID1_ENTRY)pbFileEntries;
    PCASC_FILE_ENTRY pFileEntry;

    // Overflow test
    if((pRootHandler->FileTable.ItemCount + dwFileEntries) >= pRootHandler->FileTable.ItemCountMax)
    {
        assert(false);
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    // Parse the all ID1 entries in the file
    for(DWORD i = 0; i < dwFileEntries; i++, pEntry++)
    {
        // Insert the file entry to the global list
        pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);
        assert(pFileEntry != NULL);

        // Fill the index entry
        pFileEntry->EncodingKey  = pEntry->EncodingKey;
        pFileEntry->FileNameHash = MAKE_INDEX64(dwRootDirIndex, pEntry->FileIndex, 0);
        pFileEntry->dwFlags      = CASC_ENTRY_SHORT_NAME;
    }

    return ERROR_SUCCESS;
}

static int ParseDirEntries_FileId2(
    TRootHandler_Diablo3 * pRootHandler,
    LPBYTE pbFileEntries,
    DWORD dwFileEntries,
    DWORD dwRootDirIndex)
{
    PDIABLO3_FILEID2_ENTRY pEntry = (PDIABLO3_FILEID2_ENTRY)pbFileEntries;
    PCASC_FILE_ENTRY pFileEntry;

    // Overflow test
    if((pRootHandler->FileTable.ItemCount + dwFileEntries) >= pRootHandler->FileTable.ItemCountMax)
    {
        assert(false);
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    // Parse the all ID1 entries in the file
    for(DWORD i = 0; i < dwFileEntries; i++, pEntry++)
    {
        // Insert the file entry to the global list
        pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);
        assert(pFileEntry != NULL);

        // Fill the index entry
        pFileEntry->EncodingKey  = pEntry->EncodingKey;
        pFileEntry->FileNameHash = MAKE_INDEX64(dwRootDirIndex, pEntry->FileIndex, pEntry->SubIndex);
        pFileEntry->dwFlags      = CASC_ENTRY_SHORT_NAME | CASC_ENTRY_HAS_SUBINDEX;
    }

    return ERROR_SUCCESS;
}

static int ParseDirEntries_Named(
    TRootHandler_Diablo3 * pRootHandler,
    LPBYTE pbFileEntries,
    LPBYTE pbFileEnd,
    DWORD dwFileEntries,
    DWORD dwRootDirIndex)
{
    char szFileName[MAX_PATH+1];
    char * szNamePtr = szFileName;
    DWORD cbFileEntry;
    int nError = ERROR_SUCCESS;

    // Overflow test
    if((pRootHandler->FileTable.ItemCount + dwFileEntries) >= pRootHandler->FileTable.ItemCountMax)
    {
        assert(false);
        return ERROR_NOT_ENOUGH_MEMORY;
    }

    // If we the file is not in the root directory itself,
    // prepare the prefix for the root directory.
    if(dwRootDirIndex != DIABLO3_INVALID_INDEX)
    {
        PCASC_FILE_ENTRY pRootEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, dwRootDirIndex);
        const char * szRootName = (const char *)Array_ItemAt(&pRootHandler->FileNames, pRootEntry->dwFileName);

        // Copy the root directory name
        while(szRootName[0] != 0)
            *szNamePtr++ = *szRootName++;

        // Append the backslash
        *szNamePtr++ = '\\';
    }

    // Parse the file entry
    while(pbFileEntries < pbFileEnd)
    {
        PDIABLO3_NAMED_ENTRY pNamedEntry = (PDIABLO3_NAMED_ENTRY)pbFileEntries;
        DWORD cchFileName;

        // Verify the named entry whether it does not go beyond the EOF
        cbFileEntry = VerifyNamedFileEntry(pbFileEntries, pbFileEnd);
        if(cbFileEntry == 0)
            return ERROR_FILE_CORRUPT;

        // Append the file name to the prepared file name
        // This way we obtain the full name and the name lookup
        // will be fully operational
        memcpy(szNamePtr, pNamedEntry->szFileName, (cbFileEntry - sizeof(ENCODING_KEY)));
        cchFileName = (DWORD)((szNamePtr - szFileName) + (cbFileEntry - sizeof(ENCODING_KEY)));

        // Insert the named entry to the global file table
        nError = InsertFileEntry(pRootHandler,
                                 pNamedEntry->EncodingKey,
                                 szFileName,
                                 cchFileName);
        if(nError != ERROR_SUCCESS)
            return nError;

        // Move the pointer to the next entry
        pbFileEntries += cbFileEntry;
    }

    return ERROR_SUCCESS;
}

static void ResolveFullFileNames(
    TRootHandler_Diablo3 * pRootHandler,
    PDIABLO3_CORE_TOC_ENTRY pCoreTocEntries,
    PCASC_MAP pPackageMap,
    LPBYTE pbCoreTocFile,
    DWORD dwFileIndexes)
{
    PCASC_FILE_ENTRY pFileEntry;
    char * szPlainName;
    char * szNamePtr;
    size_t nLength;
    DWORD dwRootIndex;
    DWORD dwFileIndex;
    DWORD dwSubIndex;
    char szShortName[MAX_PATH+1];
    char szFullName[MAX_PATH+1];

    // Parse the entire file table
    for(size_t i = 0; i < pRootHandler->FileTable.ItemCount; i++)
    {
        // Retrieve the file entry at n-th position
        pFileEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, i);

        // Skip the items that already have full name
        if(pFileEntry->dwFlags & CASC_ENTRY_SHORT_NAME)
        {
            // Retrieve the file index of that file
            dwRootIndex = INDEX64_ROOT_INDEX(pFileEntry->FileNameHash);
            dwFileIndex = INDEX64_FILE_INDEX(pFileEntry->FileNameHash);
            dwSubIndex = (pFileEntry->dwFlags & CASC_ENTRY_HAS_SUBINDEX) ? INDEX64_SUB_INDEX(pFileEntry->FileNameHash) : DIABLO3_INVALID_INDEX;
            assert(dwFileIndex < dwFileIndexes);

            // Get the plain name of the file
            szPlainName = (char *)(pbCoreTocFile + pCoreTocEntries[dwFileIndex].NameOffset);

            // Create the short file name
            nLength = CreateShortName(pPackageMap,
                                      dwRootIndex,
                                      pCoreTocEntries[dwFileIndex].AssetIndex,
                                      szPlainName,
                                      dwSubIndex,
                                      szShortName);

            // Insert the short name to the list of the names
            szNamePtr = (char *)Array_Insert(&pRootHandler->FileNames, szShortName, nLength + 1);
            pFileEntry->dwFileName = (DWORD)Array_IndexOf(&pRootHandler->FileNames, szNamePtr);

            // Create the full file name
            nLength = CreateFileName(pRootHandler, szShortName, szFullName);
            pFileEntry->FileNameHash = CalcFileNameHash(szFullName);

            // Insert the entry to the name map. Use the mapping of FullName -> FileHash
            Map_InsertObject(pRootHandler->pRootMap, pFileEntry, &pFileEntry->FileNameHash);
        }
    }
}

static LPBYTE LoadFileToMemory(TCascStorage * hs, LPBYTE pbEncodingKey, DWORD * pcbFileData)
{
    QUERY_KEY EncodingKey;
    LPBYTE pbFileData = NULL;
    HANDLE hFile;
    DWORD cbBytesRead = 0;
    DWORD cbFileData = 0;

    // Open the file by encoding key
    EncodingKey.pbData = pbEncodingKey;
    EncodingKey.cbData = MD5_HASH_SIZE;
    if(CascOpenFileByEncodingKey((HANDLE)hs, &EncodingKey, 0, &hFile))
    {
        // Retrieve the file size
        cbFileData = CascGetFileSize(hFile, NULL);
        if(cbFileData > 0)
        {
            pbFileData = CASC_ALLOC(BYTE, cbFileData);
            if(pbFileData != NULL)
            {
                CascReadFile(hFile, pbFileData, cbFileData, &cbBytesRead);
            }
        }

        // Close the file
        CascCloseFile(hFile);
    }

    // Give the file to the caller
    if(pcbFileData != NULL)
        pcbFileData[0] = cbBytesRead;
    return pbFileData;
}

static LPBYTE LoadFileToMemory(TCascStorage * hs, const char * szFileName, DWORD * pcbFileData)
{
    LPBYTE pbEncodingKey = NULL;
    LPBYTE pbFileData = NULL;

    // Try to find encoding key for the file
    pbEncodingKey = RootHandler_GetKey(hs->pRootHandler, szFileName);
    if(pbEncodingKey != NULL)
        pbFileData = LoadFileToMemory(hs, pbEncodingKey, pcbFileData);

    return pbFileData;
}

static int ParseDirectoryHeader(
    PDIABLO3_DIR_HEADER pDirHeader,
    LPBYTE pbDirFile,
    LPBYTE pbFileEnd)
{
    DWORD dwSignature = 0;

    //
    // Structure of a Diablo3 directory file
    // 1) Signature (4 bytes)
    // 2) Number of DIABLO3_FILEID1_ENTRY entries (4 bytes)
    // 3) Array of DIABLO3_FILEID1_ENTRY entries
    // 4) Number of DIABLO3_FILEID2_ENTRY entries (4 bytes)
    // 5) Array of DIABLO3_FILEID2_ENTRY entries
    // 6) Number of DIABLO3_NAMED_ENTRY entries (4 bytes)
    // 7) Array of DIABLO3_NAMED_ENTRY entries
    //

    // Prepare the header signature
    memset(pDirHeader, 0, sizeof(DIABLO3_DIR_HEADER));

    // Get the signature
    if((pbDirFile + sizeof(DWORD)) >= pbFileEnd)
        return ERROR_BAD_FORMAT;
    dwSignature = *(PDWORD)pbDirFile;

    // Check the signature
    if(dwSignature != CASC_DIABLO3_ROOT_SIGNATURE && dwSignature != DIABLO3_SUBDIR_SIGNATURE)
        return ERROR_BAD_FORMAT;
    pbDirFile += sizeof(DWORD);

    // Subdirectories have extra two arrays
    if(dwSignature == DIABLO3_SUBDIR_SIGNATURE)
    {
        // Get the number of DIABLO3_FILEID1_ENTRY items
        if((pbDirFile + sizeof(DWORD)) >= pbFileEnd)
            return ERROR_BAD_FORMAT;
        pDirHeader->dwEntries1 = *(PDWORD)pbDirFile;

        // Get the array of DIABLO3_FILEID1_ENTRY
        pDirHeader->pbEntries1 = (pbDirFile + sizeof(DWORD));
        pbDirFile = pbDirFile + sizeof(DWORD) + pDirHeader->dwEntries1 * sizeof(DIABLO3_FILEID1_ENTRY);

        // Get the number of DIABLO3_FILEID2_ENTRY items
        if((pbDirFile + sizeof(DWORD)) >= pbFileEnd)
            return ERROR_BAD_FORMAT;
        pDirHeader->dwEntries2 = *(PDWORD)pbDirFile;

        // Get the array of DIABLO3_FILEID2_ENTRY
        pDirHeader->pbEntries2 = (pbDirFile + sizeof(DWORD));
        pbDirFile = pbDirFile + sizeof(DWORD) + pDirHeader->dwEntries2 * sizeof(DIABLO3_FILEID2_ENTRY);
    }

    // Get the pointer and length DIABLO3_NAMED_ENTRY array
    if((pbDirFile + sizeof(DWORD)) >= pbFileEnd)
        return ERROR_BAD_FORMAT;
    pDirHeader->dwEntries3 = *(PDWORD)pbDirFile;
    pDirHeader->pbEntries3 = (pbDirFile + sizeof(DWORD));
    return ERROR_SUCCESS;
}

static DWORD ScanDirectoryFile(
    TCascStorage * hs,
    LPBYTE pbRootFile,
    LPBYTE pbFileEnd)
{
    PDIABLO3_NAMED_ENTRY pNamedEntry;
    DIABLO3_DIR_HEADER RootHeader;
    DIABLO3_DIR_HEADER DirHeader;
    LPBYTE pbSubDir;
    DWORD dwTotalFileCount;
    DWORD cbNamedEntry;
    DWORD cbSubDir;
    int nError;

    // Parse the directory header in order to retrieve the items
    nError = ParseDirectoryHeader(&RootHeader, pbRootFile, pbFileEnd);
    if(nError != ERROR_SUCCESS)
        return 0;

    // Add the root directory's entries
    dwTotalFileCount = RootHeader.dwEntries1 + RootHeader.dwEntries2 + RootHeader.dwEntries3;

    // Parse the named entries
    for(DWORD i = 0; i < RootHeader.dwEntries3; i++)
    {
        // Get the this named entry
        if((cbNamedEntry = VerifyNamedFileEntry(RootHeader.pbEntries3, pbFileEnd)) == 0)
            return 0;
        pNamedEntry = (PDIABLO3_NAMED_ENTRY)RootHeader.pbEntries3;
        RootHeader.pbEntries3 += cbNamedEntry;

        // Load the subdirectory to memory
        pbSubDir = LoadFileToMemory(hs, pNamedEntry->EncodingKey.Value, &cbSubDir);
        if(pbSubDir != NULL)
        {
            // Count the files in the subdirectory
            if(ParseDirectoryHeader(&DirHeader, pbSubDir, pbSubDir + cbSubDir) == ERROR_SUCCESS)
            {
                dwTotalFileCount += DirHeader.dwEntries1 + DirHeader.dwEntries2 + DirHeader.dwEntries3;
            }

            // Free the subdirectory
            CASC_FREE(pbSubDir);
        }
    }

    // Return the total number of entries
    return dwTotalFileCount;
}

static int ParseDirectoryFile(
    TRootHandler_Diablo3 * pRootHandler,
    LPBYTE pbDirFile,
    LPBYTE pbFileEnd,
    DWORD dwRootDirIndex)
{
    DIABLO3_DIR_HEADER DirHeader;
    int nError;

    // Sanity checks
    assert(pRootHandler->FileTable.ItemArray != NULL);
    assert(pRootHandler->FileTable.ItemCount < pRootHandler->FileTable.ItemCountMax);

    // Parse the directory header in order to retrieve the items
    nError = ParseDirectoryHeader(&DirHeader, pbDirFile, pbFileEnd);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Process all DIABLO3_FILEID1_ENTRY entries. These are for files
    // belonging to an asset group, without subitem number.
    // Example: "SoundBank\SoundFile.smp"
    // We skip inserting them to the name map, because the names are not known yet
    if(DirHeader.pbEntries1 && DirHeader.dwEntries1)
    {
        assert(dwRootDirIndex != DIABLO3_INVALID_INDEX);
        nError = ParseDirEntries_FileId1(pRootHandler, DirHeader.pbEntries1, DirHeader.dwEntries1, dwRootDirIndex);
        if(nError != ERROR_SUCCESS)
            return nError;
    }

    // Parse all DIABLO3_FILEID2_ENTRY entries. These are for files
    // belonging to an asset group, with a subitem number.
    // Example: "SoundBank\SoundFile\0001.smp"
    // We skip inserting them to the name map, because the names are not known yet
    if(DirHeader.pbEntries2 && DirHeader.dwEntries2)
    {
        assert(dwRootDirIndex != DIABLO3_INVALID_INDEX);
        nError = ParseDirEntries_FileId2(pRootHandler, DirHeader.pbEntries2, DirHeader.dwEntries2, dwRootDirIndex);
        if(nError != ERROR_SUCCESS)
            return nError;
    }


    // Parse all named entries. These are for files with arbitrary names,
    // and they do not belong to an asset.
    if(DirHeader.pbEntries3 && DirHeader.dwEntries3)
    {
        nError = ParseDirEntries_Named(pRootHandler, DirHeader.pbEntries3, pbFileEnd, DirHeader.dwEntries3, dwRootDirIndex);
        if(nError != ERROR_SUCCESS)
            return nError;
    }

    // Give the directory to the caller
    return nError;
}

static int ParseCoreTOC(
    TRootHandler_Diablo3 * pRootHandler,
    PCASC_MAP pPackageMap,
    LPBYTE pbCoreTocFile,
    LPBYTE pbCoreTocEnd)
{
    PDIABLO3_CORE_TOC_HEADER pTocHeader;
    PDIABLO3_CORE_TOC_ENTRY pSortedEntries;
    PDIABLO3_CORE_TOC_ENTRY pTocEntry;
    LPBYTE pbCoreTocNames;
    DWORD dwFileIndexes = 0;
    DWORD i;

    // Check the space for header
    if((pbCoreTocFile + sizeof(DIABLO3_CORE_TOC_HEADER)) > pbCoreTocEnd)
        return ERROR_FILE_CORRUPT;
    pTocHeader = (PDIABLO3_CORE_TOC_HEADER)pbCoreTocFile;
    pbCoreTocFile += sizeof(DIABLO3_CORE_TOC_HEADER);

    // Calculate space needed for allocation
    for(i = 0; i < DIABLO3_MAX_ASSETS; i++)
    {
        // Get the first entry
        pTocEntry = (PDIABLO3_CORE_TOC_ENTRY)(pbCoreTocFile + pTocHeader->EntryOffsets[i]);

        // Find out the entry with the maximum index
        for(DWORD n = 0; n < pTocHeader->EntryCounts[i]; n++)
        {
            if(pTocEntry->FileIndex > dwFileIndexes)
                dwFileIndexes = pTocEntry->FileIndex + 1;
            pTocEntry++;
        }
    }

    // Allocate and populate the array of DIABLO3_CORE_TOC_ENTRYs
    pSortedEntries = CASC_ALLOC(DIABLO3_CORE_TOC_ENTRY, dwFileIndexes);
    if(pSortedEntries != NULL)
    {
        // Initialize all entries to invalid
        memset(pSortedEntries, 0xFF, dwFileIndexes * sizeof(DIABLO3_CORE_TOC_ENTRY));

        // Populate the linear array with the entries
        for(i = 0; i < DIABLO3_MAX_ASSETS; i++)
        {
            // Set the pointers
            pTocEntry = (PDIABLO3_CORE_TOC_ENTRY)(pbCoreTocFile + pTocHeader->EntryOffsets[i]);
            pbCoreTocNames = (LPBYTE)(pTocEntry + pTocHeader->EntryCounts[i]);

            // Setup the entries
            for(DWORD n = 0; n < pTocHeader->EntryCounts[i]; n++)
            {
                pSortedEntries[pTocEntry->FileIndex].AssetIndex = pTocEntry->AssetIndex;
                pSortedEntries[pTocEntry->FileIndex].FileIndex  = pTocEntry->FileIndex;
                pSortedEntries[pTocEntry->FileIndex].NameOffset = (DWORD)(pbCoreTocNames - pbCoreTocFile) + pTocEntry->NameOffset;
                pTocEntry++;
            }
        }

        // Now use the linear array to resolve the asset indexes and plain names
        ResolveFullFileNames(pRootHandler, pSortedEntries, pPackageMap, pbCoreTocFile, dwFileIndexes);
        CASC_FREE(pSortedEntries);
    }

    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Implementation of Diablo III root file

static int D3Handler_Insert(TRootHandler_Diablo3 * pRootHandler, const char * szFileName, LPBYTE pbEncodingKey)
{
    ENCODING_KEY EncodingKey;
    DWORD dwFileIndex;

    // Don't let the number of items to overflow
    if(pRootHandler->FileTable.ItemCount >= pRootHandler->FileTable.ItemCountMax)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Insert the item
    EncodingKey = *(PENCODING_KEY)pbEncodingKey;
    dwFileIndex = InsertFileEntry(pRootHandler,
                                  EncodingKey,
                                  szFileName,
                                  strlen(szFileName) + 1);
    return (dwFileIndex != INVALID_FILE_INDEX) ? ERROR_SUCCESS : ERROR_NOT_ENOUGH_MEMORY;
}

static LPBYTE D3Handler_Search(TRootHandler_Diablo3 * pRootHandler, TCascSearch * pSearch, PDWORD /* PtrFileSize */, PDWORD /* PtrLocaleFlags */)
{
    PCASC_FILE_ENTRY pFileEntry;
    const char * szSrcName = NULL;

    // Are we still inside the root directory range?
    while(pSearch->IndexLevel1 < pRootHandler->FileTable.ItemCount)
    {
        // Get the n-th directory and the file name
        pFileEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, pSearch->IndexLevel1);
        szSrcName = (char *)Array_ItemAt(&pRootHandler->FileNames, pFileEntry->dwFileName);

        // This is either a full file name or an abbreviated name
        if(pFileEntry->dwFlags & CASC_ENTRY_SHORT_NAME)
        {
            CreateFileName(pRootHandler, szSrcName, pSearch->szFileName);
        }
        else
        {
            strcpy(pSearch->szFileName, szSrcName);
        }

        // Prepare for the next search
        pSearch->IndexLevel1++;
        return pFileEntry->EncodingKey.Value;
    }

    // No more entries
    return NULL;
}

static void D3Handler_EndSearch(TRootHandler_Diablo3 * /* pRootHandler */, TCascSearch * /* pSearch */)
{
    // Do nothing
}

static LPBYTE D3Handler_GetKey(TRootHandler_Diablo3 * pRootHandler, const char * szFileName)
{
    PCASC_FILE_ENTRY pFileEntry;
    ULONGLONG FileNameHash = CalcFileNameHash(szFileName);

    // Find the file in the name table
    pFileEntry = (PCASC_FILE_ENTRY)Map_FindObject(pRootHandler->pRootMap, &FileNameHash, NULL);
    return (pFileEntry != NULL) ? pFileEntry->EncodingKey.Value : NULL;
}

static void D3Handler_Close(TRootHandler_Diablo3 * pRootHandler)
{
    if(pRootHandler != NULL)
    {
        // Free the file map
        Map_Free(pRootHandler->pRootMap);

        // Free the array of the file entries and file names
        Array_Free(&pRootHandler->FileTable);
        Array_Free(&pRootHandler->FileNames);

        // Free the root file itself
        CASC_FREE(pRootHandler);
    }
}

/*
static void DumpRootFile(TDumpContext * dc, LPBYTE pbFileData, LPBYTE pbFileDataEnd)
{
    char  szMD5Buffer[MD5_STRING_SIZE+1];
    DWORD dwSignature;
    DWORD dwItemCount;
    DWORD i;

    dwSignature = *(PDWORD)pbFileData;
    if(dwSignature != CASC_DIABLO3_SUBDIR_SIGNATURE)
        return;
    pbFileData += sizeof(DWORD);

    // Dump items that contain EncodingKey + AssetId
    dwItemCount = *(PDWORD)pbFileData;
    pbFileData += sizeof(DWORD);
    for(i = 0; i < dwItemCount; i++)
    {
        PCASC_DIABLO3_ASSET_ENTRY pEntry = (PCASC_DIABLO3_ASSET_ENTRY)pbFileData;

        if((pbFileData + sizeof(*pEntry)) > pbFileDataEnd)
            return;
        pbFileData += sizeof(*pEntry);

        dump_print(dc, "%s %08X\n", StringFromMD5(pEntry->EncodingKey, szMD5Buffer), pEntry->AssetId);
    }

    // Terminate with two newlines
    dump_print(dc, "\n");

    // Dump items that contain EncodingKey + AssetId + FileNumber
    dwItemCount = *(PDWORD)pbFileData;
    pbFileData += sizeof(DWORD);
    for(i = 0; i < dwItemCount; i++)
    {
        PCASC_DIABLO3_ASSET_ENTRY2 pEntry = (PCASC_DIABLO3_ASSET_ENTRY2)pbFileData;

        if((pbFileData + sizeof(*pEntry)) > pbFileDataEnd)
            return;
        pbFileData += sizeof(*pEntry);

        dump_print(dc, "%s %08X %08X\n", StringFromMD5((LPBYTE)pEntry->EncodingKey, szMD5Buffer), pEntry->AssetId, pEntry->FileNumber);
    }

    // Terminate with two newlines
    dump_print(dc, "\n");

    // Dump items that contain EncodingKey + FileName
    dwItemCount = *(PDWORD)pbFileData;
    pbFileData += sizeof(DWORD);
    for(i = 0; i < dwItemCount; i++)
    {
        PDIABLO3_NAMED_ENTRY pEntry = (PDIABLO3_NAMED_ENTRY)pbFileData;
        DWORD dwEntrySize = VerifyNamedFileEntry(pbFileData, pbFileDataEnd);

        if((pbFileData + dwEntrySize) > pbFileDataEnd)
            return;
        pbFileData += dwEntrySize;

        dump_print(dc, "%s %s\n", StringFromMD5((LPBYTE)pEntry->EncodingKey, szMD5Buffer), pEntry->szFileName);
    }

    dump_print(dc, "\n\n");
}
*/
//-----------------------------------------------------------------------------
// Public functions

int RootHandler_CreateDiablo3(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_Diablo3 * pRootHandler;
    PCASC_MAP pPackageMap = NULL;
    LPBYTE pbRootFileEnd = pbRootFile + cbRootFile;
    LPBYTE pbPackagesDat = NULL;
    DWORD dwTotalFileCount;
    DWORD cbPackagesDat = 0;
    int nError;

    // Allocate the root handler object
    hs->pRootHandler = pRootHandler = CASC_ALLOC(TRootHandler_Diablo3, 1);
    if(pRootHandler == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill-in the handler functions
    memset(pRootHandler, 0, sizeof(TRootHandler_Diablo3));
    pRootHandler->Insert      = (ROOT_INSERT)D3Handler_Insert;
    pRootHandler->Search      = (ROOT_SEARCH)D3Handler_Search;
    pRootHandler->EndSearch   = (ROOT_ENDSEARCH)D3Handler_EndSearch;
    pRootHandler->GetKey      = (ROOT_GETKEY)D3Handler_GetKey;
    pRootHandler->Close       = (ROOT_CLOSE)D3Handler_Close;

    // Fill-in the flags
    pRootHandler->dwRootFlags |= ROOT_FLAG_HAS_NAMES;

    // Scan the total number of files in the root directories
    // Reserve space for extra files
    dwTotalFileCount = ScanDirectoryFile(hs, pbRootFile, pbRootFileEnd);
    if(dwTotalFileCount == 0)
        return ERROR_FILE_CORRUPT;
    dwTotalFileCount += CASC_EXTRA_FILES;

    // Allocate the global linear file table
    // Note: This is about 18 MB of memory for Diablo III PTR build 30013
    nError = Array_Create(&pRootHandler->FileTable, CASC_FILE_ENTRY, dwTotalFileCount);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Allocate global buffer for file names.
    // The size of the buffer was taken from Diablo III build 30013
    nError = Array_Create(&pRootHandler->FileNames, char, 0x01000000);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Create map of ROOT_ENTRY -> FileEntry
    pRootHandler->pRootMap = Map_Create(dwTotalFileCount, sizeof(ULONGLONG), FIELD_OFFSET(CASC_FILE_ENTRY, FileNameHash));
    if(pRootHandler->pRootMap == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Parse the ROOT file and insert all entries in the file table
    nError = ParseDirectoryFile(pRootHandler, pbRootFile, pbRootFileEnd, DIABLO3_INVALID_INDEX);
    if(nError == ERROR_SUCCESS)
    {
        size_t dwRootEntries = pRootHandler->FileTable.ItemCount;

        // We expect the number of level-0 to be less than maximum
        assert(dwRootEntries < DIABLO3_MAX_SUBDIRS);

        // Now parse the all root items and load them
        for(size_t i = 0; i < dwRootEntries; i++)
        {
            PCASC_FILE_ENTRY pRootEntry = (PCASC_FILE_ENTRY)Array_ItemAt(&pRootHandler->FileTable, i);

            // Load the entire file to memory
            pbRootFile = LoadFileToMemory(hs, pRootEntry->EncodingKey.Value, &cbRootFile);
            if(pbRootFile != NULL)
            {
                nError = ParseDirectoryFile(pRootHandler, pbRootFile, pbRootFile + cbRootFile, i);
                CASC_FREE(pbRootFile);
            }
        }
    }

    // Note: The file "Base\Data_D3\PC\Misc\Packages.dat" contains the names
    // of the files (without level-0 and level-1 directory). We can use these
    // names for supplying the missing extensions
    if(nError == ERROR_SUCCESS)
    {
        // Load the entire file to memory
        pbPackagesDat = LoadFileToMemory(hs, "Base\\Data_D3\\PC\\Misc\\Packages.dat", &cbPackagesDat);
        if(pbPackagesDat != NULL)
        {
            pPackageMap = CreatePackageMap(pbPackagesDat, pbPackagesDat + cbPackagesDat);
        }
    }

    // Vast majorify of files at this moment don't have names.
    // We can load the Base\CoreTOC.dat file in order
    // to get directory asset indexes, file names and extensions
    if(nError == ERROR_SUCCESS)
    {
        LPBYTE pbCoreTOC;
        DWORD cbCoreTOC = 0;

        // Load the entire file to memory
        pbCoreTOC = LoadFileToMemory(hs, "Base\\CoreTOC.dat", &cbCoreTOC);
        if(pbCoreTOC != NULL)
        {
            ParseCoreTOC(pRootHandler, pPackageMap, pbCoreTOC, pbCoreTOC + cbCoreTOC);
            CASC_FREE(pbCoreTOC);
        }
    }

    // Free the packages map
    if(pPackageMap != NULL)
        Map_Free(pPackageMap);
    if(pbPackagesDat != NULL)
        CASC_FREE(pbPackagesDat);
    return nError;
}
