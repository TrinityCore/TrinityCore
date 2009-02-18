// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_stat.h
 *
 *  data returned by the stat() function
 *
 *  $Id: os_stat.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_STAT_H
#define ACE_OS_INCLUDE_SYS_OS_STAT_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
#  include /**/ <direct.h>
#endif /* ACE_WIN32 && !ACE_HAS_WINCE */

#if !defined (ACE_LACKS_SYS_STAT_H)
#  include /**/ <sys/stat.h>
#endif /* !ACE_LACKS_SYS_STAT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_MODE_MASKS)
// MODE MASKS

// the following macros are for POSIX conformance.

#  if !defined (ACE_HAS_USER_MODE_MASKS)
#    define S_IRWXU 00700         /* read, write, execute: owner. */
#    define S_IRUSR 00400         /* read permission: owner. */
#    define S_IWUSR 00200         /* write permission: owner. */
#    define S_IXUSR 00100         /* execute permission: owner. */
#  endif /* ACE_HAS_USER_MODE_MASKS */
#  define S_IRWXG 00070           /* read, write, execute: group. */
#  define S_IRGRP 00040           /* read permission: group. */
#  define S_IWGRP 00020           /* write permission: group. */
#  define S_IXGRP 00010           /* execute permission: group. */
#  define S_IRWXO 00007           /* read, write, execute: other. */
#  define S_IROTH 00004           /* read permission: other. */
#  define S_IWOTH 00002           /* write permission: other. */
#  define S_IXOTH 00001           /* execute permission: other. */

// WinCE's S_IFLNK is defined with the other bits, below.
#if !defined (S_IFLNK) && !defined (ACE_HAS_WINCE)
#define S_IFLNK 0200000
#endif /* S_IFLNK && !ACE_HAS_WINCE */

#endif /* ACE_LACKS_MODE_MASKS */

// Some systems (VxWorks) don't define S_ISLNK
#if !defined (S_ISLNK)
# if defined (S_IFLNK)
#   define S_ISLNK(mode) (((mode)&S_IFLNK) == S_IFLNK)
# else
#   define S_ISLNK(mode) 0
# endif /* S_IFLNK */
#endif /* S_ISLNK */

#if defined (ACE_HAS_WINCE)
#  include "ace/Time_Value.h"

// Translate the WinCE bits into names expected by our callers.
// The dwFileAttributes parameter doesn't have protection info, so
// S_IFMT is the whole thing. Since there are no symbolic links, S_IFLNK is 0.
#  define S_IFMT 0xFFFF
#  define S_IFDIR FILE_ATTRIBUTE_DIRECTORY
#  define S_IFREG FILE_ATTRIBUTE_NORMAL
#  define S_IFLNK 0

   struct stat
   {
      /// always 0 on Windows platforms
      dev_t st_dev;

      /// always 0 on Windows platforms
      dev_t st_rdev;

      /// file attribute
      unsigned short st_mode;

      /// number of hard links
      short st_nlink;

      /// time of last access
      ACE_Time_Value st_atime;

      /// time of last data modification
      ACE_Time_Value st_mtime;

      /// time of creation
      ACE_Time_Value st_ctime;

      /// file size, in bytes
      ACE_OFF_T st_size;

      // Following members do not have direct conversion in Window platforms.
      //u_long st_blksize;        // optimal blocksize for I/O
      //u_long st_flags;          // user defined flags for file
   };
#endif /* ACE_HAS_WINCE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_STAT_H */

