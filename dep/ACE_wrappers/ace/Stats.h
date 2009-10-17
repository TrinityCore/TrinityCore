// -*- C++ -*-

//==========================================================================
/**
 *  @file    Stats.h
 *
 *  $Id: Stats.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author David L. Levine
 */
//==========================================================================

#ifndef ACE_STATS_H
#define ACE_STATS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Unbounded_Queue.h"
#include "ace/Log_Msg.h"
#include "ace/Basic_Stats.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Stats_Value
 *
 * @brief Helper class for ACE_Stats.
 *
 * Container struct for 64-bit signed quantity and its
 * precision.  It would be nicer to use a fixed-point class, but
 * this is sufficient.  Users typically don't need to use this
 * class directly; see ACE_Stats below.
 */
class ACE_Export ACE_Stats_Value
{
public:
  /**
   * Constructor, which requires precision in terms of number of
   * decimal digits.  The more variation in the data, and the greater
   * the data values, the smaller the precision must be to avoid
   * overflow in the standard deviation calculation.  3 might be a
   * good value, or maybe 4.  5 will probably be too large for
   * non-trivial data sets.
   */
  ACE_Stats_Value (const u_int precision);

  /// Accessor for precision.
  u_int precision (void) const;

  /// Set the whole_ field.
  void whole (const ACE_UINT32);

  /// Accessor for the whole_ field.
  ACE_UINT32 whole (void) const;

  /// Set the fractional_ field.
  void fractional (const ACE_UINT32);

  /// Accessor for the fractional_ field.
  ACE_UINT32 fractional (void) const;

  /// Calculates the maximum value of the fractional portion, given its
  /// precision.
  ACE_UINT32 fractional_field (void) const;

  /**
   * Access the value as an _unsigned_ 64 bit quantity.  It scales the
   * value up by {precision} decimal digits, so that no precision will
   * be lost.  It assumes that {whole_} is >= 0.
   */
  void scaled_value (ACE_UINT64 &) const;

  /// Print to stdout.
  void dump (void) const;

private:

  ACE_Stats_Value (void) {}

private:
  /// The integer portion of the value.
  ACE_UINT32 whole_;

  /// The fractional portion of the value.
  ACE_UINT32 fractional_;

  /**
   * The number of decimal digits of precision represented by
   * {fractional_}.  Not declared const, so the only way to change it
   * is via the assignment operator.
   */
  u_int precision_;

};

/**
 * @class ACE_Stats
 *
 * @brief Provides simple statistical analysis.
 *
 * Simple statistical analysis package.  Prominent features are:
 * -# It does not use any floating point arithmetic.
 * -# It handles positive and/or negative sample values.  The
 *    sample value type is ACE_INT32.
 * -# It uses 64 bit unsigned, but not 64 bit signed, quantities
 *    internally.
 * -# It checks for overflow of internal state.
 * -# It has no static variables of other than built-in types.
 *
 * Example usage:
 *
 * @verbatim
 * ACE_Stats stats;
 * for (u_int i = 0; i < n; ++i)
 * {
 * const ACE_UINT32 sample = ...;
 * stats.sample (sample);
 * }
 * stats.print_summary (3);
 * @endverbatim
 */
class ACE_Export ACE_Stats
{
public:
  /// Default constructor.
  ACE_Stats (void);

  /// Provide a new sample.  Returns 0 on success, -1 if it fails due
  /// to running out of memory, or to rolling over of the sample count.
  int sample (const ACE_INT32 value);

  /// Access the number of samples provided so far.
  ACE_UINT32 samples (void) const;

  /// Value of the minimum sample provided so far.
  ACE_INT32 min_value (void) const;

  /// Value of the maximum sample provided so far.
  ACE_INT32 max_value (void) const;

  /**
   * Access the mean of all samples provided so far.  The fractional
   * part is to the specified number of digits.  E.g., 3 fractional
   * digits specifies that the fractional part is in thousandths.
   */
  void mean (ACE_Stats_Value &mean,
             const ACE_UINT32 scale_factor = 1);

  /// Access the standard deviation, whole and fractional parts.  See
  /// description of {mean} method for argument descriptions.
  int std_dev (ACE_Stats_Value &std_dev,
               const ACE_UINT32 scale_factor = 1);

  /**
   * Print summary statistics.  If scale_factor is not 1, then the
   * results are divided by it, i.e., each of the samples is scaled
   * down by it.  If internal overflow is reached with the specified
   * scale factor, it successively tries to reduce it.  Returns -1 if
   * there is overflow even with a 0 scale factor.
   */
  int print_summary (const u_int precision,
                     const ACE_UINT32 scale_factor = 1,
                     FILE * = stdout) const;

  /// Initialize internal state.
  void reset (void);

  /// Utility division function, for ACE_UINT64 dividend.
  static void quotient (const ACE_UINT64 dividend,
                        const ACE_UINT32 divisor,
                        ACE_Stats_Value &quotient);

  /// Utility division function, for ACE_Stats_Value dividend.
  static void quotient (const ACE_Stats_Value &dividend,
                        const ACE_UINT32 divisor,
                        ACE_Stats_Value &quotient);

  /**
   * Sqrt function, which uses an oversimplified version of Newton's
   * method.  It's not fast, but it doesn't require floating point
   * support.
   */
  static void square_root (const ACE_UINT64 n,
                           ACE_Stats_Value &square_root);

  /// Print summary statistics to stdout.
  void dump (void) const;

protected:
  /// Internal indication of whether there has been overflow.  Contains
  /// the errno corresponding to the cause of overflow.
  u_int overflow_;

  /// Number of samples.
  ACE_UINT32 number_of_samples_;

  /// Minimum sample value.
  ACE_INT32 min_;

  /// Maximum sample value.
  ACE_INT32 max_;

  /// The samples.
  ACE_Unbounded_Queue <ACE_INT32> samples_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "ace/Stats.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif /* ! ACE_STATS_H */

