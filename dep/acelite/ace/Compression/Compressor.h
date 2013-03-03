// -*- C++ -*-
//=============================================================================
/**
 *  @file   Compressor.h
 *
 *  $Id: Compressor.h
 *
 *  @author ACE version by
 *  @author Derek Dominish <derek.dominish@dsto.defence.gov.au>
 */
//=============================================================================

#ifndef ACE_COMPRESSOR_H
#define ACE_COMPRESSOR_H

#include /**/ "ace/pre.h"

#include /**/ "ACE_Compression_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Guard_T.h"
#include "ace/Thread_Mutex.h"
#include "ace/Synch_Traits.h"
#include "ace/Copy_Disabled.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * CompressorId from OMG Compression::CompressorId
 * see $(TAO_ROOT)/tao/Compression.pidl
 */
enum ACE_CompressorId
{
    ACE_COMPRESSORID_NONE   = 0,
    ACE_COMPRESSORID_GZIP   = 1,
    ACE_COMPRESSORID_PKZIP  = 2,
    ACE_COMPRESSORID_BZIP2  = 3,
    ACE_COMPRESSORID_ZLIB   = 4,
    ACE_COMPRESSORID_LZMA   = 5,
    ACE_COMPRESSORID_LZO    = 6,
    ACE_COMPRESSORID_RZIP   = 7,
    ACE_COMPRESSORID_7X     = 8,
    ACE_COMPRESSORID_XAR    = 9,
    ACE_COMPRESSORID_RLE    = 10
};

class ACE_Compression_Export ACE_Compressor : private ACE_Copy_Disabled
{
public:

  ACE_CompressorId    get_compressor_id(void) const;

  ACE_UINT32          get_compression_level(void) const;

  /**
    * Compress the @a in_ptr buffer for @a in_len into the
    * @a dest_ptr buffer with a maximum @a max_out_len. If the
    * @a max_out_len is exhausted through the compress process
    * then a value of -1 will be returned from the function,
    * otherwise the return value will indicate the resultant
    * @a out_ptr compressed buffer length.
    *
    * NOTE: it is advisable that the @max_out_len be slightly
    * larger of the input @a in_len (i.e. x 1.1F) to cater
    * for the possibility that a reduced compressed length
    * is not possible.
    */
  virtual ACE_UINT64 compress( const void *in_ptr,
                                ACE_UINT64 in_len,
                                void *out_ptr,
                                ACE_UINT64 max_out_len ) = 0;

  /**
    * DeCompress the @a in_ptr buffer for @a in_len into the
    * @a out_ptr buffer with a maximum @a max_out_len. If the
    * @a max_out_len is exhausted during decompression
    * then a value of -1 will be returned from the function,
    * otherwise the return value will indicate the resultant
    * @a out_ptr decompressed buffer length.
    */
  virtual ACE_UINT64 decompress( const void *in_ptr,
                                  ACE_UINT64 in_len,
                                  void *out_ptr,
                                  ACE_UINT64 max_out_len ) = 0;

  /**
    *  Return the current compressed bytes statistics counter.
    */
  virtual ACE_UINT64  compressed_bytes(void) const;

  /**
    *  Return the current uncompressed bytes statistics counter.
    */
  virtual ACE_UINT64  uncompressed_bytes(void) const;

  /**
    *  Return the current compression ratio statistics.
    */
  virtual float       compression_ratio(void) const;

  /**
    *  Reset the statistics to zero.
    */
  virtual void        reset_stats(void);

  virtual ~ACE_Compressor (void);

protected:
  ACE_Compressor(ACE_CompressorId compressor_id,
                  ACE_UINT32 compression_level = 0); // Must be inherited.

  virtual void update_stats(  ACE_UINT64 uncompressed_bytes,
                              ACE_UINT64 compressed_bytes );

private:
  ACE_CompressorId    compressor_id_;
  ACE_UINT32          compression_level_;

  // Ensure we can lock with imutability (i.e. const)
  mutable ACE_SYNCH_MUTEX mutex_;

  ACE_UINT64          compressed_bytes_;
  ACE_UINT64          uncompressed_bytes_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "Compressor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif // ACE_COMPRESSOR_H
