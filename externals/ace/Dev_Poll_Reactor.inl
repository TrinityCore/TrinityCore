// -*- C++ -*-
//
// $Id: Dev_Poll_Reactor.inl 90177 2010-05-19 11:44:22Z vzykov $

#include "ace/Log_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Dev_Poll_Reactor::Event_Tuple::Event_Tuple (ACE_Event_Handler *eh,
                                                ACE_Reactor_Mask m,
                                                bool is_suspended,
                                                bool is_controlled)
  : event_handler (eh),
    mask (m),
    suspended (is_suspended),
    controlled (is_controlled)
{
}

// ---------------------------------------------------------------------

#if 0
ACE_INLINE
ACE_Dev_Poll_Ready_Set::ACE_Dev_Poll_Ready_Set (void)
  : pfds (0),
    nfds (0)
{
}
#endif  /* 0 */

// ---------------------------------------------------------------------

ACE_INLINE size_t
ACE_Dev_Poll_Reactor::Handler_Repository::size (void) const
{
  ACE_TRACE ("ACE_Dev_Poll_Reactor::Handler_Repository::size");

  return this->size_;
}

ACE_INLINE size_t
ACE_Dev_Poll_Reactor::Handler_Repository::max_size (void) const
{
  ACE_TRACE ("ACE_Dev_Poll_Reactor::Handler_Repository::max_size");

  return this->max_size_;
}

// -----------------------------------------------------------------

ACE_INLINE
ACE_Dev_Poll_Handler_Guard::ACE_Dev_Poll_Handler_Guard
  (ACE_Event_Handler *eh,
   bool do_incr)
  : eh_ (eh),
    refcounted_ (false)
{
  if (eh == 0)
    return;

  this->refcounted_ =
    eh->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;

  if (do_incr && this->refcounted_)
    eh->add_reference ();
}

ACE_INLINE
ACE_Dev_Poll_Handler_Guard::~ACE_Dev_Poll_Handler_Guard (void)
{
  if (this->refcounted_ && this->eh_ != 0)
    this->eh_->remove_reference ();
}

ACE_INLINE void
ACE_Dev_Poll_Handler_Guard::release (void)
{
  this->eh_ = 0;
}

// ---------------------------------------------------------------------

ACE_INLINE int
ACE_Dev_Poll_Reactor::upcall (ACE_Event_Handler *event_handler,
                              int (ACE_Event_Handler::*callback)(ACE_HANDLE),
                              ACE_HANDLE handle)
{
  // If the handler returns positive value (requesting a reactor
  // callback) just call back as many times as the handler requests
  // it.  The handler is suspended internally and other threads are off
  // handling other things.
  int status = 0;

  do
    {
      status = (event_handler->*callback) (handle);
    }
  while (status > 0 && event_handler != this->notify_handler_);

  return status;
}


/************************************************************************/
// Methods for ACE_Dev_Poll_Reactor::Token_Guard
/************************************************************************/

ACE_INLINE
ACE_Dev_Poll_Reactor::Token_Guard::Token_Guard (ACE_Dev_Poll_Reactor_Token &token)

  : token_ (token),
    owner_ (0)
{
}

ACE_INLINE
ACE_Dev_Poll_Reactor::Token_Guard::~Token_Guard (void)
{
  if (this->owner_ == 1)
    {
      ACE_MT (this->token_.release ());
      this->owner_ = 0;
    }
}

ACE_INLINE void
ACE_Dev_Poll_Reactor::Token_Guard::release_token (void)
{
  if (this->owner_)
    {
      ACE_MT (this->token_.release ());

      // We are not the owner anymore..
      this->owner_ = 0;
    }
}

ACE_INLINE int
ACE_Dev_Poll_Reactor::Token_Guard::is_owner (void)
{
  return this->owner_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
