// -*- C++ -*-

//=============================================================================
/**
 *  @file    Time_Value_T.h
 *
 *  $Id: Time_Value_T.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *  @author Martin Corino <mcorino@remedy.nl>
 */
//=============================================================================

#ifndef ACE_TIME_VALUE_T_H
#define ACE_TIME_VALUE_T_H

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Time_Value
 *
 * @brief Operations on "timeval" structures, which express time in
 * seconds (secs) and microseconds (usecs).
 *
 * This class centralizes all the time related processing in
 * ACE.  These time values are typically used in conjunction with OS
 * mechanisms like <select>, <poll>, or <cond_timedwait>.
 */
template <class TIME_POLICY>
class ACE_Time_Value_T : public ACE_Time_Value
{
public:
  typedef TIME_POLICY time_policy_t;

  // = Initialization methods.

  /// Default Constructor.
  ACE_Time_Value_T (void) {}

  /// Constructor.
  explicit ACE_Time_Value_T (time_t sec, suseconds_t usec = 0)
    : ACE_Time_Value (sec, usec) {}

  // = Methods for converting to/from various time formats.

  /// Construct the ACE_Time_Value from a timeval.
  explicit ACE_Time_Value_T (const struct timeval &t)
    : ACE_Time_Value (t) {}

  /// Construct the ACE_Time_Value object from a timespec_t.
  explicit ACE_Time_Value_T (const timespec_t &t)
    : ACE_Time_Value (t) {}

  /// Construct from ACE_Time_Value_T<TIME_POLICY>
  ACE_Time_Value_T(const ACE_Time_Value_T<TIME_POLICY>& tv)
    : ACE_Time_Value (tv),
      time_policy_ (tv.time_policy_)
  {}

  /// Construct from ACE_Time_Value
  explicit ACE_Time_Value_T(const ACE_Time_Value& tv,
                            const TIME_POLICY& tp = TIME_POLICY ())
    : ACE_Time_Value (tv),
      time_policy_ (tp)
  {}

  /// Destructor
  virtual ~ACE_Time_Value_T () {}

  /// Add @a tv to this.
  ACE_Time_Value_T<TIME_POLICY> &operator += (const ACE_Time_Value &tv);

  /// Add @a tv to this.
  ACE_Time_Value_T<TIME_POLICY> &operator += (time_t tv);

  /// Assign @ tv to this
  ACE_Time_Value_T<TIME_POLICY> &operator = (const ACE_Time_Value_T<TIME_POLICY> &tv);

  /// Assign @ tv to this
  ACE_Time_Value_T<TIME_POLICY> &operator = (const ACE_Time_Value &tv);

  /// Assign @ tv to this
  ACE_Time_Value_T<TIME_POLICY> &operator = (time_t tv);

  /// Subtract @a tv to this.
  ACE_Time_Value_T<TIME_POLICY> &operator -= (const ACE_Time_Value &tv);

  /// Subtract @a tv to this.
  ACE_Time_Value_T<TIME_POLICY> &operator -= (time_t tv);

  /**
    \brief Multiply the time value by the @a d factor.
    \note The result of the operator is valid for results from range
    < (ACE_INT32_MIN, -999999), (ACE_INT32_MAX, 999999) >. Result
    outside this range are saturated to a limit.
     */
  ACE_Time_Value_T<TIME_POLICY> &operator *= (double d);

  /// Increment microseconds as postfix.
  /**
   * @note The only reason this is here is to allow the use of ACE_Atomic_Op
   * with ACE_Time_Value.
   */
  ACE_Time_Value_T<TIME_POLICY> operator++ (int);

  /// Increment microseconds as prefix.
  /**
   * @note The only reason this is here is to allow the use of ACE_Atomic_Op
   * with ACE_Time_Value.
   */
  ACE_Time_Value_T<TIME_POLICY> &operator++ (void);

  /// Decrement microseconds as postfix.
  /**
   * @note The only reason this is here is to allow the use of ACE_Atomic_Op
   * with ACE_Time_Value.
   */
  ACE_Time_Value_T<TIME_POLICY> operator-- (int);

  /// Decrement microseconds as prefix.
  /**
   * @note The only reason this is here is to allow the use of ACE_Atomic_Op
   * with ACE_Time_Value.
   */
  ACE_Time_Value_T<TIME_POLICY> &operator-- (void);

  /// Get current time of day according to time policy.
  /**
   * @return  Time value representing current time of day according to time policy.
   */
  virtual ACE_Time_Value now () const;

  /// Converts absolute time value to time value relative to current time of day.
  /**
   * @return  Relative time value.
   *
   * @note    This method uses it's time_policy_ member to get the current
   *          time of day.
   *          The developer is responsible for making sure this is an absolute
   *          time value compatible with the active time policy.
   *          Note that the returned time value has no notion of the time policy
   *          on which it is based anymore.
   */
  virtual ACE_Time_Value to_relative_time () const;

  /// Converts relative time value to absolute time value based on current time of day.
  /**
   * @return  Absolute time value.
   *
   * @note    This method uses it's time_policy_ member to get the current
   *          time of day.
   *          The developer is responsible for making sure this is a relative
   *          time value.
   *          Note that the returned time value has no notion of the time policy
   *          on which it is based anymore.
   */
  virtual ACE_Time_Value to_absolute_time () const;

  /// Duplicates this time value (incl. time policy).
  /**
   * @return  Dynamically allocated time value copy.
   *
   * @note    The caller is responsible for freeing the copy when it's not needed
   *          anymore.
   */
  virtual ACE_Time_Value * duplicate () const;

private:
  TIME_POLICY time_policy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Time_Value_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Time_Value_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Time_Value_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TIME_VALUE_T_H */
