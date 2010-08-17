/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Active_Map_Manager.h
 *
 *  $Id: Active_Map_Manager.h 91066 2010-07-12 11:05:04Z johnnyw $
 *
 *  @author Irfan Pyarali
 */
//=============================================================================


#ifndef ACE_ACTIVE_MAP_MANAGER_H
#define ACE_ACTIVE_MAP_MANAGER_H
#include /**/ "ace/pre.h"

#include /**/ "ace/ACE_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Active_Map_Manager_Key
 *
 * @brief Key used in the Active Object Map.
 *
 * This key keeps information of the index and the generation
 * count of the slot it represents.  Since the index information
 * is part of the key, lookups are super fast and predictable,
 */
class ACE_Export ACE_Active_Map_Manager_Key
{
public:
  /// Default constructor.
  ACE_Active_Map_Manager_Key (void);

  /**
   * Constructor given the @a slot_index and @a slot_generation number.
   * This is useful once the user has somehow recovered the
   * @a slot_index and @a slot_generation number from the client.
   */
  ACE_Active_Map_Manager_Key (ACE_UINT32 slot_index,
                              ACE_UINT32 slot_generation);

  /// Get the slot_index.
  ACE_UINT32 slot_index (void) const;

  /// Set the slot_index.
  void slot_index (ACE_UINT32 i);

  /// Get the slot_generation number.
  ACE_UINT32 slot_generation (void) const;

  /// Set the slot_generation number.
  void slot_generation (ACE_UINT32 g);

  /// Size required to store information about active key.
  static size_t size (void);

  /// Recover state of active key from @a data.  User must make sure
  /// that @a data encoded using the encode() method.
  void decode (const void *data);

  /// Encode state of the active key into @a data.  @a data must be as
  /// big as the value returned from <size>.
  void encode (void *data) const;

  /// Compare keys.
  bool operator== (const ACE_Active_Map_Manager_Key &rhs) const;
  bool operator!= (const ACE_Active_Map_Manager_Key &rhs) const;

  // = This really should be protected but because of template
  // friends, they are not.

  /// Increment the slot_generation number.
  void increment_slot_generation_count (void);

private:

  /**
   * @brief Data for the Active Object Map Key.
   *
   * This separate structure makes it easier to manage copying
   *  the index and the generation to and from the user buffer.
   *
   */
  struct key_data
  {
    /// Slot index in the active map.
    ACE_UINT32 slot_index_;

    /// Slot generation number of @c slot_index_ slot in the active map.
    ACE_UINT32 slot_generation_;
  };

  /// Data for the Active Object Map Key.
  key_data key_data_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Active_Map_Manager.inl"
#endif /* __ACE_INLINE__ */

// Include the templates here.
#include "ace/Active_Map_Manager_T.h"

#include /**/ "ace/post.h"
#endif /* ACE_ACTIVE_MAP_MANAGER_H */
