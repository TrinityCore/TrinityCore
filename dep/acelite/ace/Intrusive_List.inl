// -*- C++ -*-
//
// $Id: Intrusive_List.inl 91688 2010-09-09 11:21:50Z johnnyw $

#include <algorithm>

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class T> ACE_INLINE bool
ACE_Intrusive_List<T>::is_empty (void) const
{
  return this->head_ == 0;
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
