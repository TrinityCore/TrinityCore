// -*- C++ -*-
//
// $Id: PI_Malloc.inl 80826 2008-03-04 14:51:23Z wotte $
#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE
ACE_PI_Control_Block::ACE_Name_Node::~ACE_Name_Node (void)
{
}
ACE_INLINE void
ACE_PI_Control_Block::ACE_Malloc_Header::init_ptr
  (MALLOC_HEADER_PTR *ptr, ACE_Malloc_Header *init, void *base_addr)
{
  new ((void *) ptr) MALLOC_HEADER_PTR (base_addr, 0);
  *ptr = init;
}
ACE_INLINE void
ACE_PI_Control_Block::ACE_Name_Node::init_ptr
  (NAME_NODE_PTR *ptr, ACE_Name_Node *init, void *base_addr)
{
  new ((void *) ptr) NAME_NODE_PTR (base_addr, 0);
  *ptr = init;
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

