// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_mman.h
 *
 *  $Id: OS_NS_sys_mman.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_MMAN_H
# define ACE_OS_NS_SYS_MMAN_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"
#include "ace/os_include/sys/os_types.h"
#include "ace/os_include/sys/os_mman.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{

  //@{ @name A set of wrappers for memory mapped files.
  ACE_NAMESPACE_INLINE_FUNCTION
  int madvise (caddr_t addr,
               size_t len,
               int map_advice);

  ACE_NAMESPACE_INLINE_FUNCTION
  void *mmap (void *addr,
              size_t len,
              int prot,
              int flags,
              ACE_HANDLE handle,
              ACE_OFF_T off = 0,
              ACE_HANDLE *file_mapping = 0,
              LPSECURITY_ATTRIBUTES sa = 0,
              const ACE_TCHAR *file_mapping_name = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  int mprotect (void *addr,
                size_t len,
                int prot);

  ACE_NAMESPACE_INLINE_FUNCTION
  int msync (void *addr,
             size_t len,
             int sync);

  ACE_NAMESPACE_INLINE_FUNCTION
  int munmap (void *addr,
              size_t len);
  //@}

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE shm_open (const ACE_TCHAR *filename,
                       int mode,
                       mode_t perms = 0,
                       LPSECURITY_ATTRIBUTES sa = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  int shm_unlink (const ACE_TCHAR *path);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_mman.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_MMAN_H */

