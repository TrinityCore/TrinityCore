/*
 *  explode.h -- header file for pkware data decompression library
 *               used by mpq-tools.
 *
 *  Copyright (c) 2003-2008 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of pklib.h included
 *  in stormlib. The C++ version belongs to the following authors:
 *
 *  Ladislav Zezula <ladik@zezula.net>
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

/* define compression constants and return values. */
#define LIBMPQ_PKZIP_CMP_BINARY			0		/* binary compression. */
#define LIBMPQ_PKZIP_CMP_ASCII			1		/* ascii compression. */
#define LIBMPQ_PKZIP_CMP_NO_ERROR		0
#define LIBMPQ_PKZIP_CMP_INV_DICTSIZE		1
#define LIBMPQ_PKZIP_CMP_INV_MODE		2
#define LIBMPQ_PKZIP_CMP_BAD_DATA		3
#define LIBMPQ_PKZIP_CMP_ABORT			4

#ifdef _MSC_VER
#pragma pack(push,1)
#endif

/* compression structure. */
typedef struct {
	uint32_t	offs0000;		/* 0000 - start. */
	uint32_t	cmp_type;		/* 0004 - compression type (binary or ascii). */
	uint32_t	out_pos;		/* 0008 - position in output buffer. */
	uint32_t	dsize_bits;		/* 000C - dict size (4, 5, 6 for 0x400, 0x800, 0x1000). */
	uint32_t	dsize_mask;		/* 0010 - dict size bitmask (0x0F, 0x1F, 0x3F for 0x400, 0x800, 0x1000). */
	uint32_t	bit_buf;		/* 0014 - 16-bit buffer for processing input data. */
	uint32_t	extra_bits;		/* 0018 - number of extra (above 8) bits in bit buffer. */
	uint32_t	in_pos;			/* 001C - position in in_buf. */
	uint32_t	in_bytes;		/* 0020 - number of bytes in input buffer. */
	void		*param;			/* 0024 - custom parameter. */
	uint32_t	(*read_buf)(char *buf, uint32_t *size, void *param);	/* 0028 offset.*/
	void		(*write_buf)(char *buf, uint32_t *size, void *param);	/* 002C offset. */
	uint8_t		out_buf[0x2000];	/* 0030 - output circle buffer, starting position is 0x1000. */
	uint8_t		offs_2030[0x204];	/* 2030 - whats that? */
	uint8_t		in_buf[0x800];		/* 2234 - buffer for data to be decompressed. */
	uint8_t		pos1[0x100];		/* 2A34 - positions in buffers. */
	uint8_t		pos2[0x100];		/* 2B34 - positions in buffers. */
	uint8_t		offs_2c34[0x100];	/* 2C34 - buffer. */
	uint8_t		offs_2d34[0x100];	/* 2D34 - buffer. */
	uint8_t		offs_2e34[0x80];	/* 2EB4 - buffer. */
	uint8_t		offs_2eb4[0x100];	/* 2EB4 - buffer. */
	uint8_t		bits_asc[0x100];	/* 2FB4 - buffer. */
	uint8_t		dist_bits[0x40];	/* 30B4 - numbers of bytes to skip copied block length. */
	uint8_t		slen_bits[0x10];	/* 30F4 - numbers of bits for skip copied block length. */
	uint8_t		clen_bits[0x10];	/* 3104 - number of valid bits for copied block. */
	uint16_t	len_base[0x10];		/* 3114 - buffer. */
#ifdef _MSC_VER
} pkzip_cmp_s;
#pragma pack(pop)
#else
} __attribute__ ((packed)) pkzip_cmp_s;
#endif

/* data structure. */
typedef struct {
	uint8_t		*in_buf;		/* pointer to input data buffer. */
	uint32_t	in_pos;			/* current offset in input data buffer. */
	int32_t		in_bytes;		/* number of bytes in the input buffer. */
	uint8_t		*out_buf;		/* pointer to output data buffer. */
	uint32_t	out_pos;		/* position in the output buffer. */
	int32_t		max_out;		/* maximum number of bytes in the output buffer. */
} pkzip_data_s;

/* decompress the stream using pkzip compression. */
uint32_t libmpq__do_decompress_pkzip(
	uint8_t		*work_buf,
	void		*param
);

#endif						/* _EXPLODE_H */
