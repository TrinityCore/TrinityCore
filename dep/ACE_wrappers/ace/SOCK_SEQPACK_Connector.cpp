// $Id: SOCK_SEQPACK_Connector.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/SOCK_SEQPACK_Connector.h"

#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"
#include "ace/Time_Value.h"
#include "ace/OS_Memory.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/os_include/os_fcntl.h"

#if defined (ACE_WIN32)
#include "ace/OS_NS_unistd.h"
#endif /* ACE_WIN32 */

#if !defined (__ACE_INLINE__)
#include "ace/SOCK_SEQPACK_Connector.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, SOCK_SEQPACK_Connector, "SOCK_SEQPACK_Connector.cpp,v 4.35 2002/03/08 23:18:09 spark Exp")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_SEQPACK_Connector)

void
ACE_SOCK_SEQPACK_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::dump");
#endif /* ACE_HAS_DUMP */
}

int
ACE_SOCK_SEQPACK_Connector::shared_open (ACE_SOCK_SEQPACK_Association &new_association,
                                 int protocol_family,
                                 int protocol,
                                 int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::shared_open");

  // Only open a new socket if we don't already have a valid handle.
  if (new_association.get_handle () == ACE_INVALID_HANDLE &&
#if defined (ACE_HAS_LKSCTP)
         new_association.open (SOCK_STREAM,
#else
         new_association.open (SOCK_SEQPACKET,
#endif /* ACE_HAS_LKSCTP */
                               protocol_family,
                               protocol,
                               reuse_addr) == -1)
    return -1;
  else
    return 0;
}

int
ACE_SOCK_SEQPACK_Connector::shared_open (ACE_SOCK_SEQPACK_Association &new_association,
                                 int protocol_family,
                                 int protocol,
                                 ACE_Protocol_Info *protocolinfo,
                                 ACE_SOCK_GROUP g,
                                 u_long flags,
                                 int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::shared_open");

  // Only open a new socket if we don't already have a valid handle.
  if (new_association.get_handle () == ACE_INVALID_HANDLE &&
#if defined (ACE_HAS_LKSCTP)
      new_association.open (SOCK_STREAM,
#else
      new_association.open (SOCK_SEQPACKET,
#endif /* ACE_HAS_LKSCTP */
                               protocol_family,
                               protocol,
                               protocolinfo,
                               g,
                               flags,
                               reuse_addr) == -1)
      return -1;
  else
    return 0;
}

int
ACE_SOCK_SEQPACK_Connector::shared_connect_start (ACE_SOCK_SEQPACK_Association &new_association,
                                          const ACE_Time_Value *timeout,
                                          const ACE_Addr &local_sap)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::shared_connect_start");

  if (local_sap != ACE_Addr::sap_any)
    {
      sockaddr *laddr = reinterpret_cast<sockaddr *> (local_sap.get_addr ());
      int size = local_sap.get_size ();

      if (ACE_OS::bind (new_association.get_handle (),
                        laddr,
                        size) == -1)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          new_association.close ();
          return -1;
        }
    }

  // Enable non-blocking, if required.
  if (timeout != 0
      && new_association.enable (ACE_NONBLOCK) == -1)
    return -1;
  else
    return 0;
}

// Multihomed version of same
int
ACE_SOCK_SEQPACK_Connector::shared_connect_start (ACE_SOCK_SEQPACK_Association &new_association,
                                          const ACE_Time_Value *timeout,
                                          const ACE_Multihomed_INET_Addr &local_sap)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::shared_connect_start");

  if (local_sap.ACE_Addr::operator!= (ACE_Addr::sap_any))
    {
      // The total number of addresses is the number of secondary
      // addresses plus one.
      size_t num_addresses = local_sap.get_num_secondary_addresses() + 1;

      // Create an array of sockaddr_in to hold the underlying
      // representations of the primary and secondary
      // addresses.
      sockaddr_in*  local_inet_addrs = 0;
      ACE_NEW_NORETURN (local_inet_addrs, sockaddr_in[num_addresses]);
      if (!local_inet_addrs)
        return -1;

      // Populate the array by invoking the get_addresses method on
      // the Multihomed_INET_Addr
      local_sap.get_addresses(local_inet_addrs, num_addresses);

#if defined (ACE_HAS_LKSCTP)
      sockaddr_in *local_sockaddr = 0;
      sockaddr_in portst;
      int sn = sizeof(sockaddr);

      // bind to the primary addr first
      if (ACE_OS::bind(new_association.get_handle (),
                       reinterpret_cast<sockaddr *> (&(local_inet_addrs[0])),
                       sizeof(sockaddr)))
      {
        ACE_Errno_Guard error (errno);
        new_association.close ();
        return -1;
      }

      // do we need to bind multiple addrs
      if (num_addresses > 1)
      {
        // allocate enough memory to hold the number of secondary addrs
        ACE_NEW_NORETURN(local_sockaddr,
                         sockaddr_in[num_addresses - 1]);

        // get sockaddr_in for the local handle
        if (ACE_OS::getsockname(new_association.get_handle (),
                                reinterpret_cast<sockaddr *> (&portst),
                                                     &sn))
        {
          ACE_Errno_Guard error (errno);
          new_association.close ();
          return -1;
        }

        // set the local port # assigned by the os to every secondary addr
        for (size_t i = 1; i < num_addresses; i++)
        {
          local_inet_addrs[i].sin_port = portst.sin_port;
        }

        // copy all of the secondary addrs into a sockaddr structure
        for (size_t i = 0; i < num_addresses - 1; i++)
        {
          ACE_OS::memcpy(&(local_sockaddr[i]),
                         &(local_inet_addrs[i + 1]),
                         sizeof(sockaddr_in));
        }

        // bind other ifaces
        if (sctp_bindx(new_association.get_handle(),
                       reinterpret_cast<sockaddr *> (local_sockaddr),
                       num_addresses - 1,
                       SCTP_BINDX_ADD_ADDR))
        {
          ACE_Errno_Guard error (errno);
          new_association.close ();
          return -1;
        }

        delete [] local_sockaddr;
      }
#else

      // Call bind
      size_t name_len = (sizeof (sockaddr_in)) * num_addresses;
      if (ACE_OS::bind (new_association.get_handle (),
                        reinterpret_cast<sockaddr *> (local_inet_addrs),
                        static_cast<int> (name_len)) == -1)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          new_association.close ();
          return -1;
        }
#endif /* ACE_HAS_LKSCTP */

      delete [] local_inet_addrs;
    }

  // Enable non-blocking, if required.
  if (timeout != 0
      && new_association.enable (ACE_NONBLOCK) == -1)
    return -1;
  else
    return 0;
}

int
ACE_SOCK_SEQPACK_Connector::shared_connect_finish (ACE_SOCK_SEQPACK_Association &new_association,
                                           const ACE_Time_Value *timeout,
                                           int result)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::shared_connect_finish");
  // Save/restore errno.
  ACE_Errno_Guard error (errno);

  if (result == -1 && timeout != 0)
    {
      // Check whether the connection is in progress.
      if (error == EINPROGRESS || error == EWOULDBLOCK)
        {
          // This expression checks if we were polling.
          if (timeout->sec () == 0
              && timeout->usec () == 0)
            error = EWOULDBLOCK;
          // Wait synchronously using timeout.
          else if (this->complete (new_association,
                                   0,
                                   timeout) == -1)
            error = errno;
          else
            return 0;
        }
    }

  // EISCONN is treated specially since this routine may be used to
  // check if we are already connected.
  if (result != -1 || error == EISCONN)
    // Start out with non-blocking disabled on the <new_association>.
    new_association.disable (ACE_NONBLOCK);
  else if (!(error == EWOULDBLOCK || error == ETIMEDOUT))
    new_association.close ();

  return result;
}

// Actively connect and produce a new ACE_SOCK_SEQPACK_Association if things go well...

int
ACE_SOCK_SEQPACK_Connector::connect (ACE_SOCK_SEQPACK_Association &new_association,
                             const ACE_Addr &remote_sap,
                             const ACE_Time_Value *timeout,
                             const ACE_Addr &local_sap,
                             int reuse_addr,
                             int /* flags */,
                             int /* perms */,
                             int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::connect");

  if (this->shared_open (new_association,
                         remote_sap.get_type (),
                         protocol,
                         reuse_addr) == -1)
    return -1;
  else if (this->shared_connect_start (new_association,
                                       timeout,
                                       local_sap) == -1)
    return -1;

  int result = ACE_OS::connect (new_association.get_handle (),
                                reinterpret_cast<sockaddr *> (remote_sap.get_addr ()),
                                remote_sap.get_size ());

  return this->shared_connect_finish (new_association,
                                      timeout,
                                      result);
}

// Multihomed version of same
int
ACE_SOCK_SEQPACK_Connector::connect (ACE_SOCK_SEQPACK_Association &new_association,
                             const ACE_Addr &remote_sap,
                             const ACE_Time_Value *timeout,
                             const ACE_Multihomed_INET_Addr &local_sap,
                             int reuse_addr,
                             int /* flags */,
                             int /* perms */,
                             int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::connect");

  if (this->shared_open (new_association,
                         remote_sap.get_type (),
                         protocol,
                         reuse_addr) == -1)
    return -1;
  else if (this->shared_connect_start (new_association,
                                       timeout,
                                       local_sap) == -1)
    return -1;

  int result = ACE_OS::connect (new_association.get_handle (),
                                reinterpret_cast<sockaddr *> (remote_sap.get_addr ()),
                                remote_sap.get_size ());

  return this->shared_connect_finish (new_association,
                                      timeout,
                                      result);
}

// Try to complete a non-blocking connection.

int
ACE_SOCK_SEQPACK_Connector::complete (ACE_SOCK_SEQPACK_Association &new_association,
                              ACE_Addr *remote_sap,
                              const ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::complete");
  ACE_HANDLE h = ACE::handle_timed_complete (new_association.get_handle (),
                                             tv);
  // We failed to get connected.
  if (h == ACE_INVALID_HANDLE)
    {
#if defined (ACE_WIN32)
      // Win32 has a timing problem - if you check to see if the
      // connection has completed too fast, it will fail - so wait
      // <ACE_NON_BLOCKING_BUG_DELAY> microseconds to let it catch up
      // then retry to see if it's a real failure.
      ACE_Time_Value time (0, ACE_NON_BLOCKING_BUG_DELAY);
      ACE_OS::sleep (time);
      h = ACE::handle_timed_complete (new_association.get_handle (),
                                      tv);
      if (h == ACE_INVALID_HANDLE)
        {
#endif /* ACE_WIN32 */
      // Save/restore errno.
      ACE_Errno_Guard error (errno);
      new_association.close ();
      return -1;
#if defined (ACE_WIN32)
        }
#endif /* ACE_WIN32 */
    }

  if (remote_sap != 0)
    {
      int len = remote_sap->get_size ();
      sockaddr *addr = reinterpret_cast<sockaddr *> (remote_sap->get_addr ());
      if (ACE_OS::getpeername (h,
                               addr,
                               &len) == -1)
        {
          // Save/restore errno.
          ACE_Errno_Guard error (errno);
          new_association.close ();
          return -1;
        }
    }

  // Start out with non-blocking disabled on the <new_association>.
  new_association.disable (ACE_NONBLOCK);
  return 0;
}

ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector (ACE_SOCK_SEQPACK_Association &new_association,
                                        const ACE_Addr &remote_sap,
                                        const ACE_Time_Value *timeout,
                                        const ACE_Addr &local_sap,
                                        int reuse_addr,
                                        int flags,
                                        int perms,
                                        int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector");

  if (this->connect (new_association,
                     remote_sap,
                     timeout,
                     local_sap,
                     reuse_addr,
                     flags,
                     perms,
                     protocol) == -1
      && timeout != 0
      && !(errno == EWOULDBLOCK || errno == ETIME || errno == ETIMEDOUT))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector")));
}

// Multihomed version of same
ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector (ACE_SOCK_SEQPACK_Association &new_association,
                                        const ACE_Addr &remote_sap,
                                        const ACE_Time_Value *timeout,
                                        const ACE_Multihomed_INET_Addr &local_sap,
                                        int reuse_addr,
                                        int flags,
                                        int perms,
                                        int protocol)
{
  ACE_TRACE ("ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector");

  if (this->connect (new_association,
                     remote_sap,
                     timeout,
                     local_sap,
                     reuse_addr,
                     flags,
                     perms,
                     protocol) == -1
      && timeout != 0
      && !(errno == EWOULDBLOCK || errno == ETIME || errno == ETIMEDOUT))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SOCK_SEQPACK_Connector::ACE_SOCK_SEQPACK_Connector")));
}

ACE_END_VERSIONED_NAMESPACE_DECL

