/*****************************************************************************/
/* explode.c                              Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Implode function of PKWARE Data Compression library                       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 11.03.03  1.00  Lad  Splitted from Pkware.cpp                             */
/* 08.04.03  1.01  Lad  Renamed to explode.c to be compatible with pklib     */
/* 02.05.03  1.01  Lad  Stress test done                                     */
/*****************************************************************************/

#include <assert.h>
#include <string.h>

#include "pklib.h"

//-----------------------------------------------------------------------------
// Tables

static unsigned char DistBits[] =
{
    0x02, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

static unsigned char DistCode[] =
{
    0x03, 0x0D, 0x05, 0x19, 0x09, 0x11, 0x01, 0x3E, 0x1E, 0x2E, 0x0E, 0x36, 0x16, 0x26, 0x06, 0x3A,
    0x1A, 0x2A, 0x0A, 0x32, 0x12, 0x22, 0x42, 0x02, 0x7C, 0x3C, 0x5C, 0x1C, 0x6C, 0x2C, 0x4C, 0x0C,
    0x74, 0x34, 0x54, 0x14, 0x64, 0x24, 0x44, 0x04, 0x78, 0x38, 0x58, 0x18, 0x68, 0x28, 0x48, 0x08,
    0xF0, 0x70, 0xB0, 0x30, 0xD0, 0x50, 0x90, 0x10, 0xE0, 0x60, 0xA0, 0x20, 0xC0, 0x40, 0x80, 0x00
};

static unsigned char ExLenBits[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
};

static unsigned short LenBase[] =
{
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x000A, 0x000E, 0x0016, 0x0026, 0x0046, 0x0086, 0x0106
};

static unsigned char LenBits[] =
{
    0x03, 0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x07, 0x07
};

static unsigned char LenCode[] =
{
    0x05, 0x03, 0x01, 0x06, 0x0A, 0x02, 0x0C, 0x14, 0x04, 0x18, 0x08, 0x30, 0x10, 0x20, 0x40, 0x00
};

static unsigned char ChBitsAsc[] =
{
    0x0B, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x08, 0x07, 0x0C, 0x0C, 0x07, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0D, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x04, 0x0A, 0x08, 0x0C, 0x0A, 0x0C, 0x0A, 0x08, 0x07, 0x07, 0x08, 0x09, 0x07, 0x06, 0x07, 0x08,
    0x07, 0x06, 0x07, 0x07, 0x07, 0x07, 0x08, 0x07, 0x07, 0x08, 0x08, 0x0C, 0x0B, 0x07, 0x09, 0x0B,
    0x0C, 0x06, 0x07, 0x06, 0x06, 0x05, 0x07, 0x08, 0x08, 0x06, 0x0B, 0x09, 0x06, 0x07, 0x06, 0x06,
    0x07, 0x0B, 0x06, 0x06, 0x06, 0x07, 0x09, 0x08, 0x09, 0x09, 0x0B, 0x08, 0x0B, 0x09, 0x0C, 0x08,
    0x0C, 0x05, 0x06, 0x06, 0x06, 0x05, 0x06, 0x06, 0x06, 0x05, 0x0B, 0x07, 0x05, 0x06, 0x05, 0x05,
    0x06, 0x0A, 0x05, 0x05, 0x05, 0x05, 0x08, 0x07, 0x08, 0x08, 0x0A, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C,
    0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0C, 0x0D,
    0x0D, 0x0D, 0x0C, 0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D, 0x0D
};

static unsigned short ChCodeAsc[] =
{
    0x0490, 0x0FE0, 0x07E0, 0x0BE0, 0x03E0, 0x0DE0, 0x05E0, 0x09E0,
    0x01E0, 0x00B8, 0x0062, 0x0EE0, 0x06E0, 0x0022, 0x0AE0, 0x02E0,
    0x0CE0, 0x04E0, 0x08E0, 0x00E0, 0x0F60, 0x0760, 0x0B60, 0x0360,
    0x0D60, 0x0560, 0x1240, 0x0960, 0x0160, 0x0E60, 0x0660, 0x0A60,
    0x000F, 0x0250, 0x0038, 0x0260, 0x0050, 0x0C60, 0x0390, 0x00D8,
    0x0042, 0x0002, 0x0058, 0x01B0, 0x007C, 0x0029, 0x003C, 0x0098,
    0x005C, 0x0009, 0x001C, 0x006C, 0x002C, 0x004C, 0x0018, 0x000C,
    0x0074, 0x00E8, 0x0068, 0x0460, 0x0090, 0x0034, 0x00B0, 0x0710,
    0x0860, 0x0031, 0x0054, 0x0011, 0x0021, 0x0017, 0x0014, 0x00A8,
    0x0028, 0x0001, 0x0310, 0x0130, 0x003E, 0x0064, 0x001E, 0x002E,
    0x0024, 0x0510, 0x000E, 0x0036, 0x0016, 0x0044, 0x0030, 0x00C8,
    0x01D0, 0x00D0, 0x0110, 0x0048, 0x0610, 0x0150, 0x0060, 0x0088,
    0x0FA0, 0x0007, 0x0026, 0x0006, 0x003A, 0x001B, 0x001A, 0x002A,
    0x000A, 0x000B, 0x0210, 0x0004, 0x0013, 0x0032, 0x0003, 0x001D,
    0x0012, 0x0190, 0x000D, 0x0015, 0x0005, 0x0019, 0x0008, 0x0078,
    0x00F0, 0x0070, 0x0290, 0x0410, 0x0010, 0x07A0, 0x0BA0, 0x03A0,
    0x0240, 0x1C40, 0x0C40, 0x1440, 0x0440, 0x1840, 0x0840, 0x1040,
    0x0040, 0x1F80, 0x0F80, 0x1780, 0x0780, 0x1B80, 0x0B80, 0x1380,
    0x0380, 0x1D80, 0x0D80, 0x1580, 0x0580, 0x1980, 0x0980, 0x1180,
    0x0180, 0x1E80, 0x0E80, 0x1680, 0x0680, 0x1A80, 0x0A80, 0x1280,
    0x0280, 0x1C80, 0x0C80, 0x1480, 0x0480, 0x1880, 0x0880, 0x1080,
    0x0080, 0x1F00, 0x0F00, 0x1700, 0x0700, 0x1B00, 0x0B00, 0x1300,
    0x0DA0, 0x05A0, 0x09A0, 0x01A0, 0x0EA0, 0x06A0, 0x0AA0, 0x02A0,
    0x0CA0, 0x04A0, 0x08A0, 0x00A0, 0x0F20, 0x0720, 0x0B20, 0x0320,
    0x0D20, 0x0520, 0x0920, 0x0120, 0x0E20, 0x0620, 0x0A20, 0x0220,
    0x0C20, 0x0420, 0x0820, 0x0020, 0x0FC0, 0x07C0, 0x0BC0, 0x03C0,
    0x0DC0, 0x05C0, 0x09C0, 0x01C0, 0x0EC0, 0x06C0, 0x0AC0, 0x02C0,
    0x0CC0, 0x04C0, 0x08C0, 0x00C0, 0x0F40, 0x0740, 0x0B40, 0x0340,
    0x0300, 0x0D40, 0x1D00, 0x0D00, 0x1500, 0x0540, 0x0500, 0x1900,
    0x0900, 0x0940, 0x1100, 0x0100, 0x1E00, 0x0E00, 0x0140, 0x1600,
    0x0600, 0x1A00, 0x0E40, 0x0640, 0x0A40, 0x0A00, 0x1200, 0x0200,
    0x1C00, 0x0C00, 0x1400, 0x0400, 0x1800, 0x0800, 0x1000, 0x0000
};

//-----------------------------------------------------------------------------
// Local variables

static char Copyright[] = "PKWARE Data Compression Library for Win32\r\n"
                          "Copyright 1989-1995 PKWARE Inc.  All Rights Reserved\r\n"
                          "Patent No. 5,051,745\r\n"
                          "PKWARE Data Compression Library Reg. U.S. Pat. and Tm. Off.\r\n"
                          "Version 1.11\r\n";

//-----------------------------------------------------------------------------
// Local functions

// Copies a block to another location
static void lmemcpy(void * trg, const void * src, size_t count)
{
    memcpy(trg, src, count);
}

static void GenDecodeTabs(long count, unsigned char * bits, unsigned char * pCode, unsigned char * buffer2)
{
    long i;

    for(i = count-1; i >= 0; i--)             // EBX - count
    {
        unsigned long idx1 = pCode[i];
        unsigned long idx2 = 1 << bits[i];

        do
        {
            buffer2[idx1] = (unsigned char)i;
            idx1         += idx2;
        }
        while(idx1 < 0x100);
    }
}

static void GenAscTabs(TDcmpStruct * pWork)
{
    unsigned short * pChCodeAsc = &ChCodeAsc[0xFF];
    unsigned long  acc, add;
    unsigned short count;

    for(count = 0x00FF; pChCodeAsc >= ChCodeAsc; pChCodeAsc--, count--)
    {
        unsigned char * pChBitsAsc = pWork->ChBitsAsc + count;
        unsigned char bits_asc = *pChBitsAsc;

        if(bits_asc <= 8)
        {
            add = (1 << bits_asc);
            acc = *pChCodeAsc;

            do
            {
                pWork->offs2C34[acc] = (unsigned char)count;
                acc += add;
            }
            while(acc < 0x100);
        }
        else if((acc = (*pChCodeAsc & 0xFF)) != 0)
        {
            pWork->offs2C34[acc] = 0xFF;

            if(*pChCodeAsc & 0x3F)
            {
                bits_asc -= 4;
                *pChBitsAsc = bits_asc;

                add = (1 << bits_asc);
                acc = *pChCodeAsc >> 4;
                do
                {
                    pWork->offs2D34[acc] = (unsigned char)count;
                    acc += add;
                }
                while(acc < 0x100);
            }
            else
            {
                bits_asc -= 6;
                *pChBitsAsc = bits_asc;

                add = (1 << bits_asc);
                acc = *pChCodeAsc >> 6;
                do
                {
                    pWork->offs2E34[acc] = (unsigned char)count;
                    acc += add;
                }
                while(acc < 0x80);
            }
        }
        else
        {
            bits_asc -= 8;
            *pChBitsAsc = bits_asc;

            add = (1 << bits_asc);
            acc = *pChCodeAsc >> 8;
            do
            {
                pWork->offs2EB4[acc] = (unsigned char)count;
                acc += add;
            }
            while(acc < 0x100);
        }
    }
}

//-----------------------------------------------------------------------------
// Skips given number of bits in bit buffer. Result is stored in pWork->bit_buff
// If no data in input buffer, returns true

static int WasteBits(TDcmpStruct * pWork, unsigned long nBits)
{
    // If number of bits required is less than number of (bits in the buffer) ?
    if(nBits <= pWork->extra_bits)
    {
        pWork->extra_bits -= nBits;
        pWork->bit_buff  >>= nBits;
        return 0;
    }

    // Load input buffer if necessary
    pWork->bit_buff >>= pWork->extra_bits;
    if(pWork->in_pos == pWork->in_bytes)
    {
        pWork->in_pos = sizeof(pWork->in_buff);
        if((pWork->in_bytes = pWork->read_buf((char *)pWork->in_buff, &pWork->in_pos, pWork->param)) == 0)
            return 1;
        pWork->in_pos = 0;
    }

    // Update bit buffer
    pWork->bit_buff  |= (pWork->in_buff[pWork->in_pos++] << 8);
    pWork->bit_buff >>= (nBits - pWork->extra_bits);
    pWork->extra_bits    = (pWork->extra_bits - nBits) + 8;
    return 0;
}

//-----------------------------------------------------------------------------
// Returns : 0x000 - 0x0FF : One byte from compressed file.
//           0x100 - 0x305 : Copy previous block (0x100 = 1 byte)
//           0x306         : Out of buffer (?)

static unsigned long DecodeLit(TDcmpStruct * pWork)
{
    unsigned long nBits;                // Number of bits to skip
    unsigned long value;                // Position in buffers

    // Test the current bit in byte buffer. If is not set, simply return the next byte.
    if(pWork->bit_buff & 1)
    {
        // Skip current bit in the buffer
        if(WasteBits(pWork, 1))
            return 0x306;

        // The next bits are position in buffers
        value = pWork->position2[(pWork->bit_buff & 0xFF)];

        // Get number of bits to skip
        if(WasteBits(pWork, pWork->LenBits[value]))
            return 0x306;

        if((nBits = pWork->ExLenBits[value]) != 0)
        {
            unsigned long val2 = pWork->bit_buff & ((1 << nBits) - 1);

            if(WasteBits(pWork, nBits))
            {
                if((value + val2) != 0x10E)
                    return 0x306;
            }
            value = pWork->LenBase[value] + val2;
        }
        return value + 0x100;           // Return number of bytes to repeat
    }

    // Waste one bit
    if(WasteBits(pWork, 1))
        return 0x306;

    // If the binary compression type, read 8 bits and return them as one byte.
    if(pWork->ctype == CMP_BINARY)
    {
        value = pWork->bit_buff & 0xFF;
        if(WasteBits(pWork, 8))
            return 0x306;
        return value;
    }

    // When ASCII compression ...
    if(pWork->bit_buff & 0xFF)
    {
        value = pWork->offs2C34[pWork->bit_buff & 0xFF];

        if(value == 0xFF)
        {
            if(pWork->bit_buff & 0x3F)
            {
                if(WasteBits(pWork, 4))
                    return 0x306;

                value = pWork->offs2D34[pWork->bit_buff & 0xFF];
            }
            else
            {
                if(WasteBits(pWork, 6))
                    return 0x306;

                value = pWork->offs2E34[pWork->bit_buff & 0x7F];
            }
        }
    }
    else
    {
        if(WasteBits(pWork, 8))
            return 0x306;

        value = pWork->offs2EB4[pWork->bit_buff & 0xFF];
    }

    return WasteBits(pWork, pWork->ChBitsAsc[value]) ? 0x306 : value;
}

//-----------------------------------------------------------------------------
// Retrieves the number of bytes to move back

static unsigned long DecodeDist(TDcmpStruct * pWork, unsigned long dwLength)
{
    unsigned long pos   = pWork->position1[(pWork->bit_buff & 0xFF)];
    unsigned long nSkip = pWork->DistBits[pos];     // Number of bits to skip

    // Skip the appropriate number of bits
    if(WasteBits(pWork, nSkip) == 1)
        return 0;

    if(dwLength == 2)
    {
        pos = (pos << 2) | (pWork->bit_buff & 0x03);

        if(WasteBits(pWork, 2) == 1)
            return 0;
    }
    else
    {
        pos = (pos << pWork->dsize_bits) | (pWork->bit_buff & pWork->dsize_mask);

        // Skip the bits
        if(WasteBits(pWork, pWork->dsize_bits) == 1)
            return 0;
    }
    return pos+1;
}

static unsigned long Expand(TDcmpStruct * pWork)
{
    unsigned int  copyBytes;            // Number of bytes to copy
    unsigned long oneByte;              // One byte from compressed file
    unsigned long dwResult;

    pWork->outputPos = 0x1000;          // Initialize output buffer position

    // If end of data or error, terminate decompress
    while((dwResult = oneByte = DecodeLit(pWork)) < 0x305)
    {
        // If one byte is greater than 0x100, means "Repeat n - 0xFE bytes"
        if(oneByte >= 0x100)
        {
            unsigned char * source;          // ECX
            unsigned char * target;          // EDX
            unsigned long  copyLength = oneByte - 0xFE;
            unsigned long  moveBack;

            // Get length of data to copy
            if((moveBack = DecodeDist(pWork, copyLength)) == 0)
            {
                dwResult = 0x306;
                break;
            }

            // Target and source pointer
            target = &pWork->out_buff[pWork->outputPos];
            source = target - moveBack;
            pWork->outputPos += copyLength;

            while(copyLength-- > 0)
                *target++ = *source++;
        }
        else
            pWork->out_buff[pWork->outputPos++] = (unsigned char)oneByte;

        // If number of extracted bytes has reached 1/2 of output buffer,
        // flush output buffer.
        if(pWork->outputPos >= 0x2000)
        {
            // Copy decompressed data into user buffer
            copyBytes = 0x1000;
            pWork->write_buf((char *)&pWork->out_buff[0x1000], &copyBytes, pWork->param);

            // If there are some data left, keep them alive
            lmemcpy(pWork->out_buff, &pWork->out_buff[0x1000], pWork->outputPos - 0x1000);
            pWork->outputPos -= 0x1000;
        }
    }

    copyBytes = pWork->outputPos - 0x1000;
    pWork->write_buf((char *)&pWork->out_buff[0x1000], &copyBytes, pWork->param);
    return dwResult;
}


//-----------------------------------------------------------------------------
// Main exploding function.

unsigned int explode(
        unsigned int (*read_buf)(char *buf, unsigned  int *size, void *param),
        void         (*write_buf)(char *buf, unsigned  int *size, void *param),
        char         *work_buf,
        void         *param)
{
    TDcmpStruct * pWork = (TDcmpStruct *)work_buf;

    // Set the whole work buffer to zeros
    memset(pWork, 0, sizeof(TDcmpStruct));

    // Initialize work struct and load compressed data
    pWork->read_buf   = read_buf;
    pWork->write_buf  = write_buf;
    pWork->param      = param;
    pWork->in_pos     = sizeof(pWork->in_buff);
    pWork->in_bytes   = pWork->read_buf((char *)pWork->in_buff, &pWork->in_pos, pWork->param);
    if(pWork->in_bytes <= 4)
        return CMP_BAD_DATA;

    pWork->ctype      = pWork->in_buff[0]; // Get the compression type
    pWork->dsize_bits = pWork->in_buff[1]; // Get the dictionary size
    pWork->bit_buff   = pWork->in_buff[2]; // Initialize 16-bit bit buffer
    pWork->extra_bits = 0;                 // Extra (over 8) bits
    pWork->in_pos     = 3;                 // Position in input buffer

    // Test for the valid dictionary size
    if(4 > pWork->dsize_bits || pWork->dsize_bits > 6)
        return CMP_INVALID_DICTSIZE;

    pWork->dsize_mask = 0xFFFF >> (0x10 - pWork->dsize_bits); // Shifted by 'sar' instruction

    if(pWork->ctype != CMP_BINARY)
    {
        if(pWork->ctype != CMP_ASCII)
            return CMP_INVALID_MODE;

        lmemcpy(pWork->ChBitsAsc, ChBitsAsc, sizeof(pWork->ChBitsAsc));
        GenAscTabs(pWork);
    }

    lmemcpy(pWork->LenBits, LenBits, sizeof(pWork->LenBits));
    GenDecodeTabs(0x10, pWork->LenBits, LenCode, pWork->position2);
    lmemcpy(pWork->ExLenBits, ExLenBits, sizeof(pWork->ExLenBits));
    lmemcpy(pWork->LenBase, LenBase, sizeof(pWork->LenBase));
    lmemcpy(pWork->DistBits, DistBits, sizeof(pWork->DistBits));
    GenDecodeTabs(0x40, pWork->DistBits, DistCode, pWork->position1);
    if(Expand(pWork) != 0x306)
        return CMP_NO_ERROR;

    return CMP_ABORT;
}
