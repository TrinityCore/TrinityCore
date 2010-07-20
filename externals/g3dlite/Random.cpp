/**
 @file Random.cpp
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2009-01-02
 @edited  2009-03-29

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */
#include "G3D/Random.h"

namespace G3D {

Random& Random::common() {
    static Random r;
    return r;
}

Random::Random(void* x) : state(NULL), m_threadsafe(false) {
    (void)x;
}


Random::Random(uint32 seed, bool threadsafe) : m_threadsafe(threadsafe) {
    const uint32 X = 1812433253UL;

    state = new uint32[N];
    state[0] = seed;
    for (index = 1; index < (int)N; ++index) {
        state[index] = X * (state[index - 1] ^ (state[index - 1] >> 30)) + index;
    }
}


Random::~Random() {
    delete[] state;
    state = NULL;
}


uint32 Random::bits() {
    // See http://en.wikipedia.org/wiki/Mersenne_twister

    // Make a local copy of the index variable to ensure that it
    // is not out of bounds
    int localIndex = index;

    // Automatically checks for index < 0 if corrupted
    // by unsynchronized threads.
    if ((unsigned int)localIndex >= (unsigned int)N) {
        generate();
        localIndex = 0;
    }
    // Increment the global index.  It may go out of bounds on
    // multiple threads, but the above check ensures that the
    // array index actually used never goes out of bounds.
    // It doesn't matter if we grab the same array index twice
    // on two threads, since the distribution of random numbers
    // will still be uniform.
    ++index;
    // Return the next random in the sequence
    uint32 r = state[localIndex];

    // Temper the result
    r ^=  r >> U;
    r ^= (r << S) & B;
    r ^= (r << T) & C;
    r ^=  r >> L;
    
    return r;    
}


/** Generate the next N ints, and store them for readback later */
void Random::generate() {
    // Lower R bits
    static const uint32 LOWER_MASK = (1LU << R) - 1;

    // Upper (32 - R) bits
    static const uint32 UPPER_MASK = 0xFFFFFFFF << R;
    static const uint32 mag01[2] = {0UL, (uint32)A};

    if (m_threadsafe) {
        bool contention = ! lock.lock();
        if (contention)  {
            // Another thread just generated a set of numbers; no need for
            // this thread to do it too
            lock.unlock();
            return;
        }
    }

    // First N - M
    for (unsigned int i = 0; i < N - M; ++i) {    
        uint32 x = (state[i] & UPPER_MASK) | (state[i + 1] & LOWER_MASK);
        state[i] = state[i + M] ^ (x >> 1) ^ mag01[x & 1];
    }

    // Rest
    for (unsigned int i = N - M + 1; i < N - 1; ++i) {    
        uint32 x = (state[i] & UPPER_MASK) | (state[i + 1] & LOWER_MASK);
        state[i] = state[i + (M - N)] ^ (x >> 1) ^ mag01[x & 1];
    }
        
    uint32 y = (state[N - 1] & UPPER_MASK) | (state[0] & LOWER_MASK);
    state[N - 1] = state[M - 1] ^ (y >> 1) ^ mag01[y & 1];
    index = 0;

    if (m_threadsafe) {
        lock.unlock();
    }
}

    
int Random::integer(int low, int high) {
    int r = iFloor(low + (high - low + 1) * (double)bits() / 0xFFFFFFFFUL);

    // There is a *very small* chance of generating
    // a number larger than high.
    if (r > high) {
        return high;
    } else {
        return r;
    }
}

    
float Random::gaussian(float mean, float stdev) {

    // Using Box-Mueller method from http://www.taygeta.com/random/gaussian.html
    // Modified to specify standard deviation and mean of distribution
    float w, x1, x2;

    // Loop until w is less than 1 so that log(w) is negative
    do {
        x1 = uniform(-1.0, 1.0);
        x2 = uniform(-1.0, 1.0);

        w = float(square(x1) + square(x2));
    } while (w > 1.0f);

    // Transform to gassian distribution
    // Multiply by sigma (stdev ^ 2) and add mean.
    return x2 * (float)square(stdev) * sqrtf((-2.0f * logf(w) ) / w) + mean; 
}


void Random::cosHemi(float& x, float& y, float& z) {
    const float e1 = uniform();
    const float e2 = uniform();

    // Jensen's method 
    const float sin_theta = sqrtf(1.0f - e1);
    const float cos_theta = sqrtf(e1);
    const float phi = 6.28318531f * e2;

    x = cos(phi) * sin_theta;
    y = sin(phi) * sin_theta;
    z = cos_theta;

    // We could also use Malley's method (pbrt p.657), since they are the same cost:
    //
    //  r = sqrt(e1);
    //  t = 2*pi*e2;
    //  x = cos(t)*r;
    //  y = sin(t)*r;
    //  z = sqrt(1.0 - x*x + y*y);
}


void Random::cosPowHemi(const float k, float& x, float& y, float& z) {
    const float e1 = uniform();
    const float e2 = uniform();

    const float cos_theta = pow(e1, 1.0f / (k + 1.0f));
    const float sin_theta = sqrtf(1.0f - square(cos_theta));
    const float phi = 6.28318531f * e2;

    x = cos(phi) * sin_theta;
    y = sin(phi) * sin_theta;
    z = cos_theta;
}


void Random::hemi(float& x, float& y, float& z) {
    sphere(x, y, z);
    z = fabsf(z);
}


void Random::sphere(float& x, float& y, float& z) {
    // Squared magnitude
    float m2;

    // Rejection sample
    do {
        x = uniform() * 2.0f - 1.0f, 
        y = uniform() * 2.0f - 1.0f,
        z = uniform() * 2.0f - 1.0f;
        m2 = x*x + y*y + z*z;
    } while (m2 >= 1.0f);

    // Divide by magnitude to produce a unit vector
    float s = rsqrt(m2);
    x *= s;
    y *= s;
    z *= s;
}

} // G3D
