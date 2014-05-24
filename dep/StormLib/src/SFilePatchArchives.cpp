/*****************************************************************************/
/* SFilePatchArchives.cpp                 Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* Description:                                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 18.08.10  1.00  Lad  The first version of SFilePatchArchives.cpp          */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local structures

typedef struct _BLIZZARD_BSDIFF40_FILE
{
    ULONGLONG Signature;
    ULONGLONG CtrlBlockSize;
    ULONGLONG DataBlockSize;
    ULONGLONG NewFileSize;
} BLIZZARD_BSDIFF40_FILE, *PBLIZZARD_BSDIFF40_FILE;

//-----------------------------------------------------------------------------
// Local functions

static bool GetDefaultPatchPrefix(
    const TCHAR * szBaseMpqName,
    char * szBuffer)
{
    const TCHAR * szExtension;
    const TCHAR * szDash;

    // Ensure that both names are plain names
    szBaseMpqName = GetPlainFileNameT(szBaseMpqName);

    // Patch prefix is for the Cataclysm MPQs, whose names
    // are like "locale-enGB.MPQ" or "speech-enGB.MPQ"
    szExtension = _tcsrchr(szBaseMpqName, _T('.'));
    szDash = _tcsrchr(szBaseMpqName, _T('-'));
    strcpy(szBuffer, "Base");

    // If the length of the prefix doesn't match, use default one
    if(szExtension != NULL && szDash != NULL && (szExtension - szDash) == 5)
    {
        // Copy the prefix
        szBuffer[0] = (char)szDash[1];
        szBuffer[1] = (char)szDash[2];
        szBuffer[2] = (char)szDash[3];
        szBuffer[3] = (char)szDash[4];
        szBuffer[4] = 0;
    }

    return true;
}

static void Decompress_RLE(LPBYTE pbDecompressed, DWORD cbDecompressed, LPBYTE pbCompressed, DWORD cbCompressed)
{
    LPBYTE pbDecompressedEnd = pbDecompressed + cbDecompressed;
    LPBYTE pbCompressedEnd = pbCompressed + cbCompressed;
    BYTE RepeatCount; 
    BYTE OneByte;

    // Cut the initial DWORD from the compressed chunk
    pbCompressed += sizeof(DWORD);
    cbCompressed -= sizeof(DWORD);

    // Pre-fill decompressed buffer with zeros
    memset(pbDecompressed, 0, cbDecompressed);

    // Unpack
    while(pbCompressed < pbCompressedEnd && pbDecompressed < pbDecompressedEnd)
    {
        OneByte = *pbCompressed++;
        
        // Is it a repetition byte ?
        if(OneByte & 0x80)
        {
            RepeatCount = (OneByte & 0x7F) + 1;
            for(BYTE i = 0; i < RepeatCount; i++)
            {
                if(pbDecompressed == pbDecompressedEnd || pbCompressed == pbCompressedEnd)
                    break;

                *pbDecompressed++ = *pbCompressed++;
            }
        }
        else
        {
            pbDecompressed += (OneByte + 1);
        }
    }
}

static int LoadMpqPatch_COPY(TMPQFile * hf, TPatchHeader * pPatchHeader)
{
    int nError = ERROR_SUCCESS;

    // Allocate space for patch header and compressed data
    hf->pPatchHeader = (TPatchHeader *)STORM_ALLOC(BYTE, pPatchHeader->dwSizeOfPatchData);
    if(hf->pPatchHeader == NULL)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    // Load the patch data and decide if they are compressed or not
    if(nError == ERROR_SUCCESS)
    {
        LPBYTE pbPatchFile = (LPBYTE)hf->pPatchHeader;

        // Copy the patch header itself
        memcpy(pbPatchFile, pPatchHeader, sizeof(TPatchHeader));
        pbPatchFile += sizeof(TPatchHeader);

        // Load the rest of the patch
        if(!SFileReadFile((HANDLE)hf, pbPatchFile, pPatchHeader->dwSizeOfPatchData - sizeof(TPatchHeader)))
            nError = GetLastError();
    }

    return nError;
}

static int LoadMpqPatch_BSD0(TMPQFile * hf, TPatchHeader * pPatchHeader)
{
    LPBYTE pbDecompressed = NULL;
    LPBYTE pbCompressed = NULL;
    DWORD cbDecompressed = 0;
    DWORD cbCompressed = 0;
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Allocate space for compressed data
    cbCompressed = pPatchHeader->dwXfrmBlockSize - SIZE_OF_XFRM_HEADER;
    pbCompressed = STORM_ALLOC(BYTE, cbCompressed);
    if(pbCompressed == NULL)
        nError = ERROR_SUCCESS;

    // Read the compressed patch data
    if(nError == ERROR_SUCCESS)
    {
        // Load the rest of the header
        SFileReadFile((HANDLE)hf, pbCompressed, cbCompressed, &dwBytesRead);
        if(dwBytesRead != cbCompressed)
            nError = ERROR_FILE_CORRUPT;
    }

    // Get the uncompressed size of the patch
    if(nError == ERROR_SUCCESS)
    {
        cbDecompressed = pPatchHeader->dwSizeOfPatchData - sizeof(TPatchHeader);
        hf->pPatchHeader = (TPatchHeader *)STORM_ALLOC(BYTE, pPatchHeader->dwSizeOfPatchData);
        if(hf->pPatchHeader == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Now decompress the patch data
    if(nError == ERROR_SUCCESS)
    {
        // Copy the patch header
        memcpy(hf->pPatchHeader, pPatchHeader, sizeof(TPatchHeader));
        pbDecompressed = (LPBYTE)hf->pPatchHeader + sizeof(TPatchHeader);

        // Uncompress or copy the patch data
        if(cbCompressed < cbDecompressed)
        {
            Decompress_RLE(pbDecompressed, cbDecompressed, pbCompressed, cbCompressed);
        }
        else
        {
            assert(cbCompressed == cbDecompressed);
            memcpy(pbDecompressed, pbCompressed, cbCompressed);
        }
    }

    // Free buffers and exit
    if(pbCompressed != NULL)
        STORM_FREE(pbCompressed);
    return nError;
}

static int ApplyMpqPatch_COPY(
    TMPQFile * hf,
    TPatchHeader * pPatchHeader)
{
    LPBYTE pbNewFileData;
    DWORD cbNewFileData;

    // Allocate space for new file data
    cbNewFileData = pPatchHeader->dwXfrmBlockSize - SIZE_OF_XFRM_HEADER;
    pbNewFileData = STORM_ALLOC(BYTE, cbNewFileData);
    if(pbNewFileData == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Copy the patch data as-is
    memcpy(pbNewFileData, (LPBYTE)pPatchHeader + sizeof(TPatchHeader), cbNewFileData);

    // Free the old file data
    STORM_FREE(hf->pbFileData);

    // Put the new file data there
    hf->pbFileData = pbNewFileData;
    hf->cbFileData = cbNewFileData;
    return ERROR_SUCCESS;
}

static int ApplyMpqPatch_BSD0(
    TMPQFile * hf,
    TPatchHeader * pPatchHeader)
{
    PBLIZZARD_BSDIFF40_FILE pBsdiff;
    LPDWORD pCtrlBlock;
    LPBYTE pbPatchData = (LPBYTE)pPatchHeader + sizeof(TPatchHeader);
    LPBYTE pDataBlock;
    LPBYTE pExtraBlock;
    LPBYTE pbNewData = NULL;
    LPBYTE pbOldData = (LPBYTE)hf->pbFileData;
    DWORD dwNewOffset = 0;                          // Current position to patch
    DWORD dwOldOffset = 0;                          // Current source position
    DWORD dwNewSize;                                // Patched file size
    DWORD dwOldSize = hf->cbFileData;               // File size before patch

    // Get pointer to the patch header
    // Format of BSDIFF header corresponds to original BSDIFF, which is:
    // 0000   8 bytes   signature "BSDIFF40"
    // 0008   8 bytes   size of the control block
    // 0010   8 bytes   size of the data block
    // 0018   8 bytes   new size of the patched file
    pBsdiff = (PBLIZZARD_BSDIFF40_FILE)pbPatchData;
    pbPatchData += sizeof(BLIZZARD_BSDIFF40_FILE);

    // Get pointer to the 32-bit BSDIFF control block
    // The control block follows immediately after the BSDIFF header
    // and consists of three 32-bit integers
    // 0000   4 bytes   Length to copy from the BSDIFF data block the new file
    // 0004   4 bytes   Length to copy from the BSDIFF extra block
    // 0008   4 bytes   Size to increment source file offset
    pCtrlBlock = (LPDWORD)pbPatchData;
    pbPatchData += (size_t)BSWAP_INT64_UNSIGNED(pBsdiff->CtrlBlockSize);

    // Get the pointer to the data block
    pDataBlock = (LPBYTE)pbPatchData;
    pbPatchData += (size_t)BSWAP_INT64_UNSIGNED(pBsdiff->DataBlockSize);

    // Get the pointer to the extra block
    pExtraBlock = (LPBYTE)pbPatchData;
    dwNewSize = (DWORD)BSWAP_INT64_UNSIGNED(pBsdiff->NewFileSize);

    // Allocate new buffer
    pbNewData = STORM_ALLOC(BYTE, dwNewSize);
    if(pbNewData == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Now patch the file
    while(dwNewOffset < dwNewSize)
    {
        DWORD dwAddDataLength = BSWAP_INT32_UNSIGNED(pCtrlBlock[0]);
        DWORD dwMovDataLength = BSWAP_INT32_UNSIGNED(pCtrlBlock[1]);
        DWORD dwOldMoveLength = BSWAP_INT32_UNSIGNED(pCtrlBlock[2]);
        DWORD i;

        // Sanity check
        if((dwNewOffset + dwAddDataLength) > dwNewSize)
        {
            STORM_FREE(pbNewData);
            return ERROR_FILE_CORRUPT;
        }

        // Read the diff string to the target buffer
        memcpy(pbNewData + dwNewOffset, pDataBlock, dwAddDataLength);
        pDataBlock += dwAddDataLength;

        // Now combine the patch data with the original file
        for(i = 0; i < dwAddDataLength; i++)
        {
            if(dwOldOffset < dwOldSize)
                pbNewData[dwNewOffset] = pbNewData[dwNewOffset] + pbOldData[dwOldOffset];

            dwNewOffset++;
            dwOldOffset++;
        }

        // Sanity check
        if((dwNewOffset + dwMovDataLength) > dwNewSize)
        {
            STORM_FREE(pbNewData);
            return ERROR_FILE_CORRUPT;
        }

        // Copy the data from the extra block in BSDIFF patch
        memcpy(pbNewData + dwNewOffset, pExtraBlock, dwMovDataLength);
        pExtraBlock += dwMovDataLength;
        dwNewOffset += dwMovDataLength;

        // Move the old offset
        if(dwOldMoveLength & 0x80000000)
            dwOldMoveLength = 0x80000000 - dwOldMoveLength;
        dwOldOffset += dwOldMoveLength;
        pCtrlBlock += 3;
    }

    // Free the old file data
    STORM_FREE(hf->pbFileData);

    // Put the new data to the fil structure
    hf->pbFileData = pbNewData;
    hf->cbFileData = dwNewSize;
    return ERROR_SUCCESS;
}


static int LoadMpqPatch(TMPQFile * hf)
{
    TPatchHeader PatchHeader;
    DWORD dwBytesRead;
    int nError = ERROR_SUCCESS;

    // Read the patch header
    SFileReadFile((HANDLE)hf, &PatchHeader, sizeof(TPatchHeader), &dwBytesRead);
    if(dwBytesRead != sizeof(TPatchHeader))
        nError = ERROR_FILE_CORRUPT;

    // Verify the signatures in the patch header
    if(nError == ERROR_SUCCESS)
    {
        // BSWAP the entire header, if needed
        BSWAP_ARRAY32_UNSIGNED(&PatchHeader, sizeof(DWORD) * 6);
        PatchHeader.dwXFRM          = BSWAP_INT32_UNSIGNED(PatchHeader.dwXFRM);
        PatchHeader.dwXfrmBlockSize = BSWAP_INT32_UNSIGNED(PatchHeader.dwXfrmBlockSize);
        PatchHeader.dwPatchType     = BSWAP_INT32_UNSIGNED(PatchHeader.dwPatchType);

        if(PatchHeader.dwSignature != 0x48435450 || PatchHeader.dwMD5 != 0x5f35444d || PatchHeader.dwXFRM != 0x4d524658)
            nError = ERROR_FILE_CORRUPT;
    }

    // Read the patch, depending on patch type
    if(nError == ERROR_SUCCESS)
    {
        switch(PatchHeader.dwPatchType)
        {
            case 0x59504f43:    // 'COPY'
                nError = LoadMpqPatch_COPY(hf, &PatchHeader);
                break;

            case 0x30445342:    // 'BSD0'
                nError = LoadMpqPatch_BSD0(hf, &PatchHeader);
                break;

            default:
                nError = ERROR_FILE_CORRUPT;
                break;
        }
    }

    return nError;
}

static int ApplyMpqPatch(
    TMPQFile * hf,
    TPatchHeader * pPatchHeader)
{
    int nError = ERROR_SUCCESS;

    // Verify the original file before patching
    if(pPatchHeader->dwSizeBeforePatch != 0)
    {
        if(!VerifyDataBlockHash(hf->pbFileData, hf->cbFileData, pPatchHeader->md5_before_patch))
            nError = ERROR_FILE_CORRUPT;
    }

    // Apply the patch
    if(nError == ERROR_SUCCESS)
    {
        switch(pPatchHeader->dwPatchType)
        {
            case 0x59504f43:    // 'COPY'
                nError = ApplyMpqPatch_COPY(hf, pPatchHeader);
                break;

            case 0x30445342:    // 'BSD0'
                nError = ApplyMpqPatch_BSD0(hf, pPatchHeader);
                break;

            default:
                nError = ERROR_FILE_CORRUPT;
                break;
        }
    }

    // Verify MD5 after patch
    if(nError == ERROR_SUCCESS && pPatchHeader->dwSizeAfterPatch != 0)
    {
        // Verify the patched file
        if(!VerifyDataBlockHash(hf->pbFileData, hf->cbFileData, pPatchHeader->md5_after_patch))
            nError = ERROR_FILE_CORRUPT;
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Public functions (StormLib internals)

bool IsIncrementalPatchFile(const void * pvData, DWORD cbData, LPDWORD pdwPatchedFileSize)
{
    TPatchHeader * pPatchHeader = (TPatchHeader *)pvData;
    BLIZZARD_BSDIFF40_FILE DiffFile;
    DWORD dwPatchType;

    if(cbData >= sizeof(TPatchHeader) + sizeof(BLIZZARD_BSDIFF40_FILE))
    {
        dwPatchType = BSWAP_INT32_UNSIGNED(pPatchHeader->dwPatchType);
        if(dwPatchType == 0x30445342)
        {
            // Give the caller the patch file size
            if(pdwPatchedFileSize != NULL)
            {
                Decompress_RLE((LPBYTE)&DiffFile, sizeof(BLIZZARD_BSDIFF40_FILE), (LPBYTE)(pPatchHeader + 1), sizeof(BLIZZARD_BSDIFF40_FILE));
                DiffFile.NewFileSize = BSWAP_INT64_UNSIGNED(DiffFile.NewFileSize);
                *pdwPatchedFileSize = (DWORD)DiffFile.NewFileSize;
                return true;
            }
        }
    }

    return false;
}

int PatchFileData(TMPQFile * hf)
{
    TMPQFile * hfBase = hf;
    int nError = ERROR_SUCCESS;

    // Move to the first patch
    hf = hf->hfPatchFile;

    // Now go through all patches and patch the original data
    while(hf != NULL)
    {
        // This must be true
        assert(hf->pFileEntry->dwFlags & MPQ_FILE_PATCH_FILE);

        // Make sure that the patch data is loaded
        nError = LoadMpqPatch(hf);
        if(nError != ERROR_SUCCESS)
            break;

        // Apply the patch
        nError = ApplyMpqPatch(hfBase, hf->pPatchHeader);
        if(nError != ERROR_SUCCESS)
            break;

        // Move to the next patch
        hf = hf->hfPatchFile;
    }

    return nError;
}

//-----------------------------------------------------------------------------
// Public functions

//
// Patch prefix is the path subdirectory where the patched files are within MPQ.
//
// Example 1:
// Main MPQ:  locale-enGB.MPQ
// Patch MPQ: wow-update-12694.MPQ
// File in main MPQ: DBFilesClient\Achievement.dbc
// File in patch MPQ: enGB\DBFilesClient\Achievement.dbc
// Path prefix: enGB
//
// Example 2:
// Main MPQ:  expansion1.MPQ
// Patch MPQ: wow-update-12694.MPQ
// File in main MPQ: DBFilesClient\Achievement.dbc
// File in patch MPQ: Base\DBFilesClient\Achievement.dbc
// Path prefix: Base
//

bool WINAPI SFileOpenPatchArchive(
    HANDLE hMpq,
    const TCHAR * szPatchMpqName,
    const char * szPatchPathPrefix,
    DWORD dwFlags)
{
    TMPQArchive * haPatch;
    TMPQArchive * ha = (TMPQArchive *)hMpq;
    HANDLE hPatchMpq = NULL;
    char szPatchPrefixBuff[MPQ_PATCH_PREFIX_LEN];
    int nError = ERROR_SUCCESS;

    // Keep compiler happy
    dwFlags = dwFlags;

    // Verify input parameters
    if(!IsValidMpqHandle(ha))
        nError = ERROR_INVALID_HANDLE;
    if(szPatchMpqName == NULL || *szPatchMpqName == 0)
        nError = ERROR_INVALID_PARAMETER;

    // If the user didn't give the patch prefix, get default one
    if(szPatchPathPrefix != NULL)
    {
        // Save length of the patch prefix
        if(strlen(szPatchPathPrefix) > MPQ_PATCH_PREFIX_LEN - 2)
            nError = ERROR_INVALID_PARAMETER;
    }

    //
    // We don't allow adding patches to archives that have been open for write
    //
    // Error scenario:
    //
    // 1) Open archive for writing
    // 2) Modify or replace a file
    // 3) Add patch archive to the opened MPQ
    // 4) Read patched file
    // 5) Now what ?
    //

    if(nError == ERROR_SUCCESS)
    {
        if(!FileStream_IsReadOnly(ha->pStream))
            nError = ERROR_ACCESS_DENIED;
    }

    // Open the archive like it is normal archive
    if(nError == ERROR_SUCCESS)
    {
        if(!SFileOpenArchive(szPatchMpqName, 0, MPQ_OPEN_READ_ONLY, &hPatchMpq))
            return false;
        haPatch = (TMPQArchive *)hPatchMpq;

        // Older WoW patches (build 13914) used to have
        // several language versions in one patch file
        // Those patches needed to have a path prefix
        // We can distinguish such patches by not having the (patch_metadata) file
        if(szPatchPathPrefix == NULL)
        {
            if(!SFileHasFile(hPatchMpq, PATCH_METADATA_NAME))
            {
                GetDefaultPatchPrefix(FileStream_GetFileName(ha->pStream), szPatchPrefixBuff);
                szPatchPathPrefix = szPatchPrefixBuff;
            }
        }

        // Save the prefix for patch file names.
        // Make sure that there is backslash after it
        if(szPatchPathPrefix != NULL && *szPatchPathPrefix != 0)
        {
            strcpy(haPatch->szPatchPrefix, szPatchPathPrefix);
            strcat(haPatch->szPatchPrefix, "\\");
            haPatch->cchPatchPrefix = strlen(haPatch->szPatchPrefix);
        }

        // Now add the patch archive to the list of patches to the original MPQ
        while(ha != NULL)
        {
            if(ha->haPatch == NULL)
            {
                haPatch->haBase = ha;
                ha->haPatch = haPatch;
                return true;
            }

            // Move to the next archive
            ha = ha->haPatch;
        }

        // Should never happen
        nError = ERROR_CAN_NOT_COMPLETE;
    }

    SetLastError(nError);
    return false;
}

bool WINAPI SFileIsPatchedArchive(HANDLE hMpq)
{
    TMPQArchive * ha = (TMPQArchive *)hMpq;

    // Verify input parameters
    if(!IsValidMpqHandle(ha))
        return false;

    return (ha->haPatch != NULL);
}
