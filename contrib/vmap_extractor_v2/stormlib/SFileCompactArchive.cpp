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
#include "SCommon.h"

/*****************************************************************************/
/* Local structures                                                          */
/*****************************************************************************/

/*****************************************************************************/
/* Local variables                                                           */
/*****************************************************************************/

static COMPACTCB CompactCB  = NULL;
static void    * lpUserData = NULL;

/*****************************************************************************/
/* Local functions                                                           */
/*****************************************************************************/

// Creates a copy of hash table
static TMPQHash * CopyHashTable(TMPQArchive * ha)
{
    TMPQHash * pHashTableCopy = ALLOCMEM(TMPQHash, ha->pHeader->dwHashTableSize);

    if(pHashTableCopy != NULL)
        memcpy(pHashTableCopy, ha->pHashTable, sizeof(TMPQHash) * ha->pHeader->dwHashTableSize);

    return pHashTableCopy;
}

// TODO: Test for archives > 4GB
static int CheckIfAllFilesKnown(TMPQArchive * ha, const char * szListFile, DWORD * pFileSeeds)
{
    TMPQHash * pHashTableCopy = NULL;   // Copy of the hash table
    TMPQHash * pHash;
    TMPQHash * pHashEnd = NULL;         // End of the hash table
    DWORD dwFileCount = 0;
    int nError = ERROR_SUCCESS;

    // First of all, create a copy of hash table
    if(nError == ERROR_SUCCESS)
    {
        if((pHashTableCopy = CopyHashTable(ha)) == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
        pHashEnd = pHashTableCopy + ha->pHeader->dwHashTableSize;

        // Notify the user
        if(CompactCB != NULL)
            CompactCB(lpUserData, CCB_CHECKING_FILES, 0, ha->pHeader->dwBlockTableSize);
    }

    // Now check all the files from the filelist
    if(nError == ERROR_SUCCESS)
    {
        SFILE_FIND_DATA wf;
        HANDLE hFind = SFileFindFirstFile((HANDLE)ha, "*", &wf, szListFile);
        BOOL bResult = TRUE;

        // Do while some files have been found
        while(hFind != NULL && bResult)
        {
            TMPQHash * pHash = GetHashEntry(ha, wf.cFileName);

            // If the hash table entry has been found, find it's position
            // in the hash table copy
            if(pHash != NULL)
            {
                pHash = pHashTableCopy + (pHash - ha->pHashTable);
                if(pHash->dwName1 != (DWORD)-1 && pHash->dwName2 != (DWORD)-1)
                {
                    TMPQBlock * pBlock = ha->pBlockTable + pHash->dwBlockIndex;
                    DWORD dwSeed = 0;

                    // Resolve the file seed. Use plain file name for it
                    if(pBlock->dwFlags & MPQ_FILE_ENCRYPTED)
                    {
                        char * szFileName = strrchr(wf.cFileName, '\\');

                        if(szFileName == NULL)
                            szFileName = wf.cFileName;
                        else
                            szFileName++;

                        dwSeed = DecryptFileSeed(szFileName);
                        if(pBlock->dwFlags & MPQ_FILE_FIXSEED)
                            dwSeed = (dwSeed + pBlock->dwFilePos) ^ pBlock->dwFSize;
                    }
                    pFileSeeds[pHash->dwBlockIndex] = dwSeed;

                    pHash->dwName1      = 0xFFFFFFFF;
                    pHash->dwName2      = 0xFFFFFFFF;
                    pHash->lcLocale     = 0xFFFF;
                    pHash->wPlatform    = 0xFFFF;
                    pHash->dwBlockIndex = 0xFFFFFFFF;
                }
            }
            // Notify the user
            if(CompactCB != NULL)
                CompactCB(lpUserData, CCB_CHECKING_FILES, ++dwFileCount, ha->pHeader->dwBlockTableSize);

            // Find the next file in the archive
            bResult = SFileFindNextFile(hFind, &wf);
        }

        if(hFind != NULL)
            SFileFindClose(hFind);
    }

    // When the filelist checking is complete, parse the hash table copy and find the
    if(nError == ERROR_SUCCESS)
    {
        // Notify the user about checking hash table
        dwFileCount = 0;
        if(CompactCB != NULL)
            CompactCB(lpUserData, CCB_CHECKING_HASH_TABLE, dwFileCount, ha->pHeader->dwBlockTableSize);

        for(pHash = pHashTableCopy; pHash < pHashEnd; pHash++)
        {
            // If there is an unresolved entry, try to detect its seed. If it fails,
            // we cannot complete the work
            if(pHash->dwName1 != (DWORD)-1 && pHash->dwName2 != (DWORD)-1)
            {
                HANDLE hFile  = NULL;
                DWORD dwFlags = 0;
                DWORD dwSeed  = 0;

                if(SFileOpenFileEx((HANDLE)ha, (char *)(DWORD_PTR)pHash->dwBlockIndex, 0, &hFile))
                {
                    TMPQFile * hf = (TMPQFile *)hFile;
                    dwFlags = hf->pBlock->dwFlags;
                    dwSeed = hf->dwSeed1;
                    SFileCloseFile(hFile);
                }

                // If the file is encrypted, we have to check 
                // If we can apply the file decryption seed
                if(dwFlags & MPQ_FILE_ENCRYPTED && dwSeed == 0)
                {
                    nError = ERROR_CAN_NOT_COMPLETE;
                    break;
                }

                // Remember the seed
                pFileSeeds[pHash->dwBlockIndex] = dwSeed;

                // Notify the user
                if(CompactCB != NULL)
                    CompactCB(lpUserData, CCB_CHECKING_HASH_TABLE, ++dwFileCount, ha->pHeader->dwBlockTableSize);
            }
        }
    }

    // Delete the copy of hash table
    if(pHashTableCopy != NULL)
        FREEMEM(pHashTableCopy);
    return nError;
}

// Copies all file blocks into another archive.
// TODO: Test for archives > 4GB
static int CopyMpqFileBlocks(
    HANDLE hFile,
    TMPQArchive * ha,
    TMPQBlockEx * pBlockEx,
    TMPQBlock * pBlock,
    DWORD dwSeed)
{
    LARGE_INTEGER FilePos = {0};
    DWORD * pdwBlockPos2 = NULL;        // File block positions to be written to target file
    DWORD * pdwBlockPos = NULL;         // File block positions (unencrypted)
    BYTE  * pbBlock = NULL;             // Buffer for the file block
    DWORD dwTransferred;                // Number of bytes transferred
    DWORD dwCSize = 0;                  // Compressed file size
    DWORD dwBytes = 0;                  // Number of bytes
    DWORD dwSeed1 = 0;                  // File seed used for decryption
    DWORD dwSeed2 = 0;                  // File seed used for encryption
    DWORD nBlocks = 0;                  // Number of file blocks
    DWORD nBlock = 0;                   // Currently processed file block
    int nError = ERROR_SUCCESS;

    // When file length is zero, do nothing
    if(pBlock->dwFSize == 0)
        return ERROR_SUCCESS;

    // Calculate number of blocks in the file
    if(nError == ERROR_SUCCESS)
    {
        nBlocks = pBlock->dwFSize / ha->dwBlockSize;
        if(pBlock->dwFSize % ha->dwBlockSize)
            nBlocks++;
        pbBlock = ALLOCMEM(BYTE, ha->dwBlockSize);
        if(pbBlock == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Set the position to the begin of the file within archive
    if(nError == ERROR_SUCCESS)
    {
        FilePos.HighPart = pBlockEx->wFilePosHigh;
        FilePos.LowPart = pBlock->dwFilePos;
        FilePos.QuadPart += ha->MpqPos.QuadPart;
        if(SetFilePointer(ha->hFile, FilePos.LowPart, &FilePos.HighPart, FILE_BEGIN) != FilePos.LowPart)
            nError = GetLastError();
    }

    // Remember the position in the destination file
    if(nError == ERROR_SUCCESS)
    {
        FilePos.HighPart = 0;
        FilePos.LowPart = SetFilePointer(hFile, 0, &FilePos.HighPart, FILE_CURRENT);
    }

    // Resolve decryption seeds. The 'dwSeed' parameter is the decryption
    // seed for the file.
    if(nError == ERROR_SUCCESS && (pBlock->dwFlags & MPQ_FILE_ENCRYPTED))
    {
        dwSeed1 = dwSeed;
        if(pBlock->dwFlags & MPQ_FILE_FIXSEED)
            dwSeed = (dwSeed1 ^ pBlock->dwFSize) - pBlock->dwFilePos;

        dwSeed2 = dwSeed;
        if(pBlock->dwFlags & MPQ_FILE_FIXSEED)
            dwSeed2 = (dwSeed + (DWORD)(FilePos.QuadPart - ha->MpqPos.QuadPart)) ^ pBlock->dwFSize;
    }

    // Load the file positions from the archive and save it to the target file
    // (only if the file is compressed)
    if(pBlock->dwFlags & MPQ_FILE_COMPRESSED)
    {
        // Allocate buffers
        if(nError == ERROR_SUCCESS)
        {
            pdwBlockPos = ALLOCMEM(DWORD, nBlocks + 2);
            pdwBlockPos2 = ALLOCMEM(DWORD, nBlocks + 2);

            if(pdwBlockPos == NULL || pdwBlockPos2 == NULL)
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }

        // Load the block positions
        if(nError == ERROR_SUCCESS)
        {
            dwBytes = (nBlocks + 1) * sizeof(DWORD);
            if(pBlock->dwFlags & MPQ_FILE_HAS_EXTRA)
                dwBytes += sizeof(DWORD);

            ReadFile(ha->hFile, pdwBlockPos, dwBytes, &dwTransferred, NULL);
            if(dwTransferred != dwBytes)
                nError = ERROR_FILE_CORRUPT;
        }

        // Re-encrypt the block table positions
        if(nError == ERROR_SUCCESS)
        {
            BSWAP_ARRAY32_UNSIGNED(pdwBlockPos, dwBytes / sizeof(DWORD));
            if(pBlock->dwFlags & MPQ_FILE_ENCRYPTED)
            {
                DecryptMPQBlock(pdwBlockPos, dwBytes, dwSeed1 - 1);
                if(pdwBlockPos[0] != dwBytes)
                    nError = ERROR_FILE_CORRUPT;
            
                memcpy(pdwBlockPos2, pdwBlockPos, dwBytes);
                EncryptMPQBlock(pdwBlockPos2, dwBytes, dwSeed2 - 1);
            }
            else
            {
                memcpy(pdwBlockPos2, pdwBlockPos, dwBytes);
            }
            BSWAP_ARRAY32_UNSIGNED(pdwBlockPos2, dwBytes / sizeof(DWORD));
        }

        // Write to the target file
        if(nError == ERROR_SUCCESS)
        {
            WriteFile(hFile, pdwBlockPos2, dwBytes, &dwTransferred, NULL);
            dwCSize += dwTransferred;
            if(dwTransferred != dwBytes)
                nError = ERROR_DISK_FULL;
        }
    }

    // Now we have to copy all file block. We will do it without
    // recompression, because re-compression is not necessary in this case
    if(nError == ERROR_SUCCESS)
    {
        for(nBlock = 0; nBlock < nBlocks; nBlock++)
        {
            // Fix: The last block must not be exactly the size of one block.
            dwBytes = ha->dwBlockSize;
            if(nBlock == nBlocks - 1)
            {
                dwBytes = pBlock->dwFSize - (ha->dwBlockSize * (nBlocks - 1));
            }

            if(pBlock->dwFlags & MPQ_FILE_COMPRESSED)
                dwBytes = pdwBlockPos[nBlock+1] - pdwBlockPos[nBlock];

            // Read the file block
            ReadFile(ha->hFile, pbBlock, dwBytes, &dwTransferred, NULL);
            if(dwTransferred != dwBytes)
            {
                nError = ERROR_FILE_CORRUPT;
                break;
            }

            // If necessary, re-encrypt the block
            // Note: Recompression is not necessary here. Unlike encryption, 
            // the compression does not depend on the position of the file in MPQ.
            if((pBlock->dwFlags & MPQ_FILE_ENCRYPTED) && dwSeed1 != dwSeed2)
            {
                BSWAP_ARRAY32_UNSIGNED((DWORD *)pbBlock, dwBytes/sizeof(DWORD));
                DecryptMPQBlock((DWORD *)pbBlock, dwBytes, dwSeed1 + nBlock);
                EncryptMPQBlock((DWORD *)pbBlock, dwBytes, dwSeed2 + nBlock);
                BSWAP_ARRAY32_UNSIGNED((DWORD *)pbBlock, dwBytes/sizeof(DWORD));
            }

            // Now write the block back to the file
            WriteFile(hFile, pbBlock, dwBytes, &dwTransferred, NULL);
            dwCSize += dwTransferred;
            if(dwTransferred != dwBytes)
            {
                nError = ERROR_DISK_FULL;
                break;
            }
        }
    }

    // Copy the file extras, if any
    // These extras does not seem to be encrypted, and their purpose is unknown
    if(nError == ERROR_SUCCESS && (pBlock->dwFlags & MPQ_FILE_HAS_EXTRA))
    {
        dwBytes = pdwBlockPos[nBlocks + 1] - pdwBlockPos[nBlocks];
        if(dwBytes != 0)
        {
            ReadFile(ha->hFile, pbBlock, dwBytes, &dwTransferred, NULL);
            if(dwTransferred == dwBytes)
            {
                WriteFile(hFile, pbBlock, dwBytes, &dwTransferred, NULL);
                dwCSize += dwTransferred;
                if(dwTransferred != dwBytes)
                    nError = ERROR_DISK_FULL;
            }
            else
            {
                nError = ERROR_FILE_CORRUPT;
            }
        }
    }

    // Update file position in the block table
    if(nError == ERROR_SUCCESS)
    {
        // At this point, number of bytes written should be exactly
        // the same like the compressed file size. If it isn't, there's something wrong
        // (maybe new archive version ?)
        assert(dwCSize == pBlock->dwCSize);

        // Update file pos in the block table
        FilePos.QuadPart -= ha->MpqPos.QuadPart;
        pBlockEx->wFilePosHigh = (USHORT)FilePos.HighPart;
        pBlock->dwFilePos = FilePos.LowPart;
    }

    // Cleanup and return
    if(pdwBlockPos2 != NULL)
        FREEMEM(pdwBlockPos2);
    if(pdwBlockPos != NULL)
        FREEMEM(pdwBlockPos);
    if(pbBlock != NULL)
        FREEMEM(pbBlock);
    return nError;
}


static int CopyNonMpqData(
    HANDLE hSrcFile,
    HANDLE hTrgFile,
    LARGE_INTEGER & DataSizeToCopy)
{
    LARGE_INTEGER DataSize = DataSizeToCopy;
    DWORD dwTransferred;
    DWORD dwToRead;
    char DataBuffer[0x1000];
    int nError = ERROR_SUCCESS;

    while(DataSize.QuadPart > 0)
    {
        // Get the proper size of data
        dwToRead = sizeof(DataBuffer);
        if(DataSize.HighPart == 0 && DataSize.LowPart < dwToRead)
            dwToRead = DataSize.LowPart;

        // Read the source file
        ReadFile(hSrcFile, DataBuffer, dwToRead, &dwTransferred, NULL);
        if(dwTransferred != dwToRead)
        {
            nError = ERROR_CAN_NOT_COMPLETE;
            break;
        }

        // Write to the target file
        WriteFile(hTrgFile, DataBuffer, dwToRead, &dwTransferred, NULL);
        if(dwTransferred != dwToRead)
        {
            nError = ERROR_DISK_FULL;
            break;
        }

        // Decrement the number of data to be copied
        DataSize.QuadPart -= dwTransferred;
    }

    return ERROR_SUCCESS;
}

// TODO: Test for archives > 4GB
static int CopyMpqFiles(HANDLE hFile, TMPQArchive * ha, DWORD * pFileSeeds)
{
    TMPQBlockEx * pBlockEx;
    TMPQBlock * pBlock;
    DWORD dwSeed1;
    DWORD dwIndex;
    int nError = ERROR_SUCCESS;

    // Walk through all files and write them to the destination MPQ archive
    for(dwIndex = 0; dwIndex < ha->pHeader->dwBlockTableSize; dwIndex++)
    {
        pBlockEx = ha->pExtBlockTable + dwIndex;
        pBlock = ha->pBlockTable + dwIndex;
        dwSeed1 = pFileSeeds[dwIndex];

        // Notify the caller about work
        if(CompactCB != NULL)
            CompactCB(lpUserData, CCB_COMPACTING_FILES, dwIndex, ha->pHeader->dwBlockTableSize);

//      if(dwIndex == 0x1B9)
//          DebugBreak();

        // Copy all the file blocks
        // Debug: Break at (dwIndex == 5973)
        if(pBlock->dwFlags & MPQ_FILE_EXISTS)
        {
            nError = CopyMpqFileBlocks(hFile, ha, pBlockEx, pBlock, dwSeed1);
            if(nError != ERROR_SUCCESS)
                break;
        }
    }

    // Cleanup and exit
    return nError;
}


/*****************************************************************************/
/* Public functions                                                          */
/*****************************************************************************/

BOOL WINAPI SFileSetCompactCallback(HANDLE /* hMPQ */, COMPACTCB aCompactCB, void * lpData)
{
    CompactCB = aCompactCB;
    lpUserData = lpData;
    return TRUE;
}

//-----------------------------------------------------------------------------
// Archive compacting (incomplete)

// TODO: Test for archives > 4GB
BOOL WINAPI SFileCompactArchive(HANDLE hMPQ, const char * szListFile, BOOL /* bReserved */)
{
    TMPQArchive * ha = (TMPQArchive *)hMPQ;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    DWORD * pFileSeeds = NULL;
    char szTempFile[MAX_PATH] = "";
    char * szTemp = NULL;
    DWORD dwTransferred;
    int nError = ERROR_SUCCESS;

    // Test the valid parameters
    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_PARAMETER;

    // Create the table with file seeds
    if(nError == ERROR_SUCCESS)
    {
        if((pFileSeeds = ALLOCMEM(DWORD, ha->pHeader->dwBlockTableSize)) != NULL)
            memset(pFileSeeds, 0, sizeof(DWORD) * ha->pHeader->dwBlockTableSize);
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // First of all, we have to check of we are able to decrypt all files.
    // If not, sorry, but the archive cannot be compacted.
    if(nError == ERROR_SUCCESS)
        nError = CheckIfAllFilesKnown(ha, szListFile, pFileSeeds);

    // Get the temporary file name and create it
    if(nError == ERROR_SUCCESS)
    {
        if(CompactCB != NULL)
            CompactCB(lpUserData, CCB_COPYING_NON_MPQ_DATA, 0, 0);

        strcpy(szTempFile, ha->szFileName);
        if((szTemp = strrchr(szTempFile, '.')) != NULL)
            strcpy(szTemp + 1, "mp_");
        else
            strcat(szTempFile, "_");

        hFile = CreateFile(szTempFile, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, 0, NULL);
        if(hFile == INVALID_HANDLE_VALUE)
            nError = GetLastError();
    }

    // Write the data before MPQ header (if any)
    if(nError == ERROR_SUCCESS && ha->MpqPos.QuadPart > 0)
    {
        SetFilePointer(ha->hFile, 0, NULL, FILE_BEGIN);
        if(ha->pShunt != NULL)
            nError = CopyNonMpqData(ha->hFile, hFile, ha->ShuntPos);
        else
            nError = CopyNonMpqData(ha->hFile, hFile, ha->MpqPos);
    }

    // Write the MPQ shunt (if any)
    if(nError == ERROR_SUCCESS && ha->pShunt != NULL)
    {
        BSWAP_TMPQSHUNT(ha->pShunt);
        WriteFile(hFile, ha->pShunt, sizeof(TMPQShunt), &dwTransferred, NULL);
        BSWAP_TMPQSHUNT(ha->pShunt);

        if(dwTransferred != sizeof(TMPQShunt))
            nError = ERROR_DISK_FULL;
    }

    // Write the data between MPQ shunt and the MPQ header (if any)
    if(nError == ERROR_SUCCESS && ha->pShunt != NULL)
    {
        LARGE_INTEGER BytesToCopy;

        BytesToCopy.QuadPart = ha->MpqPos.QuadPart - (ha->ShuntPos.QuadPart + sizeof(TMPQShunt));
        nError = CopyNonMpqData(ha->hFile, hFile, BytesToCopy);
    }

    // Write the MPQ header
    if(nError == ERROR_SUCCESS)
    {
        BSWAP_TMPQHEADER(ha->pHeader);
        WriteFile(hFile, ha->pHeader, ha->pHeader->dwHeaderSize, &dwTransferred, NULL);
        BSWAP_TMPQHEADER(ha->pHeader);
        if(dwTransferred != ha->pHeader->dwHeaderSize)
            nError = ERROR_DISK_FULL;
    }

    // Write the data between the header and between the first file
    // For this, we have to determine where the first file begins
    if(nError == ERROR_SUCCESS)
    {
        LARGE_INTEGER FirstFilePos;
        LARGE_INTEGER TempPos;
        TMPQBlockEx * pBlockEx = ha->pExtBlockTable;
        TMPQBlock * pBlockEnd = ha->pBlockTable + ha->pHeader->dwBlockTableSize;
        TMPQBlock * pBlock = ha->pBlockTable;

        // Maximum file position
        FirstFilePos.HighPart = 0x7FFFFFFF;
        FirstFilePos.LowPart = 0xFFFFFFFF;

        // Find the block with the least position in the MPQ
        while(pBlock < pBlockEnd)
        {
            TempPos.HighPart = pBlockEx->wFilePosHigh;
            TempPos.LowPart = pBlock->dwFilePos;
            if(TempPos.QuadPart < FirstFilePos.QuadPart)
                FirstFilePos = TempPos;
        
            pBlockEx++;
            pBlock++;
        }

        // Set the position in the source file right after the file header
        TempPos.QuadPart = ha->MpqPos.QuadPart + ha->pHeader->dwHeaderSize;
        SetFilePointer(ha->hFile, TempPos.LowPart, &TempPos.HighPart, FILE_BEGIN);

        // Get the number of bytes to copy
        FirstFilePos.QuadPart -= ha->pHeader->dwHeaderSize;
        nError = CopyNonMpqData(ha->hFile, hFile, FirstFilePos);
    }

    // Now write all file blocks.
    if(nError == ERROR_SUCCESS)
        nError = CopyMpqFiles(hFile, ha, pFileSeeds);

    // Now we need to update the tables positions
    // (but only if the tables are at the end of the file)
    if(nError == ERROR_SUCCESS)
    {
        LARGE_INTEGER RelativePos;
        LARGE_INTEGER FilePos = {0};

        // Set the hash table position
        FilePos.LowPart = SetFilePointer(hFile, 0, &FilePos.HighPart, FILE_CURRENT);
        RelativePos.QuadPart = FilePos.QuadPart - ha->MpqPos.QuadPart;
        ha->pHeader->wHashTablePosHigh = (USHORT)RelativePos.HighPart;
        ha->pHeader->dwHashTablePos = RelativePos.LowPart;
        ha->HashTablePos = FilePos;

        // Set the block table position
        RelativePos.QuadPart += ha->pHeader->dwHashTableSize * sizeof(TMPQHash);
        FilePos.QuadPart += ha->pHeader->dwHashTableSize * sizeof(TMPQHash);
        ha->pHeader->wBlockTablePosHigh = (USHORT)RelativePos.HighPart;
        ha->pHeader->dwBlockTablePos = RelativePos.LowPart;
        ha->BlockTablePos = FilePos;

        // Set the extended block table position
        RelativePos.QuadPart += ha->pHeader->dwBlockTableSize * sizeof(TMPQBlock);
        FilePos.QuadPart += ha->pHeader->dwBlockTableSize * sizeof(TMPQBlock);
        if(ha->ExtBlockTablePos.QuadPart != 0)
        {
            ha->pHeader->ExtBlockTablePos = RelativePos;
            ha->ExtBlockTablePos = FilePos;

            RelativePos.QuadPart += ha->pHeader->dwBlockTableSize * sizeof(TMPQBlockEx);
            FilePos.QuadPart += ha->pHeader->dwBlockTableSize * sizeof(TMPQBlockEx);
        }

        // Set the archive size
        ha->pHeader->dwArchiveSize = RelativePos.LowPart;
        ha->MpqSize = RelativePos;
    }

    // If succeeded, update the tables in the file
    if(nError == ERROR_SUCCESS)
    {
        CloseHandle(ha->hFile);
        ha->FilePointer.QuadPart = 0;
        ha->hFile = hFile;
        hFile = INVALID_HANDLE_VALUE;
        nError = SaveMPQTables(ha);
    }

    // If all succeeded, switch the archives
    if(nError == ERROR_SUCCESS)
    {
        if(CompactCB != NULL)
            CompactCB(lpUserData, CCB_CLOSING_ARCHIVE, 0, 0);

        if(!DeleteFile(ha->szFileName) ||           // Delete the old archive
           !CloseHandle(ha->hFile)     ||           // Close the new archive
           !MoveFile(szTempFile, ha->szFileName))   // Rename the temporary archive
            nError = GetLastError();
    }

    // Now open the freshly renamed archive file
    if(nError == ERROR_SUCCESS)
    {
        ha->hFile = CreateFile(ha->szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
        if(ha->hFile == INVALID_HANDLE_VALUE)
            nError = GetLastError();
    }

    // Invalidate the positions of the archive
    if(nError == ERROR_SUCCESS)
    {
        ha->FilePointer.QuadPart = 0;
        ha->pLastFile  = NULL;
        ha->dwBlockPos = 0;
        ha->dwBuffPos  = 0;
    }

    // Cleanup and return
    if(hFile != INVALID_HANDLE_VALUE)
        CloseHandle(hFile);
    if(pFileSeeds != NULL)
        FREEMEM(pFileSeeds);
    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    DeleteFile(szTempFile);
    CompactCB = NULL;
    return (nError == ERROR_SUCCESS);
}
