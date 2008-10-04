// $Id: LSOCK_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/LSOCK_Acceptor.h"

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/Log_Msg.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_socket.h"

ACE_RCSID(ace, LSOCK_Acceptor, "$Id: LSOCK_Acceptor.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_LSOCK_Acceptor)

// Return the local endpoint address.

int
ACE_LSOCK_Acceptor::get_local_addr (ACE_Addr &a) const
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::get_local_addr");

  ACE_UNIX_Addr& target = dynamic_cast<ACE_UNIX_Addr &> (a);

  target = this->local_addr_;

  return 0;
}

void
ACE_LSOCK_Acceptor::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_LSOCK_Acceptor::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->local_addr_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Do nothing routine for constructor.

ACE_LSOCK_Acceptor::ACE_LSOCK_Acceptor (void)
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::ACE_LSOCK_Acceptor");
}

int
ACE_LSOCK_Acceptor::open (const ACE_Addr &remote_sap,
                          int reuse_addr,
                          int protocol_family,
                          int backlog,
                          int protocol)
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::open");
  this->local_addr_ = *((ACE_UNIX_Addr *) &remote_sap); // This is a gross hack...
  return ACE_SOCK_Acceptor::open (remote_sap, reuse_addr,
                                  protocol_family, backlog, protocol);
}

// General purpose routine for performing server ACE_SOCK creation.

ACE_LSOCK_Acceptor::ACE_LSOCK_Acceptor (const ACE_Addr &remote_sap,
                                        int reuse_addr,
                                        int protocol_family,
                                        int backlog,
                                        int protocol)
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::ACE_LSOCK_Acceptor");
  if (this->open (remote_sap,
                  reuse_addr,
                  protocol_family,
                  backlog,
                  protocol) == -1)
    ACE_ERROR ((LM_ERROR,
                "ACE_LSOCK_Acceptor::ACE_LSOCK_Acceptor"));
}

// General purpose routine for accepting new connections.

int
ACE_LSOCK_Acceptor::accept (ACE_LSOCK_Stream &new_stream,
                            ACE_Addr *remote_addr,
                            ACE_Time_Value *timeout,
                            int restart,
                            int reset_new_handle) const
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::accept");

  int in_blocking_mode = 0;
  if (this->shared_accept_start (timeout,
                                 restart,
                                 in_blocking_mode) == -1)
    return -1;
  else
    {
      sockaddr *addr = 0;
      int len = 0;

      if (remote_addr != 0)
        {
          len = remote_addr->get_size ();
          addr = (sockaddr *) remote_addr->get_addr ();
        }

      do
        new_stream.set_handle (ACE_OS::accept (this->get_handle (),
                                               addr,
                                               &len));
      while (new_stream.get_handle () == ACE_INVALID_HANDLE
             && restart != 0
             && errno == EINTR
             && timeout == 0);

      // Reset the size of the addr, which is only necessary for UNIX
      // domain sockets.
      if (new_stream.get_handle () != ACE_INVALID_HANDLE
          && remote_addr != 0)
        remote_addr->set_size (len);
    }

  return this->shared_accept_finish (new_stream,
                                     in_blocking_mode,
                                     reset_new_handle);
}

// Close down the UNIX domain stream and remove the rendezvous point
// from the file system.

int
ACE_LSOCK_Acceptor::remove (void)
{
  ACE_TRACE ("ACE_LSOCK_Acceptor::remove");
  int result = this->close ();
  return ACE_OS::unlink (this->local_addr_.get_path_name ()) == -1
    || result == -1 ? -1 : 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
