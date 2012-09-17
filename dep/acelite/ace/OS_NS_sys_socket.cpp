// $Id: OS_NS_sys_socket.cpp 93822 2011-04-08 21:56:45Z mesnier_p $

#include "ace/OS_NS_sys_socket.h"



#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_sys_socket.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/Containers_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_WIN32)
int ACE_OS::socket_initialized_;
#endif /* ACE_WIN32 */

ACE_HANDLE
ACE_OS::accept (ACE_HANDLE handle,
                struct sockaddr *addr,
                int *addrlen,
                const ACE_Accept_QoS_Params &qos_params)
{
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAAccept ((ACE_SOCKET) handle,
                                    addr,
                                    (ACE_SOCKET_LEN *) addrlen,
                                    (LPCONDITIONPROC) qos_params.qos_condition_callback (),
                                    qos_params.callback_data ()),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);
# else
  ACE_UNUSED_ARG (qos_params);
  return ACE_OS::accept (handle,
                         addr,
                         addrlen);
# endif /* ACE_HAS_WINSOCK2 */
}

int
ACE_OS::connect (ACE_HANDLE handle,
                 const sockaddr *addr,
                 int addrlen,
                 const ACE_QoS_Params &qos_params)
{
  ACE_OS_TRACE ("ACE_OS::connect");
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAConnect ((ACE_SOCKET) handle,
                                     (const sockaddr *) addr,
                                     (ACE_SOCKET_LEN) addrlen,
                                     (WSABUF *) qos_params.caller_data (),
                                     (WSABUF *) qos_params.callee_data (),
                                     (QOS *) qos_params.socket_qos (),
                                     (QOS *) qos_params.group_socket_qos ()),
                       int, -1);
# else
  ACE_UNUSED_ARG (qos_params);
  return ACE_OS::connect (handle,
                          const_cast <sockaddr *> (addr),
                          addrlen);
# endif /* ACE_HAS_WINSOCK2 */
}

ACE_HANDLE
ACE_OS::join_leaf (ACE_HANDLE socket,
                   const sockaddr *name,
                   int namelen,
                   const ACE_QoS_Params &qos_params)
{
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  QOS qos;
  // Construct the WinSock2 QOS structure.

  qos.SendingFlowspec = *(qos_params.socket_qos ()->sending_flowspec ());
  qos.ReceivingFlowspec = *(qos_params.socket_qos ()->receiving_flowspec ());
  qos.ProviderSpecific = (WSABUF) qos_params.socket_qos ()->provider_specific ();

  ACE_SOCKCALL_RETURN (::WSAJoinLeaf ((ACE_SOCKET) socket,
                                      name,
                                      namelen,
                                      (WSABUF *) qos_params.caller_data (),
                                      (WSABUF *) qos_params.callee_data (),
                                      &qos,
                                      (QOS *) qos_params.group_socket_qos (),
                                      qos_params.flags ()),
                       ACE_HANDLE,
                       ACE_INVALID_HANDLE);

# else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (name);
  ACE_UNUSED_ARG (namelen);
  ACE_UNUSED_ARG (qos_params);
  ACE_NOTSUP_RETURN (ACE_INVALID_HANDLE);
# endif /* ACE_HAS_WINSOCK2 */
}

int
ACE_OS::socket_init (int version_high, int version_low)
{
# if defined (ACE_WIN32) && !defined(ACE_DONT_INIT_WINSOCK)
  if (ACE_OS::socket_initialized_ == 0)
    {
      WORD version_requested = MAKEWORD (version_high, version_low);
      WSADATA wsa_data;
      int error = WSAStartup (version_requested, &wsa_data);

      if (error != 0)
#   if defined (ACE_HAS_WINCE)
        {
          ACE_TCHAR fmt[] = ACE_TEXT ("%s failed, WSAGetLastError returned %d");
          ACE_TCHAR buf[80];  // @@ Eliminate magic number.
          ACE_OS::sprintf (buf, fmt, ACE_TEXT ("WSAStartup"), error);
          ::MessageBox (0, buf, ACE_TEXT ("WSAStartup failed!"), MB_OK);
        }
#   else
      ACE_OS::fprintf (stderr,
                       "ACE_OS::socket_init; WSAStartup failed, "
                         "WSAGetLastError returned %d\n",
                       error);
#   endif /* ACE_HAS_WINCE */

      ACE_OS::socket_initialized_ = 1;
    }
# else
  ACE_UNUSED_ARG (version_high);
  ACE_UNUSED_ARG (version_low);
# endif /* ACE_WIN32 */
  return 0;
}

int
ACE_OS::socket_fini (void)
{
# if defined (ACE_WIN32)
  if (ACE_OS::socket_initialized_ != 0)
    {
      if (WSACleanup () != 0)
        {
          int error = ::WSAGetLastError ();
#   if defined (ACE_HAS_WINCE)
          ACE_TCHAR fmt[] = ACE_TEXT ("%s failed, WSAGetLastError returned %d");
          ACE_TCHAR buf[80];  // @@ Eliminate magic number.
          ACE_OS::sprintf (buf, fmt, ACE_TEXT ("WSACleanup"), error);
          ::MessageBox (0, buf , ACE_TEXT ("WSACleanup failed!"), MB_OK);
#   else
          ACE_OS::fprintf (stderr,
                           "ACE_OS::socket_fini; WSACleanup failed, "
                             "WSAGetLastError returned %d\n",
                           error);
#   endif /* ACE_HAS_WINCE */
        }
      ACE_OS::socket_initialized_ = 0;
    }
# endif /* ACE_WIN32 */
  return 0;
}

ssize_t
ACE_OS::sendv_partial_i (ACE_HANDLE handle,
                         const iovec *buffers,
                         int n)
{
  // the divide and conquer logic should remain consistent
  // with send_partial_i
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  DWORD bytes_sent = 0;
  int result = 1;
  int simulated_n = n;
  ACE_UINT64 buffer_size = 0;
  ACE_Array<iovec> iovec_array(simulated_n);
  int i = 0;
  for ( ; i < simulated_n; ++i)
    {
      iovec_array[i].iov_base = buffers[i].iov_base;
      iovec_array[i].iov_len = buffers[i].iov_len;
      buffer_size += buffers[i].iov_len;
    }
  // keep dividing the current buffer_size in half and then
  // attempt to send the modified iovec buffer until some
  // data is sent, or we get an errno that is not ENOBUFS
  while (true)
    {
      ACE_UINT64 remove_size = buffer_size / 2;
      buffer_size -= remove_size;
      for (i = simulated_n - 1; (i >= 0) && (remove_size > 0); --i)
        {
          // if the buffer division splits an iovec, we need
          // to set its iov_len properly
          if (iovec_array[i].iov_len > remove_size)
            {
              iovec_array[i].iov_len -= static_cast<u_long>(remove_size);
              break;
            }
          remove_size -= iovec_array[i].iov_len;
        }

      simulated_n = i + 1;

      result = ::WSASend ((SOCKET) handle,
                          (WSABUF *) &(iovec_array[0]),
                          simulated_n,
                          &bytes_sent,
                          0,
                          0,
                          0);
      if (result != SOCKET_ERROR)
        break;

      ACE_OS::set_errno_to_wsa_last_error ();
      // if ENOBUFS is received, we apply a divide and
      // conquer strategy, but if bytes are sent we
      // cannot guarantee this is the same behavior
      if ((errno != ENOBUFS) ||
          (bytes_sent != 0))
        {
          return -1;
        }
    }

  return (ssize_t) bytes_sent;
# else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buffers);
  ACE_UNUSED_ARG (n);

  return -1;
# endif /* ACE_HAS_WINSOCK2 */
}

ssize_t
ACE_OS::send_partial_i (ACE_HANDLE handle,
                        const char *buf,
                        size_t len,
                        int flags)
{
  // the divide and conquer logic should remain consistent
  // with sendv_partial_i
#if !defined (ACE_LACKS_SEND) && defined (ACE_WIN32)
  DWORD bytes_sent = 0;
  ssize_t result = 1;
  // keep dividing the current buffer_size in half and then
  // attempt to send the modified buffer until some data is
  // sent, or we get an errno that is not ENOBUFS
  while (true)
    {
      len -= len / 2;

      result = (ssize_t) ::send ((SOCKET) handle,
                                 buf,
                                 static_cast<int> (len),
                                 flags);
      if (result != SOCKET_ERROR)
        break;

      ACE_OS::set_errno_to_wsa_last_error ();
      // if ENOBUFS is received, we apply a divide and
      // conquer strategy, but if bytes are sent we
      // cannot guarantee this is the same behavior
      if ((errno != ENOBUFS) ||
          (bytes_sent != 0))
        {
          return -1;
        }
    }

  return result;
# else
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (buf);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (flags);

  return -1;
# endif /* ACE_LACKS_SEND && ACE_WIN32 */
}

ACE_END_VERSIONED_NAMESPACE_DECL
