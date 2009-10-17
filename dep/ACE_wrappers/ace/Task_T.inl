// -*- C++ -*-
//
// $Id: Task_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <ACE_SYNCH_DECL> ACE_INLINE void
ACE_Task<ACE_SYNCH_USE>::water_marks (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds cmd,
                                      size_t wm_size)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::water_marks");
  if (cmd == ACE_IO_Cntl_Msg::SET_LWM)
    this->msg_queue_->low_water_mark (wm_size);
  else /* cmd == ACE_IO_Cntl_Msg::SET_HWM */
    this->msg_queue_->high_water_mark (wm_size);
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::getq (ACE_Message_Block *&mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::getq");
  return this->msg_queue_->dequeue_head (mb, tv);
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::can_put (ACE_Message_Block *)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::can_put");
  ACE_NOTSUP_RETURN (-1);
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::putq (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::putq");
  return this->msg_queue_->enqueue_tail (mb, tv);
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::ungetq (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::ungetq");
  return this->msg_queue_->enqueue_head (mb, tv);
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::flush (u_long flag)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::flush");
  if (ACE_BIT_ENABLED (flag, ACE_Task_Flags::ACE_FLUSHALL))
    return this->msg_queue_ != 0 && this->msg_queue_->close ();
  else
    return -1;   // Note, need to be more careful about what we free...
}

template <ACE_SYNCH_DECL> ACE_INLINE void
ACE_Task<ACE_SYNCH_USE>::msg_queue (ACE_Message_Queue<ACE_SYNCH_USE> *mq)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::msg_queue");
  if (this->delete_msg_queue_)
    {
      delete this->msg_queue_;
      this->delete_msg_queue_ = false;
    }
  this->msg_queue_ = mq;
}

template <ACE_SYNCH_DECL> ACE_Message_Queue<ACE_SYNCH_USE> *
ACE_Task<ACE_SYNCH_USE>::msg_queue (void)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::msg_queue");
  return this->msg_queue_;
}

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::reply (ACE_Message_Block *mb, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::reply");
  return this->sibling ()->put_next (mb, tv);
}

template <ACE_SYNCH_DECL> ACE_INLINE ACE_Task<ACE_SYNCH_USE> *
ACE_Task<ACE_SYNCH_USE>::next (void)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::next");
  return this->next_;
}

template <ACE_SYNCH_DECL> ACE_INLINE void
ACE_Task<ACE_SYNCH_USE>::next (ACE_Task<ACE_SYNCH_USE> *q)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::next");
  this->next_ = q;
}

// Transfer msg to the next ACE_Task.

template <ACE_SYNCH_DECL> ACE_INLINE int
ACE_Task<ACE_SYNCH_USE>::put_next (ACE_Message_Block *msg, ACE_Time_Value *tv)
{
  ACE_TRACE ("ACE_Task<ACE_SYNCH_USE>::put_next");
  return this->next_ == 0 ? -1 : this->next_->put (msg, tv);
}

ACE_END_VERSIONED_NAMESPACE_DECL
