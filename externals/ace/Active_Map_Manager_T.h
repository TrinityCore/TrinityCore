/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Active_Map_Manager_T.h
 *
 *  $Id: Active_Map_Manager_T.h 84316 2009-02-03 19:46:05Z johnnyw $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================


#ifndef ACE_ACTIVE_MAP_MANAGER_T_H
#define ACE_ACTIVE_MAP_MANAGER_T_H
#include /**/ "ace/pre.h"

#include "ace/Map_Manager.h"
#include "ace/Active_Map_Manager.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Null_Mutex.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Active_Map_Manager
 *
 * @brief Define a map abstraction that associates system generated
 * keys with user specified values.
 *
 * Since the key is system generated, searches are very fast and
 * take a constant amount of time.
 */
template <class T>
class ACE_Active_Map_Manager : public ACE_Map_Manager<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex>
{
public:

  // = Traits.
  typedef ACE_Active_Map_Manager_Key key_type;
  typedef T mapped_type;

  typedef ACE_Map_Entry<ACE_Active_Map_Manager_Key, T> ENTRY;
  typedef ACE_Map_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> ITERATOR;
  typedef ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> REVERSE_ITERATOR;

  typedef ENTRY entry;
  typedef ITERATOR iterator;
  typedef REVERSE_ITERATOR reverse_iterator;

  // = Initialization and termination methods.
  /// Initialize a Active_Map_Manager with the ACE_DEFAULT_MAP_SIZE.
  ACE_Active_Map_Manager (ACE_Allocator *alloc = 0);

  /// Initialize a Active_Map_Manager with @a size entries.
  ACE_Active_Map_Manager (size_t size,
                          ACE_Allocator *alloc = 0);

  /// Close down a Active_Map_Manager and release dynamically
  /// allocated resources.
  ~ACE_Active_Map_Manager (void);

  /// Initialize a Active_Map_Manager with size @a length.
  int open (size_t length = ACE_DEFAULT_MAP_SIZE,
            ACE_Allocator *alloc = 0);

  /// Close down a Active_Map_Manager and release dynamically
  /// allocated resources.
  int close (void);

  /// Add @a value to the map, and the corresponding key produced by the
  /// Active_Map_Manager is returned through @a key.
  int bind (const T &value,
            ACE_Active_Map_Manager_Key &key);

  /// Add @a value to the map.  The user does not care about the
  /// corresponding key produced by the Active_Map_Manager.
  int bind (const T &value);

  /**
   * Reserves a slot in the internal structure and returns the key and
   * a pointer to the value.  User should place their @a value into
   * @a internal_value.  This method is useful in reducing the number
   * of copies required in some cases.  Note that @a internal_value is
   * only a temporary pointer and will change when the map resizes.
   * Therefore, the user should use the pointer immediately and not
   * hold on to it.
   */
  int bind (ACE_Active_Map_Manager_Key &key,
            T *&internal_value);

  /// Reassociate @a key with @a value. The function fails if @a key is
  /// not in the map.
  int rebind (const ACE_Active_Map_Manager_Key &key,
              const T &value);

  /**
   * Reassociate @a key with @a value, storing the old value into the
   * "out" parameter @a old_value.  The function fails if @a key is not
   * in the map.
   */
  int rebind (const ACE_Active_Map_Manager_Key &key,
              const T &value,
              T &old_value);

  /**
   * Reassociate @a key with @a value, storing the old key and value
   * into the "out" parameter @a old_key and @a old_value.  The function
   * fails if @a key is not in the map.
   */
  int rebind (const ACE_Active_Map_Manager_Key &key,
              const T &value,
              ACE_Active_Map_Manager_Key &old_key,
              T &old_value);

  /// Locate @a value associated with @a key.
  int find (const ACE_Active_Map_Manager_Key &key,
            T &value) const;

  /// Is @a key in the map?
  int find (const ACE_Active_Map_Manager_Key &key) const;

  /**
   * Locate @a value associated with @a key.  The value is returned via
   * @a internal_value and hence a copy is saved.  Note that
   * @a internal_value is only a temporary pointer and will change when
   * the map resizes.  Therefore, the user should use the pointer
   * immediately and not hold on to it.
   */
  int find (const ACE_Active_Map_Manager_Key &key,
            T *&internal_value) const;

  // Creates a key.  User should place their @a value into
  // <*internal_value>.  This method is useful in reducing the number
  // of copies required in some cases.

  /// Remove @a key from the map.
  int unbind (const ACE_Active_Map_Manager_Key &key);

  /// Remove @a key from the map, and return the @a value associated with
  /// @a key.
  int unbind (const ACE_Active_Map_Manager_Key &key,
              T &value);

  /**
   * Locate @a value associated with @a key.  The value is returned via
   * @a internal_value and hence a copy is saved.  Note that
   * @a internal_value is only a temporary pointer and will change when
   * the map resizes or when this slot is reused.  Therefore, the user
   * should use the pointer immediately and not hold on to it.
   */
  int unbind (const ACE_Active_Map_Manager_Key &key,
              T *&internal_value);

  /// Return the current size of the map.
  size_t current_size (void) const;

  /// Return the total size of the map.
  size_t total_size (void) const;

  /// Returns a key that cannot be found in the map.
  static const ACE_Active_Map_Manager_Key npos (void);

  /// Dump the state of an object.
  void dump (void) const;

  // = STL styled iterator factory functions.

  /// Return forward iterator.
  ACE_Map_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> begin (void);
  ACE_Map_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> end (void);

  /// Return reverse iterator.
  ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> rbegin (void);
  ACE_Map_Reverse_Iterator<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> rend (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:

  /// Private base class
  typedef ACE_Map_Manager<ACE_Active_Map_Manager_Key, T, ACE_Null_Mutex> ACE_AMM_BASE;

private:

  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Active_Map_Manager<T> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Active_Map_Manager (const ACE_Active_Map_Manager<T> &))
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Active_Map_Manager_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Active_Map_Manager_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Active_Map_Manager_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_ACTIVE_MAP_MANAGER_T_H */
