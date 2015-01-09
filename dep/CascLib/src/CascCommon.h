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
#include "common/FileStream.h"
#include "common/ListFile.h"
#include "common/Map.h"

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

// Prevent problems with CRT "min" and "max" functions,
// as they are not defined on all platforms
#define CASCLIB_MIN(a, b) ((a < b) ? a : b)
#define CASCLIB_MAX(a, b) ((a > b) ? a : b)
#define CASCLIB_UNUSED(p) ((void)(p))

#define CASC_PACKAGE_BUFFER     0x1000

//-----------------------------------------------------------------------------
// Structures

struct TFileStream;
struct _MAR_FILE;

typedef struct _CASC_INDEX_ENTRY
{
    BYTE IndexKey[CASC_FILE_KEY_SIZE];              // The first 9 bytes of the encoding key
    BYTE FileOffset[5];                             // 
    BYTE FileSize[4];
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
    BYTE FileSizeBytes[4];                          // File size as bytes (big-endian)
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

typedef struct _CASC_ROOT_ENTRY
{
    BYTE EncodingKey[MD5_HASH_SIZE];                // File encoding key (MD5)
    ULONGLONG FileNameHash;                         // Jenkins hash of the file name
    DWORD Locales;                                  // File locales (see CASC_LOCALE_XXX)
    DWORD Flags;                                    // File flags

} CASC_ROOT_ENTRY, *PCASC_ROOT_ENTRY;

typedef struct _CASC_ROOT_KEY_INFO
{
    BYTE EncodingKey[MD5_HASH_SIZE];                // Encoding key for the file, obtained from root info
    ULONGLONG FileSize;                             // Size of the file, in bytes
    BYTE Flags;                                     // File flags
} CASC_ROOT_KEY_INFO, *PCASC_ROOT_KEY_INFO;

typedef struct _CASC_MNDX_ENTRY
{
    DWORD Flags;                                    // High 8 bits: Flags, low 24 bits: package index
    BYTE  EncodingKey[MD5_HASH_SIZE];               // Encoding key for the file
    DWORD FileSize;                                 // Size of the file, in bytes

} CASC_MNDX_ENTRY, *PCASC_MNDX_ENTRY;

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
    PCASC_MNDX_ENTRY pMndxEntries;
    PCASC_MNDX_ENTRY * ppValidEntries;

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

    PCASC_ROOT_ENTRY * ppRootEntries;               // Sorted array of root entries
    PCASC_ROOT_ENTRY pRootEntries;                  // Linear array of root entries
    size_t nRootEntries;                            // Number of root entries

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
    DWORD FramesOffset;                             // Offset of the frame data, relative to the begin of the archive
    DWORD CompressedSize;                           // Compressed size of the file (in bytes)
    DWORD FileSize;                                 // Size of file, in bytes

    PCASC_FILE_FRAME pFrames;                       // Array of file frames
    DWORD FrameCount;                               // Number of the file frames

    LPBYTE pbFileCache;                             // Pointer to file cache
    DWORD cbFileCache;                              // Size of the file cache
    DWORD CacheStart;                               // Starting offset in the cache
    DWORD CacheEnd;                                 // Ending offset in the cache

} TCascFile;

class TMndxFindResult;

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
    ULONGLONG FileNameHash;                         // Name hash being searched right now
    size_t RootIndex;                               // Root index of the previously found item
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
/*
void * DbgRealloc(void * ptr, size_t nSize);

#define CASC_REALLOC(type, ptr, count) (type *)DbgRealloc(ptr, ((count) * sizeof(type)))
#define CASC_ALLOC(type, count)        (type *)HeapAlloc(GetProcessHeap(), 0, ((count) * sizeof(type)))
#define CASC_FREE(ptr)                 HeapFree(GetProcessHeap(), 0, ptr)
*/

#define CASC_REALLOC(type, ptr, count) (type *)realloc(ptr, (count) * sizeof(type))
#define CASC_ALLOC(type, count)        (type *)malloc((count) * sizeof(type))
#define CASC_FREE(ptr)                 free(ptr)

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

int LoadBuildConfiguration(TCascStorage * hs);

//-----------------------------------------------------------------------------
// Internal file functions

TCascStorage * IsValidStorageHandle(HANDLE hStorage);
TCascFile * IsValidFileHandle(HANDLE hFile);

PCASC_ROOT_ENTRY     FindFirstRootEntry(TCascStorage * hs, const char * szFileName, size_t * PtrIndex);
PCASC_ENCODING_ENTRY FindEncodingEntry(TCascStorage * hs, PQUERY_KEY pEncodingKey, size_t * PtrIndex);
PCASC_INDEX_ENTRY    FindIndexEntry(TCascStorage * hs, PQUERY_KEY pIndexKey);

int CascDecompress(void * pvOutBuffer, PDWORD pcbOutBuffer, void * pvInBuffer, DWORD cbInBuffer);

//-----------------------------------------------------------------------------
// Dump data

#ifdef _DEBUG
void CascDumpSparseArray(const char * szFileName, void * pvSparseArray);
void CascDumpNameFragTable(const char * szFileName, void * pvMarFile);
void CascDumpFileNames(const char * szFileName, void * pvMarFile);
void CascDumpMndxRoot(const char * szFileName, PCASC_MNDX_INFO pMndxInfo);
void CascDumpIndexEntries(const char * szFileName, TCascStorage * hs);
void CascDumpStorage(const char * szFileName, TCascStorage * hs, const TCHAR * szListFile);
void CascDumpFile(const char * szFileName, HANDLE hFile);
#else   // _DEBUG
#define CascDumpSparseArray(n,a)    /* */
#define CascDumpNameFragTable(n, m) /* */
#define CascDumpFileNames(n, m)     /* */
#define CascDumpMndxRoot(n,i)       /* */
#define CascDumpIndexEntries(n,h)   /* */
#define CascDumpStorage(n,h)        /* */
#define CascDumpFile(n,h)           /* */
#endif  // _DEBUG

#endif // __CASCCOMMON_H__
