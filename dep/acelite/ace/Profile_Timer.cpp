// $Id: Profile_Timer.cpp 95761 2012-05-15 18:23:04Z johnnyw $

#include "ace/Profile_Timer.h"

#if !defined (__ACE_INLINE__)
# include "ace/Profile_Timer.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"

#if defined (ACE_HAS_PRUSAGE_T)
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_unistd.h"
#endif



#if (defined (ACE_HAS_PRUSAGE_T) || defined (ACE_HAS_GETRUSAGE)) && !defined (ACE_WIN32)

#include "ace/OS_NS_stdio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Profile_Timer)


void
ACE_Profile_Timer::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Profile_Timer::dump");
#endif /* ACE_HAS_DUMP */
}

// Initialize interval timer.

ACE_Profile_Timer::ACE_Profile_Timer (void)
{
  ACE_TRACE ("ACE_Profile_Timer::ACE_Profile_Timer");
  ACE_OS::memset (&this->end_usage_, 0, sizeof this->end_usage_);
  ACE_OS::memset (&this->begin_usage_, 0, sizeof this->begin_usage_);
  ACE_OS::memset (&this->last_usage_, 0, sizeof this->last_usage_);

#  if defined (ACE_HAS_PRUSAGE_T)
  ACE_OS::memset (&this->last_usage_, 0, sizeof this->last_usage_);
  char buf[20];
  ACE_OS::sprintf (buf, "/proc/%d", static_cast<int> (ACE_OS::getpid ()));

  this->proc_handle_ = ACE_OS::open (buf, O_RDONLY, 0);
  if (this->proc_handle_ == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                buf));
#  elif defined (ACE_HAS_GETRUSAGE)
  ACE_OS::memset (&this->begin_time_, 0, sizeof this->begin_time_);
  ACE_OS::memset (&this->end_time_, 0, sizeof this->end_time_);
  ACE_OS::memset (&this->last_time_, 0, sizeof this->last_time_);
#  endif /* ACE_HAS_PRUSAGE_T */
}

// Terminate the interval timer.
ACE_Profile_Timer::~ACE_Profile_Timer (void)
{
  ACE_TRACE ("ACE_Profile_Timer::~ACE_Profile_Timer");
#  if defined (ACE_HAS_PRUSAGE_T)
  if (ACE_OS::close (this->proc_handle_) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Profile_Timer::~ACE_Profile_Timer")));
#  endif /* ACE_HAS_PRUSAGE_T */
}

// Return the resource utilization.

void
ACE_Profile_Timer::get_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::get_rusage");
  usage = this->end_usage_;
}

#  if defined (ACE_HAS_PRUSAGE_T)

// Compute the amount of resource utilization since the start time.

void
ACE_Profile_Timer::elapsed_rusage (ACE_Profile_Timer::Rusage &rusage)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_rusage");
  rusage.pr_lwpid =
    this->end_usage_.pr_lwpid - this->last_usage_.pr_lwpid;
  rusage.pr_count =
    this->end_usage_.pr_count - this->last_usage_.pr_count;
  rusage.pr_minf  =
    this->end_usage_.pr_minf - this->last_usage_.pr_minf;
  rusage.pr_majf  =
    this->end_usage_.pr_majf - this->last_usage_.pr_majf;
  rusage.pr_inblk =
    this->end_usage_.pr_inblk - this->last_usage_.pr_inblk;
  rusage.pr_oublk =
    this->end_usage_.pr_oublk - this->last_usage_.pr_oublk;
  rusage.pr_msnd =
    this->end_usage_.pr_msnd - this->last_usage_.pr_msnd;
  rusage.pr_mrcv =
    this->end_usage_.pr_mrcv - this->last_usage_.pr_mrcv;
  rusage.pr_sigs =
    this->end_usage_.pr_sigs - this->last_usage_.pr_sigs;
  this->subtract (rusage.pr_wtime,
                  this->end_usage_.pr_wtime,
                  this->last_usage_.pr_wtime);
  this->subtract (rusage.pr_ltime,
                  this->end_usage_.pr_ltime,
                  this->last_usage_.pr_ltime);
  this->subtract (rusage.pr_slptime,
                  this->end_usage_.pr_slptime,
                  this->last_usage_.pr_slptime);
  rusage.pr_vctx  =
    this->end_usage_.pr_vctx - this->last_usage_.pr_vctx;
  rusage.pr_ictx  =
    this->end_usage_.pr_ictx - this->last_usage_.pr_ictx;
  rusage.pr_sysc  =
    this->end_usage_.pr_sysc - this->last_usage_.pr_sysc;
  rusage.pr_ioch  =
    this->end_usage_.pr_ioch - this->last_usage_.pr_ioch;
}

// Compute the elapsed time.

void
ACE_Profile_Timer::compute_times (ACE_Elapsed_Time &et)
{
  ACE_TRACE ("ACE_Profile_Timer::compute_times");
  timespec_t td;

  ACE_Profile_Timer::Rusage &end = this->end_usage_;
  ACE_Profile_Timer::Rusage &begin = this->begin_usage_;

  this->subtract (td, end.pr_tstamp, begin.pr_tstamp);
  // Convert nanoseconds into seconds.
  et.real_time = td.tv_sec + ((double) td.tv_nsec) / ACE_ONE_SECOND_IN_NSECS;
  this->subtract (td, end.pr_utime, begin.pr_utime);
  // Convert nanoseconds into seconds.
  et.user_time = td.tv_sec + ((double) td.tv_nsec) / ACE_ONE_SECOND_IN_NSECS;
  this->subtract (td, end.pr_stime,  begin.pr_stime);
  // Convert nanoseconds into seconds.
  et.system_time = td.tv_sec + ((double) td.tv_nsec) / ACE_ONE_SECOND_IN_NSECS;
}

// Determine the difference between T1 and T2.

void
ACE_Profile_Timer::subtract (timespec_t &tdiff, timespec_t &t1, timespec_t &t0)
{
  ACE_TRACE ("ACE_Profile_Timer::subtract");
  tdiff.tv_sec  = t1.tv_sec - t0.tv_sec;
  tdiff.tv_nsec = t1.tv_nsec - t0.tv_nsec;

  // Normalize the time.

  while (tdiff.tv_nsec < 0)
    {
      tdiff.tv_sec--;
      tdiff.tv_nsec += ACE_ONE_SECOND_IN_NSECS;
    }
}

#  elif defined (ACE_HAS_GETRUSAGE)
// Compute the amount of resource utilization since the start time.

void
ACE_Profile_Timer::elapsed_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_rusage");
#    if !defined (ACE_HAS_LIMITED_RUSAGE_T)
  // integral shared memory size
  usage.ru_ixrss =
    this->end_usage_.ru_ixrss - this->last_usage_.ru_ixrss;
  // integral unshared data "
  usage.ru_idrss =
    this->end_usage_.ru_idrss - this->last_usage_.ru_idrss;
  // integral unshared stack "
  usage.ru_isrss =
    this->end_usage_.ru_isrss - this->last_usage_.ru_isrss;
  // page reclaims - total vmfaults
  usage.ru_minflt =
    this->end_usage_.ru_minflt - this->last_usage_.ru_minflt;
  // page faults
  usage.ru_majflt =
    this->end_usage_.ru_majflt - this->last_usage_.ru_majflt;
  // swaps
  usage.ru_nswap =
    this->end_usage_.ru_nswap - this->last_usage_.ru_nswap;
  // block input operations
  usage.ru_inblock =
    this->end_usage_.ru_inblock - this->last_usage_.ru_inblock;
  // block output operations
  usage.ru_oublock =
    this->end_usage_.ru_oublock - this->last_usage_.ru_oublock;
  // messages sent
  usage.ru_msgsnd =
    this->end_usage_.ru_msgsnd - this->last_usage_.ru_msgsnd;
  // messages received
  usage.ru_msgrcv =
    this->end_usage_.ru_msgrcv - this->last_usage_.ru_msgrcv;
  // signals received
  usage.ru_nsignals =
    this->end_usage_.ru_nsignals - this->last_usage_.ru_nsignals;
  // voluntary context switches
  usage.ru_nvcsw =
    this->end_usage_.ru_nvcsw - this->last_usage_.ru_nvcsw;
  // involuntary context switches
  usage.ru_nivcsw =
    this->end_usage_.ru_nivcsw - this->last_usage_.ru_nivcsw;
  this->subtract (usage.ru_utime,
                  this->end_usage_.ru_utime,
                  this->last_usage_.ru_utime);
  this->subtract (usage.ru_stime,
                  this->end_usage_.ru_stime,
                  this->last_usage_.ru_stime);
#    else
  ACE_UNUSED_ARG(usage);
#    endif /* ACE_HAS_LIMITED_RUSAGE_T */
}

void
ACE_Profile_Timer::compute_times (ACE_Elapsed_Time &et)
{
  ACE_TRACE ("ACE_Profile_Timer::compute_times");

  timeval td;

  this->subtract (td, this->end_time_, this->begin_time_);
  et.real_time = td.tv_sec + ((double) td.tv_usec) / ACE_ONE_SECOND_IN_USECS;

  this->subtract (td, this->end_usage_.ru_utime, this->begin_usage_.ru_utime);
  et.user_time = td.tv_sec + ((double) td.tv_usec) / ACE_ONE_SECOND_IN_USECS;

  this->subtract (td, this->end_usage_.ru_stime,  this->begin_usage_.ru_stime);
  et.system_time = td.tv_sec + ((double) td.tv_usec) / ACE_ONE_SECOND_IN_USECS;
}

// Determine the difference between T1 and T2.

void
ACE_Profile_Timer::subtract (timeval &tdiff, timeval &t1, timeval &t0)
{
  ACE_TRACE ("ACE_Profile_Timer::subtract");
  tdiff.tv_sec  = t1.tv_sec - t0.tv_sec;
  tdiff.tv_usec = t1.tv_usec - t0.tv_usec;

  // Normalize the time.

  while (tdiff.tv_usec < 0)
    {
      tdiff.tv_sec--;
      tdiff.tv_usec += ACE_ONE_SECOND_IN_USECS;
    }
}

#  endif /* ACE_HAS_PRUSAGE_T */

// Compute the amount of time that has elapsed between start and stop.

int
ACE_Profile_Timer::elapsed_time (ACE_Elapsed_Time &et)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_time");
  this->compute_times (et);
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#elif defined (ACE_WIN32) /* defined (ACE_HAS_PRUSAGE_T) || defined (ACE_HAS_GETRUSAGE) */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Profile_Timer::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Profile_Timer::dump");
  timer_.dump ();
#endif /* ACE_HAS_DUMP */
}

// Initialize interval timer.
ACE_Profile_Timer::ACE_Profile_Timer (void)
  : timer_ ()
{
  ACE_TRACE ("ACE_Profile_Timer::ACE_Profile_Timer");
#  if defined (ACE_HAS_GETRUSAGE)

  ACE_OS::memset (&this->end_usage_, 0, sizeof this->end_usage_);
  ACE_OS::memset (&this->begin_usage_, 0, sizeof this->begin_usage_);
  ACE_OS::memset (&this->last_usage_, 0, sizeof this->last_usage_);

  ACE_OS::memset (&this->begin_time_, 0, sizeof this->begin_time_);
  ACE_OS::memset (&this->end_time_, 0, sizeof this->end_time_);
  ACE_OS::memset (&this->last_time_, 0, sizeof this->last_time_);
#  endif /* ACE_HAS_GETRUSAGE */
}

int
ACE_Profile_Timer::elapsed_time (ACE_Elapsed_Time &et)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_time");

  ACE_hrtime_t delta_t; // nanoseconds
  timer_.elapsed_time (delta_t);
  et.real_time = (__int64) delta_t / (double) ACE_ONE_SECOND_IN_NSECS;
#  if defined (ACE_HAS_GETRUSAGE)
  ACE_Time_Value atv = ACE_Time_Value (this->end_usage_.ru_utime)
                       - ACE_Time_Value (this->begin_usage_.ru_utime);
  et.user_time = atv.sec () + ((double) atv.usec ()) / ACE_ONE_SECOND_IN_USECS;

  atv = ACE_Time_Value (this->end_usage_.ru_stime)
        - ACE_Time_Value (this->begin_usage_.ru_stime);
  et.system_time = atv.sec () + ((double) atv.usec ()) / ACE_ONE_SECOND_IN_USECS;
#  else /* ACE_HAS_GETRUSAGE */
  et.user_time = 0;
  et.system_time = 0;
#  endif /* ACE_HAS_GETRUSAGE */

  return 0;
}

// Return the resource utilization.

void
ACE_Profile_Timer::get_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::get_rusage");
#  if defined (ACE_HAS_GETRUSAGE)
  usage = this->end_usage_;
#  else /* ACE_HAS_GETRUSAGE */
  usage = 0;
#  endif /* ACE_HAS_GETRUSAGE */
}

// Compute the amount of resource utilization since the start time.

void
ACE_Profile_Timer::elapsed_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_rusage");

#  if defined (ACE_HAS_GETRUSAGE)
  // Use ACE_Time_Value's as intermediate because the type of ru_utime can
  // be multiple types and using the - operator is not safe when this are
  // 64bit FILETIMEs on Windows
  ACE_Time_Value end_ru_utime (this->end_usage_.ru_utime);
  ACE_Time_Value begin_ru_utime (this->begin_usage_.ru_utime);
  usage.ru_utime = end_ru_utime - begin_ru_utime;

  ACE_Time_Value end_ru_stime (this->end_usage_.ru_stime);
  ACE_Time_Value begin_ru_stime (this->begin_usage_.ru_stime);
  usage.ru_stime = end_ru_stime - begin_ru_stime;
#  else /* ACE_HAS_GETRUSAGE */
  usage = 0;
#  endif /* ACE_HAS_GETRUSAGE */
}

#  if defined (ACE_HAS_GETRUSAGE)
// Determine the difference between T1 and T2.

void
ACE_Profile_Timer::subtract (timeval &tdiff, timeval &t1, timeval &t0)
{
  ACE_TRACE ("ACE_Profile_Timer::subtract");
  tdiff.tv_sec  = t1.tv_sec - t0.tv_sec;
  tdiff.tv_usec = t1.tv_usec - t0.tv_usec;

  // Normalize the time.

  while (tdiff.tv_usec < 0)
    {
      tdiff.tv_sec--;
      tdiff.tv_usec += ACE_ONE_SECOND_IN_USECS;
    }
}
#  endif /* ACE_HAS_GETRUSAGE */

ACE_END_VERSIONED_NAMESPACE_DECL

#else

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Profile_Timer::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Profile_Timer::dump");
  timer_.dump ();
#endif /* ACE_HAS_DUMP */
}

ACE_Profile_Timer::ACE_Profile_Timer (void)
  : timer_ ()
{
  ACE_TRACE ("ACE_Profile_Timer::ACE_Profile_Timer");
}

int
ACE_Profile_Timer::elapsed_time (ACE_Elapsed_Time &et)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_time");

  ACE_hrtime_t delta_t; /* nanoseconds */
  timer_.elapsed_time (delta_t);

  et.real_time = delta_t / (double) ACE_ONE_SECOND_IN_NSECS;

  et.user_time = 0;
  et.system_time = 0;

  return 0;
}

void
ACE_Profile_Timer::get_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::get_rusage");
  usage = 0;
}


void
ACE_Profile_Timer::elapsed_rusage (ACE_Profile_Timer::Rusage &usage)
{
  ACE_TRACE ("ACE_Profile_Timer::elapsed_rusage");
  usage = 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* defined (ACE_HAS_PRUSAGE_T) ||
          defined (ACE_HAS_GETRUSAGE) && !defined (ACE_WIN32) */
