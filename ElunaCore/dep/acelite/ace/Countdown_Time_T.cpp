// $Id: Countdown_Time_T.cpp 95332 2011-12-15 11:09:41Z mcorino $

#ifndef ACE_COUNTDOWN_TIME_T_CPP
#define ACE_COUNTDOWN_TIME_T_CPP

#include "ace/Countdown_Time_T.h"

#if !defined (__ACE_INLINE__)
#include "ace/Countdown_Time_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename TIME_POLICY> ACE_INLINE
ACE_Countdown_Time_T<TIME_POLICY>::ACE_Countdown_Time_T (ACE_Time_Value *max_wait_time,
                                                         TIME_POLICY const & time_policy)
  : time_policy_ (time_policy),
    max_wait_time_ (max_wait_time),
    stopped_ (false)
{
  this->start ();
}

template <typename TIME_POLICY> ACE_INLINE
ACE_Countdown_Time_T<TIME_POLICY>::~ACE_Countdown_Time_T (void)
{
  this->stop ();
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Countdown_Time_T<TIME_POLICY>::start (void)
{
  if (this->max_wait_time_ != 0)
    {
      this->start_time_ = this->time_policy_ ();
      this->stopped_ = false;
    }
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Countdown_Time_T<TIME_POLICY>::stop (void)
{
  if (this->max_wait_time_ != 0 && !this->stopped_)
    {
      ACE_Time_Value const elapsed_time =
          this->time_policy_ () - this->start_time_;

      if (elapsed_time >= ACE_Time_Value::zero &&
          *this->max_wait_time_ > elapsed_time)
        {
          *this->max_wait_time_ -= elapsed_time;
        }
      else
        {
          // Used all of timeout.
          *this->max_wait_time_ = ACE_Time_Value::zero;
          // errno = ETIME;
        }
      this->stopped_ = true;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_COUNTDOWN_TIME_T_CPP */
