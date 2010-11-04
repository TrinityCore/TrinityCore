// -*- C++ -*-

//==========================================================================
/**
 *  @file    Throughput_Stats.h
 *
 *  $Id: Throughput_Stats.h 92069 2010-09-28 11:38:59Z johnnyw $
 *
 *  @author David L. Levine
 */
//==========================================================================


#ifndef ACE_THROUGHPUT_STATS_H
#define ACE_THROUGHPUT_STATS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Stats.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/// A simple class to make throughput and latency analysis.
/**
 *
 * Keep the relevant information to perform throughput and latency
 * analysis, including:
 * -# Minimum, Average and Maximum latency
 * -# Jitter for the latency
 * -# Linear regression for throughput
 * -# Accumulate results from several samples to obtain aggregated
 *    results, across several threads or experiments.
 *
 * @todo The idea behind this class was to use linear regression to
 *       determine if the throughput was linear or exhibited jitter.
 *       Unfortunately it never worked quite right, so only average
 *       throughput is computed.
 */
class ACE_Export ACE_Throughput_Stats : public ACE_Basic_Stats
{
public:
  /// Constructor
  ACE_Throughput_Stats (void);

  /// Store one sample
  void sample (ACE_UINT64 throughput, ACE_UINT64 latency);

  /// Update the values to reflect the stats in @a throughput
  void accumulate (const ACE_Throughput_Stats &throughput);

  /// Print down the stats
  void dump_results (const ACE_TCHAR* msg, ACE_UINT32 scale_factor);

  /// Dump the average throughput stats.
  static void dump_throughput (const ACE_TCHAR *msg,
                               ACE_UINT32 scale_factor,
                               ACE_UINT64 elapsed_time,
                               ACE_UINT32 samples_count);
private:
  /// The last throughput measurement.
  ACE_UINT64 throughput_last_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ! ACE_THROUGHPUT_STATS_H */
