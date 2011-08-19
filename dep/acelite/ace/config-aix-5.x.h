// $Id: config-aix-5.x.h 91685 2010-09-09 09:35:14Z johnnyw $
//
// Config file for AIX 5.1 and higher.

#ifndef ACE_CONFIG_AIX_5_X_H
#define ACE_CONFIG_AIX_5_X_H

// This define is needed for building with Visual Age C++ 5 in incremental
// mode. In the batch mode build, platform_aix_ibm.GNU sets it. The incremental
// mode compiler won't be supported after ACE 5.3, so this will also go away
// in that timeframe, so don't worry about future AIX versions.
#if !defined (ACE_AIX_VERS)
#  define ACE_AIX_VERS 501
#endif

// AIX 5.1 has AIO, but it doesn't have the same API as other POSIX
// systems, and the semantics of operations are a bit different. Will take
// some real work to get this going.
// AIX 5.2, however, has the POSIX API implemented. However, the libc functions
// to implement it aren't exported by default. You need to use smit to enable
// them. So, leave AIO disabled unless the user explicitly enables it.
// config-aix-4.x.h will set ACE_HAS_AIO_CALLS if config-posix.h senses the
// feature-test macros, so set up _ACE_DISABLE_AIO_CALLS_ if the user didn't
// set it. Then check for it after including config-aix-4.x.h and remove
// ACE_HAS_AIO_CALLS if so.
#if !defined (ACE_HAS_AIO_CALLS)
#  define _ACE_DISABLE_AIO_CALLS_
#endif

// Both IBM and g++ compilers set _THREAD_SAFE if compiler is asked to compile
// threaded code (xlC_r, as opposed to xlC; and g++ -pthread)
#if !defined (ACE_MT_SAFE) || (ACE_MT_SAFE != 0)
#  if defined (ACE_HAS_THREADS)
#    undef ACE_HAS_THREADS
#  endif
#  if defined (_THREAD_SAFE)
#    define ACE_HAS_THREADS 1
// #  else
// #    define ACE_HAS_THREADS 0
#  endif /* _THREAD_SAFE */
#endif /* !ACE_MT_SAFE || (ACE_MT_SAFE != 0) */

#if defined (__IBMCPP__)
   // AIX xlC, IBM C/C++ compiler
   //********************************************************************
   //

   // Compiler does this with a builtin - it's not in libc.
   // Although ACE does have alloca() on this compiler/platform combination,
   // it is disabled by default since it can be dangerous.  Uncomment the
   // following line if you ACE to use it.
   //#  define ACE_HAS_ALLOCA

   // Compiler supports the ssize_t typedef.
#  define ACE_HAS_SSIZE_T

   // Keep an eye on this as the compiler and standards converge...
#  define ACE_LACKS_LINEBUFFERED_STREAMBUF
#  define ACE_LACKS_PRAGMA_ONCE

#  define ACE_EXPLICIT_TEMPLATE_DESTRUCTOR_TAKES_ARGS
   // When using -qtempinc, we don't need to see template implementation
   // source (though we do need a pragma to find the correct source file).
   // However, without -qtempinc (either -qnotempinc or -qtemplateregistry)
   // we do need to see the source.
#  if defined (__TEMPINC__)
#    if !defined ACE_TEMPLATES_REQUIRE_PRAGMA
#      define ACE_TEMPLATES_REQUIRE_PRAGMA
#    endif
#  else
#    if !defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#      define ACE_TEMPLATES_REQUIRE_SOURCE
#    endif
#  endif /* __TEMPINC__ */

#  undef WIFEXITED
#  undef WEXITSTATUS
#  define ACE_HAS_STANDARD_CPP_LIBRARY 1
#  define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1

#  define ACE_HAS_CUSTOM_EXPORT_MACROS
#  define ACE_Proper_Export_Flag
#  define ACE_Proper_Import_Flag
   // There's no explicit import/export per-se, but to be sure that declared
   // template code is exported, explicitly instantiate the class.
#  define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class SINGLETON_TYPE < CLASS, LOCK >;
#  define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) extern template class SINGLETON_TYPE < CLASS, LOCK >;

#elif defined (__GNUG__)
  // config-g++-common.h undef's ACE_HAS_STRING_CLASS with -frepo, so
  // this must appear before its #include.
# define ACE_HAS_STRING_CLASS

# include "ace/config-g++-common.h"

# define ACE_HAS_SSIZE_T

# if (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ == 0))
// We have to explicitly instantiate static template members prior to g++ 4.1
#   define ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION
#endif /* g++ prior to 4.1 */

# if !defined (ACE_MT_SAFE) || ACE_MT_SAFE != 0
    // ACE_MT_SAFE is #defined below, for all compilers.
#   if !defined (_REENTRANT)
#     define _REENTRANT
#   endif /* _REENTRANT */
# endif /* !ACE_MT_SAFE */

#else  /* ! __IBMCPP__ && ! __GNUG__ */
#  ifdef __cplusplus  /* Let it slide for C compilers. */
#    error unsupported compiler in ace/config-aix-5.x.h
#  endif  /* __cplusplus */
#endif /* ! __xlC__ && ! __GNUG__ */

// Compiling for AIX.
#ifndef AIX
#  define AIX
#endif /* AIX */

// Pick up all the detectable settings.
#include "ace/config-posix.h"

// Regardless of what config-posix.h may indicate, AIX 5.3 is the first
// to support sem_timedwait(). Prior to that, use the emulation.
#if defined (ACE_HAS_POSIX_SEM_TIMEOUT) && \
  (defined (ACE_AIX_VERS) && (ACE_AIX_VERS < 503))
#  undef ACE_HAS_POSIX_SEM_TIMEOUT
#endif /* ACE_HAS_POSIX_SEM_TIMEOUT && ACE_AIX_VERS < 503 */

#if defined (ACE_DLL_SUFFIX)
#  undef ACE_DLL_SUFFIX
#endif
#define ACE_DLL_SUFFIX ACE_TEXT (".so")

#define ACE_DEFAULT_BASE_ADDR ((char *) 0x80000000)

#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

#define ACE_HAS_SOCKLEN_T
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG

// AIX has AIO, but the functions don't match those of other AIO-enabled
// platforms. If this is to work, it'll require some significant work,
// maybe moving the OS-abstraction stuff to an OS_AIO or some such thing.
//#  define ACE_HAS_AIO_CALLS

#define ACE_HAS_AIX_HI_RES_TIMER

// Compiler/platform has correctly prototyped header files.
#define ACE_HAS_CPLUSPLUS_HEADERS

// Prototypes for both signal() and struct sigaction are consistent.
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES

// OS has readdir and friends.
#define ACE_HAS_DIRENT

// OS supports the getrusage() system call
#define ACE_HAS_GETRUSAGE

#define ACE_HAS_GPERF

#define ACE_HAS_H_ERRNO

#define ACE_LACKS_STDINT_H
#define ACE_LACKS_SYS_SYSCTL_H

#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_ICMP_SUPPORT 1
#define ACE_HAS_IP_MULTICAST

// Lacks perfect filtering, must bind group address.
#if !defined ACE_LACKS_PERFECT_MULTICAST_FILTERING
# define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#endif /* ACE_LACKS_PERFECT_MULTICAST_FILTERING */

#define ACE_HAS_MSG

// Compiler/platform supports poll().
#define ACE_HAS_POLL

// Platform supports POSIX O_NONBLOCK semantics.
#define ACE_HAS_POSIX_NONBLOCK

#define ACE_HAS_POSIX_TIME
// ... but needs to include another header for it on 4.2+
#  define ACE_HAS_BROKEN_POSIX_TIME
// ... and needs another typedef
#define ACE_LACKS_TIMESPEC_T
#define ACE_HAS_SELECT_H

#define ACE_HAS_REENTRANT_FUNCTIONS

// Compiler/platform defines the sig_atomic_t typedef
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_SIGINFO_T
#define ACE_LACKS_SIGINFO_H
#define ACE_HAS_P_READ_WRITE

#define ACE_HAS_SIGWAIT
#define ACE_HAS_SOCKADDR_IN_SIN_LEN
#define ACE_HAS_STRBUF_T

// Compiler supports stropts.h
#define ACE_HAS_STREAMS
// #define ACE_HAS_STREAM_PIPES

// AIX bzero()
#define ACE_HAS_STRINGS

#define ACE_HAS_STRUCT_NETDB_DATA

// Dynamic linking is in good shape on newer OS/patch levels.  If you have
// trouble with the dynamic linking parts of ACE, and can't patch your OS
// up to latest levels, comment this out.
#define ACE_HAS_SVR4_DYNAMIC_LINKING
// This is tightly related to dynamic linking...
#define ACE_HAS_AUTOMATIC_INIT_FINI

#define ACE_HAS_SVR4_GETTIMEOFDAY

#define ACE_HAS_SYSV_IPC
#define ACE_HAS_TIMOD_H
#define ACE_HAS_XTI
#define ACE_HAS_BROKEN_T_ERROR
#define ACE_TLI_TCP_DEVICE  "/dev/xti/tcp"

#define ACE_HAS_UALARM

#define ACE_HAS_UCONTEXT_T

#define ACE_HAS_UTIME

#define ACE_HAS_CTYPE_T

// Platform has XPG4 wide character type and functions. However, the size
// of wchar_t changes for 32- vs. 64-bit builds (unsigned short vs. unsigned
// int, respectively).
#define ACE_HAS_XPG4_MULTIBYTE_CHAR
#ifdef __64BIT__
#  define ACE_SIZEOF_WCHAR 4
#else
#  define ACE_SIZEOF_WCHAR 2
#endif /* __64BIT__ */

#define ACE_LACKS_NETINET_TCP_H

// AIX uses LIBPATH to search for libraries
#define ACE_LD_SEARCH_PATH ACE_TEXT ("LIBPATH")

// Defines the page size of the system.
#define ACE_PAGE_SIZE 4096

//**************************************************************
//
// Threads related definitions.
//
// The threads on AIX are generally POSIX P1003.1c (ACE_HAS_PTHREADS).
// However, there is also a kernel thread ID (tid_t) that is used in
// ACE_Log_Msg (printing the thread ID).  The tid_t is not the same as
// pthread_t, and can't derive one from the other - thread_self() gets
// the tid_t (kernel thread ID) if called from a thread.
// Thanks very much to Chris Lahey for straightening this out.

#if defined (ACE_HAS_THREADS)
#  if !defined (ACE_MT_SAFE)
#    define ACE_MT_SAFE 1
#  endif

#  define ACE_HAS_PTHREADS
#  define ACE_HAS_PTHREADS_UNIX98_EXT
#  define ACE_HAS_PTHREAD_CONTINUE_NP
#  define ACE_HAS_PTHREAD_SUSPEND_NP
#  define ACE_HAS_RECURSIVE_MUTEXES
#  define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS
#  define ACE_HAS_SIGTHREADMASK
#  define ACE_HAS_THREAD_SPECIFIC_STORAGE

#  define ACE_LACKS_THREAD_PROCESS_SCOPING
#else
#  undef ACE_HAS_THREADS
#endif /* ACE_HAS_THREADS != 0 */

#define ACE_MALLOC_ALIGN 8

#if (defined _XOPEN_SOURCE && (_XOPEN_SOURCE - 0) >= 500) && !defined(_UNIX95)
# define ACE_HAS_3_PARAM_WCSTOK
#endif /* (_XOPEN_SOURCE -0) >= 500 && !_UNIX95 */

#if defined (_ACE_DISABLE_AIO_CALLS_)
#  if defined (ACE_HAS_AIO_CALLS)
#    undef ACE_HAS_AIO_CALLS
#  endif
#  undef _ACE_DISABLE_AIO_CALLS_
#endif

// AIX's /usr/include/unistd.h sets _POSIX_SEMAPHORE to indicate the system
// supplies such a facility, but the headers don't enable it unless
// _XOPEN_SOURCE >= 500. So disable semaphores here if _XOPEN_SOURCE isn't
// up to snuff.
#if defined (ACE_HAS_POSIX_SEM) && \
    (!defined (_XOPEN_SOURCE) || (_XOPEN_SOURCE-0 < 500))
#  undef ACE_HAS_POSIX_SEM
#endif

// I think this is correct, but needs to be verified...   -Steve Huston
#define ACE_HAS_SIGTIMEDWAIT

// AIX 5.1 has netinet/tcp.h
#undef ACE_LACKS_NETINET_TCP_H

#define ACE_HAS_3_PARAM_READDIR_R
#define ACE_HAS_POSIX_GETPWNAM_R
#define ACE_HAS_SCANDIR
#define ACE_SCANDIR_CMP_USES_VOIDPTR
#define ACE_SCANDIR_SEL_LACKS_CONST
#define ACE_HAS_SIGSUSPEND
#define ACE_HAS_TIMEZONE  /* Call tzset() to set timezone */
#define ACE_LACKS_ISCTYPE
#define ACE_HAS_STRSIGNAL
#define ACE_NEEDS_STRSIGNAL_RANGE_CHECK

#endif /* ACE_CONFIG_AIX_5_X_H */
