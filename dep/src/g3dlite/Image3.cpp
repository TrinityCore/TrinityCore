/**
  @file Image3.cpp

  @maintainer Morgan McGuire, http://graphics.cs.williams.edu

  @created 2007-01-31
  @edited  2007-01-31
*/


#include "G3D/Image3.h"
#include "G3D/Image3uint8.h"
#include "G3D/GImage.h"
#include "G3D/Color4.h"
#include "G3D/Color4uint8.h"
#include "G3D/Color1.h"
#include "G3D/Color1uint8.h"
#include "G3D/ImageFormat.h"

namespace G3D {

Image3::Image3(int w, int h, WrapMode wrap) : Map2D<Color3, Color3>(w, h, wrap) {
    setAll(Color3::black());
}


Image3::Ref Image3::fromGImage(const GImage& im, WrapMode wrap) {
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


Image3::Ref Image3::fromImage3uint8(const ReferenceCountedPointer<Image3uint8>& im) {
    Ref out = createEmpty(im->wrapMode());
    out->resize(im->width(), im->height());

    int N = im->width() * im->height();
    const Color3uint8* src = reinterpret_cast<Color3uint8*>(im->getCArray());
    for (int i = 0; i < N; ++i) {
        out->data[i] = Color3(src[i]);
    }

    return out;
}


Image3::Ref Image3::createEmpty(int width, int height, WrapMode wrap) {
    return new Image3(width, height, wrap);
}


Image3::Ref Image3::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image3::Ref Image3::fromFile(const std::string& filename, WrapMode wrap, GImage::Format fmt) {
    Ref out = createEmpty(wrap);
    out->load(filename, fmt);
    return out;
}


void Image3::load(const std::string& filename, GImage::Format fmt) {
    copyGImage(GImage(filename, fmt));
    setChanged(true);
}


Image3::Ref Image3::fromArray(const class Color3uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image3::Ref Image3::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image3::Ref Image3::fromArray(const class Color1uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image3::Ref Image3::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image3::Ref Image3::fromArray(const class Color4uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image3::Ref Image3::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


void Image3::copyGImage(const GImage& im) {
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


void Image3::copyArray(const Color3uint8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color3* dst = data.getCArray();
    // Convert int8 -> float
    for (int i = 0; i < N; ++i) {
        dst[i] = Color3(src[i]);
    }
}


void Image3::copyArray(const Color4uint8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color3* dst = data.getCArray();
    
    // Strip alpha and convert
    for (int i = 0; i < N; ++i) {
        dst[i] = Color3(src[i].rgb());
    }
}


void Image3::copyArray(const Color3* src, int w, int h) {
    resize(w, h);
    System::memcpy(getCArray(), src, w * h * sizeof(Color3));
}


void Image3::copyArray(const Color4* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color3* dst = data.getCArray();
    
    // Strip alpha
    for (int i = 0; i < N; ++i) {
        dst[i] = src[i].rgb();
    }
}


void Image3::copyArray(const Color1uint8* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color3* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = Color1(src[i]).value;
    }
}


void Image3::copyArray(const Color1* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color3* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = src[i].value;
    }
}


/** Saves in any of the formats supported by G3D::GImage. */
void Image3::save(const std::string& filename, GImage::Format fmt) {
    GImage im(width(), height(), 3);

    int N = im.width() * im.height();
    Color3uint8* dst = im.pixel3();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color3uint8(data[i]);
    }
    
    im.save(filename, fmt);
}


const ImageFormat* Image3::format() const {
    return ImageFormat::RGB32F();
}

} // G3D
