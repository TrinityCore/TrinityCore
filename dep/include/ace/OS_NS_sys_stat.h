// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_stat.h
 *
 *  $Id: OS_NS_sys_stat.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_STAT_H
# define ACE_OS_NS_SYS_STAT_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_stat.h"
#include "ace/Default_Constants.h" // for ACE_DEFAULT_DIR_PERMS
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

# if defined (_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64  \
     && defined (ACE_WIN32)
#   if defined (__BORLANDC__)
typedef struct stati64 ACE_stat;
#       define ACE_STAT_FUNC_NAME ::_stati64
#       define ACE_WSTAT_FUNC_NAME ::_wstati64
#   elif !defined (ACE_HAS_WINCE) && defined (_MSC_VER)
#     if _MSC_VER >= 1400
//      For vc8 which has time_t as 64bit
//      64-bit file offsets, 64-bit time_t
#       if defined (ACE_MSVC_USES_DOUBLE_UNDERSCORE_STAT64)
typedef struct __stat64 ACE_stat;
#       else
typedef struct _stat64 ACE_stat;
#       endif
#       define ACE_STAT_FUNC_NAME ::_stat64
#       define ACE_WSTAT_FUNC_NAME ::_wstat64
#     else
//      For vc71 which has time_t as 32bit
typedef struct _stati64 ACE_stat;
#       define ACE_STAT_FUNC_NAME ::_stati64
#       define ACE_WSTAT_FUNC_NAME ::_wstati64
#     endif  /* _MSC_VER >= 1400 */
#   else
typedef struct stat ACE_stat;
#     define ACE_STAT_FUNC_NAME ::stat
#     define ACE_WSTAT_FUNC_NAME ACE_STAT_FUNC_NAME
#   endif  /**/
# else
//  Default file offset case.
#   if defined (ACE_WIN32) && !defined (ACE_HAS_WINCE)
typedef struct _stat ACE_stat;
#     define ACE_STAT_FUNC_NAME ::_stat
#     define ACE_WSTAT_FUNC_NAME ::_wstat
#   else
typedef struct stat ACE_stat;
#     define ACE_STAT_FUNC_NAME ::stat
#     define ACE_WSTAT_FUNC_NAME ACE_STAT_FUNC_NAME
#   endif /* ACE_WIN32 */
# endif  /* _FILE_OFFSET_BITS == 64 && ACE_WIN32 */

namespace ACE_OS
{

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE creat (const ACE_TCHAR *filename,
                    mode_t mode);

  //@{ @name A set of wrappers for low-level file operations.

  // non-standard
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_OFF_T filesize (ACE_HANDLE handle);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_OFF_T filesize (const ACE_TCHAR *handle);
  //@}

  ACE_NAMESPACE_INLINE_FUNCTION
  int fstat (ACE_HANDLE,
             ACE_stat *);

  ACE_NAMESPACE_INLINE_FUNCTION
  int lstat (const char *,
             ACE_stat *);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int lstat (const wchar_t *,
             ACE_stat *);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  int mkdir (const char *path,
             mode_t mode = ACE_DEFAULT_DIR_PERMS);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int mkdir (const wchar_t *path,
             mode_t mode = ACE_DEFAULT_DIR_PERMS);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  int mkfifo (const ACE_TCHAR *file,
              mode_t mode = ACE_DEFAULT_FILE_PERMS);

  ACE_NAMESPACE_INLINE_FUNCTION
  int stat (const char *file, ACE_stat *);

#if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int stat (const wchar_t *file, ACE_stat *);
#endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  mode_t umask (mode_t cmask);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_stat.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_STAT_H */

