// -*- C++ -*-
//
// $Id: Active_Map_Manager_T.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::bind (ACE_Active_Map_Manager_Key &key,
                                 T *&internal_value)
{
  ACE_UINT32 slot_index;
  int result = this->next_free (slot_index);

  if (result == 0)
    {
      // Move from free list to occupied list
      this->move_from_free_list_to_occupied_list (slot_index);

      // Reset the key.
      this->search_structure_[slot_index].ext_id_.increment_slot_generation_count ();
      this->search_structure_[slot_index].ext_id_.slot_index (slot_index);

      // Copy the key for the user.
      key = this->search_structure_[slot_index].ext_id_;

      // This is where the user should place the value.
      internal_value = &this->search_structure_[slot_index].int_id_;

      // Update the current size.
      ++this->cur_size_;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::bind (const T &value,
                                 ACE_Active_Map_Manager_Key &key)
{
  T *internal_value = 0;
  int result = this->bind (key,
                           internal_value);

  if (result == 0)
    {
      // Store new value.
      *internal_value = value;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::bind (const T &value)
{
  ACE_Active_Map_Manager_Key key;
  return this->bind (value, key);
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::find (const ACE_Active_Map_Manager_Key &key,
                                 T *&internal_value) const
{
  ACE_UINT32 slot_index = key.slot_index ();
  ACE_UINT32 slot_generation = key.slot_generation ();

  if (slot_index > this->total_size_ ||
#if defined (ACE_HAS_LAZY_MAP_MANAGER)
      this->search_structure_[slot_index].free_ ||
#endif /* ACE_HAS_LAZY_MAP_MANAGER */
      this->search_structure_[slot_index].ext_id_.slot_generation () != slot_generation ||
      this->search_structure_[slot_index].ext_id_.slot_index () ==
                 (ACE_UINT32)this->free_list_id ())
    {
      return -1;
    }
  else
    {
      // This is where the user value is.
      internal_value = &this->search_structure_[slot_index].int_id_;
    }

  return 0;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::find (const ACE_Active_Map_Manager_Key &key) const
{
  T *internal_value = 0;
  return this->find (key,
                     internal_value);
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::find (const ACE_Active_Map_Manager_Key &key,
                                 T &value) const
{
  T *internal_value = 0;
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    value = *internal_value;

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::rebind (const ACE_Active_Map_Manager_Key &key,
                                   const T &value)
{
  int result = this->find (key);

  if (result == 0)
    {
      // Store new value.
      this->search_structure_[key.slot_index ()].int_id_ = value;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::rebind (const ACE_Active_Map_Manager_Key &key,
                                   const T &value,
                                   T &old_value)
{
  int result = this->find (key);

  if (result == 0)
    {
      // Copy old value.
      old_value = this->search_structure_[key.slot_index ()].int_id_;

      // Store new value.
      this->search_structure_[key.slot_index ()].int_id_ = value;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::rebind (const ACE_Active_Map_Manager_Key &key,
                                   const T &value,
                                   ACE_Active_Map_Manager_Key &old_key,
                                   T &old_value)
{
  int result = this->find (key);

  if (result == 0)
    {
      // Copy old key.
      old_key = this->search_structure_[key.slot_index ()].ext_id_;

      // Copy old value.
      old_value = this->search_structure_[key.slot_index ()].int_id_;

      // Store new value.
      this->search_structure_[key.slot_index ()].int_id_ = value;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::unbind (const ACE_Active_Map_Manager_Key &key,
                                   T *&internal_value)
{
  int result = this->find (key,
                           internal_value);

  if (result == 0)
    {
      ACE_UINT32 slot_index = key.slot_index ();

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

      //
      // In the case of lazy map managers, the movement of free slots
      // from the occupied list to the free list is delayed until we
      // run out of free slots in the free list.
      //

      this->search_structure_[slot_index].free_ = 1;

#else

      // Move from occupied list to free list.
      this->move_from_occupied_list_to_free_list (slot_index);

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

      // Reset the slot_index.  This will tell us that this entry is free.
      this->search_structure_[slot_index].ext_id_.slot_index (this->free_list_id ());

      // Update the current size.
      --this->cur_size_;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::unbind (const ACE_Active_Map_Manager_Key &key,
                                   T &value)
{
  T *internal_value;
  int result = this->unbind (key,
                             internal_value);

  if (result == 0)
    {
      // Copy old value.
      value = *internal_value;
    }

  return result;
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::unbind (const ACE_Active_Map_Manager_Key &key)
{
  T *internal_value;
  return this->unbind (key,
                       internal_value);
}

template <class T> ACE_INLINE
ACE_Active_Map_Manager<T>::ACE_Active_Map_Manager (ACE_Allocator *alloc)
  : ACE_AMM_BASE (alloc)
{
}

template <class T> ACE_INLINE
ACE_Active_Map_Manager<T>::ACE_Active_Map_Manager (size_t size,
                                                   ACE_Allocator *alloc)
  : ACE_AMM_BASE (size,
                  alloc)
{
}

template <class T> ACE_INLINE
ACE_Active_Map_Manager<T>::~ACE_Active_Map_Manager (void)
{
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::open (size_t length,
                                 ACE_Allocator *alloc)
{
  return ACE_AMM_BASE::open (length, alloc);
}

template <class T> ACE_INLINE int
ACE_Active_Map_Manager<T>::close (void)
{
  return ACE_AMM_BASE::close ();
}

template <class T> ACE_INLINE size_t
ACE_Active_Map_Manager<T>::current_size (void) const
{
  return ACE_AMM_BASE::current_size ();
}

template <class T> ACE_INLINE size_t
ACE_Active_Map_Manager<T>::total_size (void) const
{
  return ACE_AMM_BASE::total_size ();
}

/* static */
template <class T> ACE_INLINE const ACE_Active_Map_Manager_Key
ACE_Active_Map_Manager<T>::npos (void)
{
  return ACE_Active_Map_Manager_Key (~0, ~0);
}

template <class T> ACE_INLINE void
ACE_Active_Map_Manager<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_AMM_BASE::dump ();
#endif /* ACE_HAS_DUMP */
}

template <class T> ACE_Map_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex>
ACE_Active_Map_Manager<T>::begin (void)
{
  return ACE_AMM_BASE::begin ();
}

template <class T> ACE_INLINE ACE_Map_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex>
ACE_Active_Map_Manager<T>::end (void)
{
  return ACE_AMM_BASE::end ();
}

template <class T> ACE_INLINE ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex>
ACE_Active_Map_Manager<T>::rbegin (void)
{
  return ACE_AMM_BASE::rbegin ();
}

template <class T> ACE_INLINE ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex>
ACE_Active_Map_Manager<T>::rend (void)
{
  return ACE_AMM_BASE::rend ();
}

ACE_END_VERSIONED_NAMESPACE_DECL
