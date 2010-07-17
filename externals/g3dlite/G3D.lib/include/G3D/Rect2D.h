/**
  @file Rect2D.h
 
  @maintainer Morgan McGuire, matrix@graphics3d.com
 
  @created 2003-11-13
  @created 2008-11-16

  Copyright 2000-2008, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_RECT2D_H
#define G3D_RECT2D_H

// Linux defines this as a macro
#ifdef border
#undef border
#endif

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Vector2.h"

namespace G3D {

/**
 If you are using this class for pixel rectangles, keep in mind that the last
 pixel you can draw to is at x0() + width() - 1.
 */
class Rect2D {
private:
    Vector2 min, max;

    /**
     Returns true if the whole polygon is clipped.
     @param p Value of the point
     @param axis Index [0 or 1] of the axis to clip along?
     @param clipGreater Are we clipping greater than or less than the line?
     @param inPoly Polygon being clipped
     @param outPoly The clipped polygon
     */
    template<class T>
    static bool clipSide2D(
        const float p, bool clipGreater, int axis, 
        const Array<T>& inPoly, Array<T>& outPoly) {

        outPoly.clear();
        int i0 = -1;

        Vector2 pt1;
        bool c1 = true;

        float negate = clipGreater ? -1 : 1;

        // Find a point that is not clipped
        for (i0 = 0; (i0 < inPoly.length()) && c1; ++i0) {
            pt1 = inPoly[i0];       
            c1  = (negate * pt1[axis]) < (negate * p);
        }

        // We incremented i0 one time to many
        --i0;

        if (c1) {
            // We could not find an unclipped point
            return true;
        }

        outPoly.append(pt1);

        // for each point in inPoly,
        //     if the point is outside the side and the previous one was also outside, continue
        //     if the point is outside the side and the previous one was inside, cut the line
        //     if the point is inside the side and the previous one was also inside, append the points
        //     if the point is inside the side and the previous one was outside, cut the line    
        for (int i = 1; i <= inPoly.length(); ++i) {
            T pt2 = inPoly[(i + i0) % inPoly.length()];
            bool    c2  = (negate * pt2[axis]) < (negate * p);

            if (c1 ^ c2) {

                if (!c1 && c2 && (i > 1)) {
                    // Unclipped to clipped trasition and not the first iteration
                    outPoly.append(pt1);
                }

                // only one point is clipped, find where the line crosses the clipping plane


                float alpha;
                if (pt2[axis] == pt1[axis]) {
                    alpha = 0;
                } else {
                    alpha = (p - pt1[axis]) / (pt2[axis] - pt1[axis]);
                }
                outPoly.append(pt1.lerp(pt2, alpha));
            } else if (! (c1 || c2) && (i != 1)) {
                // neither point is clipped (don't do this the first time 
                // because we appended the first pt before the loop)
                outPoly.append(pt1);
            }
        
            pt1 = pt2;
            c1 = c2;
        }

        return false;
    }

public:

    inline Rect2D() : min(0, 0), max(0, 0) {}

    /** Creates a rectangle at 0,0 with the given width and height*/
    inline Rect2D(const Vector2& wh) : min(0, 0), max(wh.x, wh.y) {}

    /** Computes a rectangle that contains both @a a and @a b.  
        Note that even if @a or @b has zero area, its origin will be included.*/
    inline Rect2D(const Rect2D& a, const Rect2D& b) {
        min = a.min.min(b.min);
        max = a.max.max(b.max);
    }

    /** @brief Uniformly random point on the interior */
    inline Vector2 randomPoint() const {
        return Vector2(uniformRandom(0, max.x - min.x) + min.x,
                       uniformRandom(0, max.y - min.y) + min.y);
    }

    inline float width() const {
        return max.x - min.x;
    }

    inline float height() const {
        return max.y - min.y;
    }

    inline float x0() const {
        return min.x;
    }

    inline float x1() const {
        return max.x;
    }

    inline float y0() const {
        return min.y;
    }

    inline float y1() const {
        return max.y;
    }

    /** Min, min corner */
    inline Vector2 x0y0() const {
        return min;
    }

    inline Vector2 x1y0() const {
        return Vector2(max.x, min.y);
    }

    inline Vector2 x0y1() const {
        return Vector2(min.x, max.y);
    }

    /** Max,max corner */
    inline Vector2 x1y1() const {
        return max;
    }

    /** Width and height */
    inline Vector2 wh() const {
        return max - min;
    }

    inline Vector2 center() const {
        return (max + min) * 0.5;
    }

    inline static Rect2D xyxy(float x0, float y0, float x1, float y1) {
        Rect2D r;
        
        r.min.x = G3D::min(x0, x1);
        r.min.y = G3D::min(y0, y1);
        r.max.x = G3D::max(x0, x1);
        r.max.y = G3D::max(y0, y1);

        return r;
    }

    Rect2D lerp(const Rect2D& other, float alpha) const {
        Rect2D out;
        
        out.min = min.lerp(other.min, alpha);
        out.max = max.lerp(other.max, alpha);

        return out;
    }

    inline static Rect2D xyxy(const Vector2& v0, const Vector2& v1) {
        Rect2D r;

        r.min = v0.min(v1);
        r.max = v0.max(v1);

        return r;
    }

    inline static Rect2D xywh(float x, float y, float w, float h) {
        return xyxy(x, y, x + w, y + h);
    }

    inline static Rect2D xywh(const Vector2& v, const Vector2& w) {
        return xyxy(v.x, v.y, v.x + w.x, v.y + w.y);
    }

    inline bool contains(const Vector2& v) const {
        return (v.x >= min.x) && (v.y >= min.y) && (v.x <= max.x) && (v.y <= max.y);
    }

    inline bool contains(const Rect2D& r) const {
        return (min.x <= r.min.x) && (min.y <= r.min.y) &&
               (max.x >= r.max.x) && (max.y >= r.max.y);
    }

    /** True if there is non-zero area to the intersection between @a this and @a r.
        Note that two rectangles that are adjacent do not intersect because there is
        zero area to the overlap, even though one of them "contains" the corners of the other.*/
    inline bool intersects(const Rect2D& r) const {
        return (min.x < r.max.x) && (min.y < r.max.y) &&
               (max.x > r.min.x) && (max.y > r.min.y);
    }

    /** Like intersection, but counts the adjacent case as touching. */
    inline bool intersectsOrTouches(const Rect2D& r) const {
        return (min.x <= r.max.x) && (min.y <= r.max.y) &&
               (max.x >= r.min.x) && (max.y >= r.min.y);
    }

    inline Rect2D operator*(float s) const {
        return xyxy(min.x * s, min.y * s, max.x * s, max.y * s);
    }

    inline Rect2D operator/(float s) const {
        return xyxy(min / s, max / s);
    }

    inline Rect2D operator/(const Vector2& s) const {
        return xyxy(min / s, max / s);
    }

    inline Rect2D operator+(const Vector2& v) const {
        return xyxy(min + v, max + v);
    }

    inline Rect2D operator-(const Vector2& v) const {
        return xyxy(min - v, max - v);
    }

    inline bool operator==(const Rect2D& other) const {
        return (min == other.min) && (max == other.max);
    }

    inline bool operator!=(const Rect2D& other) const {
        return (min != other.min) || (max != other.max);
    }

    /** Returns the corners in the order: (min,min), (max,min), (max,max), (min,max). */
    inline Vector2 corner(int i) const {
        debugAssert(i >= 0 && i < 4);
        switch (i & 3) {
        case 0:
            return Vector2(min.x, min.y);
        case 1:
            return Vector2(max.x, min.y);
        case 2:
            return Vector2(max.x, max.y);
        case 3:
            return Vector2(min.x, max.y);
        default:
            // Should never get here
            return Vector2(0, 0);
        }
    }


    /** @deprecated  
     @sa expand() */
    inline Rect2D border(float delta) const {
        return Rect2D::xywh(x0() + delta, 
                     y0() + delta, 
                     width() - 2.0f * delta, 
                     height() - 2.0f * delta);
    }

    /** Returns a new Rect2D that is bigger/smaller by the specified amount 
        (negative is shrink.) */
    inline Rect2D expand(float delta) const {
        float newX = x0() - delta;
        float newY = y0() - delta;
        float newW = width() + 2.0f * delta;
        float newH = height() + 2.0f * delta;

        if (newW < 0.0f) {
            newX = (x0() + width()) / 2.0f;
            newW = 0.0f;
        }

        if (newH < 0.0f) {
            newY = (y0() + height()) / 2.0f;
            newH = 0.0f;
        }
        return Rect2D::xywh(newX, newY, newW, newH);
    }

    /** 
     Clips so that the rightmost point of the outPoly is at rect.x1 (e.g. a 800x600 window produces
     rightmost point 799, not 800).  The results are suitable for pixel rendering if iRounded.
     Templated so that it will work for Vector2,3,4 (the z and w components are interpolated linearly).
     The template parameter must define T.lerp and contain x and y components.

     If the entire polygon is clipped by a single side, the result will be empty.
     The result might also have zero area but not be empty.
     */
    template<class T>
    void clip(const Array<T>& inPoly, Array<T>& outPoly) const {

        const bool greaterThan = true;
        const bool lessThan    = false;
        const int  X = 0;
        const int  Y = 1;

        Array<T> temp;

        bool entirelyClipped =
          clipSide2D(x0(), lessThan,    X,    inPoly,  temp)    ||
          clipSide2D(x1(), greaterThan, X,    temp,    outPoly) ||
          clipSide2D(y0(), lessThan,    Y,    outPoly, temp)    || 
          clipSide2D(y1(), greaterThan, Y,    temp,    outPoly);

        if (entirelyClipped) {
            outPoly.clear();
        }
    }


    /** Returns the largest, centered Rect2D that can fit inside this
        while maintaining the aspect ratio of x:y.  Convenient for
        displaying images in odd-shaped windows.
    */
    Rect2D largestCenteredSubRect(float ww, float hh) const {
        float textureAspect = hh / ww;
        float viewAspect = height() / width();

        if (viewAspect > textureAspect) {
            // The view is too tall
            float h = width() * textureAspect;
            float y = (height() - h) / 2;
            return Rect2D::xywh(0, y, width(), h) + corner(0);
        } else {
            // The view is too wide
            float w = height() / textureAspect;
            float x = (width() - w) / 2;
            return Rect2D::xywh(x, 0, w, height()) + corner(0);
        }
    }

    /**
     Returns the overlap region between the two rectangles.  This may have zero area
     if they do not intersect.  See the two-Rect2D constructor for a way to compute
     a union-like rectangle.
     */
    Rect2D intersect(const Rect2D& other) const {
        if (intersects(other)) {
            return Rect2D::xyxy(min.max(other.min), max.min(other.max));
        }else{
            return Rect2D::xywh(0, 0, 0, 0);
        }
    }

    float area() const {
        return width() * height();
    }
};

typedef Rect2D AABox2D;
}

#endif
