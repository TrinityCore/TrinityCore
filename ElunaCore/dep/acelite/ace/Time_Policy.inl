// -*- C++ -*-
//
// $Id: Time_Policy.inl 96061 2012-08-16 09:36:07Z mcorino $

#include "ace/OS_NS_sys_time.h"
#include "ace/High_Res_Timer.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Time_Value_T<ACE_System_Time_Policy>
ACE_System_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_System_Time_Policy> (ACE_OS::gettimeofday());
}

ACE_INLINE void
ACE_System_Time_Policy::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

ACE_INLINE ACE_Time_Value_T<ACE_HR_Time_Policy>
ACE_HR_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_HR_Time_Policy> (ACE_High_Res_Timer::gettimeofday_hr ());
}

ACE_INLINE void
ACE_HR_Time_Policy::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

ACE_INLINE
ACE_FPointer_Time_Policy::ACE_FPointer_Time_Policy()
  : function_(ACE_OS::gettimeofday)
{
}

ACE_INLINE
ACE_FPointer_Time_Policy::
ACE_FPointer_Time_Policy(ACE_FPointer_Time_Policy::FPtr f)
  : function_(f)
{
}

ACE_INLINE ACE_Time_Value_T<ACE_FPointer_Time_Policy>
ACE_FPointer_Time_Policy::operator()() const
{
  return ACE_Time_Value_T<ACE_FPointer_Time_Policy> ((*this->function_)(), *this);
}

ACE_INLINE void
ACE_FPointer_Time_Policy::set_gettimeofday (ACE_Time_Value (*f)(void))
{
  this->function_ = f;
}

ACE_INLINE ACE_Time_Value_T<ACE_Delegating_Time_Policy>
ACE_Dynamic_Time_Policy_Base::operator()() const
{
  return this->gettimeofday ();
}

ACE_INLINE void
ACE_Dynamic_Time_Policy_Base::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

ACE_INLINE ACE_Time_Value_T<ACE_Delegating_Time_Policy>
ACE_Delegating_Time_Policy::operator()() const
{
  return (*this->delegate_) ();
}

ACE_INLINE void
ACE_Delegating_Time_Policy::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

ACE_INLINE void
ACE_Delegating_Time_Policy::set_delegate (ACE_Dynamic_Time_Policy_Base const * delegate)
{
  if (delegate != 0)
    {
      this->delegate_ = delegate;
    }
}

ACE_INLINE ACE_Delegating_Time_Policy&
ACE_Delegating_Time_Policy::operator =(ACE_Delegating_Time_Policy const & pol)
{
  this->delegate_ = pol.delegate_;
  return *this;
}

ACE_END_VERSIONED_NAMESPACE_DECL
