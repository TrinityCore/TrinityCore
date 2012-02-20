/*****************************************************************************/
/* SFileAddFile.cpp                       Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* MPQ Editing functions                                                     */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 27.03.10  1.00  Lad  Splitted from SFileCreateArchiveEx.cpp               */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local variables

// Data compression for SFileAddFile
// Kept here for compatibility with code that was created with StormLib version < 6.50
static DWORD DefaultDataCompression = MPQ_COMPRESSION_PKWARE;

static SFILE_ADDFILE_CALLBACK AddFileCB = NULL;
static void * pvUserData = NULL;

//-----------------------------------------------------------------------------
// MPQ write data functions

#define LOSSY_COMPRESSION_MASK (MPQ_COMPRESSION_ADPCM_MONO | MPQ_COMPRESSION_ADPCM_STEREO | MPQ_COMPRESSION_HUFFMANN)

static int WriteDataToMpqFile(
    TMPQArchive * ha,
    TMPQFile * hf,
    LPBYTE pbFileData,
    DWORD dwDataSize,
    DWORD dwCompression)
{
    TFileEntry * pFileEntry = hf->pFileEntry;
    ULONGLONG ByteOffset;
    LPBYTE pbCompressed = NULL;         // Compressed (target) data
    LPBYTE pbToWrite = NULL;            // Data to write to the file
    int nCompressionLevel = -1;         // ADPCM compression level (only used for wave files)
    int nError = ERROR_SUCCESS;

    // If the caller wants ADPCM compression, we will set wave compression level to 4,
    // which corresponds to medium quality
    if(dwCompression & LOSSY_COMPRESSION_MASK)
        nCompressionLevel = 4;

    // Make sure that the caller won't overrun the previously initiated file size
    assert(hf->dwFilePos + dwDataSize <= pFileEntry->dwFileSize);
    assert(hf->dwSectorCount != 0);
    assert(hf->pbFileSector != NULL);
    if((hf->dwFilePos + dwDataSize) > pFileEntry->dwFileSize)
        return ERROR_DISK_FULL;
    pbToWrite = hf->pbFileSector;

    // Now write all data to the file sector buffer
    if(nError == ERROR_SUCCESS)
    {
        DWORD dwBytesInSector = hf->dwFilePos % hf->dwSectorSize;
        DWORD dwSectorIndex = hf->dwFilePos / hf->dwSectorSize;
        DWORD dwBytesToCopy;

        // Process all data. 
        while(dwDataSize != 0)
        {
            dwBytesToCopy = dwDataSize;
                
            // Check for sector overflow
            if(dwBytesToCopy > (hf->dwSectorSize - dwBytesInSector))
                dwBytesToCopy = (hf->dwSectorSize - dwBytesInSector);

            // Copy the data to the file sector
            memcpy(hf->pbFileSector + dwBytesInSector, pbFileData, dwBytesToCopy);
            dwBytesInSector += dwBytesToCopy;
            pbFileData += dwBytesToCopy;
            dwDataSize -= dwBytesToCopy;

            // Update the file position
            hf->dwFilePos += dwBytesToCopy;

            // If the current sector is full, or if the file is already full,
            // then write the data to the MPQ
            if(dwBytesInSector >= hf->dwSectorSize || hf->dwFilePos >= pFileEntry->dwFileSize)
            {
                // Set the position in the file
                ByteOffset = hf->RawFilePos + pFileEntry->dwCmpSize;

                // If the file is compressed, allocate buffer for the compressed data.
                // Note that we allocate buffer that is a bit longer than sector size,
                // for case if the compression method performs a buffer overrun
                if((pFileEntry->dwFlags & MPQ_FILE_COMPRESSED) && pbCompressed == NULL)
                {
                    pbToWrite = pbCompressed = STORM_ALLOC(BYTE, hf->dwSectorSize + 0x100);
                    if(pbCompressed == NULL)
                        nError = ERROR_NOT_ENOUGH_MEMORY;
                }

                // Update CRC32 and MD5 of the file
                md5_process((hash_state *)hf->hctx, hf->pbFileSector, dwBytesInSector);
                hf->dwCrc32 = crc32(hf->dwCrc32, hf->pbFileSector, dwBytesInSector);

                // Compress the file sector, if needed
                if(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED)
                {
                    int nOutBuffer = (int)dwBytesInSector;
                    int nInBuffer = (int)dwBytesInSector;

                    assert(pbCompressed != NULL);

                    //
                    // Note that both SCompImplode and SCompCompress give original buffer,
                    // if they are unable to comperss the data.
                    //

                    if(pFileEntry->dwFlags & MPQ_FILE_IMPLODE)
                    {
                        SCompImplode((char *)pbCompressed,
                                            &nOutBuffer,
                                     (char *)hf->pbFileSector,
                                             nInBuffer);
                    }

                    if(pFileEntry->dwFlags & MPQ_FILE_COMPRESS)
                    {
                        SCompCompress((char *)pbCompressed,
                                             &nOutBuffer,
                                      (char *)hf->pbFileSector,
                                              nInBuffer,
                                    (unsigned)dwCompression,
                                              0,
                                              nCompressionLevel);
                    }

                    // Update sector positions
                    dwBytesInSector = nOutBuffer;
                    if(hf->SectorOffsets != NULL)
                        hf->SectorOffsets[dwSectorIndex+1] = hf->SectorOffsets[dwSectorIndex] + dwBytesInSector;

                    // We have to calculate sector CRC, if enabled
                    if(hf->SectorChksums != NULL)
                        hf->SectorChksums[dwSectorIndex] = adler32(0, pbCompressed, nOutBuffer);
                }                 

                // Encrypt the sector, if necessary
                if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
                {
                    BSWAP_ARRAY32_UNSIGNED(pbToWrite, dwBytesInSector);
                    EncryptMpqBlock(pbToWrite, dwBytesInSector, hf->dwFileKey + dwSectorIndex);
                    BSWAP_ARRAY32_UNSIGNED(pbToWrite, dwBytesInSector);
                }

                // Write the file sector
                if(!FileStream_Write(ha->pStream, &ByteOffset, pbToWrite, dwBytesInSector))
                {
                    nError = GetLastError();
                    break;
                }

                // Call the compact callback, if any
                if(AddFileCB != NULL)
                    AddFileCB(pvUserData, hf->dwFilePos, hf->dwDataSize, false);

                // Update the compressed file size
                pFileEntry->dwCmpSize += dwBytesInSector;
                dwBytesInSector = 0;
                dwSectorIndex++;
            }
        }
    }

    // Cleanup
    if(pbCompressed != NULL)
        STORM_FREE(pbCompressed);
    return nError;
}

//-----------------------------------------------------------------------------
// Recrypts file data for file renaming

static int RecryptFileData(
    TMPQArchive * ha,
    TMPQFile * hf,
    const char * szFileName,
    const char * szNewFileName)
{
    ULONGLONG RawFilePos;
    TFileEntry * pFileEntry = hf->pFileEntry;
    DWORD dwBytesToRecrypt = pFileEntry->dwCmpSize;
    DWORD dwOldKey;
    DWORD dwNewKey;
    int nError = ERROR_SUCCESS;

    // The file must be encrypted
    assert(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED);

    // File decryption key is calculated from the plain name
    szNewFileName = GetPlainFileNameA(szNewFileName);
    szFileName = GetPlainFileNameA(szFileName);

    // Calculate both file keys
    dwOldKey = DecryptFileKey(szFileName,    pFileEntry->ByteOffset, pFileEntry->dwFileSize, pFileEntry->dwFlags);
    dwNewKey = DecryptFileKey(szNewFileName, pFileEntry->ByteOffset, pFileEntry->dwFileSize, pFileEntry->dwFlags);

    // Incase the keys are equal, don't recrypt the file
    if(dwNewKey == dwOldKey)
        return ERROR_SUCCESS;
    hf->dwFileKey = dwOldKey;

    // Calculate the raw position of the file in the archive
    hf->MpqFilePos = pFileEntry->ByteOffset;
    hf->RawFilePos = ha->MpqPos + hf->MpqFilePos;

    // Allocate buffer for file transfer
    nError = AllocateSectorBuffer(hf);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Also allocate buffer for sector offsets
    // Note: Don't load sector checksums, we don't need to recrypt them
    nError = AllocateSectorOffsets(hf, true);
    if(nError != ERROR_SUCCESS)
        return nError;

    // If we have sector offsets, recrypt these as well
    if(hf->SectorOffsets != NULL)
    {
        // Allocate secondary buffer for sectors copy
        DWORD * SectorOffsetsCopy = (DWORD *)STORM_ALLOC(BYTE, hf->SectorOffsets[0]);
        DWORD dwSectorOffsLen = hf->SectorOffsets[0];

        if(SectorOffsetsCopy == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Recrypt the array of sector offsets
        memcpy(SectorOffsetsCopy, hf->SectorOffsets, dwSectorOffsLen);
        EncryptMpqBlock(SectorOffsetsCopy, dwSectorOffsLen, dwNewKey - 1);
        BSWAP_ARRAY32_UNSIGNED(SectorOffsetsCopy, dwSectorOffsLen);

        // Write the recrypted array back
        if(!FileStream_Write(ha->pStream, &hf->RawFilePos, SectorOffsetsCopy, dwSectorOffsLen))
            nError = GetLastError();
        STORM_FREE(SectorOffsetsCopy);
    }

    // Now we have to recrypt all file sectors. We do it without
    // recompression, because recompression is not necessary in this case
    if(nError == ERROR_SUCCESS)
    {
        for(DWORD dwSector = 0; dwSector < hf->dwSectorCount; dwSector++)
        {
            DWORD dwRawDataInSector = hf->dwSectorSize;
            DWORD dwRawByteOffset = dwSector * hf->dwSectorSize;

            // Last sector: If there is not enough bytes remaining in the file, cut the raw size
            if(dwRawDataInSector > dwBytesToRecrypt)
                dwRawDataInSector = dwBytesToRecrypt;

            // Fix the raw data length if the file is compressed
            if(hf->SectorOffsets != NULL)
            {
                dwRawDataInSector = hf->SectorOffsets[dwSector+1] - hf->SectorOffsets[dwSector];
                dwRawByteOffset = hf->SectorOffsets[dwSector];
            }

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
            BSWAP_ARRAY32_UNSIGNED(hf->pbFileSector, dwRawDataInSector);
            DecryptMpqBlock(hf->pbFileSector, dwRawDataInSector, dwOldKey + dwSector);
            EncryptMpqBlock(hf->pbFileSector, dwRawDataInSector, dwNewKey + dwSector);
            BSWAP_ARRAY32_UNSIGNED(hf->pbFileSector, dwRawDataInSector);

            // Write the sector back
            if(!FileStream_Write(ha->pStream, &RawFilePos, hf->pbFileSector, dwRawDataInSector))
            {
                nError = GetLastError();
                break;
            }

            // Decrement number of bytes remaining
            dwBytesToRecrypt -= hf->dwSectorSize;
        }
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Support functions for adding files to the MPQ

int SFileAddFile_Init(
    TMPQArchive * ha,
    const char * szFileName,
    ULONGLONG FileTime,
    DWORD dwFileSize,
    LCID lcLocale,
    DWORD dwFlags,
    TMPQFile ** phf)
{
    TFileEntry * pFileEntry = NULL;
    ULONGLONG TempPos;                  // For various file offset calculations
    TMPQFile * hf = NULL;               // File structure for newly added file
    int nError = ERROR_SUCCESS;

    //
    // Note: This is an internal function so no validity checks are done.
    // It is the caller's responsibility to make sure that no invalid
    // flags get to this point
    //

    // Adjust file flags for too-small files
    if(dwFileSize < 0x04)
        dwFlags &= ~(MPQ_FILE_ENCRYPTED | MPQ_FILE_FIX_KEY);
    if(dwFileSize < 0x20)
        dwFlags &= ~(MPQ_FILE_COMPRESSED | MPQ_FILE_SECTOR_CRC);

    // If the MPQ is of version 3.0 or higher, we ignore file locale.
    // This is because HET and BET tables have no known support for it
    if(ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_3)
        lcLocale = 0;

    // Allocate the TMPQFile entry for newly added file
    hf = CreateMpqFile(ha);
    if(hf == NULL)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    // Find a free space in the MPQ, as well as free block table entry
    if(nError == ERROR_SUCCESS)
    {
        // Find the position where the file will be stored
        FindFreeMpqSpace(ha, &hf->MpqFilePos);
        hf->RawFilePos = ha->MpqPos + hf->MpqFilePos;
        hf->bIsWriteHandle = true;

        // Sanity check: The MPQ must be marked as changed at this point
        assert((ha->dwFlags & MPQ_FLAG_CHANGED) != 0);

        // When format V1, the size of the archive cannot exceed 4 GB
        if(ha->pHeader->wFormatVersion == MPQ_FORMAT_VERSION_1)
        {
            TempPos  = hf->MpqFilePos + dwFileSize;
            TempPos += ha->pHeader->dwHashTableSize * sizeof(TMPQHash);
            TempPos += ha->pHeader->dwBlockTableSize * sizeof(TMPQBlock);
            TempPos += ha->pHeader->dwBlockTableSize * sizeof(USHORT);
            if((TempPos >> 32) != 0)
                nError = ERROR_DISK_FULL;
        }
    }

    // Allocate file entry in the MPQ
    if(nError == ERROR_SUCCESS)
    {
        // Check if the file already exists in the archive
        pFileEntry = GetFileEntryExact(ha, szFileName, lcLocale);
        if(pFileEntry == NULL)
        {
            pFileEntry = AllocateFileEntry(ha, szFileName, lcLocale);
            if(pFileEntry == NULL)
                nError = ERROR_DISK_FULL;
        }
        else
        {
            // If the file is marked as deleted, it's OK
            if(!(pFileEntry->dwFlags & MPQ_FILE_DELETE_MARKER))
            {
                if((dwFlags & MPQ_FILE_REPLACEEXISTING) == 0)
                    nError = ERROR_ALREADY_EXISTS;
            }

            // If the file entry already contains a file
            // and it is a pseudo-name, replace it
            if(nError == ERROR_SUCCESS)
            {
                AllocateFileName(pFileEntry, szFileName);
            }
        }
    }

    //
    // At this point, the file name in file entry must be non-NULL
    //

    // Create key for file encryption
    if(nError == ERROR_SUCCESS && (dwFlags & MPQ_FILE_ENCRYPTED))
    {
        hf->dwFileKey = DecryptFileKey(szFileName, hf->MpqFilePos, dwFileSize, dwFlags);
    }

    if(nError == ERROR_SUCCESS)
    {
        // Initialize the hash entry for the file
        hf->pFileEntry = pFileEntry;
        hf->dwDataSize = dwFileSize;

        // Initialize the block table entry for the file
        pFileEntry->ByteOffset = hf->MpqFilePos;
        pFileEntry->dwFileSize = dwFileSize;
        pFileEntry->dwCmpSize = 0;
        pFileEntry->dwFlags  = dwFlags | MPQ_FILE_EXISTS;
        pFileEntry->lcLocale = (USHORT)lcLocale;

        // Initialize the file time, CRC32 and MD5
        assert(sizeof(hf->hctx) >= sizeof(hash_state));
        memset(pFileEntry->md5, 0, MD5_DIGEST_SIZE);
        md5_init((hash_state *)hf->hctx);
        pFileEntry->dwCrc32 = crc32(0, Z_NULL, 0);

        // If the caller gave us a file time, use it.
        pFileEntry->FileTime = FileTime;

        // Call the callback, if needed
        if(AddFileCB != NULL)
            AddFileCB(pvUserData, 0, hf->dwDataSize, false);
    }

    // If an error occured, remember it
    if(nError != ERROR_SUCCESS)
        hf->bErrorOccured = true;
    *phf = hf;
    return nError;
}

int SFileAddFile_Write(TMPQFile * hf, const void * pvData, DWORD dwSize, DWORD dwCompression)
{
    TMPQArchive * ha;
    TFileEntry * pFileEntry;
    int nError = ERROR_SUCCESS;

    // Don't bother if the caller gave us zero size
    if(pvData == NULL || dwSize == 0)
        return ERROR_SUCCESS;

    // Get pointer to the MPQ archive
    pFileEntry = hf->pFileEntry;
    ha = hf->ha;

    // Allocate file buffers
    if(hf->pbFileSector == NULL)
    {
        ULONGLONG RawFilePos = hf->RawFilePos;

        // Allocate buffer for file sector
        nError = AllocateSectorBuffer(hf);
        if(nError != ERROR_SUCCESS)
        {
            hf->bErrorOccured = true;
            return nError;
        }

        // Allocate patch info, if the data is patch
        if(hf->pPatchInfo == NULL && IsPatchData(pvData, dwSize, &hf->dwPatchedFileSize))
        {
            // Set the MPQ_FILE_PATCH_FILE flag
            hf->pFileEntry->dwFlags |= MPQ_FILE_PATCH_FILE;

            // Allocate the patch info
            nError = AllocatePatchInfo(hf, false);
            if(nError != ERROR_SUCCESS)
            {
                hf->bErrorOccured = true;
                return nError;
            }
        }

        // Allocate sector offsets
        if(hf->SectorOffsets == NULL)
        {
            nError = AllocateSectorOffsets(hf, false);
            if(nError != ERROR_SUCCESS)
            {
                hf->bErrorOccured = true;
                return nError;
            }
        }

        // Create array of sector checksums
        if(hf->SectorChksums == NULL && (pFileEntry->dwFlags & MPQ_FILE_SECTOR_CRC))
        {
            nError = AllocateSectorChecksums(hf, false);
            if(nError != ERROR_SUCCESS)
            {
                hf->bErrorOccured = true;
                return nError;
            }
        }

        // Pre-save the patch info, if any
        if(hf->pPatchInfo != NULL)
        {
            if(!FileStream_Write(ha->pStream, &RawFilePos, hf->pPatchInfo, hf->pPatchInfo->dwLength))
                nError = GetLastError();
  
            pFileEntry->dwCmpSize += hf->pPatchInfo->dwLength;
            RawFilePos += hf->pPatchInfo->dwLength;
        }

        // Pre-save the sector offset table, just to reserve space in the file.
        // Note that we dont need to swap the sector positions, nor encrypt the table
        // at the moment, as it will be written again after writing all file sectors.
        if(hf->SectorOffsets != NULL)
        {
            if(!FileStream_Write(ha->pStream, &RawFilePos, hf->SectorOffsets, hf->SectorOffsets[0]))
                nError = GetLastError();

            pFileEntry->dwCmpSize += hf->SectorOffsets[0];
            RawFilePos += hf->SectorOffsets[0];
        }
    }

    // Write the MPQ data to the file
    if(nError == ERROR_SUCCESS)
        nError = WriteDataToMpqFile(ha, hf, (LPBYTE)pvData, dwSize, dwCompression);

    // If it succeeded and we wrote all the file data,
    // we need to re-save sector offset table
    if(nError == ERROR_SUCCESS)
    {
        if(hf->dwFilePos >= pFileEntry->dwFileSize)
        {
            // Finish calculating CRC32
            hf->pFileEntry->dwCrc32 = hf->dwCrc32;

            // Finish calculating MD5
            md5_done((hash_state *)hf->hctx, hf->pFileEntry->md5);

            // If we also have sector checksums, write them to the file
            if(hf->SectorChksums != NULL)
            {
                nError = WriteSectorChecksums(hf);
                if(nError != ERROR_SUCCESS)
                    hf->bErrorOccured = true;
            }

            // Now write patch info
            if(hf->pPatchInfo != NULL)
            {
                memcpy(hf->pPatchInfo->md5, hf->pFileEntry->md5, MD5_DIGEST_SIZE);
                hf->pPatchInfo->dwDataSize  = hf->pFileEntry->dwFileSize;
                hf->pFileEntry->dwFileSize = hf->dwPatchedFileSize;
                nError = WritePatchInfo(hf);
                if(nError != ERROR_SUCCESS)
                    hf->bErrorOccured = true;
            }

            // Now write sector offsets to the file
            if(hf->SectorOffsets != NULL)
            {
                nError = WriteSectorOffsets(hf);
                if(nError != ERROR_SUCCESS)
                    hf->bErrorOccured = true;
            }

            // Write the MD5 hashes of each file chunk, if required
            if(ha->pHeader->dwRawChunkSize != 0)
            {
                nError = WriteMpqDataMD5(ha->pStream,
                                         ha->MpqPos + hf->pFileEntry->ByteOffset,
                                         hf->pFileEntry->dwCmpSize,
                                         ha->pHeader->dwRawChunkSize);
                if(nError != ERROR_SUCCESS)
                    hf->bErrorOccured = true;
            }
        }
    }
    else
    {
        hf->bErrorOccured = true;
    }

    return nError;
}

int SFileAddFile_Finish(TMPQFile * hf)
{
    TMPQArchive * ha = hf->ha;
    TFileEntry * pFileEntry = hf->pFileEntry;
    int nError = ERROR_SUCCESS;

    // If all previous operations succeeded, we can update the MPQ
    if(!hf->bErrorOccured)
    {
        // Verify if the caller wrote the file properly
        if(hf->pPatchInfo == NULL)
        {
            assert(pFileEntry != NULL);
            if(hf->dwFilePos != pFileEntry->dwFileSize)
            {
                nError = ERROR_CAN_NOT_COMPLETE;
                hf->bErrorOccured = true;
            }
        }
        else
        {
            if(hf->dwFilePos != hf->pPatchInfo->dwDataSize)
            {
                nError = ERROR_CAN_NOT_COMPLETE;
                hf->bErrorOccured = true;
            }
        }
    }

    if(!hf->bErrorOccured)
    {
        // Call the user callback, if any
        if(AddFileCB != NULL)
            AddFileCB(pvUserData, hf->dwDataSize, hf->dwDataSize, true);

        // Update the size of the block table
        ha->pHeader->dwBlockTableSize = ha->dwFileTableSize;
    }
    else
    {
        // Free the file entry in MPQ tables
        if(pFileEntry != NULL)
            FreeFileEntry(ha, pFileEntry);
    }

    // Clear the add file callback
    FreeMPQFile(hf);
    pvUserData = NULL;
    AddFileCB = NULL;
    return nError;
}

//-----------------------------------------------------------------------------
// Adds data as file to the archive 

bool WINAPI SFileCreateFile(
    HANDLE hMpq,
    const char * szArchivedName,
    ULONGLONG FileTime,
    DWORD dwFileSize,
    LCID lcLocale,
    DWORD dwFlags,
    HANDLE * phFile)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    int nError = ERROR_SUCCESS;

    // Check valid parameters
    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_HANDLE;
    if(szArchivedName == NULL || *szArchivedName == 0)
        nError = ERROR_INVALID_PARAMETER;
    if(phFile == NULL)
        nError = ERROR_INVALID_PARAMETER;
    
    // Don't allow to add file if the MPQ is open for read only
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
        nError = ERROR_ACCESS_DENIED;

    // Don't allow to add a file under pseudo-file name
    if(IsPseudoFileName(szArchivedName, NULL))
        nError = ERROR_INVALID_PARAMETER;

    // Don't allow to add any of the internal files
    if(IsInternalMpqFileName(szArchivedName))
        nError = ERROR_INTERNAL_FILE;

    // Perform validity check of the MPQ flags
    if(nError == ERROR_SUCCESS)
    {
        // Mask all unsupported flags out
        dwFlags &= MPQ_FILE_VALID_FLAGS;

        // Check for valid flag combinations
        if((dwFlags & (MPQ_FILE_IMPLODE | MPQ_FILE_COMPRESS)) == (MPQ_FILE_IMPLODE | MPQ_FILE_COMPRESS))
            nError = ERROR_INVALID_PARAMETER;
    }

    // Create the file in MPQ
    if(nError == ERROR_SUCCESS)
    {
        // Invalidate the entries for (listfile) and (attributes)
        // After we are done with MPQ changes, we need to re-create them anyway
        InvalidateInternalFiles(ha);

        // Initiate the add file operation
        nError = SFileAddFile_Init(ha, szArchivedName, FileTime, dwFileSize, lcLocale, dwFlags, (TMPQFile **)phFile);
    }

    // Deal with the errors
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

bool WINAPI SFileWriteFile(
    HANDLE hFile,
    const void * pvData,
    DWORD dwSize,
    DWORD dwCompression)
{
    TMPQFile * hf = (TMPQFile *)hFile;
    int nError = ERROR_SUCCESS;

    // Check the proper parameters
    if(!IsValidFileHandle(hf))
        nError = ERROR_INVALID_HANDLE;
    if(hf->bIsWriteHandle == false)
        nError = ERROR_INVALID_HANDLE;

    // Special checks for single unit files
    if(nError == ERROR_SUCCESS && (hf->pFileEntry->dwFlags & MPQ_FILE_SINGLE_UNIT))
    {
        //
        // Note: Blizzard doesn't support single unit files
        // that are stored as encrypted or imploded. We will allow them here,
        // the calling application must ensure that such flag combination doesn't get here
        //

//      if(dwFlags & MPQ_FILE_IMPLODE)
//          nError = ERROR_INVALID_PARAMETER;
//
//      if(dwFlags & MPQ_FILE_ENCRYPTED)
//          nError = ERROR_INVALID_PARAMETER;
        
        // Lossy compression is not allowed on single unit files
        if(dwCompression & LOSSY_COMPRESSION_MASK)
            nError = ERROR_INVALID_PARAMETER;
    }


    // Write the data to the file
    if(nError == ERROR_SUCCESS)
        nError = SFileAddFile_Write(hf, pvData, dwSize, dwCompression);
    
    // Deal with errors
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

bool WINAPI SFileFinishFile(HANDLE hFile)
{
    TMPQFile * hf = (TMPQFile *)hFile;
    int nError = ERROR_SUCCESS;

    // Check the proper parameters
    if(!IsValidFileHandle(hf))
        nError = ERROR_INVALID_HANDLE;
    if(hf->bIsWriteHandle == false)
        nError = ERROR_INVALID_HANDLE;

    // Finish the file
    if(nError == ERROR_SUCCESS)
        nError = SFileAddFile_Finish(hf);
    
    // Deal with errors
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// Adds a file to the archive 

bool WINAPI SFileAddFileEx(
    HANDLE hMpq,
    const TCHAR * szFileName,
    const char * szArchivedName,
    DWORD dwFlags,
    DWORD dwCompression,            // Compression of the first sector
    DWORD dwCompressionNext)        // Compression of next sectors
{
    ULONGLONG FileSize = 0;
    ULONGLONG FileTime = 0;
    TFileStream * pStream = NULL;
    HANDLE hMpqFile = NULL;
    LPBYTE pbFileData = NULL;
    DWORD dwBytesRemaining = 0;
    DWORD dwBytesToRead;
    DWORD dwSectorSize = 0x1000;
    int nError = ERROR_SUCCESS;

    // Check parameters
    if(szFileName == NULL || *szFileName == 0)
        nError = ERROR_INVALID_PARAMETER;

    // Open added file
    if(nError == ERROR_SUCCESS)
    {
        pStream = FileStream_OpenFile(szFileName, false);
        if(pStream == NULL)
            nError = GetLastError();
    }

    // Get the file size and file time
    if(nError == ERROR_SUCCESS)
    {
        FileStream_GetLastWriteTime(pStream, &FileTime);
        FileStream_GetSize(pStream, FileSize);
        
        // Files bigger than 4GB cannot be added to MPQ
        if(FileSize >> 32)
            nError = ERROR_DISK_FULL;
    }

    // Allocate data buffer for reading from the source file
    if(nError == ERROR_SUCCESS)
    {
        dwBytesRemaining = (DWORD)FileSize;
        pbFileData = STORM_ALLOC(BYTE, dwSectorSize);
        if(pbFileData == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Deal with various combination of compressions
    if(nError == ERROR_SUCCESS)
    {
        // When the compression for next blocks is set to default,
        // we will copy the compression for the first sector
        if(dwCompressionNext == 0xFFFFFFFF)
            dwCompressionNext = dwCompression;
        
        // If the caller wants ADPCM compression, we make sure that the first sector is not
        // compressed with lossy compression
        if(dwCompressionNext & (MPQ_COMPRESSION_WAVE_MONO | MPQ_COMPRESSION_WAVE_STEREO))
        {
            // The first compression must not be WAVE
            if(dwCompression & (MPQ_COMPRESSION_WAVE_MONO | MPQ_COMPRESSION_WAVE_STEREO))
                dwCompression = MPQ_COMPRESSION_PKWARE;
        }

        // Initiate adding file to the MPQ
        if(!SFileCreateFile(hMpq, szArchivedName, FileTime, (DWORD)FileSize, lcFileLocale, dwFlags, &hMpqFile))
            nError = GetLastError();
    }

    // Write the file data to the MPQ
    while(nError == ERROR_SUCCESS && dwBytesRemaining != 0)
    {
        // Get the number of bytes remaining in the source file
        dwBytesToRead = dwBytesRemaining;
        if(dwBytesToRead > dwSectorSize)
            dwBytesToRead = dwSectorSize;

        // Read data from the local file
        if(!FileStream_Read(pStream, NULL, pbFileData, dwBytesToRead))
        {
            nError = GetLastError();
            break;
        }

        // Add the file sectors to the MPQ
        if(!SFileWriteFile(hMpqFile, pbFileData, dwBytesToRead, dwCompression))
        {
            nError = GetLastError();
            break;
        }

        // Set the next data compression
        dwBytesRemaining -= dwBytesToRead;
        dwCompression = dwCompressionNext;
    }

    // Finish the file writing
    if(hMpqFile != NULL)
    {
        if(!SFileFinishFile(hMpqFile))
            nError = GetLastError();
    }

    // Cleanup and exit
    if(pbFileData != NULL)
        STORM_FREE(pbFileData);
    if(pStream != NULL)
        FileStream_Close(pStream);
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}
                                                                                                                                 
// Adds a data file into the archive
bool WINAPI SFileAddFile(HANDLE hMpq, const TCHAR * szFileName, const char * szArchivedName, DWORD dwFlags)
{
    return SFileAddFileEx(hMpq,
                          szFileName,
                          szArchivedName,
                          dwFlags,
                          DefaultDataCompression,
                          DefaultDataCompression);
}

// Adds a WAVE file into the archive
bool WINAPI SFileAddWave(HANDLE hMpq, const TCHAR * szFileName, const char * szArchivedName, DWORD dwFlags, DWORD dwQuality)
{
    DWORD dwCompression = 0;

    //
    // Note to wave compression level:
    // The following conversion table applied:
    // High quality:   WaveCompressionLevel = -1
    // Medium quality: WaveCompressionLevel = 4
    // Low quality:    WaveCompressionLevel = 2
    //
    // Starcraft files are packed as Mono (0x41) on medium quality.
    // Because this compression is not used anymore, our compression functions
    // will default to WaveCompressionLevel = 4 when using ADPCM compression
    // 

    // Convert quality to data compression
    switch(dwQuality)
    {
        case MPQ_WAVE_QUALITY_HIGH:
//          WaveCompressionLevel = -1;
            dwCompression = MPQ_COMPRESSION_PKWARE;
            break;

        case MPQ_WAVE_QUALITY_MEDIUM:
//          WaveCompressionLevel = 4;
            dwCompression = MPQ_COMPRESSION_WAVE_STEREO | MPQ_COMPRESSION_HUFFMANN;
            break;

        case MPQ_WAVE_QUALITY_LOW:
//          WaveCompressionLevel = 2;
            dwCompression = MPQ_COMPRESSION_WAVE_STEREO | MPQ_COMPRESSION_HUFFMANN;
            break;
    }

    return SFileAddFileEx(hMpq,
                          szFileName,
                          szArchivedName,
                          dwFlags,
                          MPQ_COMPRESSION_PKWARE,   // First sector should be compressed as data
                          dwCompression);           // Next sectors should be compressed as WAVE
}

//-----------------------------------------------------------------------------
// bool SFileRemoveFile(HANDLE hMpq, char * szFileName)
//
// This function removes a file from the archive. The file content
// remains there, only the entries in the hash table and in the block
// table are updated. 

bool WINAPI SFileRemoveFile(HANDLE hMpq, const char * szFileName, DWORD dwSearchScope)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pFileEntry = NULL; // File entry of the file to be deleted
    DWORD dwFileIndex = 0;
    int nError = ERROR_SUCCESS;

    // Keep compiler happy
    dwSearchScope = dwSearchScope;

    // Check the parameters
    if(nError == ERROR_SUCCESS)
    {
        if(!IsValidMpqHandle(ha))
            nError = ERROR_INVALID_HANDLE;
        if(szFileName == NULL || *szFileName == 0)
            nError = ERROR_INVALID_PARAMETER;
        if(IsInternalMpqFileName(szFileName))
            nError = ERROR_INTERNAL_FILE;
    }

    if(nError == ERROR_SUCCESS)
    {
        // Do not allow to remove files from MPQ open for read only
        if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
            nError = ERROR_ACCESS_DENIED;
    }

    // Get hash entry belonging to this file
    if(nError == ERROR_SUCCESS)
    {
        if(!IsPseudoFileName(szFileName, &dwFileIndex))
        {
            if((pFileEntry = GetFileEntryExact(ha, (char *)szFileName, lcFileLocale)) == NULL)
                nError = ERROR_FILE_NOT_FOUND;
        }
        else
        {
            if((pFileEntry = GetFileEntryByIndex(ha, dwFileIndex)) == NULL)
                nError = ERROR_FILE_NOT_FOUND;
        }
    }

    // Test if the file is not already deleted
    if(nError == ERROR_SUCCESS)
    {
        if(!(pFileEntry->dwFlags & MPQ_FILE_EXISTS))
            nError = ERROR_FILE_NOT_FOUND;
    }

    if(nError == ERROR_SUCCESS)
    {
        // Invalidate the entries for (listfile) and (attributes)
        // After we are done with MPQ changes, we need to re-create them anyway
        InvalidateInternalFiles(ha);

        // Mark the file entry as free
        nError = FreeFileEntry(ha, pFileEntry);
    }

    // Resolve error and exit
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

// Renames the file within the archive.
bool WINAPI SFileRenameFile(HANDLE hMpq, const char * szFileName, const char * szNewFileName)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TFileEntry * pFileEntry = NULL;
    ULONGLONG RawDataOffs;
    TMPQFile * hf;
    int nError = ERROR_SUCCESS;

    // Test the valid parameters
    if(nError == ERROR_SUCCESS)
    {
        if(!IsValidMpqHandle(ha))
            nError = ERROR_INVALID_HANDLE;
        if(szFileName == NULL || *szFileName == 0 || szNewFileName == NULL || *szNewFileName == 0)
            nError = ERROR_INVALID_PARAMETER;
    }

    if(nError == ERROR_SUCCESS)
    {
        // Do not allow to rename files in MPQ open for read only
        if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
            nError = ERROR_ACCESS_DENIED;

        // Do not allow renaming anything to a pseudo-file name
        if(IsPseudoFileName(szFileName, NULL) || IsPseudoFileName(szNewFileName, NULL))
            nError = ERROR_INVALID_PARAMETER;

        // Do not allow to rename any of the internal files
        // Also do not allow to rename any of files to an internal file
        if(IsInternalMpqFileName(szFileName) || IsInternalMpqFileName(szNewFileName))
            nError = ERROR_INTERNAL_FILE;
    }

    // Find the current file entry.
    if(nError == ERROR_SUCCESS)
    {
        // Get the file entry
        pFileEntry = GetFileEntryLocale(ha, szFileName, lcFileLocale);
        if(pFileEntry == NULL)
            nError = ERROR_FILE_NOT_FOUND;
    }
        
    // Also try to find file entry for the new file.
    // This verifies if we are not overwriting an existing file
    // (whose name we perhaps don't know)
    if(nError == ERROR_SUCCESS)
    {
        if(GetFileEntryLocale(ha, szNewFileName, pFileEntry->lcLocale) != NULL)
            nError = ERROR_ALREADY_EXISTS;
    }

    // Now we rename the existing file entry.
    if(nError == ERROR_SUCCESS)
    {
        // Rename the file entry
        nError = RenameFileEntry(ha, pFileEntry, szNewFileName);
    }

    // Now we copy the existing file entry to the new one
    if(nError == ERROR_SUCCESS)
    {
        // If the file is encrypted, we have to re-crypt the file content
        // with the new decryption key
        if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
        {
            hf = CreateMpqFile(ha);
            if(hf != NULL)
            {
                // Recrypt the file data in the MPQ
                hf->pFileEntry = pFileEntry;
                hf->dwDataSize = pFileEntry->dwFileSize;
                nError = RecryptFileData(ha, hf, szFileName, szNewFileName);
                
                // Update the MD5
                if(ha->pHeader->dwRawChunkSize != 0)
                {
                    RawDataOffs = ha->MpqPos + pFileEntry->ByteOffset;
                    WriteMpqDataMD5(ha->pStream,
                                    RawDataOffs,
                                    pFileEntry->dwCmpSize,
                                    ha->pHeader->dwRawChunkSize);
                }
                
                FreeMPQFile(hf);
            }
            else
            {
                nError = ERROR_NOT_ENOUGH_MEMORY;
            }
        }
    }

    //
    // Note: MPQ_FLAG_CHANGED is set by RenameFileEntry
    //

    // Resolve error and return
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// Sets default data compression for SFileAddFile

bool WINAPI SFileSetDataCompression(DWORD DataCompression)
{
    unsigned int uValidMask = (MPQ_COMPRESSION_ZLIB | MPQ_COMPRESSION_PKWARE | MPQ_COMPRESSION_BZIP2 | MPQ_COMPRESSION_SPARSE);

    if((DataCompression & uValidMask) != DataCompression)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    DefaultDataCompression = DataCompression;
    return true;
}

//-----------------------------------------------------------------------------
// Changes locale ID of a file

bool WINAPI SFileSetFileLocale(HANDLE hFile, LCID lcNewLocale)
{
    TMPQArchive * ha;
    TFileEntry * pFileEntry;
    TMPQFile * hf = (TMPQFile *)hFile;

    // Invalid handle => do nothing
    if(!IsValidFileHandle(hf))
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Do not allow unnamed access
    if(hf->pFileEntry->szFileName == NULL)
    {
        SetLastError(ERROR_CAN_NOT_COMPLETE);
        return false;
    }

    // Do not allow to change locale of any internal file
    if(IsInternalMpqFileName(hf->pFileEntry->szFileName))
    {
        SetLastError(ERROR_INTERNAL_FILE);
        return false;
    }

    // Do not allow changing file locales in MPQs version 3 or higher
    ha = hf->ha;
    if(ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_3)
    {
        SetLastError(ERROR_NOT_SUPPORTED);
        return false;
    }

    // Do not allow to rename files in MPQ open for read only
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    // If the file already has that locale, return OK
    if(hf->pFileEntry->lcLocale == lcNewLocale)
        return true;

    // We have to check if the file+locale is not already there
    pFileEntry = GetFileEntryExact(ha, hf->pFileEntry->szFileName, lcNewLocale);
    if(pFileEntry != NULL)
    {
        SetLastError(ERROR_ALREADY_EXISTS);
        return false;
    }

    // Set the locale and return success
    pFileEntry = hf->pFileEntry;
    pFileEntry->lcLocale = (USHORT)lcNewLocale;

    // Save the new locale to the hash table, if any
    if(ha->pHashTable != NULL)
        ha->pHashTable[pFileEntry->dwHashIndex].lcLocale = (USHORT)lcNewLocale;

    // Remember that the MPQ tables have been changed
    ha->dwFlags |= MPQ_FLAG_CHANGED;
    return true;
}

//-----------------------------------------------------------------------------
// Sets add file callback

bool WINAPI SFileSetAddFileCallback(HANDLE /* hMpq */, SFILE_ADDFILE_CALLBACK aAddFileCB, void * pvData)
{
    pvUserData = pvData;
    AddFileCB = aAddFileCB;
    return true;
}
