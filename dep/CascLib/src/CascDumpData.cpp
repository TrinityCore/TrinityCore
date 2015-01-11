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
// Forward definitions

LPBYTE VerifyLocaleBlock(PROOT_BLOCK_INFO pBlockInfo, LPBYTE pbFilePointer, LPBYTE pbFileEnd);

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
// Local functions

static char * StringFromMD5(LPBYTE md5, char * szBuffer)
{
    return StringFromBinary(md5, MD5_HASH_SIZE, szBuffer);
}

static char * FormatFileName(const char * szFormat, TCascStorage * hs)
{
    char * szFileName;
    char * szSrc;
    char * szTrg;

    // Create copy of the file name
    szFileName = szSrc = szTrg = NewStr(szFormat, 0);
    if(szFileName != NULL)
    {
        // Format the file name
        while(szSrc[0] != 0)
        {
            if(szSrc[0] == '%')
            {
                // Replace "%build%" with a build number
                if(!strncmp(szSrc, "%build%", 7))
                {
                    szTrg += sprintf(szTrg, "%u", hs->dwBuildNumber);
                    szSrc += 7;
                    continue;
                }
            }

            // Just copy the character
            *szTrg++ = *szSrc++;
        }

        // Terminate the target file name
        szTrg[0] = 0;
    }

    return szFileName;
}

FILE * CreateDumpFile(const char * szFormat, TCascStorage * hs)
{
    FILE * fp = NULL;
    char * szFileName;

    // Validate the storage handle
    if(hs != NULL)
    {
        // Format the real file name
        szFileName = FormatFileName(szFormat, hs);
        if(szFileName != NULL)
        {
            // Create the dump file
            fp = fopen(szFileName, "wt");
            CASC_FREE(szFileName);
        }
    }

    return fp;
}

static void DumpIndexKey(
    FILE * fp,
    TCascStorage * hs,
    LPBYTE pbIndexKey,
    int nDumpLevel)
{
    PCASC_INDEX_ENTRY pIndexEntry;
    TCascFile * hf;
    QUERY_KEY QueryKey;
    HANDLE hFile;
    BYTE HeaderArea[MAX_HEADER_AREA_SIZE];
    char szBuffer[0x20];

    QueryKey.pbData = pbIndexKey;
    QueryKey.cbData = MD5_HASH_SIZE;
    pIndexEntry = FindIndexEntry(hs, &QueryKey);
    if(pIndexEntry != NULL)
    {
        ULONGLONG FileOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffsetBE);
        DWORD ArchIndex = (DWORD)(FileOffset >> 0x1E);
        DWORD FileSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);

        // Mask the file offset
        FileOffset &= 0x3FFFFFFF;
        fprintf(fp, "    data.%03u at 0x%08x (0x%lx bytes)\n",
                    ArchIndex,
             (DWORD)FileOffset,
                    FileSize);

        if(nDumpLevel > 2)
        {
            QueryKey.pbData = pIndexEntry->IndexKey;
            QueryKey.cbData = MD5_HASH_SIZE;
            if(CascOpenFileByIndexKey((HANDLE)hs, &QueryKey, 0, &hFile))
            {
                // Make sure that the data file is open and frame header loaded
                CascGetFileSize(hFile, NULL);
                hf = IsValidFileHandle(hFile);
                assert(hf->pStream != NULL);

                // Read the header area
                FileOffset = hf->HeaderOffset - BLTE_HEADER_DELTA;
                FileStream_Read(hf->pStream, &FileOffset, HeaderArea, sizeof(HeaderArea));
                CascCloseFile(hFile);

                // Dump the header area
                fprintf(fp, "    FileSize: %X  Rest: %s\n",
                            ConvertBytesToInteger_4_LE(&HeaderArea[0x10]),
                            StringFromBinary(&HeaderArea[0x14], 10, szBuffer));
            }
        }
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
    int nDumpLevel)
{
    LPBYTE pbIndexKey;
    char szMd5[MD5_STRING_SIZE];

    // If the encoding key exists
    if(pEncodingEntry != NULL)
    {
        fprintf(fp, "  Size %lx Key Count: %u\n",
                    ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE),
                    pEncodingEntry->KeyCount);

        // Dump all index keys
        pbIndexKey = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;
        for(DWORD j = 0; j < pEncodingEntry->KeyCount; j++)
        {
            fprintf(fp, "  %s\n", StringFromMD5(pbIndexKey, szMd5));
            DumpIndexKey(fp, hs, pbIndexKey, nDumpLevel);
            pbIndexKey += MD5_HASH_SIZE;
        }

    }
    else
    {
        fprintf(fp, "  NO ENCODING KEYS\n");
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
    PCASC_ROOT_ENTRY_MNDX pRootEntry;
    FILE * fp;
    char szMd5[MD5_STRING_SIZE];

    // Create the dump file
    fp = fopen(szFileName, "wt");
    if(fp != NULL)
    {
        fprintf(fp, "Indx Fl+Asset EncodingKey                      FileSize\n==== ======== ================================ ========\n");
        for(DWORD i = 0; i < pMndxInfo->MndxEntriesValid; i++)
        {
            pRootEntry = pMndxInfo->ppValidEntries[i];

            fprintf(fp, "%04X %08X %s %08X\n", i,
                                               pRootEntry->Flags,
                                               StringFromMD5(pRootEntry->EncodingKey, szMd5),
                                               pRootEntry->FileSize);
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
                ULONGLONG ArchOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffsetBE);
                DWORD ArchIndex = (DWORD)(ArchOffset >> 0x1E);
                DWORD FileSize;

                FileSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);
                ArchOffset &= 0x3FFFFFFF;
                
                fprintf(fp, " %02X  %08X %08X %s\n", ArchIndex, ArchOffset, FileSize, StringFromBinary(pIndexEntry->IndexKey, CASC_FILE_KEY_SIZE, szIndexKey));
            }

            CASC_FREE(ppIndexEntries);
        }

        fclose(fp);
    }
}

void CascDumpRootFile(
    TCascStorage * hs,
    LPBYTE pbRootFile,
    DWORD cbRootFile,
    const char * szFormat,
    const TCHAR * szListFile,
    int nDumpLevel)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    ROOT_BLOCK_INFO BlockInfo;
    PLISTFILE_MAP pListMap;
    QUERY_KEY EncodingKey;
    LPBYTE pbRootFileEnd = pbRootFile + cbRootFile;
    LPBYTE pbFilePointer;
    FILE * fp;
    char szOneLine[0x100];
    DWORD i;

    // This function only dumps WoW-style root file
    assert(*(PDWORD)pbRootFile != CASC_MNDX_SIGNATURE);

    // Create the dump file
    fp = CreateDumpFile(szFormat, hs);
    if(fp != NULL)                      
    {
        // Create the listfile map
//      DWORD dwTickCount = GetTickCount();
        pListMap = ListFile_CreateMap(szListFile);
//      dwTickCount = GetTickCount() - dwTickCount;

        // Dump the root entries as-is
        for(pbFilePointer = pbRootFile; pbFilePointer <= pbRootFileEnd; )
        {
            // Validate the root block
            pbFilePointer = VerifyLocaleBlock(&BlockInfo, pbFilePointer, pbRootFileEnd);
            if(pbFilePointer == NULL)
                break;

            // Dump the locale block
            fprintf(fp, "Flags: %08X  Locales: %08X  NumberOfFiles: %u\n"
                        "=========================================================\n",
                        BlockInfo.pLocaleBlockHdr->Flags, 
                        BlockInfo.pLocaleBlockHdr->Locales,
                        BlockInfo.pLocaleBlockHdr->NumberOfFiles);

            // Dump the hashes and encoding keys
            for(i = 0; i < BlockInfo.pLocaleBlockHdr->NumberOfFiles; i++)
            {
                // Dump the entry
                fprintf(fp, "%08X %08X-%08X %s %s\n",
                            (DWORD)(BlockInfo.pInt32Array[i]),
                            (DWORD)(BlockInfo.pRootEntries[i].FileNameHash >> 0x20),
                            (DWORD)(BlockInfo.pRootEntries[i].FileNameHash),
                            StringFromMD5((LPBYTE)BlockInfo.pRootEntries[i].EncodingKey, szOneLine),
                            ListFile_FindName(pListMap, BlockInfo.pRootEntries[i].FileNameHash));

                // Find the encoding entry in the encoding table
                if(nDumpLevel > 1)
                {
                    EncodingKey.pbData = (LPBYTE)BlockInfo.pRootEntries[i].EncodingKey;
                    EncodingKey.cbData = MD5_HASH_SIZE;
                    pEncodingEntry = FindEncodingEntry(hs, &EncodingKey, NULL);
                    DumpEncodingEntry(fp, hs, pEncodingEntry, nDumpLevel);
                }
            }

            // Put extra newline
            fprintf(fp, "\n");
        }
        
        ListFile_FreeMap(pListMap);
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
