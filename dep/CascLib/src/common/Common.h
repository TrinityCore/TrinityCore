/*****************************************************************************/
/* CascCommon.h                           Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascCommon.h                    */
/*****************************************************************************/

#ifndef __COMMON_H__
#define __COMMON_H__

//-----------------------------------------------------------------------------
// Common macros

// Macro for building 64-bit file offset from two 32-bit
#define MAKE_OFFSET64(hi, lo)      (((ULONGLONG)hi << 32) | (ULONGLONG)lo)

#ifndef ALIGN_TO_SIZE
#define ALIGN_TO_SIZE(x, a)   (((x) + (a)-1) & ~((a)-1))
#endif

// Prevent problems with CRT "min" and "max" functions,
// as they are not defined on all platforms
#define CASCLIB_MIN(a, b) ((a < b) ? a : b)
#define CASCLIB_MAX(a, b) ((a > b) ? a : b)
#define CASCLIB_UNUSED(p) ((void)(p))

//-----------------------------------------------------------------------------
// Common structures

// Structure for static content key (CKey) and encoded key (EKey)
// The CKey is a MD5 hash of the file data.
// The EKey is (shortened) MD5 hash of the file header, which contains MD5 hashes of all the logical blocks of the file.
typedef struct _CONTENT_KEY
{
    BYTE Value[MD5_HASH_SIZE];                      // MD5 of the file

} CONTENT_KEY, *PCONTENT_KEY, ENCODED_KEY, *PENCODED_KEY;

// Helper structure for merging file paths
typedef struct _PATH_BUFFER
{
    char * szBegin;
    char * szPtr;
    char * szEnd;
} PATH_BUFFER, *PPATH_BUFFER;

//-----------------------------------------------------------------------------
// Basic structure used by all CascLib objects to describe a single entry
// in the CASC storage. Each entry represents one physical file
// in the storage. Note that the file may be present under several file names.

// Flags for CASC_CKEY_ENTRY::Flags
#define CASC_CE_FILE_IS_LOCAL      0x00000001       // The file is available locally. Keep this flag to have value of 1
#define CASC_CE_HAS_CKEY           0x00000002       // The CKey is present in the entry
#define CASC_CE_HAS_EKEY           0x00000004       // The EKey is present, at least partial one
#define CASC_CE_HAS_EKEY_PARTIAL   0x00000008       // The EKey is only partial, padded by zeros. Always used with CASC_CE_HAS_EKEY
#define CASC_CE_IN_ENCODING        0x00000010       // Present in the ENCODING manifest
#define CASC_CE_IN_DOWNLOAD        0x00000020       // Present in the DOWNLOAD manifest
#define CASC_CE_FOLDER_ENTRY       0x00000040       // This CKey entry is a folder

// In-memory representation of a single entry. 
struct CASC_CKEY_ENTRY
{
    CASC_CKEY_ENTRY()
    {
        Init();
    }

    void Init(void)
    {
        memset(this, 0, sizeof(CASC_CKEY_ENTRY));
        StorageOffset = CASC_INVALID_OFFS64;
        EncodedSize = CASC_INVALID_SIZE;
        ContentSize = CASC_INVALID_SIZE;
    }

    BYTE CKey[MD5_HASH_SIZE];                       // Content key of the full length
    BYTE EKey[MD5_HASH_SIZE];                       // Encoded key of the full length
    ULONGLONG StorageOffset;                        // Linear offset over the entire storage. 0 if not present
    ULONGLONG TagBitMask;                           // Bitmap for the tags. 0 ig tags are not supported
    DWORD EncodedSize;                              // Encoded size of the file. 0 if not supported
    DWORD ContentSize;                              // Content size of the file. 0 if not supported
    DWORD Flags;                                    // See CASC_CE_XXX
    USHORT RefCount;                                // This is the number of file names referencing this entry
    BYTE Priority;                                  // Download priority
    BYTE Alignment;

};
typedef CASC_CKEY_ENTRY *PCASC_CKEY_ENTRY;

//-----------------------------------------------------------------------------
// Conversion tables

extern unsigned char AsciiToLowerTable_Slash[256];
extern unsigned char AsciiToUpperTable_BkSlash[256];
extern unsigned char IntToHexChar[];

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
//  - Memory freeing function must check for NULL pointer and do nothing if so
//

#define CASC_REALLOC(type, ptr, count) (type *)realloc(ptr, (count) * sizeof(type))
#define CASC_ALLOC(type, count)        (type *)malloc((count) * sizeof(type))

template <typename T>
void CASC_FREE(T *& ptr)
{
    if (ptr != NULL)
        free(ptr);
    ptr = NULL;
}

//-----------------------------------------------------------------------------
// Big endian number manipulation

inline DWORD ConvertBytesToInteger_2(LPBYTE ValueAsBytes)
{
    USHORT Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];

    return Value;
}

inline DWORD ConvertBytesToInteger_3(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];

    return Value;
}

inline DWORD ConvertBytesToInteger_4(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[3];

    return Value;
}

// Converts the variable-size big-endian into integer
inline DWORD ConvertBytesToInteger_X(LPBYTE ValueAsBytes, DWORD dwByteSize)
{
    DWORD Value = 0;

    if(dwByteSize > 0)
        Value = (Value << 0x08) | ValueAsBytes[0];
    if(dwByteSize > 1)
        Value = (Value << 0x08) | ValueAsBytes[1];
    if(dwByteSize > 2)
        Value = (Value << 0x08) | ValueAsBytes[2];
    if(dwByteSize > 3)
        Value = (Value << 0x08) | ValueAsBytes[3];

    return Value;
}

inline DWORD ConvertBytesToInteger_4_LE(LPBYTE ValueAsBytes)
{
    DWORD Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[3];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[0];

    return Value;
}

// Read the 40-bit big-endian offset into ULONGLONG
inline ULONGLONG ConvertBytesToInteger_5(LPBYTE ValueAsBytes)
{
    ULONGLONG Value = 0;

    Value = (Value << 0x08) | ValueAsBytes[0];
    Value = (Value << 0x08) | ValueAsBytes[1];
    Value = (Value << 0x08) | ValueAsBytes[2];
    Value = (Value << 0x08) | ValueAsBytes[3];
    Value = (Value << 0x08) | ValueAsBytes[4];

    return Value;
}

inline void ConvertIntegerToBytes_4(DWORD Value, LPBYTE ValueAsBytes)
{
    ValueAsBytes[0] = (Value >> 0x18) & 0xFF;
    ValueAsBytes[1] = (Value >> 0x10) & 0xFF;
    ValueAsBytes[2] = (Value >> 0x08) & 0xFF;
    ValueAsBytes[3] = (Value >> 0x00) & 0xFF;
}

inline void ConvertIntegerToBytes_4_LE(DWORD Value, LPBYTE ValueAsBytes)
{
    ValueAsBytes[0] = (Value >> 0x00) & 0xFF;
    ValueAsBytes[1] = (Value >> 0x08) & 0xFF;
    ValueAsBytes[2] = (Value >> 0x10) & 0xFF;
    ValueAsBytes[3] = (Value >> 0x18) & 0xFF;
}

// Faster than memset(Buffer, 0, 0x10)
inline void ZeroMemory16(void * Buffer)
{
    PDWORD PtrBuffer = (PDWORD)Buffer;

    PtrBuffer[0] = 0;
    PtrBuffer[1] = 0;
    PtrBuffer[2] = 0;
    PtrBuffer[3] = 0;
}

// Faster than memcpy(Target, Source, 0x10)
inline void CopyMemory16(void * Target, void * Source)
{
    PDWORD PtrTarget = (PDWORD)Target;
    PDWORD PtrSource = (PDWORD)Source;

    PtrTarget[0] = PtrSource[0];
    PtrTarget[1] = PtrSource[1];
    PtrTarget[2] = PtrSource[2];
    PtrTarget[3] = PtrSource[3];
}

//-----------------------------------------------------------------------------
// Linear data stream manipulation

LPBYTE CaptureInteger32(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue);
LPBYTE CaptureInteger32_BE(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue);
LPBYTE CaptureByteArray(LPBYTE pbDataPtr, LPBYTE pbDataEnd, size_t nLength, LPBYTE pbOutput);
LPBYTE CaptureContentKey(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PCONTENT_KEY * PtrCKey);
LPBYTE CaptureArray_(LPBYTE pbDataPtr, LPBYTE pbDataEnd, LPBYTE * PtrArray, size_t ItemSize, size_t ItemCount);

#define CaptureArray(pbDataPtr, pbDataEnd, PtrArray, type, count) CaptureArray_(pbDataPtr, pbDataEnd, PtrArray, sizeof(type), count) 

//-----------------------------------------------------------------------------
// String copying and conversion

void CascStrCopy(char * szTarget, size_t cchTarget, const char * szSource, size_t cchSource = -1);
void CascStrCopy(char * szTarget, size_t cchTarget, const wchar_t * szSource, size_t cchSource = -1);
void CascStrCopy(wchar_t * szTarget, size_t cchTarget, const char * szSource, size_t cchSource = -1);
void CascStrCopy(wchar_t * szTarget, size_t cchTarget, const wchar_t * szSource, size_t cchSource = -1);

//-----------------------------------------------------------------------------
// Safe version of s(w)printf

size_t CascStrPrintf(char * buffer, size_t nCount, const char * format, ...);
size_t CascStrPrintf(wchar_t * buffer, size_t nCount, const wchar_t * format, ...);

//-----------------------------------------------------------------------------
// String allocation

char * CascNewStr(const char * szString, size_t nCharsToReserve = 0);
wchar_t * CascNewStr(const wchar_t * szString, size_t nCharsToReserve = 0);

TCHAR * CombinePath(const TCHAR * szPath, const TCHAR * szSubDir);
size_t CombineFilePath(TCHAR * szBuffer, size_t nMaxChars, const TCHAR * szPath, const TCHAR * szSubPath1, const TCHAR * szSubPath2 = NULL);
size_t CombineUrlPath(TCHAR * szBuffer, size_t nMaxChars, const TCHAR * szHost, const TCHAR * szSubPath1, const TCHAR * szSubPath2 = NULL);
TCHAR * GetLastPathPart(TCHAR * szWorkPath);
bool CutLastPathPart(TCHAR * szWorkPath);

size_t CreateCascSubdirectoryName(TCHAR * szBuffer, size_t nMaxChars, const TCHAR * szSubDir, const TCHAR * szExtension, LPBYTE pbEKey);
size_t NormalizeFileName_UpperBkSlash(char * szNormName, const char * szFileName, size_t cchMaxChars);
size_t NormalizeFileName_LowerSlash(char * szNormName, const char * szFileName, size_t cchMaxChars);

ULONGLONG CalcNormNameHash(const char * szNormName, size_t nLength);
ULONGLONG CalcFileNameHash(const char * szFileName);

int ConvertDigitToInt32(const TCHAR * szString, PDWORD PtrValue);
int ConvertStringToInt08(const char * szString, PDWORD PtrValue);
int ConvertStringToInt32(const TCHAR * szString, size_t nMaxDigits, PDWORD PtrValue);
int ConvertStringToBinary(const char * szString, size_t nMaxDigits, LPBYTE pbBinary);
char * StringFromBinary(LPBYTE pbBinary, size_t cbBinary, char * szBuffer);
char * StringFromMD5(LPBYTE md5, char * szBuffer);

//-----------------------------------------------------------------------------
// Structure query key

struct QUERY_KEY
{
    QUERY_KEY()
    {
        pbData = NULL;
        cbData = 0;
    }

    ~QUERY_KEY()
    {
        CASC_FREE(pbData);
        cbData = 0;
    }

    LPBYTE pbData;
    size_t cbData;
};
typedef QUERY_KEY *PQUERY_KEY;

//-----------------------------------------------------------------------------
// File name utilities

// Retrieves the pointer to plain name
template <typename XCHAR>
const XCHAR * GetPlainFileName(const XCHAR * szFileName)
{
    const XCHAR * szPlainName = szFileName;

    while(*szFileName != 0)
    {
        if(*szFileName == '\\' || *szFileName == '/')
            szPlainName = szFileName + 1;
        szFileName++;
    }

    return szPlainName;
}

// Retrieves the pointer to file extension
template <typename XCHAR>
const XCHAR * GetFileExtension(const XCHAR * szFileName)
{
    const XCHAR * szExtension = NULL;

    // We need to start searching from the plain name
    // Avoid: C:\$RECYCLE.BIN\File.ext
    szFileName = GetPlainFileName(szFileName);
    
    // Find the last dot in the plain file name
    while(szFileName[0] != 0)
    {
        if(szFileName[0] == '.')
            szExtension = szFileName;
        szFileName++;
    }

    // If not found, return the end of the file name
    return (XCHAR *)((szExtension != NULL) ? szExtension : szFileName);
}

bool IsFileDataIdName(const char * szFileName, DWORD & FileDataId);
bool IsFileCKeyEKeyName(const char * szFileName, LPBYTE PtrKeyBuffer);

bool CascCheckWildCard(const char * szString, const char * szWildCard);

//-----------------------------------------------------------------------------
// Hashing functions

ULONGLONG HashStringJenkins(const char * szFileName);

bool CascIsValidMD5(LPBYTE pbMd5);
void CascCalculateDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE md5_hash);
bool CascVerifyDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE expected_md5);

//-----------------------------------------------------------------------------
// Scanning a directory

typedef bool (*INDEX_FILE_FOUND)(const TCHAR * szFileName, PDWORD IndexArray, PDWORD OldIndexArray, void * pvContext);

bool DirectoryExists(const TCHAR * szDirectory);

int ScanIndexDirectory(
    const TCHAR * szIndexPath,
    INDEX_FILE_FOUND pfnOnFileFound,
    PDWORD IndexArray,
    PDWORD OldIndexArray,
    void * pvContext
    );

#endif // __COMMON_H__
