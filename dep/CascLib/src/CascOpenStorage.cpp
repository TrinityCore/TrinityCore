/*****************************************************************************/
/* CascOpenStorage.cpp                    Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Storage functions for CASC                                                */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascOpenStorage.cpp             */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"
#include "CascMndxRoot.h"

//-----------------------------------------------------------------------------
// Local structures

#define CASC_ENCODING_SEGMENT_SIZE  0x1000

typedef struct _BLOCK_SIZE_AND_HASH
{
    DWORD cbBlockSize;
    DWORD dwBlockHash;

} BLOCK_SIZE_AND_HASH, *PBLOCK_SIZE_AND_HASH;

typedef struct _FILE_INDEX_HEADER_V1
{
    USHORT field_0;
    BYTE  KeyIndex;                             // Key index (0 for data.i0x, 1 for data.i1x, 2 for data.i2x etc.)
    BYTE  align_3;
    DWORD field_4;
    ULONGLONG field_8;
    ULONGLONG MaxFileOffset;
    BYTE  SpanSizeBytes;
    BYTE  SpanOffsBytes;
    BYTE  KeyBytes;
    BYTE  SegmentBits;                          // Number of bits for file offset
    DWORD KeyCount1;
    DWORD KeyCount2;
    DWORD KeysHash1;
    DWORD KeysHash2;
    DWORD dwHeaderHash;
} FILE_INDEX_HEADER_V1, *PFILE_INDEX_HEADER_V1;

typedef struct _FILE_INDEX_HEADER_V2
{
    USHORT IndexVersion;                        // Must be 0x07
    BYTE   KeyIndex;                            // Must be equal to the file key index
    BYTE   ExtraBytes;                          // (?) Extra bytes in the key record
    BYTE   SpanSizeBytes;                       // Size of field with file size
    BYTE   SpanOffsBytes;                       // Size of field with file offset
    BYTE   KeyBytes;                            // Size of the file key (bytes)
    BYTE   SegmentBits;                         // Number of bits for the file offset (rest is archive index)
    ULONGLONG MaxFileOffset;

} FILE_INDEX_HEADER_V2, *PFILE_INDEX_HEADER_V2;

typedef struct _FILE_ENCODING_HEADER
{
    BYTE Magic[2];                              // "EN"
    BYTE field_2;
    BYTE field_3;
    BYTE field_4;
    BYTE field_5[2];
    BYTE field_7[2];
    BYTE NumSegments[4];                        // Number of entries (big endian)
    BYTE field_D[4];
    BYTE field_11;
    BYTE SegmentsPos[4];                        // Offset of encoding segments

} FILE_ENCODING_HEADER, *PFILE_ENCODING_HEADER;

typedef struct _FILE_ENCODING_SEGMENT
{
    BYTE FirstEncodingKey[MD5_HASH_SIZE];           // The first encoding key in the segment
    BYTE SegmentHash[MD5_HASH_SIZE];                // MD5 hash of the entire segment

} FILE_ENCODING_SEGMENT, *PFILE_ENCODING_SEGMENT;

typedef struct _FILE_LOCALE_BLOCK
{
    DWORD NumberOfFiles;                        // Number of entries
    DWORD Flags;
    DWORD Locales;                              // File locale mask (CASC_LOCALE_XXX)

    // Followed by a block of 32-bit integers (count: NumberOfFiles)
    // Followed by the MD5 and file name hash (count: NumberOfFiles)

} FILE_LOCALE_BLOCK, *PFILE_LOCALE_BLOCK;

typedef struct _FILE_ROOT_ENTRY
{
    BYTE EncodingKey[MD5_HASH_SIZE];            // MD5 of the file
    ULONGLONG FileNameHash;                     // Jenkins hash of the file name

} FILE_ROOT_ENTRY, *PFILE_ROOT_ENTRY;

typedef struct _ROOT_BLOCK_INFO
{
    PFILE_LOCALE_BLOCK pLocaleBlockHdr;         // Pointer to the locale block
    PDWORD pInt32Array;                         // Pointer to the array of 32-bit integers
    PFILE_ROOT_ENTRY pRootEntries;

} ROOT_BLOCK_INFO, *PROOT_BLOCK_INFO;

//-----------------------------------------------------------------------------
// Local variables

static const TCHAR * szAllowedHexChars = _T("0123456789aAbBcCdDeEfF");
static const TCHAR * szIndexFormat_V1 = _T("data.i%x%x");
static const TCHAR * szIndexFormat_V2 = _T("%02x%08x.idx");

//-----------------------------------------------------------------------------
// Local functions

inline void CopyFileKey(LPBYTE Trg, LPBYTE Src)
{
    Trg[0x00] = Src[0x00];
    Trg[0x01] = Src[0x01];
    Trg[0x02] = Src[0x02];
    Trg[0x03] = Src[0x03];
    Trg[0x04] = Src[0x04];
    Trg[0x05] = Src[0x05];
    Trg[0x06] = Src[0x06];
    Trg[0x07] = Src[0x07];
    Trg[0x08] = Src[0x08];
    Trg[0x09] = Src[0x09];
    Trg[0x0A] = Src[0x0A];
    Trg[0x0B] = Src[0x0B];
    Trg[0x0C] = Src[0x0C];
    Trg[0x0D] = Src[0x0D];
    Trg[0x0E] = Src[0x0E];
    Trg[0x0F] = Src[0x0F];
}

TCascStorage * IsValidStorageHandle(HANDLE hStorage)
{
    TCascStorage * hs = (TCascStorage *)hStorage;

    return (hs != NULL && hs->szClassName != NULL && !strcmp(hs->szClassName, "TCascStorage")) ? hs : NULL;
}

// "data.iXY"
static bool IsIndexFileName_V1(const TCHAR * szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 8 &&
            _tcsnicmp(szFileName, _T("data.i"), 6) == 0 &&
            _tcsspn(szFileName + 6, szAllowedHexChars) == 2);
}

static bool IsIndexFileName_V2(const TCHAR * szFileName)
{
    // Check if the name looks like a valid index file
    return (_tcslen(szFileName) == 14 && 
            _tcsspn(szFileName, _T("0123456789aAbBcCdDeEfF")) == 0x0A &&
            _tcsicmp(szFileName + 0x0A, _T(".idx")) == 0);
}

static void QUERY_KEY_Free(PQUERY_KEY pBlob)
{
    if(pBlob != NULL)
    {
        if(pBlob->pbData != NULL)
            CASC_FREE(pBlob->pbData);
        
        pBlob->pbData = NULL;
        pBlob->cbData = 0;
    }
}

static void QUERY_KEY_FreeArray(PQUERY_KEY pBlobArray)
{
    // Free the buffer in the first blob
    // (will also free all buffers in the array)
    QUERY_KEY_Free(pBlobArray);

    // Free the array itself
    CASC_FREE(pBlobArray);
}

static int CompareRootEntries(const void *, const void * pvKeyEntry1, const void * pvKeyEntry2)
{
    PCASC_ROOT_ENTRY pRootEntry1 = (PCASC_ROOT_ENTRY)pvKeyEntry1;
    PCASC_ROOT_ENTRY pRootEntry2 = (PCASC_ROOT_ENTRY)pvKeyEntry2;

    // Compare name hash first
    if(pRootEntry1->FileNameHash < pRootEntry2->FileNameHash)
        return -1;
    if(pRootEntry1->FileNameHash > pRootEntry2->FileNameHash)
        return +1;
    return 0;
}

static bool IsCascIndexHeader_V1(LPBYTE pbFileData, DWORD cbFileData)
{
    PFILE_INDEX_HEADER_V1 pIndexHeader = (PFILE_INDEX_HEADER_V1)pbFileData;
    DWORD dwHeaderHash;
    bool bResult = false;

    // Check the size
    if(cbFileData >= sizeof(FILE_INDEX_HEADER_V1))
    {
        // Save the header hash
        dwHeaderHash = pIndexHeader->dwHeaderHash;
        pIndexHeader->dwHeaderHash = 0;

        // Calculate the hash
        if(hashlittle(pIndexHeader, sizeof(FILE_INDEX_HEADER_V1), 0) == dwHeaderHash)
            bResult = true;

        // Put the hash back
        pIndexHeader->dwHeaderHash = dwHeaderHash;
    }

    return bResult;
}

static bool IsCascIndexHeader_V2(LPBYTE pbFileData, DWORD cbFileData)
{
    PBLOCK_SIZE_AND_HASH pSizeAndHash = (PBLOCK_SIZE_AND_HASH)pbFileData;
    unsigned int HashHigh = 0;
    unsigned int HashLow = 0;

    // Check for the header
    if(cbFileData < sizeof(BLOCK_SIZE_AND_HASH) || pSizeAndHash->cbBlockSize < 0x10)
        return false;
    if(cbFileData < pSizeAndHash->cbBlockSize + sizeof(BLOCK_SIZE_AND_HASH))
        return false;

    // The index header for CASC v 2.0 begins with length and checksum
    hashlittle2(pSizeAndHash + 1, pSizeAndHash->cbBlockSize, &HashHigh, &HashLow);
    return (HashHigh == pSizeAndHash->dwBlockHash);
}

static LPBYTE VerifyLocaleBlock(PROOT_BLOCK_INFO pBlockInfo, LPBYTE pbFilePointer, LPBYTE pbFileEnd)
{
    // Validate the locale header
    pBlockInfo->pLocaleBlockHdr = (PFILE_LOCALE_BLOCK)pbFilePointer;
    pbFilePointer += sizeof(FILE_LOCALE_BLOCK);
    if(pbFilePointer >= pbFileEnd)
        return NULL;

    // Validate the array of 32-bit integers
    pBlockInfo->pInt32Array = (PDWORD)pbFilePointer;
    pbFilePointer = (LPBYTE)(pBlockInfo->pInt32Array + pBlockInfo->pLocaleBlockHdr->NumberOfFiles);
    if(pbFilePointer >= pbFileEnd)
        return NULL;

    // Validate the array of root entries
    pBlockInfo->pRootEntries = (PFILE_ROOT_ENTRY)pbFilePointer;
    pbFilePointer = (LPBYTE)(pBlockInfo->pRootEntries + pBlockInfo->pLocaleBlockHdr->NumberOfFiles);
    if(pbFilePointer > pbFileEnd)
        return NULL;

    // Return the position of the next block
    return pbFilePointer;
}

static int InitializeCascDirectories(TCascStorage * hs, const TCHAR * szDataPath)
{
    TCHAR * szLastPathPart;

    // Save the game data directory
    hs->szDataPath  = NewStr(szDataPath, 0);
    
    // Save the root game directory
    hs->szRootPath  = NewStr(szDataPath, 0);

    // Find the last part
    szLastPathPart = hs->szRootPath;
    for(size_t i = 0; hs->szRootPath[i] != 0; i++)
    {
        if(hs->szRootPath[i] == '\\' || hs->szRootPath[i] == '/')  
            szLastPathPart = hs->szRootPath + i;
    } 
    
    // Cut the last part
    if(szLastPathPart != NULL)
        szLastPathPart[0] = 0;
    return (hs->szRootPath && hs->szDataPath) ? ERROR_SUCCESS : ERROR_NOT_ENOUGH_MEMORY;
}

static bool IndexDirectory_OnFileFound(
    const TCHAR * szFileName,
    PDWORD IndexArray,
    PDWORD OldIndexArray,
    void * pvContext)
{
    TCascStorage * hs = (TCascStorage *)pvContext;
    DWORD IndexValue = 0;
    DWORD IndexVersion = 0;

    // Auto-detect the format of the index file name
    if(hs->szIndexFormat == NULL)
    {
        if(IsIndexFileName_V1(szFileName))
            hs->szIndexFormat = szIndexFormat_V1;
        else if(IsIndexFileName_V2(szFileName))
            hs->szIndexFormat = szIndexFormat_V2;
        else
            return false;
    }

    if(hs->szIndexFormat == szIndexFormat_V1)
    {
        // Check the index file name format
        if(!IsIndexFileName_V1(szFileName))
            return false;

        // Get the main index from the first two digits
        if(ConvertDigitToInt32(szFileName + 6, &IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertDigitToInt32(szFileName + 7, &IndexVersion) != ERROR_SUCCESS)
            return false;
    }

    else if(hs->szIndexFormat == szIndexFormat_V2)
    {
        // Check the index file name format
        if(!IsIndexFileName_V2(szFileName))
            return false;

        // Get the main index from the first two digits
        if(ConvertStringToInt32(szFileName, 2, &IndexValue) != ERROR_SUCCESS)
            return false;
        if(ConvertStringToInt32(szFileName + 2, 8, &IndexVersion) != ERROR_SUCCESS)
            return false;
    }
    else
    {
        // Should never happen
        assert(false);
        return false;
    }

    // The index value must not be greater than 0x0F
    if(IndexValue >= CASC_INDEX_COUNT)
        return false;

    // If the new subindex is greater than the previous one,
    // use this one instead
    if(IndexVersion > IndexArray[IndexValue])
    {
        OldIndexArray[IndexValue] = IndexArray[IndexValue];
        IndexArray[IndexValue] = IndexVersion;
    }
    else if(IndexVersion > OldIndexArray[IndexValue])
    {
        OldIndexArray[IndexValue] = IndexVersion;
    }

    // Note: WoW6 only keeps last two index files
    // Any additional index files are deleted at this point
    return true;
}

static TCHAR * CreateIndexFileName(TCascStorage * hs, DWORD IndexValue, DWORD IndexVersion)
{
    TCHAR szPlainName[0x40];

    // Sanity checks
    assert(hs->szIndexFormat != NULL);
    assert(hs->szIndexPath != NULL);
    assert(IndexValue <= 0x0F);

    // Create the full path
    _stprintf(szPlainName, hs->szIndexFormat, IndexValue, IndexVersion);
    return CombinePath(hs->szIndexPath, szPlainName);
}

static int VerifyAndParseKeyMapping_V1(PCASC_MAPPING_TABLE pKeyMapping, DWORD KeyIndex)
{
    PFILE_INDEX_HEADER_V1 pIndexHeader = (PFILE_INDEX_HEADER_V1)pKeyMapping->pbFileData;
    DWORD dwDataHash1;
    DWORD dwDataHash2;

    // Verify the format
    if(pIndexHeader->field_0 != 0x0005)
        return ERROR_NOT_SUPPORTED;
    if(pIndexHeader->KeyIndex != KeyIndex)              
        return ERROR_NOT_SUPPORTED;
    if(pIndexHeader->field_8 == 0)
        return ERROR_NOT_SUPPORTED;

    // Verofy the bit counts
    if(pIndexHeader->SpanSizeBytes != 0x04 ||
       pIndexHeader->SpanOffsBytes != 0x05 ||
       pIndexHeader->KeyBytes != 0x09)
        return ERROR_NOT_SUPPORTED;

    pKeyMapping->ExtraBytes    = 0;
    pKeyMapping->SpanSizeBytes = pIndexHeader->SpanSizeBytes;
    pKeyMapping->SpanOffsBytes = pIndexHeader->SpanOffsBytes;
    pKeyMapping->KeyBytes      = pIndexHeader->KeyBytes;
    pKeyMapping->SegmentBits   = pIndexHeader->SegmentBits;
    pKeyMapping->MaxFileOffset = pIndexHeader->MaxFileOffset;

    // Get the pointer to the key entry array
    pKeyMapping->nIndexEntries = pIndexHeader->KeyCount1 + pIndexHeader->KeyCount2;
    if(pKeyMapping->nIndexEntries != 0)
        pKeyMapping->pIndexEntries = (PCASC_INDEX_ENTRY)(pKeyMapping->pbFileData + sizeof(FILE_INDEX_HEADER_V1));

    // Verify hashes
    dwDataHash1 = hashlittle(pKeyMapping->pIndexEntries, pIndexHeader->KeyCount1 * sizeof(CASC_INDEX_ENTRY), 0);
    dwDataHash2 = hashlittle(pKeyMapping->pIndexEntries + pIndexHeader->KeyCount1, pIndexHeader->KeyCount2 * sizeof(CASC_INDEX_ENTRY), 0);
    if(dwDataHash1 != pIndexHeader->KeysHash1 || dwDataHash2 != pIndexHeader->KeysHash2)
        return ERROR_FILE_CORRUPT;

    return ERROR_SUCCESS;
}

static int VerifyAndParseKeyMapping_V2(PCASC_MAPPING_TABLE pKeyMapping, DWORD KeyIndex)
{
    PFILE_INDEX_HEADER_V2 pIndexHeader = (PFILE_INDEX_HEADER_V2)pKeyMapping->pbFileData;
    PBLOCK_SIZE_AND_HASH pSizeAndHash;
    LPBYTE pbLastPartEnd;
    LPBYTE pbLastPart;
    DWORD FilePosition;
    DWORD LastPartLength;
    unsigned int HashHigh = 0;
    unsigned int HashLow = 0;

    // The index header v2 begins after the SizeAndHash
    pSizeAndHash = (PBLOCK_SIZE_AND_HASH)pKeyMapping->pbFileData;
    pIndexHeader = (PFILE_INDEX_HEADER_V2)(pSizeAndHash + 1);
    if(pIndexHeader->IndexVersion != 0x07 || pIndexHeader->KeyIndex != KeyIndex)
        return ERROR_BAD_FORMAT;

    if(pIndexHeader->ExtraBytes    != 0x00 ||
       pIndexHeader->SpanSizeBytes != 0x04 ||
       pIndexHeader->SpanOffsBytes != 0x05 ||
       pIndexHeader->KeyBytes  != CASC_FILE_KEY_SIZE)
        return ERROR_BAD_FORMAT;

    // Remember the sizes
    pKeyMapping->ExtraBytes    = pIndexHeader->ExtraBytes;
    pKeyMapping->SpanSizeBytes = pIndexHeader->SpanSizeBytes;
    pKeyMapping->SpanOffsBytes = pIndexHeader->SpanOffsBytes;
    pKeyMapping->KeyBytes      = pIndexHeader->KeyBytes;
    pKeyMapping->SegmentBits   = pIndexHeader->SegmentBits;
    pKeyMapping->MaxFileOffset = pIndexHeader->MaxFileOffset;

    // Get the data position
    FilePosition = (sizeof(BLOCK_SIZE_AND_HASH) + pSizeAndHash->cbBlockSize + 0x0F) & 0xFFFFFFF0;
    if((FilePosition + 0x08) > pKeyMapping->cbFileData)
        return ERROR_BAD_FORMAT;
    
    // Get the pointer to "size+hash" block
    pSizeAndHash = (PBLOCK_SIZE_AND_HASH)(pKeyMapping->pbFileData + FilePosition);
    FilePosition += 0x08;

    if((FilePosition + pSizeAndHash->cbBlockSize) > pKeyMapping->cbFileData)
        return ERROR_BAD_FORMAT;
    if(pSizeAndHash->cbBlockSize < sizeof(CASC_INDEX_ENTRY))
        return ERROR_BAD_FORMAT;

    // Remember the array of file keys
    pKeyMapping->pIndexEntries = (PCASC_INDEX_ENTRY)(pKeyMapping->pbFileData + FilePosition);
    pKeyMapping->nIndexEntries = pSizeAndHash->cbBlockSize / sizeof(CASC_INDEX_ENTRY);
    FilePosition += pSizeAndHash->cbBlockSize;

    // Verify the integrity of the key array
    for(DWORD i = 0; i < pKeyMapping->nIndexEntries; i++)
        hashlittle2(pKeyMapping->pIndexEntries + i, sizeof(CASC_INDEX_ENTRY), &HashHigh, &HashLow);
    if(HashHigh != pSizeAndHash->dwBlockHash)
        return ERROR_BAD_FORMAT;

    // Align the data position up to next 0x1000
    FilePosition = ALIGN_TO_SIZE(FilePosition, 0x1000);
    if(FilePosition > pKeyMapping->cbFileData)
        return ERROR_BAD_FORMAT;
    
    LastPartLength = pKeyMapping->cbFileData - FilePosition;
    if(LastPartLength < 0x7800)
        return ERROR_BAD_FORMAT;
    
    pbLastPart = pKeyMapping->pbFileData + FilePosition;
    pbLastPartEnd = pbLastPart + ((LastPartLength >> 0x09) << 0x09);

    while(pbLastPart < pbLastPartEnd)
    {
        for(int i = 0; i < 0x1F8; i += 0x18)
        {
            PDWORD PtrLastPart = (PDWORD)pbLastPart;
            if(PtrLastPart[0] == 0)
                return ERROR_SUCCESS;

            HashLow = hashlittle(PtrLastPart + 1, 0x13, 0) | 0x80000000;
            if(HashLow != PtrLastPart[0])
                return ERROR_BAD_FORMAT;
        }

        pbLastPart += 0x200;
    }

    return ERROR_SUCCESS;
}

static int VerifyAndParseKeyMapping(PCASC_MAPPING_TABLE pKeyMapping, DWORD KeyIndex)
{
    // Sanity checks
    assert(pKeyMapping->pbFileData != NULL);
    assert(pKeyMapping->cbFileData != 0);

    // Check for CASC version 2
    if(IsCascIndexHeader_V2(pKeyMapping->pbFileData, pKeyMapping->cbFileData))
        return VerifyAndParseKeyMapping_V2(pKeyMapping, KeyIndex);

    // Check for CASC version 1
    if(IsCascIndexHeader_V1(pKeyMapping->pbFileData, pKeyMapping->cbFileData))
        return VerifyAndParseKeyMapping_V1(pKeyMapping, KeyIndex);

    // Unknown CASC version
    assert(false);
    return ERROR_BAD_FORMAT;
}

static int LoadKeyMapping(PCASC_MAPPING_TABLE pKeyMapping, DWORD KeyIndex)
{
    TFileStream * pStream;
    ULONGLONG FileSize = 0;
    int nError = ERROR_SUCCESS;

    // Sanity checks
    assert(pKeyMapping->szFileName != NULL && pKeyMapping->szFileName[0] != 0);

    // Open the stream for read-only access and read the file
    pStream = FileStream_OpenFile(pKeyMapping->szFileName, STREAM_FLAG_READ_ONLY | STREAM_PROVIDER_FLAT | BASE_PROVIDER_FILE);
    if(pStream != NULL)
    {
        // Retrieve the file size
        FileStream_GetSize(pStream, &FileSize);
        if((0 < FileSize && FileSize <= 0x90000) || 1)
        {
            // WoW6 actually reads THE ENTIRE file to memory
            // Verified on Mac build (x64)
            pKeyMapping->pbFileData = CASC_ALLOC(BYTE, (DWORD)FileSize);
            pKeyMapping->cbFileData = (DWORD)FileSize;

            // Load the data to memory and parse it
            if(pKeyMapping->pbFileData != NULL)
            {
                if(FileStream_Read(pStream, NULL, pKeyMapping->pbFileData, pKeyMapping->cbFileData))
                {
                    nError = VerifyAndParseKeyMapping(pKeyMapping, KeyIndex);
                }
            }
            else
                nError = ERROR_NOT_ENOUGH_MEMORY;
        }
        else
        {
            assert(false);
            nError = ERROR_BAD_FORMAT;
        }

        // Close the file stream
        FileStream_Close(pStream);
    }
    else
        nError = GetLastError();

    return ERROR_SUCCESS;
}

static int CreateArrayOfIndexEntries(TCascStorage * hs)
{
    PCASC_MAP pMap;
    DWORD TotalCount = 0;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Count the total number of files in the storage
    for(size_t i = 0; i < CASC_INDEX_COUNT; i++)
        TotalCount += hs->KeyMapping[i].nIndexEntries;

    // Create the map of all index entries
    pMap = Map_Create(TotalCount, CASC_FILE_KEY_SIZE, FIELD_OFFSET(CASC_INDEX_ENTRY, IndexKey));
    if(pMap != NULL)
    {
        // Put all index entries in the map
        for(size_t i = 0; i < CASC_INDEX_COUNT; i++)
        {
            PCASC_INDEX_ENTRY pIndexEntry = hs->KeyMapping[i].pIndexEntries;
            DWORD nIndexEntries = hs->KeyMapping[i].nIndexEntries;

            for(DWORD j = 0; j < nIndexEntries; j++)
            {
                // Insert the index entry to the map
                // Note that duplicate entries will not be inserted to the map
                //
                // Duplicate entries in WoW-WOD build 18179:
                // 9e dc a7 8f e2 09 ad d8 b7 (encoding file)
                // f3 5e bb fb d1 2b 3f ef 8b
                // c8 69 9f 18 a2 5e df 7e 52
                Map_InsertObject(pMap, pIndexEntry->IndexKey);

                // Move to the next entry
                pIndexEntry++;
            }
        }

        // Store the map to the storage handle
        hs->pIndexEntryMap = pMap;
        nError = ERROR_SUCCESS;
    }

    return nError;
}

static int CreateMapOfEncodingKeys(TCascStorage * hs, PFILE_ENCODING_SEGMENT pEncodingSegment, DWORD dwNumberOfSegments)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    size_t nMaxEntries;
    size_t nEntries = 0;
    int nError = ERROR_SUCCESS;

    // Sanity check
    assert(hs->ppEncodingEntries == NULL);
    assert(hs->pIndexEntryMap != NULL);

    // Calculate the largest eventual number of encodign entries
    nMaxEntries = (dwNumberOfSegments * CASC_ENCODING_SEGMENT_SIZE) / (sizeof(CASC_ENCODING_ENTRY) + MD5_HASH_SIZE);

    // Allocate the array of pointers to encoding entries
    hs->ppEncodingEntries = CASC_ALLOC(PCASC_ENCODING_ENTRY, nMaxEntries);
    if(hs->ppEncodingEntries != NULL)
    {
        LPBYTE pbStartOfSegment = (LPBYTE)(pEncodingSegment + dwNumberOfSegments);

        // Parse all segments
        for(DWORD i = 0; i < dwNumberOfSegments; i++)
        {
            LPBYTE pbEncodingEntry = pbStartOfSegment;
            LPBYTE pbEndOfSegment = pbStartOfSegment + CASC_ENCODING_SEGMENT_SIZE - sizeof(CASC_ENCODING_ENTRY) - MD5_HASH_SIZE;

            // Parse all encoding entries
            while(pbEncodingEntry <= pbEndOfSegment)
            {
                // Get pointer to the encoding entry
                pEncodingEntry = (PCASC_ENCODING_ENTRY)pbEncodingEntry;
                if(pEncodingEntry->KeyCount == 0)
                    break;

                // Insert the pointer the array
                hs->ppEncodingEntries[nEntries++] = pEncodingEntry;

                // Move to the next encoding entry
                pbEncodingEntry += sizeof(CASC_ENCODING_ENTRY) + (pEncodingEntry->KeyCount * MD5_HASH_SIZE);
            }

            // Move to the next segment
            pbStartOfSegment += CASC_ENCODING_SEGMENT_SIZE;
        }

        // Remember the total number of encoding entries
        hs->nEncodingEntries = nEntries;
    }
    else
        nError = ERROR_NOT_ENOUGH_MEMORY;

    return nError;
}

static DWORD GetSizeOfEncodingFile(HANDLE hFile)
{
    CASC_ENCODING_HEADER EncodingHeader;
    DWORD cbEncodingFile = 0;
    DWORD dwSegmentPos;
    DWORD dwNumSegments;
    DWORD dwBytesRead;

    // Read the endoding header
    CascReadFile(hFile, &EncodingHeader, sizeof(CASC_ENCODING_HEADER), &dwBytesRead);
    if(dwBytesRead == sizeof(CASC_ENCODING_HEADER))
    {
        dwNumSegments = ConvertBytesToInteger_4(EncodingHeader.NumSegments);
        dwSegmentPos = ConvertBytesToInteger_4(EncodingHeader.SegmentsPos);

        cbEncodingFile = sizeof(CASC_ENCODING_HEADER) +
                         dwSegmentPos +
                         dwNumSegments * (sizeof(FILE_ENCODING_SEGMENT) + CASC_ENCODING_SEGMENT_SIZE);
    }

    // Reset the position back
    CascSetFilePointer(hFile, 0, NULL, FILE_BEGIN);
    return cbEncodingFile;
}

static LPBYTE LoadCascFile(HANDLE hFile, DWORD cbMaxSize, PDWORD pcbFileData)
{
    LPBYTE pbFileData = NULL;
    DWORD cbFileData;
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Retrieve the size of the file
    cbFileData = CascGetFileSize(hFile, NULL);
    if(cbFileData != 0 && cbFileData != CASC_INVALID_SIZE)
    {
        // Trim the size to the maximum
        cbFileData = CASCLIB_MIN(cbMaxSize, cbFileData);

        // Allocate the buffer that will hold the entire file
        pbFileData = CASC_ALLOC(BYTE, cbFileData);
        if(pbFileData != NULL)
        {
            // Read the entire file to memory
            CascReadFile(hFile, pbFileData, cbFileData, &dwBytesRead);
            if(dwBytesRead != cbFileData)
                nError = ERROR_FILE_CORRUPT;
        }
        else
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }
    else
        nError = ERROR_FILE_CORRUPT;

    // If something failed, clean-up the buffers
    if(nError != ERROR_SUCCESS)
    {
        // Clear the file data
        if(pbFileData != NULL)
            CASC_FREE(pbFileData);
        pbFileData = NULL;
        cbFileData = 0;

        // Set the last error value
        SetLastError(nError);
    }

    // Return what we got
    if(pcbFileData != NULL)
        *pcbFileData = cbFileData;
    return pbFileData;
}

static int LoadIndexFiles(TCascStorage * hs)
{
    DWORD IndexArray[CASC_INDEX_COUNT];
    DWORD OldIndexArray[CASC_INDEX_COUNT];
    int nError;
    int i;

    // Scan all index files
    memset(IndexArray, 0, sizeof(IndexArray));
    memset(OldIndexArray, 0, sizeof(OldIndexArray));
    nError = ScanIndexDirectory(hs->szIndexPath, IndexDirectory_OnFileFound, IndexArray, OldIndexArray, hs);
    if(nError == ERROR_SUCCESS)
    {
        // Load each index file
        for(i = 0; i < CASC_INDEX_COUNT; i++)
        {
            hs->KeyMapping[i].szFileName = CreateIndexFileName(hs, i, IndexArray[i]);
            if(hs->KeyMapping[i].szFileName != NULL)
            {
                nError = LoadKeyMapping(&hs->KeyMapping[i], i);
                if(nError != ERROR_SUCCESS)
                    break;
            }
        }
    }

    // Now we need to build the map of the index entries
    if(nError == ERROR_SUCCESS)
    {
        nError = CreateArrayOfIndexEntries(hs);
    }

    return nError;
}

static int LoadEncodingFile(TCascStorage * hs)
{
    PFILE_ENCODING_SEGMENT pEncodingSegment;
    PCASC_ENCODING_ENTRY pEncodingEntry;
    LPBYTE pbStartOfSegment;
    LPBYTE pbEncodingFile = NULL;
    HANDLE hFile = NULL; 
    DWORD cbEncodingFile = 0;
    DWORD dwNumberOfSegments = 0;
    DWORD dwSegmentsPos = 0;
    int nError = ERROR_SUCCESS;

    // Open the encoding file
    if(!CascOpenFileByIndexKey((HANDLE)hs, &hs->EncodingEKey, 0, &hFile))
        nError = GetLastError();

    // Load the encoding file to memory
    if(nError == ERROR_SUCCESS)
    {
        // Retrieve the CASC header. We do not usually need to load
        // the entire file, but we need to know how big part of it we need
        cbEncodingFile = GetSizeOfEncodingFile(hFile);

        // Load the entire file to memory
        pbEncodingFile = LoadCascFile(hFile, cbEncodingFile, &cbEncodingFile);
        if(pbEncodingFile == NULL || cbEncodingFile <= sizeof(CASC_ENCODING_HEADER))
            nError = ERROR_FILE_CORRUPT;

        CascCloseFile(hFile);
    }

    // Verify all encoding segments
    if(nError == ERROR_SUCCESS)
    {
        // Save the encoding header
        hs->pEncodingHeader = (PCASC_ENCODING_HEADER)pbEncodingFile;

        // Convert size and offset
        dwNumberOfSegments = ConvertBytesToInteger_4(hs->pEncodingHeader->NumSegments);
        dwSegmentsPos = ConvertBytesToInteger_4(hs->pEncodingHeader->SegmentsPos);

        // Allocate the array of encoding segments
        pEncodingSegment = (PFILE_ENCODING_SEGMENT)(pbEncodingFile + sizeof(CASC_ENCODING_HEADER) + dwSegmentsPos);
        pbStartOfSegment = (LPBYTE)(pEncodingSegment + dwNumberOfSegments);

        // Go through all encoding segments and verify them
        for(DWORD i = 0; i < dwNumberOfSegments; i++)
        {
            // Check if there is enough space in the buffer
            if((pbStartOfSegment + CASC_ENCODING_SEGMENT_SIZE) > (pbEncodingFile + cbEncodingFile))
            {
                nError = ERROR_FILE_CORRUPT;
                break;
            }

            // Check the hash of the entire segment
            // Note that verifying takes considerable time of the storage loading
//          if(!VerifyDataBlockHash(pbStartOfSegment, CASC_ENCODING_SEGMENT_SIZE, pEncodingSegment->SegmentHash))
//          {
//              nError = ERROR_FILE_CORRUPT;
//              break;
//          }

            // Check if the encoding key matches
            pEncodingEntry = (PCASC_ENCODING_ENTRY)pbStartOfSegment;
            if(memcmp(pEncodingEntry->EncodingKey, pEncodingSegment->FirstEncodingKey, MD5_HASH_SIZE))
            {
                nError = ERROR_FILE_CORRUPT;
                break;
            }

            // Move to the next segment
            pbStartOfSegment += CASC_ENCODING_SEGMENT_SIZE;
            pEncodingSegment++;
        }
    }

    // Create the map of the encoding keys
    // Note that the array of encoding keys is already sorted - no need to sort it
    if(nError == ERROR_SUCCESS)
    {
        pEncodingSegment = (PFILE_ENCODING_SEGMENT)(pbEncodingFile + sizeof(CASC_ENCODING_HEADER) + dwSegmentsPos);
        nError = CreateMapOfEncodingKeys(hs, pEncodingSegment, dwNumberOfSegments);
    }
    return nError;
}

static int LoadRootFile(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    PFILE_ROOT_ENTRY pSrcEntry;
    PCASC_ROOT_ENTRY pTrgEntry;
    ROOT_BLOCK_INFO BlockInfo;
    LPBYTE pbRootFileEnd = pbRootFile + cbRootFile;
    LPBYTE pbFilePointer;
    size_t nRootEntries = 0;
    size_t nRootIndex = 0;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Calculate the root entries
    for(pbFilePointer = pbRootFile; pbFilePointer <= pbRootFileEnd; )
    {
        // Validate the root block
        pbFilePointer = VerifyLocaleBlock(&BlockInfo, pbFilePointer, pbRootFileEnd);
        if(pbFilePointer == NULL)
            break;

        // Add the number of entries
        nRootEntries = nRootEntries + BlockInfo.pLocaleBlockHdr->NumberOfFiles;
    }

    // Create a linear array of the root entries and sort it
    hs->pRootEntries = pTrgEntry = CASC_ALLOC(CASC_ROOT_ENTRY, nRootEntries);
    hs->ppRootEntries = CASC_ALLOC(PCASC_ROOT_ENTRY, nRootEntries);
    if(hs->ppRootEntries && hs->pRootEntries)
    {
        // Convert each entry from FILE_ROOT_ENTRY to CASC_ROOT_ENTRY
        for(pbFilePointer = pbRootFile; pbFilePointer <= pbRootFileEnd; )
        {
            // Validate the root block
            pbFilePointer = VerifyLocaleBlock(&BlockInfo, pbFilePointer, pbRootFileEnd);
            if(pbFilePointer == NULL)
                break;

            // Get the pointer to the first root entry
            pSrcEntry = (PFILE_ROOT_ENTRY)BlockInfo.pRootEntries;

            // Convert all entries
            for(DWORD i = 0; i < BlockInfo.pLocaleBlockHdr->NumberOfFiles; i++)
            {
                // Copy the root entry
                CopyFileKey(pTrgEntry->EncodingKey, pSrcEntry->EncodingKey);
                pTrgEntry->FileNameHash = pSrcEntry->FileNameHash;
                pTrgEntry->Locales = BlockInfo.pLocaleBlockHdr->Locales;
                pTrgEntry->Flags = BlockInfo.pLocaleBlockHdr->Flags;

//              if(pTrgEntry->FileNameHash == 0x5ddb88608673f698ULL)
//                  DebugBreak();

                // Insert the CASC root entry to the linear array of pointers
                hs->ppRootEntries[nRootIndex++] = pTrgEntry;

                // Move to the next root entry
                pSrcEntry++;
                pTrgEntry++;
            }
        }

        // Save the number of entries
        assert(nRootIndex == nRootEntries);
        hs->nRootEntries = nRootIndex;

        // Now sort the array
        qsort_pointer_array((void **)hs->ppRootEntries, hs->nRootEntries, CompareRootEntries, NULL);
        nError = ERROR_SUCCESS;
    }

    return nError;

/*
    FILE * fp = fopen("E:\\root_entries.txt", "wt");
    if(fp != NULL)
    {
        for(size_t i = 0; i < nRootEntries; i++)
        {
            fprintf(fp, "%08X: %016I64lX\n", i, hs->ppRootEntries[i]->FileNameHash);
        }
        fclose(fp);
    }
*/
}

static int LoadRootFile(TCascStorage * hs)
{
    PDWORD FileSignature;
    HANDLE hFile = NULL; 
    LPBYTE pbRootFile = NULL;
    DWORD cbRootFile = 0;
    int nError = ERROR_SUCCESS;

    // Sanity checks
    assert(hs->ppEncodingEntries != NULL);
    assert(hs->pRootEntries == NULL);
    assert(hs->nRootEntries == 0);

    // The root file is either MNDX file (Heroes of the Storm)
    // or a file containing an array of root entries (World of Warcraft 6.0+)
    // Note: The "root" key file's MD5 hash is equal to its name
    // in the configuration
    if(!CascOpenFileByEncodingKey((HANDLE)hs, &hs->RootKey, 0, &hFile))
        nError = GetLastError();

    // Load ther entire root file to memory
    if(nError == ERROR_SUCCESS)
    {
        // Load the entire root file to memory
        pbRootFile = LoadCascFile(hFile, 0xFFFFFFFF, &cbRootFile);
        if(pbRootFile == NULL || cbRootFile == 0)
            nError = ERROR_FILE_CORRUPT;

        // Close the root file
        CascCloseFile(hFile);
    }

    // Check if the file is a MNDX file
    if(nError == ERROR_SUCCESS)
    {
        FileSignature = (PDWORD)pbRootFile;
        if(FileSignature[0] == CASC_MNDX_SIGNATURE)
        {
            nError = LoadMndxRootFile(hs, pbRootFile, cbRootFile);
        }
        else
        {
            nError = LoadRootFile(hs, pbRootFile, cbRootFile);
        }
    }

    // Free the root file
    CASC_FREE(pbRootFile);
    return nError;
}

static TCascStorage * FreeCascStorage(TCascStorage * hs)
{
    size_t i;

    if(hs != NULL)
    {
        // Free the MNDX info
        if(hs->pPackages != NULL)
            CASC_FREE(hs->pPackages);
        if(hs->pMndxInfo != NULL)
            FreeMndxInfo(hs->pMndxInfo);

        // Free the pointers to file entries
        if(hs->ppRootEntries != NULL)
            CASC_FREE(hs->ppRootEntries);
        if(hs->pRootEntries != NULL)
            CASC_FREE(hs->pRootEntries);
        if(hs->ppEncodingEntries != NULL)
            CASC_FREE(hs->ppEncodingEntries);
        if(hs->pEncodingHeader != NULL)
            CASC_FREE(hs->pEncodingHeader);
        if(hs->pIndexEntryMap != NULL)
            Map_Free(hs->pIndexEntryMap);

        // Close all data files
        for(i = 0; i < CASC_MAX_DATA_FILES; i++)
        {
            if(hs->DataFileArray[i] != NULL)
            {
                FileStream_Close(hs->DataFileArray[i]);
                hs->DataFileArray[i] = NULL;
            }
        }

        // Close all key mappings
        for(i = 0; i < CASC_INDEX_COUNT; i++)
        {
            if(hs->KeyMapping[i].szFileName != NULL)
                CASC_FREE(hs->KeyMapping[i].szFileName);
            if(hs->KeyMapping[i].pbFileData != NULL)
                CASC_FREE(hs->KeyMapping[i].pbFileData);
            hs->KeyMapping[i].pIndexEntries = NULL;
        }

        // Free the file paths
        if(hs->szRootPath != NULL)
            CASC_FREE(hs->szRootPath);
        if(hs->szDataPath != NULL)
            CASC_FREE(hs->szDataPath);
        if(hs->szIndexPath != NULL)
            CASC_FREE(hs->szIndexPath);
        if(hs->szUrlPath != NULL)
            CASC_FREE(hs->szUrlPath);

        // Fre the blob arrays
        QUERY_KEY_FreeArray(hs->pArchiveArray);
        QUERY_KEY_FreeArray(hs->pPatchArchiveArray);
        QUERY_KEY_FreeArray(hs->pEncodingKeys);

        // Free the blobs
        QUERY_KEY_Free(&hs->CdnConfigKey);
        QUERY_KEY_Free(&hs->CdnBuildKey);
        QUERY_KEY_Free(&hs->ArchiveGroup);
        QUERY_KEY_Free(&hs->PatchArchiveGroup);
        QUERY_KEY_Free(&hs->RootKey);
        QUERY_KEY_Free(&hs->PatchKey);
        QUERY_KEY_Free(&hs->DownloadKey);
        QUERY_KEY_Free(&hs->InstallKey);

        // Free the storage structure
        hs->szClassName = NULL;
        CASC_FREE(hs);
    }

    return NULL;
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascOpenStorage(const TCHAR * szDataPath, DWORD dwFlags, HANDLE * phStorage)
{
    TCascStorage * hs;        
    int nError = ERROR_SUCCESS;

    CASCLIB_UNUSED(dwFlags);

    // Allocate the storage structure
    hs = (TCascStorage *)CASC_ALLOC(TCascStorage, 1);
    if(hs == NULL)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    // Load the storage configuration
    if(nError == ERROR_SUCCESS)
    {
        // Prepare the base storage parameters
        memset(hs, 0, sizeof(TCascStorage));
        hs->szClassName = "TCascStorage";
        hs->dwRefCount = 1;
        nError = InitializeCascDirectories(hs, szDataPath);
    }

    // Now we need to load the root file so we know the config files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadBuildConfiguration(hs);
    }

    // Load the index files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadIndexFiles(hs);
    }

    // Load the index files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadEncodingFile(hs);
    }

    // Load the index files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadRootFile(hs);
    }

#ifdef _DEBUG
//  if(nError == ERROR_SUCCESS)
//  {
//      CascDumpStorage("E:\\casc_dump.txt", hs, _T("e:\\Ladik\\Appdir\\CascLib\\listfile\\listfile-wow6.txt"));
//      CascDumpIndexEntries("E:\\casc_index.txt", hs);
//  }
#endif

    // If something failed, free the storage and return
    if(nError != ERROR_SUCCESS)
    {
        hs = FreeCascStorage(hs);
        SetLastError(nError);
    }

    *phStorage = (HANDLE)hs;
    return (nError == ERROR_SUCCESS);
}

bool WINAPI CascGetStorageInfo(
    HANDLE hStorage,
    CASC_STORAGE_INFO_CLASS InfoClass, 
    void * pvStorageInfo,
    size_t cbStorageInfo,
    size_t * pcbLengthNeeded)
{
    TCascStorage * hs;
    DWORD dwCascFeatures = 0;

    // Verify the storage handle
    hs = IsValidStorageHandle(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_HANDLE);
        return false;
    }

    // Differentiate between info classes
    switch(InfoClass)
    {
        case CascStorageFileCount:

            // Check the buffer size
            if(cbStorageInfo < sizeof(DWORD))
            {
                *pcbLengthNeeded = sizeof(DWORD);
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return false;
            }

            // Give the number of files
            *(PDWORD)pvStorageInfo = (DWORD)hs->pIndexEntryMap->ItemCount;
            return true;

        case CascStorageFeatures:

            // Check the buffer size
            if(cbStorageInfo < sizeof(DWORD))
            {
                *pcbLengthNeeded = sizeof(DWORD);
                SetLastError(ERROR_INSUFFICIENT_BUFFER);
                return false;
            }

            // Construct the features
            if(hs->pMndxInfo != NULL)
                dwCascFeatures |= CASC_FEATURE_LISTFILE;

            // Give the number of files
            *(PDWORD)pvStorageInfo = dwCascFeatures;
            return true;

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
    }
}



bool WINAPI CascCloseStorage(HANDLE hStorage)
{
    TCascStorage * hs;

    // Verify the storage handle
    hs = IsValidStorageHandle(hStorage);
    if(hs == NULL)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return false;
    }

    // Only free the storage if the reference count reaches 0
    if(hs->dwRefCount == 1)
    {
        FreeCascStorage(hs);
        return true;
    }

    // Just decrement number of references
    hs->dwRefCount--;
    return true;
}

