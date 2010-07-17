/**
  @file EqualsTrait.h

  @maintainer Morgan McGuire, morgan@cs.williams.edu
  @created 2008-10-01
  @edited  2008-10-01
  Copyright 2000-2008, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_EQUALSTRAIT_H
#define G3D_EQUALSTRAIT_H

#include "G3D/platform.h"

/** Default implementation of EqualsTrait.
    @see G3D::Table for specialization requirements.
*/
template<typename Key> struct EqualsTrait {
    static bool equals(const Key& a, const Key& b) {
        return a == b;
    }
};

#endif

