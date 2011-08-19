/**
 @file PhysicsFrame.cpp

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2002-07-09
 @edited  2010-03-25
*/

#include "G3D/platform.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"
#include "G3D/PhysicsFrame.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

PhysicsFrame::PhysicsFrame() {
    translation = Vector3::zero();
    rotation    = Quat();
}


PhysicsFrame::PhysicsFrame(
    const CoordinateFrame& coordinateFrame) {

    translation = coordinateFrame.translation;
    rotation    = Quat(coordinateFrame.rotation);
}


PhysicsFrame::PhysicsFrame(const Any& a) {
    const std::string& n = toLower(a.name());
    *this = PhysicsFrame();

    if (beginsWith(n, "vector3")) {
        *this = PhysicsFrame(Vector3(a));
    } else if (beginsWith(n, "matrix3")) {        
        *this = PhysicsFrame(Matrix3(a));
    } else if (beginsWith(n, "cframe") || beginsWith(n, "coordinateframe")) {        
        *this = PhysicsFrame(CoordinateFrame(a));
    } else if (beginsWith(n, "pframe") || beginsWith(n, "physicsframe")) {
        if (a.type() == Any::ARRAY) {
            a.verifySize(2);
            rotation    = a[0];
            translation = a[1];
        } else {
            for (Any::AnyTable::Iterator it = a.table().begin(); it.hasMore(); ++it) {
                const std::string& n = toLower(it->key);
                if (n == "translation") {
                    translation = it->value;
                } else if (n == "rotation") {
                    rotation = it->value;
                } else {
                    a.verify(false, "Illegal table key: " + it->key);
                }
            }
        }
    }
}


PhysicsFrame PhysicsFrame::operator*(const PhysicsFrame& other) const {
    PhysicsFrame result;

    result.rotation = rotation * other.rotation;
    result.translation = translation + rotation.toRotationMatrix() * other.translation;

    return result;
}


PhysicsFrame::operator CoordinateFrame() const {
    CoordinateFrame f;
    
    f.translation = translation;
    f.rotation    = rotation.toRotationMatrix();

    return f;
}


PhysicsFrame PhysicsFrame::lerp(
    const PhysicsFrame&     other,
    float                   alpha) const {

    PhysicsFrame result;

    result.translation = translation.lerp(other.translation, alpha);
    result.rotation    = rotation.slerp(other.rotation, alpha);

    return result;
}


void PhysicsFrame::deserialize(class BinaryInput& b) {
    translation.deserialize(b);
    rotation.deserialize(b);
}


void PhysicsFrame::serialize(class BinaryOutput& b) const {
    translation.serialize(b);
    rotation.serialize(b);
}


}; // namespace

