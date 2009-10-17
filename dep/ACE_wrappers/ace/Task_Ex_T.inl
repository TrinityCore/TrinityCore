// -*- C++ -*-
//
// $Id: Task_Ex_T.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE void
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::water_marks (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd,
                                    size_t wm_size)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::water_marks");
  if (cmd == ACE_IO_Cntl_Msg::SET_LWM)
    this->msg_queue_->low_water_mark (wm_size);
  else /* cmd == ACE_IO_Cntl_Msg::SET_HWM */
    this->msg_queue_->high_water_mark (wm_size);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::getq (ACE_MESSAGE_TYPE *&mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::getq");
  return this->msg_queue_->dequeue_head (mb, tv);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::can_put (ACE_MESSAGE_TYPE *)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::can_put");
  ACE_NOTSUP_RETURN (-1);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::putq (ACE_MESSAGE_TYPE *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::putq");
  return this->msg_queue_->enqueue_tail (mb, tv);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::ungetq (ACE_MESSAGE_TYPE *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::ungetq");
  return this->msg_queue_->enqueue_head (mb, tv);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::flush (u_long flag)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::flush");
  if (ACE_BIT_ENABLED (flag, ACE_Task_Flags::ACE_FLUSHALL))
    return this->msg_queue_ != 0 && this->msg_queue_->close ();
  else
    return -1;   // Note, need to be more careful about what we free...
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE void
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::msg_queue (ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE> *mq)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::msg_queue");
  if (this->delete_msg_queue_)
    {
      delete this->msg_queue_;
      this->delete_msg_queue_ = false;
    }
  this->msg_queue_ = mq;
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE> *
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::msg_queue (void)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::msg_queue");
  return this->msg_queue_;
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::reply (ACE_MESSAGE_TYPE *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::reply");
  ACE_UNUSED_ARG (mb);
  ACE_UNUSED_ARG (tv);
  return -1 ; // this->sibling ()->put_next (mb, tv);
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE ACE_Task<ACE_SYNCH_USE> *
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::next (void)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::next");
  return this->next_;
}
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE void
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::next (ACE_Task<ACE_SYNCH_USE> *q)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::next");
  this->next_ = q;
}
// Transfer msg to the next ACE_Task_Ex.
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE> ACE_INLINE int
ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::put_next (
  ACE_MESSAGE_TYPE * /* msg */,
  ACE_Time_Value * /* tv */)
{
  ACE_TRACE ("ACE_Task_Ex<ACE_SYNCH_USE,ACE_MESSAGE_TYPE>::put_next");
  return  -1; // this->next_ == 0 ? -1 : this->next_->put (msg, tv);
}
ACE_END_VERSIONED_NAMESPACE_DECL
