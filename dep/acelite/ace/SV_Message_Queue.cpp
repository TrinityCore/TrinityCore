// $Id: SV_Message_Queue.cpp 91286 2010-08-05 09:04:31Z johnnyw $

#include "ace/SV_Message_Queue.h"
#include "ace/Log_Msg.h"

#if !defined (__ACE_INLINE__)
#include "ace/SV_Message_Queue.inl"
#endif /* __ACE_INLINE__ */



ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_SV_Message_Queue)

void
ACE_SV_Message_Queue::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_SV_Message_Queue::dump");
#endif /* ACE_HAS_DUMP */
}

ACE_SV_Message_Queue::ACE_SV_Message_Queue (void)
{
  ACE_TRACE ("ACE_SV_Message_Queue::ACE_SV_Message_Queue");
}

ACE_SV_Message_Queue::~ACE_SV_Message_Queue (void)
{
  ACE_TRACE ("ACE_SV_Message_Queue::~ACE_SV_Message_Queue");
}

ACE_SV_Message_Queue::ACE_SV_Message_Queue (key_t external_id,
                                            int create,
                                            int perms)
{
  ACE_TRACE ("ACE_SV_Message_Queue::ACE_SV_Message_Queue");
  if (this->open (external_id, create, perms) == -1)
    ACE_ERROR ((LM_ERROR, ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_SV_Message_Queue::ACE_SV_Message_Queue")));
}

ACE_END_VERSIONED_NAMESPACE_DECL
