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

#ifndef PORTABLE_BLAKE2_IMPL_H
#define PORTABLE_BLAKE2_IMPL_H

#include <stdint.h>
#include <string.h>

#if defined(_MSC_VER)
#define BLAKE2_INLINE __inline
#elif defined(__GNUC__) || defined(__clang__)
#define BLAKE2_INLINE __inline__
#else
#define BLAKE2_INLINE
#endif

/* Argon2 Team - Begin Code */
/*
   Not an exhaustive list, but should cover the majority of modern platforms
   Additionally, the code will always be correct---this is only a performance
   tweak.
*/
#if (defined(__BYTE_ORDER__) &&                                                \
     (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)) ||                           \
    defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__MIPSEL__) || \
    defined(__AARCH64EL__) || defined(__amd64__) || defined(__i386__) ||       \
    defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64) ||                \
    defined(_M_ARM)
#define NATIVE_LITTLE_ENDIAN
#endif
/* Argon2 Team - End Code */

static BLAKE2_INLINE uint32_t load32(const void *src) {
#if defined(NATIVE_LITTLE_ENDIAN)
    uint32_t w;
    memcpy(&w, src, sizeof w);
    return w;
#else
    const uint8_t *p = (const uint8_t *)src;
    uint32_t w = *p++;
    w |= (uint32_t)(*p++) << 8;
    w |= (uint32_t)(*p++) << 16;
    w |= (uint32_t)(*p++) << 24;
    return w;
#endif
}

static BLAKE2_INLINE uint64_t load64(const void *src) {
#if defined(NATIVE_LITTLE_ENDIAN)
    uint64_t w;
    memcpy(&w, src, sizeof w);
    return w;
#else
    const uint8_t *p = (const uint8_t *)src;
    uint64_t w = *p++;
    w |= (uint64_t)(*p++) << 8;
    w |= (uint64_t)(*p++) << 16;
    w |= (uint64_t)(*p++) << 24;
    w |= (uint64_t)(*p++) << 32;
    w |= (uint64_t)(*p++) << 40;
    w |= (uint64_t)(*p++) << 48;
    w |= (uint64_t)(*p++) << 56;
    return w;
#endif
}

static BLAKE2_INLINE void store32(void *dst, uint32_t w) {
#if defined(NATIVE_LITTLE_ENDIAN)
    memcpy(dst, &w, sizeof w);
#else
    uint8_t *p = (uint8_t *)dst;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
#endif
}

static BLAKE2_INLINE void store64(void *dst, uint64_t w) {
#if defined(NATIVE_LITTLE_ENDIAN)
    memcpy(dst, &w, sizeof w);
#else
    uint8_t *p = (uint8_t *)dst;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
#endif
}

static BLAKE2_INLINE uint64_t load48(const void *src) {
    const uint8_t *p = (const uint8_t *)src;
    uint64_t w = *p++;
    w |= (uint64_t)(*p++) << 8;
    w |= (uint64_t)(*p++) << 16;
    w |= (uint64_t)(*p++) << 24;
    w |= (uint64_t)(*p++) << 32;
    w |= (uint64_t)(*p++) << 40;
    return w;
}

static BLAKE2_INLINE void store48(void *dst, uint64_t w) {
    uint8_t *p = (uint8_t *)dst;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
    w >>= 8;
    *p++ = (uint8_t)w;
}

static BLAKE2_INLINE uint32_t rotr32(const uint32_t w, const unsigned c) {
    return (w >> c) | (w << (32 - c));
}

static BLAKE2_INLINE uint64_t rotr64(const uint64_t w, const unsigned c) {
    return (w >> c) | (w << (64 - c));
}

void clear_internal_memory(void *v, size_t n);

#endif
