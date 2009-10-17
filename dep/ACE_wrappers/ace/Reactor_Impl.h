// -*- C++ -*-

//=============================================================================
/**
 *  @file    Reactor_Impl.h
 *
 *  $Id: Reactor_Impl.h 81082 2008-03-25 09:09:11Z johnnyw $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================


#ifndef ACE_REACTOR_IMPL_H
#define ACE_REACTOR_IMPL_H
#include /**/ "ace/pre.h"

// Timer Queue is a complicated template class. A simple forward
// declaration will not work
#include "ace/Timer_Queuefwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Event_Handler.h contains the definition of ACE_Reactor_Mask
#include "ace/Event_Handler.h"
#include "ace/Countdown_Time.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls
class ACE_Handle_Set;
class ACE_Reactor_Impl;
class ACE_Sig_Action;
class ACE_Sig_Handler;
class ACE_Sig_Set;

/**
 * @class ACE_Reactor_Notify
 *
 * @internal This class is for ACE internal use only.
 *
 * @brief Abstract class for unblocking an ACE_Reactor_Impl from its
 * event loop.
 */
class ACE_Export ACE_Reactor_Notify : public ACE_Event_Handler
{
public:
  // = Initialization and termination methods.
  virtual int open (ACE_Reactor_Impl *,
                    ACE_Timer_Queue *timer_queue = 0,
                    int disable_notify = 0) = 0;
  virtual int close (void) = 0;

  /**
   * Called by a thread when it wants to unblock the <Reactor_Impl>.
   * This wakeups the <Reactor_Impl> if currently blocked.  Pass over
   * both the <Event_Handler> *and* the @a mask to allow the caller to
   * dictate which <Event_Handler> method the <Reactor_Impl> will
   * invoke.  The ACE_Time_Value indicates how long to blocking
   * trying to notify the <Reactor_Impl>.  If @a timeout == 0, the
   * caller will block until action is possible, else will wait until
   * the relative time specified in *@a timeout elapses).
   */
  virtual int notify (ACE_Event_Handler *eh = 0,
                      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value *timeout = 0) = 0;

  /// Handles pending threads (if any) that are waiting to unblock the
  /// <Reactor_Impl>.
  virtual int dispatch_notifications (int &number_of_active_handles,
                                      ACE_Handle_Set &rd_mask) = 0;

  /// Returns the ACE_HANDLE of the notify pipe on which the reactor
  /// is listening for notifications so that other threads can unblock
  /// the <Reactor_Impl>
  virtual ACE_HANDLE notify_handle (void) = 0;

  /// Verify whether the buffer has dispatchable info  or not.
  virtual int is_dispatchable (ACE_Notification_Buffer &buffer)= 0;

  /// Handle one of the notify call on the <handle>. This could be
  /// because of a thread trying to unblock the <Reactor_Impl>
  virtual int dispatch_notify (ACE_Notification_Buffer &buffer) = 0;

  /// Read one of the notify call on the @a handle into the
  /// @a buffer. This could be because of a thread trying to unblock
  /// the <Reactor_Impl>
  virtual int read_notify_pipe (ACE_HANDLE handle,
                                ACE_Notification_Buffer &buffer) = 0;
  /**
   * Set the maximum number of times that the <handle_input> method
   * will iterate and dispatch the <ACE_Event_Handlers> that are
   * passed in via the notify queue before breaking out of the event
   * loop.  By default, this is set to -1, which means "iterate until
   * the queue is empty."  Setting this to a value like "1 or 2" will
   * increase "fairness" (and thus prevent starvation) at the expense
   * of slightly higher dispatching overhead.
   */
  virtual void max_notify_iterations (int) = 0;

  /**
   * Get the maximum number of times that the <handle_input> method
   * will iterate and dispatch the <ACE_Event_Handlers> that are
   * passed in via the notify queue before breaking out of its event
   * loop.
   */
  virtual int max_notify_iterations (void) = 0;

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. Returns the number of notifications
   * purged. Returns -1 on error.
   */
  virtual int purge_pending_notifications (ACE_Event_Handler * = 0,
                                           ACE_Reactor_Mask    = ACE_Event_Handler::ALL_EVENTS_MASK) = 0;

  /// Dump the state of an object.
  virtual void dump (void) const = 0;
};

/**
 * @class ACE_Reactor_Impl
 *
 * @brief An abstract class for implementing the Reactor Pattern.
 */
class ACE_Export ACE_Reactor_Impl
{
public:
  /// Close down and release all resources.
  virtual ~ACE_Reactor_Impl (void);

  /// Initialization.
  virtual int open (size_t size,
                    int restart = 0,
                    ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    int disable_notify_pipe = 0,
                    ACE_Reactor_Notify * = 0) = 0;

  /**
   * Returns 0, if the size of the current message has been put in
   * @a size Returns -1, if not.  ACE_HANDLE allows the reactor to
   * check if the caller is valid.
   */
  virtual int current_info (ACE_HANDLE, size_t & /* size */) = 0;

  /// Use a user specified signal handler instead.
  virtual int set_sig_handler (ACE_Sig_Handler *signal_handler) = 0;

  /// Set a user-specified timer queue.
  virtual int timer_queue (ACE_Timer_Queue *tq) = 0;

  /// Return the current ACE_Timer_Queue.
  virtual ACE_Timer_Queue *timer_queue (void) const = 0;

  /// Close down and release all resources.
  virtual int close (void) = 0;

  // = Event loop drivers.
  /**
   * Returns non-zero if there are I/O events "ready" for dispatching,
   * but does not actually dispatch the event handlers.  By default,
   * don't block while checking this, i.e., "poll".
   */
  virtual int work_pending (const ACE_Time_Value &max_wait_time =  ACE_Time_Value::zero)  = 0;

  /**
   * This event loop driver blocks for up to @a max_wait_time before
   * returning.  It will return earlier if events occur.  Note that
   * @a max_wait_time can be 0, in which case this method blocks
   * indefinitely until events occur.
   *
   * @a max_wait_time is decremented to reflect how much time this call
   * took.  For instance, if a time value of 3 seconds is passed to
   * handle_events and an event occurs after 2 seconds,
   * @a max_wait_time will equal 1 second.  This can be used if an
   * application wishes to handle events for some fixed amount of
   * time.
   *
   * Returns the total number of ACE_Event_Handlers that were
   * dispatched, 0 if the @a max_wait_time elapsed without dispatching
   * any handlers, or -1 if an error occurs.
   *
   * The only difference between <alertable_handle_events> and
   * <handle_events> is that in the alertable case, the eventloop will
   * return when the system queues an I/O completion routine or an
   * Asynchronous Procedure Call.
   */
  virtual int handle_events (ACE_Time_Value *max_wait_time = 0) = 0;
  virtual int alertable_handle_events (ACE_Time_Value *max_wait_time = 0) = 0;

  /**
   * This method is just like the one above, except the
   * @a max_wait_time value is a reference and can therefore never be
   * NULL.
   *
   * The only difference between <alertable_handle_events> and
   * <handle_events> is that in the alertable case, the eventloop will
   * return when the system queues an I/O completion routine or an
   * Asynchronous Procedure Call.
   */
  virtual int handle_events (ACE_Time_Value &max_wait_time) = 0;
  virtual int alertable_handle_events (ACE_Time_Value &max_wait_time) = 0;

  // = Event handling control.

  /**
   * Return the status of Reactor.  If this function returns 0, the reactor is
   * actively handling events.  If it returns non-zero, <handling_events> and
   * <handle_alertable_events> return -1 immediately.
   */
  virtual int deactivated (void) = 0;

  /**
   * Control whether the Reactor will handle any more incoming events or not.
   * If @a do_stop == 1, the Reactor will be disabled.  By default, a reactor
   * is in active state and can be deactivated/reactived as wish.
   */
  virtual void deactivate (int do_stop) = 0;

  // = Register and remove Handlers.

  /// Register @a event_handler with @a mask.  The I/O handle will always
  /// come from <get_handle> on the @a event_handler.
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask) = 0;

  /// Register @a event_handler with @a mask.  The I/O handle is provided
  /// through the <io_handle> parameter.
  virtual int register_handler (ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask) = 0;

#if defined (ACE_WIN32)

  // Originally this interface was available for all platforms, but
  // because ACE_HANDLE is an int on non-Win32 platforms, compilers
  // are not able to tell the difference between
  // register_handler(ACE_Event_Handler*,ACE_Reactor_Mask) and
  // register_handler(ACE_Event_Handler*,ACE_HANDLE). Therefore, we
  // have restricted this method to Win32 only.

  /**
   * Register an @a event_handler that will be notified when
   * <event_handle> is signaled.  Since no event mask is passed
   * through this interface, it is assumed that the <event_handle>
   * being passed in is an event handle and not an I/O handle.
   */
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_HANDLE event_handle = ACE_INVALID_HANDLE) = 0;

#endif /* ACE_WIN32 */

  /**
   * Register an @a event_handler that will be notified when
   * <event_handle> is signaled.  @a mask specifies the network events
   * that the @a event_handler is interested in.
   */
  virtual int register_handler (ACE_HANDLE event_handle,
                                ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask) = 0;

  /// Register @a event_handler with all the <handles> in the <Handle_Set>.
  virtual int register_handler (const ACE_Handle_Set &handles,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask) = 0;

  /**
   * Register <new_sh> to handle the signal @a signum using the
   * <new_disp>.  Returns the <old_sh> that was previously registered
   * (if any), along with the <old_disp> of the signal handler.
   */
  virtual int register_handler (int signum,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0,
                                ACE_Event_Handler **old_sh = 0,
                                ACE_Sig_Action *old_disp = 0) = 0;

  /// Registers <new_sh> to handle a set of signals <sigset> using the
  /// <new_disp>.
  virtual int register_handler (const ACE_Sig_Set &sigset,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0) = 0;

  /**
   * Removes @a event_handler.  Note that the I/O handle will be
   * obtained using <get_handle> method of @a event_handler .  If
   * @a mask == ACE_Event_Handler::DONT_CALL then the <handle_close>
   * method of the @a event_handler is not invoked.
   */
  virtual int remove_handler (ACE_Event_Handler *event_handler,
                              ACE_Reactor_Mask mask) = 0;

  /**
   * Removes <handle>.  If @a mask == ACE_Event_Handler::DONT_CALL
   * then the <handle_close> method of the associated <event_handler>
   * is not invoked.
   */
  virtual int remove_handler (ACE_HANDLE handle,
                              ACE_Reactor_Mask mask) = 0;

  /**
   * Removes all handles in <handle_set>.  If @a mask ==
   * ACE_Event_Handler::DONT_CALL then the <handle_close> method of
   * the associated <event_handler>s is not invoked.
   */
  virtual int remove_handler (const ACE_Handle_Set &handle_set,
                              ACE_Reactor_Mask mask) = 0;

  /**
   * Remove the ACE_Event_Handler currently associated with @a signum.
   * Install the new disposition (if given) and return the previous
   * disposition (if desired by the caller).  Returns 0 on success and
   * -1 if @a signum is invalid.
   */
  virtual int remove_handler (int signum,
                              ACE_Sig_Action *new_disp,
                              ACE_Sig_Action *old_disp = 0,
                              int sigkey = -1) = 0;

  /// Calls <remove_handler> for every signal in <sigset>.
  virtual int remove_handler (const ACE_Sig_Set &sigset) = 0;

  // = Suspend and resume Handlers.

  /// Suspend @a event_handler temporarily.  Use
  /// <ACE_Event_Handler::get_handle> to get the handle.
  virtual int suspend_handler (ACE_Event_Handler *event_handler) = 0;

  /// Suspend <handle> temporarily.
  virtual int suspend_handler (ACE_HANDLE handle) = 0;

  /// Suspend all <handles> in handle set temporarily.
  virtual int suspend_handler (const ACE_Handle_Set &handles) = 0;

  /// Suspend all <handles> temporarily.
  virtual int suspend_handlers (void) = 0;

  /// Resume @a event_handler. Use <ACE_Event_Handler::get_handle> to
  /// get the handle.
  virtual int resume_handler (ACE_Event_Handler *event_handler) = 0;

  /// Resume <handle>.
  virtual int resume_handler (ACE_HANDLE handle) = 0;

  /// Resume all <handles> in handle set.
  virtual int resume_handler (const ACE_Handle_Set &handles) = 0;

  /// Resume all <handles>.
  virtual int resume_handlers (void) = 0;

  /// Does the reactor allow the application to resume the handle on
  /// its own ie. can it pass on the control of handle resumption to
  /// the application
  virtual int resumable_handler (void) = 0;

  /// Return 1 if we any event associations were made by the reactor
  /// for the handles that it waits on, 0 otherwise.
  virtual int uses_event_associations (void) = 0;

  // If we need to reset handles returned from accept/connect.

  // = Timer management.

  /**
   * Schedule an ACE_Event_Handler that will expire after an amount
   * of time.  The return value of this method, a timer_id value,
   * uniquely identifies the event_handler in the ACE_Reactor's
   * internal list of timers.
   * This timer_id value can be used to cancel the timer
   * with the cancel_timer() call.
   *
   * @see cancel_timer()
   * @see reset_timer_interval()
   *
   * @param event_handler  event handler to schedule on reactor
   * @param arg   argument passed to the handle_timeout() method of  event_handler
   * @param delay  time interval after which the timer will expire
   * @param interval  time interval after which the timer will be automatically rescheduled
   * @return -1 on failure, a timer_id value on success
   */
  virtual long schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                               const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval = ACE_Time_Value::zero) = 0;

  /**
   * Resets the interval of the timer represented by @a timer_id to
   * @a interval, which is specified in relative time to the current
   * <gettimeofday>.  If @a interval is equal to
   * ACE_Time_Value::zero, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   */
  virtual int reset_timer_interval (long timer_id,
                                    const ACE_Time_Value &interval) = 0;

  /// Cancel all Event_Handlers that match the address of
  /// @a event_handler.  Returns number of handlers cancelled.
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1) = 0;

  /**
   * Cancel the single Event_Handler that matches the @a timer_id value
   * (which was returned from the schedule method).  If arg is
   * non-NULL then it will be set to point to the ``magic cookie''
   * argument passed in when the Event_Handler was registered.  This
   * makes it possible to free up the memory and avoid memory leaks.
   * Returns 1 if cancellation succeeded and 0 if the @a timer_id
   * wasn't found.
   */
  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1) = 0;

  // = High-level Event_Handler scheduling operations

  /// Add @a masks_to_be_added to the @a event_handler's entry.
  /// @a event_handler must already have been registered.
  virtual int schedule_wakeup (ACE_Event_Handler *event_handler,
                               ACE_Reactor_Mask masks_to_be_added) = 0;

  /// Add @a masks_to_be_added to the <handle>'s entry.  <event_handler>
  /// associated with <handle> must already have been registered.
  virtual int schedule_wakeup (ACE_HANDLE handle,
                               ACE_Reactor_Mask masks_to_be_added) = 0;

  /// Clear @a masks_to_be_cleared from the <event_handler>'s entry.
  virtual int cancel_wakeup (ACE_Event_Handler *event_handler,
                             ACE_Reactor_Mask masks_to_be_cleared) = 0;

  /// Clear @a masks_to_be_cleared from the <handle>'s entry.
  virtual int cancel_wakeup (ACE_HANDLE handle,
                             ACE_Reactor_Mask masks_to_be_cleared) = 0;

  // = Notification methods.

  /**
   * Notify @a event_handler of @a mask event.  The ACE_Time_Value
   * indicates how long to blocking trying to notify.  If @a timeout ==
   * 0, the caller will block until action is possible, else will wait
   * until the relative time specified in @a timeout elapses).
   */
  virtual int notify (ACE_Event_Handler *event_handler = 0,
                      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value * = 0) = 0;

  /**
   * Set the maximum number of times that ACE_Reactor_Impl will
   * iterate and dispatch the <ACE_Event_Handlers> that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."  Setting this
   * to a value like "1 or 2" will increase "fairness" (and thus
   * prevent starvation) at the expense of slightly higher dispatching
   * overhead.
   */
  virtual void max_notify_iterations (int) = 0;

  /**
   * Get the maximum number of times that the ACE_Reactor_Impl will
   * iterate and dispatch the <ACE_Event_Handlers> that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.
   */
  virtual int max_notify_iterations (void) = 0;

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. Returns the number of notifications
   * purged. Returns -1 on error.
   */
  virtual int purge_pending_notifications (ACE_Event_Handler * = 0,
                                           ACE_Reactor_Mask    = ACE_Event_Handler::ALL_EVENTS_MASK) = 0;

  /**
   * Return the Event_Handler associated with <handle>.  Return 0 if
   * <handle> is not registered.
   */
  virtual ACE_Event_Handler *find_handler (ACE_HANDLE handle) = 0;

  /**
   * Check to see if <handle> is associated with a valid Event_Handler
   * bound to @a mask.  Return the @a event_handler associated with this
   * handler if @a event_handler != 0.
   */
  virtual int handler (ACE_HANDLE handle,
                       ACE_Reactor_Mask mask,
                       ACE_Event_Handler **event_handler = 0) = 0;

  /**
   * Check to see if @a signum is associated with a valid Event_Handler
   * bound to a signal.  Return the @a event_handler associated with
   * this handler if @a event_handler != 0.
   */
  virtual int handler (int signum,
                       ACE_Event_Handler ** = 0) = 0;

  /// Returns true if Reactor has been successfully initialized, else
  /// false.
  virtual bool initialized (void) = 0;

  /// Returns the current size of the Reactor's internal descriptor
  /// table.
  virtual size_t size (void) const = 0;

  /// Returns a reference to the Reactor's internal lock.
  virtual ACE_Lock &lock (void) = 0;

  /// Wake up all threads in waiting in the event loop
  virtual void wakeup_all_threads (void) = 0;

  /// Transfers ownership of Reactor_Impl to the <new_owner>.
  virtual int owner (ACE_thread_t new_owner, ACE_thread_t *old_owner = 0) = 0;

  /// Return the ID of the "owner" thread.
  virtual int owner (ACE_thread_t *owner) = 0;

  /// Get the existing restart value.
  virtual int restart (void) = 0;

  /// Set a new value for restart and return the original value.
  virtual int restart (int r) = 0;

  /// Set position of the owner thread.
  virtual void requeue_position (int) = 0;

  /// Get position of the owner thread.
  virtual int requeue_position (void) = 0;

  // = Low-level wait_set mask manipulation methods.

  /// GET/SET/ADD/CLR the dispatch mask "bit" bound with the
  /// @a event_handler and @a mask.
  virtual int mask_ops (ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask mask,
                        int ops) = 0;

  /// GET/SET/ADD/CLR the dispatch MASK "bit" bound with the <handle>
  /// and @a mask.
  virtual int mask_ops (ACE_HANDLE handle,
                        ACE_Reactor_Mask mask,
                        int ops) = 0;

  // = Low-level ready_set mask manipulation methods.
  /// GET/SET/ADD/CLR the ready "bit" bound with the @a event_handler
  /// and @a mask.
  virtual int ready_ops (ACE_Event_Handler *event_handler,
                         ACE_Reactor_Mask mask,
                         int ops) = 0;

  /// GET/SET/ADD/CLR the ready "bit" bound with the <handle> and @a mask.
  virtual int ready_ops (ACE_HANDLE handle,
                         ACE_Reactor_Mask,
                         int ops) = 0;

  /// Dump the state of an object.
  virtual void dump (void) const = 0;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_REACTOR_IMPL_H */

