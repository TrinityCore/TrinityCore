// -*- C++ -*-
//
// $Id: DEV_IO.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_Memory.h"
#include "ace/ACE.h"
// Send exactly N bytes from BUF to this device.  Keeping trying until
// this many bytes are sent.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ssize_t
ACE_DEV_IO::send_n (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_DEV_IO::send_n");
  return ACE::write_n (this->get_handle (), buf, n);
}
// Receive exactly N bytes from this file into BUF.  Keep trying until
// this many bytes are received.
ACE_INLINE ssize_t
ACE_DEV_IO::recv_n (void *buf,
                    size_t n,
                    const ACE_Time_Value *timeout,
                    size_t *bytes_transferred) const
{
  ACE_TRACE ("ACE_DEV_IO::recv_n");
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (timeout);
  return ACE::read_n (this->get_handle (),
                      buf,
                      n,
                      bytes_transferred);
#else
  return ACE::recv_n (this->get_handle (),
                      buf,
                      n,
                      timeout,
                      bytes_transferred);
#endif /*ACE_WIN32*/
}
ACE_INLINE ssize_t
ACE_DEV_IO::send (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  return ACE_OS::write (this->get_handle (), (const char *) buf, n);
}
ACE_INLINE ssize_t
ACE_DEV_IO::recv (void *buf, size_t n) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  return ACE_OS::read (this->get_handle (), (char *) buf, n);
}
ACE_INLINE ssize_t
ACE_DEV_IO::send (const iovec iov[], size_t n) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  return ACE_OS::writev (this->get_handle (), iov, static_cast<int> (n));
}
ACE_INLINE ssize_t
ACE_DEV_IO::recv (iovec iov[], size_t n) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  return ACE_OS::readv (this->get_handle (), iov, static_cast<int> (n));
}
ACE_INLINE ssize_t
ACE_DEV_IO::send (const void *buf, size_t n,
                  ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  return ACE_OS::write (this->get_handle (),
                        (const char *) buf, n,
                        overlapped);
}
ACE_INLINE ssize_t
ACE_DEV_IO::recv (void *buf, size_t n,
                  ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  return ACE_OS::read (this->get_handle (), (char *) buf, n,
                       overlapped);
}
#if defined (ACE_HAS_STREAM_PIPES)
ACE_INLINE ssize_t
ACE_DEV_IO::recv (ACE_Str_Buf *cntl, ACE_Str_Buf *data, int *band, int *flags) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  return ACE_OS::getpmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, band, flags);
}
ACE_INLINE ssize_t
ACE_DEV_IO::send (const ACE_Str_Buf *cntl, const ACE_Str_Buf *data, int band, int flags) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  return ACE_OS::putpmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, band, flags);
}
ACE_INLINE ssize_t
ACE_DEV_IO::recv (ACE_Str_Buf *cntl, ACE_Str_Buf *data, int *flags) const
{
  ACE_TRACE ("ACE_DEV_IO::recv");
  return ACE_OS::getmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, flags);
}
ACE_INLINE ssize_t
ACE_DEV_IO::send (const ACE_Str_Buf *cntl, const ACE_Str_Buf *data, int flags) const
{
  ACE_TRACE ("ACE_DEV_IO::send");
  return ACE_OS::putmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, flags);
}
#endif /* ACE_HAS_STREAM_PIPES */
ACE_END_VERSIONED_NAMESPACE_DECL
