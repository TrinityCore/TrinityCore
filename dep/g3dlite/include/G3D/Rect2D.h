/**
  \file Rect2D.h
 
  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
  \created 2003-11-13
  \created 2011-06-16

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_Rect2D_h
#define G3D_Rect2D_h

// Linux defines this as a macro
#ifdef border
#undef border
#endif

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Vector2.h"

#ifdef _MSC_VER
// Turn off "conditional expression is constant" warning; MSVC generates this
// for debug assertions in inlined methods.
#   pragma warning (disable : 4127)
#endif


namespace G3D {

class Any;

/**
 If you are using this class for pixel rectangles, keep in mind that the last
 pixel you can draw to is at x0() + width() - 1.
 */
class Rect2D {
private:
    Point2 min, max;

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

    /** Uninitialized constructor */
    Rect2D(bool /*b*/) {}
public:

    /** \param any Must either Rect2D::xywh(#, #, #, #) or Rect2D::xyxy(#, #, #, #)*/
    Rect2D(const Any& any);
    
    /** Converts the Rect2D to an Any. */
    Any toAny() const;

    Rect2D(const Rect2D& r) : min(r.min), max(r.max) {}

    /** Creates the empty set rectangle.
    */
    Rect2D() : min(fnan(), fnan()), max(fnan(), fnan()) {}

    static const Rect2D& empty();

    /** Returns true if this is the empty set, which is distinct from a zero-area rectangle. */
    inline bool isEmpty() const {
        return min.isNaN() && max.isNaN();
    }

    /** Creates a rectangle at 0,0 with the given width and height*/
    Rect2D(const Vector2& wh) : min(0, 0), max(wh.x, wh.y) {}

    Vector2 extent() const {
        if (isEmpty()) {
            return Vector2::zero();
        } else {
            return max - min;
        }
    }

    /** @brief Uniformly random point on the interior */
    Point2 randomPoint() const {
        return Point2(uniformRandom(0, max.x - min.x) + min.x,
                       uniformRandom(0, max.y - min.y) + min.y);
    }

    float width() const {
        if (isEmpty()) {
            return 0;
        } else {
            return max.x - min.x;
        }
    }

    float height() const {
        if (isEmpty()) {
            return 0;
        } else {
            return max.y - min.y;
        }
    }

    float x0() const {
        return min.x;
    }

    float x1() const {
        return max.x;
    }

    float y0() const {
        return min.y;
    }

    float y1() const {
        return max.y;
    }

    /** Min, min corner */
    Point2 x0y0() const {
        return min;
    }

    Point2 x1y0() const {
        return Point2(max.x, min.y);
    }

    Point2 x0y1() const {
        return Point2(min.x, max.y);
    }

    /** Max,max corner */
    Point2 x1y1() const {
        return max;
    }

    /** Width and height */
    Vector2 wh() const {
        if (isEmpty()) {
            return Vector2::zero();
        } else {
            return max - min;
        }
    }

    Point2 center() const {
        return (max + min) * 0.5;
    }

    float area() const {
        return width() * height();
    }

    bool isFinite() const {
        return (min.isFinite() && max.isFinite());
    }

    Rect2D lerp(const Rect2D& other, float alpha) const {
        Rect2D out(false);
        
        out.min = min.lerp(other.min, alpha);
        out.max = max.lerp(other.max, alpha);

        return out;
    }

    static Rect2D xyxy(float x0, float y0, float x1, float y1) {
        Rect2D r(false);
        
        r.min.x = G3D::min(x0, x1);
        r.min.y = G3D::min(y0, y1);
        r.max.x = G3D::max(x0, x1);
        r.max.y = G3D::max(y0, y1);

        return r;
    }

    static Rect2D xyxy(const Point2& v0, const Point2& v1) {
        Rect2D r(false);

        r.min = v0.min(v1);
        r.max = v0.max(v1);

        return r;
    }

    static Rect2D xywh(float x, float y, float w, float h) {
        return xyxy(x, y, x + w, y + h);
    }

    static Rect2D xywh(const Point2& v, const Vector2& w) {
        return xyxy(v.x, v.y, v.x + w.x, v.y + w.y);
    }

    /** Constructs a Rect2D with infinite boundaries.
        Use isFinite() to test either min or max.
     */
    static Rect2D inf() {
        return xyxy(Vector2::inf(), Vector2::inf());
    }

    bool contains(const Point2& v) const {
        // This will automatically return false if isEmpty()
        return (v.x >= min.x) && (v.y >= min.y) && (v.x <= max.x) && (v.y <= max.y);
    }

    bool contains(const Rect2D& r) const {
        // This will automatically return false if isEmpty()
        return (min.x <= r.min.x) && (min.y <= r.min.y) &&
               (max.x >= r.max.x) && (max.y >= r.max.y);
    }

    /** True if there is non-zero area to the intersection between @a this and @a r.
        Note that two rectangles that are adjacent do not intersect because there is
        zero area to the overlap, even though one of them "contains" the corners of the other.*/
    bool intersects(const Rect2D& r) const {
        // This will automatically return false if isEmpty()
        return (min.x < r.max.x) && (min.y < r.max.y) &&
               (max.x > r.min.x) && (max.y > r.min.y);
    }

    /** Like intersection, but counts the adjacent case as touching. */
    bool intersectsOrTouches(const Rect2D& r) const {
        // This will automatically return false if isEmpty()
        return (min.x <= r.max.x) && (min.y <= r.max.y) &&
               (max.x >= r.min.x) && (max.y >= r.min.y);
    }

    Rect2D operator*(float s) const {
        return xyxy(min.x * s, min.y * s, max.x * s, max.y * s);
    }

    Rect2D operator*(const Vector2& s) const {
        return xyxy(min * s, max * s);
    }

    Rect2D operator/(float s) const {
        return xyxy(min / s, max / s);
    }

    Rect2D operator/(const Vector2& s) const {
        return xyxy(min / s, max / s);
    }

    Rect2D operator+(const Vector2& v) const {
        return xyxy(min + v, max + v);
    }

    Rect2D operator-(const Vector2& v) const {
        return xyxy(min - v, max - v);
    }

    bool operator==(const Rect2D& other) const {
        return (min == other.min) && (max == other.max);
    }

    bool operator!=(const Rect2D& other) const {
        return (min != other.min) || (max != other.max);
    }

    void serialize(class BinaryOutput& b) const;

    void deserialize(class BinaryInput& b);

    /** Returns the corners in the order: (min,min), (max,min), (max,max), (min,max). */
    Point2 corner(int i) const {
        debugAssert(i >= 0 && i < 4);
        switch (i & 3) {
        case 0:
            return Point2(min.x, min.y);
        case 1:
            return Point2(max.x, min.y);
        case 2:
            return Point2(max.x, max.y);
        case 3:
            return Point2(min.x, max.y);
        default:
            // Should never get here
            return Point2(0, 0);
        }
    }


    /** @deprecated  
     @sa expand() */
    Rect2D border(float delta) const {
        return Rect2D::xywh(x0() + delta, 
                     y0() + delta, 
                     width() - 2.0f * delta, 
                     height() - 2.0f * delta);
    }

    /** Returns a new Rect2D that is bigger/smaller by the specified amount 
        (negative is shrink.) */
    Rect2D expand(float delta) const {
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

    void merge(const Rect2D& other) {
        if (isEmpty()) {
            *this = other;
        } else if (! other.isEmpty()) {
            min = min.min(other.min);
            max = max.max(other.max);
        }
    }

    /** Computes a rectangle that contains both @a a and @a b.  
        Note that even if @a or @b has zero area, its origin will be included.*/
    Rect2D(const Rect2D& a, const Rect2D& b) {
        *this = a;
        merge(b);
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
     Returns the overlap region between the two rectangles.  This may
     have zero area if they do not intersect.  See the two-Rect2D
     constructor and merge() for a way to compute a union-like
     rectangle.
     */
    Rect2D intersect(const Rect2D& other) const {
        if (intersects(other)) {
            return Rect2D::xyxy(min.max(other.min), max.min(other.max));
        } else {
            return empty();
        }
    }
};

typedef Rect2D AABox2D;
}

#endif
