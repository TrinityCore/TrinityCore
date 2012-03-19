// $Id: SOCK_CODgram.cpp 91287 2010-08-05 10:30:49Z johnnyw $

#include "ace/SOCK_CODgram.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_socket.h"

#if !defined (__ACE_INLINE__)
#include "ace/SOCK_CODgram.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SOCK_CODgram)

void
ACE_SOCK_CODgram::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SOCK_CODgram::dump");
#endif /* ACE_HAS_DUMP */
}

// Here's the general-purpose constructor.

ACE_SOCK_CODgram::ACE_SOCK_CODgram (const ACE_Addr &remote,
                                    const ACE_Addr &local,
                                    int protocol_family,
                                    int protocol,
                                    int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_CODgram::ACE_SOCK_CODgram");
  if (this->open (remote,
                  local,
                  protocol_family,
                  protocol,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"), ACE_TEXT ("ACE_SOCK_CODgram")));
}

/* This is the general-purpose open routine.  Note that it performs
   a different set of functions depending on the LOCAL and REMOTE
   addresses passed to it.  Here's the basic logic:

   1. remote == ACE_Addr::sap_any && local == ACE_Addr::sap_any
         if protocol_family == PF_INET || PF_INET6 then
             bind the local address to a randomly generated port number...

   2. remote == ACE_Addr::sap_any && local != ACE_Addr::sap_any
         we are just binding the local address
         (used primarily by servers)

   3. remote != ACE_Addr::sap_any && local == ACE_Addr::sap_any
         we are connecting to the remote address
         (used primarily by clients)

   4. remote != ACE_Addr::sap_any && local != ACE_Addr::sap_any
         we are binding to the local address
         and connecting to the remote address
*/

int
ACE_SOCK_CODgram::open (const ACE_Addr &remote, const ACE_Addr &local,
                        int protocol_family, int protocol,
                        int reuse_addr)
{
  ACE_TRACE ("ACE_SOCK_CODgram::open");
  // Depending on the addresses passed as described above, figure out what
  // address family to specify for the new socket. If either address is
  // !ACE_Addr::sap_any, use that family. If they don't match, it's an error.
  if (remote != ACE_Addr::sap_any)
    {
      if (local == ACE_Addr::sap_any)
        protocol_family = remote.get_type ();
      else
        { // Both specified; family must match
          if (local.get_type () != remote.get_type ())
            {
              errno = EAFNOSUPPORT;
              return -1;
            }
          protocol_family = remote.get_type ();
        }
    }
  else
    {
      if (local != ACE_Addr::sap_any)
        {
          protocol_family = local.get_type ();
        }
    }
  if (ACE_SOCK::open (SOCK_DGRAM,
                      protocol_family,
                      protocol,
                      reuse_addr) == -1)
    {
      return -1;
    }
  else
    {
      bool error = false;

      if (local == ACE_Addr::sap_any && remote == ACE_Addr::sap_any)
        {
          // Assign an arbitrary port number from the transient range!!
          if ((protocol_family == PF_INET
#if defined (ACE_HAS_IPV6)
               || protocol_family == PF_INET6
#endif /* ACE_HAS_IPV6 */
              ) && ACE::bind_port (this->get_handle ()) == -1)
            error = true;
        }
      // We are binding just the local address.
      else if (local != ACE_Addr::sap_any && remote == ACE_Addr::sap_any)
        {
          if (ACE_OS::bind (this->get_handle (),
                            (sockaddr *) local.get_addr (),
                            local.get_size ()) == -1)
            error = true;
        }
      // We are connecting to the remote address.
      else if (local == ACE_Addr::sap_any && remote != ACE_Addr::sap_any)
        {
          if (ACE_OS::connect (this->get_handle (),
                               (sockaddr *) remote.get_addr (),
                               remote.get_size ()) == -1)
            error = true;
        }
      // We are binding to the local address and connecting to the
      // remote addresses.
      else
        {
          if (ACE_OS::bind (this->get_handle (),
                            (sockaddr *) local.get_addr (),
                            local.get_size ()) == -1
              || ACE_OS::connect (this->get_handle (),
                                  (sockaddr *) remote.get_addr (),
                                  remote.get_size ()) == -1)
            error = true;
        }
      if (error)
        {
          this->close ();
          this->set_handle (ACE_INVALID_HANDLE);
        }
      return error ? -1 : 0;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
