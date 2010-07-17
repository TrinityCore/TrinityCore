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

/** See G3D::Crypto::md5 */
class MD5Hash {
private:

    uint8   value[16];

public:

    MD5Hash() {
        for (int i = 0; i < 16; ++i) {
            value[i] = 0;
        }
    }

    explicit MD5Hash(class BinaryInput& b);

    uint8& operator[](int i) {
        return value[i];
    }

    const uint8& operator[](int i) const {
        return value[i];
    }

    bool operator==(const MD5Hash& other) const {
        bool match = true;
        for (int i = 0; i < 16; ++i) {
            match = match && (other.value[i] == value[i]);
        }
        return match;
    }

    inline bool operator!=(const MD5Hash& other) const {
        return !(*this == other);
    }

    void deserialize(class BinaryInput& b);

    void serialize(class BinaryOutput& b) const;
};


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
     Computes the MD5 hash (message digest) of a byte stream, as defined by
     http://www.ietf.org/rfc/rfc1321.txt.

     @cite Based on implementation by L. Peter Deutsch, ghost@aladdin.com
     */
    MD5Hash md5(const void* bytes, size_t numBytes);

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
