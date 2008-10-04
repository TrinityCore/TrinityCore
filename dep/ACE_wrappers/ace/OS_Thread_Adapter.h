// -*- C++ -*-

//=============================================================================
/**
 *  @file OS_Thread_Adapter.h
 *
 *  $Id: OS_Thread_Adapter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_OS_THREAD_ADAPTER_H
#define ACE_OS_THREAD_ADAPTER_H
#include /**/ "ace/pre.h"

#include "ace/Base_Thread_Adapter.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_OS_Thread_Adapter
 *
 * @brief Converts a C++ function into a function that can be
 * called from a thread creation routine
 * (e.g., pthread_create() or _beginthreadex()) that expects an
 * extern "C" entry point.  This class also makes it possible to
 * transparently provide hooks to register a thread with an
 * ACE_Thread_Manager.
 *
 * This class is used in ACE_OS::thr_create().  In general, the
 * thread that creates an object of this class is different from
 * the thread that calls invoke() on this object.  Therefore,
 * the invoke() method is responsible for deleting itself.
 */
class ACE_Export ACE_OS_Thread_Adapter : public ACE_Base_Thread_Adapter
{
public:
  /// Constructor.
  ACE_OS_Thread_Adapter (ACE_THR_FUNC user_func,
                         void *arg,
                         ACE_THR_C_FUNC entry_point = (ACE_THR_C_FUNC) ACE_THREAD_ADAPTER_NAME
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                         , ACE_SEH_EXCEPT_HANDLER selector = 0
                         , ACE_SEH_EXCEPT_HANDLER handler = 0
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                         );

  /**
   * Execute the @a user_func_ with the @a arg.  This function deletes
   * @c this, thereby rendering the object useless after the call
   * returns.
   */
  virtual ACE_THR_FUNC_RETURN invoke (void);

protected:

  /// Ensure that this object is allocated on the heap.
  ~ACE_OS_Thread_Adapter (void);

};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"
#endif /* ACE_THREAD_ADAPTER_H */
