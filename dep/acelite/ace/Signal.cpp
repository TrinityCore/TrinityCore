// $Id: Signal.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Signal.h"
// #include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Signal.inl"
#endif /* __ACE_INLINE__ */




ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Sig_Action)

void
ACE_Sig_Action::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Sig_Action::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_ALLOC_HOOK_DEFINE(ACE_Sig_Set)

ACE_Sig_Set::~ACE_Sig_Set (void)
{
  ACE_TRACE ("ACE_Sig_Set::~ACE_Sig_Set");
  ACE_OS::sigemptyset (&this->sigset_);
}

ACE_Sig_Action::~ACE_Sig_Action (void)
{
  ACE_TRACE ("ACE_Sig_Action::~ACE_Sig_Action");
}

// Restore the signal mask.

ACE_Sig_Guard::~ACE_Sig_Guard (void)
{
  //ACE_TRACE ("ACE_Sig_Guard::~ACE_Sig_Guard");
  if (!this->condition_)
    return;

#if !defined (ACE_LACKS_UNIX_SIGNALS)
#if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
  ACE_OS::sigprocmask (SIG_SETMASK,
                       (sigset_t *) this->omask_,
                       0);
#else
  ACE_OS::thr_sigsetmask (SIG_SETMASK,
                          (sigset_t *) this->omask_,
                          0);
#endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
#endif /* !ACE_LACKS_UNIX_SIGNALS */
}

void
ACE_Sig_Set::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Sig_Set::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_ALLOC_HOOK_DEFINE(ACE_Sig_Guard)

void
ACE_Sig_Guard::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Sig_Guard::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_Sig_Action::ACE_Sig_Action (void)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = 0;

  // Since Service_Config::signal_handler_ is static and has an
  // ACE_Sig_Action instance, Win32 will get errno set unless this is
  // commented out.
#if !defined (ACE_WIN32)
  ACE_OS::sigemptyset (&this->sa_.sa_mask);
#endif /* ACE_WIN32 */
  this->sa_.sa_handler = 0;
}

ACE_Sig_Action::ACE_Sig_Action (ACE_SignalHandler sig_handler,
                                sigset_t *sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  if (sig_mask == 0)
    ACE_OS::sigemptyset (&this->sa_.sa_mask);
  else
    this->sa_.sa_mask = *sig_mask; // Structure assignment...

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */
}

ACE_Sig_Action::ACE_Sig_Action (ACE_SignalHandler sig_handler,
                                const ACE_Sig_Set &sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  // Structure assignment...
  this->sa_.sa_mask = sig_mask.sigset ();

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */
}

ACE_Sig_Action::ACE_Sig_Action (ACE_SignalHandler sig_handler,
                                int signum,
                                sigset_t *sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  if (sig_mask == 0)
    ACE_OS::sigemptyset (&this->sa_.sa_mask);
  else
    this->sa_.sa_mask = *sig_mask; // Structure assignment...

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */
  ACE_OS::sigaction (signum, &this->sa_, 0);
}

ACE_Sig_Action::ACE_Sig_Action (ACE_SignalHandler sig_handler,
                                int signum,
                                const ACE_Sig_Set &sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  // Structure assignment...
  this->sa_.sa_mask = sig_mask.sigset ();

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */
  ACE_OS::sigaction (signum, &this->sa_, 0);
}

ACE_Sig_Action::ACE_Sig_Action (const ACE_Sig_Set &signals,
                                ACE_SignalHandler sig_handler,
                                const ACE_Sig_Set &sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  // Structure assignment...
  this->sa_.sa_mask = sig_mask.sigset ();

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */

#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; s++)
    if ((signals.is_member (s)) == 1)
      ACE_OS::sigaction (s, &this->sa_, 0);
#else  /* ACE_NSIG <= 0  */
  ACE_UNUSED_ARG (signals);
#endif /* ACE_NSIG <= 0  */
}

ACE_Sig_Action::ACE_Sig_Action (const ACE_Sig_Set &signals,
                                ACE_SignalHandler sig_handler,
                                sigset_t *sig_mask,
                                int sig_flags)
{
  // ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  this->sa_.sa_flags = sig_flags;

  if (sig_mask == 0)
    ACE_OS::sigemptyset (&this->sa_.sa_mask);
  else
    this->sa_.sa_mask = *sig_mask; // Structure assignment...

#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (sig_handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (sig_handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */

#if (ACE_NSIG > 0)
  for (int s = 1; s < ACE_NSIG; s++)
    if ((signals.is_member (s)) == 1)
      ACE_OS::sigaction (s, &this->sa_, 0);
#else  /* ACE_NSIG <= 0  */
  ACE_UNUSED_ARG (signals);
#endif /* ACE_NSIG <= 0  */
}

ACE_END_VERSIONED_NAMESPACE_DECL
