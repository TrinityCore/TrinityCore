// -*- C++ -*-
//
// $Id: ACE.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_Thread.h"
#include "ace/OS_NS_ctype.h"
#include "ace/OS_NS_sys_socket.h"

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Wrappers for methods that have been moved to ACE_OS.

ACE_INLINE ssize_t
ACE::read_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             size_t *bytes_transferred)
{
  return ACE_OS::read_n (handle,
                         buf,
                         len,
                         bytes_transferred);
}

ACE_INLINE ssize_t
ACE::write_n (ACE_HANDLE handle,
              const void *buf,
              size_t len,
              size_t *bytes_transferred)
{
  return ACE_OS::write_n (handle,
                          buf,
                          len,
                          bytes_transferred);
}

ACE_INLINE ssize_t
ACE::recv_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             int flags,
             const ACE_Time_Value *timeout,
             size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          flags,
                          bytes_transferred);
  else
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          flags,
                          timeout,
                          bytes_transferred);
}

#if defined (ACE_HAS_TLI)

ACE_INLINE ssize_t
ACE::t_rcv_n (ACE_HANDLE handle,
              void *buf,
              size_t len,
              int *flags,
              const ACE_Time_Value *timeout,
              size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::t_rcv_n_i (handle,
                           buf,
                           len,
                           flags,
                           bytes_transferred);
  else
    return ACE::t_rcv_n_i (handle,
                           buf,
                           len,
                           flags,
                           timeout,
                           bytes_transferred);
}

#endif /* ACE_HAS_TLI */

ACE_INLINE ssize_t
ACE::recv_n (ACE_HANDLE handle,
             void *buf,
             size_t len,
             const ACE_Time_Value *timeout,
             size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          bytes_transferred);
  else
    return ACE::recv_n_i (handle,
                          buf,
                          len,
                          timeout,
                          bytes_transferred);
}

ACE_INLINE ssize_t
ACE::recvv_n (ACE_HANDLE handle,
              iovec *iov,
              int iovcnt,
              const ACE_Time_Value *timeout,
              size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::recvv_n_i (handle,
                           iov,
                           iovcnt,
                           bytes_transferred);
  else
    return ACE::recvv_n_i (handle,
                           iov,
                           iovcnt,
                           timeout,
                           bytes_transferred);
}

ACE_INLINE ssize_t
ACE::send_n (ACE_HANDLE handle,
             const void *buf,
             size_t len,
             int flags,
             const ACE_Time_Value *timeout,
             size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          flags,
                          bytes_transferred);
  else
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          flags,
                          timeout,
                          bytes_transferred);
}

#if defined (ACE_HAS_TLI)

ACE_INLINE ssize_t
ACE::t_snd_n (ACE_HANDLE handle,
              const void *buf,
              size_t len,
              int flags,
              const ACE_Time_Value *timeout,
              size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::t_snd_n_i (handle,
                           buf,
                           len,
                           flags,
                           bytes_transferred);
  else
    return ACE::t_snd_n_i (handle,
                           buf,
                           len,
                           flags,
                           timeout,
                           bytes_transferred);
}

#endif /* ACE_HAS_TLI */

ACE_INLINE ssize_t
ACE::send_n (ACE_HANDLE handle,
             const void *buf,
             size_t len,
             const ACE_Time_Value *timeout,
             size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          bytes_transferred);
  else
    return ACE::send_n_i (handle,
                          buf,
                          len,
                          timeout,
                          bytes_transferred);
}

ACE_INLINE ssize_t
ACE::sendv_n (ACE_HANDLE handle,
              const iovec *iov,
              int iovcnt,
              const ACE_Time_Value *timeout,
              size_t *bytes_transferred)
{
  if (timeout == 0)
    return ACE::sendv_n_i (handle,
                           iov,
                           iovcnt,
                           bytes_transferred);
  else
    return ACE::sendv_n_i (handle,
                           iov,
                           iovcnt,
                           timeout,
                           bytes_transferred);
}

ACE_INLINE ssize_t
ACE::send_i (ACE_HANDLE handle, const void *buf, size_t len)
{
#if defined (ACE_WIN32) || defined (HPUX)
  return ACE_OS::send (handle, (const char *) buf, len);
#else
  return ACE_OS::write (handle, (const char *) buf, len);
#endif /* ACE_WIN32 */
}

ACE_INLINE ssize_t
ACE::recv_i (ACE_HANDLE handle, void *buf, size_t len)
{
#if defined (ACE_WIN32) || defined (ACE_OPENVMS) || defined (ACE_TANDEM_T1248_PTHREADS)
  return ACE_OS::recv (handle, (char *) buf, len);
#else
  return ACE_OS::read (handle, (char *) buf, len);
#endif /* ACE_WIN32 */
}

ACE_INLINE int
ACE::handle_read_ready (ACE_HANDLE handle,
                        const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            1,
                            0,
                            0);
}

ACE_INLINE int
ACE::handle_write_ready (ACE_HANDLE handle,
                         const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            0,
                            1,
                            0);
}

ACE_INLINE int
ACE::handle_exception_ready (ACE_HANDLE handle,
                             const ACE_Time_Value *timeout)
{
  return ACE::handle_ready (handle,
                            timeout,
                            0,
                            0,
                            1);
}

ACE_INLINE void
ACE::strdelete (char *s)
{
  delete [] s;
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE void
ACE::strdelete (wchar_t *s)
{
  delete [] s;
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE void
ACE::unique_name (const void *object,
                  ACE_TCHAR *name,
                  size_t length)
{
  ACE_OS::unique_name (object, name, length);
}

ACE_INLINE u_long
ACE::log2 (u_long num)
{
  u_long log = 0;

  for (; num > 1; ++log)
    num >>= 1;

  return log;
}

ACE_INLINE ACE_TCHAR
ACE::nibble2hex (u_int n)
{
  // Hexadecimal characters.
#if defined (ACE_VXWORKS) && !defined (__DCPLUSPLUS__)
  // temporary solution to prevent Windriver GNU toolchains from spewing
  // loads of warnings when inlining.
  // problem (incorrect warning leftover from older GNU) has been reported as
  // TSR to Windriver.
  const ACE_TCHAR hex_chars[] = ACE_TEXT ("0123456789abcdef");
#else
  static const ACE_TCHAR hex_chars[] = ACE_TEXT ("0123456789abcdef");
#endif

  // Yes, this works for UNICODE
  return hex_chars[n & 0x0f];
}

ACE_INLINE int
ACE::map_errno (int error)
{
#if defined (ACE_WIN32)
  switch (error)
    {
    case WSAEWOULDBLOCK:
      return EAGAIN; // Same as UNIX errno EWOULDBLOCK.
    }
#endif /* ACE_WIN32 */

  return error;
}

ACE_INLINE u_char
ACE::hex2byte (ACE_TCHAR c)
{
  if (ACE_OS::ace_isdigit (c))
    return (u_char) (c - ACE_TEXT ('0'));
  else if (ACE_OS::ace_islower (c))
    return (u_char) (10 + c - ACE_TEXT ('a'));
  else
    return (u_char) (10 + c - ACE_TEXT ('A'));
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
