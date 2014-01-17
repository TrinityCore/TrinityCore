// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_dlfcn.h
 *
 *  dynamic linking
 *
 *  $Id: os_dlfcn.h 94379 2011-08-09 17:18:49Z johnnyw $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_DLFCN_H
#define ACE_OS_INCLUDE_OS_DLFCN_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_DLFCN_H)
#  include /**/ <dlfcn.h>
#endif /* !ACE_LACKS_DLFCN_H */

#if defined (__hpux)
#  if defined(__GNUC__) || __cplusplus >= 199707L
#    include /**/ <dl.h>
#  else
#    include /**/ <cxxdl.h>
#  endif /* (g++ || HP aC++) vs. HP C++ */
#endif /* __hpux */

#if defined (ACE_VXWORKS) && !defined (__RTP__)
#  include /**/ <loadLib.h> /* for module load */
#  include /**/ <unldLib.h> /* for module unload */
#  include /**/ <symLib.h> /* for findSymbol  */
#  include /**/ <sysSymTbl.h> /* for global symbol table */
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/* Set the proper handle type for dynamically-loaded libraries. */
/* Also define a default 'mode' for loading a library - the names and values */
/* differ between OSes, so if you write code that uses the mode, be careful */
/* of the platform differences. */
#if defined (ACE_WIN32)
   // Dynamic loading-related types - used for dlopen and family.
   typedef HINSTANCE ACE_SHLIB_HANDLE;
#  if !defined (ACE_SHLIB_INVALID_HANDLE)
#    define ACE_SHLIB_INVALID_HANDLE 0
#  endif /* ACE_SHLIB_INVALID_HANDLE */
#  if !defined (ACE_DEFAULT_SHLIB_MODE)
#    define ACE_DEFAULT_SHLIB_MODE 0
#  endif /* ACE_DEFAULT_SHLIB_MODE */
#elif defined (ACE_HAS_SVR4_DYNAMIC_LINKING)
   typedef void *ACE_SHLIB_HANDLE;
#  if !defined (ACE_SHLIB_INVALID_HANDLE)
#    define ACE_SHLIB_INVALID_HANDLE 0
#  endif /* ACE_SHLIB_INVALID_HANDLE */
   // This is needed to for dynamic_cast to work properly on objects passed to
   // libraries.
#  if !defined (ACE_DEFAULT_SHLIB_MODE)
#    define ACE_DEFAULT_SHLIB_MODE RTLD_LAZY | RTLD_GLOBAL
#  endif
#elif defined (__hpux)
   typedef shl_t ACE_SHLIB_HANDLE;
#  if !defined (ACE_SHLIB_INVALID_HANDLE)
#    define ACE_SHLIB_INVALID_HANDLE 0
#  endif /* ACE_SHLIB_INVALID_HANDLE */
#  if !defined (ACE_DEFAULT_SHLIB_MODE)
#    define ACE_DEFAULT_SHLIB_MODE BIND_DEFERRED | DYNAMIC_PATH
#  endif /* ACE_DEFAULT_SHLIB_MODE */
#else /* !ACE_WIN32 && !ACE_HAS_SVR4_DYNAMIC_LINKING && !__hpux */
   typedef void *ACE_SHLIB_HANDLE;
#  if !defined (ACE_SHLIB_INVALID_HANDLE)
#    define ACE_SHLIB_INVALID_HANDLE 0
#  endif /* ACE_SHLIB_INVALID_HANDLE */
#  if !defined (ACE_DEFAULT_SHLIB_MODE)
#    define ACE_DEFAULT_SHLIB_MODE RTLD_LAZY
#  endif /* ACE_DEFAULT_SHLIB_MODE */
#endif /* ACE_WIN32 */

#if !defined (RTLD_LAZY)
#define RTLD_LAZY 1
#endif /* !RTLD_LAZY */

#if !defined (RTLD_NOW)
#define RTLD_NOW 2
#endif /* !RTLD_NOW */

#if !defined (RTLD_GLOBAL)
#define RTLD_GLOBAL 3
#endif /* !RTLD_GLOBAL */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_DLFCN_H */
