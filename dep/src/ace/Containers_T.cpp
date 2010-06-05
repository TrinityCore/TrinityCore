// $Id: Containers_T.cpp 82588 2008-08-11 13:37:41Z johnnyw $

#ifndef ACE_CONTAINERS_T_CPP
#define ACE_CONTAINERS_T_CPP

#include "ace/Log_Msg.h"
#include "ace/Malloc_Base.h"
#include "ace/OS_Memory.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Containers.h"

#if !defined (__ACE_INLINE__)
#include "ace/Containers_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Bounded_Stack)

template <class T> void
ACE_Bounded_Stack<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Bounded_Stack<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template<class T>
ACE_Bounded_Stack<T>::ACE_Bounded_Stack (size_t size)
  : size_ (size),
    top_ (0)
{
  ACE_NEW (this->stack_,
           T[size]);
  ACE_TRACE ("ACE_Bounded_Stack<T>::ACE_Bounded_Stack");
}

template<class T>
ACE_Bounded_Stack<T>::ACE_Bounded_Stack (const ACE_Bounded_Stack<T> &s)
  : size_ (s.size_),
    top_ (s.top_)
{
  ACE_NEW (this->stack_,
           T[s.size_]);

  ACE_TRACE ("ACE_Bounded_Stack<T>::ACE_Bounded_Stack");

  for (size_t i = 0; i < this->top_; i++)
    this->stack_[i] = s.stack_[i];
}

template<class T> void
ACE_Bounded_Stack<T>::operator= (const ACE_Bounded_Stack<T> &s)
{
  ACE_TRACE ("ACE_Bounded_Stack<T>::operator=");

  if (&s != this)
    {
      if (this->size_ < s.size_)
        {
          delete [] this->stack_;
          ACE_NEW (this->stack_,
                   T[s.size_]);
          this->size_ = s.size_;
        }
      this->top_ = s.top_;

      for (size_t i = 0; i < this->top_; i++)
        this->stack_[i] = s.stack_[i];
    }
}

template<class T>
ACE_Bounded_Stack<T>::~ACE_Bounded_Stack (void)
{
  ACE_TRACE ("ACE_Bounded_Stack<T>::~ACE_Bounded_Stack");
  delete [] this->stack_;
}

// ----------------------------------------

ACE_ALLOC_HOOK_DEFINE(ACE_Fixed_Stack)

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Stack<T, ACE_SIZE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Fixed_Stack<T, ACE_SIZE>::dump");
#endif /* ACE_HAS_DUMP */
}

template<class T, size_t ACE_SIZE>
ACE_Fixed_Stack<T, ACE_SIZE>::ACE_Fixed_Stack (void)
  : size_ (ACE_SIZE),
    top_ (0)
{
  ACE_TRACE ("ACE_Fixed_Stack<T, ACE_SIZE>::ACE_Fixed_Stack");
}

template<class T, size_t ACE_SIZE>
ACE_Fixed_Stack<T, ACE_SIZE>::ACE_Fixed_Stack (const ACE_Fixed_Stack<T, ACE_SIZE> &s)
  : size_ (s.size_),
    top_ (s.top_)
{
  ACE_TRACE ("ACE_Fixed_Stack<T, ACE_SIZE>::ACE_Fixed_Stack");
  for (size_t i = 0; i < this->top_; i++)
    this->stack_[i] = s.stack_[i];
}

template<class T, size_t ACE_SIZE> void
ACE_Fixed_Stack<T, ACE_SIZE>::operator= (const ACE_Fixed_Stack<T, ACE_SIZE> &s)
{
  ACE_TRACE ("ACE_Fixed_Stack<T, ACE_SIZE>::operator=");

  if (&s != this)
    {
      this->top_ = s.top_;

      for (size_t i = 0; i < this->top_; i++)
        this->stack_[i] = s.stack_[i];
    }
}

template<class T, size_t ACE_SIZE>
ACE_Fixed_Stack<T, ACE_SIZE>::~ACE_Fixed_Stack (void)
{
  ACE_TRACE ("ACE_Fixed_Stack<T, ACE_SIZE>::~ACE_Fixed_Stack");
}

//----------------------------------------

ACE_ALLOC_HOOK_DEFINE(ACE_Unbounded_Stack)

template <class T> void
ACE_Unbounded_Stack<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template<class T>
ACE_Unbounded_Stack<T>::ACE_Unbounded_Stack (ACE_Allocator *alloc)
  : head_ (0),
    cur_size_ (0),
    allocator_ (alloc)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::ACE_Unbounded_Stack");
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (ACE_Node<T> *) this->allocator_->malloc (sizeof (ACE_Node<T>)),
                  ACE_Node<T>);
  this->head_->next_ = this->head_;
}

template<class T> void
ACE_Unbounded_Stack<T>::delete_all_nodes (void)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::delete_all_nodes");

  while (this->is_empty () == 0)
    {
      ACE_Node<T> *temp = this->head_->next_;
      this->head_->next_ = temp->next_;
      ACE_DES_FREE_TEMPLATE (temp, this->allocator_->free,
                             ACE_Node, <T>);
    }

  this->cur_size_ = 0;

  ACE_ASSERT (this->head_ == this->head_->next_
              && this->is_empty ());
}

template<class T> void
ACE_Unbounded_Stack<T>::copy_all_nodes (const ACE_Unbounded_Stack<T> &s)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::copy_all_nodes");

  ACE_ASSERT (this->head_ == this->head_->next_);

  ACE_Node<T> *temp = this->head_;

  for (ACE_Node<T> *s_temp = s.head_->next_;
       s_temp != s.head_;
       s_temp = s_temp->next_)
    {
      ACE_Node<T> *nptr = temp->next_;
      ACE_NEW_MALLOC (temp->next_,
                      (ACE_Node<T> *) this->allocator_->malloc (sizeof (ACE_Node<T>)),
                      ACE_Node<T> (s_temp->item_, nptr));
      temp = temp->next_;
    }
  this->cur_size_ = s.cur_size_;
}

template<class T>
ACE_Unbounded_Stack<T>::ACE_Unbounded_Stack (const ACE_Unbounded_Stack<T> &s)
  : head_ (0),
    cur_size_ (0),
    allocator_ (s.allocator_)
{
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (ACE_Node<T> *) this->allocator_->malloc (sizeof (ACE_Node<T>)),
                  ACE_Node<T>);
  this->head_->next_ = this->head_;

  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::ACE_Unbounded_Stack");
  this->copy_all_nodes (s);
}

template<class T> void
ACE_Unbounded_Stack<T>::operator= (const ACE_Unbounded_Stack<T> &s)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::operator=");

  if (this != &s)
    {
      this->delete_all_nodes ();
      this->copy_all_nodes (s);
    }
}

template<class T>
ACE_Unbounded_Stack<T>::~ACE_Unbounded_Stack (void)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::~ACE_Unbounded_Stack");

  this->delete_all_nodes ();
  ACE_DES_FREE_TEMPLATE (head_,
                         this->allocator_->free,
                         ACE_Node,
                         <T>);
}

template<class T> int
ACE_Unbounded_Stack<T>::push (const T &new_item)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::push");

  ACE_Node<T> *temp = 0;

  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<ACE_Node<T> *> (this->allocator_->malloc (sizeof (ACE_Node<T>))),
                         ACE_Node<T> (new_item, this->head_->next_),
                         -1);
  this->head_->next_ = temp;
  ++this->cur_size_;
  return 0;
}

template<class T> int
ACE_Unbounded_Stack<T>::pop (T &item)
{
  //  ACE_TRACE ("ACE_Unbounded_Stack<T>::pop");

  if (this->is_empty ())
    return -1;
  else
    {
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
}

template <class T> int
ACE_Unbounded_Stack<T>::find (const T &item) const
{
  // ACE_TRACE ("ACE_Unbounded_Stack<T>::find");
  // Set <item> into the dummy node.
  this->head_->item_ = item;

  ACE_Node<T> *temp = this->head_->next_;

  // Keep looping until we find the item.
  while (!(temp->item_ == item))
    temp = temp->next_;

  // If we found the dummy node then it's not really there, otherwise,
  // it is there.
  return temp == this->head_ ? -1 : 0;
}

template <class T> int
ACE_Unbounded_Stack<T>::insert (const T &item)
{
  // ACE_TRACE ("ACE_Unbounded_Stack<T>::insert");

  if (this->find (item) == 0)
    return 1;
  else
    return this->push (item);
}

template <class T> int
ACE_Unbounded_Stack<T>::remove (const T &item)
{
  // ACE_TRACE ("ACE_Unbounded_Stack<T>::remove");

  // Insert the item to be founded into the dummy node.
  this->head_->item_ = item;

  ACE_Node<T> *curr = this->head_;

  while (!(curr->next_->item_ == item))
    curr = curr->next_;

  if (curr->next_ == this->head_)
    return -1; // Item was not found.
  else
    {
      ACE_Node<T> *temp = curr->next_;
      // Skip over the node that we're deleting.
      curr->next_ = temp->next_;
      --this->cur_size_;
      ACE_DES_FREE_TEMPLATE (temp,
                             this->allocator_->free,
                             ACE_Node,
                             <T>);
      return 0;
    }
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Double_Linked_List_Iterator_Base)

template <class T>
ACE_Double_Linked_List_Iterator_Base<T>::ACE_Double_Linked_List_Iterator_Base (const ACE_Double_Linked_List<T> &dll)
  : current_ (0), dllist_ (&dll)
{
  // Do nothing
}

template <class T>
ACE_Double_Linked_List_Iterator_Base<T>::ACE_Double_Linked_List_Iterator_Base (const ACE_Double_Linked_List_Iterator_Base<T> &iter)
  : current_ (iter.current_),
    dllist_ (iter.dllist_)
{
  // Do nothing
}


template <class T> T *
ACE_Double_Linked_List_Iterator_Base<T>::next (void) const
{
  return this->not_done ();
}

template <class T> int
ACE_Double_Linked_List_Iterator_Base<T>::next (T *&ptr) const
{
  ptr = this->not_done ();
  return ptr ? 1 : 0;
}


template <class T> int
ACE_Double_Linked_List_Iterator_Base<T>::done (void) const
{
  return this->not_done () ? 0 : 1;
}

template <class T> T &
ACE_Double_Linked_List_Iterator_Base<T>::operator* (void) const
{
  return *(this->not_done ());
}

// @@ Is this a valid retasking? Make sure to check with Purify and
// whatnot that we're not leaking memory or doing any other screwing things.
template <class T> void
ACE_Double_Linked_List_Iterator_Base<T>::reset (ACE_Double_Linked_List<T> &dll)
{
  current_ = 0;
  dllist_ = &dll;
}

 template <class T> int
ACE_Double_Linked_List_Iterator_Base<T>::go_head (void)
{
  this->current_ = static_cast<T*> (dllist_->head_->next_);
  return this->current_ ? 1 : 0;
}

template <class T> int
ACE_Double_Linked_List_Iterator_Base<T>::go_tail (void)
{
  this->current_ = static_cast<T*> (dllist_->head_->prev_);
  return this->current_ ? 1 : 0;
}

template <class T> T *
ACE_Double_Linked_List_Iterator_Base<T>::not_done (void) const
{
  if (this->current_ != this->dllist_->head_)
    return this->current_;
  else
    return 0;
}

template <class T> T *
ACE_Double_Linked_List_Iterator_Base<T>::do_advance (void)
{
  if (this->not_done ())
    {
      this->current_ = static_cast<T*> (this->current_->next_);
      return this->not_done ();
    }
  else
    return 0;
}

template <class T> T *
ACE_Double_Linked_List_Iterator_Base<T>::do_retreat (void)
{
  if (this->not_done ())
    {
      this->current_ = static_cast<T*> (this->current_->prev_);
      return this->not_done ();
    }
  else
    return 0;
}

template <class T> void
ACE_Double_Linked_List_Iterator_Base<T>::dump_i (void) const
{
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("current_ = %x"), this->current_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Double_Linked_List_Iterator)

template <class T>
ACE_Double_Linked_List_Iterator<T>::ACE_Double_Linked_List_Iterator (const ACE_Double_Linked_List<T> &dll)
  : ACE_Double_Linked_List_Iterator_Base <T> (dll)
{
  this->current_ = static_cast<T*> (dll.head_->next_);
  // Advance current_ out of the null area and onto the first item in
  // the list
}

template <class T> void
ACE_Double_Linked_List_Iterator<T>::reset (ACE_Double_Linked_List<T> &dll)
{
  this->ACE_Double_Linked_List_Iterator_Base <T>::reset (dll);
  this->current_ = static_cast<T*> (dll.head_->next_);
  // Advance current_ out of the null area and onto the first item in
  // the list
}

template <class T> int
ACE_Double_Linked_List_Iterator<T>::first (void)
{
  return this->go_head ();
}

template <class T> int
ACE_Double_Linked_List_Iterator<T>::advance (void)
{
  return this->do_advance () ? 1 : 0;
}

template <class T> T*
ACE_Double_Linked_List_Iterator<T>::advance_and_remove (bool dont_remove)
{
  T* item = 0;
  if (dont_remove)
    this->do_advance ();
  else
    {
      item = this->next ();
      this->do_advance ();
      // It seems dangerous to remove nodes in an iterator, but so it goes...
      ACE_Double_Linked_List<T> *dllist =
        const_cast<ACE_Double_Linked_List<T> *> (this->dllist_);
      dllist->remove (item);
    }
  return item;
}

template <class T> void
ACE_Double_Linked_List_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

// Prefix advance.

template <class T>
ACE_Double_Linked_List_Iterator<T> &
ACE_Double_Linked_List_Iterator<T>::operator++ (void)
{
  this->do_advance ();
  return *this;
}


// Postfix advance.

template <class T>
ACE_Double_Linked_List_Iterator<T>
ACE_Double_Linked_List_Iterator<T>::operator++ (int)
{
  ACE_Double_Linked_List_Iterator<T> retv (*this);
  this->do_advance ();
  return retv;
}


// Prefix reverse.

template <class T>
ACE_Double_Linked_List_Iterator<T> &
ACE_Double_Linked_List_Iterator<T>::operator-- (void)
{
  this->do_retreat ();
  return *this;
}


// Postfix reverse.

template <class T>
ACE_Double_Linked_List_Iterator<T>
ACE_Double_Linked_List_Iterator<T>::operator-- (int)
{
  ACE_Double_Linked_List_Iterator<T> retv (*this);
  this->do_retreat ();
  return retv;
}


//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Double_Linked_List_Reverse_Iterator)

  template <class T>
ACE_Double_Linked_List_Reverse_Iterator<T>::ACE_Double_Linked_List_Reverse_Iterator (ACE_Double_Linked_List<T> &dll)
  : ACE_Double_Linked_List_Iterator_Base <T> (dll)
{
  this->current_ = static_cast<T*> (dll.head_->prev_);
  // Advance current_ out of the null area and onto the last item in
  // the list
}

template <class T> void
ACE_Double_Linked_List_Reverse_Iterator<T>::reset (ACE_Double_Linked_List<T> &dll)
{
  this->ACE_Double_Linked_List_Iterator_Base <T>::reset (dll);
  this->current_ = static_cast<T*> (dll.head_->prev_);
  // Advance current_ out of the null area and onto the last item in
  // the list
}

template <class T> int
ACE_Double_Linked_List_Reverse_Iterator<T>::first (void)
{
  return this->go_tail ();
}

template <class T> int
ACE_Double_Linked_List_Reverse_Iterator<T>::advance (void)
{
  return this->do_retreat () ? 1 : 0;
}

template <class T> T*
ACE_Double_Linked_List_Reverse_Iterator<T>::advance_and_remove (bool dont_remove)
{
  T* item = 0;
  if (dont_remove)
    {
      this->do_retreat ();
    }
  else
    {
      item = this->next ();
      this->do_retreat ();
      // It seems dangerous to remove nodes in an iterator, but so it goes...
      ACE_Double_Linked_List<T> *dllist =
        const_cast<ACE_Double_Linked_List<T> *> (this->dllist_);
      dllist->remove (item);
    }
  return item;
}

template <class T> void
ACE_Double_Linked_List_Reverse_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

// Prefix advance.

template <class T>
ACE_Double_Linked_List_Reverse_Iterator<T> &
ACE_Double_Linked_List_Reverse_Iterator<T>::operator++ (void)
{
  this->do_retreat ();
  return *this;
}


// Postfix advance.

template <class T>
ACE_Double_Linked_List_Reverse_Iterator<T>
ACE_Double_Linked_List_Reverse_Iterator<T>::operator++ (int)
{
  ACE_Double_Linked_List_Reverse_Iterator<T> retv (*this);
  this->do_retreat ();
  return retv;
}


// Prefix reverse.

template <class T>
ACE_Double_Linked_List_Reverse_Iterator<T> &
ACE_Double_Linked_List_Reverse_Iterator<T>::operator-- (void)
{
  this->do_advance ();
  return *this;
}


// Postfix reverse.

template <class T>
ACE_Double_Linked_List_Reverse_Iterator<T>
ACE_Double_Linked_List_Reverse_Iterator<T>::operator-- (int)
{
  ACE_Double_Linked_List_Reverse_Iterator<T> retv (*this);
  this->do_advance ();
  return retv;
}


ACE_ALLOC_HOOK_DEFINE(ACE_Double_Linked_List)

  template <class T>
ACE_Double_Linked_List<T>:: ACE_Double_Linked_List (ACE_Allocator *alloc)
  : size_ (0), allocator_ (alloc)
{
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (T *) this->allocator_->malloc (sizeof (T)),
                  T);
  this->init_head ();
}

template <class T>
ACE_Double_Linked_List<T>::ACE_Double_Linked_List (const ACE_Double_Linked_List<T> &cx)
  : allocator_ (cx.allocator_)
{
  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (T *) this->allocator_->malloc (sizeof (T)),
                  T);
  this->init_head ();
  this->copy_nodes (cx);
  this->size_ = cx.size_;
}

template <class T> void
ACE_Double_Linked_List<T>::operator= (const ACE_Double_Linked_List<T> &cx)
{
  if (this != &cx)
    {
      this->delete_nodes ();
      this->copy_nodes (cx);
    }
}

template <class T>
ACE_Double_Linked_List<T>::~ACE_Double_Linked_List (void)
{
  this->delete_nodes ();

  ACE_DES_FREE (head_,
                this->allocator_->free,
                T);

  this->head_ = 0;
}

template <class T> int
ACE_Double_Linked_List<T>::is_empty (void) const
{
  return this->size () ? 0 : 1;
}

template <class T> int
ACE_Double_Linked_List<T>::is_full (void) const
{
  return 0;                     // We have no bound.
}

template <class T> T *
ACE_Double_Linked_List<T>::insert_tail (T *new_item)
{
  // Insert it before <head_>, i.e., at tail.
  this->insert_element (new_item, 1);
  return new_item;
}

template <class T> T *
ACE_Double_Linked_List<T>::insert_head (T *new_item)
{
  this->insert_element (new_item); // Insert it after <head_>, i.e., at head.
  return new_item;
}

template <class T> T *
ACE_Double_Linked_List<T>::delete_head (void)
{
  if (this->is_empty ())
    return 0;

  T *temp = static_cast<T *> (this->head_->next_);
  // Detach it from the list.
  this->remove_element (temp);
  return temp;
}

template <class T> T *
ACE_Double_Linked_List<T>::delete_tail (void)
{
  if (this->is_empty ())
    return 0;

  T *temp = static_cast <T *> (this->head_->prev_);
  // Detach it from the list.
  this->remove_element (temp);
  return temp;
}

template <class T> void
ACE_Double_Linked_List<T>::reset (void)
{
  this->delete_nodes ();
}

template <class T> int
ACE_Double_Linked_List<T>::get (T *&item, size_t slot)
{
  ACE_Double_Linked_List_Iterator<T> iter (*this);

  for (size_t i = 0;
       i < slot && !iter.done ();
       i++)
    iter.advance ();

  item = iter.next ();
  return item ? 0 : -1;
}

template <class T> size_t
ACE_Double_Linked_List<T>::size (void) const
{
  return this->size_;
}

template <class T> void
ACE_Double_Linked_List<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // Dump the state of an object.
#endif /* ACE_HAS_DUMP */
}

#if 0
template <class T> T *
ACE_Double_Linked_List<T>::find (const T &item)
{
  for (ACE_Double_Linked_List_Iterator<T> iter (*this);
       !iter.done ();
       iter.advance ())
    {
      T *temp = iter.next ();

      if (*temp == item)
        return temp;
    }

  return 0;
}

template <class T> int
ACE_Double_Linked_List<T>::remove (const T &item)
{
  T *temp = this->find (item);

  if (temp != 0)
    return this->remove (temp);
  else
    return -1;
}
#endif /* 0 */

template <class T> int
ACE_Double_Linked_List<T>::remove (T *n)
{
  return this->remove_element (n);
}

template <class T> void
ACE_Double_Linked_List<T>::delete_nodes (void)
{
  while (! this->is_empty ())
    {
      T * temp = static_cast<T*> (this->head_->next_);
      this->remove_element (temp);
      ACE_DES_FREE (temp,
                    this->allocator_->free,
                    T);
    }
}

template <class T> void
ACE_Double_Linked_List<T>::copy_nodes (const ACE_Double_Linked_List<T> &c)
{
  for (ACE_Double_Linked_List_Iterator<T> iter (c);
       !iter.done ();
       iter.advance ())
    {
      T* temp = 0;
      ACE_NEW_MALLOC (temp,
                      (T *)this->allocator_->malloc (sizeof (T)),
                      T (*iter.next ()));
      this->insert_tail (temp);
    }
}

template <class T> void
ACE_Double_Linked_List<T>::init_head (void)
{
  this->head_->next_ = this->head_;
  this->head_->prev_ = this->head_;
}

template <class T> int
ACE_Double_Linked_List<T>::insert_element (T *new_item,
                                           int before,
                                           T *old_item)
{
  if (old_item == 0)
    old_item = this->head_;

  if (before)
    old_item = static_cast<T *> (old_item->prev_);

  new_item->next_ = old_item->next_;
  new_item->next_->prev_ = new_item;
  new_item->prev_ = old_item;
  old_item->next_ = new_item;
  ++this->size_;
  return 0;                     // Well, what will cause errors here?
}

template <class T> int
ACE_Double_Linked_List<T>::remove_element (T *item)
{
  // Notice that you have to ensure that item is an element of this
  // list.  We can't do much checking here.

  if (item == this->head_ || item->next_ == 0
      || item->prev_ == 0 || this->size () == 0)      // Can't remove head
    return -1;

  item->prev_->next_ = item->next_;
  item->next_->prev_ = item->prev_;
  item->next_ = item->prev_ = 0; // reset pointers to prevent double removal.
  --this->size_;
  return 0;
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Fixed_Set)

template <class T, size_t ACE_SIZE> size_t
ACE_Fixed_Set<T, ACE_SIZE>::size (void) const
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::size");
  return this->cur_size_;
}

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Set<T, ACE_SIZE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set<T, ACE_SIZE>::~ACE_Fixed_Set (void)
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::~ACE_Fixed_Set");
  this->cur_size_ = 0;
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set<T, ACE_SIZE>::ACE_Fixed_Set (const ACE_Fixed_Set<T, ACE_SIZE> &fs)
  : cur_size_ (fs.cur_size_)
{
  ACE_TRACE ("ACE_Fixed_Set<T>::ACE_Fixed_Set");

  for (size_t i = 0, j = 0; i < fs.max_size_ && j < this->cur_size_; ++i)
    if (fs.search_structure_[i].is_free_ == 0)
      this->search_structure_[j++] = fs.search_structure_[i];
}

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Set<T, ACE_SIZE>::operator= (const ACE_Fixed_Set<T, ACE_SIZE> &fs)
{
  ACE_TRACE ("ACE_Fixed_Set<T>::operator=");

  if (this != &fs)
    {
      this->cur_size_ = fs.cur_size_;

      for (size_t i = 0, j = 0; i < fs.max_size_ && j < this->cur_size_; ++i)
        if (fs.search_structure_[i].is_free_ == 0)
          this->search_structure_[j++] = fs.search_structure_[i];
    }
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set<T, ACE_SIZE>::ACE_Fixed_Set (void)
  : cur_size_ (0),
    max_size_ (ACE_SIZE)
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::ACE_Fixed_Set");
  for (size_t i = 0; i < this->max_size_; i++)
    this->search_structure_[i].is_free_ = 1;
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set<T, ACE_SIZE>::find (const T &item) const
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::find");

  for (size_t i = 0, j = 0; i < this->max_size_ && j < this->cur_size_; ++i)
    if (this->search_structure_[i].is_free_ == 0)
      {
        if (this->search_structure_[i].item_ == item)
          return 0;
        ++j;
      }

  return -1;
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set<T, ACE_SIZE>::insert (const T &item)
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::insert");
  ssize_t first_free = -1;   // Keep track of first free slot.
  size_t i;

  for (i = 0;
       i < this->max_size_  && first_free == -1;
       ++i)

    // First, make sure we don't allow duplicates.

    if (this->search_structure_[i].is_free_ == 0)
      {
        if (this->search_structure_[i].item_ == item)
          return 1;
      }
    else
      first_free = static_cast<ssize_t> (i);

  // If we found a free spot let's reuse it.

  if (first_free > -1)
    {
      this->search_structure_[first_free].item_ = item;
      this->search_structure_[first_free].is_free_ = 0;
      this->cur_size_++;
      return 0;
    }
  else /* No more room! */
    {
      errno = ENOMEM;
      return -1;
    }
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set<T, ACE_SIZE>::remove (const T &item)
{
  ACE_TRACE ("ACE_Fixed_Set<T, ACE_SIZE>::remove");

  for (size_t i = 0, j = 0;
       i < this->max_size_ && j < this->cur_size_;
       ++i)
    if (this->search_structure_[i].is_free_ == 0)
      {
        if (this->search_structure_[i].item_ == item)
          {
            // Mark this entry as being free.
            this->search_structure_[i].is_free_ = 1;

            --this->cur_size_;
            return 0;
          }
        else
          ++j;
      }

  return -1;
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Fixed_Set_Iterator_Base)

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::dump_i (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::dump_i");
#endif /* ACE_HAS_DUMP */
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::ACE_Fixed_Set_Iterator_Base (ACE_Fixed_Set<T, ACE_SIZE> &s)
  : s_ (s),
    next_ (-1),
    iterated_items_ (0)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::ACE_Fixed_Set_Iterator_Base");
  this->advance ();
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::advance (void)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::advance");

  if (this->iterated_items_ < this->s_.cur_size_)
    {
      for (++this->next_;
           static_cast<size_t> (this->next_) < this->s_.max_size_;
           ++this->next_)
      if (this->s_.search_structure_[this->next_].is_free_ == 0)
        {
          ++this->iterated_items_;
          return 1;
        }
    }
  else
    ++this->next_;

  return 0;
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::first (void)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::first");

  next_ = -1;
  iterated_items_ = 0;
  return this->advance ();
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::done (void) const
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::done");

  return ! (this->iterated_items_ < this->s_.cur_size_);
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::next_i (T *&item)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE>::next_i");

  if (static_cast<size_t> (this->next_) < this->s_.max_size_)
    do
      {
        if (this->s_.search_structure_[this->next_].is_free_ == 0)
          {
            item = &this->s_.search_structure_[this->next_].item_;
            this->advance ();
            return 1;
          }
      }
    while (this->advance () == 1);

  return 0;
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Fixed_Set_Iterator)

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Set_Iterator<T, ACE_SIZE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set_Iterator<T, ACE_SIZE>::ACE_Fixed_Set_Iterator (ACE_Fixed_Set<T, ACE_SIZE> &s)
  : ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE> (s)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator<T, ACE_SIZE>::ACE_Fixed_Set_Iterator");
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator<T, ACE_SIZE>::next (T *&item)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator<T, ACE_SIZE>::next");
  return this->next_i (item);
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Iterator<T, ACE_SIZE>::remove (T *&item)
{
  ACE_TRACE ("ACE_Fixed_Set_Iterator<T, ACE_SIZE>::remove");

  if (this->s_.search_structure_[this->next_].is_free_ == 0)
    {
      item = &this->s_.search_structure_[this->next_].item_;
      this->s_.remove (*item);
      --(this->iterated_items_);
      return 1;
    }

  return 0;
}

template <class T, size_t ACE_SIZE> T&
ACE_Fixed_Set_Iterator<T, ACE_SIZE>::operator* (void)
{
  T *retv = 0;

  if (this->s_.search_structure_[this->next_].is_free_ == 0)
    retv = &this->s_.search_structure_[this->next_].item_;

  ACE_ASSERT (retv != 0);

  return *retv;
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Fixed_Set_Const_Iterator)

template <class T, size_t ACE_SIZE> void
ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class T, size_t ACE_SIZE>
ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::ACE_Fixed_Set_Const_Iterator (const ACE_Fixed_Set<T, ACE_SIZE> &s)
  : ACE_Fixed_Set_Iterator_Base<T, ACE_SIZE> (s)
{
  ACE_TRACE ("ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::ACE_Fixed_Set_Const_Iterator");
}

template <class T, size_t ACE_SIZE> int
ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::next (const T *&item)
{
  ACE_TRACE ("ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::next");

  return this->next_i (item);
}

template <class T, size_t ACE_SIZE> const T&
ACE_Fixed_Set_Const_Iterator<T, ACE_SIZE>::operator* (void) const
{
  const T *retv = 0;

  if (this->s_.search_structure_[this->next_].is_free_ == 0)
    retv = &this->s_.search_structure_[this->next_].item_;

  ACE_ASSERT (retv != 0);

  return *retv;
}

//--------------------------------------------------
ACE_ALLOC_HOOK_DEFINE(ACE_Bounded_Set)

template <class T> void
ACE_Bounded_Set<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Bounded_Set<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Bounded_Set<T>::~ACE_Bounded_Set (void)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::~ACE_Bounded_Set");
  delete [] this->search_structure_;
}

template <class T>
ACE_Bounded_Set<T>::ACE_Bounded_Set (void)
  : cur_size_ (0),
    max_size_ (static_cast<size_t> (ACE_Bounded_Set<T>::DEFAULT_SIZE))
{
  ACE_TRACE ("ACE_Bounded_Set<T>::ACE_Bounded_Set");

  ACE_NEW (this->search_structure_,
           typename ACE_Bounded_Set<T>::Search_Structure[this->max_size_]);

  for (size_t i = 0; i < this->max_size_; ++i)
    this->search_structure_[i].is_free_ = 1;
}

template <class T> size_t
ACE_Bounded_Set<T>::size (void) const
{
  ACE_TRACE ("ACE_Bounded_Set<T>::size");
  return this->cur_size_;
}

template <class T>
ACE_Bounded_Set<T>::ACE_Bounded_Set (const ACE_Bounded_Set<T> &bs)
  : cur_size_ (bs.cur_size_),
    max_size_ (bs.max_size_)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::ACE_Bounded_Set");

  ACE_NEW (this->search_structure_,
           typename ACE_Bounded_Set<T>::Search_Structure[this->max_size_]);

  for (size_t i = 0; i < this->cur_size_; i++)
    this->search_structure_[i] = bs.search_structure_[i];
}

template <class T> void
ACE_Bounded_Set<T>::operator= (const ACE_Bounded_Set<T> &bs)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::operator=");

  if (this != &bs)
    {
      if (this->max_size_ < bs.cur_size_)
        {
          delete [] this->search_structure_;
          ACE_NEW (this->search_structure_,
                   typename ACE_Bounded_Set<T>::Search_Structure[bs.cur_size_]);
          this->max_size_ = bs.cur_size_;
        }

      this->cur_size_ = bs.cur_size_;

      for (size_t i = 0; i < this->cur_size_; i++)
        this->search_structure_[i] = bs.search_structure_[i];
    }
}

template <class T>
ACE_Bounded_Set<T>::ACE_Bounded_Set (size_t size)
  : cur_size_ (0),
    max_size_ (size)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::ACE_Bounded_Set");
  ACE_NEW (this->search_structure_,
           typename ACE_Bounded_Set<T>::Search_Structure[size]);

  for (size_t i = 0; i < this->max_size_; i++)
    this->search_structure_[i].is_free_ = 1;
}

template <class T> int
ACE_Bounded_Set<T>::find (const T &item) const
{
  ACE_TRACE ("ACE_Bounded_Set<T>::find");

  for (size_t i = 0; i < this->cur_size_; i++)
    if (this->search_structure_[i].item_ == item
        && this->search_structure_[i].is_free_ == 0)
      return 0;

  return -1;
}

template <class T> int
ACE_Bounded_Set<T>::insert (const T &item)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::insert");
  int first_free = -1;   // Keep track of first free slot.
  size_t i;

  for (i = 0; i < this->cur_size_; i++)
    // First, make sure we don't allow duplicates.

    if (this->search_structure_[i].item_ == item
        && this->search_structure_[i].is_free_ == 0)
      return 1;
    else if (this->search_structure_[i].is_free_ && first_free == -1)
      first_free = static_cast<int> (i);

  if (first_free > -1)   // If we found a free spot let's reuse it.
    {
      this->search_structure_[first_free].item_ = item;
      this->search_structure_[first_free].is_free_ = 0;
      return 0;
    }
  else if (i < this->max_size_) // Insert at the end of the active portion.
    {
      this->search_structure_[i].item_ = item;
      this->search_structure_[i].is_free_ = 0;
      this->cur_size_++;
      return 0;
    }
  else /* No more room! */
    {
      errno = ENOMEM;
      return -1;
    }
}

template <class T> int
ACE_Bounded_Set<T>::remove (const T &item)
{
  ACE_TRACE ("ACE_Bounded_Set<T>::remove");
  for (size_t i = 0; i < this->cur_size_; i++)
    if (this->search_structure_[i].item_ == item)
      {
        // Mark this entry as being free.
        this->search_structure_[i].is_free_ = 1;

        // If we just unbound the highest entry, then we need to
        // figure out where the next highest active entry is.
        if (i + 1 == this->cur_size_)
          {
            while (i > 0 && this->search_structure_[--i].is_free_)
              continue;

            if (i == 0 && this->search_structure_[i].is_free_)
              this->cur_size_ = 0;
            else
              this->cur_size_ = i + 1;
          }
        return 0;
      }

  return -1;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Bounded_Set_Iterator)

  template <class T> void
ACE_Bounded_Set_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Bounded_Set_Iterator<T>::ACE_Bounded_Set_Iterator (ACE_Bounded_Set<T> &s)
  : s_ (s),
    next_ (-1)
{
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::ACE_Bounded_Set_Iterator");
  this->advance ();
}

template <class T> int
ACE_Bounded_Set_Iterator<T>::advance (void)
{
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::advance");

  for (++this->next_;
       static_cast<size_t> (this->next_) < this->s_.cur_size_
         && this->s_.search_structure_[this->next_].is_free_;
       ++this->next_)
    continue;

  return static_cast<size_t> (this->next_) < this->s_.cur_size_;
}

template <class T> int
ACE_Bounded_Set_Iterator<T>::first (void)
{
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::first");

  next_ = -1;
  return this->advance ();
}

template <class T> int
ACE_Bounded_Set_Iterator<T>::done (void) const
{
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::done");

  return static_cast<ACE_CAST_CONST size_t> (this->next_) >=
    this->s_.cur_size_;
}

template <class T> int
ACE_Bounded_Set_Iterator<T>::next (T *&item)
{
  ACE_TRACE ("ACE_Bounded_Set_Iterator<T>::next");
  if (static_cast<size_t> (this->next_) < this->s_.cur_size_)
    {
      item = &this->s_.search_structure_[this->next_].item_;
      return 1;
    }
  else
    return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_DNode)

  template <class T>
ACE_DNode<T>::ACE_DNode (const T &i, ACE_DNode<T> *n, ACE_DNode<T> *p)
  : next_ (n), prev_ (p), item_ (i)
{
}

template <class T>
ACE_DNode<T>::~ACE_DNode (void)
{
}

// ****************************************************************

template <class T> void
ACE_Unbounded_Stack_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Unbounded_Stack_Iterator<T>::ACE_Unbounded_Stack_Iterator (ACE_Unbounded_Stack<T> &q)
  : current_ (q.head_->next_),
    stack_ (q)
{
  // ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::ACE_Unbounded_Stack_Iterator");
}

template <class T> int
ACE_Unbounded_Stack_Iterator<T>::advance (void)
{
  // ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::advance");
  this->current_ = this->current_->next_;
  return this->current_ != this->stack_.head_;
}

template <class T> int
ACE_Unbounded_Stack_Iterator<T>::first (void)
{
  // ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::first");
  this->current_ = this->stack_.head_->next_;
  return this->current_ != this->stack_.head_;
}

template <class T> int
ACE_Unbounded_Stack_Iterator<T>::done (void) const
{
  ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::done");

  return this->current_ == this->stack_.head_;
}

template <class T> int
ACE_Unbounded_Stack_Iterator<T>::next (T *&item)
{
  // ACE_TRACE ("ACE_Unbounded_Stack_Iterator<T>::next");
  if (this->current_ == this->stack_.head_)
    return 0;
  else
    {
      item = &this->current_->item_;
      return 1;
    }
}


ACE_ALLOC_HOOK_DEFINE(ACE_Ordered_MultiSet)


  template <class T>
ACE_Ordered_MultiSet<T>::ACE_Ordered_MultiSet (ACE_Allocator *alloc)
  : head_ (0)
  , tail_ (0)
  , cur_size_ (0)
  , allocator_ (alloc)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::ACE_Ordered_MultiSet");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();
}

template <class T>
ACE_Ordered_MultiSet<T>::ACE_Ordered_MultiSet (const ACE_Ordered_MultiSet<T> &us)
  : head_ (0)
  , tail_ (0)
  , cur_size_ (0)
  , allocator_ (us.allocator_)
{
  ACE_TRACE ("ACE_Ordered_MultiSet<T>::ACE_Ordered_MultiSet");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  this->copy_nodes (us);
}

template <class T>
ACE_Ordered_MultiSet<T>::~ACE_Ordered_MultiSet (void)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::~ACE_Ordered_MultiSet");

  this->delete_nodes ();
}


template <class T> void
ACE_Ordered_MultiSet<T>::operator= (const ACE_Ordered_MultiSet<T> &us)
{
  ACE_TRACE ("ACE_Ordered_MultiSet<T>::operator=");

  if (this != &us)
    {
      this->delete_nodes ();
      this->copy_nodes (us);
    }
}


template <class T> int
ACE_Ordered_MultiSet<T>::insert (const T &item)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::insert");

  return this->insert_from (item, this->head_, 0);
}

template <class T> int
ACE_Ordered_MultiSet<T>::insert (const T &new_item,
                                 ITERATOR &iter)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::insert using iterator");

  return  this->insert_from (new_item, iter.current_, &iter.current_);
}

template <class T> int
ACE_Ordered_MultiSet<T>::remove (const T &item)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::remove");

  ACE_DNode<T> *node = 0;

  int result = locate (item, 0, node);

  // if we found the node, remove from list and free it
  if (node && (result == 0))
    {
      if (node->prev_)
        node->prev_->next_ = node->next_;
      else
        head_ = node->next_;

      if (node->next_)
        node->next_->prev_ = node->prev_;
      else
        tail_ = node->prev_;

      --this->cur_size_;

      ACE_DES_FREE_TEMPLATE (node,
                             this->allocator_->free,
                             ACE_DNode,
                             <T>);
      return 0;
    }

  return -1;
}

template <class T> int
ACE_Ordered_MultiSet<T>::find (const T &item,
                               ITERATOR &iter) const
{
  // search an occurance of item, using iterator's current position as a hint
  ACE_DNode<T> *node = iter.current_;
  int const result = locate (item, node, node);

  // if we found the node, update the iterator and indicate success
  if (node && (result == 0))
    {
      iter.current_ = node;
      return 0;
    }

  return -1;
}



template <class T> void
ACE_Ordered_MultiSet<T>::reset (void)
{
  ACE_TRACE ("reset");

  this->delete_nodes ();
}

template <class T> void
ACE_Ordered_MultiSet<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  //  ACE_TRACE ("ACE_Ordered_MultiSet<T>::dump");
  //
  //  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  //  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_ = %u"), this->head_));
  //  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_->next_ = %u"), this->head_->next_));
  //  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncur_size_ = %d\n"), this->cur_size_));
  //
  //  T *item = 0;
  //  size_t count = 1;
  //
  //  for (ACE_Ordered_MultiSet_Iterator<T> iter (*(ACE_Ordered_MultiSet<T> *) this);
  //       iter.next (item) != 0;
  //       iter.advance ())
  //    ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("count = %d\n"), count++));
  //
  //  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class T> int
ACE_Ordered_MultiSet<T>::insert_from (const T &item, ACE_DNode<T> *position,
                                      ACE_DNode<T> **new_position)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet<T>::insert_from");

  // create a new node
  ACE_DNode<T> *temp = 0;
  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<ACE_DNode<T>*> (this->allocator_->malloc (sizeof (ACE_DNode<T>))),
                         ACE_DNode<T> (item),
                         -1);
  // obtain approximate location of the node
  int result = locate (item, position, position);

  // if there are nodes in the multiset
  if (position)
    {
      switch (result)
        {
          // insert after the approximate position
        case -1:

          // if there is a following node
          if (position->next_)
            {
              // link up with the following node
              position->next_->prev_ = temp;
              temp->next_ = position->next_;
            }
          else
            // appending to the end of the set
            tail_ = temp;

          // link up with the preceeding node
          temp->prev_ = position;
          position->next_ = temp;

          break;

          // insert before the position
        case  0:
        case  1:

          // if there is a preceeding node
          if (position->prev_)
            {
              // link up with the preceeding node
              position->prev_->next_ = temp;
              temp->prev_ = position->prev_;
            }
          else
            // prepending to the start of the set
            head_ = temp;

          // link up with the preceeding node
          temp->next_ = position;
          position->prev_ = temp;

          break;

        default:
          return -1;
        }
    }
  else
    {
      // point the head and tail to the new node.
      this->head_ = temp;
      this->tail_ = temp;
    }

  ++this->cur_size_;
  if (new_position)
    *new_position = temp;

  return 0;
}

template <class T> int
ACE_Ordered_MultiSet<T>::locate (const T &item, ACE_DNode<T> *start_position,
                                 ACE_DNode<T> *&new_position) const
{
  if (! start_position)
    start_position = this->head_;

  // If starting before the item, move forward until at or just before
  // item.
  while (start_position && start_position->item_ < item &&
         start_position->next_)
    start_position = start_position->next_;

  // If starting after the item, move back until at or just after item
  while (start_position && item < start_position->item_ &&
         start_position->prev_)
    start_position = start_position->prev_;

  // Save the (approximate) location in the passed pointer.
  new_position = start_position;

  // Show the location is after (1), before (-1) , or at (0) the item
  if (!new_position)
    return 1;
  else if (item < new_position->item_)
    return 1;
  else if (new_position->item_ < item)
    return -1;
  else
    return 0;
}

// Looks for first occurance of <item> in the ordered set, using the
// passed starting position as a hint: if there is such an instance,
// it updates the new_position pointer to point to one such node and
// returns 0; if there is no such node, then if there is a node before
// where the item would have been, it updates the new_position pointer
// to point to this node and returns -1; if there is no such node,
// then if there is a node after where the item would have been, it
// updates the new_position pointer to point to this node (or 0 if
// there is no such node) and returns 1;

template <class T> void
ACE_Ordered_MultiSet<T>::copy_nodes (const ACE_Ordered_MultiSet<T> &us)
{
  ACE_DNode<T> *insertion_point = this->head_;

  for (ACE_DNode<T> *curr = us.head_;
       curr != 0;
       curr = curr->next_)
    this->insert_from (curr->item_, insertion_point, &insertion_point);
}

template <class T> void
ACE_Ordered_MultiSet<T>::delete_nodes (void)
{
  // iterate through list, deleting nodes
  for (ACE_DNode<T> *curr = this->head_;
       curr != 0;
       )
    {
      ACE_DNode<T> *temp = curr;
      curr = curr->next_;
      ACE_DES_FREE_TEMPLATE (temp,
                             this->allocator_->free,
                             ACE_DNode,
                             <T>);
    }

  this->head_ = 0;
  this->tail_ = 0;
  this->cur_size_ = 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Ordered_MultiSet_Iterator)

template <class T>
ACE_Ordered_MultiSet_Iterator<T>::ACE_Ordered_MultiSet_Iterator (ACE_Ordered_MultiSet<T> &s)
  : current_ (s.head_),
    set_ (s)
{
  // ACE_TRACE ("ACE_Ordered_MultiSet_Iterator<T>::ACE_Ordered_MultiSet_Iterator");
}

template <class T> int
ACE_Ordered_MultiSet_Iterator<T>::next (T *&item) const
{
  // ACE_TRACE ("ACE_Ordered_MultiSet_Iterator<T>::next");
  if (this->current_)
    {
      item = &this->current_->item_;
      return 1;
    }

  return 0;
}

template <class T> T&
ACE_Ordered_MultiSet_Iterator<T>::operator* (void)
{
  //ACE_TRACE ("ACE_Ordered_MultiSet_Iterator<T>::operator*");
  T *retv = 0;

  int const result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

ACE_ALLOC_HOOK_DEFINE (ACE_DLList_Node)

template <class T> T *
ACE_DLList<T>::insert_tail (T *new_item)
{
  ACE_DLList_Node *temp1 = 0;
  ACE_NEW_MALLOC_RETURN (temp1,
                         static_cast<ACE_DLList_Node *> (this->allocator_->malloc (sizeof (ACE_DLList_Node))),
                         ACE_DLList_Node (new_item),
                         0);
  ACE_DLList_Node *temp2 = ACE_DLList_Base::insert_tail (temp1);
  return (T *) (temp2 ? temp2->item_ : 0);
}

template <class T> T *
ACE_DLList<T>::insert_head (T *new_item)
{
  ACE_DLList_Node *temp1 = 0;
  ACE_NEW_MALLOC_RETURN (temp1,
                         (ACE_DLList_Node *) this->allocator_->malloc (sizeof (ACE_DLList_Node)),
                         ACE_DLList_Node (new_item), 0);
  ACE_DLList_Node *temp2 = ACE_DLList_Base::insert_head (temp1);
  return (T *) (temp2 ? temp2->item_ : 0);
}

template <class T> T *
ACE_DLList<T>::delete_head (void)
{
  ACE_DLList_Node *temp1 = ACE_DLList_Base::delete_head ();
  T *temp2 = (T *) (temp1 ? temp1->item_ : 0);
  ACE_DES_FREE (temp1,
                this->allocator_->free,
                ACE_DLList_Node);

  return temp2;
}

template <class T> T *
ACE_DLList<T>::delete_tail (void)
{
  ACE_DLList_Node *temp1 = ACE_DLList_Base::delete_tail ();
  T *temp2 = (T *) (temp1 ? temp1->item_ : 0);
  ACE_DES_FREE (temp1,
                this->allocator_->free,
                ACE_DLList_Node);
  return temp2;
}

// ****************************************************************

// Compare this array with <s> for equality.

template <class T> bool
ACE_Array<T>::operator== (const ACE_Array<T> &s) const
{
  if (this == &s)
    return true;
  else if (this->size () != s.size ())
    return false;

  const size_t len = s.size ();
  for (size_t slot = 0; slot < len; ++slot)
    if ((*this)[slot] != s[slot])
      return false;

  return true;
}

// ****************************************************************

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CONTAINERS_T_CPP */

