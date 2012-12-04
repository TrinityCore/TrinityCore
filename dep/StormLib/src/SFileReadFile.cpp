/*****************************************************************************/
/* SFileReadFile.cpp                      Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Description :                                                             */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.99  1.00  Lad  The first version of SFileReadFile.cpp               */
/* 24.03.99  1.00  Lad  Added the SFileGetFileInfo function                  */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local structures

struct TFileHeader2Ext
{
    DWORD dwOffset00Data;               // Required data at offset 00 (32-bits)
    DWORD dwOffset00Mask;               // Mask for data at offset 00 (32 bits). 0 = data are ignored
    DWORD dwOffset04Data;               // Required data at offset 04 (32-bits)
    DWORD dwOffset04Mask;               // Mask for data at offset 04 (32 bits). 0 = data are ignored
    const char * szExt;                 // Supplied extension, if the condition is true
};

//-----------------------------------------------------------------------------
// Local functions

static void CopyFileName(char * szTarget, const TCHAR * szSource)
{
    while(*szSource != 0)
        *szTarget++ = (char)*szSource++;
    *szTarget = 0;
}

static DWORD GetMpqFileCount(TMPQArchive * ha)
{
    TFileEntry * pFileTableEnd;
    TFileEntry * pFileEntry;
    DWORD dwFileCount = 0;

    // Go through all open MPQs, including patches
    while(ha != NULL)
    {
        // Only count files that are not patch files
        pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
        for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++)
        {
            // If the file is patch file and this is not primary archive, skip it
            // BUGBUG: This errorneously counts non-patch files that are in both
            // base MPQ and in patches, and increases the number of files by cca 50%
            if((pFileEntry->dwFlags & (MPQ_FILE_EXISTS | MPQ_FILE_PATCH_FILE)) == MPQ_FILE_EXISTS)
                dwFileCount++;
        }

        // Move to the next patch archive
        ha = ha->haPatch;
    }

    return dwFileCount;
}

static bool GetFilePatchChain(TMPQFile * hf, void * pvFileInfo, DWORD cbFileInfo, LPDWORD pcbLengthNeeded)
{
    TMPQFile * hfTemp;
    TCHAR * szPatchChain = (TCHAR *)pvFileInfo;
    TCHAR * szFileName;
    size_t cchCharsNeeded = 1;
    size_t nLength;
    DWORD cbLengthNeeded;

    // Check if the "hf" is a MPQ file
    if(hf->pStream != NULL)
    {
        // Calculate the length needed
        szFileName = FileStream_GetFileName(hf->pStream);
        cchCharsNeeded += _tcslen(szFileName) + 1;
        cbLengthNeeded = (DWORD)(cchCharsNeeded * sizeof(TCHAR));
        
        // If we have enough space, copy the file name
        if(cbFileInfo >= cbLengthNeeded)
        {
            nLength = _tcslen(szFileName) + 1;
            memcpy(szPatchChain, szFileName, nLength * sizeof(TCHAR));
            szPatchChain += nLength;

            // Terminate the multi-string
            *szPatchChain = 0;
        }
    }
    else
    {
        // Calculate number of characters needed
        for(hfTemp = hf; hfTemp != NULL; hfTemp = hfTemp->hfPatchFile)
            cchCharsNeeded += _tcslen(FileStream_GetFileName(hfTemp->ha->pStream)) + 1;
        cbLengthNeeded = (DWORD)(cchCharsNeeded * sizeof(TCHAR));

        // If we have enough space, the copy the patch chain
        if(cbFileInfo >= cbLengthNeeded)
        {
            for(hfTemp = hf; hfTemp != NULL; hfTemp = hfTemp->hfPatchFile)
            {
                szFileName = FileStream_GetFileName(hfTemp->ha->pStream);
                nLength = _tcslen(szFileName) + 1;
                memcpy(szPatchChain, szFileName, nLength * sizeof(TCHAR));
                szPatchChain += nLength;
            }

            // Terminate the multi-string
            *szPatchChain = 0;
        }
    }

    // Give result length, terminate multi-string and return
    *pcbLengthNeeded = cbLengthNeeded;
    return true;
}

//  hf            - MPQ File handle.
//  pbBuffer      - Pointer to target buffer to store sectors.
//  dwByteOffset  - Position of sector in the file (relative to file begin)
//  dwBytesToRead - Number of bytes to read. Must be multiplier of sector size.
//  pdwBytesRead  - Stored number of bytes loaded
static int ReadMpqSectors(TMPQFile * hf, LPBYTE pbBuffer, DWORD dwByteOffset, DWORD dwBytesToRead, LPDWORD pdwBytesRead)
{
    ULONGLONG RawFilePos;
    TMPQArchive * ha = hf->ha;
    TFileEntry * pFileEntry = hf->pFileEntry;
    LPBYTE pbRawSector = NULL;
    LPBYTE pbOutSector = pbBuffer;
    LPBYTE pbInSector = pbBuffer;
    DWORD dwRawBytesToRead;
    DWORD dwRawSectorOffset = dwByteOffset;
    DWORD dwSectorsToRead = dwBytesToRead / ha->dwSectorSize;
    DWORD dwSectorIndex = dwByteOffset / ha->dwSectorSize;
    DWORD dwSectorsDone = 0;
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Note that dwByteOffset must be aligned to size of one sector
    // Note that dwBytesToRead must be a multiplier of one sector size
    // This is local function, so we won't check if that's true.
    // Note that files stored in single units are processed by a separate function

    // If there is not enough bytes remaining, cut dwBytesToRead
    if((dwByteOffset + dwBytesToRead) > hf->dwDataSize)
        dwBytesToRead = hf->dwDataSize - dwByteOffset;
    dwRawBytesToRead = dwBytesToRead;

    // Perform all necessary work to do with compressed files
    if(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED)
    {
        // If the sector positions are not loaded yet, do it
        if(hf->SectorOffsets == NULL)
        {
            nError = AllocateSectorOffsets(hf, true);
            if(nError != ERROR_SUCCESS)
                return nError;
        }

        // If the sector checksums are not loaded yet, load them now.
        if(hf->SectorChksums == NULL && (pFileEntry->dwFlags & MPQ_FILE_SECTOR_CRC) && hf->bLoadedSectorCRCs == false)
        {
            //
            // Sector CRCs is plain crap feature. It is almost never present,
            // often it's empty, or the end offset of sector CRCs is zero.
            // We only try to load sector CRCs once, and regardless if it fails
            // or not, we won't try that again for the given file.
            //

            AllocateSectorChecksums(hf, true);
            hf->bLoadedSectorCRCs = true;
        }

        // TODO: If the raw data MD5s are not loaded yet, load them now
        // Only do it if the MPQ is of format 4.0
//      if(ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_4 && ha->pHeader->dwRawChunkSize != 0)
//      {
//          nError = AllocateRawMD5s(hf, true);
//          if(nError != ERROR_SUCCESS)
//              return nError;
//      }

        // If the file is compressed, also allocate secondary buffer
        pbInSector = pbRawSector = STORM_ALLOC(BYTE, dwBytesToRead);
        if(pbRawSector == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Assign the temporary buffer as target for read operation
        dwRawSectorOffset = hf->SectorOffsets[dwSectorIndex];
        dwRawBytesToRead = hf->SectorOffsets[dwSectorIndex + dwSectorsToRead] - dwRawSectorOffset;
    }

    // Calculate raw file offset where the sector(s) are stored.
    CalculateRawSectorOffset(RawFilePos, hf, dwRawSectorOffset);

    // Set file pointer and read all required sectors
    if(!FileStream_Read(ha->pStream, &RawFilePos, pbInSector, dwRawBytesToRead))
        return GetLastError();
    dwBytesRead = 0;

    // Now we have to decrypt and decompress all file sectors that have been loaded
    for(DWORD i = 0; i < dwSectorsToRead; i++)
    {
        DWORD dwRawBytesInThisSector = ha->dwSectorSize;
        DWORD dwBytesInThisSector = ha->dwSectorSize;
        DWORD dwIndex = dwSectorIndex + i;

        // If there is not enough bytes in the last sector,
        // cut the number of bytes in this sector
        if(dwRawBytesInThisSector > dwBytesToRead)
            dwRawBytesInThisSector = dwBytesToRead;
        if(dwBytesInThisSector > dwBytesToRead)
            dwBytesInThisSector = dwBytesToRead;

        // If the file is compressed, we have to adjust the raw sector size
        if(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED)
            dwRawBytesInThisSector = hf->SectorOffsets[dwIndex + 1] - hf->SectorOffsets[dwIndex];

        // If the file is encrypted, we have to decrypt the sector
        if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
        {
            BSWAP_ARRAY32_UNSIGNED(pbInSector, dwRawBytesInThisSector);

            // If we don't know the key, try to detect it by file content
            if(hf->dwFileKey == 0)
            {
                hf->dwFileKey = DetectFileKeyByContent(pbInSector, dwBytesInThisSector);
                if(hf->dwFileKey == 0)
                {
                    nError = ERROR_UNKNOWN_FILE_KEY;
                    break;
                }
            }

            DecryptMpqBlock(pbInSector, dwRawBytesInThisSector, hf->dwFileKey + dwIndex);
            BSWAP_ARRAY32_UNSIGNED(pbInSector, dwRawBytesInThisSector);
        }

        // If the file has sector CRC check turned on, perform it
        if(hf->bCheckSectorCRCs && hf->SectorChksums != NULL)
        {
            DWORD dwAdlerExpected = hf->SectorChksums[dwIndex];
            DWORD dwAdlerValue = 0;

            // We can only check sector CRC when it's not zero
            // Neither can we check it if it's 0xFFFFFFFF.
            if(dwAdlerExpected != 0 && dwAdlerExpected != 0xFFFFFFFF)
            {
                dwAdlerValue = adler32(0, pbInSector, dwRawBytesInThisSector);
                if(dwAdlerValue != dwAdlerExpected)
                {
                    nError = ERROR_CHECKSUM_ERROR;
                    break;
                }
            }
        }

        // If the sector is really compressed, decompress it.
        // WARNING : Some sectors may not be compressed, it can be determined only
        // by comparing uncompressed and compressed size !!!
        if(dwRawBytesInThisSector < dwBytesInThisSector)
        {
            int cbOutSector = dwBytesInThisSector;
            int cbInSector = dwRawBytesInThisSector;
            int nResult = 0;

            // Is the file compressed by Blizzard's multiple compression ?
            if(pFileEntry->dwFlags & MPQ_FILE_COMPRESS)
            {
                if(ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_2)
                    nResult = SCompDecompress2((char *)pbOutSector, &cbOutSector, (char *)pbInSector, cbInSector);
                else
                    nResult = SCompDecompress((char *)pbOutSector, &cbOutSector, (char *)pbInSector, cbInSector);
            }

            // Is the file compressed by PKWARE Data Compression Library ?
            else if(pFileEntry->dwFlags & MPQ_FILE_IMPLODE)
            {
                nResult = SCompExplode((char *)pbOutSector, &cbOutSector, (char *)pbInSector, cbInSector);
            }

            // Did the decompression fail ?
            if(nResult == 0)
            {
                nError = ERROR_FILE_CORRUPT;
                break;
            }
        }
        else
        {
            if(pbOutSector != pbInSector)
                memcpy(pbOutSector, pbInSector, dwBytesInThisSector);
        }

        // Move pointers
        dwBytesToRead -= dwBytesInThisSector;
        dwByteOffset += dwBytesInThisSector;
        dwBytesRead += dwBytesInThisSector;
        pbOutSector += dwBytesInThisSector;
        pbInSector += dwRawBytesInThisSector;
        dwSectorsDone++;
    }

    // Free all used buffers
    if(pbRawSector != NULL)
        STORM_FREE(pbRawSector);
    
    // Give the caller thenumber of bytes read
    *pdwBytesRead = dwBytesRead;
    return nError; 
}

static int ReadMpqFileSingleUnit(TMPQFile * hf, void * pvBuffer, DWORD dwFilePos, DWORD dwToRead, LPDWORD pdwBytesRead)
{
    ULONGLONG RawFilePos = hf->RawFilePos;
    TMPQArchive * ha = hf->ha;
    TFileEntry * pFileEntry = hf->pFileEntry;
    LPBYTE pbCompressed = NULL;
    LPBYTE pbRawData = NULL;
    int nError = ERROR_SUCCESS;

    // If the file buffer is not allocated yet, do it.
    if(hf->pbFileSector == NULL)
    {
        nError = AllocateSectorBuffer(hf);
        if(nError != ERROR_SUCCESS)
            return nError;
        pbRawData = hf->pbFileSector;
    }

    // If the file is a patch file, adjust raw data offset
    if(hf->pPatchInfo != NULL)
        RawFilePos += hf->pPatchInfo->dwLength;

    // If the file sector is not loaded yet, do it
    if(hf->dwSectorOffs != 0)
    {
        // Is the file compressed?
        if(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED)
        {
            // Allocate space for compressed data
            pbCompressed = STORM_ALLOC(BYTE, pFileEntry->dwCmpSize);
            if(pbCompressed == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;
            pbRawData = pbCompressed;
        }
        
        // Load the raw (compressed, encrypted) data
        if(!FileStream_Read(ha->pStream, &RawFilePos, pbRawData, pFileEntry->dwCmpSize))
        {
            STORM_FREE(pbCompressed);
            return GetLastError();
        }

        // If the file is encrypted, we have to decrypt the data first
        if(pFileEntry->dwFlags & MPQ_FILE_ENCRYPTED)
        {
            BSWAP_ARRAY32_UNSIGNED(pbRawData, pFileEntry->dwCmpSize);
            DecryptMpqBlock(pbRawData, pFileEntry->dwCmpSize, hf->dwFileKey);
            BSWAP_ARRAY32_UNSIGNED(pbRawData, pFileEntry->dwCmpSize);
        }

        // If the file is compressed, we have to decompress it now
        if(pFileEntry->dwFlags & MPQ_FILE_COMPRESSED)
        {
            int cbOutBuffer = (int)hf->dwDataSize;
            int cbInBuffer = (int)pFileEntry->dwCmpSize;
            int nResult = 0;

            //
            // If the file is an incremental patch, the size of compressed data
            // is determined as pFileEntry->dwCmpSize - sizeof(TPatchInfo)
            //
            // In "wow-update-12694.MPQ" from Wow-Cataclysm BETA:
            //
            // File                                    CmprSize   DcmpSize DataSize Compressed?
            // --------------------------------------  ---------- -------- -------- ---------------
            // esES\DBFilesClient\LightSkyBox.dbc      0xBE->0xA2  0xBC     0xBC     Yes
            // deDE\DBFilesClient\MountCapability.dbc  0x93->0x77  0x77     0x77     No
            // 

            if(pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE)
                cbInBuffer = cbInBuffer - sizeof(TPatchInfo);

            // Is the file compressed by Blizzard's multiple compression ?
            if(pFileEntry->dwFlags & MPQ_FILE_COMPRESS)
            {
                if(ha->pHeader->wFormatVersion >= MPQ_FORMAT_VERSION_2)
                    nResult = SCompDecompress2((char *)hf->pbFileSector, &cbOutBuffer, (char *)pbRawData, cbInBuffer);
                else
                    nResult = SCompDecompress((char *)hf->pbFileSector, &cbOutBuffer, (char *)pbRawData, cbInBuffer);
            }

            // Is the file compressed by PKWARE Data Compression Library ?
            // Note: Single unit files compressed with IMPLODE are not supported by Blizzard
            else if(pFileEntry->dwFlags & MPQ_FILE_IMPLODE)
                nResult = SCompExplode((char *)hf->pbFileSector, &cbOutBuffer, (char *)pbRawData, cbInBuffer);

            nError = (nResult != 0) ? ERROR_SUCCESS : ERROR_FILE_CORRUPT;
        }
        else
        {
            if(pbRawData != hf->pbFileSector)
                memcpy(hf->pbFileSector, pbRawData, hf->dwDataSize);
        }

        // Free the decompression buffer.
        if(pbCompressed != NULL)
            STORM_FREE(pbCompressed);

        // The file sector is now properly loaded
        hf->dwSectorOffs = 0;
    }

    // At this moment, we have the file loaded into the file buffer.
    // Copy as much as the caller wants
    if(nError == ERROR_SUCCESS && hf->dwSectorOffs == 0)
    {
        // File position is greater or equal to file size ?
        if(dwFilePos >= hf->dwDataSize)
        {
            *pdwBytesRead = 0;
            return ERROR_SUCCESS;
        }

        // If not enough bytes remaining in the file, cut them
        if((hf->dwDataSize - dwFilePos) < dwToRead)
            dwToRead = (hf->dwDataSize - dwFilePos);

        // Copy the bytes
        memcpy(pvBuffer, hf->pbFileSector + dwFilePos, dwToRead);

        // Give the number of bytes read
        *pdwBytesRead = dwToRead;
        return ERROR_SUCCESS;
    }

    // An error, sorry
    return ERROR_CAN_NOT_COMPLETE;
}

static int ReadMpqFile(TMPQFile * hf, void * pvBuffer, DWORD dwFilePos, DWORD dwBytesToRead, LPDWORD pdwBytesRead)
{
    TMPQArchive * ha = hf->ha;
    LPBYTE pbBuffer = (BYTE *)pvBuffer;
    DWORD dwTotalBytesRead = 0;                         // Total bytes read in all three parts
    DWORD dwSectorSizeMask = ha->dwSectorSize - 1;      // Mask for block size, usually 0x0FFF
    DWORD dwFileSectorPos;                              // File offset of the loaded sector
    DWORD dwBytesRead;                                  // Number of bytes read (temporary variable)
    int nError;

    // If the file position is at or beyond end of file, do nothing
    if(dwFilePos >= hf->dwDataSize)
    {
        *pdwBytesRead = 0;
        return ERROR_SUCCESS;
    }

    // If not enough bytes in the file remaining, cut them
    if(dwBytesToRead > (hf->dwDataSize - dwFilePos))
        dwBytesToRead = (hf->dwDataSize - dwFilePos);

    // Compute sector position in the file
    dwFileSectorPos = dwFilePos & ~dwSectorSizeMask;  // Position in the block

    // If the file sector buffer is not allocated yet, do it now
    if(hf->pbFileSector == NULL)
    {
        nError = AllocateSectorBuffer(hf);
        if(nError != ERROR_SUCCESS)
            return nError;
    }

    // Load the first (incomplete) file sector
    if(dwFilePos & dwSectorSizeMask)
    {
        DWORD dwBytesInSector = ha->dwSectorSize;
        DWORD dwBufferOffs = dwFilePos & dwSectorSizeMask;
        DWORD dwToCopy;                                     

        // Is the file sector already loaded ?
        if(hf->dwSectorOffs != dwFileSectorPos)
        {
            // Load one MPQ sector into archive buffer
            nError = ReadMpqSectors(hf, hf->pbFileSector, dwFileSectorPos, ha->dwSectorSize, &dwBytesInSector);
            if(nError != ERROR_SUCCESS)
                return nError;

            // Remember that the data loaded to the sector have new file offset
            hf->dwSectorOffs = dwFileSectorPos;
        }
        else
        {
            if((dwFileSectorPos + dwBytesInSector) > hf->dwDataSize)
                dwBytesInSector = hf->dwDataSize - dwFileSectorPos;
        }

        // Copy the data from the offset in the loaded sector to the end of the sector
        dwToCopy = dwBytesInSector - dwBufferOffs;
        if(dwToCopy > dwBytesToRead)
            dwToCopy = dwBytesToRead;

        // Copy data from sector buffer into target buffer
        memcpy(pbBuffer, hf->pbFileSector + dwBufferOffs, dwToCopy);

        // Update pointers and byte counts
        dwTotalBytesRead += dwToCopy;
        dwFileSectorPos  += dwBytesInSector;
        pbBuffer         += dwToCopy;
        dwBytesToRead    -= dwToCopy;
    }

    // Load the whole ("middle") sectors only if there is at least one full sector to be read
    if(dwBytesToRead >= ha->dwSectorSize)
    {
        DWORD dwBlockBytes = dwBytesToRead & ~dwSectorSizeMask;

        // Load all sectors to the output buffer
        nError = ReadMpqSectors(hf, pbBuffer, dwFileSectorPos, dwBlockBytes, &dwBytesRead);
        if(nError != ERROR_SUCCESS)
            return nError;

        // Update pointers
        dwTotalBytesRead += dwBytesRead;
        dwFileSectorPos  += dwBytesRead;
        pbBuffer         += dwBytesRead;
        dwBytesToRead    -= dwBytesRead;
    }

    // Read the terminating sector
    if(dwBytesToRead > 0)
    {
        DWORD dwToCopy = ha->dwSectorSize;

        // Is the file sector already loaded ?
        if(hf->dwSectorOffs != dwFileSectorPos)
        {
            // Load one MPQ sector into archive buffer
            nError = ReadMpqSectors(hf, hf->pbFileSector, dwFileSectorPos, ha->dwSectorSize, &dwBytesRead);
            if(nError != ERROR_SUCCESS)
                return nError;

            // Remember that the data loaded to the sector have new file offset
            hf->dwSectorOffs = dwFileSectorPos;
        }

        // Check number of bytes read
        if(dwToCopy > dwBytesToRead)
            dwToCopy = dwBytesToRead;

        // Copy the data from the cached last sector to the caller's buffer
        memcpy(pbBuffer, hf->pbFileSector, dwToCopy);
        
        // Update pointers
        dwTotalBytesRead += dwToCopy;
    }

    // Store total number of bytes read to the caller
    *pdwBytesRead = dwTotalBytesRead;
    return ERROR_SUCCESS;
}

static int ReadMpqFilePatchFile(TMPQFile * hf, void * pvBuffer, DWORD dwFilePos, DWORD dwToRead, LPDWORD pdwBytesRead)
{
    DWORD dwBytesToRead = dwToRead;
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Make sure that the patch file is loaded completely
    if(hf->pbFileData == NULL)
    {
        // Load the original file and store its content to "pbOldData"
        hf->pbFileData = STORM_ALLOC(BYTE, hf->pFileEntry->dwFileSize);
        hf->cbFileData = hf->pFileEntry->dwFileSize;
        if(hf->pbFileData == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Read the file data
        if(hf->pFileEntry->dwFlags & MPQ_FILE_SINGLE_UNIT)
            nError = ReadMpqFileSingleUnit(hf, hf->pbFileData, 0, hf->cbFileData, &dwBytesRead);
        else
            nError = ReadMpqFile(hf, hf->pbFileData, 0, hf->cbFileData, &dwBytesRead);

        // Fix error code
        if(nError == ERROR_SUCCESS && dwBytesRead != hf->cbFileData)
            nError = ERROR_FILE_CORRUPT;

        // Patch the file data
        if(nError == ERROR_SUCCESS)
            nError = PatchFileData(hf);

        // Reset number of bytes read to zero
        dwBytesRead = 0;
    }

    // If there is something to read, do it
    if(nError == ERROR_SUCCESS)
    {
        if(dwFilePos < hf->cbFileData)
        {
            // Make sure we don't copy more than file size
            if((dwFilePos + dwToRead) > hf->cbFileData)
                dwToRead = hf->cbFileData - dwFilePos;

            // Copy the appropriate amount of the file data to the caller's buffer
            memcpy(pvBuffer, hf->pbFileData + dwFilePos, dwToRead);
            dwBytesRead = dwToRead;
        }

        // Set the proper error code
        nError = (dwBytesRead == dwBytesToRead) ? ERROR_SUCCESS : ERROR_HANDLE_EOF;
    }

    // Give the result to the caller
    if(pdwBytesRead != NULL)
        *pdwBytesRead = dwBytesRead;
    return nError;
}

//-----------------------------------------------------------------------------
// SFileReadFile

bool WINAPI SFileReadFile(HANDLE hFile, void * pvBuffer, DWORD dwToRead, LPDWORD pdwRead, LPOVERLAPPED lpOverlapped)
{
    TMPQFile * hf = (TMPQFile *)hFile;
    DWORD dwBytesRead = 0;                      // Number of bytes read
    int nError = ERROR_SUCCESS;

    // Keep compilers happy
    lpOverlapped = lpOverlapped;

    // Check valid parameters
    if(!IsValidFileHandle(hf))
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    if(pvBuffer == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // If the file is local file, read the data directly from the stream
    if(hf->pStream != NULL)
    {
        ULONGLONG FilePosition1;
        ULONGLONG FilePosition2;

        // Because stream I/O functions are designed to read
        // "all or nothing", we compare file position before and after,
        // and if they differ, we assume that number of bytes read
        // is the difference between them

        FileStream_GetPos(hf->pStream, FilePosition1);
        if(!FileStream_Read(hf->pStream, NULL, pvBuffer, dwToRead))
        {
            // If not all bytes have been read, then return the number
            // of bytes read
            if((nError = GetLastError()) == ERROR_HANDLE_EOF)
            {
                FileStream_GetPos(hf->pStream, FilePosition2);
                dwBytesRead = (DWORD)(FilePosition2 - FilePosition1);
            }
            else
            {
                nError = GetLastError();
            }
        }
        else
        {
            dwBytesRead = dwToRead;
        }
    }
    else
    {
        // If the file is a patch file, we have to read it special way
        if(hf->hfPatchFile != NULL && (hf->pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE) == 0)
        {
            nError = ReadMpqFilePatchFile(hf, pvBuffer, hf->dwFilePos, dwToRead, &dwBytesRead);
        }

        // If the file is single unit file, redirect it to read file 
        else if(hf->pFileEntry->dwFlags & MPQ_FILE_SINGLE_UNIT)
        {
            nError = ReadMpqFileSingleUnit(hf, pvBuffer, hf->dwFilePos, dwToRead, &dwBytesRead);
        }

        // Otherwise read it as sector based MPQ file
        else
        {                                                                   
            nError = ReadMpqFile(hf, pvBuffer, hf->dwFilePos, dwToRead, &dwBytesRead);
        }

        // Increment the file position
        hf->dwFilePos += dwBytesRead;
    }

    // Give the caller the number of bytes read
    if(pdwRead != NULL)
        *pdwRead = dwBytesRead;

    // If the read operation succeeded, but not full number of bytes was read,
    // set the last error to ERROR_HANDLE_EOF
    if(nError == ERROR_SUCCESS && (dwBytesRead < dwToRead))
        nError = ERROR_HANDLE_EOF;

    // If something failed, set the last error value
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// SFileGetFileSize

DWORD WINAPI SFileGetFileSize(HANDLE hFile, LPDWORD pdwFileSizeHigh)
{
    ULONGLONG FileSize;
    TMPQFile * hf = (TMPQFile *)hFile;

    // Validate the file handle before we go on
    if(IsValidFileHandle(hf))
    {
        // Make sure that the variable is initialized
        FileSize = 0;

        // If the file is patched file, we have to get the size of the last version
        if(hf->hfPatchFile != NULL)
        {
            // Walk through the entire patch chain, take the last version
            while(hf != NULL)
            {
                // Get the size of the currently pointed version
                FileSize = hf->pFileEntry->dwFileSize;

                // Move to the next patch file in the hierarchy
                hf = hf->hfPatchFile;
            }
        }
        else
        {
            // Is it a local file ?
            if(hf->pStream != NULL)
            {
                FileStream_GetSize(hf->pStream, FileSize);
            }
            else
            {
                FileSize = hf->dwDataSize;
            }
        }

        // If opened from archive, return file size
        if(pdwFileSizeHigh != NULL)
            *pdwFileSizeHigh = (DWORD)(FileSize >> 32);
        return (DWORD)FileSize;
    }

    SetLastError(ERROR_INVALID_HANDLE);
    return SFILE_INVALID_SIZE;
}

DWORD WINAPI SFileSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod)
{
    TMPQFile * hf = (TMPQFile *)hFile;
    ULONGLONG FilePosition;
    ULONGLONG MoveOffset;
    DWORD dwFilePosHi;

    // If the hFile is not a valid file handle, return an error.
    if(!IsValidFileHandle(hf))
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return SFILE_INVALID_POS;
    }

    // Get the relative point where to move from
    switch(dwMoveMethod)
    {
        case FILE_BEGIN:
            FilePosition = 0;
            break;

        case FILE_CURRENT:
            if(hf->pStream != NULL)
            {
                FileStream_GetPos(hf->pStream, FilePosition);
            }
            else
            {
                FilePosition = hf->dwFilePos;
            }
            break;

        case FILE_END:
            if(hf->pStream != NULL)
            {
                FileStream_GetSize(hf->pStream, FilePosition);
            }
            else
            {
                FilePosition = SFileGetFileSize(hFile, NULL);
            }
            break;

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return SFILE_INVALID_POS;
    }

    // Now get the move offset. Note that both values form
    // a signed 64-bit value (a file pointer can be moved backwards)
    if(plFilePosHigh != NULL)
        dwFilePosHi = *plFilePosHigh;
    else
        dwFilePosHi = (lFilePos & 0x80000000) ? 0xFFFFFFFF : 0;
    MoveOffset = MAKE_OFFSET64(dwFilePosHi, lFilePos);

    // Now calculate the new file pointer
    // Do not allow the file pointer to go before the begin of the file
    FilePosition += MoveOffset;
    if(FilePosition < 0)
        FilePosition = 0;

    // Now apply the file pointer to the file
    if(hf->pStream != NULL)
    {
        // Apply the new file position
        if(!FileStream_Read(hf->pStream, &FilePosition, NULL, 0))
            return SFILE_INVALID_POS;

        // Return the new file position
        if(plFilePosHigh != NULL)
            *plFilePosHigh = (LONG)(FilePosition >> 32);
        return (DWORD)FilePosition;
    }
    else
    {
        // Files in MPQ can't be bigger than 4 GB.
        // We don't allow to go past 4 GB
        if(FilePosition >> 32)
        {
            SetLastError(ERROR_INVALID_PARAMETER);
            return SFILE_INVALID_POS;
        }

        // Change the file position
        hf->dwFilePos = (DWORD)FilePosition;

        // Return the new file position
        if(plFilePosHigh != NULL)
            *plFilePosHigh = 0;
        return (DWORD)FilePosition;
    }
}

//-----------------------------------------------------------------------------
// Tries to retrieve the file name

static TFileHeader2Ext data2ext[] = 
{
    {0x00005A4D, 0x0000FFFF, 0x00000000, 0x00000000, "exe"},    // EXE files
    {0x00000006, 0xFFFFFFFF, 0x00000001, 0xFFFFFFFF, "dc6"},    // EXE files
    {0x1A51504D, 0xFFFFFFFF, 0x00000000, 0x00000000, "mpq"},    // MPQ archive header ID ('MPQ\x1A')
    {0x46464952, 0xFFFFFFFF, 0x00000000, 0x00000000, "wav"},    // WAVE header 'RIFF'
    {0x324B4D53, 0xFFFFFFFF, 0x00000000, 0x00000000, "smk"},    // Old "Smacker Video" files 'SMK2'
    {0x694B4942, 0xFFFFFFFF, 0x00000000, 0x00000000, "bik"},    // Bink video files (new)
    {0x0801050A, 0xFFFFFFFF, 0x00000000, 0x00000000, "pcx"},    // PCX images used in Diablo I
    {0x544E4F46, 0xFFFFFFFF, 0x00000000, 0x00000000, "fnt"},    // Font files used in Diablo II
    {0x6D74683C, 0xFFFFFFFF, 0x00000000, 0x00000000, "html"},   // HTML '<htm'
    {0x4D54483C, 0xFFFFFFFF, 0x00000000, 0x00000000, "html"},   // HTML '<HTM
    {0x216F6F57, 0xFFFFFFFF, 0x00000000, 0x00000000, "tbl"},    // Table files
    {0x31504C42, 0xFFFFFFFF, 0x00000000, 0x00000000, "blp"},    // BLP textures
    {0x32504C42, 0xFFFFFFFF, 0x00000000, 0x00000000, "blp"},    // BLP textures (v2)
    {0x584C444D, 0xFFFFFFFF, 0x00000000, 0x00000000, "mdx"},    // MDX files
    {0x45505954, 0xFFFFFFFF, 0x00000000, 0x00000000, "pud"},    // Warcraft II maps
    {0x38464947, 0xFFFFFFFF, 0x00000000, 0x00000000, "gif"},    // GIF images 'GIF8'
    {0x3032444D, 0xFFFFFFFF, 0x00000000, 0x00000000, "m2"},     // WoW ??? .m2
    {0x43424457, 0xFFFFFFFF, 0x00000000, 0x00000000, "dbc"},    // ??? .dbc
    {0x47585053, 0xFFFFFFFF, 0x00000000, 0x00000000, "bls"},    // WoW pixel shaders
    {0xE0FFD8FF, 0xFFFFFFFF, 0x00000000, 0x00000000, "jpg"},    // JPEG image
    {0x00000000, 0x00000000, 0x00000000, 0x00000000, "xxx"},    // Default extension
    {0, 0, 0, 0, NULL}                                          // Terminator 
};

bool WINAPI SFileGetFileName(HANDLE hFile, char * szFileName)
{
    TFileEntry * pFileEntry;
    TMPQFile * hf = (TMPQFile *)hFile;  // MPQ File handle
    char szPseudoName[20];    
    DWORD FirstBytes[2];                // The first 4 bytes of the file
    DWORD dwFilePos;                    // Saved file position
    int nError = ERROR_SUCCESS;
    int i;

    // Pre-zero the output buffer
    if(szFileName != NULL)
        *szFileName = 0;

    // Check valid parameters
    if(!IsValidFileHandle(hf))
        nError = ERROR_INVALID_HANDLE;
    pFileEntry = hf->pFileEntry;
    
    // Only do something if the file name is not filled
    if(nError == ERROR_SUCCESS && pFileEntry != NULL && pFileEntry->szFileName == NULL)
    {
        // Read the first 2 DWORDs bytes from the file
        FirstBytes[0] = FirstBytes[1] = 0;
        dwFilePos = SFileSetFilePointer(hf, 0, NULL, FILE_CURRENT);   
        SFileReadFile(hFile, FirstBytes, sizeof(FirstBytes), NULL);
        BSWAP_ARRAY32_UNSIGNED(FirstBytes, sizeof(FirstBytes));
        SFileSetFilePointer(hf, dwFilePos, NULL, FILE_BEGIN);

        // Try to guess file extension from those 2 DWORDs
        for(i = 0; data2ext[i].szExt != NULL; i++)
        {
            if((FirstBytes[0] & data2ext[i].dwOffset00Mask) == data2ext[i].dwOffset00Data &&
               (FirstBytes[1] & data2ext[i].dwOffset04Mask) == data2ext[i].dwOffset04Data)
            {
                sprintf(szPseudoName, "File%08u.%s", (unsigned int)(pFileEntry - hf->ha->pFileTable), data2ext[i].szExt);
                break;
            }
        }

        // Put the file name to the file table
        AllocateFileName(pFileEntry, szPseudoName);
    } 

    // Now put the file name to the file structure
    if(nError == ERROR_SUCCESS && szFileName != NULL)
    {
        if(pFileEntry != NULL && pFileEntry->szFileName != NULL)
            strcpy(szFileName, pFileEntry->szFileName);
        else if(hf->pStream != NULL)
            CopyFileName(szFileName, FileStream_GetFileName(hf->pStream));
    }
    return (nError == ERROR_SUCCESS);
}

//-----------------------------------------------------------------------------
// Retrieves an information about an archive or about a file within the archive
//
//  hMpqOrFile - Handle to an MPQ archive or to a file
//  dwInfoType - Information to obtain

#define VERIFY_MPQ_HANDLE(h)                \
    if(!IsValidMpqHandle(h))                \
    {                                       \
        nError = ERROR_INVALID_HANDLE;      \
        break;                              \
    }

#define VERIFY_FILE_HANDLE(h)               \
    if(!IsValidFileHandle(h))               \
    {                                       \
        nError = ERROR_INVALID_HANDLE;      \
        break;                              \
    }

bool WINAPI SFileGetFileInfo(
    HANDLE hMpqOrFile,
    DWORD dwInfoType,
    void * pvFileInfo,
    DWORD cbFileInfo,
    LPDWORD pcbLengthNeeded)
{
    TMPQArchive * ha = (TMPQArchive *)hMpqOrFile;
    TMPQBlock * pBlock;
    TMPQFile * hf = (TMPQFile *)hMpqOrFile;
    void * pvSrcFileInfo = NULL;
    DWORD cbLengthNeeded = 0;
    DWORD dwIsReadOnly;
    DWORD dwFileCount = 0;
    DWORD dwFileIndex;
    DWORD dwFileKey;
    DWORD i;
    int nError = ERROR_SUCCESS;

    switch(dwInfoType)
    {
        case SFILE_INFO_ARCHIVE_NAME:
            VERIFY_MPQ_HANDLE(ha);
            
            // pvFileInfo receives the name of the archive, terminated by 0
            pvSrcFileInfo = FileStream_GetFileName(ha->pStream);
            cbLengthNeeded = (DWORD)(_tcslen((TCHAR *)pvSrcFileInfo) + 1) * sizeof(TCHAR);
            break;

        case SFILE_INFO_ARCHIVE_SIZE:       // Size of the archive
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &ha->pHeader->dwArchiveSize;
            break;

        case SFILE_INFO_MAX_FILE_COUNT:     // Max. number of files in the MPQ
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &ha->dwMaxFileCount;
            break;

        case SFILE_INFO_HASH_TABLE_SIZE:    // Size of the hash table
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &ha->pHeader->dwHashTableSize;
            break;

        case SFILE_INFO_BLOCK_TABLE_SIZE:   // Size of the block table
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &ha->pHeader->dwBlockTableSize;
            break;

        case SFILE_INFO_SECTOR_SIZE:
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &ha->dwSectorSize;
            break;

        case SFILE_INFO_HASH_TABLE:
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = ha->pHeader->dwHashTableSize * sizeof(TMPQHash);
            pvSrcFileInfo = ha->pHashTable;
            break;

        case SFILE_INFO_BLOCK_TABLE:
            VERIFY_MPQ_HANDLE(ha);
            cbLengthNeeded = ha->dwFileTableSize * sizeof(TMPQBlock);
            if(cbFileInfo < cbLengthNeeded)
            {
                nError = ERROR_INSUFFICIENT_BUFFER;
                break;
            }

            // Construct block table from file table size
            pBlock = (TMPQBlock *)pvFileInfo;
            for(i = 0; i < ha->dwFileTableSize; i++)
            {
                pBlock->dwFilePos = (DWORD)ha->pFileTable[i].ByteOffset;
                pBlock->dwFSize   = ha->pFileTable[i].dwFileSize;
                pBlock->dwCSize   = ha->pFileTable[i].dwCmpSize;
                pBlock->dwFlags   = ha->pFileTable[i].dwFlags;
                pBlock++;
            }
            break;

        case SFILE_INFO_NUM_FILES:
            VERIFY_MPQ_HANDLE(ha);
            dwFileCount = GetMpqFileCount(ha);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &dwFileCount;
            break;

        case SFILE_INFO_STREAM_FLAGS:   // Deprecated
            nError = ERROR_INVALID_PARAMETER;
            break;

        case SFILE_INFO_IS_READ_ONLY:
            VERIFY_MPQ_HANDLE(ha);
            dwIsReadOnly = (FileStream_IsReadOnly(ha->pStream) || (ha->dwFlags & MPQ_FLAG_READ_ONLY));
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &dwIsReadOnly;
            break;

        case SFILE_INFO_HASH_INDEX:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->dwHashIndex;
            break;

        case SFILE_INFO_CODENAME1:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->dwHashIndex;
            if(ha->pHashTable != NULL)
                pvSrcFileInfo = &ha->pHashTable[hf->pFileEntry->dwHashIndex].dwName1;
            break;

        case SFILE_INFO_CODENAME2:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            if(ha->pHashTable != NULL)
                pvSrcFileInfo = &ha->pHashTable[hf->pFileEntry->dwHashIndex].dwName2;
            break;

        case SFILE_INFO_LOCALEID:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->lcLocale;
            break;

        case SFILE_INFO_BLOCKINDEX:
            VERIFY_FILE_HANDLE(hf);
            dwFileIndex = (DWORD)(hf->pFileEntry - hf->ha->pFileTable);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &dwFileIndex;
            break;

        case SFILE_INFO_FILE_SIZE:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->dwFileSize;
            break;

        case SFILE_INFO_COMPRESSED_SIZE:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->dwCmpSize;
            break;

        case SFILE_INFO_FLAGS:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->pFileEntry->dwFlags;
            break;

        case SFILE_INFO_POSITION:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(ULONGLONG);
            pvSrcFileInfo = &hf->pFileEntry->ByteOffset;
            break;

        case SFILE_INFO_KEY:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &hf->dwFileKey;
            break;

        case SFILE_INFO_KEY_UNFIXED:
            VERIFY_FILE_HANDLE(hf);
            dwFileKey = hf->dwFileKey;
            if(hf->pFileEntry->dwFlags & MPQ_FILE_FIX_KEY)
                dwFileKey = (dwFileKey ^ hf->pFileEntry->dwFileSize) - (DWORD)hf->MpqFilePos;
            cbLengthNeeded = sizeof(DWORD);
            pvSrcFileInfo = &dwFileKey;
            break;

        case SFILE_INFO_FILETIME:
            VERIFY_FILE_HANDLE(hf);
            cbLengthNeeded = sizeof(ULONGLONG);
            pvSrcFileInfo = &hf->pFileEntry->FileTime;
            break;

        case SFILE_INFO_PATCH_CHAIN:
            VERIFY_FILE_HANDLE(hf);
            GetFilePatchChain(hf, pvFileInfo, cbFileInfo, &cbLengthNeeded);
            break;

        default:
            nError = ERROR_INVALID_PARAMETER;
            break;
    }

    // If everything is OK so far, copy the information
    if(nError == ERROR_SUCCESS)
    {
        // Is the output buffer large enough?
        if(cbFileInfo >= cbLengthNeeded)
        {
            // Copy the data
            if(pvSrcFileInfo != NULL)
                memcpy(pvFileInfo, pvSrcFileInfo, cbLengthNeeded);
        }
        else
        {
            nError = ERROR_INSUFFICIENT_BUFFER;
        }

        // Give the size to the caller
        if(pcbLengthNeeded != NULL)
            *pcbLengthNeeded = cbLengthNeeded;
    }

    // Set the last error value, if needed
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}
