// -*- C++ -*-

//=============================================================================
/**
 *  @file    Sig_Adapter.h
 *
 *  $Id: Sig_Adapter.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SIG_ADAPTER_H
#define ACE_SIG_ADAPTER_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"
#include "ace/Signal.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Sig_Adapter
 *
 * @brief Provide an adapter that transforms various types of signal
 * handlers into the scheme used by the ACE_Reactor.
 */
class ACE_Export ACE_Sig_Adapter : public ACE_Event_Handler
{
public:
  ACE_Sig_Adapter (ACE_Sig_Action &, int sigkey);
  ACE_Sig_Adapter (ACE_Event_Handler *, int sigkey);
  ACE_Sig_Adapter (ACE_Sig_Handler_Ex, int sigkey = 0);
  ~ACE_Sig_Adapter (void);

  /// Returns this signal key that's used to remove this from the
  /// ACE_Reactor's internal table.
  int sigkey (void);

  /// Called by the <Reactor> to dispatch the signal handler.
  virtual int handle_signal (int, siginfo_t *, ucontext_t *);

private:
  /// Key for this signal handler (used to remove it).
  int sigkey_;

  /// Is this an external handler or an ACE handler?
  enum
  {
    /// We're just wrapping an ACE_Event_Handler.
    ACE_HANDLER,
    /// An ACE_Sig_Action.
    SIG_ACTION,
    /// A normal C function.
    C_FUNCTION
  } type_;

  // = This should be a union, but C++ won't allow that because the
  // <ACE_Sig_Action> has a constructor.
  /// This is an external handler (ugh).
  ACE_Sig_Action sa_;

  /// This is an ACE hander.
  ACE_Event_Handler *eh_;

  /// This is a normal C function.
  ACE_Sig_Handler_Ex sig_func_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_SIG_ADAPTER_H */
