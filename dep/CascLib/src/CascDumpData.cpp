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
#include "CascMndx.h"

#ifdef _DEBUG       // The entire feature is only valid for debug purposes

//-----------------------------------------------------------------------------
// Forward definitions

//LPBYTE VerifyLocaleBlock(PROOT_BLOCK_INFO pBlockInfo, LPBYTE pbFilePointer, LPBYTE pbFileEnd);

//-----------------------------------------------------------------------------
// Sort compare functions

static int CompareIndexEntries_FilePos(const void *, const void * pvIndexEntry1, const void * pvIndexEntry2)
{
    PCASC_INDEX_ENTRY pIndexEntry1 = (PCASC_INDEX_ENTRY)pvIndexEntry1;
    PCASC_INDEX_ENTRY pIndexEntry2 = (PCASC_INDEX_ENTRY)pvIndexEntry2;
    ULONGLONG FileOffset1 = ConvertBytesToInteger_5(pIndexEntry1->FileOffsetBE);
    ULONGLONG FileOffset2 = ConvertBytesToInteger_5(pIndexEntry2->FileOffsetBE);
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

void CascDumpIndexEntry(
    TCascStorage * /* hs */,
    TDumpContext * dc,
    PCASC_INDEX_ENTRY pIndexEntry,
    int /* nDumpLevel */)
{
    if(pIndexEntry != NULL)
    {
        ULONGLONG FileOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffsetBE);
        DWORD ArchIndex = (DWORD)(FileOffset >> 0x1E);
        DWORD FileSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);

        // Mask the file offset
        FileOffset &= 0x3FFFFFFF;
        dump_print(dc, "    data.%03u at 0x%08x (0x%lx bytes)\n",
                       ArchIndex,
                (DWORD)FileOffset,
                       FileSize);

        //if(nDumpLevel > 2)
        //{
        //    QueryKey.pbData = pIndexEntry->IndexKey;
        //    QueryKey.cbData = MD5_HASH_SIZE;
        //    if(CascOpenFileByIndexKey((HANDLE)hs, &QueryKey, 0, &hFile))
        //    {
        //        // Make sure that the data file is open and frame header loaded
        //        CascGetFileSize(hFile, NULL);
        //        hf = IsValidFileHandle(hFile);
        //        assert(hf->pStream != NULL);

        //        // Read the header area
        //        FileOffset = hf->HeaderOffset - BLTE_HEADER_DELTA;
        //        FileStream_Read(hf->pStream, &FileOffset, HeaderArea, sizeof(HeaderArea));
        //        CascCloseFile(hFile);

        //        // Dump the header area
        //        dump_print(dc, "    FileSize: %X  Rest: %s\n",
        //                       ConvertBytesToInteger_4_LE(&HeaderArea[0x10]),
        //                       StringFromBinary(&HeaderArea[0x14], 10, szBuffer));
        //    }
        //}
    }
    else
    {
        dump_print(dc, "    NO INDEX ENTRY\n");
    }
}

void CascDumpEncodingEntry(
    TCascStorage * hs,
    TDumpContext * dc,
    PCASC_ENCODING_ENTRY pEncodingEntry,
    int nDumpLevel)
{
    PCASC_INDEX_ENTRY pIndexEntry;
    QUERY_KEY QueryKey;
    LPBYTE pbIndexKey;
    char szMd5[MD5_STRING_SIZE+1];

    // If the encoding key exists
    if(pEncodingEntry != NULL)
    {
        dump_print(dc, "  Size %lx Key Count: %u\n",
                       ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE),
                       pEncodingEntry->KeyCount);

        // Dump all index keys
        pbIndexKey = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;
        for(DWORD j = 0; j < pEncodingEntry->KeyCount; j++, pbIndexKey += MD5_HASH_SIZE)
        {
            // Dump the index key
            dump_print(dc, "  %s\n", StringFromMD5(pbIndexKey, szMd5));

            // Dump the index entry as well
            if(nDumpLevel >= DUMP_LEVEL_INDEX_ENTRIES)
            {
                QueryKey.pbData = pbIndexKey;
                QueryKey.cbData = MD5_HASH_SIZE;
                pIndexEntry = FindIndexEntry(hs, &QueryKey);
                CascDumpIndexEntry(hs, dc, pIndexEntry, nDumpLevel);
            }
        }
    }
    else
    {
        dump_print(dc, "  NO ENCODING KEYS\n");
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
                ULONGLONG ArchOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffsetBE);
                DWORD ArchIndex = (DWORD)(ArchOffset >> 0x1E);
                DWORD FileSize;

                FileSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);
                ArchOffset &= 0x3FFFFFFF;

                fprintf(fp, " %02X  %08X %08X %s\n", ArchIndex, (DWORD)ArchOffset, FileSize, StringFromBinary(pIndexEntry->IndexKey, CASC_FILE_KEY_SIZE, szIndexKey));
            }

            CASC_FREE(ppIndexEntries);
        }

        fclose(fp);
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
