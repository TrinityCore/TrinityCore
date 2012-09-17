// -*- C++ -*-
//
// $Id: Timer_Queue_Adapters.inl 95368 2011-12-19 13:38:49Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class TQ, class TYPE> ACE_INLINE TQ *
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::timer_queue (void) const
{
  return this->timer_queue_;
}

template<class TQ, class TYPE> ACE_INLINE int
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::timer_queue (TQ *tq)
{
  if (this->delete_timer_queue_)
    delete this->timer_queue_;
  else if (this->timer_queue_)
    this->timer_queue_->close ();
  this->timer_queue_ = tq;
  this->delete_timer_queue_ = false;
  return 0;
}

template<class TQ, class TYPE> ACE_INLINE ACE_thread_t
ACE_Thread_Timer_Queue_Adapter<TQ, TYPE>::thr_id (void) const
{
  return this->thr_id_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
