// -*- C++ -*-
//==========================================================================
/**
 *  @file    High_Res_Timer.h
 *
 *  $Id: High_Res_Timer.h 81286 2008-04-09 07:27:30Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//==========================================================================
#ifndef ACE_HIGH_RES_TIMER_H
#define ACE_HIGH_RES_TIMER_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Basic_Types.h"
#include "ace/OS_NS_time.h"
#include "ace/Time_Value.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_High_Res_Timer
 *
 * @brief A high resolution timer class wrapper that encapsulates
 * OS-specific high-resolution timers, such as those found on
 * Solaris, AIX, Win32/Pentium, and VxWorks.
 *
 * Most of the member functions don't return values.  The only
 * reason that one would fail is if high-resolution time isn't
 * supported on the platform.  To avoid impacting performance
 * and complicating the interface, in that case,
 * <ACE_OS::gettimeofday> is used instead.
 * The global scale factor is required for platforms that have
 * high-resolution timers that return units other than
 * microseconds, such as clock ticks.  It is represented as a
 * static u_long, can only be accessed through static methods,
 * and is used by all instances of High Res Timer.  The member
 * functions that return or print times use the global scale
 * factor.  They divide the "time" that they get from
 * <ACE_OS::gethrtime> by global_scale_factor_ to obtain the
 * time in microseconds.  Its units are therefore 1/microsecond.
 * On Windows the global_scale_factor_ units are 1/millisecond.
 * There's a macro <ACE_HR_SCALE_CONVERSION> which gives the
 * units/second.  Because it's possible that the units/second
 * changes in the future, it's recommended to use it instead
 * of a "hard coded" solution.
 * Dependend on the platform and used class members, there's a
 * maximum elapsed period before overflow (which is not checked).
 * Look at the documentation with some members functions.
 * On some (most?) implementations it's not recommended to measure
 * "long" timeperiods, because the error's can accumulate fast.
 * This is probably not a problem profiling code, but could be
 * on if the high resolution timer class is used to initiate
 * actions after a "long" timeout.
 * On Solaris, a scale factor of 1000 should be used because its
 * high-resolution timer returns nanoseconds.  However, on Intel
 * platforms, we use RDTSC which returns the number of clock
 * ticks since system boot.  For a 200MHz cpu, each clock tick
 * is 1/200 of a microsecond; the global_scale_factor_ should
 * therefore be 200 or 200000 if it's in unit/millisecond.
 * On Windows ::QueryPerformanceCounter() is used, which can be a
 * different implementation depending on the used windows HAL
 * (Hardware Abstraction Layer).  On some it uses the PC "timer chip"
 * while it uses RDTSC on others.
 * @note The elapsed time calculations in the print methods use
 * ACE_hrtime_t values.  Those methods do _not_ check for overflow!
 * @note Gabe <begeddov@proaxis.com> raises this issue regarding
 * <ACE_OS::gethrtime>: on multi-processors, the processor that
 * you query for your <timer.stop> value might not be the one
 * you queried for <timer.start>.  Its not clear how much
 * divergence there would be, if any.
 * This issue is not mentioned in the Solaris 2.5.1 gethrtime
 * man page.
 * A RDTSC NOTE: RDTSC is the Intel Pentium read-time stamp counter
 * and is actualy a 64 bit clock cycle counter, which is increased
 * with every cycle.  It has a low overhead and can be read within
 * 16 (pentium) or 32 (pentium II,III,...) cycles, but it doesn't
 * serialize the processor, which could give wrong timings when
 * profiling very short code fragments.
 * Problematic is that some power sensitive devices
 * (laptops for example, but probably also embedded devices),
 * do change the cycle rate while running.
 * Some pentiums can run on (at least) two clock frequency's.
 * Another problem arises with multiprocessor computers, there
 * are reports that the different RDTSC's are not always kept
 * in sync.
 * A windows "timer chip" NOTE: (8254-compatible real-time clock)
 * When ::QueryPerformanceCounter() uses the 8254 it has a
 * frequency off about 1.193 Mhz (or sometimes 3.579 Mhz?) and
 * reading it requires some time (several thousand cycles).
 */
class ACE_Export ACE_High_Res_Timer
{
public:
  // = Initialization method.
  /**
   * global_scale_factor_ is set to @a gsf.  All High_Res_Timers use
   * global_scale_factor_.  This allows applications to set the scale
   * factor just once for all High_Res_Timers.  Check
   *  High_Res_Timer.cpp for the default global_scale_factors for
   * several platforms.  For many platforms (e.g., Solaris), the
   * global_scale_factor_ is set to 1000 so that <scale_factor> need
   * not be set.  Careful, a <scale_factor> of 0 will cause division
   * by zero exceptions.
   * Depending on the platform its units are 1/microsecond or
   * 1/millisecond. Use <ACE_HR_SCALE_CONVERSION> inside calculations
   * instead a hardcoded value.
   */
  static void global_scale_factor (ACE_UINT32 gsf);
  /// Returns the global_scale_factor.
  static ACE_UINT32 global_scale_factor (void);
#ifndef  ACE_HR_SCALE_CONVERSION
#  define ACE_HR_SCALE_CONVERSION (ACE_ONE_SECOND_IN_USECS)
#endif /* ACE_HR_SCALE_CONVERSION */
  /**
   * Sets the global_scale_factor to the value in the @a env
   * environment variable.  Returns 0 on success, -1 on failure.
   * @note If @a env points to string "0" (value zero), this call will fail.
   * This is basically a no-op on CE because there is no concept of
   * environment variable on CE.
   */
  static int get_env_global_scale_factor (const ACE_TCHAR *env
                                          = ACE_TEXT ("ACE_SCALE_FACTOR"));
  /**
   * Set (and return, for info) the global scale factor by sleeping
   * for @a usec and counting the number of intervening clock cycles.
   * Average over @a iterations of @a usec each.  On some platforms,
   * such as Pentiums, this is called automatically during the first
   * ACE_High_Res_Timer construction with the default parameter
   * values.  An application can override that by calling calibrate
   * with any desired parameter values _prior_ to constructing the
   * first ACE_High_Res_Timer instance.
   * Beware for platforms that can change the cycle rate on the fly.
   */
  static ACE_UINT32 calibrate (const ACE_UINT32 usec = 500000,
                               const u_int iterations = 10);
  /// Initialize the timer.
  ACE_High_Res_Timer (void);
  /// Destructor.
  ~ACE_High_Res_Timer (void);
  /// Reinitialize the timer.
  void reset (void);
  /// Start timing.
  void start (const ACE_OS::ACE_HRTimer_Op = ACE_OS::ACE_HRTIMER_GETTIME);
  /// Stop timing.
  void stop (const ACE_OS::ACE_HRTimer_Op = ACE_OS::ACE_HRTIMER_GETTIME);
  /// Set @a tv to the number of microseconds elapsed.
  /**
   *  Could overflow within hours on windows with emulated 64 bit int's
   *  and a fast counter. VC++ and Borland normaly use __int64 and
   *  so normaly don't have this problem.
   */
  void elapsed_time (ACE_Time_Value &tv) const;
  /// Set @a nanoseconds to the number of nanoseconds elapsed.
  /**
   *  Will overflow when measuring more than 194 day's.
   */
  void elapsed_time (ACE_hrtime_t &nanoseconds) const;
#if defined (ACE_HAS_POSIX_TIME)
  /// Returns the elapsed (stop - start) time in a struct timespec
  /// (sec, nsec).
  void elapsed_time (struct timespec &) const;
#endif /* ACE_HAS_POSIX_TIME */
  /// Sets @a usecs to the elapsed (stop - start) time in microseconds.
  /**
   *  Will overflow on windows when measuring more than appox. 2^^54 ticks.
   *  Is still more than 48 days with a 4 Ghz counter.
   */
  void elapsed_microseconds (ACE_hrtime_t &usecs) const;
  /// Start incremental timing.
  void start_incr (const ACE_OS::ACE_HRTimer_Op = ACE_OS::ACE_HRTIMER_GETTIME);
  /// Stop incremental timing.
  void stop_incr (const ACE_OS::ACE_HRTimer_Op = ACE_OS::ACE_HRTIMER_GETTIME);
  /// Set @a tv to the number of microseconds elapsed between all calls
  /// to start_incr and stop_incr.
  void elapsed_time_incr (ACE_Time_Value &tv) const;
  /// Set <nsec> to the number of nanoseconds elapsed between all calls
  /// to start_incr and stop_incr.
  void elapsed_time_incr (ACE_hrtime_t &nanoseconds) const;
#if !defined (ACE_HAS_WINCE)
  // @@ WINCE These two functions are currently not supported on Windows CE.
  //    However, we should probably use the handle and ACE_Log_Msg to
  //    print out the result.
  /// Print total time.
  /// @note only use <print_total> if incremental timings had been used!
  void print_total (const ACE_TCHAR *message,
                    const int iterations = 1,
                    ACE_HANDLE handle = ACE_STDOUT) const;
  /// Print average time.
  void print_ave (const ACE_TCHAR *message,
                  const int iterations = 1,
                  ACE_HANDLE handle = ACE_STDOUT) const;
#endif /* !ACE_HAS_WINCE */
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
  /**
   * Get the current "time" as the high resolution counter at this time.
   * This is intended to be useful for supplying to a ACE_Timer_Queue
   * as the gettimeofday function, thereby basing the timer calculations
   * on the high res timer rather than wall clock time.
   */
  static ACE_Time_Value gettimeofday_hr (void);
  /**
   * @deprecated THIS FUNCTION IS DEPRECATED.  PLEASE USE
   * <ACE_OS::gettimeofday> INSTEAD!  Calls <ACE_High_Res_Timer::hrtime_to_tv>
   * passing <ACE_OS::gethrtime>.  This function can be used to parameterize
   * objects such as <ACE_Timer_Queue::gettimeofday>.  If
   * <global_scale_factor_> is not set, and we're on a platform that
   * requires <global_scale_factor_> (e.g., Win32),
   * ACE_OS::gettimeofday will be used instead of <ACE_OS::gethrtime>.
   * This allows applications on Intel to use <High_Res_Timer> even
   * when <global_scale_factor> is not set.  However, setting the
   * <global_scale_factor_> appropriately will result in the finest
   * resolution possible.
   */
  static ACE_Time_Value gettimeofday (const ACE_OS::ACE_HRTimer_Op =
                                        ACE_OS::ACE_HRTIMER_GETTIME);
  /// Converts an @a hrt to @a tv using global_scale_factor_.
  static void hrtime_to_tv (ACE_Time_Value &tv,
                            const ACE_hrtime_t hrt);
#if defined (linux)
  /**
   * This is used to find out the Mhz of the machine for the scale
   * factor.  If there are any problems getting it, we just return 1
   * (the default).
   */
  static ACE_UINT32 get_cpuinfo (void);
#endif /* defined (linux) */
private:
  /**
   * For internal use: gets the high-resolution time using
   * <ACE_OS::gethrtime>.  Except on platforms that require that the
   * <global_scale_factor_> be set, such as ACE_WIN32, uses the
   * low-resolution clock if the <global_scale_factor_> has not been
   * set.
   */
  static ACE_hrtime_t gettime (const ACE_OS::ACE_HRTimer_Op =
                                 ACE_OS::ACE_HRTIMER_GETTIME);
  /// Calculate the difference between two ACE_hrtime_t values. It is assumed
  /// that the end time is later than start time, so if end is a smaller
  /// value, the time counter has wrapped around.
  static ACE_hrtime_t elapsed_hrtime (const ACE_hrtime_t end,
                                      const ACE_hrtime_t start);
  /// Starting time.
  ACE_hrtime_t start_;
  /// Ending time.
  ACE_hrtime_t end_;
  /// Total elapsed time.
  ACE_hrtime_t total_;
  /// Start time of incremental timing.
  ACE_hrtime_t start_incr_;
  /// Converts ticks to microseconds.  That is, ticks /
  /// global_scale_factor_ == microseconds.
  static ACE_UINT32 global_scale_factor_;
  /**
   * Indicates the status of the global scale factor,
   * 0  = hasn't been set
   * 1  = been set
   * -1 = HR timer not supported
   */
  static int global_scale_factor_status_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/High_Res_Timer.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_HIGH_RES_TIMER_H */

