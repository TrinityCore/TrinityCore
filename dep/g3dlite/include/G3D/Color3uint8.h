/** 
  @file Color3uint8.h
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2003-04-07
  @edited  2010-03-24

  Copyright 2000-2010, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Color3uint8_h
#define G3D_Color3uint8_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

namespace G3D {

/**
 Represents a Color3 as a packed integer.  Convenient
 for creating unsigned int vertex arrays.  Used by
 G3D::GImage as the underlying format.

 <B>WARNING</B>: Integer color formats are different than
 integer vertex formats.  The color channels are automatically
 scaled by 255 (because OpenGL automatically scales integer
 colors back by this factor).  So Color3(1,1,1) == Color3uint8(255,255,255)
 but Vector3(1,1,1) == Vector3int16(1,1,1).
 */

G3D_BEGIN_PACKED_CLASS(1)

class Color3uint8 {
private:
    // Hidden operators
    bool operator<(const Color3uint8&) const;
    bool operator>(const Color3uint8&) const;
    bool operator<=(const Color3uint8&) const;
    bool operator>=(const Color3uint8&) const;

public:
    uint8       r;
    uint8       g;
    uint8       b;

    Color3uint8() : r(0), g(0), b(0) {}

    Color3uint8(const uint8 _r, const uint8 _g, const uint8 _b) : r(_r), g(_g), b(_b) {}

    Color3uint8(const class Color3& c);

    Color3uint8(class BinaryInput& bi);

    static Color3uint8 fromARGB(uint32 i) {
        Color3uint8 c;
        c.r = (i >> 16) & 0xFF;
        c.g = (i >> 8) & 0xFF;
        c.b = i & 0xFF;
        return c;
    }

    Color3uint8 bgr() const {
        return Color3uint8(b, g, r);
    }

    Color3uint8 max(const Color3uint8 x) const {
        return Color3uint8(G3D::max(r, x.r), G3D::max(g, x.g), G3D::max(b, x.b));
    }

    Color3uint8 min(const Color3uint8 x) const {
        return Color3uint8(G3D::min(r, x.r), G3D::min(g, x.g), G3D::min(b, x.b));
    }

    /**
     Returns the color packed into a uint32
     (the upper byte is 0xFF)
     */
    uint32 asUInt32() const {
        return (0xFF << 24) + ((uint32)r << 16) + ((uint32)g << 8) + b;
    }

    void serialize(class BinaryOutput& bo) const;

    void deserialize(class BinaryInput& bi);

    // access vector V as V[0] = V.r, V[1] = V.g, V[2] = V.b
    //
    // WARNING.  These member functions rely on
    // (1) Color3 not having virtual functions
    // (2) the data packed in a 3*sizeof(uint8) memory block
    uint8& operator[] (int i) const {
        debugAssert((unsigned int)i < 3);
        return ((uint8*)this)[i];
    }

    operator uint8* () {
        return (G3D::uint8*)this;
    }

    operator const uint8* () const {
        return (uint8*)this;
    }

    bool operator==(const Color3uint8 other) const {
        return (other.r == r) && (other.g == g) && (other.b == b);
    }

    bool operator!=(const Color3uint8 other) const {
        return ! (*this == other);
    }
}
G3D_END_PACKED_CLASS(1)

} // namespace G3D

#endif
