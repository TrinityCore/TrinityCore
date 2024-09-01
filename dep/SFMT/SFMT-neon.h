/**
 * @file  SFMT-neon.h
 * @brief SIMD oriented Fast Mersenne Twister(SFMT) for ARM with 128b NEON 
 *
 * @author Masaki Ota 
 *
 * @note We assume LITTLE ENDIAN in this file
 */

#ifndef SFMT_NEON_H
#define SFMT_NEON_H

#ifdef _MSC_VER
// The .n128_u64 field is first.  Combine pairs of 32-bit integers in little-endian order.
#define sfmt_neon_init_uint32x4_t(w,x,y,z) { .n128_u32 = { (w), (x), (y), (z) } }
#else
#define sfmt_neon_init_uint32x4_t(w,x,y,z) { (w), (x), (y), (z) }
#endif

inline static void neon_recursion(uint32x4_t * r, uint32x4_t a, uint32x4_t b,
                                uint32x4_t c, uint32x4_t d);



/**
 * This function represents the recursion formula.
 * @param r an output
 * @param a a 128-bit part of the interal state array
 * @param b a 128-bit part of the interal state array
 * @param c a 128-bit part of the interal state array
 * @param d a 128-bit part of the interal state array
 */
inline static void neon_recursion(uint32x4_t * r, uint32x4_t a, uint32x4_t b,
                                uint32x4_t c, uint32x4_t d)
{
    uint32x4_t v, x, y, z;
    static const uint32x4_t vzero = sfmt_neon_init_uint32x4_t(0, 0, 0, 0);
    static const uint32x4_t vmask = sfmt_neon_init_uint32x4_t(SFMT_MSK1, SFMT_MSK2, SFMT_MSK3, SFMT_MSK4);

#define rotate_bytes(A, B, C) vreinterpretq_u32_u8(vextq_u8(vreinterpretq_u8_u32(A),vreinterpretq_u8_u32(B),(C)))

    y = vshrq_n_u32(b, SFMT_SR1);
    z = rotate_bytes(c, vzero, SFMT_SR2);
    v = vshlq_n_u32(d, SFMT_SL1);
    z = veorq_u32(z, a);
    z = veorq_u32(z, v);
    x = rotate_bytes(vzero, a, 16-SFMT_SL2);
    y = vandq_u32(y, vmask);
    z = veorq_u32(z, x);
    z = veorq_u32(z, y);
    *r = z;
}

/**
 * This function fills the internal state array with pseudorandom
 * integers.
 * @param sfmt SFMT internal state
 */
void sfmt_gen_rand_all(sfmt_t * sfmt) {
    int i;
    uint32x4_t r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        neon_recursion(&pstate[i].si, pstate[i].si, pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = pstate[i].si;
    }
    for (; i < SFMT_N; i++) {
        neon_recursion(&pstate[i].si, pstate[i].si, pstate[i + SFMT_POS1 - SFMT_N].si, r1, r2);
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
    uint32x4_t r1, r2;
    w128_t * pstate = sfmt->state;

    r1 = pstate[SFMT_N - 2].si;
    r2 = pstate[SFMT_N - 1].si;
    for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
        neon_recursion(&array[i].si, pstate[i].si, pstate[i + SFMT_POS1].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < SFMT_N; i++) {
        neon_recursion(&array[i].si, pstate[i].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (; i < size - SFMT_N; i++) {
        neon_recursion(&array[i].si, array[i - SFMT_N].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = array[i].si;
    }
    for (j = 0; j < 2 * SFMT_N - size; j++) {
        pstate[j] = array[j + size - SFMT_N];
    }
    for (; i < size; i++, j++) {
        neon_recursion(&array[i].si, array[i - SFMT_N].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
        r1 = r2;
        r2 = pstate[j].si = array[i].si;
    }
}

#endif
