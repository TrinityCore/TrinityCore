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
#include "common/Array.h"
#include "common/Map.h"
#include "common/FileTree.h"
#include "common/FileStream.h"
#include "common/Directory.h"
#include "common/ListFile.h"
#include "common/Csv.h"
#include "common/RootHandler.h"

// Headers from Alexander Peslyak's MD5 implementation
#include "md5/md5.h"

// For HashStringJenkins
#include "jenkins/lookup.h"

// On-disk CASC structures
#include "CascStructs.h"

//-----------------------------------------------------------------------------
// CascLib private defines

#ifdef _DEBUG
#define BREAK_ON_XKEY3(CKey, v0, v1, v2) if(CKey[0] == v0 && CKey[1] == v1 && CKey[2] == v2) { __debugbreak(); }
#define BREAKIF(condition)               if(condition)  { __debugbreak(); }
#else
#define BREAK_ON_XKEY3(CKey, v0, v1, v2) { /* NOTHING */ }
#define BREAKIF(condition)               { /* NOTHING */ }
#endif

//-----------------------------------------------------------------------------
// In-memory structures

typedef enum _CBLD_TYPE
{
    CascBuildNone = 0,                              // No build type found
    CascBuildInfo,                                  // .build.info
    CascBuildDb,                                    // .build.db (older storages)
    CascVersionsDb                                  // versions (downloaded online)
} CBLD_TYPE, *PCBLD_TYPE;

// Tag file entry, loaded from the DOWNLOAD file
typedef struct _CASC_TAG_ENTRY
{
    USHORT HashType;                                // Hash type
    char TagName[1];                                // Tag name. Variable length.
} CASC_TAG_ENTRY, *PCASC_TAG_ENTRY;

// Normalized header of the index files.
// Both version 1 and version 2 are converted to this structure
typedef struct _CASC_INDEX_HEADER
{
    USHORT IndexVersion;                            // 5 for index v 1.0, 7 for index version 2.0
    BYTE   BucketIndex;                             // Should be the same as the first byte of the hex filename. 
    BYTE   StorageOffsetLength;                     // Length, in bytes, of the StorageOffset field in the EKey entry
    BYTE   EncodedSizeLength;                       // Length, in bytes, of the EncodedSize in the EKey entry
    BYTE   EKeyLength;                              // Length, in bytes, of the (trimmed) EKey in the EKey entry
    BYTE   FileOffsetBits;                          // Number of bits of the archive file offset in StorageOffset field. Rest is data segment index
    BYTE   Alignment;
    ULONGLONG SegmentSize;                          // Size of one data segment (aka data.### file)
    size_t HeaderLength;                            // Length of the on-disk header structure, in bytes
    size_t HeaderPadding;                           // Length of padding after the header
    size_t EntryLength;                             // Length of the on-disk EKey entry structure, in bytes
    size_t EKeyCount;                               // Number of EKey entries. Only supplied for index files version 1.

} CASC_INDEX_HEADER, *PCASC_INDEX_HEADER;

// Normalized footer of the archive index files (md5.index)
typedef struct _CASC_ARCINDEX_FOOTER
{
    BYTE   TocHash[MD5_HASH_SIZE];                  // Hash of the structure
    BYTE   FooterHash[MD5_HASH_SIZE];               // MD5 hash of the footer, possibly shortened
    BYTE   Version;                                 // Version of the index footer
    BYTE   OffsetBytes;                             // Length, in bytes, of the file offset field
    BYTE   SizeBytes;                               // Length, in bytes, of the file size field
    BYTE   EKeyBytes;                               // Length, in bytes, of the EKey field
    BYTE   FooterHashBytes;                         // Length, in bytes, of the hash and checksum
    BYTE   Alignment[3];
    size_t ElementCount;                            // total number of elements in the index file
    size_t PageLength;                              // Length, in bytes, of the index page
    size_t ItemLength;                              // Length, in bytes, of the single item
    size_t FooterLength;                            // Length, in bytes, of the index footer structure

} CASC_ARCINDEX_FOOTER, *PCASC_ARCINDEX_FOOTER;

// Normalized structure for archive index entry
typedef struct _CASC_ARCINDEX_ENTRY
{
    BYTE IndexHash[MD5_HASH_SIZE];
    BYTE EKey[MD5_HASH_SIZE];
    DWORD ArchiveOffset;
    DWORD EncodedSize;
} CASC_ARCINDEX_ENTRY, *PCASC_ARCINDEX_ENTRY;

// Normalized header of the ENCODING file
typedef struct _CASC_ENCODING_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_ENCODING ('EN')
    USHORT Version;                                 // Expected to be 1 by CascLib
    BYTE   CKeyLength;                              // The content key length in ENCODING file. Usually 0x10
    BYTE   EKeyLength;                              // The encoded key length in ENCODING file. Usually 0x10
    DWORD  CKeyPageSize;                            // Size of the CKey page in bytes
    DWORD  EKeyPageSize;                            // Size of the CKey page in bytes
    DWORD  CKeyPageCount;                           // Number of CKey pages in the page table
    DWORD  EKeyPageCount;                           // Number of EKey pages in the page table
    DWORD  ESpecBlockSize;                          // Size of the ESpec string block, in bytes
} CASC_ENCODING_HEADER, *PCASC_ENCODING_HEADER;

typedef struct _CASC_DOWNLOAD_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_DOWNLOAD ('DL')
    USHORT Version;                                 // Version
    USHORT EKeyLength;                              // Length of the EKey
    USHORT EntryHasChecksum;                        // If nonzero, then the entry has checksum
    DWORD  EntryCount;
    DWORD  TagCount;
    USHORT FlagByteSize;
    USHORT BasePriority;

    size_t HeaderLength;                            // Length of the on-disk header, in bytes
    size_t EntryLength;                             // Length of the on-disk entry, in bytes

} CASC_DOWNLOAD_HEADER, *PCASC_DOWNLOAD_HEADER;

typedef struct _CASC_DOWNLOAD_ENTRY
{
    BYTE EKey[MD5_HASH_SIZE];
    ULONGLONG EncodedSize;
    DWORD Checksum;
    DWORD Flags;
    BYTE Priority;
} CASC_DOWNLOAD_ENTRY, *PCASC_DOWNLOAD_ENTRY;

// Capturable tag structure for loading from DOWNLOAD manifest
typedef struct _CASC_TAG_ENTRY1
{
    const char * szTagName;                         // Tag name
    LPBYTE Bitmap;                                  // Bitmap
    size_t BitmapLength;                            // Length of the bitmap, in bytes
    size_t NameLength;                              // Length of the tag name, in bytes, not including '\0'
    size_t TagLength;                               // Length of the on-disk tag, in bytes
    DWORD TagValue;                                 // Tag value
} CASC_TAG_ENTRY1, *PCASC_TAG_ENTRY1;

// Tag structure for storing in arrays
typedef struct _CASC_TAG_ENTRY2
{
    size_t NameLength;                              // Length of the on-disk tag, in bytes
    DWORD TagValue;                                 // Tag value
    char szTagName[0x08];                           // Tag string. This member can be longer than declared. Aligned to 8 bytes.
} CASC_TAG_ENTRY2, *PCASC_TAG_ENTRY2;

typedef struct _CASC_INSTALL_HEADER
{
    USHORT Magic;                                   // FILE_MAGIC_DOWNLOAD ('DL')
    BYTE   Version;                                 // Version
    BYTE   EKeyLength;                              // Length of the EKey
    DWORD  EntryCount;
    DWORD  TagCount;

    size_t HeaderLength;                            // Length of the on-disk header, in bytes
} CASC_INSTALL_HEADER, *PCASC_INSTALL_HEADER;

typedef struct _CASC_FILE_FRAME
{
    CONTENT_KEY FrameHash;                          // MD5 hash of the file frame
    DWORD DataFileOffset;                           // Offset in the data file (data.###)
    DWORD FileOffset;                               // File offset of this frame
    DWORD EncodedSize;                              // Encoded size of the frame
    DWORD ContentSize;                              // Content size of the frame
} CASC_FILE_FRAME, *PCASC_FILE_FRAME;

//-----------------------------------------------------------------------------
// Structures for CASC storage and CASC file

struct TCascStorage
{
    TCascStorage();
    ~TCascStorage();
    TCascStorage * AddRef();
    TCascStorage * Release();

    static TCascStorage * IsValid(HANDLE hStorage);

    PFNPROGRESSCALLBACK PfnCallback;                // Callback to be called during CascOpen(Online)Storage
    void * PtrCallbackParam;

    const TCHAR * szIndexFormat;                    // Format of the index file name
    const char * szClassName;                       // "TCascStorage"
    const char * szProductName;                     // String representation of the product name
    TCHAR * szRootPath;                             // Path where the build file is
    TCHAR * szDataPath;                             // This is the directory where data files are
    TCHAR * szIndexPath;                            // This is the directory where index files are
    TCHAR * szBuildFile;                            // Build file name (.build.info or .build.db)
    TCHAR * szCdnServers;                           // Multi-SZ list of CDN servers
    TCHAR * szCdnPath;                              // Remote CDN sub path for the product
    TCHAR * szCodeName;                             // Product code name. Only for online storages
    char * szRegion;                                // Product region. Only when "versions" is used as storage root file
    CASC_PRODUCT Product;                           // Product enum value (see CASC_PRODUCT)
    DWORD dwBuildNumber;                            // Product build number
    DWORD dwRefCount;                               // Number of references
    DWORD dwDefaultLocale;                          // Default locale, read from ".build.info"
    DWORD dwFeatures;                               // List of CASC features. See CASC_FEATURE_XXX
    bool bAllowOrphans;                             // If TRUE, then orphaned items are allowed

    CBLD_TYPE BuildFileType;                        // Type of the build file

    QUERY_KEY CdnConfigKey;                         // Currently selected CDN config file. Points to "config\%02X\%02X\%s
    QUERY_KEY CdnBuildKey;                          // Currently selected CDN build file. Points to "config\%02X\%02X\%s

    QUERY_KEY ArchiveGroup;                         // Key array of the "archive-group"
    QUERY_KEY ArchivesKey;                          // Key array of the "archives"
    QUERY_KEY PatchArchivesKey;                     // Key array of the "patch-archives"
    QUERY_KEY PatchArchivesGroup;                   // Key array of the "patch-archive-group"
    QUERY_KEY BuildFiles;                           // List of supported build files

    TFileStream * DataFiles[CASC_MAX_DATA_FILES];   // Array of open data files

    CASC_CKEY_ENTRY EncodingCKey;                   // Information about ENCODING file
    CASC_CKEY_ENTRY DownloadCKey;                   // Information about DOWNLOAD file
    CASC_CKEY_ENTRY InstallCKey;                    // Information about INSTALL file
    CASC_CKEY_ENTRY PatchFile;                      // Information about PATCH file
    CASC_CKEY_ENTRY RootFile;                       // Information about ROOT file
    CASC_CKEY_ENTRY SizeFile;                       // Information about SIZE file
    CASC_CKEY_ENTRY VfsRoot;                        // The main VFS root file
    CASC_ARRAY VfsRootList;                         // List of CASC_EKEY_ENTRY for each TVFS sub-root

    TRootHandler * pRootHandler;                    // Common handler for various ROOT file formats
    CASC_ARRAY ArcIndexArray;                       // Array of CASC_ARCINDEX_ENTRY, loaded from archive indexes
    CASC_ARRAY IndexArray;                          // Array of CASC_CKEY_ENTRY loaded from local index files
    CASC_ARRAY CKeyArray;                           // Array of CASC_CKEY_ENTRY, one entry for each physical file
    CASC_ARRAY TagsArray;                           // Array of CASC_DOWNLOAD_TAG2
    CASC_MAP ArcIndexMap;                           // Map of EKey -> CASC_ARCINDEX_ENTRY
    CASC_MAP CKeyMap;                               // Map of CKey -> CASC_CKEY_ENTRY
    CASC_MAP EKeyMap;                               // Map of EKey -> CASC_EKEY_ENTRY
    size_t LocalFiles;                              // Number of files that are present locally
    size_t TotalFiles;                              // Total number of files in the storage, some may not be present locally
    size_t EKeyEntries;                             // Number of CKeyEntry-ies loaded from text build file
    size_t OrphanItems;                             // Number of EKey entries in indexes that do not have their counterpart in ENCODING
    size_t SkippedItems;                            // Number of EKey entries in indexes that were ignored due to insufficient capacity of CKeyArray
    size_t EKeyLength;                              // EKey length from the index files
    DWORD FileOffsetBits;                           // Nimber of bits in the storage offset which mean data segent offset

    CASC_ARRAY ExtraKeysList;                       // List additional encryption keys
    CASC_MAP   EncryptionKeys;                      // Map of encryption keys

};

struct TCascFile
{
    TCascFile(TCascStorage * ahs, PCASC_CKEY_ENTRY apCKeyEntry)
    {
        ULONGLONG StorageOffset;
        ULONGLONG FileOffsMask;

        // Reference the storage handle
        hs = ahs->AddRef();
        szClassName = "TCascFile";

        // Init class variables
        pCKeyEntry = apCKeyEntry;
        pFrames = NULL;
        pbFileCache = NULL;
        cbFileCache = 0;

        // Supply the sizes
        StorageOffset = pCKeyEntry->StorageOffset;
        FileOffsMask = ((ULONGLONG)1 << hs->FileOffsetBits) - 1;
        ArchiveIndex = (DWORD)(StorageOffset >> hs->FileOffsetBits);
        ArchiveOffset = (DWORD)(StorageOffset & FileOffsMask);
        EncodedSize = pCKeyEntry->EncodedSize;
        ContentSize = pCKeyEntry->ContentSize;
        FilePointer = 0;
        FrameCount = 0;
        bVerifyIntegrity = false;
        bDownloadFileIf = false;
        bLocalFileStream = false;
    }

    ~TCascFile()
    {
        // Close (dereference) the archive handle
        hs = hs->Release();
        szClassName = NULL;

        // Free the file cache and frame array
        CASC_FREE(pbFileCache);
        CASC_FREE(pFrames);

        // If we are supposed to close the file stream, do it
        if (pStream && bLocalFileStream)
            FileStream_Close(pStream);
    }

    static TCascFile * IsValid(HANDLE hFile)
    {
        TCascFile * hf = (TCascFile *)hFile;

        return (hf != INVALID_HANDLE_VALUE &&
                hf != NULL &&
                hf->hs != NULL &&
                hf->szClassName != NULL &&
                hf->pCKeyEntry != NULL) ? hf : NULL;
    }

    TCascStorage * hs;                              // Pointer to storage structure
    TFileStream * pStream;                          // An open data stream
    const char * szClassName;                       // "TCascFile"

    PCASC_CKEY_ENTRY pCKeyEntry;
    PCASC_FILE_FRAME pFrames;                       // Array of file frames
    DWORD ArchiveIndex;                             // Index of the archive (data.###)
    DWORD ArchiveOffset;                            // Offset in the archive (data.###)
    DWORD FilePointer;                              // Current file pointer
    DWORD EncodedSize;                              // Encoded size. This is the size of encoded header, all file frame headers and all file frames
    DWORD ContentSize;                              // Content size. This is the size of the file content, aka the file size
    DWORD FrameCount;                               // Number of the file frames
    DWORD bVerifyIntegrity:1;                       // If true, then the data are validated more strictly when read
    DWORD bDownloadFileIf:1;                        // If true, then the data will be downloaded from the online storage if missing
    DWORD bLocalFileStream:1;                       // If true, then the file stream is a local file
    DWORD bOvercomeEncrypted:1;                     // If true, then CascReadFile will fill the part that is encrypted (and key was not found) with zeros 

    LPBYTE pbFileCache;                             // Pointer to file cache
    DWORD cbFileCache;                              // Size of the file cache

};

struct TCascSearch
{
    TCascSearch(TCascStorage * ahs, LPCTSTR aszListFile, const char * aszMask)
    {
        // Init the class
        szClassName = "TCascSearch";
        hs = ahs->AddRef();

        // Init provider-specific data
        pCache = NULL;
        nFileIndex = 0;
        nSearchState = 0;
        bListFileUsed = false;

        // Allocate mask
        szListFile = CascNewStr(aszListFile);
        szMask = CascNewStr((aszMask != NULL) ? aszMask : "*");
    }

    ~TCascSearch()
    {
        // Dereference the CASC storage
        hs = hs->Release();
        szClassName = NULL;

        // Free the rest of the members
        CASC_FREE(szMask);
        CASC_FREE(szListFile);
        CASC_FREE(pCache);
    }

    static TCascSearch * IsValid(HANDLE hFind)
    {
        TCascSearch * pSearch = (TCascSearch *)hFind;

        return (hFind != INVALID_HANDLE_VALUE &&
                hFind != NULL &&
                pSearch->szClassName != NULL &&
               !strcmp(pSearch->szClassName, "TCascSearch") &&
                pSearch->szMask != NULL) ? pSearch : NULL;
    }

    TCascStorage * hs;                              // Pointer to the storage handle
    const char * szClassName;                       // Contains "TCascSearch"
    TCHAR * szListFile;                             // Name of the listfile
    void * pCache;                                  // Listfile cache
    char * szMask;                                  // Search mask

    // Provider-specific data
    size_t nFileIndex;                              // Root-specific search context
    DWORD nSearchState:8;                           // The current search state (0 = listfile, 1 = nameless, 2 = done)
    DWORD bListFileUsed:1;                          // TRUE: The listfile has already been loaded
};

//-----------------------------------------------------------------------------
// Common functions (CascCommon.cpp)

bool OpenFileByCKeyEntry(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, DWORD dwOpenFlags, HANDLE * PtrFileHandle);
LPBYTE LoadInternalFileToMemory(TCascStorage * hs, PCASC_CKEY_ENTRY pCKeyEntry, DWORD * pcbFileData);
LPBYTE LoadFileToMemory(const TCHAR * szFileName, DWORD * pcbFileData);
void FreeCascBlob(PQUERY_KEY pQueryKey);

//-----------------------------------------------------------------------------
// Text file parsing (CascFiles.cpp)

int DownloadFileFromCDN(TCascStorage * hs, const TCHAR * szSubDir, LPBYTE pbEKey, const TCHAR * szExtension, TCHAR * szOutLocalPath, size_t cchOutLocalPath);
int CheckGameDirectory(TCascStorage * hs, TCHAR * szDirectory);
int LoadCdnsInfo(TCascStorage * hs);
int LoadBuildInfo(TCascStorage * hs);
int LoadCdnConfigFile(TCascStorage * hs);
int LoadCdnBuildFile(TCascStorage * hs);

//-----------------------------------------------------------------------------
// Internal file functions

void * ProbeOutputBuffer(void * pvBuffer, size_t cbLength, size_t cbMinLength, size_t * pcbLengthNeeded);

PCASC_CKEY_ENTRY FindCKeyEntry_CKey(TCascStorage * hs, LPBYTE pbCKey, PDWORD PtrIndex = NULL);
PCASC_CKEY_ENTRY FindCKeyEntry_EKey(TCascStorage * hs, LPBYTE pbEKey, PDWORD PtrIndex = NULL);

size_t GetTagBitmapLength(LPBYTE pbFilePtr, LPBYTE pbFileEnd, DWORD EntryCount);

int CascDecompress(LPBYTE pvOutBuffer, PDWORD pcbOutBuffer, LPBYTE pvInBuffer, DWORD cbInBuffer);
int CascDirectCopy(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer);

int CascLoadEncryptionKeys(TCascStorage * hs);
int CascDecrypt(TCascStorage * hs, LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer, DWORD dwFrameIndex);

//-----------------------------------------------------------------------------
// Support for index files

int LoadIndexFiles(TCascStorage * hs);

//-----------------------------------------------------------------------------
// Support for ROOT file

int RootHandler_CreateMNDX(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateTVFS(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateDiablo3(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateWoW(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile, DWORD dwLocaleMask);
int RootHandler_CreateOverwatch(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateStarcraft1(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);
int RootHandler_CreateInstall(TCascStorage * hs, LPBYTE pbRootFile, DWORD cbRootFile);

//-----------------------------------------------------------------------------
// Dumpers (CascDumpData.cpp)

#ifdef _DEBUG
void CascDumpFile(HANDLE hFile, const char * szDumpFile = NULL);
void CascDumpStorage(HANDLE hStorage, const char * szDumpFile = NULL);
#endif

#endif // __CASCCOMMON_H__
