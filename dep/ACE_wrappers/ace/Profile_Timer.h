// -*- C++ -*-
//==========================================================================
/**
 *  @file    Profile_Timer.h
 *
 *  $Id: Profile_Timer.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================

#ifndef ACE_PROFILE_TIMER_H
#define ACE_PROFILE_TIMER_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/High_Res_Timer.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Profile_Timer
 *
 * @brief This class provides both a timing mechanism and a mechanism
 * for reporting the resource usage of a process.
 */
class ACE_Export ACE_Profile_Timer
{
public:
  /**
   * @class ACE_Elapsed_Time
   *
   * @brief Keeps track of the various user, system, and elapsed (real)
   * times.
   */
  class ACE_Elapsed_Time
  {
  public:
    /// Elapsed wall clock time.
    ACE_timer_t real_time;
    /// CPU time spent in user space.
    ACE_timer_t user_time;
    /// CPU time spent in system space.
    ACE_timer_t system_time;
  };
  typedef ACE_Rusage Rusage;
  // = Initialization and termination methods.
  /// Default constructor. Clears all time values to 0.
  ACE_Profile_Timer (void);
  /// Shutdown the timer.
  ~ACE_Profile_Timer (void);
  // = Timer methods.
  /// Activate the timer.
  int start (void);
  /// Stop the timer.
  int stop (void);
  // = Resource utilization methods.
  /// Compute the time elapsed between calls to @c start() and @c stop().
  int elapsed_time (ACE_Elapsed_Time &et);
  /// Compute the amount of resource utilization between calls to @c start()
  /// and @c stop().
  void elapsed_rusage (ACE_Profile_Timer::Rusage &rusage);
  /// Return the resource utilization (don't recompute it).
  void get_rusage (ACE_Profile_Timer::Rusage &rusage);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Compute how much time has elapsed.
  void compute_times (ACE_Elapsed_Time &et);
  /// Keep track of the starting resource utilization.
  ACE_Profile_Timer::Rusage begin_usage_;
  /// Keep track of the ending resource utilization.
  ACE_Profile_Timer::Rusage end_usage_;
  /// Keep track of the last rusage for incremental timing.
  ACE_Profile_Timer::Rusage last_usage_;
#if defined (ACE_HAS_PRUSAGE_T)
  /// Substract two timestructs and store their difference.
  void subtract (timespec_t &tdiff, timespec_t &t0, timespec_t &t1);
  /// I/O handle for /proc file system.
  ACE_HANDLE proc_handle_;
#elif defined (ACE_HAS_GETRUSAGE)
  /// Substract two timestructs and store their difference.
  void subtract (timeval &tdiff,
                 timeval &t0,
                 timeval &t1);
  /// Keep track of the beginning time.
  timeval begin_time_;
  /// Keep track of the ending time.
  timeval end_time_;
  /// Keep track of the last time for incremental timing.
  timeval last_time_;
#endif /* ACE_HAS_PRUSAGE_T */
#if defined (ACE_WIN32) || (!defined (ACE_HAS_PRUSAGE_T) && !defined (ACE_HAS_GETRUSAGE))
  /// The high resolution timer
  ACE_High_Res_Timer timer_;
#endif /* ACE_WIN32 || !ACE_HAS_PRUSAGE_T && !ACE_HAS_GETRUSAGE */
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
# include "ace/Profile_Timer.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_PROFILE_TIMER_H */

