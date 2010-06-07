// -*- C++ -*-
//
// $Id: SOCK.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_sys_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_SOCK::~ACE_SOCK (void)
{
  // ACE_TRACE ("ACE_SOCK::~ACE_SOCK");
}

ACE_INLINE int
ACE_SOCK::set_option (int level,
                      int option,
                      void *optval,
                      int optlen) const
{
  ACE_TRACE ("ACE_SOCK::set_option");
  return ACE_OS::setsockopt (this->get_handle (), level,
                             option, (char *) optval, optlen);
}

// Provides access to the ACE_OS::getsockopt system call.

ACE_INLINE int
ACE_SOCK::get_option (int level,
                      int option,
                      void *optval,
                      int *optlen) const
{
  ACE_TRACE ("ACE_SOCK::get_option");
  return ACE_OS::getsockopt (this->get_handle (), level,
                             option, (char *) optval, optlen);
}

ACE_END_VERSIONED_NAMESPACE_DECL
