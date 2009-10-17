// -*- C++ -*-
//
// $Id: Pagefile_Memory_Pool.inl 80826 2008-03-04 14:51:23Z wotte $
#if defined (ACE_WIN32) && !defined (ACE_HAS_PHARLAP)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE size_t
ACE_Pagefile_Memory_Pool::round_to_chunk_size (size_t nbytes)
{
  return (nbytes + ACE_DEFAULT_PAGEFILE_POOL_CHUNK - 1)
          & (~(ACE_DEFAULT_PAGEFILE_POOL_CHUNK - 1));
}
ACE_INLINE size_t
ACE_Pagefile_Memory_Pool::round_to_page_size (size_t nbytes)
{
  return ACE::round_to_pagesize (nbytes);
}
ACE_INLINE int
ACE_Pagefile_Memory_Pool::sync (ssize_t, int)
{
  return 0;
}
ACE_INLINE int
ACE_Pagefile_Memory_Pool::sync (void *, size_t, int)
{
  return 0;
}
ACE_INLINE int
ACE_Pagefile_Memory_Pool::protect (ssize_t, int)
{
  return 0;
}
ACE_INLINE int
ACE_Pagefile_Memory_Pool::protect (void *, size_t, int)
{
  return 0;
}
ACE_INLINE void *
ACE_Pagefile_Memory_Pool::base_addr (void) const
{
  return 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_WIN32 &7 !ACE_HAS_PHARLAP */
