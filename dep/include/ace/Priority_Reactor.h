// -*- C++ -*-

//=============================================================================
/**
 *  @file    Priority_Reactor.h
 *
 *  $Id: Priority_Reactor.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_PRIORITY_REACTOR_H
#define ACE_PRIORITY_REACTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Select_Reactor.h"
#include "ace/Unbounded_Queue.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Priority_Reactor
 *
 * @brief Implements priority based dispatching.
 *
 * This class refines the dispatching mechanism for the
 * Select_Reactor by taking advantage of the priority method on
 * ACE_Event_Handler.
 */
class ACE_Export ACE_Priority_Reactor : public ACE_Select_Reactor
{
public:
  // = Initialization and termination methods.

  /// Initialize ACE_Priority_Reactor with the default size.
  ACE_Priority_Reactor (ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0);

  /// Initialize ACE_Priority_Reactor with size @a size.
  ACE_Priority_Reactor (size_t size,
                        int restart = 0,
                        ACE_Sig_Handler * = 0,
                        ACE_Timer_Queue * = 0);

  /// Close down the select_reactor and release all of its resources.
  virtual ~ACE_Priority_Reactor (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = Dispatching methods.

  /// We simply override this function to implement the priority
  /// dispatching.
  virtual int dispatch_io_set (int number_of_active_handles,
                               int &number_dispatched,
                               int mask,
                               ACE_Handle_Set &dispatch_mask,
                               ACE_Handle_Set &ready_mask,
                               ACE_EH_PTMF callback);

private:
  /// A small helper to initialize the bucket.
  void init_bucket (void);

  /// Build the bucket from the given dispatch_mask.  Return -1 on
  /// failure, 0 otherwise.
  int build_bucket (ACE_Handle_Set& dispatch_mask,
                     int &min_priority,
                     int &max_priority);

  /// There is a queue per-priority, which simply holds the
  /// Event_Handlers until we know who goes first.
  typedef ACE_Unbounded_Queue<ACE_Event_Tuple> QUEUE;
  QUEUE** bucket_;

  /// The queues themselves use this allocator to minimize dynamic
  /// memory usage.
  ACE_Allocator* tuple_allocator_;

  /// Deny access since member-wise won't work...
  ACE_Priority_Reactor (const ACE_Priority_Reactor &);
  ACE_Priority_Reactor &operator = (const ACE_Priority_Reactor &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_PRIORITY_REACTOR_H */

