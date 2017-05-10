/**
  \file G3D/Image4.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2007-01-31
  \edited  2011-08-11
*/


#ifndef G3D_Image4_h
#define G3D_Image4_h

#include "G3D/platform.h"
#include "G3D/Map2D.h"
#include "G3D/Color4.h"

namespace G3D {

typedef shared_ptr<class Image4> Image4Ref;

/**
 RGBA image with 32-bit floating point storage for each channel.

 Whenever a method needs to convert from RGB to RGBA, A=1 is assumed.

 Bilinear interpolation on Image4 is about 8x faster than on
 Image4unorm8 due to the large cost of converting int->float on modern
 machines.

 @sa G3D::Image4unorm8, G3D::GImage.
 */
class Image4 : public Map2D<Color4, Color4> {
public:

    typedef Image4      Type;
    typedef shared_ptr<class Image4>   Ref;

protected:

    Image4(int w, int h, WrapMode wrap);

    void copyArray(const Color1* src, int w, int h);
    void copyArray(const Color3* src, int w, int h);
    void copyArray(const Color4* src, int w, int h);
    void copyArray(const Color1unorm8* src, int w, int h);
    void copyArray(const Color3unorm8* src, int w, int h);
    void copyArray(const Color4unorm8* src, int w, int h);

public:

    const class ImageFormat* format() const;

    /** Creates an all-zero width x height image. */
    static Ref createEmpty(int width, int height, WrapMode wrap = WrapMode::ERROR);

    /** Creates a 0 x 0 image. */
    static Ref createEmpty(WrapMode wrap = WrapMode::ERROR);

    static Ref fromFile(const std::string& filename, WrapMode wrap = WrapMode::ERROR);
    
    static Ref fromArray(const class Color1unorm8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color3unorm8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color4unorm8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color1* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color3* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color4* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);

    static Ref fromImage4unorm8(const shared_ptr<class Image4unorm8>& im);

    /** Loads from any of the file formats supported by G3D::GImage. */
    void load(const std::string& filename);

    /** Saves in any of the formats supported by G3D::GImage. */
    void save(const std::string& filename);
};

} // G3D

#endif
