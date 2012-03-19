// -*- C++ -*-
//
// $Id: Reactor_Notification_Strategy.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Reactor *
ACE_Reactor_Notification_Strategy::reactor (void)
{
  return this->reactor_;
}

ACE_INLINE void
ACE_Reactor_Notification_Strategy::reactor (ACE_Reactor *r)
{
  this->reactor_ = r;
}

ACE_END_VERSIONED_NAMESPACE_DECL
