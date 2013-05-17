// -*- C++ -*-

//==========================================================================
/**
 *  @file    Null_Condition.h
 *
 *  $Id: Null_Condition.h 96076 2012-08-18 19:26:00Z johnnyw $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_NULL_CONDITION_H
#define ACE_NULL_CONDITION_H
#include /**/ "ace/pre.h"

#include "ace/Null_Mutex.h"
#include "ace/Condition_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;
class ACE_Condition_Attributes;
template <class MUTEX> class ACE_Condition;

/**
 * @brief ACE_Condition template specialization written using
 * ACE_Null_Mutexes. Implements a do nothing ACE_Condition
 * specialization, i.e., all methods are no ops.
 */
template <>
class ACE_Condition<ACE_Null_Mutex>
{
public:
  ACE_Condition (const ACE_Null_Mutex &m,
                 const ACE_TCHAR * = 0,
                 void * = 0)
    : mutex_ ((ACE_Null_Mutex &) m) {}

  ACE_Condition (const ACE_Null_Mutex &m,
                 const ACE_Condition_Attributes &,
                 const ACE_TCHAR * = 0,
                 void * = 0)
  : mutex_ ((ACE_Null_Mutex &) m) {}

  ~ACE_Condition (void) {}

  /// Returns 0.
  int remove (void) {return 0;}

  /// Returns -1 with @c errno == @c ETIME.
  int wait (const ACE_Time_Value * = 0) {errno = ETIME; return -1;}

  /// Returns -1 with @c errno == @c ETIME.
  int wait (ACE_Null_Mutex &,
            const ACE_Time_Value * = 0) {errno = ETIME; return -1;}

  /// Returns 0.
  int signal (void) {return 0;}

  /// Returns 0.
  int broadcast (void) {return 0;}
  ACE_Null_Mutex &mutex (void) {return this->mutex_;};

  /// Dump the state of an object.
  void dump (void) const {}

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  ACE_Null_Mutex &mutex_; // Reference to mutex lock.

private:
  // = Prevent assignment and initialization.
  void operator= (const ACE_Condition<ACE_Null_Mutex> &);
  ACE_Condition (const ACE_Condition<ACE_Null_Mutex> &);
};

typedef ACE_Condition<ACE_Null_Mutex> ACE_Null_Condition;

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_NULL_CONDITION_H */
