// $Id: config-WinCE.h 93622 2011-03-22 15:45:57Z johnnyw $

// Note: For WinCE build, simply use: #include "ace/config-win32.h"
//       It is same as config.h for Windows NT/2k so that you can
//       share same files and directories for both WinCE and NT/2k
//       builds, unless you add additional definition(s) for each
//       specific build or change the output directory.

#ifndef ACE_CONFIG_WINCE_H
#define ACE_CONFIG_WINCE_H

#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
# error Use config-win32.h in config.h instead of this header
#endif  // ACE_CONFIG_WIN32_H

#if !defined (_WIN32_WCE)
# error Define _WIN32_WCE to version (i.e. 500 = 5.0)
#endif  // _WIN32_WCE

#if (_WIN32_WCE < 500)
# error ACE requires Windows CE 5.0 and later.
#endif  // _WIN32_WCE

#if !defined (ACE_HAS_WINCE)
# define ACE_HAS_WINCE 1
#endif

#if defined (_MSC_VER) && (_MSC_VER < 1400)
// WinCE prior to Visual Studio 2005 integration doesn't have most of
// the standard C library time functions. It also doesn't define struct tm.
// SYSTEMTIME has pretty much the same info though, so we can map it when
// needed. Define struct tm here and use it when needed. This is taken
// from the standard C library.
# define ACE_LACKS_STRUCT_TM
#endif

// We need these libraries to build:
#if defined (_MSC_VER)
#  pragma comment(lib,"corelibc.lib")
#  pragma comment(linker, "/nodefaultlib:oldnames.lib")
#endif

// Only DLL version is supported on CE.
//#if defined (ACE_HAS_DLL)
//# undef ACE_HAS_DLL
//#endif  // ACE_HAS_DLL
//#define ACE_HAS_DLL 1

// Need to define LD search path explicitly on CE because
// CE doesn't have environment variables and we can't get
// the information using getenv.
#define ACE_DEFAULT_LD_SEARCH_PATH ACE_TEXT (".\\;\\windows")

#define ACE_LACKS_ABORT
#define ACE_LACKS_FCNTL_H
#define ACE_LACKS_SYS_TYPES_H
#define ACE_LACKS_GETCWD
#define ACE_LACKS_ASCTIME
#define ACE_LACKS_ASCTIME_R
#define ACE_LACKS_GMTIME
#define ACE_LACKS_GMTIME_R
#define ACE_LACKS_LOCALTIME
#define ACE_LACKS_STRTOK_R
#define ACE_LACKS_PERROR
#define ACE_LACKS_STRFTIME
#define ACE_LACKS_WIN32_SETFILEPOINTEREX
#define ACE_LACKS_WIN32_SERVICES
#define ACE_LACKS_WIN32_SECURITY_DESCRIPTORS
#define ACE_LACKS_GETPROCESSTIMES
#define ACE_LACKS_PDH_H
#define ACE_LACKS_PDHMSG_H
#define ACE_LACKS_TIME
#define ACE_LACKS_TZSET
#define ACE_LACKS_RAISE
#define ACE_LACKS_BSEARCH

#define ACE_LACKS_MSG_WFMO
#define ACE_LACKS_UMASK
#define ACE_HAS_TYPES_H
#define ACE_LACKS_DEV_T

#define ACE_ISCTYPE_EQUIVALENT ::_isctype

// WinCE only supports the UNICODE API
#if !defined (ACE_USES_WCHAR)
# define ACE_USES_WCHAR
#endif /* ACE_USES_WCHAR */

#if (_WIN32_WCE < 0x600)
# define ACE_USES_WINCE_SEMA_SIMULATION
# define ACE_LACKS_ERRNO_H
# define ACE_LACKS_DUP
# define ACE_LACKS_GETSYSTEMTIMEASFILETIME
#endif /*  (_WIN32_WCE < 0x600) */

#define ACE_LACKS_REGNOTIFYCHANGEKEYVALUE

#define ACE_HAS_NONSTATIC_OBJECT_MANAGER 1

#if ! defined(ACE_DEFAULT_THREAD_KEYS)
# define ACE_DEFAULT_THREAD_KEYS TLS_MINIMUM_AVAILABLE
#endif // ! defined(ACE_DEFAULT_THREAD_KEYS)

// FILE stuff isn't always defined in CE
#if (_MSC_VER < 1400) && !defined (_FILE_DEFINED)
  typedef void FILE;
# define _FILE_DEFINED
#endif  /* _MSC_VER < 1400 && !_FILE_DEFINED */

// This was defined in previous versions of CE, but not 2.11
#define EXCEPTION_ACCESS_VIOLATION STATUS_ACCESS_VIOLATION

#define ACE_MAIN WINAPI WinMain

// SH3 cross-compiler can't handle inline functions correctly
// (along with other bugs.)
#if defined (SH3)
# define ACE_LACKS_INLINE_FUNCTIONS
#endif  // SH3 && _DEBUG

#ifndef ACE_DEFAULT_SERVER_HOST
# define ACE_DEFAULT_SERVER_HOST ACE_TEXT("localhost")
#endif  // ACE_DEFAULT_SERVER_HOST

// @@ Need to remap every function that uses any of these flags to
//    Win32 API.  These are for ANSI styled function and are not
//    available on WinCE.

#define _O_RDONLY       0x0000  // open for reading only
#define _O_WRONLY       0x0001  // open for writing only
#define _O_RDWR         0x0002  // open for reading and writing
#define _O_APPEND       0x0008  // writes done at eof

#define _O_CREAT        0x0100  // create and open file
#define _O_TRUNC        0x0200  // open and truncate
#define _O_EXCL         0x0400  // open only if file doesn't already exist

// O_TEXT files have <cr><lf> sequences translated to <lf> on read()'s,
// and <lf> sequences translated to <cr><lf> on write()'s
#define _O_TEXT         0x4000  // file mode is text (translated)
#define _O_BINARY       0x8000  // file mode is binary (untranslated)

// Temporary file bit - file is deleted when last handle is closed
#define _O_TEMPORARY    0x0040  // temporary file bit

// Non-ANSI names
#define O_RDONLY        _O_RDONLY
#define O_WRONLY        _O_WRONLY
#define O_RDWR          _O_RDWR
#define O_APPEND        _O_APPEND
#define O_CREAT         _O_CREAT
#define O_TRUNC         _O_TRUNC
#define O_EXCL          _O_EXCL
#define O_TEXT          _O_TEXT
#define O_BINARY        _O_BINARY
#define O_TEMPORARY     _O_TEMPORARY

// @@ NSIG value.  This is definitely not correct.
#define NSIG 23

#if !defined (FILE_MAP_COPY)
#define FILE_MAP_COPY 0
#endif

#define ACE_HAS_INTERLOCKED_EXCHANGEADD
#define ACE_LACKS_ACCESS
#define ACE_LACKS__WACCESS
#define ACE_HAS_ACCESS_EMULATION
#define ACE_LACKS_EXEC
#define ACE_LACKS_MKTEMP
#define ACE_LACKS_ISATTY
#define ACE_LACKS_STRERROR
#define ACE_LACKS_SYSTEM
#define ACE_LACKS_PIPE

#define ACE_LACKS_CHDIR
#define ACE_LACKS_GETENV
#define ACE_LACKS_SETENV
#define ACE_LACKS_UNSETENV
#define ACE_LACKS_PUTENV
#define ACE_LACKS_GETENVSTRINGS
#define ACE_LACKS_STRENVDUP
#define ACE_LACKS_REALPATH
#define ACE_LACKS_SWAB
#define ACE_LACKS_TEMPNAM

#if defined (_WIN32_WCE_EMULATION)
// @@ For some reason, qsort isn't defined correctly (_stdcall vs _cdecl)
// under emulation.  So for right now, exclude it.
# define ACE_LACKS_QSORT
#endif  // _WIN32_WCE_EMULATION

#if !defined (BUFSIZ)
# define BUFSIZ 1024
#endif

#define ACE_LACKS_MALLOC_H      // We do have malloc.h, but don't use it.

#define ACE_HAS_WINCE_BROKEN_ERRNO

#define ACE_HAS_STRDUP_EMULATION

#if !defined (MAXSYMLINKS)
# define MAXSYMLINKS 0
#endif

// WinCE can't do fixed addresses for memory-mapped files.
#if defined (ACE_DEFAULT_BASE_ADDR)
# undef ACE_DEFAULT_BASE_ADDR
#endif
#define ACE_DEFAULT_BASE_ADDR 0

#if (_WIN32_WCE < 0x600)
# define ACE_HAS_TSS_EMULATION
#endif  // WinCE version < 6.0

// CE doesn't support FILE_SHARE_DELETE like regular windows
#if !defined (ACE_DEFAULT_FILE_PERMS)
# define ACE_DEFAULT_FILE_PERMS (FILE_SHARE_READ | FILE_SHARE_WRITE)
#endif

#define ACE_LACKS_SIGNAL_H
#define ACE_LACKS_SYS_STAT_H

#include /**/ "ace/post.h"

#endif  // ACE_CONFIG_WINCE_H
