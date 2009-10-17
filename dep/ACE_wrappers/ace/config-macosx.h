/* -*- C++ -*- */
// $Id: config-macosx.h 80826 2008-03-04 14:51:23Z wotte $
// This configuration file is designed to work with the MacOS X operating system, version 10.2 (Jaguar).
#ifndef ACE_CONFIG_MACOSX_H
#define ACE_CONFIG_MACOSX_H
#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */
#if defined (__GNUG__)
# include "ace/config-g++-common.h"
#endif /* __GNUG__ */
#define ACE_SIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%lu")
#if defined (ACE_HAS_PENTIUM)
# undef ACE_HAS_PENTIUM
#endif /* ACE_HAS_PENTIUM */
#if !defined (_THREAD_SAFE)
#define _THREAD_SAFE
#endif /* _THREAD_SAFE */
#define ACE_HAS_GPERF
#define ACE_HAS_POSIX_SEM
//#define ACE_HAS_SVR4_TLI
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_WCHAR_H
#define ACE_SYS_SELECT_NEEDS_UNISTD_H
//
// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T
// Compiler/platform supports SVR4 signal typedef
#define ACE_HAS_SVR4_SIGNAL_T
//Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT
//Platform supports sigsuspend()
#define ACE_HAS_SIGSUSPEND
//Platform/compiler has macros for sig{empty,fill,add,del}set (e.g., SCO and FreeBSD)
#define ACE_HAS_SIG_MACROS
//#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_LACKS_GETPGID
#define ACE_LACKS_RWLOCK_T
// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_SYSCTL
//?
#define ACE_LACKS_SIGSET
#define ACE_NEEDS_SCHED_H
// Use of <malloc.h> is deprecated.
#define ACE_LACKS_MALLOC_H
#define ACE_HAS_ALT_CUSERID
// Platform supports POSIX timers via struct timespec.
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_UALARM
// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T
#define ACE_LACKS_STRRECVFD
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN
// Platform supports System V IPC (most versions of UNIX, but not Win32)
//#define ACE_HAS_SYSV_IPC
// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
// Compiler/platform supports alloca().
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA
// Compiler/platform correctly calls init()/fini() for shared libraries.
#define ACE_HAS_AUTOMATIC_INIT_FINI
// Explicit dynamic linking permits "lazy" symbol resolution
//#define ACE_HAS_RTLD_LAZY_V
// platform supports POSIX O_NONBLOCK semantics
#define ACE_HAS_POSIX_NONBLOCK
// platform supports IP multicast
#define ACE_HAS_IP_MULTICAST
#define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE
// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T
// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR
// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SYS_SOCKIO_H
// Defines the page size of the system.
#define ACE_HAS_GETPAGESIZE
// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H
// Platform/compiler supports timezone * as second parameter to gettimeofday().
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_SYSV_MSQ_PROTOS
#define ACE_HAS_MSG
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
#define ACE_HAS_NONCONST_MSGSND
#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif
#if ACE_MT_SAFE == 1
// Yes, we do have threads.
# define ACE_HAS_THREADS
// And they're even POSIX pthreads
# define ACE_HAS_PTHREADS
# define ACE_HAS_THREAD_SPECIFIC_STORAGE
# define ACE_LACKS_THREAD_PROCESS_SCOPING
#endif  /* ACE_MT_SAFE == 1 */
#define ACE_HAS_DIRENT
#define ACE_LACKS_POLL_H
#define ACE_LACKS_SEARCH_H
#define ACE_LACKS_SETSCHED
//#define ACE_HAS_RECURSIVE_MUTEXES
// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS
#define ACE_HAS_SEMUN
#define ACE_HAS_SIGINFO_T
#define ACE_LACKS_SIGINFO_H
#define ACE_HAS_UCONTEXT_T
#define ACE_HAS_GETIFADDRS
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES
#define ACE_LACKS_UNNAMED_SEMAPHORE
// dlcompat package (not part of base Darwin) is needed for dlopen().
// You may download directly from sourceforge and install or use fink
// Fink installer puts libraries in /sw/lib and headers in /sw/include
// In order to install dlcompat do the following:
//   - download fink from http://fink.sf.net
//   - type:
//        fink install dlcompat
// as of Dec 2002, if you use fink you will need to uncomment the next line
//#define ACE_NEEDS_DL_UNDERSCORE
#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_LD_SEARCH_PATH ACE_TEXT ("DYLD_LIBRARY_PATH")
#define ACE_DLL_SUFFIX ACE_TEXT (".dylib")
#define ACE_LACKS_DLCLOSE
// gperf seems to need this
#define ACE_HAS_NONSTATIC_OBJECT_MANAGER
#if defined(__APPLE_CC__) && (__APPLE_CC__ < 1173)
#error "Compiler must be upgraded, see http://developer.apple.com"
#endif /* __APPLE_CC__ */
#endif /* ACE_CONFIG_MACOSX_H */

