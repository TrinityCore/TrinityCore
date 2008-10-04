// $Id: OS_NS_stropts.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_stropts.h"

ACE_RCSID(ace, OS_NS_stropts, "$Id: OS_NS_stropts.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_stropts.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_OS::ioctl (ACE_HANDLE socket,
               unsigned long io_control_code,
               void *in_buffer_p,
               unsigned long in_buffer,
               void *out_buffer_p,
               unsigned long out_buffer,
               unsigned long *bytes_returned,
               ACE_OVERLAPPED *overlapped,
               ACE_OVERLAPPED_COMPLETION_FUNC func)
{
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  ACE_SOCKCALL_RETURN (::WSAIoctl ((ACE_SOCKET) socket,
                                   io_control_code,
                                   in_buffer_p,
                                   in_buffer,
                                   out_buffer_p,
                                   out_buffer,
                                   bytes_returned,
                                   (WSAOVERLAPPED *) overlapped,
                                   func),
                       int,
                       SOCKET_ERROR);
# else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (io_control_code);
  ACE_UNUSED_ARG (in_buffer_p);
  ACE_UNUSED_ARG (in_buffer);
  ACE_UNUSED_ARG (out_buffer_p);
  ACE_UNUSED_ARG (out_buffer);
  ACE_UNUSED_ARG (bytes_returned);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_WINSOCK2 */
}

#if !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500))
int
ACE_OS::ioctl (ACE_HANDLE socket,
               unsigned long io_control_code,
               ACE_QoS &ace_qos,
               unsigned long *bytes_returned,
               void *buffer_p,
               unsigned long buffer,
               ACE_OVERLAPPED *overlapped,
               ACE_OVERLAPPED_COMPLETION_FUNC func)
{
# if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)

  QOS qos;
  unsigned long qos_len = sizeof (QOS);

  if (io_control_code == SIO_SET_QOS)
    {
      qos.SendingFlowspec = *(ace_qos.sending_flowspec ());
      qos.ReceivingFlowspec = *(ace_qos.receiving_flowspec ());
      qos.ProviderSpecific = (WSABUF) ace_qos.provider_specific ();

      qos_len += ace_qos.provider_specific ().iov_len;

      ACE_SOCKCALL_RETURN (::WSAIoctl ((ACE_SOCKET) socket,
                                       io_control_code,
                                       &qos,
                                       qos_len,
                                       buffer_p,
                                       buffer,
                                       bytes_returned,
                                       (WSAOVERLAPPED *) overlapped,
                                       func),
                           int,
                           SOCKET_ERROR);
    }
  else
    {
      unsigned long dwBufferLen = 0;

      // Query for the buffer size.
      int result = ::WSAIoctl ((ACE_SOCKET) socket,
                                io_control_code,
                                0,
                                0,
                                &dwBufferLen,
                                sizeof (dwBufferLen),
                                bytes_returned,
                                0,
                                0);


      if (result == SOCKET_ERROR)
        {
          unsigned long dwErr = ::WSAGetLastError ();

          if (dwErr == WSAEWOULDBLOCK)
            {
              errno = dwErr;
              return -1;
            }
          else
            if (dwErr != WSAENOBUFS)
              {
                errno = dwErr;
                return -1;
              }
          }

    char *qos_buf = 0;
    ACE_NEW_RETURN (qos_buf,
                    char [dwBufferLen],
                    -1);

    QOS *qos = reinterpret_cast<QOS*> (qos_buf);

    result = ::WSAIoctl ((ACE_SOCKET) socket,
                       io_control_code,
                       0,
                       0,
                       qos,
                       dwBufferLen,
                       bytes_returned,
                       0,
                       0);

    if (result == SOCKET_ERROR)
      return result;

    ACE_Flow_Spec sending_flowspec (qos->SendingFlowspec.TokenRate,
                                    qos->SendingFlowspec.TokenBucketSize,
                                    qos->SendingFlowspec.PeakBandwidth,
                                    qos->SendingFlowspec.Latency,
                                    qos->SendingFlowspec.DelayVariation,
#  if defined(ACE_HAS_WINSOCK2_GQOS)
                                    qos->SendingFlowspec.ServiceType,
                                    qos->SendingFlowspec.MaxSduSize,
                                    qos->SendingFlowspec.MinimumPolicedSize,
#  else /* ACE_HAS_WINSOCK2_GQOS */
                                    0,
                                    0,
                                    0,
#  endif /* ACE_HAS_WINSOCK2_GQOS */
                                    0,
                                    0);

    ACE_Flow_Spec receiving_flowspec (qos->ReceivingFlowspec.TokenRate,
                                      qos->ReceivingFlowspec.TokenBucketSize,
                                      qos->ReceivingFlowspec.PeakBandwidth,
                                      qos->ReceivingFlowspec.Latency,
                                      qos->ReceivingFlowspec.DelayVariation,
#  if defined(ACE_HAS_WINSOCK2_GQOS)
                                      qos->ReceivingFlowspec.ServiceType,
                                      qos->ReceivingFlowspec.MaxSduSize,
                                      qos->ReceivingFlowspec.MinimumPolicedSize,
#  else /* ACE_HAS_WINSOCK2_GQOS */
                                      0,
                                      0,
                                      0,
#  endif /* ACE_HAS_WINSOCK2_GQOS */
                                      0,
                                      0);

       ace_qos.sending_flowspec (&sending_flowspec);
       ace_qos.receiving_flowspec (&receiving_flowspec);
       ace_qos.provider_specific (*((struct iovec *) (&qos->ProviderSpecific)));


      return result;
    }

# else
  ACE_UNUSED_ARG (socket);
  ACE_UNUSED_ARG (io_control_code);
  ACE_UNUSED_ARG (ace_qos);
  ACE_UNUSED_ARG (bytes_returned);
  ACE_UNUSED_ARG (buffer_p);
  ACE_UNUSED_ARG (buffer);
  ACE_UNUSED_ARG (overlapped);
  ACE_UNUSED_ARG (func);
  ACE_NOTSUP_RETURN (-1);
# endif /* ACE_HAS_WINSOCK2 */
}
#endif /* !(defined (ACE_HAS_WINCE) && (UNDER_CE < 500)) */

ACE_END_VERSIONED_NAMESPACE_DECL
