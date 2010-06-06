/**
 @file Vector3int32.cpp
 
 @author Morgan McGuire, matrix@graphics3d.com
  
 @created 2008-07-01
 @edited  2008-07-01
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3int32.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/format.h"

namespace G3D {

Vector3int32::Vector3int32(const class Vector3& v) {
    x = (int32)iFloor(v.x + 0.5);
    y = (int32)iFloor(v.y + 0.5);
    z = (int32)iFloor(v.z + 0.5);
}


Vector3int32::Vector3int32(const class Vector3int16& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}


Vector3int32::Vector3int32(class BinaryInput& bi) {
    deserialize(bi);
}


void Vector3int32::serialize(class BinaryOutput& bo) const {
    bo.writeInt32(x);
    bo.writeInt32(y);
    bo.writeInt32(z);
}


void Vector3int32::deserialize(class BinaryInput& bi) {
    x = bi.readInt32();
    y = bi.readInt32();
    z = bi.readInt32();
}

std::string Vector3int32::toString() const {
    return G3D::format("(%d, %d, %d)", x, y, z);
}

}
