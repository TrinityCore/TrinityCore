// -*- C++ -*-
//
// $Id: MEM_Stream.inl 92069 2010-09-28 11:38:59Z johnnyw $

#include "ace/MEM_Stream.h"
#include "ace/OS_NS_sys_socket.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_MEM_Stream::ACE_MEM_Stream (void)
{
  // ACE_TRACE ("ACE_MEM_Stream::ACE_MEM_Stream");
}

ACE_INLINE
ACE_MEM_Stream::ACE_MEM_Stream (ACE_HANDLE h)
{
  // ACE_TRACE ("ACE_MEM_Stream::ACE_MEM_Stream");
  this->set_handle (h);
}

ACE_INLINE
ACE_MEM_Stream::~ACE_MEM_Stream (void)
{
  // ACE_TRACE ("ACE_MEM_Stream::~ACE_MEM_Stream");
}

ACE_INLINE int
ACE_MEM_Stream::close_reader (void)
{
  ACE_TRACE ("ACE_MEM_Stream::close_reader");
  if (this->get_handle () != ACE_INVALID_HANDLE)
    return ACE_OS::shutdown (this->get_handle (), ACE_SHUTDOWN_READ);
  else
    return 0;
}

// Shut down just the writing end of a ACE_SOCK.

ACE_INLINE int
ACE_MEM_Stream::close_writer (void)
{
  ACE_TRACE ("ACE_MEM_Stream::close_writer");
  if (this->get_handle () != ACE_INVALID_HANDLE)
    return ACE_OS::shutdown (this->get_handle (), ACE_SHUTDOWN_WRITE);
  else
    return 0;
}

ACE_INLINE ssize_t
ACE_MEM_Stream::send_n (const void *buf, size_t n)
{
  return this->send (buf, n);
}


ACE_INLINE ssize_t
ACE_MEM_Stream::recv_n (void *buf, size_t n)
{
  return this->recv (buf, n);
}

ACE_INLINE ssize_t
ACE_MEM_Stream::send_n (const void *buf, size_t n, int flags)
{
  return this->send (buf, n, flags);
}

ACE_INLINE ssize_t
ACE_MEM_Stream::recv_n (void *buf, size_t n, int flags)
{
  return this->recv (buf, n, flags);
}

ACE_END_VERSIONED_NAMESPACE_DECL
