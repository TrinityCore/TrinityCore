
//=============================================================================
/**
 *  @file    Basic_Stats.h
 *
 *  $Id: Basic_Stats.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Carlos O'Ryan <coryan@uci.edu>
 */
//=============================================================================


#ifndef ACE_BASIC_STATS_H
#define ACE_BASIC_STATS_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"
#include "ace/Basic_Types.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// Collect basic stats about a series of samples
/**
 * Compute the average and standard deviation (aka jitter) for an
 * arbitrary number of samples, using constant space.
 * Normally used for latency statistics.
 */
class ACE_Export ACE_Basic_Stats
{
public:
  /// Constructor
  /**
   * The number of samples is pre-allocated, and cannot changes once
   * the class is initialized.
   */
  ACE_Basic_Stats (void);

  /// The number of samples received so far
  ACE_UINT32 samples_count (void) const;

  /// Record one sample.
  void sample (ACE_UINT64 value);

  /// Update the values to reflect the stats in @a rhs.
  void accumulate (const ACE_Basic_Stats &rhs);

  /// Dump all the samples
  /**
   * Prints out the results, using @a msg as a prefix for each message and
   * scaling all the numbers by @a scale_factor. The latter is useful because
   * high resolution timer samples are acquired in clock ticks, but often
   * presented in microseconds.
   */
  void dump_results (const ACE_TCHAR *msg,
                     ACE_UINT32 scale_factor) const;

  /// The number of samples
  ACE_UINT32 samples_count_;

  /// The minimum value
  ACE_UINT64 min_;

  /// The number of the sample that had the minimum value
  ACE_UINT32 min_at_;

  /// The maximum value
  ACE_UINT64 max_;

  /// The number of the sample that had the maximum value
  ACE_UINT32 max_at_;

  /// The sum of all the values
  ACE_UINT64 sum_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Basic_Stats.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_BASIC_STATS_H */
