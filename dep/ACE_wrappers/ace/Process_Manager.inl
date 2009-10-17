// -*- C++ -*-
//
// $Id: Process_Manager.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE size_t
ACE_Process_Manager::managed (void) const
{
  return current_count_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
