// -*- C++ -*-
//
// $Id: Signal.inl 92069 2010-09-28 11:38:59Z johnnyw $

#include "ace/OS_NS_signal.h"
#include "ace/config-all.h"
#include "ace/Trace.h"
#include "ace/Object_Manager_Base.h"
#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Sig_Set::ACE_Sig_Set (sigset_t *ss)
  // : sigset_ ()
{
  ACE_TRACE ("ACE_Sig_Set::ACE_Sig_Set");

  if (ss == 0)
    ACE_OS::sigfillset (&this->sigset_);
  else
    // Structure assignment.
    this->sigset_ = *ss;
}

ACE_INLINE
ACE_Sig_Set::ACE_Sig_Set (int fill)
  // : sigset_ ()
{
  ACE_TRACE ("ACE_Sig_Set::ACE_Sig_Set");

  if (fill)
    ACE_OS::sigfillset (&this->sigset_);
  else
    ACE_OS::sigemptyset (&this->sigset_);
}

ACE_INLINE
ACE_Sig_Set::ACE_Sig_Set (ACE_Sig_Set *ss)
  // : sigset_ ()
{
  ACE_TRACE ("ACE_Sig_Set::ACE_Sig_Set");

  if (ss == 0)
    ACE_OS::sigfillset (&this->sigset_);
  else
    this->sigset_ = ss->sigset_;
}

ACE_INLINE int
ACE_Sig_Set::empty_set (void)
{
  ACE_TRACE ("ACE_Sig_Set::empty_set");
  return ACE_OS::sigemptyset (&this->sigset_);
}

ACE_INLINE int
ACE_Sig_Set::fill_set (void)
{
  ACE_TRACE ("ACE_Sig_Set::fill_set");
  return ACE_OS::sigfillset (&this->sigset_);
}

ACE_INLINE int
ACE_Sig_Set::sig_add (int signo)
{
  ACE_TRACE ("ACE_Sig_Set::sig_add");
  return ACE_OS::sigaddset (&this->sigset_, signo);
}

ACE_INLINE int
ACE_Sig_Set::sig_del (int signo)
{
  ACE_TRACE ("ACE_Sig_Set::sig_del");
  return ACE_OS::sigdelset (&this->sigset_, signo);
}

ACE_INLINE int
ACE_Sig_Set::is_member (int signo) const
{
  ACE_TRACE ("ACE_Sig_Set::is_member");
  return ACE_OS::sigismember (const_cast<sigset_t *> (&this->sigset_), signo);
}

ACE_INLINE
ACE_Sig_Set::operator sigset_t *(void)
{
  ACE_TRACE ("ACE_Sig_Set::operator sigset_t *");
  return &this->sigset_;
}

ACE_INLINE sigset_t
ACE_Sig_Set::sigset (void) const
{
  ACE_TRACE ("ACE_Sig_Set::sigset");
  return this->sigset_;
}

ACE_INLINE int
ACE_Sig_Action::flags (void)
{
  ACE_TRACE ("ACE_Sig_Action::flags");
  return this->sa_.sa_flags;
}

ACE_INLINE void
ACE_Sig_Action::flags (int flags)
{
  ACE_TRACE ("ACE_Sig_Action::flags");
  this->sa_.sa_flags = flags;
}

ACE_INLINE sigset_t *
ACE_Sig_Action::mask (void)
{
  ACE_TRACE ("ACE_Sig_Action::mask");
  return &this->sa_.sa_mask;
}

ACE_INLINE void
ACE_Sig_Action::mask (sigset_t *ss)
{
  ACE_TRACE ("ACE_Sig_Action::mask");
  if (ss != 0)
    this->sa_.sa_mask = *ss; // Structure assignment
}

ACE_INLINE void
ACE_Sig_Action::mask (ACE_Sig_Set &ss)
{
  ACE_TRACE ("ACE_Sig_Action::mask");
  this->sa_.sa_mask = ss.sigset (); // Structure assignment
}

ACE_INLINE ACE_SignalHandler
ACE_Sig_Action::handler (void)
{
  ACE_TRACE ("ACE_Sig_Action::handler");
  return ACE_SignalHandler (this->sa_.sa_handler);
}

ACE_INLINE void
ACE_Sig_Action::handler (ACE_SignalHandler handler)
{
  ACE_TRACE ("ACE_Sig_Action::handler");
#if !defined(ACE_HAS_TANDEM_SIGNALS)
  this->sa_.sa_handler = ACE_SignalHandlerV (handler);
#else
  this->sa_.sa_handler = (void (*)()) ACE_SignalHandlerV (handler);
#endif /* !ACE_HAS_TANDEM_SIGNALS */
}

ACE_INLINE void
ACE_Sig_Action::set (struct sigaction *sa)
{
  ACE_TRACE ("ACE_Sig_Action::set");
  this->sa_ = *sa; // Structure assignment.
}

ACE_INLINE struct sigaction *
ACE_Sig_Action::get (void)
{
  ACE_TRACE ("ACE_Sig_Action::get");
  return &this->sa_;
}

ACE_INLINE
ACE_Sig_Action::operator struct sigaction * ()
{
  ACE_TRACE ("ACE_Sig_Action::operator struct sigaction *");
  return &this->sa_;
}

ACE_INLINE
ACE_Sig_Action::ACE_Sig_Action (const ACE_Sig_Action &s)
  // : sa_ ()
{
  ACE_TRACE ("ACE_Sig_Action::ACE_Sig_Action");
  *this = s; // structure copy.
}

ACE_INLINE int
ACE_Sig_Action::register_action (int signum, ACE_Sig_Action *oaction)
{
  ACE_TRACE ("ACE_Sig_Action::register_action");
  struct sigaction *sa = oaction == 0 ? 0 : oaction->get ();

  return ACE_OS::sigaction (signum, &this->sa_, sa);
}

ACE_INLINE int
ACE_Sig_Action::retrieve_action (int signum)
{
  ACE_TRACE ("ACE_Sig_Action::retrieve_action");
  return ACE_OS::sigaction (signum, 0, &this->sa_);
}

ACE_INLINE int
ACE_Sig_Action::restore_action (int signum, ACE_Sig_Action &oaction)
{
  ACE_TRACE ("ACE_Sig_Action::restore_action");
  this->sa_ = *oaction.get (); // Structure assignment
  return ACE_OS::sigaction (signum, &this->sa_, 0);
}

// Block out the signal MASK until the destructor is called.

ACE_INLINE
ACE_Sig_Guard::ACE_Sig_Guard (ACE_Sig_Set *mask,
                              bool condition)
  : omask_ ()
  , condition_ (condition)
{
  //ACE_TRACE ("ACE_Sig_Guard::ACE_Sig_Guard");
  if (!this->condition_)
    return;

#if defined (ACE_LACKS_UNIX_SIGNALS)
  ACE_UNUSED_ARG (mask);
#else
  // If MASK is 0 then block all signals!
  if (mask == 0)
    {
#  if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
      ACE_OS::sigprocmask (SIG_BLOCK,
                           ACE_OS_Object_Manager::default_mask (),
                           (sigset_t *) this->omask_);
#  else
      ACE_OS::thr_sigsetmask (SIG_BLOCK,
                              ACE_OS_Object_Manager::default_mask (),
                              (sigset_t *) this->omask_);
#  endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
    }
  else
#  if defined (ACE_LACKS_PTHREAD_THR_SIGSETMASK)
    ACE_OS::sigprocmask (SIG_BLOCK,
                         (sigset_t *) *mask,
                         (sigset_t *)
                         this->omask_);
#  else
    ACE_OS::thr_sigsetmask (SIG_BLOCK,
                            (sigset_t *) *mask,
                            (sigset_t *)
                            this->omask_);
#  endif /* ACE_LACKS_PTHREAD_THR_SIGSETMASK */
#endif /* ACE_LACKS_UNIX_SIGNALS */
}

ACE_END_VERSIONED_NAMESPACE_DECL
