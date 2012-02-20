#include "tommath.h"
#ifdef BN_MP_PRIME_RABIN_MILLER_TRIALS_C
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


static const struct {
   int k, t;
} sizes[] = {
{   128,    28 },
{   256,    16 },
{   384,    10 },
{   512,     7 },
{   640,     6 },
{   768,     5 },
{   896,     4 },
{  1024,     4 }
};

/* returns # of RM trials required for a given bit size */
int mp_prime_rabin_miller_trials(int size)
{
   int x;

   for (x = 0; x < (int)(sizeof(sizes)/(sizeof(sizes[0]))); x++) {
       if (sizes[x].k == size) {
          return sizes[x].t;
       } else if (sizes[x].k > size) {
          return (x == 0) ? sizes[0].t : sizes[x - 1].t;
       }
   }
   return sizes[x-1].t + 1;
}


#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_prime_rabin_miller_trials.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
