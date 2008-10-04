/* -*- C++ -*- */
// $Id: config-sunos5.5.h 81971 2008-06-16 12:15:00Z parsons $

// This configuration file is designed to work for SunOS 5.5 platforms
// using the following compilers:
//   * Sun C++ 4.2 and later (including 5.x), patched as noted below
//   * g++ 2.7.2 and later, including egcs
//   * Green Hills 1.8.8 and later

#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"

#define ACE_LACKS_STDINT_H

// alphasort() is present on earlier Solaris versions but is marked as not for
// use on non-BSD systems and not supported for use in applications that use
// system libraries or with multiple threads. So it's mostly useless.
#define ACE_LACKS_ALPHASORT

// Solaris doesn't support log2()
#define ACE_LACKS_LOG2

// SunOS 5.5 does not provide getloadavg()
#define ACE_LACKS_GETLOADAVG

// Before we do anything, we should include <sys/feature_tests.h> to
// ensure that things are set up properly.
#include <sys/feature_tests.h>

// Sun has the posix defines so let this file sort out what Sun delivers
#include "ace/config-posix.h"

// Compiler version-specific settings:
#if defined (__SUNPRO_CC)
# if (__SUNPRO_CC < 0x410)
    // The following might not be necessary, but I can't tell: my build
    // with Sun C++ 4.0.1 never completes.
#   define ACE_NEEDS_DEV_IO_CONVERSION
# elif (__SUNPRO_CC >= 0x420)
# if (__SUNPRO_CC >= 0x500)
    // string.h and memory.h conflict for memchr definitions
#   define ACE_LACKS_MEMORY_H
    // If -compat=4 is turned on, the old 4.2 settings for iostreams are used,
    // but the newer, explicit instantiation is used (above)
#   if (__SUNPRO_CC_COMPAT >= 5)
#     define ACE_HAS_TEMPLATE_TYPEDEFS
#     define ACE_HAS_STANDARD_CPP_LIBRARY 1
#     define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#     define ACE_HAS_THR_C_DEST
#   endif /* __SUNPRO_CC_COMPAT >= 5 */
#  if defined (ACE_HAS_EXCEPTIONS)
#    define ACE_HAS_NEW_NOTHROW
#  else
     // See /opt/SUNWspro_5.0/SC5.0/include/CC/stdcomp.h:
#    define _RWSTD_NO_EXCEPTIONS 1
#  endif /* ! ACE_HAS_EXCEPTIONS */
# elif (__SUNPRO_CC == 0x420) || (__SUNPRO_CC == 0x410)
# define ACE_LACKS_PLACEMENT_OPERATOR_DELETE
# endif /* __SUNPRO_CC >= 0x500 */
# endif /* __SUNPRO_CC >= 0x420 */

# define ACE_CAST_CONST const
# define ACE_HAS_HI_RES_TIMER
# define ACE_HAS_SIG_C_FUNC /* Sun CC 5.0 needs this, 4.2 doesn't mind. */
# define ACE_HAS_XPG4_MULTIBYTE_CHAR
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_SIGNED_CHAR

  // ACE_HAS_EXCEPTIONS precludes -noex in
  // include/makeinclude/platform_macros.GNU.  But beware, we have
  // seen problems with exception handling on multiprocessor
  // UltraSparcs:  threaded executables core dump when threads exit.
  // This problem does not seem to appear on single-processor UltraSparcs.
  // And, it is solved with the application of patch
  //   104631-02 "C++ 4.2: Jumbo Patch for C++ 4.2 on Solaris SPARC"
  // to Sun C++ 4.2.
  // To provide optimum performance, ACE_HAS_EXCEPTIONS is disabled by
  // default.  It can be enabled by adding "exceptions=1" to the "make"
  // invocation.  See include/makeinclude/platform_sunos5_sunc++.GNU
  // for details.

#  if defined (ACE_HAS_EXCEPTIONS)
     // If exceptions are enabled and we are using Sun/CC then
     // <operator new> throws an exception instead of returning 0.
#    define ACE_NEW_THROWS_EXCEPTIONS
#  endif /* ACE_HAS_EXCEPTIONS */

    /* If you want to disable threading with Sun CC, remove -mt
       from your CFLAGS, e.g., using make threads=0. */


// Take advantage of Sun Studio 8 (Sun C++ 5.5) or better symbol
// visibility to generate improved shared library binaries.
#  if (__SUNPRO_CC > 0x540)

#    if defined (ACE_HAS_CUSTOM_EXPORT_MACROS) && ACE_HAS_CUSTOM_EXPORT_MACROS == 0
#     undef ACE_HAS_CUSTOM_EXPORT_MACROS
#    else
#      ifndef ACE_HAS_CUSTOM_EXPORT_MACROS
#        define ACE_HAS_CUSTOM_EXPORT_MACROS
#      endif  /* !ACE_HAS_CUSTOM_EXPORT_MACROS */
#      define ACE_Proper_Export_Flag __symbolic
#      define ACE_Proper_Import_Flag __global

#      define ACE_EXPORT_SINGLETON_DECLARATION(T) template class ACE_Proper_Export_Flag T
#      define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class ACE_Proper_Export_Flag SINGLETON_TYPE <CLASS, LOCK>;

// #      define ACE_IMPORT_SINGLETON_DECLARATION(T) extern template class T
// #      define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) extern template class SINGLETON_TYPE<CLASS, LOCK>;

#    endif  /* ACE_HAS_CUSTOM_EXPORT_MACROS == 0 */
#  endif  /* __SUNPRO_CC > 0x540 (> Sun C++ 5.4) */

#elif defined (__GNUG__)
  // config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS
# include "ace/config-g++-common.h"
# define ACE_HAS_HI_RES_TIMER
  // Denotes that GNU has cstring.h as standard, to redefine memchr().
# define ACE_HAS_GNU_CSTRING_H
# define ACE_HAS_XPG4_MULTIBYTE_CHAR

# if !defined (ACE_MT_SAFE) || ACE_MT_SAFE != 0
    // ACE_MT_SAFE is #defined below, for all compilers.
#   if !defined (_REENTRANT)
    /* If you want to disable threading, comment out the following
       line.  Or, add -DACE_MT_SAFE=0 to your CFLAGS, e.g., using
       make threads=0. */
#     define _REENTRANT
#   endif /* _REENTRANT */
# endif /* !ACE_MT_SAFE */

#elif defined (ghs)

# if !defined (ACE_MT_SAFE) || ACE_MT_SAFE != 0
    // ACE_MT_SAFE is #defined below, for all compilers.
#   if !defined (_REENTRANT)
    /* If you want to disable threading, comment out the following
       line.  Or, add -DACE_MT_SAFE=0 to your CFLAGS, e.g., using
       make threads=0. */
#     define _REENTRANT
#   endif /* _REENTRANT */
# endif /* !ACE_MT_SAFE */

# define ACE_CONFIG_INCLUDE_GHS_COMMON
# include "ace/config-ghs-common.h"

  // To avoid warning about inconsistent declaration between Sun's
  // stdlib.h and Green Hills' ctype.h.
# include <stdlib.h>

  // IOStream_Test never halts with Green Hills 1.8.9.
# define ACE_LACKS_ACE_IOSTREAM

#else  /* ! __SUNPRO_CC && ! __GNUG__  && ! ghs */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#    error unsupported compiler in ace/config-sunos5.5.h
#  endif /* __cplusplus */
#endif /* ! __SUNPRO_CC && ! __GNUG__  && ! ghs */

#if !defined (__ACE_INLINE__)
// @note If you have link problems with undefined inline template
// functions with Sun C++, be sure that the #define of __ACE_INLINE__
// below is not commented out.
# define __ACE_INLINE__
#endif /* ! __ACE_INLINE__ */

// Platform supports the POSIX regular expression library.
// @note Please comment out the ACE_HAS_REGEX #define if you
// have link problems with g++ or egcs on SunOS 5.5.
#define ACE_HAS_REGEX

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// select()'s timeval arg is not declared as const and may be modified
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

// Platform supports pread() and pwrite()
#define ACE_HAS_P_READ_WRITE
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#define ACE_HAS_UALARM
#define ACE_LACKS_UALARM_PROTOTYPE

// Platform supports System V IPC (most versions of UNIX, but not Win32)
#define ACE_HAS_SYSV_IPC

#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// Platform supports system configuration information.
#define ACE_HAS_SYS_SYSTEMINFO_H
#define ACE_HAS_SYSINFO

// Platform supports recvmsg and sendmsg.
#define ACE_HAS_MSG

// Compiler/platform contains the <sys/syscall.h> file.
#define ACE_HAS_SYS_SYSCALL_H

// Platform has POSIX terminal interface.
#define ACE_HAS_TERMIOS

// Compiler/platform correctly calls init()/fini() for shared libraries.
#define ACE_HAS_AUTOMATIC_INIT_FINI

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Platform supports IP multicast
#define ACE_HAS_IP_MULTICAST

// This setting was determined by running the autoconf tests. If it doesn't
// work uniformly, will need some tweaking, possibly based on other
// XPG feature-test macros.
#define ACE_HAS_CONST_CHAR_SWAB

// Compiler/platform supports alloca()
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA

// Compiler/platform has <alloca.h>
#define ACE_HAS_ALLOCA_H

// Platform contains <poll.h>.
#define ACE_HAS_POLL

// Platform supports POSIX timers via timestruc_t.
#define ACE_HAS_POSIX_TIME

// ACE_HAS_CLOCK_GETTIME requires linking with -lposix4.
#define ACE_HAS_CLOCK_GETTIME
#define ACE_HAS_CLOCK_SETTIME

// Platform supports the /proc file system.
#define ACE_HAS_PROC_FS

// Platform supports the prusage_t struct.
#define ACE_HAS_PRUSAGE_T
#define ACE_HAS_GETRUSAGE

// Compiler/platform defines the sig_atomic_t typedef.
#define ACE_HAS_SIG_ATOMIC_T

// Platform supports SVR4 extended signals.
#define ACE_HAS_SIGINFO_T
#define ACE_HAS_UCONTEXT_T

// Compiler/platform provides the sockio.h file.
#define ACE_HAS_SYS_SOCKIO_H

// Compiler supports the ssize_t typedef.
#define ACE_HAS_SSIZE_T

// Platform supports STREAMS.
#define ACE_HAS_STREAMS

// Platform supports STREAM pipes.
#define ACE_HAS_STREAM_PIPES

// Compiler/platform supports strerror ().
#define ACE_HAS_STRERROR

// Compiler/platform supports struct strbuf.
#define ACE_HAS_STRBUF_T

// Compiler/platform supports SVR4 dynamic linking semantics.
#define ACE_HAS_SVR4_DYNAMIC_LINKING

// Compiler/platform supports SVR4 gettimeofday() prototype.
#define ACE_HAS_SVR4_GETTIMEOFDAY

// Compiler/platform supports SVR4 ACE_TLI (in particular, T_GETNAME stuff)...
#define ACE_HAS_SVR4_TLI

// Platform provides <sys/filio.h> header.
#define ACE_HAS_SYS_FILIO_H

// Compiler/platform supports sys_siglist array.
#define ACE_HAS_SYS_SIGLIST

// SunOS 5.5.x does not support mkstemp
#define ACE_LACKS_MKSTEMP
#define ACE_LACKS_SYS_SYSCTL_H

#if !(defined(_XOPEN_SOURCE) && (_XOPEN_VERSION - 0 >= 4))
#  define ACE_HAS_CHARPTR_SHMDT
#endif

// Platform has posix getpwnam_r
#if (defined (_POSIX_C_SOURCE) && _POSIX_C_SOURCE - 0 >= 199506L) || \
    defined(_POSIX_PTHREAD_SEMANTICS)
# define ACE_HAS_POSIX_GETPWNAM_R
#endif /* _POSIX_C_SOURCE || _POSIX_PTHREAD_SEMANTICS */

#if !defined (ACE_MT_SAFE) || (ACE_MT_SAFE == 1)
#if defined (_REENTRANT) || \
 (defined (_POSIX_C_SOURCE) && (_POSIX_C_SOURCE - 0 >= 199506L)) || \
 defined (_POSIX_PTHREAD_SEMANTICS)
  // Compile using multi-thread libraries.
# define ACE_HAS_THREADS

# if !defined (ACE_MT_SAFE)
#   define ACE_MT_SAFE 1
# endif /* ACE_MT_SAFE */

  // Platform supports POSIX pthreads *and* Solaris threads, by
  // default!  If you only want to use POSIX pthreads, add
  // -D_POSIX_PTHREAD_SEMANTICS to your CFLAGS.  Or, #define it right
  // here.  See the Intro (3) man page for information on
  // -D_POSIX_PTHREAD_SEMANTICS.
# if defined (_POSIX_PTHREAD_SEMANTICS)
#   define ACE_LACKS_RWLOCK_T
# else
#   define ACE_HAS_STHREADS
# endif /* ! _POSIX_PTHREAD_SEMANTICS */

# define ACE_HAS_PTHREADS
  // . . . but only supports SCHED_OTHER scheduling policy
# define ACE_HAS_ONLY_SCHED_OTHER
# define ACE_HAS_SIGWAIT
# define ACE_HAS_SIGTIMEDWAIT
# define ACE_HAS_SIGSUSPEND
# define ACE_LACKS_PTHREAD_ATTR_SETSTACK

  // Compiler/platform has thread-specific storage
# define ACE_HAS_THREAD_SPECIFIC_STORAGE

  // Platform supports reentrant functions (i.e., all the POSIX *_r functions).
# define ACE_HAS_REENTRANT_FUNCTIONS

# define ACE_NEEDS_LWP_PRIO_SET
# define ACE_HAS_THR_YIELD
# define ACE_LACKS_PTHREAD_YIELD
#endif /* _REENTRANT || _POSIX_C_SOURCE >= 199506L || \
          _POSIX_PTHREAD_SEMANTICS */
#endif /* !ACE_MT_SAFE || ACE_MT_SAFE == 1 */

#define ACE_HAS_PRIOCNTL

// Platform supports ACE_TLI timod STREAMS module.
#define ACE_HAS_TIMOD_H

// Platform supports ACE_TLI tiuser header.
#define ACE_HAS_TIUSER_H

// Platform provides ACE_TLI function prototypes.
#define ACE_HAS_TLI_PROTOTYPES

// Platform has broken t_error() prototype.
#define ACE_HAS_BROKEN_T_ERROR

// Platform supports ACE_TLI.
#define ACE_HAS_TLI

#define ACE_HAS_GETPAGESIZE 1

#define ACE_HAS_STL_MAP_CONFLICT

#define ACE_HAS_IDTYPE_T

#define ACE_HAS_GPERF
#define ACE_HAS_DIRENT

#if defined (__SUNPRO_CC)
# define ACE_CC_NAME ACE_TEXT ("SunPro C++")
# define ACE_CC_MAJOR_VERSION (__SUNPRO_CC >> 8)
# define ACE_CC_MINOR_VERSION (__SUNPRO_CC & 0x00ff)
# define ACE_CC_BETA_VERSION  (0)
#elif defined (__GNUG__)
# define ACE_CC_MAJOR_VERSION __GNUC__
# define ACE_CC_MINOR_VERSION __GNUC_MINOR__
# define ACE_CC_BETA_VERSION  (0)
# if __GNUC_MINOR__ >= 90
#   define ACE_CC_NAME ACE_TEXT ("egcs")
# else
#   define ACE_CC_NAME ACE_TEXT ("g++")
# endif /* __GNUC_MINOR__ */
#endif /* __GNUG__ */

#if defined (i386) && (_FILE_OFFSET_BITS==32)
# define ACE_HAS_X86_STAT_MACROS
#endif /* i386 && _FILE_OFFSET_BITS==32 */

#define ACE_MALLOC_ALIGN ((size_t)8)
#define ACE_LACKS_SETREUID_PROTOTYPE
#define ACE_LACKS_SETREGID_PROTOTYPE

// Solaris does indeed implement the inet_aton() function, but it is
// found in `libresolv.*'.  It doesn't seem worth it to link another
// library just for that function.  Just use the emulation in ACE that
// has been used for years.
#define ACE_LACKS_INET_ATON

// Solaris doesn't have wcstoull
#define ACE_LACKS_WCSTOULL

#if defined (_LARGEFILE_SOURCE) || (_FILE_OFFSET_BITS==64)
#undef ACE_HAS_PROC_FS
#undef ACE_HAS_PRUSAGE_T
#endif /* (_LARGEFILE_SOURCE) || (_FILE_OFFSET_BITS==64) */

#if defined (_POSIX_PTHREAD_SEMANTICS) || (_FILE_OFFSET_BITS == 64) || (_POSIX_C_SOURCE - 0 >= 199506L)
#  define ACE_HAS_3_PARAM_READDIR_R
#endif

// Sum of the iov_len values can't be larger then SSIZE_MAX
#define ACE_HAS_SOCK_BUF_SIZE_MAX

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */
