/**
  @file GImage_tga.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Log.h"

namespace G3D {

void GImage::encodeTGA(
    BinaryOutput&       out) const {

    out.setEndian(G3D_LITTLE_ENDIAN);

    // ID length
    out.writeUInt8(0);

    // Color map Type
    out.writeUInt8(0);

    // Type
    out.writeUInt8(2);

    // Color map
    out.skip(5);

    // x, y offsets
    out.writeUInt16(0);
    out.writeUInt16(0);

    // Width & height
    out.writeUInt16(width);
    out.writeUInt16(height);

    // Color depth
    out.writeUInt8(8 * channels);

    // Image descriptor
    if (channels == 3) {
        // 0 alpha bits
        out.writeUInt8(0);
    }
    else {
        // 8 alpha bits
        out.writeUInt8(8);
    }

    // Image ID (zero length)

    if (channels == 3) {
        // Pixels are upside down in BGR format.
        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                uint8* p = &(_byte[3 * (y * width + x)]);
                out.writeUInt8(p[2]);
                out.writeUInt8(p[1]);
                out.writeUInt8(p[0]);
            }
        }
    } else {
        // Pixels are upside down in BGRA format.
        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                uint8* p = &(_byte[4 * (y * width + x)]);
                out.writeUInt8(p[2]);
                out.writeUInt8(p[1]);
                out.writeUInt8(p[0]);
                out.writeUInt8(p[3]);
            }
        }
    }

    // Write "TRUEVISION-XFILE " 18 bytes from the end 
    // (with null termination)
    out.writeString("TRUEVISION-XFILE ");
}


void GImage::decodeTGA(
    BinaryInput&        input) {

    // This is a simple TGA loader that can handle uncompressed
    // truecolor TGA files (TGA type 2). 
    // Verify this is a TGA file by looking for the TRUEVISION tag.
    int pos = input.getPosition();
    input.setPosition(input.size() - 18);
    std::string tag = input.readString(16);
    if (tag != "TRUEVISION-XFILE") {
        throw Error("Not a TGA file", input.getFilename());
    }

    input.setPosition(pos);

    int IDLength     = input.readUInt8();
    int colorMapType = input.readUInt8();
    int imageType    = input.readUInt8();

    (void)colorMapType;
	
    // 2 is the type supported by this routine.
    if (imageType != 2) {
        throw Error("TGA images must be type 2 (Uncompressed truecolor)", input.getFilename());
    }
	
    // Color map specification
    input.skip(5);

    // Image specification

    // Skip x and y offsets
    input.skip(4); 

    width = input.readInt16();
    height = input.readInt16();

    int colorDepth = input.readUInt8();

    if ((colorDepth != 24) && (colorDepth != 32)) {
        throw Error("TGA files must be 24 or 32 bit.", input.getFilename());
    }

    if (colorDepth == 32) {
        channels = 4;
    } else {
        channels = 3;
    }

    // Image descriptor contains overlay data as well
    // as data indicating where the origin is
    int imageDescriptor = input.readUInt8();
    (void)imageDescriptor;
	
    // Image ID
    input.skip(IDLength);

    _byte = (uint8*)System::malloc(width * height * channels);
    debugAssert(_byte);
	
    // Pixel data
    int x;
    int y;

    if (channels == 3) {
        for (y = height - 1; y >= 0; y--) {
          for (x = 0; x < width; x++) {
            int b = input.readUInt8();
            int g = input.readUInt8();
            int r = input.readUInt8();
		    
            int i = (x + y * width) * 3;
            _byte[i + 0] = r;
            _byte[i + 1] = g;
            _byte[i + 2] = b;
          }
        }
    } else {
        for (y = height - 1; y >= 0; y--) {
          for (x = 0; x < width; x++) {
            int b = input.readUInt8();
            int g = input.readUInt8();
            int r = input.readUInt8();
            int a = input.readUInt8();
		    
            int i = (x + y * width) * 4;
            _byte[i + 0] = r;
            _byte[i + 1] = g;
            _byte[i + 2] = b;
            _byte[i + 3] = a;
          }
        }
    }
}

}
