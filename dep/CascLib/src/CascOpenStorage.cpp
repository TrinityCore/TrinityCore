/*****************************************************************************/
/* CascOpenStorage.cpp                    Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Storage functions for CASC                                                */
/* Note: WoW6 offsets refer to WoW.exe 6.0.3.19116 (32-bit)                  */
/* SHA1: c10e9ffb7d040a37a356b96042657e1a0c95c0dd                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascOpenStorage.cpp             */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local structures

// Size of one segment in the ENCODING table
// The segment is filled by entries of type
#define CASC_ENCODING_SEGMENT_SIZE      0x1000

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

typedef struct _FILE_ENCODING_SEGMENT
{
    BYTE FirstEncodingKey[MD5_HASH_SIZE];       // The first encoding key in the segment
    BYTE SegmentHash[MD5_HASH_SIZE];            // MD5 hash of the entire segment

} FILE_ENCODING_SEGMENT, *PFILE_ENCODING_SEGMENT;

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

static bool IsRootFile_Starcraft1(LPBYTE pbFileData, DWORD cbFileData)
{
    LPBYTE pbFileEnd = pbFileData + cbFileData;
    LPBYTE pbHashName;
    LPBYTE pbHashEnd;

    // Skip the file name
    while(pbFileData < pbFileEnd && pbFileData[0] != '|')
        pbFileData++;
    if(pbFileData[0] != '|')
        return false;

    // Then, a MD5 must follow
    pbHashName = pbHashEnd = pbFileData + 1;
    while(pbHashEnd < pbFileEnd && pbHashEnd[0] != 0x0A)
        pbHashEnd++;
    if(pbHashEnd[0] != 0x0A)
        return false;

    // The length must be exactly 32 characters
    return ((pbHashEnd - pbHashName) == 32);
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

static bool CutLastPathPart(TCHAR * szWorkPath)
{
    size_t nLength = _tcslen(szWorkPath);

    // Go one character back
    if(nLength > 0)
        nLength--;

    // Cut ending (back)slashes, if any
    while(nLength > 0 && (szWorkPath[nLength] == _T('\\') || szWorkPath[nLength] == _T('/')))
        nLength--;

    // Cut the last path part
    while(nLength > 0)
    {
        // End of path?
        if(szWorkPath[nLength] == _T('\\') || szWorkPath[nLength] == _T('/'))
        {
            szWorkPath[nLength] = 0;
            return true;
        }

        // Go one character back
        nLength--;
    }

    return false;
}

static int InsertExtraFile(
    TCascStorage * hs,
    const char * szFileName,
    PQUERY_KEY pQueryKey)
{
    // If the given key is not encoding key (aka, it's an index key),
    // we need to create a fake encoding entry
    if(pQueryKey->cbData == MD5_HASH_SIZE * 2)
    {
        PCASC_ENCODING_ENTRY pNewEntry;
        PCASC_INDEX_ENTRY pIndexEntry;
        QUERY_KEY IndexKey;

        // Find the entry in the index table in order to get the file size
        IndexKey.pbData = pQueryKey->pbData + MD5_HASH_SIZE;
        IndexKey.cbData = MD5_HASH_SIZE;
        pIndexEntry = FindIndexEntry(hs, &IndexKey);
        if(pIndexEntry == NULL)
            return ERROR_FILE_NOT_FOUND;

        // Create a fake entry in the encoding map
        pNewEntry = (PCASC_ENCODING_ENTRY)Array_Insert(&hs->ExtraEntries, NULL, 1);
        if(pNewEntry == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Fill the encoding entry
        pNewEntry->KeyCount = 1;
        pNewEntry->FileSizeBE[0] = pIndexEntry->FileSizeLE[3];
        pNewEntry->FileSizeBE[1] = pIndexEntry->FileSizeLE[2];
        pNewEntry->FileSizeBE[2] = pIndexEntry->FileSizeLE[1];
        pNewEntry->FileSizeBE[3] = pIndexEntry->FileSizeLE[0];
        memcpy(pNewEntry->EncodingKey, pQueryKey->pbData, MD5_HASH_SIZE);
        memcpy(pNewEntry + 1, pQueryKey->pbData + MD5_HASH_SIZE, MD5_HASH_SIZE);

        // Insert the entry to the map of encoding keys
        Map_InsertObject(hs->pEncodingMap, pNewEntry, pNewEntry->EncodingKey);
    }

    // Now we need to insert the entry to the root handler in order
    // to be able to translate file name to encoding key
    return RootHandler_Insert(hs->pRootHandler, szFileName, pQueryKey->pbData);
}

static int InitializeCascDirectories(TCascStorage * hs, const TCHAR * szDataPath)
{
    TCHAR * szWorkPath;
    int nError = ERROR_NOT_ENOUGH_MEMORY;

    // Find the root directory of the storage. The root directory
    // is the one where ".build.info" is.
    szWorkPath = CascNewStr(szDataPath, 0);
    if(szWorkPath != NULL)
    {
        // Get the length and go up until we find the ".build.info" or ".build.db"
        for(;;)
        {
            // Is this a game directory?
            nError = CheckGameDirectory(hs, szWorkPath);
            if(nError == ERROR_SUCCESS)
            {
                nError = ERROR_SUCCESS;
                break;
            }

            // Cut one path part
            if(!CutLastPathPart(szWorkPath))
            {
                nError = ERROR_FILE_NOT_FOUND;
                break;
            }
        }

        // Free the work path buffer
        CASC_FREE(szWorkPath);
    }

    return nError;
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

            HashLow = hashlittle(PtrLastPart + i, 0x13, 0) | 0x80000000;
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
        if(0 < FileSize && FileSize <= 0x200000)
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
                Map_InsertObject(pMap, pIndexEntry, pIndexEntry->IndexKey);

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

static int CreateMapOfEncodingKeys(TCascStorage * hs, PFILE_ENCODING_SEGMENT pEncodingSegment, DWORD dwNumSegments)
{
    PCASC_ENCODING_ENTRY pEncodingEntry;
    DWORD dwMaxEntries;
    int nError = ERROR_SUCCESS;

    // Sanity check
    assert(hs->pIndexEntryMap != NULL);
    assert(hs->pEncodingMap == NULL);

    // Calculate the largest eventual number of encoding entries
    // Add space for extra entries
    dwMaxEntries = (dwNumSegments * CASC_ENCODING_SEGMENT_SIZE) / (sizeof(CASC_ENCODING_ENTRY) + MD5_HASH_SIZE);

    // Create the map of the encoding entries
    hs->pEncodingMap = Map_Create(dwMaxEntries + CASC_EXTRA_FILES, MD5_HASH_SIZE, FIELD_OFFSET(CASC_ENCODING_ENTRY, EncodingKey));
    if(hs->pEncodingMap != NULL)
    {
        LPBYTE pbStartOfSegment = (LPBYTE)(pEncodingSegment + dwNumSegments);

        // Parse all segments
        for(DWORD i = 0; i < dwNumSegments; i++)
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
                Map_InsertObject(hs->pEncodingMap, pEncodingEntry, pEncodingEntry->EncodingKey);

                // Move to the next encoding entry
                pbEncodingEntry += sizeof(CASC_ENCODING_ENTRY) + (pEncodingEntry->KeyCount * MD5_HASH_SIZE);
            }

            // Move to the next segment
            pbStartOfSegment += CASC_ENCODING_SEGMENT_SIZE;
        }
    }
    else
        nError = ERROR_NOT_ENOUGH_MEMORY;

    return nError;
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

static LPBYTE LoadEncodingFileToMemory(HANDLE hFile, DWORD * pcbEncodingFile)
{
    CASC_ENCODING_HEADER EncodingHeader;
    LPBYTE pbEncodingFile = NULL;
    DWORD cbEncodingFile = 0;
    DWORD dwSegmentPos = 0;
    DWORD dwNumSegments = 0;
    DWORD dwBytesRead = 0;
    int nError = ERROR_BAD_FORMAT;

    // Read the encoding header
    CascReadFile(hFile, &EncodingHeader, sizeof(CASC_ENCODING_HEADER), &dwBytesRead);
    if(dwBytesRead == sizeof(CASC_ENCODING_HEADER))
    {
        // Check the version and sizes
        if(EncodingHeader.Version != 0x01 || EncodingHeader.ChecksumSizeA != MD5_HASH_SIZE || EncodingHeader.ChecksumSizeB != MD5_HASH_SIZE)
        {
            assert(false);
            return NULL;
        }

        // Get the number of segments
        dwNumSegments = ConvertBytesToInteger_4(EncodingHeader.Entries_TableA);
        dwSegmentPos = ConvertBytesToInteger_4(EncodingHeader.Size_StringTable1);
        if(EncodingHeader.Magic[0] == 'E' && EncodingHeader.Magic[1] == 'N' && dwSegmentPos != 0 && dwNumSegments != 0)
            nError = ERROR_SUCCESS;
    }

    // Calculate and allocate space for the entire file
    if(nError == ERROR_SUCCESS)
    {
        cbEncodingFile = sizeof(CASC_ENCODING_HEADER) +
                         dwSegmentPos +
                         dwNumSegments * (sizeof(FILE_ENCODING_SEGMENT) + CASC_ENCODING_SEGMENT_SIZE);
        pbEncodingFile = CASC_ALLOC(BYTE, cbEncodingFile);
        if(pbEncodingFile == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // If all went OK, we load the entire file to memory
    if(nError == ERROR_SUCCESS)
    {
        // Copy the header itself
        memcpy(pbEncodingFile, &EncodingHeader, sizeof(CASC_ENCODING_HEADER));

        // Read the rest of the data
        CascReadFile(hFile, pbEncodingFile + sizeof(CASC_ENCODING_HEADER), cbEncodingFile - sizeof(CASC_ENCODING_HEADER), &dwBytesRead);
        if(dwBytesRead != (cbEncodingFile - sizeof(CASC_ENCODING_HEADER)))
            nError = ERROR_FILE_CORRUPT;
    }

    // Give the loaded file length
    if(pcbEncodingFile != NULL)
        *pcbEncodingFile = cbEncodingFile;
    return pbEncodingFile;
}

static LPBYTE LoadRootFileToMemory(HANDLE hFile, DWORD * pcbRootFile)
{
    LPBYTE pbRootFile = NULL;
    DWORD cbRootFile = 0;
    DWORD dwBytesRead = 0;
    int nError = ERROR_SUCCESS;

    // Retrieve the size of the ROOT file
    cbRootFile = CascGetFileSize(hFile, NULL);
    if(cbRootFile == 0)
        nError = ERROR_BAD_FORMAT;

    // Allocate space for the entire file
    if(nError == ERROR_SUCCESS)
    {
        pbRootFile = CASC_ALLOC(BYTE, cbRootFile);
        if(pbRootFile == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // If all went OK, we load the entire file to memory
    if(nError == ERROR_SUCCESS)
    {
        // Read the entire file to memory
        CascReadFile(hFile, pbRootFile, cbRootFile, &dwBytesRead);
        if(dwBytesRead != cbRootFile)
            nError = ERROR_FILE_CORRUPT;
    }

    // Give the loaded file length
    if(pcbRootFile != NULL)
        *pcbRootFile = cbRootFile;
    return pbRootFile;
}

static int LoadEncodingFile(TCascStorage * hs)
{
    PFILE_ENCODING_SEGMENT pEncodingSegment;
    QUERY_KEY EncodingKey;
    LPBYTE pbStartOfSegment;
    LPBYTE pbEncodingFile = NULL;
    HANDLE hFile = NULL;
    DWORD cbEncodingFile = 0;
    DWORD dwNumSegments = 0;
    DWORD dwSegmentsPos = 0;
    int nError = ERROR_SUCCESS;

    // Open the encoding file
    EncodingKey.pbData = hs->EncodingKey.pbData + MD5_HASH_SIZE;
    EncodingKey.cbData = MD5_HASH_SIZE;
    if(!CascOpenFileByIndexKey((HANDLE)hs, &EncodingKey, 0, &hFile))
        nError = GetLastError();

    // Load the entire ENCODING file to memory
    if(nError == ERROR_SUCCESS)
    {
        // Load the necessary part of the ENCODING file to memory
        pbEncodingFile = LoadEncodingFileToMemory(hFile, &cbEncodingFile);
        if(pbEncodingFile == NULL || cbEncodingFile <= sizeof(CASC_ENCODING_HEADER))
            nError = ERROR_FILE_CORRUPT;

        // Close the encoding file
        CascCloseFile(hFile);
    }

    // Verify all encoding segments
    if(nError == ERROR_SUCCESS)
    {
        PCASC_ENCODING_HEADER pEncodingHeader = (PCASC_ENCODING_HEADER)pbEncodingFile;

        // Convert size and offset
        dwNumSegments = ConvertBytesToInteger_4(pEncodingHeader->Entries_TableA);
        dwSegmentsPos = ConvertBytesToInteger_4(pEncodingHeader->Size_StringTable1);

        // Store the encoding file to the CASC storage
        hs->EncodingFile.pbData = pbEncodingFile;
        hs->EncodingFile.cbData = cbEncodingFile;

        // Allocate the array of encoding segments
        pEncodingSegment = (PFILE_ENCODING_SEGMENT)(pbEncodingFile + sizeof(CASC_ENCODING_HEADER) + dwSegmentsPos);
        pbStartOfSegment = (LPBYTE)(pEncodingSegment + dwNumSegments);

        // Go through all encoding segments and verify them
        for(DWORD i = 0; i < dwNumSegments; i++)
        {
            PCASC_ENCODING_ENTRY pEncodingEntry = (PCASC_ENCODING_ENTRY)pbStartOfSegment;

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

            // Check if the encoding key matches with the expected first value
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
        nError = CreateMapOfEncodingKeys(hs, pEncodingSegment, dwNumSegments);
    }

    return nError;
}

static int LoadRootFile(TCascStorage * hs, DWORD dwLocaleMask)
{
    PDWORD FileSignature;
    HANDLE hFile = NULL;
    LPBYTE pbRootFile = NULL;
    DWORD cbRootFile = 0;
    int nError = ERROR_SUCCESS;

    // Sanity checks
    assert(hs->pEncodingMap != NULL);
    assert(hs->pRootHandler == NULL);

    // Locale: The default parameter is 0 - in that case,
    // we assign the default locale, loaded from the .build.info file
    if(dwLocaleMask == 0)
        dwLocaleMask = hs->dwDefaultLocale;

    // Load the entire ROOT file to memory
    if(!CascOpenFileByEncodingKey((HANDLE)hs, &hs->RootKey, 0, &hFile))
        nError = GetLastError();

    // Load the entire file to memory
    if(nError == ERROR_SUCCESS)
    {
        pbRootFile = LoadRootFileToMemory(hFile, &cbRootFile);
        CascCloseFile(hFile);
    }

    // Check if the version of the ROOT file
    if(nError == ERROR_SUCCESS && pbRootFile != NULL)
    {
        FileSignature = (PDWORD)pbRootFile;
        switch(FileSignature[0])
        {
            case CASC_MNDX_ROOT_SIGNATURE:
                nError = RootHandler_CreateMNDX(hs, pbRootFile, cbRootFile);
                break;

            case CASC_DIABLO3_ROOT_SIGNATURE:
                nError = RootHandler_CreateDiablo3(hs, pbRootFile, cbRootFile);
                break;

            case CASC_OVERWATCH_ROOT_SIGNATURE:
                nError = RootHandler_CreateOverwatch(hs, pbRootFile, cbRootFile);
                break;

            default:
                if(IsRootFile_Starcraft1(pbRootFile, cbRootFile))
                    nError = RootHandler_CreateSC1(hs, pbRootFile, cbRootFile);
                else
                    nError = RootHandler_CreateWoW6(hs, pbRootFile, cbRootFile, dwLocaleMask);
                break;
        }
    }

    // Insert entry for the
    if(nError == ERROR_SUCCESS)
    {
        InsertExtraFile(hs, "ENCODING", &hs->EncodingKey);
        InsertExtraFile(hs, "ROOT", &hs->RootKey);
        InsertExtraFile(hs, "DOWNLOAD", &hs->DownloadKey);
        InsertExtraFile(hs, "INSTALL", &hs->InstallKey);
    }

#ifdef _DEBUG
    if(nError == ERROR_SUCCESS)
    {
        //RootFile_Dump(hs,
        //              pbRootFile,
        //              cbRootFile,
        //              _T("\\casc_root_%build%.txt"),
        //              _T("\\Ladik\\Appdir\\CascLib\\listfile\\listfile-wow6.txt"),
        //              DUMP_LEVEL_INDEX_ENTRIES);
    }
#endif

    // Free the root file
    CASC_FREE(pbRootFile);
    return nError;
}

static TCascStorage * FreeCascStorage(TCascStorage * hs)
{
    size_t i;

    if(hs != NULL)
    {
        // Free the root handler
        if(hs->pRootHandler != NULL)
            RootHandler_Close(hs->pRootHandler);
        hs->pRootHandler = NULL;

        // Free the extra encoding entries
        Array_Free(&hs->ExtraEntries);

        // Free the pointers to file entries
        if(hs->pEncodingMap != NULL)
            Map_Free(hs->pEncodingMap);
        if(hs->EncodingFile.pbData != NULL)
            CASC_FREE(hs->EncodingFile.pbData);
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
        if(hs->szBuildFile != NULL)
            CASC_FREE(hs->szBuildFile);
        if(hs->szIndexPath != NULL)
            CASC_FREE(hs->szIndexPath);
        if(hs->szUrlPath != NULL)
            CASC_FREE(hs->szUrlPath);

        // Free the blobs
        FreeCascBlob(&hs->CdnConfigKey);
        FreeCascBlob(&hs->CdnBuildKey);
        FreeCascBlob(&hs->ArchivesGroup);
        FreeCascBlob(&hs->ArchivesKey);
        FreeCascBlob(&hs->PatchArchivesKey);
        FreeCascBlob(&hs->PatchArchivesGroup);
        FreeCascBlob(&hs->RootKey);
        FreeCascBlob(&hs->PatchKey);
        FreeCascBlob(&hs->DownloadKey);
        FreeCascBlob(&hs->InstallKey);
        FreeCascBlob(&hs->EncodingKey);

        // Free the storage structure
        hs->szClassName = NULL;
        CASC_FREE(hs);
    }

    return NULL;
}

//-----------------------------------------------------------------------------
// Public functions

bool WINAPI CascOpenStorage(const TCHAR * szDataPath, DWORD dwLocaleMask, HANDLE * phStorage)
{
    TCascStorage * hs;
    int nError = ERROR_SUCCESS;

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
        hs->dwFileBeginDelta = 0xFFFFFFFF;
        hs->dwDefaultLocale = CASC_LOCALE_ENUS | CASC_LOCALE_ENGB;
        hs->dwRefCount = 1;
        nError = InitializeCascDirectories(hs, szDataPath);
    }

    // Now we need to load the root file so we know the config files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadBuildInfo(hs);
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

    // Initialize the dynamic array for extra files
    // Reserve space for 0x20 encoding entries
    if(nError == ERROR_SUCCESS)
    {
        nError = Array_Create(&hs->ExtraEntries, CASC_ENCODING_ENTRY_1, CASC_EXTRA_FILES);
    }

    // Load the index files
    if(nError == ERROR_SUCCESS)
    {
        nError = LoadRootFile(hs, dwLocaleMask);
    }

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
    DWORD dwInfoValue = 0;

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
            dwInfoValue = (DWORD)hs->pIndexEntryMap->ItemCount;
            break;

        case CascStorageFeatures:
            dwInfoValue |= (hs->pRootHandler->dwRootFlags & ROOT_FLAG_HAS_NAMES) ? CASC_FEATURE_LISTFILE : 0;
            break;

        case CascStorageGameInfo:
            dwInfoValue = hs->dwGameInfo;
            break;

        case CascStorageGameBuild:
            dwInfoValue = hs->dwBuildNumber;
            break;

        case CascStorageInstalledLocales:
            dwInfoValue = hs->dwDefaultLocale;
            break;

        default:
            SetLastError(ERROR_INVALID_PARAMETER);
            return false;
    }

    //
    // Return the required DWORD value
    //

    if(cbStorageInfo < sizeof(DWORD))
    {
        *pcbLengthNeeded = sizeof(DWORD);
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        return false;
    }

    // Give the number of files
    *(PDWORD)pvStorageInfo = dwInfoValue;
    return true;
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

