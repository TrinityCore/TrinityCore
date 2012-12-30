// -*- C++ -*-

//=============================================================================
/**
 *  @file    Atomic_Op.h
 *
 *  $Id: Atomic_Op.h 96147 2012-09-15 01:13:21Z shuston $
 *
 *  @author Douglas C. Schmidt <schmidt@uci.edu>
 */
//=============================================================================

#ifndef ACE_ATOMIC_OP_H
#define ACE_ATOMIC_OP_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Thread_Mutex.h"

// Include the templates here.
#include "ace/Atomic_Op_T.h"

// Determine whether builtin atomic op support is
// available on this platform.
#if defined (ACE_HAS_THREADS)
# if defined (WIN32)
#  if defined (ACE_HAS_INTRINSIC_INTERLOCKED)
#   define ACE_HAS_BUILTIN_ATOMIC_OP
#  endif /* ACE_HAS_INTRINSIC_INTERLOCKED */
#  if defined (ACE_HAS_INTERLOCKED_EXCHANGEADD)
#   define ACE_HAS_BUILTIN_ATOMIC_OP
#  else /* ACE_HAS_INTERLOCKED_EXCHANGEADD */
    // Inline assembly emulation of InterlockedExchangeAdd
    // is currently only implemented for MSVC (x86 only) and Borland.
#   if (defined (_MSC_VER) && defined (_M_IX86)) || defined (__BORLANDC__)
#    define ACE_HAS_BUILTIN_ATOMIC_OP
#   endif /* _MSC_VER || __BORLANDC__ */
#  endif /* ACE_HAS_INTERLOCKED_EXCHANGEADD */
# elif defined (ACE_HAS_INTEL_ASSEMBLY)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# elif defined (ACE_HAS_VXATOMICLIB)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# elif defined (ACE_HAS_SOLARIS_ATOMIC_LIB) && !defined (ACE_HAS_BUILTIN_ATOMIC_OP)
#  define ACE_HAS_BUILTIN_ATOMIC_OP
# endif /* WIN32 */
#endif /* ACE_HAS_THREADS */

// If we have the GCC Atomic builtin support, use it
#if defined (ACE_HAS_GCC_ATOMIC_BUILTINS) && (ACE_HAS_GCC_ATOMIC_BUILTINS == 1)
# undef ACE_HAS_BUILTIN_ATOMIC_OP
#endif

// Include the templates here.
#include "ace/Atomic_Op_GCC_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_BUILTIN_ATOMIC_OP)

/**
 * @brief Specialization of ACE_Atomic_Op for platforms that
 *        support atomic integer operations.
 *
 * Specialization of ACE_Atomic_Op for platforms that support atomic
 * integer operations.
 */
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, long>
{
public:
  /// Initialize @c value_ to 0.
  ACE_Atomic_Op (void);

  /// Initialize @c value_ to c.
  ACE_Atomic_Op (long c);

  /// Manage copying...
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &c);

  /// Atomically pre-increment @c value_.
  long operator++ (void);

  /// Atomically post-increment @c value_.
  long operator++ (int);

  /// Atomically increment @c value_ by rhs.
  long operator+= (long rhs);

  /// Atomically pre-decrement @c value_.
  long operator-- (void);

  /// Atomically post-decrement @c value_.
  long operator-- (int);

  /// Atomically decrement @c value_ by rhs.
  long operator-= (long rhs);

  /// Atomically compare @c value_ with rhs.
  bool operator== (long rhs) const;

  /// Atomically compare @c value_ with rhs.
  bool operator!= (long rhs) const;

  /// Atomically check if @c value_ greater than or equal to rhs.
  bool operator>= (long rhs) const;

  /// Atomically check if @c value_ greater than rhs.
  bool operator> (long rhs) const;

  /// Atomically check if @c value_ less than or equal to rhs.
  bool operator<= (long rhs) const;

  /// Atomically check if @c value_ less than rhs.
  bool operator< (long rhs) const;

  /// Atomically assign rhs to @c value_.
  ACE_Atomic_Op<ACE_Thread_Mutex, long> &operator= (long rhs);

  /// Atomically assign <rhs> to @c value_.
  ACE_Atomic_Op<ACE_Thread_Mutex, long> &operator= (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &rhs);

  /// Exchange value with @a newval.
  long exchange (long newval);

  /// Explicitly return @c value_.
  long value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Explicitly return @c value_ (by reference).
  volatile long &value_i (void);

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /// Used during ACE object manager initialization to optimize the fast
  /// atomic op implementation according to the number of CPUs.
  static void init_functions (void);

private:

  /// This function cannot be supported by this template specialization.
  /// If you need access to an underlying lock, use the ACE_Atomic_Op_Ex
  /// template instead.
  ACE_Thread_Mutex &mutex (void);

private:

  /// Current object decorated by the atomic op.
  volatile long value_;

  /// Pointers to selected atomic op implementations.
  static long (*increment_fn_) (volatile long *);
  static long (*decrement_fn_) (volatile long *);
  static long (*exchange_fn_) (volatile long *, long);
  static long (*exchange_add_fn_) (volatile long *, long);
};

/**
 * @brief Specialization of ACE_Atomic_Op for platforms that
 *        support atomic integer operations.
 *
 * Specialization of ACE_Atomic_Op for platforms that support atomic
 * integer operations.
 */
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>
{
public:
  /// Initialize @c value_ to 0.
  ACE_Atomic_Op (void);

  /// Initialize @c value_ to c.
  ACE_Atomic_Op (unsigned long c);

  /// Manage copying...
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &c);

  /// Atomically pre-increment @c value_.
  unsigned long operator++ (void);

  /// Atomically post-increment @c value_.
  unsigned long operator++ (int);

  /// Atomically increment @c value_ by rhs.
  unsigned long operator+= (unsigned long rhs);

  /// Atomically pre-decrement @c value_.
  unsigned long operator-- (void);

  /// Atomically post-decrement @c value_.
  unsigned long operator-- (int);

  /// Atomically decrement @c value_ by rhs.
  unsigned long operator-= (unsigned long rhs);

  /// Atomically compare @c value_ with rhs.
  bool operator== (unsigned long rhs) const;

  /// Atomically compare @c value_ with rhs.
  bool operator!= (unsigned long rhs) const;

  /// Atomically check if @c value_ greater than or equal to rhs.
  bool operator>= (unsigned long rhs) const;

  /// Atomically check if @c value_ greater than rhs.
  bool operator> (unsigned long rhs) const;

  /// Atomically check if @c value_ less than or equal to rhs.
  bool operator<= (unsigned long rhs) const;

  /// Atomically check if @c value_ less than rhs.
  bool operator< (unsigned long rhs) const;

  /// Atomically assign rhs to @c value_.
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &operator= (unsigned long rhs);

  /// Atomically assign <rhs> to @c value_.
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &operator= (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &rhs);

  /// Exchange value with @a newval.
  unsigned long exchange (unsigned long newval);

  /// Explicitly return @c value_.
  unsigned long value (void) const;

  /// Dump the state of an object.
  void dump (void) const;

  /// Explicitly return @c value_ (by reference).
  volatile unsigned long &value_i (void);

  // ACE_ALLOC_HOOK_DECLARE;
  // Declare the dynamic allocation hooks.

  /// Used during ACE object manager initialization to optimize the fast
  /// atomic op implementation according to the number of CPUs.
  static void init_functions (void);

private:

  /// This function cannot be supported by this template specialization.
  /// If you need access to an underlying lock, use the ACE_Atomic_Op_Ex
  /// template instead.
  ACE_Thread_Mutex &mutex (void);

private:

  /// Current object decorated by the atomic op.
  volatile unsigned long value_;

  // Pointers to selected atomic op implementations.
  static long (*increment_fn_) (volatile long *);
  static long (*decrement_fn_) (volatile long *);
  static long (*exchange_fn_) (volatile long *, long);
  static long (*exchange_add_fn_) (volatile long *, long);
};

#endif /* !ACE_HAS_BUILTIN_ATOMIC_OP */

#if defined (ACE_HAS_GCC_ATOMIC_BUILTINS) && (ACE_HAS_GCC_ATOMIC_BUILTINS == 1)

template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, int>
: public ACE_Atomic_Op_GCC<int>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (int c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, int> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, int> &operator= (int rhs);
};

template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int>
: public ACE_Atomic_Op_GCC<unsigned int>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (unsigned int c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned int> &operator= (unsigned int rhs);
};

// If we have built in atomic op, use that, the assignment operator
// is faster for a long/unsinged long
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, long>
: public ACE_Atomic_Op_GCC<long>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (long c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, long> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, long> &operator= (long rhs);
};

template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long>
: public ACE_Atomic_Op_GCC<unsigned long>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (unsigned long c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long> &operator= (unsigned long rhs);
};

// The long long intrinsics are not available on PPC
#if !defined (__powerpc__)
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, long long>
: public ACE_Atomic_Op_GCC<long long>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (long long c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, long long> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, long long> &operator= (long long rhs);
};

template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long long>
: public ACE_Atomic_Op_GCC<unsigned long long>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (unsigned long long c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long long> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned long long> &operator= (unsigned long long rhs);
};
#endif /* !__powerpc__ */

#if !defined (ACE_LACKS_GCC_ATOMIC_BUILTINS_2)
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, short>
: public ACE_Atomic_Op_GCC<short>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (short c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, short> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, short> &operator= (short rhs);
};

template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short>
: public ACE_Atomic_Op_GCC<unsigned short>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (unsigned short c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, unsigned short> &operator= (unsigned short rhs);
};
#endif

#if !defined (ACE_LACKS_GCC_ATOMIC_BUILTINS_1)
template<>
class ACE_Export ACE_Atomic_Op<ACE_Thread_Mutex, bool>
: public ACE_Atomic_Op_GCC<bool>
{
public:
  ACE_Atomic_Op (void);
  ACE_Atomic_Op (bool c);
  ACE_Atomic_Op (const ACE_Atomic_Op<ACE_Thread_Mutex, bool> &c);
  ACE_Atomic_Op<ACE_Thread_Mutex, bool> &operator= (bool rhs);
};
#endif

#endif /* ACE_HAS_BUILTIN_ATOMIC_OP */

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Atomic_Op.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /*ACE_ATOMIC_OP_H*/
