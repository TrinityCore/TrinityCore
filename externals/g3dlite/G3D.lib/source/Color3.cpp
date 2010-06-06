/**
 @file Color3.cpp

 Color class.

 @author Morgan McGuire, matrix@graphics3d.com
 @cite Portions based on Dave Eberly's Magic Software Library at http://www.magic-software.com


 @created 2001-06-02
 @edited  2006-01-13
 */

#include "G3D/platform.h"
#include <stdlib.h>
#include "G3D/Color3.h"
#include "G3D/Vector3.h"
#include "G3D/format.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Color3uint8.h"

namespace G3D {

const Color3& Color3::red() {
    static Color3 c(1.0f, 0.0f, 0.0f);
    return c;
}


const Color3& Color3::green() {
    static Color3 c(0.0f, 1.0f, 0.0f);
    return c;
}


const Color3& Color3::blue() {
    static Color3 c(0.0f, 0.0f, 1.0f);
    return c;
}


const Color3& Color3::purple() {
    static Color3 c(0.7f, 0.0f, 1.0f);
    return c;
}


const Color3& Color3::cyan() {
    static Color3 c(0.0f, 0.7f, 1.0f);
    return c;
}


const Color3& Color3::yellow() {
    static Color3 c(1.0f, 1.0f, 0.0f);
    return c;
}


const Color3& Color3::brown() {
    static Color3 c(0.5f, 0.5f, 0.0f);
    return c;
}


const Color3& Color3::orange() {
    static Color3 c(1.0f, 0.5f, 0.0f);
    return c;
}


const Color3& Color3::black() {
    static Color3 c(0.0f, 0.0f, 0.0f);
    return c;
}

const Color3& Color3::zero() {
    static Color3 c(0.0f, 0.0f, 0.0f);
    return c;
}


const Color3& Color3::one() {
    static Color3 c(1.0f, 1.0f, 1.0f);
    return c;
}


const Color3& Color3::gray() {
    static Color3 c(0.7f, 0.7f, 0.7f);
    return c;
}


const Color3& Color3::white() {
    static Color3 c(1, 1, 1);
    return c;
}


Color3::Color3(BinaryInput& bi) {
    deserialize(bi);
}


void Color3::deserialize(BinaryInput& bi) {
    r = bi.readFloat32();
    g = bi.readFloat32();
    b = bi.readFloat32();
}


void Color3::serialize(BinaryOutput& bo) const {
    bo.writeFloat32(r);
    bo.writeFloat32(g);
    bo.writeFloat32(b);
}


const Color3& Color3::wheelRandom() {
    static const Color3 colorArray[8] =
    {Color3::blue(),   Color3::red(),    Color3::green(),
     Color3::orange(), Color3::yellow(), 
     Color3::cyan(),   Color3::purple(), Color3::brown()};

    return colorArray[iRandom(0, 7)];
}


size_t Color3::hashCode() const {
    unsigned int rhash = (*(int*)(void*)(&r));
    unsigned int ghash = (*(int*)(void*)(&g));
    unsigned int bhash = (*(int*)(void*)(&b));

    return rhash + (ghash * 37) + (bhash * 101);
}


Color3::Color3(const Vector3& v) {
    r = v.x;
    g = v.y;
    b = v.z;
}


Color3::Color3(const class Color3uint8& other) {
    r = other.r / 255.0f;
    g = other.g / 255.0f;
    b = other.b / 255.0f;
}


Color3 Color3::fromARGB(uint32 x) {
    return Color3((float)((x >> 16) & 0xFF), (float)((x >> 8) & 0xFF), (float)(x & 0xFF)) / 255.0f;
}

//----------------------------------------------------------------------------


Color3 Color3::random() {
    return Color3(uniformRandom(), 
                  uniformRandom(),
                  uniformRandom()).direction();
}

//----------------------------------------------------------------------------
Color3 Color3::operator/ (float fScalar) const {
    Color3 kQuot;

    if (fScalar != 0.0f) {
		float fInvScalar = 1.0f / fScalar;
        kQuot.r = fInvScalar * r;
        kQuot.g = fInvScalar * g;
        kQuot.b = fInvScalar * b;
        return kQuot;

    } else {

        return Color3((float)G3D::inf(), (float)G3D::inf(), (float)G3D::inf());
    }
}

//----------------------------------------------------------------------------
Color3& Color3::operator/= (float fScalar) {
    if (fScalar != 0.0f) {
		float fInvScalar = 1.0f / fScalar;
        r *= fInvScalar;
        g *= fInvScalar;
        b *= fInvScalar;
    } else {
        r = (float)G3D::inf();
        g = (float)G3D::inf();
        b = (float)G3D::inf();
    }

    return *this;
}

//----------------------------------------------------------------------------
float Color3::unitize (float fTolerance) {
	float fLength = length();

    if ( fLength > fTolerance ) {
		float fInvLength = 1.0f / fLength;
        r *= fInvLength;
        g *= fInvLength;
        b *= fInvLength;
    } else {
        fLength = 0.0f;
    }

    return fLength;
}

//----------------------------------------------------------------------------
Color3 Color3::fromHSV(const Vector3& _hsv) {
	debugAssertM((_hsv.x <= 1.0f && _hsv.x >= 0.0f)
			&& (_hsv.y <= 1.0f && _hsv.y >= 0.0f) 
			&& ( _hsv.z <= 1.0f && _hsv.z >= 0.0f), "H,S,V must be between [0,1]");
	const int i = G3D::iFloor(6.0*_hsv.x);
	const float f = 6.0f * _hsv.x - i;
	const float m = _hsv.z * (1.0f - (_hsv.y));
	const float n = _hsv.z * (1.0f - (_hsv.y * f));
	const float k = _hsv.z * (1.0f - (_hsv.y * (1 - f)));
	switch(i) {
	case 0:
		return Color3(_hsv.z, k, m);

	case 1:
		return Color3(n, _hsv.z, m);

	case 2:
		return Color3(m, _hsv.z, k);

	case 3:
		return Color3(m, n, _hsv.z);

	case 4:
		return Color3(k, m, _hsv.z);

	case 5:
		return Color3(_hsv.z, m, n);

    default:
		debugAssertM(false, "fell through switch..");
	}
	return Color3::black();
}


Vector3 Color3::toHSV(const Color3& _rgb) {
	debugAssertM((_rgb.r <= 1.0f && _rgb.r >= 0.0f) 
			&& (_rgb.g <= 1.0f && _rgb.g >= 0.0f)
			&& (_rgb.b <= 1.0f && _rgb.b >= 0.0f), "R,G,B must be between [0,1]");
	Vector3 hsv = Vector3::zero();
	hsv.z = G3D::max(G3D::max(_rgb.r, _rgb.g), _rgb.b);
	if (G3D::fuzzyEq(hsv.z, 0.0f)) {
		return hsv;
	}
	
    const float x =  G3D::min(G3D::min(_rgb.r, _rgb.g), _rgb.b);
	hsv.y = (hsv.z - x) / hsv.z; 

    if (G3D::fuzzyEq(hsv.y, 0.0f)) {
		return hsv;
	}

	Vector3 rgbN;
	rgbN.x = (hsv.z - _rgb.r) / (hsv.z - x);
	rgbN.y = (hsv.z - _rgb.g) / (hsv.z - x);
	rgbN.z = (hsv.z - _rgb.b) / (hsv.z - x);

	if (_rgb.r == hsv.z) {  // note from the max we know that it exactly equals one of the three.
		hsv.x = (_rgb.g == x)? 5.0f + rgbN.z : 1.0f - rgbN.y;
	} else if (_rgb.g == hsv.z) {
		hsv.x = (_rgb.b == x)? 1.0f + rgbN.x : 3.0f - rgbN.z;
	} else {
		hsv.x = (_rgb.r == x)? 3.0f + rgbN.y : 5.0f - rgbN.x;
	}
	
    hsv.x /= 6.0f;

	return hsv;
}

Color3 Color3::jetColorMap(const float& val) {
	debugAssertM(val <= 1.0f && val >= 0.0f , "value should be in [0,1]");

	//truncated triangles where sides have slope 4
	Color3 jet;

	jet.r = G3D::min(4.0f * val - 1.5f,-4.0f * val + 4.5f) ;
	jet.g = G3D::min(4.0f * val - 0.5f,-4.0f * val + 3.5f) ;
	jet.b = G3D::min(4.0f * val + 0.5f,-4.0f * val + 2.5f) ;


	jet.r = G3D::clamp(jet.r, 0.0f, 1.0f);
	jet.g = G3D::clamp(jet.g, 0.0f, 1.0f);
	jet.b = G3D::clamp(jet.b, 0.0f, 1.0f);

	return jet;
}





std::string Color3::toString() const {
    return G3D::format("(%g, %g, %g)", r, g, b);
}

//----------------------------------------------------------------------------

Color3 Color3::rainbowColorMap(float hue) {
    return fromHSV(Vector3(hue, 1.0f, 1.0f));
}


}; // namespace

