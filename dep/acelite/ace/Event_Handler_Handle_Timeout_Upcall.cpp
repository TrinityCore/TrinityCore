// $Id: Event_Handler_Handle_Timeout_Upcall.cpp 95586 2012-03-03 20:45:57Z johnnyw $

#include "ace/Event_Handler_Handle_Timeout_Upcall.h"
#include "ace/Reactor_Timer_Interface.h"
#include "ace/Abstract_Timer_Queue.h"

#if !defined(__ACE_INLINE__)
# include "ace/Event_Handler_Handle_Timeout_Upcall.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Event_Handler_Handle_Timeout_Upcall::
ACE_Event_Handler_Handle_Timeout_Upcall (void) :
  requires_reference_counting_ (0)
{
}

ACE_Event_Handler_Handle_Timeout_Upcall::
~ACE_Event_Handler_Handle_Timeout_Upcall (void)
{
}

int
ACE_Event_Handler_Handle_Timeout_Upcall::
timeout (ACE_Timer_Queue &timer_queue,
        ACE_Event_Handler *event_handler,
        const void *act,
        int recurring_timer,
        const ACE_Time_Value &cur_time)
{
  int requires_reference_counting = 0;

  if (!recurring_timer)
    {
      requires_reference_counting =
        event_handler->reference_counting_policy ().value () ==
        ACE_Event_Handler::Reference_Counting_Policy::ENABLED;
    }

  // Upcall to the <handler>s handle_timeout method.
  if (event_handler->handle_timeout (cur_time, act) == -1)
    {
      if (event_handler->reactor_timer_interface ())
        event_handler->reactor_timer_interface ()->cancel_timer (event_handler, 0);
      else
        timer_queue.cancel (event_handler, 0); // 0 means "call handle_close()".
    }

  if (!recurring_timer &&
      requires_reference_counting)
    {
      event_handler->remove_reference ();
    }

  return 0;
}

int
ACE_Event_Handler_Handle_Timeout_Upcall::
cancel_type (ACE_Timer_Queue &,
            ACE_Event_Handler *event_handler,
            int dont_call,
            int &requires_reference_counting)
{
  requires_reference_counting =
    event_handler->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;

  // Upcall to the <handler>s handle_close method
  if (dont_call == 0)
    event_handler->handle_close (ACE_INVALID_HANDLE,
                                 ACE_Event_Handler::TIMER_MASK);

  return 0;
}

int
ACE_Event_Handler_Handle_Timeout_Upcall::
deletion (ACE_Timer_Queue &timer_queue,
          ACE_Event_Handler *event_handler,
          const void *)
{
  int requires_reference_counting = 0;

  this->cancel_type (timer_queue,
                     event_handler,
                     0,
                     requires_reference_counting);

  this->cancel_timer (timer_queue,
                      event_handler,
                      0,
                      requires_reference_counting);

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
