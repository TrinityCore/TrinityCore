/*
 *  pack_begin.h -- header file for struct packing used by libmpq.
 *
 *  Copyright (c) 2010-2011 Georg Lukas <georg@op-co.de>
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

#ifndef _PACK_BEGIN
#define _PACK_BEGIN
#else
#error "pack_begin.h may not be included twice!"
#endif

#ifdef _MSC_VER
  #pragma pack(push,1)
  #define PACK_STRUCT
#else
  /* we assume GNU here */
  #define PACK_STRUCT __attribute__((packed))
#endif

