// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_pstat.h
 *
 *  pstat functions
 *
 *  $Id: os_pstat.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_PSTAT_H
#define ACE_OS_INCLUDE_SYS_OS_PSTAT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_SYS_PSTAT_H)
#  include /**/ <sys/param.h>
#  include /**/ <sys/pstat.h>
#endif /* ACE_HAS_SYS_PSTAT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_PSTAT_H */
