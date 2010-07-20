// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_signal.h
 *
 *  signals
 *
 *  $Id: os_signal.h 87480 2009-11-11 11:38:15Z olli $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_SIGNAL_H
#define ACE_OS_INCLUDE_OS_SIGNAL_H

#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/sys/os_types.h"

#if !defined (ACE_LACKS_SIGNAL_H)
   extern "C" {
#  include /**/ <signal.h>
   }
#endif /* !ACE_LACKS_SIGNAL_H */

// This must come after signal.h is #included.
#if defined (SCO)
#  define SIGIO SIGPOLL
#  include /**/ <sys/regset.h>
#endif /* SCO */

#if defined (ACE_HAS_SIGINFO_T)
#  if !defined (ACE_LACKS_SIGINFO_H)
#    if defined (__QNX__) || defined (__OpenBSD__) || defined (__INTERIX)
#      include /**/ <sys/siginfo.h>
#    else  /* __QNX__ || __OpenBSD__ */
#      include /**/ <siginfo.h>
#    endif /* __QNX__ || __OpenBSD__ */
#  endif /* ACE_LACKS_SIGINFO_H */
#endif /* ACE_HAS_SIGINFO_T */

#if defined (ACE_VXWORKS) && (ACE_VXWORKS < 0x620) && !defined (__RTP__)
#  include /**/ <sigLib.h>
#endif /* ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_LACKS_SIGSET) && !defined (__MINGW32__)
  typedef u_int sigset_t;
#endif /* ACE_LACKS_SIGSET && !sigset_t */

#if !defined (ACE_HAS_SIG_ATOMIC_T)
   typedef int sig_atomic_t;
#endif /* !ACE_HAS_SIG_ATOMIC_T */

# if !defined (SA_SIGINFO)
#   define SA_SIGINFO 0
# endif /* SA_SIGINFO */

# if !defined (SA_RESTART)
#   define SA_RESTART 0
# endif /* SA_RESTART */

#if !defined (SIGHUP)
#  define SIGHUP 0
#endif /* SIGHUP */

#if !defined (SIGINT)
#  define SIGINT 0
#endif /* SIGINT */

#if !defined (SIGSEGV)
#  define SIGSEGV 0
#endif /* SIGSEGV */

#if !defined (SIGIO)
#  define SIGIO 0
#endif /* SIGSEGV */

#if !defined (SIGUSR1)
#  define SIGUSR1 0
#endif /* SIGUSR1 */

#if !defined (SIGUSR2)
#  define SIGUSR2 0
#endif /* SIGUSR2 */

#if !defined (SIGCHLD)
#  define SIGCHLD 0
#endif /* SIGCHLD */

#if !defined (SIGCLD)
#  define SIGCLD SIGCHLD
#endif /* SIGCLD */

#if !defined (SIGQUIT)
#  define SIGQUIT 0
#endif /* SIGQUIT */

#if !defined (SIGPIPE)
#  define SIGPIPE 0
#endif /* SIGPIPE */

#if !defined (SIGALRM)
#  define SIGALRM 0
#endif /* SIGALRM */

#if !defined (SIGABRT)
#  define SIGABRT 0
#endif /* SIGABRT */

#if !defined (SIGTERM)
#  define SIGTERM 0
#endif /* SIGTERM */

#if !defined (SIG_DFL)
#  define SIG_DFL ((__sighandler_t) 0)
#endif /* SIG_DFL */

#if !defined (SIG_IGN)
#  define SIG_IGN ((__sighandler_t) 1)     /* ignore signal */
#endif /* SIG_IGN */

#if !defined (SIG_ERR)
#  define SIG_ERR ((__sighandler_t) -1)    /* error return from signal */
#endif /* SIG_ERR */

// These are used by the <ACE_IPC_SAP::enable> and
// <ACE_IPC_SAP::disable> methods.  They must be unique and cannot
// conflict with the value of <ACE_NONBLOCK>.  We make the numbers
// negative here so they won't conflict with other values like SIGIO,
// etc.
# define ACE_SIGIO -1
# define ACE_SIGURG -2
# define ACE_CLOEXEC -3

#if defined (ACE_VXWORKS)
#  define ACE_NSIG (_NSIGS + 1)
#elif defined (__Lynx__) || defined (ACE_HAS_RTEMS)
#  define ACE_NSIG (NSIG + 1)
#else
   // All other platforms set NSIG to one greater than the
   // highest-numbered signal.
#  define ACE_NSIG NSIG
#endif /* ACE_VXWORKS */

#if defined (ACE_HAS_WINCE)
  typedef void (__cdecl * __sighandler_t)(int);
#endif

#if defined (ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES)
  // Prototypes for both signal() and struct sigaction are consistent..
  typedef void (*ACE_SignalHandler)(int);
  typedef void (*ACE_SignalHandlerV)(int);
#elif defined (ACE_HAS_LYNXOS4_SIGNALS) || defined (ACE_HAS_TANDEM_SIGNALS)
   typedef void (*ACE_SignalHandler)(...);
   typedef void (*ACE_SignalHandlerV)(...);
#elif defined (ACE_HAS_SVR4_SIGNAL_T)
   // SVR4 Signals are inconsistent (e.g., see struct sigaction)..
   typedef void (*ACE_SignalHandler)(int);
   typedef void (*ACE_SignalHandlerV)(void);
#elif defined (ACE_WIN32)
   typedef void (__cdecl *ACE_SignalHandler)(int);
   typedef void (__cdecl *ACE_SignalHandlerV)(int);
#elif defined (ACE_HAS_UNIXWARE_SVR4_SIGNAL_T)
   typedef void (*ACE_SignalHandler)(int);
   typedef void (*ACE_SignalHandlerV)(...);
#elif defined (INTEGRITY)
   typedef void (*ACE_SignalHandler)();
   typedef void (*ACE_SignalHandlerV)(int);
#elif defined (ACE_HAS_RTEMS)
   typedef void (*ACE_SignalHandler)();
   typedef void (*ACE_SignalHandlerV)();
#else /* This is necessary for some older broken version of cfront */
#  if defined (SIG_PF)
#    define ACE_SignalHandler SIG_PF
#  else
     typedef void (*ACE_SignalHandler)(int);
#  endif /* SIG_PF */
   typedef void (*ACE_SignalHandlerV)(...);
#endif /* ACE_HAS_CONSISTENT_SIGNAL_PROTOTYPES */

#if defined (ACE_LACKS_SIGACTION)
   struct sigaction
   {
     int sa_flags;
     ACE_SignalHandlerV sa_handler;
     sigset_t sa_mask;
   };
#endif /* ACE_LACKS_SIGACTION */

// Defining POSIX4 real-time signal range.
#if defined(ACE_HAS_POSIX_REALTIME_SIGNALS)
#  define ACE_SIGRTMIN SIGRTMIN
#  define ACE_SIGRTMAX SIGRTMAX
#else /* !ACE_HAS_POSIX_REALTIME_SIGNALS */
#  ifndef ACE_SIGRTMIN
#    define ACE_SIGRTMIN 0
#  endif /* ACE_SIGRTMIN */
#  ifndef ACE_SIGRTMAX
#    define ACE_SIGRTMAX 0
#  endif /* ACE_SIGRTMAX */
#endif /* ACE_HAS_POSIX_REALTIME_SIGNALS */

#if defined (DIGITAL_UNIX)
   // sigwait is yet another macro on Digital UNIX 4.0, just causing
   // trouble when introducing member functions with the same name.
   // Thanks to Thilo Kielmann" <kielmann@informatik.uni-siegen.de> for
   // this fix.
#  if defined  (__DECCXX_VER)
#    undef sigwait
     // cxx on Digital Unix 4.0 needs this declaration.  With it,
     // <::_Psigwait> works with cxx -pthread.  g++ does _not_ need
     // it.
     int _Psigwait __((const sigset_t *set, int *sig));
#  endif /* __DECCXX_VER */
#elif !defined (ACE_HAS_SIGWAIT)
#  if defined(ACE_HAS_RTEMS)
     int sigwait (const sigset_t *set, int *sig);
#  else
     int sigwait (sigset_t *set);
#  endif /* ACE_HAS_RTEMS */
#endif /* ! DIGITAL_UNIX && ! ACE_HAS_SIGWAIT */

#if !defined (ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE)
  int pthread_sigmask(int, const sigset_t *, sigset_t *);
#endif /*!ACE_HAS_PTHREAD_SIGMASK_PROTOTYPE */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "ace/os_include/os_ucontext.h"

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_SIGNAL_H */
