// $Id: TP_Reactor.cpp 85604 2009-06-11 13:26:00Z johnnyw $

#include "ace/TP_Reactor.h"
#include "ace/Thread.h"
#include "ace/Timer_Queue.h"
#include "ace/Sig_Handler.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_time.h"

#if !defined (__ACE_INLINE__)
#include "ace/TP_Reactor.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID (ace,
           TP_Reactor,
           "$Id: TP_Reactor.cpp 85604 2009-06-11 13:26:00Z johnnyw $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_TP_Reactor)

int
ACE_TP_Token_Guard::acquire_read_token (ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_TP_Token_Guard::acquire_read_token");

  // The order of these events is very subtle, modify with care.

  // Try to grab the lock.  If someone if already there, don't wake
  // them up, just queue up in the thread pool.
  int result = 0;

  if (max_wait_time)
    {
      ACE_Time_Value tv = ACE_OS::gettimeofday ();
      tv += *max_wait_time;

      ACE_MT (result = this->token_.acquire_read (&ACE_TP_Reactor::no_op_sleep_hook,
                                                  0,
                                                  &tv));
    }
  else
    {
      ACE_MT (result = this->token_.acquire_read (&ACE_TP_Reactor::no_op_sleep_hook));
    }

  // Check for timeouts and errors.
  if (result == -1)
    {
      if (errno == ETIME)
        return 0;
      else
        return -1;
    }

  // We got the token and so let us mark ourselves as owner
  this->owner_ = true;

  return result;
}

int
ACE_TP_Token_Guard::acquire_token (ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_TP_Token_Guard::acquire_token");

  // Try to grab the lock.  If someone if already there, don't wake
  // them up, just queue up in the thread pool.
  int result = 0;

  if (max_wait_time)
    {
      ACE_Time_Value tv = ACE_OS::gettimeofday ();
      tv += *max_wait_time;

      ACE_MT (result = this->token_.acquire (0,
                                             0,
                                             &tv));
    }
  else
    {
      ACE_MT (result = this->token_.acquire ());
    }

  // Check for timeouts and errors.
  if (result == -1)
    {
      if (errno == ETIME)
        return 0;
      else
        return -1;
    }

  // We got the token and so let us mark ourselves as owner
  this->owner_ = true;

  return result;
}


ACE_TP_Reactor::ACE_TP_Reactor (ACE_Sig_Handler *sh,
                                ACE_Timer_Queue *tq,
                                bool mask_signals,
                                int s_queue)
  : ACE_Select_Reactor (sh, tq, ACE_DISABLE_NOTIFY_PIPE_DEFAULT, 0, mask_signals, s_queue)
{
  ACE_TRACE ("ACE_TP_Reactor::ACE_TP_Reactor");
  this->supress_notify_renew (1);
}

ACE_TP_Reactor::ACE_TP_Reactor (size_t max_number_of_handles,
                                bool restart,
                                ACE_Sig_Handler *sh,
                                ACE_Timer_Queue *tq,
                                bool mask_signals,
                                int s_queue)
  : ACE_Select_Reactor (max_number_of_handles, restart, sh, tq, ACE_DISABLE_NOTIFY_PIPE_DEFAULT, 0, mask_signals, s_queue)
{
  ACE_TRACE ("ACE_TP_Reactor::ACE_TP_Reactor");
  this->supress_notify_renew (1);
}

int
ACE_TP_Reactor::owner (ACE_thread_t, ACE_thread_t *o_id)
{
  ACE_TRACE ("ACE_TP_Reactor::owner");
  if (o_id)
    *o_id = ACE_Thread::self ();

  return 0;
}

int
ACE_TP_Reactor::owner (ACE_thread_t *t_id)
{
  ACE_TRACE ("ACE_TP_Reactor::owner");
  *t_id = ACE_Thread::self ();

  return 0;
}

int
ACE_TP_Reactor::handle_events (ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_TP_Reactor::handle_events");

  // Stash the current time -- the destructor of this object will
  // automatically compute how much time elapsed since this method was
  // called.
  ACE_Countdown_Time countdown (max_wait_time);

  //
  // The order of these events is very subtle, modify with care.
  //

  // Instantiate the token guard which will try grabbing the token for
  // this thread.
  ACE_TP_Token_Guard guard (this->token_);

  int const result = guard.acquire_read_token (max_wait_time);

  // If the guard is NOT the owner just return the retval
  if (!guard.is_owner ())
    return result;

  // After getting the lock just just for deactivation..
  if (this->deactivated_)
    return -1;

  // Update the countdown to reflect time waiting for the token.
  countdown.update ();

  return this->dispatch_i (max_wait_time, guard);
}

int
ACE_TP_Reactor::dispatch_i (ACE_Time_Value *max_wait_time,
                            ACE_TP_Token_Guard &guard)
{
  int event_count = this->get_event_for_dispatching (max_wait_time);

  // We use this count to detect potential infinite loops as described
  // in bug 2540.
  int const initial_event_count = event_count;

  int result = 0;

  // Note: We are passing the <event_count> around, to have record of
  // how many events still need processing. May be this could be
  // useful in future.

#if 0
  // @Ciju
  // signal handling isn't in a production state yet.
  // Commenting it out for now.

  // Dispatch signals
  if (event_count == -1)
    {
      // Looks like we dont do any upcalls in dispatch signals. If at
      // a later point of time, we decide to handle signals we have to
      // release the lock before we make any upcalls.. What is here
      // now is not the right thing...
      //
      // @@ We need to do better..
      return this->handle_signals (event_count, guard);
    }
#endif // #if 0

  // If there are no signals and if we had received a proper
  // event_count then first look at dispatching timeouts. We need to
  // handle timers early since they may have higher latency
  // constraints than I/O handlers.  Ideally, the order of dispatching
  // should be a strategy...

  // NOTE: The event count does not have the number of timers that
  // needs dispatching. But we are still passing this along. We dont
  // need to do that. In the future we *may* have the timers also
  // returned through the <event_count>. Just passing that along for
  // that day.
  result = this->handle_timer_events (event_count, guard);

  if (result > 0)
    return result;

  // Else just go ahead fall through for further handling.

  if (event_count > 0)
    {
      // Next dispatch the notification handlers (if there are any to
      // dispatch).  These are required to handle multiple-threads
      // that are trying to update the <Reactor>.
      result = this->handle_notify_events (event_count, guard);

      if (result > 0)
        return result;

      // Else just fall through for further handling
    }

  if (event_count > 0)
    {
      // Handle socket events
      result = this->handle_socket_events (event_count, guard);
    }

  if (event_count != 0 && event_count == initial_event_count)
    {
      this->state_changed_ = true;
    }

  return result;
}


#if 0
  // @Ciju
  // signal handling isn't in a production state yet.
  // Commenting it out for now.

int
ACE_TP_Reactor::handle_signals (int & /*event_count*/,
                                ACE_TP_Token_Guard & /*guard*/)
{
  ACE_TRACE ("ACE_TP_Reactor::handle_signals");

  /*
   *
   *             THIS METHOD SEEMS BROKEN
   *
   *
   */
  // First check for interrupts.
  // Bail out -- we got here since <select> was interrupted.
  if (ACE_Sig_Handler::sig_pending () != 0)
    {
      ACE_Sig_Handler::sig_pending (0);

      // This piece of code comes from the old TP_Reactor. We did not
      // handle signals at all then. If we happen to handle signals
      // in the TP_Reactor, we should then start worryiung about this
      // - Bala 21-Aug- 01
if 0
      // Not sure if this should be done in the TP_Reactor
      // case... leave it out for now.   -Steve Huston 22-Aug-00

      // If any HANDLES in the <ready_set_> are activated as a
      // result of signals they should be dispatched since
      // they may be time critical...
      active_handle_count = this->any_ready (dispatch_set);
else
      // active_handle_count = 0;
endif

      // Record the fact that the Reactor has dispatched a
      // handle_signal() method.  We need this to return the
      // appropriate count.
      return 1;
    }

  return -1;
}
#endif // #if 0


int
ACE_TP_Reactor::handle_timer_events (int & /*event_count*/,
                                     ACE_TP_Token_Guard &guard)
{
  if (this->timer_queue_ == 0 || this->timer_queue_->is_empty())
    { // Empty timer queue so cannot have any expired timers.
      return 0;
    }

  // Get the current time
  ACE_Time_Value cur_time (this->timer_queue_->gettimeofday () +
                           this->timer_queue_->timer_skew ());

  // Look for a node in the timer queue whose timer <= the present
  // time.
  ACE_Timer_Node_Dispatch_Info info;

  if (this->timer_queue_->dispatch_info (cur_time, info))
    {
      const void *upcall_act = 0;

      // Preinvoke.
      this->timer_queue_->preinvoke (info, cur_time, upcall_act);

      // Release the token before dispatching notifies...
      guard.release_token ();

      // call the functor
      this->timer_queue_->upcall (info, cur_time);

      // Postinvoke
      this->timer_queue_->postinvoke (info, cur_time, upcall_act);

      // We have dispatched a timer
      return 1;
    }

  return 0;
}

int
ACE_TP_Reactor::handle_notify_events (int & /*event_count*/,
                                      ACE_TP_Token_Guard &guard)
{
  // Get the handle on which notify calls could have occured
  ACE_HANDLE notify_handle = this->get_notify_handle ();

  int result = 0;

  // The notify was not in the list returned by
  // wait_for_multiple_events ().
  if (notify_handle == ACE_INVALID_HANDLE)
    return result;

  // Now just do a read on the pipe..
  ACE_Notification_Buffer buffer;

  // Clear the handle of the read_mask of our <ready_set_>
  this->ready_set_.rd_mask_.clr_bit (notify_handle);

  // Keep reading notifies till we empty it or till we have a
  // dispatchable buffer
  while (this->notify_handler_->read_notify_pipe (notify_handle, buffer) > 0)
    {
      // Just figure out whether we can read any buffer that has
      // dispatchable info. If not we have just been unblocked by
      // another thread trying to update the reactor. If we get any
      // buffer that needs dispatching we will dispatch that after
      // releasing the lock
      if (this->notify_handler_->is_dispatchable (buffer) > 0)
        {
          // Release the token before dispatching notifies...
          guard.release_token ();

          // Dispatch the upcall for the notify
          this->notify_handler_->dispatch_notify (buffer);

          // We had a successful dispatch.
          result = 1;

          // break out of the while loop
          break;
        }
    }

  // If we did some work, then we just return 1 which will allow us
  // to get out of here. If we return 0, then we will be asked to do
  // some work ie. dispacth socket events
  return result;
}

int
ACE_TP_Reactor::handle_socket_events (int &event_count,
                                      ACE_TP_Token_Guard &guard)
{

  // We got the lock, lets handle some I/O events.
  ACE_EH_Dispatch_Info dispatch_info;

  this->get_socket_event_info (dispatch_info);

  // If there is any event handler that is ready to be dispatched, the
  // dispatch information is recorded in dispatch_info.
  if (!dispatch_info.dispatch ())
    {
      // Check for removed handlers.
      if (dispatch_info.event_handler_ == 0)
        {
          this->handler_rep_.unbind(dispatch_info.handle_,
                                    dispatch_info.mask_);
        }


      return 0;
    }

  // Suspend the handler so that other threads don't start dispatching
  // it, if we can't suspend then return directly
  //
  // NOTE: This check was performed in older versions of the
  // TP_Reactor. Looks like it is a waste..
  if (dispatch_info.event_handler_ != this->notify_handler_)
    if (this->suspend_i (dispatch_info.handle_) == -1)
      return 0;

  // Call add_reference() if needed.
  if (dispatch_info.reference_counting_required_)
    dispatch_info.event_handler_->add_reference ();

  // Release the lock.  Others threads can start waiting.
  guard.release_token ();

  int result = 0;

  // If there was an event handler ready, dispatch it.
  // Decrement the event left
  --event_count;

  // Dispatched an event
  if (this->dispatch_socket_event (dispatch_info) == 0)
    ++result;

  return result;
}

int
ACE_TP_Reactor::get_event_for_dispatching (ACE_Time_Value *max_wait_time)
{
  // If the reactor handler state has changed, clear any remembered
  // ready bits and re-scan from the master wait_set.
  if (this->state_changed_)
    {
      this->ready_set_.rd_mask_.reset ();
      this->ready_set_.wr_mask_.reset ();
      this->ready_set_.ex_mask_.reset ();

      this->state_changed_ = false;
    }
  else
    {
      // This is a hack... somewhere, under certain conditions (which
      // I don't understand...) the mask will have all of its bits clear,
      // yet have a size_ > 0. This is an attempt to remedy the affect,
      // without knowing why it happens.

      this->ready_set_.rd_mask_.sync (this->ready_set_.rd_mask_.max_set ());
      this->ready_set_.wr_mask_.sync (this->ready_set_.wr_mask_.max_set ());
      this->ready_set_.ex_mask_.sync (this->ready_set_.ex_mask_.max_set ());
    }

  return this->wait_for_multiple_events (this->ready_set_, max_wait_time);
}

int
ACE_TP_Reactor::get_socket_event_info (ACE_EH_Dispatch_Info &event)
{
  // Check for dispatch in write, except, read. Only catch one, but if
  // one is caught, be sure to clear the handle from each mask in case
  // there is more than one mask set for it. This would cause problems
  // if the handler is suspended for dispatching, but its set bit in
  // another part of ready_set_ kept it from being dispatched.
  int found_io = 0;
  ACE_HANDLE handle;

  // @@todo: We can do quite a bit of code reduction here. Let me get
  // it to work before I do this.
  {
    ACE_Handle_Set_Iterator handle_iter (this->ready_set_.wr_mask_);

    while (!found_io && (handle = handle_iter ()) != ACE_INVALID_HANDLE)
      {
        if (this->is_suspended_i (handle))
          continue;

        // Remember this info
        event.set (handle,
                   this->handler_rep_.find (handle),
                   ACE_Event_Handler::WRITE_MASK,
                   &ACE_Event_Handler::handle_output);

        this->clear_handle_read_set (handle);
        found_io = 1;
      }
  }

  if (!found_io)
    {
      ACE_Handle_Set_Iterator handle_iter (this->ready_set_.ex_mask_);

      while (!found_io && (handle = handle_iter ()) != ACE_INVALID_HANDLE)
        {
          if (this->is_suspended_i (handle))
            continue;

          // Remember this info
          event.set (handle,
                     this->handler_rep_.find (handle),
                     ACE_Event_Handler::EXCEPT_MASK,
                     &ACE_Event_Handler::handle_exception);

          this->clear_handle_read_set (handle);

          found_io = 1;
        }
    }

  if (!found_io)
    {
      ACE_Handle_Set_Iterator handle_iter (this->ready_set_.rd_mask_);

      while (!found_io && (handle = handle_iter ()) != ACE_INVALID_HANDLE)
        {
          if (this->is_suspended_i (handle))
            continue;

          // Remember this info
          event.set (handle,
                     this->handler_rep_.find (handle),
                     ACE_Event_Handler::READ_MASK,
                     &ACE_Event_Handler::handle_input);

          this->clear_handle_read_set (handle);
          found_io = 1;
        }
    }

  return found_io;
}

// Dispatches a single event handler
int
ACE_TP_Reactor::dispatch_socket_event (ACE_EH_Dispatch_Info &dispatch_info)
{
  ACE_TRACE ("ACE_TP_Reactor::dispatch_socket_event");

  ACE_Event_Handler * const event_handler = dispatch_info.event_handler_;
  ACE_EH_PTMF const callback = dispatch_info.callback_;

  // Check for removed handlers.
  if (event_handler == 0)
    return -1;

  // Upcall. If the handler returns positive value (requesting a
  // reactor callback) don't set the ready-bit because it will be
  // ignored if the reactor state has changed. Just call back
  // as many times as the handler requests it. Other threads are off
  // handling other things.
  int status = 1;
  while (status > 0)
    status = (event_handler->*callback) (dispatch_info.handle_);

  // Post process socket event
  return this->post_process_socket_event (dispatch_info, status);
}

int
ACE_TP_Reactor::post_process_socket_event (ACE_EH_Dispatch_Info &dispatch_info,
                                           int status)
{
  int result = 0;

  // First check if we really have to post process something, if not, then
  // we don't acquire the token which saves us a lot of time.
  if (status < 0 ||
     (dispatch_info.event_handler_ != this->notify_handler_ &&
      dispatch_info.resume_flag_ ==
        ACE_Event_Handler::ACE_REACTOR_RESUMES_HANDLER))
    {
      // Get the reactor token and with this token acquired remove first the
      // handler and resume it at the same time. This must be atomic, see also
      // bugzilla 2395. When this is not atomic it can be that we resume the
      // handle after it is reused by the OS.
      ACE_TP_Token_Guard guard (this->token_);

      result = guard.acquire_token ();

      // If the guard is NOT the owner just return the retval
      if (!guard.is_owner ())
        return result;

      // A different event handler may have been registered during the
      // upcall if the handle was closed and then reopened, for
      // example.  Make sure we're removing and/or resuming the event
      // handler used during the upcall.
      ACE_Event_Handler const * const eh =
        this->handler_rep_.find (dispatch_info.handle_);

      // Only remove or resume the event handler used during the
      // upcall.
      if (eh == dispatch_info.event_handler_)
        {
          if (status < 0)
            {
              result =
                this->remove_handler_i (dispatch_info.handle_,
                                        dispatch_info.mask_);
            }

          // Resume handler if required.
          if (dispatch_info.event_handler_ != this->notify_handler_ &&
              dispatch_info.resume_flag_ ==
              ACE_Event_Handler::ACE_REACTOR_RESUMES_HANDLER)
            this->resume_i (dispatch_info.handle_);
        }
    }

  // Call remove_reference() if needed.
  if (dispatch_info.reference_counting_required_)
    dispatch_info.event_handler_->remove_reference ();

  return result;
}

int
ACE_TP_Reactor::resumable_handler (void)
{
  return 1;
}

int
ACE_TP_Reactor::handle_events (ACE_Time_Value &max_wait_time)
{
  return this->handle_events (&max_wait_time);
}

void
ACE_TP_Reactor::notify_handle (ACE_HANDLE,
                               ACE_Reactor_Mask,
                               ACE_Handle_Set &,
                               ACE_Event_Handler *eh,
                               ACE_EH_PTMF)
{
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("ACE_TP_Reactor::notify_handle: ")
              ACE_TEXT ("Wrong version of notify_handle() got called\n")));

  ACE_ASSERT (eh == 0);
  ACE_UNUSED_ARG (eh);
}

ACE_HANDLE
ACE_TP_Reactor::get_notify_handle (void)
{
  // Call the notify handler to get a handle on which we would have a
  // notify waiting
  ACE_HANDLE const read_handle =
    this->notify_handler_->notify_handle ();

  // Check whether the rd_mask has been set on that handle. If so
  // return the handle.
  if (read_handle != ACE_INVALID_HANDLE &&
      this->ready_set_.rd_mask_.is_set (read_handle))
    {
      return read_handle;
    }

  // None found..
  return ACE_INVALID_HANDLE;
}

ACE_END_VERSIONED_NAMESPACE_DECL
