/**
  \file G3D/Box.h
 
  Box class
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \cite Portions based on Dave Eberly's Magic Software Library at <A HREF="http://www.magic-software.com">http://www.magic-software.com</A>
  \created 2001-06-02
  \edited  2013-04-13

  Copyright 2000-2013, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Box_h
#define G3D_Box_h

#include "G3D/platform.h"
#include "G3D/Vector3.h"
#include "G3D/Array.h"
#include "G3D/Plane.h"

namespace G3D {

class CoordinateFrame;
class Any;

/**
 \brief An arbitrary (oriented) 3D box, useful as a bounding box. 

 To construct a box from a coordinate frame, center and extent, use the idiom:
 <CODE>Box box = cframe.toObjectSpace(Box(center - extent/2, center + extent/2));</CODE>
 */
class Box {
private:

    static int32 dummy;

    friend class CoordinateFrame;

    /**
     Axes with length equal to the 4 edges that run along each of them
     */
    Vector3 _edgeVector[3];
   
    Point3  _center;

    float  _area;

    float  _volume;

    void init(
        const Vector3& min,
        const Vector3& max);

public:

    Box();

    explicit Box(const Any& a);

    /**
      Constructs a box from two opposite corners.
     */
    Box(const Vector3&      min,
        const Vector3&      max);

    Box(const Vector3&      osMin,
        const Vector3&      osMax,
        const CoordinateFrame&       frame);

    Box(class BinaryInput& b);

    Box(const class AABox& b);

    explicit Box(const Point3& p);

    static Box inf();

    Any toAny() const;

    void serialize(class BinaryOutput& b) const;
    void deserialize(class BinaryInput& b);
    
    /**
     Returns the object to world transformation for 
     this box, where the origin is the center of the box.  localFrame().worldToObject(...) takes
     objects into the space where the box axes are
     (1,0,0), (0,1,0), (0,0,1).  Note that there
     is no scaling in this transformation.
     */
    CoordinateFrame localFrame() const;

    /** \sa localFrame */
    void getLocalFrame(CoordinateFrame& frame) const;

    Box operator*(float f) const;

    /**
      Returns the centroid of the box.
     */
    inline Vector3 center() const {
        return _center;
    }

    /**
       \htmlonly
      <PRE>
		

      2--------3
     / :      /|
    /  :     / |
   6--------7  |
   |   :    |  |
   |   0....|..1
   | /      | /
   |/       |/
   4--------5

    y  
    ^ 
    |
    |-->x
  z/
  

      </PRE>
      \endhtmlonly
     */
    Vector3 corner(int i) const;

    /**
     Unit length.
     */
    inline Vector3 axis(int a) const {
        debugAssert(a < 3);
        return _edgeVector[a].direction();
    }

    /**
     Distance from corner(0) to the next corner
     along the box's local axis a.
     */
    inline float extent(int a) const {
        debugAssert(a < 3);
        return _edgeVector[a].length();
    }

    inline Vector3 extent() const {
        return Vector3(_edgeVector[0].length(), _edgeVector[1].length(), _edgeVector[2].length());
    }

    /**
     Returns the four corners of a face (0 <= f < 6).
     The corners are returned to form a clockwise quad facing outwards.
     
	 
	 
	  +--------+
     / :      /|
    /  :     / |
   +--------+  |
   |   :    |  |
   |   +....|..+
   | /      | /
   |/       |/
   +--------+
	
  y  
  ^ 
  |
  |-->x
z/	
	Faces are in the following order:
	0: -Z
	1: X
	2: Z
	3: Y
	4: -X
	5: -Y

	 */
    void getFaceCorners(
        int                 f,
        Vector3&            v0,
        Vector3&            v1,
        Vector3&            v2,
        Vector3&            v3) const;


    /**
      See AABox::culledBy
     */
    bool culledBy
    (
     const Array<Plane>&        plane,
     int32&                     cullingPlaneIndex,
     const uint32               testMask,
     uint32&                    childMask) const;

    /**
     Conservative culling test that does not produce a mask for children.
     */
    bool culledBy
    (
     const Array<Plane>&        plane,
     int32&                     cullingPlaneIndex = dummy,
     const uint32               testMask      = -1) const;

    bool contains(
        const Vector3&      point) const;

    float area() const;

    float volume() const;

    void getRandomSurfacePoint(Vector3& P, Vector3& N = Vector3::ignore()) const;

    /**
     Uniformly distributed on the interior (includes surface)
     */
    Vector3 randomInteriorPoint() const;

    void getBounds(class AABox&) const;

    bool isFinite() const {
        return G3D::isFinite(_volume);
    }
};

}

#endif
