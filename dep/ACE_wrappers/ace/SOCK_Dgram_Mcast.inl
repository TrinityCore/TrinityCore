// -*- C++ -*-
//
// $Id: SOCK_Dgram_Mcast.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_SOCK_Dgram_Mcast::set_option (int option,
                                  char optval)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::set_option");
  if (this->get_handle () == ACE_INVALID_HANDLE)
    return -1;
  int level = IPPROTO_IP;
#if defined (IPPROTO_IPV6) && ! defined (INTEGRITY)
  if (this->send_addr_.get_type () == PF_INET6)
    level = IPPROTO_IPV6;
#endif /* IPPROTO_IPV6 */
  return this->ACE_SOCK::set_option (level,
                                     option,
                                     &optval,
                                     sizeof (optval));
}
ACE_INLINE ssize_t
ACE_SOCK_Dgram_Mcast::send (const void *buf,
                            size_t n,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::send");
  return this->ACE_SOCK_Dgram::send (buf,
                                     n,
                                     this->send_addr_,
                                     flags);
}
ACE_INLINE ssize_t
ACE_SOCK_Dgram_Mcast::send (const iovec iov[],
                            int n,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::send");
  return this->ACE_SOCK_Dgram::send (iov,
                                     n,
                                     this->send_addr_,
                                     flags);
}
ACE_END_VERSIONED_NAMESPACE_DECL
