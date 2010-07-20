/**
 @file g3dmath.inl

  @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2001-06-02
 @edited  2006-01-14
 */

#include <stdlib.h>

#ifdef _MSC_VER
// Disable conditional expression is constant, which occurs incorrectly on inlined functions
#   pragma warning (push)
#   pragma warning( disable : 4127 )
#endif

namespace G3D {

inline bool isNaN(double x) {
    bool b1  = (x < 0.0);
    bool b2  = (x >= 0.0);
    bool b3  = !(b1 || b2);
    return b3;
}

inline bool isFinite(double x) {
    return ! isNaN(x) && (x < G3D::inf()) && (x > -G3D::inf());
}

//----------------------------------------------------------------------------
inline int iAbs (int iValue) {
    return ( iValue >= 0 ? iValue : -iValue );
}

//----------------------------------------------------------------------------
inline int iCeil (double fValue) {
    return int(::ceil(fValue));
}

//----------------------------------------------------------------------------

inline int iClamp(int val, int low, int hi) {
    debugAssert(low <= hi);
    if (val <= low) {
        return low;
    } else if (val >= hi) {
        return hi;
    } else {
        return val;
    }
}

//----------------------------------------------------------------------------

inline double clamp(double val, double low, double hi) {
    debugAssert(low <= hi);
    if (val <= low) {
        return low;
    } else if (val >= hi) {
        return hi;
    } else {
        return val;
    }
}

inline float clamp(float val, float low, float hi) {
    debugAssert(low <= hi);
    if (val <= low) {
        return low;
    } else if (val >= hi) {
        return hi;
    } else {
        return val;
    }
}
//----------------------------------------------------------------------------

inline int iWrap(int val, int hi) {
    if (val < 0) {
        return ((val % hi) + hi) % hi;
    } else {
        return val % hi;
    }
}

//----------------------------------------------------------------------------
inline int iFloor (double fValue) {
    return int(::floor(fValue));
}

//----------------------------------------------------------------------------
inline int iSign (int iValue) {
    return ( iValue > 0 ? + 1 : ( iValue < 0 ? -1 : 0 ) );
}

inline int iSign (double fValue) {
    return ( fValue > 0.0 ? + 1 : ( fValue < 0.0 ? -1 : 0 ) );
}

//----------------------------------------------------------------------------
inline double abs (double fValue) {
    return double(::fabs(fValue));
}

//----------------------------------------------------------------------------
inline double aCos (double fValue) {
    if ( -1.0 < fValue ) {
        if ( fValue < 1.0 )
            return double(::acos(fValue));
        else
            return 0.0;
    } else {
        return G3D_PI;
    }
}

//----------------------------------------------------------------------------
inline double aSin (double fValue) {
    if ( -1.0 < fValue ) {
        if ( fValue < 1.0 ) {
            return double(::asin(fValue));
        } else {
            return -G3D_HALF_PI;
        }
    } else {
        return G3D_HALF_PI;
    }
}

//----------------------------------------------------------------------------
inline double aTan (double fValue) {
    return double(::atan(fValue));
}

//----------------------------------------------------------------------------
inline double aTan2 (double fY, double fX) {
    return double(::atan2(fY, fX));
}

//----------------------------------------------------------------------------
inline double sign (double fValue) {
    if (fValue > 0.0) {
        return 1.0;
    }

    if (fValue < 0.0) {
        return -1.0;
    }

    return 0.0;
}

inline double G3D_DEPRECATED unitRandom () {
    return double(::rand()) / double(RAND_MAX);
}

inline float uniformRandom(float low, float hi) {
    return (hi - low) * float(::rand()) / float(RAND_MAX) + low;
}

//----------------------------------------------------------------------------
inline double G3D_DEPRECATED symmetricRandom () {
    return 2.0 * double(::rand()) / double(RAND_MAX) - 1.0;
}

//----------------------------------------------------------------------------
inline double square(double x) {
    return x * x;
}

//----------------------------------------------------------------------------
inline double sumSquares(double x, double y) {
    return x*x + y*y;
}

//----------------------------------------------------------------------------
inline double sumSquares(double x, double y, double z) {
    return x*x + y*y + z*z;
}

//----------------------------------------------------------------------------
inline double distance(double x, double y) {
    return sqrt(sumSquares(x, y));
}

//----------------------------------------------------------------------------
inline double distance(double x, double y, double z) {
    return sqrt(sumSquares(x, y, z));
}

//----------------------------------------------------------------------------

/** @deprecated use G3D::min */
inline int iMin(int x, int y) {
    return (x >= y) ? y : x;
}

//----------------------------------------------------------------------------
/** @deprecated use G3D::min */
inline int iMax(int x, int y) {
    return (x >= y) ? x : y;
}

//----------------------------------------------------------------------------
inline int ceilPow2(unsigned int in) {
    in -= 1;

    in |= in >> 16;
    in |= in >> 8;
    in |= in >> 4;
    in |= in >> 2;
    in |= in >> 1;

    return in + 1;
}

inline bool isPow2(int num) {
    return ((num & -num) == num);
}

inline bool isOdd(int num) {
    return (num & 1) == 1;
}

inline bool isEven(int num) {
    return (num & 1) == 0;
}

inline double toRadians(double deg) {
    return deg * G3D_PI / 180.0;
}

inline double toDegrees(double rad) {
    return rad * 180.0 / G3D_PI;
}

/**
 Computes an appropriate epsilon for comparing a and b.
 */
inline double eps(double a, double b) {
    // For a and b to be nearly equal, they must have nearly
    // the same magnitude.  This means that we can ignore b
    // since it either has the same magnitude or the comparison
    // will fail anyway.
    (void)b;
    const double aa = abs(a) + 1;
    if (aa == inf()) {
        return fuzzyEpsilon;
    } else {
        return fuzzyEpsilon * aa;
    }
}

inline bool fuzzyEq(double a, double b) {
    return (a == b) || (abs(a - b) <= eps(a, b));
}

inline bool fuzzyNe(double a, double b) {
    return ! fuzzyEq(a, b);
}

inline bool fuzzyGt(double a, double b) {
    return a > b + eps(a, b);
}

inline bool fuzzyGe(double a, double b) {
    return a > b - eps(a, b);
}

inline bool fuzzyLt(double a, double b) {
    return a < b - eps(a, b);
}

inline bool fuzzyLe(double a, double b) {
    return a < b + eps(a, b);
}

inline int iMod3(int x) {
    return x % 3;
}

} // namespace G3D

#ifdef _MSC_VER
// Disable conditional expression is constant, which occurs incorrectly on inlined functions
#   pragma warning (pop)
#endif
