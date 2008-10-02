/*
 *  wave.c -- this file contains decompression methods used by Storm.dll
 *            to decompress wave files.
 *
 *  Copyright (C) 2003 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of wave.cpp included
 *  in stormlib. The C++ version belongs to the following authors,
 *
 *  Ladislav Zezula <ladik.zezula.net>
 *  Tom Amigo <tomamigo@apexmail.com>
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

#include "wave.h"

/* Tables necessary dor decompression */
static unsigned long wave_table_1503f120[] = {
	0xFFFFFFFF, 0x00000000, 0xFFFFFFFF, 0x00000004, 0xFFFFFFFF, 0x00000002, 0xFFFFFFFF, 0x00000006,
	0xFFFFFFFF, 0x00000001, 0xFFFFFFFF, 0x00000005, 0xFFFFFFFF, 0x00000003, 0xFFFFFFFF, 0x00000007,
	0xFFFFFFFF, 0x00000001, 0xFFFFFFFF, 0x00000005, 0xFFFFFFFF, 0x00000003, 0xFFFFFFFF, 0x00000007,  
	0xFFFFFFFF, 0x00000002, 0xFFFFFFFF, 0x00000004, 0xFFFFFFFF, 0x00000006, 0xFFFFFFFF, 0x00000008  
};

static unsigned long wave_table_1503f1a0[] = {
	0x00000007, 0x00000008, 0x00000009, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E,
	0x00000010, 0x00000011, 0x00000013, 0x00000015, 0x00000017, 0x00000019, 0x0000001C, 0x0000001F,
	0x00000022, 0x00000025, 0x00000029, 0x0000002D, 0x00000032, 0x00000037, 0x0000003C, 0x00000042,
	0x00000049, 0x00000050, 0x00000058, 0x00000061, 0x0000006B, 0x00000076, 0x00000082, 0x0000008F,
	0x0000009D, 0x000000AD, 0x000000BE, 0x000000D1, 0x000000E6, 0x000000FD, 0x00000117, 0x00000133,
	0x00000151, 0x00000173, 0x00000198, 0x000001C1, 0x000001EE, 0x00000220, 0x00000256, 0x00000292,
	0x000002D4, 0x0000031C, 0x0000036C, 0x000003C3, 0x00000424, 0x0000048E, 0x00000502, 0x00000583,
	0x00000610, 0x000006AB, 0x00000756, 0x00000812, 0x000008E0, 0x000009C3, 0x00000ABD, 0x00000BD0,
	0x00000CFF, 0x00000E4C, 0x00000FBA, 0x0000114C, 0x00001307, 0x000014EE, 0x00001706, 0x00001954,
	0x00001BDC, 0x00001EA5, 0x000021B6, 0x00002515, 0x000028CA, 0x00002CDF, 0x0000315B, 0x0000364B,
	0x00003BB9, 0x000041B2, 0x00004844, 0x00004F7E, 0x00005771, 0x0000602F, 0x000069CE, 0x00007462,
	0x00007FFF
};

/*
 *  Decompress a wave file, mono or stereo
 *
 *  Offset: 1500F230
 */
int libmpq_wave_decompress(unsigned char *out_buf, int out_length, unsigned char *in_buf, int in_length, int channels) {
	byte_and_short out;
	byte_and_short in;
	unsigned char *in_end = in_buf + in_length;	/* End on input buffer */
	unsigned long index;
	long nr_array1[2];
	long nr_array2[2];
	int count = 0;

	out.pb     = out_buf;
	in.pb      = in_buf;
	nr_array1[0] = 0x2C;
	nr_array1[1] = 0x2C;
	in.pw++;

	/* 15007AD7 */
	for (count = 0; count < channels; count++) {
		long temp;
		temp = *(short *)in.pw++;
		nr_array2[count] = temp;
		if (out_length < 2) {
			return out.pb - out_buf;
		}
		*out.pw++   = (unsigned short)temp;
		out_length -= 2;
	}
	index = channels - 1;
	while (in.pb < in_end) {
		unsigned char one_byte = *in.pb++;
		if (channels == 2) {
			index = (index == 0) ? 1 : 0;
		}

		/*
		 * Get one byte from input buffer
		 * 15007B25
		 */
		if (one_byte & 0x80) {
			/* 15007B32 */
			switch(one_byte & 0x7F) {
				case 0:					/* 15007B8E */
					if (nr_array1[index] != 0) {
						nr_array1[index]--;
					}
					if (out_length < 2) {
						break;
					}
					*out.pw++ = (unsigned short)nr_array2[index];
					out_length -= 2;
					continue;
				case 1:					/* 15007B72 */
					nr_array1[index] += 8;		/* EBX also */
					if (nr_array1[index] > 0x58) {
						nr_array1[index] = 0x58;
					}
					if (channels == 2) {
						index = (index == 0) ? 1 : 0;
					}
					continue;
				case 2:
					continue;
				default:
					nr_array1[index] -= 8;
					if (nr_array1[index] < 0) {
						nr_array1[index] = 0;
					}
					if (channels != 2) {
						continue;
					}
					index = (index == 0) ? 1 : 0;
					continue;
			}
		} else {
			unsigned long temp1 = wave_table_1503f1a0[nr_array1[index]];	/* EDI */
			unsigned long temp2 = temp1 >> in_buf[1];	/* ESI */
			long temp3 = nr_array2[index];			/* ECX */
			if (one_byte & 0x01) {				/* EBX = one_byte */
				temp2 += (temp1 >> 0);
			}
			if (one_byte & 0x02) {
				temp2 += (temp1 >> 1);
			}
			if (one_byte & 0x04) {
				temp2 += (temp1 >> 2);
			}
			if (one_byte & 0x08) {
				temp2 += (temp1 >> 3);
			}
			if (one_byte & 0x10) {
				temp2 += (temp1 >> 4);
			}
			if (one_byte & 0x20) {
				temp2 += (temp1 >> 5);
			}
			if(one_byte & 0x40) {
				temp3 -= temp2;
				if (temp3 <= (long)0xFFFF8000) {
					temp3 = (long)0xFFFF8000;
				}
			} else {
				temp3 += temp2;
				if (temp3 >= 0x7FFF) {
					temp3 = 0x7FFF;
				}
			}
			nr_array2[index] = temp3;
			if (out_length < 2) {
				break;
			}

			temp2 = nr_array1[index];
			one_byte &= 0x1F;
			*out.pw++ = (unsigned short)temp3;
			out_length -= 2;
			temp2 += wave_table_1503f120[one_byte];
			nr_array1[index] = temp2;

			if (nr_array1[index] < 0) {
				nr_array1[index] = 0;
			} else {
				if (nr_array1[index] > 0x58) {
					nr_array1[index] = 0x58;
				}
			}
		}
	}
	return (out.pb - out_buf);
}
