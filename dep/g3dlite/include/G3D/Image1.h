/**
  \file G3D/Image1.h

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2007-01-31
  \edited  2011-08-31
*/


#ifndef G3D_Image1_h
#define G3D_Image1_h

#include "G3D/platform.h"
#include "G3D/Map2D.h"
#include "G3D/Color1.h"

namespace G3D {

typedef shared_ptr<class Image1> Image1Ref;

/**
 Luminance image with 32-bit floating point storage.

 See also G3D::Image1unorm8, G3D::GImage.
 */
class Image1 : public Map2D<Color1, Color1> {
public:

    typedef Image1      Type;
    typedef shared_ptr<class Image1>   Ref;
    typedef Color1      Storage;
    typedef Color1      Compute;

protected:

    Image1(int w, int h, WrapMode wrap);

    void copyGImage(const class GImage& im);
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

    static Ref fromImage1unorm8(const shared_ptr<class Image1unorm8>& im);

    /** Loads from any of the file formats supported by G3D::Image.

        If there is an alpha channel on the input, it is stripped.
        Values are automatically scaled to the range [0, 1]. */
    void load(const std::string& filename);

    /** Saves in any of the formats supported by G3D::Image. 

        The data values are assumed to be on the range [0, 1] and will
        be scaled appropriately for the save format.*/
    void save(const std::string& filename);
};

} // G3D

#endif
