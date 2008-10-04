// $Id: Select_Reactor_T.cpp 82393 2008-07-23 10:52:34Z johnnyw $

#ifndef ACE_SELECT_REACTOR_T_CPP
#define ACE_SELECT_REACTOR_T_CPP

#include "ace/Select_Reactor_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/ACE.h"
#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/Signal.h"
#include "ace/Sig_Handler.h"
#include "ace/Thread.h"
#include "ace/Timer_Heap.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_sys_select.h"
#include "ace/OS_NS_sys_stat.h"

// For timer_queue_
#include "ace/Recursive_Thread_Mutex.h"

/*
 * ACE Reactor specialization hook.
 */
//@@ REACTOR_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK

#if !defined (__ACE_INLINE__)
#include "ace/Select_Reactor_T.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           Select_Reactor_T,
           "$Id: Select_Reactor_T.cpp 82393 2008-07-23 10:52:34Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Select_Reactor_T)

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::any_ready
  (ACE_Select_Reactor_Handle_Set &wait_set)
{
  ACE_TRACE ("ACE_Select_Reactor_T::any_ready");

  if (this->mask_signals_)
    {
#if !defined (ACE_WIN32)
      // Make this call signal safe.
      ACE_Sig_Guard sb;
#endif /* ACE_WIN32 */

      return this->any_ready_i (wait_set);
    }
  return this->any_ready_i (wait_set);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::any_ready_i
  (ACE_Select_Reactor_Handle_Set &wait_set)
{
  ACE_TRACE ("ACE_Select_Reactor_T::any_ready_i");

  int number_ready = this->ready_set_.rd_mask_.num_set ()
    + this->ready_set_.wr_mask_.num_set ()
    + this->ready_set_.ex_mask_.num_set ();

  // number_ready > 0 meaning there are handles in the ready_set
  // &wait_set != &(this->ready_set_) means that we need to copy
  // the handles from the ready_set to the wait set because the
  // wait_set_ doesn't contain all the handles in the ready_set_
  if (number_ready > 0 && &wait_set != &(this->ready_set_))
    {
      wait_set.rd_mask_ = this->ready_set_.rd_mask_;
      wait_set.wr_mask_ = this->ready_set_.wr_mask_;
      wait_set.ex_mask_ = this->ready_set_.ex_mask_;

      this->ready_set_.rd_mask_.reset ();
      this->ready_set_.wr_mask_.reset ();
      this->ready_set_.ex_mask_.reset ();
    }

  return number_ready;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handler_i (int signum,
                                                           ACE_Event_Handler **eh)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handler_i");
  ACE_Event_Handler *handler = this->signal_handler_->handler (signum);

  if (handler == 0)
    return -1;
  else if (eh != 0)
    *eh = handler;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> bool
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::initialized (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::initialized");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, false));
  return this->initialized_;
}


template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::owner (ACE_thread_t tid,
                                                       ACE_thread_t *o_id)
{
  ACE_TRACE ("ACE_Select_Reactor_T::owner");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (o_id)
    *o_id = this->owner_;

  this->owner_ = tid;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::owner (ACE_thread_t *t_id)
{
  ACE_TRACE ("ACE_Select_Reactor_T::owner");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  *t_id = this->owner_;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::restart (void)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->restart_;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::restart (int r)
{
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  int const current_value = this->restart_;
  this->restart_ = r;
  return current_value;
}

template <class ACE_SELECT_REACTOR_TOKEN> void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::requeue_position (int rp)
{
  ACE_TRACE ("ACE_Select_Reactor_T::requeue_position");
  ACE_MT (ACE_GUARD (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_));
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (rp);
  // Must always requeue ourselves "next" on Win32.
  this->requeue_position_ = 0;
#else
  this->requeue_position_ = rp;
#endif /* ACE_WIN32 */
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::requeue_position (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::requeue_position");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->requeue_position_;
}

template <class ACE_SELECT_REACTOR_TOKEN> void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::max_notify_iterations (int iterations)
{
  ACE_TRACE ("ACE_Select_Reactor_T::max_notify_iterations");
  ACE_MT (ACE_GUARD (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_));

  this->notify_handler_->max_notify_iterations (iterations);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::max_notify_iterations (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::max_notify_iterations");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->notify_handler_->max_notify_iterations ();
}

// Enqueue ourselves into the list of waiting threads.
template <class ACE_SELECT_REACTOR_TOKEN> void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::renew (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::renew");
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  if (this->supress_notify_renew () == 0)
    this->token_.renew (this->requeue_position_);
#endif /* defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0) */
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::notify (ACE_Event_Handler *eh,
                                                        ACE_Reactor_Mask mask,
                                                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Select_Reactor_T::notify");

  // Pass over both the Event_Handler *and* the mask to allow the
  // caller to dictate which Event_Handler method the receiver
  // invokes.  Note that this call can timeout.

  ssize_t const n = this->notify_handler_->notify (eh, mask, timeout);
  return n == -1 ? -1 : 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::resume_handler (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::resume_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->resume_i (handle);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::suspend_handler (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::suspend_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->suspend_i (handle);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::suspend_handlers (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::suspend_handlers");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  ACE_Event_Handler *eh = 0;

  for (ACE_Select_Reactor_Handler_Repository_Iterator iter (&this->handler_rep_);
       iter.next (eh) != 0;
       iter.advance ())
    {
      this->suspend_i (eh->get_handle ());
    }

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::resume_handlers (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::resume_handlers");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  ACE_Event_Handler *eh = 0;

  for (ACE_Select_Reactor_Handler_Repository_Iterator iter (&this->handler_rep_);
       iter.next (eh) != 0;
       iter.advance ())
    {
      this->resume_i (eh->get_handle ());
    }

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler
  (ACE_Event_Handler *handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->register_handler_i (handler->get_handle (), handler, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler
  (ACE_HANDLE handle,
   ACE_Event_Handler *handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->register_handler_i (handle, handler, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler
  (const ACE_Handle_Set &handles,
   ACE_Event_Handler *handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->register_handler_i (handles, handler, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_Event_Handler *
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::find_handler
  (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::find_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, 0));
  return this->find_handler_i (handle);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handler
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask,
   ACE_Event_Handler **handler)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->handler_i (handle, mask, handler);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler
  (const ACE_Handle_Set &handles,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->remove_handler_i (handles, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler
  (ACE_Event_Handler *handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->remove_handler_i (handler->get_handle (), mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->remove_handler_i (handle, mask);
}

// Performs operations on the "ready" bits.

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::ready_ops
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask,
   int ops)
{
  ACE_TRACE ("ACE_Select_Reactor_T::ready_ops");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));
  return this->bit_ops (handle,
                        mask,
                        this->ready_set_,
                        ops);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::open
  (size_t size,
   int restart,
   ACE_Sig_Handler *sh,
   ACE_Timer_Queue *tq,
   int disable_notify_pipe,
   ACE_Reactor_Notify *notify)
{
  ACE_TRACE ("ACE_Select_Reactor_T::open");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  // Can't initialize ourselves more than once.
  if (this->initialized_)
    return -1;

  this->owner_ = ACE_Thread::self ();
  this->restart_ = restart;
  this->signal_handler_ = sh;
  this->timer_queue_ = tq;
  this->notify_handler_ = notify;

  int result = 0;

  // Allows the signal handler to be overridden.
  if (this->signal_handler_ == 0)
    {
      ACE_NEW_RETURN (this->signal_handler_,
                      ACE_Sig_Handler,
                      -1);

      this->delete_signal_handler_ = true;
    }

  // Allows the timer queue to be overridden.
  if (result != -1 && this->timer_queue_ == 0)
    {
      ACE_NEW_RETURN (this->timer_queue_,
                      ACE_Timer_Heap,
                      -1);

      this->delete_timer_queue_ = true;
    }

  // Allows the Notify_Handler to be overridden.
  if (result != -1 && this->notify_handler_ == 0)
    {
      ACE_NEW_RETURN (this->notify_handler_,
                      ACE_Select_Reactor_Notify,
                      -1);

      this->delete_notify_handler_ = true;
    }

  if (result != -1 && this->handler_rep_.open (size) == -1)
    result = -1;
  else if (this->notify_handler_->open (this,
                                        0,
                                        disable_notify_pipe) == -1)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%p\n"),
                  ACE_TEXT ("notification pipe open failed")));
      result = -1;
    }

  if (result != -1)
    // We're all set to go.
    this->initialized_ = true;
  else
    // This will close down all the allocated resources properly.
    this->close ();

  return result;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::set_sig_handler
  (ACE_Sig_Handler *signal_handler)
{
  if (this->delete_signal_handler_)
    delete this->signal_handler_;
  this->signal_handler_ = signal_handler;
  this->delete_signal_handler_ = false;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_Timer_Queue *
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::timer_queue (void) const
{
  return this->timer_queue_;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::timer_queue
  (ACE_Timer_Queue *tq)
{
  if (this->delete_timer_queue_)
    delete this->timer_queue_;
  this->timer_queue_ = tq;
  this->delete_timer_queue_ = false;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::ACE_Select_Reactor_T
  (ACE_Sig_Handler *sh,
   ACE_Timer_Queue *tq,
   int disable_notify_pipe,
   ACE_Reactor_Notify *notify,
   bool mask_signals,
   int s_queue)
    : ACE_Select_Reactor_Impl (mask_signals)
    , token_ (s_queue)
    , lock_adapter_ (token_)
    , deactivated_ (0)
{
  ACE_TRACE ("ACE_Select_Reactor_T::ACE_Select_Reactor_T");

  this->token_.reactor (*this);
  // First try to open the Reactor with the hard-coded default.
  if (this->open (ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::DEFAULT_SIZE,
                  0,
                  sh,
                  tq,
                  disable_notify_pipe,
                  notify) == -1)
    {
      // The hard-coded default Reactor size failed, so attempt to
      // determine the size at run-time by checking the process file
      // descriptor limit on platforms that support this feature.

      // There is no need to deallocate resources from previous open()
      // call since the open() method deallocates any resources prior
      // to exiting if an error was encountered.

      // Set the default reactor size to be the current limit on the
      // number of file descriptors available to the process.  This
      // size is not necessarily the maximum limit.
      if (this->open (ACE::max_handles (),
                     0,
                     sh,
                     tq,
                     disable_notify_pipe,
                     notify) == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%p\n"),
                    ACE_TEXT ("ACE_Select_Reactor_T::open ")
                    ACE_TEXT ("failed inside ")
                    ACE_TEXT ("ACE_Select_Reactor_T::CTOR")));
    }
}

// Initialize ACE_Select_Reactor_T.

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::ACE_Select_Reactor_T
  (size_t size,
   int rs,
   ACE_Sig_Handler *sh,
   ACE_Timer_Queue *tq,
   int disable_notify_pipe,
   ACE_Reactor_Notify *notify,
   bool mask_signals,
   int s_queue)
    : ACE_Select_Reactor_Impl (mask_signals)
    , token_ (s_queue)
    , lock_adapter_ (token_)
    , deactivated_ (0)
{
  ACE_TRACE ("ACE_Select_Reactor_T::ACE_Select_Reactor_T");

  this->token_.reactor (*this);
  if (this->open (size,
                  rs,
                  sh,
                  tq,
                  disable_notify_pipe,
                  notify) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Select_Reactor_T::open ")
                ACE_TEXT ("failed inside ACE_Select_Reactor_T::CTOR")));
}

// Close down the ACE_Select_Reactor_T instance, detaching any
// remaining Event_Handers.  This had better be called from the main
// event loop thread...

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::close (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::close");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (this->delete_signal_handler_)
    {
      delete this->signal_handler_;
      this->signal_handler_ = 0;
      this->delete_signal_handler_ = false;
    }

  this->handler_rep_.close ();

  if (this->delete_timer_queue_)
    {
      delete this->timer_queue_;
      this->timer_queue_ = 0;
      this->delete_timer_queue_ = false;
    }

  if (this->notify_handler_ != 0)
    this->notify_handler_->close ();

  if (this->delete_notify_handler_)
    {
      delete this->notify_handler_;
      this->notify_handler_ = 0;
      this->delete_notify_handler_ = false;
    }

  this->initialized_ = false;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::current_info
  (ACE_HANDLE, size_t &)
{
  return -1;
}

template <class ACE_SELECT_REACTOR_TOKEN>
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::~ACE_Select_Reactor_T (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::~ACE_Select_Reactor_T");
  this->close ();
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler_i
  (const ACE_Handle_Set &handles,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler_i");
  ACE_HANDLE h;

  ACE_Handle_Set_Iterator handle_iter (handles);

  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->remove_handler_i (h, mask) == -1)
      return -1;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler_i
  (const ACE_Handle_Set &handles,
   ACE_Event_Handler *handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler_i");
  ACE_HANDLE h;

  ACE_Handle_Set_Iterator handle_iter (handles);
  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->register_handler_i (h, handler, mask) == -1)
      return -1;

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler
  (const ACE_Sig_Set &sigset,
   ACE_Event_Handler *new_sh,
   ACE_Sig_Action *new_disp)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler");

  int result = 0;

#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; ++s)
    if ((sigset.is_member (s) == 1)
        && this->signal_handler_->register_handler (s,
                                                    new_sh,
                                                    new_disp) == -1)
      result = -1;
#else  /* ACE_NSIG <= 0 */
  ACE_UNUSED_ARG (sigset);
  ACE_UNUSED_ARG (new_sh);
  ACE_UNUSED_ARG (new_disp);
#endif /* ACE_NSIG <= 0 */
  return result;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler
  (const ACE_Sig_Set &sigset)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler");
  int result = 0;

#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; ++s)
    if ((sigset.is_member (s) == 1)
        && this->signal_handler_->remove_handler (s) == -1)
      result = -1;
#else  /* ACE_NSIG <= 0 */
  ACE_UNUSED_ARG (sigset);
#endif /* ACE_NSIG <= 0 */

  return result;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::cancel_timer (ACE_Event_Handler *handler,
                                                              int dont_call_handle_close)
{
  ACE_TRACE ("ACE_Select_Reactor_T::cancel_timer");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (this->timer_queue_ != 0)
    return this->timer_queue_->cancel (handler, dont_call_handle_close);
  else
    return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::cancel_timer (long timer_id,
                                                              const void **arg,
                                                              int dont_call_handle_close)
{
  ACE_TRACE ("ACE_Select_Reactor_T::cancel_timer");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (this->timer_queue_ != 0)
    return this->timer_queue_->cancel (timer_id,
                                       arg,
                                       dont_call_handle_close);
  else
    return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> long
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::schedule_timer
  (ACE_Event_Handler *handler,
   const void *arg,
   const ACE_Time_Value &delay_time,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Select_Reactor_T::schedule_timer");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (0 != this->timer_queue_)
    return this->timer_queue_->schedule
      (handler,
       arg,
       timer_queue_->gettimeofday () + delay_time,
       interval);

  errno = ESHUTDOWN;
  return -1;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::reset_timer_interval
  (long timer_id,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Select_Reactor_T::reset_timer_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  if (0 != this->timer_queue_)
    return this->timer_queue_->reset_interval (timer_id, interval);

  errno = ESHUTDOWN;
  return -1;
}

// Main event loop driver that blocks for <max_wait_time> before
// returning (will return earlier if I/O or signal events occur).

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handle_events
  (ACE_Time_Value &max_wait_time)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handle_events");

  return this->handle_events (&max_wait_time);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handle_error (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handle_error");
#if defined (linux) && defined (ERESTARTNOHAND)
  int const error = errno; // Avoid multiple TSS accesses.
  if (error == EINTR || error == ERESTARTNOHAND)
    return this->restart_;
#else
  if (errno == EINTR)
    return this->restart_;
#endif /* linux && ERESTARTNOHAND */
#if defined (__MVS__) || defined (ACE_WIN32) || defined (ACE_VXWORKS)
  // On MVS Open Edition and Win32, there can be a number of failure
  // codes on a bad socket, so check_handles on anything other than
  // EINTR.  VxWorks doesn't even bother to always set errno on error
  // in select (specifically, it doesn't return EBADF for bad FDs).
  else
    return this->check_handles ();
#else
  else if (errno == EBADF)
    return this->check_handles ();
  else
    return -1;
#endif  /* __MVS__ || ACE_WIN32 */
}

template <class ACE_SELECT_REACTOR_TOKEN> void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::notify_handle
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask,
   ACE_Handle_Set &ready_mask,
   ACE_Event_Handler *event_handler,
   ACE_EH_PTMF ptmf)
{
  ACE_TRACE ("ACE_Select_Reactor_T::notify_handle");
  // Check for removed handlers.
  if (event_handler == 0)
    return;

  bool const reference_counting_required =
    event_handler->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;

  // Call add_reference() if needed.
  if (reference_counting_required)
    {
      event_handler->add_reference ();
    }

  int status = (event_handler->*ptmf) (handle);

  if (status < 0)
    this->remove_handler_i (handle, mask);
  else if (status > 0)
    ready_mask.set_bit (handle);

  // Call remove_reference() if needed.
  if (reference_counting_required)
    event_handler->remove_reference ();
}

// Perform GET, CLR, SET, and ADD operations on the select()
// Handle_Sets.
//
// GET = 1, Retrieve current value
// SET = 2, Set value of bits to new mask (changes the entire mask)
// ADD = 3, Bitwise "or" the value into the mask (only changes
//          enabled bits)
// CLR = 4  Bitwise "and" the negation of the value out of the mask
//          (only changes enabled bits)
//
// Returns the original mask.

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::mask_ops
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask,
   int ops)
{
  ACE_TRACE ("ACE_Select_Reactor_T::mask_ops");
  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1));

  // If the handle is not suspended, then set the ops on the
  // <wait_set_>, otherwise set the <suspend_set_>.

  if (this->is_suspended_i (handle))
    return this->bit_ops (handle, mask,
                          this->suspend_set_,
                          ops);
  else
    return this->bit_ops (handle, mask,
                          this->wait_set_,
                          ops);
}

template <class ACE_SELECT_REACTOR_TOKEN> ACE_Event_Handler *
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::find_handler_i
  (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::find_handler_i");

  ACE_Event_Handler *event_handler =
    this->handler_rep_.find (handle);

  if (event_handler)
    event_handler->add_reference ();

  return event_handler;
}

// Must be called with locks held.

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handler_i
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask,
   ACE_Event_Handler **eh)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handler_i");
  ACE_Event_Handler *event_handler =
    this->handler_rep_.find (handle);

  if (event_handler == 0)
    return -1;
  else
    {
      if ((ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK)
           || ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
          && this->wait_set_.rd_mask_.is_set (handle) == 0)
        return -1;
      if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK)
          && this->wait_set_.wr_mask_.is_set (handle) == 0)
        return -1;
      if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK)
          && this->wait_set_.ex_mask_.is_set (handle) == 0)
        return -1;
    }

  if (eh != 0)
    {
      *eh = event_handler;
      event_handler->add_reference ();
    }

  return 0;
}

// Must be called with locks held

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::resume_i (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::resume_i");
  if (this->handler_rep_.find (handle) == 0)
    return -1;

  if (this->suspend_set_.rd_mask_.is_set (handle))
    {
      this->wait_set_.rd_mask_.set_bit (handle);
      this->suspend_set_.rd_mask_.clr_bit (handle);
    }
  if (this->suspend_set_.wr_mask_.is_set (handle))
    {
      this->wait_set_.wr_mask_.set_bit (handle);
      this->suspend_set_.wr_mask_.clr_bit (handle);
    }
  if (this->suspend_set_.ex_mask_.is_set (handle))
    {
      this->wait_set_.ex_mask_.set_bit (handle);
      this->suspend_set_.ex_mask_.clr_bit (handle);
    }
  return 0;
}

// Must be called with locks held

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::suspend_i (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::suspend_i");
  if (this->handler_rep_.find (handle) == 0)
    return -1;

  if (this->wait_set_.rd_mask_.is_set (handle))
    {
      this->suspend_set_.rd_mask_.set_bit (handle);
      this->wait_set_.rd_mask_.clr_bit (handle);
    }
  if (this->wait_set_.wr_mask_.is_set (handle))
    {
      this->suspend_set_.wr_mask_.set_bit (handle);
      this->wait_set_.wr_mask_.clr_bit (handle);
    }
  if (this->wait_set_.ex_mask_.is_set (handle))
    {
      this->suspend_set_.ex_mask_.set_bit (handle);
      this->wait_set_.ex_mask_.clr_bit (handle);
    }

  // Kobi: we need to remove that handle from the
  // dispatch set as well. We use that function with all the relevant
  // masks - rd/wr/ex - all the mask. it is completely suspended
  this->clear_dispatch_mask (handle, ACE_Event_Handler::RWE_MASK);
  return 0;
}

// Must be called with locks held

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::is_suspended_i (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_Select_Reactor_T::is_suspended_i");
  if (this->handler_rep_.find (handle) == 0)
    return 0;

  return this->suspend_set_.rd_mask_.is_set (handle) ||
         this->suspend_set_.wr_mask_.is_set (handle) ||
         this->suspend_set_.ex_mask_.is_set (handle);

}

// Must be called with locks held

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::register_handler_i
  (ACE_HANDLE handle,
   ACE_Event_Handler *event_handler,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::register_handler_i");

  // Insert the <handle, event_handle> tuple into the Handler
  // Repository.
  return this->handler_rep_.bind (handle, event_handler, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::remove_handler_i
  (ACE_HANDLE handle,
   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Select_Reactor_T::remove_handler_i");

  // Unbind this handle.
  return this->handler_rep_.unbind (handle, mask);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::work_pending
  (const ACE_Time_Value &max_wait_time)
{
  ACE_TRACE ("ACE_Select_Reactor_T::work_pending");

  ACE_Time_Value mwt (max_wait_time);
  ACE_MT (ACE_Countdown_Time countdown (&mwt));

  ACE_MT (ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN,
                            ace_mon,
                            this->token_,
                            -1));

  if (this->deactivated_)
    return 0;

  // Update the countdown to reflect time waiting for the mutex.
  ACE_MT (countdown.update ());

  ACE_Time_Value timer_buf (0);
  ACE_Time_Value *this_timeout =
    this->timer_queue_->calculate_timeout (&mwt, &timer_buf);

  // Check if we have timers to fire.
  bool const timers_pending =
    (this_timeout != 0 && *this_timeout != mwt ? true : false);

#ifdef ACE_WIN32
  // This arg is ignored on Windows and causes pointer truncation
  // warnings on 64-bit compiles.
  int const width = 0;
#else
  int const width = this->handler_rep_.max_handlep1 ();
#endif  /* ACE_WIN32 */

  ACE_Select_Reactor_Handle_Set fd_set;
  fd_set.rd_mask_ = this->wait_set_.rd_mask_;
  fd_set.wr_mask_ = this->wait_set_.wr_mask_;
  fd_set.ex_mask_ = this->wait_set_.ex_mask_;

  int const nfds = ACE_OS::select (width,
                                   fd_set.rd_mask_,
                                   fd_set.wr_mask_,
                                   fd_set.ex_mask_,
                                   this_timeout);

  // If timers are pending, override any timeout from the select()
  // call.
  return (nfds == 0 && timers_pending ? 1 : nfds);
}

// Must be called with lock held.

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::wait_for_multiple_events
  (ACE_Select_Reactor_Handle_Set &dispatch_set,
   ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_Select_Reactor_T::wait_for_multiple_events");
  ACE_Time_Value timer_buf (0);
  ACE_Time_Value *this_timeout = 0;

  int number_of_active_handles = this->any_ready (dispatch_set);

  // If there are any bits enabled in the <ready_set_> then we'll
  // handle those first, otherwise we'll block in <select>.

  if (number_of_active_handles == 0)
    {
      do
        {
          if (this->timer_queue_ == 0)
            return 0;

          this_timeout =
            this->timer_queue_->calculate_timeout (max_wait_time,
                                                   &timer_buf);
#ifdef ACE_WIN32
          // This arg is ignored on Windows and causes pointer
          // truncation warnings on 64-bit compiles.
          int const width = 0;
#else
          int const width = this->handler_rep_.max_handlep1 ();
#endif  /* ACE_WIN32 */

          dispatch_set.rd_mask_ = this->wait_set_.rd_mask_;
          dispatch_set.wr_mask_ = this->wait_set_.wr_mask_;
          dispatch_set.ex_mask_ = this->wait_set_.ex_mask_;
          number_of_active_handles = ACE_OS::select (width,
                                                     dispatch_set.rd_mask_,
                                                     dispatch_set.wr_mask_,
                                                     dispatch_set.ex_mask_,
                                                     this_timeout);
        }
      while (number_of_active_handles == -1 && this->handle_error () > 0);

      if (number_of_active_handles > 0)
        {
#if !defined (ACE_WIN32)
          // Resynchronize the fd_sets so their "max" is set properly.
          dispatch_set.rd_mask_.sync (this->handler_rep_.max_handlep1 ());
          dispatch_set.wr_mask_.sync (this->handler_rep_.max_handlep1 ());
          dispatch_set.ex_mask_.sync (this->handler_rep_.max_handlep1 ());
#endif /* ACE_WIN32 */
        }
      else if (number_of_active_handles == -1)
        {
          // Normally, select() will reset the bits in dispatch_set
          // so that only those filed descriptors that are ready will
          // have bits set.  However, when an error occurs, the bit
          // set remains as it was when the select call was first made.
          // Thus, we now have a dispatch_set that has every file
          // descriptor that was originally waited for, which is not
          // correct.  We must clear all the bit sets because we
          // have no idea if any of the file descriptors is ready.
          //
          // NOTE: We dont have a test case to reproduce this
          // problem. But pleae dont ignore this and remove it off.
          dispatch_set.rd_mask_.reset ();
          dispatch_set.wr_mask_.reset ();
          dispatch_set.ex_mask_.reset ();
        }
    }

  // Return the number of events to dispatch.
  return number_of_active_handles;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dispatch_timer_handlers
  (int &number_of_handlers_dispatched)
{
  number_of_handlers_dispatched += this->timer_queue_->expire ();

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dispatch_notification_handlers
  (ACE_Select_Reactor_Handle_Set &dispatch_set,
   int &number_of_active_handles,
   int &number_of_handlers_dispatched)
{
  // Check to see if the ACE_HANDLE associated with the
  // Select_Reactor's notify hook is enabled.  If so, it means that
  // one or more other threads are trying to update the
  // ACE_Select_Reactor_T's internal tables or the notify pipe is
  // enabled.  We'll handle all these threads and notifications, and
  // then break out to continue the event loop.
  int const n =
    this->notify_handler_->dispatch_notifications (number_of_active_handles,
                                                   dispatch_set.rd_mask_);

  if (n == -1)
    return -1;
  else
    {
      number_of_handlers_dispatched += n;
      number_of_active_handles -= n;
    }

  // Same as dispatch_timer_handlers
  // No need to do anything with the state changed. That is because
  // unbind already handles the case where someone unregister some
  // kind of handle and unbind it. (::unbind calls the function
  // state_changed ()  to reflect ant change with that)
  //   return this->state_changed_ ? -1 : 0;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dispatch_io_set
  (int number_of_active_handles,
   int &number_of_handlers_dispatched,
   int mask,
   ACE_Handle_Set &dispatch_mask,
   ACE_Handle_Set &ready_mask,
   ACE_EH_PTMF callback)
{
  ACE_TRACE ("ACE_Select_Reactor_T::dispatch_io_set");
  ACE_HANDLE handle;

  ACE_Handle_Set_Iterator handle_iter (dispatch_mask);

  while ((handle = handle_iter ()) != ACE_INVALID_HANDLE &&
         number_of_handlers_dispatched < number_of_active_handles)
    {
      ++number_of_handlers_dispatched;

      this->notify_handle (handle,
                           mask,
                           ready_mask,
                           this->handler_rep_.find (handle),
                           callback);

      // clear the bit from that dispatch mask,
      // so when we need to restart the iteration (rebuilding the iterator...)
      // we will not dispatch the already dispatched handlers
      this->clear_dispatch_mask (handle, mask);

      if (this->state_changed_)
        {

          handle_iter.reset_state ();
          this->state_changed_ = false;
        }
    }

  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dispatch_io_handlers
  (ACE_Select_Reactor_Handle_Set &dispatch_set,
   int &number_of_active_handles,
   int &number_of_handlers_dispatched)
{
  ACE_TRACE ("ACE_Select_Reactor_T::dispatch_io_handlers");

  // Handle output events (this code needs to come first to handle the
  // obscure case of piggy-backed data coming along with the final
  // handshake message of a nonblocking connection).

  if (this->dispatch_io_set (number_of_active_handles,
                             number_of_handlers_dispatched,
                             ACE_Event_Handler::WRITE_MASK,
                             dispatch_set.wr_mask_,
                             this->ready_set_.wr_mask_,
                             &ACE_Event_Handler::handle_output) == -1)
    {
      number_of_active_handles -= number_of_handlers_dispatched;
      return -1;
    }

  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Select_Reactor_T::dispatch - EXCEPT\n")));
  if (this->dispatch_io_set (number_of_active_handles,
                             number_of_handlers_dispatched,
                             ACE_Event_Handler::EXCEPT_MASK,
                             dispatch_set.ex_mask_,
                             this->ready_set_.ex_mask_,
                             &ACE_Event_Handler::handle_exception) == -1)
    {
      number_of_active_handles -= number_of_handlers_dispatched;
      return -1;
    }

  // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Select_Reactor_T::dispatch - READ\n")));
  if (this->dispatch_io_set (number_of_active_handles,
                             number_of_handlers_dispatched,
                             ACE_Event_Handler::READ_MASK,
                             dispatch_set.rd_mask_,
                             this->ready_set_.rd_mask_,
                             &ACE_Event_Handler::handle_input) == -1)
    {
      number_of_active_handles -= number_of_handlers_dispatched;
      return -1;
    }

  number_of_active_handles -= number_of_handlers_dispatched;
  return 0;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dispatch
  (int active_handle_count,
   ACE_Select_Reactor_Handle_Set &dispatch_set)
{
  ACE_TRACE ("ACE_Select_Reactor_T::dispatch");

  int io_handlers_dispatched = 0;
  int other_handlers_dispatched = 0;
  int signal_occurred = 0;
  // The following do/while loop keeps dispatching as long as there
  // are still active handles.  Note that the only way we should ever
  // iterate more than once through this loop is if signals occur
  // while we're dispatching other handlers.

  do
    {
      // We expect that the loop will decrease the number of active
      // handles in each iteration.  If it does not, then something is
      // inconsistent in the state of the Reactor and we should avoid
      // the loop.  Please read the comments on bug 2540 for more
      // details.
      int initial_handle_count = active_handle_count;

      // Note that we keep track of changes to our state.  If any of
      // the dispatch_*() methods below return -1 it means that the
      // <wait_set_> state has changed as the result of an
      // <ACE_Event_Handler> being dispatched.  This means that we
      // need to bail out and rerun the select() loop since our
      // existing notion of handles in <dispatch_set> may no longer be
      // correct.
      //
      // In the beginning, our state starts out unchanged.  After
      // every iteration (i.e., due to signals), our state starts out
      // unchanged again.

      this->state_changed_ = false;

      // Perform the Template Method for dispatching all the handlers.

      // First check for interrupts.
      if (active_handle_count == -1)
        {
          // Bail out -- we got here since <select> was interrupted.
          if (ACE_Sig_Handler::sig_pending () != 0)
            {
              ACE_Sig_Handler::sig_pending (0);

              // If any HANDLES in the <ready_set_> are activated as a
              // result of signals they should be dispatched since
              // they may be time critical...
              active_handle_count = this->any_ready (dispatch_set);

              // Record the fact that the Reactor has dispatched a
              // handle_signal() method.  We need this to return the
              // appropriate count below.
              signal_occurred = 1;
            }
          else
            return -1;
        }

      // Handle timers early since they may have higher latency
      // constraints than I/O handlers.  Ideally, the order of
      // dispatching should be a strategy...
      else if (this->dispatch_timer_handlers (other_handlers_dispatched) == -1)
        // State has changed or timer queue has failed, exit loop.
        break;

      // Check to see if there are no more I/O handles left to
      // dispatch AFTER we've handled the timers...
      else if (active_handle_count == 0)
        return io_handlers_dispatched
          + other_handlers_dispatched
          + signal_occurred;

      // Next dispatch the notification handlers (if there are any to
      // dispatch).  These are required to handle multi-threads that
      // are trying to update the <Reactor>.

      else if (this->dispatch_notification_handlers
               (dispatch_set,
                active_handle_count,
                other_handlers_dispatched) == -1)
        // State has changed or a serious failure has occured, so exit
        // loop.
        break;

      // Finally, dispatch the I/O handlers.
      else if (this->dispatch_io_handlers
               (dispatch_set,
                active_handle_count,
                io_handlers_dispatched) == -1)
        // State has changed, so exit loop.
        break;

      // if state changed, we need to re-eval active_handle_count,
      // so we will not end with an endless loop
      if (initial_handle_count == active_handle_count
          || this->state_changed_)
      {
        active_handle_count = this->any_ready (dispatch_set);
      }
    }
  while (active_handle_count > 0);

  return io_handlers_dispatched + other_handlers_dispatched + signal_occurred;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::release_token (void)
{
#if defined (ACE_WIN32)
  this->token_.release ();
  return (int) EXCEPTION_CONTINUE_SEARCH;
#else
  return 0;
#endif /* ACE_WIN32 */
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handle_events
  (ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_Select_Reactor_T::handle_events");

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)

  // Stash the current time -- the destructor of this object will
  // automatically compute how much time elapsed since this method was
  // called.
  ACE_Countdown_Time countdown (max_wait_time);

  ACE_GUARD_RETURN (ACE_SELECT_REACTOR_TOKEN, ace_mon, this->token_, -1);

  if (ACE_OS::thr_equal (ACE_Thread::self (),
                         this->owner_) == 0 || this->deactivated_)
    return -1;

  // Update the countdown to reflect time waiting for the mutex.
  countdown.update ();
#else
  if (this->deactivated_)
    return -1;
#endif /* ACE_MT_SAFE */

  return this->handle_events_i (max_wait_time);
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::handle_events_i
  (ACE_Time_Value *max_wait_time)
{
  int result = -1;

  ACE_SEH_TRY
    {
      // We use the data member dispatch_set_ as the current dispatch
      // set.

      // We need to start from a clean dispatch_set
      this->dispatch_set_.rd_mask_.reset ();
      this->dispatch_set_.wr_mask_.reset ();
      this->dispatch_set_.ex_mask_.reset ();

      int number_of_active_handles =
        this->wait_for_multiple_events (this->dispatch_set_,
                                        max_wait_time);

      result =
        this->dispatch (number_of_active_handles,
                        this->dispatch_set_);
    }
  ACE_SEH_EXCEPT (this->release_token ())
    {
      // As it stands now, we catch and then rethrow all Win32
      // structured exceptions so that we can make sure to release the
      // <token_> lock correctly.
    }

  return result;
}

template <class ACE_SELECT_REACTOR_TOKEN> int
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::check_handles (void)
{
  ACE_TRACE ("ACE_Select_Reactor_T::check_handles");

#if defined (ACE_WIN32) || defined (__MVS__) || defined (ACE_VXWORKS)
  ACE_Time_Value time_poll = ACE_Time_Value::zero;
  ACE_Handle_Set rd_mask;
#endif /* ACE_WIN32 || MVS || ACE_VXWORKS */

  int result = 0;

  /*
   * It's easier to run through the handler repository iterator, but that
   * misses handles that are registered on a handler that doesn't implement
   * get_handle(). So, build a handle set that's the union of the three
   * wait_sets (rd, wrt, ex) and run through that. Bad handles get cleared
   * out of all sets.
   */
  ACE_HANDLE h;
  ACE_Handle_Set check_set (this->wait_set_.rd_mask_);
  ACE_Handle_Set_Iterator wr_iter (this->wait_set_.wr_mask_);
  while ((h = wr_iter ()) != ACE_INVALID_HANDLE)
    check_set.set_bit (h);
  ACE_Handle_Set_Iterator ex_iter (this->wait_set_.ex_mask_);
  while ((h = ex_iter ()) != ACE_INVALID_HANDLE)
    check_set.set_bit (h);

  ACE_Handle_Set_Iterator check_iter (check_set);
  while ((h = check_iter ()) != ACE_INVALID_HANDLE)
    {

#if defined (ACE_WIN32) || defined (__MVS__) || defined (ACE_VXWORKS)
      // Win32 needs to do the check this way because fstat won't work on
      // a socket handle.  MVS Open Edition needs to do it this way because,
      // even though the docs say to check a handle with either select or
      // fstat, the fstat method always says the handle is ok.
      // pSOS needs to do it this way because file handles and socket handles
      // are maintained by separate pieces of the system.  VxWorks needs the select
      // variant since fstat always returns an error on socket FDs.
      rd_mask.set_bit (h);

      int select_width;
#  if defined (ACE_WIN32)
      // This arg is ignored on Windows and causes pointer truncation
      // warnings on 64-bit compiles.
      select_width = 0;
#  else
      select_width = int (h) + 1;
#  endif /* ACE_WIN32 */

      if (ACE_OS::select (select_width,
                          rd_mask, 0, 0,
                          &time_poll) < 0)
        {
          result = 1;
          this->remove_handler_i (h, ACE_Event_Handler::ALL_EVENTS_MASK);
        }
      rd_mask.clr_bit (h);
#else /* !ACE_WIN32 && !MVS && !VXWORKS */
      struct stat temp;

      if (ACE_OS::fstat (h, &temp) == -1)
        {
          result = 1;
          this->remove_handler_i (h, ACE_Event_Handler::ALL_EVENTS_MASK);
        }
#endif /* ACE_WIN32 || MVS */
    }

  return result;
}

template <class ACE_SELECT_REACTOR_TOKEN> void
ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Select_Reactor_T::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  this->timer_queue_->dump ();
  this->handler_rep_.dump ();
  this->signal_handler_->dump ();
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("delete_signal_handler_ = %d\n"),
              this->delete_signal_handler_));

  ACE_HANDLE h;

  for (ACE_Handle_Set_Iterator handle_iter_wr (this->wait_set_.wr_mask_);
       (h = handle_iter_wr ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("write_handle = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_rd (this->wait_set_.rd_mask_);
       (h = handle_iter_rd ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("read_handle = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_ex (this->wait_set_.ex_mask_);
       (h = handle_iter_ex ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("except_handle = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_wr_ready (this->ready_set_.wr_mask_);
       (h = handle_iter_wr_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("write_handle_ready = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_rd_ready (this->ready_set_.rd_mask_);
       (h = handle_iter_rd_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("read_handle_ready = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_ex_ready (this->ready_set_.ex_mask_);
       (h = handle_iter_ex_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("except_handle_ready = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_su_ready (this->suspend_set_.wr_mask_);
       (h = handle_iter_su_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("write_handle_suspend = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_su_ready (this->suspend_set_.rd_mask_);
       (h = handle_iter_su_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("read_handle_suspend = %d\n"), h));

  for (ACE_Handle_Set_Iterator handle_iter_su_ready (this->suspend_set_.ex_mask_);
       (h = handle_iter_su_ready ()) != ACE_INVALID_HANDLE;)
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("except_handle_suspend = %d\n"), h));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("restart_ = %d\n"), this->restart_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("requeue_position_ = %d\n"), this->requeue_position_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("initialized_ = %d\n"), this->initialized_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("owner_ = %d\n"), this->owner_));

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  this->notify_handler_->dump ();
  this->token_.dump ();
#endif /* ACE_MT_SAFE */

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_SELECT_REACTOR_T_CPP */
