/**
 @file Color4.h
 
 Color class
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 @cite Portions based on Dave Eberly's Magic Software Library
      at <A HREF="http://www.magic-software.com">http://www.magic-software.com</A>
 
 @created 2002-06-25
 @edited  2009-11-15

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_Color4_h
#define G3D_Color4_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Color3.h"
#include <string>

namespace G3D {

class Any;

/**
 Do not subclass-- this implementation makes assumptions about the
 memory layout.
 */
class Color4 {
private:
    // Hidden operators
    bool operator<(const Color4&) const;
    bool operator>(const Color4&) const;
    bool operator<=(const Color4&) const;
    bool operator>=(const Color4&) const;

public:

    /** \param any Must be in one of the following forms: 
        - Color4(#, #, #, #)
        - Color4::fromARGB(#)
        - Color4{r = #, g = #, b = #, a = #)
        */
    Color4(const Any& any);
    
    /** Converts the Color4 to an Any. */
    operator Any() const;

    /**
     * Does not initialize fields.
     */
    Color4 ();

    Color4(const Color3& c3, float a = 1.0);

    Color4(const class Color4uint8& c);

    Color4(class BinaryInput& bi);

    Color4(const class Vector4& v);

    Color4(float r, float g, float b, float a = 1.0);

    static const Color4& one();
 
    Color4(float value[4]);

    /**
     * Initialize from another color.
     */
    Color4(const Color4& other);


    inline bool isZero() const {
        return (r == 0.0f) && (g == 0.0f) && (b == 0.0f) && (a == 0.0f);
    }

    inline bool isOne() const {
        return (r == 1.0f) && (g == 1.0f) && (b == 1.0f) && (a == 1.0f);
    }

    void serialize(class BinaryOutput& bo) const;
    void deserialize(class BinaryInput& bi);

    /**
     Initialize from an HTML-style color (e.g. 0xFFFF0000 == RED)
     */
    static Color4 fromARGB(uint32);

    /**
     * Channel values.
     */
    float r, g, b, a;

    inline Color3 rgb() const {
        return Color3(r, g, b);
    }

    // access vector V as V[0] = V.r, V[1] = V.g, V[2] = V.b, v[3] = V.a
    //
    // WARNING.  These member functions rely on
    // (1) Color4 not having virtual functions
    // (2) the data packed in a 3*sizeof(float) memory block
    float& operator[] (int i) const;

    // assignment and comparison
    Color4& operator= (const Color4& rkVector);
    bool operator== (const Color4& rkVector) const;
    bool operator!= (const Color4& rkVector) const;
    size_t hashCode() const;

    // arithmetic operations
    Color4 operator+ (const Color4& rkVector) const;
    Color4 operator- (const Color4& rkVector) const;
    Color4 operator* (float fScalar) const;
    Color4 operator* (const Color4& k) const {
        return Color4(r*k.r, g*k.g, b*k.b, a * k.a); 
    }

    Color4& operator*= (const Color4& c) {
        r *= c.r;
        g *= c.g;
        b *= c.b;
        a *= c.a;
        return *this;
    }

    Color4 operator/ (float fScalar) const;
    Color4 operator- () const;
    friend Color4 operator* (double fScalar, const Color4& rkVector);

    // arithmetic updates
    Color4& operator+= (const Color4& rkVector);
    Color4& operator-= (const Color4& rkVector);
    Color4& operator*= (float fScalar);
    Color4& operator/= (float fScalar);

    bool fuzzyEq(const Color4& other) const;
    bool fuzzyNe(const Color4& other) const;

    std::string toString() const;

    inline Color4 max(const Color4& other) const {
        return Color4(G3D::max(r, other.r), G3D::max(g, other.g), G3D::max(b, other.b), G3D::max(a, other.a));
    }

    inline Color4 min(const Color4& other) const {
        return Color4(G3D::min(r, other.r), G3D::min(g, other.g), G3D::min(b, other.b), G3D::min(a, other.a));
    }

    /** r + g + b + a */
    inline float sum() const {
        return r + g + b + a;
    }

    inline Color4 lerp(const Color4& other, float a) const {
        return (*this) + (other - *this) * a; 

    }

    // Special values.
    // Intentionally not inlined: see Matrix3::identity() for details.
    static const Color4& zero();
    static const Color4& clear();

    static const Color4& inf();
    static const Color4& nan();

    inline bool isFinite() const {
        return G3D::isFinite(r) && G3D::isFinite(g) && G3D::isFinite(b) && G3D::isFinite(a);
    }

    inline Color3 bgr() const {
        return Color3(b, g, r);
    }
};

/**
 Extends the c3 with alpha = 1.0
 */
Color4 operator*(const Color3& c3, const Color4& c4);


inline Color4 operator*(const Color3& c3, const Color4& c4) {
    return Color4(c3.r * c4.r, c3.g * c4.g, c3.b * c4.b, c4.a);
}

//----------------------------------------------------------------------------

inline Color4::Color4 () {
    // For efficiency in construction of large arrays of vectors, the
    // default constructor does not initialize the vector.
}

//----------------------------------------------------------------------------

inline Color4::Color4(const Color3& c3, float a) {
    r = c3.r;
    g = c3.g;
    b = c3.b;
    this->a = a;
}

//----------------------------------------------------------------------------

inline Color4::Color4(
    float       r,
    float       g,
    float       b,
    float       a) :
    r(r), g(g), b(b), a(a) {
}

//----------------------------------------------------------------------------
inline Color4::Color4 (float afCoordinate[4]) {
    r = afCoordinate[0];
    g = afCoordinate[1];
    b = afCoordinate[2];
    a = afCoordinate[3];
}

//----------------------------------------------------------------------------

inline Color4::Color4(
    const Color4&           other) {

    r = other.r;
    g = other.g;
    b = other.b;
    a = other.a;
}

//----------------------------------------------------------------------------

inline float& Color4::operator[] (int i) const {
    return ((float*)this)[i];
}

//----------------------------------------------------------------------------

inline bool Color4::fuzzyEq(const Color4& other) const {
    Color4 dif = (*this - other);
    return G3D::fuzzyEq(dif.r * dif.r + dif.g * dif.g + dif.b * dif.b + dif.a * dif.a, 0);
}

//----------------------------------------------------------------------------

inline bool Color4::fuzzyNe(const Color4& other) const {
    Color4 dif = (*this - other);
    return G3D::fuzzyNe(dif.r * dif.r + dif.g * dif.g + dif.b * dif.b + dif.a * dif.a, 0);
}


//----------------------------------------------------------------------------
inline Color4& Color4::operator= (const Color4& other) {
    r = other.r;
    g = other.g;
    b = other.b;
    a = other.a;
    return *this;
}

//----------------------------------------------------------------------------

inline bool Color4::operator== (const Color4& other) const {
    return ( r == other.r && g == other.g && b == other.b && a == other.a);
}

//----------------------------------------------------------------------------

inline bool Color4::operator!= (const Color4& other) const {
    return ( r != other.r || g != other.g || b != other.b || a != other.a);
}

//----------------------------------------------------------------------------
inline Color4 Color4::operator+ (const Color4& other) const {
    return Color4(r + other.r, g + other.g, b + other.b, a + other.a);
}

//----------------------------------------------------------------------------
inline Color4 Color4::operator- (const Color4& other) const {
    return Color4(r - other.r, g - other.g, b - other.b, a - other.a);
}

//----------------------------------------------------------------------------

inline Color4 Color4::operator* (float fScalar) const {
    return Color4(fScalar * r, fScalar * g, fScalar * b, fScalar * a);
}

//----------------------------------------------------------------------------

inline Color4 Color4::operator- () const {
    return Color4(-r, -g, -b, -a);
}

//----------------------------------------------------------------------------

inline Color4 operator* (float fScalar, const Color4& other) {
    return Color4(fScalar * other.r, fScalar * other.g,
                  fScalar * other.b, fScalar * other.a);
}

//----------------------------------------------------------------------------

inline Color4& Color4::operator+= (const Color4& other) {
    r += other.r;
    g += other.g;
    b += other.b;
    a += other.a;
    return *this;
}

//----------------------------------------------------------------------------

inline Color4& Color4::operator-= (const Color4& other) {
    r -= other.r;
    g -= other.g;
    b -= other.b;
    a -= other.a;
    return *this;
}

//----------------------------------------------------------------------------

inline Color4& Color4::operator*= (float fScalar) {
    r *= fScalar;
    g *= fScalar;
    b *= fScalar;
    a *= fScalar;
    return *this;
}

} // namespace

template <>
struct HashTrait<G3D::Color4> {
    static size_t hashCode(const G3D::Color4& key) {
        return key.hashCode();
    }
};

#endif
