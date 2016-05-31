/**
  @file G3D/Vector3int32.h
  
  @maintainer Morgan McGuire, matrix@brown.edu

  @created 2008-07-01
  @edited  2011-01-01
  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Vector3int32_h
#define G3D_Vector3int32_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"
#include "G3D/Crypto.h"

namespace G3D {

    class Any;

/**
 \ Vector3int32
 A Vector3 that packs its fields into uint32s.
 */
G3D_BEGIN_PACKED_CLASS(4)
Vector3int32 {
private:
    // Hidden operators
    bool operator<(const Vector3int32&) const;
    bool operator>(const Vector3int32&) const;
    bool operator<=(const Vector3int32&) const;
    bool operator>=(const Vector3int32&) const;

public:
    G3D::int32              x;
    G3D::int32              y;
    G3D::int32              z;

    Vector3int32() : x(0), y(0), z(0) {}
    Vector3int32(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    Vector3int32(const class Vector2int32& v, int _z);
    Vector3int32(const class Vector2int16& v, int _z);
    Vector3int32(const class Vector3int16& v);
    Vector3int32(const Any& any);
    Any toAny() const;

    /** Rounds to the nearest int */
    explicit Vector3int32(const class Vector3& v);
    explicit Vector3int32(class BinaryInput& bi);

    static Vector3int32 truncate(const class Vector3& v);

    bool nonZero() const {
        return (x != 0) || (y != 0) || (z != 0);
    }

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    inline G3D::int32& operator[] (int i) {
        debugAssert(i <= 2);
        return ((G3D::int32*)this)[i];
    }

    inline const G3D::int32& operator[] (int i) const {
        debugAssert(i <= 2);
        return ((G3D::int32*)this)[i];
    }

    inline Vector3int32 operator+(const Vector3int32& other) const {
        return Vector3int32(x + other.x, y + other.y, z + other.z);
    }

    inline Vector3int32 operator-(const Vector3int32& other) const {
        return Vector3int32(x - other.x, y - other.y, z - other.z);
    }

    inline Vector3int32 operator*(const Vector3int32& other) const {
        return Vector3int32(x * other.x, y * other.y, z * other.z);
    }

    inline Vector3int32 operator*(const int s) const {
        return Vector3int32(x * s, y * s, z * s);
    }

    /** Integer division */
    inline Vector3int32 operator/(const Vector3int32& other) const {
        return Vector3int32(x / other.x, y / other.y, z / other.z);
    }

    /** Integer division */
    inline Vector3int32 operator/(const int s) const {
        return Vector3int32(x / s, y / s, z / s);
    }

    Vector3int32& operator+=(const Vector3int32& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vector3int32& operator-=(const Vector3int32& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vector3int32& operator*=(const Vector3int32& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    bool operator== (const Vector3int32& rkVector) const {
        return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
    }

    bool operator!= (const Vector3int32& rkVector) const {
        return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
    }

    Vector3int32 max(const Vector3int32& v) const {
        return Vector3int32(iMax(x, v.x), iMax(y, v.y), iMax(z, v.z));
    }

    Vector3int32 min(const Vector3int32& v) const {
        return Vector3int32(iMin(x, v.x), iMin(y, v.y), iMin(z, v.z));
    }

    Vector3int32 operator-() const {
        return Vector3int32(-x, -y, -z);
    }

    std::string toString() const;

    Vector3int32 operator<<(int i) const {
        return Vector3int32(x << i, y << i, z << i);
    }

    Vector3int32 operator>>(int i) const {
        return Vector3int32(x >> i, y >> i, z >> i);
    }

    Vector3int32 operator>>(const Vector3int32& v) const {
        return Vector3int32(x >> v.x, y >> v.y, z >> v.z);
    }

    Vector3int32 operator<<(const Vector3int32& v) const {
        return Vector3int32(x << v.x, y << v.y, z << v.z);
    }

    Vector3int32 operator&(int16 i) const {
        return Vector3int32(x & i, y & i, z & i);
    }

    // 2-char swizzles

    Vector2int32 xx() const;
    Vector2int32 yx() const;
    Vector2int32 zx() const;
    Vector2int32 xy() const;
    Vector2int32 yy() const;
    Vector2int32 zy() const;
    Vector2int32 xz() const;
    Vector2int32 yz() const;
    Vector2int32 zz() const;
}
G3D_END_PACKED_CLASS(4)

typedef Vector3int32 Point3int32;

Vector3int32 iFloor(const Vector3&);

} // namespace G3D

template <> struct HashTrait<G3D::Vector3int32> {
    static size_t hashCode(const G3D::Vector3int32& key) {
        return G3D::superFastHash(&key, sizeof(key));
        //return G3D::Crypto::crc32(&key, sizeof(key));
        /*
        // Mask for the top bit of a uint32
        const G3D::uint32 top = (1UL << 31);
        // Mask for the bottom 10 bits of a uint32
        const G3D::uint32 bot = 0x000003FF;
        return static_cast<size_t>(((key.x & top) | ((key.y & top) >> 1) | ((key.z & top) >> 2)) | 
                                   (((key.x & bot) << 19) ^ ((key.y & bot) << 10) ^ (key.z & bot)));
        */
    }
};

#endif
