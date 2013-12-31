/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "TOTP.h"
#include <cstring>

int base32_decode(const char* encoded, char* result, int bufSize)
{
    // Base32 implementation
    // Copyright 2010 Google Inc.
    // Author: Markus Gutschke
    // Licensed under the Apache License, Version 2.0
    int buffer = 0;
    int bitsLeft = 0;
    int count = 0;
    for (const char *ptr = encoded; count < bufSize && *ptr; ++ptr)
    {
        char ch = *ptr;
        if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '-')
            continue;
        buffer <<= 5;

        // Deal with commonly mistyped characters
        if (ch == '0')
            ch = 'O';
        else if (ch == '1')
            ch = 'L';
        else if (ch == '8')
            ch = 'B';

        // Look up one base32 digit
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            ch = (ch & 0x1F) - 1;
        else if (ch >= '2' && ch <= '7')
            ch -= '2' - 26;
        else
            return -1;

        buffer |= ch;
        bitsLeft += 5;
        if (bitsLeft >= 8)
        {
            result[count++] = buffer >> (bitsLeft - 8);
            bitsLeft -= 8;
        }
    }

    if (count < bufSize)
        result[count] = '\000';
    return count;
}

#define HMAC_RES_SIZE 20

namespace TOTP
{
    unsigned int GenerateToken(const char* b32key)
    {
        size_t keySize = strlen(b32key);
        int bufsize = (keySize + 7)/8*5;
        char* encoded = new char[bufsize];
        memset(encoded, 0, bufsize);
        unsigned int hmacResSize = HMAC_RES_SIZE;
        unsigned char hmacRes[HMAC_RES_SIZE];
        unsigned long timestamp = time(NULL)/30;
        unsigned char challenge[8];

        for (int i = 8; i--;timestamp >>= 8)
            challenge[i] = timestamp;

        base32_decode(b32key, encoded, bufsize);
        HMAC(EVP_sha1(), encoded, bufsize, challenge, 8, hmacRes, &hmacResSize);
        unsigned int offset = hmacRes[19] & 0xF;
        unsigned int truncHash = (hmacRes[offset] << 24) | (hmacRes[offset+1] << 16 )| (hmacRes[offset+2] << 8) | (hmacRes[offset+3]);
        truncHash &= 0x7FFFFFFF;

        delete[] encoded;

        return truncHash % 1000000;
    }
}
