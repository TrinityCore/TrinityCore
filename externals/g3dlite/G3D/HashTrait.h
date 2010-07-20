/**
  @file HashTrait.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2008-10-01
  @edited  2009-11-01

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_HashTrait_h
#define G3D_HashTrait_h

#include "G3D/platform.h"
#include "G3D/Crypto.h"
#include "G3D/g3dmath.h"
#include "G3D/uint128.h"

/** Must be specialized for custom types.
    @see G3D::Table for specialization requirements.
*/
template <typename T> struct HashTrait{};

template <typename T> struct HashTrait<T*> {
    static size_t hashCode(const void* k) { return reinterpret_cast<size_t>(k); }
};

#if 0
template <> struct HashTrait <int> {
    static size_t hashCode(int k) { return static_cast<size_t>(k); }
};
#endif

template <> struct HashTrait <G3D::int16> {
    static size_t hashCode(G3D::int16 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::uint16> {
    static size_t hashCode(G3D::uint16 k) { return static_cast<size_t>(k); }
};

//template <> struct HashTrait <int> {
//    static size_t hashCode(int k) { return static_cast<size_t>(k); }
//};

template <> struct HashTrait <G3D::int32> {
    static size_t hashCode(G3D::int32 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::uint32> {
    static size_t hashCode(G3D::uint32 k) { return static_cast<size_t>(k); }
};

#if 0
template <> struct HashTrait <long unsigned int> {
    static size_t hashCode(G3D::uint32 k) { return static_cast<size_t>(k); }
};
#endif

template <> struct HashTrait <G3D::int64> {
    static size_t hashCode(G3D::int64 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <G3D::uint64> {
    static size_t hashCode(G3D::uint64 k) { return static_cast<size_t>(k); }
};

template <> struct HashTrait <std::string> {
    static size_t hashCode(const std::string& k) { return static_cast<size_t>(G3D::Crypto::crc32(k.c_str(), k.size())); }
};

template <> struct HashTrait<G3D::uint128> {
    // Use the FNV-1 hash (http://isthe.com/chongo/tech/comp/fnv/#FNV-1).
    static size_t hashCode(G3D::uint128 key) {
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
    }
};

#endif
