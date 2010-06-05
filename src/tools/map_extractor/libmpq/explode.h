/*
 *  explode.h -- header file for PKWARE data decompression library
 *               used by mpq-tools.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of pklib.h included
 *  in stormlib. The C++ version belongs to the following authors,
 *
 *  Ladislav Zezula <ladik.zezula.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _EXPLODE_H
#define _EXPLODE_H

#define LIBMPQ_PKZIP_EXP_BUFFER_SIZE    12596       /* Size of decompress buffer */
#define LIBMPQ_PKZIP_CMP_BINARY     0       /* Binary compression */
#define LIBMPQ_PKZIP_CMP_ASCII      1       /* Ascii compression */
#define LIBMPQ_PKZIP_CMP_NO_ERROR   0
#define LIBMPQ_PKZIP_CMP_INV_DICTSIZE   1
#define LIBMPQ_PKZIP_CMP_INV_MODE   2
#define LIBMPQ_PKZIP_CMP_BAD_DATA   3
#define LIBMPQ_PKZIP_CMP_ABORT      4

/* Compression structure (size: 12596 bytes on x86-32) */
typedef struct {
    unsigned long   offs0000;       /* 0000 */
    unsigned long   cmp_type;       /* 0004 - Compression type (LIBMPQ_PZIP_CMP_BINARY or LIBMPQ_PKZIP_CMP_ASCII) */
    unsigned long   out_pos;        /* 0008 - Position in output buffer */
    unsigned long   dsize_bits;     /* 000C - Dict size (4, 5, 6 for 0x400, 0x800, 0x1000) */
    unsigned long   dsize_mask;     /* 0010 - Dict size bitmask (0x0F, 0x1F, 0x3F for 0x400, 0x800, 0x1000) */
    unsigned long   bit_buf;        /* 0014 - 16-bit buffer for processing input data */
    unsigned long   extra_bits;     /* 0018 - Number of extra (above 8) bits in bit buffer */
    unsigned int    in_pos;         /* 001C - Position in in_buf */
    unsigned long   in_bytes;       /* 0020 - Number of bytes in input buffer */
    void        *param;         /* 0024 - Custom parameter */
    unsigned int    (*read_buf)(char *buf, unsigned  int *size, void *param);   /* 0028 */
    void        (*write_buf)(char *buf, unsigned  int *size, void *param);  /* 002C */
    unsigned char   out_buf[0x2000];    /* 0030 - Output circle buffer. Starting position is 0x1000 */
    unsigned char   offs_2030[0x204];   /* 2030 - ??? */
    unsigned char   in_buf[0x800];      /* 2234 - Buffer for data to be decompressed */
    unsigned char   pos1[0x100];        /* 2A34 - Positions in buffers */
    unsigned char   pos2[0x100];        /* 2B34 - Positions in buffers */
    unsigned char   offs_2c34[0x100];   /* 2C34 - Buffer for */
    unsigned char   offs_2d34[0x100];   /* 2D34 - Buffer for */
    unsigned char   offs_2e34[0x80];    /* 2EB4 - Buffer for */
    unsigned char   offs_2eb4[0x100];   /* 2EB4 - Buffer for */
    unsigned char   bits_asc[0x100];    /* 2FB4 - Buffer for */
    unsigned char   dist_bits[0x40];    /* 30B4 - Numbers of bytes to skip copied block length */
    unsigned char   slen_bits[0x10];    /* 30F4 - Numbers of bits for skip copied block length */
    unsigned char   clen_bits[0x10];    /* 3104 - Number of valid bits for copied block */
    unsigned short  len_base[0x10];     /* 3114 - Buffer for */
} pkzip_data_cmp;
// __attribute__ ((packed)) pkzip_data_cmp;

typedef struct {
    char        *in_buf;    /* Pointer to input data buffer */
    unsigned int    in_pos;     /* Current offset in input data buffer */
    int     in_bytes;   /* Number of bytes in the input buffer */
    char        *out_buf;   /* Pointer to output data buffer */
    unsigned int    out_pos;    /* Position in the output buffer */
    int     max_out;    /* Maximum number of bytes in the output buffer */
} pkzip_data;

extern unsigned int libmpq_pkzip_explode(
    unsigned int    (*read_buf)(char *buf, unsigned int *size, void *param),
    void        (*write_buf)(char *buf, unsigned int *size, void *param),
    char        *work_buf,
    void        *param
);

#endif                  /* _EXPLODE_H */

