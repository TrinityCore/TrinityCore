// -*- C++ -*-
//
//$Id: Recyclable.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE ACE_Recyclable_State
ACE_Recyclable::recycle_state (void) const
{
  return this->recycle_state_;
}
ACE_INLINE void
ACE_Recyclable::recycle_state (ACE_Recyclable_State new_state)
{
  if (this->recycle_state_ != ACE_RECYCLABLE_CLOSED)
    this->recycle_state_ = new_state;
}
ACE_END_VERSIONED_NAMESPACE_DECL
