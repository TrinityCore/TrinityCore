// $Id: Typed_SV_Message_Queue.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_TYPED_SV_MESSAGE_QUEUE_CPP
#define ACE_TYPED_SV_MESSAGE_QUEUE_CPP

#include "ace/Typed_SV_Message.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Typed_SV_Message_Queue.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/Typed_SV_Message_Queue.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Typed_SV_Message_Queue)

template <class T> void
ACE_Typed_SV_Message_Queue<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Typed_SV_Message_Queue<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Typed_SV_Message_Queue<T>::ACE_Typed_SV_Message_Queue (void)
{
  ACE_TRACE ("ACE_Typed_SV_Message_Queue<T>::ACE_Typed_SV_Message_Queue");
}

template <class T>
ACE_Typed_SV_Message_Queue<T>::ACE_Typed_SV_Message_Queue (key_t external_id,
                                                           int create,
                                                           int perms)
{
  ACE_TRACE ("ACE_Typed_SV_Message_Queue<T>::ACE_Typed_SV_Message_Queue");
  if (this->open (external_id, create, perms) == -1)
    ACE_ERROR ((LM_ERROR,
                "ACE_Typed_SV_Message_Queue::ACE_Typed_SV_Message_Queue"));
}

template <class T>
ACE_Typed_SV_Message_Queue<T>::~ACE_Typed_SV_Message_Queue (void)
{
  ACE_TRACE ("ACE_Typed_SV_Message_Queue<T>::~ACE_Typed_SV_Message_Queue");
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TYPED_SV_MESSAGE_QUEUE_CPP */
