/*****************************************************************************/
/* CascLib.h                              Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* CascLib library v 1.00                                                    */
/*                                                                           */
/* Author : Ladislav Zezula                                                  */
/* E-mail : ladik@zezula.net                                                 */
/* WWW    : http://www.zezula.net                                            */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  Created                                              */
/*****************************************************************************/

#ifndef __CASCLIB_H__
#define __CASCLIB_H__

#ifdef _MSC_VER
#pragma warning(disable:4668)       // 'XXX' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif' 
#pragma warning(disable:4820)       // 'XXX' : '2' bytes padding added after data member 'XXX::yyy'
#endif                                             

#include "CascPort.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Defines

#define CASCLIB_VERSION                 0x0100  // Current version of CascLib (1.0)
#define CASCLIB_VERSION_STRING          "1.00"  // String version of CascLib version

#define ERROR_UNKNOWN_FILE_KEY           10001  // Returned by encrypted stream when can't find file key
#define ERROR_FILE_INCOMPLETE            10006  // The required file part is missing

// Values for CascOpenStorage
#define CASC_STOR_XXXXX             0x00000001  // Not used

// Values for CascOpenFile
#define CASC_FILE_XXXXX             0x00000001  // Not used

// Flags for file stream
#define BASE_PROVIDER_FILE          0x00000000  // Base data source is a file
#define BASE_PROVIDER_MAP           0x00000001  // Base data source is memory-mapped file
#define BASE_PROVIDER_HTTP          0x00000002  // Base data source is a file on web server
#define BASE_PROVIDER_MASK          0x0000000F  // Mask for base provider value

#define STREAM_PROVIDER_FLAT        0x00000000  // Stream is linear with no offset mapping
#define STREAM_PROVIDER_PARTIAL     0x00000010  // Stream is partial file (.part)
#define STREAM_PROVIDER_ENCRYPTED   0x00000020  // Stream is an encrypted archive
#define STREAM_PROVIDER_BLOCK4      0x00000030  // 0x4000 per block, text MD5 after each block, max 0x2000 blocks per file
#define STREAM_PROVIDER_MASK        0x000000F0  // Mask for stream provider value

#define STREAM_FLAG_READ_ONLY       0x00000100  // Stream is read only
#define STREAM_FLAG_WRITE_SHARE     0x00000200  // Allow write sharing when open for write
#define STREAM_FLAG_USE_BITMAP      0x00000400  // If the file has a file bitmap, load it and use it
#define STREAM_OPTIONS_MASK         0x0000FF00  // Mask for stream options

#define STREAM_PROVIDERS_MASK       0x000000FF  // Mask to get stream providers
#define STREAM_FLAGS_MASK           0x0000FFFF  // Mask for all stream flags (providers+options)

#define CASC_LOCALE_ALL             0xFFFFFFFF
#define CASC_LOCALE_NONE            0x00000000
#define CASC_LOCALE_UNKNOWN1        0x00000001
#define CASC_LOCALE_ENUS            0x00000002
#define CASC_LOCALE_KOKR            0x00000004 
#define CASC_LOCALE_UNKNOWN8        0x00000008 
#define CASC_LOCALE_FRFR            0x00000010 
#define CASC_LOCALE_DEDE            0x00000020 
#define CASC_LOCALE_ZHCN            0x00000040 
#define CASC_LOCALE_ESES            0x00000080 
#define CASC_LOCALE_ZHTW            0x00000100  
#define CASC_LOCALE_ENGB            0x00000200 
#define CASC_LOCALE_ENCN            0x00000400 
#define CASC_LOCALE_ENTW            0x00000800 
#define CASC_LOCALE_ESMX            0x00001000 
#define CASC_LOCALE_RURU            0x00002000 
#define CASC_LOCALE_PTBR            0x00004000  
#define CASC_LOCALE_ITIT            0x00008000 
#define CASC_LOCALE_PTPT            0x00010000

#define MAX_CASC_KEY_LENGTH               0x10  // Maximum length of the key (equal to MD5 hash)

#ifndef MD5_HASH_SIZE
#define MD5_HASH_SIZE                     0x10
#define MD5_STRING_SIZE                   0x21
#endif

#ifndef SHA1_DIGEST_SIZE
#define SHA1_DIGEST_SIZE                  0x14  // 160 bits
#endif

#ifndef LANG_NEUTRAL
#define LANG_NEUTRAL                      0x00  // Neutral locale
#endif

// Return value for CascGetFileSize and CascSetFilePointer
#define CASC_INVALID_SIZE           0xFFFFFFFF
#define CASC_INVALID_POS            0xFFFFFFFF

// Flags for CascGetStorageInfo
#define CASC_FEATURE_LISTFILE       0x00000001  // The storage supports listfile

//-----------------------------------------------------------------------------
// Structures

typedef enum _CASC_STORAGE_INFO_CLASS
{
    CascStorageFileCount,
    CascStorageFeatures,
    CascStorageInfoClassMax

} CASC_STORAGE_INFO_CLASS, *PCASC_STORAGE_INFO_CLASS;


typedef struct _QUERY_KEY
{
    LPBYTE pbData;
    DWORD cbData;
} QUERY_KEY, *PQUERY_KEY;

// Structure for SFileFindFirstFile and SFileFindNextFile
typedef struct _CASC_FIND_DATA
{
    char   szFileName[MAX_PATH];                // Full name of the found file
    char * szPlainName;                         // Plain name of the found file
    ULONGLONG FileNameHash;                     // File name hash
    BYTE   EncodingKey[MD5_HASH_SIZE];          // Encoding key
    DWORD  dwPackageIndex;                      // File package index (HOTS only)
    DWORD  dwLocaleFlags;                       // Locale flags (WoW only)
    DWORD  dwFileSize;                          // Size of the file

} CASC_FIND_DATA, *PCASC_FIND_DATA;

//-----------------------------------------------------------------------------
// Callback functions

typedef struct TFileStream TFileStream;
typedef void (WINAPI * STREAM_DOWNLOAD_CALLBACK)(void * pvUserData, ULONGLONG ByteOffset, DWORD dwTotalBytes);

//-----------------------------------------------------------------------------
// We have our own qsort implementation, optimized for sorting array of pointers

void qsort_pointer_array(void ** base, size_t num, int (*compare)(const void *, const void *, const void *), const void * context);

//-----------------------------------------------------------------------------
// Functions for storage manipulation

bool  WINAPI CascOpenStorage(const TCHAR * szDataPath, DWORD dwFlags, HANDLE * phStorage);
bool  WINAPI CascGetStorageInfo(HANDLE hStorage, CASC_STORAGE_INFO_CLASS InfoClass, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded);
bool  WINAPI CascCloseStorage(HANDLE hStorage);

bool  WINAPI CascOpenFileByIndexKey(HANDLE hStorage, PQUERY_KEY pIndexKey, DWORD dwFlags, HANDLE * phFile);
bool  WINAPI CascOpenFileByEncodingKey(HANDLE hStorage, PQUERY_KEY pEncodingKey, DWORD dwFlags, HANDLE * phFile);
bool  WINAPI CascOpenFile(HANDLE hStorage, const char * szFileName, DWORD dwLocale, DWORD dwFlags, HANDLE * phFile);
DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh);
DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod);
bool  WINAPI CascReadFile(HANDLE hFile, void * lpBuffer, DWORD dwToRead, PDWORD pdwRead);
bool  WINAPI CascCloseFile(HANDLE hFile);

HANDLE WINAPI CascFindFirstFile(HANDLE hStorage, const char * szMask, PCASC_FIND_DATA pFindData, const TCHAR * szListFile);
bool  WINAPI CascFindNextFile(HANDLE hFind, PCASC_FIND_DATA pFindData);
bool  WINAPI CascFindClose(HANDLE hFind);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif  // __CASCLIB_H__
