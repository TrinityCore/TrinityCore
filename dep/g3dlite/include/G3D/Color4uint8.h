/** 
  @file Color4uint8.h
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2003-04-07
  @edited  2010-03-24

  Copyright 2000-2010, Morgan McGuire.
  All rights reserved.
 */

#ifndef COLOR4UINT8_H
#define COLOR4UINT8_H

#include "G3D/g3dmath.h"
#include "G3D/platform.h"
#include "G3D/Color3uint8.h"

namespace G3D {

/**
 Represents a Color4 as a packed integer.  Convenient
 for creating unsigned int vertex arrays.  Used by
 G3D::GImage as the underlying format.

 <B>WARNING</B>: Integer color formats are different than
 integer vertex formats.  The color channels are automatically
 scaled by 255 (because OpenGL automatically scales integer
 colors back by this factor).  So Color4(1,1,1) == Color4uint8(255,255,255)
 but Vector3(1,1,1) == Vector3int16(1,1,1).

 */
G3D_BEGIN_PACKED_CLASS(1)
class Color4uint8 {
private:
    // Hidden operators
    bool operator<(const Color4uint8&) const;
    bool operator>(const Color4uint8&) const;
    bool operator<=(const Color4uint8&) const;
    bool operator>=(const Color4uint8&) const;

public:
    uint8       r;
    uint8       g;
    uint8       b;
    uint8       a;

    Color4uint8() : r(0), g(0), b(0), a(0) {}

    Color4uint8(const class Color4& c);

    Color4uint8 max(const Color4uint8 x) const {
        return Color4uint8(G3D::max(r, x.r), G3D::max(g, x.g), G3D::max(b, x.b), G3D::max(a, x.a));
    }

    Color4uint8 min(const Color4uint8 x) const {
        return Color4uint8(G3D::min(r, x.r), G3D::min(g, x.g), G3D::min(b, x.b), G3D::min(a, x.a));
    }

    Color4uint8(const uint8 _r, const uint8 _g, const uint8 _b, const uint8 _a) : r(_r), g(_g), b(_b), a(_a) {}

    Color4uint8(const Color3uint8& c, const uint8 _a) : r(c.r), g(c.g), b(c.b), a(_a) {}

    Color4uint8(class BinaryInput& bi);

    inline static Color4uint8 fromARGB(uint32 i) {
        Color4uint8 c;
        c.a = (i >> 24) & 0xFF;
        c.r = (i >> 16) & 0xFF;
        c.g = (i >> 8) & 0xFF;
        c.b = i & 0xFF;
        return c;
    }

    inline uint32 asUInt32() const {
        return ((uint32)a << 24) + ((uint32)r << 16) + ((uint32)g << 8) + b;
    }

    // access vector V as V[0] = V.r, V[1] = V.g, V[2] = V.b
    //
    // WARNING.  These member functions rely on
    // (1) Color4uint8 not having virtual functions
    // (2) the data packed in a 3*sizeof(uint8) memory block
    uint8& operator[] (int i) const {
        return ((uint8*)this)[i];
    }

    operator uint8* () {
        return (uint8*)this;
    }

    operator const uint8* () const {
        return (uint8*)this;
    }


    inline Color3uint8 bgr() const {
        return Color3uint8(b, g, r);
    }

    void serialize(class BinaryOutput& bo) const;

    void deserialize(class BinaryInput& bi);

    inline Color3uint8 rgb() const {
        return Color3uint8(r, g, b);
    }

    bool operator==(const Color4uint8& other) const {
        return *reinterpret_cast<const uint32*>(this) == *reinterpret_cast<const uint32*>(&other);
    }

    bool operator!=(const Color4uint8& other) const {
        return *reinterpret_cast<const uint32*>(this) != *reinterpret_cast<const uint32*>(&other);
    }

}
G3D_END_PACKED_CLASS(1)

} // namespace G3D

#endif
