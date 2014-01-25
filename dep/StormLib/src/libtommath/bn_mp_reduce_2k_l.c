#include "tommath.h"
#ifdef BN_MP_REDUCE_2K_L_C
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

/* reduces a modulo n where n is of the form 2**p - d 
   This differs from reduce_2k since "d" can be larger
   than a single digit.
*/
int mp_reduce_2k_l(mp_int *a, mp_int *n, mp_int *d)
{
   mp_int q;
   int    p, res;
   
   if ((res = mp_init(&q)) != MP_OKAY) {
      return res;
   }
   
   p = mp_count_bits(n);    
top:
   /* q = a/2**p, a = a mod 2**p */
   if ((res = mp_div_2d(a, p, &q, a)) != MP_OKAY) {
      goto ERR;
   }
   
   /* q = q * d */
   if ((res = mp_mul(&q, d, &q)) != MP_OKAY) { 
      goto ERR;
   }
   
   /* a = a + q */
   if ((res = s_mp_add(a, &q, a)) != MP_OKAY) {
      goto ERR;
   }
   
   if (mp_cmp_mag(a, n) != MP_LT) {
      s_mp_sub(a, n, a);
      goto top;
   }
   
ERR:
   mp_clear(&q);
   return res;
}

#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_reduce_2k_l.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
