// -*- C++ -*-
//
// $Id: Array_Base.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Clean up the array (e.g., delete dynamically allocated memory).
template <class T> ACE_INLINE
ACE_Array_Base<T>::~ACE_Array_Base (void)
{
  ACE_DES_ARRAY_FREE (this->array_,
                      this->max_size_,
                      this->allocator_->free,
                      T);
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::iterator
ACE_Array_Base<T>::begin (void)
{
  return this->array_;
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::iterator
ACE_Array_Base<T>::end (void)
{
  return this->array_ + this->cur_size_;
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::const_iterator
ACE_Array_Base<T>::begin (void) const
{
  return this->array_;
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::const_iterator
ACE_Array_Base<T>::end (void) const
{
  return this->array_ + this->cur_size_;
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::reverse_iterator
ACE_Array_Base<T>::rbegin (void)
{
  return reverse_iterator (this->end ());
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::reverse_iterator
ACE_Array_Base<T>::rend (void)
{
  return reverse_iterator (this->begin ());
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::const_reverse_iterator
ACE_Array_Base<T>::rbegin (void) const
{
  return const_reverse_iterator (this->end ());
}

template <class T>
ACE_INLINE typename ACE_Array_Base<T>::const_reverse_iterator
ACE_Array_Base<T>::rend (void) const
{
  return const_reverse_iterator (this->begin ());
}

template <class T> ACE_INLINE typename ACE_Array_Base<T>::size_type
ACE_Array_Base<T>::size (void) const
{
  return this->cur_size_;
}

template <class T> ACE_INLINE typename ACE_Array_Base<T>::size_type
ACE_Array_Base<T>::max_size (void) const
{
  return this->max_size_;
}

template <class T> ACE_INLINE bool
ACE_Array_Base<T>::in_range (typename ACE_Array_Base<T>::size_type index) const
{
  return index < this->cur_size_;
}

template <class T> ACE_INLINE T &
ACE_Array_Base<T>::operator[] (typename ACE_Array_Base<T>::size_type index)
{
  return this->array_[index];
}

template <class T> ACE_INLINE const T &
ACE_Array_Base<T>::operator[] (typename ACE_Array_Base<T>::size_type index) const
{
  return this->array_[index];
}

// ****************************************************************

template <class T> ACE_INLINE void
ACE_Array_Iterator<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  // ACE_TRACE ("ACE_Array_Iterator<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T> ACE_INLINE
ACE_Array_Iterator<T>::ACE_Array_Iterator (ACE_Array_Base<T> &a)
    : current_ (0),
      array_ (a)
{
  // ACE_TRACE ("ACE_Array_Iterator<T>::ACE_Array_Iterator");
}

template <class T> ACE_INLINE int
ACE_Array_Iterator<T>::advance (void)
{
  // ACE_TRACE ("ACE_Array_Iterator<T>::advance");

  if (this->current_ < array_.size ())
    {
      ++this->current_;
      return 1;
    }
  else
    {
      // Already finished iterating.
      return 0;
    }
}

template <class T> ACE_INLINE int
ACE_Array_Iterator<T>::done (void) const
{
  ACE_TRACE ("ACE_Array_Iterator<T>::done");

  return this->current_ >= array_.size ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
