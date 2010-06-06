/**
  @file G3D/filter.h

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2007-03-01
  @edited  2007-03-01

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */
#ifndef G3D_FILTER_H
#define G3D_FILTER_H

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/g3dmath.h"

namespace G3D {
/**
 Generates a set of 1D gaussian filter coefficients of size N.  The coefficients
 are centered on element (N-1)/2 and have standard deviation given by std.  The coefficients
 are normalized such that the sum across coeff is 1.0.

 Matches the results returned by Matlab <code>fspecial('gaussian', [1, N], std)</code>
 */ 
void gaussian1D(Array<float>& coeff, int N = 5, float std = 0.5f);
}

#endif
