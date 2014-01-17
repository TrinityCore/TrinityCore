// -*- C++ -*-

// =========================================================================
/**
 *  @file    Dev_Poll_Reactor.h
 *
 *  $Id: Dev_Poll_Reactor.h 94549 2011-10-03 06:31:27Z johnnyw $
 *
 *  @c /dev/poll (or Linux @c sys_epoll) based Reactor implementation.
 *
 *  @author  Ossama Othman <ossama@dre.vanderbilt.edu>
 */
// =========================================================================


#ifndef ACE_DEV_POLL_REACTOR_H
#define ACE_DEV_POLL_REACTOR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_EVENT_POLL) && defined (ACE_HAS_DEV_POLL)
#  error ACE_HAS_EVENT_POLL and ACE_HAS_DEV_POLL are mutually exclusive.
#endif  /* ACE_HAS_EVENT_POLL && defined ACE_HAS_DEV_POLL */

#if defined (ACE_HAS_EVENT_POLL) || defined (ACE_HAS_DEV_POLL)

#include "ace/Pipe.h"
#include "ace/Lock_Adapter_T.h"
#include "ace/Reactor_Impl.h"
#include "ace/Reactor_Token_T.h"
#include "ace/Token.h"

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
# include "ace/Notification_Queue.h"
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

#if defined (ACE_HAS_DEV_POLL)
struct pollfd;
#elif defined (ACE_HAS_EVENT_POLL)
#  include "ace/Array_Map.h"
#  include /**/ <sys/epoll.h>
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations
class ACE_Sig_Handler;
class ACE_Dev_Poll_Reactor;


// ---------------------------------------------------------------------

/**
 * @class ACE_Dev_Poll_Reactor_Notify
 *
 * @brief Event handler used for unblocking the ACE_Dev_Poll_Reactor
 *        from its event loop.
 *
 * This event handler is used internally by the ACE_Dev_Poll_Reactor
 * as a means to allow a thread other then the one running the event
 * loop to unblock the event loop.
 */
class ACE_Dev_Poll_Reactor_Notify : public ACE_Reactor_Notify
{
public:

  /// Constructor
  ACE_Dev_Poll_Reactor_Notify (void);

  /**
   * @name Initialization and Termination Methods
   *
   * Methods called when initializing and terminating this event
   * handler.
   */
  virtual int open (ACE_Reactor_Impl *,
                    ACE_Timer_Queue *timer_queue = 0,
                    int disable_notify = 0);
  virtual int close (void);

  /**
   * Called by a thread when it wants to unblock the Reactor_Impl.
   * This wakes up the Reactor_Impl if currently blocked.  Pass over
   * both the Event_Handler and the mask to allow the caller to
   * dictate which Event_Handler method the Reactor_Impl will
   * invoke.  The ACE_Time_Value indicates how long to block
   * trying to notify the Reactor_Impl.  If timeout == 0, the
   * caller will block until action is possible, else will wait until
   * the relative time specified in *timeout elapses).
   */
  virtual int notify (ACE_Event_Handler *eh = 0,
                      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value *timeout = 0);

  /// Unimplemented method required by pure virtual method in abstract
  /// base class.
  /**
   * This method's interface is not very compatibile with this
   * Reactor's design.  It's not clear why this method is pure virtual
   * either.
   */
  virtual int dispatch_notifications (int &number_of_active_handles,
                                      ACE_Handle_Set &rd_mask);

  /// Returns the ACE_HANDLE of the notify pipe on which the reactor
  /// is listening for notifications so that other threads can unblock
  /// the Reactor_Impl.
  virtual ACE_HANDLE notify_handle (void);

  /// Verify whether the buffer has dispatchable info or not.
  virtual int is_dispatchable (ACE_Notification_Buffer &buffer);

  /// Handle one notify call represented in @a buffer.  This could be
  /// because of a thread trying to unblock the Reactor_Impl.
  virtual int dispatch_notify (ACE_Notification_Buffer &buffer);

  /// Read one notify call on the handle into @a buffer.
  /// This could be because of a thread trying to unblock the Reactor_Impl.
  virtual int read_notify_pipe (ACE_HANDLE handle,
                                ACE_Notification_Buffer &buffer);

  /// Called back by the ACE_Dev_Poll_Reactor when a thread wants to
  /// unblock us.
  virtual int handle_input (ACE_HANDLE handle);

  /**
   * Set the maximum number of times that the handle_input method
   * will iterate and dispatch the ACE_Event_Handlers that are
   * passed in via the notify queue before breaking out of the event
   * loop.  By default, this is set to -1, which means "iterate until
   * the queue is empty."  Setting this to a value like "1 or 2" will
   * increase "fairness" (and thus prevent starvation) at the expense
   * of slightly higher dispatching overhead.
   */
  virtual void max_notify_iterations (int);

  /**
   * Get the maximum number of times that the handle_input method
   * will iterate and dispatch the ACE_Event_Handlers that are
   * passed in via the notify queue before breaking out of its event
   * loop.
   */
  virtual int max_notify_iterations (void);

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. Returns the number of notifications
   * purged. Returns -1 on error.
   */
  virtual int purge_pending_notifications (
    ACE_Event_Handler * = 0,
    ACE_Reactor_Mask    = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Method called by ACE_Dev_Poll_Reactor to obtain one notification.
  /// THIS METHOD MUST BE CALLED WITH THE REACTOR TOKEN HELD!
  ///
  /// @return -1 on error, else 0 and @arg nb has the notify to
  ///            dispatch. Note that the contained event handler may be
  ///            0 if there were only wake-ups (no handlers to dispatch).
  int dequeue_one (ACE_Notification_Buffer &nb);

protected:

  /**
   * Keep a back pointer to the ACE_Dev_Poll_Reactor.  If this value
   * if NULL then the ACE_Dev_Poll_Reactor has been initialized with
   * disable_notify_pipe.
   */
  ACE_Dev_Poll_Reactor *dp_reactor_;

  /**
   * Contains the ACE_HANDLE the ACE_Dev_Poll_Reactor is listening
   * on, as well as the ACE_HANDLE that threads wanting the attention
   * of the ACE_Dev_Poll_Reactor will write to.
   */
  ACE_Pipe notification_pipe_;

  /**
   * Keeps track of the maximum number of times that the
   * ACE_Dev_Poll_Reactor_Notify::handle_input method will iterate and
   * dispatch the ACE_Event_Handlers that are passed in via the
   * notify pipe before breaking out of its recv loop.  By default,
   * this is set to -1, which means "iterate until the pipe is empty."
   */
  int max_notify_iterations_;

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
  /**
   * @brief A user-space queue to store the notifications.
   *
   * The notification pipe has OS-specific size restrictions.  That
   * is, no more than a certain number of bytes may be stored in the
   * pipe without blocking.  This limit may be too small for certain
   * applications.  In this case, ACE can be configured to store all
   * the events in user-space.  The pipe is still needed to wake up
   * the reactor thread, but only one event is sent through the pipe
   * at a time.
   */
  ACE_Notification_Queue notification_queue_;
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */
};

// ---------------------------------------------------------------------

/**
 * @class ACE_Dev_Poll_Reactor
 *
 * @brief A `/dev/poll' or `/dev/epoll' based Reactor implemenatation.
 *
 * @attention The Linux epoll implementation works quite well and is
 * fully supported; however, the /dev/poll implementation is @em experimental.
 *
 * The ACE_Dev_Poll_Reactor uses the `/dev/poll' or '/dev/epoll'
 * character devices to demultiplex events on a given set of file
 * descriptors.  Unlike @c select(), `/dev/poll' and `/dev/epoll' have
 * no hard-coded limit on the number of file descriptors that may be
 * handled at any given time.  As such, the ACE_Dev_Poll_Reactor can
 * generally handle a much larger number of file descriptors than
 * @c select() -based reactors.  Furthermore, since `/dev/poll' and
 * `/dev/epoll' both return a set of file descriptors that are active,
 * there is no need to "walk" the set of file descriptors to determine
 * which ones are active, such as what is done with the @c select() and
 * @c poll() system calls.  All returned file descriptors are active.
 * This makes event dispatching very efficient.
 *
 * @note In general, this reactor may only be used to demultiplex
 *       events on sockets.  Demultiplexing events on pipes, for
 *       example may not work.  This is due to a limitation in the
 *       underlying `/dev/poll' device driver.
 *
 * @note It is only possible to achieve millisecond timeout
 *       resolutions with the @c ACE_Dev_Poll_Reactor.  However, the
 *       timeout resolution for timers is independent of the reactors
 *       timeout resolution.  As such, it may be possible to achieve
 *       sub-millisecond timeout resolutions for timers but that is
 *       entirely platform dependent.
 */

#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
typedef ACE_Token ACE_DEV_POLL_TOKEN;
#else
typedef ACE_Noop_Token ACE_DEV_POLL_TOKEN;
#endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */
typedef ACE_Reactor_Token_T<ACE_DEV_POLL_TOKEN> ACE_Dev_Poll_Reactor_Token;

class ACE_Export ACE_Dev_Poll_Reactor : public ACE_Reactor_Impl
{

  /**
   * @struct Event_Tuple
   *
   * @brief Struct that collects event registration information for a handle.
   *
   * @internal Internal use only
   *
   * This struct merely provides a means to associate an event mask
   * with an event handler.  Such an association is needed since it is
   * not possible to retrieve the event mask from the "interest set"
   * stored in the `/dev/poll' or `/dev/epoll' driver.  Without this
   * external association, it would not be possible keep track of the
   * event mask for a given event handler when suspending it or resuming
   * it.
   *
   * @note An ACE_Handle_Set is not used since the number of handles may
   *       exceed its capacity (ACE_DEFAULT_SELECT_REACTOR_SIZE).
   */
  struct Event_Tuple
  {
    /// Constructor to set up defaults.
    Event_Tuple (ACE_Event_Handler *eh = 0,
                 ACE_Reactor_Mask m = ACE_Event_Handler::NULL_MASK,
                 bool is_suspended = false,
                 bool is_controlled = false);

    /// The event handler.
    ACE_Event_Handler *event_handler;

    /// The event mask for the above event handler.
    ACE_Reactor_Mask mask;

    /// Flag that states whether or not the event handler is suspended.
    bool suspended;

    /// Flag to say whether or not this handle is registered with epoll.
    bool controlled;
  };


  // ---------------------------------------------------------------------

  /**
   * @class Handler_Repository
   *
   * @internal
   *
   * @brief Used to map ACE_HANDLEs onto the appropriate Event_Tuple.
   *
   * This class is simply a container that maps a handle to its
   * corresponding event tuple. It is not meant for use outside of
   * the Dev_Poll_Reactor.
   *
   * @note Calls to any method in this class, and any modification to a
   *       Event_Tuple returned from this class's methods, must be made
   *       while holding the reactor token.
   */
  class Handler_Repository
  {
  public:

    /// Constructor.
    Handler_Repository (void);

    /// Initialize a repository that can map handles up to the value @a size.
    /// Since the event tuples are accessed directly using the handle as
    /// an index, @a size sets the maximum handle value, minus 1.
    int open (size_t size);

    /// Close down the repository.
    int close (void);

    /**
     * @name Repository Manipulation Operations
     *
     * Methods used to search and modify the handler repository.
     */
    //@{

    /// Return a pointer to the Event_Tuple associated with @a handle.
    /// If there is none associated, returns 0 and sets errno.
    Event_Tuple *find (ACE_HANDLE handle);


    /// Bind the ACE_Event_Handler to the @c ACE_HANDLE with the
    /// appropriate ACE_Reactor_Mask settings.
    int bind (ACE_HANDLE handle,
              ACE_Event_Handler *handler,
              ACE_Reactor_Mask mask);

    /// Remove the binding for @a handle; optionally decrement the associated
    /// handler's reference count.
    int unbind (ACE_HANDLE handle, bool decr_refcnt = true);

    /// Remove all the registered tuples.
    int unbind_all (void);

    //@}

    /**
     * @name Sanity Checking
     *
     * Methods used to prevent "out-of-range" errors when indexing the
     * underlying handler array.
     */
    //@{

    // Check the @a handle to make sure it's a valid @c ACE_HANDLE that
    // within the range of legal handles (i.e., greater than or equal to
    // zero and less than @c max_size_).
    bool invalid_handle (ACE_HANDLE handle) const;

    // Check the handle to make sure it's a valid @c ACE_HANDLE that is
    // within the range of currently registered handles (i.e., greater
    // than or equal to zero and less than @c max_handlep1_).
    bool handle_in_range (ACE_HANDLE handle) const;

    //@}

    /// Returns the current table size.
    size_t size (void) const;

    /// Returns the current table size.
    size_t max_size (void) const;

    /// Dump the state of an object.
    void dump (void) const;

    /// Declare the dynamic allocation hooks.
    ACE_ALLOC_HOOK_DECLARE;

  private:

    /// Current number of handles.
    int size_;

    /// Maximum number of handles.
    int max_size_;

    /// The underlying array of event handlers.
    /**
     * The array of event handlers is directly indexed directly using
     * an @c ACE_HANDLE value.  This is Unix-specific.
     */
    Event_Tuple *handlers_;

  };

public:

  /// Initialize @c ACE_Dev_Poll_Reactor with the default size.
  /**
   * The default size for the @c ACE_Dev_Poll_Reactor is the maximum
   * number of open file descriptors for the process.
   */
  ACE_Dev_Poll_Reactor (ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0,
                        int disable_notify_pipe = 0,
                        ACE_Reactor_Notify *notify = 0,
                        int mask_signals = 1,
                        int s_queue = ACE_DEV_POLL_TOKEN::FIFO);

  /// Initialize ACE_Dev_Poll_Reactor with size @a size.
  /**
   * @note On Unix platforms, the @a size parameter should be as large
   *       as the maximum number of file descriptors allowed for a
   *       given process.  This is necessary since a file descriptor
   *       is used to directly index the array of event handlers
   *       maintained by the Reactor's handler repository.  Direct
   *       indexing is used for efficiency reasons.  If the size
   *       parameter is less than the process maximum, the process
   *       maximum will be decreased in order to prevent potential
   *       access violations.
   */
  ACE_Dev_Poll_Reactor (size_t size,
                        bool restart = false,
                        ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0,
                        int disable_notify_pipe = 0,
                        ACE_Reactor_Notify *notify = 0,
                        int mask_signals = 1,
                        int s_queue = ACE_DEV_POLL_TOKEN::FIFO);

  /// Close down and release all resources.
  virtual ~ACE_Dev_Poll_Reactor (void);

  /// Initialization.
  virtual int open (size_t size,
                    bool restart = false,
                    ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    int disable_notify_pipe = 0,
                    ACE_Reactor_Notify * = 0);

  /**
   * @param handle allows the reactor to check if the caller is
   *        valid.
   *
   * @return 0 if the size of the current message has been put in
   *         size.  -1 if not.
   */
  virtual int current_info (ACE_HANDLE handle, size_t & /* size */);

  /// Use a user specified signal handler instead.
  virtual int set_sig_handler (ACE_Sig_Handler *signal_handler);

  /// Set a user-specified timer queue.
  virtual int timer_queue (ACE_Timer_Queue *tq);

  /// Get the timer queue
  /// @return The current @c ACE_Timer_Queue.
  virtual ACE_Timer_Queue *timer_queue (void) const;

  /// Close down and release all resources.
  virtual int close (void);

  // = Event loop drivers.
  /**
   * Returns non-zero if there are I/O events "ready" for dispatching,
   * but does not actually dispatch the event handlers.  By default,
   * don't block while checking this, i.e., "poll".
   *
   * @note It is only possible to achieve millisecond timeout
   *       resolutions with the @c ACE_Dev_Poll_Reactor.
   */
  virtual int work_pending (
    const ACE_Time_Value &max_wait_time = ACE_Time_Value::zero);

  /**
   * This event loop driver blocks for up to @a max_wait_time before
   * returning.  It will return earlier if events occur.  Note that
   * @a max_wait_time can be 0, in which case this method blocks
   * indefinitely until events occur.
   * @par
   * @a max_wait_time is decremented to reflect how much time this
   * call took.  For instance, if a time value of 3 seconds is passed
   * to @c handle_events() and an event occurs after 2 seconds,
   * @a max_wait_time will equal 1 second.  This can be used if an
   * application wishes to handle events for some fixed amount of
   * time.
   * @par
   * The only difference between @c alertable_handle_events() and
   * handle_events() is that in the alertable case, the event loop
   * will return when the system queues an I/O completion routine or
   * an Asynchronous Procedure Call.
   *
   * @return  The total number of @c ACE_Event_Handlers that were
   *          dispatched, 0 if the @a max_wait_time elapsed without
   *          dispatching any handlers, or -1 if an error occurs.

   * @note It is only possible to achieve millisecond timeout
   *       resolutions with the @c ACE_Dev_Poll_Reactor.
   */
  virtual int handle_events (ACE_Time_Value *max_wait_time = 0);
  virtual int alertable_handle_events (ACE_Time_Value *max_wait_time = 0);

  /**
   * This method is just like the one above, except the
   * @a max_wait_time value is a reference and can therefore never be
   * @c NULL.
   *
   * @note It is only possible to achieve millisecond timeout
   *       resolutions with the @c ACE_Dev_Poll_Reactor.
   */
  virtual int handle_events (ACE_Time_Value &max_wait_time);
  virtual int alertable_handle_events (ACE_Time_Value &max_wait_time);

  // = Event handling control.

  /**
   * @return The status of Reactor.  If this function returns 0, the
   *         reactor is actively handling events.  If it returns
   *         non-zero, @c handle_events() and
   *         @c handle_alertable_events() return -1 immediately.
   */
  virtual int deactivated (void);

  /**
   * Control whether the Reactor will handle any more incoming events
   * or not.  If @a do_stop == 1, the Reactor will be disabled.  By
   * default, a reactor is in active state and can be
   * deactivated/reactived as desired.
   */
  virtual void deactivate (int do_stop);

  // = Register and remove Handlers.

  /// Register @a event_handler with @a mask.  The I/O handle will
  /// always come from get_handle on the event_handler.
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);

  /// Register @a event_handler with @a mask.  The I/O handle is
  /// provided through the @a io_handle parameter.
  virtual int register_handler (ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);

  /**
   * Register an @a event_handler that will be notified when
   * @a event_handle is signaled.  @a mask specifies the network
   * events that the @a event_handler is interested in.
   */
  virtual int register_handler (ACE_HANDLE event_handle,
                                ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);

  /// Register @a event_handler with all the @a handles in the @c
  /// Handle_Set.
  virtual int register_handler (const ACE_Handle_Set &handles,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);

  /**
   * Register @a new_sh to handle the signal @a signum using the
   * @a new_disp.  Returns the @a old_sh that was previously
   * registered (if any), along with the @a old_disp of the signal
   * handler.
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

  /// Removes @a event_handler.
  /**
   * @note The I/O handle will be obtained using @c get_handle()
   *       method of @a event_handler .  If @a mask ==
   *       @c ACE_Event_Handler::DONT_CALL then the @c handle_close()
   *       method of the @a event_handler is not invoked.
   */
  virtual int remove_handler (ACE_Event_Handler *event_handler,
                              ACE_Reactor_Mask mask);

  /**
   * Removes @a handle.  If @a mask == ACE_Event_Handler::DONT_CALL
   * then the <handle_close> method of the associated <event_handler>
   * is not invoked.
   */
  virtual int remove_handler (ACE_HANDLE handle,
                              ACE_Reactor_Mask mask);

  /**
   * Removes all handles in @a handle_set.  If @a mask ==
   * ACE_Event_Handler::DONT_CALL then the <handle_close> method of
   * the associated <event_handler>s is not invoked.
   */
  virtual int remove_handler (const ACE_Handle_Set &handle_set,
                              ACE_Reactor_Mask mask);

  /**
   * Remove the ACE_Event_Handler currently associated with @a signum.
   * Install the new disposition (if given) and return the previous
   * disposition (if desired by the caller).  Returns 0 on success and
   * -1 if @a signum is invalid.
   */
  virtual int remove_handler (int signum,
                              ACE_Sig_Action *new_disp,
                              ACE_Sig_Action *old_disp = 0,
                              int sigkey = -1);

  /// Calls <remove_handler> for every signal in @a sigset.
  virtual int remove_handler (const ACE_Sig_Set &sigset);

  // = Suspend and resume Handlers.

  /// Suspend event_handler temporarily.  Use
  /// ACE_Event_Handler::get_handle() to get the handle.
  virtual int suspend_handler (ACE_Event_Handler *event_handler);

  /// Suspend handle temporarily.
  virtual int suspend_handler (ACE_HANDLE handle);

  /// Suspend all handles in handle set temporarily.
  virtual int suspend_handler (const ACE_Handle_Set &handles);

  /// Suspend all handles temporarily.
  virtual int suspend_handlers (void);

  /// Resume event_handler. Use ACE_Event_Handler::get_handle() to
  /// get the handle.
  virtual int resume_handler (ACE_Event_Handler *event_handler);

  /// Resume handle.
  virtual int resume_handler (ACE_HANDLE handle);

  /// Resume all handles in handle set.
  virtual int resume_handler (const ACE_Handle_Set &handles);

  /// Resume all handles.
  virtual int resume_handlers (void);

  /// Does the reactor allow the application to resume the handle on
  /// its own, i.e., can it pass on the control of handle resumption to
  /// the application.
  virtual int resumable_handler (void);

  /// Return true if we any event associations were made by the reactor
  /// for the handles that it waits on, false otherwise.
  virtual bool uses_event_associations (void);

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
   * @param arg   argument passed to the handle_timeout() method of
   *              event_handler.
   * @param delay  time interval after which the timer will expire.
   * @param interval  time interval for which the timer will be
   *                  automatically rescheduled.
   * @return -1 on failure, a timer_id value on success
   */
  virtual long schedule_timer (ACE_Event_Handler *event_handler,
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

  /// Cancel all Event_Handlers that match the address of
  /// @a event_handler.  Returns number of handlers cancelled.
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1);

  /**
   * Cancel the single event handler that matches the @a timer_id value
   * (which was returned from the schedule method).  If @a arg is
   * non-NULL then it will be set to point to the ``magic cookie''
   * argument passed in when the event handler was registered.  This
   * makes it possible to free up the memory and avoid memory leaks.
   * Returns 1 if cancellation succeeded and 0 if the @a timer_id
   * wasn't found.
   */
  virtual int cancel_timer (long timer_id,
                            const void **arg = 0,
                            int dont_call_handle_close = 1);

  // = High-level event handler scheduling operations

  /// Add @a masks_to_be_added to the @a event_handler's entry.
  /// @a event_handler must already have been registered.
  virtual int schedule_wakeup (ACE_Event_Handler *event_handler,
                               ACE_Reactor_Mask masks_to_be_added);

  /// Add @a masks_to_be_added to the @a handle's entry.  <event_handler>
  /// associated with @a handle must already have been registered.
  virtual int schedule_wakeup (ACE_HANDLE handle,
                               ACE_Reactor_Mask masks_to_be_added);

  /// Clear @a masks_to_be_cleared from the @a event_handler's entry.
  virtual int cancel_wakeup (ACE_Event_Handler *event_handler,
                             ACE_Reactor_Mask masks_to_be_cleared);

  /// Clear @a masks_to_be_cleared from the @a handle's entry.
  virtual int cancel_wakeup (ACE_HANDLE handle,
                             ACE_Reactor_Mask masks_to_be_cleared);

  // = Notification methods.

  /**
   * Notify @a event_handler of @a mask event.  The ACE_Time_Value
   * indicates how long to blocking trying to notify.  If @a timeout ==
   * 0, the caller will block until action is possible, else will wait
   * until the relative time specified in @a timeout elapses).
   */
  virtual int notify (ACE_Event_Handler *event_handler = 0,
                      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value * = 0);

  /**
   * Set the maximum number of times that ACE_Reactor_Impl will
   * iterate and dispatch the ACE_Event_Handlers that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."  Setting this
   * to a value like "1 or 2" will increase "fairness" (and thus
   * prevent starvation) at the expense of slightly higher dispatching
   * overhead.
   */
  virtual void max_notify_iterations (int);

  /**
   * Get the maximum number of times that the ACE_Reactor_Impl will
   * iterate and dispatch the ACE_Event_Handlers that are passed in
   * via the notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.
   */
  virtual int max_notify_iterations (void);

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. Returns the number of notifications
   * purged. Returns -1 on error.
   */
  virtual int purge_pending_notifications (ACE_Event_Handler * = 0,
                                           ACE_Reactor_Mask    = ACE_Event_Handler::ALL_EVENTS_MASK);

  /**
   * Return the Event_Handler associated with @a handle.  Return 0 if
   * @a handle is not registered.
   */
  virtual ACE_Event_Handler *find_handler (ACE_HANDLE handle);

  /**
   * Check to see if @a handle is associated with a valid Event_Handler
   * bound to @a mask.  Return the @a event_handler associated with this
   * @c handler if @a event_handler != 0.
   */
  virtual int handler (ACE_HANDLE handle,
                       ACE_Reactor_Mask mask,
                       ACE_Event_Handler **event_handler = 0);

  /**
   * Check to see if @a signum is associated with a valid Event_Handler
   * bound to a signal.  Return the @a event_handler associated with
   * this @c handler if @a event_handler != 0.
   */
  virtual int handler (int signum,
                       ACE_Event_Handler ** = 0);

  /// Returns true if Reactor has been successfully initialized, else
  /// false.
  virtual bool initialized (void);

  /// Returns the current size of the Reactor's internal descriptor
  /// table.
  virtual size_t size (void) const;

  /// Returns a reference to the Reactor's internal lock.
  virtual ACE_Lock &lock (void);

  /// Wake up all threads waiting in the event loop.
  virtual void wakeup_all_threads (void);

  /// Transfers ownership of Reactor_Impl to the @a new_owner.
  /**
   * @note There is no need to set the owner of the event loop for the
   *       ACE_Dev_Poll_Reactor.  Multiple threads may invoke the
   *       event loop simulataneously.  As such, this method is a
   *       no-op.
   */
  virtual int owner (ACE_thread_t new_owner, ACE_thread_t *old_owner = 0);

  /// Return the ID of the "owner" thread.
  /**
   * @note There is no need to set the owner of the event loop for the
   *       ACE_Dev_Poll_Reactor.  Multiple threads may invoke the
   *       event loop simultaneously.  As such, this method is a
   *       no-op.
   */
  virtual int owner (ACE_thread_t *owner);

  /// Get the existing restart value.
  virtual bool restart (void);

  /// Set a new value for restart and return the original value.
  /**
   * @param r If zero, then the event loop will not be automatically
   *          restarted if the underlying poll is interrupted via the
   *          INTR (interrupt) signal.
   *
   * @return Returns the previous "restart" value.
   */
  virtual bool restart (bool r);

  /// Set position of the owner thread.
  /**
   * @note This is currently a no-op.
   */
  virtual void requeue_position (int);

  /// Get position of the owner thread.
  /**
   * @note This is currently a no-op.
   */
  virtual int requeue_position (void);

  /**
   * @name Low-level wait_set mask manipulation methods
   *
   * Low-level methods to manipulate the event/reactor mask associated
   * with a handle and event handler when polling for events.
   * @par
   * The "interest set," i.e. the wait set, can be directly
   * manipulated with these methods.
   */
  //@{

  /// GET/SET/ADD/CLR the dispatch mask "bit" bound with the
  /// event_handler and mask.
  /**
   * @return Old mask on success, -1 on error.
   */
  virtual int mask_ops (ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask mask,
                        int ops);

  /// GET/SET/ADD/CLR the dispatch MASK "bit" bound with the handle
  /// and mask.
  /**
   * @return Old mask on success, -1 on error.
   */
  virtual int mask_ops (ACE_HANDLE handle,
                        ACE_Reactor_Mask mask,
                        int ops);

  //@}

  /**
   * @name Low-level ready_set mask manipulation methods
   *
   * These methods are unimplemented.
   */
  //@{

  /// GET/SET/ADD/CLR the ready "bit" bound with the event_handler
  /// and mask.
  virtual int ready_ops (ACE_Event_Handler *event_handler,
                         ACE_Reactor_Mask mask,
                         int ops);

  /// GET/SET/ADD/CLR the ready "bit" bound with the handle and mask.
  virtual int ready_ops (ACE_HANDLE handle,
                         ACE_Reactor_Mask,
                         int ops);

  //@}

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  class Token_Guard;

  /// Non-locking version of wait_pending().
  /**
   * Returns non-zero if there are I/O events "ready" for dispatching,
   * but does not actually dispatch the event handlers.  By default,
   * don't block while checking this, i.e., "poll".
   *
   * @note It is only possible to achieve millisecond timeout
   *       resolutions with the ACE_Dev_Poll_Reactor.
   */
  int work_pending_i (ACE_Time_Value *max_wait_time);

  /// Poll for events and return the number of event handlers that
  /// were dispatched.
  /**
   * This is a helper method called by all handle_events() methods.
   */
  int handle_events_i (ACE_Time_Value *max_wait_time, Token_Guard &guard);

  /// Perform the upcall with the given event handler method.
  int upcall (ACE_Event_Handler *event_handler,
              int (ACE_Event_Handler::*callback)(ACE_HANDLE),
              ACE_HANDLE handle);

  /**
   * Dispatch ACE_Event_Handlers for time events, I/O events, and
   * signal events.  Returns the total number of ACE_Event_Handlers
   * that were dispatched or -1 if something goes wrong.
   */
  int dispatch (Token_Guard &guard);

  /// Dispatch a single timer, if ready.
  /// Returns: 0 if no timers ready (token still held),
  ///          1 if a timer was expired (token released),
  ///         -1 on error (token still held).
  int dispatch_timer_handler (Token_Guard &guard);

  /// Dispatch an IO event to the corresponding event handler. Returns
  /// Returns: 0 if no events ready (token still held),
  ///          1 if an event was expired (token released),
  ///         -1 on error (token still held).
  int dispatch_io_event (Token_Guard &guard);

  /// Register the given event handler with the reactor.
  int register_handler_i (ACE_HANDLE handle,
                          ACE_Event_Handler *eh,
                          ACE_Reactor_Mask mask);

  /// Remove the event handler associated with the given handle and
  /// event mask from the "interest set." If @a eh is supplied, only
  /// do the remove if @eh matches the event handler that's registered
  /// for @a handle.
  int remove_handler_i (ACE_HANDLE handle,
                        ACE_Reactor_Mask mask,
                        ACE_Event_Handler *eh = 0);

  /// Temporarily remove the given handle from the "interest set."
  int suspend_handler_i (ACE_HANDLE handle);

  /// Place the given handle that was temporarily removed from the
  /// "interest set," i.e that was suspended, back in to the interest
  /// set.  The given handle will once again be polled for events.
  int resume_handler_i (ACE_HANDLE handle);

  /// GET/SET/ADD/CLR the dispatch MASK "bit" bound with the handle
  /// and mask.  This internal helper method acquires no lock.
  /**
   * @return Old mask on success, -1 on error.
   */
  int mask_ops_i (ACE_HANDLE handle,
                  ACE_Reactor_Mask mask,
                  int ops);

  /// Convert a reactor mask to its corresponding poll() event mask.
  short reactor_mask_to_poll_event (ACE_Reactor_Mask mask);

protected:

  /// Has the reactor been initialized.
  bool initialized_;

  /// The file descriptor associated with the open `/dev/poll' or
  /// `/dev/epoll' device.
  /**
   * All interactions with the `/dev/poll' or `/dev/epoll' device are
   * done through this file descriptor.
   */
  ACE_HANDLE poll_fd_;

#if defined (ACE_HAS_EVENT_POLL)
  /// Event structure to be filled by epoll_wait. epoll_wait() only gets
  /// one event at a time and we rely on it's internals for fairness.
  /// If this struct's fd is ACE_INVALID_HANDLE, the rest is indeterminate.
  /// If the fd is good, the event is one that's been retrieved by
  /// epoll_wait() but not yet processed.
  struct epoll_event event_;

  /// Event handlers that are suspended/resumed around upcalls are not
  /// immediately resumed; they're added to this list for resumption at
  /// the next epoll_wait() call. This avoids always needing to acquire the
  /// token just to resume a handler. Of course, if there are no other
  /// handlers in the to-be-resumed list and an epoll_wait is already in
  /// progress, the reactor needs to be notified to force another run around
  /// the epoll_wait() call.
  typedef ACE_Array_Map<ACE_HANDLE, ACE_Event_Handler *> Resume_Map;
  Resume_Map to_be_resumed_;
  volatile bool epoll_wait_in_progress_;
  ACE_SYNCH_MUTEX to_be_resumed_lock_;
#else
  /// The pollfd array that `/dev/poll' will feed its results to.
  struct pollfd *dp_fds_;


  /// Pointer to the next pollfd array element that contains the next
  /// event to be dispatched.
  struct pollfd *start_pfds_;

  /// The last element in the pollfd array plus one.
  /**
   * The loop that dispatches IO events stops when this->start_pfds ==
   * this->end_pfds_.
   */
  struct pollfd *end_pfds_;
#endif  /* ACE_HAS_EVENT_POLL */

  /// This flag is used to keep track of whether we are actively handling
  /// events or not.
  sig_atomic_t deactivated_;

  /// Lock used for synchronization of reactor state.
  ACE_Dev_Poll_Reactor_Token token_;

  /// Adapter used to return internal lock to outside world.
  ACE_Lock_Adapter<ACE_Dev_Poll_Reactor_Token> lock_adapter_;

  /// The repository that contains all registered event handlers.
  Handler_Repository handler_rep_;

  /// Defined as a pointer to allow overriding by derived classes...
  ACE_Timer_Queue *timer_queue_;

  /// Keeps track of whether we should delete the timer queue (if we
  /// didn't create it, then we don't delete it).
  bool delete_timer_queue_;

  /// Handle signals without requiring global/static variables.
  ACE_Sig_Handler *signal_handler_;

  /// Keeps track of whether we should delete the signal handler (if we
  /// didn't create it, then we don't delete it).
  bool delete_signal_handler_;

  /// Callback object that unblocks the <ACE_Select_Reactor> if it's
  /// sleeping.
  ACE_Reactor_Notify *notify_handler_;

  /// Keeps track of whether we need to delete the notify handler (if
  /// we didn't create it, then we don't delete it).
  bool delete_notify_handler_;

  /// Flag that determines if signals are masked during event
  /// dispatching.
  /**
   * If 0 then the Reactor will not mask the signals during the event
   * dispatching.  This is useful for applications that do not
   * register any signal handlers and want to reduce the overhead
   * introduce by the kernel level locks required to change the mask.
   */
  int mask_signals_;

  /// Restart the handle_events event loop method automatically when
  /// polling function in use (ioctl() in this case) is interrupted
  /// via an EINTR signal.
  bool restart_;

protected:

  /**
   * @class Token_Guard
   *
   * @brief A helper class that helps grabbing, releasing and waiting
   * on tokens for a thread that needs access to the reactor's token.
   */
  class ACE_Export Token_Guard
  {
  public:

    /// Constructor that will grab the token for us
    Token_Guard (ACE_Dev_Poll_Reactor_Token &token);

    /// Destructor. This will release the token if it hasn't been
    /// released till this point
    ~Token_Guard (void);

    /// Release the token ..
    void release_token (void);

    /// Returns whether the thread that created this object owns the
    /// token or not.
    int is_owner (void);

    /// A helper method that acquires the token 1) at a low priority, and
    /// 2) wait quietly for the token, not waking another thread. This
    /// is appropriate for cases where a thread wants to wait for and
    /// dispatch an event, not causing an existing waiter to relinquish the
    /// token, and also queuing up behind other threads waiting to modify
    /// event records.
    int acquire_quietly (ACE_Time_Value *max_wait = 0);

    /// A helper method that acquires the token at a high priority, and
    /// does wake the current token holder.
    int acquire (ACE_Time_Value *max_wait = 0);

  private:

    Token_Guard (void);

  private:

    /// The Reactor token.
    ACE_Dev_Poll_Reactor_Token &token_;

    /// Flag that indicate whether the thread that created this object
    /// owns the token or not. A value of 0 indicates that this class
    /// hasn't got the token (and hence the thread) and a value of 1
    /// vice-versa.
    int owner_;

  };

};


/**
 * @class ACE_Dev_Poll_Handler_Guard
 *
 * @brief Class used to make event handler reference count
 *        manipulation exception-safe.
 *
 * This class makes the reference count manipulation that occurs
 * during an upcall exception-safe.  Prior to dispatching the event
 * handler, the reference count is increased.  Once the upcall for the
 * given event handler is complete, its reference count will be decreased.
 */
class ACE_Dev_Poll_Handler_Guard
{
public:

  /// Constructor
  /**
   * The constructor checks to see if @a eh is a reference-counted handler and
   * remember that for later. If @a eh is reference counted, its reference
   * count is incremented unless @a do_incr is false.
   * @a do_incr should be false if the reference count was incremented
   * independently of this guard, for example, on a notify handler since
   * the reference count is incremented when the notify is queued.
   */
  ACE_Dev_Poll_Handler_Guard (ACE_Event_Handler *eh, bool do_incr = true);

  /// Destructor
  /**
   * The destructor decrements the reference count on the event
   * handler corresponding to the given handle.
   */
  ~ACE_Dev_Poll_Handler_Guard (void);

  /// Release the event handler from this guard; when the destructor is
  /// called, the handler's reference count will not be decremented.
  void release (void);

private:

  /// The event handler being managed.
  ACE_Event_Handler *eh_;

  /// true if eh_ is a reference-counted handler.
  bool refcounted_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "ace/Dev_Poll_Reactor.inl"
#endif /* __ACE_INLINE__ */

#endif  /* ACE_HAS_EVENT_POLL || ACE_HAS_DEV_POLL */

#include /**/ "ace/post.h"

#endif  /* ACE_DEV_POLL_REACTOR_H */
