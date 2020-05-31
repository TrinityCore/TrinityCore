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
    pFindData->FileSize = CASC_INVALID_SIZE64;
    pFindData->dwFileDataId = CASC_INVALID_ID;
    pFindData->dwLocaleFlags = CASC_INVALID_ID;
    pFindData->dwContentFlags = CASC_INVALID_ID;
    pFindData->dwSpanCount = 1;
    pFindData->NameType = CascNameFull;
    pFindData->bFileAvailable = false;
}

static void SupplyFakeFileName(PCASC_FIND_DATA pFindData, PCASC_CKEY_ENTRY pCKeyEntry)
{
    // If there is a file data ID, create fake file name
    if(pFindData->dwFileDataId != CASC_INVALID_ID)
    {
        CascStrPrintf(pFindData->szFileName, _countof(pFindData->szFileName), "FILE%08X.dat", pFindData->dwFileDataId);
        pFindData->NameType = CascNameDataId;
        return;
    }

    // If there is a CKey, convert the CKey to file name
    if(pCKeyEntry->Flags & CASC_CE_HAS_CKEY)
    {
        StringFromBinary(pFindData->CKey, MD5_HASH_SIZE, pFindData->szFileName);
        pFindData->NameType = CascNameCKey;
        return;
    }

    // EKey should be always present
    if(pCKeyEntry->Flags & CASC_CE_HAS_EKEY)
    {
        StringFromBinary(pFindData->EKey, MD5_HASH_SIZE, pFindData->szFileName);
        pFindData->NameType = CascNameEKey;
        return;
    }

    assert(false);
}

static bool CopyCKeyEntryToFindData(PCASC_FIND_DATA pFindData, PCASC_CKEY_ENTRY pCKeyEntry)
{
    ULONGLONG ContentSize = 0;
    ULONGLONG EncodedSize = 0;

    // Supply both keys
    CopyMemory16(pFindData->CKey, pCKeyEntry->CKey);
    CopyMemory16(pFindData->EKey, pCKeyEntry->EKey);

    // Supply the tag mask
    pFindData->TagBitMask = pCKeyEntry->TagBitMask;
    
    // Supply the plain name. Only do that if the found name is not a CKey/EKey
    if(pFindData->szFileName[0] != 0)
        pFindData->szPlainName = (char *)GetPlainFileName(pFindData->szFileName);

    // If we retrieved the file size directly from the root provider, use it
    // Otherwise, supply EncodedSize or ContentSize, whichever is available (but ContentSize > EncodedSize)
    pFindData->dwSpanCount = GetFileSpanInfo(pCKeyEntry, &ContentSize, &EncodedSize);
    if(pFindData->FileSize == CASC_INVALID_SIZE64)
    {
        if(ContentSize != CASC_INVALID_SIZE64)
            pFindData->FileSize = ContentSize;
        else 
            pFindData->FileSize = EncodedSize;
    }

    // Set flag indicating that the file is locally available
    pFindData->bFileAvailable = (pCKeyEntry->Flags & CASC_CE_FILE_IS_LOCAL);

    // Supply a fake file name, if there is none supplied by the root handler
    if(pFindData->szFileName[0] == 0)
        SupplyFakeFileName(pFindData, pCKeyEntry);
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
        // Locate the n-th CKey entry.
        pCKeyEntry = (PCASC_CKEY_ENTRY)hs->CKeyArray.ItemAt(pSearch->nFileIndex++);
        //BREAK_ON_XKEY3(pCKeyEntry->CKey, 0x2B, 0xfc, 0xe4);

        // Only report files that are unreferenced by the ROOT handler
        if(pCKeyEntry->IsFile() && pCKeyEntry->RefCount == 0)
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
    DWORD dwErrCode = ERROR_SUCCESS;

    // Check parameters
    if((hs = TCascStorage::IsValid(hStorage)) == NULL)
        dwErrCode = ERROR_INVALID_HANDLE;
    if(szMask == NULL || pFindData == NULL)
        dwErrCode = ERROR_INVALID_PARAMETER;

    // Init the search structure and search handle
    if(dwErrCode == ERROR_SUCCESS)
    {
        // Allocate the search handle
        pSearch = new TCascSearch(hs, szListFile, szMask);
        if(pSearch == NULL)
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Perform search
    if(dwErrCode == ERROR_SUCCESS)
    {
        if(!DoStorageSearch(pSearch, pFindData))
            dwErrCode = ERROR_NO_MORE_FILES;
    }

    if(dwErrCode != ERROR_SUCCESS)
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
