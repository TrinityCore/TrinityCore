// -*- C++ -*-
//
// $Id: Malloc.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Control_Block::ACE_Name_Node::~ACE_Name_Node (void)
{
}

ACE_INLINE void
ACE_Control_Block::ACE_Malloc_Header::init_ptr
  (ACE_Malloc_Header **ptr, ACE_Malloc_Header *init, void *)
{
  *ptr = init;
}

ACE_INLINE void
ACE_Control_Block::ACE_Name_Node::init_ptr
  (ACE_Name_Node **ptr, ACE_Name_Node *init, void *)
{
  *ptr = init;
}

ACE_END_VERSIONED_NAMESPACE_DECL
