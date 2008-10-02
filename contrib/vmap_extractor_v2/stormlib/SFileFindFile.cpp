/*****************************************************************************/
/* SFileFindFile.cpp                      Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* A module for file searching within MPQs                                   */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 25.03.03  1.00  Lad  The first version of SFileFindFile.cpp               */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "SCommon.h"

//-----------------------------------------------------------------------------
// Defines

#define LISTFILE_CACHE_SIZE 0x1000

//-----------------------------------------------------------------------------
// Local functions

static BOOL IsValidSearchHandle(TMPQSearch * hs)
{
    if(hs == NULL || IsBadReadPtr(hs, sizeof(TMPQSearch)))
        return FALSE;

    if(!IsValidMpqHandle(hs->ha))
        return FALSE;

    return TRUE;
}

// This function compares a string with a wildcard search string.
// returns TRUE, when the string matches with the wildcard.
BOOL CheckWildCard(const char * szString, const char * szWildCard)
{
    char * szTemp;                      // Temporary helper pointer
    int nResult = 0;                    // For memcmp return values
    int nMustNotMatch = 0;              // Number of following chars int szString,
                                        // which must not match with szWildCard
    int nMustMatch = 0;                 // Number of the following characters,
                                        // which must match

    // When the string is empty, it does not match with every wildcard
    if(*szString == 0)
        return FALSE;

    // When the mask is empty, it matches to every wildcard
    if(szWildCard == NULL || *szWildCard == 0)
        return FALSE;

    // Do normal test
    for(;;)
    {
        switch(*szWildCard)
        {
            case '*': // Means "every number of characters"
                // Skip all asterisks
                while(*szWildCard == '*')
                    szWildCard++;

                // When no more characters in wildcard, it means that the strings match
                if(*szWildCard == 0)
                    return TRUE;

                // The next N characters must not agree
                nMustNotMatch |= 0x70000000;
                break;
            
            case '?':  // Means "One or no character"
                while(*szWildCard == '?')
                {
                    nMustNotMatch++;
                    szWildCard++;
                }
                break;

            default:
                // If the two characters match
                if(toupper(*szString) == toupper(*szWildCard))
                {
                    // When end of string, they agree
                    if(*szString == 0)
                        return TRUE;

                    nMustNotMatch = 0;
                    szWildCard++;
                    szString++;
                    break;
                }

                // If the next character must match, the string does not match
                if(nMustNotMatch == 0)
                    return FALSE;

                // Count the characters which must match after characters
                // that must not match
                szTemp = (char *)szWildCard;
                nMustMatch = 0;
                while(*szTemp != 0 && *szTemp != '*' && *szTemp != '?')
                {
                    nMustMatch++;
                    szTemp++;
                }

                // Now skip characters from szString up to number of chars
                // that must not match
                nResult = -1;
                while(nMustNotMatch > 0 && *szString != 0)
                {
                    if((nResult = _strnicmp(szString, szWildCard, nMustMatch)) == 0)
                        break;
                    
                    szString++;
                    nMustNotMatch--;
                }

                // Make one more comparison
                if(nMustNotMatch == 0)
                    nResult = _strnicmp(szString, szWildCard, nMustMatch);

                // If a match has been found, continue the search
                if(nResult == 0)
                {
                    nMustNotMatch = 0;
                    szWildCard += nMustMatch;
                    szString   += nMustMatch;
                    break;
                }
                return FALSE;
        }
    }
}

// Performs one MPQ search
// TODO: Test for archives > 4GB
static int DoMPQSearch(TMPQSearch * hs, SFILE_FIND_DATA * lpFindFileData)
{
    TMPQArchive * ha = hs->ha;
    TFileNode * pNode;
    TMPQHash * pHashEnd = ha->pHashTable + ha->pHeader->dwHashTableSize;
    TMPQHash * pHash = ha->pHashTable + hs->dwNextIndex;

    // Do until some file found or no more files
    while(pHash < pHashEnd)
    {
        pNode = ha->pListFile[hs->dwNextIndex++];

        // If this entry is free, do nothing
        if(pHash->dwBlockIndex < HASH_ENTRY_FREE && (DWORD_PTR)pNode < HASH_ENTRY_FREE)
        {
            // Check the file name.
            if(CheckWildCard(pNode->szFileName, hs->szSearchMask))
            {
                TMPQBlock * pBlock = ha->pBlockTable + pHash->dwBlockIndex;

                lpFindFileData->lcLocale     = pHash->lcLocale;
                lpFindFileData->dwFileSize   = pBlock->dwFSize;
                lpFindFileData->dwFileFlags  = pBlock->dwFlags;
                lpFindFileData->dwBlockIndex = pHash->dwBlockIndex;
                lpFindFileData->dwCompSize   = pBlock->dwCSize;

                // Fill the file name and plain file name
                strcpy(lpFindFileData->cFileName, pNode->szFileName);
                lpFindFileData->szPlainName = strrchr(lpFindFileData->cFileName, '\\');
                if(lpFindFileData->szPlainName == NULL)
                    lpFindFileData->szPlainName = lpFindFileData->cFileName;
                else
                    lpFindFileData->szPlainName++;

                // Fill the next entry
                return ERROR_SUCCESS;
            }
        }

        pHash++;
    }

    // No more files found, return error
    return ERROR_NO_MORE_FILES;
}

// TODO: Test for archives > 4GB
static void FreeMPQSearch(TMPQSearch *& hs)
{
    if(hs != NULL)
    {
        FREEMEM(hs);
        hs = NULL;
    }
}

//-----------------------------------------------------------------------------
// Public functions

// TODO: Test for archives > 4GB
HANDLE WINAPI SFileFindFirstFile(HANDLE hMPQ, const char * szMask, SFILE_FIND_DATA * lpFindFileData, const char * szListFile)
{
    TMPQArchive * ha = (TMPQArchive *)hMPQ;
    TMPQSearch * hs = NULL;             // Search object handle
    size_t nSize  = 0;
    int nError = ERROR_SUCCESS;

    // Check for the valid parameters
    if(nError == ERROR_SUCCESS)
    {
        if(!IsValidMpqHandle(ha))
            nError = ERROR_INVALID_PARAMETER;
       
        if(szMask == NULL || lpFindFileData == NULL)
            nError = ERROR_INVALID_PARAMETER;

        if(szListFile == NULL && !IsValidMpqHandle(ha))
            nError = ERROR_INVALID_PARAMETER;
    }

    // Include the listfile into the MPQ's internal listfile
    // Note that if the listfile name is NULL, do nothing because the
    // internal listfile is always included.
    if(nError == ERROR_SUCCESS && szListFile != NULL)
        nError = SFileAddListFile((HANDLE)ha, szListFile);

    // Allocate the structure for MPQ search
    if(nError == ERROR_SUCCESS)
    {
        nSize = sizeof(TMPQSearch) + strlen(szMask) + 1;
        if((hs = (TMPQSearch *)ALLOCMEM(char, nSize)) == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Perform the first search
    if(nError == ERROR_SUCCESS)
    {
        memset(hs, 0, sizeof(TMPQSearch));
        hs->ha          = ha;
        hs->dwNextIndex = 0;
        strcpy(hs->szSearchMask, szMask);
        nError = DoMPQSearch(hs, lpFindFileData);
    }

    // Cleanup
    if(nError != ERROR_SUCCESS)
    {
        FreeMPQSearch(hs);
        SetLastError(nError);
    }
    
    // Return the result value
    return (HANDLE)hs;
}

// TODO: Test for archives > 4GB
BOOL WINAPI SFileFindNextFile(HANDLE hFind, SFILE_FIND_DATA * lpFindFileData)
{
    TMPQSearch * hs = (TMPQSearch *)hFind;
    int nError = ERROR_SUCCESS;

    // Check the parameters
    if(nError == ERROR_SUCCESS)
    {
        if(!IsValidSearchHandle(hs) || lpFindFileData == NULL)
            nError = ERROR_INVALID_PARAMETER;
    }

    if(nError == ERROR_SUCCESS)
        nError = DoMPQSearch(hs, lpFindFileData);

    if(nError != ERROR_SUCCESS)
    {
        SetLastError(nError);
        return FALSE;
    }
    return TRUE;
}

// TODO: Test for archives > 4GB
BOOL WINAPI SFileFindClose(HANDLE hFind)
{
    TMPQSearch * hs = (TMPQSearch *)hFind;

    // Check the parameters
    if(!IsValidSearchHandle(hs))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    FreeMPQSearch(hs);
    return TRUE;
}
