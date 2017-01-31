/**
 \file G3D/Vector2int16.cpp
 
 \author Morgan McGuire, http://graphics.cs.williams.edu
  
 \created 2003-08-09
 \edited  2011-01-06
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector2.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Any.h"
#include "G3D/Vector2int32.h"

namespace G3D {

Vector2int16::Vector2int16(const class Vector2int32& v) : x(v.x), y(v.y) {}

Vector2int16::Vector2int16(const Any& any) {
    any.verifyName("Vector2int16", "Point2int16");
    any.verifyType(Any::TABLE, Any::ARRAY);
    any.verifySize(2);

    if (any.type() == Any::ARRAY) {
        x = any[0];
        y = any[1];
    } else {
        // Table
        x = any["x"];
        y = any["y"];
    }
}


Vector2int16& Vector2int16::operator=(const Any& a) {
    *this = Vector2int16(a);
    return *this;
}


Any Vector2int16::toAny() const {
    Any any(Any::ARRAY, "Vector2int16");
    any.append(x, y);
    return any;
}

Vector2int16::Vector2int16(const class Vector2& v) {
    x = (int16)iFloor(v.x + 0.5);
    y = (int16)iFloor(v.y + 0.5);
}


Vector2int16::Vector2int16(class BinaryInput& bi) {
    deserialize(bi);
}


void Vector2int16::serialize(class BinaryOutput& bo) const {
    bo.writeInt16(x);
    bo.writeInt16(y);
}


void Vector2int16::deserialize(class BinaryInput& bi) {
    x = bi.readInt16();
    y = bi.readInt16();
}


Vector2int16 Vector2int16::clamp(const Vector2int16& lo, const Vector2int16& hi) {
    return Vector2int16(iClamp(x, lo.x, hi.x), iClamp(y, lo.y, hi.y));
}


}
