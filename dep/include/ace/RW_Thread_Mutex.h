// -*- C++ -*-

//==========================================================================
/**
 *  @file    RW_Thread_Mutex.h
 *
 *  $Id: RW_Thread_Mutex.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_RW_THREAD_MUTEX_H
#define ACE_RW_THREAD_MUTEX_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_HAS_THREADS)
#  include "ace/Null_Mutex.h"
#else /* ACE_HAS_THREADS */
// ACE platform supports some form of threading.

#include "ace/RW_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_RW_Thread_Mutex
 *
 * @brief Wrapper for readers/writer locks that exist within a process.
 */
class ACE_Export ACE_RW_Thread_Mutex : public ACE_RW_Mutex
{
public:
  ACE_RW_Thread_Mutex (const ACE_TCHAR *name = 0,
                       void *arg = 0);

  /// Default dtor.
  ~ACE_RW_Thread_Mutex (void);

  /**
   * Conditionally upgrade a read lock to a write lock.  This only
   * works if there are no other readers present, in which case the
   * method returns 0.  Otherwise, the method returns -1 and sets
   * @c errno to @c EBUSY.  Note that the caller of this method *must*
   * already possess this lock as a read lock (but this condition is
   * not checked by the current implementation).
   */
  int tryacquire_write_upgrade (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/RW_Thread_Mutex.inl"
#endif /* __ACE_INLINE__ */

#endif /* !ACE_HAS_THREADS */

#include /**/ "ace/post.h"
#endif /* ACE_RW_THREAD_MUTEX_H */

