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

typedef struct _BLTE_FRAME
{
    BYTE CompressedSize[4];                     // Compressed file size as big endian
    BYTE FrameSize[4];                          // File size as big endian
    BYTE md5[MD5_HASH_SIZE];                    // Hash of the compressed frame

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
            CASC_FREE(szDataFile);
        }
    }

    // Return error or success
    hf->pStream = hs->DataFileArray[hf->ArchiveIndex];
    return (hf->pStream != NULL) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
}

static int LoadFileFrames(TCascFile * hf)
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
    pFileFrames = pFileFrame = CASC_ALLOC(BLTE_FRAME, hf->FrameCount);
    if(pFileFrames != NULL)
    {
        // Load the frame array
        ArchiveFileOffset = hf->FramesOffset;
        if(FileStream_Read(hf->pStream, &ArchiveFileOffset, pFileFrames, hf->FrameCount * sizeof(BLTE_FRAME)))
        {
            // Move the raw archive offset
            ArchiveFileOffset += (hf->FrameCount * sizeof(BLTE_FRAME));

            // Copy the frames to the file structure
            for(DWORD i = 0; i < hf->FrameCount; i++, pFileFrame++)
            {
                hf->pFrames[i].FrameArchiveOffset = (DWORD)ArchiveFileOffset;
                hf->pFrames[i].FrameFileOffset = FrameOffset;
                hf->pFrames[i].CompressedSize = ConvertBytesToInteger_4(pFileFrame->CompressedSize);
                hf->pFrames[i].FrameSize = ConvertBytesToInteger_4(pFileFrame->FrameSize);
                memcpy(hf->pFrames[i].md5, pFileFrame->md5, MD5_HASH_SIZE);

                ArchiveFileOffset += hf->pFrames[i].CompressedSize;
                FrameOffset += hf->pFrames[i].FrameSize;
                FileSize += hf->pFrames[i].FrameSize;
            }
        }
        else
            nError = GetLastError();

        // Note: Do not take the FileSize from the sum of frames.
        // This value is invalid when loading the ENCODING file.
//      hf->FileSize = FileSize;

#ifdef CASCLIB_TEST
        hf->FileSize_FrameSum = FileSize;
#endif

        // Free the array
        CASC_FREE(pFileFrames);
    }
    else
        nError = ERROR_NOT_ENOUGH_MEMORY;

    return nError;
}

static int EnsureHeaderAreaIsLoaded(TCascFile * hf)
{
    TCascStorage * hs = hf->hs;
    ULONGLONG FileOffset = hf->HeaderOffset;
    LPBYTE pbHeaderArea;
    DWORD FileSignature;
    DWORD FileSize;
    BYTE HeaderArea[MAX_HEADER_AREA_SIZE];
    int nError;

    // We need the data file to be open
    nError = EnsureDataStreamIsOpen(hf);
    if(nError != ERROR_SUCCESS)
        return nError;

    // Make sure that we already know the shift
    // to the begin of file data.
    // Note that older builds of Heroes of the Storm have entries pointing
    // to the beginning of the header area.
    // Newer versions of HOTS have encoding entries pointing directly to
    // the BLTE header
    if(hs->dwFileBeginDelta == 0xFFFFFFFF)
    {
        FileSignature = 0;
        FileOffset = hf->HeaderOffset;
        if(!FileStream_Read(hf->pStream, &FileOffset, &FileSignature, sizeof(DWORD)))
            return ERROR_FILE_CORRUPT;

        hs->dwFileBeginDelta = (FileSignature == BLTE_HEADER_SIGNATURE) ? BLTE_HEADER_DELTA : 0;
    }
           
    // If the file size is not loaded yet, do it
    if(hf->FrameCount == 0)
    {
        // Load the part before BLTE header + header itself
        FileOffset = hf->HeaderOffset - hs->dwFileBeginDelta;
        if(!FileStream_Read(hf->pStream, &FileOffset, HeaderArea, sizeof(HeaderArea)))
            return ERROR_FILE_CORRUPT;

        // Copy the MD5 hash of the frame array
        memcpy(hf->FrameArrayHash, HeaderArea, MD5_HASH_SIZE);
        pbHeaderArea = HeaderArea + MD5_HASH_SIZE;

        // Copy the file size
        FileSize = ConvertBytesToInteger_4_LE(pbHeaderArea);
        pbHeaderArea += 0x0E;

        // Verify the BLTE signature
        if(ConvertBytesToInteger_4_LE(pbHeaderArea) != BLTE_HEADER_SIGNATURE)
            return ERROR_BAD_FORMAT;
        pbHeaderArea += sizeof(DWORD);

        // Load the size of the frame headers
        hf->HeaderSize = ConvertBytesToInteger_4(pbHeaderArea);
        if(hf->HeaderSize & 0x80000000)
            return ERROR_BAD_FORMAT;
        pbHeaderArea += sizeof(DWORD);

        // Read the header size
        assert(hs->dwFileBeginDelta <= BLTE_HEADER_DELTA);
        hf->HeaderOffset += (BLTE_HEADER_DELTA - hs->dwFileBeginDelta);
        hf->FrameCount = 1;

        // Retrieve the frame count, if different from 1
        if(hf->HeaderSize != 0)
        {
            // The next byte must be 0x0F
            if(pbHeaderArea[0] != 0x0F)
                return ERROR_BAD_FORMAT;
            pbHeaderArea++;

            // Next three bytes form number of frames
            hf->FrameCount = ConvertBytesToInteger_3(pbHeaderArea);
        }

#ifdef CASCLIB_TEST
        hf->FileSize_HdrArea = FileSize;
#endif
    }

    return ERROR_SUCCESS;
}

static int EnsureFrameHeadersLoaded(TCascFile * hf)
{
    int nError;

    // Make sure we have header area loaded
    nError = EnsureHeaderAreaIsLoaded(hf);
    if(nError != ERROR_SUCCESS)
        return nError;

    // If the frame headers are not loaded yet, do it
    if(hf->pFrames == NULL)
    {
        // Allocate the frame array
        hf->pFrames = CASC_ALLOC(CASC_FILE_FRAME, hf->FrameCount);
        if(hf->pFrames != NULL)
        {
            // Either load the frames from the file or supply them on our own
            if(hf->HeaderSize != 0)
            {
                hf->FramesOffset = hf->HeaderOffset + sizeof(DWORD) + sizeof(DWORD) + sizeof(DWORD);
                nError = LoadFileFrames(hf);
            }
            else
            {
                // Offset of the first frame is right after the file frames
                hf->FramesOffset = hf->HeaderOffset + sizeof(DWORD) + sizeof(DWORD);
                
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

//
// THE FILE SIZE PROBLEM
//
// There are members called "FileSize" in many CASC-related structure
// For various files, these variables have different meaning.
//
// Storage      FileName  FileSize     FrameSum    HdrArea     IdxEntry    EncEntry    RootEntry
// -----------  --------  ----------   --------    --------    --------    --------    ---------
// HotS(29049)  ENCODING  0x0024BA45 - 0x0024b98a  0x0024BA45  0x0024BA45  n/a         n/a
// HotS(29049)  ROOT      0x00193340 - 0x00193340  0x0010db65  0x0010db65  0x00193340  n/a
// HotS(29049)  (other)   0x00001080 - 0x00001080  0x000008eb  0x000008eb  0x00001080  0x00001080
//
// WoW(18888)   ENCODING  0x030d487b - 0x030dee79  0x030d487b  0x030d487b  n/a         n/a
// WoW(18888)   ROOT      0x016a9800 - n/a         0x0131313d  0x0131313d  0x016a9800  n/a
// WoW(18888)   (other)   0x000007d0 - 0x000007d0  0x00000397  0x00000397  0x000007d0  n/a
//

DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh)
{
    TCascFile * hf;
    int nError;

    CASCLIB_UNUSED(pdwFileSizeHigh);

    // Validate the file handle
    if((hf = IsValidFileHandle(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return CASC_INVALID_SIZE;
    }

    // Make sure that the file header area is loaded
    nError = EnsureHeaderAreaIsLoaded(hf);
    if(nError != ERROR_SUCCESS)
    {
        SetLastError(nError);
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

    // If the file frames are not loaded yet, do it now
    if(nError == ERROR_SUCCESS)
    {
        nError = EnsureFrameHeadersLoaded(hf);
    }

    // If the file position is at or beyond end of file, do nothing
    if(nError == ERROR_SUCCESS && hf->FilePointer >= hf->FileSize)
    {
        *pdwBytesRead = 0;
        return ERROR_SUCCESS;
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
                if(!VerifyDataBlockHash(pbRawData, pFrame->CompressedSize, pFrame->md5))
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

