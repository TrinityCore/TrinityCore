// $Id: Throughput_Stats.cpp 95761 2012-05-15 18:23:04Z johnnyw $

#include "ace/Throughput_Stats.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/High_Res_Timer.h"
#include "ace/Log_Msg.h"



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Throughput_Stats::ACE_Throughput_Stats (void)
  : ACE_Basic_Stats ()
  , throughput_last_ (0)
{
}

void
ACE_Throughput_Stats::sample (ACE_UINT64 throughput,
                              ACE_UINT64 latency)
{
  this->ACE_Basic_Stats::sample (latency);

  if (this->samples_count () == 1u)
    {
      this->throughput_last_ = throughput;
    }
}

void
ACE_Throughput_Stats::accumulate (const ACE_Throughput_Stats &rhs)
{
  if (rhs.samples_count () == 0u)
    return;

  this->ACE_Basic_Stats::accumulate (rhs);

  if (this->samples_count () == 0u)
    {
      this->throughput_last_   = rhs.throughput_last_;
      return;
    }

  if (this->throughput_last_ < rhs.throughput_last_)
    this->throughput_last_ = rhs.throughput_last_;
}

void
ACE_Throughput_Stats::dump_results (const ACE_TCHAR* msg,
                                    ACE_Basic_Stats::scale_factor_type sf)
{
  if (this->samples_count () == 0u)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s : no data collected\n"), msg));
      return;
    }

  this->ACE_Basic_Stats::dump_results (msg, sf);

  ACE_Throughput_Stats::dump_throughput (msg, sf,
                                         this->throughput_last_,
                                         this->samples_count ());
}

void
ACE_Throughput_Stats::dump_throughput (const ACE_TCHAR *msg,
                                       ACE_Basic_Stats::scale_factor_type sf,
                                       ACE_UINT64 elapsed_time,
                                       ACE_UINT32 samples_count)
{
#ifndef ACE_NLOGGING
  double seconds =
    static_cast<double> (ACE_UINT64_DBLCAST_ADAPTER (elapsed_time / sf));
  seconds /= ACE_HR_SCALE_CONVERSION;

  const double t_avg = samples_count / seconds;

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%s throughput: %.2f (events/second)\n"),
              msg, t_avg));
#else
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (sf);
  ACE_UNUSED_ARG (elapsed_time);
  ACE_UNUSED_ARG (samples_count);
#endif /* ACE_NLOGGING */
}

ACE_END_VERSIONED_NAMESPACE_DECL
