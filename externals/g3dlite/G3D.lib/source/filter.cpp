/**
  @file filter.cpp

  @author Morgan McGuire, matrix@graphics3d.com
  @created 2007-03-01
  @edited  2007-03-01

  Copyright 2000-2007, Morgan McGuire.
  All rights reserved.
 */
#include "G3D/filter.h"

namespace G3D {

void gaussian1D(Array<float>& coeff, int N, float std) {
    coeff.resize(N);
    float sum = 0.0f;
    for (int i = 0; i < N; ++i) {
        float x = i - (N - 1) / 2.0f;
        float p = -square(x / std) / 2.0f;
        float y = exp(p);
        coeff[i] = y;
        sum += y;
    }

    for (int i = 0; i < N; ++i) {
        coeff[i] /= sum;
    }   
}


} // namespace
