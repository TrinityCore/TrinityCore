// -*- C++ -*-
//
// $Id: Active_Map_Manager.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_string.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_Active_Map_Manager_Key::ACE_Active_Map_Manager_Key (void)
{
  // If you change ~0, please change ACE_Map_Manager::free_list_id()
  // accordingly.
  this->key_data_.slot_index_ = (ACE_UINT32) ~0;
  this->key_data_.slot_generation_ = 0;
}
ACE_INLINE
ACE_Active_Map_Manager_Key::ACE_Active_Map_Manager_Key (ACE_UINT32 slot_index,
                                                        ACE_UINT32 slot_generation)
{
  this->key_data_.slot_index_ = slot_index;
  this->key_data_.slot_generation_ = slot_generation;
}
ACE_INLINE ACE_UINT32
ACE_Active_Map_Manager_Key::slot_index (void) const
{
  return this->key_data_.slot_index_;
}
ACE_INLINE ACE_UINT32
ACE_Active_Map_Manager_Key::slot_generation (void) const
{
  return this->key_data_.slot_generation_;
}
ACE_INLINE bool
ACE_Active_Map_Manager_Key::operator== (const ACE_Active_Map_Manager_Key &rhs) const
{
  return
    this->key_data_.slot_index_ == rhs.key_data_.slot_index_ &&
    this->key_data_.slot_generation_ == rhs.key_data_.slot_generation_;
}
ACE_INLINE bool
ACE_Active_Map_Manager_Key::operator!= (const ACE_Active_Map_Manager_Key &rhs) const
{
  return !this->operator== (rhs);
}
ACE_INLINE void
ACE_Active_Map_Manager_Key::slot_index (ACE_UINT32 i)
{
  this->key_data_.slot_index_ = i;
}
ACE_INLINE void
ACE_Active_Map_Manager_Key::slot_generation (ACE_UINT32 g)
{
  this->key_data_.slot_generation_ = g;
}
ACE_INLINE void
ACE_Active_Map_Manager_Key::increment_slot_generation_count (void)
{
  ++this->key_data_.slot_generation_;
}
/* static */
ACE_INLINE size_t
ACE_Active_Map_Manager_Key::size (void)
{
  return sizeof (ACE_UINT32) + sizeof (ACE_UINT32);
}
ACE_INLINE void
ACE_Active_Map_Manager_Key::decode (const void *data)
{
  // Copy the information from the user buffer into the key.
  ACE_OS::memcpy (&this->key_data_,
                  data,
                  sizeof this->key_data_);
}
ACE_INLINE void
ACE_Active_Map_Manager_Key::encode (void *data) const
{
  // Copy the key data to the user buffer.
  ACE_OS::memcpy (data,
                  &this->key_data_,
                  sizeof this->key_data_);
}
ACE_END_VERSIONED_NAMESPACE_DECL
