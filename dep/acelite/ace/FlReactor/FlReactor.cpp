// $Id: FlReactor.cpp 95511 2012-01-27 09:40:38Z johnnyw $

#include "ace/FlReactor/FlReactor.h"

#include /**/ <FL/Fl.H>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_FlReactor)

// Must be called with lock held
ACE_FlReactor::ACE_FlReactor (size_t size,
                              bool restart,
                              ACE_Sig_Handler *h)
  : ACE_Select_Reactor (size, restart, h)
{
  // When the ACE_Select_Reactor is constructed it creates the notify
  // pipe and registers it with the register_handler_i() method. The
  // FlReactor overloads this method BUT because the
  // register_handler_i occurs when constructing the base class
  // ACE_Select_Reactor, the ACE_Select_Reactor register_handler_i()
  // is called not the FlReactor register_handler_i().  This means
  // that the notify pipe is registered with the ACE_Select_Reactor
  // event handling code not the FlReactor and so notfications don't
  // work.  To get around this we simply close and re-opened the
  // notification handler in the constructor of the FlReactor.

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  this->notify_handler_->close ();
  this->notify_handler_->open (this, 0);
#endif /* ACE_MT_SAFE */
}

ACE_FlReactor::~ACE_FlReactor (void)
{
}

// This is just the <wait_for_multiple_events> from ace/Reactor.cpp
// but we use the Fl functions to wait for an event, not <select>

int
ACE_FlReactor::wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &handle_set,
                                         ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_FlReactor::wait_for_multiple_events");
  int nfound;

  do
    {
      max_wait_time = this->timer_queue_->calculate_timeout (max_wait_time);

      size_t width = this->handler_rep_.max_handlep1 ();
      handle_set.rd_mask_ = this->wait_set_.rd_mask_;
      handle_set.wr_mask_ = this->wait_set_.wr_mask_;
      handle_set.ex_mask_ = this->wait_set_.ex_mask_;

      // Check to make sure our handle's are all usable.
      ACE_Select_Reactor_Handle_Set temp_set = handle_set;

      ACE_Time_Value zero = ACE_Time_Value::zero;
      if (ACE_OS::select (width,
                          temp_set.rd_mask_,
                          temp_set.wr_mask_,
                          temp_set.ex_mask_,
                          &zero) == -1)
        return -1; // Bad file arguments...

      // Instead of waiting using <select>, just use the Fl mechanism
      // to wait for one or more events...

      // Wait for something to happen.
      double t = 0;
      if (max_wait_time != 0)
        t = max_wait_time->sec () + max_wait_time->usec () / 1000000.0F;

      while (t > 0) {
        t = Fl::wait (t);
      }

      // Reset the width, in case it changed during the upcalls.
      width = this->handler_rep_.max_handlep1 ();

      // Now actually read the result needed by the <Select_Reactor>
      // using <select>.
      zero = ACE_Time_Value::zero;
      nfound = ACE_OS::select (width,
                               handle_set.rd_mask_,
                               handle_set.wr_mask_,
                               handle_set.ex_mask_,
                               &zero);

    } while (nfound == -1 && this->handle_error () > 0);

  if (nfound > 0)
    {
#if !defined (ACE_WIN32)
      handle_set.rd_mask_.sync (this->handler_rep_.max_handlep1 ());
      handle_set.wr_mask_.sync (this->handler_rep_.max_handlep1 ());
      handle_set.ex_mask_.sync (this->handler_rep_.max_handlep1 ());
#endif /* ACE_WIN32 */
    }
  return nfound; // Timed out or input available
}

void
ACE_FlReactor::fl_io_proc (int fd, void* reactor)
{
  ACE_FlReactor *self = static_cast<ACE_FlReactor *> (reactor);
  ACE_HANDLE handle = (ACE_HANDLE)fd; //reinterpret_cast<ACE_HANDLE> (fd);

  // my copy isn't const.
  ACE_Time_Value zero = ACE_Time_Value::zero;

  ACE_Select_Reactor_Handle_Set wait_set;

  // Deal with one file event.

  // - read which kind of event
  if (self->wait_set_.rd_mask_.is_set (handle))
    wait_set.rd_mask_.set_bit (handle);
  if (self->wait_set_.wr_mask_.is_set (handle))
    wait_set.wr_mask_.set_bit (handle);
  if (self->wait_set_.ex_mask_.is_set (handle))
    wait_set.ex_mask_.set_bit (handle);

  int result = ACE_OS::select (fd + 1,
                               wait_set.rd_mask_,
                               wait_set.wr_mask_,
                               wait_set.ex_mask_, &zero);

  ACE_Select_Reactor_Handle_Set dispatch_set;

  // - Use only that one file event (removes events for other files).
  if (result > 0)
    {
      if (wait_set.rd_mask_.is_set (handle))
        dispatch_set.rd_mask_.set_bit (handle);
      if (wait_set.wr_mask_.is_set (handle))
        dispatch_set.wr_mask_.set_bit (handle);
      if (wait_set.ex_mask_.is_set (handle))
        dispatch_set.ex_mask_.set_bit (handle);

      self->dispatch (1, dispatch_set);
    }
}

void
ACE_FlReactor::fl_timeout_proc (void* reactor)
{
  ACE_FlReactor *self = static_cast<ACE_FlReactor *> (reactor);

  // Deal with any timer events
  ACE_Select_Reactor_Handle_Set handle_set;
  self->dispatch (0, handle_set);
  self->reset_timeout ();
}


int
ACE_FlReactor::register_handler_i (ACE_HANDLE handle,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_FlReactor::register_handler_i");

  int result = ACE_Select_Reactor::register_handler_i (handle,
                                                       handler, mask);
  if (result == -1)
    return -1;

  int condition = 0;

  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK))
    ACE_SET_BITS (condition, FL_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    ACE_SET_BITS (condition, FL_WRITE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    ACE_SET_BITS (condition, FL_EXCEPT);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    ACE_SET_BITS (condition, FL_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK))
    {
      ACE_SET_BITS (condition, FL_WRITE); // connected, you may write
      ACE_SET_BITS (condition, FL_READ);  // connected, you have data/err
    }

  if (condition != 0)
    {
      Fl::add_fd ((int)handle, // reinterpret_cast<int> (handle),
                  ACE_FlReactor::fl_io_proc,
                  this);
    }
  return 0;
}

int
ACE_FlReactor::register_handler_i (const ACE_Handle_Set &handles,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::register_handler_i (handles,
                                                 handler,
                                                 mask);
}

int
ACE_FlReactor::remove_handler_i (ACE_HANDLE handle,
                                 ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_FlReactor::remove_handler_i");

  // In the registration phase we registered first with
  // ACE_Select_Reactor and then with X.  Now we are now doing things
  // in reverse order.

  // First clean up the corresponding X11Input.
  Fl::remove_fd ((int)handle); // reinterpret_cast<int> (handle);

  // Now let the reactor do its work.
  return ACE_Select_Reactor::remove_handler_i (handle,
                                               mask);
}

int
ACE_FlReactor::remove_handler_i (const ACE_Handle_Set &handles,
                                 ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::remove_handler_i (handles,
                                               mask);
}

// The following function ensures there's an Fl timeout for the first
// timeout in the Reactor's Timer_Queue.

void
ACE_FlReactor::reset_timeout (void)
{
  ACE_Time_Value *max_wait_time =
    this->timer_queue_->calculate_timeout (0);

  if (max_wait_time != 0)
    {
      float t = max_wait_time->sec ()
        + max_wait_time->usec () / 1000000.0F;
      Fl::add_timeout (t,
                       ACE_FlReactor::fl_timeout_proc,
                       this);
    }
}

int
ACE_FlReactor::reset_timer_interval
  (long timer_id,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_FlReactor::reset_timer_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_Select_Reactor_Token, ace_mon, this->token_, -1));

  int const result =
    ACE_Select_Reactor::reset_timer_interval (timer_id,
                                              interval);

  if (result == -1)
    return -1;
  else
    {
      this->reset_timeout ();
      return result;
    }
}

long
ACE_FlReactor::schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_FlReactor::schedule_timer");
  ACE_MT (ACE_GUARD_RETURN (ACE_Select_Reactor_Token, ace_mon, this->token_, -1));

  long result = ACE_Select_Reactor::schedule_timer (event_handler,
                                                    arg,
                                                    delay,
                                                    interval);
  if (result == -1)
    return -1;
  else
    {
      this->reset_timeout ();
      return result;
    }
}

int
ACE_FlReactor::cancel_timer (ACE_Event_Handler *handler,
                             int dont_call_handle_close)
{
  ACE_TRACE ("ACE_FlReactor::cancel_timer");

  if (ACE_Select_Reactor::cancel_timer (handler,
                                        dont_call_handle_close) == -1)
    return -1;
  else
    {
      this->reset_timeout ();
      return 0;
    }
}

int
ACE_FlReactor::cancel_timer (long timer_id,
                             const void **arg,
                             int dont_call_handle_close)
{
  ACE_TRACE ("ACE_FlReactor::cancel_timer");

  if (ACE_Select_Reactor::cancel_timer (timer_id,
                                        arg,
                                        dont_call_handle_close) == -1)
    return -1;
  else
    {
      this->reset_timeout ();
      return 0;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
