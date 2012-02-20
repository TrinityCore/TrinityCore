#include "tommath.h"
#ifdef BN_MP_DR_SETUP_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis
 *
 * LibTomMath is a library that provides multiple-precision
 * integer arithmetic as well as number theoretic functionality.
 *
 * The library was designed directly after the MPI library by
 * Michael Fromberger but has been written from scratch with
 * additional optimizations in place.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */

/* determines the setup value */
void mp_dr_setup(mp_int *a, mp_digit *d)
{
   /* the casts are required if DIGIT_BIT is one less than
    * the number of bits in a mp_digit [e.g. DIGIT_BIT==31]
    */
   *d = (mp_digit)((((mp_word)1) << ((mp_word)DIGIT_BIT)) - 
        ((mp_word)a->dp[0]));
}

#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_dr_setup.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
