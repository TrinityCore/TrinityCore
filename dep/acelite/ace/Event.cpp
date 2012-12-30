// $Id: Event.cpp 96220 2012-11-06 10:03:41Z mcorino $

#include "ace/Event.h"

#if !defined (__ACE_INLINE__)
#include "ace/Event.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/Condition_Attributes.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TIME_POLICY>
ACE_Event_T<TIME_POLICY>::ACE_Event_T (int manual_reset,
                                       int initial_state,
                                       int type,
                                       const ACE_TCHAR *name,
                                       void *arg,
                                       LPSECURITY_ATTRIBUTES sa)
  : ACE_Event_Base ()
{
  ACE_Condition_Attributes_T<TIME_POLICY> cond_attr (type);
  if (ACE_OS::event_init (&this->handle_,
                          type,
                          &const_cast<ACE_condattr_t&> (cond_attr.attributes ()),
                          manual_reset,
                          initial_state,
                          name,
                          arg,
                          sa) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Event_T<TIME_POLICY>::ACE_Event_T")));
}

template <class TIME_POLICY>
ACE_Event_T<TIME_POLICY>::~ACE_Event_T (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL
