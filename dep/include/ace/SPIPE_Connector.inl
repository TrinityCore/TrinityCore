// -*- C++ -*-
//
// $Id: SPIPE_Connector.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_SPIPE_Connector::reset_new_handle (ACE_HANDLE handle)
{
  ACE_UNUSED_ARG (handle);
  // Nothing to do here since the handle is not a socket
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
