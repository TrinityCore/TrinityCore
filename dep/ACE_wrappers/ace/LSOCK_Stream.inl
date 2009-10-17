// -*- C++ -*-
//
// $Id: LSOCK_Stream.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Sets both the file descriptors... Overrides handle from the base
// classes.
ACE_INLINE void
ACE_LSOCK_Stream::set_handle (ACE_HANDLE fd)
{
  ACE_TRACE ("ACE_LSOCK_Stream::set_handle");
  this->ACE_SOCK_Stream::set_handle (fd);
  this->ACE_LSOCK::set_handle (fd);
}
ACE_INLINE ACE_HANDLE
ACE_LSOCK_Stream::get_handle (void) const
{
  ACE_TRACE ("ACE_LSOCK_Stream::get_handle");
  return this->ACE_SOCK_Stream::get_handle ();
}
ACE_END_VERSIONED_NAMESPACE_DECL
