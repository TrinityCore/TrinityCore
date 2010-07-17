/**
  @file GImage.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  Copyright 2002-2007, Morgan McGuire

  @created 2002-05-27
  @edited  2006-10-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/debug.h"
#include "G3D/stringutils.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Log.h"
#include <png.h>
#include <sys/stat.h>
#include <assert.h>
#include <sys/types.h>

//////////////////////////////////////////////////////////////////////////////////////////////

namespace G3D {
   
void GImage::RGBtoRGBA(
    const uint8*    in,
    uint8*          out,
    int             numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = in[i3 + 0]; 
        out[i4 + 1] = in[i3 + 1]; 
        out[i4 + 2] = in[i3 + 2]; 
        out[i4 + 3] = 255; 
    }
}


void GImage::RGBAtoRGB(
    const uint8*    in,
    uint8*          out,
    int             numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i3 + 0] = in[i4 + 0]; 
        out[i3 + 1] = in[i4 + 1]; 
        out[i3 + 2] = in[i4 + 2]; 
    }
}


void GImage::RGBtoBGRA(
    const uint8*    in,
    uint8*          out,
    int                     numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 2] = in[i3 + 0]; 
        out[i4 + 1] = in[i3 + 1]; 
        out[i4 + 0] = in[i3 + 2]; 
        out[i4 + 3] = 255; 
    }
}



void GImage::RGBtoBGR(
    const uint8*    in,
    uint8*          out,
    int             numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;

        int r = in[i3 + 0];
        int g = in[i3 + 1];
        int b = in[i3 + 2];

        out[i3 + 2] = r; 
        out[i3 + 1] = g; 
        out[i3 + 0] = b;
    }
}


void GImage::RGBxRGBtoRGBA(
    const uint8*            colorRGB,
    const uint8*            alphaRGB,
    uint8*                  out,
    int                     numPixels) {

    for (int i = numPixels - 1; i >= 0; --i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = colorRGB[i3 + 0];
        out[i4 + 1] = colorRGB[i3 + 1];
        out[i4 + 2] = colorRGB[i3 + 2];
        out[i4 + 3] = alphaRGB[i3 + 0];
    }
}


void GImage::RGBtoARGB(
    const uint8*            in,
    uint8*                  out,
    int                     numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = 255; 
        out[i4 + 1] = in[i3 + 0]; 
        out[i4 + 2] = in[i3 + 1]; 
        out[i4 + 3] = in[i3 + 2];
    }
}


void GImage::flipRGBVertical(
    const uint8*            in,
    uint8*                  out,
    int                     width,
    int                     height) {

    
    // Allocate a temp row so the operation
    // is still safe if in == out
    uint8* temp = (uint8*)System::malloc(width * 3);
    alwaysAssertM(temp != NULL, "Out of memory"); 

    int oneRow = width * 3;
    int N = height / 2;

    // if height is an odd value, don't swap odd middle row
    for (int i = 0; i < N; ++i) {
        int topOff = i * oneRow;
        int botOff = (height - i - 1) * oneRow;
        System::memcpy(temp,         in + topOff, oneRow);
        System::memcpy(out + topOff, in + botOff, oneRow);
        System::memcpy(out + botOff, temp,        oneRow);
    }

    System::free(temp);
}


void GImage::flipRGBAVertical(
    const uint8*            in,
    uint8*                  out,
    int                     width,
    int                     height) {

    
    // Allocate a temp row so the operation
    // is still safe if in == out
    uint8* temp = (uint8*)System::malloc(width * 4);
    alwaysAssertM(temp != NULL, "Out of memory");

    int oneRow = width * 4;

    // if height is an odd value, don't swap odd middle row
    for (int i = 0; i < height / 2; ++i) {
        int topOff = i * oneRow;
        int botOff = (height - i - 1) * oneRow;
        System::memcpy(temp,         in + topOff, oneRow);
        System::memcpy(out + topOff, in + botOff, oneRow);
        System::memcpy(out + botOff, temp,        oneRow);
    }

    System::free(temp);
}

////////////////////////////////////////////////////////////////////////////////////////

void GImage::decode(
    BinaryInput&        input,
    Format              format) {

    switch (format) {
    case PPM_ASCII:
        decodePPMASCII(input);
        break;

    case PPM:
        decodePPM(input);
        break;

    case PNG:
        decodePNG(input);
        break;

    case JPEG:
        decodeJPEG(input);
        break;

    case TGA:
        decodeTGA(input);
        break;

    case BMP:
        decodeBMP(input);
        break;

    case ICO:
        decodeICO(input);
        break;

    case PCX:
        decodePCX(input);
        break;

    default:
        debugAssert(false);
    }

    debugAssert(width >= 0);
    debugAssert(height >= 0);
    debugAssert(channels == 1 || channels == 3 || channels == 4);
    debugAssert(_byte != NULL);
}


void GImage::decodePCX(
    BinaryInput&                input) {

    uint8  manufacturer = input.readUInt8();
    uint8  version      = input.readUInt8();
    uint8  encoding     = input.readUInt8();
    uint8  bitsPerPixel = input.readUInt8();

    uint16 xmin         = input.readUInt16();
    uint16 ymin         = input.readUInt16();
    uint16 xmax         = input.readUInt16();
    uint16 ymax         = input.readUInt16();

    uint16 horizDPI     = input.readUInt16();
    uint16 vertDPI      = input.readUInt16();

    Color3uint8 colorMap[16];
    input.readBytes(colorMap, 48);

    input.skip(1);

    uint8  planes       = input.readUInt8();
    uint16 bytesPerLine = input.readUInt16();
    uint16 paletteType  = input.readUInt16();
    input.skip(4 + 54);

    (void)bytesPerLine;

    width  = xmax - xmin + 1;
    height = ymax - ymin + 1;
    channels = 3;

    if ((manufacturer != 0x0A) || (encoding != 0x01)) {
        throw GImage::Error("PCX file is corrupted", input.getFilename());
    }

    (void)version;
    (void)vertDPI;
    (void)horizDPI;

    if ((bitsPerPixel != 8) || ((planes != 1) && (planes != 3))) {
        throw GImage::Error("Only 8-bit paletted and 24-bit PCX files supported.", input.getFilename());
    }

	// Prepare the pointer object for the pixel data
    _byte = (uint8*)System::malloc(width * height * 3);

    if ((paletteType == 1) && (planes == 3)) {

        Color3uint8* pixel = pixel3();

        // Iterate over each scan line
        for (int row = 0; row < height; ++row) {
            // Read each scan line once per plane
            for (int plane = 0; plane < planes; ++plane) {
                int p = row * width;
                int p1 = p + width;
                while (p < p1) {
                    uint8 value = input.readUInt8();
                    int length = 1;
            
                    if (value >= 192) {
                        // This is the length, not the value.  Mask off
                        // the two high bits and read the true index.
                        length = value & 0x3F;
                        value = input.readUInt8();
                    }

                    // Set the whole run
                    for (int i = length - 1; i >= 0; --i, ++p) {
                        debugAssert(p < width * height);
                        pixel[p][plane] = value;
                    }
                }
            }
        }

    } else if (planes == 1) {

        Color3uint8 palette[256];

        int imageBeginning   = input.getPosition();
        int paletteBeginning = input.getLength() - 769;

        input.setPosition(paletteBeginning);

        uint8 dummy = input.readUInt8();

        if (dummy != 12) {
            Log::common()->println("\n*********************");
            Log::common()->printf("Warning: Corrupted PCX file (palette marker byte was missing) \"%s\"\nLoading anyway\n\n", input.getFilename().c_str());
        }

        input.readBytes(palette, sizeof(palette));
        input.setPosition(imageBeginning);
        
        Color3uint8* pixel = pixel3();
        
        // The palette indices are run length encoded.
        int p = 0;
        while (p < width * height) {
            uint8 index  = input.readUInt8();
            uint8 length = 1;

            if (index >= 192) {
                // This is the length, not the index.  Mask off
                // the two high bits and read the true index.
                length = index & 0x3F;
                index  = input.readUInt8();
            }

            Color3uint8 color = palette[index];

            // Set the whole run
            for (int i = length - 1; i >= 0; --i, ++p) {
                if (p > width * height) {
                    break;
                }
                pixel[p] = color;
            }

        }

    } else {
        throw GImage::Error("Unsupported PCX file type.", input.getFilename());
    }
}


GImage::Format GImage::resolveFormat(const std::string&  filename) {
    BinaryInput b(filename, G3D_LITTLE_ENDIAN);
    if (b.size() <= 0) {
        throw Error("File not found.", filename);
    }

    return resolveFormat(filename, b.getCArray(), b.size(), AUTODETECT);
}


GImage::Format GImage::resolveFormat(
    const std::string&  filename,
    const uint8*        data,
    int                 dataLen,
    Format              maybeFormat) {

    // Return the provided format if it is specified.
    if (maybeFormat != AUTODETECT) {
        return maybeFormat;
    }

    std::string extension;

    // Try to detect from the filename's extension
    if (filename.size() >= 5) {
        int n = iMax(filename.size() - 1, 5);
        // Search backwards for the "."
        for (int i = 1; i <= n; ++i) {
            if (filename[filename.size() - i] == '.') {
                // Upper case
                extension = toUpper(filename.substr(filename.size() - i + 1));
                break;
            }
        }
    }

    if (extension == "PPM") {
        // There are two PPM formats; we handle them differently
        if (dataLen > 3) {
            if (!memcmp(data, "P6", 2)) {
                return PPM;
            } else {
                return PPM_ASCII;
            }
        }
    }

    Format tmp = stringToFormat(extension);
    if ((tmp != AUTODETECT) && (tmp != UNKNOWN)) {
        return tmp;
    }

    // Try and autodetect from the file itself by looking at the first
    // character.

    // We can't look at the character if it is null.
    debugAssert(data != NULL);              

    if ((dataLen > 3) && (!memcmp(data, "P3", 2) || !memcmp(data, "P2", 2) || !memcmp(data, "P1", 2))) {
        return PPM_ASCII;
    }

    if ((dataLen > 3) && !memcmp(data, "P6", 2)) {
        return PPM;
    }

    if (dataLen > 8) {
        if (!png_sig_cmp((png_bytep)data, 0, 8))
            return PNG;
    }

    if ((dataLen > 0) && (data[0] == 'B')) {
        return BMP;
    }

    if (dataLen > 10) {
        if ((dataLen > 11) && (data[0] == 0xFF) &&
            (memcmp(&data[6], "JFIF", 4) == 0)) {
            return JPEG;
        }
    }

    if (dataLen > 40) {
        if (memcmp(&data[dataLen - 18], "TRUEVISION-XFILE", 16) == 0) {
            return TGA;
        }
    }

    if ((dataLen > 4) && (data[0] == 0) && (data[1] == 0) && (data[2] == 0) && (data[3] == 1)) {
        return ICO;
    }

    if ((dataLen > 0) && (data[0] == 10)) {
        return PCX;
    }

    return UNKNOWN;
}


GImage::GImage(
    const std::string&  filename,
    Format              format) : 
    _byte(NULL), 
    width(0),
    height(0), 
    channels(0){
    
    load(filename, format);
}


void GImage::load(
    const std::string&  filename,
    Format              format) {

    clear();

    try {
        BinaryInput b(filename, G3D_LITTLE_ENDIAN);
        if (b.size() <= 0) {
            throw Error("File not found.", filename);
        }

        alwaysAssertM(this != NULL, "Corrupt GImage");
        decode(b, resolveFormat(filename, b.getCArray(), b.size(), format));
    } catch (const std::string& error) {
        throw Error(error, filename);
    }
}


GImage::GImage(
    const uint8*        data,
    int                 length,
    Format              format) {

    BinaryInput b(data, length, G3D_LITTLE_ENDIAN);
    // It is safe to cast away the const because we
    // know we don't corrupt the data.

    decode(b, resolveFormat("", data, length, format));
}


GImage::GImage(
    int                 width,
    int                 height,
    int                 channels) {
    
    _byte = NULL;
    resize(width, height, channels);
}


void GImage::resize(
    int                 width,
    int                 height,
    int                 channels) {
    debugAssert(width >= 0);
    debugAssert(height >= 0);
    debugAssert(channels >= 1);

    clear();

    this->width = width;
    this->height = height;
    this->channels = channels;
    size_t sz = width * height * channels;

    _byte = (uint8*)System::calloc(sz, sizeof(uint8));
    debugAssert(isValidHeapPointer(_byte));
}


void GImage::_copy(
    const GImage&       other) {

    clear();

    width  = other.width;
    height = other.height;
    channels = other.channels;
    int s  = width * height * channels * sizeof(uint8);
    _byte  = (uint8*)System::malloc(s);
    debugAssert(isValidHeapPointer(_byte));
    memcpy(_byte, other._byte, s);
}


GImage::GImage(
    const GImage&        other) : _byte(NULL) {

    _copy(other);
}


GImage::~GImage() {
    clear();
}


void GImage::clear() {
    width = 0;
    height = 0;
    System::free(_byte);
    _byte = NULL;
}


GImage& GImage::operator=(const GImage& other) {
    _copy(other);
    return *this;
}


bool GImage::copySubImage(
    GImage & dest, const GImage & src,
    int srcX, int srcY, int srcWidth, int srcHeight) {
    if ((src.width < srcX + srcWidth) ||
        (src.height < srcY + srcHeight) ||
        (srcY < 0) ||
        (srcX < 0)) {

        return false;
    }

    dest.resize(srcWidth, srcHeight, src.channels);
    
    bool ret;
    ret = pasteSubImage(dest, src, 0, 0, srcX, srcY, srcWidth, srcHeight);
    debugAssert(ret);

    return true;
}


bool GImage::pasteSubImage(
    GImage & dest, const GImage & src,
    int destX, int destY,
    int srcX, int srcY, int srcWidth, int srcHeight) {
    if ((src.width < srcX + srcWidth) ||
        (src.height < srcY + srcHeight) ||
        (dest.width < destX + srcWidth) ||
        (dest.height < destY + srcHeight) ||
        (srcY < 0) ||
        (srcX < 0) ||
        (destY < 0) ||
        (destX < 0) ||
        (src.channels != dest.channels)) {

        return false;
    }

    for (int i = 0; i < srcHeight; i++) {
        const uint8* srcRow = src.byte() +
            ((i + srcY) * src.width + srcX) * src.channels;
        uint8* destRow = dest.byte() +
            ((i + destY) * dest.width + destX) * dest.channels;
        memcpy(destRow, srcRow, srcWidth * src.channels);
    }

    return true;
}


bool GImage::supportedFormat(
    const std::string& format) {

    return (stringToFormat(format) != UNKNOWN);
}


GImage::Format GImage::stringToFormat(
    const std::string& format) {

    std::string extension = toUpper(format);

    if ((extension == "JPG") || (extension == "JPEG")) {
        return JPEG;
    } else if (extension == "TGA") {
        return TGA;
    } else if (extension == "BMP") {
        return BMP;
    } else if (extension == "PCX") {
        return PCX;
    } else if (extension == "ICO") {
        return ICO;
    } else if (extension == "PNG") {
        return PNG;
    } else if (extension == "PPM") {
        return PPM;
    } else {
        return UNKNOWN;
    }
}


void GImage::save(
    const std::string& filename,
    Format             format) const {

    BinaryOutput b(filename, G3D_LITTLE_ENDIAN);
    encode(resolveFormat(filename, NULL, 0, format), b);
    b.commit(false);
}


void GImage::encode(
    Format              format,
    uint8*&             outData,
    int&                outLength) const {

    BinaryOutput out;

    encode(format, out);

    outData = (uint8*)System::malloc(out.size());
    debugAssert(outData);
    outLength = out.size();

    out.commit(outData);
}


void GImage::encode(
    Format              format,
    BinaryOutput&       out) const {

    switch (format) {
    case PPM_ASCII:
        encodePPMASCII(out);
        break;

    case PPM:
        encodePPM(out);
        break;

    case PNG:
        encodePNG(out);
        break;

    case JPEG:
        encodeJPEG(out);
        break;

    case BMP:
        encodeBMP(out);
        break;

    case TGA:
        encodeTGA(out);
        break;

    default:
        debugAssert(false);
    }
}

void GImage::insertRedAsAlpha(const GImage& alpha, GImage& output) const {
    debugAssert(alpha.width == width);
    debugAssert(alpha.height == height);

    // make sure output GImage is valid
    if (output.width != width || output.height != height || output.channels != 4) {
        output.resize(width, height, 4);
    }

    for (int i = 0; i < width * height; ++i) {
        output.byte()[i * 4 + 0] = byte()[i * channels + 0];
        output.byte()[i * 4 + 1] = byte()[i * channels + 1];
        output.byte()[i * 4 + 2] = byte()[i * channels + 2];
        output.byte()[i * 4 + 3] = alpha.byte()[i * alpha.channels];
    }
}

GImage GImage::insertRedAsAlpha(const GImage& alpha) const {
    debugAssert(alpha.width == width);
    debugAssert(alpha.height == height);

    GImage out(width, height, 4);

    insertRedAsAlpha(alpha, out);

    return out;
}


void GImage::stripAlpha(GImage& output) const {

    if (output.width != width || output.height != height || output.channels != 3)
    {
        output.resize(width, height, 3);
    }

    for (int i = 0; i < width * height; ++i) {
        output.byte()[i * 3 + 0] = byte()[i * channels + 0];
        output.byte()[i * 3 + 1] = byte()[i * channels + 1];
        output.byte()[i * 3 + 2] = byte()[i * channels + 2];
    }
}

GImage GImage::stripAlpha() const {
    GImage out(width, height, 3);

    stripAlpha(out);

    return out;
}


int GImage::sizeInMemory() const {
    return sizeof(GImage) + width * height * channels;
}


void GImage::computeNormalMap(
    const GImage&       bump,
    GImage&             normal,
    float               whiteHeightInPixels,
    bool                lowPassBump,
    bool                scaleHeightByNz) {
    computeNormalMap(bump.width, bump.height, bump.channels, bump.byte(), normal, whiteHeightInPixels, lowPassBump, scaleHeightByNz);
}

void GImage::computeNormalMap(
    int                 width,
    int                 height,
    int                 channels,
    const uint8*        src,
    GImage&             normal,
    float               whiteHeightInPixels,
    bool                lowPassBump,
    bool                scaleHeightByNz) {

    if (whiteHeightInPixels == -1.0f) {
        // Default setting scales so that a gradient ramp
        // over the whole image becomes a 45-degree angle
        
        // Account for potentially non-square aspect ratios
        whiteHeightInPixels = max(width, height);
    }

    debugAssert(whiteHeightInPixels >= 0);

    const int w = width;
    const int h = height;
    const int stride = channels;

    normal.resize(w, h, 4);

    const uint8* const B = src;
    Color4uint8* const N = normal.pixel4();

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            // Index into normal map pixel
            int i = x + y * w;

            // Index into bump map *byte*
            int j = stride * i;

            Vector3 delta;

            // Get a value from B (with wrapping lookup) relative to (x, y)
            // and divide by 255
            #define height(DX, DY)  ((int)B[(((DX + x + w) % w) + \
                                            ((DY + y + h) % h) * w) * stride])


            // Sobel filter to compute the normal.  
            //
            // Y Filter (X filter is the transpose)
            //  [ -1 -2 -1 ]
            //  [  0  0  0 ]
            //  [  1  2  1 ]

            // Write the Y value directly into the x-component so we don't have
            // to explicitly compute a cross product at the end.
            delta.y = -(height(-1, -1) *  1 + height( 0, -1) *  2 + height( 1, -1) *  1 +
                        height(-1,  1) * -1 + height( 0,  1) * -2 + height( 1,  1) * -1);

            delta.x = -(height(-1, -1) * -1 + height( 1, -1) * 1 + 
                        height(-1,  0) * -2 + height( 1,  0) * 2 + 
                        height(-1,  1) * -1 + height( 1,  1) * 1);

            // The scale of each filter row is 4, the filter width is two pixels,
            // and the "normal" range is 0-255.
            delta.z = 4 * 2 * (whiteHeightInPixels / 255.0f);

            // Delta is now scaled in pixels; normalize 
            delta = delta.direction();

            // Copy over the bump value into the alpha channel.
            float H = B[j] / 255.0;

            if (lowPassBump) {
                H = (height(-1, -1) + height( 0, -1) + height(1, -1) +
                        height(-1,  0) + height( 0,  0) + height(1,  0) +
                        height(-1,  1) + height( 0,  1) + height(1,  1)) / (255.0f * 9.0f);
            }
            #undef height

            if (scaleHeightByNz) {
                // delta.z can't possibly be negative, so we avoid actually
                // computing the absolute value.
                H *= delta.z;
            }

            N[i].a = iRound(H * 255.0);

            // Pack into byte range
            delta = delta * 127.5 + Vector3(127.5, 127.5, 127.5);
            N[i].r = iClamp(iRound(delta.x), 0, 255);
            N[i].g = iClamp(iRound(delta.y), 0, 255);
            N[i].b = iClamp(iRound(delta.z), 0, 255);
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GImage::convertToL8() {
    switch(channels) {
    case 1:
        return;

    case 3:
        {            
            // Average
            Color3uint8* src = (Color3uint8*)_byte;
            _byte = NULL;
            resize(width, height, 1);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color3uint8   s = src[i];
                uint8&              d = _byte[i]; 
                d = ((int)s.r + (int)s.g + (int)s.b) / 3;
            }
            System::free(src);
        }
        break;

    case 4:
        {            
            // Average
            Color4uint8* src = (Color4uint8*)_byte;
            _byte = NULL;
            resize(width, height, 1);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color4uint8   s = src[i];
                uint8&              d = _byte[i]; 
                d = ((int)s.r + (int)s.g + (int)s.b) / 3;
            }
            System::free(src);
        }
        return;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::convertToRGBA() {
    switch(channels) {
    case 1:
        {            
            // Spread
            uint8* old = _byte;
            _byte = NULL;
            resize(width, height, 4);
            for (int i = width * height - 1; i >= 0; --i) {
                const uint8  s = old[i];
                Color4uint8& d = ((Color4uint8*)_byte)[i]; 
                d.r = d.g = d.b = s;
                d.a = 255;
            }
            System::free(_byte);
        }
        break;

    case 3:
        {            
            // Add alpha
            Color3uint8* old = (Color3uint8*)_byte;
            _byte = NULL;
            resize(width, height, 4);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color3uint8   s = old[i];
                Color4uint8&        d = ((Color4uint8*)_byte)[i]; 
                d.r = s.r;
                d.g = s.g;
                d.b = s.b;
                d.a = 255;
            }
            System::free(old);
        }
        break;

    case 4:
        // Already RGBA
        return;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::convertToRGB() {
    switch(channels) {
    case 1:
        {            
            // Spread
            uint8* old = _byte;
            _byte = NULL;
            resize(width, height, 3);
            for (int i = width * height - 1; i >= 0; --i) {
                const uint8  s = old[i];
                Color3uint8& d = ((Color3uint8*)_byte)[i]; 
                d.r = d.g = d.b = s;
            }
            System::free(old);
        }
        break;

    case 3:
		return;

    case 4:
		// Strip alpha
        {            
            Color4uint8* old = (Color4uint8*)_byte;
            _byte = NULL;
            resize(width, height, 3);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color4uint8   s = old[i];
                Color3uint8&        d = ((Color3uint8*)_byte)[i]; 
                d.r = s.r;
                d.g = s.g;
                d.b = s.b;
            }
            System::free(old);
        }
        break;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::R8G8B8_to_Y8U8V8(int width, int height, const uint8* _in, uint8* _out) {
    const Color3uint8* in = reinterpret_cast<const Color3uint8*>(_in);
    Color3uint8* out = reinterpret_cast<Color3uint8*>(_out);

    Color3uint8 p;
    for (int i = width * height - 1; i >= 0; --i) {
        p.r = iClamp(iRound(in->r *  0.229 + in->g *  0.587 + in->b *  0.114), 0, 255);
        p.g = iClamp(iRound(in->r * -0.147 + in->g * -0.289 + in->b *  0.436) + 127, 0, 255);
        p.b = iClamp(iRound(in->r *  0.615 + in->g * -0.515 + in->b * -0.100) + 127, 0, 255);
        *out = p;
        ++in;
        ++out;
    }
}



void GImage::Y8U8V8_to_R8G8B8(int width, int height, const uint8* _in, uint8* _out) {
    const Color3uint8* in = reinterpret_cast<const Color3uint8*>(_in);
    Color3uint8* out = reinterpret_cast<Color3uint8*>(_out);

    Color3uint8 p;
    for (int i = width * height - 1; i >= 0; --i) {
        p.r = iClamp(iRound(in->r *  1.0753 +                   (in->b - 127) *  1.2256), 0, 255);
        p.g = iClamp(iRound(in->r *  1.0753 + (in->g - 127) * -0.3946 + (in->b - 127) * -0.4947), 0, 255);
        p.b = iClamp(iRound(in->r *  1.0753 + (in->g - 127) *  2.0320 + (in->b - 127) *  0.0853), 0, 255);
        *out = p;
        ++in;
        ++out;
    }
}


void GImage::makeCheckerboard(GImage& im, int checkerSize, const Color4uint8& A, const Color4uint8& B) {
    for (int y = 0; y < im.height; ++y) {
        for (int x = 0; x < im.width; ++x) {
            bool checker = isOdd((x / checkerSize) + (y / checkerSize));
            const Color4uint8& color = checker ? A : B;
            for (int c = 0; c < im.channels; ++c) {
                uint8* v = im.byte() + (x + y * im.width) * im.channels + c;
                *v = color[c];
            }
        }
    }
}

}

