/*****************************************************************************/
/* CascRootFile_WoW.cpp                   Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Storage functions for CASC                                                */
/* Note: WoW offsets refer to WoW.exe 6.0.3.19116 (32-bit)                   */
/* SHA1: c10e9ffb7d040a37a356b96042657e1a0c95c0dd                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascRootFile_WoW.cpp            */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local structures

#define ROOT_SEARCH_PHASE_INITIALIZING  0
#define ROOT_SEARCH_PHASE_LISTFILE      1
#define ROOT_SEARCH_PHASE_NAMELESS      2
#define ROOT_SEARCH_PHASE_FINISHED      3

// Known dwRegion values returned from sub_661316 (7.0.3.22210 x86 win), also referred by lua GetCurrentRegion
#define WOW_REGION_US              0x01
#define WOW_REGION_KR              0x02
#define WOW_REGION_EU              0x03
#define WOW_REGION_TW              0x04
#define WOW_REGION_CN              0x05

typedef enum _ROOT_FORMAT
{
    RootFormatWoW6x,                            // WoW 6.x - 8.1.x
    RootFormatWoW82                             // WoW 8.2 or newer
} ROOT_FORMAT, *PROOT_FORMAT;

// ROOT file header, since 8.2
typedef struct _FILE_ROOT_HEADER_82
{
    DWORD Signature;                            // Must be CASC_WOW82_ROOT_SIGNATURE
    DWORD TotalFiles;
    DWORD FilesWithNameHash;
} FILE_ROOT_HEADER_82, *PFILE_ROOT_HEADER_82;

// On-disk version of root group. A root group contains a group of file
// with the same locale and file flags
typedef struct _FILE_ROOT_GROUP_HEADER
{
    DWORD NumberOfFiles;                        // Number of entries
    DWORD ContentFlags;
    DWORD LocaleFlags;                          // File locale mask (CASC_LOCALE_XXX)

    // Followed by a block of file data IDs (count: NumberOfFiles)
    // Followed by the MD5 and file name hash (count: NumberOfFiles)

} FILE_ROOT_GROUP_HEADER, *PFILE_ROOT_GROUP_HEADER;

// On-disk version of root entry. Only present in versions 6.x - 8.1.xx
// Each root entry represents one file in the CASC storage
// In WoW 8.2 and newer, CKey and FileNameHash are split into separate arrays
// and FileNameHash is optional
typedef struct _FILE_ROOT_ENTRY
{
    CONTENT_KEY CKey;                           // MD5 of the file
    ULONGLONG FileNameHash;                     // Jenkins hash of the file name

} FILE_ROOT_ENTRY, *PFILE_ROOT_ENTRY;

typedef struct _FILE_ROOT_GROUP
{
    FILE_ROOT_GROUP_HEADER Header;
    PDWORD FileDataIds;                         // Pointer to the array of File Data IDs

    PFILE_ROOT_ENTRY pRootEntries;              // Valid for WoW 6.x - 8.1.x
    PCONTENT_KEY pCKeyEntries;                  // Valid for WoW 8.2 or newer
    PULONGLONG pHashes;                         // Valid for WoW 8.2 or newer (optional)

} FILE_ROOT_GROUP, *PFILE_ROOT_GROUP;

//-----------------------------------------------------------------------------
// TRootHandler_WoW interface / implementation

#define FTREE_FLAGS_WOW (FTREE_FLAG_USE_DATA_ID | FTREE_FLAG_USE_LOCALE_FLAGS | FTREE_FLAG_USE_CONTENT_FLAGS)

struct TRootHandler_WoW : public TFileTreeRoot
{
    public:

    TRootHandler_WoW(ROOT_FORMAT RFormat, DWORD HashlessFileCount) : TFileTreeRoot(FTREE_FLAGS_WOW)
    {
        // Turn off the "we know file names" bit 
        FileCounterHashless = HashlessFileCount;
        FileCounter = 0;
        RootFormat = RFormat;

        // Update the flags based on format
        switch(RootFormat)
        {
            case RootFormatWoW6x:
                dwFeatures |= CASC_FEATURE_ROOT_CKEY | CASC_FEATURE_FNAME_HASHES | CASC_FEATURE_FILE_DATA_IDS | CASC_FEATURE_LOCALE_FLAGS | CASC_FEATURE_CONTENT_FLAGS;
                break;

            case RootFormatWoW82:
                dwFeatures |= CASC_FEATURE_ROOT_CKEY | CASC_FEATURE_FNAME_HASHES_OPTIONAL | CASC_FEATURE_FILE_DATA_IDS | CASC_FEATURE_LOCALE_FLAGS | CASC_FEATURE_CONTENT_FLAGS;
                break;
        }
    }

    static LPBYTE CaptureRootHeader(FILE_ROOT_HEADER_82 & RootHeader, LPBYTE pbRootPtr, LPBYTE pbRootEnd)
    {
        // Validate the root file header
        if((pbRootPtr + sizeof(FILE_ROOT_HEADER_82)) >= pbRootEnd)
            return NULL;
        memcpy(&RootHeader, pbRootPtr, sizeof(FILE_ROOT_HEADER_82));

        // Verify the root file header
        if(RootHeader.Signature != CASC_WOW82_ROOT_SIGNATURE)
            return NULL;
        if(RootHeader.FilesWithNameHash > RootHeader.TotalFiles)
            return NULL;

        return pbRootPtr + sizeof(FILE_ROOT_HEADER_82);
    }

    LPBYTE CaptureRootGroup(FILE_ROOT_GROUP & RootGroup, LPBYTE pbRootPtr, LPBYTE pbRootEnd)
    {
        // Reset the entire root group structure
        memset(&RootGroup, 0, sizeof(FILE_ROOT_GROUP));

        // Validate the locale block header
        if((pbRootPtr + sizeof(FILE_ROOT_GROUP_HEADER)) >= pbRootEnd)
            return NULL;
        memcpy(&RootGroup.Header, pbRootPtr, sizeof(FILE_ROOT_GROUP_HEADER));
        pbRootPtr = pbRootPtr + sizeof(FILE_ROOT_GROUP_HEADER);

        // Validate the array of file data IDs
        if((pbRootPtr + (sizeof(DWORD) * RootGroup.Header.NumberOfFiles)) >= pbRootEnd)
            return NULL;
        RootGroup.FileDataIds = (PDWORD)pbRootPtr;
        pbRootPtr = pbRootPtr + (sizeof(DWORD) * RootGroup.Header.NumberOfFiles);

        // Add the number of files in this block to the number of files loaded
        FileCounter += RootGroup.Header.NumberOfFiles;

        // Validate the array of root entries
        switch(RootFormat)
        {
            case RootFormatWoW6x:
                if((pbRootPtr + (sizeof(FILE_ROOT_ENTRY) * RootGroup.Header.NumberOfFiles)) > pbRootEnd)
                    return NULL;
                RootGroup.pRootEntries = (PFILE_ROOT_ENTRY)pbRootPtr;

                // Return the position of the next block
                return pbRootPtr + (sizeof(FILE_ROOT_ENTRY) * RootGroup.Header.NumberOfFiles);

            case RootFormatWoW82:
                
                // Verify the position of array of CONTENT_KEY
                if((pbRootPtr + (sizeof(CONTENT_KEY) * RootGroup.Header.NumberOfFiles)) > pbRootEnd)
                    return NULL;
                RootGroup.pCKeyEntries = (PCONTENT_KEY)pbRootPtr;
                pbRootPtr = pbRootPtr + (sizeof(CONTENT_KEY) * RootGroup.Header.NumberOfFiles);

                // Also include array of file hashes
                if(!(RootGroup.Header.ContentFlags & CASC_CFLAG_NO_NAME_HASH))
                {
                    if((pbRootPtr + (sizeof(ULONGLONG) * RootGroup.Header.NumberOfFiles)) > pbRootEnd)
                        return NULL;
                    RootGroup.pHashes = (PULONGLONG)pbRootPtr;
                    pbRootPtr = pbRootPtr + (sizeof(ULONGLONG) * RootGroup.Header.NumberOfFiles);
                }

                return pbRootPtr;

            default:
                return NULL;
        }
    }

    DWORD ParseWowRootFile_AddFiles_6x(TCascStorage * hs, FILE_ROOT_GROUP & RootGroup)
    {
        PFILE_ROOT_ENTRY pRootEntry = RootGroup.pRootEntries;
        PCASC_CKEY_ENTRY pCKeyEntry;
        DWORD FileDataId = 0;

        // Sanity check
        assert(RootGroup.pRootEntries != NULL);

        // WoW.exe (build 19116): Blocks with zero files are skipped
        for(DWORD i = 0; i < RootGroup.Header.NumberOfFiles; i++, pRootEntry++)
        {
            // Set the file data ID
            FileDataId = FileDataId + RootGroup.FileDataIds[i];
//          BREAKIF(FileDataId == 2823765);

            // Find the item in the central storage. Insert it to the tree
            if((pCKeyEntry = FindCKeyEntry_CKey(hs, pRootEntry->CKey.Value)) != NULL)
            {
                if(pRootEntry->FileNameHash != 0)
                {
                    FileTree.InsertByHash(pCKeyEntry, pRootEntry->FileNameHash, FileDataId, RootGroup.Header.LocaleFlags, RootGroup.Header.ContentFlags);
                }
                else
                {
                    FileTree.InsertById(pCKeyEntry, FileDataId, RootGroup.Header.LocaleFlags, RootGroup.Header.ContentFlags);
                }
            }

            // Update the file data ID
            assert((FileDataId + 1) > FileDataId);
            FileDataId++;
        }

        return ERROR_SUCCESS;
    }

    DWORD ParseWowRootFile_AddFiles_82(TCascStorage * hs, FILE_ROOT_GROUP & RootGroup)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        PCONTENT_KEY pCKey = RootGroup.pCKeyEntries;
        DWORD FileDataId = 0;

        // Sanity check
        assert(RootGroup.pCKeyEntries != NULL);

        // WoW.exe (build 19116): Blocks with zero files are skipped
        for(DWORD i = 0; i < RootGroup.Header.NumberOfFiles; i++, pCKey++)
        {
            // Set the file data ID
            FileDataId = FileDataId + RootGroup.FileDataIds[i];
            //printf("File Data ID: %u\n", FileDataId);

            // Find the item in the central storage. Insert it to the tree
            if((pCKeyEntry = FindCKeyEntry_CKey(hs, pCKey->Value)) != NULL)
            {
                // If we know the file name hash, we're gonna insert it by hash AND file data id.
                // If we don't know the hash, we're gonna insert it just by file data id.
                if(RootGroup.pHashes != NULL && RootGroup.pHashes[i] != 0)
                {
                    FileTree.InsertByHash(pCKeyEntry, RootGroup.pHashes[i], FileDataId, RootGroup.Header.LocaleFlags, RootGroup.Header.ContentFlags);
                }
                else
                {
                    FileTree.InsertById(pCKeyEntry, FileDataId, RootGroup.Header.LocaleFlags, RootGroup.Header.ContentFlags);
                }
            }

            // Update the file data ID
            assert((FileDataId + 1) > FileDataId);
            FileDataId++;
        }

        return ERROR_SUCCESS;
    }

    DWORD ParseWowRootFile_Level2(
        TCascStorage * hs,
        LPBYTE pbRootPtr,
        LPBYTE pbRootEnd,
        DWORD dwLocaleMask,
        BYTE bOverrideLowViolence,
        BYTE bAudioLocale)
    {
        FILE_ROOT_GROUP RootBlock;

        // Reset the total file counter
        FileCounter = 0;

        // Now parse the root file
        while(pbRootPtr < pbRootEnd)
        {
            //char szMessage[0x100];
            //StringCchPrintfA(szMessage, _countof(szMessage), "%p\n", (pbRootEnd - pbRootPtr));
            //OutputDebugStringA(szMessage);

            // Validate the file locale block
            pbRootPtr = CaptureRootGroup(RootBlock, pbRootPtr, pbRootEnd);
            if(pbRootPtr == NULL)
                return ERROR_BAD_FORMAT;

            // WoW.exe (build 19116): Entries with flag 0x100 set are skipped
            if(RootBlock.Header.ContentFlags & CASC_CFLAG_DONT_LOAD)
                continue;

            // WoW.exe (build 19116): Entries with flag 0x80 set are skipped if overrideArchive CVAR is set to FALSE (which is by default in non-chinese clients)
            if((RootBlock.Header.ContentFlags & CASC_CFLAG_LOW_VIOLENCE) && bOverrideLowViolence == 0)
                continue;

            // WoW.exe (build 19116): Entries with (flags >> 0x1F) not equal to bAudioLocale are skipped
            if((RootBlock.Header.ContentFlags >> 0x1F) != bAudioLocale)
                continue;

            // WoW.exe (build 19116): Locales other than defined mask are skipped too
            if(RootBlock.Header.LocaleFlags != 0 && (RootBlock.Header.LocaleFlags & dwLocaleMask) == 0)
                continue;

            // Now call the custom function
            switch(RootFormat)
            {
                case RootFormatWoW82:
                    ParseWowRootFile_AddFiles_82(hs, RootBlock);
                    break;

                case RootFormatWoW6x:
                    ParseWowRootFile_AddFiles_6x(hs, RootBlock);
                    break;

                default:
                    return ERROR_NOT_SUPPORTED;
            }
        }

        return ERROR_SUCCESS;
    }

    /*
    #define CASC_LOCALE_BIT_ENUS            0x01
    #define CASC_LOCALE_BIT_KOKR            0x02
    #define CASC_LOCALE_BIT_RESERVED        0x03
    #define CASC_LOCALE_BIT_FRFR            0x04
    #define CASC_LOCALE_BIT_DEDE            0x05
    #define CASC_LOCALE_BIT_ZHCN            0x06
    #define CASC_LOCALE_BIT_ESES            0x07
    #define CASC_LOCALE_BIT_ZHTW            0x08
    #define CASC_LOCALE_BIT_ENGB            0x09
    #define CASC_LOCALE_BIT_ENCN            0x0A
    #define CASC_LOCALE_BIT_ENTW            0x0B
    #define CASC_LOCALE_BIT_ESMX            0x0C
    #define CASC_LOCALE_BIT_RURU            0x0D
    #define CASC_LOCALE_BIT_PTBR            0x0E
    #define CASC_LOCALE_BIT_ITIT            0x0F
    #define CASC_LOCALE_BIT_PTPT            0x10

        // dwLocale is obtained from a WOW_LOCALE_* to CASC_LOCALE_BIT_* mapping (sub_6615D0 in 7.0.3.22210 x86 win)
        // because (ENUS, ENGB) and (PTBR, PTPT) pairs share the same value on WOW_LOCALE_* enum
        // dwRegion is used to distinguish them
        if(dwRegion == WOW_REGION_EU)
        {
            // Is this english version of WoW?
            if(dwLocale == CASC_LOCALE_BIT_ENUS)
            {
                LoadWowRootFileLocales(hs, pbRootPtr, cbRootFile, CASC_LOCALE_ENGB, bOverrideArchive, bAudioLocale);
                LoadWowRootFileLocales(hs, pbRootPtr, cbRootFile, CASC_LOCALE_ENUS, bOverrideArchive, bAudioLocale);
                return ERROR_SUCCESS;
            }

            // Is this portuguese version of WoW?
            if(dwLocale == CASC_LOCALE_BIT_PTBR)
            {
                LoadWowRootFileLocales(hs, pbRootPtr, cbRootFile, CASC_LOCALE_PTPT, bOverrideArchive, bAudioLocale);
                LoadWowRootFileLocales(hs, pbRootPtr, cbRootFile, CASC_LOCALE_PTBR, bOverrideArchive, bAudioLocale);
            }
        }
        else
            LoadWowRootFileLocales(hs, pbRootPtr, cbRootFile, (1 << dwLocale), bOverrideArchive, bAudioLocale);
    */

    DWORD ParseWowRootFile_Level1(
        TCascStorage * hs, 
        LPBYTE pbRootPtr,
        LPBYTE pbRootEnd,
        DWORD dwLocaleMask,
        BYTE bAudioLocale)
    {
        DWORD dwErrCode;

        // Load the locale as-is
        dwErrCode = ParseWowRootFile_Level2(hs, pbRootPtr, pbRootEnd, dwLocaleMask, false, bAudioLocale);
        if (dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // If we wanted enGB, we also load enUS for the missing files
        if(dwLocaleMask == CASC_LOCALE_ENGB)
            ParseWowRootFile_Level2(hs, pbRootPtr, pbRootEnd, CASC_LOCALE_ENUS, false, bAudioLocale);

        if(dwLocaleMask == CASC_LOCALE_PTPT)
            ParseWowRootFile_Level2(hs, pbRootPtr, pbRootEnd, CASC_LOCALE_PTBR, false, bAudioLocale);

        return ERROR_SUCCESS;
    }

    // WoW.exe: 004146C7 (BuildManifest::Load)
    DWORD Load(TCascStorage * hs, LPBYTE pbRootPtr, LPBYTE pbRootEnd, DWORD dwLocaleMask)
    {
        DWORD dwErrCode;

        dwErrCode = ParseWowRootFile_Level1(hs, pbRootPtr, pbRootEnd, dwLocaleMask, 0);
        if (dwErrCode == ERROR_SUCCESS)
            dwErrCode = ParseWowRootFile_Level1(hs, pbRootPtr, pbRootEnd, dwLocaleMask, 1);

        return dwErrCode;
    }

    // Search for files
    PCASC_CKEY_ENTRY Search(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
    {
        // If we have a listfile, we'll feed the listfile entries to the file tree
        if(pSearch->pCache != NULL && pSearch->bListFileUsed == false)
        {
            PCASC_FILE_NODE pFileNode;
            ULONGLONG FileNameHash;
            size_t nLength;
            DWORD FileDataId = CASC_INVALID_ID;
            char szFileName[MAX_PATH];

            if(RootFormat == RootFormatWoW82)
            {
                // Keep going through the listfile
                for(;;)
                {
                    // Retrieve the next line from the list file. Ignore lines that are too long to fit in the buffer
                    nLength = ListFile_GetNext(pSearch->pCache, szFileName, _countof(szFileName), &FileDataId);
                    if(nLength == 0)
                    {
                        if(GetCascError() == ERROR_INSUFFICIENT_BUFFER)
                            continue;
                        break;
                    }

                    // Try to find the file node by file data id
                    pFileNode = FileTree.FindById(FileDataId);
                    if(pFileNode != NULL && pFileNode->NameLength == 0)
                    {
                        FileTree.SetNodeFileName(pFileNode, szFileName);
                    }
                }
            }
            else
            {
                // Keep going through the listfile
                for(;;)
                {
                    // Retrieve the next line from the list file. Ignore lines that are too long to fit in the buffer
                    nLength = ListFile_GetNextLine(pSearch->pCache, szFileName, _countof(szFileName));
                    if(nLength == 0)
                    {
                        if(GetCascError() == ERROR_INSUFFICIENT_BUFFER)
                            continue;
                        break;
                    }

                    // Calculate the hash of the file name
                    FileNameHash = CalcFileNameHash(szFileName);

                    // Try to find the file node by file name hash
                    pFileNode = FileTree.Find(FileNameHash);
                    if(pFileNode != NULL && pFileNode->NameLength == 0)
                    {
                        FileTree.SetNodeFileName(pFileNode, szFileName);
                    }
                }
            }
            pSearch->bListFileUsed = true;
        }

        // Let the file tree root give us the file names
        return TFileTreeRoot::Search(pSearch, pFindData);
    }

    ROOT_FORMAT RootFormat;                 // Root file format
    DWORD FileCounterHashless;              // Number of files for which we don't have hash. Meaningless for WoW before 8.2
    DWORD FileCounter;                      // Counter of loaded files. Only used during loading of ROOT file
};

//-----------------------------------------------------------------------------
// Public functions

DWORD RootHandler_CreateWoW(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile, DWORD dwLocaleMask)
{
    TRootHandler_WoW * pRootHandler = NULL;
    FILE_ROOT_HEADER_82 RootHeader;
    ROOT_FORMAT RootFormat = RootFormatWoW6x;
    LPBYTE pbRootEnd = pbRootFile + cbRootFile;
    LPBYTE pbRootPtr;
    DWORD FileCounterHashless = 0;
    DWORD dwErrCode = ERROR_BAD_FORMAT;

    // Check for the new format (World of Warcraft 8.2, build 30170)
    pbRootPtr = TRootHandler_WoW::CaptureRootHeader(RootHeader, pbRootFile, pbRootEnd);
    if(pbRootPtr != NULL)
    {
        FileCounterHashless = RootHeader.TotalFiles - RootHeader.FilesWithNameHash;
        RootFormat = RootFormatWoW82;
        pbRootFile = pbRootPtr;
    }

    // Create the WOW handler
    pRootHandler = new TRootHandler_WoW(RootFormat, FileCounterHashless);
    if(pRootHandler != NULL)
    {
        // Load the root directory. If load failed, we free the object
        dwErrCode = pRootHandler->Load(hs, pbRootFile, pbRootEnd, dwLocaleMask);
        if(dwErrCode != ERROR_SUCCESS)
        {
            delete pRootHandler;
            pRootHandler = NULL;
        }
    }

    // Assign the root directory (or NULL) and return error
    hs->pRootHandler = pRootHandler;
    return dwErrCode;
}

