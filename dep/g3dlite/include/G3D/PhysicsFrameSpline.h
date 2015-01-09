/**
  @file PhysicsFrameSpline.h

  @author Morgan McGuire, http://graphics.cs.williams.edu
 */
#ifndef G3D_PhysicsFrameSpline_h
#define G3D_PhysicsFrameSpline_h

#include "G3D/platform.h"
#include "G3D/PhysicsFrame.h"
#include "G3D/Spline.h"

namespace G3D {

/**
 A subclass of Spline that keeps the rotation field of a
 PhysicsFrame normalized and rotating the short direction.

 \sa UprightFrameSpline
 */
class PhysicsFrameSpline : public Spline<PhysicsFrame> {
public:

    PhysicsFrameSpline();

    /** Accepts a table of properties, or any valid PhysicsFrame specification for a single control*/
    PhysicsFrameSpline(const Any& any);

    bool operator==(const PhysicsFrameSpline& a) const;
 
    bool operator!=(const PhysicsFrameSpline& a) const {
        return ! ((*this) == a);
    }

    /** Mutates all underlying PhysicsFrames by scaling their translation by \param scaleFactor */
    void scaleControlPoints(float scaleFactor);

    virtual void correct(PhysicsFrame& frame) const;
    virtual void ensureShortestPath(PhysicsFrame* A, int N) const;

    virtual Any toAny(const std::string& myName) const override {
        return Spline<PhysicsFrame>::toAny(myName);
    }

    Any toAny() const {
        return toAny("PFrameSpline");
    }
};

}

#endif
