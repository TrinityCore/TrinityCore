/* -*- C++ -*- */
// $Id: config-openvms.h 81935 2008-06-12 22:01:53Z jtc $
// The following configuration file is designed to work for OpenVMS 7.3-2
#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#if !defined (ACE_USE_RCSID)
# define ACE_USE_RCSID 0
#endif
#ifdef __cplusplus
#pragma message disable CODCAUUNR
#pragma message disable CODEUNREACHABLE
//#pragma message disable DOLLARID
//#pragma message disable NOSIMPINT
//#pragma message disable NOSTDLONGLONG
#pragma message disable NARROWPTR
//#pragma message disable LONGEXTERN
#pragma message disable UNSCOMZER
#endif
// Use a signed int to match POSIX
#define __SIGNED_INT_TIME_T
#define ACE_OPENVMS __VMS_VER
#define ACE_DLL_SUFFIX ACE_TEXT("")
#define ACE_HAS_DUMP    1
// need this includes to ensure proper sequence of definitions so that
// f.i. HP C/C++ does not '#define ' memcpy, memmove etc.
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#undef clearerr
#undef memset
#undef memcpy
#undef memmove
#if defined(__ia64__)
  // on OpenVMS IA64 we need this get the singleton exported since we build
  // ACE/TAO with the NOTEMPLATES export option which prohibits exporting
  // of any template symbols unless explicitly exported
  #define ACE_HAS_CUSTOM_EXPORT_MACROS
  #define ACE_Proper_Export_Flag
  #define ACE_Proper_Import_Flag
  #define ACE_EXPORT_SINGLETON_DECLARATION(T) template class __declspec (dllexport) T
  #define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
#else
  #define ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION
#endif
#define ACE_DEFAULT_BASE_ADDR ((char*)(0x30000000))
#define ACE_MAX_UDP_PACKET_SIZE 65535
#define ACE_HAS_STDCPP_STL_INCLUDES 1
/* missing system headers */
#define ACE_LACKS_STDINT_H  1
#define ACE_LACKS_SYS_IPC_H 1
#define ACE_LACKS_SYS_SEM_H 1
#define ACE_LACKS_SEMAPHORE_H 1
#define ACE_LACKS_SYS_SELECT_H 1
#define ACE_LACKS_TERMIOS_H 1
#define ACE_LACKS_SYS_SHM_H 1
#define ACE_LACKS_SYS_MSG_H 1
#define ACE_LACKS_REGEX_H 1
#define ACE_LACKS_SEARCH_H 1
#define ACE_LACKS_SCHED_H 1
#define ACE_LACKS_SYS_SYSCTL_H 1
#define ACE_LACKS_MALLOC_H 1
#define ACE_LACKS_SYS_PARAM_H 1
#define ACE_LACKS_SIGINFO_H 1
#define ACE_LACKS_UCONTEXT_H 1
/* missing rtl functions */
#define ACE_LACKS_SETPGID 1
#define ACE_LACKS_SETREUID 1
#define ACE_LACKS_SETREGID 1
#define ACE_LACKS_FORK 1
#define ACE_LACKS_GETPGID 1
#define ACE_LACKS_SETSID 1
#define ACE_LACKS_FCNTL 1
#define ACE_LACKS_SETEGID 1
#define ACE_LACKS_SETEUID 1
#define ACE_LACKS_REALPATH 1
#define ACE_LACKS_SYMLINKS 1
#define ACE_LACKS_PWD_REENTRANT_FUNCTIONS 1
#define ACE_LACKS_RAND_REENTRANT_FUNCTIONS 1
#define ACE_HAS_P_READ_WRITE
#define ACE_HAS_CHARPTR_DL 1
#define ACE_HAS_CLOCK_GETTIME 1
#define ACE_HAS_CLOCK_SETTIME 1
#define ACE_HAS_VOIDPTR_GETTIMEOFDAY 1
#define ACE_HAS_DIRENT 1
#define ACE_HAS_GETPAGESIZE 1
#define ACE_HAS_MSG
#define ACE_HAS_NONCONST_SELECT_TIMEVAL 1
#define ACE_HAS_2_PARAM_ASCTIME_R_AND_CTIME_R 1
#define ACE_HAS_3_PARAM_WCSTOK 1
#define ACE_HAS_SIGSUSPEND 1
#define ACE_HAS_SIG_MACROS 1
#define ACE_HAS_SIGWAIT 1
#define ACE_HAS_SIGTIMEDWAIT 1
#define ACE_HAS_SIG_C_FUNC 1
#define ACE_HAS_SIGISMEMBER_BUG
#define ACE_HAS_STRNLEN 1
#define ACE_HAS_STREAMS 1
#define ACE_HAS_STRERROR 1
#define ACE_HAS_UALARM 1
#define ACE_HAS_VOIDPTR_MMAP 1
#define ACE_HAS_VOIDPTR_SOCKOPT 1
#define ACE_LACKS_LSTAT 1
#define ACE_LACKS_MADVISE 1
#define ACE_LACKS_MKFIFO 1
#define ACE_LACKS_NETDB_REENTRANT_FUNCTIONS 1
#define ACE_LACKS_READLINK 1
#define ACE_LACKS_RLIMIT 1
#define ACE_LACKS_RLIMIT_PROTOTYPE 1
#define ACE_LACKS_SETSCHED
#define ACE_LACKS_SYSCALL 1
#define ACE_LACKS_WCSTOULL 1
/* (missing) standard data types */
#define ACE_LACKS_CONST_TIMESPEC_PTR 1
#define ACE_LACKS_SUSECONDS_T 1
#define ACE_HAS_IDTYPE_T 1
#define ACE_HAS_SIGINFO_T 1
#define ACE_HAS_XPG4_MULTIBYTE_CHAR 1
#define ACE_HAS_SIZET_SOCKET_LEN 1
#define ACE_HAS_SSIZE_T 1
#define ACE_LACKS_PRI_T 1
#define ACE_LACKS_SEMBUF_T 1
#define ACE_LACKS_STRRECVFD 1
#define ACE_LACKS_T_ERRNO 1
/* POSIX threads ompatibilities */
#define ACE_LACKS_RWLOCK_T 1
#define ACE_LACKS_PTHREAD_KILL 1
#define ACE_LACKS_THREAD_PROCESS_SCOPING 1
#define ACE_HAS_PTHREADS 1
#define ACE_HAS_PTHREAD_PROCESS_ENUM 1
#define ACE_LACKS_UNNAMED_SEMAPHORE 1
#define ACE_MT_SAFE 1
#define ACE_HAS_THREADS 1
#define ACE_HAS_THREAD_SPECIFIC_STORAGE 1
#define ACE_HAS_THR_C_DEST 1
#define ACE_HAS_THR_C_FUNC 1
#define ACE_LACKS_PTHREAD_SIGMASK 1
#define ACE_LACKS_PTHREAD_THR_SIGSETMASK 1
#define ACE_NEEDS_HUGE_THREAD_STACKSIZE (64U*1024)
#define ACE_HAS_PTHREAD_SETCONCURRENCY 1
#define ACE_HAS_PTHREAD_GETCONCURRENCY 1
#define ACE_HAS_PTHREAD_SCHEDPARAM 1
/* language/platform conformance */
#define ACE_NEW_THROWS_EXCEPTIONS 1
#define ACE_TEMPLATES_REQUIRE_SOURCE 1
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#define ACE_HAS_AUTOMATIC_INIT_FINI 1
#define ACE_LACKS_UNIX_SIGNALS 1
#define ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES 1
#define ACE_HAS_CPLUSPLUS_HEADERS 1
#define ACE_HAS_EXCEPTIONS 1
#define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
#define ACE_HAS_GPERF 1
#define ACE_HAS_IP_MULTICAST 1
#define ACE_LACKS_PERFECT_MULTICAST_FILTERING 1
#define ACE_HAS_POSIX_NONBLOCK 1
#define ACE_HAS_POSIX_TIME 1
#define ACE_HAS_BROKEN_POSIX_TIME 1
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#define ACE_HAS_STRING_CLASS 1
#define ACE_HAS_SVR4_DYNAMIC_LINKING 1
#define ACE_HAS_TEMPLATE_TYPEDEFS 1
#define ACE_LACKS_NAMED_POSIX_SEM 1
#define ACE_LACKS_SYSV_SHMEM 1
#define ACE_LACKS_UNIX_DOMAIN_SOCKETS 1
#define ACE_LACKS_UNIX_SYSLOG 1
#define ACE_LACKS_ALPHASORT 1
#endif

