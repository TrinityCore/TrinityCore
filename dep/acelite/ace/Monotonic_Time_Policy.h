#ifndef ACE_MONOTONIC_TIME_POLICY_H
#define ACE_MONOTONIC_TIME_POLICY_H
// -*- C++ -*-
/**
 *  @file Monotonic_Time_Policy.h
 *
 *  $Id: Monotonic_Time_Policy.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *  @author Martin Corino <mcorino@remedy.nl>
 */
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#include /**/ "ace/Time_Value_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Monotonic_Time_Policy
 *
 * @brief Implement a monotonic time policy for ACE.
 *
 * This class implements support for returning monotonic time values
 * on platforms that support that.
 * If a platform does not support monotonic time the policy returns
 * ACE_Time_Value::zero.
 */
class ACE_Export ACE_Monotonic_Time_Policy
{
public:
  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_Monotonic_Time_Policy> operator() () const;

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Monotonic_Time_Policy.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_MONOTONIC_TIME_POLICY_H */
