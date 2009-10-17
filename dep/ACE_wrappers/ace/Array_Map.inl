// -*- C++ -*-
//
// $Id: Array_Map.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<typename Key, typename Value, class EqualTo>
ACE_INLINE
ACE_Array_Map<Key, Value, EqualTo>::ACE_Array_Map (
  typename ACE_Array_Map<Key, Value, EqualTo>::size_type s)
  : size_ (0)
  , capacity_ (s)
  , nodes_ (s == 0 ? 0 : new value_type[s])
{
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE ACE_Array_Map<Key, Value, EqualTo> &
ACE_Array_Map<Key, Value, EqualTo>::operator= (
  ACE_Array_Map<Key, Value, EqualTo> const & map)
{
  // Strongly exception-safe assignment.

  ACE_Array_Map<Key, Value, EqualTo> temp (map);
  this->swap (temp);
  return *this;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::iterator
ACE_Array_Map<Key, Value, EqualTo>::begin (void)
{
  return this->nodes_;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::iterator
ACE_Array_Map<Key, Value, EqualTo>::end (void)
{
  return this->nodes_ + this->size_;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator
ACE_Array_Map<Key, Value, EqualTo>::begin (void) const
{
  return this->nodes_;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::const_iterator
ACE_Array_Map<Key, Value, EqualTo>::end (void) const
{
  return this->nodes_ + this->size_;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::reverse_iterator
ACE_Array_Map<Key, Value, EqualTo>::rbegin (void)
{
  return reverse_iterator (this->end ());
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::reverse_iterator
ACE_Array_Map<Key, Value, EqualTo>::rend (void)
{
  return reverse_iterator (this->begin ());
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::const_reverse_iterator
ACE_Array_Map<Key, Value, EqualTo>::rbegin (void) const
{
  return const_reverse_iterator (this->end ());
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::const_reverse_iterator
ACE_Array_Map<Key, Value, EqualTo>::rend (void) const
{
  return const_reverse_iterator (this->begin ());
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::size_type
ACE_Array_Map<Key, Value, EqualTo>::size (void) const
{
  return this->size_;
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::size_type
ACE_Array_Map<Key, Value, EqualTo>::max_size (void) const
{
  return size_type (-1) / sizeof (value_type);
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE bool
ACE_Array_Map<Key, Value, EqualTo>::is_empty (void) const
{
  return this->size_ == 0;
}

// The following method is deprecated.

template<typename Key, typename Value, class EqualTo>
ACE_INLINE bool
ACE_Array_Map<Key, Value, EqualTo>::empty (void) const
{
  return this->is_empty ();
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::size_type
ACE_Array_Map<Key, Value, EqualTo>::count (
  typename ACE_Array_Map<Key, Value, EqualTo>::key_type const & k)
{
  return
    (this->find (k) == this->end () ? 0 : 1); // Only one datum per key.
}

template<typename Key, typename Value, class EqualTo>
ACE_INLINE typename ACE_Array_Map<Key, Value, EqualTo>::data_type &
ACE_Array_Map<Key, Value, EqualTo>::operator[] (
  typename ACE_Array_Map<Key, Value, EqualTo>::key_type const & k)
{
  iterator i = (this->insert (value_type (k, data_type ()))).first;
  return (*i).second;
}

ACE_END_VERSIONED_NAMESPACE_DECL
