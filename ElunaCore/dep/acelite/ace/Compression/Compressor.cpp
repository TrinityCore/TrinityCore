// $Id: Compressor.cpp 95556 2012-02-24 09:14:51Z johnnyw $

#include "Compressor.h"

#if !defined (__ACE_INLINE__)
#include "Compressor.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Compressor::ACE_Compressor( ACE_CompressorId compressor_id,
                                ACE_UINT32 compression_level )
    : compressor_id_        (compressor_id)
    , compression_level_    (compression_level)
    , compressed_bytes_     (0)
    , uncompressed_bytes_   (0)
{}

ACE_Compressor::~ACE_Compressor ()
{
}

ACE_UINT64
ACE_Compressor::compressed_bytes(void) const
{
    ACE_GUARD_RETURN( ACE_SYNCH_MUTEX, ace_mon, this->mutex_, 0 );
    return this->compressed_bytes_;
}

ACE_UINT64
ACE_Compressor::uncompressed_bytes(void) const
{
    ACE_GUARD_RETURN( ACE_SYNCH_MUTEX, ace_mon, this->mutex_, 0 );
    return this->uncompressed_bytes_;
}

void
ACE_Compressor::reset_stats(void)
{
    ACE_GUARD( ACE_SYNCH_MUTEX, ace_mon, this->mutex_ );
    this->compressed_bytes_   = 0;
    this->uncompressed_bytes_ = 0;
}

void
ACE_Compressor::update_stats(ACE_UINT64 uncompressed_bytes, ACE_UINT64 compressed_bytes)
{
    ACE_GUARD( ACE_SYNCH_MUTEX, ace_mon, this->mutex_ );
    this->compressed_bytes_   += compressed_bytes;
    this->uncompressed_bytes_ += uncompressed_bytes;
}

float
ACE_Compressor::compression_ratio(void) const
{
    ACE_GUARD_RETURN( ACE_SYNCH_MUTEX, ace_mon, this->mutex_, 0.0f );
    if (this->uncompressed_bytes_ > 0) {
        return static_cast<float>(this->compressed_bytes_) / this->uncompressed_bytes_;
    }
    return 0.0f;
}

ACE_END_VERSIONED_NAMESPACE_DECL
