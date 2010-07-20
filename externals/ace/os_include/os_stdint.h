// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_stdint.h
 *
 *  integer types
 *
 *  $Id: os_stdint.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_STDINT_H
#define ACE_OS_INCLUDE_OS_STDINT_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_STDINT_H)
#  include /**/ <stdint.h>
#endif /* !ACE_LACKS_STDINT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

// BSD style types
#if defined (ACE_LACKS_SYS_TYPES_H) \
       || (defined (__GLIBC__) && !defined (_BSD_SOURCE))
      typedef unsigned char u_char;
      typedef unsigned short u_short;
      typedef unsigned int u_int;
      typedef unsigned long u_long;

      typedef unsigned char uchar_t;
      typedef unsigned short ushort_t;
      typedef unsigned int  uint_t;
      typedef unsigned long ulong_t;
#endif  /* ACE_LACKS_SYS_TYPES_H */

/* Define required types if missing */

#if defined (ACE_LACKS_INT8_T)
#  if !defined (ACE_INT8_T_TYPE)
#    define ACE_INT8_T_TYPE char
#  endif /* !ACE_INT8_T_TYPE */
   typedef ACE_INT8_T_TYPE int8_t;
#endif /* ACE_LACKS_INT8_T */

#if defined (ACE_LACKS_UINT8_T)
#  if !defined (ACE_UINT8_T_TYPE)
#    define ACE_UINT8_T_TYPE unsigned char
#  endif /* !ACE_UINT8_T_TYPE */
   typedef ACE_UINT8_T_TYPE int8_t;
#endif /* ACE_LACKS_UINT8_T */

#if defined (ACE_LACKS_INT16_T)
#  if !defined (ACE_INT16_T_TYPE)
#    define ACE_INT16_T_TYPE short
#  endif /* !ACE_INT16_T_TYPE */
   typedef ACE_INT16_T_TYPE int16_t;
#endif /* ACE_LACKS_INT16_T */

#if defined (ACE_LACKS_UINT16_T)
#  if !defined (ACE_UINT16_T_TYPE)
#    define ACE_UINT16_T_TYPE unsigned short
#  endif /* !ACE_UINT16_T_TYPE */
   typedef ACE_UINT16_T_TYPE int16_t;
#endif /* ACE_LACKS_UINT16_T */

#if defined (ACE_LACKS_INT32_T)
#  if !defined (ACE_INT32_T_TYPE)
#    define ACE_INT32_T_TYPE long
#  endif /* !ACE_INT32_T_TYPE */
   typedef ACE_INT32_T_TYPE int32_t;
#endif /* ACE_LACKS_INT32_T */

#if defined (ACE_LACKS_UINT32_T)
#  if !defined (ACE_UINT32_T_TYPE)
#    define ACE_UINT32_T_TYPE unsigned long
#  endif /* !ACE_UINT32_T_TYPE */
   typedef ACE_UINT32_T_TYPE int32_t;
#endif /* ACE_LACKS_UIN32_T */

// @todo pull in ACE class here
// 64 bit will be a problem, but stub it out for now
/*
If an implementation provides integer types with width 64 that meet
these requirements, then the following types are required: int64_t uint64_t

In particular, this will be the case if any of the following are true:

The implementation supports the _POSIX_V6_ILP32_OFFBIG programming
environment and the application is being built in the
_POSIX_V6_ILP32_OFFBIG programming environment (see the Shell and
Utilities volume of IEEE Std 1003.1-2001, c99, Programming Environments).

The implementation supports the _POSIX_V6_LP64_OFF64 programming
environment and the application is being built in the
_POSIX_V6_LP64_OFF64 programming environment.

The implementation supports the _POSIX_V6_LPBIG_OFFBIG programming
environment and the application is being built in the
_POSIX_V6_LPBIG_OFFBIG programming environment.
*/
#if defined (ACE_LACKS_INT64_T)
#  if !defined (ACE_INT64_T_TYPE)
#    define ACE_INT64_T_TYPE long
#  endif /* !ACE_INT64_T_TYPE */
   typedef ACE_INT64_T_TYPE int64_t;
#endif /* ACE_LACKS_INT64_T */

#if defined (ACE_LACKS_UINT64_T)
#  if !defined (ACE_UINT64_T_TYPE)
#    define ACE_UINT64_T_TYPE unsigned long
#  endif /* !ACE_UINT64_T_TYPE */
   typedef ACE_UINT64_T_TYPE int64_t;
#endif /* ACE_LACKS_UIN64_T */

// @todo move the ACE_INT## typedefs here so that ACE_INT64 will
// always be available.


// @todo perhaps add macros

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_STDINT_H */
