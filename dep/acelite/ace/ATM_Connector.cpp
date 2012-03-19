// ATM_Connector.cpp
// $Id: ATM_Connector.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/ATM_Connector.h"
#if defined (ACE_HAS_ATM)

#include "ace/Handle_Set.h"



#if !defined (__ACE_INLINE__)
#include "ace/ATM_Connector.inl"
#endif /* __ACE_INLINE__ */

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_ATM_Connector)

ACE_ATM_Connector::ACE_ATM_Connector (void)
{
  ACE_TRACE ("ACE_ATM_Connector::ACE_ATM_Connector");
}

// Actively connect and produce a new ACE_ATM_Stream if things go well...
// Connect the <new_stream> to the <remote_sap>, waiting up to
// <timeout> amount of time if necessary.

int
ACE_ATM_Connector::connect (ACE_ATM_Stream &new_stream,
                            const ACE_ATM_Addr &remote_sap,
                            ACE_ATM_Params params,
                            ACE_ATM_QoS options,
                            ACE_Time_Value *timeout,
                            const ACE_ATM_Addr &local_sap,
                            int reuse_addr,
                            int flags,
                            int perms)
{
  ACE_TRACE ("ACE_ATM_Connector::connect");
#if defined (ACE_HAS_FORE_ATM_XTI)
  return connector_.connect(new_stream.get_stream(),
                            remote_sap,
                            timeout,
                            local_sap,
                            reuse_addr,
                            flags,
                            perms,
                            params.get_device(),
                            params.get_info(),
                            params.get_rw_flag(),
                            params.get_user_data(),
                            &options.get_qos());
#elif defined (ACE_HAS_FORE_ATM_WS2)
  ACE_DEBUG(LM_DEBUG,
            ACE_TEXT ("ATM_Connector(connect): set QoS parameters\n" ));

  ACE_HANDLE s = new_stream.get_handle();
  struct sockaddr_atm *saddr = ( struct sockaddr_atm *)remote_sap.get_addr();
  ACE_QoS cqos = options.get_qos();

  ACE_QoS_Params qos_params = ACE_QoS_Params(0,
                                             0,
                                             &cqos,
                                             0,
                                             0);

  ACE_DEBUG(LM_DEBUG,
            ACE_TEXT ("ATM_Connector(connect): connecting...\n"));

  int result = ACE_OS::connect( s,
                                ( struct sockaddr *)saddr,
                                sizeof( struct sockaddr_atm ),
                                qos_params );

  if ( result != 0 )
    ACE_OS::printf( "ATM_Connector(connect): connection failed, %d\n",
                    ::WSAGetLastError());

  return result;
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_UNUSED_ARG (params);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (reuse_addr);
  ACE_UNUSED_ARG (perms);
  ACE_UNUSED_ARG (flags);

  ACE_HANDLE handle = new_stream.get_handle();
  ATM_QoS qos =options.get_qos();
  ATM_Addr *local_addr=(ATM_Addr*)local_sap.get_addr(),
    *remote_addr=(ATM_Addr*)remote_sap.get_addr();

  if (ACE_OS::setsockopt(handle,
                         SOL_ATM,
                         SO_ATMSAP,
                         reinterpret_cast<char*> (&(local_addr->atmsap)),
                         sizeof(local_addr->atmsap)) < 0) {
    ACE_OS::printf( "ATM_Connector(connect): unable to set atmsap %d\nContinuing...",
                    errno);
  }
  if (ACE_OS::setsockopt(handle,
                         SOL_ATM,
                         SO_ATMQOS,
                         reinterpret_cast<char*> (&qos),
                         sizeof(qos)) < 0) {
    ACE_DEBUG((LM_DEBUG,ACE_TEXT ("ATM_Connector(connect): unable to set qos %d\n"),
               errno));
    return -1;
  }

  int result = ACE_OS::connect(handle,
                               (struct sockaddr *)&(remote_addr->sockaddratmsvc),
                               sizeof( remote_addr->sockaddratmsvc));

  if ( result != 0 )
    ACE_DEBUG(LM_DEBUG,
              ACE_TEXT ("ATM_Connector(connect): connection failed, %d\n"),
              errno);

  return result;
#else
  ACE_UNUSED_ARG (new_stream);
  ACE_UNUSED_ARG (remote_sap);
  ACE_UNUSED_ARG (params);
  ACE_UNUSED_ARG (options);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (local_sap);
  ACE_UNUSED_ARG (reuse_addr);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (perms);
  return 0;
#endif /* ACE_HAS_FORE_ATM_XTI || ACE_HAS_FORE_ATM_WS2 || ACE_HAS_LINUX_ATM */
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_ATM */
