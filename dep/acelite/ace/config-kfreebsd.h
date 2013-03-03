// $Id: config-kfreebsd.h 93550 2011-03-15 21:26:56Z olli $

#ifndef ACE_CONFIG_KFREEBSD_H
#define ACE_CONFIG_KFREEBSDH
#include "ace/config-g++-common.h"


/* Uses ctime_r & asctime_r with only two parameters vs. three. */
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R 1

/* Define to 1 if platform has 3 parameter readdir_r() */
#define ACE_HAS_3_PARAM_READDIR_R 1

/* Define to 1 if platform has 3 parameter wcstok() */
#define ACE_HAS_3_PARAM_WCSTOK 1

/* Platform has BSD 4.4 sendmsg()/recvmsg() APIs. */
#define ACE_HAS_4_4BSD_SENDMSG_RECVMSG 1

/* Platform supports Asynchronous IO calls */
#define ACE_HAS_AIO_CALLS 1

/* Use ACE's alternate cuserid() implementation since a system cuserid() may
   not exist, or it is not desirable to use it. The implementation requires
   ACE_LACKS_PWD_FUNCTIONS to be undefined and that the geteuid() system call
   exists. */
#define ACE_HAS_ALT_CUSERID 1

/* Compiler/platform correctly calls init()/fini() for shared libraries. */
#define ACE_HAS_AUTOMATIC_INIT_FINI 1

/* Define to 1 if platform has bswap_16(). */
#define ACE_HAS_BSWAP_16 1

/* Define to 1 if platform has bswap_32(). */
#define ACE_HAS_BSWAP_32 1

/* Define to 1 if platform has bswap_64(). */
#define ACE_HAS_BSWAP_64 1

/* Define to 1 if platform has the <byteswap.h> header file. */
#define ACE_HAS_BYTESWAP_H 1

/* Define to 1 if platform has clock_gettime(). */
#define ACE_HAS_CLOCK_GETTIME 1

/* Define to 1 if platform has clock_settime(). */
#define ACE_HAS_CLOCK_SETTIME 1

/* Prototypes for both signal() and struct sigaction are consistent. */
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES 1

/* Define to 1 if the system has the type `cpu_set_t'. */
#define ACE_HAS_CPU_SET_T 1

/* Platform supports operations on directories via struct dirent, readdir_r,
   etc. */
#define ACE_HAS_DIRENT 1

/* Compiler supports C++ exception handling. */
#define ACE_HAS_EXCEPTIONS 1

/* Define to 1 if platform has getifaddrs(). */
#define ACE_HAS_GETIFADDRS 1

/* Platform supports getpagesize() call (otherwise, ACE_PAGE_SIZE must be
   defined, except on Win32). */
#define ACE_HAS_GETPAGESIZE 1

/* Define to 1 if platform has getrusage(). */
#define ACE_HAS_GETRUSAGE 1

/* Define to 1 if platform has the declaration of getrusage(). */
#define ACE_HAS_GETRUSAGE_PROTOTYPE 1

/* Denotes that GNU has cstring.h as standard which redefines memchr() */
#define ACE_HAS_GNU_CSTRING_H 1

/* The GPERF utility is compiled for this platform */
#define ACE_HAS_GPERF 1

/* Optimize ACE_Handle_Set::count_bits for select() operations (common case)
   */
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT 1

/* Defined to 1 if platform supports ICMP over raw sockets */
#define ACE_HAS_ICMP_SUPPORT 1

/* Define to 1 if the system has the type `int16_t'. */
#define ACE_HAS_INT16_T 1

/* Define to 1 if the system has the type `int32_t'. */
#define ACE_HAS_INT32_T 1

/* Define to 1 if the system has the type `int64_t'. */
#define ACE_HAS_INT64_T 1

/* Define to 1 if the system has the type `int8_t'. */
#define ACE_HAS_INT8_T 1

/* Platform supports IPv6 */
#define ACE_HAS_IPV6 1

/* Platform supports IP multicast */
#define ACE_HAS_IP_MULTICAST 1

/* Define to 1 if platform has the declaration of isastream(). */
#define ACE_HAS_ISASTREAM_PROTOTYPE 1

/* Platform supports lseek64(). This should not be defined if ACE_HAS_LLSEEK
   is defined. */
#define ACE_HAS_LSEEK64 1

/* Define to 1 if platform has memchr(). */
#define ACE_HAS_MEMCHR 1

/* Define to 1 if unrolled ACE_OS::fast_memcpy() is faster than system
   memcpy() */
#define ACE_HAS_MEMCPY_LOOP_UNROLL 1

/* Define to 1 if platform has mkdir(). */
#define ACE_HAS_MKDIR 1

/* Platform supports recvmsg and sendmsg */
#define ACE_HAS_MSG 1

/* Compiler supports timed mutex acquisitions (e.g.
   pthread_mutex_timedlock()). */
#define ACE_HAS_MUTEX_TIMEOUTS 1

/* Define to 1 if platform has nanosleep(). */
#define ACE_HAS_NANOSLEEP 1

/* Define to 1 if platform has the <new.h> header file. */
#ifdef ACE_HAS_NEW_H
#undef ACE_HAS_NEW_H
#endif

#ifndef ACE_LACKS_NEW_H
#define ACE_LACKS_NEW_H 1
#endif

/* Platform provides new style C++ <new> header */
#define ACE_HAS_NEW_NO_H 1

/* Platform's select() uses non-const timeval* (only found on Linux right now)
   */
#define ACE_HAS_NONCONST_SELECT_TIMEVAL 1

/* Platform has swab(char*, char*, ssize_t) variant. */
#define ACE_HAS_NONCONST_SWAB 1

/* Platform contains <poll.h> */
#define ACE_HAS_POLL 1

/* Platform supports POSIX O_NONBLOCK semantics */
#define ACE_HAS_POSIX_NONBLOCK 1

/* Platform supports POSIX real-time semaphores (e.g., VxWorks and Solaris) */
#define ACE_HAS_POSIX_SEM 1

/* Platform supports the POSIX struct timespec type */
#define ACE_HAS_POSIX_TIME 1

/* Platform supports the /proc file system and defines tid_t in <sys/procfs.h>
   */
#define ACE_HAS_PROC_FS 1

/* Define to 1 if platform has POSIX threads */
#define ACE_HAS_PTHREADS 1

/* Platform has the UNIX98 extensions to Pthreads (rwlocks) */
#define ACE_HAS_PTHREADS_UNIX98_EXT 1

/* Define to 1 if platform has pthread_getconcurrency(). */
#define ACE_HAS_PTHREAD_GETCONCURRENCY 1

/* Define to 1 if platform has pthread_mutexattr_setkind_np(). */
#define ACE_HAS_PTHREAD_MUTEXATTR_SETKIND_NP 1

/* pthread.h declares an enum with PTHREAD_PROCESS_PRIVATE and
   PTHREAD_PROCESS_SHARED values */
#define ACE_HAS_PTHREAD_PROCESS_ENUM 1

/* Define to 1 if platform has pthread_setconcurrency(). */
#define ACE_HAS_PTHREAD_SETCONCURRENCY 1

/* Define to 1 if platform has the declaration of pthread_sigmask(). */
#define ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE 1

/* Platform has pread() and pwrite() support. */
#define ACE_HAS_P_READ_WRITE 1

/* Define to 1 to configure Reactor to use a user-space queue for
   notifications */
#define ACE_HAS_REACTOR_NOTIFICATION_QUEUE 1

/* Mutexes are inherently recursive (e.g., Win32) */
/* #undef ACE_HAS_RECURSIVE_MUTEXES */

/* Platform will recurse infinitely on thread exits from TSS cleanup routines
   (e.g., AIX) */
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS 1

/* Platform supports reentrant functions (i.e., all the POSIX *_r functions).
   */
#define ACE_HAS_REENTRANT_FUNCTIONS 1

/* Define to 1 if platform has sched_getaffinity(). */
#define ACE_HAS_SCHED_GETAFFINITY 1

/* Define to 1 if platform has sched_setaffinity(). */
#define ACE_HAS_SCHED_SETAFFINITY 1

/* Platform has shm_open() */
#define ACE_HAS_SHM_OPEN 1

/* Platform's sigaction() function takes const sigaction* as 2nd parameter */
#define ACE_HAS_SIGACTION_CONSTP2 1

/* Define to 1 if the system has the type `siginfo_t'. */
#define ACE_HAS_SIGINFO_T 1

/* Define to 1 if platform has sigsuspend(). */
#define ACE_HAS_SIGSUSPEND 1

/* Define to 1 if platform has sigtimedwait(). */
#define ACE_HAS_SIGTIMEDWAIT 1

/* Define to 1 if platform has sigwait(). */
#define ACE_HAS_SIGWAIT 1

/* Define to 1 if the system has the type 'sig_atomic_t'. */
#define ACE_HAS_SIG_ATOMIC_T 1

/* Compiler requires extern "C" functions for signals. */
#define ACE_HAS_SIG_C_FUNC 1

/* Define to 1 if platform has snprintf(). */
#define ACE_HAS_SNPRINTF 1

/* Define to 1 if `sin6_len' is a member of `sockaddr_in6'. */
#define ACE_HAS_SOCKADDR_IN6_SIN6_LEN 1

/* Define to 1 if `sin_len' is a member of `sockaddr_in'. */
#define ACE_HAS_SOCKADDR_IN_SIN_LEN 1

/* Platform requires (struct sockaddr *) for msg_name field of struct msghdr.
   */
#define ACE_HAS_SOCKADDR_MSG_NAME 1

/* Define to 1 if the system has the type `socklen_t'. */
#define ACE_HAS_SOCKLEN_T 1

/* Define to 1 if the system has the type `ssize_t'. */
#define ACE_HAS_SSIZE_T 1

/* Platform/compiler supports Standard C++ Library */
#define ACE_HAS_STANDARD_CPP_LIBRARY 1

/* Compiler supports standard C++ template class member specializations */
#define ACE_HAS_STD_TEMPLATE_CLASS_MEMBER_SPECIALIZATION 1

/* Compiler supports standard C++ template specializations (e.g. "template <>"
   syntax.) */
#define ACE_HAS_STD_TEMPLATE_SPECIALIZATION 1

/* Compiler/platform supports struct strbuf */
#define ACE_HAS_STRBUF_T 1

/* Platform supports STREAMS */
#define ACE_HAS_STREAMS 1

/* Define to 1 if platform has strerror(). */
#define ACE_HAS_STRERROR 1

/* Platform has <strings.h> (which contains bzero() prototype) */
#define ACE_HAS_STRINGS 1

/* Platform/Compiler supports a String class (e.g., GNU or Win32). */
#define ACE_HAS_STRING_CLASS 1

/* Define to 1 if platform has strnlen(). */
#define ACE_HAS_STRNLEN 1

/* Compiler/platform supports SVR4 dynamic linking semantics */
#define ACE_HAS_SVR4_DYNAMIC_LINKING 1

/* Define to 1 if platform has sysctl(). */
#define ACE_HAS_SYSCTL 1

/* Platform supports System V IPC (most versions of UNIX, but not Win32) */
#define ACE_HAS_SYSV_IPC 1

/* Platform/compiler supports _sys_errlist symbol */
#define ACE_HAS_SYS_ERRLIST 1

/* Define to 1 if platform has the <sys/filio.h> header file. */
#define ACE_HAS_SYS_FILIO_H 1

/* Compiler/platform supports _sys_siglist array */
#define ACE_HAS_SYS_SIGLIST 1

/* Define to 1 if platform has the <sys/sockio.h> header file. */
#define ACE_HAS_SYS_SOCKIO_H 1

/* Define to 1 if platform has the <sys/syscall.h> header file. */
#define ACE_HAS_SYS_SYSCALL_H 1

/* Define to 1 if system supports POSIX tty API. */
#define ACE_HAS_TERMIOS 1

/* Platform supports threads. */
#define ACE_HAS_THREADS 1

/* Compiler/platform has thread-specific storage */
#define ACE_HAS_THREAD_SPECIFIC_STORAGE 1

/* Define to 1 if platform has global timezone variable */
#define ACE_HAS_TIMEZONE 1

/* Platform/compiler supports timezone * as second parameter to gettimeofday()
   and has a prototype. */
#define ACE_HAS_TIMEZONE_GETTIMEOFDAY 1

/* Compiler supports the C++ typename keyword */
#define ACE_HAS_TYPENAME_KEYWORD 1

/* Define to 1 if platform has ualarm(). */
#define ACE_HAS_UALARM 1

/* Define to 1 if the system has the type `ucontext_t'. */
#define ACE_HAS_UCONTEXT_T 1

/* Define to 1 if the system has the type `uint16_t'. */
#define ACE_HAS_UINT16_T 1

/* Define to 1 if the system has the type `uint32_t'. */
#define ACE_HAS_UINT32_T 1

/* Define to 1 if the system has the type `uint64_t'. */
#define ACE_HAS_UINT64_T 1

/* Define to 1 if the system has the type `uint8_t'. */
#define ACE_HAS_UINT8_T 1

/* Define to 1 if platform has vasprintf(). */
#define ACE_HAS_VASPRINTF 1

/* Define to 1 if platform has vfwprintf(). */
#define ACE_HAS_VFWPRINTF 1

/* Platform requires void * for mmap(). */
#define ACE_HAS_VOIDPTR_MMAP 1

/* OS/compiler uses void * arg 4 setsockopt() rather than const char * */
#define ACE_HAS_VOIDPTR_SOCKOPT 1

/* Define to 1 if platform has vswprintf(). */
#define ACE_HAS_VSWPRINTF 1

/* Platform/compiler supports wchar_t */
#define ACE_HAS_WCHAR 1

/* Define to 1 if platform has wcsnlen(). */
#define ACE_HAS_WCSNLEN 1

/* Platform has support for multi-byte character support compliant with the
   XPG4 Worldwide Portability Interface wide-character classification. */
#define ACE_HAS_XPG4_MULTIBYTE_CHAR 1

/* Platform has Xt Intrinsics Toolkit */
#define ACE_HAS_XT 1

/* Define to signed 64 bit integer type */
#define ACE_INT64_TYPE signed long long

/* Define to the type of arg 2 for `ioctl'. */
#define ACE_IOCTL_TYPE_ARG2 int

/* Define to 1 if platform lacks getipnodebyaddr(). */
#define ACE_LACKS_GETIPNODEBYADDR 1

/* Define to 1 if platform lacks getipnodebyname(). */
#define ACE_LACKS_GETIPNODEBYNAME 1

/* iostream header does not declare ipfx (), opfx (), etc. */
#define ACE_LACKS_IOSTREAM_FX 1

/* Define to 1 if platform lacks itow(). */
#define ACE_LACKS_ITOW 1

/* Platform lacks streambuf "linebuffered ()". */
#define ACE_LACKS_LINEBUFFERED_STREAMBUF 1

/* Platform does not have Motif X toolkit available */
#define ACE_LACKS_MOTIF 1

/* Platform defines ACE_HAS_MSG, but lacks msg_accrights{len}. */
#define ACE_LACKS_MSG_ACCRIGHTS 1

/* Platform lacks named POSIX semaphores (e.g., Chorus) */
#define ACE_LACKS_NAMED_POSIX_SEM 1

/* Compiler complains about use of obsolete "pragma once" */
#define ACE_LACKS_PRAGMA_ONCE 1

/* Define to 1 if the system lacks the type 'pri_t'. */
#define ACE_LACKS_PRI_T 1

/* Define to 1 if platform lacks pthread_thr_sigsetmask(). */
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1

/* Platform lacks readers/writer locks. */
#define ACE_LACKS_RWLOCK_T 1

/* Define to 1 if platform lacks the <siginfo.h> header file. */
#define ACE_LACKS_SIGINFO_H 1

/* Define to 1 if platform lacks the <termio.h> header file. */
#define ACE_LACKS_TERMIO_H 1

/* Define to 1 if platform lacks the declarations of recv_timedwait,
   send_timedwait, etc. */
#define ACE_LACKS_TIMEDWAIT_PROTOTYPES 1

/* Platform does not define timepec_t as a typedef for struct timespec. */
#define ACE_LACKS_TIMESPEC_T 1

/* */
#define ACE_LACKS_UNBUFFERED_STREAMBUF 1

/* Define to 1 if the system lacks the type `u_long_long_t'. */
#define ACE_LACKS_U_LONGLONG_T 1

/* Define to 1 if platform lacks wcsnicmp(). */
#define ACE_LACKS_WCSNICMP 1

/* Compile using multi-thread libraries */
#define ACE_MT_SAFE 1

/* Size of the native "double" type */
#define ACE_SIZEOF_DOUBLE 8

/* Size of the native "float" type */
#define ACE_SIZEOF_FLOAT 4

/* Size of the native "int" type */
#define ACE_SIZEOF_INT 4

/* Size of the native "long" type */
#define ACE_SIZEOF_LONG 4

/* Size of the native "long double" type */
#define ACE_SIZEOF_LONG_DOUBLE 12

/* Size of the native "long long" type */
#define ACE_SIZEOF_LONG_LONG 8

/* Size of the native "short" type */
#define ACE_SIZEOF_SHORT 2

/* Size of the native "pointer to void" type */
#define ACE_SIZEOF_VOID_P 4

/* Size of the native "wchar_t" type */
#define ACE_SIZEOF_WCHAR 4

/* Define to unsigned 64 bit integer type */
#define ACE_UINT64_TYPE unsigned long long

/* Enable IPv6 support on platforms that don't have IPv6 turned on by default
   */
#define ACE_USES_IPV4_IPV6_MIGRATION 1

/* Platform has its standard C++ library in the namespace std. */
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <fstream> header file. */
#define HAVE_FSTREAM 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <iomanip> header file. */
#define HAVE_IOMANIP 1

/* Define to 1 if you have the <ios> header file. */
#define HAVE_IOS 1

/* Define to 1 if you have the <iostream> header file. */
#define HAVE_IOSTREAM 1

/* Define to 1 if you have the <iostream.h> header file. */
/* #undef HAVE_IOSTREAM_H */

/* Define to 1 if you have the <istream> header file. */
#define HAVE_ISTREAM 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <ostream> header file. */
#define HAVE_OSTREAM 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <streambuf> header file. */
#define HAVE_STREAMBUF 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "ace-bugs@cs.wustl.edu"

/* Define to the full name of this package. */
#define PACKAGE_NAME "ACE"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ACE 5.6.3"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "ace"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "5.6.3"

/* The size of `double', as computed by sizeof. */
#define SIZEOF_DOUBLE 8

/* The size of `float', as computed by sizeof. */
#define SIZEOF_FLOAT 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `long double', as computed by sizeof. */
#define SIZEOF_LONG_DOUBLE 12

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `signed char', as computed by sizeof. */
#define SIZEOF_SIGNED_CHAR 1

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 4

/* The size of `wchar_t', as computed by sizeof. */
#define SIZEOF_WCHAR_T 4

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1


/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif


/* Enable ACE inlining */
#define __ACE_INLINE__ 1


#endif  /* ACE_CONFIG_KFREEBSDH */


