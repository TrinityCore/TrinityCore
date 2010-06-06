/**
 @file Vector2int16.cpp
 
 @author Morgan McGuire, matrix@graphics3d.com
  
 @created 2003-08-09
 @edited  2006-01-29
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector2.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

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
