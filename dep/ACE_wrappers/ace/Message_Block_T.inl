// -*- C++ -*-
//
// $Id: Message_Block_T.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template<class ACE_LOCK> ACE_INLINE
ACE_Locked_Data_Block<ACE_LOCK>::ACE_Locked_Data_Block (void)
{
  this->locking_strategy_ = &this->lock_;
}
template<class ACE_LOCK> ACE_INLINE
ACE_Locked_Data_Block<ACE_LOCK>::
ACE_Locked_Data_Block (size_t size,
                       ACE_Message_Block::ACE_Message_Type msg_type,
                       const char *msg_data,
                       ACE_Allocator *allocator_strategy,
                       ACE_Message_Block::Message_Flags flags,
                       ACE_Allocator *data_block_allocator)
  : ACE_Data_Block (size,
                    msg_type,
                    msg_data,
                    allocator_strategy,
                    &lock_,
                    flags,
                    data_block_allocator)
{
}
ACE_END_VERSIONED_NAMESPACE_DECL
