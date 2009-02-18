// -*- C++ -*-

//=============================================================================
/**
 *  @file    Reactor.h
 *
 *  $Id: Reactor.h 82117 2008-06-22 17:05:12Z schmidt $
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_REACTOR_H
#define ACE_REACTOR_H

#include /**/ "ace/pre.h"

// Timer Queue is a complicated template class. A simple forward
// declaration will not work.
#include "ace/Timer_Queuefwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Contains the timer related interface for the Reactor.
#include "ace/Reactor_Timer_Interface.h"

// Event_Handler.h contains the definition of ACE_Reactor_Mask
#include "ace/Event_Handler.h"

// Get ACE_Time_Value in
#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Reactor_Impl;
class ACE_Handle_Set;
class ACE_Sig_Action;
class ACE_Sig_Handler;
class ACE_Sig_Set;

/*
 * Hook to specialize the Reactor implementation with the concrete
 * Reactor type, for exmaple, select, thread pool reactor known
 * at compile time.
 */
//@@ REACTOR_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK

/**
 * @class ACE_Reactor
 *
 * @brief This class forwards all methods to its delegation/implementation class, e.g.,
 * ACE_Select_Reactor or ACE_WFMO_Reactor.
 */
class ACE_Export ACE_Reactor : public ACE_Reactor_Timer_Interface
{
public:
  /// Operations on the "ready" mask and the "dispatch" mask.
  enum
  {
    /// Retrieve current value of the the "ready" mask or the
    /// "dispatch" mask.
    GET_MASK = 1,
    /// Set value of bits to new mask (changes the entire mask).
    SET_MASK = 2,
    /// Bitwise "or" the value into the mask (only changes enabled
    /// bits).
    ADD_MASK = 3,
    /// Bitwise "and" the negation of the value out of the mask (only
    /// changes enabled bits).
    CLR_MASK = 4
  };

  /**
   * You can specify a hook function to event-handling methods that will
   * be called after each iteration of event handling.  If the hook function
   * returns a non-zero value, the event loop will immediately resume
   * waiting for the next event(s) to process without checking the error
   * status of the just-completed iteration of event handling or the
   * end-of-loop indication. If the hook function returns 0, the event
   * handling error status and the end-of-loop indication will be checked
   * as normal, just as if there is no hook function specified.
   */
  typedef int (*REACTOR_EVENT_HOOK)(ACE_Reactor *);

  /// Get pointer to a process-wide ACE_Reactor.
  static ACE_Reactor *instance (void);

  /**
   * Set pointer to a process-wide ACE_Reactor and return existing
   * pointer.  If @a delete_reactor == true then we'll delete the Reactor
   * at destruction time.
   */
  static ACE_Reactor *instance (ACE_Reactor *, bool delete_reactor = false);

  /// Delete the dynamically allocated Singleton
  static void close_singleton (void);

  /// Name of the dll in which the dll lives.
  static const ACE_TCHAR *dll_name (void);

  /// Name of the component--ACE_Reactor in this case.
  static const ACE_TCHAR *name (void);

  // = Singleton reactor event loop management methods.

  // Note that these method ONLY work on the "Singleton Reactor,"
  // i.e., the one returned from <ACE_Reactor::instance>.
  /**
   * Run the event loop until the
   * <ACE_Reactor::handle_events/ACE_Reactor::alertable_handle_events>
   * method returns -1 or the <end_event_loop> method is invoked.
   * Note that this method can only be used by the singleton
   * <ACE_Reactor::instance>.  Thus, to run another reactor use
   * <ACE_Reactor::run_reactor_event_loop>.
   *
   * @deprecated Use ACE_Reactor::instance()->run_reactor_event_loop() instead
   */
  static int run_event_loop (void);
  static int run_alertable_event_loop (void);

  /**
   * Run the event loop until the <ACE_Reactor::handle_events> or
   * <ACE_Reactor::alertable_handle_events> methods returns -1, the
   * <end_event_loop> method is invoked, or the ACE_Time_Value
   * expires.  Note that this method can only be used by the singleton
   * <ACE_Reactor::instance>.  Thus, to run another reactor use
   * <ACE_Reactor::run_reactor_event_loop>.
   *
   * @deprecated Use ACE_Reactor::instance()->run_reactor_event_loop() instead
   */
  static int run_event_loop (ACE_Time_Value &tv);
  static int run_alertable_event_loop (ACE_Time_Value &tv);

  /**
   * Instruct the <ACE_Reactor::instance> to terminate its event loop
   * and notifies the <ACE_Reactor::instance> so that it can wake up
   * and close down gracefully.  Note that this method can only be
   * used by the singleton <ACE_Reactor::instance>.  Thus, to
   * terminate another reactor, use
   * <ACE_Reactor::end_reactor_event_loop>.
   *
   * @deprecated Use ACE_Reactor::instance()->end_reactor_event_loop() instead
   */
  static int end_event_loop (void);

  /**
   * Report if the <ACE_Reactor::instance>'s event loop is finished.
   * Note that this method can only be used by the singleton
   * <ACE_Reactor::instance>.  Thus, to check another reactor use
   * <ACE_Reactor::reactor_event_loop_done>.
   *
   * @deprecated Use ACE_Reactor::instance()->reactor_event_loop_done() instead
   */
  static int event_loop_done (void);

  /**
   * Resets the <ACE_Reactor::end_event_loop_> static so that the
   * <run_event_loop> method can be restarted.  Note that this method
   * can only be used by the singleton <ACE_Reactor::instance>.  Thus,
   * to reset another reactor use <ACE_Reactor::reset_reactor_event_loop>.
   *
   * @deprecated Use ACE_Reactor::instance()->reset_reactor_event_loop()
   * instead
   */
  static void reset_event_loop (void);

  /**
   * The singleton reactor is used by the ACE_Service_Config.
   * Therefore, we must check for the reconfiguration request and
   * handle it after handling an event.
   */
  static int check_reconfiguration (ACE_Reactor *);

  // = Reactor event loop management methods.

  // These methods work with an instance of a reactor.
  /**
   * Run the event loop until the
   * <ACE_Reactor::handle_events/ACE_Reactor::alertable_handle_events>
   * method returns -1 or the <end_reactor_event_loop> method is invoked.
   */
  int run_reactor_event_loop (REACTOR_EVENT_HOOK = 0);
  int run_alertable_reactor_event_loop (REACTOR_EVENT_HOOK = 0);

  /**
   * Run the event loop until the <ACE_Reactor::handle_events> or
   * <ACE_Reactor::alertable_handle_events> methods returns -1, the
   * <end_reactor_event_loop> method is invoked, or the ACE_Time_Value
   * expires.
   */
  int run_reactor_event_loop (ACE_Time_Value &tv,
                              REACTOR_EVENT_HOOK = 0);
  int run_alertable_reactor_event_loop (ACE_Time_Value &tv,
                                        REACTOR_EVENT_HOOK = 0);

  /**
   * Instruct the Reactor to terminate its event loop and notifies the
   * Reactor so that it can wake up and deactivate
   * itself. Deactivating the Reactor would allow the Reactor to be
   * shutdown gracefully. Internally the Reactor calls deactivate ()
   * on the underlying implementation.
   * Any queued notifications remain queued on return from this method.
   * If the event loop is restarted in the future, the notifications
   * will be dispatched then. If the reactor is closed or deleted without
   * further dispatching, the notifications will be lost.
   */
  int end_reactor_event_loop (void);

  /// Indicate if the Reactor's event loop has been ended.
  int reactor_event_loop_done (void);

  /// Resets the <ACE_Reactor::end_event_loop_> static so that the
  /// <run_event_loop> method can be restarted.
  void reset_reactor_event_loop (void);

  /**
   * Create the Reactor using @a implementation.  The flag
   * @a delete_implementation tells the Reactor whether or not to
   * delete the @a implementation on destruction.
   */
  ACE_Reactor (ACE_Reactor_Impl *implementation = 0,
               bool delete_implementation = false);

  /// Close down and release all resources.
  /**
   * Any notifications that remain queued on this reactor instance are
   * lost.
   */
  virtual ~ACE_Reactor (void);

  /**
   * Initialize the ACE_Reactor to manage <max_number_of_handles>.
   * If <restart> is non-0 then the ACE_Reactor's <handle_events>
   * method will be restarted automatically when <EINTR> occurs.  If
   * <signal_handler> or <timer_queue> are non-0 they are used as the
   * signal handler and timer queue, respectively.
   */
  int open (size_t max_number_of_handles,
            int restart = 0,
            ACE_Sig_Handler *signal_handler = 0,
            ACE_Timer_Queue *timer_queue = 0);

  /// Use a user specified signal handler instead.
  int set_sig_handler (ACE_Sig_Handler *signal_handler);

  /// Set a user-specified timer queue.
  int timer_queue (ACE_Timer_Queue *tq);

  /// Return the current ACE_Timer_Queue.
  ACE_Timer_Queue *timer_queue (void) const;

  /// Close down and release all resources.
  int close (void);

  // = Event loop drivers.

  /**
   * Returns non-zero if there are I/O events "ready" for dispatching,
   * but does not actually dispatch the event handlers.  By default,
   * don't block while checking this, i.e., "poll".
   */
  int work_pending (const ACE_Time_Value &max_wait_time = ACE_Time_Value::zero);

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
   * Returns the total number of timers and I/O ACE_Event_Handlers
   * that were dispatched, 0 if the @a max_wait_time elapsed without
   * dispatching any handlers, or -1 if an error occurs.
   *
   * The only difference between <alertable_handle_events> and
   * <handle_events> is that in the alertable case, the eventloop will
   * return when the system queues an I/O completion routine or an
   * Asynchronous Procedure Call.
   */
  int handle_events (ACE_Time_Value *max_wait_time = 0);
  int alertable_handle_events (ACE_Time_Value *max_wait_time = 0);

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
  int handle_events (ACE_Time_Value &max_wait_time);
  int alertable_handle_events (ACE_Time_Value &max_wait_time);

  // = Register and remove handlers.

  /**
   * Register handler for I/O events.
   *
   * A handler can be associated with multiple handles. A handle
   * cannot be associated with multiple handlers.
   *
   * The handle will come from ACE_Event_Handler::get_handle().
   *
   * Reactor will call ACE_Event_Handler::add_reference() for a new
   * handler/handle pair.
   *
   * If this handler/handle pair has already been registered, any new
   * masks specified will be added. In this case,
   * ACE_Event_Handler::add_reference() will not be called.
   *
   * If the registered handler is currently suspended, it will remain
   * suspended.  When the handler is resumed, it will have the
   * existing masks plus any masks added through this call. Handlers
   * do not have partial suspensions.
   */
  int register_handler (ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask mask);

  /**
   * Register handler for I/O events.
   *
   * Same as register_handler(ACE_Event_Handler*,ACE_Reactor_Mask),
   * except handle is explicitly specified.
   */
  int register_handler (ACE_HANDLE io_handle,
                        ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask mask);

#if defined (ACE_WIN32)

  /**
   * Register handler for OS events.
   *
   * Register an @a event_handler that will be notified when
   * <event_handle> is signaled.  This will call back its
   * <handle_signal> hook method.
   *
   * Reactor will call ACE_Event_Handler::add_reference() for a new
   * handler/handle pair.
   *
   * This interface is only available Win32 platforms because
   * ACE_HANDLE is an int on non-Win32 platforms and compilers are not
   * able to tell the difference between
   * register_handler(ACE_Event_Handler*,ACE_Reactor_Mask) and
   * register_handler(ACE_Event_Handler*,ACE_HANDLE).
   */
  int register_handler (ACE_Event_Handler *event_handler,
                        ACE_HANDLE event_handle = ACE_INVALID_HANDLE);

#endif /* ACE_WIN32 */

  /**
   * Register handler for I/O events.
   *
   * Similar to
   * register_handler(ACE_HANDLE,ACE_Event_Handler*,ACE_Reactor_Mask),
   * except that the user gets to specify the event handle that will
   * be used for this registration.  This only applies to Reactors
   * that use event handles for I/O registrations.
   */
  int register_handler (ACE_HANDLE event_handle,
                        ACE_HANDLE io_handle,
                        ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask mask);

  /**
   * Register handler for multiple I/O events.
   *
   * Shorthand for calling
   * register_handler(ACE_HANDLE,ACE_Event_Handler*,ACE_Reactor_Mask),
   * multiple times for the same @a event_handler and @a masks but
   * different <handles>.
   */
  int register_handler (const ACE_Handle_Set &handles,
                        ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask masks);

  /**
   * Register handler for signals.
   *
   * Register @a new_sh to handle the signal @a signum using the
   * @a new_disp.  Returns the @a old_sh that was previously registered
   * (if any), along with the @a old_disp of the signal handler.
   *
   * Reactor will call ACE_Event_Handler::add_reference() on @a new_sh
   * and ACE_Event_Handler::remove_reference() on @a old_sh.
   */
  int register_handler (int signum,
                        ACE_Event_Handler *new_sh,
                        ACE_Sig_Action *new_disp = 0,
                        ACE_Event_Handler **old_sh = 0,
                        ACE_Sig_Action *old_disp = 0);

  /**
   * Register handler for multiple signals.
   *
   * Shorthand for calling
   * register_handler(int,ACE_Event_Handler*,ACE_Sig_Action*,ACE_Event_Handler**,ACE_Sig_Action*)
   * multiple times for the same @a event_handler and @a sig_action but
   * different <signals>.
   */
  int register_handler (const ACE_Sig_Set &sigset,
                        ACE_Event_Handler *event_handler,
                        ACE_Sig_Action *sig_action = 0);

  /**
   * Remove @a masks from @a handle registration.
   *
   * For I/O handles, @a masks are removed from the Reactor.  Unless
   * @a masks includes ACE_Event_Handler::DONT_CALL,
   * ACE_Event_Handler::handle_close() will be called with the @a masks
   * that have been removed.  If all masks have been removed,
   * ACE_Event_Handler::remove_reference() will be called.
   *
   * For OS handles, the @a handle is removed from the Reactor.  Unless
   * @a masks includes ACE_Event_Handler::DONT_CALL,
   * ACE_Event_Handler::handle_close() will be called with
   * ACE_Event_Handler::NULL_MASK.
   * ACE_Event_Handler::remove_reference() will also be called.
   */
  int remove_handler (ACE_HANDLE handle,
                      ACE_Reactor_Mask masks);

  /**
   * Remove @a masks from @a event_handler registration.
   *
   * Same as remove_handler(ACE_HANDLE,ACE_Reactor_Mask), except
   * @a handle comes from ACE_Event_Handler::get_handle().
   */
  int remove_handler (ACE_Event_Handler *event_handler,
                      ACE_Reactor_Mask masks);

  /**
   * Remove @a masks from multiple <handle> registrations.
   *
   * Shorthand for calling remove_handler(ACE_HANDLE,ACE_Reactor_Mask)
   * multiple times for the same @a masks but different @a handles.
   */
  int remove_handler (const ACE_Handle_Set &handles,
                      ACE_Reactor_Mask masks);

  /**
   * Remove signal handler registration.
   *
   * Remove the ACE_Event_Handler currently associated with @a signum.
   * Install the new disposition (if given) and return the previous
   * disposition (if desired by the caller).
   *
   * Note that, unlike removing handler for I/O events,
   * ACE_Event_Handler::handle_close() will not be called when the
   * handler is removed. Neither will any reference-counting activity be
   * involved.
   *
   * @note There's an existing enhancement request in Bugzilla,
   * #2368, to change this behavior so that ACE_Event_Handler::handle_close()
   * is called when the signal handler is removed. Thus, there's some chance
   * this behavior will change in a future version of ACE.
   */
  int remove_handler (int signum,
                      ACE_Sig_Action *new_disp,
                      ACE_Sig_Action *old_disp = 0,
                      int sigkey = -1);

  /**
   * Remove multiple signal handler registrations.
   *
   * Shorthand for calling
   * remove_handler(int,ACE_Sig_Action*,ACE_Sig_Action*,int) multiple
   * times for every signal in @a sigset.
   */
  int remove_handler (const ACE_Sig_Set &sigset);

  // = Suspend and resume Handlers.

  /**
   * Suspend @a handle temporarily.
   */
  int suspend_handler (ACE_HANDLE handle);

  /**
   * Suspend @a event_handler temporarily.
   *
   * Handle is obtained from ACE_Event_Handler::get_handle().
   */
  int suspend_handler (ACE_Event_Handler *event_handler);

  /**
   * Suspend @a handles temporarily.
   *
   * Shorthand for calling suspend_handler(ACE_HANDLE) with multiple
   * @a handles.
   */
  int suspend_handler (const ACE_Handle_Set &handles);

  /**
   * Suspend all registered handles temporarily.
   */
  int suspend_handlers (void);

  /**
   * Resume @a handle.
   */
  int resume_handler (ACE_HANDLE handle);

  /**
   * Resume @a event_handler.
   *
   * Handle is obtained from ACE_Event_Handler::get_handle().
   */
  int resume_handler (ACE_Event_Handler *event_handler);

  /**
   * Resume @a handles.
   *
   * Shorthand for calling resume_handler(ACE_HANDLE) with multiple
   * <handles>.
   */
  int resume_handler (const ACE_Handle_Set &handles);

  /**
   * Resume all registered handles.
   */
  int resume_handlers (void);

  /// Does the reactor allow the application to resume the handle on
  /// its own ie. can it pass on the control of handle resumption to
  /// the application. A positive value indicates that the handlers
  /// are application resumable. A value of 0 indicates otherwise.
  int resumable_handler (void);

  // = Timer management.

  /**
   * Schedule a timer event.
   *
   * Schedule a timer event that will expire after an <delay> amount
   * of time.  The return value of this method, a timer_id value,
   * uniquely identifies the @a event_handler in the ACE_Reactor's
   * internal list of timers.  This timer_id value can be used to
   * cancel the timer with the cancel_timer() call.
   *
   * Reactor will call ACE_Event_Handler::add_reference() on the
   * handler.  After the timeout occurs and
   * ACE_Event_Handler::handle_timeout() has completed, the handler
   * will be implicitly removed from the Reactor and
   * ACE_Event_Handler::remove_reference() will be called.
   *
   * @see cancel_timer()
   * @see reset_timer_interval()
   *
   * @param event_handler Event handler to schedule on reactor
   * @param arg Argument passed to the handle_timeout() method of
   * event_handler
   * @param delay Time interval after which the timer will expire
   * @param interval Time interval after which the timer will be automatically
   * rescheduled
   * @return -1 on failure, a timer_id value on success
   */
  virtual long schedule_timer (ACE_Event_Handler *event_handler,
                               const void *arg,
                               const ACE_Time_Value &delay,
                               const ACE_Time_Value &interval =
                                ACE_Time_Value::zero);

  /**
   * Reset recurring timer interval.
   *
   * Resets the interval of the timer represented by @a timer_id to
   * @a interval, which is specified in relative time to the current
   * <gettimeofday>.  If @a interval is equal to
   * ACE_Time_Value::zero, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   *
   * This change will not take effect until the next timeout.
   */
  virtual int reset_timer_interval (long timer_id,
                                    const ACE_Time_Value &interval);

  /**
   * Cancel timer.
   *
   * Cancel timer associated with @a timer_id that was returned from
   * the schedule_timer() method.  If arg is non-NULL then it will be
   * set to point to the ``magic cookie'' argument passed in when the
   * handler was registered.  This makes it possible to free up the
   * memory and avoid memory leaks.  Returns 1 if cancellation
   * succeeded and 0 if the @a timer_id wasn't found.
   *
   * On successful cancellation, ACE_Event_Handler::handle_close()
   * will be called with ACE_Event_Handler::TIMER_MASK.
   * ACE_Event_Handler::remove_reference() will also be called.
   */
  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1);

  /**
   * Cancel all timers associated with event handler.
   *
   * Shorthand for calling cancel_timer(long,const void **,int)
   * multiple times for all timer associated with @a event_handler.
   *
   * ACE_Event_Handler::handle_close() will be called with
   * ACE_Event_Handler::TIMER_MASK only once irrespective of the
   * number of timers associated with the event handler.
   * ACE_Event_Handler::remove_reference() will also be called once
   * for every timer associated with the event handler.
   *
   * Returns number of handlers cancelled.
   */
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1);

  // = High-level Event_Handler scheduling operations

  /// Add @a masks_to_be_added to the @a event_handler's entry.
  /// @a event_handler must already have been registered.
  /// Note that this call does not cause the Reactor to re-examine
  /// its set of handlers - the new masks will be noticed the next
  /// time the Reactor waits for activity. If there is no other
  /// activity expected, or you need immediate re-examination of the
  /// wait masks, either call ACE_Reactor::notify after this call, or
  /// use ACE_Reactor::register_handler instead.
  int schedule_wakeup (ACE_Event_Handler *event_handler,
                       ACE_Reactor_Mask masks_to_be_added);

  /// Add @a masks_to_be_added to the @a handle's entry.  <event_handler>
  /// associated with @a handle must already have been registered.
  /// Note that this call does not cause the Reactor to re-examine
  /// its set of handlers - the new masks will be noticed the next
  /// time the Reactor waits for activity. If there is no other
  /// activity expected, or you need immediate re-examination of
  /// the wait masks, either call ACE_Reactor::notify after this call,
  /// or use ACE_Reactor::register_handler instead.
  int schedule_wakeup (ACE_HANDLE handle,
                       ACE_Reactor_Mask masks_to_be_added);

  /// Clear @a masks_to_be_cleared from the @a event_handler's entry.
  /// Note that this call does not cause the Reactor to re-examine
  /// its set of handlers - the new masks will be noticed the next
  /// time the Reactor waits for activity. If there is no other
  /// activity expected, or you need immediate re-examination of
  /// the wait masks, either call ACE_Reactor::notify after this
  /// call, or use ACE_Reactor::register_handler instead.
  int cancel_wakeup (ACE_Event_Handler *event_handler,
                     ACE_Reactor_Mask masks_to_be_cleared);

  /// Clear @a masks_to_be_cleared from the <handle>'s entry.
  /// Note that this call does not cause the Reactor to re-examine
  /// its set of handlers - the new masks will be noticed the next
  /// time the Reactor waits for activity. If there is no other
  /// activity expected, or you need immediate re-examination of
  /// the wait masks, either call ACE_Reactor::notify after this
  /// call, or use ACE_Reactor::register_handler instead.
  int cancel_wakeup (ACE_HANDLE handle,
                     ACE_Reactor_Mask masks_to_be_cleared);

  // = Notification methods.

  /**
   * Dispatch user specified events.
   *
   * Handler will be dispatched irrespective of whether it is
   * registered, not registered, or suspended in the Reactor.
   *
   * If user specified event is successfully queued,
   * ACE_Event_Handler::add_reference() will be called.  After the
   * notify occurs and the upcall to the handler completes, the
   * handler will be implicitly removed from the Reactor and
   * ACE_Event_Handler::remove_reference() will be called.  No other
   * upcall reference counting is done.
   *
   * For I/O or OS events, the upcall is invoked with an
   * ACE_INVALID_HANDLE.
   *
   * For timer events, the upcall is invoked with a null ACT.
   *
   * @param event_handler: IN - Handler on which the event will be
   * dispatched.
   * @param masks: IN - Events to be dispatched - multiple events can
   * be OR'd together.
   * @param timeout: INOUT - Relative time up to which to wait for
   * user specified event to be queued.  If tv is 0, wait
   * indefinitely.  When the call returns, tv has the time remaining
   * after the call completes.
   */
  int notify (ACE_Event_Handler *event_handler = 0,
              ACE_Reactor_Mask masks = ACE_Event_Handler::EXCEPT_MASK,
              ACE_Time_Value *timeout = 0);

  /**
   * Set the maximum number of times that ACE_Reactor will
   * iterate and dispatch the ACE_Event_Handlers that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."  Setting this
   * to a value like "1 or 2" will increase "fairness" (and thus
   * prevent starvation) at the expense of slightly higher dispatching
   * overhead.
   */
  void max_notify_iterations (int iterations);

  /**
   * Get the maximum number of times that the ACE_Reactor will
   * iterate and dispatch the ACE_Event_Handler's that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.
   */
  int max_notify_iterations (void);

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. If @a eh == 0, all notifications for
   * all handlers are removed (but not any notifications posted just
   * to wake up the reactor itself). Returns the number of
   * notifications purged.  Returns -1 on error.
   *
   * After the purging occurs, the handler will be implicitly removed
   * from the Reactor and ACE_Event_Handler::remove_reference() will
   * be called.
   */
  int purge_pending_notifications (ACE_Event_Handler *eh,
                                   ACE_Reactor_Mask =
                                            ACE_Event_Handler::ALL_EVENTS_MASK);

  // = Assorted helper methods.

  /**
   * Return the Event_Handler associated with @a handle.  Return 0 if
   * @a handle is not registered.
   *
   * Reactor will call ACE_Event_Handler::add_reference() on the
   * handler before returning it.
   */
  ACE_Event_Handler *find_handler (ACE_HANDLE handle);

  /**
   * Check to see if @a handle is associated with a valid Event_Handler
   * bound to @a mask.  Return the @c event_handler associated with this
   * @a handler if @a event_handler != 0.
   *
   * Reactor will call ACE_Event_Handler::add_reference() on the
   * handler before returning it if @a event_handler != 0.
   */
  int handler (ACE_HANDLE handle,
               ACE_Reactor_Mask mask,
               ACE_Event_Handler **event_handler = 0);

  /**
   * Check to see if @a signum is associated with a valid Event_Handler
   * bound to a signal.  Return the @a event_handler associated with
   * this @c handler if @a event_handler != 0.
   */
  int handler (int signum,
               ACE_Event_Handler **event_handler = 0);

  /// Returns true if Reactor has been successfully initialized, else
  /// false.
  int initialized (void);

  /// Returns the current size of the Reactor's internal descriptor
  /// table.
  size_t size (void) const;

  /// Returns a reference to the Reactor's internal lock.
  ACE_Lock &lock (void);

  /// Wake up all threads in waiting in the event loop
  void wakeup_all_threads (void);

  /// Transfers ownership of Reactor to the @a new_owner.
  int owner (ACE_thread_t new_owner,
             ACE_thread_t *old_owner = 0);

  /// Return the ID of the "owner" thread.
  int owner (ACE_thread_t *owner);

  /// Set position of the owner thread.
  void requeue_position (int position);

  /// Get position of the owner thread.
  int requeue_position (void);

  /// Get the existing restart value.
  int restart (void);

  /// Set a new value for restart and return the original value.
  int restart (int r);

  // = Low-level wait_set mask manipulation methods.

  /// GET/SET/ADD/CLR the dispatch mask "bit" bound with the
  /// @a event_handler and @a mask.
  int mask_ops (ACE_Event_Handler *event_handler,
                ACE_Reactor_Mask mask,
                int ops);

  /// GET/SET/ADD/CLR the dispatch MASK "bit" bound with the @a handle
  /// and @a mask.
  int mask_ops (ACE_HANDLE handle,
                ACE_Reactor_Mask mask,
                int ops);

  // = Low-level ready_set mask manipulation methods.
  /// GET/SET/ADD/CLR the ready "bit" bound with the @a event_handler
  /// and @a mask.
  int ready_ops (ACE_Event_Handler *event_handler,
                 ACE_Reactor_Mask mask,
                 int ops);

  /// GET/SET/ADD/CLR the ready "bit" bound with the <handle> and @a mask.
  int ready_ops (ACE_HANDLE handle,
                 ACE_Reactor_Mask mask,
                 int ops);

  /// Get the implementation class
  ACE_Reactor_Impl *implementation (void) const;

  /**
   * Returns 0, if the size of the current message has been put in
   * @a size returns -1, if not.  ACE_HANDLE allows the reactor to
   * check if the caller is valid.  Used for CLASSIX Reactor
   * implementation.
   */
  int current_info (ACE_HANDLE handle, size_t &msg_size);

  /// Return 1 if we any event associations were made by the reactor
  /// for the handles that it waits on, 0 otherwise.
  int uses_event_associations (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// Dump the state of the object.
  void dump (void) const;

protected:
  /// Set the implementation class.
  void implementation (ACE_Reactor_Impl *implementation);

  /// Delegation/implementation class that all methods will be
  /// forwarded to.
  ACE_Reactor_Impl *implementation_;

  /// Flag used to indicate whether we are responsible for cleaning up
  /// the implementation instance
  bool delete_implementation_;

  /// Pointer to a process-wide ACE_Reactor singleton.
  static ACE_Reactor *reactor_;

  /// Must delete the reactor_ singleton if true.
  static bool delete_reactor_;

  /// Deny access since member-wise won't work...
  ACE_Reactor (const ACE_Reactor &);
  ACE_Reactor &operator = (const ACE_Reactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "ace/Reactor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_REACTOR_H */

