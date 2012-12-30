// -*- C++ -*-
//
// $Id: Message_Queue_Vx.inl 96534 2012-12-17 20:54:40Z mitza $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_VXWORKS)
// Specialization to use native VxWorks Message Queues.

ACE_INLINE MSG_Q_ID
ACE_Message_Queue_Vx::msgq (void)
{
  // Hijack the tail_ field to store the MSG_Q_ID.
  return static_cast<MSG_Q_ID> (
#if defined __LP64__ && defined __RTP__
  // In RTP-mode only MSG_Q_ID is an int; in a 64-bit build the size of MSG_Q_ID
  // doesn't match the size of a pointer, tail_, so first treat it as 64-bit.
                                reinterpret_cast<long> (tail_)
#elif defined __RTP__
                                reinterpret_cast<int> (tail_)
#else
                                tail_
#endif
                                );
}

#endif /* ACE_VXWORKS */

ACE_END_VERSIONED_NAMESPACE_DECL
