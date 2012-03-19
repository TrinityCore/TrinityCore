// -*- C++ -*-

//=============================================================================
/**
 * @file    Hash_Multi_Map_Manager_T.h
 *
 * $Id: Hash_Multi_Map_Manager_T.h 91693 2010-09-09 12:57:54Z johnnyw $
 *
 * The code in Hash_Multi_Map_Manager_T.* was based on the code in
 * Hash_Map_Manager_T.*.
 *
 * ACE_Hash_Multi_Map_Manager maps a key type to more than one value types.
 * The template takes the key and value types as parameters. The bind and
 * unbind operations can take a key and the value or the set of the values that
 * is to be associated with that key. The find operation can take a key or a
 * key and the value that is associated with the key.
 *
 * ACE_Hash_Multi_Map_Manager uses @c ACE_Unbounded_Set to store differet values
 * with the same key.
 *
 * @author Shanshan Jiang <shanshan.jiang@vanderbilt.edu>
 */
//=============================================================================

#ifndef ACE_HASH_MULTI_MAP_MANAGER_T_H
#define ACE_HASH_MULTI_MAP_MANAGER_T_H
#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Default_Constants.h"
#include "ace/Functor_T.h"
#include "ace/Log_Msg.h"

#include "ace/Unbounded_Set.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Hash_Multi_Map_Entry
 *
 * @brief Define an entry in the hash table.
 */
template <class EXT_ID, class INT_ID>
class ACE_Hash_Multi_Map_Entry
{
public:
  friend class ACE_Unbounded_Set<INT_ID>;

  typedef ACE_Unbounded_Set<INT_ID> VALUE_SET;
  typedef ACE_Unbounded_Set_Iterator<INT_ID> VALUE_SET_ITERATOR;

  // = Initialization and termination methods.
  /// Constructor.
  ACE_Hash_Multi_Map_Entry (const EXT_ID &ext_id,
                            const ACE_Unbounded_Set<INT_ID> &int_id_set,
                            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next = 0,
                            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *prev = 0);

  /// Constructor.
  ACE_Hash_Multi_Map_Entry (ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next,
                            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *prev);

  /// Destructor.
  ~ACE_Hash_Multi_Map_Entry (void);

  /// Key accessor.
  EXT_ID& key (void);

  /// Item accessor.
  ACE_Unbounded_Set<INT_ID>& item (void);

public:
  /// Key used to look up an entry.
  /// @todo Should be private
  EXT_ID ext_id_;

  /// The contents of the entry itself.
  /// @todo Should be private
  ACE_Unbounded_Set<INT_ID> int_id_set_;

  /// Pointer to the next item in the bucket of overflow nodes.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next_;

  /// Pointer to the prev item in the bucket of overflow nodes.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *prev_;

  /// Dump the state of an object.
  void dump (void) const;
};

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Iterator_Base;

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Const_Iterator_Base;

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Const_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Reverse_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Bucket_Iterator;

// Forward decl.
class ACE_Allocator;

/**
 * @class ACE_Hash_Multi_Map_Manager
 *
 * @brief Define a multi-map abstraction that efficiently associates the keys
 * with their different values.
 *
 * This implementation of a multi-map uses a hash table.  Key hashing
 * is achieved through the @c HASH_KEY object and key comparison is
 * achieved through the @c COMPARE_KEYS object.
 * This class uses an @c ACE_Allocator to allocate memory.  The
 * user can make this a persistent class by providing an
 * @c ACE_Allocator with a persistable memory pool.
 */

template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Manager
{
public:
  friend class ACE_Hash_Multi_Map_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_Hash_Multi_Map_Const_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;
  friend class ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>;

  typedef EXT_ID
          KEY;
  typedef INT_ID
          VALUE;
  typedef ACE_LOCK lock_type;
  typedef ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>
          ENTRY;

  // = ACE-style iterator typedefs.
  typedef ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          ITERATOR;
  typedef ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          CONST_ITERATOR;
  typedef ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          REVERSE_ITERATOR;

  // = STL-style iterator typedefs.
  typedef ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          iterator;
  typedef ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          const_iterator;
  typedef ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
          reverse_iterator;

  // = Initialization and termination methods.

  /**
   * Initialize a @c Hash_Multi_Map_Manager with default size elements.
   * @param table_alloc is a pointer to a memory allocator used for
   *        table_, so it should supply size*sizeof (
   *        ACE_Hash_Multi_Map_Entry<@c EXT_ID, @c INT_ID>).
   * @param entry_alloc is a pointer to an additional allocator for
   *        entries, so it should be able to allocate 'size' / chunks
   *        of sizeof (ACE_Hash_Multi_Map_Entry<@c EXT_ID, @c INT_ID>) bytes
   *        each.
   * If @a table_alloc is 0 it defaults to @c ACE_Allocator::instance().
   * If @a entry_alloc is 0 then it defaults to the same allocator as
   * @a table_alloc.
   */
  ACE_Hash_Multi_Map_Manager (ACE_Allocator *table_alloc = 0,
                              ACE_Allocator *entry_alloc = 0);

  /**
   * Initialize a @c Hash_Multi_Map_Manager with @a size elements.
   * @param size is the number of elements in a Hash_Multi_Map_Manager.
   * @param table_alloc is a pointer to a memory allocator used for
   *        table_, so it should supply size*sizeof (
   *        ACE_Hash_Multi_Map_Entry<@c EXT_ID, <@c INT_ID>).
   * @param entry_alloc is a pointer to an additional allocator for
   *        entries, so it should be able to allocate 'size' / chunks
   *        of sizeof (ACE_Hash_Multi_Map_Entry<@c EXT_ID, @c INT_ID>) bytes
   *        each.
   * If @a table_alloc is 0 it defaults to @c ACE_Allocator::instance().
   * If @a entry_alloc is 0 then it defaults to the same allocator as
   * @a table_alloc.
   */
  ACE_Hash_Multi_Map_Manager (size_t size,
                              ACE_Allocator *table_alloc = 0,
                              ACE_Allocator *entry_alloc = 0);

  /**
   * Initialize a @c Hash_Multi_Map_Manager with @a size elements.
   * @param size is the number of elements in a Hash_Multi_Map_Manager.
   * @param table_alloc is a pointer to a memory allocator used for
   *        table_, so it should supply size*sizeof
   *        (ACE_Hash_Multi_Map_Entry<@c EXT_ID, <@c INT_ID>).
   * @param entry_alloc is a pointer to an additional allocator for
   *        entries, so it should be able to allocate 'size' / chunks
   *        of sizeof (ACE_Hash_Multi_Map_Entry<@c EXT_ID, <@c INT_ID>) bytes
   *        each.
   * If @a table_alloc is 0 it defaults to @c ACE_Allocator::instance().
   * If @a entry_alloc is 0 then it defaults to the same allocator as
   * @a table_alloc.
   * @return -1 on failure, 0 on success
   */

  int open (size_t size = ACE_DEFAULT_MAP_SIZE,
            ACE_Allocator *table_alloc = 0,
            ACE_Allocator *entry_alloc = 0);

  /// Close down a Hash_Multi_Map_Manager and release dynamically allocated
  /// resources.
  int close (void);

  /// Removes all the entries in Hash_Multi_Map_Manager.
  int unbind_all (void);

  /// Cleanup the Hash_Multi_Map_Manager.
  ~ACE_Hash_Multi_Map_Manager (void);

  /**
   * Associate @a ext_id with @a int_id.  If @a ext_id and @a int_id is already
   * in the map then the @c ACE_Hash_Multi_Map_Entry is not changed.  Returns 0 if
   * a new entry is bound successfully, returns 1 if an attempt is made
   * to bind an existing entry, and returns -1 if failures occur.
   */
  int bind (const EXT_ID &ext_id,
            const INT_ID &int_id);

  /**
   * Same as a normal bind, except the map entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int bind (const EXT_ID &ext_id,
            const INT_ID &int_id,
            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id_set.  If @a ext_id is already in the
   * map then the @c ACE_Hash_Multi_Map_Entry is not changed.  Returns 0 if a
   * new entry is bound successfully, returns 1 if an attempt is made
   * to bind an existing entry, and returns -1 if failures occur.
   */
  int bind (const EXT_ID &ext_id,
            const ACE_Unbounded_Set<INT_ID> &int_id_set);

  /**
   * Same as a normal bind, except the map entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int bind (const EXT_ID &ext_id,
            const ACE_Unbounded_Set<INT_ID> &int_id_set,
            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id_set if and only if @a ext_id is
   * not in the map.  If @a ext_id is already in the map then the @a int_id_set
   * parameter is assigned the existing value in the map.  Returns 0
   * if a new entry is bound successfully, returns 1 if an attempt is
   * made to bind an existing entry, and returns -1 if failures occur.
   */
  int trybind (const EXT_ID &ext_id,
               ACE_Unbounded_Set<INT_ID> &int_id_set);

  /**
   * Same as a normal trybind, except the map entry is also passed
   * back to the caller.  The entry in this case will either be the
   * newly created entry, or the existing one.
   */
  int trybind (const EXT_ID &ext_id,
               ACE_Unbounded_Set<INT_ID> &int_id_set,
               ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /**
   * Reassociate @a ext_id with @a int_id_set.  If @a ext_id is not in
   * the map then behaves just like bind.  Returns 0 if a new entry is
   * bound successfully, returns 1 if an existing entry was rebound,
   * and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set);

  /**
   * Same as a normal rebind, except the map entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id_set.  If @a ext_id is not in the map
   * then behaves just like bind.  Otherwise, store the old value of
   * @a int_id_set into the "out" parameter and rebind the new parameters.
   * Returns 0 if a new entry is bound successfully, returns 1 if an
   * existing entry was rebound, and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              ACE_Unbounded_Set<INT_ID> &old_int_id_set);

  /**
   * Same as a normal rebind, except the map entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              ACE_Unbounded_Set<INT_ID> &old_int_id_set,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /**
   * Associate @a ext_id with @a int_id_set.  If @a ext_id is not in the map
   * then behaves just like bind.  Otherwise, store the old values
   * of @a ext_id and @a int_id_set into the "out" parameters and rebind the
   * new parameters.  This is very useful if you need to have an
   * atomic way of updating @c ACE_Hash_Multi_Map_Entry objects and you also
   * need full control over memory allocation.  Returns 0 if a new entry
   * is bound successfully, returns 1 if an existing entry was rebound,
   * and returns -1 if failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              EXT_ID &old_ext_id,
              ACE_Unbounded_Set<INT_ID> &old_int_id_set);

  /**
   * Same as a normal rebind, except the map entry is also passed back
   * to the caller.  The entry in this case will either be the newly
   * created entry, or the existing one.
   */
  int rebind (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              EXT_ID &old_ext_id,
              ACE_Unbounded_Set<INT_ID> &old_int_id_set,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Locate @a ext_id and pass out parameter via @a int_id_set.
  /// Return 0 if found, returns -1 if not found.
  int find (const EXT_ID &ext_id,
            ACE_Unbounded_Set<INT_ID> &int_id_set) const;

  /// Locate @a ext_id and @a int_id.
  /// Return 0 if found, returns -1 if not found.
  int find (const EXT_ID &ext_id,
            const INT_ID &int_id) const;

  /// Returns 0 if the @a ext_id is in the mapping, otherwise -1.
  int find (const EXT_ID &ext_id) const;

  /// Locate @a ext_id and pass out parameter via @a entry.  If found,
  /// return 0, returns -1 if not found.
  int find (const EXT_ID &ext_id,
            ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry) const;

  /**
   * Unbind (remove) the @a ext_id from the map.  Don't return the
   * int_id to the caller (this is useful for collections where the
   * int_ids are *not* dynamically allocated...)
   */
  int unbind (const EXT_ID &ext_id);

  /// Break any association of @a ext_id.  Returns the value of @a int_id_set
  /// in case the caller needs to deallocate memory. Return 0 if the
  /// unbind was successfully, and returns -1 if failures occur.
  int unbind (const EXT_ID &ext_id,
              ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Break any association of @a ext_id and @a int_id. Return 0 if the
  /// unbind was successfully, and returns -1 if failures occur.
  int unbind (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /// Remove @a entry from map. Return 0 if the unbind was successfully,
  /// and returns -1 if failures occur.
  int unbind (ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *entry);

  /// Returns the current number of @c ACE_Hash_Multi_Map_Entry objects in the
  /// hash table.
  size_t current_size (void) const;

  /// Return the size of the array that's used to point to the
  /// linked lists of @c ACE_Hash_Multi_Map_Entry objects in the hash table.
  size_t total_size (void) const;

  /**
   * Returns a reference to the underlying @c ACE_LOCK.  This makes it
   * possible to acquire the lock explicitly, which can be useful in
   * some cases if you instantiate the @c ACE_Atomic_Op with an
   * @c ACE_Recursive_Mutex or @c ACE_Process_Mutex, or if you need to
   * guard the state of an iterator.
   * @note The right name would be lock, but HP/C++ will choke on that!
   */
  ACE_LOCK &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iterator factory functions.

  /// Return forward iterator.
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> begin (void);
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> end (void);

  /// Return reverse iterator.
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> rbegin (void);
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> rend (void);

protected:
  // = The following methods do the actual work.

  /// Returns 1 if @a id1 == @a id2, else 0.  This is defined as a
  /// separate method to facilitate template specialization.
  int equal (const EXT_ID &id1, const EXT_ID &id2);

  /// Compute the hash value of the @a ext_id.  This is defined as a
  /// separate method to facilitate template specialization.
  u_long hash (const EXT_ID &ext_id);

  // = These methods assume locks are held by private methods.

  /// Performs bind.  Must be called with locks held.
  int bind_i (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /// Performs bind.  Must be called with locks held.
  int bind_i (const EXT_ID &ext_id,
              const INT_ID &int_id,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs bind.  Must be called with locks held.
  int bind_i (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Performs bind.  Must be called with locks held.
  int bind_i (const EXT_ID &ext_id,
              const ACE_Unbounded_Set<INT_ID> &int_id_set,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs trybind.  Must be called with locks held.
  int trybind_i (const EXT_ID &ext_id,
                 ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Performs trybind.  Must be called with locks held.
  int trybind_i (const EXT_ID &ext_id,
                 ACE_Unbounded_Set<INT_ID> &int_id_set,
                 ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set,
                ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set,
                ACE_Unbounded_Set<INT_ID> &old_int_id);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set,
                ACE_Unbounded_Set<INT_ID> &old_int_id_set,
                ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set,
                EXT_ID &old_ext_id,
                ACE_Unbounded_Set<INT_ID> &old_int_id_set);

  /// Performs rebind.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const ACE_Unbounded_Set<INT_ID> &int_id_set,
                EXT_ID &old_ext_id,
                ACE_Unbounded_Set<INT_ID> &old_int_id_set,
                ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs a find of @a int_id_set using @a ext_id as the key.  Must be
  /// called with locks held.
  int find_i (const EXT_ID &ext_id,
              ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Performs a find of @a ext_id and @a int_id.  Must be
  /// called with locks held.
  int find_i (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /// Performs a find using @a ext_id as the key.  Must be called with
  /// locks held.
  int find_i (const EXT_ID &ext_id);

  /// Performs a find using @a ext_id as the key.  Must be called with
  /// locks held.
  int find_i (const EXT_ID &ext_id,
              ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry);

  /// Performs unbind.  Must be called with locks held.
  int unbind_i (const EXT_ID &ext_id,
                ACE_Unbounded_Set<INT_ID> &int_id_set);

  /// Performs unbind.  Must be called with locks held.
  int unbind_i (const EXT_ID &ext_id,
                const INT_ID &int_id);

  /// Performs unbind.  Must be called with locks held.
  int unbind_i (const EXT_ID &ext_id);

  /// Performs unbind.  Must be called with locks held.
  int unbind_i (ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *entry);

  /**
   * Resize the map.  Must be called with locks held.
   * @note This method should never be called more than once or else all the
   * hashing will get screwed up as the size will change.
   */
  int create_buckets (size_t size);

  /// Close down a Map_Manager.  Must be called with
  /// locks held.
  int close_i (void);

  /// Removes all the entries in Map_Manager.  Must be called with
  /// locks held.
  int unbind_all_i (void);

  /// Pointer to a memory allocator used for table_, so it should
  /// supply size*sizeof (@c ACE_Hash_Multi_Map_Entry<@c EXT_ID, @c INT_ID>),
  ACE_Allocator *table_allocator_;

  /// Addidtional allocator for entries, so it should be able to
  /// allocate 'size' / chunks of sizeof
  /// (@c ACE_Hash_Multi_Map_Entry<@c EXT_ID, @c INT_ID>) bytes each.
  ACE_Allocator *entry_allocator_;

  /// Synchronization variable for the MT_SAFE
  /// @c ACE_Hash_Multi_Map_Manager.
  ACE_LOCK lock_;

  /// Function object used for hashing keys.
  HASH_KEY hash_key_;

  /// Function object used for comparing keys.
  COMPARE_KEYS compare_keys_;

protected:
  /// Returns the @c ACE_Hash_Multi_Map_Entry object that corresponds to
  /// @a ext_id.
  int shared_find (const EXT_ID &ext_id,
                   ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&entry,
                   size_t &loc);

  /// Accessor of the underlying table
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *table (void);

  /// Accessor of the current size attribute
  size_t cur_size (void) const;

private:
  /**
   * Array of the pointers to @c ACE_Hash_Multi_Map_Entry objects, each of
   * which points to an @c ACE_Hash_Multi_Map_Entry that serves as the
   * beginning of a linked list of @c EXT_ID that hash to that bucket.
   */
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *table_;

  /// Total size of the hash table.
  size_t total_size_;

  /// Current number of entries in the table
  /// @note That this can be larger than total_size_ due to the
  /// bucket chaining).
  size_t cur_size_;

  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Hash_Multi_Map_Manager (const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &))
};

/**
 * @class ACE_Hash_Multi_Map_Iterator_Base
 *
 * @brief Base iterator for the @c ACE_Hash_Multi_Map_Manager
 *
 * This class factors out common code from its templatized
 * subclasses.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Iterator_Base
{
public:
  // = Initialization method.
  /// Contructor.  If @a head != 0, the iterator constructed is positioned
  /// at the head of the map, it is positioned at the end otherwise.
  ACE_Hash_Multi_Map_Iterator_Base (ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                    int head);

  // = ITERATION methods.

  /// Pass back the @a next_entry that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&next_entry) const;

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Returns a reference to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>& operator* (void) const;

  /// Returns a pointer to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>* operator-> (void) const;

  /// Returns reference the @c Hash_Multi_Map_Manager that is being iterated
  /// over.
  ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>& map (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Hash_Multi_Map_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;
  bool operator!= (const ACE_Hash_Multi_Map_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Move forward by one element in the set.  Returns 0 when there's
  /// no more item in the set after the current items, else 1.
  int forward_i (void);

  /// Move backward by one element in the set.  Returns 0 when there's
  /// no more item in the set before the current item, else 1.
  int reverse_i (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  /// Map we are iterating over.
  ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *map_man_;

  /// Keeps track of how far we've advanced in the table.
  ssize_t index_;

  /// Keeps track of how far we've advanced in a linked list in each
  /// table slot.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next_;
};

/**
 * @class ACE_Hash_Multi_Map_Const_Iterator_Base
 *
 * @brief Base const iterator for the @c ACE_Hash_Multi_Map_Manager
 *
 * This class factors out common code from its templatized
 * subclasses.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Const_Iterator_Base
{
public:
  // = Initialization method.
  /// Contructor.  If @a head != 0, the iterator constructed is positioned
  /// at the head of the map, it is positioned at the end otherwise.
  ACE_Hash_Multi_Map_Const_Iterator_Base (const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                          int head);

  // = ITERATION methods.

  /// Pass back the @a next_entry that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *&next_entry) const;

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Returns a reference to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>& operator* (void) const;

  /// Returns a pointer to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>* operator-> (void) const;

  /// Returns reference the @c Hash_Multi_Map_Manager that is being iterated
  /// over.
  const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>& map (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Hash_Multi_Map_Const_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;
  bool operator!= (const ACE_Hash_Multi_Map_Const_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Move forward by one element in the set.  Returns 0 when there's
  /// no more item in the set after the current items, else 1.
  int forward_i (void);

  /// Move backward by one element in the set.  Returns 0 when there's
  /// no more item in the set before the current item, else 1.
  int reverse_i (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  /// Map we are iterating over.
  const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *map_man_;

  /// Keeps track of how far we've advanced in the table.
  ssize_t index_;

  /// Keeps track of how far we've advanced in a linked list in each
  /// table slot.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next_;
};

/**
 * @class ACE_Hash_Multi_Map_Iterator
 *
 * @brief Forward iterator for the @c ACE_Hash_Multi_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * @c ACE_Hash_Multi_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * @c ACE_GUARD or @c ACE_READ_GUARD on the @c ACE_Hash_Multi_Map_Manager's
 * internal lock, which is accessible via its @c mutex method.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Iterator : public ACE_Hash_Multi_Map_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Hash_Multi_Map_Iterator (ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                               int tail = 0);

  // = Iteration methods.
  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix advance.
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator++ (void);

  /// Postfix advance.
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator-- (void);

  /// Postfix reverse.
  ACE_Hash_Multi_Map_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Hash_Multi_Map_Const_Iterator
 *
 * @brief Const forward iterator for the @c ACE_Hash_Multi_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * @c ACE_Hash_Multi_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * @c ACE_GUARD or @c ACE_READ_GUARD on the @c ACE_Hash_Multi_Map_Manager's
 * internal lock, which is accessible via its @c mutex() method.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Const_Iterator : public ACE_Hash_Multi_Map_Const_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Hash_Multi_Map_Const_Iterator (const ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                     int tail = 0);

  // = Iteration methods.
  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix advance.
  ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator++ (void);

  /// Postfix advance.
  ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator-- (void);

  /// Postfix reverse.
  ACE_Hash_Multi_Map_Const_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Hash_Multi_Map_Bucket_Iterator
 *
 * @brief Forward iterator for the @c ACE_Hash_Multi_Map_Manager which
 * only traverses a particular bucket.  The particular bucket is
 * specified by the @c EXT_ID parameter specified in the constructor.
 *
 * This class does not perform any internal locking of the
 * @c ACE_Hash_Multi_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * @c ACE_GUARD or @c ACE_READ_GUARD on the @c ACE_Hash_Multi_Map_Manager's
 * internal lock, which is accessible via its @c mutex method.
 *
 * Note that a creation method for this new iterator cannot be added
 * to the hash map, since this would require adding explicit template
 * instantiations for bucket iterators on platforms with broken
 * templates.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Bucket_Iterator
{
public:
  // = Initialization method.
  ACE_Hash_Multi_Map_Bucket_Iterator (ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                      const EXT_ID &ext_id,
                                      int tail = 0);

  // = STL styled iteration, compare, and reference functions.

  /// Prefix advance.
  ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator++ (void);

  /// Postfix advance.
  ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator-- (void);

  /// Postfix reverse.
  ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Returns a reference to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>& operator* (void) const;

  /// Returns a pointer to the interal element this object is pointing to.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID>* operator-> (void) const;

  /// Returns reference the Hash_Multi_Map_Manager that is being iterated
  /// over.
  ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>& map (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;
  bool operator!= (const ACE_Hash_Multi_Map_Bucket_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &) const;

protected:
  /// Move forward by one element in the set.  Returns 0 when there's
  /// no more item in the set after the current items, else 1.
  int forward_i (void);

  /// Move backward by one element in the set.  Returns 0 when there's
  /// no more item in the set before the current item, else 1.
  int reverse_i (void);

  /// Map we are iterating over.
  ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> *map_man_;

  /// Keeps track of how far we've advanced in the table.
  ssize_t index_;

  /// Keeps track of how far we've advanced in a linked list in each
  /// table slot.
  ACE_Hash_Multi_Map_Entry<EXT_ID, INT_ID> *next_;
};

/**
 * @class ACE_Hash_Multi_Map_Reverse_Iterator
 *
 * @brief Reverse iterator for the @c ACE_Hash_Multi_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * @c ACE_Hash_Multi_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * @c ACE_GUARD or @c ACE_READ_GUARD on the @c ACE_Hash_Multi_Map_Manager's
 * internal lock, which is accessible via its @c mutex method.
 */
template <class EXT_ID, class INT_ID, class HASH_KEY, class COMPARE_KEYS, class ACE_LOCK>
class ACE_Hash_Multi_Map_Reverse_Iterator : public ACE_Hash_Multi_Map_Iterator_Base<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Hash_Multi_Map_Reverse_Iterator (ACE_Hash_Multi_Map_Manager<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &mm,
                                       int head = 0);

  // = Iteration methods.
  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix reverse.
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator++ (void);

  /// Postfix reverse.
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator++ (int);

  /// Prefix advance.
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> &operator-- (void);

  /// Postfix advance.
  ACE_Hash_Multi_Map_Reverse_Iterator<EXT_ID, INT_ID, HASH_KEY, COMPARE_KEYS, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#  include "ace/Hash_Multi_Map_Manager_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Hash_Multi_Map_Manager_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Hash_Multi_Map_Manager_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_HASH_MULTI_MAP_MANAGER_T_H */
