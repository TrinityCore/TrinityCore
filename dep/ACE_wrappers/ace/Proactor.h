// -*- C++ -*-

//=============================================================================
/**
 *  @file    Proactor.h
 *
 *  $Id: Proactor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *  @author Alexander Babu Arulanthu <alex@cs.wustl.edu>
 *  @author Alexander Libman <alibman@ihug.com.au>
 */
//=============================================================================

#ifndef ACE_PROACTOR_H
#define ACE_PROACTOR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO) || defined (ACE_HAS_AIO_CALLS)
// This only works on Win32 platforms and on Unix platforms supporting
// POSIX aio calls.

#  include "ace/Asynch_IO.h"
#  include "ace/Asynch_IO_Impl.h"
#  include "ace/Thread_Manager.h"
#  include "ace/Timer_Queue.h"
#  include "ace/Timer_List.h"
#  include "ace/Timer_Heap.h"
#  include "ace/Timer_Wheel.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations.
class ACE_Proactor_Impl;
class ACE_Proactor_Timer_Handler;

/**
 * @class ACE_Proactor_Handle_Timeout_Upcall
 *
 * @brief Functor for ACE_Timer_Queue.
 *
 * This class implements the functor required by the Timer
 * Queue to call <handle_timeout> on ACE_Handlers.
 */
class ACE_Proactor_Handle_Timeout_Upcall
{

  /// Type def for the timer queue.
  typedef ACE_Timer_Queue_T<ACE_Handler *,
                            ACE_Proactor_Handle_Timeout_Upcall,
                            ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_QUEUE;

  /// The main Proactor class has special permissions.
  friend class ACE_Proactor;

public:
  /// Constructor.
  ACE_Proactor_Handle_Timeout_Upcall (void);

  /// This method is called when a timer is registered.
  int registration (TIMER_QUEUE &timer_queue,
                    ACE_Handler *handler,
                    const void *arg);

  /// This method is called before the timer expires.
  int preinvoke (TIMER_QUEUE &timer_queue,
                 ACE_Handler *handler,
                 const void *arg,
                 int recurring_timer,
                 const ACE_Time_Value &cur_time,
                 const void *&upcall_act);

  /// This method is called when the timer expires.
  int timeout (TIMER_QUEUE &timer_queue,
               ACE_Handler *handler,
               const void *arg,
               int recurring_timer,
               const ACE_Time_Value &cur_time);

  /// This method is called after the timer expires.
  int postinvoke (TIMER_QUEUE &timer_queue,
                  ACE_Handler *handler,
                  const void *arg,
                  int recurring_timer,
                  const ACE_Time_Value &cur_time,
                  const void *upcall_act);

  /// This method is called when a handler is canceled.
  int cancel_type (TIMER_QUEUE &timer_queue,
                   ACE_Handler *handler,
                   int dont_call_handle_close,
                   int &requires_reference_counting);

  /// This method is called when a timer is canceled.
  int cancel_timer (TIMER_QUEUE &timer_queue,
                    ACE_Handler *handler,
                    int dont_call_handle_close,
                    int requires_reference_counting);

  /// This method is called when the timer queue is destroyed and the
  /// timer is still contained in it.
  int deletion (TIMER_QUEUE &timer_queue,
                ACE_Handler *handler,
                const void *arg);

protected:
  /// Set the proactor. This will fail, if one is already set!
  int proactor (ACE_Proactor &proactor);

  /// Handle to the proactor. This is needed for posting a timer result
  /// to the Proactor's completion queue.
  ACE_Proactor *proactor_;
};

/**
 * @class ACE_Proactor
 *
 * @brief A manager for asynchronous event demultiplexing.
 *
 * See the Proactor pattern description at
 * http://www.cs.wustl.edu/~schmidt/proactor.ps.gz for more
 * details.
 */
class ACE_Export ACE_Proactor
{
  // = Here are the private typedefs that the ACE_Proactor uses.

  typedef ACE_Timer_Queue_Iterator_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_QUEUE_ITERATOR;
  typedef ACE_Timer_List_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_LIST;
  typedef ACE_Timer_List_Iterator_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_LIST_ITERATOR;
  typedef ACE_Timer_Heap_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_HEAP;
  typedef ACE_Timer_Heap_Iterator_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_HEAP_ITERATOR;
  typedef ACE_Timer_Wheel_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_WHEEL;
  typedef ACE_Timer_Wheel_Iterator_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_WHEEL_ITERATOR;

  // = Friendship.

  /// Timer handler runs a thread and manages the timers, on behalf of
  /// the Proactor.
  friend class ACE_Proactor_Timer_Handler;

public:
  /// Public type.
  typedef ACE_Timer_Queue_T<ACE_Handler *,
    ACE_Proactor_Handle_Timeout_Upcall,
    ACE_SYNCH_RECURSIVE_MUTEX>
  TIMER_QUEUE;

  /**
   * Constructor. If @a implementation is 0, the correct implementation
   * object will be created. @a delete_implementation flag determines
   * whether the implementation object should be deleted by the
   * Proactor or not. If @a tq is 0, a new TIMER_QUEUE is created.
   */
  ACE_Proactor (ACE_Proactor_Impl *implementation = 0,
                bool delete_implementation = false,
                TIMER_QUEUE *tq = 0);

  /// Destruction.
  ~ACE_Proactor (void);

  /// Get pointer to a process-wide ACE_Proactor.  @a threads should
  /// be part of another method.
  static ACE_Proactor *instance (size_t threads = 0);

  /// Set pointer to a process-wide ACE_Proactor and return existing
  /// pointer.
  static ACE_Proactor *instance (ACE_Proactor * proactor,
                                 bool delete_proactor = false);

  /// Delete the dynamically allocated Singleton.
  static void close_singleton (void);

  /// Cleanup method, used by the ACE_Object_Manager to destroy the
  /// singleton.
  static void cleanup (void *instance, void *arg);

  /// Name of dll in which the singleton instance lives.
  static const ACE_TCHAR *dll_name (void);

  /// Name of component--ACE_Proactor in this case.
  static const ACE_TCHAR *name (void);

  // = Proactor event loop management methods.

  /// Run the event loop until the <ACE_Proactor::handle_events> method
  /// returns -1 or the <end_event_loop> method is invoked.
  static int run_event_loop (void);

  /**
   * Run the event loop until the <ACE_Proactor::handle_events> method
   * returns -1, the <end_event_loop> method is invoked, or the
   * ACE_Time_Value expires, in which case 0 is returned.
   */
  static int run_event_loop (ACE_Time_Value &tv);

  /**
   * Instruct the <ACE_Proactor::instance> to terminate its event
   * loop.
   * This method wakes up all the threads blocked on waiting for
   * completions and end the event loop.
   */
  static int end_event_loop (void);

  /**
   * Resets the <ACE_Proactor::end_event_loop_> static so that the
   * <run_event_loop> method can be restarted.
   */
  static int reset_event_loop (void);

  /**
   * The singleton proactor is used by the ACE_Service_Config.
   * Therefore, we must check for the reconfiguration request and
   * handle it after handling an event.
   */
  static int check_reconfiguration (ACE_Proactor *);

  /// Report if the <ACE_Proactor::instance> event loop is finished.
  static int event_loop_done (void);

  /// Close the associated @c ACE_Proactor_Impl implementation object.
  /**
   * If @arg delete_implementation was specified to the @c open() method,
   * the implementation object is also deleted.
   */
  int close (void);

   /**
   * You can add a hook to various run_event methods and the hook will
   * be called after handling every proactor event.  If this function
   * returns 0, proactor_run_event_loop will check for the return value of
   * handle_events.  If it is -1, the the proactor_run_event_loop will return
   * (pre-maturely.)
   */
  typedef int (*PROACTOR_EVENT_HOOK)(ACE_Proactor *);

  // These methods work with an instance of a proactor.
  /**
   * Run the event loop until the
   * <ACE_Proactor::handle_events>
   * method returns -1 or the <end_proactor_event_loop> method is invoked.
   */
  int proactor_run_event_loop (PROACTOR_EVENT_HOOK = 0);

  /**
   * Run the event loop until the <ACE_Proactor::handle_events>
   * method returns -1, the
   * <end_proactor_event_loop> method is invoked,
   * or the ACE_Time_Value
   * expires, in which case a 0 is returned.
   */
  int proactor_run_event_loop (ACE_Time_Value &tv,
                               PROACTOR_EVENT_HOOK = 0);

  /**
   * Instruct the ACE_Proactor to terminate its event loop
   * and notifies the ACE_Proactor so that it can wake up
   * and close down gracefully.
   */
  int proactor_end_event_loop (void);

  /// Report if the ACE_Proactor event loop is finished.
  int proactor_event_loop_done (void);

  /// Resets the <ACE_Proactor::end_event_loop_> static so that the
  /// <run_event_loop> method can be restarted.
  int proactor_reset_event_loop (void);

  /// This method adds the @a handle to the I/O completion port. This
  /// function is a no-op function for Unix systems and returns 0;
  int register_handle (ACE_HANDLE handle,
                       const void *completion_key);

  // = Timer management.
  /**
   * Schedule a @a handler that will expire after <time>.  If it
   * expires then @a act is passed in as the value to the @a handler's
   * <handle_timeout> callback method.  This method returns a
   * <timer_id>. This <timer_id> can be used to cancel a timer before
   * it expires.  The cancellation ensures that <timer_ids> are unique
   * up to values of greater than 2 billion timers.  As long as timers
   * don't stay around longer than this there should be no problems
   * with accidentally deleting the wrong timer.  Returns -1 on
   * failure (which is guaranteed never to be a valid <timer_id>).
   */
  long schedule_timer (ACE_Handler &handler,
                       const void *act,
                       const ACE_Time_Value &time);

  long schedule_repeating_timer (ACE_Handler &handler,
                                 const void *act,
                                 const ACE_Time_Value &interval);

  // Same as above except @a interval it is used to reschedule the
  // @a handler automatically.

  /// This combines the above two methods into one. Mostly for backward
  /// compatibility.
  long schedule_timer (ACE_Handler &handler,
                       const void *act,
                       const ACE_Time_Value &time,
                       const ACE_Time_Value &interval);

  /// Cancel all timers associated with this @a handler.  Returns number
  /// of timers cancelled.
  int cancel_timer (ACE_Handler &handler,
                    int dont_call_handle_close = 1);

  /**
   * Cancel the single <ACE_Handler> that matches the @a timer_id value
   * (which was returned from the <schedule> method).  If @a act is
   * non-NULL then it will be set to point to the ``magic cookie''
   * argument passed in when the <Handler> was registered.  This makes
   * it possible to free up the memory and avoid memory leaks.
   * Returns 1 if cancellation succeeded and 0 if the @a timer_id
   * wasn't found.
   */
  int cancel_timer (long timer_id,
                    const void **act = 0,
                    int dont_call_handle_close = 1);

  /**
   * Dispatch a single set of events, waiting up to a specified time limit
   * if necessary.
   * @param wait_time the time to wait for an event to occur. This is
   * a relative time. On successful return, the time is updated to
   * reflect the amount of time spent waiting for event(s) to occur.
   * @return Returns 0 if no events occur before the wait_time expires.
   * Returns 1 when a completion is dispatched. On error, returns -1
   * and sets errno accordingly.
   */
  int handle_events (ACE_Time_Value &wait_time);

  /**
   * Block indefinitely until at least one event is dispatched.
   * @return Returns 1 when a completion is dispatched. On error, returns -1
   * and sets errno accordingly.
   */
  int handle_events (void);

  /// Add wakeup dispatch threads (reinit).
  int wake_up_dispatch_threads (void);

  /// Close all dispatch threads.
  int close_dispatch_threads (int wait);

  /// Get number of thread used as a parameter to CreatIoCompletionPort.
  size_t number_of_threads (void) const;

  /// Set number of thread used as a parameter to CreatIoCompletionPort.
  void number_of_threads (size_t threads);

  /// Get timer queue.
  TIMER_QUEUE *timer_queue (void) const;

  /// Set timer queue.
  void timer_queue (TIMER_QUEUE *timer_queue);

  /**
   * Get the event handle.
   * It is a no-op in POSIX platforms and it returns
   * ACE_INVALID_HANDLE.
   */
  ACE_HANDLE get_handle (void) const;

  /// Get the implementation class.
  ACE_Proactor_Impl *implementation (void) const;

  // = Factory methods for the operations

  // Note that the user does not have to use or know about these
  // methods.

  /// Create the correct implementation class for doing
  /// Asynch_Read_Stream.
  ACE_Asynch_Read_Stream_Impl *create_asynch_read_stream (void);

  /// Create the correct implementation class for doing
  /// Asynch_Write_Stream.
  ACE_Asynch_Write_Stream_Impl *create_asynch_write_stream (void);

  /// Create the correct implementation class for doing
  /// Asynch_Read_File.
  ACE_Asynch_Read_File_Impl *create_asynch_read_file (void);

  /// Create the correct implementation class for doing
  /// Asynch_Write_File.
  ACE_Asynch_Write_File_Impl *create_asynch_write_file (void);

  /// Create the correct implementation class for doing Asynch_Accept.
  ACE_Asynch_Accept_Impl *create_asynch_accept (void);

  /// Create the correct implementation class for doing Asynch_Connect.
  ACE_Asynch_Connect_Impl *create_asynch_connect (void);

  /// Create the correct implementation class for doing
  /// Asynch_Transmit_File.
  ACE_Asynch_Transmit_File_Impl *create_asynch_transmit_file (void);

  /// Create the correct implementation class for doing
  /// Asynch_Read_Dgram.
  ACE_Asynch_Read_Dgram_Impl *create_asynch_read_dgram (void);

  /// Create the correct implementation class for doing
  /// Asynch_Write_Dgram.
  ACE_Asynch_Write_Dgram_Impl *create_asynch_write_dgram (void);

  // = Factory methods for the results

  // Note that the user does not have to use or know about these
  // methods unless they want to "fake" results.

  /// Create the correct implementation class for
  /// ACE_Asynch_Read_Stream::Result class.
  ACE_Asynch_Read_Stream_Result_Impl *
    create_asynch_read_stream_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block &message_block,
                                      u_long bytes_to_read,
                                      const void* act,
                                      ACE_HANDLE event = ACE_INVALID_HANDLE,
                                      int priority = 0,
                                      int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Write_Stream::Result.
  ACE_Asynch_Write_Stream_Result_Impl *
    create_asynch_write_stream_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                       ACE_HANDLE handle,
                                       ACE_Message_Block &message_block,
                                       u_long bytes_to_write,
                                       const void* act,
                                       ACE_HANDLE event = ACE_INVALID_HANDLE,
                                       int priority = 0,
                                       int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Read_File::Result.
  ACE_Asynch_Read_File_Result_Impl *
    create_asynch_read_file_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                    ACE_HANDLE handle,
                                    ACE_Message_Block &message_block,
                                    u_long bytes_to_read,
                                    const void* act,
                                    u_long offset,
                                    u_long offset_high,
                                    ACE_HANDLE event = ACE_INVALID_HANDLE,
                                    int priority = 0,
                                    int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Write_File::Result.
  ACE_Asynch_Write_File_Result_Impl *
    create_asynch_write_file_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block &message_block,
                                     u_long bytes_to_write,
                                     const void* act,
                                     u_long offset,
                                     u_long offset_high,
                                     ACE_HANDLE event = ACE_INVALID_HANDLE,
                                     int priority = 0,
                                     int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Read_Dgram::Result.
  ACE_Asynch_Read_Dgram_Result_Impl *
    create_asynch_read_dgram_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                     ACE_HANDLE handle,
                                     ACE_Message_Block *message_block,
                                     size_t bytes_to_read,
                                     int flags,
                                     int protocol_family,
                                     const void* act,
                                     ACE_HANDLE event = ACE_INVALID_HANDLE,
                                     int priority = 0,
                                     int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Write_Dgram::Result.
  ACE_Asynch_Write_Dgram_Result_Impl *
    create_asynch_write_dgram_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                      ACE_HANDLE handle,
                                      ACE_Message_Block *message_block,
                                      size_t bytes_to_write,
                                      int flags,
                                      const void* act,
                                      ACE_HANDLE event = ACE_INVALID_HANDLE,
                                      int priority = 0,
                                      int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for ACE_Asynch_Accept::Result.
  ACE_Asynch_Accept_Result_Impl *
    create_asynch_accept_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                 ACE_HANDLE listen_handle,
                                 ACE_HANDLE accept_handle,
                                 ACE_Message_Block &message_block,
                                 u_long bytes_to_read,
                                 const void* act,
                                 ACE_HANDLE event = ACE_INVALID_HANDLE,
                                 int priority = 0,
                                 int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for ACE_Asynch_Connect::Result
  ACE_Asynch_Connect_Result_Impl *
    create_asynch_connect_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                  ACE_HANDLE  connect_handle,
                                  const void* act,
                                  ACE_HANDLE event = ACE_INVALID_HANDLE,
                                  int priority = 0,
                                  int signal_number = ACE_SIGRTMIN);

  /// Create the correct implementation class for
  /// ACE_Asynch_Transmit_File::Result.
  ACE_Asynch_Transmit_File_Result_Impl *
    create_asynch_transmit_file_result (ACE_Handler::Proxy_Ptr &handler_proxy,
                                        ACE_HANDLE socket,
                                        ACE_HANDLE file,
                                        ACE_Asynch_Transmit_File::Header_And_Trailer *header_and_trailer,
                                        u_long bytes_to_write,
                                        u_long offset,
                                        u_long offset_high,
                                        u_long bytes_per_send,
                                        u_long flags,
                                        const void *act,
                                        ACE_HANDLE event = ACE_INVALID_HANDLE,
                                        int priority = 0,
                                        int signal_number = ACE_SIGRTMIN);

  /**
   * Create a timer result object which can be used with the Timer
   * mechanism of the Proactor.
   * If @a signal_number is -1, <POSIX_SIG_Proactor> will create a
   * Timer object with a meaningful signal number, choosing the
   * largest signal number from the signal mask of the Proactor.
   */
  ACE_Asynch_Result_Impl *
    create_asynch_timer (ACE_Handler::Proxy_Ptr &handler_proxy,
                         const void *act,
                         const ACE_Time_Value &tv,
                         ACE_HANDLE event = ACE_INVALID_HANDLE,
                         int priority = 0,
                         int signal_number = ACE_SIGRTMIN);

protected:

  /**
   * Post <how_many> completions to the completion port so that all
   * threads can wake up. This is used in conjunction with the
   * <run_event_loop>.
   */
  static int post_wakeup_completions (int how_many);

  /**
   * Post <how_many> completions to the completion port so that all
   * threads can wake up. This is used in conjunction with the
   * <proactor_run_event_loop>.
   */
  int proactor_post_wakeup_completions (int how_many);

  /// Set the implementation class.
  void implementation (ACE_Proactor_Impl *implementation);

  /// Delegation/implementation class that all methods will be
  /// forwarded to.
  ACE_Proactor_Impl *implementation_;

  /// Flag used to indicate whether we are responsible for cleaning up
  /// the implementation instance.
  bool delete_implementation_;

  /// Pointer to a process-wide ACE_Proactor.
  static ACE_Proactor *proactor_;

  /// Must delete the <proactor_> if true.
  static bool delete_proactor_;

  /// Handles timeout events.
  ACE_Proactor_Timer_Handler *timer_handler_;

  /// This will manage the thread in the Timer_Handler.
  ACE_Thread_Manager thr_mgr_;

  /// Timer Queue.
  TIMER_QUEUE *timer_queue_;

  /// Flag on whether to delete the timer queue.
  int delete_timer_queue_;

  /// Terminate the proactor event loop.
  sig_atomic_t end_event_loop_;

  /// Number of threads in the event loop.
  sig_atomic_t event_loop_thread_count_;

  /// Mutex to protect work with lists.
  ACE_SYNCH_MUTEX mutex_;

private:
  /// Deny access since member-wise won't work...
  ACE_Proactor (const ACE_Proactor &);
  ACE_Proactor &operator= (const ACE_Proactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#  if defined (__ACE_INLINE__)
#    include "ace/Proactor.inl"
#  endif /* __ACE_INLINE__ */

#else /* NOT WIN32 or POSIX with AIO features. */

#  include "ace/os_include/os_stddef.h"
#  include "ace/os_include/os_signal.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

class ACE_Export ACE_Proactor
{
public:
  class Timer_Queue {};
  ACE_Proactor (size_t /* number_of_threads */ = 0,
                Timer_Queue * /* tq */ = 0) {}
  ~ACE_Proactor (void) {}
  int handle_events (void) { return -1; }
  int handle_events (ACE_Time_Value &) { return -1; }

  /// Placeholder to enable compilation on non-Win32 platforms
  static ACE_Proactor *instance (size_t threads = 0);

  /// Placeholder to enable compilation on non-Win32 platforms
  static ACE_Proactor *instance (ACE_Proactor *);

  /// Placeholder to enable compilation on non-Win32 platforms
  static void close_singleton (void);

  /// Placeholder to enable compilation on non-Win32 platforms
  static int run_event_loop (void);

  /// Placeholder to enable compilation on non-Win32 platforms
  static int run_event_loop (ACE_Time_Value &tv);

  /// Placeholder to enable compilation on non-Win32 platforms
  static int end_event_loop (void);

  /// Placeholder to enable compilation on non-Win32 platforms
  static sig_atomic_t event_loop_done (void);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO || ACE_HAS_AIO_CALLS */

#include /**/ "ace/post.h"

#endif /* ACE_PROACTOR_H */

