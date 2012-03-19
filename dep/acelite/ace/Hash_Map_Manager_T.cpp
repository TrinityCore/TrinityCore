
//=============================================================================
/**
 *  @file    Hash_Map_Manager_T.cpp
 *
 *  $Id: Hash_Map_Manager_T.cpp 84477 2009-02-16 13:30:38Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cse.wustl.edu>
 */
//=============================================================================


#ifndef ACE_HASH_MAP_MANAGER_T_CPP
#define ACE_HASH_MAP_MANAGER_T_CPP

#include "ace/Hash_Map_Manager_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
# include "ace/Hash_Map_Manager_T.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Malloc_Base.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class EXT_ID, class INT_ID>
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::ACE_Hash_Map_Entry (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *next,
                                                        ACE_Hash_Map_Entry<EXT_ID, INT_ID> *prev)
  : next_ (next),
    prev_ (prev)
{
}

template <class EXT_ID, class INT_ID>
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::ACE_Hash_Map_Entry (const EXT_ID &ext_id,
                                                        const INT_ID &int_id,
                                                        ACE_Hash_Map_Entry<EXT_ID, INT_ID> *next,
                                                        ACE_Hash_Map_Entry<EXT_ID, INT_ID> *prev)
  : ext_id_ (ext_id),
    int_id_ (int_id),
    next_ (next),
    prev_ (prev)
{
}

template <class EXT_ID, class INT_ID>
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::~ACE_Hash_Map_Entry (void)
{
}

template <class EXT_ID, class INT_ID> EXT_ID &
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::key ()
{
  return ext_id_;
}

template <class EXT_ID, class INT_ID> const EXT_ID &
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::key () const
{
  return ext_id_;
}

template <class EXT_ID, class INT_ID> INT_ID &
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::item ()
{
  return int_id_;
}

template <class EXT_ID, class INT_ID> const INT_ID &
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::item () const
{
  return int_id_;
}

template <class EXT_ID, class INT_ID> void
ACE_Hash_Map_Entry<EXT_ID, INT_ID>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %d"), this->next_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("prev_ = %d"), this->prev_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> void
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("total_size_ = %d\n"), this->total_size_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("cur_size_ = %d\n"), this->cur_size_));
  this->table_allocator_->dump ();
  this->entry_allocator_->dump ();
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::create_buckets (size_t size)
{
  size_t bytes = size * sizeof (ACE_Hash_Map_Entry<EXT_ID, INT_ID>);
  void *ptr = 0;

  ACE_ALLOCATOR_RETURN (ptr,
                        this->table_allocator_->malloc (bytes),
                        -1);

  this->table_ = (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *) ptr;

  this->total_size_ = size;

  // Initialize each entry in the hash table to be a circular linked
  // list with the dummy node in the front serving as the anchor of
  // the list.
  for (size_t i = 0; i < size; i++)
    new (&this->table_[i]) ACE_Hash_Map_Entry<EXT_ID, INT_ID> (&this->table_[i],
                                                               &this->table_[i]);
  return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::open (size_t size,
                                                                                 ACE_Allocator *table_alloc,
                                                                                 ACE_Allocator *entry_alloc)
{
  ACE_WRITE_GUARD_RETURN (ACE_LOCK, ace_mon, this->lock_, -1);

  // Calling this->close_i () to ensure we release previous allocated
  // memory before allocating new one.
  this->close_i ();

  if (table_alloc == 0)
    table_alloc = ACE_Allocator::instance ();

  this->table_allocator_ = table_alloc;

  if (entry_alloc == 0)
    entry_alloc = table_alloc;

  this->entry_allocator_ = entry_alloc;

  // This assertion is here to help track a situation that shouldn't
  // happen, but did with Sun C++ 4.1 (before a change to this class
  // was made: it used to have an enum that was supposed to be defined
  // to be ACE_DEFAULT_MAP_SIZE, but instead was defined to be 0).
  if (size == 0)
    return -1;

  return this->create_buckets (size);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::close_i (void)
{
  // Protect against "double-deletion" in case the destructor also
  // gets called.
  if (this->table_ != 0)
    {
      // Remove all the entries.
      this->unbind_all_i ();

      // Iterate through the buckets cleaning up the sentinels.
      for (size_t i = 0; i < this->total_size_; i++)
        {
          // Destroy the dummy entry.
          ACE_Hash_Map_Entry<EXT_ID, INT_ID> *entry = &this->table_[i];

          // The second argument results in a no-op instead of
          // deallocation.
          ACE_DES_FREE_TEMPLATE2 (entry, ACE_NOOP,
                                  ACE_Hash_Map_Entry, EXT_ID, INT_ID);
        }

      // Reset size.
      this->total_size_ = 0;

      // Free table memory.
      this->table_allocator_->free (this->table_);

      // Should be done last...
      this->table_ = 0;
    }

  return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind_all_i (void)
{
  // Iterate through the entire map calling the destuctor of each
  // <ACE_Hash_Map_Entry>.
  for (size_t i = 0; i < this->total_size_; i++)
    {
      for (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *temp_ptr = this->table_[i].next_;
           temp_ptr != &this->table_[i];
           )
        {
          ACE_Hash_Map_Entry<EXT_ID, INT_ID> *hold_ptr = temp_ptr;
          temp_ptr = temp_ptr->next_;

          // Explicitly call the destructor.
          ACE_DES_FREE_TEMPLATE2 (hold_ptr, this->entry_allocator_->free,
                                  ACE_Hash_Map_Entry, EXT_ID, INT_ID);
        }

      // Restore the sentinel.
      this->table_[i].next_ = &this->table_[i];
      this->table_[i].prev_ = &this->table_[i];
    }

  this->cur_size_ = 0;

  return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::bind_i (const EXT_ID &ext_id,
                                                                                   const INT_ID &int_id,
                                                                                   ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t loc = 0;
  if (this->shared_find (ext_id, entry, loc) == -1)
    {
      void *ptr = 0;
      // Not found.
      ACE_ALLOCATOR_RETURN (ptr,
                            this->entry_allocator_->malloc (sizeof (ACE_Hash_Map_Entry<EXT_ID, INT_ID>)),
                            -1);

      entry = new (ptr) ACE_Hash_Map_Entry<EXT_ID, INT_ID> (ext_id,
                                                            int_id,
                                                            this->table_[loc].next_,
                                                            &this->table_[loc]);
      this->table_[loc].next_ = entry;
      entry->next_->prev_ = entry;
      ++this->cur_size_;
      return 0;
    }
  else
    return 1;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::trybind_i (const EXT_ID &ext_id,
                                                                                      INT_ID &int_id,
                                                                                      ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t loc = 0;
  if (this->shared_find (ext_id, entry, loc) == -1)
    {
      // Not found.
      void *ptr = 0;
      ACE_ALLOCATOR_RETURN (ptr,
                            this->entry_allocator_->malloc (sizeof (ACE_Hash_Map_Entry<EXT_ID, INT_ID>)),
                            -1);

      entry = new (ptr) ACE_Hash_Map_Entry<EXT_ID, INT_ID> (ext_id,
                                                            int_id,
                                                            this->table_[loc].next_,
                                                            &this->table_[loc]);
      this->table_[loc].next_ = entry;
      entry->next_->prev_ = entry;
      ++this->cur_size_;
      return 0;
    }
  else
    return 1;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind_i (const EXT_ID &ext_id,
                                                                                     INT_ID &int_id)
{
  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *temp;

  size_t loc = 0;
  if (this->shared_find (ext_id, temp, loc) == -1)
    {
      errno = ENOENT;
      return -1;
    }

  int_id = temp->int_id_;

  return this->unbind_i (temp);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::unbind_i (ACE_Hash_Map_Entry<EXT_ID, INT_ID> *entry)
{
  entry->next_->prev_ = entry->prev_;
  entry->prev_->next_ = entry->next_;

  // Explicitly call the destructor.
  ACE_DES_FREE_TEMPLATE2 (entry, this->entry_allocator_->free,
                          ACE_Hash_Map_Entry, EXT_ID, INT_ID);

  --this->cur_size_;
  return 0;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::shared_find (const EXT_ID &ext_id,
                                                                                        ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry,
                                                                                        size_t &loc)
{
  if (this->total_size_ == 0)
    {
      errno = ENOENT;
      return -1;
    }

  loc = this->hash (ext_id) % this->total_size_;

  ACE_Hash_Map_Entry<EXT_ID, INT_ID> *temp = this->table_[loc].next_;

  while (temp != &this->table_[loc] && this->equal (temp->ext_id_, ext_id) == 0)
    temp = temp->next_;

  if (temp == &this->table_[loc])
    {
      errno = ENOENT;
      return -1;
    }
  else
    {
      entry = temp;
      return 0;
    }
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id,
                                                                                     ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t dummy = 0;
  if (this->shared_find (ext_id, entry, dummy) == -1)
    return this->bind_i (ext_id, int_id);
  else
    {
      entry->ext_id_ = ext_id;
      entry->int_id_ = int_id;
      return 1;
    }
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id,
                                                                                     INT_ID &old_int_id,
                                                                                     ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t dummy = 0;
  if (this->shared_find (ext_id, entry, dummy) == -1)
    return this->bind_i (ext_id, int_id);
  else
    {
      old_int_id = entry->int_id_;
      entry->ext_id_ = ext_id;
      entry->int_id_ = int_id;
      return 1;
    }
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Manager_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::rebind_i (const EXT_ID &ext_id,
                                                                                     const INT_ID &int_id,
                                                                                     EXT_ID &old_ext_id,
                                                                                     INT_ID &old_int_id,
                                                                                     ACE_Hash_Map_Entry<EXT_ID, INT_ID> *&entry)
{
  size_t dummy = 0;
  if (this->shared_find (ext_id, entry, dummy) == -1)
    return this->bind_i (ext_id, int_id);
  else
    {
      old_ext_id = entry->ext_id_;
      old_int_id = entry->int_id_;
      entry->ext_id_ = ext_id;
      entry->int_id_ = int_id;
      return 1;
    }
}

// ------------------------------------------------------------

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Iterator_Base_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> void
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump_i (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump_i");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("index_ = %d "), this->index_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %x"), this->next_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i");

  if (this->map_man_->table_ == 0)
    return -1;
  // Handle initial case specially.
  else if (this->index_ == -1)
    {
      this->index_++;
      return this->forward_i ();
    }
  else if (this->index_ >= static_cast<ssize_t> (this->map_man_->total_size_))
    return 0;

  this->next_ = this->next_->next_;
  if (this->next_ == &this->map_man_->table_[this->index_])
    {
      while (++this->index_ < static_cast<ssize_t> (this->map_man_->total_size_))
        {
          this->next_ = this->map_man_->table_[this->index_].next_;
          if (this->next_ != &this->map_man_->table_[this->index_])
            break;
        }
    }

  return this->index_ < static_cast<ssize_t> (this->map_man_->total_size_);
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i");

  if (this->map_man_->table_ == 0)
    return -1;
  else if (this->index_ == static_cast<ssize_t> (this->map_man_->total_size_))
    {
      --this->index_;
      return this->reverse_i ();
    }
  else if (this->index_ < 0)
    return 0;

  this->next_ = this->next_->prev_;
  if (this->next_ == &this->map_man_->table_[this->index_])
    {
      while (--this->index_ >= 0)
        {
          this->next_ = this->map_man_->table_[this->index_].prev_;
          if (this->next_ != &this->map_man_->table_[this->index_])
            break;
        }
    }

  return this->index_ >= 0;
}

// ------------------------------------------------------------

ACE_ALLOC_HOOK_DEFINE(ACE_Hash_Map_Const_Iterator_Base_Ex)

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> void
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump_i (void) const
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::dump_i");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("index_ = %d "), this->index_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("next_ = %x"), this->next_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::forward_i");

  if (this->map_man_->table_ == 0)
    return -1;
  // Handle initial case specially.
  else if (this->index_ == -1)
    {
      ++this->index_;
      return this->forward_i ();
    }
  else if (this->index_ >= (ssize_t) this->map_man_->total_size_)
    return 0;

  this->next_ = this->next_->next_;
  if (this->next_ == &this->map_man_->table_[this->index_])
    {
      while (++this->index_ < (ssize_t) this->map_man_->total_size_)
        {
          this->next_ = this->map_man_->table_[this->index_].next_;
          if (this->next_ != &this->map_man_->table_[this->index_])
            break;
        }
    }

  return this->index_ < (ssize_t) this->map_man_->total_size_;
}

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK> int
ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i (void)
{
  ACE_TRACE ("ACE_Hash_Map_Const_Iterator_Base_Ex<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>::reverse_i");

  if (this->map_man_->table_ == 0)
    return -1;
  else if (this->index_ == (ssize_t) this->map_man_->total_size_)
    {
      --this->index_;
      return this->reverse_i ();
    }
  else if (this->index_ < 0)
    return 0;

  this->next_ = this->next_->prev_;
  if (this->next_ == &this->map_man_->table_[this->index_])
    {
      while (--this->index_ >= 0)
        {
          this->next_ = this->map_man_->table_[this->index_].prev_;
          if (this->next_ != &this->map_man_->table_[this->index_])
            break;
        }
    }

  return this->index_ >= 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HASH_MAP_MANAGER_T_CPP */
