/* -*- C++ -*- */
#ifndef ACE_CONFIG_UNIXWARE_UDK_H
#define ACE_CONFIG_UNIXWARE_UDK_H

// $Id: config-unixware-7.1.0.udk.h 82267 2008-07-08 16:39:19Z jtc $

// Configuration for the unixware UDK compiler. derived from the unixware/g++ config
// which was itself derived from an autoconfig run.

/* ACE configuration header file */

#define ACE_TEMPLATES_REQUIRE_SOURCE

#ifndef UNIXWARE_7_1
#define UNIXWARE_7_1
#endif

#define ACE_LACKS_PLACEMENT_OPERATOR_DELETE

/* Define if you have the strftime function.  */
#define HAVE_STRFTIME 1

/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H 1

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if lex declares yytext as a char * by default, not a char[].  */
#define YYTEXT_POINTER 1

/* Define _REENTRANT if reentrant functions should be used. */
#ifndef _REENTRANT
# define _REENTRANT 1
#endif

#define ACE_HAS_NEW_NO_H 1
#define ACE_HAS_STDEXCEPT_NO_H 1

/*
 * TODO: These two next #defines have an #undef before them, in
 * case the variable being defined already had a value.
 * The #undefs are being picked up by configure, and are commented out!
 */
#define ACE_THREAD_MIN_PRIORITY 0
#if defined (ACE_THREAD_MIN_PRIORITY)
/* # undef PTHREAD_MIN_PRIORITY */
# define PTHREAD_MIN_PRIORITY ACE_THREAD_MIN_PRIORITY
#endif  /* #if defined (ACE_THREAD_MIN_PRIORITY) */

#define ACE_THREAD_MAX_PRIORITY 99
#if defined (ACE_THREAD_MAX_PRIORITY)
/* # undef PTHREAD_MAX_PRIORITY */
# define PTHREAD_MAX_PRIORITY ACE_THREAD_MAX_PRIORITY
#endif  /* #if defined (ACE_THREAD_MAX_PRIORITY) */

/* UnixWare specific configuration parameters */
/* #undef UNIXWARE */
/* #undef UNIXWARE_2_0 */
/* #undef UNIXWARE_2_1 */

/* Specify sizes of given built-in types.  If a size isn't defined here,
   then ace/Basic_Types.h will attempt to deduce the size. */
/* #undef ACE_SIZEOF_CHAR */
#define ACE_SIZEOF_SHORT 2
#define ACE_SIZEOF_INT 4
#define ACE_SIZEOF_LONG 4
#define ACE_SIZEOF_LONG_LONG 8
#define ACE_SIZEOF_VOID_P 4
#define ACE_SIZEOF_FLOAT 4
#define ACE_SIZEOF_DOUBLE 8
#define ACE_SIZEOF_LONG_DOUBLE 12

/* Enable ACE inlining */
#define __ACE_INLINE__ 1

/* Platform supports Asynchronous IO calls */
/* #define ACE_HAS_AIO_CALLS */

/* Specify this if you don't want threads to inherit parent thread's
   ACE_Log_Msg properties. */
/* #undef ACE_THREADS_DONT_INHERIT_LOG_MSG */

/* OS has priocntl (2) */
#define ACE_HAS_PRIOCNTL 1

/* Platform has pread() and pwrite() support */
#define ACE_HAS_P_READ_WRITE 1

/* Compiler/platform correctly calls init()/fini() for shared libraries */
#define ACE_HAS_AUTOMATIC_INIT_FINI 1

/* Compiler handles explicit calling of template destructor correctly.
   See "ace/OS.h" for details. */
/* Staller: already defined by config-g++-common.h
#define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR 1
*/

/* Platform doesn't cast MAP_FAILED to a (void *). */
/* #undef ACE_HAS_BROKEN_MAP_FAILED */
/* Staller: oh yes, let's do this! */
#define ACE_HAS_BROKEN_MAP_FAILED

/* Prototypes for both signal() and struct sigaction are consistent. */
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES 1

/* Compiler/platform has correctly prototyped header files */
#define ACE_HAS_CPLUSPLUS_HEADERS

/* Platform supports operations on directories via struct dirent,
   readdir_r, etc. */
#define ACE_HAS_DIRENT

/* Compiler supports C++ exception handling */
# if !defined (ACE_HAS_EXCEPTIONS)
#define ACE_HAS_EXCEPTIONS
# endif

/* Platform supports getpagesize() call (otherwise, ACE_PAGE_SIZE must be
   defined, except on Win32) */
#define ACE_HAS_GETPAGESIZE

/* Platform supports the getrusage() system call. */
#define ACE_HAS_GETRUSAGE

/* Platform has a getrusage () prototype in sys/resource.h that differs from
   the one in ace/OS.i. */
#define ACE_HAS_GETRUSAGE_PROTOTYPE

/* The GPERF utility is compiled for this platform */
#define ACE_HAS_GPERF

/* Optimize ACE_Handle_Set::count_bits for select() operations (common case) */
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT 1

/* Compiler/platform supports SunOS high resolution timers */
/* #undef ACE_HAS_HI_RES_TIMER */

/* Compiler/platform supports idtype_t. */
#define ACE_HAS_IDTYPE_T

/* Inline all the static class OS methods to remove call overhead */
/* Note: This gets defined by OS.h if __ACE_INLINE__ is defined */
/* #undef ACE_HAS_INLINED_OSCALLS */

/* Platform supports IP multicast */
#define ACE_HAS_IP_MULTICAST

/* Platform supports thr_keydelete (e.g,. UNIXWARE) */
#define ACE_HAS_THR_KEYDELETE

/* Platform calls thr_minstack() rather than thr_min_stack() (e.g., Tandem). */
#define ACE_HAS_THR_MINSTACK

/* Some files, such as ace/streams.h, want to include new style C++ stream
   headers.  These headers are iomanip, ios, iostream, istream, ostream,
   fstream and streambuf.  If _all_ of these headers aren't available, then
   assume that only iostream.h and fstream.h are available. */
/* #define ACE_USES_OLD_IOSTREAMS */

/* Platform supports recvmsg and sendmsg */
#define ACE_HAS_MSG

/* Platform's select() uses non-const timeval* (only found on Linux right
   now) */
#define ACE_HAS_NONCONST_SELECT_TIMEVAL

/* Uses ctime_r & asctime_r with only two parameters vs. three. */
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R

/* Platform is an Intel Pentium microprocessor. */
/* There is a problem with the gethrtime() because of (apparently) a problem
   with the inline assembly instruction.  Hopefully there is a way to resolve
   that with an improvement to the assembler
*/
#ifdef ACE_HAS_PENTIUM
//#undef ACE_HAS_PENTIUM
#endif /* ACE_HAS_PENTIUM */

/* Platform contains <poll.h> */
#define ACE_HAS_POLL

/* Platform supports POSIX O_NONBLOCK semantics */
#define ACE_HAS_POSIX_NONBLOCK

/* Platform supports the POSIX struct timespec type */
#define ACE_HAS_POSIX_TIME

/* Platform supports the /proc file system and defines tid_t
   in <sys/procfs.h> */
#define ACE_HAS_PROC_FS

/* Platform supports POSIX Threads */
#define ACE_HAS_PTHREADS

/* pthread.h declares an enum with PTHREAD_PROCESS_PRIVATE and
   PTHREAD_PROCESS_SHARED values */
#define ACE_HAS_PTHREAD_PROCESS_ENUM

/* Platform will recurse infinitely on thread exits from TSS cleanup routines
   (e.g., AIX) */
#define ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS

/* Platform supports reentrant functions (i.e., all the POSIX *_r
   functions). */
#define ACE_HAS_REENTRANT_FUNCTIONS

/* Platform has support for multi-byte character support compliant with the
   XPG4 Worldwide Portability Interface wide-character classification. */
#define ACE_HAS_XPG4_MULTIBYTE_CHAR

/* Platform does not support reentrant netdb functions (getprotobyname_r,
   getprotobynumber_r, gethostbyaddr_r, gethostbyname_r, getservbyname_r). */
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS

/* Platform supports the POSIX regular expression library */
#define ACE_HAS_REGEX

/* Platform has special header for select(). */
#define ACE_HAS_SELECT_H

/* Platform has a function to set t_errno (e.g., Tandem). */
#define ACE_HAS_SET_T_ERRNO

/* Platform supports SVR4 extended signals */
#define ACE_HAS_SIGINFO_T

/* Platform/compiler has the sigwait(2) prototype */
#define ACE_HAS_SIGWAIT

/* Compiler/platform defines the sig_atomic_t typedef */
#define ACE_HAS_SIG_ATOMIC_T

/* Platform supports new BSD inet_addr len field. */
#define ACE_HAS_SOCKADDR_IN_SIN_LEN

/* OS/compiler uses size_t * rather than int * for socket lengths */
#define ACE_HAS_SIZET_SOCKET_LEN

/* Compiler/platform provides the sys/sockio.h file */
#define ACE_HAS_SYS_SOCKIO_H

/* Compiler supports the ssize_t typedef */
#define ACE_HAS_SSIZE_T

/* Platform supports UNIX International Threads */
#define ACE_HAS_STHREADS

/* Platform has thr_yield() */
#define ACE_HAS_THR_YIELD

/* Platform/compiler supports Standard C++ Library */
/* It seems that UDK provides std-like declarations for only portions
   such as <exception>
*/
#define ACE_HAS_STANDARD_CPP_LIBRARY 0

/* Compiler/platform supports struct strbuf */
#define ACE_HAS_STRBUF_T

/* Platform supports STREAMS */
#define ACE_HAS_STREAMS

/* Platform supports STREAM pipes */
#define ACE_HAS_STREAM_PIPES

/* Compiler/platform supports strerror () */
#define ACE_HAS_STRERROR

/* Platform/Compiler supports a String class (e.g., GNU or Win32). */
#define ACE_HAS_STRING_CLASS

/* Platform has <strings.h> (which contains bzero() prototype) */
#define ACE_HAS_STRINGS

/* Platform/compiler supports void * as second parameter to gettimeofday(). */
#define ACE_HAS_VOIDPTR_GETTIMEOFDAY

/* Compiler/platform supports SVR4 dynamic linking semantics */
#define ACE_HAS_SVR4_DYNAMIC_LINKING

/* Compiler/platform supports SVR4 TLI (in particular, T_GETNAME stuff)... */
#define ACE_HAS_SVR4_TLI

/* Compiler/platform contains the <sys/syscall.h> file. */
#define ACE_HAS_SYS_SYSCALL_H

/* Platform supports system configuration information */
#define ACE_HAS_SYS_SYSTEMINFO_H
#define ACE_HAS_SYSINFO 1

/* Platform supports System V IPC (most versions of UNIX, but not Win32) */
#define ACE_HAS_SYSV_IPC 1

/* Platform provides <sys/filio.h> header */
#define ACE_HAS_SYS_FILIO_H 1

/* Platform provides <sys/xti.h> header */
#define ACE_HAS_SYS_XTI_H 1

/* Compiler implements templates that support typedefs inside of classes used
   as formal arguments to a template class. */
#define ACE_HAS_TEMPLATE_TYPEDEFS 1

/* Platform has POSIX terminal interface. */
#define ACE_HAS_TERMIOS 1

/* Platform supports threads */
#define ACE_HAS_THREADS 1

/* Compiler/platform has thread-specific storage */
#define ACE_HAS_THREAD_SPECIFIC_STORAGE 1

/* Platform supports TLI timod STREAMS module */
#define ACE_HAS_TIMOD_H 1

/* Platform supports TLI tiuser header */
#define ACE_HAS_TIUSER_H 1

/* Platform supports TLI.  Also see ACE_TLI_TCP_DEVICE. */
#define ACE_HAS_TLI 1

/* Platform provides TLI function prototypes */
#define ACE_HAS_TLI_PROTOTYPES 1

/* Platform supports ualarm() */
#define ACE_HAS_UALARM 1

/* Platform supports ucontext_t (which is used in the extended signal API). */
#define ACE_HAS_UCONTEXT_T 1

/* Platform has <utime.h> header file */
#define ACE_HAS_UTIME 1

/* Prints out console message in ACE_NOTSUP.  Useful for tracking down origin
   of ACE_NOTSUP. */
/* #undef ACE_HAS_VERBOSE_NOTSUP */

/* Platform requires void * for mmap(). */
#define ACE_HAS_VOIDPTR_MMAP 1

/* Platform has XTI (X/Open-standardized superset of TLI).  Implies
   ACE_HAS_TLI but uses a different header file. */
#define ACE_HAS_XTI 1

/* Platform can not build ace/IOStream{,_T}.cpp.  This does not necessarily
   mean that the platform does not support iostreams. */
#define ACE_LACKS_ACE_IOSTREAM 1

/* Platform does not have u_longlong_t typedef */
#define ACE_LACKS_U_LONGLONG_T 1

/* Platform lacks madvise() (e.g., Linux) */
#define ACE_LACKS_MADVISE 1

/* Platform lacks pri_t (e.g., Tandem NonStop UNIX). */
#define ACE_LACKS_PRI_T 1

/* Platform lacks pthread_thr_sigsetmask (e.g., MVS, HP/UX, and OSF/1 3.2) */
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1

/* Platfrom lack pthread_yield() support. */
#define ACE_LACKS_PTHREAD_YIELD 1

/* Platform lacks readers/writer locks. */
#define ACE_LACKS_RWLOCK_T 1

/* MIT pthreads platform lacks the timedwait prototypes */
#define ACE_LACKS_TIMEDWAIT_PROTOTYPES 1

/* Platform does not define timepec_t as a typedef for struct timespec. */
#define ACE_LACKS_TIMESPEC_T 1

/* Compile using multi-thread libraries */
#define ACE_MT_SAFE 1

/* Platform needs to #include <sched.h> to get thread scheduling defs. */
#define ACE_NEEDS_SCHED_H 1

/* The OS/platform supports the poll() event demultiplexor */
#define ACE_USE_POLL 1

/* Platform has its standard c++ library in the namespace std. */
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1

/* The number of bytes in a double.  */
#define SIZEOF_DOUBLE 8

/* The number of bytes in a float.  */
#define SIZEOF_FLOAT 4

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long double.  */
#define SIZEOF_LONG_DOUBLE 12

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a signed char.  */
#define SIZEOF_SIGNED_CHAR 1

/* The number of bytes in a void *.  */
#define SIZEOF_VOID_P 4

/* Define if you have the execv function.  */
#define HAVE_EXECV 1

/* Define if you have the execve function.  */
#define HAVE_EXECVE 1

/* Define if you have the execvp function.  */
#define HAVE_EXECVP 1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H 1

/* Define if you have the <fstream> header file.  */
#define HAVE_FSTREAM 1

/* Define if you have the <iomanip> header file.  */
#define HAVE_IOMANIP 1

/* Define if you have the <iostream> header file.  */
#define HAVE_IOSTREAM 1

/* Define if you have the <pwd.h> header file.  */
#define HAVE_PWD_H 1

/* Name of package */
#define PACKAGE "ace"

/* Version number of package */
#define VERSION "4.6.37"

/* Added by Staller */
#define ENUM_BOOLEAN // See file /usr/local/lib/gcc-lib/i486-pc-sysv5/egcs-2.91.60/include/sys/types.h
/* Hat nix gebracht
#define ACE_DEFAULT_SELECT_REACTOR_SIZE 256 // this is like in linux config fileto avoid another error
*/
#define howmany(x, y)   (((x)+((y)-1))/(y))
#define ACE_HAS_BROKEN_T_ERROR // let disappear a nasty warning from OS.i
#if !defined (__USLC__)
#  define __USLC__ 1
#endif

#define  __IOCTL_VERSIONED__ // By Carlo!
#endif /* ACE_UNIXWARE_UDK_H */

