// -*- C++ -*-
// $Id: Event.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_event_t
ACE_Event::handle (void) const
{
  return this->handle_;
}

ACE_INLINE void
ACE_Event::handle (ACE_event_t new_handle)
{
  this->handle_ = new_handle;
}

ACE_END_VERSIONED_NAMESPACE_DECL
