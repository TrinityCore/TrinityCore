// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_mman.h
 *
 *  memory management declarations
 *
 *  $Id: os_mman.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_SYS_OS_MMAN_H
#define ACE_OS_INCLUDE_SYS_OS_MMAN_H
#include /**/ "ace/pre.h"
#include "ace/config-lite.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/sys/os_types.h"
#if defined (ACE_LACKS_MMAP)
#  define ACE_LACKS_SYS_MMAN_H
#endif /* ACE_LACKS_MMAP */
#if !defined (ACE_LACKS_SYS_MMAN_H)
   // Fixes a problem with HP/UX.
#  if defined (ACE_HAS_BROKEN_MMAP_H)
     extern "C" {
#  endif /* ACE_HAS_BROKEN_MMAP_H */
#  include /**/ <sys/mman.h>
#  if defined (ACE_HAS_BROKEN_MMAP_H)
     }
#  endif /* ACE_HAS_BROKEN_MMAP_H */
#endif /* ACE_LACKS_SYS_MMAN_H */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#if defined (ACE_LACKS_SYS_MMAN_H) && !defined (ACE_WIN32)
#  define PROT_READ 0
#  define PROT_WRITE 0
#  define PROT_EXEC 0
#  define PROT_NONE 0
#  define PROT_RDWR 0
#  define MAP_PRIVATE 0
#  define MAP_SHARED 0
#  define MAP_FIXED 0
#elif defined (ACE_WIN32)
   // These two may be used for internal flags soon:
#  define MAP_PRIVATE 1
#  define MAP_SHARED  2
#  define MAP_FIXED   4
   // MMAP flags
#  define PROT_READ PAGE_READONLY
#  define PROT_WRITE PAGE_READWRITE
#  define PROT_RDWR PAGE_READWRITE
/* If we can find suitable use for these flags, here they are:
PAGE_WRITECOPY
PAGE_EXECUTE
PAGE_EXECUTE_READ
PAGE_EXECUTE_READWRITE
PAGE_EXECUTE_WRITECOPY
PAGE_GUARD
PAGE_NOACCESS
PAGE_NOCACHE  */
#endif /* !ACE_LACKS_SYS_MMAN_H && !ACE_WIN32*/
# if !defined (ACE_MAP_PRIVATE)
#   define ACE_MAP_PRIVATE MAP_PRIVATE
# endif /* ! ACE_MAP_PRIVATE */
# if !defined (ACE_MAP_SHARED)
#   define ACE_MAP_SHARED MAP_SHARED
# endif /* ! ACE_MAP_SHARED */
# if !defined (ACE_MAP_FIXED)
#   define ACE_MAP_FIXED MAP_FIXED
# endif /* ! ACE_MAP_FIXED */
# if !defined (MAP_FAILED) || defined (ACE_HAS_BROKEN_MAP_FAILED)
#   undef MAP_FAILED
#   define MAP_FAILED ((void *) -1)
# elif defined (ACE_HAS_LONG_MAP_FAILED)
#   undef MAP_FAILED
#   define MAP_FAILED ((void *) -1L)
# endif /* !MAP_FAILED || ACE_HAS_BROKEN_MAP_FAILED */
#if !defined (PROT_RDWR)
#  define PROT_RDWR (PROT_READ|PROT_WRITE)
#endif /* PROT_RDWR */
# if defined (ACE_WIN32)
    // Needed to map calls to NT transparently.
#   define MS_ASYNC 0
#   define MS_INVALIDATE 0
# endif /* ACE_WIN32 */
# if !defined (MS_SYNC)
#   define MS_SYNC 0x0
# endif /* !MS_SYNC */
#if !defined (ACE_LACKS_MADVISE) && defined (ACE_LACKS_MADVISE_PROTOTYPE)
  extern "C" int madvise(caddr_t, size_t, int);
#endif /* !ACE_LACKS_MADVISE && ACE_LACKS_MADVISE_PROTOTYPE */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_MMAN_H */

