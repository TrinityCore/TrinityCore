#include "ace/SOCK_Dgram.h"
#include "ace/Handle_Set.h"
#include "ace/Log_Msg.h"
#include "ace/INET_Addr.h"
#include "ace/ACE.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_NS_ctype.h"
#include "ace/os_include/net/os_if.h"
#include "ace/Truncate.h"
#if !defined (__ACE_INLINE__)
#  include "ace/SOCK_Dgram.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_HAS_IPV6) && defined (ACE_WIN32)
#include /**/ <Iphlpapi.h>
#endif
ACE_RCSID (ace,
           SOCK_Dgram,
           "$Id: SOCK_Dgram.cpp 82559 2008-08-07 20:23:07Z parsons $")
// This is a workaround for platforms with non-standard
// definitions of the ip_mreq structure
#if ! defined (IMR_MULTIADDR)
#define IMR_MULTIADDR imr_multiaddr
#endif /* ! defined (IMR_MULTIADDR) */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE (ACE_SOCK_Dgram)
void
ACE_SOCK_Dgram::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_Dgram::dump");
#endif /* ACE_HAS_DUMP */
}
// Allows a client to read from a socket without having to provide a
// buffer to read.  This method determines how much data is in the
// socket, allocates a buffer of this size, reads in the data, and
// returns the number of bytes read.
ssize_t
ACE_SOCK_Dgram::recv (iovec *io_vec,
                      ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
#if defined (FIONREAD)
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());
  // Check the status of the current socket to make sure there's data
  // to recv (or time out).
  int select_width;
#  if defined (ACE_WIN32)
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  select_width = 0;
#  else
  select_width = int (this->get_handle ()) + 1;
#  endif /* ACE_WIN32 */
  switch (ACE_OS::select (select_width,
                          handle_set,
                          0, 0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, fallthrough to get data
      break;
    }
  sockaddr *saddr = (sockaddr *) addr.get_addr ();
  int addr_len = addr.get_size ();
  int inlen;
  if (ACE_OS::ioctl (this->get_handle (),
                     FIONREAD,
                     &inlen) == -1)
    return -1;
  else if (inlen > 0)
    {
      ACE_NEW_RETURN (io_vec->iov_base,
                      char[inlen],
                      -1);
      ssize_t rcv_len = ACE_OS::recvfrom (this->get_handle (),
                                          (char *) io_vec->iov_base,
                                          inlen,
                                          flags,
                                          (sockaddr *) saddr,
                                          &addr_len);
      if (rcv_len < 0)
        {
          delete [] (char *)io_vec->iov_base;
          io_vec->iov_base = 0;
        }
      else
        {
          io_vec->iov_len = ACE_Utils::truncate_cast<u_long> (rcv_len);
          addr.set_size (addr_len);
        }
      return rcv_len;
    }
  else
    return 0;
#else
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (addr);
  ACE_UNUSED_ARG (io_vec);
  ACE_UNUSED_ARG (timeout);
  ACE_NOTSUP_RETURN (-1);
#endif /* FIONREAD */
}
// Here's the shared open function.  Note that if we are using the
// PF_INET protocol family and the address of LOCAL == the address of
// the special variable SAP_ANY then we are going to arbitrarily bind
// to a portnumber.
int
ACE_SOCK_Dgram::shared_open (const ACE_Addr &local,
                             int protocol_family)
{
  ACE_TRACE ("ACE_SOCK_Dgram::shared_open");
  bool error = false;
  if (local == ACE_Addr::sap_any)
    {
      if (protocol_family == PF_INET
#if defined (ACE_HAS_IPV6)
          || protocol_family == PF_INET6
#endif /* ACE_HAS_IPV6 */
          )
        {
          if (ACE::bind_port (this->get_handle (),
                              INADDR_ANY,
                              protocol_family) == -1)
            error = true;
        }
    }
  else if (ACE_OS::bind (this->get_handle (),
                         reinterpret_cast<sockaddr *> (local.get_addr ()),
                         local.get_size ()) == -1)
    error = true;
  if (error)
    this->close ();
  return error ? -1 : 0;
}
int
ACE_SOCK_Dgram::open (const ACE_Addr &local,
                      int protocol_family,
                      int protocol,
                      ACE_Protocol_Info *protocolinfo,
                      ACE_SOCK_GROUP g,
                      u_long flags,
                      int reuse_addr)
{
  if (ACE_SOCK::open (SOCK_DGRAM,
                      protocol_family,
                      protocol,
                      protocolinfo,
                      g,
                      flags,
                      reuse_addr) == -1)
    return -1;
  else if (this->shared_open (local,
                              protocol_family) == -1)
    return -1;
  else
    return 0;
}
// Here's the general-purpose open routine.
int
ACE_SOCK_Dgram::open (const ACE_Addr &local,
                      int protocol_family,
                      int protocol,
                      int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::open");
  if (local != ACE_Addr::sap_any)
    protocol_family = local.get_type ();
  else if (protocol_family == PF_UNSPEC)
    {
#if defined (ACE_HAS_IPV6)
      protocol_family = ACE::ipv6_enabled () ? PF_INET6 : PF_INET;
#else
      protocol_family = PF_INET;
#endif /* ACE_HAS_IPV6 */
    }
  if (ACE_SOCK::open (SOCK_DGRAM,
                      protocol_family,
                      protocol,
                      reuse_addr) == -1)
    return -1;
  else
    return this->shared_open (local,
                              protocol_family);
}
// Here's the general-purpose constructor used by a connectionless
// datagram ``server''...
ACE_SOCK_Dgram::ACE_SOCK_Dgram (const ACE_Addr &local,
                                int protocol_family,
                                int protocol,
                                int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::ACE_SOCK_Dgram");
  if (this->open (local,
                  protocol_family,
                  protocol,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_Dgram")));
}
ACE_SOCK_Dgram::ACE_SOCK_Dgram (const ACE_Addr &local,
                                int protocol_family,
                                int protocol,
                                ACE_Protocol_Info *protocolinfo,
                                ACE_SOCK_GROUP g,
                                u_long flags,
                                int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_Dgram::ACE_SOCK_Dgram");
  if (this->open (local,
                  protocol_family,
                  protocol,
                  protocolinfo,
                  g,
                  flags,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_Dgram")));
}
#if defined (ACE_HAS_MSG)
// Send an iovec of size N to ADDR as a datagram (connectionless
// version).
ssize_t
ACE_SOCK_Dgram::send (const iovec iov[],
                      int n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");
  msghdr send_msg;
  send_msg.msg_iov = (iovec *) iov;
  send_msg.msg_iovlen = n;
#if defined (ACE_HAS_SOCKADDR_MSG_NAME)
  send_msg.msg_name = (struct sockaddr *) addr.get_addr ();
#else
  send_msg.msg_name = (char *) addr.get_addr ();
#endif /* ACE_HAS_SOCKADDR_MSG_NAME */
  send_msg.msg_namelen = addr.get_size ();
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  send_msg.msg_control = 0;
  send_msg.msg_controllen = 0;
  send_msg.msg_flags = 0;
#else
  send_msg.msg_accrights    = 0;
  send_msg.msg_accrightslen = 0;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
  return ACE_OS::sendmsg (this->get_handle (),
                          &send_msg,
                          flags);
}
// Recv an iovec of size N to ADDR as a datagram (connectionless
// version).
ssize_t
ACE_SOCK_Dgram::recv (iovec iov[],
                      int n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
  msghdr recv_msg;
  recv_msg.msg_iov = (iovec *) iov;
  recv_msg.msg_iovlen = n;
#if defined (ACE_HAS_SOCKADDR_MSG_NAME)
  recv_msg.msg_name = (struct sockaddr *) addr.get_addr ();
#else
  recv_msg.msg_name = (char *) addr.get_addr ();
#endif /* ACE_HAS_SOCKADDR_MSG_NAME */
  recv_msg.msg_namelen = addr.get_size ();
#if defined (ACE_HAS_4_4BSD_SENDMSG_RECVMSG)
  recv_msg.msg_control = 0 ;
  recv_msg.msg_controllen = 0 ;
#else
  recv_msg.msg_accrights = 0;
  recv_msg.msg_accrightslen = 0;
#endif /* ACE_HAS_4_4BSD_SENDMSG_RECVMSG */
  ssize_t status = ACE_OS::recvmsg (this->get_handle (),
                                    &recv_msg,
                                    flags);
  addr.set_size (recv_msg.msg_namelen);
  addr.set_type (((sockaddr_in *) addr.get_addr())->sin_family);
  return status;
}
#else /* ACE_HAS_MSG */
// Send an iovec of size N to ADDR as a datagram (connectionless
// version).
ssize_t
ACE_SOCK_Dgram::send (const iovec iov[],
                      int n,
                      const ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::send");
  size_t length = 0;
  int i;
  // Determine the total length of all the buffers in <iov>.
  for (i = 0; i < n; i++)
#if ! (defined(__BORLANDC__) || defined(linux) || defined(ACE_HAS_RTEMS))
    // The iov_len is unsigned on Linux, RTEMS and with Borland. If we go
    // ahead and try the if, it will emit a warning.
    if (iov[i].iov_len < 0)
      return -1;
    else
#endif
      length += iov[i].iov_len;
  char *buf = 0;
#if defined (ACE_HAS_ALLOCA)
  buf = alloca (length);
#else
  ACE_NEW_RETURN (buf,
                  char[length],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  char *ptr = buf;
  for (i = 0; i < n; i++)
    {
      ACE_OS::memcpy (ptr, iov[i].iov_base, iov[i].iov_len);
      ptr += iov[i].iov_len;
    }
  ssize_t result = ACE_SOCK_Dgram::send (buf, length, addr, flags);
#if !defined (ACE_HAS_ALLOCA)
  delete [] buf;
#endif /* !defined (ACE_HAS_ALLOCA) */
  return result;
}
// Recv an iovec of size N to ADDR as a datagram (connectionless
// version).
ssize_t
ACE_SOCK_Dgram::recv (iovec iov[],
                      int n,
                      ACE_Addr &addr,
                      int flags) const
{
  ACE_TRACE ("ACE_SOCK_Dgram::recv");
  ssize_t length = 0;
  int i;
  for (i = 0; i < n; i++)
#if ! (defined(__BORLANDC__) || defined(linux) || defined(ACE_HAS_RTEMS))
    // The iov_len is unsigned on Linux, RTEMS and with Borland. If we go
    // ahead and try the if, it will emit a warning.
    if (iov[i].iov_len < 0)
      return -1;
    else
#endif
      length += iov[i].iov_len;
  char *buf = 0;
#if defined (ACE_HAS_ALLOCA)
  buf = alloca (length);
#else
  ACE_NEW_RETURN (buf,
                  char[length],
                  -1);
#endif /* !defined (ACE_HAS_ALLOCA) */
  length = ACE_SOCK_Dgram::recv (buf, length, addr, flags);
  if (length != -1)
    {
      char *ptr = buf;
      int copyn = length;
      for (i = 0;
           i < n && copyn > 0;
           i++)
        {
          ACE_OS::memcpy (iov[i].iov_base, ptr,
                          // iov_len is int on some platforms, size_t on others
                          copyn > (int) iov[i].iov_len
                            ? (size_t) iov[i].iov_len
                            : (size_t) copyn);
          ptr += iov[i].iov_len;
          copyn -= iov[i].iov_len;
        }
    }
#if !defined (ACE_HAS_ALLOCA)
  delete [] buf;
#endif /* !defined (ACE_HAS_ALLOCA) */
  return length;
}
#endif /* ACE_HAS_MSG */
ssize_t
ACE_SOCK_Dgram::recv (void *buf,
                      size_t n,
                      ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());
  // Check the status of the current socket.
  int select_width;
#if defined (ACE_WIN32)
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  select_width = 0;
#else
  select_width = int (this->get_handle ()) + 1;
#endif /* ACE_WIN32 */
  switch (ACE_OS::select (select_width,
                          handle_set,
                          0,
                          0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, call <recv> to get data
      return this->recv (buf, n, addr, flags);
    }
}
ssize_t
ACE_SOCK_Dgram::send (const void *buf,
                      size_t n,
                      const ACE_Addr &addr,
                      int flags,
                      const ACE_Time_Value *timeout) const
{
  ACE_Handle_Set handle_set;
  handle_set.reset ();
  handle_set.set_bit (this->get_handle ());
  // Check the status of the current socket.
  int select_width;
#if defined (ACE_WIN32)
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  select_width = 0;
#else
  select_width = int (this->get_handle ()) + 1;
#endif /* ACE_WIN32 */
  switch (ACE_OS::select (select_width,
                          0,
                          handle_set,
                          0,
                          timeout))
    {
    case -1:
      return -1;
      /* NOTREACHED */
    case 0:
      errno = ETIME;
      return -1;
      /* NOTREACHED */
    default:
      // Goes fine, call <send> to transmit the data.
      return this->send (buf, n, addr, flags);
    }
}
int
ACE_SOCK_Dgram::set_nic (const ACE_TCHAR *net_if,
                         int addr_family)
{
#if defined (IP_MULTICAST_IF) && (IP_MULTICAST_IF != 0)
# if defined (ACE_HAS_IPV6)
  bool ipv6_mif_set = false;
  if (addr_family == AF_INET6 || addr_family == AF_UNSPEC)
    {
      ACE_INET_Addr addr;
      addr.set (static_cast<u_short> (0), ACE_IPV6_ANY);
      ipv6_mreq send_mreq;
      if (this->make_multicast_ifaddr6 (&send_mreq,
                                        addr,
                                        net_if) == -1)
        return -1;
      // Only let this attempt to set unknown interface when INET6 is
      // specifically requested. Otherwise we will just try INET.
      if (send_mreq.ipv6mr_interface != 0 || addr_family == AF_INET6)
        {
          if (this->ACE_SOCK::set_option
                              (IPPROTO_IPV6, IPV6_MULTICAST_IF,
                               &(send_mreq.ipv6mr_interface),
                               sizeof send_mreq.ipv6mr_interface) == -1)
            return -1;
        }
      ipv6_mif_set = send_mreq.ipv6mr_interface != 0;
    }
#   if defined (ACE_WIN32)
  // For Win32 net_if is distintly different between INET6 and INET
  // so it is always either an INET6 if or an INET if.
  if (!ipv6_mif_set && (addr_family == AF_INET || addr_family == AF_UNSPEC))
#   else
  if (addr_family == AF_INET || addr_family == AF_UNSPEC)
#   endif
    {
      ACE_INET_Addr addr (static_cast<u_short> (0));
      ip_mreq  send_mreq;
      if (this->make_multicast_ifaddr (&send_mreq,
                                       addr,
                                       net_if) == -1)
        {
          if (!ipv6_mif_set)
            return -1;
        }
      else if (this->ACE_SOCK::set_option (IPPROTO_IP,
                                           IP_MULTICAST_IF,
                                           &(send_mreq.imr_interface),
                                           sizeof send_mreq.imr_interface) == -1)
        {
          if (!ipv6_mif_set)
            return -1;
        }
    }
# else /* ACE_HAS_IPV6 */
  ACE_UNUSED_ARG (addr_family);
  ACE_INET_Addr addr (static_cast<u_short> (0));
  ip_mreq  send_mreq;
  if (this->make_multicast_ifaddr (&send_mreq,
                                   addr,
                                   net_if) == -1)
    return -1;
  if (this->ACE_SOCK::set_option (IPPROTO_IP,
                                  IP_MULTICAST_IF,
                                  &(send_mreq.imr_interface),
                                  sizeof send_mreq.imr_interface) == -1)
    return -1;
# endif /* !ACE_HAS_IPV6 */
#else /* IP_MULTICAST_IF */
  // Send interface option not supported - ignore it.
  // (We may have been invoked by ::subscribe, so we have to allow
  // a non-null interface parameter in this function.)
  ACE_UNUSED_ARG (net_if);
  ACE_UNUSED_ARG (addr_family);
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Send interface specification not ")
              ACE_TEXT ("supported - IGNORED.\n")));
#endif /* !IP_MULTICAST_IF */
  return 0;
}
int
ACE_SOCK_Dgram::make_multicast_ifaddr (ip_mreq *ret_mreq,
                                       const ACE_INET_Addr &mcast_addr,
                                       const ACE_TCHAR *net_if)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::make_multicast_ifaddr");
  ip_mreq  lmreq;       // Scratch copy.
  if (net_if != 0)
    {
#if defined (ACE_WIN32) || defined(__INTERIX)
      // This port number is not necessary, just convenient
      ACE_INET_Addr interface_addr;
      if (interface_addr.set (mcast_addr.get_port_number (), net_if) == -1)
        return -1;
      lmreq.imr_interface.s_addr =
        ACE_HTONL (interface_addr.get_ip_address ());
#else
      ifreq if_address;
      ACE_OS::strcpy (if_address.ifr_name, ACE_TEXT_ALWAYS_CHAR (net_if));
      if (ACE_OS::ioctl (this->get_handle (),
                         SIOCGIFADDR,
                         &if_address) == -1)
        return -1;
      sockaddr_in *socket_address =
        reinterpret_cast<sockaddr_in*> (&if_address.ifr_addr);
      lmreq.imr_interface.s_addr = socket_address->sin_addr.s_addr;
#endif /* ACE_WIN32 || __INTERIX */
    }
  else
    lmreq.imr_interface.s_addr = INADDR_ANY;
  lmreq.IMR_MULTIADDR.s_addr = ACE_HTONL (mcast_addr.get_ip_address ());
  // Set return info, if requested.
  if (ret_mreq)
    *ret_mreq = lmreq;
  return 0;
}
#if defined (ACE_HAS_IPV6)
// XXX: This will not work on any operating systems that do not support
//      if_nametoindex or that is not Win32 >= Windows XP/Server 2003
int
ACE_SOCK_Dgram::make_multicast_ifaddr6 (ipv6_mreq *ret_mreq,
                                        const ACE_INET_Addr &mcast_addr,
                                        const ACE_TCHAR *net_if)
{
  ACE_TRACE ("ACE_SOCK_Dgram_Mcast::make_multicast_ifaddr6");
  ipv6_mreq  lmreq;       // Scratch copy.
  ACE_OS::memset (&lmreq,
                  0,
                  sizeof (lmreq));
#if defined(__linux__)
  if (net_if != 0)
    {
      lmreq.ipv6mr_interface = ACE_OS::if_nametoindex (ACE_TEXT_ALWAYS_CHAR(net_if));
    }
  else
#elif defined (ACE_WIN32)
  if (net_if != 0)
    {
      int if_ix = 0;
      bool num_if =
        ACE_OS::ace_isdigit (net_if[0]) &&
        (if_ix = ACE_OS::atoi (net_if)) > 0;
      IP_ADAPTER_ADDRESSES tmp_addrs;
      // Initial call to determine actual memory size needed
      DWORD dwRetVal;
      ULONG bufLen = 0;
      if ((dwRetVal = ::GetAdaptersAddresses (AF_INET6,
                                              0,
                                              0,
                                              &tmp_addrs,
                                              &bufLen)) != ERROR_BUFFER_OVERFLOW)
        return -1; // With output bufferlength 0 this can't be right.
      // Get required output buffer and retrieve info for real.
      PIP_ADAPTER_ADDRESSES pAddrs;
      char *buf;
      ACE_NEW_RETURN (buf,
                      char[bufLen],
                      -1);
      pAddrs = reinterpret_cast<PIP_ADAPTER_ADDRESSES> (buf);
      if ((dwRetVal = ::GetAdaptersAddresses (AF_INET6,
                                              0,
                                              0,
                                              pAddrs,
                                              &bufLen)) != NO_ERROR)
        {
          delete[] buf; // clean up
          return -1;
        }
      lmreq.ipv6mr_interface = 0; // initialize
      while (pAddrs)
        {
          if ((num_if && pAddrs->Ipv6IfIndex == static_cast<unsigned int>(if_ix))
              || (!num_if &&
                  (ACE_OS::strcmp (ACE_TEXT_ALWAYS_CHAR (net_if),
                                   pAddrs->AdapterName) == 0
                   || ACE_OS::strcmp (ACE_TEXT_ALWAYS_CHAR (net_if),
                                      ACE_Wide_To_Ascii (pAddrs->FriendlyName).char_rep()) == 0)))
            {
              lmreq.ipv6mr_interface = pAddrs->Ipv6IfIndex;
              break;
            }
          pAddrs = pAddrs->Next;
        }
      delete[] buf; // clean up
    }
  else
#else  /* ACE_WIN32 */
    ACE_UNUSED_ARG(net_if);
#endif /* ACE_WIN32 */
    lmreq.ipv6mr_interface = 0;
  // now set the multicast address
  ACE_OS::memcpy (&lmreq.ipv6mr_multiaddr,
                  &((sockaddr_in6 *) mcast_addr.get_addr ())->sin6_addr,
                  sizeof (in6_addr));
  // Set return info, if requested.
  if (ret_mreq)
    *ret_mreq = lmreq;
  return 0;
}
#endif /* __linux__ && ACE_HAS_IPV6 */
ACE_END_VERSIONED_NAMESPACE_DECL

