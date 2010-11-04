// -*- C++ -*-
// $Id: config-qnx-rtp-common.h 92120 2010-10-01 12:00:01Z johnnyw $
// several macros common to various qnx neutrino version.

#ifndef ACE_CONFIG_QNX_RTP_COMMON_H
#define ACE_CONFIG_QNX_RTP_COMMON_H
#include /**/ "ace/pre.h"

#define _POSIX_C_SOURCE 199506
#define _QNX_SOURCE

// These constants are in i386-nto/include/limits.h, but egcs
// picks up its own limits.h instead:
#define _POSIX_NAME_MAX     14      /*  Max bytes in a filename             */
#define _POSIX_PATH_MAX     256     /*  Num. bytes in pathname (excl. NULL) */

#if defined(__OPTIMIZE__)
# if defined(__X86__)
    // string.h can't be used by ACE with __OPTIMIZE__.
#   undef __OPTIMIZE__
#   include <string.h>
#   define __OPTIMIZE__
# endif /* __X86__ */
#endif /* __OPTIMIZE__ */

// The following defines the Neutrino compiler.
// gcc should know to call g++ as necessary
#ifdef __GNUC__
# define ACE_CC_NAME ACE_TEXT ("gcc")
#else
# define ACE_CC_NAME ACE_TEXT ("QNX-RTP compiler ??")
#endif

#include "ace/config-g++-common.h"

// /usr/nto/include/float.h defines
//  FLT_MAX_EXP 127
//  DBL_MAX_EXP 1023
//  ace expects 128 & 1024 respectively
//  to set the following macros in ace/Basic_Types.h
//  These macros are:
#define ACE_SIZEOF_DOUBLE   8
#define ACE_SIZEOF_FLOAT    4

// At least qnx 6.3.2 uses a void return for unsetenv
// This assumes that older versions do too.
#define ACE_HAS_VOID_UNSETENV

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_QNX_RTP_COMMON_H */
