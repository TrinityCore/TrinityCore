// -*- C++ -*-
//
// $Id: LSOCK_CODgram.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Do nothing constructor.
ACE_INLINE
ACE_LSOCK_CODgram::ACE_LSOCK_CODgram (void)
{
  ACE_TRACE ("ACE_LSOCK_CODgram::ACE_LSOCK_CODgram");
}
ACE_INLINE void
ACE_LSOCK_CODgram::set_handle (ACE_HANDLE h)
{
  ACE_TRACE ("ACE_LSOCK_CODgram::set_handle");
  this->ACE_SOCK_CODgram::set_handle (h);
  this->ACE_LSOCK::set_handle (h);
}
ACE_INLINE ACE_HANDLE
ACE_LSOCK_CODgram::get_handle (void) const
{
  ACE_TRACE ("ACE_LSOCK_CODgram::get_handle");
  return this->ACE_SOCK_CODgram::get_handle ();
}
ACE_END_VERSIONED_NAMESPACE_DECL
