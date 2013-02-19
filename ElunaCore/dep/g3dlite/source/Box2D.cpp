/**
  @file Box.cpp
  Box class

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2001-06-02
  @edited  2008-12-27
*/

#include "G3D/Box2D.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Rect2D.h"

namespace G3D {

bool Box2D::overlaps1Way(const Box2D& other) const {
    for (int a = 0; a < 2; ++a) {
        
        float t = other.m_corner[0].dot(m_axisin[a]);

        // Find the extent of box 2 on m_axisin a
        float tMin = t;
        float tMax = t;
        
        for (int c = 1; c < 4; ++c) {
            t = other.m_corner[c].dot(m_axisin[a]);
            
            if (t < tMin) {
                tMin = t;
            } else if (t > tMax) {
                tMax = t;
            }
        }
        
        // We have to subtract off the origin
        
        // See if [tMin, tMax] intersects [0, 1]
        if ((tMin > 1 + origin[a]) || (tMax < origin[a])) {
            // There was no intersection along this dimension;
            // the boxes cannot possibly overlap.
            return false;
        }
    }
    
    // There was no dimension along which there is no intersection.
    // Therefore the boxes overlap.
    return true;
}


void Box2D::computeAxes() {
    m_axis[0] = m_corner[1] - m_corner[0]; 
    m_axis[1] = m_corner[3] - m_corner[0]; 
    
    // Make the length of each m_axisin = 1/edge length so we know any
    // dot product must be less than 1 to fall within the edge.
    float len[2];
    for (int a = 0; a < 2; ++a) {
        float lenSq = m_axis[a].squaredLength();
        m_axisin[a] = m_axis[a] / lenSq;
        origin[a] = m_corner[0].dot(m_axisin[a]);
        len[a] = sqrt(lenSq); 
        m_axis[a] /= len[a];
    }

    // w * h
    m_area = len[0] * len[1];
    
    
    m_center = (m_corner[0] + m_corner[2]) * 0.5f;
}


Box2D::Box2D(const Vector2& center, float w, float h, float angle) {
    Vector2 X( cos(angle), sin(angle));
    Vector2 Y(-sin(angle), cos(angle));
    
    X *= w / 2;
    Y *= h / 2;
    
    m_corner[0] = center - X - Y;
    m_corner[1] = center + X - Y;
    m_corner[2] = center + X + Y;
    m_corner[3] = center - X + Y;
    
    computeAxes();
}


Box2D::Box2D(const AABox2D& b) {
    for (int i = 0; i < 4; ++i) {
        m_corner[i] = b.corner(i);
    }
    
    computeAxes();
}


Box2D::Box2D(const Vector2& min, const Vector2& max) {
    *this = Box2D(Rect2D::xyxy(min, max));
}


Box2D::Box2D(const CFrame& frame, Box2D& b) {
    for (int i = 0; i < 4; ++i) {
        m_corner[i] = frame.pointToWorldSpace(Vector3(b.corner(i), 0)).xy();
    }
    computeAxes();
}

   
} // G3D
