// -*- C++ -*-
// $Id: config-android.h 94491 2011-09-12 11:17:33Z johnnyw $

// The following configuration file is designed to work for Android
// platforms using GNU C++.

#ifndef ACE_CONFIG_ANDROID_H
#define ACE_CONFIG_ANDROID_H
#include /**/ "ace/pre.h"

// Location of the __ANDROID_API__ define
// #include $NDK_ROOT/sysroot/usr/include/android/api-level.h
#include "android/api-level.h"

#if !defined (__ANDROID_API__)
# error __ANDROID_API__ must be defined
#endif

#define ACE_HAS_SSIZE_T

// system errorno is a volatile int
#define ACE_HAS_VOLATILE_ERRNO

#define ACE_ERRNO_TYPE volatile int

// Android doesn't check is sig is out of range.
#define ACE_HAS_SIGISMEMBER_BUG

#define ACE_HAS_PTHREADS_UNIX98_EXT

// Android does not support pthread concurrency (yet)
#define ACE_LACKS_MUTEXATTR_PSHARED 1

// the android definition of struct stat{} uses
// unsigned long rather than time_t for st_[acm]time
// members of the stat struct used to report file
// status details.
#define ACE_USES_ULONG_FOR_STAT_TIME

#define ACE_LACKS_NEW_H
#define ACE_LACKS_SEARCH_H
#define ACE_LACKS_SIGINFO_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_UCONTEXT_H

#define ACE_LACKS_CUSERID
#define ACE_LACKS_FD_MASK
#define ACE_LACKS_GETHOSTENT
#define ACE_LACKS_GETLOADAVG
#define ACE_LACKS_ISCTYPE
#define ACE_LACKS_LOG2
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS
#define ACE_LACKS_PWD_FUNCTIONS
#define ACE_LACKS_PTHREAD_CANCEL
#define ACE_LACKS_SEEKDIR
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_SETINHERITSCHED
#define ACE_LACKS_STD_WSTRING
#define ACE_LACKS_STRRECVFD
#define ACE_LACKS_SWAB
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_TELLDIR
#define ACE_LACKS_WCSTOLL
#define ACE_LACKS_WCSTOULL

#define ACE_LACKS_RAND_R

// Android seems to have 64 keys of which Android itself use 5
#define ACE_DEFAULT_THREAD_KEYS 59

// Android Standalone compiler std library does not include
// wide character support
// Used in tests/Sequence_Unit_Tests/string_sequence_tester.hpp
# define TAO_LACKS_WCHAR_CXX_STDLIB

#if !defined (ACE_MT_SAFE)
#  define ACE_MT_SAFE 1
#endif

#define ACE_PLATFORM_CONFIG config-android.h

// Needed to differentiate between libc 5 and libc 6 (aka glibc).
#include <features.h>

#if (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500)
#  define ACE_HAS_PTHREADS_UNIX98_EXT
#endif /* _XOPEN_SOURCE - 0 >= 500 */

# include "ace/config-posix.h"

#if !defined (ACE_LACKS_LINUX_NPTL)

  // Temporary fix because NPTL kernels do have shm_open but there is a problem
  // with shm_open/shm_unlink pairing in ACE which needs to be fixed when I have time.
# if defined (ACE_HAS_SHM_OPEN)
#   undef ACE_HAS_SHM_OPEN
# endif /* ACE_HAS_SHM_OPEN */

# if defined (ACE_USES_FIFO_SEM)
    // Don't use this for Linux NPTL since this has complete
    // POSIX semaphores which are more efficient
#   undef ACE_USES_FIFO_SEM
# endif /* ACE_USES_FIFO_SEM */

# if defined (ACE_HAS_POSIX_SEM)
    // Linux NPTL may not define the right POSIX macro
    // but they have the actual runtime support for this stuff
#   if !defined (ACE_HAS_POSIX_SEM_TIMEOUT) && (((_POSIX_C_SOURCE - 0) >= 200112L) || (_XOPEN_SOURCE >= 600))
#     define ACE_HAS_POSIX_SEM_TIMEOUT
#   endif /* !ACE_HAS_POSIX_SEM_TIMEOUT && (((_POSIX_C_SOURCE - 0) >= 200112L) || (_XOPEN_SOURCE >= 600)) */
# endif /* ACE_HAS_POSIX_SEM */
#endif /* !ACE_LACKS_LINUX_NPTL */

// AIO support pulls in the rt library, which pulls in the pthread
// library.  Disable AIO in single-threaded builds.
#if defined (ACE_HAS_THREADS)
#  define ACE_HAS_CLOCK_GETTIME
#else
#  undef ACE_HAS_AIO_CALLS
#endif

// First the machine specific part

#if defined (__powerpc__) || defined (__x86_64__)
# if !defined (ACE_DEFAULT_BASE_ADDR)
#   define ACE_DEFAULT_BASE_ADDR ((char *) 0x40000000)
# endif /* ! ACE_DEFAULT_BASE_ADDR */
#elif defined (__ia64)
# if !defined (ACE_DEFAULT_BASE_ADDR)
// Zero base address should work fine for Linux of IA-64: it just lets
// the kernel to choose the right value.
#   define ACE_DEFAULT_BASE_ADDR ((char *) 0x0000000000000000)
# endif /* ! ACE_DEFAULT_BASE_ADDR */
#endif /* ! __powerpc__  && ! __ia64 */

#define ACE_HAS_SIGINFO_T
#define ACE_HAS_SOCKLEN_T
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG

#define ACE_HAS_LSEEK64
//#define ACE_LACKS_LSEEK64_PROTOTYPE

#define ACE_HAS_P_READ_WRITE
// Use ACE's alternate cuserid() implementation since the use of the
// system cuserid() is discouraged.
#define ACE_HAS_ALT_CUSERID

#if (__GLIBC__  > 2)  || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)
# define ACE_HAS_ISASTREAM_PROTOTYPE
# define ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE
# define ACE_HAS_CPU_SET_T
#endif /* __GLIBC__ > 2 || __GLIBC__ === 2 && __GLIBC_MINOR__ >= 3) */

// Then the compiler specific parts

#if defined (__GNUG__)
  // config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS
# include "ace/config-g++-common.h"
#elif defined (__GNUC__)
/**
 * GNU C compiler.
 *
 * We need to recognize the GNU C compiler since TAO has at least one
 * C source header and file
 * (TAO/orbsvcs/orbsvcs/SSLIOP/params_dup.{h,c}) that may indirectly
 * include this
 */
#else  /* ! __GNUG__ && !__DECCXX && !__INTEL_COMPILER && && !__PGI */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#    error unsupported compiler in ace/config-android.h
#  endif  /* __cplusplus */
#endif /* ! __GNUG__*/

// Completely common part :-)

// Platform/compiler has the sigwait(2) prototype
#define ACE_HAS_SIGWAIT

#define ACE_HAS_SIGSUSPEND

#define ACE_HAS_STRSIGNAL

#ifndef ACE_HAS_POSIX_REALTIME_SIGNALS
# define ACE_HAS_POSIX_REALTIME_SIGNALS
#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

#define ACE_HAS_XPG4_MULTIBYTE_CHAR
#define ACE_HAS_VFWPRINTF

#define ACE_LACKS_ITOW
#define ACE_LACKS_WCSICMP
#define ACE_LACKS_WCSNICMP
#define ACE_LACKS_ISWASCII

#define ACE_HAS_3_PARAM_WCSTOK

#define ACE_HAS_3_PARAM_READDIR_R

#if !defined (ACE_DEFAULT_BASE_ADDR)
#  define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
#endif /* ! ACE_DEFAULT_BASE_ADDR */

#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H
#define ACE_HAS_SYS_SYSINFO_H
#define ACE_HAS_LINUX_SYSINFO

// Compiler/platform has the getrusage() system call.
#define ACE_HAS_GETRUSAGE
#define ACE_HAS_GETRUSAGE_PROTOTYPE

#define ACE_HAS_BYTESWAP_H
#define ACE_HAS_BSWAP_16
#define ACE_HAS_BSWAP_32

#if defined (__GNUC__)
#  define ACE_HAS_BSWAP_64
#endif

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// ONLY define this if you have config'd multicast into a 2.0.34 or
// prior kernel.  It is enabled by default in 2.0.35 kernels.
#if !defined (ACE_HAS_IP_MULTICAST)
# define ACE_HAS_IP_MULTICAST
#endif /* ! ACE_HAS_IP_MULTICAST */

// At least for IPv4, Linux lacks perfect filtering.
#if !defined ACE_LACKS_PERFECT_MULTICAST_FILTERING
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#endif /* ACE_LACKS_PERFECT_MULTICAST_FILTERING */

#define ACE_HAS_BIG_FD_SET

// Linux defines struct msghdr in /usr/include/socket.h
#define ACE_HAS_MSG

// Linux "improved" the interface to select() so that it modifies
// the struct timeval to reflect the amount of time not slept
// (see NOTES in Linux's select(2) man page).
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

#define ACE_DEFAULT_MAX_SOCKET_BUFSIZ 65535

#define ACE_CDR_IMPLEMENT_WITH_NATIVE_DOUBLE 1

#define ACE_HAS_GETPAGESIZE 1

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

// Platform supplies scandir()
#define ACE_HAS_SCANDIR

#define ACE_MMAP_NO_ZERO

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

#define ACE_HAS_POSIX_TIME

#define ACE_HAS_GPERF

#define ACE_HAS_DIRENT

// Starting with FC9 rawhide this file is not available anymore but
// this define is set
#if defined _XOPEN_STREAMS && _XOPEN_STREAMS == -1
# define ACE_LACKS_STROPTS_H
# define ACE_LACKS_STRRECVFD
#endif

#if !defined (ACE_LACKS_STROPTS_H)
# define ACE_HAS_STRBUF_T
#endif

#if defined (__ia64) || defined(__alpha) || defined (__x86_64__) || defined(__powerpc64__)
// On 64 bit platforms, the "long" type is 64-bits.  Override the
// default 32-bit platform-specific format specifiers appropriately.
# define ACE_UINT64_FORMAT_SPECIFIER_ASCII "%lu"
# define ACE_SSIZE_T_FORMAT_SPECIFIER_ASCII "%ld"
# define ACE_SIZE_T_FORMAT_SPECIFIER_ASCII "%lu"
#endif /* __ia64 */

#define ACE_SIZEOF_WCHAR 4

#if defined (__powerpc__) && !defined (ACE_SIZEOF_LONG_DOUBLE)
// 32bit PowerPC Linux uses 128bit long double
# define ACE_SIZEOF_LONG_DOUBLE 16
#endif

#define ACE_LACKS_GETIPNODEBYADDR
#define ACE_LACKS_GETIPNODEBYNAME

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// Linux implements sendfile().
#define ACE_HAS_SENDFILE 1

#define ACE_HAS_VOIDPTR_MMAP

#define ACE_HAS_VASPRINTF

// According to man pages Linux uses different (compared to UNIX systems) types
// for setting IP_MULTICAST_TTL and IPV6_MULTICAST_LOOP / IP_MULTICAST_LOOP
// in setsockopt/getsockopt.
#define ACE_HAS_IP_MULTICAST_TTL_AS_INT 1
#define ACE_HAS_IPV6_MULTICAST_LOOP_AS_BOOL 1
#define ACE_HAS_IP_MULTICAST_LOOP_AS_INT 1

#if defined (ACE_LACKS_NETWORKING)
# include "ace/config-posix-nonetworking.h"
#else
# define ACE_HAS_NETLINK
#endif

#if !defined (ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO)
// Detect if getsockname() and getpeername() returns random values in
// the sockaddr_in::sin_zero field by evaluation of the kernel
// version. Since version 2.5.47 this problem is fixed.
#  if !defined (ACE_LACKS_LINUX_VERSION_H)
#    include <linux/version.h>
#  endif /* !ACE_LACKS_LINUX_VERSION_H */
#  if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,5,47))
#    define ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO 0
#  else
#    define ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO 1
#  endif  /* (LINUX_VERSION_CODE <= KERNEL_VERSION(2,5,47)) */
#endif  /* ACE_GETNAME_RETURNS_RANDOM_SIN_ZERO */

#if !defined (ACE_HAS_EVENT_POLL) && !defined (ACE_HAS_DEV_POLL)
# if !defined (ACE_LACKS_LINUX_VERSION_H)
#  include <linux/version.h>
# endif /* !ACE_LACKS_LINUX_VERSION_H */
#endif

#define ACE_HAS_SVR4_DYNAMIC_LINKING
#define ACE_HAS_AUTOMATIC_INIT_FINI
#define ACE_HAS_DLSYM_SEGFAULT_ON_INVALID_HANDLE
#define ACE_HAS_RECURSIVE_MUTEXES
#define ACE_HAS_THREAD_SPECIFIC_STORAGE
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R
#define ACE_HAS_REENTRANT_FUNCTIONS

#if __ANDROID_API__ == 8
# define ACE_LACKS_REGEX_H 1
# define ACE_LACKS_CONDATTR 1
#elif __ANDROID_API__ == 9
# define ACE_HAS_TIMEZONE
#else
# error Unsupported Android release
#endif

#include /**/ "ace/post.h"

#endif /* ACE_CONFIG_ANDROID_H */
