/*****************************************************************************/
/* SAttrFile.cpp                          Copyright (c) Ladislav Zezula 2007 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 12.06.04  1.00  Lad  The first version of SAttrFile.cpp                   */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local structures

typedef struct _MPQ_ATTRIBUTES_HEADER
{
    DWORD dwVersion;                    // Version of the (attributes) file. Must be 100 (0x64)
    DWORD dwFlags;                      // See MPQ_ATTRIBUTE_XXXX

    // Followed by an array of CRC32
    // Followed by an array of file times
    // Followed by an array of MD5
} MPQ_ATTRIBUTES_HEADER, *PMPQ_ATTRIBUTES_HEADER;

//-----------------------------------------------------------------------------
// Public functions (internal use by StormLib)

int SAttrLoadAttributes(TMPQArchive * ha)
{
    MPQ_ATTRIBUTES_HEADER AttrHeader;
    TMPQFile * hf;
    HANDLE hFile = NULL;
    DWORD dwBlockTableSize = ha->pHeader->dwBlockTableSize;
    DWORD dwArraySize;
    DWORD dwBytesRead;
    DWORD i;
    int nError = ERROR_SUCCESS;

    // File table must be initialized
    assert(ha->pFileTable != NULL);

    // Attempt to open the "(attributes)" file.
    // If it's not there, then the archive doesn't support attributes
    if(SFileOpenFileEx((HANDLE)ha, ATTRIBUTES_NAME, SFILE_OPEN_ANY_LOCALE, &hFile))
    {
        // Remember the flags for (attributes)
        hf = (TMPQFile *)hFile;
        ha->dwFileFlags2 = hf->pFileEntry->dwFlags;

        // Load the content of the attributes file
        SFileReadFile(hFile, &AttrHeader, sizeof(MPQ_ATTRIBUTES_HEADER), &dwBytesRead, NULL);
        if(dwBytesRead != sizeof(MPQ_ATTRIBUTES_HEADER))
            nError = ERROR_FILE_CORRUPT;

        // Verify the header of the (attributes) file
        if(nError == ERROR_SUCCESS)
        {
            AttrHeader.dwVersion = BSWAP_INT32_UNSIGNED(AttrHeader.dwVersion);
            AttrHeader.dwFlags   = BSWAP_INT32_UNSIGNED(AttrHeader.dwFlags);
            ha->dwAttrFlags      = AttrHeader.dwFlags;
            if(dwBytesRead != sizeof(MPQ_ATTRIBUTES_HEADER))
                nError = ERROR_FILE_CORRUPT;
        }

        // Verify format of the attributes
        if(nError == ERROR_SUCCESS)
        {
            if(AttrHeader.dwVersion > MPQ_ATTRIBUTES_V1)
                nError = ERROR_BAD_FORMAT;
        }

        // Load the CRC32 (if any)
        if(nError == ERROR_SUCCESS && (AttrHeader.dwFlags & MPQ_ATTRIBUTE_CRC32))
        {
            LPDWORD pArrayCRC32 = STORM_ALLOC(DWORD, dwBlockTableSize);

            if(pArrayCRC32 != NULL)
            {
                dwArraySize = dwBlockTableSize * sizeof(DWORD);
                SFileReadFile(hFile, pArrayCRC32, dwArraySize, &dwBytesRead, NULL);
                if(dwBytesRead == dwArraySize)
                {
                     for(i = 0; i < dwBlockTableSize; i++)
                        ha->pFileTable[i].dwCrc32 = BSWAP_INT32_UNSIGNED(pArrayCRC32[i]);
                }
                else
                    nError = ERROR_FILE_CORRUPT;

                STORM_FREE(pArrayCRC32);
            }
            else
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }

        // Read the array of file times
        if(nError == ERROR_SUCCESS && (AttrHeader.dwFlags & MPQ_ATTRIBUTE_FILETIME))
        {
            ULONGLONG * pArrayFileTime = STORM_ALLOC(ULONGLONG, dwBlockTableSize);

            if(pArrayFileTime != NULL)
            {
                dwArraySize = dwBlockTableSize * sizeof(ULONGLONG);
                SFileReadFile(hFile, pArrayFileTime, dwArraySize, &dwBytesRead, NULL);
                if(dwBytesRead == dwArraySize)
                {
                    for(i = 0; i < dwBlockTableSize; i++)
                        ha->pFileTable[i].FileTime = BSWAP_INT64_UNSIGNED(pArrayFileTime[i]);
                }
                else
                    nError = ERROR_FILE_CORRUPT;

                STORM_FREE(pArrayFileTime);
            }
            else
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }

        // Read the MD5 (if any)
        // Note: MD5 array can be incomplete, if it's the last array in the (attributes)
        if(nError == ERROR_SUCCESS && (AttrHeader.dwFlags & MPQ_ATTRIBUTE_MD5))
        {
            unsigned char * pArrayMD5 = STORM_ALLOC(unsigned char, (dwBlockTableSize * MD5_DIGEST_SIZE));
            unsigned char * md5;

            if(pArrayMD5 != NULL)
            {
                dwArraySize = dwBlockTableSize * MD5_DIGEST_SIZE;
                SFileReadFile(hFile, pArrayMD5, dwArraySize, &dwBytesRead, NULL);
                if(dwBytesRead == dwArraySize)
                {
                    md5 = pArrayMD5;
                    for(i = 0; i < dwBlockTableSize; i++)
                    {
                        memcpy(ha->pFileTable[i].md5, md5, MD5_DIGEST_SIZE);
                        md5 += MD5_DIGEST_SIZE;
                    }
                }
                else
                    nError = ERROR_FILE_CORRUPT;

                STORM_FREE(pArrayMD5);
            }
            else
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }

        // 
        // Note: Version 7.00 of StormLib saved the (attributes) incorrectly. 
        // Sometimes, number of entries in the (attributes) was 1 item less
        // than block table size. 
        // If we encounter such table, we will zero all three arrays
        //

        if(nError != ERROR_SUCCESS)
            ha->dwAttrFlags = 0;

        // Cleanup & exit
        SFileCloseFile(hFile);
    }
    return nError;
}

int SAttrFileSaveToMpq(TMPQArchive * ha)
{
    MPQ_ATTRIBUTES_HEADER AttrHeader;
    TFileEntry * pFileEntry;
    TMPQFile * hf = NULL;
    DWORD dwFinalBlockTableSize = ha->dwFileTableSize;
    DWORD dwFileSize = 0;
    DWORD dwToWrite;
    DWORD i;
    int nError = ERROR_SUCCESS;

    // If the (attributes) is not in the file table yet,
    // we have to increase the final block table size
    pFileEntry = GetFileEntryExact(ha, ATTRIBUTES_NAME, LANG_NEUTRAL);
    if(pFileEntry != NULL)
    {
        // If "(attributes)" file exists, and it's set to 0, then remove it
        if(ha->dwAttrFlags == 0)
        {
            FreeFileEntry(ha, pFileEntry);
            return ERROR_SUCCESS;
        }
    }
    else
    {
        // If we don't want to create file atributes, do nothing
        if(ha->dwAttrFlags == 0)
            return ERROR_SUCCESS;

        // Check where the file entry is going to be allocated.
        // If at the end of the file table, we have to increment
        // the expected size of the (attributes) file.
        pFileEntry = FindFreeFileEntry(ha);
        if(pFileEntry == ha->pFileTable + ha->dwFileTableSize)
            dwFinalBlockTableSize++;
    }

    // Calculate the size of the attributes file
    if(nError == ERROR_SUCCESS)
    {
        dwFileSize = sizeof(MPQ_ATTRIBUTES_HEADER);         // Header
        if(ha->dwAttrFlags & MPQ_ATTRIBUTE_CRC32)
            dwFileSize += dwFinalBlockTableSize * sizeof(DWORD);
        if(ha->dwAttrFlags & MPQ_ATTRIBUTE_FILETIME)
            dwFileSize += dwFinalBlockTableSize * sizeof(ULONGLONG);
        if(ha->dwAttrFlags & MPQ_ATTRIBUTE_MD5)
            dwFileSize += dwFinalBlockTableSize * MD5_DIGEST_SIZE;
    }

    // Create the attributes file in the MPQ
    assert(ha->dwFileFlags2 != 0);
    nError = SFileAddFile_Init(ha, ATTRIBUTES_NAME,
                                   0,
                                   dwFileSize,
                                   LANG_NEUTRAL,
                                   ha->dwFileFlags2,
                                  &hf);

    // Write all parts of the (attributes) file
    if(nError == ERROR_SUCCESS)
    {
        assert(ha->dwFileTableSize == dwFinalBlockTableSize);

        AttrHeader.dwVersion = BSWAP_INT32_UNSIGNED(100);
        AttrHeader.dwFlags   = BSWAP_INT32_UNSIGNED(ha->dwAttrFlags);
        dwToWrite = sizeof(MPQ_ATTRIBUTES_HEADER);
        nError = SFileAddFile_Write(hf, &AttrHeader, dwToWrite, MPQ_COMPRESSION_ZLIB);
    }

    // Write the array of CRC32
    if(nError == ERROR_SUCCESS && (ha->dwAttrFlags & MPQ_ATTRIBUTE_CRC32))
    {
        LPDWORD pArrayCRC32 = STORM_ALLOC(DWORD, dwFinalBlockTableSize);

        if(pArrayCRC32 != NULL)
        {
            // Copy from file table
            for(i = 0; i < ha->dwFileTableSize; i++)
                pArrayCRC32[i] = BSWAP_INT32_UNSIGNED(ha->pFileTable[i].dwCrc32);

            dwToWrite = ha->dwFileTableSize * sizeof(DWORD);
            nError = SFileAddFile_Write(hf, pArrayCRC32, dwToWrite, MPQ_COMPRESSION_ZLIB);
            STORM_FREE(pArrayCRC32);
        }
    }

    // Write the array of file time
    if(nError == ERROR_SUCCESS && (ha->dwAttrFlags & MPQ_ATTRIBUTE_FILETIME))
    {
        ULONGLONG * pArrayFileTime = STORM_ALLOC(ULONGLONG, ha->dwFileTableSize);

        if(pArrayFileTime != NULL)
        {
            // Copy from file table
            for(i = 0; i < ha->dwFileTableSize; i++)
                pArrayFileTime[i] = BSWAP_INT64_UNSIGNED(ha->pFileTable[i].FileTime);

            dwToWrite = ha->dwFileTableSize * sizeof(ULONGLONG);
            nError = SFileAddFile_Write(hf, pArrayFileTime, dwToWrite, MPQ_COMPRESSION_ZLIB);
            STORM_FREE(pArrayFileTime);
        }
    }

    // Write the array of MD5s
    if(nError == ERROR_SUCCESS && (ha->dwAttrFlags & MPQ_ATTRIBUTE_MD5))
    {
        char * pArrayMD5 = STORM_ALLOC(char, ha->dwFileTableSize * MD5_DIGEST_SIZE);

        if(pArrayMD5 != NULL)
        {
            // Copy from file table
            for(i = 0; i < ha->dwFileTableSize; i++)
                memcpy(&pArrayMD5[i * MD5_DIGEST_SIZE], ha->pFileTable[i].md5, MD5_DIGEST_SIZE);

            dwToWrite = ha->dwFileTableSize * MD5_DIGEST_SIZE;
            nError = SFileAddFile_Write(hf, pArrayMD5, dwToWrite, MPQ_COMPRESSION_ZLIB);
            STORM_FREE(pArrayMD5);
        }
    }

    // Finalize the file in the archive
    if(hf != NULL)
    {
        SFileAddFile_Finish(hf);
    }

    if(nError == ERROR_SUCCESS)
        ha->dwFlags &= ~MPQ_FLAG_INV_ATTRIBUTES;
    return nError;
}

//-----------------------------------------------------------------------------
// Public functions

DWORD WINAPI SFileGetAttributes(HANDLE hMpq)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    // Verify the parameters
    if(!IsValidMpqHandle(ha))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return SFILE_INVALID_ATTRIBUTES;
    }

    return ha->dwAttrFlags;
}

bool WINAPI SFileSetAttributes(HANDLE hMpq, DWORD dwFlags)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    // Verify the parameters
    if(!IsValidMpqHandle(ha))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Not allowed when the archive is read-only
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    // Set the attributes
    InvalidateInternalFiles(ha);
    ha->dwAttrFlags = (dwFlags & MPQ_ATTRIBUTE_ALL);
    return true;
}

bool WINAPI SFileUpdateFileAttributes(HANDLE hMpq, const char * szFileName)
{
    hash_state md5_state;
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    TMPQFile * hf;
    BYTE Buffer[0x1000];
    HANDLE hFile = NULL;
    DWORD dwTotalBytes = 0;
    DWORD dwBytesRead;
    DWORD dwCrc32;

    // Verify the parameters
    if(!IsValidMpqHandle(ha))
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Not allowed when the archive is read-only
    if(ha->dwFlags & MPQ_FLAG_READ_ONLY)
    {
        SetLastError(ERROR_ACCESS_DENIED);
        return false;
    }

    // Attempt to open the file
    if(!SFileOpenFileEx(hMpq, szFileName, SFILE_OPEN_FROM_MPQ, &hFile))
        return false;

    // Get the file size
    hf = (TMPQFile *)hFile;
    SFileGetFileInfo(hFile, SFILE_INFO_FILE_SIZE, &dwTotalBytes, sizeof(DWORD));

    // Initialize the CRC32 and MD5 contexts
    md5_init(&md5_state);
    dwCrc32 = crc32(0, Z_NULL, 0);

    // Go through entire file and calculate both CRC32 and MD5
    while(dwTotalBytes != 0)
    {
        // Read data from file
        SFileReadFile(hFile, Buffer, sizeof(Buffer), &dwBytesRead, NULL);
        if(dwBytesRead == 0)
            break;

        // Update CRC32 and MD5
        dwCrc32 = crc32(dwCrc32, Buffer, dwBytesRead);
        md5_process(&md5_state, Buffer, dwBytesRead);

        // Decrement the total size
        dwTotalBytes -= dwBytesRead;
    }

    // Update both CRC32 and MD5
    hf->pFileEntry->dwCrc32 = dwCrc32;
    md5_done(&md5_state, hf->pFileEntry->md5);

    // Remember that we need to save the MPQ tables
    InvalidateInternalFiles(ha);
    SFileCloseFile(hFile);
    return true;
}
