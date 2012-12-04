/*****************************************************************************/
/* StormLibTest.cpp                       Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Test module for StormLib                                                  */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 25.03.03  1.00  Lad  The first version of StormLibTest.cpp                */
/*****************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#define __INCLUDE_CRYPTOGRAPHY__
#define __STORMLIB_SELF__                   // Don't use StormLib.lib
#include <stdio.h>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#include "../src/StormLib.h"
#include "../src/StormCommon.h"

#ifdef _MSC_VER
#pragma warning(disable: 4505)              // 'XXX' : unreferenced local function has been removed
#endif

//------------------------------------------------------------------------------
// Defines

#ifdef PLATFORM_WINDOWS
#define WORK_PATH_ROOT "E:\\Multimedia\\MPQs\\"
#endif

#ifdef PLATFORM_LINUX
#define WORK_PATH_ROOT "/home/user/MPQs/"
#endif

#ifdef PLATFORM_MAC
#define WORK_PATH_ROOT "/Users/sam/StormLib/test"
#endif

#ifndef LANG_CZECH
#define LANG_CZECH 0x0405
#endif

#define MPQ_SECTOR_SIZE 0x1000

#define MAKE_PATH(path) _T(WORK_PATH_ROOT) _T(path)

// Unicode MPQ names
/* Czech    */ static const wchar_t szUnicodeName1[] = {0x010C, 0x0065, 0x0073, 0x006B, 0x00FD, _T('.'), _T('m'), _T('p'), _T('q'), 0};
/* Russian  */ static const wchar_t szUnicodeName2[] = {0x0420, 0x0443, 0x0441, 0x0441, 0x043A, 0x0438, 0x0439, _T('.'), _T('m'), _T('p'), _T('q'), 0};
/* Greece   */ static const wchar_t szUnicodeName3[] = {0x03B5, 0x03BB, 0x03BB, 0x03B7, 0x03BD, 0x03B9, 0x03BA, 0x03AC, _T('.'), _T('m'), _T('p'), _T('q'), 0};
/* Chinese  */ static const wchar_t szUnicodeName4[] = {0x65E5, 0x672C, 0x8A9E, _T('.'), _T('m'), _T('p'), _T('q'), 0};
/* Japanese */ static const wchar_t szUnicodeName5[] = {0x7B80, 0x4F53, 0x4E2D, 0x6587, _T('.'), _T('m'), _T('p'), _T('q'), 0};
/* Arabic */   static const wchar_t szUnicodeName6[] = {0x0627, 0x0644, 0x0639, 0x0639, 0x0631, 0x0628, 0x064A, 0x0629, _T('.'), _T('m'), _T('p'), _T('q'), 0};

//-----------------------------------------------------------------------------
// Constants

static const TCHAR * szWorkDir = MAKE_PATH("Work");

static unsigned int AddFlags[] = 
{
//  Compression          Encryption             Fixed key           Single Unit            Sector CRC
    0                 |  0                   |  0                 | 0                    | 0,
    0                 |  MPQ_FILE_ENCRYPTED  |  0                 | 0                    | 0,
    0                 |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | 0                    | 0,
    0                 |  0                   |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    0                 |  MPQ_FILE_ENCRYPTED  |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    0                 |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_IMPLODE  |  0                   |  0                 | 0                    | 0,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  0                 | 0                    | 0,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | 0                    | 0,
    MPQ_FILE_IMPLODE  |  0                   |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_IMPLODE  |  0                   |  0                 | 0                    | MPQ_FILE_SECTOR_CRC,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  0                 | 0                    | MPQ_FILE_SECTOR_CRC,
    MPQ_FILE_IMPLODE  |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | 0                    | MPQ_FILE_SECTOR_CRC,
    MPQ_FILE_COMPRESS |  0                   |  0                 | 0                    | 0,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  0                 | 0                    | 0,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | 0                    | 0,
    MPQ_FILE_COMPRESS |  0                   |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  0                 | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | MPQ_FILE_SINGLE_UNIT | 0,
    MPQ_FILE_COMPRESS |  0                   |  0                 | 0                    | MPQ_FILE_SECTOR_CRC,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  0                 | 0                    | MPQ_FILE_SECTOR_CRC,
    MPQ_FILE_COMPRESS |  MPQ_FILE_ENCRYPTED  |  MPQ_FILE_FIX_KEY  | 0                    | MPQ_FILE_SECTOR_CRC,
    0xFFFFFFFF
};

//-----------------------------------------------------------------------------
// Local testing functions

static void clreol()
{
#ifdef PLATFORM_WINDOWS
    CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    LPTSTR szConsoleLine;
    int nConsoleChars;
    int i = 0;

    GetConsoleScreenBufferInfo(hConsole, &ScreenInfo);
    nConsoleChars = (ScreenInfo.srWindow.Right - ScreenInfo.srWindow.Left);
    if(nConsoleChars > 0)
    {
        szConsoleLine = new TCHAR[nConsoleChars + 3];
        if(szConsoleLine != NULL)
        {
            szConsoleLine[i++] = '\r';
            for(; i < nConsoleChars; i++)
                szConsoleLine[i] = ' ';
            szConsoleLine[i++] = '\r';
            szConsoleLine[i] = 0;

            _tprintf(szConsoleLine);
            delete []  szConsoleLine;
        }
    }
#endif // PLATFORM_WINDOWS
}

static void PrintfTA(const TCHAR * szFormat, const TCHAR * szStrT, const char * szStrA, int lcLocale = 0)
{
    TCHAR * szTemp;
    TCHAR szBuffer[MAX_PATH];

    // Convert ANSI string to TCHAR
    for(szTemp = szBuffer; *szStrA != 0; szTemp++, szStrA++)
        szTemp[0] = szStrA[0];
    szTemp[0] = 0;

    _tprintf(szFormat, szStrT, szBuffer, lcLocale);
}

static void MergeLocalPath(TCHAR * szBuffer, const TCHAR * szPart1, const char * szPart2)
{
    // Copy directory name
    while(*szPart1 != 0)
        *szBuffer++ = *szPart1++;

    // Add separator
    *szBuffer++ = _T('/');

    // Copy file name
    while(*szPart2 != 0)
        *szBuffer++ = *szPart2++;

    // Terminate the string
    *szBuffer = 0;
}

int GetFirstDiffer(void * ptr1, void * ptr2, int nSize)
{
    char * buff1 = (char *)ptr1;
    char * buff2 = (char *)ptr2;
    int nDiffer;

    for(nDiffer = 0; nDiffer < nSize; nDiffer++)
    {
        if(*buff1++ != *buff2++)
            return nDiffer;
    }
    return -1;
}

static void WINAPI CompactCB(void * /* lpParam */, DWORD dwWork, ULONGLONG BytesDone, ULONGLONG TotalBytes)
{
    clreol();

    _tprintf(_T("%u of %u "), (DWORD)BytesDone, (DWORD)TotalBytes);
    switch(dwWork)
    {
        case CCB_CHECKING_FILES:
            _tprintf(_T("Checking files in archive ...\r"));
            break;

        case CCB_CHECKING_HASH_TABLE:
            _tprintf(_T("Checking hash table ...\r"));
            break;

        case CCB_COPYING_NON_MPQ_DATA:
            _tprintf(_T("Copying non-MPQ data ...\r"));
            break;

        case CCB_COMPACTING_FILES:
            _tprintf(_T("Compacting archive ...\r"));
            break;

        case CCB_CLOSING_ARCHIVE:
            _tprintf(_T("Closing archive ...\r"));
            break;
    }
}

static void GenerateRandomDataBlock(LPBYTE pbBuffer, DWORD cbBuffer)
{
    LPBYTE pbBufferEnd = pbBuffer + cbBuffer;
    LPBYTE pbPtr = pbBuffer;
    DWORD cbBytesToPut = 0;
    BYTE ByteToPut = 0;
    bool bRandomData = false;

    while(pbPtr < pbBufferEnd)
    {
        // If there are no bytes to put, we will generate new byte and length
        if(cbBytesToPut == 0)
        {
            bRandomData = false;
            switch(rand() % 10)
            {
                case 0:     // A short sequence of zeros
                    cbBytesToPut = rand() % 0x08;
                    ByteToPut = 0;
                    break;

                case 1:     // A long sequence of zeros
                    cbBytesToPut = rand() % 0x80;
                    ByteToPut = 0;
                    break;

                case 2:     // A short sequence of non-zeros
                    cbBytesToPut = rand() % 0x08;
                    ByteToPut = (BYTE)(rand() % 0x100);
                    break;

                case 3:     // A long sequence of non-zeros
                    cbBytesToPut = rand() % 0x80;
                    ByteToPut = (BYTE)(rand() % 0x100);
                    break;

                case 4:     // A short random data
                    cbBytesToPut = rand() % 0x08;
                    bRandomData = true;
                    break;

                case 5:     // A long random data
                    cbBytesToPut = rand() % 0x80;
                    bRandomData = true;
                    break;

                default:    // A single random byte
                    cbBytesToPut = 1;
                    ByteToPut = (BYTE)(rand() % 0x100);
                    break;
            }
        }

        // Generate random byte, if needed
        if(bRandomData)
            ByteToPut = (BYTE)(rand() % 0x100);

        // Put next byte to the output buffer
        *pbPtr++ = ByteToPut;
        cbBytesToPut--;
    }
}

static bool CompareArchivedFiles(const char * szFileName, HANDLE hFile1, HANDLE hFile2, DWORD dwBlockSize)
{
    LPBYTE pbBuffer1 = NULL;
    LPBYTE pbBuffer2 = NULL;
    DWORD dwRead1;                      // Number of bytes read (Storm.dll)
    DWORD dwRead2;                      // Number of bytes read (StormLib)
    bool bResult1 = false;              // Result from Storm.dll
    bool bResult2 = false;              // Result from StormLib
    bool bResult = true;
    int nDiff;

    szFileName = szFileName;

    // Allocate buffers
    pbBuffer1 = new BYTE[dwBlockSize];
    pbBuffer2 = new BYTE[dwBlockSize];

    for(;;)
    {
        // Read the file's content by both methods and compare the result
        memset(pbBuffer1, 0, dwBlockSize);
        memset(pbBuffer2, 0, dwBlockSize);
        bResult1 = SFileReadFile(hFile1, pbBuffer1, dwBlockSize, &dwRead1, NULL);
        bResult2 = SFileReadFile(hFile2, pbBuffer2, dwBlockSize, &dwRead2, NULL);
        if(bResult1 != bResult2)
        {
            _tprintf(_T("Different results from SFileReadFile, Mpq1 %u, Mpq2 %u\n"), bResult1, bResult2);
            bResult = false;
            break;
        }

        // Test the number of bytes read
        if(dwRead1 != dwRead2)
        {
            _tprintf(_T("Different bytes read from SFileReadFile, Mpq1 %u, Mpq2 %u\n"), dwRead1, dwRead2);
            bResult = false;
            break;
        }

        // No more bytes ==> OK
        if(dwRead1 == 0)
            break;
        
        // Test the content
        if((nDiff = GetFirstDiffer(pbBuffer1, pbBuffer2, dwRead1)) != -1)
        {
            bResult = false;
            break;
        }
    }

    delete [] pbBuffer2;
    delete [] pbBuffer1;
    return bResult;
}

// Random read version
static bool CompareArchivedFilesRR(const char * /* szFileName */, HANDLE hFile1, HANDLE hFile2, DWORD dwBlockSize)
{
    const char * szPositions[3] = {"FILE_BEGIN  ", "FILE_CURRENT", "FILE_END    "};
    LPBYTE pbBuffer1 = NULL;
    LPBYTE pbBuffer2 = NULL;
    DWORD dwFileSize1;                  // File size (Storm.dll)
    DWORD dwFileSize2;                  // File size (StormLib)
    DWORD dwRead1;                      // Number of bytes read (Storm.dll)
    DWORD dwRead2;                      // Number of bytes read (StormLib)
    bool bResult1 = false;              // Result from Storm.dll
    bool bResult2 = false;              // Result from StormLib
    int nError = ERROR_SUCCESS;

    // Test the file size
    dwFileSize1 = SFileGetFileSize(hFile1, NULL);
    dwFileSize2 = SFileGetFileSize(hFile2, NULL);
    if(dwFileSize1 != dwFileSize2)
    {
        _tprintf(_T("Different size from SFileGetFileSize (file1: %u, file2: %u)\n"), dwFileSize1, dwFileSize2);
        return false;
    }

    if(dwFileSize1 != 0)
    {
        for(int i = 0; i < 10000; i++)
        {
            DWORD dwRandom     = rand() * rand();
            DWORD dwMoveMethod = dwRandom % 3;
            DWORD dwPosition   = dwRandom % dwFileSize1;
            DWORD dwToRead     = dwRandom % dwBlockSize; 

            // Also test negative seek
            if(rand() & 1)
            {
                int nPosition = (int)dwPosition;
                dwPosition = (DWORD)(-nPosition);
            }

            // Allocate buffers
            pbBuffer1 = new BYTE[dwToRead];
            pbBuffer2 = new BYTE[dwToRead];

            // Set the file pointer
            _tprintf(_T("RndRead (%u): pos %8i from %s, size %u ...\r"), i, dwPosition, szPositions[dwMoveMethod], dwToRead);
            dwRead1 = SFileSetFilePointer(hFile1, dwPosition, NULL, dwMoveMethod);
            dwRead2 = SFileSetFilePointer(hFile2, dwPosition, NULL, dwMoveMethod);
            if(dwRead1 != dwRead2)
            {
                _tprintf(_T("Difference returned by SFileSetFilePointer (file1: %u, file2: %u)\n"), dwRead1, dwRead2);
                nError = ERROR_CAN_NOT_COMPLETE;
                break;
            }

            // Read the file's content by both methods and compare the result
            bResult1 = SFileReadFile(hFile1, pbBuffer1, dwToRead, &dwRead1, NULL);
            bResult2 = SFileReadFile(hFile2, pbBuffer2, dwToRead, &dwRead2, NULL);
            if(bResult1 != bResult2)
            {
                _tprintf(_T("Different results from SFileReadFile (file1: %u, file2: %u)\n\n"), bResult1, bResult2);
                nError = ERROR_CAN_NOT_COMPLETE;
                break;
            }

            // Test the number of bytes read
            if(dwRead1 != dwRead2)
            {
                _tprintf(_T("Different bytes read from SFileReadFile (file1: %u, file2: %u)\n\n"), dwRead1, dwRead2);
                nError = ERROR_CAN_NOT_COMPLETE;
                break;
            }
            
            // Test the content
            if(dwRead1 != 0 && memcmp(pbBuffer1, pbBuffer2, dwRead1))
            {
                _tprintf(_T("Different data content from SFileReadFile\n"));
                nError = ERROR_CAN_NOT_COMPLETE;
                break;
            }

            delete [] pbBuffer2;
            delete [] pbBuffer1;
        }
    }
    clreol();
    return (nError == ERROR_SUCCESS) ? true : false;
}

//-----------------------------------------------------------------------------
// Opening local file

static int TestOpenLocalFile(const char * szFileName)
{
    HANDLE hFile;
    char szRetrievedName[MAX_PATH];

    if(SFileOpenFileEx(NULL, szFileName, SFILE_OPEN_LOCAL_FILE, &hFile))
    {
        SFileGetFileName(hFile, szRetrievedName);
        SFileCloseFile(hFile);
    }

    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Partial file reading

static int TestPartFileRead(const TCHAR * szFileName)
{
    ULONGLONG ByteOffset;
    ULONGLONG FileSize = 0;
    TFileStream * pStream;
    BYTE BigBuffer[0x7000];
    BYTE Buffer[0x100];
    int nError = ERROR_SUCCESS;

    // Open the partial file
    pStream = FileStream_OpenFile(szFileName, false);
    if(pStream == NULL)
        nError = GetLastError();

    // Get the size of the stream
    if(nError == ERROR_SUCCESS)
    {
        if(!FileStream_GetSize(pStream, FileSize))
            nError = GetLastError();
    }

    // Read the last 0x7000 bytes
    if(nError == ERROR_SUCCESS)
    {
        ByteOffset = FileSize - sizeof(BigBuffer);
        if(!FileStream_Read(pStream, &ByteOffset, BigBuffer, sizeof(BigBuffer)))
            nError = GetLastError();
    }

    // Read the last 0x100 bytes
    if(nError == ERROR_SUCCESS)
    {
        ByteOffset = FileSize - sizeof(Buffer);
        if(!FileStream_Read(pStream, &ByteOffset, Buffer, sizeof(Buffer)))
            nError = GetLastError();
    }

    // Read 0x100 bytes from position (FileSize - 0xFF)
    if(nError == ERROR_SUCCESS)
    {
        ByteOffset = FileSize - sizeof(Buffer) + 1;
        if(!FileStream_Read(pStream, &ByteOffset, Buffer, sizeof(Buffer)))
            nError = GetLastError();
    }

    FileStream_Close(pStream);
    return nError;
}

//-----------------------------------------------------------------------------
// Compare PKLIB decompression

BYTE pbCompressed1[] = {0x00, 0x04, 0x00, 0x00, 0x04, 0xF0, 0x1F, 0x7B, 0x01, 0xFF};
BYTE pbCompressed2[] = {0x00, 0x04, 0x00, 0x00, 0x04, 0xF0, 0x1F, 0x00, 0x00, 0x04, 0xFC, 0x03};

static int ComparePklibCompressions()
{
    char Decompressed[0x1000];
    char Compressed[0x1000];
    int cbDecompressed = 0x208;
    int cbCompressed = sizeof(Compressed);

    memset(Decompressed, 0, cbDecompressed);
    SCompImplode(Compressed, &cbCompressed, Decompressed, cbDecompressed);
    
    cbDecompressed = sizeof(Decompressed);
    SCompExplode(Decompressed, &cbDecompressed, Compressed, cbCompressed);


    return ERROR_SUCCESS;
}

//-----------------------------------------------------------------------------
// Compare LZMA decompression

#ifdef PLATFORM_WINDOWS
typedef void * (*ALLOC_MEMORY)(size_t);
typedef void (*FREE_MEMORY)(void *);
typedef int (GIVE_DATA)(void *);

extern "C" int starcraft_decompress_lzma(char * pbInBuffer, int cbInBuffer, char * pbOutBuffer, int cbOutBuffer, int * pcbOutBuffer, ALLOC_MEMORY pfnAllocMemory, FREE_MEMORY pfnFreeMemory);
extern "C" int starcraft_compress_lzma(char * pbInBuffer, int cbInBuffer, int dummy1, char * pbOutBuffer, int cbOutBuffer, int dummy2, int * pcbOutBuffer, ALLOC_MEMORY pfnAllocMemory, FREE_MEMORY pfnFreeMemory, GIVE_DATA pfnGiveData);
void Compress_LZMA(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer, int *, int);
int Decompress_LZMA(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer);

extern "C" void * operator_new(size_t sz)
{
    return malloc(sz);
}

void * Memory_Allocate(size_t byte_size)
{
    return malloc(byte_size);
}

void Memory_Free(void * address)
{
    if(address != NULL)
        free(address);
}

int GiveData(void *)
{
    return 0;
}

static int StarcraftCompress_LZMA(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    return starcraft_compress_lzma(pbInBuffer,
                                   cbInBuffer,
                                   0,
                                   pbOutBuffer,
                                  *pcbOutBuffer,
                                   0,
                                   pcbOutBuffer,
                                   Memory_Allocate,
                                   Memory_Free,
                                   GiveData);
}

static int StarcraftDecompress_LZMA(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    return starcraft_decompress_lzma(pbInBuffer,
                                     cbInBuffer,
                                     pbOutBuffer,
                                     *pcbOutBuffer,
                                     pcbOutBuffer,
                                     Memory_Allocate,
                                     Memory_Free);
}

static int CompareLzmaCompressions(int nSectorSize)
{
    LPBYTE pbCompressed1 = NULL;            // Compressed by our code
    LPBYTE pbCompressed2 = NULL;            // Compressed by Blizzard's code
    LPBYTE pbDecompressed1 = NULL;          // Decompressed by our code
    LPBYTE pbDecompressed2 = NULL;          // Decompressed by Blizzard's code
    LPBYTE pbOriginalData = NULL;
    int nError = ERROR_SUCCESS;

    // Allocate buffers
    // Must allocate twice blocks due to probable bug in Storm.dll.
    // Storm.dll corrupts stack when uncompresses data with PKWARE DCL
    // and no compression occurs.
    pbDecompressed1 = new BYTE [nSectorSize];
    pbDecompressed2 = new BYTE [nSectorSize];
    pbCompressed1 = new BYTE [nSectorSize];
    pbCompressed2 = new BYTE [nSectorSize];
    pbOriginalData = new BYTE[nSectorSize];
    if(!pbDecompressed1 || !pbDecompressed2 || !pbCompressed1 || !pbCompressed2 || !pbOriginalData)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    if(nError == ERROR_SUCCESS)
    {
        for(int i = 0; i < 100000; i++)
        {
            int   nDcmpLength1;
            int   nDcmpLength2;
            int   nCmpLength1;
            int   nCmpLength2;
            int   nDiff;

            clreol();
            _tprintf(_T("Testing compression of sector %u\r"), i + 1);

            // Generate random data sector
            GenerateRandomDataBlock(pbOriginalData, nSectorSize);

            // Compress the sector by both methods
            nCmpLength1 = nCmpLength2 = nSectorSize;
//          Compress_LZMA((char *)pbCompressed1, &nCmpLength1, (char *)pbOriginalData, nSectorSize, 0, 0);
            StarcraftCompress_LZMA((char *)pbCompressed1, &nCmpLength2, (char *)pbOriginalData, nSectorSize);

__TryToDecompress:

            // Only test decompression when the compression actually succeeded
            if(nCmpLength1 < nSectorSize)
            {
                // Decompress both data
                nDcmpLength2 = nDcmpLength1 = nSectorSize;
//              Decompress_LZMA((char *)pbDecompressed1, &nDcmpLength1, (char *)pbCompressed1, nCmpLength1);
                StarcraftDecompress_LZMA((char *)pbDecompressed2, &nDcmpLength2, (char *)pbCompressed1, nCmpLength1);

                // Compare the length of the output data
                if(nDcmpLength1 != nDcmpLength2)
                {
                    _tprintf(_T("Difference in compressed blocks lengths (%u vs %u)\n"), nDcmpLength1, nDcmpLength2);
                    goto __TryToDecompress;             
                }

                // Compare the output
                if((nDiff = GetFirstDiffer(pbDecompressed1, pbDecompressed2, nDcmpLength1)) != -1)
                {
                    _tprintf(_T("Difference in decompressed blocks (offset 0x%08X)\n"), nDiff);
                    goto __TryToDecompress;
                }

                // Check for data overflow
                if(pbDecompressed1[nSectorSize] != 0xFD || pbDecompressed1[nSectorSize] != 0xFD)
                {
                    _tprintf(_T("Damage after decompressed sector !!!\n"));
                    goto __TryToDecompress;
                }

                // Compare the decompressed data against original data
                if((nDiff = GetFirstDiffer(pbDecompressed1, pbOriginalData, nDcmpLength1)) != -1)
                {
                    _tprintf(_T("Difference between original data and decompressed data (offset 0x%08X)\n"), nDiff);
                    goto __TryToDecompress;
                }
            }
        }
    }

    // Cleanup
    if(pbOriginalData != NULL)
        delete [] pbOriginalData;
    if(pbCompressed2 != NULL)
        delete [] pbCompressed2;
    if(pbCompressed1 != NULL)
        delete [] pbCompressed1;
    if(pbDecompressed2 != NULL)
        delete [] pbDecompressed2;
    if(pbDecompressed1 != NULL)
        delete [] pbDecompressed1;
    clreol();
    return nError;
}
#endif // PLATFORM_WINDOWS

//-----------------------------------------------------------------------------
// Compression method test

static int TestSectorCompress(int nSectorSize)
{
    LPBYTE pbDecompressed = NULL;
    LPBYTE pbCompressed = NULL;
    LPBYTE pbOriginal = NULL;
    int nError = ERROR_SUCCESS;

    // Allocate buffers
    pbDecompressed = new BYTE[nSectorSize];
    pbCompressed = new BYTE[nSectorSize];
    pbOriginal = new BYTE[nSectorSize];
    if(!pbDecompressed || !pbCompressed || !pbOriginal)
        nError = ERROR_NOT_ENOUGH_MEMORY;

    if(nError == ERROR_SUCCESS)
    {
        for(int i = 0; i < 100000; i++)
        {
            int nOriginalLength = nSectorSize % (rand() + 1);
            int nCompressedLength;
            int nDecompressedLength;
            int nCmp = MPQ_COMPRESSION_SPARSE | MPQ_COMPRESSION_ZLIB | MPQ_COMPRESSION_BZIP2 | MPQ_COMPRESSION_PKWARE;
            int nDiff;

            clreol();
            _tprintf(_T("Testing compression of sector %u\r"), i + 1);

            // Generate random data sector
            GenerateRandomDataBlock(pbOriginal, nOriginalLength);
            if(nOriginalLength == 0x123)
                nOriginalLength = 0;

__TryAgain:

            // Compress the sector
            nCompressedLength = nOriginalLength;
            SCompCompress((char *)pbCompressed, &nCompressedLength, (char *)pbOriginal, nOriginalLength, nCmp, 0, -1);
//          SCompImplode((char *)pbCompressed, &nCompressedLength, (char *)pbOriginal, nOriginalLength);

            // When the method was unable to compress data,
            // the compressed data must be identical to original data
            if(nCompressedLength == nOriginalLength)
            {
                if((nDiff = GetFirstDiffer(pbCompressed, pbOriginal, nOriginalLength)) != -1)
                {
                    _tprintf(_T("Compression error: Fail when unable to compress the data (Offset 0x%08X).\n"), nDiff);
                    goto __TryAgain;
                }
            }

            // Uncompress the sector
            nDecompressedLength = nOriginalLength;
            SCompDecompress((char *)pbDecompressed, &nDecompressedLength, (char *)pbCompressed, nCompressedLength);
//          SCompExplode((char *)pbDecompressed, &nDecompressedLength, (char *)pbCompressed, nCompressedLength);

            // Check the decompressed length against original length
            if(nDecompressedLength != nOriginalLength)
            {
                _tprintf(_T("Length of uncompressed data does not agree with original data length !!!\n"));
                goto __TryAgain;
            }
            
            // Check decompressed block against original block
            if((nDiff = GetFirstDiffer(pbDecompressed, pbOriginal, nOriginalLength)) != -1)
            {
                _tprintf(_T("Decompressed sector does not agree with the original data !!! (Offset 0x%08X)\n"), nDiff);
                goto __TryAgain;
            }
        }
    }

    // Cleanup
    delete [] pbOriginal;
    delete [] pbCompressed;
    delete [] pbDecompressed;
    clreol();
    return nError;
}

static int TestArchiveOpenAndClose(const TCHAR * szMpqName)
{
    const char * szFileName1 = "DBFilesClient\\Item.dbc";
//  const char * szFileName2 = "items\\map\\mapz_deleted.cel";
    TMPQArchive * ha = NULL;
    HANDLE hFile1 = NULL;
//  HANDLE hFile2 = NULL;
    HANDLE hMpq = NULL;
    int nError = ERROR_SUCCESS;

    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Opening archive %s ...\n"), szMpqName);
        if(!SFileOpenArchive(szMpqName, 0, STREAM_PROVIDER_ENCRYPTED | BASE_PROVIDER_FILE, &hMpq))
            nError = GetLastError();
        ha = (TMPQArchive *)hMpq;
    }
/*
    // Test for TBitArray
    if(nError == ERROR_SUCCESS && ha->pHetTable != NULL)
    {
        TBitArray * pBitArray = ha->pHetTable->pBetIndexes;

        for(ULONG i = 0; i < 0x10000; i++)
        {
            BYTE LoadedBits[0x20];
            BYTE SaveBits[0x40];
            unsigned int nBitPosition = (i >> 0x08);
            unsigned int nBitCount = (i & 0xFF);

            memset(LoadedBits, 0, sizeof(LoadedBits));
            memcpy(SaveBits, pBitArray->Elements, sizeof(SaveBits));

            // Load the index to the BET table
            pBitArray->GetBits(nBitPosition, nBitCount, LoadedBits, sizeof(LoadedBits));

            // Load the index to the BET table
            pBitArray->SetBits(nBitPosition, nBitCount, LoadedBits, sizeof(LoadedBits));

            // Verify the bits
            if(memcmp(SaveBits, pBitArray->Elements, sizeof(SaveBits)))
                assert(false);
        }
    }
*/
    // Verify the raw data in the archive
    if(nError == ERROR_SUCCESS)
    {
        // Verify the archive
        SFileVerifyRawData(hMpq, SFILE_VERIFY_FILE, szFileName1);

        // Try to open a file
        if(!SFileOpenFileEx(hMpq, szFileName1, SFILE_OPEN_FROM_MPQ, &hFile1))
        {
            nError = GetLastError();
            printf("%s - file not found in the MPQ\n", szFileName1);
        }
    }

    // Dummy read from the file
    if(nError == ERROR_SUCCESS)
	{
        DWORD dwBytesRead = 0;
        BYTE Buffer[0x1000];

        SFileSetFileLocale(hFile1, 0x405);
        SFileReadFile(hFile1, Buffer, sizeof(Buffer), &dwBytesRead);
	}
/*
    // Verify the MPQ listfile
    if(nError == ERROR_SUCCESS)
    {
        SFileVerifyFile(hMpq, szFileName1, 0xFFFFFFFF); 
        if(!CompareArchivedFilesRR(szFileName1, hFile1, hFile2, 0x100000))
            nError = ERROR_CAN_NOT_COMPLETE;
    }
*/
    if(hFile1 != NULL)
        SFileCloseFile(hFile1);
    if(hMpq != NULL)
        SFileCloseArchive(hMpq);
    return nError;
}

static int TestFindFiles(const TCHAR * szMpqName)
{
    TMPQFile * hf;
    HANDLE hFile;
    HANDLE hMpq = NULL;
    BYTE Buffer[100];
    int nError = ERROR_SUCCESS;
    int nFiles = 0;
    int nFound = 0;

    // Open the archive
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Opening \"%s\" for finding files ...\n"), szMpqName);
        if(!SFileOpenArchive(szMpqName, 0, 0, &hMpq))
            nError = GetLastError();
    }

    // Compact the archive
    if(nError == ERROR_SUCCESS)
    {
        SFILE_FIND_DATA sf;
        HANDLE hFind;
        DWORD dwExtraDataSize;
        bool bFound = true;

        hFind = SFileFindFirstFile(hMpq, "*", &sf, "c:\\Tools32\\ListFiles\\ListFile.txt");
        while(hFind != NULL && bFound != false)
        {
            if(SFileOpenFileEx(hMpq, sf.cFileName, 0, &hFile))
            {
                hf = (TMPQFile *)hFile;
                SFileReadFile(hFile, Buffer, sizeof(Buffer));
                nFiles++;

                if(sf.dwFileFlags & MPQ_FILE_SECTOR_CRC)
                {
                    dwExtraDataSize = hf->SectorOffsets[hf->dwSectorCount + 1] - hf->SectorOffsets[hf->dwSectorCount];
                    if(dwExtraDataSize != 0)
                        nFound++;
                }

                SFileCloseFile(hFile);
            }

            bFound = SFileFindNextFile(hFind, &sf);
        }
    }

    if(hMpq != NULL)
        SFileCloseArchive(hMpq);
    if(nError == ERROR_SUCCESS)
        _tprintf(_T("Search complete\n"));
    return nError;
}

static int TestMpqCompacting(const TCHAR * szMpqName)
{
    HANDLE hMpq = NULL;
    int nError = ERROR_SUCCESS;

    // Open the archive
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Opening \"%s\" for compacting ...\n"), szMpqName);
        if(!SFileOpenArchive(szMpqName, 0, 0, &hMpq))
            nError = GetLastError();
    }

    if(nError == ERROR_SUCCESS)
    {
        const char * szFileName = "Shaders\\Effects\\shadowmap.wfx";

        printf("Deleting file %s ...\r", szFileName);
        if(!SFileRemoveFile(hMpq, szFileName))
            nError = GetLastError();
    }
/*
    // Compact the archive
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Compacting archive ...\r"));
        SFileSetCompactCallback(hMpq, CompactCB, NULL);
        if(!SFileCompactArchive(hMpq, "c:\\Tools32\\ListFiles\\ListFile.txt"))
            nError = GetLastError();
    }
*/
    if(hMpq != NULL)
        SFileCloseArchive(hMpq);
    if(nError == ERROR_SUCCESS)
        _tprintf(_T("Compacting complete (No errors)\n"));
    return nError;
}

static int TestCreateArchive(const TCHAR * szMpqName)
{
    TFileStream * pStream;
    const TCHAR * szFileName1 = MAKE_PATH("FileTest.exe");
    const TCHAR * szFileName2 = MAKE_PATH("ZeroSize.txt");
    HANDLE hMpq = NULL;                 // Handle of created archive 
    DWORD dwVerifyResult;
    DWORD dwFileCount = 0;
    LCID LocaleIDs[] = {0x000, 0x405, 0x406, 0x407, 0xFFFF};
    char szMpqFileName[MAX_PATH];
    int nError = ERROR_SUCCESS;
    int i;

    // Create the new file
    _tprintf(_T("Creating %s ...\n"), szMpqName);
    pStream = FileStream_CreateFile(szMpqName, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
    if(pStream == NULL)
        nError = GetLastError();

    // Write some data
    if(nError == ERROR_SUCCESS)
    {
        ULONGLONG FileSize = 0x100000;
      
        FileStream_SetSize(pStream, FileSize);
        FileStream_Close(pStream);
    }

    // Well, now create the MPQ archive
    if(nError == ERROR_SUCCESS)
    {
        if(!SFileCreateArchive(szMpqName,
                               MPQ_CREATE_ARCHIVE_V4 | MPQ_CREATE_ATTRIBUTES,
                               17,
                              &hMpq))
        {
            nError = GetLastError();
        }
    }

    // Add the same file multiple times
    if(nError == ERROR_SUCCESS)
    {
        // Add FileTest.exe
        for(i = 0; AddFlags[i] != 0xFFFFFFFF; i++)
        {
            sprintf(szMpqFileName, "FileTest_%02u.exe", i);
            PrintfTA(_T("Adding %s as %s ...\n"), szFileName1, szMpqFileName);
            if(SFileAddFileEx(hMpq, szFileName1, szMpqFileName, AddFlags[i], MPQ_COMPRESSION_ZLIB))
            {
                dwVerifyResult = SFileVerifyFile(hMpq, szMpqFileName, MPQ_ATTRIBUTE_CRC32 | MPQ_ATTRIBUTE_MD5);
                if(dwVerifyResult & (VERIFY_OPEN_ERROR | VERIFY_READ_ERROR | VERIFY_FILE_SECTOR_CRC_ERROR | VERIFY_FILE_CHECKSUM_ERROR | VERIFY_FILE_MD5_ERROR))
                    printf("CRC error on \"%s\"\n", szMpqFileName);
                dwFileCount++;
            }
            else
            {
                printf("Failed to add the file \"%s\".\n", szMpqFileName);
            }
        }

        
        // Delete a file in the middle of the file table
        SFileRemoveFile(hMpq, "FileTest_10.exe");
        SFileAddFileEx(hMpq, szFileName1, "FileTest_xx.exe", MPQ_FILE_COMPRESS | MPQ_FILE_ENCRYPTED, MPQ_COMPRESSION_ZLIB);
        
        // Try to decrement max file count
        dwFileCount = SFileGetMaxFileCount(hMpq);
        SFileSetMaxFileCount(hMpq, dwFileCount - 1);

        // Add ZeroSize.txt (1)
        sprintf(szMpqFileName, "ZeroSize_1.txt");
        for(i = 0; LocaleIDs[i] != 0xFFFF; i++)
        {
            PrintfTA(_T("Adding %s as %s (locale %04x) ...\n"), szFileName2, szMpqFileName, LocaleIDs[i]);
            SFileSetLocale(LocaleIDs[i]);
            if(!SFileAddFileEx(hMpq, szFileName2, szMpqFileName, MPQ_FILE_COMPRESS | MPQ_FILE_ENCRYPTED, MPQ_COMPRESSION_ZLIB))
                printf("Cannot add the file\n");
        }

        // Add ZeroSize.txt (1)
        sprintf(szMpqFileName, "ZeroSize_2.txt");
        for(int i = 0; LocaleIDs[i] != 0xFFFF; i++)
        {
            PrintfTA(_T("Adding %s as %s (locale %04x) ...\n"), szFileName2, szMpqFileName, LocaleIDs[i]);
            SFileSetLocale(LocaleIDs[i]);
            if(!SFileAddFileEx(hMpq, szFileName2, szMpqFileName, MPQ_FILE_COMPRESS | MPQ_FILE_ENCRYPTED, MPQ_COMPRESSION_ZLIB))
                printf("Cannot add the file\n");
        }
    }

    // Test rename function
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Testing rename files ...\n"));
        SFileSetLocale(LANG_NEUTRAL);
        if(!SFileRenameFile(hMpq, "FileTest_08.exe", "FileTest_08a.exe"))
        {
            nError = GetLastError();
            _tprintf(_T("Failed to rename the file\n"));
        }

        if(!SFileRenameFile(hMpq, "FileTest_08a.exe", "FileTest_08.exe"))
        {
            nError = GetLastError();
            _tprintf(_T("Failed to rename the file\n"));
        }

        if(!SFileRenameFile(hMpq, "FileTest_10.exe", "FileTest_10a.exe"))
        {
            nError = GetLastError();
            _tprintf(_T("Failed to rename the file\n"));
        }

        if(!SFileRenameFile(hMpq, "FileTest_10a.exe", "FileTest_10.exe"))
        {
            nError = GetLastError();
            _tprintf(_T("Failed to rename the file\n"));
        }
        
        if(nError == ERROR_SUCCESS)
            _tprintf(_T("Rename test succeeded.\n\n"));
        else
            _tprintf(_T("Rename test failed.\n\n"));
    }

    // Compact the archive
//  if(nError == ERROR_SUCCESS)
//      SFileCompactArchive(hMpq);

    // Test changing hash table size
    if(nError == ERROR_SUCCESS)
        SFileSetMaxFileCount(hMpq, 0x95);

    if(hMpq != NULL)
        SFileCloseArchive(hMpq);

    // Try to reopen the archive
    if(SFileOpenArchive(szMpqName, 0, 0, &hMpq))
        SFileCloseArchive(hMpq);

    _tprintf(_T("\n"));
    return nError;
}

static int TestCreateArchive_PaliRoharBug(const TCHAR * szMpqName)
{
    const TCHAR * szFileName = MAKE_PATH("FileTest.exe");
    HANDLE hMpq = NULL;                 // Handle of created archive 
    DWORD dwMaxFileCount = 0;
    DWORD dwMpqFlags = MPQ_FILE_ENCRYPTED | MPQ_FILE_COMPRESS;
    char szMpqFileName[MAX_PATH];
    int nError = ERROR_SUCCESS;
    int i;

    _tremove(szMpqName);
    if(SFileCreateArchive(szMpqName,
                          MPQ_CREATE_ARCHIVE_V4 | MPQ_CREATE_ATTRIBUTES,
                          1,
                         &hMpq))
    {
        // Add the file there
        SFileAddFileEx(hMpq, szFileName, "FileTest_base.exe", dwMpqFlags, MPQ_COMPRESSION_ZLIB);
        SFileFlushArchive(hMpq);
        SFileCloseArchive(hMpq);

        // Add the same file 10 times
        for(i = 0; i < 10; i++)
        {
            if(SFileOpenArchive(szMpqName, 0, 0, &hMpq))
            {
                dwMaxFileCount = SFileGetMaxFileCount(hMpq) + 1;
                _tprintf(_T("Increasing max file count to %u ...\n"), dwMaxFileCount);
                SFileSetMaxFileCount(hMpq, dwMaxFileCount);

                sprintf(szMpqFileName, "FileTest_%02u.exe", dwMaxFileCount);
                PrintfTA(_T("Adding %s as %s\n"), szFileName, szMpqFileName);
                if(!SFileAddFileEx(hMpq, szFileName, szMpqFileName, dwMpqFlags, MPQ_COMPRESSION_ZLIB))
                {
                    printf("Failed to add the file \"%s\".\n", szMpqFileName);
                    break;
                }

                SFileFlushArchive(hMpq);
                SFileCompactArchive(hMpq);
                SFileCloseArchive(hMpq);
            }
        }
    }

    _tprintf(_T("\n"));
    return nError;
}


static int TestAddFilesToMpq(
    const TCHAR * szMpqName,
    ...
    )
{
    const TCHAR * szFileName;
    const TCHAR * szSrc;
    char * szTrg;
    HANDLE hMpq;
    va_list argList;
    char szMpqFileName[MAX_PATH];
    int nError = ERROR_SUCCESS;

    if(!SFileOpenArchive(szMpqName, 0, 0, &hMpq))
        return GetLastError();

    va_start(argList, szMpqName);
    while((szFileName = va_arg(argList, const TCHAR *)) != NULL)
    {
        // Convert the plain name to ANSI
        szSrc = GetPlainFileNameT(szFileName);
        szTrg = szMpqFileName;
        while(*szSrc != 0)
            *szTrg++ = (char)*szSrc++;
        *szTrg = 0;

        // Add the file to MPQ
        if(!SFileAddFileEx(hMpq, szFileName,
                                 szMpqFileName,
                                 MPQ_FILE_COMPRESS,
                                 MPQ_COMPRESSION_ZLIB))
        {
            nError = GetLastError();
            printf("Failed to add the file \"%s\"\n", szFileName);
        }
    }

    SFileCloseArchive(hMpq);
    return nError;
}

static int TestCreateArchiveFromMemory(const TCHAR * szMpqName)
{
#define FILE_SIZE 65535

    HANDLE hFile;
    HANDLE hMPQ;
    char* data = new char [FILE_SIZE];          // random memory data
    char szFileName[100];
    int i;
 
    // Create an mpq file for testing
    if(SFileCreateArchive(szMpqName, MPQ_CREATE_ARCHIVE_V2|MPQ_CREATE_ATTRIBUTES, 0x100000, &hMPQ))
    {
        for(i = 0; i < 1000; i++)
        {
            sprintf(szFileName, "File%03u.bin", i);
            printf("Adding file %s\r", szFileName);

            if(SFileCreateFile(hMPQ, szFileName, 0, FILE_SIZE, 0, MPQ_FILE_COMPRESS, &hFile))
            {
                SFileWriteFile(hFile, data, FILE_SIZE, MPQ_COMPRESSION_ZLIB);
                SFileFinishFile(hFile);
            }
        }
    }
    SFileCloseArchive(hMPQ);
    delete [] data;
    return ERROR_SUCCESS;
}

static int TestFileReadAndWrite(
    const TCHAR * szMpqName,
    const char * szFileName)
{
    LPBYTE pvFile = NULL;
    HANDLE hFile = NULL;
    HANDLE hMpq = NULL;
    DWORD dwBytesRead;
    DWORD dwFileSize = 0;
    int nError = ERROR_SUCCESS;

    if(!SFileOpenArchive(szMpqName, 0, 0, &hMpq))
    {
        nError = GetLastError();
        _tprintf(_T("Failed to open the archive %s (%u).\n"), szMpqName, nError);
    }

    if(nError == ERROR_SUCCESS)
    {
        if(!SFileOpenFileEx(hMpq, szFileName, 0, &hFile))
        {
            nError = GetLastError();
            printf("Failed to open the file %s (%u).\n", szFileName, nError);
        }
    }

    if(nError == ERROR_SUCCESS)
    {
        if(!SFileGetFileInfo(hFile, SFILE_INFO_FILE_SIZE, &dwFileSize, sizeof(DWORD)))
        {
            nError = GetLastError();
            _tprintf(_T("Failed to get the file size (%u).\n"), nError);
        }
    }

    if(nError == ERROR_SUCCESS)
    {
        pvFile = new BYTE[dwFileSize];
        if(pvFile == NULL)
        {
            nError = ERROR_NOT_ENOUGH_MEMORY;
            printf("Failed to allocate buffer for the file (%u).\n", nError);
        }
    }

    if(nError == ERROR_SUCCESS)
    {
        if(!SFileReadFile(hFile, pvFile, dwFileSize, &dwBytesRead))
        {
            nError = GetLastError();
            printf("Failed to read file (%u).\n", nError);
        }
    }

    if(hFile != NULL)
    {
        SFileCloseFile(hFile);
        hFile = NULL;
    }

    if(nError == ERROR_SUCCESS)
    {
        if(!SFileCreateFile(hMpq, szFileName, 0, dwFileSize, 0, MPQ_FILE_REPLACEEXISTING, &hFile))
        {
            nError = GetLastError();
            printf("Failed to create %s in the archive (%u).\n", szFileName, nError);
        }
    }

    if(nError == ERROR_SUCCESS)
    {
        if(!SFileWriteFile(hFile, pvFile, dwFileSize, 0))
        {
            nError = GetLastError();
            printf("Failed to write the data to the MPQ (%u).\n", nError);
        }
    }

    if(hFile != NULL)
    {
        if(!SFileFinishFile(hFile))
        {
            nError = GetLastError();
            printf("Failed to finalize file creation (%u).\n", nError);
        }
    }

    if(pvFile != NULL)
        delete [] pvFile;
    if(hMpq != NULL)
        SFileCloseArchive(hMpq);
    return nError;
}

static int TestSignatureVerify(const TCHAR * szMpqName)
{
    HANDLE hMpq;
    
    if(SFileOpenArchive(szMpqName, 0, 0, &hMpq))
    {
        _tprintf(_T("Verifying digital signature in %s:\n"), szMpqName);
        switch(SFileVerifyArchive(hMpq))
        {
            case ERROR_NO_SIGNATURE:
                _tprintf(_T("No digital signature present.\n"));
                break;
        
            case ERROR_VERIFY_FAILED:
                _tprintf(_T("Failed to verify signature.\n"));
                break;
            
            case ERROR_WEAK_SIGNATURE_OK:
                _tprintf(_T("Weak signature is OK.\n"));
                break;

            case ERROR_WEAK_SIGNATURE_ERROR:
                _tprintf(_T("Weak signature mismatch.\n"));
                break;

            case ERROR_STRONG_SIGNATURE_OK:
                _tprintf(_T("Strong signature is OK.\n"));
                break;

            case ERROR_STRONG_SIGNATURE_ERROR:
                _tprintf(_T("Strong signature mismatch.\n"));
                break;
        }
        
        SFileCloseArchive(hMpq);
        _tprintf(_T("\n"));
    }

    return 0;
}


static int TestCreateArchiveCopy(const TCHAR * szMpqName, const TCHAR * szMpqCopyName, const char * szListFile)
{
    TFileStream * pStream;
    TCHAR  szLocalFile[MAX_PATH];
    HANDLE hMpq1 = NULL;                // Handle of existing archive
    HANDLE hMpq2 = NULL;                // Handle of created archive 
    DWORD dwHashTableSize = 0;
    int nError = ERROR_SUCCESS;

    // If no listfile or an empty one, use NULL
    if(szListFile == NULL || *szListFile == 0)
        szListFile = NULL;

    // Create the new file
    pStream = FileStream_CreateFile(szMpqCopyName, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
    if(pStream == NULL)
        nError = GetLastError();

    // Write some data
    if(nError == ERROR_SUCCESS)
    {
        ULONGLONG FileSize = 0x100000;
        
        FileStream_SetSize(pStream, FileSize);
        FileStream_Close(pStream);
    }

    // Open the existing MPQ archive
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Opening %s ...\n"), szMpqName);
        if(!SFileOpenArchive(szMpqName, 0, 0, &hMpq1))
            nError = GetLastError();
    }

    // Well, now create the MPQ archive
    if(nError == ERROR_SUCCESS)
    {
        _tprintf(_T("Creating %s ...\n"), szMpqCopyName);
        SFileGetFileInfo(hMpq1, SFILE_INFO_HASH_TABLE_SIZE, &dwHashTableSize, 4);
        if(!SFileCreateArchive(szMpqCopyName, 0, dwHashTableSize, &hMpq2))
            nError = GetLastError();
    }

    // Copy all files from one archive to another
    if(nError == ERROR_SUCCESS)
    {
        SFILE_FIND_DATA sf;
        HANDLE hFind = SFileFindFirstFile(hMpq1, "*", &sf, szListFile);
        bool bResult = true;

        _tprintf(_T("Copying files ...\n"));

        if(hFind != NULL)
        {
            while(bResult)
            {
                if(strcmp(sf.cFileName, LISTFILE_NAME) && strcmp(sf.cFileName, ATTRIBUTES_NAME))
                {
                    SFileSetLocale(sf.lcLocale);

                    // Create the local file name
                    MergeLocalPath(szLocalFile, szWorkDir, sf.szPlainName);
                    if(SFileExtractFile(hMpq1, sf.cFileName, szLocalFile))
                    {
                        printf("Extracting %s ... OK\n", sf.cFileName);
                        if(!SFileAddFile(hMpq2, szLocalFile, sf.cFileName, sf.dwFileFlags))
                        {
                            nError = GetLastError();
                            printf("Adding %s ... Failed\n\n", sf.cFileName);
                            _tremove(szLocalFile);
                            break;
                        }
                        else
                        {
                            printf("Adding %s ... OK\n", sf.cFileName);
                        }
                    }
                    else
                    {
                        printf("Extracting %s ... Failed\n", sf.cFileName);
                    }

                    // Delete the added file
                    _tremove(szLocalFile);
                }

                // Find the next file
                bResult = SFileFindNextFile(hFind, &sf);
            }

            // Close the search handle
            SFileFindClose(hFind);
            printf("\n");
        }
    }

    // Close both archives
    if(hMpq2 != NULL)
        SFileCloseArchive(hMpq2);
    if(hMpq1 != NULL)
        SFileCloseArchive(hMpq1);
    return nError;
}

static int TestOpenPatchedArchive(const TCHAR * szMpqName, ...)
{
    TFileStream * pStream;
    HANDLE hFile = NULL;
    HANDLE hMpq = NULL;
    va_list argList;
    const char * szFileName = "World\\Minimaps\\Azeroth\\noLiquid_map20_44.blp";
    TCHAR szLocFileName[MAX_PATH];
    LPBYTE pbFullFile = NULL;
    DWORD dwFileSize;
    int nError = ERROR_SUCCESS;

    // Open the primary MPQ
    _tprintf(_T("Opening %s ...\n"), szMpqName);
    if(!SFileOpenArchive(szMpqName, 0, MPQ_OPEN_READ_ONLY, &hMpq))
    {
        nError = GetLastError();
        _tprintf(_T("Failed to open the archive %s ...\n"), szMpqName);
    }

    // Add all patches
    if(nError == ERROR_SUCCESS)
    {
        va_start(argList, szMpqName);
        while((szMpqName = va_arg(argList, const TCHAR *)) != NULL)
        {
            _tprintf(_T("Adding patch %s ...\n"), szMpqName);
            if(!SFileOpenPatchArchive(hMpq, szMpqName, NULL, 0))
            {
                nError = GetLastError();
                printf("Failed to add patch %s ...\n", szMpqName);
            }
        }
        va_end(argList);
    }

    // Now search all files
    if(nError == ERROR_SUCCESS)
    {
        SFILE_FIND_DATA sf;
        HANDLE hFind;
        bool bResult = true;

        hFind = SFileFindFirstFile(hMpq, "World\\Minimaps\\Azeroth\\noLiquid_map20_44.*", &sf, NULL);
        while(hFind && bResult)
        {
            printf("%s\n", sf.cFileName);
            bResult = SFileFindNextFile(hFind, &sf);
        }
    }

    // Now try to open patched version of a file
    if(nError == ERROR_SUCCESS)
    {
        SFileExtractFile(hMpq, szFileName, _T("E:\\noLiquid_map20_44.blp"));
    }

    // Now try to open patched version of "Achievement.dbc"
    if(nError == ERROR_SUCCESS)
    {
        printf("Opening patched file \"%s\" ...\n", szFileName);
        SFileVerifyFile(hMpq, szFileName, SFILE_VERIFY_RAW_MD5);
        if(!SFileOpenFileEx(hMpq, szFileName, SFILE_OPEN_PATCHED_FILE, &hFile))
        {
            nError = GetLastError();
            printf("Failed to open patched file \"%s\"\n", szFileName);
        }
    }

    // Verify of the patched version is correct
    if(nError == ERROR_SUCCESS)
    {
        TCHAR * szPatchChain = NULL;
        DWORD cbPatchChain = 0;
        
        // Get the patch chain
        SFileGetFileInfo(hFile, SFILE_INFO_PATCH_CHAIN, szPatchChain, cbPatchChain, &cbPatchChain);
        szPatchChain = (TCHAR *)(new BYTE[cbPatchChain]);
        SFileGetFileInfo(hFile, SFILE_INFO_PATCH_CHAIN, szPatchChain, cbPatchChain, &cbPatchChain);
        delete [] szPatchChain;

        // Get the size of the full patched file
        dwFileSize = SFileGetFileSize(hFile, NULL);
        if(dwFileSize != 0)
        {
            DWORD dwBytesRead = 0;
            BYTE TempData[0x100];

            SFileReadFile(hFile, TempData, sizeof(TempData), &dwBytesRead);
            SFileSetFilePointer(hFile, 0, NULL, FILE_BEGIN);

            // Allocate space for the full file
            pbFullFile = new BYTE[dwFileSize];
            if(pbFullFile != NULL)
            {
                if(!SFileReadFile(hFile, pbFullFile, dwFileSize))
                {           
                    nError = GetLastError();
                    printf("Failed to read full patched file data \"%s\"\n", szFileName);
                }
                
                if(nError == ERROR_SUCCESS)
                {
                    MergeLocalPath(szLocFileName, MAKE_PATH("Work//"), GetPlainFileNameA(szFileName));
                    pStream = FileStream_CreateFile(szLocFileName, STREAM_PROVIDER_LINEAR | BASE_PROVIDER_FILE);
                    if(pStream != NULL)
                    {
                        FileStream_Write(pStream, NULL, pbFullFile, dwFileSize);
                        FileStream_Close(pStream);
                    }
                }
                
                delete [] pbFullFile;
            }
        }
    }

    // Close handles
    if(hFile != NULL)
        SFileCloseFile(hFile);
    if(hMpq != NULL)
        SFileCloseArchive(hMpq);
    return nError;
}

static int TestCompareTwoArchives(
    const TCHAR * szMpqName1,
    const TCHAR * szMpqName2,
    const char * szListFile,
    DWORD dwBlockSize)
{
    TMPQArchive * ha1 = NULL;
    TMPQArchive * ha2 = NULL;
    HANDLE hMpq1 = NULL;                // Handle of the first archive
    HANDLE hMpq2 = NULL;                // Handle of the second archive
    HANDLE hFile1 = NULL;
    HANDLE hFile2 = NULL;
    int nError = ERROR_SUCCESS;

    // If no listfile or an empty one, use NULL
    if(szListFile == NULL || *szListFile == 0)
        szListFile = NULL;

    _tprintf(_T("=============== Comparing MPQ archives ===============\n"));

    // Open the first MPQ archive
    if(nError == ERROR_SUCCESS && szMpqName1 != NULL)
    {
        _tprintf(_T("Opening %s ...\n"), szMpqName1);
        if(!SFileOpenArchive(szMpqName1, 0, 0, &hMpq1))
            nError = GetLastError();
        ha1 = (TMPQArchive *)hMpq1;
    }

    // Open the second MPQ archive
    if(nError == ERROR_SUCCESS && szMpqName2 != NULL)
    {
        _tprintf(_T("Opening %s ...\n"), szMpqName2);
        if(!SFileOpenArchive(szMpqName2, 0, 0, &hMpq2))
            nError = GetLastError();
        ha2 = (TMPQArchive *)hMpq2;
    }

    // Compare the header
    if(nError == ERROR_SUCCESS && (ha1 != NULL && ha2 != NULL))
    {
        if(ha1->pHeader->dwHeaderSize != ha2->pHeader->dwHeaderSize)
            printf(" - Header size is different\n");
        if(ha1->pHeader->wFormatVersion != ha2->pHeader->wFormatVersion)
            printf(" - Format version is different\n");
        if(ha1->pHeader->wSectorSize != ha2->pHeader->wSectorSize)
            printf(" - Sector size is different\n");
        if(ha1->pHeader->HetTableSize64 != ha2->pHeader->HetTableSize64)
            printf(" - HET table size is different\n");
        if(ha1->pHeader->BetTableSize64 != ha2->pHeader->BetTableSize64)
            printf(" - BET table size is different\n");
        if(ha1->pHeader->dwHashTableSize != ha2->pHeader->dwHashTableSize)
            printf(" - Hash table size is different\n");
        if(ha1->pHeader->dwBlockTableSize != ha2->pHeader->dwBlockTableSize)
            printf(" - Block table size is different\n");
    }

    // Find all files in the first archive and compare them
    if(nError == ERROR_SUCCESS)
    {
        SFILE_FIND_DATA sf;
        TMPQFile * hf1;
        TMPQFile * hf2;
        HANDLE hFind = SFileFindFirstFile(hMpq1, "*", &sf, szListFile);
        bool bResult = true;

        while(hFind != NULL && bResult == true)
        {
//          printf("%s           \r", sf.cFileName);
            SFileSetLocale(sf.lcLocale);

            // Open the first file
            if(!SFileOpenFileEx(hMpq1, sf.cFileName, 0, &hFile1))
                printf("Failed to open the file %s in the first archive\n", sf.cFileName);

            if(!SFileOpenFileEx(hMpq2, sf.cFileName, 0, &hFile2))
                printf("Failed to open the file %s in the second archive\n", sf.cFileName);

            if(hFile1 != NULL && hFile2 != NULL)
            {
                // Get the TMPQFile pointers
                hf1 = (TMPQFile *)hFile1;
                hf2 = (TMPQFile *)hFile2;

                // Compare the file sizes
                if(hf1->pFileEntry->dwFileSize != hf2->pFileEntry->dwFileSize)
                    printf("Different file size: %s (%u x %u)\n", sf.cFileName, hf1->pFileEntry->dwFileSize, hf2->pFileEntry->dwFileSize);

                if(hf1->pFileEntry->dwCmpSize != hf2->pFileEntry->dwCmpSize)
                    printf("Different cmpr size: %s (%u x %u)\n", sf.cFileName, hf1->pFileEntry->dwCmpSize, hf2->pFileEntry->dwCmpSize);

                if(hf1->pFileEntry->dwFlags != hf2->pFileEntry->dwFlags)
                    printf("Different mpq flags: %s (%08X x %08X)\n", sf.cFileName, hf1->pFileEntry->dwFlags, hf2->pFileEntry->dwFlags);

                if(!CompareArchivedFiles(sf.cFileName, hFile1, hFile2, dwBlockSize))
                    printf("Different file data: %s\n", sf.cFileName);

//              if(!CompareArchivedFilesRR(sf.cFileName, hFile1, hFile2, dwBlockSize))
//                  printf("Different file data: %s\n", sf.cFileName);
            }

            // Close both files
            if(hFile2 != NULL)
                SFileCloseFile(hFile2);
            if(hFile1 != NULL)
                SFileCloseFile(hFile1);
            hFile2 = hFile1 = NULL;

            // Find the next file
            bResult = SFileFindNextFile(hFind, &sf);
        }

        // Close the find handle
        if(hFind != NULL)
            SFileFindClose(hFind);
    }

    // Close both archives
    clreol();
    printf("================ MPQ compare complete ================\n");
    if(hMpq2 != NULL)
        SFileCloseArchive(hMpq2);
    if(hMpq1 != NULL)
        SFileCloseArchive(hMpq1);
    return nError;
}

//-----------------------------------------------------------------------------
// Searching all known MPQs

#ifdef _WIN32
static int TestSearchOneArchive(const TCHAR * szMpqName)
{
    SFILE_FIND_DATA sf;
    HANDLE hFind;
    HANDLE hMpq;
    const TCHAR * szExtension;
    bool bFound = true;

    // Get the file extension
    szExtension = _tcsrchr(szMpqName, _T('.'));
    if(szExtension == NULL)
        return ERROR_SUCCESS;

    // Only search defined extensions
    if(_tcsicmp(szExtension, _T(".mpq")) && _tcsnicmp(szExtension, _T(".SC2"), 4))
        return ERROR_SUCCESS;

    _tprintf(_T("Searching %s ...\n"), szMpqName);

    // Try to open the MPQ
    if(SFileOpenArchive(szMpqName, 0, MPQ_OPEN_READ_ONLY, &hMpq))
    {
        hFind = SFileFindFirstFile(hMpq, "*", &sf, NULL);
        if(hFind != NULL)
        {
            while(bFound)
            {
                if(sf.dwFileFlags & MPQ_FILE_DELETE_MARKER)
                    _tprintf(_T("Delete marker: %s:%hs\n"), szMpqName, sf.cFileName);

                bFound = SFileFindNextFile(hFind, &sf);
            }
        }

        SFileCloseArchive(hMpq);
    }

    return ERROR_SUCCESS;
}

static int TestSearchAllArchives(const TCHAR * szSearchMask)
{
    WIN32_FIND_DATA wf;
    LPTSTR szFilePart;
    HANDLE hFind;
    TCHAR szFullPath[MAX_PATH];
    BOOL bFound = TRUE;

    // Initiate search
    _tcscpy(szFullPath, szSearchMask);
    szFilePart = _tcschr(szFullPath, _T('*'));
    assert(szFilePart != NULL);

    // Begin search
    hFind = FindFirstFile(szSearchMask, &wf);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        while(bFound)
        {
            // Eliminate "." and ".."
            if(wf.cFileName[0] != _T('.'))
            {
                // Construct the full path
                _tcscpy(szFilePart, wf.cFileName);

                // If it a directory?
                if(wf.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    _tcscat(szFullPath, _T("\\*"));
                    TestSearchAllArchives(szFullPath);
                }
                else
                {
                    TestSearchOneArchive(szFullPath);
                }
            }
            bFound = FindNextFile(hFind, &wf);
        }
        FindClose(hFind);
    }

    return ERROR_SUCCESS;
}
#endif

//-----------------------------------------------------------------------------
// Main
// 

int main(void)
{
    int nError = ERROR_SUCCESS;

#if defined(_MSC_VER) && defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif  // defined(_MSC_VER) && defined(_DEBUG)

//  FileStream_OpenEncrypted(_T("e:\\Multimedia\\MPQs\\2010 - Starcraft II\\Installer UI 2 deDE.MPQE"));

    // Mix the random number generator
//  srand(GetTickCount());

    // Test structure sizes
//  if(nError == ERROR_SUCCESS)
//      nError = TestStructureSizes();

//  if(nError == ERROR_SUCCESS)
//      nError = TestOpenLocalFile("C:\\autoexec.bat");

    // Test reading partial file
//  if(nError == ERROR_SUCCESS)
//      nError = TestPartFileRead(MAKE_PATH("2009 - PartialMPQs/patch.MPQ.part"));

//  if(nError == ERROR_SUCCESS)
//      nError = ComparePklibCompressions();

    // Test LZMA compression method against the code ripped from Starcraft II
//  if(nError == ERROR_SUCCESS)
//      nError = CompareLzmaCompressions(MPQ_SECTOR_SIZE);

    // Test compression methods
//  if(nError == ERROR_SUCCESS)
//      nError = TestSectorCompress(MPQ_SECTOR_SIZE);

    // Test the archive open and close
//  if(nError == ERROR_SUCCESS)
//      nError = TestArchiveOpenAndClose(_T("d:\\Install\\Blizzard\\Diablo III\\Diablo-III-8370-enGB-Installer\\Installer Tome 1.MPQE"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("2011 - WoW BETA/wow-update-13202.MPQ"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("2002 - Warcraft III/ProtectedMap_HashTable_FakeValid.w3x"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("2010 - Starcraft II/Installer Tome 1 enGB.MPQE"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("1997 - Diablo I/DIABDAT_orig.MPQ"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("2004 - World of Warcraft/SoundCache-enUS.MPQ"));
//      nError = TestArchiveOpenAndClose(MAKE_PATH("smpq.mpq "));

//  if(nError == ERROR_SUCCESS)
//      nError = TestFindFiles(MAKE_PATH("2002 - Warcraft III/HumanEd.mpq"));

    // Create a big MPQ archive
//  if(nError == ERROR_SUCCESS)
//      nError = TestCreateArchive_PaliRoharBug(MAKE_PATH("Test.mpq"));
//      nError = TestCreateArchive(MAKE_PATH("Test.mpq"));
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName1);
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName2);
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName3);
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName4);
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName5);
//      nError = TestCreateArchive((const TCHAR*)szUnicodeName6);

//  if(nError == ERROR_SUCCESS)
//      nError = TestAddFilesToMpq(MAKE_PATH("wow-update-13202.MPQ"),
//                                 "c:\\Tools32\\Arj32.exe",
//                                 "c:\\Tools32\\autoruns.chm",
//                                 "c:\\Tools32\\CPUEater.exe",
//                                 "c:\\Tools32\\dumpbin.exe",
//                                 "c:\\Tools32\\editbin.exe",
//                                 "c:\\Tools32\\fsg.ini",
//                                 "c:\\Tools32\\hiew8.ini",
//                                 "c:\\Tools32\\ida.bat",
//                                 "c:\\Tools32\\mp3.ini",
//                                 NULL);

//  if(nError == ERROR_SUCCESS)
//      nError = TestCreateArchiveFromMemory(MAKE_PATH("Test-leak.mpq"));

//  if(nError == ERROR_SUCCESS)
//      nError = TestFileReadAndWrite(MAKE_PATH("2002 - Warcraft III/(10)DustwallowKeys.w3m"), "war3map.j");

    // Verify the archive signature
//  if(nError == ERROR_SUCCESS)
//      nError = TestSignatureVerify(MAKE_PATH("1998 - Starcraft/BW-1152.exe"));
//      nError = TestSignatureVerify(MAKE_PATH("2002 - Warcraft III/(10)DustwallowKeys.w3m"));
//      nError = TestSignatureVerify(MAKE_PATH("2002 - Warcraft III/War3TFT_121b_English.exe"));
//      nError = TestSignatureVerify(MAKE_PATH("2004 - World of Warcraft/WoW-2.3.3.7799-to-2.4.0.8089-enUS-patch.exe"));
//      nError = TestSignatureVerify(MAKE_PATH("2004 - World of Warcraft/standalone.MPQ"));

    // Compact the archive        
//  if(nError == ERROR_SUCCESS)
//      nError = TestMpqCompacting(MAKE_PATH("wow-update-base-14333.MPQ"));
    
    // Create copy of the archive, appending some bytes before the MPQ header
//  if(nError == ERROR_SUCCESS)
//      nError = TestCreateArchiveCopy(MAKE_PATH("PartialMPQs/interface.MPQ.part"), MAKE_PATH("PartialMPQs/interface-copy.MPQ.part"), NULL);

/*
    if(nError == ERROR_SUCCESS)
    {
        nError = TestOpenPatchedArchive(MAKE_PATH("2011 - WoW 4.x/locale-enGB.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13164.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13205.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13287.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13329.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13596.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-13623.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-enGB-13914.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-enGB-14007.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-enGB-14333.MPQ"),
                                        MAKE_PATH("2011 - WoW 4.x/wow-update-enGB-14480.MPQ"),
                                        NULL);
    }
*/

    if(nError == ERROR_SUCCESS)
    {
        nError = TestCompareTwoArchives(MAKE_PATH("Sound-copy.mpq"),
                                        MAKE_PATH("Sound.mpq"),
                                        NULL,
                                        0x1001);
    }


//  if(nError == ERROR_SUCCESS)
//      nError = TestSearchAllArchives(MAKE_PATH("*"));

    return nError;
}
