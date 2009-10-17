// -*- C++ -*-
// $Id: config-win32-ghs.h 81992 2008-06-16 19:09:50Z wotte $

// The following configuration file contains defines for Green Hills compilers.

#ifndef ACE_CONFIG_WIN32_GHS_H
#define ACE_CONFIG_WIN32_GHS_H
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
// GHS does not provide DLL support
#define ACE_HAS_DLL 0
#define TAO_HAS_DLL 0
#undef _DLL

//Green Hills Native x86 does not support structural exceptions
# undef ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS
# undef ACE_HAS_WCHAR
# define ACE_CONFIG_INCLUDE_GHS_COMMON
# include "ace/config-ghs-common.h"

// Changed ACE_TEXT to ACE_TEXT in the following line
# define ACE_CC_NAME ACE_TEXT ("Green Hills C++")
# define ACE_CC_MAJOR_VERSION (1)
# define ACE_CC_MINOR_VERSION (8)
# define ACE_CC_BETA_VERSION (9)
# ifndef ACE_USING_MCPP_PREPROCESSOR
#  define ACE_CC_PREPROCESSOR "GCX.EXE"
#  define ACE_CC_PREPROCESSOR_ARGS "-E"
# endif

// GHS uses Microsoft's standard cpp library, which has auto_ptr.
# undef ACE_LACKS_AUTO_PTR
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
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_HAS_STDCPP_STL_INCLUDES 1
# define ACE_HAS_STRERROR 1
# define ACE_HAS_STRING_CLASS 1
# define ACE_HAS_TEMPLATE_TYPEDEFS 1
# define ACE_HAS_USER_MODE_MASKS 1
# define ACE_LACKS_ACE_IOSTREAM 1
//# define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
# define ACE_LACKS_STRPTIME 1
//# define ACE_LACKS_PRAGMA_ONCE 1
# define ACE_LACKS_STRRECVFD 1
//# define ACE_NEW_THROWS_EXCEPTIONS 1
# define ACE_SIZEOF_LONG_DOUBLE 10
# define ACE_TEMPLATES_REQUIRE_SOURCE 1
// Changed ACE_TEXT to ACE_TEXT in the following two lines
# define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%I64u")
# define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%I64d")
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
// Set the following to zero to placate SString.h ACE_WString CTOR
# undef ACE_WSTRING_HAS_USHORT_SUPPORT

// Green Hills Native x86 does not support __int64 keyword
# define ACE_LACKS_LONGLONG_T

/* need to ensure these are included before <iomanip> */
# include <time.h>
# include <stdlib.h>

# if !defined (ACE_LD_DECORATOR_STR) && defined (_DEBUG)
#  define ACE_LD_DECORATOR_STR ACE_TEXT ("d")
# endif

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_GHS_H */

