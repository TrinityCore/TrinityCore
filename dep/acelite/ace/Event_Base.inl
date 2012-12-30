// -*- C++ -*-
// $Id: Event_Base.inl 96220 2012-11-06 10:03:41Z mcorino $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_event_t
ACE_Event_Base::handle (void) const
{
  return this->handle_;
}

ACE_INLINE void
ACE_Event_Base::handle (ACE_event_t new_handle)
{
  this->handle_ = new_handle;
}

ACE_END_VERSIONED_NAMESPACE_DECL
