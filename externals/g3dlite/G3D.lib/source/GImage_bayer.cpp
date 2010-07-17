/**
  @file GImage_bayer.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"

namespace G3D {

void GImage::BAYER_G8B8_R8G8_to_Quarter_R8G8B8(int width, int height, const uint8* in, uint8* out) {
    debugAssert(in != out);

    int halfHeight = height / 2;
    int halfWidth  = width / 2;

    int dst_off = 0;
    for (int y = 0; y < halfHeight; ++y) {
        for (int x = 0; x < halfWidth; ++x) {
            // GBRG
            int src_off = x*2 + y*2*width;
            out[dst_off] = in[src_off+width]; // red
            out[dst_off+1] = ((int)in[src_off] + (int)in[src_off+width+1])/2; // green
            out[dst_off+2] = in[src_off+1]; // blue            

            dst_off = dst_off + 3;
        }
    }
}


void GImage::Quarter_R8G8B8_to_BAYER_G8B8_R8G8(int inWidth, int inHeight, const uint8* in, uint8* out) {
    // Undo quarter-size Bayer as best we can.  This code isn't very efficient, but it
    // also isn't used very frequently.

    debugAssert(out != in);

    int outWidth  = 2 * inWidth;
    int outHeight = 2 * inHeight;

    for (int y = 0; y < outHeight; ++y) {
        for (int x = 0; x < outWidth; ++x) {
            const Color3uint8* inp = ((const Color3uint8*)in) + ((x/2) + (y/2)* inWidth);
            uint8* outp = out + x + y * outWidth;

            if (isEven(y)) {
                // GB row
                if (isEven(x)) {
                    // Green
                    *outp = inp->g;
                } else {
                    // Blue
                    *outp = inp->b;
                }
            } else {
                // RG row
                if (isEven(x)) {
                    // Red
                    *outp = inp->r;
                } else {
                    // Green
                    *outp = inp->g;
                }
            }
        }
    }
}


/** Applies a 5x5 filter to monochrome image I (wrapping at the boundaries) */
static uint8 applyFilter(
    const uint8*    I,
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


void GImage::BAYER_R8G8_G8B8_to_R8G8B8_MHC(int w, int h, const uint8* in, uint8* _out) {
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

static void swapRedAndBlue(int N, Color3uint8* out) {
    for (int i = N - 1; i >= 0; --i) {
        uint8 tmp = out[i].r;
        out[i].r = out[i].b;
        out[i].b = tmp;
    }
}

void GImage::BAYER_G8R8_B8G8_to_R8G8B8_MHC(int w, int h, const uint8* in, uint8* _out) {
    // Run the equivalent function for red
    BAYER_G8B8_R8G8_to_R8G8B8_MHC(w, h, in, _out);

    // Now swap red and blue
    swapRedAndBlue(w * h, (Color3uint8*)_out);
}


void GImage::BAYER_B8G8_G8R8_to_R8G8B8_MHC(int w, int h, const uint8* in, uint8* _out) {
    // Run the equivalent function for red
    BAYER_R8G8_G8B8_to_R8G8B8_MHC(w, h, in, _out);

    // Now swap red and blue
    swapRedAndBlue(w * h, (Color3uint8*)_out);
}


void GImage::BAYER_G8B8_R8G8_to_R8G8B8_MHC(int w, int h, const uint8* in, uint8* _out) {

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

        ++y;
        offset += w;

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
    }

}

#undef B_BGG
#undef B_GRG
#undef B_GRR

}
