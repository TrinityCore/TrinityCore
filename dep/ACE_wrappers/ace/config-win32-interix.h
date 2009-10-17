// -*- C++ -*-
// $Id: config-win32-interix.h 80826 2008-03-04 14:51:23Z wotte $
// The following configuration file is designed to work for Interix
// platforms using GNU g++ (Interix == Microsoft's Services for Unix)
#ifndef ACE_CONFIG_WIN32_INTERIX_H
#define ACE_CONFIG_WIN32_INTERIX_H
#include /**/ "ace/pre.h"
#include <arpa/inet.h>
# define ACE_LACKS_SENDMSG
# define ACE_LACKS_RECVMSG
# define ACE_LACKS_STDINT_H
# define ACE_LACKS_INTTYPES_H
# define ACE_LACKS_PRAGMA_ONCE
# define ACE_LACKS_RWLOCK_T
# define ACE_LACKS_GETPGID                      // Don't have getpgid(), have setpgid() though...
# define ACE_LACKS_UCONTEXT_H
# define ACE_HAS_REENTRANT_FUNCTIONS
# define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS    // Don't have gethostbyaddr_r and friends.
# define ACE_HAS_DIRENT
# define ACE_HAS_STDCPP_STL_INCLUDES
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_HAS_NONCONST_SELECT_TIMEVAL
# define ACE_HAS_SIGWAIT
# define ACE_HAS_SIGINFO_T
#include "ace/config-g++-common.h"
#define ACE_HAS_NEW_NOTHROW // Need to know 'new's failure semantics.
#if defined (ACE_HAS_THREADS)
#define ACE_HAS_THREADS
#define ACE_HAS_PTHREADS
#define _THREAD_SAFE
#define ACE_MTSAFE 1
#define ACE_MT_SAFE 1
#define ACE_LACKS_PTHREAD_YIELD
#define ACE_HAS_MUTEX_TIMEOUTS
#else
  error "You need to enable threads for this Interix port."
#endif /* ACE_HAS_THREADS */
// INTERIX has the following, just an issue with porting for the moment
#define ACE_LACKS_ACCESS
// END INTERIX has the following....
#define ACE_SIZEOF_LONG_DOUBLE 12
#define ACE_PAGE_SIZE 4096
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_SVR4_SIGNAL_T
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_POSIX_TIME                  // Supports POSIX timers via struct timespec.
#define ACE_LACKS_TIMESPEC_T                // Defines struct timespec but not timespec_t.
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SETSCHED
#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_RTLD_LAZY_V
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SEMUN
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STRERROR
#define ACE_HAS_SVR4_GETTIMEOFDAY
#define ACE_HAS_UALARM
#define ACE_HAS_TERMIOS
#define ACE_HAS_SIGWAIT
// Turns off the tracing feature.
#if !defined (ACE_NTRACE)
#define ACE_NTRACE 1
#endif /* ACE_NTRACE */
// NOTE:  In debugging some of the test apps they would all memory fault in using
// ACE_Errno_Guard.  Upon inspection of that code it uses TSS to save ERRNO in
// a TSS pointer.  Access to that pointer caused the fault.  The work around here
// is to tell ACE we have TSS and use emulation.  More investigation is needed to
// determine whether Interix TSS is broken or the correct semantics for usage under
// Interix simply need to be ported.
// To get around the issue ACE_HAS_TSS_EMULATION is defined to use TSS emulation
// however while many test programs that use TSS pass the TSS_Test program fails.
#define ACE_HAS_THREAD_SPECIFIC_STORAGE    // We need thread specific storage even though...
#define ACE_HAS_TSS_EMULATION              // It would appear to be broken in Interix!
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_INTERIX_H */
/*
The following tests do not run.
Dynamic_Priority_Test.log ACE_HAS_TIMED_MESSAGE_BLOCKS
Enum_Interfaces_Test.log
IOStream_Test.log ACE_IOSTREAM not supported on this platform
*/


