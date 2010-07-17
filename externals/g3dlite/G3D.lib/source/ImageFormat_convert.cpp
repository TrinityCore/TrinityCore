#include "G3D/ImageFormat.h"
#include "G3D/Color1uint8.h"
#include "G3D/Color3uint8.h"
#include "G3D/Color4uint8.h"
#include "G3D/Color1.h"
#include "G3D/Color3.h"
#include "G3D/Color4.h"


namespace G3D {

// this is the signature for all conversion routines (same parameters as ImageFormat::convert)
typedef void (*ConvertFunc)(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg);

// this defines the conversion routines for converting between compatible formats
static const int NUM_CONVERT_IMAGE_FORMATS = 5;
struct ConvertAttributes {
    ConvertFunc         m_converter;
    ImageFormat::Code   m_sourceFormats[NUM_CONVERT_IMAGE_FORMATS];
    ImageFormat::Code   m_destFormats[NUM_CONVERT_IMAGE_FORMATS];
    bool                m_handlesSourcePadding;
    bool                m_handlesDestPadding;
    bool                m_handleInvertY;
};

// forward declare the converters we can use them below
#define DECLARE_CONVERT_FUNC(name) static void name(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg);

DECLARE_CONVERT_FUNC(l8_to_rgb8);
DECLARE_CONVERT_FUNC(l32f_to_rgb8);
DECLARE_CONVERT_FUNC(rgb8_to_rgba8);
DECLARE_CONVERT_FUNC(rgb8_to_bgr8);
DECLARE_CONVERT_FUNC(rgb8_to_rgba32f);
DECLARE_CONVERT_FUNC(bgr8_to_rgb8);
DECLARE_CONVERT_FUNC(bgr8_to_rgba8);
DECLARE_CONVERT_FUNC(bgr8_to_rgba32f);
DECLARE_CONVERT_FUNC(rgba8_to_rgb8);
DECLARE_CONVERT_FUNC(rgba8_to_bgr8);
DECLARE_CONVERT_FUNC(rgba8_to_rgba32f);
DECLARE_CONVERT_FUNC(rgb32f_to_rgba32f);
DECLARE_CONVERT_FUNC(rgba32f_to_rgb8);
DECLARE_CONVERT_FUNC(rgba32f_to_rgba8);
DECLARE_CONVERT_FUNC(rgba32f_to_bgr8);
DECLARE_CONVERT_FUNC(rgba32f_to_rgb32f);
DECLARE_CONVERT_FUNC(rgba32f_to_bayer_rggb8);
DECLARE_CONVERT_FUNC(rgba32f_to_bayer_gbrg8);
DECLARE_CONVERT_FUNC(rgba32f_to_bayer_grbg8);
DECLARE_CONVERT_FUNC(rgba32f_to_bayer_bggr8);
DECLARE_CONVERT_FUNC(bayer_rggb8_to_rgba32f);
DECLARE_CONVERT_FUNC(bayer_gbrg8_to_rgba32f);
DECLARE_CONVERT_FUNC(bayer_grbg8_to_rgba32f);
DECLARE_CONVERT_FUNC(bayer_bggr8_to_rgba32f);
DECLARE_CONVERT_FUNC(rgb8_to_yuv420p);
DECLARE_CONVERT_FUNC(rgb8_to_yuv422);
DECLARE_CONVERT_FUNC(rgb8_to_yuv444);
DECLARE_CONVERT_FUNC(yuv420p_to_rgb8);
DECLARE_CONVERT_FUNC(yuv422_to_rgb8);
DECLARE_CONVERT_FUNC(yuv444_to_rgb8);

// this is the list of mappings between formats and the routines to perform them
static const ConvertAttributes sConvertMappings[] = {

    // RGB -> RGB color space
    // L8 ->
    {l8_to_rgb8,        {ImageFormat::CODE_L8, ImageFormat::CODE_NONE},         {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, true},

    // L32F ->
    {l32f_to_rgb8,      {ImageFormat::CODE_L32F, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, true},

    // RGB8 ->
    {rgb8_to_rgba8,     {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE}, false, false, true},
    {rgb8_to_bgr8,      {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE}, false, false, true},
    {rgb8_to_rgba32f,   {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, true, false, true},

    // BGR8 ->
    {bgr8_to_rgb8,      {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, true},
    {bgr8_to_rgba8,     {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE}, false, false, true},
    {bgr8_to_rgba32f,   {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE},       {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, true, false, true},

    // RGBA8 ->
    {rgba8_to_rgb8,     {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE},      {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, true},
    {rgba8_to_bgr8,     {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE},      {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE}, false, false, true},
    {rgba8_to_rgba32f,  {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE},      {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, true, false, true},

    // RGB32F ->
    {rgb32f_to_rgba32f, {ImageFormat::CODE_RGB32F, ImageFormat::CODE_NONE},     {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, true, false, true},

    // RGBA32F ->
    {rgba32f_to_rgb8,   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_rgba8,  {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGBA8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_bgr8,   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},    {ImageFormat::CODE_BGR8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_rgb32f, {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGB32F, ImageFormat::CODE_NONE}, false, true, true},
    
    // RGB -> BAYER color space
    {rgba32f_to_bayer_rggb8, {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},       {ImageFormat::CODE_BAYER_RGGB8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_bayer_gbrg8, {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},       {ImageFormat::CODE_BAYER_GBRG8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_bayer_grbg8, {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},       {ImageFormat::CODE_BAYER_GRBG8, ImageFormat::CODE_NONE}, false, true, true},
    {rgba32f_to_bayer_bggr8, {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE},       {ImageFormat::CODE_BAYER_BGGR8, ImageFormat::CODE_NONE}, false, true, true},

    // BAYER -> RGB color space
    {bayer_rggb8_to_rgba32f, {ImageFormat::CODE_BAYER_RGGB8, ImageFormat::CODE_NONE},   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, false, false, true},
    {bayer_gbrg8_to_rgba32f, {ImageFormat::CODE_BAYER_GBRG8, ImageFormat::CODE_NONE},   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, false, false, true},
    {bayer_grbg8_to_rgba32f, {ImageFormat::CODE_BAYER_GRBG8, ImageFormat::CODE_NONE},   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, false, false, true},
    {bayer_bggr8_to_rgba32f, {ImageFormat::CODE_BAYER_BGGR8, ImageFormat::CODE_NONE},   {ImageFormat::CODE_RGBA32F, ImageFormat::CODE_NONE}, false, false, true},

    // RGB <-> YUV color space
    {rgb8_to_yuv420p, {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},     {ImageFormat::CODE_YUV420_PLANAR, ImageFormat::CODE_NONE}, false, false, false},
    {rgb8_to_yuv422, {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},      {ImageFormat::CODE_YUV422, ImageFormat::CODE_NONE}, false, false, false},
    {rgb8_to_yuv444, {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE},      {ImageFormat::CODE_YUV444, ImageFormat::CODE_NONE}, false, false, false},
    {yuv420p_to_rgb8, {ImageFormat::CODE_YUV420_PLANAR, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, false},
    {yuv422_to_rgb8, {ImageFormat::CODE_YUV422, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, false},
    {yuv444_to_rgb8, {ImageFormat::CODE_YUV444, ImageFormat::CODE_NONE},    {ImageFormat::CODE_RGB8, ImageFormat::CODE_NONE}, false, false, false},
};

static ConvertFunc findConverter(TextureFormat::Code sourceCode, TextureFormat::Code destCode, bool needsSourcePadding, bool needsDestPadding, bool needsInvertY) {
    int numRoutines = sizeof(sConvertMappings) / sizeof(ConvertAttributes);
    for (int routineIndex = 0; routineIndex < numRoutines; ++routineIndex) {
        int sourceIndex = 0;
        ConvertAttributes routine = sConvertMappings[routineIndex];

        while (routine.m_sourceFormats[sourceIndex] != ImageFormat::CODE_NONE) {
            // check for matching source
            if (routine.m_sourceFormats[sourceIndex] == sourceCode) {
                int destIndex = 0;

                // now check for matching dest to see if the routine fits
                while (routine.m_destFormats[destIndex] != ImageFormat::CODE_NONE) {

                    // check if dest format matches and padding + invert rules match
                    if ((routine.m_destFormats[destIndex] == destCode) &&
                        (!needsSourcePadding || (routine.m_handlesSourcePadding == needsSourcePadding)) &&
                        (!needsDestPadding || (routine.m_handlesDestPadding == needsDestPadding)) &&
                        (!needsInvertY || (routine.m_handleInvertY == needsInvertY))) {

                        // found compatible converter
                        return routine.m_converter;
                    }
                    ++destIndex;
                }
            }
            ++sourceIndex;
        }
    }

    return NULL;
}

bool conversionAvailable(const ImageFormat* srcFormat, int srcRowPadBits, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY = false) {
    bool conversionAvailable = false;

    // check if a conversion is available
    if ( (srcFormat->code == dstFormat->code) && (srcRowPadBits == dstRowPadBits) && !invertY) {
        conversionAvailable = true;
    } else {
        ConvertFunc directConverter = findConverter(srcFormat->code, dstFormat->code, srcRowPadBits > 0, dstRowPadBits > 0, invertY);

        conversionAvailable = (directConverter != NULL);
    }

    return conversionAvailable;
}

bool ImageFormat::convert(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits,
                          const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, 
                          bool invertY, BayerAlgorithm bayerAlg) {

    bool conversionAvailable = false;

    // Handle direct copy of image to same format
    if ( (srcFormat->code == dstFormat->code) && (srcRowPadBits == dstRowPadBits) && !invertY) {

        System::memcpy(dstBytes[0], srcBytes[0], iCeil(((srcWidth * srcFormat->cpuBitsPerPixel + srcRowPadBits) * srcHeight) / 8.0f));
        conversionAvailable = true;
    } else {
        // if no direct conversion routine exists,
        // then look for conversion to intermediate
        // and then from intermediate to dest.
        // intermediate format is RGBA32F
        ConvertFunc directConverter = findConverter(srcFormat->code, dstFormat->code, srcRowPadBits > 0, dstRowPadBits > 0, invertY);

        // if we have a direct converter, use it, otherwise find intermdiate path
        if (directConverter) {
            directConverter(srcBytes, srcWidth, srcHeight, srcFormat, srcRowPadBits, dstBytes, dstFormat, dstRowPadBits, invertY, bayerAlg);
            conversionAvailable = true;
        } else {
            ConvertFunc toInterConverter = findConverter(srcFormat->code, ImageFormat::CODE_RGBA32F, srcRowPadBits > 0, false, false);;
            ConvertFunc fromInterConverter = findConverter(ImageFormat::CODE_RGBA32F, dstFormat->code, false, dstRowPadBits > 0, invertY);;

            if (toInterConverter && fromInterConverter) {
                Array<void*> tmp;
                tmp.append(System::malloc(srcWidth * srcHeight * ImageFormat::RGBA32F()->cpuBitsPerPixel * 8));

                toInterConverter(srcBytes, srcWidth, srcHeight, srcFormat, srcRowPadBits, tmp, ImageFormat::RGBA32F(), 0, false, bayerAlg);
                fromInterConverter(reinterpret_cast<Array<const void*>&>(tmp), srcWidth, srcHeight, ImageFormat::RGBA32F(), 0, dstBytes, dstFormat, dstRowPadBits, invertY, bayerAlg);

                System::free(tmp[0]);

                conversionAvailable = true;
            }
        }
    }

    return conversionAvailable;
}


// *******************
// RGB -> RGB color space conversions
// *******************

// L8 ->
static void l8_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;

            dst[i3 + 0] = src[i]; 
            dst[i3 + 1] = src[i]; 
            dst[i3 + 2] = src[i]; 
        }
    }
}

// L32F ->
static void l32f_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    int srcIndex = 0;
    int dstByteOffset = 0;
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const float* src = static_cast<const float*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            srcIndex = srcWidth * (srcHeight - y - 1);
        }
        
        for (int x = 0; x < srcWidth; ++x, ++srcIndex, dstByteOffset += 3) {
            Color3uint8&  d = *reinterpret_cast<Color3uint8*>(dst + dstByteOffset);
            float s = src[srcIndex];

            uint8 c = iMin(255, iFloor(s * 256));
            d = Color3uint8(c, c, c);
        }
    } 
}

// RGB8 ->
static void rgb8_to_rgba8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            int i4 = i3 + i; 

            dst[i4 + 0] = src[i3 + 0]; 
            dst[i4 + 1] = src[i3 + 1]; 
            dst[i4 + 2] = src[i3 + 2]; 
            dst[i4 + 3] = 255; 
        }
    }
}

static void rgb8_to_bgr8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            dst[i3 + 0] = src[i3 + 2];
            dst[i3 + 1] = src[i3 + 1];
            dst[i3 + 2] = src[i3 + 0];
        }
    }
}

static void rgb8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits % 8 == 0, "Source row padding must be a multiple of 8 bits for this format");

    int dstIndex = 0;
    int srcByteOffset = 0;
    int srcRowPadBytes = srcRowPadBits / 8;
    Color4* dst = static_cast<Color4*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            dstIndex = srcWidth * (srcHeight - 1 - y);
        }
        for (int x = 0; x < srcWidth; ++x, ++dstIndex, srcByteOffset += 3) {
            const Color3uint8& s = *reinterpret_cast<const Color3uint8*>(src + srcByteOffset);
            dst[dstIndex] = Color4(Color3(s), 1.0f);
        }
        srcByteOffset += srcRowPadBytes;
    }
}

// BGR8 ->
static void bgr8_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            dst[i3 + 0] = src[i3 + 2];
            dst[i3 + 1] = src[i3 + 1];
            dst[i3 + 2] = src[i3 + 0];
        }
    }
}

static void bgr8_to_rgba8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            int i4 = i3 + i; 

            dst[i4 + 0] = src[i3 + 2]; 
            dst[i4 + 1] = src[i3 + 1]; 
            dst[i4 + 2] = src[i3 + 0]; 
            dst[i4 + 3] = 255; 
        }
    }
}

static void bgr8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits % 8 == 0, "Source row padding must be a multiple of 8 bits for this format");

    int dstIndex = 0;
    int srcByteOffset = 0;
    int srcRowPadBytes = srcRowPadBits / 8;
    Color4* dst = static_cast<Color4*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            dstIndex = srcWidth * (srcHeight - 1 - y);
        }

        for (int x = 0; x < srcWidth; ++x, ++dstIndex, srcByteOffset += 3) {
            const Color3uint8& s = *reinterpret_cast<const Color3uint8*>(src + srcByteOffset);
            dst[dstIndex] = Color4(Color3(s).bgr(), 1.0f);
        }
        srcByteOffset += srcRowPadBytes;
    }
}

// RGBA8 ->
static void rgba8_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            int i4 = i3 + i;

            dst[i3 + 0] = src[i4 + 0]; 
            dst[i3 + 1] = src[i4 + 1]; 
            dst[i3 + 2] = src[i4 + 2]; 
        }
    }
}

static void rgba8_to_bgr8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);
    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {
            int i = (invertY) ? ((srcHeight-1-y) * srcWidth +x) : (y * srcWidth + x);
            int i3 = i * 3;
            int i4 = i3 + i;

            dst[i3 + 0] = src[i4 + 2]; 
            dst[i3 + 1] = src[i4 + 1]; 
            dst[i3 + 2] = src[i4 + 0]; 
        }
    }
}

static void rgba8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits % 8 == 0, "Source row padding must be a multiple of 8 bits for this format");

    int dstIndex = 0;
    int srcByteOffset = 0;
    int srcRowPadBytes = srcRowPadBits / 8;
    Color4* dst = static_cast<Color4*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            dstIndex = srcWidth * (srcHeight - 1 - y);
        }

        for (int x = 0; x < srcWidth; ++x, ++dstIndex, srcByteOffset += 4) {
            const Color4uint8& s = *reinterpret_cast<const Color4uint8*>(src + srcByteOffset);
            dst[dstIndex] = Color4(s);
        }
        srcByteOffset += srcRowPadBytes;
    }
}

// RGB32F ->
static void rgb32f_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits % 8 == 0, "Source row padding must be a multiple of 8 bits for this format");

    int dstIndex = 0;
    int srcByteOffset = 0;
    int srcRowPadBytes = srcRowPadBits / 8;
    Color4* dst = static_cast<Color4*>(dstBytes[0]);
    const uint8* src = static_cast<const uint8*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            dstIndex = srcWidth * (srcHeight - 1 - y);
        }

        for (int x = 0; x < srcWidth; ++x, ++dstIndex, srcByteOffset += 3 * sizeof(float)) {
            const Color3& s = *reinterpret_cast<const Color3*>(src + srcByteOffset);
            dst[dstIndex] = Color4(Color3(s), 1.0f);
        }
        srcByteOffset += srcRowPadBytes;
    }
}

// RGBA32F ->
static void rgba32f_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(dstRowPadBits % 8 == 0, "Destination row padding must be a multiple of 8 bits for this format");

    int srcIndex = 0;
    int dstByteOffset = 0;
    int dstRowPadBytes = dstRowPadBits / 8;
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const Color4* src = static_cast<const Color4*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            srcIndex = srcWidth * (srcHeight - y - 1);
        }
        
        for (int x = 0; x < srcWidth; ++x, ++srcIndex, dstByteOffset += 3) {
            Color3uint8&  d = *reinterpret_cast<Color3uint8*>(dst + dstByteOffset);
            const Color4& s = src[srcIndex];

            d = Color3uint8(s.rgb());
        }
        dstByteOffset += dstRowPadBytes;
    } 
}

static void rgba32f_to_rgba8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(dstRowPadBits % 8 == 0, "Destination row padding must be a multiple of 8 bits for this format");

    int srcIndex = 0;
    int dstByteOffset = 0;
    int dstRowPadBytes = dstRowPadBits / 8;
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const Color4* src = static_cast<const Color4*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            srcIndex = srcWidth * (srcHeight - 1 - y);
        }
        for (int x = 0; x < srcWidth; ++x, ++srcIndex, dstByteOffset += 4) {
            Color4uint8&  d = *reinterpret_cast<Color4uint8*>(dst + dstByteOffset);
            const Color4& s = src[srcIndex];

            d = Color4uint8(s);
        }
        dstByteOffset += dstRowPadBytes;
    } 
}

static void rgba32f_to_bgr8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(dstRowPadBits % 8 == 0, "Destination row padding must be a multiple of 8 bits for this format");

    int srcIndex = 0;
    int dstByteOffset = 0;
    int dstRowPadBytes = dstRowPadBits / 8;
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const Color4* src = static_cast<const Color4*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            srcIndex = srcWidth * (srcHeight - y - 1);
        }
        
        for (int x = 0; x < srcWidth; ++x, ++srcIndex, dstByteOffset += 3) {
            Color3uint8&  d = *reinterpret_cast<Color3uint8*>(dst + dstByteOffset);
            const Color4& s = src[srcIndex];

            d = Color3uint8(s.rgb()).bgr();
        }
        dstByteOffset += dstRowPadBytes;
    } 
}

static void rgba32f_to_rgb32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(dstRowPadBits % 8 == 0, "Destination row padding must be a multiple of 8 bits for this format");

    int srcIndex = 0;
    int dstByteOffset = 0;
    int dstRowPadBytes = dstRowPadBits / 8;
    uint8* dst = static_cast<uint8*>(dstBytes[0]);
    const Color4* src = static_cast<const Color4*>(srcBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        if (invertY) {
            srcIndex = srcWidth * (srcHeight - 1 - y);
        }
        for (int x = 0; x < srcWidth; ++x, ++srcIndex, dstByteOffset += 3 * sizeof(float)) {
            Color3& d = *reinterpret_cast<Color3*>(dst + dstByteOffset);
            const Color4& s = src[srcIndex];	    
            d = Color3(s);
        }
        dstByteOffset += dstRowPadBytes;
    } 
}

// *******************
// RGB <-> YUV color space conversions
// *******************

static uint32 blendPixels(uint32 pixel1, uint32 pixel2) {
    static const uint32 rbMask = 0x00FF00FF;
    static const uint32 agMask = 0xFF00FF00;

    // Compute two color channels at a time.  Use >> 1 for fast division by two
    // Using alternating color channels prevents overflow
    const uint32 rb = ((pixel1 & rbMask) + (pixel2 & rbMask)) >> 1;

    // Shift first to avoid overflow in alpha channel
    const uint32 ag = (((pixel1 & agMask) >> 1) + ((pixel2 & agMask) >> 1));

    return ((rb & rbMask) | (ag & agMask));
}

#define PIXEL_RGB8_TO_YUV_Y(r, g, b) static_cast<uint8>(iClamp(((66 * r + 129 * g + 25 * b + 128) >> 8) + 16, 0, 255))
#define PIXEL_RGB8_TO_YUV_U(r, g, b) static_cast<uint8>(iClamp(((-38 * r - 74 * g + 112 * b + 128) >> 8) + 128, 0, 255))
#define PIXEL_RGB8_TO_YUV_V(r, g, b) static_cast<uint8>(iClamp(((112 * r - 94 * g - 18 * b + 128) >> 8) + 128, 0, 255))

static void rgb8_to_yuv420p(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");
    debugAssertM((srcWidth % 2 == 0) && (srcHeight % 2 == 0), "Source width and height must be a multiple of two");

    const Color3uint8* src = static_cast<const Color3uint8*>(srcBytes[0]);

    uint8* dstY = static_cast<uint8*>(dstBytes[0]);
    uint8* dstU = static_cast<uint8*>(dstBytes[1]);
    uint8* dstV = static_cast<uint8*>(dstBytes[2]);

    for (int y = 0; y < srcHeight; y += 2) {
        for (int x = 0; x < srcWidth; x += 2) {

            // convert 4-pixel block at a time
            int srcPixelOffset0 = y * srcWidth + x;
            int srcPixelOffset1 = srcPixelOffset0 + 1;
            int srcPixelOffset2 = srcPixelOffset0 + srcWidth;
            int srcPixelOffset3 = srcPixelOffset2 + 1;

            int yIndex = y * srcWidth + x;

            dstY[yIndex] =     PIXEL_RGB8_TO_YUV_Y(src[srcPixelOffset0].r, src[srcPixelOffset0].g, src[srcPixelOffset0].b);
            dstY[yIndex + 1] = PIXEL_RGB8_TO_YUV_Y(src[srcPixelOffset1].r, src[srcPixelOffset1].g, src[srcPixelOffset1].b);

            yIndex += srcWidth;
            dstY[yIndex] =     PIXEL_RGB8_TO_YUV_Y(src[srcPixelOffset2].r, src[srcPixelOffset2].g, src[srcPixelOffset2].b);
            dstY[yIndex + 1] = PIXEL_RGB8_TO_YUV_Y(src[srcPixelOffset3].r, src[srcPixelOffset3].g, src[srcPixelOffset3].b);

            uint32 blendedPixel = blendPixels(src[srcPixelOffset0].asUInt32(), src[srcPixelOffset2].asUInt32());
            Color3uint8 uvSrcColor = Color3uint8::fromARGB(blendedPixel);

            int uvIndex = y / 2 * srcWidth / 2 + x / 2;
            dstU[uvIndex] =    PIXEL_RGB8_TO_YUV_U(uvSrcColor.r, uvSrcColor.g, uvSrcColor.b);
            dstV[uvIndex] =    PIXEL_RGB8_TO_YUV_V(uvSrcColor.r, uvSrcColor.g, uvSrcColor.b);
        }
    }
}

static void rgb8_to_yuv422(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");
    debugAssertM((srcWidth % 2 == 0), "Source width must be a multiple of two");

    const Color3uint8* src = static_cast<const Color3uint8*>(srcBytes[0]);

    uint8* dst = static_cast<uint8*>(dstBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; x += 2) {

            // convert 2-pixel horizontal block at a time
            int srcIndex = y * srcWidth + x;
            int dstIndex = srcIndex * 2;

            uint32 blendedPixel = blendPixels(src[srcIndex].asUInt32(), src[srcIndex + 1].asUInt32());
            Color3uint8 uvSrcColor = Color3uint8::fromARGB(blendedPixel);

            dst[dstIndex]     = PIXEL_RGB8_TO_YUV_Y(src[srcIndex].r, src[srcIndex].g, src[srcIndex].b);

            dst[dstIndex + 1] = PIXEL_RGB8_TO_YUV_U(uvSrcColor.r, uvSrcColor.g, uvSrcColor.b);

            dst[dstIndex + 2] = PIXEL_RGB8_TO_YUV_Y(src[srcIndex + 1].r, src[srcIndex + 1].g, src[srcIndex + 1].b);

            dst[dstIndex + 3] = PIXEL_RGB8_TO_YUV_V(uvSrcColor.r, uvSrcColor.g, uvSrcColor.b);

        }
    }
}

static void rgb8_to_yuv444(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");

    const Color3uint8* src = static_cast<const Color3uint8*>(srcBytes[0]);

    Color3uint8* dst = static_cast<Color3uint8*>(dstBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {

            // convert 1-pixels at a time
            int index = y * srcWidth + x;
            uint8 y = PIXEL_RGB8_TO_YUV_Y(src[index].r, src[index].g, src[index].b);
            uint8 u = PIXEL_RGB8_TO_YUV_U(src[index].r, src[index].g, src[index].b);
            uint8 v = PIXEL_RGB8_TO_YUV_V(src[index].r, src[index].g, src[index].b);

            dst[index].r = y;
            dst[index].g = u;
            dst[index].b = v;
        }
    }
}


#define PIXEL_YUV_TO_RGB8_R(y, u, v) static_cast<uint8>(iClamp((298 * (y - 16) + 409 * (v - 128) + 128) >> 8, 0, 255))
#define PIXEL_YUV_TO_RGB8_G(y, u, v) static_cast<uint8>(iClamp((298 * (y - 16) - 100 * (u - 128) - 208 * (v - 128) + 128) >> 8, 0, 255))
#define PIXEL_YUV_TO_RGB8_B(y, u, v) static_cast<uint8>(iClamp((298 * (y - 16) + 516 * (u - 128) + 128) >> 8, 0, 255))

static void yuv420p_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");
    debugAssertM((srcWidth % 2 == 0) && (srcHeight % 2 == 0), "Source width and height must be a multiple of two");

    const uint8* srcY = static_cast<const uint8*>(srcBytes[0]);
    const uint8* srcU = static_cast<const uint8*>(srcBytes[1]);
    const uint8* srcV = static_cast<const uint8*>(srcBytes[2]);

    Color3uint8* dst = static_cast<Color3uint8*>(dstBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; x += 2) {

            // convert to two rgb pixels in a row
            Color3uint8* rgb = &dst[y * srcWidth + x];

            int yOffset = y * srcWidth + x;
            int uvOffset = y / 2 * srcWidth / 2 + x / 2;

            rgb->r = PIXEL_YUV_TO_RGB8_R(srcY[yOffset], srcU[uvOffset], srcV[uvOffset]);
            rgb->g = PIXEL_YUV_TO_RGB8_G(srcY[yOffset], srcU[uvOffset], srcV[uvOffset]);
            rgb->b = PIXEL_YUV_TO_RGB8_B(srcY[yOffset], srcU[uvOffset], srcV[uvOffset]);

            rgb += 1;
            rgb->r = PIXEL_YUV_TO_RGB8_R(srcY[yOffset + 1], srcU[uvOffset], srcV[uvOffset]);
            rgb->g = PIXEL_YUV_TO_RGB8_G(srcY[yOffset + 1], srcU[uvOffset], srcV[uvOffset]);
            rgb->b = PIXEL_YUV_TO_RGB8_B(srcY[yOffset + 1], srcU[uvOffset], srcV[uvOffset]);
        }
    }
}

static void yuv422_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");
    debugAssertM((srcWidth % 2 == 0), "Source width must be a multiple of two");

    const uint8* src = static_cast<const uint8*>(srcBytes[0]);

    Color3uint8* dst = static_cast<Color3uint8*>(dstBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; x += 2) {

            // convert to two rgb pixels in a row
            Color3uint8* rgb = &dst[y * srcWidth + x];
            
            int srcIndex = (y * srcWidth + x) * 2;
            uint8 y  = src[srcIndex];
            uint8 u  = src[srcIndex + 1];
            uint8 y2 = src[srcIndex + 2];
            uint8 v  = src[srcIndex + 3];

            rgb->r = PIXEL_YUV_TO_RGB8_R(y, u, v);
            rgb->g = PIXEL_YUV_TO_RGB8_G(y, u, v);
            rgb->b = PIXEL_YUV_TO_RGB8_B(y, u, v);

            rgb += 1;
            rgb->r = PIXEL_YUV_TO_RGB8_R(y2, u, v);
            rgb->g = PIXEL_YUV_TO_RGB8_G(y2, u, v);
            rgb->b = PIXEL_YUV_TO_RGB8_B(y2, u, v);
        }
    }
}

static void yuv444_to_rgb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    debugAssertM(srcRowPadBits == 0, "Source row padding must be 0 for this format");

    const Color3uint8* src = static_cast<const Color3uint8*>(srcBytes[0]);

    Color3uint8* dst = static_cast<Color3uint8*>(dstBytes[0]);

    for (int y = 0; y < srcHeight; ++y) {
        for (int x = 0; x < srcWidth; ++x) {

            // convert to one rgb pixels at a time
            int index = y * srcWidth + x;
            Color3uint8* rgb = &dst[index];
            
            rgb->r = PIXEL_YUV_TO_RGB8_R(src[index].r, src[index].g, src[index].b);
            rgb->g = PIXEL_YUV_TO_RGB8_G(src[index].r, src[index].g, src[index].b);
            rgb->b = PIXEL_YUV_TO_RGB8_B(src[index].r, src[index].g, src[index].b);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Bayer conversions
//

// There are two kinds of rows (GR and BG).
// In each row, there are two kinds of pixels (G/R, B/G).
// We express the four kinds of INPUT pixels as:
//    GRG, GRG, BGB, BGG
//
// There are three kinds of OUTPUT pixels: R, G, B.
// Thus there are nominally 12 different I/O combinations, 
// but several are impulses because needed output at that 
// location *is* the input (e.g., G_GRG and G_BGG).
//
// The following 5x5 row-major filters are named as output_input.

// Green
static const float G_GRR[5][5] =
    {{     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f},
     {     0.0f,      0.0f,      2.0f,      0.0f,      0.0f},
     {    -1.0f,      2.0f,      4.0f,      2.0f,     -1.0f},
     {     0.0f,      0.0f,      2.0f,      0.0f,      0.0f},
     {     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f}};

static const float G_BGB[5][5] =
    {{     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f},
     {     0.0f,      0.0f,      2.0f,      0.0f,      0.0f},
     {    -1.0f,      2.0f,      4.0f,      2.0f,     -1.0f},
     {     0.0f,      0.0f,      2.0f,      0.0f,      0.0f},
     {     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f}};

// Red 
//(the caption in the paper is wrong for this case:
// "R row B column really means R row G column"
static const float R_GRG[5][5] =
    {{     0.0f,      0.0f,      0.5f,      0.0f,      0.0f},
     {     0.0f,     -1.0f,      0.0f,     -1.0f,      0.0f},
     {    -1.0f,      4.0f,      5.0f,      4.0f,     -1.0f},
     {     0.0f,     -1.0f,      0.0f,     -1.0f,      0.0f},
     {     0.0f,      0.0f,      0.5f,      0.0f,      0.0f}};

static const float R_BGG[5][5] =
    {{     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f},
     {     0.0f,     -1.0f,      4.0f,     -1.0f,      0.0f},
     {     0.5f,      0.0f,      5.0f,      0.0f,      0.5f},
     {     0.0f,     -1.0f,      4.0f,     -1.0f,      0.0f},
     {     0.0f,      0.0f,     -1.0f,      0.0f,      0.0f}};

static const float R_BGB[5][5] =
    {{     0.0f,      0.0f, -3.0f/2.0f,      0.0f,      0.0f},
     {     0.0f,      2.0f,      0.0f,      2.0f,      0.0f},
     {-3.0f/2.0f,      0.0f,      6.0f,      0.0f, -3.0f/2.0f},
     {     0.0f,      2.0f,      0.0f,      2.0f,      0.0f},
     {     0.0f,      0.0f, -3.0f/2.0f,      0.0f,      0.0f}};


// Blue 
//(the caption in the paper is wrong for this case:
// "B row R column really means B row G column")
#define B_BGG R_GRG
#define B_GRG R_BGG
#define B_GRR R_BGB

// =====================================================================
// Helper methods
// =====================================================================


/** Applies a 5x5 filter to monochrome image I (wrapping at the boundaries) */
static uint8 applyFilter(const uint8*    I,
			 int             x,
			 int             y,
			 int             w,
			 int             h,
			 const float     filter[5][5]) {
    
    debugAssert(isEven(w));
    debugAssert(isEven(h));
    
    float sum = 0.0f;
    float denom = 0.0f;
    
    for (int dy = 0; dy < 5; ++dy) {
	int offset = ((y + dy + h - 2) % h) * w;
    
	for (int dx = 0; dx < 5; ++dx) {
	    float f = filter[dy][dx];
	    sum += f * I[((x + dx + w - 2) % w) + offset];
	    denom += f;
	}
    }
    
    return (uint8)iClamp(iRound(sum / denom), 0, 255);
}

/** Helper method for Bayer grbg and bggr --> rgb8 */
static void swapRedAndBlue(int N, Color3uint8* out) {
    for (int i = N - 1; i >= 0; --i) {
	uint8 tmp = out[i].r;
	out[i].r = out[i].b;
	out[i].b = tmp;
    }
}

// RGB -> BAYER color space

// =====================================================================
// rgb8 --> bayer helpers
// =====================================================================
static void rgb8_to_bayer_rggb8(const int w, const int h, 
				const uint8* src, uint8* dst) {
    Color3uint8* srcColor = (Color3uint8*)src;
    Color1uint8* dstColor = (Color1uint8*)dst;

    // Top row pixels
    for (int y = 0; y < h - 1; y += 2) {
	int offset = y * w;

	// Top left pixels
	for(int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].r);
	}

	// Top right pixels
	for(int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}
    }

    // Bottom row pixels
    for (int y = 1; y < h - 1; y += 2) {
	int offset = y * w;

	// Bottom left pixels
	for (int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}

	// Bottom right pixels
	for (int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].b);
	}
    }
}


static void rgb8_to_bayer_grbg8(const int w, const int h, 
				const uint8* src, uint8* dst) {
    Color3uint8* srcColor = (Color3uint8*)src;
    Color1uint8* dstColor = (Color1uint8*)dst;

    // Top row pixels
    for (int y = 0; y < h - 1; y += 2) {
	int offset = y * w;

	// Top left pixels
	for (int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}

	// Top right pixels
	for (int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].r);
	}
    }

    // Bottom row pixels
    for (int y = 1; y < h - 1; y += 2) {
	int offset = y * w;

	// Bottom left pixels
	for (int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].b);
	}

	// Bottom right pixels
	for (int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}
    }
}


static void rgb8_to_bayer_bggr8(const int w, const int h, 
				const uint8* src, uint8* dst) {
    Color3uint8* srcColor = (Color3uint8*)src;
    Color1uint8* dstColor = (Color1uint8*)dst;

    // Top row pixels
    for (int y = 0; y < h - 1; y += 2) {
	int offset = y * w;

	// Top left pixels
	for (int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].b);
	}

	// Top right pixels
	for (int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}
    }

    // Bottom row pixels
    for (int y = 1; y < h - 1; y += 2) {
	int offset = y * w;

	// Bottom left pixels
	for(int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}

	// Bottom right pixels
	for(int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].r);
	}
    }
}


static void rgb8_to_bayer_gbrg8(const int w, const int h, 
				const uint8* src, uint8* dst) {
    Color3uint8* srcColor = (Color3uint8*)src;
    Color1uint8* dstColor = (Color1uint8*)dst;

    // Top row pixels
    for(int y = 0; y < h - 1; y += 2) {
	int offset = y * w;

	// Top left pixels
	for(int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}

	// Top right pixels
	for(int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].b);
	}
    }

    // Bottom row pixels
    for(int y = 1; y < h - 1; y += 2) {
	int offset = y * w;

	// Bottom left pixels
	for(int x = 0; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].r);
	}

	// Bottom right pixels
	for(int x = 1; x < w - 1; x += 2) {
	    dstColor[x + offset] = Color1(srcColor[x + offset].g);
	}
    }
}

// =====================================================================
// rgba32f (-->rgb8) --> bayer converter implementations
// =====================================================================
static void rgba32f_to_bayer_rggb8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    rgba32f_to_rgb8(srcBytes, srcWidth, srcHeight, ImageFormat::RGBA32F(), 0, tmp, ImageFormat::RGB8(), 0, invertY, bayerAlg);
    rgb8_to_bayer_rggb8(srcWidth, srcHeight, static_cast<uint8*>(tmp[0]), static_cast<uint8*>(dstBytes[0]));

    System::free(tmp[0]);
}

static void rgba32f_to_bayer_gbrg8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    rgba32f_to_rgb8(srcBytes, srcWidth, srcHeight, ImageFormat::RGBA32F(), 0, tmp, ImageFormat::RGB8(), 0, invertY, bayerAlg);
    rgb8_to_bayer_grbg8(srcWidth, srcHeight, static_cast<uint8*>(tmp[0]), static_cast<uint8*>(dstBytes[0]));

    System::free(tmp[0]);
}

static void rgba32f_to_bayer_grbg8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    rgba32f_to_rgb8(srcBytes, srcWidth, srcHeight, ImageFormat::RGBA32F(), 0, tmp, ImageFormat::RGB8(), 0, invertY, bayerAlg);
    rgb8_to_bayer_gbrg8(srcWidth, srcHeight, static_cast<uint8*>(tmp[0]), static_cast<uint8*>(dstBytes[0]));

    System::free(tmp[0]);
}

static void rgba32f_to_bayer_bggr8(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    rgba32f_to_rgb8(srcBytes, srcWidth, srcHeight, ImageFormat::RGBA32F(), 0, tmp, ImageFormat::RGB8(), 0, invertY, bayerAlg);
    rgb8_to_bayer_bggr8(srcWidth, srcHeight, static_cast<uint8*>(tmp[0]), static_cast<uint8*>(dstBytes[0]));

    System::free(tmp[0]);
}

// BAYER -> RGB color space

// =====================================================================
// bayer --> rgb8 helpers
// =====================================================================
static void bayer_rggb8_to_rgb8_mhc(int w, int h, 
				    const uint8* in, uint8* _out) {
    debugAssert(in != _out);

    Color3uint8* out = (Color3uint8*)_out;

    for (int y = 0; y < h; ++y) {

	// Row beginning in the input array.
	int offset = y * w;

	// RG row
	for (int x = 0; x < w; ++x, ++out) {
	    // R pixel
	    {
		out->r = in[x + offset];
		out->g = applyFilter(in, x, y, w, h, G_GRR);
		out->b = applyFilter(in, x, y, w, h, B_GRR);
	    }
	    ++x; ++out;

	    // G pixel
	    {
		out->r = applyFilter(in, x, y, w, h, R_GRG);
		out->g = in[x + offset];
		out->b = applyFilter(in, x, y, w, h, B_GRG);
	    }
	}

	++y;
	offset += w;

	// GB row
	for (int x = 0; x < w; ++x, ++out) {
	    // G pixel
	    {
		out->r = applyFilter(in, x, y, w, h, R_BGG);
		out->g = in[x + offset];
		out->b = applyFilter(in, x, y, w, h, B_BGG);
	    }
	    ++x; ++out;

	    // B pixel
	    {
		out->r = applyFilter(in, x, y, w, h, R_BGB);
		out->g = applyFilter(in, x, y, w, h, G_BGB);
		out->b = in[x + offset];
	    }
	}
    }
}



static void bayer_gbrg8_to_rgb8_mhc(int w, int h, 
				    const uint8* in, uint8* _out) {

    debugAssert(in != _out);

    Color3uint8* out = (Color3uint8*)_out;

    for (int y = 0; y < h; ++y) {

	// Row beginning in the input array.
	int offset = y * w;

	// GB row
	for (int x = 0; x < w; ++x, ++out) {
	    // G pixel
	    {
		out->r = applyFilter(in, x, y, w, h, R_BGG);
		out->g = in[x + offset];
		out->b = applyFilter(in, x, y, w, h, B_BGG);
	    }
	    ++x; ++out;

	    // B pixel
	    {
		out->r = applyFilter(in, x, y, w, h, R_BGB);
		out->g = applyFilter(in, x, y, w, h, G_BGB);
		out->b = in[x + offset];
	    }
	}
    }
}


static void bayer_grbg8_to_rgb8_mhc(int w, int h, 
				    const uint8* in, uint8* _out) {
    // Run the equivalent function for red
    bayer_gbrg8_to_rgb8_mhc(w, h, in, _out);

    // Now swap red and blue
    swapRedAndBlue(w * h, (Color3uint8*)_out);
}


static void bayer_bggr8_to_rgb8_mhc(int w, int h, 
				    const uint8* in, uint8* _out) {
    // Run the equivalent function for red
    bayer_rggb8_to_rgb8_mhc(w, h, in, _out);

    // Now swap red and blue
    swapRedAndBlue(w * h, (Color3uint8*)_out);
}

// =====================================================================
// bayer (--> rgb8) --> rgba32f converter implementations
// =====================================================================
static void bayer_rggb8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    bayer_rggb8_to_rgb8_mhc(srcWidth, srcHeight, static_cast<const uint8*>(srcBytes[0]), static_cast<uint8*>(tmp[0]));
    rgb8_to_rgba32f(reinterpret_cast<Array<const void*>&>(tmp), srcWidth, srcHeight, ImageFormat::RGB8(), 0, dstBytes, ImageFormat::RGBA32F(), 0, invertY, bayerAlg);

    System::free(tmp[0]);
}

static void bayer_gbrg8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    bayer_grbg8_to_rgb8_mhc(srcWidth, srcHeight, static_cast<const uint8*>(srcBytes[0]), static_cast<uint8*>(tmp[0]));
    rgb8_to_rgba32f(reinterpret_cast<Array<const void*>&>(tmp), srcWidth, srcHeight, ImageFormat::RGB8(), 0, dstBytes, ImageFormat::RGBA32F(), 0, invertY, bayerAlg);

    System::free(tmp[0]);
}

static void bayer_grbg8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    bayer_gbrg8_to_rgb8_mhc(srcWidth, srcHeight, static_cast<const uint8*>(srcBytes[0]), static_cast<uint8*>(tmp[0]));
    rgb8_to_rgba32f(reinterpret_cast<Array<const void*>&>(tmp), srcWidth, srcHeight, ImageFormat::RGB8(), 0, dstBytes, ImageFormat::RGBA32F(), 0, invertY, bayerAlg);

    System::free(tmp[0]);
}

static void bayer_bggr8_to_rgba32f(const Array<const void*>& srcBytes, int srcWidth, int srcHeight, const ImageFormat* srcFormat, int srcRowPadBits, const Array<void*>& dstBytes, const ImageFormat* dstFormat, int dstRowPadBits, bool invertY, ImageFormat::BayerAlgorithm bayerAlg) {
    Array<void*> tmp;
    tmp.append(System::malloc(srcWidth * srcHeight * sizeof(Color3uint8)));

    bayer_bggr8_to_rgb8_mhc(srcWidth, srcHeight, static_cast<const uint8*>(srcBytes[0]), static_cast<uint8*>(tmp[0]));
    rgb8_to_rgba32f(reinterpret_cast<Array<const void*>&>(tmp), srcWidth, srcHeight, ImageFormat::RGB8(), 0, dstBytes, ImageFormat::RGBA32F(), 0, invertY, bayerAlg);

    System::free(tmp[0]);
}





    // TODO: The following region is commented out because so far
    // those conversions are not used anywhere else. Until it is
    // decided that such conversions are not needed, this region
    // remains commented out.


// // =====================================================================
// // bayer --> bgr8 
// // =====================================================================

// static void bayer_rggb8_to_bgr8_mhc(int w, int h, 
// 				    const uint8* in, uint8* _out) {
//     debugAssert(in != _out);

//     Color3uint8* out = (Color3uint8*)_out;

//     for (int y = 0; y < h; ++y) {

// 	// Row beginning in the input array.
// 	int offset = y * w;

// 	// RG row
// 	for (int x = 0; x < w; ++x, ++out) {
// 	    // R pixel
// 	    {
// 		out->b = in[x + offset];
// 		out->g = applyFilter(in, x, y, w, h, G_GRR);
// 		out->r = applyFilter(in, x, y, w, h, B_GRR);
// 	    }
// 	    ++x; ++out;

// 	    // G pixel
// 	    {
// 		out->b = applyFilter(in, x, y, w, h, R_GRG);
// 		out->g = in[x + offset];
// 		out->r = applyFilter(in, x, y, w, h, B_GRG);
// 	    }
// 	}

// 	++y;
// 	offset += w;

// 	// GB row
// 	for (int x = 0; x < w; ++x, ++out) {
// 	    // G pixel
// 	    {
// 		out->b = applyFilter(in, x, y, w, h, R_BGG);
// 		out->g = in[x + offset];
// 		out->r = applyFilter(in, x, y, w, h, B_BGG);
// 	    }
// 	    ++x; ++out;

// 	    // B pixel
// 	    {
// 		out->b = applyFilter(in, x, y, w, h, R_BGB);
// 		out->g = applyFilter(in, x, y, w, h, G_BGB);
// 		out->r = in[x + offset];
// 	    }
// 	}
//     }
// }


// static void bayer_gbrg8_to_bgr8_mhc(int w, int h, 
// 				    const uint8* in, uint8* _out) {

//     debugAssert(in != _out);

//     Color3uint8* out = (Color3uint8*)_out;

//     for (int y = 0; y < h; ++y) {

// 	// Row beginning in the input array.
// 	int offset = y * w;

// 	// GB row
// 	for (int x = 0; x < srcWidth; ++x, ++out) {
// 	    // G pixel
// 	    {
// 		out->b = applyFilter(in, x, y, w, h, R_BGG);
// 		out->g = in[x + offset];
// 		out->r = applyFilter(in, x, y, w, h, B_BGG);
// 	    }
// 	    ++x; ++out;

// 	    // B pixel
// 	    {
// 		out->b = applyFilter(in, x, y, w, h, R_BGB);
// 		out->g = applyFilter(in, x, y, w, h, G_BGB);
// 		out->r = in[x + offset];
// 	    }
// 	}
//     }
// }

// static void bayer_grbg8_to_bgr8_mhc(int w, int h, 
// 				    const uint8* in, uint8* _out) {
//     // Run the equivalent function for red
//     bayer_gbrg8_to_bgr8_mhc(w, h, in, _out);

//     // Now swap red and blue
//     swapRedAndBlue(srcWidth * h, (Color3uint8*)_out);
// }

// static void bayer_bggr8_to_bgr8_mhc(int w, int h, 
// 				    const uint8* in, uint8* _out) {
//     // Run the equivalent function for red
//     bayer_rggb8_to_bgr8_mhc(w, h, in, _out);

//     // Now swap red and blue
//     swapRedAndBlue(srcWidth * h, (Color3uint8*)_out);
// }



///////////////////////////////////////////////////

} // namespace G3D
