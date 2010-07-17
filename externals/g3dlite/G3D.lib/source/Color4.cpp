/**
 @file Color4.cpp

 Color class.

 @author Morgan McGuire, matrix@graphics3d.com
 @cite Portions by Laura Wollstadt, graphics3d.com
 @cite Portions based on Dave Eberly's Magic Software Library at http://www.magic-software.com


 @created 2002-06-25
 @edited  2006-01-10
 */

#include <stdlib.h>
#include "G3D/Color4.h"
#include "G3D/Color4uint8.h"
#include "G3D/Vector4.h"
#include "G3D/format.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

const Color4& Color4::zero() {
    static Color4 c(0.0f, 0.0f, 0.0f, 0.0f);
    return c;
}


const Color4& Color4::inf() {
    static Color4 c((float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf());
    return c;
}


const Color4& Color4::clear() {
    return Color4::zero();
}


Color4::Color4(const Vector4& v) {
    r = v.x;
    g = v.y;
    b = v.z;
    a = v.w;
}


Color4::Color4(const Color4uint8& c) : r(c.r), g(c.g), b(c.b), a(c.a) {
    *this /= 255.0f;
}

size_t Color4::hashCode() const {
    unsigned int rhash = (*(int*)(void*)(&r));
    unsigned int ghash = (*(int*)(void*)(&g));
    unsigned int bhash = (*(int*)(void*)(&b));
    unsigned int ahash = (*(int*)(void*)(&a));

    return rhash + (ghash * 37) + (bhash * 101) + (ahash * 241);
}

Color4 Color4::fromARGB(uint32 x) {
    return Color4(
        (float)((x >> 16) & 0xFF), 
        (float)((x >> 8) & 0xFF),
        (float)(x & 0xFF), 
        (float)((x >> 24) & 0xFF)) / 255.0;
}


Color4::Color4(BinaryInput& bi) {
    deserialize(bi);
}


void Color4::deserialize(BinaryInput& bi) {
    r = bi.readFloat32();
    g = bi.readFloat32();
    b = bi.readFloat32();
    a = bi.readFloat32();
}


void Color4::serialize(BinaryOutput& bo) const {
    bo.writeFloat32(r);
    bo.writeFloat32(g);
    bo.writeFloat32(b);
    bo.writeFloat32(a);
}


//----------------------------------------------------------------------------

Color4 Color4::operator/ (float fScalar) const {
    Color4 kQuot;

    if (fScalar != 0.0f) {
		float fInvScalar = 1.0f / fScalar;
        kQuot.r = fInvScalar * r;
        kQuot.g = fInvScalar * g;
        kQuot.b = fInvScalar * b;
        kQuot.a = fInvScalar * a;
        return kQuot;

    } else {

        return Color4::inf();
    }
}

//----------------------------------------------------------------------------

Color4& Color4::operator/= (float fScalar) {
    if (fScalar != 0.0f) {
		float fInvScalar = 1.0f / fScalar;
        r *= fInvScalar;
        g *= fInvScalar;
        b *= fInvScalar;
        a *= fInvScalar;
    } else {
        r = (float)G3D::inf();
        g = (float)G3D::inf();
        b = (float)G3D::inf();
        a = (float)G3D::inf();
    }

    return *this;
}

//----------------------------------------------------------------------------

std::string Color4::toString() const {
    return G3D::format("(%g, %g, %g, %g)", r, g, b, a);
}

//----------------------------------------------------------------------------

}; // namespace

