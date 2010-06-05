// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_wordexp.h
 *
 *  word-expansion types
 *
 *  $Id: os_wordexp.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_WORDEXP_H
#define ACE_OS_INCLUDE_OS_WORDEXP_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stddef.h" // size_t

#if !defined (ACE_LACKS_WORDEXP_H)
#  include /**/ <wordexp.h>
#endif /* !ACE_LACKS_WORDEXP_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_WORDEXP_H */

