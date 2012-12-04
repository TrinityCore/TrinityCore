/*****************************************************************************/
/* SFileOpenArchive.cpp                       Copyright Ladislav Zezula 1999 */
/*                                                                           */
/* Author : Ladislav Zezula                                                  */
/* E-mail : ladik@zezula.net                                                 */
/* WWW    : www.zezula.net                                                   */
/*---------------------------------------------------------------------------*/
/*                       Archive functions of Storm.dll                      */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.xx  1.00  Lad  The first version of SFileOpenArchive.cpp            */
/* 19.11.03  1.01  Dan  Big endian handling                                  */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

static bool IsAviFile(void * pvFileBegin)
{
    LPDWORD AviHeader = (DWORD *)pvFileBegin;
    DWORD DwordValue0 = BSWAP_INT32_UNSIGNED(AviHeader[0]);
    DWORD DwordValue2 = BSWAP_INT32_UNSIGNED(AviHeader[2]);
    DWORD DwordValue3 = BSWAP_INT32_UNSIGNED(AviHeader[3]);

    // Test for 'RIFF', 'AVI ' or 'LIST'
    return (DwordValue0 == 0x46464952 && DwordValue2 == 0x20495641 && DwordValue3 == 0x5453494C);
}

static TFileBitmap * CreateFileBitmap(TMPQArchive * ha, TMPQBitmap * pMpqBitmap, bool bFileIsComplete)
{
    TFileBitmap * pBitmap;
    size_t nLength;

    // Calculate the length of the bitmap in blocks and in bytes
    nLength = (size_t)(((ha->pHeader->ArchiveSize64 - 1) / pMpqBitmap->dwBlockSize) + 1);
    nLength = (size_t)(((nLength - 1) / 8) + 1);

    // Allocate the file bitmap
    pBitmap = (TFileBitmap *)STORM_ALLOC(BYTE, sizeof(TFileBitmap) + nLength);
    if(pBitmap != NULL)
    {
        // Fill the structure
        pBitmap->StartOffset = ha->MpqPos;
        pBitmap->EndOffset = ha->MpqPos + ha->pHeader->ArchiveSize64;
        pBitmap->IsComplete = bFileIsComplete ? 1 : 0;
        pBitmap->BitmapSize = (DWORD)nLength;
        pBitmap->BlockSize = pMpqBitmap->dwBlockSize;
        pBitmap->Reserved = 0;

        // Copy the file bitmap
        memcpy((pBitmap + 1), (pMpqBitmap + 1), nLength);
    }

    return pBitmap;
}

// This function gets the right positions of the hash table and the block table.
static int VerifyMpqTablePositions(TMPQArchive * ha, ULONGLONG FileSize)
{
    TMPQHeader * pHeader = ha->pHeader;
    ULONGLONG ByteOffset;

    // Check the begin of HET table
    if(pHeader->HetTablePos64)
    {
        ByteOffset = ha->MpqPos + pHeader->HetTablePos64;
        if(ByteOffset > FileSize)
            return ERROR_BAD_FORMAT;
    }

    // Check the begin of BET table
    if(pHeader->BetTablePos64)
    {
        ByteOffset = ha->MpqPos + pHeader->BetTablePos64;
        if(ByteOffset > FileSize)
            return ERROR_BAD_FORMAT;
    }

    // Check the begin of hash table
    if(pHeader->wHashTablePosHi || pHeader->dwHashTablePos)
    {
        ByteOffset = ha->MpqPos + MAKE_OFFSET64(pHeader->wHashTablePosHi, pHeader->dwHashTablePos);
        if(ByteOffset > FileSize)
            return ERROR_BAD_FORMAT;
    }

    // Check the begin of block table
    if(pHeader->wBlockTablePosHi || pHeader->dwBlockTablePos)
    {
        ByteOffset = ha->MpqPos + MAKE_OFFSET64(pHeader->wBlockTablePosHi, pHeader->dwBlockTablePos);
        if(ByteOffset > FileSize)
            return ERROR_BAD_FORMAT;
    }

    // Check the begin of hi-block table
    if(pHeader->HiBlockTablePos64 != 0)
    {
        ByteOffset = ha->MpqPos + pHeader->HiBlockTablePos64;
        if(ByteOffset > FileSize)
            return ERROR_BAD_FORMAT;
    }

    // All OK.
    return ERROR_SUCCESS;
}


/*****************************************************************************/
/* Public functions                                                          */
/*****************************************************************************/

//-----------------------------------------------------------------------------
// SFileGetLocale and SFileSetLocale
// Set the locale for all newly opened files

LCID WINAPI SFileGetLocale()
{
    return lcFileLocale;
}

LCID WINAPI SFileSetLocale(LCID lcNewLocale)
{
    lcFileLocale = lcNewLocale;
    return lcFileLocale;
}

//-----------------------------------------------------------------------------
// SFileOpenArchive
//
//   szFileName - MPQ archive file name to open
//   dwPriority - When SFileOpenFileEx called, this contains the search priority for searched archives
//   dwFlags    - See MPQ_OPEN_XXX in StormLib.h
//   phMpq      - Pointer to store open archive handle

bool WINAPI SFileOpenArchive(
    const TCHAR * szMpqName,
    DWORD dwPriority,
    DWORD dwFlags,
    HANDLE * phMpq)
{
    TFileStream * pStream = NULL;       // Open file stream
    TMPQArchive * ha = NULL;            // Archive handle
    ULONGLONG FileSize = 0;             // Size of the file
    int nError = ERROR_SUCCESS;   

    // Verify the parameters
    if(szMpqName == NULL || *szMpqName == 0 || phMpq == NULL)
        nError = ERROR_INVALID_PARAMETER;

    // One time initialization of MPQ cryptography
    InitializeMpqCryptography();
    dwPriority = dwPriority;

    // Open the MPQ archive file
    if(nError == ERROR_SUCCESS)
    {
        // Initialize the stream
        pStream = FileStream_OpenFile(szMpqName, (dwFlags & STREAM_OPTIONS_MASK));
        if(pStream == NULL)
            nError = GetLastError();
    }
    
    // Allocate the MPQhandle
    if(nError == ERROR_SUCCESS)
    {
        FileStream_GetSize(pStream, FileSize);
        if((ha = STORM_ALLOC(TMPQArchive, 1)) == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Initialize handle structure and allocate structure for MPQ header
    if(nError == ERROR_SUCCESS)
    {
        memset(ha, 0, sizeof(TMPQArchive));
        ha->pStream = pStream;
        pStream = NULL;

        // Remember if the archive is open for write
        if(FileStream_IsReadOnly(ha->pStream))
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;

        // Also remember if we shall check sector CRCs when reading file
        if(dwFlags & MPQ_OPEN_CHECK_SECTOR_CRC)
            ha->dwFlags |= MPQ_FLAG_CHECK_SECTOR_CRC;
    }

    // Find the offset of MPQ header within the file
    if(nError == ERROR_SUCCESS)
    {
        ULONGLONG SearchPos = 0;
        DWORD dwHeaderID;

        while(SearchPos < FileSize)
        {
            DWORD dwBytesAvailable = MPQ_HEADER_SIZE_V4;

            // Cut the bytes available, if needed
            if((FileSize - SearchPos) < MPQ_HEADER_SIZE_V4)
                dwBytesAvailable = (DWORD)(FileSize - SearchPos);

            // Read the eventual MPQ header
            if(!FileStream_Read(ha->pStream, &SearchPos, ha->HeaderData, dwBytesAvailable))
            {
                nError = GetLastError();
                break;
            }

            // There are AVI files from Warcraft III with 'MPQ' extension.
            if(SearchPos == 0 && IsAviFile(ha->HeaderData))
            {
                nError = ERROR_AVI_FILE;
                break;
            }

            // If there is the MPQ user data signature, process it
            dwHeaderID = BSWAP_INT32_UNSIGNED(*(LPDWORD)ha->HeaderData);
            if(dwHeaderID == ID_MPQ_USERDATA && ha->pUserData == NULL)
            {
                // Ignore the MPQ user data completely if the caller wants to open the MPQ as V1.0
                if((dwFlags & MPQ_OPEN_FORCE_MPQ_V1) == 0)
                {
                    // Fill the user data header
                    ha->pUserData = &ha->UserData;
                    memcpy(ha->pUserData, ha->HeaderData, sizeof(TMPQUserData));
                    BSWAP_TMPQUSERDATA(ha->pUserData);

                    // Remember the position of the user data and continue search
                    ha->UserDataPos = SearchPos;
                    SearchPos += ha->pUserData->dwHeaderOffs;
                    continue;
                }
            }

            // There must be MPQ header signature
            if(dwHeaderID == ID_MPQ)
            {
                // Save the position where the MPQ header has been found
                if(ha->pUserData == NULL)
                    ha->UserDataPos = SearchPos;
                ha->pHeader = (TMPQHeader *)ha->HeaderData;
                ha->MpqPos = SearchPos;

                // Now convert the header to version 4
                BSWAP_TMPQHEADER(ha->pHeader);
                nError = ConvertMpqHeaderToFormat4(ha, FileSize, dwFlags);
                break;
            }

            // Move to the next possible offset
            SearchPos += 0x200;
        }

        // If we haven't found MPQ header in the file, it's an error
        if(ha->pHeader == NULL)
            nError = ERROR_BAD_FORMAT;
    }

    // Fix table positions according to format
    if(nError == ERROR_SUCCESS)
    {
        // Dump the header
//      DumpMpqHeader(ha->pHeader);

        // W3x Map Protectors use the fact that War3's Storm.dll ignores the MPQ user data,
        // and probably ignores the MPQ format version as well. The trick is to
        // fake MPQ format 2, with an improper hi-word position of hash table and block table
        // We can overcome such protectors by forcing opening the archive as MPQ v 1.0
        if(dwFlags & MPQ_OPEN_FORCE_MPQ_V1)
        {
            ha->pHeader->wFormatVersion = MPQ_FORMAT_VERSION_1;
            ha->pHeader->dwHeaderSize = MPQ_HEADER_SIZE_V1;
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;
            ha->pUserData = NULL;
        }

        // Both MPQ_OPEN_NO_LISTFILE or MPQ_OPEN_NO_ATTRIBUTES trigger read only mode
        if(dwFlags & (MPQ_OPEN_NO_LISTFILE | MPQ_OPEN_NO_ATTRIBUTES))
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;

        // Set the size of file sector
        ha->dwSectorSize = (0x200 << ha->pHeader->wSectorSize);

        // Verify if any of the tables doesn't start beyond the end of the file
        nError = VerifyMpqTablePositions(ha, FileSize);
    }

    // Check if the MPQ has data bitmap. If yes, we can verify if the MPQ is complete
    if(nError == ERROR_SUCCESS && ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_4)
    {
        TFileBitmap * pBitmap;
        bool bFileIsComplete = true;

        LoadMpqDataBitmap(ha, FileSize, &bFileIsComplete);
        if(ha->pBitmap != NULL && bFileIsComplete == false)
        {
            // Convert the MPQ bitmap to the file bitmap
            pBitmap = CreateFileBitmap(ha, ha->pBitmap, bFileIsComplete);

            // Set the data bitmap into the file stream for additional checks
            FileStream_SetBitmap(ha->pStream, pBitmap);
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;
        }
    }

    // Read the hash table. Ignore the result, as hash table is no longer required
    // Read HET table. Ignore the result, as HET table is no longer required
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadAnyHashTable(ha);
    }

    // Now, build the file table. It will be built by combining
    // the block table, BET table, hi-block table, (attributes) and (listfile).
    if(nError == ERROR_SUCCESS)
    {
        nError = BuildFileTable(ha, FileSize);
    }

    // Verify the file table, if no kind of protection was detected
    if(nError == ERROR_SUCCESS && (ha->dwFlags & MPQ_FLAG_PROTECTED) == 0)
    {
        TFileEntry * pFileTableEnd = ha->pFileTable + ha->pHeader->dwBlockTableSize;
        TFileEntry * pFileEntry = ha->pFileTable;
//      ULONGLONG ArchiveSize = 0;
        ULONGLONG RawFilePos;

        // Parse all file entries
        for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++)
        {
            // If that file entry is valid, check the file position
            if(pFileEntry->dwFlags & MPQ_FILE_EXISTS)
            {
                // Get the 64-bit file position,
                // relative to the begin of the file
                RawFilePos = ha->MpqPos + pFileEntry->ByteOffset;

                // Begin of the file must be within range
                if(RawFilePos > FileSize)
                {
                    nError = ERROR_FILE_CORRUPT;
                    break;
                }

                // End of the file must be within range
                RawFilePos += pFileEntry->dwCmpSize;
                if(RawFilePos > FileSize)
                {
                    nError = ERROR_FILE_CORRUPT;
                    break;
                }

                // Also, we remember end of the file
//              if(RawFilePos > ArchiveSize)
//                  ArchiveSize = RawFilePos;
            }
        }
    }

    // Load the internal listfile and include it to the file table
    if(nError == ERROR_SUCCESS && (dwFlags & MPQ_OPEN_NO_LISTFILE) == 0)
    {
        // Ignore result of the operation. (listfile) is optional.
        SFileAddListFile((HANDLE)ha, NULL);
    }

    // Load the "(attributes)" file and merge it to the file table
    if(nError == ERROR_SUCCESS && (dwFlags & MPQ_OPEN_NO_ATTRIBUTES) == 0)
    {
        // Ignore result of the operation. (attributes) is optional.
        SAttrLoadAttributes(ha);
    }

    // Cleanup and exit
    if(nError != ERROR_SUCCESS)
    {
        FileStream_Close(pStream);
        FreeMPQArchive(ha);
        SetLastError(nError);
        ha = NULL;
    }

    *phMpq = ha;
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// SFileGetArchiveBitmap

bool WINAPI SFileGetArchiveBitmap(HANDLE hMpq, TFileBitmap * pBitmap, DWORD Length, LPDWORD LengthNeeded)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    return FileStream_GetBitmap(ha->pStream, pBitmap, Length, LengthNeeded);
}

//-----------------------------------------------------------------------------
// bool SFileFlushArchive(HANDLE hMpq)
//
// Saves all dirty data into MPQ archive.
// Has similar effect like SFileCloseArchive, but the archive is not closed.
// Use on clients who keep MPQ archive open even for write operations,
// and terminating without calling SFileCloseArchive might corrupt the archive.
//

bool WINAPI SFileFlushArchive(HANDLE hMpq)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    int nResultError = ERROR_SUCCESS;
    int nError;

    // Do nothing if 'hMpq' is bad parameter
    if(!IsValidMpqHandle(ha))
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // If the (listfile) has been invalidated, save it
    if(ha->dwFlags & MPQ_FLAG_INV_LISTFILE)
    {
        nError = SListFileSaveToMpq(ha);
        if(nError != ERROR_SUCCESS)
            nResultError = nError;
    }

    // If the (attributes) has been invalidated, save it
    if(ha->dwFlags & MPQ_FLAG_INV_ATTRIBUTES)
    {
        nError = SAttrFileSaveToMpq(ha);
        if(nError != ERROR_SUCCESS)
            nResultError = nError;
    }

    // Save HET table, BET table, hash table, block table, hi-block table
    if(ha->dwFlags & MPQ_FLAG_CHANGED)
    {
        nError = SaveMPQTables(ha);
        if(nError != ERROR_SUCCESS)
            nResultError = nError;
    }

    // Return the error
    if(nResultError != ERROR_SUCCESS)
        SetLastError(nResultError);
    return (nResultError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// bool SFileCloseArchive(HANDLE hMpq);
//

bool WINAPI SFileCloseArchive(HANDLE hMpq)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    bool bResult;

    // Flush all unsaved data to the storage
    bResult = SFileFlushArchive(hMpq);

    // Free all memory used by MPQ archive
    FreeMPQArchive(ha);
    return bResult;
}

