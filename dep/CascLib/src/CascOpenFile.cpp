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
PCASC_ROOT_ENTRY FindFirstRootEntry(TCascStorage * hs, const char * szFileName, size_t * PtrIndex)
{
    PCASC_ROOT_ENTRY pFoundEntry = NULL;
    PCASC_ROOT_ENTRY pRootEntry;
    ULONGLONG FileNameHash;
    uint32_t dwHashHigh = 0;
    uint32_t dwHashLow = 0;
    size_t StartEntry = 0;
    size_t MidlEntry = 0;
    size_t EndEntry = hs->nRootEntries;

    // Calculate the HASH value of the normalized file name
    hashlittle2(szFileName, strlen(szFileName), &dwHashHigh, &dwHashLow);
    FileNameHash = ((ULONGLONG)dwHashHigh << 0x20) | dwHashLow;

    // Perform binary search
    while(StartEntry < EndEntry)
    {
        // Calculate the middle of the interval
        MidlEntry = StartEntry + ((EndEntry - StartEntry) / 2);
        pRootEntry = hs->ppRootEntries[MidlEntry];

        // Did we find it?
        if(pRootEntry->FileNameHash == FileNameHash)
        {
            pFoundEntry = pRootEntry;
            break;
        }

        // Move the interval to the left or right
        (FileNameHash < pRootEntry->FileNameHash) ? EndEntry = MidlEntry : StartEntry = MidlEntry + 1;
    }

    // Move the pointer back to the first entry with that hash
    if(pFoundEntry != NULL)
    {
        while(MidlEntry > 0 && hs->ppRootEntries[MidlEntry - 1]->FileNameHash == FileNameHash)
        {
            pFoundEntry = hs->ppRootEntries[MidlEntry - 1];
            MidlEntry--;
        }
    }

    // Return what we found
    if(PtrIndex != NULL)
        *PtrIndex = MidlEntry;
    return pFoundEntry;
}

// Check the root directory for that hash
PCASC_ROOT_ENTRY FindRootEntryLocale(TCascStorage * hs, char * szFileName, DWORD Locale)
{
    PCASC_ROOT_ENTRY pThatEntry = NULL;
    PCASC_ROOT_ENTRY pENUSEntry = NULL;
    PCASC_ROOT_ENTRY pENGBEntry = NULL;
    PCASC_ROOT_ENTRY pAnyEntry = NULL;
    PCASC_ROOT_ENTRY pEndEntry = NULL;
    PCASC_ROOT_ENTRY pRootEntry = NULL;
    ULONGLONG FileNameHash;
    size_t EntryIndex = 0;
    size_t EndEntry = hs->nRootEntries;

    // Find a root entry with the given name hash
    pRootEntry = FindFirstRootEntry(hs, szFileName, &EntryIndex);
    if(pRootEntry != NULL)
    {
        // Rememeber the file name hash
        pEndEntry = hs->pRootEntries + hs->nRootEntries;
        FileNameHash = pRootEntry->FileNameHash;

        // Find all suitable root entries
        while(EntryIndex < EndEntry)
        {
            // Get the root entry
            pRootEntry = hs->ppRootEntries[EntryIndex++];
            if(pRootEntry->FileNameHash != FileNameHash)
                break;

            // If a locale has been given, check it
            if(pThatEntry == NULL && Locale != 0 && (Locale & pRootEntry->Locales))
                pThatEntry = pRootEntry;
            if(pENUSEntry == NULL && (pRootEntry->Locales & CASC_LOCALE_ENUS))
                pENUSEntry = pRootEntry;
            if(pENGBEntry == NULL && (pRootEntry->Locales & CASC_LOCALE_ENGB))
                pENGBEntry = pRootEntry;
            if(pAnyEntry == NULL)
                pAnyEntry = pRootEntry;
            
            // Move to the next one
            pRootEntry++;
        }

        // Return the key by priority
        if(pThatEntry != NULL)
            return pThatEntry;
        if(pENGBEntry != NULL)
            return pENGBEntry;
        if(pENUSEntry != NULL)
            return pENUSEntry;
    }

    // Return whatever we got
    return pAnyEntry;
}

static TCascFile * CreateFileHandle(TCascStorage * hs, PCASC_INDEX_ENTRY pIndexEntry)
{
    ULONGLONG FileOffsMask = ((ULONGLONG)1 << hs->KeyMapping[0].SegmentBits) - 1;
    ULONGLONG FileOffset = ConvertBytesToInteger_5(pIndexEntry->FileOffset);
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
        
        // Copy the compressed file size
        hf->CompressedSize = ConvertBytesToInteger_4_LE(pIndexEntry->FileSize) - 0x1E;

        // For now, we set the file size to be equal to compressed size
        // This is used when loading the "encoding" file, which does not
        // have entry in the encoding itself
        hf->FileSize = hf->CompressedSize;

        // Increment the number of references to the archive
        hs->dwRefCount++;
        hf->hs = hs;
    }

    return hf;
}

static bool OpenFileByIndexKey(TCascStorage * hs, PQUERY_KEY pIndexKey, DWORD dwFlags, HANDLE * phFile)
{
    PCASC_INDEX_ENTRY pIndexEntry;
    TCascFile * hf = NULL;
    int nError = ERROR_SUCCESS;

    CASCLIB_UNUSED(dwFlags);

    // Find the key entry in the array of file keys
    pIndexEntry = FindIndexEntry(hs, pIndexKey);
    if(pIndexEntry == NULL)
        nError = ERROR_FILE_NOT_FOUND;

    // Create the file handle structure
    if(nError == ERROR_SUCCESS)
    {
        hf = CreateFileHandle(hs, pIndexEntry);
        *phFile = (HANDLE)hf;
        if(hf == NULL)
            nError = ERROR_FILE_NOT_FOUND;
    }

    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

static bool OpenFileByEncodingKey(TCascStorage * hs, PQUERY_KEY pEncodingKey, DWORD dwFlags, HANDLE * phFile)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    QUERY_KEY IndexKey;
    TCascFile * hf = NULL;
    int nError = ERROR_SUCCESS;

    // Find the encoding entry
    pEncodingEntry = FindEncodingEntry(hs, pEncodingKey, NULL);
    if(pEncodingEntry == NULL)
        nError = ERROR_FILE_NOT_FOUND;

    // Prepare the file index and open the file by index
    // Note: We don't know what to do if there is more than just one index key
    // We always take the first file present. Is that correct?
//  IndexKey.pbData = pEncodingEntry->EncodingKey + (MD5_HASH_SIZE * pEncodingEntry->KeyCount);
//  assert(pEncodingEntry->KeyCount == 1);
    IndexKey.pbData = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;
    IndexKey.cbData = MD5_HASH_SIZE;
    if(OpenFileByIndexKey(hs, &IndexKey, dwFlags, phFile))
    {
        // Fix the file size from the encoding key
        hf = IsValidFileHandle(*phFile);
        if(hf != NULL)
        {
            hf->FileSize = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBytes);
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
    return OpenFileByIndexKey(hs, pIndexKey, dwFlags, phFile);
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
    return OpenFileByEncodingKey(hs, pEncodingKey, dwFlags, phFile);
}

bool WINAPI CascOpenFile(HANDLE hStorage, const char * szFileName, DWORD dwLocale, DWORD dwFlags, HANDLE * phFile)
{
    CASC_ROOT_KEY_INFO EncodingKeyInfo;
    PCASC_ROOT_ENTRY pRootEntry;
    PCASC_PACKAGE pPackage;
    TCascStorage * hs;
    QUERY_KEY EncodingKey;
    char * szStrippedName;
    char * szFileName2;
    int nError = ERROR_SUCCESS;

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

    // Create the copy of the file name
    szFileName2 = NewStr(szFileName, 0);
    if(szFileName2 != NULL)
    {
        // If the storage has a MNDX root directory, use it to search the entry
        if(hs->pMndxInfo != NULL)
        {
            // Convert the file name to lowercase + slashes
            NormalizeFileName_LowerSlash(szFileName2);

            // Find the package number
            pPackage = FindMndxPackage(hs, szFileName2);
            if(pPackage != NULL)
            {
                // Cut the package name off the full path
                szStrippedName = szFileName2 + pPackage->nLength;
                while(szStrippedName[0] == '/')
                    szStrippedName++;

                nError = SearchMndxInfo(hs->pMndxInfo, szStrippedName, (DWORD)(pPackage - hs->pPackages->Packages), &EncodingKeyInfo);
                if(nError == ERROR_SUCCESS)
                {
                    // Prepare the encoding key
                    EncodingKey.pbData = EncodingKeyInfo.EncodingKey;
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
            NormalizeFileName_UpperBkSlash(szFileName2);

            // Check the root directory for that hash
            pRootEntry = FindRootEntryLocale(hs, szFileName2, dwLocale);
            nError = (pRootEntry != NULL) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
            if(pRootEntry != NULL)
            {
                // Prepare the root key
                EncodingKey.pbData = pRootEntry->EncodingKey;
                EncodingKey.cbData = MD5_HASH_SIZE;
            }
        }

        // Use the root key to find the file in the encoding table entry
        if(nError == ERROR_SUCCESS)
        {
            if(!OpenFileByEncodingKey(hs, &EncodingKey, dwFlags, phFile))
            {
                assert(GetLastError() != ERROR_SUCCESS);
                nError = GetLastError();
            }
        }

        // Delete the file name copy
        delete [] szFileName2;
    }
    else
        nError = ERROR_NOT_ENOUGH_MEMORY;

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

