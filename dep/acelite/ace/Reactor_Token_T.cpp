// $Id: Reactor_Token_T.cpp 82917 2008-10-03 19:10:56Z dai_y $

#include "ace/Log_Msg.h"
#include "ace/Reactor_Token_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class ACE_TOKEN_TYPE> void
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Reactor_Token_T::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class ACE_TOKEN_TYPE>
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::ACE_Reactor_Token_T
  (ACE_Reactor_Impl &r,
   int s_queue)
    : reactor_ (&r)
{
  ACE_TRACE ("ACE_Reactor_Token_T::ACE_Reactor_Token");

  this->queueing_strategy (s_queue);
}

template <class ACE_TOKEN_TYPE>
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::ACE_Reactor_Token_T (int s_queue)
  : reactor_ (0)
{
  ACE_TRACE ("ACE_Reactor_Token_T::ACE_Reactor_Token");

  this->queueing_strategy (s_queue);
}

template <class ACE_TOKEN_TYPE>
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::~ACE_Reactor_Token_T (void)
{
  ACE_TRACE ("ACE_Reactor_Token_T::~ACE_Reactor_Token_T");
}

template <class ACE_TOKEN_TYPE> ACE_Reactor_Impl &
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::reactor (void)
{
  return *this->reactor_;
}

template <class ACE_TOKEN_TYPE> void
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::reactor (ACE_Reactor_Impl &reactor)
{
  this->reactor_ = &reactor;
}

// Used to wakeup the reactor.

template <class ACE_TOKEN_TYPE> void
ACE_Reactor_Token_T<ACE_TOKEN_TYPE>::sleep_hook (void)
{
  ACE_TRACE ("ACE_Reactor_Token_T::sleep_hook");
  ACE_Time_Value ping = ACE_Time_Value::zero;
  if (this->reactor_->notify (0, ACE_Event_Handler::EXCEPT_MASK, &ping) == -1)
    {
      if (errno == ETIME)
        {
          errno = 0;
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%p\n"),
                      ACE_TEXT ("sleep_hook failed")));
        }
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
