// -*- C++ -*-
//
// $Id: Message_Queue_Vx.inl 96017 2012-08-08 22:18:09Z mitza $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_VXWORKS)
// Specialization to use native VxWorks Message Queues.

ACE_INLINE MSG_Q_ID
ACE_Message_Queue_Vx::msgq (void)
{
  // Hijack the tail_ field to store the MSG_Q_ID.
  return static_cast<MSG_Q_ID> (reinterpret_cast<long> (tail_));
}

#endif /* ACE_VXWORKS */

ACE_END_VERSIONED_NAMESPACE_DECL
