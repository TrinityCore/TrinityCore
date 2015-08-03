/**
 \file G3D/UprightFrame.h
 \author Morgan McGuire, http://graphics.cs.williams.edu
 */

#ifndef G3D_UprightFrame_h
#define G3D_UprightFrame_h

#include "G3D/platform.h"
#include "G3D/Spline.h"
#include "G3D/Any.h"
#include "G3D/CoordinateFrame.h"

namespace G3D {

/**
    \brief  Coordinate frame expressed in Euler angles.
            Unlike a G3D::Quat, UprightFrame always keeps the reference frame from rolling about its own z axis.
            Particularly useful for cameras.

    \sa G3D::CoordinateFrame, G3D::Matrix4, G3D::PhysicsFrame, G3D::UprightSpline, G3D::UprightSplineManipulator
 */
class UprightFrame {
public:

    Vector3         translation;

    /** -pi/2 < pitch < pi/2 in radians about the X-axis */
    float           pitch;

    /** In radians about the Y-axis */
    float           yaw;

    UprightFrame(const Vector3& t = Vector3::zero(), float p = 0, float y = 0) 
        : translation(t), pitch(p), yaw(y) {}

    UprightFrame(const CoordinateFrame& cframe);

    /** Constructs an UprightFrame from an Any object.
        
        The Any format for UprightFrame is:

        pitch = ##,
        translation = Vector3(),
        yaw = ##
    */
    explicit UprightFrame(const Any& any);
    
    Any toAny() const;

    UprightFrame& operator=(const Any& any);

    /** Supports implicit cast to CoordinateFrame */
    operator CoordinateFrame() const {
        return toCoordinateFrame();
    }

    CoordinateFrame toCoordinateFrame() const;

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

/** 
    \brief Shortest-path linear velocity spline for camera positions.  Always keeps the camera from rolling.

    \sa G3D::UprightSplineManipulator, G3D::UprightFrame
*/
class UprightSpline : public Spline<UprightFrame> {
protected:

    virtual void ensureShortestPath(UprightFrame* A, int N) const {
        UprightFrame::unwrapYaw(A, N);
    }

public:
    UprightSpline();


    /** Constructs an UprightSpline from an Any object.
        
        The Any format for UprightSpline is:

        controls = (UprightFrame, ...),
        times = (##, ...),
        cyclic = bool

        The controls and times arrays must have the same length.
    */
    explicit UprightSpline(const Any& any);

    virtual Any toAny(const std::string& myName) const override;

    Any toAny() const;

    UprightSpline& operator=(const Any& any);

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);
};

}

#endif
