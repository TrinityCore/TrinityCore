/**
 @file g3dmath.cpp
 
 @author Morgan McGuire, graphics3d.com
  
 @created 2001-06-02
 @edited  2004-02-24
 */

#include "G3D/g3dmath.h"
#include <cstdlib>
#include <cstring>

namespace G3D {

float gaussRandom(float mean, float stdev) {

    // Using Box-Mueller method from http://www.taygeta.com/random/gaussian.html
    // Modified to specify standard deviation and mean of distribution
    float w, x1, x2;

    // Loop until w is less than 1 so that log(w) is negative
    do {
        x1 = uniformRandom(-1.0, 1.0);
        x2 = uniformRandom(-1.0, 1.0);

        w = float(square(x1) + square(x2));
    } while (w > 1.0f);

    // Transform to gassian distribution
    // Multiply by sigma (stdev ^ 2) and add mean.
    return x2 * (float)square(stdev) * sqrtf((-2.0f * logf(w) ) / w) + mean; 
}

/** 
    This value should not be tested against directly, instead
    G3D::isNan() and G3D::isFinite() will return reliable results. */
double inf() {
    return std::numeric_limits<double>::infinity();
}

bool isNaN(float x) {
    static const float n = nan();
    return memcmp(&x, &n, sizeof(float)) == 0;
}

bool isNaN(double x) {
    static const double n = nan();
    return memcmp(&x, &n, sizeof(double)) == 0;
}


/** 
    This value should not be tested against directly, instead
    G3D::isNan() and G3D::isFinite() will return reliable results. */
float finf() {
    return std::numeric_limits<float>::infinity();
}

/** This value should not be tested against directly, instead
    G3D::isNan() and G3D::isFinite() will return reliable results. */
double nan() {
    // double is a standard type and should have quiet NaN
    return std::numeric_limits<double>::quiet_NaN();
}

float fnan() {
    // double is a standard type and should have quiet NaN
    return std::numeric_limits<float>::quiet_NaN();
}


int highestBit(uint32 x) {
    // Binary search.
    int base = 0;

    if (x & 0xffff0000)	{
        base = 16;
        x >>= 16;
    }
    if (x & 0x0000ff00) {
        base += 8;
        x >>= 8;
    }
    if (x & 0x000000f0) {
        base += 4;
        x >>= 4;
    }
    
    static const int lut[] = {-1,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3};
    return base + lut[x];
}


int iRandom(int low, int high) {
    int r = iFloor(low + (high - low + 1) * (double)rand() / RAND_MAX);
    
    // There is a *very small* chance of generating
    // a number larger than high.
    if (r > high) {
        return high;
    } else {
        return r;
    }
}


}
