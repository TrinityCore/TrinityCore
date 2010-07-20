// -*- C++ -*-
//
// $Id: Timer_Queue_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set (const TYPE &type,
                             const void *a,
                             const ACE_Time_Value &t,
                             const ACE_Time_Value &i,
                             ACE_Timer_Node_T<TYPE> *n,
                             long timer_id)
{
  this->type_ = type;
  this->act_ = a;
  this->timer_value_ = t;
  this->interval_ = i;
  this->next_ = n;
  this->timer_id_ = timer_id;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set (const TYPE &type,
                             const void *a,
                             const ACE_Time_Value &t,
                             const ACE_Time_Value &i,
                             ACE_Timer_Node_T<TYPE> *p,
                             ACE_Timer_Node_T<TYPE> *n,
                             long timer_id)
{
  this->type_ = type;
  this->act_ = a;
  this->timer_value_ = t;
  this->interval_ = i;
  this->prev_ = p;
  this->next_ = n;
  this->timer_id_ = timer_id;
}

template <class TYPE> ACE_INLINE TYPE &
ACE_Timer_Node_T<TYPE>::get_type (void)
{
  return this->type_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_type (TYPE &type)
{
  this->type_ = type;
}

template <class TYPE> ACE_INLINE const void *
ACE_Timer_Node_T<TYPE>::get_act (void)
{
  return this->act_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_act (void *act)
{
  this->act_ = act;
}

template <class TYPE> ACE_INLINE const ACE_Time_Value &
ACE_Timer_Node_T<TYPE>::get_timer_value (void) const
{
  return this->timer_value_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_timer_value (const ACE_Time_Value &timer_value)
{
  this->timer_value_ = timer_value;
}

template <class TYPE> ACE_INLINE const ACE_Time_Value &
ACE_Timer_Node_T<TYPE>::get_interval (void) const
{
  return this->interval_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_interval (const ACE_Time_Value &interval)
{
  this->interval_ = interval;
}

template <class TYPE> ACE_INLINE ACE_Timer_Node_T<TYPE> *
ACE_Timer_Node_T<TYPE>::get_prev (void)
{
  return this->prev_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_prev (ACE_Timer_Node_T<TYPE> *prev)
{
  this->prev_ = prev;
}

template <class TYPE> ACE_INLINE ACE_Timer_Node_T<TYPE> *
ACE_Timer_Node_T<TYPE>::get_next (void)
{
  return this->next_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_next (ACE_Timer_Node_T<TYPE> *next)
{
  this->next_ = next;
}

template <class TYPE> ACE_INLINE long
ACE_Timer_Node_T<TYPE>::get_timer_id (void) const
{
  return this->timer_id_;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::set_timer_id (long timer_id)
{
  this->timer_id_ = timer_id;
}

template <class TYPE> ACE_INLINE void
ACE_Timer_Node_T<TYPE>::get_dispatch_info (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info)
{
  // Yes, do a copy
  info.type_ = this->type_;
  info.act_  = this->act_;
  info.recurring_timer_ =
    this->interval_ > ACE_Time_Value::zero;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::timer_skew (const ACE_Time_Value &skew)
{
  timer_skew_ = skew;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE const ACE_Time_Value &
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::timer_skew (void) const
{
  return timer_skew_;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE int
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::expire (void)
{
  if (!this->is_empty ())
    return this->expire (this->gettimeofday () + timer_skew_);
  else
    return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::dispatch_info (const ACE_Time_Value &cur_time,
                                                           ACE_Timer_Node_Dispatch_Info_T<TYPE> &info)
{
  ACE_TRACE ("ACE_Timer_Queue_T::dispatch_info");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, 0));

  return this->dispatch_info_i (cur_time, info);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::upcall (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                                                    const ACE_Time_Value &cur_time)
{
  this->upcall_functor ().timeout (*this,
                                   info.type_,
                                   info.act_,
                                   info.recurring_timer_,
                                   cur_time);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::preinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
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

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::postinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
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

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE ACE_Time_Value
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::gettimeofday (void)
{
  // Invoke gettimeofday via pointer to function.
  return this->gettimeofday_ ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE void
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::gettimeofday (ACE_Time_Value (*gettimeofday)(void))
{
  this->gettimeofday_ = gettimeofday;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_INLINE FUNCTOR &
ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>::upcall_functor (void)
{
  return *this->upcall_functor_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
