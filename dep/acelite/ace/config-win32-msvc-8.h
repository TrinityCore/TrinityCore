/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   config-win32-msvc-8.h
 *
 *  $Id: config-win32-msvc-8.h 91685 2010-09-09 09:35:14Z johnnyw $
 *
 *  @brief  Microsoft Visual C++ 8.0 configuration file.
 *
 *  This file is the ACE configuration file for Microsoft Visual C++ version 8.
 *
 *  @note Do not include this file directly, include config-win32.h instead.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CONFIG_WIN32_MSVC_8_H
#define ACE_CONFIG_WIN32_MSVC_8_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

#ifndef ACE_WIN32_VC8
#  define ACE_WIN32_VC8
#endif

// Visual C++ 8.0 (.NET) deprecated the old iostreams
#if !defined (ACE_HAS_STANDARD_CPP_LIBRARY)
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#endif

#if !defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#endif

// Windows' timeval is non-conformant (defined in terms of long instead of
// time_t) and VC8 (on desktop, not CE) changed time_t to a 64-bit value
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
#if defined (ACE_HAS_WINCE)
# define ACE_FILENO_EQUIVALENT ::_fileno
#else
# define ACE_FILENO_EQUIVALENT(X) (_get_osfhandle (::_fileno (X)))
#endif

// Windows Mobile 6 doesn't do sig_atomic_t, but maybe future versions will.
// This has been true up thrugh the versions. We don't have any indication
// that this might be supported in the future, but it is an easy enough fix
// to bump the wince revision number when a new version is released.
#  if !defined (_WIN32_WCE) || (_WIN32_WCE > 0x601)
#    define ACE_HAS_SIG_ATOMIC_T
#  endif /* !Win CE 6.0 or less */

#define ACE_LACKS_STRPTIME

#if !defined (ACE_HAS_WINCE)
# define ACE_HAS_INTRIN_H
# define ACE_HAS_INTRINSIC_INTERLOCKED
#endif

#if !defined (_WIN32_WCE) || (_WIN32_WCE >= 0x501)
#  define ACE_HAS_INTRINSIC_BYTESWAP
#endif

#define ACE_LACKS_STATIC_DATA_MEMBER_TEMPLATES
#define ACE_LACKS_STRRECVFD
#define ACE_HAS_CPLUSPLUS_HEADERS

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
#pragma warning(disable:4231)

// 'class1' : inherits 'class2::member' via dominance
#pragma warning(disable:4250)

// 'this' : used in base member initializer list
#pragma warning(disable:4355)

// CE (at least thru Windows Mobile 5) doesn't have the new, secure CRT.
#if !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_TR24731_2005_CRT)
#  define ACE_HAS_TR24731_2005_CRT
#endif

//Detect Platform SDK 64-bit (AMD64) compiler using _MSC_FULL_VER
#if (defined (_WIN64) || defined (WIN64)) && _MSC_FULL_VER < 140050000
#  define ACE_AUTO_PTR_LACKS_RESET
#  define ACE_MSVC_USES_DOUBLE_UNDERSCORE_STAT64
#  define ACE_HAS_BROKEN_STD_REVERSE_ITERATOR
#  define ACE_LACKS_NUMERIC_LIMITS_64_BIT_TYPES
#  undef ACE_HAS_TR24731_2005_CRT
#  undef ACE_HAS_INTRIN_H
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
#endif /* ACE_CONFIG_WIN32_MSVC_8_H */
