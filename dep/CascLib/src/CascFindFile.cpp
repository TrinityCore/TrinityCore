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
#include "CascMndxRoot.h"

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
        CascCloseStorage((HANDLE)pSearch->hs);
    pSearch->hs = NULL;

    // Free the file cache and frame array
    if(pSearch->szMask != NULL)
        CASC_FREE(pSearch->szMask);
    if(pSearch->szListFile != NULL)
        CASC_FREE(pSearch->szListFile);
    if(pSearch->pStruct1C != NULL)
        delete pSearch->pStruct1C;
    if(pSearch->pCache != NULL)
        ListFile_Free(pSearch->pCache);

    // Free the structure itself
    pSearch->szClassName = NULL;
    CASC_FREE(pSearch);
}
/*
DWORD dwRootEntries = 0;
DWORD dwEncoEntries = 0;
DWORD dwIndexEntries = 0;
*/
static bool VerifyRootEntry(TCascSearch * pSearch, PCASC_ROOT_ENTRY pRootEntry, PCASC_FIND_DATA pFindData, size_t nRootIndex)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    PCASC_INDEX_ENTRY pIndexEntry;
    TCascStorage * hs = pSearch->hs;
    QUERY_KEY QueryKey;
    DWORD dwByteIndex = (DWORD)(nRootIndex / 0x08);
    DWORD dwBitIndex = (DWORD)(nRootIndex & 0x07);

    // First of all, check if that entry has been reported before
    // If the bit is set, then the file has already been reported
    // by a previous search iteration
    if(pSearch->BitArray[dwByteIndex] & (1 << dwBitIndex))
        return false;
    pSearch->BitArray[dwByteIndex] |= (1 << dwBitIndex);

    // Increment the number of root entries
//  dwRootEntries++;

    // Now try to find that encoding key in the array of encoding keys
    QueryKey.pbData = pRootEntry->EncodingKey;
    QueryKey.cbData = MD5_HASH_SIZE;
    pEncodingEntry = FindEncodingEntry(hs, &QueryKey, NULL);
    if(pEncodingEntry == NULL)
        return false;

//  dwEncoEntries++;

    // Now try to find the index entry. Note that we take the first key
    QueryKey.pbData = pEncodingEntry->EncodingKey + MD5_HASH_SIZE;
    QueryKey.cbData = MD5_HASH_SIZE;
    pIndexEntry = FindIndexEntry(hs, &QueryKey);
    if(pIndexEntry == NULL)
        return false;

//  dwIndexEntries++;

    // Fill the name hash and the MD5
    memcpy(pFindData->EncodingKey, pRootEntry->EncodingKey, MD5_HASH_SIZE);
    pFindData->FileNameHash = pRootEntry->FileNameHash;
    pFindData->dwPackageIndex = 0;
    pFindData->dwLocaleFlags = pRootEntry->Locales;
    pFindData->dwFileSize = ConvertBytesToInteger_4(pEncodingEntry->FileSizeBytes);
    return true;
}

static TCascSearch * AllocateSearchHandle(TCascStorage * hs, const TCHAR * szListFile, const char * szMask)
{
    TCascSearch * pSearch;
    size_t cbToAllocate;

    // When using the MNDX info, do not allocate the extra bit array
    cbToAllocate = sizeof(TCascSearch) + ((hs->pMndxInfo == NULL) ? (hs->nRootEntries / 8) : 0);
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
            pSearch->szListFile = NewStr(szListFile, 0);
            if(pSearch->szListFile == NULL)
            {
                FreeSearchHandle(pSearch);
                return NULL;
            }
        }

        // Allocate the search mask
        pSearch->szMask = NewStr(szMask, 0);
        if(pSearch->szMask == NULL)
        {
            FreeSearchHandle(pSearch);
            return NULL;
        }
    }
   
    return pSearch;
}

static bool DoStorageSearch_ListFile(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_ROOT_ENTRY pRootEntry;
    TCascStorage * hs = pSearch->hs;
    size_t RootIndex;

    for(;;)
    {
        // Shall we get a new file name from the listfile?
        if(pSearch->FileNameHash == 0)
        {
            // Try to get next file from the listfile
            if(!ListFile_GetNext(pSearch->pCache, pSearch->szMask, pSearch->szFileName, MAX_PATH))
                break;

//          if(!_stricmp(pSearch->szFileName, "Interface\\Glues\\MODELS\\UI_MainMenu_Warlords\\Caustic_MedFreq.blp"))
//              DebugBreak();

            // Normalize the file name
            strcpy(pSearch->szNormName, pSearch->szFileName);
            NormalizeFileName_UpperBkSlash(pSearch->szNormName);

            // Find the first root entry belonging to this file name
            pRootEntry = FindFirstRootEntry(pSearch->hs, pSearch->szNormName, &RootIndex);
            if(pRootEntry == NULL)
                continue;

            // We have the name now, search all locales
            pSearch->FileNameHash = pRootEntry->FileNameHash;
            pSearch->RootIndex = RootIndex;
        }

        // Is the root index in range?
        while(pSearch->RootIndex < hs->nRootEntries)
        {
            // Get the next root entry. If name mismatches, stop searching
            pRootEntry = hs->ppRootEntries[pSearch->RootIndex];
            if(pRootEntry->FileNameHash != pSearch->FileNameHash)
                break;

            // Verify whether the file exists in the storage
            if(VerifyRootEntry(pSearch, pRootEntry, pFindData, pSearch->RootIndex++))
            {
                strcpy(pFindData->szFileName, pSearch->szFileName);
                pFindData->szPlainName = (char *)GetPlainFileName(pFindData->szFileName);
                return true;
            }
        }

        // Reset the name hash and root index and retry search
        pSearch->FileNameHash = 0;
    }

    // Listfile search ended
    return false;
}

static bool DoStorageSearch_Hash(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    PCASC_ROOT_ENTRY pRootEntry;
    TCascStorage * hs = pSearch->hs;

    // Check if there is more files with the same name hash
    while(pSearch->RootIndex < hs->nRootEntries)
    {
        // Get the pointer to the root entry
        pRootEntry = hs->ppRootEntries[pSearch->RootIndex];

        // Verify if that root entry exists in the CASC storage
        // Note that the file name will be there from the previous search
        if(VerifyRootEntry(pSearch, pRootEntry, pFindData, pSearch->RootIndex))
        {
            pFindData->szFileName[0] = 0;
            pFindData->szPlainName = NULL;
            return true;
        }

        // Move to the next entry
        pSearch->RootIndex++;
    }
    
    // Nameless search ended
    return false;
}

static bool DoStorageSearch(TCascSearch * pSearch, PCASC_FIND_DATA pFindData)
{
    // Are we searching using the MNDX ?
    if(pSearch->hs->pMndxInfo != NULL)
        return DoStorageSearch_MNDX(pSearch, pFindData);

    // State 0: No search done yet
    if(pSearch->dwState == 0)
    {
        // Does the search specify listfile?
        if(pSearch->szListFile != NULL)
            pSearch->pCache = ListFile_OpenExternal(pSearch->szListFile);
        
        // Move the search phase to the listfile searching
        pSearch->FileNameHash = 0;
        pSearch->RootIndex = 0;
        pSearch->dwState++;

        // If either file stream or listfile cache are invalid,
        // move to the next phase
        if(pSearch->pCache == NULL)
            pSearch->dwState++;
    }

    // State 1: Searching the list file
    if(pSearch->dwState == 1)
    {
        if(DoStorageSearch_ListFile(pSearch, pFindData))
            return true;

        // Move to the nameless search state
        pSearch->RootIndex = 0;
        pSearch->dwState++;
    }

    // State 2: Searching the remaining entries
    if(pSearch->dwState == 2)
    {
        if(DoStorageSearch_Hash(pSearch, pFindData))
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
    
    // Allocate the structure for archive search
    if(nError == ERROR_SUCCESS)
    {
        // Clear the entire search structure
        memset(pFindData, 0, sizeof(CASC_FIND_DATA));

        // We must have listfile for non-MNDX storages
        if(hs->pMndxInfo == NULL && szListFile == NULL)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return NULL;
        }

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
