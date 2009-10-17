// -*- C++ -*-
//
// $Id: MEM_SAP.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/RW_Thread_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_MEM_SAP_Node::ACE_MEM_SAP_Node (size_t cap)
  : capacity_ (cap),
    size_ (0),
    next_ (0)
{
}

ACE_INLINE size_t
ACE_MEM_SAP_Node::size (void) const
{
  return this->size_;
}

ACE_INLINE size_t
ACE_MEM_SAP_Node::capacity (void) const
{
  return this->capacity_;
}

ACE_INLINE void *
ACE_MEM_SAP_Node::data (void)
{
  return  this + 1;
}


ACE_INLINE ACE_MEM_SAP_Node *
ACE_MEM_SAP::acquire_buffer (const ssize_t size)
{
  ACE_TRACE ("ACE_MEM_SAP::acquire_buffer");
  if (this->shm_malloc_ == 0)
    return 0;                  // not initialized.

  ACE_MEM_SAP_Node *buf = 0;

  ACE_NEW_MALLOC_RETURN (buf,
                         static_cast<ACE_MEM_SAP_Node *>
                           (this->shm_malloc_->malloc (sizeof (ACE_MEM_SAP_Node) + size)),
                         ACE_MEM_SAP_Node (size),
                         0);
  return buf;
}

ACE_INLINE int
ACE_MEM_SAP::release_buffer (ACE_MEM_SAP_Node *buf)
{
  ACE_TRACE ("ACE_MEM_SAP::release_buffer");
  if (this->shm_malloc_ == 0)
    return -1;                  // not initialized.

  this->shm_malloc_->free (buf);
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
