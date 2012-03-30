/*
 *  huffman.h -- structures used for huffman compression.
 *
 *  Copyright (c) 2003-2008 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of huffman.h included
 *  in stormlib. The C++ version belongs to the following authors:
 *
 *  Ladislav Zezula <ladik@zezula.net>
 *  ShadowFlare <BlakFlare@hotmail.com>
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

#ifndef _HUFFMAN_H
#define _HUFFMAN_H

/* define huffman compression and decompression values. */
#define LIBMPQ_HUFF_DECOMPRESS			0		/* we want to decompress using huffman trees. */

/* define pointer conversions. */
#define PTR_NOT(ptr)				(struct huffman_tree_item_s *)(~(unsigned long)(ptr))
#define PTR_PTR(ptr)				((struct huffman_tree_item_s *)(ptr))
#define PTR_INT(ptr)				(long)(ptr)

/* define item handling. */
#define INSERT_ITEM				1		/* insert item into huffman tree. */
#define SWITCH_ITEMS				2		/* switch items isnide huffman tree. */

/* input stream for huffman decompression. */
struct huffman_input_stream_s {
	uint8_t		*in_buf;				/* 00 - input data. */
	uint32_t	bit_buf;				/* 04 - input bit buffer. */
	uint32_t	bits;					/* 08 - number of bits remaining in byte. */
};

/* huffman tree item. */
struct huffman_tree_item_s {
	struct		huffman_tree_item_s *next;		/* 00 - pointer to next huffman tree item. */
	struct		huffman_tree_item_s *prev;		/* 04 - pointer to prev huffman tree item (< 0 if none). */
	uint32_t	dcmp_byte;				/* 08 - index of this item in item pointer array, decompressed byte value. */
	uint32_t	byte_value;				/* 0C - some byte value. */
	struct		huffman_tree_item_s *parent;		/* 10 - pointer to parent huffman tree item (NULL if none). */
	struct		huffman_tree_item_s *child;		/* 14 - pointer to child huffman tree item. */
};

/* structure used for quick decompression. */
struct huffman_decompress_s {
	uint32_t	offs00;					/* 00 - 1 if resolved. */
	uint32_t	bits;					/* 04 - bit count. */
	union {
		uint32_t	dcmp_byte;			/* 08 - byte value for decompress (if bitCount <= 7). */
		struct		huffman_tree_item_s *p_item;	/* 08 - huffman tree item (if number of bits is greater than 7). */
	};
};

/* structure for huffman tree. */
struct huffman_tree_s {
	uint32_t	cmp0;					/* 0000 - 1 if compression type 0. */
	uint32_t	offs0004;				/* 0004 - some flag. */
	struct		huffman_tree_item_s items0008[0x203];	/* 0008 - huffman tree items. */
	struct		huffman_tree_item_s *item3050;		/* 3050 - always NULL? */
	struct		huffman_tree_item_s *item3054;		/* 3054 - pointer to huffman tree item. */
	struct		huffman_tree_item_s *item3058;		/* 3058 - pointer to huffman tree item (< 0 if invalid). */
	struct		huffman_tree_item_s *item305C;		/* 305C - usually NULL. */
	struct		huffman_tree_item_s *first;		/* 3060 - pointer to top (first) huffman tree item. */
	struct		huffman_tree_item_s *last;		/* 3064 - pointer to bottom (last) huffman tree item (< 0 if invalid). */
	uint32_t	items;					/* 3068 - number of used huffman tree items. */
	struct		huffman_tree_item_s *items306C[0x102];	/* 306C - huffman tree item pointer array. */
	struct		huffman_decompress_s qd3474[0x80];	/* 3474 - array for quick decompression. */
	uint8_t		table_1502A630[];			/* some table to make struct size flexible. */
};

/* insert a new item into huffman tree. */
void libmpq__huffman_insert_item(
	struct		huffman_tree_item_s **p_item,
	struct		huffman_tree_item_s *item,
	uint32_t	where,
	struct		huffman_tree_item_s *item2
);

/* remove item from huffman tree. */
void libmpq__huffman_remove_item(
	struct		huffman_tree_item_s *hi
);

/* get previous item from huffman tree. */
struct huffman_tree_item_s *libmpq__huffman_previous_item(
	struct		huffman_tree_item_s *hi,
	long		value
);

/* get one bit from stream. */
uint32_t libmpq__huffman_get_1bit(
	struct		huffman_input_stream_s *is
);

/* get seven bit from stream. */
uint32_t libmpq__huffman_get_7bit(
	struct		huffman_input_stream_s *is
);

/* get eight bit from stream. */
uint32_t libmpq__huffman_get_8bit(
	struct		huffman_input_stream_s *is
);

/* call 1500E740. */
struct huffman_tree_item_s *libmpq__huffman_call_1500E740(
	struct		huffman_tree_s *ht
);

/* call 1500E820- */
void libmpq__huffman_call_1500E820(
	struct		huffman_tree_s *ht,
	struct		huffman_tree_item_s *p_item
);

/* initialize the huffman tree. */
void libmpq__huffman_tree_init(
	struct		huffman_tree_s *ht,
	uint32_t	cmp
);

/* build the huffman tree. */
void libmpq__huffman_tree_build(
	struct		huffman_tree_s *ht,
	uint32_t	cmp_type
);

/* decompress the stream using huffman compression. */
int32_t libmpq__do_decompress_huffman(
	struct		huffman_tree_s *ht,
	struct		huffman_input_stream_s *is,
	uint8_t		*out_buf,
	uint32_t	out_length
);

#endif						/* _HUFFMAN_H */