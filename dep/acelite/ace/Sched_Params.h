// -*- C++ -*-

//=============================================================================
/**
 *  @file    Sched_Params.h
 *
 *  $Id: Sched_Params.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David Levine <levine@cs.wustl.edu>
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================

#ifndef ACE_SCHED_PARAMS_H
#define ACE_SCHED_PARAMS_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Value.h"
#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Sched_Params
 *
 * @brief Container for scheduling-related parameters.
 *
 * ACE_Sched_Params are passed via <ACE_OS::sched_params> to the
 * OS to specify scheduling parameters.  These parameters include
 * scheduling policy, such as FIFO (ACE_SCHED_FIFO), round-robin
 * (ACE_SCHED_RR), or an implementation-defined "OTHER"
 * (ACE_SCHED_OTHER), to which many systems default; priority;
 * and a time-slice quantum for round-robin scheduling.  A
 * "scope" parameter specifies whether the ACE_Sched_Params
 * applies to the current process, current lightweight process
 * (LWP) (on Solaris), or current thread.  Please see the "NOTE"
 * below about not all combinations of parameters being legal on
 * a particular platform.
 * For the case of thread priorities, it is intended that
 * <ACE_OS::sched_params> usually be called from <main> before
 * any threads have been spawned.  If spawned threads inherit
 * their parent's priority (I think that's the default behavior
 * for all of our platforms), then this sets the default base
 * priority.  Individual thread priorities can be adjusted as
 * usual using <ACE_OS::thr_prio> or via the ACE_Thread
 * interface.  See the parameter descriptions in the private:
 * section below.
 * @note This class does not do any checking of parameters.  It
 * is just a container class.  If it is constructed with values
 * that are not supported on a platform, the call to
 * <ACE_OS::sched_params> will fail by returning -1 with EINVAL
 * (available through <ACE_OS::last_error>).
 */
class ACE_Export ACE_Sched_Params
{
  //    NOTE: Solaris 2.5.x threads in the RT class must set the
  //    priority of their LWP.  The only way to do that through ACE is
  //    for the RT thread itself to call <ACE_OS::thr_setprio> with
  //    it's own priority.

  //    OS Scheduling parameters are complicated and often confusing.
  //    Many thanks to Thilo Kielmann
  //    <kielmann@informatik.uni-siegen.de> for his careful review of
  //    this class design, thoughtful comments, and assistance with
  //    implementation, especially for PTHREADS platforms.  Please
  //    send any comments or corrections to the ACE developers.
public:
  typedef int Policy;

  // = Initialization and termination methods.
  /// Constructor.
  ACE_Sched_Params (const Policy policy,
                    const ACE_Sched_Priority priority,
                    const int scope = ACE_SCOPE_THREAD,
                    const ACE_Time_Value &quantum = ACE_Time_Value::zero);

  /// Termination.
  ~ACE_Sched_Params (void);

  // = Get/Set methods:

  // = Get/Set policy
  Policy policy (void) const;
  void policy (const Policy);

  // = Get/Set priority.
  ACE_Sched_Priority priority (void) const;
  void priority (const ACE_Sched_Priority);

  // = Get/Set scope.
  int scope (void) const;
  void scope(const int);

  // = Get/Set quantum.
  const ACE_Time_Value &quantum (void) const;
  void quantum (const ACE_Time_Value &);

  // = Accessors for OS-specific priorities.
  // These return priority values for ACE_SCHED_OTHER if the Policy value
  // is invalid.
  static int priority_min (const Policy,
                           const int scope = ACE_SCOPE_THREAD);
  static int priority_max (const Policy,
                           const int scope = ACE_SCOPE_THREAD);

  /**
   * The next higher priority.  "Higher" refers to scheduling priority,
   * not to the priority value itself.  (On some platforms, higher scheduling
   * priority is indicated by a lower priority value.)  If "priority" is
   * already the highest priority (for the specified policy), then it is
   * returned.
   */
  static int next_priority (const Policy,
                            const int priority,
                            const int scope = ACE_SCOPE_THREAD);

  /**
   * The previous, lower priority.  "Lower" refers to scheduling priority,
   * not to the priority value itself.  (On some platforms, lower scheduling
   * priority is indicated by a higher priority value.)  If "priority" is
   * already the lowest priority (for the specified policy), then it is
   * returned.
   */
  static int previous_priority (const Policy,
                                const int priority,
                                const int scope = ACE_SCOPE_THREAD);

private:
  /// Scheduling policy.
  Policy policy_;

  /// Default <priority_>: for setting the priority for the process, LWP,
  /// or thread, as indicated by the scope_ parameter.
  ACE_Sched_Priority priority_;

  /**
   * <scope_> must be one of the following:
   *   ACE_SCOPE_PROCESS:  sets the scheduling policy for the
   *     process, and the process priority.  On some platforms,
   *     such as Win32, the scheduling policy can _only_ be
   *     set at process scope.
   *   ACE_SCOPE_LWP: lightweight process scope, only used with
   *     Solaris threads.
   *   ACE_SCOPE_THREAD: sets the scheduling policy for the thread,
   *     if the OS supports it, such as with Posix threads, and the
   *     thread priority.
   * NOTE:  I don't think that these are the same as POSIX
   *        contention scope.  POSIX users who are interested in,
   *        and understand, contention scope will have to set it
   *        by using system calls outside of ACE.
   */
  int scope_;

  /**
   * The <quantum_> is for time slicing.  An ACE_Time_Value of 0 has
   * special significance: it means time-slicing is disabled; with
   * that, a thread that is running on a CPU will continue to run
   * until it blocks or is preempted.  Currently ignored if the OS
   * doesn't directly support time slicing, such as on VxWorks, or
   * setting the quantum (can that be done on Win32?).
   */
  ACE_Time_Value quantum_;
};

/**
 * @class ACE_Sched_Priority_Iterator
 *
 * @brief An iterator over the OS-defined scheduling priorities.
 *
 * The order of priorities (numeric value vs. importance) is OS
 * dependant, it can be the case that the priorities are not even
 * contigous.  This class permits iteration over priorities using
 * the iterator pattern.
 */
class ACE_Export ACE_Sched_Priority_Iterator
{
public:
  /// Initialize the iterator, the arguments define the scheduling
  /// policy and scope for the priorities (see ACE_Sched_Param).
  ACE_Sched_Priority_Iterator (const ACE_Sched_Params::Policy &policy,
                               int scope = ACE_SCOPE_THREAD);

  /// Default dtor.
  ~ACE_Sched_Priority_Iterator (void);

  /// Check if there are more priorities.
  int more (void) const;

  /// Return the current priority.
  int priority (void) const;

  /// Move to the next priority.
  /// The iteration is from lowest to highest importance.
  void next (void);

  /// Accessor for the scheduling policy over which we are iterating.
  const ACE_Sched_Params::Policy &policy (void) const;

  /// Accessor for the scheduling
  int scope (void) const;

private:
  /// The Scheduling policy (FIFO, RR, etc.) and scheduling scope
  /// (PROCESS, SYSTEM) we are iterating on.
  ACE_Sched_Params::Policy policy_;
  int scope_;

  /// The current priority.
  int priority_;

  /**
   * This is set to 1 when there are no more priorities. Cannot easily
   * compare against the highest priority on platforms were priorities
   * are non-contigous or descending.
   */
  int done_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Sched_Params.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_SCHED_PARAMS_H */
