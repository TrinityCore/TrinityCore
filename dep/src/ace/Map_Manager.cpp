// $Id: Map_Manager.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_MAP_MANAGER_CPP
#define ACE_MAP_MANAGER_CPP

#include "ace/Map_Manager.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Malloc_Base.h"

#if !defined (__ACE_INLINE__)
#include "ace/Map_Manager.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Map_Entry)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Manager)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Const_Iterator_Base)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Iterator_Base)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Const_Iterator)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Iterator)
ACE_ALLOC_HOOK_DEFINE(ACE_Map_Reverse_Iterator)

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::open (size_t size,
                                                 ACE_Allocator *alloc)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  // Close old map (if any).
  this->close_i ();

  // Use the user specified allocator or the default singleton one.
  if (alloc == 0)
    alloc = ACE_Allocator::instance ();

  this->allocator_ = alloc;

  // This assertion is here to help track a situation that shouldn't
  // happen.
  ACE_ASSERT (size != 0);

  // Active_Map_Manager depends on the <slot_index_> being of fixed
  // size. It cannot be size_t because size_t is 64-bits on 64-bit
  // platform and 32-bits on 32-bit platforms. Size of the <slot_index_>
  // has to be consistent across platforms. ACE_UIN32 is chosen as
  // ACE_UIN32_MAX is big enough. The assert is to ensure that the user
  // doesn't open the ACE_Map_Manager with a bigger size than we can
  // handle.
  ACE_ASSERT (size <= ACE_UINT32_MAX);

  // Resize from 0 to <size>.  Note that this will also set up the
  // circular free list.
  return this->resize_i ((ACE_UINT32) size);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close_i (void)
{
  // Free entries.
  this->free_search_structure ();

  // Reset sizes.
  this->total_size_ = 0;
  this->cur_size_ = 0;

  // Reset circular free list.
  this->free_list_.next (this->free_list_id ());
  this->free_list_.prev (this->free_list_id ());

  // Reset circular occupied list.
  this->occupied_list_.next (this->occupied_list_id ());
  this->occupied_list_.prev (this->occupied_list_id ());

  return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind_i (const EXT_ID &ext_id,
                                                   const INT_ID &int_id)
{
  // Try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);

  if (result == 0)
    // We found the key. Nothing to change.
    return 1;
  else
    // We didn't find the key.
    return this->shared_bind (ext_id,
                              int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::next_free (ACE_UINT32 &free_slot)
{
  // Look in the free list for an empty slot.
  free_slot = this->free_list_.next ();

  // If we do find a free slot, return successfully.
  if (free_slot != this->free_list_id ())
    return 0;

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  // Move any free slots from occupied list to free list.
  this->move_all_free_slots_from_occupied_list ();

  // Try again in case we found any free slots in the occupied list.
  free_slot = this->free_list_.next ();

  // If we do find a free slot, return successfully.
  if (free_slot != this->free_list_id ())
    return 0;

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  // Resize the map.
  int result = this->resize_i (this->new_size ());

  // Check for errors.
  if (result == 0)
    // New free slot.
    free_slot = this->free_list_.next ();

  return result;
}

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::move_all_free_slots_from_occupied_list (void)
{
  //
  // In the case of lazy map managers, the movement of free slots from
  // the occupied list to the free list is delayed until we run out of
  // free slots in the free list.
  //

  // Go through the entire occupied list, moving free slots to the
  // free list. Note that all free slots in the occupied list are
  // moved in this loop.
  for (ACE_UINT32 i = this->occupied_list_.next ();
       i != this->occupied_list_id ();
       )
    {
      //
      // Note the trick used here: Information about the current slot
      // is first noted; <i> then moves to the next occupied slot;
      // only after this is the slot (potentially) moved from the
      // occupied list to the free list.  This order of things, i.e.,
      // moving <i> before moving the free slot is necessary,
      // otherwise we'll forget which our next occupied slot is.
      //

      // Note information about current slot.
      ACE_Map_Entry<EXT_ID, INT_ID> &current_slot = this->search_structure_[i];
      ACE_UINT32 position_of_current_slot = i;

      // Move <i> to next occupied slot.
      i = this->search_structure_[i].next ();

      // If current slot is free
      if (current_slot.free_)
        {
          // Reset free flag to zero before moving to free list.
          current_slot.free_ = false;

          // Move from occupied list to free list.
          this->move_from_occupied_list_to_free_list (position_of_current_slot);
        }
    }
}

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_move (ACE_UINT32 slot,
                                                        ACE_Map_Entry<EXT_ID, INT_ID> &current_list,
                                                        ACE_UINT32 current_list_id,
                                                        ACE_Map_Entry<EXT_ID, INT_ID> &new_list,
                                                        ACE_UINT32 new_list_id)
{
  // Grab the entry.
  ENTRY &entry = this->search_structure_[slot];

  // Remove from current list.

  // Fix the entry before us.
  ACE_UINT32 current_list_prev = entry.prev ();

  if (current_list_prev == current_list_id)
    current_list.next (entry.next ());
  else
    this->search_structure_[current_list_prev].next (entry.next ());

  // Fix the entry after us.
  ACE_UINT32 current_list_next = entry.next ();

  if (current_list_next == current_list_id)
    current_list.prev (entry.prev ());
  else
    this->search_structure_[current_list_next].prev (entry.prev ());

  // Add to new list.

  // Fix us.
  ACE_UINT32 new_list_next = new_list.next ();
  entry.next (new_list_next);
  entry.prev (new_list_id);

  // Fix entry before us.
  new_list.next (slot);

  // Fix entry after us.
  if (new_list_next == new_list_id)
    new_list.prev (slot);
  else
    this->search_structure_[new_list_next].prev (slot);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::shared_bind (const EXT_ID &ext_id,
                                                        const INT_ID &int_id)
{
  // This function assumes that the find() has already been done, and
  // therefore, simply adds to the map.

  // Find an empty slot.
  ACE_UINT32 slot = 0;
  int result = this->next_free (slot);

  if (result == 0)
    {
      // Copy key and value.
      this->search_structure_[slot].int_id_ = int_id;
      this->search_structure_[slot].ext_id_ = ext_id;

      // Move from free list to occupied list
      this->move_from_free_list_to_occupied_list (slot);

      // Update the current size.
      ++this->cur_size_;
    }

  return result;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                     const INT_ID &int_id,
                                                     EXT_ID &old_ext_id,
                                                     INT_ID &old_int_id)
{
  // First try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);
  if (result == 0)
    {
      // We found it, so make copies of the old entries and rebind
      // current entries.
      ENTRY &ss = this->search_structure_[slot];
      old_ext_id = ss.ext_id_;
      old_int_id = ss.int_id_;
      ss.ext_id_ = ext_id;
      ss.int_id_ = int_id;

      // Sync changed entry.
      this->allocator_->sync (&ss, sizeof ss);

      return 1;
    }
  else
    // We didn't find it, so let's add it.
    return this->shared_bind (ext_id,
                              int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                     const INT_ID &int_id,
                                                     INT_ID &old_int_id)
{
  // First try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);
  if (result == 0)
    {
      // We found it, so make copies of the old entries and rebind
      // current entries.
      ENTRY &ss = this->search_structure_[slot];
      old_int_id = ss.int_id_;
      ss.ext_id_ = ext_id;
      ss.int_id_ = int_id;

      // Sync changed entry.
      this->allocator_->sync (&ss, sizeof ss);

      return 1;
    }
  else
    // We didn't find it, so let's add it.
    return this->shared_bind (ext_id,
                              int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                     const INT_ID &int_id)
{
  // First try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);
  if (result == 0)
    {
      // We found it, so rebind current entries.
      ENTRY &ss = this->search_structure_[slot];
      ss.ext_id_ = ext_id;
      ss.int_id_ = int_id;

      // Sync changed entry.
      this->allocator_->sync (&ss, sizeof ss);

      return 1;
    }
  else
    // We didn't find it, so let's add it.
    return this->shared_bind (ext_id,
                              int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind_i (const EXT_ID &ext_id,
                                                      INT_ID &int_id)
{
  // Try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);
  if (result == 0)
    {
      // Key was found.  Make a copy of value, but *don't* update
      // anything in the map!
      int_id = this->search_structure_[slot].int_id_;
      return 1;
    }
  else
    // We didn't find it, so let's bind it!
    return this->bind_i (ext_id,
                         int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_and_return_index (const EXT_ID &ext_id,
                                                                  ACE_UINT32 &slot)
{
  // Go through the entire occupied list looking for the key.
  for (ACE_UINT32 i = this->occupied_list_.next ();
       i != this->occupied_list_id ();
       i = this->search_structure_[i].next ())
    {
#if defined (ACE_HAS_LAZY_MAP_MANAGER)
      if (this->search_structure_[i].free_)
        continue;
#endif /* ACE_HAS_LAZY_MAP_MANAGER */

      if (this->equal (this->search_structure_[i].ext_id_,
                       ext_id))
        {
          // If found, return slot.
          slot = i;
          return 0;
        }
    }

  // Key was not found.
  return -1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_all (void)
{
  // Go through the entire occupied list.
  for (ACE_UINT32 i = this->occupied_list_.next ();
       i != this->occupied_list_id ();
       )
    {
      //
      // Note the trick used here: Information about the current slot
      // is first noted; <i> then moves to the next occupied slot;
      // only after this is the slot (potentially) moved from the
      // occupied list to the free list.  This order of things, i.e.,
      // moving <i> before moving the free slot is necessary,
      // otherwise we'll forget which our next occupied slot is.
      //

      // Note information about current slot.
      ACE_Map_Entry<EXT_ID, INT_ID> &current_slot =
        this->search_structure_[i];
      ACE_UINT32 position_of_current_slot = i;

      // Move <i> to next occupied slot.
      i = current_slot.next ();

#if defined (ACE_HAS_LAZY_MAP_MANAGER)
      if (current_slot.free_)
        continue;
#endif /* ACE_HAS_LAZY_MAP_MANAGER */

      this->unbind_slot (position_of_current_slot);
    }
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find_i (const EXT_ID &ext_id,
                                                   INT_ID &int_id)
{
  // Try to find the key.
  ACE_UINT32 slot = 0;
  int result = this->find_and_return_index (ext_id,
                                            slot);
  if (result == 0)
    // Key was found.  Make a copy of value.
    int_id = this->search_structure_[slot].int_id_;

  return result;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_and_return_index (const EXT_ID &ext_id,
                                                                    ACE_UINT32 &slot)
{
  // Try to find the key.
  int result = this->find_and_return_index (ext_id,
                                            slot);

  if (result == 0)
    this->unbind_slot (slot);

  return result;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_slot (ACE_UINT32 slot)
{

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  //
  // In the case of lazy map managers, the movement of free slots
  // from the occupied list to the free list is delayed until we
  // run out of free slots in the free list.
  //

  this->search_structure_[slot].free_ = true;

#else

  // Move from occupied list to free list.
  this->move_from_occupied_list_to_free_list (slot);

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  // Update the current size.
  --this->cur_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i (const EXT_ID &ext_id,
                                                     INT_ID &int_id)
{
  // Unbind the entry.
  ACE_UINT32 slot = 0;
  int result = this->unbind_and_return_index (ext_id,
                                              slot);
  if (result == 0)
    // If found, copy the value.
    int_id = this->search_structure_[slot].int_id_;

  return result;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::resize_i (ACE_UINT32 new_size)
{
  ACE_UINT32 i;
  ENTRY *temp = 0;

  // Allocate new memory.
  ACE_ALLOCATOR_RETURN (temp,
                        (ENTRY *) this->allocator_->malloc (new_size * sizeof (ENTRY)),
                        -1);

  // Copy over the occupied entires.
  for (i = this->occupied_list_.next ();
       i != this->occupied_list_id ();
       i = this->search_structure_[i].next ())
    // Call the copy constructor using operator placement new.
    new (&(temp[i])) ENTRY (this->search_structure_[i]);

  // Copy over the free entires.
  for (i = this->free_list_.next ();
       i != this->free_list_id ();
       i = this->search_structure_[i].next ())
    // Call the copy constructor using operator placement new.
    new (&(temp[i])) ENTRY (this->search_structure_[i]);

  // Construct the new elements.
  for (i = this->total_size_; i < new_size; i++)
    {
      // Call the constructor for each element in the array using
      // operator placement new.  Note that this requires a default
      // constructor for <EXT_ID> and <INT_ID>.
      new (&(temp[i])) ENTRY;
      temp[i].next (i + 1);
      temp[i].prev (i - 1);

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

      // Even though this slot is initially free, we need the <free_>
      // flag to be zero so that we don't have to set it when the slot
      // is moved to the occupied list.  In addition, this flag has no
      // meaning while this slot is in the free list.
      temp[i].free_ = false;

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

    }

  // Add new entries to the free list.
  this->free_list_.next (this->total_size_);
  this->free_list_.prev (new_size - 1);
  temp[new_size - 1].next (this->free_list_id ());
  temp[this->total_size_].prev (this->free_list_id ());

  // Remove/free old elements, update the new totoal size.
  this->free_search_structure ();
  this->total_size_ = new_size;

  // Start using new elements.
  this->search_structure_ = temp;

  return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_UINT32
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::new_size (void)
{
  // Calculate the new size.
  ACE_UINT32 current_size = this->total_size_;

  if (current_size < MAX_EXPONENTIAL)
    // Exponentially increase if we haven't reached MAX_EXPONENTIAL.
    current_size *= 2;
  else
    // Linear increase if we have reached MAX_EXPONENTIAL.
    current_size += LINEAR_INCREASE;

  // This should be the new size.
  return current_size;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::free_search_structure (void)
{
  // Free up the structure.
  if (this->search_structure_ != 0)
    {
      for (ACE_UINT32 i = 0; i < this->total_size_; i++)
        // Explicitly call the destructor.
        {
          ENTRY *ss = &this->search_structure_[i];
          // The "if" second argument results in a no-op instead of
          // deallocation.
          ACE_DES_FREE_TEMPLATE2 (ss, ACE_NOOP,
                                  ACE_Map_Entry, EXT_ID, INT_ID);
        }

      // Actually free the memory.
      this->allocator_->free (this->search_structure_);
      this->search_structure_ = 0;
    }
}

template <class EXT_ID, class INT_ID> void
ACE_Map_Entry<EXT_ID, INT_ID>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %d"), this->next_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("prev_ = %d"), this->prev_));

#if defined (ACE_HAS_LAZY_MAP_MANAGER)
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("free_ = %d"), this->free_));
#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("total_size_ = %d"), this->total_size_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ncur_size_ = %d"), this->cur_size_));
  this->allocator_->dump ();
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::dump_i (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %d"), this->next_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::dump_i (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %d"), this->next_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Entry<EXT_ID, INT_ID>&
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator* (void) const
{
  // @@ This function should be inlined.  We moved it here to avoid a
  // compiler bug in SunCC 4.2.  Once we know the correct patch to fix
  // the compiler problem, it should be moved back to .i file again.
  ACE_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Map_Entry<EXT_ID, INT_ID>&
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator* (void) const
{
  // @@ This function should be inlined.  We moved it here to avoid a
  // compiler bug in SunCC 4.2.  Once we know the correct patch to fix
  // the compiler problem, it should be moved back to .i file again.
  ACE_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> void
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_MAP_MANAGER_CPP */

