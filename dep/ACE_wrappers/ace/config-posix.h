/* -*- C++ -*- */
// $Id: config-posix.h 82517 2008-08-05 19:36:26Z shuston $
#ifndef ACE_CONFIG_POSIX_H
#define ACE_CONFIG_POSIX_H
#include <unistd.h>
/*  The following POSIX constants are defined after <unistd.h> is
 *  included.  They are documented in:
 * http://www.opengroup.org/onlinepubs/007904975/basedefs/unistd.h.html
 */
#if defined(_POSIX_REALTIME_SIGNALS) && (_POSIX_REALTIME_SIGNALS-0 != -1 )
# if !defined(ACE_HAS_POSIX_REALTIME_SIGNALS)
#  define ACE_HAS_POSIX_REALTIME_SIGNALS
# endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */
#endif /* _POSIX_REALTIME_SIGNALS */
#if defined(_POSIX_ASYNCHRONOUS_IO) && (_POSIX_ASYNCHRONOUS_IO-0 != -1 )
# if !defined(ACE_HAS_AIO_CALLS)
#  define ACE_HAS_AIO_CALLS
# endif /* ACE_HAS_AIO_CALLS */
#endif /* _POSIX_ASYNCHRONOUS_IO */
#if !defined (ACE_MT_SAFE) || (ACE_MT_SAFE != 0)
# if defined(_POSIX_SEMAPHORES) && (_POSIX_SEMAPHORES-0 != -1 )
#  if !defined(ACE_HAS_POSIX_SEM)
#   define ACE_HAS_POSIX_SEM
#  endif /* ACE_HAS_POSIX_SEM */
#  if defined(ACE_HAS_POSIX_SEM)
#   if !defined (ACE_HAS_POSIX_SEM_TIMEOUT) && \
       (defined (_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS-0 != -1))
#     define ACE_HAS_POSIX_SEM_TIMEOUT
#   endif /* ACE_HAS_POSIX_SEM_TIMEOUT && _POSIX_TIMEOUTS */
#  endif /* ACE_HAS_POSIX_SEM */
# endif /* ACE_HAS_POSIX_SEM */
#endif /* !ACE_MT_SAFE */
#if defined(_POSIX_SHARED_MEMORY_OBJECTS) && (_POSIX_SHARED_MEMORY_OBJECTS-0 != -1 )
# if !defined(ACE_HAS_SHM_OPEN)
#  define ACE_HAS_SHM_OPEN
# endif /* ACE_HAS_SHM_OPEN */
#endif /* _POSIX_SHARED_MEMORY_OBJECTS */
// Check if threading enabled/disable through platform_macros
#if !defined (ACE_MT_SAFE) || (ACE_MT_SAFE != 0)
// Allow the user to disable use of threads by setting ACE_HAS_THREADS to 0
// before including this file. The platform config (not macros) file can
// often detect that the compiler was invoked with or without threads support
// and set this accordingly.
# if defined (ACE_HAS_THREADS) && (ACE_HAS_THREADS == 0)
#   undef ACE_HAS_THREADS
# else
#   if defined(_POSIX_THREADS) && (_POSIX_THREADS-0 != -1 )
#     if !defined(ACE_HAS_THREADS)
#       define ACE_HAS_THREADS
#     endif /* ACE_HAS_THREADS */
#     if !defined(ACE_HAS_PTHREADS)
#       define ACE_HAS_PTHREADS
#     endif /* ACE_HAS_PTHREADS */
#   endif /* _POSIX_THREADS */
# endif /* ACE_HAS_THREADS */
#endif /* !ACE_MT_SAFE */
#if defined(_POSIX_MESSAGE_PASSING) && (_POSIX_MESSAGE_PASSING-0 != -1 )
# if !defined(ACE_HAS_POSIX_MESSAGE_PASSING)
#  define ACE_HAS_POSIX_MESSAGE_PASSING
# endif /* ACE_HAS_POSIX_MESSAGE_PASSING */
#endif /* _POSIX_MESSAGE_PASSING */
#endif /* ACE_CONFIG_POSIX_H */

