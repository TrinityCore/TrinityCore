#include "tommath.h"
#ifdef BN_MP_INIT_SET_C
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

/* initialize and set a digit */
int mp_init_set (mp_int * a, mp_digit b)
{
  int err;
  if ((err = mp_init(a)) != MP_OKAY) {
     return err;
  }
  mp_set(a, b);
  return err;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_init_set.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
