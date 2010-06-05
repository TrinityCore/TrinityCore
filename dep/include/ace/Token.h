// -*- C++ -*-

//=============================================================================
/**
 *  @file    Token.h
 *
 *  $Id: Token.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Original author
 *  @author Karl-Heinz Dorn (kdorn@erlh.siemens.de)
 *  @author Ported to ACE by
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_TOKEN_H
#define ACE_TOKEN_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Null_Mutex.h"

#if defined (ACE_HAS_THREADS)

#include "ace/Thread_Mutex.h"

#if (defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)) || defined (ACE_HAS_VXTHREADS)
// If platforms support semaphores with timed wait, then we use semaphores instead of c.v.
# define ACE_TOKEN_USES_SEMAPHORE
#endif /* (ACE_WIN32 && !ACE_HAS_WINCE) || VXWORKS */

#if defined (ACE_TOKEN_USES_SEMAPHORE)
#  include "ace/Semaphore.h"
#endif /* ACE_TOKEN_USES_SEMAPHORE */

#include "ace/Condition_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Token
 *
 * @brief Class that acquires, renews, and releases a synchronization
 * token that is serviced in strict FIFO/LIFO ordering and that also
 * supports (1) recursion and (2) readers/writer semantics.
 *
 * This class is a more general-purpose synchronization mechanism
 * than many native OS mutexes.  For example, it implements
 * "recursive mutex" semantics, where a thread that owns the token
 * can reacquire it without deadlocking.  If the same thread calls
 * <acquire> multiple times, however, it must call <release> an
 * equal number of times before the token is actually released.
 * Threads that are blocked awaiting the token are serviced in
 * strict FIFO/LIFO order as other threads release the token (Solaris
 * and Pthread mutexes don't strictly enforce an acquisition
 * order).  There are two lists within the class.  Write
 * acquires always have higher priority over read acquires.  Which
 * means, if you use both write/read operations, care must be
 * taken to avoid starvation on the readers.  Notice that the
 * read/write acquire operations do not have the usual semantic of
 * reader/writer locks.  Only one reader can acquire the token at
 * a time (which is different from the usual reader/writer locks
 * where several readers can acquire a lock at the same time as
 * long as there is no writer waiting for the lock).  We choose
 * the names to (1) borrow the semantic to give writers higher
 * priority and (2) support a common interface for all locking
 * classes in ACE.
 */
class ACE_Export ACE_Token
{
public:

  /**
   * Available queueing strategies.
   */
  enum QUEUEING_STRATEGY
  {
    /// FIFO, First In, First Out.
    FIFO = -1,
    /// LIFO, Last In, First Out
    LIFO = 0
  };

  // = Initialization and termination.

  /// Constructor
  ACE_Token (const ACE_TCHAR *name = 0, void * = 0);

  /// Destructor
  virtual ~ACE_Token (void);

  // = Strategies

  /// Retrieve the current queueing strategy.
  int queueing_strategy (void);

  /// Set the queueing strategy.
  void queueing_strategy (int queueing_strategy);

  // = Synchronization operations.

  /**
   * Acquire the token, sleeping until it is obtained or until the
   * expiration of @a timeout, which is treated as "absolute" time.  If
   * some other thread currently holds the token then <sleep_hook> is
   * called before our thread goes to sleep.  This <sleep_hook> can be
   * used by the requesting thread to unblock a token-holder that is
   * sleeping, e.g., by means of writing to a pipe (the ACE
   * ACE_Reactor uses this functionality).  Return values: 0 if
   * acquires without calling <sleep_hook> 1 if <sleep_hook> is
   * called.  2 if the token is signaled.  -1 if failure or timeout
   * occurs (if timeout occurs errno == ETIME) If @a timeout ==
   * <&ACE_Time_Value::zero> then acquire has polling semantics (and
   * does *not* call <sleep_hook>).
   */
  int acquire (void (*sleep_hook)(void *),
               void *arg = 0,
               ACE_Time_Value *timeout = 0);

  /**
   * This behaves just like the previous <acquire> method, except that
   * it invokes the virtual function called <sleep_hook> that can be
   * overridden by a subclass of ACE_Token.
   */
  int acquire (ACE_Time_Value *timeout = 0);

  /**
   * This should be overridden by a subclass to define the appropriate
   * behavior before <acquire> goes to sleep.  By default, this is a
   * no-op...
   */
  virtual void sleep_hook (void);

  /**
   * An optimized method that efficiently reacquires the token if no
   * other threads are waiting.  This is useful for situations where
   * you don't want to degrade the quality of service if there are
   * other threads waiting to get the token.  If <requeue_position> ==
   * -1 and there are other threads waiting to obtain the token we are
   * queued according to the queueing strategy.  If <requeue_position>
   * > -1 then it indicates how many entries to skip over before
   * inserting our thread into the list of waiters (e.g.,
   * <requeue_position> == 0 means "insert at front of the queue").
   * Renew has the rather odd semantics such that if there are other
   * waiting threads it will give up the token even if the
   * nesting_level_ > 1.  I'm not sure if this is really the right
   * thing to do (since it makes it possible for shared data to be
   * changed unexpectedly) so use with caution...  This method
   * maintians the original token priority.  As in <acquire>, the
   * @a timeout value is an absolute time.
   */
  int renew (int requeue_position = 0,
             ACE_Time_Value *timeout = 0);

  /// Become interface-compliant with other lock mechanisms (implements
  /// a non-blocking <acquire>).
  int tryacquire (void);

  /// Shuts down the ACE_Token instance.
  int remove (void);

  /// Relinquish the token.  If there are any waiters then the next one
  /// in line gets it.
  int release (void);

  /// Behaves like acquire() but at a lower priority.  It should probably
  /// be called acquire_yield() since the semantics aren't really
  /// what's commonly expected for readers/writer locks.  See the class
  /// documentation above for more details.
  int acquire_read (void);

  /// Behaves like acquire() but at a lower priority.  It should probably
  /// be called acquire_yield() since the semantics aren't really
  /// what's commonly expected for readers/writer locks.  See the class
  /// documentation above for more details.
  int acquire_read (void (*sleep_hook)(void *),
                    void *arg = 0,
                    ACE_Time_Value *timeout = 0);

  /// Calls acquire().
  int acquire_write (void);

  /// Calls acquire().
  int acquire_write (void (*sleep_hook)(void *),
                     void *arg = 0,
                     ACE_Time_Value *timeout = 0);

  /// Lower priority try_acquire().
  int tryacquire_read (void);

  /// Just calls <tryacquire>.
  int tryacquire_write (void);

  /// Assumes the caller has acquired the token and returns 0.
  int tryacquire_write_upgrade (void);

  // = Accessor methods.

  /// Return the number of threads that are currently waiting to get
  /// the token.
  int waiters (void);

  /// Return the id of the current thread that owns the token.
  ACE_thread_t current_owner (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  /// The following structure implements a LIFO/FIFO queue of waiter threads
  /// that are asleep waiting to obtain the token.
  struct ACE_Token_Queue_Entry
  {
    /// Constructor
    ACE_Token_Queue_Entry (ACE_Thread_Mutex &m,
                           ACE_thread_t t_id);

    /// Constructor using a pre-allocated attributes
    ACE_Token_Queue_Entry (ACE_Thread_Mutex &m,
                           ACE_thread_t t_id,
                           ACE_Condition_Attributes &attributes);

    /// Entry blocks on the token.
    int wait (ACE_Time_Value *timeout, ACE_Thread_Mutex &lock);

    /// Notify (unblock) the entry.
    int signal (void);

    /// Pointer to next waiter.
    ACE_Token_Queue_Entry *next_;

    /// ACE_Thread id of this waiter.
    ACE_thread_t thread_id_;

#if defined (ACE_TOKEN_USES_SEMAPHORE)
    /// ACE_Semaphore object used to wake up waiter when it can run again.
    ACE_Semaphore cv_;
#else
    /// ACE_Condition object used to wake up waiter when it can run again.
    ACE_Condition_Thread_Mutex cv_;
#endif /* ACE_TOKEN_USES_SEMAPHORE */

    /// Ok to run.
    int runable_;
  };

private:
  enum ACE_Token_Op_Type
  {
    READ_TOKEN = 1,
    WRITE_TOKEN
  };

  struct ACE_Token_Queue
  {
    /// Constructor
    ACE_Token_Queue (void);

    /// Remove a waiter from the queue.
    void remove_entry (ACE_Token_Queue_Entry *);

    /// Insert a waiter into the queue.
    void insert_entry (ACE_Token_Queue_Entry &entry,
                       int requeue_position = -1);

    /// Head of the list of waiting threads.
    ACE_Token_Queue_Entry *head_;

    /// Tail of the list of waiting threads.
    ACE_Token_Queue_Entry *tail_;
  };

  /// Implements the <acquire> and <tryacquire> methods above.
  int shared_acquire (void (*sleep_hook_func)(void *),
                      void *arg,
                      ACE_Time_Value *timeout,
                      ACE_Token_Op_Type op_type);

  /// Wake next in line for ownership.
  void wakeup_next_waiter (void);

  /// A queue of writer threads.
  ACE_Token_Queue writers_;

  /// A queue of reader threads.
  ACE_Token_Queue readers_;

  /// ACE_Thread_Mutex used to lock internal data structures.
  ACE_Thread_Mutex lock_;

  /// Current owner of the token.
  ACE_thread_t owner_;

  /// Some thread (i.e., <owner_>) is using the token.  We need this
  /// extra variable to deal with POSIX pthreads madness...
  int in_use_;

  /// Number of waiters.
  int waiters_;

  /// Current nesting level.
  int nesting_level_;

  /// The attributes for the condition variables, optimizes lock time.
  ACE_Condition_Attributes attributes_;

  /// Queueing strategy, LIFO/FIFO.
  int queueing_strategy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#else

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_Token
{
public:
  int queueing_strategy (void) { ACE_NOTSUP_RETURN (-1); }
  void queueing_strategy (int /*queueing_strategy*/) { }
  int acquire (ACE_Time_Value * = 0) { ACE_NOTSUP_RETURN (-1); }
  int tryacquire (void) { ACE_NOTSUP_RETURN (-1); }
  int remove (void) { ACE_NOTSUP_RETURN (-1); }
  int release (void) { ACE_NOTSUP_RETURN (-1); }
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Export ACE_Noop_Token : public ACE_Null_Mutex
{
public:
  /// Queueing strategy
  enum QUEUEING_STRATEGY
  {
    FIFO = -1,
    LIFO = 0
  };

  /// Get queueing strategy.
  int queueing_strategy (void);

  /// Set queueing strategy.
  void queueing_strategy (int queueing_strategy);

  int renew (int = 0, ACE_Time_Value * =0);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Token.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_TOKEN_H */

