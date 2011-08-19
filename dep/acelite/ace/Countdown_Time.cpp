// $Id: Countdown_Time.cpp 91287 2010-08-05 10:30:49Z johnnyw $

#include "ace/Countdown_Time.h"
#include "ace/OS_NS_sys_time.h"

#if !defined (__ACE_INLINE__)
#include "ace/Countdown_Time.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Countdown_Time::ACE_Countdown_Time (ACE_Time_Value *max_wait_time)
  : max_wait_time_ (max_wait_time),
    stopped_ (false)
{
  this->start ();
}

ACE_Countdown_Time::~ACE_Countdown_Time (void)
{
  this->stop ();
}

void
ACE_Countdown_Time::start (void)
{
  if (this->max_wait_time_ != 0)
    {
      this->start_time_ = ACE_OS::gettimeofday ();
      this->stopped_ = false;
    }
}

void
ACE_Countdown_Time::stop (void)
{
  if (this->max_wait_time_ != 0 && !this->stopped_)
    {
      ACE_Time_Value const elapsed_time =
        ACE_OS::gettimeofday () - this->start_time_;

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
