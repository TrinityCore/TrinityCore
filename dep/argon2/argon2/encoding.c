/*
 * Argon2 reference source code package - reference C implementations
 *
 * Copyright 2015
 * Daniel Dinu, Dmitry Khovratovich, Jean-Philippe Aumasson, and Samuel Neves
 *
 * You may use this work under the terms of a Creative Commons CC0 1.0
 * License/Waiver or the Apache Public License 2.0, at your option. The terms of
 * these licenses can be found at:
 *
 * - CC0 1.0 Universal : http://creativecommons.org/publicdomain/zero/1.0
 * - Apache 2.0        : http://www.apache.org/licenses/LICENSE-2.0
 *
 * You should have received a copy of both of these licenses along with this
 * software. If not, they may be obtained at the above URLs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "encoding.h"
#include "core.h"

/*
 * Example code for a decoder and encoder of "hash strings", with Argon2
 * parameters.
 *
 * This code comprises three sections:
 *
 *   -- The first section contains generic Base64 encoding and decoding
 *   functions. It is conceptually applicable to any hash function
 *   implementation that uses Base64 to encode and decode parameters,
 *   salts and outputs. It could be made into a library, provided that
 *   the relevant functions are made public (non-static) and be given
 *   reasonable names to avoid collisions with other functions.
 *
 *   -- The second section is specific to Argon2. It encodes and decodes
 *   the parameters, salts and outputs. It does not compute the hash
 *   itself.
 *
 * The code was originally written by Thomas Pornin <pornin@bolet.org>,
 * to whom comments and remarks may be sent. It is released under what
 * should amount to Public Domain or its closest equivalent; the
 * following mantra is supposed to incarnate that fact with all the
 * proper legal rituals:
 *
 * ---------------------------------------------------------------------
 * This file is provided under the terms of Creative Commons CC0 1.0
 * Public Domain Dedication. To the extent possible under law, the
 * author (Thomas Pornin) has waived all copyright and related or
 * neighboring rights to this file. This work is published from: Canada.
 * ---------------------------------------------------------------------
 *
 * Copyright (c) 2015 Thomas Pornin
 */

/* ==================================================================== */
/*
 * Common code; could be shared between different hash functions.
 *
 * Note: the Base64 functions below assume that uppercase letters (resp.
 * lowercase letters) have consecutive numerical codes, that fit on 8
 * bits. All modern systems use ASCII-compatible charsets, where these
 * properties are true. If you are stuck with a dinosaur of a system
 * that still defaults to EBCDIC then you already have much bigger
 * interoperability issues to deal with.
 */

/*
 * Some macros for constant-time comparisons. These work over values in
 * the 0..255 range. Returned value is 0x00 on "false", 0xFF on "true".
 */
#define EQ(x, y) ((((0U - ((unsigned)(x) ^ (unsigned)(y))) >> 8) & 0xFF) ^ 0xFF)
#define GT(x, y) ((((unsigned)(y) - (unsigned)(x)) >> 8) & 0xFF)
#define GE(x, y) (GT(y, x) ^ 0xFF)
#define LT(x, y) GT(y, x)
#define LE(x, y) GE(y, x)

/*
 * Convert value x (0..63) to corresponding Base64 character.
 */
static int b64_byte_to_char(unsigned x) {
    return (LT(x, 26) & (x + 'A')) |
           (GE(x, 26) & LT(x, 52) & (x + ('a' - 26))) |
           (GE(x, 52) & LT(x, 62) & (x + ('0' - 52))) | (EQ(x, 62) & '+') |
           (EQ(x, 63) & '/');
}

/*
 * Convert character c to the corresponding 6-bit value. If character c
 * is not a Base64 character, then 0xFF (255) is returned.
 */
static unsigned b64_char_to_byte(int c) {
    unsigned x;

    x = (GE(c, 'A') & LE(c, 'Z') & (c - 'A')) |
        (GE(c, 'a') & LE(c, 'z') & (c - ('a' - 26))) |
        (GE(c, '0') & LE(c, '9') & (c - ('0' - 52))) | (EQ(c, '+') & 62) |
        (EQ(c, '/') & 63);
    return x | (EQ(x, 0) & (EQ(c, 'A') ^ 0xFF));
}

/*
 * Convert some bytes to Base64. 'dst_len' is the length (in characters)
 * of the output buffer 'dst'; if that buffer is not large enough to
 * receive the result (including the terminating 0), then (size_t)-1
 * is returned. Otherwise, the zero-terminated Base64 string is written
 * in the buffer, and the output length (counted WITHOUT the terminating
 * zero) is returned.
 */
static size_t to_base64(char *dst, size_t dst_len, const void *src,
                        size_t src_len) {
    size_t olen;
    const unsigned char *buf;
    unsigned acc, acc_len;

    olen = (src_len / 3) << 2;
    switch (src_len % 3) {
    case 2:
        olen++;
    /* fall through */
    case 1:
        olen += 2;
        break;
    }
    if (dst_len <= olen) {
        return (size_t)-1;
    }
    acc = 0;
    acc_len = 0;
    buf = (const unsigned char *)src;
    while (src_len-- > 0) {
        acc = (acc << 8) + (*buf++);
        acc_len += 8;
        while (acc_len >= 6) {
            acc_len -= 6;
            *dst++ = (char)b64_byte_to_char((acc >> acc_len) & 0x3F);
        }
    }
    if (acc_len > 0) {
        *dst++ = (char)b64_byte_to_char((acc << (6 - acc_len)) & 0x3F);
    }
    *dst++ = 0;
    return olen;
}

/*
 * Decode Base64 chars into bytes. The '*dst_len' value must initially
 * contain the length of the output buffer '*dst'; when the decoding
 * ends, the actual number of decoded bytes is written back in
 * '*dst_len'.
 *
 * Decoding stops when a non-Base64 character is encountered, or when
 * the output buffer capacity is exceeded. If an error occurred (output
 * buffer is too small, invalid last characters leading to unprocessed
 * buffered bits), then NULL is returned; otherwise, the returned value
 * points to the first non-Base64 character in the source stream, which
 * may be the terminating zero.
 */
static const char *from_base64(void *dst, size_t *dst_len, const char *src) {
    size_t len;
    unsigned char *buf;
    unsigned acc, acc_len;

    buf = (unsigned char *)dst;
    len = 0;
    acc = 0;
    acc_len = 0;
    for (;;) {
        unsigned d;

        d = b64_char_to_byte(*src);
        if (d == 0xFF) {
            break;
        }
        src++;
        acc = (acc << 6) + d;
        acc_len += 6;
        if (acc_len >= 8) {
            acc_len -= 8;
            if ((len++) >= *dst_len) {
                return NULL;
            }
            *buf++ = (acc >> acc_len) & 0xFF;
        }
    }

    /*
     * If the input length is equal to 1 modulo 4 (which is
     * invalid), then there will remain 6 unprocessed bits;
     * otherwise, only 0, 2 or 4 bits are buffered. The buffered
     * bits must also all be zero.
     */
    if (acc_len > 4 || (acc & (((unsigned)1 << acc_len) - 1)) != 0) {
        return NULL;
    }
    *dst_len = len;
    return src;
}

/*
 * Decode decimal integer from 'str'; the value is written in '*v'.
 * Returned value is a pointer to the next non-decimal character in the
 * string. If there is no digit at all, or the value encoding is not
 * minimal (extra leading zeros), or the value does not fit in an
 * 'unsigned long', then NULL is returned.
 */
static const char *decode_decimal(const char *str, unsigned long *v) {
    const char *orig;
    unsigned long acc;

    acc = 0;
    for (orig = str;; str++) {
        int c;

        c = *str;
        if (c < '0' || c > '9') {
            break;
        }
        c -= '0';
        if (acc > (ULONG_MAX / 10)) {
            return NULL;
        }
        acc *= 10;
        if ((unsigned long)c > (ULONG_MAX - acc)) {
            return NULL;
        }
        acc += (unsigned long)c;
    }
    if (str == orig || (*orig == '0' && str != (orig + 1))) {
        return NULL;
    }
    *v = acc;
    return str;
}

/* ==================================================================== */
/*
 * Code specific to Argon2.
 *
 * The code below applies the following format:
 *
 *  $argon2<T>[$v=<num>]$m=<num>,t=<num>,p=<num>$<bin>$<bin>
 *
 * where <T> is either 'd', 'id', or 'i', <num> is a decimal integer (positive,
 * fits in an 'unsigned long'), and <bin> is Base64-encoded data (no '=' padding
 * characters, no newline or whitespace).
 *
 * The last two binary chunks (encoded in Base64) are, in that order,
 * the salt and the output. Both are required. The binary salt length and the
 * output length must be in the allowed ranges defined in argon2.h.
 *
 * The ctx struct must contain buffers large enough to hold the salt and pwd
 * when it is fed into decode_string.
 */

int decode_string(argon2_context *ctx, const char *str, argon2_type type) {

/* check for prefix */
#define CC(prefix)                                                             \
    do {                                                                       \
        size_t cc_len = strlen(prefix);                                        \
        if (strncmp(str, prefix, cc_len) != 0) {                               \
            return ARGON2_DECODING_FAIL;                                       \
        }                                                                      \
        str += cc_len;                                                         \
    } while ((void)0, 0)

/* optional prefix checking with supplied code */
#define CC_opt(prefix, code)                                                   \
    do {                                                                       \
        size_t cc_len = strlen(prefix);                                        \
        if (strncmp(str, prefix, cc_len) == 0) {                               \
            str += cc_len;                                                     \
            { code; }                                                          \
        }                                                                      \
    } while ((void)0, 0)

/* Decoding prefix into decimal */
#define DECIMAL(x)                                                             \
    do {                                                                       \
        unsigned long dec_x;                                                   \
        str = decode_decimal(str, &dec_x);                                     \
        if (str == NULL) {                                                     \
            return ARGON2_DECODING_FAIL;                                       \
        }                                                                      \
        (x) = dec_x;                                                           \
    } while ((void)0, 0)


/* Decoding prefix into uint32_t decimal */
#define DECIMAL_U32(x)                                                         \
    do {                                                                       \
        unsigned long dec_x;                                                   \
        str = decode_decimal(str, &dec_x);                                     \
        if (str == NULL || dec_x > UINT32_MAX) {                               \
            return ARGON2_DECODING_FAIL;                                       \
        }                                                                      \
        (x) = (uint32_t)dec_x;                                                 \
    } while ((void)0, 0)


/* Decoding base64 into a binary buffer */
#define BIN(buf, max_len, len)                                                 \
    do {                                                                       \
        size_t bin_len = (max_len);                                            \
        str = from_base64(buf, &bin_len, str);                                 \
        if (str == NULL || bin_len > UINT32_MAX) {                             \
            return ARGON2_DECODING_FAIL;                                       \
        }                                                                      \
        (len) = (uint32_t)bin_len;                                             \
    } while ((void)0, 0)

    size_t maxsaltlen = ctx->saltlen;
    size_t maxoutlen = ctx->outlen;
    int validation_result;
    const char* type_string;

    /* We should start with the argon2_type we are using */
    type_string = argon2_type2string(type, 0);
    if (!type_string) {
        return ARGON2_INCORRECT_TYPE;
    }

    CC("$");
    CC(type_string);

    /* Reading the version number if the default is suppressed */
    ctx->version = ARGON2_VERSION_10;
    CC_opt("$v=", DECIMAL_U32(ctx->version));

    CC("$m=");
    DECIMAL_U32(ctx->m_cost);
    CC(",t=");
    DECIMAL_U32(ctx->t_cost);
    CC(",p=");
    DECIMAL_U32(ctx->lanes);
    ctx->threads = ctx->lanes;

    CC("$");
    BIN(ctx->salt, maxsaltlen, ctx->saltlen);
    CC("$");
    BIN(ctx->out, maxoutlen, ctx->outlen);

    /* The rest of the fields get the default values */
    ctx->secret = NULL;
    ctx->secretlen = 0;
    ctx->ad = NULL;
    ctx->adlen = 0;
    ctx->allocate_cbk = NULL;
    ctx->free_cbk = NULL;
    ctx->flags = ARGON2_DEFAULT_FLAGS;

    /* On return, must have valid context */
    validation_result = validate_inputs(ctx);
    if (validation_result != ARGON2_OK) {
        return validation_result;
    }

    /* Can't have any additional characters */
    if (*str == 0) {
        return ARGON2_OK;
    } else {
        return ARGON2_DECODING_FAIL;
    }
#undef CC
#undef CC_opt
#undef DECIMAL
#undef BIN
}

int encode_string(char *dst, size_t dst_len, argon2_context *ctx,
                  argon2_type type) {
#define SS(str)                                                                \
    do {                                                                       \
        size_t pp_len = strlen(str);                                           \
        if (pp_len >= dst_len) {                                               \
            return ARGON2_ENCODING_FAIL;                                       \
        }                                                                      \
        memcpy(dst, str, pp_len + 1);                                          \
        dst += pp_len;                                                         \
        dst_len -= pp_len;                                                     \
    } while ((void)0, 0)

#define SX(x)                                                                  \
    do {                                                                       \
        char tmp[30];                                                          \
        sprintf(tmp, "%lu", (unsigned long)(x));                               \
        SS(tmp);                                                               \
    } while ((void)0, 0)

#define SB(buf, len)                                                           \
    do {                                                                       \
        size_t sb_len = to_base64(dst, dst_len, buf, len);                     \
        if (sb_len == (size_t)-1) {                                            \
            return ARGON2_ENCODING_FAIL;                                       \
        }                                                                      \
        dst += sb_len;                                                         \
        dst_len -= sb_len;                                                     \
    } while ((void)0, 0)

    const char* type_string = argon2_type2string(type, 0);
    int validation_result = validate_inputs(ctx);

    if (!type_string) {
      return ARGON2_ENCODING_FAIL;
    }

    if (validation_result != ARGON2_OK) {
      return validation_result;
    }


    SS("$");
    SS(type_string);

    SS("$v=");
    SX(ctx->version);

    SS("$m=");
    SX(ctx->m_cost);
    SS(",t=");
    SX(ctx->t_cost);
    SS(",p=");
    SX(ctx->lanes);

    SS("$");
    SB(ctx->salt, ctx->saltlen);

    SS("$");
    SB(ctx->out, ctx->outlen);
    return ARGON2_OK;

#undef SS
#undef SX
#undef SB
}

size_t b64len(uint32_t len) {
    size_t olen = ((size_t)len / 3) << 2;

    switch (len % 3) {
    case 2:
        olen++;
    /* fall through */
    case 1:
        olen += 2;
        break;
    }

    return olen;
}

size_t numlen(uint32_t num) {
    size_t len = 1;
    while (num >= 10) {
        ++len;
        num = num / 10;
    }
    return len;
}

