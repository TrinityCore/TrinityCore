#include "tommath.h"
#ifdef BN_MP_TO_SIGNED_BIN_C
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

/* store in signed [big endian] format */
int mp_to_signed_bin (mp_int * a, unsigned char *b)
{
  int     res;

  if ((res = mp_to_unsigned_bin (a, b + 1)) != MP_OKAY) {
    return res;
  }
  b[0] = (unsigned char) ((a->sign == MP_ZPOS) ? 0 : 1);
  return MP_OKAY;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_to_signed_bin.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
