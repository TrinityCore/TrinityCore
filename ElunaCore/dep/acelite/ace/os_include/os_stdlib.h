// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_stdlib.h
 *
 *  standard library definitions
 *
 *  $Id: os_stdlib.h 93573 2011-03-17 07:53:03Z olli $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_STDLIB_H
#define ACE_OS_INCLUDE_OS_STDLIB_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stddef.h"
#include "ace/os_include/sys/os_wait.h"

#if defined (ACE_HAS_ALLOCA_H)
#   include /**/ <alloca.h>
#endif /* ACE_HAS_ALLOCA_H */

#if !defined (ACE_LACKS_STDLIB_H)
#  include /**/ <stdlib.h>
#endif /* !ACE_LACKS_STDLIB_H */

#if defined (ACE_VXWORKS) && !defined (__RTP__)
#  include /**/ <envLib.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_PUTENV_PROTOTYPE)
  int putenv (char *);
#endif /* ACE_LACKS_PUTENV_PROTOTYPE */

#if defined (ACE_LACKS_MKTEMP_PROTOTYPE)
  char *mktemp (char *);
#endif /* ACE_LACKS_MKTEMP_PROTOTYPE */

#if defined (ACE_LACKS_MKSTEMP_PROTOTYPE)
  int mkstemp (char *);
#endif /* ACE_LACKS_MKSTEMP_PROTOTYPE */

#if defined (ACE_LACKS_STRTOLL_PROTOTYPE)
  long long strtoll (const char *, char **, int);
#endif /* ACE_LACKS_STRTOLL_PROTOTYPE */

#if defined (ACE_LACKS_STRTOULL_PROTOTYPE)
  unsigned long long strtoull (const char *, char **, int);
#endif /* ACE_LACKS_STRTOULL_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_STDLIB_H */
