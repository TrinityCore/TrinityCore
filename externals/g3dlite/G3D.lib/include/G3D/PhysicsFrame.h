/**
 @file PhysicsFrame.h

 @maintainer Morgan McGuire, matrix@graphics3d.com
 
 @created 2002-07-08
 @edited  2006-01-10
*/

#ifndef G3D_PHYSICSFRAME_H
#define G3D_PHYSICSFRAME_H

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
     Takes object space points to world space.
     */
    Vector3 translation;

    /**
     Initializes to the identity frame.
     */
    PhysicsFrame();

    /**
     Purely translational force
     */
    PhysicsFrame(const Vector3& translation) : translation(translation) {}

    PhysicsFrame(const CoordinateFrame& coordinateFrame);

    /** Compose: create the transformation that is <I>other</I> followed by <I>this</I>.*/
    PhysicsFrame operator*(const PhysicsFrame& other) const;

    virtual ~PhysicsFrame() {}

    CoordinateFrame toCoordinateFrame() const;

    /**
     Linear interpolation (spherical linear for the rotations).
     */
    PhysicsFrame lerp(
        const PhysicsFrame&     other,
        float                   alpha) const;

    void deserialize(class BinaryInput& b);

    void serialize(class BinaryOutput& b) const;

};

} // namespace

#endif
