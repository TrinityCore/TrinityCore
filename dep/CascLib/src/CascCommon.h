/*****************************************************************************/
/* CascCommon.h                           Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascCommon.h                    */
/*****************************************************************************/

#ifndef __CASCCOMMON_H__
#define __CASCCOMMON_H__

//-----------------------------------------------------------------------------
// Compression support

// Include functions from zlib
#ifndef __SYS_ZLIB
  #include "zlib/zlib.h"
#else
  #include <zlib.h>
#endif

#include "CascPort.h"
#include "common/Common.h"
#include "common/Map.h"
#include "common/FileStream.h"
#include "common/ListFile.h"

// Headers from LibTomCrypt
#include "libtomcrypt/src/headers/tomcrypt.h"

// For HashStringJenkins
#include "jenkins/lookup.h"

//-----------------------------------------------------------------------------
// CascLib private defines

#define CASC_GAME_HOTS      0x00010000          // Heroes of the Storm
#define CASC_GAME_WOW6      0x00020000          // World of Warcraft - Warlords of Draenor
#define CASC_GAME_MASK      0xFFFF0000          // Mask for getting game ID

#define CASC_INDEX_COUNT          0x10
#define CASC_FILE_KEY_SIZE        0x09          // Size of the file key
#define CASC_MAX_DATA_FILES      0x100
#define CASC_MAX_MAR_FILES           3          // Maximum of 3 MAR files are supported
#define CASC_MNDX_SIGNATURE 0x58444E4D          // 'MNDX'

#define CASC_SEARCH_HAVE_NAME   0x0001          // Indicated that previous search found a name

#define BLTE_HEADER_SIGNATURE   0x45544C42      // 'BLTE' header in the data files
#define BLTE_HEADER_DELTA       0x1E            // Distance of BLTE header from begin of the header area
#define MAX_HEADER_AREA_SIZE    0x2A            // Length of the file header area

// File header area in the data.xxx:
//  BYTE  HeaderHash[MD5_HASH_SIZE];            // MD5 of the frame array
//  DWORD dwFileSize;                           // Size of the file (see comment before CascGetFileSize for details)
//  BYTE  SomeSize[4];                          // Some size (big endian)
//  BYTE  Padding[6];                           // Padding (?)
//  DWORD dwSignature;                          // Must be "BLTE"
//  BYTE  HeaderSizeAsBytes[4];                 // Header size in bytes (big endian)
//  BYTE  MustBe0F;                             // Must be 0x0F. Optional, only if HeaderSizeAsBytes != 0
//  BYTE  FrameCount[3];                        // Frame count (big endian). Optional, only if HeaderSizeAsBytes != 0

// Prevent problems with CRT "min" and "max" functions,
// as they are not defined on all platforms
#define CASCLIB_MIN(a, b) ((a < b) ? a : b)
#define CASCLIB_MAX(a, b) ((a > b) ? a : b)
#define CASCLIB_UNUSED(p) ((void)(p))

#define CASC_PACKAGE_BUFFER     0x1000

//-----------------------------------------------------------------------------
// On-disk structures

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
    DWORD EncodingKey[4];                       // MD5 of the file
    ULONGLONG FileNameHash;                     // Jenkins hash of the file name

} FILE_ROOT_ENTRY, *PFILE_ROOT_ENTRY;

typedef struct _ROOT_BLOCK_INFO
{
    PFILE_LOCALE_BLOCK pLocaleBlockHdr;         // Pointer to the locale block
    PDWORD pInt32Array;                         // Pointer to the array of 32-bit integers
    PFILE_ROOT_ENTRY pRootEntries;

} ROOT_BLOCK_INFO, *PROOT_BLOCK_INFO;

//-----------------------------------------------------------------------------
// In-memory structures

class TMndxFindResult;
struct TFileStream;
struct _MAR_FILE;

typedef struct _CASC_INDEX_ENTRY
{
    BYTE IndexKey[CASC_FILE_KEY_SIZE];              // The first 9 bytes of the encoding key
    BYTE FileOffsetBE[5];                           // Index of data file and offset within (big endian).
    BYTE FileSizeLE[4];                             // Size occupied in the storage file (data.###). See comment before CascGetFileSize for details
} CASC_INDEX_ENTRY, *PCASC_INDEX_ENTRY;

typedef struct _CASC_MAPPING_TABLE
{
    TCHAR * szFileName;                             // Name of the key mapping file
    LPBYTE  pbFileData;                             // Pointer to the file data
    DWORD   cbFileData;                             // Length of the file data
    BYTE   ExtraBytes;                              // (?) Extra bytes in the key record
    BYTE   SpanSizeBytes;                           // Size of field with file size
    BYTE   SpanOffsBytes;                           // Size of field with file offset
    BYTE   KeyBytes;                                // Size of the file key
    BYTE   SegmentBits;                             // Number of bits for the file offset (rest is archive index)
    ULONGLONG MaxFileOffset;
        
    PCASC_INDEX_ENTRY pIndexEntries;                // Sorted array of index entries
    DWORD nIndexEntries;                            // Number of index entries

} CASC_MAPPING_TABLE, *PCASC_MAPPING_TABLE;

typedef struct _CASC_FILE_FRAME
{
    DWORD FrameArchiveOffset;                       // Archive file pointer corresponding to the begin of the frame
    DWORD FrameFileOffset;                          // File pointer corresponding to the begin of the frame
    DWORD CompressedSize;                           // Compressed size of the file
    DWORD FrameSize;                                // Size of the frame
    BYTE  md5[MD5_HASH_SIZE];                       // MD5 hash of the file sector
} CASC_FILE_FRAME, *PCASC_FILE_FRAME;

typedef struct _CASC_ENCODING_HEADER
{
    BYTE Magic[2];                                  // "EN"
    BYTE field_2;
    BYTE field_3;
    BYTE field_4;
    BYTE field_5[2];
    BYTE field_7[2];
    BYTE NumSegments[4];                            // Number of entries (big endian)
    BYTE field_D[4];
    BYTE field_11;
    BYTE SegmentsPos[4];                            // Offset of encoding segments

} CASC_ENCODING_HEADER, *PCASC_ENCODING_HEADER;

typedef struct _CASC_ENCODING_ENTRY
{
    USHORT KeyCount;                                // Number of subitems
    BYTE FileSizeBE[4];                          // Compressed file size (header area + frame headers + compressed frames), in bytes
    BYTE EncodingKey[MD5_HASH_SIZE];                // File encoding key

    // Followed by the index keys
    // (number of items = KeyCount)
    // Followed by the index keys (number of items = KeyCount)
} CASC_ENCODING_ENTRY, *PCASC_ENCODING_ENTRY;

typedef struct _CASC_ROOT_LOCALE_BLOCK
{
    DWORD NumberOfFiles;                            // Number of entries
    DWORD Flags;
    DWORD FileLocales;                              // File locales (CASC_LOCALE_XXX)

    // Followed by a block of 32-bit integers (count: NumberOfFiles)
    // Followed by the MD5 and file name hash (count: NumberOfFiles)

} CASC_ROOT_LOCALE_BLOCK, *PCASC_ROOT_LOCALE_BLOCK;

// Root file entry for CASC storages with MNDX root file (Heroes of the Storm)
// Corresponds to the in-file structure
typedef struct _CASC_ROOT_ENTRY_MNDX
{
    DWORD Flags;                                    // High 8 bits: Flags, low 24 bits: package index
    BYTE  EncodingKey[MD5_HASH_SIZE];               // Encoding key for the file
    DWORD FileSize;                                 // Uncompressed file size, in bytes

} CASC_ROOT_ENTRY_MNDX, *PCASC_ROOT_ENTRY_MNDX;

// Root file entry for CASC storages without MNDX root file (World of Warcraft 6.0+)
// Does not match to the in-file structure of the root entry
typedef struct _CASC_ROOT_ENTRY
{
    ULONGLONG FileNameHash;                         // Jenkins hash of the file name
    DWORD SumValue;                                 // Sum value
    DWORD Locales;                                  // Locale flags of the file
    DWORD EncodingKey[4];                           // File encoding key (MD5)

} CASC_ROOT_ENTRY, *PCASC_ROOT_ENTRY;

// Definition of the hash table for CASC root items
typedef struct _CASC_ROOT_HASH_TABLE
{
    PCASC_ROOT_ENTRY TablePtr;                      // Pointer to the CASC root table
    DWORD TableSize;                                // Total size of the root table
    DWORD ItemCount;                                // Number of items currently in the table

} CASC_ROOT_HASH_TABLE, *PCASC_ROOT_HASH_TABLE;

typedef struct _CASC_MNDX_INFO
{
    bool bRootFileLoaded;                           // true if the root info file was properly loaded
    BYTE RootFileName[MD5_HASH_SIZE];               // Name (aka MD5) of the root file 
    DWORD HeaderVersion;                            // Must be <= 2
    DWORD FormatVersion;
    DWORD field_1C;
    DWORD field_20;
    DWORD MarInfoOffset;                            // Offset of the first MAR entry info
    DWORD MarInfoCount;                             // Number of the MAR info entries
    DWORD MarInfoSize;                              // Size of the MAR info entry
    DWORD MndxEntriesOffset;
    DWORD MndxEntriesTotal;                         // Total number of MNDX root entries
    DWORD MndxEntriesValid;                         // Number of valid MNDX root entries
    DWORD MndxEntrySize;                            // Size of one MNDX root entry
    struct _MAR_FILE * pMarFile1;                   // File name list for the packages
    struct _MAR_FILE * pMarFile2;                   // File name list for names stripped of package names
    struct _MAR_FILE * pMarFile3;                   // File name list for complete names
    PCASC_ROOT_ENTRY_MNDX pMndxEntries;
    PCASC_ROOT_ENTRY_MNDX * ppValidEntries;

} CASC_MNDX_INFO, *PCASC_MNDX_INFO;

typedef struct _CASC_PACKAGE
{
    char * szFileName;                              // Pointer to file name
    size_t nLength;                                 // Length of the file name

} CASC_PACKAGE, *PCASC_PACKAGE;

typedef struct _CASC_PACKAGES
{
    char * szNameBuffer;                            // Pointer to the buffer for file names
    size_t NameEntries;                             // Number of name entries in Names
    size_t NameBufferUsed;                          // Number of bytes used in the name buffer
    size_t NameBufferMax;                           // Total size of the name buffer

    CASC_PACKAGE Packages[1];                       // List of packages

} CASC_PACKAGES, *PCASC_PACKAGES;

typedef struct _TCascStorage
{
    const char * szClassName;                       // "TCascStorage"
    const TCHAR * szIndexFormat;                    // Format of the index file name
    TCHAR * szRootPath;                             // This is the game directory
    TCHAR * szDataPath;                             // This is the directory where data files are
    TCHAR * szIndexPath;                            // This is the directory where index files are
    TCHAR * szUrlPath;                              // URL to the Blizzard servers
    DWORD dwRefCount;                               // Number of references
    DWORD dwGameInfo;                               // Game type
    DWORD dwBuildNumber;                            // Game build number
    DWORD dwFileBeginDelta;                         // This is number of bytes to shift back from archive offset (from index entry) to actual begin of file data
    DWORD dwDefaultLocale;                          // Default locale, read from ".build.info"
    
    QUERY_KEY CdnConfigKey;
    QUERY_KEY CdnBuildKey;

    PQUERY_KEY pArchiveArray;                       // Array of the archives
    QUERY_KEY ArchiveGroup;                         // Name of the group archive file
    DWORD ArchiveCount;                             // Number of archives in the array

    PQUERY_KEY pPatchArchiveArray;                  // Array of the patch archives
    QUERY_KEY PatchArchiveGroup;                    // Name of the patch group archive file
    DWORD PatchArchiveCount;                        // Number of patch archives in the array

    QUERY_KEY RootKey;
    QUERY_KEY PatchKey;
    QUERY_KEY DownloadKey;
    QUERY_KEY InstallKey;

    PQUERY_KEY pEncodingKeys;
    QUERY_KEY EncodingKey;
    QUERY_KEY EncodingEKey;
    DWORD EncodingKeys;

    TFileStream * DataFileArray[CASC_MAX_DATA_FILES]; // Data file handles

    CASC_MAPPING_TABLE KeyMapping[CASC_INDEX_COUNT]; // Key mapping
    PCASC_MAP pIndexEntryMap;                       // Map of index entries

    PCASC_ENCODING_HEADER pEncodingHeader;          // The encoding file
    PCASC_ENCODING_ENTRY * ppEncodingEntries;       // Map of encoding entries
    size_t nEncodingEntries;

    CASC_ROOT_HASH_TABLE RootTable;                 // Hash table for the root entries

    PCASC_MNDX_INFO pMndxInfo;                      // Used for storages which have MNDX/MAR file
    PCASC_PACKAGES pPackages;                       // Linear list of present packages

} TCascStorage;

typedef struct _TCascFile
{
    TCascStorage * hs;                              // Pointer to storage structure
    TFileStream * pStream;                          // An open data stream
    const char * szClassName;                       // "TCascFile"
    
    DWORD FilePointer;                              // Current file pointer

    DWORD ArchiveIndex;                             // Index of the archive (data.###)
    DWORD HeaderOffset;                             // Offset of the BLTE header, relative to the begin of the archive
    DWORD HeaderSize;                               // Length of the BLTE header
    DWORD FramesOffset;                             // Offset of the frame data, relative to the begin of the archive
    DWORD CompressedSize;                           // Compressed size of the file (in bytes)
    DWORD FileSize;                                 // Size of file, in bytes
    BYTE FrameArrayHash[MD5_HASH_SIZE];             // MD5 hash of the frame array

    PCASC_FILE_FRAME pFrames;                       // Array of file frames
    DWORD FrameCount;                               // Number of the file frames

    LPBYTE pbFileCache;                             // Pointer to file cache
    DWORD cbFileCache;                              // Size of the file cache
    DWORD CacheStart;                               // Starting offset in the cache
    DWORD CacheEnd;                                 // Ending offset in the cache

#ifdef CASCLIB_TEST     // Extra fields for analyzing the file size problem
    DWORD FileSize_RootEntry;                       // File size, from the root entry
    DWORD FileSize_EncEntry;                        // File size, from the encoding entry
    DWORD FileSize_IdxEntry;                        // File size, from the index entry
    DWORD FileSize_HdrArea;                         // File size, as stated in the file header area
    DWORD FileSize_FrameSum;                        // File size as sum of frame sizes
#endif

} TCascFile;

typedef struct _TCascSearch
{
    TCascStorage * hs;                              // Pointer to the storage handle
    const char * szClassName;
    TCHAR * szListFile;
    void * pCache;                                  // Listfile cache
    TMndxFindResult * pStruct1C;                    // Search structure for MNDX info
    char * szMask;
    char szFileName[MAX_PATH];                      // Buffer for the file name
    char szNormName[MAX_PATH];                      // Buffer for normalized file name
    DWORD RootIndex;                                // Root index of the previously found item
    DWORD dwState;                                  // Pointer to the state (0 = listfile, 1 = nameless, 2 = done)
    BYTE BitArray[1];                               // Bit array of already-reported files

} TCascSearch;

//-----------------------------------------------------------------------------
// Memory management
//
// We use our own macros for allocating/freeing memory. If you want
// to redefine them, please keep the following rules:
//
//  - The memory allocation must return NULL if not enough memory
//    (i.e not to throw exception)
//  - The allocating function does not need to fill the allocated buffer with zeros
//  - The reallocating function must support NULL as the previous block
//  - Memory freeing function doesn't have to test the pointer to NULL
//

#if defined(_MSC_VER) && defined(_DEBUG)

#define CASC_REALLOC(type, ptr, count) (type *)HeapReAlloc(GetProcessHeap(), 0, ptr, ((count) * sizeof(type)))
#define CASC_ALLOC(type, count)        (type *)HeapAlloc(GetProcessHeap(), 0, ((count) * sizeof(type)))
#define CASC_FREE(ptr)                 HeapFree(GetProcessHeap(), 0, ptr)

#else

#define CASC_REALLOC(type, ptr, count) (type *)realloc(ptr, (count) * sizeof(type))
#define CASC_ALLOC(type, count)        (type *)malloc((count) * sizeof(type))
#define CASC_FREE(ptr)                 free(ptr)

#endif

//-----------------------------------------------------------------------------
// Big endian number manipulation

DWORD ConvertBytesToInteger_3(LPBYTE ValueAsBytes);
DWORD ConvertBytesToInteger_4(LPBYTE ValueAsBytes);
DWORD ConvertBytesToInteger_4_LE(LPBYTE ValueAsBytes);
ULONGLONG ConvertBytesToInteger_5(LPBYTE ValueAsBytes);

//-----------------------------------------------------------------------------
// Build configuration reading

int LoadBuildInfo(TCascStorage * hs);

//-----------------------------------------------------------------------------
// Internal file functions

TCascStorage * IsValidStorageHandle(HANDLE hStorage);
TCascFile * IsValidFileHandle(HANDLE hFile);

PCASC_ROOT_ENTRY     FindRootEntry(TCascStorage * hs, const char * szFileName, DWORD * PtrTableIndex);
PCASC_ENCODING_ENTRY FindEncodingEntry(TCascStorage * hs, PQUERY_KEY pEncodingKey, size_t * PtrIndex);
PCASC_INDEX_ENTRY    FindIndexEntry(TCascStorage * hs, PQUERY_KEY pIndexKey);

int CascDecompress(void * pvOutBuffer, PDWORD pcbOutBuffer, void * pvInBuffer, DWORD cbInBuffer);

//-----------------------------------------------------------------------------
// Dumping CASC data structures

#ifdef _DEBUG
void CascDumpSparseArray(const char * szFileName, void * pvSparseArray);
void CascDumpNameFragTable(const char * szFileName, void * pvMarFile);
void CascDumpFileNames(const char * szFileName, void * pvMarFile);
void CascDumpIndexEntries(const char * szFileName, TCascStorage * hs);
void CascDumpMndxRoot(const char * szFileName, PCASC_MNDX_INFO pMndxInfo);
void CascDumpRootFile(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile, const char * szFormat, const TCHAR * szListFile, int nDumpLevel);
void CascDumpFile(const char * szFileName, HANDLE hFile);
#endif  // _DEBUG

#endif // __CASCCOMMON_H__
