/*****************************************************************************/
/* SBaseDumpData.cpp                      Copyright (c) Ladislav Zezula 2011 */
/*---------------------------------------------------------------------------*/
/* Description :                                                             */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 26.01.11  1.00  Lad  The first version of SBaseDumpData.cpp               */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "StormCommon.h"

#ifdef __STORMLIB_DUMP_DATA__

void DumpMpqHeader(TMPQHeader * pHeader)
{
    printf("== MPQ Header =================================\n");
    printf("DWORD dwID                   = %08X\n",    pHeader->dwID);
    printf("DWORD dwHeaderSize           = %08X\n",    pHeader->dwHeaderSize);
    printf("DWORD dwArchiveSize          = %08X\n",    pHeader->dwArchiveSize);
    printf("USHORT wFormatVersion        = %04X\n",    pHeader->wFormatVersion);
    printf("USHORT wSectorSize           = %04X\n",    pHeader->wSectorSize);
    printf("DWORD dwHashTablePos         = %08X\n",    pHeader->dwHashTablePos);
    printf("DWORD dwBlockTablePos        = %08X\n",    pHeader->dwBlockTablePos);
    printf("DWORD dwHashTableSize        = %08X\n",    pHeader->dwHashTableSize);
    printf("DWORD dwBlockTableSize       = %08X\n",    pHeader->dwBlockTableSize);
    printf("ULONGLONG HiBlockTablePos64  = %016llX\n", pHeader->HiBlockTablePos64);
    printf("USHORT wHashTablePosHi       = %04X\n",    pHeader->wHashTablePosHi);
    printf("USHORT wBlockTablePosHi      = %04X\n",    pHeader->wBlockTablePosHi);
    printf("ULONGLONG ArchiveSize64      = %016llX\n", pHeader->ArchiveSize64);
    printf("ULONGLONG BetTablePos64      = %016llX\n", pHeader->BetTablePos64);
    printf("ULONGLONG HetTablePos64      = %016llX\n", pHeader->HetTablePos64);
    printf("ULONGLONG HashTableSize64    = %016llX\n", pHeader->HashTableSize64);
    printf("ULONGLONG BlockTableSize64   = %016llX\n", pHeader->BlockTableSize64);
    printf("ULONGLONG HiBlockTableSize64 = %016llX\n", pHeader->HiBlockTableSize64);
    printf("ULONGLONG HetTableSize64     = %016llX\n", pHeader->HetTableSize64);
    printf("ULONGLONG BetTableSize64     = %016llX\n", pHeader->BetTableSize64);
    printf("DWORD dwRawChunkSize         = %08X\n",     pHeader->dwRawChunkSize);
    printf("-----------------------------------------------\n\n");
}

void DumpHetAndBetTable(TMPQHetTable * pHetTable, TMPQBetTable * pBetTable)
{
    DWORD i;

    if(pHetTable == NULL || pBetTable == NULL)
        return;

    printf("== HET Header =================================\n");
    printf("ULONGLONG  AndMask64         = %016llX\n", pHetTable->AndMask64);       
    printf("ULONGLONG  OrMask64          = %016llX\n", pHetTable->OrMask64);        
    printf("DWORD      dwIndexSizeTotal  = %08X\n",     pHetTable->dwIndexSizeTotal);
    printf("DWORD      dwIndexSizeExtra  = %08X\n",     pHetTable->dwIndexSizeExtra);
    printf("DWORD      dwIndexSize       = %08X\n",     pHetTable->dwIndexSize);     
    printf("DWORD      dwMaxFileCount    = %08X\n",     pHetTable->dwMaxFileCount);  
    printf("DWORD      dwHashTableSize   = %08X\n",     pHetTable->dwHashTableSize); 
    printf("DWORD      dwHashBitSize     = %08X\n",     pHetTable->dwHashBitSize);   
    printf("-----------------------------------------------\n\n");

    printf("== BET Header =================================\n");
    printf("DWORD dwTableEntrySize       = %08X\n",     pBetTable->dwTableEntrySize);
    printf("DWORD dwBitIndex_FilePos     = %08X\n",     pBetTable->dwBitIndex_FilePos);
    printf("DWORD dwBitIndex_FileSize    = %08X\n",     pBetTable->dwBitIndex_FileSize);
    printf("DWORD dwBitIndex_CmpSize     = %08X\n",     pBetTable->dwBitIndex_CmpSize);
    printf("DWORD dwBitIndex_FlagIndex   = %08X\n",     pBetTable->dwBitIndex_FlagIndex);
    printf("DWORD dwBitIndex_Unknown     = %08X\n",     pBetTable->dwBitIndex_Unknown);
    printf("DWORD dwBitCount_FilePos     = %08X\n",     pBetTable->dwBitCount_FilePos);
    printf("DWORD dwBitCount_FileSize    = %08X\n",     pBetTable->dwBitCount_FileSize);
    printf("DWORD dwBitCount_CmpSize     = %08X\n",     pBetTable->dwBitCount_CmpSize);
    printf("DWORD dwBitCount_FlagIndex   = %08X\n",     pBetTable->dwBitCount_FlagIndex);   
    printf("DWORD dwBitCount_Unknown     = %08X\n",     pBetTable->dwBitCount_Unknown);
    printf("DWORD dwBetHashSizeTotal     = %08X\n",     pBetTable->dwBetHashSizeTotal);
    printf("DWORD dwBetHashSizeExtra     = %08X\n",     pBetTable->dwBetHashSizeExtra);
    printf("DWORD dwBetHashSize          = %08X\n",     pBetTable->dwBetHashSize);
    printf("DWORD dwMaxFileCount         = %08X\n",     pBetTable->dwMaxFileCount);
    printf("DWORD dwFlagCount            = %08X\n",     pBetTable->dwFlagCount);
    printf("-----------------------------------------------\n\n");

    printf("== HET & Bet Table ======================================================================\n\n");
    printf("HetIdx HetHash BetIdx BetHash          ByteOffset       FileSize CmpSize  FlgIdx Flags   \n");
    printf("------ ------- ------ ---------------- ---------------- -------- -------- ------ --------\n");
    for(i = 0; i < pHetTable->dwHashTableSize; i++)
    {
        ULONGLONG ByteOffset = 0;
        ULONGLONG BetHash = 0;
        DWORD dwFileSize = 0;
        DWORD dwCmpSize = 0;
        DWORD dwFlagIndex = 0;
        DWORD dwFlags = 0;
        DWORD dwBetIndex = 0;

        pHetTable->pBetIndexes->GetBits(i * pHetTable->dwIndexSizeTotal,
                                        pHetTable->dwIndexSize,
                                       &dwBetIndex,
                                        4);
        
        if(dwBetIndex < pHetTable->dwMaxFileCount)
        {
            DWORD dwEntryIndex = pBetTable->dwTableEntrySize * dwBetIndex;

            pBetTable->pBetHashes->GetBits(dwBetIndex * pBetTable->dwBetHashSizeTotal,
                                           pBetTable->dwBetHashSize,
                                          &BetHash,
                                           8);

            pBetTable->pFileTable->GetBits(dwEntryIndex + pBetTable->dwBitIndex_FilePos,
                                           pBetTable->dwBitCount_FilePos,
                                          &ByteOffset,
                                           8);

            pBetTable->pFileTable->GetBits(dwEntryIndex + pBetTable->dwBitIndex_FileSize,
                                           pBetTable->dwBitCount_FileSize,
                                          &dwFileSize,
                                           4);

            pBetTable->pFileTable->GetBits(dwEntryIndex + pBetTable->dwBitIndex_CmpSize,
                                           pBetTable->dwBitCount_CmpSize,
                                          &dwCmpSize,
                                           4);

            pBetTable->pFileTable->GetBits(dwEntryIndex + pBetTable->dwBitIndex_FlagIndex,
                                           pBetTable->dwBitCount_FlagIndex,
                                          &dwFlagIndex,
                                           4);

            dwFlags = pBetTable->pFileFlags[dwFlagIndex];
        }

        printf(" %04X    %02lX     %04X  %016llX %016llX %08X %08X  %04X  %08X\n", i,
                                                         pHetTable->pHetHashes[i],
                                                         dwBetIndex,
                                                         BetHash,
                                                         ByteOffset,
                                                         dwFileSize,
                                                         dwCmpSize,
                                                         dwFlagIndex,
                                                         dwFlags);
    }
    printf("-----------------------------------------------------------------------------------------\n");
}

#endif  // __STORMLIB_DUMP_DATA__
