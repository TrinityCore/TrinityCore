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
#include "common/DynamicArray.h"
#include "common/Map.h"
#include "common/FileStream.h"
#include "common/Directory.h"
#include "common/ListFile.h"
#include "common/DumpContext.h"
#include "common/RootHandler.h"

// Headers from LibTomCrypt
#include "libtomcrypt/src/headers/tomcrypt.h"

// For HashStringJenkins
#include "jenkins/lookup.h"

//-----------------------------------------------------------------------------
// CascLib private defines

#define CASC_GAME_HOTS       0x00010000         // Heroes of the Storm
#define CASC_GAME_WOW6       0x00020000         // World of Warcraft - Warlords of Draenor
#define CASC_GAME_DIABLO3    0x00030000         // Diablo 3 since PTR 2.2.0
#define CASC_GAME_OVERWATCH  0x00040000         // Overwatch since PTR 24919
#define CASC_GAME_STARCRAFT2 0x00050000         // Starcraft II - Legacy of the Void, since build 38996
#define CASC_GAME_STARCRAFT1 0x00060000         // Starcraft 1 (remastered)
#define CASC_GAME_MASK       0xFFFF0000         // Mask for getting game ID

#define CASC_INDEX_COUNT          0x10
#define CASC_FILE_KEY_SIZE        0x09          // Size of the file key
#define CASC_MAX_DATA_FILES      0x100
#define CASC_EXTRA_FILES          0x20          // Number of extra entries to be reserved for additionally inserted files

#define CASC_SEARCH_HAVE_NAME   0x0001          // Indicated that previous search found a name

#define BLTE_HEADER_SIGNATURE   0x45544C42      // 'BLTE' header in the data files
#define BLTE_HEADER_DELTA       0x1E            // Distance of BLTE header from begin of the header area
#define MAX_HEADER_AREA_SIZE    0x2A            // Length of the file header area

// File header area in the data.nnn:
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

#ifndef _maxchars
#define _maxchars(buff)  ((sizeof(buff) / sizeof(buff[0])) - 1)
#endif

//-----------------------------------------------------------------------------
// In-memory structures
// See http://pxr.dk/wowdev/wiki/index.php?title=CASC for more information

struct TFileStream;

typedef enum _CBLD_TYPE
{
    CascBuildNone = 0,                              // No build type found
    CascBuildInfo,                                  // .build.info
    CascBuildDb,                                    // .build.db (older storages)
} CBLD_TYPE, *PCBLD_TYPE;

typedef struct _ENCODING_KEY
{
    BYTE Value[MD5_HASH_SIZE];                      // MD5 of the file

} ENCODING_KEY, *PENCODING_KEY;

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

// The encoding file is in the form of:
// * File header
// * String block #1
// * Table A header
// * Table A entries
// * Table B header
// * Table B entries
// * String block #2
// http://pxr.dk/wowdev/wiki/index.php?title=CASC#Key_CASC_Files
typedef struct _CASC_ENCODING_HEADER
{
    BYTE Magic[2];                                  // "EN"
    BYTE Version;                                   // Expected to be 1 by CascLib
    BYTE ChecksumSizeA;                             // The length of the checksums in Encoding Table
    BYTE ChecksumSizeB;                             // The length of the checksums in Encoding Layout Table
    BYTE Flags_TableA[2];                           // Flags for Encoding Table
    BYTE Flags_TableB[2];                           // Flags for Encoding Layout Table
    BYTE Entries_TableA[4];                         // Number of segments in Encoding Table (big endian)
    BYTE Entries_TableB[4];                         // Number of segments in Encoding Layout Table (big endian)
    BYTE field_11;
    BYTE Size_StringTable1[4];                      // Size of the string block #1

} CASC_ENCODING_HEADER, *PCASC_ENCODING_HEADER;

typedef struct _CASC_ENCODING_ENTRY
{
    USHORT KeyCount;                                // Number of index keys
    BYTE FileSizeBE[4];                             // Compressed file size (header area + frame headers + compressed frames), in bytes
    BYTE EncodingKey[MD5_HASH_SIZE];                // File encoding key

    // Followed by the index keys
    // (number of items = KeyCount)
    // Followed by the index keys (number of items = KeyCount)
} CASC_ENCODING_ENTRY, *PCASC_ENCODING_ENTRY;

// A version of CASC_ENCODING_ENTRY with one index key
typedef struct _CASC_ENCODING_ENTRY_1
{
    USHORT KeyCount;                                // Number of index keys
    BYTE FileSizeBE[4];                             // Compressed file size (header area + frame headers + compressed frames), in bytes
    BYTE EncodingKey[MD5_HASH_SIZE];                // File encoding key
    BYTE IndexKey[MD5_HASH_SIZE];                   // File index key

} CASC_ENCODING_ENTRY_1, *PCASC_ENCODING_ENTRY_1;

#define GET_INDEX_KEY(pEncodingEntry)  (pEncodingEntry->EncodingKey + MD5_HASH_SIZE)
#define FAKE_ENCODING_ENTRY_SIZE  (sizeof(CASC_ENCODING_ENTRY) + MD5_HASH_SIZE)

//-----------------------------------------------------------------------------
// Structures for CASC storage and CASC file

typedef struct _TCascStorage
{
    const char * szClassName;                       // "TCascStorage"
    const TCHAR * szIndexFormat;                    // Format of the index file name
    TCHAR * szRootPath;                             // This is the game directory
    TCHAR * szDataPath;                             // This is the directory where data files are
    TCHAR * szBuildFile;                            // Build file name (.build.info or .build.db)
    TCHAR * szIndexPath;                            // This is the directory where index files are
    TCHAR * szUrlPath;                              // URL to the Blizzard servers
    DWORD dwRefCount;                               // Number of references
    DWORD dwGameInfo;                               // Game type
    DWORD dwBuildNumber;                            // Game build number
    DWORD dwFileBeginDelta;                         // This is number of bytes to shift back from archive offset (from index entry) to actual begin of file data
    DWORD dwDefaultLocale;                          // Default locale, read from ".build.info"

    CBLD_TYPE BuildFileType;                        // Type of the build file

    QUERY_KEY CdnConfigKey;
    QUERY_KEY CdnBuildKey;
    QUERY_KEY ArchivesGroup;                        // Key array of the "archive-group"
    QUERY_KEY ArchivesKey;                          // Key array of the "archives"
    QUERY_KEY PatchArchivesKey;                     // Key array of the "patch-archives"
    QUERY_KEY PatchArchivesGroup;                   // Key array of the "patch-archive-group"
    QUERY_KEY RootKey;
    QUERY_KEY PatchKey;
    QUERY_KEY DownloadKey;
    QUERY_KEY InstallKey;
    QUERY_KEY EncodingKey;

    TFileStream * DataFileArray[CASC_MAX_DATA_FILES]; // Data file handles

    CASC_MAPPING_TABLE KeyMapping[CASC_INDEX_COUNT]; // Key mapping
    PCASC_MAP pIndexEntryMap;                       // Map of index entries

    QUERY_KEY EncodingFile;                         // Content of the ENCODING file
    PCASC_MAP pEncodingMap;                         // Map of encoding entries
    DYNAMIC_ARRAY ExtraEntries;                     // Extra encoding entries

    TRootHandler * pRootHandler;                    // Common handler for various ROOT file formats

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
    const char * szClassName;                       // Contains "TCascSearch"
    TCHAR * szListFile;                             // Name of the listfile
    void * pCache;                                  // Listfile cache
    char * szMask;                                  // Search mask
    char szFileName[MAX_PATH];                      // Buffer for the file name

    // Provider-specific data
    void * pRootContext;                            // Root-specific search context
    size_t IndexLevel1;                             // Root-specific search context
    size_t IndexLevel2;                             // Root-specific search context
    DWORD dwState;                                  // Pointer to the search state (0 = listfile, 1 = nameless, 2 = done)

    BYTE BitArray[1];                               // Bit array of encoding keys. Set for each entry that has already been reported

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

void ConvertIntegerToBytes_4(DWORD Value, LPBYTE ValueAsBytes);
void FreeCascBlob(PQUERY_KEY pQueryKey);

//-----------------------------------------------------------------------------
// Text file parsing (CascFiles.cpp)

int LoadBuildInfo(TCascStorage * hs);
int CheckGameDirectory(TCascStorage * hs, TCHAR * szDirectory);

int GetRootVariableIndex(const char * szLinePtr, const char * szLineEnd, const char * szVariableName, int * PtrIndex);
int ParseRootFileLine(const char * szLinePtr, const char * szLineEnd, int nFileNameIndex, PQUERY_KEY pEncodingKey, char * szFileName, size_t nMaxChars);

//-----------------------------------------------------------------------------
// Internal file functions

TCascStorage * IsValidStorageHandle(HANDLE hStorage);
TCascFile * IsValidFileHandle(HANDLE hFile);

PCASC_ENCODING_ENTRY FindEncodingEntry(TCascStorage * hs, PQUERY_KEY pEncodingKey, PDWORD PtrIndex);
PCASC_INDEX_ENTRY    FindIndexEntry(TCascStorage * hs, PQUERY_KEY pIndexKey);

int CascDecompress(LPBYTE pvOutBuffer, PDWORD pcbOutBuffer, LPBYTE pvInBuffer, DWORD cbInBuffer);
int CascDecrypt   (LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer, DWORD dwFrameIndex);
int CascDirectCopy(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer);

//-----------------------------------------------------------------------------
// Support for ROOT file

int RootHandler_CreateMNDX(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateDiablo3(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateOverwatch(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateWoW6(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile, DWORD dwLocaleMask);
int RootHandler_CreateSC1(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);

//-----------------------------------------------------------------------------
// Dumping CASC data structures

#ifdef _DEBUG
void CascDumpSparseArray(const char * szFileName, void * pvSparseArray);
void CascDumpNameFragTable(const char * szFileName, void * pvMarFile);
void CascDumpFileNames(const char * szFileName, void * pvMarFile);
void CascDumpIndexEntries(const char * szFileName, TCascStorage * hs);
void CascDumpEncodingEntry(TCascStorage * hs, TDumpContext * dc, PCASC_ENCODING_ENTRY pEncodingEntry, int nDumpLevel);
void CascDumpFile(const char * szFileName, HANDLE hFile);
#endif  // _DEBUG

#endif // __CASCCOMMON_H__
