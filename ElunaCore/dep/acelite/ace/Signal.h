// -*- C++ -*-

//=============================================================================
/**
 *  @file    Signal.h
 *
 *  $Id: Signal.h 94454 2011-09-08 17:36:56Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_SIGNAL_H
#define ACE_SIGNAL_H
#include /**/ "ace/pre.h"

#include "ace/config-lite.h"

#if defined (ACE_DONT_INCLUDE_ACE_SIGNAL_H)
# error ace/Signal.h was #included instead of signal.h by ace/OS_NS_signal.h:  fix!!!!
#endif /* ACE_DONT_INCLUDE_ACE_SIGNAL_H */

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_signal.h"

// Type of the extended signal handler.
typedef void (*ACE_Sig_Handler_Ex) (int, siginfo_t *siginfo, ucontext_t *ucontext);

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Sig_Set
 *
 * @brief Provide a C++ wrapper for the C sigset_t interface.
 *
 * Handle signals via a more elegant C++ interface (e.g.,
 * doesn't require the use of global variables or global
 * functions in an application).
 */
class ACE_Export ACE_Sig_Set
{
public:
  /// Initialize <sigset_> with @a sigset.  If @a sigset == 0 then fill
  /// the set.
  ACE_Sig_Set (sigset_t *sigset);

  /// Initialize <sigset_> with @a sigset.  If @a sigset == 0 then fill
  /// the set.
  ACE_Sig_Set (ACE_Sig_Set *sigset);

  /// If @a fill == 0 then initialize the <sigset_> to be empty, else
  /// full.
  ACE_Sig_Set (int fill = 0);

  ~ACE_Sig_Set (void);

  /// Create a set that excludes all signals defined by the system.
  int empty_set (void);

  /// Create a set that includes all signals defined by the system.
  int fill_set (void);

  /// Adds the individual signal specified by @a signo to the set.
  int sig_add (int signo);

  /// Deletes the individual signal specified by @a signo from the set.
  int sig_del (int signo);

  /// Checks whether the signal specified by @a signo is in the set.
  int is_member (int signo) const;

  /// Returns a pointer to the underlying @c sigset_t.
  operator sigset_t *();

  /// Returns a copy of the underlying @c sigset_t.
  sigset_t sigset (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Set of signals.
  sigset_t sigset_;
};

/**
 * @class ACE_Sig_Action
 *
 * @brief C++ wrapper facade for the @c sigaction struct.
 */
class ACE_Export ACE_Sig_Action
{
public:
  // = Initialization methods.
  /// Default constructor.  Initializes everything to 0.
  ACE_Sig_Action (void);

  /// Assigns the various fields of a @c sigaction struct but doesn't
  /// register for signal handling via the @c sigaction function.
  ACE_Sig_Action (ACE_SignalHandler handler,
                  sigset_t *sigmask = 0,
                  int flags = 0);

  /// Assigns the various fields of a @c sigaction struct but doesn't
  /// register for signal handling via the @c sigaction function.
  ACE_Sig_Action (ACE_SignalHandler handler,
                  const ACE_Sig_Set &sigmask,
                  int flags = 0);

  /**
   * Assigns the various fields of a @c sigaction struct and registers
   * the @a handler to process signal @a signum via the @c sigaction
   * function.
   */
  ACE_Sig_Action (ACE_SignalHandler handler,
                  int signum,
                  sigset_t *sigmask = 0,
                  int flags = 0);

  /**
   * Assigns the various fields of a @c sigaction struct and registers
   * the @a handler to process signal @a signum via the @c sigaction
   * function.
   */
  ACE_Sig_Action (ACE_SignalHandler handler,
                  int signum,
                  const ACE_Sig_Set &sigmask,
                  int flags = 0);

  /**
   * Assigns the various fields of a @c sigaction struct and registers
   * the @a handler to process all @a signalss via the @c sigaction
   * function.
   */
  ACE_Sig_Action (const ACE_Sig_Set &signalss,
                  ACE_SignalHandler handler,
                  const ACE_Sig_Set &sigmask,
                  int flags = 0);

  /**
   * Assigns the various fields of a @c sigaction struct and registers
   * the @a handler to process all @a signalss via the @c sigaction
   * function.
   */
  ACE_Sig_Action (const ACE_Sig_Set &signalss,
                  ACE_SignalHandler handler,
                  sigset_t *sigmask = 0,
                  int flags = 0);

  /// Copy constructor.
  ACE_Sig_Action (const ACE_Sig_Action &s);

  /// Default dtor.
  ~ACE_Sig_Action (void);

  // = Signal action management.
  /// Register @c this as the current disposition and store old
  /// disposition into @a oaction if it is non-NULL.
  int register_action (int signum,
                       ACE_Sig_Action *oaction = 0);

  /// Assign the value of @a oaction to @c this and make it become the
  /// new signal disposition.
  int restore_action (int signum,
                      ACE_Sig_Action &oaction);

  /// Retrieve the current disposition into @c this.
  int retrieve_action (int signum);

  /// Set current signal action.
  void set (struct sigaction *);

  /// Get current signal action.
  struct sigaction *get (void);
  operator struct sigaction *();

  /// Set current signal flags.
  void flags (int);

  /// Get current signal flags.
  int flags (void);

  /// Set current signal mask.
  void mask (sigset_t *);
  void mask (ACE_Sig_Set &);

  /// Get current signal mask.
  sigset_t *mask (void);

  /// Set current signal handler (pointer to function).
  void handler (ACE_SignalHandler);

  /// Get current signal handler (pointer to function).
  ACE_SignalHandler handler (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Controls signal behavior.
  struct sigaction sa_;
};

/**
 * @class ACE_Sig_Guard
 *
 * @brief Hold signals in MASK for duration of a C++ statement block.
 * Note that a "0" for mask causes all signals to be held.
 */
class ACE_Export ACE_Sig_Guard
{
public:
  // = Initialization and termination methods.
  /// This is kind of conditional Guard, needed when guard should be
  /// activated only when a specific condition met. When condition ==
  /// true (default), Guard is activated
  ACE_Sig_Guard (ACE_Sig_Set *mask = 0, bool condition = true);

  /// Restore blocked signals.
  ~ACE_Sig_Guard (void);

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  /// Original signal mask.
  ACE_Sig_Set omask_;

  /// Guard Condition
  bool condition_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Signal.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SIGNAL_HANDLER_H */
