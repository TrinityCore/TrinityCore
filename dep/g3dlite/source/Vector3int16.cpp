/**
 @file Vector3int16.cpp
 
 @author Morgan McGuire, http://graphics.cs.williams.edu
  
 @created 2003-04-07
 @edited  2006-01-17
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/format.h"

namespace G3D {

Vector3int16::Vector3int16(const class Vector3& v) {
    x = (int16)iFloor(v.x + 0.5);
    y = (int16)iFloor(v.y + 0.5);
    z = (int16)iFloor(v.z + 0.5);
}


Vector3int16::Vector3int16(class BinaryInput& bi) {
    deserialize(bi);
}


void Vector3int16::serialize(class BinaryOutput& bo) const {
    bo.writeInt16(x);
    bo.writeInt16(y);
    bo.writeInt16(z);
}


void Vector3int16::deserialize(class BinaryInput& bi) {
    x = bi.readInt16();
    y = bi.readInt16();
    z = bi.readInt16();
}

std::string Vector3int16::toString() const {
    return G3D::format("(%d, %d, %d)", x, y, z);
}

    
Vector3int16 Vector3int16::floor(const Vector3& v) {
    return Vector3int16(iFloor(v.x), iFloor(v.y), iFloor(v.z));
}


Vector3int16 Vector3int16::ceil(const Vector3& v) {
    return Vector3int16(iCeil(v.x), iCeil(v.y), iCeil(v.z));
}

}
