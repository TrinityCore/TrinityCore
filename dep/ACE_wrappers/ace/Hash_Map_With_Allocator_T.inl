// -*- C++ -*-
// $Id: Hash_Map_With_Allocator_T.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
template <class EXT_ID, class INT_ID> ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::close (ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::close");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->close_i ();
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::bind (const EXT_ID &ext_id,
                                                   const INT_ID &int_id,
                                                   ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::bind");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->bind_i (ext_id, int_id);
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::unbind (const EXT_ID &ext_id,
                                                     INT_ID &int_id,
                                                     ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::unbind");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->unbind_i (ext_id, int_id);
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::unbind (const EXT_ID &ext_id,
                                                     ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID>::unbind");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->unbind_i (ext_id);
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::rebind (const EXT_ID &ext_id,
                                                     const INT_ID &int_id,
                                                     EXT_ID &old_ext_id,
                                                     INT_ID &old_int_id,
                                                     ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::rebind");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->rebind_i (ext_id, int_id, old_ext_id, old_int_id);
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::find (const EXT_ID &ext_id,
                                                   INT_ID &int_id,
                                                   ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::find");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->find_i (ext_id, int_id);
}
template <class EXT_ID, class INT_ID>  ACE_INLINE int
ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::find (const EXT_ID &ext_id,
                                                   ACE_Allocator *alloc)
{
  ACE_TRACE ("ACE_Hash_Map_With_Allocator<EXT_ID, INT_ID>::find");
  this->table_allocator_ = alloc;
  this->entry_allocator_ = alloc;
  return this->find_i (ext_id);
}
ACE_END_VERSIONED_NAMESPACE_DECL
