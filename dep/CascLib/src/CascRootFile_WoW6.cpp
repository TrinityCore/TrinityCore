/*****************************************************************************/
/* CascOpenStorage.cpp                    Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Storage functions for CASC                                                */
/* Note: WoW6 offsets refer to WoW.exe 6.0.3.19116 (32-bit)                  */
/* SHA1: c10e9ffb7d040a37a356b96042657e1a0c95c0dd                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascOpenStorage.cpp             */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local structures

#define ROOT_SEARCH_PHASE_INITIALIZING  0
#define ROOT_SEARCH_PHASE_LISTFILE      1
#define ROOT_SEARCH_PHASE_NAMELESS      2
#define ROOT_SEARCH_PHASE_FINISHED      2

// On-disk version of locale block
typedef struct _FILE_LOCALE_BLOCK
{
    DWORD NumberOfFiles;                        // Number of entries
    DWORD Flags;
    DWORD Locales;                              // File locale mask (CASC_LOCALE_XXX)

    // Followed by a block of 32-bit integers (count: NumberOfFiles)
    // Followed by the MD5 and file name hash (count: NumberOfFiles)

} FILE_LOCALE_BLOCK, *PFILE_LOCALE_BLOCK;

// On-disk version of root entry
typedef struct _FILE_ROOT_ENTRY
{
    ENCODING_KEY EncodingKey;                   // MD5 of the file
    ULONGLONG FileNameHash;                     // Jenkins hash of the file name

} FILE_ROOT_ENTRY, *PFILE_ROOT_ENTRY;


typedef struct _CASC_ROOT_BLOCK
{
    PFILE_LOCALE_BLOCK pLocaleBlockHdr;         // Pointer to the locale block
    PDWORD FileDataIds;                         // Pointer to the array of File Data IDs
    PFILE_ROOT_ENTRY pRootEntries;

} CASC_ROOT_BLOCK, *PCASC_ROOT_BLOCK;

// Root file entry for CASC storages without MNDX root file (World of Warcraft 6.0+)
// Does not match to the in-file structure of the root entry
typedef struct _CASC_FILE_ENTRY
{
    ENCODING_KEY EncodingKey;                       // File encoding key (MD5)
    ULONGLONG FileNameHash;                         // Jenkins hash of the file name
    DWORD FileDataId;                               // File Data Index
    DWORD Locales;                                  // Locale flags of the file

} CASC_FILE_ENTRY, *PCASC_FILE_ENTRY;

struct TRootHandler_WoW6 : public TRootHandler
{
    // Linear global list of file entries
    DYNAMIC_ARRAY FileTable;

    // Global map of FileName -> FileEntry
    PCASC_MAP pRootMap;

    // For counting files
    DWORD dwTotalFileCount;
    DWORD FileDataId;
};

// Prototype for root file parsing routine
typedef int (*PARSE_ROOT)(TRootHandler_WoW6 * pRootHandler, PCASC_ROOT_BLOCK pBlockInfo);

//-----------------------------------------------------------------------------
// Local functions

static bool IsFileDataIdName(const char * szFileName)
{
    BYTE BinaryValue[4];

    // File name must begin with "File", case insensitive
    if(AsciiToUpperTable_BkSlash[szFileName[0]] == 'F' &&
       AsciiToUpperTable_BkSlash[szFileName[1]] == 'I' &&
       AsciiToUpperTable_BkSlash[szFileName[2]] == 'L' &&
       AsciiToUpperTable_BkSlash[szFileName[3]] == 'E')
    {
        // Then, 8 hexadecimal digits must follow
        if(ConvertStringToBinary(szFileName + 4, 8, BinaryValue) == ERROR_SUCCESS)
        {
            // Must be followed by an extension or end-of-string
            return (szFileName[0x0C] == 0 || szFileName[0x0C] == '.');
        }
    }

    return false;
}

// Search by FileDataId
PCASC_FILE_ENTRY FindRootEntry(DYNAMIC_ARRAY & FileTable, DWORD FileDataId)
{
    PCASC_FILE_ENTRY pStartEntry = (PCASC_FILE_ENTRY)FileTable.ItemArray;
    PCASC_FILE_ENTRY pMidlEntry;
    PCASC_FILE_ENTRY pEndEntry = pStartEntry + FileTable.ItemCount - 1;
    int nResult;

    // Perform binary search on the table
    while(pStartEntry < pEndEntry)
    {
        // Calculate the middle of the interval
        pMidlEntry = pStartEntry + ((pEndEntry - pStartEntry) / 2);

        // Did we find it?
        nResult = (int)FileDataId - (int)pMidlEntry->FileDataId;
        if(nResult == 0)
            return pMidlEntry;

        // Move the interval to the left or right
        (nResult < 0) ? pEndEntry = pMidlEntry : pStartEntry = pMidlEntry + 1;
    }

    return NULL;
}

// Search by file name hash
// Also used in CascSearchFile
PCASC_FILE_ENTRY FindRootEntry(PCASC_MAP pRootMap, const char * szFileName, DWORD * PtrTableIndex)
{
    // Calculate the HASH value of the normalized file name
    ULONGLONG FileNameHash = CalcFileNameHash(szFileName);

    // Perform the hash search
    return (PCASC_FILE_ENTRY)Map_FindObject(pRootMap, &FileNameHash, PtrTableIndex);
}

LPBYTE VerifyLocaleBlock(PCASC_ROOT_BLOCK pBlockInfo, LPBYTE pbFilePointer, LPBYTE pbFileEnd)
{
    // Validate the file locale block
    pBlockInfo->pLocaleBlockHdr = (PFILE_LOCALE_BLOCK)pbFilePointer;
    pbFilePointer = (LPBYTE)(pBlockInfo->pLocaleBlockHdr + 1);
    if(pbFilePointer > pbFileEnd)
        return NULL;

    // Validate the array of 32-bit integers
    pBlockInfo->FileDataIds = (PDWORD)pbFilePointer;
    pbFilePointer = (LPBYTE)(pBlockInfo->FileDataIds + pBlockInfo->pLocaleBlockHdr->NumberOfFiles);
    if(pbFilePointer > pbFileEnd)
        return NULL;

    // Validate the array of root entries
    pBlockInfo->pRootEntries = (PFILE_ROOT_ENTRY)pbFilePointer;
    pbFilePointer = (LPBYTE)(pBlockInfo->pRootEntries + pBlockInfo->pLocaleBlockHdr->NumberOfFiles);
    if(pbFilePointer > pbFileEnd)
        return NULL;

    // Return the position of the next block
    return pbFilePointer;
}

static int ParseRoot_CountFiles(
    TRootHandler_WoW6 * pRootHandler,
    PCASC_ROOT_BLOCK pRootBlock)
{
    // Add the file count to the total file count
    pRootHandler->dwTotalFileCount += pRootBlock->pLocaleBlockHdr->NumberOfFiles;
    return ERROR_SUCCESS;
}

static int ParseRoot_AddRootEntries(
    TRootHandler_WoW6 * pRootHandler,
    PCASC_ROOT_BLOCK pRootBlock)
{
    PCASC_FILE_ENTRY pFileEntry;

    // Sanity checks
    assert(pRootHandler->FileTable.ItemArray != NULL);
    assert(pRootHandler->FileTable.ItemCountMax != 0);

    // WoW.exe (build 19116): Blocks with zero files are skipped
    for(DWORD i = 0; i < pRootBlock->pLocaleBlockHdr->NumberOfFiles; i++)
    {
        // Create new entry, with overflow check
        if(pRootHandler->FileTable.ItemCount >= pRootHandler->FileTable.ItemCountMax)
            return ERROR_INSUFFICIENT_BUFFER;
        pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);

        // (004147A3) Prepare the CASC_FILE_ENTRY structure
        pFileEntry->FileNameHash = pRootBlock->pRootEntries[i].FileNameHash;
        pFileEntry->FileDataId = pRootHandler->FileDataId + pRootBlock->FileDataIds[i];
        pFileEntry->Locales = pRootBlock->pLocaleBlockHdr->Locales;
        pFileEntry->EncodingKey = pRootBlock->pRootEntries[i].EncodingKey;

        // Also, insert the entry to the map
        Map_InsertObject(pRootHandler->pRootMap, pFileEntry, &pFileEntry->FileNameHash);

        // Update the local File Data Id
        assert((pFileEntry->FileDataId + 1) > pFileEntry->FileDataId);
        pRootHandler->FileDataId = pFileEntry->FileDataId + 1;

        // Move to the next root entry
        pFileEntry++;
    }

    return ERROR_SUCCESS;
}

static int ParseWowRootFileInternal(
    TRootHandler_WoW6 * pRootHandler,
    PARSE_ROOT pfnParseRoot,
    LPBYTE pbRootFile,
    LPBYTE pbRootFileEnd,
    DWORD dwLocaleMask,
    bool bLoadBlocksWithFlags80,
    BYTE HighestBitValue)
{
    CASC_ROOT_BLOCK RootBlock;

    // Now parse the root file
    while(pbRootFile < pbRootFileEnd)
    {
        // Validate the file locale block
        pbRootFile = VerifyLocaleBlock(&RootBlock, pbRootFile, pbRootFileEnd);
        if(pbRootFile == NULL)
            break;

        // WoW.exe (build 19116): Entries with flag 0x100 set are skipped
        if(RootBlock.pLocaleBlockHdr->Flags & 0x100)
            continue;

        // WoW.exe (build 19116): Entries with flag 0x80 set are skipped if arg_4 is set to FALSE (which is by default)
        if((RootBlock.pLocaleBlockHdr->Flags & 0x80) && bLoadBlocksWithFlags80 == 0)
            continue;

        // WoW.exe (build 19116): Entries with (flags >> 0x1F) not equal to arg_8 are skipped
        if((RootBlock.pLocaleBlockHdr->Flags >> 0x1F) != HighestBitValue)
            continue;

        // WoW.exe (build 19116): Locales other than defined mask are skipped too
        if((RootBlock.pLocaleBlockHdr->Locales & dwLocaleMask) == 0)
            continue;

        // Now call the custom function
        pfnParseRoot(pRootHandler, &RootBlock);
    }

    return ERROR_SUCCESS;
}

/*
    // Code from WoW.exe
    if(dwLocaleMask == CASC_LOCALE_DUAL_LANG)
    {
        // Is this english version of WoW?
        if(arg_4 == CASC_LOCALE_BIT_ENUS)
        {
            LoadWowRootFileLocales(hs, pbRootFile, cbRootFile, CASC_LOCALE_ENGB, false, HighestBitValue);
            LoadWowRootFileLocales(hs, pbRootFile, cbRootFile, CASC_LOCALE_ENUS, false, HighestBitValue);
            return ERROR_SUCCESS;
        }

        // Is this portuguese version of WoW?
        if(arg_4 == CASC_LOCALE_BIT_PTBR)
        {
            LoadWowRootFileLocales(hs, pbRootFile, cbRootFile, CASC_LOCALE_PTPT, false, HighestBitValue);
            LoadWowRootFileLocales(hs, pbRootFile, cbRootFile, CASC_LOCALE_PTBR, false, HighestBitValue);
        }
    }

    LoadWowRootFileLocales(hs, pbRootFile, cbRootFile, (1 << arg_4), false, HighestBitValue);
*/

static int ParseWowRootFile2(
    TRootHandler_WoW6 * pRootHandler,
    PARSE_ROOT pfnParseRoot,
    LPBYTE pbRootFile,
    LPBYTE pbRootFileEnd,
    DWORD dwLocaleMask,
    BYTE HighestBitValue)
{
    // Load the locale as-is
    ParseWowRootFileInternal(pRootHandler, pfnParseRoot, pbRootFile, pbRootFileEnd, dwLocaleMask, false, HighestBitValue);

    // If we wanted enGB, we also load enUS for the missing files
    if(dwLocaleMask == CASC_LOCALE_ENGB)
        ParseWowRootFileInternal(pRootHandler, pfnParseRoot, pbRootFile, pbRootFileEnd, CASC_LOCALE_ENUS, false, HighestBitValue);

    if(dwLocaleMask == CASC_LOCALE_PTPT)
        ParseWowRootFileInternal(pRootHandler, pfnParseRoot, pbRootFile, pbRootFileEnd, CASC_LOCALE_PTBR, false, HighestBitValue);

    return ERROR_SUCCESS;
}

// WoW.exe: 004146C7 (BuildManifest::Load)
static int ParseWowRootFile(
    TRootHandler_WoW6 * pRootHandler,
    PARSE_ROOT pfnParseRoot,
    LPBYTE pbRootFile,
    LPBYTE pbRootFileEnd,
    DWORD dwLocaleMask)
{
    ParseWowRootFile2(pRootHandler, pfnParseRoot, pbRootFile, pbRootFileEnd, dwLocaleMask, 0);
    ParseWowRootFile2(pRootHandler, pfnParseRoot, pbRootFile, pbRootFileEnd, dwLocaleMask, 1);
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Implementation of WoW6 root file

static int WowHandler_Insert(
    TRootHandler_WoW6 * pRootHandler,
    const char * szFileName,
    LPBYTE pbEncodingKey)
{
    PCASC_FILE_ENTRY pFileEntry;
    DWORD FileDataId = 0;

    // Don't let the number of items to overflow
    if(pRootHandler->FileTable.ItemCount >= pRootHandler->FileTable.ItemCountMax)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Insert the item to the linear file list
    pFileEntry = (PCASC_FILE_ENTRY)Array_Insert(&pRootHandler->FileTable, NULL, 1);
    if(pFileEntry != NULL)
    {
        // Get the file data ID of the previous item (0 if this is the first one)
        if(pRootHandler->FileTable.ItemCount > 1)
            FileDataId = pFileEntry[-1].FileDataId;

        // Fill-in the new entry
        pFileEntry->EncodingKey  = *(PENCODING_KEY)pbEncodingKey;
        pFileEntry->FileNameHash = CalcFileNameHash(szFileName);
        pFileEntry->FileDataId   = FileDataId + 1;
        pFileEntry->Locales      = CASC_LOCALE_ALL;

        // Verify collisions (debug version only)
        assert(Map_FindObject(pRootHandler->pRootMap, &pFileEntry->FileNameHash, NULL) == NULL);

        // Insert the entry to the map
        Map_InsertObject(pRootHandler->pRootMap, pFileEntry, &pFileEntry->FileNameHash);
    }

    return ERROR_SUCCESS;
}

static LPBYTE WowHandler_Search(TRootHandler_WoW6 * pRootHandler, TCascSearch * pSearch, PDWORD /* PtrFileSize */, PDWORD PtrLocaleFlags)
{
    PCASC_FILE_ENTRY pFileEntry;

    // Only if we have a listfile
    if(pSearch->pCache != NULL)
    {
        // Keep going through the listfile
        while(ListFile_GetNext(pSearch->pCache, pSearch->szMask, pSearch->szFileName, MAX_PATH))
        {
            // Find the root entry
            pFileEntry = FindRootEntry(pRootHandler->pRootMap, pSearch->szFileName, NULL);
            if(pFileEntry != NULL)
            {
                // Give the caller the locale mask
                if(PtrLocaleFlags != NULL)
                    PtrLocaleFlags[0] = pFileEntry->Locales;
                return pFileEntry->EncodingKey.Value;
            }
        }
    }

    // No more files
    return NULL;
}

static LPBYTE WowHandler_GetKey(TRootHandler_WoW6 * pRootHandler, const char * szFileName)
{
    PCASC_FILE_ENTRY pFileEntry;
    DWORD FileDataId;
    BYTE FileDataIdLE[4];

    // Open by FileDataId. The file name must be as following:
    // File########.xxx, where '#' are hexa-decimal numbers (case insensitive).
    // Extension is ignored in that case
    if(IsFileDataIdName(szFileName))
    {
        ConvertStringToBinary(szFileName + 4, 8, FileDataIdLE);
        FileDataId = ConvertBytesToInteger_4(FileDataIdLE);

        pFileEntry = FindRootEntry(pRootHandler->FileTable, FileDataId);
    }
    else
    {
        // Find by the file name hash
        pFileEntry = FindRootEntry(pRootHandler->pRootMap, szFileName, NULL);
    }

    return (pFileEntry != NULL) ? pFileEntry->EncodingKey.Value : NULL;
}

static void WowHandler_EndSearch(TRootHandler_WoW6 * /* pRootHandler */, TCascSearch * pSearch)
{
    if(pSearch->pRootContext != NULL)
        CASC_FREE(pSearch->pRootContext);
    pSearch->pRootContext = NULL;
}

static void WowHandler_Close(TRootHandler_WoW6 * pRootHandler)
{
    if(pRootHandler != NULL)
    {
        Array_Free(&pRootHandler->FileTable);
        Map_Free(pRootHandler->pRootMap);
        CASC_FREE(pRootHandler);
    }
}

#ifdef _DEBUG
static void TRootHandlerWoW6_Dump(
    TCascStorage * hs,
    TDumpContext * dc,                                      // Pointer to an opened file
    LPBYTE pbRootFile,
    DWORD cbRootFile,
    const TCHAR * szListFile,
    int nDumpLevel)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    CASC_ROOT_BLOCK BlockInfo;
    PLISTFILE_MAP pListMap;
    QUERY_KEY EncodingKey;
    LPBYTE pbRootFileEnd = pbRootFile + cbRootFile;
    LPBYTE pbFilePointer;
    char szOneLine[0x100];
    DWORD i;

    // Create the listfile map
    pListMap = ListFile_CreateMap(szListFile);

    // Dump the root entries
    for(pbFilePointer = pbRootFile; pbFilePointer <= pbRootFileEnd; )
    {
        // Validate the root block
        pbFilePointer = VerifyLocaleBlock(&BlockInfo, pbFilePointer, pbRootFileEnd);
        if(pbFilePointer == NULL)
            break;

        // Dump the locale block
        dump_print(dc, "Flags: %08X  Locales: %08X  NumberOfFiles: %u\n"
                       "=========================================================\n",
                       BlockInfo.pLocaleBlockHdr->Flags,
                       BlockInfo.pLocaleBlockHdr->Locales,
                       BlockInfo.pLocaleBlockHdr->NumberOfFiles);

        // Dump the hashes and encoding keys
        for(i = 0; i < BlockInfo.pLocaleBlockHdr->NumberOfFiles; i++)
        {
            // Dump the entry
            dump_print(dc, "%08X %08X-%08X %s %s\n",
                           (DWORD)(BlockInfo.FileDataIds[i]),
                           (DWORD)(BlockInfo.pRootEntries[i].FileNameHash >> 0x20),
                           (DWORD)(BlockInfo.pRootEntries[i].FileNameHash),
                           StringFromMD5(BlockInfo.pRootEntries[i].EncodingKey.Value, szOneLine),
                           ListFile_FindName(pListMap, BlockInfo.pRootEntries[i].FileNameHash));

            // Find the encoding entry in the encoding table
            if(nDumpLevel >= DUMP_LEVEL_ENCODING_FILE)
            {
                EncodingKey.pbData = BlockInfo.pRootEntries[i].EncodingKey.Value;
                EncodingKey.cbData = MD5_HASH_SIZE;
                pEncodingEntry = FindEncodingEntry(hs, &EncodingKey, NULL);
                CascDumpEncodingEntry(hs, dc, pEncodingEntry, nDumpLevel);
            }
        }

        // Put extra newline
        dump_print(dc, "\n");
    }

    ListFile_FreeMap(pListMap);
}
#endif

//-----------------------------------------------------------------------------
// Public functions

int RootHandler_CreateWoW6(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile, DWORD dwLocaleMask)
{
    TRootHandler_WoW6 * pRootHandler;
    LPBYTE pbRootFileEnd = pbRootFile + cbRootFile;
    int nError;

    // Verify the size
    if(pbRootFile == NULL || cbRootFile <= sizeof(PFILE_LOCALE_BLOCK))
        nError = ERROR_FILE_CORRUPT;

    // Allocate the root handler object
    hs->pRootHandler = pRootHandler = CASC_ALLOC(TRootHandler_WoW6, 1);
    if(pRootHandler == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill-in the handler functions
    memset(pRootHandler, 0, sizeof(TRootHandler_WoW6));
    pRootHandler->Insert      = (ROOT_INSERT)WowHandler_Insert;
    pRootHandler->Search      = (ROOT_SEARCH)WowHandler_Search;
    pRootHandler->EndSearch   = (ROOT_ENDSEARCH)WowHandler_EndSearch;
    pRootHandler->GetKey      = (ROOT_GETKEY)WowHandler_GetKey;
    pRootHandler->Close       = (ROOT_CLOSE)WowHandler_Close;

#ifdef _DEBUG
    pRootHandler->Dump = TRootHandlerWoW6_Dump;    // Support for ROOT file dump
#endif  // _DEBUG

    // Count the files that are going to be loaded
    ParseWowRootFile(pRootHandler, ParseRoot_CountFiles, pbRootFile, pbRootFileEnd, dwLocaleMask);
    pRootHandler->dwTotalFileCount += CASC_EXTRA_FILES;

    // Create linear table that will contain all root items
    nError = Array_Create(&pRootHandler->FileTable, CASC_FILE_ENTRY, pRootHandler->dwTotalFileCount);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Create the map of FileHash ->FileEntry
    pRootHandler->pRootMap = Map_Create(pRootHandler->dwTotalFileCount, sizeof(ULONGLONG), FIELD_OFFSET(CASC_FILE_ENTRY, FileNameHash));
    if(pRootHandler->pRootMap == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Parse the root file again and insert all files to the map
    ParseWowRootFile(pRootHandler, ParseRoot_AddRootEntries, pbRootFile, pbRootFileEnd, dwLocaleMask);
    return ERROR_SUCCESS;
}
