/*****************************************************************************/
/* CascOpenFile.cpp                       Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* System-dependent directory functions for CascLib                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 01.05.14  1.00  Lad  The first version of CascOpenFile.cpp                */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"
#include "CascMndxRoot.h"

//-----------------------------------------------------------------------------
// Local structures

//-----------------------------------------------------------------------------
// Local functions

TCascFile * IsValidFileHandle(HANDLE hFile)
{
    TCascFile * hf = (TCascFile *)hFile;

    return (hf != NULL && hf->hs != NULL && hf->szClassName != NULL && !strcmp(hf->szClassName, "TCascFile")) ? hf : NULL;
}

PCASC_INDEX_ENTRY FindIndexEntry(TCascStorage * hs, PQUERY_KEY pIndexKey)
{
    PCASC_INDEX_ENTRY pIndexEntry = NULL;

    if(hs->pIndexEntryMap != NULL)
        pIndexEntry = (PCASC_INDEX_ENTRY)Map_FindObject(hs->pIndexEntryMap, pIndexKey->pbData);

    return pIndexEntry;
}

PCASC_ENCODING_ENTRY FindEncodingEntry(TCascStorage * hs, PQUERY_KEY pEncodingKey, size_t * PtrIndex)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    size_t StartEntry = 0;
    size_t MidlEntry;
    size_t EndEntry = hs->nEncodingEntries;
    int nResult;

    // Perform binary search
    while(StartEntry < EndEntry)
    {
        // Calculate the middle of the interval
        MidlEntry = StartEntry + ((EndEntry - StartEntry) / 2);
        pEncodingEntry = hs->ppEncodingEntries[MidlEntry];

        // Did we find it?
        nResult = memcmp(pEncodingKey->pbData, pEncodingEntry->EncodingKey, MD5_HASH_SIZE);
        if(nResult == 0)
        {
            if(PtrIndex != NULL)
                PtrIndex[0] = MidlEntry;
            return pEncodingEntry;
        }

        // Move the interval to the left or right
        (nResult < 0) ? EndEntry = MidlEntry : StartEntry = MidlEntry + 1;
    }

    // Not found, sorry
    return NULL;
}

// Also used in CascSearchFile
PCASC_ROOT_ENTRY FindRootEntry(TCascStorage * hs, const char * szFileName, DWORD * PtrTableIndex)
{
    PCASC_ROOT_ENTRY pRootEntry;
    ULONGLONG FileNameHash;
    DWORD TableIndex;
    uint32_t dwHashHigh = 0;
    uint32_t dwHashLow = 0;

    // Calculate the HASH value of the normalized file name
    hashlittle2(szFileName, strlen(szFileName), &dwHashHigh, &dwHashLow);
    FileNameHash = ((ULONGLONG)dwHashHigh << 0x20) | dwHashLow;

    // Get the first table index
    TableIndex = (DWORD)(FileNameHash & (hs->RootTable.TableSize - 1));
    assert(hs->RootTable.ItemCount < hs->RootTable.TableSize);

    // Search the proper entry
    for(;;)
    {
        // Does the has match?
        pRootEntry = hs->RootTable.TablePtr + TableIndex;
        if(pRootEntry->FileNameHash == FileNameHash)
        {
            if(PtrTableIndex != NULL)
                PtrTableIndex[0] = TableIndex;
            return pRootEntry;
        }

        // If the entry is free, the file is not there
        if(pRootEntry->FileNameHash == 0 && pRootEntry->SumValue == 0)
            return NULL;

        // Move to the next entry
        TableIndex = (DWORD)((TableIndex + 1) & (hs->RootTable.TableSize - 1));
    }
}

static TCascFile * CreateFileHandle(TCascStorage * hs, PCASC_INDEX_ENTRY pIndexEntry)
{
    ULONGLONG FileOffsMask = ((ULONGLONG)1 << hs->KeyMapping[0].SegmentBits) - 1;
    ULONGLONG FileOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffsetBE);
    TCascFile * hf;

    // Allocate the CASC file structure
    hf = (TCascFile *)CASC_ALLOC(TCascFile, 1);
    if(hf != NULL)
    {
        // Initialize the structure
        memset(hf, 0, sizeof(TCascFile));
        hf->ArchiveIndex = (DWORD)(FileOffset >> hs->KeyMapping[0].SegmentBits);
        hf->HeaderOffset = (DWORD)(FileOffset & FileOffsMask);
        hf->szClassName = "TCascFile";
        
        // Copy the file size. Note that for all files except ENCODING,
        // this is the compressed file size
        hf->CompressedSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);

        // For now, we set the file size to be equal to compressed size
        // This is used when loading the ENCODING file, which does not
        // have entry in the encoding table
        hf->FileSize = hf->CompressedSize;

        // Increment the number of references to the archive
        hs->dwRefCount++;
        hf->hs = hs;
    }

    return hf;
}

static bool OpenFileByIndexKey(TCascStorage * hs, PQUERY_KEY pIndexKey, DWORD dwFlags, TCascFile ** ppCascFile)
{
    PCASC_INDEX_ENTRY pIndexEntry;
    int nError = ERROR_SUCCESS;

    CASCLIB_UNUSED(dwFlags);

    // Find the key entry in the array of file keys
    pIndexEntry = FindIndexEntry(hs, pIndexKey);
    if(pIndexEntry == NULL)
        nError = ERROR_FILE_NOT_FOUND;

    // Create the file handle structure
    if(nError == ERROR_SUCCESS)
    {
        ppCascFile[0] = CreateFileHandle(hs, pIndexEntry);
        if(ppCascFile[0] == NULL)
            nError = ERROR_FILE_NOT_FOUND;
    }

#ifdef CASCLIB_TEST
    if(nError == ERROR_SUCCESS && ppCascFile[0] != NULL)
    {
        ppCascFile[0]->FileSize_IdxEntry = ConvertBytesToInteger_4_LE(pIndexEntry->FileSizeLE);
    }
#endif

    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

static bool OpenFileByEncodingKey(TCascStorage * hs, PQUERY_KEY pEncodingKey, DWORD dwFlags, TCascFile ** ppCascFile)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    QUERY_KEY IndexKey;

    // Find the encoding entry
    pEncodingEntry = FindEncodingEntry(hs, pEncodingKey, NULL);
    if(pEncodingEntry == NULL)
    {
        SetLastError(ERROR_FILE_NOT_FOUND);
        return false;
    }

    // Prepare the file index and open the file by index
    // Note: We don't know what to do if there is more than just one index key
    // We always take the first file present. Is that correct?
    IndexKey.pbData = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;
    IndexKey.cbData = MD5_HASH_SIZE;
    if(OpenFileByIndexKey(hs, &IndexKey, dwFlags, ppCascFile))
    {
        // Check if the file handle was created
        if(ppCascFile[0] != NULL)
        {
            // Fill-in the file size. For all files except ENCODING,
            // this overrides the value stored in the index entry.
            ppCascFile[0]->FileSize = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE);

#ifdef CASCLIB_TEST
            ppCascFile[0]->FileSize_EncEntry = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE);
#endif
            return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascOpenFileByIndexKey(HANDLE hStorage, PQUERY_KEY pIndexKey, DWORD dwFlags, HANDLE * phFile)
{
    TCascStorage * hs;

    // Validate the storage handle
    hs = IsValidStorageHandle(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Validate the other parameters
    if(pIndexKey == NULL || pIndexKey->pbData == NULL || pIndexKey->cbData == 0 || phFile == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Use the internal function to open the file
    return OpenFileByIndexKey(hs, pIndexKey, dwFlags, (TCascFile **)phFile);
}

bool WINAPI CascOpenFileByEncodingKey(HANDLE hStorage, PQUERY_KEY pEncodingKey, DWORD dwFlags, HANDLE * phFile)
{
    TCascStorage * hs;

    // Validate the storage handle
    hs = IsValidStorageHandle(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Validate the other parameters
    if(pEncodingKey == NULL || pEncodingKey->pbData == NULL || pEncodingKey->cbData == 0 || phFile == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Use the internal function fo open the file
    return OpenFileByEncodingKey(hs, pEncodingKey, dwFlags, (TCascFile **)phFile);
}

bool WINAPI CascOpenFile(HANDLE hStorage, const char * szFileName, DWORD dwLocale, DWORD dwFlags, HANDLE * phFile)
{
    PCASC_ROOT_ENTRY_MNDX pRootEntryMndx = NULL;
    PCASC_ROOT_ENTRY pRootEntry;
    PCASC_PACKAGE pPackage;
    TCascStorage * hs;
    QUERY_KEY EncodingKey;
    char * szStrippedName;
    char szFileName2[MAX_PATH+1];
    int nError = ERROR_SUCCESS;

    CASCLIB_UNUSED(dwLocale);

    // Validate the storage handle
    hs = IsValidStorageHandle(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Validate the other parameters
    if(szFileName == NULL || szFileName[0] == 0 || phFile == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // If the storage has a MNDX root directory, use it to search the entry
    if(hs->pMndxInfo != NULL)
    {
        // Convert the file name to lowercase + slashes
        NormalizeFileName_LowerSlash(szFileName2, szFileName, MAX_PATH);

        // Find the package number
        pPackage = FindMndxPackage(hs, szFileName2);
        if(pPackage != NULL)
        {
            // Cut the package name off the full path
            szStrippedName = szFileName2 + pPackage->nLength;
            while(szStrippedName[0] == '/')
                szStrippedName++;

            nError = SearchMndxInfo(hs->pMndxInfo, szStrippedName, (DWORD)(pPackage - hs->pPackages->Packages), &pRootEntryMndx);
            if(nError == ERROR_SUCCESS)
            {
                // Prepare the encoding key
                EncodingKey.pbData = pRootEntryMndx->EncodingKey;
                EncodingKey.cbData = MD5_HASH_SIZE;
            }
        }
        else
        {
            nError = ERROR_FILE_NOT_FOUND;
        }
    }
    else
    {
        // Convert the file name to lowercase + slashes
        NormalizeFileName_UpperBkSlash(szFileName2, szFileName, MAX_PATH);

        // Check the root directory for that hash
        pRootEntry = FindRootEntry(hs, szFileName2, NULL);
        if(pRootEntry != NULL)
        {
            // Prepare the root key
            EncodingKey.pbData = (LPBYTE)pRootEntry->EncodingKey;
            EncodingKey.cbData = MD5_HASH_SIZE;
            nError = ERROR_SUCCESS;
        }
        else
        {
            nError = ERROR_FILE_NOT_FOUND;
        }
    }

    // Use the root key to find the file in the encoding table entry
    if(nError == ERROR_SUCCESS)
    {
        if(!OpenFileByEncodingKey(hs, &EncodingKey, dwFlags, (TCascFile **)phFile))
        {
            assert(GetLastError() != ERROR_SUCCESS);
            nError = GetLastError();
        }
    }

#ifdef CASCLIB_TEST
    if(phFile[0] != NULL && pRootEntryMndx != NULL)
    {
        ((TCascFile *)(phFile[0]))->FileSize_RootEntry = pRootEntryMndx->FileSize;
    }
#endif

    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

bool WINAPI CascCloseFile(HANDLE hFile)
{
    TCascFile * hf;

    hf = IsValidFileHandle(hFile);
    if(hf != NULL)
    {
        // Close (dereference) the archive handle
        if(hf->hs != NULL)
            CascCloseStorage((HANDLE)hf->hs);
        hf->hs = NULL;

        // Free the file cache and frame array
        if(hf->pbFileCache != NULL)
            CASC_FREE(hf->pbFileCache);
        if(hf->pFrames != NULL)
            CASC_FREE(hf->pFrames);

        // Free the structure itself
        hf->szClassName = NULL;
        CASC_FREE(hf);
        return true;
    }

    SetLastError(ERROR_INVALID_HANDLE);
    return false;
}

