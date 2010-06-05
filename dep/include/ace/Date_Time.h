// -*- C++ -*-

//==========================================================================
/**
 *  @file    Date_Time.h
 *
 *  $Id: Date_Time.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Tim Harrison (harrison@cs.wustl.edu) (and he's darn proud of this ;-))
 *
 */
//==========================================================================

#ifndef ACE_DATE_TIME_H
#define ACE_DATE_TIME_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

class ACE_Time_Value;

/**
 * @class ACE_Date_Time
 *
 * @brief System independent representation of date and time.
 */
class ACE_Export ACE_Date_Time
{
public:
  /// Constructor initializes current time/date info.
  ACE_Date_Time (void);

  /// Constructor initializes with the given ACE_Time_Value
  explicit ACE_Date_Time (const ACE_Time_Value& timevalue);

  /// Constructor with init values, no check for validy
  /// Set/get portions of ACE_Date_Time, no check for validity.
  ACE_Date_Time (long day,
                 long month = 0,
                 long year = 0,
                 long hour = 0,
                 long minute = 0,
                 long second = 0,
                 long microsec = 0,
                 long wday = 0);

  /// Update to the current time/date.
  void update (void);

  /// Update to the given ACE_Time_Value
  void update (const ACE_Time_Value& timevalue);

  /// Get day.
  long day (void) const;

  /// Set day.
  void day (long day);

  /// Get month.
  long month (void) const;

  /// Set month.
  void month (long month);

  /// Get year.
  long year (void) const;

  /// Set year.
  void year (long year);

  /// Get hour.
  long hour (void) const;

  /// Set hour.
  void hour (long hour);

  /// Get minute.
  long minute (void) const;

  /// Set minute.
  void minute (long minute);

  /// Get second.
  long second (void) const;

  /// Set second.
  void second (long second);

  /// Get microsec.
  long microsec (void) const;

  /// Set microsec.
  void microsec (long microsec);

  /// Get weekday.
  long weekday (void) const;

  /// Set weekday.
  void weekday (long wday);

private:
  long day_;
  long month_;
  long year_;
  long hour_;
  long minute_;
  long second_;
  long microsec_;
  long wday_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Date_Time.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_DATE_TIME_H */

