// -*- C++ -*-
//
// $Id: Hash_Map_Manager_T.inl 84477 2009-02-16 13:30:38Z johnnyw $

#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Manager_Ex (size_t size,
                                                                                                    ACE_Allocator *table_alloc,
                                                                                                    ACE_Allocator *entry_alloc)
  : table_allocator_ (table_alloc),
    entry_allocator_ (entry_alloc),
    table_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  if (this->open (size, table_alloc, entry_alloc) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("ACE_Hash_Map_Manager_Ex\n")));
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Manager_Ex (ACE_Allocator *table_alloc,
                                                                                                    ACE_Allocator *entry_alloc)
  : table_allocator_ (table_alloc),
    entry_allocator_ (entry_alloc),
    table_ (0),
    total_size_ (0),
    cur_size_ (0)
{
  if (this->open (ACE_DEFAULT_MAP_SIZE, table_alloc, entry_alloc) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Hash_Map_Manager_Ex open")));
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::close (void)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->close_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind_all (void)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_all_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::~ACE_Hash_Map_Manager_Ex (void)
{
  this->close ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE size_t
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::current_size (void) const
{
  return this->cur_size_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE size_t
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::total_size (void) const
{
  return this->total_size_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE ACE_LOCK &
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::mutex (void)
{
  ACE_TRACE ("ACE_Hash_Map_Manager_Ex::mutex");
  return this->lock_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE u_long
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::hash (const EXT_ID &ext_id)
{
  return this->hash_key_ (ext_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::equal (const EXT_ID &id1,
                                                                                  const EXT_ID &id2)
{
  return this->compare_keys_ (id1, id2);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::bind_i (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *temp;

  return this->bind_i (ext_id, int_id, temp);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                                                 const INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->bind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::bind (const EXT_ID &ext_id,
                                                                                 const INT_ID &int_id,
                                                                                 ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->bind_i (ext_id, int_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::trybind_i (const EXT_ID &ext_id,
                                                                                      INT_ID &int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *temp;

  int result = this->trybind_i (ext_id, int_id, temp);
  if (result == 1)
    int_id = temp->int_id_;
  return result;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                                                    INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->trybind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::trybind (const EXT_ID &ext_id,
                                                                                    INT_ID &int_id,
                                                                                    ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->trybind_i (ext_id, int_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind_i (const EXT_ID &ext_id)
{
  INT_ID int_id;

  return this->unbind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind (const EXT_ID &ext_id,
                                                                                   INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_i (ext_id, int_id);
}

template <class EXT_ID,
          class INT_ID,
          class HASH_KEY,
          class COMPARE_KEYS,
          class ACE_LOCK>
ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID,
                        INT_ID,
                        HASH_KEY,
                        COMPARE_KEYS,
                        ACE_LOCK>::unbind (
  typename ACE_Hash_Map_Manager_Ex<EXT_ID,
                                   INT_ID,
                                   HASH_KEY,
                                   COMPARE_KEYS,
                                   ACE_LOCK>::iterator pos)
{
  return this->unbind (&(*pos));
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind (const EXT_ID &ext_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_i (ext_id) == -1 ? -1 : 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->unbind_i (entry) == -1 ? -1 : 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find_i (const EXT_ID &ext_id,
                                                                                   INT_ID &int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *entry;

  size_t dummy;
  if (this->shared_find (ext_id, entry, dummy) == -1)
    return -1;
  else
    {
      int_id = entry->int_id_;
      return 0;
    }
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find_i (const EXT_ID &ext_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *entry;

  size_t dummy;
  return this->shared_find (ext_id, entry, dummy);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                                                 INT_ID &int_id) const
{
  ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *nc_this =
    const_cast <ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *>
    (this);

  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return nc_this->find_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &ext_id) const
{
  ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *nc_this =
    const_cast <ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *>
    (this);

  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return nc_this->find_i (ext_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find_i (const EXT_ID &ext_id,
                                                                                   ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t dummy;
  return this->shared_find (ext_id, entry, dummy);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::find (const EXT_ID &ext_id,
                                                                                 ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry) const
{
  ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *nc_this =
    const_cast <ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *>
    (this);

  ACE_READ_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return nc_this->find_i (ext_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *node;

  return this->rebind_i (ext_id,
                         int_id,
                         node);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id,
                                                                                     INT_ID &old_int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *node;

  return this->rebind_i (ext_id,
                         int_id,
                         old_int_id,
                         node);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id,
                                                                                     EXT_ID &old_ext_id,
                                                                                     INT_ID &old_int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *node;

  return this->rebind_i (ext_id,
                         int_id,
                         old_ext_id,
                         old_int_id,
                         node);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   INT_ID &old_int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, old_int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   INT_ID &old_int_id,
                                                                                   ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, old_int_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   EXT_ID &old_ext_id,
                                                                                   INT_ID &old_int_id)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, old_ext_id, old_int_id);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   EXT_ID &old_ext_id,
                                                                                   INT_ID &old_int_id,
                                                                                   ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  return this->rebind_i (ext_id, int_id, old_ext_id, old_int_id, entry);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::begin (void)
{
  return iterator (*this);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::end (void)
{
  return iterator (*this, 1);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::const_iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::begin (void) const
{
  return const_iterator (*this);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::const_iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::end (void) const
{
  return const_iterator (*this, 1);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rbegin (void)
{
  return reverse_iterator (*this);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_iterator
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rend (void)
{
  return reverse_iterator (*this, 1);
}

 template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
 typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::const_reverse_iterator
 ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rbegin (void) const
 {
   return const_reverse_iterator (*this);
 }

 template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
 typename ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::const_reverse_iterator
 ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rend (void) const
 {
   return const_reverse_iterator (*this, 1);
 }

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> *
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::table (void)
{
  return this->table_;
}

template <class EXT_ID,
          class INT_ID,
          class HASH_KEY,
          class COMPARE_KEYS,
          class ACE_LOCK>
ACE_INLINE void
ACE_Hash_Map_Manager_Ex<EXT_ID,
                        INT_ID,
                        HASH_KEY,
                        COMPARE_KEYS,
                        ACE_LOCK>::find (
  EXT_ID const &ext_id,
  typename ACE_Hash_Map_Manager_Ex<EXT_ID,
                                   INT_ID,
                                   HASH_KEY,
                                   COMPARE_KEYS,
                                   ACE_LOCK>::iterator & pos) const
{
  ENTRY * entry = 0;
  size_t index = 0;

  ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *nc_this =
    const_cast <ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *>
    (this);

  ACE_READ_GUARD (ACE_LOCK, ace_mon, this->lock_);

  if (nc_this->shared_find (ext_id, entry, index) != -1)
    pos = iterator (*nc_this, entry, index);
  else
    pos = nc_this->end ();
}

// ---------------------------------------------------------------------

template <class EXT_ID,
          class INT_ID,
          class HASH_KEY,
          class COMPARE_KEYS,
          class ACE_LOCK>
ACE_INLINE
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID,
                              INT_ID,
                              HASH_KEY,
                              COMPARE_KEYS,
                              ACE_LOCK>::ACE_Hash_Map_Iterator_Base_Ex (
  ACE_Hash_Map_Manager_Ex<EXT_ID,
                          INT_ID,
                          HASH_KEY,
                          COMPARE_KEYS,
                          ACE_LOCK> &mm,
  bool head)
  : map_man_ (&mm),
    index_ (head ? -1 : (ssize_t) mm.total_size_),
    next_ (0)
{
  if (mm.table_ != 0)
    this->next_ = &mm.table_[head ? 0 : mm.total_size_ - 1];
}

template <class EXT_ID,
          class INT_ID,
          class HASH_KEY,
          class COMPARE_KEYS,
          class ACE_LOCK>
ACE_INLINE
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID,
                              INT_ID,
                              HASH_KEY,
                              COMPARE_KEYS,
                              ACE_LOCK>::ACE_Hash_Map_Iterator_Base_Ex (
  ACE_Hash_Map_Manager_Ex<EXT_ID,
                          INT_ID,
                          HASH_KEY,
                          COMPARE_KEYS,
                          ACE_LOCK> & mm,
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> * entry,
  size_t index)
  : map_man_ (&mm)
  , index_ (static_cast<ssize_t> (index))
  , next_ (entry)
{
}

template <class EXT_ID,
    class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::next (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::next");

  if (this->map_man_->table_ != 0
      && this->index_ < static_cast<ssize_t> (this->map_man_->total_size_)
      && this->index_ >= 0
      && this->next_ != &this->map_man_->table_[this->index_])
    {
      entry = this->next_;
      return 1;
    }
  else
    return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::done (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::done");

  return this->map_man_->table_ == 0
    || this->index_ >= static_cast<ssize_t> (this->map_man_->total_size_)
    || this->index_ < 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> &
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator* (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator*");
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);

  ACE_UNUSED_ARG (result);
  ACE_ASSERT (result != 0);

  return *retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> *
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-> (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator->");
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);

  ACE_UNUSED_ARG (result);
  ACE_ASSERT (result != 0);

  return retv;
}

// Returns the reference to the hash_map_manager_ex that is being
// iterated over.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>&
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map");
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator== (const ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator==");
  return this->map_man_ == rhs.map_man_
    && this->index_ == rhs.index_
    && this->next_ == rhs.next_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!= (const ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!=");
  return this->next_ != rhs.next_
    || this->index_ != rhs.index_
    || this->map_man_ != rhs.map_man_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Iterator_Base_Ex (const ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                                                                                                            bool head)
  : map_man_ (&mm),
    index_ (head ? -1 : (ssize_t) mm.total_size_),
    next_ (0)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Iterator_Base_Ex");

  if (mm.table_ != 0)
    this->next_ = &mm.table_[head ? 0 : mm.total_size_ - 1];
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::next (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::next");

  if (this->map_man_->table_ != 0
      && this->index_ < (ssize_t) this->map_man_->total_size_
      && this->index_ >= 0
      && this->next_ != &this->map_man_->table_[this->index_])
    {
      entry = this->next_;
      return 1;
    }
  else
    return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::done (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::done");

  return this->map_man_->table_ == 0
    || this->index_ >= (ssize_t) this->map_man_->total_size_
    || this->index_ < 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> &
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator* (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator*");
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);

  ACE_UNUSED_ARG (result);
  ACE_ASSERT (result != 0);

  return *retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> *
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-> (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator->");
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *retv = 0;

  int result = this->next (retv);

  ACE_UNUSED_ARG (result);
  ACE_ASSERT (result != 0);

  return retv;
}

// Returns the reference to the hash_map_manager_ex that is being
// iterated over.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
const ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>&
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map");
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator== (const ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator==");
  return this->map_man_ == rhs.map_man_
    && this->index_ == rhs.index_
    && this->next_ == rhs.next_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!= (const ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!=");
  return this->next_ != rhs.next_
    || this->index_ != rhs.index_
    || this->map_man_ != rhs.map_man_;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Iterator_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE void
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Iterator_Ex (ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                                                                                      int tail)
  : ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> (mm,
                                                                                     tail == 0 ? 1 : 0)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Iterator_Ex");
  if (tail == 0)
    this->forward_i ();
}

template <class EXT_ID,
          class INT_ID,
          class HASH_KEY,
          class COMPARE_KEYS,
          class ACE_LOCK>
ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID,
                         INT_ID,
                         HASH_KEY,
                         COMPARE_KEYS,
                         ACE_LOCK>::ACE_Hash_Map_Iterator_Ex (
  ACE_Hash_Map_Manager_Ex<EXT_ID,
                          INT_ID,
                          HASH_KEY,
                          COMPARE_KEYS,
                          ACE_LOCK> & mm,
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> * entry,
  size_t index)
  : ACE_Hash_Map_Iterator_Base_Ex<EXT_ID,
                                  INT_ID,
                                  HASH_KEY,
                                  COMPARE_KEYS,
                                  ACE_LOCK> (mm,
                                             entry,
                                             index)
{
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance");
  return this->forward_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Const_Iterator_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE void
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Iterator_Ex (const ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                                                                                                  int tail)
  : ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> (mm,
                                                                                           tail == 0 ? 1 : 0)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Iterator_Ex");
  if (tail == 0)
    this->forward_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance");
  return this->forward_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Bucket_Iterator (ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                                                                                              const EXT_ID &ext_id,
                                                                                                              int tail)
  : map_man_ (&mm)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Bucket_Iterator");

  this->index_ = this->map_man_->hash (ext_id) % this->map_man_->total_size_;
  this->next_ = &this->map_man_->table_[this->index_];

  if (tail == 0)
    this->forward_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i");

  this->next_ = this->next_->next_;
  return this->next_ != &this->map_man_->table_[this->index_];
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i");

  this->next_ = this->next_->prev_;
  return this->next_ != &this->map_man_->table_[this->index_];
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> &
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator* (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator*");

  return *this->next_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Entry<EXT_ID, INT_ID> *
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-> (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator->");

  return this->next_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map (void)
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::map");
  return *this->map_man_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator== (const ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator==");
  return this->map_man_ == rhs.map_man_
    && this->index_ == rhs.index_
    && this->next_ == rhs.next_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE bool
ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!= (const ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &rhs) const
{
  ACE_TRACE ("ACE_Hash_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator!=");
  return this->next_ != rhs.next_
    || this->index_ != rhs.index_
    || this->map_man_ != rhs.map_man_;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Reverse_Iterator_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE void
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Reverse_Iterator_Ex (ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm, bool head)
  : ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> (mm, head)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Reverse_Iterator_Ex");
  if (!head)
    this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance");
  return this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Const_Reverse_Iterator_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE void
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump");

  this->dump_i ();
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Reverse_Iterator_Ex (const ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm, bool head)
  : ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> (mm, head)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::ACE_Hash_Map_Const_Reverse_Iterator_Ex");
  if (!head)
    this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE int
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::advance");
  return this->reverse_i ();
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (void)");

  this->reverse_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator++ (int)");

  ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  ++*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (void)");

  this->forward_i ();
  return *this;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> ACE_INLINE
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::operator-- (int)");

  ACE_Hash_Map_Const_Reverse_Iterator_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> retv (*this);
  --*this;
  return retv;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Manager (ACE_Allocator *table_alloc,
                                                                      ACE_Allocator *entry_alloc)
  : ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (table_alloc,
                                                                                               entry_alloc)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Manager (size_t size,
                                                                      ACE_Allocator *table_alloc,
                                                                      ACE_Allocator *entry_alloc)
  : ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (size,
                                                                                               table_alloc,
                                                                                               entry_alloc)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> int
ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::equal (const EXT_ID &id1, const EXT_ID &id2)
{
  return ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK>::equal (id1, id2);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> u_long
ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>::hash (const EXT_ID &ext_id)
{
  return ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK>::hash (ext_id);
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Iterator (ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                                        int tail)
  : ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (mm,
                                                                                                tail)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Iterator (const ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base)
  : ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (base)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_Hash_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Hash_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator= (const ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &rhs)
{
  if (this != &rhs)
  {
    ACE_Hash_Map_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base = *this;

    base = rhs;
  }

  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Const_Iterator (const ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                                                    int tail)
  : ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (mm,
                                                                                                      tail)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Const_Iterator (const ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base)
  : ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (base)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_Hash_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Hash_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator= (const ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &rhs)
{
  if (this != &rhs)
  {
    ACE_Hash_Map_Const_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base = *this;

    base = rhs;
  }

  return *this;
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Reverse_Iterator (ACE_Hash_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &mm,
                                                                                        bool head)
  : ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (mm,
                                                                                                        head)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK>
ACE_Hash_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::ACE_Hash_Map_Reverse_Iterator (const ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base)
  : ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> (base)
{
}

template <class EXT_ID, class INT_ID, class ACE_LOCK> ACE_Hash_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> &
ACE_Hash_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>::operator= (const ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &rhs)
{
  ACE_Hash_Map_Reverse_Iterator_Ex<EXT_ID, INT_ID, ACE_Hash<EXT_ID>, ACE_Equal_To<EXT_ID>, ACE_LOCK> &base = *this;

  base = rhs;

  return *this;
}

ACE_END_VERSIONED_NAMESPACE_DECL
