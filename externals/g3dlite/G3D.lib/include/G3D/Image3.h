/**
  @file Image3.h

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2007-01-31
  @edited  2007-01-31
*/


#ifndef G3D_IMAGE3_H
#define G3D_IMAGE3_H

#include "G3D/platform.h"
#include "G3D/Map2D.h"
#include "G3D/Color3.h"
#include "G3D/GImage.h"

namespace G3D {

typedef ReferenceCountedPointer<class Image3> Image3Ref;

/**
 RGB image with 32-bit floating point storage for each channel.

 See also G3D::Image3uint8, G3D::GImage.
 */
class Image3 : public Map2D<Color3, Color3> {
public:

    typedef Image3      Type;
    typedef Image3Ref   Ref;

protected:

    Image3(int w, int h, WrapMode wrap);

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

    static Ref fromImage3uint8(const ReferenceCountedPointer<class Image3uint8>& im);

    static Ref fromGImage(const class GImage& im, WrapMode wrap = WrapMode::ERROR);

    /** Loads from any of the file formats supported by G3D::GImage.  If there is an alpha channel on the input,
        it is stripped. */
    void load(const std::string& filename, GImage::Format fmt = GImage::AUTODETECT);

    /** Saves in any of the formats supported by G3D::GImage. */
    void save(const std::string& filename, GImage::Format fmt = GImage::AUTODETECT);
};

} // G3D

#endif
