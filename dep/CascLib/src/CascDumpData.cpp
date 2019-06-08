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

#ifdef _DEBUG       // The entire feature is only valid for debug purposes

//-----------------------------------------------------------------------------
// Forward definitions

int CaptureEncodingHeader(CASC_ENCODING_HEADER & EnHeader, LPBYTE pbFileData, size_t cbFileData);
int CaptureDownloadHeader(CASC_DOWNLOAD_HEADER & DlHeader, LPBYTE pbFileData, size_t cbFileData);
int CaptureDownloadEntry(CASC_DOWNLOAD_HEADER & DlHeader, CASC_DOWNLOAD_ENTRY & DlEntry, LPBYTE pbFilePtr, LPBYTE pbFileEnd);
int CaptureDownloadTag(CASC_DOWNLOAD_HEADER & DlHeader, CASC_TAG_ENTRY1 & DlTag, LPBYTE pbFilePtr, LPBYTE pbFileEnd);

//-----------------------------------------------------------------------------
// Local functions

static char * StringFromLPTSTR(const TCHAR * szString, char * szBuffer, size_t cchBuffer)
{
    char * szSaveBuffer = szBuffer;
    char * szBufferEnd = szBuffer + cchBuffer - 1;

    while (szBuffer < szBufferEnd && szString[0] != 0)
        *szBuffer++ = (char)*szString++;
    szBuffer[0] = 0;

    return szSaveBuffer;
}

// Either opens a dump file or returns "stdout"
static FILE * OpenDumpFile(const char * szDumpFile)
{
    if(szDumpFile != NULL)
    {
        return fopen(szDumpFile, "wt");
    }
    else
    {
        return stdout;
    }
}

// Closes the dump file if it was open by OpenDumpFile
static void CloseDumpFile(const char * szDumpFile, FILE * fp)
{
    if(szDumpFile != NULL && fp != NULL)
        fclose(fp);
}

static void DumpKey(FILE * fp, const char * szInFormat, LPBYTE pbData, size_t cbData)
{
    const char * szFormatSpec;
    LPBYTE pbDataEnd = pbData + cbData;
    char szFormat[0x100];
    char szKey[MD5_STRING_SIZE + 1];

    // First line: Copy the line with the complete format
    CascStrCopy(szFormat, _countof(szFormat), szInFormat);
    szFormatSpec = strstr(szFormat, "%s");

    // Dump all keys, every one on a new line
    while(pbData < pbDataEnd)
    {
        // Fump the line
        StringFromBinary(pbData, MD5_HASH_SIZE, szKey);
        fprintf(fp, szFormat, szKey);

        // If there will be more lines, then we clear the entire part until "%s"
        if(szFormatSpec != NULL)
            memset(szFormat, ' ', (szFormatSpec - szFormat));
        
        // Move pointers
        pbData += MD5_HASH_SIZE;
    }
}

/*
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
        PNAME_FRAG pNameTable = pDB->NameFragTable.ItemArray;
        const char * szNames = pDB->IndexStruct_174.ItemArray;
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
                    CascStrPrintf(szMatchType, _countof(szMatchType), "SINGLE_CHAR (\'%c\')", (pNameTable->FragOffs & 0xFF));
                else
                    CascStrPrintf(szMatchType, _countof(szMatchType), "NAME_FRAGMT (\"%s\")", szNames + pNameTable->FragOffs);
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


void DumpEKeyEntries(TCascStorage * hs, FILE * fp)
{
    // Dump header
    fprintf(fp, "=== Ekey Entries ============================================================\n");

    // Dump index entries from all index files
    for(int file = 0; file < CASC_INDEX_COUNT; file++)
    {
        PCASC_EKEY_ENTRY pEKeyEntry = hs->IndexFile[file].pEKeyEntries;
        DWORD nEKeyEntries = hs->IndexFile[file].nEKeyEntries;

        // Only if they are present
        if(pEKeyEntry && nEKeyEntries)
        {
//          fprintf(fp, "--- Index: %03u --------------------------------------------------------------\n", file);
            for(DWORD entry = 0; entry < nEKeyEntries; entry++, pEKeyEntry++)
                DumpEKeyEntry(fp, pEKeyEntry->EKey, CASC_EKEY_SIZE, pEKeyEntry->StorageOffset, ConvertBytesToInteger_4_LE(pEKeyEntry->EncodedSize));
        }
    }

    // Dump tail
    fprintf(fp, "=============================================================================\n\n");
}
*/

//-----------------------------------------------------------------------------
// Dumping the ENCODING manifest
/*
static void DumpESpecEntries(FILE * fp, LPBYTE pbDataPtr, LPBYTE pbDataEnd)
{
    fprintf(fp, "--- ESpec Entries -----------------------------------------------------------\n");

    while(pbDataPtr < pbDataEnd)
    {
        const char * szESpecEntry = (const char *)pbDataPtr;

        // Find the end of the entry
        while((pbDataPtr < pbDataEnd) && (pbDataPtr[0] != 0))
        {
            pbDataPtr++;
        }

        // Dump the entry
        if(pbDataPtr[0] == 0)
        {
            fprintf(fp, "%s\n", szESpecEntry);
            pbDataPtr++;
        }
    }
}

static void DumpCKeyEntry(PCASC_CKEY_ENTRY pCKeyEntry, FILE * fp, DWORD nIndex)
{
    LPBYTE pbEKey;
    char szStringBuff[MD5_STRING_SIZE + 1];

    // Print the CKey and number of EKeys
    fprintf(fp, "[0x%02X] %s (EKeys: %02u): ", nIndex, StringFromBinary(pCKeyEntry->CKey, MD5_HASH_SIZE, szStringBuff), pCKeyEntry->EKeyCount);
    pbEKey = pCKeyEntry->EKey;

    // Print the EKeys
    for(USHORT i = 0; i < pCKeyEntry->EKeyCount; i++, pbEKey += MD5_HASH_SIZE)
        fprintf(fp, " %s ", StringFromBinary(pbEKey, MD5_HASH_SIZE, szStringBuff));
    fprintf(fp, "\n");
}

static void DumpCKeyPages(FILE * fp, CASC_ENCODING_HEADER & EnHeader, LPBYTE pbDataPtr, LPBYTE pbDataEnd)
{
    // Get the CKey page header and the page itself
    PFILE_CKEY_PAGE pPageHeader = (PFILE_CKEY_PAGE)pbDataPtr;
    LPBYTE pbPageEntry = (LPBYTE)(pPageHeader + EnHeader.CKeyPageCount);

    fprintf(fp, "--- CKey Pages --------------------------------------------------------------\n");
    for(DWORD i = 0; i < EnHeader.CKeyPageCount; i++, pPageHeader++)
    {
        LPBYTE pbCKeyEntry = pbPageEntry;
        LPBYTE pbEndOfPage = pbPageEntry + EnHeader.CKeyPageSize;
        DWORD nCKeyIndex = 0;

        // Check if there is enough space in the buffer
        if((pbPageEntry + EnHeader.CKeyPageSize) > pbDataEnd)
            break;

        DumpKey(fp, "First CKey:     %s\n", pPageHeader->FirstKey, EnHeader.CKeyLength);
        DumpKey(fp, "Page hash:      %s\n", pPageHeader->SegmentHash, MD5_HASH_SIZE);
        fprintf(fp, "\n");

        // Parse all CKey entries
        while(pbCKeyEntry <= pbEndOfPage)
        {
            PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)pbCKeyEntry;

            // Get pointer to the encoding entry
            if(pCKeyEntry->EKeyCount == 0)
                break;

            // Dump this encoding entry
            DumpCKeyEntry(pCKeyEntry, fp, nCKeyIndex++);

            // Move to the next encoding entry
            pbCKeyEntry += sizeof(FILE_CKEY_ENTRY) + ((pCKeyEntry->EKeyCount - 1) * EnHeader.CKeyLength);
        }

        // Move to the next segment
        pbPageEntry += EnHeader.CKeyPageSize;
        fprintf(fp, "\n");
    }
}

void DumpEncodingManifest(TCascStorage * hs, LPBYTE pbData, ULONG cbData, FILE * fp)
{
    // Dump header
    fprintf(fp, "=== ENCODING Manifest =======================================================\n");

    // Dump the encoding file
    if(hs->EncodingManifest.pbData && hs->EncodingManifest.cbData)
    {
        CASC_ENCODING_HEADER EnHeader;
        LPBYTE pbFilePtr = hs->EncodingManifest.pbData;
        DWORD cbDataSize;

        // Capture the header of the ENCODING file
        if(CaptureEncodingHeader(EnHeader, hs->EncodingManifest.pbData, hs->EncodingManifest.cbData) == ERROR_SUCCESS)
        {
            // Dump the ENCODING file info
            fprintf(fp, "Magic:            %u\n",   EnHeader.Magic);
            fprintf(fp, "Version:          %u\n",   EnHeader.Version);
            fprintf(fp, "CKey Length:      %02X\n", EnHeader.CKeyLength);
            fprintf(fp, "EKey Length:      %02X\n", EnHeader.EKeyLength);
            fprintf(fp, "CKey page size:   %08X\n", EnHeader.CKeyPageSize);
            fprintf(fp, "CKey page count:  %08X\n", EnHeader.CKeyPageCount);
            fprintf(fp, "EKey page size:   %08X\n", EnHeader.EKeyPageSize);
            fprintf(fp, "EKey page count:  %08X\n", EnHeader.EKeyPageCount);
            fprintf(fp, "ESpec block size: %08X\n", EnHeader.ESpecBlockSize);
            pbFilePtr += sizeof(FILE_ENCODING_HEADER);

            // Dump all ESpec entries
            DumpESpecEntries(fp, pbFilePtr, pbFilePtr + EnHeader.ESpecBlockSize);
            pbFilePtr += EnHeader.ESpecBlockSize;

            // Parse all CKey pages and dump them
            cbDataSize = EnHeader.CKeyPageCount * (sizeof(FILE_CKEY_PAGE) + EnHeader.CKeyPageSize);
            DumpCKeyPages(fp, EnHeader, pbFilePtr, pbFilePtr + cbDataSize);
            pbFilePtr += cbDataSize;
        }
    }
    else
    {
        fprintf(fp, "(empty)\n");
    }

    // Dump tail
    fprintf(fp, "=============================================================================\n\n");
}
*/
//-----------------------------------------------------------------------------
// Dumping the DOWNLOAD manifest
/*
static void DumpDownloadEntries(FILE * fp, CASC_DOWNLOAD_HEADER & DlHeader, LPBYTE pbDownloadPtr, LPBYTE pbDownloadEnd)
{
    fprintf(fp, "--- DOWNLOAD Entries --------------------------------------------------------\n");
    fprintf(fp, "Index    EKey                             FileSize   Checksum Flags    Prio\n");
    fprintf(fp, "-------- -------------------------------- ---------- -------- -------- ----\n");

    for(DWORD i = 0; i < DlHeader.EntryCount; i++)
    {
        CASC_DOWNLOAD_ENTRY DlEntry;
        char szEKey[MD5_STRING_SIZE+1];
        char szChksum[0x40];
        char szFlags[0x40];

        if(CaptureDownloadEntry(DlHeader, DlEntry, pbDownloadPtr, pbDownloadEnd) != ERROR_SUCCESS)
            break;

        // Dump the entry
        StringFromBinary(DlEntry.EKey, DlHeader.EKeyLength, szEKey);
        CascStrPrintf(szChksum, _countof(szChksum), (DlHeader.EntryHasChecksum ? "%08X" : "<none>  "), DlEntry.Checksum);
        CascStrPrintf(szFlags,  _countof(szFlags), (DlHeader.FlagByteSize ? "%08X" : "<none>  "), DlEntry.Flags);
        fprintf(fp, "[%06X] %-16s %010I64X %s %s %04X\n", i, szEKey, DlEntry.FileSize, szChksum, szFlags, DlEntry.Priority);

        // Move to the next entry
        pbDownloadPtr += DlHeader.EntryLength;
    }

    fprintf(fp, "\n");
}

static void DumpDownloadTags(FILE * fp, CASC_DOWNLOAD_HEADER & DlHeader, LPBYTE pbFilePtr, LPBYTE pbFileEnd)
{
    CASC_TAG_ENTRY1 DlTag;

    fprintf(fp, "--- DOWNLOAD Tags ---------------------------------------------------------\n");
    for(DWORD i = 0; i < DlHeader.TagCount; i++)
    {
        // Capture the download tag
        if(CaptureDownloadTag(DlHeader, DlTag, pbFilePtr, pbFileEnd) != ERROR_SUCCESS)
            break;

        // Dump the tag
        fprintf(fp, "[%02X]: %08X = %s\n", i, DlTag.TagValue, DlTag.szTagName);
        pbFilePtr += DlTag.TagLength;
    }
}

void DumpDownloadManifest(TCascStorage * hs, FILE * fp)
{
    // Dump header
    fprintf(fp, "=== DOWNLOAD Manifest =======================================================\n");

    // Dump the encoding file
    if(hs->DownloadManifest.pbData && hs->DownloadManifest.cbData)
    {
        CASC_DOWNLOAD_HEADER DlHeader;
        LPBYTE pbFileEnd = hs->DownloadManifest.pbData + hs->DownloadManifest.cbData;
        LPBYTE pbFilePtr = hs->DownloadManifest.pbData;

        // Capture the header of the ENCODING file
        if(CaptureDownloadHeader(DlHeader, hs->DownloadManifest.pbData, hs->DownloadManifest.cbData) == ERROR_SUCCESS)
        {
            // Dump the DOWNLOAD header
            fprintf(fp, "Magic:            %u\n",   DlHeader.Magic);
            fprintf(fp, "Version:          %u\n",   DlHeader.Version);
            fprintf(fp, "EKey Length:      %02X\n", DlHeader.EKeyLength);
            fprintf(fp, "Checksum present: %s\n",   DlHeader.EntryHasChecksum ? "Yes" : "No");
            fprintf(fp, "Entry Count:      %08X\n", DlHeader.EntryCount);
            fprintf(fp, "Tag Count:        %08X\n", DlHeader.TagCount);
            fprintf(fp, "Flag byte size:   %08X\n", DlHeader.FlagByteSize);
            fprintf(fp, "Base priority:    %08X\n", DlHeader.BasePriority);
            fprintf(fp, "Header length:    %08X\n", (DWORD)DlHeader.HeaderLength);
            fprintf(fp, "Entry length:     %08X\n", (DWORD)DlHeader.EntryLength);
            fprintf(fp, "\n");
            pbFilePtr += DlHeader.HeaderLength;

            // Dump all download entries
            DumpDownloadEntries(fp, DlHeader, pbFilePtr, pbFileEnd);
            pbFilePtr += DlHeader.EntryLength * DlHeader.EntryCount;

            // Dump all tags
            DumpDownloadTags(fp, DlHeader, pbFilePtr, pbFileEnd);
        }
    }
    else
    {
        fprintf(fp, "(empty)\n");
    }

    // Dump tail
    fprintf(fp, "=============================================================================\n\n");
}
*/
//-----------------------------------------------------------------------------
// Public dumping functions

void CascDumpFile(const char * szDumpFile, HANDLE hFile)
{
    FILE * fp;
    DWORD dwBytesRead = 1;
    DWORD dwFilePos = CascSetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    BYTE Buffer[0x1000];

    // Create/open the dump file
    fp = OpenDumpFile(szDumpFile);
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

        // Restore the file pointer
        CascSetFilePointer(hFile, dwFilePos, NULL, FILE_BEGIN);

        // Close the dump file
        CloseDumpFile(szDumpFile, fp);
    }
}

void CascDumpStorage(HANDLE hStorage, const char * szDumpFile)
{
    TCascStorage * hs;
    FILE * fp = stdout;
    char szStringBuff[0x800];

    // Verify the storage handle
    hs = TCascStorage::IsValid(hStorage);
    if(hs == NULL)
        return;

    // Create/open the dump file
    fp = OpenDumpFile(szDumpFile);
    if(fp != NULL)
    {
        // Dump the basic storage info
        fprintf(fp, "=== Basic Storage Info ======================================================\n");
        fprintf(fp, "DataPath:  %s\n", StringFromLPTSTR(hs->szDataPath, szStringBuff, sizeof(szStringBuff)));
        fprintf(fp, "IndexPath: %s\n", StringFromLPTSTR(hs->szIndexPath, szStringBuff, sizeof(szStringBuff)));
        fprintf(fp, "BuildFile: %s\n", StringFromLPTSTR(hs->szBuildFile, szStringBuff, sizeof(szStringBuff)));
        fprintf(fp, "CDN Server: %s\n", StringFromLPTSTR(hs->szCdnServers, szStringBuff, sizeof(szStringBuff)));
        fprintf(fp, "CDN Path: %s\n", StringFromLPTSTR(hs->szCdnPath, szStringBuff, sizeof(szStringBuff)));
        DumpKey(fp, "CDN Config Key: %s\n", hs->CdnConfigKey.pbData, hs->CdnConfigKey.cbData);
        DumpKey(fp, "CDN Build Key:  %s\n", hs->CdnBuildKey.pbData, hs->CdnBuildKey.cbData);
        DumpKey(fp, "Archives Key:   %s\n", hs->ArchivesKey.pbData, hs->ArchivesKey.cbData);
        DumpKey(fp, "ROOT file:      %s\n", hs->RootFile.CKey, CASC_CKEY_SIZE);
        DumpKey(fp, "PATCH file:     %s\n", hs->PatchFile.CKey, CASC_CKEY_SIZE);
        DumpKey(fp, "ENCODING file:  %s\n", hs->EncodingCKey.CKey, CASC_CKEY_SIZE);
        DumpKey(fp, "DOWNLOAD file:  %s\n", hs->DownloadCKey.CKey, CASC_CKEY_SIZE);
        DumpKey(fp, "INSTALL file:   %s\n", hs->InstallCKey.CKey, CASC_CKEY_SIZE);
        fprintf(fp, "\n");

        // Dump the complete ENCODING manifest
//      DumpEncodingManifest(hs, fp);

        // Dump the complete ENCODING manifest
//      DumpDownloadManifest(hs, fp);

        // Close the dump file
        CloseDumpFile(szDumpFile, fp);
    }
}

#endif // _DEBUG
