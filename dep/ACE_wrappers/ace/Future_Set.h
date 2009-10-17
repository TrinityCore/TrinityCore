// -*- C++ -*-

//=============================================================================
/**
 *  @file    Future_Set.h
 *
 *  $Id: Future_Set.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author John Tucker <jtucker@infoglide.com>
 */
//=============================================================================

#ifndef ACE_FUTURE_SET_H
#define ACE_FUTURE_SET_H
#include /**/ "ace/pre.h"

#include "ace/Thread.h"
#include "ace/Message_Queue.h"
#include "ace/Future.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Future_Set
 *
 * @brief This class implements a mechanism which allows the values of
 * a collection of ACE_Future objects to be accessed by reader threads
 * as they become available.  The caller(s) provide the ACE_Future_Set
 * (i.e. the observer...) with the collection of ACE_Future objects
 * (i.e. the subjects...) that are to be observed using the
 * the ACE_Future_Set::insert() method.  The caller(s) may then iterate
 * over the collection in the order in which they become readable using
 * the ACE_Future_Set::next_readable() method.
 */
template <class T>
class ACE_Future_Set : public ACE_Future_Observer<T>
{
public:
  // = Initialization and termination methods.

  /// Constructor.
  ACE_Future_Set (ACE_Message_Queue<ACE_SYNCH> *future_notification_queue_ = 0);

  /// Destructor.
  ~ACE_Future_Set (void);

  /**
   * Return 1 if their are no ACE_Future objects left on its queue and
   * 0 otherwise.
   *
   * When an ACE_Future_Set has no ACE_Future>subjects to observe it is
   * empty. The ACE_Future_Set is in the empty state when either the caller(s)
   * have retrieved every readable ACE_Future subject assigned the
   * ACE_Future_Set via the ACE_Future_Set::next_readable() method,
   * or when the ACE_Future_Set has not been assigned any subjects.
   */
  int is_empty (void) const;

  /**
   * Enqueus the given ACE_Future into this objects queue when it is
   * readable.
   *
   * Returns 0 if the future is successfully inserted, 1 if the
   * future is already inserted, and -1 if failures occur.
   */
  int insert (ACE_Future<T> &future);

  /**
   * Wait up to @a tv time to get the @a value.  Note that @a tv must be
   * specified in absolute time rather than relative time.); get the
   * next ACE_Future that is readable.  If @a tv = 0, the will block
   * forever.
   *
   * If a readable future becomes available, then the input
   * ACE_Future object param will be assigned with it and 1 will
   * be returned.  If the ACE_Future_Set is empty (i.e. see definition
   * of ACE_Future_Set::is_empty()), then 0 is returned.
   *
   * When a readable ACE_Future object is retrieved via the
   * ACE_Future_Set::next_readable() method, the ACE_Future_Set will
   * remove that ACE_Future object from its list of subjects.
   */
  int next_readable (ACE_Future<T> &result,
                     ACE_Time_Value *tv = 0);

  /// Called by the ACE_Future subject in which we are subscribed to
  /// when its value is written to.
  virtual void update (const ACE_Future<T> &future);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Future_Set<T> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Future_Set (const ACE_Future_Set<T> &))

  typedef ACE_Future<T> FUTURE;

  typedef ACE_Future_Rep<T> FUTURE_REP;

  typedef ACE_Future_Holder<T> FUTURE_HOLDER;

  typedef ACE_Pointer_Hash<FUTURE_REP *> FUTURE_REP_HASH;

  typedef ACE_Equal_To<FUTURE_REP *> FUTURE_REP_COMPARE;

  typedef ACE_Hash_Map_Manager_Ex<FUTURE_REP *,
                                  FUTURE_HOLDER *,
                                  FUTURE_REP_HASH,
                                  FUTURE_REP_COMPARE,
                                  ACE_Null_Mutex> FUTURE_HASH_MAP;

  /// Map of <ACE_Futures>, subjects, which have not been written to by
  /// client's writer thread.
  FUTURE_HASH_MAP future_map_;

  /// Message queue for notifying the reader thread of <ACE_Futures> which
  /// have been written to by client's writer thread.
  ACE_Message_Queue<ACE_SYNCH> *future_notification_queue_;

  /// Keeps track of whether we need to delete the message queue.
  bool delete_queue_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Future_Set.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Future_Set.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* ACE_HAS_THREADS */
#include /**/ "ace/post.h"
#endif /* ACE_FUTURE_SET_H */

