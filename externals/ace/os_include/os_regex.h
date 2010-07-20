// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_regex.h
 *
 *  regular expression matching types
 *
 *  $Id: os_regex.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_REGEX_H
#define ACE_OS_INCLUDE_OS_REGEX_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_REGEX_H)
# include /**/ <regex.h>
#endif /* !ACE_LACKS_REGEX_H */

#if defined (ACE_HAS_REGEX)
#  include /**/ <regexpr.h>
#endif /* ACE_HAS_REGEX */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_REGEX_H */
