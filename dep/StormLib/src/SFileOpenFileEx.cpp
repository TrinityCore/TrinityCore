/*****************************************************************************/
/* SFileOpenFileEx.cpp                    Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Description :                                                             */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.99  1.00  Lad  The first version of SFileOpenFileEx.cpp             */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

static bool OpenLocalFile(const char * szFileName, HANDLE * phFile)
{
    TFileStream * pStream;
    TMPQFile * hf = NULL;

    // We have to convert the local file name to UNICODE, if needed
#ifdef _UNICODE
    TCHAR szFileNameT[MAX_PATH];
    int i;

    for(i = 0; szFileName[i] != 0; i++)
        szFileNameT[i] = szFileName[i];
    szFileNameT[i] = 0;
    pStream = FileStream_OpenFile(szFileNameT, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);

#else
    pStream = FileStream_OpenFile(szFileName, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
#endif

    if(pStream != NULL)
    {
        // Allocate and initialize file handle
        hf = CreateMpqFile(NULL);
        if(hf != NULL)
        {
            hf->pStream = pStream;
            *phFile = hf;
            return true;
        }
        else
        {
            FileStream_Close(pStream);
            SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        }
    }
    *phFile = NULL;
    return false;
}

bool OpenPatchedFile(HANDLE hMpq, const char * szFileName, DWORD dwReserved, HANDLE * phFile)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TMPQFile * hfPatch;                     // Pointer to patch file
    TMPQFile * hfBase = NULL;               // Pointer to base open file
    TMPQFile * hfLast = NULL;               // The highest file in the chain that is not patch file
    TMPQFile * hf = NULL;
    HANDLE hPatchFile;
    char szPatchFileName[MAX_PATH];

    // Keep this flag here for future updates
    dwReserved = dwReserved;

    // First of all, try to open the original version of the file in any of the patch chain
    while(ha != NULL)
    {
        // Construct the name of the patch file
        strcpy(szPatchFileName, ha->szPatchPrefix);
        strcpy(&szPatchFileName[ha->cchPatchPrefix], szFileName);
        if(SFileOpenFileEx((HANDLE)ha, szPatchFileName, SFILE_OPEN_FROM_MPQ, (HANDLE *)&hfBase))
        {
            // The file must be a base file, i.e. without MPQ_FILE_PATCH_FILE
            if((hfBase->pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE) == 0)
            {
                hf = hfLast = hfBase;
                break;
            }

            SFileCloseFile((HANDLE)hfBase);
        }

        // Move to the next file in the patch chain
        ha = ha->haPatch;
    }

    // If we couldn't find the file in any of the patches, it doesn't exist
    if(hf == NULL)
    {
        SetLastError(ERROR_FILE_NOT_FOUND);
        return false;
    }

    // Now keep going in the patch chain and open every patch file that is there
    for(ha = ha->haPatch; ha != NULL; ha = ha->haPatch)
    {
        // Construct patch file name
        strcpy(szPatchFileName, ha->szPatchPrefix);
        strcpy(&szPatchFileName[ha->cchPatchPrefix], szFileName);
        if(SFileOpenFileEx((HANDLE)ha, szPatchFileName, SFILE_OPEN_FROM_MPQ, &hPatchFile))
        {
            // Remember the new version
            hfPatch = (TMPQFile *)hPatchFile;

            // If we encountered a full replacement of the file, 
            // we have to remember the highest full file
            if((hfPatch->pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE) == 0)
                hfLast = hfPatch;

            // Set current patch to base file and move on
            hf->hfPatchFile = hfPatch;
            hf = hfPatch;
        }
    }

    // Now we need to free all files that are below the highest unpatched version
    while(hfBase != hfLast)
    {
        TMPQFile * hfNext = hfBase->hfPatchFile;

        // Free the file below
        hfBase->hfPatchFile = NULL;
        FreeMPQFile(hfBase);

        // Move the base to the next file
        hfBase = hfNext;
    }

    // Give the updated base MPQ
    if(phFile != NULL)
        *phFile = (HANDLE)hfBase;
    return true;
}

/*****************************************************************************/
/* Public functions                                                          */
/*****************************************************************************/

//-----------------------------------------------------------------------------
// SFileEnumLocales enums all locale versions within MPQ. 
// Functions fills all available language identifiers on a file into the buffer
// pointed by plcLocales. There must be enough entries to copy the localed,
// otherwise the function returns ERROR_INSUFFICIENT_BUFFER.

int WINAPI SFileEnumLocales(
    HANDLE hMpq,
    const char * szFileName,
    LCID * plcLocales,
    LPDWORD pdwMaxLocales,
    DWORD dwSearchScope)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pFileEntry;
    TMPQHash * pFirstHash;
    TMPQHash * pHash;
    DWORD dwFileIndex = 0;
    DWORD dwLocales = 0;

    // Test the parameters
    if(!IsValidMpqHandle(ha))
        return ERROR_INVALID_HANDLE;
    if(szFileName == NULL || *szFileName == 0)
        return ERROR_INVALID_PARAMETER;
    if(pdwMaxLocales == NULL)
        return ERROR_INVALID_PARAMETER;
    
    // Keep compiler happy
    dwSearchScope = dwSearchScope;

    // Parse hash table entries for all locales
    if(!IsPseudoFileName(szFileName, &dwFileIndex))
    {
        // Calculate the number of locales
        pFirstHash = pHash = GetFirstHashEntry(ha, szFileName);
        while(pHash != NULL)
        {
            dwLocales++;
            pHash = GetNextHashEntry(ha, pFirstHash, pHash);
        }

        // Test if there is enough space to copy the locales
        if(*pdwMaxLocales < dwLocales)
        {
            *pdwMaxLocales = dwLocales;
            return ERROR_INSUFFICIENT_BUFFER;
        }

        // Enum the locales
        pFirstHash = pHash = GetFirstHashEntry(ha, szFileName);
        while(pHash != NULL)
        {
            *plcLocales++ = pHash->lcLocale;
            pHash = GetNextHashEntry(ha, pFirstHash, pHash);
        }
    }
    else
    {
        // There must be space for 1 locale
        if(*pdwMaxLocales < 1)
        {
            *pdwMaxLocales = 1;
            return ERROR_INSUFFICIENT_BUFFER;
        }

        // For nameless access, always return 1 locale
        pFileEntry = GetFileEntryByIndex(ha, dwFileIndex);
        pHash = ha->pHashTable + pFileEntry->dwHashIndex;
        *plcLocales = pHash->lcLocale;
        dwLocales = 1;
    }

    // Give the caller the total number of found locales
    *pdwMaxLocales = dwLocales;
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// SFileHasFile
//
//   hMpq          - Handle of opened MPQ archive
//   szFileName    - Name of file to look for

bool WINAPI SFileHasFile(HANDLE hMpq, const char * szFileName)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pFileEntry;
    DWORD dwFlagsToCheck = MPQ_FILE_EXISTS;
    DWORD dwFileIndex = 0;
    char szPatchFileName[MAX_PATH];
    bool bIsPseudoName;
    int nError = ERROR_SUCCESS;

    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_HANDLE;
    if(szFileName == NULL || *szFileName == 0)
        nError = ERROR_INVALID_PARAMETER;

    // Prepare the file opening
    if(nError == ERROR_SUCCESS)
    {
        // Different processing for pseudo-names
        bIsPseudoName = IsPseudoFileName(szFileName, &dwFileIndex);

        // Walk through the MPQ and all patches
        while(ha != NULL)
        {
            // Verify presence of the file
            pFileEntry = (bIsPseudoName == false) ? GetFileEntryLocale(ha, szFileName, lcFileLocale)
                                                  : GetFileEntryByIndex(ha, dwFileIndex);
            // Verify the file flags
            if(pFileEntry != NULL && (pFileEntry->dwFlags & dwFlagsToCheck) == MPQ_FILE_EXISTS)
                return true;

            // If this is patched archive, go to the patch
            dwFlagsToCheck = MPQ_FILE_EXISTS | MPQ_FILE_PATCH_FILE;
            ha = ha->haPatch;

            // Prepare the patched file name
            if(ha != NULL)
            {
                strcpy(szPatchFileName, ha->szPatchPrefix);
                strcat(szPatchFileName, szFileName);
                szFileName = szPatchFileName;
            }
        }

        // Not found, sorry
        nError = ERROR_FILE_NOT_FOUND;
    }

    // Cleanup
    SetLastError(nError);
    return false;
}


//-----------------------------------------------------------------------------
// SFileOpenFileEx
//
//   hMpq          - Handle of opened MPQ archive
//   szFileName    - Name of file to open
//   dwSearchScope - Where to search
//   phFile        - Pointer to store opened file handle

bool WINAPI SFileOpenFileEx(HANDLE hMpq, const char * szFileName, DWORD dwSearchScope, HANDLE * phFile)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry  * pFileEntry = NULL;
    TMPQFile    * hf = NULL;
    DWORD dwFileIndex = 0;
    bool bOpenByIndex = false;
    int nError = ERROR_SUCCESS;

    // Don't accept NULL pointer to file handle
    if(phFile == NULL)
        nError = ERROR_INVALID_PARAMETER;

    // Prepare the file opening
    if(nError == ERROR_SUCCESS)
    {
        switch(dwSearchScope)
        {
            case SFILE_OPEN_PATCHED_FILE:

                // We want to open the updated version of the file
                return OpenPatchedFile(hMpq, szFileName, 0, phFile);

            case SFILE_OPEN_FROM_MPQ:
                
                if(!IsValidMpqHandle(ha))
                {
                    nError = ERROR_INVALID_HANDLE;
                    break;
                }

                if(szFileName == NULL || *szFileName == 0)
                {
                    nError = ERROR_INVALID_PARAMETER;
                    break;
                }

                // First of all, check the name as-is
                if(!IsPseudoFileName(szFileName, &dwFileIndex))
                {
                    pFileEntry = GetFileEntryLocale(ha, szFileName, lcFileLocale);
                    if(pFileEntry == NULL)
                        nError = ERROR_FILE_NOT_FOUND;
                }
                else
                {
                    bOpenByIndex = true;
                    pFileEntry = GetFileEntryByIndex(ha, dwFileIndex);
                    if(pFileEntry == NULL)
                        nError = ERROR_FILE_NOT_FOUND;
                }
                break;

            case SFILE_OPEN_ANY_LOCALE:

                // This open option is reserved for opening MPQ internal listfile.
                // No argument validation. Tries to open file with neutral locale first,
                // then any other available.
                dwSearchScope = SFILE_OPEN_FROM_MPQ;
                pFileEntry = GetFileEntryAny(ha, szFileName);
                if(pFileEntry == NULL)
                    nError = ERROR_FILE_NOT_FOUND;
                break;

            case SFILE_OPEN_LOCAL_FILE:

                if(szFileName == NULL || *szFileName == 0)
                {
                    nError = ERROR_INVALID_PARAMETER;
                    break;
                }

                return OpenLocalFile(szFileName, phFile); 

            default:

                // Don't accept any other value
                nError = ERROR_INVALID_PARAMETER;
                break;
        }

        // Quick return if something failed
        if(nError != ERROR_SUCCESS)
        {
            SetLastError(nError);
            return false;
        }
    }

    // Test if the file was not already deleted.
    if(nError == ERROR_SUCCESS)
    {
        if((pFileEntry->dwFlags & MPQ_FILE_EXISTS) == 0)
            nError = ERROR_FILE_NOT_FOUND;
        if(pFileEntry->dwFlags & ~MPQ_FILE_VALID_FLAGS)
            nError = ERROR_NOT_SUPPORTED;
    }

    // Allocate file handle
    if(nError == ERROR_SUCCESS)
    {
        if((hf = STORM_ALLOC(TMPQFile, 1)) == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Initialize file handle
    if(nError == ERROR_SUCCESS)
    {
        memset(hf, 0, sizeof(TMPQFile));
        hf->pFileEntry = pFileEntry;
        hf->dwMagic = ID_MPQ_FILE;
        hf->ha = ha;

        hf->MpqFilePos   = pFileEntry->ByteOffset;
        hf->RawFilePos   = ha->MpqPos + hf->MpqFilePos;
        hf->dwDataSize   = pFileEntry->dwFileSize;

        // If the MPQ has sector CRC enabled, enable if for the file
        if(ha->dwFlags & MPQ_FLAG_CHECK_SECTOR_CRC)
            hf->bCheckSectorCRCs = true;

        // If we know the real file name, copy it to the file entry
        if(bOpenByIndex == false)
        {
            // If there is no file name yet, allocate it
            AllocateFileName(pFileEntry, szFileName);

            // If the file is encrypted, we should detect the file key
            if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
            {
                hf->dwFileKey = DecryptFileKey(szFileName,
                                               pFileEntry->ByteOffset,
                                               pFileEntry->dwFileSize,
                                               pFileEntry->dwFlags);
            }
        }
        else
        {
            // Try to auto-detect the file name
            if(!SFileGetFileName(hf, NULL))
                nError = GetLastError();
        }
    }

    // If the file is actually a patch file, we have to load the patch file header
    if(nError == ERROR_SUCCESS && pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE)
    {
        assert(hf->pPatchInfo == NULL);
        nError = AllocatePatchInfo(hf, true);
    }

    // Cleanup
    if(nError != ERROR_SUCCESS)
    {
        SetLastError(nError);
        FreeMPQFile(hf);
    }

    *phFile = hf;
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// bool WINAPI SFileCloseFile(HANDLE hFile);

bool WINAPI SFileCloseFile(HANDLE hFile)
{
    TMPQFile * hf = (TMPQFile *)hFile;
    
    if(!IsValidFileHandle(hf))
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Free the structure
    FreeMPQFile(hf);
    return true;
}
