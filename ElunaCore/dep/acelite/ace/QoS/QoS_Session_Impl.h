// -*- C++ -*-

//=============================================================================
/**
 *  @file    QoS_Session_Impl.h
 *
 *  $Id: QoS_Session_Impl.h 91743 2010-09-13 18:24:51Z johnnyw $
 *
 *  @author Vishal Kachroo <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_QOS_SESSION_IMPL_H
#define ACE_QOS_SESSION_IMPL_H
#include /**/ "ace/pre.h"

#include "ace/QoS/QoS_Session.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if defined (ACE_HAS_RAPI)
#include "rapi_lib.h"

#define DEFAULT_SOURCE_SENDER_PORT 10001

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_RAPI_Session
 *
 * @brief A RAPI QoS session object.
 *
 * This class is a RAPI (RSVP API, an implementation of RSVP on UNIX)
 * implementation of the ACE_QoS_Session interface.
 */
class ACE_QoS_Export ACE_RAPI_Session : public ACE_QoS_Session
{

public:

  /// Default destructor.
  ~ACE_RAPI_Session (void);

  /// Error handling for RSVP callback
  static int rsvp_error;

  /// Open a RAPI QoS session [dest IP, dest port, Protocol ID].
  virtual int open (ACE_INET_Addr dest_addr,
                    ACE_Protocol_ID protocol_id);

  /// Close the RAPI QoS Session.
  virtual int close (void);

  /// Returns the QoS for this RAPI session.
  virtual ACE_QoS qos (void) const;

  /// Set QoS for this RAPI session. The socket parameter is used to confirm if
  /// this QoS session was subscribed to by the socket.
  virtual int qos (ACE_SOCK *socket,
                   ACE_QoS_Manager *qos_manager,
                   const ACE_QoS &ace_qos);

  /**
   * Sets the QoS for this session object to ace_qos. Does not interfere with the
   * QoS in the underlying socket. This call is useful to update the QoS object
   * when the underlying socket QoS is being set through a mechanism other than
   * the previous qos () method e.g. inside the dgram_mcast.subscribe () where the
   * QoS for the socket is set through ACE_OS::join_leaf ().
   */
  virtual void qos (const ACE_QoS &ace_qos);

  /**
   * Calls rapi_dispatch () that further triggers the call back function.
   * It is a mechanism of updating the QoS for this session asynchronously, as
   * RSVP events occur.
   */
  virtual int update_qos (void);

  /// Get methods for the flags_.
  virtual ACE_End_Point_Type flags (void) const;

  /// Set methods for the flags_.
  virtual void flags (const ACE_End_Point_Type flags);

  /// Get the RAPI session id.
  virtual int session_id (void) const;

  /// Set the RAPI session id.
  virtual void session_id (const int session_id);

  /// Get the RAPI file descriptor for RSVP events.
  virtual ACE_HANDLE rsvp_events_handle (void);

  ///Set the RAPI event that last occured
  virtual void  rsvp_event_type (RSVP_Event_Type event_type);

  ///Get the RAPI event that last occured
  virtual RSVP_Event_Type rsvp_event_type (void);

  /// Get the destination address for this RAPI session.
  virtual ACE_INET_Addr dest_addr (void) const;

  /// Set the destination address for this RAPI session.
  virtual void dest_addr (const ACE_INET_Addr &dest_addr);

  /// Get the source port for this session.
  virtual u_short source_port (void) const;

  /// Set the source port for this session.
  virtual void source_port (const u_short &source_port);

  //Set the source host
  virtual ACE_INET_Addr* source_addr (void) const;

  /// Set the source port for this session.
  virtual void source_addr (ACE_INET_Addr* source_addr);

  /// RAPI version. Returned value = 100 * major-version + minor-version.
  virtual int version ();

  /// The factory is a friend so it can create this object through
  /// the only private constructor.
  friend class ACE_QoS_Session_Factory;

private:

  /// Default constuctor. Constructor is defined private so that only
  /// the friend factory can instantiate this class.
  ACE_RAPI_Session (void);

  /// Construct a simplified RAPI Sender TSpec object
  /// from an ACE_Flow_Spec object. Used internally by this class.
  rapi_tspec_t *init_tspec_simplified (const ACE_Flow_Spec &flow_spec);

  /// Construct a simplified RAPI Receiver FlowSpec object
  /// from an ACE_Flow_Spec object. Used internally by the class.
  rapi_flowspec_t *init_flowspec_simplified(const ACE_Flow_Spec &flow_spec);

  /// Set sending QoS for this RAPI session.
  int sending_qos (const ACE_QoS &ace_qos);

  /// Set receiving  QoS for this RAPI session.
  int receiving_qos (const ACE_QoS &ace_qos);

};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_RAPI */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_GQoS_Session
 *
 * @brief A GQoS session object.
 *
 * This class is a GQoS (Generic QoS, an implementation of RSVP on
 * Win2K) implementation of the ACE_QoS_Session interface.
 */
class ACE_QoS_Export ACE_GQoS_Session : public ACE_QoS_Session
{

public:

  /// Default destructor.
  ~ACE_GQoS_Session (void);

  /// This is a session ID generator. It does a lot more than expected
  /// from an int!.
  static int GQoS_session_id;

  /// Open a GQoS session [dest IP, dest port, Protocol ID].
  virtual int open (ACE_INET_Addr dest_addr,
                    ACE_Protocol_ID protocol_id);

  /// Close the GQoS Session.
  virtual int close (void);

  /// Returns the QoS for this GQoS session.
  virtual ACE_QoS qos (void) const;

  /// Set QoS for this GQoS session. The socket parameter is used to confirm if
  /// this QoS session was subscribed to by the socket.
  virtual int qos (ACE_SOCK *socket,
                   ACE_QoS_Manager *qos_manager,
                   const ACE_QoS &ace_qos);

  /**
   * Sets the QoS for this session object to ace_qos. Does not interfere with the
   * QoS in the underlying socket. This call is useful to update the QoS object
   * when the underlying socket QoS is being set through a mechanism other than
   * the previous qos () method e.g. inside the dgram_mcast.subscribe () where the
   * QoS for the socket is set through ACE_OS::join_leaf ().
   */
  virtual void qos (const ACE_QoS &ace_qos);

  /// Calls the ioctl (ACE_SIO_GET_QOS). It is a mechanism of updating the
  /// QoS for this session asynchronously, as RSVP events occur.
  virtual int update_qos (void);

  /// Get/Set methods for the flags_.
  virtual ACE_End_Point_Type flags (void) const;
  virtual void flags (const ACE_End_Point_Type flags);

  /// Get the destination address for this GQoS session.
  virtual ACE_INET_Addr dest_addr (void) const;

  /// Set the destination address for this GQoS session.
  virtual void dest_addr (const ACE_INET_Addr &dest_addr);

  /// Get the source port for this session.
  virtual u_short source_port (void) const;

  /// Set the source port for this session.
  virtual void source_port (const u_short &source_port);

  //Set the source host
  virtual ACE_INET_Addr* source_addr (void) const;

  /// Set the source port for this session.
  virtual void source_addr (ACE_INET_Addr* source_addr);

  /// Get the GQoS session id.
  virtual int session_id (void) const;

  /// Set the GQoS session id.
  virtual void session_id (const int session_id);

  /// Get the file descriptor of the underlying socket.
  virtual ACE_HANDLE rsvp_events_handle (void);

  virtual void  rsvp_event_type (RSVP_Event_Type event_type);
  ///Set the RAPI event that last occured

  virtual RSVP_Event_Type rsvp_event_type (void);
  ///Get the RAPI event that last occured

  /// GQoS version.
  virtual int version ();

  /// The factory is a friend so it can create this object through
  /// the only private constructor.
  friend class ACE_QoS_Session_Factory;

private:

  /// Default constructor. Constructor is defined private so that only
  /// the friend factory can instantiate this class.
  ACE_GQoS_Session (void);

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "QoS_Session_Impl.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_QOS_SESSION_IMPL_H */
