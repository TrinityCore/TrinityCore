//$Id: Hashable.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/Hashable.h"

#if !defined (__ACE_INLINE__)
#include "ace/Hashable.inl"
#endif /* __ACE_INLINE __ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Hashable::~ACE_Hashable (void)
{
}

unsigned long
ACE_Hashable::hash (void) const
{
  // In doing the check below, we take chance of paying a performance
  // price when the hash value is zero.  But, that will (hopefully)
  // happen far less often than a non-zero value, so this caching
  // strategy should pay off, esp. if hash computation is expensive
  // relative to the simple comparison.

  if (this->hash_value_ == 0)
    this->hash_value_ = this->hash_i ();

  return this->hash_value_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
