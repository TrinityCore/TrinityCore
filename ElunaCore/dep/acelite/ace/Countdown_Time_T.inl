// -*- C++ -*-
//
// $Id: Countdown_Time_T.inl 95332 2011-12-15 11:09:41Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename TIME_POLICY> ACE_INLINE bool
ACE_Countdown_Time_T<TIME_POLICY>::stopped (void) const
{
  return stopped_;
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Countdown_Time_T<TIME_POLICY>::update (void)
{
  this->stop ();
  this->start ();
}

template <typename TIME_POLICY> ACE_INLINE void
ACE_Countdown_Time_T<TIME_POLICY>::set_time_policy(TIME_POLICY const & time_policy)
{
  this->time_policy_ = time_policy;
}

ACE_END_VERSIONED_NAMESPACE_DECL
