// -*- C++ -*-
//
// $Id: FIFO_Send.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/ACE.h"
#include "ace/OS_NS_unistd.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ssize_t
ACE_FIFO_Send::send (const void *buf, size_t len)
{
  ACE_TRACE ("ACE_FIFO_Send::send");
  return ACE_OS::write (this->get_handle (), (const char *) buf, len);
}
ACE_INLINE ssize_t
ACE_FIFO_Send::send_n (const void *buf, size_t n)
{
  ACE_TRACE ("ACE_FIFO_Send::send_n");
  return ACE::send_n (this->get_handle (), buf, n);
}
ACE_END_VERSIONED_NAMESPACE_DECL
