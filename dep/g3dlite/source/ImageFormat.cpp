/**
 \file ImageFormat.cpp
 
 \maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 \created 2003-05-23
 \edited  2013-01-12
 */

#include "GLG3D/glheaders.h"
#include "G3D/ImageFormat.h"
#include "G3D/stringutils.h"

namespace G3D {

ImageFormat::ImageFormat(
    int             _numComponents,
    bool            _compressed,
    int             _glFormat,
    int             _glBaseFormat,
    int             _luminanceBits,
    int             _alphaBits,
    int             _redBits,
    int             _greenBits,
    int             _blueBits,
    int             _depthBits,
    int             _stencilBits,
    int             _openGLBitsPerPixel,
    int             _cpuBitsPerPixel,
    int             glDataFormat,
    bool            _opaque,
    NumberFormat    _numberFormat,
    Code            _code,
    ColorSpace      _colorSpace,
    BayerPattern    _bayerPattern) : 

    numComponents(_numComponents),
    compressed(_compressed),
    code(_code),
    colorSpace(_colorSpace),
    bayerPattern(_bayerPattern),
    openGLFormat(_glFormat),
    openGLBaseFormat(_glBaseFormat),
    luminanceBits(_luminanceBits),
    alphaBits(_alphaBits),
    redBits(_redBits),
    greenBits(_greenBits),
    blueBits(_blueBits),
    stencilBits(_stencilBits),
    depthBits(_depthBits),
    cpuBitsPerPixel(_cpuBitsPerPixel),
    openGLBitsPerPixel(_openGLBitsPerPixel),
    openGLDataFormat(glDataFormat),
    opaque(_opaque),
    numberFormat(_numberFormat){

    floatingPoint = (numberFormat == FLOATING_POINT_FORMAT);
    debugAssert(cpuBitsPerPixel <= openGLBitsPerPixel);
}


bool ImageFormat::sameComponents(const ImageFormat* other) const {
    return
        (numComponents == other->numComponents) &&
        ((alphaBits != 0) == (other->alphaBits != 0)) &&
        ((redBits != 0) == (other->redBits != 0)) &&
        ((greenBits != 0) == (other->greenBits != 0)) &&
        ((blueBits != 0) == (other->blueBits != 0)) &&
        ((luminanceBits != 0) == (other->luminanceBits != 0)) &&
        ((stencilBits != 0) == (other->stencilBits != 0)) &&
        ((depthBits != 0) == (other->depthBits != 0));
}


const ImageFormat* ImageFormat::depth(int depthBits) {

    switch (depthBits) {
    case 16:
        return DEPTH16();

    case 24:
        return DEPTH24();

    case 32:
        return DEPTH32();

    default:
        debugAssertM(false, "Depth must be 16, 24, or 32.");
        return DEPTH32();
    }
}


const ImageFormat* ImageFormat::stencil(int bits) {
    switch (bits) {
    case 1:
        return STENCIL1();

    case 4:
        return STENCIL4();

    case 8:
        return STENCIL8();

    case 16:
        return STENCIL16();

    default:
        debugAssertM(false, "Stencil must be 1, 4, 8 or 16.");
        return STENCIL16();
    }
}


    static const std::string nameArray[ImageFormat::CODE_NUM] = 
    {
        "L8", 
        "L16",
        "L16F",
        "L32F",

        "A8",
        "A16",
        "A16F",
        "A32F",

        "LA4",
        "LA8",
        "LA16",
        "LA16F",
        "LA32F",

        "RGB5",
        "RGB5A1",
        "RGB8",
        "RGB10",
        "RGB10A2",
        "RGB16",
        "RGB16F",
        "RGB32F",
        "R11G11B10F",
        "RGB9E5F",

        "RGB8I",
        "RGB8UI",

        "RGBA8I",
        "RGBA8UI",

        "RGB8_SNORM",
        "RGBA8_SNORM",
        "RGB16_SNORM",
        "RGBA16_SNORM",

        "ARGB8",
        "BGR8",
        "BGRA8",

        "R8",
        "R8I",
        "R8UI",

        "R16",
        "R16I",
        "R16UI",

        "R32I",
        "R32UI",

        "RG8",
        "RG8I",
        "RG8UI",

        "RG16",
        "RG16I",
        "RG16UI",

        "R16F",
        "RG16F",

        "RG32I",
        "RG32UI",

        "R32F",
        "RG32F",

        "RGBA8",
        "RGBA16",
        "RGBA16F",
        "RGBA32F",

        "RGBA16I",
        "RGBA16UI",

        "RGB32I",
        "RGB32UI",
        "RGBA32I",
        "RGBA32UI",

        "BAYER_RGGB8",
        "BAYER_GRBG8",
        "BAYER_GBRG8",
        "BAYER_BGGR8",
        "BAYER_RGGB32F",
        "BAYER_GRBG32F",
        "BAYER_GBRG32F",
        "BAYER_BGGR32F",

        "HSV8",
        "HSV32F",

        "YUV420_PLANAR",
        "YUV422",
        "YUV444",

        "RGB_DXT1",
        "RGBA_DXT1",
        "RGBA_DXT3",
        "RGBA_DXT5",

        "SRGB8",
        "SRGBA8",

        "SL8",
        "SLA8",

        "SRGB_DXT1",
        "SRGBA_DXT1",
        "SRGBA_DXT3",
        "SRGBA_DXT5",

        "DEPTH16",
        "DEPTH24",
        "DEPTH32",
        "DEPTH32F",
        
        "STENCIL1",
        "STENCIL4",
        "STENCIL8",
        "STENCIL16",

        "DEPTH24_STENCIL8"
    };

const std::string& ImageFormat::name() const {
    debugAssert(code < CODE_NUM);
    return nameArray[code];
}

bool ImageFormat::canInterpretAs(const ImageFormat* otherFormat) const {
    if (this == otherFormat) {
        return true;
    }

    if (compressed || otherFormat->compressed) {
        return false;
    }

    if (colorSpace != otherFormat->colorSpace) {
        return false;
    }

    if (floatingPoint != otherFormat->floatingPoint) {
        return false;
    }

    if (numComponents != otherFormat->numComponents) {
        return false;
    }

    if (cpuBitsPerPixel != otherFormat->cpuBitsPerPixel) {
        return false;
    }

    if (openGLDataFormat != otherFormat->openGLDataFormat) {
        return false;
    }

    return true;
}


const ImageFormat* ImageFormat::getSRGBFormat(const ImageFormat* otherFormat) {
    switch (otherFormat->code) {
    case CODE_RGB8:
        return SRGB8();

    case CODE_RGBA8:
        return SRGBA8();

    case CODE_RGB_DXT1:
        return SRGB_DXT1();

    case CODE_RGBA_DXT1:
        return SRGBA_DXT1();

    case CODE_RGBA_DXT3:
        return SRGBA_DXT3();

    case CODE_RGBA_DXT5:
        return SRGBA_DXT5();

    default:
        return otherFormat;
    }
}


const ImageFormat* ImageFormat::getFormatWithAlpha(const ImageFormat* otherFormat) {
    if (! otherFormat->opaque) {
        return otherFormat;
    }

    switch (otherFormat->code) {
    case CODE_L8:
        return LA8();
        break;

    case CODE_L16F:
        return LA16F();
        break;

    case CODE_RGB8:
        return RGBA8();
        break;
        
    case CODE_RGB8I:
        return RGBA8I();
        break;

    case CODE_RGB32I:
        return RGBA32I();
        break;

    case CODE_RGB32UI:
        return RGBA32UI();
        break;

    case CODE_RGB8UI:
        return RGBA8UI();
        break;

    case CODE_RGB8_SNORM:
        return RGB8_SNORM();
        break;
    case CODE_RGBA8_SNORM:
        return RGBA8_SNORM();
        break;

    case CODE_RGB16_SNORM:
        return RGB16_SNORM();
        break;

    case CODE_RGBA16_SNORM:
        return RGBA16_SNORM();
        break;
        
    case CODE_BGR8:
        return BGRA8();
        break;
        
    case CODE_RGB16:
        return RGBA16();
        break;
        
    case CODE_RGB16F:
        return RGBA16F();
        break;
        
    case CODE_RGB32F:
        return RGBA32F();
        break;

    case CODE_R11G11B10F:
        return RGBA16F();
        break;
        
    default:
        break;
    }

    return NULL;
}


const ImageFormat* ImageFormat::fromString(const std::string& s) {
    if (toLower(s) == "auto") {
        return NULL;
    }

    for (int i = 0; i < CODE_NUM; ++i) {
        if (s == nameArray[i]) {
            return fromCode(ImageFormat::Code(i));
        }
    }
    return NULL;
}

const ImageFormat* ImageFormat::fromCode(ImageFormat::Code code) {
    switch (code) {
    case ImageFormat::CODE_L8:
        return ImageFormat::L8();

    case ImageFormat::CODE_L16:
        return ImageFormat::L16();

    case ImageFormat::CODE_L16F:
        return ImageFormat::L16F();

    case ImageFormat::CODE_L32F:
        return ImageFormat::L32F();

    case ImageFormat::CODE_A8:
        return ImageFormat::A8();

    case ImageFormat::CODE_A16:
        return ImageFormat::A16();

    case ImageFormat::CODE_A16F:
        return ImageFormat::A16F();

    case ImageFormat::CODE_A32F:
        return ImageFormat::A32F();

    case ImageFormat::CODE_LA4:
        return ImageFormat::LA4();

    case ImageFormat::CODE_LA8:
        return ImageFormat::LA8();

    case ImageFormat::CODE_LA16:
        return ImageFormat::LA16();

    case ImageFormat::CODE_LA16F:
        return ImageFormat::LA16F();
        
    case ImageFormat::CODE_LA32F:
        return ImageFormat::LA32F();

    case ImageFormat::CODE_RGB5:
        return ImageFormat::RGB5();

    case ImageFormat::CODE_RGB5A1:
        return ImageFormat::RGB5A1();

    case ImageFormat::CODE_RGB8:
        return ImageFormat::RGB8();

    case ImageFormat::CODE_RGB10:
        return ImageFormat::RGB10();

    case ImageFormat::CODE_RGB10A2:
        return ImageFormat::RGB10A2();

    case ImageFormat::CODE_RGB16:
        return ImageFormat::RGB16();

    case ImageFormat::CODE_RGB32F:
        return ImageFormat::RGB32F();

    case ImageFormat::CODE_R11G11B10F:
        return ImageFormat::R11G11B10F();

    case ImageFormat::CODE_RGB9E5F:
        return ImageFormat::RGB9E5F();

    case ImageFormat::CODE_RGB8I:
        return ImageFormat::RGB8I();

    case ImageFormat::CODE_RGB8UI:
        return ImageFormat::RGB8UI();

    case ImageFormat::CODE_RGBA8I:
        return ImageFormat::RGBA8I();

    case ImageFormat::CODE_RGBA8UI:
        return ImageFormat::RGBA8UI();

    case ImageFormat::CODE_RGB8_SNORM:
        return ImageFormat::RGB8_SNORM();
    case ImageFormat::CODE_RGBA8_SNORM:
        return ImageFormat::RGBA8_SNORM();
    case ImageFormat::CODE_RGB16_SNORM:
        return ImageFormat::RGB16_SNORM();
    case ImageFormat::CODE_RGBA16_SNORM:
        return ImageFormat::RGBA16_SNORM();

    case ImageFormat::CODE_ARGB8:
        return NULL;

    case ImageFormat::CODE_BGR8:
        return ImageFormat::BGR8();

    case ImageFormat::CODE_BGRA8:
        return ImageFormat::BGRA8();

    case ImageFormat::CODE_R8:
        return ImageFormat::R8();

    case ImageFormat::CODE_R8I:
        return ImageFormat::R8I();

    case ImageFormat::CODE_R8UI:
        return ImageFormat::R8UI();

    case ImageFormat::CODE_R16:
        return ImageFormat::R16();

    case ImageFormat::CODE_R16I:
        return ImageFormat::R16I();

    case ImageFormat::CODE_R16UI:
        return ImageFormat::R16UI();

    case ImageFormat::CODE_R32I:
        return ImageFormat::R32I();

    case ImageFormat::CODE_R32UI:
        return ImageFormat::R32UI();

    case ImageFormat::CODE_RG8:
        return ImageFormat::RG8();

    case ImageFormat::CODE_RG8I:
        return ImageFormat::RG8I();

    case ImageFormat::CODE_RG8UI:
        return ImageFormat::RG8UI();

    case ImageFormat::CODE_R16F:
        return ImageFormat::R16F();

    case ImageFormat::CODE_RG16F:
        return ImageFormat::RG16F();

    case ImageFormat::CODE_R32F:
        return ImageFormat::R32F();

    case ImageFormat::CODE_RG32F:
        return ImageFormat::RG32F();

    case ImageFormat::CODE_RGBA8:
        return ImageFormat::RGBA8();

    case ImageFormat::CODE_RGBA16:
        return ImageFormat::RGBA16();

    case ImageFormat::CODE_RGBA16F:
        return ImageFormat::RGBA16F();

    case ImageFormat::CODE_RGBA32F:
        return ImageFormat::RGBA32F();

    case ImageFormat::CODE_RGB32I:
        return ImageFormat::RGB32I();

    case ImageFormat::CODE_RGBA32I:
        return ImageFormat::RGBA32I();

    case ImageFormat::CODE_RGB32UI:
        return ImageFormat::RGB32UI();

    case ImageFormat::CODE_RGBA32UI:
        return ImageFormat::RGBA32UI();

    case ImageFormat::CODE_BAYER_RGGB8:
        // TODO
    case ImageFormat::CODE_BAYER_GRBG8:
        // TODO
    case ImageFormat::CODE_BAYER_GBRG8:
        // TODO
    case ImageFormat::CODE_BAYER_BGGR8:
        // TODO
    case ImageFormat::CODE_BAYER_RGGB32F:
        // TODO
    case ImageFormat::CODE_BAYER_GRBG32F:
        // TODO
    case ImageFormat::CODE_BAYER_GBRG32F:
        // TODO
    case ImageFormat::CODE_BAYER_BGGR32F:
        // TODO

    case ImageFormat::CODE_HSV8:
        // TODO
    case ImageFormat::CODE_HSV32F:
        // TODO
        return NULL;
        break;

    case ImageFormat::CODE_RGB_DXT1:
        return ImageFormat::RGB_DXT1();
        break;
    case ImageFormat::CODE_RGBA_DXT1:
        return ImageFormat::RGBA_DXT1();
        break;
    case ImageFormat::CODE_RGBA_DXT3:
        return ImageFormat::RGBA_DXT3();
        break;
    case ImageFormat::CODE_RGBA_DXT5:
        return ImageFormat::RGBA_DXT5();
        break;

    case ImageFormat::CODE_SRGB8:
        return ImageFormat::SRGB8();
        break;

    case ImageFormat::CODE_SRGBA8:
        return ImageFormat::SRGBA8();
        break;

    case ImageFormat::CODE_SL8:
        return ImageFormat::SL8();
        break;

    case ImageFormat::CODE_SLA8:
        return ImageFormat::SLA8();
        break;

    case ImageFormat::CODE_SRGB_DXT1:
        return ImageFormat::SRGB_DXT1();
        break;

    case ImageFormat::CODE_SRGBA_DXT1:
        return ImageFormat::SRGBA_DXT1();
        break;

    case ImageFormat::CODE_SRGBA_DXT3:
        return ImageFormat::SRGBA_DXT3();
        break;

    case ImageFormat::CODE_SRGBA_DXT5:
        return ImageFormat::SRGBA_DXT5();
        break;

    case ImageFormat::CODE_DEPTH16:
        return ImageFormat::DEPTH16();
        break;
    case ImageFormat::CODE_DEPTH24:
        return ImageFormat::DEPTH24();
        break;
    case ImageFormat::CODE_DEPTH32:
        return ImageFormat::DEPTH32();
        break;
    case ImageFormat::CODE_DEPTH32F:
        return ImageFormat::DEPTH32F();
        break;

    case ImageFormat::CODE_STENCIL1:
        return ImageFormat::STENCIL1();
        break;
    case ImageFormat::CODE_STENCIL4:
        return ImageFormat::STENCIL4();
        break;
    case ImageFormat::CODE_STENCIL8:
        return ImageFormat::STENCIL8();
        break;
    case ImageFormat::CODE_STENCIL16:
        return ImageFormat::STENCIL16();
        break;

    case ImageFormat::CODE_DEPTH24_STENCIL8:
        return ImageFormat::DEPTH24_STENCIL8();
        break;

    case ImageFormat::CODE_YUV420_PLANAR:
        return ImageFormat::YUV420_PLANAR();
        break;

    case ImageFormat::CODE_YUV422:
        return ImageFormat::YUV422();
        break;

    case ImageFormat::CODE_YUV444:
        return ImageFormat::YUV444();
        break;

    default:
        return NULL;
    }
}


bool ImageFormat::representableAsColor1unorm8() const {
    return (numComponents == 1) &&
        (cpuBitsPerPixel == 8) &&
        ((luminanceBits == 8) ||
         (redBits == 8) ||
         (alphaBits == 8));
}


bool ImageFormat::representableAsColor2unorm8() const {
    return (numComponents == 2) &&
        (cpuBitsPerPixel == 16) &&
        ((redBits == 8 && greenBits == 8) ||
         (luminanceBits == 8 && alphaBits == 8) ||
         (redBits == 8 && alphaBits == 8));
}


bool ImageFormat::representableAsColor3unorm8() const {
    return (numComponents == 3) &&
        (cpuBitsPerPixel == 24) &&
        (redBits == 8 && greenBits == 8 && blueBits == 8);
}


bool ImageFormat::representableAsColor4unorm8() const {
    return (numComponents == 4) &&
        (cpuBitsPerPixel == 32) &&
        (redBits == 8 && greenBits == 8 && blueBits == 8 && alphaBits == 8);
}

Color4 ImageFormat::channelMask() const{
    Color4 mask;
    mask.r = (redBits > 0 || luminanceBits > 0) ? 1.0f : 0.0f;
    mask.b = (blueBits > 0)                     ? 1.0f : 0.0f;
    mask.g = (greenBits > 0)                    ? 1.0f : 0.0f;
    mask.a = (alphaBits > 0)                    ? 1.0f : 0.0f;
    return mask;

}

// Helper variables for defining texture formats

// Is opaque format (no alpha)
static const bool OPAQUE_FORMAT = true;
static const bool CLEAR_FORMAT  = false;

// Is compressed format (not raw component data)
static const bool COMP_FORMAT   = true;
static const bool UNCOMP_FORMAT = false;


#define DEFINE_TEXTUREFORMAT_METHOD(enumname, cmpnts, cmprssd, glf, glbf, lb, ab, rb, gb, bb, db, sb, hbpt, pbpt, gldf, opq, fp, code, cs) \
    const ImageFormat* ImageFormat::enumname() {                                                                                           \
        static const ImageFormat format(cmpnts, cmprssd, glf, glbf, lb, ab, rb, gb, bb, db, sb, hbpt, pbpt, gldf, opq, fp, code, cs);      \
    return &format; }

DEFINE_TEXTUREFORMAT_METHOD(L8,         1, UNCOMP_FORMAT,   GL_LUMINANCE8,      GL_LUMINANCE,   8, 0, 0, 0, 0, 0, 0, 8, 8,  GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_L8, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(L16,        1, UNCOMP_FORMAT,   GL_LUMINANCE16,     GL_LUMINANCE,  16, 0, 0, 0, 0, 0, 0, 16, 16,GL_UNSIGNED_SHORT, OPAQUE_FORMAT, INTEGER_FORMAT, CODE_L16, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(L16F,       1, UNCOMP_FORMAT,   GL_LUMINANCE16F_ARB,GL_LUMINANCE, 16, 0, 0, 0, 0, 0, 0, 16, 16, GL_HALF_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, CODE_L16F, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(L32F,       1, UNCOMP_FORMAT,   GL_LUMINANCE32F_ARB,GL_LUMINANCE, 32, 0, 0, 0, 0, 0, 0, 32, 32, GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, CODE_L32F, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(A8,         1, UNCOMP_FORMAT,   GL_ALPHA8,          GL_ALPHA,   0, 8, 0, 0, 0, 0, 0, 8, 8,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_A8, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(A16,        1, UNCOMP_FORMAT,   GL_ALPHA16,         GL_ALPHA,   0, 16, 0, 0, 0, 0, 0, 16, 16,   GL_UNSIGNED_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_A16, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(A16F,       1, UNCOMP_FORMAT,   GL_ALPHA16F_ARB,    GL_ALPHA,   0, 16, 0, 0, 0, 0, 0, 16, 16,   GL_HALF_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, CODE_A16F, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(A32F,       1, UNCOMP_FORMAT,   GL_ALPHA32F_ARB,    GL_ALPHA,   0, 32, 0, 0, 0, 0, 0, 32, 32,   GL_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, CODE_A32F, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(LA4,        2, UNCOMP_FORMAT,   GL_LUMINANCE4_ALPHA4,       GL_LUMINANCE_ALPHA, 4, 4, 0, 0, 0, 0, 0, 8, 8,              GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_LA4, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(LA8,        2, UNCOMP_FORMAT,   GL_LUMINANCE8_ALPHA8,       GL_LUMINANCE_ALPHA, 8, 8, 0, 0, 0, 0, 0, 16, 16,            GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_LA8, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(LA16,       2, UNCOMP_FORMAT,   GL_LUMINANCE16_ALPHA16,     GL_LUMINANCE_ALPHA, 16, 16, 0, 0, 0, 0, 0, 16*2, 16*2,      GL_UNSIGNED_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, CODE_LA16, COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(LA16F,      2, UNCOMP_FORMAT,   GL_LUMINANCE_ALPHA16F_ARB,  GL_LUMINANCE_ALPHA, 16, 16, 0, 0, 0, 0, 0, 16*2, 16*2,      GL_HALF_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_LA16F, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(LA32F,      2, UNCOMP_FORMAT,   GL_LUMINANCE_ALPHA32F_ARB,  GL_LUMINANCE_ALPHA, 32, 32,  0,  0,  0,  0,  0, 32*2, 32*2, GL_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_LA32F, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(BGR8,       3, UNCOMP_FORMAT,   GL_RGB8,            GL_BGR,     0,  0,  8,  8,  8,  0,  0, 32, 24,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_BGR8, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(BGRA8,      4, UNCOMP_FORMAT,   GL_RGBA8,           GL_BGRA,    0,  8,  8,  8,  8,  0,  0, 32, 32,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_BGRA8, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R8,         1, UNCOMP_FORMAT,   GL_R8,              GL_RED,    0,  0,  8,  0,  0,  0,  0, 8, 8,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_R8, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R8I,        1, UNCOMP_FORMAT,   GL_R8I,             GL_RED_INTEGER,    0,  0,  8,  0,  0,  0,  0, 8, 8,      GL_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R8I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R8UI,       1, UNCOMP_FORMAT,   GL_R8UI,            GL_RED_INTEGER,    0,  0,  8,  0,  0,  0,  0, 8, 8,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R8UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R16,        1, UNCOMP_FORMAT,   GL_R16,             GL_RED,    0,  0,  16,  0,  0,  0,  0, 16, 16,      GL_UNSIGNED_SHORT, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_R16, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R16I,       1, UNCOMP_FORMAT,   GL_R16I,            GL_RED_INTEGER,    0,  0,  16,  0,  0,  0,  0, 16, 16,      GL_SHORT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R16I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R16UI,      1, UNCOMP_FORMAT,   GL_R16UI,           GL_RED_INTEGER,    0,  0,  16,  0,  0,  0,  0, 16, 16,      GL_UNSIGNED_SHORT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R16UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R32I,       1, UNCOMP_FORMAT,   GL_R32I,            GL_RED_INTEGER,    0,  0,  32,  0,  0,  0,  0, 32, 32,      GL_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R32I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R32UI,      1, UNCOMP_FORMAT,   GL_R32UI,           GL_RED_INTEGER,    0,  0,  32,  0,  0,  0,  0, 32, 32,      GL_UNSIGNED_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_R32UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG8,        2, UNCOMP_FORMAT,   GL_RG8,             GL_RG,     0,  0,  8,  8,  0,  0,  0, 16, 16,    GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RG8, ImageFormat::COLOR_SPACE_RGB);

// The base format for integer formats must be *_INTEGER even though the spec doesn't state this
DEFINE_TEXTUREFORMAT_METHOD(RG8I,       2, UNCOMP_FORMAT,   GL_RG8I,            GL_RG_INTEGER,     0,  0,  8,  8,  0,  0,  0, 16, 16,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG8I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG8UI,      2, UNCOMP_FORMAT,   GL_RG8UI,           GL_RG_INTEGER,     0,  0,  8,  8,  0,  0,  0, 16, 16,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG8UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG16,       2, UNCOMP_FORMAT,   GL_RG16,            GL_RG,    0,  0,  16,  16,  0,  0,  0, 16*2, 16*2,      GL_UNSIGNED_SHORT, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RG16, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG16I,      2, UNCOMP_FORMAT,   GL_RG16I,           GL_RG_INTEGER,    0,  0,  16,  16,  0,  0,  0, 16*2, 16*2,      GL_SHORT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG16I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG16UI,     2, UNCOMP_FORMAT,   GL_RG16UI,          GL_RG_INTEGER,    0,  0,  16,  16,  0,  0,  0, 16*2, 16*2,      GL_UNSIGNED_SHORT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG16UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R16F,       1, UNCOMP_FORMAT,   GL_R16F,            GL_RED,      0,  0,  16, 0,  0,  0,  0, 16, 16,       GL_HALF_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_R16F, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG16F,      2, UNCOMP_FORMAT,   GL_RG16F,           GL_RG,     0,  0,  16, 16,  0,  0,  0, 32, 32,      GL_HALF_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RG16F, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG32I,      2, UNCOMP_FORMAT,   GL_RG32I,           GL_RG_INTEGER,    0,  0,  32,  32,  0,  0,  0, 32*2, 32*2,      GL_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG32I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG32UI,     2, UNCOMP_FORMAT,   GL_RG32UI,          GL_RG_INTEGER,    0,  0,  32,  32,  0,  0,  0, 32*2, 32*2,      GL_UNSIGNED_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RG32UI, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(R32F,       1, UNCOMP_FORMAT,   GL_R32F,            GL_RED,      0,  0,  32, 0,  0,  0,  0, 32, 32,       GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_R32F, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RG32F,      2, UNCOMP_FORMAT,   GL_RG32F,           GL_RG,     0,  0,  32, 32,  0,  0,  0, 64, 64,      GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RG32F, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB5,       3, UNCOMP_FORMAT,   GL_RGB5,            GL_RGBA,    0,  0,  5,  5,  5,  0,  0, 16, 16,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB5, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB5A1,     4, UNCOMP_FORMAT,   GL_RGB5_A1,         GL_RGBA,    0,  1,  5,  5,  5,  0,  0, 16, 16,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB5A1, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB8,       3, UNCOMP_FORMAT,   GL_RGB8,            GL_RGB,     0,  0,  8,  8,  8,  0,  0, 32, 24,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB8, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB10,      3, UNCOMP_FORMAT,   GL_RGB10,           GL_RGB,     0,  0, 10, 10, 10,  0,  0, 32, 10*3,    GL_UNSIGNED_SHORT, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB10, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB10A2,    4, UNCOMP_FORMAT,   GL_RGB10_A2,        GL_RGBA,    0,  2, 10, 10, 10,  0,  0, 32, 32,      GL_UNSIGNED_INT_10_10_10_2, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB10A2, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB16,      3, UNCOMP_FORMAT,   GL_RGB16,           GL_RGB,     0,  0, 16, 16, 16,  0,  0, 16*3, 16*3,  GL_UNSIGNED_SHORT, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB16, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB16F,     3, UNCOMP_FORMAT,   GL_RGB16F_ARB,      GL_RGB,     0,  0, 16, 16, 16,  0,  0, 16*3, 16*3,  GL_HALF_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RGB16F, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGB32F,     3, UNCOMP_FORMAT,   GL_RGB32F_ARB,      GL_RGB,     0,  0, 32, 32, 32,  0,  0, 32*3, 32*3,  GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RGB32F, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA8,      4, UNCOMP_FORMAT,   GL_RGBA8,           GL_RGBA,    0,  8,  8,  8,  8,  0,  0, 32, 32,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGBA8, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA16,     4, UNCOMP_FORMAT,   GL_RGBA16,          GL_RGBA,    0, 16, 16, 16, 16, 0, 0, 16*4, 16*4,    GL_UNSIGNED_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGBA16, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA16F,    4, UNCOMP_FORMAT,   GL_RGBA16F_ARB,     GL_RGBA,    0, 16, 16, 16, 16, 0, 0, 16*4, 16*4,    GL_HALF_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RGBA16F, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA32F,    4, UNCOMP_FORMAT,   GL_RGBA32F_ARB,     GL_RGBA,    0, 32, 32, 32, 32, 0, 0, 32*4, 32*4,    GL_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RGBA32F, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGBA16I,    4, UNCOMP_FORMAT,   GL_RGBA16I,         GL_RGBA_INTEGER,    0, 16, 16, 16, 16, 0, 0, 16*4, 16*4,    GL_SHORT, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA16I, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA16UI,   4, UNCOMP_FORMAT,   GL_RGBA16UI,        GL_RGBA_INTEGER,    0, 16, 16, 16, 16, 0, 0, 16*4, 16*4,    GL_UNSIGNED_SHORT, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA16UI, ImageFormat::COLOR_SPACE_RGB);


// The base format for integer formats must be *_INTEGER even though the spec doesn't state this
DEFINE_TEXTUREFORMAT_METHOD(RGB32I,     3, UNCOMP_FORMAT,   GL_RGB32I,           GL_RGBA_INTEGER,    0, 32, 32, 32,  0, 0, 0, 32*3, 32*3,    GL_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGB32I, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGB32UI,    3, UNCOMP_FORMAT,   GL_RGB32UI,          GL_RGBA_INTEGER,    0, 32, 32, 32,  0, 0, 0, 32*3, 32*3,    GL_UNSIGNED_INT, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGB32UI, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA32I,    4, UNCOMP_FORMAT,   GL_RGBA32I,          GL_RGBA_INTEGER,    0, 32, 32, 32, 32, 0, 0, 32*4, 32*4,    GL_INT, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA32I, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA32UI,   4, UNCOMP_FORMAT,   GL_RGBA32UI,         GL_RGBA_INTEGER,    0, 32, 32, 32, 32, 0, 0, 32*4, 32*4,    GL_UNSIGNED_INT, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA32UI, ImageFormat::COLOR_SPACE_RGB);


DEFINE_TEXTUREFORMAT_METHOD(R11G11B10F, 3, UNCOMP_FORMAT,   GL_R11F_G11F_B10F_EXT,GL_RGB,     0,  0, 11, 11, 10, 0, 0,   32,   32,    GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_R11G11B10F, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGB9E5F,    3, UNCOMP_FORMAT,   GL_RGB9_E5_EXT,      GL_RGB,     0,  0, 14, 14, 14, 0, 0,   32,   32,    GL_FLOAT, OPAQUE_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_RGB9E5F, ImageFormat::COLOR_SPACE_RGB);

// The base format for integer formats must be *_INTEGER even though the spec doesn't state this
DEFINE_TEXTUREFORMAT_METHOD(RGB8I,      3, UNCOMP_FORMAT,   GL_RGB8I_EXT,        GL_RGB_INTEGER,     0,  0,  8,  8,  8,  0,  0, 32, 24,      GL_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGB8I, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGB8UI,     3, UNCOMP_FORMAT,   GL_RGB8UI_EXT,       GL_RGB_INTEGER,     0,  0,  8,  8,  8,  0,  0, 32, 24,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGB8UI, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA8I,     4, UNCOMP_FORMAT,   GL_RGBA8I_EXT,       GL_RGBA_INTEGER,    0,  8,  8,  8,  8,  0,  0, 32, 32,      GL_BYTE, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA8I, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA8UI,    4, UNCOMP_FORMAT,   GL_RGBA8UI_EXT,      GL_RGBA_INTEGER,    0,  8,  8,  8,  8,  0,  0, 32, 32,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, INTEGER_FORMAT, ImageFormat::CODE_RGBA8UI, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGB8_SNORM, 3, UNCOMP_FORMAT,   GL_RGB8_SNORM,       GL_RGB,       0,  0,  8,  8,  8,  0,  0, 32, 32,      GL_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB8_SNORM, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGBA8_SNORM,4, UNCOMP_FORMAT,   GL_RGBA8_SNORM,      GL_RGBA,      0,  8,  8,  8,  8,  0,  0, 32, 32,      GL_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGBA8_SNORM, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGB16_SNORM,3, UNCOMP_FORMAT,   GL_RGB16_SNORM,      GL_RGB,       0,  0, 16, 16, 16,  0,  0, 64, 64,      GL_SHORT, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGB16_SNORM, ImageFormat::COLOR_SPACE_RGB);
DEFINE_TEXTUREFORMAT_METHOD(RGBA16_SNORM,4,UNCOMP_FORMAT,   GL_RGBA16_SNORM,     GL_RGB,      0, 16, 16, 16, 16,  0,  0, 64, 64,      GL_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_RGBA16_SNORM, ImageFormat::COLOR_SPACE_RGB);


DEFINE_TEXTUREFORMAT_METHOD(RGB_DXT1,   3, COMP_FORMAT,     GL_COMPRESSED_RGB_S3TC_DXT1_EXT,    GL_RGB,     0, 0, 0, 0, 0, 0, 0, 64, 64,    GL_UNSIGNED_BYTE, OPAQUE_FORMAT, OTHER, ImageFormat::CODE_RGB_DXT1, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGBA_DXT1,  4, COMP_FORMAT,     GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,   GL_RGBA,    0, 0, 0, 0, 0, 0, 0, 64, 64,    GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_RGBA_DXT1, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGBA_DXT3,  4, COMP_FORMAT,     GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,   GL_RGBA,    0, 0, 0, 0, 0, 0, 0, 128, 128,  GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_RGBA_DXT3, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(RGBA_DXT5,  4, COMP_FORMAT,     GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,   GL_RGBA,    0, 0, 0, 0, 0, 0, 0, 128, 128,  GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_RGBA_DXT5, ImageFormat::COLOR_SPACE_RGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGB8,      3, UNCOMP_FORMAT,   GL_SRGB8,                           GL_RGB,                0,  0,  8,  8,  8,  0,  0, 32, 24,      GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_SRGB8, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGBA8,     4, UNCOMP_FORMAT,   GL_SRGB8_ALPHA8,                    GL_RGBA,            0,  8,  8,  8,  8,  0,  0, 32, 24,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_SRGBA8, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SL8,        1, UNCOMP_FORMAT,   GL_SLUMINANCE8,                     GL_LUMINANCE,        8,  0,  0,  0,  0,  0,  0, 8, 8,        GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_SL8, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SLA8,       2, UNCOMP_FORMAT,   GL_SLUMINANCE8_ALPHA8,              GL_LUMINANCE_ALPHA,    8,  8,  0,  0,  0,  0,  0, 16, 16,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_SLA8, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGB_DXT1,  3, COMP_FORMAT,     GL_COMPRESSED_SRGB_S3TC_DXT1_EXT,       GL_RGB,            0, 0, 0, 0, 0, 0, 0, 64, 64,    GL_UNSIGNED_BYTE, OPAQUE_FORMAT, OTHER, ImageFormat::CODE_SRGB_DXT1, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGBA_DXT1, 4, COMP_FORMAT,     GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT, GL_RGBA,        0, 0, 0, 0, 0, 0, 0, 64, 64,    GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_SRGBA_DXT1, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGBA_DXT3, 4, COMP_FORMAT,     GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT, GL_RGBA,        0, 0, 0, 0, 0, 0, 0, 128, 128,  GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_SRGBA_DXT3, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(SRGBA_DXT5, 4, COMP_FORMAT,     GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT, GL_RGBA,        0, 0, 0, 0, 0, 0, 0, 128, 128,  GL_UNSIGNED_BYTE, CLEAR_FORMAT, OTHER, ImageFormat::CODE_SRGBA_DXT5, ImageFormat::COLOR_SPACE_SRGB);

DEFINE_TEXTUREFORMAT_METHOD(DEPTH16,    1, UNCOMP_FORMAT,   GL_DEPTH_COMPONENT16_ARB,           GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 16, 0, 16, 16,   GL_UNSIGNED_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_DEPTH16, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(DEPTH24,    1, UNCOMP_FORMAT,   GL_DEPTH_COMPONENT24_ARB,           GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 24, 0, 32, 24,   GL_UNSIGNED_INT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_DEPTH24, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(DEPTH32,    1, UNCOMP_FORMAT,   GL_DEPTH_COMPONENT32_ARB,           GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 32, 0, 32, 32,   GL_UNSIGNED_INT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_DEPTH32, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(DEPTH32F,   1, UNCOMP_FORMAT,   GL_DEPTH_COMPONENT32_ARB,           GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 32, 0, 32, 32,   GL_FLOAT, CLEAR_FORMAT, FLOATING_POINT_FORMAT, ImageFormat::CODE_DEPTH32F, ImageFormat::COLOR_SPACE_NONE);

// These formats are for use with Renderbuffers only!
DEFINE_TEXTUREFORMAT_METHOD(STENCIL1,   1, UNCOMP_FORMAT,   GL_STENCIL_INDEX1_EXT,              GL_STENCIL_INDEX,  0, 0, 0, 0, 0, 0, 1, 1, 1,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_STENCIL1, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(STENCIL4,   1, UNCOMP_FORMAT,   GL_STENCIL_INDEX4_EXT,              GL_STENCIL_INDEX,  0, 0, 0, 0, 0, 0, 4, 4, 4,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_STENCIL4, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(STENCIL8,   1, UNCOMP_FORMAT,   GL_STENCIL_INDEX8_EXT,              GL_STENCIL_INDEX,  0, 0, 0, 0, 0, 0, 8, 8, 8,      GL_UNSIGNED_BYTE, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_STENCIL8, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(STENCIL16,  1, UNCOMP_FORMAT,   GL_STENCIL_INDEX16_EXT,             GL_STENCIL_INDEX, 0, 0, 0, 0, 0, 0, 16, 16, 16,   GL_UNSIGNED_SHORT, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_STENCIL16, ImageFormat::COLOR_SPACE_NONE);

DEFINE_TEXTUREFORMAT_METHOD(DEPTH24_STENCIL8,   2, UNCOMP_FORMAT,   GL_DEPTH24_STENCIL8_EXT,    GL_DEPTH_STENCIL_EXT,0, 0, 0, 0, 0, 24, 8, 32, 32,  GL_UNSIGNED_INT_24_8, CLEAR_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_DEPTH24_STENCIL8, ImageFormat::COLOR_SPACE_NONE);


// TODO: Find out if these are acutally NFP, not integer, formats.
DEFINE_TEXTUREFORMAT_METHOD(YUV420_PLANAR,  3, UNCOMP_FORMAT,   GL_NONE,    GL_NONE, 0, 0, 0, 0, 0, 0, 0, 12, 12,  GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_YUV420_PLANAR, ImageFormat::COLOR_SPACE_YUV);
DEFINE_TEXTUREFORMAT_METHOD(YUV422,         3, UNCOMP_FORMAT,   GL_NONE,    GL_NONE, 0, 0, 0, 0, 0, 0, 0, 16, 16,  GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_YUV422, ImageFormat::COLOR_SPACE_YUV);
DEFINE_TEXTUREFORMAT_METHOD(YUV444,         3, UNCOMP_FORMAT,   GL_NONE,    GL_NONE, 0, 0, 0, 0, 0, 0, 0, 24, 24,  GL_UNSIGNED_BYTE, OPAQUE_FORMAT, NORMALIZED_FIXED_POINT_FORMAT, ImageFormat::CODE_YUV444, ImageFormat::COLOR_SPACE_YUV);

}
