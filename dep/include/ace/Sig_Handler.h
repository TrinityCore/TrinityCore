// -*- C++ -*-

//=============================================================================
/**
 *  @file    Sig_Handler.h
 *
 *  $Id: Sig_Handler.h 81388 2008-04-23 14:02:05Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SIGNAL_HANDLER_H
#define ACE_SIGNAL_HANDLER_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Event_Handler.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Sig_Action;

/**
 * @class ACE_Sig_Handler
 *
 * @brief This is the main dispatcher of signals for ACE.  It improves
 * the existing UNIX signal handling mechanism by allowing C++
 * objects to handle signals in a way that avoids the use of
 * global/static variables and functions.
 *
 * Using this class a program can register an ACE_Event_Handler
 * with the ACE_Sig_Handler in order to handle a designated
 * @a signum.  When a signal occurs that corresponds to this
 * @a signum, the @c handle_signal method of the registered
 * ACE_Event_Handler is invoked automatically.
 */
class ACE_Export ACE_Sig_Handler
{
public:
  /// Default constructor.
  ACE_Sig_Handler (void);

  /// Destructor
  virtual ~ACE_Sig_Handler (void);

  // = Registration and removal methods.
  /**
   * Add a new ACE_Event_Handler and a new sigaction associated with
   * @a signum.  Passes back the existing ACE_Event_Handler and its
   * sigaction if pointers are non-zero.  Returns -1 on failure and >=
   * 0 on success.
   */
  virtual int register_handler (int signum,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0,
                                ACE_Event_Handler **old_sh = 0,
                                ACE_Sig_Action *old_disp = 0);

  /**
   * Remove the ACE_Event_Handler currently associated with
   * @a signum.  @a sigkey is ignored in this implementation since there
   * is only one instance of a signal handler.  Install the new
   * disposition (if given) and return the previous disposition (if
   * desired by the caller).  Returns 0 on success and -1 if @a signum
   * is invalid.
   */
  virtual int remove_handler (int signum,
                              ACE_Sig_Action *new_disp = 0,
                              ACE_Sig_Action *old_disp = 0,
                              int sigkey = -1);

  // Set/get signal status.
  /// True if there is a pending signal.
  static int sig_pending (void);

  /// Reset the value of <sig_pending_> so that no signal is pending.
  static void sig_pending (int);

  // = Set/get the handler associated with a particular signal.

  /// Return the ACE_Sig_Handler associated with @a signum.
  virtual ACE_Event_Handler *handler (int signum);

  /// Set a new ACE_Event_Handler that is associated with @a signum.
  /// Return the existing handler.
  virtual ACE_Event_Handler *handler (int signum, ACE_Event_Handler *);

  /**
   * Callback routine registered with sigaction(2) that dispatches the
   * <handle_signal> method of the appropriate pre-registered
   * ACE_Event_Handler.
   */
  static void dispatch (int, siginfo_t *,
                        ucontext_t *);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  // = These methods and data members are shared by derived classes.

  /**
   * Set a new ACE_Event_Handler that is associated with @a signum.
   * Return the existing handler.  Does not acquire any locks so that
   * it can be called from a signal handler, such as <dispatch>.
   */
  static ACE_Event_Handler *handler_i (int signum,
                                       ACE_Event_Handler *);

  /**
   * This implementation method is called by <register_handler> and
   * @c dispatch.  It doesn't do any locking so that it can be called
   * within a signal handler, such as @c dispatch.  It adds a new
   * ACE_Event_Handler and a new sigaction associated with @a signum.
   * Passes back the existing ACE_Event_Handler and its sigaction if
   * pointers are non-zero.  Returns -1 on failure and >= 0 on
   * success.
   */
  static int register_handler_i (int signum,
                                 ACE_Event_Handler *new_sh,
                                 ACE_Sig_Action *new_disp = 0,
                                 ACE_Event_Handler **old_sh = 0,
                                 ACE_Sig_Action *old_disp = 0);

  /// Check whether the SIGNUM is within the legal range of signals.
  static int in_range (int signum);

  /// Keeps track of whether a signal is pending.
  static sig_atomic_t sig_pending_;

private:
  /// Array used to store one user-defined Event_Handler for every
  /// signal.
  static ACE_Event_Handler *signal_handlers_[ACE_NSIG];
};

/**
 * @class ACE_Sig_Handlers
 *
 * @brief This is an alternative signal handling dispatcher for ACE.  It
 * allows a list of signal handlers to be registered for each
 * signal.  It also makes SA_RESTART the default mode.
 *
 * Using this class a program can register one or more
 * ACE_Event_Handler with the ACE_Sig_Handler in order to
 * handle a designated @a signum.  When a signal occurs that
 * corresponds to this @a signum, the <handle_signal> methods of
 * all the registered ACE_Event_Handlers are invoked
 * automatically.
 */
class ACE_Export ACE_Sig_Handlers : public ACE_Sig_Handler
{
public:
  // = Registration and removal methods.
  /**
   * Add a new ACE_Event_Handler and a new sigaction associated with
   * @a signum.  Passes back the existing ACE_Event_Handler and its
   * sigaction if pointers are non-zero.  Returns -1 on failure and
   * a <sigkey> that is >= 0 on success.
   */
  virtual int register_handler (int signum,
                                ACE_Event_Handler *new_sh,
                                ACE_Sig_Action *new_disp = 0,
                                ACE_Event_Handler **old_sh = 0,
                                ACE_Sig_Action *old_disp = 0);

  /**
   * Remove an ACE_Event_Handler currently associated with @a signum.
   * We remove the handler if (1) its sigkey> matches the @a sigkey
   * passed as a parameter or (2) if we've been told to remove all the
   * handlers, i.e., <sigkey> == -1.  If a new disposition is given it
   * is installed and the previous disposition is returned (if desired
   * by the caller).  Returns 0 on success and -1 if @a signum is
   * invalid.
   */
  virtual int remove_handler (int signum,
                              ACE_Sig_Action *new_disp = 0,
                              ACE_Sig_Action *old_disp = 0,
                              int sigkey = -1);

  // = Set/get the handler associated with a particular signal.

  /// Return the head of the list of <ACE_Sig_Handler>s associated with
  /// SIGNUM.
  virtual ACE_Event_Handler *handler (int signum);

  /**
   * Set a new ACE_Event_Handler that is associated with SIGNUM at
   * the head of the list of signals.  Return the existing handler
   * that was at the head.
   */
  virtual ACE_Event_Handler *handler (int signum,
                                      ACE_Event_Handler *);

  /**
   * Callback routine registered with sigaction(2) that dispatches the
   * <handle_signal> method of all the pre-registered
   * ACE_Event_Handlers for @a signum
   */
  static void dispatch (int signum, siginfo_t *, ucontext_t *);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /**
   * Keeps track of the id that uniquely identifies each registered
   * signal handler.  This id can be used to cancel a timer via the
   * <remove_handler> method.
   */
  static int sigkey_;

  /// If this is true then a 3rd party library has registered a
  /// handler...
  static bool third_party_sig_handler_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Sig_Handler.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SIG_HANDLER_H */

