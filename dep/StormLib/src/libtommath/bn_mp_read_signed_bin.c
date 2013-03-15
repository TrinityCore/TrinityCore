#include "tommath.h"
#ifdef BN_MP_READ_SIGNED_BIN_C
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

/* read signed bin, big endian, first byte is 0==positive or 1==negative */
int mp_read_signed_bin (mp_int * a, const unsigned char *b, int c)
{
  int     res;

  /* read magnitude */
  if ((res = mp_read_unsigned_bin (a, b + 1, c - 1)) != MP_OKAY) {
    return res;
  }

  /* first byte is 0 for positive, non-zero for negative */
  if (b[0] == 0) {
     a->sign = MP_ZPOS;
  } else {
     a->sign = MP_NEG;
  }

  return MP_OKAY;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_read_signed_bin.c,v $ */
/* $Revision: 1.5 $ */
/* $Date: 2006/12/28 01:25:13 $ */
