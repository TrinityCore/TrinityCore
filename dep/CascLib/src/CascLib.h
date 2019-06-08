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

#define CASCLIB_VERSION                 0x0132  // Current version of CascLib (1.50)
#define CASCLIB_VERSION_STRING          "1.50"  // String version of CascLib version

// Values for CascOpenFile
#define CASC_OPEN_BY_NAME           0x00000000  // Open the file by name. This is the default value
#define CASC_OPEN_BY_CKEY           0x00000001  // The name is just the content key; skip ROOT file processing
#define CASC_OPEN_BY_EKEY           0x00000002  // The name is just the encoded key; skip ROOT file processing
#define CASC_OPEN_BY_FILEID         0x00000003  // The name is CASC_IDTONAME(FileDataId)
#define CASC_OPEN_TYPE_MASK         0x0000000F  // The mask which gets open type from the dwFlags
#define CASC_OPEN_FLAGS_MASK        0xFFFFFFF0  // The mask which gets open type from the dwFlags
#define CASC_STRICT_DATA_CHECK      0x00000010  // Verify all data read from a file

#define CASC_LOCALE_ALL             0xFFFFFFFF
#define CASC_LOCALE_NONE            0x00000000
#define CASC_LOCALE_UNKNOWN1        0x00000001
#define CASC_LOCALE_ENUS            0x00000002
#define CASC_LOCALE_KOKR            0x00000004
#define CASC_LOCALE_RESERVED        0x00000008
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

// Content flags on WoW
#define CASC_CFLAG_LOAD_ON_WINDOWS        0x08
#define CASC_CFLAG_LOAD_ON_MAC            0x10
#define CASC_CFLAG_LOW_VIOLENCE           0x80
#define CASC_CFLAG_DONT_LOAD             0x100
#define CASC_CFLAG_NO_NAME_HASH     0x10000000
#define CASC_CFLAG_BUNDLE           0x40000000
#define CASC_CFLAG_NO_COMPRESSION   0x80000000

#ifndef MD5_HASH_SIZE
#define MD5_HASH_SIZE                     0x10
#define MD5_STRING_SIZE                   0x20
#endif

#ifndef SHA1_DIGEST_SIZE
#define SHA1_DIGEST_SIZE                  0x14  // 160 bits
#endif

// Return value for CascGetFileSize and CascSetFilePointer
#define CASC_INVALID_INDEX          0xFFFFFFFF
#define CASC_INVALID_SIZE           0xFFFFFFFF
#define CASC_INVALID_POS            0xFFFFFFFF
#define CASC_INVALID_ID             0xFFFFFFFF
#define CASC_INVALID_OFFS64         0xFFFFFFFFFFFFFFFF

// Flags for CASC_STORAGE_FEATURES::dwFeatures
#define CASC_FEATURE_FILE_NAMES     0x00000001  // File names are supported by the storage
#define CASC_FEATURE_ROOT_CKEY      0x00000002  // Present if the storage's ROOT returns CKey
#define CASC_FEATURE_TAGS           0x00000002  // Tags are supported by the storage
#define CASC_FEATURE_FNAME_HASHES   0x00000004  // The storage contains file name hashes on ALL files
#define CASC_FEATURE_FNAME_HASHES_OPTIONAL 0x00000008  // The storage contains file name hashes for SOME files
#define CASC_FEATURE_FILE_DATA_IDS  0x00000010  // The storage indexes files by FileDataId
#define CASC_FEATURE_LOCALE_FLAGS   0x00000020  // Locale flags are supported
#define CASC_FEATURE_CONTENT_FLAGS  0x00000040  // Content flags are supported
#define CASC_FEATURE_ONLINE         0x00000080  // The storage is an online storage

// Macro to convert FileDataId to the argument of CascOpenFile
#define CASC_FILE_DATA_ID(FileDataId) ((LPCSTR)(size_t)FileDataId)
#define CASC_FILE_DATA_ID_FROM_STRING(szFileName)  ((DWORD)(size_t)szFileName)

//-----------------------------------------------------------------------------
// Structures

typedef enum _CASC_STORAGE_INFO_CLASS
{
    // Returns the number of local files in the storage. Note that files
    // can exist under different names, so the total number of files in the archive
    // can be higher than the value returned by this info class
    CascStorageLocalFileCount,

    // Returns the total file count, including the offline files
    CascStorageTotalFileCount,

    // Returns the CASC_STORAGE_FEATURES structure.
    CascStorageFeatures,
    CascStorageInstalledLocales,
    CascStorageProduct,                         // Gives CASC_STORAGE_PRODUCT
    CascStorageTags,                            // Gives CASC_STORAGE_TAGS structure
    CascStorageInfoClassMax

} CASC_STORAGE_INFO_CLASS, *PCASC_STORAGE_INFO_CLASS;

typedef enum _CASC_FILE_INFO_CLASS
{
    CascFileContentKey,
    CascFileEncodedKey,
    CascFileFullInfo,                           // Gives CASC_FILE_FULL_INFO structure
    CascFileInfoClassMax
} CASC_FILE_INFO_CLASS, *PCASC_FILE_INFO_CLASS;

// See https://wowdev.wiki/TACT#Products
typedef enum _CASC_PRODUCT
{
    UnknownProduct,
    HeroesOfTheStorm,
    Diablo3,
    Overwatch,
    StarCraft1,
    StarCraft2,
    WorldOfWarcraft,
    WarCraft3,
    Destiny2,
    CallOfDutyBlackOps4,
    Odin,
    MaxProductValue

} CASC_PRODUCT, *PCASC_PRODUCT;

// CascLib may provide a fake name, constructed from file data id, CKey or EKey.
// This enum helps to see what name was actually returned
// Note that any of these names can be passed to CascOpenFile with no extra flags
typedef enum _CASC_NAME_TYPE
{
    CascNameFull,                               // Fully qualified file name
    CascNameDataId,                             // Name created from file data id (FILE%08X.dat)
    CascNameCKey,                               // Name created as string representation of CKey
    CascNameEKey                                // Name created as string representation of EKey
} CASC_NAME_TYPE, *PCASC_NAME_TYPE; 

// Structure for SFileFindFirstFile and SFileFindNextFile
typedef struct _CASC_FIND_DATA
{
    // Full name of the found file. In case when this is CKey/EKey,
    // this will be just string representation of the key stored in 'FileKey'
    char szFileName[MAX_PATH];
    
    // Content key. This is present if the CASC_FEATURE_ROOT_CKEY is present
    BYTE CKey[MD5_HASH_SIZE];

    // Encoded key. This is always present.
    BYTE EKey[MD5_HASH_SIZE];

    // Tag mask. Only valid if the storage supports tags, otherwise 0
    ULONGLONG TagBitMask;

    // Plain name of the found file. Pointing inside the 'szFileName' array
    char * szPlainName;

    // File data ID. Only valid if the storage supports file data IDs, otherwise CASC_INVALID_ID
    DWORD dwFileDataId;
    
    // Size of the file, as retrieved from CKey entry or EKey entry
    DWORD dwFileSize;

    // Locale flags. Only valid if the storage supports locale flags, otherwise CASC_INVALID_ID
    DWORD dwLocaleFlags;

    // Content flags. Only valid if the storage supports content flags, otherwise CASC_INVALID_ID
    DWORD dwContentFlags;

    // Hints as for which open method is suitable
    DWORD bFileAvailable:1;                     // If true the file is available locally
    DWORD bCanOpenByName:1;
    DWORD bCanOpenByDataId:1;
    DWORD bCanOpenByCKey:1;
    DWORD bCanOpenByEKey:1;
    CASC_NAME_TYPE NameType;

} CASC_FIND_DATA, *PCASC_FIND_DATA;

typedef struct _CASC_STORAGE_TAG
{
    LPCSTR szTagName;                           // Tag name (zero terminated, ANSI)
    DWORD TagNameLength;                        // Length of the tag name
    DWORD TagValue;                             // Tag value
} CASC_STORAGE_TAG, *PCASC_STORAGE_TAG;

typedef struct _CASC_STORAGE_TAGS
{
    size_t TagCount;                            // Number of items in the Tags array
    size_t Reserved;                            // Reserved for future use

    CASC_STORAGE_TAG Tags[1];                   // Array of CASC tags

} CASC_STORAGE_TAGS, *PCASC_STORAGE_TAGS; 

typedef struct _CASC_STORAGE_PRODUCT
{
    LPCSTR szProductName;
    DWORD dwBuildNumber;
    CASC_PRODUCT Product;

} CASC_STORAGE_PRODUCT, *PCASC_STORAGE_PRODUCT;

typedef struct _CASC_FILE_FULL_INFO
{
    BYTE CKey[MD5_HASH_SIZE];                   // CKey
    BYTE EKey[MD5_HASH_SIZE];                   // EKey
    char  DataFileName[0x10];                   // Plain name of the data file where the file is stored
    ULONGLONG StorageOffset;                    // Offset of the file over the entire storage
    ULONGLONG SegmentOffset;                    // Offset of the file in the segment file ("data.###")
    ULONGLONG TagBitMask;                       // Bitmask of tags. Zero if not supported
    ULONGLONG FileNameHash;                     // Hash of the file name. Zero if not supported
    DWORD SegmentIndex;                         // Index of the segment file (aka 0 = "data.000")
    DWORD FileDataId;                           // File data ID. CASC_INVALID_ID if not supported.
    DWORD ContentSize;                          // Content size of the file
    DWORD EncodedSize;                          // Encoded size of the file
    DWORD LocaleFlags;                          // Locale flags. CASC_INVALID_ID if not supported.
    DWORD ContentFlags;                         // Locale flags. CASC_INVALID_ID if not supported

} CASC_FILE_FULL_INFO, *PCASC_FILE_FULL_INFO;

//-----------------------------------------------------------------------------
// Some operations (e.g. opening an online storage) may take long time.
// This callback allows an application to be notified about loading progress.
// This callback only works for a single CascOpen(Online)Storage call.

typedef bool (WINAPI * PFNPROGRESSCALLBACK)(    // Return 'true' to cancel the loading process
    void * PtrUserParam,                        // User-specific parameter passed to the callback
    LPCSTR szWork,                              // Text for the current activity (example: "Loading "ENCODING" file")
    LPCSTR szObject,                            // (optional) name of the object tied to the activity (example: index file name)
    DWORD nCurrent,                             // (optional) current object being processed
    DWORD nTotal                                // (optional) If non-zero, this is the total number of objects to process
    );

void WINAPI CascSetProgressCallback(
    PFNPROGRESSCALLBACK PtrUserCallback,        // Pointer to the callback function that will be called during opening the storage
    void * PtrUserParam                         // Arbitrary user parameter that will be passed to the callback
    );

//-----------------------------------------------------------------------------
// Functions for storage manipulation

bool  WINAPI CascOpenStorage(LPCTSTR szDataPath, DWORD dwLocaleMask, HANDLE * phStorage);
bool  WINAPI CascOpenOnlineStorage(LPCTSTR szLocalCache, LPCSTR szCodeName, LPCSTR szRegion, DWORD dwLocaleMask, HANDLE * phStorage);
bool  WINAPI CascGetStorageInfo(HANDLE hStorage, CASC_STORAGE_INFO_CLASS InfoClass, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded);
bool  WINAPI CascAddEncryptionKey(HANDLE hStorage, ULONGLONG KeyName, LPBYTE Key);
LPBYTE WINAPI CascFindEncryptionKey(HANDLE hStorage, ULONGLONG KeyName);
bool  WINAPI CascCloseStorage(HANDLE hStorage);

bool  WINAPI CascOpenFile(HANDLE hStorage, const void * pvFileName, DWORD dwLocaleFlags, DWORD dwOpenFlags, HANDLE * phFile);
bool  WINAPI CascGetFileInfo(HANDLE hFile, CASC_FILE_INFO_CLASS InfoClass, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded);
DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh);
DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * plFilePosHigh, DWORD dwMoveMethod);
bool  WINAPI CascReadFile(HANDLE hFile, void * lpBuffer, DWORD dwToRead, PDWORD pdwRead);
bool  WINAPI CascCloseFile(HANDLE hFile);

HANDLE WINAPI CascFindFirstFile(HANDLE hStorage, LPCSTR szMask, PCASC_FIND_DATA pFindData, LPCTSTR szListFile);
bool  WINAPI CascFindNextFile(HANDLE hFind, PCASC_FIND_DATA pFindData);
bool  WINAPI CascFindClose(HANDLE hFind);

//-----------------------------------------------------------------------------
// GetLastError/SetLastError support for non-Windows platform

#ifndef PLATFORM_WINDOWS

DWORD GetLastError();
void SetLastError(DWORD dwErrCode);

#endif  // PLATFORM_WINDOWS

#ifdef __cplusplus
}   // extern "C"
#endif

#endif  // __CASCLIB_H__
