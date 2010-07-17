/**
  @file Image1uint8.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2007-01-31
  @edited  2008-01-13
*/

#include "G3D/Image1uint8.h"
#include "G3D/Image3uint8.h"
#include "G3D/Image1.h"
#include "G3D/GImage.h"
#include "G3D/Color1.h"
#include "G3D/Color1uint8.h"
#include "G3D/Color4.h"
#include "G3D/Color4uint8.h"
#include "G3D/ImageFormat.h"

namespace G3D {

Image1uint8::Image1uint8(int w, int h, WrapMode wrap) : Map2D<Color1uint8, Color1>(w, h, wrap) {
    setAll(Color1uint8(0));
}


Image1uint8::Ref Image1uint8::fromImage3uint8(const ReferenceCountedPointer<class Image3uint8>& im) {
    return fromArray(im->getCArray(), im->width(), im->height(), im->wrapMode());
}


Image1uint8::Ref Image1uint8::fromGImage(const GImage& im, WrapMode wrap) {
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


Image1uint8::Ref Image1uint8::fromImage1(const ReferenceCountedPointer<Image1>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->copyArray(im->getCArray(), im->width(), im->height());

    return out;
}


Image1uint8::Ref Image1uint8::createEmpty(int width, int height, WrapMode wrap) {
    return new Type(width, height, wrap);
}


Image1uint8::Ref Image1uint8::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image1uint8::Ref Image1uint8::fromFile(const std::string& filename, WrapMode wrap, GImage::Format fmt) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color3uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color1uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color4uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1uint8::Ref Image1uint8::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


void Image1uint8::load(const std::string& filename, GImage::Format fmt) {
    copyGImage(GImage(filename, fmt));
    setChanged(true);
}


void Image1uint8::copyGImage(const GImage& im) {
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


void Image1uint8::copyArray(const Color3uint8* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].value = (src[i].r + src[i].g + src[i].b) / 3;
    }
}

void Image1uint8::copyArray(const Color3* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1uint8(Color1(src[i].average()));
    }
}


void Image1uint8::copyArray(const Color1uint8* ptr, int w, int h) {
    resize(w, h);
    System::memcpy(getCArray(), ptr, w * h);
}


void Image1uint8::copyArray(const Color1* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1uint8(src[i]);
    }
}


void Image1uint8::copyArray(const Color4uint8* ptr, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i].value = (ptr[i].r + ptr[i].g + ptr[i].b) / 3;
    }
}


void Image1uint8::copyArray(const Color4* src, int w, int h) {
    resize(w, h);
    int N = w * h;

    Color1uint8* dst = getCArray();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1uint8(Color1(src[i].rgb().average()));
    }
}


/** Saves in any of the formats supported by G3D::GImage. */
void Image1uint8::save(const std::string& filename, GImage::Format fmt) {
    GImage im(width(), height(), 1);
    System::memcpy(im.byte(), getCArray(), width() * height());
    im.save(filename, fmt);
}


const ImageFormat* Image1uint8::format() const {
    return ImageFormat::L8();
}

} // G3D
