/**
  \file UprightFrame.cpp

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
*/

#include "G3D/UprightFrame.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

UprightFrame::UprightFrame(const CoordinateFrame& cframe) {
    Vector3 look = cframe.lookVector();

    yaw = (float)(G3D::pi() + atan2(look.x, look.z));
    pitch = asin(look.y);

    translation = cframe.translation;
}


UprightFrame::UprightFrame(const Any& any) {
    any.verifyName("UprightFrame");
    any.verifyType(Any::TABLE);

    translation = any["translation"];
    pitch = any["pitch"];
    yaw = any["yaw"];
}


Any UprightFrame::toAny() const {
    Any any(Any::TABLE, "UprightFrame");

    any["translation"] = translation;
    any["pitch"] = pitch;
    any["yaw"] = yaw;

    return any;
}


UprightFrame& UprightFrame::operator=(const Any& any) {
    *this = UprightFrame(any);
    return *this;
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
            float p = (float)wrap(prev, twoPi());
            float c = (float)wrap(cur, twoPi());
            
            // Find the difference -pi < diff < pi between the current and previous values
            float diff = c - p;
            if (diff < -G3D::pi()) {
                diff += (float)twoPi();
            } else if (diff > G3D::pi()) {
                diff -= (float)twoPi();
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

///////////////////////////////////////////////////////////////////////////////////////////

UprightSpline::UprightSpline() : Spline<UprightFrame>() {
}


UprightSpline::UprightSpline(const Any& any) {
    any.verifyName("UprightSpline");
    any.verifyType(Any::TABLE);

    extrapolationMode = any["extrapolationMode"];

    const Any& controlsAny = any["control"];
    controlsAny.verifyType(Any::ARRAY);

    control.resize(controlsAny.length());
    for (int controlIndex = 0; controlIndex < control.length(); ++controlIndex) {
        control[controlIndex] = controlsAny[controlIndex];
    }

    const Any& timesAny = any["time"];
    timesAny.verifyType(Any::ARRAY);

    time.resize(timesAny.length());
    for (int timeIndex = 0; timeIndex < time.length(); ++timeIndex) {
        time[timeIndex] = timesAny[timeIndex];
    }
}


Any UprightSpline::toAny(const std::string& myName) const {
    Any any(Any::TABLE, myName);

    any["extrapolationMode"] = extrapolationMode;

    Any controlsAny(Any::ARRAY);
    for (int controlIndex = 0; controlIndex < control.length(); ++controlIndex) {
        controlsAny.append(control[controlIndex]);
    }
    any["control"] = controlsAny;

    Any timesAny(Any::ARRAY);
    for (int timeIndex = 0; timeIndex < time.length(); ++timeIndex) {
        timesAny.append(Any(time[timeIndex]));
    }
    any["time"] = timesAny;

    return any;
}


Any UprightSpline::toAny() const {
    return toAny("UprightSpline");
}


UprightSpline& UprightSpline::operator=(const Any& any) {
    *this = UprightSpline(any);
    return *this;
}


void UprightSpline::serialize(class BinaryOutput& b) const {
    b.writeInt32(extrapolationMode);

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
    extrapolationMode = SplineExtrapolationMode(b.readInt32());

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
            time[i] = (float)i;
        }
    }
}

}
