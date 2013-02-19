// -*- C++ -*-

//=============================================================================
/**
 *  @file    Process_Mutex.h
 *
 *  $Id: Process_Mutex.h 87179 2009-10-20 16:27:01Z shuston $
 *
 *   A wrapper for mutexes that can be used across processes on the
 *   same host machine, as well as within a process, of course.
 *
 * @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================

#ifndef ACE_PROCESS_MUTEX_H
#define ACE_PROCESS_MUTEX_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// To make it easier to carry the setting though this file as well as
// Process_Mutex.{cpp inl}, set a private macro here.
#ifdef _ACE_USE_SV_SEM
#  undef _ACE_USE_SV_SEM
#endif /* _ACE_USE_SV_SEM */

#if defined (ACE_HAS_SYSV_IPC) && !defined (ACE_USES_MUTEX_FOR_PROCESS_MUTEX)
#  include "ace/SV_Semaphore_Complex.h"
#  define _ACE_USE_SV_SEM
#else
#  include "ace/Mutex.h"
#endif /* ACE_HAS_SYSV_IPC && !ACE_USES_MUTEX_FOR_PROCESS_MUTEX */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declarations
class ACE_Time_Value;

/**
 * @class ACE_Process_Mutex
 *
 * @brief A wrapper for mutexes that can be used across processes on
 * the same host machine, as well as within a process, of course.
 *
 * @attention The mechanism upon which @c ACE_Process_Mutex is based
 * can be configured at build time to be either @c ACE_SV_Semaphore_Complex
 * (on platforms that support it) or @c ACE_Mutex. On platforms that offer
 * System V IPC (the @c ACE_HAS_SYSV_IPC config macro is defined)
 * @c ACE_SV_Semaphore_Complex is the default because it is more convenient
 * and easy to use. @c ACE_Mutex is the default on all other platforms.
 * On platforms where ACE_SV_Semaphore_Complex is used by default, the
 * mechanism can be changed to ACE_Mutex when ACE is built by adding
 * @code
 *   #define ACE_USES_MUTEX_FOR_PROCESS_MUTEX
 * @endcode
 * to your @c config.h file.
 * @par
 * Consider these tradeoffs when evaluating whether or not to change
 * the default:
 *   - Some platforms (e.g., Pthreads and UI Threads) require interprocess
 *     mutexes to be allocated from shared memory. On these platforms, using
 *     ACE_Mutex as the underlying mechanism requires that ACE_Process_Mutex
 *     objects be allocated in shared memory. Using ACE_SV_Semaphore_Complex
 *     avoids this restriction.
 *   - System V IPC kernel parameters have a low default limit on some
 *     platforms. This would restrict the number of ACE_Process_Mutex objects
 *     that can be in use simultaneously when using ACE_SV_Semaphore_Complex.
 *   - If you require the ability to do a timed @c acquire(), you must
 *     use ACE_Mutex as the underlying mechanism because timed acquire does not
 *     work with System V semaphores.
 *   - When using ACE_Mutex on a Pthreads-based platform, an ACE_Process_Mutex
 *     object is deleted when the process which created the object destroys
 *     it, regardless of whether or not there are other processes still
 *     accessing the ACE_Process_Mutex. Using ACE_SV_Semaphore_Complex avoids
 *     this problem; the semaphore is destroyed when the last use of the
 *     object ends. For portable applications it is better to always ensure
 *     that the owner of the mutex destroys it after all other processes have
 *     stopped using it.
 */
class ACE_Export ACE_Process_Mutex
{
public:
  /**
   * Create an ACE_Process_Mutex.
   *
   * @param name optional, null-terminated string containing the name of
   * the object. Multiple users of the same @c ACE_Process_Mutex must use
   * the same name to access the same object.  If not specified, a name
   * is generated.
   * @param arg optional, attributes to be used to initialize the mutex.
   * If using @c ACE_SV_Semaphore_Complex as the underlying mechanism,
   * this argument is ignored.
   * @param mode optional, the protection mode for either the backing store
   * file (for ACE_Mutex use) or the ACE_SV_Semaphore_Complex that's created.
   */
  ACE_Process_Mutex (const char *name = 0,
                     void *arg = 0,
                     mode_t mode = ACE_DEFAULT_FILE_PERMS);

#if defined (ACE_HAS_WCHAR)
  /**
   * Create an ACE_Process_Mutex (@c wchar_t version)
   *
   * @param name optional, null-terminated string containing the name of
   * the object. Multiple users of the same @c ACE_Process_Mutex must use
   * the same name to access the same object. If not specified, a name
   * is generated.
   * @param arg optional, attributes to be used to initialize the mutex.
   * If using @c ACE_SV_Semaphore_Complex as the underlying mechanism,
   * this argument is ignored.
   * @param mode optional, the protection mode for either the backing store
   * file (for ACE_Mutex use) or the ACE_SV_Semaphore_Complex that's created.
   */
  ACE_Process_Mutex (const wchar_t *name,
                     void *arg = 0,
                     mode_t mode = ACE_DEFAULT_FILE_PERMS);
#endif /* ACE_HAS_WCHAR */

  /**
   * Destructor.
   *
   * @note The destructor will not release an acquired mutex except
   * on Windows.
   */
  ~ACE_Process_Mutex (void);

  /**
   * Explicitly destroy the mutex.  Note that only one thread should
   * call this method since it doesn't protect against race
   * conditions.
   *
   * @return 0 on success; -1 on failure.
   */
  int remove (void);

  /**
   * Acquire lock ownership (wait on queue if necessary).
   *
   * @return 0 on success; -1 on failure.
   */
  int acquire (void);

  /**
   * Acquire lock ownership, but timeout if lock if hasn't been
   * acquired by given time.
   *
   * @param tv the absolute time until which the caller is willing to
   * wait to acquire the lock.
   *
   * @return 0 on success; -1 on failure.
   */
  int acquire (ACE_Time_Value &tv);

  /**
   * Conditionally acquire lock (i.e., don't wait on queue).
   *
   * @return 0 on success; -1 on failure.  If the lock could not be acquired
   * because someone else already had the lock, @c errno is set to @c EBUSY.
   */
  int tryacquire (void);

  /// Release lock and unblock a thread at head of queue.
  int release (void);

  /// Acquire lock ownership (wait on queue if necessary).
  int acquire_read (void);

  /// Acquire lock ownership (wait on queue if necessary).
  int acquire_write (void);

  /**
   * Conditionally acquire a lock (i.e., won't block).  Returns -1 on
   * failure.  If we "failed" because someone else already had the
   * lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_read (void);

  /**
   * Conditionally acquire a lock (i.e., won't block).  Returns -1 on
   * failure.  If we "failed" because someone else already had the
   * lock, @c errno is set to @c EBUSY.
   */
  int tryacquire_write (void);

  /**
   * This is only here for consistency with the other synchronization
   * APIs and usability with Lock adapters. Assumes the caller already has
   * acquired the mutex and returns 0 in all cases.
   */
  int tryacquire_write_upgrade (void);

#if !defined (_ACE_USE_SV_SEM)
  /// Return the underlying mutex.
  const ACE_mutex_t &lock (void) const;
#endif /* !_ACE_USE_SV_SEM */

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// If the user does not provide a name we generate a unique name in
  /// this buffer.
  ACE_TCHAR name_[ACE_UNIQUE_NAME_LEN];

  /// Create and return the unique name.
  const ACE_TCHAR *unique_name (void);

#if defined (_ACE_USE_SV_SEM)
  /// We need this to get the right semantics...
  ACE_SV_Semaphore_Complex lock_;
#else
  ACE_Mutex lock_;
#endif /* _ACE_USE_SV_SEM */
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Process_Mutex.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ACE_PROCESS_MUTEX_H */
