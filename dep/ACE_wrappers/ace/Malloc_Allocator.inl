// -*- C++ -*-
//
// $Id: Malloc_Allocator.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Static_Allocator_Base::ACE_Static_Allocator_Base (char * buffer,
                                                      size_t size)
  : buffer_ (buffer),
    size_ (size),
    offset_ (0)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
