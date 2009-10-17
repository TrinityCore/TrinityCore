// -*- C++ -*-
//
// $Id: SPIPE_Stream.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_sys_uio.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_unistd.h"
#if defined (ACE_WIN32)
#include "ace/OS_NS_sys_socket.h"
#endif
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Create an ACE_SPIPE_Stream.
ACE_INLINE int
ACE_SPIPE_Stream::get_remote_addr (ACE_SPIPE_Addr &remote_sap) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::get_remote_addr");
  remote_sap = this->remote_addr_;
  return 0;
}
// Send exactly N bytes from BUF to this socket.  Keeping trying until
// this many bytes are sent.
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send_n (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send_n");
  return ACE::write_n (this->get_handle (), buf, n);
}
// Receive exactly N bytes from this socket into BUF.  Keep trying
// until this many bytes are received.
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv_n (void *buf, size_t n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv_n");
  return ACE::read_n (this->get_handle (), buf, n);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send (const void *buf, size_t n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send");
  return ACE_OS::write (this->get_handle (), (const char *) buf, n);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv (void *buf, size_t n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv");
  return ACE_OS::read (this->get_handle (), (char *) buf, n);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send (const ACE_Str_Buf *cntl, const ACE_Str_Buf *data, int flags) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send");
  return ACE_OS::putmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, flags);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv (ACE_Str_Buf *cntl, ACE_Str_Buf *data, int *flags) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv");
  return ACE_OS::getmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, flags);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send (const ACE_Str_Buf *cntl, const ACE_Str_Buf *data, int band, int flags) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send");
  return ACE_OS::putpmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, band, flags);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv (ACE_Str_Buf *cntl, ACE_Str_Buf *data, int *band, int *flags) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv");
  return ACE_OS::getpmsg (this->get_handle (), (strbuf *) cntl, (strbuf *) data, band, flags);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send (const iovec iov[], int n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send");
  return ACE_OS::writev (this->get_handle (), iov, n);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv (iovec iov[], int n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv");
  return ACE_OS::readv (this->get_handle (), iov, n);
}
// This routine sends an open file descriptor to this socket.
ACE_INLINE int
ACE_SPIPE_Stream::send_handle (ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send_handle");
#if defined (ACE_HAS_STREAM_PIPES)
  return ACE_OS::ioctl (this->get_handle (), I_SENDFD, (void *) handle);
#elif defined (ACE_WIN32) && \
      (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)) && \
       !defined (ACE_HAS_WINCE)   /* CE4 has WS2 but not WSADuplicateSocket */
  DWORD procID;
  WSAPROTOCOL_INFO protInfo;
  ssize_t res = this->recv(&procID, sizeof(procID));
  if (res != sizeof(procID))
  {
    if(res != -1)
        errno = ENXIO;
    return -1;
  }
  if (::WSADuplicateSocket ((SOCKET)handle, procID, &protInfo) == -1)
  {
    ACE_OS::set_errno_to_wsa_last_error();
      return -1;
  }
  res = this->send(&protInfo, sizeof(protInfo));
  if (res != sizeof(protInfo))
  {
    if(res != -1)
        errno = ENXIO;
    return -1;
  }
  // This is just for synchronization, we will ignore the data
  res = this->recv(&procID, sizeof(procID));
  if (res != sizeof(procID))
  {
    if(res != -1)
        errno = ENXIO;
    return -1;
  }
  return 0;
#else
  handle = handle;
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
// This file receives an open file descriptor from this socket.
ACE_INLINE int
ACE_SPIPE_Stream::recv_handle (ACE_HANDLE &handle) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv_handle");
#if defined (ACE_HAS_STREAM_PIPES)
  strrecvfd recvfd;
  if (ACE_OS::ioctl (this->get_handle (), I_RECVFD, (void *) &recvfd) == -1)
    return -1;
  else
    {
      handle = recvfd.fd;
      return 0;
    }
#elif defined (ACE_WIN32) && \
      (defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0))
  pid_t procID = ACE_OS::getpid();
  WSAPROTOCOL_INFO protInfo;
  ssize_t res = this->send(&procID, sizeof(procID));
  if (res != sizeof(procID))
  {
    if(res != -1)
        errno = ENXIO;
    return -1;
  }
  res = this->recv(&protInfo, sizeof(protInfo));
  if (res != sizeof(protInfo))
  {
    if(res != -1)
        errno = ENXIO;
     return -1;
  }
  handle = ACE_OS::socket (FROM_PROTOCOL_INFO, FROM_PROTOCOL_INFO, FROM_PROTOCOL_INFO,
                           &protInfo, 0, 0);
  if (handle == ACE_INVALID_HANDLE)
  {
    return -1;
  }
  // Since it does not matter what the data is, just send something to
  // synchronize the end of the exchange
  res = this->send(&procID, sizeof(procID));
  if (res != sizeof(procID))
  {
    if(res != -1)
        errno = ENXIO;
    return -1;
  }
  return 0;
#else
  handle = handle;
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
// This file receives an open file descriptor from this socket and
// also passes back the information about the address...
ACE_INLINE int
ACE_SPIPE_Stream::recv_handle (strrecvfd &recvfd) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv_handle");
#if defined (ACE_HAS_STREAM_PIPES)
  return ACE_OS::ioctl (this->get_handle (), I_RECVFD, (void *) &recvfd);
#else
  ACE_UNUSED_ARG (recvfd);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_STREAM_PIPES */
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::send (const void *buf, size_t n,
                        ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::send");
  return ACE_OS::write (this->get_handle (),
                        (const char *) buf, n,
                        overlapped);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recv (void *buf, size_t n,
                        ACE_OVERLAPPED *overlapped) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recv");
  return ACE_OS::read (this->get_handle (),
                       (char *) buf, n,
                       overlapped);
}
ACE_INLINE ssize_t
ACE_SPIPE_Stream::sendv_n (const iovec iov[],
                           int n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::sendv_n");
  return ACE::writev_n (this->get_handle (),
                        iov,
                        n);
}
// Recv an n byte message from the Stream.
ACE_INLINE ssize_t
ACE_SPIPE_Stream::recvv_n (iovec iov[],
                           int n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::recvv_n");
  // @@ Carlos, can you please update this to call the
  // new ACE::recvv_n() method that you write?
  return ACE_OS::readv (this->get_handle (),
                        iov,
                        n);
}
// Send an <iovec> of size <n> to the Stream.
ACE_INLINE ssize_t
ACE_SPIPE_Stream::sendv (const iovec iov[],
                         int n) const
{
  ACE_TRACE ("ACE_SPIPE_Stream::sendv");
  return ACE_OS::writev (this->get_handle (),
                         iov,
                         n);
}
ACE_END_VERSIONED_NAMESPACE_DECL

