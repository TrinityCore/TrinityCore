/**
  \file G3D/unorm16.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \created 2012-03-02 by Zina Cigolle
  \edited  2012-03-02

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_unorm16_h
#define G3D_unorm16_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"

namespace G3D {


/** Represents numbers on [0, 1] in 16 bits as an unsigned normalized
 0.8 fixed-point value using the same encoding scheme as OpenGL.  

 Note that arithmetic operations may over and under-flow, just like
 uint16 arithmetic.

 OpenGL specifications can be found here: 
 http://www.opengl.org/registry/specs/ARB/shading_language_packing.txt

*/
G3D_BEGIN_PACKED_CLASS(1)
unorm16 {
private:
    uint16    m_bits;

    /** Private to prevent illogical conversions without explicitly
     stating that the input should be treated as bits; see fromBits. */
    explicit unorm16(uint16 b) : m_bits(b) {}

public:

    /** Equivalent to: \code unorm16 u = reinterpret_cast<const unorm16&>(255);\endcode */
    static unorm16 fromBits(uint16 b) {
        return unorm16(b);
    }

    /** \copydoc fromBits */
    static unorm16 reinterpretFrom(uint16 b) {
        return unorm16(b);
    }

    unorm16() : m_bits(0) {}
    
    unorm16(const unorm16& other) : m_bits(other.m_bits) {}

    explicit unorm16(const class Any& a);

    class Any toAny() const;

    /** Maps f to round(f * 65535).*/
    explicit unorm16(float f) {
        m_bits = uint16(clamp(f, 0.0f, 1.0f) * 65535.0f + 0.5f);
    }

    explicit unorm16(double f) {
        m_bits = uint16(clamp(f, 0.0, 1.0) * 65535.0 + 0.5);
    }

    /** Returns a number on [0.0f, 1.0f] */
    operator float() const {
        return float(m_bits) * (1.0f / 65535.0f);
    }

    operator double() const {
        return double(m_bits) * (1.0 / 65535.0);
    }

    static unorm16 one() {
        return fromBits(65535);
    }

    static unorm16 zero() {
        return fromBits(0);
    }

    /**\brief Returns the underlying bits in this representation. 
     Equivalent to:
    \code uint16 i = reinterpret_cast<const uint16&>(u); \endcode */
    uint16 bits() const {
        return m_bits;
    }

    /** \copydoc bits */
    uint16 reinterpretAsUInt16() const {
        return m_bits;
    }

    bool operator>(const unorm16 other) const {
        return m_bits > other.m_bits;
    }

    bool operator<(const unorm16 other) const {
        return m_bits < other.m_bits;
    }

    bool operator>=(const unorm16 other) const {
        return m_bits >= other.m_bits;
    }

    bool operator<=(const unorm16 other) const {
        return m_bits <= other.m_bits;
    }

    bool operator==(const unorm16 other) const {
        return m_bits <= other.m_bits;
    }

    bool operator!=(const unorm16 other) const {
        return m_bits != other.m_bits;
    }

    unorm16 operator+(const unorm16 other) const {
        return unorm16(uint16(m_bits + other.m_bits));
    }

    unorm16& operator+=(const unorm16 other) {
        m_bits += other.m_bits;
        return *this;
    }

    unorm16 operator-(const unorm16 other) const {
        return unorm16(uint16(m_bits - other.m_bits));
    }

    unorm16& operator-=(const unorm16 other) {
        m_bits -= other.m_bits;
        return *this;
    }

    unorm16 operator*(const int i) const {
        return unorm16(uint16(m_bits * i));
    }

    unorm16& operator*=(const int i) {
        m_bits *= i;
        return *this;
    }

    unorm16 operator/(const int i) const {
        return unorm16(uint16(m_bits / i));
    }

    unorm16& operator/=(const int i) {
        m_bits /= i;
        return *this;
    }

    unorm16 operator<<(const int i) const {
        return unorm16((uint16)(m_bits << i));
    }

    unorm16& operator<<=(const int i) {
        m_bits <<= i;
        return *this;
    }

    unorm16 operator>>(const int i) const {
        return unorm16(uint16(m_bits >> i));
    }

    unorm16& operator>>=(const int i) {
        m_bits >>= i;
        return *this;
    }
}
G3D_END_PACKED_CLASS(1)

} // namespace G3D

#endif // G3D_unorm16
