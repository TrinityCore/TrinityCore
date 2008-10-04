/* -*- C++ -*- */
// $Id: config-linux-common.h 82516 2008-08-05 19:22:59Z shuston $

// Do not use this configuration file directly since it's designed to
// be included by another, specific configuration file, such as
// config-linux.h.  It provides config information common to all Linux
// platforms.  It automatically determines the CPU architecture,
// compiler (g++ or egcs), and libc (libc5 or glibc), and configures
// based on those.

#ifndef ACE_LINUX_COMMON_H
#define ACE_LINUX_COMMON_H
#include /**/ "ace/pre.h"

#define ACE_HAS_BYTESEX_H

#if ! defined (__ACE_INLINE__)
#define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Needed to differentiate between libc 5 and libc 6 (aka glibc).
#include <features.h>

#if (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500)
#  define ACE_HAS_PTHREADS_UNIX98_EXT
#endif /* _XOPEN_SOURCE - 0 >= 500 */

#if !defined (ACE_LACKS_LINUX_NPTL)

# include "ace/config-posix.h"

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

// Then glibc/libc5 specific parts

#if defined(__GLIBC__)
# if (__GLIBC__  < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 1)
#   define ACE_HAS_NONCONST_SETRLIMIT
# endif
# if (__GLIBC__  < 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ < 3)
#   define ACE_HAS_RUSAGE_WHO_ENUM enum __rusage_who
#   define ACE_HAS_RLIMIT_RESOURCE_ENUM enum __rlimit_resource
# endif
# define ACE_HAS_SOCKLEN_T
# define ACE_HAS_4_4BSD_SENDMSG_RECVMSG

  // glibc defines both of these, used in OS_String.
# if defined (_GNU_SOURCE)
#   define ACE_HAS_STRNLEN
#   define ACE_HAS_WCSNLEN

  // This is probably not a 100%-sure-fire check... Red Hat Linux 9
  // and Enterprise Linux 3 and up have a new kernel that can send signals
  // across threads. This was not possible prior because there was no real
  // difference between a process and a thread. With this, the
  // ACE_POSIX_SIG_Proactor is the only chance of getting asynch I/O working.
  // There are restrictions, such as all socket operations being silently
  // converted to synchronous by the kernel, that make aio a non-starter
  // for most Linux platforms at this time. But we'll start to crawl...
#   define ACE_POSIX_SIG_PROACTOR
# endif

  // To avoid the strangeness with Linux's ::select (), which modifies
  // its timeout argument, use ::poll () instead.
# define ACE_HAS_POLL

// Don't define _XOPEN_SOURCE and _XOPEN_SOURCE_EXTENDED in ACE to make
// getpgid() prototype visible.  ACE shouldn't depend on feature test
// macros to make prototypes visible.
# define ACE_LACKS_GETPGID_PROTOTYPE

// @note  the following defines are necessary with glibc 2.0 (0.961212-5)
//        on Alpha.  I assume that they're necessary on Intel as well,
//        but that may depend on the version of glibc that is used.
//# define ACE_HAS_DLFCN_H_BROKEN_EXTERN_C
# define ACE_HAS_VOIDPTR_SOCKOPT

// Don't define _POSIX_SOURCE in ACE to make strtok() prototype
// visible.  ACE shouldn't depend on feature test macros to make
// prototypes visible.
# define ACE_LACKS_STRTOK_R_PROTOTYPE
// @note  end of glibc 2.0 (0.961212-5)-specific configuration.

# if __GLIBC__ > 1 && __GLIBC_MINOR__ >= 1
    // These were suggested by Robert Hanzlik <robi@codalan.cz> to get
    // ACE to compile on Linux using glibc 2.1 and libg++/gcc 2.8.
#   undef ACE_HAS_BYTESEX_H
#   define ACE_HAS_SIGINFO_T
#   define ACE_LACKS_SIGINFO_H
#   define ACE_HAS_UCONTEXT_T

    // Pre-glibc (RedHat 5.2) doesn't have sigtimedwait.
#   define ACE_HAS_SIGTIMEDWAIT
# endif /* __GLIBC__ 2.1+ */
#else  /* ! __GLIBC__ */
    // Fixes a problem with some non-glibc versions of Linux...
#   define ACE_LACKS_MADVISE
#   define ACE_LACKS_MSG_ACCRIGHTS
#endif /* ! __GLIBC__ */

// Don't define _LARGEFILE64_SOURCE in ACE to make llseek() or
// lseek64() prototype visible.  ACE shouldn't depend on feature test
// macros to make prototypes visible.
#if __GLIBC__ > 1
#  if __GLIBC_MINOR__ == 0
#    define ACE_HAS_LLSEEK
#    define ACE_LACKS_LLSEEK_PROTOTYPE
#  else  /* __GLIBC_MINOR__ > 0 */
#    define ACE_HAS_LSEEK64
#    define ACE_LACKS_LSEEK64_PROTOTYPE
#  endif
#endif /* __GLIBC__ > 1 */

#if __GLIBC__ > 1 && __GLIBC_MINOR__ >= 1
# define ACE_HAS_P_READ_WRITE
# define ACE_LACKS_PREAD_PROTOTYPE
// Use ACE's alternate cuserid() implementation since the use of the
// system cuserid() is discouraged.
# define ACE_HAS_ALT_CUSERID
#endif /* __GLIBC__ > 1 && __GLIBC_MINOR__ >= 0 */

#if (__GLIBC__  > 2)  || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3)
# define ACE_HAS_ISASTREAM_PROTOTYPE
# define ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE
# define ACE_HAS_CPU_SET_T
#endif /* __GLIBC__ > 2 || __GLIBC__ === 2 && __GLIBC_MINOR__ >= 3) */

// Then the compiler specific parts

#if defined (__INTEL_COMPILER)
# include "ace/config-icc-common.h"
#elif defined (__GNUG__)
  // config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS
# include "ace/config-g++-common.h"
#define ACE_CC_NAME ACE_TEXT ("g++")
#define ACE_CC_MAJOR_VERSION __GNUC__
#define ACE_CC_MINOR_VERSION __GNUC_MINOR__
//#define ACE_CC_BETA_VERSION 0 /* ??? */
#elif defined (__DECCXX)
# define ACE_CONFIG_INCLUDE_CXX_COMMON
# include "ace/config-cxx-common.h"
#elif defined (__BORLANDC__)
# undef ACE_HAS_LLSEEK
# undef ACE_HAS_LSEEK64
# undef ACE_LACKS_LLSEEK_PROTOTYPE
# undef ACE_LACKS_LSEEK64_PROTOTYPE
# include "ace/config-borland-common.h"
#elif defined (__SUNCC_PRO)
# include "ace/config-suncc-common.h"
#elif defined (__PGI)
// Portable group compiler
# define ACE_HAS_CPLUSPLUS_HEADERS
# define ACE_HAS_STDCPP_STL_INCLUDES
# define ACE_HAS_TEMPLATE_TYPEDEFS
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_LACKS_SWAB
#elif defined (__GNUC__)
/**
 * GNU C compiler.
 *
 * We need to recognize the GNU C compiler since TAO has at least one
 * C source header and file
 * (TAO/orbsvcs/orbsvcs/SSLIOP/params_dup.{h,c}) that may indirectly
 * include this
 */
#else  /* ! __GNUG__ && !__DECCXX && !__INTEL_COMPILER && !__BORLANDC__ && !__PGI */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#    error unsupported compiler in ace/config-linux-common.h
#  endif  /* __cplusplus */
#endif /* ! __GNUG__*/

// Completely common part :-)

// Platform/compiler has the sigwait(2) prototype
# define ACE_HAS_SIGWAIT

# define ACE_HAS_SIGSUSPEND

# define ACE_HAS_UALARM

#if __GLIBC__ >= 2
#ifndef ACE_HAS_POSIX_REALTIME_SIGNALS
#define ACE_HAS_POSIX_REALTIME_SIGNALS
#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

#ifndef ACE_HAS_AIO_CALLS
#define ACE_HAS_AIO_CALLS
#endif /* ACE_HAS_AIO_CALLS */
#endif

#if __GLIBC__ >= 2
// glibc 2 and higher has wchar support
# define ACE_HAS_XPG4_MULTIBYTE_CHAR
# define ACE_HAS_VFWPRINTF
#endif

#if __GLIBC__ < 2
// These are present in glibc 2 and higher
# define ACE_LACKS_WCSTOK
# define ACE_LACKS_WCSDUP_PROTOTYPE
#endif /* __GLIBC__ < 2 */

#define ACE_LACKS_ITOW
#define ACE_LACKS_WCSICMP
#define ACE_LACKS_WCSNICMP

#if __GLIBC__ >= 2
# define ACE_HAS_3_PARAM_WCSTOK
#endif

#define ACE_HAS_3_PARAM_READDIR_R

#if !defined (ACE_DEFAULT_BASE_ADDR)
#  define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
#endif /* ! ACE_DEFAULT_BASE_ADDR */

// Compiler/platform supports alloca().
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA

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

#if defined __GNUC__ && __GNUC__ >= 2
# define ACE_HAS_BSWAP_64
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

#if (__GLIBC__  < 2)  ||  (__GLIBC__ == 2 && __GLIBC_MINOR__ < 2)
// glibc supports wchar, but lacks fgetwc and ungetwc
# define ACE_LACKS_FGETWC
# define ACE_HAS_NONCONST_MSGSND
# define ACE_LACKS_STRNLEN_PROTOTYPE
#endif

// glibc requires _XOPEN_SOURCE_EXTENDED to make this prototype
// visible, so force ACE to declare one.  Yuk!
#ifndef _XOPEN_SOURCE_EXTENDED
# define ACE_LACKS_MKSTEMP_PROTOTYPE
#endif  /* !_XOPEN_SOURCE_EXTENDED */

// Platform defines struct timespec but not timespec_t
#define ACE_LACKS_TIMESPEC_T

// Platform supplies scandir()
#define ACE_HAS_SCANDIR
// Although the scandir man page says otherwise, this setting is correct.
#define ACE_SCANDIR_CMP_USES_CONST_VOIDPTR

// A conflict appears when including both <ucontext.h> and
// <sys/procfs.h> with recent glibc headers.
//#define ACE_HAS_PROC_FS

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

// Platform/compiler supports global timezone variable.
#define ACE_HAS_TIMEZONE

#define ACE_HAS_TIMEZONE_GETTIMEOFDAY

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Don't define _XOPEN_SOURCE in ACE to make strptime() prototype
// visible.  ACE shouldn't depend on feature test macros to make
// prototypes visible.
#define ACE_LACKS_STRPTIME_PROTOTYPE

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Compiler/platform defines a union semun for SysV shared memory.
#define ACE_HAS_SEMUN

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

#if defined (__ia64) || defined(__alpha) || defined (__x86_64__)
// On 64 bit platforms, the "long" type is 64-bits.  Override the
// default 32-bit platform-specific format specifiers appropriately.
# define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%lu")
# define ACE_SSIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%ld")
# define ACE_SIZE_T_FORMAT_SPECIFIER ACE_TEXT ("%lu")
#endif /* __ia64 */

#define ACE_SIZEOF_WCHAR 4

#define ACE_LACKS_GETIPNODEBYADDR
#define ACE_LACKS_GETIPNODEBYNAME

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// Linux implements sendfile().
#define ACE_HAS_SENDFILE

#define ACE_HAS_VOIDPTR_MMAP

#if defined (ACE_LACKS_NETWORKING)
# include "ace/config-posix-nonetworking.h"
#else
# define ACE_HAS_NETLINK
# define ACE_HAS_GETIFADDRS
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

#if defined (ACE_HAS_EVENT_POLL)
// The sys_epoll interface was introduced in Linux kernel 2.5.45.
// Don't support backported versions since they appear to be buggy.
// The obsolete ioctl()-based interface is no longer supported.
#if 0
// linux/version.h may not be accurate. It's not for Fedora Core 2...
# if !defined (ACE_LACKS_LINUX_VERSION_H)
#   include <linux/version.h>
# endif /* !ACE_LACKS_LINUX_VERSION_H */
# if (LINUX_VERSION_CODE < KERNEL_VERSION (2,5,45))
#   undef ACE_HAS_EVENT_POLL
#   error Disabling Linux epoll support.  Kernel used in C library is too old.
#   error Linux kernel 2.5.45 or better is required.
# endif  /* LINUX_VERSION_CODE < KERNEL_VERSION (2,5,45) */
#endif  /* ACE_HAS_EVENT_POLL */
#endif

#if !defined (ACE_HAS_EVENT_POLL) && !defined (ACE_HAS_DEV_POLL)
# if !defined (ACE_LACKS_LINUX_VERSION_H)
#  include <linux/version.h>
# endif /* !ACE_LACKS_LINUX_VERSION_H */
# if (LINUX_VERSION_CODE > KERNEL_VERSION (2,6,0))
#  define ACE_HAS_EVENT_POLL
# endif
#endif

#include /**/ "ace/post.h"

#endif /* ACE_LINUX_COMMON_H */
