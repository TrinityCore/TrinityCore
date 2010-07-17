/**
 @file Color3.h
 
 Color class
 
 @maintainer Morgan McGuire, matrix@graphics3d.com
 @cite Portions based on Dave Eberly's Magic Software Library
      at <A HREF="http://www.magic-software.com">http://www.magic-software.com</A>
 
 @created 2001-06-02
 @edited  2008-07-17

 Copyright 2000-2008, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_COLOR3_H
#define G3D_COLOR3_H

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/HashTrait.h"
#include "G3D/Color1.h"
#include <string>

namespace G3D {

/**
 Do not subclass-- this implementation makes assumptions about the
 memory layout.
 */
class Color3 {
private:
    // Hidden operators
    bool operator<(const Color3&) const;
    bool operator>(const Color3&) const;
    bool operator<=(const Color3&) const;
    bool operator>=(const Color3&) const;

public:
    /**
     Does not initialize fields.
     */
    Color3();

    explicit Color3(class BinaryInput& bi);

    Color3(float r, float g, float b);
    Color3(float v) : r(v), g(v), b(v) {}

    explicit Color3(const class Vector3& v);
    
    explicit Color3(const float value[3]);

    /**
     Initialize from another color.
     */
    Color3 (const Color3& other);

    Color3 (const class Color3uint8& other);

    /**
     Initialize from an HTML-style color (e.g. 0xFF0000 == RED)
     */
    static Color3 fromARGB(uint32);

    /** Returns one of the color wheel colors (e.g. RED, GREEN, CYAN).
        Does not include white, black, or gray. */
    static const Color3& wheelRandom();

    /**
     * Channel value.
     */
    float r, g, b;

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    // access vector V as V[0] = V.r, V[1] = V.g, V[2] = V.b
    //
    // WARNING.  These member functions rely on
    // (1) Color3 not having virtual functions
    // (2) the data packed in a 3*sizeof(float) memory block
    const float& operator[] (int i) const;
    float& operator[] (int i);

    // assignment and comparison
    Color3& operator= (const Color3& rkVector);
    bool operator== (const Color3& rkVector) const;
    bool operator!= (const Color3& rkVector) const;
    size_t hashCode() const;

    // arithmetic operations
    Color3 operator+ (const Color3& rkVector) const;
    Color3 operator- (const Color3& rkVector) const;
    Color3 operator* (float fScalar) const;
    Color3 operator* (const Color3& rkVector) const;
    Color3 operator/ (float fScalar) const;
    Color3 operator- () const;

    // arithmetic updates
    Color3& operator+= (const Color3& rkVector);
    Color3& operator-= (const Color3& rkVector);
    Color3& operator*= (const Color3& rkVector);
    Color3& operator*= (float fScalar);
    Color3& operator/= (float fScalar);

    bool fuzzyEq(const Color3& other) const;
    bool fuzzyNe(const Color3& other) const;

    inline operator float* () {
        return (float*)this;
    }

    operator const float* () const {
        return (float*)this;
    }

    // vector operations
    float length () const;
    Color3 direction() const;
    float squaredLength () const;
    float dot (const Color3& rkVector) const;
    float unitize (float fTolerance = 1e-06);
    Color3 cross (const Color3& rkVector) const;
    Color3 unitCross (const Color3& rkVector) const;

    inline Color3 pow(const Color3& other) const {
        return Color3(::pow(r, other.r), ::pow(g, other.g), ::pow(b, other.b));
    }
    
    inline Color3 pow(float other) const {
        return Color3(::pow(r, other), ::pow(g, other), ::pow(b, other));
    }

    /**@return the largest component */
    inline float max() const {
        return G3D::max(G3D::max(r, g), b);
    }

    inline Color3 max(const Color3& other) const {
        return Color3(G3D::max(r, other.r), G3D::max(g, other.g), G3D::max(b, other.b));
    }

    inline Color3 min(const Color3& other) const {
        return Color3(G3D::min(r, other.r), G3D::min(g, other.g), G3D::min(b, other.b));
    }

    inline Color3 lerp(const Color3& other, float a) const {
        return (*this) + (other - *this) * a; 

    }

    inline float sum() const {
        return r + g + b;
    }

    inline float average() const {
        return sum() / 3.0f;
    }


    /**
     *  Converts from HSV to RGB , note: toHSV(fromHSV(_hsv)) may not be _hsv, if it is at a grey point or black point.
     *  The components of _hsv should lie in the unit interval. 
     *  @cite Alvy Ray Smith SIGGRAPH 1978 "Color Gamut Transform Pairs"
     **/
    static Color3 fromHSV(const Vector3& _hsv);
    static Vector3 toHSV(const Color3& _rgb);
    
    /** Duplicates the matlab jet colormap maps [0,1] --> (r,g,b) where blue is close to  0 and red is close to 1. */
    static Color3 jetColorMap(const float& val);
    
    /** Returns colors with maximum saturation and value @param hue [0, 1]*/
    static Color3 rainbowColorMap(float hue);

    std::string toString() const;

    /** Random unit vector */
    static Color3 random();

    // Special values.
    // Intentionally not inlined: see Matrix3::identity() for details.
    static const Color3& red();
    static const Color3& green();
    static const Color3& blue();
    static const Color3& purple();
    static const Color3& cyan();
    static const Color3& yellow();
    static const Color3& brown();
    static const Color3& orange();
    static const Color3& black();
    static const Color3& gray();
    static const Color3& white();

    static const Color3& zero();
    static const Color3& one();

    inline Color3 bgr() const {
        return Color3(b, g, r);
    }
};

inline G3D::Color3 operator* (float s, const G3D::Color3& c) {
    return c * s;
}

inline G3D::Color3 operator* (G3D::Color1& s, const G3D::Color3& c) {
    return c * s.value;
}

inline G3D::Color3 operator* (const G3D::Color3& c, G3D::Color1& s) {
    return c * s.value;
}


//----------------------------------------------------------------------------
inline Color3::Color3 () {
}

//----------------------------------------------------------------------------

inline Color3::Color3(float fX, float fY, float fZ) {
    r = fX;
    g = fY;
    b = fZ;
}

//----------------------------------------------------------------------------
inline Color3::Color3(const float afCoordinate[3]) {
    r = afCoordinate[0];
    g = afCoordinate[1];
    b = afCoordinate[2];
}

//----------------------------------------------------------------------------
inline Color3::Color3 (const Color3& rkVector) {
    r = rkVector.r;
    g = rkVector.g;
    b = rkVector.b;
}

//----------------------------------------------------------------------------
inline float& Color3::operator[] (int i) {
    return ((float*)this)[i];
}

//----------------------------------------------------------------------------

inline const float& Color3::operator[] (int i) const {
    return ((float*)this)[i];
}

//----------------------------------------------------------------------------

inline bool Color3::fuzzyEq(const Color3& other) const {
    return G3D::fuzzyEq((*this - other).squaredLength(), 0);
}

//----------------------------------------------------------------------------

inline bool Color3::fuzzyNe(const Color3& other) const {
    return G3D::fuzzyNe((*this - other).squaredLength(), 0);
}


//----------------------------------------------------------------------------
inline Color3& Color3::operator= (const Color3& rkVector) {
    r = rkVector.r;
    g = rkVector.g;
    b = rkVector.b;
    return *this;
}

//----------------------------------------------------------------------------
inline bool Color3::operator== (const Color3& rkVector) const {
    return ( r == rkVector.r && g == rkVector.g && b == rkVector.b );
}

//----------------------------------------------------------------------------
inline bool Color3::operator!= (const Color3& rkVector) const {
    return ( r != rkVector.r || g != rkVector.g || b != rkVector.b );
}

//----------------------------------------------------------------------------
inline Color3 Color3::operator+ (const Color3& rkVector) const {
    return Color3(r + rkVector.r, g + rkVector.g, b + rkVector.b);
}

//----------------------------------------------------------------------------
inline Color3 Color3::operator- (const Color3& rkVector) const {
    return Color3(r -rkVector.r, g - rkVector.g, b - rkVector.b);
}

//----------------------------------------------------------------------------
inline Color3 Color3::operator* (float fScalar) const {
    return Color3(fScalar*r, fScalar*g, fScalar*b);
}

//----------------------------------------------------------------------------
inline Color3 Color3::operator* (const Color3& rkVector) const {
    return Color3(r * rkVector.r, g  * rkVector.g, b * rkVector.b);
}

//----------------------------------------------------------------------------
inline Color3 Color3::operator- () const {
    return Color3( -r, -g, -b);
}

//----------------------------------------------------------------------------
inline Color3& Color3::operator+= (const Color3& rkVector) {
    r += rkVector.r;
    g += rkVector.g;
    b += rkVector.b;
    return *this;
}

//----------------------------------------------------------------------------
inline Color3& Color3::operator-= (const Color3& rkVector) {
    r -= rkVector.r;
    g -= rkVector.g;
    b -= rkVector.b;
    return *this;
}

//----------------------------------------------------------------------------
inline Color3& Color3::operator*= (float fScalar) {
    r *= fScalar;
    g *= fScalar;
    b *= fScalar;
    return *this;
}

//----------------------------------------------------------------------------
inline Color3& Color3::operator*= (const Color3& rkVector) {
    r *= rkVector.r;
    g *= rkVector.g;
    b *= rkVector.b;
    return *this;
}
//----------------------------------------------------------------------------
inline float Color3::squaredLength () const {
    return r*r + g*g + b*b;
}

//----------------------------------------------------------------------------
inline float Color3::length () const {
    return sqrtf(r*r + g*g + b*b);
}

//----------------------------------------------------------------------------
inline Color3 Color3::direction () const {
    float lenSquared = r * r + g * g + b * b;

    if (lenSquared != 1.0f) {
        return *this / sqrtf(lenSquared);
    } else {
        return *this;
    }
}

//----------------------------------------------------------------------------
inline float Color3::dot (const Color3& rkVector) const {
    return r*rkVector.r + g*rkVector.g + b*rkVector.b;
}

//----------------------------------------------------------------------------
inline Color3 Color3::cross (const Color3& rkVector) const {
    return Color3(g*rkVector.b - b*rkVector.g, b*rkVector.r - r*rkVector.b,
                  r*rkVector.g - g*rkVector.r);
}

//----------------------------------------------------------------------------
inline Color3 Color3::unitCross (const Color3& rkVector) const {
    Color3 kCross(g*rkVector.b - b*rkVector.g, b*rkVector.r - r*rkVector.b,
                  r*rkVector.g - g*rkVector.r);
    kCross.unitize();
    return kCross;
}
} // namespace


template <> struct HashTrait<G3D::Color3> {
    static size_t hashCode(const G3D::Color3& key) {
        return key.hashCode();
    }
};


#endif
