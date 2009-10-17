// -*- C++ -*-
//
// $Id: Message_Block.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ACE_Data_Block *
ACE_Message_Block::data_block (void) const
{
  ACE_TRACE ("ACE_Message_Block::data_block");
  return this->data_block_;
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::set_self_flags (ACE_Message_Block::Message_Flags more_flags)
{
  ACE_TRACE ("ACE_Message_Block::set_self_flags");
  // Later we might mask more_glags so that user can't change internal
  // ones: more_flags &= ~(USER_FLAGS -1).
  return ACE_SET_BITS (this->flags_, more_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::clr_self_flags (ACE_Message_Block::Message_Flags less_flags)
{
  ACE_TRACE ("ACE_Message_Block::clr_self_flags");
  // Later we might mask more_flags so that user can't change internal
  // ones: less_flags &= ~(USER_FLAGS -1).
  return ACE_CLR_BITS (this->flags_, less_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::self_flags (void) const
{
  ACE_TRACE ("ACE_Message_Block::self_flags");
  return this->flags_;
}
ACE_INLINE int
ACE_Data_Block::reference_count_i (void) const
{
  return reference_count_;
}
ACE_INLINE int
ACE_Message_Block::reference_count (void) const
{
  return data_block () ? data_block ()->reference_count () : 0;
}
ACE_INLINE char *
ACE_Data_Block::base (void) const
{
  ACE_TRACE ("ACE_Data_Block::base");
  return this->base_;
}
ACE_INLINE size_t
ACE_Data_Block::size (void) const
{
  ACE_TRACE ("ACE_Data_Block::size");
  return this->cur_size_;
}
ACE_INLINE size_t
ACE_Data_Block::capacity (void) const
{
  ACE_TRACE ("ACE_Data_Block::capacity");
  return this->max_size_;
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Data_Block::set_flags (ACE_Message_Block::Message_Flags more_flags)
{
  ACE_TRACE ("ACE_Data_Block::set_flags");
  // Later we might mask more_glags so that user can't change internal
  // ones: more_flags &= ~(USER_FLAGS -1).
  return ACE_SET_BITS (this->flags_, more_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Data_Block::clr_flags (ACE_Message_Block::Message_Flags less_flags)
{
  ACE_TRACE ("ACE_Data_Block::clr_flags");
  // Later we might mask more_flags so that user can't change internal
  // ones: less_flags &= ~(USER_FLAGS -1).
  return ACE_CLR_BITS (this->flags_, less_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Data_Block::flags (void) const
{
  ACE_TRACE ("ACE_Data_Block::flags");
   return this->flags_;
}
ACE_INLINE ACE_Allocator*
ACE_Data_Block::data_block_allocator (void) const
{
  ACE_TRACE ("ACE_Data_Block::data_block_allocator");
  return this->data_block_allocator_;
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::set_flags (ACE_Message_Block::Message_Flags more_flags)
{
  ACE_TRACE ("ACE_Message_Block::set_flags");
  return this->data_block ()->set_flags (more_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::clr_flags (ACE_Message_Block::Message_Flags less_flags)
{
  ACE_TRACE ("ACE_Message_Block::clr_flags");
  return this->data_block ()->clr_flags (less_flags);
}
ACE_INLINE ACE_Message_Block::Message_Flags
ACE_Message_Block::flags (void) const
{
  ACE_TRACE ("ACE_Message_Block::flags");
   return this->data_block ()->flags ();
}
// Return the length of the "active" portion of the message.
ACE_INLINE size_t
ACE_Message_Block::length (void) const
{
  ACE_TRACE ("ACE_Message_Block::length");
  return this->wr_ptr_ - this->rd_ptr_;
}
// Sets the length of the "active" portion of the message.  This is
// defined as the offset from RD_PTR to WR_PTR.
ACE_INLINE void
ACE_Message_Block::length (size_t len)
{
  ACE_TRACE ("ACE_Message_Block::length");
  this->wr_ptr_ = this->rd_ptr_ + len;
}
// Return the length of the potential size of the message.
ACE_INLINE size_t
ACE_Message_Block::size (void) const
{
  ACE_TRACE ("ACE_Message_Block::size");
  return this->data_block ()->size ();
}
ACE_INLINE size_t
ACE_Message_Block::capacity (void) const
{
  ACE_TRACE ("ACE_Message_Block::capacity");
  return this->data_block ()->capacity ();
}
ACE_INLINE ACE_Message_Block::ACE_Message_Type
ACE_Data_Block::msg_type (void) const
{
  ACE_TRACE ("ACE_Data_Block::msg_type");
  return this->type_;
}
ACE_INLINE void
ACE_Data_Block::msg_type (ACE_Message_Block::ACE_Message_Type t)
{
  ACE_TRACE ("ACE_Data_Block::msg_type");
  this->type_ = t;
}
ACE_INLINE ACE_Message_Block::ACE_Message_Type
ACE_Message_Block::msg_type (void) const
{
  ACE_TRACE ("ACE_Message_Block::msg_type");
  return this->data_block ()->msg_type ();
}
ACE_INLINE void
ACE_Message_Block::msg_type (ACE_Message_Block::ACE_Message_Type t)
{
  ACE_TRACE ("ACE_Message_Block::msg_type");
  this->data_block ()->msg_type (t);
}
ACE_INLINE ACE_Message_Block::ACE_Message_Type
ACE_Message_Block::msg_class (void) const
{
  ACE_TRACE ("ACE_Message_Block::msg_class");
  if (this->msg_type () < ACE_Message_Block::MB_PRIORITY)
    return ACE_Message_Block::MB_NORMAL;
  else if (this->msg_type () < ACE_Message_Block::MB_USER)
    return ACE_Message_Block::MB_PRIORITY;
  else
    return ACE_Message_Block::MB_USER;
}
ACE_INLINE int
ACE_Message_Block::is_data_msg (void) const
{
  ACE_TRACE ("ACE_Message_Block::is_data_msg");
  ACE_Message_Type mt = this->msg_type ();
  return
    mt == ACE_Message_Block::MB_DATA
    || mt == ACE_Message_Block::MB_PROTO
    || mt == ACE_Message_Block::MB_PCPROTO;
}
ACE_INLINE unsigned long
ACE_Message_Block::msg_priority (void) const
{
  ACE_TRACE ("ACE_Message_Block::msg_priority");
  return this->priority_;
}
ACE_INLINE void
ACE_Message_Block::msg_priority (unsigned long pri)
{
  ACE_TRACE ("ACE_Message_Block::msg_priority");
  this->priority_ = pri;
}
ACE_INLINE const ACE_Time_Value &
ACE_Message_Block::msg_execution_time (void) const
{
  ACE_TRACE ("ACE_Message_Block::msg_execution_time (void)");
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  return this->execution_time_;
#else
  return ACE_Time_Value::zero;
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}
ACE_INLINE void
ACE_Message_Block::msg_execution_time (const ACE_Time_Value &et)
{
  ACE_TRACE ("ACE_Message_Block::msg_execution_time (const ACE_Time_Value & et)");
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  this->execution_time_ = et;
#else
  ACE_UNUSED_ARG (et);
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}
ACE_INLINE const ACE_Time_Value &
ACE_Message_Block::msg_deadline_time (void) const
{
  ACE_TRACE ("ACE_Message_Block::msg_deadline_time (void)");
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  return this->deadline_time_;
#else
  return ACE_Time_Value::max_time; // absolute time of deadline
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}
ACE_INLINE void
ACE_Message_Block::msg_deadline_time (const ACE_Time_Value &dt)
{
  ACE_TRACE ("ACE_Message_Block::msg_deadline_time (const ACE_Time_Value & et)");
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  this->deadline_time_ = dt;
#else
  ACE_UNUSED_ARG (dt);
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}
ACE_INLINE void
ACE_Message_Block::access_allocators (ACE_Allocator *& allocator_strategy,
                                      ACE_Allocator *& data_block_allocator,
                                      ACE_Allocator *& message_block_allocator)
{
  allocator_strategy =
    this->data_block_->allocator_strategy_;
  data_block_allocator =
    this->data_block_->data_block_allocator_;
  message_block_allocator =
    this->message_block_allocator_;
}
ACE_INLINE char *
ACE_Message_Block::base (void) const
{
  ACE_TRACE ("ACE_Message_Block::base");
  return this->data_block ()->base ();
}
ACE_INLINE void
ACE_Message_Block::base (char *msg_data,
                         size_t msg_length,
                         Message_Flags msg_flags)
{
  ACE_TRACE ("ACE_Message_Block::base");
  this->rd_ptr_ = 0;
  this->wr_ptr_ = 0;
  this->data_block ()->base (msg_data, msg_length, msg_flags);
}
ACE_INLINE char *
ACE_Message_Block::rd_ptr (void) const
{
  ACE_TRACE ("ACE_Message_Block::rd_ptr");
  return this->base () + this->rd_ptr_;
}
ACE_INLINE void
ACE_Message_Block::wr_ptr (char *new_ptr)
{
  ACE_TRACE ("ACE_Message_Block::wr_ptr");
  this->wr_ptr_ = new_ptr - this->base ();
}
// Return a pointer to 1 past the end of the data buffer.
ACE_INLINE char *
ACE_Data_Block::mark (void) const
{
  ACE_TRACE ("ACE_Data_Block::mark");
  return this->base_ + this->cur_size_;
}
ACE_INLINE char *
ACE_Message_Block::mark (void) const
{
  ACE_TRACE ("ACE_Message_Block::mark");
  return this->data_block ()->mark ();
}
ACE_INLINE char *
ACE_Data_Block::end (void) const
{
  ACE_TRACE ("ACE_Data_Block::end");
  return this->base_ + this->max_size_;
}
ACE_INLINE char *
ACE_Message_Block::end (void) const
{
  ACE_TRACE ("ACE_Message_Block::end");
  return this->data_block ()->end ();
}

ACE_INLINE void
ACE_Message_Block::rd_ptr (char *new_ptr)
{
  ACE_TRACE ("ACE_Message_Block::rd_ptr");
  this->rd_ptr_ = new_ptr - this->base ();
}
ACE_INLINE void
ACE_Message_Block::rd_ptr (size_t n)
{
  ACE_TRACE ("ACE_Message_Block::rd_ptr");
  this->rd_ptr_ += n;
}
ACE_INLINE char *
ACE_Message_Block::wr_ptr (void) const
{
  ACE_TRACE ("ACE_Message_Block::wr_ptr");
  return this->base () + this->wr_ptr_;
}
ACE_INLINE void
ACE_Message_Block::wr_ptr (size_t n)
{
  ACE_TRACE ("ACE_Message_Block::wr_ptr");
  this->wr_ptr_ += n;
}
ACE_INLINE void
ACE_Message_Block::reset (void)
{
  ACE_TRACE ("ACE_Message_Block::reset");
  this->rd_ptr_ = 0;
  this->wr_ptr_ = 0;
}
ACE_INLINE size_t
ACE_Message_Block::space (void) const
{
  ACE_TRACE ("ACE_Message_Block::space");
  return this->mark () - this->wr_ptr ();
}
ACE_INLINE ACE_Data_Block *
ACE_Message_Block::replace_data_block (ACE_Data_Block *db)
{
  ACE_TRACE ("ACE_Message_Block::replace_data_block");
  ACE_Data_Block *old = this->data_block_;
  this->data_block_ = db;
  if (db != 0)
    {
      // Set the read and write pointers in the <Message_Block> to point
      // to the buffer in the <ACE_Data_Block>.
      this->rd_ptr (this->data_block ()->base ());
      this->wr_ptr (this->data_block ()->base ());
    }
  return old;
}
ACE_INLINE void
ACE_Message_Block::cont (ACE_Message_Block *cont_msg)
{
  ACE_TRACE ("ACE_Message_Block::cont");
  this->cont_ = cont_msg;
}
ACE_INLINE ACE_Message_Block *
ACE_Message_Block::cont (void) const
{
  ACE_TRACE ("ACE_Message_Block::cont");
  return this->cont_;
}
ACE_INLINE void
ACE_Message_Block::reset_allocators (ACE_Allocator *allocator_strategy,
                                     ACE_Allocator *data_block_allocator,
                                     ACE_Allocator *message_block_allocator)
{
  this->data_block_->allocator_strategy_ =
    allocator_strategy;
  this->data_block_->data_block_allocator_ =
    data_block_allocator;
  this->message_block_allocator_ =
    message_block_allocator;
  if (this->cont () != 0)
    this->cont ()->reset_allocators (allocator_strategy,
                                     data_block_allocator,
                                     message_block_allocator);
}
ACE_INLINE void
ACE_Message_Block::next (ACE_Message_Block *next_msg)
{
  ACE_TRACE ("ACE_Message_Block::next");
  this->next_ = next_msg;
}
ACE_INLINE ACE_Message_Block *
ACE_Message_Block::next (void) const
{
  ACE_TRACE ("ACE_Message_Block::next");
  return this->next_;
}
ACE_INLINE void
ACE_Message_Block::prev (ACE_Message_Block *next_msg)
{
  ACE_TRACE ("ACE_Message_Block::prev");
  this->prev_ = next_msg;
}
ACE_INLINE ACE_Message_Block *
ACE_Message_Block::prev (void) const
{
  ACE_TRACE ("ACE_Message_Block::prev");
  return this->prev_;
}
ACE_INLINE ACE_Allocator *
ACE_Data_Block::allocator_strategy (void) const
{
  ACE_TRACE ("ACE_Data_Block::allocator_strategy");
  return this->allocator_strategy_;
}
ACE_INLINE ACE_Lock *
ACE_Data_Block::locking_strategy (void)
{
  ACE_TRACE ("ACE_Data_Block::locking_strategy");
  return this->locking_strategy_;
}
ACE_INLINE ACE_Lock *
ACE_Data_Block::locking_strategy (ACE_Lock *nls)
{
  ACE_TRACE ("ACE_Data_Block::locking_strategy");
  ACE_Lock *ols = this->locking_strategy_;
  this->locking_strategy_ = nls;
  return ols;
}
ACE_INLINE ACE_Lock *
ACE_Message_Block::locking_strategy (void)
{
  ACE_TRACE ("ACE_Message_Block::locking_strategy");
  return this->data_block ()->locking_strategy ();
}
ACE_INLINE ACE_Lock *
ACE_Message_Block::locking_strategy (ACE_Lock *nls)
{
  ACE_TRACE ("ACE_Message_Block::locking_strategy");
  ACE_Lock *ols = this->data_block ()->locking_strategy ();
  this->data_block ()->locking_strategy (nls);
  return ols;
}
ACE_END_VERSIONED_NAMESPACE_DECL
