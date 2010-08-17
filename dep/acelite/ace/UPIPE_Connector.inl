// -*- C++ -*-
//
// $Id: UPIPE_Connector.inl 82723 2008-09-16 09:35:44Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Creates a Local ACE_UPIPE.
ACE_INLINE
ACE_UPIPE_Connector::ACE_UPIPE_Connector (ACE_UPIPE_Stream &new_stream,
                                          const ACE_UPIPE_Addr &addr,
                                          ACE_Time_Value *timeout,
                                          const ACE_Addr &local_sap,
                                          int reuse_addr,
                                          int flags,
                                          int perms)
{
  ACE_TRACE ("ACE_UPIPE_Connector::ACE_UPIPE_Connector");
  if (this->connect (new_stream, addr, timeout, local_sap,
                     reuse_addr, flags, perms) == -1
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("address %s, %p\n"),
                addr.get_path_name (),
                ACE_TEXT ("ACE_UPIPE_Connector")));
}

ACE_INLINE bool
ACE_UPIPE_Connector::reset_new_handle (ACE_HANDLE /* handle */)
{
  // Nothing to do here since the handle is not a socket
  return false;
}

ACE_END_VERSIONED_NAMESPACE_DECL
