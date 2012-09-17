// $Id: FoxReactor.cpp 93117 2011-01-20 12:11:28Z mcorino $

#include "ace/FoxReactor/FoxReactor.h"

FXDEFMAP(ACE_FoxReactor) ACE_FoxReactorMap[]={
  FXMAPFUNCS(SEL_IO_READ,0,MAXKEY,ACE_FoxReactor::onFileEvents),
  FXMAPFUNCS(SEL_IO_WRITE,0,MAXKEY,ACE_FoxReactor::onFileEvents),
  FXMAPFUNCS(SEL_IO_EXCEPT,0,MAXKEY,ACE_FoxReactor::onFileEvents),
  FXMAPFUNCS(SEL_TIMEOUT,0,MAXKEY,ACE_FoxReactor::onTimerEvents),
};

FXIMPLEMENT(ACE_FoxReactor,FXObject,ACE_FoxReactorMap,ARRAYNUMBER(ACE_FoxReactorMap))

ACE_ALLOC_HOOK_DEFINE (ACE_FoxReactor)

// Must be called with lock held
ACE_FoxReactor::ACE_FoxReactor (FXApp* a,
                                size_t size,
                                bool restart,
                                ACE_Sig_Handler *h)
  : ACE_Select_Reactor (size, restart, h), fxapp(a)
{
  // When the ACE_Select_Reactor is constructed it creates the notify
  // pipe and registers it with the register_handler_i() method. The
  // FoxReactor overloads this method BUT because the
  // register_handler_i occurs when constructing the base class
  // ACE_Select_Reactor, the ACE_Select_Reactor register_handler_i()
  // is called not the FoxReactor register_handler_i().  This means
  // that the notify pipe is registered with the ACE_Select_Reactor
  // event handling code not the FoxReactor and so notfications don't
  // work.  To get around this we simply close and re-opened the
  // notification handler in the constructor of the FoxReactor.

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  this->notify_handler_->close ();
  this->notify_handler_->open (this, 0);
#endif /* ACE_MT_SAFE */
}

ACE_FoxReactor::~ACE_FoxReactor (void)
{
}

void ACE_FoxReactor::fxapplication(FXApp *a)
{
   fxapp=a;
}

// This is just the <wait_for_multiple_events> from ace/Reactor.cpp
// but we use the Fox functions to wait for an event, not <select>

int
ACE_FoxReactor::wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &handle_set,
                                         ACE_Time_Value *max_wait_time)
{
  ACE_TRACE( "ACE_FoxReactor::wait_for_multiple_events" );

  int nfound = 0;
  do
  {
    max_wait_time = this->timer_queue_->calculate_timeout (max_wait_time);
    size_t width = this->handler_rep_.max_handlep1 ();
    handle_set.rd_mask_ = this->wait_set_.rd_mask_;
    handle_set.wr_mask_ = this->wait_set_.wr_mask_;
    handle_set.ex_mask_ = this->wait_set_.ex_mask_;

    nfound = FoxWaitForMultipleEvents (width,
                                      handle_set,
                                      max_wait_time);

  } while( nfound == -1 && this->handle_error () > 0 );

  if (nfound > 0)
  {
#if !defined (ACE_WIN32)
    handle_set.rd_mask_.sync (this->handler_rep_.max_handlep1 ());
    handle_set.wr_mask_.sync (this->handler_rep_.max_handlep1 ());
    handle_set.ex_mask_.sync (this->handler_rep_.max_handlep1 ());
#endif /* ACE_WIN32 */
  }

  return nfound;
  // Timed out or input available
}

int
ACE_FoxReactor::FoxWaitForMultipleEvents (int width,
                                        ACE_Select_Reactor_Handle_Set &wait_set,
                                        ACE_Time_Value */*max_wait_time*/)
{
  // Check to make sure our handle's are all usable.
  ACE_Select_Reactor_Handle_Set temp_set = wait_set;

  if (ACE_OS::select (width,
                      temp_set.rd_mask_,
                      temp_set.wr_mask_,
                      temp_set.ex_mask_,
                      (ACE_Time_Value *) &ACE_Time_Value::zero ) == -1)
    return -1; // Bad file arguments...

  // Qt processing.
  this->fxapp->runOneEvent () ;

  // Reset the width, in case it changed during the upcalls.
  width = handler_rep_.max_handlep1 ();

  // Now actually read the result needed by the <Select_Reactor> using
  // <select>.
  return ACE_OS::select(width,
                        wait_set.rd_mask_,
                        wait_set.wr_mask_,
                        wait_set.ex_mask_,
                        (ACE_Time_Value *) &ACE_Time_Value::zero);
}


long ACE_FoxReactor::onFileEvents(FXObject* /* ob */, FXSelector se, void* handle){
  FXSelector sel=FXSELTYPE(se);
  ACE_Select_Reactor_Handle_Set dispatch_set;
  bool f=false;
  if(sel==SEL_IO_READ){
    dispatch_set.rd_mask_.set_bit(ACE_HANDLE(reinterpret_cast<FXival>(handle)));
    f=true;
  }
  else
  if(sel==SEL_IO_WRITE){
    dispatch_set.wr_mask_.set_bit(ACE_HANDLE(reinterpret_cast<FXival>(handle)));
    f=true;
  }
  else
  if(sel==SEL_IO_EXCEPT){
    dispatch_set.ex_mask_.set_bit(ACE_HANDLE(reinterpret_cast<FXival>(handle)));
    f=true;
  };
  if(f) dispatch (1, dispatch_set);

  return 1;
}

long ACE_FoxReactor::onTimerEvents(FXObject* /* ob */, FXSelector /* sel */, void* /* handle */)
{
  // Deal with any timer events
  ACE_Select_Reactor_Handle_Set handle_set;
  this->dispatch (0, handle_set );

  // Set next timeout signal
  this->reset_timeout ();

  return 0;
}

int
ACE_FoxReactor::register_handler_i (ACE_HANDLE handle,
                                    ACE_Event_Handler *handler,
                                    ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_FoxReactor::register_handler_i");

  int const result = ACE_Select_Reactor::register_handler_i (handle,
                                                             handler, mask);
  if (result == -1)
    return -1;

  unsigned long condition = 0;

  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK))
    ACE_SET_BITS (condition, FX::INPUT_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    ACE_SET_BITS (condition, FX::INPUT_WRITE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    ACE_SET_BITS (condition, FX::INPUT_EXCEPT);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    ACE_SET_BITS (condition, FX::INPUT_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK))
    {
      ACE_SET_BITS (condition, FX::INPUT_WRITE); // connected, you may write
      ACE_SET_BITS (condition, FX::INPUT_READ);  // connected, you have data/err
    }

  if (condition != 0)
    {
     fxapp->addInput(handle, condition, this, 0);
    }
  return 0;
}

int
ACE_FoxReactor::register_handler_i (const ACE_Handle_Set &handles,
                                    ACE_Event_Handler *handler,
                                    ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::register_handler_i (handles, handler, mask);
}

int
ACE_FoxReactor::remove_handler_i (ACE_HANDLE handle, ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_FoxReactor::remove_handler_i");

  // In the registration phase we registered first with
  // ACE_Select_Reactor and then with X.  Now we are now doing things
  // in reverse order.

  int condition = 0;

  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::READ_MASK))
    ACE_SET_BITS (condition, FX::INPUT_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::WRITE_MASK))
    ACE_SET_BITS (condition, FX::INPUT_WRITE);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::EXCEPT_MASK))
    ACE_SET_BITS (condition, FX::INPUT_EXCEPT);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::ACCEPT_MASK))
    ACE_SET_BITS (condition, FX::INPUT_READ);
  if (ACE_BIT_ENABLED (mask, ACE_Event_Handler::CONNECT_MASK))
    {
      ACE_SET_BITS (condition, FX::INPUT_WRITE); // connected, you may write
      ACE_SET_BITS (condition, FX::INPUT_READ);  // connected, you have data/err
    }

  // First clean up the corresponding X11Input.
  fxapp->removeInput ((int)handle,condition); // ACE_reinterpret_cast(int,handle));

  // Now let the reactor do its work.
  return ACE_Select_Reactor::remove_handler_i (handle, mask);
}

int
ACE_FoxReactor::remove_handler_i (const ACE_Handle_Set &handles,
                               ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::remove_handler_i (handles, mask);
}

// The following function ensures there's an Fox timeout for the first
// timeout in the Reactor's Timer_Queue.

void
ACE_FoxReactor::reset_timeout (void)
{
  ACE_Time_Value *max_wait_time =
    this->timer_queue_->calculate_timeout (0);

  if (max_wait_time != 0)
    {
      float t = max_wait_time->sec () +
        max_wait_time->usec () / 1000000.0F;
      fxapp->addTimeout (this, 0, t*1000);
    }
}

int
ACE_FoxReactor::reset_timer_interval
  (long timer_id,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_FoxReactor::reset_timer_interval");
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
ACE_FoxReactor::schedule_timer (ACE_Event_Handler *event_handler,
                                const void *arg,
                                const ACE_Time_Value &delay,
                                const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_FoxReactor::schedule_timer");
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
ACE_FoxReactor::cancel_timer (ACE_Event_Handler *handler,
                              int dont_call_handle_close)
{
  ACE_TRACE ("ACE_FoxReactor::cancel_timer");

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
ACE_FoxReactor::cancel_timer (long timer_id,
                              const void **arg,
                              int dont_call_handle_close)
{
  ACE_TRACE ("ACE_FoxReactor::cancel_timer");

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

