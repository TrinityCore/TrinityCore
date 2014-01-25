#include "tommath.h"
#ifdef BN_S_MP_MUL_HIGH_DIGS_C
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

/* multiplies |a| * |b| and does not compute the lower digs digits
 * [meant to get the higher part of the product]
 */
int
s_mp_mul_high_digs (mp_int * a, mp_int * b, mp_int * c, int digs)
{
  mp_int  t;
  int     res, pa, pb, ix, iy;
  mp_digit u;
  mp_word r;
  mp_digit tmpx, *tmpt, *tmpy;

  /* can we use the fast multiplier? */
#ifdef BN_FAST_S_MP_MUL_HIGH_DIGS_C
  if (((a->used + b->used + 1) < MP_WARRAY)
      && MIN (a->used, b->used) < (1 << ((CHAR_BIT * sizeof (mp_word)) - (2 * DIGIT_BIT)))) {
    return fast_s_mp_mul_high_digs (a, b, c, digs);
  }
#endif

  if ((res = mp_init_size (&t, a->used + b->used + 1)) != MP_OKAY) {
    return res;
  }
  t.used = a->used + b->used + 1;

  pa = a->used;
  pb = b->used;
  for (ix = 0; ix < pa; ix++) {
    /* clear the carry */
    u = 0;

    /* left hand side of A[ix] * B[iy] */
    tmpx = a->dp[ix];

    /* alias to the address of where the digits will be stored */
    tmpt = &(t.dp[digs]);

    /* alias for where to read the right hand side from */
    tmpy = b->dp + (digs - ix);

    for (iy = digs - ix; iy < pb; iy++) {
      /* calculate the double precision result */
      r       = ((mp_word)*tmpt) +
                ((mp_word)tmpx) * ((mp_word)*tmpy++) +
                ((mp_word) u);

      /* get the lower part */
      *tmpt++ = (mp_digit) (r & ((mp_word) MP_MASK));

      /* carry the carry */
      u       = (mp_digit) (r >> ((mp_word) DIGIT_BIT));
    }
    *tmpt = u;
  }
  mp_clamp (&t);
  mp_exch (&t, c);
  mp_clear (&t);
  return MP_OKAY;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_s_mp_mul_high_digs.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
