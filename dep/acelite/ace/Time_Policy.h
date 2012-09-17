#ifndef ACE_TIME_POLICY_H
#define ACE_TIME_POLICY_H
// -*- C++ -*-
/**
 *  @file Time_Policy.h
 *
 *  $Id: Time_Policy.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *  @author Carlos O'Ryan <coryan@atdesk.com>
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
 * @class ACE_System_Time_Policy
 *
 * @brief Implement the system time policy for ACE.
 *
 * The most common time policy is to simply use
 * ACE_OS::gettimeofday(), this class implements that policy, i.e., it
 * simply calls that function.
 */
class ACE_Export ACE_System_Time_Policy
{
public:
  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_System_Time_Policy> operator() () const;

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
};

/**
 * @class ACE_HR_Time_Policy
 *
 * @brief Implement a time policy based on the ACE Highres timer.
 *
 */
class ACE_Export ACE_HR_Time_Policy
{
public:
  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_HR_Time_Policy> operator() () const;

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
};

/**
 * @class ACE_FPointer_Timer_Policy
 *
 * @brief Implement a time policy based on a function pointer.
 *
 * This time policy allows dynamic changes to the source of time by
 * using a function pointer.
 */
class ACE_Export ACE_FPointer_Time_Policy
{
public:
  /**
   * @brief Default constructor uses ACE_OS::gettimeofday()
   *
   * ACE_T requires a default constructor that leaves the
   * policy in a functional state.  Therefore, a null pointer would
   * not be desirable, in other words, we need a non-trivial default
   * constructor.
   */
  ACE_FPointer_Time_Policy();

  /**
   * @typedef FPtr
   *
   * Short-hand for the right type of pointer to function.
   */
  typedef ACE_Time_Value (*FPtr)();

  /**
   * @brief Constructor from a pointer to function.
   *
   * Construct from a pointer to function.
   */
  ACE_FPointer_Time_Policy(FPtr f);

  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_FPointer_Time_Policy> operator()() const;

  /// Satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
private:
  FPtr function_;
};

class ACE_Dynamic_Time_Policy_Base; // forward decl

/**
 * @class ACE_Delegating_Time_Policy
 *
 * @brief Implement a time policy that delegates to a dynamic
 *        time policy.
 */
class ACE_Export ACE_Delegating_Time_Policy
{
public:
  ACE_Delegating_Time_Policy (ACE_Dynamic_Time_Policy_Base const * delegate = 0);

  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_Delegating_Time_Policy> operator()() const;

  /// Set delegate
  void set_delegate (ACE_Dynamic_Time_Policy_Base const * delegate);

  /// Copy policy
  ACE_Delegating_Time_Policy& operator =(ACE_Delegating_Time_Policy const & pol);

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
private:
  ACE_Dynamic_Time_Policy_Base const * delegate_;
};

/**
 * @class ACE_Dynamic_Time_Policy_base
 *
 * @brief Abstract base class for dynamically loaded and/or shared
 *        time policies.
 *
 */
class ACE_Export ACE_Dynamic_Time_Policy_Base
{
public:
  virtual ~ACE_Dynamic_Time_Policy_Base ();

  /// Return the current time according to this policy
  ACE_Time_Value_T<ACE_Delegating_Time_Policy> operator()() const;

  /// Noop. Just here to satisfy backwards compatibility demands.
  void set_gettimeofday (ACE_Time_Value (*gettimeofday)(void));
protected:
  /// Return the current time according to policy implementation.
  virtual ACE_Time_Value_T<ACE_Delegating_Time_Policy> gettimeofday () const = 0;
};

/// Temporarily, for backwards compatibility reasons, this will
/// be the default time policy. In time to be replaced by
/// ACE_System_Time_Policy.
typedef ACE_FPointer_Time_Policy ACE_Default_Time_Policy;

#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
template class ACE_Export ACE_Time_Value_T<ACE_System_Time_Policy>;
template class ACE_Export ACE_Time_Value_T<ACE_HR_Time_Policy>;
template class ACE_Export ACE_Time_Value_T<ACE_FPointer_Time_Policy>;
template class ACE_Export ACE_Time_Value_T<ACE_Delegating_Time_Policy>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Time_Policy.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_TIME_POLICY_H */
