/**
  @file Image4.h

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2007-01-31
  @edited  2007-01-31
*/


#ifndef G3D_IMAGE4_H
#define G3D_IMAGE4_H

#include "G3D/platform.h"
#include "G3D/Map2D.h"
#include "G3D/Color4.h"
#include "G3D/GImage.h"

namespace G3D {

typedef ReferenceCountedPointer<class Image4> Image4Ref;

/**
 RGBA image with 32-bit floating point storage for each channel.

 Whenever a method needs to convert from RGB to RGBA, A=1 is assumed.

 Bilinear interpolation on Image4 is about 8x faster than on
 Image4uint8 due to the large cost of converting int->float on modern
 machines.

 @sa G3D::Image4uint8, G3D::GImage.
 */
class Image4 : public Map2D<Color4, Color4> {
public:

    typedef Image4      Type;
    typedef ReferenceCountedPointer<class Image4>   Ref;
    typedef Color4      Storage;
    typedef Color4      Compute;

protected:

    Image4(int w, int h, WrapMode wrap);

    void copyGImage(const class GImage& im);
    void copyArray(const Color1* src, int w, int h);
    void copyArray(const Color3* src, int w, int h);
    void copyArray(const Color4* src, int w, int h);
    void copyArray(const Color1uint8* src, int w, int h);
    void copyArray(const Color3uint8* src, int w, int h);
    void copyArray(const Color4uint8* src, int w, int h);

public:

    const class ImageFormat* format() const;

    /** Creates an all-zero width x height image. */
    static Ref createEmpty(int width, int height, WrapMode wrap = WrapMode::ERROR);

    /** Creates a 0 x 0 image. */
    static Ref createEmpty(WrapMode wrap = WrapMode::ERROR);

    static Ref fromFile(const std::string& filename, WrapMode wrap = WrapMode::ERROR, GImage::Format fmt = GImage::AUTODETECT);
    
    static Ref fromArray(const class Color1uint8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color3uint8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color4uint8* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color1* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color3* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);
    static Ref fromArray(const class Color4* ptr, int width, int height, WrapMode wrap = WrapMode::ERROR);

    static Ref fromImage4uint8(const ReferenceCountedPointer<class Image4uint8>& im);

    static Ref fromGImage(const class GImage& im, WrapMode wrap = WrapMode::ERROR);

    /** Loads from any of the file formats supported by G3D::GImage. */
    void load(const std::string& filename, GImage::Format fmt = GImage::AUTODETECT);

    /** Saves in any of the formats supported by G3D::GImage. */
    void save(const std::string& filename, GImage::Format fmt = GImage::AUTODETECT);
};

} // G3D

#endif
