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
#include "StormCommon.h"

//-----------------------------------------------------------------------------
// Local structures

// Information about the input and output buffers for pklib
typedef struct
{
    char * pbInBuff;                     // Pointer to input data buffer
    char * pbInBuffEnd;                  // End of the input buffer
    char * pbOutBuff;                    // Pointer to output data buffer
    char * pbOutBuffEnd;                 // Pointer to output data buffer
} TDataInfo;

// Prototype of the compression function
// Function doesn't return an error. A success means that the size of compressed buffer
// is lower than size of uncompressed buffer.
typedef void (*COMPRESS)(
    char * pbOutBuffer,                 // [out] Pointer to the buffer where the compressed data will be stored
    int * pcbOutBuffer,                 // [in]  Pointer to length of the buffer pointed by pbOutBuffer
                                        // [out] Contains length of the compressed data
    char * pbInBuffer,                  // [in]  Pointer to the buffer with data to compress
    int cbInBuffer,                     // [in]  Length of the buffer pointer by pbInBuffer
    int * pCmpType,                     // [in]  Compression-method specific value. ADPCM Setups this for the following Huffman compression
    int nCmpLevel);                     // [in]  Compression specific value. ADPCM uses this. Should be set to zero.

// Prototype of the decompression function
// Returns 1 if success, 0 if failure
typedef int (*DECOMPRESS)(
    char * pbOutBuffer,                 // [out] Pointer to the buffer where to store decompressed data
    int * pcbOutBuffer,                 // [in]  Pointer to total size of the buffer pointed by pbOutBuffer
                                        // [out] Contains length of the decompressed data
    char * pbInBuffer,                  // [in]  Pointer to data to be decompressed  
    int cbInBuffer);                    // [in]  Length of the data to be decompressed

// Table of compression functions
typedef struct  
{
    unsigned long uMask;                // Compression mask
    COMPRESS Compress;                  // Compression function
} TCompressTable;

// Table of decompression functions
typedef struct
{
    unsigned long uMask;                // Decompression bit
    DECOMPRESS    Decompress;           // Decompression function
} TDecompressTable;


/*****************************************************************************/
/*                                                                           */
/*  Support for Huffman compression (0x01)                                   */
/*                                                                           */
/*****************************************************************************/

// 1500F4C0
void Compress_huff(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * pCmpType,
    int /* nCmpLevel */)
{
    THuffmannTree ht;                   // Huffmann tree for compression
    TOutputStream os;                   // Output stream

    // Initialize output stream
    os.pbOutBuffer = (unsigned char *)pbOutBuffer;
    os.cbOutSize   = *pcbOutBuffer;
    os.pbOutPos    = (unsigned char *)pbOutBuffer;
    os.dwBitBuff   = 0;
    os.nBits       = 0;

    // Initialize the Huffmann tree for compression
    ht.InitTree(true);

    *pcbOutBuffer = ht.DoCompression(&os, (unsigned char *)pbInBuffer, cbInBuffer, *pCmpType);

    // The following code is not necessary to run, because it has no
    // effect on the output data. It only clears the huffmann tree, but when
    // the tree is on the stack, who cares ?
//  ht.UninitTree();
}

// 1500F5F0
int Decompress_huff(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    THuffmannTree ht;
    TInputStream  is;

    // Initialize input stream
    is.pbInBufferEnd = (unsigned char *)pbInBuffer + cbInBuffer;
    is.pbInBuffer = (unsigned char *)pbInBuffer;
    is.BitBuffer  = 0;
    is.BitCount   = 0;

    // Initialize the Huffmann tree for compression
    ht.InitTree(false);
    *pcbOutBuffer = ht.DoDecompression((unsigned char *)pbOutBuffer, *pcbOutBuffer, &is);
    if(*pcbOutBuffer == 0)
        return 0;

    // The following code is not necessary to run, because it has no
    // effect on the output data. It only clears the huffmann tree, but when
    // the tree is on the stack, who cares ?
//  ht.UninitTree();
    return 1;
}

/******************************************************************************/
/*                                                                            */
/*  Support for ZLIB compression (0x02)                                       */
/*                                                                            */
/******************************************************************************/

void Compress_ZLIB(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * /* pCmpType */,
    int /* nCmpLevel */)
{
    z_stream z;                        // Stream information for zlib
    int windowBits;
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = (Bytef *)pbInBuffer;
    z.avail_in  = (uInt)cbInBuffer;
    z.total_in  = cbInBuffer;
    z.next_out  = (Bytef *)pbOutBuffer;
    z.avail_out = *pcbOutBuffer;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Determine the proper window bits (WoW.exe build 12694)
    if(cbInBuffer <= 0x100)
        windowBits = 8;
    else if(cbInBuffer <= 0x200)
        windowBits = 9;
    else if(cbInBuffer <= 0x400)
        windowBits = 10;
    else if(cbInBuffer <= 0x800)
        windowBits = 11;
    else if(cbInBuffer <= 0x1000)
        windowBits = 12;
    else if(cbInBuffer <= 0x2000)
        windowBits = 13;
    else if(cbInBuffer <= 0x4000)
        windowBits = 14;
    else
        windowBits = 15;

    // Initialize the compression.
    // Storm.dll uses zlib version 1.1.3
    // Wow.exe uses zlib version 1.2.3
    nResult = deflateInit2(&z,
                            Z_DEFAULT_COMPRESSION,
                            Z_DEFLATED,
                            windowBits,
                            8,
                            Z_DEFAULT_STRATEGY);
    if(nResult == Z_OK)
    {
        // Call zlib to compress the data
        nResult = deflate(&z, Z_FINISH);
        
        if(nResult == Z_OK || nResult == Z_STREAM_END)
            *pcbOutBuffer = z.total_out;

        deflateEnd(&z);
    }
}

int Decompress_ZLIB(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    z_stream z;                        // Stream information for zlib
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = (Bytef *)pbInBuffer;
    z.avail_in  = (uInt)cbInBuffer;
    z.total_in  = cbInBuffer;
    z.next_out  = (Bytef *)pbOutBuffer;
    z.avail_out = *pcbOutBuffer;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Initialize the decompression structure. Storm.dll uses zlib version 1.1.3
    if((nResult = inflateInit(&z)) == 0)
    {
        // Call zlib to decompress the data
        nResult = inflate(&z, Z_FINISH);
        *pcbOutBuffer = z.total_out;
        inflateEnd(&z);
    }
    return nResult;
}

/******************************************************************************/
/*                                                                            */
/*  Support functions for PKWARE Data Compression Library compression (0x08)  */
/*                                                                            */
/******************************************************************************/

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
    unsigned int nMaxAvail = (unsigned int)(pInfo->pbInBuffEnd - pInfo->pbInBuff);
    unsigned int nToRead = *size;

    // Check the case when not enough data available
    if(nToRead > nMaxAvail)
        nToRead = nMaxAvail;
    
    // Load data and increment offsets
    memcpy(buf, pInfo->pbInBuff, nToRead);
    pInfo->pbInBuff += nToRead;
    assert(pInfo->pbInBuff <= pInfo->pbInBuffEnd);
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
    unsigned int nMaxWrite = (unsigned int)(pInfo->pbOutBuffEnd - pInfo->pbOutBuff);
    unsigned int nToWrite = *size;

    // Check the case when not enough space in the output buffer
    if(nToWrite > nMaxWrite)
        nToWrite = nMaxWrite;

    // Write output data and increments offsets
    memcpy(pInfo->pbOutBuff, buf, nToWrite);
    pInfo->pbOutBuff += nToWrite;
    assert(pInfo->pbOutBuff <= pInfo->pbOutBuffEnd);
}

static void Compress_PKLIB(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * /* pCmpType */,
    int /* nCmpLevel */)
{
    TDataInfo Info;                                      // Data information
    char * work_buf = STORM_ALLOC(char, CMP_BUFFER_SIZE);// Pklib's work buffer
    unsigned int dict_size;                              // Dictionary size
    unsigned int ctype = CMP_BINARY;                     // Compression type

    // Fill data information structure
    memset(work_buf, 0, CMP_BUFFER_SIZE);
    Info.pbInBuff     = pbInBuffer;
    Info.pbInBuffEnd  = pbInBuffer + cbInBuffer;
    Info.pbOutBuff    = pbOutBuffer;
    Info.pbOutBuffEnd = pbOutBuffer + *pcbOutBuffer;

    // Set the compression type and dictionary size
    if (cbInBuffer < 0x600)
        dict_size = CMP_IMPLODE_DICT_SIZE1;
    else if(0x600 <= cbInBuffer && cbInBuffer < 0xC00)
        dict_size = CMP_IMPLODE_DICT_SIZE2;
    else
        dict_size = CMP_IMPLODE_DICT_SIZE3;

    // Do the compression
    if(implode(ReadInputData, WriteOutputData, work_buf, &Info, &ctype, &dict_size) == CMP_NO_ERROR)
        *pcbOutBuffer = (int)(Info.pbOutBuff - pbOutBuffer);

    STORM_FREE(work_buf);
}

static int Decompress_PKLIB(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    TDataInfo Info;                             // Data information
    char * work_buf = STORM_ALLOC(char, EXP_BUFFER_SIZE);// Pklib's work buffer

    // Fill data information structure
    memset(work_buf, 0, EXP_BUFFER_SIZE);
    Info.pbInBuff     = pbInBuffer;
    Info.pbInBuffEnd  = pbInBuffer + cbInBuffer;
    Info.pbOutBuff    = pbOutBuffer;
    Info.pbOutBuffEnd = pbOutBuffer + *pcbOutBuffer;

    // Do the decompression
    explode(ReadInputData, WriteOutputData, work_buf, &Info);
    
    // If PKLIB is unable to decompress the data, return 0;
    if(Info.pbOutBuff == pbOutBuffer)
        return 0;

    // Give away the number of decompressed bytes
    *pcbOutBuffer = (int)(Info.pbOutBuff - pbOutBuffer);
    STORM_FREE(work_buf);
    return 1;
}

/******************************************************************************/
/*                                                                            */
/*  Support for Bzip2 compression (0x10)                                      */
/*                                                                            */
/******************************************************************************/

static void Compress_BZIP2(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * /* pCmpType */,
    int /* nCmpLevel */)
{
    bz_stream strm;
    int blockSize100k = 9;
    int workFactor = 30;
    int bzError;

    // Initialize the BZIP2 compression
    strm.bzalloc = NULL;
    strm.bzfree  = NULL;

    // Blizzard uses 9 as blockSize100k, (0x30 as workFactor)
    // Last checked on Starcraft II
    if(BZ2_bzCompressInit(&strm, blockSize100k, 0, workFactor) == BZ_OK)
    {
        strm.next_in   = pbInBuffer;
        strm.avail_in  = cbInBuffer;
        strm.next_out  = pbOutBuffer;
        strm.avail_out = *pcbOutBuffer;

        // Perform the compression
        for(;;)
        {
            bzError = BZ2_bzCompress(&strm, (strm.avail_in != 0) ? BZ_RUN : BZ_FINISH);
            if(bzError == BZ_STREAM_END || bzError < 0)
                break;
        }

        // Put the stream into idle state
        BZ2_bzCompressEnd(&strm);

        if(bzError > 0)
            *pcbOutBuffer = strm.total_out_lo32;
    }
}

static int Decompress_BZIP2(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    bz_stream strm;
    int nResult = BZ_OK;

    // Initialize the BZIP2 decompression
    strm.bzalloc = NULL;
    strm.bzfree  = NULL;
    if(BZ2_bzDecompressInit(&strm, 0, 0) == BZ_OK)
    {
        strm.next_in   = pbInBuffer;
        strm.avail_in  = cbInBuffer;
        strm.next_out  = pbOutBuffer;
        strm.avail_out = *pcbOutBuffer;

        // Perform the decompression
        while(nResult != BZ_STREAM_END)
        {
            nResult = BZ2_bzDecompress(&strm);
            
            // If any error there, break the loop 
            if(nResult < BZ_OK)
                break;
        }

        // Put the stream into idle state
        BZ2_bzDecompressEnd(&strm);

        // If all succeeded, set the number of output bytes
        if(nResult >= BZ_OK)
        {
            *pcbOutBuffer = strm.total_out_lo32;
            return 1;
        }
    }

    // Something failed, so set number of output bytes to zero
    *pcbOutBuffer = 0;
    return 1;
}

/******************************************************************************/
/*                                                                            */
/*  Support functions for LZMA compression (0x12)                             */
/*                                                                            */
/******************************************************************************/

#define LZMA_HEADER_SIZE (1 + LZMA_PROPS_SIZE + 8)

static SRes LZMA_Callback_Progress(void * /* p */, UInt64 /* inSize */, UInt64 /* outSize */)
{
    return SZ_OK;
}

static void * LZMA_Callback_Alloc(void *p, size_t size)
{
    p = p;
    return STORM_ALLOC(BYTE, size);
}

/* address can be 0 */
static void LZMA_Callback_Free(void *p, void *address)
{
    p = p;
    if(address != NULL)
        STORM_FREE(address);
}

//
// Note: So far, I haven't seen any files compressed by LZMA.
// This code haven't been verified against code ripped from Starcraft II Beta,
// but we know that Starcraft LZMA decompression code is able to decompress
// the data compressed by StormLib.
//

static void Compress_LZMA(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * /* pCmpType */,
    int /* nCmpLevel */)
{
    ICompressProgress Progress;
    CLzmaEncProps props;
    ISzAlloc SzAlloc;
    Byte * destBuffer;
    SizeT destLen = *pcbOutBuffer;
    SizeT srcLen = cbInBuffer;
    Byte encodedProps[LZMA_PROPS_SIZE];
    size_t encodedPropsSize = LZMA_PROPS_SIZE;
    SRes nResult;

    // Fill the callbacks in structures
    Progress.Progress = LZMA_Callback_Progress;
    SzAlloc.Alloc = LZMA_Callback_Alloc;
    SzAlloc.Free = LZMA_Callback_Free;

    // Initialize properties
    LzmaEncProps_Init(&props);

    // Perform compression
    destBuffer = (Byte *)pbOutBuffer + LZMA_HEADER_SIZE;
    destLen = *pcbOutBuffer - LZMA_HEADER_SIZE;
    nResult = LzmaEncode(destBuffer,
                        &destLen,
                 (Byte *)pbInBuffer,
                         srcLen,
                        &props,
                         encodedProps,
                        &encodedPropsSize,
                         0,
                        &Progress,
                        &SzAlloc,
                        &SzAlloc);
    if(nResult != SZ_OK)
        return;

    // If we failed to compress the data
    if(destLen >= (SizeT)(*pcbOutBuffer - LZMA_HEADER_SIZE))
        return;

    // Write "useFilter" variable. Blizzard MPQ must not use filter.
    *pbOutBuffer++ = 0;

    // Copy the encoded properties to the output buffer
    memcpy(pbOutBuffer, encodedProps, encodedPropsSize);
    pbOutBuffer += encodedPropsSize;

    // Copy the size of the data
    *pbOutBuffer++ = (unsigned char)(srcLen >> 0x00);
    *pbOutBuffer++ = (unsigned char)(srcLen >> 0x08);
    *pbOutBuffer++ = (unsigned char)(srcLen >> 0x10);
    *pbOutBuffer++ = (unsigned char)(srcLen >> 0x18);
    *pbOutBuffer++ = 0;
    *pbOutBuffer++ = 0;
    *pbOutBuffer++ = 0;
    *pbOutBuffer++ = 0;

    // Give the size of the data to the caller
    *pcbOutBuffer = (unsigned int)(destLen + LZMA_HEADER_SIZE);
}

static int Decompress_LZMA(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    ELzmaStatus LzmaStatus;
    ISzAlloc SzAlloc;
    Byte * destBuffer = (Byte *)pbOutBuffer;
    Byte * srcBuffer = (Byte *)pbInBuffer;
    SizeT destLen = *pcbOutBuffer;
    SizeT srcLen = cbInBuffer;
    SRes nResult;

    // There must be at least 0x0E bytes in the buffer
    if(srcLen <= LZMA_HEADER_SIZE) 
        return 0;

    // We only accept blocks that have no filter used
    if(*srcBuffer != 0)
        return 0;

    // Fill the callbacks in structures
    SzAlloc.Alloc = LZMA_Callback_Alloc;
    SzAlloc.Free = LZMA_Callback_Free;

    // Perform compression
    srcLen = cbInBuffer - LZMA_HEADER_SIZE;
    nResult = LzmaDecode(destBuffer,
                        &destLen,
                         srcBuffer + LZMA_HEADER_SIZE,
                        &srcLen,
                         srcBuffer + 1, 
                         LZMA_PROPS_SIZE,
                         LZMA_FINISH_END,
                        &LzmaStatus,
                        &SzAlloc);
    if(nResult != SZ_OK)
        return 0;

    *pcbOutBuffer = (unsigned int)destLen;
    return 1;
}

/******************************************************************************/
/*                                                                            */
/*  Support functions for SPARSE compression (0x20)                           */
/*                                                                            */
/******************************************************************************/

void Compress_SPARSE(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * /* pCmpType */,
    int /* nCmpLevel */)
{
    CompressSparse((unsigned char *)pbOutBuffer, pcbOutBuffer, (unsigned char *)pbInBuffer, cbInBuffer);
}

int Decompress_SPARSE(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    return DecompressSparse((unsigned char *)pbOutBuffer, pcbOutBuffer, (unsigned char *)pbInBuffer, cbInBuffer);
}

/******************************************************************************/
/*                                                                            */
/*  Support for ADPCM mono compression (0x40)                                 */
/*                                                                            */
/******************************************************************************/

static void Compress_ADPCM_mono(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * pCmpType,
    int nCmpLevel)
{
    // Prepare the compression level for Huffmann compression,
    // which will be called as next step
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
    *pcbOutBuffer = CompressADPCM((unsigned char *)pbOutBuffer, *pcbOutBuffer, (short *)pbInBuffer, cbInBuffer, 1, nCmpLevel);
}

static int Decompress_ADPCM_mono(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    *pcbOutBuffer = DecompressADPCM((unsigned char *)pbOutBuffer, *pcbOutBuffer, (unsigned char *)pbInBuffer, cbInBuffer, 1);
    return 1;
}

/******************************************************************************/
/*                                                                            */
/*  Support for ADPCM stereo compression (0x80)                               */
/*                                                                            */
/******************************************************************************/

static void Compress_ADPCM_stereo(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    int * pCmpType,
    int nCmpLevel)
{
    // Prepare the compression level for Huffmann compression,
    // which will be called as next step
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
    *pcbOutBuffer = CompressADPCM((unsigned char *)pbOutBuffer, *pcbOutBuffer, (short *)pbInBuffer, cbInBuffer, 2, nCmpLevel);
}

static int Decompress_ADPCM_stereo(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    *pcbOutBuffer = DecompressADPCM((unsigned char *)pbOutBuffer, *pcbOutBuffer, (unsigned char *)pbInBuffer, cbInBuffer, 2);
    return 1;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompImplode                                                            */
/*                                                                           */
/*****************************************************************************/

int WINAPI SCompImplode(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    int cbOutBuffer = *pcbOutBuffer;

    // Check for valid parameters
    if(!pcbOutBuffer || *pcbOutBuffer < cbInBuffer || !pbOutBuffer || !pbInBuffer)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // Perform the compression
    Compress_PKLIB(pbOutBuffer, &cbOutBuffer, pbInBuffer, cbInBuffer, NULL, 0);

    // If the compression was unsuccessful, copy the data as-is
    if(cbOutBuffer >= *pcbOutBuffer)
    {
        memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
        cbOutBuffer = *pcbOutBuffer;
    }

    *pcbOutBuffer = cbOutBuffer;
    return 1;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompExplode                                                            */
/*                                                                           */
/*****************************************************************************/

int WINAPI SCompExplode(char * pbOutBuffer, int * pcbOutBuffer, char * pbInBuffer, int cbInBuffer)
{
    int cbOutBuffer = *pcbOutBuffer;

    // Check for valid parameters
    if(!pcbOutBuffer || *pcbOutBuffer < cbInBuffer || !pbOutBuffer || !pbInBuffer)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // If the input length is the same as output length, do nothing.
    if(cbInBuffer == cbOutBuffer)
    {
        // If the buffers are equal, don't copy anything.
        if(pbInBuffer == pbOutBuffer)
            return 1;

        memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
        return 1;
    }
    
    // Perform decompression
    if(!Decompress_PKLIB(pbOutBuffer, &cbOutBuffer, pbInBuffer, cbInBuffer))
    {
        SetLastError(ERROR_FILE_CORRUPT);
        return false;
    }

    *pcbOutBuffer = cbOutBuffer;
    return 1;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompCompress                                                           */
/*                                                                           */
/*****************************************************************************/

// This table contains compress functions which can be applied to
// uncompressed data. Each bit means the corresponding
// compression method/function must be applied.
//
//   WAVes compression            Data compression
//   ------------------           -------------------
//   1st sector   - 0x08          0x08 (D, HF, W2, SC, D2)
//   Next sectors - 0x81          0x02 (W3)

static TCompressTable cmp_table[] =
{
    {MPQ_COMPRESSION_SPARSE,      Compress_SPARSE},         // Sparse compression
    {MPQ_COMPRESSION_WAVE_MONO,   Compress_ADPCM_mono},     // IMA ADPCM mono compression
    {MPQ_COMPRESSION_WAVE_STEREO, Compress_ADPCM_stereo},   // IMA ADPCM stereo compression
    {MPQ_COMPRESSION_HUFFMANN,    Compress_huff},           // Huffmann compression
    {MPQ_COMPRESSION_ZLIB,        Compress_ZLIB},           // Compression with the "zlib" library
    {MPQ_COMPRESSION_PKWARE,      Compress_PKLIB},          // Compression with Pkware DCL
    {MPQ_COMPRESSION_BZIP2,       Compress_BZIP2}           // Compression Bzip2 library
};

int WINAPI SCompCompress(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer,
    unsigned uCompressionMask,
    int nCmpType,
    int nCmpLevel)
{
    COMPRESS CompressFuncArray[0x10];       // Array of compression functions, applied sequentially
    unsigned char CompressByte[0x10];       // CompressByte for each method in the CompressFuncArray array
    char * pbWorkBuffer = NULL;             // Temporary storage for decompressed data
    char * pbOutput = pbOutBuffer;          // Current output buffer
    char * pbInput = pbInBuffer;            // Current input buffer
    int nCompressCount = 0;
    int nCompressIndex = 0;
    int nAtLeastOneCompressionDone = 0;
    int cbOutBuffer = 0;
    int cbInLength = cbInBuffer;
    int nResult = 1;

    // Check for valid parameters
    if(!pcbOutBuffer || *pcbOutBuffer < cbInBuffer || !pbOutBuffer || !pbInBuffer)
    {
        SetLastError(ERROR_INVALID_PARAMETER);
        return 0;
    }

    // Zero input length brings zero output length
    if(cbInBuffer == 0)
    {
        *pcbOutBuffer = 0;
        return true;
    }

    // Setup the compression function array
    if(uCompressionMask == MPQ_COMPRESSION_LZMA)
    {
        CompressFuncArray[0] = Compress_LZMA;
        CompressByte[0] = (char)uCompressionMask;
        nCompressCount = 1;
    }
    else
    {
        // Fill the compressions array
        for(size_t i = 0; i < (sizeof(cmp_table) / sizeof(TCompressTable)); i++)
        {
            // If the mask agrees, insert the compression function to the array
            if(uCompressionMask & cmp_table[i].uMask)
            {
                CompressFuncArray[nCompressCount] = cmp_table[i].Compress;
                CompressByte[nCompressCount] = (unsigned char)cmp_table[i].uMask;
                uCompressionMask &= ~cmp_table[i].uMask;
                nCompressCount++;
            }
        }

        // If at least one of the compressions remaing unknown, return an error
        if(uCompressionMask != 0)
        {
            SetLastError(ERROR_NOT_SUPPORTED);
            return 0;
        }
    }

    // If there is at least one compression, do it
    if(nCompressCount > 0)
    {
        // If we need to do more than 1 compression, allocate intermediate buffer
        if(nCompressCount > 1)
        {
            pbWorkBuffer = STORM_ALLOC(char, *pcbOutBuffer);
            if(pbWorkBuffer == NULL)
            {
                SetLastError(ERROR_NOT_ENOUGH_MEMORY);
                return 0;
            }
        }

        // Get the current compression index
        nCompressIndex = nCompressCount - 1;

        // Perform all compressions in the array
        for(int i = 0; i < nCompressCount; i++)
        {
            // Choose the proper output buffer
            pbOutput = (nCompressIndex & 1) ? pbWorkBuffer : pbOutBuffer;
            nCompressIndex--;

            // Perform the (next) compression
            // Note that if the compression method is unable to compress the input data block
            // by at least 2 bytes, we consider it as failure and will use source data instead
            cbOutBuffer = *pcbOutBuffer - 1;
            CompressFuncArray[i](pbOutput + 1, &cbOutBuffer, pbInput, cbInLength, &nCmpType, nCmpLevel);

            // If the compression failed, we copy the input buffer as-is.
            // Note that there is one extra byte at the end of the intermediate buffer, so it should be OK
            if(cbOutBuffer > (cbInLength - 2))
            {
                memcpy(pbOutput + nAtLeastOneCompressionDone, pbInput, cbInLength);
                cbOutBuffer = cbInLength;
            }
            else
            {
                // Remember that we have done at least one compression
                nAtLeastOneCompressionDone = 1;
                uCompressionMask |= CompressByte[i];
            }

            // Now point input buffer to the output buffer
            pbInput = pbOutput + nAtLeastOneCompressionDone;
            cbInLength = cbOutBuffer;
        }

        // If at least one compression succeeded, put the compression
        // mask to the begin of the output buffer
        if(nAtLeastOneCompressionDone)
            *pbOutBuffer  = (char)uCompressionMask;
        *pcbOutBuffer = cbOutBuffer + nAtLeastOneCompressionDone;
    }
    else
    {
        memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
        *pcbOutBuffer = cbInBuffer;
    }

    // Cleanup and return
    if(pbWorkBuffer != NULL)
        STORM_FREE(pbWorkBuffer);
    return nResult;
}

/*****************************************************************************/
/*                                                                           */
/*   SCompDecompress                                                         */
/*                                                                           */
/*****************************************************************************/

// This table contains decompress functions which can be applied to
// uncompressed data. The compression mask is stored in the first byte
// of compressed data
static TDecompressTable dcmp_table[] =
{
    {MPQ_COMPRESSION_BZIP2,       Decompress_BZIP2},        // Decompression with Bzip2 library
    {MPQ_COMPRESSION_PKWARE,      Decompress_PKLIB},        // Decompression with Pkware Data Compression Library
    {MPQ_COMPRESSION_ZLIB,        Decompress_ZLIB},         // Decompression with the "zlib" library
    {MPQ_COMPRESSION_HUFFMANN,    Decompress_huff},         // Huffmann decompression
    {MPQ_COMPRESSION_WAVE_STEREO, Decompress_ADPCM_stereo}, // IMA ADPCM stereo decompression
    {MPQ_COMPRESSION_WAVE_MONO,   Decompress_ADPCM_mono},   // IMA ADPCM mono decompression
    {MPQ_COMPRESSION_SPARSE,      Decompress_SPARSE}        // Sparse decompression
};

int WINAPI SCompDecompress(
    char * pbOutBuffer,
    int * pcbOutBuffer,
    char * pbInBuffer,
    int cbInBuffer)
{
    DECOMPRESS DecompressFuncArray[0x10];   // Array of compression functions, applied sequentially
    char *   pbWorkBuffer = NULL;           // Temporary storage for decompressed data
    char *   pbOutput = pbOutBuffer;        // Where to store decompressed data
    char *   pbInput;                       // Where to store decompressed data
    unsigned uCompressionMask;              // Decompressions applied to the data
    int      cbOutBuffer = *pcbOutBuffer;   // Current size of the output buffer
    int      cbInLength;                    // Current size of the input buffer
    int      nCompressCount = 0;            // Number of compressions to be applied
    int      nCompressIndex = 0;
    int      nResult = 1;

    // Zero input data bring zero output data
    if(cbInBuffer == 0)
    {
        *pcbOutBuffer = 0;
        return 1;
    }

/*
    // If the input length is the same as output length, do nothing.
    // Unfortunately, some data in WoW-Cataclysm BETA MPQs are like that ....
    if(cbInBuffer == cbOutBuffer)
    {
        // If the buffers are equal, don't copy anything.
        if(pbInBuffer == pbOutBuffer)
            return 1;

        memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
        return 1;
    }
*/

    // Get applied compression types and decrement data length
    uCompressionMask = (unsigned char)*pbInBuffer++;              
    cbInBuffer--;

    // Get current compressed data and length of it
    pbInput = pbInBuffer;
    cbInLength = cbInBuffer;

    //
    // Beginning with Starcraft II, the decompression byte can no longer contain
    // any arbitrary combination types. Instead, it can be one of the few
    // pre-set values (0x02, 0x08, 0x10, 0x12, 0x20, 0x22, 0x30)
    // Note that Starcraft II no longer uses WAVE files, so compressions 0x41, 0x48, 0x81, 0x88
    // are no longer used.
    //

    // Special case: LZMA decompression (added in Starcraft II)
    if(uCompressionMask == MPQ_COMPRESSION_LZMA)
    {
        DecompressFuncArray[0] = Decompress_LZMA;
        nCompressCount = 1;
    }
    else
    {
        // Fill the compressions array
        for(size_t i = 0; i < (sizeof(dcmp_table) / sizeof(TDecompressTable)); i++)
        {
            // If the mask agrees, insert the compression function to the array
            if(uCompressionMask & dcmp_table[i].uMask)
            {
                DecompressFuncArray[nCompressCount] = dcmp_table[i].Decompress;
                uCompressionMask &= ~dcmp_table[i].uMask;
                nCompressCount++;
            }
        }

        // If at least one of the compressions remaing unknown, return an error
        if(uCompressionMask != 0)
        {
            SetLastError(ERROR_NOT_SUPPORTED);
            return 0;
        }
    }

    // If there is at least one decompression, do it
    if(nCompressCount > 0)
    {
        // If there is more than one compression, we have to allocate extra buffer
        if(nCompressCount > 1)
        {
            pbWorkBuffer = STORM_ALLOC(char, *pcbOutBuffer);
            if(pbWorkBuffer == NULL)
            {
                SetLastError(ERROR_NOT_ENOUGH_MEMORY);
                return 0;
            }
        }

        // Get the current compression index
        nCompressIndex = nCompressCount - 1;

        // Apply all decompressions
        for(int i = 0; i < nCompressCount; i++)
        {
            // Get the correct output buffer
            pbOutput = (nCompressIndex & 1) ? pbWorkBuffer : pbOutBuffer;
            nCompressIndex--;
            
            // Perform the (next) decompression
            cbOutBuffer = *pcbOutBuffer;
            nResult = DecompressFuncArray[i](pbOutput, &cbOutBuffer, pbInput, cbInLength);
            if(nResult == 0 || cbOutBuffer == 0)
            {
                SetLastError(ERROR_FILE_CORRUPT);
                nResult = 0;
                break;
            }

            // Switch buffers
            pbInput = pbOutput;
            cbInLength = cbOutBuffer;
        }

        // Put the length of the decompressed data to the output buffer
        *pcbOutBuffer = cbOutBuffer;
    }
    else
    {
        memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
        *pcbOutBuffer = cbInBuffer;
    }

    // Cleanup and return
    if(pbWorkBuffer != NULL)
        STORM_FREE(pbWorkBuffer);
    return nResult;
}
