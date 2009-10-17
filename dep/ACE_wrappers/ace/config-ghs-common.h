/* -*- C++ -*- */
// $Id: config-ghs-common.h 80826 2008-03-04 14:51:23Z wotte $
// This configuration file is designed to be included by another,
// specific configuration file.  It provides config information common
// to all Green Hills platforms.
#ifndef ACE_GHS_COMMON_H
#define ACE_GHS_COMMON_H
#include /**/ "ace/pre.h"
#if !defined (ACE_CONFIG_INCLUDE_GHS_COMMON)
# error ace/config-ghs-common.h: ACE configuration error!  Do not #include this file directly!
#endif
#if defined (ghs)
# if defined (sun)
    // Need nonstatic Object_Manager on Solaris to prevent seg fault
    // on startup.
#   define ACE_HAS_NONSTATIC_OBJECT_MANAGER
# endif /* sun */
# if defined (__STANDARD_CXX)
    // Green Hills 1.8.9, but not 1.8.8.
#   define ACE_HAS_STANDARD_CPP_LIBRARY 1
#   define ACE_LACKS_AUTO_PTR
#   define ACE_LACKS_CHAR_RIGHT_SHIFTS
#   define ACE_LACKS_UNBUFFERED_STREAMBUF
# else
#   define ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA
# endif /* __STANDARD_CXX */
# define ACE_LACKS_LINEBUFFERED_STREAMBUF
# define ACE_LACKS_LONGLONG_T
# define ACE_LACKS_SIGNED_CHAR
#else  /* ! ghs */
# error ace/config-ghs-common.h can only be used with Green Hills compilers!
#endif /* ! ghs */
#include /**/ "ace/post.h"
#endif /* ACE_GHS_COMMON_H */

