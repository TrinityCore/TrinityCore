/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */
#include "../../headers/tomcrypt.h"

/**
  @file rsa_verify_simple.c
  Created by Ladislav Zezula (zezula@volny.cz) as modification
  for Blizzard strong signature verification
*/

#ifdef LTC_MRSA

/**
  Simple RSA decryption
  @param sig              The signature data
  @param siglen           The length of the signature data (octets)
  @param hash             The hash of the message that was signed
  @param hashlen          The length of the hash of the message that was signed (octets)
  @param stat             [out] The result of the signature comparison, 1==valid, 0==invalid
  @param key              The public RSA key corresponding
  @return Error code
*/
int rsa_verify_simple(const unsigned char *sig,  unsigned long siglen,
                      const unsigned char *hash, unsigned long hashlen,
                            int           *stat,
                            rsa_key       *key)
{
  unsigned long modulus_bitlen, modulus_bytelen, x;
  unsigned char *tmpbuf;
  int           err;

  LTC_ARGCHK(sig  != NULL);
  LTC_ARGCHK(hash != NULL);
  LTC_ARGCHK(stat != NULL);
  LTC_ARGCHK(key  != NULL);

  /* default to invalid */
  *stat = 0;

  /* get modulus len in bits */
  modulus_bitlen = mp_count_bits( (key->N));

  /* outlen must be at least the size of the modulus */
  modulus_bytelen = mp_unsigned_bin_size( (key->N));
  if (modulus_bytelen != siglen) {
     return CRYPT_INVALID_PACKET;
  }

  /* allocate temp buffer for decoded sig */
  tmpbuf = XMALLOC(siglen);
  if (tmpbuf == NULL) {
     return CRYPT_MEM;
  }

  /* RSA decode it  */
  x = siglen;
  if ((err = ltc_mp.rsa_me(sig, siglen, tmpbuf, &x, PK_PUBLIC, key)) != CRYPT_OK) {
     XFREE(tmpbuf);
     return err;
  }

  /* make sure the output is the right size */
  if (x != siglen) {
     XFREE(tmpbuf);
     return CRYPT_INVALID_PACKET;
  }

  /* compare the decrypted signature with the given hash */
  if(x == hashlen && XMEMCMP(tmpbuf, hash, hashlen) == 0)
      *stat = 1;
       
#ifdef LTC_CLEAN_STACK
  zeromem(tmpbuf, siglen);
#endif
  XFREE(tmpbuf);
  return CRYPT_OK;
}

#endif /* LTC_MRSA */
