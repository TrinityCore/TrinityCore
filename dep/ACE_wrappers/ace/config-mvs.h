/* -*- C++ -*- */
// $Id: config-mvs.h 81992 2008-06-16 19:09:50Z wotte $

// Config file for MVS with OpenEdition

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

// The following #defines are hacks to get around things
// that seem to be missing or different in MVS land
#define MAXPATHLEN 1024         /* sys/param.h not on MVS */
#define NSIG 44                 /* missing from Signal.h */
#define MAXHOSTNAMELEN 256      /* missing form netdb.h */
#define howmany __howmany       /* MVS uses different names than most others */
#define fd_mask __fd_mask
#define MAXNAMLEN  __DIR_NAME_MAX
#if defined (log)               /* log is a macro in math.h */
# undef log                     /* conflicts with log function in ACE */
#endif /* log */

#define ACE_MVS

// Preprocesor requires an extra argument
#ifndef ACE_USING_MCPP_PREPROCESSOR
# define ACE_CC_PREPROCESSOR_ARGS "-+ -E"
#endif

// See the README file in this directory
// for a description of the following ACE_ macros

#if __COMPILER_VER__ >= 0x21020000   /* OS/390 r2 or higher */
# define ACE_HAS_4_4BSD_SENDMSG_RECVMSG
# define ACE_HAS_UCONTEXT_T
#else  /* __COMPILER_VER__ < 0x21020000 */
# define ACE_LACKS_UCONTEXT_H
#endif /* __COMPILER_VER__ < 0x21020000 */

#if __COMPILER_VER__ < 0x22060000   /* before OS/390 r2.6 */
# define ACE_LACKS_LONGLONG_T
#endif /* __COMPILER_VER__ < 0x22060000 */

#define ERRMAX __sys_nerr

#define ACE_HAS_3_PARAM_WCSTOK
#define ACE_HAS_BROKEN_CTIME
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES
#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_DIRENT
#define ACE_HAS_GETPAGESIZE
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_LIMITED_RUSAGE_T
#define ACE_HAS_MSG
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_NONSCALAR_THREAD_KEY_T
#define ACE_HAS_POLL
#define ACE_HAS_POSIX_NONBLOCK
#define ACE_HAS_POSIX_TIME
#define ACE_HAS_PTHREADS
#define ACE_HAS_PTHREAD_CONDATTR_SETKIND_NP
#define ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SIG_C_FUNC
#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_SIZET_SOCKET_LEN
#define ACE_HAS_SSIZE_T
#define ACE_HAS_STRERROR
#define ACE_HAS_STRBUF_T
#define ACE_HAS_STRINGS
#define ACE_HAS_SYSV_IPC
#define ACE_HAS_TEMPLATE_TYPEDEFS
#define ACE_HAS_THREADS
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_THR_C_DEST
#define ACE_HAS_THR_C_FUNC
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY
#define ACE_HAS_UALARM
#define ACE_HAS_UTIME
#define ACE_HAS_VOIDPTR_MMAP
#define ACE_HAS_VOIDPTR_SOCKOPT
#define ACE_HAS_XPG4_MULTIBYTE_CHAR

#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_INET_ATON
#define ACE_LACKS_MSGBUF_T
#define ACE_LACKS_MUTEXATTR_PSHARED
#define ACE_LACKS_IOSTREAM_FX
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_MADVISE
#define ACE_LACKS_MALLOC_H
#define ACE_LACKS_PARAM_H
#define ACE_LACKS_SYS_PARAM_H
#define ACE_LACKS_PLACEMENT_OPERATOR_DELETE
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_SCHED_H
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_STDINT_H
#define ACE_LACKS_SYS_NERR
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_SYSTIME_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_TCP_H
#define ACE_LACKS_THREAD_PROCESS_SCOPING
#define ACE_LACKS_PTHREAD_ATTR_SETSTACKADDR
#define ACE_LACKS_TIMESPEC_T

#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif

#define ACE_NEEDS_DEV_IO_CONVERSION

#define ACE_SIZEOF_FLOAT 4
#define ACE_SIZEOF_DOUBLE 8
#define ACE_SIZEOF_LONG_DOUBLE 16
#define ACE_HAS_EBCDIC

#define ACE_TEMPLATES_REQUIRE_SOURCE

#define IN_CLASSD(a) ((((in_addr_t)(a)) & 0xf0000000) == 0xe0000000)
#define IN_MULTICAST(a) IN_CLASSD(a)
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */
