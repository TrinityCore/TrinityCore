// -*- C++ -*-

//==========================================================================
/**
 *  @file    Functor.h
 *
 *  $Id: Functor.h 86698 2009-09-13 15:58:17Z johnnyw $
 *
 *   Non-templatized classes and class template specializations for
 *   implementing function objects that are used in  various places
 *   in ACE.  There are currently two major categories of function
 *   objects in ACE: GoF Command Pattern objects, and STL-style
 *   functors for comparison of container elements.  The command objects
 *   are invoked via an execute () method, while the STL-style functors are
 *   invoked via an operator() () method.
 *  Non-templatized classes for implementing the GoF Command Pattern,
 *  also known as functors or function objects.
 *
 *
 *  @author Chris Gill <cdgill@cs.wustl.edu>
 *  @author Based on Command Pattern implementations originally done by
 *  @author Carlos O'Ryan <coryan@cs.wustl.edu>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Sergio Flores-Gaitan <sergio@cs.wustl.edu>
 *  @author and on STL-style functor implementations originally done by
 *  @author Irfan Pyarali  <irfan@cs.wustl.edu>
 */
//==========================================================================


#ifndef ACE_FUNCTOR_H
#define ACE_FUNCTOR_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "ace/ACE_export.h"
#include "ace/Basic_Types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

//////////////////////////////////////////////////////////////
// GOF Command Pattern Classes and Template Specializations //
//////////////////////////////////////////////////////////////

/**
 * @class ACE_Command_Base
 *
 * @brief Defines an abstract class that allows us to invoke commands
 * without knowing anything about the implementation.
 *
 * This class declares an interface to execute a command
 * independent of the effect of the command, or the objects used
 * to implement it.
 */
class ACE_Export ACE_Command_Base
{
public:
  // = Initialization and termination methods.
  /// Default constructor.
  ACE_Command_Base (void);

  /// Virtual destructor.
  virtual ~ACE_Command_Base (void);

  /**
   * Invokes the method encapsulated by the command, passing along the
   * passed argument (if any).  Users of classes derived from this
   * class must ensure that the resulting invocation can tolerate a
   * null void pointer being passed, or otherwise ensure that this
   * will never occur.
   */
  virtual int execute (void *arg = 0) = 0;
};

////////////////////////////////////////////////////////////
// STL-style Functor Classes and Template Specializations //
////////////////////////////////////////////////////////////

// Forward declaration since we are going to specialize that template
// here. The template itself requires this file so every user of the
// template should also see the specialization.
template <class TYPE> class ACE_Hash;
template <class TYPE> class ACE_Equal_To;
template <class TYPE> class ACE_Less_Than;

/**
 * @brief Function object for hashing a char
 */
template<>
class ACE_Export ACE_Hash<char>
{
public:
  /// Simply returns t
  unsigned long operator () (char t) const;
};

/**
 * @brief Function object for hashing a signed char
 */
template<>
class ACE_Export ACE_Hash<signed char>
{
public:
  /// Simply returns t
  unsigned long operator () (signed char t) const;
};

/**
 * @brief Function object for hashing an unsigned char
 */
template<>
class ACE_Export ACE_Hash<unsigned char>
{
public:
  /// Simply returns t
  unsigned long operator () (unsigned char t) const;
};

#if 0
// @@ ADD HASHES FOR ACE TYPES

/**
 * @brief Function object for hashing a 16-bit signed number
 */
template<>
class ACE_Export ACE_Hash<ACE_INT16>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_INT16 t) const;
};

/**
 * @brief Function object for hashing a 16-bit unsigned number
 */
template<>
class ACE_Export ACE_Hash<ACE_UINT16>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_UINT16 t) const;
};

/**
 * @brief Function object for hashing a 32-bit signed number
 */
template<>
class ACE_Export ACE_Hash<ACE_INT32>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_INT32 t) const;
};

/**
 * @brief Function object for hashing a 32-bit unsigned number
 */
template<>
class ACE_Export ACE_Hash<ACE_UINT32>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_UINT32 t) const;
};

/**
 * @brief Function object for hashing a 64-bit unsigned number
 */
template<>
class ACE_Export ACE_Hash<ACE_UINT64>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_UINT64 t) const;
};

// @@ DONE ADDING HASHES FOR ACE TYPES
#endif

/**
 * @brief Function object for hashing a short number
 */
template<>
class ACE_Export ACE_Hash<short>
{
public:
  /// Simply returns t
  unsigned long operator () (short t) const;
};

/**
 * @brief Function object for hashing an unsigned short number
 */
template<>
class ACE_Export ACE_Hash<unsigned short>
{
public:
  /// Simply returns t
  unsigned long operator () (unsigned short t) const;
};

/**
 * @brief Function object for hashing an int number
 */
template<>
class ACE_Export ACE_Hash<int>
{
public:
  /// Simply returns t
  unsigned long operator () (int t) const;
};

/**
 * @brief Function object for hashing an unsigned int number
 */
template<>
class ACE_Export ACE_Hash<unsigned int>
{
public:
  /// Simply returns t
  unsigned long operator () (unsigned int t) const;
};

/**
 * @brief Function object for hashing a long number
 */
template<>
class ACE_Export ACE_Hash<long>
{
public:
  /// Simply returns t
  unsigned long operator () (long t) const;
};

/**
 * @brief Function object for hashing an unsigned long number
 */
template<>
class ACE_Export ACE_Hash<unsigned long>
{
public:
  /// Simply returns t
  unsigned long operator () (unsigned long t) const;
};

#if !defined (ACE_LACKS_LONGLONG_T) && (ACE_SIZEOF_LONG < 8)
/**
 * @brief Function object for hashing a signed 64-bit number
 */
template<>
class ACE_Export ACE_Hash<ACE_INT64>
{
public:
  /// Simply returns t
  unsigned long operator () (ACE_INT64 t) const;
};
#endif /* !ACE_LACKS_LONGLONG_T && ACE_SIZEOF_LONG < 8 */

// We can do this even if ACE_LACKS_UNSIGNEDLONGLONG_T because there's an
// emulation for it in ACE_U_LongLong.
#if (ACE_SIZEOF_LONG < 8)
/**
 * @brief Function object for hashing an unsigned 64-bit number
 */
template<>
class ACE_Export ACE_Hash<ACE_UINT64>
{
public:
  /// Simply returns t
  unsigned long operator () (const ACE_UINT64 &t) const;
};
#endif /* ACE_SIZEOF_LONG < 8 */

/**
 * @brief Function object for hashing a const string
 */
template<>
class ACE_Export ACE_Hash<const char *>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const char *t) const;
};

/**
 * @brief Function object for hashing a string
 */
template<>
class ACE_Export ACE_Hash<char *>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const char *t) const;
};

/**
 * @brief Function object for hashing a void *
 */
template<>
class ACE_Export ACE_Hash<void *>
{
public:
  unsigned long operator () (const void *) const;
};

/**
 * @brief Function object for determining whether two const strings are equal.
 */
template<>
class ACE_Export ACE_Equal_To<const char *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const char *lhs,
                   const char *rhs) const;
};

/**
 * @brief Function object for determining whether two non-const
 * strings are equal.
 */
template<>
class ACE_Export ACE_Equal_To<char *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const char *lhs,
                   const char *rhs) const;
};

/**
 * @brief Function object for determining whether two unsigned
 * 16 bit ints are equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_UINT16>
{
public:
  /// Simply calls built-in operators
  int operator () (const ACE_UINT16 lhs,
                   const ACE_UINT16 rhs) const;
};

/**
 * @brief Function object for determining whether two
 * 16 bit ints are equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_INT16>
{
public:
  /// Simply calls built-in operators
  int operator () (const ACE_INT16 lhs,
                   const ACE_INT16 rhs) const;
};

/**
 * @brief Function object for determining whether two unsigned
 * 32 bit ints are equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_UINT32>
{
public:
  /// Simply calls built-in operators
  int operator () (const ACE_UINT32 lhs,
                   const ACE_UINT32 rhs) const;
};

/**
 * @brief Function object for determining whether two
 * 32 bit ints are equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_INT32>
{
public:
  /// Simply calls built-in operators
  int operator () (const ACE_INT32 lhs,
                   const ACE_INT32 rhs) const;
};

/**
 * @brief Function object for determining whether two unsigned
 * 64 bit ints are equal.
 */
template<>
class ACE_Export ACE_Equal_To<ACE_UINT64>
{
public:
  /// Simply calls built-in operators
  int operator () (const ACE_UINT64 lhs,
                   const ACE_UINT64 rhs) const;
};

/**
 * @brief Function object for determining whether the first const string
 * is less than the second const string.
 */
template<>
class ACE_Export ACE_Less_Than<const char *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const char *lhs,
                   const char *rhs) const;
};

/**
 * @brief Function object for determining whether the first string
 * is less than the second string.
 */
template<>
class ACE_Export ACE_Less_Than<char *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const char *lhs,
                   const char *rhs) const;
};

#if defined (ACE_HAS_WCHAR)

#  if ! defined (ACE_LACKS_NATIVE_WCHAR_T)
/**
 * @brief Function object for hashing a wchar_t
 */
template<>
class ACE_Export ACE_Hash<wchar_t>
{
public:
  /// Simply returns t
  unsigned long operator () (wchar_t t) const;
};
#  endif /* ACE_LACKS_NATIVE_WCHAR_T */
/**
 * @brief Function object for hashing a const string
 */
template<>
class ACE_Export ACE_Hash<const wchar_t *>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const wchar_t *t) const;
};

/**
 * @brief Function object for hashing a string
 */
template<>
class ACE_Export ACE_Hash<wchar_t *>
{
public:
  /// Calls ACE::hash_pjw
  unsigned long operator () (const wchar_t *t) const;
};

/**
 * @brief Function object for determining whether two const strings are equal.
 */
template<>
class ACE_Export ACE_Equal_To<const wchar_t *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const wchar_t *lhs,
                   const wchar_t *rhs) const;
};

/**
 * @brief Function object for determining whether two non-const
 * strings are equal.
 */
template<>
class ACE_Export ACE_Equal_To<wchar_t *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const wchar_t *lhs,
                   const wchar_t *rhs) const;
};

/**
 * @brief Function object for determining whether the first const string
 * is less than the second const string.
 */
template<>
class ACE_Export ACE_Less_Than<const wchar_t *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const wchar_t *lhs,
                   const wchar_t *rhs) const;
};

/**
 * @brief Function object for determining whether the first string
 * is less than the second string.
 */
template<>
class ACE_Export ACE_Less_Than<wchar_t *>
{
public:
  /// Simply calls ACE_OS::strcmp
  int operator () (const wchar_t *lhs,
                   const wchar_t *rhs) const;
};

#endif  // ACE_HAS_WCHAR

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Functor.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_FUNCTOR_H */
