// -*- C++ -*-

//=============================================================================
/**
 *  @file    Atomic_Op_T.h
 *
 *  $Id: Atomic_Op_T.h 92353 2010-10-25 06:34:35Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================

#ifndef ACE_ATOMIC_OP_T_H
#define ACE_ATOMIC_OP_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename TYPE>
struct ACE_Type_Traits
{
  typedef TYPE const & parameter_type;
};

template<>
struct ACE_Type_Traits<bool>
{
  typedef bool parameter_type;
};

template<>
struct ACE_Type_Traits<char>
{
  typedef char parameter_type;
};

template<>
struct ACE_Type_Traits<signed char>
{
  typedef signed char parameter_type;
};

template<>
struct ACE_Type_Traits<unsigned char>
{
  typedef unsigned char parameter_type;
};

template<>
struct ACE_Type_Traits<short>
{
  typedef short parameter_type;
};

template<>
struct ACE_Type_Traits<unsigned short>
{
  typedef unsigned short parameter_type;
};

template<>
struct ACE_Type_Traits<int>
{
  typedef int parameter_type;
};

template<>
struct ACE_Type_Traits<unsigned int>
{
  typedef unsigned int parameter_type;
};

template<>
struct ACE_Type_Traits<long>
{
  typedef long parameter_type;
};

template<>
struct ACE_Type_Traits<unsigned long>
{
  typedef unsigned long parameter_type;
};

#ifndef ACE_LACKS_LONGLONG_T
template<>
struct ACE_Type_Traits<long long>
{
  typedef long long parameter_type;
};
#endif  /* !ACE_LACKS_LONGLONG_T */

#if !defined (ACE_LACKS_LONGLONG_T) \
  && !defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
template<>
struct ACE_Type_Traits<unsigned long long>
{
  typedef unsigned long long parameter_type;
};
#endif  /* !ACE_LACKS_LONGLONG_T && !ACE_LACKS_UNSIGNEDLONGLONG_T */

template<>
struct ACE_Type_Traits<float>
{
  typedef float parameter_type;
};

template<>
struct ACE_Type_Traits<double>
{
  typedef double parameter_type;
};

template<>
struct ACE_Type_Traits<long double>
{
  typedef long double parameter_type;
};

template<typename TYPE>
struct ACE_Type_Traits<TYPE*>
{
  typedef TYPE* parameter_type;
};

/**
 * @class ACE_Atomic_Op_Ex
 *
 * @brief Transparently parameterizes synchronization into basic
 * arithmetic operations.
 *
 * This class is described in an article in the July/August 1994
 * issue of the C++ Report magazine.  It implements a
 * templatized version of the Decorator pattern from the GoF book.
 *
 * ACE_Atomic_Op_Ex objects must be constructed with a reference
 * to an existing lock. A single lock can be shared between
 * multiple ACE_Atomic_Op_Ex objects. If you do not require this
 * ability consider using the ACE_Atomic_Op class instead, which
 * may be able to take advantage of platform-specific
 * optimisations to provide atomic operations without requiring a
 * lock.
 */
template <class ACE_LOCK, typename TYPE>
class ACE_Atomic_Op_Ex
{
public:

  typedef typename ACE_Type_Traits<TYPE>::parameter_type arg_type;

  // = Initialization methods.

  /// Initialize @c value_ to 0.
  ACE_Atomic_Op_Ex (ACE_LOCK & mtx);

  /// Initialize @c value_ to c.
  ACE_Atomic_Op_Ex (ACE_LOCK & mtx, arg_type c);

  // = Accessors.

  /// Atomically pre-increment @c value_.
  TYPE operator++ (void);

  /// Atomically post-increment @c value_.
  TYPE operator++ (int);

  /// Atomically increment @c value_ by rhs.
  TYPE operator+= (arg_type rhs);

  /// Atomically pre-decrement @c value_.
  TYPE operator-- (void);

  /// Atomically post-decrement @c value_.
  TYPE operator-- (int);

  /// Atomically decrement @c value_ by rhs.
  TYPE operator-= (arg_type rhs);

  /// Atomically compare @c value_ with rhs.
  bool operator== (arg_type rhs) const;

  /// Atomically compare @c value_ with rhs.
  bool operator!= (arg_type rhs) const;

  /// Atomically check if @c value_ greater than or equal to rhs.
  bool operator>= (arg_type rhs) const;

  /// Atomically check if @c value_ greater than rhs.
  bool operator> (arg_type rhs) const;

  /// Atomically check if @c value_ less than or equal to rhs.
  bool operator<= (arg_type rhs) const;

  /// Atomically check if @c value_ less than rhs.
  bool operator< (arg_type rhs) const;

  /// Atomically assign rhs to @c value_.
  ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> &operator= (arg_type rhs);

  /// Atomically assign <rhs> to @c value_.
  ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> &operator= (
    ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> const & rhs);

  /// Explicitly return @c value_.
  TYPE value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /// Manage copying...
  ACE_Atomic_Op_Ex (ACE_Atomic_Op_Ex<ACE_LOCK, TYPE> const &);

  /**
   * Returns a reference to the underlying ACE_LOCK.  This makes it
   * possible to acquire the lock explicitly, which can be useful in
   * some cases if you instantiate the ACE_Atomic_Op_Ex with an
   * ACE_Recursive_Mutex or ACE_Process_Mutex.
   *
   * @note The right name would be lock_, but HP/C++ will choke on that!
   */
  ACE_LOCK & mutex (void);

  /**
   * Explicitly return @c value_ (by reference).  This gives the user
   * full, unrestricted access to the underlying value.  This method
   * will usually be used in conjunction with explicit access to the
   * lock.  Use with care ;-)
   */
  TYPE & value_i (void);

private:
  /// Type of synchronization mechanism.
  ACE_LOCK & mutex_;

  /// Current object decorated by the atomic op.
  TYPE value_;
};

/**
 * @class ACE_Atomic_Op
 *
 * @brief Transparently parameterizes synchronization into basic
 * arithmetic operations.
 *
 * This class is described in an article in the July/August 1994
 * issue of the C++ Report magazine.  It implements a
 * templatized version of the Decorator pattern from the GoF book.
 *
 * Certain platforms may provide a template specialization for
 * ACE_Atomic_Op <ACE_Thread_Mutex, long> that provides optimized
 * atomic integer operations without actually requiring a mutex.
 */
template <class ACE_LOCK, typename TYPE>
class ACE_Atomic_Op
{
public:

  typedef typename ACE_Type_Traits<TYPE>::parameter_type arg_type;

  /// Initialize @c value_ to 0.
  ACE_Atomic_Op (void);

  /// Initialize @c value_ to c.
  ACE_Atomic_Op (arg_type c);

  /// Manage copying...
  ACE_Atomic_Op (ACE_Atomic_Op<ACE_LOCK, TYPE> const & c);

  /// Atomically assign @a rhs to @c value_.
  ACE_Atomic_Op<ACE_LOCK, TYPE> & operator= (arg_type rhs);

  /// Atomically assign @a rhs to @c value_.
  ACE_Atomic_Op<ACE_LOCK, TYPE> & operator= (
    ACE_Atomic_Op<ACE_LOCK, TYPE> const & rhs);

  /// Atomically pre-increment @c value_.
  TYPE operator++ (void);

  /// Atomically post-increment @c value_.
  TYPE operator++ (int);

  /// Atomically increment @c value_ by rhs.
  TYPE operator+= (arg_type rhs);

  /// Atomically pre-decrement @c value_.
  TYPE operator-- (void);

  /// Atomically post-decrement @c value_.
  TYPE operator-- (int);

  /// Atomically decrement @c value_ by @a rhs.
  TYPE operator-= (arg_type rhs);

  /// Atomically compare @c value_ with @a rhs.
  bool operator== (arg_type rhs) const;

  /// Atomically compare @c value_ with @a rhs.
  bool operator!= (arg_type rhs) const;

  /// Atomically check if @c value_ greater than or equal to @a rhs.
  bool operator>= (arg_type rhs) const;

  /// Atomically check if @c value_ greater than @a rhs.
  bool operator> (arg_type rhs) const;

  /// Atomically check if @c value_ less than or equal to @a rhs.
  bool operator<= (arg_type rhs) const;

  /// Atomically check if @c value_ less than @a rhs.
  bool operator< (arg_type rhs) const;

  /// Explicitly return @c value_.
  TYPE value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /**
   * Explicitly return @c value_ (by reference).  This gives the user
   * full, unrestricted access to the underlying value.  This method
   * will usually be used in conjunction with explicit access to the
   * lock.  Use with care ;-)
   */
  TYPE & value_i (void);

private:
  /// Type of synchronization mechanism.
  ACE_LOCK own_mutex_;

  /// Underlying atomic op implementation.
  ACE_Atomic_Op_Ex <ACE_LOCK, TYPE> impl_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Atomic_Op_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Atomic_Op_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Atomic_Op_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /*ACE_ATOMIC_OP_T_H*/
