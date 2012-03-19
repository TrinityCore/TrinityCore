// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_shm.h
 *
 *  $Id: OS_NS_sys_shm.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_SHM_H
# define ACE_OS_NS_SYS_SHM_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_shm.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{

  //@{ @name A set of wrappers for System V shared memory.
  ACE_NAMESPACE_INLINE_FUNCTION
  void *shmat (int int_id,
               const void *shmaddr,
               int shmflg);

  ACE_NAMESPACE_INLINE_FUNCTION
  int shmctl (int int_id,
              int cmd,
              struct shmid_ds *buf);

  ACE_NAMESPACE_INLINE_FUNCTION
  int shmdt (const void *shmaddr);

  ACE_NAMESPACE_INLINE_FUNCTION
  int shmget (key_t key,
              size_t size,
              int flags);
  ///@}

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_shm.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_SHM_H */
