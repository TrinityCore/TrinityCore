/*
 *  extract.c -- global extracting function for all known file compressions
 *               in a mpq archive.
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

/* generic includes. */
#include <stdlib.h>
#include <string.h>

/* zlib includes. */
#include <zlib.h>
#include <bzlib.h>

/* libmpq main includes. */
#include "mpq.h"

/* libmpq generic includes. */
#include "explode.h"
#include "extract.h"
#include "huffman.h"
#include "wave.h"

/* table with decompression bits and functions. */
static decompress_table_s dcmp_table[] = {
	{LIBMPQ_COMPRESSION_HUFFMAN, libmpq__decompress_huffman},	/* decompression using huffman trees. */
	{LIBMPQ_COMPRESSION_ZLIB, libmpq__decompress_zlib},	/* decompression with the zlib library. */
	{LIBMPQ_COMPRESSION_PKZIP, libmpq__decompress_pkzip},	/* decompression with pkware data compression library. */
	{LIBMPQ_COMPRESSION_BZIP2, libmpq__decompress_bzip2},	/* decompression with bzip2 library. */
	{LIBMPQ_COMPRESSION_WAVE_MONO, libmpq__decompress_wave_mono},	/* decompression for mono waves. */
	{LIBMPQ_COMPRESSION_WAVE_STEREO, libmpq__decompress_wave_stereo}	/* decompression for stereo waves. */
};

/* this function decompress a stream using huffman algorithm. */
int32_t libmpq__decompress_huffman(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

    (void)in_size;
	/* TODO: make typdefs of this structs? */
	/* some common variables. */
	int32_t tb     = 0;
	struct huffman_tree_s *ht;
	struct huffman_input_stream_s *is;

	/* allocate memory for the huffman tree. */
	if ((ht = malloc(sizeof(struct huffman_tree_s))) == NULL ||
	    (is = malloc(sizeof(struct huffman_input_stream_s))) == NULL) {

		/* memory allocation problem. */
		return LIBMPQ_ERROR_MALLOC;
	}

	/* cleanup structures. */
	memset(ht, 0, sizeof(struct huffman_tree_s));
	memset(is, 0, sizeof(struct huffman_input_stream_s));

	/* initialize input stream. */
	is->bit_buf  = *(uint32_t *)in_buf;
	in_buf      += sizeof(int32_t);
	is->in_buf   = (uint8_t *)in_buf;
	is->bits     = 32;

// TODO: add all the mallocs to init function and add function libmpq__huffman_tree_free() */
//	if ((result = libmpq__huffman_tree_init(ht, LIBMPQ_HUFF_DECOMPRESS)) < 0) {
//
//		/* something on zlib initialization failed. */
//		return LIBMPQ_ERROR_UNPACK;
//	}

	/* initialize the huffman tree for decompression. */
	libmpq__huffman_tree_init(ht, LIBMPQ_HUFF_DECOMPRESS);

	/* save the number of copied bytes. */
	tb = libmpq__do_decompress_huffman(ht, is, out_buf, out_size);

	/* free structures. */
	free(is);
	free(ht);

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using zlib algorithm. */
int32_t libmpq__decompress_zlib(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t result = 0;
	int32_t tb     = 0;
	z_stream z;

	/* fill the stream structure for zlib. */
	z.next_in   = (Bytef *)in_buf;
	z.avail_in  = (uInt)in_size;
	z.total_in  = in_size;
	z.next_out  = (Bytef *)out_buf;
	z.avail_out = (uInt)out_size;
	z.total_out = 0;
	z.zalloc    = NULL;
	z.zfree     = NULL;

	/* initialize the decompression structure, storm.dll uses zlib version 1.1.3. */
	if ((result = inflateInit(&z)) != Z_OK) {

		/* something on zlib initialization failed. */
		return result;
	}

	/* call zlib to decompress the data. */
	if ((result = inflate(&z, Z_FINISH)) != Z_STREAM_END) {

		/* something on zlib decompression failed. */
		return result;
	}

	/* save transferred bytes. */
	tb = z.total_out;

	/* cleanup zlib. */
	if ((result = inflateEnd(&z)) != Z_OK) {

		/* something on zlib finalization failed. */
		return result;
	}

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using pkzip algorithm. */
int32_t libmpq__decompress_pkzip(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t tb = 0;
	uint8_t *work_buf;
	pkzip_data_s info;

	/* allocate memory for pkzip data structure. */
	if ((work_buf = malloc(sizeof(pkzip_cmp_s))) == NULL) {

		/* memory allocation problem. */
		return LIBMPQ_ERROR_MALLOC;
	}

	/* cleanup. */
	memset(work_buf, 0, sizeof(pkzip_cmp_s));

	/* fill data information structure. */
	info.in_buf   = in_buf;
	info.in_pos   = 0;
	info.in_bytes = in_size;
	info.out_buf  = out_buf;
	info.out_pos  = 0;
	info.max_out  = out_size;

	/* do the decompression. */
	if ((tb = libmpq__do_decompress_pkzip(work_buf, &info)) < 0) {

		/* free working buffer. */
		free(work_buf);

		/* something failed on pkzip decompression. */
		return tb;
	}

	/* save transferred bytes. */
	tb = info.out_pos;

	/* free working buffer. */
	free(work_buf);

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using bzip2 library. */
int32_t libmpq__decompress_bzip2(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t result = 0;
	int32_t tb     = 0;
	bz_stream strm;

	/* initialize the bzlib decompression. */
	strm.bzalloc = NULL;
	strm.bzfree  = NULL;

	/* initialize the structure. */
	if ((result = BZ2_bzDecompressInit(&strm, 0, 0)) != BZ_OK) {

		/* something on bzlib initialization failed. */
		return result;
	}

	/* fill the stream structure for bzlib. */
	strm.next_in   = (char *)in_buf;
	strm.avail_in  = in_size;
	strm.next_out  = (char *)out_buf;
	strm.avail_out = out_size;

	/* do the decompression. */
	while (BZ2_bzDecompress(&strm) != BZ_STREAM_END);

	/* save transferred bytes. */
	tb = strm.total_out_lo32;

	/* cleanup of bzip stream. */
	BZ2_bzDecompressEnd(&strm);

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using wave algorithm. (1 channel) */
int32_t libmpq__decompress_wave_mono(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t tb = 0;

	/* save the number of copied bytes. */
	if ((tb = libmpq__do_decompress_wave(out_buf, out_size, in_buf, in_size, 1)) < 0) {

		/* something on wave decompression failed. */
		return tb;
	}

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using wave algorithm. (2 channels) */
int32_t libmpq__decompress_wave_stereo(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t tb = 0;

	/* save the number of copied bytes. */
	if ((tb = libmpq__do_decompress_wave(out_buf, out_size, in_buf, in_size, 2)) < 0) {

		/* something on wave decompression failed. */
		return tb;
	}

	/* return transferred bytes. */
	return tb;
}

/* this function decompress a stream using a combination of the other compression algorithm. */
int32_t libmpq__decompress_multi(uint8_t *in_buf, uint32_t in_size, uint8_t *out_buf, uint32_t out_size) {

	/* some common variables. */
	int32_t tb        = 0;
	uint32_t count    = 0;
	uint32_t entries  = (sizeof(dcmp_table) / sizeof(decompress_table_s));
	uint8_t *temp_buf = NULL;
	uint8_t *work_buf = 0;
	uint8_t decompress_flag, decompress_unsupp;
	uint32_t i;

	/* get applied compression types. */
	decompress_flag = decompress_unsupp = *in_buf++;

	/* decrement data size. */
	in_size--;

	/* search decompression table type and get all types of compression. */
	for (i = 0; i < entries; i++) {

		/* check if have to apply this decompression. */
		if (decompress_flag & dcmp_table[i].mask) {

			/* increase counter for used compression algorithms. */
			count++;
			/* this algorithm is supported, remove from unsupp mask */
			decompress_unsupp &= ~dcmp_table[i].mask;
		}
	}

	/* check if there is some method unhandled. (e.g. compressed by future versions) */
	if (decompress_unsupp) {

		/* compression type is unknown and we need to implement it. :) */
		return LIBMPQ_ERROR_UNPACK;
	}

	/* if multiple decompressions should be made, we need temporary buffer for the data. */
	if (count > 1) {

		/* allocate memory for temporary buffer. */
		if ((temp_buf = malloc(out_size)) == NULL) {

			/* memory allocation problem. */
			return LIBMPQ_ERROR_MALLOC;
		}

		/* cleanup. */
		memset(temp_buf, 0, out_size);
	}

	/* apply all decompressions. */
	for (i = 0, count = 0; i < entries; i++) {

		/* check if not used this kind of compression. */
		if (decompress_flag & dcmp_table[i].mask) {

			/* if multiple decompressions should be made, we need temporary buffer for the data. */
			if (count == 0) {

				/* use output buffer as working buffer. */
				work_buf = out_buf;
			} else {

				/* use temporary buffer as working buffer. */
				work_buf = temp_buf;
			}

			/* decompress buffer using corresponding function. */
			if ((tb = dcmp_table[i].decompress(in_buf, in_size, work_buf, out_size)) < 0) {

				/* free temporary buffer. */
				free(temp_buf);

				/* something on decompression failed. */
				return tb;
			}

			/* move output size to source size for next compression. */
			in_size = out_size;
			in_buf  = work_buf;

			/* increase counter. */
			count++;
		}
	}

	/* if output buffer is not the same like target buffer, we have to copy data (this will happen on multiple decompressions). */
	if (work_buf != out_buf) {

		/* copy buffer. */
		memcpy(out_buf, in_buf, out_size);
	}

	/* free temporary buffer. */
	free(temp_buf);

	/* return transferred bytes. */
	return tb;
}
