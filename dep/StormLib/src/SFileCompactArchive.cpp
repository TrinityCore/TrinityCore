/*****************************************************************************/
/* SFileCompactArchive.cpp                Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Archive compacting function                                               */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 14.04.03  1.00  Lad  Splitted from SFileCreateArchiveEx.cpp               */
/* 19.11.03  1.01  Dan  Big endian handling                                  */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

/*****************************************************************************/
/* Local variables                                                           */
/*****************************************************************************/

static SFILE_COMPACT_CALLBACK CompactCB = NULL;
static ULONGLONG CompactBytesProcessed = 0;
static ULONGLONG CompactTotalBytes = 0;
static void * pvUserData = NULL;

/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

static int CheckIfAllFilesKnown(TMPQArchive * ha, const char * szListFile, LPDWORD pFileKeys)
{
    TFileEntry * pFileTableEnd;
    TFileEntry * pFileEntry;
    DWORD dwBlockIndex = 0;
    int nError = ERROR_SUCCESS;

    // Add the listfile to the MPQ
    if(nError == ERROR_SUCCESS && szListFile != NULL)
    {
        // Notify the user
        if(CompactCB != NULL)
            CompactCB(pvUserData, CCB_CHECKING_FILES, CompactBytesProcessed, CompactTotalBytes);

        nError = SFileAddListFile((HANDLE)ha, szListFile);
    }

    // Verify the file table
    if(nError == ERROR_SUCCESS)
    {
        pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
        for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++, dwBlockIndex++)
        {
            if(pFileEntry->dwFlags & MPQ_FILE_EXISTS)
            {
                if(pFileEntry->szFileName != NULL && !IsPseudoFileName(pFileEntry->szFileName, NULL))
                {
                    DWORD dwFileKey = 0;

                    // Resolve the file key. Use plain file name for it
                    if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
                    {
                        dwFileKey = DecryptFileKey(pFileEntry->szFileName,
                                                   pFileEntry->ByteOffset,
                                                   pFileEntry->dwFileSize,
                                                   pFileEntry->dwFlags);
                    }

                    // Give the key to the caller
                    if(pFileKeys != NULL)
                        pFileKeys[dwBlockIndex] = dwFileKey;
                }
                else
                {
                    nError = ERROR_CAN_NOT_COMPLETE;
                    break;
                }
            }
        }
    }

    return nError;
}

static int CopyNonMpqData(
    TFileStream * pSrcStream,
    TFileStream * pTrgStream,
    ULONGLONG & ByteOffset,
    ULONGLONG & ByteCount)
{
    ULONGLONG DataSize = ByteCount;
    DWORD dwToRead;
    char DataBuffer[0x1000];
    int nError = ERROR_SUCCESS;

    // Copy the data
    while(DataSize > 0)
    {
        // Get the proper size of data
        dwToRead = sizeof(DataBuffer);
        if(DataSize < dwToRead)
            dwToRead = (DWORD)DataSize;

        // Read from the source stream
        if(!FileStream_Read(pSrcStream, &ByteOffset, DataBuffer, dwToRead))
        {
            nError = GetLastError();
            break;
        }

        // Write to the target stream
        if(!FileStream_Write(pTrgStream, NULL, DataBuffer, dwToRead))
        {
            nError = GetLastError();
            break;
        }

        // Update the progress
        if(CompactCB != NULL)
        {
            CompactBytesProcessed += dwToRead;
            CompactCB(pvUserData, CCB_COPYING_NON_MPQ_DATA, CompactBytesProcessed, CompactTotalBytes);
        }

        // Decrement the number of data to be copied
        ByteOffset += dwToRead;
        DataSize -= dwToRead;
    }

    return ERROR_SUCCESS;
}

// Copies all file sectors into another archive.
static int CopyMpqFileSectors(
    TMPQArchive * ha,
    TMPQFile * hf,
    TFileStream * pNewStream)
{
    TFileEntry * pFileEntry = hf->pFileEntry;
    ULONGLONG RawFilePos;               // Used for calculating sector offset in the old MPQ archive
    ULONGLONG MpqFilePos;               // MPQ file position in the new archive
    DWORD dwBytesToCopy = pFileEntry->dwCmpSize;
    DWORD dwPatchSize = 0;              // Size of patch header
    DWORD dwFileKey1 = 0;               // File key used for decryption
    DWORD dwFileKey2 = 0;               // File key used for encryption
    DWORD dwCmpSize = 0;                // Compressed file size, including patch header
    int nError = ERROR_SUCCESS;

    // Remember the position in the destination file
    FileStream_GetPos(pNewStream, MpqFilePos);
    MpqFilePos -= ha->MpqPos;

    // Resolve decryption keys. Note that the file key given 
    // in the TMPQFile structure also includes the key adjustment
    if(nError == ERROR_SUCCESS && (pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED))
    {
        dwFileKey2 = dwFileKey1 = hf->dwFileKey;
        if(pFileEntry->dwFlags & MPQ_FILE_FIX_KEY)
        {
            dwFileKey2 = (dwFileKey1 ^ pFileEntry->dwFileSize) - (DWORD)pFileEntry->ByteOffset;
            dwFileKey2 = (dwFileKey2 + (DWORD)MpqFilePos) ^ pFileEntry->dwFileSize;
        }
    }

    // If we have to save patch header, do it
    if(nError == ERROR_SUCCESS && hf->pPatchInfo != NULL)
    {
        BSWAP_ARRAY32_UNSIGNED(hf->pPatchInfo, sizeof(DWORD) * 3);
        if(!FileStream_Write(pNewStream, NULL, hf->pPatchInfo, hf->pPatchInfo->dwLength))
            nError = GetLastError();

        // Save the size of the patch info
        dwPatchSize = hf->pPatchInfo->dwLength;
    }

    // If we have to save sector offset table, do it.
    if(nError == ERROR_SUCCESS && hf->SectorOffsets != NULL)
    {
        DWORD * SectorOffsetsCopy = (DWORD *)STORM_ALLOC(BYTE, hf->SectorOffsets[0]);
        DWORD dwSectorOffsLen = hf->SectorOffsets[0];

        assert((pFileEntry->dwFlags & MPQ_FILE_SINGLE_UNIT) == 0);
        assert(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED);

        if(SectorOffsetsCopy == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;

        // Encrypt the secondary sector offset table and write it to the target file
        if(nError == ERROR_SUCCESS)
        {
            memcpy(SectorOffsetsCopy, hf->SectorOffsets, dwSectorOffsLen);
            if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
                EncryptMpqBlock(SectorOffsetsCopy, dwSectorOffsLen, dwFileKey2 - 1);

            BSWAP_ARRAY32_UNSIGNED(SectorOffsetsCopy, dwSectorOffsLen);
            if(!FileStream_Write(pNewStream, NULL, SectorOffsetsCopy, dwSectorOffsLen))
                nError = GetLastError();

            dwBytesToCopy -= dwSectorOffsLen;
            dwCmpSize += dwSectorOffsLen;
        }

        // Update compact progress
        if(CompactCB != NULL)
        {
            CompactBytesProcessed += dwSectorOffsLen;
            CompactCB(pvUserData, CCB_COMPACTING_FILES, CompactBytesProcessed, CompactTotalBytes);
        }

        STORM_FREE(SectorOffsetsCopy);
    }

    // Now we have to copy all file sectors. We do it without
    // recompression, because recompression is not necessary in this case
    if(nError == ERROR_SUCCESS)
    {
        for(DWORD dwSector = 0; dwSector < hf->dwSectorCount; dwSector++)
        {
            DWORD dwRawDataInSector = hf->dwSectorSize;
            DWORD dwRawByteOffset = dwSector * hf->dwSectorSize;

            // Fix the raw data length if the file is compressed
            if(hf->SectorOffsets != NULL)
            {
                dwRawDataInSector = hf->SectorOffsets[dwSector+1] - hf->SectorOffsets[dwSector];
                dwRawByteOffset = hf->SectorOffsets[dwSector];
            }

            // Last sector: If there is not enough bytes remaining in the file, cut the raw size
            if(dwRawDataInSector > dwBytesToCopy)
                dwRawDataInSector = dwBytesToCopy;

            // Calculate the raw file offset of the file sector
            CalculateRawSectorOffset(RawFilePos, hf, dwRawByteOffset);
            
            // Read the file sector
            if(!FileStream_Read(ha->pStream, &RawFilePos, hf->pbFileSector, dwRawDataInSector))
            {
                nError = GetLastError();
                break;
            }

            // If necessary, re-encrypt the sector
            // Note: Recompression is not necessary here. Unlike encryption, 
            // the compression does not depend on the position of the file in MPQ.
            if((pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED) && dwFileKey1 != dwFileKey2)
            {
                BSWAP_ARRAY32_UNSIGNED(hf->pbFileSector, dwRawDataInSector);
                DecryptMpqBlock(hf->pbFileSector, dwRawDataInSector, dwFileKey1 + dwSector);
                EncryptMpqBlock(hf->pbFileSector, dwRawDataInSector, dwFileKey2 + dwSector);
                BSWAP_ARRAY32_UNSIGNED(hf->pbFileSector, dwRawDataInSector);
            }

            // Now write the sector back to the file
            if(!FileStream_Write(pNewStream, NULL, hf->pbFileSector, dwRawDataInSector))
            {
                nError = GetLastError();
                break;
            }

            // Update compact progress
            if(CompactCB != NULL)
            {
                CompactBytesProcessed += dwRawDataInSector;
                CompactCB(pvUserData, CCB_COMPACTING_FILES, CompactBytesProcessed, CompactTotalBytes);
            }

            // Adjust byte counts
            dwBytesToCopy -= dwRawDataInSector;
            dwCmpSize += dwRawDataInSector;
        }
    }

    // Copy the sector CRCs, if any
    // Sector CRCs are always compressed (not imploded) and unencrypted
    if(nError == ERROR_SUCCESS && hf->SectorOffsets != NULL && hf->SectorChksums != NULL)
    {
        DWORD dwCrcLength;

        dwCrcLength = hf->SectorOffsets[hf->dwSectorCount + 1] - hf->SectorOffsets[hf->dwSectorCount];
        if(dwCrcLength != 0)
        {
            if(!FileStream_Read(ha->pStream, NULL, hf->SectorChksums, dwCrcLength))
                nError = GetLastError();

            if(!FileStream_Write(pNewStream, NULL, hf->SectorChksums, dwCrcLength))
                nError = GetLastError();

            // Update compact progress
            if(CompactCB != NULL)
            {
                CompactBytesProcessed += dwCrcLength;
                CompactCB(pvUserData, CCB_COMPACTING_FILES, CompactBytesProcessed, CompactTotalBytes);
            }

            // Size of the CRC block is also included in the compressed file size
            dwBytesToCopy -= dwCrcLength;
            dwCmpSize += dwCrcLength;
        }
    }

    // There might be extra data beyond sector checksum table
    // Sometimes, these data are even part of sector offset table
    // Examples:
    // 2012 - WoW\15354\locale-enGB.MPQ:DBFilesClient\SpellLevels.dbc
    // 2012 - WoW\15354\locale-enGB.MPQ:Interface\AddOns\Blizzard_AuctionUI\Blizzard_AuctionUI.xml
    if(nError == ERROR_SUCCESS && dwBytesToCopy != 0)
    {
        LPBYTE pbExtraData;

        // Allocate space for the extra data
        pbExtraData = STORM_ALLOC(BYTE, dwBytesToCopy);
        if(pbExtraData != NULL)
        {
            if(!FileStream_Read(ha->pStream, NULL, pbExtraData, dwBytesToCopy))
                nError = GetLastError();

            if(!FileStream_Write(pNewStream, NULL, pbExtraData, dwBytesToCopy))
                nError = GetLastError();

            // Include these extra data in the compressed size
            dwCmpSize += dwBytesToCopy;
            dwBytesToCopy = 0;
            STORM_FREE(pbExtraData);
        }
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Write the MD5's of the raw file data, if needed
    if(nError == ERROR_SUCCESS && ha->pHeader->dwRawChunkSize != 0)
    {
        nError = WriteMpqDataMD5(pNewStream, 
                                 ha->MpqPos + MpqFilePos,
                                 pFileEntry->dwCmpSize,
                                 ha->pHeader->dwRawChunkSize);
    }

    // Update file position in the block table
    if(nError == ERROR_SUCCESS)
    {
        // At this point, number of bytes written should be exactly
        // the same like the compressed file size. If it isn't,
        // there's something wrong (an unknown archive version, MPQ protection, ...)
        // 
        // Note: Diablo savegames have very weird layout, and the file "hero"
        // seems to have improper compressed size. Instead of real compressed size,
        // the "dwCmpSize" member of the block table entry contains
        // uncompressed size of file data + size of the sector table.
        // If we compact the archive, Diablo will refuse to load the game
        // Seems like some sort of protection to me.
        //
        // Note: Some patch files in WOW patches don't count the patch header
        // into compressed size
        //

        if(dwCmpSize <= pFileEntry->dwCmpSize && pFileEntry->dwCmpSize <= dwCmpSize + dwPatchSize)
        {
            // Note: DO NOT update the compressed size in the file entry, no matter how bad it is.
            pFileEntry->ByteOffset = MpqFilePos;
        }
        else
        {
            nError = ERROR_FILE_CORRUPT;
            assert(false);
        }
    }

    return nError;
}

static int CopyMpqFiles(TMPQArchive * ha, LPDWORD pFileKeys, TFileStream * pNewStream)
{
    TFileEntry * pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
    TFileEntry * pFileEntry;
    TMPQFile * hf = NULL;
    int nError = ERROR_SUCCESS;

    // Walk through all files and write them to the destination MPQ archive
    for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++)
    {
        // Copy all the file sectors
        // Only do that when the file has nonzero size
        if((pFileEntry->dwFlags & MPQ_FILE_EXISTS) && pFileEntry->dwFileSize != 0)
        {
            // Allocate structure for the MPQ file
            hf = CreateMpqFile(ha);
            if(hf == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;

            // Store file entry
            hf->pFileEntry = pFileEntry;

            // Set the raw file position
            hf->MpqFilePos = pFileEntry->ByteOffset;
            hf->RawFilePos = ha->MpqPos + hf->MpqFilePos;

            // Set the file decryption key
            hf->dwFileKey = pFileKeys[pFileEntry - ha->pFileTable];
            hf->dwDataSize = pFileEntry->dwFileSize;

            // If the file is a patch file, load the patch header
            if(pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE)
            {
                nError = AllocatePatchInfo(hf, true);
                if(nError != ERROR_SUCCESS)
                    break;
            }

            // Allocate buffers for file sector and sector offset table
            nError = AllocateSectorBuffer(hf);
            if(nError != ERROR_SUCCESS)
                break;

            // Also allocate sector offset table and sector checksum table
            nError = AllocateSectorOffsets(hf, true);
            if(nError != ERROR_SUCCESS)
                break;

            // Also load sector checksums, if any
            if(pFileEntry->dwFlags & MPQ_FILE_SECTOR_CRC)
            {
                nError = AllocateSectorChecksums(hf, false);
                if(nError != ERROR_SUCCESS)
                    break;
            }

            // Copy all file sectors
            nError = CopyMpqFileSectors(ha, hf, pNewStream);
            if(nError != ERROR_SUCCESS)
                break;

            // Free buffers. This also sets "hf" to NULL.
            FreeMPQFile(hf);
        }
    }

    // Cleanup and exit
    if(hf != NULL)
        FreeMPQFile(hf);
    return nError;
}


/*****************************************************************************/
/* Public functions                                                          */
/*****************************************************************************/

bool WINAPI SFileSetCompactCallback(HANDLE /* hMpq */, SFILE_COMPACT_CALLBACK aCompactCB, void * pvData)
{
    CompactCB = aCompactCB;
    pvUserData = pvData;
    return true;
}

//-----------------------------------------------------------------------------
// Archive compacting

bool WINAPI SFileCompactArchive(HANDLE hMpq, const char * szListFile, bool /* bReserved */)
{
    TFileStream * pTempStream = NULL;
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    ULONGLONG ByteOffset;
    ULONGLONG ByteCount;
    LPDWORD pFileKeys = NULL;
    TCHAR szTempFile[MAX_PATH] = _T("");
    TCHAR * szTemp = NULL;
    int nError = ERROR_SUCCESS;

    // Test the valid parameters
    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_HANDLE;
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
        nError = ERROR_ACCESS_DENIED;

    // If the MPQ is changed at this moment, we have to flush the archive
    if(nError == ERROR_SUCCESS && (ha->dwFlags & MPQ_FLAG_CHANGED))
    {
        SFileFlushArchive(hMpq);
    }

    // Create the table with file keys
    if(nError == ERROR_SUCCESS)
    {
        if((pFileKeys = STORM_ALLOC(DWORD, ha->dwFileTableSize)) != NULL)
            memset(pFileKeys, 0, sizeof(DWORD) * ha->dwFileTableSize);
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // First of all, we have to check of we are able to decrypt all files.
    // If not, sorry, but the archive cannot be compacted.
    if(nError == ERROR_SUCCESS)
    {
        // Initialize the progress variables for compact callback
        FileStream_GetSize(ha->pStream, CompactTotalBytes);
        CompactBytesProcessed = 0;
        nError = CheckIfAllFilesKnown(ha, szListFile, pFileKeys);
    }

    // Get the temporary file name and create it
    if(nError == ERROR_SUCCESS)
    {
        _tcscpy(szTempFile, FileStream_GetFileName(ha->pStream));
        if((szTemp = _tcsrchr(szTempFile, '.')) != NULL)
            _tcscpy(szTemp + 1, _T("mp_"));
        else
            _tcscat(szTempFile, _T("_"));

        pTempStream = FileStream_CreateFile(szTempFile, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
        if(pTempStream == NULL)
            nError = GetLastError();
    }

    // Write the data before MPQ user data (if any)
    if(nError == ERROR_SUCCESS && ha->UserDataPos != 0)
    {
        // Inform the application about the progress
        if(CompactCB != NULL)
            CompactCB(pvUserData, CCB_COPYING_NON_MPQ_DATA, CompactBytesProcessed, CompactTotalBytes);

        ByteOffset = 0;
        ByteCount = ha->UserDataPos;
        nError = CopyNonMpqData(ha->pStream, pTempStream, ByteOffset, ByteCount);
    }

    // Write the MPQ user data (if any)
    if(nError == ERROR_SUCCESS && ha->MpqPos > ha->UserDataPos)
    {
        // At this point, we assume that the user data size is equal
        // to pUserData->dwHeaderOffs.
        // If this assumption doesn't work, then we have an unknown version of MPQ
        ByteOffset = ha->UserDataPos;
        ByteCount = ha->MpqPos - ha->UserDataPos;

        assert(ha->pUserData != NULL);
        assert(ha->pUserData->dwHeaderOffs == ByteCount);
        nError = CopyNonMpqData(ha->pStream, pTempStream, ByteOffset, ByteCount);
    }

    // Write the MPQ header
    if(nError == ERROR_SUCCESS)
    {
        // Remember the header size before swapping
        DWORD dwBytesToWrite = ha->pHeader->dwHeaderSize;

        BSWAP_TMPQHEADER(ha->pHeader);
        if(!FileStream_Write(pTempStream, NULL, ha->pHeader, dwBytesToWrite))
            nError = GetLastError();
        BSWAP_TMPQHEADER(ha->pHeader);

        // Update the progress
        CompactBytesProcessed += ha->pHeader->dwHeaderSize;
    }

    // Now copy all files
    if(nError == ERROR_SUCCESS)
    {
        nError = CopyMpqFiles(ha, pFileKeys, pTempStream);
        ha->dwFlags |= MPQ_FLAG_CHANGED;
    }

    // If succeeded, switch the streams
    if(nError == ERROR_SUCCESS)
    {
        if(FileStream_Switch(ha->pStream, pTempStream))
            pTempStream = NULL;
        else
            nError = ERROR_CAN_NOT_COMPLETE;
    }

    // If all succeeded, save the MPQ tables
    if(nError == ERROR_SUCCESS)
    {
        //
        // Note: We don't recalculate position of the MPQ tables at this point.
        // SaveMPQTables does it automatically.
        // 

        nError = SaveMPQTables(ha);
        if(nError == ERROR_SUCCESS && CompactCB != NULL)
        {
            CompactBytesProcessed += (ha->pHeader->dwHashTableSize * sizeof(TMPQHash));
            CompactBytesProcessed += (ha->pHeader->dwBlockTableSize * sizeof(TMPQBlock));
            CompactCB(pvUserData, CCB_CLOSING_ARCHIVE, CompactBytesProcessed, CompactTotalBytes);
        }
    }

    // Invalidate the compact callback
    pvUserData = NULL;
    CompactCB = NULL;

    // Cleanup and return
    if(pTempStream != NULL)
        FileStream_Close(pTempStream);
    if(pFileKeys != NULL)
        STORM_FREE(pFileKeys);
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// Changing hash table size

DWORD WINAPI SFileGetMaxFileCount(HANDLE hMpq)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    return ha->dwMaxFileCount;
}

bool WINAPI SFileSetMaxFileCount(HANDLE hMpq, DWORD dwMaxFileCount)
{
    TMPQHetTable * pOldHetTable = NULL;
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pOldFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
    TFileEntry * pOldFileTable = NULL;
    TFileEntry * pOldFileEntry;
    TFileEntry * pFileEntry;
    TMPQHash * pOldHashTable = NULL;
    DWORD dwOldHashTableSize = 0;
    DWORD dwOldFileTableSize = 0;
    int nError = ERROR_SUCCESS;

    // Test the valid parameters
    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_HANDLE;
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
        nError = ERROR_ACCESS_DENIED;

    // The new limit must not be lower than the index of the last file entry in the table
    if(nError == ERROR_SUCCESS && ha->dwFileTableSize > dwMaxFileCount)
        nError = ERROR_DISK_FULL;

    // ALL file names must be known in order to be able
    // to rebuild hash table size
    if(nError == ERROR_SUCCESS)
    {
        nError = CheckIfAllFilesKnown(ha, NULL, NULL);
    }

    // If the MPQ has a hash table, then we relocate the hash table
    if(nError == ERROR_SUCCESS && ha->pHashTable != NULL)
    {
        // Save parameters for the current hash table
        dwOldHashTableSize = ha->pHeader->dwHashTableSize;
        pOldHashTable = ha->pHashTable;

        // Allocate new hash table
        ha->pHeader->dwHashTableSize = GetHashTableSizeForFileCount(dwMaxFileCount);
        ha->pHashTable = STORM_ALLOC(TMPQHash, ha->pHeader->dwHashTableSize);
        if(ha->pHashTable != NULL)
            memset(ha->pHashTable, 0xFF, ha->pHeader->dwHashTableSize * sizeof(TMPQHash));
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // If the MPQ has HET table, allocate new one as well
    if(nError == ERROR_SUCCESS && ha->pHetTable != NULL)
    {
        // Save the original HET table
        pOldHetTable = ha->pHetTable;

        // Create new one
        ha->pHetTable = CreateHetTable(dwMaxFileCount, 0x40, true);
        if(ha->pHetTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Now reallocate the file table
    if(nError == ERROR_SUCCESS)
    {
        // Save the current file table
        dwOldFileTableSize = ha->dwFileTableSize;
        pOldFileTable = ha->pFileTable;

        // Create new one
        ha->pFileTable = STORM_ALLOC(TFileEntry, dwMaxFileCount);
        if(ha->pFileTable != NULL)
            memset(ha->pFileTable, 0, dwMaxFileCount * sizeof(TFileEntry));
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Now we have to build both classic hash table and HET table.
    if(nError == ERROR_SUCCESS)
    {
        DWORD dwFileIndex = 0;
        DWORD dwHashIndex = 0;

        // Create new hash and HET entry for each file
        pFileEntry = ha->pFileTable;
        for(pOldFileEntry = pOldFileTable; pOldFileEntry < pOldFileTableEnd; pOldFileEntry++)
        {
            if(pOldFileEntry->dwFlags & MPQ_FILE_EXISTS)
            {
                // Copy the old file entry to the new one
                memcpy(pFileEntry, pOldFileEntry, sizeof(TFileEntry));
                assert(pFileEntry->szFileName != NULL);
                
                // Create new entry in the hash table
                if(ha->pHashTable != NULL)
                {
                    dwHashIndex = AllocateHashEntry(ha, pFileEntry);
                    if(dwHashIndex == HASH_ENTRY_FREE)
                    {
                        nError = ERROR_CAN_NOT_COMPLETE;
                        break;
                    }
                }

                // Create new entry in the HET table, if needed
                if(ha->pHetTable != NULL)
                {
                    dwHashIndex = AllocateHetEntry(ha, pFileEntry);
                    if(dwHashIndex == HASH_ENTRY_FREE)
                    {
                        nError = ERROR_CAN_NOT_COMPLETE;
                        break;
                    }
                }

                // Move to the next file entry in the new table
                pFileEntry++;
                dwFileIndex++;
            }
        }
    }

    // Mark the archive as changed
    // Note: We always have to rebuild the (attributes) file due to file table change
    if(nError == ERROR_SUCCESS)
    {
        ha->dwMaxFileCount = dwMaxFileCount;
        InvalidateInternalFiles(ha);
    }
    else
    {
        // Revert the hash table
        if(ha->pHashTable != NULL && pOldHashTable != NULL)
        {
            STORM_FREE(ha->pHashTable);
            ha->pHeader->dwHashTableSize = dwOldHashTableSize;
            ha->pHashTable = pOldHashTable;
        }

        // Revert the HET table
        if(ha->pHetTable != NULL && pOldHetTable != NULL)
        {
            FreeHetTable(ha->pHetTable);
            ha->pHetTable = pOldHetTable;
        }

        // Revert the file table
        if(pOldFileTable != NULL)
        {
            STORM_FREE(ha->pFileTable);
            ha->pFileTable = pOldFileTable;
        }

        SetLastError(nError);
    }

    // Return the result
    return (nError == ERROR_SUCCESS);
}
