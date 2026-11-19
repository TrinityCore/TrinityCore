/**
  \file G3D/unorm8.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \created 2011-08-11
  \edited  2011-08-11

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_unorm8_h
#define G3D_unorm8_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

namespace G3D {


/** Represents numbers on [0, 1] in 8 bits as an unsigned normalized
 0.8 fixed-point value using the same encoding scheme as OpenGL.  

 OpenGL specifications can be found here: 
 <www.opengl.org/registry/specs/ARB/shading_language_packing.txt>

 Note that arithmetic operations may over and under-flow, just like
 uint8 arithmetic.


*/
G3D_BEGIN_PACKED_CLASS(1)
unorm8 {
private:
    uint8    m_bits;

    /** Private to prevent illogical conversions without explicitly
     stating that the input should be treated as bits; see fromBits. */
    explicit unorm8(uint8 b) : m_bits(b) {}

public:

    /** Equivalent to: \code unorm8 u = reinterpret_cast<const unorm8&>(255);\endcode */
    static unorm8 fromBits(uint8 b) {
        return unorm8(b);
    }

    /** \copydoc fromBits */
    static unorm8 reinterpretFrom(uint8 b) {
        return unorm8(b);
    }

    unorm8() : m_bits(0) {}
    
    unorm8(const unorm8& other) : m_bits(other.m_bits) {}

    /** Maps f to round(f * 255).*/
    explicit unorm8(float f) {
        m_bits = (uint8)(clamp(f, 0.0f, 1.0f) * 255.0f + 0.5f);
    }

    explicit unorm8(double f) {
        m_bits = iClamp(int(f * 255.0f + 0.5f), 0, 255);
    }

    /** Returns a number on [0.0f, 1.0f] */
    operator float() const {
        return float(m_bits) * (1.0f / 255.0f);
    }

    operator double() const {
        return double(m_bits) * (1.0 / 255.0);
    }

    static unorm8 one() {
        return fromBits(255);
    }

    static unorm8 zero() {
        return fromBits(0);
    }

    /**\brief Returns the underlying bits in this representation. 
     Equivalent to:
    \code uint8 i = reinterpret_cast<const uint8&>(u); \endcode */
    uint8 bits() const {
        return m_bits;
    }

    /** \copydoc bits */
    uint8 reinterpretAsUInt8() const {
        return m_bits;
    }

    bool operator>(const unorm8 other) const {
        return m_bits > other.m_bits;
    }

    bool operator<(const unorm8 other) const {
        return m_bits < other.m_bits;
    }

    bool operator>=(const unorm8 other) const {
        return m_bits >= other.m_bits;
    }

    bool operator<=(const unorm8 other) const {
        return m_bits <= other.m_bits;
    }

    bool operator==(const unorm8 other) const {
        return m_bits <= other.m_bits;
    }

    bool operator!=(const unorm8 other) const {
        return m_bits != other.m_bits;
    }

    unorm8 operator+(const unorm8 other) const {
        return unorm8(uint8(m_bits + other.m_bits));
    }

    unorm8& operator+=(const unorm8 other) {
        m_bits += other.m_bits;
        return *this;
    }

    unorm8 operator-(const unorm8 other) const {
        return unorm8(uint8(m_bits - other.m_bits));
    }

    unorm8& operator-=(const unorm8 other) {
        m_bits -= other.m_bits;
        return *this;
    }

    unorm8 operator*(const int i) const {
        return unorm8(uint8(m_bits * i));
    }

    unorm8& operator*=(const int i) {
        m_bits *= i;
        return *this;
    }

    unorm8 operator/(const int i) const {
        return unorm8(uint8(m_bits / i));
    }

    unorm8& operator/=(const int i) {
        m_bits /= i;
        return *this;
    }

    unorm8 operator<<(const int i) const {
        return unorm8((uint8)(m_bits << i));
    }

    unorm8& operator<<=(const int i) {
        m_bits <<= i;
        return *this;
    }

    unorm8 operator>>(const int i) const {
        return unorm8(uint8(m_bits >> i));
    }

    unorm8& operator>>=(const int i) {
        m_bits >>= i;
        return *this;
    }
}
G3D_END_PACKED_CLASS(1)

} // namespace G3D

#endif // G3D_unorm8
