/****************************************************************************/
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
// Local functions

static int EnsureDataStreamIsOpen(TCascFile * hf)
{
    TCascStorage * hs = hf->hs;
    TFileStream * pStream = NULL;
    ULONGLONG EncodedSize = 0;
    TCHAR * szDataFile;
    TCHAR szCachePath[MAX_PATH];
    TCHAR szPlainName[0x80];
    int nError;

    // If the file is available locally, we rely on data files.
    // If not, we download the file and open the stream
    if(hf->pCKeyEntry->Flags & CASC_CE_FILE_IS_LOCAL)
    {
        // If the file is not open yet, do it
        if(hs->DataFiles[hf->ArchiveIndex] == NULL)
        {
            // Prepare the name of the data file
            CascStrPrintf(szPlainName, _countof(szPlainName), _T("data.%03u"), hf->ArchiveIndex);
            szDataFile = CombinePath(hs->szIndexPath, szPlainName);

            // Open the data file
            if(szDataFile != NULL)
            {
                // Open the data stream with read+write sharing to prevent Battle.net agent
                // detecting a corruption and redownloading the entire package
                pStream = FileStream_OpenFile(szDataFile, STREAM_FLAG_READ_ONLY | STREAM_FLAG_WRITE_SHARE | STREAM_PROVIDER_FLAT | STREAM_FLAG_FILL_MISSING | BASE_PROVIDER_FILE);
                hs->DataFiles[hf->ArchiveIndex] = pStream;
                CASC_FREE(szDataFile);
            }
        }

        // Return error or success
        hf->pStream = hs->DataFiles[hf->ArchiveIndex];
        return (hf->pStream != NULL) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
    }
    else
    {
        if(hf->bDownloadFileIf)
        {
            // Create the local folder path and download the file from CDN
            nError = DownloadFileFromCDN(hf->hs, _T("data"), hf->pCKeyEntry->EKey, NULL, szCachePath, _countof(szCachePath));
            if(nError == ERROR_SUCCESS)
            {
                hf->pStream = FileStream_OpenFile(szCachePath, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
                if(hf->pStream != NULL)
                {
                    // Supply the file size, if unknown yet
                    if(hf->EncodedSize == CASC_INVALID_SIZE)
                    {
                        FileStream_GetSize(hf->pStream, &EncodedSize);
                        hf->pCKeyEntry->EncodedSize = (DWORD)EncodedSize;
                        hf->EncodedSize = (DWORD)EncodedSize;
                    }

                    hf->bLocalFileStream = true;
                    return ERROR_SUCCESS;
                }
            }
        }

        return ERROR_FILE_OFFLINE;
    }
}

#ifdef _DEBUG
static unsigned int table_16C57A8[0x10] =
{
    0x049396B8, 0x72A82A9B, 0xEE626CCA, 0x9917754F,
    0x15DE40B1, 0xF5A8A9B6, 0x421EAC7E, 0xA9D55C9A,
    0x317FD40C, 0x04FAF80D, 0x3D6BE971, 0x52933CFD,
    0x27F64B7D, 0xC6F5C11B, 0xD5757E3A, 0x6C388745
};

// Obtained from Agent.exe v 2.15.0.6296 (d14ec9d9a1b396a42964b05f40ea55f37eae5478d550c07ebb6cb09e50968d62)
// Note the "Checksum" value probably won't match with older game versions.
static void VerifyHeaderSpan(PBLTE_ENCODED_HEADER pBlteHeader, ULONGLONG HeaderOffset)
{
    LPBYTE pbBlteHeader = (LPBYTE)pBlteHeader;
    DWORD dwInt32;
    BYTE EncodedOffset[4] = { 0 };
    BYTE HashedHeader[4] = { 0 };
    BYTE JenkinsHash[4];
    BYTE Checksum[4];
    size_t i, j;

    // Seems to be hardcoded to zero
    assert(pBlteHeader->field_15 == 0);

    // Calculate the Jenkins hash and write it to the header
    dwInt32 = hashlittle(pbBlteHeader, FIELD_OFFSET(BLTE_ENCODED_HEADER, JenkinsHash), 0x3D6BE971);
    ConvertIntegerToBytes_4_LE(dwInt32, JenkinsHash);
//  assert(memcmp(pBlteHeader->JenkinsHash, JenkinsHash, sizeof(JenkinsHash)) == 0);

    // Encode the lower 32-bits of the offset
    dwInt32 = (DWORD)(HeaderOffset + FIELD_OFFSET(BLTE_ENCODED_HEADER, Signature));
    dwInt32 = table_16C57A8[dwInt32 & 0x0F] ^ dwInt32;
    ConvertIntegerToBytes_4_LE(dwInt32, EncodedOffset);

    // Calculate checksum of the so-far filled structure
    for (i = 0; i < FIELD_OFFSET(BLTE_ENCODED_HEADER, Checksum); i++)
        HashedHeader[i & 3] ^= pbBlteHeader[i];

    // XOR the two values together to get the final checksum.
    for (j = 0; j < 4; j++, i++)
        Checksum[j] = HashedHeader[i & 3] ^ EncodedOffset[i & 3];
//  assert(memcmp(pBlteHeader->Checksum, Checksum, sizeof(Checksum)) == 0);
}
#endif

static int ParseBlteHeader(TCascFile * hf, ULONGLONG HeaderOffset, LPBYTE pbEncodedBuffer, size_t cbEncodedBuffer, size_t * pcbHeaderSize)
{
    PBLTE_ENCODED_HEADER pEncodedHeader = (PBLTE_ENCODED_HEADER)pbEncodedBuffer;
    PBLTE_HEADER pBlteHeader = (PBLTE_HEADER)pbEncodedBuffer;
    DWORD ExpectedHeaderSize;
    DWORD ExHeaderSize = 0;
    DWORD HeaderSize;
    DWORD FrameCount = 0;

    CASCLIB_UNUSED(HeaderOffset);

    // On files within storage segments ("data.###"), there is BLTE_ENCODED_HEADER
    // On local files, there is just PBLTE_HEADER
    if(ConvertBytesToInteger_4_LE(pBlteHeader->Signature) != BLTE_HEADER_SIGNATURE)
    {
        // There must be at least some bytes
        if (cbEncodedBuffer < FIELD_OFFSET(BLTE_ENCODED_HEADER, MustBe0F))
            return ERROR_BAD_FORMAT;
        if (pEncodedHeader->EncodedSize != hf->EncodedSize)
            return ERROR_BAD_FORMAT;

#ifdef _DEBUG
        // Not really needed, it's here just for explanation of what the values mean
        //assert(memcmp(hf->pCKeyEntry->EKey, pEncodedHeader->EKey.Value, MD5_HASH_SIZE) == 0);
        VerifyHeaderSpan(pEncodedHeader, HeaderOffset);
#endif
        // Capture the EKey
        ExHeaderSize = FIELD_OFFSET(BLTE_ENCODED_HEADER, Signature);
        pBlteHeader = (PBLTE_HEADER)(pbEncodedBuffer + ExHeaderSize);
    }

    // Verify the signature
    if(ConvertBytesToInteger_4_LE(pBlteHeader->Signature) != BLTE_HEADER_SIGNATURE)
        return ERROR_BAD_FORMAT;

    // Capture the header size. If this is non-zero, then array
    // of chunk headers follow. Otherwise, the file is just one chunk
    HeaderSize = ConvertBytesToInteger_4(pBlteHeader->HeaderSize);
    if (HeaderSize != 0)
    {
        if (pBlteHeader->MustBe0F != 0x0F)
            return ERROR_BAD_FORMAT;
        
        // Verify the header size
        FrameCount = ConvertBytesToInteger_3(pBlteHeader->FrameCount);
        ExpectedHeaderSize = 0x0C + FrameCount * sizeof(BLTE_FRAME);
        if (ExpectedHeaderSize != HeaderSize)
            return ERROR_BAD_FORMAT;

        // Give the values
        pcbHeaderSize[0] = ExHeaderSize + FIELD_OFFSET(BLTE_HEADER, MustBe0F) + sizeof(DWORD);
    }
    else
    {
        pcbHeaderSize[0] = ExHeaderSize + FIELD_OFFSET(BLTE_HEADER, MustBe0F);
    }

    // Give the frame count
    hf->FrameCount = FrameCount;
    return ERROR_SUCCESS;
}

static LPBYTE ReadMissingHeaderData(TCascFile * hf, ULONGLONG DataFileOffset, LPBYTE pbEncodedBuffer, size_t cbEncodedBuffer, size_t cbTotalHeaderSize)
{
    LPBYTE pbNewBuffer;

    // Reallocate the buffer
    pbNewBuffer = CASC_REALLOC(BYTE, pbEncodedBuffer, cbTotalHeaderSize);
    if (pbNewBuffer != NULL)
    {
        // Load the missing data
        DataFileOffset += cbEncodedBuffer;
        if (FileStream_Read(hf->pStream, &DataFileOffset, pbNewBuffer + cbEncodedBuffer, (DWORD)(cbTotalHeaderSize - cbEncodedBuffer)))
        {
            return pbNewBuffer;
        }
    }

    // If anything failed, we free the original buffer and return NULL;
    CASC_FREE(pbEncodedBuffer);
    return NULL;
}

static int LoadFileFrames(TCascFile * hf, ULONGLONG DataFileOffset, LPBYTE pbFramePtr, LPBYTE pbFrameEnd, size_t cbHeaderSize)
{
    PBLTE_FRAME pFileFrame;
    DWORD ContentSize = 0;
    DWORD FileOffset = 0;
    int nError = ERROR_SUCCESS;

    assert(hf != NULL);
    assert(hf->pStream != NULL);
    assert(hf->pFrames == NULL);

    if (hf->FrameCount != 0)
    {
        // Move the raw archive offset
        DataFileOffset += (hf->FrameCount * sizeof(BLTE_FRAME));

        // Allocate array of file frames
        hf->pFrames = CASC_ALLOC(CASC_FILE_FRAME, hf->FrameCount);
        if (hf->pFrames != NULL)
        {
            // Copy the frames to the file structure
            for (DWORD i = 0; i < hf->FrameCount; i++, pbFramePtr += sizeof(BLTE_FRAME))
            {
                // Capture the file frame
                if ((pbFramePtr + sizeof(BLTE_FRAME)) > pbFrameEnd)
                    return ERROR_BAD_FORMAT;
                pFileFrame = (PBLTE_FRAME)pbFramePtr;

                // Convert the file frame to the native format
                hf->pFrames[i].DataFileOffset = (DWORD)DataFileOffset;
                hf->pFrames[i].FileOffset = CASC_INVALID_POS;
                hf->pFrames[i].EncodedSize = ConvertBytesToInteger_4(pFileFrame->EncodedSize);
                hf->pFrames[i].ContentSize = ConvertBytesToInteger_4(pFileFrame->ContentSize);
                hf->pFrames[i].FrameHash = pFileFrame->FrameHash;

                DataFileOffset += hf->pFrames[i].EncodedSize;
                ContentSize += hf->pFrames[i].ContentSize;
                FileOffset += hf->pFrames[i].ContentSize;
            }

            // Save the content size of the file
            if(hf->pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
            {
                hf->pCKeyEntry->ContentSize = ContentSize;
                hf->ContentSize = ContentSize;
            }
        }
    }
    else
    {
        // The content size in the file structure must be valid at this point,
        // otherwise we don't know the frame content size
        if (hf->ContentSize == CASC_INVALID_SIZE)
        {
            assert(false);
            return ERROR_CAN_NOT_COMPLETE;
        }

        // Save the number of file frames
        hf->FrameCount = 1;

        // Allocate single "dummy" frame
        hf->pFrames = CASC_ALLOC(CASC_FILE_FRAME, 1);
        if (hf->pFrames != NULL)
        {
            memset(&hf->pFrames->FrameHash, 0, sizeof(CONTENT_KEY));
            hf->pFrames->DataFileOffset = (DWORD)DataFileOffset;
            hf->pFrames->FileOffset = CASC_INVALID_POS;
            hf->pFrames->EncodedSize = (DWORD)(hf->EncodedSize - cbHeaderSize);
            hf->pFrames->ContentSize = hf->ContentSize;
        }
    }

    if (hf->pFrames == NULL)
        nError = ERROR_NOT_ENOUGH_MEMORY;
    return nError;
}

static int LoadEncodedHeaderAndFileFrames(TCascFile * hf)
{
    LPBYTE pbEncodedBuffer;
    size_t cbEncodedBuffer = MAX_ENCODED_HEADER;
    int nError = ERROR_SUCCESS;

    // Should only be called when the file frames are NOT loaded
    assert(hf->pFrames == NULL);
    assert(hf->FrameCount == 0);

    // Allocate the initial buffer for the encoded headers
    pbEncodedBuffer = CASC_ALLOC(BYTE, MAX_ENCODED_HEADER);
    if (pbEncodedBuffer != NULL)
    {
        ULONGLONG ReadOffset = hf->ArchiveOffset;
        size_t cbTotalHeaderSize;
        size_t cbHeaderSize = 0;

        // At this point, we expect encoded size to be known
        assert(hf->EncodedSize != CASC_INVALID_SIZE);

        // Do not read more than encoded size
        cbEncodedBuffer = CASCLIB_MIN(cbEncodedBuffer, hf->EncodedSize);

        // Load the entire (eventual) header area. This is faster than doing
        // two read operations in a row. Read as much as possible. If the file is cut,
        // the FileStream will pad it with zeros
        if (FileStream_Read(hf->pStream, &ReadOffset, pbEncodedBuffer, (DWORD)cbEncodedBuffer))
        {
            // Parse the BLTE header
            nError = ParseBlteHeader(hf, ReadOffset, pbEncodedBuffer, cbEncodedBuffer, &cbHeaderSize);
            if (nError == ERROR_SUCCESS)
            {
                // If the headers are larger than the initial read size,
                // We read the missing data
                cbTotalHeaderSize = cbHeaderSize + (hf->FrameCount * sizeof(BLTE_FRAME));
                if (cbTotalHeaderSize > cbEncodedBuffer)
                {
                    pbEncodedBuffer = ReadMissingHeaderData(hf, ReadOffset, pbEncodedBuffer, cbEncodedBuffer, cbTotalHeaderSize);
                    if (pbEncodedBuffer == NULL)
                        nError = GetLastError();
                    cbEncodedBuffer = cbTotalHeaderSize;
                }

                // Load the array of frame headers
                if (nError == ERROR_SUCCESS)
                {
                    nError = LoadFileFrames(hf, ReadOffset + cbHeaderSize, pbEncodedBuffer + cbHeaderSize, pbEncodedBuffer + cbEncodedBuffer, cbHeaderSize);
                }
            }
        }
        else
        {
            nError = ERROR_FILE_CORRUPT;
        }

        // Free the frame buffer
        CASC_FREE(pbEncodedBuffer);
    }
    else
    {
        nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    return nError;
}

static int EnsureFileFramesLoaded(TCascFile * hf)
{
    int nError = ERROR_SUCCESS;

    // If the encoded frames are not loaded, do it now
    if(hf->pFrames == NULL)
    {
        // We need the data file to be open
        nError = EnsureDataStreamIsOpen(hf);
        if(nError != ERROR_SUCCESS)
            return nError;

        // Make sure we have header area loaded
        nError = LoadEncodedHeaderAndFileFrames(hf);
    }

    return nError;
}

static int LoadEncodedFrame(TFileStream * pStream, PCASC_FILE_FRAME pFrame, LPBYTE pbEncodedFrame, bool bVerifyIntegrity)
{
    ULONGLONG FileOffset = pFrame->DataFileOffset;
    int nError = ERROR_SUCCESS;

    // Load the encoded frame to memory
    if(FileStream_Read(pStream, &FileOffset, pbEncodedFrame, pFrame->EncodedSize))
    {
        if (bVerifyIntegrity)
        {
            if (!CascVerifyDataBlockHash(pbEncodedFrame, pFrame->EncodedSize, pFrame->FrameHash.Value))
                nError = ERROR_FILE_CORRUPT;
        }
    }
    else
    {
        nError = GetLastError();
    }

    return nError;
}

static int ProcessFileFrame(
    TCascStorage * hs,
    LPBYTE pbOutBuffer,
    DWORD  cbOutBuffer,
    LPBYTE pbInBuffer,
    DWORD cbInBuffer,
    DWORD dwFrameIndex)
{
    LPBYTE pbWorkBuffer = NULL;
    DWORD cbOutBufferExpected = 0;
    DWORD cbWorkBuffer = 0;
    DWORD dwStepCount = 0;
    bool bWorkComplete = false;
    int nError = ERROR_SUCCESS;

    // Perform the loop
    while(bWorkComplete == false)
    {
        // There should never be a 3rd step
        assert(dwStepCount < 2);

        // Perform the operation specific by the first byte
        switch(pbInBuffer[0])
        {
            case 'E':   // Encrypted files
                
                // The work buffer should not have been allocated by any step
                assert(pbWorkBuffer == NULL && cbWorkBuffer == 0);

                // Allocate temporary buffer to decrypt into
                // Example storage: "2016 - WoW/23420", File: "4ee6bc9c6564227f1748abd0b088e950"
                pbWorkBuffer = CASC_ALLOC(BYTE, cbInBuffer - 1);
                cbWorkBuffer = cbInBuffer - 1;
                if(pbWorkBuffer == NULL)
                    return ERROR_NOT_ENOUGH_MEMORY;

                // Decrypt the stream to the work buffer
                nError = CascDecrypt(hs, pbWorkBuffer, &cbWorkBuffer, pbInBuffer + 1, cbInBuffer - 1, dwFrameIndex);
                if(nError != ERROR_SUCCESS)
                {
                    bWorkComplete = true;
                    break;
                }

                // When encrypted, there is always one more step after this.
                // Setup the work buffer as input buffer for the next operation
                pbInBuffer = pbWorkBuffer;
                cbInBuffer = cbWorkBuffer;
                break;

            case 'Z':   // ZLIB compressed files
                
                // If we decompressed less than expected, we simply fill the rest with zeros
                // Example: INSTALL file from the TACT CASC storage
                cbOutBufferExpected = cbOutBuffer;
                nError = CascDecompress(pbOutBuffer, &cbOutBuffer, pbInBuffer + 1, cbInBuffer - 1);

                // We exactly know what the output buffer size will be.
                // If the uncompressed data is smaller, fill the rest with zeros
                if(cbOutBuffer < cbOutBufferExpected)
                    memset(pbOutBuffer + cbOutBuffer, 0, (cbOutBufferExpected - cbOutBuffer));
                bWorkComplete = true;
                break;

            case 'N':   // Normal stored files
                nError = CascDirectCopy(pbOutBuffer, &cbOutBuffer, pbInBuffer + 1, cbInBuffer - 1);
                bWorkComplete = true;
                break;

            case 'F':   // Recursive frames - not supported
            default:    // Unrecognized - if we unpacked something, we consider it done
                nError = ERROR_NOT_SUPPORTED;
                bWorkComplete = true;
                assert(false);
                break;
        }

        // Increment the step count
        dwStepCount++;
    }

    // Free the temporary buffer
    CASC_FREE(pbWorkBuffer);
    return nError;
}

static bool GetFileFullInfo(TCascFile * hf, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded)
{
    PCASC_FILE_FULL_INFO pFileInfo;
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    TCascStorage * hs = hf->hs;

    // Verify whether we have enough space in the buffer
    pFileInfo = (PCASC_FILE_FULL_INFO)ProbeOutputBuffer(pvFileInfo, cbFileInfo, sizeof(CASC_FILE_FULL_INFO), pcbLengthNeeded);
    if(pFileInfo != NULL)
    {
        // Reset the entire structure
        CopyMemory16(pFileInfo->CKey, pCKeyEntry->CKey);
        CopyMemory16(pFileInfo->EKey, pCKeyEntry->EKey);
        pFileInfo->FileDataId = CASC_INVALID_ID;
        pFileInfo->LocaleFlags = CASC_INVALID_ID;
        pFileInfo->ContentFlags = CASC_INVALID_ID;

        // Supply information not depending on root
        CascStrPrintf(pFileInfo->DataFileName, _countof(pFileInfo->DataFileName), "data.%03u", hf->ArchiveIndex);
        pFileInfo->StorageOffset = pCKeyEntry->StorageOffset;
        pFileInfo->SegmentOffset = hf->ArchiveOffset;
        pFileInfo->FileNameHash = 0;
        pFileInfo->TagBitMask = pCKeyEntry->TagBitMask;
        pFileInfo->SegmentIndex = hf->ArchiveIndex;
        pFileInfo->ContentSize = hf->ContentSize;
        pFileInfo->EncodedSize = hf->EncodedSize;

        // Supply the root-specific information
        hs->pRootHandler->GetInfo(pCKeyEntry, pFileInfo);
    }

    return (pFileInfo != NULL);
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascGetFileInfo(HANDLE hFile, CASC_FILE_INFO_CLASS InfoClass, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded)
{
    TCascFile * hf;
    LPBYTE pbOutputValue = NULL;
    LPBYTE pbInfoValue = NULL;
    size_t cbInfoValue = 0;

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Differentiate between info classes
    switch(InfoClass)
    {
        case CascFileContentKey:

            // Do we have content key at all?
            if(hf->pCKeyEntry == NULL || (hf->pCKeyEntry->Flags & CASC_CE_HAS_CKEY) == 0)
            {
                SetLastError(ERROR_NOT_SUPPORTED);
                return false;
            }

            // Give the content key
            pbInfoValue = hf->pCKeyEntry->CKey;
            cbInfoValue = CASC_CKEY_SIZE;
            break;

        case CascFileEncodedKey:

            // Do we have content key at all?
            if(hf->pCKeyEntry == NULL || (hf->pCKeyEntry->Flags & CASC_CE_HAS_EKEY) == 0)
            {
                SetLastError(ERROR_NOT_SUPPORTED);
                return false;
            }

            // Give the content key
            pbInfoValue = hf->pCKeyEntry->EKey;
            cbInfoValue = CASC_CKEY_SIZE;
            break;

        case CascFileFullInfo:
            return GetFileFullInfo(hf, pvFileInfo, cbFileInfo, pcbLengthNeeded);

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
    }

    // Sanity check
    assert(pbInfoValue != NULL);
    assert(cbInfoValue != 0);

    // Give the result
    pbOutputValue = (LPBYTE)ProbeOutputBuffer(pvFileInfo, cbFileInfo, cbInfoValue, pcbLengthNeeded);
    if(pbOutputValue != NULL)
        memcpy(pbOutputValue, pbInfoValue, cbInfoValue);
    return (pbOutputValue != NULL);
}

//
// THE FILE SIZE PROBLEM
//
// There are members called "FileSize" in many CASC-related structure
// For various files, these variables have different meaning.
//
// Storage      FileName  FileSize     FrameSum    HdrArea     CKeyEntry   EKeyEntry   RootEntry
// -----------  --------  ----------   --------    --------    ----------  ----------  ----------
// HotS(29049)  ENCODING  0x0024BA45 - 0x0024b98a  0x0024BA45  n/a         0x0024BA45  n/a
// HotS(29049)  ROOT      0x00193340 - 0x00193340  0x0010db65  0x00193340  0x0010db65  n/a
// HotS(29049)  (other)   0x00001080 - 0x00001080  0x000008eb  0x00001080  0x000008eb  0x00001080
//                                                             
// WoW(18888)   ENCODING  0x030d487b - 0x030dee79  0x030d487b  n/a         0x030d487b  n/a
// WoW(18888)   ROOT      0x016a9800 - n/a         0x0131313d  0x016a9800  0x0131313d  n/a
// WoW(18888)   (other)   0x000007d0 - 0x000007d0  0x00000397  0x000007d0  0x00000397  n/a
//

DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh)
{
    TCascFile * hf;
    int nError;

    CASCLIB_UNUSED(pdwFileSizeHigh);

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return CASC_INVALID_SIZE;
    }

    // Someone may have provided file content size.
    // If yes, do not load the frames, as it's not necessary.
    if(hf->ContentSize == CASC_INVALID_SIZE)
    {
        // Make sure that the file header area is loaded
        nError = EnsureFileFramesLoaded(hf);
        if(nError != ERROR_SUCCESS)
        {
            SetLastError(nError);
            return CASC_INVALID_SIZE;
        }

        // The content size should be loaded from the frames
        assert(hf->ContentSize != CASC_INVALID_SIZE);
    }

    // Give the file size to the caller
    if(pdwFileSizeHigh != NULL)
        *pdwFileSizeHigh = 0;
    return hf->ContentSize;
}

DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod)
{
    TCascFile * hf;
    ULONGLONG FilePosition;
    ULONGLONG MoveOffset;
    DWORD dwFilePosHi;

    // If the hFile is not a valid file handle, return an error.
    hf = TCascFile::IsValid(hFile);
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
            FilePosition = hf->ContentSize;
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
    TCascFile * hf;
    int nError = ERROR_SUCCESS;

    // The buffer must be valid
    if(pvBuffer == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // If the file frames are not loaded yet, do it now
    if(nError == ERROR_SUCCESS)
    {
        nError = EnsureFileFramesLoaded(hf);
    }

    // If the file position is at or beyond end of file, do nothing
    if(nError == ERROR_SUCCESS)
    {
        // Check the starting position
        if(hf->FilePointer >= hf->ContentSize)
        {
            *pdwBytesRead = 0;
            return true;
        }

        // Check the ending position
        if((hf->FilePointer + dwBytesToRead) > hf->ContentSize)
        {
            dwBytesToRead = hf->ContentSize - hf->FilePointer;
        }
    }

    // Allocate cache buffer for the entire file. This is the fastest approach
    // (without reallocations). However, this may consume quite a lot of memory
    // (Storage: "2016 - Starcraft II/45364", file: "3d815f40c0413701aa2bd214070d0062"
    // needs 0x239a09b3 bytes of memory (~600 MB)
    if(nError == ERROR_SUCCESS)
    {
        if(hf->pbFileCache == NULL)
        {
            // Allocate buffer
            hf->pbFileCache = CASC_ALLOC(BYTE, hf->ContentSize);
            hf->cbFileCache = hf->ContentSize;
            if(hf->pbFileCache == NULL)
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Load all frames that are not loaded yet
    if(nError == ERROR_SUCCESS)
    {
        PCASC_FILE_FRAME pFrame = hf->pFrames;
        DWORD StartFrameOffset = 0;
        DWORD StartReadOffset = hf->FilePointer;
        DWORD EndReadOffset = hf->FilePointer + dwBytesToRead;

        for(DWORD i = 0; (i < hf->FrameCount) && (nError == ERROR_SUCCESS); i++, pFrame++)
        {
            LPBYTE pbDecodedFrame = hf->pbFileCache + StartFrameOffset;
            LPBYTE pbEncodedFrame;
            DWORD EndFrameOffset = StartFrameOffset + pFrame->ContentSize;

            // Does that frame belong to the range?
            if(StartReadOffset < EndFrameOffset && EndReadOffset > StartFrameOffset)
            {
                // Is the frame already loaded?
                if (pFrame->FileOffset == CASC_INVALID_POS)
                {
                    // Allocate space for the encoded frame
                    pbEncodedFrame = CASC_ALLOC(BYTE, pFrame->EncodedSize);
                    if (pbEncodedFrame != NULL)
                    {
                        // Load the encoded frame data
                        nError = LoadEncodedFrame(hf->pStream, pFrame, pbEncodedFrame, hf->bVerifyIntegrity);
                        if (nError == ERROR_SUCCESS)
                        {
                            // Decode the frame
                            nError = ProcessFileFrame(hf->hs,
                                                      pbDecodedFrame,
                                                      pFrame->ContentSize,
                                                      pbEncodedFrame,
                                                      pFrame->EncodedSize,
                                              (DWORD)(pFrame - hf->pFrames));

                            // Some people find it handy to extract data from partially encrypted file,
                            // even at the cost producing files that are corrupt.
                            // We overcome missing decryption key by zeroing the encrypted portions
                            if(nError == ERROR_FILE_ENCRYPTED && hf->bOvercomeEncrypted)
                            {
                                memset(pbDecodedFrame, 0, pFrame->ContentSize);
                                nError = ERROR_SUCCESS;
                            }

                            if (nError == ERROR_SUCCESS)
                            {
                                // Mark the frame as loaded
                                pFrame->FileOffset = StartFrameOffset;
                            }
                        }

                        // Free the frame buffer
                        CASC_FREE(pbEncodedFrame);
                    }
                    else
                    {
                        nError = ERROR_NOT_ENOUGH_MEMORY;
                    }
                }
            }

            // If the frame start is past the read offset, stop the loop
            if ((StartFrameOffset + pFrame->ContentSize) >= EndReadOffset)
                break;
            StartFrameOffset += pFrame->ContentSize;
        }
    }

    // Now all frames have been loaded into the cache; copy the entire block to the output buffer
    if(nError == ERROR_SUCCESS)
    {
        // Copy the entire data
        memcpy(pvBuffer, hf->pbFileCache + hf->FilePointer, dwBytesToRead);
        hf->FilePointer += dwBytesToRead;

        // Give the number of bytes read
        if(pdwBytesRead != NULL)
            *pdwBytesRead = dwBytesToRead;
        return true;
    }
    else
    {
        SetLastError(nError);
        return false;
    }
}
