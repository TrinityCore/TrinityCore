/**
  @file Image4uint8.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2007-01-31
  @edited  2008-07-31
*/

#include "G3D/Image4uint8.h"
#include "G3D/Image4.h"
#include "G3D/Image3uint8.h"
#include "G3D/Image3.h"
#include "G3D/GImage.h"
#include "G3D/Color1.h"
#include "G3D/Color1uint8.h"
#include "G3D/Color4.h"
#include "G3D/Color4uint8.h"
#include "G3D/ImageFormat.h"

namespace G3D {

Image4uint8::Image4uint8(int w, int h, WrapMode wrap) : Map2D<Color4uint8, Color4>(w, h, wrap) {
    setAll(Color4::zero());
}


Image4uint8::Ref Image4uint8::fromGImage(const GImage& im, WrapMode wrap) {
    switch (im.channels) {
    case 1:
        return fromArray(im.pixel1(), im.width, im.height, wrap);

    case 3:
        return fromArray(im.pixel3(), im.width, im.height, wrap);

    case 4:
        return fromArray(im.pixel4(), im.width, im.height, wrap);

    default:
        debugAssertM(false, "Input GImage must have 1, 3, or 4 channels.");
        return NULL;
    }
}


Image4uint8::Ref Image4uint8::fromImage4(const ReferenceCountedPointer<Image4>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->copyArray(im->getCArray(), im->width(), im->height());

    return out;
}


Image4uint8::Ref Image4uint8::createEmpty(int width, int height, WrapMode wrap) {
    return new Type(width, height, wrap);
}


Image4uint8::Ref Image4uint8::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image4uint8::Ref Image4uint8::fromFile(const std::string& filename, WrapMode wrap, GImage::Format fmt) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color3uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color1uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color4uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image4uint8::Ref Image4uint8::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


void Image4uint8::load(const std::string& filename, GImage::Format fmt) {
    copyGImage(GImage(filename, fmt));
    setChanged(true);
}


void Image4uint8::copyGImage(const GImage& im) {
    switch (im.channels) {
    case 1:
        copyArray(im.pixel1(), im.width, im.height);
        break;

    case 3:
        copyArray(im.pixel3(), im.width, im.height);
        break;

    case 4:
        copyArray(im.pixel4(), im.width, im.height);
        break;
    } 
}


void Image4uint8::copyArray(const Color1uint8* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = src[i].value;
        dst[i].a = 255;
    }
}

void Image4uint8::copyArray(const Color1* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].r = dst[i].g = dst[i].b = Color1uint8(src[i]).value;
        dst[i].a = 255;
    }
}


void Image4uint8::copyArray(const Color4uint8* ptr, int w, int h) {
    resize(w, h);
    System::memcpy(getCArray(), ptr, w * h * 4);
}


void Image4uint8::copyArray(const Color4* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4uint8(src[i]);
    }
}


void Image4uint8::copyArray(const Color3uint8* ptr, int w, int h) {
    resize(w, h);
    
    GImage::RGBtoRGBA((const uint8*)ptr, (uint8*)getCArray(), w * h);
}


void Image4uint8::copyArray(const Color3* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color4uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color4uint8(Color4(src[i], 1.0f));
    }
}


/** Saves in any of the formats supported by G3D::GImage. */
void Image4uint8::save(const std::string& filename, GImage::Format fmt) {
    GImage im(width(), height(), 4);
    System::memcpy(im.byte(), getCArray(), width() * height() * 4);
    im.save(filename, fmt);
}


ReferenceCountedPointer<class Image1uint8> Image4uint8::getChannel(int c) const {
    debugAssert(c >= 0 && c <= 3);

    Image1uint8Ref dst = Image1uint8::createEmpty(width(), height(), wrapMode());
    const Color4uint8* srcArray = getCArray();
    Color1uint8* dstArray = dst->getCArray();

    const int N = width() * height();
    for (int i = 0; i < N; ++i) {
        dstArray[i] = Color1uint8(srcArray[i][c]);
    }

    return dst;
}


const ImageFormat* Image4uint8::format() const {
    return ImageFormat::RGBA8();
}

} // G3D
