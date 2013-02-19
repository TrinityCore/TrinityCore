/**
  @file GImage_bmp.cpp
  @author Morgan McGuire, http://graphics.cs.williams.edu
  @created 2002-05-27
  @edited  2006-05-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Log.h"

namespace G3D {

#ifndef G3D_WIN32
/**
 This is used by the Windows bitmap I/O.
 */
static const int BI_RGB = 0;
#endif

void GImage::encodeBMP(
    BinaryOutput&       out) const {

    debugAssert(m_channels == 1 || m_channels == 3);
    out.setEndian(G3D_LITTLE_ENDIAN);

    uint8 red;
    uint8 green;
    uint8 blue;
    int pixelBufferSize = m_width * m_height * 3;
    int fileHeaderSize = 14;
    int infoHeaderSize = 40;
    int BMScanWidth;
    int BMPadding;

    // First write the BITMAPFILEHEADER
    //
    //  WORD    bfType; 
    //  DWORD   bfSize; 
    //  WORD    bfReserved1; 
    //  WORD    bfReserved2; 
    //  DWORD   bfOffBits; 

    // Type
    out.writeUInt8('B');
    out.writeUInt8('M');

    // File size
    out.writeUInt32(fileHeaderSize + infoHeaderSize + pixelBufferSize);

    // Two reserved fields set to zero
    out.writeUInt16(0);
    out.writeUInt16(0);

	// The offset, in bytes, from the BITMAPFILEHEADER structure
    // to the bitmap bits.
    out.writeUInt32(infoHeaderSize + fileHeaderSize);

    // Now the BITMAPINFOHEADER
    //
    //  DWORD  biSize; 
    //  LONG   biWidth; 
    //  LONG   biHeight; 
    //  WORD   biPlanes; 
    //  WORD   biBitCount 
    //  DWORD  biCompression; 
    //  DWORD  biSizeImage; 
    //  LONG   biXPelsPerMeter; 
    //  LONG   biYPelsPerMeter; 
    //  DWORD  biClrUsed; 
    //  DWORD  biClrImportant; 

    // Size of the info header
    out.writeUInt32(infoHeaderSize);
 
    // Width and height of the image
	out.writeUInt32(m_width);
    out.writeUInt32(m_height);

    // Planes ("must be set to 1")
    out.writeUInt16(1);

    // BitCount and CompressionType
    out.writeUInt16(24);
    out.writeUInt32(BI_RGB);

    // Image size ("may be zero for BI_RGB bitmaps")
    out.writeUInt32(0);

    // biXPelsPerMeter
    out.writeUInt32(0);
    // biYPelsPerMeter
    out.writeUInt32(0);

    // biClrUsed
    out.writeUInt32(0); 

    // biClrImportant
    out.writeUInt32(0); 
    
    BMScanWidth = m_width * 3;

    if (BMScanWidth & 3) {
        BMPadding = 4 - (BMScanWidth & 3);
    } else {
        BMPadding = 0;
    }

    int hStart = m_height - 1;
    int hEnd   = -1;
    int hDir   = -1;
    int dest;

    // Write the pixel data
    for (int h = hStart; h != hEnd; h += hDir) {
        dest = m_channels * h * m_width;
        for (int w = 0; w < m_width; ++w) {

            if (m_channels == 3) {
                red   = m_byte[dest];
                green = m_byte[dest + 1];
                blue  = m_byte[dest + 2];
            } else {
                red   = m_byte[dest];
                green = m_byte[dest];
                blue  = m_byte[dest];
            }

            out.writeUInt8(blue);
            out.writeUInt8(green);
            out.writeUInt8(red);

            dest += m_channels;
        }

        if (BMPadding > 0) {
            out.skip(BMPadding);
        }
    }
}


void GImage::decodeBMP(
    BinaryInput&            input) {

    // The BMP decoding uses these flags.
    static const uint16 PICTURE_NONE               = 0x0000;
    static const uint16 PICTURE_BITMAP             = 0x1000;

    // Compression Flags
    static const uint16 PICTURE_UNCOMPRESSED       = 0x0100;
    static const uint16 PICTURE_MONOCHROME         = 0x0001;
    static const uint16 PICTURE_4BIT               = 0x0002;
    static const uint16 PICTURE_8BIT               = 0x0004;
    static const uint16 PICTURE_16BIT              = 0x0008;
    static const uint16 PICTURE_24BIT              = 0x0010;
    static const uint16 PICTURE_32BIT              = 0x0020;

    (void)PICTURE_16BIT;
    (void)PICTURE_32BIT;

    // This is a simple BMP loader that can handle uncompressed BMP files.
    // Verify this is a BMP file by looking for the BM tag.
    input.reset();
    std::string tag = input.readString(2);
    if (tag != "BM") {
        throw Error("Not a BMP file", input.getFilename());
    }

    m_channels = 3;
	// Skip to the BITMAPINFOHEADER's width and height
	input.skip(16);

    m_width  = input.readUInt32();
    m_height = input.readUInt32();

	// Skip to the bit count and compression type
	input.skip(2);

    uint16 bitCount        = input.readUInt16();
    uint32 compressionType = input.readUInt32();

    uint8 red;
    uint8 green;
    uint8 blue;
    uint8 blank;

	// Only uncompressed bitmaps are supported by this code
    if ((int32)compressionType != BI_RGB) {
        throw Error("BMP images must be uncompressed", input.getFilename());
    }

    uint8* palette = NULL;

	// Create the palette if needed
    if (bitCount <= 8) {

        // Skip to the palette color count in the header
        input.skip(12);

        int numColors = input.readUInt32();

        palette = (uint8*)System::malloc(numColors * 3);
        debugAssert(palette);

        // Skip past the end of the header to the palette info
        input.skip(4);

        int c;
        for(c = 0; c < numColors * 3; c += 3) {
            // Palette information in bitmaps is stored in BGR_ format.
            // That means it's blue-green-red-blank, for each entry.
            blue  = input.readUInt8();
            green = input.readUInt8();
            red   = input.readUInt8();
            blank = input.readUInt8();

            palette[c]     = red;
            palette[c + 1] = green;
            palette[c + 2] = blue;
        }
	}

    int hStart = 0;
    int hEnd   = 0;
    int hDir   = 0;

    if (m_height < 0) {
        m_height = -m_height;
        hStart = 0;
        hEnd   = m_height;
        hDir   = 1;
    } else {
        //height = height;
        hStart = m_height - 1;
        hEnd   = -1;
        hDir   = -1;
    }

    m_byte = (uint8*)m_memMan->alloc(m_width * m_height * 3);
    debugAssert(m_byte);

    int BMScanWidth;
    int BMPadding;
    uint8 BMGroup;
    uint8 BMPixel8;
    int currPixel;
    int dest;
    int flags = PICTURE_NONE;

    if (bitCount == 1) {
        // Note that this file is not necessarily grayscale, since it's possible
        // the palette is blue-and-white, or whatever. But of course most image
        // programs only write 1-bit images if they're black-and-white.
        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_MONOCHROME;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = (m_width + 7) >> 3;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        // Powers of 2
        int pow2[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * m_width;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMGroup = input.readUInt8();

                // Now we read the pixels. Usually there are eight pixels per byte,
                // since each pixel is represented by one bit, but if the width
                // is not a multiple of eight, the last byte will have some bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "width" number of pixels.
                for (int i = 7; i >= 0; --i) {
                    if (currPixel < m_width) {
                        int src  = 3 * ((BMGroup & pow2[i]) >> i);
                    
                        m_byte[dest]     = palette[src];
                        m_byte[dest + 1] = palette[src + 1];
                        m_byte[dest + 2] = palette[src + 2];
                    
                        ++currPixel;
                        dest += 3;
                    }
                }
            }
        }

	} else if (bitCount == 4) {

        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_4BIT;

        // For bitmaps, each scanline is dword-aligned.
        int BMScanWidth = (m_width + 1) >> 1;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * m_width;

            for (int w = 0; w < BMScanWidth; w++) {

                BMGroup = input.readUInt8();
                int src[2];
                src[0] = 3 * ((BMGroup & 0xF0) >> 4);
                src[1] = 3 * (BMGroup & 0x0F);

                // Now we read the pixels. Usually there are two pixels per byte,
                // since each pixel is represented by four bits, but if the width
                // is not a multiple of two, the last byte will have only four bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "Width" number of pixels.

                for (int i = 0; i < 2; ++i) {
                    if (currPixel < m_width) {
                        int tsrc  = src[i];
                    
                        m_byte[dest]     = palette[tsrc];
                        m_byte[dest + 1] = palette[tsrc + 1];
                        m_byte[dest + 2] = palette[tsrc + 2];

                        ++currPixel;
                        dest += 3;
                    }
                }
            }
        }

	} else if (bitCount == 8) {
        
        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_8BIT;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = m_width;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMPixel8 = input.readUInt8();

                if (currPixel < m_width) {
                    dest = 3 * ((h * m_width) + currPixel);
                    int src  = 3 * BMPixel8;
                    
                    m_byte[dest]     = palette[src];
                    m_byte[dest + 1] = palette[src + 1];
                    m_byte[dest + 2] = palette[src + 2];
                    
                    ++currPixel;
                }
            }
        }

    } else if (bitCount == 16) {

        m_memMan->free(m_byte);
        m_byte = NULL;
        System::free(palette); 
        palette = NULL;
    	throw Error("16-bit bitmaps not supported", input.getFilename());

	} else if (bitCount == 24) {
        input.skip(20);

        flags = PICTURE_BITMAP | PICTURE_UNCOMPRESSED | PICTURE_24BIT;

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = m_width * 3;

        if (BMScanWidth & 3) {
            BMPadding = 4 - (BMScanWidth & 3);
        } else {
            BMPadding = 0;
        }

        for (int h = hStart; h != hEnd; h += hDir) {
            dest = 3 * h * m_width;
            for (int w = 0; w < m_width; ++w) {

                blue  = input.readUInt8();
                green = input.readUInt8();
                red   = input.readUInt8();

                m_byte[dest]     = red;
                m_byte[dest + 1] = green;
                m_byte[dest + 2] = blue;

                dest += 3;
            }

            if (BMPadding) {
                input.skip(2);
            }
        }

	} else if (bitCount == 32) {

        m_memMan->free(m_byte);
        m_byte = NULL;
        System::free(palette); 
        palette = NULL;
    	throw Error("32 bit bitmaps not supported", input.getFilename());
    
    } else {
        // We support all possible bit depths, so if the
        //     code gets here, it's not even a real bitmap.
        m_memMan->free(m_byte);
        m_byte = NULL;
        throw Error("Not a bitmap!", input.getFilename());
	}

    System::free(palette); 
    palette = NULL;
}


void GImage::decodeICO(
    BinaryInput&            input) {

	// Header
	uint16 r = input.readUInt16();
	debugAssert(r == 0);
	r = input.readUInt16();
	debugAssert(r == 1);

	// Read the number of icons, although we'll only load the
	// first one.
	int count = input.readUInt16();

	m_channels = 4;

	debugAssert(count > 0);

    const uint8* headerBuffer = input.getCArray() + input.getPosition();
    int maxWidth = 0, maxHeight = 0;
    int maxHeaderNum = 0;
    for (int currentHeader = 0; currentHeader < count; ++currentHeader) {
        
        const uint8* curHeaderBuffer = headerBuffer + (currentHeader * 16);
        int tmpWidth = curHeaderBuffer[0];
        int tmpHeight = curHeaderBuffer[1];
        // Just in case there is a non-square icon, checking area
        if ((tmpWidth * tmpHeight) > (maxWidth * maxHeight)) {
            maxWidth = tmpWidth;
            maxHeight = tmpHeight;
            maxHeaderNum = currentHeader;
        }
    }

    input.skip(maxHeaderNum * 16);

    m_width = input.readUInt8();
    m_height = input.readUInt8();
    int numColors = input.readUInt8();
	
    m_byte = (uint8*)m_memMan->alloc(m_width * m_height * m_channels);
    debugAssert(m_byte);

    // Bit mask for packed bits
    int mask = 0;
    
    int bitsPerPixel = 8;
    
    switch (numColors) {
    case 2:
        mask      = 0x01;
        bitsPerPixel = 1;
        break;
        
    case 16:
        mask      = 0x0F;
        bitsPerPixel = 4;
        break;
        
    case 0:
        numColors = 256;
        mask      = 0xFF;
        bitsPerPixel = 8;
        break;

    default:
    	throw Error("Unsupported ICO color count.", input.getFilename());
    }

    input.skip(5);
    // Skip 'size' unused
    input.skip(4);
    
    int offset = input.readUInt32();
    
    // Skip over any other icon descriptions
    input.setPosition(offset);
    
    // Skip over bitmap header; it is redundant
    input.skip(40);
    
    Array<Color4uint8> palette;
    palette.resize(numColors, true);
    for (int c = 0; c < numColors; ++c) {
        palette[c].b = input.readUInt8();
        palette[c].g = input.readUInt8();
        palette[c].r = input.readUInt8();
        palette[c].a = input.readUInt8();
    }

	// The actual image and mask follow

	// The XOR Bitmap is stored as 1-bit, 4-bit or 8-bit uncompressed Bitmap 
	// using the same encoding as BMP files. The AND Bitmap is stored in as 
	// 1-bit uncompressed Bitmap.
	// 
	// Pixels are stored bottom-up, left-to-right. Pixel lines are padded 
	// with zeros to end on a 32bit (4byte) boundary. Every line will have the 
	// same number of bytes. Color indices are zero based, meaning a pixel color 
	// of 0 represents the first color table entry, a pixel color of 255 (if there
	// are that many) represents the 256th entry.
/*
	int bitsPerRow  = width * bitsPerPixel;
	int bytesPerRow = iCeil((double)bitsPerRow / 8);
	// Rows are padded to 32-bit boundaries
	bytesPerRow += bytesPerRow % 4;

	// Read the XOR values into the color channel
	for (int y = height - 1; y >= 0; --y) {
		int x = 0;
		// Read the row
		for (int i = 0; i < bytesPerRow; ++i) {
			uint8 byte = input.readUInt8();
			for (int j = 0; (j < 8) && (x < width); ++x, j += bitsPerPixel) {
				int bit = ((byte << j) >> (8 - bitsPerPixel)) & mask;
				pixel4(x, y) = colorTable[bit];
			}
		}
	}
*/
    int hStart = 0;
    int hEnd   = 0;
    int hDir   = 0;

    if (m_height < 0) {
        m_height = -m_height;
        hStart = 0;
        hEnd   = m_height;
        hDir   = 1;
    } else {
        //height = height;
        hStart = m_height - 1;
        hEnd   = -1;
        hDir   = -1;
    }

    int BMScanWidth;
    uint8 BMGroup;
    uint8 BMPixel8;
    int currPixel;
    int dest;

    if (bitsPerPixel == 1) {
        // Note that this file is not necessarily grayscale, since it's possible
        // the palette is blue-and-white, or whatever. But of course most image
        // programs only write 1-bit images if they're black-and-white.

        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = (m_width + 7) >> 3;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        // Powers of 2
        int pow2[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 3 * h * m_width;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMGroup = input.readUInt8();

                // Now we read the pixels. Usually there are eight pixels per byte,
                // since each pixel is represented by one bit, but if the width
                // is not a multiple of eight, the last byte will have some bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "width" number of pixels.
                for (int i = 7; i >= 0; --i) {
                    if (currPixel < m_width) {
                        int src  = ((BMGroup & pow2[i]) >> i);
                    
                        m_byte[dest]     = palette[src].r;
                        m_byte[dest + 1] = palette[src].g;
                        m_byte[dest + 2] = palette[src].b;
                    
                        ++currPixel;
                        dest += 4;
                    }
                }
            }
        }

	} else if (bitsPerPixel == 4) {

        // For bitmaps, each scanline is dword-aligned.
        int BMScanWidth = (m_width + 1) >> 1;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;
            dest = 4 * h * m_width;

            for (int w = 0; w < BMScanWidth; w++) {

                BMGroup = input.readUInt8();
                int src[2];
                src[0] = ((BMGroup & 0xF0) >> 4);
                src[1] = (BMGroup & 0x0F);

                // Now we read the pixels. Usually there are two pixels per byte,
                // since each pixel is represented by four bits, but if the width
                // is not a multiple of two, the last byte will have only four bits
                // set, with the others just being extra. Plus there's the
                // dword-alignment padding. So we keep checking to see if we've
                // already read "Width" number of pixels.

                for (int i = 0; i < 2; ++i) {
                    if (currPixel < m_width) {
                        int tsrc  = src[i];
                    
                        m_byte[dest]     = palette[tsrc].r;
                        m_byte[dest + 1] = palette[tsrc].g;
                        m_byte[dest + 2] = palette[tsrc].b;

                        ++currPixel;
                        dest += 4;
                    }
                }
            }
        }

	} else if (bitsPerPixel == 8) {
        
        // For bitmaps, each scanline is dword-aligned.
        BMScanWidth = m_width;
        if (BMScanWidth & 3) {
            BMScanWidth += 4 - (BMScanWidth & 3);
        }

        for (int h = hStart; h != hEnd; h += hDir) {

            currPixel = 0;

            for (int w = 0; w < BMScanWidth; ++w) {

                BMPixel8 = input.readUInt8();

                if (currPixel < m_width) {
                    dest = 4 * ((h * m_width) + currPixel);
                    int src  = BMPixel8;
                    
                    m_byte[dest]     = palette[src].r;
                    m_byte[dest + 1] = palette[src].g;
                    m_byte[dest + 2] = palette[src].b;
                    
                    ++currPixel;
                }
            }
        }
    }

	// Read the mask into the alpha channel
	int bitsPerRow  = m_width;
	int bytesPerRow = iCeil((double)bitsPerRow / 8);

    // For bitmaps, each scanline is dword-aligned.
    //BMScanWidth = (width + 1) >> 1;
    if (bytesPerRow & 3) {
        bytesPerRow += 4 - (bytesPerRow & 3);
    }
    
    for (int y = m_height - 1; y >= 0; --y) {
		int x = 0;
		// Read the row
		for (int i = 0; i < bytesPerRow; ++i) {
			uint8 byte = input.readUInt8();
			for (int j = 0; (j < 8) && (x < m_width); ++x, ++j) {
				int bit = (byte >> (7 - j)) & 0x01;
				pixel4(x, y).a = (1 - bit) * 0xFF;
			}
		}
	}

}


}
