#include "ace/Countdown_Time.h"
#include "ace/OS_NS_sys_time.h"

ACE_RCSID (ace,
           Countdown_Time,
           "$Id: Countdown_Time.cpp 80826 2008-03-04 14:51:23Z wotte $")

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

bool
ACE_Countdown_Time::stopped (void) const
{
  return stopped_;
}

void
ACE_Countdown_Time::stop (void)
{
  if (this->max_wait_time_ != 0 && this->stopped_ == false)
    {
      ACE_Time_Value elapsed_time = ACE_OS::gettimeofday () - this->start_time_;

      if (*this->max_wait_time_ > elapsed_time)
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

void
ACE_Countdown_Time::update (void)
{
  this->stop ();
  this->start ();
}

ACE_END_VERSIONED_NAMESPACE_DECL

