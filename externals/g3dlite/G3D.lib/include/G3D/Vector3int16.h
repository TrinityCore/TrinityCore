/**
  @file Vector3int16.h
  
  @maintainer Morgan McGuire, matrix@brown.edu

  @created 2003-04-07
  @edited  2003-06-24
  Copyright 2000-2004, Morgan McGuire.
  All rights reserved.
 */

#ifndef VECTOR3INT16_H
#define VECTOR3INT16_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"

namespace G3D {

/**
 A Vector3 that packs its fields into uint16s.
 */
#ifdef G3D_WIN32
    // Switch to tight alignment
    #pragma pack(push, 2)
#endif

class Vector3int16 {
private:
    // Hidden operators
    bool operator<(const Vector3int16&) const;
    bool operator>(const Vector3int16&) const;
    bool operator<=(const Vector3int16&) const;
    bool operator>=(const Vector3int16&) const;

public:
    G3D::int16              x;
    G3D::int16              y;
    G3D::int16              z;

    Vector3int16() : x(0), y(0), z(0) {}
    Vector3int16(G3D::int16 _x, G3D::int16 _y, G3D::int16 _z) : x(_x), y(_y), z(_z) {}
    Vector3int16(const class Vector3& v);
    Vector3int16(class BinaryInput& bi);

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    inline G3D::int16& operator[] (int i) {
        debugAssert(i <= 2);
        return ((G3D::int16*)this)[i];
    }

    inline const G3D::int16& operator[] (int i) const {
        debugAssert(i <= 2);
        return ((G3D::int16*)this)[i];
    }

    inline Vector3int16 operator+(const Vector3int16& other) const {
        return Vector3int16(x + other.x, y + other.y, z + other.z);
    }

    inline Vector3int16 operator-(const Vector3int16& other) const {
        return Vector3int16(x - other.x, y - other.y, z - other.z);
    }

    inline Vector3int16 operator*(const Vector3int16& other) const {
        return Vector3int16(x * other.x, y * other.y, z * other.z);
    }

    inline Vector3int16 operator*(const int s) const {
        return Vector3int16(x * s, y * s, z * s);
    }

    inline Vector3int16& operator+=(const Vector3int16& other) {
        x += other.x;
        y += other.y;
        z += other.y;
        return *this;
    }

    inline Vector3int16& operator-=(const Vector3int16& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    inline Vector3int16& operator*=(const Vector3int16& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    inline bool operator== (const Vector3int16& rkVector) const {
        return ( x == rkVector.x && y == rkVector.y && z == rkVector.z );
    }

    inline bool operator!= (const Vector3int16& rkVector) const {
        return ( x != rkVector.x || y != rkVector.y || z != rkVector.z );
    }

    Vector3int16 max(const Vector3int16& v) const {
        return Vector3int16(iMax(x, v.x), iMax(y, v.y), iMax(z, v.z));
    }

    Vector3int16 min(const Vector3int16& v) const {
        return Vector3int16(iMin(x, v.x), iMin(y, v.y), iMin(z, v.z));
    }

    std::string toString() const;
}
#if defined(G3D_LINUX) || defined(G3D_OSX)
    __attribute((aligned(1)))
#endif
;

#ifdef G3D_WIN32
    #pragma pack(pop)
#endif

}

template <> struct HashTrait<G3D::Vector3int16> {
    static size_t hashCode(const G3D::Vector3int16& key) { return static_cast<size_t>(key.x + ((int)key.y << 5) + ((int)key.z << 10)); }
};

#endif
