#pragma once
/**
 * @file  SFMT-sse2-msc.h
 * @brief SIMD oriented Fast Mersenne Twister(SFMT) for Intel SSE2 for MSC
 *
 * @author Mutsuo Saito (Hiroshima University)
 * @author Makoto Matsumoto (Hiroshima University)
 *
 * @note We assume LITTLE ENDIAN in this file
 *
 * Copyright (C) 2006, 2007 Mutsuo Saito, Makoto Matsumoto and Hiroshima
 * University. All rights reserved.
 * Copyright (C) 2013 Mutsuo Saito, Makoto Matsumoto and Hiroshima
 * University.
 *
 * The new BSD License is applied to this software, see LICENSE.txt
 */

#ifndef SFMT_SSE2_MSC_H
#define SFMT_SSE2_MSC_H

/* This header file is included only when _MSC_VER is defined. */
#if _MSC_VER > 1700

inline static __m128i __vectorcall mm_recursion(__m128i a, __m128i b,
                                                __m128i c, __m128i d);

/**
 * This function represents the recursion formula.
 * @param a a 128-bit part of the interal state array
 * @param b a 128-bit part of the interal state array
 * @param c a 128-bit part of the interal state array
 * @param d a 128-bit part of the interal state array
 * @return new value
 */
inline static __m128i __vectorcall mm_recursion(__m128i a, __m128i b,
                                                __m128i c, __m128i d)
{
    __m128i v, x, y, z;

    y = _mm_srli_epi32(b, SFMT_SR1);
    z = _mm_srli_si128(c, SFMT_SR2);
    v = _mm_slli_epi32(d, SFMT_SL1);
    z = _mm_xor_si128(z, a);
    z = _mm_xor_si128(z, v);
    x = _mm_slli_si128(a, SFMT_SL2);
    y = _mm_and_si128(y, sse2_param_mask.si);
    z = _mm_xor_si128(z, x);
    return _mm_xor_si128(z, y);
}

/**
 * This function fills the internal state array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state
 */
void sfmt_gen_rand_all(sfmt_t * sfmt) {
    int i;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        pstate[i].si = mm_recursion(pstate[i].si,
                                    pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
    for (; i < SFMT_N; i++) {
        pstate[i].si = mm_recursion(pstate[i].si,
                                    pstate[i + SFMT_POS1 - SFMT_N].si,
                                    r1, r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
}

/**
 * This function fills the user-specified array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state.
 * @param array an 128-bit array to be filled by pseudorandom numbers.
 * @param size number of 128-bit pseudorandom numbers to be generated.
 */
static void gen_rand_array(sfmt_t * sfmt, w128_t * array, int size)
{
    int i, j;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        array[i].si = mm_recursion(pstate[i].si,
                                   pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < SFMT_N; i++) {
        array[i].si = mm_recursion(pstate[i].si,
                                   array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < size - SFMT_N; i++) {
        array[i].si = mm_recursion(array[i - SFMT_N].si,
                                   array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (j = 0; j < 2 * SFMT_N - size; j++) {
        pstate[j] = array[j + size - SFMT_N];
    }
    for (; i < size; i++, j++) {
        array[i].si = mm_recursion(array[i - SFMT_N].si,
                                   array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
        pstate[j] = array[i];
    }
}

#elif defined(SFMT_USE_MACRO_FUNCTION_FOR_MSC)
/**
 * This function represents the recursion formula.
 * @param r an output
 * @param a a 128-bit part of the interal state array
 * @param b a 128-bit part of the interal state array
 * @param c a 128-bit part of the interal state array
 * @param d a 128-bit part of the interal state array
 */
#define mm_recursion(r, a, b, c, d)           \
do {                                          \
    __m128i v, x, y, z;                       \
                                              \
    y = _mm_srli_epi32((b), SFMT_SR1);        \
    z = _mm_srli_si128((c), SFMT_SR2);        \
    v = _mm_slli_epi32((d), SFMT_SL1);        \
    z = _mm_xor_si128(z, (a));                \
    z = _mm_xor_si128(z, v);                  \
    x = _mm_slli_si128((a), SFMT_SL2);        \
    y = _mm_and_si128(y, sse2_param_mask.si); \
    z = _mm_xor_si128(z, x);                  \
    r = _mm_xor_si128(z, y);                  \
} while (0)

/**
 * This function fills the internal state array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state
 */
void sfmt_gen_rand_all(sfmt_t * sfmt) {
    int i;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        mm_recursion(pstate[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
    for (; i < SFMT_N; i++) {
        mm_recursion(pstate[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1 - SFMT_N].si,
                     r1, r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
}

/**
 * This function fills the user-specified array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state.
 * @param array an 128-bit array to be filled by pseudorandom numbers.
 * @param size number of 128-bit pseudorandom numbers to be generated.
 */
static void gen_rand_array(sfmt_t * sfmt, w128_t * array, int size)
{
    int i, j;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        mm_recursion(array[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < SFMT_N; i++) {
        mm_recursion(array[i].si, pstate[i].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < size - SFMT_N; i++) {
        mm_recursion(array[i].si, array[i - SFMT_N].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (j = 0; j < 2 * SFMT_N - size; j++) {
        pstate[j] = array[j + size - SFMT_N];
    }
    for (; i < size; i++, j++) {
        mm_recursion(array[i].si, array[i - SFMT_N].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
        pstate[j] = array[i];
    }
}
#else
inline static void mm_recursion(__m128i * r, __m128i a, __m128i b,
                                __m128i c, __m128i * d);

/**
 * This function represents the recursion formula.
 * @param r an output
 * @param a a 128-bit part of the interal state array
 * @param b a 128-bit part of the interal state array
 * @param c a 128-bit part of the interal state array
 * @param d a 128-bit part of the interal state array
 */
inline static void mm_recursion(__m128i * r, __m128i a, __m128i b,
                                __m128i c, __m128i * d)
{
    __m128i v, x, y, z;

    y = _mm_srli_epi32(b, SFMT_SR1);
    z = _mm_srli_si128(c, SFMT_SR2);
    v = _mm_slli_epi32(*d, SFMT_SL1);
    z = _mm_xor_si128(z, a);
    z = _mm_xor_si128(z, v);
    x = _mm_slli_si128(a, SFMT_SL2);
    y = _mm_and_si128(y, sse2_param_mask.si);
    z = _mm_xor_si128(z, x);
    z = _mm_xor_si128(z, y);
    *r = z;
}

/**
 * This function fills the internal state array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state
 */
void sfmt_gen_rand_all(sfmt_t * sfmt) {
    int i;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        mm_recursion(&pstate[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1].si, r1, &r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
    for (; i < SFMT_N; i++) {
        mm_recursion(&pstate[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1 - SFMT_N].si,
                     r1, &r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
}

/**
 * This function fills the user-specified array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state.
 * @param array an 128-bit array to be filled by pseudorandom numbers.
 * @param size number of 128-bit pseudorandom numbers to be generated.
 */
static void gen_rand_array(sfmt_t * sfmt, w128_t * array, int size)
{
    int i, j;
    __m128i r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        mm_recursion(&array[i].si, pstate[i].si,
                     pstate[i + SFMT_POS1].si, r1, &r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < SFMT_N; i++) {
        mm_recursion(&array[i].si, pstate[i].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, &r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < size - SFMT_N; i++) {
        mm_recursion(&array[i].si, array[i - SFMT_N].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, &r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (j = 0; j < 2 * SFMT_N - size; j++) {
        pstate[j] = array[j + size - SFMT_N];
    }
    for (; i < size; i++, j++) {
        mm_recursion(&array[i].si, array[i - SFMT_N].si,
                     array[i + SFMT_POS1 - SFMT_N].si, r1, &r2);
        r1 = r2;
        r2 = array[i].si;
        pstate[j] = array[i];
    }
}
#endif

#endif
