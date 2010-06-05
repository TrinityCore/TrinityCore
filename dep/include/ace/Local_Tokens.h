// -*- C++ -*-

//=============================================================================
/**
 *  @file    Local_Tokens.h
 *
 *  $Id: Local_Tokens.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Karl-Heinz Dorn <kdorn@erlh.siemens.de>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Tim Harrison <harrison@cs.wustl.edu>
 *
 * This file contains definitions for the following classes:
 *
 * public:
 *   7. ACE_Token_Proxy
 *   8. ACE_Null_Token : public ACE_Token_Proxy
 *   9. ACE_Local_Mutex : public ACE_Token_Proxy
 *   *. ACE_Local_RLock : public ACE_Local_Mutex
 *   &. ACE_Local_WLock : public ACE_Local_Mutex
 * private:
 *   1. ACE_TOKEN_CONST
 *   3. ACE_TPQ_Entry
 *   b. ACE_TSS_TPQ_Entry
 *   c. ACE_TPQ_Iterator
 *   4. ACE_Token_Proxy_Queue
 *   5. ACE_Tokens
 *   6. ACE_Mutex_Token : public ACE_Tokens
 *   12. ACE_RW_Token : public ACE_Tokens
 *   a. ACE_Token_Name
 *
 *  Note that the locking classes defined in this file are *not*
 *  intended to be used as general-purpose synchronization
 *  mechanisms, such as mutexes or semaphores.  Instead, you should
 *  use the ACE_Recursive_Thread_Mutex, ACE_Thread_Mutex,
 *  ACE_Thread_Semaphore, etc., that are defined in
 *  $ACE_ROOT/ace/Synch.h and $ACE_ROOT/ace/Synch_T.h or the
 *  ACE_Token that's defined in $ACE_ROOT/ace/Token.h.
 *
 *
 */
//=============================================================================

#ifndef ACE_LOCAL_MUTEX_H
#define ACE_LOCAL_MUTEX_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Synch_Traits.h"
#include "ace/Condition_Thread_Mutex.h"
#include "ace/TSS_T.h"
#include "ace/Containers.h"
#include "ace/Synch_Options.h"
#include "ace/Map_Manager.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/os_netdb.h"

#if !(defined (ACE_HAS_THREADS) && defined (ACE_HAS_THREAD_SPECIFIC_STORAGE))
# define ACE_NO_TSS_TOKENS 1
#endif /* !(defined (ACE_HAS_THREADS) && defined (ACE_HAS_THREAD_SPECIFIC_STORAGE)) */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// 1.
/**
 * @class ACE_TOKEN_CONST
 *
 * @brief Not a public interface.
 *
 * Constant definitions and typedefs for Token library.  Mostly,
 * this class is necessary to fight the compiler with order of
 * declaration errors.
 */
namespace ACE_TOKEN_CONST
{
#if defined (ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
  // ACE platform supports some form of threading.
  typedef ACE_Condition_Thread_Mutex COND_VAR;
  typedef ACE_Thread_Mutex MUTEX;
  typedef ACE_Guard<ACE_Thread_Mutex> GUARD;
#else
  typedef ACE_Null_Condition COND_VAR;
  typedef ACE_Null_Mutex MUTEX;
  typedef ACE_Guard<ACE_Null_Mutex> GUARD;
#endif /* ACE_HAS_THREADS */
}

// Forward decl.
class ACE_Token_Proxy;

// 3..
/**
 * @class ACE_TPQ_Entry
 *
 * @brief Token Proxy Queue entry.  Used in the ACE_Token_Proxy_Queue
 *
 * Not a public interface.
 */
class ACE_Export ACE_TPQ_Entry
{
  friend class ACE_Token_Manager;
public:
  typedef void (*PTVF) (void *);

  /// Null constructor.
  ACE_TPQ_Entry (void);

  /// Constructor.
  ACE_TPQ_Entry (const ACE_Token_Proxy *proxy,
                 const ACE_TCHAR *client_id);

  /// Copy constructor.
  ACE_TPQ_Entry (const ACE_TPQ_Entry &rhs);

  /// Destructor.
  ~ACE_TPQ_Entry (void);

  /// Copy operator use by the queue.
  void operator= (const ACE_TPQ_Entry &rhs);

  /// Get top of the queue.
  ACE_Token_Proxy *proxy (void) const;

  /// Set top of the queue.
  void proxy (ACE_Token_Proxy *);

  /// Get nesting level of the entry.
  int nesting_level (void) const;

  /// Delta nesting level of the entry.
  void nesting_level (int delta);

  /// Get client_id of the entry.
  const ACE_TCHAR *client_id (void) const;

  /// Set client_id of the entry.
  void client_id (const ACE_TCHAR *);

  /// Returns 1 if @a id == client id.  Does not check for @a id == 0.
  int equal_client_id (const ACE_TCHAR *id);

  /// One method for arg and sleep_hook.
  void set (void (*sleep_hook)(void *));

  /// Set sleep hook of the entry.
  void sleep_hook (void (*sh)(void *));

  /// Get sleep hook of the entry.
  PTVF sleep_hook (void) const;

  /// Call the sleep hook function or method passing arg.
  void call_sleep_hook (void);

  /// Dump the state of the class.
  void dump (void) const;

  // = Used to block the thread if an acquire fails with EWOULDBLOCK.
  ACE_TOKEN_CONST::COND_VAR cond_var_;
  ACE_TOKEN_CONST::MUTEX lock_;

  /// Pointer to next in list.
  ACE_TPQ_Entry *next_;

  /// Get whether this client is blocked waiting for a token.
  int waiting (void) const;

  /// Set whether this client is blocked waiting for a token.
  void waiting (int w);

private:
  /// This client is waiting for a token.
  int waiting_;

  /// Proxy.
  ACE_Token_Proxy *proxy_;

  /// Nesting level.
  int nesting_level_;

  /// Arg.
  void *arg_;

  /// Client id.
  ACE_TCHAR client_id_[ACE_MAXCLIENTIDLEN];

  /// Sleep hook.
  void (*sleep_hook_)(void *);
};

// b..
#if defined (ACE_NO_TSS_TOKENS)
typedef ACE_TPQ_Entry ACE_TPQ_ENTRY;
#else
typedef ACE_TSS<ACE_TPQ_Entry> ACE_TPQ_ENTRY;
#endif /* ACE_NO_TSS_TOKENS */

/**
 * @class ACE_TSS_TPQ_Entry
 *
 * @brief ACE_TSS_TPQ_Entry
 *
 * Not a public interface.
 */
class ACE_Export ACE_TSS_TPQ_Entry : public ACE_TPQ_ENTRY
{
public:
  /// These are passed to the constructor of ACE_TPQ_Entry in
  /// make_TSS_TYPE
  ACE_TSS_TPQ_Entry (const ACE_Token_Proxy *proxy,
                     const ACE_TCHAR *client_id);

  /// Destructor.
  virtual ~ACE_TSS_TPQ_Entry (void);

  /// Allows us to pass args to the construction of the TSS object.
  virtual ACE_TPQ_Entry *make_TSS_TYPE (void) const;

  /// Operator overloading and inheritence don't mix.
  operator ACE_TPQ_Entry *(void);

  /// Dump the state of the class.
  void dump (void) const;

#if defined (ACE_NO_TSS_TOKENS)
  ACE_TPQ_Entry *operator-> (void)
    {
      return (ACE_TPQ_Entry *) this;
    }
#endif /* ACE_NO_TSS_TOKENS */

private:
  /// Private: should not be used
  ACE_TSS_TPQ_Entry (const ACE_TSS_TPQ_Entry &);
  void operator= (const ACE_TSS_TPQ_Entry &);

  // = These are passed to the constructor of ACE_TPQ_Entry in
  // make_TSS_TYPE

  /// Proxy.
  const ACE_Token_Proxy *proxy_;

  /// Client_id.
  const ACE_TCHAR *client_id_;
};

class ACE_Token_Proxy_Queue;

// c..
/**
 * @class ACE_TPQ_Iterator
 *
 * @brief Iterates through ACE_Token_Proxy_Queues.
 *
 * Not a public interface.
 */
class ACE_Export ACE_TPQ_Iterator
{
public:
  /// Constructor.
  ACE_TPQ_Iterator (ACE_Token_Proxy_Queue &q);

  /// Destructor.
  ~ACE_TPQ_Iterator (void);

  /// Pass back the <next_item>.
  int next (ACE_TPQ_Entry *&next_item);

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Move forward by one element in the queue.
  void advance (void);

  /// Dump the state of an object.
  void dump (void) const;

private:
  ACE_TPQ_Entry *current_;
};

// 4..
/**
 * @class ACE_Token_Proxy_Queue
 *
 * @brief Token waiter list.
 *
 * Not a public interface.
 * This queue holds all the token proxies waiting for ownership
 * of a token.  Along with the proxy reference, it also stores
 * the nesting level, client id, and a magic cookie from the
 * proxy.  This queue stores the ACE_TPQ_Entries by pointer
 * values.  It DOES NOT make copies.  Thus, the user is
 * responsible to ensure that the TPQ's stick around.  This is
 * motivated by the need to reduce dynamic memory allocation.
 */
class ACE_Export ACE_Token_Proxy_Queue
{
public:
  friend class ACE_TPQ_Iterator;

  /// Constructor.
  ACE_Token_Proxy_Queue (void);

  /// Destructor.
  ~ACE_Token_Proxy_Queue (void);

  /**
   * Enqueue a proxy, nesting level, client_id, and a magic cookie at
   * the given position in the list.  If the position is -1, we
   * enqueue at the end of the list (I think).
   */
  void enqueue (ACE_TPQ_Entry* new_entry,
                int position);

  /// Top of the queue.
  const ACE_TPQ_Entry* head (void);

//  int member (const ACE_TCHAR *id);
  // Is this id in the waiter list?

  /// Remove the top waiter.
  void dequeue (void);

  /// Remove the waiter whose proxy ref matches @a remove_me.
  void remove (const ACE_TPQ_Entry *remove_me);

  /// The number of waiters.
  int size (void);

  /// Dump the state of the class.
  void dump (void) const;

protected:
  /// Head.
  ACE_TPQ_Entry *head_;

  /// Tail.
  ACE_TPQ_Entry *tail_;

  /// Size.
  int size_;
};

// 5..
/**
 * @class ACE_Tokens
 *
 * @brief Abstract representation of ACE tokens.
 *
 * Not a public interface.
 * Currently, I don't see a reason for providing an abstract
 * interface at this level of the library.  As of yet, no one
 * uses ACE_Tokens derivatives through this abstract interface
 * except for ACE_Token_Manager.  It only uses the statistical
 * methods which are shared by all Tokens.  For that reason, it
 * still makes since to have a common base class.  However,
 * acquire, renew, and release do not need to have matching
 * interfaces throughout all Tokens.
 * To add a new type of token (e.g. semaphore), this class must
 * be subtyped to define the new semantics.  See
 * ACE_Token_Manager for details.
 */
class ACE_Export ACE_Tokens
{
public:

  /// Null constructor.
  ACE_Tokens (void);

  /// Destructor
  virtual ~ACE_Tokens (void);

  /// No implementation.
  virtual int acquire (ACE_TPQ_Entry *caller,
                       int ignore_deadlock,
                       int notify) = 0;

  /// No implementation.
  virtual int tryacquire (ACE_TPQ_Entry *caller) = 0;

  /// No implementation.
  virtual int renew (ACE_TPQ_Entry *caller,
                     int requeue_position) = 0;

  /// No implementation.
  virtual int release (ACE_TPQ_Entry *caller) = 0;

  /// Move the caller to the front of the waiter list.  This is for use
  /// with remote mutexes and shadow mutexes.
  void make_owner (ACE_TPQ_Entry *caller);

  /// Remove the caller from the waiter list.
  void remove (ACE_TPQ_Entry *caller);

  // = Accessor methods.

  /// Stack of owners.
  typedef ACE_Unbounded_Stack<ACE_TPQ_Entry *> OWNER_STACK;

  /// Returns a stack of the current owners.  Returns -1 on error, 0 on
  /// success.  If <id> is non-zero, returns 1 if id is an owner.
  virtual int owners (OWNER_STACK &o, const ACE_TCHAR *id) = 0;

  /// Returns 1 if <id> is waiting for this token.  0 otherwise.
  virtual int is_waiting_for (const ACE_TCHAR *id) = 0;

  /// Returns 1 if <id> is an owner of this token.  0 otherwise.
  virtual int is_owner (const ACE_TCHAR *id) = 0;

  /// Return the queue of waiters.
  virtual ACE_Token_Proxy_Queue *waiters (void);

  /// Return the number of proxies that are currently waiting to get
  /// the token.
  virtual int no_of_waiters (void);

  /// The current owner.
  const ACE_TCHAR *owner_id (void);

  /// Token name.
  const ACE_TCHAR* name (void);

  // = Reference counting.  These are only called by the
  // Token_Manager.
  void inc_reference (void);
  int dec_reference (void);

  /// Dump the state of the class.
  void dump (void) const;

  /**
   * These are the Token types supported by the library at ship time.
   * There is no restriction on the number of Token types added by
   * "3rd parties."  These are only necessary for the Token Server.
   */
  enum TOKEN_TYPES { MUTEX, RWLOCK };

  /**
   * Provides a manual RTTI mechanism.  This method is used only by
   * ACE_Token_Request so that the type of a token can be sent to a
   * remote Token Server.
   */
  virtual int type (void) const = 0;

  // = The following methods allow the deadlock detection algorithm to
  // check if this token has been visited.

  /// Mark or unmark the token as visited.
  void visit (int v);

  /// Check if the token has been visited.
  int visited (void);

  /// All the data of the current owner.
  ACE_TPQ_Entry *owner (void);

protected:

  /// For the deadlock detection algorithm.
  int visited_;

  /// Reference count.
  int reference_count_;

  /// List of client's owning and waiting the token.
  ACE_Token_Proxy_Queue waiters_;

  /// Name of token.
  ACE_TCHAR token_name_[ACE_MAXTOKENNAMELEN];
};

class ACE_Local_Mutex;

// 6..
/**
 * @class ACE_Mutex_Token
 *
 * @brief Class that acquires, renews, and releases a process-local
 * synchronization token.
 *
 * Not a public interface.
 * This class is a more general-purpose synchronization mechanism
 * than SunOS 5.x mutexes.  For example, it implements "recursive
 * mutex" semantics, where a thread that owns the token can
 * reacquire it without deadlocking.  In addition, threads that
 * are blocked awaiting the token are serviced in strict FIFO
 * order as other threads release the token (SunOS 5.x mutexes
 * don't strictly enforce an acquisition order).
 */
class ACE_Export ACE_Mutex_Token : public ACE_Tokens
{
public:
  /// Constructor
  explicit ACE_Mutex_Token (const ACE_TCHAR* name);

  /// Destructor
  virtual ~ACE_Mutex_Token (void);

  // = Synchronization operations.
  // With acquire, renew, and release, the caller must be specified so
  // that multiple proxies (e.g. ACE_Local_Mutex) can use the same
  // token.

  /**
   * Returns 0 on success, -1 on failure with <ACE_Log_Msg::errnum> as
   * the reason.  If errnum == EWOULDBLOCK, and notify == 1,
   * <ACE_Token_Proxy::sleep_hook> has been called on the current
   * owner of the token.  If ignore_deadlock is passed as 1 and errnum
   * == EDEADLK, then deadlock was detected via ace_token_manager.
   */
  virtual int acquire (ACE_TPQ_Entry *caller,
                       int ignore_deadlock,
                       int notify);

  /// Same as acquire, but fails if would block
  virtual int tryacquire (ACE_TPQ_Entry *caller);

  /**
   * An optimized method that efficiently reacquires the token if no
   * other threads are waiting.  This is useful for situations where
   * you don't want to degrade the quality of service if there are
   * other threads waiting to get the token.  If <requeue_position> ==
   * -1 and there are other threads waiting to obtain the token we are
   * queued at the end of the list of waiters.  If <requeue_position>
   * > -1 then it indicates how many entries to skip over before
   * inserting our thread into the list of waiters (e.g.,
   * <requeue_position> == 0 means "insert at front of the queue").
   * Renew has the rather odd semantics such that if there are other
   * waiting threads it will give up the token even if the
   * nesting_level_ > 1.  I'm not sure if this is really the right
   * thing to do (since it makes it possible for shared data to be
   * changed unexpectedly) so use with caution...  Returns 0 on
   * success, -1 on failure with <ACE_Log_Msg::errnum> as the reason.
   * If errnum == EWOULDBLOCK, and notify == 1,
   * <ACE_Token_Proxy::sleep_hook> has been called on the current
   * owner of the token.
   */
  virtual int renew (ACE_TPQ_Entry *caller,
                     int requeue_position);

  /**
   * Relinquish the token.  If there are any waiters then the next one
   * in line gets it.  If the caller is not the owner, caller is
   * removed from the waiter list.
   */
  virtual int release (ACE_TPQ_Entry *caller);

  /// Dump the state of the class.
  void dump (void) const;

  /// Returns ACE_Tokens::MUTEX.
  virtual int type (void) const;

  /// Returns a stack of the current owners.  Returns -1 on error, 0 on
  /// success.  If <id> is non-zero, returns 1 if id is an owner.
  virtual int owners (OWNER_STACK &o, const ACE_TCHAR *id);

  /// Returns 1 if <id> is waiting for this token.  0 otherwise.
  virtual int is_waiting_for (const ACE_TCHAR *id);

  /// Returns 1 if <id> is an owner of this token.  0 otherwise.
  virtual int is_owner (const ACE_TCHAR *id);

private:
  /// ACE_Mutex_Token used to lock internal data structures.
  ACE_TOKEN_CONST::MUTEX lock_;
};

// 12..
/**
 * @class ACE_RW_Token
 *
 * @brief Class that acquires, renews, and releases a process-local
 * synchronization token.
 *
 * Not a public interface.
 * This class is a more general-purpose synchronization mechanism
 * than SunOS 5.x mutexes.  For example, it implements "recursive
 * mutex" semantics, where a thread that owns the token can
 * reacquire it without deadlocking.  In addition, threads that are
 * blocked awaiting the token are serviced in strict FIFO order as
 * other threads release the token (SunOS 5.x mutexes don't strictly
 * enforce an acquisition order).
 */
class ACE_Export ACE_RW_Token : public ACE_Tokens
{
public:
  /// Constructor.
  explicit ACE_RW_Token (const ACE_TCHAR* name);

  /// Destructor.
  virtual ~ACE_RW_Token (void);

  // = Synchronization operations.
  // With acquire, renew, and release, the caller must be specified so
  // that multiple proxies (e.g. ACE_Local_Mutex) can use the same
  // token.

  /**
   * Returns 0 on success, -1 on failure with <ACE_Log_Msg::errnum> as
   * the reason.  If errnum == EWOULDBLOCK, and notify == 1,
   * <ACE_Token_Proxy::sleep_hook> has been called on the current
   * owner of the token.  If @a ignore_deadlock is passed as 1 and errnum
   * == EDEADLK, then deadlock was detected via ACE_Token_Manager.
   */
  virtual int acquire (ACE_TPQ_Entry *caller,
                       int ignore_deadlock,
                       int notify);

  /// Same as acquire except fails on would block
  virtual int tryacquire (ACE_TPQ_Entry *caller);

  /**
   * An optimized method that efficiently reacquires the token if no
   * other threads are waiting.  This is useful for situations where
   * you don't want to degrade the quality of service if there are
   * other threads waiting to get the token.  If <requeue_position> ==
   * -1 and there are other threads waiting to obtain the token we are
   * queued at the end of the list of waiters.  If <requeue_position>
   * > -1 then it indicates how many entries to skip over before
   * inserting our thread into the list of waiters (e.g.,
   * <requeue_position> == 0 means "insert at front of the queue").
   * Renew has the rather odd semantics such that if there are other
   * waiting threads it will give up the token even if the
   * nesting_level_ > 1.  I'm not sure if this is really the right
   * thing to do (since it makes it possible for shared data to be
   * changed unexpectedly) so use with caution...  Returns 0 on
   * success, -1 on failure with <ACE_Log_Msg::errnum> as the reason.
   * If errnum == EWOULDBLOCK, and notify == 1,
   * <ACE_Token_Proxy::sleep_hook> has been called on the current
   * owner of the token.
   */
  virtual int renew (ACE_TPQ_Entry *caller,
                     int requeue_position);

  /**
   * Relinquish the token.  If there are any waiters then the next one
   * in line gets it.  If the caller is not the owner, caller is
   * removed from the waiter list.
   */
  virtual int release (ACE_TPQ_Entry *caller);

  /// Dump the state of the class.
  void dump (void) const;

  /// These are the types that proxies can be.
  enum PROXY_TYPE { READER, WRITER };

  /// Returns READER or WRITER.
  virtual int type (void) const;

  /// Returns a stack of the current owners.  Returns -1 on error, 0 on
  /// success.  If <id> is non-zero, returns 1 if id is an owner.
  virtual int owners (OWNER_STACK &o, const ACE_TCHAR *id);

  /// Returns 1 if <id> is waiting for this token.  0 otherwise.
  virtual int is_waiting_for (const ACE_TCHAR *id);

  /// Returns 1 if <id> is an owner of this token.  0 otherwise.
  virtual int is_owner (const ACE_TCHAR *id);

protected:
  /// The number of waiting writers.
  int num_writers_;

  /// ACE_Mutex_Token used to lock internal data structures.
  ACE_TOKEN_CONST::MUTEX lock_;

  /// Sets the new owner.
  void notify_new_owner (ACE_TPQ_Entry *caller);
};

// a..
/**
 * @class ACE_Token_Name
 *
 * @brief Allows Token_Manger to identify tokens.
 *
 * For now, this is just a string.  We need a string class
 * anyway to use in ACE_Map_Manager.  Having this class
 * (instead of <ACE_SString>) allows us to easily change if
 * needed.  For instance, we may choose to identify tokens by
 * name and *type* in the future.
 */
class ACE_Export ACE_Token_Name
{
public:
  /// Construction.
  ACE_Token_Name (const ACE_TCHAR *token_name = 0);

  /// Copy construction.
  ACE_Token_Name (const ACE_Token_Name &rhs);

  /// Destructor.
  virtual ~ACE_Token_Name (void);

  /// Copy.
  void operator= (const ACE_Token_Name &rhs);

  /// Comparison.
  bool operator== (const ACE_Token_Name &rhs) const;

  /// Get the token name.
  const ACE_TCHAR *name (void) const;

  /// Set the token name.
  void name (const ACE_TCHAR *new_name);

  /// Dump the state of the class.
  void dump (void) const;

private:
  /// Name of the token.
  ACE_TCHAR token_name_[ACE_MAXTOKENNAMELEN];
};

// 7..
/**
 * @class ACE_Token_Proxy
 *
 * @brief Abstract representation of ACE tokens.
 *
 * Interface for all Tokens in ACE.  This class implements the
 * synchronization needed for tokens (condition variables etc.)
 * The algorithms for the operations (acquire, release, etc.)
 * operate on the generic ACE_Tokens interface.  Thus, the _type_
 * of token (mutex, rwlock) can be set at construction of
 * ACE_Token_Proxy.  You can use all Tokens in ACE through the
 * ACE_Token_Proxy by passing the proper values at construction.
 * Alternatively, there are class definitions which "know" how to
 * do this (ACE_Local_Mutex, ACE_Local_RLock, ACE_Local_WLock).
 * To add a new type of token (e.g. semaphore), this class is not
 * changed.  See ACE_Token_Manager for details.
 * Tokens (e.g. ACE_Mutex_Token) assume that it can always call
 * <ACE_Token_Proxy::token_acquired> on a new token owner.  This
 * is not a problem for synchronous use of token proxies (that is,
 * when acquires block until successful.)  However, for
 * implementations of the Token Server, which may use asynch
 * operations, the proxy can not go away after an acquire until
 * the token is acquired.  This is not really a problem, but
 * should be understood.
 */
class ACE_Export ACE_Token_Proxy
{
public:
  friend class ACE_Token_Manager;
  friend class ACE_Token_Invariant_Manager; // For testing.

  // Initialization and termination methods.
  /// Construction.
  ACE_Token_Proxy (void);

  /// Destructor.
  virtual ~ACE_Token_Proxy (void);

  /**
   * Open the <ACE_Token>.
   * @param name The string uniquely identifying the token.
   * @param ignore_deadlock Can be 1 to disable deadlock notifications.
   * @param debug Prints debug messages.
   */
  virtual int open (const ACE_TCHAR *name,
                    int ignore_deadlock = 0,
                    int debug = 0);

  // = The following methods have implementations which are
  // independent of the token semantics (mutex, rwlock, etc.)  They
  // forward operations to the underlying token and perform the
  // necessary blocking semantics for operations (condition variables
  // etc.)  This allows reuse of the blocking code as well as having
  // multiple proxies to the same token.

  /// Calls acquire on the token.  Blocks the calling thread if would
  /// block.
  virtual int acquire (int notify = 0,
                       void (*sleep_hook)(void *) = 0,
                       ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);

  /// Calls renew on the token.  Blocks the calling thread if would block.
  virtual int renew (int requeue_position = -1,
                     ACE_Synch_Options &options =
                     ACE_Synch_Options::defaults);

  /// Calls renew on the token.
  virtual int tryacquire (void (*sleep_hook)(void *) = 0);

  /// Calls release on the token.
  virtual int release (ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);

  /// Calls remove on the token.
  virtual int remove (ACE_Synch_Options &options =
                      ACE_Synch_Options::defaults);

  /// Since the locking mechanism doesn't support read locks then this
  /// just calls <acquire>.
  virtual int acquire_read (int notify = 0,
                            void (*sleep_hook)(void *) = 0,
                            ACE_Synch_Options &options =
                            ACE_Synch_Options::defaults);

  /// Since the locking mechanism doesn't support write locks then this
  /// just calls <acquire>.
  virtual int acquire_write (int notify = 0,
                             void (*sleep_hook)(void *) = 0,
                             ACE_Synch_Options &options =
                             ACE_Synch_Options::defaults);

  /// Since the locking mechanism doesn't support read locks then this
  /// just calls <tryacquire>.
  virtual int tryacquire_read (void (*sleep_hook)(void *) = 0);

  /// Since the locking mechanism doesn't support write locks then this
  /// just calls <tryacquire>.
  virtual int tryacquire_write (void (*sleep_hook)(void *) = 0);

  // = Utility methods.

  /// Get the client id of the proxy.  This is implemented as
  /// thread-specific data.
  virtual const ACE_TCHAR *client_id (void) const;

  /**
   * Set the client_id for the calling thread.  I strongly recommend
   * that this not be used unless you really know what you're doing.
   * I use this in the Token Server, and it caused many headaches.
   */
  virtual void client_id (const ACE_TCHAR *client_id);

  /**
   * Return the name of the token.  This is important for use within
   * the token servers (local and remote) as well as with token
   * collections.  So, all derivations of ACE_Token_Proxy must be able to
   * stringify some name.  The name must uniquely identify a token.
   * So, for instance, the token within the reactor should probably be
   * called "Reactor Token."
   */
  virtual const ACE_TCHAR *name (void) const;

  /**
   * This should really be called <someone_waiting>.  This is called
   * by ACE_Token_xx's when another proxy enters the waiting list and
   * requests that the current token holder be notified.
   */
  virtual void sleep_hook (void);

  /// This is called when a queued (waiting) proxy is removed from the
  /// waiters list and given the token.
  virtual void token_acquired (ACE_TPQ_Entry *);

  /// The client id of the current token holder
  virtual const ACE_TCHAR *owner_id (void);

  /// Return a dynamically allocated clone of the derived class.
  virtual ACE_Token_Proxy *clone (void) const = 0;

  /// Dump the state of the class.
  void dump (void) const;

  /**
   * This method can be used be Tokens (e.g. Readers/Writer Tokens) to
   * distinguish between Proxy types.  For instance a Reader proxy
   * should return a different type value than a Writer proxy.  The
   * default implementation returns 0.
   */
  virtual int type (void) const;

protected:
  /// Duplication.
  ACE_Token_Proxy (const ACE_Token_Proxy &);

  /// If this is set, we ignore deadlock.
  int ignore_deadlock_;

  /// Print a bunch of debug messages.
  int debug_;

  /// Reference to the actual logical token.  Many ACE_Local_Mutex
  /// proxies can reference the same ACE_Mutex_Token.
  ACE_Tokens *token_;

  /// Handles cond_var waits.
  int handle_options (ACE_Synch_Options &options,
                      ACE_TOKEN_CONST::COND_VAR &cv);

  /// Waiter info used for asynchronous transactions.
  ACE_TSS_TPQ_Entry waiter_;

  /// Make the correct type of ACE_Tokens.  This is called by the Token
  /// Manager.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name) = 0;
};

// 8..
/**
 * @class ACE_Null_Token
 *
 * @brief No op class for nonthreaded platform protocols.
 */
class ACE_Export ACE_Null_Token : public ACE_Token_Proxy
{
public:
#if defined (ACE_LACKS_INLINE_FUNCTIONS)
  // @@ Hopefully, we can remove this ridicules ifdef when CE's compiler becomes more normal.
  /// Construction.
  ACE_Null_Token (void);

  /// Destructor.
  ~ACE_Null_Token (void);
#endif /* ACE_LACKS_INLINE_FUNCTION */

  /// Acquire.
  virtual int acquire (int /* notify */ = 0,
                       void (* /* sleep_hook */ )(void *) = 0,
                       ACE_Synch_Options & /* options */ =
                       ACE_Synch_Options::defaults) { return 0; }

  /// Renew.
  virtual int renew (int /* requeue_position */ = -1,
                     ACE_Synch_Options & /* options */ =
                     ACE_Synch_Options::defaults) { return 0; }

  /// Try acquire.
  virtual int tryacquire (void (* /* sleep_hook */)(void *) = 0) { return 0; }

  /// Release.
  virtual int release (ACE_Synch_Options & /* options */ =
                       ACE_Synch_Options::defaults) { return 0; }

  /// Remove.
  virtual int remove (ACE_Synch_Options & /* options */ =
                      ACE_Synch_Options::defaults) { return 0; }

  /// Return a dynamically allocated clone of the derived class.
  virtual ACE_Token_Proxy *clone (void) const { return new ACE_Null_Token; }

  /// Dump the state of the class.
  void dump (void) const;

  /// Do not allow the Token Manager to create us.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *) { return 0; }
};

// 9..
/**
 * @class ACE_Local_Mutex
 *
 * @brief Class that acquires, renews, and releases a synchronization
 * token local to the process.
 *
 * This class is a more general-purpose synchronization mechanism
 * than SunOS 5.x mutexes.  For example, it implements "recursive
 * mutex" semantics, where a thread that owns the token can
 * reacquire it without deadlocking.  In addition, threads that
 * are blocked awaiting the token are serviced in strict FIFO
 * order as other threads release the token (SunOS 5.x mutexes
 * don't strictly enforce an acquisition order).  Lastly,
 * ACE_Local_Mutex performs deadlock detection on acquire calls.
 * The interfaces for acquire, tryacquire, renew, release,
 * etc. are defined in ACE_Token_Proxy.  The semantics for
 * ACE_Local_Mutex are that of a mutex.
 */
class ACE_Export ACE_Local_Mutex : public ACE_Token_Proxy
{
public:
  /**
   * Constructor.
   * @param token_name Uniquely id's the token.
   * @param ignore_deadlock Will allow deadlock to occur (useful for testing).
   * @param debug Prints a bunch of messages.
   */
  ACE_Local_Mutex (const ACE_TCHAR *token_name = 0,
                   int ignore_deadlock = 0,
                   int debug = 0);

  /// Destructor
  ~ACE_Local_Mutex (void);

  /// Dump the state of the class.
  void dump (void) const;

  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;

protected:
  /// Return a new ACE_Local_Mutex.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};

// *.
/**
 * @class ACE_Local_RLock
 *
 * @brief Class that acquires, renews, and releases a readers lock that
 * is local to the process.
 *
 * This class implements the reader interface to canonical
 * readers/writer locks.  Multiple readers can hold the lock
 * simultaneously when no writers have the lock.  Alternatively,
 * when a writer holds the lock, no other participants (readers
 * or writers) may hold the lock.  This class is a more
 * general-purpose synchronization mechanism than SunOS 5.x
 * RLocks.  For example, it implements "recursive RLock"
 * semantics, where a thread that owns the token can reacquire it
 * without deadlocking.  In addition, threads that are blocked
 * awaiting the token are serviced in strict FIFO order as other
 * threads release the token (SunOS 5.x RLockes don't strictly
 * enforce an acquisition order).
 * The interfaces for acquire, tryacquire, renew, release,
 * etc. are defined in ACE_Token_Proxy.  The semantics for
 * ACE_Local_RLock are that of a readers/writers lock.  Acquire
 * for this class implies a reader acquisition.  That is,
 * multiple clients may acquire a lock for read only.
 */
class ACE_Export ACE_Local_RLock : public ACE_Token_Proxy
{
public:
  // = Initialization and termination.

  /**
   * Constructor.
   * @param token_name Uniquely id's the token.
   * @param ignore_deadlock Will allow deadlock to occur (useful for testing).
   * @param debug Prints a bunch of messages.
   */
  ACE_Local_RLock (const ACE_TCHAR *token_name = 0,
                   int ignore_deadlock = 0,
                   int debug = 0);

  /// Destructor
  ~ACE_Local_RLock (void);

  /// Dump the state of the class.
  void dump (void) const;

  /// Returns ACE_RW_Token::RLOCK.
  virtual int type (void) const;

  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;

protected:
  /// Return a new ACE_Local_Mutex.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};

// *.
/**
 * @class ACE_Local_WLock
 *
 * @brief Class that acquires, renews, and releases a writer lock that
 * is local to the process.
 *
 * This class implements the writer interface to canonical
 * readers/writer locks. Multiple readers can hold the lock
 * simultaneously when no writers have the lock.  Alternatively,
 * when a writer holds the lock, no other participants (readers
 * or writers) may hold the lock.  This class is a more
 * general-purpose synchronization mechanism than SunOS 5.x
 * WLock.  For example, it implements "recursive WLock"
 * semantics, where a thread that owns the token can reacquire it
 * without deadlocking.  In addition, threads that are blocked
 * awaiting the token are serviced in strict FIFO order as other
 * threads release the token (SunOS 5.x WLocks don't strictly
 * enforce an acquisition order).
 * The interfaces for acquire, tryacquire, renew, release,
 * etc. are defined in ACE_Token_Proxy.  The semantics for
 * ACE_Local_WLock are that of a readers/writers lock.  Acquire
 * for this class implies a writer acquisition.  That is, only
 * one client may hold the lock for writing.
 */
class ACE_Export ACE_Local_WLock : public ACE_Token_Proxy
{
public:
  // = Initialization and termination.

  /**
   * Constructor.
   * @param token_name Uniquely id's the token.
   * @param ignore_deadlock Will allow deadlock to occur (useful for testing).
   * @param debug Prints a bunch of messages.
   */
  ACE_Local_WLock (const ACE_TCHAR *token_name = 0,
                   int ignore_deadlock = 0,
                   int debug = 0);

  /// Destructor
  ~ACE_Local_WLock (void);

  /// Dump the state of the class.
  void dump (void) const;

  /// Returns ACE_RW_Token::WLOCK.
  virtual int type (void) const;

  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;

protected:
  /// Return a new ACE_Local_Mutex.
  ACE_Tokens *create_token (const ACE_TCHAR *name);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */

#if defined (__ACE_INLINE__)
#include "ace/Local_Tokens.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_LOCAL_MUTEX_H */

