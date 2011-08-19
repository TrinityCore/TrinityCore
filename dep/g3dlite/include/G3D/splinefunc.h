/**
 @file spline.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2004-07-25
 @edited  2007-05-05
 */

#ifndef G3D_SPLINEFUNC_H
#define G3D_SPLINEFUNC_H

#include "G3D/platform.h"
#include "G3D/debug.h"
#include "G3D/Array.h"
#include "G3D/g3dmath.h"

namespace G3D {

/**
 Interpolates a property according to a piecewise linear spline.  This provides
 C0 continuity but the derivatives are not smooth.  
 <P>
 Example:
 <CODE>
    const double times[] = {MIDNIGHT,               SUNRISE - HOUR,         SUNRISE,              SUNRISE + sunRiseAndSetTime / 4, SUNRISE + sunRiseAndSetTime, SUNSET - sunRiseAndSetTime, SUNSET - sunRiseAndSetTime / 2, SUNSET,               SUNSET + HOUR/2,     DAY};
    const Color3 color[] = {Color3(0, .0, .1),      Color3(0, .0, .1),      Color3::black(),        Color3::black(),                   Color3::white() * .25,         Color3::white() * .25,        Color3(.5, .2, .2),             Color3(.05, .05, .1),   Color3(0, .0, .1), Color3(0, .0, .1)};
    ambient = linearSpline(time, times, color, 10);
 </CODE>

 See also G3D::Spline

  @param x         The spline is a function of x; this is the sample to choose.
  @param controlX  controlX[i], controlY[i] is a control points.  It is assumed
                   that controlX are strictly increasing.  XType must support
                   the "<" operator and a subtraction operator that returns
                   a number.
  @param controlY  YType must support multiplication and addition.
  @param numControl The number of control points.
 */
template<class XType, class YType>
YType linearSpline(double x, const XType* controlX, const YType* controlY, int numControl) {
    debugAssert(numControl >= 1);

    // Off the beginning
    if ((numControl == 1) || (x < controlX[0])) {
        return controlY[0];
    }

    for (int i = 1; i < numControl; ++i) {
        if (x < controlX[i]) {
            const double alpha = (double)(controlX[i] - x) / (controlX[i] - controlX[i - 1]);
            return controlY[i] * (1 - alpha) + controlY[i - 1] * alpha;
        }
    }

    // Off the end
    return controlY[numControl - 1];
}

 
    /** See also G3D::Spline*/
template<class YType> YType cyclicCatmullRomSpline(
    double       t,
    const YType* controlY,
    int          numPoints) {

    debugAssert(numPoints >= 3);

    t = wrap(t, numPoints);

    // Find the indices of adjacent control points    
    int i = iFloor(t);
    
    // Compute the distance from the control point
    t = t - i;

    // Shift back one point for correct indexing
    i += numPoints - 1;

    // Pick up four control points
    const YType& P0 = controlY[(i + 0) % numPoints];
    const YType& P1 = controlY[(i + 1) % numPoints];
    const YType& P2 = controlY[(i + 2) % numPoints];
    const YType& P3 = controlY[(i + 3) % numPoints];

    return 0.5 * ((2 * P1) + 
                  (-P0 + P2) * t +
                  (2*P0 - 5*P1 + 4*P2 - P3) * t*t +
                  (-P0 + 3*P1- 3*P2 + P3) * t*t*t);
}

/**
 A cubic spline with regularly spaced 
 control points.  The spline interpolates
 the control points.  The spline
 will wrap from the last point back to the first.

 The t parameter is on the range [0, controlY.size()],
 where integers correspond to control points exactly.

 See also G3D::Spline

 @cite http://www.mvps.org/directx/articles/catmull/
*/
template<class YType> YType cyclicCatmullRomSpline(
    double       t,
    const Array<YType>&  controlY) {

    int numPoints = controlY.size();
    return cyclicCatmullRomSpline(t, controlY.getCArray(), numPoints);
}

}

#endif


