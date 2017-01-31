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
        pIndexEntry = (PCASC_INDEX_ENTRY)Map_FindObject(hs->pIndexEntryMap, pIndexKey->pbData, NULL);

    return pIndexEntry;
}

PCASC_ENCODING_ENTRY FindEncodingEntry(TCascStorage * hs, PQUERY_KEY pEncodingKey, PDWORD PtrIndex)
{
    PCASC_ENCODING_ENTRY pEncodingEntry = NULL;

    if(hs->pEncodingMap != NULL)
        pEncodingEntry = (PCASC_ENCODING_ENTRY)Map_FindObject(hs->pEncodingMap, pEncodingKey->pbData, PtrIndex);

    return pEncodingEntry;
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
    IndexKey.pbData = GET_INDEX_KEY(pEncodingEntry);
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
    TCascStorage * hs;
    QUERY_KEY EncodingKey;
    LPBYTE pbEncodingKey;
    BYTE KeyBuffer[MD5_HASH_SIZE];
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

    // If the user is opening the file via encoding key, skip the ROOT file processing
    if((dwFlags & CASC_OPEN_BY_ENCODING_KEY) == 0)
    {
        // Let the root directory provider get us the encoding key
        pbEncodingKey = RootHandler_GetKey(hs->pRootHandler, szFileName);
        if(pbEncodingKey == NULL)
        {
            SetLastError(ERROR_FILE_NOT_FOUND);
            return false;
        }

        // Setup the encoding key
        EncodingKey.pbData = pbEncodingKey;
        EncodingKey.cbData = MD5_HASH_SIZE;
    }
    else
    {
        // Check the length of the file name
        if(strlen(szFileName) < MD5_STRING_SIZE)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
        }

        // Convert the file name to binary blob
        EncodingKey.pbData = KeyBuffer;
        EncodingKey.cbData = MD5_HASH_SIZE;
        nError = ConvertStringToBinary(szFileName, MD5_STRING_SIZE, KeyBuffer);
    }

    // Use the encoding key to find the file in the encoding table entry
    if(nError == ERROR_SUCCESS)
    {
        if(!OpenFileByEncodingKey(hs, &EncodingKey, dwFlags, (TCascFile **)phFile))
        {
            assert(GetLastError() != ERROR_SUCCESS);
            nError = GetLastError();
        }
    }

#ifdef CASCLIB_TEST
//  if(phFile[0] != NULL && pRootEntryMndx != NULL)
//  {
//      ((TCascFile *)(phFile[0]))->FileSize_RootEntry = pRootEntryMndx->FileSize;
//  }
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

