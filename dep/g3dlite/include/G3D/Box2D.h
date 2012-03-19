/**
  @file Box2D.h
 
  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  @created 2001-06-02
  @edited  2008-12-27

  Copyright 2000-2009, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Box2D_h
#define G3D_Box2D_h

#include "G3D/platform.h"
#include "G3D/Vector2.h"

namespace G3D {

class CoordinateFrame;
typedef class CoordinateFrame CFrame;
class Rect2D;
typedef class Rect2D AABox2D;

/**
   2D oriented box
   @cite http://www.flipcode.com/archives/2D_OBB_Intersection.shtml
 */
class Box2D {
private:
    /** Corners of the box, where 0 is the lower left. */
    Vector2         m_corner[4];

    /** Two edges of the box extended away from corner[0], with length
        = 1 / extentSquared */
    Vector2         m_axisin[2];

    /** Two edges of the box extended away from corner[0], with unit length */
    Vector2         m_axis[2];

    /** Centroid of the box */
    Vector2         m_center;

    /** origin[a] = m_corner[0].dot(m_axisin[a]); */
    float           origin[2];

    /** Surface area */
    float           m_area;

    Vector2         m_extent;

    /** Returns true if other overlaps one dimension of this. */
    bool overlaps1Way(const Box2D& other) const;


    /** Updates the axes after the m_corners move.  Assumes the
        m_corners actually form a rectangle. */
    void computeAxes();

public:

    /** 
        @param center World-space center
        @param w Width along object-space x-axis
        @param h Height along object-space y-axis
        @param angle Counter-clockwise angle from object-space x-axis in radians
     */
    Box2D(const Vector2& center = Vector2(0, 0), float w = 0, float h = 0, float angle = 0);

    Box2D(const AABox2D& b);

    Box2D(const Vector2& min, const Vector2& max);

    /** Transform @a b by @a frame, discarding the Z components, and
        compute the new box.*/
    Box2D(const CFrame& frame, Box2D& b);
    
    inline bool contains(const Vector2& v) const {
        // Take to object space:
        const Vector2& p = v - m_center;
        float x = p.dot(m_axisin[0]);
        float y = p.dot(m_axisin[1]);

        // Must be within extent/2 on both axes in object space
        return (abs(x) <= 0.5f) && (abs(y) <= 0.5f);        
    }

    /** @brief Distance from corner(0) to the next corner along the box's local axis a. */
    inline const Vector2& extent() const {
        return m_extent;
    }

    /** @brief Unit length vector along axis @a a */
    inline const Vector2& axis(int a) const {
        debugAssert(a == 0 || a == 1);
        return m_axis[a];
    }

    /** @brief Surface area */
    inline float area() const {
        return m_area;
    }

    inline const Vector2& corner(int i) const {
        debugAssert(i >=0 && i <= 3);
        return m_corner[i];
    }

    inline const Vector2& center() const {
        return m_center;
    }

    /** Returns true if the intersection of the boxes is non-empty. */
    inline bool overlaps(const Box2D& other) const {
        return overlaps1Way(other) && other.overlaps1Way(*this);
    }
};

} // G3D
#endif
