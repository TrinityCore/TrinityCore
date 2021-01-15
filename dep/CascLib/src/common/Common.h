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

//-----------------------------------------------------------------------------
// EKey entry, captured from index files of all types. This structure
// is somewhat less memory consuming than CASC_CKEY_ENTRY

typedef struct _CASC_EKEY_ENTRY
{
    BYTE EKey[MD5_HASH_SIZE];                       // Encoded key. Length depends on TCascStorage::EKeyLength
    ULONGLONG StorageOffset;                        // Offset of the encoded file in archive.
                                                    // Lower (TCascStorage::FileOffsetBits) bits are archive offset.
                                                    // Upper bits are archive index
    DWORD EncodedSize;                              // Encoded size
    DWORD Alignment;                                // Alignment to 8-byte boundary. Reserved for future use
} CASC_EKEY_ENTRY, *PCASC_EKEY_ENTRY;

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
#define CASC_CE_IN_BUILD           0x00000040       // Present in the BUILD (text) manifest
#define CASC_CE_IN_ARCHIVE         0x00000080       // File is stored in an archive (for online storages)
#define CASC_CE_FOLDER_ENTRY       0x00000100       // This CKey entry is a folder
#define CASC_CE_FILE_SPAN          0x00000200       // This CKey entry is a follow-up file span
#define CASC_CE_FILE_PATCH         0x00000400       // The file is in PATCH subfolder in remote storage
#define CASC_CE_PLAIN_DATA         0x00000800       // The file data is not BLTE encoded, but in plain format

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
        SpanCount = 1;
    }

    bool IsFile()
    {
        // Must not be a folder entry
        if((Flags & CASC_CE_FOLDER_ENTRY) == 0)
        {
            // There can be entries that are both file span or the standalone file
            // * zone/zm_red.xpak - { zone/zm_red.xpak_1, zone/zm_red.xpak_2, ..., zone/zm_red.xpak_6 }
            if(RefCount != 0)
                return true;

            // To include the file, it must either be present in ENCODING, DOWNLOAD or in BUILD file
            if(((Flags & CASC_CE_FILE_SPAN) == 0) && (Flags & (CASC_CE_IN_ENCODING | CASC_CE_IN_DOWNLOAD | CASC_CE_IN_BUILD)))
                return true;
        }
        return false;
    }

    BYTE CKey[MD5_HASH_SIZE];                       // Content key of the full length
    BYTE EKey[MD5_HASH_SIZE];                       // Encoded key of the full length
    ULONGLONG StorageOffset;                        // Linear offset over the entire storage. 0 if not present
    ULONGLONG TagBitMask;                           // Bitmap for the tags. 0 ig tags are not supported
    DWORD ContentSize;                              // Content size of the file
    DWORD EncodedSize;                              // Encoded size of the file
    DWORD Flags;                                    // See CASC_CE_XXX
    USHORT RefCount;                                // This is the number of file names referencing this entry
    BYTE SpanCount;                                 // Number of spans for the file
    BYTE Priority;                                  // Download priority
};
typedef CASC_CKEY_ENTRY *PCASC_CKEY_ENTRY;

//-----------------------------------------------------------------------------
// Conversion tables

extern unsigned char AsciiToLowerTable_Slash[256];
extern unsigned char AsciiToUpperTable_BkSlash[256];
extern unsigned char AsciiToHexTable[0x80];
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

template <typename T>
T * CASC_ALLOC(size_t nCount)
{
    return (T *)malloc(nCount * sizeof(T));
}

template <typename T>
T * CASC_ALLOC_ZERO(size_t nCount)
{
    T * ptr = CASC_ALLOC<T>(nCount);

    if(ptr != NULL)
        memset(ptr, 0, sizeof(T) * nCount);
    return ptr;
}

template <typename T>
void CASC_FREE(T *& ptr)
{
    if (ptr != NULL)
        free(ptr);
    ptr = NULL;
}

//-----------------------------------------------------------------------------
// 32-bit ROL

inline DWORD Rol32(DWORD dwValue, DWORD dwRolCount)
{
    return (dwValue << dwRolCount) | (dwValue >> (32 - dwRolCount));
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
    ValueAsBytes[0] = (BYTE)((Value >> 0x18) & 0xFF);
    ValueAsBytes[1] = (BYTE)((Value >> 0x10) & 0xFF);
    ValueAsBytes[2] = (BYTE)((Value >> 0x08) & 0xFF);
    ValueAsBytes[3] = (BYTE)((Value >> 0x00) & 0xFF);
}

inline void ConvertIntegerToBytes_4_LE(DWORD Value, LPBYTE ValueAsBytes)
{
    ValueAsBytes[0] = (BYTE)((Value >> 0x00) & 0xFF);
    ValueAsBytes[1] = (BYTE)((Value >> 0x08) & 0xFF);
    ValueAsBytes[2] = (BYTE)((Value >> 0x10) & 0xFF);
    ValueAsBytes[3] = (BYTE)((Value >> 0x18) & 0xFF);
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
// Capturing various integral values

LPBYTE CaptureInteger16_BE(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue);
LPBYTE CaptureInteger32(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue);
LPBYTE CaptureInteger32_BE(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue);
LPBYTE CaptureByteArray(LPBYTE pbDataPtr, LPBYTE pbDataEnd, size_t nLength, LPBYTE pbOutput);
LPBYTE CaptureContentKey(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PCONTENT_KEY * PtrCKey);
LPBYTE CaptureEncodedKey(LPBYTE pbEKey, LPBYTE pbData, BYTE EKeyLength);
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

char    * CascNewStr(const char * szString, size_t nCharsToReserve = 0);
wchar_t * CascNewStr(const wchar_t * szString, size_t nCharsToReserve = 0);

LPSTR  CascNewStrT2A(LPCTSTR szString, size_t nCharsToReserve = 0);
LPTSTR CascNewStrA2T(LPCSTR szString, size_t nCharsToReserve = 0);

size_t CombinePath(LPTSTR szBuffer, size_t nMaxChars, char chSeparator, va_list argList);
size_t CombinePath(LPTSTR szBuffer, size_t nMaxChars, char chSeparator, ...);
LPTSTR CombinePath(LPCTSTR szPath, LPCTSTR szSubDir);
LPTSTR GetLastPathPart(LPTSTR szWorkPath);
bool CutLastPathPart(LPTSTR szWorkPath);

size_t NormalizeFileName_UpperBkSlash(char * szNormName, const char * szFileName, size_t cchMaxChars);
size_t NormalizeFileName_LowerSlash(char * szNormName, const char * szFileName, size_t cchMaxChars);

ULONGLONG CalcNormNameHash(const char * szNormName, size_t nLength);
ULONGLONG CalcFileNameHash(const char * szFileName);

//-----------------------------------------------------------------------------
// String conversion functions

template <typename xchar, typename INTXX>
DWORD ConvertStringToInt(const xchar * szString, size_t nMaxDigits, INTXX & RefValue, const xchar ** PtrStringEnd = NULL)
{
    INTXX MaxValueMask = (INTXX)0x0F << ((sizeof(INTXX) * 8) - 4);
    INTXX Accumulator = 0;
    BYTE DigitOne;

    // Set default value
    if(nMaxDigits == 0)
        nMaxDigits = sizeof(INTXX) * 2;

    // Convert the string up to the number of digits
    for(size_t i = 0; i < nMaxDigits; i++, szString++)
    {
        // Check for the end of the string
        if(szString[0] > sizeof(AsciiToHexTable))
            return ERROR_BAD_FORMAT;
        if(szString[0] <= 0x20)
            break;

        // Extract the next digit
        DigitOne = AsciiToHexTable[szString[0]];
        if(DigitOne == 0xFF)
            return ERROR_BAD_FORMAT;

        // Check overflow. If OK, shift the value by 4 to the left
        if(Accumulator & MaxValueMask)
            return ERROR_ARITHMETIC_OVERFLOW;
        Accumulator = (Accumulator << 4) | DigitOne;
    }

    // Give the results
    if(PtrStringEnd != NULL)
        PtrStringEnd[0] = szString;
    RefValue = Accumulator;
    return ERROR_SUCCESS;
}

// Converts string blob to binary blob
template <typename xchar>
DWORD BinaryFromString(const xchar * szString, size_t nMaxDigits, LPBYTE pbBinary)
{
    const xchar * szStringEnd = szString + nMaxDigits;
    DWORD dwCounter = 0;
    BYTE DigitValue;
    BYTE ByteValue = 0;

    // Convert the string
    while(szString < szStringEnd)
    {
        // Retrieve the digit converted to hexa
        DigitValue = (BYTE)(AsciiToUpperTable_BkSlash[szString[0]] - '0');
        if(DigitValue > 9)
            DigitValue -= 'A' - '9' - 1;
        if(DigitValue > 0x0F)
            return ERROR_BAD_FORMAT;

        // Insert the digit to the binary buffer
        ByteValue = (ByteValue << 0x04) | DigitValue;
        dwCounter++;

        // If we reached the second digit, it means that we need
        // to flush the byte value and move on
        if((dwCounter & 0x01) == 0)
            *pbBinary++ = ByteValue;
        szString++;
    }

    return ERROR_SUCCESS;
}

// Converts binary array to string.
// The caller must ensure that the buffer has at least ((cbBinary * 2) + 1) characters
template <typename xchar>
xchar * StringFromBinary(LPBYTE pbBinary, size_t cbBinary, xchar * szBuffer)
{
    xchar * szSaveBuffer = szBuffer;

    // Verify the binary pointer
    if(pbBinary && cbBinary)
    {
        // Convert the bytes to string array
        for(size_t i = 0; i < cbBinary; i++)
        {
            *szBuffer++ = IntToHexChar[pbBinary[i] >> 0x04];
            *szBuffer++ = IntToHexChar[pbBinary[i] & 0x0F];
        }
    }

    // Terminate the string
    *szBuffer = 0;
    return szSaveBuffer;
}

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

typedef bool (*INDEX_FILE_FOUND)(LPCTSTR szFileName, void * pvContext);

bool DirectoryExists(LPCTSTR szDirectory);

int ScanIndexDirectory(LPCTSTR szIndexPath, INDEX_FILE_FOUND pfnOnFileFound, void * pvContext);

//-----------------------------------------------------------------------------
// Argument structure versioning
// Safely retrieves field value from a structure
// intended for cases where users upgrade CascLib by simply dropping in a new .dll without recompiling their app

template <typename ARG, typename ARG_HOLDER>
bool ExtractVersionedArgument(const ARG_HOLDER * pHolder, size_t ArgOffset, ARG * pArg)
{
    if (pHolder == NULL)
        return false;

    // Check input structure size
    if (ArgOffset + sizeof(ARG) > pHolder->Size)
        return false;

    *pArg = *((ARG *)(((char*)pHolder) + ArgOffset));
    return true;
}

#endif // __COMMON_H__
