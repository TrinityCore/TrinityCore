// -*- C++ -*-
//
// $Id: ATM_Connector.inl 84565 2009-02-23 08:20:39Z johnnyw $

// Open versioned namespace, if enabled by the user.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void
ACE_ATM_Connector::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_ATM_Connector::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_INLINE
ACE_ATM_Connector::ACE_ATM_Connector (ACE_ATM_Stream &new_stream,
                                      const ACE_ATM_Addr &remote_sap,
                                      ACE_ATM_Params params,
                                      ACE_ATM_QoS options,
                                      ACE_Time_Value *timeout,
                                      const ACE_ATM_Addr &local_sap,
                                      int reuse_addr,
                                      int flags,
                                      int perms)
{
  ACE_TRACE ("ACE_ATM_Connector::ACE_ATM_Connector");
  if ((ACE_HANDLE)this->connect (new_stream,
                                 remote_sap,
                                 params,
                                 options,
                                 timeout,
                                 local_sap,
                                 reuse_addr,
                                 flags,
                                 perms) == ACE_INVALID_HANDLE
      && timeout != 0 && !(errno == EWOULDBLOCK || errno == ETIME))
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_ATM_Stream::ACE_ATM_Stream")));
}

// Try to complete a non-blocking connection.

ACE_INLINE
int
ACE_ATM_Connector::complete (ACE_ATM_Stream &new_stream,
                             ACE_ATM_Addr *remote_sap,
                             ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_ATM_Connector::complete");
#if defined (ACE_HAS_ATM)
  return connector_.complete(new_stream.get_stream(),
                             remote_sap,
                             tv);
#else
  ACE_UNUSED_ARG(new_stream);
  ACE_UNUSED_ARG(remote_sap);
  ACE_UNUSED_ARG(tv);
  return 0;
#endif
}

ACE_INLINE
int
ACE_ATM_Connector::add_leaf (ACE_ATM_Stream &current_stream,
                             const ACE_Addr &remote_sap,
                             ACE_ATM_QoS &qos)
{
  ACE_TRACE ("ACE_ATM_Connector::add_leaf");
#if defined (ACE_HAS_FORE_ATM_XTI)
  return connector_.add_leaf(current_stream.get_stream(),
                             remote_sap,
                             leaf_id,
                             timeout);
#elif defined (ACE_HAS_FORE_ATM_WS2)
  struct sockaddr_atm *saddr = (struct sockaddr_atm *)remote_sap.get_addr();
  ACE_QoS cqos = qos.get_qos();
  int addr_len = sizeof( struct sockaddr_atm );

  ACE_QoS_Params qos_params(0,
                            0,
                            &cqos,
                            0,
                            (JL_SENDER_ONLY));

  ACE_OS::printf( "ATM_Connector::add_leaf: connecting...\n" );

  ACE_HANDLE result = ACE_OS::join_leaf(current_stream.get_handle(),
                                        (struct sockaddr *)saddr,
                                        addr_len,
                                        qos_params);

  if ( result == ACE_INVALID_HANDLE )
    ACE_OS::printf( "ATM_Connector(add_leaf): connection failed, %d\n",
                    ::WSAGetLastError());

  return (result != ACE_INVALID_HANDLE);
#elif defined (ACE_HAS_LINUX_ATM)
  ACE_OS::printf("ATM_Connector(add_leaf): not yet implemented in Linux\n");

  ACE_UNUSED_ARG(current_stream);
  ACE_UNUSED_ARG(remote_sap);
  ACE_UNUSED_ARG(leaf_id);
  ACE_UNUSED_ARG(timeout);

  return 0;
#else
  ACE_UNUSED_ARG(current_stream);
  ACE_UNUSED_ARG(remote_sap);
  ACE_UNUSED_ARG(leaf_id);
  ACE_UNUSED_ARG(timeout);
  return 0;
#endif
}

ACE_INLINE
bool
ACE_ATM_Connector::reset_new_handle (ACE_HANDLE handle)
{
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
  // Reset the event association
  return ::WSAEventSelect ((SOCKET) handle,
                           0,
                           0);
#else /* !defined ACE_HAS_WINSOCK2 */
  ACE_UNUSED_ARG (handle);
  return false;
#endif /* ACE_WIN32 */
}

// Close versioned namespace, if enabled by the user.
ACE_END_VERSIONED_NAMESPACE_DECL
