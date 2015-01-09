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
// Local structures

#define BLTE_HEADER_SIGNATURE   0x45544C42

// Data file begin:
//  BYTE  HeaderHash[MD5_HASH_SIZE];            // MD5 of the frame array
//  DWORD dwFileSize;                           // Size of the file
//  BYTE  SomeSize[4];                          // Some size (big endian)
//  BYTE  Padding[6];                           // Padding (?)

typedef struct _BLTE_HEADER
{
    DWORD dwSignature;                          // Must be "BLTE"
    BYTE  HeaderSizeAsBytes[4];                 // Header size in bytes (big endian)
    BYTE  MustBe0F;                             // Must be 0x0F
    BYTE  FrameCount[3];                        // Number of frames (big endian)

} BLTE_HEADER, *PBLTE_HEADER;

typedef struct _BLTE_FRAME
{
    BYTE CompressedSize[4];                     // Compressed file size as big endian
    BYTE FrameSize[4];                          // File size as big endian
    BYTE md5[MD5_HASH_SIZE];                    // Hash of the frame

} BLTE_FRAME, *PBLTE_FRAME;

//-----------------------------------------------------------------------------
// Local functions

TCascFile * IsValidFileHandle(HANDLE hFile);        // In CascOpenFile.cpp

static int EnsureDataStreamIsOpen(TCascFile * hf)
{
    TCascStorage * hs = hf->hs;
    TFileStream * pStream = NULL;
    TCHAR * szDataFile;
    TCHAR szPlainName[0x40];

    // If the file is not open yet, do it
    if(hs->DataFileArray[hf->ArchiveIndex] == NULL)
    {
        // Prepare the name of the data file
        _stprintf(szPlainName, _T("data.%03u"), hf->ArchiveIndex);
        szDataFile = CombinePath(hs->szIndexPath, szPlainName);

        // Open the data file
        if(szDataFile != NULL)
        {
            // Open the stream
            pStream = FileStream_OpenFile(szDataFile, STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
            hs->DataFileArray[hf->ArchiveIndex] = pStream;

            // TODO: There is 0x1E bytes at the beginning of the file stream
            // Ignore them for now, but we will want to know what they mean
            // Offs0000: MD5 of something
            // Offs0010: 2 bytes
            CASC_FREE(szDataFile);
        }
    }

    // Return error or success
    hf->pStream = hs->DataFileArray[hf->ArchiveIndex];
    return (hf->pStream != NULL) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
}

static int LoadFileFrames(TCascFile * hf, DWORD FrameCount)
{
    PBLTE_FRAME pFileFrames;
    PBLTE_FRAME pFileFrame;
    ULONGLONG ArchiveFileOffset;
    DWORD FrameOffset = 0;
    DWORD FileSize = 0;
    int nError = ERROR_SUCCESS;

    assert(hf != NULL);
    assert(hf->pStream != NULL);
    assert(hf->pFrames != NULL);

    // Allocate frame array
    pFileFrames = pFileFrame = CASC_ALLOC(BLTE_FRAME, FrameCount);
    if(pFileFrames != NULL)
    {
        // Load the frame array
        ArchiveFileOffset = hf->FramesOffset;
        if(FileStream_Read(hf->pStream, &ArchiveFileOffset, pFileFrames, FrameCount * sizeof(BLTE_FRAME)))
        {
            // Move the raw archive offset
            ArchiveFileOffset += (hf->FrameCount * sizeof(BLTE_FRAME));

            // Copy the frames to the file structure
            for(DWORD i = 0; i < FrameCount; i++, pFileFrame++)
            {
                hf->pFrames[i].FrameArchiveOffset = (DWORD)ArchiveFileOffset;
                hf->pFrames[i].FrameFileOffset = FrameOffset;
                hf->pFrames[i].CompressedSize = ConvertBytesToInteger_4(pFileFrame->CompressedSize);
                hf->pFrames[i].FrameSize      = ConvertBytesToInteger_4(pFileFrame->FrameSize);
                memcpy(hf->pFrames[i].md5, pFileFrame->md5, MD5_HASH_SIZE);

                ArchiveFileOffset += hf->pFrames[i].CompressedSize;
                FrameOffset += hf->pFrames[i].FrameSize;
                FileSize += hf->pFrames[i].FrameSize;
            }

            // Fill-in the frame count
            hf->FrameCount = FrameCount;
        }
        else
            nError = GetLastError();

        // Verify the file size
//      assert(FileSize == hf->FileSize);
//      hf->FileSize = FileSize;

        // Free the array
        CASC_FREE(pFileFrames);
    }
    else
        nError = ERROR_NOT_ENOUGH_MEMORY;

    return nError;
}

static int EnsureFrameHeadersLoaded(TCascFile * hf)
{
    PBLTE_HEADER pBlteHeader;
    ULONGLONG FileOffset = hf->HeaderOffset;
    DWORD dwHeaderOffsetFixup = 0;
    DWORD dwFrameHeaderSize;
    DWORD dwFrameCount;
    BYTE HeaderBuffer[sizeof(BLTE_HEADER) + 0x20];
    int nError = ERROR_SUCCESS;

    // Sanity check
    assert(hf->pStream != NULL);

    // If the frame headers are not loaded yet, do it
    if(hf->pFrames == NULL)
    {
        // Note that older builds of Heroes of the Storm have entries pointing
        // to the begin of the BLTE header, which is MD5 + some junk.
        // Newer versions of HOTS have encoding entries pointing directly to
        // the BLTE header
        FileStream_Read(hf->pStream, &FileOffset, HeaderBuffer, sizeof(HeaderBuffer));
        pBlteHeader = (PBLTE_HEADER)HeaderBuffer;

        // If we don't have the BLTE header right there,
        // just get the block that is 0x1E bytes later
        if(pBlteHeader->dwSignature != BLTE_HEADER_SIGNATURE)
        {
            memcpy(&HeaderBuffer[0x00], &HeaderBuffer[0x1E], sizeof(BLTE_HEADER));
            dwHeaderOffsetFixup = 0x1E;
        }

        // Check for the BLTE header signature
        if(pBlteHeader->dwSignature != BLTE_HEADER_SIGNATURE)
            return ERROR_BAD_FORMAT;
        hf->HeaderOffset += dwHeaderOffsetFixup;

        // Check for a single unit file
        dwFrameHeaderSize = ConvertBytesToInteger_4(pBlteHeader->HeaderSizeAsBytes);
        dwFrameCount = (dwFrameHeaderSize != 0) ? ConvertBytesToInteger_3(pBlteHeader->FrameCount) : 1;

        // Allocate the frame array
        hf->pFrames = CASC_ALLOC(CASC_FILE_FRAME, dwFrameCount);
        if(hf->pFrames != NULL)
        {
            // Save the number of frames
            hf->FrameCount = dwFrameCount;

            // Either load the frames from the file or supply them on our own
            if(dwFrameHeaderSize != 0)
            {
                if(pBlteHeader->MustBe0F != 0x0F)
                    return ERROR_FILE_CORRUPT;

                hf->FramesOffset = hf->HeaderOffset + sizeof(BLTE_HEADER);
                nError = LoadFileFrames(hf, dwFrameCount);
            }
            else
            {
                // Offset of the first frame is right after the file frames
                hf->FramesOffset = hf->HeaderOffset + sizeof(pBlteHeader->dwSignature) + sizeof(pBlteHeader->HeaderSizeAsBytes);
                
                hf->pFrames[0].FrameArchiveOffset = hf->FramesOffset;
                hf->pFrames[0].FrameFileOffset = 0;
                hf->pFrames[0].CompressedSize = hf->CompressedSize;
                hf->pFrames[0].FrameSize      = hf->FileSize;
                memset(hf->pFrames[0].md5, 0, MD5_HASH_SIZE);
            }
        }

        // Return result
        return (hf->pFrames != NULL) ? ERROR_SUCCESS : ERROR_FILE_CORRUPT;
    }

    return ERROR_SUCCESS;
}

static PCASC_FILE_FRAME FindFileFrame(TCascFile * hf, DWORD FilePointer)
{
    PCASC_FILE_FRAME pFrame = hf->pFrames;
    DWORD FrameBegin;
    DWORD FrameEnd;

    // Sanity checks
    assert(hf->pFrames != NULL);
    assert(hf->FrameCount != 0);

    // Find the frame where to read from
    for(DWORD i = 0; i < hf->FrameCount; i++, pFrame++)
    {
        // Does the read request fit into the current frame?
        FrameBegin = pFrame->FrameFileOffset;
        FrameEnd = FrameBegin + pFrame->FrameSize;
        if(FrameBegin <= FilePointer && FilePointer < FrameEnd)
            return pFrame;
    }

    // Not found, sorry
    return NULL;
}

//-----------------------------------------------------------------------------
// Public functions

DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh)
{
    TCascFile * hf;

    CASCLIB_UNUSED(pdwFileSizeHigh);

    // Validate the file handle
    if((hf = IsValidFileHandle(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return CASC_INVALID_SIZE;
    }

    // Give the file size to the caller
    if(pdwFileSizeHigh != NULL)
        *pdwFileSizeHigh = 0;
    return hf->FileSize;
}

DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod)
{
    TCascFile * hf;
    ULONGLONG FilePosition;
    ULONGLONG MoveOffset;
    DWORD dwFilePosHi;

    // If the hFile is not a valid file handle, return an error.
    hf = IsValidFileHandle(hFile);
    if(hf == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return CASC_INVALID_POS;
    }

    // Get the relative point where to move from
    switch(dwMoveMethod)
    {
        case FILE_BEGIN:
            FilePosition = 0;
            break;

        case FILE_CURRENT:
            FilePosition = hf->FilePointer;
            break;

        case FILE_END:
            FilePosition = hf->FileSize;
            break;

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return CASC_INVALID_POS;
    }

    // Now get the move offset. Note that both values form
    // a signed 64-bit value (a file pointer can be moved backwards)
    if(plFilePosHigh != NULL)
        dwFilePosHi = *plFilePosHigh;
    else
        dwFilePosHi = (lFilePos & 0x80000000) ? 0xFFFFFFFF : 0;
    MoveOffset = MAKE_OFFSET64(dwFilePosHi, lFilePos);

    // Now calculate the new file pointer
    // Do not allow the file pointer to overflow
    FilePosition = ((FilePosition + MoveOffset) >= FilePosition) ? (FilePosition + MoveOffset) : 0;

    // CASC files can't be bigger than 4 GB.
    // We don't allow to go past 4 GB
    if(FilePosition >> 32)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return CASC_INVALID_POS;
    }

    // Change the file position
    hf->FilePointer = (DWORD)FilePosition;

    // Return the new file position
    if(plFilePosHigh != NULL)
        *plFilePosHigh = 0;
    return hf->FilePointer;
}

bool WINAPI CascReadFile(HANDLE hFile, void * pvBuffer, DWORD dwBytesToRead, PDWORD pdwBytesRead)
{
    PCASC_FILE_FRAME pFrame = NULL;
    ULONGLONG FileOffset;
    TCascFile * hf;
    LPBYTE pbBuffer = (LPBYTE)pvBuffer;
    DWORD dwStartPointer = 0;
    DWORD dwFilePointer = 0;
    DWORD dwEndPointer = 0;
    DWORD cbOutBuffer;
    int nError = ERROR_SUCCESS;

    // The buffer must be valid
    if(pvBuffer == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Validate the file handle
    if((hf = IsValidFileHandle(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // If the file position is at or beyond end of file, do nothing
    if(hf->FilePointer >= hf->FileSize)
    {
        *pdwBytesRead = 0;
        return ERROR_SUCCESS;
    }

    // Make sure we have that data file open
    if(nError == ERROR_SUCCESS)
    {
        nError = EnsureDataStreamIsOpen(hf);
    }

    // If the file frames are not loaded yet, do it now
    if(nError == ERROR_SUCCESS)
    {
        nError = EnsureFrameHeadersLoaded(hf);
    }

    // Find the file frame where to read from
    if(nError == ERROR_SUCCESS)
    {
        // Get the frame
        pFrame = FindFileFrame(hf, hf->FilePointer);
        if(pFrame == NULL)
            nError = ERROR_FILE_CORRUPT;
    }

    // Perform the read
    if(nError == ERROR_SUCCESS)
    {
        // If not enough bytes in the file remaining, cut them
        dwStartPointer = dwFilePointer = hf->FilePointer;
        dwEndPointer = dwStartPointer + dwBytesToRead;
        if(dwEndPointer > hf->FileSize)
            dwEndPointer = hf->FileSize;

        // Perform block read from each file frame
        while(dwFilePointer < dwEndPointer)
        {
            LPBYTE pbRawData = NULL;
            DWORD dwFrameStart = pFrame->FrameFileOffset;
            DWORD dwFrameEnd = pFrame->FrameFileOffset + pFrame->FrameSize;

            // Shall we populate the cache with a new data?
            if(dwFrameStart != hf->CacheStart || hf->CacheEnd != dwFrameEnd)
            {
                // Shall we reallocate the cache buffer?
                if(pFrame->FrameSize > hf->cbFileCache)
                {
                    if(hf->pbFileCache != NULL)
                        CASC_FREE(hf->pbFileCache);
                    
                    hf->pbFileCache = CASC_ALLOC(BYTE, pFrame->FrameSize);
                    hf->cbFileCache = pFrame->FrameSize;
                }

                // We also need to allocate buffer for the raw data
                pbRawData = CASC_ALLOC(BYTE, pFrame->CompressedSize);
                if(pbRawData == NULL)
                {
                    nError = ERROR_NOT_ENOUGH_MEMORY;
                    break;
                }

                // Load the raw file data to memory
                FileOffset = pFrame->FrameArchiveOffset;
                if(!FileStream_Read(hf->pStream, &FileOffset, pbRawData, pFrame->CompressedSize))
                {
                    CASC_FREE(pbRawData);
                    nError = GetLastError();
                    break;
                }

                // Verify the block MD5
                if(IsValidMD5(pFrame->md5) && !VerifyDataBlockHash(pbRawData, pFrame->CompressedSize, pFrame->md5))
                {
                    CASC_FREE(pbRawData);
                    nError = ERROR_FILE_CORRUPT;
                    break;
                }

                // Decompress the file frame
                cbOutBuffer = pFrame->FrameSize;
                nError = CascDecompress(hf->pbFileCache, &cbOutBuffer, pbRawData, pFrame->CompressedSize);
                if(nError != ERROR_SUCCESS || cbOutBuffer != pFrame->FrameSize)
                {
                    CASC_FREE(pbRawData);
                    nError = ERROR_FILE_CORRUPT;
                    break;
                }

                // Set the start and end of the cache
                hf->CacheStart = dwFrameStart;
                hf->CacheEnd = dwFrameEnd;

                // Free the decompress buffer, if needed
                CASC_FREE(pbRawData);
            }

            // Copy the decompressed data
            if(dwFrameEnd > dwEndPointer)
                dwFrameEnd = dwEndPointer;
            memcpy(pbBuffer, hf->pbFileCache + (dwFilePointer - dwFrameStart), (dwFrameEnd - dwFilePointer));
            pbBuffer += (dwFrameEnd - dwFilePointer);

            // Move pointers
            dwFilePointer = dwFrameEnd;
            pFrame++;
        }
    }

    // Update the file position
    if(nError == ERROR_SUCCESS)
    {
        if(pdwBytesRead != NULL)
            *pdwBytesRead = (dwFilePointer - dwStartPointer);
        hf->FilePointer = dwFilePointer;
    }

    if(nError != ERROR_SUCCESS)
        SetLastError(nError);
    return (nError == ERROR_SUCCESS);
}

