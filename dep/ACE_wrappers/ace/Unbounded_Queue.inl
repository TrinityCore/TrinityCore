// -*- C++ -*-
//
// $Id: Unbounded_Queue.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class T> ACE_INLINE size_t
ACE_Unbounded_Queue<T>::size (void) const
{
  return this->cur_size_;
}
template <class T> ACE_INLINE int
ACE_Unbounded_Queue<T>::is_empty (void) const
{
  //  ACE_TRACE ("ACE_Unbounded_Queue<T>::is_empty");
  return this->head_ == this->head_->next_;
}
template <class T> ACE_INLINE int
ACE_Unbounded_Queue<T>::is_full (void) const
{
  //  ACE_TRACE ("ACE_Unbounded_Queue<T>::is_full");
  return 0; // We should implement a "node of last resort for this..."
}
ACE_END_VERSIONED_NAMESPACE_DECL
