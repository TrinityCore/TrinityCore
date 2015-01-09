/**
  \file G3D/Image3.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2007-01-31
  \edited  2011-08-31
*/


#ifndef G3D_IMAGE3_H
#define G3D_IMAGE3_H

#include "G3D/platform.h"
#include "G3D/Map2D.h"
#include "G3D/Color3.h"

namespace G3D {

typedef shared_ptr<class Image3> Image3Ref;

/**
 RGB image with 32-bit floating point storage for each channel.

 See also G3D::Image3unorm8, G3D::GImage.
 */
class Image3 : public Map2D<Color3, Color3> {
public:

    typedef Image3      Type;
    typedef shared_ptr<class Image3>   Ref;

protected:

    Image3(int w, int h, WrapMode wrap);

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

    static Ref fromImage3unorm8(const shared_ptr<class Image3unorm8>& im);

    /** Loads from any of the file formats supported by G3D::GImage.  If there is an alpha channel on the input,
        it is stripped. Converts 8-bit formats to the range (0, 1) */
    void load(const std::string& filename);

    /** Saves in any of the formats supported by G3D::GImage. Assumes the data is on the range (0, 1) if saving to an 8-bit format.*/
    void save(const std::string& filename);
};

} // G3D

#endif
