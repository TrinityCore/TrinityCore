// -*- C++ -*-
//=============================================================================
/**
 *  @file    WFMO_Reactor.h
 *
 *  $Id: WFMO_Reactor.h 81138 2008-03-28 09:18:15Z johnnyw $
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_WFMO_REACTOR_H
#define ACE_WFMO_REACTOR_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#if defined (ACE_WIN32)
#include "ace/Signal.h"
#include "ace/Timer_Queue.h"
#include "ace/Event_Handler.h"
#include "ace/Auto_Event.h"
#include "ace/Manual_Event.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/Lock_Adapter_T.h"
#include "ace/Reactor_Impl.h"
#include "ace/Message_Queue.h"
#include "ace/Process_Mutex.h"
// If we don't have WinSOCK2, we need these defined
#if !defined (ACE_HAS_WINSOCK2) || (ACE_HAS_WINSOCK2 == 0)
/*
 * WinSock 2 extension -- bit values and indices for FD_XXX network events
 */
#define FD_READ_BIT      0
#define FD_WRITE_BIT     1
#define FD_OOB_BIT       2
#define FD_ACCEPT_BIT    3
#define FD_CONNECT_BIT   4
#define FD_CLOSE_BIT     5
#define FD_QOS_BIT       6
#define FD_GROUP_QOS_BIT 7
#define FD_QOS           (1 << FD_QOS_BIT)
#define FD_GROUP_QOS     (1 << FD_GROUP_QOS_BIT)
#define FD_MAX_EVENTS    8
#define FD_ALL_EVENTS    ((1 << FD_MAX_EVENTS) - 1)
#define WSAEVENT                HANDLE
typedef struct _WSANETWORKEVENTS
{
  long lNetworkEvents;
  int iErrorCode[FD_MAX_EVENTS];
} WSANETWORKEVENTS, FAR * LPWSANETWORKEVENTS;
int WSAEventSelect (SOCKET s,
                    WSAEVENT hEventObject,
                    long lNetworkEvents);
int WSAEnumNetworkEvents (SOCKET s,
                          WSAEVENT hEventObject,
                          LPWSANETWORKEVENTS lpNetworkEvents);
#endif /* !defined ACE_HAS_WINSOCK2 */
class ACE_WFMO_Reactor_Test;  // Must be out of versioned namespace.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Forward decl.
class ACE_WFMO_Reactor;
class ACE_Handle_Set;
/**
 * @class ACE_Wakeup_All_Threads_Handler
 *
 * @brief This is a helper class whose sole purpose is to handle events
 * on <ACE_WFMO_Reactor->wakeup_all_threads_>
 */
class ACE_Export ACE_Wakeup_All_Threads_Handler : public ACE_Event_Handler
{
public:
  /// Called when the <ACE_WFMO_Reactor->wakeup_all_threads_>
  virtual int handle_signal (int signum, siginfo_t * = 0, ucontext_t * = 0);
};
/**
 * @class ACE_WFMO_Reactor_Handler_Repository
 *
 * @internal This class is for internal ACE use only.
 *
 * @brief Used to map ACE_HANDLEs onto the appropriate
 * ACE_Event_Handler * and other information.
 */
class ACE_Export ACE_WFMO_Reactor_Handler_Repository
{
public:
  friend class ACE_WFMO_Reactor;
  friend class ACE_WFMO_Reactor_Test;
  /**
   * @class Common_Info
   *
   * @brief This struct contains the necessary information for every
   * <Event_Handler> entry. The reason the event is not in this
   * structure is because we need to pass an event array into
   * WaitForMultipleObjects and therefore keeping the events
   * seperate makes sense.
   */
  class Common_Info
  {
  public:
    /// This indicates whether this entry is for I/O or for a regular
    /// event
    bool io_entry_;
    /// The assosiated <Event_Handler>
    ACE_Event_Handler *event_handler_;
    /// The I/O handle related to the <Event_Handler>.  This entry is
    /// only valid if the <io_entry_> flag is true.
    ACE_HANDLE io_handle_;
    /**
     * This is the set of events that the <Event_Handler> is
     * interested in. This entry is only valid if the <io_entry_> flag
     * is true.
     */
    long network_events_;
    /**
     * This flag indicates that <WFMO_Reactor> created the event on
     * behalf of the user. Therefore we need to clean this up when the
     * <Event_Handler> removes itself from <WFMO_Reactor>.  This entry
     * is only valid if the <io_entry_> flag is true.
     */
    bool delete_event_;
    /// This is set when the entry needed to be deleted.
    bool delete_entry_;
    /**
     * These are the masks related to <handle_close> for the
     * <Event_Handler>.  This is only valid when <delete_entry_> is
     * set.
     */
    ACE_Reactor_Mask close_masks_;
    /// Constructor used for initializing the structure
    Common_Info (void);
    /// Reset the state of the structure
    void reset (void);
    /// Set the structure to these new values
    void set (bool io_entry,
              ACE_Event_Handler *event_handler,
              ACE_HANDLE io_handle,
              long network_events,
              bool delete_event,
              bool delete_entry,
              ACE_Reactor_Mask close_masks);
    /// Set the structure to these new values
    void set (Common_Info &common_info);
    /// Dump the state of an object.
    void dump (void) const;
  };
  /**
   * @class Current_Info
   *
   * @brief This structure inherits from the common structure to add
   * information for current entries.
   */
  class Current_Info : public Common_Info
  {
  public:
    /// This is set when the entry needed to be suspended.
    bool suspend_entry_;
    /// Default constructor
    Current_Info (void);
    /// Reset the state of the structure
    void reset (void);
    /// Set the structure to these new values
    void set (bool io_entry,
              ACE_Event_Handler *event_handler,
              ACE_HANDLE io_handle,
              long network_events,
              bool delete_event,
              bool delete_entry = false,
              ACE_Reactor_Mask close_masks = ACE_Event_Handler::NULL_MASK,
              bool suspend_entry = false);
    /// Set the structure to these new values
    void set (Common_Info &common_info,
              bool suspend_entry = false);
    /// Dump the state of an object.
    void dump (ACE_HANDLE event_handle) const;
  };
  /**
   * @class To_Be_Added_Info
   *
   * @brief This structure inherits from the common structure to add
   * information for <to_be_added> entries.
   */
  class To_Be_Added_Info : public Common_Info
  {
  public:
    /// Handle for the event
    ACE_HANDLE event_handle_;
    /// This is set when the entry needed to be suspended.
    bool suspend_entry_;
    /// Default constructor
    To_Be_Added_Info (void);
    /// Reset the state of the structure
    void reset (void);
    /// Set the structure to these new values
    void set (ACE_HANDLE event_handle,
              bool io_entry,
              ACE_Event_Handler *event_handler,
              ACE_HANDLE io_handle,
              long network_events,
              bool delete_event,
              bool delete_entry = false,
              ACE_Reactor_Mask close_masks = ACE_Event_Handler::NULL_MASK,
              bool suspend_entry = false);
    /// Set the structure to these new values
    void set (ACE_HANDLE event_handle,
              Common_Info &common_info,
              bool suspend_entry = false);
    /// Dump the state of an object.
    void dump (void) const;
  };
  /**
   * @class Suspended_Info
   *
   * @brief This structure inherits from the common structure to add
   * information for suspended entries.
   */
  class Suspended_Info : public Common_Info
  {
  public:
    /// Handle for the event
    ACE_HANDLE event_handle_;
    /// This is set when the entry needed to be resumed.
    bool resume_entry_;
    /// Constructor used for initializing the structure
    Suspended_Info (void);
    /// Reset the state of the structure
    void reset (void);
    /// Set the structure to these new values
    void set (ACE_HANDLE event_handle,
              bool io_entry,
              ACE_Event_Handler *event_handler,
              ACE_HANDLE io_handle,
              long network_events,
              bool delete_event,
              bool delete_entry = false,
              ACE_Reactor_Mask close_masks = 0,
              bool resume_entry = false);
    /// Set the structure to these new values
    void set (ACE_HANDLE event_handle,
              Common_Info &common_info,
              bool resume_entry = false);
    /// Dump the state of an object.
    void dump (void) const;
  };
  /// Constructor.
  ACE_WFMO_Reactor_Handler_Repository (ACE_WFMO_Reactor &wfmo_reactor);
  /// Destructor.
  virtual ~ACE_WFMO_Reactor_Handler_Repository (void);
  /// Initialize the repository of the approriate @a size.
  int open (size_t size);
  /// Close down the handler repository.
  int close (void);
  // = Search structure operations.
  /// Bind the <ACE_Event_Handler *> to the ACE_HANDLE. This is for
  /// the simple event entry.
  int bind (ACE_HANDLE, ACE_Event_Handler *);
  /// Insert I/O <Event_Handler> entry into the system. This method
  /// assumes that the lock are head *before* this method is invoked.
  int bind_i (bool io_entry,
              ACE_Event_Handler *event_handler,
              long network_events,
              ACE_HANDLE io_handle,
              ACE_HANDLE event_handle,
              bool delete_event);
  /// Remove the binding of ACE_HANDLE in accordance with the @a mask.
  int unbind (ACE_HANDLE,
              ACE_Reactor_Mask mask);
  /// Non-lock-grabbing version of <unbind>
  int unbind_i (ACE_HANDLE,
                ACE_Reactor_Mask mask,
                bool &changes_required);
  /// Remove all bindings of <ACE_HANDLE, ACE_Event_Handler> tuples.
  void unbind_all (void);
  // = Sanity checking.
  // Check the <handle> to make sure it's a valid ACE_HANDLE
  int invalid_handle (ACE_HANDLE handle) const;
  // = Accessors.
  /// Maximum ACE_HANDLE value, plus 1.
  DWORD max_handlep1 (void) const;
  /// Pointer to the beginning of the current array of ACE_HANDLE
  /// *'s.
  ACE_HANDLE *handles (void) const;
  /// Pointer to the beginning of the current array of
  /// ACE_Event_Handler *'s.
  Current_Info *current_info (void) const;
  /// Check if changes to the handle set are required.
  virtual bool changes_required (void);
  /// Make changes to the handle set
  virtual int make_changes (void);
  /// Check to see if @a slot has been scheduled for deletion
  int scheduled_for_deletion (size_t slot) const;
  /**
   * This method is used to calculate the network mask after a mask_op
   * request to <WFMO_Reactor>. Note that because the <Event_Handler>
   * may already be in the handler repository, we may have to find the
   * old event and the old network events
   */
  int modify_network_events_i (ACE_HANDLE io_handle,
                               ACE_Reactor_Mask new_masks,
                               ACE_Reactor_Mask &old_masks,
                               long &new_network_events,
                               ACE_HANDLE &event_handle,
                               bool &delete_event,
                               int operation);
  /// This method is used to change the network mask left (if any)
  /// after a remove request to <WFMO_Reactor>
  ACE_Reactor_Mask bit_ops (long &existing_masks,
                            ACE_Reactor_Mask to_be_removed_masks,
                            int operation);
  /// Temporarily suspend entry
  int suspend_handler_i (ACE_HANDLE handle,
                         bool &changes_required);
  /// Resume suspended entry
  int resume_handler_i (ACE_HANDLE handle,
                        bool &changes_required);
  /// Deletions and suspensions in current_info_
  int make_changes_in_current_infos (void);
  /// Deletions and resumptions in current_suspended_info_
  int make_changes_in_suspension_infos (void);
  /// Deletions in to_be_added_info_, or transfers to current_info_ or
  /// current_suspended_info_ from to_be_added_info_
  int make_changes_in_to_be_added_infos (void);
  /// Removes the ACE_Event_Handler at @a slot from the table.
  int remove_handler_i (size_t slot,
                        ACE_Reactor_Mask mask);
  /// Removes the ACE_Event_Handler at @a slot from the table.
  int remove_suspended_handler_i (size_t slot,
                                  ACE_Reactor_Mask mask);
  /// Removes the ACE_Event_Handler at @a slot from the table.
  int remove_to_be_added_handler_i (size_t slot,
                                    ACE_Reactor_Mask to_be_removed_masks);
  /**
   * Return the Event_Handler associated with <handle>.  Return 0 if
   * <handle> is not registered.
   */
  ACE_Event_Handler *find_handler (ACE_HANDLE handle);
  /**
   * Check to see if <handle> is associated with a valid Event_Handler
   * bound to @a mask.  Return the <event_handler> associated with this
   * @a handler if <event_handler> != 0.
   */
  int handler (ACE_HANDLE handle,
               ACE_Reactor_Mask mask,
               ACE_Event_Handler **event_handler = 0);
  /**
   * Check to see if <handle> is associated with a valid
   * Event_Handler. Return Event_Handler and associated masks.
   */
  ACE_Event_Handler *handler (ACE_HANDLE handle,
                              long &existing_masks);
  /// Dump the state of an object.
  void dump (void) const;
protected:
  /// Reference to our <WFMO_Reactor>.
  ACE_WFMO_Reactor &wfmo_reactor_;
  /// Maximum number of handles.
  size_t max_size_;
  /**
   * Array of <ACE_HANDLEs> passed to <WaitForMultipleObjects>.  This
   * is not part of the structure as the handle array needs to be
   * passed directly to <WaitForMultipleObjects>.
   */
  ACE_HANDLE *current_handles_;
  /// Array of current entries in the table
  Current_Info *current_info_;
  /// A count of the number of active handles.
  DWORD max_handlep1_;
  /// Information for entries to be added
  To_Be_Added_Info *to_be_added_info_;
  /// Number of records to be added
  size_t handles_to_be_added_;
  /// Currently suspended handles
  Suspended_Info *current_suspended_info_;
  /// Number of currently suspended handles
  size_t suspended_handles_;
  /// Number of records to be suspended
  size_t handles_to_be_suspended_;
  /// Number of records to be resumed
  size_t handles_to_be_resumed_;
  /// Number of records to be deleted
  size_t handles_to_be_deleted_;
};
/**
 * @class ACE_WFMO_Reactor_Notify
 *
 * @brief Unblock the <ACE_WFMO_Reactor> from its event loop, passing
 * it an optional ACE_Event_Handler to dispatch.
 *
 * This implementation is necessary for cases where the
 * <ACE_WFMO_Reactor> is run in a multi-threaded program.  In
 * this case, we need to be able to unblock
 * <WaitForMultipleObjects> when updates occur other than in the
 * main <ACE_WFMO_Reactor> thread.  To do this, we signal an
 * auto-reset event the <ACE_WFMO_Reactor> is listening on.  If
 * an ACE_Event_Handler and ACE_Reactor_Mask is passed to
 * <notify>, the appropriate <handle_*> method is dispatched.
 */
class ACE_Export ACE_WFMO_Reactor_Notify : public ACE_Reactor_Notify
{
public:
  /// Constructor
  ACE_WFMO_Reactor_Notify (size_t max_notifies = 1024);
  /// Initialization. <timer_queue> is stored to call <gettimeofday>.
  virtual int open (ACE_Reactor_Impl *wfmo_reactor,
                    ACE_Timer_Queue *timer_queue,
                    int disable_notify = 0);
  /// No-op.
  virtual int close (void);
  /**
   * Special trick to unblock <WaitForMultipleObjects> when updates
   * occur.  All we do is enqueue <event_handler> and @a mask onto the
   * ACE_Message_Queue and wakeup the <WFMO_Reactor> by signaling
   * its <ACE_Event> handle.  The ACE_Time_Value indicates how long
   * to blocking trying to notify the <WFMO_Reactor>.  If @a timeout ==
   * 0, the caller will block until action is possible, else will wait
   * until the relative time specified in @a timeout elapses).
   */
  virtual int notify (ACE_Event_Handler *event_handler = 0,
                      ACE_Reactor_Mask mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value *timeout = 0);
  /// No-op.
  virtual int dispatch_notifications (int &number_of_active_handles,
                                      ACE_Handle_Set &rd_mask);
  /// Returns a handle to the <ACE_Auto_Event>.
  virtual ACE_HANDLE get_handle (void) const;
  /// Returns the ACE_HANDLE of the notify pipe on which the reactor
  /// is listening for notifications so that other threads can unblock
  /// the <Reactor_Impl>
  virtual ACE_HANDLE notify_handle (void);
  /// Handle one of the notify call on the <handle>. This could be
  /// because of a thread trying to unblock the <Reactor_Impl>
  virtual int dispatch_notify (ACE_Notification_Buffer &buffer);
  /// Verify whether the buffer has dispatchable info or not.
  virtual int is_dispatchable (ACE_Notification_Buffer &buffer);
  /// Read one of the notify call on the <handle> into the
  /// <buffer>. This could be because of a thread trying to unblock
  /// the <Reactor_Impl>
  virtual int read_notify_pipe (ACE_HANDLE handle,
                                ACE_Notification_Buffer &buffer);
  /**
   * Set the maximum number of times that the
   * <ACE_WFMO_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."  Setting this
   * to a value like "1 or 2" will increase "fairness" (and thus
   * prevent starvation) at the expense of slightly higher dispatching
   * overhead.
   */
  void max_notify_iterations (int);
  /**
   * Get the maximum number of times that the
   * <ACE_WFMO_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.
   */
  int max_notify_iterations (void);
  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. If <eh> == 0, all notifications for all
   * handlers are removed (but not any notifications posted just to wake up
   * the reactor itself). Returns the number of notifications purged.
   * Returns -1 on error.
   */
  virtual int purge_pending_notifications (ACE_Event_Handler *,
                                           ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);
  /// Dump the state of an object.
  virtual void dump (void) const;
private:
  /// Pointer to the wfmo_reactor's timer queue.
  ACE_Timer_Queue *timer_queue_;
  /**
   * Called when the notification event waited on by
   * <ACE_WFMO_Reactor> is signaled.  This dequeues all pending
   * <ACE_Event_Handlers> and dispatches them.
   */
  virtual int handle_signal (int signum, siginfo_t * = 0, ucontext_t * = 0);
  /// An auto event is used so that we can <signal> it to wakeup one
  /// thread up (e.g., when the <notify> method is called).
  ACE_Auto_Event wakeup_one_thread_;
  /// Message queue that keeps track of pending <ACE_Event_Handlers>.
  /// This queue must be thread-safe because it can be called by
  /// multiple threads of control.
  ACE_Message_Queue<ACE_MT_SYNCH> message_queue_;
  /**
   * Keeps track of the maximum number of times that the
   * <ACE_WFMO_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."
   */
  int max_notify_iterations_;
};
/**
 * @class ACE_WFMO_Reactor
 *
 * @brief An object oriented event demultiplexor and event handler.
 * ACE_WFMO_Reactor is a Windows-only implementation of the ACE_Reactor
 * interface that uses the WaitForMultipleObjects() event demultiplexer.
 *
 * Like the other ACE Reactors, ACE_WFMO_Reactor can schedule timers.
 * It also reacts to signalable handles, such as events (see the documentation
 * for WaitForMultipleObjects() for a complete list of signalable handle
 * types). Therefore, I/O handles are not directly usable for registering
 * for input, output, and exception notification. The exception to this
 * is ACE_SOCK-based handles, which can be registered for input, output, and
 * exception notification just as with other platforms. See Chapter 4 in
 * C++NPv2 for complete details.
 *
 * Note that changes to the state of ACE_WFMO_Reactor are not
 * instantaneous.  Most changes (registration, removal,
 * suspension, and resumption of handles, and changes in
 * ownership) are made when the ACE_WFMO_Reactor reaches a stable
 * state.  Users should be careful, especially when removing
 * handlers.  This is because the ACE_WFMO_Reactor will call
 * handle_close() on the handler when it is finally removed and
 * not when remove_handler() is called.  If the registered handler's pointer
 * is not valid when ACE_WFMO_Reactor calls ACE_Event_Handler::handle_close(),
 * use the DONT_CALL flag with remove_handler(). Preferably, use dynamically
 * allocated event handlers and call "delete this" inside the handle_close()
 * hook method.
 *
 * Note that although multiple threads can concurrently run the
 * ACE_WFMO_Reactor event loop, the concept of the reactor "owner" is still
 * important. Only the owner thread can expire timers and wait on the
 * notifications handle. Thus, be careful to properly set the owner thread
 * when spawning threads to run the event loop while you are using timers
 * or notifications.
 */
class ACE_Export ACE_WFMO_Reactor : public ACE_Reactor_Impl
{
public:
  friend class ACE_WFMO_Reactor_Handler_Repository;
  friend class ACE_WFMO_Reactor_Test;
  enum
  {
    /// Default size of the WFMO_Reactor's handle table.
    /**
     * Two slots will be added to the @a size parameter in the
     * constructor and open methods which will store handles used for
     * internal management purposes.
     */
    DEFAULT_SIZE = MAXIMUM_WAIT_OBJECTS - 2
  };
  // = Initialization and termination methods.
  /// Initialize ACE_WFMO_Reactor with the default size.
  ACE_WFMO_Reactor (ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    ACE_Reactor_Notify * = 0);
  /**
   * Initialize ACE_WFMO_Reactor with the specified size.
   *
   * @param size  The maximum number of handles the reactor can
   *              register. The value should not exceed
   *              ACE_WFMO_Reactor::DEFAULT_SIZE. Two slots will be
   *              added to the @a size parameter which will store handles
   *              used for internal management purposes.
   */
  ACE_WFMO_Reactor (size_t size,
                    int unused = 0,
                    ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    ACE_Reactor_Notify * = 0);
  /**
   * Initialize ACE_WFMO_Reactor with the specified size.
   *
   * @param size  The maximum number of handles the reactor can
   *              register. The value should not exceed
   *              ACE_WFMO_Reactor::DEFAULT_SIZE. Two slots will be
   *              added to the @a size parameter which will store handles
   *              used for internal management purposes.
   */
  virtual int open (size_t size = ACE_WFMO_Reactor::DEFAULT_SIZE,
                    int restart = 0,
                    ACE_Sig_Handler * = 0,
                    ACE_Timer_Queue * = 0,
                    int disable_notify_pipe = 0,
                    ACE_Reactor_Notify * = 0);
  /// Returns -1 (not used in this implementation);
  virtual int current_info (ACE_HANDLE, size_t & /* size */);
  /// Use a user specified signal handler instead.
  virtual int set_sig_handler (ACE_Sig_Handler *signal_handler);
  /// Set a user-specified timer queue.
  virtual int timer_queue (ACE_Timer_Queue *tq);
  /// Return the current ACE_Timer_Queue.
  virtual ACE_Timer_Queue *timer_queue (void) const;
  /// Close down the ACE_WFMO_Reactor and release all of its resources.
  virtual int close (void);
  /// Close down the ACE_WFMO_Reactor and release all of its resources.
  virtual ~ACE_WFMO_Reactor (void);
  // = Event loop drivers.
  /**
   * This method is not currently implemented.  We recommend that you
   * use handle_events (ACE_Time_Value::zero) to get basically the
   * same effect, i.e., it won't block the caller if there are no events.
   */
  virtual int work_pending (const ACE_Time_Value &max_wait_time =  ACE_Time_Value::zero);
  /**
   * This event loop driver blocks for up to @a max_wait_time before
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
   * <WaitForMultipleObjects> is used as the demultiplexing call
   *
   * Returns the total number of I/O and timer ACE_Event_Handlers
   * that were dispatched, 0 if the @a max_wait_time elapsed without
   * dispatching any handlers, or -1 if an error occurs.
   *
   * The only difference between <alertable_handle_events> and
   * <handle_events> is that in the alertable case, TRUE is passed to
   * <WaitForMultipleObjects> for the <bAlertable> option.
   */
  virtual int handle_events (ACE_Time_Value *max_wait_time = 0);
  virtual int alertable_handle_events (ACE_Time_Value *max_wait_time = 0);
  /**
   * This method is just like the one above, except the
   * @a max_wait_time value is a reference and can therefore never be
   * NULL.
   *
   * The only difference between <alertable_handle_events> and
   * <handle_events> is that in the alertable case, TRUE is passed to
   * <WaitForMultipleObjects> for the <bAlertable> option.
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
   * If <do_stop> == 1, the Reactor will be disabled.  By default, a reactor
   * is in active state and can be deactivated/reactived as wish.
   */
  virtual void deactivate (int do_stop);
  // = Register and remove Handlers.
  /**
   * Register an ACE_Event_Handler <event_handler>.  Since no Event
   * Mask is passed through this interface, it is assumed that the
   * <handle> being passed in is an event handle and when the event
   * becomes signaled, <WFMO_Reactor> will call handle_signal on
   * <event_handler>.  If <handle> == <ACE_INVALID_HANDLE> the
   * <ACE_WFMO_Reactor> will call the <get_handle> method of
   * <event_handler> to extract the underlying event handle.
   */
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_HANDLE event_handle = ACE_INVALID_HANDLE);
  /**
   * Register an ACE_Event_Handler <event_handle>.  @a mask specifies
   * the network events that the <event_handler> is interested in.  If
   * <io_handle> == <ACE_INVALID_HANDLE> the <ACE_WFMO_Reactor> will
   * call the <get_handle> method of <event_handler> to extract the
   * underlying I/O handle. If the <event_handle> ==
   * <ACE_INVALID_HANDLE>, WFMO_Reactor will create an event for
   * associating it with the I/O handle. When the <event_handle> is
   * signalled, the appropriate <handle_*> callback will be invoked on
   * the <Event_Handler>
   */
  virtual int register_handler (ACE_HANDLE event_handle,
                                ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);
  /**
   * This is a simple version of the above <register_handler> method
   * where the I/O handle is passed in and the event handle will
   * always be created by <WFMO_Reactor>
   */
  virtual int register_handler (ACE_HANDLE io_handle,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);
  /**
   * This is a simple version of the above <register_handler> method
   * where the I/O handle will always come from <get_handle> on the
   * <Event_Handler> and the event handle will always be created by
   * <WFMO_Reactor>
   */
  virtual int register_handler (ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);
  /// Register <event_handler> with all the <handles> in the
  /// <Handle_Set>.
  virtual int register_handler (const ACE_Handle_Set &handles,
                                ACE_Event_Handler *event_handler,
                                ACE_Reactor_Mask mask);
  /**
   * Register <new_sh> to handle the signal @a signum using the
   * <new_disp>.  Returns the <old_sh> that was previously registered
   * (if any), along with the <old_disp> of the signal handler.
   */
  virtual int register_handler (int signum,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0,
                                ACE_Event_Handler **old_sh = 0,
                                ACE_Sig_Action *old_disp = 0);
  /// Registers <new_sh> to handle a set of signals <sigset> using the
  /// <new_disp>.
  virtual int register_handler (const ACE_Sig_Set &sigset,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0);
  /**
   * Removes <event_handler> from the <ACE_WFMO_Reactor>.  Note that
   * the <ACE_WFMO_Reactor> will call the <get_handle> method of
   * <event_handler> to extract the underlying handle.  If @a mask ==
   * ACE_Event_Handler::DONT_CALL then the <handle_close> method of
   * the <event_handler> is not invoked. Note that the <handle> can
   * either be the <event_handle> or the <io_handle>
   */
  virtual int remove_handler (ACE_Event_Handler *event_handler,
                              ACE_Reactor_Mask mask);
  /**
   * Removes <handle> from the <ACE_WFMO_Reactor>.  If @a mask ==
   * ACE_Event_Handler::DONT_CALL then the <handle_close> method of
   * the <event_handler> is not invoked. Note that the <handle> can
   * either be the <event_handle> or the <io_handle>
   *
   * For the case of I/O entries, this removes the @a mask binding of
   * <Event_Handler> whose handle is <handle> from <WFMO_Reactor>.  If
   * there are no more bindings for this <event_handler> then it is
   * removed from the WFMO_Reactor.  For simple event entries, mask is
   * mostly ignored and the <Event_Handler> is always removed from
   * <WFMO_Reactor>
   */
  virtual int remove_handler (ACE_HANDLE handle,
                              ACE_Reactor_Mask mask);
  /**
   * Removes all the @a mask bindings for handles in the <handle_set>
   * bind of <Event_Handler>.  If there are no more bindings for any
   * of these handles then they are removed from WFMO_Reactor.
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
  /// Suspend <event_handler> temporarily.  Use
  /// <ACE_Event_Handler::get_handle> to get the handle.
  virtual int suspend_handler (ACE_Event_Handler *event_handler);
  /// Suspend <handle> temporarily.
  virtual int suspend_handler (ACE_HANDLE handle);
  /// Suspend all <handles> in handle set temporarily.
  virtual int suspend_handler (const ACE_Handle_Set &handles);
  /// Suspend all <handles> temporarily.
  virtual int suspend_handlers (void);
  /// Resume <event_handler>. Use <ACE_Event_Handler::get_handle> to
  /// get the handle.
  virtual int resume_handler (ACE_Event_Handler *event_handler);
  /// Resume <handle>.
  virtual int resume_handler (ACE_HANDLE handle);
  /// Resume all <handles> in handle set.
  virtual int resume_handler (const ACE_Handle_Set &handles);
  /// Resume all <handles>.
  virtual int resume_handlers (void);
  /// Does the reactor allow the application to resume the handle on
  /// its own ie. can it pass on the control of handle resumption to
  /// the application. A positive value indicates that the handlers
  /// are application resumable. A value of 0 indicates otherwise.
  virtual int resumable_handler (void);
  /**
   * Return 1 if we any event associations were made by the reactor
   * for the handles that it waits on, 0 otherwise. Since the
   * WFMO_Reactor does use event associations, this function always
   * return 1.
   */
  virtual int uses_event_associations (void);
  // Timer management.
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
  /// <event_handler>.  Returns number of handler's cancelled.
  virtual int cancel_timer (ACE_Event_Handler *event_handler,
                            int dont_call_handle_close = 1);
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
                            int dont_call_handle_close = 1);
  // = High-level Event_Handler scheduling operations
  /**
   * Add @a masks_to_be_added to the <event_handler>'s entry in
   * WFMO_Reactor.  <event_handler> must already have been registered
   * with WFMO_Reactor.
   */
  virtual int schedule_wakeup (ACE_Event_Handler *event_handler,
                               ACE_Reactor_Mask masks_to_be_added);
  /**
   * Add @a masks_to_be_added to the @a handle's entry in WFMO_Reactor.
   * The Event_Handler associated with <handle> must already have been
   * registered with WFMO_Reactor.
   */
  virtual int schedule_wakeup (ACE_HANDLE handle,
                               ACE_Reactor_Mask masks_to_be_added);
  /**
   * Remove <masks_to_be_deleted> to the <handle>'s entry in
   * WFMO_Reactor.  The Event_Handler associated with <handle> must
   * already have been registered with WFMO_Reactor.
   */
  virtual int cancel_wakeup (ACE_Event_Handler *event_handler,
                             ACE_Reactor_Mask masks_to_be_deleted);
  /**
   * Remove <masks_to_be_deleted> to the <handle>'s entry in
   * WFMO_Reactor.  The Event_Handler associated with <handle> must
   * already have been registered with WFMO_Reactor.
   */
  virtual int cancel_wakeup (ACE_HANDLE handle,
                             ACE_Reactor_Mask masks_to_be_deleted);
  // = Notification methods.
  /**
   * Wakeup one <ACE_WFMO_Reactor> thread if it is currently blocked
   * in <WaitForMultipleObjects>.  The ACE_Time_Value indicates how
   * long to blocking trying to notify the <WFMO_Reactor>.  If
   * @a timeout == 0, the caller will block until action is possible,
   * else will wait until the relative time specified in @a timeout
   * elapses).
   */
  virtual int notify (ACE_Event_Handler * = 0,
                      ACE_Reactor_Mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value * = 0);
  /**
   * Set the maximum number of times that the
   * <ACE_WFMO_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify queue before breaking out of its
   * <ACE_Message_Queue::dequeue> loop.  By default, this is set to
   * -1, which means "iterate until the queue is empty."  Setting this
   * to a value like "1 or 2" will increase "fairness" (and thus
   * prevent starvation) at the expense of slightly higher dispatching
   * overhead.
   */
  virtual void max_notify_iterations (int);
  /**
   * Get the maximum number of times that the
   * <ACE_WFMO_Reactor_Notify::handle_input> method will iterate and
   * dispatch the <ACE_Event_Handlers> that are passed in via the
   * notify queue before breaking out of its
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
  // = Assorted helper methods.
  /**
   * Return the Event_Handler associated with <handle>.  Return 0 if
   * <handle> is not registered.
   */
  ACE_Event_Handler *find_handler (ACE_HANDLE handle);
  /**
   * Check to see if <handle> is associated with a valid Event_Handler
   * bound to @a mask.  Return the <event_handler> associated with this
   * @a handler if <event_handler> != 0.
   */
  virtual int handler (ACE_HANDLE handle,
                       ACE_Reactor_Mask mask,
                       ACE_Event_Handler **event_handler = 0);
  /**
   * Check to see if @a signum is associated with a valid Event_Handler
   * bound to a signal.  Return the <event_handler> associated with
   * this @a handler if <event_handler> != 0.
   */
  virtual int handler (int signum,
                       ACE_Event_Handler ** = 0);
  /// Returns true if WFMO_Reactor has been successfully initialized, else
  /// false.
  virtual bool initialized (void);
  /// Returns the current size of the WFMO_Reactor's internal
  /// descriptor table.
  virtual size_t size (void) const;
  /// Returns a reference to the WFMO_Reactor's internal lock.
  virtual ACE_Lock &lock (void);
  /// Wake up all threads in WaitForMultipleObjects so that they can
  /// reconsult the handle set
  virtual void wakeup_all_threads (void);
  /**
   * Transfers ownership of the WFMO_Reactor to the <new_owner>. The
   * transfer will not complete until all threads are ready (just like
   * the handle set).
   */
  virtual int owner (ACE_thread_t new_owner, ACE_thread_t *old_owner = 0);
  /// Return the ID of the "owner" thread.
  virtual int owner (ACE_thread_t *owner);
  /// Get the existing restart value.
  virtual int restart (void);
  /// Set a new value for restart and return the original value.
  virtual int restart (int r);
  /// Not implemented
  virtual void requeue_position (int);
  /// Not implemented
  virtual int requeue_position (void);
  // = Low-level wait_set mask manipulation methods.
  /**
   * Modify @a masks of the <event_handler>'s entry in WFMO_Reactor
   * depending upon <operation>.  <event_handler> must already have
   * been registered with WFMO_Reactor.
   */
  virtual int mask_ops (ACE_Event_Handler *event_handler,
                        ACE_Reactor_Mask masks,
                        int operation);
  /**
   * Modify @a masks of the <handle>'s entry in WFMO_Reactor depending
   * upon <operation>.  <handle> must already have been registered
   * with WFMO_Reactor.
   */
  virtual int mask_ops (ACE_HANDLE handle,
                        ACE_Reactor_Mask masks,
                        int ops);
  // = Low-level ready_set mask manipulation methods.
  /// Not implemented
  virtual int ready_ops (ACE_Event_Handler *event_handler,
                         ACE_Reactor_Mask mask,
                         int ops);
  /// Not implemented
  virtual int ready_ops (ACE_HANDLE handle,
                         ACE_Reactor_Mask,
                         int ops);
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  /// Dump the state of an object.
  virtual void dump (void) const;
protected:
  /// Registration workhorse
  virtual int register_handler_i (ACE_HANDLE event_handle,
                                  ACE_HANDLE io_handle,
                                  ACE_Event_Handler *event_handler,
                                  ACE_Reactor_Mask mask);
  /// Event handling workhorse
  virtual int event_handling (ACE_Time_Value *max_wait_time = 0,
                              int alertable = 0);
  /// Bit masking workhorse
  virtual int mask_ops_i (ACE_HANDLE io_handle,
                          ACE_Reactor_Mask masks,
                          int operation);
  /// Return the ID of the "owner" thread. Does not do any locking.
  virtual ACE_thread_t owner_i (void);
  /// Wait up to @a max_wait_time until it's ok to enter
  /// WaitForMultipleObjects. Returns 1 (and holding lock_) if ok to wait;
  /// -1 (and not holding lock_) if not.
  virtual int ok_to_wait (ACE_Time_Value *max_wait_time,
                          int alertable);
  /// Wait for timer and I/O events to occur.
  virtual DWORD wait_for_multiple_events (int timeout,
                                          int alertable);
  /// Check for activity on remaining handles.
  virtual DWORD poll_remaining_handles (DWORD slot);
  /// Expire timers. Only the owner thread does useful stuff in this
  /// function.
  virtual int expire_timers (void);
  /// Dispatches the timers and I/O handlers.
  virtual int dispatch (DWORD wait_status);
  /// Protect against structured exceptions caused by user code when
  /// dispatching handles
  virtual int safe_dispatch (DWORD wait_status);
  /**
   * Dispatches any active handles from handles_[@a slot] to
   * handles_[active_handles_] using <WaitForMultipleObjects> to poll
   * through our handle set looking for active handles.
   */
  virtual int dispatch_handles (DWORD slot);
  /// Dispatches a single handler. Returns 0 on success, -1 if the
  /// handler was removed.
  virtual int dispatch_handler (DWORD slot,
                                DWORD max_handlep1);
  /// Dispatches a single handler.  Returns 0 on success, -1 if the
  /// handler was removed.
  virtual int simple_dispatch_handler (DWORD slot,
                                       ACE_HANDLE event_handle);
  /// Dispatches a single handler. Returns 0 on success, -1 if the
  /// handler was removed.
  virtual int complex_dispatch_handler (DWORD slot,
                                        ACE_HANDLE event_handle);
  /// Dispatches window messages. Noop for WFMO_Reactor.
  virtual int dispatch_window_messages (void);
  virtual ACE_Reactor_Mask upcall (ACE_Event_Handler *event_handler,
                                   ACE_HANDLE io_handle,
                                   WSANETWORKEVENTS &events);
  /// Used to caluculate the next timeout
  virtual int calculate_timeout (ACE_Time_Value *time);
  /// Update the state of the handler repository
  virtual int update_state (void);
  /// Check to see if we have a new owner
  virtual int new_owner (void);
  /// Set owner to new owner
  virtual int change_owner (void);
  /// Handle signals without requiring global/static variables.
  ACE_Sig_Handler *signal_handler_;
  /// Keeps track of whether we should delete the signal handler (if we
  /// didn't create it, then we don't delete it).
  bool delete_signal_handler_;
  /// Defined as a pointer to allow overriding by derived classes...
  ACE_Timer_Queue *timer_queue_;
  /// Keeps track of whether we should delete the timer queue (if we
  /// didn't create it, then we don't delete it).
  bool delete_timer_queue_;
  /// Keeps track of whether we should delete the handler repository
  bool delete_handler_rep_;
  /// Used when <notify> is called.
  ACE_Reactor_Notify *notify_handler_;
  /// Keeps track of whether we should delete the notify handler.
  bool delete_notify_handler_;
  /**
   * Synchronization for the ACE_WFMO_Reactor.
   *
   * A Process Mutex is used here because of two reasons:
   * (a) The implementation of ACE_Thread_Mutex uses CriticalSections
   *     CriticalSections are not waitable using ::WaitForMultipleObjects
   * (b) This is really not a process mutex because it is not
   *     named. No other process can use this mutex.
   */
  ACE_Process_Mutex lock_;
  /// Adapter used to return internal lock to outside world.
  ACE_Lock_Adapter<ACE_Process_Mutex> lock_adapter_;
  /// Table that maps <ACE_HANDLEs> to <ACE_Event_Handler *>'s.
  ACE_WFMO_Reactor_Handler_Repository handler_rep_;
  /// A manual event used to block threads from proceeding into
  /// WaitForMultipleObjects
  ACE_Manual_Event ok_to_wait_;
  /**
   * A manual event is used so that we can wake everyone up (e.g.,
   * when <ACE_Event_Handlers> are bounded and unbound from the
   * handler repository).
   */
  ACE_Manual_Event wakeup_all_threads_;
  /// Used when <wakeup_all_threads_> is signaled
  ACE_Wakeup_All_Threads_Handler wakeup_all_threads_handler_;
  /// The changing thread waits on this event, till all threads are not
  /// active anymore
  ACE_Auto_Event waiting_to_change_state_;
  /// Count of currently active threads
  size_t active_threads_;
  /**
   * The thread which is "owner" of the WFMO_Reactor. The owner
   * concept is used because we don't want multiple threads to try to
   * expire timers. Therefore the "owner" thread is the only one
   * allowed to expire timers. Also, the owner thread is the only
   * thread which waits on the notify handle. Note that the ownership
   * can be transferred.
   */
  ACE_thread_t owner_;
  /// The owner to be of the WFMO_Reactor
  ACE_thread_t new_owner_;
  /// This is the thread which is responsible for the changing the
  /// state of the <WFMO_Reactor> handle set
  ACE_thread_t change_state_thread_;
  /// This is an array of ACE_HANDLEs which keep track of the <lock_>
  /// and <ok_to_wait_> handles
  ACE_HANDLE atomic_wait_array_ [2];
  /// This flag is used to keep track of whether we are already closed.
  bool open_for_business_;
  /// This flag is used to keep track of whether we are actively handling
  /// events or not.
  sig_atomic_t deactivated_;
private:
  /// Deny access since member-wise won't work...
  ACE_WFMO_Reactor (const ACE_WFMO_Reactor &);
  ACE_WFMO_Reactor &operator = (const ACE_WFMO_Reactor &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/WFMO_Reactor.inl"
#endif /* __ACE_INLINE__ */
#endif /* ACE_WIN32 */
#include /**/ "ace/post.h"
#endif /* ACE_WFMO_REACTOR_H */

