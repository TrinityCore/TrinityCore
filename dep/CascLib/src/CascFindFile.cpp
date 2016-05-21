/*****************************************************************************/
/* CascFindFile.cpp                       Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* System-dependent directory functions for CascLib                          */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 10.05.14  1.00  Lad  The first version of CascFindFile.cpp                */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static TCascSearch * IsValidSearchHandle(HANDLE hFind)
{
    TCascSearch * pSearch = (TCascSearch *)hFind;

    return (pSearch != NULL && pSearch->szClassName != NULL && !strcmp(pSearch->szClassName, "TCascSearch") && pSearch->szMask != NULL) ? pSearch : NULL;
}

static void FreeSearchHandle(TCascSearch * pSearch)
{
    // Only if the storage handle is valid
    assert(pSearch != NULL);

    // Close (dereference) the archive handle
    if(pSearch->hs != NULL)
    {
        // Give root handler chance to free their stuff
        RootHandler_EndSearch(pSearch->hs->pRootHandler, pSearch);

        // Dereference the storage handle
        CascCloseStorage((HANDLE)pSearch->hs);
        pSearch->hs = NULL;
    }

    // Free the file cache and frame array
    if(pSearch->szMask != NULL)
        CASC_FREE(pSearch->szMask);
    if(pSearch->szListFile != NULL)
        CASC_FREE(pSearch->szListFile);
//  if(pSearch->pStruct1C != NULL)
//      delete pSearch->pStruct1C;
    if(pSearch->pCache != NULL)
        ListFile_Free(pSearch->pCache);

    // Free the structure itself
    pSearch->szClassName = NULL;
    CASC_FREE(pSearch);
}

static TCascSearch * AllocateSearchHandle(TCascStorage * hs, const TCHAR * szListFile, const char * szMask)
{
    TCascSearch * pSearch;
    size_t cbToAllocate;

    // When using the MNDX info, do not allocate the extra bit array
    cbToAllocate = sizeof(TCascSearch) + ((hs->pEncodingMap->TableSize + 7) / 8);
    pSearch = (TCascSearch *)CASC_ALLOC(BYTE, cbToAllocate);
    if(pSearch != NULL)
    {
        // Initialize the structure
        memset(pSearch, 0, cbToAllocate);
        pSearch->szClassName = "TCascSearch";

        // Save the search handle
        pSearch->hs = hs;
        hs->dwRefCount++;

        // If the mask was not given, use default
        if(szMask == NULL)
            szMask = "*";

        // Save the other variables
        if(szListFile != NULL)
        {
            pSearch->szListFile = CascNewStr(szListFile, 0);
            if(pSearch->szListFile == NULL)
            {
                FreeSearchHandle(pSearch);
                return NULL;
            }
        }

        // Allocate the search mask
        pSearch->szMask = CascNewStr(szMask, 0);
        if(pSearch->szMask == NULL)
        {
            FreeSearchHandle(pSearch);
            return NULL;
        }
    }

    return pSearch;
}

// Perform searching using root-specific provider.
// The provider may need the listfile
static bool DoStorageSearch_RootFile(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    PCASC_INDEX_ENTRY pIndexEntry;
    QUERY_KEY EncodingKey;
    QUERY_KEY IndexKey;
    LPBYTE pbEncodingKey;
    DWORD EncodingIndex = 0;
    DWORD LocaleFlags = 0;
    DWORD FileSize = CASC_INVALID_SIZE;
    DWORD ByteIndex;
    DWORD BitMask;

    for(;;)
    {
        // Attempt to find (the next) file from the root entry
        pbEncodingKey = RootHandler_Search(pSearch->hs->pRootHandler, pSearch, &FileSize, &LocaleFlags);
        if(pbEncodingKey == NULL)
            return false;

        // Verify whether the encoding key exists in the encoding table
        EncodingKey.pbData = pbEncodingKey;
        EncodingKey.cbData = MD5_HASH_SIZE;
        pEncodingEntry = FindEncodingEntry(pSearch->hs, &EncodingKey, &EncodingIndex);
        if(pEncodingEntry != NULL)
        {
            // Mark the item as already found
            // Note: Duplicate items are allowed while we are searching using file names
            // Do not exclude items from search if they were found before
            ByteIndex = (DWORD)(EncodingIndex / 8);
            BitMask   = 1 << (EncodingIndex & 0x07);
            pSearch->BitArray[ByteIndex] |= BitMask;

            // Locate the index entry
            IndexKey.pbData = GET_INDEX_KEY(pEncodingEntry);
            IndexKey.cbData = MD5_HASH_SIZE;
            pIndexEntry = FindIndexEntry(pSearch->hs, &IndexKey);
            if(pIndexEntry == NULL)
                continue;

            // If we retrieved the file size directly from the root provider, use it
            // Otherwise, we need to retrieve it from the encoding entry
            if(FileSize == CASC_INVALID_SIZE)
                FileSize = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE);

            // Fill-in the found file
            strcpy(pFindData->szFileName, pSearch->szFileName);
            memcpy(pFindData->EncodingKey, pEncodingEntry->EncodingKey, MD5_HASH_SIZE);
            pFindData->szPlainName = (char *)GetPlainFileName(pFindData->szFileName);
            pFindData->dwLocaleFlags = LocaleFlags;
            pFindData->dwFileSize = FileSize;
            return true;
        }
    }
}

static bool DoStorageSearch_EncodingKey(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    PCASC_INDEX_ENTRY pIndexEntry;
    TCascStorage * hs = pSearch->hs;
    QUERY_KEY IndexKey;
    DWORD ByteIndex;
    DWORD BitMask;

    // Check for encoding keys that haven't been found yet
    while(pSearch->IndexLevel1 < hs->pEncodingMap->TableSize)
    {
        // Check if that entry has been reported before
        ByteIndex = (DWORD)(pSearch->IndexLevel1 / 8);
        BitMask = 1 << (pSearch->IndexLevel1 & 0x07);
        if((pSearch->BitArray[ByteIndex] & BitMask) == 0)
        {
            // Locate the index entry
            pEncodingEntry  = (PCASC_ENCODING_ENTRY)hs->pEncodingMap->HashTable[pSearch->IndexLevel1];
            if(pEncodingEntry != NULL)
            {
                IndexKey.pbData = GET_INDEX_KEY(pEncodingEntry);
                IndexKey.cbData = MD5_HASH_SIZE;
                pIndexEntry = FindIndexEntry(pSearch->hs, &IndexKey);
                if(pIndexEntry != NULL)
                {
                    // Fill-in the found file
                    memcpy(pFindData->EncodingKey, pEncodingEntry->EncodingKey, MD5_HASH_SIZE);
                    pFindData->szFileName[0] = 0;
                    pFindData->szPlainName = NULL;
                    pFindData->dwLocaleFlags = CASC_LOCALE_NONE;
                    pFindData->dwFileSize = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBE);

                    // Mark the entry as already-found
                    pSearch->BitArray[ByteIndex] |= BitMask;
                    return true;
                }
            }
        }

        // Go to the next encoding entry
        pSearch->IndexLevel1++;
    }

    // Nameless search ended
    return false;
}

static bool DoStorageSearch(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    // State 0: No search done yet
    if(pSearch->dwState == 0)
    {
        // Does the search specify listfile?
        if(pSearch->szListFile != NULL)
            pSearch->pCache = ListFile_OpenExternal(pSearch->szListFile);

        // Move the search phase to the listfile searching
        pSearch->IndexLevel1 = 0;
        pSearch->dwState++;
    }

    // State 1: Searching the list file
    if(pSearch->dwState == 1)
    {
        if(DoStorageSearch_RootFile(pSearch, pFindData))
            return true;

        // Move to the nameless search state
        pSearch->IndexLevel1 = 0;
        pSearch->dwState++;
    }

    // State 2: Searching the remaining entries
    if(pSearch->dwState == 2)
    {
        if(DoStorageSearch_EncodingKey(pSearch, pFindData))
            return true;

        // Move to the final search state
        pSearch->dwState++;
    }

    return false;
}

//-----------------------------------------------------------------------------
// Public functions

HANDLE WINAPI CascFindFirstFile(
    HANDLE hStorage,
    const char * szMask,
    PCASC_FIND_DATA pFindData,
    const TCHAR * szListFile)
{
    TCascStorage * hs;
    TCascSearch * pSearch = NULL;
    int nError = ERROR_SUCCESS;

    // Check parameters
    if((hs = IsValidStorageHandle(hStorage)) == NULL)
        nError = ERROR_INVALID_HANDLE;
    if(szMask == NULL || pFindData == NULL)
        nError = ERROR_INVALID_PARAMETER;

    // Init the search structure and search handle
    if(nError == ERROR_SUCCESS)
    {
        // Clear the entire search structure
        memset(pFindData, 0, sizeof(CASC_FIND_DATA));

        // Allocate the search handle
        pSearch = AllocateSearchHandle(hs, szListFile, szMask);
        if(pSearch == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Perform search
    if(nError == ERROR_SUCCESS)
    {
        if(!DoStorageSearch(pSearch, pFindData))
            nError = ERROR_NO_MORE_FILES;
    }

    if(nError != ERROR_SUCCESS)
    {
        if(pSearch != NULL)
            FreeSearchHandle(pSearch);
        pSearch = NULL;
    }

    return (HANDLE)pSearch;
}

bool WINAPI CascFindNextFile(
    HANDLE hFind,
    PCASC_FIND_DATA pFindData)
{
    TCascSearch * pSearch;

    pSearch = IsValidSearchHandle(hFind);
    if(pSearch == NULL || pFindData == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Perform search
    return DoStorageSearch(pSearch, pFindData);
}

bool WINAPI CascFindClose(HANDLE hFind)
{
    TCascSearch * pSearch;

    pSearch = IsValidSearchHandle(hFind);
    if(pSearch == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    FreeSearchHandle(pSearch);
    return true;
}
