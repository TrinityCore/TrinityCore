/* -*- C++ -*- */
// $Id: config-openbsd.h 89494 2010-03-15 20:11:18Z olli $

// The following configuration file is designed to work for OpenBSD
// platforms using GNU g++.

#ifndef ACE_CONFIG_H
# define ACE_CONFIG_H
#include /**/ "ace/pre.h"

// Platform specific directives
// gcc defines __OpenBSD__ automatically for us.
#include <sys/param.h>

#if defined (ACE_HAS_THREADS)
# include /**/ <pthread.h>
#endif /* ACE_HAS_THREADS */

#include "ace/config-posix.h"

#if !defined (__ACE_INLINE__)
# define __ACE_INLINE__
#endif /* !__ACE_INLINE__ */

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#endif /* __GNUG__ */


#if defined (ACE_HAS_THREADS)

# if !defined (_THREAD_SAFE)
#  define _THREAD_SAFE
# endif /* _THREAD_SAFE */

// And they're even POSIX pthreads
# if !defined (ACE_MT_SAFE)
#  define ACE_MT_SAFE 1
# endif /* ! ACE_MT_SAFE */


// Check if pthreads and native exceptions are being used together.
// This causes SEGVs to tbe thrown somewhat randomly for some
// reason.  According to newsgroup postings, it appears to be an
// OpenBSD or gcc bug.
# if defined (ACE_USES_NATIVE_EXCEPTIONS)
#  error "OpenBSD pthreads and native exceptions currently do not work.  See OpenBSD bug #1750"
# endif /* ACE_USES_NATIVE_EXCEPTIONS */

#else
// OpenBSD really has readdir_r () in single threaded mode,
// but the #ifdefs in OS.i select one with the wrong parameter
// sets if the ACE_HAS_POSIX_STD isn't defined (which is defined
// when ACE_HAS_THREADS is defined.)
# define ACE_LACKS_READDIR_R

#endif /* ACE_HAS_THREADS */


#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#define ACE_HAS_3_PARAM_READDIR_R
#define ACE_HAS_3_PARAM_WCSTOK
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_ALLOCA
#define ACE_HAS_ALT_CUSERID
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_CHARPTR_DL
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_DIRENT
#define ACE_HAS_GETIFADDRS
#define ACE_HAS_GETPAGESIZE
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GPERF
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_ICMP_SUPPORT 1
#define ACE_HAS_IPV6
#define ACE_HAS_IP_MULTICAST
#define ACE_HAS_MEMCHR
#define ACE_HAS_MKDIR
#define ACE_HAS_MSG
#define ACE_HAS_NANOSLEEP
#define ACE_HAS_NEW_NO_H
#define ACE_HAS_NONCONST_MSGSND
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_NONCONST_SWAB
#define ACE_HAS_POLL
#define ACE_HAS_POSITION_INDEPENDENT_POINTERS 1
#define ACE_HAS_POSIX_GETPWNAM_R
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_PTHREADS_STD
#define ACE_HAS_PTHREADS_UNIX98_EXT
#define ACE_HAS_PTHREAD_ATTR_SETCREATESUSPEND_NP
#define ACE_HAS_PTHREAD_GETCONCURRENCY
#define ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP
#define ACE_HAS_PTHREAD_NP_H
#define ACE_HAS_PTHREAD_RESUME_NP
#define ACE_HAS_PTHREAD_SETCONCURRENCY
#define ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE
#define ACE_HAS_PTHREAD_SUSPEND_NP
#define ACE_HAS_P_READ_WRITE
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_HAS_RTLD_LAZY_V
#define ACE_HAS_SCANDIR
#define ACE_HAS_SEMUN
#define ACE_HAS_SIGACTION_CONSTP2
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGSUSPEND
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SIG_C_FUNC
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN
#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_SOCKADDR_MSG_NAME
#define ACE_HAS_SOCKLEN_T
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STRINGS
#define ACE_HAS_STRING_CLASS
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_SVR4_SIGNAL_T
#define ACE_HAS_SYSCTL
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_SYS_FILIO_H
#define ACE_HAS_STRSIGNAL
#define ACE_HAS_SYS_SOCKIO_H
#define ACE_HAS_SYS_SYSCALL_H
#define ACE_HAS_TERMIOS
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
#define ACE_HAS_UALARM
#define ACE_HAS_VASPRINTF
#define ACE_HAS_VOIDPTR_MMAP
#define ACE_HAS_VOIDPTR_SOCKOPT
#define ACE_HAS_VOID_UNSETENV
#define ACE_HAS_WCHAR
#define ACE_HAS_XPG4_MULTIBYTE_CHAR

#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_GETIPNODEBYADDR
#define ACE_LACKS_GETIPNODEBYNAME
#define ACE_LACKS_GETPGID
#define ACE_LACKS_IOSTREAM_FX
#define ACE_LACKS_ISCTYPE
#define ACE_LACKS_ITOW
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_LOG2
#define ACE_LACKS_MALLOC_H
#define ACE_LACKS_MSG_ACCRIGHTS
#define ACE_LACKS_MUTEXATTR_PSHARED
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_PERFECT_MULTICAST_FILTERING
#define ACE_LACKS_PRI_T
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS
#define ACE_LACKS_RAND_REENTRANT_FUNCTIONS
#define ACE_LACKS_RLIMIT_PROTOTYPE
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_STDINT_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_TERMIO_H
#define ACE_LACKS_THREAD_PROCESS_SCOPING
#define ACE_LACKS_TIMEDWAIT_PROTOTYPES
#define ACE_LACKS_TIMESPEC_T
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_UNBUFFERED_STREAMBUF
#define ACE_LACKS_U_LONGLONG_T
#define ACE_LACKS_WCHAR_H
#define ACE_LACKS_WCSCASECMP
#define ACE_LACKS_WCSDUP
#define ACE_LACKS_WCSNCASECMP
#define ACE_LACKS_WCSNICMP

#define ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS
#define ACE_PAGE_SIZE 4096
#define ACE_SCANDIR_CMP_USES_CONST_VOIDPTR
#define ACE_SCANDIR_SEL_LACKS_CONST

// OpenBSD 3.6
#if (OpenBSD < 200411)
# define ACE_USES_ASM_SYMBOL_IN_DLSYM
#endif

// ucontext_t is in OpenBSD 3.5 and later.
#if (OpenBSD >= 200405)
# define ACE_HAS_UCONTEXT_T
#endif /* OpenBSD >= 200405 */

// Lacks perfect filtering, must bind group address.
#if !defined ACE_LACKS_PERFECT_MULTICAST_FILTERING
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING
#endif /* ACE_LACKS_PERFECT_MULTICAST_FILTERING */

// OpenBSD's dlsym call segfaults when passed an invalid handle.
// It seems as if most other OSs detect this and just report an error.
#define ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_H */
