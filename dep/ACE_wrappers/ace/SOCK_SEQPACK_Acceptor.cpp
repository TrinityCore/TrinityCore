// $Id: SOCK_SEQPACK_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/SOCK_SEQPACK_Acceptor.h"
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/os_include/os_fcntl.h"
#if !defined (__ACE_INLINE__)
#include "ace/SOCK_SEQPACK_Acceptor.inl"
#endif /* __ACE_INLINE__ */
ACE_RCSID(ace, SOCK_SEQPACK_Acceptor, "SOCK_SEQPACK_Acceptor.cpp,v 4.30 2002/03/08 23:18:09 spark Exp")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_SEQPACK_Acceptor)
// Do nothing routine for constructor.
ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor (void)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor");
}
// Performs the timed accept operation.
int
ACE_SOCK_SEQPACK_Acceptor::shared_accept_start (ACE_Time_Value *timeout,
                                        int restart,
                                        int &in_blocking_mode) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::shared_accept_start");
  ACE_HANDLE handle = this->get_handle ();
  // Handle the case where we're doing a timed <accept>.
  if (timeout != 0)
    {
      if (ACE::handle_timed_accept (handle,
                                    timeout,
                                    restart) == -1)
        return -1;
      else
        {
          in_blocking_mode = ACE_BIT_DISABLED (ACE::get_flags (handle),
                                               ACE_NONBLOCK);
          // Set the handle into non-blocking mode if it's not already
          // in it.
          if (in_blocking_mode
              && ACE::set_flags (handle,
                                 ACE_NONBLOCK) == -1)
            return -1;
        }
    }
  return 0;
}
int
ACE_SOCK_SEQPACK_Acceptor::shared_accept_finish (ACE_SOCK_SEQPACK_Association new_association,
                                         int in_blocking_mode,
                                         int reset_new_handle) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::shared_accept_finish ()");
  ACE_HANDLE new_handle = new_association.get_handle ();
  // Check to see if we were originally in blocking mode, and if so,
  // set the <new_association>'s handle and <this> handle to be in blocking
  // mode.
  if (in_blocking_mode)
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);
      // Only disable ACE_NONBLOCK if we weren't in non-blocking mode
      // originally.
      ACE::clr_flags (this->get_handle (),
                      ACE_NONBLOCK);
      ACE::clr_flags (new_handle,
                      ACE_NONBLOCK);
    }
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  if (reset_new_handle)
    // Reset the event association inherited by the new handle.
    ::WSAEventSelect ((SOCKET) new_handle, 0, 0);
#else
  ACE_UNUSED_ARG (reset_new_handle);
#endif /* ACE_WIN32 */
  return new_handle == ACE_INVALID_HANDLE ? -1 : 0;
}
// General purpose routine for accepting new connections.
int
ACE_SOCK_SEQPACK_Acceptor::accept (ACE_SOCK_SEQPACK_Association &new_association,
                           ACE_Addr *remote_addr,
                           ACE_Time_Value *timeout,
                           int restart,
                           int reset_new_handle) const
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::accept");
  int in_blocking_mode = 0;
  if (this->shared_accept_start (timeout,
                                 restart,
                                 in_blocking_mode) == -1)
    return -1;
  else
    {
      // On Win32 the third parameter to <accept> must be a NULL
      // pointer if we want to ignore the client's address.
      int *len_ptr = 0;
      sockaddr *addr = 0;
      int len = 0;
      if (remote_addr != 0)
        {
          len = remote_addr->get_size ();
          len_ptr = &len;
          addr = (sockaddr *) remote_addr->get_addr ();
        }
      do
        new_association.set_handle (ACE_OS::accept (this->get_handle (),
                                               addr,
                                               len_ptr));
      while (new_association.get_handle () == ACE_INVALID_HANDLE
             && restart != 0
             && errno == EINTR
             && timeout == 0);
      // Reset the size of the addr, so the proper UNIX/IPv4/IPv6 family
      // is known.
      if (new_association.get_handle () != ACE_INVALID_HANDLE
          && remote_addr != 0)
        {
          remote_addr->set_size (len);
          remote_addr->set_type (addr->sa_family);
        }
    }
  return this->shared_accept_finish (new_association,
                                     in_blocking_mode,
                                     reset_new_handle);
}
void
ACE_SOCK_SEQPACK_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::dump");
#endif /* ACE_HAS_DUMP */
}
int
ACE_SOCK_SEQPACK_Acceptor::shared_open (const ACE_Addr &local_sap,
                                int protocol_family,
                                int backlog)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::shared_open");
  int error = 0;
#if defined (ACE_HAS_IPV6)
  ACE_ASSERT (protocol_family == PF_INET || protocol_family == PF_INET6);
  if (protocol_family == PF_INET6)
    {
      sockaddr_in6 local_inet6_addr;
      ACE_OS::memset (reinterpret_cast<void *> (&local_inet6_addr),
                      0,
                      sizeof local_inet6_addr);
      if (local_sap == ACE_Addr::sap_any)
        {
          local_inet6_addr.sin6_family = AF_INET6;
          local_inet6_addr.sin6_port = 0;
          local_inet6_addr.sin6_addr = in6addr_any;
        }
      else
        local_inet6_addr = *reinterpret_cast<sockaddr_in6 *> (local_sap.get_addr ());
      // We probably don't need a bind_port written here.
      // There are currently no supported OS's that define
      // ACE_LACKS_WILDCARD_BIND.
      if (ACE_OS::bind (this->get_handle (),
                        reinterpret_cast<sockaddr *> (&local_inet6_addr),
                        sizeof local_inet6_addr) == -1)
        error = 1;
    }
  else
#endif
  if (protocol_family == PF_INET)
    {
      sockaddr_in local_inet_addr;
      ACE_OS::memset (reinterpret_cast<void *> (&local_inet_addr),
                      0,
                      sizeof local_inet_addr);
      if (local_sap == ACE_Addr::sap_any)
        {
          local_inet_addr.sin_port = 0;
        }
      else
        local_inet_addr = *reinterpret_cast<sockaddr_in *> (local_sap.get_addr ());
      if (local_inet_addr.sin_port == 0)
        {
          if (ACE::bind_port (this->get_handle ()) == -1)
            error = 1;
        }
      else if (ACE_OS::bind (this->get_handle (),
                             reinterpret_cast<sockaddr *> (&local_inet_addr),
                             sizeof local_inet_addr) == -1)
        error = 1;
    }
  else if (ACE_OS::bind (this->get_handle (),
                         (sockaddr *) local_sap.get_addr (),
                         local_sap.get_size ()) == -1)
    error = 1;
  if (error != 0
      || ACE_OS::listen (this->get_handle (),
                         backlog) == -1)
    {
      error = 1;
      this->close ();
    }
  return error ? -1 : 0;
}
// Multihomed version of same.
int
ACE_SOCK_SEQPACK_Acceptor::shared_open (const ACE_Multihomed_INET_Addr &local_sap,
                                        int protocol_family,
                                        int backlog)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::shared_open");
  int error = 0;
  // TODO: Add multi-address support to IPV6
#if defined (ACE_HAS_IPV6)
  ACE_ASSERT (protocol_family == PF_INET || protocol_family == PF_INET6);
  if (protocol_family == PF_INET6)
    {
      sockaddr_in6 local_inet6_addr;
      ACE_OS::memset (reinterpret_cast<void *> (&local_inet6_addr),
                      0,
                      sizeof local_inet6_addr);
      if (local_sap.ACE_Addr::operator== (ACE_Addr::sap_any))
        {
          local_inet6_addr.sin6_family = AF_INET6;
          local_inet6_addr.sin6_port = 0;
          local_inet6_addr.sin6_addr = in6addr_any;
        }
      else
        local_inet6_addr = *reinterpret_cast<sockaddr_in6 *> (local_sap.get_addr ());
      // We probably don't need a bind_port written here.
      // There are currently no supported OS's that define
      // ACE_LACKS_WILDCARD_BIND.
      if (ACE_OS::bind (this->get_handle (),
                        reinterpret_cast<sockaddr *> (&local_inet6_addr),
                        sizeof local_inet6_addr) == -1)
        error = 1;
    }
  else
#endif
  if (protocol_family == PF_INET)
    {
      sockaddr_in local_inet_addr;
      ACE_OS::memset (reinterpret_cast<void *> (&local_inet_addr),
                      0,
                      sizeof local_inet_addr);
      if (local_sap.ACE_Addr::operator== (ACE_Addr::sap_any))
        {
          local_inet_addr.sin_port = 0;
        }
      else
        local_inet_addr = *reinterpret_cast<sockaddr_in *> (local_sap.get_addr ());
//  A port number of 0 means that the user is requesting that the
//  operating system choose an arbitrary, unused port.  Since some
//  operating systems don't provide this service, ACE provides an
//  emulation layer.  Therefore, the "ACE way" to bind an arbitrary,
//  unused port is to call ACE:bind_port, which either
//
//    (1)  Calls ACE_OS::bind with port 0, if the operating system
//         directly supports the automated selection, or
//
//    (2)  Performs more complicated logic to emulate this feature if
//         it's missing from the OS.
//
//  The emulation logic in choice (2) is compiled if and only if
//  ACE_LACKS_WILDCARD_BIND is defined at compile time.
//
//  Along these lines, the following block of code seems like it would
//  be sufficient to support the wildcard bind operation:
//
//      if (local_inet_addr.sin_port == 0)
//         {
//           if (ACE::bind_port (this->get_handle (),
//               ACE_NTOHL (ACE_UINT32 (local_inet_addr.sin_addr.s_addr))) == -1)
//             error = 1;
//
//         }
//      else
//
//  Unfortunately, this code is insufficient because it does not
//  address the possibility of secondary addresses.
//
//  However, rather than writing the correct code now, I'm putting it
//  off, because this class, ACE_SOCK_SEQPACK_Acceptor, is currently
//  only used with SCTP, and ACE currently supports SCTP only through
//  the OpenSS7 and LKSCTP implmentations, which are available only on
//  Linux.  Linux has native support for the wildcard bind, so the
//  following code works regardless of whether or not the port is 0.
        {
          // The total number of addresses is the number of secondary
          // addresses plus one.
          size_t num_addresses = local_sap.get_num_secondary_addresses() + 1;
          // Create an array of sockaddr_in to hold the underlying
          // representations of the primary and secondary
          // addresses.
          sockaddr_in*  local_inet_addrs = 0;
          ACE_NEW_NORETURN (local_inet_addrs,
                            sockaddr_in[num_addresses]);
          if (!local_inet_addrs)
            error = 1;
          else
            {
              // Populate the array by invoking the get_addresses method
              // on the Multihomed_INET_Addr
              local_sap.get_addresses(local_inet_addrs,
                                      num_addresses);
#if defined (ACE_HAS_LKSCTP)
              sockaddr_in *local_sockaddr = 0;
              // bind the primary first
              if (ACE_OS::bind (this->get_handle (),
                                reinterpret_cast<sockaddr *> (&(local_inet_addrs[0])),
                                sizeof(sockaddr)) == -1)
              {
                error = 1;
              }
              // do we need to bind multiple addresses?
              if (num_addresses > 1)
              {
                ACE_NEW_NORETURN(local_sockaddr,
                               sockaddr_in[num_addresses - 1]);
                // all of the secondary addresses need the local port set
                for (size_t i = 1; i < num_addresses; i++)
                {
                  local_inet_addrs[i].sin_port = local_inet_addrs[0].sin_port;
                }
                // copy only the sockaddrs that we need to bindx
                for (size_t i = 0; i < num_addresses - 1; i++)
                {
                  ACE_OS::memcpy(&(local_sockaddr[i]),
                                 &(local_inet_addrs[i + 1]),
                                 sizeof(sockaddr_in));
                }
                // now call bindx
                if (!error && sctp_bindx(this->get_handle (),
                                         reinterpret_cast<sockaddr *> (local_sockaddr),
                                         num_addresses - 1,
                                         SCTP_BINDX_ADD_ADDR))
                {
                  error = 1;
                }
                delete [] local_sockaddr;
              }
#else
              // Call bind
              size_t name_len = (sizeof local_inet_addr) * num_addresses;
              if (ACE_OS::bind (this->get_handle (),
                                reinterpret_cast<sockaddr *> (local_inet_addrs),
                                static_cast<int> (name_len)) == -1)
                error = 1;
#endif /* ACE_HAS_LKSCTP */
            }
          delete [] local_inet_addrs;
        }
    }
  else if (ACE_OS::bind (this->get_handle (),
                         (sockaddr *) local_sap.get_addr (),
                         local_sap.get_size ()) == -1)
    error = 1;
  if (error != 0
      || ACE_OS::listen (this->get_handle (),
                         backlog) == -1)
    {
      error = 1;
      this->close ();
    }
  return error ? -1 : 0;
}
int
ACE_SOCK_SEQPACK_Acceptor::open (const ACE_Addr &local_sap,
                         ACE_Protocol_Info *protocolinfo,
                         ACE_SOCK_GROUP g,
                         u_long flags,
                         int reuse_addr,
                         int protocol_family,
                         int backlog,
                         int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::open");
  if (protocol_family == PF_UNSPEC)
    protocol_family = local_sap.get_type ();
#if defined (ACE_HAS_LKSCTP)
  if (ACE_SOCK::open (SOCK_STREAM,
#else
  if (ACE_SOCK::open (SOCK_SEQPACKET,
#endif
                      protocol_family,
                      protocol,
                      protocolinfo,
                      g,
                      flags,
                      reuse_addr) == -1)
    return -1;
  else
    return this->shared_open (local_sap,
                              protocol_family,
                              backlog);
}
ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor (const ACE_Addr &local_sap,
                                      ACE_Protocol_Info *protocolinfo,
                                      ACE_SOCK_GROUP g,
                                      u_long flags,
                                      int reuse_addr,
                                      int protocol_family,
                                      int backlog,
                                      int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor");
  if (this->open (local_sap,
                  protocolinfo,
                  g,
                  flags,
                  reuse_addr,
                  protocol_family,
                  backlog,
                  protocol) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_SEQPACK_Acceptor")));
}
// General purpose routine for performing server ACE_SOCK creation.
int
ACE_SOCK_SEQPACK_Acceptor::open (const ACE_Addr &local_sap,
                         int reuse_addr,
                         int protocol_family,
                         int backlog,
                         int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::open");
  if (local_sap != ACE_Addr::sap_any)
    protocol_family = local_sap.get_type ();
  else if (protocol_family == PF_UNSPEC)
    {
#if defined (ACE_HAS_IPV6)
      protocol_family = ACE::ipv6_enabled () ? PF_INET6 : PF_INET;
#else
      protocol_family = PF_INET;
#endif /* ACE_HAS_IPV6 */
    }
#if defined (ACE_HAS_LKSCTP)
  if (ACE_SOCK::open (SOCK_STREAM,
#else
  if (ACE_SOCK::open (SOCK_SEQPACKET,
#endif
                      protocol_family,
                      protocol,
                      reuse_addr) == -1)
    return -1;
  else
    return this->shared_open (local_sap,
                              protocol_family,
                              backlog);
}
// Multihomed version of same.
int
ACE_SOCK_SEQPACK_Acceptor::open (const ACE_Multihomed_INET_Addr &local_sap,
                         int reuse_addr,
                         int protocol_family,
                         int backlog,
                         int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::open");
  if (local_sap.ACE_Addr::operator!= (ACE_Addr::sap_any))
    protocol_family = local_sap.get_type ();
  else if (protocol_family == PF_UNSPEC)
    {
#if defined (ACE_HAS_IPV6)
      protocol_family = ACE::ipv6_enabled () ? PF_INET6 : PF_INET;
#else
      protocol_family = PF_INET;
#endif /* ACE_HAS_IPV6 */
    }
#if defined (ACE_HAS_LKSCTP)
  if (ACE_SOCK::open (SOCK_STREAM,
#else
  if (ACE_SOCK::open (SOCK_SEQPACKET,
#endif
                      protocol_family,
                      protocol,
                      reuse_addr) == -1)
    return -1;
  else
    return this->shared_open (local_sap,
                              protocol_family,
                              backlog);
}
// General purpose routine for performing server ACE_SOCK creation.
ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor (const ACE_Addr &local_sap,
                                      int reuse_addr,
                                      int protocol_family,
                                      int backlog,
                                      int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor");
  if (this->open (local_sap,
                  reuse_addr,
                  protocol_family,
                  backlog,
                  protocol) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_SEQPACK_Acceptor")));
}
// Multihomed version of same.
ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor (const ACE_Multihomed_INET_Addr &local_sap,
                                      int reuse_addr,
                                      int protocol_family,
                                      int backlog,
                                      int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Acceptor::ACE_SOCK_SEQPACK_Acceptor");
  if (this->open (local_sap,
                  reuse_addr,
                  protocol_family,
                  backlog,
                  protocol) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_SEQPACK_Acceptor")));
}
int
ACE_SOCK_SEQPACK_Acceptor::close (void)
{
  return ACE_SOCK::close ();
}
ACE_END_VERSIONED_NAMESPACE_DECL

