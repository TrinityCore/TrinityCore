/**
 @file PrecomputedRandom.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @created 2009-03-31
 @edited  2009-03-31

 Copyright 2000-2009, Morgan McGuire.
 All rights reserved.
 */
#ifndef G3D_PrecomputedRandom_h
#define G3D_PrecomputedRandom_h

#include "G3D/platform.h"
#include "G3D/Random.h"

namespace G3D {

/** Fast random numbers using a precomputed data table. 

    e.g., generates cosHemi about 13x faster than Random.
    This is useful for quickly generating seeded random 
    numbers for reproducibility.  G3D::Random takes a long
    time to seed; this is instantaneous (providing the 
    precomputed data is already available.)

    Not threadsafe.*/
class PrecomputedRandom : public Random {
public:
    /** Put the cosHemi and the uniform together so that when
        alternating between them we stay in cache. This is also packed
        into a good size for SIMD and GPU operations.*/
    class HemiUniformData {
    public:
        float   cosHemiX;
        float   cosHemiY;
        float   cosHemiZ;
        float   uniform;
    };

    class SphereBitsData {
    public:
        float   sphereX;
        float   sphereY;
        float   sphereZ;
        uint32  bits;
    };

protected:

    /** Array of 2^n elements. */
    const HemiUniformData*      m_hemiUniform;
    const SphereBitsData*       m_sphereBits;

    /** 2^n - 1; the AND mask for computing a fast modulo */
    int                         m_modMask;

    int                         m_index;

    /** If true, free m_hemiUniform and m_sphereBits in destructor */
    bool                        m_freeData;

public:

    /*
      \param dataSize Must be a power of 2
      \param data Will NOT be deleted by the destructor.
     */
    PrecomputedRandom(const HemiUniformData* data1, const SphereBitsData* data2, int dataSize, uint32 seed = 0xF018A4D2);

    /**
      \param dataSize Number of random numbers that can be requested before periodicity.  Must be a power of 2.
      */
    PrecomputedRandom(int dataSize, uint32 seed = 0xF018A4D2);

    ~PrecomputedRandom();

    /** Each bit is random.  Subclasses can choose to override just 
       this method and the other methods will all work automatically. */
    virtual uint32 bits();

    // integer is inherited

    /** Uniform random float on the range [min, max] */
    virtual float uniform(float low, float high);

    /** Uniform random float on the range [0, 1] */
    virtual float uniform();

    // gaussian is inherited

    /** Returns 3D unit vectors distributed according to 
        a cosine distribution about the z axis. */
    virtual void cosHemi(float& x, float& y, float& z);

    /** Returns 3D unit vectors distributed according to a cosine
        power distribution (\f$ \mbox{cos}^k \theta \f$) about
        the z-axis. */
    virtual void cosPowHemi(const float k, float& x, float& y, float& z);

    // hemi is inherited

    /** Returns 3D unit vectors uniformly distributed on the sphere */
    virtual void sphere(float& x, float& y, float& z);
};

}

#endif
