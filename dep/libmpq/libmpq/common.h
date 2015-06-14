/*
 *  common.h -- header functions used by mpq-tools.
 *
 *  Copyright (c) 2003-2011 Maik Broemme <mbroemme@libmpq.org>
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

#ifndef _COMMON_H
#define _COMMON_H

/* function to return the hash to a given string. */
uint32_t libmpq__hash_string(
	const char	*key,
	uint32_t	offset
);

/* function to encrypt a block. */
int32_t libmpq__encrypt_block(
	uint32_t	*in_buf,
	uint32_t	in_size,
	uint32_t	seed
);

/* function to decrypt a block. */
int32_t libmpq__decrypt_block(
	uint32_t	*in_buf,
	uint32_t	in_size,
	uint32_t	seed
);

/* function to detect decryption key. */
int32_t libmpq__decrypt_key(
	uint8_t		*in_buf,
	uint32_t	in_size,
	uint32_t	block_size,
	uint32_t	*key
);

/* function to decompress or explode block from archive. */
int32_t libmpq__decompress_block(
	uint8_t		*in_buf,
	uint32_t	in_size,
	uint8_t		*out_buf,
	uint32_t	out_size,
	uint32_t	compression_type
);

#endif						/* _COMMON_H */
