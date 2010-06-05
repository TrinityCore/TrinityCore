// -*- C++ -*-

//=============================================================================
/**
 *  @file    Select_Reactor_Base.h
 *
 *  $Id: Select_Reactor_Base.h 82393 2008-07-23 10:52:34Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SELECT_REACTOR_BASE_H
#define ACE_SELECT_REACTOR_BASE_H

#include /**/ "ace/pre.h"

#include "ace/Timer_Queuefwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"
#include "ace/Handle_Set.h"
#include "ace/Pipe.h"
#include "ace/Reactor_Impl.h"

#if defined (ACE_HAS_REACTOR_NOTIFICATION_QUEUE)
# include "ace/Notification_Queue.h"
#endif /* ACE_HAS_REACTOR_NOTIFICATION_QUEUE */

#ifdef ACE_WIN32
# include "ace/Null_Mutex.h"
# include "ace/Hash_Map_Manager_T.h"
# include "ace/Functor.h"  /* For ACE_Hash<void *> */
# include <functional>      /* For std::equal_to<>  */
#else
# include "ace/Array_Base.h"
#endif  /* ACE_WIN32 */

#if !defined (ACE_DISABLE_NOTIFY_PIPE_DEFAULT)
# define ACE_DISABLE_NOTIFY_PIPE_DEFAULT 0
#endif /* ACE_DISABLE_NOTIFY_PIPE_DEFAULT */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Add useful typedefs to simplify the following code.
typedef void (ACE_Handle_Set::*ACE_FDS_PTMF) (ACE_HANDLE);
typedef int (ACE_Event_Handler::*ACE_EH_PTMF) (ACE_HANDLE);

// Forward declaration.
class ACE_Select_Reactor_Impl;
class ACE_Sig_Handler;

/*
 * Hook to specialize the Select_Reactor_Base implementation
 * with the concrete reactor, e.g., select or tp reactor
 * specified at build/compilation time.
 */
//@@ REACTOR_SPL_INCLUDE_FORWARD_DECL_ADD_HOOK

/**
 * @class ACE_Select_Reactor_Handle_Set
 *
 * @brief Track handles we are interested for various events.
 */
class ACE_Export ACE_Select_Reactor_Handle_Set
{
public:
  /// Read events (e.g., input pending, accept pending).
  ACE_Handle_Set rd_mask_;

  /// Write events (e.g., flow control abated, non-blocking connection
  /// complete).
  ACE_Handle_Set wr_mask_;

  /// Exception events (e.g., SIG_URG).
  ACE_Handle_Set ex_mask_;
};

/**
 * @class ACE_Event_Tuple
 *
 * @brief An ACE_Event_Handler and its associated ACE_HANDLE.
 *
 * One ACE_Event_Handler is registered for one or more
 * ACE_HANDLE.  At various points, this information must be
 * stored explicitly.  This class provides a lightweight
 * mechanism to do so.
 */
class ACE_Event_Tuple
{
public:

  /// Default constructor.
  ACE_Event_Tuple (void);

  /// Constructor.
  ACE_Event_Tuple (ACE_Event_Handler *eh, ACE_HANDLE h);

  /// Equality operator.
  bool operator== (const ACE_Event_Tuple &rhs) const;

  /// Inequality operator.
  bool operator!= (const ACE_Event_Tuple &rhs) const;

public:

  /// Handle.
  ACE_HANDLE handle_;

  /// ACE_Event_Handler associated with the ACE_HANDLE.
  ACE_Event_Handler *event_handler_;

};

/**
 * @class ACE_Select_Reactor_Notify
 *
 * @brief Unblock the ACE_Select_Reactor from its event loop.
 *
 * This implementation is necessary for cases where the
 * ACE_Select_Reactor is run in a multi-threaded program.  In
 * this case, we need to be able to unblock @c select or @c poll
 * when updates occur other than in the main
 * ACE_Select_Reactor thread.  To do this, we signal an
 * auto-reset event the ACE_Select_Reactor is listening on.
 * If an ACE_Event_Handler and ACE_Select_Reactor_Mask is
 * passed to @c notify, the appropriate @c handle_* method is
 * dispatched in the context of the ACE_Select_Reactor thread.
 */
class ACE_Export ACE_Select_Reactor_Notify : public ACE_Reactor_Notify
{
public:
  /// Constructor.
  ACE_Select_Reactor_Notify (void);

  /// Destructor.
  virtual ~ACE_Select_Reactor_Notify (void);

  // = Initialization and termination methods.
  /// Initialize.
  virtual int open (ACE_Reactor_Impl *,
                    ACE_Timer_Queue * = 0,
                    int disable_notify_pipe = ACE_DISABLE_NOTIFY_PIPE_DEFAULT);

  /// Destroy.
  virtual int close (void);

  /**
   * Called by a thread when it wants to unblock the
   * ACE_Select_Reactor.  This wakeups the ACE_Select_Reactor if
   * currently blocked in @c select/poll.  Pass over both the
   * @c Event_Handler *and* the @c mask to allow the caller to dictate
   * which @c Event_Handler method the ACE_Select_Reactor will
   * invoke.  The ACE_Time_Value indicates how long to blocking
   * trying to notify the ACE_Select_Reactor.  If @a timeout == 0,
   * the caller will block until action is possible, else will wait
   * until the relative time specified in @c *timeout elapses).
   */
  virtual int notify (ACE_Event_Handler * = 0,
                      ACE_Reactor_Mask = ACE_Event_Handler::EXCEPT_MASK,
                      ACE_Time_Value * timeout = 0);

  /// Handles pending threads (if any) that are waiting to unblock the
  /// ACE_Select_Reactor.
  virtual int dispatch_notifications (int &number_of_active_handles,
                                      ACE_Handle_Set &rd_mask);

  /// Returns the ACE_HANDLE of the notify pipe on which the reactor
  /// is listening for notifications so that other threads can unblock
  /// the Select_Reactor
  virtual ACE_HANDLE notify_handle (void);

  /// Handle one of the notify call on the @c handle. This could be
  /// because of a thread trying to unblock the Reactor_Impl
  virtual int dispatch_notify (ACE_Notification_Buffer &buffer);

  /// Read one of the notify call on the @a handle into the
  /// @a buffer. This could be because of a thread trying to unblock
  /// the Reactor_Impl
  virtual int read_notify_pipe (ACE_HANDLE handle,
                                ACE_Notification_Buffer &buffer);

  /// Verify whether the buffer has dispatchable info or not.
  virtual int is_dispatchable (ACE_Notification_Buffer &buffer);

  /// Called back by the ACE_Select_Reactor when a thread wants to
  /// unblock us.
  virtual int handle_input (ACE_HANDLE handle);

  /**
   * Set the maximum number of times that the
   * ACE_Select_Reactor_Notify::handle_input() method will iterate and
   * dispatch the ACE_Event_Handlers that are passed in via the
   * notify pipe before breaking out of its @c recv loop.  By default,
   * this is set to -1, which means "iterate until the pipe is empty."
   * Setting this to a value like "1 or 2" will increase "fairness"
   * (and thus prevent starvation) at the expense of slightly higher
   * dispatching overhead.
   */
  virtual void max_notify_iterations (int);

  /**
   * Get the maximum number of times that the
   * ACE_Select_Reactor_Notify::handle_input() method will iterate and
   * dispatch the ACE_Event_Handlers that are passed in via the
   * notify pipe before breaking out of its recv loop.
   */
  virtual int max_notify_iterations (void);

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. If @a eh == 0, all notifications for all
   * handlers are removed (but not any notifications posted just to wake up
   * the reactor itself). Returns the number of notifications purged.
   * Returns -1 on error.
   */
  virtual int purge_pending_notifications (
      ACE_Event_Handler *sh,
      ACE_Reactor_Mask mask = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /**
   * Keep a back pointer to the ACE_Select_Reactor.  If this value
   * if NULL then the ACE_Select_Reactor has been initialized with
   * disable_notify_pipe.
   */
  ACE_Select_Reactor_Impl *select_reactor_;

  /**
   * Contains the ACE_HANDLE the ACE_Select_Reactor is listening
   * on, as well as the ACE_HANDLE that threads wanting the
   * attention of the ACE_Select_Reactor will write to.
   */
  ACE_Pipe notification_pipe_;

  /**
   * Keeps track of the maximum number of times that the
   * ACE_Select_Reactor_Notify::handle_input() method will iterate and
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

/**
 * @class ACE_Select_Reactor_Handler_Repository
 *
 * @brief Used to map ACE_HANDLEs onto the appropriate
 * ACE_Event_Handler *.
 *
 * This class is necessary to shield differences between UNIX
 * and Win32.  In UNIX, ACE_HANDLE is an int, whereas in Win32
 * it's a void *.  This class hides all these details from the
 * bulk of the ACE_Select_Reactor code.  All of these methods
 * are called with the main <Select_Reactor> token lock held.
 */
class ACE_Export ACE_Select_Reactor_Handler_Repository
{
public:
  friend class ACE_Select_Reactor_Handler_Repository_Iterator;

  typedef ACE_HANDLE          key_type;
  typedef ACE_Event_Handler * value_type;

  // = The mapping from <HANDLES> to <Event_Handlers>.
#ifdef ACE_WIN32
  /**
   * The NT version implements this via a hash map
   * @c ACE_Event_Handler*.  Since NT implements @c ACE_HANDLE
   * as a void * we can't directly index into this array.  Therefore,
   * we must explicitly map @c ACE_HANDLE to @c ACE_Event_Handler.
   */
  typedef ACE_Hash_Map_Manager_Ex<key_type,
                                  value_type,
                                  ACE_Hash<key_type>,
                                  std::equal_to<key_type>,
                                  ACE_Null_Mutex> map_type;

  typedef map_type::size_type max_handlep1_type;
#else
  /**
   * The UNIX version implements this via a dynamically allocated
   * array of @c ACE_Event_Handler* that is indexed directly using
   * the @c ACE_HANDLE value.
   */
  typedef ACE_Array_Base<value_type> map_type;
  typedef ACE_HANDLE max_handlep1_type;
#endif  /* ACE_WIN32 */

  typedef map_type::size_type size_type;

  // = Initialization and termination methods.
  /// Default "do-nothing" constructor.
  ACE_Select_Reactor_Handler_Repository (ACE_Select_Reactor_Impl &);

  /// Initialize a repository of the appropriate @a size.
  /**
   * On Unix platforms, the size parameter should be as large as the
   * maximum number of file descriptors allowed for a given process.
   * This is necessary since a file descriptor is used to directly
   * index the array of event handlers maintained by the Reactor's
   * handler repository.  Direct indexing is used for efficiency
   * reasons.
   */
  int open (size_type size);

  /// Close down the repository.
  int close (void);

  // = Search structure operations.

  /**
   * Return the @c ACE_Event_Handler* associated with @c ACE_HANDLE.
   */
  ACE_Event_Handler * find (ACE_HANDLE handle);

  /// Bind the ACE_Event_Handler * to the ACE_HANDLE with the
  /// appropriate ACE_Reactor_Mask settings.
  int bind (ACE_HANDLE,
            ACE_Event_Handler *,
            ACE_Reactor_Mask);

  /// Remove the binding of ACE_HANDLE in accordance with the @a mask.
  int unbind (ACE_HANDLE,
              ACE_Reactor_Mask mask);

  /// Remove all the <ACE_HANDLE, ACE_Event_Handler> tuples.
  int unbind_all (void);

  // = Sanity checking.

  // Check the @a handle to make sure it's a valid @c ACE_HANDLE that
  // is within the range of legal handles (i.e., >= 0 && < max_size_).
  bool invalid_handle (ACE_HANDLE handle);

  // Check the @a handle to make sure it's a valid @c ACE_HANDLE that
  // within the range of currently registered handles (i.e., >= 0 && <
  // @c max_handlep1_).
  bool handle_in_range (ACE_HANDLE handle);

  // = Accessors.
  /// Returns the current table size.
  size_type size (void) const;

  /// Maximum ACE_HANDLE value, plus 1.
  max_handlep1_type max_handlep1 (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Remove the binding of @a handle corresponding to position @a pos
  /// in accordance with the @a mask.
  int unbind (ACE_HANDLE handle,
              map_type::iterator pos,
              ACE_Reactor_Mask mask);

  /**
   * @return @c iterator corresponding @c ACE_Event_Handler*
   *         associated with @c ACE_HANDLE.
   */
  map_type::iterator find_eh (ACE_HANDLE handle);

private:
  /// Reference to our @c Select_Reactor.
  ACE_Select_Reactor_Impl &select_reactor_;

#ifndef ACE_WIN32
  /// The highest currently active handle, plus 1 (ranges between 0 and
  /// @c max_size_.
  max_handlep1_type max_handlep1_;
#endif  /* !ACE_WIN32 */

  /// Underlying table of event handlers.
  map_type event_handlers_;
};

/**
 * @class ACE_Select_Reactor_Handler_Repository_Iterator
 *
 * @brief Iterate through the ACE_Select_Reactor_Handler_Repository.
 */
class ACE_Export ACE_Select_Reactor_Handler_Repository_Iterator
{
public:

  typedef
    ACE_Select_Reactor_Handler_Repository::map_type::const_iterator const_base_iterator;

  // = Initialization method.
  explicit ACE_Select_Reactor_Handler_Repository_Iterator (
    ACE_Select_Reactor_Handler_Repository const * s);

  // = Iteration methods.

  /// Pass back the @a next_item that hasn't been seen in the Set.
  /// Returns @c false when all items have been seen, else @c true.
  bool next (ACE_Event_Handler* & next_item);

  /// Returns @c true when all items have been seen, else @c false.
  bool done (void) const;

  /// Move forward by one element in the set.  Returns @c false when
  /// all the items in the set have been seen, else @c true.
  bool advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  /// Reference to the Handler_Repository we are iterating over.
  ACE_Select_Reactor_Handler_Repository const * const rep_;

  /// Pointer to the current iteration level.
  const_base_iterator current_;
};

/**
 * @class ACE_Select_Reactor_Impl
 *
 * @brief This class simply defines how Select_Reactor's basic interface
 * functions should look like and provides a common base class for
 * @c Select_Reactor using various locking mechanism.
 */
class ACE_Export ACE_Select_Reactor_Impl : public ACE_Reactor_Impl
{
public:
  enum
  {
    /// Default size of the Select_Reactor's handle table.
    DEFAULT_SIZE = ACE_DEFAULT_SELECT_REACTOR_SIZE
  };

  /// Constructor.
  ACE_Select_Reactor_Impl (bool mask_signals = true);

  friend class ACE_Select_Reactor_Notify;
  friend class ACE_Select_Reactor_Handler_Repository;

  /**
   * Purge any notifications pending in this reactor for the specified
   * ACE_Event_Handler object. Returns the number of notifications
   * purged. Returns -1 on error.
   */
  virtual int purge_pending_notifications (ACE_Event_Handler * = 0,
                                           ACE_Reactor_Mask    = ACE_Event_Handler::ALL_EVENTS_MASK);

  /// Does the reactor allow the application to resume the handle on
  /// its own ie. can it pass on the control of handle resumption to
  /// the application.  The select reactor has no handlers that can be
  /// resumed by the  application. So return 0;
  virtual int resumable_handler (void);

  /*
   * Hook to add concrete methods required to specialize the
   * implementation with concrete methods required for the concrete
   * reactor implementation, for example, select, tp reactors.
   */
  //@@ REACTOR_SPL_PUBLIC_METHODS_ADD_HOOK

protected:
  /// Allow manipulation of the <wait_set_> mask and <ready_set_> mask.
  virtual int bit_ops (ACE_HANDLE handle,
                       ACE_Reactor_Mask mask,
                       ACE_Select_Reactor_Handle_Set &handle_set,
                       int ops);

  /// Enqueue ourselves into the list of waiting threads at the
  /// appropriate point specified by <requeue_position_>.
  virtual void renew (void) = 0;

  /// Check to see if the <Event_Handler> associated with @a handle is
  /// suspended. Returns 0 if not, 1 if so.
  virtual int is_suspended_i (ACE_HANDLE handle) = 0;

  /// When register/unregister occur, then we need to re-eval our
  /// wait/suspend/dispatch set.
  virtual void clear_dispatch_mask (ACE_HANDLE handle,
                                    ACE_Reactor_Mask mask);

  /// Table that maps <ACE_HANDLEs> to <ACE_Event_Handler *>'s.
  ACE_Select_Reactor_Handler_Repository handler_rep_;

  /// Tracks handles that are ready for dispatch from <select>
  ACE_Select_Reactor_Handle_Set dispatch_set_;

  /// Tracks handles that are waited for by <select>.
  ACE_Select_Reactor_Handle_Set wait_set_;

  /// Tracks handles that are currently suspended.
  ACE_Select_Reactor_Handle_Set suspend_set_;

  /// Track HANDLES we are interested in for various events that must
  /// be dispatched *without* going through <select>.
  ACE_Select_Reactor_Handle_Set ready_set_;

  /// Defined as a pointer to allow overriding by derived classes...
  ACE_Timer_Queue *timer_queue_;

  /// Handle signals without requiring global/static variables.
  ACE_Sig_Handler *signal_handler_;

  /// Callback object that unblocks the ACE_Select_Reactor if it's
  /// sleeping.
  ACE_Reactor_Notify *notify_handler_;

  /// Keeps track of whether we should delete the timer queue (if we
  /// didn't create it, then we don't delete it).
  bool delete_timer_queue_;

  /// Keeps track of whether we should delete the signal handler (if we
  /// didn't create it, then we don't delete it).
  bool delete_signal_handler_;

  /// Keeps track of whether we need to delete the notify handler (if
  /// we didn't create it, then we don't delete it).
  bool delete_notify_handler_;

  /// True if we've been initialized yet...
  bool initialized_;

  /// Restart the <handle_events> event-loop method automatically when
  /// <select> is interrupted via <EINTR>.
  int restart_;

  /**
   * Position that the main ACE_Select_Reactor thread is requeued in
   * the list of waiters during a <notify> callback.  If this value ==
   * -1 we are requeued at the end of the list.  Else if it's 0 then
   * we are requeued at the front of the list.  Else if it's > 1 then
   * that indicates the number of waiters to skip over.
   */
  int requeue_position_;

  /// The original thread that created this Select_Reactor.
  ACE_thread_t owner_;

  /**
   * True if state has changed during dispatching of
   * <ACE_Event_Handlers>, else false.  This is used to determine
   * whether we need to make another trip through the
   * <Select_Reactor>'s <wait_for_multiple_events> loop.
   */
  bool state_changed_;

  /**
   * If false then the Reactor will not mask the signals during the event
   * dispatching.  This is useful for applications that do not
   * register any signal handlers and want to reduce the overhead
   * introduce by the kernel level locks required to change the mask.
   */
  bool mask_signals_;

  /// Controls/access whether the notify handler should renew the
  /// Select_Reactor's token or not.
  int supress_notify_renew (void);
  void supress_notify_renew (int sr);

private:

  /// Determine whether we should renew Select_Reactor's token after handling
  /// the notification message.
  int supress_renew_;

  /// Deny access since member-wise won't work...
  ACE_Select_Reactor_Impl (const ACE_Select_Reactor_Impl &);
  ACE_Select_Reactor_Impl &operator = (const ACE_Select_Reactor_Impl &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Select_Reactor_Base.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_SELECT_REACTOR_BASE_H */

