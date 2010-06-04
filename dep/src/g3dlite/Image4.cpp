/**
  @file Image4.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2007-01-31
  @edited  2008-07-27
*/


#include "G3D/Image4.h"
#include "G3D/Image4uint8.h"
#include "G3D/GImage.h"
#include "G3D/Color3.h"
#include "G3D/Color3uint8.h"
#include "G3D/Color1.h"
#include "G3D/Color1uint8.h"
#include "G3D/ImageFormat.h"

namespace G3D {

Image4::Image4(int w, int h, WrapMode wrap) : Map2D<Color4, Color4>(w, h, wrap) {
    setAll(Color4::zero());
}


Image4::Ref Image4::fromGImage(const GImage& im, WrapMode wrap) {
    switch (im.channels()) {
    case 1:
        return fromArray(im.pixel1(), im.width(), im.height(), wrap);

    case 3:
        return fromArray(im.pixel3(), im.width(), im.height(), wrap);

    case 4:
        return fromArray(im.pixel4(), im.width(), im.height(), wrap);

    default:
        debugAssertM(false, "Input GImage must have 1, 3, or 4 channels.");
        return NULL;
    }
}


Image4::Ref Image4::fromImage4uint8(const ReferenceCountedPointer<Image4uint8>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->resize(im->width(), im->height());

    int N = im->width() * im->height();
    const Color4uint8* src = reinterpret_cast<Color4uint8*>(im->getCArray());
    for (int i = 0; i < N; ++i) {
        out->data[i] = Color4(src[i]);
    }

    return out;
}


Image4::Ref Image4::createEmpty(int width, int height, WrapMode wrap) {
    return new Type(width, height, wrap);
}


Image4::Ref Image4::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image4::Ref Image4::fromFile(const std::string& filename, WrapMode wrap, GImage::Format fmt) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


void Image4::load(const std::string& filename, GImage::Format fmt) {
    copyGImage(GImage(filename, fmt));
    setChanged(true);
}


Image4::Ref Image4::fromArray(const class Color3uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color1uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color4uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4::Ref Image4::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


void Image4::copyGImage(const GImage& im) {
    switch (im.channels()) {
    case 1:
        copyArray(im.pixel1(), im.width(), im.height());
        break;

    case 3:
        copyArray(im.pixel3(), im.width(), im.height());
        break;

    case 4:
        copyArray(im.pixel4(), im.width(), im.height());
        break;
    } 
}


void Image4::copyArray(const Color4uint8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color4* dst = data.getCArray();
    // Convert int8 -> float
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4(src[i]);
    }
}


void Image4::copyArray(const Color3uint8* src, int w, int h) {
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


void Image4::copyArray(const Color1uint8* src, int w, int h) {
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
void Image4::save(const std::string& filename, GImage::Format fmt) {
    GImage im(width(), height(), 4);

    int N = im.width() * im.height();
    Color4uint8* dst = im.pixel4();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4uint8(data[i]);
    }
    
    im.save(filename, fmt);
}

const ImageFormat* Image4::format() const {
    return ImageFormat::RGBA32F();
}

} // G3D
