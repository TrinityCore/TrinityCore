/**
  \file PhysicsFrameSpline.cpp

  \author Morgan McGuire, http://graphics.cs.williams.edu
 */
#include "G3D/PhysicsFrameSpline.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"
#include "G3D/UprightFrame.h"

namespace G3D {

PhysicsFrameSpline::PhysicsFrameSpline() {}


PhysicsFrameSpline::PhysicsFrameSpline(const Any& any) {
    if (beginsWith(any.name(), "PFrameSpline") ||
        beginsWith(any.name(), "PhysicsFrameSpline") ||
        beginsWith(any.name(), "CFrameSpline") ||
        beginsWith(any.name(), "CoordinateFrameSpline") ||
        beginsWith(any.name(), "UprightSpline") ||
        beginsWith(any.name(), "UprightFrameSpline")) {
        AnyTableReader t(any);
        init(t);
        t.verifyDone();
    } else {
        // Must be a single control point
        control.append(any);
        time.append(0);
    }
}


bool PhysicsFrameSpline::operator==(const PhysicsFrameSpline& other) const {
    if ((extrapolationMode == other.extrapolationMode) && 
        (time.size() == other.size()) && 
        (finalInterval == other.finalInterval) && 
        (control.size() == other.control.size())) {
        // Check actual values
        for (int i = 0; i < time.size(); ++i) {
            if (time[i] != other.time[i]) {
                return false;
            }
        }

        for (int i = 0; i < control.size(); ++i) {
            if (control[i] != other.control[i]) {
                return false;
            }
        }

        return true;
    } else {
        return false;
    }
}


void PhysicsFrameSpline::correct(PhysicsFrame& frame) const {
    frame.rotation.unitize();
}

void PhysicsFrameSpline::scaleControlPoints(float scaleFactor) {
    for (int i = 0; i < control.size(); ++i) {
        control[i].translation *= scaleFactor;
    }
}

void PhysicsFrameSpline::ensureShortestPath(PhysicsFrame* A, int N) const {
    for (int i = 1; i < N; ++i) {
        const Quat& p = A[i - 1].rotation;
        Quat& q = A[i].rotation;

        float cosphi = p.dot(q);

        if (cosphi < 0) {
            // Going the long way, so change the order
            q = -q;
        }
    }
}

}
