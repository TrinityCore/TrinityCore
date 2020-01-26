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
// Public functions

DWORD CascDecompress(LPBYTE pbOutBuffer, PDWORD pcbOutBuffer, LPBYTE pbInBuffer, DWORD cbInBuffer)
{
    z_stream z;                        // Stream information for zlib
    DWORD dwErrCode = ERROR_FILE_CORRUPT;
    uInt cbOutBuffer = *pcbOutBuffer;
    int nResult;

    // Fill the stream structure for zlib
    z.next_in   = pbInBuffer;
    z.avail_in  = cbInBuffer;
    z.total_in  = cbInBuffer;
    z.next_out  = pbOutBuffer;
    z.avail_out = cbOutBuffer;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    // Reset the total number of output bytes
    cbOutBuffer = 0;

    // Initialize the decompression structure
    if((nResult = inflateInit(&z)) == Z_OK)
    {
        // Call zlib to decompress the data
        nResult = inflate(&z, Z_NO_FLUSH);
        if (nResult == Z_OK || nResult == Z_STREAM_END)
        {
            // Give the size of the uncompressed data
            cbOutBuffer = z.total_out;
            dwErrCode = ERROR_SUCCESS;
        }

        inflateEnd(&z);
    }

    // Give the caller the number of bytes needed
    pcbOutBuffer[0] = cbOutBuffer;
    return dwErrCode;
}
