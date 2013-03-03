// -*- C++ -*-

//=============================================================================
/**
 *  @file os_time.h
 *
 *  time types
 *
 *  $Id: os_time.h 96090 2012-08-22 06:13:38Z johnnyw $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_TIME_H
#define ACE_OS_INCLUDE_SYS_OS_TIME_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_SYS_TIME_H)
#  include /**/ <sys/time.h>
#endif /* !ACE_LACKS_SYS_TIME_H */

#if defined (ACE_LACKS_CLOCK_REALTIME)
#  define CLOCK_REALTIME 0
#endif /* ACE_LACKS_CLOCK_REALTIME */

#if defined (ACE_LACKS_CLOCK_MONOTONIC)
#  define CLOCK_MONOTONIC 1
#endif /* ACE_LACKS_CLOCK_MONOTONIC */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_HAS_SVR4_GETTIMEOFDAY)
  int gettimeofday (struct timeval *tp, void * = 0);
#elif defined (ACE_HAS_OSF1_GETTIMEOFDAY)
  int gettimeofday (struct timeval *tp, struct timezone * = 0);
#elif defined (ACE_HAS_VOIDPTR_GETTIMEOFDAY)
# define ACE_HAS_SVR4_GETTIMEOFDAY
#endif /* ACE_HAS_SVR4_GETTIMEOFDAY */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_TIME_H */
