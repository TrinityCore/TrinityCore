/*****************************************************************************/
/* CascIndexFiles.cpp                     Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* Index file support                                                        */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 23.05.19  1.00  Lad  Created                                              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local variables

static LPCTSTR szAllowedHexChars = _T("0123456789aAbBcCdDeEfF");
static LPCTSTR szIndexFormat_V1 = _T("data.i%x%x");
static LPCTSTR szIndexFormat_V2 = _T("%02x%08x.idx");

// Limit for "orphaned" items - those that are in index files, but are not in ENCODING manifest
#define CASC_MAX_ORPHANED_ITEMS 0x100

typedef bool (*EKEY_ENTRY_CALLBACK)(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, LPBYTE pbEKeyEntry);

//-----------------------------------------------------------------------------
// Local functions

// "data.iXY"
static bool IsIndexFileName_V1(LPCTSTR szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 8 &&
            _tcsnicmp(szFileName, _T("data.i"), 6) == 0 &&
            _tcsspn(szFileName + 6, szAllowedHexChars) == 2);
}

static bool IsIndexFileName_V2(LPCTSTR szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 14 &&
            _tcsspn(szFileName, _T("0123456789aAbBcCdDeEfF")) == 0x0A &&
            _tcsicmp(szFileName + 0x0A, _T(".idx")) == 0);
}

static bool IndexDirectory_OnFileFound(
    LPCTSTR szFileName,
    void * pvContext)
{
    TCascStorage * hs = (TCascStorage *)pvContext;
    PCASC_INDEX pIndexFile;
    DWORD IndexVersion = 0;
    DWORD IndexValue = 0;

    // Auto-detect the format of the index file name
    if(hs->szIndexFormat == NULL)
    {
        if(IsIndexFileName_V2(szFileName))
            hs->szIndexFormat = szIndexFormat_V2;
        else if(IsIndexFileName_V1(szFileName))
            hs->szIndexFormat = szIndexFormat_V1;
        else
            return false;
    }

    if(hs->szIndexFormat == szIndexFormat_V2)
    {
        // Check the index file name format
        if(!IsIndexFileName_V2(szFileName))
            return false;

        // Get the main index from the first two digits
        if(ConvertStringToInt(szFileName + 0, 2, IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertStringToInt(szFileName + 2, 8, IndexVersion) != ERROR_SUCCESS)
            return false;
    }
    else if(hs->szIndexFormat == szIndexFormat_V1)
    {
        // Check the index file name format
        if(!IsIndexFileName_V1(szFileName))
            return false;

        // Get the main index from the first two digits
        if(ConvertStringToInt(szFileName + 6, 1, IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertStringToInt(szFileName + 7, 1, IndexVersion) != ERROR_SUCCESS)
            return false;
    }
    else
    {
        // Should never happen
        assert(false);
        return false;
    }

    // The index value must not be greater than 0x0F
    if(IndexValue >= CASC_INDEX_COUNT)
        return false;
    pIndexFile = &hs->IndexFiles[IndexValue];

    // If the new subindex is greater than the previous one, use this one instead
    if(IndexVersion > pIndexFile->NewSubIndex)
    {
        pIndexFile->OldSubIndex = pIndexFile->NewSubIndex;
        pIndexFile->NewSubIndex = IndexVersion;
    }
    else if(IndexVersion > pIndexFile->OldSubIndex)
    {
        pIndexFile->OldSubIndex = IndexVersion;
    }

    // Note: WoW6 only keeps last two index files
    // Any additional index files are deleted at this point
    return true;
}

static LPTSTR CreateIndexFileName(TCascStorage * hs, DWORD IndexValue, DWORD IndexVersion)
{
    TCHAR szFullName[MAX_PATH];
    TCHAR szPlainName[0x40];

    // Sanity checks
    assert(hs->szIndexFormat != NULL);
    assert(hs->szIndexPath != NULL);
    assert(IndexValue <= 0x0F);

    // Create the full path
    CascStrPrintf(szPlainName, _countof(szPlainName), hs->szIndexFormat, IndexValue, IndexVersion);
    CombinePath(szFullName, _countof(szFullName), hs->szIndexPath, szPlainName, NULL);

    // Return allocated path
    return CascNewStr(szFullName);
}

static void SaveFileOffsetBitsAndEKeyLength(TCascStorage * hs, BYTE FileOffsetBits, BYTE EKeyLength)
{
    if(hs->FileOffsetBits == 0)
        hs->FileOffsetBits = FileOffsetBits;
    assert(hs->FileOffsetBits == FileOffsetBits);

    if(hs->EKeyLength == 0)
        hs->EKeyLength = EKeyLength;
    assert(hs->EKeyLength == EKeyLength);
}

// Verifies a guarded block - data availability and checksum match
static LPBYTE CaptureGuardedBlock1(LPBYTE pbFileData, LPBYTE pbFileEnd)
{
    PFILE_INDEX_GUARDED_BLOCK pBlock = (PFILE_INDEX_GUARDED_BLOCK)pbFileData;

    // Check the guarded block
    if((pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK)) >= pbFileEnd)
        return NULL;
    if((pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK) + pBlock->BlockSize) > pbFileEnd)
        return NULL;
    
    // Verify the hash
    if(hashlittle(pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK), pBlock->BlockSize, 0) != pBlock->BlockHash)
        return NULL;

    // Give the output
    return (LPBYTE)(pBlock + 1);
}

// Second method of checking a guarded block; hash is calculated entry-by-entry.
// Unfortunately, due to implementation in hashlittle2(), we cannot calculate the hash of a continuous block
static LPBYTE CaptureGuardedBlock2(LPBYTE pbFileData, LPBYTE pbFileEnd, size_t EntryLength, PDWORD PtrBlockSize = NULL)
{
    PFILE_INDEX_GUARDED_BLOCK pBlock = (PFILE_INDEX_GUARDED_BLOCK)pbFileData;
    LPBYTE pbEntryPtr;
    size_t EntryCount;
    unsigned int HashBlizzGet = 0;
    unsigned int HashHigh = 0;
    unsigned int HashLow = 0;

    // Check the guarded block. There must be enough bytes to contain FILE_INDEX_GUARDED_BLOCK
    // and also the block length must not be NULL
    if ((pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK)) >= pbFileEnd)
        return NULL;
    if (pBlock->BlockSize == 0 || (pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK) + pBlock->BlockSize) > pbFileEnd)
        return NULL;

    //
    // Verify the hash from the Blizzard Downloader
    //

    pbEntryPtr = pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK);
    EntryCount = pBlock->BlockSize / EntryLength;
    for (size_t i = 0; i < EntryCount; i++)
    {
        hashlittle2(pbEntryPtr, EntryLength, &HashHigh, &HashLow);
        pbEntryPtr += EntryLength;
    }

    // Verify hash
    if (HashHigh == pBlock->BlockHash)
    {
        // Give the output
        if (PtrBlockSize != NULL)
            PtrBlockSize[0] = pBlock->BlockSize;
        return (LPBYTE)(pBlock + 1);
    }

    //
    // Verify the hash from the Blizzget tool, which calculates the hash differently
    // https://github.com/d07RiV/blizzget/blob/master/src/ngdp.cpp
    // Function void DataStorage::writeIndex()
    //

    pbEntryPtr = pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK);
    EntryCount = pBlock->BlockSize / EntryLength;
    for (size_t i = 0; i < EntryCount; i++)
    {
        HashBlizzGet = hashlittle(pbEntryPtr, EntryLength, HashBlizzGet);
        pbEntryPtr += EntryLength;
    }

    // Verify hash
    if (HashBlizzGet == pBlock->BlockHash)
    {
        // Give the output
        if (PtrBlockSize != NULL)
            PtrBlockSize[0] = pBlock->BlockSize;
        return (LPBYTE)(pBlock + 1);
    }

    // Hash mismatch
    return NULL;
}

// Third method of checking a guarded block; There is 32-bit hash, followed by EKey entry
// The hash covers the EKey entry plus one byte
static LPBYTE CaptureGuardedBlock3(LPBYTE pbFileData, LPBYTE pbFileEnd, size_t EntryLength)
{
    PDWORD PtrEntryHash = (PDWORD)pbFileData;
    DWORD EntryHash;

    // Check the guarded block. There must be enough bytes to contain single entry and the hash
    // Also, the hash must be present
    if ((pbFileData + sizeof(DWORD) + EntryLength) >= pbFileEnd)
        return NULL;
    if (PtrEntryHash[0] == 0)
        return NULL;

    EntryHash = hashlittle(pbFileData + sizeof(DWORD), EntryLength+1, 0) | 0x80000000;
    if(EntryHash != PtrEntryHash[0])
        return NULL;

    // Give the output
    return (LPBYTE)(PtrEntryHash + 1);
}
/*
static bool CaptureIndexEntry(CASC_INDEX_HEADER & InHeader, PCASC_EKEY_ENTRY pEKeyEntry, LPBYTE pbEKeyEntry)
{
    // Copy the EKey of the variable length
    pbEKeyEntry = CaptureEncodedKey(pEKeyEntry->EKey, pbEKeyEntry, InHeader.EKeyLength);

    // Copy the storage offset and encoded size
    pEKeyEntry->StorageOffset = ConvertBytesToInteger_5(pbEKeyEntry);
    pEKeyEntry->EncodedSize = ConvertBytesToInteger_4_LE(pbEKeyEntry + InHeader.StorageOffsetLength);
    pEKeyEntry->Alignment = 0;

    // We ignore items that have EncodedSize of 0x1E
    return (pEKeyEntry->EncodedSize > FIELD_OFFSET(BLTE_ENCODED_HEADER, Signature));
}

static void InsertCKeyEntry(TCascStorage * hs, CASC_EKEY_ENTRY & EKeyEntry, DWORD Flags)
{
    PCASC_CKEY_ENTRY pCKeyEntry;

    // Multiple items with the same EKey in the index files may exist.
    // Example: "2018 - New CASC\00001", EKey 37 89 16 5b 2d cc 71 c1 25 00 00 00 00 00 00 00
    // Positions: 0x1D, 0x1E, 0x1F
    // In that case, we only take the first one into account
    // BREAK_ON_XKEY3(EKeyEntry.EKey, 0x09, 0xF3, 0xCD);

    // If the item is not there yet, insert a new one
    if((pCKeyEntry = FindCKeyEntry_EKey(hs, EKeyEntry.EKey)) == NULL)
    {
        // Insert a new entry to the array. DO NOT ALLOW enlarge array here
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1, false);
        if(pCKeyEntry == NULL)
            return;

        // Fill-in the information
        ZeroMemory16(pCKeyEntry->CKey);
        CopyMemory16(pCKeyEntry->EKey, EKeyEntry.EKey);
        pCKeyEntry->StorageOffset = EKeyEntry.StorageOffset;
        pCKeyEntry->TagBitMask = 0;
        pCKeyEntry->ContentSize = CASC_INVALID_SIZE;
        pCKeyEntry->EncodedSize = EKeyEntry.EncodedSize;
        pCKeyEntry->Flags = CASC_CE_HAS_EKEY | CASC_CE_HAS_EKEY_PARTIAL;
        pCKeyEntry->RefCount = 0;
        pCKeyEntry->SpanCount = 1;
        pCKeyEntry->Priority = 0;

        // Insert the item to the EKey table
        hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
    }
    else
    {
        // The entry already exists. True e.g. for ENCODING.
        // Only copy the storage offset and sizes if not available yet
        if(pCKeyEntry->StorageOffset == CASC_INVALID_OFFS64)
        {
            pCKeyEntry->StorageOffset = EKeyEntry.StorageOffset;
            pCKeyEntry->EncodedSize = EKeyEntry.EncodedSize;
        }
    }

    // Add the extra flag
    pCKeyEntry->Flags |= Flags;
}
*/
static DWORD LoadIndexItems(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, EKEY_ENTRY_CALLBACK PfnEKeyEntry, LPBYTE pbEKeyEntry, LPBYTE pbEKeyEnd)
{
    size_t EntryLength = InHeader.EntryLength;

    while((pbEKeyEntry + EntryLength) <= pbEKeyEnd)
    {
        // ENCODING for Starcraft II Beta
        BREAK_ON_XKEY3(pbEKeyEntry, 0x8b, 0x0d, 0x9a);

        if(!PfnEKeyEntry(hs, InHeader, pbEKeyEntry))
            return ERROR_INDEX_PARSING_DONE;

        pbEKeyEntry += EntryLength;
    }

    return ERROR_SUCCESS;
}

static DWORD CaptureIndexHeader_V1(CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, size_t cbFileData, DWORD BucketIndex)
{
    PFILE_INDEX_HEADER_V1 pIndexHeader = (PFILE_INDEX_HEADER_V1)pbFileData;
    LPBYTE pbKeyEntries;
    LPBYTE pbFileEnd = pbFileData + cbFileData;
    size_t cbKeyEntries;
    DWORD HeaderHash;

    // Check the available size. Note that the index file can be just a header.
    if((pbFileData + sizeof(FILE_INDEX_HEADER_V1)) > pbFileEnd)
        return ERROR_BAD_FORMAT;
    if(pIndexHeader->IndexVersion != 0x05 || pIndexHeader->BucketIndex != (BYTE)BucketIndex || pIndexHeader->field_8 == 0)
        return ERROR_BAD_FORMAT;
    if(pIndexHeader->EncodedSizeLength != 0x04 || pIndexHeader->StorageOffsetLength != 0x05 || pIndexHeader->EKeyLength != 0x09)
        return ERROR_NOT_SUPPORTED;

    // Verify the header hash
    HeaderHash = pIndexHeader->HeaderHash;
    pIndexHeader->HeaderHash = 0;
    if(hashlittle(pbFileData, sizeof(FILE_INDEX_HEADER_V1), 0) != HeaderHash)
        return ERROR_BAD_FORMAT;

    // Return the header hash back
    pIndexHeader->HeaderHash = HeaderHash;

    // Copy the fields
    InHeader.IndexVersion        = pIndexHeader->IndexVersion;
    InHeader.BucketIndex         = pIndexHeader->BucketIndex;
    InHeader.StorageOffsetLength = pIndexHeader->StorageOffsetLength;
    InHeader.EncodedSizeLength   = pIndexHeader->EncodedSizeLength;
    InHeader.EKeyLength          = pIndexHeader->EKeyLength;
    InHeader.FileOffsetBits      = pIndexHeader->FileOffsetBits;
    InHeader.Alignment           = 0;
    InHeader.SegmentSize         = pIndexHeader->SegmentSize;

    // Determine the size of the header
    InHeader.HeaderLength = sizeof(FILE_INDEX_HEADER_V1);
    InHeader.HeaderPadding = 0;
    InHeader.EntryLength = pIndexHeader->EKeyLength + pIndexHeader->StorageOffsetLength + pIndexHeader->EncodedSizeLength;
    InHeader.EKeyCount = pIndexHeader->EKeyCount1 + pIndexHeader->EKeyCount2;

    // Verify the entries hash - 1st block
    pbKeyEntries = pbFileData + InHeader.HeaderLength;
    cbKeyEntries = pIndexHeader->EKeyCount1 * InHeader.EntryLength;
    if((pbKeyEntries + cbKeyEntries) > pbFileEnd)
        return ERROR_FILE_CORRUPT;
    if(hashlittle(pbKeyEntries, cbKeyEntries, 0) != pIndexHeader->KeysHash1)
        return ERROR_FILE_CORRUPT;

    // Verify the entries hash - 2nd block
    pbKeyEntries = pbKeyEntries + cbKeyEntries;
    cbKeyEntries = pIndexHeader->EKeyCount2 * InHeader.EntryLength;
    if((pbKeyEntries + cbKeyEntries) > pbFileEnd)
        return ERROR_FILE_CORRUPT;
    if(hashlittle(pbKeyEntries, cbKeyEntries, 0) != pIndexHeader->KeysHash2)
        return ERROR_FILE_CORRUPT;

    return ERROR_SUCCESS;
}

static DWORD CaptureIndexHeader_V2(CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, size_t cbFileData, DWORD BucketIndex)
{
    PFILE_INDEX_HEADER_V2 pIndexHeader;
    LPBYTE pbFileEnd = pbFileData + cbFileData;

    // Check for guarded block
    if((pbFileData = CaptureGuardedBlock1(pbFileData, pbFileEnd)) == NULL)
        return ERROR_FILE_CORRUPT;
    pIndexHeader = (PFILE_INDEX_HEADER_V2)pbFileData;

    // Verify the content of the index header
    if(pIndexHeader->IndexVersion != 0x07 || pIndexHeader->BucketIndex != (BYTE)BucketIndex || pIndexHeader->ExtraBytes != 0x00)
        return ERROR_BAD_FORMAT;
    if(pIndexHeader->EncodedSizeLength != 0x04 || pIndexHeader->StorageOffsetLength != 0x05 || pIndexHeader->EKeyLength != 0x09)
        return ERROR_BAD_FORMAT;

    // Capture the values from the index header
    InHeader.IndexVersion        = pIndexHeader->IndexVersion;
    InHeader.BucketIndex         = pIndexHeader->BucketIndex;
    InHeader.StorageOffsetLength = pIndexHeader->StorageOffsetLength;
    InHeader.EncodedSizeLength   = pIndexHeader->EncodedSizeLength;
    InHeader.EKeyLength          = pIndexHeader->EKeyLength;
    InHeader.FileOffsetBits      = pIndexHeader->FileOffsetBits;
    InHeader.Alignment           = 0;
    InHeader.SegmentSize         = pIndexHeader->SegmentSize;

    // Supply the lengths
    InHeader.HeaderLength = sizeof(FILE_INDEX_GUARDED_BLOCK) + sizeof(FILE_INDEX_HEADER_V2);
    InHeader.HeaderPadding = 8;
    InHeader.EntryLength = pIndexHeader->EKeyLength + pIndexHeader->StorageOffsetLength + pIndexHeader->EncodedSizeLength;
    InHeader.EKeyCount = 0;
    return ERROR_SUCCESS;
}    

static DWORD LoadIndexFile_V1(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, EKEY_ENTRY_CALLBACK PfnEKeyEntry, LPBYTE pbFileData, size_t cbFileData)
{
    LPBYTE pbEKeyEntries = pbFileData + InHeader.HeaderLength + InHeader.HeaderPadding;

    // Remember the values from the index header
    SaveFileOffsetBitsAndEKeyLength(hs, InHeader.FileOffsetBits, InHeader.EKeyLength);

    // Load the entries from a continuous array
    return LoadIndexItems(hs, InHeader, PfnEKeyEntry, pbEKeyEntries, pbFileData + cbFileData);
}

static DWORD LoadIndexFile_V2(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, EKEY_ENTRY_CALLBACK PfnEKeyEntry, LPBYTE pbFileData, size_t cbFileData)
{
    LPBYTE pbEKeyEntry;
    LPBYTE pbFileEnd = pbFileData + cbFileData;
    LPBYTE pbFilePtr = pbFileData + InHeader.HeaderLength + InHeader.HeaderPadding;
    size_t EKeyEntriesLength;
    DWORD BlockSize = 0;
    DWORD dwErrCode = ERROR_NOT_SUPPORTED;

    // Remember the values from the index header
    SaveFileOffsetBitsAndEKeyLength(hs, InHeader.FileOffsetBits, InHeader.EKeyLength);

    // Get the pointer to the first block of EKey entries
    if((pbEKeyEntry = CaptureGuardedBlock2(pbFilePtr, pbFileEnd, InHeader.EntryLength, &BlockSize)) != NULL)
    {
        // Supply the number of EKey entries
        InHeader.HeaderPadding += sizeof(FILE_INDEX_GUARDED_BLOCK);

        // Load the continuous array of EKeys
        return LoadIndexItems(hs, InHeader, PfnEKeyEntry, pbEKeyEntry, pbEKeyEntry + BlockSize);
    }

    // Get the pointer to the second block of EKey entries.
    // They are alway at the position aligned to 4096
    EKeyEntriesLength = pbFileEnd - pbFilePtr;
    if(EKeyEntriesLength >= 0x7800)
    {
        LPBYTE pbStartPage = pbFileData + 0x1000;
        LPBYTE pbEndPage = pbStartPage + FILE_INDEX_PAGE_SIZE;
        size_t AlignedLength = ALIGN_TO_SIZE(InHeader.EntryLength, 4);

        // Parse the chunks with the EKey entries
        while(pbStartPage < pbFileEnd)
        {
            pbEKeyEntry = pbStartPage;
            
            while(pbEKeyEntry < pbEndPage)
            {
                // Check the EKey entry protected by 32-bit hash
                if((pbEKeyEntry = CaptureGuardedBlock3(pbEKeyEntry, pbEndPage, InHeader.EntryLength)) == NULL)
                    break;

                // CASC\\0001: Encoding
                //BREAK_ON_XKEY3(pbEKeyEntry, 0xbc, 0xe8, 0x23);

                // Call the EKey entry callback
                if(!PfnEKeyEntry(hs, InHeader, pbEKeyEntry))
                    return ERROR_INDEX_PARSING_DONE;

                pbEKeyEntry += AlignedLength;
            }

            // Move to the next chunk
            pbStartPage += FILE_INDEX_PAGE_SIZE;
        }
        dwErrCode = ERROR_SUCCESS;
    }

    return dwErrCode;
}

static DWORD LoadIndexFile(TCascStorage * hs, EKEY_ENTRY_CALLBACK PfnEKeyEntry, LPBYTE pbFileData, size_t cbFileData, DWORD BucketIndex)
{
    CASC_INDEX_HEADER InHeader;

    // Check for CASC version 2
    if(CaptureIndexHeader_V2(InHeader, pbFileData, cbFileData, BucketIndex) == ERROR_SUCCESS)
        return LoadIndexFile_V2(hs, InHeader, PfnEKeyEntry, pbFileData, cbFileData);

    // Check for CASC index version 1
    if(CaptureIndexHeader_V1(InHeader, pbFileData, cbFileData, BucketIndex) == ERROR_SUCCESS)
        return LoadIndexFile_V1(hs, InHeader, PfnEKeyEntry, pbFileData, cbFileData);

    // Should never happen
    assert(false);
    return ERROR_BAD_FORMAT;
}

// Checks the EKey entry for EKey of the ENCODING manifest
static bool InsertEncodingEKeyToMap(TCascStorage * hs, CASC_INDEX_HEADER &, LPBYTE pbEKeyEntry)
{
    hs->IndexEKeyMap.InsertObject(pbEKeyEntry, pbEKeyEntry);
    return true;
}

static DWORD ProcessLocalIndexFiles(TCascStorage * hs, EKEY_ENTRY_CALLBACK PfnEKeyEntry, DWORD dwIndexCount)
{
    DWORD dwErrCode = ERROR_SUCCESS;

    // Load each index file
    for(DWORD i = 0; i < dwIndexCount; i++)
    {
        CASC_INDEX & IndexFile = hs->IndexFiles[i];

        // Inform the user about what we are doing
        if(InvokeProgressCallback(hs, "Loading index files", NULL, i, dwIndexCount))
        {
            dwErrCode = ERROR_CANCELLED;
            break;
        }

        // Load the index file
        if((dwErrCode = LoadIndexFile(hs, PfnEKeyEntry, IndexFile.pbFileData, IndexFile.cbFileData, i)) != ERROR_SUCCESS)
            break;
    }

    // Swallow the "done parsing" error
    if(dwErrCode == ERROR_INDEX_PARSING_DONE)
        dwErrCode = ERROR_SUCCESS;

    // Remember the number of files that are present locally
    hs->LocalFiles = hs->CKeyArray.ItemCount();
    return dwErrCode;
}

static DWORD LoadLocalIndexFiles(TCascStorage * hs)
{
    ULONGLONG TotalSize = 0;
    DWORD dwIndexCount = 0;
    DWORD dwErrCode;

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading index files", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Perform the directory scan
    if((dwErrCode = ScanIndexDirectory(hs->szIndexPath, IndexDirectory_OnFileFound, hs)) == ERROR_SUCCESS)
    {
        // If no index file was found, we cannot load anything
        if(hs->szIndexFormat == NULL)
            return ERROR_FILE_NOT_FOUND;

        // Load each index file
        for(DWORD i = 0; i < CASC_INDEX_COUNT; i++)
        {
            CASC_INDEX & IndexFile = hs->IndexFiles[i];
            DWORD cbFileData = 0;

            // Create the file name
            if((IndexFile.szFileName = CreateIndexFileName(hs, i, IndexFile.NewSubIndex)) == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;

            // WoW6 actually reads THE ENTIRE file to memory. Verified on Mac build (x64).
            if((IndexFile.pbFileData = LoadFileToMemory(IndexFile.szFileName, &cbFileData)) == NULL)
            {
                // Storages downloaded by Blizzget tool don't have all index files present
                if((dwErrCode = GetCascError()) == ERROR_FILE_NOT_FOUND)
                {
                    dwErrCode = ERROR_SUCCESS;
                    break;
                }

                return dwErrCode;
            }

            // Add to the total size of the index files
            IndexFile.cbFileData = cbFileData;
            TotalSize += cbFileData;
            dwIndexCount++;
        }

        // Build the map of EKey -> IndexEKeyEntry
        dwErrCode = hs->IndexEKeyMap.Create((size_t)(TotalSize / sizeof(FILE_EKEY_ENTRY)), CASC_EKEY_SIZE, 0);
        if(dwErrCode == ERROR_SUCCESS)
        {
            dwErrCode = ProcessLocalIndexFiles(hs, InsertEncodingEKeyToMap, dwIndexCount);
        }
    }

    return dwErrCode;
}

//-----------------------------------------------------------------------------
// Online index files
// https://wowdev.wiki/TACT#CDN_File_Organization

static DWORD CaptureArcIndexFooter(CASC_ARCINDEX_FOOTER & InFooter, LPBYTE pbIndexFile, DWORD cbIndexFile)
{
    FILE_INDEX_FOOTER<0x08> * pFooter08;
    BYTE checksum_data[0x40] = { 0 };
    BYTE md5_hash[MD5_HASH_SIZE];
    DWORD checksum_data_length;

    // Clear the entire structure
    memset(&InFooter, 0, sizeof(CASC_ARCINDEX_FOOTER));

    // Check the variant for checksum == 0x08
    pFooter08 = (FILE_INDEX_FOOTER<0x08> *)(pbIndexFile + cbIndexFile - sizeof(FILE_INDEX_FOOTER<0x08>));
    if (pFooter08->Version == 1 && pFooter08->Reserved[0] == 0 && pFooter08->Reserved[1] == 0 && pFooter08->FooterHashBytes == 8)
    {
        // Copy the entire structure
        memcpy(InFooter.TocHash, pFooter08->TocHash, MD5_HASH_SIZE);
        memcpy(InFooter.FooterHash, pFooter08->FooterHash, pFooter08->FooterHashBytes);
        InFooter.Version = pFooter08->Version;
        InFooter.OffsetBytes = pFooter08->OffsetBytes;
        InFooter.SizeBytes = pFooter08->SizeBytes;
        InFooter.EKeyLength = pFooter08->EKeyLength;
        InFooter.FooterHashBytes = pFooter08->FooterHashBytes;
        InFooter.PageLength = pFooter08->PageSizeKB << 10;
        InFooter.ItemLength = pFooter08->EKeyLength + pFooter08->OffsetBytes + pFooter08->SizeBytes;
        InFooter.FooterLength = sizeof(FILE_INDEX_FOOTER<0x08>);
        InFooter.ElementCount = ConvertBytesToInteger_4_LE(pFooter08->ElementCount);

        // Verify the hash. FooterHash needs to be cleared in order to calculate footer hash properly
        checksum_data_length = FIELD_OFFSET(FILE_INDEX_FOOTER<0x08>, FooterHash) - FIELD_OFFSET(FILE_INDEX_FOOTER<0x08>, Version);
        memcpy(checksum_data, &pFooter08->Version, checksum_data_length);
        CascCalculateDataBlockHash(checksum_data, sizeof(FILE_INDEX_FOOTER<0x08>) - MD5_HASH_SIZE, md5_hash);
        if(!memcmp(md5_hash, InFooter.FooterHash, InFooter.FooterHashBytes))
            return ERROR_SUCCESS;
    }

    assert(false);
    return ERROR_BAD_FORMAT;
}

static DWORD CaptureIndexEntry(CASC_ARCINDEX_FOOTER  & InFooter, CASC_EKEY_ENTRY & EKeyEntry, LPBYTE pbIndexPage, LPBYTE pbIndexPageEnd, size_t nArchive)
{
    ULONGLONG StorageOffset = nArchive;
    ULONGLONG ArchiveOffset;

    // If there enough bytes for one entry/
    if ((pbIndexPage + InFooter.ItemLength) > pbIndexPageEnd)
        return ERROR_BAD_FORMAT;

    // Capture the EKey (variable length)
    pbIndexPage = CaptureEncodedKey(EKeyEntry.EKey, pbIndexPage, InFooter.EKeyLength);

    // Copy the archive offset
    ArchiveOffset = ConvertBytesToInteger_X(pbIndexPage + InFooter.SizeBytes, InFooter.OffsetBytes);
    if (ArchiveOffset >= 0x10000000)
        return ERROR_BAD_FORMAT;

    // Capture the storage offset and encoded size
    EKeyEntry.StorageOffset = (StorageOffset << (InFooter.OffsetBytes * 8)) | ArchiveOffset;
    EKeyEntry.EncodedSize = ConvertBytesToInteger_X(pbIndexPage, InFooter.SizeBytes);
    EKeyEntry.Alignment = 0;

    // Is there a valid hash?
    return CascIsValidMD5(EKeyEntry.EKey) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static DWORD VerifyIndexSize(CASC_ARCINDEX_FOOTER  & InFooter, LPBYTE pbIndexFile, size_t cbIndexFile, LPBYTE * PtrIndexEnd)
{
    size_t nPageCount;

    // Set the new length (without the footer)
    cbIndexFile = cbIndexFile - InFooter.FooterLength;
    nPageCount = cbIndexFile / (InFooter.PageLength + MD5_HASH_SIZE);

    // There must be equal or more pages
    if(((InFooter.PageLength + MD5_HASH_SIZE) * nPageCount) > cbIndexFile)
        return ERROR_BAD_FORMAT;

    // Return the end-of-index
    nPageCount = cbIndexFile / (InFooter.PageLength + MD5_HASH_SIZE);
    PtrIndexEnd[0] = pbIndexFile + (nPageCount * InFooter.PageLength);
    return ERROR_SUCCESS;
}

static DWORD LoadArchiveIndexPage(TCascStorage * hs, CASC_ARCINDEX_FOOTER & InFooter, LPBYTE pbIndexPage, LPBYTE pbIndexPageEnd, size_t nArchive)
{
    CASC_EKEY_ENTRY EKeyEntry;
    DWORD dwErrCode;

    while (pbIndexPage <= pbIndexPageEnd)
    {
        // Capture the index entry
        dwErrCode = CaptureIndexEntry(InFooter, EKeyEntry, pbIndexPage, pbIndexPageEnd, nArchive);
        if (dwErrCode != ERROR_SUCCESS)
            break;

        // Insert a new entry to the index array
        if((hs->IndexArray.Insert(&EKeyEntry, 1)) == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Move to the next entry
        pbIndexPage += InFooter.ItemLength;
    }

    return ERROR_SUCCESS;
}

static DWORD LoadArchiveIndexFile(TCascStorage * hs, LPBYTE pbIndexFile, DWORD cbIndexFile, size_t nArchive)
{
    CASC_ARCINDEX_FOOTER InFooter;
    LPBYTE pbIndexEnd = NULL;
    DWORD dwErrCode;

    // Validate and capture the footer
    dwErrCode = CaptureArcIndexFooter(InFooter, pbIndexFile, cbIndexFile);
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Remember the file offset and EKey length
    SaveFileOffsetBitsAndEKeyLength(hs, InFooter.OffsetBytes * 8, InFooter.EKeyLength);

    // Verify the size of the index file
    dwErrCode = VerifyIndexSize(InFooter, pbIndexFile, cbIndexFile, &pbIndexEnd);
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Parse all pages
    while (pbIndexFile < pbIndexEnd)
    {
        // Load the entire page
        dwErrCode = LoadArchiveIndexPage(hs, InFooter, pbIndexFile, pbIndexFile + InFooter.PageLength, nArchive);
        if (dwErrCode != ERROR_SUCCESS)
            break;

        // Move to the next page
        pbIndexFile += InFooter.PageLength;
    }

    return ERROR_SUCCESS;
}

static DWORD BuildMapOfArchiveIndices(TCascStorage * hs)
{
    PCASC_EKEY_ENTRY pEKeyEntry;
    size_t nItemCount = hs->IndexArray.ItemCount();
    DWORD dwErrCode;

    // Create the map
    dwErrCode = hs->IndexMap.Create(nItemCount, MD5_HASH_SIZE, FIELD_OFFSET(CASC_EKEY_ENTRY, EKey));
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Insert all items
    for(size_t i = 0; i < nItemCount; i++)
    {
        pEKeyEntry = (PCASC_EKEY_ENTRY)hs->IndexArray.ItemAt(i);
        if (pEKeyEntry != NULL)
        {
            if (!hs->IndexMap.InsertObject(pEKeyEntry, pEKeyEntry->EKey))
            {
                return ERROR_NOT_ENOUGH_MEMORY;
            }
        }
    }

    return dwErrCode;
}

static DWORD LoadArchiveIndexFiles(TCascStorage * hs)
{
    LPBYTE pbFileData;
    TCHAR szLocalPath[MAX_PATH];
    DWORD cbFileData = 0;
    size_t nArchiveCount = (hs->ArchivesKey.cbData / MD5_HASH_SIZE);
    DWORD dwErrCode = ERROR_SUCCESS;

    // Create the array object for the indices
    dwErrCode = hs->IndexArray.Create(sizeof(CASC_EKEY_ENTRY), 0x10000);
    if (dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Load all the indices
    for (size_t i = 0; i < nArchiveCount; i++)
    {
        CASC_CDN_DOWNLOAD CdnsInfo = {0};
        LPBYTE pbIndexHash = hs->ArchivesKey.pbData + (i * MD5_HASH_SIZE);

        // Inform the user about what we are doing
        if(InvokeProgressCallback(hs, "Downloading archive indexes", NULL, (DWORD)(i), (DWORD)(nArchiveCount)))
        {
            dwErrCode = ERROR_CANCELLED;
            break;
        }

        // Prepare the download structure for "%CDNS_HOST%/%CDNS_PATH%/##/##/EKey" file
        CdnsInfo.szCdnsPath = hs->szCdnPath;
        CdnsInfo.szPathType = _T("data");
        CdnsInfo.pbEKey = pbIndexHash;
        CdnsInfo.szExtension = _T(".index");
        CdnsInfo.szLocalPath = szLocalPath;
        CdnsInfo.ccLocalPath = _countof(szLocalPath);
        dwErrCode = DownloadFileFromCDN(hs, CdnsInfo);

        // Load and parse the archive index
        if (dwErrCode == ERROR_SUCCESS)
        {
            // Load the index file to memory
            pbFileData = LoadFileToMemory(szLocalPath, &cbFileData);
            if (pbFileData && cbFileData)
            {
                dwErrCode = LoadArchiveIndexFile(hs, pbFileData, cbFileData, i);
                CASC_FREE(pbFileData);
            }
        }

        // Break if an error
        if (dwErrCode != ERROR_SUCCESS)
            break;
    }

    // Build map of EKey -> CASC_EKEY_ENTRY
    if (dwErrCode == ERROR_SUCCESS)
        dwErrCode = BuildMapOfArchiveIndices(hs);
    return dwErrCode;
}

//-----------------------------------------------------------------------------
// Public functions

bool CopyEKeyEntry(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry)
{
    LPBYTE pbEKeyEntry = (LPBYTE)hs->IndexEKeyMap.FindObject(pCKeyEntry->EKey);

    // Don't do this on online storages
    if(!(hs->dwFeatures & CASC_FEATURE_ONLINE))
    {
        // If the file was found, then copy the content to the CKey entry
        pbEKeyEntry = (LPBYTE)hs->IndexEKeyMap.FindObject(pCKeyEntry->EKey);
        if(pbEKeyEntry == NULL)
            return false;

        pCKeyEntry->StorageOffset = ConvertBytesToInteger_5(pbEKeyEntry + hs->EKeyLength);
        pCKeyEntry->EncodedSize = ConvertBytesToInteger_4_LE(pbEKeyEntry + hs->EKeyLength + 5);
        pCKeyEntry->Flags |= CASC_CE_FILE_IS_LOCAL;
    }

    return true;
}

DWORD LoadIndexFiles(TCascStorage * hs)
{
    // For local storages, load the index files from the disk
    // For online storages, load the index files from the cache / internet
    if(hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        return LoadArchiveIndexFiles(hs);
    }
    else
    {
        return LoadLocalIndexFiles(hs);
    }
}

void FreeIndexFiles(TCascStorage * hs)
{
    // Free the map of EKey -> Index Ekey item
    hs->IndexEKeyMap.Free();

    // Free all loaded index files
    for(size_t i = 0; i < CASC_INDEX_COUNT; i++)
    {
        CASC_INDEX & IndexFile = hs->IndexFiles[i];

        // Free the file data
        CASC_FREE(IndexFile.pbFileData);
        IndexFile.cbFileData = 0;

        // Free the file name
        CASC_FREE(IndexFile.szFileName);
    }
}
