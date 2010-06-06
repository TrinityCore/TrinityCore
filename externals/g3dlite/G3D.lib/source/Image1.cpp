/**
  @file Image1.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2007-01-31
  @edited  2007-01-31
*/


#include "G3D/Image1.h"
#include "G3D/Image1uint8.h"
#include "G3D/GImage.h"
#include "G3D/Color4.h"
#include "G3D/Color4uint8.h"
#include "G3D/Color1.h"
#include "G3D/Color1uint8.h"
#include "G3D/ImageFormat.h"

namespace G3D {

Image1::Image1(int w, int h, WrapMode wrap) : Map2D<Color1, Color1>(w, h, wrap) {
    setAll(Color1(0.0f));
}


Image1::Ref Image1::fromGImage(const GImage& im, WrapMode wrap) {
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


Image1::Ref Image1::fromImage1uint8(const ReferenceCountedPointer<Image1uint8>& im) {
    Ref out = createEmpty(static_cast<WrapMode>(im->wrapMode()));
    out->resize(im->width(), im->height());

    int N = im->width() * im->height();
    const Color1uint8* src = reinterpret_cast<Color1uint8*>(im->getCArray());
    for (int i = 0; i < N; ++i) {
        out->data[i] = Color1(src[i]);
    }

    return out;
}


Image1::Ref Image1::createEmpty(int width, int height, WrapMode wrap) {
    return new Type(width, height, wrap);
}


Image1::Ref Image1::createEmpty(WrapMode wrap) {
    return createEmpty(0, 0, wrap);
}


Image1::Ref Image1::fromFile(const std::string& filename, WrapMode wrap, GImage::Format fmt) {
    Ref out = createEmpty(wrap);
    out->load(filename);
    return out;
}


void Image1::load(const std::string& filename, GImage::Format fmt) {
    copyGImage(GImage(filename, fmt));
    setChanged(true);
}


Image1::Ref Image1::fromArray(const class Color3uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color1* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color1uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color3* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color4uint8* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}


Image1::Ref Image1::fromArray(const class Color4* ptr, int w, int h, WrapMode wrap) {
    Ref out = createEmpty(wrap);
    out->copyArray(ptr, w, h);
    return out;
}

void Image1::copyGImage(const GImage& im) {
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


void Image1::copyArray(const Color3uint8* src, int w, int h) {
    resize(w, h);

    int N = w * h;
    Color1* dst = data.getCArray();
    // Convert int8 -> float
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1(Color3(src[i]).average());
    }
}


void Image1::copyArray(const Color4uint8* src, int w, int h) {
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


void Image1::copyArray(const Color1uint8* src, int w, int h) {
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


/** Saves in any of the formats supported by G3D::GImage. */
void Image1::save(const std::string& filename, GImage::Format fmt) {
    GImage im(width(), height(), 1);

    int N = im.width * im.height;
    Color1uint8* dst = im.pixel1();
    for (int i = 0; i < N; ++i) {
        dst[i] = Color1uint8(data[i]);
    }
    
    im.save(filename, fmt);
}


const ImageFormat* Image1::format() const {
    return ImageFormat::L32F();
}

} // G3D
