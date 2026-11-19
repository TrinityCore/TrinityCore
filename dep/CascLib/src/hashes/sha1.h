/*
 * SHA1 hash implementation and interface functions
 * Copyright (c) 2003-2005, Jouni Malinen <j@w1.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Alternatively, this software may be distributed under the terms of BSD
 * license.
 *
 * See README and COPYING for more details.
 */

#ifndef _SHA1_H
#define _SHA1_H

#include <string.h>

 /* Any 32-bit or wider unsigned integer data type will do */
typedef unsigned int u32;

typedef struct _SHA1_CTX
{
	u32 state[5];
	u32 count[2];
	unsigned char buffer[64];
} SHA1_CTX;

void SHA1_Init  (SHA1_CTX * context);
void SHA1_Update(SHA1_CTX * context, const void * data, u32 len);
void SHA1_Final (SHA1_CTX * context, unsigned char digest[20]);

#endif /* _SHA1_H */
