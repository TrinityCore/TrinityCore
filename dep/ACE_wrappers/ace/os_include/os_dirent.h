// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_dirent.h
 *
 *  format of directory entries
 *
 *  $Id: os_dirent.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_DIRENT_H
#define ACE_OS_INCLUDE_OS_DIRENT_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/os_limits.h"

#if defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620)
#  include "ace/os_include/os_unistd.h"  // VxWorks needs this to compile
#endif /* ACE_VXWORKS */

#if !defined (ACE_LACKS_DIRENT_H)
# include /**/ <dirent.h>
#endif /* !ACE_LACKS_DIRENT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if !defined (MAXNAMLEN)
#  define MAXNAMLEN NAME_MAX
#endif /* !MAXNAMLEN */

// At least compile on some of the platforms without <ACE_DIR> info yet.
#if !defined (ACE_HAS_DIRENT)
typedef int ACE_DIR;
struct dirent {
};
#endif /* ACE_HAS_DIRENT */

#if defined (ACE_LACKS_STRUCT_DIR)
struct dirent {
  unsigned short d_ino;
  unsigned short d_off;
  unsigned short d_reclen;
  // This must be a ACE_TCHAR * and not a one element
  // ACE_TCHAR array.  It causes problems on wide
  // character builds with Visual C++ 6.0.
  ACE_TCHAR *d_name;
};

#define ACE_DIRENT dirent

struct ACE_DIR {
  /// The name of the directory we are looking into
  ACE_TCHAR *directory_name_;

  /// Remember the handle between calls.
  HANDLE current_handle_;

  /// The struct for the results
  ACE_DIRENT *dirent_;

  /// The struct for intermediate results.
  ACE_TEXT_WIN32_FIND_DATA fdata_;

  /// A flag to remember if we started reading already.
  int started_reading_;
};
#elif defined (ACE_WIN32) && (__BORLANDC__) && defined (ACE_USES_WCHAR)
#define ACE_DIRENT wdirent
typedef wDIR ACE_DIR;
#else
#define ACE_DIRENT dirent
typedef DIR ACE_DIR;
#endif /* ACE_LACKS_STRUCT_DIR */

#if defined (ACE_LACKS_SCANDIR_PROTOTYPE)
int scandir (const char *,
             struct dirent ***,
             int (*) (const struct dirent *),
             int (*) (const void *, const void *));
#endif /* ACE_LACKS_SCANDIR_PROTOTYPE */

#if defined (ACE_LACKS_ALPHASORT_PROTOTYPE)
int alphasort (const void *, const void *);
#endif /* ACE_LACKS_ALPHASORT_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_DIRENT_H */
