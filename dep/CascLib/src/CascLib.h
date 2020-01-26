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
#pragma warning(disable:4668)                   // 'XXX' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#pragma warning(disable:4820)       // 'XXX' : '2' bytes padding added after data member 'XXX::yyy'
#endif

#include "CascPort.h"

#ifdef __cplusplus
extern "C" {
#endif

//-----------------------------------------------------------------------------
// Use the apropriate library
//
// The library type is encoded in the library name as the following
// CascLibXYZ.lib
//
//  X - D for Debug version, R for Release version
//  Y - A for ANSI version, U for Unicode version
//  Z - S for static-linked CRT library, D for multithreaded DLL CRT library
//
#if defined(_MSC_VER) && !defined(__CASCLIB_SELF__) && !defined(CASCLIB_NO_AUTO_LINK_LIBRARY)

  #ifdef _DEBUG                                 // DEBUG VERSIONS
    #ifndef _UNICODE
      #ifdef _DLL
        #pragma comment(lib, "CascLibDAD.lib")  // Debug Ansi CRT-DLL version
      #else
        #pragma comment(lib, "CascLibDAS.lib")  // Debug Ansi CRT-LIB version
      #endif
    #else
      #ifdef _DLL
        #pragma comment(lib, "CascLibDUD.lib")  // Debug Unicode CRT-DLL version
      #else
        #pragma comment(lib, "CascLibDUS.lib")  // Debug Unicode CRT-LIB version
      #endif
    #endif
  #else                                         // RELEASE VERSIONS
    #ifndef _UNICODE
      #ifdef _DLL
        #pragma comment(lib, "CascLibRAD.lib")  // Release Ansi CRT-DLL version
      #else
        #pragma comment(lib, "CascLibRAS.lib")  // Release Ansi CRT-LIB version
      #endif
    #else
      #ifdef _DLL
        #pragma comment(lib, "CascLibRUD.lib")  // Release Unicode CRT-DLL version
      #else
        #pragma comment(lib, "CascLibRUS.lib")  // Release Unicode CRT-LIB version
      #endif
    #endif
  #endif

#endif
//-----------------------------------------------------------------------------
// Defines

#define CASCLIB_VERSION                 0x0200  // CascLib version - integral (1.50)
#define CASCLIB_VERSION_STRING           "2.0"  // CascLib version - string

// Values for CascOpenFile
#define CASC_OPEN_BY_NAME           0x00000000  // Open the file by name. This is the default value
#define CASC_OPEN_BY_CKEY           0x00000001  // The name is just the content key; skip ROOT file processing
#define CASC_OPEN_BY_EKEY           0x00000002  // The name is just the encoded key; skip ROOT file processing
#define CASC_OPEN_BY_FILEID         0x00000003  // The name is CASC_FILE_DATA_ID(FileDataId)
#define CASC_OPEN_TYPE_MASK         0x0000000F  // The mask which gets open type from the dwFlags
#define CASC_OPEN_FLAGS_MASK        0xFFFFFFF0  // The mask which gets open type from the dwFlags
#define CASC_STRICT_DATA_CHECK      0x00000010  // Verify all data read from a file
#define CASC_OVERCOME_ENCRYPTED     0x00000020  // When CascReadFile encounters a block encrypted with a key that is missing, the block is filled with zeros and returned as success

#define CASC_LOCALE_ALL             0xFFFFFFFF
#define CASC_LOCALE_ALL_WOW         0x0001F3F6  // All except enCN and enTW
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

// Return value for CascGetFileSize and CascSetFilePointer
#define CASC_INVALID_INDEX          0xFFFFFFFF
#define CASC_INVALID_SIZE           0xFFFFFFFF
#define CASC_INVALID_POS            0xFFFFFFFF
#define CASC_INVALID_ID             0xFFFFFFFF
#define CASC_INVALID_OFFS64         0xFFFFFFFFFFFFFFFF
#define CASC_INVALID_SIZE64         0xFFFFFFFFFFFFFFFF

// Flags for CASC_STORAGE_FEATURES::dwFeatures
#define CASC_FEATURE_FILE_NAMES     0x00000001  // File names are supported by the storage
#define CASC_FEATURE_ROOT_CKEY      0x00000002  // Present if the storage's ROOT returns CKey
#define CASC_FEATURE_TAGS           0x00000004  // Tags are supported by the storage
#define CASC_FEATURE_FNAME_HASHES   0x00000008  // The storage contains file name hashes on ALL files
#define CASC_FEATURE_FNAME_HASHES_OPTIONAL 0x00000010  // The storage contains file name hashes for SOME files
#define CASC_FEATURE_FILE_DATA_IDS  0x00000020  // The storage indexes files by FileDataId
#define CASC_FEATURE_LOCALE_FLAGS   0x00000040  // Locale flags are supported
#define CASC_FEATURE_CONTENT_FLAGS  0x00000080  // Content flags are supported
#define CASC_FEATURE_ONLINE         0x00000100  // The storage is an online storage

// Macro to convert FileDataId to the argument of CascOpenFile
#define CASC_FILE_DATA_ID(FileDataId) ((LPCSTR)(size_t)FileDataId)
#define CASC_FILE_DATA_ID_FROM_STRING(szFileName)  ((DWORD)(size_t)szFileName)

// Maximum length of encryption key
#define CASC_KEY_LENGTH 0x10

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

    
    CascStorageFeatures,                        // Returns the features flag
    CascStorageInstalledLocales,                // Not supported
    CascStorageProduct,                         // Gives CASC_STORAGE_PRODUCT
    CascStorageTags,                            // Gives CASC_STORAGE_TAGS structure
    CascStoragePathProduct,                     // Gives Path:Product into a LPTSTR buffer
    CascStorageInfoClassMax

} CASC_STORAGE_INFO_CLASS, *PCASC_STORAGE_INFO_CLASS;

typedef enum _CASC_FILE_INFO_CLASS
{
    CascFileContentKey,
    CascFileEncodedKey,
    CascFileFullInfo,                           // Gives CASC_FILE_FULL_INFO structure
    CascFileSpanInfo,                           // Gives CASC_FILE_SPAN_INFO structure for each file span
    CascFileInfoClassMax
} CASC_FILE_INFO_CLASS, *PCASC_FILE_INFO_CLASS;

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

    // Size of the file, as retrieved from CKey entry
    ULONGLONG FileSize;

    // Plain name of the found file. Pointing inside the 'szFileName' array
    char * szPlainName;

    // File data ID. Only valid if the storage supports file data IDs, otherwise CASC_INVALID_ID
    DWORD dwFileDataId;
    
    // Locale flags. Only valid if the storage supports locale flags, otherwise CASC_INVALID_ID
    DWORD dwLocaleFlags;

    // Content flags. Only valid if the storage supports content flags, otherwise CASC_INVALID_ID
    DWORD dwContentFlags;

    // Span count
    DWORD dwSpanCount;

    // If true the file is available locally
    DWORD bFileAvailable:1;

    // Name type in 'szFileName'. In case the file name is not known,
    // CascLib can put FileDataId-like name or a string representation of CKey/EKey
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
    char szCodeName[0x1C];                      // Code name of the product ("wowt" = "World of Warcraft PTR")
    DWORD BuildNumber;                          // Build number. If zero, then CascLib didn't recognize build number

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
    ULONGLONG ContentSize;                      // Content size of all spans
    ULONGLONG EncodedSize;                      // Encoded size of all spans
    DWORD SegmentIndex;                         // Index of the segment file (aka 0 = "data.000")
    DWORD SpanCount;                            // Number of spans forming the file
    DWORD FileDataId;                           // File data ID. CASC_INVALID_ID if not supported.
    DWORD LocaleFlags;                          // Locale flags. CASC_INVALID_ID if not supported.
    DWORD ContentFlags;                         // Locale flags. CASC_INVALID_ID if not supported

} CASC_FILE_FULL_INFO, *PCASC_FILE_FULL_INFO;

typedef struct _CASC_FILE_SPAN_INFO
{
    BYTE CKey[MD5_HASH_SIZE];                   // Content key of the file span
    BYTE EKey[MD5_HASH_SIZE];                   // Encoded key of the file span
    ULONGLONG StartOffset;                      // Starting offset of the file span
    ULONGLONG EndOffset;                        // Ending offset of the file span
    DWORD ArchiveIndex;                         // Index of the archive
    DWORD ArchiveOffs;                          // Offset in the archive
    DWORD HeaderSize;                           // Size of encoded frame headers
    DWORD FrameCount;                           // Number of frames in this span

} CASC_FILE_SPAN_INFO, *PCASC_FILE_SPAN_INFO;

//-----------------------------------------------------------------------------
// Extended version of CascOpenStorage

// Some operations (e.g. opening an online storage) may take long time.
// This callback allows an application to be notified about loading progress
// and even cancel the storage loading process
typedef bool (WINAPI * PFNPROGRESSCALLBACK)(    // Return 'true' to cancel the loading process
    void * PtrUserParam,                        // User-specific parameter passed to the callback
    LPCSTR szWork,                              // Text for the current activity (example: "Loading "ENCODING" file")
    LPCSTR szObject,                            // (optional) name of the object tied to the activity (example: index file name)
    DWORD CurrentValue,                         // (optional) current object being processed
    DWORD TotalValue                            // (optional) If non-zero, this is the total number of objects to process
    );

// Some storages support multi-product installation (e.g. World of Warcraft).
// With this callback, the calling application can specify which storage to open
typedef bool (WINAPI * PFNPRODUCTCALLBACK)(     // Return 'true' to cancel the loading process
    void * PtrUserParam,                        // User-specific parameter passed to the callback
    LPCSTR * ProductList,                       // Array of product codenames found in the storage
    size_t ProductCount,                        // Number of products in the ProductList array
    size_t * PtrSelectedProduct                 // [out] This is the selected product to open. On input, set to 0 (aka the first product)
    );

typedef struct _CASC_OPEN_STORAGE_ARGS
{
    size_t Size;                                // Length of this structure. Initialize to sizeof(CASC_OPEN_STORAGE_ARGS)

    LPCTSTR szLocalPath;                        // Local:  Path to the storage directory (where ".build.info: is) or any of the sub-path
                                                // Online: Path to the local storage cache

    LPCTSTR szCodeName;                         // If non-null, this will specify a product in a multi-product local storage
                                                // Has higher priority than PfnProductCallback (if both specified)
    LPCTSTR szRegion;                           // If non-null, this will specify a product region.

    PFNPROGRESSCALLBACK PfnProgressCallback;    // Progress callback. If non-NULL, this can inform the caller about state of the opening storage
    void * PtrProgressParam;                    // Pointer-sized parameter that will be passed to PfnProgressCallback
    PFNPRODUCTCALLBACK PfnProductCallback;      // Progress callback. If non-NULL, will be called on multi-product storage to select one of the products
    void * PtrProductParam;                     // Pointer-sized parameter that will be passed to PfnProgressCallback

    DWORD dwLocaleMask;                         // Locale mask to open
    DWORD dwFlags;                              // Reserved. Set to zero.

    //
    // Any additional member from here on must be checked for availability using the ExtractVersionedArgument function.
    // Example:
    //
    // DWORD dwMyExtraMember = 0;
    // ExtractVersionedArgument(pArgs, offsetof(CASC_OPEN_STORAGE_ARGS, dwMyExtraMember), &dwMyExtraMember);
    //

} CASC_OPEN_STORAGE_ARGS, *PCASC_OPEN_STORAGE_ARGS;

//-----------------------------------------------------------------------------
// Functions for storage manipulation

bool  WINAPI CascOpenStorageEx(LPCTSTR szParams, PCASC_OPEN_STORAGE_ARGS pArgs, bool bOnlineStorage, HANDLE * phStorage);
bool  WINAPI CascOpenStorage(LPCTSTR szParams, DWORD dwLocaleMask, HANDLE * phStorage);
bool  WINAPI CascOpenOnlineStorage(LPCTSTR szParams, DWORD dwLocaleMask, HANDLE * phStorage);
bool  WINAPI CascGetStorageInfo(HANDLE hStorage, CASC_STORAGE_INFO_CLASS InfoClass, void * pvStorageInfo, size_t cbStorageInfo, size_t * pcbLengthNeeded);
bool  WINAPI CascCloseStorage(HANDLE hStorage);

bool  WINAPI CascOpenFile(HANDLE hStorage, const void * pvFileName, DWORD dwLocaleFlags, DWORD dwOpenFlags, HANDLE * PtrFileHandle);
bool  WINAPI CascOpenLocalFile(LPCTSTR szFileName, DWORD dwOpenFlags, HANDLE * PtrFileHandle);
bool  WINAPI CascGetFileInfo(HANDLE hFile, CASC_FILE_INFO_CLASS InfoClass, void * pvFileInfo, size_t cbFileInfo, size_t * pcbLengthNeeded);
bool  WINAPI CascGetFileSize64(HANDLE hFile, PULONGLONG PtrFileSize);
bool  WINAPI CascSetFilePointer64(HANDLE hFile, LONGLONG DistanceToMove, PULONGLONG PtrNewPos, DWORD dwMoveMethod);
bool  WINAPI CascReadFile(HANDLE hFile, void * lpBuffer, DWORD dwToRead, PDWORD pdwRead);
bool  WINAPI CascCloseFile(HANDLE hFile);

DWORD WINAPI CascGetFileSize(HANDLE hFile, PDWORD pdwFileSizeHigh);
DWORD WINAPI CascSetFilePointer(HANDLE hFile, LONG lFilePos, LONG * PtrFilePosHigh, DWORD dwMoveMethod);

HANDLE WINAPI CascFindFirstFile(HANDLE hStorage, LPCSTR szMask, PCASC_FIND_DATA pFindData, LPCTSTR szListFile);
bool  WINAPI CascFindNextFile(HANDLE hFind, PCASC_FIND_DATA pFindData);
bool  WINAPI CascFindClose(HANDLE hFind);

bool   WINAPI CascAddEncryptionKey(HANDLE hStorage, ULONGLONG KeyName, LPBYTE Key);
bool   WINAPI CascAddStringEncryptionKey(HANDLE hStorage, ULONGLONG KeyName, LPCSTR szKey);
LPBYTE WINAPI CascFindEncryptionKey(HANDLE hStorage, ULONGLONG KeyName);
bool   WINAPI CascGetNotFoundEncryptionKey(HANDLE hStorage, ULONGLONG * KeyName);

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
