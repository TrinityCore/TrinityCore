/* -*- C++ -*- */
// $Id: config-openbsd.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for OpenBSD
// platforms using GNU g++.

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

#if defined (ACE_HAS_THREADS)
#include /**/ <pthread.h>
#endif /* ACE_HAS_THREADS */

#include "ace/config-posix.h"

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

#define ACE_SIZEOF_LONG_DOUBLE 12

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#endif /* __GNUG__ */

// Platform specific directives
// gcc defines __OpenBSD__ automatically for us.
#include <sys/param.h>

#if defined (ACE_HAS_THREADS)
#if !defined (_THREAD_SAFE)
#define _THREAD_SAFE
#endif /* _THREAD_SAFE */

// Check if pthreads and native exceptions are being used together.
// This causes SEGVs to tbe thrown somewhat randomly for some
// reason.  According to newsgroup postings, it appears to be an
// OpenBSD or gcc bug.
#if defined (ACE_USES_NATIVE_EXCEPTIONS)
#error "OpenBSD pthreads and native exceptions currently do not work.  See OpenBSD bug #1750"
#endif /* ACE_USES_NATIVE_EXCEPTIONS */

#endif /* ACE_HAS_THREADS */

#define ACE_HAS_GPERF

// Platform specific directives
/* Are the following true? */
#define ACE_LACKS_GETPGID
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID

#define ACE_HAS_ALT_CUSERID
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS

#define ACE_LACKS_RWLOCK_T
#define ACE_HAS_SIG_MACROS
#define ACE_HAS_CHARPTR_DL
#define ACE_HAS_DIRENT

// OpenBSD 3.6
#if (OpenBSD < 200411)
# define ACE_USES_ASM_SYMBOL_IN_DLSYM
#endif

#define ACE_LACKS_UCONTEXT_H

// ucontext_t is in OpenBSD 3.5 and later.
#if (OpenBSD >= 200405)
# define ACE_HAS_UCONTEXT_T
#endif /* OpenBSD >= 200405 */

// OpenBSD has sigwait defined
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIGINFO_T

#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS
#define ACE_LACKS_RAND_REENTRANT_FUNCTIONS
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

#define ACE_HAS_SOCKLEN_T

#define ACE_HAS_POLL

// Use of <malloc.h> is deprecated.
#define ACE_LACKS_MALLOC_H

// NetBSD appears to have a sigset_t type.
// #define ACE_LACKS_SIGSET

// Platform supports POSIX timers via struct timespec.
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_UALARM

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

#define ACE_LACKS_STDINT_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_WCHAR_H

#define ACE_LACKS_STRRECVFD

#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

// OpenBSD supports the getifaddrs interface
#define ACE_HAS_GETIFADDRS

// Compiler/platform supports SVR4 signal typedef
#define ACE_HAS_SVR4_SIGNAL_T
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

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

#define ACE_HAS_SYSCTL

// Platform/compiler supports timezone * as second parameter to gettimeofday().
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

// OpenBSD's dlsym call segfaults when passed an invalid handle.
// It seems as if most other OSs detect this and just report an
// error.
#define ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE

#define ACE_HAS_MSG
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_NONCONST_MSGSND

#ifdef ACE_HAS_THREADS
// Thread specific settings

// And they're even POSIX pthreads
#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif /* ! ACE_MT_SAFE */
#endif /* ACE_HAS_THREADS */

#define ACE_HAS_SIGWAIT

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_LACKS_THREAD_PROCESS_SCOPING
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_MUTEXATTR_PSHARED
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_DIRENT

#if !defined (ACE_HAS_THREADS)
// OpenBSD really has readdir_r () in single threaded mode,
// but the #ifdefs in OS.i select one with the wrong parameter
// sets if the ACE_HAS_POSIX_STD isn't defined (which is defined
// when ACE_HAS_THREADS is defined.)

#define ACE_LACKS_READDIR_R

#endif /* ! ACE_HAD_THREADS */

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// OpenBSD 3.2 lacks sched_setscheduler (see /usr/src/lib/libc_r/TODO)
#define ACE_LACKS_SETSCHED

// OpenBSD supports IPv6 by default, but ACE IPv6 code
// has compile errors.
//#define ACE_HAS_IPV6

#define ACE_HAS_3_PARAM_READDIR_R

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */

