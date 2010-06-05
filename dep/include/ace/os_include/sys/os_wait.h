// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_wait.h
 *
 *  declarations for waiting
 *
 *  $Id: os_wait.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_SYS_OS_WAIT_H
#define ACE_OS_INCLUDE_SYS_OS_WAIT_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_signal.h"
#include "ace/os_include/sys/os_resource.h"

#if !defined (ACE_LACKS_SYS_WAIT_H)
#  include /**/ <sys/wait.h>
#endif /* !ACE_LACKS_SYS_WAIT_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

  // Wrapping around wait status <wstat> macros for platforms that
  // lack them.

# if !defined (WCOREDUMP)
#   define WCOREDUMP(stat) 0
# endif /* WCOREDUMP */

# if !defined (WNOHANG)
#   define WNOHANG 0100
# endif /* !WNOHANG */

  // If the value of WIFEXITED(stat) is non-zero, this macro evaluates
  // to the exit code that the child process exit(3C), or the value
  // that the child process returned from main.  Peaceful exit code is
  // 0.
# if !defined (WEXITSTATUS)
#   define WEXITSTATUS(stat) stat
# endif /* WEXITSTATUS */

# if !defined (WIFCONTINUED)
#   define WIFCONTINUED(stat) 0
# endif /* WIFCONTINUED */

  // Evaluates to a non-zero value if status was returned for a child
  // process that terminated normally.  0 means status wasn't
  // returned.
# if !defined (WIFEXITED)
#   define WIFEXITED(stat) 1
# endif /* WIFEXITED */

  // Evaluates to a non-zero value if status was returned for a child
  // process that terminated due to the receipt of a signal.  0 means
  // status wasnt returned.
# if !defined (WIFSIGNALED)
#   define WIFSIGNALED(stat) 0
# endif /* WIFSIGNALED */

# if !defined (WIFSTOPPED)
#   define WIFSTOPPED(stat) 0
# endif /* WIFSTOPPED */

# if !defined (WSTOPSIG)
#   define WSTOPSIG(stat) 0
# endif /* WSTOPSIG */

  // If the value of  WIFSIGNALED(stat)  is non-zero,  this macro
  // evaluates to the number of the signal that  caused  the
  // termination of the child process.
# if !defined (WTERMSIG)
#   define WTERMSIG(stat) 0
# endif /* WTERMSIG */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_SYS_OS_WAIT_H */

