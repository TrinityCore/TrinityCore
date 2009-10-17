// -*- C++ -*-
//$Id: config-borland-common.h 82294 2008-07-12 13:03:37Z johnnyw $
// The following configuration file contains defines for Borland compilers.
#ifndef ACE_CONFIG_BORLAND_COMMON_H
#define ACE_CONFIG_BORLAND_COMMON_H
#include /**/ "ace/pre.h"
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
# define ACE_CC_NAME ACE_TEXT ("Borland C++ Builder")
# define ACE_CC_MAJOR_VERSION (__BORLANDC__ / 0x100)
# define ACE_CC_MINOR_VERSION (__BORLANDC__ % 0x100)
# define ACE_CC_BETA_VERSION (0)
# ifndef ACE_USING_MCPP_PREPROCESSOR
#  define ACE_CC_PREPROCESSOR_ARGS "-q -P- -o%s"
# endif
# define ACE_EXPORT_NESTED_CLASSES 1
# define ACE_HAS_CPLUSPLUS_HEADERS 1
# define ACE_HAS_EXCEPTIONS
# define ACE_HAS_GNU_CSTRING_H 1
# define ACE_HAS_NONCONST_SELECT_TIMEVAL
# define ACE_HAS_SIG_ATOMIC_T
# define ACE_HAS_STANDARD_CPP_LIBRARY 1
# define ACE_HAS_STDCPP_STL_INCLUDES 1
# define ACE_HAS_STRERROR
# define ACE_HAS_STRING_CLASS 1
# define ACE_HAS_TEMPLATE_TYPEDEFS 1
# define ACE_HAS_USER_MODE_MASKS 1
# define ACE_LACKS_ACE_IOSTREAM 1
# define ACE_LACKS_LINEBUFFERED_STREAMBUF 1
# define ACE_LACKS_STRPTIME 1
# if (__BORLANDC__ < 0x590)
#   define ACE_LACKS_PLACEMENT_OPERATOR_DELETE 1
# endif
# define ACE_LACKS_PRAGMA_ONCE 1
# define ACE_HAS_NEW_NOTHROW
# define ACE_TEMPLATES_REQUIRE_SOURCE 1
# define ACE_SIZEOF_LONG_DOUBLE 10
# define ACE_UINT64_FORMAT_SPECIFIER ACE_TEXT ("%Lu")
# define ACE_INT64_FORMAT_SPECIFIER ACE_TEXT ("%Ld")
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
# define ACE_USES_STD_NAMESPACE_FOR_STDC_LIB 0
# define ACE_ENDTHREADEX(STATUS) ::_endthreadex ((DWORD) STATUS)
# define ACE_LACKS_SWAB
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_BORLAND_COMMON_H */

