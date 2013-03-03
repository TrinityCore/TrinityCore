// -*- C++ -*-
//=============================================================================
/**
 *  @file   RLECompressor.h
 *
 *  $Id: RLECompressor.h
 *
 *  @author TAO version by
 *  @author Derek Dominish <derek.dominish@dsto.defence.gov.au>
 *  @author ACE version by
 *  @author Derek Dominish <derek.dominish@dsto.defence.gov.au>
 *
 *  Run-length encoding (RLE) is a very simple form of data compression
 *  in which runs of data (that is, sequences in which the same data value
 *  occurs in many consecutive data elements) are stored as a single data
 *  value and count, rather than as the original run. This is most useful
 *  on data that contains many such runs: for example, simple graphic
 *  images such as icons, line drawings, and animations. It is not useful
 *  with files that don't have many runs as it could slightly increase the
 *  output size.
 *  ALGORITHM: This algorithm is an optimized version of the traditional
 *  RLE algorithm in that it behaves better with very few runs.
 *
 *  With a run of a character where that run is >= 3 this is
 *  replaced with the repeat indicator 0X80 and then the repeat count OR'd
 *  over this ident.  This repeat count is therefore has a maximum value
 *  of 127 (0x7F) which is to be interpreted as the next character repeated
 *  another 'repeat count' times (i.e. a maximum of 128 characters can be
 *  represented in any single dupal). if the repeat ident is not present
 *  then the count is to be interpreted as a copy of the next repeat count
 *  characters + 1.
 *
 *  EXAMPLE: the following arbitary string of 67 bytes:-
 *  WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW
 *  will produce (as a HEXDUMP) of 14 bytes
 *  8B 57 00 42 8B 57 82 42  97 57 00 42 8D 57        .W.B.W.B.W.B.W
 */
//=============================================================================

#ifndef ACE_RLECOMPRESSOR_H
#define ACE_RLECOMPRESSOR_H

#include /**/ "ace/pre.h"

#include "ACE_RLECompression_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Compression/Compressor.h"
#include "ace/Singleton.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_RLECompression_Export ACE_RLECompressor : public ACE_Compressor
{
public:
  /**
  * Default constructor. Should use instance() to get global instance.
  */
  ACE_RLECompressor(void);

  virtual ~ACE_RLECompressor(void);

  /**
  * Compress the @a in_ptr buffer for @a in_len into the
  * @a dest_ptr buffer with a maximum @a max_out_len using
  * the Run Length Ecoding (RLE) algorithm. If the
  * @a max_out_len is exhausted through the compress process
  * then a value of -1 will be returned from the function,
  * otherwise the return value will indicate the resultant
  * @a out_ptr compressed buffer length.
  *
  * @note It is advisable that the @max_out_len be slightly
  * larger of the input @a in_len (i.e. x 1.1F) to cater
  * for the possibility that a reduced compressed length
  * is not possible.
  */
  virtual ACE_UINT64 compress( const void *in_ptr,
                                ACE_UINT64 in_len,
                                void *out_ptr,
                                ACE_UINT64 max_out_len );

  /**
  * DeCompress the @a in_ptr buffer for @a in_len into the
  * @a out_ptr buffer with a maximum @a max_out_len using
  * the Run Length Ecoding (RLE) algorithm. If the
  * @a max_out_len is exhausted during decompression
  * then a value of -1 will be returned from the function,
  * otherwise the return value will indicate the resultant
  * @a out_ptr decompressed buffer length.
  */
  virtual ACE_UINT64 decompress( const void *in_ptr,
                                  ACE_UINT64 in_len,
                                  void *out_ptr,
                                  ACE_UINT64 max_out_len );
};

ACE_RLECOMPRESSION_SINGLETON_DECLARE(ACE_Singleton, ACE_RLECompressor, ACE_SYNCH_MUTEX);

typedef class ACE_Singleton<ACE_RLECompressor, ACE_SYNCH_MUTEX> ACE_RLECompression;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif // ACE_RLECOMPRESSOR_H
