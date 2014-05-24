#include "tommath.h"
#ifdef BN_MP_FREAD_C
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

/* read a bigint from a file stream in ASCII */
int mp_fread(mp_int *a, int radix, FILE *stream)
{
   int err, ch, neg, y;
   
   /* clear a */
   mp_zero(a);
   
   /* if first digit is - then set negative */
   ch = fgetc(stream);
   if (ch == '-') {
      neg = MP_NEG;
      ch = fgetc(stream);
   } else {
      neg = MP_ZPOS;
   }
   
   for (;;) {
      /* find y in the radix map */
      for (y = 0; y < radix; y++) {
          if (mp_s_rmap[y] == ch) {
             break;
          }
      }
      if (y == radix) {
         break;
      }
      
      /* shift up and add */
      if ((err = mp_mul_d(a, radix, a)) != MP_OKAY) {
         return err;
      }
      if ((err = mp_add_d(a, y, a)) != MP_OKAY) {
         return err;
      }
      
      ch = fgetc(stream);
   }
   if (mp_cmp_d(a, 0) != MP_EQ) {
      a->sign = neg;
   }
   
   return MP_OKAY;
}

#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_fread.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
