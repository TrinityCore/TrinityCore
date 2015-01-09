/*****************************************************************************/
/* CascDumpData.cpp                       Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* System-dependent directory functions for CascLib                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 07.05.14  1.00  Lad  The first version of CascDumpData.cpp                */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"
#include "CascMndxRoot.h"

#ifdef _DEBUG       // The entire file is only valid for debug purposes

//-----------------------------------------------------------------------------
// Local functions

static char * StringFromIndexKey(LPBYTE md5, char * szBuffer)
{
    return StringFromBinary(md5, 9, szBuffer);
}

static char * StringFromMD5(LPBYTE md5, char * szBuffer)
{
    return StringFromBinary(md5, MD5_HASH_SIZE, szBuffer);
}

static int CompareIndexEntries_FilePos(const void *, const void * pvIndexEntry1, const void * pvIndexEntry2)
{
    PCASC_INDEX_ENTRY pIndexEntry1 = (PCASC_INDEX_ENTRY)pvIndexEntry1;
    PCASC_INDEX_ENTRY pIndexEntry2 = (PCASC_INDEX_ENTRY)pvIndexEntry2;
    ULONGLONG FileOffset1 = ConvertBytesToInteger_5(pIndexEntry1->FileOffset);
    ULONGLONG FileOffset2 = ConvertBytesToInteger_5(pIndexEntry2->FileOffset);
    DWORD ArchIndex1 = (DWORD)(FileOffset1 >> 0x1E);
    DWORD ArchIndex2 = (DWORD)(FileOffset2 >> 0x1E);

    // First, compare the archive index
    if(ArchIndex1 < ArchIndex2)
        return -1;
    if(ArchIndex1 > ArchIndex2)
        return +1;

    // Second, compare the archive offset
    FileOffset1 &= 0x3FFFFFFF;
    FileOffset2 &= 0x3FFFFFFF;
    if(FileOffset1 < FileOffset2)
        return -1;
    if(FileOffset1 > FileOffset2)
        return +1;

    return 0;
}


static char ** CreateFileNameArray(TCascStorage * hs, const TCHAR * szListFile)
{
    PCASC_ROOT_ENTRY pRootEntry;
    char ** FileNameArray = NULL;
    void * pvListFile;
    size_t nRootIndex;
    char szFileName1[MAX_PATH+1];
    char szFileName2[MAX_PATH+1];

    // Open the listfile stream and initialize the listfile cache
    pvListFile = ListFile_OpenExternal(szListFile);
    if(pvListFile != NULL)
    {
        // Allocate the array of file names
        FileNameArray = CASC_ALLOC(char*, hs->nRootEntries);
        if(FileNameArray != NULL)
        {
            // Zero the name array
            memset(FileNameArray, 0, hs->nRootEntries * sizeof(char *));

            // Perform search
            while(ListFile_GetNext(pvListFile, "*", szFileName1, MAX_PATH))
            {
                // Create normalized name
                strcpy(szFileName2, szFileName1);
                NormalizeFileName_UpperBkSlash(szFileName2);

                // Try to find the root entry
                pRootEntry = FindFirstRootEntry(hs, szFileName2, &nRootIndex);
                if(pRootEntry != NULL)
                {
                    assert(nRootIndex < hs->nRootEntries);
                    if(FileNameArray[nRootIndex] == NULL)
                        FileNameArray[nRootIndex] = NewStr(szFileName1, 0);
                }
            }
        }

        // Close the listfile cache
        ListFile_Free(pvListFile);
    }

    return FileNameArray;
}

static void FreeFileNameArray(TCascStorage * hs, char ** FileNameArray)
{
    if(FileNameArray != NULL)
    {
        // Free all sub-entries
        for(size_t i = 0; i < hs->nRootEntries; i++)
        {
            if(FileNameArray[i] != NULL)
                CASC_FREE(FileNameArray[i]);
        }

        // Free the array itself
        CASC_FREE(FileNameArray);
    }
}

static void DumpIndexKey(
    FILE * fp,
    TCascStorage * hs,
    LPBYTE pbEncodingKey,
    PCASC_INDEX_ENTRY * ppIndexEntries)
{
    PCASC_INDEX_ENTRY pIndexEntry;
    QUERY_KEY QueryKey;
    size_t EntryIndex = 0;
    char szMd5[MD5_STRING_SIZE];

    QueryKey.pbData = pbEncodingKey;
    QueryKey.cbData = MD5_HASH_SIZE;
    pIndexEntry = FindIndexEntry(hs, &QueryKey);
    if(pIndexEntry != NULL)
    {
        ULONGLONG FileOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffset);
        DWORD ArchIndex = (DWORD)(FileOffset >> 0x1E);
        DWORD FileSize = *(PDWORD)pIndexEntry->FileSize;

        // Mark the index entry as dumped
        ppIndexEntries[EntryIndex] = NULL;

        // Mask the file offset
        FileOffset &= 0x3FFFFFFF;
        fprintf(fp, "    Index: %s, ArchIdx: %02x  FileOffset %08x  FileSize: %lx\n",
                    StringFromIndexKey(pIndexEntry->IndexKey, szMd5),
                    ArchIndex,
             (DWORD)FileOffset,
                    FileSize);
    }
    else
    {
        fprintf(fp, "    NO INDEX ENTRY\n");
    }
}

static void DumpEncodingEntry(
    FILE * fp,
    TCascStorage * hs,
    PCASC_ENCODING_ENTRY pEncodingEntry,
    PCASC_INDEX_ENTRY * ppIndexEntries)
{
    LPBYTE pbEncodingKey;
    char szMd5[MD5_STRING_SIZE];

    fprintf(fp, "  Encoding Key: %s  Key Count: %u  Size: %lx\n",
                StringFromMD5(pEncodingEntry->EncodingKey, szMd5),
                pEncodingEntry->KeyCount,
                ConvertBytesToInteger_4(pEncodingEntry->FileSizeBytes));

    // If there is a file key
    if(pEncodingEntry->KeyCount != 0)
    {                 
        // Get the first encoding key
        pbEncodingKey = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;

        // Dump all encoding keys
        for(DWORD j = 0; j < pEncodingEntry->KeyCount; j++)
        {
            fprintf(fp, "  Index Key: %s\n", StringFromMD5(pbEncodingKey, szMd5));
            DumpIndexKey(fp, hs, pbEncodingKey, ppIndexEntries);
            pbEncodingKey += MD5_HASH_SIZE;
        }
    }
    else
    {
        fprintf(fp, "    ZERO FILE KEYS\n");
        return;
    }
}

static void DumpEncodingEntry(
    FILE * fp,
    TCascStorage * hs,
    PCASC_ROOT_ENTRY pRootEntry,
    PCASC_ENCODING_ENTRY * ppEncodingKeys,
    PCASC_INDEX_ENTRY * ppIndexEntries)
{
    PCASC_ENCODING_ENTRY pEncodingKey;
    QUERY_KEY QueryKey;
    size_t EntryIndex = 0;

    // Find the encoding key
    QueryKey.pbData = pRootEntry->EncodingKey;
    QueryKey.cbData = MD5_HASH_SIZE;
    pEncodingKey = FindEncodingEntry(hs, &QueryKey, &EntryIndex);
    if(pEncodingKey == NULL)
    {
        fprintf(fp, "  NO ENCODING KEY\n");
        return;
    }

    // Get the file key, clear the encoding key
    ppEncodingKeys[EntryIndex] = NULL;
    DumpEncodingEntry(fp, hs, pEncodingKey, ppIndexEntries);
}

static void DumpRootEntries(FILE * fp, TCascStorage * hs, char ** FileNameArray)
{
    PCASC_ENCODING_ENTRY * ppEncodingEntries;      // Array of encoding entries
    PCASC_INDEX_ENTRY * ppIndexEntries;         // Complete list of key entries for all files
    const char * szFileName = NULL;
    ULONGLONG PrevNameHash = (ULONGLONG)-1;
    char szMd5[MD5_STRING_SIZE];

    // Create copy of the encoding keys and file keys
    ppEncodingEntries = CASC_ALLOC(PCASC_ENCODING_ENTRY, hs->nEncodingEntries);
    ppIndexEntries = CASC_ALLOC(PCASC_INDEX_ENTRY, hs->pIndexEntryMap->ItemCount);
    if(ppEncodingEntries && ppIndexEntries)
    {
        // Copy all pointers
        memcpy(ppEncodingEntries, hs->ppEncodingEntries, hs->nEncodingEntries * sizeof(PCASC_ENCODING_ENTRY));
        Map_EnumObjects(hs->pIndexEntryMap, (void **)ppIndexEntries);

        // Parse all entries
        for(size_t i = 0; i < hs->nRootEntries; i++)
        {
            PCASC_ROOT_ENTRY pRootEntry = hs->ppRootEntries[i];
            const char * szDuplicate = "";

            // Check duplicates
            if(pRootEntry->FileNameHash != PrevNameHash)
                szFileName = FileNameArray[i];
            else
                szDuplicate = "(DUPLICATE)  ";

            // Dump the root entry
            fprintf(fp, "NameHash: %016llx  Locales: %08lx  MD5: %s  %sFileName: %s\n",
                pRootEntry->FileNameHash,
                pRootEntry->Locales,
                StringFromMD5(pRootEntry->EncodingKey, szMd5),
                szDuplicate,
                szFileName);

            DumpEncodingEntry(fp, hs, pRootEntry, ppEncodingEntries, ppIndexEntries);
            PrevNameHash = pRootEntry->FileNameHash;
            fprintf(fp, "\n");
        }

        // Dump all orphaned encoding keys
        for(size_t i = 0; i < hs->nEncodingEntries; i++)
        {
            if(ppEncodingEntries[i] != NULL)
            {
                fprintf(fp, "[NO ROOT KEY]\n");
                
                DumpEncodingEntry(fp, hs, ppEncodingEntries[i], ppIndexEntries);
                ppEncodingEntries[i] = NULL;

                fprintf(fp, "\n");
            }
        }


        CASC_FREE(ppIndexEntries);
        CASC_FREE(ppEncodingEntries);
    }
}

//-----------------------------------------------------------------------------
// Public functions

void CascDumpSparseArray(const char * szFileName, void * pvSparseArray)
{
    TSparseArray * pSparseArray = (TSparseArray *)pvSparseArray;
    FILE * fp;

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)                             
    {
        // Write header
        fprintf(fp, "##   Value\n--   -----\n");
                          
        // Write the values
        for(DWORD i = 0; i < pSparseArray->TotalItemCount; i++)
        {
            DWORD Value = 0;

            if(pSparseArray->IsItemPresent(i))
            {
                Value = pSparseArray->GetItemValue(i);
                fprintf(fp, "%02X    %02X\n", i, Value);
            }
            else
            {
                fprintf(fp, "%02X    --\n", i);
            }
        }

        fclose(fp);
    }
}

void CascDumpNameFragTable(const char * szFileName, void * pMarFile)
{
    TFileNameDatabase * pDB = ((PMAR_FILE)pMarFile)->pDatabasePtr->pDB;
    FILE * fp;

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)                             
    {
        PNAME_FRAG pNameTable = pDB->NameFragTable.NameFragArray;
        const char * szNames = pDB->IndexStruct_174.NameFragments.CharArray;
        const char * szLastEntry;
        char szMatchType[0x100];

        // Dump the table header
        fprintf(fp, "Indx  ThisHash NextHash FragOffs\n");
        fprintf(fp, "----  -------- -------- --------\n");

        // Dump all name entries
        for(DWORD i = 0; i < pDB->NameFragTable.ItemCount; i++)
        {
            // Reset both match types
            szMatchType[0] = 0;
            szLastEntry = "";

            // Only if the table entry is not empty
            if(pNameTable->ItemIndex != 0xFFFFFFFF)
            {
                // Prepare the entry
                if(IS_SINGLE_CHAR_MATCH(pDB->NameFragTable, i))
                    sprintf(szMatchType, "SINGLE_CHAR (\'%c\')", (pNameTable->FragOffs & 0xFF));
                else
                    sprintf(szMatchType, "NAME_FRAGMT (\"%s\")", szNames + pNameTable->FragOffs);
            }

            // Dump the entry
            fprintf(fp, "0x%02X  %08x %08x %08x %s%s\n", i, pNameTable->ItemIndex,
                                                            pNameTable->NextIndex,
                                                            pNameTable->FragOffs,
                                                            szMatchType,
                                                            szLastEntry);
            pNameTable++;
        }
        fclose(fp);
    }
}

void CascDumpFileNames(const char * szFileName, void * pvMarFile)
{
    TMndxFindResult Struct1C;
    PMAR_FILE pMarFile = (PMAR_FILE)pvMarFile;
    FILE * fp;
    char szNameBuff[0x200];
    bool bFindResult;

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)
    {
        // Set an empty path as search mask (?)
        Struct1C.SetSearchPath("", 0);

        // Keep searching
        for(;;)
        {
            // Search the next file name
            pMarFile->pDatabasePtr->sub_1956CE0(&Struct1C, &bFindResult);

            // Stop the search in case of failure
            if(!bFindResult)
                break;

            // Printf the found file name
            memcpy(szNameBuff, Struct1C.szFoundPath, Struct1C.cchFoundPath);
            szNameBuff[Struct1C.cchFoundPath] = 0;
            fprintf(fp, "%s\n", szNameBuff);
        }

        fclose(fp);
    }

    // Free the search structures
    Struct1C.FreeStruct40();
}

void CascDumpMndxRoot(const char * szFileName, PCASC_MNDX_INFO pMndxInfo)
{
    PCASC_MNDX_ENTRY pMndxEntry;
    FILE * fp;
    char szMd5[MD5_STRING_SIZE];

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)
    {
        fprintf(fp, "Indx Fl+Asset EncodingKey                      FileSize\n==== ======== ================================ ========\n");
        for(DWORD i = 0; i < pMndxInfo->MndxEntriesValid; i++)
        {
            pMndxEntry = pMndxInfo->ppValidEntries[i];

            fprintf(fp, "%04X %08X %s %08X\n", i,
                                               pMndxEntry->Flags,
                                               StringFromMD5(pMndxEntry->EncodingKey, szMd5),
                                               pMndxEntry->FileSize);
        }
        fclose(fp);
    }
}

void CascDumpIndexEntries(const char * szFileName, TCascStorage * hs)
{
    PCASC_INDEX_ENTRY * ppIndexEntries;
    FILE * fp;
    size_t nIndexEntries = hs->pIndexEntryMap->ItemCount;
    char szIndexKey[0x40];

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)
    {
        // Create linear aray
        ppIndexEntries = CASC_ALLOC(PCASC_INDEX_ENTRY, nIndexEntries);
        if(ppIndexEntries != NULL)
        {
            // Obtain the linear array of index entries
            Map_EnumObjects(hs->pIndexEntryMap, (void **)ppIndexEntries);

            // Sort the array by archive number and archive offset
            qsort_pointer_array((void **)ppIndexEntries, nIndexEntries, CompareIndexEntries_FilePos, NULL);

            // Parse the array
            fprintf(fp, "ArNo ArOffset FileSize IndexKey\n==== ======== ======== ================================\n");
            for(size_t i = 0; i < nIndexEntries; i++)
            {
                PCASC_INDEX_ENTRY pIndexEntry = ppIndexEntries[i];
                ULONGLONG ArchOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffset);
                DWORD ArchIndex = (DWORD)(ArchOffset >> 0x1E);
                DWORD FileSize;

                FileSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSize);
                ArchOffset &= 0x3FFFFFFF;
                
                fprintf(fp, " %02X  %08X %08X %s\n", ArchIndex, ArchOffset, FileSize, StringFromBinary(pIndexEntry->IndexKey, CASC_FILE_KEY_SIZE, szIndexKey));
            }

            CASC_FREE(ppIndexEntries);
        }

        fclose(fp);
    }
}

void CascDumpStorage(const char * szFileName, TCascStorage * hs, const TCHAR * szListFile)
{
    char ** FileNameArray = NULL;
    FILE * fp;

    // Validate the storage handle
    if(hs != NULL)
    {
        // Create the dump file
        fp = fopen(szFileName, "wt");
        if(fp != NULL)
        {
            // If we also have listfile, open it
            if(szListFile != NULL)
                FileNameArray = CreateFileNameArray(hs, szListFile);

            // Dump all root keys
            fprintf(fp, "Root Entries\n=========\n\n");
            DumpRootEntries(fp, hs, FileNameArray);

            FreeFileNameArray(hs, FileNameArray);
            fclose(fp);
        }
    }
}


void CascDumpFile(const char * szFileName, HANDLE hFile)
{
    FILE * fp;
    DWORD dwBytesRead = 1;
    DWORD dwFilePos = CascSetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    BYTE Buffer[0x1000];

    // Create the dump file
    fp = fopen(szFileName, "wb");
    if(fp != NULL)
    {
        // Read data as long as we can, write as long as we can
        while(dwBytesRead != 0)
        {
            // Read from the source file
            if(!CascReadFile(hFile, Buffer, sizeof(Buffer), &dwBytesRead))
                break;

            // Write to the destination file
            if(fwrite(Buffer, 1, dwBytesRead, fp) != dwBytesRead)
                break;
        }

        // Close the local file
        fclose(fp);

        // Restore the file pointer
        CascSetFilePointer(hFile, dwFilePos, NULL, FILE_BEGIN);
    }
}

#endif // _DEBUG
