/*****************************************************************************/
/* SBaseFileTable.cpp                     Copyright (c) Ladislav Zezula 2010 */
/*---------------------------------------------------------------------------*/
/* Description: Common handler for classic and new hash&block tables         */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 06.09.10  1.00  Lad  The first version of SBaseFileTable.cpp              */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#define INVALID_FLAG_VALUE 0xCCCCCCCC
#define MAX_FLAG_INDEX     512

//-----------------------------------------------------------------------------
// Local structures

// Structure for HET table header
typedef struct _HET_TABLE_HEADER
{
    DWORD dwTableSize;                      // Size of the entire HET table, including HET_TABLE_HEADER (in bytes)
    DWORD dwMaxFileCount;                   // Maximum number of files in the MPQ
    DWORD dwHashTableSize;                  // Size of the hash table (in bytes)
    DWORD dwHashEntrySize;                  // Effective size of the hash entry (in bits)
    DWORD dwIndexSizeTotal;                 // Total size of file index (in bits)
    DWORD dwIndexSizeExtra;                 // Extra bits in the file index
    DWORD dwIndexSize;                      // Effective size of the file index (in bits)
    DWORD dwIndexTableSize;                 // Size of the block index subtable (in bytes)

} HET_TABLE_HEADER, *PHET_TABLE_HEADER;

// Structure for BET table header
typedef struct _BET_TABLE_HEADER
{
    DWORD dwTableSize;                      // Size of the entire BET table, including the header (in bytes)
    DWORD dwFileCount;                      // Number of files in the BET table
    DWORD dwUnknown08;
    DWORD dwTableEntrySize;                 // Size of one table entry (in bits)
    DWORD dwBitIndex_FilePos;               // Bit index of the file position (within the entry record)
    DWORD dwBitIndex_FileSize;              // Bit index of the file size (within the entry record)
    DWORD dwBitIndex_CmpSize;               // Bit index of the compressed size (within the entry record)
    DWORD dwBitIndex_FlagIndex;             // Bit index of the flag index (within the entry record)
    DWORD dwBitIndex_Unknown;               // Bit index of the ??? (within the entry record)
    DWORD dwBitCount_FilePos;               // Bit size of file position (in the entry record)
    DWORD dwBitCount_FileSize;              // Bit size of file size (in the entry record)
    DWORD dwBitCount_CmpSize;               // Bit size of compressed file size (in the entry record)
    DWORD dwBitCount_FlagIndex;             // Bit size of flags index (in the entry record)
    DWORD dwBitCount_Unknown;               // Bit size of ??? (in the entry record)
    DWORD dwBetHashSizeTotal;               // Total size of the BET hash
    DWORD dwBetHashSizeExtra;               // Extra bits in the BET hash
    DWORD dwBetHashSize;                    // Effective size of BET hash (in bits)
    DWORD dwBetHashArraySize;               // Size of BET hashes array, in bytes
    DWORD dwFlagCount;                      // Number of flags in the following array

} BET_TABLE_HEADER, *PBET_TABLE_HEADER;

//-----------------------------------------------------------------------------
// Support for calculating bit sizes

static void InitFileFlagArray(LPDWORD FlagArray)
{
    for(DWORD dwFlagIndex = 0; dwFlagIndex < MAX_FLAG_INDEX; dwFlagIndex++)
        FlagArray[dwFlagIndex] = INVALID_FLAG_VALUE;
}

static DWORD GetFileFlagIndex(LPDWORD FlagArray, DWORD dwFlags)
{
    // Find free or equal entry in the flag array
    for(DWORD dwFlagIndex = 0; dwFlagIndex < MAX_FLAG_INDEX; dwFlagIndex++)
    {
        if(FlagArray[dwFlagIndex] == INVALID_FLAG_VALUE || FlagArray[dwFlagIndex] == dwFlags)
        {
            FlagArray[dwFlagIndex] = dwFlags;
            return dwFlagIndex;
        }
    }

    // This should never happen
    assert(false);
    return 0xFFFFFFFF;
}

static DWORD GetNecessaryBitCount(ULONGLONG MaxValue)
{
    DWORD dwBitCount = 0;

    while(MaxValue > 0)
    {
        MaxValue >>= 1;
        dwBitCount++;
    }
    
    return dwBitCount;
}

//-----------------------------------------------------------------------------
// Support functions for BIT_ARRAY

static USHORT SetBitsMask[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};

static TBitArray * CreateBitArray(
    DWORD NumberOfBits,
    BYTE FillValue)
{
    TBitArray * pBitArray;
    size_t nSize = sizeof(TBitArray) + (NumberOfBits + 7) / 8;

    // Allocate the bit array
    pBitArray = (TBitArray *)STORM_ALLOC(BYTE, nSize);
    if(pBitArray != NULL)
    {
        memset(pBitArray, FillValue, nSize);
        pBitArray->NumberOfBits = NumberOfBits;
    }

    return pBitArray;
}

void TBitArray::GetBits(
    unsigned int nBitPosition,
    unsigned int nBitLength,
    void * pvBuffer,
    int nResultByteSize)
{
    unsigned char * pbBuffer = (unsigned char *)pvBuffer;
    unsigned int nBytePosition0 = (nBitPosition / 8);
    unsigned int nBytePosition1 = nBytePosition0 + 1;
    unsigned int nByteLength = (nBitLength / 8);
    unsigned int nBitOffset = (nBitPosition & 0x07);
    unsigned char BitBuffer;

    // Keep compiler happy for platforms where nResultByteSize is not used
    nResultByteSize = nResultByteSize;

#ifdef _DEBUG
    // Check if the target is properly zeroed
    for(int i = 0; i < nResultByteSize; i++)
        assert(pbBuffer[i] == 0);
#endif

#ifndef PLATFORM_LITTLE_ENDIAN
    // Adjust the buffer pointer for big endian platforms
    pbBuffer += (nResultByteSize - 1);
#endif    

    // Copy whole bytes, if any
    while(nByteLength > 0)
    {
        // Is the current position in the Elements byte-aligned?
        if(nBitOffset != 0)
        {
            BitBuffer = (unsigned char)((Elements[nBytePosition0] >> nBitOffset) | (Elements[nBytePosition1] << (0x08 - nBitOffset)));
        }
        else
        {
            BitBuffer = Elements[nBytePosition0];
        }

#ifdef PLATFORM_LITTLE_ENDIAN
        *pbBuffer++ = BitBuffer;
#else
        *pbBuffer-- = BitBuffer;
#endif

        // Move byte positions and lengths
        nBytePosition1++;
        nBytePosition0++;
        nByteLength--;
    }

    // Get the rest of the bits
    nBitLength = (nBitLength & 0x07);
    if(nBitLength != 0)
    {
        *pbBuffer = (unsigned char)(Elements[nBytePosition0] >> nBitOffset);

        if(nBitLength > (8 - nBitOffset))
            *pbBuffer = (unsigned char)((Elements[nBytePosition1] << (8 - nBitOffset)) | (Elements[nBytePosition0] >> nBitOffset));

        *pbBuffer &= (0x01 << nBitLength) - 1;
    }
}

void TBitArray::SetBits(
    unsigned int nBitPosition,
    unsigned int nBitLength,
    void * pvBuffer,
    int nResultByteSize)
{
    unsigned char * pbBuffer = (unsigned char *)pvBuffer;
    unsigned int nBytePosition = (nBitPosition / 8);
    unsigned int nBitOffset = (nBitPosition & 0x07);
    unsigned short BitBuffer = 0;
    unsigned short AndMask = 0;
    unsigned short OneByte = 0;

    // Keep compiler happy for platforms where nResultByteSize is not used
    nResultByteSize = nResultByteSize;

#ifndef PLATFORM_LITTLE_ENDIAN
    // Adjust the buffer pointer for big endian platforms
    pbBuffer += (nResultByteSize - 1);
#endif    

    // Copy whole bytes, if any
    while(nBitLength > 8)
    {
        // Reload the bit buffer
#ifdef PLATFORM_LITTLE_ENDIAN
        OneByte = *pbBuffer++;
#else
        OneByte = *pbBuffer--;
#endif
        // Update the BitBuffer and AndMask for the bit array
        BitBuffer = (BitBuffer >> 0x08) | (OneByte << nBitOffset);
        AndMask = (AndMask >> 0x08) | (0x00FF << nBitOffset);

        // Update the byte in the array
        Elements[nBytePosition] = (BYTE)((Elements[nBytePosition] & ~AndMask) | BitBuffer);

        // Move byte positions and lengths
        nBytePosition++;
        nBitLength -= 0x08;
    }

    if(nBitLength != 0)
    {
        // Reload the bit buffer
        OneByte = *pbBuffer;

        // Update the AND mask for the last bit
        BitBuffer = (BitBuffer >> 0x08) | (OneByte << nBitOffset);
        AndMask = (AndMask >> 0x08) | (SetBitsMask[nBitLength] << nBitOffset);

        // Update the byte in the array
        Elements[nBytePosition] = (BYTE)((Elements[nBytePosition] & ~AndMask) | BitBuffer);

        // Update the next byte, if needed
        if(AndMask & 0xFF00)
        {
            nBytePosition++;
            BitBuffer >>= 0x08;
            AndMask >>= 0x08;

            Elements[nBytePosition] = (BYTE)((Elements[nBytePosition] & ~AndMask) | BitBuffer);
        }
    }
}


//-----------------------------------------------------------------------------
// Support for hash table

// Returns a hash table entry in the following order:
// 1) A hash table entry with the neutral locale
// 2) A hash table entry with any other locale
// 3) NULL
static TMPQHash * GetHashEntryAny(TMPQArchive * ha, const char * szFileName)
{
    TMPQHash * pHashNeutral = NULL;
    TMPQHash * pFirstHash = GetFirstHashEntry(ha, szFileName);
    TMPQHash * pHashAny = NULL;
    TMPQHash * pHash = pFirstHash;

    // Parse the found hashes
    while(pHash != NULL)
    {
        // If we found neutral hash, remember it
        if(pHash->lcLocale == 0)
            pHashNeutral = pHash;
        if(pHashAny == NULL)
            pHashAny = pHash;

        // Get the next hash entry for that file
        pHash = GetNextHashEntry(ha, pFirstHash, pHash); 
    }

    // At the end, return neutral hash (if found), otherwise NULL
    return (pHashNeutral != NULL) ? pHashNeutral : pHashAny;
}

// Returns a hash table entry in the following order:
// 1) A hash table entry with the preferred locale
// 2) A hash table entry with the neutral locale
// 3) NULL
static TMPQHash * GetHashEntryLocale(TMPQArchive * ha, const char * szFileName, LCID lcLocale)
{
    TMPQHash * pHashNeutral = NULL;
    TMPQHash * pFirstHash = GetFirstHashEntry(ha, szFileName);
    TMPQHash * pHash = pFirstHash;

    // Parse the found hashes
    while(pHash != NULL)
    {
        // If the locales match, return it
        if(pHash->lcLocale == lcLocale)
            return pHash;
        
        // If we found neutral hash, remember it
        if(pHash->lcLocale == 0)
            pHashNeutral = pHash;

        // Get the next hash entry for that file
        pHash = GetNextHashEntry(ha, pFirstHash, pHash); 
    }

    // At the end, return neutral hash (if found), otherwise NULL
    return pHashNeutral;
}

// Returns a hash table entry in the following order:
// 1) A hash table entry with the preferred locale
// 2) NULL
static TMPQHash * GetHashEntryExact(TMPQArchive * ha, const char * szFileName, LCID lcLocale)
{
    TMPQHash * pFirstHash = GetFirstHashEntry(ha, szFileName);
    TMPQHash * pHash = pFirstHash;

    // Parse the found hashes
    while(pHash != NULL)
    {
        // If the locales match, return it
        if(pHash->lcLocale == lcLocale)
            return pHash;
        
        // Get the next hash entry for that file
        pHash = GetNextHashEntry(ha, pFirstHash, pHash); 
    }

    // Not found
    return NULL;
}

static TMPQHash * TranslateHashTable(
    TMPQArchive * ha,
    ULONGLONG * pcbTableSize)
{
    TMPQHash * pHashTable;
    size_t HashTableSize;

    // Allocate copy of the hash table
    pHashTable = STORM_ALLOC(TMPQHash, ha->pHeader->dwHashTableSize);
    if(pHashTable != NULL)
    {
        // Copy the hash table
        HashTableSize = sizeof(TMPQHash) * ha->pHeader->dwHashTableSize;
        memcpy(pHashTable, ha->pHashTable, HashTableSize);

        // Give the size to the caller
        if(pcbTableSize != NULL)
        {
            *pcbTableSize = (ULONGLONG)HashTableSize;
        }
    }

    return pHashTable;
}

static TMPQBlock * TranslateBlockTable(
    TMPQArchive * ha,
    ULONGLONG * pcbTableSize,
    bool * pbNeedHiBlockTable)
{
    TFileEntry * pFileEntry = ha->pFileTable;
    TMPQBlock * pBlockTable;
    TMPQBlock * pBlock;
    size_t BlockTableSize;
    bool bNeedHiBlockTable = false;

    // Allocate copy of the hash table
    pBlockTable = pBlock = STORM_ALLOC(TMPQBlock, ha->dwFileTableSize);
    if(pBlockTable != NULL)
    {
        // Copy the block table
        BlockTableSize = sizeof(TMPQBlock) * ha->dwFileTableSize;
        for(DWORD i = 0; i < ha->dwFileTableSize; i++)
        {
            bNeedHiBlockTable = (pFileEntry->ByteOffset >> 32) ? true : false;
            pBlock->dwFilePos = (DWORD)pFileEntry->ByteOffset;
            pBlock->dwFSize   = pFileEntry->dwFileSize;
            pBlock->dwCSize   = pFileEntry->dwCmpSize;
            pBlock->dwFlags   = pFileEntry->dwFlags;

            pFileEntry++;
            pBlock++;
        }

        // Give the size to the caller
        if(pcbTableSize != NULL)
            *pcbTableSize = (ULONGLONG)BlockTableSize;

        if(pbNeedHiBlockTable != NULL)
            *pbNeedHiBlockTable = bNeedHiBlockTable;
    }

    return pBlockTable;
}

static USHORT * TranslateHiBlockTable(
    TMPQArchive * ha,
    ULONGLONG * pcbTableSize)
{
    TFileEntry * pFileEntry = ha->pFileTable;
    USHORT * pHiBlockTable;
    USHORT * pHiBlock;
    size_t HiBlockTableSize;

    // Allocate copy of the hash table
    pHiBlockTable = pHiBlock = STORM_ALLOC(USHORT, ha->dwFileTableSize);
    if(pHiBlockTable != NULL)
    {
        // Copy the block table
        HiBlockTableSize = sizeof(USHORT) * ha->dwFileTableSize;
        for(DWORD i = 0; i < ha->dwFileTableSize; i++)
            pHiBlock[i] = (USHORT)(pFileEntry[i].ByteOffset >> 0x20);

        // Give the size to the caller
        if(pcbTableSize != NULL)
            *pcbTableSize = (ULONGLONG)HiBlockTableSize;
    }

    return pHiBlockTable;
}

//-----------------------------------------------------------------------------
// General EXT table functions

TMPQExtTable * LoadExtTable(
    TMPQArchive * ha,
    ULONGLONG ByteOffset,
    size_t Size,
    DWORD dwSignature,
    DWORD dwKey)
{
    TMPQExtTable * pCompressed = NULL;      // Compressed table
    TMPQExtTable * pExtTable = NULL;        // Uncompressed table

    // Do nothing if the size is zero
    if(ByteOffset != 0 && Size != 0)
    {
        // Allocate size for the compressed table
        pExtTable = (TMPQExtTable *)STORM_ALLOC(BYTE, Size);
        if(pExtTable != NULL)
        {
            // Load the table from the MPQ
            ByteOffset += ha->MpqPos;
            if(!FileStream_Read(ha->pStream, &ByteOffset, pExtTable, (DWORD)Size))
            {
                STORM_FREE(pExtTable);
                return NULL;
            }

            // Swap the ext table header
            BSWAP_ARRAY32_UNSIGNED(pExtTable, sizeof(TMPQExtTable));
            if(pExtTable->dwSignature != dwSignature)
            {
                STORM_FREE(pExtTable);
                return NULL;
            }

            // Decrypt the block
            BSWAP_ARRAY32_UNSIGNED(pExtTable + 1, pExtTable->dwDataSize);
            DecryptMpqBlock(pExtTable + 1, (DWORD)(Size - sizeof(TMPQExtTable)), dwKey);
            BSWAP_ARRAY32_UNSIGNED(pExtTable + 1, pExtTable->dwDataSize);

            // If the table is compressed, decompress it
            if((pExtTable->dwDataSize + sizeof(TMPQExtTable)) > Size)
            {
                pCompressed = pExtTable;
                pExtTable = (TMPQExtTable *)STORM_ALLOC(BYTE, sizeof(TMPQExtTable) + pCompressed->dwDataSize);
                if(pExtTable != NULL)
                {
                    int cbOutBuffer = (int)pCompressed->dwDataSize;
                    int cbInBuffer = (int)Size;

                    // Decompress the extended table
                    pExtTable->dwSignature = pCompressed->dwSignature;
                    pExtTable->dwVersion   = pCompressed->dwVersion;
                    pExtTable->dwDataSize  = pCompressed->dwDataSize;
                    if(!SCompDecompress2((char *)(pExtTable + 1), &cbOutBuffer, (char *)(pCompressed + 1), cbInBuffer))
                    {
                        STORM_FREE(pExtTable);
                        pExtTable = NULL;
                    }
                }

                // Free the compressed block
                STORM_FREE(pCompressed);
            }
        }
    }

    // Return the decompressed table to the caller
    return pExtTable;
}

// Used in MPQ Editor
void FreeMpqBuffer(void * pvBuffer)
{
    STORM_FREE(pvBuffer);
}

static int SaveMpqTable(
    TMPQArchive * ha,
    void * pMpqTable,
    ULONGLONG ByteOffset,
    size_t Size,
    unsigned char * md5,
    DWORD dwKey,
    bool bCompress)
{
    ULONGLONG FileOffset;
    void * pCompressed = NULL;
    int nError = ERROR_SUCCESS;

    // Do we have to compress the table?
    if(bCompress)
    {
        int cbOutBuffer = (int)Size;
        int cbInBuffer = (int)Size;

        // Allocate extra space for compressed table
        pCompressed = STORM_ALLOC(BYTE, Size);
        if(pCompressed == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Compress the table
        SCompCompress((char *)pCompressed, &cbOutBuffer, (char *)pMpqTable, cbInBuffer, MPQ_COMPRESSION_ZLIB, 0, 0);

        // If the compression failed, revert it. Otherwise, swap the tables
        if(cbOutBuffer >= cbInBuffer)
        {
            STORM_FREE(pCompressed);
            pCompressed = NULL;
        }
        else
        {
            pMpqTable = pCompressed;
        }
    }

    // Encrypt the table
    if(dwKey != 0)
    {
        BSWAP_ARRAY32_UNSIGNED(pMpqTable, Size);
        EncryptMpqBlock(pMpqTable, (DWORD)Size, dwKey);
        BSWAP_ARRAY32_UNSIGNED(pMpqTable, Size);
    }

    // Calculate the MD5
    if(md5 != NULL)
    {
        CalculateDataBlockHash(pMpqTable, (DWORD)Size, md5);
    }

    // Save the table to the MPQ
    BSWAP_ARRAY32_UNSIGNED(pMpqTable, Size);
    FileOffset = ha->MpqPos + ByteOffset;
    if(!FileStream_Write(ha->pStream, &FileOffset, pMpqTable, (DWORD)Size))
        nError = GetLastError();

    // Free the compressed table, if any
    if(pCompressed != NULL)
        STORM_FREE(pCompressed);
    return nError;
}

static int SaveExtTable(
    TMPQArchive * ha,
    TMPQExtTable * pExtTable,
    ULONGLONG ByteOffset,
    DWORD dwTableSize,
    unsigned char * md5,
    DWORD dwKey,
    bool bCompress,
    LPDWORD pcbTotalSize)
{
    ULONGLONG FileOffset;
    TMPQExtTable * pCompressed = NULL;
    DWORD cbTotalSize = 0;
    int nError = ERROR_SUCCESS;

    // Do we have to compress the table?
    if(bCompress)
    {
        int cbOutBuffer = (int)dwTableSize;
        int cbInBuffer = (int)dwTableSize;

        // Allocate extra space for compressed table
        pCompressed = (TMPQExtTable *)STORM_ALLOC(BYTE, dwTableSize);
        if(pCompressed == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Compress the table
        pCompressed->dwSignature = pExtTable->dwSignature;
        pCompressed->dwVersion   = pExtTable->dwVersion;
        pCompressed->dwDataSize  = pExtTable->dwDataSize;
        SCompCompress((char *)(pCompressed + 1), &cbOutBuffer, (char *)(pExtTable + 1), cbInBuffer, MPQ_COMPRESSION_ZLIB, 0, 0);

        // If the compression failed, revert it. Otherwise, swap the tables
        if(cbOutBuffer >= cbInBuffer)
        {
            STORM_FREE(pCompressed);
            pCompressed = NULL;
        }
        else
        {
            pExtTable = pCompressed;
        }
    }

    // Encrypt the table
    if(dwKey != 0)
    {
        BSWAP_ARRAY32_UNSIGNED(pExtTable + 1, pExtTable->dwDataSize);
        EncryptMpqBlock(pExtTable + 1, (DWORD)(dwTableSize - sizeof(TMPQExtTable)), dwKey);
        BSWAP_ARRAY32_UNSIGNED(pExtTable + 1, pExtTable->dwDataSize);
    }

    // Calculate the MD5 of the table after
    if(md5 != NULL)
    {
        CalculateDataBlockHash(pExtTable, dwTableSize, md5);
    }

    // Save the table to the MPQ
    FileOffset = ha->MpqPos + ByteOffset;
    if(FileStream_Write(ha->pStream, &FileOffset, pExtTable, dwTableSize))
        cbTotalSize += dwTableSize;
    else
        nError = GetLastError();

    // We have to write raw data MD5
    if(nError == ERROR_SUCCESS && ha->pHeader->dwRawChunkSize != 0)
    {
        nError = WriteMemDataMD5(ha->pStream,
                                 FileOffset,
                                 pExtTable,
                                 dwTableSize,
                                 ha->pHeader->dwRawChunkSize,
                                &cbTotalSize);
    }

    // Give the total written size, if needed
    if(pcbTotalSize != NULL)
        *pcbTotalSize = cbTotalSize;

    // Free the compressed table, if any
    if(pCompressed != NULL)
        STORM_FREE(pCompressed);
    return nError;
}

//-----------------------------------------------------------------------------
// Support for HET table

static void CreateHetHeader(
    TMPQHetTable * pHetTable,
    PHET_TABLE_HEADER pHetHeader)
{
    // Fill the BET header
    pHetHeader->dwMaxFileCount   = pHetTable->dwMaxFileCount;
    pHetHeader->dwHashTableSize  = pHetTable->dwHashTableSize;
    pHetHeader->dwHashEntrySize  = pHetTable->dwHashBitSize;
    pHetHeader->dwIndexSizeTotal = GetNecessaryBitCount(pHetTable->dwMaxFileCount);
    pHetHeader->dwIndexSizeExtra = 0;
    pHetHeader->dwIndexSize      = pHetHeader->dwIndexSizeTotal;
    pHetHeader->dwIndexTableSize = ((pHetHeader->dwIndexSizeTotal * pHetTable->dwHashTableSize) + 7) / 8;

    // Calculate the total size needed for holding HET table
    pHetHeader->dwTableSize = sizeof(HET_TABLE_HEADER) +
                              pHetHeader->dwHashTableSize +
                              pHetHeader->dwIndexTableSize;
}

TMPQHetTable * CreateHetTable(DWORD dwMaxFileCount, DWORD dwHashBitSize, bool bCreateEmpty)
{
    TMPQHetTable * pHetTable;

    pHetTable = STORM_ALLOC(TMPQHetTable, 1);
    if(pHetTable != NULL)
    {
        pHetTable->dwIndexSizeTotal = 0;
        pHetTable->dwIndexSizeExtra = 0;
        pHetTable->dwIndexSize      = pHetTable->dwIndexSizeTotal;
        pHetTable->dwMaxFileCount   = dwMaxFileCount;
        pHetTable->dwHashTableSize  = (dwMaxFileCount * 4 / 3);
        pHetTable->dwHashBitSize    = dwHashBitSize;

        // Size of one index is calculated from max file count
        pHetTable->dwIndexSizeTotal = GetNecessaryBitCount(dwMaxFileCount);
        pHetTable->dwIndexSizeExtra = 0;
        pHetTable->dwIndexSize      = pHetTable->dwIndexSizeTotal;

        // Allocate hash table
        pHetTable->pHetHashes = STORM_ALLOC(BYTE, pHetTable->dwHashTableSize);
        memset(pHetTable->pHetHashes, 0, pHetTable->dwHashTableSize);

        // If we shall create empty HET table, we have to allocate empty block index table as well
        if(bCreateEmpty)
            pHetTable->pBetIndexes = CreateBitArray(pHetTable->dwHashTableSize * pHetTable->dwIndexSizeTotal, 0xFF);

        // Calculate masks
        pHetTable->AndMask64 = 0;
        if(dwHashBitSize != 0x40)
            pHetTable->AndMask64 = (ULONGLONG)1 << dwHashBitSize;
        pHetTable->AndMask64--;

        pHetTable->OrMask64 = (ULONGLONG)1 << (dwHashBitSize - 1);
    }

    return pHetTable;
}

static TMPQHetTable * TranslateHetTable(TMPQExtTable * pExtTable)
{
    HET_TABLE_HEADER HetHeader;
    TMPQHetTable * pHetTable = NULL;
    LPBYTE pbSrcData = (LPBYTE)(pExtTable + 1);

    // Sanity check
    assert(pExtTable->dwSignature == HET_TABLE_SIGNATURE);
    assert(pExtTable->dwVersion == 1);

    // Verify size of the HET table
    if(pExtTable != NULL && pExtTable->dwDataSize >= sizeof(HET_TABLE_HEADER))
    {
        // Copy the table header in order to have it aligned and swapped
        memcpy(&HetHeader, pbSrcData, sizeof(HET_TABLE_HEADER));
        BSWAP_ARRAY32_UNSIGNED(&HetHeader, sizeof(HET_TABLE_HEADER));
        pbSrcData += sizeof(HET_TABLE_HEADER);

        // Verify the size of the table in the header
        if(HetHeader.dwTableSize == pExtTable->dwDataSize)
        {
            // Create translated table
            pHetTable = CreateHetTable(HetHeader.dwMaxFileCount, HetHeader.dwHashEntrySize, false);
            if(pHetTable != NULL)
            {
                // Copy the hash table size, index size and extra bits from the HET header
                pHetTable->dwHashTableSize  = HetHeader.dwHashTableSize;
                pHetTable->dwIndexSizeTotal = HetHeader.dwIndexSizeTotal;
                pHetTable->dwIndexSizeExtra = HetHeader.dwIndexSizeExtra;

                // Fill the hash table
                if(pHetTable->pHetHashes != NULL)
                    memcpy(pHetTable->pHetHashes, pbSrcData, pHetTable->dwHashTableSize);
                pbSrcData += pHetTable->dwHashTableSize;

                // Copy the block index table
                pHetTable->pBetIndexes = CreateBitArray(HetHeader.dwIndexTableSize * 8, 0xFF);
                if(pHetTable->pBetIndexes != NULL)
                    memcpy(pHetTable->pBetIndexes->Elements, pbSrcData, HetHeader.dwIndexTableSize);
                pbSrcData += HetHeader.dwIndexTableSize;
            }
        }
    }

    return pHetTable;
}

static TMPQExtTable * TranslateHetTable(TMPQHetTable * pHetTable, ULONGLONG * pcbHetTable)
{
    TMPQExtTable * pExtTable = NULL;
    HET_TABLE_HEADER HetHeader;
    LPBYTE pbLinearTable = NULL;
    LPBYTE pbTrgData;
    size_t HetTableSize;

    // Prepare header of the HET table
    CreateHetHeader(pHetTable, &HetHeader);

    // Calculate the total size needed for holding the encrypted HET table
    HetTableSize = HetHeader.dwTableSize;

    // Allocate space for the linear table
    pbLinearTable = STORM_ALLOC(BYTE, sizeof(TMPQExtTable) + HetTableSize);
    if(pbLinearTable != NULL)
    {
        // Create the common ext table header
        pExtTable = (TMPQExtTable *)pbLinearTable;
        pExtTable->dwSignature = HET_TABLE_SIGNATURE;
        pExtTable->dwVersion   = 1;
        pExtTable->dwDataSize  = (DWORD)HetTableSize;
        pbTrgData = (LPBYTE)(pExtTable + 1);

        // Copy the HET table header
        memcpy(pbTrgData, &HetHeader, sizeof(HET_TABLE_HEADER));
        BSWAP_ARRAY32_UNSIGNED(pbTrgData, sizeof(HET_TABLE_HEADER));
        pbTrgData += sizeof(HET_TABLE_HEADER);

        // Copy the array of HET hashes
        memcpy(pbTrgData, pHetTable->pHetHashes, pHetTable->dwHashTableSize);
        pbTrgData += pHetTable->dwHashTableSize;

        // Copy the bit array of BET indexes
        memcpy(pbTrgData, pHetTable->pBetIndexes->Elements, HetHeader.dwIndexTableSize);

        // Calculate the total size of the table, including the TMPQExtTable
        if(pcbHetTable != NULL)
        {
            *pcbHetTable = (ULONGLONG)(sizeof(TMPQExtTable) + HetTableSize);
        }
    }

    return pExtTable;
}

DWORD GetFileIndex_Het(TMPQArchive * ha, const char * szFileName)
{
    TMPQHetTable * pHetTable = ha->pHetTable;
    ULONGLONG FileNameHash;
    ULONGLONG AndMask64;
    ULONGLONG OrMask64;
    ULONGLONG BetHash;
    DWORD StartIndex;
    DWORD Index;
    BYTE HetHash;                   // Upper 8 bits of the masked file name hash

    // Do nothing if the MPQ has no HET table
    assert(ha->pHetTable != NULL);

    // Calculate 64-bit hash of the file name
    AndMask64 = pHetTable->AndMask64;
    OrMask64 = pHetTable->OrMask64;
    FileNameHash = (HashStringJenkins(szFileName) & AndMask64) | OrMask64;

    // Split the file name hash into two parts:
    // Part 1: The highest 8 bits of the name hash
    // Part 2: The rest of the name hash (without the highest 8 bits)
    HetHash = (BYTE)(FileNameHash >> (pHetTable->dwHashBitSize - 8));
    BetHash = FileNameHash & (AndMask64 >> 0x08);

    // Calculate the starting index to the hash table
    StartIndex = Index = (DWORD)(FileNameHash % pHetTable->dwHashTableSize);

    // Go through HET table until we find a terminator
    while(pHetTable->pHetHashes[Index] != HET_ENTRY_FREE)
    {
        // Did we find match ?
        if(pHetTable->pHetHashes[Index] == HetHash)
        {
            DWORD dwFileIndex = 0;

            // Get the index of the BetHash
            pHetTable->pBetIndexes->GetBits(pHetTable->dwIndexSizeTotal * Index,
                                            pHetTable->dwIndexSize,
                                           &dwFileIndex,
                                            4);

            //
            // TODO: This condition only happens when we are opening a MPQ
            // where some files were deleted by StormLib. Perhaps 
            // we should not allow shrinking of the file table in MPQs v 4.0?
            // assert(dwFileIndex <= ha->dwFileTableSize);
            //

            // Verify the BetHash against the entry in the table of BET hashes
            if(dwFileIndex <= ha->dwFileTableSize && ha->pFileTable[dwFileIndex].BetHash == BetHash)
                return dwFileIndex;
        }

        // Move to the next entry in the primary search table
        // If we came to the start index again, we are done
        Index = (Index + 1) % pHetTable->dwHashTableSize;
        if(Index == StartIndex)
            break;
    }

    // File not found
    return HASH_ENTRY_FREE;
}

DWORD AllocateHetEntry(
    TMPQArchive * ha,
    TFileEntry * pFileEntry)
{
    TMPQHetTable * pHetTable = ha->pHetTable;
    ULONGLONG FileNameHash;
    ULONGLONG AndMask64;
    ULONGLONG OrMask64;
    ULONGLONG BetHash;
    DWORD FreeHetIndex = HASH_ENTRY_FREE;
    DWORD dwFileIndex;
    DWORD StartIndex;
    DWORD Index;
    BYTE HetHash;                   // Upper 8 bits of the masked file name hash

    // Do nothing if the MPQ has no HET table
    assert(ha->pHetTable != NULL);

    // Calculate 64-bit hash of the file name
    AndMask64 = pHetTable->AndMask64;
    OrMask64 = pHetTable->OrMask64;
    FileNameHash = (HashStringJenkins(pFileEntry->szFileName) & AndMask64) | OrMask64;

    // Calculate the starting index to the hash table
    StartIndex = Index = (DWORD)(FileNameHash % pHetTable->dwHashTableSize);

    // Split the file name hash into two parts:
    // Part 1: The highest 8 bits of the name hash
    // Part 2: The rest of the name hash (without the highest 8 bits)
    HetHash = (BYTE)(FileNameHash >> (pHetTable->dwHashBitSize - 8));
    BetHash = FileNameHash & (AndMask64 >> 0x08);

    // Go through HET table until we find a terminator
    for(;;)
    {
        // Check for entries that might have been deleted
        if(pHetTable->pHetHashes[Index] == HET_ENTRY_DELETED)
        {
            DWORD dwInvalidBetIndex = (1 << pHetTable->dwIndexSizeTotal) - 1;
            DWORD dwBetIndex = 0;

            // Verify the BET index. If it's really free, we can use it
            dwFileIndex = (DWORD)(pFileEntry - ha->pFileTable);
            pHetTable->pBetIndexes->GetBits(pHetTable->dwIndexSizeTotal * Index,
                                            pHetTable->dwIndexSize,
                                           &dwBetIndex,
                                            4);
            
            if(dwBetIndex == dwInvalidBetIndex)
            {
                FreeHetIndex = Index;
                break;
            }
        }

        // Is that entry free ?
        if(pHetTable->pHetHashes[Index] == HET_ENTRY_FREE)
        {
            FreeHetIndex = Index;
            break;
        }

        // Move to the next entry in the primary search table
        // If we came to the start index again, we are done
        Index = (Index + 1) % pHetTable->dwHashTableSize;
        if(Index == StartIndex)
            return HASH_ENTRY_FREE;
    }

    // Fill the HET table entry
    dwFileIndex = (DWORD)(pFileEntry - ha->pFileTable);
    pHetTable->pHetHashes[FreeHetIndex] = HetHash;
    pHetTable->pBetIndexes->SetBits(pHetTable->dwIndexSizeTotal * FreeHetIndex,
                                    pHetTable->dwIndexSize,
                                   &dwFileIndex,
                                    4);
    // Fill the file entry
    pFileEntry->BetHash    = BetHash;
    pFileEntry->dwHetIndex = FreeHetIndex;
    return FreeHetIndex;
}

void FreeHetTable(TMPQHetTable * pHetTable)
{
    if(pHetTable != NULL)
    {
        if(pHetTable->pHetHashes != NULL)
            STORM_FREE(pHetTable->pHetHashes);
        if(pHetTable->pBetIndexes != NULL)
            STORM_FREE(pHetTable->pBetIndexes);

        STORM_FREE(pHetTable);
    }
}

//-----------------------------------------------------------------------------
// Support for BET table

static void CreateBetHeader(
    TMPQArchive * ha,
    PBET_TABLE_HEADER pBetHeader)
{
    TFileEntry * pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
    TFileEntry * pFileEntry;
    ULONGLONG MaxByteOffset = 0;
    DWORD FlagArray[MAX_FLAG_INDEX];
    DWORD dwMaxFlagIndex = 0;
    DWORD dwMaxFileSize = 0;
    DWORD dwMaxCmpSize = 0;
    DWORD dwFlagIndex;

    // Initialize array of flag combinations
    InitFileFlagArray(FlagArray);

    // Get the maximum values for the BET table
    for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++)
    {
        // Highest file position in the MPQ
        if(pFileEntry->ByteOffset > MaxByteOffset)
            MaxByteOffset = pFileEntry->ByteOffset;

        // Biggest file size
        if(pFileEntry->dwFileSize > dwMaxFileSize)
            dwMaxFileSize = pFileEntry->dwFileSize;

        // Biggest compressed size
        if(pFileEntry->dwCmpSize > dwMaxCmpSize)
            dwMaxCmpSize = pFileEntry->dwCmpSize;

        // Check if this flag was there before
        dwFlagIndex = GetFileFlagIndex(FlagArray, pFileEntry->dwFlags);
        if(dwFlagIndex > dwMaxFlagIndex)
            dwMaxFlagIndex = dwFlagIndex;
    }

    // Now save bit count for every piece of file information
    pBetHeader->dwBitIndex_FilePos   = 0;
    pBetHeader->dwBitCount_FilePos   = GetNecessaryBitCount(MaxByteOffset);

    pBetHeader->dwBitIndex_FileSize  = pBetHeader->dwBitIndex_FilePos + pBetHeader->dwBitCount_FilePos;
    pBetHeader->dwBitCount_FileSize  = GetNecessaryBitCount(dwMaxFileSize);

    pBetHeader->dwBitIndex_CmpSize   = pBetHeader->dwBitIndex_FileSize + pBetHeader->dwBitCount_FileSize;
    pBetHeader->dwBitCount_CmpSize   = GetNecessaryBitCount(dwMaxCmpSize);

    pBetHeader->dwBitIndex_FlagIndex = pBetHeader->dwBitIndex_CmpSize + pBetHeader->dwBitCount_CmpSize;
    pBetHeader->dwBitCount_FlagIndex = GetNecessaryBitCount(dwMaxFlagIndex + 1);

    pBetHeader->dwBitIndex_Unknown   = pBetHeader->dwBitIndex_FlagIndex + pBetHeader->dwBitCount_FlagIndex;
    pBetHeader->dwBitCount_Unknown   = 0;

    // Calculate the total size of one entry
    pBetHeader->dwTableEntrySize     = pBetHeader->dwBitCount_FilePos +
                                       pBetHeader->dwBitCount_FileSize +
                                       pBetHeader->dwBitCount_CmpSize +
                                       pBetHeader->dwBitCount_FlagIndex +
                                       pBetHeader->dwBitCount_Unknown;

    // Save the file count and flag count
    pBetHeader->dwFileCount          = ha->dwFileTableSize;
    pBetHeader->dwFlagCount          = dwMaxFlagIndex + 1;
    pBetHeader->dwUnknown08          = 0x10;

    // Save the total size of the BET hash
    pBetHeader->dwBetHashSizeTotal   = ha->pHetTable->dwHashBitSize - 0x08;
    pBetHeader->dwBetHashSizeExtra   = 0;
    pBetHeader->dwBetHashSize        = pBetHeader->dwBetHashSizeTotal;
    pBetHeader->dwBetHashArraySize   = ((pBetHeader->dwBetHashSizeTotal * pBetHeader->dwFileCount) + 7) / 8;

    // Save the total table size
    pBetHeader->dwTableSize          = sizeof(BET_TABLE_HEADER) +
                                       pBetHeader->dwFlagCount * sizeof(DWORD) +
                                     ((pBetHeader->dwTableEntrySize * pBetHeader->dwFileCount) + 7) / 8 +
                                      pBetHeader->dwBetHashArraySize;
}

TMPQBetTable * CreateBetTable(DWORD dwFileCount)
{
    TMPQBetTable * pBetTable;

    // Allocate BET table
    pBetTable = STORM_ALLOC(TMPQBetTable, 1);
    if(pBetTable != NULL)
    {
        memset(pBetTable, 0, sizeof(TMPQBetTable));
        pBetTable->dwFileCount = dwFileCount;
    }

    return pBetTable;
}

static TMPQBetTable * TranslateBetTable(
    TMPQArchive * ha,
    TMPQExtTable * pExtTable)
{
    BET_TABLE_HEADER BetHeader;
    TMPQBetTable * pBetTable = NULL;
    LPBYTE pbSrcData = (LPBYTE)(pExtTable + 1);
    DWORD LengthInBytes;

    // Sanity check
    assert(pExtTable->dwSignature == BET_TABLE_SIGNATURE);
    assert(pExtTable->dwVersion == 1);
    assert(ha->pHetTable != NULL);
    ha = ha;

    // Verify size of the HET table
    if(pExtTable != NULL && pExtTable->dwDataSize >= sizeof(BET_TABLE_HEADER))
    {
        // Copy the table header in order to have it aligned and swapped
        memcpy(&BetHeader, pbSrcData, sizeof(BET_TABLE_HEADER));
        BSWAP_ARRAY32_UNSIGNED(&BetHeader, sizeof(BET_TABLE_HEADER));
        pbSrcData += sizeof(BET_TABLE_HEADER);

        // Some MPQs affected by a bug in StormLib have pBetTable->dwFileCount
        // greater than ha->dwMaxFileCount
        if(BetHeader.dwFileCount > ha->dwMaxFileCount)
            return NULL;

        // Verify the size of the table in the header
        if(BetHeader.dwTableSize == pExtTable->dwDataSize)
        {
            // Create translated table
            pBetTable = CreateBetTable(BetHeader.dwFileCount);
            if(pBetTable != NULL)
            {
                // Copy the variables from the header to the BetTable
                pBetTable->dwTableEntrySize     = BetHeader.dwTableEntrySize;
                pBetTable->dwBitIndex_FilePos   = BetHeader.dwBitIndex_FilePos;
                pBetTable->dwBitIndex_FileSize  = BetHeader.dwBitIndex_FileSize;
                pBetTable->dwBitIndex_CmpSize   = BetHeader.dwBitIndex_CmpSize;
                pBetTable->dwBitIndex_FlagIndex = BetHeader.dwBitIndex_FlagIndex;
                pBetTable->dwBitIndex_Unknown   = BetHeader.dwBitIndex_Unknown;
                pBetTable->dwBitCount_FilePos   = BetHeader.dwBitCount_FilePos;
                pBetTable->dwBitCount_FileSize  = BetHeader.dwBitCount_FileSize;
                pBetTable->dwBitCount_CmpSize   = BetHeader.dwBitCount_CmpSize;
                pBetTable->dwBitCount_FlagIndex = BetHeader.dwBitCount_FlagIndex;
                pBetTable->dwBitCount_Unknown   = BetHeader.dwBitCount_Unknown;

                // Since we don't know what the "unknown" is, we'll assert when it's nonzero
                assert(pBetTable->dwBitCount_Unknown == 0);

                // Allocate array for flags
                if(BetHeader.dwFlagCount != 0)
                {
                    // Allocate array for file flags and load it
                    pBetTable->pFileFlags = STORM_ALLOC(DWORD, BetHeader.dwFlagCount);
                    if(pBetTable->pFileFlags != NULL)
                    {
                        LengthInBytes = BetHeader.dwFlagCount * sizeof(DWORD);
                        memcpy(pBetTable->pFileFlags, pbSrcData, LengthInBytes);
                        BSWAP_ARRAY32_UNSIGNED(pBetTable->pFileFlags, LengthInBytes);
                        pbSrcData += LengthInBytes;
                    }

                    // Save the number of flags
                    pBetTable->dwFlagCount = BetHeader.dwFlagCount;
                }

                // Load the bit-based file table
                pBetTable->pFileTable = CreateBitArray(pBetTable->dwTableEntrySize * BetHeader.dwFileCount, 0);
                LengthInBytes = (pBetTable->pFileTable->NumberOfBits + 7) / 8;
                if(pBetTable->pFileTable != NULL)
                    memcpy(pBetTable->pFileTable->Elements, pbSrcData, LengthInBytes);
                pbSrcData += LengthInBytes;

                // Fill the sizes of BET hash
                pBetTable->dwBetHashSizeTotal = BetHeader.dwBetHashSizeTotal;
                pBetTable->dwBetHashSizeExtra = BetHeader.dwBetHashSizeExtra;
                pBetTable->dwBetHashSize      = BetHeader.dwBetHashSize;
                
                // Create and load the array of BET hashes
                pBetTable->pBetHashes = CreateBitArray(pBetTable->dwBetHashSizeTotal * BetHeader.dwFileCount, 0);
                LengthInBytes = (pBetTable->pBetHashes->NumberOfBits + 7) / 8;
                if(pBetTable->pBetHashes != NULL)
                    memcpy(pBetTable->pBetHashes->Elements, pbSrcData, LengthInBytes);
                pbSrcData += BetHeader.dwBetHashArraySize;

                // Dump both tables
//              DumpHetAndBetTable(ha->pHetTable, pBetTable);
            }
        }
    }

    return pBetTable;
}

TMPQExtTable * TranslateBetTable(
    TMPQArchive * ha,
    ULONGLONG * pcbBetTable)
{
    TMPQExtTable * pExtTable = NULL;
    BET_TABLE_HEADER BetHeader;
    TBitArray * pBitArray = NULL;
    LPBYTE pbLinearTable = NULL;
    LPBYTE pbTrgData;
    size_t BetTableSize;
    DWORD LengthInBytes;
    DWORD FlagArray[MAX_FLAG_INDEX];
    DWORD i;

    // Calculate the bit sizes of various entries
    InitFileFlagArray(FlagArray);
    CreateBetHeader(ha, &BetHeader);

    // Calculate the size of the BET table
    BetTableSize = sizeof(BET_TABLE_HEADER) +
                   BetHeader.dwFlagCount * sizeof(DWORD) +
                 ((BetHeader.dwTableEntrySize * BetHeader.dwFileCount) + 7) / 8 +
                   BetHeader.dwBetHashArraySize;

    // Allocate space
    pbLinearTable = STORM_ALLOC(BYTE, sizeof(TMPQExtTable) + BetTableSize);
    if(pbLinearTable != NULL)
    {
        // Create the common ext table header
        pExtTable = (TMPQExtTable *)pbLinearTable;
        pExtTable->dwSignature = BET_TABLE_SIGNATURE;
        pExtTable->dwVersion   = 1;
        pExtTable->dwDataSize  = (DWORD)BetTableSize;
        pbTrgData = (LPBYTE)(pExtTable + 1);

        // Copy the BET table header
        memcpy(pbTrgData, &BetHeader, sizeof(BET_TABLE_HEADER));
        BSWAP_ARRAY32_UNSIGNED(pbTrgData, sizeof(BET_TABLE_HEADER));
        pbTrgData += sizeof(BET_TABLE_HEADER);

        // Save the bit-based block table
        pBitArray = CreateBitArray(BetHeader.dwFileCount * BetHeader.dwTableEntrySize, 0);
        if(pBitArray != NULL)
        {
            TFileEntry * pFileEntry = ha->pFileTable;
            DWORD dwFlagIndex = 0;
            DWORD nBitOffset = 0;

            // Construct the array of flag values and bit-based file table
            for(i = 0; i < BetHeader.dwFileCount; i++, pFileEntry++)
            {
                //
                // Note: Blizzard MPQs contain valid values even for non-existant files
                // (FilePos, FileSize, CmpSize and FlagIndex)
                // Note: If flags is zero, it must be in the flag table too !!!
                //
                
                // Save the byte offset
                pBitArray->SetBits(nBitOffset + BetHeader.dwBitIndex_FilePos,
                                   BetHeader.dwBitCount_FilePos,
                                  &pFileEntry->ByteOffset,
                                   8);
                pBitArray->SetBits(nBitOffset + BetHeader.dwBitIndex_FileSize,
                                   BetHeader.dwBitCount_FileSize,
                                  &pFileEntry->dwFileSize,
                                   4);
                pBitArray->SetBits(nBitOffset + BetHeader.dwBitIndex_CmpSize,
                                   BetHeader.dwBitCount_CmpSize,
                                  &pFileEntry->dwCmpSize,
                                   4);

                // Save the flag index
                dwFlagIndex = GetFileFlagIndex(FlagArray, pFileEntry->dwFlags);
                pBitArray->SetBits(nBitOffset + BetHeader.dwBitIndex_FlagIndex,
                                   BetHeader.dwBitCount_FlagIndex,
                                  &dwFlagIndex,
                                   4);

                // Move the bit offset
                nBitOffset += BetHeader.dwTableEntrySize;
            }

            // Write the array of flags
            LengthInBytes = BetHeader.dwFlagCount * sizeof(DWORD);
            memcpy(pbTrgData, FlagArray, LengthInBytes);
            BSWAP_ARRAY32_UNSIGNED(pbTrgData, LengthInBytes);
            pbTrgData += LengthInBytes;

            // Write the bit-based block table
            LengthInBytes = (pBitArray->NumberOfBits + 7) / 8;
            memcpy(pbTrgData, pBitArray->Elements, LengthInBytes);
            pbTrgData += LengthInBytes;

            // Free the bit array
            STORM_FREE(pBitArray);
        }

        // Create bit array for BET hashes
        pBitArray = CreateBitArray(BetHeader.dwBetHashSizeTotal * BetHeader.dwFileCount, 0);
        if(pBitArray != NULL)
        {
            TFileEntry * pFileEntry = ha->pFileTable;
            ULONGLONG AndMask64 = ha->pHetTable->AndMask64;
            ULONGLONG OrMask64 = ha->pHetTable->OrMask64;

            for(i = 0; i < BetHeader.dwFileCount; i++)
            {
                ULONGLONG FileNameHash = 0;

                // Calculate 64-bit hash of the file name
                if((pFileEntry->dwFlags & MPQ_FILE_EXISTS) && pFileEntry->szFileName != NULL)
                {
                    FileNameHash = (HashStringJenkins(pFileEntry->szFileName) & AndMask64) | OrMask64;
                    FileNameHash = FileNameHash & (AndMask64 >> 0x08);
                }

                // Insert the name hash to the bit array
                pBitArray->SetBits(BetHeader.dwBetHashSizeTotal * i,
                                   BetHeader.dwBetHashSize,
                                  &FileNameHash,
                                   8);

                // Move to the next file entry
                pFileEntry++;
            }

            // Write the array of BET hashes
            LengthInBytes = (pBitArray->NumberOfBits + 7) / 8;
            memcpy(pbTrgData, pBitArray->Elements, LengthInBytes);
            pbTrgData += LengthInBytes;

            // Free the bit array
            STORM_FREE(pBitArray);
        }

        // Write the size of the BET table in the MPQ
        if(pcbBetTable != NULL)
        {
            *pcbBetTable = (ULONGLONG)(sizeof(TMPQExtTable) + BetTableSize);
        }
    }

    return pExtTable;
}

void FreeBetTable(TMPQBetTable * pBetTable)
{
    if(pBetTable != NULL)
    {
        if(pBetTable->pFileTable != NULL)
            STORM_FREE(pBetTable->pFileTable);
        if(pBetTable->pFileFlags != NULL)
            STORM_FREE(pBetTable->pFileFlags);
        if(pBetTable->pBetHashes != NULL)
            STORM_FREE(pBetTable->pBetHashes);

        STORM_FREE(pBetTable);
    }
}

//-----------------------------------------------------------------------------
// Support for file table

TFileEntry * GetFileEntryAny(TMPQArchive * ha, const char * szFileName)
{
    TMPQHash * pHash;
    DWORD dwFileIndex;

    // If we have HET table in the MPQ, try to find the file in HET table
    if(ha->pHetTable != NULL)
    {
        dwFileIndex = GetFileIndex_Het(ha, szFileName);
        if(dwFileIndex != HASH_ENTRY_FREE)
            return ha->pFileTable + dwFileIndex;
    }

    // Otherwise, perform the file search in the classic hash table
    if(ha->pHashTable != NULL)
    {
        pHash = GetHashEntryAny(ha, szFileName);
        if(pHash != NULL && pHash->dwBlockIndex < ha->dwFileTableSize)
            return ha->pFileTable + pHash->dwBlockIndex;
    }
    
    // Not found
    return NULL;
}

TFileEntry * GetFileEntryLocale(TMPQArchive * ha, const char * szFileName, LCID lcLocale)
{
    TMPQHash * pHash;
    DWORD dwFileIndex;

    // If we have HET table in the MPQ, try to find the file in HET table
    if(ha->pHetTable != NULL)
    {
        dwFileIndex = GetFileIndex_Het(ha, szFileName);
        if(dwFileIndex != HASH_ENTRY_FREE)
            return ha->pFileTable + dwFileIndex;
    }

    // Otherwise, perform the file search in the classic hash table
    if(ha->pHashTable != NULL)
    {
        pHash = GetHashEntryLocale(ha, szFileName, lcLocale);
        if(pHash != NULL && pHash->dwBlockIndex < ha->dwFileTableSize)
            return ha->pFileTable + pHash->dwBlockIndex;
    }
    
    // Not found
    return NULL;
}

TFileEntry * GetFileEntryExact(TMPQArchive * ha, const char * szFileName, LCID lcLocale)
{
    TMPQHash * pHash;
    DWORD dwFileIndex;

    // If we have HET table in the MPQ, try to find the file in HET table
    if(ha->pHetTable != NULL)
    {
        dwFileIndex = GetFileIndex_Het(ha, szFileName);
        if(dwFileIndex != HASH_ENTRY_FREE)
            return ha->pFileTable + dwFileIndex;
    }

    // Otherwise, perform the file search in the classic hash table
    if(ha->pHashTable != NULL)
    {
        pHash = GetHashEntryExact(ha, szFileName, lcLocale);
        if(pHash != NULL && pHash->dwBlockIndex < ha->dwFileTableSize)
            return ha->pFileTable + pHash->dwBlockIndex;
    }
    
    // Not found
    return NULL;
}

TFileEntry * GetFileEntryByIndex(TMPQArchive * ha, DWORD dwIndex)
{
    // For MPQs with classic hash table
    if(dwIndex < ha->dwFileTableSize)
        return ha->pFileTable + dwIndex;
    return NULL;
}

void AllocateFileName(TFileEntry * pFileEntry, const char * szFileName)
{
    // Sanity check
    assert(pFileEntry != NULL);

    // If the file name is pseudo file name, free it at this point
    if(IsPseudoFileName(pFileEntry->szFileName, NULL))
    {
        if(pFileEntry->szFileName != NULL)
            STORM_FREE(pFileEntry->szFileName);
        pFileEntry->szFileName = NULL;
    }

    // Only allocate new file name if it's not there yet
    if(pFileEntry->szFileName == NULL)
    {
        pFileEntry->szFileName = STORM_ALLOC(char, strlen(szFileName) + 1);
        if(pFileEntry->szFileName != NULL)
            strcpy(pFileEntry->szFileName, szFileName);
    }
}


// Finds a free file entry. Does NOT increment table size.
TFileEntry * FindFreeFileEntry(TMPQArchive * ha)
{
    TFileEntry * pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
    TFileEntry * pFreeEntry = NULL;
    TFileEntry * pFileEntry;

    // Try to find a free entry
    for(pFileEntry = ha->pFileTable; pFileEntry < pFileTableEnd; pFileEntry++)
    {
        // If that entry is free, we reuse it
        if((pFileEntry->dwFlags & MPQ_FILE_EXISTS) == 0)
        {
            pFreeEntry = pFileEntry;
            break;
        }

        //
        // Note: Files with "delete marker" are not deleted.
        // Don't consider them free entries
        //
    }

    // Do we have a deleted entry?
    if(pFreeEntry != NULL)
    {
        ClearFileEntry(ha, pFreeEntry);
        return pFreeEntry;
    }

    // If no file entry within the existing file table is free,
    // we try the reserve space after current file table
    if(ha->dwFileTableSize < ha->dwMaxFileCount)
        return ha->pFileTable + ha->dwFileTableSize;

    // If we reached maximum file count, we cannot add more files to the MPQ
    assert(ha->dwFileTableSize == ha->dwMaxFileCount);
    return NULL;
}


TFileEntry * AllocateFileEntry(TMPQArchive * ha, const char * szFileName, LCID lcLocale)
{
    TFileEntry * pFileEntry = NULL;
    TMPQHash * pHash;
    DWORD dwHashIndex;
    DWORD dwFileIndex;
    bool bHashEntryExists = false;
    bool bHetEntryExists = false;

    // If the archive has classic hash table, we try to
    // find the file in the hash table
    if(ha->pHashTable != NULL)
    {
        // If the hash entry is already there, we reuse the file entry
        pHash = GetHashEntryExact(ha, szFileName, lcLocale);
        if(pHash != NULL)
        {
            pFileEntry = ha->pFileTable + pHash->dwBlockIndex;
            bHashEntryExists = true;
        }
    }

    // If the archive has HET table, try to use it for
    // finding the file
    if(ha->pHetTable != NULL)
    {
        dwFileIndex = GetFileIndex_Het(ha, szFileName);
        if(dwFileIndex != HASH_ENTRY_FREE)
        {
            pFileEntry = ha->pFileTable + dwFileIndex;
            bHetEntryExists = true;
        }
    }

    // If still haven't found the file entry, we allocate new one
    if(pFileEntry == NULL)
    {
        pFileEntry = FindFreeFileEntry(ha);
        if(pFileEntry == NULL)
            return NULL;
    }

    // Fill the rest of the file entry
    pFileEntry->ByteOffset = 0;
    pFileEntry->FileTime   = 0;
    pFileEntry->dwFileSize = 0;
    pFileEntry->dwCmpSize  = 0;
    pFileEntry->dwFlags    = 0;
    pFileEntry->lcLocale   = 0;
    pFileEntry->wPlatform  = 0;
    pFileEntry->dwCrc32    = 0;
    memset(pFileEntry->md5, 0, MD5_DIGEST_SIZE);

    // Allocate space for file name, if it's not there yet
    AllocateFileName(pFileEntry, szFileName);

    // If the free file entry is at the end of the file table,
    // we have to increment file table size
    if(pFileEntry == ha->pFileTable + ha->dwFileTableSize)
    {
        assert(ha->dwFileTableSize < ha->dwMaxFileCount);
        ha->pHeader->dwBlockTableSize++;
        ha->dwFileTableSize++;
    }

    // If the MPQ has hash table, we have to insert the new entry into the hash table
    if(ha->pHashTable != NULL && bHashEntryExists == false)
    {
        dwHashIndex = AllocateHashEntry(ha, pFileEntry);
        assert(dwHashIndex != HASH_ENTRY_FREE);
    }

    // If the MPQ has HET table, we have to insert it to the HET table as well
    if(ha->pHetTable != NULL && bHetEntryExists == false)
    {
        // TODO: Does HET table even support locales?
        // Most probably, Blizzard gave up that silly idea long ago.
        dwHashIndex = AllocateHetEntry(ha, pFileEntry);
        assert(dwHashIndex != HASH_ENTRY_FREE);
    }

    // Return the file entry
    return pFileEntry;
}

int RenameFileEntry(
    TMPQArchive * ha,
    TFileEntry * pFileEntry,
    const char * szNewFileName)
{
    TMPQHash * pHash;
    DWORD dwFileIndex;
    int nError = ERROR_SUCCESS;

    // If the MPQ has classic hash table, clear the entry there
    if(ha->pHashTable != NULL)
    {
        assert(pFileEntry->dwHashIndex < ha->pHeader->dwHashTableSize);

        pHash = ha->pHashTable + pFileEntry->dwHashIndex;
        memset(pHash, 0xFF, sizeof(TMPQHash));
        pHash->dwBlockIndex = HASH_ENTRY_DELETED;
    }

    // If the MPQ has HET table, clear the entry there as well
    if(ha->pHetTable != NULL)
    {
        TMPQHetTable * pHetTable = ha->pHetTable;
        DWORD dwInvalidFileIndex = (1 << pHetTable->dwIndexSizeTotal) - 1;

        assert(pFileEntry->dwHetIndex < pHetTable->dwHashTableSize);

        // Clear the entry in the HET hash array
        pHetTable->pHetHashes[pFileEntry->dwHetIndex] = HET_ENTRY_DELETED;

        // Set the BET index to invalid index
        pHetTable->pBetIndexes->SetBits(pHetTable->dwIndexSizeTotal * pFileEntry->dwHetIndex,
                                        pHetTable->dwIndexSize,
                                       &dwInvalidFileIndex,
                                        4);
    }

    // Free the old file name
    if(pFileEntry->szFileName != NULL)
        STORM_FREE(pFileEntry->szFileName);
    pFileEntry->szFileName = NULL;

    // Allocate new file name
    AllocateFileName(pFileEntry, szNewFileName);

    // Now find a hash entry for the new file name
    if(ha->pHashTable != NULL)
    {
        // Try to find the hash table entry for the new file name
        // Note: If this fails, we leave the MPQ in a corrupt state
        dwFileIndex = AllocateHashEntry(ha, pFileEntry);
        if(dwFileIndex == HASH_ENTRY_FREE)
            nError = ERROR_FILE_CORRUPT;
    }

    // If the archive has HET table, we have to allocate HET table for the file as well
    // finding the file
    if(ha->pHetTable != NULL)
    {
        dwFileIndex = AllocateHetEntry(ha, pFileEntry);
        if(dwFileIndex == HASH_ENTRY_FREE)
            nError = ERROR_FILE_CORRUPT;
    }

    // Invalidate the entries for (listfile) and (attributes)
    // After we are done with MPQ changes, we need to re-create them
    InvalidateInternalFiles(ha);
    return nError;
}

void ClearFileEntry(
    TMPQArchive * ha,
    TFileEntry * pFileEntry)
{
    TMPQHash * pHash = NULL;

    // If the MPQ has classic hash table, clear the entry there
    if(ha->pHashTable != NULL)
    {
        assert(pFileEntry->dwHashIndex < ha->pHeader->dwHashTableSize);

        pHash = ha->pHashTable + pFileEntry->dwHashIndex;
        memset(pHash, 0xFF, sizeof(TMPQHash));
        pHash->dwBlockIndex = HASH_ENTRY_DELETED;
    }

    // If the MPQ has HET table, clear the entry there as well
    if(ha->pHetTable != NULL)
    {
        TMPQHetTable * pHetTable = ha->pHetTable;
        DWORD dwInvalidFileIndex = (1 << pHetTable->dwIndexSizeTotal) - 1;

        assert(pFileEntry->dwHetIndex < pHetTable->dwHashTableSize);

        // Clear the entry in the HET hash array
        pHetTable->pHetHashes[pFileEntry->dwHetIndex] = HET_ENTRY_DELETED;

        // Set the BET index to invalid index
        pHetTable->pBetIndexes->SetBits(pHetTable->dwIndexSizeTotal * pFileEntry->dwHetIndex,
                                        pHetTable->dwIndexSize,
                                       &dwInvalidFileIndex,
                                        4);
    }

    // Free the file name, and set the file entry as deleted
    if(pFileEntry->szFileName != NULL)
        STORM_FREE(pFileEntry->szFileName);

    // Invalidate the file entry
    memset(pFileEntry, 0, sizeof(TFileEntry));
}

int FreeFileEntry(
    TMPQArchive * ha,
    TFileEntry * pFileEntry)
{
    TFileEntry * pFileTableEnd = ha->pFileTable + ha->dwFileTableSize;
    TFileEntry * pTempEntry;
    int nError = ERROR_SUCCESS;

    //
    // If we have HET table, we cannot just get rid of the file
    // Doing so would lead to empty gaps in the HET table
    // We have to keep BET hash, hash index, HET index, locale, platform and file name
    //

    if(ha->pHetTable == NULL)
    {
        TFileEntry * pLastFileEntry = ha->pFileTable + ha->dwFileTableSize - 1;
        TFileEntry * pLastUsedEntry = pLastFileEntry;

        // Zero the file entry
        ClearFileEntry(ha, pFileEntry);

        // Now there is a chance that we created a chunk of free
        // file entries at the end of the file table. We check this
        // and eventually free all deleted file entries at the end
        for(pTempEntry = ha->pFileTable; pTempEntry < pFileTableEnd; pTempEntry++)
        {
            // Is that an occupied file entry?
            if(pTempEntry->dwFlags & MPQ_FILE_EXISTS)
                pLastUsedEntry = pTempEntry;
        }

        // Can we free some entries at the end?                 
        if(pLastUsedEntry < pLastFileEntry)
        {
            // Fix the size of the file table entry
            ha->dwFileTableSize = (DWORD)(pLastUsedEntry - ha->pFileTable) + 1;
            ha->pHeader->dwBlockTableSize = ha->dwFileTableSize;
        }
    }
    else
    {
        // Note: Deleted entries in Blizzard MPQs version 4.0
        // normally contain valid byte offset and length
        pFileEntry->dwFlags &= ~MPQ_FILE_EXISTS;
        nError = ERROR_SUCCESS;
    }

    return nError;
}

void InvalidateInternalFiles(TMPQArchive * ha)
{
    TFileEntry * pFileEntry;

    // Invalidate the (listfile), if not done yet
    if(!(ha->dwFlags & MPQ_FLAG_INV_LISTFILE))
    {
        pFileEntry = GetFileEntryExact(ha, LISTFILE_NAME, LANG_NEUTRAL);
        if(pFileEntry != NULL)
            FreeFileEntry(ha, pFileEntry);
        ha->dwFlags |= MPQ_FLAG_INV_LISTFILE;
    }

    // Invalidate the (attributes), if not done yet
    if(!(ha->dwFlags & MPQ_FLAG_INV_ATTRIBUTES))
    {
        pFileEntry = GetFileEntryExact(ha, ATTRIBUTES_NAME, LANG_NEUTRAL);
        if(pFileEntry != NULL)
            FreeFileEntry(ha, pFileEntry);
        ha->dwFlags |= MPQ_FLAG_INV_ATTRIBUTES;
    }

    // Remember that the MPQ has been changed and it will be necessary
    // to update the tables
    ha->dwFlags |= MPQ_FLAG_CHANGED;
}

//-----------------------------------------------------------------------------
// Functions that loads and verify MPQ data bitmap

int LoadMpqDataBitmap(TMPQArchive * ha, ULONGLONG FileSize, bool * pbFileIsComplete)
{
    TMPQBitmap * pBitmap = NULL;
    TMPQBitmap DataBitmap;
    ULONGLONG BitmapOffset;
    ULONGLONG EndOfMpq;
    DWORD DataBlockCount = 0;
    DWORD BitmapByteSize;
    DWORD WholeByteCount;
    DWORD ExtraBitsCount;

    // Is there enough space for a MPQ bitmap?
    EndOfMpq = ha->MpqPos + ha->pHeader->ArchiveSize64;
    FileSize = FileSize - sizeof(TMPQBitmap);
    if(FileSize > EndOfMpq)
    {
        // Try to load the data bitmap from the end of the file
        if(FileStream_Read(ha->pStream, &FileSize, &DataBitmap, sizeof(TMPQBitmap)))
        {
            // Is it a valid data bitmap?
            BSWAP_ARRAY32_UNSIGNED((LPDWORD)(&DataBitmap), sizeof(TMPQBitmap));
            if(DataBitmap.dwSignature == MPQ_DATA_BITMAP_SIGNATURE)
            {
                // We assume that MPQs with data bitmap begin at position 0
                assert(ha->MpqPos == 0);

                // Calculate the number of extra bytes for data bitmap
                DataBlockCount = (DWORD)(((ha->pHeader->ArchiveSize64 - 1) / DataBitmap.dwBlockSize) + 1);
                BitmapByteSize = ((DataBlockCount - 1) / 8) + 1;

                // Verify the data block size
                BitmapOffset = ((ULONGLONG)DataBitmap.dwMapOffsetHi << 32) | DataBitmap.dwMapOffsetLo;
                assert((DWORD)(FileSize - BitmapOffset) == BitmapByteSize);

                // Allocate space for the data bitmap
                pBitmap = (TMPQBitmap *)STORM_ALLOC(BYTE, sizeof(TMPQBitmap) + BitmapByteSize);
                if(pBitmap != NULL)
                {
                    // Copy the bitmap header
                    memcpy(pBitmap, &DataBitmap, sizeof(TMPQBitmap));

                    // Read the remaining part
                    if(!FileStream_Read(ha->pStream, &BitmapOffset, (pBitmap + 1), BitmapByteSize))
                    {
                        STORM_FREE(pBitmap);
                        pBitmap = NULL;
                    }
                }
            }
        }
    }

    // If the caller asks for file completeness, check it
    if(pBitmap != NULL && pbFileIsComplete != NULL)
    {
        LPBYTE pbBitmap = (LPBYTE)(pBitmap + 1);
        DWORD i;
        bool bFileIsComplete = true;

        // Calculate the number of whole bytes and extra bits of the bitmap
        WholeByteCount = (DataBlockCount / 8);
        ExtraBitsCount = (DataBlockCount & 7);

        // Verify the whole bytes - their value must be 0xFF
        for(i = 0; i < WholeByteCount; i++)
        {
            if(pbBitmap[i] != 0xFF)
                bFileIsComplete = false;
        }

        // If there are extra bits, calculate the mask
        if(ExtraBitsCount != 0)
        {
            BYTE ExpectedValue = (BYTE)((1 << ExtraBitsCount) - 1);
            
            if(pbBitmap[i] != ExpectedValue)
                bFileIsComplete = false;
        }

        // Give the result to the caller
        *pbFileIsComplete = bFileIsComplete;
    }

    ha->pBitmap = pBitmap;
    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Support for file tables - hash table, block table, hi-block table

int CreateHashTable(TMPQArchive * ha, DWORD dwHashTableSize)
{
    TMPQHash * pHashTable;

    // Sanity checks
    assert((dwHashTableSize & (dwHashTableSize - 1)) == 0);
    assert(ha->pHashTable == NULL);

    // Create the hash table
    pHashTable = STORM_ALLOC(TMPQHash, dwHashTableSize);
    if(pHashTable == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill it
    memset(pHashTable, 0xFF, dwHashTableSize * sizeof(TMPQHash));
    ha->pHashTable = pHashTable;

    // Set the max file count, if needed
    if(ha->pHetTable == NULL)
        ha->dwMaxFileCount = dwHashTableSize;
    return ERROR_SUCCESS;
}

TMPQHash * LoadHashTable(TMPQArchive * ha)
{
    TMPQHeader * pHeader = ha->pHeader;
    ULONGLONG ByteOffset;
    TMPQHash * pHashTable;
    DWORD dwTableSize;
    DWORD dwCmpSize;
    int nError;

    // If the MPQ has no hash table, do nothing
    if(pHeader->dwHashTablePos == 0 && pHeader->wHashTablePosHi == 0)
        return NULL;

    // If the hash table size is zero, do nothing
    if(pHeader->dwHashTableSize == 0)
        return NULL;

    // Allocate buffer for the hash table
    dwTableSize = pHeader->dwHashTableSize * sizeof(TMPQHash);
    pHashTable = STORM_ALLOC(TMPQHash, pHeader->dwHashTableSize);
    if(pHashTable == NULL)
        return NULL;

    // Compressed size of the hash table
    dwCmpSize = (DWORD)pHeader->HashTableSize64;

    // 
    // Load the table from the MPQ, with decompression
    //
    // Note: We will NOT check if the hash table is properly decrypted.
    // Some MPQ protectors corrupt the hash table by rewriting part of it.
    // Hash table, the way how it works, allows arbitrary values for unused entries.
    // 

    ByteOffset = ha->MpqPos + MAKE_OFFSET64(pHeader->wHashTablePosHi, pHeader->dwHashTablePos);
    nError = LoadMpqTable(ha, ByteOffset, pHashTable, dwCmpSize, dwTableSize, MPQ_KEY_HASH_TABLE);
    if(nError != ERROR_SUCCESS)
    {
        STORM_FREE(pHashTable);
        pHashTable = NULL;
    }

    // Return the hash table
    return pHashTable;
}

static void FixBlockTableSize(
    TMPQArchive * ha,
    TMPQBlock * pBlockTable,
    DWORD dwClaimedSize)
{
    TMPQHeader * pHeader = ha->pHeader;
    ULONGLONG BlockTableStart;
    ULONGLONG BlockTableEnd;
    ULONGLONG FileDataStart;

    // Only perform this check on MPQs version 1.0
    if(pHeader->dwHeaderSize == MPQ_HEADER_SIZE_V1)
    {
        // Calculate claimed block table begin and end
        BlockTableStart = ha->MpqPos + MAKE_OFFSET64(pHeader->wBlockTablePosHi, pHeader->dwBlockTablePos);
        BlockTableEnd = BlockTableStart + (pHeader->dwBlockTableSize * sizeof(TMPQBlock));

        for(DWORD i = 0; i < dwClaimedSize; i++)
        {
            // If the block table end goes into that file, fix the block table end
            FileDataStart = ha->MpqPos + pBlockTable[i].dwFilePos;
            if(BlockTableStart < FileDataStart && BlockTableEnd > FileDataStart)
            {
                dwClaimedSize = (DWORD)((FileDataStart - BlockTableStart) / sizeof(TMPQBlock));
                BlockTableEnd = FileDataStart;
            }
        }
    }

    // Fix the block table size
    pHeader->BlockTableSize64 = dwClaimedSize * sizeof(TMPQBlock);
    pHeader->dwBlockTableSize = dwClaimedSize;
}

TMPQBlock * LoadBlockTable(TMPQArchive * ha, ULONGLONG FileSize)
{
    TMPQHeader * pHeader = ha->pHeader;
    TMPQBlock * pBlockTable;
    ULONGLONG ByteOffset;
    DWORD dwTableSize;
    DWORD dwCmpSize;
    int nError;

    // Do nothing if the block table position is zero
    if(pHeader->dwBlockTablePos == 0 && pHeader->wBlockTablePosHi == 0)
        return NULL;

    // Do nothing if the block table size is zero
    if(pHeader->dwBlockTableSize == 0)
        return NULL;

    // Sanity check, enforced by LoadAnyHashTable
    assert(ha->dwMaxFileCount >= pHeader->dwBlockTableSize);

    // Calculate sizes of both tables
    ByteOffset = ha->MpqPos + MAKE_OFFSET64(pHeader->wBlockTablePosHi, pHeader->dwBlockTablePos);
    dwTableSize = pHeader->dwBlockTableSize * sizeof(TMPQBlock);
    dwCmpSize = (DWORD)pHeader->BlockTableSize64;

    // Allocate space for the block table
    // Note: pHeader->dwBlockTableSize can be zero !!!
    pBlockTable = STORM_ALLOC(TMPQBlock, ha->dwMaxFileCount);
    if(pBlockTable == NULL)
        return NULL;

    // Fill the block table with zeros
    memset(pBlockTable, 0, dwTableSize);

    // I found a MPQ which claimed 0x200 entries in the block table,
    // but the file was cut and there was only 0x1A0 entries.
    // We will handle this case properly.
    if(dwTableSize == dwCmpSize && (ByteOffset + dwTableSize) > FileSize)
    {
        pHeader->dwBlockTableSize = (DWORD)((FileSize - ByteOffset) / sizeof(TMPQBlock));
        pHeader->BlockTableSize64 = pHeader->dwBlockTableSize * sizeof(TMPQBlock);
        dwTableSize = dwCmpSize = pHeader->dwBlockTableSize * sizeof(TMPQBlock);
    }

    //
    // One of the first cracked versions of Diablo I had block table unencrypted 
    // StormLib does NOT support such MPQs anymore, as they are incompatible
    // with compressed block table feature
    //

    // Load the block table
    nError = LoadMpqTable(ha, ByteOffset, pBlockTable, dwCmpSize, dwTableSize, MPQ_KEY_BLOCK_TABLE);
    if(nError != ERROR_SUCCESS)
    {
        // Failed, sorry
        STORM_FREE(pBlockTable);
        return NULL;
    }

    // Defense against MPQs that claim block table to be bigger than it really is
    FixBlockTableSize(ha, pBlockTable, pHeader->dwBlockTableSize);
    return pBlockTable;
}

int LoadHetTable(TMPQArchive * ha)
{
    TMPQExtTable * pExtTable;
    TMPQHeader * pHeader = ha->pHeader;
    int nError = ERROR_SUCCESS;

    // If the HET table position is not NULL, we expect
    // both HET and BET tables to be present.
    if(pHeader->HetTablePos64 != 0)
    {
        // Attempt to load the HET table (Hash Extended Table)
        pExtTable = LoadExtTable(ha, pHeader->HetTablePos64, (size_t)pHeader->HetTableSize64, HET_TABLE_SIGNATURE, MPQ_KEY_HASH_TABLE);
        if(pExtTable != NULL)
        {
            // If succeeded, we have to limit the maximum file count
            // to the values saved in the HET table
            // If loading HET table fails, we ignore the result.
            ha->pHetTable = TranslateHetTable(pExtTable);
            if(ha->pHetTable != NULL)
                ha->dwMaxFileCount = ha->pHetTable->dwMaxFileCount;

            STORM_FREE(pExtTable);
        }

        // If the HET hable failed to load, it's corrupt.
        if(ha->pHetTable == NULL)
            nError = ERROR_FILE_CORRUPT;
    }

    return nError;
}

TMPQBetTable * LoadBetTable(TMPQArchive * ha)
{
    TMPQExtTable * pExtTable;
    TMPQBetTable * pBetTable = NULL;
    TMPQHeader * pHeader = ha->pHeader;

    // If the HET table position is not NULL, we expect
    // both HET and BET tables to be present.
    if(pHeader->BetTablePos64 != 0)
    {
        // Attempt to load the HET table (Hash Extended Table)
        pExtTable = LoadExtTable(ha, pHeader->BetTablePos64, (size_t)pHeader->BetTableSize64, BET_TABLE_SIGNATURE, MPQ_KEY_BLOCK_TABLE);
        if(pExtTable != NULL)
        {
            // If succeeded, we translate the BET table
            // to more readable form
            pBetTable = TranslateBetTable(ha, pExtTable);
            STORM_FREE(pExtTable);
        }
    }

    return pBetTable;
}

int LoadAnyHashTable(TMPQArchive * ha)
{
    TMPQHeader * pHeader = ha->pHeader;

    // If the MPQ archive is empty, don't bother trying to load anything
    if(pHeader->dwHashTableSize == 0 && pHeader->HetTableSize64 == 0)
        return CreateHashTable(ha, HASH_TABLE_SIZE_DEFAULT);

    // Try to load HET and/or classic hash table
    LoadHetTable(ha);

    // Load the HASH table
    ha->pHashTable = LoadHashTable(ha);

    // Set the maximum file count to the size of the hash table
    // In case there is HET table, we have to keep the file limit
    if(ha->pHetTable == NULL)
        ha->dwMaxFileCount = pHeader->dwHashTableSize;

    // Did at least one succeed?
    if(ha->pHetTable == NULL && ha->pHashTable == NULL)
        return ERROR_FILE_CORRUPT;

    // In theory, a MPQ could have bigger block table than hash table
    if(ha->pHeader->dwBlockTableSize > ha->dwMaxFileCount)
    {
        ha->dwMaxFileCount = ha->pHeader->dwBlockTableSize;
        ha->dwFlags |= MPQ_FLAG_READ_ONLY;
    }
        
    return ERROR_SUCCESS;
}

int BuildFileTable_Classic(
    TMPQArchive * ha,
    TFileEntry * pFileTable,
    ULONGLONG FileSize)
{
    TFileEntry * pFileEntry;
    TMPQHeader * pHeader = ha->pHeader;
    TMPQBlock * pBlockTable;
    TMPQBlock * pBlock;
    int nError = ERROR_SUCCESS;

    // Sanity checks
    assert(ha->pHashTable != NULL);

    // Load the block table
    pBlockTable = LoadBlockTable(ha, FileSize);
    if(pBlockTable != NULL)
    {
        TMPQHash * pHashEnd = ha->pHashTable + pHeader->dwHashTableSize;
        TMPQHash * pHash;

        // If we don't have HET table, we build the file entries from the hash&block tables
        if(ha->pHetTable == NULL)
        {
            for(pHash = ha->pHashTable; pHash < pHashEnd; pHash++)
            {
                if(pHash->dwBlockIndex < pHeader->dwBlockTableSize)
                {
                    pFileEntry = pFileTable + pHash->dwBlockIndex;
                    pBlock = pBlockTable + pHash->dwBlockIndex;

                    //
                    // Yet another silly map protector: For each valid file,
                    // there are 4 items in the hash table, that appears to be valid:
                    //
                    //   a6d79af0 e61a0932 001e0000 0000770b <== Fake valid
                    //   a6d79af0 e61a0932 0000d761 0000dacb <== Fake valid
                    //   a6d79af0 e61a0932 00000000 0000002f <== Real file entry
                    //   a6d79af0 e61a0932 00005a4f 000093bc <== Fake valid
                    // 

                    if(!(pBlock->dwFlags & ~MPQ_FILE_VALID_FLAGS) && (pBlock->dwFlags & MPQ_FILE_EXISTS))
                    {
                        // Fill the entry
                        pFileEntry->ByteOffset  = pBlock->dwFilePos;
                        pFileEntry->dwHashIndex = (DWORD)(pHash - ha->pHashTable);
                        pFileEntry->dwFileSize  = pBlock->dwFSize;
                        pFileEntry->dwCmpSize   = pBlock->dwCSize;
                        pFileEntry->dwFlags     = pBlock->dwFlags;
                        pFileEntry->lcLocale    = pHash->lcLocale;
                        pFileEntry->wPlatform   = pHash->wPlatform;
                    }
                    else
                    {
                        // If the hash table entry doesn't point to the valid file item,
                        // we invalidate the entire hash table entry
                        pHash->dwName1      = 0xFFFFFFFF;
                        pHash->dwName2      = 0xFFFFFFFF;
                        pHash->lcLocale     = 0xFFFF;
                        pHash->wPlatform    = 0xFFFF;
                        pHash->dwBlockIndex = HASH_ENTRY_DELETED;
                    }
                }
            }
        }
        else
        {
            for(pHash = ha->pHashTable; pHash < pHashEnd; pHash++)
            {
                if(pHash->dwBlockIndex < ha->dwFileTableSize)
                {
                    pFileEntry = pFileTable + pHash->dwBlockIndex;
                    if(pFileEntry->dwFlags & MPQ_FILE_EXISTS)
                    {
                        pFileEntry->dwHashIndex = (DWORD)(pHash - ha->pHashTable);
                        pFileEntry->lcLocale    = pHash->lcLocale;
                        pFileEntry->wPlatform   = pHash->wPlatform;
                    }
                }
            }
        }

        // Free the block table
        STORM_FREE(pBlockTable);
    }
    else
    {
        nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Load the hi-block table
    if(nError == ERROR_SUCCESS && pHeader->HiBlockTablePos64 != 0)
    {
        ULONGLONG ByteOffset;
        USHORT * pHiBlockTable = NULL;
        DWORD dwTableSize = pHeader->dwBlockTableSize * sizeof(USHORT);

        // Allocate space for the hi-block table
        // Note: pHeader->dwBlockTableSize can be zero !!!
        pHiBlockTable = STORM_ALLOC(USHORT, pHeader->dwBlockTableSize + 1);
        if(pHiBlockTable != NULL)
        {
            // Load the hi-block table. It is not encrypted, nor compressed
            ByteOffset = ha->MpqPos + pHeader->HiBlockTablePos64;
            if(!FileStream_Read(ha->pStream, &ByteOffset, pHiBlockTable, dwTableSize))
                nError = GetLastError();

            // Now merge the hi-block table to the file table
            if(nError == ERROR_SUCCESS)
            {
                pFileEntry = pFileTable;

                // Add the high file offset to the base file offset.
                // We also need to swap it during the process.
                for(DWORD i = 0; i < pHeader->dwBlockTableSize; i++)
                {
                    pFileEntry->ByteOffset |= ((ULONGLONG)BSWAP_INT16_UNSIGNED(pHiBlockTable[i]) << 32);
                    pFileEntry++;
                }
            }

            // Free the hi-block table
            STORM_FREE(pHiBlockTable);
        }
        else
        {
            nError = ERROR_NOT_ENOUGH_MEMORY;
        }
    }

    // Set the current size of the file table
    ha->dwFileTableSize = pHeader->dwBlockTableSize;
    return nError;
}

int BuildFileTable_HetBet(
    TMPQArchive * ha,
    TFileEntry * pFileTable)
{
    TMPQHetTable * pHetTable = ha->pHetTable;
    TMPQBetTable * pBetTable;
    TFileEntry * pFileEntry = pFileTable;
    TBitArray * pBitArray;
    DWORD dwBitPosition = 0;
    DWORD i;
    int nError = ERROR_FILE_CORRUPT;

    // Load the BET table from the MPQ
    pBetTable = LoadBetTable(ha);
    if(pBetTable != NULL)
    {
        // Step one: Fill the indexes to the HET table
        for(i = 0; i < pHetTable->dwHashTableSize; i++)
        {
            DWORD dwFileIndex = 0;

            // Is the entry in the HET table occupied?
            if(pHetTable->pHetHashes[i] != 0)
            {
                // Load the index to the BET table
                pHetTable->pBetIndexes->GetBits(pHetTable->dwIndexSizeTotal * i,
                                                pHetTable->dwIndexSize,
                                               &dwFileIndex,
                                                4);
                // Overflow test
                if(dwFileIndex < pBetTable->dwFileCount)
                {
                    // Get the file entry and save HET index
                    pFileEntry = pFileTable + dwFileIndex;
                    pFileEntry->dwHetIndex = i;

                    // Load the BET hash
                    pBetTable->pBetHashes->GetBits(pBetTable->dwBetHashSizeTotal * dwFileIndex,
                                                   pBetTable->dwBetHashSize,
                                                  &pFileEntry->BetHash,
                                                   8);
                }
            }
        }

        // Go through the entire BET table and convert it to the file table.
        pFileEntry = pFileTable;
        pBitArray = pBetTable->pFileTable; 
        for(i = 0; i < pBetTable->dwFileCount; i++)
        {
            DWORD dwFlagIndex = 0;

            // Read the file position
            pBitArray->GetBits(dwBitPosition + pBetTable->dwBitIndex_FilePos,
                               pBetTable->dwBitCount_FilePos,
                              &pFileEntry->ByteOffset,
                               8);

            // Read the file size
            pBitArray->GetBits(dwBitPosition + pBetTable->dwBitIndex_FileSize,
                               pBetTable->dwBitCount_FileSize,
                              &pFileEntry->dwFileSize,
                               4);

            // Read the compressed size
            pBitArray->GetBits(dwBitPosition + pBetTable->dwBitIndex_CmpSize,
                               pBetTable->dwBitCount_CmpSize,
                              &pFileEntry->dwCmpSize,
                               4);


            // Read the flag index
            if(pBetTable->dwFlagCount != 0)
            {
                pBitArray->GetBits(dwBitPosition + pBetTable->dwBitIndex_FlagIndex,
                                   pBetTable->dwBitCount_FlagIndex,
                                  &dwFlagIndex,
                                   4);

                pFileEntry->dwFlags = pBetTable->pFileFlags[dwFlagIndex];
            }

            //
            // TODO: Locale (?)
            //

            // Move the current bit position
            dwBitPosition += pBetTable->dwTableEntrySize;
            pFileEntry++;
        }

        // Set the current size of the file table
        ha->dwFileTableSize = pBetTable->dwFileCount;
        FreeBetTable(pBetTable);
        nError = ERROR_SUCCESS;
    }
    else
    {
        nError = ERROR_FILE_CORRUPT;
    }

    return nError;
}

int BuildFileTable(TMPQArchive * ha, ULONGLONG FileSize)
{
    TFileEntry * pFileTable;
    bool bFileTableCreated = false;

    // Sanity checks
    assert(ha->dwFileTableSize == 0);
    assert(ha->dwMaxFileCount != 0);

    // Allocate the file table with size determined before
    pFileTable = STORM_ALLOC(TFileEntry, ha->dwMaxFileCount);
    if(pFileTable == NULL)
        return ERROR_NOT_ENOUGH_MEMORY;

    // Fill the table with zeros
    memset(pFileTable, 0, ha->dwMaxFileCount * sizeof(TFileEntry));

    // If we have HET table, we load file table from the BET table
    // Note: If BET table is corrupt or missing, we set the archive as read only
    if(ha->pHetTable != NULL)
    {
        if(BuildFileTable_HetBet(ha, pFileTable) != ERROR_SUCCESS)
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;
        else
            bFileTableCreated = true;
    }

    // If we have hash table, we load the file table from the block table
    // Note: If block table is corrupt or missing, we set the archive as read only
    if(ha->pHashTable != NULL)
    {
        if(BuildFileTable_Classic(ha, pFileTable, FileSize) != ERROR_SUCCESS)
            ha->dwFlags |= MPQ_FLAG_READ_ONLY;
        else
            bFileTableCreated = true;
    }
    
    // If something failed, we free the file table entry
    if(bFileTableCreated == false)
    {
        STORM_FREE(pFileTable);
        return ERROR_FILE_CORRUPT;
    }

    // Assign it to the archive structure
    ha->pFileTable = pFileTable;
    return ERROR_SUCCESS;
}

// Saves MPQ header, hash table, block table and hi-block table.
int SaveMPQTables(TMPQArchive * ha)
{
    TMPQExtTable * pHetTable = NULL;
    TMPQExtTable * pBetTable = NULL;
    TMPQHeader * pHeader = ha->pHeader;
    TMPQBlock * pBlockTable = NULL;
    TMPQHash * pHashTable = NULL;
    ULONGLONG HetTableSize64 = 0;
    ULONGLONG BetTableSize64 = 0;
    ULONGLONG HashTableSize64 = 0;
    ULONGLONG BlockTableSize64 = 0;
    ULONGLONG HiBlockTableSize64 = 0;
    ULONGLONG TablePos = 0;             // A table position, relative to the begin of the MPQ
    USHORT * pHiBlockTable = NULL;
    DWORD cbTotalSize;
    bool bNeedHiBlockTable = false;
    int nError = ERROR_SUCCESS;

    // We expect this function to be called only when tables have been changed
    assert(ha->dwFlags & MPQ_FLAG_CHANGED);

    // Find the space where the MPQ tables will be saved 
    FindFreeMpqSpace(ha, &TablePos);

    // If the MPQ has HET table, we prepare a ready-to-save version
    if(nError == ERROR_SUCCESS && ha->pHetTable != NULL)
    {
        pHetTable = TranslateHetTable(ha->pHetTable, &HetTableSize64);
        if(pHetTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // If the MPQ has HET table, we also must create BET table to be saved
    if(nError == ERROR_SUCCESS && ha->pHetTable != NULL)
    {
        pBetTable = TranslateBetTable(ha, &BetTableSize64);
        if(pBetTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Now create hash table
    if(nError == ERROR_SUCCESS && ha->pHashTable != NULL)
    {
        pHashTable = TranslateHashTable(ha, &HashTableSize64);
        if(pHashTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Create block table
    if(nError == ERROR_SUCCESS && ha->pHashTable != NULL)
    {
        pBlockTable = TranslateBlockTable(ha, &BlockTableSize64, &bNeedHiBlockTable);
        if(pBlockTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Create hi-block table, if needed
    if(nError == ERROR_SUCCESS && bNeedHiBlockTable)
    {
        pHiBlockTable = TranslateHiBlockTable(ha, &HiBlockTableSize64);
        if(pHiBlockTable == NULL)
            nError = ERROR_NOT_ENOUGH_MEMORY;
    }

    // Write the HET table, if any
    if(nError == ERROR_SUCCESS && pHetTable != NULL)
    {
        pHeader->HetTableSize64 = HetTableSize64;
        pHeader->HetTablePos64  = TablePos;
        nError = SaveExtTable(ha, pHetTable, TablePos, (DWORD)HetTableSize64, pHeader->MD5_HetTable, MPQ_KEY_HASH_TABLE, false, &cbTotalSize);
        TablePos += cbTotalSize;
    }

    // Write the BET table, if any
    if(nError == ERROR_SUCCESS && pBetTable != NULL)
    {
        pHeader->BetTableSize64 = BetTableSize64;
        pHeader->BetTablePos64  = TablePos;
        nError = SaveExtTable(ha, pBetTable, TablePos, (DWORD)BetTableSize64, pHeader->MD5_BetTable, MPQ_KEY_BLOCK_TABLE, false, &cbTotalSize);
        TablePos += cbTotalSize;
    }

    // Write the hash table, if we have any
    if(nError == ERROR_SUCCESS && pHashTable != NULL)
    {
        pHeader->HashTableSize64 = HashTableSize64;
        pHeader->wHashTablePosHi = (USHORT)(TablePos >> 32);
        pHeader->dwHashTableSize = (DWORD)(HashTableSize64 / sizeof(TMPQHash));
        pHeader->dwHashTablePos = (DWORD)TablePos;
        nError = SaveMpqTable(ha, pHashTable, TablePos, (size_t)HashTableSize64, pHeader->MD5_HashTable, MPQ_KEY_HASH_TABLE, false);
        TablePos += HashTableSize64;
    }

    // Write the block table, if we have any
    if(nError == ERROR_SUCCESS && pBlockTable != NULL)
    {
        pHeader->BlockTableSize64 = BlockTableSize64;
        pHeader->wBlockTablePosHi = (USHORT)(TablePos >> 32);
        pHeader->dwBlockTableSize = (DWORD)(BlockTableSize64 / sizeof(TMPQBlock));
        pHeader->dwBlockTablePos = (DWORD)TablePos;
        nError = SaveMpqTable(ha, pBlockTable, TablePos, (size_t)BlockTableSize64, pHeader->MD5_BlockTable, MPQ_KEY_BLOCK_TABLE, false);
        TablePos += BlockTableSize64;
    }

    // Write the hi-block table, if we have any
    if(nError == ERROR_SUCCESS && pHiBlockTable != NULL)
    {
        ULONGLONG ByteOffset = ha->MpqPos + TablePos;

        pHeader->HiBlockTableSize64 = HiBlockTableSize64;
        pHeader->HiBlockTablePos64 = TablePos;
        BSWAP_ARRAY16_UNSIGNED(pHiBlockTable, HiBlockTableSize64);
        
        if(!FileStream_Write(ha->pStream, &ByteOffset, pHiBlockTable, (DWORD)HiBlockTableSize64))
            nError = GetLastError();
        TablePos += HiBlockTableSize64;
    }

    // Cut the MPQ
    if(nError == ERROR_SUCCESS)
    {
        ULONGLONG FileSize = ha->MpqPos + TablePos;

        if(!FileStream_SetSize(ha->pStream, FileSize))
            nError = GetLastError();
    }

    // Write the MPQ header
    if(nError == ERROR_SUCCESS)
    {
        // Update the size of the archive
        pHeader->ArchiveSize64 = TablePos;
        pHeader->dwArchiveSize = (DWORD)TablePos;
        
        // Update the MD5 of the archive header
        CalculateDataBlockHash(pHeader, MPQ_HEADER_SIZE_V4 - MD5_DIGEST_SIZE, pHeader->MD5_MpqHeader);

        // Write the MPQ header to the file
        BSWAP_TMPQHEADER(pHeader);
        if(!FileStream_Write(ha->pStream, &ha->MpqPos, pHeader, pHeader->dwHeaderSize))
            nError = GetLastError();
        BSWAP_TMPQHEADER(pHeader);
    }

    // Clear the changed flag
    if(nError == ERROR_SUCCESS)
        ha->dwFlags &= ~MPQ_FLAG_CHANGED;

    // Cleanup and exit
    if(pHetTable != NULL)
        STORM_FREE(pHetTable);
    if(pBetTable != NULL)
        STORM_FREE(pBetTable);
    if(pHashTable != NULL)
        STORM_FREE(pHashTable);
    if(pBlockTable != NULL)
        STORM_FREE(pBlockTable);
    if(pHiBlockTable != NULL)
        STORM_FREE(pHiBlockTable);
    return nError;
}
