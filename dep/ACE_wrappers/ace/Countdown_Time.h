// -*- C++ -*-
//=============================================================================
/**
 *  @file    Countdown_Time.h
 *
 *  $Id: Countdown_Time.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_COUNTDOWN_TIME_H
#define ACE_COUNTDOWN_TIME_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Time_Value.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Countdown_Time
 *
 * @brief Keeps track of the amount of elapsed time.
 *
 * This class has a side-effect on the @c max_wait_time -- every
 * time the stop() method is called the @c max_wait_time is
 * updated.
 */
class ACE_Export ACE_Countdown_Time
{
public:
  /// Cache the @a max_wait_time and call @c start().
  ACE_Countdown_Time (ACE_Time_Value *max_wait_time);
  /// Destructor, makes sure the max_wait_time that got passed as pointer
  /// to the constructor is updated with the time elapsed.
  ~ACE_Countdown_Time (void);
  /// Cache the current time and enter a start state.
  void start (void);
  /// Subtract the elapsed time from max_wait_time_ and enter a stopped
  /// state.
  void stop (void);
  /// Calls stop and then start.  max_wait_time_ is modified by the
  /// call to stop.
  void update (void);
  /// Returns true if we've already been stopped, else false.
  bool stopped (void) const;
private:
  /// Maximum time we were willing to wait.
  ACE_Time_Value *max_wait_time_;
  /// Beginning of the start time.
  ACE_Time_Value start_time_;
  /// Keeps track of whether we've already been stopped.
  bool stopped_;
  // Prevent copying
  ACE_Countdown_Time (const ACE_Countdown_Time &);
  ACE_Countdown_Time &operator= (const ACE_Countdown_Time &);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif /* ACE_COUNTDOWN_TIME_H */

