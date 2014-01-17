// $Id: Time_Value_T.cpp 96061 2012-08-16 09:36:07Z mcorino $

#ifndef ACE_TIME_VALUE_T_CPP
#define ACE_TIME_VALUE_T_CPP

#include "ace/Time_Value_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Time_Value_T.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_Memory.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TIME_POLICY>
ACE_Time_Value
ACE_Time_Value_T<TIME_POLICY>::now () const
{
  return this->time_policy_ ();
}

template <class TIME_POLICY>
ACE_Time_Value
ACE_Time_Value_T<TIME_POLICY>::to_relative_time () const
{
  return (*this) - this->time_policy_ ();
}

template <class TIME_POLICY>
ACE_Time_Value
ACE_Time_Value_T<TIME_POLICY>::to_absolute_time () const
{
  return (*this) + this->time_policy_ ();
}

template <class TIME_POLICY>
ACE_Time_Value *
ACE_Time_Value_T<TIME_POLICY>::duplicate () const
{
  ACE_Time_Value_T<TIME_POLICY> * tmp = 0;
  ACE_NEW_RETURN (tmp, ACE_Time_Value_T<TIME_POLICY> (*this), 0);
  return tmp;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TIME_VALUE_T_CPP */
