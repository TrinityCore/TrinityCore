// -*- C++ -*-

//=============================================================================
/**
 *  @file    Atomic_Op_GCC_T.h
 *
 *  $Id: Atomic_Op_GCC_T.h 89339 2010-03-05 12:20:47Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl
 */
//=============================================================================

#ifndef ACE_ATOMIC_OP_GCC_T_H
#define ACE_ATOMIC_OP_GCC_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Thread_Mutex.h"
#include "ace/ACE_export.h"

#if defined (ACE_HAS_GCC_ATOMIC_BUILTINS) && (ACE_HAS_GCC_ATOMIC_BUILTINS == 1)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @brief Specialization of ACE_Atomic_Op for platforms that
 *        support atomic integer operations.
 *
 * Specialization of ACE_Atomic_Op for platforms that support atomic
 * integer operations.
 */
template<typename T>
class ACE_Export ACE_Atomic_Op_GCC
{
public:
  /// Atomically pre-increment @c value_.
  T operator++ (void);

  /// Atomically post-increment @c value_.
  T operator++ (int);

  /// Atomically increment @c value_ by rhs.
  T operator+= (T rhs);

  /// Atomically pre-decrement @c value_.
  T operator-- (void);

  /// Atomically post-decrement @c value_.
  T operator-- (int);

  /// Atomically decrement @c value_ by rhs.
  T operator-= (T rhs);

  /// Atomically compare @c value_ with rhs.
  bool operator== (T rhs) const;

  /// Atomically compare @c value_ with rhs.
  bool operator!= (T rhs) const;

  /// Atomically check if @c value_ greater than or equal to rhs.
  bool operator>= (T rhs) const;

  /// Atomically check if @c value_ greater than rhs.
  bool operator> (T rhs) const;

  /// Atomically check if @c value_ less than or equal to rhs.
  bool operator<= (T rhs) const;

  /// Atomically check if @c value_ less than rhs.
  bool operator< (T rhs) const;

  /// Explicitly return @c value_.
  T value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Explicitly return @c value_ (by reference).
  volatile T &value_i (void);

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

protected:
  /// Atomically assign rhs to @c value_.
  ACE_Atomic_Op_GCC<T> &operator= (T rhs);

  /// Atomically assign <rhs> to @c value_.
  ACE_Atomic_Op_GCC<T> &operator= (const ACE_Atomic_Op_GCC<T> &rhs);

  /// Initialize @c value_ to 0.
  ACE_Atomic_Op_GCC (void);

  /// Initialize @c value_ to c.
  ACE_Atomic_Op_GCC (T c);

  /// Manage copying...
  ACE_Atomic_Op_GCC (const ACE_Atomic_Op_GCC<T> &c);

private:

  // This function cannot be supported by this template specialization.
  // If you need access to an underlying lock, use the ACE_Atomic_Op_Ex
  // template instead.
  ACE_Thread_Mutex &mutex (void);

private:

  /// Current object decorated by the atomic op.
  volatile T value_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Atomic_Op_GCC_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Atomic_Op_GCC_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Atomic_Op_GCC_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */


#endif /* ACE_HAS_GCC_ATOMIC_BUILTINS */

#include /**/ "ace/post.h"
#endif /*ACE_ATOMIC_OP_GCC_T_H*/
