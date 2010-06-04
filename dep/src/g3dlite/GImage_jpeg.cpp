/**
  @file GImage_jpeg.cpp
  @author Morgan McGuire, http://graphics.cs.williams.edu
  @created 2002-05-27
  @edited  2009-04-20
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

#include <cstring>

extern "C" { 
#ifdef G3D_LINUX
#   include <jconfig.h>
#   include <jpeglib.h>
#else
#   include "jconfig.h"
#   include "jpeglib.h"
#endif
}

namespace G3D {


const int jpegQuality = 96;

/**
 The IJG library needs special setup for compress/decompressing
 from memory.  These classes provide them.  
 
 The format of this class is defined by the IJG library; do not
 change it.
 */ 
class memory_destination_mgr {
public:
	struct jpeg_destination_mgr pub;
	JOCTET*                     buffer;
	int                         size;
	int                         count;
};

typedef memory_destination_mgr* mem_dest_ptr;

/**
 Signature dictated by IJG.
 */
static void init_destination (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;

	dest->pub.next_output_byte = dest->buffer;
	dest->pub.free_in_buffer = dest->size;
	dest->count=0;
}

/**
 Signature dictated by IJG.
 */
static boolean empty_output_buffer (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;

	dest->pub.next_output_byte = dest->buffer;
	dest->pub.free_in_buffer = dest->size;

	return TRUE;
}

/**
 Signature dictated by IJG.
 */
static void term_destination (
    j_compress_ptr              cinfo) {

	mem_dest_ptr dest = (mem_dest_ptr) cinfo->dest;
	dest->count = dest->size - dest->pub.free_in_buffer;
}

/**
 Signature dictated by IJG.
 */
static void jpeg_memory_dest (
    j_compress_ptr              cinfo,
    JOCTET*                     buffer,
    int                         size) {

	mem_dest_ptr dest;

	if (cinfo->dest == NULL) {
        // First time for this JPEG object; call the
        // IJG allocator to get space.
		cinfo->dest = (struct jpeg_destination_mgr*)
			(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, 
                                        JPOOL_PERMANENT,
                       				    sizeof(memory_destination_mgr));
	}

	dest                            = (mem_dest_ptr) cinfo->dest;
	dest->size                      = size;
	dest->buffer                    = buffer;
	dest->pub.init_destination      = init_destination;
	dest->pub.empty_output_buffer   = empty_output_buffer;
	dest->pub.term_destination      = term_destination;
}
  
////////////////////////////////////////////////////////////////////////////////////////

#define INPUT_BUF_SIZE  4096

/**
 Structure dictated by IJG.
 */
class memory_source_mgr {
public:
    struct jpeg_source_mgr  pub;
	int                     source_size;
	unsigned char*          source_data;
	boolean                 start_of_data;
	JOCTET*                 buffer;
};


typedef memory_source_mgr* mem_src_ptr;


/**
 Signature dictated by IJG.
 */
static void init_source(
    j_decompress_ptr        cinfo) {

    mem_src_ptr src = (mem_src_ptr) cinfo->src;

    src->start_of_data = TRUE;
}


/**
 Signature dictated by IJG.
 */
static boolean fill_input_buffer(
    j_decompress_ptr        cinfo) {

	mem_src_ptr src = (mem_src_ptr) cinfo->src;

	size_t bytes_read = 0;

	if (src->source_size > INPUT_BUF_SIZE)
		bytes_read = INPUT_BUF_SIZE;
	else
		bytes_read = src->source_size;

	memcpy (src->buffer, src->source_data, bytes_read);

	src->source_data += bytes_read;
	src->source_size -= bytes_read;

	src->pub.next_input_byte = src->buffer;
	src->pub.bytes_in_buffer = bytes_read;
	src->start_of_data = FALSE;


	return TRUE;
}


/**
 Signature dictated by IJG.
 */
static void skip_input_data(
    j_decompress_ptr        cinfo,
    long                    num_bytes) {

	mem_src_ptr src = (mem_src_ptr)cinfo->src;

	if (num_bytes > 0) {
		while (num_bytes > (long) src->pub.bytes_in_buffer) {
			num_bytes -= (long) src->pub.bytes_in_buffer;
			boolean s = fill_input_buffer(cinfo);
            debugAssert(s); (void)s;
		}

		src->pub.next_input_byte += (size_t) num_bytes;
		src->pub.bytes_in_buffer -= (size_t) num_bytes;
	}
}


/**
 Signature dictated by IJG.
 */
static void term_source (
    j_decompress_ptr        cinfo) {
    (void)cinfo;
	// Intentionally empty
}


/**
 Signature dictated by IJG.
 */
static void jpeg_memory_src (
    j_decompress_ptr        cinfo,
    JOCTET*                 buffer,
    int                     size) {

	mem_src_ptr src;

	if (cinfo->src == NULL) {
        // First time for this JPEG object
		cinfo->src = (struct jpeg_source_mgr*)
			(*cinfo->mem->alloc_small)(
                (j_common_ptr) cinfo,
                JPOOL_PERMANENT,
				sizeof(memory_source_mgr));
		
        src = (mem_src_ptr)cinfo->src;
		
        src->buffer = (JOCTET*)
			(*cinfo->mem->alloc_small)(
                (j_common_ptr) cinfo,
                JPOOL_PERMANENT,
				INPUT_BUF_SIZE * sizeof(JOCTET));
	}

	src = (mem_src_ptr)cinfo->src;
	src->pub.init_source        = init_source;
	src->pub.fill_input_buffer  = fill_input_buffer;
	src->pub.skip_input_data    = skip_input_data;

    // use default method
	src->pub.resync_to_restart  = jpeg_resync_to_restart;
	src->pub.term_source        = term_source;
	src->source_data            = buffer;
	src->source_size            = size;

    // forces fill_input_buffer on first read
	src->pub.bytes_in_buffer    = 0;
    
    // until buffer loaded
    src->pub.next_input_byte = NULL; 
}


void GImage::encodeJPEG(
    BinaryOutput&           out) const {

	if (m_channels != 3) {
		// Convert to three channel
		GImage tmp = *this;
		tmp.convertToRGB();
		tmp.encodeJPEG(out);
		return;
	}

    debugAssert(m_channels == 3);
    out.setEndian(G3D_LITTLE_ENDIAN);

    // Allocate and initialize a compression object
    jpeg_compress_struct    cinfo;
    jpeg_error_mgr          jerr;

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

    // Specify the destination for the compressed data.
    // (Overestimate the size)
    int buffer_size = m_width * m_height * 3 + 200;
    JOCTET* compressed_data = (JOCTET*)System::malloc(buffer_size);
	jpeg_memory_dest(&cinfo, compressed_data, buffer_size);


    cinfo.image_width       = m_width;
    cinfo.image_height      = m_height;

	// # of color components per pixel
    cinfo.input_components  = 3;

    // colorspace of input image
    cinfo.in_color_space    = JCS_RGB; 
    cinfo.input_gamma       = 1.0;
    
    // Set parameters for compression, including image size & colorspace
    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, jpegQuality, false);
    cinfo.smoothing_factor = 0;
    cinfo.optimize_coding = TRUE;
//    cinfo.dct_method = JDCT_FLOAT;
    cinfo.dct_method = JDCT_ISLOW;
    cinfo.jpeg_color_space = JCS_YCbCr;

    // Initialize the compressor
    jpeg_start_compress(&cinfo, TRUE);

    // Iterate over all scanlines from top to bottom
	// pointer to a single row
    JSAMPROW row_pointer[1];
    
    // JSAMPLEs per row in image_buffer
    int row_stride = cinfo.image_width * 3;
    while (cinfo.next_scanline < cinfo.image_height) {
	    row_pointer[0] = &(m_byte[cinfo.next_scanline * row_stride]);
	    jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    // Shut down the compressor
    jpeg_finish_compress(&cinfo);
    
    // Figure out how big the result was.
    int outLength = ((mem_dest_ptr)cinfo.dest)->count;

    //	Release the JPEG compression object
    jpeg_destroy_compress(&cinfo);

    // Copy into an appropriately sized output buffer.
    out.writeBytes(compressed_data, outLength);

    // Free the conservative buffer.
    System::free(compressed_data);
    compressed_data = NULL;
}


void GImage::decodeJPEG(
    BinaryInput&                input) {

	struct jpeg_decompress_struct   cinfo;
	struct jpeg_error_mgr           jerr;
    int                             loc = 0;

    m_channels = 3;
    // We have to set up the error handler, in case initialization fails.
	cinfo.err = jpeg_std_error(&jerr);

    // Initialize the JPEG decompression object.
	jpeg_create_decompress(&cinfo);

	// Specify data source (eg, a file, for us, memory)
	jpeg_memory_src(&cinfo, const_cast<uint8*>(input.getCArray()), input.size());

	// Read the parameters with jpeg_read_header()
	jpeg_read_header(&cinfo, TRUE);

	// Set parameters for decompression
	// (We do nothing here since the defaults are fine)

	// Start decompressor
	jpeg_start_decompress(&cinfo);

	// Get and set the values of interest to this object
	m_width     = cinfo.output_width;
	m_height    = cinfo.output_height;

	// Prepare the pointer object for the pixel data
    m_byte = (uint8*)m_memMan->alloc(m_width * m_height * 3);

 	// JSAMPLEs per row in output buffer
    int bpp         = cinfo.output_components;
    int row_stride  = cinfo.output_width * bpp;

	// Make a one-row-high sample array that will go away when done with image
    JSAMPARRAY temp = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);

    // Read data on a scanline by scanline basis
	while (cinfo.output_scanline < cinfo.output_height) {

        // We may need to adjust the output based on the
        // number of channels it has.
        switch (bpp) {
	    case 1:
            // Grayscale; decompress to temp.
    		jpeg_read_scanlines(&cinfo, temp, 1);

            // Expand to three channels
            {
                uint8* scan     = &(m_byte[loc * 3]);
                uint8* endScan  = scan + (m_width * 3);
                uint8* t        = *temp;

                while (scan < endScan) {
                    uint8 value = t[0];

                    // Spread the value 3x.
                    scan[0] = value;
                    scan[1] = value;
                    scan[2] = value;

                    scan    += 3;
                    t       += 1;
                }
            }
		    break;

	    case 3:
            // Read directly into the array
            {
                // Need one extra level of indirection.
                uint8*     scan = m_byte + loc;
                JSAMPARRAY ptr  = &scan;
    		    jpeg_read_scanlines(&cinfo, ptr, 1);
            }
		    break;

	    case 4:
            // RGBA; decompress to temp.
    		jpeg_read_scanlines(&cinfo, temp, 1);

            // Drop the 3rd channel
            {
                uint8* scan     = &(m_byte[loc * 3]);
                uint8* endScan  = scan + m_width * 3;
                uint8* t        = *temp;

                while (scan < endScan) {
                    scan[0] = t[0];
                    scan[1] = t[1];
                    scan[2] = t[2];
                    
                    scan    += 3;
                    t       += 4;
                }
            }
		    break;

	    default:
		    throw Error("Unexpected number of channels.", input.getFilename());
	    }

		loc += row_stride;
	}

	// Finish decompression
	jpeg_finish_decompress(&cinfo);

    alwaysAssertM(this, "Corrupt GImage");
	// Release JPEG decompression object
	jpeg_destroy_decompress(&cinfo);
}


}
