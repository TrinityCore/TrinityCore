/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   config-win32-msvc-9.h
 *
 *  $Id: config-win32-msvc-9.h 81935 2008-06-12 22:01:53Z jtc $
 *
 *  @brief  Microsoft Visual C++ 9.0 configuration file.
 *
 *  This file is the ACE configuration file for Microsoft Visual C++ version 9.
 *
 *  @note Do not include this file directly, include config-win32.h instead.
 */
//=============================================================================
#ifndef ACE_CONFIG_WIN32_MSVC_9_H
#define ACE_CONFIG_WIN32_MSVC_9_H
#include /**/ "ace/pre.h"
#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */
#ifndef ACE_WIN32_VC9
#  define ACE_WIN32_VC9
#endif
// Visual C++ 9.0 (.NET) deprecated the old iostreams
#if !defined (ACE_HAS_STANDARD_CPP_LIBRARY)
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#endif
#if !defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#endif
// Windows' timeval is non-conformant (defined in terms of long instead of
// time_t) and VC9 (on desktop, not CE) changed time_t to a 64-bit value
// even when compiling a 32-bit application. Therefore, ace/Time_Value
// needs to rearrange a few things for this compiler. See Time_Value.h
// for complete details.
#if !defined (ACE_HAS_WINCE)
#  define ACE_HAS_TIME_T_LONG_MISMATCH
#endif
#define ACE_HAS_ITOA
#define ACE_HAS_HEADER_ALLOCATED_CLASS_STATIC_CONST_INT_STOREAGE
#define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR
#define ACE_ITOA_EQUIVALENT ::_itoa
#define ACE_STRCASECMP_EQUIVALENT ::_stricmp
#define ACE_STRNCASECMP_EQUIVALENT ::_strnicmp
#define ACE_WCSDUP_EQUIVALENT ::_wcsdup
#define ACE_HAS_EXCEPTIONS
// Windows Mobile 5 doesn't do sig_atomic_t, but maybe future versions will.
#  if !defined (_WIN32_WCE) || (_WIN32_WCE > 0x501)
#    define ACE_HAS_SIG_ATOMIC_T
#  endif /* !Win CE 5.0 or less */
#define ACE_HAS_STRERROR
#define ACE_LACKS_STRPTIME
// Evaluate this with a WinCE build; maybe things have improved since VC8.
//#if !defined (ACE_HAS_WINCE)
# define ACE_HAS_INTRIN_H
# define ACE_HAS_INTRINSIC_INTERLOCKED
//#endif
#if !defined (_WIN32_WCE) || (_WIN32_WCE >= 0x501)
#  define ACE_HAS_INTRINSIC_BYTESWAP
#endif
#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES
#define ACE_LACKS_STRRECVFD
#define ACE_HAS_CPLUSPLUS_HEADERS
#define ACE_HAS_TEMPLATE_TYPEDEFS
#define ACE_TEMPLATES_REQUIRE_SOURCE
// Platform provides ACE_TLI function prototypes.
// For Win32, this is not really true, but saves a lot of hassle!
#define ACE_HAS_TLI_PROTOTYPES
// Platform support linebuffered streaming is broken
#define ACE_LACKS_LINEBUFFERED_STREAMBUF
#if defined (ACE_HAS_STANDARD_CPP_LIBRARY) && (ACE_HAS_STANDARD_CPP_LIBRARY != 0)
// Platform has its Standard C++ library in the namespace std
# if !defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
# define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB       1
# endif /* ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB */
// ace/iostream.h does not work with the standard cpp library (yet).
# if !defined (ACE_USES_OLD_IOSTREAMS)
# define ACE_LACKS_ACE_IOSTREAM
# endif /* ! ACE_USES_OLD_IOSTREAMS */
// Starting with MSVC 7.1, std::new throws std::bad_alloc on out-of-memory.
#define ACE_NEW_THROWS_EXCEPTIONS
#define ACE_HAS_NEW_NOTHROW
#else
// iostream header lacks ipfx (), isfx (), etc., declarations
#  define ACE_LACKS_IOSTREAM_FX
#endif
// There are too many instances of this warning to fix it right now.
// Maybe in the future.
// Disable warning of using Microsoft Extension.
# pragma warning(disable:4231)
// 'class1' : inherits 'class2::member' via dominance
#pragma warning(disable:4250)
// CE (at least thru Windows Mobile 5) doesn't have the new, secure CRT.
#if !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_TR24731_2005_CRT)
#  define ACE_HAS_TR24731_2005_CRT
#endif
// On CE w/o MFC config-WinCE.h needs to declare a placement new. This
// triggers a warning that there's no placement delete, which can be ignored.
#if defined (ACE_HAS_WINCE) && !defined (ACE_HAS_MFC)
#  pragma warning(disable:4291)
#endif
// A template can not be exported. Only an instantiation may be exported.
#define ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
// At least for ACE_UNIMPLEMENTED_FUNC in class templates, this is needed to
// explicitly instantiate a template that has ACE_UNIMPLEMENTED_FUNC.
# define ACE_NEEDS_FUNC_DEFINITIONS
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_MSVC_9_H */

