/**
  \file PhysicsFrameSpline.cpp

  \author Morgan McGuire, http://graphics.cs.williams.edu
 */
#include "G3D/PhysicsFrameSpline.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

PhysicsFrameSpline::PhysicsFrameSpline() {}

PhysicsFrameSpline::PhysicsFrameSpline(const Any& any) {
    *this = any;
}

PhysicsFrameSpline& PhysicsFrameSpline::operator=(const Any& any) {
    const std::string& n = toLower(any.name());
    *this = PhysicsFrameSpline();

    if (n == "physicsframespline" || n == "pframespline") {
        any.verifyName("PhysicsFrameSpline", "PFrameSpline");
        
        for (Any::AnyTable::Iterator it = any.table().begin(); it.hasMore(); ++it) {
            const std::string& k = toLower(it->key);
            if (k == "cyclic") {
                cyclic = it->value;
            } else if (k == "control") {
                const Any& v = it->value;
                v.verifyType(Any::ARRAY);
                control.resize(v.size());
                for (int i = 0; i < control.size(); ++i) {
                    control[i] = v[i];
                }
                if (! any.containsKey("time")) {
                    time.resize(control.size());
                    for (int i = 0; i < time.size(); ++i) {
                        time[i] = i;
                    }
                }
            } else if (k == "finalinterval") {
                finalInterval = it->value;
            } else if (k == "time") {
                const Any& v = it->value;
                v.verifyType(Any::ARRAY);
                time.resize(v.size());
                for (int i = 0; i < time.size(); ++i) {
                    time[i] = v[i];
                }
            }
        }
    } else {
        // Must be a PhysicsFrame constructor of some kind
        append(any);
    }
    return *this;
}


void PhysicsFrameSpline::correct(PhysicsFrame& frame) const {
    frame.rotation.unitize();
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
