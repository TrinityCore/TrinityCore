/*****************************************************************************/
/* implode.c                              Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Implode function of PKWARE Data Compression library                       */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 11.04.03  1.00  Lad  First version of implode.c                           */
/* 02.05.03  1.00  Lad  Stress test done                                     */
/* 22.04.10  1.01  Lad  Documented                                           */
/*****************************************************************************/

#include <assert.h>
#include <string.h>

#include "pklib.h"

#if ((1200 < _MSC_VER) && (_MSC_VER < 1400))
#pragma optimize("", off)               // Fucking Microsoft VS.NET 2003 compiler !!! (_MSC_VER=1310)
#endif

//-----------------------------------------------------------------------------
// Defines

#define MAX_REP_LENGTH 0x204            // The longest allowed repetition

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
// Macros

// Macro for calculating hash of the current byte pair.
// Note that most exact byte pair hash would be buffer[0] + buffer[1] << 0x08,
// but even this way gives nice indication of equal byte pairs, with significantly
// smaller size of the array that holds numbers of those hashes
#define BYTE_PAIR_HASH(buffer)   ((buffer[0] * 4) + (buffer[1] * 5))

//-----------------------------------------------------------------------------
// Local functions

// Builds the "hash_to_index" table and "pair_hash_offsets" table.
// Every element of "hash_to_index" will contain lowest index to the
// "pair_hash_offsets" table, effectively giving offset of the first
// occurence of the given PAIR_HASH in the input data.
static void SortBuffer(TCmpStruct * pWork, unsigned char * buffer_begin, unsigned char * buffer_end)
{
    unsigned short * phash_to_index;
    unsigned char  * buffer_ptr;
    unsigned short total_sum = 0;
    unsigned long byte_pair_hash;           // Hash value of the byte pair
    unsigned short byte_pair_offs;          // Offset of the byte pair, relative to "work_buff"

    // Zero the entire "phash_to_index" table
    memset(pWork->phash_to_index, 0, sizeof(pWork->phash_to_index));
    
    // Step 1: Count amount of each PAIR_HASH in the input buffer
    // The table will look like this:
    //  offs 0x000: Number of occurences of PAIR_HASH 0
    //  offs 0x001: Number of occurences of PAIR_HASH 1
    //  ...
    //  offs 0x8F7: Number of occurences of PAIR_HASH 0x8F7 (the highest hash value)
    for(buffer_ptr = buffer_begin; buffer_ptr < buffer_end; buffer_ptr++)
        pWork->phash_to_index[BYTE_PAIR_HASH(buffer_ptr)]++;

    // Step 2: Convert the table to the array of PAIR_HASH amounts. 
    // Each element contains count of PAIR_HASHes that is less or equal
    // to element index
    // The table will look like this:
    //  offs 0x000: Number of occurences of PAIR_HASH 0 or lower
    //  offs 0x001: Number of occurences of PAIR_HASH 1 or lower
    //  ...
    //  offs 0x8F7: Number of occurences of PAIR_HASH 0x8F7 or lower
    for(phash_to_index = pWork->phash_to_index; phash_to_index < &pWork->phash_to_index_end; phash_to_index++)
    {
        total_sum = total_sum + phash_to_index[0];
        phash_to_index[0] = total_sum;
    }

    // Step 3: Convert the table to the array of indexes.
    // Now, each element contains index to the first occurence of given PAIR_HASH
    for(buffer_end--; buffer_end >= buffer_begin; buffer_end--)
    {
        byte_pair_hash = BYTE_PAIR_HASH(buffer_end);
        byte_pair_offs = (unsigned short)(buffer_end - pWork->work_buff);

        pWork->phash_to_index[byte_pair_hash]--;
        pWork->phash_offs[pWork->phash_to_index[byte_pair_hash]] = byte_pair_offs;
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

    memset(pWork->out_buff, 0, sizeof(pWork->out_buff));

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

// This function searches for a repetition
// (a previous occurence of the current byte sequence)
// Returns length of the repetition, and stores the backward distance 
// to pWork structure.
static unsigned int FindRep(TCmpStruct * pWork, unsigned char * input_data)
{
    unsigned short * phash_to_index;            // Pointer into pWork->phash_to_index table
    unsigned short * phash_offs;                // Pointer to the table containing offsets of each PAIR_HASH
    unsigned char * repetition_limit;           // An eventual repetition must be at position below this pointer
    unsigned char * prev_repetition;            // Pointer to the previous occurence of the current PAIR_HASH
    unsigned char * prev_rep_end;               // End of the previous repetition
    unsigned char * input_data_ptr;
    unsigned short phash_offs_index;            // Index to the table with PAIR_HASH positions
    unsigned short min_phash_offs;              // The lowest allowed hash offset
    unsigned short offs_in_rep;                 // Offset within found repetition
    unsigned int equal_byte_count;              // Number of bytes that are equal to the previous occurence
    unsigned int rep_length = 1;                // Length of the found repetition
    unsigned int rep_length2;                   // Secondary repetition
    unsigned char pre_last_byte;                // Last but one byte from a repetion
    unsigned short di_val;

    // Calculate the previous position of the PAIR_HASH
    phash_to_index   = pWork->phash_to_index + BYTE_PAIR_HASH(input_data);
    min_phash_offs   = (unsigned short)((input_data - pWork->work_buff) - pWork->dsize_bytes + 1);
    phash_offs_index = phash_to_index[0];

    // If the PAIR_HASH offset is below the limit, find a next one
    phash_offs = pWork->phash_offs + phash_offs_index;
    if(*phash_offs < min_phash_offs)
    {
        while(*phash_offs < min_phash_offs)
        {
            phash_offs_index++;
            phash_offs++;
        }
        *phash_to_index = phash_offs_index;
    }

    // Get the first location of the PAIR_HASH,
    // and thus the first eventual location of byte repetition
    phash_offs = pWork->phash_offs + phash_offs_index;
    prev_repetition = pWork->work_buff + phash_offs[0];
    repetition_limit = input_data - 1;
    
    // If the current PAIR_HASH was not encountered before,
    // we haven't found a repetition.
    if(prev_repetition >= repetition_limit)
        return 0;

    // We have found a match of a PAIR_HASH. Now we have to make sure
    // that it is also a byte match, because PAIR_HASH is not unique.
    // We compare the bytes and count the length of the repetition
    input_data_ptr = input_data;
    for(;;)
    {
        // If the first byte of the repetition and the so-far-last byte
        // of the repetition are equal, we will compare the blocks.
        if(*input_data_ptr == *prev_repetition && input_data_ptr[rep_length-1] == prev_repetition[rep_length-1])
        {
            // Skip the current byte
            prev_repetition++;
            input_data_ptr++;
            equal_byte_count = 2;

            // Now count how many more bytes are equal
            while(equal_byte_count < MAX_REP_LENGTH)
            {
                prev_repetition++;
                input_data_ptr++;
                
                // Are the bytes different ?
                if(*prev_repetition != *input_data_ptr)
                    break;

                equal_byte_count++;
            }

            // If we found a repetition of at least the same length, take it.
            // If there are multiple repetitions in the input buffer, this will
            // make sure that we find the most recent one, which in turn allows
            // us to store backward length in less amount of bits
            input_data_ptr = input_data;
            if(equal_byte_count >= rep_length)
            {
                // Calculate the backward distance of the repetition.
                // Note that the distance is stored as decremented by 1
                pWork->distance = (unsigned int)(input_data - prev_repetition + equal_byte_count - 1);

                // Repetitions longer than 10 bytes will be stored in more bits,
                // so they need a bit different handling
                if((rep_length = equal_byte_count) > 10)
                    break;
            }
        }

        // Move forward in the table of PAIR_HASH repetitions.
        // There might be a more recent occurence of the same repetition.
        phash_offs_index++;
        phash_offs++;
        prev_repetition = pWork->work_buff + phash_offs[0];

        // If the next repetition is beyond the minimum allowed repetition, we are done.
        if(prev_repetition >= repetition_limit)
        {
            // A repetition must have at least 2 bytes, otherwise it's not worth it
            return (rep_length >= 2) ? rep_length : 0;
        }
    }

    // If the repetition has max length of 0x204 bytes, we can't go any fuhrter
    if(equal_byte_count == MAX_REP_LENGTH)
    {
        pWork->distance--;
        return equal_byte_count;
    }

    // Check for possibility of a repetition that occurs at more recent position
    phash_offs = pWork->phash_offs + phash_offs_index;
    if(pWork->work_buff + phash_offs[1] >= repetition_limit)
        return rep_length;

    //
    // The following part checks if there isn't a longer repetition at
    // a latter offset, that would lead to better compression.
    //
    // Example of data that can trigger this optimization:
    //
    //   "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEQQQQQQQQQQQQ"
    //   "XYZ"
    //   "EEEEEEEEEEEEEEEEQQQQQQQQQQQQ";
    //
    // Description of data in this buffer
    //   [0x00] Single byte "E"
    //   [0x01] Single byte "E"
    //   [0x02] Repeat 0x1E bytes from [0x00]
    //   [0x20] Single byte "X"
    //   [0x21] Single byte "Y"
    //   [0x22] Single byte "Z"
    //   [0x23] 17 possible previous repetitions of length at least 0x10 bytes:
    //          - Repetition of 0x10 bytes from [0x00] "EEEEEEEEEEEEEEEE"
    //          - Repetition of 0x10 bytes from [0x01] "EEEEEEEEEEEEEEEE"
    //          - Repetition of 0x10 bytes from [0x02] "EEEEEEEEEEEEEEEE"
    //          ...
    //          - Repetition of 0x10 bytes from [0x0F] "EEEEEEEEEEEEEEEE"
    //          - Repetition of 0x1C bytes from [0x10] "EEEEEEEEEEEEEEEEQQQQQQQQQQQQ"
    //          The last repetition is the best one.
    //

    pWork->offs09BC[0] = 0xFFFF;
    pWork->offs09BC[1] = 0x0000;
    di_val = 0;

    // Note: I failed to figure out what does the table "offs09BC" mean.
    // If anyone has an idea, let me know to zezula_at_volny_dot_cz
    for(offs_in_rep = 1; offs_in_rep < rep_length; )
    {
        if(input_data[offs_in_rep] != input_data[di_val])
        {
            di_val = pWork->offs09BC[di_val];
            if(di_val != 0xFFFF)
                continue;
        }
        pWork->offs09BC[++offs_in_rep] = ++di_val;
    }

    // 
    // Now go through all the repetitions from the first found one
    // to the current input data, and check if any of them migh be
    // a start of a greater sequence match.
    //

    prev_repetition = pWork->work_buff + phash_offs[0];
    prev_rep_end = prev_repetition + rep_length;
    rep_length2 = rep_length;
    
    for(;;)
    {
        rep_length2 = pWork->offs09BC[rep_length2];
        if(rep_length2 == 0xFFFF)
            rep_length2 = 0;

        // Get the pointer to the previous repetition
        phash_offs = pWork->phash_offs + phash_offs_index;

        // Skip those repetitions that don't reach the end
        // of the first found repetition
        do
        {
            phash_offs++;
            phash_offs_index++;
            prev_repetition = pWork->work_buff + *phash_offs;
            if(prev_repetition >= repetition_limit)
                return rep_length;
        }
        while(prev_repetition + rep_length2 < prev_rep_end);

        // Verify if the last but one byte from the repetition matches
        // the last but one byte from the input data.
        // If not, find a next repetition
        pre_last_byte = input_data[rep_length - 2];
        if(pre_last_byte == prev_repetition[rep_length - 2])
        {
            // If the new repetition reaches beyond the end
            // of previously found repetition, reset the repetition length to zero.
            if(prev_repetition + rep_length2 != prev_rep_end)
            {
                prev_rep_end = prev_repetition;
                rep_length2 = 0;
            }
        }
        else
        {
            phash_offs = pWork->phash_offs + phash_offs_index;
            do
            {
                phash_offs++;
                phash_offs_index++;
                prev_repetition = pWork->work_buff + *phash_offs;
                if(prev_repetition >= repetition_limit)
                    return rep_length;
            }
            while(prev_repetition[rep_length - 2] != pre_last_byte || prev_repetition[0] != input_data[0]);

            // Reset the length of the repetition to 2 bytes only
            prev_rep_end = prev_repetition + 2;
            rep_length2 = 2;
        }

        // Find out how many more characters are equal to the first repetition.
        while(*prev_rep_end == input_data[rep_length2])
        {
            if(++rep_length2 >= 0x204)
                break;
            prev_rep_end++;
        }

        // Is the newly found repetion at least as long as the previous one ?
        if(rep_length2 >= rep_length)
        {
            // Calculate the distance of the new repetition
            pWork->distance = (unsigned int)(input_data - prev_repetition - 1);
            if((rep_length = rep_length2) == 0x204)
                return rep_length;

            // Update the additional elements in the "offs09BC" table
            // to reflect new rep length
            while(offs_in_rep < rep_length2)
            {
                if(input_data[offs_in_rep] != input_data[di_val])
                {
                    di_val = pWork->offs09BC[di_val];
                    if(di_val != 0xFFFF)
                        continue;
                }
                pWork->offs09BC[++offs_in_rep] = ++di_val;
            }
        }
    }
}

static void WriteCmpData(TCmpStruct * pWork)
{
    unsigned char * input_data_end;         // Pointer to the end of the input data
    unsigned char * input_data = pWork->work_buff + pWork->dsize_bytes + 0x204;
    unsigned int input_data_ended = 0;      // If 1, then all data from the input stream have been already loaded
    unsigned int save_rep_length;           // Saved length of current repetition
    unsigned int save_distance = 0;         // Saved distance of current repetition
    unsigned int rep_length;                // Length of the found repetition
    unsigned int phase = 0;                 // 

    // Store the compression type and dictionary size
    pWork->out_buff[0] = (char)pWork->ctype;
    pWork->out_buff[1] = (char)pWork->dsize_bits;
    pWork->out_bytes = 2;

    // Reset output buffer to zero
    memset(&pWork->out_buff[2], 0, sizeof(pWork->out_buff) - 2);
    pWork->out_bits = 0;

    while(input_data_ended == 0)
    {
        unsigned int bytes_to_load = 0x1000;
        int total_loaded = 0;
        int bytes_loaded;

        // Load the bytes from the input stream, up to 0x1000 bytes
        while(bytes_to_load != 0)
        {
            bytes_loaded = pWork->read_buf((char *)pWork->work_buff + pWork->dsize_bytes + 0x204 + total_loaded,
                                                  &bytes_to_load,
                                                   pWork->param);
            if(bytes_loaded == 0)
            {
                if(total_loaded == 0 && phase == 0)
                    goto __Exit;
                input_data_ended = 1;
                break;
            }
            else
            {
                bytes_to_load -= bytes_loaded;
                total_loaded += bytes_loaded;
            }
        }

        input_data_end = pWork->work_buff + pWork->dsize_bytes + total_loaded;
        if(input_data_ended)
            input_data_end += 0x204;
        
        //
        // Warning: The end of the buffer passed to "SortBuffer" is actually 2 bytes beyond
        // valid data. It is questionable if this is actually a bug or not,
        // but it might cause the compressed data output to be dependent on random bytes
        // that are in the buffer. 
        // To prevent that, the calling application must always zero the compression
        // buffer before passing it to "implode"
        //

        // Search the PAIR_HASHes of the loaded blocks. Also, include
        // previously compressed data, if any.
        switch(phase)
        {
            case 0: 
                SortBuffer(pWork, input_data, input_data_end + 1);
                phase++;
                if(pWork->dsize_bytes != 0x1000)
                    phase++;
                break;

            case 1:
                SortBuffer(pWork, input_data - pWork->dsize_bytes + 0x204, input_data_end + 1);
                phase++;
                break;

            default:
                SortBuffer(pWork, input_data - pWork->dsize_bytes, input_data_end + 1);
                break;
        }

        // Perform the compression of the current block
        while(input_data < input_data_end)
        {
            // Find if the current byte sequence wasn't there before.
            rep_length = FindRep(pWork, input_data);
            while(rep_length != 0)
            {
                // If we found repetition of 2 bytes, that is 0x100 or fuhrter back,
                // don't bother. Storing the distance of 0x100 bytes would actually
                // take more space than storing the 2 bytes as-is.
                if(rep_length == 2 && pWork->distance >= 0x100)
                    break;

                // When we are at the end of the input data, we cannot allow
                // the repetition to go past the end of the input data.
                if(input_data_ended && input_data + rep_length > input_data_end)
                {
                    // Shorten the repetition length so that it only covers valid data
                    rep_length = (unsigned long)(input_data_end - input_data);
                    if(rep_length < 2)
                        break;

                    // If we got repetition of 2 bytes, that is 0x100 or more backward, don't bother
                    if(rep_length == 2 && pWork->distance >= 0x100)
                        break;
                    goto __FlushRepetition;
                }

                if(rep_length >= 8 || input_data + 1 >= input_data_end)
                    goto __FlushRepetition;

                // Try to find better repetition 1 byte later.
                // Example: "ARROCKFORT" "AROCKFORT"
                // When "input_data" points to the second string, FindRep
                // returns the occurence of "AR". But there is longer repetition "ROCKFORT",
                // beginning 1 byte after.
                save_rep_length = rep_length;
                save_distance = pWork->distance;
                rep_length = FindRep(pWork, input_data + 1);

                // Only use the new repetition if it's length is greater than the previous one
                if(rep_length > save_rep_length)
                {
                    // If the new repetition if only 1 byte better
                    // and the previous distance is less than 0x80 bytes, use the previous repetition
                    if(rep_length > save_rep_length + 1 || save_distance > 0x80)
                    {
                        // Flush one byte, so that input_data will point to the secondary repetition
                        OutputBits(pWork, pWork->nChBits[*input_data], pWork->nChCodes[*input_data]);
                        input_data++;
                        continue;
                    }
                }

                // Revert to the previous repetition
                rep_length = save_rep_length;
                pWork->distance = save_distance;

                __FlushRepetition:

                OutputBits(pWork, pWork->nChBits[rep_length + 0xFE], pWork->nChCodes[rep_length + 0xFE]);
                if(rep_length == 2)
                {
                    OutputBits(pWork, pWork->dist_bits[pWork->distance >> 2],
                                      pWork->dist_codes[pWork->distance >> 2]);
                    OutputBits(pWork, 2, pWork->distance & 3);
                }
                else
                {
                    OutputBits(pWork, pWork->dist_bits[pWork->distance >> pWork->dsize_bits],
                                      pWork->dist_codes[pWork->distance >> pWork->dsize_bits]);
                    OutputBits(pWork, pWork->dsize_bits, pWork->dsize_mask & pWork->distance);
                }

                // Move the begin of the input data by the length of the repetition
                input_data += rep_length;
                goto _00402252;
            }

            // If there was no previous repetition for the current position in the input data,
            // just output the 9-bit literal for the one character
            OutputBits(pWork, pWork->nChBits[*input_data], pWork->nChCodes[*input_data]);
            input_data++;
_00402252:;
        }

        if(input_data_ended == 0)
        {
            input_data -= 0x1000;
            memcpy(pWork->work_buff, pWork->work_buff + 0x1000, pWork->dsize_bytes + 0x204);
        }
    }

__Exit:

    // Write the termination literal
    OutputBits(pWork, pWork->nChBits[0x305], pWork->nChCodes[0x305]);
    if(pWork->out_bits != 0)
        pWork->out_bytes++;
    pWork->write_buf(pWork->out_buff, &pWork->out_bytes, pWork->param);
    return;
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
    int nCount2;

    // Fill the work buffer information
    // Note: The caller must zero the "work_buff" before passing it to implode
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
        case CMP_IMPLODE_DICT_SIZE3:    // 0x1000 bytes
            pWork->dsize_bits++;
            pWork->dsize_mask |= 0x20;
            // No break here !!!

        case CMP_IMPLODE_DICT_SIZE2:    // 0x800 bytes
            pWork->dsize_bits++;
            pWork->dsize_mask |= 0x10;
            // No break here !!!

        case CMP_IMPLODE_DICT_SIZE1:    // 0x400
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
        if(1 << ExLenBits[i])
        {
            for(nCount2 = 0; nCount2 < (1 << ExLenBits[i]); nCount2++)
            {
                pWork->nChBits[nCount]  = (unsigned char)(ExLenBits[i] + LenBits[i] + 1);
                pWork->nChCodes[nCount] = (unsigned short)((nCount2 << (LenBits[i] + 1)) | ((LenCode[i] & 0xFFFF00FF) * 2) | 1);
                nCount++;
            }
        }
    }

    // Copy the distance codes and distance bits and perform the compression
    memcpy(&pWork->dist_codes, DistCode, sizeof(DistCode));
    memcpy(&pWork->dist_bits, DistBits, sizeof(DistBits));
    WriteCmpData(pWork);
    return CMP_NO_ERROR;
}
