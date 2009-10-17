// -*- C++ -*-
//
// $Id: MMAP_Memory_Pool.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_Mem_Map const &
ACE_MMAP_Memory_Pool::mmap (void) const
{
  return mmap_;
}
ACE_INLINE
ACE_Mem_Map &
ACE_MMAP_Memory_Pool::mmap (void)
{
  return mmap_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
