/**
  \file constants.cpp

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu
  \created 2009-05-20
  \edited  2013-09-27
*/
#include "G3D/constants.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

// TODO: Remove February 2014, used for String benchmark
const char* libraryString = "libraryString";

const char* PrimitiveType::toString(int i, Value& v) {
    static const char* str[] = {"POINTS", "LINES", "LINE_STRIP", "TRIANGLES", "TRIANGLE_FAN", "QUADS", "QUAD_STRIP", NULL}; 
    static const Value val[] = {POINTS, LINES, LINE_STRIP, TRIANGLES, TRIANGLE_FAN, QUADS, QUAD_STRIP};
    const char* s = str[i];
    if (s) {
        v = val[i];
    }
    return s; 
}

} // G3D
