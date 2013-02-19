// -*- C++ -*-

//=============================================================================
/**
 *  @file    Token_Collection.h
 *
 *  $Id: Token_Collection.h 91688 2010-09-09 11:21:50Z johnnyw $
 *
 *  The ACE_Token class offers methods for acquiring, renewing,
 *  and releasing a synchronization token on a per-token basis.  The
 *  ACE_Token_Collection offers an interface for performing
 *  operations on groups of tokens as a whole, or on a single token
 *  within the collection.
 *
 *  The atomic group operations are not yet implemented.
 *
 *
 *  @author Douglas C. Schmidt (schmidt@cs.wustl.edu)
 *  @author Tim Harrison (harrison@cs.wustl.edu)
 */
//=============================================================================

#ifndef ACE_TOKEN_COLLECTION_H
#define ACE_TOKEN_COLLECTION_H
#include /**/ "ace/pre.h"

#include "ace/Map_Manager.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Local_Tokens.h"
#include "ace/Null_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Token_Collection
 *
 * @brief Allows atomic token group operations AND
 * provides a ACE_Token manager interface.
 *
 * There are two types of operations offered by
 * ACE_Token_Collection.  The first is atomic operations on
 * collections of Token_Proxies.  In this respect, the
 * ACE_Token_Collection can be thought of as a single token
 * consisting of multiple Token_Proxies.  The second role of the
 * ACE_Token_Collection is as a ACE_Token manager.
 * ACE_Token_Collection allows individual operations on single
 * members of a collection of Token_Proxies.  This provides a
 * single access point for operations on multiple tokens.
 *
 * @bug Although ACE_Token_Collection inherits from ACE_Token_Proxy, it
 * can not be including in a collection.  This is because <clone>
 * returns zero for now.
 *
 */
class ACE_Export ACE_Token_Collection : public ACE_Token_Proxy
{
public:
  /**
   * @a debug print out verbose debugging messages. @a name will give a
   * name to the collection.  Collections don't really need names, but
   * are sometimes useful for debugging.
   */
  ACE_Token_Collection (bool debug = false,
                        const ACE_TCHAR *name = 0);

// Collection Management operations

  /**
   * Insert a Token into the collection.  All ACE_Token type
   * operations performed on the collection will also be performed on
   * the new_proxy until it is removed.  Note that no operations
   * performed prior to the insertion will be performed.  Returns: 0
   * on success, -1 on failure with @c errno == problem.  If a token
   * proxy already exists in the collection with the same name, the
   * insertion will fail.  Also, <token> is copied.  Note that during
   * the copy, client_id's are *not* inherited.  The client ID of the
   * thread using the collection will be used.  Client ID's can be
   * changed explicity on each proxy using is_member.
   */
  int insert (ACE_Token_Proxy &token);

  /**
   * Removes the ACE_Token matching the given token_name from the
   * collection.  On success, extract returns 0. On failure
   * (token_name was not in the collection,) extract returns -1.  On
   * success, the state of the token found is copied into proxy.
   * The returned ACE_Token_Proxy* must be deleted by the user.
   */
  int extract (const ACE_TCHAR *token_name, ACE_Token_Proxy *&proxy);

  /// Returns the proxy if true.  0 otherwise.
  ACE_Token_Proxy *is_member (const ACE_TCHAR *token_name);

  /**
   * Is the specified token in the collection?
   * 1, yes.
   * 0, no.
   */
  int is_member (const ACE_Token_Proxy &token);

// = Collective operation semantics.

//   For acquire, renew, and release, there are two interfaces.  Once
//   interface allows an operation on a single token in the
//   collection.  The collective interfaces perform atomic operations
//   on the entire collection.  For instance, a collective acquire
//   will perform an acquire for each and every token in the
//   collection or the operation will fail.  Currently, these
//   operations are performed with no ordering heuristics.  That is,
//   the Collection steps through the tokens in the order they were
//   inserted.  For each one it performs the operation (acquire,
//   renew, or release).

  /**
   * Acquire "atomically" all resources in the collection.  This is
   * only successfull if all tokens in the collection could be
   * acquired.  options contains the blocking semantics, timeout
   * value, etc.  Returns: 0 on success, -1 on failure with @c errno ==
   * problem.  If and error or deadlock occurs for one of the tokens,
   * all the tokens will be released and the method will return -1.
   * Note that returning on detection of deadlock prevents livelock
   * between competing collections.  If a collection returns after
   * detecting deadlock, it is the application's responsibility to not
   * to blindly loop on the collection::acquire operation.  In other
   * words, once the collection reports deadlock, it is out of our
   * hands.
   */
  virtual int acquire (int notify = 0,
                       void (*sleep_hook)(void *) = 0,
                       ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);

  /// Acquire the token corresponding to @a token_name.  The other
  /// parameters are passed to <token>::acquire.
  virtual int acquire (const ACE_TCHAR *token_name,
                       int notify = 0,
                       void (*sleep_hook)(void *) = 0,
                       ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);

  /// Try to acquire all tokens in collection.
  virtual int tryacquire (void (*sleep_hook)(void *) = 0);

  /// Try to acquire @a token_name.
  virtual int tryacquire (const ACE_TCHAR *token_name,
                          void (*sleep_hook)(void *) = 0);

  /**
   * Renews "atomically" all resources in the collection.  This is
   * only successfull if all tokens in the collection could be
   * renewed.  options contains the blocking semantics, timeout
   * value, etc.  Returns: 0 on success, -1 on failure with @c errno ==
   * problem.
   */
  virtual int renew (int requeue_position = 0,
                     ACE_Synch_Options &options =
                     ACE_Synch_Options::defaults);


  /// Renew the token corresponding to @a token_name.  The other
  /// parameters are passed to <token>::renew.
  virtual int renew (const ACE_TCHAR *token_name,
                     int requeue_position = 0,
                     ACE_Synch_Options &options =
                     ACE_Synch_Options::defaults);

  /**
   * Releases "atomically" all resources in the collection.  This is
   * only successfull if all tokens in the collection could be
   * released.  options contains the blocking semantics, timeout
   * value, etc.  Returns: 0 on success, -1 on failure with @c errno ==
   * problem.
   */
  virtual int release (ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);


  /// Release the token corresponding to <token_name>.  The other
  /// parameters are passed to <token>::release.
  virtual int release (const ACE_TCHAR *token_name,
                       ACE_Synch_Options &options =
                       ACE_Synch_Options::defaults);

  ~ACE_Token_Collection (void);

  /// Dump the state of the class.
  void dump (void) const;

  /// Return the name of the collection.  Not very functionally
  /// important, but sometimes a useful debugging tool.
  virtual const ACE_TCHAR *name (void) const;

protected:

  typedef ACE_Token_Name TOKEN_NAME;

  /// COLLECTION maintains a mapping from token names to ACE_Tokens*
  typedef ACE_Map_Manager<TOKEN_NAME, ACE_Token_Proxy *, ACE_Null_Mutex>
    COLLECTION;

  /// COLLECTION maintains a mapping from token names to ACE_Tokens*.
  COLLECTION collection_;

  /// Whether to print out debug messages or not.
  bool debug_;

  /// Name of the collection.
  ACE_TCHAR name_[ACE_MAXTOKENNAMELEN];

  // = I'm not sure what these mean, but they have to be defined since they're
  //   pure virtual in ACE_Token_Proxy.
  virtual ACE_Token_Proxy *clone (void) const;
  virtual ACE_Tokens *create_token (const ACE_TCHAR *name);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Token_Collection.inl"
#endif /* __ACE_INLINE__ */

#endif /* ACE_HAS_TOKENS_LIBRARY */

#include /**/ "ace/post.h"
#endif /* ACE_TOKEN_COLLECTION_H */
