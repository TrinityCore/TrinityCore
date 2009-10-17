/* -*- C++ -*- */
// $Id: config-win32-common.h 82316 2008-07-15 01:28:39Z johnnyw $


#ifndef ACE_CONFIG_WIN32_COMMON_H
#define ACE_CONFIG_WIN32_COMMON_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */


// Windows Mobile (CE) stuff is primarily further restrictions to what's
// in the rest of this file. Also, it defined ACE_HAS_WINCE, which is used
// in this file.
#if defined (_WIN32_WCE)
#  include "ace/config-WinCE.h"
#endif /* _WIN32_WCE */

// Complain if WIN32 is not already defined.
#if !defined (WIN32) && !defined (ACE_HAS_WINCE)
# error Please define WIN32 in your project settings.
#endif

#define ACE_WIN32
#if defined (_WIN64) || defined (WIN64)
#  define ACE_WIN64

// Use 64-bit file offsets by default in the WIN64 case, similar to
// what 64-bit UNIX systems do.
//
// Note that _FILE_OFFSET_BITS is not recognized by Windows.  It is,
// however, recognized by ACE.
#  ifndef _FILE_OFFSET_BITS
#    define _FILE_OFFSET_BITS 64
#  endif  /* !_FILE_OFFSET_BITS */
#endif /* _WIN64 || WIN64 */

#if !defined (_WIN32_WINNT)
# define _WIN32_WINNT 0x0501 // pretend it's at least Windows XP or Win2003
#endif

// If the invoking procedure turned off debugging by setting NDEBUG, then
// also set ACE_NDEBUG, unless the user has already set it.
#if defined (NDEBUG)
#  if !defined (ACE_NDEBUG)
#    define ACE_NDEBUG
#  endif /* ACE_NDEBUG */
#endif /* NDEBUG */

// Define ACE_HAS_MFC to 1, if you want ACE to use CWinThread. This should
// be defined, if your application uses MFC.
//  Setting applies to  : building ACE
//  Runtime restrictions: MFC DLLs must be installed
//  Additonal notes             : If both ACE_HAS_MFC and ACE_MT_SAFE are
//                        defined, the MFC DLL (not the static lib)
//                        will be used from ACE.
#if !defined (ACE_HAS_MFC)
# define ACE_HAS_MFC 0
#endif

// ACE_USES_STATIC_MFC always implies ACE_HAS_MFC
#if defined (ACE_USES_STATIC_MFC)
# if defined (ACE_HAS_MFC)
#   undef ACE_HAS_MFC
# endif
# define ACE_HAS_MFC 1
#endif /* ACE_USES_STATIC_MFC */

// Define ACE_HAS_STRICT to 1 in your config.h file if you want to use
// STRICT type checking.  It is disabled by default because it will
// break existing application code. However, if ACE_HAS_MFC is turned on,
// ACE_HAS_STRICT is required by MFC.
//  Setting applies to  : building ACE, linking with ACE
//  Runtime restrictions: -
#if !defined (ACE_HAS_STRICT)
# define ACE_HAS_STRICT 0
#endif

// MFC itself defines STRICT.
#if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
# undef ACE_HAS_STRICT
# define ACE_HAS_STRICT 1
#endif

// Turn off the following define if you want to disable threading.
// Compile using multi-thread libraries.
//  Setting applies to  : building ACE, linking with ACE
//  Runtime restrictions: multithreaded runtime DLL must be installed
#if !defined (ACE_MT_SAFE)
# define ACE_MT_SAFE 1
#endif

// Build ACE services as DLLs.  If you write a library and want it to
// use ACE_Svc_Export, this will cause those macros to build dlls.  If
// you want your ACE service to be a static library, comment out this
// line.  As far as I know, the only reason to have a library be an
// ACE "service" is to leverage the ACE_Svc_Export macros.  It's just
// as easy to define your own export macros.
//  #if !defined (ACE_SVC_HAS_DLL)
//  # define ACE_SVC_HAS_DLL 1
//  #endif

// Define the special export macros needed to export symbols outside a dll
#if !defined(__BORLANDC__)
#define ACE_HAS_CUSTOM_EXPORT_MACROS 1
#define ACE_Proper_Export_Flag __declspec (dllexport)
#define ACE_Proper_Import_Flag __declspec (dllimport)
#define ACE_EXPORT_SINGLETON_DECLARATION(T) template class __declspec (dllexport) T
#define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
#define ACE_IMPORT_SINGLETON_DECLARATION(T) extern template class T
#define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) extern template class SINGLETON_TYPE <CLASS, LOCK>;
#endif /* !__BORLANDC__ */

// Define ACE_HAS_WINSOCK2 to 0 in your config.h file if you do *not*
// want to compile with WinSock 2.0.
//  Setting applies to  : building ACE
//  Runtime restrictions: winsock2 must be installed.
//      #define ACE_HAS_WINSOCK2 0

// By default, we use non-static object manager on Win32.  That is,
// the object manager is allocated in main's stack memory.  If this
// does not suit your need, i.e., if your programs depend on the use
// of static object manager, you neet to disable the behavior by adding
//
//   #undef ACE_HAS_NONSTATIC_OBJECT_MANAGER
//
// in the config.h after including config-win32.h
//
// MFC users: the main function is defined within a MFC library and
// therefore, ACE won't be able to meddle with main function and
// instantiate the non-static object manager for you.  To solve the
// problem, you'll need to instantiate the ACE_Object_Manager by
// either:
//
// 1. Using static object manager (as described above), however, using
// the non-static object manager is prefered, therefore,
// 2. Instantiate the non-static object manager yourself by either 1)
//    call ACE::init () at the beginning and ACE::fini () at the end,
//    _or_ 2) instantiate the ACE_Object_Manager in your CWinApp
//    derived class.
//
// Optionally, you can #define
// ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER in your
// ace/config.h and always take care of the business by yourself.
// ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER has no effect when
// using static object managers.
#if !defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER)
# define ACE_HAS_NONSTATIC_OBJECT_MANAGER
#elif (ACE_HAS_NONSTATIC_OBJECT_MANAGER == 0)
# undef ACE_HAS_NONSTATIC_OBJECT_MANAGER
#endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER */

#define ACE_HAS_GPERF

// By default, don't include RCS Id strings in object code.
#if !defined (ACE_USE_RCSID)
# define ACE_USE_RCSID 0
#endif /* ! ACE_USE_RCSID */

// ---------------- platform features or lack of them -------------

// By default WIN32 has FD_SETSIZE of 64, which places the limit
// between 61 and 64 on the number of clients a server using the
// Select Reactor can support at the same time (i.e., 64 - standard in,
// out, error).  Here we raise the limit to 1024.  Adjust the definition
// below if you need to raise or lower it.

#if !defined (FD_SETSIZE)
#define FD_SETSIZE 1024
#endif /* FD_SETSIZE */


// Windows doesn't like 65536 ;-) If 65536 is specified, it is
// silently ignored by the OS, i.e., setsockopt does not fail, and you
// get stuck with the default size of 8k.
#define ACE_DEFAULT_MAX_SOCKET_BUFSIZ 65535

// It seems like Win32 does not have a limit on the number of buffers
// that can be transferred by the scatter/gather type of I/O
// functions, e.g., WSASend and WSARecv.  We are setting this to be 64
// for now.  The typically use case is to create an I/O vector array
// of size ACE_IOV_MAX on the stack and then filled in.  Note that we
// probably don't want too big a value for ACE_IOV_MAX since it may
// mostly go to waste or the size of the activation record may become
// excessively large.
#if !defined (ACE_IOV_MAX)
# define ACE_IOV_MAX 64
#endif /* ACE_IOV_MAX */

#if !defined (ACE_HAS_WINCE)
// Platform supports pread() and pwrite()
# define ACE_HAS_P_READ_WRITE
#endif /* ! ACE_HAS_WINCE */

#if !defined (__MINGW32__)
# define ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS
#endif /* __MINGW32__ */

#define ACE_DEFAULT_THREAD_PRIORITY 0

#define ACE_HAS_DIRENT
#define ACE_HAS_MSG
#define ACE_HAS_RECURSIVE_MUTEXES
#define ACE_HAS_SOCKADDR_MSG_NAME
#define ACE_HAS_THREAD_SAFE_ACCEPT

/* LACKS dir-related facilities */
#define ACE_LACKS_READDIR_R
#define ACE_LACKS_REWINDDIR
#define ACE_LACKS_SEEKDIR
#define ACE_LACKS_TELLDIR

/* LACKS gid/pid/sid/uid facilities */
#define ACE_LACKS_GETPGID
#define ACE_LACKS_GETPPID
#define ACE_LACKS_SETPGID
#define ACE_LACKS_SETREGID
#define ACE_LACKS_SETREUID
#define ACE_LACKS_SETSID
#define ACE_LACKS_SETEGID
#define ACE_LACKS_SETUID
#define ACE_LACKS_SETEUID
#define ACE_LACKS_GETGID
#define ACE_LACKS_GETEGID
#define ACE_LACKS_GETUID
#define ACE_LACKS_GETEUID
#define ACE_LACKS_SETGID

/* LACKS miscellaneous */
#define ACE_LACKS_ALARM
#define ACE_LACKS_ARPA_INET_H
#define ACE_LACKS_DUP2
#define ACE_LACKS_FORK
#define ACE_LACKS_GETHOSTENT
#define ACE_LACKS_GETOPT
#define ACE_LACKS_GETIPNODEBYNAME_IPV6
#define ACE_LACKS_KILL
#define ACE_LACKS_INET_ATON
#define ACE_LACKS_MADVISE
#define ACE_LACKS_MKFIFO
#define ACE_LACKS_MODE_MASKS
#define ACE_LACKS_PTHREAD_H
#define ACE_LACKS_PWD_FUNCTIONS
#define ACE_LACKS_READLINK
#define ACE_LACKS_RLIMIT
#define ACE_LACKS_SBRK
#define ACE_LACKS_SCHED_H
#define ACE_LACKS_SEMBUF_T
#define ACE_LACKS_SIGACTION
#define ACE_LACKS_SIGSET
#define ACE_LACKS_SOCKETPAIR
#define ACE_LACKS_SUSECONDS_T
#define ACE_LACKS_USECONDS_T
#define ACE_LACKS_SYS_PARAM_H
#define ACE_LACKS_SYS_SYSCTL_H
#define ACE_LACKS_SYSCONF
#define ACE_LACKS_SYSV_SHMEM
#define ACE_LACKS_UNISTD_H
#define ACE_LACKS_UNIX_SIGNALS
#define ACE_LACKS_UNIX_SYSLOG
#define ACE_LACKS_UTSNAME_T
#define ACE_LACKS_UNAME
#define ACE_LACKS_WAIT
#define ACE_LACKS_IOVEC
#define ACE_LACKS_LOG2

#define ACE_HAS_PDH_H
#define ACE_HAS_PDHMSG_H

#define ACE_HAS_VFWPRINTF

#define ACE_MKDIR_LACKS_MODE

#define ACE_SIZEOF_LONG_LONG 8
// Green Hills Native x86 does not support __int64 keyword
// Neither does mingw32.
#if !defined (ACE_LACKS_LONGLONG_T) && !defined (__MINGW32__)
#define ACE_INT64_TYPE  signed __int64
#define ACE_UINT64_TYPE unsigned __int64
#endif /* (ghs) */

#if defined (__MINGW32__)
#define ACE_INT64_TYPE  signed long long
#define ACE_UINT64_TYPE unsigned long long
#endif

// Optimize ACE_Handle_Set for select().
#define ACE_HAS_HANDLE_SET_OPTIMIZED_FOR_SELECT

// Win32 has wide-char support. Use of the compiler-defined wchar_t type
// is controlled in compiler configs since it's a compiler switch.
#define ACE_HAS_WCHAR

// Compiler/platform correctly calls init()/fini() for shared
// libraries. - applied for DLLs ?
//define ACE_HAS_AUTOMATIC_INIT_FINI

// Platform supports POSIX O_NONBLOCK semantics.
//define ACE_HAS_POSIX_NONBLOCK

// Platform contains <poll.h>.
//define ACE_HAS_POLL

// Platform supports the /proc file system.
//define ACE_HAS_PROC_FS

// Platform supports the rusage struct.
#define ACE_HAS_GETRUSAGE

// Compiler/platform supports SVR4 signal typedef.
//define ACE_HAS_SVR4_SIGNAL_T

// Platform provides <sys/filio.h> header.
//define ACE_HAS_SYS_FILIO_H

// Compiler/platform supports sys_siglist array.
//define ACE_HAS_SYS_SIGLIST

// Platform supports ACE_TLI timod STREAMS module.
//define ACE_HAS_TIMOD_H

// Platform supports ACE_TLI tiuser header.
//define ACE_HAS_TIUSER_H

// Platform provides ACE_TLI function prototypes.
// For Win32, this is not really true, but saves a lot of hassle!
#define ACE_HAS_TLI_PROTOTYPES

// Platform supports ACE_TLI.
//define ACE_HAS_TLI

// I'm pretty sure NT lacks these
#define ACE_LACKS_UNIX_DOMAIN_SOCKETS

// Windows NT needs readv() and writev()
#define ACE_LACKS_WRITEV
#define ACE_LACKS_READV

#define ACE_LACKS_COND_T
#define ACE_LACKS_RWLOCK_T

#define ACE_LACKS_KEY_T

// No system support for replacing any previous mappings.
#define ACE_LACKS_AUTO_MMAP_REPLACEMENT

// ACE_HAS_PENTIUM is used to optimize some CDR operations; it's used for
// some other time-related things using g++, but not for VC. Current VC
// compilers set _M_IX86 > 400 by default so if you're not using a Pentium
// class CPU, set the project code generation options appropriately.
#if !defined(ACE_HAS_PENTIUM) && (_M_IX86 > 400)
# define ACE_HAS_PENTIUM
#endif

#if defined(ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
// Platform supports threads.
# define ACE_HAS_THREADS

// Platform supports Windows32 threads.
# define ACE_HAS_WTHREADS

// Compiler/platform has thread-specific storage
# define ACE_HAS_THREAD_SPECIFIC_STORAGE

// Win32 doesn't have fcntl
#define ACE_LACKS_FCNTL

#endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */

#if !defined(_DEBUG)
// If we are making a release, and the user has not specified
// inline directives, we will default to inline
# if ! defined (__ACE_INLINE__)
#  define __ACE_INLINE__ 1
# endif /* __ACE_INLINE__ */
#endif

// If __ACE_INLINE__ is defined to be 0, we will undefine it
#if defined (__ACE_INLINE__) && (__ACE_INLINE__ == 0)
# undef __ACE_INLINE__
#endif /* __ACE_INLINE__ */

// We are build ACE and want to use MFC (multithreaded)
#if defined(ACE_HAS_MFC) && (ACE_HAS_MFC != 0) && defined (_MT)
# if (ACE_HAS_DLL != 0) && defined(ACE_BUILD_DLL) && !defined (_WINDLL)
// force multithreaded MFC DLL
#  define _WINDLL
# endif /* _AFXDLL */
# if !defined (_AFXDLL) && !defined (ACE_USES_STATIC_MFC)
#  define _AFXDLL
# endif /* _AFXDLL */
#endif

// <windows.h> and MFC's <afxwin.h> are mutually
// incompatible. <windows.h> is brain-dead about MFC; it doesn't check
// to see whether MFC stuff is anticipated or already in progress
// before doing its thing. ACE needs (practically always) <winsock.h>,
// and winsock in turn needs support either from windows.h or from
// afxwin.h. One or the other, not both.
//
// The MSVC++ V4.0 environment defines preprocessor macros that
// indicate the programmer has chosen something from the
// Build-->Settings-->General-->MFC combo-box. <afxwin.h> defines a
// macro itself to protect against double inclusion. We'll take
// advantage of all this to select the proper support for winsock. -
// trl 26-July-1996

// This is necessary since MFC users apparently can't #include
// <windows.h> directly.
#if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
#  include /**/ <afxwin.h>   /* He is doing MFC */
// Windows.h will be included via afxwin.h->afx.h->afx_ver_.h->afxv_w32.h
// #define      _INC_WINDOWS  // Prevent winsock.h from including windows.h
#elif defined (ACE_HAS_WINCE)
#  include /**/ <windows.h>
#endif

#if !defined (_INC_WINDOWS)     /* Already include windows.h ? */
// Must define strict before including windows.h !
# if defined (ACE_HAS_STRICT) && (ACE_HAS_STRICT != 0) && !defined (STRICT)
#  define STRICT 1
# endif /* ACE_HAS_STRICT */

# if !defined (WIN32_LEAN_AND_MEAN) && !defined (ACE_NO_WIN32_LEAN_AND_MEAN)
#  define WIN32_LEAN_AND_MEAN
# endif /* WIN32_LEAN_AND_MEAN */

#endif /* !defined (_INC_WINDOWS) */

// Always use WS2 when available
#if !defined(ACE_HAS_WINSOCK2)
# define ACE_HAS_WINSOCK2 1
#endif /* !defined(ACE_HAS_WINSOCK2) */


#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
# if !defined (_WINSOCK2API_)
// will also include windows.h, if not present
#  include /**/ <winsock2.h>
// WinCE 4 doesn't define the Exxx values without the WSA prefix, so do that
// here. This is all lifted from the #if 0'd out part of winsock2.h.
#  if defined (UNDER_CE)
#    define EWOULDBLOCK             WSAEWOULDBLOCK
#    define EINPROGRESS             WSAEINPROGRESS
#    define EALREADY                WSAEALREADY
#    define ENOTSOCK                WSAENOTSOCK
#    define EDESTADDRREQ            WSAEDESTADDRREQ
#    define EMSGSIZE                WSAEMSGSIZE
#    define EPROTOTYPE              WSAEPROTOTYPE
#    define ENOPROTOOPT             WSAENOPROTOOPT
#    define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
#    define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
#    define EOPNOTSUPP              WSAEOPNOTSUPP
#    define EPFNOSUPPORT            WSAEPFNOSUPPORT
#    define EAFNOSUPPORT            WSAEAFNOSUPPORT
#    define EADDRINUSE              WSAEADDRINUSE
#    define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
#    define ENETDOWN                WSAENETDOWN
#    define ENETUNREACH             WSAENETUNREACH
#    define ENETRESET               WSAENETRESET
#    define ECONNABORTED            WSAECONNABORTED
#    define ECONNRESET              WSAECONNRESET
#    define ENOBUFS                 WSAENOBUFS
#    define EISCONN                 WSAEISCONN
#    define ENOTCONN                WSAENOTCONN
#    define ESHUTDOWN               WSAESHUTDOWN
#    define ETOOMANYREFS            WSAETOOMANYREFS
#    define ETIMEDOUT               WSAETIMEDOUT
#    define ECONNREFUSED            WSAECONNREFUSED
#    define ELOOP                   WSAELOOP
#    define ENAMETOOLONG            WSAENAMETOOLONG
#    define EHOSTDOWN               WSAEHOSTDOWN
#    define EHOSTUNREACH            WSAEHOSTUNREACH
#    define ENOTEMPTY               WSAENOTEMPTY
#    define EPROCLIM                WSAEPROCLIM
#    define EUSERS                  WSAEUSERS
#    define EDQUOT                  WSAEDQUOT
#    define ESTALE                  WSAESTALE
#    define EREMOTE                 WSAEREMOTE
#  endif /* UNDER_CE */
# endif /* _WINSOCK2API */

# if defined (ACE_HAS_FORE_ATM_WS2)
#  include /**/ <ws2atm.h>
# endif /*ACE_HAS_FORE_ATM_WS2 */

// CE doesn't have Microsoft Winsock 2 extensions
# if !defined _MSWSOCK_ && !defined (ACE_HAS_WINCE)
#  include /**/ <mswsock.h>
# endif /* _MSWSOCK_ */

# if defined (_MSC_VER)
#  if defined (ACE_HAS_WINCE)
#    pragma comment(lib, "ws2.lib")
#  else
#    pragma comment(lib, "ws2_32.lib")
#    pragma comment(lib, "mswsock.lib")
#    if defined (ACE_HAS_IPV6)
#      pragma comment(lib, "iphlpapi.lib")
#    endif
#  endif /* ACE_HAS_WINCE */
# endif /* _MSC_VER */

# define ACE_WSOCK_VERSION 2, 0
#else
# if !defined (_WINSOCKAPI_)
   // will also include windows.h, if not present
#  include /**/ <winsock.h>
# endif /* _WINSOCKAPI */

// PharLap ETS has its own winsock lib, so don't grab the one
// supplied with the OS.
# if defined (_MSC_VER) && !defined (UNDER_CE) && !defined (ACE_HAS_PHARLAP)
#  pragma comment(lib, "wsock32.lib")
# endif /* _MSC_VER */

// We can't use recvmsg and sendmsg unless WinSock 2 is available
# define ACE_LACKS_RECVMSG
# define ACE_LACKS_SENDMSG

// Version 1.1 of WinSock
# define ACE_WSOCK_VERSION 1, 1
#endif /* ACE_HAS_WINSOCK2 */

// Platform supports IP multicast on Winsock 2
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
# define ACE_HAS_IP_MULTICAST
#endif /* ACE_HAS_WINSOCK2 */

#if !defined (ACE_HAS_WINCE) || defined (PPC)   /* CE only on some CPUs */
#  define ACE_HAS_INTERLOCKED_EXCHANGEADD
#endif
#define ACE_HAS_WIN32_TRYLOCK

#if !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_PHARLAP)
# define ACE_HAS_SIGNAL_OBJECT_AND_WAIT

// If CancelIO is undefined get the updated sp2-sdk from MS
# define ACE_HAS_CANCEL_IO
# define ACE_HAS_WIN32_OVERLAPPED_IO
# define ACE_HAS_WIN32_NAMED_PIPES
#endif /* !defined (ACE_USES_WINCE_SEMA_SIMULATION) && !ACE_HAS_PHARLAP */

#if !defined (ACE_SEH_DEFAULT_EXCEPTION_HANDLING_ACTION)
# define ACE_SEH_DEFAULT_EXCEPTION_HANDLING_ACTION EXCEPTION_CONTINUE_SEARCH
#endif /* ACE_SEH_DEFAULT_EXCEPTION_HANDLING_ACTION */

// ACE_HAS_QOS is defined in the qos.mpb base project.
// If qos=1 in default.features, then this macro will be defined.
#if defined (ACE_HAS_QOS) && !defined (ACE_HAS_WINSOCK2_GQOS)
# if defined (WINSOCK_VERSION)
#  define ACE_HAS_WINSOCK2_GQOS 1
# endif /* WINSOCK_VERSION */
#endif /* ACE_HAS_WINSOCK2_GQOS */

// These are the defaults and can be overridden by a user's config.h
#if !defined (ACE_DEFAULT_FILE_PERMS)
#  define ACE_DEFAULT_FILE_PERMS (FILE_SHARE_READ | FILE_SHARE_WRITE | \
                                  FILE_SHARE_DELETE)
// This alternate used to be used for pre-NT4 systems; may still be needed
// by knock-offs such as CE and Pharlap.
//#       define ACE_DEFAULT_FILE_PERMS (FILE_SHARE_READ | FILE_SHARE_WRITE)
#endif /* !defined (ACE_DEFAULT_FILE_PERMS) */

#define ACE_SIZEOF_WCHAR 2
#define ACE_HAS_MUTEX_TIMEOUTS
#define ACE_LACKS_STRUCT_DIR
#define ACE_LACKS_OPENDIR
#define ACE_LACKS_CLOSEDIR
#define ACE_LACKS_READDIR
#define ACE_LACKS_ALPHASORT
#define ACE_LACKS_MKSTEMP
#define ACE_LACKS_LSTAT
// Looks like Win32 has a non-const swab function
#define ACE_HAS_NONCONST_SWAB

// If we are using winsock2 then the SO_REUSEADDR feature is broken
// SO_REUSEADDR=1 behaves like SO_REUSEPORT=1. (SO_REUSEPORT is an
// extension to sockets on some platforms)
// We define SO_REUSEPORT here so that ACE_OS::setsockopt() can still
// allow the user to specify that a socketaddr can *always* be reused.
#if defined (ACE_HAS_WINSOCK2) && ACE_HAS_WINSOCK2 != 0 && ! defined(SO_REUSEPORT)
#define SO_REUSEPORT 0x0400  // We just have to pick a value that won't conflict
#endif

#if defined (ACE_WIN64)
// Data must be aligned on 8-byte boundaries, at a minimum.
#  define ACE_MALLOC_ALIGN 8
// Void pointers are 8 bytes
#  define ACE_SIZEOF_VOID_P 8
#endif /* ACE_WIN64 */

#if !defined (ACE_DISABLES_THREAD_LIBRARY_CALLS)
# define ACE_DISABLES_THREAD_LIBRARY_CALLS 0
#endif /* ACE_DISABLES_THREAD_LIBRARY_CALLS */

#if !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_PHARLAP)
#  define ACE_HAS_LOG_MSG_NT_EVENT_LOG
#endif /* !ACE_HAS_WINCE && !ACE_HAS_PHARLAP */

#if !defined (ACE_HAS_WINCE)
# define ACE_HAS_LLSEEK
#endif /* !ACE_HAS_WINCE */

// Needed for obtaining the MAC address
// I dont believe this will work under CE, notice the
// check for ACE_HAS_WINCE.
# if !defined (ACE_HAS_WINCE)
# include <nb30.h>
#  if defined (_MSC_VER)
#   pragma comment(lib, "netapi32.lib") // needed for obtaing MACaddress
#  endif
# endif /* !ACE_HAS_WINCE */

#if !defined (WINVER)
# define WINVER 0x0400 // pretend it's at least WinNT 4.0
#endif

///////////////////////////////////////
// windows version-specific definitions
// see: http://msdn2.microsoft.com/en-us/library/aa383745.aspx
//
// For TSS information
// see http://msdn.microsoft.com/library/default.asp?url=/library/en-us/dllproc/base/thread_local_storage.asp

#if (WINVER>=0x0600)
// Windows Server 2008 definitions go here
// Windows Vista defintions go here
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 1088
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#elif (WINVER>=0x0502)
  // Windows Server 2003 SP1 definitions go here
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 1088
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#elif (WINVER>=0x0501)
// Windows XP definitions go here
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 1088
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#elif (WINVER>=0x0500)
// Windows 2000 definitions go here
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 1088
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#elif (WINVER>=0x0410)
// Windows 98 definitions go here
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 80
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#else
// antique windows
#  if ! defined(ACE_DEFAULT_THREAD_KEYS)
#    define ACE_DEFAULT_THREAD_KEYS 64
#  endif // ! defined(ACE_DEFAULT_THREAD_KEYS)
#endif

#if !defined (ACE_DEFAULT_BACKLOG)
#  define ACE_DEFAULT_BACKLOG SOMAXCONN
#endif /* ACE_DEFAULT_BACKLOG */

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_COMMON_H */

