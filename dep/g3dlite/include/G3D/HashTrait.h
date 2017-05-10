/**
  \file G3D/HashTrait.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2008-10-01
  \edited  2011-06-09

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_HashTrait_h
#define G3D_HashTrait_h

#include "G3D/platform.h"
#include "G3D/Crypto.h"
#include "G3D/g3dmath.h"
#include "G3D/uint128.h"
#include <typeinfo>

#include <stdint.h>
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
    || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                      +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif
namespace G3D {
/** \brief A hash function that is faster than CRC32 for arbitrary long strings
    \cite From http://www.azillionmonkeys.com/qed/hash.html by Paul Hsieh*/
inline uint32_t superFastHash (const void* _data, size_t numBytes) {
    const char* data = (const char*)_data;
    uint32_t hash = (uint32_t)numBytes;
    uint32_t tmp;
    int rem;

    if ((numBytes <= 0) || (data == NULL)) {
        return 0;
    }

    rem = numBytes & 3;
    numBytes >>= 2;

    /* Main loop */
    for (;numBytes > 0; --numBytes) {
        hash  += get16bits (data);
        tmp    = (get16bits (data+2) << 11) ^ hash;
        hash   = (hash << 16) ^ tmp;
        data  += 2*sizeof (uint16_t);
        hash  += hash >> 11;
    }

    /* Handle end cases */
    switch (rem) {
    case 3: hash += get16bits (data);
        hash ^= hash << 16;
        hash ^= data[sizeof (uint16_t)] << 18;
        hash += hash >> 11;
        break;
    case 2: hash += get16bits (data);
        hash ^= hash << 11;
        hash += hash >> 17;
        break;
    case 1: hash += *data;
        hash ^= hash << 10;
        hash += hash >> 1;
    }

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;

    return hash;
}


/**
 Thomas Wang's 64-to-32-bit mix hash based on Robert Jenkin's hash http://www.concentric.net/~ttwang/tech/inthash.htm  
 
 Found by Morgan to produce the best net performance for building tables from Vector4int16
*/
inline uint32_t wangHash6432Shift(int64 key) {
    key = (~key) + (key << 18); // key = (key << 18) - key - 1;
    key = key ^ (key >> 31);
    key = key * 21; // key = (key + (key << 2)) + (key << 4);
    key = key ^ (key >> 11);
    key = key + (key << 6);
    return uint32_t(key) ^ uint32_t(key >> 22);
}

}
#undef get16bits

/** Must be specialized for custom types.
    @see G3D::Table for specialization requirements.
*/
template <typename T> struct HashTrait{};

template <typename T> struct HashTrait<T*> {
    static size_t hashCode(const void* k) { return reinterpret_cast<size_t>(k) >> 1; }
};

/** For use with \code Table<std::type_info* const, ValueType> \endcode. */
template <> struct HashTrait <std::type_info* const> {
    static size_t hashCode(const std::type_info* const t) { 
#       ifdef _MSC_VER
            return t->hash_code(); 
#       else
            return reinterpret_cast<size_t>(t) >> 1;
#       endif
    }
};

template <> struct HashTrait <G3D::int16> {
    static size_t hashCode(G3D::int16 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::uint16> {
    static size_t hashCode(G3D::uint16 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::int32> {
    static size_t hashCode(G3D::int32 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::uint32> {
    static size_t hashCode(G3D::uint32 k) { return static_cast<size_t>(k); }
};

#ifdef G3D_OSX
template <> struct HashTrait <long unsigned int> {
    static size_t hashCode(G3D::uint32 k) { return static_cast<size_t>(k); }
};
#endif


template <> struct HashTrait <G3D::uint64> {
    static size_t hashCode(G3D::uint64 k) { return static_cast<size_t>(k) ^ static_cast<size_t>(k >> 32); }
};

template <> struct HashTrait <G3D::int64> {
    static size_t hashCode(G3D::int64 k) { return HashTrait<G3D::uint64>::hashCode(G3D::uint64(k)); }
};


template <> struct HashTrait <std::string> {
    static size_t hashCode(const std::string& k) { 
        return G3D::superFastHash(k.c_str(), k.size());
        //return static_cast<size_t>(G3D::Crypto::crc32(k.c_str(), k.size())); 
    }
};

template <> struct HashTrait<G3D::uint128> {
    static size_t hashCode(G3D::uint128 key) {
        return G3D::superFastHash(&key, sizeof(key));
        //return HashTrait<G3D::uint64>::hashCode(key.hi) ^ HashTrait<G3D::uint64>::hashCode(key.lo);

#if 0 // Really slow under gcc
    // Use the FNV-1 hash (http://isthe.com/chongo/tech/comp/fnv/#FNV-1).
        static const G3D::uint128 FNV_PRIME_128(1 << 24, 0x159);
        static const G3D::uint128 FNV_OFFSET_128(0xCF470AAC6CB293D2ULL, 0xF52F88BF32307F8FULL);

        G3D::uint128 hash = FNV_OFFSET_128;
        G3D::uint128 mask(0, 0xFF);
        for (int i = 0; i < 16; ++i) {
            hash *= FNV_PRIME_128;
            hash ^= (mask & key);
            key >>= 8;
        }
    
        G3D::uint64 foldedHash = hash.hi ^ hash.lo;
        return static_cast<size_t>((foldedHash >> 32) ^ (foldedHash & 0xFFFFFFFF));
#endif
    }
};

#endif
