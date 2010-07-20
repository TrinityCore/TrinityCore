// -*- C++ -*-

//==========================================================================
/**
 *  @file    Null_Condition.h
 *
 *  $Id: Null_Condition.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *   Moved from Synch.h.
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_NULL_CONDITION_H
#define ACE_NULL_CONDITION_H
#include /**/ "ace/pre.h"

// All methods in this class are inline, so there is no
// need to import or export on Windows. -- CAE 12/18/2003
#include "ace/Null_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Null_Condition
 *
 * @brief Implement a do nothing ACE_Condition variable wrapper,
 * i.e., all methods are no ops.  This class is necessary since
 * some C++ compilers are *very* lame...
 */
class ACE_Null_Condition
{
public:
  ACE_Null_Condition (const ACE_Null_Mutex &m,
                      const ACE_TCHAR * = 0,
                      void * = 0)
    : mutex_ ((ACE_Null_Mutex &) m) {}

  ~ACE_Null_Condition (void) {}

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
  void operator= (const ACE_Null_Condition &);
  ACE_Null_Condition (const ACE_Null_Condition &);
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_NULL_CONDITION_H */
