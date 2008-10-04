// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_timeb.h
 *
 *  additional definitions for date and time
 *
 *  $Id: os_timeb.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_TIMEB_H
#define ACE_OS_INCLUDE_SYS_OS_TIMEB_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_SYS_TIMEB_H)
#  include /**/ <sys/timeb.h>
#endif /* !ACE_LACKS_SYS_TIMEB_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (__BORLANDC__) && (__BORLANDC__ <= 0x560)
#  define _ftime ftime
#  define _timeb timeb
#endif /* __BORLANDC__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_TIMEB_H */
