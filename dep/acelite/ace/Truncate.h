// -*- C++ -*-

//=============================================================================
/**
 * @file Truncate.h
 *
 * $Id: Truncate.h 95761 2012-05-15 18:23:04Z johnnyw $
 *
 * @author Steve Huston  <shuston@riverace.com>
 * @author Ossama Othman <ossama_othman@symantec.com>
 * @author Russell Mora  <russell_mora@symantec.com>
 */
//=============================================================================

#ifndef ACE_TRUNCATE_H
#define ACE_TRUNCATE_H

#include /**/ "ace/pre.h"

#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Global_Macros.h"
#include "ace/If_Then_Else.h"
#include "ace/Numeric_Limits.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_Utils
{
  template<typename T> struct Sign_Check;

  // Specialize the unsigned signed cases.
  template<> struct Sign_Check<unsigned char>  { ACE_STATIC_CONSTANT (bool, is_signed = 0); };
  template<> struct Sign_Check<unsigned short> { ACE_STATIC_CONSTANT (bool, is_signed = 0); };
  template<> struct Sign_Check<unsigned int>   { ACE_STATIC_CONSTANT (bool, is_signed = 0); };
  template<> struct Sign_Check<unsigned long>  { ACE_STATIC_CONSTANT (bool, is_signed = 0); };
# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  template<> struct Sign_Check<unsigned long long> { ACE_STATIC_CONSTANT (bool, is_signed = 0); };

  // Specialize the signed cases.
  template<> struct Sign_Check<signed char>  { ACE_STATIC_CONSTANT (bool, is_signed = 1); };
  template<> struct Sign_Check<signed short> { ACE_STATIC_CONSTANT (bool, is_signed = 1); };
  template<> struct Sign_Check<signed int>   { ACE_STATIC_CONSTANT (bool, is_signed = 1); };
  template<> struct Sign_Check<signed long>  { ACE_STATIC_CONSTANT (bool, is_signed = 1); };
# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  template<> struct Sign_Check<signed long long> { ACE_STATIC_CONSTANT (bool, is_signed = 1); };

  // -----------------------------------------------------

  /**
   * @struct To_Unsigned
   *
   * @brief Retrieve unsigned counterpart to given type or value.
   *
   * Retrieve unsigned counterpart to given type or value.
   */
  template<typename T> struct To_Unsigned;

  template<>
  struct To_Unsigned<unsigned char>
  {
    typedef unsigned char unsigned_type;

    unsigned_type operator() (unsigned_type x) { return x; }
  };

  template<>
  struct To_Unsigned<unsigned short>
  {
    typedef unsigned short unsigned_type;

    unsigned_type operator() (unsigned_type x) { return x; }
  };

  template<>
  struct To_Unsigned<unsigned int>
  {
    typedef unsigned int unsigned_type;

    unsigned_type operator() (unsigned_type x) { return x; }
  };

  template<>
  struct To_Unsigned<unsigned long>
  {
    typedef unsigned long unsigned_type;

    unsigned_type operator() (unsigned_type x) { return x; }
  };

# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  template<>
  struct To_Unsigned<unsigned long long>
  {
    typedef unsigned long long unsigned_type;

    unsigned_type operator() (unsigned_type x) { return x; }
  };

  // ----------------

  template<>
  struct To_Unsigned<signed char>
  {
    typedef signed char   signed_type;
    typedef unsigned char unsigned_type;

    unsigned_type operator() (signed_type x)
    {
      return static_cast<unsigned_type> (x);
    }
  };

  template<>
  struct To_Unsigned<signed short>
  {
    typedef signed short   signed_type;
    typedef unsigned short unsigned_type;

    unsigned_type operator() (signed_type x)
    {
      return static_cast<unsigned_type> (x);
    }
  };

  template<>
  struct To_Unsigned<signed int>
  {
    typedef signed int   signed_type;
    typedef unsigned int unsigned_type;

    unsigned_type operator() (signed_type x)
    {
      return static_cast<unsigned_type> (x);
    }
  };

  template<>
  struct To_Unsigned<signed long>
  {
    typedef signed long   signed_type;
    typedef unsigned long unsigned_type;

    unsigned_type operator() (signed_type x)
    {
      return static_cast<unsigned_type> (x);
    }
  };

# ifdef __GNUC__
  // Silence g++ "-pedantic" warnings regarding use of "long long"
  // type.
  __extension__
# endif  /* __GNUC__ */
  template<>
  struct To_Unsigned<signed long long>
  {
    typedef signed long long   signed_type;
    typedef unsigned long long unsigned_type;

    unsigned_type operator() (signed_type x)
    {
      return static_cast<unsigned_type> (x);
    }
  };

  // -----------------------------------------------------

  /**
   * @struct Safe_Comparator
   *
   * @brief Conservative comparison of types that may not be safely
   *        promoted and/or converted to each other.
   *
   * The comparison operations provided by this structure perform
   * negative value checking when necessary to prevent wrap-around
   * when explicitly casting to an unsigned type.
   *
   * @internal This structure is not meant for general use.
   */
  template<typename LEFT,
           typename RIGHT,
           bool IS_LEFT_SIGNED,
           bool IS_RIGHT_SIGNED> struct Safe_Comparator;

  // LEFT: signed, RIGHT: unsigned
  template<typename LEFT, typename RIGHT>
  struct Safe_Comparator<LEFT, RIGHT, true, false>
  {
    static bool greater_than (LEFT lhs, RIGHT rhs)
    {
      // Prevent wrap-around when casting to unsigned.
      if (lhs < 0)
        return false;  // since rhs is always positive
      else
        {
          // Implicit promotion of unsigned LEFT and RIGHT types here.
          return To_Unsigned<LEFT>() (lhs) > rhs;
        }
    }
  };

  // LEFT: unsigned, RIGHT: signed
  template<typename LEFT, typename RIGHT>
  struct Safe_Comparator<LEFT, RIGHT, false, true>
  {
    static bool greater_than (LEFT lhs, RIGHT rhs)
    {
      // Prevent wrap-around when casting to unsigned.
      if (rhs < 0)
        return true;  // since lhs is always positive
      else
        {
          // Implicit promotion of unsigned LEFT and RIGHT types here.
          return lhs > To_Unsigned<RIGHT>() (rhs);
        }
    }
  };

  // LEFT: unsigned, RIGHT: unsigned
  template<typename LEFT, typename RIGHT>
  struct Safe_Comparator<LEFT, RIGHT, false, false>
  {
    static bool greater_than (LEFT lhs, RIGHT rhs)
    {
      // Implicit promotion of unsigned LEFT and RIGHT types here.
      return lhs > rhs;
    }
  };

  // LEFT: signed, RIGHT: signed
  template<typename LEFT, typename RIGHT>
  struct Safe_Comparator<LEFT, RIGHT, true, true>
  {
    static bool greater_than (LEFT lhs, RIGHT rhs)
    {
      // Implicit promotion of signed LEFT and RIGHT types here.
      return lhs > rhs;
    }
  };

  // -----------------------------------------------------

  /**
   * @struct Fast_Comparator
   *
   * @brief Quick comparison of types that can be safely promoted
   *        and/or converted to each other.
   *
   * The comparison operations provided by this structure perform no
   * negative value checking, meaning it is not applicable to all
   * types.  Check the value of the @c USABLE enumerator to determine
   * if it applies to the types in question.
   *
   * @internal This structure is not meant for general use.
   */
  template<typename LEFT, typename RIGHT>
  struct Fast_Comparator
  {
    ACE_STATIC_CONSTANT (
      bool,
      USE_LEFT  = ((sizeof (LEFT) > sizeof (RIGHT)
                    && (Sign_Check<LEFT>::is_signed == 1
                        || Sign_Check<RIGHT>::is_signed == 0))

                   // The following is basically the case where LEFT
                   // and RIGHT are the same integral type.
                   || (sizeof (LEFT) == sizeof (RIGHT)
                       // Can't portably do
                       // Sign_Check<LEFT>::is_signed ==
                       // Sign_Check<RIGHT>::is_signed,
                       // i.e. comparison of anonymous enumerations,
                       // without triggering a compiler diagnostic
                       // so expand the comparison.
                       && ((Sign_Check<LEFT>::is_signed == 1
                            && Sign_Check<RIGHT>::is_signed == 1)
                           || (Sign_Check<LEFT>::is_signed == 0
                               && Sign_Check<RIGHT>::is_signed == 0)))));

    ACE_STATIC_CONSTANT (
      bool,
      USE_RIGHT = (sizeof (RIGHT) > sizeof (LEFT)
                   && (Sign_Check<RIGHT>::is_signed == 1
                       || Sign_Check<LEFT>::is_signed == 0)));

    ACE_STATIC_CONSTANT (bool, USABLE = (USE_LEFT || USE_RIGHT));

    typedef typename ACE::If_Then_Else<
      USE_LEFT,
      LEFT,
      typename ACE::If_Then_Else<
        USE_RIGHT,
        RIGHT,
        void>::result_type>::result_type promote_type;

    static bool greater_than (LEFT lhs, RIGHT rhs)
    {
      // The explicit cast is assumed to change the type of rhs without
      // changing its value.
      return
        (static_cast<promote_type> (lhs) > static_cast<promote_type> (rhs));
    }

  };

  // -----------------------------------------------------

  /**
   * @struct Comparator
   *
   * @brief Structure that provides optimal comparison operation for
   *        given types.
   *
   * The comparison operations provided by this structure are chosen
   * at compile time based on the signs and sizes of types being
   * compared.
   * @par
   * Comparisons of values with the same sign or those with types that
   * can be promoted safely are done quickly, without any range
   * checking.
   * @par
   * Comparisons of values of different types that cannot be safely
   * promoted incur an additional check for a negative value to allow
   * the compiler to perform the appropriate implicit unsigned type
   * promotion.
   *
   * @note In general, the operations found in this structure should
   *       not be used to work around compiler diagnostics regarding
   *       comparison of signed and unsigned types.  Verify that your
   *       types are correct before relying on those operations.
   *
   * @internal This structure is not meant for general use.
   */
  template<typename LEFT, typename RIGHT>
  struct Comparator
  {
    typedef typename ACE::If_Then_Else<
      Fast_Comparator<LEFT, RIGHT>::USABLE,
      Fast_Comparator<LEFT, RIGHT>,
      Safe_Comparator<LEFT,
                      RIGHT,
                      Sign_Check<LEFT>::is_signed,
                      Sign_Check<RIGHT>::is_signed> >::result_type comp_type;
  };

  // -----------------------------------------------------

  /**
   * @struct Truncator
   *
   * @brief Truncate value of type @c FROM to value of type @c TO.
   *
   * Truncate a value of type @c FROM to value of type @c TO, if the
   * value is larger than the maximum of value of type @c TO.
   */
  template<typename FROM, typename TO>
  struct Truncator
  {
    ACE_STATIC_CONSTANT (
      bool,
      // max FROM always greater than max TO
      MAX_FROM_GT_MAX_TO = (sizeof(FROM) > sizeof (TO)
                            || (sizeof(FROM) == sizeof (TO)
                                && Sign_Check<FROM>::is_signed == 0)));

    typedef typename ACE::If_Then_Else<
      MAX_FROM_GT_MAX_TO,
      FROM,
      TO>::result_type comp_to_type;

    // Take advantage of knowledge that we're casting a positive value
    // to a type large enough to hold it so that we can bypass
    // negative value checks at compile-time.  Otherwise fallback on
    // the safer comparison.
    typedef typename ACE::If_Then_Else<
      MAX_FROM_GT_MAX_TO,
      Fast_Comparator<FROM, comp_to_type>,
      typename Comparator<FROM, comp_to_type>::comp_type>::result_type comparator;

    /// Truncate a value of type @c FROM to value of type @c TO, if
    /// the value is larger than the maximum of value of type @c TO.
    TO operator() (FROM val)
    {
      return
        (comparator::greater_than (val, ACE_Numeric_Limits<TO>::max ())
         ? ACE_Numeric_Limits<TO>::max ()
         : static_cast<TO> (val));
    }

  };

  // Partial specialization for the case where the types are the same.
  // No truncation is necessary.
  template<typename T>
  struct Truncator<T, T>
  {
    T operator() (T val)
    {
      return val;
    }
  };


  // -----------------------------------------------------
  /**
   * @struct Noop_Truncator
   *
   * @brief No-op truncation.
   *
   * This structure/functor performs no truncation since it assumes
   * that @c sizeof(FROM) @c < @c sizeof(TO), meaning that
   * @c numeric_limits<FROM>::max() @c < @c numeric_limits<TO>::max().
   */
  template<typename FROM, typename TO>
  struct Noop_Truncator
  {
    TO operator() (FROM val)
    {
      return static_cast<TO> (val);
    }
  };
  // -----------------------------------------------------

  /**
   * @class truncate_cast
   *
   * @brief Helper function to truncate an integral value to the
   *        maximum  value of the given type.
   *
   *        Very useful since ACE methods return @c int very often and
   *        the value's source is often a different-size integral
   *        type, such as @c size_t.  This function hides the
   *        truncation logic and resolves compiler diagnostics.
   *
   * @internal Internal use only.
   */
  template<typename TO, typename FROM>
  inline TO truncate_cast (FROM val)
  {
    // If the size of FROM is less than the size of TO, "val" will
    // never be greater than the maximum "TO" value, so there is no
    // need to attempt to truncate.
    typedef typename ACE::If_Then_Else<
      (sizeof (FROM) < sizeof (TO)),
      Noop_Truncator<FROM, TO>,
      Truncator<FROM, TO> >::result_type truncator;

    return truncator() (val);
  }

} // namespace ACE_Utils

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ACE_TRUNCATE_H*/
