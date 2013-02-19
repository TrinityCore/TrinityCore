// -*- C++ -*-
//
// $Id: Pipe.inl 92010 2010-09-24 14:54:19Z shuston $

#include "ace/Global_Macros.h"
#include "ace/ACE.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Pipe::~ACE_Pipe (void)
{
  ACE_TRACE ("ACE_Pipe::~ACE_Pipe");
  // Notice that the destructor doesn't close the handles for you.
}

ACE_INLINE ACE_HANDLE
ACE_Pipe::read_handle (void) const
{
  ACE_TRACE ("ACE_Pipe::read_handle");
  return this->handles_[0];
}

ACE_INLINE ACE_HANDLE
ACE_Pipe::write_handle (void) const
{
  ACE_TRACE ("ACE_Pipe::write_handle");
  return this->handles_[1];
}

ACE_INLINE ssize_t
ACE_Pipe::sendv_n (const iovec iov[], int n) const
{
  ACE_TRACE ("ACE_Pipe::sendv_n");
#if defined (ACE_WIN32)
  return ACE::sendv_n (this->write_handle (),
                      iov,
                      n);
#else
  return ACE::writev_n (this->write_handle (),
                        iov,
                        n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::send_n (const ACE_Message_Block *message_block,
                  const ACE_Time_Value *timeout,
                  size_t *bytes_transferred)
{
  ACE_TRACE ("ACE_Pipe::send_n");
#if defined (ACE_WIN32)
  return ACE::send_n (this->write_handle (),
                      message_block,
                      timeout,
                      bytes_transferred);
#else
  ACE_UNUSED_ARG (timeout);
  return ACE::write_n (this->write_handle (),
                      message_block,
                      bytes_transferred);
#endif /* ACE_WIN32 */
}

// Recv an n byte message from the file.

ACE_INLINE ssize_t
ACE_Pipe::recvv_n (iovec iov[], int n) const
{
  ACE_TRACE ("ACE_Pipe::recvv_n");
  // @@ Carlos, can you please update this to call the
  // new ACE::recvv_n() method that you write?
#if defined (ACE_WIN32)
  return ACE_OS::sendv (this->read_handle (),
                        iov,
                        n);
#else
  return ACE_OS::readv (this->read_handle (),
                        iov,
                        n);
#endif /* ACE_WIN32 */
}

// Send an <iovec> of size <n> to the file.

ACE_INLINE ssize_t
ACE_Pipe::sendv (const iovec iov[], int n) const
{
  ACE_TRACE ("ACE_Pipe::sendv");
#if defined (ACE_WIN32)
  return ACE_OS::sendv (this->write_handle (), iov, n);
#else
  return ACE_OS::writev (this->write_handle (), iov, n);
#endif /* ACE_WIN32 */
}

// Send exactly N bytes from BUF to this file.  Keeping trying until
// this many bytes are sent.

ACE_INLINE ssize_t
ACE_Pipe::send_n (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_Pipe::send_n");
#if defined (ACE_WIN32)
  return ACE::send_n (this->write_handle (), buf, n);
#else
  return ACE::write_n (this->write_handle (), buf, n);
#endif /* ACE_WIN32 */
}

// Receive exactly N bytes from this file into BUF.  Keep trying until
// this many bytes are received.

ACE_INLINE ssize_t
ACE_Pipe::recv_n (void *buf, size_t n) const
{
  ACE_TRACE ("ACE_Pipe::recv_n");
#if defined (ACE_WIN32)
  return ACE::recv_n (this->read_handle (), buf, n);
#else
  return ACE::read_n (this->read_handle (), buf, n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::send (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_Pipe::send");
#if defined (ACE_WIN32)
  return ACE_OS::send (this->write_handle (), static_cast <const char *> (buf), n);
#else
  return ACE_OS::write (this->write_handle (), static_cast <const char *> (buf), n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::recv (void *buf, size_t n) const
{
  ACE_TRACE ("ACE_Pipe::recv");
#if defined (ACE_WIN32)
  return ACE_OS::recv (this->read_handle (), static_cast <char *> (buf), n);
#else
  return ACE_OS::read (this->read_handle (), static_cast <char *> (buf), n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::send (const iovec iov[], int n) const
{
  ACE_TRACE ("ACE_Pipe::send");
#if defined (ACE_WIN32)
  return ACE_OS::sendv (this->write_handle (), iov, n);
#else
  return ACE_OS::writev (this->write_handle (), iov, n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::recv (iovec iov[], int n) const
{
  ACE_TRACE ("ACE_Pipe::recv");
#if defined (ACE_WIN32)
  return ACE_OS::recvv (this->read_handle (), iov, n);
#else
  return ACE_OS::readv (this->read_handle (), iov, n);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE_Pipe::send (const void *buf, size_t n,
                ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_Pipe::send");
  return ACE_OS::write (this->write_handle (),
                        static_cast <const char *> (buf), n,
                        overlapped);
}

ACE_INLINE ssize_t
ACE_Pipe::recv (void *buf, size_t n,
                ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_Pipe::recv");
  return ACE_OS::read (this->read_handle (), static_cast <char *> (buf), n,
                       overlapped);
}

ACE_INLINE int
ACE_Pipe::close_handle (int which)
{
  int result = 0;

  // Note that the following will work even if we aren't closing down
  // sockets because <ACE_OS::closesocket> will just call <::close> in
  // that case!

  if (this->handles_[which] != ACE_INVALID_HANDLE)
    result = ACE_OS::closesocket (this->handles_[which]);
  this->handles_[which] = ACE_INVALID_HANDLE;
  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
