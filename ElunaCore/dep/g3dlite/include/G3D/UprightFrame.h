/**
 @file UprightFrame.h

 @author Morgan McGuire, http://graphics.cs.williams.edu
 */

#ifndef G3D_UPRIGHTFRAME_H
#define G3D_UPRIGHTFRAME_H

#include "G3D/platform.h"
#include "G3D/Spline.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"

namespace G3D {

/**
 Coordinate frame expressed in Euler angles.
 Unlike a G3D::Quat, UprightFrame always keeps the reference frame from rolling about its own z axis.
 Particularly useful for cameras.

 @sa G3D::CoordinateFrame, G3D::Matrix4, G3D::PhysicsFrame, G3D::UprightSpline, G3D::UprightSplineManipulator
 */
class UprightFrame {
public:

    Vector3         translation;

    /** -pi/2 < pitch < pi/2 in radians about the X-axis */
    float           pitch;

    /** In radians about the Y-axis */
    float           yaw;

    inline UprightFrame(const Vector3& t = Vector3::zero(), float p = 0, float y = 0) 
        : translation(t), pitch(p), yaw(y) {}

    UprightFrame(const CoordinateFrame& cframe);
    
    CoordinateFrame toCoordinateFrame() const;

    /** Supports implicit cast to CoordinateFrame */
    inline operator CoordinateFrame() const {
        return toCoordinateFrame();
    }

    /** Required for use with spline */
    UprightFrame operator+(const UprightFrame& other) const;

    /** Required for use with spline */
    UprightFrame operator*(const float k) const;

    /**
       Unwraps the yaw values in the elements of the array such that
       they still represent the same angles but strictly increase/decrease
       without wrapping about zero.  For use with Spline<UprightFrame>
     */
    static void unwrapYaw(UprightFrame* a, int N);

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);
};

/** Shortest-path linear velocity spline for camera positions.  Always keeps the camera from rolling.
@sa G3D::UprightSplineManipulator, G3D::UprightFrame
*/
class UprightSpline : public Spline<UprightFrame> {
protected:

    virtual void ensureShortestPath(UprightFrame* A, int N) const {
        UprightFrame::unwrapYaw(A, N);
    }

public:
    
    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);

};

}

#endif
