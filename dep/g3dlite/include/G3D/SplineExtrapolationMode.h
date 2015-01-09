/** 
  \file G3D/SplineExtrapolationMode.h
 
  \maintainer Michael Mara, http://graphics.cs.williams.edu
 
  \created 2013-01-24
  \edited  2013-01-24

  Copyright 2000-2013, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_SplineExtrapolationMode_h
#define G3D_SplineExtrapolationMode_h

#include "G3D/platform.h"
#include "G3D/enumclass.h"


namespace G3D {

/** 
  Describes the behavior of G3D::Spline, etc. when accessing a time outside of the control point range.

  Refer to these as scoped enums, e.g., <code>SplineExtrapolationMode m = SplineExtrapolationMode::CLAMP;</code>.

  Uses the "Intelligent Enum" design pattern 
  http://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4001/
 */ 
class SplineExtrapolationMode {
public:
    /** Don't use this enum; use SplineExtrapolationMode instances instead. */
    enum Value {
        CYCLIC,
        LINEAR,
        CLAMP
    };
    Value value;
private:
    
    static const char* toString(int i, Value& v) {
        static const char* str[] = {"CYCLIC", "LINEAR", "CLAMP", NULL}; 
        static const Value val[] = {CYCLIC, LINEAR, CLAMP};
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }

public:

    G3D_DECLARE_ENUM_CLASS_METHODS(SplineExtrapolationMode);
};




/** 
  Describes the behavior of G3D::Spline
 */ 
class SplineInterpolationMode {
public:
    /** Don't use this enum; use SplineExtrapolationMode instances instead. */
    enum Value {
        LINEAR,
        CUBIC
    };
    Value value;
private:
    
    static const char* toString(int i, Value& v) {
        static const char* str[] = {"LINEAR", "CUBIC", NULL}; 
        static const Value val[] = {LINEAR, CUBIC};
        const char* s = str[i];
        if (s) {
            v = val[i];
        }
        return s;
    }

public:

    G3D_DECLARE_ENUM_CLASS_METHODS(SplineInterpolationMode);

};


} // namespace G3D

G3D_DECLARE_ENUM_CLASS_HASHCODE(G3D::SplineExtrapolationMode);
G3D_DECLARE_ENUM_CLASS_HASHCODE(G3D::SplineInterpolationMode);

#endif
