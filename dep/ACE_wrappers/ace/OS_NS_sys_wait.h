// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_sys_wait.h
 *
 *  $Id: OS_NS_sys_wait.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_SYS_WAIT_H
# define ACE_OS_NS_SYS_WAIT_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_wait.h"
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{

  /// Calls OS @c ::wait function, so it's only portable to UNIX/POSIX
  /// platforms.
  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t wait (int * = 0);

  /**
   * Calls @c ::WaitForSingleObject on Win32 and ACE::waitpid ()
   * otherwise.  Returns the passed in @a pid_t on success and -1 on
   * failure.
   * On Win32, @a pid is ignored if the @a handle is not equal to 0.
   * Passing the process @a handle is prefer on Win32 because using
   * @a pid to wait on the project doesn't always work correctly
   * if the waited process has already terminated.
   */
  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t wait (pid_t pid,
              ACE_exitcode *status,
              int wait_options = 0,
              ACE_HANDLE handle = 0);

  /**
   * Calls @c ::waitpid on UNIX/POSIX platforms Does not work on Vxworks 5.5.x.
   * On Win32, @a pid is ignored if the @a handle is not equal to 0.
   * Passing the process @a handle is prefer on Win32 because using
   * @a pid to wait on the project doesn't always work correctly
   * if the waited process has already terminated.
   */
  ACE_NAMESPACE_INLINE_FUNCTION
  pid_t waitpid (pid_t pid,
                 ACE_exitcode *status = 0,
                 int wait_options = 0,
                 ACE_HANDLE handle = 0);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_sys_wait.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SYS_WAIT_H */

