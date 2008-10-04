/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   config-win32-msvc-7.h
 *
 *  $Id: config-win32-msvc-7.h 81935 2008-06-12 22:01:53Z jtc $
 *
 *  @brief  Microsoft Visual C++ 7.0 configuration file.
 *
 *  This file is the ACE configuration file for Microsoft Visual C++ version 7.
 *
 *  @note Do not include this file directly, include config-win32.h instead.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CONFIG_WIN32_MSVC_7_H
#define ACE_CONFIG_WIN32_MSVC_7_H
#include /**/ "ace/pre.h"

#ifndef ACE_CONFIG_WIN32_H
#error Use config-win32.h in config.h instead of this header
#endif /* ACE_CONFIG_WIN32_H */

// Visual C++ 7.0 (.NET) deprecated the old iostreams
#if !defined (ACE_HAS_STANDARD_CPP_LIBRARY)
#define ACE_HAS_STANDARD_CPP_LIBRARY 1
#endif

#if !defined (ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB)
#define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#endif

// Win64 SDK compiler claims std::auto_ptr<>::reset not available.
#if defined (_WIN64) || defined (WIN64)
#define ACE_AUTO_PTR_LACKS_RESET
#endif

#define ACE_HAS_ITOA
#define ACE_HAS_HEADER_ALLOCATED_CLASS_STATIC_CONST_INT_STOREAGE
#define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR

#define ACE_ITOA_EQUIVALENT ::_itoa
#define ACE_STRCASECMP_EQUIVALENT ::_stricmp
#define ACE_STRNCASECMP_EQUIVALENT ::_strnicmp
#define ACE_WCSDUP_EQUIVALENT ::_wcsdup

#if !defined (ACE_HAS_WINCE) && !defined (ACE_HAS_EXCEPTIONS)
#define ACE_HAS_EXCEPTIONS
#endif /* ACE_HAS_WINCE */

#define ACE_HAS_STRERROR
#define ACE_LACKS_STRPTIME

#define ACE_HAS_SIG_ATOMIC_T
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

#if !defined (ACE_HAS_WINCE) && !(defined (__INTEL_COMPILER) && (__INTEL_COMPILER == 900))
# define ACE_HAS_INTRINSIC_INTERLOCKED
# define ACE_HAS_INTRINSIC_BYTESWAP
#endif

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
// Since we don't support MSVC 7.0, don't test for it.
# define ACE_NEW_THROWS_EXCEPTIONS
# define ACE_HAS_NEW_NOTHROW

#else

// iostream header lacks ipfx (), isfx (), etc., declarations
#  define ACE_LACKS_IOSTREAM_FX

#endif

// There are too many instances of this warning to fix it right now.
// Maybe in the future.
// 'this' : used in base member initializer list
#pragma warning(disable:4355)

// 'class1' : inherits 'class2::member' via dominance
#pragma warning(disable:4250)

// C++ Exception Specification ignored
#pragma warning(disable:4290)

// Disable warning of using Microsoft Extension.
#pragma warning(disable:4231)

// 'function' : unreferenced local function has been removed
# pragma warning(disable:4505)

// A template can not be exported. Only an instantiation may be exported.
#define ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT

// At least for ACE_UNIMPLEMENTED_FUNC in class templates, this is needed to
// explicitly instantiate a template that has ACE_UNIMPLEMENTED_FUNC.
# define ACE_NEEDS_FUNC_DEFINITIONS

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_MSVC_7_H */
