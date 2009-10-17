//=============================================================================
/**
 *  @file   config-win32-msvc.h
 *
 *  $Id: config-win32-msvc.h 82643 2008-08-19 14:02:12Z johnnyw $
 *
 *  @brief  Microsoft Visual C++ configuration file.
 *
 *  This file is the ACE configuration file for Microsoft Visual C++ versions
 *  5.0, 6.0, and 7.0 (.NET)
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_CONFIG_WIN32_MSVC_H
#define ACE_CONFIG_WIN32_MSVC_H
#include /**/ "ace/pre.h"
#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */
#define ACE_CC_NAME ACE_TEXT ("Visual C++")
#ifndef ACE_USING_MCPP_PREPROCESSOR
# define ACE_CC_PREPROCESSOR "CL.EXE"
# define ACE_CC_PREPROCESSOR_ARGS "-nologo -E"
#endif
#define ACE_CC_MAJOR_VERSION (_MSC_VER / 100 - 6)
#define ACE_CC_MINOR_VERSION (_MSC_VER % 100)
#define ACE_CC_BETA_VERSION (0)
#if !defined (ACE_LD_DECORATOR_STR)
# if defined (_DEBUG)
#  define ACE_LD_DECORATOR_STR ACE_TEXT ("d")
# endif  /* _DEBUG */
#endif  /* ACE_LD_DECORATOR_STR */
#if !defined(_NATIVE_WCHAR_T_DEFINED)
  #define ACE_LACKS_NATIVE_WCHAR_T
#endif
// Win Mobile still does thread exits differently than PC Windows.
#if defined (_WIN32_WCE)
#  define ACE_ENDTHREADEX(STATUS) ExitThread ((DWORD) STATUS)
#else
#  define ACE_ENDTHREADEX(STATUS) ::_endthreadex ((DWORD) STATUS)
#endif /* _WIN32_WCE */
#if (_MSC_VER >= 1500)
# include "ace/config-win32-msvc-9.h"
#elif (_MSC_VER >= 1400)
# include "ace/config-win32-msvc-8.h"
#elif (_MSC_VER >= 1310)
# include "ace/config-win32-msvc-7.h"
#else
# error This version of Microsoft Visual C++ is not supported.
#endif
// MFC changes the behavior of operator new at all MSVC versions from 6 up
// by throwing a static CMemoryException* instead of std::bad_alloc
// (see ace/OS_Memory.h). This MFC exception object needs to be cleaned up
// by calling its Delete() method.
#if defined (ACE_HAS_MFC) && (ACE_HAS_MFC == 1)
#  if !defined (ACE_NEW_THROWS_EXCEPTIONS)
#    define ACE_NEW_THROWS_EXCEPTIONS
#  endif
#  if defined (ACE_bad_alloc)
#    undef ACE_bad_alloc
#  endif
#  define ACE_bad_alloc CMemoryException *e
#  if defined (ACE_del_bad_alloc)
#    undef ACE_del_bad_alloc
#  endif
#  define ACE_del_bad_alloc e->Delete();
#endif /* ACE_HAS_MFC && ACE_HAS_MFC==1 */
#if defined(ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
// must have _MT defined to include multithreading
// features from win32 headers
# if !defined(_MT) && !defined (ACE_HAS_WINCE)
// *** DO NOT *** defeat this error message by defining _MT yourself.
// On MSVC, this is changed by selecting the Multithreaded
// DLL or Debug Multithreaded DLL in the Project Settings
// under C++ Code Generation.
#  error You must link against multi-threaded libraries when using ACE (check your project settings)
# endif /* !_MT && !ACE_HAS_WINCE */
#endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */
#include <malloc.h>
// Although ACE does have alloca() on this compiler/platform combination, it is
// disabled by default since it can be dangerous.  Uncomment the following line
// if you ACE to use it.
//#define ACE_HAS_ALLOCA 1
#define ACE_LACKS_DIRENT_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_INTTYPES_H
#define ACE_LACKS_NETDB_H
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_NETINET_IN_H
#define ACE_LACKS_STDINT_H
#define ACE_LACKS_STROPTS_H
#define ACE_LACKS_SYS_IOCTL_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_MMAN_H
#define ACE_LACKS_SYS_RESOURCE_H
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SYS_SOCKET_H
#define ACE_LACKS_SYS_TIME_H
#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_WAIT_H
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_STRINGS_H
#define ACE_LACKS_PWD_H
#define ACE_LACKS_POLL_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_REGEX_H
#define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%I64d")
#define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%I64u")
#define ACE_STRTOULL_EQUIVALENT ::_strtoui64
#define ACE_WCSTOOULL_EQUIVALENT ::_wcstoui64
// Turn off warnings for /W4
// To resume any of these warning: #pragma warning(default: 4xxx)
// which should be placed after these defines
#if !defined (ALL_WARNINGS) && defined(_MSC_VER) && !defined(ghs) && !defined(__MINGW32__)
#     pragma warning(disable: 4127)  /* constant expression for TRACE/ASSERT */
#     pragma warning(disable: 4134)  /* message map member fxn casts */
#     pragma warning(disable: 4511)  /* private copy constructors are good to have */
#     pragma warning(disable: 4512)  /* private operator= are good to have */
#     pragma warning(disable: 4514)  /* unreferenced inlines are common */
#     pragma warning(disable: 4710)  /* private constructors are disallowed */
#     pragma warning(disable: 4705)  /* statement has no effect in optimized code */
#     pragma warning(disable: 4791)  /* loss of debugging info in retail version */
#     pragma warning(disable: 4275)  /* deriving exported class from non-exported */
#     pragma warning(disable: 4251)  /* using non-exported as public in exported */
#     pragma warning(disable: 4786)  /* identifier was truncated to '255' characters in the browser information */
#     pragma warning(disable: 4097)  /* typedef-name used as synonym for class-name */
#     pragma warning(disable: 4800)  /* converting int to boolean */
# if defined (__INTEL_COMPILER)
#     pragma warning(disable: 1744)  /* field of class type without a DLL interface used in a class with a DLL interface */
#     pragma warning(disable: 1738)
# endif
#endif /* !ALL_WARNINGS && _MSV_VER && !ghs && !__MINGW32__ */
// STRICT type checking in WINDOWS.H enhances type safety for Windows
// programs by using distinct types to represent all the different
// HANDLES in Windows. So for example, STRICT prevents you from
// mistakenly passing an HPEN to a routine expecting an HBITMAP.
// Note that we only use this if we
#   if defined (ACE_HAS_STRICT) && (ACE_HAS_STRICT != 0)
#     if !defined (STRICT)   /* may already be defined */
#       define STRICT
#     endif /* !STRICT */
#   endif /* ACE_HAS_STRICT */
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_MSVC_H */

