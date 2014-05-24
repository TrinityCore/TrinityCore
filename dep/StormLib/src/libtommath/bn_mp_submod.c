#include "tommath.h"
#ifdef BN_MP_SUBMOD_C
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

/* d = a - b (mod c) */
int
mp_submod (mp_int * a, mp_int * b, mp_int * c, mp_int * d)
{
  int     res;
  mp_int  t;


  if ((res = mp_init (&t)) != MP_OKAY) {
    return res;
  }

  if ((res = mp_sub (a, b, &t)) != MP_OKAY) {
    mp_clear (&t);
    return res;
  }
  res = mp_mod (&t, c, d);
  mp_clear (&t);
  return res;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_submod.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
