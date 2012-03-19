// $Id: Basic_Stats.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/Basic_Stats.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Basic_Stats.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Basic_Stats::accumulate (const ACE_Basic_Stats &rhs)
{
  if (rhs.samples_count_ == 0)
    return;

  if (this->samples_count_ == 0)
    {
      this->min_ = rhs.min_;
      this->min_at_ = rhs.min_at_;

      this->max_ = rhs.max_;
      this->max_at_ = rhs.max_at_;
    }
  else
    {
      if (this->min_ > rhs.min_)
        {
          this->min_ = rhs.min_;
          this->min_at_ = rhs.min_at_;
        }
      if (this->max_ < rhs.max_)
        {
          this->max_ = rhs.max_;
          this->max_at_ = rhs.max_at_;
        }
    }

  this->samples_count_ += rhs.samples_count_;
  this->sum_ += rhs.sum_;
}

void
ACE_Basic_Stats::dump_results (const ACE_TCHAR *msg, ACE_UINT32 sf) const
{
#ifndef ACE_NLOGGING
  if (this->samples_count () == 0u)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%s : no data collected\n"), msg));
      return;
    }

  ACE_UINT64 avg = this->sum_ / this->samples_count_;

  ACE_UINT64 l_min = this->min_ / sf;
  ACE_UINT64 l_max = this->max_ / sf;
  ACE_UINT64 l_avg = avg / sf;

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("%s latency   : %Q[%d]/%Q/%Q[%d] (min/avg/max)\n"),
              msg,
              l_min, this->min_at_,
              l_avg,
              l_max, this->max_at_));

#else
  ACE_UNUSED_ARG (msg);
  ACE_UNUSED_ARG (sf);
#endif /* ACE_NLOGGING */
}

ACE_END_VERSIONED_NAMESPACE_DECL
