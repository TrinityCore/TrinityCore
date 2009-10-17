/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Pair_T.h
 *
 *  $Id: Pair_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Irfan Pyarali <irfan@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_PAIR_T_H
#define ACE_PAIR_T_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
/**
 * @class ACE_Pair
 *
 * @brief Defines a pair.
 *
 * Similar to the STL pair.
 */
template <class T1, class T2>
class ACE_Pair
{
public:
  // = Traits.
  typedef T1 first_type;
  typedef T2 second_type;
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Pair (const T1 &t1,
            const T2 &t2);
  /// Default constructor.
  ACE_Pair (void);
  /// Get first.
  T1 &first (void);
  const T1 &first (void) const;
  /// Set first.
  void first (const T1 &t1);
  /// Get second.
  T2 &second (void);
  const T2 &second (void) const;
  /// Set second.
  void second (const T2 &t2);
  // Compare pairs.
  bool operator== (const ACE_Pair<T1, T2> &rhs) const;
protected:
  /// First.
  T1 first_;
  /// Second.
  T2 second_;
};
/**
 * @class ACE_Reference_Pair
 *
 * @brief Defines a pair that only hold references.
 *
 * Similar to the STL pair (but restricted to holding references
 * and not copies).
 */
template <class T1, class T2>
class ACE_Reference_Pair
{
public:
  // = Traits.
  typedef T1 first_type;
  typedef T2 second_type;
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Reference_Pair (T1 &t1,
                      T2 &t2);
  /// Access first.
  T1 &first (void) const;
  /// Access second.
  T2 &second (void) const;
  // Compare pairs.
  bool operator== (const ACE_Reference_Pair<T1, T2> &rhs) const;
protected:
  /// First.
  T1 &first_;
  /// Second.
  T2 &second_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Pair_T.inl"
#endif /* __ACE_INLINE__ */
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Pair_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Pair_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_PAIR_T_H */

