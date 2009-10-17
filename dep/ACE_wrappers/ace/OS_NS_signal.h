// -*- C++ -*-
//=============================================================================
/**
 *  @file   OS_NS_signal.h
 *
 *  $Id: OS_NS_signal.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================
#ifndef ACE_OS_NS_SIGNAL_H
# define ACE_OS_NS_SIGNAL_H
# include /**/ "ace/pre.h"
# include "ace/config-lite.h"
# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/os_signal.h"
#include /**/ "ace/ACE_export.h"
#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export
# if !defined (SIG_BLOCK)
#   define SIG_BLOCK   1
# endif /* SIG_BLOCK   */
# if !defined (SIG_UNBLOCK)
#   define SIG_UNBLOCK 2
# endif /* SIG_UNBLOCK */
# if !defined (SIG_SETMASK)
#   define SIG_SETMASK 3
# endif /* SIG_SETMASK */
// Create some useful typedefs.
# if !defined (ACE_HAS_SIGINFO_T)
struct ACE_Export siginfo_t
{
  siginfo_t (ACE_HANDLE handle);
  siginfo_t (ACE_HANDLE *handles);      // JCEJ 12/23/96
  /// Win32 HANDLE that has become signaled.
  ACE_HANDLE si_handle_;
  /// Array of Win32 HANDLEs all of which have become signaled.
  ACE_HANDLE *si_handles_;
};
# endif /* ACE_HAS_SIGINFO_T */
#if !defined (ACE_WIN32)
extern "C"
{
  typedef void (*ACE_SIGNAL_C_FUNC)(int, siginfo_t *, void *);
}
#endif /* ACE_WIN32 */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// This hack is needed to get around an odd and hard-to-reproduce problem
// with HP aC++. If struct sigaction is defined extern "C" and the sigaction
// function in namespace ACE_OS, the compiler sometimes gets confused.
// If we help it with this typedef, it's fine. User code should not use
// the ACE typedef - it will be removed without warning as soon as we can
// either drop support for the broken compilers or figure out how to reproduce
// it so it can be reported to HP and fixed.
// There's a similar hack in OS_TLI.h for struct t_optmgmt.
// Also see ChangeLog entries:
// Mon Jan 23 16:35:40 UTC 2006  Steve Huston  <shuston@riverace.com>
// Mon Jan 23 22:08:56 UTC 2006  Steve Huston  <shuston@riverace.com>
#if defined (__HP_aCC) && (__HP_aCC <= 37300)
typedef extern "C" struct sigaction  ACE_SIGACTION;
#else
typedef struct sigaction ACE_SIGACTION;
#endif
namespace ACE_OS {
  //@{ @name A set of wrappers for Signals.
  ACE_NAMESPACE_INLINE_FUNCTION
  int kill (pid_t pid,
            int signum);
  ACE_NAMESPACE_INLINE_FUNCTION
  int pthread_sigmask (int how,
                       const sigset_t *nsp,
                       sigset_t *osp);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigaction (int signum,
                 const ACE_SIGACTION *nsa,
                 ACE_SIGACTION *osa);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigaddset (sigset_t *s,
                 int signum);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigdelset (sigset_t *s,
                 int signum);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigemptyset (sigset_t *s);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigfillset (sigset_t *s);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigismember (sigset_t *s,
                   int signum);
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_SignalHandler signal (int signum,
                            ACE_SignalHandler);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigprocmask (int how,
                   const sigset_t *nsp,
                   sigset_t *osp);
  ACE_NAMESPACE_INLINE_FUNCTION
  int sigsuspend (const sigset_t *set);
  //@}
} /* namespace ACE_OS */
ACE_END_VERSIONED_NAMESPACE_DECL
# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_signal.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */
# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_SIGNAL_H */

