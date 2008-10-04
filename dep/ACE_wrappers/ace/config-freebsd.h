/* -*- C++ -*- */
// $Id: config-freebsd.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for FreeBSD

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

#if !defined (ACE_MT_SAFE)
#  define ACE_MT_SAFE 1
#endif

#if ACE_MT_SAFE
   // Yes, we do have threads.
#  define ACE_HAS_THREADS 1
#else
   // Set to 0 since that's what config-posix.h checks for.
#  define ACE_HAS_THREADS 0
#endif /* ACE_MT_SAFE */

#include "ace/config-posix.h"

#include <osreldate.h>
// Make sure we source in the OS version.

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

#if (__FreeBSD_version < 220000)
#if defined (ACE_HAS_THREADS)
#error Threads are not supported.
#endif /* ACE_HAS_THREADS */
#endif /* __FreeBSD_version < 220000 */

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#endif /* __GNUG__ */

#if defined (ACE_HAS_PENTIUM)
# undef ACE_HAS_PENTIUM
#endif /* ACE_HAS_PENTIUM */

// Platform specific directives
// gcc defines __FreeBSD__ automatically for us.
#ifdef ACE_HAS_THREADS
#if !defined (_THREAD_SAFE)
#define _THREAD_SAFE
#endif /* _THREAD_SAFE */
#endif

#define ACE_HAS_GPERF

#if (__FreeBSD_version < 420000)
#define ACE_LACKS_GETPGID
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID
#define ACE_LACKS_PTHREAD_CANCEL
#endif /* __FreeBSD_version < 420000 */

#define ACE_HAS_ALT_CUSERID
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_SIG_MACROS
// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_CHARPTR_DL

#if (__FreeBSD_version < 400000)
#define ACE_LACKS_SIGSET
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_RAND_REENTRANT_FUNCTIONS
#endif

#define ACE_NEEDS_SCHED_H

#if (__FreeBSD_version < 400000)
enum schedparam_policy {
        SCHED_RR,
        SCHED_IO,
        SCHED_FIFO,
        SCHED_OTHER
};
#endif

// Use of <malloc.h> is deprecated.
#define ACE_LACKS_MALLOC_H


// This won't be necessary after it is fixed in the system include headers.
extern "C" { char * cuserid (char *s); }

// Platform supports POSIX timers via struct timespec.
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_UALARM

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

#if (__FreeBSD_version < 501000)
#define ACE_LACKS_STDINT_H
#endif

#define ACE_HAS_SYSCTL
#define ACE_LACKS_STRRECVFD

#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

#if (__FreeBSD_version >= 220000)
#define ACE_HAS_VASPRINTF
#endif

#if (__FreeBSD_version >= 300000)
#define ACE_HAS_SIGINFO_T
#endif /* __FreeBSD_version >= 300000 */

#if (__FreeBSD_version >= 320000)
#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#endif /* __FreeBSD_version >= 320000 */

#if (__FreeBSD_version >= 440000)
#define ACE_HAS_GETPROGNAME
#define ACE_HAS_SETPROGNAME
#endif

#if (__FreeBSD_version < 501000)
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS
#endif

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_LOG2
#define ACE_LACKS_SI_ADDR

// Compiler/platform supports SVR4 signal typedef
#define ACE_HAS_SVR4_SIGNAL_T

// Compiler/platform supports alloca().
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA

// Compiler/platform supports SVR4 dynamic linking semantics..
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Compiler/platform correctly calls init()/fini() for shared libraries.
#define ACE_HAS_AUTOMATIC_INIT_FINI

// Explicit dynamic linking permits "lazy" symbol resolution
#define ACE_HAS_RTLD_LAZY_V

// platform supports POSIX O_NONBLOCK semantics
#define ACE_HAS_POSIX_NONBLOCK

// platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// Lacks perfect filtering, must bind group address.
#if !defined ACE_LACKS_PERFECT_MULTICAST_FILTERING
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#endif /* ACE_LACKS_PERFECT_MULTICAST_FILTERING */

// Compiler/platform has <alloca.h>
//#define ACE_HAS_ALLOCA_H

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Compiler/platform supports sys_siglist array.
// *** This refers to (_sys_siglist) instead of (sys_siglist)
// #define ACE_HAS_SYS_SIGLIST

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SYS_SOCKIO_H

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Platform/compiler supports timezone * as second parameter to gettimeofday().
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

#define ACE_HAS_MSG
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG

#if (__FreeBSD_version < 500100)
#  define ACE_HAS_NONCONST_MSGSND
#endif

// Thread specific settings
// Yes, we do have threads.
#ifdef ACE_HAS_THREADS
#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif /* ! ACE_MT_SAFE */
#endif /* ACE_HAS_THREADS */

#define ACE_LACKS_THREAD_PROCESS_SCOPING
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_MUTEXATTR_PSHARED
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_DIRENT

#define ACE_HAS_SIGWAIT

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

#if (__FreeBSD_version > 400000)
#define ACE_HAS_UCONTEXT_T
#define ACE_HAS_SOCKLEN_T
#define ACE_HAS_GETIFADDRS
#define ACE_HAS_PTHREADS_UNIX98_EXT
#endif

// Note, on FreeBSD 5, POSIX aio is now an optional kernel module which
// must be loaded.
// Read the aio(4) man page for what to do, otherwise any aio_* call
// will coredump.

// By default use Proactor which does not use POSIX Real-time Signals.
#ifdef ACE_HAS_AIO_CALLS
#  ifndef ACE_POSIX_AIOCB_PROACTOR
#    define ACE_POSIX_AIOCB_PROACTOR
#  endif /* ACE_POSIX_AIOCB_PROACTOR */
#endif /* ACE_HAS_AIO_CALLS */

#define ACE_LACKS_STROPTS_H

// Needed when ACE_HAS_WCHAR is defined.
#define ACE_LACKS_WCSNICMP
#define ACE_LACKS_WCSICMP
#define ACE_LACKS_WCSDUP
#define ACE_LACKS_ITOW
#define ACE_HAS_3_PARAM_WCSTOK
#define ACE_HAS_3_PARAM_READDIR_R

#if (__FreeBSD_version >= 501000)
#  define ACE_HAS_PTHREAD_SETSTACK
#endif

#if (__FreeBSD_version < 700007)
# define ACE_HAS_SIGVAL_SIGVAL_INT
# define ACE_HAS_BROKEN_SIGEVENT_STRUCT
#endif

#if (__FreeBSD_version >= 700028)
# define ACE_HAS_SCTP
# define ACE_HAS_LKSCTP
#endif

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_H */
