// $Id: Throughput_Stats.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Throughput_Stats.h"

#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/High_Res_Timer.h"
#include "ace/Log_Msg.h"

ACE_RCSID(ace, Throughput_Stats, "$Id: Throughput_Stats.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Throughput_Stats::ACE_Throughput_Stats (void)
  : ACE_Basic_Stats ()
  , throughput_last_ (0)
#if 0
  // @@TODO: This is what I really wanted to compute, but it just
  // does not work.
  , throughput_sum_x_ (0)
  , throughput_sum_x2_ (0)
  , throughput_sum_y_ (0)
  , throughput_sum_y2_ (0)
  , throughput_sum_xy_ (0)
#endif /* 0 */
{
}

void
ACE_Throughput_Stats::sample (ACE_UINT64 throughput,
                              ACE_UINT64 latency)
{
  this->ACE_Basic_Stats::sample (latency);

  if (this->samples_count () == 1u)
    {

      this->throughput_last_   = throughput;
#if 0
      // @@TODO: This is what I really wanted to compute, but it just
      // does not work.
      this->throughput_sum_y_  = this->samples_count_;
      this->throughput_sum_y2_ = this->samples_count_ * this->samples_count_;
      this->throughput_sum_x_  = throughput;
      this->throughput_sum_x2_ = throughput * throughput;
      this->throughput_sum_xy_ = throughput * this->samples_count_;

      ACE_OS::printf ("%f %qu\n", throughput / 400000000.0, this->samples_count_);
#endif /* 0 */
    }
  else
    {
      this->throughput_last_ = throughput;

#if 0
      // @@TODO: This is what I really wanted to compute, but it just
      // does not work.
      this->throughput_sum_y_  += this->samples_count_;
      this->throughput_sum_y2_ += this->samples_count_ * this->samples_count_;
      this->throughput_sum_x_  += throughput;
      this->throughput_sum_x2_ += throughput * throughput;
      this->throughput_sum_xy_ += throughput * this->samples_count_;

      ACE_OS::printf ("%f %qu\n", throughput / 400000000.0, this->samples_count_);
#endif /* 0 */
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
#if 0
      // @@TODO: This is what I really wanted to compute, but it just
      // does not work.
      this->throughput_sum_x_  = rhs.throughput_sum_x_;
      this->throughput_sum_x2_ = rhs.throughput_sum_x2_;
      this->throughput_sum_y_  = rhs.throughput_sum_y_;
      this->throughput_sum_y2_ = rhs.throughput_sum_y2_;
      this->throughput_sum_xy_ = rhs.throughput_sum_xy_;
#endif /* 0 */

      return;
    }


  if (this->throughput_last_ < rhs.throughput_last_)
    this->throughput_last_ = rhs.throughput_last_;

#if 0
  // @@TODO: This is what I really wanted to compute, but it just
  // does not work.
  this->throughput_sum_x_  += rhs.throughput_sum_x_;
  this->throughput_sum_x2_ += rhs.throughput_sum_x2_;
  this->throughput_sum_y_  += rhs.throughput_sum_y_;
  this->throughput_sum_y2_ += rhs.throughput_sum_y2_;
  this->throughput_sum_xy_ += rhs.throughput_sum_xy_;
#endif /* 0 */
}

void
ACE_Throughput_Stats::dump_results (const ACE_TCHAR* msg,
                                    ACE_UINT32 sf)
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

#if 0
  // @@TODO: This is what I really wanted to generate, but it just
  // doesn't work.
  double t_sum_x =
    ACE_CU64_TO_CU32 (this->throughput_sum_x_);// / sf);
  //t_sum_x /= 1000000.0;
  double t_sum_y =
    ACE_CU64_TO_CU32 (this->throughput_sum_y_);
  double t_sum_x2 =
    ACE_CU64_TO_CU32 (this->throughput_sum_x2_);// / (sf*sf));
  //t_sum_x2 /= 1000000.0;
  //t_sum_x2 /= 1000000.0;
  double t_sum_y2 =
    ACE_CU64_TO_CU32 (this->throughput_sum_y2_);
  double t_sum_xy =
    ACE_CU64_TO_CU32 (this->throughput_sum_xy_);// / sf);
  //t_sum_xy /= 1000000.0;
  double t_avgx = t_sum_x / this->samples_count ();
  double t_avgy = t_sum_y / this->samples_count ();

  double t_a =
    (this->samples_count () * t_sum_xy - t_sum_x * t_sum_y)
    / (this->samples_count () * t_sum_x2 - t_sum_x * t_sum_x);
  double t_b = (t_avgy - t_a * t_avgx);

  t_a *= 1000000.0;

  double d_r =
    (t_sum_xy - t_avgx * t_sum_y - t_avgy * t_sum_x
     + this->samples_count () * t_avgx * t_avgy);
  double n_r =
    (t_sum_x2
     - this->samples_count () * t_avgx * t_avgx)
    * (t_sum_y2
       - this->samples_count () * t_avgy * t_avgy);
  double t_r = d_r * d_r / n_r;

  //  ACE_DEBUG ((LM_DEBUG,
  //              "%s throughput: %.2f/%.2f/%.2f/%.6f/%.2f (avg/a/b/r/elapsed)\n",
  //              msg, t_avg, t_a, t_b, t_r, seconds));
  //  ACE_DEBUG ((LM_DEBUG,
  //              "%s        data: %.2f/%.2f/%.2f/%.6f/%.2f (x/x2/y/y2/xy)\n",
  //              msg, t_sum_x, t_sum_x2, t_sum_y, t_sum_y2, t_sum_xy));
#endif
}

void
ACE_Throughput_Stats::dump_throughput (const ACE_TCHAR *msg,
                                       ACE_UINT32 sf,
                                       ACE_UINT64 elapsed_time,
                                       ACE_UINT32 samples_count)
{
#ifndef ACE_NLOGGING
  double seconds =
# if defined ACE_LACKS_LONGLONG_T
    elapsed_time / sf;
#elif  defined (ACE_LACKS_UNSIGNEDLONGLONG_T)
    static_cast<double> (ACE_UINT64_DBLCAST_ADAPTER (
                           ACE_U_LongLong(elapsed_time / sf)));
# else  /* ! ACE_LACKS_LONGLONG_T */
    static_cast<double> (ACE_UINT64_DBLCAST_ADAPTER (elapsed_time / sf));
# endif /* ! ACE_LACKS_LONGLONG_T */
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

