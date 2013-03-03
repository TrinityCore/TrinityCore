//$Id: QtReactor.cpp 82723 2008-09-16 09:35:44Z johnnyw $

#include "ace/QtReactor/QtReactor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE (ACE_QtReactor)

// Must be called with lock held

ACE_QtReactor::ACE_QtReactor (QApplication *qapp ,
    ACE_Sig_Handler *sh,
    ACE_Timer_Queue *tq,
    int disable_notify_pipe,
    ACE_Reactor_Notify *notify,
    bool mask_signals,
    int s_queue ):
    ACE_Select_Reactor( sh, tq, disable_notify_pipe,
        notify, mask_signals, s_queue),
    qapp_(qapp),
    qtime_ (0)
{
    reopen_notification_pipe();
}

// Must be called with lock held
ACE_QtReactor::ACE_QtReactor (size_t size,
    QApplication *qapp,
    bool restart,
    ACE_Sig_Handler *sh,
    ACE_Timer_Queue *tq,
    int disable_notify_pipe,
    ACE_Reactor_Notify *notify,
    bool mask_signals,
    int s_queue):
    ACE_Select_Reactor( size, restart, sh, tq,
        disable_notify_pipe, notify, mask_signals,
        s_queue ),
    qapp_(qapp),
    qtime_ (0)

{
    reopen_notification_pipe();
}

void ACE_QtReactor::reopen_notification_pipe( void)
{
  // When the ACE_Select_Reactor is constructed it creates the notify
  // pipe and registers it with the register_handler_i() method. The
  // QtReactor overloads this method BUT because the
  // register_handler_i occurs when constructing the base class
  // ACE_Select_Reactor, the ACE_Select_Reactor register_handler_i()
  // is called not the QtReactor register_handler_i().  This means
  // that the notify pipe is registered with the ACE_Select_Reactor
  // event handling code not the QtReactor and so notfications don't
  // work.  To get around this we simply close and re-opened the
  // notification handler in the constructor of the QtReactor.

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
    if ( initialized_ )
    {
        this->notify_handler_->close ();

        // Patch for MS Windows: close and open doesn't clear the read
        // fd_set, so reset it manually
        this->wait_set_.rd_mask_.reset ();

        this->notify_handler_->open (this, 0);
    }
#endif /* ACE_MT_SAFE */
}

ACE_QtReactor::~ACE_QtReactor (void)
{
    // iterate over QSocketNotifiers for read and release them
    MAP::ITERATOR iter = this->read_notifier_.begin ();
    MAP::ITERATOR iterEnd = this->read_notifier_.end ();
    while( iter != iterEnd )
    {
        MAP::ENTRY &entry = *iter;
        // QOBject destructor notifies qapplication (hopefully) on delete
        delete entry.int_id_;
        ++iter;
    }

    // iterate over QSocketNotifiers for write and release them
    this->write_notifier_.begin ();
    this->write_notifier_.end ();
    while( iter != iterEnd )
    {
        MAP::ENTRY &entry = *iter;
        // QOBject destructor notifies qapplication (hopefully) on delete
        delete entry.int_id_;
        ++iter;
    }

    // iterate over QSocketNotifiers for exceptions and release them
    this->exception_notifier_.begin ();
    this->exception_notifier_.end ();
    while( iter != iterEnd )
    {
        MAP::ENTRY &entry = *iter;
        // QOBject destructor notifies qapplication (hopefully) on delete
        delete entry.int_id_;
        ++iter;
    }

    // QOBject destructor notifies qapplication (hopefully) on delete
    delete qtime_;
}

void
ACE_QtReactor::qapplication (QApplication *qapp)
{
  // reparent QSocketNotifiers and QTimer
  qapp_ = qapp ;
}

void
ACE_QtReactor::timeout_event (void)
{
  // Deal with any timer events
  ACE_Select_Reactor_Handle_Set handle_set;
  this->dispatch (0, handle_set );

  // Set next timeout signal
  this->reset_timeout ();
}

void
ACE_QtReactor::read_event (int p_handle)
{
  ACE_TRACE ("ACE_QtReactor::read_event");

  ACE_HANDLE handle = ACE_HANDLE( p_handle );

#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // disable socket notifier to clear pending events
  QSocketNotifier *qsock_notifier = 0;
  if ( ( this->read_notifier_.find( handle,
             qsock_notifier) != -1) )
    qsock_notifier->setEnabled( false );
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */

  // The core of read event handling
  ACE_Select_Reactor_Handle_Set dispatch_set;

  dispatch_set.rd_mask_.set_bit ( handle );
  this->dispatch (1, dispatch_set);

#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // enable socket notifier according to current mask
  ACE_Reactor_Mask mask = 0;
  mask = mask_ops( handle, mask, ACE_Reactor::GET_MASK );
  if ( -1 != mask )
        set_enable_flag_by_mask ( 1, handle, mask);
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */
}

void
ACE_QtReactor::write_event (int p_handle)
{
  ACE_TRACE ("ACE_QtReactor::write_event");

  ACE_HANDLE handle = ACE_HANDLE( p_handle );

#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // disable socket notifier to clear pending events
  QSocketNotifier *qsock_notifier = 0;
  if ( ( this->write_notifier_.find( handle, qsock_notifier) != -1) )
    qsock_notifier->setEnabled( false );
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */

  // The core of write event handling
  ACE_Select_Reactor_Handle_Set dispatch_set;

  dispatch_set.wr_mask_.set_bit( handle );
  this->dispatch (1, dispatch_set);

#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // enable socket notifier according to current mask
  ACE_Reactor_Mask mask = 0;
  mask = mask_ops( handle, mask, ACE_Reactor::GET_MASK );
  if ( -1 != mask )
        set_enable_flag_by_mask ( 1, handle, mask);
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */
}

void
ACE_QtReactor::exception_event (int p_handle)
{
  ACE_TRACE ("ACE_QtReactor::exception_event");

  ACE_HANDLE handle = ACE_HANDLE( p_handle );


#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // disable socket notifier to clear pending events
  QSocketNotifier *qsock_notifier = 0;
  if ( ( this->exception_notifier_.find( handle, qsock_notifier) != -1) )
    qsock_notifier->setEnabled( false );
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */

  // The core of exception event handling
  ACE_Select_Reactor_Handle_Set dispatch_set;

  dispatch_set.ex_mask_.set_bit( handle );
  dispatch (1, dispatch_set);

#ifdef ACE_QTREACTOR_CLEAR_PENDING_EVENTS
  // enable socket notifier according to current mask
  ACE_Reactor_Mask mask = 0;
  mask = mask_ops( handle, mask, ACE_Reactor::GET_MASK );
  if ( -1 != mask )
        set_enable_flag_by_mask ( 1, handle, mask);
#endif /* ACE_QTREACTOR_CLEAR_PENDING_EVENTS  */
}

int
ACE_QtReactor::set_enable_flag_by_mask (int flag_value,
                                        ACE_HANDLE handle,
                                        ACE_Reactor_Mask mask)
{
  QSocketNotifier *qs_not;

  if (ACE_BIT_ENABLED(mask, ACE_Event_Handler::READ_MASK) ||
      ACE_BIT_ENABLED( mask, ACE_Event_Handler::ACCEPT_MASK))
    {
      // Find the current notifier
      qs_not = 0;
      if ((this->read_notifier_.find (handle, qs_not) == -1))
        return -1;

      qs_not->setEnabled (flag_value);
    }

  if (ACE_BIT_ENABLED( mask, ACE_Event_Handler::WRITE_MASK) ||
      ACE_BIT_ENABLED( mask, ACE_Event_Handler::ACCEPT_MASK) ||
      ACE_BIT_ENABLED( mask, ACE_Event_Handler::CONNECT_MASK))
    {
      qs_not = 0;
      if ((this->write_notifier_.find (handle, qs_not) == -1))
        return -1;

      qs_not->setEnabled (flag_value);
    }

  if (ACE_BIT_ENABLED( mask,
                       ACE_Event_Handler::EXCEPT_MASK))
    {
      qs_not = 0;
      if ((this->exception_notifier_.find (handle, qs_not) == -1))
        return -1;

      qs_not->setEnabled (flag_value);
    }

  return 0;
}

int
ACE_QtReactor::bit_ops (ACE_HANDLE handle,
                        ACE_Reactor_Mask mask,
                        ACE_Select_Reactor_Handle_Set &handle_set,
                        int ops)
{
  int result;
  ACE_Select_Reactor_Handle_Set preserved_handle_set = handle_set;

  // Call regular bit_ops
  if ((result = ACE_Select_Reactor::bit_ops (handle, mask, handle_set, ops)) == -1)
    return -1;

  // disable or enable the notifiers based on handle_set and mask
  int enableFlag = -1;
  if (&handle_set == &this->suspend_set_)
    enableFlag = 0;
  else if (&handle_set == &this->wait_set_)
    enableFlag = 1;
  else
    // We have no work to do here, so just return
    return result;

  switch (ops)
    {
    case ACE_Reactor::SET_MASK:
    case ACE_Reactor::ADD_MASK:
      // Enable or disable notifiers based on the specified masks
      if (this->set_enable_flag_by_mask (enableFlag, handle, mask) == -1)
        {
          // We can't just return -1 here because we'll have half-changed things.
          // So, we need to restore the old handle_set, then return -1.
          handle_set = preserved_handle_set;
          return -1;
        }
      break;

    case ACE_Reactor::CLR_MASK:
      if (this->set_enable_flag_by_mask (!enableFlag, handle, mask) == -1)
        {
          handle_set = preserved_handle_set;
          return -1;
        }
      break;

    default:
      // we take no action for any other operations
      break;
    }

  return result;
}

void
ACE_QtReactor::create_notifiers_for_handle (ACE_HANDLE handle)
{
    QSocketNotifier *qsock_notifier = 0;

    // if there is already a read socket notifier for this handle, do nothing
    // otherwise create read notifier
    if ( ( this->read_notifier_.find (handle,
               qsock_notifier) == -1) )
    {
        ACE_NEW (qsock_notifier,
            QSocketNotifier (int(handle), QSocketNotifier::Read, this));
        this->read_notifier_.bind (handle,
            qsock_notifier);
        QObject::connect (qsock_notifier,
            SIGNAL (activated (int)),
            this,
            SLOT (read_event (int))) ;
        // disable; it will be enabled by the regular register_handler_i if
        // necessary
        qsock_notifier->setEnabled (0);
    }

    qsock_notifier = 0;


    // if there is already a write socket notifier for this handle, do nothing
    // otherwise create read notifier
    if ((this->write_notifier_.find (handle,
             qsock_notifier) == -1))
    {
        ACE_NEW (qsock_notifier,
            QSocketNotifier (int(handle), QSocketNotifier::Write, this));

        this->write_notifier_.bind (handle,
            qsock_notifier);

        QObject::connect (qsock_notifier,
            SIGNAL (activated (int)),
            this,
            SLOT (write_event (int)));
        // disable; it will be enabled by the regular register_handler_i if
        // necessary
        qsock_notifier->setEnabled (0);
    }


    qsock_notifier = 0;

    // if there is already a write socket notifier for this handle, do nothing
    // otherwise create read notifier
    if ((this->exception_notifier_.find (handle,
             qsock_notifier) == -1))
    {

        ACE_NEW (qsock_notifier,
            QSocketNotifier (int(handle), QSocketNotifier::Exception, this));

        this->exception_notifier_.bind (handle,
            qsock_notifier);

        QObject::connect (qsock_notifier,
            SIGNAL (activated (int)),
            this,
            SLOT (exception_event (int))) ;
        // disable; it will be enabled by the regular register_handler_i if
        // necessary
        qsock_notifier->setEnabled (0);
    }
}

void
ACE_QtReactor::destroy_notifiers_for_handle (ACE_HANDLE handle)
{
  QSocketNotifier *qsock_notifier = 0;

  // Looks for the handle in the maps and removes them.

  if ((this->read_notifier_.find (handle,
                                  qsock_notifier) != -1))
    {
      this->read_notifier_.unbind (handle,
                                   qsock_notifier);
      delete qsock_notifier;
    }

  if ((this->write_notifier_.find (handle,
                                   qsock_notifier) != -1))
    {
      this->write_notifier_.unbind (handle,
                                    qsock_notifier);
      delete qsock_notifier;
    }


  if ((this->exception_notifier_.find (handle,
                                       qsock_notifier) != -1))
    {
      this->exception_notifier_.unbind (handle,
                                        qsock_notifier);
      delete qsock_notifier;
    }
}

int
ACE_QtReactor::register_handler_i (ACE_HANDLE handle ,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_QtReactor::register_handler_i");

  this->create_notifiers_for_handle (handle);

  int result;
  if ((result = ACE_Select_Reactor::register_handler_i(handle,
                                                       handler,
                                                       mask ))
      == -1)
    {
        // destroy notifiers only when there is no handler for handle
        if ( !ACE_Select_Reactor::find_handler( handle ) )
            this->destroy_notifiers_for_handle (handle);
      return -1;
    }

  return 0;
}

int
ACE_QtReactor::register_handler_i (const ACE_Handle_Set &handles,
                                   ACE_Event_Handler *handler,
                                   ACE_Reactor_Mask mask)
{
  return ACE_Select_Reactor::register_handler_i(handles,
                                                handler,
                                                mask);
}

int ACE_QtReactor::remove_handler_i (ACE_HANDLE handle ,
                                     ACE_Reactor_Mask mask   )
{
  ACE_TRACE ("ACE_QtReactor::remove_handler_i");

  int result = ACE_Select_Reactor::remove_handler_i (handle, mask);
  // destroy notifiers only when there is no handler for handle
  if ( !ACE_Select_Reactor::find_handler( handle ) )
      this->destroy_notifiers_for_handle (handle);
  return result;
}


int
ACE_QtReactor::remove_handler_i (const ACE_Handle_Set &handles,
                                 ACE_Reactor_Mask  mask)
{
  return ACE_Select_Reactor::remove_handler_i (handles,
                                               mask);
}

// The following functions ensure that there is an Qt timeout for the
// first timeout in the Reactor's Timer_Queue.

void
ACE_QtReactor::reset_timeout (void)
{
  if (this->qtime_ != 0)
    {
      delete this->qtime_;
      this->qtime_ = 0;
    }

  ACE_Time_Value *max_wait_time =
    this->timer_queue_->calculate_timeout (0) ;

  if (max_wait_time)
  {
    ACE_NEW (this->qtime_,
             QTimer);

    QObject::connect (qtime_,
                      SIGNAL (timeout ()),
                      this,
                      SLOT (timeout_event ()));

#if QT_VERSION >= 0x040000
    qtime_->setSingleShot (1);
    qtime_->start(max_wait_time->msec());
#else
    qtime_->start(max_wait_time->msec(), 1);
#endif
  }

}


long
ACE_QtReactor::schedule_timer (ACE_Event_Handler *handler,
                               const void *arg,
                               const ACE_Time_Value &delay_time,
                               const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_QtReactor::schedule_timer");
  ACE_MT (ACE_GUARD_RETURN (ACE_Select_Reactor_Token,
                            ace_mon,
                            this->token_,
                            -1));

  long result;
  if ((result = ACE_Select_Reactor::schedule_timer(handler,
                                                   arg,
                                                   delay_time,
                                                   interval)) == -1 )
    return -1;
  else
  {
    this->reset_timeout ();
    return result;
  }
}

int
ACE_QtReactor::cancel_timer (ACE_Event_Handler *handler,
                             int dont_call_handle_close)
{
  ACE_TRACE ("ACE_QtReactor::cancel_timer");

  if (ACE_Select_Reactor::cancel_timer (handler,
                                        dont_call_handle_close ) == -1 )
    return -1 ;
  else
  {
    this->reset_timeout( ) ;
    return 0 ;
  }
}

int ACE_QtReactor::cancel_timer (long  timer_id,
                                 const void **arg,
                                 int dont_call_handle_close )
{
  ACE_TRACE ("ACE_QtReactor::cancel_timer") ;

  if (ACE_Select_Reactor::cancel_timer (timer_id,
                                        arg,
                                        dont_call_handle_close ) == -1 )
    return -1 ;
  else
  {
    this->reset_timeout( ) ;
    return 0 ;
  }
}

// mbrudka: who needs QtWaitForMultipleEvents? It seems it's cargo load now!
int
ACE_QtReactor::QtWaitForMultipleEvents (int width,
                                        ACE_Select_Reactor_Handle_Set &wait_set,
                                        ACE_Time_Value * /*max_wait_time*/)
{
  // Keep a copy of the wait set in case the wait_set be changed
  // between the two select calls in this function. It could happen
  // while waiting for an event, another event is handled and dispatched
  // which changes the dispatch_set_/wait_set.
  ACE_Select_Reactor_Handle_Set orig_wait_set = wait_set;

  // Check to make sure our handle's are all usable.
  ACE_Select_Reactor_Handle_Set temp_set = wait_set;

  if (ACE_OS::select (width,
                      temp_set.rd_mask_,
                      temp_set.wr_mask_,
                      temp_set.ex_mask_,
                      (ACE_Time_Value *) &ACE_Time_Value::zero ) == -1)
    return -1; // Bad file arguments...

  // Qt processing.
#if QT_VERSION >= 0x040000
  this->qapp_->processEvents();
#else
  this->qapp_->processOneEvent ();
#endif

  // Reset the width, in case it changed during the upcalls.
  width = handler_rep_.max_handlep1 ();

  // Now actually read the result needed by the <Select_Reactor> using
  // <select>.
  return ACE_OS::select(width,
                        orig_wait_set.rd_mask_,
                        orig_wait_set.wr_mask_,
                        orig_wait_set.ex_mask_,
                        (ACE_Time_Value *) &ACE_Time_Value::zero);
}

// mbrudka: who needs wait_for_multiple_events? It seems it's cargo load now!
int
ACE_QtReactor::wait_for_multiple_events (
  ACE_Select_Reactor_Handle_Set &handle_set,
  ACE_Time_Value *max_wait_time)
{
  ACE_TRACE ("ACE_QtReactor::wait_for_multiple_events");

  int nfound = 0;
  do
  {
    max_wait_time = this->timer_queue_->calculate_timeout (max_wait_time);
    size_t width = this->handler_rep_.max_handlep1 ();
    handle_set.rd_mask_ = this->wait_set_.rd_mask_;
    handle_set.wr_mask_ = this->wait_set_.wr_mask_;
    handle_set.ex_mask_ = this->wait_set_.ex_mask_;

    nfound = QtWaitForMultipleEvents (width,
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

ACE_END_VERSIONED_NAMESPACE_DECL
