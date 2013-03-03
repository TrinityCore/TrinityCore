// -*- C++ -*-

//=============================================================================
/**
 *  @file    Token_Manager.h
 *
 *  $Id: Token_Manager.h 91688 2010-09-09 11:21:50Z johnnyw $
 *
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_TOKEN_MANAGER_H
#define ACE_TOKEN_MANAGER_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Local_Tokens.h"

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Null_Mutex.h"
#include "ace/Map_Manager.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Local_Mutex;
class ACE_Mutex_Token;

/**
 * @class ACE_Token_Manager
 *
 * @brief Manages all tokens in a process space.
 *
 * Factory:  Proxies use the token manager to obtain token
 * references.  This allows multiple proxies to reference the same
 * logical token.
 * Deadlock detection:  Tokens use the manager to check for
 * deadlock situations during acquires.
 */
class ACE_Export ACE_Token_Manager : public ACE_Cleanup
{

  //   To add a new type of token (e.g. semaphore), do the following
  //   steps: 1. Create a new derivation of ACE_Token.  This class
  //   defines the semantics of the new Token.  2.  Create a
  //   derivation of ACE_Token_Manager.  You will only need to
  //   redefine make_mutex.
public:
  ACE_Token_Manager (void);
  virtual ~ACE_Token_Manager (void);

  /// Get the pointer to token manager singleton.
  static ACE_Token_Manager *instance (void);

  /// Set the pointer to token manager singleton.
  void instance (ACE_Token_Manager *);

  /**
   * The Token manager uses ACE_Token_Proxy::token_id_ to look for
   * an existing token.  If none is found, the Token Manager calls
   * ACE_Token_Proxy::create_token to create a new one.  When
   * finished, sets ACE_Token_Proxy::token_.  @a token_name uniquely
   * id's the token name.
   */
  void get_token (ACE_Token_Proxy *, const ACE_TCHAR *token_name);

  /**
   * Check whether acquire will cause deadlock or not.
   * returns 1 if the acquire will _not_ cause deadlock.
   * returns 0 if the acquire _will_ cause deadlock.
   * This method ignores recursive acquisition.  That is, it will not
   * report deadlock if the client holding the token requests the
   * token again.  Thus, it assumes recursive mutexes.
   */
  int check_deadlock (ACE_Token_Proxy *proxy);
  int check_deadlock (ACE_Tokens *token, ACE_Token_Proxy *proxy);

  /// Notify the token manager that a token has been released.  If as a
  /// result, there is no owner of the token, the token is deleted.
  void release_token (ACE_Tokens *&token);

  /**
   * This is to allow Tokens to perform atomic transactions.  The
   * typical usage is to acquire this mutex, check for a safe_acquire,
   * perform some queueing (if need be) and then release the lock.
   * This is necessary since safe_acquire is implemented in terms of
   * the Token queues.
   */
  ACE_TOKEN_CONST::MUTEX &mutex (void);

  /// Dump the state of the class.
  void dump (void) const;

  /// Turn debug mode on/off.
  void debug (bool d);

private:
  /// Whether to print debug messages or not.
  bool debug_;

  /// pointer to singleton token manager.
  static ACE_Token_Manager *token_manager_;

  /// Return the token that the given client_id is waiting for, if any
  ACE_Tokens *token_waiting_for (const ACE_TCHAR *client_id);

  /// ACE_Mutex_Token used to lock internal data structures.
  ACE_TOKEN_CONST::MUTEX lock_;

  /// This may be changed to a template type.
  typedef ACE_Token_Name TOKEN_NAME;

  /// COLLECTION maintains a mapping from token names to ACE_Tokens*
  typedef ACE_Map_Manager<TOKEN_NAME, ACE_Tokens *, ACE_Null_Mutex>
  COLLECTION;

  /// COLLECTION maintains a mapping from token names to ACE_Tokens*.
  COLLECTION collection_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Token_Manager.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_TOKENS_LIBRARY */

#include /**/ "ace/post.h"
#endif /* ACE_TOKEN_MANAGER_H */
