// -*- C++ -*-
//
// $Id: TLI_Connector.inl 82723 2008-09-16 09:35:44Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_TLI_Connector::ACE_TLI_Connector (ACE_TLI_Stream &new_stream,
                  const ACE_Addr &remote_sap,
                  ACE_Time_Value *timeout,
                  const ACE_Addr &local_sap,
                  int reuse_addr,
                  int flags,
                  int perms,
                  const char device[],
                  struct t_info *info,
                  int rw_flag,
                  struct netbuf *udata,
                  struct netbuf *opt)
{
  ACE_TRACE ("ACE_TLI_Connector::ACE_TLI_Connector");
  if (this->connect (new_stream,
                     remote_sap,
                     timeout,
                     local_sap,
                     reuse_addr,
                     flags,
                     perms,
                     device,
                     info,
                     rw_flag,
                     udata,
                     opt) == -1
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_TLI_Stream::ACE_TLI_Stream")));
}

ACE_INLINE
bool
ACE_TLI_Connector::reset_new_handle (ACE_HANDLE)
{
  // Nothing to do here since the handle is not a socket
  return false;
}

ACE_END_VERSIONED_NAMESPACE_DECL
