// $Id: RLECompressor.cpp 95560 2012-02-27 08:11:54Z johnnyw $

#include "RLECompressor.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_RLECompressor::ACE_RLECompressor(void)
    : ACE_Compressor(ACE_COMPRESSORID_RLE)
{
}

ACE_RLECompressor::~ACE_RLECompressor(void)
{
}

ACE_UINT64
ACE_RLECompressor::compress( const void *in_ptr,
                             ACE_UINT64 in_len,
                             void *out_ptr,
                             ACE_UINT64 max_out_len )
{
    const ACE_UINT8 *in_p   = static_cast<const ACE_UINT8*>(in_ptr);
    ACE_UINT8 *out_p        = static_cast<ACE_UINT8*>(out_ptr);

    ACE_UINT64  src_len     = in_len;  // Save for stats
    ACE_UINT64  out_len     = 0;
    ACE_UINT64  out_index   = 0;
    ACE_UINT64  out_base    = 0;

    ACE_UINT32  run_count   = 0;
    ACE_UINT32  dup_count   = 0;

    bool        run_code    = false;

    ACE_UINT8   nxt_byte, cur_byte;

    if (in_p && out_p) while (in_len-- > 0) {

        if (run_code) switch (run_count) {

        default:

            out_p[out_index = out_base] = ACE_UINT8(run_count++ | 0x80);
            out_p[++out_index] = cur_byte = *in_p++;

            if (in_len ? cur_byte == (nxt_byte = *in_p) : true) {
                continue;
            }

            // Fall Through

        case 128:

            if (++out_index >= max_out_len) {
                return ACE_UINT64(-1); // Output Exhausted
            } else if (in_len == 0) {
                continue;
            }

            run_code  = false;
            out_p[out_base = out_index] = 0;
            dup_count = run_count = 0;
            continue;
        }

        switch (run_count) {

        case 128:

            if (++out_index >= max_out_len) {
                return ACE_UINT64(-1); // Output Exhausted
            }
            out_p[out_base = out_index] = 0;
            dup_count = run_count = 0;

            // Fall Through

        default :

            cur_byte = *in_p++;

            if (in_len > 0) {
                if (cur_byte == (nxt_byte = *in_p)) {
                    if (dup_count++ == 1) {
                        if (run_count >= dup_count) {
                            out_p[out_base] = static_cast<ACE_UINT8>(run_count - dup_count);
                            out_base += run_count;
                        }
                        run_code  = true;
                        run_count = dup_count - 1;
                        dup_count = 0;
                        out_p[out_index = out_base] = static_cast<ACE_UINT8>(run_count++ | 0x80);
                        break;
                    }
                } else dup_count = 0;
            }
            out_p[out_base] = char(run_count++);
            break;
        }

        if (++out_index >= max_out_len) {
            return ACE_UINT64(-1); // Output Exhausted
        }

        out_p[out_index] = cur_byte;
    }

    out_len = ++out_index;  // Update our output length

    this->update_stats(src_len, out_len);

    return out_len;
}

// Decompress using Run Length Encoding (RLE)
ACE_UINT64
ACE_RLECompressor::decompress( const void *in_ptr,
                               ACE_UINT64 in_len,
                               void *out_ptr,
                               ACE_UINT64 max_out_len )
{
    ACE_UINT64  out_len     = 0;

    const ACE_UINT8 *in_p   = static_cast<const ACE_UINT8*>(in_ptr);
    ACE_UINT8 *out_p        = static_cast<ACE_UINT8*>(out_ptr);

    if (in_p && out_p) while(in_len-- > 0) {

        ACE_UINT8   cur_byte    = *in_p++;
        ACE_UINT32  cpy_len     = ACE_UINT32((cur_byte & 0x7F) + 1);

        if (cpy_len > max_out_len) {
            return ACE_UINT64(-1); // Output Exhausted
        } else if ((cur_byte & 0x80) != 0) {  // compressed
            if (in_len-- > 0) {
                ACE_OS::memset(out_p, *in_p++, cpy_len);
            } else {
                return ACE_UINT64(-1); // Output Exhausted
            }
        } else if (in_len >= cpy_len) {
            ACE_OS::memcpy(out_p, in_p, cpy_len);
            in_p    += cpy_len;
            in_len  -= cpy_len;
        } else {
            return ACE_UINT64(-1); // Output Exhausted
        }

        out_p       += cpy_len;
        max_out_len -= cpy_len;
        out_len     += cpy_len;
    }

    return out_len;
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
