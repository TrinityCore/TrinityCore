// $Id: Unbounded_Set_Ex.cpp 81702 2008-05-15 10:18:07Z johnnyw $

#ifndef ACE_UNBOUNDED_SET_EX_CPP
#define ACE_UNBOUNDED_SET_EX_CPP

#include "ace/Unbounded_Set.h"
#include "ace/Malloc_Base.h"
#include "ace/Log_Msg.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Unbounded_Set_Ex.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Unbounded_Set_Ex)

template <class T, class C> size_t
ACE_Unbounded_Set_Ex<T, C>::size (void) const
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::size");
  return this->cur_size_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex<T, C>::insert_tail (const T &item)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::insert_tail");
  NODE *temp = 0;

  // Insert <item> into the old dummy node location.
  this->head_->item_ = item;

  // Create a new dummy node.
  ACE_NEW_MALLOC_RETURN (temp,
                         static_cast<NODE*> (this->allocator_->malloc (sizeof (NODE))),
                         NODE (this->head_->next_),
                         -1);
  // Link this pointer into the list.
  this->head_->next_ = temp;

  // Point the head to the new dummy node.
  this->head_ = temp;

  ++this->cur_size_;
  return 0;
}

template <class T, class C> void
ACE_Unbounded_Set_Ex<T, C>::reset (void)
{
  ACE_TRACE ("reset");

  this->delete_nodes ();
}

template <class T, class C> void
ACE_Unbounded_Set_Ex<T, C>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_ = %u"), this->head_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nhead_->next_ = %u"), this->head_->next_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncur_size_ = %d\n"), this->cur_size_));

  T *item = 0;
#if !defined (ACE_NLOGGING)
  size_t count = 1;
#endif /* ! ACE_NLOGGING */

  const_iterator const the_end = this->end ();
  for (const_iterator i (this->begin ());
       i != end;
       ++i)
    ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("count = %u\n"), count++));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class T, class C> void
ACE_Unbounded_Set_Ex<T, C>::copy_nodes (const ACE_Unbounded_Set_Ex<T, C> &us)
{
  for (NODE *curr = us.head_->next_;
       curr != us.head_;
       curr = curr->next_)
    this->insert_tail (curr->item_);
}

template <class T, class C> void
ACE_Unbounded_Set_Ex<T, C>::delete_nodes (void)
{
  NODE *curr = this->head_->next_;

  // Keep looking until we've hit the dummy node.

  while (curr != this->head_)
    {
      NODE *temp = curr;
      curr = curr->next_;
      ACE_DES_FREE_TEMPLATE2 (temp,
                             this->allocator_->free,
                             ACE_Node,
                             T, C);
      --this->cur_size_;
    }

  // Reset the list to be a circular list with just a dummy node.
  this->head_->next_ = this->head_;
}

template <class T, class C>
ACE_Unbounded_Set_Ex<T, C>::~ACE_Unbounded_Set_Ex (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::~ACE_Unbounded_Set_Ex");

  this->delete_nodes ();

  // Delete the dummy node.
  ACE_DES_FREE_TEMPLATE2 (head_,
                         this->allocator_->free,
                         ACE_Node,
                         T, C);
  this->head_ = 0;
}

template <class T, class C>
ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex (ACE_Allocator *alloc)
  : head_ (0),
    cur_size_ (0),
    allocator_ (alloc)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (NODE*) this->allocator_->malloc (sizeof (NODE)),
                  NODE);
  // Make the list circular by pointing it back to itself.
  this->head_->next_ = this->head_;
}

template <class T, class C>
ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex (const C &comp,
                                            ACE_Allocator *alloc)
  : head_ (0),
    cur_size_ (0),
    allocator_ (alloc),
    comp_ (comp)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (NODE*) this->allocator_->malloc (sizeof (NODE)),
                  NODE);
  // Make the list circular by pointing it back to itself.
  this->head_->next_ = this->head_;
}

template <class T, class C>
ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex (const ACE_Unbounded_Set_Ex<T, C> &us)
  : head_ (0),
    cur_size_ (0),
    allocator_ (us.allocator_),
    comp_ (us.comp_)
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::ACE_Unbounded_Set_Ex");

  if (this->allocator_ == 0)
    this->allocator_ = ACE_Allocator::instance ();

  ACE_NEW_MALLOC (this->head_,
                  (NODE*) this->allocator_->malloc (sizeof (NODE)),
                  NODE);
  this->head_->next_ = this->head_;
  this->copy_nodes (us);
}

template <class T, class C> ACE_Unbounded_Set_Ex<T, C> &
ACE_Unbounded_Set_Ex<T, C>::operator= (const ACE_Unbounded_Set_Ex<T, C> &us)
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::operator=");

  if (this != &us)
    {
      this->delete_nodes ();
      this->copy_nodes (us);
    }

  return *this;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex<T, C>::find (const T &item) const
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::find");
  const_iterator const the_end = this->end ();
  for (const_iterator i = this->begin (); i != the_end; ++i)
    if (this->comp_(*i, item))
      return 0;

  return -1;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex<T, C>::insert (const T &item)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::insert");
  if (this->find (item) == 0)
    return 1;
  else
    return this->insert_tail (item);
}

template <class T, class C> int
ACE_Unbounded_Set_Ex<T, C>::remove (const T &item)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::remove");

  // Insert the item to be founded into the dummy node.
  this->head_->item_ = item;

  NODE *curr = this->head_;

  while (!(this->comp_ (curr->next_->item_, item)))
    curr = curr->next_;

  if (curr->next_ == this->head_)
    return -1; // Item was not found.
  else
    {
      NODE *temp = curr->next_;
      // Skip over the node that we're deleting.
      curr->next_ = temp->next_;
      --this->cur_size_;
      ACE_DES_FREE_TEMPLATE2 (temp,
                             this->allocator_->free,
                             ACE_Node,
                             T, C);
      return 0;
    }
}

template <class T, class C> typename ACE_Unbounded_Set_Ex<T, C>::iterator
ACE_Unbounded_Set_Ex<T, C>::begin (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::begin");
  return iterator (*this);
}

template <class T, class C> typename ACE_Unbounded_Set_Ex<T, C>::iterator
ACE_Unbounded_Set_Ex<T, C>::end (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::end");
  return iterator (*this, 1);
}

template <class T, class C> typename ACE_Unbounded_Set_Ex<T, C>::const_iterator
ACE_Unbounded_Set_Ex<T, C>::begin (void) const
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::begin");
  return const_iterator (*this);
}

template <class T, class C> typename ACE_Unbounded_Set_Ex<T, C>::const_iterator
ACE_Unbounded_Set_Ex<T, C>::end (void) const
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex<T, C>::end");
  return const_iterator (*this, 1);
}

ACE_ALLOC_HOOK_DEFINE(ACE_Unbounded_Set_Ex_Iterator)

template <class T, class C> void
ACE_Unbounded_Set_Ex_Iterator<T, C>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T, class C>
ACE_Unbounded_Set_Ex_Iterator<T, C>::ACE_Unbounded_Set_Ex_Iterator (
  ACE_Unbounded_Set_Ex<T, C> &s,
  bool end)
  : current_ (!end ? s.head_->next_ : s.head_ ),
    set_ (&s)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::ACE_Unbounded_Set_Ex_Iterator");
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Iterator<T, C>::advance (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::advance");
  this->current_ = this->current_->next_;
  return this->current_ != this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Iterator<T, C>::first (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::first");
  this->current_ = this->set_->head_->next_;
  return this->current_ != this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Iterator<T, C>::done (void) const
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::done");

  return this->current_ == this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Iterator<T, C>::next (T *&item)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::next");
  if (this->current_ == this->set_->head_)
    return 0;
  else
    {
      item = &this->current_->item_;
      return 1;
    }
}

template <class T, class C> ACE_Unbounded_Set_Ex_Iterator<T, C>
ACE_Unbounded_Set_Ex_Iterator<T, C>::operator++ (int)
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::operator++ (int)");
  ACE_Unbounded_Set_Ex_Iterator<T, C> retv (*this);

  // postfix operator

  this->advance ();
  return retv;
}

template <class T, class C> ACE_Unbounded_Set_Ex_Iterator<T, C>&
ACE_Unbounded_Set_Ex_Iterator<T, C>::operator++ (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::operator++ (void)");

  // prefix operator

  this->advance ();
  return *this;
}

template <class T, class C> T&
ACE_Unbounded_Set_Ex_Iterator<T, C>::operator* (void)
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::operator*");
  T *retv = 0;

  int result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

template <class T, class C> bool
ACE_Unbounded_Set_Ex_Iterator<T, C>::operator== (const ACE_Unbounded_Set_Ex_Iterator<T, C> &rhs) const
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::operator==");
  return (this->set_ == rhs.set_ && this->current_ == rhs.current_);
}

template <class T, class C> bool
ACE_Unbounded_Set_Ex_Iterator<T, C>::operator!= (const ACE_Unbounded_Set_Ex_Iterator<T, C> &rhs) const
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Iterator<T, C>::operator!=");
  return (this->set_ != rhs.set_ || this->current_ != rhs.current_);
}

ACE_ALLOC_HOOK_DEFINE(ACE_Unbounded_Set_Ex_Const_Iterator)

template <class T, class C> void
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T, class C>
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::ACE_Unbounded_Set_Ex_Const_Iterator (
  const ACE_Unbounded_Set_Ex<T, C> &s,
  bool end)
  : current_ (!end ? s.head_->next_ : s.head_ ),
    set_ (&s)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::ACE_Unbounded_Set_Ex_Const_Iterator");
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::advance (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::advance");
  this->current_ = this->current_->next_;
  return this->current_ != this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::first (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::first");
  this->current_ = this->set_->head_->next_;
  return this->current_ != this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::done (void) const
{
  ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::done");

  return this->current_ == this->set_->head_;
}

template <class T, class C> int
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::next (T *&item)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::next");
  if (this->current_ == this->set_->head_)
    return 0;
  else
    {
      item = &this->current_->item_;
      return 1;
    }
}

template <class T, class C> ACE_Unbounded_Set_Ex_Const_Iterator<T, C>
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator++ (int)
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator++ (int)");
  ACE_Unbounded_Set_Ex_Const_Iterator<T, C> retv (*this);

  // postfix operator

  this->advance ();
  return retv;
}

template <class T, class C> ACE_Unbounded_Set_Ex_Const_Iterator<T, C>&
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator++ (void)
{
  // ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator++ (void)");

  // prefix operator

  this->advance ();
  return *this;
}

template <class T, class C> T&
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator* (void)
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator*");
  T *retv = 0;

  int const result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

template <class T, class C> bool
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator== (const ACE_Unbounded_Set_Ex_Const_Iterator<T, C> &rhs) const
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator==");
  return (this->set_ == rhs.set_ && this->current_ == rhs.current_);
}

template <class T, class C> bool
ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator!= (const ACE_Unbounded_Set_Ex_Const_Iterator<T, C> &rhs) const
{
  //ACE_TRACE ("ACE_Unbounded_Set_Ex_Const_Iterator<T, C>::operator!=");
  return (this->set_ != rhs.set_ || this->current_ != rhs.current_);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_UNBOUNDED_SET_EX_CPP */

