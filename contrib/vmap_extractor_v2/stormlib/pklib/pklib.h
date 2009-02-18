/*****************************************************************************/
/* pklib.h                                Copyright (c) Ladislav Zezula 2003 */
/*---------------------------------------------------------------------------*/
/* Header file for PKWARE Data Compression Library                           */
/*---------------------------------------------------------------------------*/
/*   Date    Ver   Who  Comment                                              */
/* --------  ----  ---  -------                                              */
/* 31.03.03  1.00  Lad  The first version of pkware.h                        */
/*****************************************************************************/

#ifndef __PKLIB_H__
#define __PKLIB_H__

#include "../StormPort.h"

//-----------------------------------------------------------------------------
// Defines

#define CMP_BINARY             0        // Binary compression
#define CMP_ASCII              1        // Ascii compression

#define CMP_NO_ERROR           0
#define CMP_INVALID_DICTSIZE   1
#define CMP_INVALID_MODE       2
#define CMP_BAD_DATA           3
#define CMP_ABORT              4

//-----------------------------------------------------------------------------
// Define calling convention

#ifndef PKEXPORT
#define PKEXPORT  //__cdecl               // Use for normal __cdecl calling
#endif
//#define PKEXPORT  __stdcall
//#define PKEXPORT  __fastcall

//-----------------------------------------------------------------------------
// Internal structures

// Compression structure
typedef struct
{
    unsigned int   offs0000;            // 0000 :
    unsigned int   out_bytes;           // 0004 : # bytes available in out_buff
    unsigned int   out_bits;            // 0008 : # of bits available in the last out byte
    unsigned int   dsize_bits;          // 000C : Dict size : 4=0x400, 5=0x800, 6=0x1000
    unsigned int   dsize_mask;          // 0010 : Dict size : 0x0F=0x400, 0x1F=0x800, 0x3F=0x1000
    unsigned int   ctype;               // 0014 : Compression type (Ascii or binary)
    unsigned int   dsize_bytes;         // 0018 : Dictionary size in bytes
    unsigned char  dist_bits[0x40];     // 001C : Distance bits
    unsigned char  dist_codes[0x40];    // 005C : Distance codes
    unsigned char  nChBits[0x306];      // 009C :
    unsigned short nChCodes[0x306];     // 03A2 :
    unsigned short offs09AE;            // 09AE :

    void         * param;               // 09B0 : User parameter
    unsigned int (*read_buf)(char *buf, unsigned int *size, void *param);  // 9B4
    void         (*write_buf)(char *buf, unsigned int *size, void *param); // 9B8

    unsigned short offs09BC[0x204];     // 09BC :
    unsigned long  offs0DC4;            // 0DC4 :
    unsigned short offs0DC8[0x900];     // 0DC8 :
    unsigned short offs1FC8;            // 1FC8 :
    char           out_buff[0x802];     // 1FCA : Output (compressed) data
    unsigned char  work_buff[0x2204];   // 27CC : Work buffer
                                        //  + DICT_OFFSET  => Dictionary
                                        //  + UNCMP_OFFSET => Uncompressed data
    unsigned short offs49D0[0x2000];    // 49D0 :
} TCmpStruct;

#define CMP_BUFFER_SIZE  sizeof(TCmpStruct) // Size of compression buffer


// Decompression structure
typedef struct
{
    unsigned long offs0000;             // 0000
    unsigned long ctype;                // 0004 - Compression type (CMP_BINARY or CMP_ASCII)
    unsigned long outputPos;            // 0008 - Position in output buffer
    unsigned long dsize_bits;           // 000C - Dict size (4, 5, 6 for 0x400, 0x800, 0x1000)
    unsigned long dsize_mask;           // 0010 - Dict size bitmask (0x0F, 0x1F, 0x3F for 0x400, 0x800, 0x1000)
    unsigned long bit_buff;             // 0014 - 16-bit buffer for processing input data
    unsigned long extra_bits;           // 0018 - Number of extra (above 8) bits in bit buffer
    unsigned int  in_pos;               // 001C - Position in in_buff
    unsigned long in_bytes;             // 0020 - Number of bytes in input buffer
    void        * param;                // 0024 - Custom parameter
    unsigned int (*read_buf)(char *buf, unsigned  int *size, void *param); // 0028
    void         (*write_buf)(char *buf, unsigned  int *size, void *param);// 002C
    unsigned char out_buff[0x2000];     // 0030 - Output circle buffer. Starting position is 0x1000
    unsigned char offs2030[0x204];      // 2030 - ???
    unsigned char in_buff[0x800];       // 2234 - Buffer for data to be decompressed
    unsigned char position1[0x100];     // 2A34 - Positions in buffers
    unsigned char position2[0x100];     // 2B34 - Positions in buffers
    unsigned char offs2C34[0x100];      // 2C34 - Buffer for
    unsigned char offs2D34[0x100];      // 2D34 - Buffer for
    unsigned char offs2E34[0x80];       // 2EB4 - Buffer for
    unsigned char offs2EB4[0x100];      // 2EB4 - Buffer for
    unsigned char ChBitsAsc[0x100];     // 2FB4 - Buffer for
    unsigned char DistBits[0x40];       // 30B4 - Numbers of bytes to skip copied block length
    unsigned char LenBits[0x10];        // 30F4 - Numbers of bits for skip copied block length
    unsigned char ExLenBits[0x10];      // 3104 - Number of valid bits for copied block
    unsigned short LenBase[0x10];       // 3114 - Buffer for
} TDcmpStruct;

#define EXP_BUFFER_SIZE    sizeof(TDcmpStruct)  // Size of decompress buffer

//-----------------------------------------------------------------------------
// Public functions

#ifdef __cplusplus
   extern "C" {
#endif

unsigned int PKEXPORT implode(
   unsigned int (*read_buf)(char *buf, unsigned int *size, void *param),
   void         (*write_buf)(char *buf, unsigned int *size, void *param),
   char         *work_buf,
   void         *param,
   unsigned int *type,
   unsigned int *dsize);


unsigned int PKEXPORT explode(
   unsigned int (*read_buf)(char *buf, unsigned  int *size, void *param),
   void         (*write_buf)(char *buf, unsigned  int *size, void *param),
   char         *work_buf,
   void         *param);

// The original name "crc32" was changed to "crc32pk" due
// to compatibility with zlib
unsigned long PKEXPORT crc32pk(char *buffer, unsigned int *size, unsigned long *old_crc);

#ifdef __cplusplus
   }                         // End of 'extern "C"' declaration
#endif

#endif // __PKLIB_H__

