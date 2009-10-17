// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_fcntl.h
 *
 *  file control options
 *
 *  $Id: os_fcntl.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_OS_FCNTL_H
#define ACE_OS_INCLUDE_OS_FCNTL_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/sys/os_stat.h"
#include "ace/os_include/sys/os_types.h"
#if !defined (ACE_LACKS_FCNTL_H)
# include /**/ <fcntl.h>
#endif /* !ACE_LACKS_FCNTL_H */
#if defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620)
// for creat(), open()
#  include /**/ <ioLib.h>
#endif /* ACE_VXWORKS */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#if defined (__BORLANDC__)
#  define _O_CREAT O_CREAT
#  define _O_EXCL  O_EXCL
#  define _O_TRUNC O_TRUNC
   // 0x0800 is used for O_APPEND.  0x08 looks free.
#  define _O_TEMPORARY 0x08 /* see fcntl.h */
#  define _O_RDWR   O_RDWR
#  define _O_WRONLY O_WRONLY
#  define _O_RDONLY O_RDONLY
#  define _O_APPEND O_APPEND
#  define _O_BINARY O_BINARY
#  define _O_TEXT   O_TEXT
#endif /* __BORLANDC__ */
#if defined (__DMC__)
#  define _O_TEMPORARY 0x08 /* see fcntl.h */
#endif /* __DMC__ */
// defined Win32 specific macros for UNIX platforms
#if !defined (O_BINARY)
#  define O_BINARY 0
#endif /* O_BINARY */
#if !defined (_O_BINARY)
#  define _O_BINARY O_BINARY
#endif /* _O_BINARY */
#if !defined (O_TEXT)
#  define O_TEXT 0
#endif /* O_TEXT */
#if !defined (_O_TEXT)
#  define _O_TEXT O_TEXT
#endif /* _O_TEXT */
#if !defined (O_RAW)
#  define O_RAW 0
#endif /* O_RAW */
#if !defined (_O_RAW)
#  define _O_RAW O_RAW
#endif /* _O_RAW */
#if defined (ACE_WIN32)
#  define O_NDELAY    1
#endif /* ACE_WIN32 */
# if !defined (O_NONBLOCK)
#   define O_NONBLOCK  1
# endif /* O_NONBLOCK  */
#if defined (ACE_HAS_POSIX_NONBLOCK)
#  define ACE_NONBLOCK O_NONBLOCK
#else
#  define ACE_NONBLOCK O_NDELAY
#endif /* ACE_HAS_POSIX_NONBLOCK */
# if !defined (F_GETFL)
#   define F_GETFL 0
# endif /* F_GETFL */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_FCNTL_H */

