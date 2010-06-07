// -*- C++ -*-
//$Id: config-win32-borland.h 89292 2010-03-04 08:06:15Z johnnyw $

// The following configuration file contains defines for Borland compilers.

#ifndef ACE_CONFIG_WIN32_BORLAND_H
#define ACE_CONFIG_WIN32_BORLAND_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#define ACE_HAS_CUSTOM_EXPORT_MACROS
#define ACE_Proper_Export_Flag __declspec (dllexport)
#define ACE_Proper_Import_Flag __declspec (dllimport)
#define ACE_EXPORT_SINGLETON_DECLARATION(T) template class __declspec (dllexport) T
#define ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllexport) SINGLETON_TYPE<CLASS, LOCK>;
#define ACE_IMPORT_SINGLETON_DECLARATION(T) template class __declspec (dllimport) T
#define ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) template class __declspec (dllimport) SINGLETON_TYPE <CLASS, LOCK>;

// In later versions of C++Builder we will prefer inline functions by
// default. The debug configuration of ACE is built with functions
// out-of-line, so when linking your application against a debug ACE
// build, you can choose to use the out-of-line functions by adding
// ACE_NO_INLINE=1 to your project settings.
# if !defined (__ACE_INLINE__)
#  define __ACE_INLINE__ 1
# endif /* __ACE_INLINE__ */

# define ACE_CC_NAME ACE_TEXT ("Embarcadero C++ Builder")
# define ACE_CC_MAJOR_VERSION (__BORLANDC__ / 0x100)
# define ACE_CC_MINOR_VERSION (__BORLANDC__ % 0x100)
# define ACE_CC_BETA_VERSION (0)

#ifndef ACE_USING_MCPP_PREPROCESSOR
# if (__BORLANDC__ >= 0x620)
#  define ACE_CC_PREPROCESSOR_ARGS "-q -Sl -o%s"
# else
#  define ACE_CC_PREPROCESSOR_ARGS "-q -P- -o%s"
# endif
#endif

// Automatically define WIN32 macro if the compiler tells us it is our
// target platform.
# if defined (__WIN32__) && !defined (WIN32)
#  define WIN32 1
# endif

// When building a VCL application, the main VCL header file should be
// included before anything else. You can define ACE_HAS_VCL=1 in your
// project settings to have this file included for you automatically.
# if defined (ACE_HAS_VCL) && (ACE_HAS_VCL != 0)
#  include /**/ <vcl.h>
# endif

# define ACE_CC_PREPROCESSOR "CPP32.EXE"

# include "ace/config-win32-common.h"

# define ACE_WSTRING_HAS_USHORT_SUPPORT 1
# define ACE_HAS_DIRENT

#define ACE_USES_STD_NAMESPACE_FOR_STDC_LIB 1

#define ACE_NEEDS_DL_UNDERSCORE

#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_REGEX_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_PWD_H
#define ACE_LACKS_POLL_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_STRINGS_H
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_INTTYPES_H
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_SYS_TIME_H
#define ACE_LACKS_SYS_RESOURCE_H
#define ACE_LACKS_SYS_WAIT_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_SYS_MMAN_H
#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_SOCKET_H
#define ACE_LACKS_NETINET_IN_H
#define ACE_LACKS_NETDB_H
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SYS_IOCTL_H
#define ACE_LACKS_STROPTS_H

#undef ACE_LACKS_STRUCT_DIR
#undef ACE_LACKS_CLOSEDIR
#undef ACE_LACKS_OPENDIR
#undef ACE_LACKS_READDIR
#undef ACE_LACKS_REWINDDIR

#define ACE_HAS_WOPENDIR
#define ACE_HAS_WCLOSEDIR
#define ACE_HAS_WREADDIR
#define ACE_HAS_WREWINDDIR

#define ACE_LACKS_STRRECVFD
#define ACE_USES_EXPLICIT_STD_NAMESPACE

#define ACE_HAS_TIME_T_LONG_MISMATCH

#define ACE_EXPORT_NESTED_CLASSES 1
#define ACE_HAS_CPLUSPLUS_HEADERS 1
#define ACE_HAS_EXCEPTIONS
#define ACE_HAS_NONCONST_SELECT_TIMEVAL
#define ACE_HAS_SIG_ATOMIC_T
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#define ACE_HAS_STDCPP_STL_INCLUDES 1
#define ACE_HAS_STRING_CLASS 1
#define ACE_HAS_TEMPLATE_TYPEDEFS 1
#define ACE_HAS_USER_MODE_MASKS 1
#define ACE_LACKS_ACE_IOSTREAM 1
#define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
#define ACE_HAS_NEW_NOTHROW
#define ACE_TEMPLATES_REQUIRE_SOURCE 1
#define ACE_SIZEOF_LONG_DOUBLE 10
#define ACE_UINT64_FORMAT_SPECIFIER_ASCII "%Lu"
#define ACE_INT64_FORMAT_SPECIFIER_ASCII "%Ld"
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#define ACE_USES_STD_NAMESPACE_FOR_ABS 1
#define ACE_ENDTHREADEX(STATUS) ::_endthreadex ((DWORD) STATUS)

#if defined(ACE_MT_SAFE) && (ACE_MT_SAFE != 0)
// must have _MT defined to include multithreading
// features from win32 headers
# if !defined(__MT__)
// *** DO NOT *** defeat this error message by defining __MT__ yourself.
// You must link with the multi threaded libraries. Add -tWM to your
// compiler options
#  error You must link against multi-threaded libraries when using ACE (check your project settings)
# endif /* !_MT && !ACE_HAS_WINCE */
#endif /* ACE_MT_SAFE && ACE_MT_SAFE != 0 */

#if (__BORLANDC__ < 0x620)
# define ACE_LACKS_ISBLANK
# define ACE_LACKS_ISWBLANK
# define ACE_LACKS_PRAGMA_ONCE 1
#endif

#define ACE_LACKS_ISWCTYPE
#define ACE_LACKS_ISCTYPE

#if (__BORLANDC__ < 0x620)
// Older Borland compilers can't handle assembly in inline methods or
// templates (E2211). When we build for pentium optimized and we are inlining
// then we disable inline assembly
# if defined (ACE_HAS_PENTIUM) && defined(__ACE_INLINE__)
#  define ACE_LACKS_INLINE_ASSEMBLY
# endif
#endif

#if (__BORLANDC__ == 0x621)
// C++ Builder 2010 wcsncat seems broken
# define ACE_LACKS_WCSNCAT
#endif

#define ACE_WCSDUP_EQUIVALENT ::_wcsdup
#define ACE_STRCASECMP_EQUIVALENT ::stricmp
#define ACE_STRNCASECMP_EQUIVALENT ::strnicmp
#define ACE_WTOF_EQUIVALENT ::_wtof
#define ACE_FILENO_EQUIVALENT(X) (_get_osfhandle (::_fileno (X)))
#define ACE_HAS_ITOA 1

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_BORLAND_H */
