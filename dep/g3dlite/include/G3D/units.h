/**
 @file units.h

 @maintainer Morgan McGuire, http://graphics.cs.williams.edu

 @created 2009-08-21
 @edited  2009-08-21
 */
#ifndef G3D_units_h
#define G3D_units_h

#include "G3D/platform.h"

namespace G3D {
/** Use <code>using namespace G3D::units;</code> to include all units
 into your program.  The units system is specifically designed not to
 be general but to support commonly used units efficiently and
 clearly.  See http://en.wikipedia.org/wiki/SI_prefix for interesting facts
 about SI/metric units and full definitions.*/
namespace units {

/** 1e-9 m */
inline float nanometers() {
    return 1e-9f;
}

/** 1e-6 m */
inline float micrometers() {
    return 1e-6f;
}

/** 0.001 m */
inline float millimeters() {
    return 0.001f;
}

/** 0.01 m */
inline float centimeters() {
    return 0.01f;
}

/** SI base unit of distance measure. */
inline float meters() {
    return 1.0f;
}

/** 1000 m */
inline float kilometers() {
    return 100.0f;
}

/** 0.0254 m */
inline float inches() {
    return 0.0254f;
}

/** 0.3048 m */
inline float feet() {
    return 0.3048f;
}

/** 0.9144 m */
inline float yards() {
    return 0.9144f;
}

/** 1609.344 m */
inline float miles() {
    return 1609.344f;
}

/////////////////////////////////////////////////////////////

/** SI base unit of angular measure. */
inline float radians() {
    return 1.0f;
}

/** pi/180 */
inline float degrees() {
    return 0.0174532925f;
}

//////////////////////////////////////////////////////////////

/** 1e-9 s */
inline float nanoseconds() {
    return 1e-9f;
}

/** 1e-3 s */
inline float milliseconds() {
    return 1e-3f;
}

/** Base unit of time */
inline float seconds() {
    return 1.0;
}

/** 60 s */
inline float minutes() {
    return 60.0f;
}

/** 3600 s */
inline float hours() {
    return 3600.0f;
}

/** 86400 s */
inline float days() {
    return 86400.0f;
}

/**  31556926 s */
inline float years() {
    return 31556926.0f;
}

///////////////////////////////////////////

}
}

#endif
