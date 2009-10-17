// -*- C++ -*-
//
// $Id: FIFO_Recv.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/ACE.h"
#include "ace/OS_NS_unistd.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ssize_t
ACE_FIFO_Recv::recv (void *buf, size_t len)
{
  ACE_TRACE ("ACE_FIFO_Recv::recv");
  return ACE_OS::read (this->get_handle (), (char *) buf, len);
}
ACE_INLINE ssize_t
ACE_FIFO_Recv::recv_n (void *buf, size_t n)
{
  ACE_TRACE ("ACE_FIFO_Recv::recv_n");
  return ACE::recv_n (this->get_handle (), buf, n);
}
ACE_END_VERSIONED_NAMESPACE_DECL
