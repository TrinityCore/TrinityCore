/*
 *  explode.c -- explode function of pkware data compression library.
 *
 *  Copyright (c) 2003-2008 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of pkware.cpp included
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

/* generic includes. */
#include <string.h>

/* libmpq main includes. */
#include "mpq.h"

/* libmpq generic includes. */
#include "explode.h"

/* tables used for data extraction. */
static const uint8_t pkzip_dist_bits[] = {
	0x02, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

/* tables used for data extraction. */
static const uint8_t pkzip_dist_code[] = {
	0x03, 0x0D, 0x05, 0x19, 0x09, 0x11, 0x01, 0x3E, 0x1E, 0x2E, 0x0E, 0x36, 0x16, 0x26, 0x06, 0x3A,
	0x1A, 0x2A, 0x0A, 0x32, 0x12, 0x22, 0x42, 0x02, 0x7C, 0x3C, 0x5C, 0x1C, 0x6C, 0x2C, 0x4C, 0x0C,
	0x74, 0x34, 0x54, 0x14, 0x64, 0x24, 0x44, 0x04, 0x78, 0x38, 0x58, 0x18, 0x68, 0x28, 0x48, 0x08,
	0xF0, 0x70, 0xB0, 0x30, 0xD0, 0x50, 0x90, 0x10, 0xE0, 0x60, 0xA0, 0x20, 0xC0, 0x40, 0x80, 0x00
};

/* tables used for data extraction. */
static const uint8_t pkzip_clen_bits[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
};

/* tables used for data extraction. */
static const uint16_t pkzip_len_base[] = {
	0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
	0x0008, 0x000A, 0x000E, 0x0016, 0x0026, 0x0046, 0x0086, 0x0106
};

/* tables used for data extraction. */
static const uint8_t pkzip_slen_bits[] = {
	0x03, 0x02, 0x03, 0x03, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x07, 0x07
};

/* tables used for data extraction. */
static const uint8_t pkzip_len_code[] = {
	0x05, 0x03, 0x01, 0x06, 0x0A, 0x02, 0x0C, 0x14, 0x04, 0x18, 0x08, 0x30, 0x10, 0x20, 0x40, 0x00
};

/* tables used for data extraction. */
static const uint8_t pkzip_bits_asc[] = {
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

/* tables used for data extraction. */
static const uint16_t pkzip_code_asc[] = {
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

/* local unused variables. */
char pkware_copyright[] = "PKWARE Data Compression Library for Win32\r\n"
			  "Copyright 1989-1995 PKWARE Inc.  All Rights Reserved\r\n"
			  "Patent No. 5,051,745\r\n"
			  "PKWARE Data Compression Library Reg. U.S. Pat. and Tm. Off.\r\n"
			  "Version 1.11\r\n";

/* skips given number of bits. */
static int32_t skip_bit(pkzip_cmp_s *mpq_pkzip, uint32_t bits) {

	/* check if number of bits required is less than number of bits in the buffer. */
	if (bits <= mpq_pkzip->extra_bits) {
		mpq_pkzip->extra_bits  -= bits;
		mpq_pkzip->bit_buf    >>= bits;
		return 0;
	}

	/* load input buffer if necessary. */
	mpq_pkzip->bit_buf >>= mpq_pkzip->extra_bits;
	if (mpq_pkzip->in_pos == mpq_pkzip->in_bytes) {
		mpq_pkzip->in_pos = sizeof(mpq_pkzip->in_buf);
		if ((mpq_pkzip->in_bytes = mpq_pkzip->read_buf((char *)mpq_pkzip->in_buf, &mpq_pkzip->in_pos, mpq_pkzip->param)) == 0) {
			return 1;
		}
		mpq_pkzip->in_pos = 0;
	}

	/* update bit buffer. */
	mpq_pkzip->bit_buf     |= (mpq_pkzip->in_buf[mpq_pkzip->in_pos++] << 8);
	mpq_pkzip->bit_buf    >>= (bits - mpq_pkzip->extra_bits);
	mpq_pkzip->extra_bits   = (mpq_pkzip->extra_bits - bits) + 8;

	/* if no error was found, return zero. */
	return 0;
}

/* this function generate the decode tables used for decryption. */
static void generate_tables_decode(int32_t count, uint8_t *bits, const uint8_t *code, uint8_t *buf2) {

	/* some common variables. */
	int32_t i;

	/* EBX - count */
	for (i = count-1; i >= 0; i--) {

		/* some common variables. */
		uint32_t idx1 = code[i];
		uint32_t idx2 = 1 << bits[i];

		/* loop until table is ready. */
		do {
			buf2[idx1] = (uint8_t)i;
			idx1      += idx2;
		} while (idx1 < 0x100);
	}
}

/* this function generate the tables for ascii decompression. */
static void generate_tables_ascii(pkzip_cmp_s *mpq_pkzip) {

	/* some common variables. */
	const uint16_t *code_asc = &pkzip_code_asc[0xFF];
	uint32_t acc;
	uint32_t add;
	uint16_t count;

	/* loop through ascii table. */
	for (count = 0x00FF; code_asc >= pkzip_code_asc; code_asc--, count--) {
		uint8_t *bits_asc = mpq_pkzip->bits_asc + count;
		uint8_t bits_tmp  = *bits_asc;

		/* check if byte is finished. */
		if (bits_tmp <= 8) {
			add = (1 << bits_tmp);
			acc = *code_asc;
			do {
				mpq_pkzip->offs_2c34[acc]  = (uint8_t)count;
				acc                       += add;
			} while (acc < 0x100);
		} else {
			if ((acc = (*code_asc & 0xFF)) != 0) {
				mpq_pkzip->offs_2c34[acc] = 0xFF;
				if (*code_asc & 0x3F) {

					/* decrease bit by four. */
					bits_tmp  -= 4;
					*bits_asc  = bits_tmp;
					add        = (1 << bits_tmp);
					acc        = *code_asc >> 4;
					do {
						mpq_pkzip->offs_2d34[acc]  = (uint8_t)count;
						acc                       += add;
					} while (acc < 0x100);
				} else {

					/* decrease bit by six. */
					bits_tmp  -= 6;
					*bits_asc  = bits_tmp;
					add        = (1 << bits_tmp);
					acc        = *code_asc >> 6;
					do {
						mpq_pkzip->offs_2e34[acc]  = (uint8_t)count;
						acc                       += add;
					} while (acc < 0x80);
				}
			} else {

				/* decrease bit by eight. (one byte) */
				bits_tmp  -= 8;
				*bits_asc  = bits_tmp;
				add        = (1 << bits_tmp);
				acc        = *code_asc >> 8;
				do {
					mpq_pkzip->offs_2eb4[acc]  = (uint8_t)count;
					acc                       += add;
				} while (acc < 0x100);
			}
		}
	}
}

/*
 *  decompress the imploded data using coded literals.
 *
 *  returns: 0x000 - 0x0FF : one byte from compressed file.
 *           0x100 - 0x305 : copy previous block. (0x100 = 1 byte)
 *           0x306         : out of buffer?
 */
static uint32_t decode_literal(pkzip_cmp_s *mpq_pkzip) {

	/* number of bits to skip. */
	uint32_t bits;

	/* position in buffers. */
	uint32_t value;

	/* check if bit the current buffer is set, if not return the next byte. */
	if (mpq_pkzip->bit_buf & 1) {

		/* skip current bit in the buffer. */
		if (skip_bit(mpq_pkzip, 1)) {
			return 0x306;
		}

		/* the next bits are position in buffers. */
		value = mpq_pkzip->pos2[(mpq_pkzip->bit_buf & 0xFF)];

		/* get number of bits to skip. */
		if (skip_bit(mpq_pkzip, mpq_pkzip->slen_bits[value])) {
			return 0x306;
		}

		/* check bits. */
		if ((bits = mpq_pkzip->clen_bits[value]) != 0) {

			/* some common variables. */
			uint32_t val2 = mpq_pkzip->bit_buf & ((1 << bits) - 1);

			/* check if we should skip one bit. */
			if (skip_bit(mpq_pkzip, bits)) {

				/* check position if we should skip the bit. */
				if ((value + val2) != 0x10E) {
					return 0x306;
				}
			}

			/* fill values. */
			value = mpq_pkzip->len_base[value] + val2;
		}

		/* return number of bytes to repeat. */
		return value + 0x100;
	}

	/* skip one bit. */
	if (skip_bit(mpq_pkzip, 1)) {
		return 0x306;
	}

	/* check the binary compression type, read 8 bits and return them as one byte. */
	if (mpq_pkzip->cmp_type == LIBMPQ_PKZIP_CMP_BINARY) {

		/* fill values. */
		value = mpq_pkzip->bit_buf & 0xFF;

		/* check if we should skip one bit. */
		if (skip_bit(mpq_pkzip, 8)) {
			return 0x306;
		}

		/* return value from bit buffer. */
		return value;
	}

	/* check if ascii compression is used. */
	if (mpq_pkzip->bit_buf & 0xFF) {

		/* fill values. */
		value = mpq_pkzip->offs_2c34[mpq_pkzip->bit_buf & 0xFF];

		/* check value. */
		if (value == 0xFF) {
			if (mpq_pkzip->bit_buf & 0x3F) {

				/* check if four bits are in bit buffer for skipping. */
				if (skip_bit(mpq_pkzip, 4)) {
					return 0x306;
				}

				/* fill values. */
				value = mpq_pkzip->offs_2d34[mpq_pkzip->bit_buf & 0xFF];
			} else {

				/* check if six bits are in bit buffer for skipping. */
				if (skip_bit(mpq_pkzip, 6)) {
					return 0x306;
				}

				/* fill values. */
				value = mpq_pkzip->offs_2e34[mpq_pkzip->bit_buf & 0x7F];
			}
		}
	} else {

		/* check if eight bits are in bit buffer for skipping. */
		if (skip_bit(mpq_pkzip, 8)) {
			return 0x306;
		}

		/* fill values. */
		value = mpq_pkzip->offs_2eb4[mpq_pkzip->bit_buf & 0xFF];
	}

	/* return out of buffer error (0x306) or position in buffer. */
	return skip_bit(mpq_pkzip, mpq_pkzip->bits_asc[value]) ? 0x306 : value;
}

/* this function retrieves the number of bytes to move back. */
static uint32_t decode_distance(pkzip_cmp_s *mpq_pkzip, uint32_t length) {

	/* some common variables. */
	uint32_t pos  = mpq_pkzip->pos1[(mpq_pkzip->bit_buf & 0xFF)];

	/* number of bits to skip. */
	uint32_t skip = mpq_pkzip->dist_bits[pos];

	/* skip the appropriate number of bits. */
	if (skip_bit(mpq_pkzip, skip) == 1) {
		return 0;
	}

	/* check if length is two. */
	if (length == 2) {
		pos = (pos << 2) | (mpq_pkzip->bit_buf & 0x03);

		/* skip the bits. */
		if (skip_bit(mpq_pkzip, 2) == 1) {
			return 0;
		}
	} else {
		pos = (pos << mpq_pkzip->dsize_bits) | (mpq_pkzip->bit_buf & mpq_pkzip->dsize_mask);

		/* skip the bits */
		if (skip_bit(mpq_pkzip, mpq_pkzip->dsize_bits) == 1) {
			return 0;
		}
	}

	/* return the bytes to move back. */
	return pos + 1;
}

/*
 *  function loads data from the input buffer used by mpq_pkzip
 *  "implode" and "explode" function as user defined callback and
 *  returns number of bytes loaded.
 *
 *  char		*buf	- pointer to a buffer where to store loaded data.
 *  uint32_t		*size	- maximum number of bytes to read.
 *  void		*param	- custom pointer, parameter of implode/explode.
 */
static uint32_t data_read_input(char *buf, uint32_t *size, void *param) {

	/* some common variables. */
	pkzip_data_s *info   = (pkzip_data_s *)param;
	uint32_t max_avail = (info->in_bytes - info->in_pos);
	uint32_t to_read   = *size;

	/* check the case when not enough data available. */
	if (to_read > max_avail) {
		to_read = max_avail;
	}

	/* load data and increment offsets. */
	memcpy(buf, info->in_buf + info->in_pos, to_read);
	info->in_pos += to_read;

	/* return bytes read. */
	return to_read;
}

/*
 *  function for store output data used by mpq_pkzip "implode" and
 *  "explode" as userdefined callback.
 *
 *  char		*buf	- pointer to data to be written.
 *  uint32_t		*size	- number of bytes to write.
 *  void		*param	- custom pointer, parameter of implode/explode.
 */
static void data_write_output(char *buf, uint32_t *size, void *param) {

	/* some common variables. */
	pkzip_data_s *info   = (pkzip_data_s *)param;
	uint32_t max_write = (info->max_out - info->out_pos);
	uint32_t to_write  = *size;

	/* check the case when not enough space in the output buffer. */
	if (to_write > max_write) {
		to_write = max_write;
	}

	/* write output data and increments offsets. */
	memcpy(info->out_buf + info->out_pos, buf, to_write);
	info->out_pos += to_write;
}

/* this function extract the data from input stream. */
static uint32_t expand(pkzip_cmp_s *mpq_pkzip) {

	/* number of bytes to copy. */
	uint32_t copy_bytes;

	/* one byte from compressed file. */
	uint32_t one_byte;

	/* some common variables. */
	uint32_t result;

	/* initialize output buffer position. */
	mpq_pkzip->out_pos = 0x1000;

	/* check if end of data or error, so terminate decompress. */
	while ((result = one_byte = decode_literal(mpq_pkzip)) < 0x305) {

		/* check if one byte is greater than 0x100, which means 'repeat n - 0xFE bytes'. */
		if (one_byte >= 0x100) {

			/* ECX */
			uint8_t *source;

			/* EDX */
			uint8_t *target;

			/* some common variables. */
			uint32_t copy_length = one_byte - 0xFE;
			uint32_t move_back;

			/* get length of data to copy. */
			if ((move_back = decode_distance(mpq_pkzip, copy_length)) == 0) {
				result = 0x306;
				break;
			}

			/* target and source pointer. */
			target              = &mpq_pkzip->out_buf[mpq_pkzip->out_pos];
			source              = target - move_back;
			mpq_pkzip->out_pos += copy_length;

			/* copy until nothing left. */
			while (copy_length-- > 0) {
				*target++ = *source++;
			}
		} else {

			/* byte is 0x100 great, so add one byte. */
			mpq_pkzip->out_buf[mpq_pkzip->out_pos++] = (uint8_t)one_byte;
		}

		/* check if number of extracted bytes has reached 1/2 of output buffer, so flush output buffer. */
		if (mpq_pkzip->out_pos >= 0x2000) {

			/* copy decompressed data into user buffer. */
			copy_bytes = 0x1000;
			mpq_pkzip->write_buf((char *)&mpq_pkzip->out_buf[0x1000], &copy_bytes, mpq_pkzip->param);

			/* check if there are some data left, keep them alive. */
			memcpy(mpq_pkzip->out_buf, &mpq_pkzip->out_buf[0x1000], mpq_pkzip->out_pos - 0x1000);
			mpq_pkzip->out_pos -= 0x1000;
		}
	}

	/* copy the rest. */
	copy_bytes = mpq_pkzip->out_pos - 0x1000;
	mpq_pkzip->write_buf((char *)&mpq_pkzip->out_buf[0x1000], &copy_bytes, mpq_pkzip->param);

	/* return copied bytes. */
	return result;
}

/* this function explode the data stream. */
uint32_t libmpq__do_decompress_pkzip(uint8_t *work_buf, void *param) {

	/* some common variables. */
	pkzip_cmp_s *mpq_pkzip = (pkzip_cmp_s *)work_buf;

	/* set the whole work buffer to zeros. */
	memset(mpq_pkzip, 0, sizeof(pkzip_cmp_s));

	/* initialize work struct and load compressed data. */
	mpq_pkzip->read_buf   = data_read_input;
	mpq_pkzip->write_buf  = data_write_output;
	mpq_pkzip->param      = param;
	mpq_pkzip->in_pos     = sizeof(mpq_pkzip->in_buf);
	mpq_pkzip->in_bytes   = mpq_pkzip->read_buf((char *)mpq_pkzip->in_buf, &mpq_pkzip->in_pos, mpq_pkzip->param);

	/* check if we have pkzip data. */
	if (mpq_pkzip->in_bytes <= 4) {
		return LIBMPQ_PKZIP_CMP_BAD_DATA;
	}

	/* get the compression type. */
	mpq_pkzip->cmp_type   = mpq_pkzip->in_buf[0];

	/* get the dictionary size. */
	mpq_pkzip->dsize_bits = mpq_pkzip->in_buf[1];

	/* initialize 16-bit bit buffer. */
	mpq_pkzip->bit_buf    = mpq_pkzip->in_buf[2];

	/* extra (over 8) bits. */
	mpq_pkzip->extra_bits = 0;

	/* position in input buffer. */
	mpq_pkzip->in_pos     = 3;

	/* check if valid dictionary size. */
	if (4 > mpq_pkzip->dsize_bits || mpq_pkzip->dsize_bits > 6) {
		return LIBMPQ_PKZIP_CMP_INV_DICTSIZE;
	}

	/* shifted by 'sar' instruction. */
	mpq_pkzip->dsize_mask = 0xFFFF >> (0x10 - mpq_pkzip->dsize_bits);

	/* check if we are using binary compression. */
	if (mpq_pkzip->cmp_type != LIBMPQ_PKZIP_CMP_BINARY) {

		/* check if we are using ascii compression. */
		if (mpq_pkzip->cmp_type != LIBMPQ_PKZIP_CMP_ASCII) {
			return LIBMPQ_PKZIP_CMP_INV_MODE;
		}

		/* create ascii buffer. */
		memcpy(mpq_pkzip->bits_asc, pkzip_bits_asc, sizeof(mpq_pkzip->bits_asc));
		generate_tables_ascii(mpq_pkzip);
	}

	/* create the tables for decode. */
	memcpy(mpq_pkzip->slen_bits, pkzip_slen_bits, sizeof(mpq_pkzip->slen_bits));
	generate_tables_decode(0x10, mpq_pkzip->slen_bits, pkzip_len_code, mpq_pkzip->pos2);

	/* create the tables for decode. */
	memcpy(mpq_pkzip->clen_bits, pkzip_clen_bits, sizeof(mpq_pkzip->clen_bits));
	memcpy(mpq_pkzip->len_base, pkzip_len_base, sizeof(mpq_pkzip->len_base));
	memcpy(mpq_pkzip->dist_bits, pkzip_dist_bits, sizeof(mpq_pkzip->dist_bits));
	generate_tables_decode(0x40, mpq_pkzip->dist_bits, pkzip_dist_code, mpq_pkzip->pos1);

	/* check if data extraction works. */
	if (expand(mpq_pkzip) != 0x306) {
		return LIBMPQ_PKZIP_CMP_NO_ERROR;
	}

	/* something failed, so return error. */
	return LIBMPQ_PKZIP_CMP_ABORT;
}
