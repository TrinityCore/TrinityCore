// -*- C++ -*-
//
// $Id: XTI_ATM_Mcast.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_XTI_ATM_Mcast::ACE_XTI_ATM_Mcast (ACE_TLI_Stream &new_stream,
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
  ACE_TRACE ("ACE_XTI_ATM_Mcast::ACE_XTI_ATM_Mcast");
  if (this->connect (new_stream, remote_sap, timeout, local_sap, reuse_addr,
           flags, perms, device,
           info, rw_flag,
           udata, opt) == ACE_INVALID_HANDLE
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_TLI_Stream::ACE_TLI_Stream")));
}
// Connect the <new_stream> to the <remote_sap>, waiting up to
// <timeout> amount of time if necessary. This is simple a pass-
// through function to ACE_TLI_Connector::connect(). It is over-
// ridden to change the default device from TCP to XTI/ATM.
ACE_INLINE
int
ACE_XTI_ATM_Mcast::connect (ACE_TLI_Stream &new_stream,
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
  ACE_TRACE ("ACE_XTI_ATM_Mcast::connect");
  return ACE_TLI_Connector::connect(new_stream,
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
                                    opt);
}
ACE_END_VERSIONED_NAMESPACE_DECL
