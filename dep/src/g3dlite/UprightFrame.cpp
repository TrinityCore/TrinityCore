/**
  @file UprightFrame.cpp
  Box class

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2007-05-02
  @edited  2007-05-05
*/

#include "G3D/UprightFrame.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

UprightFrame::UprightFrame(const CoordinateFrame& cframe) {
    Vector3 look = cframe.lookVector();

    yaw = G3D::pi() + atan2(look.x, look.z);
    pitch = asin(look.y);

    translation = cframe.translation;
}

    
CoordinateFrame UprightFrame::toCoordinateFrame() const {
    CoordinateFrame cframe;

    Matrix3 P(Matrix3::fromAxisAngle(Vector3::unitX(), pitch));
    Matrix3 Y(Matrix3::fromAxisAngle(Vector3::unitY(), yaw));

    cframe.rotation = Y * P;
    cframe.translation = translation;

    return cframe;
}


UprightFrame UprightFrame::operator+(const UprightFrame& other) const {
    return UprightFrame(translation + other.translation, pitch + other.pitch, yaw + other.yaw);
}


UprightFrame UprightFrame::operator*(const float k) const {
    return UprightFrame(translation * k, pitch * k, yaw * k);
}


void UprightFrame::unwrapYaw(UprightFrame* a, int N) {
    // Use the first point to establish the wrapping convention
    for (int i = 1; i < N; ++i) {
        const float prev = a[i - 1].yaw;
        float& cur = a[i].yaw;

        // No two angles should be more than pi (i.e., 180-degrees) apart.  
        if (abs(cur - prev) > G3D::pi()) {
            // These angles must have wrapped at zero, causing them
            // to be interpolated the long way.

            // Find canonical [0, 2pi] versions of these numbers
            float p = wrap(prev, twoPi());
            float c = wrap(cur, twoPi());
            
            // Find the difference -pi < diff < pi between the current and previous values
            float diff = c - p;
            if (diff < -G3D::pi()) {
                diff += twoPi();
            } else if (diff > G3D::pi()) {
                diff -= twoPi();
            } 

            // Offset the current from the previous by the difference
            // between them.
            cur = prev + diff;
        }
    }
}


void UprightFrame::serialize(class BinaryOutput& b) const {
    translation.serialize(b);
    b.writeFloat32(pitch);
    b.writeFloat32(yaw);
}


void UprightFrame::deserialize(class BinaryInput& b) {
    translation.deserialize(b);
    pitch = b.readFloat32();
    yaw = b.readFloat32();
}


void UprightSpline::serialize(class BinaryOutput& b) const {
    b.writeBool8(cyclic);

    b.writeInt32(control.size());
    for (int i = 0; i < control.size(); ++i) {
        control[i].serialize(b);
    }
    b.writeInt32(time.size());
    for (int i = 0; i < time.size(); ++i) {
        b.writeFloat32(time[i]);
    }
}


void UprightSpline::deserialize(class BinaryInput& b) {
    cyclic = b.readBool8();

    control.resize(b.readInt32());
    for (int i = 0; i < control.size(); ++i) {
        control[i].deserialize(b);
    }

    if (b.hasMore()) {
        time.resize(b.readInt32());
        for (int i = 0; i < time.size(); ++i) {
            time[i] = b.readFloat32();
        }
        debugAssert(time.size() == control.size());
    } else {
        // Import legacy path
        time.resize(control.size());
        for (int i = 0; i < time.size(); ++i) {
            time[i] = i;
        }
    }
}

}
