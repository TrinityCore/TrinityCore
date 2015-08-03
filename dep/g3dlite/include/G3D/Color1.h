/**
 \file G3D/Color1.h
 
 Monochrome Color class
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 \created 2007-01-31
 \edited  2011-08-20

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_Color1_h
#define G3D_Color1_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/unorm8.h"
#include "G3D/HashTrait.h"
#include <string>

namespace G3D {

/**
 Monochrome color. 
 */
class Color1 {
private:
    // Hidden operators
    bool operator<(const Color1&) const;
    bool operator>(const Color1&) const;
    bool operator<=(const Color1&) const;
    bool operator>=(const Color1&) const;

public:
    float value;

    /**
    Initializes to 0
     */
    inline Color1() : value(0) {}

    Color1(class BinaryInput& bi);

    inline explicit Color1(float v) : value(v) {
    }
    
    inline explicit Color1(unorm8 v) : value(v) {
    }

    inline bool isZero() const {
        return value == 0.0f;
    }

    inline bool isOne() const {
        return value == 1.0f;
    }

    static const Color1& one();

    static const Color1& zero();

    /** Returns the value three times */
    class Color3 rgb() const;

    explicit Color1(const class Color1unorm8& other);

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    Color1 operator+ (const Color1& other) const {
        return Color1(value + other.value);
    }

    /** \deprecated */
    Color1 operator+ (const float other) const {
        return Color1(value + other);
    }

    Color1& operator+= (const Color1 other) {
        value += other.value;
        return *this;
    }

    Color1& operator-= (const Color1 other) {
        value -= other.value;
        return *this;
    }

    Color1 operator- (const Color1& other) const {
        return Color1(value - other.value);
    }

    /** \deprecated */
    Color1 operator- (const float other) const {
        return Color1(value - other);
    }

    Color1 operator- () const {
        return Color1(-value);
    }

    Color1 operator* (const Color1& other) const {
        return Color1(value * other.value);
    }

    Color1& operator*=(const Color1 other) {
        value *= other.value;
        return *this;
    }

    Color1& operator*=(const float other) {
        value *= other;
        return *this;
    }

    Color1& operator/=(const float other) {
        value /= other;
        return *this;
    }

    Color1& operator/=(const Color1 other) {
        value /= other.value;
        return *this;
    }

    Color1 operator* (const float other) const {
        return Color1(value * other);
    }

    Color1 operator/ (const Color1& other) const {
        return Color1(value / other.value);
    }

    Color1 operator/ (const float other) const {
        return Color1(value / other);
    }

    inline Color1 max(const Color1& other) const {
        return Color1(G3D::max(value, other.value));
    }

    inline Color1 min(const Color1& other) const {
        return Color1(G3D::min(value, other.value));
    }

    inline Color1 lerp(const Color1& other, float a) const {
        return Color1(value + (other.value - value) * a); 

    }

    inline size_t hashCode() const {
        return (size_t)(value * 0xFFFFFF);
    }
};

}

template <>
struct HashTrait<G3D::Color1> {
    static size_t hashCode(const G3D::Color1& key) {
        return key.hashCode();
    }
};

inline G3D::Color1 operator*(float f, G3D::Color1 c) {
    return c * f;
}

#endif
