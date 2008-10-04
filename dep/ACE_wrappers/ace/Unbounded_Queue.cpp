// $Id: Unbounded_Queue.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_UNBOUNDED_QUEUE_CPP
#define ACE_UNBOUNDED_QUEUE_CPP

#include "ace/Unbounded_Queue.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Unbounded_Queue.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Malloc_Base.h"
#include "ace/Log_Msg.h"
#include "ace/os_include/os_errno.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Unbounded_Queue)

template <class T>
ACE_Unbounded_Queue<T>::ACE_Unbounded_Queue (ACE_Allocator *alloc)
  : head_ (0),
    cur_size_ (0),
    allocator_ (alloc)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::ACE_Unbounded_Queue (void)");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (ACE_Node<T> *) this->allocator_->malloc (sizeof (ACE_Node<T>)),
                  ACE_Node<T>);
  // Make the list circular by pointing it back to itself.
  this->head_->next_ = this->head_;
}

template <class T>
ACE_Unbounded_Queue<T>::ACE_Unbounded_Queue (const ACE_Unbounded_Queue<T> &us)
  : head_ (0),
    cur_size_ (0),
    allocator_ (us.allocator_)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::ACE_Unbounded_Queue");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (ACE_Node<T> *) this->allocator_->malloc (sizeof (ACE_Node<T>)),
                  ACE_Node<T>);
  this->head_->next_ = this->head_;
  this->copy_nodes (us);
}

template <class T> void
ACE_Unbounded_Queue<T>::operator= (const ACE_Unbounded_Queue<T> &us)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::operator=");

  if (this != &us)
    {
      this->delete_nodes ();
      this->copy_nodes (us);
    }
}

template <class T> ACE_Unbounded_Queue_Iterator<T>
ACE_Unbounded_Queue<T>::begin (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue<T>::begin");
  return ACE_Unbounded_Queue_Iterator<T> (*this);
}

template <class T> ACE_Unbounded_Queue_Iterator<T>
ACE_Unbounded_Queue<T>::end (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue<T>::end");
  return ACE_Unbounded_Queue_Iterator<T> (*this, 1);
}

template <class T> void
ACE_Unbounded_Queue<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_ = %u"), this->head_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_->next_ = %u"), this->head_->next_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncur_size_ = %d\n"), this->cur_size_));

  T *item = 0;
#if !defined (ACE_NLOGGING)
  size_t count = 1;
#endif /* ! ACE_NLOGGING */

  for (ACE_Unbounded_Queue_Iterator<T> iter (*(ACE_Unbounded_Queue<T> *) this);
       iter.next (item) != 0;
       iter.advance ())
    ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("count = %d\n"), count++));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class T> void
ACE_Unbounded_Queue<T>::copy_nodes (const ACE_Unbounded_Queue<T> &us)
{
  for (ACE_Node<T> *curr = us.head_->next_;
       curr != us.head_;
       curr = curr->next_)
    if (this->enqueue_tail (curr->item_) == -1)
      // @@ What's the right thing to do here?
      this->delete_nodes ();
}

template <class T> void
ACE_Unbounded_Queue<T>::delete_nodes (void)
{
  for (ACE_Node<T> *curr = this->head_->next_;
       // Keep looking until we've hit the dummy node.
       curr != this->head_;
       )
    {
      ACE_Node<T> *temp = curr;
      curr = curr->next_;

      ACE_DES_FREE_TEMPLATE (temp,
                             this->allocator_->free,
                             ACE_Node,
                             <T>);
      --this->cur_size_;
      // @@ Doesnt make sense to have this check since
      // this will always be true.
      //   ACE_ASSERT (this->cur_size_ >= 0);
    }

  // Reset the list to be a circular list with just a dummy node.
  this->head_->next_ = this->head_;
}

template <class T>
ACE_Unbounded_Queue<T>::~ACE_Unbounded_Queue (void)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::~ACE_Unbounded_Queue (void)");

  this->delete_nodes ();
  ACE_DES_FREE_TEMPLATE (head_,
                         this->allocator_->free,
                         ACE_Node,
                         <T>);
  this->head_ = 0;
}

template <class T> int
ACE_Unbounded_Queue<T>::enqueue_head (const T &new_item)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::enqueue_head");

  ACE_Node<T> *temp = 0;

  // Create a new node that points to the original head.
  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<ACE_Node<T> *> (this->allocator_->malloc (sizeof (ACE_Node<T>))),
                         ACE_Node<T> (new_item, this->head_->next_),
                         -1);
  // Link this pointer into the front of the list.  Note that the
  // "real" head of the queue is <head_->next_>, whereas <head_> is
  // just a pointer to the dummy node.
  this->head_->next_ = temp;

  ++this->cur_size_;
  return 0;
}

template <class T> int
ACE_Unbounded_Queue<T>::enqueue_tail (const T &new_item)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::enqueue_tail");

  // Insert <item> into the old dummy node location.  Note that this
  // isn't actually the "head" item in the queue, it's a dummy node at
  // the "tail" of the queue...
  this->head_->item_ = new_item;

  ACE_Node<T> *temp = 0;

  // Create a new dummy node.
  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<ACE_Node<T> *> (this->allocator_->malloc (sizeof (ACE_Node<T>))),
                         ACE_Node<T> (this->head_->next_),
                         -1);
  // Link this dummy pointer into the list.
  this->head_->next_ = temp;

  // Point the head to the new dummy node.
  this->head_ = temp;

  ++this->cur_size_;
  return 0;
}

template <class T> int
ACE_Unbounded_Queue<T>::dequeue_head (T &item)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::dequeue_head");

  // Check for empty queue.
  if (this->is_empty ())
    return -1;

  ACE_Node<T> *temp = this->head_->next_;

  item = temp->item_;
  this->head_->next_ = temp->next_;
  ACE_DES_FREE_TEMPLATE (temp,
                         this->allocator_->free,
                         ACE_Node,
                         <T>);
  --this->cur_size_;
  return 0;
}

template <class T> void
ACE_Unbounded_Queue<T>::reset (void)
{
  ACE_TRACE ("reset");

  this->delete_nodes ();
}

template <class T> int
ACE_Unbounded_Queue<T>::get (T *&item, size_t slot) const
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::get");

  ACE_Node<T> *curr = this->head_->next_;

  size_t i;

  for (i = 0; i < this->cur_size_; i++)
    {
      if (i == slot)
        break;

      curr = curr->next_;
    }

  if (i < this->cur_size_)
    {
      item = &curr->item_;
      return 0;
    }
  else
    return -1;
}

template <class T> int
ACE_Unbounded_Queue<T>::set (const T &item,
                             size_t slot)
{
  //   ACE_TRACE ("ACE_Unbounded_Queue<T>::set");

  ACE_Node<T> *curr = this->head_->next_;

  size_t i;

  for (i = 0;
       i < slot && i < this->cur_size_;
       ++i)
    curr = curr->next_;

  if (i < this->cur_size_)
    {
      // We're in range, so everything's cool.
      curr->item_ = item;
      return 0;
    }
  else
    {
      // We need to expand the list.

      // A common case will be increasing the set size by 1.
      // Therefore, we'll optimize for this case.
      if (i == slot)
        {
          // Try to expand the size of the set by 1.
          if (this->enqueue_tail (item) == -1)
            return -1;
          else
            return 0;
        }
      else
        {
          T const dummy = T ();

          // We need to expand the list by multiple (dummy) items.
          for (; i < slot; ++i)
            {
              // This head points to the existing dummy node, which is
              // about to be overwritten when we add the new dummy
              // node.
              curr = this->head_;

              // Try to expand the size of the set by 1, but don't
              // store anything in the dummy node (yet).
              if (this->enqueue_tail (dummy) == -1)
                return -1;
            }

          curr->item_ = item;
          return 0;
        }
    }
}

// ****************************************************************

template <class T> void
ACE_Unbounded_Queue_Const_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Unbounded_Queue_Const_Iterator<T>::ACE_Unbounded_Queue_Const_Iterator (const ACE_Unbounded_Queue<T> &q, int end)
  : current_ (end == 0 ? q.head_->next_ : q.head_ ),
    queue_ (q)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::ACE_Unbounded_Queue_Const_Iterator");
}

template <class T> int
ACE_Unbounded_Queue_Const_Iterator<T>::advance (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::advance");
  this->current_ = this->current_->next_;
  return this->current_ != this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Const_Iterator<T>::first (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::first");
  this->current_ = this->queue_.head_->next_;
  return this->current_ != this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Const_Iterator<T>::done (void) const
{
  ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::done");

  return this->current_ == this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Const_Iterator<T>::next (T *&item)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Const_Iterator<T>::next");
  if (this->current_ == this->queue_.head_)
    return 0;
  else
    {
      item = &this->current_->item_;
      return 1;
    }
}

// ****************************************************************

template <class T> void
ACE_Unbounded_Queue_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Unbounded_Queue_Iterator<T>::ACE_Unbounded_Queue_Iterator (ACE_Unbounded_Queue<T> &q, int end)
  : current_ (end == 0 ? q.head_->next_ : q.head_ ),
    queue_ (q)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::ACE_Unbounded_Queue_Iterator");
}

template <class T> int
ACE_Unbounded_Queue_Iterator<T>::advance (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::advance");
  this->current_ = this->current_->next_;
  return this->current_ != this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Iterator<T>::first (void)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::first");
  this->current_ = this->queue_.head_->next_;
  return this->current_ != this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Iterator<T>::done (void) const
{
  ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::done");

  return this->current_ == this->queue_.head_;
}

template <class T> int
ACE_Unbounded_Queue_Iterator<T>::next (T *&item)
{
  // ACE_TRACE ("ACE_Unbounded_Queue_Iterator<T>::next");
  if (this->current_ == this->queue_.head_)
    return 0;
  else
    {
      item = &this->current_->item_;
      return 1;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_UNBOUNDED_QUEUE_CPP */
