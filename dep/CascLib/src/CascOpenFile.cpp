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
// TCascFile class functions

TCascFile::TCascFile(TCascStorage * ahs, PCASC_CKEY_ENTRY apCKeyEntry)
{
    // Reference the storage handle
    if((hs = ahs) != NULL)
        hs->AddRef();
    ClassName = CASC_MAGIC_FILE;

    FilePointer = 0;
    pCKeyEntry = apCKeyEntry;
    SpanCount = (pCKeyEntry->SpanCount != 0) ? pCKeyEntry->SpanCount : 1;
    bVerifyIntegrity = false;
    bDownloadFileIf = false;
    bCloseFileStream = false;
    bFreeCKeyEntries = false;

    // Allocate the array of file spans
    if((pFileSpan = CASC_ALLOC_ZERO<CASC_FILE_SPAN>(SpanCount)) != NULL)
    {
        InitFileSpans(pFileSpan, SpanCount);
        InitCacheStrategy();
    }
}

TCascFile::~TCascFile()
{
    // Free all stuff related to file spans
    if (pFileSpan != NULL)
    {
        PCASC_FILE_SPAN pSpanPtr = pFileSpan;

        for(DWORD i = 0; i < SpanCount; i++, pSpanPtr++)
        {
            // Close the span file stream if this is a local file
            if(bCloseFileStream)
                FileStream_Close(pSpanPtr->pStream);
            pSpanPtr->pStream = NULL;

            // Free the span frames
            CASC_FREE(pSpanPtr->pFrames);
        }

        CASC_FREE(pFileSpan);
    }

    // Free the CKey entries, if needed
    if(pCKeyEntry && bFreeCKeyEntries)
        delete [] pCKeyEntry;
    pCKeyEntry = NULL;

    // Free the file cache
    CASC_FREE(pbFileCache);

    // Close (dereference) the archive handle
    if(hs != NULL)
        hs = hs->Release();
    ClassName = 0;
}

DWORD TCascFile::OpenFileSpans(LPCTSTR szSpanList)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    for(DWORD i = 0; i < SpanCount; i++)
    {
        // Open the file span
        pFileSpan[i].pStream = pStream = FileStream_OpenFile(szSpanList, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
        if(pFileSpan[i].pStream == NULL)
        {
            dwErrCode = GetCascError();
            break;
        }

        // If succeeded, we assign the span to the 
        FileStream_GetSize(pStream, &FileSize);
        if((FileSize >> 0x1E) != 0)
        {
            dwErrCode = ERROR_NOT_SUPPORTED;
            break;
        }

        pCKeyEntry[i].EncodedSize = (DWORD)FileSize;
    }

    // Free the so-far-opened files
    if(dwErrCode != ERROR_SUCCESS)
    {
        for(DWORD i = 0; i < SpanCount; i++)
        {
            if(pFileSpan[i].pStream != NULL)
                FileStream_Close(pFileSpan[i].pStream);
            pFileSpan[i].pStream = NULL;
        }
    }

    return dwErrCode;
}

void TCascFile::InitFileSpans(PCASC_FILE_SPAN pSpans, DWORD dwSpanCount)
{
    ULONGLONG FileOffsetBits = 30;
    ULONGLONG FileOffsetMask = 0;
    ULONGLONG FileOffset = 0;

    // Initialize the file sizes. Note that if any of the spans has invalid size,
    // the entire file size will be set to CASC_INVALID_SIZE64.
    GetFileSpanInfo(pCKeyEntry, &ContentSize, &EncodedSize);

    // Resolve the file offset bits and file offset mask
    if(hs != NULL)
        FileOffsetBits = hs->FileOffsetBits;
    FileOffsetMask = ((ULONGLONG)1 << FileOffsetBits) - 1;

    // Add all span sizes
    for(DWORD i = 0; i < dwSpanCount; i++, pSpans++)
    {
        // Put the archive index and archive offset
        pSpans->ArchiveIndex = (DWORD)(pCKeyEntry[i].StorageOffset >> FileOffsetBits);
        pSpans->ArchiveOffs = (DWORD)(pCKeyEntry[i].StorageOffset & FileOffsetMask);

        // Add to the total encoded size
        if(ContentSize != CASC_INVALID_SIZE64)
        {
            pSpans->StartOffset = FileOffset;
            FileOffset = FileOffset + pCKeyEntry[i].ContentSize;
            pSpans->EndOffset = FileOffset;
        }
    }
}

void TCascFile::InitCacheStrategy()
{
    CacheStrategy = CascCacheLastFrame;
    FileCacheStart = FileCacheEnd = 0;
    pbFileCache = NULL;
}

//-----------------------------------------------------------------------------
// Local functions

static size_t GetSpanFileCount(LPTSTR szSpanList)
{
    LPTSTR szSpanPtr = szSpanList;
    size_t nSpanCount = 1;

    while(szSpanPtr[0] != 0)
    {
        // End of a file?
        if(szSpanPtr[0] == ';' && szSpanPtr[1] != 0)
        {
            szSpanPtr[0] = 0;
            nSpanCount++;
        }

        szSpanPtr++;
    }

    // Place an additional zero to make the list terminated by double EOS
    szSpanPtr[1] = 0;
    return nSpanCount;
}

PCASC_CKEY_ENTRY FindCKeyEntry_CKey(TCascStorage * hs, LPBYTE pbCKey, PDWORD PtrIndex)
{
    return (PCASC_CKEY_ENTRY)hs->CKeyMap.FindObject(pbCKey, PtrIndex);
}

PCASC_CKEY_ENTRY FindCKeyEntry_EKey(TCascStorage * hs, LPBYTE pbEKey, PDWORD PtrIndex)
{
    return (PCASC_CKEY_ENTRY)hs->EKeyMap.FindObject(pbEKey, PtrIndex);
}

bool OpenFileByCKeyEntry(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, DWORD dwOpenFlags, HANDLE * PtrFileHandle)
{
    TCascFile * hf = NULL;
    DWORD dwErrCode = ERROR_FILE_NOT_FOUND;

    // If the CKey entry is NULL, we consider the file non-existant
    if(pCKeyEntry != NULL)
    {
        // Create the file handle structure
        if((hf = new TCascFile(hs, pCKeyEntry)) != NULL)
        {
            hf->bVerifyIntegrity   = (dwOpenFlags & CASC_STRICT_DATA_CHECK)  ? true : false;
            hf->bDownloadFileIf    = (hs->dwFeatures & CASC_FEATURE_ONLINE)  ? true : false;
            hf->bOvercomeEncrypted = (dwOpenFlags & CASC_OVERCOME_ENCRYPTED) ? true : false;
            dwErrCode = ERROR_SUCCESS;
        }
        else
        {
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Give the output parameter, no matter what
    PtrFileHandle[0] = (HANDLE)hf;

    // Handle last error
    if(dwErrCode != ERROR_SUCCESS)
        SetCascError(dwErrCode);
    return (dwErrCode == ERROR_SUCCESS);
}

bool OpenLocalFile(LPCTSTR szFileName, DWORD dwOpenFlags, HANDLE * PtrFileHandle)
{
    PCASC_CKEY_ENTRY pCKeyEntry;
    TCascFile * hf = NULL;
    LPTSTR szSpanList;
    size_t nSpanCount;
    DWORD dwErrCode = ERROR_NOT_ENOUGH_MEMORY;

    // Create a copy of the file name. It is actually a file name list,
    // separated by comma (for supporting multi-span files)
    if((szSpanList = CascNewStr(szFileName, 1)) != NULL)
    {
        // Calculate the span count
        if((nSpanCount = GetSpanFileCount(szSpanList)) != 0 || nSpanCount > 0xFF)
        {
            // Allocate CKey array for the file. Each entry describes one file span
            if((pCKeyEntry = new CASC_CKEY_ENTRY[nSpanCount]) != NULL)
            {
                // Prepare the span count to the first item
                pCKeyEntry->SpanCount = (BYTE)nSpanCount;

                // Prepare the archive offset in each CKey entry
                for(size_t i = 0; i < nSpanCount; i++)
                    pCKeyEntry[i].StorageOffset = 0;

                // Create an instance of the TCascFile
                if((hf = new TCascFile(NULL, pCKeyEntry)) != NULL)
                {
                    // Prepare the structure
                    hf->bVerifyIntegrity   = (dwOpenFlags & CASC_STRICT_DATA_CHECK)  ? true : false;
                    hf->bOvercomeEncrypted = (dwOpenFlags & CASC_OVERCOME_ENCRYPTED) ? true : false;
                    hf->bCloseFileStream = true;

                    // Open all local file spans
                    dwErrCode = hf->OpenFileSpans(szSpanList);
                    if(dwErrCode != ERROR_SUCCESS)
                    {
                        delete hf;
                        hf = NULL;
                    }
                }
            }
        }
        else
        {
            dwErrCode = ERROR_INVALID_PARAMETER;
        }

        delete [] szSpanList;
    }

    // Give the output parameter, no matter what
    PtrFileHandle[0] = (HANDLE)hf;

    // Handle last error
    if(dwErrCode != ERROR_SUCCESS)
        SetCascError(dwErrCode);
    return (dwErrCode == ERROR_SUCCESS);
}

bool SetCacheStrategy(HANDLE hFile, CSTRTG CacheStrategy)
{
    TCascFile * hf;

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) != NULL)
    {
        // The cache must not be initialized yet
        if(hf->pbFileCache == NULL)
        {
            hf->CacheStrategy = CacheStrategy;
            return true;
        }
    }

    // Failed. This should never happen
    assert(false);
    return false;
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascOpenFile(HANDLE hStorage, const void * pvFileName, DWORD dwLocaleFlags, DWORD dwOpenFlags, HANDLE * PtrFileHandle)
{
    PCASC_CKEY_ENTRY pCKeyEntry = NULL;
    TCascStorage * hs;
    const char * szFileName;
    DWORD FileDataId = CASC_INVALID_ID;
    BYTE CKeyEKeyBuffer[MD5_HASH_SIZE];
    DWORD dwErrCode = ERROR_SUCCESS;

    // This parameter is not used
    CASCLIB_UNUSED(dwLocaleFlags);

    // Validate the storage handle
    hs = TCascStorage::IsValid(hStorage);
    if(hs == NULL)
    {
        SetCascError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Validate the other parameters
    if(PtrFileHandle == NULL)
    {
        SetCascError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Retrieve the CKey/EKey from the file name in different modes
    switch(dwOpenFlags & CASC_OPEN_TYPE_MASK)
    {
        case CASC_OPEN_BY_NAME:

            // The 'pvFileName' must be zero terminated ANSI file name
            szFileName = (const char *)pvFileName;
            if(szFileName == NULL || szFileName[0] == 0)
            {
                SetCascError(ERROR_INVALID_PARAMETER);
                return false;
            }

            // The first chance: Try to find the file by name (using the root handler)
            pCKeyEntry = hs->pRootHandler->GetFile(hs, szFileName);
            if(pCKeyEntry != NULL)
                break;

            // Second chance: If the file name is actually a file data id, we convert it to file data ID
            if(IsFileDataIdName(szFileName, FileDataId))
            {
                pCKeyEntry = hs->pRootHandler->GetFile(hs, FileDataId);
                if(pCKeyEntry != NULL)
                    break;
            }

            // Third chance: If the file name is a string representation of CKey/EKey, we try to query for CKey
            if(IsFileCKeyEKeyName(szFileName, CKeyEKeyBuffer))
            {
                pCKeyEntry = FindCKeyEntry_CKey(hs, CKeyEKeyBuffer);
                if(pCKeyEntry != NULL)
                    break;

                pCKeyEntry = FindCKeyEntry_EKey(hs, CKeyEKeyBuffer);
                if(pCKeyEntry != NULL)
                    break;
            }

            SetCascError(ERROR_FILE_NOT_FOUND);
            return false;

        case CASC_OPEN_BY_CKEY:

            // The 'pvFileName' must be a pointer to 16-byte CKey or EKey
            if(pvFileName == NULL)
            {
                SetCascError(ERROR_INVALID_PARAMETER);
                return false;
            }

            // Search the CKey map in order to find the CKey entry
            pCKeyEntry = FindCKeyEntry_CKey(hs, (LPBYTE)pvFileName);
            break;

        case CASC_OPEN_BY_EKEY:

            // The 'pvFileName' must be a pointer to 16-byte CKey or EKey
            if(pvFileName == NULL)
            {
                SetCascError(ERROR_INVALID_PARAMETER);
                return false;
            }

            // Search the CKey map in order to find the CKey entry
            pCKeyEntry = FindCKeyEntry_EKey(hs, (LPBYTE)pvFileName);
            break;

        case CASC_OPEN_BY_FILEID:

            // Retrieve the file CKey/EKey
            pCKeyEntry = hs->pRootHandler->GetFile(hs, CASC_FILE_DATA_ID_FROM_STRING(pvFileName));
            break;

        default:

            // Unknown open mode
            dwErrCode = ERROR_INVALID_PARAMETER;
            break;
    }

    // Perform the open operation
    return OpenFileByCKeyEntry(hs, pCKeyEntry, dwOpenFlags, PtrFileHandle);
}

bool WINAPI CascOpenLocalFile(LPCTSTR szFileName, DWORD dwOpenFlags, HANDLE * PtrFileHandle)
{
    // Verify parameters
    if(szFileName == NULL || szFileName[0] == 0 || PtrFileHandle == NULL)
    {
        SetCascError(ERROR_INVALID_PARAMETER);
        return false;
    }

    return OpenLocalFile(szFileName, dwOpenFlags, PtrFileHandle);
}

bool WINAPI CascCloseFile(HANDLE hFile)
{
    TCascFile * hf;

    hf = TCascFile::IsValid(hFile);
    if (hf != NULL)
    {
        delete hf;
        return true;
    }

    SetCascError(ERROR_INVALID_HANDLE);
    return false;
}

