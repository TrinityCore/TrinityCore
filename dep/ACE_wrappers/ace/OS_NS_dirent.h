// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_NS_dirent.h
 *
 *  $Id: OS_NS_dirent.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================
#ifndef ACE_OS_NS_DIRENT_H
# define ACE_OS_NS_DIRENT_H
# include /**/ "ace/pre.h"
# include "ace/config-all.h"
# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/os_dirent.h"
#include /**/ "ace/ACE_export.h"
#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export
// Define the scandir() selector and comparator function types. Many platforms
// define these in terms of const pointers to dirent arrays/structs. Some
// platforms use void pointers instead. The ACE-exported API is defined in
// terms of the dirent-using function types, and if the OS-native scandir()
// uses void*, that's handled internal to the ACE_OS::scandir() wrapper using
// the ACE_SCANDIR_OS_COMPARATOR.
extern "C" {
#if defined (ACE_SCANDIR_CMP_USES_VOIDPTR)
  typedef int (*ACE_SCANDIR_OS_COMPARATOR)(void *f1, void *f2);
#elif defined (ACE_SCANDIR_CMP_USES_CONST_VOIDPTR)
  typedef int (*ACE_SCANDIR_OS_COMPARATOR)(const void *f1, const void *f2);
#endif /* ACE_SCANDIR_CMP_USES_VOIDPTR */
  typedef int (*ACE_SCANDIR_COMPARATOR)(const ACE_DIRENT **f1,
                                        const ACE_DIRENT **f2);
#if defined (ACE_SCANDIR_SEL_LACKS_CONST)
  typedef int (*ACE_SCANDIR_OS_SELECTOR)(ACE_DIRENT *filename);
#endif /* ACE_SCANDIR_SEL_LACKS_CONST */
  typedef int (*ACE_SCANDIR_SELECTOR)(const ACE_DIRENT *filename);
}
/*
 * We inline and undef some functions that may be implemented
 * as macros on some platforms. This way macro definitions will
 * be usable later as there is no way to save the macro definition
 * using the pre-processor.
 *
 */
#if !defined (ACE_LACKS_REWINDDIR)
#  if !defined (ACE_HAS_WREWINDDIR) || !defined (ACE_USES_WCHAR)
inline void ace_rewinddir_helper (ACE_DIR *dir)
{
#    if defined (rewinddir)
   rewinddir (dir);
#    undef rewinddir
#    else
  ::rewinddir (dir);
#    endif /* defined (rewinddir) */
}
#  endif /* !defined (ACE_HAS_WREWINDDIR) && !defined (ACE_USES_WCHAR) */
#endif /* ACE_LACKS_REWINDDIR */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE_OS {
  ACE_NAMESPACE_INLINE_FUNCTION
  void closedir (ACE_DIR *);
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_DIR *opendir (const ACE_TCHAR *filename);
  ACE_NAMESPACE_INLINE_FUNCTION
  struct ACE_DIRENT *readdir (ACE_DIR *);
  ACE_NAMESPACE_INLINE_FUNCTION
  int readdir_r (ACE_DIR *dirp,
                 struct ACE_DIRENT *entry,
                 struct ACE_DIRENT **result);
  ACE_NAMESPACE_INLINE_FUNCTION
  void rewinddir (ACE_DIR *);
  ACE_NAMESPACE_INLINE_FUNCTION
  int scandir (const ACE_TCHAR *dirname,
               struct ACE_DIRENT **namelist[],
               ACE_SCANDIR_SELECTOR selector,
               ACE_SCANDIR_COMPARATOR comparator);
  ACE_NAMESPACE_INLINE_FUNCTION
  int alphasort (const void *, const void *);
  ACE_NAMESPACE_INLINE_FUNCTION
  void seekdir (ACE_DIR *,
                long loc);
  ACE_NAMESPACE_INLINE_FUNCTION
  long telldir (ACE_DIR *);
  // Win32 emulation functions
#if defined (ACE_LACKS_OPENDIR)
  extern ACE_Export
  ACE_DIR *opendir_emulation (const ACE_TCHAR *filename);
#endif /* ACE_LACKS_OPENDIR */
#if !defined (ACE_HAS_SCANDIR)
  extern ACE_Export
  int scandir_emulation (const ACE_TCHAR *dirname,
                         ACE_DIRENT **namelist[],
                         ACE_SCANDIR_SELECTOR selector,
                         ACE_SCANDIR_COMPARATOR comparator);
#endif /* !ACE_HAS_SCANDIR */
#if defined (ACE_LACKS_CLOSEDIR)
  extern ACE_Export
  void closedir_emulation (ACE_DIR *);
#endif /* ACE_LACKS_CLOSEDIR */
#if defined (ACE_LACKS_READDIR)
  extern ACE_Export
  struct ACE_DIRENT *readdir_emulation (ACE_DIR *);
#endif /* ACE_LACKS_READDIR */
} /* namespace ACE_OS */
ACE_END_VERSIONED_NAMESPACE_DECL
# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_dirent.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */
# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_DIRENT_H */

