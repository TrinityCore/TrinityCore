/*****************************************************************************/
/* CascStructs.h                          Copyright (c) Ladislav Zezula 2019 */
/*---------------------------------------------------------------------------*/
/* On-disk structures for CASC storages                                      */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 28.04.19  1.00  Lad  The first version of CascStructs.h                   */
/*****************************************************************************/

#ifndef __CASC_STRUCTS_H__
#define __CASC_STRUCTS_H__

//-----------------------------------------------------------------------------
// Common definitions

#define CASC_INDEX_COUNT          0x10              // Number of index files
#define CASC_CKEY_SIZE            0x10              // Size of the content key
#define CASC_EKEY_SIZE            0x09              // Size of the encoded key
#define CASC_MAX_DATA_FILES      0x100              // Maximum number of data files

//-----------------------------------------------------------------------------
// The index files structures

#define FILE_INDEX_PAGE_SIZE    0x200               // Number of bytes in one page of EKey items

// Structure describing the 32-bit block size and 32-bit Jenkins hash of the block
typedef struct _BLOCK_SIZE_AND_HASH
{
    DWORD cbBlockSize;
    DWORD dwBlockHash;

} BLOCK_SIZE_AND_HASH, *PBLOCK_SIZE_AND_HASH;

// Checksum describing a block in the index file (v2)
typedef struct _FILE_INDEX_GUARDED_BLOCK
{
    DWORD BlockSize;
    DWORD BlockHash;

} FILE_INDEX_GUARDED_BLOCK, *PFILE_INDEX_GUARDED_BLOCK;

// Structure of the header of the index files version 1
typedef struct _FILE_INDEX_HEADER_V1
{
    USHORT IndexVersion;                            // Must be 0x05
    BYTE  BucketIndex;                              // The bucket index of this file; should be the same as the first byte of the hex filename. 
    BYTE  align_3;
    DWORD field_4;
    ULONGLONG field_8;
    ULONGLONG SegmentSize;                          // Size of one data segment (aka data.### file)
    BYTE  EncodedSizeLength;                        // Length, in bytes, of the EncodedSize in the EKey entry
    BYTE  StorageOffsetLength;                      // Length, in bytes, of the StorageOffset field in the EKey entry
    BYTE  EKeyLength;                               // Length of the encoded key (bytes)
    BYTE  FileOffsetBits;                           // Number of bits of the archive file offset in StorageOffset field. Rest is data segment index
    DWORD EKeyCount1;
    DWORD EKeyCount2;
    DWORD KeysHash1;
    DWORD KeysHash2;
    DWORD HeaderHash;
} FILE_INDEX_HEADER_V1, *PFILE_INDEX_HEADER_V1;

typedef struct _FILE_INDEX_HEADER_V2
{
    USHORT IndexVersion;                            // Must be 0x07
    BYTE   BucketIndex;                             // The bucket index of this file; should be the same as the first byte of the hex filename. 
    BYTE   ExtraBytes;                              // Unknown; must be 0
    BYTE   EncodedSizeLength;                       // Length, in bytes, of the EncodedSize in the EKey entry
    BYTE   StorageOffsetLength;                     // Length, in bytes, of the StorageOffset field in the EKey entry
    BYTE   EKeyLength;                              // Length of the encoded key (bytes)
    BYTE   FileOffsetBits;                          // Number of bits of the archive file offset in StorageOffset field. Rest is data segment index
    ULONGLONG SegmentSize;                          // Size of one data segment (aka data.### file)

} FILE_INDEX_HEADER_V2, *PFILE_INDEX_HEADER_V2;

// The EKey entry from the ".idx" files. Note that the lengths are optional and controlled by the FILE_INDEX_HEADER_Vx
typedef struct _FILE_EKEY_ENTRY
{
    BYTE EKey[CASC_EKEY_SIZE];                      // The first 9 bytes of the encoded key
    BYTE FileOffsetBE[5];                           // Index of data file and offset within (big endian).
    BYTE EncodedSize[4];                            // Encoded size (big endian). This is the size of encoded header, all file frame headers and all file frames
} FILE_EKEY_ENTRY, *PFILE_EKEY_ENTRY;

//-----------------------------------------------------------------------------
// The archive index (md5.index) files structures
// https://wowdev.wiki/TACT#CDN_File_Organization

template <int CHKSUM_LENGTH>
struct FILE_INDEX_FOOTER
{
    BYTE TocHash[MD5_HASH_SIZE];                    // Client tries to read with 0x10, then backs off in size when smaller
    BYTE Version;                                   // Version of the index header
    BYTE Reserved[2];                               // Length, in bytes, of the file offset field
    BYTE PageSizeKB;                                // Length, in kilobytes, of the index page
    BYTE OffsetBytes;                               // Normally 4 for archive indices, 6 for group indices, and 0 for loose file indices
    BYTE SizeBytes;                                 // Normally 4
    BYTE EKeyLength;                                // Normally 16
    BYTE FooterHashBytes;                           // Normally 8, <= 0x10
    BYTE ElementCount[4];                           // BigEndian in _old_ versions (e.g. 18179)
    BYTE FooterHash[CHKSUM_LENGTH];
};

//-----------------------------------------------------------------------------
// The ENCODING manifest structures
//
// The ENCODING file is in the form of:
// * File header. Fixed length.
// * Encoding Specification (ESpec) in the string form. Length is stored in FILE_ENCODING_HEADER::ESpecBlockSize
// https://wowdev.wiki/CASC#Encoding
// https://wowdev.wiki/TACT#Encoding_table
//

#define FILE_MAGIC_ENCODING 0x4E45                  // 'EN'

// File header of the ENCODING manifest
typedef struct _FILE_ENCODING_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_ENCODING ('EN')
    BYTE Version;                                   // Expected to be 1 by CascLib
    BYTE CKeyLength;                                // The content key length in ENCODING file. Usually 0x10
    BYTE EKeyLength;                                // The encoded key length in ENCODING file. Usually 0x10
    BYTE CKeyPageSize[2];                           // Size of the CKey page, in KB (big-endian)
    BYTE EKeyPageSize[2];                           // Size of the EKey page, in KB (big-endian)
    BYTE CKeyPageCount[4];                          // Number of CKey pages in the table (big endian)
    BYTE EKeyPageCount[4];                          // Number of EKey pages in the table (big endian)
    BYTE field_11;                                  // Asserted to be zero by the agent
    BYTE ESpecBlockSize[4];                         // Size of the ESpec string block

} FILE_ENCODING_HEADER, *PFILE_ENCODING_HEADER;

// Page header of the ENCODING manifest
typedef struct _FILE_CKEY_PAGE
{
    BYTE FirstKey[MD5_HASH_SIZE];                   // The first CKey/EKey in the segment
    BYTE SegmentHash[MD5_HASH_SIZE];                // MD5 hash of the entire segment

} FILE_CKEY_PAGE, *PFILE_CKEY_PAGE;

// Single entry in the page
typedef struct _FILE_CKEY_ENTRY
{
    USHORT EKeyCount;                               // Number of EKeys
    BYTE ContentSize[4];                            // Content file size (big endian)
    BYTE CKey[CASC_CKEY_SIZE];                      // Content key. This is MD5 of the file content
    BYTE EKey[CASC_CKEY_SIZE];                      // Encoded key. This is (trimmed) MD5 hash of the file header, containing MD5 hashes of all the logical blocks of the file

} FILE_CKEY_ENTRY, *PFILE_CKEY_ENTRY;

typedef struct _FILE_ESPEC_ENTRY
{
    BYTE ESpecKey[MD5_HASH_SIZE];                   // The ESpec key of the file
    BYTE ESpecIndexBE[4];                           // Index of ESPEC entry, assuming zero-terminated strings (big endian)
    BYTE FileSizeBE[5];                             // Size of the encoded version of the file (big endian)

} FILE_ESPEC_ENTRY, *PFILE_ESPEC_ENTRY;

//-----------------------------------------------------------------------------
// The DOWNLOAD manifest structures
//
// See https://wowdev.wiki/TACT#Download_manifest
//

#define FILE_MAGIC_DOWNLOAD 0x4C44                  // 'DL'

// File header of the DOWNLOAD manifest
typedef struct _FILE_DOWNLOAD_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_DOWNLOAD ('DL')
    BYTE Version;                                   // Expected to be 1 by CascLib
    BYTE EKeyLength;                                // The content key length in DOWNLOAD file. Expected to be 0x10
    BYTE EntryHasChecksum;                          // If nonzero, then the entry has checksum.
    BYTE EntryCount[4];                             // Number of entries (big-endian)
    BYTE TagCount[2];                               // Number of tag entries (big endian)

    // Version 2 or newer
    BYTE FlagByteSize;                              // Number of flag bytes

    // Verion 3 or newer
    BYTE BasePriority;
    BYTE Unknown2[3];

} FILE_DOWNLOAD_HEADER, *PFILE_DOWNLOAD_HEADER;

typedef struct _FILE_DOWNLOAD_ENTRY
{
    BYTE EKey[MD5_HASH_SIZE];                       // Encoding key (variable length)
    BYTE FileSize[5];                               // File size
    BYTE Priority;

    // DWORD Checksum [optional]
    // BYTE Flags;

} FILE_DOWNLOAD_ENTRY, *PFILE_DOWNLOAD_ENTRY;

//-----------------------------------------------------------------------------
// The INSTALL manifest structures
//
// See https://wowdev.wiki/TACT#Install_manifest
//

#define FILE_MAGIC_INSTALL 0x4E49                   // 'IN'

// File header of the INSTALL manifest
typedef struct _FILE_INSTALL_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_INSTALL ('DL')
    BYTE Version;                                   // Expected to be 1 by CascLib
    BYTE EKeyLength;                                // The content key length in INSTALL file. Expected to be 0x10
    BYTE TagCount[2];                               // Number of tag entries (big endian)
    BYTE EntryCount[4];                             // Number of entries (big-endian)

} FILE_INSTALL_HEADER, *PFILE_INSTALL_HEADER;

//-----------------------------------------------------------------------------
// Data file structures

#define BLTE_HEADER_SIGNATURE   0x45544C42          // 'BLTE' header in the data files
#define BLTE_HEADER_DELTA       0x1E                // Distance of BLTE header from begin of the header area
#define MAX_ENCODED_HEADER      0x1000              // Starting size for the frame headers

typedef struct _BLTE_HEADER
{
    BYTE  Signature[4];                             // Must be "BLTE"
    BYTE  HeaderSize[4];                            // Header size in bytes (big endian)
    BYTE  MustBe0F;                                 // Must be 0x0F. Optional, only if HeaderSize != 0
    BYTE  FrameCount[3];                            // Frame count (big endian). Optional, only if HeaderSize != 0
} BLTE_HEADER, *PBLTE_HEADER;

typedef struct _BLTE_ENCODED_HEADER
{
    // Header span.
    ENCODED_KEY EKey;                               // Encoded key of the data beginning with "BLTE" (byte-reversed)
    DWORD EncodedSize;                              // Encoded size of the data data beginning with "BLTE" (little endian)
    BYTE  field_14;                                 // Seems to be 1 if the header span has no data
    BYTE  field_15;                                 // Hardcoded to zero (Agent.exe 2.15.0.6296: 01370000->0148E2AA)
    BYTE  JenkinsHash[4];                           // Jenkins hash (hashlittle2) of the preceding fields (EKey + EncodedSize + field_14 + field_15) (little endian)
    BYTE  Checksum[4];                              // Checksum of the previous part. See "VerifyHeaderSpan()" for more information.

    // BLTE header. Always present.
    BYTE  Signature[4];                             // Must be "BLTE"
    BYTE  HeaderSize[4];                            // Header size in bytes (big endian)
    BYTE  MustBe0F;                                 // Must be 0x0F. Optional, only if HeaderSize != 0
    BYTE  FrameCount[3];                            // Frame count (big endian). Optional, only if HeaderSize != 0
} BLTE_ENCODED_HEADER, *PBLTE_ENCODED_HEADER;

typedef struct _BLTE_FRAME
{
    BYTE EncodedSize[4];                            // Encoded frame size (big endian)
    BYTE ContentSize[4];                            // Content frame size (big endian)
    CONTENT_KEY FrameHash;                          // Hash of the encoded frame

} BLTE_FRAME, *PBLTE_FRAME;

#endif  // __CASC_STRUCTS_H__

