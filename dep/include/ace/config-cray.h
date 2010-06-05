/* -*- C++ -*- */
// $Id: config-cray.h 81935 2008-06-12 22:01:53Z jtc $

#ifndef ACE_CONFIG_CRAY_H
#define ACE_CONFIG_CRAY_H
#include /**/ "ace/pre.h"

/*
    The following predefined macros are used within ACE ifdefs.
    These are defined when using the Cray compilers.  _CRAYMPP
    is defined, for example, if you are running on a Cray T3E
    massively parallel machine.  Moreover, in the case of the T3E,
    _CRAYT3E will be defined.  This is used to determine the
    ACE_SIZEOF defines for primitive types.

    _UNICOS is defined as either the major version of UNICOS being run,
    e.g. 9 or 10 on the vector machines (e.g. C90, T90, J90, YMP, ...)
    or the major+minor+level UNICOS/mk version, e.g. 2.0.3 => 203,
    being run on an MPP machine.

    Summary:

    _CRAYMPP  (defined only if running on MPP machine, e.g. T3E, UNICOS/mk)
    _CRAYT3E  (defined specifically if compiling on a Cray T3E)
    _UNICOS   (defined if running UNICOS or UNICOS/mk)

    Tested on UNICOS 10.0.0.5, UNICOS/mk 2.0.4.57
    Compiles on UNICOS 9.0.2.8, but some tests deadlock

    Contributed by Doug Anderson <dla@home.com>
*/

#if defined (_UNICOS) && !defined (MAXPATHLEN)
#define MAXPATHLEN 1023
#endif /* _UNICOS */

#define ACE_DEFAULT_CLOSE_ALL_HANDLES 0

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

#define ACE_HAS_CPLUSPLUS_HEADERS

#define ACE_HAS_SSIZE_T

#define ACE_HAS_SYSV_IPC

#define ACE_MT_SAFE 1

#define ACE_HAS_THREADS

#define ACE_HAS_PTHREADS

#define ACE_HAS_THREAD_SPECIFIC_STORAGE

#define ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP

#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

#define ACE_HAS_POSIX_TIME

#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

#define ACE_HAS_POSIX_NONBLOCK

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

#define ACE_HAS_DIRENT

#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

#define ACE_HAS_IP_MULTICAST

#define ACE_HAS_SOCKADDR_IN_SIN_LEN

#define ACE_HAS_NONCONST_SELECT_TIMEVAL

#define ACE_HAS_NONCONST_READLINK

#define ACE_HAS_CHARPTR_SOCKOPT

#define ACE_HAS_NONCONST_GETBY

// has man pages, but links with missing symbols and I can't find lib yet
/* #define ACE_HAS_REGEX */

#define ACE_HAS_SIG_MACROS

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

#if _UNICOS > 9
# define ACE_HAS_SIGWAIT
#endif

#define ACE_HAS_SIG_ATOMIC_T

#define ACE_HAS_SIGISMEMBER_BUG

#define ACE_HAS_MSG

#define ACE_HAS_STRERROR

#define ACE_HAS_GPERF

// Special modifications that apply to UNICOS/mk
#if defined(_CRAYMPP)

# define ACE_HAS_SIGINFO_T
# define ACE_HAS_UCONTEXT_T

#endif

// The Cray T90 supposedly supports SYSV SHMEM, but I was unable to get it
// working.  Of course, all other Cray PVP and MPP systems do NOT support it,
// so it's probably good to just define like this for consistency
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_MMAP
#define ACE_LACKS_CONST_TIMESPEC_PTR
#define ACE_LACKS_SYSCALL
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_MADVISE
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#define ACE_LACKS_PTHREAD_CLEANUP
#define ACE_LACKS_CONDATTR_PSHARED
#define ACE_LACKS_THREAD_PROCESS_SCOPING

#if !defined(_CRAYMPP)

#define ACE_LACKS_PTHREAD_CANCEL
#define ACE_LACKS_PTHREAD_KILL

#endif

#define ACE_LACKS_MUTEXATTR_PSHARED
#define ACE_LACKS_RWLOCK_T
#define ACE_LACKS_PRI_T
#define ACE_LACKS_GETPGID
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID
#define ACE_LACKS_MPROTECT
#define ACE_LACKS_MSYNC
#define ACE_LACKS_READV
#define ACE_LACKS_RLIMIT

// we probably want to fake not having this, since Cray memory mgmt is different
#define ACE_LACKS_SBRK

#define ACE_LACKS_SETSCHED

#define ACE_LACKS_SIGINFO_H

#define ACE_LACKS_TIMESPEC_T

#define ACE_LACKS_WRITEV

// Cray vector machines are "word" oriented, and modern ones are hard 64-bit.
// "char" is somewhat of a special case.  Most problems arise when code thinks
// it can address 32-bit quantities and the like.  MPP crays are typically
// byte oriented, e.g. T3E uses Alpha processors, so we don't need as much
// special treatment.

#ifndef _CRAYMPP

# define ACE_SIZEOF_CHAR        1
# define ACE_SIZEOF_SHORT       8
# define ACE_SIZEOF_INT         8
# define ACE_SIZEOF_LONG        8
# define ACE_SIZEOF_LONG_LONG   8
# define ACE_SIZEOF_FLOAT       8
# define ACE_SIZEOF_DOUBLE      8
# define ACE_SIZEOF_LONG_DOUBLE 16
# define ACE_SIZEOF_VOID_P      8

#elif defined(_CRAYT3E)

# define ACE_SIZEOF_CHAR        1
# define ACE_SIZEOF_SHORT       4
# define ACE_SIZEOF_INT         8
# define ACE_SIZEOF_LONG        8
# define ACE_SIZEOF_LONG_LONG   8
# define ACE_SIZEOF_FLOAT       4
# define ACE_SIZEOF_DOUBLE      8
# define ACE_SIZEOF_LONG_DOUBLE 8
# define ACE_SIZEOF_VOID_P      8

#endif

// Ones to check out at some point

/* #define ACE_HAS_SYS_SIGLIST */

// C++ Compiler stuff to verify
/* #define ACE_NEW_THROWS_EXCEPTIONS */
/* #define ACE_HAS_TEMPLATE_TYPEDEFS */

// thread issues to check out
/* #define ACE_LACKS_TIMEDWAIT_PROTOTYPES */

// Cray does seem to support it, in -lnsl and has tiuser.h header
/* #define ACE_HAS_TLI */
/* #define ACE_HAS_TIUSER_H */
/* #define ACE_HAS_TLI_PROTOTYPES */
/* #define ACE_LACKS_T_ERRNO */

/* #define ACE_LACKS_NAMED_POSIX_SEM */

/* #define ACE_HAS_SYS_ERRLIST */

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_CRAY_H */

