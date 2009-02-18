/*****************************************************************************/
/* SCompression.cpp                       Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* This module serves as a bridge between StormLib code and (de)compression  */
/* functions. All (de)compression calls go (and should only go) through this */
/* module. No system headers should be included in this module to prevent    */
/* compile-time problems.                                                    */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 01.04.03  1.00  Lad  The first version of SCompression.cpp                */
/* 19.11.03  1.01  Dan  Big endian handling                                  */
/*****************************************************************************/

#define __STORMLIB_SELF__
#include "StormLib.h"
#include "SCommon.h"

#include <string.h>

// Include functions from Pkware Data Compression Library
#include "pklib/pklib.h"

// Include functions from zlib
#ifndef __SYS_ZLIB
#include "zlib/zlib.h"      // Include functions from zlib
#else
#include <zlib.h>           // If zlib is available on system, use this instead
#endif

// Include functions from Huffmann compression
#include "huffman/huff.h"

// Include functions from WAVe compression
#include "wave/wave.h"

// Include functions from BZip2 compression library
#ifndef __SYS_BZLIB
#include "bzip2/bzlib.h"      // Include functions from bzlib
#else
#include <bzlib.h>           // If bzlib is available on system, use this instead
#endif

//-----------------------------------------------------------------------------
// Local structures

// Information about the input and output buffers for pklib
typedef struct
{
    char * pInBuff;                     // Pointer to input data buffer
    int    nInPos;                      // Current offset in input data buffer
    int    nInBytes;                    // Number of bytes in the input buffer
    char * pOutBuff;                    // Pointer to output data buffer
    int    nOutPos;                     // Position in the output buffer
    int    nMaxOut;                     // Maximum number of bytes in the output buffer
} TDataInfo;

// Table of compression functions
typedef int (*COMPRESS)(char *, int *, char *, int, int *, int);
typedef struct
{
    unsigned long dwMask;               // Compression mask
    COMPRESS Compress;                  // Compression function
} TCompressTable;

// Table of decompression functions
typedef int (*DECOMPRESS)(char *, int *, char *, int);
typedef struct
{
    unsigned long dwMask;               // Decompression bit
    DECOMPRESS    Decompress;           // Decompression function
} TDecompressTable;


/*****************************************************************************/
/*                                                                           */
/*  Support functions for Pkware Data Compression Library                    */
/*                                                                           */
/*****************************************************************************/

// Function loads data from the input buffer. Used by Pklib's "implode"
// and "explode" function as user-defined callback
// Returns number of bytes loaded
//
//   char * buf          - Pointer to a buffer where to store loaded data
//   unsigned int * size - Max. number of bytes to read
//   void * param        - Custom pointer, parameter of implode/explode

static unsigned int ReadInputData(char * buf, unsigned int * size, void * param)
{
    TDataInfo * pInfo = (TDataInfo *)param;
    unsigned int nMaxAvail = (pInfo->nInBytes - pInfo->nInPos);
    unsigned int nToRead = *size;

    // Check the case when not enough data available
    if(nToRead > nMaxAvail)
        nToRead = nMaxAvail;

    // Load data and increment offsets
    memcpy(buf, pInfo->pInBuff + pInfo->nInPos, nToRead);
    pInfo->nInPos += nToRead;

    return nToRead;
}

// Function for store output data. Used by Pklib's "implode" and "explode"
// as user-defined callback
//
//   char * buf          - Pointer to data to be written
//   unsigned int * size - Number of bytes to write
//   void * param        - Custom pointer, parameter of implode/explode

static void WriteOutputData(char * buf, unsigned int * size, void * param)
{
    TDataInfo * pInfo = (TDataInfo *)param;
    unsigned int nMaxWrite = (pInfo->nMaxOut - pInfo->nOutPos);
    unsigned int nToWrite = *size;

    // Check the case when not enough space in the output buffer
    if(nToWrite > nMaxWrite)
        nToWrite = nMaxWrite;

    // Write output data and increments offsets
    memcpy(pInfo->pOutBuff + pInfo->nOutPos, buf, nToWrite);
    pInfo->nOutPos += nToWrite;
}

/*****************************************************************************/
/*                                                                           */
/*  "80" is IMA ADPCM stereo (de)compression                                 */
/*  "40" is IMA ADPCM mono (de)compression                                   */
/*                                                                           */
/*****************************************************************************/

int Compress_wave_mono(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * pCmpType, int nCmpLevel)
{
    // Prepare the compression level for the next compression
    // (After us, the Huffmann compression will be called)
    if(0 < nCmpLevel && nCmpLevel <= 2)
    {
        nCmpLevel = 4;
        *pCmpType = 6;
    }
    else if(nCmpLevel == 3)
    {
        nCmpLevel = 6;
        *pCmpType = 8;
    }
    else
    {
        nCmpLevel = 5;
        *pCmpType = 7;
    }
    *pdwOutLength = CompressWave((unsigned char *)pbOutBuffer, *pdwOutLength, (short *)pbInBuffer, dwInLength, 1, nCmpLevel);
    return 0;
}

int Decompress_wave_mono(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    *pdwOutLength = DecompressWave((unsigned char *)pbOutBuffer, *pdwOutLength, (unsigned char *)pbInBuffer, dwInLength, 1);
    return 1;
}

int Compress_wave_stereo(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * pCmpType, int nCmpLevel)
{
    // Prepare the compression type for the next compression
    // (After us, the Huffmann compression will be called)
    if(0 < nCmpLevel && nCmpLevel <= 2)
    {
        nCmpLevel = 4;
        *pCmpType = 6;
    }
    else if(nCmpLevel == 3)
    {
        nCmpLevel = 6;
        *pCmpType = 8;
    }
    else
    {
        nCmpLevel = 5;
        *pCmpType = 7;
    }
    *pdwOutLength = CompressWave((unsigned char *)pbOutBuffer, *pdwOutLength, (short *)pbInBuffer, dwInLength, 2, nCmpLevel);
    return 0;
}

int Decompress_wave_stereo(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    *pdwOutLength = DecompressWave((unsigned char *)pbOutBuffer, *pdwOutLength, (unsigned char *)pbInBuffer, dwInLength, 2);
    return 1;
}

/*****************************************************************************/
/*                                                                           */
/*  The "01" (de)compression is the Huffman (de)compression                  */
/*                                                                           */
/*****************************************************************************/

// 1500F4C0
int Compress_huff(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * pCmpType, int /* nCmpLevel */)
{
    THuffmannTree ht;                   // Huffmann tree for compression
    TOutputStream os;                   // Output stream

    // Initialize output stream
    os.pbOutBuffer = (unsigned char *)pbOutBuffer;
    os.dwOutSize   = *pdwOutLength;
    os.pbOutPos    = (unsigned char *)pbOutBuffer;
    os.dwBitBuff   = 0;
    os.nBits       = 0;

    // Initialize the Huffmann tree for compression
    ht.InitTree(true);

    *pdwOutLength = ht.DoCompression(&os, (unsigned char *)pbInBuffer, dwInLength, *pCmpType);

    // The following code is not necessary to run, because it has no
    // effect on the output data. It only clears the huffmann tree, but when
    // the tree is on the stack, who cares ?
//  ht.UninitTree();
    return 0;
}

// 1500F5F0
int Decompress_huff(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int /* dwInLength */)
{
    THuffmannTree ht;
    TInputStream  is;

    // Initialize input stream
//  is.pbInBuffer  = (unsigned char *)pbInBuffer;
    is.dwBitBuff   = BSWAP_INT32_UNSIGNED(*(unsigned long *)pbInBuffer);
    pbInBuffer    += sizeof(unsigned long);
    is.pbInBuffer  = (unsigned char *)pbInBuffer;
    is.nBits       = 32;

    // Initialize the Huffmann tree for compression
    ht.InitTree(false);
    *pdwOutLength = ht.DoDecompression((unsigned char *)pbOutBuffer, *pdwOutLength, &is);

    // The following code is not necessary to run, because it has no
    // effect on the output data. It only clears the huffmann tree, but when
    // the tree is on the stack, who cares ?
//  ht.UninitTree();
    return 0;
}

/*****************************************************************************/
/*                                                                           */
/*  The "02" (de)compression is the ZLIB (de)compression                     */
/*                                                                           */
/*****************************************************************************/

int Compress_zlib(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * /* pCmpType */, int /* nCmpLevel */)
{
    z_stream z;                        // Stream information for zlib
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = (Bytef *)pbInBuffer;
    z.avail_in  = (uInt)dwInLength;
    z.total_in  = dwInLength;
    z.next_out  = (Bytef *)pbOutBuffer;
    z.avail_out = *pdwOutLength;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Initialize the compression structure. Storm.dll uses zlib version 1.1.3
    *pdwOutLength = 0;
    if((nResult = deflateInit(&z, Z_DEFAULT_COMPRESSION)) == 0)
    {
        // Call zlib to compress the data
        nResult = deflate(&z, Z_FINISH);

        if(nResult == Z_OK || nResult == Z_STREAM_END)
            *pdwOutLength = z.total_out;

        deflateEnd(&z);
    }
    return nResult;
}

int Decompress_zlib(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    z_stream z;                        // Stream information for zlib
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = (Bytef *)pbInBuffer;
    z.avail_in  = (uInt)dwInLength;
    z.total_in  = dwInLength;
    z.next_out  = (Bytef *)pbOutBuffer;
    z.avail_out = *pdwOutLength;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Initialize the decompression structure. Storm.dll uses zlib version 1.1.3
    if((nResult = inflateInit(&z)) == 0)
    {
        // Call zlib to decompress the data
        nResult = inflate(&z, Z_FINISH);
        *pdwOutLength = z.total_out;
        inflateEnd(&z);
    }
    return nResult;
}

/*****************************************************************************/
/*                                                                           */
/*  The "08" (de)compression is the Pkware DCL (de)compression               */
/*                                                                           */
/*****************************************************************************/

int Compress_pklib(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * pCmpType, int /* nCmpLevel */)
{
    TDataInfo Info;                             // Data information
    char * work_buf = ALLOCMEM(char, CMP_BUFFER_SIZE);// Pklib's work buffer
    unsigned int dict_size;                     // Dictionary size
    unsigned int ctype;                         // Compression type

    // Fill data information structure
    Info.pInBuff  = pbInBuffer;
    Info.nInPos   = 0;
    Info.nInBytes = dwInLength;
    Info.pOutBuff = pbOutBuffer;
    Info.nOutPos  = 0;
    Info.nMaxOut  = *pdwOutLength;

    // Set the compression type and dictionary size
    ctype = (*pCmpType == 2) ? CMP_ASCII : CMP_BINARY;
    if (dwInLength < 0x600)
        dict_size = 0x400;
    else if(0x600 <= dwInLength && dwInLength < 0xC00)
        dict_size = 0x800;
    else
        dict_size = 0x1000;

    // Do the compression
    implode(ReadInputData, WriteOutputData, work_buf, &Info, &ctype, &dict_size);
    *pdwOutLength = Info.nOutPos;
    FREEMEM(work_buf);
    return 0;
}

int Decompress_pklib(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    TDataInfo Info;                             // Data information
    char * work_buf = ALLOCMEM(char, EXP_BUFFER_SIZE);// Pklib's work buffer

    // Fill data information structure
    Info.pInBuff  = pbInBuffer;
    Info.nInPos   = 0;
    Info.nInBytes = dwInLength;
    Info.pOutBuff = pbOutBuffer;
    Info.nOutPos  = 0;
    Info.nMaxOut  = *pdwOutLength;

    // Do the decompression
    explode(ReadInputData, WriteOutputData, work_buf, &Info);

    // Fix: If PKLIB is unable to decompress the data, they are uncompressed
    if(Info.nOutPos == 0)
    {
        Info.nOutPos = min(*pdwOutLength, dwInLength);
        memcpy(pbOutBuffer, pbInBuffer, Info.nOutPos);
    }

    *pdwOutLength = Info.nOutPos;
    FREEMEM(work_buf);
    return 0;
}

/*****************************************************************************/
/*                                                                           */
/*  The "10" (de)compression is the Bzip2 (de)compression                    */
/*                                                                           */
/*****************************************************************************/

int Compress_bzip2(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength, int * pCmpType, int nCmpLevel)
{
    bz_stream strm;
    int blockSize100k;
    int workFactor = 30;

    // Keep compiler happy
    nCmpLevel = nCmpLevel;

    // Initialize the BZLIB compression
    strm.bzalloc = NULL;
    strm.bzfree  = NULL;

    // Adjust the block size
    blockSize100k = *pCmpType;
    if(blockSize100k < 1 || blockSize100k > 9)
        blockSize100k = 9;

    // Blizzard uses 9 as blockSize100k, (0 as workFactor)
    if(BZ2_bzCompressInit(&strm, blockSize100k, 0, workFactor) == 0)
    {
        strm.next_in   = pbInBuffer;
        strm.avail_in  = dwInLength;
        strm.next_out  = pbOutBuffer;
        strm.avail_out = *pdwOutLength;

        // Perform the compression
        while(BZ2_bzCompress(&strm, (strm.avail_in != 0) ? BZ_RUN : BZ_FINISH) != BZ_STREAM_END);

        // Put the stream into idle state
        BZ2_bzCompressEnd(&strm);
        *pdwOutLength = strm.total_out_lo32;
    }
    else
    {
        *pdwOutLength = 0;
    }

    return 0;
}

int Decompress_bzip2(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    bz_stream strm;

    // Initialize the BZLIB decompression
    strm.bzalloc = NULL;
    strm.bzfree  = NULL;
    if(BZ2_bzDecompressInit(&strm, 0, 0) == 0)
    {
        strm.next_in   = pbInBuffer;
        strm.avail_in  = dwInLength;
        strm.next_out  = pbOutBuffer;
        strm.avail_out = *pdwOutLength;

        // Perform the decompression
        while(BZ2_bzDecompress(&strm) != BZ_STREAM_END);

        // Put the stream into idle state
        BZ2_bzDecompressEnd(&strm);
        *pdwOutLength = strm.total_out_lo32;
    }
    else
    {
        // Set zero output length
        *pdwOutLength = 0;
    }

    return 0;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompCompress                                                           */
/*                                                                           */
/*****************************************************************************/

// This table contains compress functions which can be applied to
// uncompressed blocks. Each bit set means the corresponding
// compression method/function must be applied.
//
//   WAVes compression            Data compression
//   ------------------           -------------------
//   1st block   - 0x08           0x08 (D, HF, W2, SC, D2)
//   Rest blocks - 0x81           0x02 (W3)

static TCompressTable cmp_table[] =
{
    {MPQ_COMPRESSION_WAVE_MONO,   Compress_wave_mono},   // IMA ADPCM mono compression
    {MPQ_COMPRESSION_WAVE_STEREO, Compress_wave_stereo}, // IMA ADPCM stereo compression
    {MPQ_COMPRESSION_HUFFMANN,    Compress_huff},        // Huffmann compression
    {MPQ_COMPRESSION_ZLIB,        Compress_zlib},        // Compression with the "zlib" library
    {MPQ_COMPRESSION_PKWARE,      Compress_pklib},       // Compression with Pkware DCL
    {MPQ_COMPRESSION_BZIP2,       Compress_bzip2}        // Compression Bzip2 library
};

int WINAPI SCompCompress(char * pbCompressed, int * pdwOutLength, char * pbUncompressed, int dwInLength,
                  int uCompressions, int nCmpType, int nCmpLevel)
{
    char * pbTempBuff = NULL;           // Temporary storage for decompressed data
    char * pbOutput = pbCompressed;     // Current output buffer
    char * pbInput;                     // Current input buffer
    int uCompressions2;
    int dwCompressCount = 0;
    int dwDoneCount = 0;
    int dwOutSize = 0;
    int dwInSize  = dwInLength;
    int dwEntries = (sizeof(cmp_table) / sizeof(TCompressTable));
    int nResult = 1;
    int i;

    // Check for valid parameters
    if(!pdwOutLength || *pdwOutLength < dwInLength || !pbCompressed || !pbUncompressed)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // Count the compressions
    for(i = 0, uCompressions2 = uCompressions; i < dwEntries; i++)
    {
        if(uCompressions & cmp_table[i].dwMask)
            dwCompressCount++;

        uCompressions2 &= ~cmp_table[i].dwMask;
    }

    // If a compression remains, do nothing
    if(uCompressions2 != 0)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // If more that one compression, allocate intermediate buffer
    if(dwCompressCount >= 2)
        pbTempBuff = ALLOCMEM(char, *pdwOutLength + 1);

    // Perform the compressions
    pbInput = pbUncompressed;
    dwInSize = dwInLength;
    for(i = 0, uCompressions2 = uCompressions; i < dwEntries; i++)
    {
        if(uCompressions2 & cmp_table[i].dwMask)
        {
            // Set the right output buffer
            dwCompressCount--;
            pbOutput = (dwCompressCount & 1) ? pbTempBuff : pbCompressed;

            // Perform the partial compression
            dwOutSize = *pdwOutLength - 1;

            cmp_table[i].Compress(pbOutput + 1, &dwOutSize, pbInput, dwInSize, &nCmpType, nCmpLevel);
            if(dwOutSize == 0)
            {
                SetLastError(ERROR_GEN_FAILURE);
                *pdwOutLength = 0;
                nResult = 0;
                break;
            }

            // If the compression failed, copy the block instead
            if(dwOutSize >= dwInSize - 1)
            {
                if(dwDoneCount > 0)
                    pbOutput++;

                memcpy(pbOutput, pbInput, dwInSize);
                pbInput = pbOutput;
                uCompressions &= ~cmp_table[i].dwMask;
                dwOutSize = dwInSize;
            }
            else
            {
                pbInput = pbOutput + 1;
                dwInSize = dwOutSize;
                dwDoneCount++;
            }
        }
    }

    // Copy the compressed data to the correct output buffer
    if(nResult != 0)
    {
        if(uCompressions && (dwInSize + 1) < *pdwOutLength)
        {
            if(pbOutput != pbCompressed  && pbOutput != pbCompressed + 1)
                memcpy(pbCompressed, pbOutput, dwInSize);
            *pbCompressed = (char)uCompressions;
            *pdwOutLength = dwInSize + 1;
        }
        else
        {
            memmove(pbCompressed, pbUncompressed, dwInSize);
            *pdwOutLength = dwInSize;
        }
    }

    // Cleanup and return
    if(pbTempBuff != NULL)
        FREEMEM(pbTempBuff);
    return nResult;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompDecompress                                                         */
/*                                                                           */
/*****************************************************************************/

// This table contains decompress functions which can be applied to
// uncompressed blocks. The compression mask is stored in the first byte
// of compressed block
static TDecompressTable dcmp_table[] =
{
    {MPQ_COMPRESSION_BZIP2,       Decompress_bzip2},       // Decompression with Bzip2 library
    {MPQ_COMPRESSION_PKWARE,      Decompress_pklib},       // Decompression with Pkware Data Compression Library
    {MPQ_COMPRESSION_ZLIB,        Decompress_zlib},        // Decompression with the "zlib" library
    {MPQ_COMPRESSION_HUFFMANN,    Decompress_huff},        // Huffmann decompression
    {MPQ_COMPRESSION_WAVE_STEREO, Decompress_wave_stereo}, // IMA ADPCM stereo decompression
    {MPQ_COMPRESSION_WAVE_MONO,   Decompress_wave_mono}    // IMA ADPCM mono decompression
};

int WINAPI SCompDecompress(char * pbOutBuffer, int * pdwOutLength, char * pbInBuffer, int dwInLength)
{
    char *   pbTempBuff = NULL;           // Temporary storage for decompressed data
    char *   pbWorkBuff = NULL;           // Where to store decompressed data
    int      dwOutLength = *pdwOutLength; // For storage number of output bytes
    unsigned fDecompressions1;            // Decompressions applied to the block
    unsigned fDecompressions2;            // Just another copy of decompressions applied to the block
    int      dwCount = 0;                 // Counter for every use
    int      dwEntries = (sizeof(dcmp_table) / sizeof(TDecompressTable));
    int      nResult = 1;
    int      i;

    // If the input length is the same as output, do nothing.
    if(dwInLength == dwOutLength)
    {
        if(pbInBuffer == pbOutBuffer)
            return 1;

        memcpy(pbOutBuffer, pbInBuffer, dwInLength);
        *pdwOutLength = dwInLength;
        return 1;
    }

    // Get applied compression types and decrement data length
    fDecompressions1 = fDecompressions2 = (unsigned char)*pbInBuffer++;
    dwInLength--;

    // Search decompression table type and get all types of compression
    for(i = 0; i < dwEntries; i++)
    {
        // We have to apply this decompression ?
        if(fDecompressions1 & dcmp_table[i].dwMask)
            dwCount++;

        // Clear this flag from temporary variable.
        fDecompressions2 &= ~dcmp_table[i].dwMask;
    }

    // Check if there is some method unhandled
    // (E.g. compressed by future versions)
    if(fDecompressions2 != 0)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // If there is more than only one compression, we have to allocate extra buffer
    if(dwCount >= 2)
        pbTempBuff = ALLOCMEM(char, dwOutLength);

    // Apply all decompressions
    for(i = 0, dwCount = 0; i < dwEntries; i++)
    {
        // If not used this kind of compression, skip the loop
        if(fDecompressions1 & dcmp_table[i].dwMask)
        {
            // If odd case, use target buffer for output, otherwise use allocated tempbuffer
            pbWorkBuff  = (dwCount++ & 1) ? pbTempBuff : pbOutBuffer;
            dwOutLength = *pdwOutLength;

            // Decompress buffer using corresponding function
            dcmp_table[i].Decompress(pbWorkBuff, &dwOutLength, pbInBuffer, dwInLength);
            if(dwOutLength == 0)
            {
                SetLastError(ERROR_GEN_FAILURE);
                nResult = 0;
                break;
            }

            // Move output length to src length for next compression
            dwInLength = dwOutLength;
            pbInBuffer = pbWorkBuff;
        }
    }

    // If output buffer is not the same like target buffer, we have to copy data
    if(nResult != 0)
    {
        if(pbWorkBuff != pbOutBuffer)
            memcpy(pbOutBuffer, pbInBuffer, dwOutLength);

    }

    // Delete temporary buffer, if necessary
    if(pbTempBuff != NULL)
        FREEMEM(pbTempBuff);

    *pdwOutLength = dwOutLength;
    return nResult;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompSetDataCompression                                                 */
/*                                                                           */
/*****************************************************************************/

int WINAPI SCompSetDataCompression(int nDataCompression)
{
    int nValidMask = (MPQ_COMPRESSION_ZLIB | MPQ_COMPRESSION_PKWARE | MPQ_COMPRESSION_BZIP2);

    if((nDataCompression & nValidMask) != nDataCompression)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return FALSE;
    }

    SetDataCompression(nDataCompression);
    return TRUE;
}



