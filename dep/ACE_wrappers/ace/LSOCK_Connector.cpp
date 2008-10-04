// $Id: LSOCK_Connector.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/LSOCK_Connector.h"
#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#include "ace/Log_Msg.h"

ACE_RCSID(ace, LSOCK_Connector, "$Id: LSOCK_Connector.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (__ACE_INLINE__)
#include "ace/LSOCK_Connector.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_LSOCK_Connector)

void
ACE_LSOCK_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_LSOCK_Connector::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_LSOCK_Connector::ACE_LSOCK_Connector (void)
{
  ACE_TRACE ("ACE_LSOCK_Connector::ACE_LSOCK_Connector");
}

// Establish a connection.
ACE_LSOCK_Connector::ACE_LSOCK_Connector (ACE_LSOCK_Stream &new_stream,
                                          const ACE_UNIX_Addr &remote_sap,
                                          ACE_Time_Value *timeout,
                                          const ACE_Addr &local_sap,
                                          int reuse_addr,
                                          int flags,
                                          int perms)
  : ACE_SOCK_Connector (new_stream,
                        remote_sap,
                        timeout,
                        local_sap,
                        reuse_addr,
                        flags,
                        perms)
{
  ACE_TRACE ("ACE_LSOCK_Connector::ACE_LSOCK_Connector");
  // This is necessary due to the weird inheritance relationships of
  // ACE_LSOCK_Stream.
  new_stream.set_handle (new_stream.get_handle ());
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */
