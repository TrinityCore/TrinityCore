/**
  \file G3D/Image1.cpp

  \maintainer Morgan McGuire, http://graphics.cs.williams.edu

  \created 2007-01-31
  \edited  2012-12-25
*/


#include "G3D/Image1.h"
#include "G3D/Image1unorm8.h"
#include "G3D/Image.h"
#include "G3D/Color4.h"
#include "G3D/Color4unorm8.h"
#include "G3D/Color1.h"
#include "G3D/Color1unorm8.h"
#include "G3D/ImageFormat.h"
#include "G3D/PixelTransferBuffer.h"
#include "G3D/CPUPixelTransferBuffer.h"

namespace G3D {

Image1::Image1(int w, int h, WrapMode wrap) : Map2D<Color1, Color1>(w, h, wrap) {
    setAll(Color1(0.0f));
}


Image1::Ref Image1::fromImage1unorm8(const shared_ptr<Image1unorm8>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->resize(im->width(), im->height());

    int N = im->width() * im->height();
    const Color1unorm8* src = reinterpret_cast<Color1unorm8*>(im->getCArray());
    for (int i = 0; i < N; ++i) {
        out->data[i] = Color1(src[i]);
    }

    return out;
}


Image1::Ref Image1::createEmpty(int width, int height, WrapMode wrap) {
    return Image1::Ref(new Type(width, height, wrap));
}


Image1::Ref Image1::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image1::Ref Image1::fromFile(const std::string& filename, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


void Image1::load(const std::string& filename) {
    shared_ptr<Image> image = Image::fromFile(filename);
    if (image->format() != ImageFormat::L32F()) {
        image->convertToL8();
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


Image1::Ref Image1::fromArray(const class Color3unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color1unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color4unorm8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}

void Image1::copyArray(const Color3unorm8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color1* dst = data.getCArray();
    // Convert int8 -> float
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1(Color3(src[i]).average());
    }
}


void Image1::copyArray(const Color4unorm8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color1* dst = data.getCArray();
    
    // Strip alpha and convert
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1(Color3(src[i].rgb()).average());
    }
}


void Image1::copyArray(const Color1* src, int w, int h) {
    resize(w, h);
    System::memcpy(getCArray(), src, w * h * sizeof(Color1));
}


void Image1::copyArray(const Color4* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color1* dst = data.getCArray();
    
    // Strip alpha
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1(src[i].rgb().average());
    }
}


void Image1::copyArray(const Color1unorm8* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i]= Color1(src[i]);
    }
}


void Image1::copyArray(const Color3* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1(src[i].average());
    }
}


void Image1::save(const std::string& filename) {
    // To avoid saving as floating point image.  FreeImage cannot convert floating point to L8.
    Image1unorm8::Ref unorm8 = Image1unorm8::fromImage1(dynamic_pointer_cast<Image1>(shared_from_this()));
    unorm8->save(filename);
}


const ImageFormat* Image1::format() const {
    return ImageFormat::L32F();
}

} // G3D
