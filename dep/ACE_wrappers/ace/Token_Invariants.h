// -*- C++ -*-

//=============================================================================
/**
 *  @file    Token_Invariants.h
 *
 *  $Id: Token_Invariants.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 *
 *   Allows applications to test that invariants are always
 *   satisfied.  Can test mutexes and readers/writer locks.  Does
 *   not test recursive acquisition.
 *
 *
 */
//=============================================================================

#ifndef ACE_TOKEN_INVARIANTS_H
#define ACE_TOKEN_INVARIANTS_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Map_Manager.h"
#include "ace/Local_Tokens.h"
#include "ace/Null_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Mutex_Invariants
 *
 * @brief Mutex Invariants
 * = INVARIANTS
 * 1. Only one owner at a time.
 */
class ACE_Export ACE_Mutex_Invariants
{
public:
  /// Default construction.
  ACE_Mutex_Invariants (void);

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int acquired (void);

  /// Updates internal database.
  void releasing (void);

  // = Map_Manager operations.

  /// Copy construction.
  ACE_Mutex_Invariants (const ACE_Mutex_Invariants &rhs);

  /// Copy.
  void operator= (const ACE_Mutex_Invariants &rhs);

  /// Dump the state of the class.
  void dump (void) const;

private:
  /// Number of owners.  This had better be 0 >= owners_ <= 1;
  int owners_;
};

/**
 * @class ACE_RWLock_Invariants
 *
 * @brief RWLock Invariants
 *
 * Preserve the following invariants:
 * -# Only one writer at a time.
 * -# If there is an owning writer, there are no owning readers.
 */
class ACE_Export ACE_RWLock_Invariants
{
public:
  /// Default construction.
  ACE_RWLock_Invariants (void);

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int writer_acquired (void);

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int reader_acquired (void);

  /// Updates internal database.
  void releasing (void);

  // = Map_Manager operations.

  /// Copy construction.
  ACE_RWLock_Invariants (const ACE_RWLock_Invariants &rhs);

  /// Copy.
  void operator= (const ACE_RWLock_Invariants &rhs);

  /// Dump the state of the class.
  void dump (void) const;

private:
  /// Number of owning writers.
  int writers_;

  /// Number of owning readers.
  int readers_;
};

/**
 * @class ACE_Token_Invariant_Manager
 *
 * @brief Token Invariants
 *
 * The Token Invariant Manager allows applications to test that
 * invariants are always satisfied.  Currently, Token_Invariants
 * can test mutexes and readers/writer locks.  Does not test
 * recursive acquisition.
 * Note that this class does not ever clean its database.  Until
 * destroyed, it's size will forever increase.
 */
class ACE_Export ACE_Token_Invariant_Manager : public ACE_Cleanup
{
public:

  /// Singleton access point.
  static ACE_Token_Invariant_Manager *instance (void);

  // = Polymorphic methods.  Just pass in the proxy and the method
  // figures out the type of the token.

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int acquired (const ACE_Token_Proxy *proxy);

  /// Updates internal database.
  void releasing (const ACE_Token_Proxy *proxy);

  // = Explicit methods.  These to not require actual proxies in order
  // to test a scenario.

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int mutex_acquired (const ACE_TCHAR *token_name);

  /// Updates internal database.
  void mutex_releasing (const ACE_TCHAR *token_name);

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int reader_acquired (const ACE_TCHAR *token_name);

  /// Returns 1 on success, 0 when an invariant has been violated and
  /// -1 on error.
  int writer_acquired (const ACE_TCHAR *token_name);

  /// Updates internal database.
  void rwlock_releasing (const ACE_TCHAR *token_name);

  /// Dump the state of the class.
  void dump (void) const;

  // = The following two method should be in the protected part of the
  //   class.  Bugs with certain compilers preclude this.
  /// Prevent non-singleton construction.
  ACE_Token_Invariant_Manager (void);

  /// Destruction.
  virtual ~ACE_Token_Invariant_Manager (void);

protected:
  /// Return or create.
  int get_mutex (const ACE_TCHAR *token_name,
                 ACE_Mutex_Invariants *&inv);

  /// Return or create.
  int get_rwlock (const ACE_TCHAR *token_name,
                  ACE_RWLock_Invariants *&inv);

  /// ACE_Mutex_Token used to lock internal data structures.
  ACE_TOKEN_CONST::MUTEX lock_;

  /// This may be changed to a template type.
  typedef ACE_Token_Name TOKEN_NAME;

  /// COLLECTION maintains a mapping from token names to mutexes.
  typedef ACE_Map_Manager<TOKEN_NAME, ACE_Mutex_Invariants *, ACE_Null_Mutex>
    MUTEX_COLLECTION;

  /// Allows iterations through collection.
  /**
   * @deprecated Deprecated typedef.  Use MUTEX_COLLECTION::ITERATOR trait
   * instead.
   */
  typedef MUTEX_COLLECTION::ITERATOR MUTEX_COLLECTION_ITERATOR;

  /// Allows iterations through collection.
  /**
   * @deprecated Deprecated typedef.  Use MUTEX_COLLECTION::ENTRY trait
   * instead.
   */
  typedef MUTEX_COLLECTION::ENTRY MUTEX_COLLECTION_ENTRY;

  /// MUTEX_COLLECTION maintains a mapping from token names to mutexes.
  MUTEX_COLLECTION mutex_collection_;

  /// COLLECTION maintains a mapping from token names to mutexes.
  typedef ACE_Map_Manager<TOKEN_NAME, ACE_RWLock_Invariants *, ACE_Null_Mutex>
    RWLOCK_COLLECTION;

  /// Allows iterations through collection.
  /**
   * @deprecated Deprecated typedef.  Use RWLOCK_COLLECTION::ITERATOR trait
   * instead.
   */
  typedef RWLOCK_COLLECTION::ITERATOR RWLOCK_COLLECTION_ITERATOR;

  /// Allows iterations through collection.
  /**
   * @deprecated Deprecated typedef.  Use RWLOCK_COLLECTION::ENTRY trait
   * instead.
   */
  typedef RWLOCK_COLLECTION::ENTRY RWLOCK_COLLECTION_ENTRY;

  /// MUTEX_COLLECTION maintains a mapping from token names to mutexes.
  RWLOCK_COLLECTION rwlock_collection_;

  /// Singleton pointer.
  static ACE_Token_Invariant_Manager *instance_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */

#include /**/ "ace/post.h"
#endif /* ACE_TOKEN_INVARIANTS_H */

