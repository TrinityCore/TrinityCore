/**
  \file BumpMapPreprocess.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2010-01-28
  \edited  2010-01-28

  Copyright 2000-2012, Morgan McGuire.
  All rights reserved.
 */

#ifndef G3D_BumpMapPreprocess_h
#define G3D_BumpMapPreprocess_h

#include "G3D/platform.h"

namespace G3D {
class Any;

/** 
Not in the BumpMap class to avoid a circular dependency between Texture and BumpMap.
G3D::Image::computeNormalMap().
*/
class BumpMapPreprocess {
public:

    /** If true, the elevations are box filtered after computing normals
     and before uploading, which produces better results for parallax offset mapping
     Defaults to false. */
    bool            lowPassFilter;

    /** Height of the maximum ("white") value, in pixels, for the purpose of computing normals.
       A value of 255 means that a 255 x 255 bump image with a full black-to-white gradient
         will produce a 45-degree ramp (this also results in "cubic" voxels).
         A negative value means to set zExtentPixels to -zExtentPixels * max(width, height).
         The default is -0.02.
     */
    float           zExtentPixels;

    /** After computing normals, scale the height by |N.z|, a trick that reduces texture swim in steep areas for parallax offset 
      mapping. Defaults to false.*/
    bool            scaleZByNz;

    BumpMapPreprocess() : lowPassFilter(false), zExtentPixels(-0.02f), scaleZByNz(false) {}

    BumpMapPreprocess(const Any& any);

    Any toAny() const;

    bool operator==(const BumpMapPreprocess& other) const {
        return 
            (lowPassFilter == other.lowPassFilter) &&
            (zExtentPixels == other.zExtentPixels) &&
            (scaleZByNz == other.scaleZByNz);
    }
};

}

#endif
