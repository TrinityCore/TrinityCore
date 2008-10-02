/*
 *  explode.c -- explode function of PKWARE data compression library.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of pkware.cpp included
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

#include <assert.h>
#include <string.h>

#include "mpq.h"
#include "explode.h"

/* Tables */
static unsigned char pkzip_dist_bits[] = {
	0x02, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

static unsigned char pkzip_dist_code[] = {
	0x03, 0x0D, 0x05, 0x19, 0x09, 0x11, 0x01, 0x3E, 0x1E, 0x2E, 0x0E, 0x36, 0x16, 0x26, 0x06, 0x3A,
	0x1A, 0x2A, 0x0A, 0x32, 0x12, 0x22, 0x42, 0x02, 0x7C, 0x3C, 0x5C, 0x1C, 0x6C, 0x2C, 0x4C, 0x0C,
	0x74, 0x34, 0x54, 0x14, 0x64, 0x24, 0x44, 0x04, 0x78, 0x38, 0x58, 0x18, 0x68, 0x28, 0x48, 0x08,
	0xF0, 0x70, 0xB0, 0x30, 0xD0, 0x50, 0x90, 0x10, 0xE0, 0x60, 0xA0, 0x20, 0xC0, 0x40, 0x80, 0x00
};

static unsigned char pkzip_clen_bits[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
};

static unsigned short pkzip_len_base[] = {
	0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
	0x0008, 0x000A, 0x000E, 0x0016, 0x0026, 0x0046, 0x0086, 0x0106
};

static unsigned char pkzip_slen_bits[] = {
	0x03, 0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x07, 0x07
};

static unsigned char pkzip_len_code[] = {
	0x05, 0x03, 0x01, 0x06, 0x0A, 0x02, 0x0C, 0x14, 0x04, 0x18, 0x08, 0x30, 0x10, 0x20, 0x40, 0x00
};

static unsigned char pkzip_bits_asc[] = {
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

static unsigned short pkzip_code_asc[] = {
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

/* Local variables */
static char copyright[] = "PKWARE Data Compression Library for Win32\r\n"
                          "Copyright 1989-1995 PKWARE Inc.  All Rights Reserved\r\n"
                          "Patent No. 5,051,745\r\n"
                          "PKWARE Data Compression Library Reg. U.S. Pat. and Tm. Off.\r\n"
                          "Version 1.11\r\n";

/* Local functions */
static void libmpq_pkzip_gen_decode_tabs(long count, unsigned char *bits, unsigned char *code, unsigned char *buf2) {
	long i;

	for (i = count-1; i >= 0; i--) {		/* EBX - count */
		unsigned long idx1 = code[i];
		unsigned long idx2 = 1 << bits[i];
		do {
			buf2[idx1] = (unsigned char)i;
			idx1      += idx2;
		} while (idx1 < 0x100);
	}
}

static void libmpq_pkzip_gen_asc_tabs(pkzip_data_cmp *mpq_pkzip) {
	unsigned short *code_asc = &pkzip_code_asc[0xFF];
	unsigned long acc, add;
	unsigned short count;

	for (count = 0x00FF; code_asc >= pkzip_code_asc; code_asc--, count--) {
		unsigned char *bits_asc = mpq_pkzip->bits_asc + count;
		unsigned char bits_tmp = *bits_asc;

		if (bits_tmp <= 8) {
			add = (1 << bits_tmp);
			acc = *code_asc;
			do {
				mpq_pkzip->offs_2c34[acc] = (unsigned char)count;
				acc += add;
			} while (acc < 0x100);
		} else {
			if ((acc = (*code_asc & 0xFF)) != 0) {
				mpq_pkzip->offs_2c34[acc] = 0xFF;
				if (*code_asc & 0x3F) {
					bits_tmp -= 4;
					*bits_asc = bits_tmp;
					add = (1 << bits_tmp);
					acc = *code_asc >> 4;
					do {
						mpq_pkzip->offs_2d34[acc] = (unsigned char)count;
						acc += add;
					} while (acc < 0x100);
				} else {
					bits_tmp -= 6;
					*bits_asc = bits_tmp;
					add = (1 << bits_tmp);
					acc = *code_asc >> 6;
					do {
						mpq_pkzip->offs_2e34[acc] = (unsigned char)count;
						acc += add;
					} while (acc < 0x80);
				}
			} else {
				bits_tmp -= 8;
				*bits_asc = bits_tmp;
				add = (1 << bits_tmp);
				acc = *code_asc >> 8;
				do {
					mpq_pkzip->offs_2eb4[acc] = (unsigned char)count;
					acc += add;
				} while (acc < 0x100);
			}
		}
	}
}

/*
 *  Skips given number of bits in bit buffer. Result is stored in mpq_pkzip->bit_buf
 *  If no data in input buffer, returns true
 */
static int libmpq_pkzip_skip_bits(pkzip_data_cmp *mpq_pkzip, unsigned long bits) {
	/* If number of bits required is less than number of (bits in the buffer) ? */
	if (bits <= mpq_pkzip->extra_bits) {
		mpq_pkzip->extra_bits -= bits;
		mpq_pkzip->bit_buf >>= bits;
		return 0;
	}

	/* Load input buffer if necessary */
	mpq_pkzip->bit_buf >>= mpq_pkzip->extra_bits;
	if (mpq_pkzip->in_pos == mpq_pkzip->in_bytes) {
		mpq_pkzip->in_pos = sizeof(mpq_pkzip->in_buf);
		if ((mpq_pkzip->in_bytes = mpq_pkzip->read_buf((char *)mpq_pkzip->in_buf, &mpq_pkzip->in_pos, mpq_pkzip->param)) == 0) {
			return 1;
		}
		mpq_pkzip->in_pos = 0;
	}

	/* Update bit buffer */
	mpq_pkzip->bit_buf |= (mpq_pkzip->in_buf[mpq_pkzip->in_pos++] << 8);
	mpq_pkzip->bit_buf >>= (bits - mpq_pkzip->extra_bits);
	mpq_pkzip->extra_bits = (mpq_pkzip->extra_bits - bits) + 8;
	return 0;
}

/*
 *  Decompress the imploded data using coded literals.
 *  Returns: 0x000 - 0x0FF : One byte from compressed file.
 *           0x100 - 0x305 : Copy previous block (0x100 = 1 byte)
 *           0x306         : Out of buffer (?)
 */
static unsigned long libmpq_pkzip_explode_lit(pkzip_data_cmp *mpq_pkzip) {
	unsigned long bits;				/* Number of bits to skip */
	unsigned long value;				/* Position in buffers */

	/* Test the current bit in byte buffer. If is not set, simply return the next byte. */
	if (mpq_pkzip->bit_buf & 1) {

		/* Skip current bit in the buffer. */
		if (libmpq_pkzip_skip_bits(mpq_pkzip, 1)) {
			return 0x306;
		}

		/* The next bits are position in buffers. */
		value = mpq_pkzip->pos2[(mpq_pkzip->bit_buf & 0xFF)];

		/* Get number of bits to skip */
		if (libmpq_pkzip_skip_bits(mpq_pkzip, mpq_pkzip->slen_bits[value])) {
			return 0x306;
		}
		if ((bits = mpq_pkzip->clen_bits[value]) != 0) {
			unsigned long val2 = mpq_pkzip->bit_buf & ((1 << bits) - 1);
			if (libmpq_pkzip_skip_bits(mpq_pkzip, bits)) {
				if ((value + val2) != 0x10E) {
					return 0x306;
				}
			}
			value = mpq_pkzip->len_base[value] + val2;
		}
		return value + 0x100;			/* Return number of bytes to repeat */
	}

	/* Skip one bit */
	if (libmpq_pkzip_skip_bits(mpq_pkzip, 1)) {
		return 0x306;
	}

	/* If the binary compression type, read 8 bits and return them as one byte. */
	if (mpq_pkzip->cmp_type == LIBMPQ_PKZIP_CMP_BINARY) {
		value = mpq_pkzip->bit_buf & 0xFF;
		if (libmpq_pkzip_skip_bits(mpq_pkzip, 8)) {
			return 0x306;
		}
		return value;
	}

	/* When ASCII compression ... */
	if (mpq_pkzip->bit_buf & 0xFF) {
		value = mpq_pkzip->offs_2c34[mpq_pkzip->bit_buf & 0xFF];
		if (value == 0xFF) {
			if (mpq_pkzip->bit_buf & 0x3F) {
				if (libmpq_pkzip_skip_bits(mpq_pkzip, 4)) {
					return 0x306;
				}
				value = mpq_pkzip->offs_2d34[mpq_pkzip->bit_buf & 0xFF];
			} else {
				if (libmpq_pkzip_skip_bits(mpq_pkzip, 6)) {
					return 0x306;
				}
				value = mpq_pkzip->offs_2e34[mpq_pkzip->bit_buf & 0x7F];
			}
		}
	} else {
		if (libmpq_pkzip_skip_bits(mpq_pkzip, 8)) {
			return 0x306;
		}
		value = mpq_pkzip->offs_2eb4[mpq_pkzip->bit_buf & 0xFF];
	}
	return libmpq_pkzip_skip_bits(mpq_pkzip, mpq_pkzip->bits_asc[value]) ? 0x306 : value;
}

/*
 *  Retrieves the number of bytes to move back.
 */
static unsigned long libmpq_pkzip_explode_dist(pkzip_data_cmp *mpq_pkzip, unsigned long length) {
	unsigned long pos  = mpq_pkzip->pos1[(mpq_pkzip->bit_buf & 0xFF)];
	unsigned long skip = mpq_pkzip->dist_bits[pos];	/* Number of bits to skip */

	/* Skip the appropriate number of bits */
	if (libmpq_pkzip_skip_bits(mpq_pkzip, skip) == 1) {
		return 0;
	}
	if (length == 2) {
		pos = (pos << 2) | (mpq_pkzip->bit_buf & 0x03);
		if (libmpq_pkzip_skip_bits(mpq_pkzip, 2) == 1) {
			return 0;
		}
	} else {
		pos = (pos << mpq_pkzip->dsize_bits) | (mpq_pkzip->bit_buf & mpq_pkzip->dsize_mask);

		/* Skip the bits */
		if (libmpq_pkzip_skip_bits(mpq_pkzip, mpq_pkzip->dsize_bits) == 1) {
			return 0;
		}
	}
	return pos + 1;
}

static unsigned long libmpq_pkzip_expand(pkzip_data_cmp *mpq_pkzip) {
	unsigned int copy_bytes;			/* Number of bytes to copy */
	unsigned long one_byte;				/* One byte from compressed file */
	unsigned long result;

	mpq_pkzip->out_pos = 0x1000;			/* Initialize output buffer position */

	/* If end of data or error, terminate decompress */
	while ((result = one_byte = libmpq_pkzip_explode_lit(mpq_pkzip)) < 0x305) {

		/* If one byte is greater than 0x100, means "Repeat n - 0xFE bytes" */
		if (one_byte >= 0x100) {
			unsigned char *source;		/* ECX */
			unsigned char *target;		/* EDX */
			unsigned long copy_length = one_byte - 0xFE;
			unsigned long move_back;

			/* Get length of data to copy */
			if ((move_back = libmpq_pkzip_explode_dist(mpq_pkzip, copy_length)) == 0) {
				result = 0x306;
				break;
			}

			/* Target and source pointer */
			target = &mpq_pkzip->out_buf[mpq_pkzip->out_pos];
			source = target - move_back;
			mpq_pkzip->out_pos += copy_length;
			while (copy_length-- > 0) {
				*target++ = *source++;
			}
		} else {
			mpq_pkzip->out_buf[mpq_pkzip->out_pos++] = (unsigned char)one_byte;
		}

		/*
		 * If number of extracted bytes has reached 1/2 of output buffer,
		 * flush output buffer.
		 */
		if (mpq_pkzip->out_pos >= 0x2000) {

			/* Copy decompressed data into user buffer. */
			copy_bytes = 0x1000;
			mpq_pkzip->write_buf((char *)&mpq_pkzip->out_buf[0x1000], &copy_bytes, mpq_pkzip->param);

			/* If there are some data left, keep them alive */
			memcpy(mpq_pkzip->out_buf, &mpq_pkzip->out_buf[0x1000], mpq_pkzip->out_pos - 0x1000);
			mpq_pkzip->out_pos -= 0x1000;
		}
	}
	copy_bytes = mpq_pkzip->out_pos - 0x1000;
	mpq_pkzip->write_buf((char *)&mpq_pkzip->out_buf[0x1000], &copy_bytes, mpq_pkzip->param);
	return result;
}

/*
 * Main exploding function.
 */
unsigned int libmpq_pkzip_explode(
	unsigned int	(*read_buf)(char *buf, unsigned  int *size, void *param),
	void		(*write_buf)(char *buf, unsigned  int *size, void *param),
	char		*work_buf,
	void		*param) {

	pkzip_data_cmp *mpq_pkzip = (pkzip_data_cmp *)work_buf;

	/* Set the whole work buffer to zeros */
	memset(mpq_pkzip, 0, sizeof(pkzip_data_cmp));

	/* Initialize work struct and load compressed data */
	mpq_pkzip->read_buf   = read_buf;
	mpq_pkzip->write_buf  = write_buf;
	mpq_pkzip->param      = param;
	mpq_pkzip->in_pos     = sizeof(mpq_pkzip->in_buf);
	mpq_pkzip->in_bytes   = mpq_pkzip->read_buf((char *)mpq_pkzip->in_buf, &mpq_pkzip->in_pos, mpq_pkzip->param);
	if (mpq_pkzip->in_bytes <= 4) {
		return LIBMPQ_PKZIP_CMP_BAD_DATA;
	}
	mpq_pkzip->cmp_type   = mpq_pkzip->in_buf[0];	/* Get the compression type */
	mpq_pkzip->dsize_bits = mpq_pkzip->in_buf[1];	/* Get the dictionary size */
	mpq_pkzip->bit_buf    = mpq_pkzip->in_buf[2];	/* Initialize 16-bit bit buffer */
	mpq_pkzip->extra_bits = 0;			/* Extra (over 8) bits */
	mpq_pkzip->in_pos     = 3;			/* Position in input buffer */

	/* Test for the valid dictionary size */
	if (4 > mpq_pkzip->dsize_bits || mpq_pkzip->dsize_bits > 6) {
		return LIBMPQ_PKZIP_CMP_INV_DICTSIZE;
	}
	mpq_pkzip->dsize_mask = 0xFFFF >> (0x10 - mpq_pkzip->dsize_bits);	/* Shifted by 'sar' instruction */
	if (mpq_pkzip->cmp_type != LIBMPQ_PKZIP_CMP_BINARY) {
		if (mpq_pkzip->cmp_type != LIBMPQ_PKZIP_CMP_ASCII) {
			return LIBMPQ_PKZIP_CMP_INV_MODE;
		}
		memcpy(mpq_pkzip->bits_asc, pkzip_bits_asc, sizeof(mpq_pkzip->bits_asc));
		libmpq_pkzip_gen_asc_tabs(mpq_pkzip);
	}
	memcpy(mpq_pkzip->slen_bits, pkzip_slen_bits, sizeof(mpq_pkzip->slen_bits));
	libmpq_pkzip_gen_decode_tabs(0x10, mpq_pkzip->slen_bits, pkzip_len_code, mpq_pkzip->pos2);
	memcpy(mpq_pkzip->clen_bits, pkzip_clen_bits, sizeof(mpq_pkzip->clen_bits));
	memcpy(mpq_pkzip->len_base, pkzip_len_base, sizeof(mpq_pkzip->len_base));
	memcpy(mpq_pkzip->dist_bits, pkzip_dist_bits, sizeof(mpq_pkzip->dist_bits));
	libmpq_pkzip_gen_decode_tabs(0x40, mpq_pkzip->dist_bits, pkzip_dist_code, mpq_pkzip->pos1);
	if (libmpq_pkzip_expand(mpq_pkzip) != 0x306) {
		return LIBMPQ_PKZIP_CMP_NO_ERROR;
	}
	return LIBMPQ_PKZIP_CMP_ABORT;
}
