// -*- C++ -*-
//
// $Id: Select_Reactor_T.inl 96017 2012-08-08 22:18:09Z mitza $

#include "ace/Reactor.h"
#include "ace/Signal.h"
#include "ace/Sig_Handler.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::resume_handler (ACE_Event_Handler *h)
{
  ACE_TRACE ("ACE_Select_Reactor_T::resume_handler");
  return this->resume_handler (h->get_handle ());
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::resume_handler (const ACE_Handle_Set &handles)
{
  ACE_TRACE ("ACE_Select_Reactor_T::resume_handler");
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;

  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->resume_i (h) == -1)
      return -1;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::suspend_handler (ACE_Event_Handler *h)
{
  ACE_TRACE ("ACE_Select_Reactor_T::suspend_handler");
  return this->suspend_handler (h->get_handle ());
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::suspend_handler (const ACE_Handle_Set &handles)
{
  ACE_TRACE ("ACE_Select_Reactor_T::suspend_handler");
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;

  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->suspend_i (h) == -1)
      return -1;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler (int signum,
                                                                  ACE_Event_Handler *new_sh,
                                                                  ACE_Sig_Action *new_disp,
                                                                  ACE_Event_Handler **old_sh,
                                                                  ACE_Sig_Action *old_disp)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler");
  return this->signal_handler_->register_handler (signum,
                                                  new_sh, new_disp,
                                                  old_sh, old_disp);
}

#if defined (ACE_WIN32)

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler (ACE_Event_Handler *,
                                                                  ACE_HANDLE )
{
  // Don't have an implementation for this yet...
  ACE_NOTSUP_RETURN (-1);
}

#endif /* ACE_WIN32 */

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler (ACE_HANDLE ,
                                                                  ACE_HANDLE ,
                                                                  ACE_Event_Handler *,
                                                                  ACE_Reactor_Mask )
{
  // Don't have an implementation for this yet...
  ACE_NOTSUP_RETURN (-1);
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handler (int signum, ACE_Event_Handler **handler)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handler");
  return this->handler_i (signum, handler);
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler (int signum,
                                                                ACE_Sig_Action *new_disp,
                                                                ACE_Sig_Action *old_disp,
                                                                int sigkey)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler");
  return this->signal_handler_->remove_handler (signum, new_disp, old_disp, sigkey);
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_INLINE bool
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::uses_event_associations (void)
{
  // Since the Select_Reactor does not do any event associations, this
  // function always return false.
  return false;
}

// = The remaining methods in this file must be called with locks
// held.

// Performs operations on the "ready" bits.

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::ready_ops (ACE_Event_Handler *handler,
                                                           ACE_Reactor_Mask mask,
                                                           int ops)
{
  ACE_TRACE ("ACE_Select_Reactor_T::ready_ops");
  return this->ready_ops (handler->get_handle (), mask, ops);
}

// Performs operations on the "dispatch" masks.

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::mask_ops (ACE_Event_Handler *handler,
                                                          ACE_Reactor_Mask mask,
                                                          int ops)
{
  ACE_TRACE ("ACE_Select_Reactor_T::mask_ops");
  return this->mask_ops (handler->get_handle (), mask, ops);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::schedule_wakeup (ACE_Event_Handler *eh,
                                                                 ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::schedule_wakeup");
  return this->mask_ops (eh->get_handle (), mask, ACE_Reactor::ADD_MASK);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::cancel_wakeup (ACE_Event_Handler *eh,
                                                               ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::cancel_wakeup");
  return this->mask_ops (eh->get_handle (), mask, ACE_Reactor::CLR_MASK);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::schedule_wakeup (ACE_HANDLE handle,
                                                                 ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::schedule_wakeup");
  return this->mask_ops (handle, mask, ACE_Reactor::ADD_MASK);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::cancel_wakeup (ACE_HANDLE handle,
                                                               ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::cancel_wakeup");
  return this->mask_ops (handle, mask, ACE_Reactor::CLR_MASK);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE ACE_Lock &
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::lock (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::lock");
  return this->lock_adapter_;
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::wakeup_all_threads (void)
{
  // Send a notification, but don't block if there's no one to receive
  // it.
  this->notify (0, ACE_Event_Handler::NULL_MASK, (ACE_Time_Value *) &ACE_Time_Value::zero);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::alertable_handle_events (ACE_Time_Value *max_wait_time)
{
  return this->handle_events (max_wait_time);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::alertable_handle_events (ACE_Time_Value &max_wait_time)
{
  return this->handle_events (max_wait_time);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::deactivated (void)
{
  return this->deactivated_;
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::deactivate (int do_stop)
{
  {
    ACE_MT (ACE_GUARD (ACE_SELECT_REACTOR_TOKEN,
                       ace_mon,
                       this->token_));
    this->deactivated_ = static_cast<sig_atomic_t> (do_stop);
  }

  this->wakeup_all_threads ();
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_INLINE size_t
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::size (void) const
{
  return this->handler_rep_.size ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
