/* -*- C++ -*- */
// $Id: config-hpux-11.00.h 96096 2012-08-23 12:34:02Z johnnyw $

// The following configuration file is designed to work for HP
// platforms running HP-UX 11.00 using aC++ or gcc (2.95 and up).

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

#define ACE_LACKS_STDINT_H
#define ACE_LACKS_SYS_SELECT_H

#if defined (__GNUG__)

// config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
// this must appear before its #include.
#  define ACE_HAS_STRING_CLASS

#  include "ace/config-g++-common.h"

#else

// aC++...

// Precompiler needs extra flags to ignore "invalid #pragma directive"
#  define ACE_CC_PREPROCESSOR_ARGS "-E +W 67"

// If the -AA compile option is used, the compiler defines _HP_NAMESPACE_STD.
// The -AA option enables the 2.0 standard C++ library. If not used, then
// we have the old, 1.2.1 C++ library.
#    if defined (_HP_NAMESPACE_STD)
#      if defined (ACE_HAS_STANDARD_CPP_LIBRARY)
#        undef ACE_HAS_STANDARD_CPP_LIBRARY
#      endif
#      define ACE_HAS_STANDARD_CPP_LIBRARY 1
#      if defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#        undef ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB
#      endif
#      if defined (RWSTD_NO_NAMESPACE)
         namespace std {} using namespace std;
#      else
#        define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#      endif /* RWSTD_NO_NAMESPACE */
#    else
#      define ACE_USES_OLD_IOSTREAMS
       // There's no support in ACE's use of numeric_limits for those that
       // aren't in std::
#      define ACE_LACKS_NUMERIC_LIMITS
#    endif /* _HP_NAMESPACE_STD */

#    define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR

// Platform lacks streambuf "linebuffered ()".
#    define ACE_LACKS_LINEBUFFERED_STREAMBUF 1

// Lack of (and broken) support for placement operator delete is a known
// bug by HP, up until aC++ A.03.55.02.
#    if (__HP_aCC < 35502)
#      define ACE_LACKS_PLACEMENT_OPERATOR_DELETE
#    endif /* __HP_aCC < 35502 */

// Compiler's 'new' throws exceptions on failure, regardless of whether or
// not exception handling is enabled in the compiler options. Fortunately,
// new(nothrow_t) is offered.
#    define ACE_NEW_THROWS_EXCEPTIONS
#    define ACE_HAS_NEW_NOTHROW
#    define ACE_HAS_NEW_NO_H 1

// Compiler's template mechanism must see source code (i.e., .C files).
#    define ACE_TEMPLATES_REQUIRE_SOURCE

// Compiler doesn't handle 'signed char' correctly (used in ace/IOStream.h)
#  define ACE_LACKS_SIGNED_CHAR

#endif /* __GNUG__, HP */

//*********************************************************************
//
// From here down is the compiler-INdependent OS settings.
//
//*********************************************************************

// Compiling for HPUX.
#if !defined (HPUX)
#define HPUX
#endif /* HPUX */
#define HPUX_11

#ifndef _HPUX_SOURCE
#define _HPUX_SOURCE
#endif

#include /**/ <sys/stdsyms.h>

// HP-UX is a POSIX-compliant system - see what's available.
#include "ace/config-posix.h"

// config-posix.h sets up ACE_HAS_AIO_CALLS if the headers define the
// proper things. In HP-UX 11's case, the AIOCB Proactor works the best
// overall. If the user hasn't overridden it, select AIOCB.
#if defined (ACE_HAS_AIO_CALLS)
#  if !defined (ACE_POSIX_AIOCB_PROACTOR) && !defined (ACE_POSIX_SIG_PROACTOR)
#    define ACE_POSIX_AIOCB_PROACTOR
#  endif /* !ACE_HAS_POSIX_AIOCB_PROACTOR && !ACE_POSIX_SIG_PROACTOR */
#endif /* ACE_HAS_AIO_CALLS */

////////////////////////////////////////////////////////////////////////////
//
// General OS information - see README for more details on what they mean
//
///////////////////////////////////////////////////////////////////////////

// HP/UX needs to have these addresses in a special range.
// If this is on a 64-bit model, the default is to use 64-bit addressing.
// It can also be set so that the mapped region is shareable with 32-bit
// programs.  To enable the 32/64 sharing, comment out the first definition
// of ACE_DEFAULT_BASE_ADDR and uncomment the two lines after it.
#if defined (__LP64__)
#  define ACE_DEFAULT_BASE_ADDR ((char *) 0x0000001100000000)
//#  define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
//#  define ACE_OS_EXTRA_MMAP_FLAGS MAP_ADDR32

#  define ACE_DEFAULT_BASE_ADDRL (0x0000001100000000)
//#  define ACE_DEFAULT_BASE_ADDRL (0x80000000)
#else
#  define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)
#endif  /* __LP64__ */

// Preprocessor needs some help with data types
#if defined (__LP64__)
#  define ACE_SIZEOF_LONG 8
#else
#  define ACE_SIZEOF_LONG 4
#endif

// Platform can do async I/O (aio_*) (set up in config-posix.h)
// ... but seems to require this in order to keep from hanging.  Needs some
// investigation, maybe with HP.  John Mulhern determined this value
// empirically.  YMMV.  If it does vary, set it up in your own config.h which
// then includes the ACE-supplied config.
#if !defined (ACE_INFINITE)
#  define ACE_INFINITE 10000000
#endif

/* Compiler/platform correctly calls init()/fini() for shared libraries. */
#define ACE_HAS_AUTOMATIC_INIT_FINI 1

// Manually tweak the malloc control block paddings to properly align
// things.
#define ACE_MALLOC_PADDING 16
#define ACE_MALLOC_ALIGN 8
#define ACE_PI_CONTROL_BLOCK_ALIGN_LONGS  3

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

#define ACE_HAS_SYS_PSTAT_H

// But doesn't have a prototype for syscall()
#define ACE_LACKS_SYSCALL

// Platform supports POSIX.1b clock_gettime ()
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME

#define ACE_LACKS_CLOCK_MONOTONIC
#define ACE_LACKS_MONOTONIC_TIME

// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Compiler/platform has Dirent iterator functions.
#define ACE_HAS_DIRENT

#define ACE_HAS_VSWPRINTF

// Platform supports getpagesize() call
#define ACE_HAS_GETPAGESIZE
// But we define this just to be safe
#define ACE_PAGE_SIZE 4096

// Can run gperf on this platform (needed for TAO)
#  define ACE_HAS_GPERF

// Optimize ACE_Handle_Set for select().
#  define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST
// At least for 11iv2, lacks perfect filtering.
#if (HPUX_VERS >= 1123) && !defined (ACE_LACKS_PERFECT_MULTICAST_FILTERING)
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#endif

/* Platform defines MAP_FAILED as a long constant. */
#define ACE_HAS_LONG_MAP_FAILED 1

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Platform's select() has non-const timeval argument
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

// Compiler/platform supports poll().
#define ACE_HAS_POLL

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Platform supports the POSIX struct timespec type
#define ACE_HAS_POSIX_TIME

/* Platform has pread() and pwrite() support. */
#define ACE_HAS_P_READ_WRITE 1

/* Platform will recurse infinitely on thread exits from TSS cleanup routines
   (e.g., AIX) */
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS 1

// Platform supports reentrant functions (all the POSIX *_r functions).
#define ACE_HAS_REENTRANT_FUNCTIONS
// ctime_r and asctime_r conform to POSIX.1c (2 param version)
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

// Platform offers scandir(), and requires no adjustments for its API.
#define ACE_HAS_SCANDIR

// HP-UX 11 has reentrant netdb functions.  The catch is that the old
// functions (gethostbyname, etc.) are thread-safe and the _r versions are
// not used and will be removed at some point.  So, define things so
// the _r versions are not used.  This will slow things down a bit due to
// the extra mutex lock in the ACE_NETDBCALL_RETURN macro, and will be fixed
// in the future (problem ID P64).
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS

/* Platform lacks pri_t (e.g., Tandem NonStop UNIX). */
#define ACE_LACKS_PRI_T 1

// Platform has shm_open
#define ACE_HAS_SHM_OPEN

// Compiler/platform defines the sig_atomic_t typedef
#define ACE_HAS_SIG_ATOMIC_T

/* Compiler requires extern "C" functions for signals. */
#define ACE_HAS_SIG_C_FUNC 1

// Platform's sigaction() function takes const sigaction* as 2nd parameter.
#define ACE_HAS_SIGACTION_CONSTP2

#define ACE_HAS_SSIZE_T

// Platform supports SVR4 extended signals
#define ACE_HAS_SIGINFO_T

/* Define to 1 if platform has sigsuspend(). */
#define ACE_HAS_SIGSUSPEND 1

// Platform doesn't detect a signal out of range unless it's way out of range.
#define ACE_HAS_SIGISMEMBER_BUG

/* Platform provides socklen_t type, such as Linux with glibc2. */
#define ACE_HAS_SOCKLEN_T 1

#define ACE_HAS_XPG4_MULTIBYTE_CHAR

#define ACE_HAS_UALARM

// Platform supports ucontext_t (which is used in the extended signal API).
#define ACE_HAS_UCONTEXT_T

// Platform/compiler supports void * as second parameter to gettimeofday().
#define ACE_HAS_VOIDPTR_GETTIMEOFDAY

/* Platform requires void * for mmap(). */
#define ACE_HAS_VOIDPTR_MMAP 1

/* OS/compiler uses void * arg 4 setsockopt() rather than const char * */
#define ACE_HAS_VOIDPTR_SOCKOPT 1

// Platform supports SVR4 dynamic linking semantics.
// When used, this requires -ldl on the ACE library link line.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Platform supports the getrusage() system call.
#define ACE_HAS_GETRUSAGE

/* Define to 1 if platform has the declaration of getrusage(). */
#define ACE_HAS_GETRUSAGE_PROTOTYPE 1

// Platform has the sigwait function in a header file
#define ACE_HAS_SIGWAIT
#define ACE_HAS_SIGTIMEDWAIT

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

// accept() is thread-safe
#define ACE_HAS_THREAD_SAFE_ACCEPT

// Platform lacks a typedef for timespec_t, but has struct timespec
#define ACE_LACKS_TIMESPEC_T

// dlopen() takes a char* instead of const char*
#define ACE_HAS_CHARPTR_DL

// lacks setegid and seteuid
#define ACE_LACKS_SETEGID
#define ACE_LACKS_SETEUID

#define ACE_LACKS_SUSECONDS_T
#define ACE_LACKS_SYS_SYSCTL_H

#if !(defined(__STDC_EXT__) || defined(_INCLUDE_LONGLONG) || defined(_INCLUDE_STDC__SOURCE_199901))
#  define ACE_LACKS_STRTOLL
#  define ACE_LACKS_WCSTOLL
#  define ACE_LACKS_STRTOULL
#  define ACE_LACKS_WCSTOULL
#endif

#define ACE_LACKS_ISWASCII

#define ACE_LACKS_SETENV
#define ACE_LACKS_UNSETENV

// Shared library name/path components
#if defined (__ia64)
#  define ACE_DLL_SUFFIX  ACE_TEXT (".so")
#else
#  define ACE_DLL_SUFFIX  ACE_TEXT (".sl")
#endif  /* __ia64 */
#if defined (__LP64__)
#  define ACE_LD_SEARCH_PATH ACE_TEXT ("LD_LIBRARY_PATH")
#else
#  define ACE_LD_SEARCH_PATH ACE_TEXT ("SHLIB_PATH")
#endif  /* __LP64__ */

#if defined (_INCLUDE__STDC_A1_SOURCE)
#  define ACE_HAS_3_PARAM_WCSTOK
#endif

#define ACE_HAS_3_PARAM_READDIR_R

#define ACE_LACKS_STRUCT_LIFNUM

//////////////////////////////////////////////////////////////////////////
//
// STREAMS information
//
//////////////////////////////////////////////////////////////////////////

// Platform supports STREAMS
#define ACE_HAS_STREAMS
// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T
// But the putmsg signature doesn't have it as const...
// Well, it really does, but it depends on preprocessor defines.
#define ACE_LACKS_CONST_STRBUF_PTR
/* Platform supports TLI timod STREAMS module */
#define ACE_HAS_TIMOD_H 1

// Platform supports STREAM pipes
// This is possible, but not by default - need to rebuild the kernel to
// get them enabled - see pipe(2) and "STREAMS/UX for the HP 9000"
// #define ACE_HAS_STREAM_PIPES

/////////////////////////////////////////////////////////////////////////
//
// TLI/XTI information
//
////////////////////////////////////////////////////////////////////////

// Platform supports XTI (includes TLI).
#define ACE_HAS_XTI
// HP-UX 11 conforms to the XPG4 spec, which ACE calls broken for the
// errmsg not being const...
#define ACE_HAS_BROKEN_T_ERROR
// The definitions of TCP_NODELAY and TCP_MAXSEG conflict between
// sys/xti.h and netinet/tcp.h.
#define ACE_HAS_CONFLICTING_XTI_MACROS
/* Platform provides <sys/xti.h> header */
#define ACE_HAS_SYS_XTI_H 1

/////////////////////////////////////////////////////////////////////////
//
// Threads information.
//
// Use of threads is controlled by the 'threads' argument to make.  See
// include/makeinclude/platform_hpux_aCC.GNU for details. If it's not set,
// the default is to enable it, since kernel threads are always available
// on HP-UX 11, as opposed to 10.x where it was optional software.
//
////////////////////////////////////////////////////////////////////////

#if defined (ACE_HAS_THREADS)
#  if (ACE_HAS_THREADS == 0)
#    undef ACE_HAS_THREADS
#  endif /* ACE_HAS_THREADS == 0 */
#else
#  define ACE_HAS_THREADS
#endif /* ACE_HAS_THREADS */

#if defined (ACE_HAS_THREADS)

#  if !defined (ACE_MT_SAFE)
#    define ACE_MT_SAFE 1
#  endif

// HP-UX doesn't define _POSIX_THREADS since it doesn't implement all
// features (lacks thread priority inheritance and protection), so
// config-posix.h doesn't get this one...
#  define ACE_HAS_PTHREADS
#  define ACE_HAS_PTHREADS_UNIX98_EXT
#  define ACE_HAS_PTHREAD_CONTINUE
#  define ACE_HAS_PTHREAD_RESUME_NP
#  define ACE_HAS_PTHREAD_SUSPEND
#  define ACE_HAS_RECURSIVE_MUTEXES
#  define ACE_HAS_THREAD_SPECIFIC_STORAGE
#  define ACE_LACKS_PTHREAD_ATTR_SETSTACK
#  define ACE_LACKS_CONDATTR_SETCLOCK
#endif /* ACE_HAS_THREADS */

#define ACE_HAS_POSIX_SEM

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// gethostbyaddr does not handle IPv6-mapped-IPv4 addresses
#define ACE_HAS_BROKEN_GETHOSTBYADDR_V4MAPPED

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */
