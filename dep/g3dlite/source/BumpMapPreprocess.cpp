/**
  \file BumpMapPreprocess.cpp

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2010-01-28
  \edited  2010-01-28

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */
#include "G3D/BumpMapPreprocess.h"
#include "G3D/Any.h"
#include "G3D/stringutils.h"

namespace G3D {

BumpMapPreprocess::BumpMapPreprocess(const Any& any) {
    *this = BumpMapPreprocess();
    for (Any::AnyTable::Iterator it = any.table().begin(); it.isValid(); ++it) {
        const std::string& key = toLower(it->key);
        if (key == "lowpassfilter") {
            lowPassFilter = it->value;
        } else if (key == "zextentpixels") {
            zExtentPixels = it->value;
        } else if (key == "scalezbynz") {
            scaleZByNz = it->value;
        } else {
            any.verify(false, "Illegal key: " + it->key);
        }
    }
}


Any BumpMapPreprocess::toAny() const {
    Any any(Any::TABLE, "BumpMapPreprocess");
    any["lowPassFilter"] = lowPassFilter;
    any["zExtentPixels"] = zExtentPixels;
    any["scaleZByNz"] = scaleZByNz;
    return any;
}

}
