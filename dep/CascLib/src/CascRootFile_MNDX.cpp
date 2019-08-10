/*****************************************************************************/
/* CascRootFile_MNDX.cpp                  Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/* Note: "HOTS" refers to Play.exe, v2.5.0.29049 (Heroes of the Storm Alpha) */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 18.05.14  1.00  Lad  The first version of CascRootFile_MNDX.cpp           */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local defines

#define MNDX_MAR_SIGNATURE 0x0052414d           // 'MAR\0'
#define MAR_PACKAGE_NAMES           0           // MAR with package names only
#define MAR_STRIPPED_NAMES          1           // MAR with names where packages were stripped
#define MAR_FULL_NAMES              2           // MAR with full file names
#define MAR_COUNT                   3           // Maximum of 3 MAR files are supported

#define MNDX_SEARCH_INITIALIZING    0
#define MNDX_SEARCH_SEARCHING       2
#define MNDX_SEARCH_FINISHED        4

#define MNDX_MAX_ENTRIES(type)  (0xFFFFFFFF / sizeof(type))

#define MNDX_INVALID_SIZE_T        ((size_t)(-1))

#define MNDX_LAST_CKEY_ENTRY       0x80000000

//-----------------------------------------------------------------------------
// Local structures

typedef union _SETBITS
{
    struct
    {
        DWORD Lower08 : 8;                          // Number of set bits in the lower 1 byte
        DWORD Lower16 : 8;                          // Number of set bits in the lower 2 bytes
        DWORD Lower24 : 8;                          // Number of set bits in the lower 3 bytes
        DWORD Lower32 : 8;                          // Number of set bits in the 32-bit integer
    } u;

    DWORD SetBitsAll;                               // The total set bits mask

} SETBITS, *PSETBITS;

typedef struct _HASH_ENTRY
{
    DWORD NodeIndex;                                // Index of the path node
    DWORD NextIndex;                                // ID of the first subnode in the hash table

    union
    {
        DWORD FragmentOffset;                       // Offset of the path fragment in the TPathFragmentTable
        DWORD ChildTableIndex;                      // Starting search index for the child database (if child database is present)
        char SingleChar;                            // If the upper 24 bits of the FragmentOffset is 0xFFFFFFFF, this single character
    };
                                                    // Otherwise --> Offset to the name fragment table
} HASH_ENTRY, *PHASH_ENTRY;

typedef struct _FILE_MNDX_HEADER
{
    DWORD Signature;                                // 'MNDX'
    DWORD HeaderVersion;                            // Must be <= 2
    DWORD FormatVersion;

} FILE_MNDX_HEADER, *PFILE_MNDX_HEADER;

typedef struct _MNDX_PACKAGE
{
    char * szFileName;                              // Pointer to file name
    size_t nLength;                                 // Length of the file name
    size_t nIndex;                                  // Package index

} MNDX_PACKAGE, *PMNDX_PACKAGE;

// Root file entry for CASC storages with MNDX root file (Heroes of the Storm)
// Corresponds to the in-file structure
typedef struct _MNDX_CKEY_ENTRY
{
    DWORD Flags;                                    // High 8 bits: Flags, low 24 bits: package index
    BYTE  CKey[MD5_HASH_SIZE];                      // Content key for the file
    DWORD ContentSize;                              // Uncompressed file size, in bytes

} MNDX_CKEY_ENTRY, *PMNDX_CKEY_ENTRY;

typedef struct _FILE_MAR_INFO
{
    DWORD MarIndex;
    DWORD MarDataSize;
    DWORD MarDataSizeHi;
    DWORD MarDataOffset;
    DWORD MarDataOffsetHi;
} FILE_MAR_INFO, *PFILE_MAR_INFO;

//-----------------------------------------------------------------------------
// Local variables

unsigned char table_1BA1818[0x800] =
{
    0x07, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x05, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x06, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x05, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x07, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x05, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x06, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x05, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00,
    0x07, 0x07, 0x07, 0x01, 0x07, 0x02, 0x02, 0x01, 0x07, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x05, 0x05, 0x01, 0x05, 0x02, 0x02, 0x01, 0x05, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x05, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x06, 0x06, 0x01, 0x06, 0x02, 0x02, 0x01, 0x06, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x06, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x06, 0x05, 0x05, 0x01, 0x05, 0x02, 0x02, 0x01, 0x05, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x05, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x07, 0x07, 0x01, 0x07, 0x02, 0x02, 0x01, 0x07, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x05, 0x05, 0x01, 0x05, 0x02, 0x02, 0x01, 0x05, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x05, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x06, 0x06, 0x01, 0x06, 0x02, 0x02, 0x01, 0x06, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x06, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x06, 0x05, 0x05, 0x01, 0x05, 0x02, 0x02, 0x01, 0x05, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x05, 0x04, 0x04, 0x01, 0x04, 0x02, 0x02, 0x01, 0x04, 0x03, 0x03, 0x01, 0x03, 0x02, 0x02, 0x01,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x07, 0x07, 0x07, 0x03, 0x07, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x04, 0x07, 0x04, 0x04, 0x02, 0x07, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x02, 0x07, 0x05, 0x05, 0x03, 0x05, 0x03, 0x03, 0x02,
    0x07, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x02, 0x05, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x02, 0x07, 0x06, 0x06, 0x03, 0x06, 0x03, 0x03, 0x02,
    0x07, 0x06, 0x06, 0x04, 0x06, 0x04, 0x04, 0x02, 0x06, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x02, 0x06, 0x05, 0x05, 0x03, 0x05, 0x03, 0x03, 0x02,
    0x06, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x02, 0x05, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x02, 0x07, 0x07, 0x07, 0x03, 0x07, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x04, 0x07, 0x04, 0x04, 0x02, 0x07, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x02, 0x07, 0x05, 0x05, 0x03, 0x05, 0x03, 0x03, 0x02,
    0x07, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x02, 0x05, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x02, 0x07, 0x06, 0x06, 0x03, 0x06, 0x03, 0x03, 0x02,
    0x07, 0x06, 0x06, 0x04, 0x06, 0x04, 0x04, 0x02, 0x06, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x02, 0x06, 0x05, 0x05, 0x03, 0x05, 0x03, 0x03, 0x02,
    0x06, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x02, 0x05, 0x04, 0x04, 0x03, 0x04, 0x03, 0x03, 0x02,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x04, 0x07, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x03,
    0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x04, 0x07, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x03,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x04, 0x07, 0x06, 0x06, 0x04, 0x06, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x03,
    0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x04, 0x06, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x04, 0x07, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x03,
    0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x04, 0x07, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x03,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x04, 0x07, 0x06, 0x06, 0x04, 0x06, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x03,
    0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x04, 0x06, 0x05, 0x05, 0x04, 0x05, 0x04, 0x04, 0x03,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05, 0x07, 0x07, 0x07, 0x05, 0x07, 0x05, 0x05, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05,
    0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x06, 0x06, 0x05, 0x06, 0x05, 0x05, 0x04,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x07, 0x06, 0x06, 0x05,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x06,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07
};

//-----------------------------------------------------------------------------
// Local functions - Number of set bits in an integer

// HOTS: inlined
static SETBITS GetNumberOfSetBits(DWORD Value32)
{
    SETBITS SetBits;

    Value32 = ((Value32 >> 1) & 0x55555555) + (Value32 & 0x55555555);
    Value32 = ((Value32 >> 2) & 0x33333333) + (Value32 & 0x33333333);
    Value32 = ((Value32 >> 4) & 0x0F0F0F0F) + (Value32 & 0x0F0F0F0F);
    SetBits.SetBitsAll = Value32 * 0x01010101;

    return SetBits;
}

static DWORD GetNumberOfSetBits32(DWORD Value32)
{
    return GetNumberOfSetBits(Value32).u.Lower32;
}

static LPBYTE CaptureData(LPBYTE pbRootPtr, LPBYTE pbRootEnd, void * pvBuffer, size_t cbLength)
{
    // Check whether there is enough data in the buffer
    if((pbRootPtr + cbLength) > pbRootEnd)
        return NULL;

    // Copy the data
    memcpy(pvBuffer, pbRootPtr, cbLength);
    return pbRootPtr + cbLength;
}

//-----------------------------------------------------------------------------
// The TPathStop structure

struct TPathStop
{
    TPathStop()
    {
        LoBitsIndex = 0;
        field_4 = 0;
        Count = 0;
        HiBitsIndex_PathFragment = CASC_INVALID_INDEX;
        field_10 = 0xFFFFFFFF;
    }

    TPathStop(DWORD arg_0, DWORD arg_4, DWORD arg_8)
    {
        LoBitsIndex = arg_0;
        field_4 = arg_4;
        Count = arg_8;
        HiBitsIndex_PathFragment = CASC_INVALID_INDEX;
        field_10 = 0xFFFFFFFF;
    }

    DWORD LoBitsIndex;
    DWORD field_4;
    DWORD Count;
    DWORD HiBitsIndex_PathFragment;
    DWORD field_10;
};

//-----------------------------------------------------------------------------
// Basic array implementations

class TByteStream
{
    public:

    // HOTS: 01959990
    TByteStream()
    {
        pbByteData = NULL;
        pvMappedFile = NULL;
        cbByteData = 0;
        field_C = 0;
        hFile = 0;
        hMap = 0;
    }

    // HOTS: 19599F0
    template <typename T>
    int GetBytes(size_t length, T ** Pointer)
    {
        // Is there enough bytes in the array?
        if(length > cbByteData)
            return ERROR_BAD_FORMAT;

        // Give the buffer to the caller
        Pointer[0] = (T *)(pbByteData);

        // Move pointers
        pbByteData += length;
        cbByteData -= length;
        return ERROR_SUCCESS;
    }

    int CopyBytes(void * value, size_t length)
    {
        // Is there enough bytes in the array?
        if(length > cbByteData)
            return ERROR_BAD_FORMAT;

        // Give the buffer to the caller
        memcpy(value, pbByteData, length);

        // Move pointers
        pbByteData += length;
        cbByteData -= length;
        return ERROR_SUCCESS;
    }

    // HOTS: 1959A60
    int SkipBytes(size_t cbByteCount)
    {
        LPBYTE Pointer;

        return GetBytes<BYTE>(cbByteCount, &Pointer);
    }

    // HOTS: 1959AF0
    int SetByteBuffer(LPBYTE pbNewByteData, size_t cbNewByteData)
    {
        if(pbNewByteData != NULL || cbNewByteData == 0)
        {
            pbByteData = pbNewByteData;
            cbByteData = cbNewByteData;
            return ERROR_SUCCESS;
        }

        return ERROR_INVALID_PARAMETER;
    }

    // HOTS: 1957160 <DWORD>
    template <typename T>
    DWORD GetValue(T & Value)
    {
        T * Pointer;
        DWORD dwErrCode;

        dwErrCode = GetBytes(sizeof(T), (LPBYTE *)(&Pointer));
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        Value = Pointer[0];
        return ERROR_SUCCESS;
    }

    // Retrieves the item count in the array
    template <typename T>
    DWORD GetArrayItemCount(DWORD & ArraySize, DWORD & ItemCount)
    {
        ULONGLONG ByteCount;
        DWORD dwErrCode;

        // The first 8 bytes is the byte size of the array
        dwErrCode = GetValue<ULONGLONG>(ByteCount);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Extract the number of bytes
        if(ByteCount > 0xFFFFFFFF || (ByteCount % sizeof(T)) != 0)
            return ERROR_BAD_FORMAT;

        // Give the result to the caller
        ItemCount = (DWORD)(ByteCount / sizeof(T));
        ArraySize = (DWORD)(ByteCount);
        return ERROR_SUCCESS;
    }

    // HOTS: 1957190: <DWORD>
    // HOTS: 19571E0: <BASEVALS>
    // HOTS: 1957230: <BYTE>
    // HOTS: 1957280: <HASH_ENTRY>
    template <typename T>
    DWORD GetArray(T ** Pointer, size_t ItemCount)
    {
        DWORD dwErrCode = ERROR_SUCCESS;

        // Verify parameters
        if(Pointer == NULL && ItemCount != 0)
            return ERROR_INVALID_PARAMETER;
        if(ItemCount > MNDX_MAX_ENTRIES(T))
            return ERROR_NOT_ENOUGH_MEMORY;

        // Allocate bytes for the array
        if (Pointer != NULL)
        {
            Pointer[0] = CASC_ALLOC<T>(ItemCount);
            if (Pointer[0] == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;

            // Get the pointer to the array
            dwErrCode = CopyBytes(Pointer[0], sizeof(T) * ItemCount);
        }

        return dwErrCode;
    }

    LPBYTE pbByteData;
    void * pvMappedFile;
    size_t cbByteData;
    DWORD field_C;
    HANDLE hFile;
    HANDLE hMap;
};

//-----------------------------------------------------------------------------
// TGenericArray interface/implementation

template <typename T>
class TGenericArray
{
    public:

    TGenericArray()
    {
        ItemArray = NULL;
        ItemCount = 0;
        MaxItemCount = 0;
        bIsValidArray = false;
    }

    ~TGenericArray()
    {
        CASC_FREE(ItemArray);
    }

    T & operator[] (size_t index)
    {
        assert(index < ItemCount);
        return ItemArray[index];
    }

    // HOTS: 1957090 (SetDwordsValid)
    // HOTS: 19570B0 (SetBaseValsValid)
    // HOTS: 19570D0 (? SetBitsValid ?)
    // HOTS: 19570F0 (SetPathFragmentsValid)
    int SetArrayValid()
    {
        if(bIsValidArray != 0)
            return ERROR_ALREADY_EXISTS;

        bIsValidArray = true;
        return ERROR_SUCCESS;
    }

    // HOTS: 19575A0 (char)
    // HOTS: 1957600 (TPathStop)
    void SetMaxItems(DWORD NewMaxItemCount)
    {
        T * OldArray = ItemArray;
        T * NewArray;

        // Allocate new data buffer
        NewArray = CASC_ALLOC<T>(NewMaxItemCount);
        if(NewArray != NULL)
        {
            // Copy the old items to the buffer
            for(size_t i = 0; i < ItemCount; i++)
            {
                NewArray[i] = ItemArray[i];
            }
        }

        ItemArray = NewArray;
        MaxItemCount = NewMaxItemCount;
        CASC_FREE(OldArray);
    }

    // HOTS: 19575A0 (char)
    // HOTS: 1957600 (TPathStop)
    void SetMaxItemsIf(DWORD NewMaxItemCount)
    {
        if(NewMaxItemCount > MaxItemCount)
        {
            if(MaxItemCount > (NewMaxItemCount / 2))
            {
                if(MaxItemCount <= (MNDX_MAX_ENTRIES(T) / 2))
                    NewMaxItemCount = MaxItemCount + MaxItemCount;
                else
                    NewMaxItemCount = MNDX_MAX_ENTRIES(T);
            }

            SetMaxItems(NewMaxItemCount);
        }
    }

    // HOTS: inline  <char>
    // HOTS: 1958330 <TPathStop>
    void Insert(T NewItem)
    {
        // Make sure we have enough capacity for the new item
        SetMaxItemsIf(ItemCount + 1);

        // Put the character to the slot that has been reserved
        ItemArray[ItemCount++] = NewItem;
    }

    // HOTS: 19583A0 <TPathStop>
    void GrowArray(DWORD NewItemCount)
    {
        DWORD OldMaxItemCount = MaxItemCount;

        // Make sure we have enough capacity for new items
        SetMaxItemsIf(NewItemCount);

        // Initialize the newly inserted items
        for(DWORD i = OldMaxItemCount; i < NewItemCount; i++)
        {
            ItemArray[i] = T();
        }

        ItemCount = NewItemCount;
    }

    // HOTS: 1957440 <DWORD>
    // HOTS: 19574E0 <BASEVALS>
    // HOTS: 1957690 <BYTE>
    // HOTS: 1957700 <HASH_ENTRY>
    // HOTS: 195A220 <char>
    // HOTS: 1958580 <TBitStream, DWORD>
    DWORD LoadFromStream(TByteStream & InStream)
    {
        DWORD NumberOfBytes;
        DWORD dwErrCode;

        // Get and verify the number of items
        dwErrCode = InStream.GetArrayItemCount<T>(NumberOfBytes, ItemCount);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Get the pointer to the array
        dwErrCode = InStream.GetArray<T>(&ItemArray, ItemCount);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = InStream.SkipBytes((0 - (DWORD)NumberOfBytes) & 0x07);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        return SetArrayValid();
    }

    T * ItemArray;
    DWORD ItemCount;                           // Number of items in the array
    DWORD MaxItemCount;                        // Capacity of the array
    bool bIsValidArray;
};

class TBitEntryArray : public TGenericArray<DWORD>
{
    public:

    TBitEntryArray() : TGenericArray()
    {
        BitsPerEntry = 0;
        EntryBitMask = 0;
        TotalEntries = 0;
    }

    ~TBitEntryArray()
    {}

    DWORD GetItem(DWORD EntryIndex)
    {
        DWORD dwItemIndex = (EntryIndex * BitsPerEntry) >> 0x05;
        DWORD dwStartBit = (EntryIndex * BitsPerEntry) & 0x1F;
        DWORD dwEndBit = dwStartBit + BitsPerEntry;
        DWORD dwResult;

        // If the end bit index is greater than 32,
        // we also need to load from the next 32-bit item
        if(dwEndBit > 0x20)
        {
            dwResult = (ItemArray[dwItemIndex + 1] << (0x20 - dwStartBit)) | (ItemArray[dwItemIndex] >> dwStartBit);
        }
        else
        {
            dwResult = ItemArray[dwItemIndex] >> dwStartBit;
        }

        // Now we also need to mask the result by the bit mask
        return dwResult & EntryBitMask;
    }

    DWORD LoadBitsFromStream(TByteStream & InStream)
    {
        ULONGLONG Value64 = 0;
        DWORD dwErrCode;

        dwErrCode = LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = InStream.GetValue<DWORD>(BitsPerEntry);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
        if(BitsPerEntry > 0x20)
            return ERROR_BAD_FORMAT;

        dwErrCode = InStream.GetValue<DWORD>(EntryBitMask);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = InStream.GetValue<ULONGLONG>(Value64);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
        if(Value64 > 0xFFFFFFFF)
            return ERROR_BAD_FORMAT;
        TotalEntries = (DWORD)Value64;

        assert((BitsPerEntry * TotalEntries) / 32 <= ItemCount);
        return ERROR_SUCCESS;
    }

    DWORD BitsPerEntry;
    DWORD EntryBitMask;
    DWORD TotalEntries;
};

//-----------------------------------------------------------------------------
// TSparseArray functions

#define INDEX_TO_GROUP(val)   (val >> 9)
#define GROUP_TO_INDEX(grp)   (grp << 9)

// For each 0x200-th bit, this contains information about amount of "1" bits 
typedef struct _BASEVALS
{
    DWORD BaseValue200;             // Item value of every 0x200-th item

    DWORD AddValue40 : 7;           // For each 0x40 items (above the base200),
    DWORD AddValue80 : 8;           // we have extra shortcut to the item value
    DWORD AddValueC0 : 8;           // that is to be added to BaseValue200
    DWORD AddValue100 : 9;
    DWORD AddValue140 : 9;
    DWORD AddValue180 : 9;
    DWORD AddValue1C0 : 9;

    DWORD __xalignment : 5;         // Filling
} BASEVALS, *PBASEVALS;

class TSparseArray
{
    public:

    TSparseArray()
    {
        TotalItemCount = 0;
        ValidItemCount = 0;
    }

    // HOTS: 1958630
    DWORD LoadFromStream(TByteStream & InStream)
    {
        DWORD total_count = 0;
        DWORD valid_count = 0;
        DWORD dwErrCode;

        dwErrCode = ItemBits.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = InStream.GetValue<DWORD>(total_count);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
        dwErrCode = InStream.GetValue<DWORD>(valid_count);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;
        if(valid_count > total_count)
            return ERROR_FILE_CORRUPT;

        TotalItemCount = total_count;
        ValidItemCount = valid_count;

        dwErrCode = BaseVals.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = IndexToItem0.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = IndexToItem1.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        return ERROR_SUCCESS;
    }

    // Returns true if the array is empty
    bool IsEmpty()
    {
        return (TotalItemCount == 0);
    }

    // Returns true if the item at n-th position is present
    bool IsItemPresent(size_t index)
    {
        // (index >> 0x05) gives the DWORD, (1 << (ItemIndex & 0x1F)) gives the bit
        return (ItemBits[index >> 0x05] & (1 << (index & 0x1F))) ? true : false;
    }

    // Retrieves the value of the n-th item in the sparse array.
    // Note that for items that are not present, the value is equal
    // to the nearest lower present value
    DWORD GetItemValueAt(size_t index)
    {
        BASEVALS & SetBitsCount = BaseVals[index >> 0x09];
        DWORD IntValue;
        DWORD BitMask;

        //
        // Since we don't want to count bits for the entire array,
        // there are item value shortcuts every 0x200 items,
        // and then every 0x40 items above the 0x200 base
        //

        // 1) We have base value for every 0x200-th item
        IntValue = SetBitsCount.BaseValue200;

        // 2) Add the base value for each 0x40-th item above the 0x200 base
        switch(((index >> 0x06) & 0x07) - 1)
        {
            case 0:     // Add the 1st value (7 bits)
                IntValue += SetBitsCount.AddValue40;
                break;

            case 1:     // Add the 2nd value (8 bits)
                IntValue += SetBitsCount.AddValue80;
                break;

            case 2:     // Add the 3rd value (8 bits)
                IntValue += SetBitsCount.AddValueC0;
                break;

            case 3:     // Add the 4th value (9 bits)
                IntValue += SetBitsCount.AddValue100;
                break;

            case 4:     // Add the 5th value (9 bits)
                IntValue += SetBitsCount.AddValue140;
                break;

            case 5:     // Add the 6th value (9 bits)
                IntValue += SetBitsCount.AddValue180;
                break;

            case 6:     // Add the 7th value (9 bits)
                IntValue += SetBitsCount.AddValue1C0;
                break;
        }

        // 3) Count the bits of the higher DWORD, if the index 0x20 - 0x30 above the 0x200 base
        if(index & 0x20)
            IntValue += GetNumberOfSetBits32(ItemBits[(index >> 0x05) - 1]);

        // 4) Count the bits in the current DWORD (masked by bit index mask) 
        BitMask = (1 << (index & 0x1F)) - 1;
        return IntValue + GetNumberOfSetBits32(ItemBits[index >> 0x05] & BitMask);
    }

    DWORD FindGroup_Items0(DWORD index)
    {
        // Setup the group range to search
        DWORD minGroup = (IndexToItem0[INDEX_TO_GROUP(index) + 0]) >> 9;
        DWORD maxGroup = (IndexToItem0[INDEX_TO_GROUP(index) + 1] + 0x1FF) >> 9;

        // Search the groups and find the BASEVALS structure
        // For spans less than 10 groups, use sequential search, otherwise binary search.
        if ((maxGroup - minGroup) < 10)
        {
            // HOTS: 1959CF7
            while (index >= GROUP_TO_INDEX(minGroup) - BaseVals[minGroup + 1].BaseValue200 + 0x200)
            {
                // HOTS: 1959D14
                minGroup++;
            }
        }
        else
        {
            // HOTS: 1959D2E
            while ((minGroup + 1) < maxGroup)
            {
                // HOTS: 1959D38
                DWORD middleValue = (maxGroup + minGroup) >> 1;

                if (index < (maxGroup << 0x09) - BaseVals[maxGroup].BaseValue200)
                {
                    // HOTS: 01959D4B
                    maxGroup = middleValue;
                }
                else
                {
                    // HOTS: 1959D50
                    minGroup = middleValue;
                }
            }
        }

        return minGroup;
    }

    DWORD FindGroup_Items1(DWORD index)
    {
        DWORD groupIndex = (index >> 0x09);
        DWORD startValue = IndexToItem1[groupIndex] >> 9;
        DWORD nextValue = (IndexToItem1[groupIndex + 1] + 0x1FF) >> 9;

        // Find the BASEVALS structure which the start index belongs to
        // For less than 10 values, use sequential search. Otherwise, use binary search
        if ((nextValue - startValue) < 10)
        {
            // HOTS: 01959F94
            while (index >= BaseVals[startValue + 1].BaseValue200)
            {
                // HOTS: 1959FA3
                startValue++;
            }
        }
        else
        {
            // Binary search (HOTS: 1959FAD)
            if ((startValue + 1) < nextValue)
            {
                // HOTS: 1959FB4
                DWORD middleValue = (nextValue + startValue) >> 1;

                if (index < BaseVals[middleValue].BaseValue200)
                {
                    // HOTS: 1959FC4
                    nextValue = middleValue;
                }
                else
                {
                    // HOTS: 1959FC8
                    startValue = middleValue;
                }
            }
        }

        return startValue;
    }

    // Returns the value of Item0[index] (HOTS: 1959CB0)
    DWORD GetItem0(DWORD index)
    {
        SETBITS zeroBits;
        DWORD groupIndex;
        DWORD dwordIndex;
        DWORD itemIndex;
        DWORD bitGroup;
        DWORD edx = index;

#ifdef _DEBUG
        //if (TotalItemCount > 0x200)
        //{
        //    FILE * fp = fopen("e:\\Ladik\\Appdir\\CascLib\\doc\\mndx-sparse-array.txt", "wt");
        //    Dump(fp);
        //    fclose(fp);
        //}
#endif

        // If the index is at begin of the group, we just return the start value
        if ((index & 0x1FF) == 0)
            return IndexToItem0[INDEX_TO_GROUP(index)];

        // Find the group where the index belongs to
        groupIndex = FindGroup_Items0(index);

        // HOTS: 1959D5F
        edx += BaseVals[groupIndex].BaseValue200 - (groupIndex << 0x09);
        dwordIndex = (groupIndex << 4);

        if (edx < 0x100 - BaseVals[groupIndex].AddValue100)
        {
            // HOTS: 1959D8C
            if (edx < 0x80 - BaseVals[groupIndex].AddValue80)
            {
                // HOTS: 01959DA2
                if (edx >= 0x40 - BaseVals[groupIndex].AddValue40)
                {
                    // HOTS: 01959DB7
                    dwordIndex += 2;
                    edx = edx + BaseVals[groupIndex].AddValue40 - 0x40;
                }
            }
            else
            {
                // HOTS: 1959DC0
                if (edx < 0xC0 - BaseVals[groupIndex].AddValueC0)
                {
                    // HOTS: 1959DD3
                    dwordIndex += 4;
                    edx = edx + BaseVals[groupIndex].AddValue80 - 0x80;
                }
                else
                {
                    // HOTS: 1959DD3
                    dwordIndex += 6;
                    edx = edx + BaseVals[groupIndex].AddValueC0 - 0xC0;
                }
            }
        }
        else
        {
            // HOTS: 1959DE8
            if (edx < 0x180 - BaseVals[groupIndex].AddValue180)
            {
                // HOTS: 01959E00
                if (edx < 0x140 - BaseVals[groupIndex].AddValue140)
                {
                    // HOTS: 1959E11
                    dwordIndex += 8;
                    edx = edx + BaseVals[groupIndex].AddValue100 - 0x100;
                }
                else
                {
                    // HOTS: 1959E1D
                    dwordIndex += 10;
                    edx = edx + BaseVals[groupIndex].AddValue140 - 0x140;
                }
            }
            else
            {
                // HOTS: 1959E29
                if (edx < 0x1C0 - BaseVals[groupIndex].AddValue1C0)
                {
                    // HOTS: 1959E3D
                    dwordIndex += 12;
                    edx = edx + BaseVals[groupIndex].AddValue180 - 0x180;
                }
                else
                {
                    // HOTS: 1959E49
                    dwordIndex += 14;
                    edx = edx + BaseVals[groupIndex].AddValue1C0 - 0x1C0;
                }
            }
        }

        // HOTS: 1959E53:
        // Calculate the number of bits set in the value of "bitGroup"
        bitGroup = ~ItemBits[dwordIndex];
        zeroBits = GetNumberOfSetBits(bitGroup);

        if (edx >= zeroBits.u.Lower32)
        {
            // HOTS: 1959ea4
            bitGroup = ~ItemBits[++dwordIndex];
            edx = edx - zeroBits.u.Lower32;
            zeroBits = GetNumberOfSetBits(bitGroup);
        }

        // Re-calculate the item index
        itemIndex = (dwordIndex << 0x05);

        // HOTS: 1959eea
        if (edx < zeroBits.u.Lower16)
        {
            // HOTS: 1959EFC
            if (edx >= zeroBits.u.Lower08)
            {
                // HOTS: 1959F05
                bitGroup >>= 0x08;
                itemIndex += 0x08;
                edx -= zeroBits.u.Lower08;
            }
        }
        else
        {
            // HOTS: 1959F0D
            if (edx < zeroBits.u.Lower24)
            {
                // HOTS: 1959F19
                bitGroup >>= 0x10;
                itemIndex += 0x10;
                edx -= zeroBits.u.Lower16;
            }
            else
            {
                // HOTS: 1959F23
                bitGroup >>= 0x18;
                itemIndex += 0x18;
                edx -= zeroBits.u.Lower24;
            }
        }

        // HOTS: 1959f2b
        edx = edx << 0x08;
        bitGroup = bitGroup & 0xFF;

        // BUGBUG: Possible buffer overflow here. Happens when dwItemIndex >= 0x9C.
        // The same happens in Heroes of the Storm (build 29049), so I am not sure
        // if this is a bug or a case that never happens
        assert((bitGroup + edx) < sizeof(table_1BA1818));
        return table_1BA1818[bitGroup + edx] + itemIndex;
    }

    DWORD GetItem1(DWORD index)
    {
        SETBITS setBits;
        DWORD distFromBase;
        DWORD groupIndex;
        DWORD dwordIndex;
        DWORD itemIndex;
        DWORD bitGroup;

        // If the index is at begin of the group, we just return the start value
        if ((index & 0x1FF) == 0)
            return IndexToItem1[INDEX_TO_GROUP(index)];

        // Find the group where the index belongs to
        groupIndex = FindGroup_Items1(index);

        // Calculate the base200 dword index (HOTS: 1959FD4)
        distFromBase = index - BaseVals[groupIndex].BaseValue200;
        dwordIndex = groupIndex << 0x04;

        // Calculate the dword index including the sub-checkpoint
        if (distFromBase < BaseVals[groupIndex].AddValue100)
        {
            // HOTS: 1959FF1
            if (distFromBase < BaseVals[groupIndex].AddValue80)
            {
                // HOTS: 0195A000
                if (distFromBase >= BaseVals[groupIndex].AddValue40)
                {
                    // HOTS: 195A007
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue40;
                    dwordIndex += 2;
                }
            }
            else
            {
                // HOTS: 195A00E
                if (distFromBase < BaseVals[groupIndex].AddValueC0)
                {
                    // HOTS: 195A01A
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue80;
                    dwordIndex += 4;
                }
                else
                {
                    // HOTS: 195A01F
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValueC0;
                    dwordIndex += 6;
                }
            }
        }
        else
        {
            // HOTS: 195A026
            if (distFromBase < BaseVals[groupIndex].AddValue180)
            {
                // HOTS: 195A037
                if (distFromBase < BaseVals[groupIndex].AddValue140)
                {
                    // HOTS: 195A041
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue100;
                    dwordIndex += 8;
                }
                else
                {
                    // HOTS: 195A048
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue140;
                    dwordIndex += 10;
                }
            }
            else
            {
                // HOTS: 195A04D
                if (distFromBase < BaseVals[groupIndex].AddValue1C0)
                {
                    // HOTS: 195A05A
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue180;
                    dwordIndex += 12;
                }
                else
                {
                    // HOTS: 195A061
                    distFromBase = distFromBase - BaseVals[groupIndex].AddValue1C0;
                    dwordIndex += 14;
                }
            }
        }

        // HOTS: 195A066
        bitGroup = ItemBits[dwordIndex];
        setBits = GetNumberOfSetBits(bitGroup);

        // Get total number of set bits in the bit group
        if (distFromBase >= setBits.u.Lower32)
        {
            // HOTS: 195A0B2
            bitGroup = ItemBits[++dwordIndex];
            distFromBase = distFromBase - setBits.u.Lower32;
            setBits = GetNumberOfSetBits(bitGroup);
        }

        // Calculate the item index
        itemIndex = (dwordIndex << 0x05);

        // Get the number of set bits in the lower word (HOTS: 195A0F6)
        if (distFromBase < setBits.u.Lower16)
        {
            // HOTS: 195A111
            if (distFromBase >= setBits.u.Lower08)
            {
                // HOTS: 195A111
                itemIndex = itemIndex + 0x08;
                bitGroup = bitGroup >> 0x08;
                distFromBase = distFromBase - setBits.u.Lower08;
            }
        }
        else
        {
            // HOTS: 195A119
            if (distFromBase < setBits.u.Lower24)
            {
                // HOTS: 195A125
                bitGroup = bitGroup >> 0x10;
                itemIndex = itemIndex + 0x10;
                distFromBase = distFromBase - setBits.u.Lower16;
            }
            else
            {
                // HOTS: 195A12F
                bitGroup = bitGroup >> 0x18;
                itemIndex = itemIndex + 0x18;
                distFromBase = distFromBase - setBits.u.Lower24;
            }
        }

        bitGroup = bitGroup & 0xFF;
        distFromBase = distFromBase << 0x08;

        // BUGBUG: Potential buffer overflow
        // Happens in Heroes of the Storm when index == 0x5B
        assert((bitGroup + distFromBase) < sizeof(table_1BA1818));
        return table_1BA1818[bitGroup + distFromBase] + itemIndex;
    }

#ifdef _DEBUG
    void Dump(FILE * fp)
    {
        size_t * ArrayNormal;
        size_t * ArrayInvert;
        size_t IndexNormal = 0;
        size_t IndexInvert = 0;

        // Output numbers of set bits for every 0x200-th item
        fprintf(fp, "Number of set bits for every 0x200-th index\n"
                    "========================================================\n"
                    "   Index    Base200h  +40  +80  +C0  +100 +140 +180 +1C0\n"
                    "--------------------------------------------------------\n");
        for (size_t i = 0; i < BaseVals.ItemCount; i++)
        {
            fprintf(fp, "[%08zX]: %08x  %04x %04x %04x %04x %04x %04x %04x\n", GROUP_TO_INDEX(i), BaseVals[i].BaseValue200,
                BaseVals[i].AddValue40,
                BaseVals[i].AddValue80,
                BaseVals[i].AddValueC0,
                BaseVals[i].AddValue100,
                BaseVals[i].AddValue140,
                BaseVals[i].AddValue180,
                BaseVals[i].AddValue1C0);
        }
        fprintf(fp, "\n");

        // Output values of Item1 and Item0 for every 0x200-th index
        fprintf(fp, "Item0 and Item1 for every 0x200-th index\n"
                    "========================================\n"
                    "   Index     Item0    Item1\n"
                    "-----------------------------\n");
        for (size_t i = 0; i < IndexToItem0.ItemCount; i++)
        {
            fprintf(fp, "[%08zX]: %08x %08x\n", GROUP_TO_INDEX(i), IndexToItem0[i], IndexToItem1[i]);
        }
        fprintf(fp, "\n");


        // Output values of Item1 and Item0 for every index
        ArrayNormal = new size_t[TotalItemCount];
        ArrayInvert = new size_t[TotalItemCount];
        if (ArrayNormal && ArrayInvert)
        {
            // Invalidate both arrays
            memset(ArrayNormal, 0xFF, TotalItemCount * sizeof(size_t));
            memset(ArrayInvert, 0xFF, TotalItemCount * sizeof(size_t));

            // Load the both arrays
            for (size_t i = 0; i < TotalItemCount; i++)
            {
                if (IsItemPresent(i))
                    ArrayNormal[IndexNormal++] = i;
                else
                    ArrayInvert[IndexInvert++] = i;
            }

            // Output both arrays
            fprintf(fp, "Item0 and Item1 for every index\n"
                        "========================================\n"
                        "   Index     Item0    Item1\n"
                        "-----------------------------\n");
            for (size_t i = 0; i < TotalItemCount; i++)
            {
                char NormalValue[0x20];
                char InvertValue[0x20];

                if (ArrayNormal[i] == MNDX_INVALID_SIZE_T && ArrayInvert[i] == MNDX_INVALID_SIZE_T)
                    break;
                fprintf(fp, "[%08zX]: %8s  %8s\n", i, DumpValue(InvertValue, _countof(InvertValue), ArrayInvert[i]), DumpValue(NormalValue, _countof(NormalValue), ArrayNormal[i]));
            }
            fprintf(fp, "\n");
        }

        // Free both arrays
        delete[] ArrayNormal;
        delete[] ArrayInvert;

        // Output array of all values
        fprintf(fp, "Item List: Index -> Value\n==========================\n");
        for (size_t i = 0; i < TotalItemCount; i++)
        {
            if (IsItemPresent(i))
            {
                fprintf(fp, "[%08zX]: %08x\n", i, GetItemValueAt(i));
            }
            else
            {
                fprintf(fp, "[%08zX]: NOT PRESENT\n", i);
            }
        }
        fprintf(fp, "\n");
    }

    char * DumpValue(char * szBuffer, size_t cchBuffer, size_t value)
    {
        CascStrPrintf(szBuffer, cchBuffer, (value != MNDX_INVALID_SIZE_T) ? "%08zX" : "   -    ", value);
        return szBuffer;
    }
#endif

    TGenericArray<DWORD> ItemBits;              // A bit array for each item. 1 if the item is present.
    size_t TotalItemCount;                      // Total number of items in the array
    size_t ValidItemCount;                      // Number of present items in the array
    TGenericArray<BASEVALS> BaseVals;           // For each 0x200-th item, this contains the number of set bits up to that 0x200-th item
    TGenericArray<DWORD> IndexToItem0;          // Mapping of index to invert item. An "invert" item is an item whose bit in "ItemBits" is zero.
    TGenericArray<DWORD> IndexToItem1;          // Mapping of index to normal item. An "normal" item is an item whose bit in "ItemBits" is set.
};

//-----------------------------------------------------------------------------
// TStruct40 functions

class TStruct40
{
    public:

    TStruct40()
    {
        NodeIndex   = 0;
        ItemCount   = 0;
        PathLength  = 0;
        SearchPhase = MNDX_SEARCH_INITIALIZING;
    }

    // HOTS: 19586B0
    void BeginSearch()
    {
        // HOTS: 19586BD
        PathBuffer.ItemCount = 0;
        PathBuffer.SetMaxItemsIf(0x40);

        // HOTS: 19586E1
        // Set the new item count
        PathStops.GrowArray(0);
        PathStops.SetMaxItemsIf(4);

        PathLength = 0;
        NodeIndex = 0;
        ItemCount = 0;
        SearchPhase = MNDX_SEARCH_SEARCHING;
    }

    DWORD CalcHashValue(const char * szPath)
    {
        return (BYTE)(szPath[PathLength]) ^ (NodeIndex << 0x05) ^ NodeIndex;
    }

    TGenericArray<TPathStop> PathStops;         // Array of path checkpoints
    TGenericArray<char> PathBuffer;             // Buffer for building a file name
    DWORD NodeIndex;                            // ID of a path node being searched; starting with 0
    DWORD PathLength;                           // Length of the path in the PathBuffer
    DWORD ItemCount;
    DWORD SearchPhase;                          // 0 = initializing, 2 = searching, 4 = finished
};

//-----------------------------------------------------------------------------
// Local functions - TMndxSearch

class TMndxSearch
{
    public:

    // HOTS: 01956EE0
    TMndxSearch()
    {
        szSearchMask = NULL;
        cchSearchMask = 0;
        szFoundPath = NULL;
        cchFoundPath = 0;
        nIndex = 0;
    }

    // HOTS: 01956F00
    ~TMndxSearch()
    {}

    // HOTS: 01956E70
    int SetSearchMask(
        const char * szNewSearchMask,
        size_t cchNewSearchMask)
    {
        if(szSearchMask == NULL && cchSearchMask != 0)
            return ERROR_INVALID_PARAMETER;

        Struct40.SearchPhase = MNDX_SEARCH_INITIALIZING;

        szSearchMask = szNewSearchMask;
        cchSearchMask = cchNewSearchMask;
        return ERROR_SUCCESS;
    }

    TStruct40 Struct40;
    const char * szSearchMask;          // Search mask without wildcards
    size_t cchSearchMask;               // Length of the search mask
    const char * szFoundPath;           // Found path name
    size_t cchFoundPath;                // Length of the found path name
    DWORD nIndex;                       // Index of the file name
};

//-----------------------------------------------------------------------------
// TPathFragmentTable class. This class implements table of the path fragments.
// These path fragments can either by terminated by zeros (ASCIIZ)
// or can be marked by the external "PathMarks" structure

class TPathFragmentTable
{
    public:

    // HOTS: 0195A290
    TPathFragmentTable()
    {}

    // HOTS: inlined
    ~TPathFragmentTable()
    {}

    // HOTS: 195A180
    bool ComparePathFragment(TMndxSearch * pSearch, size_t nFragmentOffset)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;

        // Do we have path fragment separators in an external structure?
        if(PathMarks.IsEmpty())
        {
            // Keep searching as long as the name matches with the fragment
            while(PathFragments[nFragmentOffset] == pSearch->szSearchMask[pStruct40->PathLength])
            {
                // Move to the next character
                pStruct40->PathLength++;
                nFragmentOffset++;

                // Is it the end of the fragment or end of the path?
                if(PathFragments[nFragmentOffset] == 0)
                    return true;
                if(pStruct40->PathLength >= pSearch->cchSearchMask)
                    return false;
            }

            return false;
        }
        else
        {
            // Keep searching as long as the name matches with the fragment
            while(PathFragments[nFragmentOffset] == pSearch->szSearchMask[pStruct40->PathLength])
            {
                // Move to the next character
                pStruct40->PathLength++;

                // Is it the end of the path fragment?
                if(PathMarks.IsItemPresent(nFragmentOffset++))
                    return true;
                if(nFragmentOffset >= pSearch->cchSearchMask)
                    return false;
            }

            return false;
        }
    }

    // HOTS: 195A3F0
    void CopyPathFragment(TMndxSearch * pSearch, size_t nFragmentOffset)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;

        // Do we have path fragment separators in an external structure?
        if (PathMarks.IsEmpty())
        {
            // HOTS: 195A40C
            while (PathFragments[nFragmentOffset] != 0)
            {
                // Insert the character to the path being built
                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset++]);
            }
        }
        else
        {
            // HOTS: 195A4B3
            while(!PathMarks.IsItemPresent(nFragmentOffset))
            {
                // Insert the character to the path being built
                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset++]);
            }
        }
    }

    // HOTS: 195A570
    bool CompareAndCopyPathFragment(TMndxSearch * pSearch, size_t nFragmentOffset)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;

        // Do we have path fragment separators in an external structure?
        if(PathMarks.IsEmpty())
        {
            // Keep copying as long as we don't reach the end of the search mask
            while(pStruct40->PathLength < pSearch->cchSearchMask)
            {
                // HOTS: 195A5A0
                if(PathFragments[nFragmentOffset] != pSearch->szSearchMask[pStruct40->PathLength])
                    return false;

                // HOTS: 195A5B7
                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset++]);
                pStruct40->PathLength++;

                // If we found the end of the fragment, return success
                if(PathFragments[nFragmentOffset] == 0)
                    return true;
            }

            // HOTS: 195A660
            // Now we need to copy the rest of the fragment
            while(PathFragments[nFragmentOffset] != 0)
            {
                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset]);
                nFragmentOffset++;
            }
        }
        else
        {
            // Keep copying as long as we don't reach the end of the search mask
            while(nFragmentOffset < pSearch->cchSearchMask)
            {
                if(PathFragments[nFragmentOffset] != pSearch->szSearchMask[pStruct40->PathLength])
                    return false;

                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset]);
                pStruct40->PathLength++;

                // If we found the end of the fragment, return success
                if(PathMarks.IsItemPresent(nFragmentOffset++))
                    return true;
            }

            // Now we need to copy the rest of the fragment
            while(!PathMarks.IsItemPresent(nFragmentOffset))
            {
                // HOTS: 195A7A6
                pStruct40->PathBuffer.Insert(PathFragments[nFragmentOffset++]);
            }
        }

        return true;
    }

    // HOTS: 0195A820
    DWORD LoadFromStream(TByteStream & InStream)
    {
        DWORD dwErrCode;

        dwErrCode = PathFragments.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        return PathMarks.LoadFromStream(InStream);
    }

    TGenericArray<char> PathFragments;
    TSparseArray PathMarks;
};

//-----------------------------------------------------------------------------
// TStruct10 functions

class TStruct10
{
    public:

    TStruct10()
    {
        field_0 = 0x03;
        field_4 = 0x200;
        field_8 = 0x1000;
        field_C = 0x20000;
    }

    // HOTS: 1956FD0
    int sub_1956FD0(DWORD dwBitMask)
    {
        switch(dwBitMask & 0xF80)
        {
            case 0x00:
                field_4 = 0x200;
                return ERROR_SUCCESS;

            case 0x80:
                field_4 = 0x80;
                return ERROR_SUCCESS;

            case 0x100:
                field_4 = 0x100;
                return ERROR_SUCCESS;

            case 0x200:
                field_4 = 0x200;
                return ERROR_SUCCESS;

            case 0x400:
                field_4 = 0x400;
                return ERROR_SUCCESS;

            case 0x800:
                field_4 = 0x800;
                return ERROR_SUCCESS;
        }

        return ERROR_INVALID_PARAMETER;
    }

    // HOTS: 1957050
    int sub_1957050(DWORD dwBitMask)
    {
        switch(dwBitMask & 0xF0000)
        {
            case 0x00:
                field_C = 0x20000;
                return ERROR_SUCCESS;

            case 0x10000:
                field_C = 0x10000;
                return ERROR_SUCCESS;

            case 0x20000:
                field_C = 0x20000;
                return ERROR_SUCCESS;
        }

        return ERROR_INVALID_PARAMETER;
    }

    // HOTS: 19572E0
    DWORD sub_19572E0(DWORD dwBitMask)
    {
        DWORD dwSubMask;
        DWORD dwErrCode;

        if(dwBitMask & 0xFFF00000)
            return ERROR_INVALID_PARAMETER;

        dwSubMask = dwBitMask & 0x7F;
        if(dwSubMask)
            field_0 = dwSubMask;

        dwErrCode = sub_1956FD0(dwBitMask);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwSubMask = dwBitMask & 0xF000;
        if(dwSubMask == 0 || dwSubMask == 0x1000)
        {
            field_8 = 0x1000;
            return sub_1957050(dwBitMask);
        }

        if(dwSubMask == 0x2000)
        {
            field_8 = 0x2000;
            return sub_1957050(dwBitMask);
        }

        return ERROR_INVALID_PARAMETER;
    }

    // HOTS: 1957800
    int sub_1957800(DWORD dwBitMask)
    {
        return sub_19572E0(dwBitMask);
    }

    DWORD field_0;
    DWORD field_4;
    DWORD field_8;
    DWORD field_C;
};

//-----------------------------------------------------------------------------
// TFileNameDatabase interface/implementation

class TFileNameDatabase
{
    public:

    // HOTS: 01958730
    TFileNameDatabase()
    {
        HashTableMask = 0;
        field_214 = 0;
        pChildDB = NULL;
    }

    ~TFileNameDatabase()
    {
        delete pChildDB;
    }

    // Returns nonzero if the name fragment match is a single-char match
    bool IsPathFragmentSingleChar(HASH_ENTRY * pHashEntry)
    {
        return ((pHashEntry->FragmentOffset & 0xFFFFFF00) == 0xFFFFFF00);
    }

    // Returns true if the given collision path fragment is a string (aka more than 1 char)
    bool IsPathFragmentString(size_t index)
    {
        return CollisionHiBitsIndexes.IsItemPresent(index);
    }

    // HOTS: 1957350, inlined
    DWORD GetPathFragmentOffset1(DWORD index_lobits)
    {
        DWORD index_hibits = CollisionHiBitsIndexes.GetItemValueAt(index_lobits);

        return (HiBitsTable.GetItem(index_hibits) << 0x08) | LoBitsTable[index_lobits];
    }

    // Retrieves fragment_offset/subtable_index of the path fragment, with check for starting value
    DWORD GetPathFragmentOffset2(DWORD & index_hibits, DWORD index_lobits)
    {
        // If the hi-bits index is invalid, we need to get its starting value
        if (index_hibits == CASC_INVALID_INDEX)
        {
/*
            printf("\n");
            for (DWORD i = 0; i < CollisionHiBitsIndexes.TotalItemCount; i++)
            {
                if (CollisionHiBitsIndexes.IsItemPresent(i))
                    printf("[%02X] = %02X\n", i, CollisionHiBitsIndexes.GetIntValueAt(i));
                else
                    printf("[%02X] = NOT_PRESENT\n", i);
            }
*/
            index_hibits = CollisionHiBitsIndexes.GetItemValueAt(index_lobits);
        }
        else
        {
            index_hibits++;
        }

        // Now we use both NodeIndex and HiBits index for retrieving the path fragment index
        return (HiBitsTable.GetItem(index_hibits) << 0x08) | LoBitsTable[index_lobits];
    }

    // HOTS: 1956DA0
    DWORD Load(LPBYTE pbMarData, size_t cbMarData)
    {
        TByteStream ByteStream;
        DWORD dwSignature;
        DWORD dwErrCode;

        if(pbMarData == NULL && cbMarData != 0)
            return ERROR_INVALID_PARAMETER;

        dwErrCode = ByteStream.SetByteBuffer(pbMarData, cbMarData);
        if(dwErrCode == ERROR_SUCCESS)
        {
            // Get pointer to MAR signature
            dwErrCode = ByteStream.GetValue<DWORD>(dwSignature);
            if(dwErrCode != ERROR_SUCCESS)
                return dwErrCode;

            // Verify the signature
            if(dwSignature != MNDX_MAR_SIGNATURE)
                return ERROR_BAD_FORMAT;

            // HOTS: 1956E11
            dwErrCode = LoadFromStream(ByteStream);
        }

        return dwErrCode;
    }

    // HOTS: 19584B0
    int SetChildDatabase(TFileNameDatabase * pNewDB)
    {
        if(pNewDB != NULL && pChildDB == pNewDB)
            return ERROR_INVALID_PARAMETER;

        if(pChildDB != NULL)
            delete pChildDB;
        pChildDB = pNewDB;
        return ERROR_SUCCESS;
    }

    // HOTS: 1957970
    bool ComparePathFragment(TMndxSearch * pSearch)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        PHASH_ENTRY pHashEntry;
        DWORD ColTableIndex;
        DWORD HiBitsIndex;
        DWORD NodeIndex;

        // Calculate the item hash from the current char and fragment ID
        NodeIndex = pStruct40->CalcHashValue(pSearch->szSearchMask) & HashTableMask;
        pHashEntry = &HashTable[NodeIndex];

        // Does the hash value ID match?
        if(pHashEntry->NodeIndex == pStruct40->NodeIndex)
        {
            // Check if there is single character match
            if (!IsPathFragmentSingleChar(pHashEntry))
            {
                // Check if there is a name fragment match
                if (pChildDB != NULL)
                {
                    if (!pChildDB->ComparePathFragmentByIndex(pSearch, pHashEntry->ChildTableIndex))
                        return false;
                }
                else
                {
                    if (!PathFragmentTable.ComparePathFragment(pSearch, pHashEntry->FragmentOffset))
                        return false;
                }
            }
            else
            {
                pStruct40->PathLength++;
            }

            pStruct40->NodeIndex = pHashEntry->NextIndex;
            return true;
        }

        //
        // Conflict: Multiple node IDs give the same table index
        //

        // HOTS: 1957A0E
        ColTableIndex = CollisionTable.GetItem0(pStruct40->NodeIndex) + 1;
        pStruct40->NodeIndex = (ColTableIndex - pStruct40->NodeIndex - 1);
        HiBitsIndex = CASC_INVALID_INDEX;

        // HOTS: 1957A41:
        while(CollisionTable.IsItemPresent(ColTableIndex))
        {
            // HOTS: 1957A41
            // Check if the low 8 bits if the fragment offset contain a single character
            // or an offset to a name fragment
            if(IsPathFragmentString(pStruct40->NodeIndex))
            {
                DWORD FragmentOffset = GetPathFragmentOffset2(HiBitsIndex, pStruct40->NodeIndex);
                DWORD SavePathLength = pStruct40->PathLength;       // HOTS: 1957A83

                // Do we have a child database?
                if(pChildDB != NULL)
                {
                    // HOTS: 1957AEC
                    if(pChildDB->ComparePathFragmentByIndex(pSearch, FragmentOffset))
                        return true;
                }
                else
                {
                    // HOTS: 1957AF7
                    if(PathFragmentTable.ComparePathFragment(pSearch, FragmentOffset))
                        return true;
                }

                // HOTS: 1957B0E
                // If there was partial match with the fragment, end the search
                if(pStruct40->PathLength != SavePathLength)
                    return false;
            }
            else
            {
                // HOTS: 1957B1C
                if(LoBitsTable[pStruct40->NodeIndex] == pSearch->szSearchMask[pStruct40->PathLength])
                {
                    pStruct40->PathLength++;
                    return true;
                }
            }

            // HOTS: 1957B32
            pStruct40->NodeIndex++;
            ColTableIndex++;
        }

        return false;
    }

    // HOTS: 1957B80
    bool ComparePathFragmentByIndex(TMndxSearch * pSearch, DWORD TableIndex)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        PHASH_ENTRY pHashEntry;
        DWORD eax;

        // HOTS: 1957B95
        for (;;)
        {
            // Get the hasn table item
            pHashEntry = &HashTable[TableIndex & HashTableMask];

            // 
            if (TableIndex == pHashEntry->NextIndex)
            {
                // HOTS: 01957BB4
                if (!IsPathFragmentSingleChar(pHashEntry))
                {
                    // HOTS: 1957BC7
                    if (pChildDB != NULL)
                    {
                        // HOTS: 1957BD3
                        if (!pChildDB->ComparePathFragmentByIndex(pSearch, pHashEntry->ChildTableIndex))
                            return false;
                    }
                    else
                    {
                        // HOTS: 1957BE0
                        if (!PathFragmentTable.ComparePathFragment(pSearch, pHashEntry->FragmentOffset))
                            return false;
                    }
                }
                else
                {
                    // HOTS: 1957BEE
                    if (pSearch->szSearchMask[pStruct40->PathLength] != pHashEntry->SingleChar)
                        return false;
                    pStruct40->PathLength++;
                }

                // HOTS: 1957C05
                TableIndex = pHashEntry->NodeIndex;
                if (TableIndex == 0)
                    return true;

                if (pStruct40->PathLength >= pSearch->cchSearchMask)
                    return false;
            }
            else
            {
                // HOTS: 1957C30
                if (IsPathFragmentString(TableIndex))
                {
                    DWORD FragmentOffset = GetPathFragmentOffset1(TableIndex);

                    // HOTS: 1957C4C
                    if (pChildDB != NULL)
                    {
                        // HOTS: 1957C58
                        if (!pChildDB->ComparePathFragmentByIndex(pSearch, FragmentOffset))
                            return false;
                    }
                    else
                    {
                        // HOTS: 1957350
                        if (!PathFragmentTable.ComparePathFragment(pSearch, FragmentOffset))
                            return false;
                    }
                }
                else
                {
                    // HOTS: 1957C8E
                    if (LoBitsTable[TableIndex] != pSearch->szSearchMask[pStruct40->PathLength])
                        return false;

                    pStruct40->PathLength++;
                }

                // HOTS: 1957CB2
                if (TableIndex <= field_214)
                    return true;

                if (pStruct40->PathLength >= pSearch->cchSearchMask)
                    return false;

                eax = CollisionTable.GetItem1(TableIndex);
                TableIndex = (eax - TableIndex - 1);
            }
        }
    }

    // HOTS: 1958D70
    void CopyPathFragmentByIndex(TMndxSearch * pSearch, DWORD TableIndex)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        PHASH_ENTRY pHashEntry;

        // HOTS: 1958D84
        for (;;)
        {
            pHashEntry = &HashTable[TableIndex & HashTableMask];
            if (TableIndex == pHashEntry->NextIndex)
            {
                // HOTS: 1958DA6
                if (!IsPathFragmentSingleChar(pHashEntry))
                {
                    // HOTS: 1958DBA
                    if (pChildDB != NULL)
                    {
                        pChildDB->CopyPathFragmentByIndex(pSearch, pHashEntry->ChildTableIndex);
                    }
                    else
                    {
                        PathFragmentTable.CopyPathFragment(pSearch, pHashEntry->FragmentOffset);
                    }
                }
                else
                {
                    // HOTS: 1958DE7
                    // Insert the low 8 bits to the path being built
                    pStruct40->PathBuffer.Insert(pHashEntry->SingleChar);
                }

                // HOTS: 1958E71
                TableIndex = pHashEntry->NodeIndex;
                if (TableIndex == 0)
                    return;
            }
            else
            {
                // HOTS: 1958E8E
                if (IsPathFragmentString(TableIndex))
                {
                    DWORD FragmentOffset = GetPathFragmentOffset1(TableIndex);

                    // HOTS: 1958EAF
                    if (pChildDB != NULL)
                    {
                        pChildDB->CopyPathFragmentByIndex(pSearch, FragmentOffset);
                    }
                    else
                    {
                        PathFragmentTable.CopyPathFragment(pSearch, FragmentOffset);
                    }
                }
                else
                {
                    // HOTS: 1958F50
                    // Insert one character to the path being built
                    pStruct40->PathBuffer.Insert(LoBitsTable[TableIndex]);
                }

                // HOTS: 1958FDE
                if (TableIndex <= field_214)
                    return;

                TableIndex = 0xFFFFFFFF - TableIndex + CollisionTable.GetItem1(TableIndex);
            }
        }
    }

    // HOTS: 1958B00
    bool CompareAndCopyPathFragment(TMndxSearch * pSearch)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        PHASH_ENTRY pHashEntry;
        DWORD HiBitsIndex;
        DWORD ColTableIndex;
        DWORD TableIndex;
/*
        FILE * fp = fopen("E:\\PathFragmentTable.txt", "wt");
        if (fp != NULL)
        {
            for (DWORD i = 0; i < HashTable.ItemCount; i++)
            {
                FragOffs = HashTable[i].FragOffs;
                fprintf(fp, "%02x ('%c') %08X %08X %08X", i, (0x20 <= i && i < 0x80) ? i : 0x20, HashTable[i].ItemIndex, HashTable[i].NextIndex, FragOffs);

                if(FragOffs != 0x00800000)
                {
                    if((FragOffs & 0xFFFFFF00) == 0xFFFFFF00)
                        fprintf(fp, " '%c'", (char)(FragOffs & 0xFF));
                    else
                        fprintf(fp, " %s", &PathFragmentTable.PathFragments[FragOffs]);
                }
                fprintf(fp, "\n");
            }

            fclose(fp);
        }
*/
        // Calculate the item hash from the current char and fragment ID
        TableIndex = pStruct40->CalcHashValue(pSearch->szSearchMask) & HashTableMask;
        pHashEntry = &HashTable[TableIndex];

        // Does the hash value ID match?
        if(pStruct40->NodeIndex == pHashEntry->NodeIndex)
        {
            // If the higher 24 bits are set, then the fragment is just one letter,
            // contained directly in the table.
            if(!IsPathFragmentSingleChar(pHashEntry))
            {
                // HOTS: 1958B59
                if (pChildDB != NULL)
                {
                    if (!pChildDB->CompareAndCopyPathFragmentByIndex(pSearch, pHashEntry->ChildTableIndex))
                        return false;
                }
                else
                {
                    if (!PathFragmentTable.CompareAndCopyPathFragment(pSearch, pHashEntry->FragmentOffset))
                        return false;
                }
            }
            else
            {
                // HOTS: 1958B88
                pStruct40->PathBuffer.Insert(pHashEntry->SingleChar);
                pStruct40->PathLength++;
            }

            // HOTS: 1958BCA
            pStruct40->NodeIndex = pHashEntry->NextIndex;
            return true;
        }

        // HOTS: 1958BE5
        ColTableIndex = CollisionTable.GetItem0(pStruct40->NodeIndex) + 1;
        pStruct40->NodeIndex = (ColTableIndex - pStruct40->NodeIndex - 1);
        HiBitsIndex = CASC_INVALID_INDEX;

        // Keep searching while we have a valid collision table entry
        while(CollisionTable.IsItemPresent(ColTableIndex))
        {
            // If we have high bits in the the bit at NodeIndex is set, it means that there is fragment offset
            // If not, the byte in LoBitsTable is the character
            if(IsPathFragmentString(pStruct40->NodeIndex))
            {
                DWORD FragmentOffset = GetPathFragmentOffset2(HiBitsIndex, pStruct40->NodeIndex);
                DWORD SavePathLength = pStruct40->PathLength;   // HOTS: 1958C62

                // Do we have a child database?
                if(pChildDB != NULL)
                {
                    // HOTS: 1958CCB
                    if(pChildDB->CompareAndCopyPathFragmentByIndex(pSearch, FragmentOffset))
                        return true;
                }
                else
                {
                    // HOTS: 1958CD6
                    if(PathFragmentTable.CompareAndCopyPathFragment(pSearch, FragmentOffset))
                        return true;
                }

                // HOTS: 1958CED
                if(SavePathLength != pStruct40->PathLength)
                    return false;
            }
            else
            {
                // HOTS: 1958CFB
                if(LoBitsTable[pStruct40->NodeIndex] == pSearch->szSearchMask[pStruct40->PathLength])
                {
                    // HOTS: 1958D11
                    pStruct40->PathBuffer.Insert(LoBitsTable[pStruct40->NodeIndex]);
                    pStruct40->PathLength++;
                    return true;
                }
            }

            // HOTS: 1958D11
            pStruct40->NodeIndex++;
            ColTableIndex++;
        }

        return false;
    }

    // HOTS: 1959010
    bool CompareAndCopyPathFragmentByIndex(TMndxSearch * pSearch, DWORD TableIndex)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        PHASH_ENTRY pHashEntry;

        // HOTS: 1959024
        for(;;)
        {
            pHashEntry = &HashTable[TableIndex & HashTableMask];
            if(TableIndex == pHashEntry->NextIndex)
            {
                // HOTS: 1959047
                if(!IsPathFragmentSingleChar(pHashEntry))
                {
                    // HOTS: 195905A
                    if(pChildDB != NULL)
                    {
                        if(!pChildDB->CompareAndCopyPathFragmentByIndex(pSearch, pHashEntry->ChildTableIndex))
                            return false;
                    }
                    else
                    {
                        if(!PathFragmentTable.CompareAndCopyPathFragment(pSearch, pHashEntry->FragmentOffset))
                            return false;
                    }
                }
                else
                {
                    // HOTS: 1959092
                    if(pHashEntry->SingleChar != pSearch->szSearchMask[pStruct40->PathLength])
                        return false;

                    // Insert the low 8 bits to the path being built
                    pStruct40->PathBuffer.Insert(pHashEntry->SingleChar);
                    pStruct40->PathLength++;
                }

                // HOTS: 195912E
                TableIndex = pHashEntry->NodeIndex;
                if(TableIndex == 0)
                    return true;
            }
            else
            {
                // HOTS: 1959147
                if(IsPathFragmentString(TableIndex))
                {
                    // HOTS: 195917C
                    DWORD FragmentOffset = GetPathFragmentOffset1(TableIndex);

                    if(pChildDB != NULL)
                    {
                        if(!pChildDB->CompareAndCopyPathFragmentByIndex(pSearch, FragmentOffset))
                            return false;
                    }
                    else
                    {
                        if(!PathFragmentTable.CompareAndCopyPathFragment(pSearch, FragmentOffset))
                            return false;
                    }
                }
                else
                {
                    // HOTS: 195920E
                    if(LoBitsTable[TableIndex] != pSearch->szSearchMask[pStruct40->PathLength])
                        return false;

                    // Insert one character to the path being built
                    pStruct40->PathBuffer.Insert(LoBitsTable[TableIndex]);
                    pStruct40->PathLength++;
                }

                // HOTS: 19592B6
                if(TableIndex <= field_214)
                    return true;

                TableIndex = 0xFFFFFFFF - TableIndex + CollisionTable.GetItem1(TableIndex);
            }

            // HOTS: 19592D5
            if(pStruct40->PathLength >= pSearch->cchSearchMask)
                break;
        }

        CopyPathFragmentByIndex(pSearch, TableIndex);
        return true;
    }

    // HOTS: 1959460
    bool DoSearch(TMndxSearch * pSearch)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;
        TPathStop * pPathStop;
        DWORD edi;

        // Perform action based on the search phase
        switch (pStruct40->SearchPhase)
        {
            case MNDX_SEARCH_INITIALIZING:
            {
                // HOTS: 1959489
                pStruct40->BeginSearch();

                // If the caller passed a part of the search path, we need to find that one
                while (pStruct40->PathLength < pSearch->cchSearchMask)
                {
                    if (!CompareAndCopyPathFragment(pSearch))
                    {
                        pStruct40->SearchPhase = MNDX_SEARCH_FINISHED;
                        return false;
                    }
                }

                // HOTS: 19594b0
                TPathStop PathStop(pStruct40->NodeIndex, 0, pStruct40->PathBuffer.ItemCount);
                pStruct40->PathStops.Insert(PathStop);
                pStruct40->ItemCount = 1;

                if (FileNameIndexes.IsItemPresent(pStruct40->NodeIndex))
                {
                    pSearch->szFoundPath = &pStruct40->PathBuffer[0];
                    pSearch->cchFoundPath = pStruct40->PathBuffer.ItemCount;
                    pSearch->nIndex = FileNameIndexes.GetItemValueAt(pStruct40->NodeIndex);
                    return true;
                }
            }
            // No break here, go straight to the MNDX_SEARCH_SEARCHING

            case MNDX_SEARCH_SEARCHING:
            {
                // HOTS: 1959522
                for (;;)
                {
                    // HOTS: 1959530
                    if (pStruct40->ItemCount == pStruct40->PathStops.ItemCount)
                    {
                        TPathStop * pLastStop;
                        DWORD ColTableIndex;

                        pLastStop = &pStruct40->PathStops[pStruct40->PathStops.ItemCount - 1];

                        ColTableIndex = CollisionTable.GetItem0(pLastStop->LoBitsIndex) + 1;

                        // Insert a new structure
                        TPathStop PathStop(ColTableIndex - pLastStop->LoBitsIndex - 1, ColTableIndex, 0);
                        pStruct40->PathStops.Insert(PathStop);
                    }

                    // HOTS: 19595BD
                    pPathStop = &pStruct40->PathStops[pStruct40->ItemCount];

                    // HOTS: 19595CC
                    if (CollisionTable.IsItemPresent(pPathStop->field_4++))
                    {
                        // HOTS: 19595F2
                        pStruct40->ItemCount++;

                        if (IsPathFragmentString(pPathStop->LoBitsIndex))
                        {
                            DWORD FragmentOffset = GetPathFragmentOffset2(pPathStop->HiBitsIndex_PathFragment, pPathStop->LoBitsIndex);

                            // HOTS: 1959630
                            if (pChildDB != NULL)
                            {
                                // HOTS: 1959649
                                pChildDB->CopyPathFragmentByIndex(pSearch, FragmentOffset);
                            }
                            else
                            {
                                // HOTS: 1959654
                                PathFragmentTable.CopyPathFragment(pSearch, FragmentOffset);
                            }
                        }
                        else
                        {
                            // HOTS: 1959665
                            // Insert one character to the path being built
                            pStruct40->PathBuffer.Insert(LoBitsTable[pPathStop->LoBitsIndex]);
                        }

                        // HOTS: 19596AE
                        pPathStop->Count = pStruct40->PathBuffer.ItemCount;

                        // HOTS: 19596b6
                        if (FileNameIndexes.IsItemPresent(pPathStop->LoBitsIndex))
                        {
                            // HOTS: 19596D1
                            if (pPathStop->field_10 == 0xFFFFFFFF)
                            {
                                // HOTS: 19596D9
                                pPathStop->field_10 = FileNameIndexes.GetItemValueAt(pPathStop->LoBitsIndex);
                            }
                            else
                            {
                                pPathStop->field_10++;
                            }

                            // HOTS: 1959755
                            pSearch->szFoundPath = &pStruct40->PathBuffer[0];
                            pSearch->cchFoundPath = pStruct40->PathBuffer.ItemCount;
                            pSearch->nIndex = pPathStop->field_10;
                            return true;
                        }
                    }
                    else
                    {
                        // HOTS: 19596E9
                        if (pStruct40->ItemCount == 1)
                        {
                            pStruct40->SearchPhase = MNDX_SEARCH_FINISHED;
                            return false;
                        }

                        // HOTS: 19596F5
                        pStruct40->PathStops[pStruct40->ItemCount - 1].LoBitsIndex++;
                        edi = pStruct40->PathStops[pStruct40->ItemCount - 2].Count;
                        pStruct40->PathBuffer.SetMaxItemsIf(edi);

                        // HOTS: 1959749
                        pStruct40->PathBuffer.ItemCount = edi;
                        pStruct40->ItemCount--;
                    }
                }
            }

            case MNDX_SEARCH_FINISHED:
                break;
        }

        return false;
    }

    // HOTS: 1957EF0
    bool FindFileInDatabase(TMndxSearch * pSearch)
    {
        TStruct40 * pStruct40 = &pSearch->Struct40;

        pStruct40->NodeIndex = 0;
        pStruct40->PathLength = 0;
        pStruct40->SearchPhase = MNDX_SEARCH_INITIALIZING;

        if(pSearch->cchSearchMask > 0)
        {
            while(pStruct40->PathLength < pSearch->cchSearchMask)
            {
                // HOTS: 01957F12
                if(!ComparePathFragment(pSearch))
                    return false;
            }
        }

        // HOTS: 1957F26
        if(!FileNameIndexes.IsItemPresent(pStruct40->NodeIndex))
            return false;

        pSearch->szFoundPath   = pSearch->szSearchMask;
        pSearch->cchFoundPath  = pSearch->cchSearchMask;
        pSearch->nIndex = FileNameIndexes.GetItemValueAt(pStruct40->NodeIndex);
        return true;
    }

    // HOTS: 1959790
    DWORD LoadFromStream(TByteStream & InStream)
    {
        DWORD dwBitMask;
        DWORD dwErrCode;

        dwErrCode = CollisionTable.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = FileNameIndexes.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = CollisionHiBitsIndexes.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // HOTS: 019597CD
        dwErrCode = LoBitsTable.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = HiBitsTable.LoadBitsFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // HOTS: 019597F5
        dwErrCode = PathFragmentTable.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // HOTS: 0195980A
        if(CollisionHiBitsIndexes.ValidItemCount != 0 && PathFragmentTable.PathFragments.ItemCount == 0)
        {
            TFileNameDatabase * pNewDB;

            pNewDB = new TFileNameDatabase;
            if (pNewDB == NULL)
                return ERROR_NOT_ENOUGH_MEMORY;

            dwErrCode = SetChildDatabase(pNewDB);
            if(dwErrCode != ERROR_SUCCESS)
                return dwErrCode;

            dwErrCode = pChildDB->LoadFromStream(InStream);
            if(dwErrCode != ERROR_SUCCESS)
                return dwErrCode;
        }

        // HOTS: 0195986B
        dwErrCode = HashTable.LoadFromStream(InStream);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        HashTableMask = HashTable.ItemCount - 1;

        dwErrCode = InStream.GetValue<DWORD>(field_214);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        dwErrCode = InStream.GetValue<DWORD>(dwBitMask);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        return Struct10.sub_1957800(dwBitMask);
    }

    TSparseArray CollisionTable;                // Table of valid collisions, indexed by NodeIndex
    TSparseArray FileNameIndexes;               // Array of file name indexes
    TSparseArray CollisionHiBitsIndexes;        // Table of indexes of high bits (above 8 bits) for collisions 

    // This pair of arrays serves for fast conversion from node index to FragmentOffset / FragmentChar
    TGenericArray<BYTE> LoBitsTable;            // Array of lower 8 bits of name fragment offset
    TBitEntryArray      HiBitsTable;            // Array of upper x bits of name fragment offset

    TPathFragmentTable PathFragmentTable;
    TFileNameDatabase * pChildDB;

    TGenericArray<HASH_ENTRY> HashTable;         // Hash table for searching name fragments

    DWORD HashTableMask;                        // Mask to get hash table index from hash value
    DWORD field_214;
    TStruct10 Struct10;
};

//-----------------------------------------------------------------------------
// Local functions - MAR file

class TMndxMarFile
{
    public:

    TMndxMarFile()
    {
        pDatabase = NULL;
        pbMarData = NULL;
        cbMarData = 0;
    }

    ~TMndxMarFile()
    {
        if(pDatabase != NULL)
            delete pDatabase;
        CASC_FREE(pbMarData);
    }

    // HOTS: 00E94180
    int LoadRootData(FILE_MAR_INFO & MarInfo, LPBYTE pbRootFile, LPBYTE pbRootEnd)
    {
        // Allocate the MAR data
        pbMarData = CASC_ALLOC<BYTE>(MarInfo.MarDataSize);
        cbMarData = MarInfo.MarDataSize;
        if(pbMarData == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        // Capture the MAR data
        if(!CaptureData(pbRootFile + MarInfo.MarDataOffset, pbRootEnd, pbMarData, cbMarData))
            return ERROR_FILE_CORRUPT;

        // Create the file name database
        pDatabase = new TFileNameDatabase();
        if(pDatabase == NULL)
            return ERROR_NOT_ENOUGH_MEMORY;

        return pDatabase->Load(pbMarData, cbMarData);
    }

    // HOTS: 1956C60
    DWORD SearchFile(TMndxSearch * pSearch)
    {
        DWORD dwErrCode = ERROR_SUCCESS;

        if(pDatabase == NULL)
            return ERROR_INVALID_PARAMETER;

        if(!pDatabase->FindFileInDatabase(pSearch))
            dwErrCode = ERROR_FILE_NOT_FOUND;

        return dwErrCode;
    }

    // HOTS: 1956CE0
    DWORD DoSearch(TMndxSearch * pSearch, bool * pbFindResult)
    {
        DWORD dwErrCode = ERROR_SUCCESS;

        if(pDatabase == NULL)
            return ERROR_INVALID_PARAMETER;

        *pbFindResult = pDatabase->DoSearch(pSearch);
        return dwErrCode;
    }

    // HOTS: 1956D20
    int GetFileNameCount(size_t * PtrFileNameCount)
    {
        if(pDatabase == NULL)
            return ERROR_INVALID_PARAMETER;

        PtrFileNameCount[0] = pDatabase->FileNameIndexes.ValidItemCount;
        return ERROR_SUCCESS;
    }

//  protected:
    TFileNameDatabase * pDatabase;
    LPBYTE pbMarData;
    size_t cbMarData;
};

//-----------------------------------------------------------------------------
// Implementation of root file functions

typedef struct _FILE_MNDX_INFO
{
    BYTE  RootFileName[MD5_HASH_SIZE];              // Name (aka MD5) of the root file
    DWORD HeaderVersion;                            // Must be <= 2
    DWORD FormatVersion;
    DWORD field_1C;
    DWORD field_20;
    DWORD MarInfoOffset;                            // Offset of the first MAR entry info
    DWORD MarInfoCount;                             // Number of the MAR info entries
    DWORD MarInfoSize;                              // Size of the MAR info entry
    DWORD CKeyEntriesOffset;                        // Offset of the CKey entries, relative to begin of the root file
    DWORD CKeyEntriesCount;                         // Number of CKeys (files) in the root file
    DWORD FileNameCount;                            // Number of unique file names. More files with the same name in the different packages can exist
    DWORD CKeyEntrySize;                            // Size of one CKey root entry
    TMndxMarFile * MarFiles[MAR_COUNT];             // File name list for the packages

} FILE_MNDX_INFO, *PFILE_MNDX_INFO;

struct TMndxHandler
{
    public:

    //
    //  Constructor and destructor
    //

    TMndxHandler()
    {
        memset(this, 0, sizeof(TMndxHandler));
    }

    ~TMndxHandler()
    {
        PMNDX_PACKAGE pPackage;
        size_t i;

        for(i = 0; i < MAR_COUNT; i++)
            delete MndxInfo.MarFiles[i];
        CASC_FREE(FileNameIndexToCKeyIndex);
        pCKeyEntries = NULL;

        for(i = 0; i < Packages.ItemCount(); i++)
        {
            pPackage = (PMNDX_PACKAGE)Packages.ItemAt(i);
            CASC_FREE(pPackage->szFileName);
        }
        Packages.Free();
    }

    //
    //  Helper functions
    //

    static LPBYTE CaptureRootHeader(FILE_MNDX_HEADER & MndxHeader, LPBYTE pbRootPtr, LPBYTE pbRootEnd)
    {
        // Capture the root header
        pbRootPtr = CaptureData(pbRootPtr, pbRootEnd, &MndxHeader, sizeof(FILE_MNDX_HEADER));
        if (pbRootPtr == NULL)
            return NULL;

        // Check signature and version
        if (MndxHeader.Signature != CASC_MNDX_ROOT_SIGNATURE || MndxHeader.FormatVersion > 2 || MndxHeader.FormatVersion < 1)
            return NULL;

        // Passed
        return pbRootPtr + sizeof(FILE_MNDX_HEADER);
    }

    DWORD LoadPackageNames()
    {
        TMndxMarFile * pMarFile = MndxInfo.MarFiles[MAR_PACKAGE_NAMES];
        TMndxSearch Search;
        PMNDX_PACKAGE pPackage;
        size_t nPackageCount = 0x40;
        bool bFindResult = false;
        DWORD dwErrCode;

        // Prepare the file name search in the top level directory
        Search.SetSearchMask("", 0);

        // Allocate initial name list structure
        pMarFile->GetFileNameCount(&nPackageCount);
        dwErrCode = Packages.Create<MNDX_PACKAGE>(nPackageCount);
        if(dwErrCode != ERROR_SUCCESS)
            return dwErrCode;

        // Reset the package array
        Packages.Reset();

        // Keep searching as long as we find something
        while(pMarFile->DoSearch(&Search, &bFindResult) == ERROR_SUCCESS && bFindResult)
        {
            // Insert new package to the array
            assert(Search.nIndex < nPackageCount);
            pPackage = (PMNDX_PACKAGE)Packages.InsertAt(Search.nIndex);
            if (pPackage != NULL)
            {
                // The package mut not be initialized yet
                assert(pPackage->szFileName == NULL);

                // Allocate space for the file name
                pPackage->szFileName = CASC_ALLOC<char>(Search.cchFoundPath + 1);
                if (pPackage->szFileName == NULL)
                    return ERROR_NOT_ENOUGH_MEMORY;

                // Fill the package structure
                memcpy(pPackage->szFileName, Search.szFoundPath, Search.cchFoundPath);
                pPackage->szFileName[Search.cchFoundPath] = 0;
                pPackage->nLength = Search.cchFoundPath;
                pPackage->nIndex = Search.nIndex;
            }
        }

        // Give the packages to the caller
        return ERROR_SUCCESS;
    }

    DWORD Load(const FILE_MNDX_HEADER & MndxHeader, LPBYTE pbRootFile, LPBYTE pbRootEnd)
    {
        TMndxMarFile * pMarFile;
        FILE_MAR_INFO MarInfo;
        size_t nFilePointer = 0;
        DWORD i;
        DWORD dwErrCode = ERROR_SUCCESS;

        // Copy the header into the MNDX info
        MndxInfo.HeaderVersion = MndxHeader.HeaderVersion;
        MndxInfo.FormatVersion = MndxHeader.FormatVersion;
        nFilePointer += sizeof(FILE_MNDX_HEADER);

        // Header version 2 has 2 extra fields that we need to load
        if(MndxInfo.HeaderVersion == 2)
        {
            if(!CaptureData(pbRootFile + nFilePointer, pbRootEnd, &MndxInfo.field_1C, sizeof(DWORD) + sizeof(DWORD)))
                return ERROR_FILE_CORRUPT;
            nFilePointer += sizeof(DWORD) + sizeof(DWORD);
        }

        // Load the rest of the file header
        if(!CaptureData(pbRootFile + nFilePointer, pbRootEnd, &MndxInfo.MarInfoOffset, 0x1C))
            return ERROR_FILE_CORRUPT;

        // Verify the structure
        if(MndxInfo.MarInfoCount > MAR_COUNT || MndxInfo.MarInfoSize != sizeof(FILE_MAR_INFO))
            return ERROR_FILE_CORRUPT;

        // Load all MAR infos
        for(i = 0; i < MndxInfo.MarInfoCount; i++)
        {
            // Capture the n-th MAR info
            nFilePointer = MndxInfo.MarInfoOffset + (MndxInfo.MarInfoSize * i);
            if(!CaptureData(pbRootFile + nFilePointer, pbRootEnd, &MarInfo, sizeof(FILE_MAR_INFO)))
                return ERROR_FILE_CORRUPT;

            // Allocate MAR_FILE structure
            pMarFile = new TMndxMarFile();
            if(pMarFile == NULL)
            {
                dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
                break;
            }

            // Create the database from the MAR data
            dwErrCode = pMarFile->LoadRootData(MarInfo, pbRootFile, pbRootEnd);
            if(dwErrCode != ERROR_SUCCESS)
                break;

            // Assign the MAR file to the MNDX info structure
            MndxInfo.MarFiles[i] = pMarFile;
        }

        // All three MAR files must be loaded
        // HOTS: 00E9503B
        if(dwErrCode == ERROR_SUCCESS)
        {
            if(MndxInfo.MarFiles[MAR_PACKAGE_NAMES] == NULL || MndxInfo.MarFiles[MAR_STRIPPED_NAMES] == NULL || MndxInfo.MarFiles[MAR_FULL_NAMES] == NULL)
                dwErrCode = ERROR_BAD_FORMAT;
            if(MndxInfo.CKeyEntrySize != sizeof(MNDX_CKEY_ENTRY))
                dwErrCode = ERROR_BAD_FORMAT;
        }

        // Load the array of Ckey entries. All present files are in the array,
        // the same names (differentiated by package ID) are groupped together
        if(dwErrCode == ERROR_SUCCESS)
        {
            size_t CKeyEntriesSize;
            size_t FileNameCount = 0;

            pMarFile = MndxInfo.MarFiles[MAR_STRIPPED_NAMES];
            dwErrCode = ERROR_FILE_CORRUPT;

            // Capture the array of CKey entries
            if(pMarFile->GetFileNameCount(&FileNameCount) == ERROR_SUCCESS && FileNameCount == MndxInfo.FileNameCount)
            {
                CKeyEntriesSize = MndxInfo.CKeyEntriesCount * MndxInfo.CKeyEntrySize;
                if ((pbRootFile + MndxInfo.CKeyEntriesOffset + CKeyEntriesSize) <= pbRootEnd)
                {
                    pCKeyEntries = (PMNDX_CKEY_ENTRY)(pbRootFile + MndxInfo.CKeyEntriesOffset);
                    dwErrCode = ERROR_SUCCESS;
                }
            }
        }

        // Pick the CKey entries that are the first with a given name
        if(dwErrCode == ERROR_SUCCESS)
        {
            assert(MndxInfo.FileNameCount <= MndxInfo.CKeyEntriesCount);
            FileNameIndexToCKeyIndex = CASC_ALLOC<PMNDX_CKEY_ENTRY>(MndxInfo.FileNameCount + 1);
            if(FileNameIndexToCKeyIndex != NULL)
            {
                PMNDX_CKEY_ENTRY pRootEntry = pCKeyEntries;
                DWORD nFileNameIndex = 0;

                // The first entry is always beginning of a file name group
                FileNameIndexToCKeyIndex[nFileNameIndex++] = pRootEntry;

                // Get the remaining file name groups
                for(i = 0; i < MndxInfo.CKeyEntriesCount; i++, pRootEntry++)
                {
                    if (nFileNameIndex > MndxInfo.FileNameCount)
                        break;

                    if (pRootEntry->Flags & MNDX_LAST_CKEY_ENTRY)
                    {
                        FileNameIndexToCKeyIndex[nFileNameIndex++] = pRootEntry + 1;
                    }
                }

                // Verify the final number of file names
                if ((nFileNameIndex - 1) != MndxInfo.FileNameCount)
                    dwErrCode = ERROR_BAD_FORMAT;
            }
            else
                dwErrCode = ERROR_NOT_ENOUGH_MEMORY;
        }

        // Load the package names from the 0-th MAR file
        if(dwErrCode == ERROR_SUCCESS)
        {
            dwErrCode = LoadPackageNames();
        }

        return dwErrCode;
    }

    DWORD LoadFileNames(TCascStorage * hs, CASC_FILE_TREE & FileTree)
    {
        PCASC_CKEY_ENTRY pCKeyEntry;
        PMNDX_CKEY_ENTRY pRootEntry;
        PMNDX_CKEY_ENTRY pRootEnd = pCKeyEntries + MndxInfo.CKeyEntriesCount;
        PMNDX_PACKAGE pPackage;
        TMndxMarFile * pMarFile = MndxInfo.MarFiles[MAR_STRIPPED_NAMES];
        TMndxSearch Search;
        char szFileName[MAX_PATH];
        bool bFindResult = false;
        DWORD dwErrCode;

        // Setup the search mask
        Search.SetSearchMask("", 0);

        // Keep searching ad long as we found something
        while ((dwErrCode = pMarFile->DoSearch(&Search, &bFindResult)) == ERROR_SUCCESS && bFindResult)
        {
            // Sanity check
            assert(Search.cchFoundPath < MAX_PATH);

            // The found file name index must fall into range of file names
            if (Search.nIndex < MndxInfo.FileNameCount)
            {
                // Retrieve the first-in-group CKey entry of that name
                pRootEntry = FileNameIndexToCKeyIndex[Search.nIndex];

                // Now take all files of that name, prepend their package name and insert to file tree
                while(pRootEntry < pRootEnd)
                {
                    // Find the appropriate CKey entry in the central storage
                    pCKeyEntry = FindCKeyEntry_CKey(hs, pRootEntry->CKey);
                    if (pCKeyEntry != NULL)
                    {
                        size_t nPackageIndex = pRootEntry->Flags & 0x00FFFFFF;

                        // Retrieve the package for this entry
                        pPackage = (PMNDX_PACKAGE)Packages.ItemAt(nPackageIndex);
                        if (pPackage != NULL)
                        {
                            // Sanity check
                            assert(pPackage->nIndex == nPackageIndex);

                            // Merge the package name and file name
                            MakeFileName(szFileName, _countof(szFileName), pPackage, &Search);

                            // Insert the entry to the file tree
                            FileTree.InsertByName(pCKeyEntry, szFileName);
                        }
                    }

                    // Is this the last-in-group entry?
                    if (pRootEntry->Flags & MNDX_LAST_CKEY_ENTRY)
                        break;
                    pRootEntry++;
                }
            }
        }

        return dwErrCode;
    }

    //
    //  Helper functions
    //

    void MakeFileName(char * szBuffer, size_t cchBuffer, PMNDX_PACKAGE pPackage, TMndxSearch * pSearch)
    {
        char * szBufferEnd = szBuffer + cchBuffer - 1;

        // Buffer length check
        assert((pPackage->nLength + 1 + pSearch->cchFoundPath + 1) < cchBuffer);

        // Copy the package name
        if ((szBuffer + pPackage->nLength) < szBufferEnd)
        {
            memcpy(szBuffer, pPackage->szFileName, pPackage->nLength);
            szBuffer += pPackage->nLength;
        }

        // Append slash
        if ((szBuffer + 1) < szBufferEnd)
            *szBuffer++ = '/';

        // Append file name
        if ((szBuffer + pSearch->cchFoundPath) < szBufferEnd)
        {
            memcpy(szBuffer, pSearch->szFoundPath, pSearch->cchFoundPath);
            szBuffer += pSearch->cchFoundPath;
        }

        szBuffer[0] = 0;
    }

    protected:

    FILE_MNDX_INFO MndxInfo;

    PMNDX_CKEY_ENTRY * FileNameIndexToCKeyIndex;
    PMNDX_CKEY_ENTRY pCKeyEntries;
    CASC_ARRAY Packages;                        // Linear list of present packages
};

//-----------------------------------------------------------------------------
// Handler definition for MNDX root file

struct TRootHandler_MNDX : public TFileTreeRoot
{
    public:

    TRootHandler_MNDX() : TFileTreeRoot(0)
    {
        // MNDX supports file names and CKeys
        dwFeatures |= CASC_FEATURE_FILE_NAMES | CASC_FEATURE_ROOT_CKEY;
    }

    DWORD Load(TCascStorage * hs, const FILE_MNDX_HEADER & MndxHeader, LPBYTE pbRootFile, LPBYTE pbRootEnd)
    {
        TMndxHandler Handler;
        DWORD dwErrCode;

        // Load and parse the entire MNDX structure
        dwErrCode = Handler.Load(MndxHeader, pbRootFile, pbRootEnd);
        if (dwErrCode == ERROR_SUCCESS)
        {
            // Search all file names and insert them into the file tree
            dwErrCode = Handler.LoadFileNames(hs, FileTree);
        }

        return dwErrCode;
    }
};

//-----------------------------------------------------------------------------
// Public functions - MNDX info

DWORD RootHandler_CreateMNDX(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile)
{
    TRootHandler_MNDX * pRootHandler = NULL;
    FILE_MNDX_HEADER MndxHeader;
    LPBYTE pbRootEnd = pbRootFile + cbRootFile;
    DWORD dwErrCode = ERROR_BAD_FORMAT;

    // Verify the header of the ROOT file
    if(TMndxHandler::CaptureRootHeader(MndxHeader, pbRootFile, pbRootEnd) != NULL)
    {
        // Allocate the root handler object
        pRootHandler = new TRootHandler_MNDX();
        if(pRootHandler != NULL)
        {
            // Load the root directory. If load failed, we free the object
            dwErrCode = pRootHandler->Load(hs, MndxHeader, pbRootFile, pbRootEnd);
            if(dwErrCode != ERROR_SUCCESS)
            {
                delete pRootHandler;
                pRootHandler = NULL;
            }
        }
    }

    // Assign the root directory (or NULL) and return error
    hs->pRootHandler = pRootHandler;
    return dwErrCode;
}
