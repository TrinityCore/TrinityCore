// -*- C++ -*-
//
// $Id: Map_Manager.inl 91809 2010-09-17 07:20:41Z johnnyw $

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class EXT_ID, class INT_ID> ACE_INLINE
ACE_Map_Entry<EXT_ID, INT_ID>::ACE_Map_Entry (void)
  : next_ (0),
    prev_ (0)
#if defined (ACE_HAS_LAZY_MAP_MANAGER)
    , free_ (1)
#endif /* ACE_HAS_LAZY_MAP_MANAGER */
{
}

template <class EXT_ID, class INT_ID> ACE_INLINE
ACE_Map_Entry<EXT_ID, INT_ID>::~ACE_Map_Entry (void)
{
  // No-op just to keep some compilers happy...
}

template <class EXT_ID, class INT_ID> ACE_INLINE ACE_UINT32
ACE_Map_Entry<EXT_ID, INT_ID>::next (void) const
{
  return this->next_;
}

template <class EXT_ID, class INT_ID> ACE_INLINE void
ACE_Map_Entry<EXT_ID, INT_ID>::next (ACE_UINT32 n)
{
  this->next_ = n;
}

template <class EXT_ID, class INT_ID> ACE_INLINE ACE_UINT32
ACE_Map_Entry<EXT_ID, INT_ID>::prev (void) const
{
  return this->prev_;
}

template <class EXT_ID, class INT_ID> ACE_INLINE void
ACE_Map_Entry<EXT_ID, INT_ID>::prev (ACE_UINT32 p)
{
  this->prev_ = p;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager (size_t size,
                                                            ACE_Allocator *alloc)
  : allocator_ (0),
    search_structure_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  if (this->open (size, alloc) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("ACE_Map_Manager\n")));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Manager (ACE_Allocator *alloc)
  : allocator_ (0),
    search_structure_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  if (this->open (ACE_DEFAULT_MAP_SIZE, alloc) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("ACE_Map_Manager\n")));
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::close (void)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->close_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::~ACE_Map_Manager (void)
{
  this->close ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                 const INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->bind_i (ext_id,
                       int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                   const INT_ID &int_id,
                                                   EXT_ID &old_ext_id,
                                                   INT_ID &old_int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id,
                         int_id,
                         old_ext_id,
                         old_int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                   const INT_ID &int_id,
                                                   INT_ID &old_int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id,
                         int_id,
                         old_int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                   const INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id,
                         int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                    INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->trybind_i (ext_id,
                          int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find (const EXT_ID &ext_id) const
{
  ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> *nc_this =
    (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> *) this;
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, nc_this->lock_, -1);

  ACE_UINT32 slot = 0;
  return nc_this->find_and_return_index (ext_id, slot);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                 INT_ID &int_id) const
{
  ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> *nc_this =
    (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> *) this;
  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, nc_this->lock_, -1);

  return nc_this->find_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind_i (const EXT_ID &ext_id)
{
  // Unbind the entry.
  ACE_UINT32 slot = 0;
  return this->unbind_and_return_index (ext_id,
                                        slot);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind (const EXT_ID &ext_id,
                                                   INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_i (ext_id,
                         int_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::unbind (const EXT_ID &ext_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);
  return this->unbind_i (ext_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE size_t
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::current_size (void) const
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, static_cast<size_t> (-1));
  return this->cur_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE size_t
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::total_size (void) const
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, static_cast<size_t> (-1));
  return this->total_size_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE ACE_LOCK &
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::mutex (void)
{
  return this->lock_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::move_from_free_list_to_occupied_list (ACE_UINT32 slot)
{
  this->shared_move (slot,
                     this->free_list_,
                     this->free_list_id (),
                     this->occupied_list_,
                     this->occupied_list_id ());
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE void
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::move_from_occupied_list_to_free_list (ACE_UINT32 slot)
{
  this->shared_move (slot,
                     this->occupied_list_,
                     this->occupied_list_id (),
                     this->free_list_,
                     this->free_list_id ());
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::equal (const EXT_ID &id1,
                                                  const EXT_ID &id2)
{
  return id1 == id2;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE ACE_UINT32
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::free_list_id (void) const
{
  // If you change ~0, please change
  // ACE_Active_Map_Manager_Key::ACE_Active_Map_Manager_Key()
  // accordingly.
  return (ACE_UINT32) ~0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE ACE_UINT32
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::occupied_list_id (void) const
{
  return (ACE_UINT32) ~1;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::begin (void)
{
  return ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::end (void)
{
  return ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this, 1);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rbegin (void)
{
  return ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::rend (void)
{
  return ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> (*this, 1);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator_Base (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm)
  : map_man_ (&mm),
    next_ (map_man_->occupied_list_id ())
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::next (ACE_Map_Entry<EXT_ID, INT_ID> *&mm) const
{
  if (this->next_ != this->map_man_->occupied_list_id ())
    {
      mm = &this->map_man_->search_structure_[this->next_];
      return 1;
    }
  else
    return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::done (void) const
{
  return this->next_ == this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::forward_i (void)
{

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  while (1)
    {
      // Go to the next item in the list.
      this->next_ = this->map_man_->search_structure_[this->next_].next ();

      // Stop if we reach the end.
      if (this->done ())
        break;

      // Break if we find a non-free slot.
      if (!this->map_man_->search_structure_[this->next_].free_)
        {
          break;
        }
    }

#else

  this->next_ = this->map_man_->search_structure_[this->next_].next ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  return this->next_ != this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::reverse_i (void)
{

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  while (1)
    {
      // Go to the prev item in the list.
      this->next_ = this->map_man_->search_structure_[this->next_].prev ();

      // Stop if we reach the end.
      if (this->done ())
        break;

      // Break if we find a non-free slot.
      if (!this->map_man_->search_structure_[this->next_].free_)
        {
          break;
        }
    }

#else

  this->next_ = this->map_man_->search_structure_[this->next_].prev ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  return this->next_ != this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::map (void)
{
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE bool
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator== (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  return (this->map_man_ == rhs.map_man_ &&
          this->next_ == rhs.next_);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE bool
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator!= (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  return !this->operator== (rhs);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Const_Iterator_Base (const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm)
  : map_man_ (&mm),
    next_ (this->map_man_->occupied_list_id ())
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::next (ACE_Map_Entry<EXT_ID, INT_ID> *&mm) const
{
  if (this->next_ != this->map_man_->occupied_list_id ())
    {
      mm = &this->map_man_->search_structure_[this->next_];
      return 1;
    }
  else
    return 0;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::done (void) const
{
  return this->next_ == this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::forward_i (void)
{

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  while (1)
    {
      // Go to the next item in the list.
      this->next_ = this->map_man_->search_structure_[this->next_].next ();

      // Stop if we reach the end.
      if (this->done ())
        break;

      // Break if we find a non-free slot.
      if (!this->map_man_->search_structure_[this->next_].free_)
        {
          break;
        }
    }

#else

  this->next_ = this->map_man_->search_structure_[this->next_].next ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  return this->next_ != this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::reverse_i (void)
{

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  while (1)
    {
      // Go to the prev item in the list.
      this->next_ = this->map_man_->search_structure_[this->next_].prev ();

      // Stop if we reach the end.
      if (this->done ())
        break;

      // Break if we find a non-free slot.
      if (!this->map_man_->search_structure_[this->next_].free_)
        {
          break;
        }
    }

#else

  this->next_ = this->map_man_->search_structure_[this->next_].prev ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  return this->next_ != this->map_man_->occupied_list_id ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::map (void) const
{
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE bool
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator== (const ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  return (this->map_man_ == rhs.map_man_ &&
          this->next_ == rhs.next_);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE bool
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator!= (const ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &rhs) const
{
  return !this->operator== (rhs);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Iterator (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                              int pass_end)
  : ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> (mm)
{
  if (!pass_end)
    {

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

      // Start here.
      this->next_ = this->map_man_->occupied_list_.next ();

      while (1)
        {
          // Stop if we reach the end.
          if (this->done ())
            break;

          // Break if we find a non-free slot.
          if (!this->map_man_->search_structure_[this->next_].free_)
            {
              break;
            }

          // Go to the next item in the list.
          this->next_ = this->map_man_->search_structure_[this->next_].next ();
        }

#else

      this->next_ = this->map_man_->occupied_list_.next ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

    }
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance (void)
{
  return this->forward_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)
{
  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)
{
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)
{
  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)
{
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Const_Iterator (const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                                          int pass_end)
  : ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> (mm)
{
  if (!pass_end)
    {

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

      // Start here.
      this->next_ = this->map_man_->occupied_list_.next ();

      while (1)
        {
          // Stop if we reach the end.
          if (this->done ())
            break;

          // Break if we find a non-free slot.
          if (!this->map_man_->search_structure_[this->next_].free_)
            {
              break;
            }

          // Go to the next item in the list.
          this->next_ = this->map_man_->search_structure_[this->next_].next ();
        }

#else

      this->next_ = this->map_man_->occupied_list_.next ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

    }
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance (void)
{
  return this->forward_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)
{
  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)
{
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)
{
  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)
{
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Map_Reverse_Iterator (ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                                              int pass_end)
  : ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> (mm)
{
  if (!pass_end)
    {

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

      // Start here.
      this->next_ = this->map_man_->occupied_list_.prev ();

      while (1)
        {
          // Stop if we reach the end.
          if (this->done ())
            break;

          // Break if we find a non-free slot.
          if (!this->map_man_->search_structure_[this->next_].free_)
            {
              break;
            }

          // Go to the prev item in the list.
          this->next_ = this->map_man_->search_structure_[this->next_].prev ();
        }

#else

      this->next_ = this->map_man_->occupied_list_.prev ();

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

}
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE int
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::advance (void)
{
  return this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (void)
{
  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator++ (int)
{
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (void)
{
  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>
ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator-- (int)
{
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Entry<EXT_ID, INT_ID>&
ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator* (void) const
{
  ACE_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int const result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_INLINE
ACE_Map_Entry<EXT_ID, INT_ID>&
ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>::operator* (void) const
{
  ACE_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int const result = this->next (retv);
  ACE_ASSERT (result != 0);
  ACE_UNUSED_ARG (result);

  return *retv;
}


ACE_END_VERSIONED_NAMESPACE_DECL
