#include "tommath.h"
#ifdef BN_MP_PRIME_NEXT_PRIME_C
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

/* finds the next prime after the number "a" using "t" trials
 * of Miller-Rabin.
 *
 * bbs_style = 1 means the prime must be congruent to 3 mod 4
 */
int mp_prime_next_prime(mp_int *a, int t, int bbs_style)
{
   int      err, res, x, y;
   mp_digit res_tab[PRIME_SIZE], step, kstep;
   mp_int   b;

   /* ensure t is valid */
   if (t <= 0 || t > PRIME_SIZE) {
      return MP_VAL;
   }

   /* force positive */
   a->sign = MP_ZPOS;

   /* simple algo if a is less than the largest prime in the table */
   if (mp_cmp_d(a, ltm_prime_tab[PRIME_SIZE-1]) == MP_LT) {
      /* find which prime it is bigger than */
      for (x = PRIME_SIZE - 2; x >= 0; x--) {
          if (mp_cmp_d(a, ltm_prime_tab[x]) != MP_LT) {
             if (bbs_style == 1) {
                /* ok we found a prime smaller or
                 * equal [so the next is larger]
                 *
                 * however, the prime must be
                 * congruent to 3 mod 4
                 */
                if ((ltm_prime_tab[x + 1] & 3) != 3) {
                   /* scan upwards for a prime congruent to 3 mod 4 */
                   for (y = x + 1; y < PRIME_SIZE; y++) {
                       if ((ltm_prime_tab[y] & 3) == 3) {
                          mp_set(a, ltm_prime_tab[y]);
                          return MP_OKAY;
                       }
                   }
                }
             } else {
                mp_set(a, ltm_prime_tab[x + 1]);
                return MP_OKAY;
             }
          }
      }
      /* at this point a maybe 1 */
      if (mp_cmp_d(a, 1) == MP_EQ) {
         mp_set(a, 2);
         return MP_OKAY;
      }
      /* fall through to the sieve */
   }

   /* generate a prime congruent to 3 mod 4 or 1/3 mod 4? */
   if (bbs_style == 1) {
      kstep   = 4;
   } else {
      kstep   = 2;
   }

   /* at this point we will use a combination of a sieve and Miller-Rabin */

   if (bbs_style == 1) {
      /* if a mod 4 != 3 subtract the correct value to make it so */
      if ((a->dp[0] & 3) != 3) {
         if ((err = mp_sub_d(a, (a->dp[0] & 3) + 1, a)) != MP_OKAY) { return err; };
      }
   } else {
      if (mp_iseven(a) == 1) {
         /* force odd */
         if ((err = mp_sub_d(a, 1, a)) != MP_OKAY) {
            return err;
         }
      }
   }

   /* generate the restable */
   for (x = 1; x < PRIME_SIZE; x++) {
      if ((err = mp_mod_d(a, ltm_prime_tab[x], res_tab + x)) != MP_OKAY) {
         return err;
      }
   }

   /* init temp used for Miller-Rabin Testing */
   if ((err = mp_init(&b)) != MP_OKAY) {
      return err;
   }

   for (;;) {
      /* skip to the next non-trivially divisible candidate */
      step = 0;
      do {
         /* y == 1 if any residue was zero [e.g. cannot be prime] */
         y     =  0;

         /* increase step to next candidate */
         step += kstep;

         /* compute the new residue without using division */
         for (x = 1; x < PRIME_SIZE; x++) {
             /* add the step to each residue */
             res_tab[x] += kstep;

             /* subtract the modulus [instead of using division] */
             if (res_tab[x] >= ltm_prime_tab[x]) {
                res_tab[x]  -= ltm_prime_tab[x];
             }

             /* set flag if zero */
             if (res_tab[x] == 0) {
                y = 1;
             }
         }
      } while (y == 1 && step < ((((mp_digit)1)<<DIGIT_BIT) - kstep));

      /* add the step */
      if ((err = mp_add_d(a, step, a)) != MP_OKAY) {
         goto LBL_ERR;
      }

      /* if didn't pass sieve and step == MAX then skip test */
      if (y == 1 && step >= ((((mp_digit)1)<<DIGIT_BIT) - kstep)) {
         continue;
      }

      /* is this prime? */
      for (x = 0; x < t; x++) {
          mp_set(&b, ltm_prime_tab[t]);
          if ((err = mp_prime_miller_rabin(a, &b, &res)) != MP_OKAY) {
             goto LBL_ERR;
          }
          if (res == MP_NO) {
             break;
          }
      }

      if (res == MP_YES) {
         break;
      }
   }

   err = MP_OKAY;
LBL_ERR:
   mp_clear(&b);
   return err;
}

#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_prime_next_prime.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
