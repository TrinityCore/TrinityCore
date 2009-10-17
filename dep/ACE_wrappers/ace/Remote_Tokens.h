// -*- C++ -*-
//=============================================================================
/**
 *  @file    Remote_Tokens.h
 *
 *  $Id: Remote_Tokens.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 */
//=============================================================================
#ifndef ACE_REMOTE_MUTEX_H
#define ACE_REMOTE_MUTEX_H
#include /**/ "ace/pre.h"
#include "ace/INET_Addr.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/SOCK_Connector.h"
#include "ace/SOCK_Stream.h"
#include "ace/Synch_Options.h"
#include "ace/Local_Tokens.h"
#include "ace/Token_Request_Reply.h"
#if defined (ACE_HAS_TOKENS_LIBRARY)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Remote_Token_Proxy
 *
 * @brief Proxy for acquiring, renewing, and releasing a distributed
 * synchronization token.
 *
 * The Remote_Token_Proxy class implements the mechanisms for
 * distributed token operations.  It is similar to the
 * ACE_Token_Proxy.
 * = BUGS
 * Distributed sleep_hooks have not been implemented.  <owner_id>
 * is not implemented.
 */
class ACE_Export ACE_Remote_Token_Proxy : public ACE_Token_Proxy
{
public:
  /// Null construction.
  ACE_Remote_Token_Proxy (void);
  /// Death.
  virtual ~ACE_Remote_Token_Proxy (void);
  /**
   * Same as Token_Proxy. @a name is the string uniquely identifying
   * the token.  <ignore_deadlock> can be 1 to disable deadlock
   * notifications.  <debug> prints debug messages.
   */
  int open (const ACE_TCHAR *name,
            int ignore_deadlock = 0,
            int debug = 0);

  /**
   * Open a connection with the token server.  This only need be used
   * when the user wishes to explicitly open a connection to check if
   * the server exists.  Connections are stored in the
   * ACE_Token_Connections singleton as thread-specific data.  That
   * is, every thread has only one connection that is used for all
   * remote tokens.
   */
  int initiate_connection (void);
  /**
   * Acquire the distributed token.  If notify is specified and the
   * token is already held, the owner is notified.  options contains
   * the timeout value for the acquire call.  The timer is kept at the
   * token server.  Asynchronous operations are not supported.
   * Returns 0 on success, -1 on failure with @c errno == problem.
   */
  virtual int acquire (int notify = 0,
                       void (*sleep_hook)(void *) = 0,
                       ACE_Synch_Options &options =
                       ACE_Synch_Options::synch);
  /**
   * Try to acquire the distributed token.  If the token is already
   * held, the call returns without queueing the caller as a waiter.
   * Returns 0 on success (the token was acquired), and -1 with
   * EWOULDBLOCK if the token was already held.
   */
  virtual int tryacquire (void (*sleep_hook)(void *) = 0);
  /**
   * Renew the token by offering to release it if there are any other
   * waiters, otherwise get the token back immediately.  This renew
   * has the same semantics as ACE_Local_Mutex release.  It is
   * semantically equivalent to <release> followed by <acquire>, but
   * it is faster.  options contains the timeout value used if renew
   * blocks.  As with acquire, the timer is maintained at the token
   * server.  If there are waiters and requeue_position == -1, the
   * caller is queued at the rear of the waiter list.  Otherwise,
   * requeue_position specifies the number of waiters to "let by"
   * before reacquiring the token (effectively, the position in the
   * waiter list.)
   */
  virtual int renew (int requeue_position = 0,
                     ACE_Synch_Options &options =
                     ACE_Synch_Options::synch);
  /**
   * Release the distributed token. Similar to ACE_Local_Mutex, if the
   * caller is not the owner, it is removed from the waiter list (if
   * applicable.) Returns 0 on success, -1 on failure with @c errno ==
   * problem.
   */
  virtual int release (ACE_Synch_Options &options =
                       ACE_Synch_Options::synch);
  /// Become interface compliant for ACE_Guard<>.  This has no
  /// functionality.
  virtual int remove (ACE_Synch_Options &options =
                      ACE_Synch_Options::synch);
  /// Override the default to do nothing.
  virtual void token_acquired (ACE_TPQ_Entry *);
  /// The client id of the current token holder
  virtual const ACE_TCHAR* owner_id (void);
  /**
   * Sets the server address for all instances of ACE_Remote_Token_Proxy
   * If this isn't called, the environment variable TOKEN_SERVER is
   * checked for the server address.  If that is not specified, all
   * ACE_Remote_** operations will fail.
   */
  static void set_server_address (const ACE_INET_Addr &server_address);
  /// Dump the state of the class.
  void dump (void) const;
protected:
  /// If shadows report deadlock, go remote anyway
  int ignore_shadow_deadlock_;
  /// Perform the request and wait for the reply.
  int request_reply (ACE_Token_Request &request,
                     ACE_Synch_Options &options);
};
/**
 * @class ACE_Remote_Mutex
 *
 * @brief Proxy for acquiring, renewing, and releasing a distributed
 * mutex.
 *
 * This is the remote equivalent to ACE_Local_Mutex.  The
 * Remote_Mutex class offers methods for acquiring, renewing, and
 * releasing a distributed synchronization mutex.  Similar to
 * ACE_Local_Mutex, ACE_Remote_Token_Proxy offers recursive
 * acquisition, FIFO waiter ordering, and deadlock detection.  It
 * depends on the Token Server for its distributed synchronization
 * semantics.
 */
class ACE_Export ACE_Remote_Mutex : public ACE_Remote_Token_Proxy
{
public:
  /// Null creation.  Remote_Token_Proxy::open must be called.
  ACE_Remote_Mutex (void);
  /// Calls Remote_Token_Proxy::open for you.
  ACE_Remote_Mutex (const ACE_TCHAR *token_name,
                    int ignore_deadlock = 0,
                    int debug = 0);
  /// Dump the state of the class.
  void dump (void) const;
  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;
protected:
  /// Make the correct type of ACE_Tokens.
  /// This is called by the ACE_Token_Manager.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};
/**
 * @class ACE_Remote_RLock
 *
 * @brief Proxy for acquiring, renewing, and releasing a distributed
 * readers lock.
 *
 * This is the remote equivalent to ACE_Local_RLock. Multiple
 * readers can hold the lock simultaneously when no writers have
 * the lock.  Alternatively, when a writer holds the lock, no other
 * participants (readers or writers) may hold the lock.
 * ACE_Remote_RLock depends on the ACE Token Server for its
 * distributed synchronization semantics.
 */
class ACE_Export ACE_Remote_RLock : public ACE_Remote_Token_Proxy
{
public:
  ACE_Remote_RLock (void);
  ACE_Remote_RLock (const ACE_TCHAR *token_name,
                    int ignore_deadlock = 0,
                    int debug = 0);
  ACE_Remote_RLock (const ACE_Remote_RLock &mutex);
  /// Dump the state of the class.
  void dump (void) const;
  /// Returns ACE_RW_Token::RLOCK;
  virtual int type (void) const;
  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;
protected:
  /// Make the correct type of ACE_Tokens.  This is called by the Token
  /// Manager.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};
/**
 * @class ACE_Remote_WLock
 *
 * @brief Proxy for acquiring, renewing, and releasing a distributed
 * writers lock.
 *
 * Shields applications from details of interacting with the
 * ACE_Token_Server.  The token_name_ is just the string that the
 * Token Server uses to identify the token.  The client_id_ (also
 * used by the Token Server,) identifies the owner of the token and
 * is used for deadlock detection.
 */
class ACE_Export ACE_Remote_WLock : public ACE_Remote_Token_Proxy
{
public:
  ACE_Remote_WLock (void);
  ACE_Remote_WLock (const ACE_TCHAR *token_name,
                    int ignore_deadlock = 0,
                    int debug = 0);
  ACE_Remote_WLock (const ACE_Remote_WLock &mutex);
  /// Dump the state of the class.
  void dump (void) const;
  /// Returns ACE_RW_Token::WLOCK;
  virtual int type (void) const;
  /// Return deep copy.
  virtual ACE_Token_Proxy *clone (void) const;
protected:
  /// Make the correct type of ACE_Tokens.  This is called by the Token
  /// Manager.
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};
/**
 * @class ACE_TSS_Connection
 *
 * @brief Class for providing a connection per thread.
 *
 * ACE_TSS_Connection provides a single access point for all
 * threads to access thread-specific connections.  This prevents
 * resource-sharing problems such as thread serialization.
 */
class ACE_Export ACE_TSS_Connection : public ACE_TSS<ACE_SOCK_Stream>
{
public:
  // Necessary to make some compilers work...
  ACE_TSS_Connection (void);
  ~ACE_TSS_Connection (void);
  /// Retrieve the thread's connection
  ACE_SOCK_Stream *get_connection (void);
  /// Factory Method that creates a new SOCK Stream.
  virtual ACE_SOCK_Stream *make_TSS_TYPE (void) const;
  /// Inheritence and operator overloading don't mix.  Redefine this
  /// from ACE_TSS so that we can use it.
  operator ACE_SOCK_Stream *(void);
  /// Set the server address.
  static void set_server_address (const ACE_INET_Addr &server_address);
  /// Dump the state of the class.
  void dump (void) const;
protected:
  /// The address of the Token Server used by all instances of
  /// Token_Proxy.
  static ACE_INET_Addr server_address_;
private:
  /// Private: should not be used
  ACE_TSS_Connection (const ACE_TSS_Connection &);
  void operator= (const ACE_TSS_Connection &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_TOKENS_LIBRARY */
#if defined (__ACE_INLINE__)
#include "ace/Remote_Tokens.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_REMOTE_TOKEN_H */

