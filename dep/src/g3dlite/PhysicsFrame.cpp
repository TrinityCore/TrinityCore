/**
 @file PhysicsFrame.cpp

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2002-07-09
 @edited  2006-01-25
*/

#include "G3D/platform.h"
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


PhysicsFrame PhysicsFrame::operator*(const PhysicsFrame& other) const {
    PhysicsFrame result;

    result.rotation = rotation * other.rotation;
    result.translation = translation + rotation.toRotationMatrix() * other.translation;

    return result;
}


CoordinateFrame PhysicsFrame::toCoordinateFrame() const {
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

