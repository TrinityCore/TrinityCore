// -*- C++ -*-
//
// $Id: Timer_Queue_Iterator.inl 95332 2011-12-15 11:09:41Z mcorino $

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

ACE_END_VERSIONED_NAMESPACE_DECL
