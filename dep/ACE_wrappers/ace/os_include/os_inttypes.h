// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_inttypes.h
 *
 *  fixed size integer types
 *
 *  $Id: os_inttypes.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_OS_INTTYPES_H
#define ACE_OS_INCLUDE_OS_INTTYPES_H
#include /**/ "ace/pre.h"
#include "ace/config-lite.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/os_stdint.h"
#if !defined (ACE_LACKS_INTTYPES_H)
# include /**/ <inttypes.h>
#endif /* !ACE_LACKS_INTTYPES_H */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
// @todo if needbe, we can define the macros if they aren't available.
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_INTTYPES_H */

