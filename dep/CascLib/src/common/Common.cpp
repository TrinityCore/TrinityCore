/*****************************************************************************/
/* CascCommon.cpp                         Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Common functions for CascLib                                              */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 29.04.14  1.00  Lad  The first version of CascCommon.cpp                  */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "../CascLib.h"
#include "../CascCommon.h"

//-----------------------------------------------------------------------------
// Conversion to uppercase/lowercase

// Converts ASCII characters to lowercase
// Converts backslash (0x5C) to normal slash (0x2F)
unsigned char AsciiToLowerTable_Slash[256] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x2F, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

// Converts ASCII characters to uppercase
// Converts slash (0x2F) to backslash (0x5C)
unsigned char AsciiToUpperTable_BkSlash[256] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x5C,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

unsigned char IntToHexChar[] = "0123456789abcdef";

//-----------------------------------------------------------------------------
// GetLastError/SetLastError support for non-Windows platform

#ifndef PLATFORM_WINDOWS
static int nLastError = ERROR_SUCCESS;

int GetLastError()
{
    return nLastError;
}

void SetLastError(int nError)
{
    nLastError = nError;
}
#endif

//-----------------------------------------------------------------------------
// String manipulation

void CopyString(char * szTarget, const char * szSource, size_t cchLength)
{
    memcpy(szTarget, szSource, cchLength);
    szTarget[cchLength] = 0;
}

void CopyString(wchar_t * szTarget, const char * szSource, size_t cchLength)
{
    mbstowcs(szTarget, szSource, cchLength);
    szTarget[cchLength] = 0;
}

void CopyString(char * szTarget, const wchar_t * szSource, size_t cchLength)
{
    wcstombs(szTarget, szSource, cchLength);
    szTarget[cchLength] = 0;
}

char * CascNewStr(const char * szString, size_t nCharsToReserve)
{
    char * szNewString = NULL;
    size_t nLength;

    if(szString != NULL)
    {
        nLength = strlen(szString);
        szNewString = CASC_ALLOC(char, nLength + nCharsToReserve + 1);
        if(szNewString != NULL)
        {
            memcpy(szNewString, szString, nLength);
            szNewString[nLength] = 0;
        }
    }

    return szNewString;
}

wchar_t * CascNewStr(const wchar_t * szString, size_t nCharsToReserve)
{
    wchar_t * szNewString = NULL;
    size_t nLength;

    if(szString != NULL)
    {
        nLength = wcslen(szString);
        szNewString = CASC_ALLOC(wchar_t, nLength + nCharsToReserve + 1);
        if(szNewString != NULL)
        {
            memcpy(szNewString, szString, nLength * sizeof(wchar_t));
            szNewString[nLength] = 0;
        }
    }

    return szNewString;
}

TCHAR * CascNewStrFromAnsi(const char * szBegin, const char * szEnd)
{
    TCHAR * szNewString = NULL;

    // Only if the entry is valid
    if(szBegin != NULL && szEnd > szBegin)
    {
        // Allocate and copy the string
        szNewString = CASC_ALLOC(TCHAR, (szEnd - szBegin + 1));
        if(szNewString != NULL)
            CopyString(szNewString, szBegin, (szEnd - szBegin));
    }

    // Return the string
    return szNewString;
}

TCHAR * CombinePath(const TCHAR * szDirectory, const TCHAR * szSubDir)
{
    TCHAR * szFullPath = NULL;
    TCHAR * szPathPtr;
    size_t nLength1 = 0;
    size_t nLength2 = 0;

    // Calculate lengths of each part
    if(szDirectory != NULL)
    {
        // Get the length of the directory
        nLength1 = _tcslen(szDirectory);

        // Cut all ending backslashes
        while(nLength1 > 0 && szDirectory[nLength1 - 1] == _T(PATH_SEPARATOR))
            nLength1--;
    }

    if(szSubDir != NULL)
    {
        // Cut all leading backslashes
        while(szSubDir[0] == _T(PATH_SEPARATOR))
            szSubDir++;

        // Get the length of the subdir
        nLength2 = _tcslen(szSubDir);

        // Cut all ending backslashes
        while(nLength2 > 0 && szSubDir[nLength2 - 1] == _T(PATH_SEPARATOR))
            nLength2--;
    }

    // Allocate space for the full path
    szFullPath = szPathPtr = CASC_ALLOC(TCHAR, nLength1 + nLength2 + 2);
    if(szFullPath != NULL)
    {
        // Copy the directory
        if(szDirectory != NULL && nLength1 != 0)
        {
            memcpy(szPathPtr, szDirectory, (nLength1 * sizeof(TCHAR)));
            szPathPtr += nLength1;
        }

        // Copy the sub-directory
        if(szSubDir != NULL && nLength2 != 0)
        {
            // Append backslash to the previous one
            if(szPathPtr > szFullPath)
                *szPathPtr++ = _T(PATH_SEPARATOR);

            // Copy the string
            memcpy(szPathPtr, szSubDir, (nLength2 * sizeof(TCHAR)));
            szPathPtr += nLength2;
        }

        // Terminate the string
        szPathPtr[0] = 0;
    }

    return szFullPath;
}

TCHAR * CombinePathAndString(const TCHAR * szPath, const char * szString, size_t nLength)
{
    TCHAR * szFullPath = NULL;
    TCHAR * szSubDir;

    // Create the subdir string
    szSubDir = CASC_ALLOC(TCHAR, nLength + 1);
    if(szSubDir != NULL)
    {
        CopyString(szSubDir, szString, nLength);
        szFullPath = CombinePath(szPath, szSubDir);
        CASC_FREE(szSubDir);
    }

    return szFullPath;
}

size_t NormalizeFileName(const unsigned char * NormTable, char * szNormName, const char * szFileName, size_t cchMaxChars)
{
    char * szNormNameEnd = szNormName + cchMaxChars;
    size_t i;

    // Normalize the file name: ToLower + BackSlashToSlash
    for(i = 0; szFileName[0] != 0 && szNormName < szNormNameEnd; i++)
        *szNormName++ = NormTable[*szFileName++];

    // Terminate the string
    szNormName[0] = 0;
    return i;
}

size_t NormalizeFileName_UpperBkSlash(char * szNormName, const char * szFileName, size_t cchMaxChars)
{
    return NormalizeFileName(AsciiToUpperTable_BkSlash, szNormName, szFileName, cchMaxChars);
}

size_t NormalizeFileName_LowerSlash(char * szNormName, const char * szFileName, size_t cchMaxChars)
{
    return NormalizeFileName(AsciiToLowerTable_Slash, szNormName, szFileName, cchMaxChars);
}

ULONGLONG CalcFileNameHash(const char * szFileName)
{
    char szNormName[MAX_PATH+1];
    uint32_t dwHashHigh = 0;
    uint32_t dwHashLow = 0;
    size_t nLength;

    // Normalize the file name - convert to uppercase, slashes to backslashes
    nLength = NormalizeFileName_UpperBkSlash(szNormName, szFileName, MAX_PATH);

    // Calculate the HASH value of the normalized file name
    hashlittle2(szNormName, nLength, &dwHashHigh, &dwHashLow);
    return ((ULONGLONG)dwHashHigh << 0x20) | dwHashLow;
}

int ConvertDigitToInt32(const TCHAR * szString, PDWORD PtrValue)
{
    BYTE Digit;

    Digit = (BYTE)(AsciiToUpperTable_BkSlash[szString[0]] - _T('0'));
    if(Digit > 9)
        Digit -= 'A' - '9' - 1;

    PtrValue[0] = Digit;
    return (Digit > 0x0F) ? ERROR_BAD_FORMAT : ERROR_SUCCESS;
}

int ConvertStringToInt08(const char * szString, PDWORD PtrValue)
{
    BYTE DigitOne = AsciiToUpperTable_BkSlash[szString[0]] - '0';
    BYTE DigitTwo = AsciiToUpperTable_BkSlash[szString[1]] - '0';

    // Fix the digits
    if(DigitOne > 9)
        DigitOne -= 'A' - '9' - 1;
    if(DigitTwo > 9)
        DigitTwo -= 'A' - '9' - 1;

    // Combine them into a value
    PtrValue[0] = (DigitOne << 0x04) | DigitTwo;
    return (DigitOne <= 0x0F && DigitTwo <= 0x0F) ? ERROR_SUCCESS : ERROR_BAD_FORMAT;
}

int ConvertStringToInt32(const TCHAR * szString, size_t nMaxDigits, PDWORD PtrValue)
{
    // The number of digits must be even
    assert((nMaxDigits & 0x01) == 0);
    assert(nMaxDigits <= 8);

    // Prepare the variables
    PtrValue[0] = 0;
    nMaxDigits >>= 1;

    // Convert the string up to the number of digits
    for(size_t i = 0; i < nMaxDigits; i++)
    {
        BYTE DigitOne;
        BYTE DigitTwo;

        DigitOne = (BYTE)(AsciiToUpperTable_BkSlash[szString[0]] - _T('0'));
        if(DigitOne > 9)
            DigitOne -= 'A' - '9' - 1;

        DigitTwo = (BYTE)(AsciiToUpperTable_BkSlash[szString[1]] - _T('0'));
        if(DigitTwo > 9)
            DigitTwo -= 'A' - '9' - 1;

        if(DigitOne > 0x0F || DigitTwo > 0x0F)
            return ERROR_BAD_FORMAT;

        PtrValue[0] = (PtrValue[0] << 0x08) | (DigitOne << 0x04) | DigitTwo;
        szString += 2;
    }

    return ERROR_SUCCESS;
}

// Converts string blob to binary blob.
int ConvertStringToBinary(
    const char * szString,
    size_t nMaxDigits,
    LPBYTE pbBinary)
{
    const char * szStringEnd = szString + nMaxDigits;
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

char * StringFromBinary(LPBYTE pbBinary, size_t cbBinary, char * szBuffer)
{
    char * szSaveBuffer = szBuffer;

    // Convert the string to the array of MD5
    // Copy the blob data as text
    for(size_t i = 0; i < cbBinary; i++)
    {
        *szBuffer++ = IntToHexChar[pbBinary[0] >> 0x04];
        *szBuffer++ = IntToHexChar[pbBinary[0] & 0x0F];
        pbBinary++;
    }

    // Terminate the string
    *szBuffer = 0;
    return szSaveBuffer;
}

char * StringFromMD5(LPBYTE md5, char * szBuffer)
{
    return StringFromBinary(md5, MD5_HASH_SIZE, szBuffer);
}

//-----------------------------------------------------------------------------
// File name utilities

const wchar_t * GetPlainFileName(const wchar_t * szFileName)
{
    const wchar_t * szPlainName = szFileName;

    while(*szFileName != 0)
    {
        if(*szFileName == '\\' || *szFileName == '/')
            szPlainName = szFileName + 1;
        szFileName++;
    }

    return szPlainName;
}

const char * GetPlainFileName(const char * szFileName)
{
    const char * szPlainName = szFileName;

    while(*szFileName != 0)
    {
        if(*szFileName == '\\' || *szFileName == '/')
            szPlainName = szFileName + 1;
        szFileName++;
    }

    return szPlainName;
}

bool CheckWildCard(const char * szString, const char * szWildCard)
{
    const char * szWildCardPtr;

    for(;;)
    {
        // If there is '?' in the wildcard, we skip one char
        while(szWildCard[0] == '?')
        {
            if(szString[0] == 0)
                return false;

            szWildCard++;
            szString++;
        }

        // Handle '*'
        szWildCardPtr = szWildCard;
        if(szWildCardPtr[0] != 0)
        {
            if(szWildCardPtr[0] == '*')
            {
                szWildCardPtr++;

                if(szWildCardPtr[0] == '*')
                    continue;

                if(szWildCardPtr[0] == 0)
                    return true;

                if(AsciiToUpperTable_BkSlash[szWildCardPtr[0]] == AsciiToUpperTable_BkSlash[szString[0]])
                {
                    if(CheckWildCard(szString, szWildCardPtr))
                        return true;
                }
            }
            else
            {
                if(AsciiToUpperTable_BkSlash[szWildCardPtr[0]] != AsciiToUpperTable_BkSlash[szString[0]])
                    return false;

                szWildCard = szWildCardPtr + 1;
            }

            if(szString[0] == 0)
                return false;
            szString++;
        }
        else
        {
            return (szString[0] == 0) ? true : false;
        }
    }
}

//-----------------------------------------------------------------------------
// Hashing functions

bool IsValidMD5(LPBYTE pbMd5)
{
    BYTE BitSummary = 0;

    // The MD5 is considered invalid of it is zeroed
    BitSummary |= pbMd5[0x00] | pbMd5[0x01] | pbMd5[0x02] | pbMd5[0x03] | pbMd5[0x04] | pbMd5[0x05] | pbMd5[0x06] | pbMd5[0x07];
    BitSummary |= pbMd5[0x08] | pbMd5[0x09] | pbMd5[0x0A] | pbMd5[0x0B] | pbMd5[0x0C] | pbMd5[0x0D] | pbMd5[0x0E] | pbMd5[0x0F];
    return (BitSummary != 0);
}

bool VerifyDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE expected_md5)
{
    hash_state md5_state;
    BYTE md5_digest[MD5_HASH_SIZE];

    // Don't verify the block if the MD5 is not valid.
    if(!IsValidMD5(expected_md5))
        return true;

    // Calculate the MD5 of the data block
    md5_init(&md5_state);
    md5_process(&md5_state, (unsigned char *)pvDataBlock, cbDataBlock);
    md5_done(&md5_state, md5_digest);

    // Does the MD5's match?
    return (memcmp(md5_digest, expected_md5, MD5_HASH_SIZE) == 0);
}

void CalculateDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE md5_hash)
{
    hash_state md5_state;

    md5_init(&md5_state);
    md5_process(&md5_state, (unsigned char *)pvDataBlock, cbDataBlock);
    md5_done(&md5_state, md5_hash);
}

//-----------------------------------------------------------------------------
// We have our own qsort implementation, optimized for using array of pointers

#define STKSIZ (8*sizeof(void*) - 2)

#define SWAP_ENTRIES(index1, index2)        \
{                                           \
    temp = base[index1];                    \
    base[index1] = base[index2];            \
    base[index2] = temp;                    \
}

void qsort_pointer_array(void ** base, size_t num, int (*compare)(const void *, const void *, const void *), const void * context)
{
    size_t lo, hi;                  /* ends of sub-array currently sorting */
    size_t mid;                     /* points to middle of subarray */
    size_t loguy, higuy;            /* traveling pointers for partition step */
    size_t size;                    /* size of the sub-array */
    size_t lostk[STKSIZ], histk[STKSIZ];
    void * temp;
    int stkptr;                     /* stack for saving sub-array to be processed */

    /* validation section */
    assert(base != NULL);
    assert(compare != NULL);

    if (num < 2)
        return;                 /* nothing to do */

    stkptr = 0;                 /* initialize stack */

    lo = 0;
    hi = (num-1);               /* initialize limits */

    /* this entry point is for pseudo-recursion calling: setting
       lo and hi and jumping to here is like recursion, but stkptr is
       preserved, locals aren't, so we preserve stuff on the stack */
recurse:

    size = (hi - lo) + 1;       /* number of el's to sort */

    /* First we pick a partitioning element.  The efficiency of the
       algorithm demands that we find one that is approximately the median
       of the values, but also that we select one fast.  We choose the
       median of the first, middle, and last elements, to avoid bad
       performance in the face of already sorted data, or data that is made
       up of multiple sorted runs appended together.  Testing shows that a
       median-of-three algorithm provides better performance than simply
       picking the middle element for the latter case. */

    mid = lo + (size / 2);      /* find middle element */

    /* Sort the first, middle, last elements into order */
    if (compare(context, base[lo], base[mid]) > 0) {
        SWAP_ENTRIES(lo, mid);
    }
    if (compare(context, base[lo], base[hi]) > 0) {
        SWAP_ENTRIES(lo, hi);
    }
    if (compare(context, base[mid], base[hi]) > 0) {
        SWAP_ENTRIES(mid, hi);
    }

    /* We now wish to partition the array into three pieces, one consisting
       of elements <= partition element, one of elements equal to the
       partition element, and one of elements > than it.  This is done
       below; comments indicate conditions established at every step. */

    loguy = lo;
    higuy = hi;

    /* Note that higuy decreases and loguy increases on every iteration,
       so loop must terminate. */
    for (;;) {
        /* lo <= loguy < hi, lo < higuy <= hi,
           A[i] <= A[mid] for lo <= i <= loguy,
           A[i] > A[mid] for higuy <= i < hi,
           A[hi] >= A[mid] */

        /* The doubled loop is to avoid calling comp(mid,mid), since some
           existing comparison funcs don't work when passed the same
           value for both pointers. */

        if (mid > loguy) {
            do  {
                loguy ++;
            } while (loguy < mid && compare(context, base[loguy], base[mid]) <= 0);
        }
        if (mid <= loguy) {
            do  {
                loguy ++;
            } while (loguy <= hi && compare(context, base[loguy], base[mid]) <= 0);
        }

        /* lo < loguy <= hi+1, A[i] <= A[mid] for lo <= i < loguy,
           either loguy > hi or A[loguy] > A[mid] */

        do  {
            higuy --;
        } while (higuy > mid && compare(context, base[higuy], base[mid]) > 0);

        /* lo <= higuy < hi, A[i] > A[mid] for higuy < i < hi,
           either higuy == lo or A[higuy] <= A[mid] */

        if (higuy < loguy)
            break;

        /* if loguy > hi or higuy == lo, then we would have exited, so
           A[loguy] > A[mid], A[higuy] <= A[mid],
           loguy <= hi, higuy > lo */

        SWAP_ENTRIES(loguy, higuy);

        /* If the partition element was moved, follow it.  Only need
           to check for mid == higuy, since before the swap,
           A[loguy] > A[mid] implies loguy != mid. */

        if (mid == higuy)
            mid = loguy;

        /* A[loguy] <= A[mid], A[higuy] > A[mid]; so condition at top
           of loop is re-established */
    }

    /*     A[i] <= A[mid] for lo <= i < loguy,
           A[i] > A[mid] for higuy < i < hi,
           A[hi] >= A[mid]
           higuy < loguy
       implying:
           higuy == loguy-1
           or higuy == hi - 1, loguy == hi + 1, A[hi] == A[mid] */

    /* Find adjacent elements equal to the partition element.  The
       doubled loop is to avoid calling comp(mid,mid), since some
       existing comparison funcs don't work when passed the same value
       for both pointers. */

    higuy ++;
    if (mid < higuy) {
        do  {
            higuy --;
        } while (higuy > mid && compare(context, base[higuy], base[mid]) == 0);
    }
    if (mid >= higuy) {
        do  {
            higuy --;
        } while (higuy > lo && compare(context, base[higuy], base[mid]) == 0);
    }

    /* OK, now we have the following:
          higuy < loguy
          lo <= higuy <= hi
          A[i]  <= A[mid] for lo <= i <= higuy
          A[i]  == A[mid] for higuy < i < loguy
          A[i]  >  A[mid] for loguy <= i < hi
          A[hi] >= A[mid] */

    /* We've finished the partition, now we want to sort the subarrays
       [lo, higuy] and [loguy, hi].
       We do the smaller one first to minimize stack usage.
       We only sort arrays of length 2 or more.*/

    if ( higuy - lo >= hi - loguy ) {
        if (lo < higuy) {
            lostk[stkptr] = lo;
            histk[stkptr] = higuy;
            ++stkptr;
        }                           /* save big recursion for later */

        if (loguy < hi) {
            lo = loguy;
            goto recurse;           /* do small recursion */
        }
    }
    else {
        if (loguy < hi) {
            lostk[stkptr] = loguy;
            histk[stkptr] = hi;
            ++stkptr;               /* save big recursion for later */
        }

        if (lo < higuy) {
            hi = higuy;
            goto recurse;           /* do small recursion */
        }
    }

    /* We have sorted the array, except for any pending sorts on the stack.
       Check if there are any, and do them. */

    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;           /* pop subarray from stack */
    }
    else
        return;                 /* all subarrays done */
}
