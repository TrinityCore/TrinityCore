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

#ifndef BLAKE_ROUND_MKA_H
#define BLAKE_ROUND_MKA_H

#include "blake2.h"
#include "blake2-impl.h"

/* designed by the Lyra PHC team */
static BLAKE2_INLINE uint64_t fBlaMka(uint64_t x, uint64_t y) {
    const uint64_t m = UINT64_C(0xFFFFFFFF);
    const uint64_t xy = (x & m) * (y & m);
    return x + y + 2 * xy;
}

#define G(a, b, c, d)                                                          \
    do {                                                                       \
        a = fBlaMka(a, b);                                                     \
        d = rotr64(d ^ a, 32);                                                 \
        c = fBlaMka(c, d);                                                     \
        b = rotr64(b ^ c, 24);                                                 \
        a = fBlaMka(a, b);                                                     \
        d = rotr64(d ^ a, 16);                                                 \
        c = fBlaMka(c, d);                                                     \
        b = rotr64(b ^ c, 63);                                                 \
    } while ((void)0, 0)

#define BLAKE2_ROUND_NOMSG(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11,   \
                           v12, v13, v14, v15)                                 \
    do {                                                                       \
        G(v0, v4, v8, v12);                                                    \
        G(v1, v5, v9, v13);                                                    \
        G(v2, v6, v10, v14);                                                   \
        G(v3, v7, v11, v15);                                                   \
        G(v0, v5, v10, v15);                                                   \
        G(v1, v6, v11, v12);                                                   \
        G(v2, v7, v8, v13);                                                    \
        G(v3, v4, v9, v14);                                                    \
    } while ((void)0, 0)

#endif
