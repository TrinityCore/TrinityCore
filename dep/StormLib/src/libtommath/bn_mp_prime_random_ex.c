#include "tommath.h"
#ifdef BN_MP_PRIME_RANDOM_EX_C
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

/* makes a truly random prime of a given size (bits),
 *
 * Flags are as follows:
 * 
 *   LTM_PRIME_BBS      - make prime congruent to 3 mod 4
 *   LTM_PRIME_SAFE     - make sure (p-1)/2 is prime as well (implies LTM_PRIME_BBS)
 *   LTM_PRIME_2MSB_OFF - make the 2nd highest bit zero
 *   LTM_PRIME_2MSB_ON  - make the 2nd highest bit one
 *
 * You have to supply a callback which fills in a buffer with random bytes.  "dat" is a parameter you can
 * have passed to the callback (e.g. a state or something).  This function doesn't use "dat" itself
 * so it can be NULL
 *
 */

/* This is possibly the mother of all prime generation functions, muahahahahaha! */
int mp_prime_random_ex(mp_int *a, int t, int size, int flags, ltm_prime_callback cb, void *dat)
{
   unsigned char *tmp, maskAND, maskOR_msb, maskOR_lsb;
   int res, err, bsize, maskOR_msb_offset;

   /* sanity check the input */
   if (size <= 1 || t <= 0) {
      return MP_VAL;
   }

   /* LTM_PRIME_SAFE implies LTM_PRIME_BBS */
   if (flags & LTM_PRIME_SAFE) {
      flags |= LTM_PRIME_BBS;
   }

   /* calc the byte size */
   bsize = (size>>3) + ((size&7)?1:0);

   /* we need a buffer of bsize bytes */
   tmp = OPT_CAST(unsigned char) XMALLOC(bsize);
   if (tmp == NULL) {
      return MP_MEM;
   }

   /* calc the maskAND value for the MSbyte*/
   maskAND = ((size&7) == 0) ? 0xFF : (0xFF >> (8 - (size & 7)));

   /* calc the maskOR_msb */
   maskOR_msb        = 0;
   maskOR_msb_offset = ((size & 7) == 1) ? 1 : 0;
   if (flags & LTM_PRIME_2MSB_ON) {
      maskOR_msb       |= 0x80 >> ((9 - size) & 7);
   }  

   /* get the maskOR_lsb */
   maskOR_lsb         = 1;
   if (flags & LTM_PRIME_BBS) {
      maskOR_lsb     |= 3;
   }

   do {
      /* read the bytes */
      if (cb(tmp, bsize, dat) != bsize) {
         err = MP_VAL;
         goto error;
      }
 
      /* work over the MSbyte */
      tmp[0]    &= maskAND;
      tmp[0]    |= 1 << ((size - 1) & 7);

      /* mix in the maskORs */
      tmp[maskOR_msb_offset]   |= maskOR_msb;
      tmp[bsize-1]             |= maskOR_lsb;

      /* read it in */
      if ((err = mp_read_unsigned_bin(a, tmp, bsize)) != MP_OKAY)     { goto error; }

      /* is it prime? */
      if ((err = mp_prime_is_prime(a, t, &res)) != MP_OKAY)           { goto error; }
      if (res == MP_NO) {  
         continue;
      }

      if (flags & LTM_PRIME_SAFE) {
         /* see if (a-1)/2 is prime */
         if ((err = mp_sub_d(a, 1, a)) != MP_OKAY)                    { goto error; }
         if ((err = mp_div_2(a, a)) != MP_OKAY)                       { goto error; }
 
         /* is it prime? */
         if ((err = mp_prime_is_prime(a, t, &res)) != MP_OKAY)        { goto error; }
      }
   } while (res == MP_NO);

   if (flags & LTM_PRIME_SAFE) {
      /* restore a to the original value */
      if ((err = mp_mul_2(a, a)) != MP_OKAY)                          { goto error; }
      if ((err = mp_add_d(a, 1, a)) != MP_OKAY)                       { goto error; }
   }

   err = MP_OKAY;
error:
   XFREE(tmp);
   return err;
}


#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_prime_random_ex.c,v $ */
/* $Revision: 1.5 $ */
/* $Date: 2006/12/28 01:25:13 $ */
