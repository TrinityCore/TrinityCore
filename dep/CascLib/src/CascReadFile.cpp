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

static DWORD GetStreamEncodedSize(TFileStream * pStream)
{
    ULONGLONG FileSize = 0;

    FileStream_GetSize(pStream, &FileSize);
    assert((FileSize >> 32) == 0);

    return (DWORD)(FileSize);
}

static DWORD OpenDataStream(TCascFile * hf, PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry, bool bDownloadFileIf)
{
    TCascStorage * hs = hf->hs;
    TFileStream * pStream = NULL;
    TCHAR szCachePath[MAX_PATH];
    TCHAR szDataFile[MAX_PATH];
    TCHAR szPlainName[0x80];
    DWORD dwErrCode;

    // If the file is available locally, we rely on data files.
    // If not, we download the file and open the stream
    if(pCKeyEntry->Flags & CASC_CE_FILE_IS_LOCAL)
    {
        DWORD dwArchiveIndex = pFileSpan->ArchiveIndex;

        // Lock the storage to make the operation thread-safe
        CascLock(hs->StorageLock);

        // If the data archive is not open yet, open it now.
        if(hs->DataFiles[dwArchiveIndex] == NULL)
        {
            // Prepare the name of the data file
            CascStrPrintf(szPlainName, _countof(szPlainName), _T("data.%03u"), dwArchiveIndex);
            CombinePath(szDataFile, _countof(szDataFile), PATH_SEP_CHAR, hs->szIndexPath, szPlainName, NULL);

            // Open the data stream with read+write sharing to prevent Battle.net agent
            // detecting a corruption and redownloading the entire package
            pStream = FileStream_OpenFile(szDataFile, STREAM_FLAG_READ_ONLY | STREAM_FLAG_WRITE_SHARE | STREAM_PROVIDER_FLAT | STREAM_FLAG_FILL_MISSING | BASE_PROVIDER_FILE);
            hs->DataFiles[dwArchiveIndex] = pStream;
        }

        // Unlock the storage
        CascUnlock(hs->StorageLock);

        // Return error or success
        pFileSpan->pStream = hs->DataFiles[dwArchiveIndex];
        return (pFileSpan->pStream != NULL) ? ERROR_SUCCESS : ERROR_FILE_NOT_FOUND;
    }
    else
    {
        if(bDownloadFileIf)
        {
            CASC_CDN_DOWNLOAD CdnsInfo = {0};
            LPCTSTR szPathType = (pCKeyEntry->Flags & CASC_CE_FILE_PATCH) ? _T("patch") : _T("data");

            // Prepare the download structure for "%CDNS_HOST%/%CDNS_PATH%/##/##/EKey" file
            CdnsInfo.szCdnsPath = hs->szCdnPath;
            CdnsInfo.szPathType = szPathType;
            CdnsInfo.pbEKey = pCKeyEntry->EKey;
            CdnsInfo.szLocalPath = szCachePath;
            CdnsInfo.ccLocalPath = _countof(szCachePath);

            // Download the file from CDN
            dwErrCode = DownloadFileFromCDN(hs, CdnsInfo);
            if(dwErrCode == ERROR_SUCCESS)
            {
                pStream = FileStream_OpenFile(szCachePath, BASE_PROVIDER_FILE | STREAM_PROVIDER_FLAT);
                if(pStream != NULL)
                {
                    // Initialize information about the position and size of the file in archive
                    // On loose files, their position is zero and encoded size is length of the file
                    if(CdnsInfo.pbArchiveKey != NULL)
                    {
                        // Archive position
                        pFileSpan->ArchiveIndex = CdnsInfo.ArchiveIndex;
                        pFileSpan->ArchiveOffs = (DWORD)CdnsInfo.ArchiveOffs;

                        // Encoded size
                        if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
                            pCKeyEntry->EncodedSize = CdnsInfo.EncodedSize;
                        assert(pCKeyEntry->EncodedSize == CdnsInfo.EncodedSize);
                    }
                    else
                    {
                        // Archive position
                        pFileSpan->ArchiveIndex = 0;
                        pFileSpan->ArchiveOffs = 0;

                        // Encoded size
                        if(pCKeyEntry->EncodedSize == CASC_INVALID_SIZE)
                            pCKeyEntry->EncodedSize = GetStreamEncodedSize(pStream);
                        assert(pCKeyEntry->EncodedSize == GetStreamEncodedSize(pStream));
                    }

                    // We need to close the file stream after we're done
                    pFileSpan->pStream = pStream;
                    hf->bCloseFileStream = true;
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

static DWORD ParseBlteHeader(PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry, ULONGLONG HeaderOffset, LPBYTE pbEncodedBuffer, size_t cbEncodedBuffer, size_t * pcbHeaderSize)
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
        if (pEncodedHeader->EncodedSize != pCKeyEntry->EncodedSize)
            return ERROR_BAD_FORMAT;

#ifdef _DEBUG
        // Not really needed, it's here just for explanation of what the values mean
        //assert(memcmp(pCKeyEntry->EKey, pEncodedHeader->EKey.Value, MD5_HASH_SIZE) == 0);
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
    pFileSpan->FrameCount = FrameCount;
    return ERROR_SUCCESS;
}

static LPBYTE ReadMissingHeaderData(PCASC_FILE_SPAN pFileSpan, ULONGLONG DataFileOffset, LPBYTE pbEncodedBuffer, size_t cbEncodedBuffer, size_t cbTotalHeaderSize)
{
    LPBYTE pbNewBuffer;

    // Reallocate the buffer
    pbNewBuffer = CASC_REALLOC(BYTE, pbEncodedBuffer, cbTotalHeaderSize);
    if (pbNewBuffer != NULL)
    {
        // Load the missing data
        DataFileOffset += cbEncodedBuffer;
        if (FileStream_Read(pFileSpan->pStream, &DataFileOffset, pbNewBuffer + cbEncodedBuffer, (DWORD)(cbTotalHeaderSize - cbEncodedBuffer)))
        {
            return pbNewBuffer;
        }
    }

    // If anything failed, we free the original buffer and return NULL;
    CASC_FREE(pbEncodedBuffer);
    return NULL;
}

static LPBYTE CaptureBlteFileFrame(CASC_FILE_FRAME & Frame, LPBYTE pbFramePtr, LPBYTE pbFrameEnd)
{
    PBLTE_FRAME pFileFrame = (PBLTE_FRAME)pbFramePtr;

    // Check whether we have enough data ready
    if((pbFramePtr + sizeof(BLTE_FRAME)) > pbFrameEnd)
        return NULL;

    Frame.FrameHash   = pFileFrame->FrameHash;
    Frame.ContentSize = ConvertBytesToInteger_4(pFileFrame->ContentSize);
    Frame.EncodedSize = ConvertBytesToInteger_4(pFileFrame->EncodedSize);
    return pbFramePtr + sizeof(BLTE_FRAME);
}

static DWORD LoadSpanFrames(PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry, ULONGLONG DataFileOffset, LPBYTE pbFramePtr, LPBYTE pbFrameEnd, size_t cbHeaderSize)
{
    PCASC_FILE_FRAME pFrames = NULL;
    DWORD ContentSize = 0;
    DWORD dwErrCode = ERROR_SUCCESS;

    assert(pFileSpan != NULL);
    assert(pFileSpan->pStream != NULL);
    assert(pFileSpan->pFrames == NULL);

    if (pFileSpan->FrameCount != 0)
    {
        // Move the raw archive offset
        DataFileOffset += (pFileSpan->FrameCount * sizeof(BLTE_FRAME));

        // Allocate array of file frames
        pFrames = CASC_ALLOC<CASC_FILE_FRAME>(pFileSpan->FrameCount);
        if (pFrames != NULL)
        {
            // Copy the frames to the file structure
            for (DWORD i = 0; i < pFileSpan->FrameCount; i++)
            {
                CASC_FILE_FRAME & Frame = pFrames[i];

                // Capture the single BLTE frame
                pbFramePtr = CaptureBlteFileFrame(Frame, pbFramePtr, pbFrameEnd);
                if(pbFramePtr == NULL)
                {
                    dwErrCode = ERROR_BAD_FORMAT;
                    break;
                }

                // Fill-in the file range of the frame
                Frame.StartOffset = pFileSpan->StartOffset + ContentSize;
                Frame.EndOffset = Frame.StartOffset + Frame.ContentSize;
                ContentSize += Frame.ContentSize;

                // Fill-in the archive range of the frame
                assert((DataFileOffset + Frame.EncodedSize) > DataFileOffset);
                Frame.DataFileOffset = DataFileOffset;
                DataFileOffset += Frame.EncodedSize;
            }

            // Save the content size of the file
            if(pCKeyEntry->ContentSize == CASC_INVALID_SIZE)
            {
                pCKeyEntry->ContentSize = ContentSize;
            }
        }
        else
        {
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }
    }
    else
    {
        // Allocate single "dummy" frame
        pFrames = CASC_ALLOC<CASC_FILE_FRAME>(1);
        if (pFrames != NULL)
        {
            // Fill the single frame
            memset(&pFrames->FrameHash, 0, sizeof(CONTENT_KEY));
            pFrames->StartOffset = pFileSpan->StartOffset;
            pFrames->EndOffset = pFileSpan->EndOffset;
            pFrames->DataFileOffset = DataFileOffset;
            pFrames->EncodedSize = (DWORD)(pCKeyEntry->EncodedSize - cbHeaderSize);
            pFrames->ContentSize = pCKeyEntry->ContentSize;

            // Save the number of file frames
            pFileSpan->FrameCount = 1;
        }
        else
        {
            dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Free the frame array on error
    if(dwErrCode != ERROR_SUCCESS)
    {
        pFileSpan->FrameCount = 0;
        CASC_FREE(pFrames);
    }

    pFileSpan->pFrames = pFrames;
    return dwErrCode;
}

static DWORD LoadSpanFramesForPlainFile(PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry)
{
    PCASC_FILE_FRAME pFrames;

    // Allocate single "dummy" frame
    pFrames = CASC_ALLOC<CASC_FILE_FRAME>(1);
    if (pFrames != NULL)
    {
        // Setup the size
        pFileSpan->EndOffset = pFileSpan->StartOffset + pCKeyEntry->ContentSize;
        pCKeyEntry->Flags |= CASC_CE_PLAIN_DATA;

        // Fill the single frame
        memset(&pFrames->FrameHash, 0, sizeof(CONTENT_KEY));
        pFrames->StartOffset = pFileSpan->StartOffset;
        pFrames->EndOffset = pFrames->StartOffset + pCKeyEntry->ContentSize;
        pFrames->DataFileOffset = 0;
        pFrames->EncodedSize = pCKeyEntry->EncodedSize;
        pFrames->ContentSize = pCKeyEntry->ContentSize;

        // Save the number of file frames
        pFileSpan->FrameCount = 1;
        pFileSpan->pFrames = pFrames;
        return ERROR_SUCCESS;
    }

    return ERROR_NOT_ENOUGH_MEMORY;
}

static DWORD LoadEncodedHeaderAndSpanFrames(PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry)
{
    LPBYTE pbEncodedBuffer;
    size_t cbEncodedBuffer = MAX_ENCODED_HEADER;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Should only be called when the file frames are NOT loaded
    assert(pFileSpan->pFrames == NULL);
    assert(pFileSpan->FrameCount == 0);

    // Allocate the initial buffer for the encoded headers
    pbEncodedBuffer = CASC_ALLOC<BYTE>(MAX_ENCODED_HEADER);
    if (pbEncodedBuffer != NULL)
    {
        ULONGLONG ReadOffset = pFileSpan->ArchiveOffs;
        size_t cbTotalHeaderSize;
        size_t cbHeaderSize = 0;

        // At this point, we expect encoded size to be known
        assert(pCKeyEntry->EncodedSize != CASC_INVALID_SIZE);

        // Do not read more than encoded size
        cbEncodedBuffer = CASCLIB_MIN(cbEncodedBuffer, pCKeyEntry->EncodedSize);

        // Load the entire (eventual) header area. This is faster than doing
        // two read operations in a row. Read as much as possible. If the file is cut,
        // the FileStream will pad it with zeros
        if (FileStream_Read(pFileSpan->pStream, &ReadOffset, pbEncodedBuffer, (DWORD)cbEncodedBuffer))
        {
            // Parse the BLTE header
            dwErrCode = ParseBlteHeader(pFileSpan, pCKeyEntry, ReadOffset, pbEncodedBuffer, cbEncodedBuffer, &cbHeaderSize);
            if (dwErrCode == ERROR_SUCCESS)
            {
                // If the headers are larger than the initial read size, we read the missing data
                pFileSpan->HeaderSize = (DWORD)(cbTotalHeaderSize = cbHeaderSize + (pFileSpan->FrameCount * sizeof(BLTE_FRAME)));
                if (cbTotalHeaderSize > cbEncodedBuffer)
                {
                    pbEncodedBuffer = ReadMissingHeaderData(pFileSpan, ReadOffset, pbEncodedBuffer, cbEncodedBuffer, cbTotalHeaderSize);
                    if (pbEncodedBuffer == NULL)
                        dwErrCode = GetCascError();
                    cbEncodedBuffer = cbTotalHeaderSize;
                }

                // Load the array of frame headers
                if (dwErrCode == ERROR_SUCCESS)
                {
                    assert((ReadOffset + cbHeaderSize) > ReadOffset);
                    dwErrCode = LoadSpanFrames(pFileSpan, pCKeyEntry, ReadOffset + cbHeaderSize, pbEncodedBuffer + cbHeaderSize, pbEncodedBuffer + cbEncodedBuffer, cbHeaderSize);
                }
            }
            else
            {
                // Special treatment for plain files ("PATCH"): If the content size and encoded size
                // are equal, we will create a single fake frame
                if(pCKeyEntry->EncodedSize == pCKeyEntry->ContentSize)
                {
                    dwErrCode = LoadSpanFramesForPlainFile(pFileSpan, pCKeyEntry);
                }
            }
        }
        else
        {
            dwErrCode = ERROR_FILE_CORRUPT;
        }

        // Free the frame buffer
        CASC_FREE(pbEncodedBuffer);
    }
    else
    {
        dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
    }

    return dwErrCode;
}

static DWORD LoadSpanFrames(TCascFile * hf, PCASC_FILE_SPAN pFileSpan, PCASC_CKEY_ENTRY pCKeyEntry)
{
    DWORD dwErrCode = ERROR_SUCCESS;

    // Sanity check
    assert(pFileSpan->pFrames == NULL);

    // Make sure that the data stream is open for that span
    if(pFileSpan->pStream == NULL)
    {
        dwErrCode = OpenDataStream(hf, pFileSpan, pCKeyEntry, hf->bDownloadFileIf);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
    }

    // Make sure we have header area loaded
    return LoadEncodedHeaderAndSpanFrames(pFileSpan, pCKeyEntry);
}

// Loads all file spans to memory
static DWORD LoadFileSpanFrames(TCascFile * hf)
{
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    PCASC_FILE_SPAN pFileSpan = hf->pFileSpan;
    DWORD dwErrCode = ERROR_SUCCESS;

    // If the ContentSize/EncodedSize is still unknown, we need to get it from the file frames
    if(hf->ContentSize == CASC_INVALID_SIZE64 || hf->EncodedSize == CASC_INVALID_SIZE64)
    {
        // Set initially to zero
        hf->ContentSize = 0;
        hf->EncodedSize = 0;

        // Load file frames for all spans
        for(DWORD i = 0; i < hf->SpanCount; i++, pCKeyEntry++, pFileSpan++)
        {
            // Init the range of the file span
            pFileSpan->StartOffset = hf->ContentSize;
            pFileSpan->EndOffset = hf->ContentSize;

            // Load the frames of the file span
            dwErrCode = LoadSpanFrames(hf, pFileSpan, pCKeyEntry);
            if(dwErrCode != ERROR_SUCCESS)
                break;

            hf->ContentSize += pCKeyEntry->ContentSize;
            hf->EncodedSize += pCKeyEntry->EncodedSize;
            pFileSpan->EndOffset = hf->ContentSize;
        }
    }
    else
    {
        // Load file frames for all spans
        for(DWORD i = 0; i < hf->SpanCount; i++, pCKeyEntry++, pFileSpan++)
        {
            // Load the frames of the file span
            dwErrCode = LoadSpanFrames(hf, pFileSpan, pCKeyEntry);
            if(dwErrCode != ERROR_SUCCESS)
                break;
        }
    }

    return dwErrCode;
}

static DWORD EnsureFileSpanFramesLoaded(TCascFile * hf)
{
    DWORD dwErrCode;

    if(hf->ContentSize == CASC_INVALID_SIZE64 || hf->pFileSpan->pFrames == NULL)
    {
        // Load all frames of all file spans
        dwErrCode = LoadFileSpanFrames(hf);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Now the content size must be known
        if(hf->ContentSize == CASC_INVALID_SIZE64)
            return ERROR_CAN_NOT_COMPLETE;
    }

    return ERROR_SUCCESS;
}

static DWORD DecodeFileFrame(
    TCascFile * hf,
    PCASC_CKEY_ENTRY pCKeyEntry,
    PCASC_FILE_FRAME pFrame,
    LPBYTE pbEncoded,
    LPBYTE pbDecoded,
    DWORD FrameIndex)
{
    TCascStorage * hs = hf->hs;
    LPBYTE pbWorkBuffer = NULL;
    DWORD cbDecodedExpected = 0;
    DWORD cbWorkBuffer = 0;
    DWORD dwStepCount = 0;
    DWORD dwErrCode = ERROR_SUCCESS;
    DWORD cbEncoded = pFrame->EncodedSize;
    DWORD cbDecoded = pFrame->ContentSize;
    bool bWorkComplete = false;

    //if(pFrame->EncodedSize == 0xda001)
    //{
    //    FILE * fp = fopen("E:\\frame-da001-002.dat", "wb");
    //    fwrite(pbEncoded, 1, pFrame->EncodedSize, fp);
    //    fclose(fp);
    //}

    // If this is a file span with plain data, just copy the data
    if(pCKeyEntry->Flags & CASC_CE_PLAIN_DATA)
    {
        assert(pCKeyEntry->ContentSize == pCKeyEntry->EncodedSize);
        assert(pCKeyEntry->ContentSize == pFrame->ContentSize);
        assert(pFrame->ContentSize == pFrame->EncodedSize);
        memcpy(pbDecoded, pbEncoded, pCKeyEntry->ContentSize);
        return ERROR_SUCCESS;
    }

    // Shall we verify the frame integrity?
    if(hf->bVerifyIntegrity)
    {
        if(!CascVerifyDataBlockHash(pbEncoded, pFrame->EncodedSize, pFrame->FrameHash.Value))
            return ERROR_FILE_CORRUPT;
    }

    // Perform the loop
    while(bWorkComplete == false)
    {
        // There should never be a 3rd step
        assert(dwStepCount < 2);

        // Perform the operation specific by the first byte
        switch(pbEncoded[0])
        {
            case 'E':   // Encrypted files
                
                // The work buffer should not have been allocated by any step
                assert(pbWorkBuffer == NULL && cbWorkBuffer == 0);

                // Allocate temporary buffer to decrypt into
                // Example storage: "2016 - WoW/23420", File: "4ee6bc9c6564227f1748abd0b088e950"
                pbWorkBuffer = CASC_ALLOC<BYTE>(cbEncoded - 1);
                cbWorkBuffer = cbEncoded - 1;
                if(pbWorkBuffer == NULL)
                    return ERROR_NOT_ENOUGH_MEMORY;

                // Decrypt the stream to the work buffer
                dwErrCode = CascDecrypt(hs, pbWorkBuffer, &cbWorkBuffer, pbEncoded + 1, cbEncoded - 1, FrameIndex);
                if(dwErrCode != ERROR_SUCCESS)
                {
                    bWorkComplete = true;
                    break;
                }

                // When encrypted, there is always one more step after this.
                // Setup the work buffer as input buffer for the next operation
                pbEncoded = pbWorkBuffer;
                cbEncoded = cbWorkBuffer;
                break;

            case 'Z':   // ZLIB compressed files
                
                // If we decompressed less than expected, we simply fill the rest with zeros
                // Example: INSTALL file from the TACT CASC storage
                cbDecodedExpected = cbDecoded;
                dwErrCode = CascDecompress(pbDecoded, &cbDecoded, pbEncoded + 1, cbEncoded - 1);

                // We exactly know what the output buffer size will be.
                // If the uncompressed data is smaller, fill the rest with zeros
                if(cbDecoded < cbDecodedExpected)
                    memset(pbDecoded + cbDecoded, 0, (cbDecodedExpected - cbDecoded));
                bWorkComplete = true;
                break;

            case 'N':   // Normal stored files
                dwErrCode = CascDirectCopy(pbDecoded, &cbDecoded, pbEncoded + 1, cbEncoded - 1);
                bWorkComplete = true;
                break;

            case 'F':   // Recursive frames (not supported)
            default:    // Unrecognized. Could be a plain file data
                dwErrCode = ERROR_NOT_SUPPORTED;
                bWorkComplete = true;
                assert(false);
                break;
        }

        // Increment the step count
        dwStepCount++;
    }

    // Some people find it handy to extract data from partially encrypted file,
    // even at the cost of producing corrupt files.
    // We overcome missing decryption key by zeroing the encrypted portions
    if(dwErrCode == ERROR_FILE_ENCRYPTED && hf->bOvercomeEncrypted)
    {
        memset(pbDecoded, 0, cbDecoded);
        dwErrCode = ERROR_SUCCESS;
    }

    // Free the temporary buffer
    CASC_FREE(pbWorkBuffer);
    return dwErrCode;
}

static bool GetFileFullInfo(TCascFile * hf, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded)
{
    PCASC_FILE_FULL_INFO pFileInfo;
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    TCascStorage * hs = hf->hs;
    DWORD dwErrCode;

    // Make sure that the file spans are loaded
    dwErrCode = EnsureFileSpanFramesLoaded(hf);
    if(dwErrCode != ERROR_SUCCESS)
    {
        SetCascError(dwErrCode);
        return false;
    }

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
        CascStrPrintf(pFileInfo->DataFileName, _countof(pFileInfo->DataFileName), "data.%03u", hf->pFileSpan->ArchiveIndex);
        pFileInfo->StorageOffset = pCKeyEntry->StorageOffset;
        pFileInfo->SegmentOffset = hf->pFileSpan->ArchiveOffs;
        pFileInfo->FileNameHash = 0;
        pFileInfo->TagBitMask = pCKeyEntry->TagBitMask;
        pFileInfo->ContentSize = hf->ContentSize;
        pFileInfo->EncodedSize = hf->EncodedSize;
        pFileInfo->SegmentIndex = hf->pFileSpan->ArchiveIndex;
        pFileInfo->SpanCount = hf->SpanCount;

        // Supply the root-specific information
        hs->pRootHandler->GetInfo(pCKeyEntry, pFileInfo);
    }

    return (pFileInfo != NULL);
}

static bool GetFileSpanInfo(TCascFile * hf, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded)
{
    PCASC_FILE_SPAN_INFO pFileInfo;
    PCASC_FILE_SPAN pFileSpan = hf->pFileSpan;
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    DWORD dwErrCode = ERROR_SUCCESS;

    // Make sure that the file spans are loaded
    dwErrCode = EnsureFileSpanFramesLoaded(hf);
    if(dwErrCode != ERROR_SUCCESS)
    {
        SetCascError(dwErrCode);
        return false;
    }

    // Verify whether we have enough space in the buffer
    pFileInfo = (PCASC_FILE_SPAN_INFO)ProbeOutputBuffer(pvFileInfo, cbFileInfo, sizeof(CASC_FILE_SPAN_INFO) * hf->SpanCount, pcbLengthNeeded);
    if(pFileInfo != NULL)
    {
        // Copy all file spans
        for(DWORD i = 0; i < hf->SpanCount; i++, pFileInfo++, pFileSpan++, pCKeyEntry++)
        {
            CopyMemory16(pFileInfo->CKey, pCKeyEntry->CKey);
            CopyMemory16(pFileInfo->EKey, pCKeyEntry->EKey);
            pFileInfo->StartOffset = pFileSpan->StartOffset;
            pFileInfo->EndOffset = pFileSpan->EndOffset;
            pFileInfo->ArchiveIndex = pFileSpan->ArchiveIndex;
            pFileInfo->ArchiveOffs = pFileSpan->ArchiveOffs;
            pFileInfo->HeaderSize = pFileSpan->HeaderSize;
            pFileInfo->FrameCount = pFileSpan->FrameCount;
        }
    }

    return (pFileInfo != NULL);
}


// Reads the file data from cache. Returns the number of bytes read
static DWORD ReadFile_Cache(TCascFile * hf, LPBYTE pbBuffer, ULONGLONG StartOffset, ULONGLONG EndOffset)
{
    // Is there a file cache at all?
    if(hf->pbFileCache != NULL && hf->FileCacheStart <= StartOffset && StartOffset < hf->FileCacheEnd)
    {
        LPBYTE pbStartBlock = hf->pbFileCache + (size_t)(StartOffset - hf->FileCacheStart);

        // Can we handle the entire request from the cache?
        if(EndOffset <= hf->FileCacheEnd)
        {
            DWORD dwBytesToCopy = (DWORD)(EndOffset - StartOffset);

            memcpy(pbBuffer, pbStartBlock, dwBytesToCopy);
            return dwBytesToCopy;
        }

        // We copy as much bytes as available. The rest is handled by normal read
        else
        {
            DWORD dwBytesToCopy = (DWORD)(hf->FileCacheEnd - StartOffset);

            memcpy(pbBuffer, pbStartBlock, dwBytesToCopy);
            return dwBytesToCopy;
        }
    }

    // Can't handle the request from the cache
    return 0;
}

// No cache at all. The entire file will be read directly to the user buffer
static DWORD ReadFile_WholeFile(TCascFile * hf, LPBYTE pbBuffer)
{
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    PCASC_FILE_SPAN pFileSpan = hf->pFileSpan;
    LPBYTE pbSaveBuffer = pbBuffer;
    LPBYTE pbEncoded;
    LPBYTE pbEncodedPtr;
    DWORD dwErrCode;

    for(DWORD SpanIndex = 0; SpanIndex < hf->SpanCount; SpanIndex++, pCKeyEntry++, pFileSpan++)
    {
        ULONGLONG ByteOffset = pFileSpan->ArchiveOffs + pFileSpan->HeaderSize;
        DWORD EncodedSize = pCKeyEntry->EncodedSize - pFileSpan->HeaderSize;

        // Allocate the buffer for the entire encoded span 
        pbEncodedPtr = pbEncoded = CASC_ALLOC<BYTE>(EncodedSize);
        if(pbEncoded == NULL)
        {
            SetCascError(ERROR_NOT_ENOUGH_MEMORY);
            return 0;
        }

        // Load the encoded buffer
        if(FileStream_Read(pFileSpan->pStream, &ByteOffset, pbEncoded, EncodedSize))
        {
            PCASC_FILE_FRAME pFileFrame = pFileSpan->pFrames;

            for(DWORD FrameIndex = 0; FrameIndex < pFileSpan->FrameCount; FrameIndex++, pFileFrame++)
            {
                // Decode the file frame
                dwErrCode = DecodeFileFrame(hf, pCKeyEntry, pFileFrame, pbEncodedPtr, pbBuffer, FrameIndex);
                if(dwErrCode != ERROR_SUCCESS)
                    break;

                // Move pointers
                pbEncodedPtr += pFileFrame->EncodedSize;
                pbBuffer += pFileFrame->ContentSize;
            }
        }

        CASC_FREE(pbEncoded);
    }

    // Give the amount of bytes read
    return (DWORD)(pbBuffer - pbSaveBuffer);
}

static DWORD ReadFile_FrameCached(TCascFile * hf, LPBYTE pbBuffer, ULONGLONG StartOffset, ULONGLONG EndOffset)
{
    PCASC_CKEY_ENTRY pCKeyEntry = hf->pCKeyEntry;
    PCASC_FILE_SPAN pFileSpan = hf->pFileSpan;
    PCASC_FILE_FRAME pFileFrame = NULL;
    LPBYTE pbSaveBuffer = pbBuffer;
    LPBYTE pbEncoded = NULL;
    LPBYTE pbDecoded = NULL;
    DWORD dwBytesRead = 0;
    DWORD dwErrCode = ERROR_SUCCESS;
    bool bNeedFreeDecoded = true;

    // Parse all file spans
    for(DWORD SpanIndex = 0; SpanIndex < hf->SpanCount; SpanIndex++, pCKeyEntry++, pFileSpan++)
    {
        if(pFileSpan->StartOffset <= StartOffset && StartOffset < pFileSpan->EndOffset)
        {
            for(DWORD FrameIndex = 0; FrameIndex < pFileSpan->FrameCount; FrameIndex++)
            {
                // Get the current file frame
                pFileFrame = pFileSpan->pFrames + FrameIndex;

                // Check the frame byte range
                if(pFileFrame->StartOffset <= StartOffset && StartOffset < pFileFrame->EndOffset)
                {
                    // Check bytes read overflow
                    if((dwBytesRead + pFileFrame->ContentSize) < dwBytesRead)
                    {
                        SetCascError(ERROR_BUFFER_OVERFLOW);
                        return 0;
                    }

                    // Pick the buffer for decoded data. If we are going to read the entire frame,
                    // there is a little chance that the caller will read the same file range again
                    // So we can as well just unpack the entire frame into the output buffer
                    if(pFileFrame->StartOffset < StartOffset || EndOffset < pFileFrame->EndOffset)
                    {
                        if((pbDecoded = CASC_ALLOC<BYTE>(pFileFrame->ContentSize)) == NULL)
                        {
                            SetCascError(ERROR_NOT_ENOUGH_MEMORY);
                            return 0;
                        }
                        bNeedFreeDecoded = true;
                    }
                    else
                    {
                        bNeedFreeDecoded = false;
                        pbDecoded = pbBuffer;
                    }

                    // Allocate the encoded frame
                    if((pbEncoded = CASC_ALLOC<BYTE>(pFileFrame->EncodedSize)) == NULL)
                    {
                        CASC_FREE(pbDecoded);
                        SetCascError(ERROR_NOT_ENOUGH_MEMORY);
                        return 0;
                    }

                    // Load the frame to the encoded buffer
                    if(FileStream_Read(pFileSpan->pStream, &pFileFrame->DataFileOffset, pbEncoded, pFileFrame->EncodedSize))
                    {
                        ULONGLONG EndOfCopy = CASCLIB_MIN(pFileFrame->EndOffset, EndOffset);
                        DWORD dwBytesToCopy = (DWORD)(EndOfCopy - StartOffset);

                        // Decode the frame
                        dwErrCode = DecodeFileFrame(hf, pCKeyEntry, pFileFrame, pbEncoded, pbDecoded, FrameIndex);
                        if(dwErrCode == ERROR_SUCCESS)
                        {
                            // Copy the data
                            if(pbDecoded != pbBuffer)
                                memcpy(pbBuffer, pbDecoded + (DWORD)(StartOffset - pFileFrame->StartOffset), dwBytesToCopy);
                            StartOffset += dwBytesToCopy;
                            pbBuffer += dwBytesToCopy;
                        }
                    }

                    // Free the encoded buffer
                    CASC_FREE(pbEncoded);

                    // If we are at the end of the read area, break all loops
                    if(dwErrCode != ERROR_SUCCESS || StartOffset >= EndOffset)
                        goto __WorkComplete;
                    if(bNeedFreeDecoded)
                        CASC_FREE(pbDecoded);
                }
            }
        }
    }

    __WorkComplete:

    if(dwErrCode == ERROR_SUCCESS)
    {
        // If there is some data left in the frame, we set it as cache
        if(pFileFrame != NULL && pbDecoded != NULL && EndOffset < pFileFrame->EndOffset)
        {
            CASC_FREE(hf->pbFileCache);

            hf->FileCacheStart = pFileFrame->StartOffset;
            hf->FileCacheEnd = pFileFrame->EndOffset;
            hf->pbFileCache = pbDecoded;
            pbDecoded = NULL;
        }
    }

    // Final free of the decoded buffer, if needeed
    if(bNeedFreeDecoded)
        CASC_FREE(pbDecoded);
    pbDecoded = NULL;

    // Return the number of bytes read. Always set LastError.
    SetCascError(dwErrCode);
    return (DWORD)(pbBuffer - pbSaveBuffer);
}

// No cache at all. The entire file will be read directly to the user buffer
static DWORD ReadFile_NonCached(TCascFile * hf, LPBYTE pbBuffer, ULONGLONG StartOffset, ULONGLONG EndOffset)
{
    // Reading the whole file?
    if(StartOffset == 0 && EndOffset == hf->ContentSize)
    {
        return ReadFile_WholeFile(hf, pbBuffer);
    }

    // Reading just a part of the file?
    else
    {
        assert(false);
    }

    return 0;
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
        SetCascError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Differentiate between info classes
    switch(InfoClass)
    {
        case CascFileContentKey:

            // Do we have content key at all?
            if(hf->pCKeyEntry == NULL || (hf->pCKeyEntry->Flags & CASC_CE_HAS_CKEY) == 0)
            {
                SetCascError(ERROR_NOT_SUPPORTED);
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
                SetCascError(ERROR_NOT_SUPPORTED);
                return false;
            }

            // Give the content key
            pbInfoValue = hf->pCKeyEntry->EKey;
            cbInfoValue = CASC_CKEY_SIZE;
            break;

        case CascFileFullInfo:
            return GetFileFullInfo(hf, pvFileInfo, cbFileInfo, pcbLengthNeeded);

        case CascFileSpanInfo:
            return GetFileSpanInfo(hf, pvFileInfo, cbFileInfo, pcbLengthNeeded);

        default:
            SetCascError(ERROR_INVALID_PARAMETER);
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

bool WINAPI CascGetFileSize64(HANDLE hFile, PULONGLONG PtrFileSize)
{
    TCascFile * hf;
    DWORD dwErrCode;

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) == NULL)
    {
        SetCascError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Validate the file pointer
    if(PtrFileSize == NULL)
    {
        SetCascError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // ENCODING on older storages: Content size is not present in the BUILD file
    // For that reason, we need to query the content size from the file frames
    dwErrCode = EnsureFileSpanFramesLoaded(hf);
    if(dwErrCode != ERROR_SUCCESS)
    {
        SetCascError(dwErrCode);
        return false;
    }

    // Give the file size to the caller
    PtrFileSize[0] = hf->ContentSize;
    return true;
}

DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD PtrFileSizeHigh)
{
    ULONGLONG FileSize = 0;

    // Retrieve the 64-bit file size
    if(!CascGetFileSize64(hFile, &FileSize))
        return CASC_INVALID_SIZE;

    // Give the file size to the caller
    if(PtrFileSizeHigh != NULL)
        PtrFileSizeHigh[0] = (DWORD)(FileSize >> 32);
    return (DWORD)(FileSize);
}

bool WINAPI CascSetFilePointer64(HANDLE hFile, LONGLONG DistanceToMove, PULONGLONG PtrNewPos, DWORD dwMoveMethod)
{
    ULONGLONG FilePosition;
    TCascFile * hf;

    // If the hFile is not a valid file handle, return an error.
    hf = TCascFile::IsValid(hFile);
    if(hf == NULL)
    {
        SetCascError(ERROR_INVALID_HANDLE);
        return false;
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
            SetCascError(ERROR_INVALID_PARAMETER);
            return false;
    }

    // Now calculate the new file pointer
    if(DistanceToMove >= 0)
    {
        // Do not allow the file pointer to overflow 64-bit range
        if((FilePosition + DistanceToMove) < FilePosition)
        {
            SetCascError(ERROR_INVALID_PARAMETER);
            return false;
        }

        // Do not allow the file pointer to overflow the file size
        if((FilePosition = FilePosition + DistanceToMove) > hf->ContentSize)
            FilePosition = hf->ContentSize;
        hf->FilePointer = FilePosition;
    }
    else
    {
        // Do not allow the file pointer to underflow 64-bit range
        if((FilePosition + DistanceToMove) > FilePosition)
        {
            SetCascError(ERROR_INVALID_PARAMETER);
            return false;
        }

        // Do not allow the file pointer to move to negative values
        if((LONGLONG)(FilePosition = FilePosition + DistanceToMove) < 0)
            FilePosition = 0;
        hf->FilePointer = FilePosition;
    }

    // Give the result size to the caller
    if(PtrNewPos != NULL)
        PtrNewPos[0] = hf->FilePointer;
    return true;
}

DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * PtrFilePosHigh, DWORD dwMoveMethod)
{
    ULONGLONG NewPos = 0;
    LONGLONG DistanceToMove;
    
    // Assemble the 64-bit distance to move
    DistanceToMove = (PtrFilePosHigh != NULL) ? MAKE_OFFSET64(PtrFilePosHigh[0], lFilePos) : (LONGLONG)(LONG)lFilePos;

    // Set the file offset
    if(!CascSetFilePointer64(hFile, DistanceToMove, &NewPos, dwMoveMethod))
        return CASC_INVALID_POS;

    // Give the result to the caller
    if(PtrFilePosHigh != NULL)
        PtrFilePosHigh[0] = (LONG)(NewPos >> 32);
    return (DWORD)(NewPos);
}

bool WINAPI CascReadFile(HANDLE hFile, void * pvBuffer, DWORD dwBytesToRead, PDWORD PtrBytesRead)
{
    ULONGLONG SaveFilePointer;
    ULONGLONG StartOffset;
    ULONGLONG EndOffset;
    TCascFile * hf;
    LPBYTE pbBuffer = (LPBYTE)pvBuffer;
    DWORD dwBytesRead1 = 0;     // From cache
    DWORD dwBytesRead2 = 0;     // From file
    DWORD dwErrCode;

    // The buffer must be valid
    if(pvBuffer == NULL)
    {
        SetCascError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Validate the file handle
    if((hf = TCascFile::IsValid(hFile)) == NULL)
    {
        SetCascError(ERROR_INVALID_HANDLE);
        return false;
    }

    // If we don't have file frames loaded, we need to do it now.
    // Need to do it before file range check, as the file size may be unknown at this point
    dwErrCode = EnsureFileSpanFramesLoaded(hf);
    if(dwErrCode != ERROR_SUCCESS)
    {
        SetCascError(dwErrCode);
        return false;
    }

    // If the file position is at or beyond end of file, do nothing
    SaveFilePointer = StartOffset = hf->FilePointer;
    if(StartOffset >= hf->ContentSize)
    {
        PtrBytesRead[0] = 0;
        return true;
    }

    // If the read area goes beyond end of the file, cut the number of bytes to read
    EndOffset = StartOffset + dwBytesToRead;
    if(EndOffset > hf->ContentSize)
    {
        EndOffset = hf->ContentSize;
    }

    // Can we handle the request (at least partially) from the cache?
    if((dwBytesRead1 = ReadFile_Cache(hf, pbBuffer, StartOffset, EndOffset)) != 0)
    {
        // Move pointers
        StartOffset = StartOffset + dwBytesRead1;
        pbBuffer += dwBytesRead1;

        // Has the read request been fully satisfied?
        if(StartOffset == EndOffset)
        {
            if(PtrBytesRead != NULL)
                PtrBytesRead[0] = dwBytesRead1;
            hf->FilePointer = EndOffset;
            return true;
        }
    }

    // Perform the cache-strategy-specific read
    switch(hf->CacheStrategy)
    {
        // No caching at all. The entire file will be read directly to the user buffer
        // Used for loading internal files, where we need to read the whole file
        case CascCacheNothing:  
            dwBytesRead2 = ReadFile_NonCached(hf, pbBuffer, StartOffset, EndOffset);
            break;

        // Read as many frames as we can. The last loaded frame, if not read entirely,
        // will stay in the cache - We expect the next read to continue from that offset.
        case CascCacheLastFrame:
            dwBytesRead2 = ReadFile_FrameCached(hf, pbBuffer, StartOffset, EndOffset);
            break;
    }

    // If the second-stage-read failed, we invalidate the entire operation and return 0 bytes read
    if(dwBytesRead2 != 0)
    {
        // Give the result to the caller
        if(PtrBytesRead != NULL)
            PtrBytesRead[0] = (dwBytesRead1 + dwBytesRead2);
        hf->FilePointer = StartOffset + dwBytesRead2;
        return true;
    }
    else
    {
        // Give the result to the caller
        if(PtrBytesRead != NULL)
            PtrBytesRead[0] = 0;
        hf->FilePointer = SaveFilePointer;
        
        // If 0 bytes were requested, it's actually a success
        return (dwBytesToRead == 0);
    }
}
