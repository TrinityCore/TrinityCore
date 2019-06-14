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

static const TCHAR * szAllowedHexChars = _T("0123456789aAbBcCdDeEfF");
static const TCHAR * szIndexFormat_V1 = _T("data.i%x%x");
static const TCHAR * szIndexFormat_V2 = _T("%02x%08x.idx");

// Limit for "orphaned" items - those that are in index files, but are not in ENCODING manifest
#define CASC_MAX_ORPHANED_ITEMS 0x100

//-----------------------------------------------------------------------------
// Local functions

// "data.iXY"
static bool IsIndexFileName_V1(const TCHAR * szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 8 &&
            _tcsnicmp(szFileName, _T("data.i"), 6) == 0 &&
            _tcsspn(szFileName + 6, szAllowedHexChars) == 2);
}

static bool IsIndexFileName_V2(const TCHAR * szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 14 &&
            _tcsspn(szFileName, _T("0123456789aAbBcCdDeEfF")) == 0x0A &&
            _tcsicmp(szFileName + 0x0A, _T(".idx")) == 0);
}

static bool IndexDirectory_OnFileFound(
    const TCHAR * szFileName,
    PDWORD IndexArray,
    PDWORD OldIndexArray,
    void * pvContext)
{
    TCascStorage * hs = (TCascStorage *)pvContext;
    DWORD IndexValue = 0;
    DWORD IndexVersion = 0;

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
        if(ConvertStringToInt32(szFileName, 2, &IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertStringToInt32(szFileName + 2, 8, &IndexVersion) != ERROR_SUCCESS)
            return false;
    }
    else if(hs->szIndexFormat == szIndexFormat_V1)
    {
        // Check the index file name format
        if(!IsIndexFileName_V1(szFileName))
            return false;

        // Get the main index from the first two digits
        if(ConvertDigitToInt32(szFileName + 6, &IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertDigitToInt32(szFileName + 7, &IndexVersion) != ERROR_SUCCESS)
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

    // If the new subindex is greater than the previous one,
    // use this one instead
    if(IndexVersion > IndexArray[IndexValue])
    {
        OldIndexArray[IndexValue] = IndexArray[IndexValue];
        IndexArray[IndexValue] = IndexVersion;
    }
    else if(IndexVersion > OldIndexArray[IndexValue])
    {
        OldIndexArray[IndexValue] = IndexVersion;
    }

    // Note: WoW6 only keeps last two index files
    // Any additional index files are deleted at this point
    return true;
}

static TCHAR * CreateIndexFileName(TCascStorage * hs, DWORD IndexValue, DWORD IndexVersion)
{
    TCHAR szPlainName[0x40];

    // Sanity checks
    assert(hs->szIndexFormat != NULL);
    assert(hs->szIndexPath != NULL);
    assert(IndexValue <= 0x0F);

    // Create the full path
    CascStrPrintf(szPlainName, _countof(szPlainName), hs->szIndexFormat, IndexValue, IndexVersion);
    return CombinePath(hs->szIndexPath, szPlainName);
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
    unsigned int HashHigh = 0;
    unsigned int HashLow = 0;

    // Check the guarded block. There must be enough bytes to contain FILE_INDEX_GUARDED_BLOCK
    // and also the block length must not be NULL
    if ((pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK)) >= pbFileEnd)
        return NULL;
    if (pBlock->BlockSize == 0 || (pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK) + pBlock->BlockSize) > pbFileEnd)
        return NULL;

    // Compute the hash entry-by-entry
    pbEntryPtr = pbFileData + sizeof(FILE_INDEX_GUARDED_BLOCK);
    EntryCount = pBlock->BlockSize / EntryLength;
    for (size_t i = 0; i < EntryCount; i++)
    {
        hashlittle2(pbEntryPtr, EntryLength, &HashHigh, &HashLow);
        pbEntryPtr += EntryLength;
    }

    // Verify hash
    if (HashHigh != pBlock->BlockHash)
        return NULL;

    // Give the output
    if (PtrBlockSize != NULL)
        PtrBlockSize[0] = pBlock->BlockSize;
    return (LPBYTE)(pBlock + 1);
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

static bool CaptureIndexEntry(CASC_INDEX_HEADER & InHeader, PCASC_CKEY_ENTRY pCKeyEntry, LPBYTE pbEKeyEntry)
{
    // Zero both CKey and EKey
    ZeroMemory16(pCKeyEntry->CKey);
    ZeroMemory16(pCKeyEntry->EKey);

    // Copy the EKey. We assume 9 bytes
    pCKeyEntry->EKey[0x00] = pbEKeyEntry[0];
    pCKeyEntry->EKey[0x01] = pbEKeyEntry[1];
    pCKeyEntry->EKey[0x02] = pbEKeyEntry[2];
    pCKeyEntry->EKey[0x03] = pbEKeyEntry[3];
    pCKeyEntry->EKey[0x04] = pbEKeyEntry[4];
    pCKeyEntry->EKey[0x05] = pbEKeyEntry[5];
    pCKeyEntry->EKey[0x06] = pbEKeyEntry[6];
    pCKeyEntry->EKey[0x07] = pbEKeyEntry[7];
    pCKeyEntry->EKey[0x08] = pbEKeyEntry[8];
    pCKeyEntry->EKey[0x09] = pbEKeyEntry[9];
    pbEKeyEntry += InHeader.EKeyLength;

    // Copy the storage offset
    pCKeyEntry->StorageOffset = ConvertBytesToInteger_5(pbEKeyEntry);
    pbEKeyEntry += InHeader.StorageOffsetLength;

    // Clear the tag bit mask
    pCKeyEntry->TagBitMask = 0;

    // Copy the encoded length
    pCKeyEntry->EncodedSize = ConvertBytesToInteger_4_LE(pbEKeyEntry);
    pCKeyEntry->ContentSize = CASC_INVALID_SIZE;
    pCKeyEntry->RefCount = 0;
    pCKeyEntry->Priority = 0;
    pCKeyEntry->Flags = CASC_CE_FILE_IS_LOCAL | CASC_CE_HAS_EKEY | CASC_CE_HAS_EKEY_PARTIAL;

    // We ignore items that have EncodedSize of 0x1E
    return (pCKeyEntry->EncodedSize > FIELD_OFFSET(BLTE_ENCODED_HEADER, Signature));
}

static void CheckForEncodingManifestCKey(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry)
{
    // If the encoding file was not found yet
    if(hs->EncodingCKey.StorageOffset == CASC_INVALID_OFFS64)
    {
        if(!memcmp(pCKeyEntry->EKey, hs->EncodingCKey.EKey, hs->EKeyLength))
        {
            hs->EncodingCKey.StorageOffset = pCKeyEntry->StorageOffset;
            hs->EncodingCKey.EncodedSize = pCKeyEntry->EncodedSize;
            hs->EncodingCKey.Flags |= CASC_CE_FILE_IS_LOCAL;
        }
    }
}

static int LoadIndexItems(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, LPBYTE pbEKeyEntry, LPBYTE pbEKeyEnd)
{
    size_t EntryLength = InHeader.EntryLength;

    while((pbEKeyEntry + EntryLength) <= pbEKeyEnd)
    {
        CASC_CKEY_ENTRY CKeyEntry;

        // Capture the index entry and verify it.
        if(CaptureIndexEntry(InHeader, &CKeyEntry, pbEKeyEntry))
        {
            // Insert new entry to the array of CKey entries
            if(hs->IndexArray.Insert(&CKeyEntry, 1) == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;

            // Verify whether the key is not a CKEy entry for ENCODING file
            CheckForEncodingManifestCKey(hs, &CKeyEntry);
        }

        pbEKeyEntry += EntryLength;
    }

    return ERROR_SUCCESS;
}

static int CaptureIndexHeader_V1(CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, DWORD cbFileData, DWORD BucketIndex)
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

static int CaptureIndexHeader_V2(CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, DWORD cbFileData, DWORD BucketIndex)
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

static int LoadIndexFile_V1(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, DWORD cbFileData)
{
    LPBYTE pbEKeyEntries = pbFileData + InHeader.HeaderLength + InHeader.HeaderPadding;

    // Remember the values from the index header
    hs->FileOffsetBits = InHeader.FileOffsetBits;
    hs->EKeyLength = InHeader.EKeyLength;

    // Load the entries from a continuous array
    return LoadIndexItems(hs, InHeader, pbEKeyEntries, pbFileData + cbFileData);
}

static int LoadIndexFile_V2(TCascStorage * hs, CASC_INDEX_HEADER & InHeader, LPBYTE pbFileData, DWORD cbFileData)
{
    LPBYTE pbEKeyEntry;
    LPBYTE pbFileEnd = pbFileData + cbFileData;
    LPBYTE pbFilePtr = pbFileData + InHeader.HeaderLength + InHeader.HeaderPadding;
    size_t EKeyEntriesLength;
    DWORD BlockSize = 0;
    int nError = ERROR_NOT_SUPPORTED;

    // Remember the values from the index header
    hs->FileOffsetBits = InHeader.FileOffsetBits;
    hs->EKeyLength = InHeader.EKeyLength;

    // Get the pointer to the first block of EKey entries
    if((pbEKeyEntry = CaptureGuardedBlock2(pbFilePtr, pbFileEnd, InHeader.EntryLength, &BlockSize)) != NULL)
    {
        // Supply the number of EKey entries
        InHeader.HeaderPadding += sizeof(FILE_INDEX_GUARDED_BLOCK);

        // Load the continuous array of EKeys
        return LoadIndexItems(hs, InHeader, pbEKeyEntry, pbEKeyEntry + BlockSize);
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
                CASC_CKEY_ENTRY CKeyEntry;

                // Check the EKey entry protected by 32-bit hash
                if((pbEKeyEntry = CaptureGuardedBlock3(pbEKeyEntry, pbEndPage, InHeader.EntryLength)) == NULL)
                    break;

                // CASC\\0001: Encoding
                //BREAK_ON_XKEY3(pbEKeyEntry, 0xbc, 0xe8, 0x23);

                // Capture the index entry and verify it.
                if(CaptureIndexEntry(InHeader, &CKeyEntry, pbEKeyEntry))
                {
                    // Insert the EKey entry to the array
                    if(hs->IndexArray.Insert(&CKeyEntry, 1) == NULL)
                        return ERROR_NOT_ENOUGH_MEMORY;

                    // Check whether the CKey entry is an encoding entry
                    CheckForEncodingManifestCKey(hs, &CKeyEntry);
                }

                // Move to the next entry
                pbEKeyEntry += AlignedLength;
            }

            // Move to the next chunk
            pbStartPage += FILE_INDEX_PAGE_SIZE;
        }
        nError = ERROR_SUCCESS;
    }

    return nError;
}

static int LoadIndexFile(TCascStorage * hs, LPBYTE pbFileData, DWORD cbFileData, DWORD BucketIndex)
{
    CASC_INDEX_HEADER InHeader;

    // Check for CASC version 2
    if(CaptureIndexHeader_V2(InHeader, pbFileData, cbFileData, BucketIndex) == ERROR_SUCCESS)
        return LoadIndexFile_V2(hs, InHeader, pbFileData, cbFileData);

    // Check for CASC index version 1
    if(CaptureIndexHeader_V1(InHeader, pbFileData, cbFileData, BucketIndex) == ERROR_SUCCESS)
        return LoadIndexFile_V1(hs, InHeader, pbFileData, cbFileData);

    // Should never happen
    assert(false);
    return ERROR_BAD_FORMAT;
}

static int LoadIndexFile(TCascStorage * hs, const TCHAR * szFileName, DWORD BucketIndex)
{
    LPBYTE pbFileData;
    DWORD cbFileData;
    int nError = ERROR_SUCCESS;

    // WoW6 actually reads THE ENTIRE file to memory. Verified on Mac build (x64).
    pbFileData = LoadFileToMemory(szFileName, &cbFileData);
    if(pbFileData && cbFileData)
    {
        // Parse and load the index file
        nError = LoadIndexFile(hs, pbFileData, cbFileData, BucketIndex);
        CASC_FREE(pbFileData);
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

static int LoadLocalIndexFiles(TCascStorage * hs)
{
    TCHAR * szFileName;
    DWORD OldIndexArray[CASC_INDEX_COUNT];
    DWORD IndexArray[CASC_INDEX_COUNT];
    int nError;

    // Scan all index files and load contained EKEY entries
    memset(OldIndexArray, 0, sizeof(OldIndexArray));
    memset(IndexArray, 0, sizeof(IndexArray));
    nError = ScanIndexDirectory(hs->szIndexPath, IndexDirectory_OnFileFound, IndexArray, OldIndexArray, hs);
    if(nError == ERROR_SUCCESS)
    {
        // Initialize the array of index files
        if((nError = hs->IndexArray.Create(sizeof(CASC_CKEY_ENTRY), 0x200000)) == ERROR_SUCCESS)
        {
            // Load each index file
            for(DWORD i = 0; i < CASC_INDEX_COUNT; i++)
            {
                // Create the name of the index file
                if((szFileName = CreateIndexFileName(hs, i, IndexArray[i])) != NULL)
                {
                    // Inform the user about what we are doing
                    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Loading index files", NULL, i, CASC_INDEX_COUNT))
                    {
                        nError = ERROR_CANCELLED;
                        break;
                    }

                    // Load the index file
                    if((nError = LoadIndexFile(hs, szFileName, i)) != ERROR_SUCCESS)
                        break;
                    CASC_FREE(szFileName);
                }
            }

            // Remember the number of files that are present locally
            hs->LocalFiles = hs->IndexArray.ItemCount();
        }
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Online index files

static int CaptureArcIndexFooter(CASC_ARCINDEX_FOOTER & InFooter, LPBYTE pbIndexFile, DWORD cbIndexFile)
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
        InFooter.EKeyBytes = pFooter08->EKeySizeBytes;
        InFooter.FooterHashBytes = pFooter08->FooterHashBytes;
        InFooter.PageLength = pFooter08->PageSizeKB << 10;
        InFooter.ItemLength = pFooter08->EKeySizeBytes + pFooter08->OffsetBytes + pFooter08->SizeBytes;
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

static int CaptureArcIndexEntry(CASC_ARCINDEX_FOOTER  & InFooter, CASC_ARCINDEX_ENTRY & InEntry, LPBYTE pbIndexPage, LPBYTE pbIndexPageEnd)
{
    // If there enough bytes for one entry/
    if ((pbIndexPage + InFooter.ItemLength) > pbIndexPageEnd)
        return ERROR_BAD_FORMAT;

    // Copy the item
    memcpy(InEntry.EKey, pbIndexPage, InFooter.EKeyBytes);
    pbIndexPage += InFooter.EKeyBytes;

    // Copy the archive offset
    InEntry.EncodedSize = ConvertBytesToInteger_X(pbIndexPage, InFooter.OffsetBytes);
    pbIndexPage += InFooter.OffsetBytes;

    // Copy thefile encoded size
    InEntry.ArchiveOffset = ConvertBytesToInteger_X(pbIndexPage, InFooter.SizeBytes);
    if (InEntry.ArchiveOffset >= 0x10000000)
        return ERROR_BAD_FORMAT;

    // Is there a valid hash?
    return CascIsValidMD5(InEntry.EKey) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

static int VerifyIndexSize(CASC_ARCINDEX_FOOTER  & InFooter, LPBYTE pbIndexFile, size_t cbIndexFile, LPBYTE * PtrIndexEnd)
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

static int LoadArchiveIndexPage(TCascStorage * hs, CASC_ARCINDEX_FOOTER & InFooter, LPBYTE pbIndexHash, LPBYTE pbIndexPage, LPBYTE pbIndexPageEnd)
{
    CASC_ARCINDEX_ENTRY InEntry;
    int nError;

    while (pbIndexPage < pbIndexPageEnd)
    {
        // Capture the index entry
        nError = CaptureArcIndexEntry(InFooter, InEntry, pbIndexPage, pbIndexPageEnd);
        if (nError != ERROR_SUCCESS)
            break;

        // Insert the index entry to the array
        memcpy(InEntry.IndexHash, pbIndexHash, MD5_HASH_SIZE);
        if (hs->ArcIndexArray.Insert(&InEntry, 1) == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Move to the next entry
        pbIndexPage += InFooter.ItemLength;
    }

    return ERROR_SUCCESS;
}

static int LoadArchiveIndexFile(TCascStorage * hs, LPBYTE pbIndexHash, LPBYTE pbIndexFile, DWORD cbIndexFile)
{
    CASC_ARCINDEX_FOOTER InFooter;
    LPBYTE pbIndexEnd = NULL;
    int nError;

    // Validate and capture the footer
    nError = CaptureArcIndexFooter(InFooter, pbIndexFile, cbIndexFile);
    if (nError != ERROR_SUCCESS)
        return nError;

    // Verify the size of the index file
    nError = VerifyIndexSize(InFooter, pbIndexFile, cbIndexFile, &pbIndexEnd);
    if (nError != ERROR_SUCCESS)
        return nError;

    // Parse all pages
    while (pbIndexFile < pbIndexEnd)
    {
        // Load the entire page
        nError = LoadArchiveIndexPage(hs, InFooter, pbIndexHash, pbIndexFile, pbIndexFile + InFooter.PageLength);
        if (nError != ERROR_SUCCESS)
            break;

        // Move to the next page
        pbIndexFile += InFooter.PageLength;
    }

    return ERROR_SUCCESS;
}

static int BuildMapOfArcIndices(TCascStorage * hs)
{
    PCASC_ARCINDEX_ENTRY pEntry;
    size_t nItemCount = hs->ArcIndexArray.ItemCount();
    int nError;

    // Create the map
    nError = hs->ArcIndexMap.Create(nItemCount, MD5_HASH_SIZE, FIELD_OFFSET(CASC_ARCINDEX_ENTRY, EKey));
    if (nError != ERROR_SUCCESS)
        return nError;

    // Insert all items
    for(size_t i = 0; i < nItemCount; i++)
    {
        pEntry = (PCASC_ARCINDEX_ENTRY)hs->ArcIndexArray.ItemAt(i);
        if (pEntry != NULL)
        {
            if (!hs->ArcIndexMap.InsertObject(pEntry, pEntry->EKey))
            {
                return ERROR_NOT_ENOUGH_MEMORY;
            }
        }
    }

    return nError;
}

static int LoadArchiveIndexFiles(TCascStorage * hs)
{
    LPBYTE pbFileData;
    TCHAR szLocalPath[MAX_PATH];
    DWORD cbFileData = 0;
    size_t nArchiveCount = (hs->ArchivesKey.cbData / MD5_HASH_SIZE);
    int nError = ERROR_SUCCESS;

    // Create the array object for the indices
    nError = hs->ArcIndexArray.Create(sizeof(CASC_ARCINDEX_ENTRY), 10000);
    if (nError != ERROR_SUCCESS)
        return nError;

    // Load all the indices
    for (size_t i = 0; i < nArchiveCount; i++)
    {
        LPBYTE pbIndexHash = hs->ArchivesKey.pbData + (i * MD5_HASH_SIZE);

        // Inform the user about what we are doing
        if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Downloading archive indexes", NULL, (DWORD)(i), (DWORD)(nArchiveCount)))
        {
            nError = ERROR_CANCELLED;
            break;
        }

        // Make sure that we have local copy of the file
        nError = DownloadFileFromCDN(hs, _T("data"), pbIndexHash, _T(".index"), szLocalPath, _countof(szLocalPath));
        if (nError == ERROR_SUCCESS)
        {
            // Load the index file to memory
            pbFileData = LoadFileToMemory(szLocalPath, &cbFileData);
            if (pbFileData && cbFileData)
            {
                nError = LoadArchiveIndexFile(hs, pbIndexHash, pbFileData, cbFileData);
                CASC_FREE(pbFileData);
            }
        }

        // Break if an error
        if (nError != ERROR_SUCCESS)
            break;
    }

    // Build map of EKey -> CASC_ARCINDEX_ENTRY
    if (nError == ERROR_SUCCESS)
        nError = BuildMapOfArcIndices(hs);

    return nError;
}

//-----------------------------------------------------------------------------
// Public functions

int LoadIndexFiles(TCascStorage * hs)
{
    if (hs->dwFeatures & CASC_FEATURE_ONLINE)
    {
        return LoadArchiveIndexFiles(hs);
    }
    else
    {
        return LoadLocalIndexFiles(hs);
    }
}