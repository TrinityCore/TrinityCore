/*****************************************************************************/
/* implode.c                              Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Implode function of PKWARE Data Compression library                       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 11.04.03  1.00  Lad  First version of implode.c                           */
/* 02.05.03  1.00  Lad  Stress test done                                     */
/*****************************************************************************/

#include <assert.h>
#include <string.h>

#include "pklib.h"

#if ((1200 < _MSC_VER) && (_MSC_VER < 1400))
#pragma optimize("", off)               // Fucking Microsoft VS.NET 2003 compiler !!!
                                        // (_MSC_VER=1310)
#endif

//-----------------------------------------------------------------------------
// Defines

#define DICT_OFFSET   0x204
#define UNCMP_OFFSET  (pWork->dsize_bytes + DICT_OFFSET)

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

// Fills memory block with a character
static void lmemset(void * buff, int c, size_t count)
{
    memset(buff, c, count);
}

// Copies memory block to another location
static void lmemcpy(void * trg, const void * src, size_t count)
{
    memcpy(trg, src, count);
}

static void SortBuffer(TCmpStruct * pWork, unsigned char * uncmp_data, unsigned char * work_end)
{
    unsigned short * pin0DC8;
    unsigned char  * puncmp;
    unsigned long    offs1, offs2;
    unsigned long    ndwords;
    unsigned int     add;

    // Fill 0x480 dwords (0x1200 bytes)
    ndwords = (unsigned long)((pWork->out_buff - (char *)pWork->offs0DC8 + 1) >> 2);
    if(ndwords <= 1)
        ndwords = 1;
    memset(pWork->offs0DC8, 0, ndwords << 2);

    for(puncmp = uncmp_data; work_end > puncmp; puncmp++)
        pWork->offs0DC8[(puncmp[0] * 4) + (puncmp[1] * 5)]++;

    add = 0;
    for(pin0DC8 = pWork->offs0DC8; pin0DC8 < &pWork->offs1FC8; pin0DC8++)
    {
        add     += *pin0DC8;
        *pin0DC8 = (unsigned short)add;
    }

    for(work_end--; work_end >= uncmp_data; work_end--)
    {
        offs1 = (work_end[0] * 4) + (work_end[1] * 5);  // EAX
        offs2 = (unsigned long)(work_end - pWork->work_buff);          // EDI

        pWork->offs0DC8[offs1]--;
        pWork->offs49D0[pWork->offs0DC8[offs1]] = (unsigned short)offs2;
    }
}

static void FlushBuf(TCmpStruct * pWork)
{
    unsigned char save_ch1;
    unsigned char save_ch2;
    unsigned int size = 0x800;

    pWork->write_buf(pWork->out_buff, &size, pWork->param);

    save_ch1 = pWork->out_buff[0x800];
    save_ch2 = pWork->out_buff[pWork->out_bytes];
    pWork->out_bytes -= 0x800;

    lmemset(pWork->out_buff, 0, 0x802);

    if(pWork->out_bytes != 0)
        pWork->out_buff[0] = save_ch1;
    if(pWork->out_bits != 0)
        pWork->out_buff[pWork->out_bytes] = save_ch2;
}

static void OutputBits(TCmpStruct * pWork, unsigned int nbits, unsigned long bit_buff)
{
    unsigned int out_bits;

    // If more than 8 bits to output, do recursion
    if(nbits > 8)
    {
        OutputBits(pWork, 8, bit_buff);
        bit_buff >>= 8;
        nbits -= 8;
    }

    // Add bits to the last out byte in out_buff;
    out_bits = pWork->out_bits;
    pWork->out_buff[pWork->out_bytes] |= (unsigned char)(bit_buff << out_bits);
    pWork->out_bits += nbits;

    // If 8 or more bits, increment number of bytes
    if(pWork->out_bits > 8)
    {
        pWork->out_bytes++;
        bit_buff >>= (8 - out_bits);

        pWork->out_buff[pWork->out_bytes] = (unsigned char)bit_buff;
        pWork->out_bits &= 7;
    }
    else
    {
        pWork->out_bits &= 7;
        if(pWork->out_bits == 0)
            pWork->out_bytes++;
    }

    // If there is enough compressed bytes, flush them
    if(pWork->out_bytes >= 0x800)
        FlushBuf(pWork);
}

static unsigned long FindRep(TCmpStruct * pWork, unsigned char * srcbuff)
{
    unsigned short  esp12;
    unsigned char * esp14;
    unsigned short  esp18;
    unsigned char * srcbuff2;
    unsigned char   esp20;

    unsigned char  * srcbuff3;
    unsigned short * pin0DC8;
    unsigned char  * pin27CC;
    unsigned short * pin49D0;
    unsigned long    nreps = 1;         // EAX
    unsigned long    ebx, esi;
    unsigned short   di;

    pin0DC8 = pWork->offs0DC8 + (srcbuff[0] * 4) + (srcbuff[1] * 5);
    esi     = (unsigned long)(srcbuff - pWork->dsize_bytes - pWork->work_buff + 1);
    esp18   = *pin0DC8;
    pin49D0 = pWork->offs49D0 + esp18;

    if(*pin49D0 < esi)
    {
        while(*pin49D0 < esi)
        {
            pin49D0++;
            esp18++;
        }
        *pin0DC8 = esp18;
    }
//---------------------------------------------------------------------------
    srcbuff2 = srcbuff - 1;
    pin49D0  = pWork->offs49D0 + esp18;
    pin27CC  = pWork->work_buff + *pin49D0;
    if(srcbuff2 <= pin27CC)
        return 0;
//---------------------------------------------------------------------------
    srcbuff3 = srcbuff;
    for(;;)
    {
        if(srcbuff3[nreps-1] == pin27CC[nreps-1] && *srcbuff3 == *pin27CC)
        {
            //
            // The following code does not work when compiled with MSVC.NET 2003
            // optimizing compiler. We have to switch the optimizations off to make it work
            // I found that in debug version (where the optimizations are off), the value
            // of "pin27CC" gets incremented twice (once at below, once in the "for" loop)
            //

            pin27CC++;
            srcbuff3++;

            for(ebx = 2; ebx < DICT_OFFSET; ebx++)
            {
                pin27CC++;
                srcbuff3++;
                if(*pin27CC != *srcbuff3)
                    break;
            }

            srcbuff3 = srcbuff;
            if(ebx >= nreps)
            {
                pWork->offs0000 = (unsigned int)(srcbuff3 - pin27CC + ebx - 1);
                if((nreps = ebx) > 10)
                    break;
            }
        }

        pin49D0++;
        esp18++;
        pin27CC = pWork->work_buff + *pin49D0;

        if(srcbuff2 > pin27CC)
            continue;

        return (nreps >= 2) ? nreps : 0;
    }
//---------------------------------------------------------------------------
    if(ebx == DICT_OFFSET)
    {
        pWork->offs0000--;
        return ebx;
    }
//---------------------------------------------------------------------------
    pin49D0 = pWork->offs49D0 + esp18;
    if(pWork->work_buff + pin49D0[1] >= srcbuff2)
        return nreps;
//---------------------------------------------------------------------------
    di = 0;
    pWork->offs09BC[0] = 0xFFFF;
    pWork->offs09BC[1] = di;
    esp12 = 1;

    do
    {
        esi = di;
        if(srcbuff[esp12] != srcbuff[esi])
        {
            di = pWork->offs09BC[esi];
            if(di != 0xFFFF)
                continue;
        }
        pWork->offs09BC[++esp12] = ++di;
    }
    while(esp12 < nreps);
//---------------------------------------------------------------------------
    esi     = nreps;
    pin27CC = pWork->work_buff + pin49D0[0] + nreps;
    esp14   = pin27CC;

    for(;;)   // 0040268B
    {
        esi = pWork->offs09BC[esi];
        if(esi == 0xFFFF)
            esi = 0;

        pin49D0 = pWork->offs49D0 + esp18;
        do
        {
            pin49D0++;
            esp18++;
            pin27CC = pWork->work_buff + pin49D0[0];
            if(pin27CC >= srcbuff2)
                return nreps;
        }
        while(pin27CC + esi < esp14);
//---------------------------------------------------------------------------
        esp20 = srcbuff[nreps - 2];
        if(esp20 == pin27CC[nreps - 2])
        {
            if(pin27CC + esi != esp14)
            {
                esp14 = pin27CC;
                esi = 0;
            }
        }
        else
        {
            pin49D0 = pWork->offs49D0 + esp18;
            do
            {
                pin49D0++;
                esp18++;
                pin27CC = pWork->work_buff + pin49D0[0];
                if(pin27CC >= srcbuff2)
                    return nreps;
            }
            while(pin27CC[nreps - 2] != esp20 || pin27CC[0] != *srcbuff);

            esp14 = pin27CC + 2;
            esi   = 2;
        }
//---------------------------------------------------------------------------
        for(; esp14[0] == srcbuff[esi]; esp14++)
        {
            if(++esi >= DICT_OFFSET)
                break;
        }

        if(esi < nreps)
            continue;
        pWork->offs0000 = (unsigned int)(srcbuff - pin27CC - 1);
        if(esi <= nreps)
            continue;
        nreps = esi;
        if(esi == DICT_OFFSET)
            return nreps;

        do
        {
            if(srcbuff[esp12] != srcbuff[di])
            {
                di = pWork->offs09BC[di];
                if(di != 0xFFFF)
                    continue;
            }
            pWork->offs09BC[++esp12] = ++di;
        }
        while(esp12 < esi);
    }
}

static void WriteCmpData(TCmpStruct * pWork)
{
    unsigned int    nreps = 0;          // ESP+10 : Number of repeats
    unsigned char * uncmp_end;          // ESP+14 : End of uncompressed data
    unsigned int    esp18 = 0;          // ESP+18 :
    unsigned int    bytes_required;     // ESP+1C : Number of bytes required to read
    unsigned int    esp20 = 0;          // ESP+20 :
    unsigned char * uncmp_begin = pWork->work_buff + UNCMP_OFFSET; // EDI
    unsigned long   nreps1;
    unsigned long   save_offs0000 = 0;

    // Store the compression type and dictionary size
    pWork->out_buff[0] = (char)pWork->ctype;
    pWork->out_buff[1] = (char)pWork->dsize_bits;
    pWork->out_bytes = 2;

    // Reset output buffer to zero
    lmemset(&pWork->out_buff[2], 0, sizeof(pWork->out_buff) - 2);
    pWork->out_bits = 0;

    do
    {
        int total_loaded = 0;

        for(bytes_required = 0x1000; bytes_required != 0; )
        {
            int loaded = pWork->read_buf((char *)pWork->work_buff + UNCMP_OFFSET + total_loaded,
                       &bytes_required, pWork->param);

            if(loaded == 0)
            {
                if(total_loaded == 0 && esp20 == 0)
                    goto __Exit;
                esp18 = 1;
                break;
            }
            else
            {
                total_loaded += loaded;
                bytes_required -= loaded;
            }
        }

        uncmp_end = pWork->work_buff + pWork->dsize_bytes + total_loaded;
        if(esp18 != 0)
            uncmp_end += DICT_OFFSET;

        //
        // Warning: Passing "uncmp_end + 1" to the SortBuffer function may cause
        // the output to be unpredictable in Storm.dll's compression. Because Storm.dll
        // does not pass the zeroed buffer to the "implode" function, the byte after
        // uncmp_end contains random data. This causes difference within dictionary
        // created in SortBuffer function and may also cause different compressed output.
        // We always zero the data before compression, so this thing never occurs.
        // Funny is that it is actually not a bug, because if we decompress the data back,
        // we'll get the identical data with the original input.
        //
        switch(esp20)
        {
            case 0:
                SortBuffer(pWork, uncmp_begin, uncmp_end + 1);
                esp20++;
                if(pWork->dsize_bytes != 0x1000)
                    esp20++;
                break;

            case 1:
                SortBuffer(pWork, uncmp_begin - pWork->dsize_bytes + DICT_OFFSET, uncmp_end + 1);
                esp20++;
                break;

            default:
                SortBuffer(pWork, uncmp_begin - pWork->dsize_bytes, uncmp_end + 1);
                break;
        }

        while(uncmp_end > uncmp_begin)
        {
            nreps1 = FindRep(pWork, uncmp_begin);
            while(nreps1 != 0)
            {
                if(nreps1 == 2 && pWork->offs0000 >= 0x100)
                    break;

                if(esp18 != 0 && uncmp_begin + nreps1 > uncmp_end)
                    goto _004022DB;

                if(nreps1 >= 8 || uncmp_begin + 1 >= uncmp_end)
                    goto _004022FF;

                save_offs0000 = pWork->offs0000;    // ebp
                nreps  = nreps1;
                nreps1 = FindRep(pWork, uncmp_begin + 1);

                if(nreps >= nreps1)
                    goto _004022F9;

                if(nreps + 1 >= nreps1 && save_offs0000 <= 0x80)
                    goto _004022F9;

                OutputBits(pWork, pWork->nChBits[*uncmp_begin], pWork->nChCodes[*uncmp_begin]);
                uncmp_begin++;
            }

_0040222F:
            OutputBits(pWork, pWork->nChBits[*uncmp_begin], pWork->nChCodes[*uncmp_begin]);
            uncmp_begin++;
_00402252:;
        }

        if(esp18 == 0)
        {
            uncmp_begin -= 0x1000;
            lmemcpy(pWork->work_buff, pWork->work_buff + 0x1000, pWork->dsize_bytes + DICT_OFFSET);
        }
    }
    while(esp18 == 0);

__Exit:
    OutputBits(pWork, pWork->nChBits[0x305], pWork->nChCodes[0x305]);
    if(pWork->out_bits != 0)
        pWork->out_bytes++;
    pWork->write_buf(pWork->out_buff, &pWork->out_bytes, pWork->param);
    return;

_004022DB:
    nreps1 = (unsigned long)(uncmp_end - uncmp_begin);
    if(nreps1 < 2)
        goto _0040222F;

    if(nreps1 != 2 || pWork->offs0000 < 0x100)
        goto _004022FF;
    goto _0040222F;

_004022F9:
    nreps1 = nreps;
    pWork->offs0000 = save_offs0000;

_004022FF:
    OutputBits(pWork, pWork->nChBits[nreps1 + 0xFE], pWork->nChCodes[nreps1 + 0xFE]);

    if(nreps1 == 2)
    {
        OutputBits(pWork, pWork->dist_bits[pWork->offs0000 >> 2],
                          pWork->dist_codes[pWork->offs0000 >> 2]);
        OutputBits(pWork, 2, pWork->offs0000 & 3);
    }
    else
    {
        OutputBits(pWork, pWork->dist_bits[pWork->offs0000 >> pWork->dsize_bits],
                          pWork->dist_codes[pWork->offs0000 >> pWork->dsize_bits]);
        OutputBits(pWork, pWork->dsize_bits, pWork->dsize_mask & pWork->offs0000);
    }
    uncmp_begin += nreps1;
    goto _00402252;
}

//-----------------------------------------------------------------------------
// Main imploding function

unsigned int PKEXPORT implode(
    unsigned int (*read_buf)(char *buf, unsigned int *size, void *param),
    void         (*write_buf)(char *buf, unsigned int *size, void *param),
    char         *work_buf,
    void         *param,
    unsigned int *type,
    unsigned int *dsize)
{
    TCmpStruct * pWork = (TCmpStruct *)work_buf;
    unsigned int nChCode;
    unsigned int nCount;
    unsigned int i;

    // Initialize the work buffer. This is not in the Pklib,
    // but it seems to be a bug. Storm always pre-fills the data with zeros,
    // and always compresses one block only. So the bug will not appear.
    // But when a larger data block (size > 0x1000) is compressed,
    // it may fail.
    memset(pWork, 0, sizeof(TCmpStruct));

    // Fill the work buffer information
    pWork->read_buf    = read_buf;
    pWork->write_buf   = write_buf;
    pWork->dsize_bytes = *dsize;
    pWork->ctype       = *type;
    pWork->param       = param;
    pWork->dsize_bits  = 4;
    pWork->dsize_mask  = 0x0F;

    // Test dictionary size
    switch(*dsize)
    {
        case 0x1000 :
            pWork->dsize_bits++;
            pWork->dsize_mask |= 0x20;
            // No break here !!!

        case 0x0800 :
            pWork->dsize_bits++;
            pWork->dsize_mask |= 0x10;
            // No break here !!!

        case 0x0400 :
            break;

        default:
            return CMP_INVALID_DICTSIZE;
    }

    // Test the compression type
    switch(*type)
    {
        case CMP_BINARY: // We will compress data with binary compression type
            for(nChCode = 0, nCount = 0; nCount < 0x100; nCount++)
            {
                pWork->nChBits[nCount]  = 9;
                pWork->nChCodes[nCount] = (unsigned short)nChCode;
                nChCode = (nChCode & 0x0000FFFF) + 2;
            }
            break;


        case CMP_ASCII: // We will compress data with ASCII compression type
            for(nCount = 0; nCount < 0x100; nCount++)
            {
                pWork->nChBits[nCount]  = (unsigned char )(ChBitsAsc[nCount] + 1);
                pWork->nChCodes[nCount] = (unsigned short)(ChCodeAsc[nCount] * 2);
            }
            break;

        default:
            return CMP_INVALID_MODE;
    }

    for(i = 0; i < 0x10; i++)
    {
        int nCount2 = 0;    // EBX

        if((1 << ExLenBits[i]) == 0)
            continue;

        do
        {
            pWork->nChBits[nCount]  = (unsigned char)(ExLenBits[i] + LenBits[i] + 1);
            pWork->nChCodes[nCount] = (unsigned short)((nCount2 << (LenBits[i] + 1)) | ((LenCode[i] & 0xFFFF00FF) * 2) | 1);

            nCount2++;
            nCount++;
        }
        while((1 << ExLenBits[i]) > nCount2);
    }

    // Copy the distance codes and distance bits and perform the compression
    lmemcpy(&pWork->dist_codes, DistCode, sizeof(DistCode));
    lmemcpy(&pWork->dist_bits, DistBits, sizeof(DistBits));
    WriteCmpData(pWork);
    return CMP_NO_ERROR;
}
