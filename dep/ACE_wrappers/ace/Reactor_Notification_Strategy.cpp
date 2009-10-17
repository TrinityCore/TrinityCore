#include "ace/Reactor_Notification_Strategy.h"
#include "ace/Reactor.h"
#if !defined (__ACE_INLINE__)
#include "ace/Reactor_Notification_Strategy.inl"
#endif /* __ACE_INLINE __ */
ACE_RCSID(ace, Reactor_Notification_Strategy, "$Id: Reactor_Notification_Strategy.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Reactor_Notification_Strategy::ACE_Reactor_Notification_Strategy (
  ACE_Reactor *reactor,
  ACE_Event_Handler *eh,
  ACE_Reactor_Mask mask)
  : ACE_Notification_Strategy (eh, mask),
    reactor_ (reactor)
{
}
ACE_Reactor_Notification_Strategy::~ACE_Reactor_Notification_Strategy (void)
{
}
int
ACE_Reactor_Notification_Strategy::notify (void)
{
  return this->reactor_->notify (this->eh_, this->mask_);
}
int
ACE_Reactor_Notification_Strategy::notify (ACE_Event_Handler *eh,
                                           ACE_Reactor_Mask mask)
{
  return this->reactor_->notify (eh, mask);
}
ACE_END_VERSIONED_NAMESPACE_DECL

