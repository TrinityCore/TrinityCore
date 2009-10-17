// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_pthread.h
 *
 *  threads
 *
 *  $Id: os_pthread.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_PTHREAD_H
#define ACE_OS_INCLUDE_OS_PTHREAD_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_PRIOCNTL)
   // Need to #include thread.h before #defining THR_BOUND, etc.,
   // when building without threads on SunOS 5.x.
#  if defined (sun)
#    include /**/ <thread.h>
#  endif /* sun */

   // Need to #include these before #defining USYNC_PROCESS on SunOS 5.x.
#  include /**/ <sys/rtpriocntl.h>
#  include /**/ <sys/tspriocntl.h>
#endif /* ACE_HAS_PRIOCNTL */

#include "ace/os_include/sys/os_types.h"

// This needs to go here *first* to avoid problems with AIX.
# if defined (ACE_HAS_PTHREADS)
#   define ACE_DONT_INCLUDE_ACE_SIGNAL_H
#     include "ace/os_include/os_signal.h"
#   undef ACE_DONT_INCLUDE_ACE_SIGNAL_H
#   if defined (DIGITAL_UNIX)
#     define pthread_self __pthread_self
extern "C" pthread_t pthread_self (void);
#   endif /* DIGITAL_UNIX */
# endif /* ACE_HAS_PTHREADS */


#if !defined (ACE_LACKS_PTHREAD_H)
   extern "C" {
#   if defined (ACE_TANDEM_T1248_PTHREADS)
#   include /**/ <spthread.h>
#   else
#  include /**/ <pthread.h>
#   endif
   }
#endif /* !ACE_LACKS_PTHREAD_H */

#if defined (ACE_HAS_PTHREAD_NP_H)
// FreeBSD declares _np (non-portable) pthread extensions in <pthread_np.h>
#  include /**/ <pthread_np.h>
#endif

// @todo: need to reoganize to put includes at the top and the rest of the
// code at the bottom.  Also, move the classes out of this file.
#if defined (ACE_HAS_PTHREADS)
#  define ACE_SCHED_OTHER SCHED_OTHER
#  define ACE_SCHED_FIFO SCHED_FIFO
#  define ACE_SCHED_RR SCHED_RR

// Definitions for THREAD- and PROCESS-LEVEL priorities...some
// implementations define these while others don't.  In order to
// further complicate matters, we don't redefine the default (*_DEF)
// values if they've already been defined, which allows individual
// programs to have their own ACE-wide "default".

// PROCESS-level values
#  if (defined (_POSIX_PRIORITY_SCHEDULING) || defined (ACE_TANDEM_T1248_PTHREADS)) \
   && !defined(_UNICOS) && !defined(UNIXWARE_7_1)
#    define ACE_PROC_PRI_FIFO_MIN  (sched_get_priority_min(SCHED_FIFO))
#    define ACE_PROC_PRI_RR_MIN    (sched_get_priority_min(SCHED_RR))
#    if defined (HPUX)
       // HP-UX's other is the SCHED_HPUX class, which uses historical
       // values that have reverse semantics from POSIX (low value is
       // more important priority). To use these in pthreads calls,
       // the values need to be converted. The other scheduling classes
       // don't need this special treatment.
#      define ACE_PROC_PRI_OTHER_MIN \
                      (sched_get_priority_min(SCHED_OTHER))
#    else
#      define ACE_PROC_PRI_OTHER_MIN (sched_get_priority_min(SCHED_OTHER))
#    endif /* HPUX */
#  else /* UNICOS is missing a sched_get_priority_min() implementation,
              SCO too */
#    define ACE_PROC_PRI_FIFO_MIN  0
#    define ACE_PROC_PRI_RR_MIN    0
#    define ACE_PROC_PRI_OTHER_MIN 0
#  endif

#  if defined (_POSIX_PRIORITY_SCHEDULING) && !defined(UNIXWARE_7_1)
#    define ACE_PROC_PRI_FIFO_MAX  (sched_get_priority_max(SCHED_FIFO))
#    define ACE_PROC_PRI_RR_MAX    (sched_get_priority_max(SCHED_RR))
#    if defined (HPUX)
#      define ACE_PROC_PRI_OTHER_MAX \
                      (sched_get_priority_max(SCHED_OTHER))
#    else
#      define ACE_PROC_PRI_OTHER_MAX (sched_get_priority_max(SCHED_OTHER))
#    endif /* HPUX */
#  else /* SCO missing sched_get_priority_max() implementation */
#    define ACE_PROC_PRI_FIFO_MAX  59
#    define ACE_PROC_PRI_RR_MAX    59
#    define ACE_PROC_PRI_OTHER_MAX 59
#  endif

#  if !defined(ACE_PROC_PRI_FIFO_DEF)
#    define ACE_PROC_PRI_FIFO_DEF (ACE_PROC_PRI_FIFO_MIN + (ACE_PROC_PRI_FIFO_MAX - ACE_PROC_PRI_FIFO_MIN)/2)
#  endif
#  if !defined(ACE_PROC_PRI_RR_DEF)
#    define ACE_PROC_PRI_RR_DEF (ACE_PROC_PRI_RR_MIN + (ACE_PROC_PRI_RR_MAX - ACE_PROC_PRI_RR_MIN)/2)
#  endif
#  if !defined(ACE_PROC_PRI_OTHER_DEF)
#    define ACE_PROC_PRI_OTHER_DEF (ACE_PROC_PRI_OTHER_MIN + (ACE_PROC_PRI_OTHER_MAX - ACE_PROC_PRI_OTHER_MIN)/2)
#  endif

// THREAD-level values
#  if defined(PRI_FIFO_MIN) && defined(PRI_FIFO_MAX) && defined(PRI_RR_MIN) && defined(PRI_RR_MAX) && defined(PRI_OTHER_MIN) && defined(PRI_OTHER_MAX)
#    if !defined (ACE_THR_PRI_FIFO_MIN)
#      define ACE_THR_PRI_FIFO_MIN  (long) PRI_FIFO_MIN
#    endif /* !ACE_THR_PRI_FIFO_MIN */
#    if !defined (ACE_THR_PRI_FIFO_MAX)
#      define ACE_THR_PRI_FIFO_MAX  (long) PRI_FIFO_MAX
#    endif /* !ACE_THR_PRI_FIFO_MAX */
#    if !defined (ACE_THR_PRI_RR_MIN)
#      define ACE_THR_PRI_RR_MIN    (long) PRI_RR_MIN
#    endif /* !ACE_THR_PRI_RR_MIN */
#    if !defined (ACE_THR_PRI_RR_MAX)
#      define ACE_THR_PRI_RR_MAX    (long) PRI_RR_MAX
#    endif /* !ACE_THR_PRI_RR_MAX */
#    if !defined (ACE_THR_PRI_OTHER_MIN)
#      define ACE_THR_PRI_OTHER_MIN (long) PRI_OTHER_MIN
#    endif /* !ACE_THR_PRI_OTHER_MIN */
#    if !defined (ACE_THR_PRI_OTHER_MAX)
#      define ACE_THR_PRI_OTHER_MAX (long) PRI_OTHER_MAX
#    endif /* !ACE_THR_PRI_OTHER_MAX */
#  elif defined (AIX)
     // AIX's priority range is 1 (low) to 127 (high). There aren't
     // any preprocessor macros I can find. PRIORITY_MIN is for
     // process priorities, as far as I can see, and does not apply
     // to thread priority. The 1 to 127 range is from the
     // pthread_attr_setschedparam man page (Steve Huston, 18-May-2001).
#    if !defined (ACE_THR_PRI_FIFO_MIN)
#      define ACE_THR_PRI_FIFO_MIN  (long) 1
#    endif /* !ACE_THR_PRI_FIFO_MIN */
#    if !defined (ACE_THR_PRI_FIFO_MAX)
#      define ACE_THR_PRI_FIFO_MAX  (long) 127
#    endif /* !ACE_THR_PRI_FIFO_MAX */
#    if !defined (ACE_THR_PRI_RR_MIN)
#      define ACE_THR_PRI_RR_MIN    (long) 1
#    endif /* !ACE_THR_PRI_RR_MIN */
#    if !defined (ACE_THR_PRI_RR_MAX)
#      define ACE_THR_PRI_RR_MAX    (long) 127
#    endif /* !ACE_THR_PRI_RR_MAX */
#    if !defined (ACE_THR_PRI_OTHER_MIN)
#      define ACE_THR_PRI_OTHER_MIN (long) 1
#    endif /* !ACE_THR_PRI_OTHER_MIN */
#    if !defined (ACE_THR_PRI_OTHER_MAX)
#      define ACE_THR_PRI_OTHER_MAX (long) 127
#    endif /* !ACE_THR_PRI_OTHER_MAX */
#  elif defined (sun)
#    if !defined (ACE_THR_PRI_FIFO_MIN)
#      define ACE_THR_PRI_FIFO_MIN  (long) 0
#    endif /* !ACE_THR_PRI_FIFO_MIN */
#    if !defined (ACE_THR_PRI_FIFO_MAX)
#      define ACE_THR_PRI_FIFO_MAX  (long) 59
#    endif /* !ACE_THR_PRI_FIFO_MAX */
#    if !defined (ACE_THR_PRI_RR_MIN)
#      define ACE_THR_PRI_RR_MIN    (long) 0
#    endif /* !ACE_THR_PRI_RR_MIN */
#    if !defined (ACE_THR_PRI_RR_MAX)
#      define ACE_THR_PRI_RR_MAX    (long) 59
#    endif /* !ACE_THR_PRI_RR_MAX */
#    if !defined (ACE_THR_PRI_OTHER_MIN)
#      define ACE_THR_PRI_OTHER_MIN (long) 0
#    endif /* !ACE_THR_PRI_OTHER_MIN */
#    if !defined (ACE_THR_PRI_OTHER_MAX)
#      define ACE_THR_PRI_OTHER_MAX (long) 127
#    endif /* !ACE_THR_PRI_OTHER_MAX */
#  else
#    if !defined (ACE_THR_PRI_FIFO_MIN)
#      define ACE_THR_PRI_FIFO_MIN  (long) ACE_PROC_PRI_FIFO_MIN
#    endif /* !ACE_THR_PRI_FIFO_MIN */
#    if !defined (ACE_THR_PRI_FIFO_MAX)
#      define ACE_THR_PRI_FIFO_MAX  (long) ACE_PROC_PRI_FIFO_MAX
#    endif /* !ACE_THR_PRI_FIFO_MAX */
#    if !defined (ACE_THR_PRI_RR_MIN)
#      define ACE_THR_PRI_RR_MIN    (long) ACE_PROC_PRI_RR_MIN
#    endif /* !ACE_THR_PRI_RR_MIN */
#    if !defined (ACE_THR_PRI_RR_MAX)
#      define ACE_THR_PRI_RR_MAX    (long) ACE_PROC_PRI_RR_MAX
#    endif /* !ACE_THR_PRI_RR_MAX */
#    if !defined (ACE_THR_PRI_OTHER_MIN)
#      define ACE_THR_PRI_OTHER_MIN (long) ACE_PROC_PRI_OTHER_MIN
#    endif /* !ACE_THR_PRI_OTHER_MIN */
#    if !defined (ACE_THR_PRI_OTHER_MAX)
#      define ACE_THR_PRI_OTHER_MAX (long) ACE_PROC_PRI_OTHER_MAX
#    endif /* !ACE_THR_PRI_OTHER_MAX */
#  endif
#  if !defined(ACE_THR_PRI_FIFO_DEF)
#    define ACE_THR_PRI_FIFO_DEF  ((ACE_THR_PRI_FIFO_MIN + ACE_THR_PRI_FIFO_MAX)/2)
#  endif
#  if !defined(ACE_THR_PRI_RR_DEF)
#    define ACE_THR_PRI_RR_DEF ((ACE_THR_PRI_RR_MIN + ACE_THR_PRI_RR_MAX)/2)
#  endif
#  if !defined(ACE_THR_PRI_OTHER_DEF)
#    define ACE_THR_PRI_OTHER_DEF ((ACE_THR_PRI_OTHER_MIN + ACE_THR_PRI_OTHER_MAX)/2)
#  endif
   // Typedefs to help compatibility with Windows NT and Pthreads.
   typedef pthread_t ACE_hthread_t;
   typedef pthread_t ACE_thread_t;

   // native TSS key type
   typedef pthread_key_t ACE_OS_thread_key_t;
   // TSS key type to be used by application
#  if defined (ACE_HAS_TSS_EMULATION)
     typedef u_int ACE_thread_key_t;
#  else  /* ! ACE_HAS_TSS_EMULATION */
     typedef ACE_OS_thread_key_t ACE_thread_key_t;
#  endif /* ! ACE_HAS_TSS_EMULATION */

#  if !defined (ACE_LACKS_COND_T)
     typedef pthread_mutex_t ACE_mutex_t;
     typedef pthread_cond_t ACE_cond_t;
     typedef pthread_condattr_t ACE_condattr_t;
     typedef pthread_mutexattr_t ACE_mutexattr_t;
#  endif /* ! ACE_LACKS_COND_T */
   typedef pthread_mutex_t ACE_thread_mutex_t;

#  if !defined (PTHREAD_CANCEL_DISABLE)
#    define PTHREAD_CANCEL_DISABLE      0
#  endif /* PTHREAD_CANCEL_DISABLE */

#  if !defined (PTHREAD_CANCEL_ENABLE)
#    define PTHREAD_CANCEL_ENABLE       0
#  endif /* PTHREAD_CANCEL_ENABLE */

#  if !defined (PTHREAD_CANCEL_DEFERRED)
#    define PTHREAD_CANCEL_DEFERRED     0
#  endif /* PTHREAD_CANCEL_DEFERRED */

#  if !defined (PTHREAD_CANCEL_ASYNCHRONOUS)
#    define PTHREAD_CANCEL_ASYNCHRONOUS 0
#  endif /* PTHREAD_CANCEL_ASYNCHRONOUS */

#  define THR_CANCEL_DISABLE      PTHREAD_CANCEL_DISABLE
#  define THR_CANCEL_ENABLE       PTHREAD_CANCEL_ENABLE
#  define THR_CANCEL_DEFERRED     PTHREAD_CANCEL_DEFERRED
#  define THR_CANCEL_ASYNCHRONOUS PTHREAD_CANCEL_ASYNCHRONOUS

#  if !defined (PTHREAD_CREATE_JOINABLE)
#    if defined (PTHREAD_CREATE_UNDETACHED)
#      define PTHREAD_CREATE_JOINABLE PTHREAD_CREATE_UNDETACHED
#    else
#      define PTHREAD_CREATE_JOINABLE 0
#    endif /* PTHREAD_CREATE_UNDETACHED */
#  endif /* PTHREAD_CREATE_JOINABLE */

#  if !defined (PTHREAD_CREATE_DETACHED)
#    define PTHREAD_CREATE_DETACHED 1
#  endif /* PTHREAD_CREATE_DETACHED */

#  if !defined (PTHREAD_PROCESS_PRIVATE) && !defined (ACE_HAS_PTHREAD_PROCESS_ENUM)
#    if defined (PTHREAD_MUTEXTYPE_FAST)
#      define PTHREAD_PROCESS_PRIVATE PTHREAD_MUTEXTYPE_FAST
#    else
#      define PTHREAD_PROCESS_PRIVATE 0
#    endif /* PTHREAD_MUTEXTYPE_FAST */
#  endif /* PTHREAD_PROCESS_PRIVATE */

#  if !defined (PTHREAD_PROCESS_SHARED) && !defined (ACE_HAS_PTHREAD_PROCESS_ENUM)
#    if defined (PTHREAD_MUTEXTYPE_FAST)
#      define PTHREAD_PROCESS_SHARED PTHREAD_MUTEXTYPE_FAST
#    else
#      define PTHREAD_PROCESS_SHARED 1
#    endif /* PTHREAD_MUTEXTYPE_FAST */
#  endif /* PTHREAD_PROCESS_SHARED */

#  if !defined (ACE_HAS_STHREADS)
#    if !defined (USYNC_THREAD)
#      define USYNC_THREAD PTHREAD_PROCESS_PRIVATE
#    endif /* ! USYNC_THREAD */
#      if !defined (USYNC_PROCESS)
#        define USYNC_PROCESS PTHREAD_PROCESS_SHARED
#      endif /* ! USYNC_PROCESS */
#  endif /* ACE_HAS_STHREADS */

   /* MM-Graz:  prevent warnings */
#  if !defined (UNIXWARE_7_1)
#    undef THR_BOUND
#    undef THR_NEW_LWP
#    undef THR_DETACHED
#    undef THR_SUSPENDED
#    undef THR_DAEMON

#    define THR_BOUND               0x00000001
#    define THR_NEW_LWP             0x00000002
#    define THR_DETACHED            0x00000040
#    define THR_SUSPENDED           0x00000080
#    define THR_DAEMON              0x00000100
#    define THR_SCHED_FIFO          0x00020000
#    define THR_SCHED_RR            0x00040000
#    define THR_SCHED_DEFAULT       0x00080000
#  endif /* UNIXWARE_7_1 */

#  define THR_JOINABLE            0x00010000

#  if defined (ACE_HAS_IRIX62_THREADS)
#    define THR_SCOPE_SYSTEM        0x00100000
#  else
#    define THR_SCOPE_SYSTEM        THR_BOUND
#  endif /*ACE_HAS_IRIX62_THREADS*/

#  define THR_SCOPE_PROCESS       0x00200000
#  define THR_INHERIT_SCHED       0x00400000
#  define THR_EXPLICIT_SCHED      0x00800000
#  define THR_SCHED_IO            0x01000000

#  if !defined (ACE_HAS_STHREADS)
#    if !defined (ACE_HAS_POSIX_SEM) && !defined (ACE_USES_FIFO_SEM)

// This needs to be moved out of here.
#include /**/ "ace/ACE_export.h"
/**
 * @class ACE_sema_t
 *
 * @brief This is used to implement semaphores for platforms that support
 * POSIX pthreads, but do *not* support POSIX semaphores, i.e.,
 * it's a different type than the POSIX <sem_t>.
 */
class ACE_Export ACE_sema_t
{
public:
  /// Serialize access to internal state.
  ACE_mutex_t lock_;

  /// Block until there are no waiters.
  ACE_cond_t count_nonzero_;

  /// Count of the semaphore.
  u_long count_;

  /// Number of threads that have called <ACE_OS::sema_wait>.
  u_long waiters_;
};
#    endif /* !ACE_HAS_POSIX_SEM */

#    if defined (ACE_LACKS_PTHREAD_YIELD) && defined (ACE_HAS_THR_YIELD)
       // If we are on Solaris we can just reuse the existing
       // implementations of these synchronization types.
#      if !defined (ACE_LACKS_RWLOCK_T) && !defined (ACE_HAS_PTHREADS_UNIX98_EXT)
#        include /**/ <synch.h>
         typedef rwlock_t ACE_rwlock_t;
#      endif /* !ACE_LACKS_RWLOCK_T */
#        include /**/ <thread.h>
#    endif /* (ACE_LACKS_PTHREAD_YIELD) && defined (ACE_HAS_THR_YIELD) */

#  else
#    if !defined (ACE_HAS_POSIX_SEM)
       typedef sema_t ACE_sema_t;
#    endif /* !ACE_HAS_POSIX_SEM */
#  endif /* !ACE_HAS_STHREADS */

#  if defined (ACE_HAS_PTHREADS_UNIX98_EXT)
     typedef pthread_rwlock_t ACE_rwlock_t;
#   endif /* ACE_HAS_PTHREADS_UNIX98_EXT */

#  if defined (__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 2))

     // glibc 2.2.x or better has pthread_mutex_timedlock()
#    ifndef ACE_HAS_MUTEX_TIMEOUTS
#      define ACE_HAS_MUTEX_TIMEOUTS
#    endif  /* ACE_HAS_MUTEX_TIMEOUTS */

     // Use new pthread_attr_setstack if XPG6 support is enabled.
#    if defined (_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 600
#      define ACE_LACKS_PTHREAD_ATTR_SETSTACK
#    endif /* (_XOPEN_SOURCE - 0) < 600 */

#    if !defined (_XOPEN_SOURCE) \
     || (defined (_XOPEN_SOURCE) && (_XOPEN_SOURCE - 0) < 600)
       // pthread_mutex_timedlock() prototype is not visible if _XOPEN_SOURCE
       // is not >= 600 (i.e. for XPG6).
       extern "C" int pthread_mutex_timedlock (pthread_mutex_t *mutex,
                                             const struct timespec * abstime);
#    endif  /* _XOPEN_SOURCE && _XOPEN_SOURCE < 600 */

#  endif  /* linux && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 2)) */

#elif defined (ACE_HAS_STHREADS)
#  if !defined (ACE_THR_PRI_FIFO_MIN)
#    define ACE_THR_PRI_FIFO_MIN  (long) 0
#  endif /* !ACE_THR_PRI_FIFO_MIN */
#  if !defined (ACE_THR_PRI_FIFO_MAX)
#    define ACE_THR_PRI_FIFO_MAX  (long) 59
#  endif /* !ACE_THR_PRI_FIFO_MAX */
#  if !defined (ACE_THR_PRI_RR_MIN)
#    define ACE_THR_PRI_RR_MIN    (long) 0
#  endif /* !ACE_THR_PRI_RR_MIN */
#  if !defined (ACE_THR_PRI_RR_MAX)
#    define ACE_THR_PRI_RR_MAX    (long) 59
#  endif /* !ACE_THR_PRI_RR_MAX */
#  if !defined (ACE_THR_PRI_OTHER_MIN)
#    define ACE_THR_PRI_OTHER_MIN (long) 0
#  endif /* !ACE_THR_PRI_OTHER_MIN */
#  if !defined (ACE_THR_PRI_OTHER_MAX)
#    define ACE_THR_PRI_OTHER_MAX (long) 127
#  endif /* !ACE_THR_PRI_OTHER_MAX */
#endif /* ACE_HAS_PTHREADS */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_PTHREAD_H */

