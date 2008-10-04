// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_sched.h
 *
 *  execution scheduling (REALTIME)
 *
 *  $Id: os_sched.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_SCHED_H
#define ACE_OS_INCLUDE_OS_SCHED_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_time.h"

#if !defined (ACE_LACKS_SCHED_H)
# include /**/ <sched.h>
#endif /* !ACE_LACKS_SCHED_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if !defined (__cpu_set_t_defined) || !defined (ACE_HAS_CPU_SET_T)
#  define ACE_CPU_SETSIZE 1024
   typedef struct
   {
     ACE_UINT32 bit_array_[ACE_CPU_SETSIZE / (8 * sizeof (ACE_UINT32))];
   } cpu_set_t;
#endif /* !ACE_HAS_CPU_SET_T || !__cpu_set_t_defined */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_SCHED_H */
