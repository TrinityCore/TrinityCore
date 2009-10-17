// $Id: Event.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Event.h"
#if !defined (__ACE_INLINE__)
#include "ace/Event.inl"
#endif /* __ACE_INLINE__ */
#include "ace/Log_Msg.h"
ACE_RCSID(ace, Event, "$Id: Event.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Event::ACE_Event (int manual_reset,
                      int initial_state,
                      int type,
                      const ACE_TCHAR *name,
                      void *arg,
                      LPSECURITY_ATTRIBUTES sa)
  : removed_ (false)
{
  if (ACE_OS::event_init (&this->handle_,
                          manual_reset,
                          initial_state,
                          type,
                          name,
                          arg,
                          sa) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Event::ACE_Event")));
}
ACE_Event::~ACE_Event (void)
{
  this->remove ();
}
int
ACE_Event::remove (void)
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
ACE_Event::wait (void)
{
  return ACE_OS::event_wait (&this->handle_);
}
int
ACE_Event::wait (const ACE_Time_Value *abstime, int use_absolute_time)
{
  return ACE_OS::event_timedwait (&this->handle_,
                                  const_cast <ACE_Time_Value *> (abstime),
                                  use_absolute_time);
}
int
ACE_Event::signal (void)
{
  return ACE_OS::event_signal (&this->handle_);
}
int
ACE_Event::pulse (void)
{
  return ACE_OS::event_pulse (&this->handle_);
}
int
ACE_Event::reset (void)
{
  return ACE_OS::event_reset (&this->handle_);
}
void
ACE_Event::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
ACE_END_VERSIONED_NAMESPACE_DECL

