/*****************************************************************************/
/* StormLib.h                        Copyright (c) Ladislav Zezula 1999-2010 */
/*---------------------------------------------------------------------------*/
/* StormLib library v 7.02                                                   */
/*                                                                           */
/* Author : Ladislav Zezula                                                  */
/* E-mail : ladik@zezula.net                                                 */
/* WWW    : http://www.zezula.net                                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* xx.xx.99  1.00  Lad  Created                                              */
/* 24.03.03  2.50  Lad  Version 2.50                                         */
/* 02.04.03  3.00  Lad  Version 3.00 with compression                        */
/* 11.04.03  3.01  Lad  Renamed to StormLib.h for compatibility with         */
/*                      original headers for Storm.dll                       */
/* 10.05.03  3.02  Lad  Added Pkware DCL compression                         */
/* 26.05.03  4.00  Lad  Completed all compressions                           */
/* 18.06.03  4.01  Lad  Added SFileSetFileLocale                             */
/*                      Added SFileExtractFile                               */
/* 26.07.03  4.02  Lad  Implemented nameless rename and delete               */
/* 26.07.03  4.03  Lad  Added support for protected MPQs                     */
/* 28.08.03  4.10  Lad  Fixed bugs that caused StormLib incorrectly work     */
/*                      with Diablo I savegames and with files having full   */
/*                      hash table                                           */
/* 08.12.03  4.11  DCH  Fixed bug in reading file sector larger than 0x1000  */
/*                      on certain files.                                    */
/*                      Fixed bug in AddFile with MPQ_FILE_REPLACE_EXISTING  */
/*                      (Thanx Daniel Chiamarello, dchiamarello@madvawes.com)*/
/* 21.12.03  4.50  Lad  Completed port for Mac                               */
/*                      Fixed bug in compacting (if fsize is mul of 0x1000)  */
/*                      Fixed bug in SCompCompress                           */
/* 27.05.04  4.51  Lad  Changed memory management from new/delete to our     */
/*                      own macros                                           */
/* 22.06.04  4.60  Lad  Optimized search. Support for multiple listfiles.    */
/* 30.09.04  4.61  Lad  Fixed some bugs (Aaargh !!!)                         */
/*                      Correctly works if HashTableSize > BlockTableSize    */
/* 29.12.04  4.70  Lad  Fixed compatibility problem with MPQs from WoW       */
/* 14.07.05  5.00  Lad  Added the BZLIB compression support                  */
/*                      Added suport of files stored as single unit          */
/* 17.04.06  5.01  Lad  Converted to MS Visual Studio 8.0                    */
/*                      Fixed issue with protected Warcraft 3 protected maps */
/* 15.05.06  5.02  Lad  Fixed issue with WoW 1.10+                           */
/* 07.09.06  5.10  Lad  Fixed processing files longer than 2GB               */
/* 22.11.06  6.00  Lad  Support for MPQ archives V2                          */
/* 12.06.07  6.10  Lad  Support for (attributes) file                        */
/* 10.09.07  6.12  Lad  Support for MPQs protected by corrupting hash table  */
/* 03.12.07  6.13  Lad  Support for MPQs with hash tbl size > block tbl size */
/* 07.04.08  6.20  Lad  Added SFileFlushArchive                              */
/* 09.04.08        Lad  Removed FilePointer variable from MPQ handle         */
/*                      structure, as it caused more problems than benefits  */
/* 12.05.08  6.22  Lad  Support for w3xMaster map protector                  */
/* 05.10.08  6.23  Lad  Support for protectors who set negative values in    */
/*                      the table of file blocks                             */
/* 26.05.09  6.24  Lad  Fixed search for multiple lang files with deleted    */
/*                      entries                                              */
/* 03.09.09  6.25  Lad  Fixed decompression bug in huffmann decompression    */
/* 22.03.10  6.50  Lad  New compressions in Starcraft II (LZMA, sparse)      */
/*                      Fixed compacting MPQs that contain single unit files */
/* 26.04.10  7.00  Lad  Major rewrite                                        */
/* 08.06.10  7.10  Lad  Support for partial MPQs                             */
/* 08.07.10  7.11  Lad  Support for MPQs v 3.0                               */
/* 20.08.10  7.20  Lad  Support for opening multiple MPQs in patch mode      */
/* 20.09.10  8.00  Lad  MPQs v 4, HET and BET tables                         */
/* 07.01.11  8.01  Lad  Write support for MPQs v 3 and 4                     */
/* 15.09.11  8.04  Lad  Bug fixes, testing for Diablo III MPQs               */
/* 26.04.12  8.10  Lad  Support for data map, added SFileGetArchiveBitmap    */
/*****************************************************************************/

#ifndef __STORMLIB_H__
#define __STORMLIB_H__

#ifdef _MSC_VER
#pragma warning(disable:4668)       // 'XXX' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif' 
#pragma warning(disable:4820)       // 'XXX' : '2' bytes padding added after data member 'XXX::yyy'
#endif                                             

#include "StormPort.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Use the apropriate library
//
// The library type is encoded in the library name as the following
// StormLibXYZ.lib
// 
//  X - D for Debug version, R for Release version
//  Y - A for ANSI version, U for Unicode version
//  Z - S for static-linked CRT library, D for multithreaded DLL CRT library
//

#if 0 && defined(_MSC_VER) && !defined(__STORMLIB_SELF__)
  
  #ifdef _DEBUG                                 // DEBUG VERSIONS
    #ifndef _UNICODE                            
      #ifdef _DLL                               
        #pragma comment(lib, "StormLibDAD.lib") // Debug Ansi CRT-DLL version
      #else        
        #pragma comment(lib, "StormLibDAS.lib") // Debug Ansi CRT-LIB version
      #endif
    #else
      #ifdef _DLL                               
        #pragma comment(lib, "StormLibDUD.lib") // Debug Unicode CRT-DLL version
      #else        
        #pragma comment(lib, "StormLibDUS.lib") // Debug Unicode CRT-LIB version
      #endif
    #endif
  #else                                         // RELEASE VERSIONS
    #ifndef _UNICODE                            
      #ifdef _DLL
        #pragma comment(lib, "StormLibRAD.lib") // Release Ansi CRT-DLL version
      #else        
        #pragma comment(lib, "StormLibRAS.lib") // Release Ansi CRT-LIB version
      #endif
    #else
      #ifdef _DLL
        #pragma comment(lib, "StormLibRUD.lib") // Release Unicode CRT-DLL version
      #else        
        #pragma comment(lib, "StormLibRUS.lib") // Release Unicode CRT-LIB version
      #endif
    #endif
  #endif

#endif

//-----------------------------------------------------------------------------
// Defines

#define ID_MPQ                      0x1A51504D  // MPQ archive header ID ('MPQ\x1A')
#define ID_MPQ_USERDATA             0x1B51504D  // MPQ userdata entry ('MPQ\x1B')

#define ERROR_AVI_FILE                   10000  // No MPQ file, but AVI file.
#define ERROR_UNKNOWN_FILE_KEY           10001  // Returned by SFileReadFile when can't find file key
#define ERROR_CHECKSUM_ERROR             10002  // Returned by SFileReadFile when sector CRC doesn't match
#define ERROR_INTERNAL_FILE              10003  // The given operation is not allowed on internal file
#define ERROR_BASE_FILE_MISSING          10004  // The file is present as incremental patch file, but base file is missing
#define ERROR_MARKED_FOR_DELETE          10005  // The file was marked as "deleted" in the MPQ

// Values for SFileCreateArchive
#define HASH_TABLE_SIZE_MIN         0x00000004  // Minimum acceptable hash table size
#define HASH_TABLE_SIZE_DEFAULT     0x00001000  // Default hash table size for empty MPQs
#define HASH_TABLE_SIZE_MAX         0x00080000  // Maximum acceptable hash table size

#define HASH_ENTRY_DELETED          0xFFFFFFFE  // Block index for deleted entry in the hash table
#define HASH_ENTRY_FREE             0xFFFFFFFF  // Block index for free entry in the hash table

#define HET_ENTRY_DELETED                 0x80  // HET hash value for a deleted entry
#define HET_ENTRY_FREE                    0x00  // HET hash value for free entry

#define HASH_STATE_SIZE                   0x60  // Size of LibTomCrypt's hash_state structure

#define MPQ_PATCH_PREFIX_LEN              0x20  // Maximum length of the patch prefix

// Values for SFileOpenArchive
#define SFILE_OPEN_HARD_DISK_FILE            2  // Open the archive on HDD
#define SFILE_OPEN_CDROM_FILE                3  // Open the archive only if it is on CDROM

// Values for SFileOpenFile
#define SFILE_OPEN_FROM_MPQ         0x00000000  // Open the file from the MPQ archive
#define SFILE_OPEN_PATCHED_FILE     0x00000001  // Open the file from the MPQ archive
#define SFILE_OPEN_ANY_LOCALE       0xFFFFFFFE  // Reserved for StormLib internal use
#define SFILE_OPEN_LOCAL_FILE       0xFFFFFFFF  // Open a local file

// Flags for TMPQArchive::dwFlags
#define MPQ_FLAG_READ_ONLY          0x00000001  // If set, the MPQ has been open for read-only access
#define MPQ_FLAG_CHANGED            0x00000002  // If set, the MPQ tables have been changed
#define MPQ_FLAG_PROTECTED          0x00000004  // Set on protected MPQs (like W3M maps)
#define MPQ_FLAG_CHECK_SECTOR_CRC   0x00000008  // Checking sector CRC when reading files
#define MPQ_FLAG_NEED_FIX_SIZE      0x00000010  // Used during opening the archive
#define MPQ_FLAG_INV_LISTFILE       0x00000020  // If set, it means that the (listfile) has been invalidated
#define MPQ_FLAG_INV_ATTRIBUTES     0x00000040  // If set, it means that the (attributes) has been invalidated

// Return value for SFileGetFileSize and SFileSetFilePointer
#define SFILE_INVALID_SIZE          0xFFFFFFFF
#define SFILE_INVALID_POS           0xFFFFFFFF
#define SFILE_INVALID_ATTRIBUTES    0xFFFFFFFF

// Flags for SFileAddFile
#define MPQ_FILE_IMPLODE            0x00000100  // Implode method (By PKWARE Data Compression Library)
#define MPQ_FILE_COMPRESS           0x00000200  // Compress methods (By multiple methods)
#define MPQ_FILE_COMPRESSED         0x0000FF00  // File is compressed
#define MPQ_FILE_ENCRYPTED          0x00010000  // Indicates whether file is encrypted 
#define MPQ_FILE_FIX_KEY            0x00020000  // File decryption key has to be fixed
#define MPQ_FILE_PATCH_FILE         0x00100000  // The file is a patch file. Raw file data begin with TPatchInfo structure
#define MPQ_FILE_SINGLE_UNIT        0x01000000  // File is stored as a single unit, rather than split into sectors (Thx, Quantam)
#define MPQ_FILE_DELETE_MARKER      0x02000000  // File is a deletion marker. Used in MPQ patches, indicating that the file no longer exists.
#define MPQ_FILE_SECTOR_CRC         0x04000000  // File has checksums for each sector.
                                                // Ignored if file is not compressed or imploded.
#define MPQ_FILE_EXISTS             0x80000000  // Set if file exists, reset when the file was deleted
#define MPQ_FILE_REPLACEEXISTING    0x80000000  // Replace when the file exist (SFileAddFile)

#define MPQ_FILE_VALID_FLAGS     (MPQ_FILE_IMPLODE       |  \
                                  MPQ_FILE_COMPRESS      |  \
                                  MPQ_FILE_ENCRYPTED     |  \
                                  MPQ_FILE_FIX_KEY       |  \
                                  MPQ_FILE_PATCH_FILE    |  \
                                  MPQ_FILE_SINGLE_UNIT   |  \
                                  MPQ_FILE_DELETE_MARKER |  \
                                  MPQ_FILE_SECTOR_CRC    |  \
                                  MPQ_FILE_EXISTS)

// Compression types for multiple compressions
#define MPQ_COMPRESSION_HUFFMANN          0x01  // Huffmann compression (used on WAVE files only)
#define MPQ_COMPRESSION_ZLIB              0x02  // ZLIB compression
#define MPQ_COMPRESSION_PKWARE            0x08  // PKWARE DCL compression
#define MPQ_COMPRESSION_BZIP2             0x10  // BZIP2 compression (added in Warcraft III)
#define MPQ_COMPRESSION_SPARSE            0x20  // Sparse compression (added in Starcraft 2)
#define MPQ_COMPRESSION_ADPCM_MONO        0x40  // IMA ADPCM compression (mono)
#define MPQ_COMPRESSION_ADPCM_STEREO      0x80  // IMA ADPCM compression (stereo)
#define MPQ_COMPRESSION_LZMA              0x12  // LZMA compression. Added in Starcraft 2. This value is NOT a combination of flags.
#define MPQ_COMPRESSION_NEXT_SAME   0xFFFFFFFF  // Same compression

// Constants for SFileAddWave
#define MPQ_WAVE_QUALITY_HIGH                0  // Best quality, the worst compression
#define MPQ_WAVE_QUALITY_MEDIUM              1  // Medium quality, medium compression
#define MPQ_WAVE_QUALITY_LOW                 2  // Low quality, the best compression

// Signatures for HET and BET table
#define HET_TABLE_SIGNATURE         0x1A544548  // 'HET\x1a'
#define BET_TABLE_SIGNATURE         0x1A544542  // 'BET\x1a'

// Decryption keys for MPQ tables
#define MPQ_KEY_HASH_TABLE          0xC3AF3770  // Obtained by HashString("(hash table)", MPQ_HASH_FILE_KEY)
#define MPQ_KEY_BLOCK_TABLE         0xEC83B3A3  // Obtained by HashString("(block table)", MPQ_HASH_FILE_KEY)

// Block map defines
#define MPQ_DATA_BITMAP_SIGNATURE   0x33767470  // Signature of the MPQ data bitmap ('ptv3')

// Constants for SFileGetFileInfo
#define SFILE_INFO_ARCHIVE_NAME              1  // MPQ size (value from header)
#define SFILE_INFO_ARCHIVE_SIZE              2  // MPQ size (value from header)
#define SFILE_INFO_MAX_FILE_COUNT            3  // Max number of files in the MPQ
#define SFILE_INFO_HASH_TABLE_SIZE           4  // Size of hash table, in entries
#define SFILE_INFO_BLOCK_TABLE_SIZE          5  // Number of entries in the block table
#define SFILE_INFO_SECTOR_SIZE               6  // Size of file sector (in bytes)
#define SFILE_INFO_HASH_TABLE                7  // Pointer to Hash table (TMPQHash *)
#define SFILE_INFO_BLOCK_TABLE               8  // Pointer to Block Table (TMPQBlock *)
#define SFILE_INFO_NUM_FILES                 9  // Real number of files within archive
#define SFILE_INFO_STREAM_FLAGS             10  // Stream flags for the MPQ. See STREAM_FLAG_XXX
#define SFILE_INFO_IS_READ_ONLY             11  // TRUE of the MPQ was open as read only
//------                                 
#define SFILE_INFO_HASH_INDEX              100  // Hash index of file in MPQ
#define SFILE_INFO_CODENAME1               101  // The first codename of the file
#define SFILE_INFO_CODENAME2               102  // The second codename of the file
#define SFILE_INFO_LOCALEID                103  // Locale ID of file in MPQ
#define SFILE_INFO_BLOCKINDEX              104  // Index to Block Table
#define SFILE_INFO_FILE_SIZE               105  // Original file size (from the block table)
#define SFILE_INFO_COMPRESSED_SIZE         106  // Compressed file size (from the block table)
#define SFILE_INFO_FLAGS                   107  // File flags
#define SFILE_INFO_POSITION                108  // File position within archive
#define SFILE_INFO_KEY                     109  // File decryption key
#define SFILE_INFO_KEY_UNFIXED             110  // Decryption key not fixed to file pos and size
#define SFILE_INFO_FILETIME                111  // TMPQFileTime
#define SFILE_INFO_PATCH_CHAIN             112  // Chain of patches

#define LISTFILE_NAME             "(listfile)"  // Name of internal listfile
#define SIGNATURE_NAME           "(signature)"  // Name of internal signature
#define ATTRIBUTES_NAME         "(attributes)"  // Name of internal attributes file
#define PATCH_METADATA_NAME "(patch_metadata)"

#define STORMLIB_VERSION                0x080A  // Current version of StormLib (8.10)
#define STORMLIB_VERSION_STRING         "8.10"

#define MPQ_FORMAT_VERSION_1                 0  // Up to The Burning Crusade
#define MPQ_FORMAT_VERSION_2                 1  // The Burning Crusade and newer 
#define MPQ_FORMAT_VERSION_3                 2  // WoW Cataclysm Beta
#define MPQ_FORMAT_VERSION_4                 3  // WoW Cataclysm and newer

// Flags for MPQ attributes
#define MPQ_ATTRIBUTE_CRC32         0x00000001  // The "(attributes)" contains CRC32 for each file
#define MPQ_ATTRIBUTE_FILETIME      0x00000002  // The "(attributes)" contains file time for each file
#define MPQ_ATTRIBUTE_MD5           0x00000004  // The "(attributes)" contains MD5 for each file
#define MPQ_ATTRIBUTE_PATCH_BIT     0x00000008  // The "(attributes)" contains a patch bit for each file
#define MPQ_ATTRIBUTE_ALL           0x0000000F  // Summary mask

#define MPQ_ATTRIBUTES_V1                  100  // (attributes) format version 1.00

// Flags for SFileOpenArchive
#define BASE_PROVIDER_FILE          0x00000000  // Base data source is a file
#define BASE_PROVIDER_MAP           0x00000001  // Base data source is memory-mapped file
#define BASE_PROVIDER_HTTP          0x00000002  // Base data source is a file on web server
#define BASE_PROVIDER_MASK          0x0000000F  // Mask for base provider value

#define STREAM_PROVIDER_LINEAR      0x00000000  // Stream is linear with no offset mapping
#define STREAM_PROVIDER_PARTIAL     0x00000010  // Stream is partial file (.part)
#define STREAM_PROVIDER_ENCRYPTED   0x00000020  // Stream is an encrypted MPQ
#define STREAM_PROVIDER_MASK        0x000000F0  // Mask for stream provider value

#define STREAM_FLAG_READ_ONLY       0x00000100  // Stream is read only
#define STREAM_FLAG_WRITE_SHARE     0x00000200  // Allow write sharing when open for write
#define STREAM_FLAG_MASK            0x0000FF00  // Mask for stream flags
#define STREAM_OPTIONS_MASK         0x0000FFFF  // Mask for all stream options

#define MPQ_OPEN_NO_LISTFILE        0x00010000  // Don't load the internal listfile
#define MPQ_OPEN_NO_ATTRIBUTES      0x00020000  // Don't open the attributes
#define MPQ_OPEN_FORCE_MPQ_V1       0x00040000  // Always open the archive as MPQ v 1.00, ignore the "wFormatVersion" variable in the header
#define MPQ_OPEN_CHECK_SECTOR_CRC   0x00080000  // On files with MPQ_FILE_SECTOR_CRC, the CRC will be checked when reading file

// Deprecated
#define MPQ_OPEN_READ_ONLY          STREAM_FLAG_READ_ONLY
#define MPQ_OPEN_ENCRYPTED          STREAM_PROVIDER_ENCRYPTED

// Flags for SFileCreateArchive
#define MPQ_CREATE_ATTRIBUTES       0x00100000  // Also add the (attributes) file
#define MPQ_CREATE_ARCHIVE_V1       0x00000000  // Creates archive of version 1 (size up to 4GB)
#define MPQ_CREATE_ARCHIVE_V2       0x01000000  // Creates archive of version 2 (larger than 4 GB)
#define MPQ_CREATE_ARCHIVE_V3       0x02000000  // Creates archive of version 3
#define MPQ_CREATE_ARCHIVE_V4       0x03000000  // Creates archive of version 4
#define MPQ_CREATE_ARCHIVE_VMASK    0x0F000000  // Mask for archive version

#define FLAGS_TO_FORMAT_SHIFT               24  // (MPQ_CREATE_ARCHIVE_V4 >> FLAGS_TO_FORMAT_SHIFT) => MPQ_FORMAT_VERSION_4

// Flags for SFileVerifyFile
#define SFILE_VERIFY_SECTOR_CRC     0x00000001  // Verify sector checksum for the file, if available
#define SFILE_VERIFY_FILE_CRC       0x00000002  // Verify file CRC, if available
#define SFILE_VERIFY_FILE_MD5       0x00000004  // Verify file MD5, if available
#define SFILE_VERIFY_RAW_MD5        0x00000008  // Verify raw file MD5, if available
#define SFILE_VERIFY_ALL            0x0000000F  // Verify every checksum possible

// Return values for SFileVerifyFile
#define VERIFY_OPEN_ERROR               0x0001  // Failed to open the file
#define VERIFY_READ_ERROR               0x0002  // Failed to read all data from the file
#define VERIFY_FILE_HAS_SECTOR_CRC      0x0004  // File has sector CRC
#define VERIFY_FILE_SECTOR_CRC_ERROR    0x0008  // Sector CRC check failed
#define VERIFY_FILE_HAS_CHECKSUM        0x0010  // File has CRC32
#define VERIFY_FILE_CHECKSUM_ERROR      0x0020  // CRC32 check failed
#define VERIFY_FILE_HAS_MD5             0x0040  // File has data MD5
#define VERIFY_FILE_MD5_ERROR           0x0080  // MD5 check failed
#define VERIFY_FILE_HAS_RAW_MD5         0x0100  // File has raw data MD5
#define VERIFY_FILE_RAW_MD5_ERROR       0x0200  // Raw MD5 check failed
#define VERIFY_FILE_ERROR_MASK      (VERIFY_OPEN_ERROR | VERIFY_READ_ERROR | VERIFY_FILE_SECTOR_CRC_ERROR | VERIFY_FILE_CHECKSUM_ERROR | VERIFY_FILE_MD5_ERROR | VERIFY_FILE_RAW_MD5_ERROR)

// Flags for SFileVerifyRawData (for MPQs version 4.0 or higher)
#define SFILE_VERIFY_MPQ_HEADER         0x0001  // Verify raw MPQ header
#define SFILE_VERIFY_HET_TABLE          0x0002  // Verify raw data of the HET table
#define SFILE_VERIFY_BET_TABLE          0x0003  // Verify raw data of the BET table
#define SFILE_VERIFY_HASH_TABLE         0x0004  // Verify raw data of the hash table
#define SFILE_VERIFY_BLOCK_TABLE        0x0005  // Verify raw data of the block table
#define SFILE_VERIFY_HIBLOCK_TABLE      0x0006  // Verify raw data of the hi-block table
#define SFILE_VERIFY_FILE               0x0007  // Verify raw data of a file

// Return values for SFileVerifyArchive
#define ERROR_NO_SIGNATURE                   0  // There is no signature in the MPQ
#define ERROR_VERIFY_FAILED                  1  // There was an error during verifying signature (like no memory)
#define ERROR_WEAK_SIGNATURE_OK              2  // There is a weak signature and sign check passed
#define ERROR_WEAK_SIGNATURE_ERROR           3  // There is a weak signature but sign check failed
#define ERROR_STRONG_SIGNATURE_OK            4  // There is a strong signature and sign check passed
#define ERROR_STRONG_SIGNATURE_ERROR         5  // There is a strong signature but sign check failed
                                           
#ifndef MD5_DIGEST_SIZE
#define MD5_DIGEST_SIZE                   0x10
#endif

#ifndef SHA1_DIGEST_SIZE
#define SHA1_DIGEST_SIZE                  0x14  // 160 bits
#endif

#ifndef LANG_NEUTRAL
#define LANG_NEUTRAL                      0x00  // Neutral locale
#endif

//-----------------------------------------------------------------------------
// Callback functions

// Values for compact callback
#define CCB_CHECKING_FILES                   1  // Checking archive (dwParam1 = current, dwParam2 = total)
#define CCB_CHECKING_HASH_TABLE              2  // Checking hash table (dwParam1 = current, dwParam2 = total)
#define CCB_COPYING_NON_MPQ_DATA             3  // Copying non-MPQ data: No params used
#define CCB_COMPACTING_FILES                 4  // Compacting archive (dwParam1 = current, dwParam2 = total)
#define CCB_CLOSING_ARCHIVE                  5  // Closing archive: No params used
                                      
typedef void (WINAPI * SFILE_ADDFILE_CALLBACK)(void * pvUserData, DWORD dwBytesWritten, DWORD dwTotalBytes, bool bFinalCall);
typedef void (WINAPI * SFILE_COMPACT_CALLBACK)(void * pvUserData, DWORD dwWorkType, ULONGLONG BytesProcessed, ULONGLONG TotalBytes);

struct TFileStream;

//-----------------------------------------------------------------------------
// Structure for bit arrays used for HET and BET tables

struct TBitArray
{
    void GetBits(unsigned int nBitPosition, unsigned int nBitLength, void * pvBuffer, int nResultSize);
    void SetBits(unsigned int nBitPosition, unsigned int nBitLength, void * pvBuffer, int nResultSize);

    DWORD NumberOfBits;                         // Total number of bits that are available
    BYTE Elements[1];                           // Array of elements (variable length)
};

// Structure for file bitmap. Used by SFileGetArchiveBitmap
struct TFileBitmap
{
    ULONGLONG StartOffset;                      // Starting offset of the file, covered by bitmap
    ULONGLONG EndOffset;                        // Ending offset of the file, covered by bitmap
    DWORD IsComplete;                           // If nonzero, no blocks are missing
    DWORD BitmapSize;                           // Size of the file bitmap (in bytes)
    DWORD BlockSize;                            // Size of one block, in bytes
    DWORD Reserved;                             // Alignment

    // Followed by file bitmap (variable length), array of BYTEs)
};

//-----------------------------------------------------------------------------
// Structures related to MPQ format
//
// Note: All structures in this header file are supposed to remain private
// to StormLib. The structures may (and will) change over time, as the MPQ
// file format evolves. Programmers directly using these structures need to
// be aware of this. And the last, but not least, NEVER do any modifications
// to those structures directly, always use SFile* functions.
//

#define MPQ_HEADER_SIZE_V1    0x20
#define MPQ_HEADER_SIZE_V2    0x2C
#define MPQ_HEADER_SIZE_V3    0x44
#define MPQ_HEADER_SIZE_V4    0xD0

struct TMPQUserData
{
    // The ID_MPQ_USERDATA ('MPQ\x1B') signature
    DWORD dwID;

    // Maximum size of the user data
    DWORD cbUserDataSize;

    // Offset of the MPQ header, relative to the begin of this header
    DWORD dwHeaderOffs;

    // Appears to be size of user data header (Starcraft II maps)
    DWORD cbUserDataHeader;
};

// MPQ file header
//
// We have to make sure that the header is packed OK.
// Reason: A 64-bit integer at the beginning of 3.0 part,
// which is offset 0x2C
#pragma pack(push, 1)
struct TMPQHeader
{
    // The ID_MPQ ('MPQ\x1A') signature
    DWORD dwID;                         

    // Size of the archive header
    DWORD dwHeaderSize;                   

    // 32-bit size of MPQ archive
    // This field is deprecated in the Burning Crusade MoPaQ format, and the size of the archive
    // is calculated as the size from the beginning of the archive to the end of the hash table,
    // block table, or hi-block table (whichever is largest).
    DWORD dwArchiveSize;

    // 0 = Format 1 (up to The Burning Crusade)
    // 1 = Format 2 (The Burning Crusade and newer)
    // 2 = Format 3 (WoW - Cataclysm beta or newer)
    // 3 = Format 4 (WoW - Cataclysm beta or newer)
    USHORT wFormatVersion;

    // Power of two exponent specifying the number of 512-byte disk sectors in each file sector
    // in the archive. The size of each file sector in the archive is 512 * 2 ^ wSectorSize.
    USHORT wSectorSize;

    // Offset to the beginning of the hash table, relative to the beginning of the archive.
    DWORD dwHashTablePos;
    
    // Offset to the beginning of the block table, relative to the beginning of the archive.
    DWORD dwBlockTablePos;
    
    // Number of entries in the hash table. Must be a power of two, and must be less than 2^16 for
    // the original MoPaQ format, or less than 2^20 for the Burning Crusade format.
    DWORD dwHashTableSize;
    
    // Number of entries in the block table
    DWORD dwBlockTableSize;

    //-- MPQ HEADER v 2 -------------------------------------------

    // Offset to the beginning of array of 16-bit high parts of file offsets.
    ULONGLONG HiBlockTablePos64;

    // High 16 bits of the hash table offset for large archives.
    USHORT wHashTablePosHi;

    // High 16 bits of the block table offset for large archives.
    USHORT wBlockTablePosHi;

    //-- MPQ HEADER v 3 -------------------------------------------

    // 64-bit version of the archive size
    ULONGLONG ArchiveSize64;

    // 64-bit position of the BET table
    ULONGLONG BetTablePos64;

    // 64-bit position of the HET table
    ULONGLONG HetTablePos64;

    //-- MPQ HEADER v 4 -------------------------------------------

    // Compressed size of the hash table
    ULONGLONG HashTableSize64;

    // Compressed size of the block table
    ULONGLONG BlockTableSize64;

    // Compressed size of the hi-block table
    ULONGLONG HiBlockTableSize64;

    // Compressed size of the HET block
    ULONGLONG HetTableSize64;

    // Compressed size of the BET block
    ULONGLONG BetTableSize64;

    // Size of raw data chunk to calculate MD5.
    // MD5 of each data chunk follows the raw file data.
    DWORD dwRawChunkSize;                                 

    // MD5 of MPQ tables
    unsigned char MD5_BlockTable[MD5_DIGEST_SIZE];      // MD5 of the block table before decryption
    unsigned char MD5_HashTable[MD5_DIGEST_SIZE];       // MD5 of the hash table before decryption
    unsigned char MD5_HiBlockTable[MD5_DIGEST_SIZE];    // MD5 of the hi-block table
    unsigned char MD5_BetTable[MD5_DIGEST_SIZE];        // MD5 of the BET table before decryption
    unsigned char MD5_HetTable[MD5_DIGEST_SIZE];        // MD5 of the HET table before decryption
    unsigned char MD5_MpqHeader[MD5_DIGEST_SIZE];       // MD5 of the MPQ header from signature to (including) MD5_HetTable
};
#pragma pack(pop)


// Hash entry. All files in the archive are searched by their hashes.
struct TMPQHash
{
    // The hash of the file path, using method A.
    DWORD dwName1;
    
    // The hash of the file path, using method B.
    DWORD dwName2;

#ifdef PLATFORM_LITTLE_ENDIAN

    // The language of the file. This is a Windows LANGID data type, and uses the same values.
    // 0 indicates the default language (American English), or that the file is language-neutral.
    USHORT lcLocale;

    // The platform the file is used for. 0 indicates the default platform.
    // No other values have been observed.
    // Note: wPlatform is actually just BYTE, but since it has never been used, we don't care.
    USHORT wPlatform;

#else

    USHORT wPlatform;
    USHORT lcLocale;

#endif

    // If the hash table entry is valid, this is the index into the block table of the file.
    // Otherwise, one of the following two values:
    //  - FFFFFFFFh: Hash table entry is empty, and has always been empty.
    //               Terminates searches for a given file.
    //  - FFFFFFFEh: Hash table entry is empty, but was valid at some point (a deleted file).
    //               Does not terminate searches for a given file.
    DWORD dwBlockIndex;
};


// File description block contains informations about the file
struct TMPQBlock
{
    // Offset of the beginning of the file, relative to the beginning of the archive.
    DWORD dwFilePos;
    
    // Compressed file size
    DWORD dwCSize;
    
    // Only valid if the block is a file; otherwise meaningless, and should be 0.
    // If the file is compressed, this is the size of the uncompressed file data.
    DWORD dwFSize;                      
    
    // Flags for the file. See MPQ_FILE_XXXX constants
    DWORD dwFlags;                      
};

// Patch file information, preceding the sector offset table
struct TPatchInfo
{
	DWORD dwLength;                     // Length of patch info header, in bytes
	DWORD dwFlags;                      // Flags. 0x80000000 = MD5 (?)
	DWORD dwDataSize;                   // Uncompressed size of the patch file
	BYTE  md5[0x10];                    // MD5 of the entire patch file after decompression

    // Followed by the sector table (variable length)
};

// Header for PTCH files 
struct TPatchHeader
{
    //-- PATCH header -----------------------------------
    DWORD dwSignature;                  // 'PTCH'
    DWORD dwSizeOfPatchData;            // Size of the entire patch (decompressed)
    DWORD dwSizeBeforePatch;            // Size of the file before patch
    DWORD dwSizeAfterPatch;             // Size of file after patch
    
    //-- MD5 block --------------------------------------
    DWORD dwMD5;                        // 'MD5_'
    DWORD dwMd5BlockSize;               // Size of the MD5 block, including the signature and size itself
    BYTE md5_before_patch[0x10];        // MD5 of the original (unpached) file
    BYTE md5_after_patch[0x10];         // MD5 of the patched file

    //-- XFRM block -------------------------------------
    DWORD dwXFRM;                       // 'XFRM'
    DWORD dwXfrmBlockSize;              // Size of the XFRM block, includes XFRM header and patch data
    DWORD dwPatchType;                  // Type of patch ('BSD0' or 'COPY')

    // Followed by the patch data
};

#define SIZE_OF_XFRM_HEADER  0x0C

// This is the combined file entry for maintaining file list in the MPQ.
// This structure is combined from block table, hi-block table,
// (attributes) file and from (listfile).
struct TFileEntry
{
    ULONGLONG ByteOffset;               // Position of the file content in the MPQ, relative to the MPQ header
    ULONGLONG FileTime;                 // FileTime from the (attributes) file. 0 if not present.
    ULONGLONG BetHash;                  // Lower part of the file name hash. Only used when the MPQ has BET table.
    DWORD     dwHashIndex;              // Index to the hash table. Only used when the MPQ has classic hash table
    DWORD     dwHetIndex;               // Index to the HET table. Only used when the MPQ has HET table
    DWORD     dwFileSize;               // Decompressed size of the file
    DWORD     dwCmpSize;                // Compressed size of the file (i.e., size of the file data in the MPQ)
    DWORD     dwFlags;                  // File flags (from block table)
    USHORT    lcLocale;                 // Locale ID for the file
    USHORT    wPlatform;                // Platform ID for the file
    DWORD     dwCrc32;                  // CRC32 from (attributes) file. 0 if not present.
    unsigned char md5[MD5_DIGEST_SIZE]; // File MD5 from the (attributes) file. 0 if not present.
    char * szFileName;                  // File name. NULL if not known.
};

// Common header for HET and BET tables
struct TMPQExtTable
{
    DWORD dwSignature;                  // 'HET\x1A' or 'BET\x1A'
    DWORD dwVersion;                    // Version. Seems to be always 1
    DWORD dwDataSize;                   // Size of the contained table

    // Followed by the table header
    // Followed by the table data

};

//
// MPQ data bitmap, can be found at (FileSize - sizeof(TMPQBlockMap))
//
// There is bit map of the entire MPQ before TMPQBitmap. Each 0x4000-byte
// block is represented by one bit (including the last, eventually incomplete block).
// 
struct TMPQBitmap
{
    DWORD dwSignature;                  // 'ptv3' (MPQ_BLOCK_MAP_SIGNATURE)
    DWORD dwAlways3;                    // Unknown, seems to always have value of 3
    DWORD dwBuildNumber;                // Game build number for that MPQ
    DWORD dwMapOffsetLo;                // Low 32-bits of the offset of the bit map
    DWORD dwMapOffsetHi;                // High 32-bits of the offset of the bit map
    DWORD dwBlockSize;                  // Size of one block (usually 0x4000 bytes)
};

// Structure for parsed HET table
struct TMPQHetTable
{
    TBitArray * pBetIndexes;            // Bit array of indexes to BET tables
    LPBYTE     pHetHashes;              // Array of HET hashes. Each entry has size of 1 byte
    ULONGLONG  AndMask64;               // AND mask used for calculating file name hash
    ULONGLONG  OrMask64;                // OR mask used for setting the highest bit of the file name hash

    DWORD      dwIndexSizeTotal;        // Total size of one entry in pBetIndexes (in bits)
    DWORD      dwIndexSizeExtra;        // Extra bits in the entry in pBetIndexes
    DWORD      dwIndexSize;             // Effective size of one entry in pBetIndexes (in bits)
    DWORD      dwMaxFileCount;          // Maximum number of files in the MPQ
    DWORD      dwHashTableSize;         // Number of entries in pBetHashes
    DWORD      dwHashBitSize;           // Effective number of bits in the hash
};

// Structure for parsed BET table
struct TMPQBetTable
{
    TBitArray * pBetHashes;             // Array of BET hashes
    TBitArray * pFileTable;             // Bit-based file table
    LPDWORD pFileFlags;                 // Array of file flags

    DWORD dwTableEntrySize;             // Size of one table entry, in bits
    DWORD dwBitIndex_FilePos;           // Bit index of the file position in the table entry
    DWORD dwBitIndex_FileSize;          // Bit index of the file size in the table entry
    DWORD dwBitIndex_CmpSize;           // Bit index of the compressed size in the table entry
    DWORD dwBitIndex_FlagIndex;         // Bit index of the flag index in the table entry
    DWORD dwBitIndex_Unknown;           // Bit index of ??? in the table entry
    DWORD dwBitCount_FilePos;           // Size of file offset (in bits) within table entry
    DWORD dwBitCount_FileSize;          // Size of file size (in bits) within table entry
    DWORD dwBitCount_CmpSize;           // Size of compressed file size (in bits) within table entry
    DWORD dwBitCount_FlagIndex;         // Size of flag index (in bits) within table entry
    DWORD dwBitCount_Unknown;           // Size of ??? (in bits) within table entry
    DWORD dwBetHashSizeTotal;           // Total size of bet hash
    DWORD dwBetHashSizeExtra;           // Extra bits in the bet hash
    DWORD dwBetHashSize;                // Effective size of the bet hash
    DWORD dwFileCount;                  // Number of files (usually equal to maximum number of files)
    DWORD dwFlagCount;                  // Number of entries in pFileFlags
};

// Archive handle structure
struct TMPQArchive
{
    TFileStream  * pStream;             // Open stream for the MPQ

    ULONGLONG      UserDataPos;         // Position of user data (relative to the begin of the file)
    ULONGLONG      MpqPos;              // MPQ header offset (relative to the begin of the file)

    TMPQArchive  * haPatch;             // Pointer to patch archive, if any
    TMPQArchive  * haBase;              // Pointer to base ("previous version") archive, if any
    char szPatchPrefix[MPQ_PATCH_PREFIX_LEN]; // Prefix for file names in patch MPQs
    size_t         cchPatchPrefix;      // Length of the patch prefix, in characters

    TMPQUserData * pUserData;           // MPQ user data (NULL if not present in the file)
    TMPQHeader   * pHeader;             // MPQ file header
    TMPQBitmap   * pBitmap;             // MPQ bitmap
    TMPQHash     * pHashTable;          // Hash table
    TMPQHetTable * pHetTable;           // Het table
    TFileEntry   * pFileTable;          // File table
    
    TMPQUserData   UserData;            // MPQ user data. Valid only when ID_MPQ_USERDATA has been found
    BYTE           HeaderData[MPQ_HEADER_SIZE_V4];  // Storage for MPQ header

    DWORD          dwHETBlockSize;
    DWORD          dwBETBlockSize;
    DWORD          dwFileTableSize;     // Current size of the file table, e.g. index of the entry past the last occupied one
    DWORD          dwMaxFileCount;      // Maximum number of files in the MPQ
    DWORD          dwSectorSize;        // Default size of one file sector
    DWORD          dwFileFlags1;        // Flags for (listfile)
    DWORD          dwFileFlags2;        // Flags for (attributes)
    DWORD          dwAttrFlags;         // Flags for the (attributes) file, see MPQ_ATTRIBUTE_XXX
    DWORD          dwFlags;             // See MPQ_FLAG_XXXXX
};                                      

// File handle structure
struct TMPQFile
{
    TFileStream  * pStream;             // File stream. Only used on local files
    TMPQArchive  * ha;                  // Archive handle
    TFileEntry   * pFileEntry;          // File entry for the file
    DWORD          dwFileKey;           // Decryption key
    DWORD          dwFilePos;           // Current file position
    ULONGLONG      RawFilePos;          // Offset in MPQ archive (relative to file begin)
    ULONGLONG      MpqFilePos;          // Offset in MPQ archive (relative to MPQ header)
    DWORD          dwMagic;             // 'FILE'

    TMPQFile     * hfPatchFile;         // Pointer to opened patch file
    TPatchHeader * pPatchHeader;        // Patch header. Only used if the file is a patch file
    LPBYTE         pbFileData;          // Loaded and patched file data. Only used if the file is a patch file
    DWORD          cbFileData;          // Size of loaded patched data

    TPatchInfo   * pPatchInfo;          // Patch info block, preceding the sector table
	DWORD        * SectorOffsets;       // Position of each file sector, relative to the begin of the file. Only for compressed files.
    DWORD        * SectorChksums;       // Array of sector checksums (either ADLER32 or MD5) values for each file sector
    DWORD          dwSectorCount;       // Number of sectors in the file
    DWORD          dwPatchedFileSize;   // Size of patched file. Used when saving patch file to the MPQ
    DWORD          dwDataSize;          // Size of data in the file (on patch files, this differs from file size in block table entry)

    LPBYTE         pbFileSector;        // Last loaded file sector. For single unit files, entire file content
    DWORD          dwSectorOffs;        // File position of currently loaded file sector
    DWORD          dwSectorSize;        // Size of the file sector. For single unit files, this is equal to the file size

    unsigned char  hctx[HASH_STATE_SIZE];// Hash state for MD5. Used when saving file to MPQ
    DWORD          dwCrc32;             // CRC32 value, used when saving file to MPQ

    bool           bLoadedSectorCRCs;   // If true, we already tried to load sector CRCs
    bool           bCheckSectorCRCs;    // If true, then SFileReadFile will check sector CRCs when reading the file
    bool           bIsWriteHandle;      // If true, this handle has been created by SFileCreateFile
    bool           bErrorOccured;       // If true, then at least one error occured during saving the file to the archive
};

// Structure for SFileFindFirstFile and SFileFindNextFile
typedef struct _SFILE_FIND_DATA
{
    char   cFileName[MAX_PATH];         // Full name of the found file
    char * szPlainName;                 // Plain name of the found file
    DWORD  dwHashIndex;                 // Hash table index for the file
    DWORD  dwBlockIndex;                // Block table index for the file
    DWORD  dwFileSize;                  // File size in bytes
    DWORD  dwFileFlags;                 // MPQ file flags
    DWORD  dwCompSize;                  // Compressed file size
    DWORD  dwFileTimeLo;                // Low 32-bits of the file time (0 if not present)
    DWORD  dwFileTimeHi;                // High 32-bits of the file time (0 if not present)
    LCID   lcLocale;                    // Locale version

} SFILE_FIND_DATA, *PSFILE_FIND_DATA;

typedef struct _SFILE_CREATE_MPQ
{
    DWORD cbSize;                       // Size of this structure, in bytes
    DWORD dwMpqVersion;                 // Version of the MPQ to be created
    void *pvUserData;                   // Reserved, must be NULL
    DWORD cbUserData;                   // Reserved, must be 0
    DWORD dwStreamFlags;                // Stream flags for creating the MPQ
    DWORD dwFileFlags1;                 // File flags for (listfile). 0 = default
    DWORD dwFileFlags2;                 // File flags for (attributes). 0 = default
    DWORD dwAttrFlags;                  // Flags for the (attributes) file. If 0, no attributes will be created
    DWORD dwSectorSize;                 // Sector size for compressed files
    DWORD dwRawChunkSize;               // Size of raw data chunk
    DWORD dwMaxFileCount;               // File limit for the MPQ

} SFILE_CREATE_MPQ, *PSFILE_CREATE_MPQ;

//-----------------------------------------------------------------------------
// Stream support - functions

TFileStream * FileStream_CreateFile(const TCHAR * szFileName, DWORD dwStreamFlags);
TFileStream * FileStream_OpenFile(const TCHAR * szFileName, DWORD dwStreamFlags);
TCHAR * FileStream_GetFileName(TFileStream * pStream);
bool FileStream_IsReadOnly(TFileStream * pStream);
bool FileStream_Read(TFileStream * pStream, ULONGLONG * pByteOffset, void * pvBuffer, DWORD dwBytesToRead);
bool FileStream_Write(TFileStream * pStream, ULONGLONG * pByteOffset, const void * pvBuffer, DWORD dwBytesToWrite);
bool FileStream_GetPos(TFileStream * pStream, ULONGLONG & ByteOffset);
bool FileStream_SetPos(TFileStream * pStream, ULONGLONG ByteOffset);
bool FileStream_GetSize(TFileStream * pStream, ULONGLONG & FileSize);
bool FileStream_SetSize(TFileStream * pStream, ULONGLONG NewFileSize);
bool FileStream_GetTime(TFileStream * pStream, ULONGLONG * pFT);
bool FileStream_Switch(TFileStream * pStream, TFileStream * pTempStream);
bool FileStream_SetBitmap(TFileStream * pStream, TFileBitmap * pBitmap);
bool FileStream_GetBitmap(TFileStream * pStream, TFileBitmap * pBitmap, DWORD Length, LPDWORD LengthNeeded);
void FileStream_Close(TFileStream * pStream);

//-----------------------------------------------------------------------------
// Functions prototypes for Storm.dll

// Typedefs for functions exported by Storm.dll
typedef LCID  (WINAPI * SFILESETLOCALE)(LCID);
typedef bool  (WINAPI * SFILEOPENARCHIVE)(const char *, DWORD, DWORD, HANDLE *);
typedef bool  (WINAPI * SFILECLOSEARCHIVE)(HANDLE);
typedef bool  (WINAPI * SFILEOPENFILEEX)(HANDLE, const char *, DWORD, HANDLE *);
typedef bool  (WINAPI * SFILECLOSEFILE)(HANDLE);
typedef DWORD (WINAPI * SFILEGETFILESIZE)(HANDLE, LPDWORD);
typedef DWORD (WINAPI * SFILESETFILEPOINTER)(HANDLE, LONG, LONG *, DWORD);
typedef bool  (WINAPI * SFILEREADFILE)(HANDLE, void *, DWORD, LPDWORD, LPOVERLAPPED);

//-----------------------------------------------------------------------------
// Functions for manipulation with StormLib global flags

LCID   WINAPI SFileGetLocale();
LCID   WINAPI SFileSetLocale(LCID lcNewLocale);

//-----------------------------------------------------------------------------
// Functions for archive manipulation

bool   WINAPI SFileOpenArchive(const TCHAR * szMpqName, DWORD dwPriority, DWORD dwFlags, HANDLE * phMpq);
bool   WINAPI SFileCreateArchive(const TCHAR * szMpqName, DWORD dwFlags, DWORD dwMaxFileCount, HANDLE * phMpq);
bool   WINAPI SFileCreateArchive2(const TCHAR * szMpqName, PSFILE_CREATE_MPQ pCreateInfo, HANDLE * phMpq);

bool   WINAPI SFileGetArchiveBitmap(HANDLE hMpq, TFileBitmap * pBitmap, DWORD Length, LPDWORD LengthNeeded);
bool   WINAPI SFileFlushArchive(HANDLE hMpq);
bool   WINAPI SFileCloseArchive(HANDLE hMpq);

// Adds another listfile into MPQ. The currently added listfile(s) remain,
// so you can use this API to combining more listfiles.
// Note that this function is internally called by SFileFindFirstFile
int    WINAPI SFileAddListFile(HANDLE hMpq, const char * szListFile);

// Archive compacting
bool   WINAPI SFileSetCompactCallback(HANDLE hMpq, SFILE_COMPACT_CALLBACK CompactCB, void * pvData);
bool   WINAPI SFileCompactArchive(HANDLE hMpq, const char * szListFile = NULL, bool bReserved = 0);

// Changing the maximum file count
DWORD  WINAPI SFileGetMaxFileCount(HANDLE hMpq);
bool   WINAPI SFileSetMaxFileCount(HANDLE hMpq, DWORD dwMaxFileCount);

// Changing (attributes) file
DWORD  WINAPI SFileGetAttributes(HANDLE hMpq);
bool   WINAPI SFileSetAttributes(HANDLE hMpq, DWORD dwFlags);
bool   WINAPI SFileUpdateFileAttributes(HANDLE hMpq, const char * szFileName);

//-----------------------------------------------------------------------------
// Functions for manipulation with patch archives

bool   WINAPI SFileOpenPatchArchive(HANDLE hMpq, const TCHAR * szPatchMpqName, const char * szPatchPathPrefix, DWORD dwFlags);
bool   WINAPI SFileIsPatchedArchive(HANDLE hMpq);

//-----------------------------------------------------------------------------
// Functions for file manipulation

// Reading from MPQ file
bool   WINAPI SFileOpenFileEx(HANDLE hMpq, const char * szFileName, DWORD dwSearchScope, HANDLE * phFile);
DWORD  WINAPI SFileGetFileSize(HANDLE hFile, LPDWORD pdwFileSizeHigh = NULL);
DWORD  WINAPI SFileSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod);
bool   WINAPI SFileReadFile(HANDLE hFile, void * lpBuffer, DWORD dwToRead, LPDWORD pdwRead = NULL, LPOVERLAPPED lpOverlapped = NULL);
bool   WINAPI SFileCloseFile(HANDLE hFile);

// Retrieving info about the file
bool   WINAPI SFileHasFile(HANDLE hMpq, const char * szFileName);
bool   WINAPI SFileGetFileName(HANDLE hFile, char * szFileName);
bool   WINAPI SFileGetFileInfo(HANDLE hMpqOrFile, DWORD dwInfoType, void * pvFileInfo, DWORD cbFileInfo, LPDWORD pcbLengthNeeded = NULL);

// High-level extract function
bool   WINAPI SFileExtractFile(HANDLE hMpq, const char * szToExtract, const TCHAR * szExtracted, DWORD dwSearchScope = SFILE_OPEN_FROM_MPQ);

//-----------------------------------------------------------------------------
// Functions for file and archive verification

// Generates file CRC32
bool   WINAPI SFileGetFileChecksums(HANDLE hMpq, const char * szFileName, LPDWORD pdwCrc32, char * pMD5);

// Verifies file against its checksums stored in (attributes) attributes (depending on dwFlags).
// For dwFlags, use one or more of MPQ_ATTRIBUTE_MD5
DWORD  WINAPI SFileVerifyFile(HANDLE hMpq, const char * szFileName, DWORD dwFlags);

// Verifies raw data of the archive. Only works for MPQs version 4 or newer
int    WINAPI SFileVerifyRawData(HANDLE hMpq, DWORD dwWhatToVerify, const char * szFileName);

// Verifies the signature, if present
DWORD  WINAPI SFileVerifyArchive(HANDLE hMpq);

//-----------------------------------------------------------------------------
// Functions for file searching

HANDLE WINAPI SFileFindFirstFile(HANDLE hMpq, const char * szMask, SFILE_FIND_DATA * lpFindFileData, const char * szListFile);
bool   WINAPI SFileFindNextFile(HANDLE hFind, SFILE_FIND_DATA * lpFindFileData);
bool   WINAPI SFileFindClose(HANDLE hFind);

HANDLE WINAPI SListFileFindFirstFile(HANDLE hMpq, const char * szListFile, const char * szMask, SFILE_FIND_DATA * lpFindFileData);
bool   WINAPI SListFileFindNextFile(HANDLE hFind, SFILE_FIND_DATA * lpFindFileData);
bool   WINAPI SListFileFindClose(HANDLE hFind);

// Locale support
int    WINAPI SFileEnumLocales(HANDLE hMpq, const char * szFileName, LCID * plcLocales, LPDWORD pdwMaxLocales, DWORD dwSearchScope);

//-----------------------------------------------------------------------------
// Support for adding files to the MPQ

bool   WINAPI SFileCreateFile(HANDLE hMpq, const char * szArchivedName, ULONGLONG FileTime, DWORD dwFileSize, LCID lcLocale, DWORD dwFlags, HANDLE * phFile);
bool   WINAPI SFileWriteFile(HANDLE hFile, const void * pvData, DWORD dwSize, DWORD dwCompression);
bool   WINAPI SFileFinishFile(HANDLE hFile);

bool   WINAPI SFileAddFileEx(HANDLE hMpq, const TCHAR * szFileName, const char * szArchivedName, DWORD dwFlags, DWORD dwCompression, DWORD dwCompressionNext = MPQ_COMPRESSION_NEXT_SAME); 
bool   WINAPI SFileAddFile(HANDLE hMpq, const TCHAR * szFileName, const char * szArchivedName, DWORD dwFlags); 
bool   WINAPI SFileAddWave(HANDLE hMpq, const TCHAR * szFileName, const char * szArchivedName, DWORD dwFlags, DWORD dwQuality); 
bool   WINAPI SFileRemoveFile(HANDLE hMpq, const char * szFileName, DWORD dwSearchScope = SFILE_OPEN_FROM_MPQ);
bool   WINAPI SFileRenameFile(HANDLE hMpq, const char * szOldFileName, const char * szNewFileName);
bool   WINAPI SFileSetFileLocale(HANDLE hFile, LCID lcNewLocale);
bool   WINAPI SFileSetDataCompression(DWORD DataCompression);

bool   WINAPI SFileSetAddFileCallback(HANDLE hMpq, SFILE_ADDFILE_CALLBACK AddFileCB, void * pvData);

//-----------------------------------------------------------------------------
// Compression and decompression

int    WINAPI SCompImplode    (char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer);
int    WINAPI SCompExplode    (char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer);
int    WINAPI SCompCompress   (char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer, unsigned uCompressionMask, int nCmpType, int nCmpLevel);
int    WINAPI SCompDecompress (char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer);
int    WINAPI SCompDecompress2(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer);

//-----------------------------------------------------------------------------
// Non-Windows support for SetLastError/GetLastError

#ifndef PLATFORM_WINDOWS

void  SetLastError(int err);
int   GetLastError();

#endif

//-----------------------------------------------------------------------------
// Functions from Storm.dll. They use slightly different names for keeping
// possibility to use them together with StormLib (StormXXX instead of SFileXXX)

#ifdef __LINK_STORM_DLL__
  #define STORM_ALTERNATE_NAMES         // Force storm_dll.h to use alternate fnc names
  #include "..\storm_dll\storm_dll.h"
#endif // __LINK_STORM_DLL__

#ifdef __cplusplus
}   // extern "C"
#endif

#endif  // __STORMLIB_H__
