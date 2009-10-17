// -*- C++ -*-
//
// $Id: MEM_Connector.inl 80826 2008-03-04 14:51:23Z wotte $
// Establish a connection.
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ACE_MEM_IO::Signal_Strategy
ACE_MEM_Connector::preferred_strategy (void) const
{
  return this->preferred_strategy_;
}
ACE_INLINE void
ACE_MEM_Connector::preferred_strategy (ACE_MEM_IO::Signal_Strategy strategy)
{
  this->preferred_strategy_ = strategy;
}
ACE_INLINE ACE_MEM_SAP::MALLOC_OPTIONS &
ACE_MEM_Connector::malloc_options (void)
{
  // @@ This function has been deprecated and will be removed in the
  // future.
  return this->malloc_options_;
}
ACE_END_VERSIONED_NAMESPACE_DECL
