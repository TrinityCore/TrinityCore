/**
 @file PrecomputedRandom.cpp
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2009-03-31
 @edited  2009-07-01

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/PrecomputedRandom.h"
#include "G3D/System.h"

namespace G3D {

PrecomputedRandom::PrecomputedRandom(int dataSize, uint32 seed) : 
 Random((void*)NULL),
 m_hemiUniform(NULL),
 m_sphereBits(NULL),
 m_modMask(dataSize - 1),
 m_freeData(true) {

    alwaysAssertM(isPow2(dataSize), "dataSize must be a power of 2");
    m_index = seed & m_modMask;

    HemiUniformData* h;
    SphereBitsData* s;
    m_hemiUniform = h = (HemiUniformData*) System::malloc(sizeof(HemiUniformData) * dataSize);
    m_sphereBits = s = (SphereBitsData*) System::malloc(sizeof(SphereBitsData) * dataSize);

    Random r;

    for (int i = 0; i < dataSize; ++i) {
        h[i].uniform = r.uniform();
        r.cosHemi(h[i].cosHemiX, h[i].cosHemiY, h[i].cosHemiZ); 

        s[i].bits = r.bits();
        r.sphere(s[i].sphereX, s[i].sphereY, s[i].sphereZ);         
    }

}


PrecomputedRandom::PrecomputedRandom(const HemiUniformData* data1, const SphereBitsData* data2, int dataSize, uint32 seed) : 
 Random((void*)NULL),
 m_hemiUniform(data1),
 m_sphereBits(data2),
 m_modMask(dataSize - 1),
 m_freeData(false) {

    m_index = seed & m_modMask;
    alwaysAssertM(isPow2(dataSize), "dataSize must be a power of 2");
}


PrecomputedRandom::~PrecomputedRandom() {
    if (m_freeData) {
        System::free(const_cast<HemiUniformData*>(m_hemiUniform));
        System::free(const_cast<SphereBitsData*>(m_sphereBits));
    }
}

float PrecomputedRandom::uniform(float low, float high) {
    m_index = (m_index + 1) & m_modMask;
    return low + m_hemiUniform[m_index].uniform * (high - low);
}


float PrecomputedRandom::uniform() {
    m_index = (m_index + 1) & m_modMask;
    return m_hemiUniform[m_index].uniform;
}


void PrecomputedRandom::cosHemi(float& x, float& y, float& z) {
    m_index = (m_index + 1) & m_modMask;
    x = m_hemiUniform[m_index].cosHemiX;
    y = m_hemiUniform[m_index].cosHemiY;
    z = m_hemiUniform[m_index].cosHemiZ;
}

void PrecomputedRandom::cosPowHemi(const float k, float& x, float& y, float& z) {
    // Computing a cosPowHemi costs 4 slow functions (pow, sqrt, sin,
    // cos). We can do it with two, given a cosHemi sample, basically
    // saving the cost of sin and cos and making a single 128-byte
    // memory read (for a vector) instead of two (for adjacent uniform
    // floats).

    // cos^1 distribution sample
    float cos1;
    cosHemi(x, y, cos1);

    // Fix the distribution by adjusting the cosine:
    // rnd(cos^k t) = (rnd(cos(t))^2)^(1/k)
    
    // produces cos^k distribution sample
    z = pow(cos1, 2.0f / (1.0f + k));

    // Rescale x and y by sqrt(1.0f - square(z)) / sqrt(x*x + y*y).
    // Add a very tiny offset to handle the (almost impossibly unlikely) case where
    // z = 1 and x^2+y^2 = 0.
    static const float eps = 0.000001f;
    const float s = sqrt((1.0f + eps - square(z)) / (square(x) + square(y) + eps));

    x *= s;
    y *= s;
}


uint32 PrecomputedRandom::bits() {
    m_index = (m_index + 1) & m_modMask;
    return m_sphereBits[m_index].bits;
}


void PrecomputedRandom::sphere(float& x, float& y, float& z) {
    m_index = (m_index + 1) & m_modMask;
    x = m_sphereBits[m_index].sphereX;
    y = m_sphereBits[m_index].sphereY;
    z = m_sphereBits[m_index].sphereZ;
}

}
