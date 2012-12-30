// -*- C++ -*-
// $Id: Event.inl 96220 2012-11-06 10:03:41Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TIME_POLICY>
ACE_Time_Value_T<TIME_POLICY>
ACE_Event_T<TIME_POLICY>::gettimeofday (void) const
{
  return this->time_policy_ ();
}

template <class TIME_POLICY>
void
ACE_Event_T<TIME_POLICY>::set_time_policy (TIME_POLICY const & rhs)
{
  this->time_policy_ = rhs;
}

ACE_END_VERSIONED_NAMESPACE_DECL
