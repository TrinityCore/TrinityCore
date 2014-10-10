/*****************************************************************************/
/* CascDecompress.cpp                     Copyright (c) Ladislav Zezula 2014 */
/*---------------------------------------------------------------------------*/
/* Decompression functions                                                   */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 02.05.14  1.00  Lad  The first version of CascDecompress.cpp              */
/*****************************************************************************/

#define __CASCLIB_SELF__
#include "CascLib.h"
#include "CascCommon.h"

//-----------------------------------------------------------------------------
// Local functions

static int Decompress_ZLIB(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer)
{
    z_stream z;                        // Stream information for zlib
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = pbInBuffer;
    z.avail_in  = cbInBuffer;
    z.total_in  = cbInBuffer;
    z.next_out  = pbOutBuffer;
    z.avail_out = *pcbOutBuffer;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Initialize the decompression structure
    if((nResult = inflateInit(&z)) == Z_OK)
    {
        // Call zlib to decompress the data
        nResult = inflate(&z, Z_NO_FLUSH);
        inflateEnd(&z);

        // Give the size of the uncompressed data
        *pcbOutBuffer = z.total_out;
    }
    
    // Return an error code
    return (nResult == Z_OK || nResult == Z_STREAM_END) ? ERROR_SUCCESS : ERROR_FILE_CORRUPT;
}

//-----------------------------------------------------------------------------
// Public functions

int CascDecompress(void * pvOutBuffer, PDWORD pcbOutBuffer, void * pvInBuffer, DWORD cbInBuffer)
{
    LPBYTE pbOutBuffer = (LPBYTE)pvOutBuffer;
    LPBYTE pbInBuffer = (LPBYTE)pvInBuffer;
    DWORD cbOutBuffer = *pcbOutBuffer;   // Current size of the output buffer
    BYTE uCompression;                  // Decompressions applied to the data

    // Verify buffer sizes
    if(cbInBuffer <= 1)
        return 0;

    // Get applied compression types and decrement data length
    uCompression = *pbInBuffer++;
    cbInBuffer--;

    // Perform the decompressions
    switch(uCompression)
    {
        case 'N':   // Uncompressed

            assert(cbOutBuffer == cbInBuffer);
            memcpy(pbOutBuffer, pbInBuffer, cbInBuffer);
            *pcbOutBuffer = cbOutBuffer;
            return ERROR_SUCCESS;

        case 'Z':   // ZLIB
            
            return Decompress_ZLIB(pbOutBuffer, pcbOutBuffer, pbInBuffer, cbInBuffer);
    }

    assert(false);
    return ERROR_NOT_SUPPORTED;
}
