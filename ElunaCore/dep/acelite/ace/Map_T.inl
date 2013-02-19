// -*- C++ -*-
//
// $Id: Map_T.inl 92097 2010-09-30 05:41:49Z msmit $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T> ACE_INLINE int
ACE_Noop_Key_Generator<T>::operator() (T &)
{
  return -1;
}

template <class T> ACE_INLINE
ACE_Incremental_Key_Generator<T>::ACE_Incremental_Key_Generator (void)
  : t_ (0)
{
}

template <class T> ACE_INLINE int
ACE_Incremental_Key_Generator<T>::operator() (T &t)
{
  t = ++this->t_;
  return 0;
}

template <class T> ACE_INLINE const T &
ACE_Incremental_Key_Generator<T>::current_value (void) const
{
  return this->t_;
}

template <class T> ACE_INLINE
ACE_Iterator<T>::ACE_Iterator (ACE_Iterator_Impl<T> *impl)
  : implementation_ (impl)
{
}

template <class T> ACE_INLINE
ACE_Iterator<T>::ACE_Iterator (const ACE_Iterator<T> &rhs)
  : implementation_ (rhs.implementation_->clone ())
{
}

template <class T> ACE_INLINE
ACE_Iterator<T>::~ACE_Iterator (void)
{
  delete this->implementation_;
}

template <class T> ACE_INLINE ACE_Iterator<T> &
ACE_Iterator<T>::operator= (const ACE_Iterator<T> &rhs)
{
  delete this->implementation_;
  this->implementation_ = rhs.implementation_->clone ();
  return *this;
}

template <class T> ACE_INLINE bool
ACE_Iterator<T>::operator== (const ACE_Iterator<T> &rhs) const
{
  return this->implementation_->compare (*rhs.implementation_);
}

template <class T> ACE_INLINE bool
ACE_Iterator<T>::operator!= (const ACE_Iterator<T> &rhs) const
{
  return !this->operator== (rhs);
}

template <class T> ACE_INLINE T
ACE_Iterator<T>::operator* (void) const
{
  return this->implementation_->dereference ();
}

template <class T> ACE_INLINE ACE_Iterator<T> &
ACE_Iterator<T>::operator++ (void)
{
  this->implementation_->plus_plus ();
  return *this;
}

template <class T> ACE_INLINE ACE_Iterator<T>
ACE_Iterator<T>::operator++ (int)
{
  ACE_Iterator<T> tmp = *this;
  this->implementation_->plus_plus ();
  return tmp;
}

template <class T> ACE_INLINE ACE_Iterator<T> &
ACE_Iterator<T>::operator-- (void)
{
  this->implementation_->minus_minus ();
  return *this;
}

template <class T> ACE_INLINE ACE_Iterator<T>
ACE_Iterator<T>::operator-- (int)
{
  ACE_Iterator<T> tmp = *this;
  this->implementation_->minus_minus ();
  return tmp;
}

template <class T> ACE_INLINE ACE_Iterator_Impl<T> &
ACE_Iterator<T>::impl (void)
{
  return *this->implementation_;
}

template <class T> ACE_INLINE
ACE_Reverse_Iterator<T>::ACE_Reverse_Iterator (ACE_Reverse_Iterator_Impl<T> *impl)
  : implementation_ (impl)
{
}

template <class T> ACE_INLINE
ACE_Reverse_Iterator<T>::ACE_Reverse_Iterator (const ACE_Reverse_Iterator<T> &rhs)
  : implementation_ (rhs.implementation_->clone ())
{
}

template <class T> ACE_INLINE
ACE_Reverse_Iterator<T>::~ACE_Reverse_Iterator (void)
{
  delete this->implementation_;
}

template <class T> ACE_INLINE ACE_Reverse_Iterator<T> &
ACE_Reverse_Iterator<T>::operator= (const ACE_Reverse_Iterator<T> &rhs)
{
  delete this->implementation_;
  this->implementation_ = rhs.implementation_->clone ();
  return *this;
}

template <class T> ACE_INLINE bool
ACE_Reverse_Iterator<T>::operator== (const ACE_Reverse_Iterator<T> &rhs) const
{
  return this->implementation_->compare (*rhs.implementation_);
}

template <class T> ACE_INLINE bool
ACE_Reverse_Iterator<T>::operator!= (const ACE_Reverse_Iterator<T> &rhs) const
{
  return !this->operator== (rhs);
}

template <class T> ACE_INLINE T
ACE_Reverse_Iterator<T>::operator* (void) const
{
  return this->implementation_->dereference ();
}

template <class T> ACE_INLINE ACE_Reverse_Iterator<T> &
ACE_Reverse_Iterator<T>::operator++ (void)
{
  this->implementation_->plus_plus ();
  return *this;
}

template <class T> ACE_INLINE ACE_Reverse_Iterator<T>
ACE_Reverse_Iterator<T>::operator++ (int)
{
  ACE_Reverse_Iterator<T> tmp = *this;
  this->implementation_->plus_plus ();
  return tmp;
}

template <class T> ACE_INLINE ACE_Reverse_Iterator<T> &
ACE_Reverse_Iterator<T>::operator-- (void)
{
  this->implementation_->minus_minus ();
  return *this;
}

template <class T> ACE_INLINE ACE_Reverse_Iterator<T>
ACE_Reverse_Iterator<T>::operator-- (int)
{
  ACE_Reverse_Iterator<T> tmp = *this;
  this->implementation_->minus_minus ();
  return tmp;
}

template <class T> ACE_INLINE ACE_Reverse_Iterator_Impl<T> &
ACE_Reverse_Iterator<T>::impl (void)
{
  return *this->implementation_;
}

template <class KEY, class VALUE> ACE_INLINE
ACE_Map<KEY, VALUE>::ACE_Map (void)
{
}

template <class KEY, class VALUE> ACE_INLINE ACE_Iterator<ACE_Reference_Pair<const KEY, VALUE> >
ACE_Map<KEY, VALUE>::begin (void)
{
  return iterator (this->begin_impl ());
}

template <class KEY, class VALUE> ACE_INLINE ACE_Iterator<ACE_Reference_Pair<const KEY, VALUE> >
ACE_Map<KEY, VALUE>::end (void)
{
  return iterator (this->end_impl ());
}

template <class KEY, class VALUE> ACE_INLINE ACE_Reverse_Iterator<ACE_Reference_Pair<const KEY, VALUE> >
ACE_Map<KEY, VALUE>::rbegin (void)
{
  return reverse_iterator (this->rbegin_impl ());
}

template <class KEY, class VALUE> ACE_INLINE ACE_Reverse_Iterator<ACE_Reference_Pair<const KEY, VALUE> >
ACE_Map<KEY, VALUE>::rend (void)
{
  return reverse_iterator (this->rend_impl ());
}

template <class T, class IMPLEMENTATION, class ENTRY> ACE_INLINE
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::ACE_Map_Impl_Iterator_Adapter (const IMPLEMENTATION &impl)
  : implementation_ (impl)
{
}

template <class T, class IMPLEMENTATION, class ENTRY> ACE_INLINE IMPLEMENTATION &
ACE_Map_Impl_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::impl (void)
{
  return this->implementation_;
}

template <class T, class IMPLEMENTATION, class ENTRY> ACE_INLINE
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::ACE_Map_Impl_Reverse_Iterator_Adapter (const IMPLEMENTATION &impl)
  : implementation_ (impl)
{
}

template <class T, class IMPLEMENTATION, class ENTRY> ACE_INLINE IMPLEMENTATION &
ACE_Map_Impl_Reverse_Iterator_Adapter<T, IMPLEMENTATION, ENTRY>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_INLINE
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::ACE_Map_Impl (ACE_Allocator *alloc)
  : implementation_ (alloc)
{
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_INLINE
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::ACE_Map_Impl (size_t size,
                                                                                           ACE_Allocator *alloc)
  : implementation_ (size,
                     alloc)
{
}

template <class KEY, class VALUE, class IMPLEMENTATION, class ITERATOR, class REVERSE_ITERATOR, class ENTRY> ACE_INLINE IMPLEMENTATION &
ACE_Map_Impl<KEY, VALUE, IMPLEMENTATION, ITERATOR, REVERSE_ITERATOR, ENTRY>::impl (void)
{
  return this->implementation_;
}

template <class T, class VALUE> ACE_INLINE
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::ACE_Active_Map_Manager_Iterator_Adapter (const ACE_Map_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class VALUE> ACE_INLINE ACE_Map_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &
ACE_Active_Map_Manager_Iterator_Adapter<T, VALUE>::impl (void)
{
  return this->implementation_;
}

template <class T, class VALUE> ACE_INLINE
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::ACE_Active_Map_Manager_Reverse_Iterator_Adapter (const ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class VALUE> ACE_INLINE ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, VALUE, ACE_Null_Mutex> &
ACE_Active_Map_Manager_Reverse_Iterator_Adapter<T, VALUE>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_INLINE
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::ACE_Active_Map_Manager_Adapter (ACE_Allocator *alloc)
  : implementation_ (alloc)
{
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_INLINE
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::ACE_Active_Map_Manager_Adapter (size_t size,
                                                                                         ACE_Allocator *alloc)
  : implementation_ (size,
                     alloc)
{
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_INLINE ACE_Active_Map_Manager<std::pair<KEY, VALUE> > &
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class KEY_ADAPTER> ACE_INLINE KEY_ADAPTER &
ACE_Active_Map_Manager_Adapter<KEY, VALUE, KEY_ADAPTER>::key_adapter (void)
{
  return this->key_adapter_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_INLINE
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::ACE_Hash_Map_Manager_Ex_Iterator_Adapter (const ACE_Hash_Map_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_INLINE ACE_Hash_Map_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &
ACE_Hash_Map_Manager_Ex_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::impl (void)
{
  return this->implementation_;
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_INLINE
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter (const ACE_Hash_Map_Reverse_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS> ACE_INLINE ACE_Hash_Map_Reverse_Iterator_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &
ACE_Hash_Map_Manager_Ex_Reverse_Iterator_Adapter<T, KEY, VALUE, HASH_KEY, COMPARE_KEYS>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_INLINE
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::ACE_Hash_Map_Manager_Ex_Adapter (ACE_Allocator *alloc)
  : implementation_ (alloc)
{
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_INLINE
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::ACE_Hash_Map_Manager_Ex_Adapter (size_t size,
                                                                                                                     ACE_Allocator *alloc)
  : implementation_ (size,
                     alloc)
{
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_INLINE ACE_Hash_Map_Manager_Ex<KEY, VALUE, HASH_KEY, COMPARE_KEYS, ACE_Null_Mutex> &
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class HASH_KEY, class COMPARE_KEYS, class KEY_GENERATOR> ACE_INLINE KEY_GENERATOR &
ACE_Hash_Map_Manager_Ex_Adapter<KEY, VALUE, HASH_KEY, COMPARE_KEYS, KEY_GENERATOR>::key_generator (void)
{
  return this->key_generator_;
}

template <class T, class KEY, class VALUE> ACE_INLINE
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::ACE_Map_Manager_Iterator_Adapter (const ACE_Map_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class KEY, class VALUE> ACE_INLINE ACE_Map_Iterator<KEY, VALUE, ACE_Null_Mutex> &
ACE_Map_Manager_Iterator_Adapter<T, KEY, VALUE>::impl (void)
{
  return this->implementation_;
}

template <class T, class KEY, class VALUE> ACE_INLINE
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::ACE_Map_Manager_Reverse_Iterator_Adapter (const ACE_Map_Reverse_Iterator<KEY, VALUE, ACE_Null_Mutex> &impl)
  : implementation_ (impl)
{
}

template <class T, class KEY, class VALUE> ACE_INLINE ACE_Map_Reverse_Iterator<KEY, VALUE, ACE_Null_Mutex> &
ACE_Map_Manager_Reverse_Iterator_Adapter<T, KEY, VALUE>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_INLINE
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::ACE_Map_Manager_Adapter (ACE_Allocator *alloc)
  : implementation_ (alloc)
{
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_INLINE
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::ACE_Map_Manager_Adapter (size_t size,
                                                                             ACE_Allocator *alloc)
  : implementation_ (size,
                     alloc)
{
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_INLINE ACE_Map_Manager<KEY, VALUE, ACE_Null_Mutex> &
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::impl (void)
{
  return this->implementation_;
}

template <class KEY, class VALUE, class KEY_GENERATOR> ACE_INLINE KEY_GENERATOR &
ACE_Map_Manager_Adapter<KEY, VALUE, KEY_GENERATOR>::key_generator (void)
{
  return this->key_generator_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
