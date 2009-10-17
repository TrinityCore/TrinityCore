// -*- C++ -*-
//$Id: config-win32-borland.h 82643 2008-08-19 14:02:12Z johnnyw $
// The following configuration file contains defines for Borland compilers.
#ifndef ACE_CONFIG_WIN32_BORLAND_H
#define ACE_CONFIG_WIN32_BORLAND_H
#include /**/ "ace/pre.h"
#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */
#include "config-borland-common.h"
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
// Borland on win32 has swab
# undef ACE_LACKS_SWAB
# define ACE_WSTRING_HAS_USHORT_SUPPORT 1
# define ACE_HAS_DIRENT
#ifdef ACE_USES_STD_NAMESPACE_FOR_STDC_LIB
#undef ACE_USES_STD_NAMESPACE_FOR_STDC_LIB
#define ACE_USES_STD_NAMESPACE_FOR_STDC_LIB 1
#endif
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
#if (__BORLANDC__ < 0x580)
# define ACE_LACKS_INTPTR_T
# define ACE_HAS_NONCONST_SWAB
# define ACE_HAS_NONCONST_FDOPEN
#endif
#if (__BORLANDC__ < 0x610)
# define ACE_HAS_NONCONST_TEMPNAM
# define ACE_LACKS_STRTOULL
# define ACE_LACKS_WCSTOULL
#endif
#if (__BORLANDC__ <= 0x610)
// Older Borland compilers can't handle assembly in inline methods or
// templates (E2211). When we build for pentium optimized and we are inlining
// then we disable inline assembly
# if defined (ACE_HAS_PENTIUM) && defined(__ACE_INLINE__)
#  define ACE_LACKS_INLINE_ASSEMBLY
# endif
#endif
#define ACE_WCSDUP_EQUIVALENT ::_wcsdup
#define ACE_STRCASECMP_EQUIVALENT ::stricmp
#define ACE_STRNCASECMP_EQUIVALENT ::strnicmp
#define ACE_HAS_ITOA 1
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_BORLAND_H */

