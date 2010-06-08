/**
 @file Random.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2009-01-02
 @edited  2009-03-20

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */
#ifndef G3D_Random_h
#define G3D_Random_h

#include "G3D/platform.h"
#include "G3D/g3dmath.h"
#include "G3D/GMutex.h"

namespace G3D {

/** Random number generator.

    Threadsafe.

    Useful for generating consistent random numbers across platforms
    and when multiple threads are involved.

    Uses the Fast Mersenne Twister (FMT-19937) algorithm.

    On average, uniform() runs about 2x-3x faster than rand().

    @cite http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/SFMT/index.html
    
    On OS X, Random is about 10x faster than drand48() (which is
    threadsafe) and 4x faster than rand() (which is not threadsafe).
 */
class Random {
protected:

    /** Constants (important for the algorithm; do not modify) */
    enum {
        N = 624,
        M = 397,
        R = 31,
        U = 11,
        S = 7,
        T = 15,
        L = 18,
        A = 0x9908B0DF,
        B = 0x9D2C5680,
        C = 0xEFC60000};

    /** 
        Prevents multiple overlapping calls to generate(). 
     */
    Spinlock     lock;

    /** State vector (these are the next N values that will be returned) */
    uint32*      state;

    /** Index into state */
    int          index;

    bool         m_threadsafe;

    /** Generate the next N ints, and store them for readback later.
        Called from bits() */
    virtual void generate();

    /** For subclasses.  The void* parameter is just to distinguish this from the
        public constructor.*/
    Random(void*);

public:

    /** \param threadsafe Set to false if you know that this random
        will only be used on a single thread.  This eliminates the
        lock and improves performance on some platforms.
     */
    Random(uint32 seed = 0xF018A4D2, bool threadsafe = true);

    virtual ~Random();

    /** Each bit is random.  Subclasses can choose to override just 
       this method and the other methods will all work automatically. */
    virtual uint32 bits();

    /** Uniform random integer on the range [min, max] */
    virtual int integer(int min, int max);

    /** Uniform random float on the range [min, max] */
    virtual inline float uniform(float low, float high) {
        // We could compute the ratio in double precision here for
        // about 1.5x slower performance and slightly better
        // precision.
        return low + (high - low) * ((float)bits() / (float)0xFFFFFFFFUL);
    }

    /** Uniform random float on the range [0, 1] */
    virtual inline float uniform() {
        // We could compute the ratio in double precision here for
        // about 1.5x slower performance and slightly better
        // precision.
        const float norm = 1.0f / (float)0xFFFFFFFFUL;
        return (float)bits() * norm;
    }

    /** Normally distributed reals. */
    virtual float gaussian(float mean, float stdev);

    /** Returns 3D unit vectors distributed according to 
        a cosine distribution about the z-axis. */
    virtual void cosHemi(float& x, float& y, float& z);

    /** Returns 3D unit vectors distributed according to a cosine
        power distribution (\f$ \cos^k \theta \f$) about
        the z-axis. */
    virtual void cosPowHemi(const float k, float& x, float& y, float& z);

    /** Returns 3D unit vectors uniformly distributed on the 
        hemisphere about the z-axis. */
    virtual void hemi(float& x, float& y, float& z);

    /** Returns 3D unit vectors uniformly distributed on the sphere */
    virtual void sphere(float& x, float& y, float& z);

    /**
       A shared instance for when the performance and features but not
       consistency of the class are desired.  It is slightly (10%)
       faster to use a distinct instance than to use the common one.
       
       Threadsafe.
    */
    static Random& common();
};

}

#endif
