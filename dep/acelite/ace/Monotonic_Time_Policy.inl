// -*- C++ -*-
//
// $Id: Monotonic_Time_Policy.inl 96095 2012-08-23 06:36:25Z johnnyw $

#include "ace/OS_NS_sys_time.h"
#include "ace/High_Res_Timer.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Time_Value_T<ACE_Monotonic_Time_Policy>
ACE_Monotonic_Time_Policy::operator()() const
{
# if defined (ACE_WIN32)
  return ACE_Time_Value_T<ACE_Monotonic_Time_Policy> (ACE_High_Res_Timer::gettimeofday_hr ());
#elif (defined (_POSIX_MONOTONIC_CLOCK) && !defined (ACE_LACKS_MONOTONIC_TIME)) || defined (ACE_HAS_CLOCK_GETTIME_MONOTONIC)
  struct timespec ts;

  if (ACE_OS::clock_gettime (CLOCK_MONOTONIC, &ts) == 0)
    return ACE_Time_Value_T<ACE_Monotonic_Time_Policy>(ts);
  else
    return ACE_Time_Value_T<ACE_Monotonic_Time_Policy> (ACE_Time_Value::zero);
#else
  return ACE_Time_Value_T<ACE_Monotonic_Time_Policy> (ACE_Time_Value::zero);
#endif
}

ACE_INLINE void
ACE_Monotonic_Time_Policy::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
