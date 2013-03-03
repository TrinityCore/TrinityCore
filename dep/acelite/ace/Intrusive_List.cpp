// $Id: Intrusive_List.cpp 92069 2010-09-28 11:38:59Z johnnyw $

#ifndef ACE_INTRUSIVE_LIST_CPP
#define ACE_INTRUSIVE_LIST_CPP

#include "ace/Intrusive_List.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Intrusive_List.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T>
ACE_Intrusive_List<T>::ACE_Intrusive_List (void)
  : head_ (0)
  , tail_ (0)
{
}

template<class T>
ACE_Intrusive_List<T>::~ACE_Intrusive_List (void)
{
}

template<class T> void
ACE_Intrusive_List<T>::push_back (T *node)
{
  if (this->tail_ == 0)
    {
      this->tail_ = node;
      this->head_ = node;
      node->next (0);
      node->prev (0);
    }
  else
    {
      this->tail_->next (node);
      node->prev (this->tail_);
      node->next (0);
      this->tail_ = node;
    }
}

template<class T> void
ACE_Intrusive_List<T>::push_front (T *node)
{
  if (this->head_ == 0)
    {
      this->tail_ = node;
      this->head_ = node;
      node->next (0);
      node->prev (0);
    }
  else
    {
      this->head_->prev (node);
      node->next (this->head_);
      node->prev (0);
      this->head_ = node;
    }
}

template<class T> T *
ACE_Intrusive_List<T>::pop_front (void)
{
  T *node = this->head_;
  if (node != 0)
    {
      this->unsafe_remove (node);
    }
  return node;
}

template<class T> T *
ACE_Intrusive_List<T>::pop_back (void)
{
  T *node = this->tail_;
  if (node != 0)
    {
      this->unsafe_remove (node);
    }
  return node;
}

template<class T> void
ACE_Intrusive_List<T>::remove (T *node)
{
  for (T *i = this->head_; i != 0; i = i->next ())
    {
      if (node == i)
        {
          this->unsafe_remove (node);
          return;
        }
    }
}

template<class T> void
ACE_Intrusive_List<T>::unsafe_remove (T *node)
{
  if (node->prev () != 0)
    node->prev ()->next (node->next ());
  else
    this->head_ = node->next ();

  if (node->next () != 0)
    node->next ()->prev (node->prev ());
  else
    this->tail_ = node->prev ();

  node->next (0);
  node->prev (0);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_INTRUSIVE_LIST_CPP */
