/**
  @file Image4.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2007-01-31
  @edited  2011-08-27
*/


#include "G3D/Image4.h"
#include "G3D/Image4unorm8.h"
#include "G3D/Image.h"
#include "G3D/Color3.h"
#include "G3D/Color3unorm8.h"
#include "G3D/Color1.h"
#include "G3D/Color1unorm8.h"
#include "G3D/ImageFormat.h"
#include "G3D/PixelTransferBuffer.h"
#include "G3D/CPUPixelTransferBuffer.h"

namespace G3D {

Image4::Image4(int w, int h, WrapMode wrap) : Map2D<Color4, Color4>(w, h, wrap) {
    setAll(Color4::zero());
}


Image4::Ref Image4::fromImage4unorm8(const shared_ptr<Image4unorm8>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->resize(im->width(), im->height());

    int N = im->width() * im->height();
    const Color4unorm8* src = reinterpret_cast<Color4unorm8*>(im->getCArray());
    for (int i = 0; i < N; ++i) {
        out->data[i] = Color4(src[i]);
    }

    return out;
}


Image4::Ref Image4::createEmpty(int width, int height, WrapMode wrap) {
    return shared_ptr<Image4>(new Type(width, height, wrap));
}


Image4::Ref Image4::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image4::Ref Image4::fromFile(const std::string& filename, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


void Image4::load(const std::string& filename) {
    shared_ptr<Image> image = Image::fromFile(filename);
    if (image->format() != ImageFormat::RGBA32F()) {
        image->convertToRGBA8();
    }

    switch (image->format()->code)
    {
        case ImageFormat::CODE_L8:
            copyArray(static_cast<const Color1unorm8*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        case ImageFormat::CODE_L32F:
            copyArray(static_cast<const Color1*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        case ImageFormat::CODE_RGB8:
            copyArray(static_cast<const Color3unorm8*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        case ImageFormat::CODE_RGB32F:
            copyArray(static_cast<const Color3*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        case ImageFormat::CODE_RGBA8:
            copyArray(static_cast<const Color4unorm8*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        case ImageFormat::CODE_RGBA32F:
            copyArray(static_cast<const Color4*>(image->toPixelTransferBuffer()->buffer()), image->width(), image->height());
            break;
        default:
            debugAssertM(false, "Trying to load unsupported image format");
            break;
    }

    setChanged(true);
}


Image4::Ref Image4::fromArray(const class Color3unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color1unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color4unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


void Image4::copyArray(const Color4unorm8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color4* dst = data.getCArray();
    // Convert int8 -> float
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4(src[i]);
    }
}


void Image4::copyArray(const Color3unorm8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color4* dst = data.getCArray();
    
    // Add alpha and convert
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4(Color3(src[i]), 1.0f);
    }
}


void Image4::copyArray(const Color4* src, int w, int h) {
    resize(w, h);
    System::memcpy(getCArray(), src, w * h * sizeof(Color4));
}


void Image4::copyArray(const Color3* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color4* dst = data.getCArray();
    
    // Add alpha
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4(src[i], 1.0f);
    }
}


void Image4::copyArray(const Color1unorm8* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = Color1(src[i]).value;
        dst[i].a = 1.0f;
    }
}


void Image4::copyArray(const Color1* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = src[i].value;
        dst[i].a = 1.0f;
    }
}


/** Saves in any of the formats supported by G3D::GImage. */
void Image4::save(const std::string& filename) {
    // To avoid saving as floating point image.  FreeImage cannot convert floating point to RGBA8.
    Image4unorm8::Ref unorm8 = Image4unorm8::fromImage4(dynamic_pointer_cast<Image4>(shared_from_this()));
    unorm8->save(filename);
}

const ImageFormat* Image4::format() const {
    return ImageFormat::RGBA32F();
}

} // G3D
