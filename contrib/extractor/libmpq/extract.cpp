/*
 *  extract.c -- global extracting function for all known file compressions
 *               in a MPQ archive.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define HAVE_LIBZ
#ifdef HAVE_LIBZ
#include <zlib.h>
#endif

#include "mpq.h"
#include "explode.h"
#include "huffman.h"

#include "wave.h"

/*
 *  Support functions for PKWARE data compression library.
 *
 *  Function loads data from the input buffer. Used by mpq_pkzip
 *  "implode" and "explode" function as user-defined callback.
 *  Returns number of bytes loaded.
 *
 *  char * buf          - Pointer to a buffer where to store loaded data
 *  unsigned int * size - Max. number of bytes to read
 *  void * param        - Custom pointer, parameter of implode/explode
 */
static unsigned int libmpq_pkzip_read_input_data(char *buf, unsigned int *size, void *param) {
    pkzip_data *info = (pkzip_data *)param;
    unsigned int max_avail = (info->in_bytes - info->in_pos);
    unsigned int to_read = *size;

    /* Check the case when not enough data available */
    if (to_read > max_avail) {
        to_read = max_avail;
    }

    /* Load data and increment offsets */
    memcpy(buf, info->in_buf + info->in_pos, to_read);
    info->in_pos += to_read;

    return to_read;
}

/*
 *  Support functions for PKWARE data compression library.
 *
 *  Function for store output data. Used by mpq_pkzip "implode" and
 *  "explode" as user-defined callback.
 *
 *  char * buf          - Pointer to data to be written
 *  unsigned int * size - Number of bytes to write
 *  void * param        - Custom pointer, parameter of implode/explode
 */
static void libmpq_pkzip_write_output_data(char *buf, unsigned int *size, void *param) {
    pkzip_data *info = (pkzip_data *)param;
    unsigned int max_write = (info->max_out - info->out_pos);
    unsigned int to_write = *size;

    /* Check the case when not enough space in the output buffer */
    if (to_write > max_write) {
        to_write = max_write;
    }

    /* Write output data and increments offsets */
    memcpy(info->out_buf + info->out_pos, buf, to_write);
    info->out_pos += to_write;
}

int libmpq_pkzip_decompress(char *out_buf, int *out_length, char *in_buf, int in_length) {
    pkzip_data info;                    /* Data information */
    char *work_buf = (char *)malloc(LIBMPQ_PKZIP_EXP_BUFFER_SIZE);  /* mpq_pkzip work buffer */

    /* Fill data information structure */
    info.in_buf   = in_buf;
    info.in_pos   = 0;
    info.in_bytes = in_length;
    info.out_buf  = out_buf;
    info.out_pos  = 0;
    info.max_out  = *out_length;

    /* Do the decompression */
    libmpq_pkzip_explode(libmpq_pkzip_read_input_data, libmpq_pkzip_write_output_data, work_buf, &info);
    *out_length = info.out_pos;
    free(work_buf);
    return 0;
}

int libmpq_wave_decompress_mono(char *out_buf, int *out_length, char *in_buf, int in_length) {
    *out_length = libmpq_wave_decompress((unsigned char *)out_buf, *out_length, (unsigned char *)in_buf, in_length, 1);
    return 1;
}

int libmpq_wave_decompress_stereo(char *out_buf, int *out_length, char *in_buf, int in_length) {
    *out_length = libmpq_wave_decompress((unsigned char *)out_buf, *out_length, (unsigned char *)in_buf, in_length, 2);
    return 1;
}

int libmpq_zlib_decompress(char *out_buf, int *out_length, char *in_buf, int in_length) {
#ifdef HAVE_LIBZ
    z_stream z;                 /* Stream information for zlib */
    int result;

    /* Fill the stream structure for zlib */
    z.next_in   = (Bytef *)in_buf;
    z.avail_in  = (uInt)in_length;
    z.total_in  = in_length;
    z.next_out  = (Bytef *)out_buf;
    z.avail_out = *out_length;
    z.total_out = 0;
    z.zalloc    = NULL;
    z.zfree     = NULL;

    /* Initialize the decompression structure. Storm.dll uses zlib version 1.1.3 */
    if ((result = inflateInit(&z)) == 0) {

        /* Call zlib to decompress the data */
        result = inflate(&z, Z_FINISH);
        *out_length = z.total_out;
        inflateEnd(&z);
    }
    return result;
#else
    memset(out_buf, '0', *out_length);
    return 0;
#endif
}

/*
 *  Huffmann decompression routine. The in_length parameter is not used, but needs
 *  to be specified due to compatibility reasons.
 *
 *  1500F5F0
 */
int libmpq_huff_decompress(char *out_buf, int *out_length, char *in_buf, int in_length) {
    struct huffman_tree     *ht = (huffman_tree *)malloc(sizeof(struct huffman_tree));
    struct huffman_input_stream *is = (huffman_input_stream *)malloc(sizeof(struct huffman_input_stream));
    struct huffman_tree_item    *hi = (huffman_tree_item *)malloc(sizeof(struct huffman_tree_item));
    memset(ht, 0, sizeof(struct huffman_tree));
    memset(is, 0, sizeof(struct huffman_input_stream));
    memset(hi, 0, sizeof(struct huffman_tree_item));

    /* Initialize input stream */
    is->bit_buf  = *(unsigned long *)in_buf;
    in_buf      += sizeof(unsigned long);
    is->in_buf   = (unsigned char *)in_buf;
    is->bits     = 32;

    /* Initialize the Huffmann tree for decompression */
    libmpq_huff_init_tree(ht, hi, LIBMPQ_HUFF_DECOMPRESS);

    *out_length = libmpq_huff_do_decompress(ht, is, (unsigned char *)out_buf, *out_length);

    free(hi);
    free(is);
    free(ht);
    return 0;
}

int libmpq_multi_decompress(char *out_buf, int *pout_length, char *in_buf, int in_length) {
    char        *temp_buf = NULL;       /* Temporary storage for decompressed data */
    char        *work_buf = NULL;       /* Where to store decompressed data */
    int     out_length = *pout_length;  /* For storage number of output bytes */
    unsigned    fDecompressions1;       /* Decompressions applied to the block */
    unsigned    fDecompressions2;       /* Just another copy of decompressions applied to the block */
    int     count = 0;          /* Counter for every use */
    int     entries = (sizeof(dcmp_table) / sizeof(decompress_table));
    int     i;

    /* If the input length is the same as output, do nothing. */
    if (in_length == out_length) {
        if (in_buf == out_buf) {
            return 1;
        }
        memcpy(out_buf, in_buf, in_length);
        return 1;
    }

    /* Get applied compression types and decrement data length */
    fDecompressions1 = fDecompressions2 = (unsigned char)*in_buf++;
    in_length--;

    /* Search decompression table type and get all types of compression */
    for (i = 0; i < entries; i++) {
        /* We have to apply this decompression? */
        if (fDecompressions1 & dcmp_table[i].mask) {
            count++;
        }

        /* Clear this flag from temporary variable. */
        fDecompressions2 &= ~dcmp_table[i].mask;
    }

    /*
     *  Check if there is some method unhandled
     *  (E.g. compressed by future versions)
     */
    if (fDecompressions2 != 0) {
        printf("Unknown Compression\n");
        return 0;
    }

    /* If there is more than only one compression, we have to allocate extra buffer */
    if (count >= 2) {
        temp_buf = (char *)malloc(out_length);
    }

    /* Apply all decompressions */
    for (i = 0, count = 0; i < entries; i++) {

        /* If not used this kind of compression, skip the loop */
        if (fDecompressions1 & dcmp_table[i].mask) {

            /* If odd case, use target buffer for output, otherwise use allocated tempbuf */
            work_buf = (count++ & 1) ? temp_buf : out_buf;
            out_length = *pout_length;

            /* Decompress buffer using corresponding function */
            dcmp_table[i].decompress(work_buf, &out_length, in_buf, in_length);

            /* Move output length to src length for next compression */
            in_length = out_length;
            in_buf = work_buf;
        }
    }

    /* If output buffer is not the same like target buffer, we have to copy data */
    if (work_buf != out_buf) {
        memcpy(out_buf, in_buf, out_length);
    }
    *pout_length = out_length;

    /* Delete temporary buffer, if necessary */
    if (temp_buf != NULL) {
        free(temp_buf);
    }
    return 1;
}

