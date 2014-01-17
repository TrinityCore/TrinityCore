// -*- C++ -*-
//
// $Id: Timer_Queue_T.inl 95332 2011-12-15 11:09:41Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TYPE, class FUNCTOR> ACE_INLINE FUNCTOR &
ACE_Timer_Queue_Upcall_Base<TYPE, FUNCTOR>::upcall_functor (void)
{
  return *this->upcall_functor_;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::timer_skew (const ACE_Time_Value &skew)
{
  timer_skew_ = skew;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE const ACE_Time_Value &
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::timer_skew (void) const
{
  return timer_skew_;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE int
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::expire (void)
{
  if (!this->is_empty ())
    return this->expire (this->gettimeofday_static () + timer_skew_);
  else
    return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> int
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::dispatch_info (const ACE_Time_Value &cur_time,
                                                           ACE_Timer_Node_Dispatch_Info_T<TYPE> &info)
{
  ACE_TRACE ("ACE_Timer_Queue_T::dispatch_info");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, 0));

  return this->dispatch_info_i (cur_time, info);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::upcall (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                                                    const ACE_Time_Value &cur_time)
{
  this->upcall_functor ().timeout (*this,
                                   info.type_,
                                   info.act_,
                                   info.recurring_timer_,
                                   cur_time);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::preinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                                                       const ACE_Time_Value &cur_time,
                                                       const void *&upcall_act)
{
  this->upcall_functor ().preinvoke (*this,
                                     info.type_,
                                     info.act_,
                                     info.recurring_timer_,
                                     cur_time,
                                     upcall_act);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::postinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                                                        const ACE_Time_Value &cur_time,
                                                        const void *upcall_act)
{
  this->upcall_functor ().postinvoke (*this,
                                      info.type_,
                                      info.act_,
                                      info.recurring_timer_,
                                      cur_time,
                                      upcall_act);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE ACE_Time_Value
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::gettimeofday_static (void)
{
  // Get the current time according to the time policy.
  return this->time_policy_ ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>::set_time_policy (TIME_POLICY const & rhs)
{
  this->time_policy_ = rhs;
}

ACE_END_VERSIONED_NAMESPACE_DECL
