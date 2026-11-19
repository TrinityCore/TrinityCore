/**
 \file PhysicsFrame.h

 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2002-07-08
 \edited  2011-05-10
*/

#ifndef G3D_PhysicsFrame_h
#define G3D_PhysicsFrame_h

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Matrix3.h"
#include "G3D/Quat.h"
#include "G3D/CoordinateFrame.h"
#include <math.h>
#include <string>


namespace G3D {

/**
  An RT transformation using a quaternion; suitable for
  physics integration.

  This interface is in "Beta" and will change in the next release.
 */
class PhysicsFrame {
public:

    Quat    rotation;

    /**
     Origin of this reference frame in its parent's frame.
     */
    Point3 translation;

    /**
     Initializes to the identity frame.
     */
    PhysicsFrame();

    /**
     Purely translational.
     */
    PhysicsFrame(const Vector3& translation) : translation(translation) {}
    PhysicsFrame(const Quat& rot, const Vector3& translation) : rotation(rot), translation(translation) {}
    PhysicsFrame(const Matrix3& rot, const Vector3& translation) : rotation(rot), translation(translation) {}
    PhysicsFrame(const Matrix3& rot) : rotation(rot), translation(Vector3::zero()) {}
    PhysicsFrame(const CoordinateFrame& coordinateFrame);

    PhysicsFrame& operator=(const PhysicsFrame& p) {
        rotation = p.rotation;
        translation = p.translation;

        return *this;
    }

    /**
      - PhysicsFrame( [quat], [vec3] )
      - Vector3( ... )
      - CFrame( ... )
      - CFrame::from...( ... )
     */
    PhysicsFrame(const class Any& any);

    Any toAny() const;

    /** Compose: create the transformation that is <I>other</I> followed by <I>this</I>.*/
    PhysicsFrame operator*(const PhysicsFrame& other) const;

    virtual ~PhysicsFrame() {}

    /**
     Linear interpolation (spherical linear for the rotations).
     */
    PhysicsFrame lerp(
        const PhysicsFrame&     other,
        float                   alpha) const;

    void deserialize(class BinaryInput& b);

    void serialize(class BinaryOutput& b) const;

    operator CFrame() const;

    /** Multiplies both pieces by \a f; note that this will result in a non-unit 
    quaternion that needs to be normalized */
    PhysicsFrame& operator*=(float f) {
        rotation *= f;
        translation *= f;
        return *this;
    }

    /** Multiplies both pieces by \a f; note that this will result in a non-unit 
    quaternion that needs to be normalized */
    PhysicsFrame operator*(float f) const {
        return PhysicsFrame(rotation * f, translation * f);
    }

    PhysicsFrame operator+(const PhysicsFrame& f) const {
        return PhysicsFrame(rotation + f.rotation, translation + f.translation);
    }

    PhysicsFrame& operator+=(const PhysicsFrame& f) {
        rotation += f.rotation;
        translation += f.translation;
        return *this;
    }

    bool operator==(const PhysicsFrame& other) const {
        return (translation == other.translation) && 
            ((rotation == other.rotation) || (rotation == -other.rotation));
    }

    bool operator!=(const PhysicsFrame& other) const {
        return ! ((*this) == other);
    }

};

typedef PhysicsFrame PFrame;

} // namespace

#endif
