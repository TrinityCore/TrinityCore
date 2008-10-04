// -*- C++ -*-
// $Id: config-win32-dmc.h 81992 2008-06-16 19:09:50Z wotte $

// The following configuration file contains defines for Digital Mars compilers.

#ifndef ACE_CONFIG_WIN32_DMC_H
#define ACE_CONFIG_WIN32_DMC_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#ifndef WIN32
#  define WIN32
#endif /* WIN32 */

#undef _M_IX86
// This turns on ACE_HAS_PENTIUM
#define _M_IX86 500

#if defined ACE_LACKS_STRUCT_DIR
# undef ACE_LACKS_STRUCT_DIR
#endif

// Changed ACE_TEXT to ACE_TEXT in the following line
# define ACE_CC_NAME ACE_TEXT ("Digital Mars")
# define ACE_CC_MAJOR_VERSION (1)
# define ACE_CC_MINOR_VERSION (8)
# define ACE_CC_BETA_VERSION (9)
# ifndef ACE_USING_MCPP_PREPROCESSOR
#  define ACE_CC_PREPROCESSOR "DMC.EXE"
#  define ACE_CC_PREPROCESSOR_ARGS "-E"
# endif

// Microsoft's standard cpp library auto_ptr doesn't have reset ().
# define ACE_AUTO_PTR_LACKS_RESET

#define ACE_ENDTHREADEX(STATUS) ::_endthreadex ((DWORD) STATUS)

// This section below was extracted from config-win32-msvc
#define ACE_HAS_ITOA
#define ACE_ITOA_EQUIVALENT ::_itoa
#define ACE_STRCASECMP_EQUIVALENT ::_stricmp
#define ACE_STRNCASECMP_EQUIVALENT ::_strnicmp
#define ACE_WCSDUP_EQUIVALENT ::_wcsdup
//  This section above was extracted from config-win32-msvc

# define ACE_EXPORT_NESTED_CLASSES 1
# define ACE_HAS_CPLUSPLUS_HEADERS 1
//# define ACE_HAS_EXCEPTIONS 1
# define ACE_HAS_GNU_CSTRING_H 1
# define ACE_HAS_NONCONST_SELECT_TIMEVAL 1
# define ACE_HAS_SIG_ATOMIC_T 1
# define ACE_HAS_STANDARD_CPP_LIBRARY 0
# define ACE_HAS_STDCPP_STL_INCLUDES 1
# define ACE_HAS_STRERROR 1
# define ACE_HAS_STRING_CLASS 1
# define ACE_HAS_TEMPLATE_TYPEDEFS 1
# define ACE_HAS_USER_MODE_MASKS 1
//# define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
# define ACE_LACKS_STRPTIME 1
//# define ACE_LACKS_PRAGMA_ONCE 1
//# define ACE_NEW_THROWS_EXCEPTIONS 1
# define ACE_SIZEOF_LONG_DOUBLE 10
# define ACE_TEMPLATES_REQUIRE_SOURCE 1
// Changed ACE_TEXT to ACE_TEXT in the following two lines
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_HAS_STRBUF_T
#define ACE_HAS_3_PARAM_WCSTOK
#define ACE_USES_OLD_IOSTREAMS
#define ACE_LACKS_UCONTEXT_H
#define ACE_LACKS_SYS_RESOURCE_H
#define ACE_LACKS_SYS_WAIT_H
#define ACE_LACKS_STRINGS_H
#define ACE_LACKS_SYS_IPC_H
#define ACE_LACKS_SYS_SEM_H
#define ACE_LACKS_SEMAPHORE_H
#define ACE_LACKS_SYS_MMAN_H
#define ACE_LACKS_SYS_UIO_H
#define ACE_LACKS_SYS_SOCKET_H
#define ACE_LACKS_NETINET_IN_H
#define ACE_LACKS_SYS_IOCTL_H
#define ACE_LACKS_SYS_SELECT_H
#define ACE_LACKS_NET_IF_H
#define ACE_LACKS_DLFCN_H
#define ACE_LACKS_NETDB_H
#define ACE_LACKS_SYS_SHM_H
#define ACE_LACKS_REGEX_H
#define ACE_LACKS_SYS_MSG_H
#define ACE_LACKS_NETINET_TCP_H
#define ACE_LACKS_UNISTD_H
#define ACE_LACKS_TERMIOS_H
#define ACE_LACKS_ACE_IOSTREAM
#define ACE_HAS_NONCONST_TEMPNAM

// Typedefs which we expect DMC to do, but they don't do that
typedef long o_uid_t;
typedef long o_gid_t;

#include "io.h"
#undef umask;
#undef tell;

# if !defined (ACE_LD_DECORATOR_STR) && defined (_DEBUG)
#  define ACE_LD_DECORATOR_STR ACE_TEXT ("d")
# endif

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_DMC_H */
