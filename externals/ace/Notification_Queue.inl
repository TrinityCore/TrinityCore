// $Id: Notification_Queue.inl 81315 2008-04-10 07:14:15Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_Notification_Queue_Node::
ACE_Notification_Queue_Node()
  : ACE_Intrusive_List_Node<ACE_Notification_Queue_Node>()
  , contents_(0, 0)
{
}

ACE_INLINE void
ACE_Notification_Queue_Node::
set(ACE_Notification_Buffer const & rhs)
{
  contents_ = rhs;
}

ACE_INLINE ACE_Notification_Buffer const &
ACE_Notification_Queue_Node::
get() const
{
  return contents_;
}

ACE_INLINE bool
ACE_Notification_Queue_Node::
matches_for_purging(ACE_Event_Handler * eh) const
{
  return (0 != get().eh_) && (0 == eh || eh == get().eh_);
}

ACE_INLINE bool
ACE_Notification_Queue_Node::
mask_disables_all_notifications(ACE_Reactor_Mask mask)
{
  // the existing notification mask is left with nothing when applying
  // the mask
  return ACE_BIT_DISABLED (get().mask_, ~mask);
}

ACE_INLINE void
ACE_Notification_Queue_Node::
clear_mask(ACE_Reactor_Mask mask)
{
  ACE_CLR_BITS(contents_.mask_, mask);
}

ACE_END_VERSIONED_NAMESPACE_DECL

