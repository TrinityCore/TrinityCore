// -*- C++ -*-
//
// $Id: Intrusive_List.inl 80826 2008-03-04 14:51:23Z wotte $

#include <algorithm>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class T> ACE_INLINE int
ACE_Intrusive_List<T>::is_empty (void) const
{
  return this->head_ == 0;
}

template<class T> ACE_INLINE int
ACE_Intrusive_List<T>::empty (void) const
{
  return this->is_empty ();
}

template<class T> ACE_INLINE T *
ACE_Intrusive_List<T>::head (void) const
{
  return this->head_;
}

template<class T> ACE_INLINE T *
ACE_Intrusive_List<T>::tail (void) const
{
  return this->tail_;
}

template<class T> ACE_INLINE void
ACE_Intrusive_List<T>::swap(ACE_Intrusive_List<T> & rhs)
{
  std::swap(head_, rhs.head_);
  std::swap(tail_, rhs.tail_);
}

ACE_END_VERSIONED_NAMESPACE_DECL
