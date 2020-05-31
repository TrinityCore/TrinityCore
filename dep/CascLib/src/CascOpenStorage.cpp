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

#ifdef INTERLOCKED_NOT_SUPPORTED
#pragma error Interlocked operations are not supported on this architecture. Multi-threaded access to CASC storages will not work properly.
#endif

//-----------------------------------------------------------------------------
// Local defines

// Limit for "additional" items in CKey table
#define CASC_MAX_EXTRA_ITEMS 0x40

//-----------------------------------------------------------------------------
// DEBUG functions

#define CHECKED_KEY {0x00, 0x00, 0x0F, 0x84}

#if defined(_DEBUG) && defined(CHECKED_KEY)

inline bool CheckForXKey(LPBYTE XKey)
{
    BYTE CheckedKey[] = CHECKED_KEY;

    for(size_t i = 0; i < _countof(CheckedKey); i++)
    {
        if(XKey[i] != CheckedKey[i])
            return false;
    }

    return true;
}
#define BREAK_ON_WATCHED(XKey)  if(CheckForXKey((LPBYTE)XKey))  { __debugbreak(); }

#else

#define BREAK_ON_WATCHED(XKey)  { /* NOTHING */ }

#endif

//-----------------------------------------------------------------------------
// TCascStorage class functions

TCascStorage::TCascStorage()
{
    // Prepare the base storage parameters
    ClassName = CASC_MAGIC_STORAGE;
    pRootHandler = NULL;
    dwRefCount = 1;

    szRootPath = szDataPath = szIndexPath = szBuildFile = szCdnServers = szCdnPath = szCodeName = NULL;
    szIndexFormat = NULL;
    szRegion = NULL;
    szBuildKey = NULL;

    memset(DataFiles, 0, sizeof(DataFiles));
    memset(IndexFiles, 0, sizeof(IndexFiles));
    CascInitLock(StorageLock);
    dwDefaultLocale = 0;
    dwBuildNumber = 0;
    dwFeatures = 0;
    BuildFileType = CascBuildNone;

    LastFailKeyName = 0;
    LocalFiles = TotalFiles = EKeyEntries = EKeyLength = FileOffsetBits = 0;
    pArgs = NULL;
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

    // Cleanup space occupied by index files
    FreeIndexFiles(this);

    // Cleanup the lock
    CascFreeLock(StorageLock);

    // Free the file paths
    CASC_FREE(szDataPath);
    CASC_FREE(szRootPath);
    CASC_FREE(szBuildFile);
    CASC_FREE(szIndexPath);
    CASC_FREE(szCdnServers);
    CASC_FREE(szCdnPath);
    CASC_FREE(szCodeName);
    CASC_FREE(szRegion);
    CASC_FREE(szBuildKey);

    // Free the blobs
    FreeCascBlob(&CdnConfigKey);
    FreeCascBlob(&CdnBuildKey);
    
    FreeCascBlob(&ArchiveGroup);
    FreeCascBlob(&ArchivesKey);
    FreeCascBlob(&PatchArchivesKey);
    FreeCascBlob(&PatchArchivesGroup);
    FreeCascBlob(&BuildFiles);
    ClassName = 0;
}

TCascStorage * TCascStorage::AddRef()
{
    // Need this to be atomic to make multi-threaded file opens work
    CascInterlockedIncrement(&dwRefCount);
    return this;
}

TCascStorage * TCascStorage::Release()
{
    // If the reference count reached zero, we close the archive
    // Need this to be atomic to make multi-threaded file opens work
    if(CascInterlockedDecrement(&dwRefCount) == 0)
    {
        delete this;
        return NULL;
    }

    return this;
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

static LPTSTR CheckForIndexDirectory(TCascStorage * hs, LPCTSTR szSubDir)
{
    LPTSTR szIndexPath;

    // Combine the index path
    szIndexPath = CombinePath(hs->szDataPath, szSubDir);
    if (!DirectoryExists(szIndexPath))
    {
        CASC_FREE(szIndexPath);
    }

    return szIndexPath;
}

// Inserts an entry from the text build file
static PCASC_CKEY_ENTRY InsertCKeyEntry(TCascStorage * hs, CASC_CKEY_ENTRY & CKeyEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;

    // Stop on file-of-interest
    BREAK_ON_WATCHED(CKeyEntry.EKey);

    // Skip entries without any key
    if(CKeyEntry.Flags & (CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY))
    {
        // Check if there is an existing entry
        if((pCKeyEntry = FindCKeyEntry_CKey(hs, CKeyEntry.CKey)) == NULL)
        {
            // Insert a new entry to the array. DO NOT ALLOW enlarge array here
            pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1, false);
            if(pCKeyEntry == NULL)
                return NULL;

            // Fill in the item
            memcpy(pCKeyEntry, &CKeyEntry, sizeof(CASC_CKEY_ENTRY));

            // If we have CKey present, insert it to the CKey map
            if(CKeyEntry.Flags & CASC_CE_HAS_CKEY)
                hs->CKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->CKey);

            // If we have EKey present, insert it to the EKey map
            if(CKeyEntry.Flags & CASC_CE_HAS_EKEY)
                hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
        }
        else
        {
            if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
                pCKeyEntry->ContentSize = CKeyEntry.ContentSize;
            if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
                pCKeyEntry->EncodedSize = CKeyEntry.EncodedSize;
        }
    }

    return pCKeyEntry;
}

// Inserts an entry from ENCODING
static PCASC_CKEY_ENTRY InsertCKeyEntry(TCascStorage * hs, PFILE_CKEY_ENTRY pFileEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry;

    // Stop on file-of-interest
    BREAK_ON_WATCHED(pFileEntry->EKey);

    // Insert a new entry to the array. DO NOT ALLOW enlarge array here
    pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1, false);
    if(pCKeyEntry != NULL)
    {
        // Initialize the entry
        CopyMemory16(pCKeyEntry->CKey, pFileEntry->CKey);
        CopyMemory16(pCKeyEntry->EKey, pFileEntry->EKey);
        pCKeyEntry->StorageOffset = CASC_INVALID_OFFS64;
        pCKeyEntry->TagBitMask = 0;
        pCKeyEntry->ContentSize = ConvertBytesToInteger_4(pFileEntry->ContentSize);
        pCKeyEntry->EncodedSize = CASC_INVALID_SIZE;
        pCKeyEntry->Flags = CASC_CE_HAS_CKEY | CASC_CE_HAS_EKEY | CASC_CE_IN_ENCODING;
        pCKeyEntry->RefCount = 0;
        pCKeyEntry->SpanCount = 1;
        pCKeyEntry->Priority = 0;

        // Copy the information from index files to the CKey entry
        CopyEKeyEntry(hs, pCKeyEntry);

        // Insert the item into both maps
        hs->CKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->CKey);
        hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
    }
    else
    {
        assert(false);
    }

    return pCKeyEntry;
}

// Inserts an entry from DOWNLOAD
static PCASC_CKEY_ENTRY InsertCKeyEntry(TCascStorage * hs, CASC_DOWNLOAD_ENTRY & DlEntry)
{
    PCASC_CKEY_ENTRY pCKeyEntry;

    // Stop on file-of-interest
    BREAK_ON_WATCHED(DlEntry.EKey);

    // Check whether the entry is already there
    if((pCKeyEntry = FindCKeyEntry_EKey(hs, DlEntry.EKey)) == NULL)
    {
        // Insert dummy CKey entry to the array. DO NOT allow to enlarge the array
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.Insert(1, false);
        if(pCKeyEntry == NULL)
        {
            assert(false);
            return NULL;
        }

        // Copy the entry
        ZeroMemory16(pCKeyEntry->CKey);
        CopyMemory16(pCKeyEntry->EKey, DlEntry.EKey);
        pCKeyEntry->StorageOffset = CASC_INVALID_OFFS64;
        pCKeyEntry->TagBitMask = 0;
        pCKeyEntry->ContentSize = CASC_INVALID_SIZE;
        pCKeyEntry->EncodedSize = (DWORD)DlEntry.EncodedSize;
        pCKeyEntry->Flags = CASC_CE_HAS_EKEY | CASC_CE_IN_DOWNLOAD;
        pCKeyEntry->RefCount = 0;
        pCKeyEntry->SpanCount = 1;

        // Copy the information from index files to the CKey entry
        CopyEKeyEntry(hs, pCKeyEntry);

        // Insert the entry to the map. Only insert it to the EKey map, as there is no CKey present
        hs->EKeyMap.InsertObject(pCKeyEntry, pCKeyEntry->EKey);
    }
    else
    {
        // Copy the EKey if we only have partial one
        if(pCKeyEntry->Flags & CASC_CE_HAS_EKEY_PARTIAL)
            CopyMemory16(pCKeyEntry->EKey, DlEntry.EKey);

        // Supply the encoded size, if unknown yet
        if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
            pCKeyEntry->EncodedSize = (DWORD)DlEntry.EncodedSize;
        pCKeyEntry->Flags = (pCKeyEntry->Flags & ~CASC_CE_HAS_EKEY_PARTIAL) | CASC_CE_IN_DOWNLOAD;
    }

    // Supply the rest
    pCKeyEntry->Priority = DlEntry.Priority;
    return pCKeyEntry;
}

static DWORD CopyBuildFileItemsToCKeyArray(TCascStorage * hs)
{
    // Insert the well-known files
//  InsertCKeyEntry(hs, hs->EncodingCKey);
    InsertCKeyEntry(hs, hs->DownloadCKey);
    InsertCKeyEntry(hs, hs->InstallCKey);
    InsertCKeyEntry(hs, hs->PatchFile);
    InsertCKeyEntry(hs, hs->RootFile);
    InsertCKeyEntry(hs, hs->SizeFile);
    InsertCKeyEntry(hs, hs->VfsRoot);

    // Insert all VFS roots
    for(size_t i = 0; i < hs->VfsRootList.ItemCount(); i++)
    {
        PCASC_CKEY_ENTRY pCKeyEntry = (PCASC_CKEY_ENTRY)hs->VfsRootList.ItemAt(i);
        InsertCKeyEntry(hs, *pCKeyEntry);
    }

    return ERROR_SUCCESS;
}

// Estimate the total number of files, so we won't have to re-allocate arrays and maps
// and thus speed-up storage loading. In theory, we could guess the file count by
// measuring size of ENCODING or DOWNLOAD manifests.
static size_t GetEstimatedNumberOfFiles(TCascStorage * hs)
{
    size_t nNumberOfFiles1 = 0;
    size_t nNumberOfFiles2 = 0;

    // If we know the size of DOWNLOAD at this point, we estimate number of files from it.
    // Size of one entry in DOWNLOAD is at least 22 bytes. This is the most reliable method.
    // However, for some online storages ("agent"), this is a very small value
    if(hs->DownloadCKey.ContentSize != CASC_INVALID_SIZE)
        nNumberOfFiles1 = (hs->DownloadCKey.ContentSize / sizeof(FILE_DOWNLOAD_ENTRY)) + CASC_MAX_EXTRA_ITEMS;

    // If we know the size of ENCODING at this point, we estimate number of files from it.
    // Size of one entry in ENCODING is at least 38 bytes. This method fails on storages
    // with TVFS file system, as ENCODING only contains a small subset of file.
    // Fortunately, all known TVFS-based storages have "download-size" present
    if(hs->EncodingCKey.ContentSize != CASC_INVALID_SIZE)
        nNumberOfFiles2 = (hs->EncodingCKey.ContentSize / sizeof(FILE_CKEY_ENTRY)) + CASC_MAX_EXTRA_ITEMS;

    // Do we know any of them?
    if(nNumberOfFiles1 || nNumberOfFiles2)
        return CASCLIB_MAX(nNumberOfFiles1, nNumberOfFiles2);

    // Older storages (HOTS before 39445, WoW before 19116) don't state sizes of ENCODING
    // and DOWNLOAD in the Build Config files. Solution: Assume there is max 1M of files
    return 1000000;
}

static DWORD InitCKeyArray(TCascStorage * hs)
{
    size_t nNumberOfFiles = GetEstimatedNumberOfFiles(hs);
    DWORD dwErrCode;

    //
    // Allocate array and map of CKey entries
    //

    // Create the array of CKey items
    dwErrCode = hs->CKeyArray.Create(sizeof(CASC_CKEY_ENTRY), nNumberOfFiles);
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Create the map CKey -> CASC_CKEY_ENTRY
    dwErrCode = hs->CKeyMap.Create(nNumberOfFiles, MD5_HASH_SIZE, FIELD_OFFSET(CASC_CKEY_ENTRY, CKey));
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

    // Create the map CKey -> CASC_CKEY_ENTRY. Note that TVFS root references files
    // using 9-byte EKey, so cut the search EKey length to 9 bytes
    dwErrCode = hs->EKeyMap.Create(nNumberOfFiles, CASC_EKEY_SIZE, FIELD_OFFSET(CASC_CKEY_ENTRY, EKey));
    if(dwErrCode != ERROR_SUCCESS)
        return dwErrCode;

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
//      BREAK_ON_XKEY3(pFileEntry->CKey, 0x34, 0x82, 0x1f);

        // Insert the entry to the central CKey table
        InsertCKeyEntry(hs, pFileEntry);

        // Move to the next encoding entry
        pbFileEntry = pbFileEntry + 2 + 4 + EnHeader.CKeyLength + (pFileEntry->EKeyCount * EnHeader.EKeyLength);
    }
    return ERROR_SUCCESS;
}

static int LoadEncodingManifest(TCascStorage * hs)
{
    CASC_CKEY_ENTRY & CKeyEntry = hs->EncodingCKey;
    LPBYTE pbEncodingFile;
    DWORD cbEncodingFile = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading ENCODING manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Fill-in the information from the index entry and insert it to the file tree
    if(!CopyEKeyEntry(hs, &CKeyEntry))
        return ERROR_FILE_NOT_FOUND;
    InsertCKeyEntry(hs, CKeyEntry);

    // Load the entire encoding file to memory
    pbEncodingFile = LoadInternalFileToMemory(hs, &hs->EncodingCKey, &cbEncodingFile);
    if(pbEncodingFile != NULL && cbEncodingFile != 0)
    {
        CASC_ENCODING_HEADER EnHeader;

        // Capture the header of the ENCODING file
        dwErrCode = CaptureEncodingHeader(EnHeader, pbEncodingFile, cbEncodingFile);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Get the CKey page header and the first page
            PFILE_CKEY_PAGE pPageHeader = (PFILE_CKEY_PAGE)(pbEncodingFile + sizeof(FILE_ENCODING_HEADER) + EnHeader.ESpecBlockSize);
            LPBYTE pbCKeyPage = (LPBYTE)(pPageHeader + EnHeader.CKeyPageCount);

            // Go through all CKey pages and verify them
            for(DWORD i = 0; i < EnHeader.CKeyPageCount; i++)
            {
                // Check if there is enough space in the buffer
                if((pbCKeyPage + EnHeader.CKeyPageSize) > (pbEncodingFile + cbEncodingFile))
                {
                    dwErrCode = ERROR_FILE_CORRUPT;
                    break;
                }

                // Check the hash of the entire segment
                // Note that verifying takes considerable time of the storage loading
//              if(!VerifyDataBlockHash(pbCKeyPage, EnHeader.CKeyPageSize, pEncodingSegment->SegmentHash))
//              {
//                  dwErrCode = ERROR_FILE_CORRUPT;
//                  break;
//              }

                // Check if the CKey matches with the expected first value
                if(memcmp(((PFILE_CKEY_ENTRY)pbCKeyPage)->CKey, pPageHeader[i].FirstKey, MD5_HASH_SIZE))
                {
                    dwErrCode = ERROR_FILE_CORRUPT;
                    break;
                }

                // Load the entire page of CKey entries.
                // This operation will never fail, because all memory is already pre-allocated
                dwErrCode = LoadEncodingCKeyPage(hs, EnHeader, pbCKeyPage, pbCKeyPage + EnHeader.CKeyPageSize);
                if(dwErrCode != ERROR_SUCCESS)
                    break;

                // Move to the next CKey page
                pbCKeyPage += EnHeader.CKeyPageSize;
            }
        }

        // All CKey->EKey entries from the text build files need to be copied to the CKey array
        if(dwErrCode == ERROR_SUCCESS)
        {
            dwErrCode = CopyBuildFileItemsToCKeyArray(hs);
        }

        // Free the loaded ENCODING file
        CASC_FREE(pbEncodingFile);
    }
    else
    {
        dwErrCode = GetLastError();
    }

    return dwErrCode;
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
    DWORD dwErrCode = ERROR_SUCCESS;

    // Does the storage support tags?
    if(DlHeader.TagCount != 0)
    {
        // Remember that we support tags
        hs->dwFeatures |= CASC_FEATURE_TAGS;

        // Allocate space for the tag array
        TagArray = CASC_ALLOC<CASC_TAG_ENTRY1>(DlHeader.TagCount);
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
            dwErrCode = hs->TagsArray.Create(nTagEntryLengh, DlHeader.TagCount);
            if(dwErrCode == ERROR_SUCCESS)
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
                        dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
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
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Now parse all entries. For each entry, mark the corresponding tag bit in the EKey table
    for(DWORD i = 0; i < DlHeader.EntryCount; i++)
    {
        CASC_DOWNLOAD_ENTRY DlEntry;
        PCASC_CKEY_ENTRY pCKeyEntry;
        ULONGLONG TagBit = 1;
        size_t BitMaskOffset = (i / 8);
        size_t TagItemCount = hs->TagsArray.ItemCount();
        BYTE BitMaskBit = 0x80 >> (i % 8);

        // Capture the download entry
        if(CaptureDownloadEntry(DlHeader, DlEntry, pbEntry, pbFileEnd) != ERROR_SUCCESS)
            break;

        // COD4: zone/base.xpak
        //BREAK_ON_XKEY3(DlEntry.EKey, 0xa5, 0x00, 0x16);

        // Insert the entry to the central CKey table
        if((pCKeyEntry = InsertCKeyEntry(hs, DlEntry)) != NULL)
        {
            // Supply the tag bits
            for(size_t j = 0; j < TagItemCount; j++)
            {
                // Set the bit in the entry, if the tag for it is present
                if((BitMaskOffset < TagArray[j].BitmapLength) && (TagArray[j].Bitmap[BitMaskOffset] & BitMaskBit))
                    pCKeyEntry->TagBitMask |= TagBit;

                // Move to the next bit
                TagBit <<= 1;
            }
        }

        // Move to the next entry
        pbEntry += DlHeader.EntryLength;
    }

    // Free the tag array, if any
    CASC_FREE(TagArray);

    // Remember the total file count
    hs->TotalFiles = hs->CKeyArray.ItemCount();
    return dwErrCode;
}

static int LoadDownloadManifest(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pCKeyEntry = FindCKeyEntry_CKey(hs, hs->DownloadCKey.CKey);
    LPBYTE pbDownloadFile = NULL;
    DWORD cbDownloadFile = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading DOWNLOAD manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire DOWNLOAD file to memory
    pbDownloadFile = LoadInternalFileToMemory(hs, pCKeyEntry, &cbDownloadFile);
    if(pbDownloadFile != NULL && cbDownloadFile != 0)
    {
        CASC_DOWNLOAD_HEADER DlHeader;

        // Capture the header of the DOWNLOAD file
        dwErrCode = CaptureDownloadHeader(DlHeader, pbDownloadFile, cbDownloadFile);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Parse the entire download manifest
            dwErrCode = LoadDownloadManifest(hs, DlHeader, pbDownloadFile, pbDownloadFile + cbDownloadFile); 
        }

        // Free the loaded manifest
        CASC_FREE(pbDownloadFile);
    }

    // If the DOWNLOAD manifest is not present, we won't abort the downloading process.
    return dwErrCode;
}

//-----------------------------------------------------------------------------
// INSTALL manifest. This is a replacement for ROOT, if loading ROOT fails
// https://wowdev.wiki/TACT#Install_manifest

static int LoadInstallManifest(TCascStorage * hs)
{
    PCASC_CKEY_ENTRY pCKeyEntry = FindCKeyEntry_CKey(hs, hs->InstallCKey.CKey);
    LPBYTE pbInstallFile = NULL;
    DWORD cbInstallFile = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading INSTALL manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Load the entire DOWNLOAD file to memory
    pbInstallFile = LoadInternalFileToMemory(hs, pCKeyEntry, &cbInstallFile);
    if (pbInstallFile != NULL && cbInstallFile != 0)
    {
        dwErrCode = RootHandler_CreateInstall(hs, pbInstallFile, cbInstallFile);
        CASC_FREE(pbInstallFile);
    }
    else
    {
        dwErrCode = GetLastError();
    }

    return dwErrCode;
}

static bool InsertWellKnownFile(TCascStorage * hs, const char * szFileName, CASC_CKEY_ENTRY & FakeCKeyEntry, DWORD dwFlags = 0)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;

    // We need to find the CKey entry in the central array
    if(FakeCKeyEntry.Flags & CASC_CE_HAS_CKEY)
    {
        // Did we find anything?
        pCKeyEntry = FindCKeyEntry_CKey(hs, FakeCKeyEntry.CKey);
        if(pCKeyEntry != NULL)
        {
            // Insert the key to the root handler. Note that the file can already be referenced
            // ("index" vs "vfs-root" in Warcraft III storages)
            hs->pRootHandler->Insert(szFileName, pCKeyEntry);

            // Copy some flags
            pCKeyEntry->Flags |= (dwFlags | CASC_CE_IN_BUILD);
            return true;
        }
    }

    // Special case: the PATCH file is usually not in any indices.
    // It's also never locally available
    if((dwFlags & CASC_CE_FILE_PATCH) && (hs->dwFeatures & CASC_FEATURE_ONLINE))
    {
        // Get or insert the PATCH entry
        pCKeyEntry = InsertCKeyEntry(hs, FakeCKeyEntry);
        if(pCKeyEntry != NULL)
        {
            hs->pRootHandler->Insert(szFileName, pCKeyEntry);
            pCKeyEntry->Flags |= (dwFlags | CASC_CE_IN_BUILD);
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
    DWORD dwErrCode = ERROR_BAD_FORMAT;

    // Sanity checks
    assert(hs->CKeyMap.IsInitialized() == true);
    assert(hs->pRootHandler == NULL);

    // Inform the user about what we are doing
    if(InvokeProgressCallback(hs, "Loading ROOT manifest", NULL, 0, 0))
        return ERROR_CANCELLED;

    // Locale: The default parameter is 0 - in that case, we load all locales
    dwLocaleMask = (dwLocaleMask != 0) ? dwLocaleMask : 0xFFFFFFFF;

    // Prioritize the VFS root over legacy ROOT file
    pCKeyEntry = (hs->VfsRoot.ContentSize != CASC_INVALID_SIZE) ? &hs->VfsRoot : &hs->RootFile;
    pCKeyEntry = FindCKeyEntry_CKey(hs, pCKeyEntry->CKey);

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
                    dwErrCode = RootHandler_CreateMNDX(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_DIABLO3_ROOT_SIGNATURE:
                    dwErrCode = RootHandler_CreateDiablo3(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_TVFS_ROOT_SIGNATURE:
                    dwErrCode = RootHandler_CreateTVFS(hs, pbRootFile, cbRootFile);
                    break;

                case CASC_WOW82_ROOT_SIGNATURE:
                    dwErrCode = RootHandler_CreateWoW(hs, pbRootFile, cbRootFile, dwLocaleMask);
                    break;

                default:

                    //
                    // Each of these handler creators must verify their format first.
                    // If the format was not recognized, they need to return ERROR_BAD_FORMAT
                    //

                    dwErrCode = RootHandler_CreateOverwatch(hs, pbRootFile, cbRootFile);
                    if(dwErrCode == ERROR_BAD_FORMAT)
                    {
                        dwErrCode = RootHandler_CreateStarcraft1(hs, pbRootFile, cbRootFile);
                        if(dwErrCode == ERROR_BAD_FORMAT)
                        {
                            dwErrCode = RootHandler_CreateWoW(hs, pbRootFile, cbRootFile, dwLocaleMask);
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
        dwErrCode = GetLastError();
    }

    return dwErrCode;
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
            if(pCKeyEntry->IsFile())
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
        // Clear the entire structure
        memset(pProductInfo, 0, sizeof(CASC_STORAGE_PRODUCT));

        // Copy the product code name and build number
        if(hs->szCodeName != NULL)
            CascStrCopy(pProductInfo->szCodeName, _countof(pProductInfo->szCodeName), hs->szCodeName);
        pProductInfo->BuildNumber = hs->dwBuildNumber;
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

static bool GetStoragePathProduct(TCascStorage * hs, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded)
{
    LPTSTR szBuffer = (LPTSTR)pvStorageInfo;
    size_t nMaxChars = cbStorageInfo / sizeof(TCHAR);
    size_t nLength;

    // Calculate the length needed
    nLength = _tcslen(hs->szRootPath);
    if(hs->szCodeName != NULL)
        nLength = nLength + 1 + _tcslen(hs->szCodeName);
    if(hs->szRegion != NULL)
        nLength = nLength + 1 + strlen(hs->szRegion);
    nLength++;

    // Verify whether we have enough space in the buffer
    szBuffer = (LPTSTR)ProbeOutputBuffer(pvStorageInfo, cbStorageInfo, (nLength * sizeof(TCHAR)), pcbLengthNeeded);
    if(szBuffer != NULL)
    {
        LPTSTR szBufferEnd = szBuffer + nMaxChars;

        // Copy the storage path
        CascStrCopy(szBuffer, (szBufferEnd - szBuffer), hs->szRootPath);
        szBuffer += _tcslen(hs->szRootPath);

        // Append the product code name, if any
        if(hs->szCodeName != NULL)
        {
            *szBuffer++ = _T(':');
            CascStrCopy(szBuffer, (szBufferEnd - szBuffer), hs->szCodeName);
            szBuffer += _tcslen(hs->szCodeName);
        }

        // Append the product region, if any
        if(hs->szRegion != NULL)
        {
            *szBuffer++ = _T(':');
            CascStrCopy(szBuffer, (szBufferEnd - szBuffer), hs->szRegion);
        }
    }

    return (szBuffer != NULL);
}

static DWORD InitializeLocalDirectories(TCascStorage * hs, PCASC_OPEN_STORAGE_ARGS pArgs)
{
    LPTSTR szWorkPath;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Find the root directory of the storage. The root directory
    // is the one with ".build.info" or ".build.db".
    szWorkPath = CascNewStr(pArgs->szLocalPath);
    if(szWorkPath != NULL)
    {
        // Get the length and go up until we find the ".build.info" or ".build.db"
        for(;;)
        {
            // Is this a game directory?
            dwErrCode = CheckGameDirectory(hs, szWorkPath);
            if(dwErrCode == ERROR_SUCCESS)
            {
                dwErrCode = ERROR_SUCCESS;
                break;
            }

            // Cut one path part
            if(!CutLastPathPart(szWorkPath))
            {
                dwErrCode = ERROR_FILE_NOT_FOUND;
                break;
            }
        }

        // Find the index directory
        if (dwErrCode == ERROR_SUCCESS)
        {
            // First, check for more common "data" subdirectory
            if ((hs->szIndexPath = CheckForIndexDirectory(hs, _T("data"))) != NULL)
                dwErrCode = ERROR_SUCCESS;

            // Second, try the "darch" subdirectory (older builds of HOTS - Alpha)
            else if ((hs->szIndexPath = CheckForIndexDirectory(hs, _T("darch"))) != NULL)
                dwErrCode = ERROR_SUCCESS;

            else
                dwErrCode = ERROR_FILE_NOT_FOUND;
        }

        // Free the work path buffer
        CASC_FREE(szWorkPath);
    }

    return dwErrCode;
}

static DWORD InitializeOnlineDirectories(TCascStorage * hs, PCASC_OPEN_STORAGE_ARGS pArgs)
{
    // Create the root path
    hs->szRootPath = CascNewStr(pArgs->szLocalPath);
    if (hs->szRootPath != NULL)
    {
        hs->BuildFileType = CascVersionsDb;
        hs->dwFeatures |= CASC_FEATURE_ONLINE;
        return ERROR_SUCCESS;
    }

    return ERROR_NOT_ENOUGH_MEMORY;
}

static DWORD LoadCascStorage(TCascStorage * hs, PCASC_OPEN_STORAGE_ARGS pArgs)
{
    LPCTSTR szCodeName = NULL;
    LPCTSTR szRegion = NULL;
    LPCTSTR szBuildKey = NULL;
    DWORD dwLocaleMask = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Pass the argument array to the storage
    hs->pArgs = pArgs;

    // Extract optional arguments
    ExtractVersionedArgument(pArgs, FIELD_OFFSET(CASC_OPEN_STORAGE_ARGS, dwLocaleMask), &dwLocaleMask);
    
    // Extract the product code name
    if(ExtractVersionedArgument(pArgs, FIELD_OFFSET(CASC_OPEN_STORAGE_ARGS, szCodeName), &szCodeName) && szCodeName != NULL)
        hs->szCodeName = CascNewStr(szCodeName);

    // Extract the region (optional)
    if(ExtractVersionedArgument(pArgs, FIELD_OFFSET(CASC_OPEN_STORAGE_ARGS, szRegion), &szRegion) && szRegion != NULL)
        hs->szRegion = CascNewStrT2A(szRegion);

    // Extract the build key (optional)
    if(ExtractVersionedArgument(pArgs, FIELD_OFFSET(CASC_OPEN_STORAGE_ARGS, szBuildKey), &szBuildKey) && szBuildKey != NULL)
        hs->szBuildKey = CascNewStrT2A(szBuildKey);

    // For online storages, we need to load CDN servers
    if ((dwErrCode == ERROR_SUCCESS) && (hs->dwFeatures & CASC_FEATURE_ONLINE))
    {
        dwErrCode = LoadCdnsFile(hs);
    }

    // Now, load the main storage file ".build.info" (or ".build.db" in old storages) 
    if(dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadBuildInfo(hs);
    }

    // If the .build.info OR .build.db file has been loaded,
    // proceed with loading the CDN config file
    if (dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadCdnConfigFile(hs);
        if(dwErrCode != ERROR_SUCCESS && (hs->dwFeatures & CASC_FEATURE_ONLINE) == 0)
            dwErrCode = ERROR_SUCCESS;
    }

    // Proceed with loading the CDN build file
    if (dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadCdnBuildFile(hs);
    }

    // Create the array of CKey entries. Each entry represents a file in the storage
    if(dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = InitCKeyArray(hs);
    }

    // Pre-load the local index files
    if(dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadIndexFiles(hs);
    }

    // Load the ENCODING manifest
    if(dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadEncodingManifest(hs);
    }

    // We need to load the DOWNLOAD manifest
    if(dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = LoadDownloadManifest(hs);
    }

    // Load the build manifest ("ROOT" file)
    if(dwErrCode == ERROR_SUCCESS)
    {
        // For WoW storages, multiple files are present in the storage (same name, same file data ID, different locale).
        // Failing to select storage on them will lead to the first-in-order file in the list being loaded.
        // Example: WoW build 32144, file: DBFilesClient\Achievement.db2, file data ID: 1260179
        // Locales: koKR frFR deDE zhCN esES zhTW enUS&enGB esMX ruRU itIT ptBT&ptPT (in order of appearance in the build manifest)
        if(dwLocaleMask == 0)
        {
            dwLocaleMask = hs->dwDefaultLocale;
        }

        // Continue loading the manifest
        dwErrCode = LoadBuildManifest(hs, dwLocaleMask);
        if (dwErrCode != ERROR_SUCCESS)
        {
            // If we fail to load the ROOT file, we take the file names from the INSTALL manifest
            dwErrCode = LoadInstallManifest(hs);
        }
    }

    // Insert entries for files with well-known names. Their CKeys are in the BUILD file
    // See https://wowdev.wiki/TACT#Encoding_table for their list
    if (dwErrCode == ERROR_SUCCESS)
    {
        InsertWellKnownFile(hs, "ENCODING", hs->EncodingCKey);
        InsertWellKnownFile(hs, "DOWNLOAD", hs->DownloadCKey);
        InsertWellKnownFile(hs, "INSTALL", hs->InstallCKey);
        InsertWellKnownFile(hs, "PATCH", hs->PatchFile, CASC_CE_FILE_PATCH);
        InsertWellKnownFile(hs, "ROOT", hs->RootFile);
        InsertWellKnownFile(hs, "SIZE", hs->SizeFile);

        // Also reset the total file count. CascGetStorageInfo will update it on next call
        hs->TotalFiles = 0;
    }

    // Load the encryption keys
    if (dwErrCode == ERROR_SUCCESS)
    {
        dwErrCode = CascLoadEncryptionKeys(hs);
    }

    // Cleanup and exit
    FreeIndexFiles(hs);
    hs->pArgs = NULL;
    return dwErrCode;
}

static LPTSTR ParseOpenParams(LPCTSTR szParams, PCASC_OPEN_STORAGE_ARGS pArgs)
{
    LPTSTR szParamsCopy;

    // The 'szParams' must not be empty
    if(szParams == NULL || pArgs == NULL || szParams[0] == 0)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return NULL;
    }

    // The 'pArgs' must be valid but must not contain 'szLocalPath', 'szCodeName' or 'szRegion'
    if(pArgs->szLocalPath != NULL || pArgs->szCodeName != NULL || pArgs->szRegion != NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return NULL;
    }

    // Make a copy of the parameters so we can temper with them
    if((szParamsCopy = CascNewStr(szParams)) != NULL)
    {
        LPTSTR szPlainName = (LPTSTR)GetPlainFileName(szParamsCopy);
        LPTSTR szSeparator;

        // The local path is always set
        pArgs->szLocalPath = szParamsCopy;
        pArgs->szCodeName = NULL;
        pArgs->szRegion = NULL;
        pArgs->szBuildKey = NULL;

        // Find the first ":". This will indicate the end of local path and also begin of product code
        if((szSeparator = _tcschr(szPlainName, _T(':'))) != NULL)
        {
            // The found string is a product code name
            pArgs->szCodeName = szSeparator + 1;
            szSeparator[0] = 0;

            // Try again. If found, it is a product region
            if((szSeparator = _tcschr(szSeparator + 1, _T(':'))) != NULL)
            {
                pArgs->szRegion = szSeparator + 1;
                szSeparator[0] = 0;

                // Try again. If found, it is a build key (MD5 of a build file)
                if((szSeparator = _tcschr(szSeparator + 1, _T(':'))) != NULL)
                {
                    pArgs->szBuildKey = szSeparator + 1;
                    szSeparator[0] = 0;
                }
            }
        }
    }
    else
    {
        SetLastError(ERROR_NOT_ENOUGH_MEMORY);
    }

    return szParamsCopy;
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascOpenStorageEx(LPCTSTR szParams, PCASC_OPEN_STORAGE_ARGS pArgs, bool bOnlineStorage, HANDLE * phStorage)
{
    CASC_OPEN_STORAGE_ARGS LocalArgs = {sizeof(CASC_OPEN_STORAGE_ARGS)};
    TCascStorage * hs;
    LPTSTR szParamsCopy = NULL;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // The storage path[+product[+region]] must either be passed in szParams or in pArgs. Not both.
    // It is allowed to pass NULL as pArgs if the szParams is not NULL
    if(szParams != NULL)
    {
        if(pArgs == NULL)
            pArgs = &LocalArgs;

        szParamsCopy = ParseOpenParams(szParams, pArgs);
        if(szParamsCopy == NULL)
            return false;
    }
    else
    {
        // The arguments and the local path must be entered
        if(pArgs == NULL || pArgs->szLocalPath == NULL || pArgs->szLocalPath[0] == 0)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
        }
    }

    // Allocate the storage structure
    if((hs = new TCascStorage()) != NULL)
    {
        // Setup the directories
        dwErrCode = (bOnlineStorage) ? InitializeOnlineDirectories(hs, pArgs) : InitializeLocalDirectories(hs, pArgs);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Perform the entire storage loading
            dwErrCode = LoadCascStorage(hs, pArgs);
        }

        // Free the storage structure on fail
        if(dwErrCode != ERROR_SUCCESS)
        {
            hs = hs->Release();
        }
    }

    // Give the output parameter to the caller
    CASC_FREE(szParamsCopy);
    *phStorage = (HANDLE)hs;

    // Return the result
    if(dwErrCode != ERROR_SUCCESS)
        SetLastError(dwErrCode);
    return (dwErrCode == ERROR_SUCCESS);
}

// szParams: "LocalPath:CodeName", e.g. "C:\\Games\\World of Warcraft:wowt"
// * LocalPath: Local folder, where the online file will be cached.
// * CodeName: Product code name, e.g. "agent" for Battle.net Agent. More info: https://wowdev.wiki/TACT#Products
bool WINAPI CascOpenStorage(LPCTSTR szParams, DWORD dwLocaleMask, HANDLE * phStorage)
{
    CASC_OPEN_STORAGE_ARGS OpenArgs = {sizeof(CASC_OPEN_STORAGE_ARGS)};

    OpenArgs.dwLocaleMask = dwLocaleMask;
    return CascOpenStorageEx(szParams, &OpenArgs, false, phStorage);
}

// Allows to browse an online CDN storage
// szParams: "CachePath:CodeName:Region", e.g. "C:\\Cache:wowt:us"
// * CachePath: Local folder, where the online file will be cached.
// * CodeName: Product code name, e.g. "agent" for Battle.net Agent. More info: https://wowdev.wiki/TACT#Products
// * Region: The region (or subvariant) of the product. Corresponds to the first column of the "versions" file.
bool WINAPI CascOpenOnlineStorage(LPCTSTR szParams, DWORD dwLocaleMask, HANDLE * phStorage)
{
    CASC_OPEN_STORAGE_ARGS OpenArgs = {sizeof(CASC_OPEN_STORAGE_ARGS)};

    OpenArgs.dwLocaleMask = dwLocaleMask;
    return CascOpenStorageEx(szParams, &OpenArgs, true, phStorage);
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

        case CascStoragePathProduct:
            return GetStoragePathProduct(hs, pvStorageInfo, cbStorageInfo, pcbLengthNeeded);

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
