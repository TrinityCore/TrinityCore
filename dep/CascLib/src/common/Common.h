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

//-----------------------------------------------------------------------------
// Conversion tables

extern unsigned char AsciiToLowerTable[256];
extern unsigned char AsciiToUpperTable[256];
extern unsigned char IntToHexChar[];

//-----------------------------------------------------------------------------
// Memory management helper

#if defined(_MSC_VER) && defined(_DEBUG)
void * DbgRealloc(void * ptr, size_t nSize);
#endif

//-----------------------------------------------------------------------------
// GetLastError/SetLastError support for non-Windows platform

#ifndef PLATFORM_WINDOWS
int GetLastError();
void SetLastError(int nError);
#endif  // PLATFORM_WINDOWS

//-----------------------------------------------------------------------------
// String manipulation

void CopyString(char * szTarget, const char * szSource, size_t cchLength);
void CopyString(wchar_t * szTarget, const char * szSource, size_t cchLength);
void CopyString(char * szTarget, const wchar_t * szSource, size_t cchLength);

char * NewStr(const char * szString, size_t nCharsToReserve);
wchar_t * NewStr(const wchar_t * szString, size_t nCharsToReserve);

TCHAR * NewStrFromAnsi(LPBYTE pbStringBegin, LPBYTE pbStringEnd);

TCHAR * CombinePath(const TCHAR * szPath, const TCHAR * szSubDir);

void NormalizeFileName_UpperBkSlash(char * szFileName);
void NormalizeFileName_LowerSlash(char * szFileName);

int ConvertDigitToInt32(const TCHAR * szString, PDWORD PtrValue);
int ConvertStringToInt32(const TCHAR * szString, size_t nMaxDigits, PDWORD PtrValue);
char * StringFromBinary(LPBYTE pbBinary, size_t cbBinary, char * szBuffer);

//-----------------------------------------------------------------------------
// File name utilities

bool CheckWildCard(const char * szString, const char * szWildCard);
const wchar_t * GetPlainFileName(const wchar_t * szFileName);
const char * GetPlainFileName(const char * szFileName);

//-----------------------------------------------------------------------------
// Hashing functions

ULONGLONG HashStringJenkins(const char * szFileName);

bool IsValidMD5(LPBYTE pbMd5);
void CalculateDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE md5_hash);
bool VerifyDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE expected_md5);

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
