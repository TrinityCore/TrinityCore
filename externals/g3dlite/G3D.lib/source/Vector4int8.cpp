/**
  @file Vector4int8.cpp
 
  Homogeneous vector class.

  @maintainer Morgan McGuire, matrix@graphics3d.com
 
  @created 2007-02-09
  @edited  2007-02-09

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */

#include "G3D/platform.h"
#include "G3D/Vector4int8.h"
#include "G3D/Vector3.h"
#include "G3D/Vector4.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include <string>

namespace G3D {

Vector4int8::Vector4int8(const Vector4& source) {
    x = iClamp(iRound(source.x), -128, 127);
    y = iClamp(iRound(source.y), -128, 127);
    z = iClamp(iRound(source.z), -128, 127);
    w = iClamp(iRound(source.w), -128, 127);
}

Vector4int8::Vector4int8(const Vector3& source, int8 w) : w(w) {
    x = iClamp(iRound(source.x), -128, 127);
    y = iClamp(iRound(source.y), -128, 127);
    z = iClamp(iRound(source.z), -128, 127);
}

Vector4int8::Vector4int8(class BinaryInput& b) {
    deserialize(b);
}

void Vector4int8::serialize(class BinaryOutput& b) const {
    // Intentionally write individual bytes to avoid endian issues
    b.writeInt8(x);
    b.writeInt8(y);
    b.writeInt8(z);
    b.writeInt8(w);
}

void Vector4int8::deserialize(class BinaryInput& b) {
    x = b.readInt8();
    y = b.readInt8();
    z = b.readInt8();
    w = b.readInt8();
}

} // namespace G3D

