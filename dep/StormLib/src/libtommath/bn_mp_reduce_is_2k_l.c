#include "tommath.h"
#ifdef BN_MP_REDUCE_IS_2K_L_C
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

/* determines if reduce_2k_l can be used */
int mp_reduce_is_2k_l(mp_int *a)
{
   int ix, iy;
   
   if (a->used == 0) {
      return MP_NO;
   } else if (a->used == 1) {
      return MP_YES;
   } else if (a->used > 1) {
      /* if more than half of the digits are -1 we're sold */
      for (iy = ix = 0; ix < a->used; ix++) {
          if (a->dp[ix] == MP_MASK) {
              ++iy;
          }
      }
      return (iy >= (a->used/2)) ? MP_YES : MP_NO;
      
   }
   return MP_NO;
}

#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_reduce_is_2k_l.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
