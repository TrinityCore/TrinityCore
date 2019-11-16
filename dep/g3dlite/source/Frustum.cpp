/**
 Copyright 2000-2015, Morgan McGuire.
 All rights reserved.
*/
#include "G3D/Frustum.h"
#include "G3D/AABox.h"
#include "G3D/Box.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Vector3.h"

namespace G3D {

void Frustum::getPlanes(Array<Plane>& planes) const {
    for (int i = 0; i < faceArray.size(); ++i) {
        planes.append(faceArray[i].plane);
    }
}

Box Frustum::boundingBox(float minObjectSpaceDepth) const {

    debugAssert(minObjectSpaceDepth > 0);
    const float minFarPlaneZ = -minObjectSpaceDepth;

    AABox aabb;

    // Object space axes; we don't care about translation because we move back to world space at the end
    const Vector3& X = (vertexPos[1] - vertexPos[0]).xyz().direction();
    const Vector3& Y = (vertexPos[2] - vertexPos[1]).xyz().direction();
    const Vector3& Z = X.cross(Y);

    const Point3&  C = vertexPos[0].xyz();

    // Compute the world-to-object matrix, which is the transpose
    // of the object
    const Matrix3& M = Matrix3::fromRows(X, Y, Z);

    for (int v = 0; v < 8; ++v) {
        // World-space point
        const Vector4& P = vertexPos[v];

        // Object-space point (ignoring translation)
        const Point3&  Q = M * P.xyz() - C;

        // Project the point if infinite
        if ((P.w == 0.0f) || (Q.z < minFarPlaneZ)) {
            // Project onto z = minFarPlaneZ
            const float s = minFarPlaneZ / Q.z;
            aabb.merge(Point3(Q.x * s, Q.y * s, minFarPlaneZ));
        } else {
            // World-space point
            aabb.merge( M * (Q / P.w) );
        }
    }

    // Transform box to world space
    return CFrame(M.transpose(), C).toWorldSpace(aabb);
}

} // G3D
