//$Id: Event_Handler_Handle_Timeout_Upcall.h 95334 2011-12-15 12:52:50Z msmit $

#ifndef ACE_EVENT_HANDLER_HANDLE_TIMEOUT_UPCALL_H
#define ACE_EVENT_HANDLER_HANDLE_TIMEOUT_UPCALL_H

#include /**/ "ace/pre.h"

/**
 * @file Event_Handler_Handle_Timeout_Upcall.h
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 *
 * Based on classes and files developed by Doug Schmidt, Darrell
 * Brunsch, Irfan Pyarali and a cast of thousands.
 */

#include "ace/Timer_Queuefwd.h"
#include "ace/Copy_Disabled.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Event_Handler_Handle_Timeout_Upcall
 *
 * @brief Functor for Timer_Queues.
 *
 * This class implements the functor required by the Timer
 * Queue to call <handle_timeout> on ACE_Event_Handlers.
 */
class ACE_Export ACE_Event_Handler_Handle_Timeout_Upcall
  : private ACE_Copy_Disabled
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Event_Handler_Handle_Timeout_Upcall (void);

  /// Destructor.
  ~ACE_Event_Handler_Handle_Timeout_Upcall (void);

  /// This method is called when a timer is registered.
  int registration (ACE_Timer_Queue &timer_queue,
                    ACE_Event_Handler *handler,
                    const void *arg);

  /// This method is called before the timer expires.
  int preinvoke (ACE_Timer_Queue &timer_queue,
                 ACE_Event_Handler *handler,
                 const void *arg,
                 int recurring_timer,
                 const ACE_Time_Value &cur_time,
                 const void *&upcall_act);

  /// This method is called when the timer expires.
  int timeout (ACE_Timer_Queue &timer_queue,
               ACE_Event_Handler *handler,
               const void *arg,
               int recurring_timer,
               const ACE_Time_Value &cur_time);

  /// This method is called after the timer expires.
  int postinvoke (ACE_Timer_Queue &timer_queue,
                  ACE_Event_Handler *handler,
                  const void *arg,
                  int recurring_timer,
                  const ACE_Time_Value &cur_time,
                  const void *upcall_act);

  /// This method is called when a handler is cancelled
  int cancel_type (ACE_Timer_Queue &timer_queue,
                   ACE_Event_Handler *handler,
                   int dont_call,
                   int &requires_reference_counting);

  /// This method is called when a timer is cancelled
  int cancel_timer (ACE_Timer_Queue &timer_queue,
                    ACE_Event_Handler *handler,
                    int dont_call,
                    int requires_reference_counting);

  /// This method is called when the timer queue is destroyed and
  /// the timer is still contained in it
  int deletion (ACE_Timer_Queue &timer_queue,
                ACE_Event_Handler *handler,
                const void *arg);

private:

  /// Flag indicating that reference counting is required for this
  /// event handler upcall.
  int requires_reference_counting_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined(__ACE_INLINE__)
# include "ace/Event_Handler_Handle_Timeout_Upcall.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_EVENT_HANDLER_HANDLE_TIMEOUT_UPCALL_H */
