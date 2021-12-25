#pragma once
/**
 * @file SFMT-alti.h
 *
 * @brief SIMD oriented Fast Mersenne Twister(SFMT)
 * pseudorandom number generator
 *
 * @author Mutsuo Saito (Hiroshima University)
 * @author Makoto Matsumoto (Hiroshima University)
 *
 * Copyright (C) 2007 Mutsuo Saito, Makoto Matsumoto and Hiroshima
 * University. All rights reserved.
 *
 * The new BSD License is applied to this software.
 * see LICENSE.txt
 */

#ifndef SFMT_ALTI_H
#define SFMT_ALTI_H

inline static vector unsigned int vec_recursion(vector unsigned int a,
						vector unsigned int b,
						vector unsigned int c,
						vector unsigned int d);

/**
 * This function represents the recursion formula in AltiVec and BIG ENDIAN.
 * @param a a 128-bit part of the interal state array
 * @param b a 128-bit part of the interal state array
 * @param c a 128-bit part of the interal state array
 * @param d a 128-bit part of the interal state array
 * @return output
 */
inline static vector unsigned int vec_recursion(vector unsigned int a,
						vector unsigned int b,
						vector unsigned int c,
						vector unsigned int d) {

    const vector unsigned int sl1 = SFMT_ALTI_SL1;
    const vector unsigned int sr1 = SFMT_ALTI_SR1;
#ifdef ONLY64
    const vector unsigned int mask = SFMT_ALTI_MSK64;
    const vector unsigned char perm_sl = SFMT_ALTI_SL2_PERM64;
    const vector unsigned char perm_sr = SFMT_ALTI_SR2_PERM64;
#else
    const vector unsigned int mask = SFMT_ALTI_MSK;
    const vector unsigned char perm_sl = SFMT_ALTI_SL2_PERM;
    const vector unsigned char perm_sr = SFMT_ALTI_SR2_PERM;
#endif
    vector unsigned int v, w, x, y, z;
    x = vec_perm(a, (vector unsigned int)perm_sl, perm_sl);
    v = a;
    y = vec_sr(b, sr1);
    z = vec_perm(c, (vector unsigned int)perm_sr, perm_sr);
    w = vec_sl(d, sl1);
    z = vec_xor(z, w);
    y = vec_and(y, mask);
    v = vec_xor(v, x);
    z = vec_xor(z, y);
    z = vec_xor(z, v);
    return z;
}

/**
 * This function fills the internal state array with pseudorandom
 * integers.
 */
void sfmt_gen_rand_all(sfmt_t * sfmt) {
    int i;
    vector unsigned int r, r1, r2;

    r1 = sfmt->state[N - 2].s;
    r2 = sfmt->state[N - 1].s;
    for (i = 0; i < N - POS1; i++) {
	r = vec_recursion(sfmt->state[i].s, sfmt->state[i + POS1].s, r1, r2);
	sfmt->state[i].s = r;
	r1 = r2;
	r2 = r;
    }
    for (; i < N; i++) {
	r = vec_recursion(sfmt->state[i].s, sfmt->state[i + POS1 - N].s, r1, r2);
	sfmt->state[i].s = r;
	r1 = r2;
	r2 = r;
    }
}

/**
 * This function fills the user-specified array with pseudorandom
 * integers.
 *
 * @param array an 128-bit array to be filled by pseudorandom numbers.
 * @param size number of 128-bit pesudorandom numbers to be generated.
 */
inline static void gen_rand_array(sfmt_t * sfmt, w128_t *array, int size) {
    int i, j;
    vector unsigned int r, r1, r2;

    r1 = sfmt->state[N - 2].s;
    r2 = sfmt->state[N - 1].s;
    for (i = 0; i < N - POS1; i++) {
	r = vec_recursion(sfmt->state[i].s, sfmt->state[i + POS1].s, r1, r2);
	array[i].s = r;
	r1 = r2;
	r2 = r;
    }
    for (; i < N; i++) {
	r = vec_recursion(sfmt->state[i].s, array[i + POS1 - N].s, r1, r2);
	array[i].s = r;
	r1 = r2;
	r2 = r;
    }
    /* main loop */
    for (; i < size - N; i++) {
	r = vec_recursion(array[i - N].s, array[i + POS1 - N].s, r1, r2);
	array[i].s = r;
	r1 = r2;
	r2 = r;
    }
    for (j = 0; j < 2 * N - size; j++) {
	sfmt->state[j].s = array[j + size - N].s;
    }
    for (; i < size; i++) {
	r = vec_recursion(array[i - N].s, array[i + POS1 - N].s, r1, r2);
	array[i].s = r;
	sfmt->state[j++].s = r;
	r1 = r2;
	r2 = r;
    }
}

#ifndef ONLY64
#if defined(__APPLE__)
#define SFMT_ALTI_SWAP (vector unsigned char) \
	(4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11)
#else
#define SFMT_ALTI_SWAP {4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11}
#endif
/**
 * This function swaps high and low 32-bit of 64-bit integers in user
 * specified array.
 *
 * @param array an 128-bit array to be swaped.
 * @param size size of 128-bit array.
 */
inline static void swap(w128_t *array, int size) {
    int i;
    const vector unsigned char perm = SFMT_ALTI_SWAP;

    for (i = 0; i < size; i++) {
	array[i].s = vec_perm(array[i].s, (vector unsigned int)perm, perm);
    }
}
#endif

#endif
