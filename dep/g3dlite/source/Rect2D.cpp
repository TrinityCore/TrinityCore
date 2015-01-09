/**
 @file Rect2D.cpp
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
  
  @created 2003-11-13
  @created 2011-06-16

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#include "G3D/platform.h"
#include "G3D/Rect2D.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

namespace G3D {

const Rect2D& Rect2D::empty() {
    static Rect2D r;
    return r;
}


void Rect2D::serialize(class BinaryOutput& b) const {
    min.serialize(b);
    max.serialize(b);
}

    
void Rect2D::deserialize(class BinaryInput& b) {
    min.deserialize(b);
    max.deserialize(b);
}


/** \param any Must either Rect2D::xywh(#, #, #, #) or Rect2D::xyxy(#, #, #, #)*/
Rect2D::Rect2D(const Any& any) {
    if (any.name() == "Rect2D::empty" || any.name() == "AABox2D::empty") {
        *this = empty();
        return;
    }

    any.verifyName("Rect2D::xyxy", "Rect2D::xywh");
    any.verifyType(Any::ARRAY);
    any.verifySize(4);
    if (any.name() == "Rect2D::xywh") {
        *this = Rect2D::xywh(any[0], any[1], any[2], any[3]);
    } else {
        *this = Rect2D::xyxy(any[0], any[1], any[2], any[3]);
    }
}


/** Converts the Rect2D to an Any. */
Any Rect2D::toAny() const {
    if (isEmpty()) {
        return Any(Any::ARRAY, "Rect2D::empty");
    } else {
        Any any(Any::ARRAY, "Rect2D::xywh");
        any.append(Any(x0()), Any(y0()), Any(width()), Any(height()));
        return any;
    }
}

}
