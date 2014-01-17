// -*- C++ -*-
// $Id: config-win32-interix.h 93550 2011-03-15 21:26:56Z olli $

// The following configuration file is designed to work for Interix
// platforms using GNU g++ (Interix == Microsoft's Services for Unix)

#ifndef ACE_CONFIG_WIN32_INTERIX_H
#define ACE_CONFIG_WIN32_INTERIX_H

#include /**/ "ace/pre.h"

#include "ace/config-g++-common.h"

#define ACE_HAS_SYS_SIGINFO_H
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#define ACE_HAS_3_PARAM_READDIR_R
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_BROKEN_T_ERROR
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_DIRENT
#define ACE_HAS_GETPAGESIZE
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GETRUSAGE_PROTOTYPE
#define ACE_HAS_GPERF
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_ICMP_SUPPORT 1
#define ACE_HAS_IP_MULTICAST
#define ACE_HAS_MEMCHR
#define ACE_HAS_MKDIR
#define ACE_HAS_MSG
#define ACE_HAS_NEW_NOTHROW
#define ACE_HAS_NEW_NO_H
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_POLL
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_PTHREADS_UNIX98_EXT
#define ACE_HAS_PTHREAD_GETCONCURRENCY
#define ACE_HAS_PTHREAD_SETCONCURRENCY
#define ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE
#define ACE_HAS_P_READ_WRITE
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_HAS_RTLD_LAZY_V
#define ACE_HAS_SEMUN
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGSUSPEND
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SIG_C_FUNC
#define ACE_HAS_SOCKADDR_MSG_NAME
#define ACE_HAS_SOCKLEN_T
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#define ACE_HAS_STDCPP_STL_INCLUDES
#define ACE_HAS_STREAMS
#define ACE_HAS_STRING_CLASS
#define ACE_HAS_STRSIGNAL
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_SVR4_GETTIMEOFDAY
#define ACE_HAS_SVR4_SIGNAL_T
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_SYS_SYSCALL_H
#define ACE_HAS_TERMIOS
#define ACE_HAS_UALARM
#define ACE_HAS_UCONTEXT_T
#define ACE_HAS_VOIDPTR_GETTIMEOFDAY
#define ACE_HAS_NONSTATIC_OBJECT_MANAGER

#define ACE_LACKS_GETPGID
#define ACE_LACKS_ISCTYPE
#define ACE_LACKS_LOG2
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_PRAGMA_ONCE
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_TIMESPEC_T
#define ACE_LACKS_WCSTOK
#define ACE_LACKS_WCSTOLL
#define ACE_LACKS_WCSTOULL

// These are probably not needed with gcc 4.x
#define ACE_LACKS_UNSETENV
#define ACE_LACKS_STRTOLL
#define ACE_LACKS_STRTOULL
#define ACE_LACKS_SETEGID
#define ACE_LACKS_SETEUID


#define ACE_PAGE_SIZE 4096
#define ACE_SIZEOF_LONG_LONG 8
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1

#if defined (ACE_HAS_THREADS)
# define ACE_HAS_MUTEX_TIMEOUTS
# define ACE_HAS_PTHREADS
# define ACE_MT_SAFE 1
#else
# error "You need to enable threads for this Interix port."
#endif /* ACE_HAS_THREADS */

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
