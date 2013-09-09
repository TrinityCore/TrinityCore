#include "tommath.h"
#ifdef BN_MP_IS_SQUARE_C
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

/* Check if remainders are possible squares - fast exclude non-squares */
static const char rem_128[128] = {
 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1
};

static const char rem_105[105] = {
 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,
 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,
 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1
};

/* Store non-zero to ret if arg is square, and zero if not */
int mp_is_square(mp_int *arg,int *ret) 
{
  int           res;
  mp_digit      c;
  mp_int        t;
  unsigned long r;

  /* Default to Non-square :) */
  *ret = MP_NO; 

  if (arg->sign == MP_NEG) {
    return MP_VAL;
  }

  /* digits used?  (TSD) */
  if (arg->used == 0) {
     return MP_OKAY;
  }

  /* First check mod 128 (suppose that DIGIT_BIT is at least 7) */
  if (rem_128[127 & DIGIT(arg,0)] == 1) {
     return MP_OKAY;
  }

  /* Next check mod 105 (3*5*7) */
  if ((res = mp_mod_d(arg,105,&c)) != MP_OKAY) {
     return res;
  }
  if (rem_105[c] == 1) {
     return MP_OKAY;
  }


  if ((res = mp_init_set_int(&t,11L*13L*17L*19L*23L*29L*31L)) != MP_OKAY) {
     return res;
  }
  if ((res = mp_mod(arg,&t,&t)) != MP_OKAY) {
     goto ERR;
  }
  r = mp_get_int(&t);
  /* Check for other prime modules, note it's not an ERROR but we must
   * free "t" so the easiest way is to goto ERR.  We know that res
   * is already equal to MP_OKAY from the mp_mod call 
   */ 
  if ( (1L<<(r%11)) & 0x5C4L )             goto ERR;
  if ( (1L<<(r%13)) & 0x9E4L )             goto ERR;
  if ( (1L<<(r%17)) & 0x5CE8L )            goto ERR;
  if ( (1L<<(r%19)) & 0x4F50CL )           goto ERR;
  if ( (1L<<(r%23)) & 0x7ACCA0L )          goto ERR;
  if ( (1L<<(r%29)) & 0xC2EDD0CL )         goto ERR;
  if ( (1L<<(r%31)) & 0x6DE2B848L )        goto ERR;

  /* Final check - is sqr(sqrt(arg)) == arg ? */
  if ((res = mp_sqrt(arg,&t)) != MP_OKAY) {
     goto ERR;
  }
  if ((res = mp_sqr(&t,&t)) != MP_OKAY) {
     goto ERR;
  }

  *ret = (mp_cmp_mag(&t,arg) == MP_EQ) ? MP_YES : MP_NO;
ERR:mp_clear(&t);
  return res;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_is_square.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
