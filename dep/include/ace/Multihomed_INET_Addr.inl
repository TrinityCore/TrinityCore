// -*- C++ -*-
//
// $Id: Multihomed_INET_Addr.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Accessor implementations
ACE_INLINE
size_t
ACE_Multihomed_INET_Addr::get_num_secondary_addresses() const
{
  return this->secondaries_.size();
}

ACE_END_VERSIONED_NAMESPACE_DECL
