// -*- C++ -*-
//
// $Id: Ping_Socket.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE char *
ACE_Ping_Socket::icmp_recv_buff (void)
{
  return this->icmp_recv_buff_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
