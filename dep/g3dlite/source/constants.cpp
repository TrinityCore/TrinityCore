/**
  @file constants.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  @created 2009-05-20
  @edited  2010-01-29
*/
#include "G3D/constants.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

    const char* PrimitiveType::toString(int i, Value& v) {
        static const char* str[] = {"POINTS", "LINES", "LINE_STRIP", "TRIANGLES", "TRIANGLE_FAN", "QUADS", "QUAD_STRIP", NULL}; 
        static const Value val[] = {POINTS, LINES, LINE_STRIP, TRIANGLES, TRIANGLE_FAN, QUADS, QUAD_STRIP};
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s; 
    }

    const char* RefractionQuality::toString(int i, Value& v) {
        static const char* str[] = {"NONE", "STATIC_ENV", "DYNAMIC_FLAT", "DYNAMIC_FLAT_MULTILAYER", "DYNAMIC_ENV", "BEST", NULL}; 
        static const Value val[] = {NONE, STATIC_ENV, DYNAMIC_FLAT, DYNAMIC_FLAT_MULTILAYER, DYNAMIC_ENV, BEST};
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }

    const char* MirrorQuality::toString(int i, Value& v) {
        static const char* str[] = {"NONE", "STATIC_ENV", "DYNAMIC_PLANAR", "DYNAMIC_ENV", "BEST", NULL}; 
        static const Value val[] = {NONE, STATIC_ENV, DYNAMIC_PLANAR, DYNAMIC_ENV, BEST};
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }

} // G3D
