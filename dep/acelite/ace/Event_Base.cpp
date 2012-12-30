// $Id: Event_Base.cpp 96220 2012-11-06 10:03:41Z mcorino $

#include "ace/Event_Base.h"

#if !defined (__ACE_INLINE__)
#include "ace/Event_Base.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Event_Base::ACE_Event_Base ()
  : removed_ (false)
{
}

ACE_Event_Base::~ACE_Event_Base (void)
{
  this->remove ();
}

int
ACE_Event_Base::remove (void)
{
  int result = 0;
  if (!this->removed_)
    {
      this->removed_ = true;
      result = ACE_OS::event_destroy (&this->handle_);
    }
  return result;
}

int
ACE_Event_Base::wait (void)
{
  return ACE_OS::event_wait (&this->handle_);
}

int
ACE_Event_Base::wait (const ACE_Time_Value *abstime, int use_absolute_time)
{
  return ACE_OS::event_timedwait (&this->handle_,
                                  const_cast <ACE_Time_Value *> (abstime),
                                  use_absolute_time);
}

int
ACE_Event_Base::signal (void)
{
  return ACE_OS::event_signal (&this->handle_);
}

int
ACE_Event_Base::pulse (void)
{
  return ACE_OS::event_pulse (&this->handle_);
}

int
ACE_Event_Base::reset (void)
{
  return ACE_OS::event_reset (&this->handle_);
}

void
ACE_Event_Base::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL
