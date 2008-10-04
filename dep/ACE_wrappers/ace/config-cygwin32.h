/* -*- C++ -*- */
// $Id: config-cygwin32.h 81809 2008-05-30 13:40:21Z vzykov $

// The following configuration file is designed to work for CygWin
// platforms using GNU C++.

#ifndef ACE_CONFIG_CYGWIN32_H
#define ACE_CONFIG_CYGWIN32_H

#include /**/ "ace/pre.h"

#if !defined (ACE_MT_SAFE)
#define ACE_MT_SAFE 1
#endif

#define CYGWIN32

// We trust this file will get included before <sys/types.h>
#if !defined(FD_SETSIZE)
# define FD_SETSIZE 1024
#endif

#if !defined (ACE_IOV_MAX)
# define ACE_IOV_MAX 64
#endif /* ACE_IOV_MAX */

// Define custom export macros for export/import of symbols from/of dll's
#define ACE_HAS_CUSTOM_EXPORT_MACROS
#define ACE_Proper_Export_Flag __declspec (dllexport)
#define ACE_Proper_Import_Flag __declspec (dllimport)
#define ACE_EXPORT_SINGLETON_DECLARATION(T) template class __declspec (dllexport) T
#define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
#define ACE_IMPORT_SINGLETON_DECLARATION(T) extern template class T
#define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) extern template class SINGLETON_TYPE <CLASS, LOCK>;

#define ACE_HAS_SELECT_H

#define ACE_LACKS_PRAGMA_ONCE

#if ! defined (__ACE_INLINE__)
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

#include /**/ <cygwin/version.h>

// Needed to differentiate between libc 5 and libc 6 (aka glibc).
// It's there on all libc 5 systems I checked.
#include /**/ <features.h>

// config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
// this must appear before its #include.
#define ACE_HAS_STRING_CLASS

#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#else
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#   error unsupported compiler in ace/config-cygwin32.h
#  endif  /* __cplusplus */
#endif /* __GNUG__ */

#define ACE_HAS_VOIDPTR_SOCKOPT 1
#define ACE_HAS_UALARM 1
#define ACE_HAS_SYS_ERRLIST 1
#define ACE_HAS_STRNLEN 1
#define ACE_HAS_POSIX_GETPWNAM_R 1
#define ACE_HAS_POSIX_NONBLOCK 1
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_CLOCK_GETTIME 1
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
#define ACE_HAS_MSG
#define ACE_DEFAULT_BASE_ADDR ((char *) 0x8000000)
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_SVR4_DYNAMIC_LINKING
//#define ACE_HAS_SYSV_IPC
#define ACE_HAS_VOIDPTR_MMAP
#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_POLL
#define ACE_HAS_POSITION_INDEPENDENT_POINTERS 1
#define ACE_HAS_SOCKADDR_MSG_NAME 1
#define ACE_LACKS_PRI_T 1
#define ACE_HAS_3_PARAM_READDIR_R

// Compiler/platform supports alloca().
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you want ACE to use it.
//#define ACE_HAS_ALLOCA

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

#define ACE_HAS_IP_MULTICAST

#define ACE_HAS_BIG_FD_SET

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

#define ACE_DEFAULT_MAX_SOCKET_BUFSIZ 65535

#define ACE_DEFAULT_SELECT_REACTOR_SIZE 256

#define ACE_HAS_GETPAGESIZE

#define ACE_HAS_VOIDPTR_GETTIMEOFDAY

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

#define ACE_HAS_SOCKLEN_T 1

#define ACE_HAS_GPERF

#define ACE_HAS_DIRENT
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG

#define ACE_LACKS_MKFIFO
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_FGETWC 1
#define ACE_LACKS_NAMED_POSIX_SEM
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_MADVISE
#define ACE_LACKS_GETPGID_PROTOTYPE
#define ACE_LACKS_GETHOSTENT
#define ACE_LACKS_ITOW 1
#define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS 1
#define ACE_LACKS_RLIMIT
#define ACE_LACKS_RWLOCK_T 1
#define ACE_LACKS_SUSECONDS_T
#define ACE_LACKS_SYS_SYSCTL_H

#define ACE_LACKS_FGETWS 1
#define ACE_LACKS_FPUTWS 1

#define ACE_LACKS_WCSTOULL 1

#define ACE_HAS_AUTOMATIC_INIT_FINI

#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGACTION_CONSTP2
#define ACE_HAS_SIGSUSPEND
#define ACE_HAS_SIG_C_FUNC 1
#define ACE_HAS_SIG_ATOMIC_T

#define ACE_HAS_POSIX_SEM

#define ACE_HAS_P_READ_WRITE

#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

// Cygwin DLL suffix is .dll
#define ACE_DLL_SUFFIX ACE_TEXT (".dll")

// Cygwin runs on Windows, so we have to get the environment variable PATH and
// not LD_LIBRARY_PATH which is the default in ACE
#define ACE_LD_SEARCH_PATH ACE_TEXT ("PATH")

#if ACE_MT_SAFE
// Yes, we do have threads.
#  define ACE_HAS_THREADS
// And they're even POSIX pthreads (LinuxThreads implementation)
#  define ACE_HAS_PTHREADS

#  define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS

// Compiler/platform has thread-specific storage
#   define ACE_HAS_THREAD_SPECIFIC_STORAGE

#   define ACE_HAS_PTHREADS_UNIX98_EXT
#   define ACE_HAS_PTHREAD_CONTINUE 1
#   define ACE_HAS_PTHREAD_SUSPEND 1

#  define ACE_LACKS_PTHREAD_ATTR_SETSTACKADDR
// Cygwin (see pthread.h): Not supported or implemented.
#  define ACE_LACKS_SETSCHED
#  define ACE_LACKS_SETDETACH
#  define ACE_LACKS_PTHREAD_CANCEL
#  define ACE_LACKS_THREAD_PROCESS_SCOPING
#  define ACE_LACKS_MUTEXATTR_PSHARED
#  define ACE_LACKS_RWLOCKATTR_PSHARED
#  define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1
#  define ACE_LACKS_PTHREAD_YIELD 1
#  define ACE_LACKS_PTHREAD_ATTR_SETSTACK

// In the 1.5.9 release of Cygwin the pthread_kill gives an access violation
// so for the time being we say Cygwin doesn't support pthread_kill.
#  define ACE_LACKS_PTHREAD_KILL

#endif  /* ACE_MT_SAFE */

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_CYGWIN32_H */
