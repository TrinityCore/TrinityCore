// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_glob.h
 *
 *  pathname pattern-matching types
 *
 *  $Id: os_glob.h 81692 2008-05-14 12:25:02Z johnnyw $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_GLOB_H
#define ACE_OS_INCLUDE_OS_GLOB_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_GLOB_H)
# include /**/ <glob.h>
#endif /* !ACE_LACKS_GLOB_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_GLOB_H */

