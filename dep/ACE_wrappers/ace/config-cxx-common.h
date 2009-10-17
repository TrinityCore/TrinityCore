// -*- C++ -*-
//
// $Id: config-cxx-common.h 81935 2008-06-12 22:01:53Z jtc $

#ifndef ACE_CXX_COMMON_H
#define ACE_CXX_COMMON_H
#include /**/ "ace/pre.h"

#if !defined (ACE_CONFIG_INCLUDE_CXX_COMMON)
# error ace/config-cxx-common.h: ACE configuration error!  Do not #include this file directly!
#endif

#if defined (__DECCXX)
# if !defined (linux)
#   define ACE_HAS_STRING_CLASS
#   if (__DECCXX_VER >= 60090010)
#     define ACE_HAS_STDCPP_STL_INCLUDES
#   endif /* __DECCXX_VER < 60090010 */
# endif /* ! linux */

# define DEC_CXX
# define ACE_HAS_WORKING_EXPLICIT_TEMPLATE_DESTRUCTOR
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_SIGNED_CHAR
# define ACE_HAS_CPLUSPLUS_HEADERS
# define ACE_TEMPLATES_REQUIRE_SOURCE
# if (__DECCXX_VER >= 60090010)
    // DEC CXX 6.0 supports exceptions, etc., by default.  Exceptions
    // are enabled by platform_osf1_4.x.GNU/wrapper_macros.GNU.
#   if defined (ACE_HAS_EXCEPTIONS)
#     define ACE_NEW_THROWS_EXCEPTIONS
#   endif /* ACE_HAS_EXCEPTIONS */
#   define ACE_HAS_STANDARD_CPP_LIBRARY 1
#   define ACE_HAS_TEMPLATE_TYPEDEFS

#   define ACE_ENDLESS_LOOP \
      unsigned int ace_endless_loop____ = 0; if (ace_endless_loop____) break;

#   if defined (__USE_STD_IOSTREAM)
#     define ACE_LACKS_CHAR_RIGHT_SHIFTS
#     define ACE_LACKS_IOSTREAM_FX
#     define ACE_LACKS_UNBUFFERED_STREAMBUF
#     define ACE_USES_STD_NAMESPACE_FOR_STDCPP_LIB 1
#   else  /* ! __USE_STD_IOSTREAM */
#     define ACE_USES_OLD_IOSTREAMS
#   endif /* ! __USE_STD_IOSTREAM */

//    9: nested comment not allowed.  (/usr/include/pdsc.h!) (nestcomment)
//  177: variable was declared but never referenced (declbutnotref)
//  193: zero used for undefined preprocessing identifier (undpreid)
//  236: controlling expression is constant (boolexprconst)
//  401: base_class_with_nonvirtual_dtor (basclsnondto)
// 1016: expected type is incompatible with declared type of int (incint)
// 1136: conversion to smaller size integer could lose data (intconlosbit)

#   pragma message disable basclsnondto
#   pragma message disable boolexprconst
#   pragma message disable undpreid
#   pragma message disable notusetmpfunprm
#   pragma message disable bltinclnk

#   if (__DECCXX_VER >= 60190029)
      // 6.1-029 and later support msg 1136.  Disable it because it
      // causes warnings from ACE and/or TAO.
#     pragma message disable intconlosbit
#   endif /* __DECCXX_VER >= 60190029 */

# if (__DECCXX_VER == 60190027)
      // Seems that this version of cxx doesn't have reset
#     define ACE_AUTO_PTR_LACKS_RESET
#   endif /* __DECCXX_VER == 60190027 */

#   if defined (DIGITAL_UNIX)  &&  DIGITAL_UNIX >= 0x40D
      // variable "PTHREAD_THIS_CATCH_NP" was declared but never referenced
#     pragma message disable declbutnotref
#   endif /* DIGITAL_UNIX >= 4.0f */

# else  /* __DECCXX_VER < 60090010 */
#   define ACE_LACKS_PRAGMA_ONCE
# endif /* __DECCXX_VER < 60090010 */
#else  /* ! __DECCXX */
# error ace/config-cxx-common.h can only be used with Compaq CXX!
#endif /* ! __DECCXX */

#include /**/ "ace/post.h"
#endif /* ACE_CXX_COMMON_H */

