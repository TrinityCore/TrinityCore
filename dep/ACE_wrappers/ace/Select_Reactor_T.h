// -*- C++ -*-
//=============================================================================
/**
 *  @file    Select_Reactor_T.h
 *
 *  $Id: Select_Reactor_T.h 82393 2008-07-23 10:52:34Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_SELECT_REACTOR_T_H
#define ACE_SELECT_REACTOR_T_H
#include /**/ "ace/pre.h"
#include "ace/Select_Reactor_Base.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Lock_Adapter_T.h"
#include "ace/Token.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/*
 * Hook for specializing the reactor with the concrete
 * type, for example, select, or thread pool.
 */
//@@ REACTOR_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
typedef ACE_Token ACE_SELECT_TOKEN;
#else
typedef ACE_Noop_Token ACE_SELECT_TOKEN;
#endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */
/**
 * @class ACE_Select_Reactor_T
 *
 * @brief An object oriented event demultiplexor and event handler
 * dispatcher.
 *
 * The ACE_Select_Reactor is an object-oriented event
 * demultiplexor and event handler dispatcher.  The sources of
 * events that the ACE_Select_Reactor waits for and dispatches
 * includes I/O events, signals, and timer events.  All public
 * methods acquire the main ACE_Reactor_Token lock and
 * call down to private or protected methods, which assume that
 * the lock is held and so therefore don't (re)acquire the lock.
 */
template <class ACE_SELECT_REACTOR_TOKEN>
class ACE_Select_Reactor_T : public ACE_Select_Reactor_Impl
{
public:
  // = Initialization and termination methods.
  /// If @a disable_notify_pipe is non-0 then the reactor will
  /// not create a notification pipe, which will save two I/O handles
  /// but will elide the <notify()> feature.  If @a mask_signals is
  /// true the reactor is "signal-safe" when dispatching handlers to
  /// signal events, whereas if @a mask_signals is false the reactor will
  /// be more efficient, but not signal-safe (which may be perfectly
  /// fine if your application doesn't use the reactor to handle signals).
  ACE_Select_Reactor_T (ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0,
                        int disable_notify_pipe = ACE_DISABLE_NOTIFY_PIPE_DEFAULT,
                        ACE_Reactor_Notify *notify = 0,
                        bool mask_signals = true,
                        int s_queue = ACE_SELECT_TOKEN::FIFO);
  /// Initialize @c ACE_Select_Reactor with size @arg size.
  /// If @arg disable_notify_pipe is non-0 then the reactor will
  /// not create a notification pipe, which will save two I/O handles
  /// but will elide the notification feature.  If @arg mask_signals is
  /// true the reactor is "signal-safe" when dispatching handlers to
  /// signal events, whereas if @arg mask_signals is false the reactor will
  /// be more efficient, but not signal-safe (which may be perfectly
  /// fine if your application doesn't use the reactor to handle signals).
  /**
   * @note On Unix platforms, the size parameter should be as large as
   *       the maximum number of file descriptors allowed for a given
   *       process.  This is necessary since a file descriptor is used
   *       to directly index the array of event handlers maintained by
   *       the Reactor's handler repository.  Direct indexing is used
   *       for efficiency reasons.
   */
  ACE_Select_Reactor_T (size_t size,
                        int restart = 0,
                        ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0,
                        int disable_notify_pipe = ACE_DISABLE_NOTIFY_PIPE_DEFAULT,
                        ACE_Reactor_Notify *notify = 0,
                        bool mask_signals = true,
                        int s_queue = ACE_SELECT_TOKEN::FIFO);
  /**
   * Initialize the @c ACE_Select_Reactor to manage
   * @arg max_number_of_handles.  If @arg restart is non-0 then the
   * @c ACE_Reactor's @c handle_events method will be restarted
   * automatically when @c EINTR occurs.  If @arg signal_handler or
   * @arg timer_queue are non-0 they are used as the signal handler and
   * timer queue, respectively.  If @arg disable_notify_pipe is non-0 the
   * notification pipe is not created, thereby saving two I/O handles.
   *
   * @note On Unix platforms, the maximum_number_of_handles parameter
   *       should be as large as the maximum number of file
   *       descriptors allowed for a given process.  This is necessary
   *       since a file descriptor is used to directly index the array
   *       of event handlers maintained by the Reactor's handler
   *       repository.  Direct indexing is used for efficiency
   *       reasons.
   */
  virtual int open (size_t max_number_of_handles = DEFAULT_SIZE,
                    int restart = 0,
                    ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    int disable_notify_pipe = ACE_DISABLE_NOTIFY_PIPE_DEFAULT,
                    ACE_Reactor_Notify * = 0);
  /// Returns -1 (not used in this implementation);
  virtual int current_info (ACE_HANDLE, size_t &size);
  /// Use a user specified signal handler instead.
  virtual int set_sig_handler (ACE_Sig_Handler *signal_handler);
  /// Set a user-specified timer queue.
  virtual int timer_queue (ACE_Timer_Queue *tq);
  /// Return the current ACE_Timer_Queue.
  virtual ACE_Timer_Queue *timer_queue (void) const;
  /// Close down the select_reactor and release all of its resources.
  virtual int close (void);
  /// Close down the select_reactor and release all of its resources.
  virtual ~ACE_Select_Reactor_T (void);
  // = Event loop drivers.
  /**
   * Returns non-zero if there are I/O events "ready" for dispatching,
   * but does not actually dispatch the event handlers.  By default,
   * don't block while checking this, i.e., "poll".
   */
  virtual int work_pending (const ACE_Time_Value &max_wait_time = ACE_Time_Value::zero);
  /**
   * This event loop driver that blocks for @a max_wait_time before
   * returning.  It will return earlier if timer events, I/O events,
   * or signal events occur.  Note that @a max_wait_time can be 0, in
   * which case this method blocks indefinitely until events occur.
   *
   * @a max_wait_time is decremented to reflect how much time this call
   * took.  For instance, if a time value of 3 seconds is passed to
   * handle_events and an event occurs after 2 seconds,
   * @a max_wait_time will equal 1 second.  This can be used if an
   * application wishes to handle events for some fixed amount of
   * time.
   *
   * Returns the total number of I/O and Timer ACE_Event_Handler's
   * that were dispatched, 0 if the @a max_wait_time elapsed without
   * dispatching any handlers, or -1 if something goes wrong.
   *
   * Current <alertable_handle_events> is identical to
   * <handle_events>.
   */
  virtual int handle_events (ACE_Time_Value *max_wait_time = 0);
  virtual int alertable_handle_events (ACE_Time_Value *max_wait_time = 0);
  /**
   * This method is just like the one above, except the
   * @a max_wait_time value is a reference and can therefore never be
   * NULL.
   *
   * Current <alertable_handle_events> is identical to
   * <handle_events>.
   */
  virtual int handle_events (ACE_Time_Value &max_wait_time);
  virtual int alertable_handle_events (ACE_Time_Value &max_wait_time);
  // = Event handling control.
  /**
   * Return the status of Reactor.  If this function returns 0, the reactor is
   * actively handling events.  If it returns non-zero, <handling_events> and
   * <handle_alertable_events> return -1 immediately.
   */
  virtual int deactivated (void);
  /**
   * Control whether the Reactor will handle any more incoming events or not.
   * If @a do_stop == 1, the Reactor will be disabled.  By default, a reactor
   * is in active state and can be deactivated/reactived as wish.
   */
  virtual void deactivate (int do_stop);
  // = Register and remove ACE_Event_Handlers.
  /**
   * Register a @a eh with a particular @a mask.  Note that the
   * <Select_Reactor> will call ACE_Event_Handler::get_handle() to
   * extract the underlying I/O handle.
   */
  virtual int register_handler (ACE_Event_Handler *eh,
                                ACE_Reactor_Mask mask);
  /**
   * Register a @a eh with a particular @a mask.  Note that since the
   * @a handle is given the Select_Reactor will *not* call
   * ACE_Event_Handler::get_handle() to extract the underlying I/O
   * handle.
   */
  virtual int register_handler (ACE_HANDLE handle,
                                ACE_Event_Handler *eh,
                                ACE_Reactor_Mask mask);
#if defined (ACE_WIN32)
  // Originally this interface was available for all platforms, but
  // because ACE_HANDLE is an int on non-Win32 platforms, compilers
  // are not able to tell the difference between
  // register_handler(ACE_Event_Handler*,ACE_Reactor_Mask) and
  // register_handler(ACE_Event_Handler*,ACE_HANDLE). Therefore, we
  // have restricted this method to Win32 only.
  /// Not implemented.
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_HANDLE event_handle = ACE_INVALID_HANDLE);
#endif /* ACE_WIN32 */
  /// Not implemented.
  virtual int register_handler (ACE_HANDLE event_handle,
                                ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);
  /// Register @a eh with all the @a handles in the <Handle_Set>.
  virtual int register_handler (const ACE_Handle_Set &handles,
                                ACE_Event_Handler *eh,
                                ACE_Reactor_Mask mask);
  /**
   * Register @a new_sh to handle the signal @a signum using the
   * @a new_disp. Returns the @a old_sh that was previously registered
   * (if any), along with the @a old_disp of the signal handler.
   */
  virtual int register_handler (int signum,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0,
                                ACE_Event_Handler **old_sh = 0,
                                ACE_Sig_Action *old_disp = 0);
  /// Registers @a new_sh to handle a set of signals @a sigset using the
  /// @a new_disp.
  virtual int register_handler (const ACE_Sig_Set &sigset,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0);
  /**
   * Removes the @a mask binding of <eh> from the Select_Reactor.  If
   * there are no more bindings for this <eh> then it is removed from
   * the Select_Reactor.  Note that the Select_Reactor will call
   * <ACE_Event_Handler::get_handle> to extract the underlying I/O
   * handle.
   */
  virtual int remove_handler (ACE_Event_Handler *eh,
                              ACE_Reactor_Mask mask);
  /**
   * Removes the @a mask bind of <Event_Handler> whose handle is
   * <handle> from the Select_Reactor.  If there are no more bindings
   * for this <eh> then it is removed from the Select_Reactor.
   */
  virtual int remove_handler (ACE_HANDLE handle,
                              ACE_Reactor_Mask);
  /**
   * Removes all the @a mask bindings for handles in the <handle_set>
   * bind of <Event_Handler>.  If there are no more bindings for any
   * of these handlers then they are removed from the Select_Reactor.
   */
  virtual int remove_handler (const ACE_Handle_Set &handle_set,
                              ACE_Reactor_Mask);
  /**
   * Remove the ACE_Event_Handler currently associated with @a signum.
   * <sigkey> is ignored in this implementation since there is only
   * one instance of a signal handler.  Install the new disposition
   * (if given) and return the previous disposition (if desired by the
   * caller).  Returns 0 on success and -1 if @a signum is invalid.
   */
  virtual int remove_handler (int signum,
                              ACE_Sig_Action *new_disp,
                              ACE_Sig_Action *old_disp = 0,
                              int sigkey = -1);
  /// Calls <remove_handler> for every signal in <sigset>.
  virtual int remove_handler (const ACE_Sig_Set &sigset);
  // = Suspend and resume Handlers.
  /// Temporarily suspend the <Event_Handler> associated with <eh>.
  virtual int suspend_handler (ACE_Event_Handler *eh);
  /// Temporarily suspend the <Event_Handler> associated with <handle>.
  virtual int suspend_handler (ACE_HANDLE handle);
  /// Suspend all <handles> in handle set temporarily.
  virtual int suspend_handler (const ACE_Handle_Set &handles);
  /// Suspend all the <Event_Handlers> in the Select_Reactor.
  virtual int suspend_handlers (void);
  /// Resume a temporarily suspend <Event_Handler> associated with
  /// <eh>.
  virtual int resume_handler (ACE_Event_Handler *eh);
  /// Resume a temporarily suspended <Event_Handler> associated with
  /// <handle>.
  virtual int resume_handler (ACE_HANDLE handle);
  /// Resume all <handles> in handle set.
  virtual int resume_handler (const ACE_Handle_Set &handles);
  /// Resume all the <Event_Handlers> in the Select_Reactor.
  virtual int resume_handlers (void);
  /**
   * Return 1 if we any event associations were made by the reactor
   * for the handles that it waits on, 0 otherwise. Since the
   * Select_Reactor does not do any event associations, this function
   * always return 0.
   */
  virtual int uses_event_associations (void);
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
   * @param event_handler  Event handler to schedule on reactor
   * @param arg Argument passed to the handle_timeout() method of event_handler
   * @param delay Time interval after which the timer will expire
   * @param interval Time interval after which the timer will be automatically
   * rescheduled
   * @return -1 on failure, a timer_id value on success
   */
  virtual long schedule_timer (ACE_Event_Handler * event_handler,
                               const void *arg,
                               const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval = ACE_Time_Value::zero);
  /**
   * Resets the interval of the timer represented by @a timer_id to
   * @a interval, which is specified in relative time to the current
   * <gettimeofday>.  If @a interval is equal to
   * ACE_Time_Value::zero, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   */
  virtual int reset_timer_interval (long timer_id,
                                    const ACE_Time_Value &interval);
  /**
   * Cancel all <event_handlers> that match the address of
   * <event_handler>.  If @a dont_call_handle_close is 0 then the
   * <handle_close> method of <event_handler> will be invoked.
   * Returns number of handler's cancelled.
   */
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1);
  /**
   * Cancel the single ACE_Event_Handler that matches the @a timer_id
   * value (which was returned from the <schedule> method).  If arg is
   * non-NULL then it will be set to point to the ``magic cookie''
   * argument passed in when the <Event_Handler> was registered.  This
   * makes it possible to free up the memory and avoid memory leaks.
   * If @a dont_call_handle_close is 0 then the <handle_close> method
   * of <event_handler> will be invoked.  Returns 1 if cancellation
   * succeeded and 0 if the @a timer_id wasn't found.
   */
  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1);
  // = High-level Event_Handler scheduling operations
  /// ADD the dispatch MASK "bit" bound with the <eh> and the @a mask.
  virtual int schedule_wakeup (ACE_Event_Handler *eh,
                               ACE_Reactor_Mask mask);
  /// ADD the dispatch MASK "bit" bound with the <handle> and the @a mask.
  virtual int schedule_wakeup (ACE_HANDLE handle,
                               ACE_Reactor_Mask mask);
  /// CLR the dispatch MASK "bit" bound with the <eh> and the @a mask.
  virtual int cancel_wakeup (ACE_Event_Handler *eh,
                             ACE_Reactor_Mask mask);
  /// CLR the dispatch MASK "bit" bound with the <handle> and the @a mask.
  virtual int cancel_wakeup (ACE_HANDLE handle,
                             ACE_Reactor_Mask mask);
  // = Notification methods.
  /**
   * Called by a thread when it wants to unblock the Select_Reactor.
   * This wakeups the <ACE_Select_Reactor> if currently blocked in
   * <select>/<poll>.  Pass over both the <Event_Handler> *and* the
   * @a mask to allow the caller to dictate which <Event_Handler>
   * method the <Select_Reactor> will invoke.  The ACE_Time_Value
   * indicates how long to blocking trying to notify the
   * <Select_Reactor>.  If @a timeout == 0, the caller will block until
   * action is possible, else will wait until the relative time
   * specified in *@a timeout elapses).
   */
  virtual int notify (ACE_Event_Handler * = 0,
                      ACE_Reactor_Mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value * = 0);
  /**
   * Set the maximum number of times that the
   * <ACE_Select_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify pipe before breaking out of its <recv> loop.  By default,
   * this is set to -1, which means "iterate until the pipe is empty."
   * Setting this to a value like "1 or 2" will increase "fairness"
   * (and thus prevent starvation) at the expense of slightly higher
   * dispatching overhead.
   */
  virtual void max_notify_iterations (int);
  /**
   * Get the maximum number of times that the
   * <ACE_Select_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify pipe before breaking out of its <recv> loop.
   */
  virtual int max_notify_iterations (void);
  /// Get the existing restart value.
  virtual int restart (void);
  /// Set a new value for restart and return the original value.
  virtual int restart (int r);
  /// Set position that the main ACE_Select_Reactor thread is requeued in the
  /// list of waiters during a <notify> callback.
  virtual void requeue_position (int);
  /// Get position that the main ACE_Select_Reactor thread is requeued in the
  /// list of waiters during a <notify> callback.
  virtual int requeue_position (void);
  // = Low-level wait_set mask manipulation methods.
  /// GET/SET/ADD/CLR the dispatch mask "bit" bound with the <eh> and
  /// @a mask.
  virtual int mask_ops (ACE_Event_Handler *eh,
                        ACE_Reactor_Mask mask,
                        int ops);
  /// GET/SET/ADD/CLR the dispatch MASK "bit" bound with the <handle>
  /// and @a mask.
  virtual int mask_ops (ACE_HANDLE handle,
                        ACE_Reactor_Mask mask,
                        int ops);
  // = Low-level ready_set mask manipulation methods.
  /// GET/SET/ADD/CLR the ready "bit" bound with the <eh> and @a mask.
  virtual int ready_ops (ACE_Event_Handler *eh,
                         ACE_Reactor_Mask mask,
                         int ops);
  /// GET/SET/ADD/CLR the ready "bit" bound with the <handle> and @a mask.
  virtual int ready_ops (ACE_HANDLE handle,
                         ACE_Reactor_Mask,
                         int ops);
  /// Wake up all threads in waiting in the event loop
  virtual void wakeup_all_threads (void);
  // = Only the owner thread can perform a <handle_events>.
  /// Set the new owner of the thread and return the old owner.
  virtual int owner (ACE_thread_t n_id, ACE_thread_t *o_id = 0);
  /// Return the current owner of the thread.
  virtual int owner (ACE_thread_t *);
  // = Miscellaneous Handler operations.
  /**
   * Return the Event_Handler associated with <handle>.  Return 0 if
   * <handle> is not registered.
   */
  virtual ACE_Event_Handler *find_handler (ACE_HANDLE handle);
  /**
   * Check to see if <handle> is associated with a valid Event_Handler
   * bound to @a mask.  Return the @a eh associated with this @a handler
   * if <eh> != 0.
   */
  virtual int handler (ACE_HANDLE handle,
                       ACE_Reactor_Mask mask,
                       ACE_Event_Handler **eh = 0);
  /**
   * Check to see if @a signum is associated with a valid Event_Handler
   * bound to a signal.  Return the <eh> associated with this
   * handler if <eh> != 0.
   */
  virtual int handler (int signum,
                       ACE_Event_Handler ** = 0);
  /// Returns true if we've been successfully initialized, else false.
  virtual bool initialized (void);
  /// Returns the current size of the Reactor's internal descriptor
  /// table.
  virtual size_t size (void) const;
  /**
   * Returns a reference to the ACE_Reactor_Token that is
   * used to serialize the internal processing logic.
   * This can be useful for situations where you need to avoid
   * deadlock efficiently when ACE_Event_Handlers are used in
   * multiple threads.
   */
  virtual ACE_Lock &lock (void);
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  // = Internal methods that do the actual work.
  // All of these methods assume that the token
  // lock is held by the public methods that call down to them.
  /// Do the work of actually binding the <handle> and <eh> with the
  /// @a mask.
  virtual int register_handler_i (ACE_HANDLE handle,
                                  ACE_Event_Handler *eh,
                                  ACE_Reactor_Mask mask);
  /// Register a set of <handles>.
  virtual int register_handler_i (const ACE_Handle_Set &handles,
                                  ACE_Event_Handler *handler,
                                  ACE_Reactor_Mask mask);
  /// Do the work of actually unbinding the <handle> and <eh> with the
  /// @a mask.
  virtual int remove_handler_i (ACE_HANDLE handle,
                                ACE_Reactor_Mask);
  /// Remove a set of <handles>.
  virtual int remove_handler_i (const ACE_Handle_Set &handles,
                                ACE_Reactor_Mask);
  /// Suspend the <Event_Handler> associated with <handle>
  virtual int suspend_i (ACE_HANDLE handle);
  /// Check to see if the <Event_Handler> associated with <handle> is
  /// suspended. Returns 0 if not, 1 if so.
  virtual int is_suspended_i (ACE_HANDLE handle);
  /// Resume the <Event_Handler> associated with <handle>
  virtual int resume_i (ACE_HANDLE handle);
  /// Implement the public handler method.
  virtual ACE_Event_Handler *find_handler_i (ACE_HANDLE handle);
  /// Implement the public handler method.
  virtual int handler_i (ACE_HANDLE handle,
                         ACE_Reactor_Mask,
                         ACE_Event_Handler ** = 0);
  /// Implement the public handler method.
  virtual int handler_i (int signum, ACE_Event_Handler ** = 0);
  /**
   * Check if there are any HANDLEs enabled in the <ready_set_>, and
   * if so, update the <handle_set> and return the number ready.  If
   * there aren't any HANDLEs enabled return 0.
   */
  virtual int any_ready (ACE_Select_Reactor_Handle_Set &handle_set);
  /// Implement the <any_ready> method, assuming that the Sig_Guard is
  /// beign held
  virtual int any_ready_i (ACE_Select_Reactor_Handle_Set &handle_set);
  /// Take corrective action when errors occur.
  virtual int handle_error (void);
  /// Make sure the handles are all valid.
  virtual int check_handles (void);
  /// Wait for events to occur.
  virtual int wait_for_multiple_events (ACE_Select_Reactor_Handle_Set &,
                                        ACE_Time_Value *);
  // = Dispatching methods.
  /**
   * Template Method that dispatches ACE_Event_Handlers for time
   * events, I/O events, and signal events.  Returns the total number
   * of ACE_Event_Handlers that were dispatched or -1 if something
   * goes wrong.
   */
  virtual int dispatch (int nfound,
                        ACE_Select_Reactor_Handle_Set &);
  /**
   * Dispatch all timer handlers that have expired.  Returns -1 if the
   * state of the <wait_set_> has changed, else 0.
   * <number_dispatched> is set to the number of timer handlers
   * dispatched.
   */
  virtual int dispatch_timer_handlers (int &number_dispatched);
  /**
   * Dispatch any notification handlers.  Returns -1 if the state of
   * the <wait_set_> has changed, else returns number of handlers
   * notified.
   */
  virtual int dispatch_notification_handlers (ACE_Select_Reactor_Handle_Set &dispatch_set,
                                              int &number_of_active_handles,
                                              int &number_of_handlers_dispatched);
  /**
   * Dispatch all the input/output/except handlers that are enabled in
   * the <dispatch_set>.  Updates <number_of_active_handles> and
   * <number_of_handlers_dispatched> according to the behavior of the
   * number Returns -1 if the state of the <wait_set_> has changed,
   * else 0.
   */
  virtual int dispatch_io_handlers (ACE_Select_Reactor_Handle_Set &dispatch_set,
                                    int &number_of_active_handles,
                                    int &number_of_handlers_dispatched);
  /**
   * Factors the dispatching of an io handle set (each WRITE, EXCEPT
   * or READ set of handles).  It updates the
   * <number_of_handlers_dispatched> and invokes this->notify_handle
   * for all the handles in <dispatch_set> using the @a mask,
   * <ready_set> and <callback> parameters.  Must return -1 if
   * this->state_changed otherwise it must return 0.
   */
  virtual int dispatch_io_set (int number_of_active_handles,
                               int &number_of_handlers_dispatched,
                               int mask,
                               ACE_Handle_Set& dispatch_mask,
                               ACE_Handle_Set& ready_mask,
                               ACE_EH_PTMF callback);
  /// Notify the appropriate <callback> in the context of the <eh>
  /// associated with <handle> that a particular event has occurred.
  virtual void notify_handle (ACE_HANDLE handle,
                              ACE_Reactor_Mask mask,
                              ACE_Handle_Set &,
                              ACE_Event_Handler *eh,
                              ACE_EH_PTMF callback);
  /// Enqueue ourselves into the list of waiting threads at the
  /// appropriate point specified by <requeue_position_>.
  virtual void renew (void);
  /// Synchronization token for the MT_SAFE ACE_Select_Reactor.
  ACE_SELECT_REACTOR_TOKEN token_;
  /// Adapter used to return internal lock to outside world.
  ACE_Lock_Adapter<ACE_SELECT_REACTOR_TOKEN> lock_adapter_;
  /// Release the token lock when a Win32 structured exception occurs.
  int release_token (void);
  /// Stops the VC++ compiler from bitching about exceptions and destructors
  int handle_events_i (ACE_Time_Value *max_wait_time = 0);
  /// This flag is used to keep track of whether we are actively handling
  /// events or not.
  sig_atomic_t deactivated_;
private:
  /// Deny access since member-wise won't work...
  ACE_UNIMPLEMENTED_FUNC (ACE_Select_Reactor_T (const ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN> &operator=  (const ACE_Select_Reactor_T<ACE_SELECT_REACTOR_TOKEN> &) )
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Select_Reactor_T.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Select_Reactor_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Select_Reactor_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_SELECT_REACTOR_T_H */

