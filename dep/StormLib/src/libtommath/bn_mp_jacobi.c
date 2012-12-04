#include "tommath.h"
#ifdef BN_MP_JACOBI_C
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

/* computes the jacobi c = (a | n) (or Legendre if n is prime)
 * HAC pp. 73 Algorithm 2.149
 */
int mp_jacobi (mp_int * a, mp_int * p, int *c)
{
  mp_int  a1, p1;
  int     k, s, r, res;
  mp_digit residue;

  /* if p <= 0 return MP_VAL */
  if (mp_cmp_d(p, 0) != MP_GT) {
     return MP_VAL;
  }

  /* step 1.  if a == 0, return 0 */
  if (mp_iszero (a) == 1) {
    *c = 0;
    return MP_OKAY;
  }

  /* step 2.  if a == 1, return 1 */
  if (mp_cmp_d (a, 1) == MP_EQ) {
    *c = 1;
    return MP_OKAY;
  }

  /* default */
  s = 0;

  /* step 3.  write a = a1 * 2**k  */
  if ((res = mp_init_copy (&a1, a)) != MP_OKAY) {
    return res;
  }

  if ((res = mp_init (&p1)) != MP_OKAY) {
    goto LBL_A1;
  }

  /* divide out larger power of two */
  k = mp_cnt_lsb(&a1);
  if ((res = mp_div_2d(&a1, k, &a1, NULL)) != MP_OKAY) {
     goto LBL_P1;
  }

  /* step 4.  if e is even set s=1 */
  if ((k & 1) == 0) {
    s = 1;
  } else {
    /* else set s=1 if p = 1/7 (mod 8) or s=-1 if p = 3/5 (mod 8) */
    residue = p->dp[0] & 7;

    if (residue == 1 || residue == 7) {
      s = 1;
    } else if (residue == 3 || residue == 5) {
      s = -1;
    }
  }

  /* step 5.  if p == 3 (mod 4) *and* a1 == 3 (mod 4) then s = -s */
  if ( ((p->dp[0] & 3) == 3) && ((a1.dp[0] & 3) == 3)) {
    s = -s;
  }

  /* if a1 == 1 we're done */
  if (mp_cmp_d (&a1, 1) == MP_EQ) {
    *c = s;
  } else {
    /* n1 = n mod a1 */
    if ((res = mp_mod (p, &a1, &p1)) != MP_OKAY) {
      goto LBL_P1;
    }
    if ((res = mp_jacobi (&p1, &a1, &r)) != MP_OKAY) {
      goto LBL_P1;
    }
    *c = s * r;
  }

  /* done */
  res = MP_OKAY;
LBL_P1:mp_clear (&p1);
LBL_A1:mp_clear (&a1);
  return res;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_jacobi.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
