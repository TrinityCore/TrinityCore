// -*- C++ -*-
//
// $Id: FILE_Connector.inl 80826 2008-03-04 14:51:23Z wotte $

// Creates a Local ACE_FILE.

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_FILE_Connector::ACE_FILE_Connector (ACE_FILE_IO &new_io,
                                        const ACE_FILE_Addr &remote_sap,
                                        ACE_Time_Value *timeout,
                                        const ACE_Addr &local_sap,
                                        int reuse_addr,
                                        int flags,
                                        int perms)
{
  ACE_TRACE ("ACE_FILE_Connector::ACE_FILE_Connector");
  if (this->connect (new_io, remote_sap, timeout, local_sap,
                     reuse_addr, flags, perms) == ACE_IO_SAP::INVALID_HANDLE
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("address %s, %p\n"),
                remote_sap.get_path_name (),
                ACE_TEXT ("ACE_FILE_IO")));
}

ACE_INLINE int
ACE_FILE_Connector::reset_new_handle (ACE_HANDLE handle)
{
  ACE_UNUSED_ARG (handle);
  // Nothing to do here since the handle is not a socket
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
