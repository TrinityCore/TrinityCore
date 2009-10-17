// -*- C++ -*-
//
// $Id: WFMO_Reactor.inl 81138 2008-03-28 09:18:15Z johnnyw $
#include "ace/Handle_Set.h"
#include "ace/Reactor.h"
#include "ace/Thread.h"
#include "ace/Sig_Handler.h"
#include "ace/OS_NS_errno.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/************************************************************/
ACE_INLINE int
ACE_Wakeup_All_Threads_Handler::handle_signal (int /* signum */,
                                               siginfo_t * /* siginfo */,
                                               ucontext_t *)
{
  // This will get called when <WFMO_Reactor->wakeup_all_threads_> event
  // is signaled. There is nothing to be done here.
  //  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) waking up to get updated handle set info\n")));
  return 0;
}
#if defined (ACE_WIN32)
/************************************************************/
ACE_INLINE
ACE_WFMO_Reactor_Handler_Repository::Common_Info::Common_Info (void)
  : io_entry_ (false),
    event_handler_ (0),
    io_handle_ (ACE_INVALID_HANDLE),
    network_events_ (0),
    delete_event_ (false),
    delete_entry_ (false),
    close_masks_ (ACE_Event_Handler::NULL_MASK)
{
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Common_Info::reset (void)
{
  this->event_handler_ = 0;
  this->io_entry_ = false;
  this->io_handle_ = ACE_INVALID_HANDLE;
  this->network_events_ = 0;
  this->delete_event_ = false;
  this->delete_entry_ = false;
  this->close_masks_ = ACE_Event_Handler::NULL_MASK;
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Common_Info::set (bool io_entry,
                                                       ACE_Event_Handler *event_handler,
                                                       ACE_HANDLE io_handle,
                                                       long network_events,
                                                       bool delete_event,
                                                       bool delete_entry,
                                                       ACE_Reactor_Mask close_masks)
{
  this->event_handler_ = event_handler;
  this->io_entry_ = io_entry;
  this->io_handle_ = io_handle;
  this->network_events_ = network_events;
  this->delete_event_ = delete_event;
  this->delete_entry_ = delete_entry;
  this->close_masks_ = close_masks;
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Common_Info::set (Common_Info &common_info)
{
  *this = common_info;
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Common_Info::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_WFMO_Reactor_Handler_Repository::Common_Info::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("I/O Entry = %d\n"),
              this->io_entry_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Event Handler = %d\n"),
              this->event_handler_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("I/O Handle = %d\n"),
              this->io_handle_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Network Events = %d\n"),
              this->network_events_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Delete Event = %d\n"),
              this->delete_event_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Delete Entry = %d\n"),
              this->delete_entry_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Close Masks = %d\n"),
              this->close_masks_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
/************************************************************/
ACE_INLINE
ACE_WFMO_Reactor_Handler_Repository::Current_Info::Current_Info (void)
  : suspend_entry_ (false)
{
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Current_Info::set (bool io_entry,
                                                        ACE_Event_Handler *event_handler,
                                                        ACE_HANDLE io_handle,
                                                        long network_events,
                                                        bool delete_event,
                                                        bool delete_entry,
                                                        ACE_Reactor_Mask close_masks,
                                                        bool suspend_entry)
{
  this->suspend_entry_ = suspend_entry;
  Common_Info::set (io_entry,
                    event_handler,
                    io_handle,
                    network_events,
                    delete_event,
                    delete_entry,
                    close_masks);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Current_Info::set (Common_Info &common_info,
                                                        bool suspend_entry)
{
  this->suspend_entry_ = suspend_entry;
  Common_Info::set (common_info);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Current_Info::reset (void)
{
  this->suspend_entry_ = false;
  Common_Info::reset ();
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Current_Info::dump (ACE_HANDLE event_handle) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_WFMO_Reactor_Handler_Repository::Current_Info::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  Common_Info::dump ();
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Event Handle = %d\n"),
              event_handle));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Suspend Entry = %d\n"),
              this->suspend_entry_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#else /* !ACE_HAS_DUMP */
  ACE_UNUSED_ARG (event_handle);
#endif /* ACE_HAS_DUMP */
}
/************************************************************/
ACE_INLINE
ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::To_Be_Added_Info (void)
  : event_handle_ (ACE_INVALID_HANDLE),
    suspend_entry_ (false)
{
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::set (ACE_HANDLE event_handle,
                                                            bool io_entry,
                                                            ACE_Event_Handler *event_handler,
                                                            ACE_HANDLE io_handle,
                                                            long network_events,
                                                            bool delete_event,
                                                            bool delete_entry,
                                                            ACE_Reactor_Mask close_masks,
                                                            bool suspend_entry)
{
  this->event_handle_ = event_handle;
  this->suspend_entry_ = suspend_entry;
  Common_Info::set (io_entry,
                    event_handler,
                    io_handle,
                    network_events,
                    delete_event,
                    delete_entry,
                    close_masks);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::set (ACE_HANDLE event_handle,
                                                            Common_Info &common_info,
                                                            bool suspend_entry)
{
  this->event_handle_ = event_handle;
  this->suspend_entry_ = suspend_entry;
  Common_Info::set (common_info);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::reset (void)
{
  this->event_handle_ = ACE_INVALID_HANDLE;
  this->suspend_entry_ = false;
  Common_Info::reset ();
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_WFMO_Reactor_Handler_Repository::To_Be_Added_Info::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  Common_Info::dump ();
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Event Handle = %d\n"),
              this->event_handle_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Suspend Entry = %d\n"),
              this->suspend_entry_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
/************************************************************/
ACE_INLINE
ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::Suspended_Info (void)
  : event_handle_ (ACE_INVALID_HANDLE),
    resume_entry_ (false)
{
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::reset (void)
{
  this->event_handle_ = ACE_INVALID_HANDLE;
  this->resume_entry_ = false;
  Common_Info::reset ();
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::set (ACE_HANDLE event_handle,
                                                          bool io_entry,
                                                          ACE_Event_Handler *event_handler,
                                                          ACE_HANDLE io_handle,
                                                          long network_events,
                                                          bool delete_event,
                                                          bool delete_entry,
                                                          ACE_Reactor_Mask close_masks,
                                                          bool resume_entry)
{
  this->event_handle_ = event_handle;
  this->resume_entry_ = resume_entry;
  Common_Info::set (io_entry,
                    event_handler,
                    io_handle,
                    network_events,
                    delete_event,
                    delete_entry,
                    close_masks);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::set (ACE_HANDLE event_handle,
                                                          Common_Info &common_info,
                                                          bool resume_entry)
{
  this->event_handle_ = event_handle;
  this->resume_entry_ = resume_entry;
  Common_Info::set (common_info);
}
ACE_INLINE void
ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_WFMO_Reactor_Handler_Repository::Suspended_Info::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  Common_Info::dump ();
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Event Handle = %d\n"),
              this->event_handle_));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("Resume Entry = %d\n"),
              this->resume_entry_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
/************************************************************/
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::close (void)
{
  // Let all the handlers know that the <WFMO_Reactor> is closing down
  this->unbind_all ();
  return 0;
}
ACE_INLINE ACE_HANDLE *
ACE_WFMO_Reactor_Handler_Repository::handles (void) const
{
  // This code is probably too subtle to be useful in the long run...
  // The basic idea is that all threads wait on all user handles plus
  // the <wakeup_all_threads_> handle. The owner thread additional
  // waits on the <notify_> handle. This is to ensure that only the
  // <owner_> thread get to expire timers and handle event on the
  // notify pipe.
  if (ACE_Thread::self () == this->wfmo_reactor_.owner_i ())
    return this->current_handles_;
  else
    return this->current_handles_ + 1;
}
ACE_INLINE ACE_WFMO_Reactor_Handler_Repository::Current_Info *
ACE_WFMO_Reactor_Handler_Repository::current_info (void) const
{
  if (ACE_Thread::self () == this->wfmo_reactor_.owner_i ())
    return this->current_info_;
  else
    return this->current_info_ + 1;
}
ACE_INLINE DWORD
ACE_WFMO_Reactor_Handler_Repository::max_handlep1 (void) const
{
  if (ACE_Thread::self () == this->wfmo_reactor_.owner_i ())
    return this->max_handlep1_;
  else
    return this->max_handlep1_ - 1;
}
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::scheduled_for_deletion (size_t slot) const
{
  if (ACE_Thread::self () == this->wfmo_reactor_.owner_i ())
    return this->current_info_[slot].delete_entry_ == true;
  else
    return this->current_info_[slot + 1].delete_entry_ == true;
}
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::invalid_handle (ACE_HANDLE handle) const
{
  ACE_TRACE ("ACE_WFMO_Reactor_Handler_Repository::invalid_handle");
  // It's too expensive to perform more exhaustive validity checks on
  // Win32 due to the way that they implement SOCKET HANDLEs.
  if (handle == ACE_INVALID_HANDLE)
    {
      errno = EINVAL;
      return 1;
    }
  else
    return 0;
}
ACE_INLINE bool
ACE_WFMO_Reactor_Handler_Repository::changes_required (void)
{
  // Check if handles have be scheduled for additions or removal
  return this->handles_to_be_added_ > 0
    || this->handles_to_be_deleted_ > 0
    || this->handles_to_be_suspended_ > 0
    || this->handles_to_be_resumed_ > 0;
}
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::make_changes (void)
{
  // This method must ONLY be called by the
  // <WFMO_Reactor->change_state_thread_>. We therefore assume that
  // there will be no contention for this method and hence no guards
  // are neccessary.
  // Deletions and suspensions in current_info_
  this->make_changes_in_current_infos ();
  // Deletions and resumptions in current_suspended_info_
  this->make_changes_in_suspension_infos ();
  // Deletions in to_be_added_info_, or transfers to current_info_ or
  // current_suspended_info_ from to_be_added_info_
  this->make_changes_in_to_be_added_infos ();
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::unbind (ACE_HANDLE handle,
                                             ACE_Reactor_Mask mask)
{
  if (this->invalid_handle (handle))
    return -1;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->wfmo_reactor_.lock_, -1);
  bool changes_required = false;
  int const result = this->unbind_i (handle,
                                     mask,
                                     changes_required);
  if (changes_required)
    // Wake up all threads in WaitForMultipleObjects so that they can
    // reconsult the handle set
    this->wfmo_reactor_.wakeup_all_threads ();
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::reset_timer_interval
  (long timer_id,
   const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_WFMO_Reactor::reset_timer_interval");
  if (0 != this->timer_queue_)
    {
      long result = this->timer_queue_->reset_interval
        (timer_id,
         interval);
      // Wakeup the owner thread so that it gets the latest timer values
      this->notify ();
      return result;
    }
  errno = ESHUTDOWN;
  return -1;
}
ACE_INLINE long
ACE_WFMO_Reactor::schedule_timer (ACE_Event_Handler *handler,
                                  const void *arg,
                                  const ACE_Time_Value &delay_time,
                                  const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_WFMO_Reactor::schedule_timer");
  if (0 != this->timer_queue_)
    {
      long result = this->timer_queue_->schedule
        (handler,
         arg,
         timer_queue_->gettimeofday () + delay_time,
         interval);
      // Wakeup the owner thread so that it gets the latest timer values
      this->notify ();
      return result;
    }
  errno = ESHUTDOWN;
  return -1;
}
ACE_INLINE int
ACE_WFMO_Reactor::cancel_timer (ACE_Event_Handler *handler,
                                int dont_call_handle_close)
{
  ACE_TRACE ("ACE_WFMO_Reactor::cancel_timer");
  if (0 != this->timer_queue_)
    return this->timer_queue_->cancel (handler, dont_call_handle_close);
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::cancel_timer (long timer_id,
                                const void **arg,
                                int dont_call_handle_close)
{
  ACE_TRACE ("ACE_WFMO_Reactor::cancel_timer");
  if (0 != this->timer_queue_)
    return this->timer_queue_->cancel (timer_id, arg, dont_call_handle_close);
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (ACE_Event_Handler *event_handler,
                                    ACE_HANDLE event_handle)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->handler_rep_.bind_i (0,
                                    event_handler,
                                    0,
                                    ACE_INVALID_HANDLE,
                                    event_handle,
                                    0);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (ACE_Event_Handler *event_handler,
                                    ACE_Reactor_Mask mask)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->register_handler_i (ACE_INVALID_HANDLE,
                                   ACE_INVALID_HANDLE,
                                   event_handler,
                                   mask);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (ACE_HANDLE io_handle,
                                    ACE_Event_Handler *event_handler,
                                    ACE_Reactor_Mask mask)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->register_handler_i (ACE_INVALID_HANDLE,
                                   io_handle,
                                   event_handler,
                                   mask);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (ACE_HANDLE event_handle,
                                    ACE_HANDLE io_handle,
                                    ACE_Event_Handler *event_handler,
                                    ACE_Reactor_Mask mask)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->register_handler_i (event_handle,
                                   io_handle,
                                   event_handler,
                                   mask);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (const ACE_Handle_Set &handles,
                                    ACE_Event_Handler *handler,
                                    ACE_Reactor_Mask mask)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;
  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->register_handler_i (h,
                                  ACE_INVALID_HANDLE,
                                  handler,
                                  mask) == -1)
      return -1;
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::schedule_wakeup (ACE_HANDLE io_handle,
                                   ACE_Reactor_Mask masks_to_be_added)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->mask_ops_i (io_handle,
                           masks_to_be_added,
                           ACE_Reactor::ADD_MASK);
}
ACE_INLINE int
ACE_WFMO_Reactor::schedule_wakeup (ACE_Event_Handler *event_handler,
                                   ACE_Reactor_Mask masks_to_be_added)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->mask_ops_i (event_handler->get_handle (),
                           masks_to_be_added,
                           ACE_Reactor::ADD_MASK);
}
ACE_INLINE int
ACE_WFMO_Reactor::cancel_wakeup (ACE_HANDLE io_handle,
                                 ACE_Reactor_Mask masks_to_be_removed)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->mask_ops_i (io_handle,
                           masks_to_be_removed,
                           ACE_Reactor::CLR_MASK);
}
ACE_INLINE int
ACE_WFMO_Reactor::cancel_wakeup (ACE_Event_Handler *event_handler,
                                 ACE_Reactor_Mask masks_to_be_removed)
{
  // This GUARD is necessary since we are updating shared state.
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->mask_ops_i (event_handler->get_handle (),
                           masks_to_be_removed,
                           ACE_Reactor::CLR_MASK);
}
ACE_INLINE int
ACE_WFMO_Reactor::remove_handler (ACE_Event_Handler *event_handler,
                                  ACE_Reactor_Mask mask)
{
  return this->handler_rep_.unbind (event_handler->get_handle (),
                                    mask);
}
ACE_INLINE int
ACE_WFMO_Reactor::remove_handler (ACE_HANDLE handle,
                                  ACE_Reactor_Mask mask)
{
  return this->handler_rep_.unbind (handle,
                                    mask);
}
ACE_INLINE int
ACE_WFMO_Reactor::remove_handler (const ACE_Handle_Set &handles,
                                  ACE_Reactor_Mask mask)
{
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;
  bool changes_required = false;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->handler_rep_.unbind_i (h,
                                     mask,
                                     changes_required) == -1)
      return -1;
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the handle set
  this->wakeup_all_threads ();
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::suspend_handler (ACE_HANDLE handle)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  bool changes_required = false;
  int const result =
    this->handler_rep_.suspend_handler_i (handle,
                                          changes_required);
  if (changes_required)
    // Wake up all threads in WaitForMultipleObjects so that they can
    // reconsult the handle set
    this->wakeup_all_threads ();
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::suspend_handler (ACE_Event_Handler *event_handler)
{
  return this->suspend_handler (event_handler->get_handle ());
}
ACE_INLINE int
ACE_WFMO_Reactor::suspend_handler (const ACE_Handle_Set &handles)
{
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;
  bool changes_required = false;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->handler_rep_.suspend_handler_i (h,
                                              changes_required) == -1)
      return -1;
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the handle set
  this->wakeup_all_threads ();
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::suspend_handlers (void)
{
  bool error = false;
  int result = 0;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  // First suspend all current handles
  bool changes_required = false;
  for (size_t i = 0;
       i < this->handler_rep_.max_handlep1_ && !error;
       i++)
    {
      result =
        this->handler_rep_.suspend_handler_i (this->handler_rep_.current_handles_[i],
                                              changes_required);
      if (result == -1)
        error = true;
    }
  // Then suspend all to_be_added_handles
  for (size_t i = 0;
       i < this->handler_rep_.handles_to_be_added_ && !error;
       i++)
    {
      if (this->handler_rep_.to_be_added_info_[i].io_entry_)
        {
          result =
            this->handler_rep_.suspend_handler_i (this->handler_rep_.to_be_added_info_[i].io_handle_,
                                                  changes_required);
        }
      else
        {
          result =
            this->handler_rep_.suspend_handler_i (this->handler_rep_.to_be_added_info_[i].event_handle_,
                                                  changes_required);
        }
      if (result == -1)
        error = true;
    }
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the handle set
  this->wakeup_all_threads ();
  return error ? -1 : 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::resume_handler (ACE_HANDLE handle)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  bool changes_required = false;
  int result =
    this->handler_rep_.resume_handler_i (handle, changes_required);
  if (changes_required)
    // Wake up all threads in WaitForMultipleObjects so that they can
    // reconsult the handle set
    this->wakeup_all_threads ();
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::resume_handler (ACE_Event_Handler *event_handler)
{
  return this->resume_handler (event_handler->get_handle ());
}
ACE_INLINE int
ACE_WFMO_Reactor::resume_handler (const ACE_Handle_Set &handles)
{
  ACE_Handle_Set_Iterator handle_iter (handles);
  ACE_HANDLE h;
  bool changes_required = false;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  while ((h = handle_iter ()) != ACE_INVALID_HANDLE)
    if (this->handler_rep_.resume_handler_i (h,
                                             changes_required) == -1)
      return -1;
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the handle set
  this->wakeup_all_threads ();
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::resume_handlers (void)
{
  bool error = false;
  int result = 0;
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  bool changes_required = false;
  for (size_t i = 0;
       i < this->handler_rep_.suspended_handles_ && !error;
       i++)
    {
      result =
        this->handler_rep_.resume_handler_i (this->handler_rep_.current_suspended_info_[i].event_handle_,
                                             changes_required);
      if (result == -1)
        error = true;
    }
  // Then resume all to_be_added_handles
  for (size_t i = 0;
        i < this->handler_rep_.handles_to_be_added_ && !error;
        i++)
    {
      if (this->handler_rep_.to_be_added_info_[i].io_entry_)
        {
          result =
            this->handler_rep_.resume_handler_i (this->handler_rep_.to_be_added_info_[i].io_handle_,
                                                  changes_required);
        }
      else
        {
          result =
           this->handler_rep_.resume_handler_i (this->handler_rep_.to_be_added_info_[i].event_handle_,
                                                changes_required);
        }
      if (result == -1)
        error = true;
    }
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the handle set
  this->wakeup_all_threads ();
  return error ? -1 : 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::uses_event_associations (void)
{
  // Since the WFMO_Reactor does use event associations, this function
  // always return 1.
  return 1;
}
ACE_INLINE int
ACE_WFMO_Reactor::handle_events (ACE_Time_Value &how_long)
{
  return this->event_handling (&how_long, FALSE);
}
ACE_INLINE int
ACE_WFMO_Reactor::alertable_handle_events (ACE_Time_Value &how_long)
{
  return this->event_handling (&how_long, TRUE);
}
ACE_INLINE int
ACE_WFMO_Reactor::handle_events (ACE_Time_Value *how_long)
{
  return this->event_handling (how_long, FALSE);
}
ACE_INLINE int
ACE_WFMO_Reactor::alertable_handle_events (ACE_Time_Value *how_long)
{
  return this->event_handling (how_long, TRUE);
}
ACE_INLINE int
ACE_WFMO_Reactor::deactivated (void)
{
  return this->deactivated_;
}
ACE_INLINE void
ACE_WFMO_Reactor::deactivate (int do_stop)
{
  this->deactivated_ = do_stop;
  this->wakeup_all_threads ();
}
ACE_INLINE int
ACE_WFMO_Reactor::owner (ACE_thread_t *t)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  *t = this->owner_i ();
  return 0;
}
ACE_INLINE ACE_thread_t
ACE_WFMO_Reactor::owner_i (void)
{
  return this->owner_;
}
ACE_INLINE int
ACE_WFMO_Reactor::owner (ACE_thread_t new_owner, ACE_thread_t *old_owner)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, monitor, this->lock_, -1);
  this->new_owner_ = new_owner;
  if (old_owner != 0)
    *old_owner = this->owner_i ();
  // Wake up all threads in WaitForMultipleObjects so that they can
  // reconsult the new owner responsibilities
  this->wakeup_all_threads ();
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::new_owner (void)
{
  return this->new_owner_ != ACE_thread_t (0);
}
ACE_INLINE int
ACE_WFMO_Reactor::change_owner (void)
{
  this->owner_ = this->new_owner_;
  this->new_owner_ = ACE_thread_t (0);
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::safe_dispatch (DWORD wait_status)
{
  int result = -1;
  ACE_SEH_TRY
    {
      result = this->dispatch (wait_status);
    }
  ACE_SEH_FINALLY
    {
      this->update_state ();
    }
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::dispatch_window_messages (void)
{
  return 0;
}
ACE_INLINE void
ACE_WFMO_Reactor::wakeup_all_threads (void)
{
  this->wakeup_all_threads_.signal ();
}
ACE_INLINE int
ACE_WFMO_Reactor::notify (ACE_Event_Handler *event_handler,
                          ACE_Reactor_Mask mask,
                          ACE_Time_Value *timeout)
{
  return this->notify_handler_->notify (event_handler, mask, timeout);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (int signum,
                                    ACE_Event_Handler *new_sh,
                                    ACE_Sig_Action *new_disp,
                                    ACE_Event_Handler **old_sh,
                                    ACE_Sig_Action *old_disp)
{
  return this->signal_handler_->register_handler (signum,
                                                  new_sh, new_disp,
                                                  old_sh, old_disp);
}
ACE_INLINE int
ACE_WFMO_Reactor::register_handler (const ACE_Sig_Set &sigset,
                                    ACE_Event_Handler *new_sh,
                                    ACE_Sig_Action *new_disp)
{
  int result = 0;
#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; s++)
    if (sigset.is_member (s)
        && this->signal_handler_->register_handler (s,
                                                    new_sh,
                                                    new_disp) == -1)
      result = -1;
#else
  ACE_UNUSED_ARG (sigset);
  ACE_UNUSED_ARG (new_sh);
  ACE_UNUSED_ARG (new_disp);
#endif /* ACE_NSIG */
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::remove_handler (int signum,
                                  ACE_Sig_Action *new_disp,
                                  ACE_Sig_Action *old_disp,
                                  int sigkey)
{
  return this->signal_handler_->remove_handler (signum,
                                                new_disp,
                                                old_disp,
                                                sigkey);
}
ACE_INLINE int
ACE_WFMO_Reactor::remove_handler (const ACE_Sig_Set &sigset)
{
  int result = 0;
#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; s++)
    if (sigset.is_member (s)
        && this->signal_handler_->remove_handler (s) == -1)
      result = -1;
#else
  ACE_UNUSED_ARG (sigset);
#endif /* ACE_NSIG */
  return result;
}
ACE_INLINE int
ACE_WFMO_Reactor::handler (int signum, ACE_Event_Handler **eh)
{
  ACE_Event_Handler *handler =
    this->signal_handler_->handler (signum);
  if (handler == 0)
    return -1;
  else if (eh != 0)
    *eh = handler;
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::mask_ops (ACE_Event_Handler *event_handler,
                            ACE_Reactor_Mask mask,
                            int operation)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, monitor, this->lock_, -1);
  return this->mask_ops_i (event_handler->get_handle (),
                           mask,
                           operation);
}
ACE_INLINE int
ACE_WFMO_Reactor::mask_ops (ACE_HANDLE io_handle,
                            ACE_Reactor_Mask mask,
                            int operation)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, monitor, this->lock_, -1);
  return this->mask_ops_i (io_handle,
                           mask,
                           operation);
}
ACE_INLINE void
ACE_WFMO_Reactor::requeue_position (int)
{
  // Not implemented
}
ACE_INLINE int
ACE_WFMO_Reactor::requeue_position (void)
{
  // Don't have an implementation for this yet...
  ACE_NOTSUP_RETURN (-1);
}
ACE_INLINE int
ACE_WFMO_Reactor::restart (void)
{
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::restart (int)
{
  return 0;
}
ACE_INLINE int
ACE_WFMO_Reactor::ready_ops (ACE_Event_Handler *event_handler,
                             ACE_Reactor_Mask mask,
                             int ops)
{
  // Don't have an implementation for this yet...
  ACE_UNUSED_ARG (event_handler);
  ACE_UNUSED_ARG (mask);
  ACE_UNUSED_ARG (ops);
  ACE_NOTSUP_RETURN (-1);
}
ACE_INLINE int
ACE_WFMO_Reactor::ready_ops (ACE_HANDLE handle,
                             ACE_Reactor_Mask,
                             int ops)
{
  // Don't have an implementation for this yet...
  ACE_UNUSED_ARG (handle);
  ACE_UNUSED_ARG (ops);
  ACE_NOTSUP_RETURN (-1);
}
ACE_INLINE ACE_Event_Handler *
ACE_WFMO_Reactor::find_handler (ACE_HANDLE handle)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, 0);
  return this->handler_rep_.find_handler (handle);
}
ACE_INLINE int
ACE_WFMO_Reactor::handler (ACE_HANDLE handle,
                           ACE_Reactor_Mask mask,
                           ACE_Event_Handler **event_handler)
{
  ACE_GUARD_RETURN (ACE_Process_Mutex, ace_mon, this->lock_, -1);
  return this->handler_rep_.handler (handle,
                                     mask,
                                     event_handler);
}
ACE_INLINE bool
ACE_WFMO_Reactor::initialized (void)
{
  return this->open_for_business_;
}
ACE_INLINE ACE_Lock &
ACE_WFMO_Reactor::lock (void)
{
  return this->lock_adapter_;
}
ACE_INLINE size_t
ACE_WFMO_Reactor::size (void) const
{
  // Size of repository minus the 2 used for internal purposes
  return this->handler_rep_.max_size_ - 2;
}
#else
ACE_INLINE bool
ACE_WFMO_Reactor_Handler_Repository::changes_required (void)
{
  return false;
}
ACE_INLINE int
ACE_WFMO_Reactor_Handler_Repository::make_changes (void)
{
  return 0;
}
ACE_INLINE
ACE_WFMO_Reactor_Handler_Repository::~ACE_WFMO_Reactor_Handler_Repository (void)
{
}
#endif /* ACE_WIN32 */
ACE_END_VERSIONED_NAMESPACE_DECL
