// -*- C++ -*-

//=============================================================================
/**
 *  @file   Notification_Strategy.h
 *
 *  $Id: Notification_Strategy.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Doug Schmidt
 */
//=============================================================================
#ifndef ACE_NOTIFICATION_STRATEGY_H
#define ACE_NOTIFICATION_STRATEGY_H
#include /**/ "ace/pre.h"

#include "ace/Event_Handler.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls.
class ACE_Reactor;

/**
 * @class ACE_Notification_Strategy
 *
 * @brief Abstract class used for notifying an interested party
 *
 * A vehicle for extending the behavior of ACE_Message_Queue wrt
 * notification *without subclassing*.  Thus, it's an example of
 * the Bridge/Strategy patterns.
 */
class ACE_Export ACE_Notification_Strategy
{
public:
  /// Constructor.
  ACE_Notification_Strategy (ACE_Event_Handler *eh, ACE_Reactor_Mask mask);

  /// Destructor.
  virtual ~ACE_Notification_Strategy (void);

  virtual int notify (void) = 0;
  virtual int notify (ACE_Event_Handler *, ACE_Reactor_Mask mask) = 0;

  /// Get the event handler.
  ACE_Event_Handler *event_handler (void);

  /// Set the event handler.
  void event_handler (ACE_Event_Handler *eh);

  /// Get the reactor mask.
  ACE_Reactor_Mask mask (void) const;

  /// Set the reactor mask.
  void mask (ACE_Reactor_Mask m);

protected:
  /// The event handler.
  ACE_Event_Handler *eh_;

  /// The reactor mask.
  ACE_Reactor_Mask mask_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Notification_Strategy.inl"
#endif /* __ACE_INLINE __ */

#include /**/ "ace/post.h"
#endif /*ACE_NOTIFICATION_STRATEGY_H */
