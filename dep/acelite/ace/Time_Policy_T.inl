// -*- C++ -*-
//
// $Id: Time_Policy_T.inl 96066 2012-08-16 12:45:46Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename TIME_POLICY>
ACE_INLINE
ACE_Time_Policy_T<TIME_POLICY>::ACE_Time_Policy_T (TIME_POLICY const & time_policy)
  : time_policy_ (time_policy)
{
}

template <typename TIME_POLICY>
ACE_INLINE ACE_Time_Value_T<ACE_Delegating_Time_Policy>
ACE_Time_Policy_T<TIME_POLICY>::operator() () const
{
  return this->gettimeofday ();
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Time_Policy_T<TIME_POLICY>::set_gettimeofday (ACE_Time_Value (*)(void))
{
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Time_Policy_T<TIME_POLICY>::set_time_policy(TIME_POLICY const & time_policy)
{
  this->time_policy_ = time_policy;
}

ACE_END_VERSIONED_NAMESPACE_DECL
