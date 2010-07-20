// -*- C++ -*-

//=============================================================================
/**
 *  @file    Map_Manager.h
 *
 *  $Id: Map_Manager.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MAP_MANAGER_H
#define ACE_MAP_MANAGER_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"
#include "ace/Global_Macros.h"
#include "ace/Default_Constants.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declaration.
class ACE_Allocator;

/**
 * @class ACE_Map_Entry
 *
 * @brief An entry in the Map.
 */
template <class EXT_ID, class INT_ID>
class ACE_Map_Entry
{
public:
  /// Initialize member variables.
  ACE_Map_Entry (void);

  /// We need this destructor to keep some compilers from complaining.
  /// It's just a no-op, however.
  ~ACE_Map_Entry (void);

  /// Key used to look up an entry.
  EXT_ID ext_id_;

  /// The contents of the entry itself.
  INT_ID int_id_;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

  // = These are really private, but unfortunately template friends
  // are not portable.

  /// Get next entry.
  ACE_UINT32 next (void) const;

  /// Set next entry.
  void next (ACE_UINT32 n);

  /// Get prev entry.
  ACE_UINT32 prev (void) const;

  /// Set prev entry.
  void prev (ACE_UINT32 p);

  /// Keeps track of the next entry.
  ACE_UINT32 next_;

  /// Keeps track of the previous entry.
  ACE_UINT32 prev_;

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  /// Is this entry free?
  bool free_;

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

};

// Forward decl.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Iterator_Base;

// Forward decl.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Const_Iterator_Base;

// Forward decl.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Const_Iterator;

// Forward decl.
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Reverse_Iterator;

/**
 * @class ACE_Map_Manager
 *
 * @brief Define a map abstraction that associates <EXT_ID>s with
 * <INT_ID>s.
 *
 * The <EXT_ID> must support <operator==>.  This constraint can
 * be alleviated via template specialization, as shown in the
 * $ACE_ROOT/tests/Conn_Test.cpp test.
 * This class uses an ACE_Allocator to allocate memory.  The
 * user can make this a persistant class by providing an
 * ACE_Allocator with a persistable memory pool.
 * This implementation of a map uses an array, which is searched
 * linearly.  For more efficient searching you should use the
 * <ACE_Hash_Map_Manager>.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Manager
{
public:
  friend class ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>;
  friend class ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>;
  friend class ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK>;
  friend class ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK>;
  friend class ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK>;

  // = Traits.
  typedef EXT_ID KEY;
  typedef INT_ID VALUE;
  typedef ACE_LOCK lock_type;
  typedef ACE_Map_Entry<EXT_ID, INT_ID> ENTRY;
  typedef ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> ITERATOR;
  typedef ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> CONST_ITERATOR;
  typedef ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> REVERSE_ITERATOR;

  typedef ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> iterator;
  typedef ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> const_iterator;
  typedef ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> reverse_iterator;

  // = Initialization and termination methods.
  /// Initialize a ACE_Map_Manager with the ACE_DEFAULT_MAP_SIZE.
  ACE_Map_Manager (ACE_Allocator *alloc = 0);

  /// Initialize a ACE_Map_Manager with @a size entries.
  ACE_Map_Manager (size_t size,
                   ACE_Allocator *alloc = 0);

  /// Initialize a ACE_Map_Manager with size @a length.
  int open (size_t length = ACE_DEFAULT_MAP_SIZE,
            ACE_Allocator *alloc = 0);

  /// Close down a ACE_Map_Manager and release dynamically allocated
  /// resources.
  int close (void);

  /// Close down a ACE_Map_Manager and release dynamically allocated
  /// resources.
  ~ACE_Map_Manager (void);

  /**
   * Associate @a ext_id with @a int_id.  If @a ext_id is already in the
   * map then the ACE_Map_Entry is not changed.
   * @retval 0 If a new entry is bound successfully.
   * @retval 1 If an attempt is made to bind an existing entry.
   * @retval -1 If failures occur.
   */
  int bind (const EXT_ID &ext_id,
            const INT_ID &int_id);

  /**
   * Reassociate @a ext_id with @a int_id.  If @a ext_id is not in the
   * map then behaves just like bind().  Otherwise, store the old
   * values of @a ext_id and @a int_id into the "out" parameters and
   * rebind the new parameters.  This is very useful if you need to
   * have an atomic way of updating <Map_Entries> and you also need
   * full control over memory allocation.
   * @retval 0 If a new entry is bound successfully.
   * @retval 1 If an existing entry was rebound.
   * @retval -1 If failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              EXT_ID &old_ext_id,
              INT_ID &old_int_id);

  /**
   * Reassociate @a ext_id with @a int_id.  If @a ext_id is not in the
   * map then behaves just like <bind>.  Otherwise, store the old
   * values of @a int_id into the "out" parameter and rebind the new
   * parameters.
   * @retval 0 If a new entry is bound successfully.
   * @retval 1 If an existing entry was rebound.
   * @retval -1 If failures occur.
   */
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id,
              INT_ID &old_int_id);

  /// Reassociate @a ext_id with @a int_id.  Old values in the map are
  /// ignored.
  int rebind (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /**
   * Associate @a ext_id with @a int_id if and only if @a ext_id is not
   * in the map.  If @a ext_id is already in the map then the @a int_id
   * parameter is overwritten with the existing value in the map
   * @retval 0 If a new entry is bound successfully.
   * @retval 1 If an attempt is made to bind an existing entry.
   * @retval -1 If failures occur.
   */
  int trybind (const EXT_ID &ext_id,
               INT_ID &int_id);

  /**
   * Locate @a ext_id and pass out parameter via @a int_id.
   * @retval 0 If found.
   * @retval -1 If not found.
   */
  int find (const EXT_ID &ext_id,
            INT_ID &int_id) const;

  /// Returns 0 if the @a ext_id is in the mapping, otherwise -1.
  int find (const EXT_ID &ext_id) const;

  /**
   * Unbind (remove) the @a ext_id from the map.  Don't return the
   * @a int_id to the caller (this is useful for collections where the
   * @a int_ids are *not* dynamically allocated...)  Returns 0 if
   * successful, else -1.
   */
  int unbind (const EXT_ID &ext_id);

  /**
   * Break any association of @a ext_id.  Returns the value of @a int_id
   * in case the caller needs to deallocate memory.  Returns 0 if
   * successful, else -1.
   */
  int unbind (const EXT_ID &ext_id,
              INT_ID &int_id);

  /**
   * Unbind all entires.
   */
  void unbind_all (void);

  /// Return the current size of the map.
  size_t current_size (void) const;

  /// Return the total size of the map.
  size_t total_size (void) const;

  /**
   * Returns a reference to the underlying <ACE_LOCK>.  This makes it
   * possible to acquire the lock explicitly, which can be useful in
   * some cases if you instantiate the ACE_Atomic_Op with an
   * ACE_Recursive_Mutex or ACE_Process_Mutex, or if you need to
   * guard the state of an iterator.
   * @note The right name would be <lock>, but HP/C++ will choke on that!
   */
  ACE_LOCK &mutex (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iterator factory functions.

  /// Return forward iterator.
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> begin (void);
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> end (void);

  /// Return reverse iterator.
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> rbegin (void);
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> rend (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  // = The following methods do the actual work.

  // These methods assume that the locks are held by the private
  // methods.

  /// Performs the binding of @a ext_id to @a int_id.  Must be called
  /// with locks held.
  int bind_i (const EXT_ID &ext_id,
              const INT_ID &int_id);

  /// Bind an entry (without finding first).  Must be called with locks
  /// held.
  int shared_bind (const EXT_ID &ext_id,
                   const INT_ID &int_id);

  /// Performs a rebinding of <ext_it> to @a int_id.  Also, recovers old
  /// values.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const INT_ID &int_id,
                EXT_ID &old_ext_id,
                INT_ID &old_int_id);

  /// Performs a rebinding of <ext_it> to @a int_id.  Also, recovers old
  /// values.  Must be called with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const INT_ID &int_id,
                INT_ID &old_int_id);

  /// Performs a rebinding of <ext_it> to @a int_id.  Must be called
  /// with locks held.
  int rebind_i (const EXT_ID &ext_id,
                const INT_ID &int_id);

  /// Performs a conditional bind of @a int_id using @a ext_id as the
  /// key.  Must be called with locks held.
  int trybind_i (const EXT_ID &ext_id,
                 INT_ID &int_id);

  /// Performs a find of @a int_id using @a ext_id as the key.  Must be
  /// called with locks held.
  int find_i (const EXT_ID &ext_id,
              INT_ID &int_id);

  /// Performs a find using @a ext_id as the key.  Must be called with
  /// locks held.
  int find_and_return_index (const EXT_ID &ext_id,
                             ACE_UINT32 &slot);

  /// Performs an unbind of @a int_id using @a ext_id as the key.  Must
  /// be called with locks held.
  int unbind_i (const EXT_ID &ext_id,
                INT_ID &int_id);

  /// Performs an unbind using @a ext_id as the key.  Must be called
  /// with locks held.
  int unbind_i (const EXT_ID &ext_id);

  /// Performs an unbind using @a ext_id as the key.  Must be called
  /// with locks held.
  int unbind_and_return_index (const EXT_ID &ext_id,
                               ACE_UINT32 &slot);

  /// Unbind @a slot.
  void unbind_slot (ACE_UINT32 slot);

  /// Resize the map.  Must be called with locks held.
  int resize_i (ACE_UINT32 size);

  /// Close down a <Map_Manager>.  Must be called with locks held.
  int close_i (void);

  /// Returns 1 if <id1> == <id2>, else 0.  This is defined as a
  /// separate method to facilitate template specialization.
  int equal (const EXT_ID &id1, const EXT_ID &id2);

  /// This function returns the new size of the Map Manager.  This
  /// function is called when we run out of room and need to resize.
  ACE_UINT32 new_size (void);

  /// Explicitly call the destructors and free up the
  /// <search_structure_>.
  void free_search_structure (void);

  /// Id of the free list sentinel.
  ACE_UINT32 free_list_id (void) const;

  /// Id of the occupied list sentinel.
  ACE_UINT32 occupied_list_id (void) const;

  /// Finds the next free slot.
  int next_free (ACE_UINT32 &slot);

  /// Move from free list to occupied list.
  void move_from_free_list_to_occupied_list (ACE_UINT32 slot);

  /// Move from occupied list to free list.
  void move_from_occupied_list_to_free_list (ACE_UINT32 slot);

#if defined (ACE_HAS_LAZY_MAP_MANAGER)

  /**
   * In the case of lazy map managers, the movement of free slots from
   * the occupied list to the free list is delayed until we run out of
   * free slots in the free list. This function goes through the
   * entire occupied list, moving free slots to the free list.
   */
  void move_all_free_slots_from_occupied_list (void);

#endif /* ACE_HAS_LAZY_MAP_MANAGER */

  /// Move helper.
  void shared_move (ACE_UINT32 slot,
                    ACE_Map_Entry<EXT_ID, INT_ID> &current_list,
                    ACE_UINT32 current_list_id,
                    ACE_Map_Entry<EXT_ID, INT_ID> &new_list,
                    ACE_UINT32 new_list_id);

  /// Pointer to a memory allocator.
  ACE_Allocator *allocator_;

  /// Synchronization variable for the MT_SAFE ACE_Map_Manager.
  mutable ACE_LOCK lock_;

  /// Implement the Map as a resizeable array of ACE_Map_Entry.
  ACE_Map_Entry<EXT_ID, INT_ID> *search_structure_;

  /// Total number of elements in this->search_structure_.
  ACE_UINT32 total_size_;

  /// Current size of the map.
  ACE_UINT32 cur_size_;

  /// Free list.
  ACE_Map_Entry<EXT_ID, INT_ID> free_list_;

  /// Occupied list.
  ACE_Map_Entry<EXT_ID, INT_ID> occupied_list_;

  enum
  {
    /// Grow map exponentially up to 64K
    MAX_EXPONENTIAL = 64 * 1024,

    /// Afterwards grow in chunks of 32K
    LINEAR_INCREASE = 32 * 1024
  };

private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Map_Manager (const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK> &))
};

/**
 * @class ACE_Map_Iterator_Base
 *
 * @brief Iterator for the ACE_Map_Manager.
 *
 * This class factors out common code from its templatized
 * subclasses.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Iterator_Base
{
public:
  // = Initialization method.
  /// Contructor.  If head != 0, the iterator constructed is positioned
  /// at the head of the map, it is positioned at the end otherwise.
  ACE_Map_Iterator_Base (ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> &mm);

  // = Iteration methods.

  /// Pass back the next <entry> that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Map_Entry<EXT_ID, INT_ID> *&next_entry) const;

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Returns a reference to the interal element @c this is pointing to.
  ACE_Map_Entry<EXT_ID, INT_ID>& operator* (void) const;

  /// Returns reference the Map_Manager that is being iterated
  /// over.
  ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>& map (void);

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &) const;
  bool operator!= (const ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Move forward by one element in the set.  Returns 0 when there's
  /// no more item in the set after the current items, else 1.
  int forward_i (void);

  /// Move backware by one element in the set.  Returns 0 when there's
  /// no more item in the set before the current item, else 1.
  int reverse_i (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  /// Map we are iterating over.
  ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> *map_man_;

  /// Keeps track of how far we've advanced...
  ACE_UINT32 next_;
};

/**
 * @class ACE_Map_Const_Iterator_Base
 *
 * @brief Const iterator for the ACE_Map_Manager.
 *
 * This class factors out common code from its templatized
 * subclasses.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Const_Iterator_Base
{
public:
  // = Initialization method.
  /// Contructor.  If head != 0, the iterator constructed is positioned
  /// at the head of the map, it is positioned at the end otherwise.
  ACE_Map_Const_Iterator_Base (const ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> &mm);

  // = Iteration methods.

  /// Pass back the next <entry> that hasn't been seen in the Set.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Map_Entry<EXT_ID, INT_ID> *&next_entry) const;

  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;

  /// Returns a reference to the interal element @c this is pointing to.
  ACE_Map_Entry<EXT_ID, INT_ID>& operator* (void) const;

  /// Returns reference the Map_Manager that is being iterated
  /// over.
  const ACE_Map_Manager<EXT_ID, INT_ID, ACE_LOCK>& map (void) const;

  /// Check if two iterators point to the same position
  bool operator== (const ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &) const;
  bool operator!= (const ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK> &) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Move forward by one element in the set.  Returns 0 when there's
  /// no more item in the set after the current items, else 1.
  int forward_i (void);

  /// Move backware by one element in the set.  Returns 0 when there's
  /// no more item in the set before the current item, else 1.
  int reverse_i (void);

  /// Dump the state of an object.
  void dump_i (void) const;

  /// Map we are iterating over.
  const ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> *map_man_;

  /// Keeps track of how far we've advanced...
  ACE_UINT32 next_;
};

/**
 * @class ACE_Map_Iterator
 *
 * @brief Forward iterator for the ACE_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * ACE_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * ACE_Guard or ACE_Read_Guard on the ACE_Map_Manager's
 * internal lock, which is accessible via its <mutex> method.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Iterator : public ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Map_Iterator (ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> &mm,
                    int pass_end = 0);

  // = Iteration methods.

  /// Move forward by one element in the set.   Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix advance.
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator++ (void);

  /// Postfix advance.
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator-- (void);

  /// Postfix reverse.
  ACE_Map_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Map_Const_Iterator
 *
 * @brief Forward const iterator for the ACE_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * ACE_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * ACE_Guard or ACE_Read_Guard on the ACE_Map_Manager's
 * internal lock, which is accessible via its <mutex> method.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Const_Iterator : public ACE_Map_Const_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Map_Const_Iterator (const ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> &mm,
                          int pass_end = 0);

  // = Iteration methods.

  /// Move forward by one element in the set.   Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix advance.
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator++ (void);

  /// Postfix advance.
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator++ (int);

  /// Prefix reverse.
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator-- (void);

  /// Postfix reverse.
  ACE_Map_Const_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

/**
 * @class ACE_Map_Reverse_Iterator
 *
 * @brief Reverse Iterator for the ACE_Map_Manager.
 *
 * This class does not perform any internal locking of the
 * ACE_Map_Manager it is iterating upon since locking is
 * inherently inefficient and/or error-prone within an STL-style
 * iterator.  If you require locking, you can explicitly use an
 * ACE_Guard or ACE_Read_Guard on the ACE_Map_Manager's
 * internal lock, which is accessible via its <mutex> method.
 */
template <class EXT_ID, class INT_ID, class ACE_LOCK>
class ACE_Map_Reverse_Iterator : public ACE_Map_Iterator_Base<EXT_ID, INT_ID, ACE_LOCK>
{
public:
  // = Initialization method.
  ACE_Map_Reverse_Iterator (ACE_Map_Manager <EXT_ID, INT_ID, ACE_LOCK> &mm,
                            int pass_end = 0);

  // = Iteration methods.

  /// Move forward by one element in the set.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iteration, compare, and reference functions.

  /// Prefix reverse.
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator++ (void);

  /// Postfix reverse.
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator++ (int);

  /// Prefix advance.
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> &operator-- (void);

  /// Postfix advance.
  ACE_Map_Reverse_Iterator<EXT_ID, INT_ID, ACE_LOCK> operator-- (int);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Map_Manager.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Map_Manager.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Map_Manager.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* ACE_MAP_MANAGER_H */
