// -*- C++ -*-
//
// $Id: Cleanup.inl 83956 2008-12-03 07:57:38Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Cleanup::ACE_Cleanup (void)
{
}

ACE_INLINE void*
ACE_Cleanup_Info_Node::object(void)
{
  return this->object_;
}

ACE_INLINE ACE_CLEANUP_FUNC
ACE_Cleanup_Info_Node::cleanup_hook (void)
{
  return this->cleanup_hook_;
}

ACE_INLINE void *
ACE_Cleanup_Info_Node::param (void)
{
  return this->param_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
