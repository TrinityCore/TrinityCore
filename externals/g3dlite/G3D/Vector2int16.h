/**
  @file Vector2int16.h
  
  @maintainer Morgan McGuire, matrix@brown.edu

  @created 2003-08-09
  @edited  2004-01-03

  Copyright 2000-2006, Morgan McGuire.
  All rights reserved.
 */

#ifndef VECTOR2INT16_H
#define VECTOR2INT16_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"

namespace G3D {

/**
 \class Vector2int16 
 A Vector2 that packs its fields into uint16s.
 */
G3D_BEGIN_PACKED_CLASS(2)
class Vector2int16 {
private:
    // Hidden operators
    bool operator<(const Vector2int16&) const;
    bool operator>(const Vector2int16&) const;
    bool operator<=(const Vector2int16&) const;
    bool operator>=(const Vector2int16&) const;

public:
    G3D::int16              x;
    G3D::int16              y;

    Vector2int16() : x(0), y(0) {}
    Vector2int16(G3D::int16 _x, G3D::int16 _y) : x(_x), y(_y){}
    Vector2int16(const class Vector2& v);
    Vector2int16(class BinaryInput& bi);

    inline G3D::int16& operator[] (int i) {
        debugAssert(((unsigned int)i) <= 1);
        return ((G3D::int16*)this)[i];
    }

    inline const G3D::int16& operator[] (int i) const {
        debugAssert(((unsigned int)i) <= 1);
        return ((G3D::int16*)this)[i];
    }

    inline Vector2int16 operator+(const Vector2int16& other) const {
        return Vector2int16(x + other.x, y + other.y);
    }

    inline Vector2int16 operator-(const Vector2int16& other) const {
        return Vector2int16(x - other.x, y - other.y);
    }

    inline Vector2int16 operator*(const Vector2int16& other) const {
        return Vector2int16(x * other.x, y * other.y);
    }

    inline Vector2int16 operator*(const int s) const {
        return Vector2int16(x * s, y * s);
    }

    inline Vector2int16& operator+=(const Vector2int16& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    /** Shifts both x and y */
    inline Vector2int16 operator>>(const int s) const {
        return Vector2int16(x >> s, y >> s);
    }

    /** Shifts both x and y */
    inline Vector2int16 operator<<(const int s) const {
        return Vector2int16(x << s, y << s);
    }

    inline Vector2int16& operator-=(const Vector2int16& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    inline Vector2int16& operator*=(const Vector2int16& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    Vector2int16 clamp(const Vector2int16& lo, const Vector2int16& hi);

    inline bool operator== (const Vector2int16& rkVector) const {
        return ((int32*)this)[0] == ((int32*)&rkVector)[0];
    }

    inline bool operator!= (const Vector2int16& rkVector) const {
        return ((int32*)this)[0] != ((int32*)&rkVector)[0];
    }

    Vector2int16 max(const Vector2int16& v) const {
        return Vector2int16(iMax(x, v.x), iMax(y, v.y));
    }

    Vector2int16 min(const Vector2int16& v) const {
        return Vector2int16(iMin(x, v.x), iMin(y, v.y));
    }

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);
}
G3D_END_PACKED_CLASS(2)

}

template<> struct HashTrait<G3D::Vector2int16> {
    static size_t hashCode(const G3D::Vector2int16& key) { return static_cast<size_t>(key.x + ((int)key.y << 16)); }
};

#endif
