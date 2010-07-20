// -*- C++ -*-
//
// $Id: SSL_SOCK_Connector.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_SSL_SOCK_Connector::ACE_SSL_SOCK_Connector (void)
  : connector_ ()
{
  ACE_TRACE ("ACE_SSL_SOCK_Connector::ACE_SSL_SOCK_Connector");
}

ACE_INLINE int
ACE_SSL_SOCK_Connector::reset_new_handle (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_SSL_SOCK_Connector::reset_new_handle");
  return this->connector_.reset_new_handle (handle);
}

ACE_INLINE void
ACE_SSL_SOCK_Connector::dump (void) const
{
  ACE_TRACE ("ACE_SSL_SOCK_Connector::dump");
  this->connector_.dump ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
