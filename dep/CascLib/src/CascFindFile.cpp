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

// Reset the search structure. Called before each search
static void ResetFindData(PCASC_FIND_DATA pFindData)
{
    // Reset the variables
    ZeroMemory16(pFindData->CKey);
    ZeroMemory16(pFindData->EKey);
    pFindData->szFileName[0] = 0;
    pFindData->szPlainName = pFindData->szFileName;
    pFindData->TagBitMask = 0;
    pFindData->dwFileDataId = CASC_INVALID_ID;
    pFindData->dwFileSize = CASC_INVALID_SIZE;
    pFindData->dwLocaleFlags = CASC_INVALID_ID;
    pFindData->dwContentFlags = CASC_INVALID_ID;
    pFindData->NameType = CascNameFull;
    pFindData->bFileAvailable = false;
    pFindData->bCanOpenByName = false;
    pFindData->bCanOpenByDataId = false;
    pFindData->bCanOpenByCKey = false;
    pFindData->bCanOpenByEKey = false;
}

static void SupplyFakeFileName(PCASC_FIND_DATA pFindData)
{
    // If the file can be open by file data id, create fake file name
    if(pFindData->bCanOpenByDataId)
    {
        CascStrPrintf(pFindData->szFileName, _countof(pFindData->szFileName), "FILE%08X.dat", pFindData->dwFileDataId);
        pFindData->NameType = CascNameDataId;
        return;
    }

    // If the file can be open by CKey, convert the CKey to file name
    if(pFindData->bCanOpenByCKey)
    {
        StringFromBinary(pFindData->CKey, MD5_HASH_SIZE, pFindData->szFileName);
        pFindData->NameType = CascNameCKey;
        return;
    }

    // CKey should be always present
    StringFromBinary(pFindData->EKey, MD5_HASH_SIZE, pFindData->szFileName);
    pFindData->NameType = CascNameEKey;
    assert(pFindData->bCanOpenByEKey != false);
}

static bool CopyCKeyEntryToFindData(PCASC_FIND_DATA pFindData, PCASC_CKEY_ENTRY pCKeyEntry)
{
    // Supply both keys
    CopyMemory16(pFindData->CKey, pCKeyEntry->CKey);
    CopyMemory16(pFindData->EKey, pCKeyEntry->EKey);
    pFindData->bCanOpenByCKey = (pCKeyEntry->Flags & CASC_CE_HAS_CKEY) ? true : false;
    pFindData->bCanOpenByEKey = (pCKeyEntry->Flags & CASC_CE_HAS_EKEY) ? true : false;

    // Supply the tag mask
    pFindData->TagBitMask = pCKeyEntry->TagBitMask;
    
    // Supply the plain name. Only do that if the found name is not a CKey/EKey
    if(pFindData->szFileName[0] != 0)
        pFindData->szPlainName = (char *)GetPlainFileName(pFindData->szFileName);

    // If we retrieved the file size directly from the root provider, use it
    // Otherwise, supply EncodedSize or ContentSize, whichever is available (but ContentSize > EncodedSize)
    if(pFindData->dwFileSize == CASC_INVALID_SIZE)
        pFindData->dwFileSize = pCKeyEntry->ContentSize;

    // Set flag indicating that the file is locally available
    pFindData->bFileAvailable = (pCKeyEntry->Flags & CASC_CE_FILE_IS_LOCAL);

    // Supply a fake file name, if there is none supplied by the root handler
    if(pFindData->szFileName[0] == 0)
        SupplyFakeFileName(pFindData);
    return true;
}

// Perform searching using root-specific provider.
// The provider may need the listfile
static bool DoStorageSearch_RootFile(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    TCascStorage * hs = pSearch->hs;

    // Reset the search structure
    ResetFindData(pFindData);

    // Enumerate over all files
    for(;;)
    {
        // Attempt to find (the next) file from the root handler
        pCKeyEntry = hs->pRootHandler->Search(pSearch, pFindData);
        if(pCKeyEntry == NULL)
            return false;

        // The entry is expected to be referenced by the root directory
        assert(pCKeyEntry->RefCount != 0);

        // Copy the CKey entry to the find data and return it
        return CopyCKeyEntryToFindData(pFindData, pCKeyEntry);
    }
}

static bool DoStorageSearch_CKey(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    TCascStorage * hs = pSearch->hs;
    size_t nTotalItems = hs->CKeyArray.ItemCount();

    // Reset the find data structure
    ResetFindData(pFindData);

    // Check for CKeys that haven't been found yet
    while(pSearch->nFileIndex < nTotalItems)
    {
        // Locate the n-th CKey entry. If this entry is not referenced by the root handler, we include it in the search result
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.ItemAt(pSearch->nFileIndex++);
        if((pCKeyEntry->Flags & CASC_CE_FOLDER_ENTRY) == 0 && pCKeyEntry->RefCount == 0)
        {
            return CopyCKeyEntryToFindData(pFindData, pCKeyEntry);
        }
    }

    // Nameless search ended
    return false;
}

static bool DoStorageSearch(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    // State 0: No search done yet
    if(pSearch->nSearchState == 0)
    {
        // Does the search specify listfile?
        if(pSearch->szListFile != NULL)
            pSearch->pCache = ListFile_OpenExternal(pSearch->szListFile);

        // Move the search phase to the listfile searching
        pSearch->nSearchState = 1;
        pSearch->nFileIndex = 0;
    }

    // State 1: Searching the list file
    if(pSearch->nSearchState == 1)
    {
        if(DoStorageSearch_RootFile(pSearch, pFindData))
            return true;

        // Move to the nameless search state
        pSearch->nSearchState = 2;
        pSearch->nFileIndex = 0;
    }

    // State 2: Searching the remaining entries by CKey
    if(pSearch->nSearchState == 2 && (pSearch->szMask == NULL || !strcmp(pSearch->szMask, "*")))
    {
        if(DoStorageSearch_CKey(pSearch, pFindData))
            return true;

        // Move to the final search state
        pSearch->nSearchState++;
        pSearch->nFileIndex = 0;
    }

    return false;
}

//-----------------------------------------------------------------------------
// Public functions

HANDLE WINAPI CascFindFirstFile(
    HANDLE hStorage,
    LPCSTR szMask,
    PCASC_FIND_DATA pFindData,
    LPCTSTR szListFile)
{
    TCascStorage * hs;
    TCascSearch * pSearch = NULL;
    int nError = ERROR_SUCCESS;

    // Check parameters
    if((hs = TCascStorage::IsValid(hStorage)) == NULL)
        nError = ERROR_INVALID_HANDLE;
    if(szMask == NULL || pFindData == NULL)
        nError = ERROR_INVALID_PARAMETER;

    // Init the search structure and search handle
    if(nError == ERROR_SUCCESS)
    {
        // Allocate the search handle
        pSearch = new TCascSearch(hs, szListFile, szMask);
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
        delete pSearch;
        pSearch = (TCascSearch *)INVALID_HANDLE_VALUE;
    }

    return (HANDLE)pSearch;
}

bool WINAPI CascFindNextFile(
    HANDLE hFind,
    PCASC_FIND_DATA pFindData)
{
    TCascSearch * pSearch;

    pSearch = TCascSearch::IsValid(hFind);
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

    pSearch = TCascSearch::IsValid(hFind);
    if(pSearch == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    delete pSearch;
    return true;
}
