/*
 *  huffman.h -- structures used for huffman compression.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of huffman.h included
 *  in stormlib. The C++ version belongs to the following authors,
 *
 *  Ladislav Zezula <ladik.zezula.net>
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

#define PTR_NOT(ptr)    (struct huffman_tree_item *)(~(unsigned long)(ptr))
#define PTR_PTR(ptr)    ((struct huffman_tree_item *)(ptr))
#define PTR_INT(ptr)    (long)(ptr)

#define INSERT_ITEM 1
#define SWITCH_ITEMS    2               /* Switch the item1 and item2 */

/*
 *  Input stream for Huffmann decompression
 */
struct huffman_input_stream {
    unsigned char *in_buf;              /* 00 - Input data */
    unsigned long bit_buf;              /* 04 - Input bit buffer */
    unsigned int bits;              /* 08 - Number of bits remaining in 'byte' */
};

/*
 *  Huffmann tree item.
 */
struct huffman_tree_item {
    struct huffman_tree_item *next;         /* 00 - Pointer to next huffman_tree_item */
    struct huffman_tree_item *prev;         /* 04 - Pointer to prev huffman_tree_item (< 0 if none) */
    unsigned long dcmp_byte;            /* 08 - Index of this item in item pointer array, decompressed byte value */
    unsigned long byte_value;           /* 0C - Some byte value */
    struct huffman_tree_item *parent;       /* 10 - Pointer to parent huffman_tree_item (NULL if none) */
    struct huffman_tree_item *child;        /* 14 - Pointer to child huffman_tree_item */
};

/*
 *  Structure used for quick decompress. The 'bits' contains
 *  number of bits and dcmp_byte contains result decompressed byte
 *  value. After each walk through Huffman tree are filled all entries
 *  which are multiplies of number of bits loaded from input stream.
 *  These entries contain number of bits and result value. At the next
 *  7 bits is tested this structure first. If corresponding entry found,
 *  decompression routine will not walk through Huffman tree and
 *  directly stores output byte to output stream.
 */
struct huffman_decompress {
    unsigned long offs00;               /* 00 - 1 if resolved */
    unsigned long bits;             /* 04 - Bit count */
    union {
        unsigned long dcmp_byte;        /* 08 - Byte value for decompress (if bitCount <= 7) */
        struct huffman_tree_item *p_item;   /* 08 - THTreeItem (if number of bits is greater than 7 */
    };
};

/*
 *  Structure for Huffman tree.
 */
struct huffman_tree {
    unsigned long cmp0;             /* 0000 - 1 if compression type 0 */
    unsigned long offs0004;             /* 0004 - Some flag */

    struct huffman_tree_item items0008[0x203];  /* 0008 - huffman tree items */

    /* Sometimes used as huffman tree item */
    struct huffman_tree_item *item3050;     /* 3050 - Always NULL (?) */
    struct huffman_tree_item *item3054;     /* 3054 - Pointer to huffman_tree_item */
    struct huffman_tree_item *item3058;     /* 3058 - Pointer to huffman_tree_item (< 0 if invalid) */

    /* Sometimes used as huffman tree item */
    struct huffman_tree_item *item305C;     /* 305C - Usually NULL */
    struct huffman_tree_item *first;        /* 3060 - Pointer to top (first) Huffman tree item */
    struct huffman_tree_item *last;         /* 3064 - Pointer to bottom (last) Huffman tree item (< 0 if invalid) */
    unsigned long items;                /* 3068 - Number of used huffman tree items */

    struct huffman_tree_item *items306C[0x102]; /* 306C - huffman_tree_item pointer array */
    struct huffman_decompress qd3474[0x80];     /* 3474 - Array for quick decompression */

    //unsigned char table1502A630[];            /* Some table to make struct size flexible */
};

int libmpq_huff_init_tree(struct huffman_tree *ht, struct huffman_tree_item *hi, unsigned int cmp);
int libmpq_huff_do_decompress(struct huffman_tree *ht, struct huffman_input_stream *is, unsigned char *out_buf, unsigned int out_length);
#endif          /* _HUFFMAN_H */

