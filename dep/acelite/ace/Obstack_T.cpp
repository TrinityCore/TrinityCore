// $Id: Obstack_T.cpp 88793 2010-02-01 17:50:34Z cleeland $

#ifndef ACE_OBSTACK_T_CPP
#define ACE_OBSTACK_T_CPP

#include "ace/Obstack_T.h"
#include "ace/Malloc_Base.h"
#include "ace/OS_NS_string.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Obstack_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Obstack_T)

template <class ACE_CHAR_T> void
ACE_Obstack_T<ACE_CHAR_T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("size_ = %d\n"), this->size_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("head_ = %x\n"), this->head_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("curr_ = %x\n"), this->curr_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class ACE_CHAR_T> int
ACE_Obstack_T<ACE_CHAR_T>::request (size_t len)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::request");

  // normalize the length.
  len *= sizeof (ACE_CHAR_T);

  // Check to see if there's room for the requested length, including
  // any part of an existing string, if any.
  size_t resulting_len = (this->curr_->cur_ - this->curr_->block_) + len;

  // Increase the length of the underlying chunks if the request made is
  // for bigger sized chunks.
  if (this->size_ < resulting_len)
    this->size_ = this->size_ << 1;

  // We now know the request will fit; see if it can fit in the current
  // chunk or will need a new one.
  if (this->curr_->cur_ + len >= this->curr_->end_)
    {
      // Need a new chunk. Save the current one so the current string can be
      // copied to the new chunk.
      ACE_Obchunk *temp = this->curr_;
      if (this->curr_->next_ == 0)
        {
          // We must allocate new memory.
          ACE_Obchunk* tmp = this->new_chunk();
          if (!tmp)
            return -1;
          this->curr_->next_ = tmp;
          this->curr_ = this->curr_->next_;
        }
      else
        {
          // We can reuse previously allocated memory.
          this->curr_ = this->curr_->next_;
          this->curr_->block_ = this->curr_->cur_ = this->curr_->contents_;
        }

      // Copy any initial characters to the new chunk.
      if (temp->cur_ != temp->block_)
        {
          size_t datasize = temp->cur_ - temp->block_;
          ACE_OS::memcpy (this->curr_->block_,
                          temp->block_,
                          datasize);
          this->curr_->cur_ = this->curr_->block_ + datasize;
          // Reset the old chunk.
          temp->cur_ = temp->block_;
        }
    }

  return 0;
}

template <class ACE_CHAR_T> ACE_CHAR_T *
ACE_Obstack_T<ACE_CHAR_T>::grow (ACE_CHAR_T c)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::grow");

  if (this->request (1) == 0)
    {
      ACE_CHAR_T *retv = reinterpret_cast<ACE_CHAR_T *> (this->curr_->cur_);
      this->curr_->cur_ += sizeof (ACE_CHAR_T);
      *retv = c;
      return retv;
    }
  else
    return 0;
}

template <class ACE_CHAR_T> ACE_Obchunk *
ACE_Obstack_T<ACE_CHAR_T>::new_chunk (void)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::new_chunk");

  ACE_Obchunk *temp = 0;

  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<ACE_Obchunk *> (this->allocator_strategy_->malloc
                             (sizeof (class ACE_Obchunk) + this->size_)),
                         ACE_Obchunk (this->size_),
                         0);
  return temp;
}

template <class ACE_CHAR_T>
ACE_Obstack_T<ACE_CHAR_T>::ACE_Obstack_T (size_t size,
                                    ACE_Allocator *allocator_strategy)
  : allocator_strategy_ (allocator_strategy),
    size_ (size),
    head_ (0),
    curr_ (0)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::ACE_Obstack");

  if (this->allocator_strategy_ == 0)
    ACE_ALLOCATOR (this->allocator_strategy_,
                   ACE_Allocator::instance ());

  this->head_ = this->new_chunk ();
  this->curr_ = this->head_;
}

template <class ACE_CHAR_T>
ACE_Obstack_T<ACE_CHAR_T>::~ACE_Obstack_T (void)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::~ACE_Obstack_T");

  ACE_Obchunk *temp = this->head_;

  while (temp != 0)
    {
      ACE_Obchunk *next = temp->next_;
      temp->next_  = 0;
      this->allocator_strategy_->free (temp);
      temp = next;
    }
}

template <class ACE_CHAR_T> ACE_CHAR_T *
ACE_Obstack_T<ACE_CHAR_T>::copy (const ACE_CHAR_T *s,
                           size_t len)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::copy");

  if (this->request (len) != 0)
    return 0;

  size_t tsize = len * sizeof (ACE_CHAR_T);
  ACE_OS::memcpy (this->curr_->cur_, s, tsize);
  this->curr_->cur_ += tsize ;
  return this->freeze ();
}

template <class ACE_CHAR_T> void
ACE_Obstack_T<ACE_CHAR_T>::unwind (void* obj)
{
  if (obj >= this->curr_->contents_ && obj < this->curr_->end_)
    this->curr_->block_ = this->curr_->cur_ = reinterpret_cast<char*> (obj);
  else
    this->unwind_i (obj);
}

template <class ACE_CHAR_T> void
ACE_Obstack_T<ACE_CHAR_T>::unwind_i (void* obj)
{
  ACE_Obchunk* curr = this->head_;
  while (curr != 0 && (curr->contents_ > obj || curr->end_ < obj))
      curr = curr->next_;
  if (curr)
    {
      this->curr_ = curr;
      this->curr_->block_ = this->curr_->cur_ = reinterpret_cast<char*> (obj);
    }
  else if (obj != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("Deletion of non-existent object.\n%a")));
}

template <class ACE_CHAR_T> void
ACE_Obstack_T<ACE_CHAR_T>::release (void)
{
  ACE_TRACE ("ACE_Obstack_T<ACE_CHAR_T>::release");

  this->curr_ = this->head_;
  this->curr_->block_ = this->curr_->cur_ = this->curr_->contents_;
}

template <class ACE_CHAR_T> void
ACE_Obstack_T<ACE_CHAR_T>::grow_fast (ACE_CHAR_T c)
{
  * (reinterpret_cast<ACE_CHAR_T *> (this->curr_->cur_)) = c;
  this->curr_->cur_ += sizeof (ACE_CHAR_T);
}

template <class ACE_CHAR_T> ACE_CHAR_T *
ACE_Obstack_T<ACE_CHAR_T>::freeze (void)
{
  ACE_CHAR_T *retv = reinterpret_cast<ACE_CHAR_T *> (this->curr_->block_);
  * (reinterpret_cast<ACE_CHAR_T *> (this->curr_->cur_)) = 0;

  this->curr_->cur_ += sizeof (ACE_CHAR_T);
  this->curr_->block_ = this->curr_->cur_;
  return retv;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_OBSTACK_T_CPP */
