// -*- C++ -*-

//=============================================================================
/**
 *  @file    TP_Reactor.h
 *
 *  $Id: TP_Reactor.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  The ACE_TP_Reactor (aka, Thread Pool Reactor) uses the
 *  Leader/Followers pattern to demultiplex events among a pool of
 *  threads.  When using a thread pool reactor, an application
 *  pre-spawns a fixed number of threads.  When these threads
 *  invoke the ACE_TP_Reactor's handle_events() method, one thread
 *  will become the leader and wait for an event.  The other
 *  follower threads will queue up waiting for their turn to become
 *  the leader.  When an event occurs, the leader will pick a
 *  follower to become the leader and go on to handle the event.
 *  The consequence of using ACE_TP_Reactor is the amortization of
 *  the costs used to create threads.  The context switching cost
 *  will also reduce.  Moreover, the total resources used by
 *  threads are bounded because there are a fixed number of threads.
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Nanbor Wang <nanbor@cs.wustl.edu>
 */
//=============================================================================


#ifndef ACE_TP_REACTOR_H
#define ACE_TP_REACTOR_H

#include /**/ "ace/pre.h"

#include "ace/Select_Reactor.h"
#include "ace/Timer_Queue.h"    /* Simple forward decl won't work... */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_EH_Dispatch_Info
 *
 * @brief This structure contains information of the activated event
 * handler.
 */
class ACE_EH_Dispatch_Info
{
public:
  ACE_EH_Dispatch_Info (void);

  void set (ACE_HANDLE handle,
            ACE_Event_Handler *event_handler,
            ACE_Reactor_Mask mask,
            ACE_EH_PTMF callback);

  bool dispatch (void) const;

  ACE_HANDLE handle_;
  ACE_Event_Handler *event_handler_;
  ACE_Reactor_Mask mask_;
  ACE_EH_PTMF callback_;
  int resume_flag_;
  bool reference_counting_required_;

private:
  bool dispatch_;

  // Disallow copying and assignment.
  ACE_EH_Dispatch_Info (const ACE_EH_Dispatch_Info &);
  ACE_EH_Dispatch_Info &operator= (const ACE_EH_Dispatch_Info &);
};


/**
 * @class ACE_TP_Token_Guard
 *
 * @brief A helper class that helps grabbing, releasing and waiting
 * on tokens for a thread that tries calling handle_events ().
 *
 * In short, this class will be owned by one thread by creating on the
 * stack. This class gives the status of the ownership of the token
 * and manages the ownership
 */

class ACE_TP_Token_Guard
{
public:

  /// Constructor that will grab the token for us
  ACE_TP_Token_Guard (ACE_Select_Reactor_Token &token);

  /// Destructor. This will release the token if it hasnt been
  /// released till this point
  ~ACE_TP_Token_Guard (void);

  /// Release the token ..
  void release_token (void);

  /// Returns whether the thread that created this object ownes the
  /// token or not.
  bool is_owner (void);

  /// A helper method that grabs the token for us, after which the
  /// thread that owns that can do some actual work.
  int acquire_read_token (ACE_Time_Value *max_wait_time = 0);

  /**
   * A helper method that grabs the token for us, after which the
   * thread that owns that can do some actual work. This differs from
   * acquire_read_token() as it uses acquire () to get the token instead of
   * acquire_read ()
   */
  int acquire_token (ACE_Time_Value *max_wait_time = 0);

private:

  // Disallow default construction.
  ACE_TP_Token_Guard (void);

  // Disallow copying and assignment.
  ACE_TP_Token_Guard (const ACE_TP_Token_Guard &);
  ACE_TP_Token_Guard &operator= (const ACE_TP_Token_Guard &);

private:

  /// The Select Reactor token.
  ACE_Select_Reactor_Token &token_;

  /// Flag that indicate whether the thread that created this object
  /// owns the token or not. A value of false indicates that this class
  /// hasnt got the token (and hence the thread) and a value of true
  /// vice-versa.
  bool owner_;

};

/**
 * @class ACE_TP_Reactor
 *
 * @brief Specialization of ACE_Select_Reactor to support thread-pool
 * based event dispatching.
 *
 * One of the shortcomings of the ACE_Select_Reactor is that it
 * does not support a thread pool-based event dispatching model,
 * similar to the one in ACE_WFMO_Reactor.  In ACE_Select_Reactor, only
 * thread can call handle_events() at any given time. ACE_TP_Reactor
 * removes this short-coming.
 *
 * ACE_TP_Reactor is a specialization of ACE_Select_Reactor to support
 * thread pool-based event dispatching. This reactor takes advantage
 * of the fact that events reported by @c select() are persistent if not
 * acted upon immediately.  It works by remembering the event handler
 * which was just activated, suspending it for further I/O activities,
 * releasing the internal lock (so that another thread can start waiting
 * in the event loop) and then dispatching the event's handler outside the
 * scope of the reactor lock. After the event handler has been dispatched
 * the event handler is resumed for further I/O activity.
 *
 * This reactor implementation is best suited for situations when the
 * callbacks to event handlers can take arbitrarily long and/or a number
 * of threads are available to run the event loop. Note that I/O-processing
 * callback code in event handlers (e.g. handle_input()) does not have to
 * be modified or made thread-safe for this reactor.  This is because
 * before an I/O event is dispatched to an event handler, the handler is
 * suspended; it is resumed by the reactor after the upcall completes.
 * Therefore, multiple I/O events will not be made to one event handler
 * multiple threads simultaneously. This suspend/resume protection does not
 * apply to either timers scheduled with the reactor or to notifications
 * requested via the reactor. When using timers and/or notifications you
 * must provide proper protection for your class in the context of multiple
 * threads.
 */
class ACE_Export ACE_TP_Reactor : public ACE_Select_Reactor
{
public:

  /// Initialize ACE_TP_Reactor with the default size.
  ACE_TP_Reactor (ACE_Sig_Handler * = 0,
                  ACE_Timer_Queue * = 0,
                  bool mask_signals = true,
                  int s_queue = ACE_Select_Reactor_Token::FIFO);

  /**
   * Initialize the ACE_TP_Reactor to manage
   * @a max_number_of_handles.  If @a restart is non-0 then the
   * ACE_Reactor's @c handle_events() method will be restarted
   * automatically when @c EINTR occurs.  If @a sh or
   * @a tq are non-0 they are used as the signal handler and
   * timer queue, respectively.
   */
  ACE_TP_Reactor (size_t max_number_of_handles,
                  bool restart = false,
                  ACE_Sig_Handler *sh = 0,
                  ACE_Timer_Queue *tq = 0,
                  bool mask_signals = true,
                  int s_queue = ACE_Select_Reactor_Token::FIFO);

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
   * @return The total number of events that were dispatched; 0 if the
   * @a max_wait_time elapsed without dispatching any handlers, or -1
   * if an error occurs (check @c errno for more information).
   */
  virtual int handle_events (ACE_Time_Value *max_wait_time = 0);

  virtual int handle_events (ACE_Time_Value &max_wait_time);

  /// Does the reactor allow the application to resume the handle on
  /// its own ie. can it pass on the control of handle resumption to
  /// the application.  The TP reactor has can allow applications to
  /// resume handles.  So return a positive value.
  virtual int resumable_handler (void);

  /// Called from handle events
  static void no_op_sleep_hook (void *);

  /// The ACE_TP_Reactor implementation does not have a single owner thread.
  /// Attempts to set the owner explicitly are ignored. The reported owner
  /// thread is the current Leader in the pattern.
  virtual int owner (ACE_thread_t n_id, ACE_thread_t *o_id = 0);

  /// Return the thread ID of the current Leader.
  virtual int owner (ACE_thread_t *t_id);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = Internal methods that do the actual work.

  /// Template method from the base class.
  virtual void clear_dispatch_mask (ACE_HANDLE handle,
                                    ACE_Reactor_Mask mask);

  /// Dispatch just 1 signal, timer, notification handlers
  int dispatch_i (ACE_Time_Value *max_wait_time,
                  ACE_TP_Token_Guard &guard);

  /// Get the event that needs dispatching. It could be either a
  /// signal, timer, notification handlers or return possibly 1 I/O
  /// handler for dispatching. In the most common use case, this would
  /// return 1 I/O handler for dispatching
  int get_event_for_dispatching (ACE_Time_Value *max_wait_time);

#if 0
  // @Ciju
  // signal handling isn't in a production state yet.
  // Commenting it out for now.

  /// Method to handle signals
  /// @note It is just busted at this point in time.
  int handle_signals (int &event_count,
                      ACE_TP_Token_Guard &g);
#endif // #if 0

  /// Handle timer events
  int handle_timer_events (int &event_count,
                           ACE_TP_Token_Guard &g);

  /// Handle notify events
  int handle_notify_events (int &event_count,
                            ACE_TP_Token_Guard &g);

  /// handle socket events
  int handle_socket_events (int &event_count,
                            ACE_TP_Token_Guard &g);

  /// This method shouldn't get called.
  virtual void notify_handle (ACE_HANDLE handle,
                              ACE_Reactor_Mask mask,
                              ACE_Handle_Set &,
                              ACE_Event_Handler *eh,
                              ACE_EH_PTMF callback);
private:

  /// Get the handle of the notify pipe from the ready set if there is
  /// an event in the notify pipe.
  ACE_HANDLE get_notify_handle (void);

  /// Get socket event dispatch information.
  int get_socket_event_info (ACE_EH_Dispatch_Info &info);

  /// Notify the appropriate <callback> in the context of the <eh>
  /// associated with <handle> that a particular event has occurred.
  int dispatch_socket_event (ACE_EH_Dispatch_Info &dispatch_info);

  /// Clear the @a handle from the read_set
  void clear_handle_read_set (ACE_HANDLE handle);

  int post_process_socket_event (ACE_EH_Dispatch_Info &dispatch_info,int status);

private:
  /// Deny access since member-wise won't work...
  ACE_TP_Reactor (const ACE_TP_Reactor &);
  ACE_TP_Reactor &operator = (const ACE_TP_Reactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/TP_Reactor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_TP_REACTOR_H */
