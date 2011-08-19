// -*- C++ -*-

//=============================================================================
/**
 *  @file    QoS_Decorator.h
 *
 *  $Id: QoS_Decorator.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Vishal Kachroo <vishal@cs.wustl.edu>
 */
//=============================================================================


#ifndef QOS_DECORATOR_H
#define QOS_DECORATOR_H
#include /**/ "ace/pre.h"

#include "ace/Reactor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/INET_Addr.h"
#include "ace/Event_Handler.h"
#include "SOCK_Dgram_Mcast_QoS.h"
#include "ACE_QoS_Export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_QoS_Decorator_Base
 *
 * @brief This class is the Decorator Pattern Base class for decorating
 * ACE_Event_Handler.
 *
 * It simply forwards the requests for get_handle (),
 * handle_input () and handle_qos () to its event_handler_
 * component. Concrete decorators for ACE_Event_Handler will use
 * this class to access the basic event handler functionality and
 * decorate that by their own implementation.
 */
class ACE_QoS_Export ACE_QoS_Decorator_Base : public ACE_Event_Handler
{

public:

  // Initialization and termination methods.
  /// Constructor.
  ACE_QoS_Decorator_Base (void);

  /// Constructor.
  ACE_QoS_Decorator_Base (ACE_Event_Handler *event_handler);

  /// Destructor.
  ~ACE_QoS_Decorator_Base (void);

  /// Forwards the request to its event_handler_ component.
  virtual ACE_HANDLE get_handle (void) const;

  /// Forwards the request to its event_handler_ component.
  virtual int handle_input (ACE_HANDLE fd);

  /// Forwards the request to its event_handler_ component.
  virtual int handle_qos (ACE_HANDLE fd);

private:

  /// The event handler that is decorated by this class.
  ACE_Event_Handler *event_handler_;

};

/**
 * @class ACE_QoS_Event_Handler
 *
 * @brief This Handler is registered with the Reactor for QoS events.
 *
 * Concrete QoS decorator uses this class to receive QoS events
 * for RAPI.  It hides the application from knowing that it is
 * receiving QoS events on a different socket so the application
 * doesnt have to be designed differently for RAPI and GQoS.
 */
class ACE_QoS_Export ACE_QoS_Event_Handler : public ACE_Event_Handler
{

  /// Destructor.
  ~ACE_QoS_Event_Handler (void);

  /// Returns the RAPI file descriptor for receiving QoS events.
  virtual ACE_HANDLE get_handle (void) const;

  /// Calls the base class handle_input ().
  virtual int handle_input (ACE_HANDLE fd);

  /// Sets the QoS session.
  void qos_session (ACE_QoS_Session *qos_session);

  friend class ACE_QoS_Decorator;

private:

  /// Constructor is private because only ACE_QoS_Decorator should
  /// create this object.
  ACE_QoS_Event_Handler (void);

  /// The QoS Decorator passes in its base for this handler to use.
  ACE_QoS_Event_Handler (ACE_QoS_Decorator_Base *decorator_base);

  /// Used to get to the RAPI file descriptor for QoS Events.
  ACE_QoS_Session *qos_session_;

  /// Requests on the class are forwarded to this base class;
  ACE_QoS_Decorator_Base *decorator_base_;

};

/**
 * @class ACE_QoS_Decorator
 *
 * @brief Concrete QoS Decorator.
 *
 * Decorates the ACE_Event_Handler to additionally handle QoS
 * events uniformly for different QoS mechanisms like RAPI and
 * GQoS.
 */
class ACE_QoS_Export ACE_QoS_Decorator : public ACE_QoS_Decorator_Base
{

public:

  // Initialization and termination methods.
  /// Constructor.
  ACE_QoS_Decorator (void);

  /// Constructor.
  ACE_QoS_Decorator (ACE_Event_Handler *event_handler,
                     ACE_QoS_Session *qos_session,
                     ACE_Reactor *reactor = ACE_Reactor::instance ());

  /// Destructor.
  ~ACE_QoS_Decorator (void);

  /// Calls the base class get_handle ().
  virtual ACE_HANDLE get_handle (void) const;

  /// Calls the base class handle_input ().
  virtual int handle_input (ACE_HANDLE fd);

  /// Calls the base class handle_qos ().
  virtual int handle_qos (ACE_HANDLE fd);

  /// This method registers the QoS Event Handler with the Reactor
  /// to receive RAPI events.
  int init (void);

private:

  /// Requests on the class are forwarded to this base class;
  ACE_QoS_Decorator_Base *decorator_base_;

  /// Handles the QoS events and in that sense decorates the usual
  /// ACE_Event_Handler.
  ACE_QoS_Event_Handler *qos_event_handler_;

  /// Passed to the ACE_QoS_Event_Handler for retrieving the RAPI
  /// session specific information like rapi_fd.
  ACE_QoS_Session *qos_session_;

  /// If the application wants to use an instance of Reactor other
  /// than the Singleton one.
  ACE_Reactor *reactor_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif  /* QOS_DECORATOR_H */
