/**
 @file Vector3int32.cpp
 
 @author Morgan McGuire, http://graphics.cs.williams.edu
  
 @created 2008-07-01
 @edited  2010-10-20
 */

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3int32.h"
#include "G3D/Vector3int16.h"
#include "G3D/Vector3.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/format.h"
#include "G3D/Vector2int32.h"
#include "G3D/Vector2int16.h"
#include "G3D/Any.h"

namespace G3D {
Vector3int32 iFloor(const Vector3& v) {
    return Vector3int32(iFloor(v.x), iFloor(v.y), iFloor(v.z));
}

Vector3int32::Vector3int32(const Any& any) {
    *this = Vector3int32();
    any.verifyNameBeginsWith("Vector3int32", "Point3int32");
    
    switch (any.type()) {
    case Any::TABLE:
        
        for (Any::AnyTable::Iterator it = any.table().begin(); it.isValid(); ++it) {
            const std::string& key = toLower(it->key);
            
            if (key == "x") {
                x = it->value;
            } else if (key == "y") {
                y = it->value;
            } else if (key == "z") {
                z = it->value;
            } else {
                any.verify(false, "Illegal key: " + it->key);
            }
        }
        break;
            
    case Any::ARRAY:
        
        (void)any.name();
        if (any.size() == 1) {
            x = y = z = any[0];
        } else {
            any.verifySize(3);
            x = any[0];
            y = any[1];
            z = any[2];
        }
        break;
        
    default:
        any.verify(false, "Bad Vector3int32 constructor");
    }
}


Any Vector3int32::toAny() const {
    Any a(Any::ARRAY, "Vector3int32");
    a.append(x, y, z);
    return a;
}


Vector3int32::Vector3int32(const class Vector3& v) {
    x = (int32)(v.x + 0.5);
    y = (int32)(v.y + 0.5);
    z = (int32)(v.z + 0.5);
}

Vector3int32::Vector3int32(const class Vector2int32& v, int _z) : x(v.x), y(v.y), z(_z) {}

Vector3int32::Vector3int32(const class Vector2int16& v, int _z) : x(v.x), y(v.y), z(_z) {}


Vector3int32 Vector3int32::truncate(const class Vector3& v) {
    return Vector3int32(int32(v.x), int32(v.y), int32(v.z));
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

//----------------------------------------------------------------------------
// 2-char swizzles

Vector2int32 Vector3int32::xx() const  { return Vector2int32       (x, x); }
Vector2int32 Vector3int32::yx() const  { return Vector2int32       (y, x); }
Vector2int32 Vector3int32::zx() const  { return Vector2int32       (z, x); }
Vector2int32 Vector3int32::xy() const  { return Vector2int32       (x, y); }
Vector2int32 Vector3int32::yy() const  { return Vector2int32       (y, y); }
Vector2int32 Vector3int32::zy() const  { return Vector2int32       (z, y); }
Vector2int32 Vector3int32::xz() const  { return Vector2int32       (x, z); }
Vector2int32 Vector3int32::yz() const  { return Vector2int32       (y, z); }
Vector2int32 Vector3int32::zz() const  { return Vector2int32       (z, z); }
}
