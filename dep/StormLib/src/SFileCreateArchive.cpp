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
    TFileStream * pStream = NULL;           // File stream
    TMPQArchive * ha = NULL;                // MPQ archive handle
    ULONGLONG MpqPos = 0;                   // Position of MPQ header in the file
    HANDLE hMpq = NULL;
    USHORT wFormatVersion = MPQ_FORMAT_VERSION_1;
    DWORD dwBlockTableSize = 0;             // Initial block table size
    DWORD dwHashTableSize = 0;
    int nError = ERROR_SUCCESS;

    // Check the parameters, if they are valid
    if(szMpqName == NULL || *szMpqName == 0 || phMpq == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // One time initialization of MPQ cryptography
    InitializeMpqCryptography();

    // We verify if the file already exists and if it's a MPQ archive.
    // If yes, we won't allow to overwrite it.
    if(SFileOpenArchive(szMpqName, 0, dwFlags, &hMpq))
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

    pStream = FileStream_OpenFile(szMpqName, true);
    if(pStream == NULL)
    {
        pStream = FileStream_CreateFile(szMpqName);
        if(pStream == NULL)
            return false;
    }

    // Decide what format to use
    wFormatVersion = (USHORT)((dwFlags & MPQ_CREATE_ARCHIVE_VMASK) >> 16);
    if(wFormatVersion > MPQ_FORMAT_VERSION_4)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Increment the maximum amount of files to have space
    // for listfile and attributes file
    if(dwFlags & MPQ_CREATE_ATTRIBUTES)
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
        ha->dwSectorSize    = (wFormatVersion >= MPQ_FORMAT_VERSION_3) ? 0x4000 : 0x1000;
        ha->UserDataPos     = MpqPos;
        ha->MpqPos          = MpqPos;
        ha->pHeader         = (TMPQHeader *)ha->HeaderData;
        ha->dwMaxFileCount  = dwMaxFileCount;
        ha->dwFileTableSize = 0;
        ha->dwFileFlags1    = MPQ_FILE_ENCRYPTED | MPQ_FILE_COMPRESS |  MPQ_FILE_REPLACEEXISTING;
        ha->dwFileFlags2    = MPQ_FILE_ENCRYPTED | MPQ_FILE_COMPRESS |  MPQ_FILE_REPLACEEXISTING;
        ha->dwFlags         = 0;

        // Setup the attributes
        if(dwFlags & MPQ_CREATE_ATTRIBUTES)
            ha->dwAttrFlags = MPQ_ATTRIBUTE_CRC32 | MPQ_ATTRIBUTE_FILETIME | MPQ_ATTRIBUTE_MD5;
        pStream = NULL;
    }

    // Fill the MPQ header
    if(nError == ERROR_SUCCESS)
    {
        TMPQHeader * pHeader = ha->pHeader;

        // Fill the MPQ header
        memset(pHeader, 0, sizeof(ha->HeaderData));
        pHeader->dwID             = ID_MPQ;
        pHeader->dwHeaderSize     = MpqHeaderSizes[wFormatVersion];
        pHeader->dwArchiveSize    = pHeader->dwHeaderSize + dwHashTableSize * sizeof(TMPQHash);
        pHeader->wFormatVersion   = wFormatVersion;
        pHeader->wSectorSize      = GetSectorSizeShift(ha->dwSectorSize);
        pHeader->dwHashTablePos   = pHeader->dwHeaderSize;
        pHeader->dwHashTableSize  = dwHashTableSize;
        pHeader->dwBlockTablePos  = pHeader->dwHashTablePos + dwHashTableSize * sizeof(TMPQHash);
        pHeader->dwBlockTableSize = dwBlockTableSize;

        // For MPQs version 4 and higher, we set the size of raw data block
        // for calculating MD5
        if(wFormatVersion >= MPQ_FORMAT_VERSION_4)
            pHeader->dwRawChunkSize = 0x4000;

        // Write the naked MPQ header
        nError = WriteNakedMPQHeader(ha);

        // Remember that the (listfile) and (attributes) need to be saved
        ha->dwFlags |= MPQ_FLAG_CHANGED | MPQ_FLAG_INV_LISTFILE | MPQ_FLAG_INV_ATTRIBUTES;
    }

    // Create initial HET table, if the caller required an MPQ format 3.0 or newer
    if(nError == ERROR_SUCCESS && wFormatVersion >= MPQ_FORMAT_VERSION_3)
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
