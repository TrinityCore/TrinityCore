/*
 *  mpq-internal.h -- some default types and defines, but only required for
 *                    compilation of the library.
 *
 *  Copyright (c) 2003-2008 Maik Broemme <mbroemme@plusserver.de>
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

#ifndef _MPQ_INTERNAL_H
#define _MPQ_INTERNAL_H

/* generic includes. */
#include <stdint.h>
#include <stdio.h>

/* define return value if nothing failed. */
#define LIBMPQ_SUCCESS				0		/* return value for all functions which success. */

/* define generic mpq archive information. */
#define LIBMPQ_HEADER				0x1A51504D	/* mpq archive header ('MPQ\x1A') */

/* define the known archive versions. */
#define LIBMPQ_ARCHIVE_VERSION_ONE		0		/* version one used until world of warcraft. */
#define LIBMPQ_ARCHIVE_VERSION_TWO		1		/* version two used from world of warcraft - the burning crusade. */

/* define values used by blizzard as flags. */
#define LIBMPQ_FLAG_EXISTS			0x80000000	/* set if file exists, reset when the file was deleted. */
#define LIBMPQ_FLAG_ENCRYPTED			0x00010000	/* indicates whether file is encrypted. */
#define LIBMPQ_FLAG_COMPRESSED			0x0000FF00	/* file is compressed. */
#define LIBMPQ_FLAG_COMPRESS_PKZIP		0x00000100	/* compression made by pkware data compression library. */
#define LIBMPQ_FLAG_COMPRESS_MULTI		0x00000200	/* multiple compressions. */
#define LIBMPQ_FLAG_COMPRESS_NONE		0x00000300	/* no compression (no blizzard flag used by myself). */
#define LIBMPQ_FLAG_SINGLE			0x01000000	/* file is stored in one single sector, first seen in world of warcraft. */
#define LIBMPQ_FLAG_CRC				0x04000000	/* compressed block offset table has CRC checksum. */

/* define generic hash values. */
#define LIBMPQ_HASH_FREE			0xFFFFFFFF	/* hash table entry is empty and has always been empty. */

/* define special files. */
#define LIBMPQ_LISTFILE_NAME			"(listfile)"	/* internal listfile. */
#define LIBMPQ_SIGNATURE_NAME			"(signature)"	/* internal signature file. */
#define LIBMPQ_ATTRIBUTES_NAME			"(attributes)"	/* internal attributes file. */

/* define true and false, because not all systems have them. */
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#include "pack_begin.h"
/* mpq archive header. */
typedef struct {
	uint32_t	mpq_magic;		/* the 0x1A51504D ('MPQ\x1A') signature. */
	uint32_t	header_size;		/* mpq archive header size. */
	uint32_t	archive_size;		/* size of mpq archive. */
	uint16_t	version;		/* 0000 for starcraft and broodwar. */
	uint16_t	block_size;		/* size of file block is (512 * 2 ^ block size). */
	uint32_t	hash_table_offset;	/* file position of mpq_hash. */
	uint32_t	block_table_offset;	/* file position of mpq_block, each entry has 16 bytes. */
	uint32_t	hash_table_count;	/* number of entries in hash table. */
	uint32_t	block_table_count;	/* number of entries in the block table. */
} PACK_STRUCT mpq_header_s;

/* mpq extended archive header, used since world of warcraft - the burning crusade. */
typedef struct {
	uint64_t	extended_offset;	/* offset to the beginning of the extended block table, relative to the beginning of the archive. */
	uint16_t	hash_table_offset_high;	/* upper 16 bits of the hash table offset for large archives. */
	uint16_t	block_table_offset_high;/* upper 16 bits of the block table offset for large archives.*/
} PACK_STRUCT mpq_header_ex_s;

/* hash entry, all files in the archive are searched by their hashes. */
typedef struct {
	uint32_t	hash_a;			/* the first two uint32_ts are the encrypted file. */
	uint32_t	hash_b;			/* the first two uint32_ts are the encrypted file. */
	uint16_t	locale;			/* locale information. */
	uint16_t	platform;		/* platform information and zero is default. */
	uint32_t	block_table_index;	/* index to file description block. */
} PACK_STRUCT mpq_hash_s;

/* file description block contains informations about the file. */
typedef struct {
	uint32_t	offset;			/* block file starting position in the archive. */
	uint32_t	packed_size;		/* packed file size. */
	uint32_t	unpacked_size;		/* unpacked file size. */
	uint32_t	flags;			/* flags. */
} PACK_STRUCT mpq_block_s;

/* extended file description block contains information about the offset beyond 2^32 (4GB). */
typedef struct {
	uint16_t	offset_high;		/* upper 16 bit of the file offset in archive. */
} PACK_STRUCT mpq_block_ex_s;

/* file structure used since diablo 1.00 (0x38 bytes). */
typedef struct {
	uint32_t	seed;			/* seed used for file decrypt. */
	uint32_t	*packed_offset;		/* position of each file block (only for packed files). */
	uint32_t	open_count;		/* number of times it has been opened - used for freeing */
} PACK_STRUCT mpq_file_s;

/* map structure for valid blocks and hashes (first seen in warcraft 3 archives). */
typedef struct {
	uint32_t	block_table_indices;	/* real mapping for file number to block entry. */
	uint32_t	block_table_diff;	/* block table difference between valid blocks and invalid blocks before. */
} PACK_STRUCT mpq_map_s;
#include "pack_end.h"

/* archive structure used since diablo 1.00 by blizzard. */
struct mpq_archive {
	/* generic file information. */
	FILE		*fp;			/* file handle. */

	/* generic size information. */
	uint32_t	block_size;		/* size of the mpq block. */
	off_t		archive_offset;		/* absolute start position of archive. */

	/* archive related buffers and tables. */
	mpq_header_s	mpq_header;		/* mpq file header. */
	mpq_header_ex_s	mpq_header_ex;		/* mpq extended file header. */
	mpq_hash_s	*mpq_hash;		/* hash table. */
	mpq_block_s	*mpq_block;		/* block table. */
	mpq_block_ex_s	*mpq_block_ex;		/* extended block table. */
	mpq_file_s	**mpq_file;		/* pointer to the file pointers which are opened. */

	/* non archive structure related members. */
	mpq_map_s	*mpq_map;		/* map table between valid blocks and hashes. */
	uint32_t	files;			/* number of files in archive, which could be extracted. */
};

#endif						/* _MPQ_INTERNAL_H */