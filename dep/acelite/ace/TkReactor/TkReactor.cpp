// $Id: TkReactor.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $
#include "ace/TkReactor/TkReactor.h"

#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Connector.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_TkReactor)

// Must be called with lock held
ACE_TkReactor::ACE_TkReactor (size_t size,
                              bool restart,
                              ACE_Sig_Handler *h)
  : ACE_Select_Reactor (size, restart, h),
    ids_ (0),
    timeout_ (0)
{
  // When the ACE_Select_Reactor is constructed it creates the notify
  // pipe and registers it with the register_handler_i() method. The
  // TkReactor overloads this method BUT because the
  // register_handler_i occurs when constructing the base class
  // ACE_Select_Reactor, the ACE_Select_Reactor register_handler_i()
  // is called not the TkReactor register_handler_i().  This means
  // that the notify pipe is registered with the ACE_Select_Reactor
  // event handling code not the TkReactor and so notfications don't
  // work.  To get around this we simply close and re-opened the
  // notification handler in the constructor of the TkReactor.

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  this->notify_handler_->close ();
  this->notify_handler_->open (this, 0);
#endif /* ACE_MT_SAFE */
}

ACE_TkReactor::~ACE_TkReactor (void)
{
  // Delete the remaining items in the linked list.

  while (this->ids_)
    {
      ACE_TkReactorID *TkID = this->ids_->next_;
      delete this->ids_;
      this->ids_ = TkID;
    }
}

// This is just the <wait_for_multiple_events> from ace/Reactor.cpp
// but we use the Tk functions to wait for an event, not <select>

int
ACE_TkReactor::wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &handle_set,
                                         ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_TkReactor::wait_for_multiple_events");
  int nfound;

  do
    {
      max_wait_time = this->timer_queue_->calculate_timeout (max_wait_time);

      size_t width = this->handler_rep_.max_handlep1 ();
      handle_set.rd_mask_ = this->wait_set_.rd_mask_;
      handle_set.wr_mask_ = this->wait_set_.wr_mask_;
      handle_set.ex_mask_ = this->wait_set_.ex_mask_;
      nfound = TkWaitForMultipleEvents (width,
                                        handle_set,
                                        max_wait_time);

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
ACE_TkReactor::TimerCallbackProc (ClientData cd)
{
  ACE_TkReactor *self = (ACE_TkReactor *) cd;
  self->timeout_ = 0;

  // Deal with any timer events
  ACE_Select_Reactor_Handle_Set handle_set;
  self->dispatch (0, handle_set);
  self->reset_timeout ();
}

/**
 * @todo the unused mask argument is probably quite useful, but we
 *       ignore it, why?  In fact the following comment probably
 *       relates to that:
 *       This could be made shorter if we know which *kind* of event
 *       we were about to get.  Here we use <select> to find out which
 *       one might be available.
 */
void
ACE_TkReactor::InputCallbackProc (ClientData cd,
                                  int /* mask */)
{
  ACE_TkReactor_Input_Callback *callback = (ACE_TkReactor_Input_Callback *) cd;
  ACE_TkReactor *self = callback->reactor_;
  ACE_HANDLE handle = callback->handle_;

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

  int result = ACE_OS::select (handle + 1,
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

int
ACE_TkReactor::TkWaitForMultipleEvents (int width,
                                        ACE_Select_Reactor_Handle_Set &wait_set,
                                        ACE_Time_Value *)
{
  // Check to make sure our handle's are all usable.
  ACE_Select_Reactor_Handle_Set temp_set = wait_set;

  if (ACE_OS::select (width,
                      temp_set.rd_mask_,
                      temp_set.wr_mask_,
                      temp_set.ex_mask_,
                      (ACE_Time_Value *) &ACE_Time_Value::zero) == -1)
    return -1; // Bad file arguments...

  // Instead of waiting using <select>, just use the Tk mechanism to
  // wait for a single event.

  // Wait for something to happen.
  ::Tcl_DoOneEvent (0);

  // Reset the width, in case it changed during the upcalls.
  width = this->handler_rep_.max_handlep1 ();

  // Now actually read the result needed by the <Select_Reactor> using
  // <select>.
  return ACE_OS::select (width,
                         wait_set.rd_mask_,
                         wait_set.wr_mask_,
                         wait_set.ex_mask_,
                         (ACE_Time_Value *) &ACE_Time_Value::zero);
}

int
ACE_TkReactor::register_handler_i (ACE_HANDLE handle,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_TkReactor::register_handler_i");

  int result = ACE_Select_Reactor::register_handler_i (handle,
                                                       handler, mask);
  if (result == -1)
    return -1;

  int condition = 0;

#if !defined ACE_WIN32
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK))
    ACE_SET_BITS (condition, TK_READABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    ACE_SET_BITS (condition, TK_WRITABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    ACE_SET_BITS (condition, TK_EXCEPTION);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    ACE_SET_BITS (condition, TK_READABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK)){
      ACE_SET_BITS (condition, TK_READABLE); // connected, you may write
      ACE_SET_BITS (condition, TK_WRITABLE);  // connected, you have data/err
  }
#else
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK))
    ACE_SET_BITS (condition, TK_READABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    ACE_SET_BITS (condition, TK_WRITABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    ACE_NOTSUP_RETURN(-1);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    ACE_SET_BITS (condition, TK_READABLE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK)){
      ACE_SET_BITS (condition, TK_READABLE); // connected, you may write
      ACE_SET_BITS (condition, TK_WRITABLE);  // connected, you have data/err
  }
#endif /* !ACE_WIN32 */

  if (condition != 0)
    {
      ACE_TkReactorID *TkID = this->ids_;

      while(TkID)
        {
          if (TkID->handle_ == handle)
            {
              ::Tk_DeleteFileHandler (TkID->handle_);

              ACE_TkReactor_Input_Callback *callback;
              ACE_NEW_RETURN (callback,
                              ACE_TkReactor_Input_Callback,
                              -1);
              callback->reactor_ = this;
              callback->handle_ = handle;
              ::Tk_CreateFileHandler ((int) handle,
                                      condition,
                                      InputCallbackProc,
                                      (ClientData) callback);
              return 0;
            }
          else
            TkID = TkID->next_;
        }

      ACE_NEW_RETURN (TkID,
                      ACE_TkReactorID,
                      -1);
      TkID->next_ = this->ids_;
      TkID->handle_ = handle;
      ACE_TkReactor_Input_Callback *callback;
      ACE_NEW_RETURN (callback,
                      ACE_TkReactor_Input_Callback,
                      -1);
      callback->reactor_ = this;
      callback->handle_ = handle;

      ::Tk_CreateFileHandler ((int) handle,
                              condition,
                              InputCallbackProc,
                              (ClientData) callback);
      this->ids_ = TkID;
    }
  return 0;
}

int
ACE_TkReactor::register_handler_i (const ACE_Handle_Set &handles,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::register_handler_i (handles,
                                                 handler,
                                                 mask);
}

int
ACE_TkReactor::remove_handler_i (ACE_HANDLE handle,
                                 ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_TkReactor::remove_handler_i");

  // In the registration phase we registered first with
  // ACE_Select_Reactor and then with X.  Now we are now doing things
  // in reverse order.

  // First clean up the corresponding X11Input.
  this->remove_TkFileHandler (handle);

  // Now let the reactor do its work.
  return ACE_Select_Reactor::remove_handler_i (handle,
                                               mask);
}

void
ACE_TkReactor::remove_TkFileHandler (ACE_HANDLE handle)
{
  ACE_TRACE ("ACE_TkReactor::remove_TkFileHandler");

  ACE_TkReactorID *TkID = this->ids_;

  if (TkID)
    {
      if (TkID->handle_ == handle)
        {
          ::Tk_DeleteFileHandler (TkID->handle_);
          this->ids_ = TkID->next_;
          delete TkID;
          return;
        }

      ACE_TkReactorID *NextID = TkID->next_;

      while (NextID)
        {
          if (NextID->handle_ == handle)
            {
              ::Tk_DeleteFileHandler (NextID->handle_);
              TkID->next_ = NextID->next_;
              delete NextID;
              return;
            }
          else
            {
              TkID = NextID;
              NextID = NextID->next_;
            }
        }
    }
}

int
ACE_TkReactor::remove_handler_i (const ACE_Handle_Set &handles,
                                 ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::remove_handler_i (handles,
                                               mask);
}

// The following functions ensure that there is an Tk timeout for the
// first timeout in the Reactor's Timer_Queue.

void
ACE_TkReactor::reset_timeout (void)
{
  if (this->timeout_)
    ::Tk_DeleteTimerHandler (this->timeout_);
  timeout_ = 0;

  ACE_Time_Value *max_wait_time =
    this->timer_queue_->calculate_timeout (0);

  if (max_wait_time)
    timeout_ = ::Tk_CreateTimerHandler (max_wait_time->msec (),
                                        TimerCallbackProc,
                                        (ClientData) this);
}

int
ACE_TkReactor::reset_timer_interval
  (long timer_id,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_TkReactor::reset_timer_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_Select_Reactor_Token, ace_mon, this->token_, -1));

  int result = ACE_Select_Reactor::timer_queue_->reset_interval
    (timer_id,
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
ACE_TkReactor::schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_TkReactor::schedule_timer");
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
ACE_TkReactor::cancel_timer (ACE_Event_Handler *handler,
                             int dont_call_handle_close)
{
  ACE_TRACE ("ACE_TkReactor::cancel_timer");

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
ACE_TkReactor::cancel_timer (long timer_id,
                             const void **arg,
                             int dont_call_handle_close)
{
  ACE_TRACE ("ACE_TkReactor::cancel_timer");

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
