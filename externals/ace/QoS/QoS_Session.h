/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    QoS_Session.h
 *
 *  $Id: QoS_Session.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Vishal Kachroo <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_QOS_SESSION_H
#define ACE_QOS_SESSION_H
#include /**/ "ace/pre.h"

#include "ACE_QoS_Export.h"
#include "ace/INET_Addr.h"
#include "ace/OS_QoS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_SOCK;
class ACE_QoS_Manager;

typedef int ACE_Protocol_ID;
// IPPROTO_UDP or IPPROTO_TCP.

/**
 * @class ACE_QoS_Session
 *
 * @brief A QoS Session object.
 *
 * This class defines the interface for a QoS Session. It abstracts the
 * notion of QoS on different platforms and presents a simple, easy-to-use
 * API. Current [RAPI,GQoS] and future implementations will conform to this
 * interface.
 */
class ACE_QoS_Export ACE_QoS_Session
{

public:

  enum RSVP_Event_Type
  {
    RSVP_PATH_EVENT,
    RSVP_RESV_EVENT,
    RSVP_RESV_CONFIRM,
    RSVP_RESV_ERROR,
    RSVP_PATH_ERROR    
  };

  /// A flag to indicate if this endpoint is a sender or a receiver or
  /// both.
  enum ACE_End_Point_Type
  {
    ACE_QOS_SENDER,
    ACE_QOS_RECEIVER,
    ACE_QOS_BOTH
  };

  
  /// to shutup g++.
  virtual ~ACE_QoS_Session (void) {};

  /// Open a QoS session [dest IP, dest port, Protocol ID].
  virtual int open (ACE_INET_Addr dest_addr,
                    ACE_Protocol_ID protocol_id) = 0;

  /// Close the QoS Session.
  virtual int close (void) = 0;

  /// Returns the QoS in the current session.
  virtual ACE_QoS qos (void) const = 0;

  /// Set QoS for the current session. The qos manager is used to
  /// confirm if this QoS session was subscribed to by the socket.
  virtual int qos (ACE_SOCK *socket,
                   ACE_QoS_Manager *qos_manager,
                   const ACE_QoS &ace_qos) = 0;

  /**
   * Sets the QoS for this session object to ace_qos. Does not
   * interfere with the QoS in the underlying socket. This call is
   * useful to update the QoS object when the underlying socket QoS is
   * being set through a mechanism other than the previous qos ()
   * method e.g. inside the dgram_mcast.subscribe () where the QoS for
   * the socket is set through ACE_OS::join_leaf ().
   */
  virtual void qos (const ACE_QoS &ace_qos) = 0;

  /**
   * This is called from handle_qos () method of the the QoS Event
   * Handler.  Invoking this method is an indication of a QoS event
   * occurring, that may have resulted in a change of QoS for the
   * underlying session. This method updates the QoS object associated
   * with this session.
   */
  virtual int update_qos (void) = 0;

  /// Get/Set methods for the flags_.
  virtual ACE_End_Point_Type flags (void) const = 0;
  virtual void flags (const ACE_End_Point_Type flags) = 0;

  /// Get the session id.
  virtual int session_id (void) const = 0;

  /// Set the session id.
  virtual void session_id (const int session_id) = 0;

  /// Get the file descriptor on which RSVP events will occur.
  virtual ACE_HANDLE rsvp_events_handle (void) = 0;

  virtual void  rsvp_event_type (RSVP_Event_Type event_type) = 0;
  ///Set the RAPI event that last occured
  
  virtual RSVP_Event_Type rsvp_event_type (void) = 0;
  ///Get the RAPI event that last occured


  /// Get the destination address for this session.
  virtual ACE_INET_Addr dest_addr (void) const = 0;

  /// Set the destination address for this session.
  virtual void dest_addr (const ACE_INET_Addr &dest_addr) = 0;

  /// Get the source port for this session.
  virtual u_short source_port (void) const = 0;

  /// Set the source port for this session.
  virtual void source_port (const u_short &source_port) = 0;

  //Set the source host
  virtual ACE_INET_Addr* source_addr (void) const = 0;
  
  /// Set the source port for this session.
  virtual void source_addr (ACE_INET_Addr* source_addr) = 0;
  

  /**
   * Returns the version of the underlying RSVP implementation. Is
   * meaningful only when the underlying implementation has
   * versioning.
   */
  virtual int version (void) = 0;

protected:

  /// Source port if this is a Sender session. Used for rapi_sender ().
  u_short source_port_;

  /// session id for the session.
  int session_id_;

  /// Destination address for this session.
  ACE_INET_Addr dest_addr_;

  /// Source address for this session.
  ACE_INET_Addr* src_addr_;

  /// Is this a TCP or a UDP session.
  ACE_Protocol_ID protocol_id_;

  /// QoS for this session.
  ACE_QoS qos_;

  /// Specifies if this is a sending/receiving/both session.
  ACE_End_Point_Type flags_;

  RSVP_Event_Type rsvp_event_type_;
  //Has the last rsvp event that occured

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_QOS_SESSION_H */
