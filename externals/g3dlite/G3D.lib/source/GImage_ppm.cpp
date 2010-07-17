/**
  @file GImage_ppm.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/Log.h"

namespace G3D {

void GImage::encodePPMASCII(
    BinaryOutput&       out) const {

    debugAssert(channels == 3);

    TextOutput::Settings ppmOptions;
    ppmOptions.convertNewlines = false;
    ppmOptions.numColumns = 70;
    ppmOptions.wordWrap = TextOutput::Settings::WRAP_WITHOUT_BREAKING;
    TextOutput ppm(ppmOptions);
    // Always write out a full-color ppm
    ppm.printf("P3\n%d %d\n255\n", width, height);
    
    const Color3uint8* c = this->pixel3();
    for (uint32 i = 0; i < (uint32)(width * height); ++i) {
        ppm.printf("%d %d %d%c", c[i].r, c[i].g, c[i].b, 
            ((i % ((width * 3) - 1)) == 0) ?
            '\n' : ' '); 
    }

    out.writeString(ppm.commitString());
}


void GImage::encodePPM(
    BinaryOutput&       out) const {

    // http://netpbm.sourceforge.net/doc/ppm.html
    debugAssert(channels == 3);

    std::string header = format("P6 %d %d 255 ", width, height);

    out.writeBytes(header.c_str(), header.size());

    out.writeBytes(this->pixel3(), width * height * 3);
}

void GImage::decodePPMASCII(
    BinaryInput&        input) {

    int ppmWidth;
    int ppmHeight;

    double maxColor;

    // Create a TextInput object to parse ascii format
    // Mixed binary/ascii formats will require more 

    const std::string inputStr = input.readString();

    TextInput::Settings ppmOptions;
    ppmOptions.cppComments = false;
    ppmOptions.otherCommentCharacter = '#';
    ppmOptions.signedNumbers = true;
    ppmOptions.singleQuotedStrings = false;

    TextInput ppmInput(TextInput::FROM_STRING, inputStr, ppmOptions);

    //Skip first line in header P#
    std::string ppmType = ppmInput.readSymbol();

    ppmWidth = (int)ppmInput.readNumber();
    ppmHeight = (int)ppmInput.readNumber();

    // Everything but a PBM will have a max color value
    if (ppmType != "P2") {
        maxColor = ppmInput.readNumber();
    } else {
        maxColor = 255;
    }

    if ((ppmWidth < 0) ||
        (ppmHeight < 0) ||
        (maxColor <= 0)) {
        throw GImage::Error("Invalid PPM Header.", input.getFilename());
    }

    // I don't think it's proper to scale values less than 255
    if (maxColor <= 255.0) {
        maxColor = 255.0;
    }

    this->width = ppmWidth;
    this->height = ppmHeight;
    this->channels = 3;
    // always scale down to 1 byte per channel
    this->_byte = (uint8*)System::malloc(width * height * 3);

    // Read in the image data.  I am not validating if the values match the maxColor
    // requirements.  I only scale if needed to fit within the byte available.
    for (uint32 i = 0; i < (uint32)(width * height); ++i) {
        // read in color and scale to max pixel defined in header
        // A max color less than 255 might need to be left alone and not scaled.
        Color3uint8& curPixel = *(this->pixel3() + i);

        if (ppmType == "P3") {
            curPixel.r = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.g = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.b = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
        } else if (ppmType == "P2") {
            uint8 pixel = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.r = pixel;
            curPixel.g = pixel;
            curPixel.b = pixel;
        } else if (ppmType == "P1") {
            int pixel = (uint8)(ppmInput.readNumber() * maxColor);
            curPixel.r = pixel;
            curPixel.g = pixel;
            curPixel.b = pixel;
        }
    }
}

/** Consumes whitespace up to and including a number, but not the following character */
static int scanUInt(BinaryInput& input) {
    char c = input.readUInt8();
    while (isWhiteSpace(c)) {
        c = input.readUInt8();
    }

    std::string s;
    s += c;
    c = input.readUInt8();
    while (!isWhiteSpace(c)) {
        s += c;
        c = input.readUInt8();
    }

    // Back up one to avoid consuming the last character
    input.setPosition(input.getPosition() - 1);

    int x;
    sscanf(s.c_str(), "%d", &x);
    return x;
}

void GImage::decodePPM(
    BinaryInput&        input) {

    char head[2];
    int w, h;

    input.readBytes(head, 2);
    if (head[0] != 'P' || head[1] != '6') {
        throw GImage::Error("Invalid PPM Header.", input.getFilename());
    }

    w = scanUInt(input);
    h = scanUInt(input);

    // Skip the max color specifier
    scanUInt(input);

    if ((w < 0) ||
        (h < 0) ||
        (w > 100000) ||
        (h > 100000)) {
        throw GImage::Error("Invalid PPM size in header.", input.getFilename());
    }

    // Trailing whitespace
    input.readUInt8();

    resize(w, h, 3);

    input.readBytes(_byte, width * height * 3);
}

}
