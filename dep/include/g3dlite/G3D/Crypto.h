/** 
  @file Crypto.h
 
  @maintainer Morgan McGuire, matrix@graphics3d.com
 

  @created 2006-03-29
  @edited  2006-04-06
 */

#ifndef G3D_CRYPTO_H
#define G3D_CRYPTO_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include <string>

namespace G3D {

/** Cryptography and hashing helper functions */
class Crypto {
public:

    /**
     Computes the CRC32 value of a byte array.  CRC32 is designed to be a hash
     function that produces different values for similar strings.

     This implementation is compatible with PKZIP and GZIP.

     Based on http://www.gamedev.net/reference/programming/features/crc32/
    */
    static uint32 crc32(const void* bytes, size_t numBytes);

    /**
     Returns the nth prime less than 2000 in constant time.  The first prime has index
     0 and is the number 2.
     */
    static int smallPrime(int n);

    /** Returns 1 + the largest value that can be passed to smallPrime. */
    static int numSmallPrimes();
};

}

#endif
