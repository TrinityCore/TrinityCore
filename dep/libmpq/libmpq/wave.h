/*
 *  wave.h -- header file for wav unplode functions used by mpq-tools.
 *
 *  Copyright (c) 2003-2007 Maik Broemme <mbroemme@plusserver.de>
 *
 *  This source was adepted from the C++ version of wave.h included
 *  in stormlib. The C++ version belongs to the following authors:
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

#ifndef _WAVE_H
#define _WAVE_H

/* buffer. */
typedef union {
	uint16_t	*pw;
	uint8_t		*pb;
} byte_and_int16_t;

/* decompress a wave file, mono or stereo, 1500F230 offset. */
int32_t libmpq__do_decompress_wave(
	uint8_t		*out_buf,
	int32_t		out_length,
	uint8_t		*in_buf,
	int32_t		in_length,
	int32_t		channels
);

#endif						/* _WAVE_H */