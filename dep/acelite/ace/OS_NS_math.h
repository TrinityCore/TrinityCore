// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_math.h
 *
 *  $Id: OS_NS_math.h 95724 2012-05-03 06:43:31Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_MATH_H
# define ACE_OS_NS_MATH_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_math.h"

#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export


/*
 * We inline and undef some functions that may be implemented
 * as macros on some platforms. This way macro definitions will
 * be usable later as there is no way to save the macro definition
 * using the pre-processor.
 *
 */
inline double ace_log2_helper (double x)
{
#if defined (log2)
  return log2 (x);
#undef log2
#else
#  if !defined (ACE_LACKS_LOG2)
  return ACE_STD_NAMESPACE::log2 (x);
#  else
  /*
    ==================================================================

                log (x)
                   k
      log (x) = -------
         b      log (b)
                   k

    meaning the binary logarithm of x using the natural logarithm, for
    example, is:


                log (x)
                   e
      log (x) = -------
         2      log (2)
                   e

    ==================================================================
   */

  // Precomputed value of 1/log(2.0).  Saves an expensive division and
  // computing log(2.0) in each call.
  double const _1_ln2 = 1.442695040888963407359924681002;

  return log (x) * _1_ln2;
#  endif /* !ACE_LACKS_LOG2 */
#endif /* defined (log2) */
}


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS
{
  /// This method computes the largest integral value not greater than x.
  template <typename T>
  inline
  T floor (T x)
  {
    return ACE_STD_NAMESPACE::floor (x);
  }

#if defined (ACE_HAS_WINCE)
  /// Windows CE has an intrinsic floor for float
  template <>
  inline
  float floor (float x)
  {
    return ACE_STD_NAMESPACE::floorf (x);
  }
#endif

  /// This method computes the smallest integral value not less than x.
  template <typename T>
  inline
  T ceil (T x)
  {
    return ACE_STD_NAMESPACE::ceil (x);
  }

#if defined (ACE_HAS_WINCE)
  /// Windows CE has an intrinsic ceil for float
  template <>
  inline
  float ceil (float x)
  {
    return ACE_STD_NAMESPACE::ceilf (x);
  }
#endif

  /// This method computes the base-2 logarithm of x.
  ACE_NAMESPACE_INLINE_FUNCTION
  double log2 (double x);

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_math.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_MATH_H */
