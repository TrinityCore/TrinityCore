// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_wchar.h
 *
 *  wide-character handling
 *
 *  $Id: os_wchar.h 83948 2008-12-02 13:55:34Z jtc $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_WCHAR_H
#define ACE_OS_INCLUDE_OS_WCHAR_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// ctype.h, string.h, stdarg.h, stdio.h, stdlib.h, time.h
#include "ace/os_include/os_stdio.h"
#include "ace/os_include/os_stdlib.h"
#include "ace/os_include/os_time.h"
#include "ace/os_include/os_string.h"
#include "ace/os_include/os_ctype.h"

#if !defined (ACE_LACKS_WCHAR_H)
#  include /**/ <wchar.h>
#endif /* !ACE_LACKS_WCHAR_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_WCSTOLL_PROTOTYPE)
  long long wcstoll (const wchar_t *, wchar_t **, int);
#endif /* ACE_LACKS_WCSTOLL_PROTOTYPE */

#if defined (ACE_LACKS_WCSTOULL_PROTOTYPE)
  unsigned long long wcstoull (const wchar_t *, wchar_t **, int);
#endif /* ACE_LACKS_WCSTOULL_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_WCHAR_H */
