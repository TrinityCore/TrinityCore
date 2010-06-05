// $Id: Message_Block_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_MESSAGE_BLOCK_T_CPP
#define ACE_MESSAGE_BLOCK_T_CPP

#include "ace/Malloc_Base.h"     /* Need ACE_Allocator */

#if !defined (__ACE_INLINE__)
#include "ace/Message_Block_T.inl"
#endif /* __ACE_INLINE__ */

#include "ace/os_include/os_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class L>
ACE_Locked_Data_Block<L>::~ACE_Locked_Data_Block (void)
{
}

template<class ACE_LOCK> ACE_Data_Block *
ACE_Locked_Data_Block<ACE_LOCK>::clone_nocopy (ACE_Message_Block::Message_Flags mask,
                                               size_t max_size) const
{
  ACE_TRACE ("ACE_Locked_Data_Block::clone_nocopy");

  // You always want to clear this one to prevent memory leaks but you
  // might add some others later.
  const ACE_Message_Block::Message_Flags always_clear =
    ACE_Message_Block::DONT_DELETE;

  ACE_Locked_Data_Block<ACE_LOCK> *nb = 0;

  ACE_NEW_MALLOC_RETURN (nb,
                         static_cast<ACE_Locked_Data_Block<ACE_LOCK>*> (
                                         this->data_block_allocator ()->malloc (sizeof (ACE_Locked_Data_Block<ACE_LOCK>))),
                         ACE_Locked_Data_Block<ACE_LOCK> (
                                                   max_size == 0 ?
                                                     this->size () : max_size,
                                                   this->msg_type (),
                                                   0,
                                                   this->allocator_strategy (),
                                                   this->flags (),
                                                   this->data_block_allocator ()),
                         0);

  // Set new flags minus the mask...
  nb->clr_flags (mask | always_clear);
  return nb;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_MESSAGE_BLOCK_T_CPP */

