// $Id: Timer_Queue_Adapters.cpp 89482 2010-03-15 07:58:50Z johnnyw $

#ifndef ACE_TIMER_QUEUE_ADAPTERS_CPP
#define ACE_TIMER_QUEUE_ADAPTERS_CPP

#include "ace/Timer_Queue_Adapters.h"

#if defined (ACE_HAS_DEFERRED_TIMER_COMMANDS)
#include "ace/Functor.h"
#endif /* ACE_HAS_DEFERRED_TIMER_COMMANDS */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

# if !defined (__ACE_INLINE__)
#  include "ace/Timer_Queue_Adapters.inl"
# endif /* __ACE_INLINE__ */

#include "ace/Signal.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TQ, class TYPE> TQ &
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::timer_queue (void)
{
  return this->timer_queue_;
}

template <class TQ, class TYPE> int
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::cancel (long timer_id,
                                           const void **act)
{
  // Block designated signals.
  ACE_Sig_Guard sg (&this->mask_);
  ACE_UNUSED_ARG (sg);

  return this->timer_queue_.cancel (timer_id, act);
}

template <class TQ, class TYPE> int
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::expire (void)
{
  // Block designated signals.
  ACE_Sig_Guard sg (&this->mask_);
  ACE_UNUSED_ARG (sg);

  return this->timer_queue_.expire ();
}

template <class TQ, class TYPE> int
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::schedule_ualarm (void)
{
  ACE_Time_Value tv = this->timer_queue_.earliest_time ()
    - this->timer_queue_.gettimeofday ();

  // Beware of negative times and zero times (which cause problems for
  // <ualarm>).
  if (tv < ACE_Time_Value::zero)
    tv = ACE_Time_Value (0, 1);

  // @@ This code should be clever enough to avoid updating the
  // <ualarm> if we haven't actually changed the earliest time.
  // Schedule a new timer.
  ACE_OS::ualarm (tv);
  return 0;
}

template <class TQ, class TYPE> long
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::schedule (TYPE eh,
                                             const void *act,
                                             const ACE_Time_Value &future_time,
                                             const ACE_Time_Value &interval)
{
  ACE_UNUSED_ARG (act);
  ACE_UNUSED_ARG (interval);

  // Block designated signals.
  ACE_Sig_Guard sg (&this->mask_);
  ACE_UNUSED_ARG (sg);

  // @@ We still need to implement interval timers...
  long tid = this->timer_queue_.schedule (eh, act, future_time);

  if (tid == -1)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%p\n"),
                       ACE_TEXT ("schedule_timer")),
                      -1);

  if (this->schedule_ualarm () == -1)
    return 0;

  return tid;
}

template <class TQ, class TYPE>
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::ACE_Async_Timer_Queue_Adapter (ACE_Sig_Set *mask)
  // If <mask> == 0, block *all* signals when the SIGARLM handler is
  // running, else just block those in the mask.
  : mask_ (mask)
{
  // The following code is necessary to selectively "block" certain
  // signals when SIGALRM is running.  Also, we always restart system
  // calls that are interrupted by the signals.

  ACE_Sig_Action sa ((ACE_SignalHandler) 0,
                     this->mask_,
                     SA_RESTART);

  if (this->sig_handler_.register_handler (SIGALRM, this, &sa) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("register_handler")));
}

// This is the signal handler function for the asynchronous timer
// list.  It gets invoked asynchronously when the SIGALRM signal
// occurs.

template <class TQ, class TYPE> int
ACE_Async_Timer_Queue_Adapter<TQ, TYPE>::handle_signal (int signum,
                                                  siginfo_t *,
                                                  ucontext_t *)
{
  switch (signum)
    {
    case SIGALRM:
      {
        // Expire the pending timers.

        // @@ We need to figure out how to implement interval
        // timers...
        this->timer_queue_.expire ();

        // Only schedule a new timer if there is one in the list.

        // @@ This code should also become smarter to avoid
        // unnecessary calls to ualarm().
        if (this->timer_queue_.is_empty () == 0)
          return this->schedule_ualarm ();
        else
          return 0;
        /* NOTREACHED */
      }
    default:
      ACE_ERROR_RETURN ((LM_ERROR,
                         "unexpected signal %S\n",
                         signum),
                        -1);
      /* NOTREACHED */
    }
}

template<class TQ, class TYPE>
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::ACE_Thread_Timer_Queue_Adapter (ACE_Thread_Manager *tm,
                                                                    TQ* timer_queue)
  : ACE_Task_Base (tm),
    timer_queue_(timer_queue),
    delete_timer_queue_(false),
    condition_ (mutex_),
    active_ (true), // Assume that we start in active mode.
    thr_id_ (ACE_OS::NULL_thread)
{
  if (timer_queue_ == 0)
    {
      ACE_NEW (this->timer_queue_,
               TQ);
      this->delete_timer_queue_ = true;
    }
}

template<class TQ, class TYPE>
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::~ACE_Thread_Timer_Queue_Adapter (void)
{
  if (this->delete_timer_queue_)
    {
      delete this->timer_queue_;
      this->timer_queue_ = 0;
      this->delete_timer_queue_ = false;
    }
}

template<class TQ, class TYPE> ACE_SYNCH_RECURSIVE_MUTEX &
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::mutex (void)
{
  return this->mutex_;
}

template<class TQ, class TYPE> long
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::schedule
    (TYPE handler,
     const void *act,
     const ACE_Time_Value &future_time,
     const ACE_Time_Value &interval)
{
  ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX, guard, this->mutex_, -1);

  long result = this->timer_queue_->schedule (handler, act, future_time, interval);
  this->condition_.signal ();
  return result;
}

template<class TQ, class TYPE> int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::cancel (long timer_id,
                                            const void **act)
{
  ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX, guard, this->mutex_, -1);

  int result = this->timer_queue_->cancel (timer_id, act);
  condition_.signal ();
  return result;
}

template<class TQ, class TYPE> void
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::deactivate (void)
{
  ACE_GUARD (ACE_SYNCH_RECURSIVE_MUTEX, guard, this->mutex_);

  this->active_ = false;
  this->condition_.signal ();
}

template<class TQ, class TYPE> int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::svc (void)
{
  ACE_GUARD_RETURN (ACE_SYNCH_RECURSIVE_MUTEX, guard, this->mutex_, -1);

  this->thr_id_ = ACE_Thread::self ();

  // Thread cancellation point, if ACE supports it.
  //
  // Note: This call generates a warning under Solaris because the header
  //       file /usr/include/pthread.h redefines the routine argument. This
  //       is a bug in the Solaris header files and has nothing to do with
  //       ACE.
# if !defined (ACE_LACKS_PTHREAD_CANCEL)
  ACE_PTHREAD_CLEANUP_PUSH (&this->condition_.mutex ().get_nesting_mutex ());
# endif /* ACE_LACKS_PTHREAD_CANCEL */

  while (this->active_)
    {
# if defined (ACE_HAS_DEFERRED_TIMER_COMMANDS)
      // Temporarily suspend ownership of the timer queue mutex in
      // order to dispatch deferred execution commands.  These
      // commands are to be treated as executing in a context
      // "external" to the timer queue adapter, and thus must compete
      // separately for this lock.
      mutex_.release ();
      this->dispatch_commands ();

      // Re-acquire ownership of the timer queue mutex in order to
      // restore the "internal" timer queue adapter context
      mutex_.acquire ();
# endif /* ACE_HAS_DEFERRED_TIMER_COMMANDS */

      // If the queue is empty, sleep until there is a change on it.
      if (this->timer_queue_->is_empty ())
        this->condition_.wait ();
      else
        {
          // Compute the remaining time, being careful not to sleep
          // for "negative" amounts of time.
          ACE_Time_Value const tv_curr = this->timer_queue_->gettimeofday ();
          ACE_Time_Value const tv_earl = this->timer_queue_->earliest_time ();

          if (tv_earl > tv_curr)
            {
              // The earliest time on the Timer_Queue is in future, so
              // use ACE_OS::gettimeofday() to convert the tv to the
              // absolute time.
              ACE_Time_Value const tv = ACE_OS::gettimeofday () + (tv_earl - tv_curr);
              // ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("waiting until %u.%3.3u secs\n"),
              // tv.sec(), tv.msec()));
              this->condition_.wait (&tv);
            }
        }

      // Expire timers anyway, at worst this is a no-op.
      this->timer_queue_->expire ();
    }

   // Thread cancellation point, if ACE supports it.
# if !defined (ACE_LACKS_PTHREAD_CANCEL)
  ACE_PTHREAD_CLEANUP_POP (0);
# endif /* ACE_LACKS_PTHREAD_CANCEL */

  return 0;
}

template<class TQ, class TYPE> int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::activate (long flags,
                                              int ,
                                              int ,
                                              long priority,
                                              int grp_id,
                                              ACE_Task_Base *task,
                                              ACE_hthread_t [],
                                              void *stack[],
                                              size_t stack_size[],
                                              ACE_thread_t thread_ids[],
                                              const char* thr_name[])
{
  // Make sure to set this flag in case we were deactivated earlier.
  this->active_ = true;

  // Make sure that we only allow a single thread to be spawned for
  // our adapter.  Otherwise, too many weird things can happen.
  return ACE_Task_Base::activate (flags, 1, 0, priority, grp_id, task, 0,
                                  stack, stack_size, thread_ids, thr_name);
}

# if defined (ACE_HAS_DEFERRED_TIMER_COMMANDS)

// Enqueues a command object for execution just before waiting on the next
// timer event. This allows deferred execution of commands that cannot
// be performed in the timer event handler context, such as registering
// or cancelling timers on platforms where the timer queue mutex is not
// recursive.

template<class TQ, class TYPE> int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::enqueue_command (ACE_Command_Base *cmd,
                                                     COMMAND_ENQUEUE_POSITION pos)
{
  // Serialize access to the command queue.
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->command_mutex_, -1);

  if (pos == ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::TAIL)
    return command_queue_.enqueue_tail (cmd);
  else
    return command_queue_.enqueue_head (cmd);
}

// Dispatches all command objects enqueued in the most recent event
// handler context.

template<class TQ, class TYPE> int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::dispatch_commands (void)
{
  // Serialize access to the command queue.
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, guard, this->command_mutex_, -1);

  // loop through the enqueued commands
  ACE_Command_Base *cmd = 0;
  while (command_queue_.dequeue_head (cmd) == 0)
    if (cmd)
      {
        cmd->execute ();
        delete cmd;
      }

  return 0;
}

# endif /* ACE_HAS_DEFERRED_TIMER_COMMANDS */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TIMER_QUEUE_ADAPTERS_CPP */
