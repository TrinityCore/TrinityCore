// QoS_Decorator.cpp
// $Id: QoS_Decorator.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "QoS_Decorator.h"

ACE_RCSID(ace, QoS_Decorator, "$Id: QoS_Decorator.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_QOS_DECORATOR)

// Constructor.
ACE_QoS_Decorator_Base::ACE_QoS_Decorator_Base (void)
{}

// Constructor.
ACE_QoS_Decorator_Base::ACE_QoS_Decorator_Base (ACE_Event_Handler
                                                *event_handler)
  : event_handler_ (event_handler)
{
}

// Destructor.
ACE_QoS_Decorator_Base::~ACE_QoS_Decorator_Base (void)
{
}

// Forward the call to ACE_Event_Handler component.
ACE_HANDLE
ACE_QoS_Decorator_Base::get_handle (void) const
{
 return this->event_handler_->get_handle ();
}

// Forward the call to ACE_Event_Handler component.
int
ACE_QoS_Decorator_Base::handle_input (ACE_HANDLE fd)
{
  return this->event_handler_->handle_input (fd);
}

// Forward the call to ACE_Event_Handler component.
int
ACE_QoS_Decorator_Base::handle_qos (ACE_HANDLE fd)
{
  return this->event_handler_->handle_qos (fd);
}

// Constructor.
ACE_QoS_Decorator::ACE_QoS_Decorator (void)
{}

// Constructor.
ACE_QoS_Decorator::ACE_QoS_Decorator (ACE_Event_Handler *event_handler,
                                      ACE_QoS_Session *qos_session,
                                      ACE_Reactor *reactor)
  : qos_session_ (qos_session),
    reactor_ (reactor)
{
  ACE_NEW (this->decorator_base_,
           ACE_QoS_Decorator_Base (event_handler));

  ACE_NEW (this->qos_event_handler_,
           ACE_QoS_Event_Handler (this->decorator_base_));
}

// Destructor.
ACE_QoS_Decorator::~ACE_QoS_Decorator (void)
{
  delete this->decorator_base_;
  delete this->qos_event_handler_;
}

// Implements the undecorated functionality. This is sufficient for
// GQoS. RAPI needs additional QoS decoration. This is done by the
// ACE_QoS_Event_Handler class.
ACE_HANDLE
ACE_QoS_Decorator::get_handle (void) const
{
  return this->decorator_base_->get_handle ();
}

// Implements the undecorated functionality. This is sufficient for
// GQoS. RAPI needs additional QoS decoration. This is done by the
// ACE_QoS_Event_Handler class.
int
ACE_QoS_Decorator::handle_input (ACE_HANDLE fd)
{
  return this->decorator_base_->handle_input (fd);
}

// Implements the undecorated functionality. This is sufficient for
// GQoS. RAPI needs additional QoS decoration. This is done by the
// ACE_QoS_Event_Handler class.
int
ACE_QoS_Decorator::handle_qos (ACE_HANDLE fd)
{
  return this->decorator_base_->handle_qos (fd);
}

// This method registers the RAPI QoS event handler with the reactor
// if the application is using RAPI. Note that it is a no-op for GQoS
// because an extra socket for handling QoS events is not required.
int
ACE_QoS_Decorator::init (void)
{
#if defined (ACE_HAS_RAPI)

  // Pass the QoS session to QoS Event Handler.
  this->qos_event_handler_->qos_session (this->qos_session_);

  // Register the QoS Event Handler with the Reactor.
  return this->reactor_->register_handler (this->qos_event_handler_,
                                           ACE_Event_Handler::READ_MASK);
#endif
  return 0;

}

// Constructor.
ACE_QoS_Event_Handler::ACE_QoS_Event_Handler (void)
{
}

// Constructor.
ACE_QoS_Event_Handler::ACE_QoS_Event_Handler (ACE_QoS_Decorator_Base
                                              *decorator_base)
  : decorator_base_ (decorator_base)
{
}

// Destructor.
ACE_QoS_Event_Handler::~ACE_QoS_Event_Handler (void)
{
}

// Set the QoS session.
void
ACE_QoS_Event_Handler::qos_session (ACE_QoS_Session *qos_session)
{
  this->qos_session_ = qos_session;
}

// Returns the RAPI file descriptor for listening to RAPI evnets.
ACE_HANDLE
ACE_QoS_Event_Handler::get_handle (void) const
{
  return this->qos_session_->rsvp_events_handle ();
}

// Note, here the handle_input () calls the handle_qos () of the
// Decorator Base which then calls handle_qos () of the
// ACE_Event_Handler component within it. This helps to translate the
// normal read events into qos events in case of RAPI so the
// application using the API is oblivious to the fact that in RAPI,
// QoS events are received on a different socket. This helps to
// maintain a uniform design for the application irrespective of
// whether it is using RAPI or GQoS.
int
ACE_QoS_Event_Handler::handle_input (ACE_HANDLE fd)
{
  return this->decorator_base_->handle_qos (fd);
}

ACE_END_VERSIONED_NAMESPACE_DECL
