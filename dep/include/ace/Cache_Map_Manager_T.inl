// -*- C++ -*-
//
//$Id: Cache_Map_Manager_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE int
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::purge (void)
{
  return this->caching_strategy ().caching_utility ().clear_cache (this->map_,
                                                                   this->caching_strategy ().purge_percent ());
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE size_t
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::current_size (void) const
{
  return this->map_.current_size ();
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE size_t
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::total_size (void) const
{
  return this->map_.total_size ();
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE CMAP_TYPE &
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::map (void)
{
  return this->map_;
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE CACHING_STRATEGY &
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::caching_strategy (void)
{
  return this->caching_strategy_;
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Iterator<KEY, VALUE, ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::begin (void)
{
  return ITERATOR (this->map_.begin ());
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Iterator<KEY, VALUE, ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::end (void)
{
  return ITERATOR (this->map_.end ());
}

template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::rbegin (void)
{
  return REVERSE_ITERATOR (this->map_.rbegin ());
}
template <class KEY, class VALUE, class CMAP_TYPE, class ITERATOR_IMPL, class REVERSE_ITERATOR_IMPL, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Manager<KEY, VALUE, CMAP_TYPE, ITERATOR_IMPL, REVERSE_ITERATOR_IMPL, CACHING_STRATEGY, ATTRIBUTES>::rend (void)
{
  return REVERSE_ITERATOR (this->map_.rend ());
}

////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::ACE_Cache_Map_Iterator (const ACE_Cache_Map_Iterator <KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs)
  : iterator_implementation_ (rhs.iterator_implementation_)
{
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator= (const ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs)
{
  this->iterator_implementation_ = rhs.iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE bool
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator== (const ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs) const
{
  return this->iterator_implementation_ == rhs.iterator_implementation_;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE bool
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator!= (const ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs) const
{
  return this->iterator_implementation_ != rhs.iterator_implementation_;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Reference_Pair<KEY, VALUE>
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator* (void) const
{
  value_type retn ((*this->iterator_implementation_).ext_id_,
                   (*this->iterator_implementation_).int_id_.first ());
  return retn;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator++ (void)
{
  ++this->iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator++ (int)
{
  ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> retn = *this;
  ++this->iterator_implementation_;
  return retn;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator-- (void)
{
  --this->iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator-- (int)
{
  ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> retn = *this;
  --this->iterator_implementation_;
  return retn;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE void
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->iterator_implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::ACE_Cache_Map_Iterator (const IMPLEMENTATION &iterator_impl)
  : iterator_implementation_ (iterator_impl)
{
}

template <class KEY, class VALUE, class IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE IMPLEMENTATION &
ACE_Cache_Map_Iterator<KEY, VALUE, IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::iterator_implementation (void)
{
  return this->iterator_implementation_;
}

////////////////////////////////////////////////////////////////////////////////

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::ACE_Cache_Map_Reverse_Iterator (const ACE_Cache_Map_Reverse_Iterator <KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs)
  : reverse_iterator_implementation_ (rhs.reverse_iterator_implementation_)
{
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::~ACE_Cache_Map_Reverse_Iterator (void)
{
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator= (const ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs)
{
  this->reverse_iterator_implementation_ = rhs.reverse_iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE bool
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator== (const ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs) const
{
  return this->reverse_iterator_implementation_ == rhs.reverse_iterator_implementation_;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE bool
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator!= (const ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &rhs) const
{
  return this->reverse_iterator_implementation_ != rhs.reverse_iterator_implementation_;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE ACE_Reference_Pair<KEY, VALUE>
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator* (void) const
{
  value_type retv ((*this->reverse_iterator_implementation_).ext_id_,
                   (*this->reverse_iterator_implementation_).int_id_.first ());
  return retv;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator++ (void)
{
  ++this->reverse_iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator++ (int)
{
  ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> retn = *this;
  ++this->reverse_iterator_implementation_;
  return retn;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> &
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator-- (void)
{
  --this->reverse_iterator_implementation_;
  return *this;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::operator-- (int)
{
  ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES> retn = *this;
  --this->reverse_iterator_implementation_;
  return retn;
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE void
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->reverse_iterator_implementation_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::ACE_Cache_Map_Reverse_Iterator (const REVERSE_IMPLEMENTATION &iterator_impl)
  : reverse_iterator_implementation_(iterator_impl)
{
}

template <class KEY, class VALUE, class REVERSE_IMPLEMENTATION, class CACHING_STRATEGY, class ATTRIBUTES> ACE_INLINE REVERSE_IMPLEMENTATION &
ACE_Cache_Map_Reverse_Iterator<KEY, VALUE, REVERSE_IMPLEMENTATION, CACHING_STRATEGY, ATTRIBUTES>::iterator_implementation (void)
{
  return this->reverse_iterator_implementation_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
