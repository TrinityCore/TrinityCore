/**
  \file G3D/Frustum.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2005-07-20
  \edited  2013-06-11
*/

#ifndef G3D_Frustum_h
#define G3D_Frustum_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/Plane.h"
#include "G3D/SmallArray.h"
#include "G3D/Vector4.h"

namespace G3D {

class Box;

/** \see Projection */
class Frustum {
public:
    class Face {
    public:
        /** Counter clockwise indices into vertexPos */
        int             vertexIndex[4];

        /** The plane containing the face. */
        Plane           plane;
    };
        
    /** The vertices, in homogeneous space.  The order is that of
        the near face, starting from the (object space) +x,+y corner
        and proceeding CCW from the camera's point of view; followed
        by the far face also in CCW order.
    
        If w == 0,
        a vertex is at infinity. */
    SmallArray<Vector4, 8>      vertexPos;

    /** The faces in the frustum.  When the
        far plane is at infinity, there are 5 faces,
        otherwise there are 6.  The faces are in the order
        N,R,L,B,T,[F].
        */
    SmallArray<Face, 6>         faceArray;

    /** \param minObjectSpaceDepth Smallest value permitted for the near plane Z - far plane Z (e.g., to force finite bounds)*/
    Box boundingBox(float minObjectSpaceDepth = finf()) const;
};

} // namespace G3D

#endif
