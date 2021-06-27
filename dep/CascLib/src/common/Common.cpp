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

// Converts ASCII characters to hexa digit
unsigned char AsciiToHexTable[128] =
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

unsigned char IntToHexChar[] = "0123456789abcdef";

//-----------------------------------------------------------------------------
// GetCascError/SetCascError support for non-Windows platform

static DWORD dwLastError = ERROR_SUCCESS;

DWORD GetCascError()
{
#ifdef PLATFORM_WINDOWS
    return GetLastError();
#else
    return dwLastError;
#endif
}

void SetCascError(DWORD dwErrCode)
{
#ifdef PLATFORM_WINDOWS
    SetLastError(dwErrCode);
#endif
    dwLastError = dwErrCode;
}

//-----------------------------------------------------------------------------
// Linear data stream manipulation

LPBYTE CaptureInteger16_BE(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue)
{
    // Is there enough data?
    if((pbDataPtr + sizeof(USHORT)) > pbDataEnd)
        return NULL;

    // Convert data from Little endian to 
    PtrValue[0] = ConvertBytesToInteger_2(pbDataPtr);

    // Return the pointer to data following after the integer
    return pbDataPtr + sizeof(USHORT);
}

LPBYTE CaptureInteger32(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue)
{
    // Is there enough data?
    if((pbDataPtr + sizeof(DWORD)) > pbDataEnd)
        return NULL;

    // Give data
    PtrValue[0] = *(PDWORD)pbDataPtr;

    // Return the pointer to data following after the integer
    return pbDataPtr + sizeof(DWORD);
}

LPBYTE CaptureInteger32_BE(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PDWORD PtrValue)
{
    // Is there enough data?
    if((pbDataPtr + sizeof(DWORD)) > pbDataEnd)
        return NULL;

    // Convert data from Little endian to 
    PtrValue[0] = ConvertBytesToInteger_4(pbDataPtr);

    // Return the pointer to data following after the integer
    return pbDataPtr + sizeof(DWORD);
}

LPBYTE CaptureByteArray(LPBYTE pbDataPtr, LPBYTE pbDataEnd, size_t nLength, LPBYTE pbOutput)
{
    // Is there enough data?
    if((pbDataPtr + nLength) > pbDataEnd)
        return NULL;

    // Give data
    memcpy(pbOutput, pbDataPtr, nLength);

    // Return the pointer to data following after the integer
    return pbDataPtr + nLength;
}

LPBYTE CaptureContentKey(LPBYTE pbDataPtr, LPBYTE pbDataEnd, PCONTENT_KEY * PtrCKey)
{
    // Is there enough data?
    if((pbDataPtr + sizeof(CONTENT_KEY)) > pbDataEnd)
        return NULL;

    // Give data
    PtrCKey[0] = (PCONTENT_KEY)pbDataPtr;

    // Return the pointer to data following after the integer
    return pbDataPtr + sizeof(CONTENT_KEY);
}

LPBYTE CaptureEncodedKey(LPBYTE pbEKey, LPBYTE pbData, BYTE EKeyLength)
{
    // Two usual lengths of EKey
    assert(EKeyLength == 0x09 || EKeyLength == 0x10);

    // Copy the first 0x09 bytes
    if(EKeyLength >= 0x09)
    {
        pbEKey[0x00] = pbData[0x00];
        pbEKey[0x01] = pbData[0x01];
        pbEKey[0x02] = pbData[0x02];
        pbEKey[0x03] = pbData[0x03];
        pbEKey[0x04] = pbData[0x04];
        pbEKey[0x05] = pbData[0x05];
        pbEKey[0x06] = pbData[0x06];
        pbEKey[0x07] = pbData[0x07];
        pbEKey[0x08] = pbData[0x08];

        if(EKeyLength == 0x10)
        {
            pbEKey[0x09] = pbData[0x09];
            pbEKey[0x0A] = pbData[0x0A];
            pbEKey[0x0B] = pbData[0x0B];
            pbEKey[0x0C] = pbData[0x0C];
            pbEKey[0x0D] = pbData[0x0D];
            pbEKey[0x0E] = pbData[0x0E];
            pbEKey[0x0F] = pbData[0x0F];
        }
        else
        {
            pbEKey[0x09] = 0;
            pbEKey[0x0A] = 0;
            pbEKey[0x0B] = 0;
            pbEKey[0x0C] = 0;
            pbEKey[0x0D] = 0;
            pbEKey[0x0E] = 0;
            pbEKey[0x0F] = 0;
        }
    }

    return pbData + EKeyLength;
}

LPBYTE CaptureArray_(LPBYTE pbDataPtr, LPBYTE pbDataEnd, LPBYTE * PtrArray, size_t ItemSize, size_t ItemCount)
{
    size_t ArraySize = ItemSize * ItemCount;

    // Is there enough data?
    if((pbDataPtr + ArraySize) > pbDataEnd)
        return NULL;

    // Give data
    PtrArray[0] = pbDataPtr;

    // Return the pointer to data following after the array
    return pbDataPtr + ArraySize;
}

//-----------------------------------------------------------------------------
// String copying and conversion

void CascStrCopy(char * szTarget, size_t cchTarget, const char * szSource, size_t cchSource)
{
    size_t cchToCopy;

    if (cchTarget > 0)
    {
        // Make sure we know the length
        if (cchSource == -1)
            cchSource = strlen(szSource);
        cchToCopy = CASCLIB_MIN((cchTarget - 1), cchSource);

        // Copy the string
        memcpy(szTarget, szSource, cchToCopy);
        szTarget[cchToCopy] = 0;
    }
}

void CascStrCopy(char * szTarget, size_t cchTarget, const wchar_t * szSource, size_t cchSource)
{
    size_t cchToCopy;

    if (cchTarget > 0)
    {
        // Make sure we know the length
        if (cchSource == -1)
            cchSource = wcslen(szSource);
        cchToCopy = CASCLIB_MIN((cchTarget - 1), cchSource);

        wcstombs(szTarget, szSource, cchToCopy);
        szTarget[cchToCopy] = 0;
    }
}

void CascStrCopy(wchar_t * szTarget, size_t cchTarget, const char * szSource, size_t cchSource)
{
    size_t cchToCopy;

    if (cchTarget > 0)
    {
        // Make sure we know the length
        if (cchSource == -1)
            cchSource = strlen(szSource);
        cchToCopy = CASCLIB_MIN((cchTarget - 1), cchSource);

        mbstowcs(szTarget, szSource, cchToCopy);
        szTarget[cchToCopy] = 0;
    }
}

void CascStrCopy(wchar_t * szTarget, size_t cchTarget, const wchar_t * szSource, size_t cchSource)
{
    size_t cchToCopy;

    if (cchTarget > 0)
    {
        // Make sure we know the length
        if (cchSource == -1)
            cchSource = wcslen(szSource);
        cchToCopy = CASCLIB_MIN((cchTarget - 1), cchSource);

        memcpy(szTarget, szSource, cchToCopy * sizeof(wchar_t));
        szTarget[cchToCopy] = 0;
    }
}

//-----------------------------------------------------------------------------
// Safe version of s(w)printf

size_t CascStrPrintf(char * buffer, size_t nCount, const char * format, ...)
{
    char * buffend;
    va_list argList;

    // Start the argument list
    va_start(argList, format);
    
#ifdef PLATFORM_WINDOWS
    StringCchVPrintfExA(buffer, nCount, &buffend, NULL, 0, format, argList);
//  buffend = buffer + vsnprintf(buffer, nCount, format, argList);
#else
    buffend = buffer + vsnprintf(buffer, nCount, format, argList);
#endif
    
    // End the argument list
    va_end(argList);
    return (buffend - buffer);
}

size_t CascStrPrintf(wchar_t * buffer, size_t nCount, const wchar_t * format, ...)
{
    wchar_t * buffend;
    va_list argList;

    // Start the argument list
    va_start(argList, format);

#ifdef PLATFORM_WINDOWS
    StringCchVPrintfExW(buffer, nCount, &buffend, NULL, 0, format, argList);
//  buffend = buffer + vswprintf(buffer, nCount, format, argList);
#else
    buffend = buffer + vswprintf(buffer, nCount, format, argList);
#endif

    // End the argument list
    va_end(argList);
    return (buffend - buffer);
}

//-----------------------------------------------------------------------------
// String allocation

char * CascNewStr(const char * szString, size_t nCharsToReserve)
{
    char * szNewString = NULL;
    size_t nLength;

    if(szString != NULL)
    {
        nLength = strlen(szString);
        szNewString = CASC_ALLOC<char>(nLength + nCharsToReserve + 1);
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
        szNewString = CASC_ALLOC<wchar_t>(nLength + nCharsToReserve + 1);
        if(szNewString != NULL)
        {
            memcpy(szNewString, szString, nLength * sizeof(wchar_t));
            szNewString[nLength] = 0;
        }
    }

    return szNewString;
}

LPSTR CascNewStrT2A(LPCTSTR szString, size_t nCharsToReserve)
{
    LPSTR szNewString = NULL;
    size_t nLength;

    if(szString != NULL)
    {
        nLength = _tcslen(szString);
        szNewString = CASC_ALLOC<char>(nLength + nCharsToReserve + 1);
        if(szNewString != NULL)
        {
            CascStrCopy(szNewString, nLength + nCharsToReserve + 1, szString, nLength);
//          szNewString[nLength] = 0;
        }
    }

    return szNewString;
}

LPTSTR CascNewStrA2T(LPCSTR szString, size_t nCharsToReserve)
{
    LPTSTR szNewString = NULL;
    size_t nLength;

    if(szString != NULL)
    {
        nLength = strlen(szString);
        szNewString = CASC_ALLOC<TCHAR>(nLength + nCharsToReserve + 1);
        if(szNewString != NULL)
        {
            CascStrCopy(szNewString, nLength + nCharsToReserve + 1, szString, nLength);
//          szNewString[nLength] = 0;
        }
    }

    return szNewString;
}

//-----------------------------------------------------------------------------
// String merging

LPTSTR GetLastPathPart(LPTSTR szWorkPath)
{
    size_t nLength = _tcslen(szWorkPath);

    // Go one character back
    if(nLength > 0)
        nLength--;

    // Cut ending (back)slashes, if any
    while(nLength > 0 && (szWorkPath[nLength] == _T('\\') || szWorkPath[nLength] == _T('/')))
        nLength--;

    // Cut the last path part
    while(nLength > 0)
    {
        // End of path?
        if(szWorkPath[nLength] == _T('\\') || szWorkPath[nLength] == _T('/'))
        {
            return szWorkPath + nLength;
        }

        // Go one character back
        nLength--;
    }

    return NULL;
}

bool CutLastPathPart(LPTSTR szWorkPath)
{
    // Get the last part of the path
    szWorkPath = GetLastPathPart(szWorkPath);
    if(szWorkPath == NULL)
        return false;

    szWorkPath[0] = 0;
    return true;
}

size_t CombinePath(LPTSTR szBuffer, size_t nMaxChars, va_list argList)
{
    CASC_PATH<TCHAR> Path(PATH_SEP_CHAR);
    LPCTSTR szFragment;
    bool bWithSeparator = false;

    // Combine all parts of the path here
    while((szFragment = va_arg(argList, LPTSTR)) != NULL)
    {
        Path.AppendString(szFragment, bWithSeparator);
        bWithSeparator = true;
    }

    return Path.Copy(szBuffer, nMaxChars);
}

size_t CombinePath(LPTSTR szBuffer, size_t nMaxChars, ...)
{
    va_list argList;
    size_t nLength;

    va_start(argList, nMaxChars);
    nLength = CombinePath(szBuffer, nMaxChars, argList);
    va_end(argList);

    return nLength;
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

ULONGLONG CalcNormNameHash(const char * szNormName, size_t nLength)
{
    uint32_t dwHashHigh = 0;
    uint32_t dwHashLow = 0;

    // Calculate the HASH value of the normalized file name
    hashlittle2(szNormName, nLength, &dwHashHigh, &dwHashLow);
    return ((ULONGLONG)dwHashHigh << 0x20) | dwHashLow;
}

ULONGLONG CalcFileNameHash(const char * szFileName)
{
    char szNormName[MAX_PATH+1];
    size_t nLength;

    // Normalize the file name - convert to uppercase, slashes to backslashes
    nLength = NormalizeFileName_UpperBkSlash(szNormName, szFileName, MAX_PATH);

    // Calculate hash from the normalized name
    return CalcNormNameHash(szNormName, nLength);
}

//-----------------------------------------------------------------------------
// File name utilities

bool IsFileDataIdName(const char * szFileName, DWORD & FileDataId)
{
    const char * szFilePtr;
    BYTE BinaryValue[4];

    // If the file name begins with "File", then a decimal file data ID must follow
    if(!strncmp(szFileName, "File", 4))
    {
        DWORD Accumulator = 0;

        for(szFilePtr = szFileName + 4; szFilePtr[0] != 0 && szFilePtr[0] != '.'; szFilePtr++)
        {
            if(!('0' <= szFilePtr[0] && szFilePtr[0] <= '9'))
                return false;
            Accumulator = (Accumulator * 10) + (szFilePtr[0] - '0');
        }

        if(szFilePtr[0] == '.' || szFilePtr[0] == 0)
        {
            FileDataId = Accumulator;
            return true;
        }
    }

    // If the file name begins with "FILE", then a hexadecimal file data ID must follow
    if(!strncmp(szFileName, "FILE", 4) && strlen(szFileName) >= 0x0C)
    {
        // Convert the hexadecimal number to integer
        if(BinaryFromString(szFileName+4, 8, BinaryValue) == ERROR_SUCCESS)
        {
            // Must be followed by an extension or end-of-string
            if(szFileName[0x0C] == 0 || szFileName[0x0C] == '.')
            {
                FileDataId = ConvertBytesToInteger_4(BinaryValue);
                return (FileDataId != CASC_INVALID_ID);
            }
        }
    }

    return false;
}

bool IsFileCKeyEKeyName(const char * szFileName, LPBYTE PtrKeyBuffer)
{
    size_t nLength = strlen(szFileName);

    if(nLength == MD5_STRING_SIZE)
    {
        if(BinaryFromString(szFileName, MD5_STRING_SIZE, PtrKeyBuffer) == ERROR_SUCCESS)
        {
            return true;
        }
    }

    return false;
}

bool CascCheckWildCard(const char * szString, const char * szWildCard)
{
    const char * szWildCardPtr;

    while(szWildCard && szWildCard[0])
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
                while(szWildCardPtr[0] == '*')
                    szWildCardPtr++;

                if(szWildCardPtr[0] == 0)
                    return true;

                if(AsciiToUpperTable_BkSlash[szWildCardPtr[0]] == AsciiToUpperTable_BkSlash[szString[0]])
                {
                    if(CascCheckWildCard(szString, szWildCardPtr))
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
    return true;
}

//-----------------------------------------------------------------------------
// Hashing functions

bool CascIsValidMD5(LPBYTE pbMd5)
{
    PDWORD Int32Array = (PDWORD)pbMd5;

    // The MD5 is considered invalid if it is zeroed
    return (Int32Array[0] | Int32Array[1] | Int32Array[2] | Int32Array[3]) ? true : false;
}

bool CascVerifyDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE expected_md5)
{
    MD5_CTX md5_ctx;
    BYTE md5_digest[MD5_HASH_SIZE];

    // Don't verify the block if the MD5 is not valid.
    if(!CascIsValidMD5(expected_md5))
        return true;

    // Calculate the MD5 of the data block
    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, pvDataBlock, cbDataBlock);
    MD5_Final(md5_digest, &md5_ctx);

    // Does the MD5's match?
    return (memcmp(md5_digest, expected_md5, MD5_HASH_SIZE) == 0);
}

void CascCalculateDataBlockHash(void * pvDataBlock, DWORD cbDataBlock, LPBYTE md5_hash)
{
    MD5_CTX md5_ctx;

    MD5_Init(&md5_ctx);
    MD5_Update(&md5_ctx, pvDataBlock, cbDataBlock);
    MD5_Final(md5_hash, &md5_ctx);
}
