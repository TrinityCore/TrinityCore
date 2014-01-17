// -*- C++ -*-

//=============================================================================
/**
 *  @file    Time_Policy_T.h
 *
 *  $Id: Time_Policy_T.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *  @author Martin Corino <mcorino@remedy.nl>
 */
//=============================================================================

#ifndef ACE_TIME_POLICY_T_H
#define ACE_TIME_POLICY_T_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Policy.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Time_Policy_T
 *
 * @brief Template class implementing a dynamic time policy based on
 *        another time policy
 *
 */
template <typename TIME_POLICY>
class ACE_Time_Policy_T : public ACE_Dynamic_Time_Policy_Base
{
public:
  ACE_Time_Policy_T (TIME_POLICY const & time_policy = TIME_POLICY());
  virtual ~ACE_Time_Policy_T ();

  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_Delegating_Time_Policy> operator()() const;

  /// Allows applications to control how the timer queue gets the time
  /// of day.
  void set_time_policy(TIME_POLICY const & time_policy);

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
protected:
  /// Return the current time according to policy implementation.
  virtual ACE_Time_Value_T<ACE_Delegating_Time_Policy> gettimeofday () const;

private:
  /// The policy to return the current time of day
  TIME_POLICY time_policy_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#if defined (__ACE_INLINE__)
#include "ace/Time_Policy_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Time_Policy_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Time_Policy_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */


#endif /* ACE_TIME_POLICY_T_H */
