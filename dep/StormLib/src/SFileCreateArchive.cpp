/*****************************************************************************/
/* SFileCreateArchive.cpp                 Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* MPQ Editing functions                                                     */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 24.03.03  1.00  Lad  Splitted from SFileOpenArchive.cpp                   */
/* 08.06.10  1.00  Lad  Renamed to SFileCreateArchive.cpp                    */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local variables

static const DWORD MpqHeaderSizes[] =
{
    MPQ_HEADER_SIZE_V1,
    MPQ_HEADER_SIZE_V2,
    MPQ_HEADER_SIZE_V3,
    MPQ_HEADER_SIZE_V4
};

//-----------------------------------------------------------------------------
// Local functions

static USHORT GetSectorSizeShift(DWORD dwSectorSize)
{
    USHORT wSectorSizeShift = 0;

    while(dwSectorSize > 0x200)
    {
        dwSectorSize >>= 1;
        wSectorSizeShift++;
    }

    return wSectorSizeShift;
}

static int WriteNakedMPQHeader(TMPQArchive * ha)
{
    TMPQHeader * pHeader = ha->pHeader;
    TMPQHeader Header;
    DWORD dwBytesToWrite = pHeader->dwHeaderSize;
    int nError = ERROR_SUCCESS;

    // Prepare the naked MPQ header
    memset(&Header, 0, sizeof(TMPQHeader));
    Header.dwID           = pHeader->dwID;
    Header.dwHeaderSize   = pHeader->dwHeaderSize;
    Header.dwArchiveSize  = pHeader->dwHeaderSize;
    Header.wFormatVersion = pHeader->wFormatVersion;
    Header.wSectorSize    = pHeader->wSectorSize;

    // Write it to the file
    BSWAP_TMPQHEADER(&Header);
    if(!FileStream_Write(ha->pStream, &ha->MpqPos, &Header, dwBytesToWrite))
        nError = GetLastError();

    return nError;
}

//-----------------------------------------------------------------------------
// Creates a new MPQ archive.

bool WINAPI SFileCreateArchive(const TCHAR * szMpqName, DWORD dwFlags, DWORD dwMaxFileCount, HANDLE * phMpq)
{
    SFILE_CREATE_MPQ CreateInfo;

    // Fill the create structure
    memset(&CreateInfo, 0, sizeof(SFILE_CREATE_MPQ));
    CreateInfo.cbSize         = sizeof(SFILE_CREATE_MPQ);
    CreateInfo.dwMpqVersion   = (dwFlags & MPQ_CREATE_ARCHIVE_VMASK) >> FLAGS_TO_FORMAT_SHIFT;
    CreateInfo.dwStreamFlags  = STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE;
    CreateInfo.dwAttrFlags    = (dwFlags & MPQ_CREATE_ATTRIBUTES) ? MPQ_ATTRIBUTE_ALL : 0;
    CreateInfo.dwSectorSize   = (CreateInfo.dwMpqVersion >= MPQ_FORMAT_VERSION_3) ? 0x4000 : 0x1000;
    CreateInfo.dwRawChunkSize = (CreateInfo.dwMpqVersion >= MPQ_FORMAT_VERSION_4) ? 0x4000 : 0;
    CreateInfo.dwMaxFileCount = dwMaxFileCount;
    return SFileCreateArchive2(szMpqName, &CreateInfo, phMpq);
}

bool WINAPI SFileCreateArchive2(const TCHAR * szMpqName, PSFILE_CREATE_MPQ pCreateInfo, HANDLE * phMpq)
{
    TFileStream * pStream = NULL;           // File stream
    TMPQArchive * ha = NULL;                // MPQ archive handle
    ULONGLONG MpqPos = 0;                   // Position of MPQ header in the file
    HANDLE hMpq = NULL;
    DWORD dwBlockTableSize = 0;             // Initial block table size
    DWORD dwHashTableSize = 0;
    DWORD dwMaxFileCount;
    int nError = ERROR_SUCCESS;

    // Check the parameters, if they are valid
    if(szMpqName == NULL || *szMpqName == 0 || pCreateInfo == NULL || phMpq == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Verify if all variables in SFILE_CREATE_MPQ are correct
    if((pCreateInfo->cbSize == 0 || pCreateInfo->cbSize > sizeof(SFILE_CREATE_MPQ)) ||
       (pCreateInfo->dwMpqVersion > MPQ_FORMAT_VERSION_4)                        ||
       (pCreateInfo->pvUserData != NULL || pCreateInfo->cbUserData != 0)            ||
       (pCreateInfo->dwAttrFlags & ~MPQ_ATTRIBUTE_ALL)                              ||
       (pCreateInfo->dwSectorSize & (pCreateInfo->dwSectorSize - 1))                ||
       (pCreateInfo->dwRawChunkSize & (pCreateInfo->dwRawChunkSize - 1))            ||
       (pCreateInfo->dwMaxFileCount < 4))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // One time initialization of MPQ cryptography
    InitializeMpqCryptography();

    // We verify if the file already exists and if it's a MPQ archive.
    // If yes, we won't allow to overwrite it.
    if(SFileOpenArchive(szMpqName, 0, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE | MPQ_OPEN_NO_ATTRIBUTES | MPQ_OPEN_NO_LISTFILE, &hMpq))
    {
        SFileCloseArchive(hMpq);
        SetLastError(ERROR_ALREADY_EXISTS);
        return false;
    }

    //
    // At this point, we have to create the archive.
    // - If the file exists, convert it to MPQ archive.
    // - If the file doesn't exist, create new empty file
    //

    pStream = FileStream_OpenFile(szMpqName, pCreateInfo->dwStreamFlags);
    if(pStream == NULL)
    {
        pStream = FileStream_CreateFile(szMpqName, pCreateInfo->dwStreamFlags);
        if(pStream == NULL)
            return false;
    }

    // Increment the maximum amount of files to have space
    // for listfile and attributes file
    dwMaxFileCount = pCreateInfo->dwMaxFileCount;
    if(pCreateInfo->dwAttrFlags != 0)
        dwMaxFileCount++;
    dwMaxFileCount++;

    // If file count is not zero, initialize the hash table size
    dwHashTableSize = GetHashTableSizeForFileCount(dwMaxFileCount);

    // Retrieve the file size and round it up to 0x200 bytes
    FileStream_GetSize(pStream, MpqPos);
    MpqPos = (MpqPos + 0x1FF) & (ULONGLONG)0xFFFFFFFFFFFFFE00ULL;
    if(!FileStream_SetSize(pStream, MpqPos))
        nError = GetLastError();

#ifdef _DEBUG    
    // Debug code, used for testing StormLib
//  dwBlockTableSize = dwHashTableSize * 2;
#endif

    // Create the archive handle
    if(nError == ERROR_SUCCESS)
    {
        if((ha = STORM_ALLOC(TMPQArchive, 1)) == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Fill the MPQ archive handle structure
    if(nError == ERROR_SUCCESS)
    {
        memset(ha, 0, sizeof(TMPQArchive));
        ha->pStream         = pStream;
        ha->dwSectorSize    = pCreateInfo->dwSectorSize;
        ha->UserDataPos     = MpqPos;
        ha->MpqPos          = MpqPos;
        ha->pHeader         = (TMPQHeader *)ha->HeaderData;
        ha->dwMaxFileCount  = dwMaxFileCount;
        ha->dwFileTableSize = 0;
        ha->dwFileFlags1    = pCreateInfo->dwFileFlags1;
        ha->dwFileFlags2    = pCreateInfo->dwFileFlags2;
        ha->dwFlags         = 0;

        // Setup the attributes
        ha->dwAttrFlags     = pCreateInfo->dwAttrFlags;
        pStream = NULL;
    }

    // Fill the MPQ header
    if(nError == ERROR_SUCCESS)
    {
        TMPQHeader * pHeader = ha->pHeader;

        // Fill the MPQ header
        memset(pHeader, 0, sizeof(ha->HeaderData));
        pHeader->dwID             = ID_MPQ;
        pHeader->dwHeaderSize     = MpqHeaderSizes[pCreateInfo->dwMpqVersion];
        pHeader->dwArchiveSize    = pHeader->dwHeaderSize + dwHashTableSize * sizeof(TMPQHash);
        pHeader->wFormatVersion   = (USHORT)pCreateInfo->dwMpqVersion;
        pHeader->wSectorSize      = GetSectorSizeShift(ha->dwSectorSize);
        pHeader->dwHashTablePos   = pHeader->dwHeaderSize;
        pHeader->dwHashTableSize  = dwHashTableSize;
        pHeader->dwBlockTablePos  = pHeader->dwHashTablePos + dwHashTableSize * sizeof(TMPQHash);
        pHeader->dwBlockTableSize = dwBlockTableSize;

        // For MPQs version 4 and higher, we set the size of raw data block
        // for calculating MD5
        if(pCreateInfo->dwMpqVersion >= MPQ_FORMAT_VERSION_4)
            pHeader->dwRawChunkSize = pCreateInfo->dwRawChunkSize;

        // Write the naked MPQ header
        nError = WriteNakedMPQHeader(ha);

        // Remember that the (listfile) and (attributes) need to be saved
        ha->dwFlags |= MPQ_FLAG_CHANGED | MPQ_FLAG_INV_LISTFILE | MPQ_FLAG_INV_ATTRIBUTES;
    }

    // Create initial HET table, if the caller required an MPQ format 3.0 or newer
    if(nError == ERROR_SUCCESS && pCreateInfo->dwMpqVersion >= MPQ_FORMAT_VERSION_3)
    {
        ha->pHetTable = CreateHetTable(ha->dwMaxFileCount, 0x40, true);
        if(ha->pHetTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Create initial hash table
    if(nError == ERROR_SUCCESS)
    {
        nError = CreateHashTable(ha, dwHashTableSize);
    }

    // Create initial file table
    if(nError == ERROR_SUCCESS)
    {
        ha->pFileTable = STORM_ALLOC(TFileEntry, ha->dwMaxFileCount);
        if(ha->pFileTable != NULL)
            memset(ha->pFileTable, 0x00, sizeof(TFileEntry) * ha->dwMaxFileCount);
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Cleanup : If an error, delete all buffers and return
    if(nError != ERROR_SUCCESS)
    {
        FileStream_Close(pStream);
        FreeMPQArchive(ha);
        SetLastError(nError);
        ha = NULL;
    }
    
    // Return the values
    *phMpq = (HANDLE)ha;
    return (nError == ERROR_SUCCESS);
}
