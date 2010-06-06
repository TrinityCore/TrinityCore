/**
 @file Color1.h
 
 Monochrome Color class
 
 @maintainer Morgan McGuire, morgan@cs.williams.edu
 @created 2007-01-31
 @edited  2008-10-02

 Copyright 2000-2008, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_COLOR1_H
#define G3D_COLOR1_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"
#include <string>

namespace G3D {

/**
 Monochrome color.  This is just a float, but it has nice semantics
 because a scaling by 255 automatically occurs when switching between
 fixed point (Color1uint8) and floating point (Color1) formats.
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

    Color1 (const class Color1uint8& other);

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    Color1 operator+ (const Color1& other) const {
        return Color1(value + other.value);
    }

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

    Color1 operator- (const float other) const {
        return Color1(value - other);
    }

    Color1 operator- () const {
        return Color1(-value);
    }

    Color1 operator* (const Color1& other) const {
        return Color1(value * other.value);
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


#endif
