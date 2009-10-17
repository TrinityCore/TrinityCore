// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_kstat.h
 *
 *  $Id: os_kstat.h 81692 2008-05-14 12:25:02Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_KSTAT_H
#define ACE_OS_INCLUDE_OS_KSTAT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_KSTAT)
# define ACE_HAS_KSTAT_H
#endif /* ACE_HAS_KSTAT */

#if defined (ACE_HAS_KSTAT_H)
# include <kstat.h>
#endif /* ACE_HAS_KSTAT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_KSTAT_H */

