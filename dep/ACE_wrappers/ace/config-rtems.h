/* -*- C -*- */
// $Id: config-rtems.h 80826 2008-03-04 14:51:23Z wotte $

/* The following configuration file is designed to work for RTEMS
   platforms using GNU C.
*/

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Needed to make some prototypes visible.
// #if ! defined (_GNU_SOURCE)
// #define _GNU_SOURCE
// #endif /* ! _GNU_SOURCE */

// First the machine specific part
//   There are no known port specific issues with the RTEMS port of ACE.
//   XXX Pentium and PowerPC have high res timer support in ACE.

// Then the compiler specific parts
#if defined (__GNUG__)
  // config-g-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS
# include "ace/config-g++-common.h"
#else  /* ! __GNUG__  */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#   error unsupported compiler in ace/config-rtems.h
#  endif  /* __cplusplus */
#endif /* ! __GNUG__ */

#include "ace/config-posix.h"

// Completely common part :-)

#define ACE_HAS_NONSTATIC_OBJECT_MANAGER

#define ACE_LACKS_ALPHASORT
#define ACE_LACKS_REGEX_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_STRINGS_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_SETEGID
#define ACE_LACKS_SETEUID
#define ACE_LACKS_POLL_H
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_LACKS_STRCASECMP
#define ACE_LACKS_MKSTEMP
#define ACE_LACKS_STRDUP
#define ACE_LACKS_STRTOK_R
#define ACE_LACKS_RAND_REENTRANT_FUNCTIONS
#define ACE_LACKS_REALPATH
#define ACE_LACKS_TEMPNAM

// Temporarily, enabling this results in compile errors with
// rtems 4.6.6.
#define ACE_LACKS_WCHAR_H

#if !defined (ACE_MT_SAFE)
#define ACE_MT_SAFE 1
#endif

#if ACE_MT_SAFE
# define ACE_HAS_THREADS
# define ACE_HAS_PTHREADS
# define ACE_HAS_THREAD_SPECIFIC_STORAGE
# define ACE_HAS_PTHREAD_SCHEDPARAM
# define ACE_LACKS_THREAD_PROCESS_SCOPING
#else
# define ACE_HAS_POSIX_GETPWNAM_R
# define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#endif

#define ACE_HAS_ALT_CUSERID
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_3_PARAM_READDIR_R
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME
#define ACE_HAS_DIRENT
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_MSG
#define ACE_HAS_MT_SAFE_MKTIME
#define ACE_HAS_NONCONST_READV
#define ACE_HAS_GETPAGESIZE
#define ACE_HAS_POSIX_SEM
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_REENTRANT_FUNCTIONS
#define ACE_HAS_SIGACTION_CONSTP2
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGSUSPEND
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STRERROR
#define ACE_HAS_VOIDPTR_GETTIMEOFDAY
#define ACE_HAS_SYS_ERRLIST
#define ACE_HAS_SYS_FILIO_H
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
#define ACE_LACKS_EXEC
#define ACE_LACKS_FILELOCKS
#define ACE_LACKS_FORK
#define ACE_LACKS_GETPGID
#define ACE_LACKS_TIMESPEC_T
#define ACE_LACKS_MADVISE
#define ACE_LACKS_MMAP
#define ACE_LACKS_MPROTECT
#define ACE_LACKS_MSYNC
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_READLINK
#define ACE_LACKS_READV
#define ACE_LACKS_RLIMIT
#define ACE_LACKS_RLIMIT_PROTOTYPE
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_SBRK
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_SETREUID
#define ACE_LACKS_SETREUID_PROTOTYPE
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREGID_PROTOTYPE
#define ACE_LACKS_STRPTIME
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SI_ADDR
#define ACE_LACKS_SOCKETPAIR
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_SYSCALL
#define ACE_LACKS_UCONTEXT_H
#define ACE_HAS_NONCONST_WRITEV
#define ACE_LACKS_WRITEV
#define ACE_NEEDS_HUGE_THREAD_STACKSIZE 65536
#define ACE_NEEDS_SCHED_H
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_TERMIOS

// rtems 4.7 or higher
#if (__RTEMS_MAJOR__ > 4) || (__RTEMS_MAJOR__ == 4 && __RTEMS_MINOR__ > 6)
# define ACE_HAS_UALARM
#else
# define ACE_HAS_NOTSUP_SC_PAGESIZE
# define ACE_LACKS_SUSECONDS_T
# define ACE_LACKS_INTPTR_T
# undef ACE_HAS_SHM_OPEN
# undef ACE_HAS_AIO_CALLS
#endif

// __RTEMS_REVISION__ could also be used but this is broken according
// to the rtems people

#if !defined (_POSIX_REALTIME_SIGNALS)
# define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#endif

#if defined (ACE_LACKS_NETWORKING)
# include "ace/config-posix-nonetworking.h"
#endif

#endif /* ACE_CONFIG_H */
