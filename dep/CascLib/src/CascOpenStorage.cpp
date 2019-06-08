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
// Local defines

// Limit for "orphaned" items - those that are in index files, but are not in ENCODING manifest
#define CASC_MAX_ORPHANED_ITEMS 0x100

//-----------------------------------------------------------------------------
// Local variables

static PFNPROGRESSCALLBACK PfnProgressCallback = NULL;
static void * PtrProgressParam = NULL;

//-----------------------------------------------------------------------------
// TCascStorage service functions

TCascStorage::TCascStorage()
{
    // Prepare the base storage parameters
    szClassName = "TCascStorage";
    pRootHandler = NULL;
    dwDefaultLocale = CASC_LOCALE_ENUS | CASC_LOCALE_ENGB;
    dwRefCount = 1;

    szRootPath = szDataPath = szIndexPath = szBuildFile = szCdnServers = szCdnPath = szCodeName = NULL;
    szProductName = NULL;
    szIndexFormat = NULL;
    szRegion = NULL;
    
    memset(DataFiles, 0, sizeof(DataFiles));
    Product = UnknownProduct;
    dwBuildNumber = 0;
    dwFeatures = 0;
    bAllowOrphans = false;
    BuildFileType = CascBuildNone;

    LocalFiles = TotalFiles = EKeyEntries = OrphanItems = SkippedItems = EKeyLength = FileOffsetBits = 0;

    // Take the callback param and data. Zero the global pointers
    PfnCallback = PfnProgressCallback;
    PtrCallbackParam = PtrProgressParam;
    PfnProgressCallback = NULL;
    PtrProgressParam = NULL;
}

TCascStorage::~TCascStorage()
{
    // Free the root handler
    if(pRootHandler != NULL)
        delete pRootHandler;
    pRootHandler = NULL;

    // Close all data files
    for(size_t i = 0; i < CASC_MAX_DATA_FILES; i++)
    {
        FileStream_Close(DataFiles[i]);
        DataFiles[i] = NULL;
    }

    // Free the file paths
    CASC_FREE(szDataPath);
    CASC_FREE(szRootPath);
    CASC_FREE(szBuildFile);
    CASC_FREE(szIndexPath);
    CASC_FREE(szCdnServers);
    CASC_FREE(szCdnPath);
    CASC_FREE(szCodeName);
    CASC_FREE(szRegion);

    // Free the blobs
    FreeCascBlob(&CdnConfigKey);
    FreeCascBlob(&CdnBuildKey);
    
    FreeCascBlob(&ArchiveGroup);
    FreeCascBlob(&ArchivesKey);
    FreeCascBlob(&PatchArchivesKey);
    FreeCascBlob(&PatchArchivesGroup);
    FreeCascBlob(&BuildFiles);
    szClassName = NULL;
}

TCascStorage * TCascStorage::AddRef()
{
    dwRefCount++;
    return this;
}

TCascStorage * TCascStorage::Release()
{
    if (dwRefCount == 1)
    {
        delete this;
        return NULL;
    }

    dwRefCount--;
    return NULL;
}

TCascStorage * TCascStorage::IsValid(HANDLE hStorage)
{
    TCascStorage * hs = (TCascStorage *)hStorage;

    return (hs != NULL && hs->szClassName != NULL && !strcmp(hs->szClassName, "TCascStorage")) ? hs : NULL;
}

//-----------------------------------------------------------------------------
// Local functions

void * ProbeOutputBuffer(void * pvBuffer, size_t cbLength, size_t cbMinLength, size_t * pcbLengthNeeded)
{
    // Verify the output length
    if(cbLength < cbMinLength)
    {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        pvBuffer = NULL;
    }

    // Give the output length and return result
    if(pcbLengthNeeded != NULL)
        pcbLengthNeeded[0] = cbMinLength;
    return pvBuffer;
}

static TCHAR * CheckForIndexDirectory(TCascStorage * hs, const TCHAR * szSubDir)
{
    TCHAR * szIndexPath;

    // Combine the index path
    szIndexPath = CombinePath(hs->szDataPath, szSubDir);
    if (!DirectoryExists(szIndexPath))
    {
        CASC_FREE(szIndexPath);
    }

    return szIndexPath;
}

static int CreateCKeyMaps(TCascStorage * hs, CASC_ENCODING_HEADER & EnHeader)
{
    size_t nEstimatedEntries = (EnHeader.CKeyPageCount * EnHeader.CKeyPageSize) / sizeof(FILE_CKEY_ENTRY);
    size_t nIxEntries = hs->IndexArray.ItemCount();
    int nError;

    // Orphaned items: These are present in INDEX files (by EKey), but missing in the ENCODING manifest.
    // Probably a bug in generator of "2018 - New CASC\00001", but we want to open the storage nontheless.
    if(nEstimatedEntries < 0x100)
    {
        nEstimatedEntries = nEstimatedEntries + nIxEntries;
        hs->bAllowOrphans = true;
    }

    // Allow some room for extra entries
    nEstimatedEntries += CASC_MAX_ORPHANED_ITEMS;

    // Create the array of CKey items
    nError = hs->CKeyArray.Create(sizeof(CASC_CKEY_ENTRY), nEstimatedEntries);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Create the map CKey -> CASC_CKEY_ENTRY
    nError = hs->CKeyMap.Create(nEstimatedEntries, EnHeader.CKeyLength, FIELD_OFFSET(CASC_CKEY_ENTRY, CKey));
    if(nError != ERROR_SUCCESS)
        return nError;

    // Create the map EKey -> CASC_CKEY_ENTRY
    nError = hs->EKeyMap.Create(nEstimatedEntries, hs->EKeyLength, FIELD_OFFSET(CASC_CKEY_ENTRY, EKey));
    if(nError != ERROR_SUCCESS)
        return nError;

    return ERROR_SUCCESS;
}

int CaptureEncodingHeader(CASC_ENCODING_HEADER & EnHeader, LPBYTE pbFileData, size_t cbFileData)
{
    PFILE_ENCODING_HEADER pFileHeader = (PFILE_ENCODING_HEADER)pbFileData;

    // Check the signature ('EN') and version
    if(cbFileData < sizeof(FILE_ENCODING_HEADER) || pFileHeader->Magic != FILE_MAGIC_ENCODING || pFileHeader->Version != 0x01)
        return ERROR_BAD_FORMAT;

    // Note that we don't support CKey and EKey sizes other than 0x10 in the ENCODING file
    if(pFileHeader->CKeyLength != MD5_HASH_SIZE || pFileHeader->EKeyLength != MD5_HASH_SIZE)
        return ERROR_BAD_FORMAT;

    EnHeader.Magic = pFileHeader->Magic;
    EnHeader.Version = pFileHeader->Version;
    EnHeader.CKeyLength = pFileHeader->CKeyLength;
    EnHeader.EKeyLength = pFileHeader->EKeyLength;
    EnHeader.CKeyPageCount = ConvertBytesToInteger_4(pFileHeader->CKeyPageCount);
    EnHeader.CKeyPageSize = ConvertBytesToInteger_2(pFileHeader->CKeyPageSize) * 1024;
    EnHeader.EKeyPageCount = ConvertBytesToInteger_4(pFileHeader->EKeyPageCount);
    EnHeader.EKeyPageSize = ConvertBytesToInteger_2(pFileHeader->EKeyPageSize) * 1024;
    EnHeader.ESpecBlockSize = ConvertBytesToInteger_4(pFileHeader->ESpecBlockSize);
    return ERROR_SUCCESS;
}

static int LoadEncodingCKeyPage(TCascStorage * hs, CASC_ENCODING_HEADER & EnHeader, LPBYTE pbPageBegin, LPBYTE pbEndOfPage)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    PFILE_CKEY_ENTRY pFileEntry;
    LPBYTE pbFileEntry = pbPageBegin;

    // Sanity checks
    assert(hs->CKeyMap.IsInitialized());
    assert(hs->EKeyMap.IsInitialized());

    // Parse all encoding entries
    while(pbFileEntry < pbEndOfPage)
    {
        // Get pointer to the encoding entry
        pFileEntry = (PFILE_CKEY_ENTRY)pbFileEntry;
        if(pFileEntry->EKeyCount == 0)
            break;

        // Example of a file entry with multiple EKeys: 
        // Overwatch build 24919, CKey: 0e 90 94 fa d2 cb 85 ac d0 7c ea 09 f9 c5 ba 00 
//      BREAKIF(pFileEntry->EKeyCount > 1);

        // Insert the CKey entry into the array
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1);
        if(pCKeyEntry != NULL)
        {
            // Supply both CKey and EKey. Rewrite EKey regardless, because ENCODING manifest contains a full one
            CopyMemory16(pCKeyEntry->CKey, pFileEntry->CKey);
            CopyMemory16(pCKeyEntry->EKey, pFileEntry->EKey);
            pCKeyEntry->StorageOffset = CASC_INVALID_OFFS64;
            pCKeyEntry->TagBitMask = 0;
            pCKeyEntry->EncodedSize = CASC_INVALID_SIZE;
            pCKeyEntry->ContentSize = ConvertBytesToInteger_4(pFileEntry->ContentSize);
            pCKeyEntry->RefCount = 0;
            pCKeyEntry->Priority = 0;
            pCKeyEntry->Flags = (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY | CASC_CE_IN_ENCODING);

            // Insert the item into both maps
            hs->CKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->CKey);
            hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
        }

        // Move to the next encoding entry
        pbFileEntry = pbFileEntry + 2 + 4 + EnHeader.CKeyLength + (pFileEntry->EKeyCount * EnHeader.EKeyLength);
    }
    return ERROR_SUCCESS;
}

static PCASC_CKEY_ENTRY InsertCKeyEntry(TCascStorage * hs, PCASC_CKEY_ENTRY pSourceEntry, bool bAllowOrphans, bool * pbAllocatedNewEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;
    bool bAllocatedNewEntry = false;

    if(pSourceEntry->Flags & CASC_CE_HAS_EKEY)
    {
        // If there is that item already, reuse it
        pCKeyEntry = FindCKeyEntry_EKey(hs, pSourceEntry->EKey);
        if(pCKeyEntry == NULL)
        {
            // Increment number of orphaned index entries
            hs->OrphanItems++;

            // Insert the orphan item only of they are allowed and if we won't overflow the array
            if(bAllowOrphans && (hs->CKeyArray.ItemCount() + 1) < hs->CKeyArray.ItemCountMax())
            {
                // Insert a new entry to the array
                pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1);
                if(pCKeyEntry != NULL)
                {
                    // Copy CKey, EKey and some flags
                    if(pSourceEntry->Flags & CASC_CE_HAS_CKEY)
                        CopyMemory16(pCKeyEntry->CKey, pSourceEntry->CKey);

                    if(pSourceEntry->Flags & CASC_CE_HAS_EKEY)
                        CopyMemory16(pCKeyEntry->EKey, pSourceEntry->EKey);

                    pCKeyEntry->StorageOffset = CASC_INVALID_OFFS64;
                    pCKeyEntry->TagBitMask = 0;
                    pCKeyEntry->RefCount = 0;
                    pCKeyEntry->Priority = 0;

                    pCKeyEntry->EncodedSize = CASC_INVALID_SIZE;
                    pCKeyEntry->ContentSize = CASC_INVALID_SIZE;
                    pCKeyEntry->Flags = (pSourceEntry->Flags & (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY | CASC_CE_HAS_EKEY_PARTIAL));
                    bAllocatedNewEntry = true;
                }
            }
            else
            {
                hs->SkippedItems++;
            }
        }
    }

    if(pbAllocatedNewEntry != NULL)
        pbAllocatedNewEntry[0] = bAllocatedNewEntry;
    return pCKeyEntry;
}

static PCASC_CKEY_ENTRY CopyBuildFileItemToCKeyArray(TCascStorage * hs, PCASC_CKEY_ENTRY pSourceEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;
    bool bAllocatedNewEntry = false;

    pCKeyEntry = InsertCKeyEntry(hs, pSourceEntry, true, &bAllocatedNewEntry);
    if(pCKeyEntry != NULL)
    {
        // Fill the values that might be known
        if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
            pCKeyEntry->EncodedSize = pSourceEntry->EncodedSize;
        if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
            pCKeyEntry->ContentSize = pSourceEntry->ContentSize;

        // If this is a new entry, we need to insert it to the maps
        if(bAllocatedNewEntry)
        {
            if(pCKeyEntry->Flags & CASC_CE_HAS_CKEY)
                hs->CKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->CKey);
            if(pCKeyEntry->Flags & CASC_CE_HAS_EKEY)
                hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
        }
    }

    return pCKeyEntry;
}

static int CopyBuildFileItemsToCKeyArray(TCascStorage * hs)
{
    // Insert the well-known files
    CopyBuildFileItemToCKeyArray(hs, &hs->EncodingCKey);
    CopyBuildFileItemToCKeyArray(hs, &hs->DownloadCKey);
    CopyBuildFileItemToCKeyArray(hs, &hs->InstallCKey);
    CopyBuildFileItemToCKeyArray(hs, &hs->PatchFile);
    CopyBuildFileItemToCKeyArray(hs, &hs->RootFile);
    CopyBuildFileItemToCKeyArray(hs, &hs->SizeFile);
    CopyBuildFileItemToCKeyArray(hs, &hs->VfsRoot);

    // Insert all VFS roots
    for(size_t i = 0; i < hs->VfsRootList.ItemCount(); i++)
    {
        PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)hs->VfsRootList.ItemAt(i);
        CopyBuildFileItemToCKeyArray(hs, pCKeyEntry);
    }

    return ERROR_SUCCESS;
}

static int CopyIndexItemsToCKeyArray(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pIndexEntry;
    PCASC_CKEY_ENTRY pCKeyEntry;
    size_t nItemCount = hs->IndexArray.ItemCount();
    bool bAllocatedNewEntry = false;

    // Iterate over all index items
    for(size_t i = 0; i < nItemCount; i++)
    {
        // Get the n-th index entry
        pIndexEntry = (PCASC_CKEY_ENTRY)hs->IndexArray.ItemAt(i);

        // Sometimes, there are multiple items with the same EKey in the index files
        // Example: "2018 - New CASC\00001", EKey 37 89 16 5b 2d cc 71 c1 25 00 00 00 00 00 00 00
        // Positions: 0x2D, 0x2E, 0x2F
        //BREAK_ON_XKEY3(pIndexEntry->EKey, 0x37, 0x89, 0x16);

        // Copy the index entry to the central storage
        if((pCKeyEntry = InsertCKeyEntry(hs, pIndexEntry, hs->bAllowOrphans, &bAllocatedNewEntry)) != NULL)
        {
            // Make sure that the CKey is zeroed when not present
            if((pCKeyEntry->Flags & CASC_CE_HAS_CKEY) == 0)
                ZeroMemory16(pCKeyEntry->CKey);

            // Only copy the storage offset and sizes if not available yet
            if(pCKeyEntry->StorageOffset == CASC_INVALID_OFFS64)
            {
                pCKeyEntry->StorageOffset = pIndexEntry->StorageOffset;
                pCKeyEntry->EncodedSize = pIndexEntry->EncodedSize;
            }

            if(bAllocatedNewEntry)
            {
                if(pCKeyEntry->Flags & CASC_CE_HAS_CKEY)
                    hs->CKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->CKey);
                if(pCKeyEntry->Flags & CASC_CE_HAS_EKEY)
                    hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
            }

            // Mark the file as available locally
            pCKeyEntry->Flags |= CASC_CE_FILE_IS_LOCAL;
        }
    }

    // We free the index array at this point
    hs->IndexArray.Free();
    return ERROR_SUCCESS;
}

static int LoadEncodingManifest(TCascStorage * hs)
{
    LPBYTE pbEncodingFile;
    DWORD cbEncodingFile = 0;
    int nError = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Loading ENCODING manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire encoding file to memory
    pbEncodingFile = LoadInternalFileToMemory(hs, &hs->EncodingCKey, &cbEncodingFile);
    if(pbEncodingFile != NULL && cbEncodingFile != 0)
    {
        CASC_ENCODING_HEADER EnHeader;

        // Capture the header of the ENCODING file
        nError = CaptureEncodingHeader(EnHeader, pbEncodingFile, cbEncodingFile);
        if(nError == ERROR_SUCCESS)
        {
            // Get the CKey page header and the first page
            PFILE_CKEY_PAGE pPageHeader = (PFILE_CKEY_PAGE)(pbEncodingFile + sizeof(FILE_ENCODING_HEADER) + EnHeader.ESpecBlockSize);
            LPBYTE pbCKeyPage = (LPBYTE)(pPageHeader + EnHeader.CKeyPageCount);

            // Since ENCODING contains the full list of all files (even those not downloaded),
            // we can now make a fair estimate about how large maps shall we create.
            // So, we can build the maps CKey and EKey map.
            if((nError = CreateCKeyMaps(hs, EnHeader)) == ERROR_SUCCESS)
            {
                // Go through all CKey pages and verify them
                for(DWORD i = 0; i < EnHeader.CKeyPageCount; i++)
                {
                    PFILE_CKEY_ENTRY pCKeyEntry = (PFILE_CKEY_ENTRY)pbCKeyPage;

                    // Check if there is enough space in the buffer
                    if((pbCKeyPage + EnHeader.CKeyPageSize) > (pbEncodingFile + cbEncodingFile))
                    {
                        nError = ERROR_FILE_CORRUPT;
                        break;
                    }

                    // Check the hash of the entire segment
                    // Note that verifying takes considerable time of the storage loading
//                  if(!VerifyDataBlockHash(pbCKeyPage, EnHeader.CKeyPageSize, pEncodingSegment->SegmentHash))
//                  {
//                      nError = ERROR_FILE_CORRUPT;
//                      break;
//                  }

                    // Check if the CKey matches with the expected first value
                    if(memcmp(pCKeyEntry->CKey, pPageHeader[i].FirstKey, CASC_CKEY_SIZE))
                    {
                        nError = ERROR_FILE_CORRUPT;
                        break;
                    }

                    // Load the entire page of CKey entries.
                    // This operation will never fail, because all memory is already pre-allocated
                    nError = LoadEncodingCKeyPage(hs, EnHeader, pbCKeyPage, pbCKeyPage + EnHeader.CKeyPageSize);
                    if(nError != ERROR_SUCCESS)
                        break;

                    // Move to the next CKey page
                    pbCKeyPage += EnHeader.CKeyPageSize;
                }
            }
        }

        // All CKey->EKey entries from the text build files need to be copied to the CKey array
        // This also includes the ENCODING file itself, which is vital for later loading
        if(nError == ERROR_SUCCESS)
        {
            nError = CopyBuildFileItemsToCKeyArray(hs);
        }

        // Now supply all the entries from the index files
        if(nError == ERROR_SUCCESS)
        {
            nError = CopyIndexItemsToCKeyArray(hs);
        }

        // Free the loaded ENCODING file
        CASC_FREE(pbEncodingFile);
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

size_t GetTagBitmapLength(LPBYTE pbFilePtr, LPBYTE pbFileEnd, DWORD EntryCount)
{
    size_t nBitmapLength;

    nBitmapLength = (EntryCount / 8) + ((EntryCount & 0x07) ? 1 : 0);
    if ((pbFilePtr + nBitmapLength) > pbFileEnd)
        nBitmapLength = (pbFileEnd - pbFilePtr);

    return nBitmapLength;
}

int CaptureDownloadHeader(CASC_DOWNLOAD_HEADER & DlHeader, LPBYTE pbFileData, size_t cbFileData)
{
    PFILE_DOWNLOAD_HEADER pFileHeader = (PFILE_DOWNLOAD_HEADER)pbFileData;

    // Check the signature ('DL') and version
    if(cbFileData < sizeof(FILE_DOWNLOAD_HEADER) || pFileHeader->Magic != FILE_MAGIC_DOWNLOAD || pFileHeader->Version > 3)
        return ERROR_BAD_FORMAT;

    // Note that we don't support CKey sizes greater than 0x10 in the DOWNLOAD file
    if(pFileHeader->EKeyLength > MD5_HASH_SIZE)
        return ERROR_BAD_FORMAT;

    // Capture the header version 1
    memset(&DlHeader, 0, sizeof(CASC_DOWNLOAD_HEADER));
    DlHeader.Magic = pFileHeader->Magic;
    DlHeader.Version = pFileHeader->Version;
    DlHeader.EKeyLength = pFileHeader->EKeyLength;
    DlHeader.EntryHasChecksum = pFileHeader->EntryHasChecksum;
    DlHeader.EntryCount = ConvertBytesToInteger_4(pFileHeader->EntryCount);
    DlHeader.TagCount = ConvertBytesToInteger_2(pFileHeader->TagCount);
    DlHeader.HeaderLength = FIELD_OFFSET(FILE_DOWNLOAD_HEADER, FlagByteSize);
    DlHeader.EntryLength = DlHeader.EKeyLength + 5 + 1 + (DlHeader.EntryHasChecksum ? 4 : 0);

    // Capture header version 2
    if (pFileHeader->Version >= 2)
    {
        DlHeader.FlagByteSize = pFileHeader->FlagByteSize;
        DlHeader.HeaderLength = FIELD_OFFSET(FILE_DOWNLOAD_HEADER, BasePriority);
        DlHeader.EntryLength += DlHeader.FlagByteSize;

        // Capture header version 3
        if (pFileHeader->Version >= 3)
        {
            DlHeader.BasePriority = pFileHeader->BasePriority;
            DlHeader.HeaderLength = sizeof(FILE_DOWNLOAD_HEADER);
        }
    }

    return ERROR_SUCCESS;
}

int CaptureDownloadEntry(CASC_DOWNLOAD_HEADER & DlHeader, CASC_DOWNLOAD_ENTRY & DlEntry, LPBYTE pbFilePtr, LPBYTE pbFileEnd)
{
    // Check the range
    if((pbFilePtr + DlHeader.EntryLength) >= pbFileEnd)
        return ERROR_BAD_FORMAT;
    memset(&DlEntry, 0, sizeof(CASC_DOWNLOAD_ENTRY));

    // Copy the EKey
    memcpy(DlEntry.EKey, pbFilePtr, DlHeader.EKeyLength);
    pbFilePtr += DlHeader.EKeyLength;

    // Convert the file size
    DlEntry.EncodedSize = ConvertBytesToInteger_5(pbFilePtr);
    pbFilePtr += 5;

    // Copy the file priority
    DlEntry.Priority = pbFilePtr[0];
    pbFilePtr++;

    // Copy the checksum
    if(DlHeader.EntryHasChecksum)
    {
        DlEntry.Checksum = ConvertBytesToInteger_4(pbFilePtr);
        pbFilePtr += 4;
    }

    // Copy the flags
    DlEntry.Flags = ConvertBytesToInteger_X(pbFilePtr, DlHeader.FlagByteSize);
    return ERROR_SUCCESS;
}

int CaptureDownloadTag(CASC_DOWNLOAD_HEADER & DlHeader, CASC_TAG_ENTRY1 & DlTag, LPBYTE pbFilePtr, LPBYTE pbFileEnd)
{
    LPBYTE pbSaveFilePtr = pbFilePtr;

    // Prepare the tag structure
    memset(&DlTag, 0, sizeof(CASC_TAG_ENTRY1));
    DlTag.szTagName = (const char *)pbFilePtr;

    // Skip the tag string
    while(pbFilePtr < pbFileEnd && pbFilePtr[0] != 0)
        pbFilePtr++;
    if(pbFilePtr >= pbFileEnd)
        return ERROR_BAD_FORMAT;
    
    // Save the length of the tag name
    DlTag.NameLength = (pbFilePtr - pbSaveFilePtr);
    pbFilePtr++;

    // Get the tag value
    if((pbFilePtr + sizeof(DWORD)) > pbFileEnd)
        return ERROR_BAD_FORMAT;
    DlTag.TagValue = ConvertBytesToInteger_2(pbFilePtr);
    pbFilePtr += 2;

    // Get the bitmap
    DlTag.Bitmap = pbFilePtr;

    // Get the bitmap length.
    // If the bitmap is last in the list and it's shorter than declared, we make it shorter
    DlTag.BitmapLength = GetTagBitmapLength(pbFilePtr, pbFileEnd, DlHeader.EntryCount);
    
    // Get the entry length
    DlTag.TagLength = (pbFilePtr - pbSaveFilePtr) + DlTag.BitmapLength;
    return ERROR_SUCCESS;
}

static int LoadDownloadManifest(TCascStorage * hs, CASC_DOWNLOAD_HEADER & DlHeader, LPBYTE pbFileData, LPBYTE pbFileEnd)
{
    PCASC_TAG_ENTRY1 TagArray = NULL;
    LPBYTE pbEntries = pbFileData + DlHeader.HeaderLength;
    LPBYTE pbEntry = pbEntries;
    LPBYTE pbTags = pbEntries + DlHeader.EntryLength * DlHeader.EntryCount;
    LPBYTE pbTag = pbTags;
    size_t nMaxNameLength = 0;
    size_t nTagEntryLengh = 0;
    int nError = ERROR_SUCCESS;

    // Does the storage support tags?
    if(DlHeader.TagCount != 0)
    {
        // Remember that we support tags
        hs->dwFeatures |= CASC_FEATURE_TAGS;

        // Allocate space for the tag array
        TagArray = CASC_ALLOC(CASC_TAG_ENTRY1, DlHeader.TagCount);
        if(TagArray != NULL)
        {
            // Get the longest tag name
            for(DWORD i = 0; i < DlHeader.TagCount; i++)
            {
                if(CaptureDownloadTag(DlHeader, TagArray[i], pbTag, pbFileEnd) == ERROR_SUCCESS)
                    nMaxNameLength = CASCLIB_MAX(nMaxNameLength, TagArray[i].NameLength);
                pbTag = pbTag + TagArray[i].TagLength;
            }

            // Determine the tag entry length
            nTagEntryLengh = FIELD_OFFSET(CASC_TAG_ENTRY2, szTagName) + nMaxNameLength;
            nTagEntryLengh = ALIGN_TO_SIZE(nTagEntryLengh, 8);

            // Load the tags into array in the storage structure
            nError = hs->TagsArray.Create(nTagEntryLengh, DlHeader.TagCount);
            if(nError == ERROR_SUCCESS)
            {
                // Convert the array of CASC_DOWNLOAD_TAG1 to array of CASC_DOWNLOAD_TAG2
                for(DWORD i = 0; i < DlHeader.TagCount; i++)
                {
                    PCASC_TAG_ENTRY1 pSourceTag = &TagArray[i];
                    PCASC_TAG_ENTRY2 pTargetTag;

                    // Insert the tag to the array
                    pTargetTag = (PCASC_TAG_ENTRY2)hs->TagsArray.Insert(1);
                    if(pTargetTag == NULL)
                    {
                        nError = ERROR_NOT_ENOUGH_MEMORY;
                        break;
                    }

                    // Copy the tag structure
                    memset(pTargetTag, 0, nTagEntryLengh);
                    memcpy(pTargetTag->szTagName, pSourceTag->szTagName, pSourceTag->NameLength);
                    pTargetTag->NameLength = pSourceTag->NameLength;
                    pTargetTag->TagValue = pSourceTag->TagValue;
                }
            }
        }
        else
        {
            nError = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Now parse all entries. For each entry, mark the corresponding tag bit in the EKey table
    for(DWORD i = 0; i < DlHeader.EntryCount; i++)
    {
        CASC_DOWNLOAD_ENTRY DlEntry;
        PCASC_CKEY_ENTRY pCKeyEntry;
        size_t BitMaskOffset = (i / 8);
        BYTE BitMaskBit = 0x80 >> (i % 8);

        // Capture the download entry
        if(CaptureDownloadEntry(DlHeader, DlEntry, pbEntry, pbFileEnd) != ERROR_SUCCESS)
            break;

        // Make sure we have the entry in CKey table
        pCKeyEntry = FindCKeyEntry_EKey(hs, DlEntry.EKey);
        if(pCKeyEntry != NULL)
        {
            ULONGLONG TagBit = 1;
            size_t TagItemCount = hs->TagsArray.ItemCount();

            // Supply the tag bits
            for(size_t j = 0; j < TagItemCount; j++)
            {
                // Set the bit in the entry, if the tag for it is present
                if((BitMaskOffset < TagArray[j].BitmapLength) && (TagArray[j].Bitmap[BitMaskOffset] & BitMaskBit))
                    pCKeyEntry->TagBitMask |= TagBit;

                // Move to the next bit
                TagBit <<= 1;
            }

            // If the EKey has partial EKey only, fix that
            if(pCKeyEntry->Flags & CASC_CE_HAS_EKEY_PARTIAL)
            {
                CopyMemory16(pCKeyEntry->EKey, DlEntry.EKey);
                pCKeyEntry->Flags &= ~CASC_CE_HAS_EKEY_PARTIAL;
            }

            // Supply the priority
            pCKeyEntry->Priority = DlEntry.Priority;
            pCKeyEntry->Flags |= CASC_CE_IN_DOWNLOAD;
        }

        // Move to the next entry
        pbEntry += DlHeader.EntryLength;
    }

    // Free the tag array, if any
    CASC_FREE(TagArray);

    // Remember the total file count
    hs->TotalFiles = hs->CKeyArray.ItemCount();
    return nError;
}

static int LoadDownloadManifest(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pCKeyEntry = FindCKeyEntry_CKey(hs, hs->DownloadCKey.CKey);
    LPBYTE pbDownloadFile = NULL;
    DWORD cbDownloadFile = 0;
    int nError = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Loading DOWNLOAD manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire DOWNLOAD file to memory
    pbDownloadFile = LoadInternalFileToMemory(hs, pCKeyEntry, &cbDownloadFile);
    if(pbDownloadFile != NULL && cbDownloadFile != 0)
    {
        CASC_DOWNLOAD_HEADER DlHeader;

        // Capture the header of the DOWNLOAD file
        nError = CaptureDownloadHeader(DlHeader, pbDownloadFile, cbDownloadFile);
        if(nError == ERROR_SUCCESS)
        {
            // Parse the entire download manifest
            nError = LoadDownloadManifest(hs, DlHeader, pbDownloadFile, pbDownloadFile + cbDownloadFile); 
        }

        // Free the loaded manifest
        CASC_FREE(pbDownloadFile);
    }

    // If the DOWNLOAD manifest is not present, we won't abort the downloading process.
    return nError;
}

//-----------------------------------------------------------------------------
// INSTALL manifest. This is a replacement for ROOT, if loading ROOT fails
// https://wowdev.wiki/TACT#Install_manifest

static int LoadInstallManifest(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pCKeyEntry = FindCKeyEntry_CKey(hs, hs->InstallCKey.CKey);
    LPBYTE pbInstallFile = NULL;
    DWORD cbInstallFile = 0;
    int nError = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Loading INSTALL manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire DOWNLOAD file to memory
    pbInstallFile = LoadInternalFileToMemory(hs, pCKeyEntry, &cbInstallFile);
    if (pbInstallFile != NULL && cbInstallFile != 0)
    {
        nError = RootHandler_CreateInstall(hs, pbInstallFile, cbInstallFile);
        CASC_FREE(pbInstallFile);
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

static bool InsertWellKnownFile(TCascStorage * hs, const char * szFileName, CASC_CKEY_ENTRY & FakeCKeyEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;

    // We need to find the CKey entry in the central array
    if(FakeCKeyEntry.Flags & CASC_CE_HAS_CKEY)
    {
        // Did we find anything?
        pCKeyEntry = FindCKeyEntry_CKey(hs, FakeCKeyEntry.CKey);
        if(pCKeyEntry != NULL)
        {
            // Insert the key to the root handler, unless it's already referenced by a name
            if(pCKeyEntry->RefCount == 0)
                hs->pRootHandler->Insert(szFileName, pCKeyEntry);
            return true;
        }
    }

    return false;
}

static int LoadBuildManifest(TCascStorage * hs, DWORD dwLocaleMask)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    PDWORD FileSignature;
    LPBYTE pbRootFile = NULL;
    DWORD cbRootFile = 0;
    int nError = ERROR_BAD_FORMAT;

    // Sanity checks
    assert(hs->CKeyMap.IsInitialized() == true);
    assert(hs->pRootHandler == NULL);

    // Locale: The default parameter is 0 - in that case,
    // we assign the default locale, loaded from the .build.info file
    if(dwLocaleMask == 0)
        dwLocaleMask = hs->dwDefaultLocale;

    // Prioritize the VFS root over legacy ROOT file
    pCKeyEntry = (hs->VfsRoot.ContentSize != CASC_INVALID_SIZE) ? &hs->VfsRoot : &hs->RootFile;
    pCKeyEntry = FindCKeyEntry_CKey(hs, pCKeyEntry->CKey);

    // Inform the user about what we are doing
    if(hs->PfnCallback && hs->PfnCallback(hs->PtrCallbackParam, "Loading ROOT manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire ROOT file to memory
    pbRootFile = LoadInternalFileToMemory(hs, pCKeyEntry, &cbRootFile);
    if(pbRootFile != NULL)
    {
        // Ignore ROOT files that contain just a MD5 hash
        if(cbRootFile > MD5_STRING_SIZE)
        {
            // Check the type of the ROOT file
            FileSignature = (PDWORD)pbRootFile;
            switch(FileSignature[0])
            {
                case CASC_MNDX_ROOT_SIGNATURE:
                    nError = RootHandler_CreateMNDX(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_DIABLO3_ROOT_SIGNATURE:
                    nError = RootHandler_CreateDiablo3(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_TVFS_ROOT_SIGNATURE:
                    nError = RootHandler_CreateTVFS(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_WOW82_ROOT_SIGNATURE:
                    nError = RootHandler_CreateWoW(hs, pbRootFile, cbRootFile, dwLocaleMask);
                    break;

                default:

                    //
                    // Each of these handler creators must verify their format first.
                    // If the format was not recognized, they need to return ERROR_BAD_FORMAT
                    //

                    nError = RootHandler_CreateOverwatch(hs, pbRootFile, cbRootFile);
                    if(nError == ERROR_BAD_FORMAT)
                    {
                        nError = RootHandler_CreateStarcraft1(hs, pbRootFile, cbRootFile);
                        if(nError == ERROR_BAD_FORMAT)
                        {
                            nError = RootHandler_CreateWoW(hs, pbRootFile, cbRootFile, dwLocaleMask);
                        }
                    }
                    break;
            }
        }

        // Free the root file
        CASC_FREE(pbRootFile);
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

static int InitializeLocalDirectories(TCascStorage * hs, const TCHAR * szPath)
{
    TCHAR * szWorkPath;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Find the root directory of the storage. The root directory
    // is the one with ".build.info" or ".build.db".
    szWorkPath = CascNewStr(szPath);
    if(szWorkPath != NULL)
    {
        // Get the length and go up until we find the ".build.info" or ".build.db"
        for(;;)
        {
            // Is this a game directory?
            nError = CheckGameDirectory(hs, szWorkPath);
            if(nError == ERROR_SUCCESS)
            {
                nError = ERROR_SUCCESS;
                break;
            }

            // Cut one path part
            if(!CutLastPathPart(szWorkPath))
            {
                nError = ERROR_FILE_NOT_FOUND;
                break;
            }
        }

        // Find the index directory
        if (nError == ERROR_SUCCESS)
        {
            // First, check for more common "data" subdirectory
            if ((hs->szIndexPath = CheckForIndexDirectory(hs, _T("data"))) != NULL)
                nError = ERROR_SUCCESS;

            // Second, try the "darch" subdirectory (older builds of HOTS - Alpha)
            else if ((hs->szIndexPath = CheckForIndexDirectory(hs, _T("darch"))) != NULL)
                nError = ERROR_SUCCESS;

            else
                nError = ERROR_FILE_NOT_FOUND;
        }

        // Free the work path buffer
        CASC_FREE(szWorkPath);
    }

    return nError;
}

static int InitializeOnlineDirectories(TCascStorage * hs, LPCTSTR szLocalCache, LPCSTR szCodeName, LPCSTR szRegion)
{
    TCHAR szCodeNameT[0x40];

    CascStrCopy(szCodeNameT, _countof(szCodeNameT), szCodeName);
    hs->szRootPath = CombinePath(szLocalCache, szCodeNameT);
    if (hs->szRootPath != NULL)
    {
        // Create the name of the build file
        hs->szBuildFile = CombinePath(hs->szRootPath, _T("versions"));
        if(hs->szBuildFile != NULL)
        {
            hs->szCodeName = CascNewStr(szCodeNameT);
            hs->szRegion = CascNewStr(szRegion);
            if(hs->szCodeName != NULL)
            {
                hs->BuildFileType = CascVersionsDb;
                hs->dwFeatures |= CASC_FEATURE_ONLINE;
                return ERROR_SUCCESS;
            }
        }
    }

    return ERROR_NOT_ENOUGH_MEMORY;
}

static DWORD GetStorageTotalFileCount(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    size_t nItemCount = hs->CKeyArray.ItemCount();
    DWORD TotalFileCount = 0;

    for(size_t i = 0; i < nItemCount; i++)
    {
        if((pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.ItemAt(i)) != NULL)
        {
            if((pCKeyEntry->Flags & CASC_CE_FOLDER_ENTRY) == 0)
            {
                // If there is zero or one file name reference, we count the item as one file.
                // If there is more than 1 name reference, we count the file as many times as number of references
                DWORD RefCount = (pCKeyEntry->RefCount > 0) ? pCKeyEntry->RefCount : 1;

                // Add the number of references to the total file count
                TotalFileCount += RefCount;
            }
        }
    }

    return TotalFileCount;
}

static bool GetStorageProduct(TCascStorage * hs, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded)
{
    PCASC_STORAGE_PRODUCT pProductInfo;

    // Verify whether we have enough space in the buffer
    pProductInfo = (PCASC_STORAGE_PRODUCT)ProbeOutputBuffer(pvStorageInfo, cbStorageInfo, sizeof(CASC_STORAGE_PRODUCT), pcbLengthNeeded);
    if(pProductInfo != NULL)
    {
        pProductInfo->szProductName = hs->szProductName;
        pProductInfo->dwBuildNumber = hs->dwBuildNumber;
        pProductInfo->Product = hs->Product;
    }

    return (pProductInfo != NULL);
}

static bool GetStorageTags(TCascStorage * hs, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded)
{
    PCASC_STORAGE_TAGS pTags;
    PCASC_TAG_ENTRY2 pTag;
    char * szNameBuffer;
    size_t cbMinLength;

    // Does the storage support tags?
    if(hs->TagsArray.IsInitialized() == false)
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return false;
    }

    // Calculate the length of the tags
    cbMinLength = FIELD_OFFSET(CASC_STORAGE_TAGS, Tags) + hs->TagsArray.ItemCount() * sizeof(CASC_STORAGE_TAG);
    szNameBuffer = (char *)pvStorageInfo + cbMinLength;

    // Also include the tag length
    for(size_t i = 0; i < hs->TagsArray.ItemCount(); i++)
    {
        pTag = (PCASC_TAG_ENTRY2)hs->TagsArray.ItemAt(i);
        cbMinLength = cbMinLength + pTag->NameLength + 1;
    }

    // Verify whether we have enough space in the buffer
    pTags = (PCASC_STORAGE_TAGS)ProbeOutputBuffer(pvStorageInfo, cbStorageInfo, cbMinLength, pcbLengthNeeded);
    if(pTags != NULL)
    {
        // Fill the output structure
        pTags->TagCount = hs->TagsArray.ItemCount();
        pTags->Reserved = 0;

        // Copy the tags
        for(size_t i = 0; i < hs->TagsArray.ItemCount(); i++)
        {
            // Get the source tag
            pTag = (PCASC_TAG_ENTRY2)hs->TagsArray.ItemAt(i);

            // Fill the target tag
            pTags->Tags[i].szTagName = szNameBuffer;
            pTags->Tags[i].TagNameLength = (DWORD)pTag->NameLength;
            pTags->Tags[i].TagValue = pTag->TagValue;

            // Copy the tag name
            memcpy(szNameBuffer, pTag->szTagName, pTag->NameLength);
            szNameBuffer[pTag->NameLength] = 0;
            szNameBuffer = szNameBuffer + pTag->NameLength + 1;
        }
    }

    return (pTags != NULL);
}

static int LoadCascStorage(TCascStorage * hs, DWORD dwLocaleMask)
{
    int nError = ERROR_SUCCESS;

    // For online storages, we need to load CDN servers
    if ((nError == ERROR_SUCCESS) && (hs->dwFeatures & CASC_FEATURE_ONLINE))
    {
        nError = LoadCdnsInfo(hs);
    }

    // Now, load the main storage file ".build.info" (or ".build.db" in old storages) 
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadBuildInfo(hs);
    }

    // If the .build.info OR .build.db file has been loaded,
    // proceed with loading the CDN config file
    if (nError == ERROR_SUCCESS)
    {
        nError = LoadCdnConfigFile(hs);
    }

    // Proceed with loading the CDN build file
    if (nError == ERROR_SUCCESS)
    {
        nError = LoadCdnBuildFile(hs);
    }

    // Load the index files. Store information from the index files to the CKeyArray.
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadIndexFiles(hs);
    }

    // Load the ENCODING manifest
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadEncodingManifest(hs);
    }

    // We need to load the DOWNLOAD manifest. This will give us the information about
    // how many physical files are in the storage, so we can start building file tables
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadDownloadManifest(hs);
    }

    // Load the build manifest ("ROOT" file)
    if(nError == ERROR_SUCCESS)
    {
        // If we fail to load the ROOT file, we take the file names from the INSTALL manifest
        nError = LoadBuildManifest(hs, dwLocaleMask);
        if (nError != ERROR_SUCCESS)
        {
            nError = LoadInstallManifest(hs);
        }
    }

    // Insert entries for files with well-known names. Their CKeys are in the BUILD file
    // See https://wowdev.wiki/TACT#Encoding_table for their list
    if (nError == ERROR_SUCCESS)
    {
        InsertWellKnownFile(hs, "ENCODING", hs->EncodingCKey);
        InsertWellKnownFile(hs, "DOWNLOAD", hs->DownloadCKey);
        InsertWellKnownFile(hs, "INSTALL", hs->InstallCKey);
        InsertWellKnownFile(hs, "PATCH", hs->PatchFile);
        InsertWellKnownFile(hs, "ROOT", hs->RootFile);
        InsertWellKnownFile(hs, "SIZE", hs->SizeFile);

        // Also reset the total file count. CascGetStorageInfo will update it on next call
        hs->TotalFiles = 0;
    }

    // Load the encryption keys
    if (nError == ERROR_SUCCESS)
    {
        nError = CascLoadEncryptionKeys(hs);
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Public functions

void WINAPI CascSetProgressCallback(PFNPROGRESSCALLBACK PtrUserCallback, void * PtrUserParam)
{
    PfnProgressCallback = PtrUserCallback;
    PtrProgressParam = PtrUserParam;
}

bool WINAPI CascOpenStorage(LPCTSTR szPath, DWORD dwLocaleMask, HANDLE * phStorage)
{
    TCascStorage * hs;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the storage structure
    if((hs = new TCascStorage()) != NULL)
    {
        // Setup the directories
        nError = InitializeLocalDirectories(hs, szPath);
        if(nError == ERROR_SUCCESS)
        {
            nError = LoadCascStorage(hs, dwLocaleMask);
            if(nError == ERROR_SUCCESS)
            {
                *phStorage = (HANDLE)hs;
                return true;
            }
        }

        // Delete the so-far-allocated storage
        hs = hs->Release();
    }

    // Failed
    SetLastError(nError);
    *phStorage = NULL;
    return false;
}

// Allows to browse an online CDN storage
// szLocalCache: Local folder, where the online file will be cached.
// szCodeName: Product code name, e.g. "agent" for Battle.net Agent. More info: https://wowdev.wiki/TACT#Products
// szRegion: The region (or subvariant) of the product. Corresponds to the first column of the "versions" file.
bool WINAPI CascOpenOnlineStorage(LPCTSTR szLocalCache, LPCSTR szCodeName, LPCSTR szRegion, DWORD dwLocaleMask, HANDLE * phStorage)
{
    TCascStorage * hs;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Allocate the storage structure
    if((hs = new TCascStorage()) != NULL)
    {
        // Setup the directories
        nError = InitializeOnlineDirectories(hs, szLocalCache, szCodeName, szRegion);
        if(nError == ERROR_SUCCESS)
        {
            nError = LoadCascStorage(hs, dwLocaleMask);
            if(nError == ERROR_SUCCESS)
            {
                *phStorage = (HANDLE)hs;
                return true;
            }
        }

        // Delete the so-far-allocated storage
        hs = hs->Release();
    }

    // Failed
    SetLastError(nError);
    *phStorage = NULL;
    return false;
}

bool WINAPI CascGetStorageInfo(
    HANDLE hStorage,
    CASC_STORAGE_INFO_CLASS InfoClass,
    void * pvStorageInfo,
    size_t cbStorageInfo,
    size_t * pcbLengthNeeded)
{
    TCascStorage * hs;
    PDWORD PtrOutputValue;
    DWORD dwInfoValue = 0;

    // Verify the storage handle
    hs = TCascStorage::IsValid(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Differentiate between info classes
    switch(InfoClass)
    {
        case CascStorageLocalFileCount:
            dwInfoValue = (DWORD)hs->LocalFiles;
            break;

        case CascStorageTotalFileCount:
            if(hs->TotalFiles == 0)
                hs->TotalFiles = GetStorageTotalFileCount(hs);
            dwInfoValue = (DWORD)hs->TotalFiles;
            break;

        case CascStorageFeatures:
            dwInfoValue = hs->dwFeatures | hs->pRootHandler->GetFeatures();
            break;

        case CascStorageInstalledLocales:
            dwInfoValue = hs->dwDefaultLocale;
            break;

        case CascStorageProduct:
            return GetStorageProduct(hs, pvStorageInfo, cbStorageInfo, pcbLengthNeeded);

        case CascStorageTags:
            return GetStorageTags(hs, pvStorageInfo, cbStorageInfo, pcbLengthNeeded);

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
    }

    //
    // Default: return a 32-bit unsigned value
    //

    PtrOutputValue = (PDWORD)ProbeOutputBuffer(pvStorageInfo, cbStorageInfo, sizeof(DWORD), pcbLengthNeeded);
    if(PtrOutputValue != NULL)
        PtrOutputValue[0] = dwInfoValue;
    return (PtrOutputValue != NULL);
}

bool WINAPI CascCloseStorage(HANDLE hStorage)
{
    TCascStorage * hs;

    // Verify the storage handle
    hs = TCascStorage::IsValid(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Only free the storage if the reference count reaches 0
    hs->Release();
    return true;
}
