// -*- C++ -*-
//
// $Id: SOCK_Dgram_Bcast.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_sys_socket.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_Bcast_Node::~ACE_Bcast_Node (void)
{
}
ACE_INLINE
ACE_SOCK_Dgram_Bcast::~ACE_SOCK_Dgram_Bcast (void)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::~ACE_SOCK_Dgram_Bcast");
}
// Broadcast an N byte datagram to ADDR (note that addr must be
// preassigned to the broadcast address of the subnet...)
ACE_INLINE ssize_t
ACE_SOCK_Dgram_Bcast::send (const void *buf,
                            size_t n,
                            const ACE_Addr &addr,
                            int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram_Bcast::send");
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int len = addr.get_size ();
  return ACE_OS::sendto (this->get_handle (), (const char *) buf, n, flags,
                         (struct sockaddr *) saddr, len);
}
ACE_END_VERSIONED_NAMESPACE_DECL
