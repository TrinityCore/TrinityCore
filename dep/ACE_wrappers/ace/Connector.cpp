// $Id: Connector.cpp 81991 2008-06-16 19:05:40Z elliott_c $

#ifndef ACE_CONNECTOR_CPP
#define ACE_CONNECTOR_CPP

#include "ace/Connector.h"
#include "ace/ACE.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"
#include "ace/os_include/os_fcntl.h"     /* Has ACE_NONBLOCK */

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Connector)

template <class SVC_HANDLER>
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::ACE_NonBlocking_Connect_Handler
(ACE_Connector_Base<SVC_HANDLER> &connector,
 SVC_HANDLER *sh,
 long id)
  : connector_ (connector)
  , svc_handler_ (sh)
  , timer_id_ (id)
{
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::ACE_NonBlocking_Connect_Handler");

  this->reference_counting_policy ().value
    (ACE_Event_Handler::Reference_Counting_Policy::ENABLED);
}

template <class SVC_HANDLER> SVC_HANDLER *
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::svc_handler (void)
{
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::svc_handler");
  return this->svc_handler_;
}

template <class SVC_HANDLER> long
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::timer_id (void)
{
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::timer_id");
  return this->timer_id_;
}

template <class SVC_HANDLER> void
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::timer_id (long id)
{
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::timer_id");
  this->timer_id_ = id;
}

template <class SVC_HANDLER> void
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("svc_handler_ = %x"), this->svc_handler_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\ntimer_id_ = %d"), this->timer_id_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER> bool
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::close (SVC_HANDLER *&sh)
{
  // Make sure that we haven't already initialized the Svc_Handler.
  if (!this->svc_handler_)
    return false;

  {
    // Exclusive access to the Reactor.
    ACE_GUARD_RETURN (ACE_Lock,
                      ace_mon,
                      this->reactor ()->lock (),
                      0);

    // Double check.
    if (!this->svc_handler_)
      return false;

    // Remember the Svc_Handler.
    sh = this->svc_handler_;
    ACE_HANDLE h = sh->get_handle ();
    this->svc_handler_ = 0;

    // Remove this handle from the set of non-blocking handles
    // in the Connector.
    this->connector_.non_blocking_handles ().remove (h);

    // Cancel timer.
    if (this->reactor ()->cancel_timer (this->timer_id (),
                                        0,
                                        0) == -1)
      return false;

    // Remove from Reactor.
    if (this->reactor ()->remove_handler (
          h,
          ACE_Event_Handler::ALL_EVENTS_MASK) == -1)
      return false;
  }

  return true;
}


template <class SVC_HANDLER> int
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_timeout
(const ACE_Time_Value &tv,
 const void *arg)
{
  // This method is called if a connection times out before completing.
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_timeout");

  SVC_HANDLER *svc_handler = 0;
  int retval = this->close (svc_handler) ? 0 : -1;

  // Forward to the SVC_HANDLER the <arg> that was passed in as a
  // magic cookie during ACE_Connector::connect().  This gives the
  // SVC_HANDLER an opportunity to take corrective action (e.g., wait
  // a few milliseconds and try to reconnect again.
  if (svc_handler != 0 && svc_handler->handle_timeout (tv, arg) == -1)
    svc_handler->handle_close (svc_handler->get_handle (),
                               ACE_Event_Handler::TIMER_MASK);

  return retval;
}


template <class SVC_HANDLER> int
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_input (ACE_HANDLE)
{
  // Called when a failure occurs during asynchronous connection
  // establishment.
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_input");

  SVC_HANDLER *svc_handler = 0;
  int const retval = this->close (svc_handler) ? 0 : -1;

  // Close Svc_Handler.
  if (svc_handler != 0)
    svc_handler->close (NORMAL_CLOSE_OPERATION);

  return retval;
}

template <class SVC_HANDLER> int
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_output (ACE_HANDLE handle)
{
  // Called when a connection is establishment asynchronous.
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_output");

  // Grab the connector ref before smashing ourselves in close().
  ACE_Connector_Base<SVC_HANDLER> &connector = this->connector_;
  SVC_HANDLER *svc_handler = 0;
  int const retval = this->close (svc_handler) ? 0 : -1;

  if (svc_handler != 0)
    connector.initialize_svc_handler (handle, svc_handler);

  return retval;
}

template <class SVC_HANDLER> int
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_exception (ACE_HANDLE h)
{
  // On Win32, the except mask must also be set for asynchronous
  // connects.
  ACE_TRACE ("ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::handle_exception");
  return this->handle_output (h);
}

template <class SVC_HANDLER> int
ACE_NonBlocking_Connect_Handler<SVC_HANDLER>::resume_handler (void)
{
  return ACE_Event_Handler::ACE_EVENT_HANDLER_NOT_RESUMED;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> void
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nflags_ = %d"), this->flags_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::make_svc_handler");

  if (sh == 0)
    ACE_NEW_RETURN (sh,
                    SVC_HANDLER,
                    -1);

  // Set the reactor of the newly created <SVC_HANDLER> to the same
  // reactor that this <Connector> is using.
  sh->reactor (this->reactor ());
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::activate_svc_handler (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::activate_svc_handler");
  // No errors initially
  int error = 0;

  // See if we should enable non-blocking I/O on the <svc_handler>'s
  // peer.
  if (ACE_BIT_ENABLED (this->flags_, ACE_NONBLOCK) != 0)
    {
      if (svc_handler->peer ().enable (ACE_NONBLOCK) == -1)
        error = 1;
    }
  // Otherwise, make sure it's disabled by default.
  else if (svc_handler->peer ().disable (ACE_NONBLOCK) == -1)
    error = 1;

  // We are connected now, so try to open things up.
  if (error || svc_handler->open ((void *) this) == -1)
    {
      // Make sure to close down the <svc_handler> to avoid descriptor
      // leaks.
      // The connection was already made; so this close is a "normal"
      // close operation.
      svc_handler->close (NORMAL_CLOSE_OPERATION);
      return -1;
    }
  else
    return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_PEER_CONNECTOR &
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connector (void) const
{
  return const_cast<ACE_PEER_CONNECTOR &> (this->connector_);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&svc_handler,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler");

  return this->connector_.connect (svc_handler->peer (),
                                   remote_addr,
                                   timeout,
                                   local_addr,
                                   reuse_addr,
                                   flags,
                                   perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&svc_handler,
 SVC_HANDLER *&sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler");

  sh_copy = svc_handler;
  return this->connector_.connect (svc_handler->peer (),
                                   remote_addr,
                                   timeout,
                                   local_addr,
                                   reuse_addr,
                                   flags,
                                   perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open (ACE_Reactor *r, int flags)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open");
  this->reactor (r);
  this->flags_ = flags;
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Connector (ACE_Reactor *r,
                                                                 int flags)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Connector");
  (void) this->open (r, flags);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 const ACE_Synch_Options &synch_options,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  // Initiate connection to peer.
  return this->connect_i (sh,
                          0,
                          remote_addr,
                          synch_options,
                          local_addr,
                          reuse_addr,
                          flags,
                          perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect
(SVC_HANDLER *&sh,
 SVC_HANDLER *&sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 const ACE_Synch_Options &synch_options,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  // Initiate connection to peer.
  return this->connect_i (sh,
                          &sh_copy,
                          remote_addr,
                          synch_options,
                          local_addr,
                          reuse_addr,
                          flags,
                          perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_i
(SVC_HANDLER *&sh,
 SVC_HANDLER **sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 const ACE_Synch_Options &synch_options,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_i");

  // If the user hasn't supplied us with a <SVC_HANDLER> we'll use the
  // factory method to create one.  Otherwise, things will remain as
  // they are...
  if (this->make_svc_handler (sh) == -1)
    return -1;

  ACE_Time_Value *timeout = 0;
  int const use_reactor = synch_options[ACE_Synch_Options::USE_REACTOR];

  if (use_reactor)
    timeout = const_cast<ACE_Time_Value *> (&ACE_Time_Value::zero);
  else
    timeout = const_cast<ACE_Time_Value *> (synch_options.time_value ());

  int result;
  if (sh_copy == 0)
    result = this->connect_svc_handler (sh,
                                        remote_addr,
                                        timeout,
                                        local_addr,
                                        reuse_addr,
                                        flags,
                                        perms);
  else
    result = this->connect_svc_handler (sh,
                                        *sh_copy,
                                        remote_addr,
                                        timeout,
                                        local_addr,
                                        reuse_addr,
                                        flags,
                                        perms);

  // Activate immediately if we are connected.
  if (result != -1)
    return this->activate_svc_handler (sh);

  // Delegate to connection strategy.
  if (use_reactor && ACE_OS::last_error () == EWOULDBLOCK)
    {
      // If the connection hasn't completed and we are using
      // non-blocking semantics then register
      // ACE_NonBlocking_Connect_Handler with the ACE_Reactor so that
      // it will call us back when the connection is complete or we
      // timeout, whichever comes first...
      int result;

      if (sh_copy == 0)
        result = this->nonblocking_connect (sh, synch_options);
      else
        result = this->nonblocking_connect (*sh_copy, synch_options);

      // If for some reason the <nonblocking_connect> call failed, then <errno>
      // will be set to the new error.  If the call succeeds, however,
      // we need to make sure that <errno> remains set to
      // <EWOULDBLOCK>.
      if (result == 0)
        errno = EWOULDBLOCK;
    }
  else
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);
      // Make sure to close down the service handler to avoid handle
      // leaks.
      if (sh_copy == 0)
        {
          if (sh)
            sh->close (CLOSE_DURING_NEW_CONNECTION);
        }
      else if (*sh_copy)
        (*sh_copy)->close (CLOSE_DURING_NEW_CONNECTION);
    }

  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_n
(size_t n,
 SVC_HANDLER *sh[],
 ACE_PEER_CONNECTOR_ADDR remote_addrs[],
 ACE_TCHAR *failed_svc_handlers,
 const ACE_Synch_Options &synch_options)
{
  int result = 0;

  for (size_t i = 0; i < n; i++)
    {
      if (this->connect (sh[i], remote_addrs[i], synch_options) == -1
          && !(synch_options[ACE_Synch_Options::USE_REACTOR]
               && errno == EWOULDBLOCK))
        {
          result = -1;
          if (failed_svc_handlers != 0)
            // Mark this entry as having failed.
            failed_svc_handlers[i] = 1;
        }
      else if (failed_svc_handlers != 0)
        // Mark this entry as having succeeded.
        failed_svc_handlers[i] = 0;
    }

  return result;
}

// Cancel a <svc_handler> that was started asynchronously.
template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::cancel (SVC_HANDLER *sh)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::cancel");

  ACE_Event_Handler *handler =
    this->reactor ()->find_handler (sh->get_handle ());

  if (handler == 0)
    return -1;

  // find_handler() increments handler's refcount; ensure we decrement it.
  ACE_Event_Handler_var safe_handler (handler);

  NBCH *nbch =
    dynamic_cast<NBCH *> (handler);

  if (nbch == 0)
    return -1;

  SVC_HANDLER *tmp_sh = 0;

  if (nbch->close (tmp_sh) == false)
    return -1;

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::nonblocking_connect
(SVC_HANDLER *sh,
 const ACE_Synch_Options &synch_options)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::nonblocking_connect");

  // Must have a valid Reactor for non-blocking connects to work.
  if (this->reactor () == 0)
    return -1;

  // Register the pending SVC_HANDLER so that it can be activated
  // later on when the connection completes.

  ACE_HANDLE handle = sh->get_handle ();
  long timer_id = -1;
  ACE_Time_Value *tv = 0;
  NBCH *nbch = 0;

  ACE_NEW_RETURN (nbch,
                  NBCH (*this,
                        sh,
                        -1),
                  -1);

  ACE_Event_Handler_var safe_nbch (nbch);

  // Exclusive access to the Reactor.
  ACE_GUARD_RETURN (ACE_Lock, ace_mon, this->reactor ()->lock (), -1);

  // Register handle with the reactor for connection events.
  ACE_Reactor_Mask mask = ACE_Event_Handler::CONNECT_MASK;
  if (this->reactor ()->register_handler (handle,
                                          nbch,
                                          mask) == -1)
    goto reactor_registration_failure;

  // Add handle to non-blocking handle set.
  this->non_blocking_handles ().insert (handle);

  // If we're starting connection under timer control then we need to
  // schedule a timeout with the ACE_Reactor.
  tv = const_cast<ACE_Time_Value *> (synch_options.time_value ());
  if (tv != 0)
    {
      timer_id =
        this->reactor ()->schedule_timer (nbch,
                                          synch_options.arg (),
                                          *tv);
      if (timer_id == -1)
        goto timer_registration_failure;

      // Remember timer id.
      nbch->timer_id (timer_id);
    }

  return 0;

  // Undo previous actions using the ol' "goto label and fallthru"
  // trick...
 timer_registration_failure:

  // Remove from Reactor.
  this->reactor ()->remove_handler (handle, mask);

  // Remove handle from the set of non-blocking handles.
  this->non_blocking_handles ().remove (handle);

  /* FALLTHRU */

 reactor_registration_failure:
  // Close the svc_handler

  sh->close (CLOSE_DURING_NEW_CONNECTION);

  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Connector (void)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Connector");

  this->close ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> void
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::initialize_svc_handler
(ACE_HANDLE handle,
 SVC_HANDLER *svc_handler)
{
  // Try to find out if the reactor uses event associations for the
  // handles it waits on. If so we need to reset it.
  int reset_new_handle =
    this->reactor ()->uses_event_associations ();

  if (reset_new_handle)
    this->connector_.reset_new_handle (handle);

  // Transfer ownership of the ACE_HANDLE to the SVC_HANDLER.
  svc_handler->set_handle (handle);

  ACE_PEER_CONNECTOR_ADDR raddr;

  // Check to see if we're connected.
  if (svc_handler->peer ().get_remote_addr (raddr) != -1)
    this->activate_svc_handler (svc_handler);
  else // Somethings gone wrong, so close down...
    {
#if defined (ACE_WIN32)
      // Win32 (at least prior to Windows 2000) has a timing problem.
      // If you check to see if the connection has completed too fast,
      // it will fail - so wait 35 milliseconds to let it catch up.
      ACE_Time_Value tv (0, ACE_NON_BLOCKING_BUG_DELAY);
      ACE_OS::sleep (tv);
      if (svc_handler->peer ().get_remote_addr (raddr) != -1)
        this->activate_svc_handler (svc_handler);
      else // do the svc handler close below...
#endif /* ACE_WIN32 */
        svc_handler->close (NORMAL_CLOSE_OPERATION);
    }
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> void
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::reactor (ACE_Reactor *reactor)
{
  this->reactor_ = reactor;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_Reactor *
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::reactor (void) const
{
  return this->reactor_;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_Unbounded_Set<ACE_HANDLE> &
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::non_blocking_handles (void)
{
  return this->non_blocking_handles_;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::close (void)
{
  // If there are no non-blocking handle pending, return immediately.
  if (this->non_blocking_handles ().size () == 0)
    return 0;

  // Exclusive access to the Reactor.
  ACE_GUARD_RETURN (ACE_Lock, ace_mon, this->reactor ()->lock (), -1);

  // Go through all the non-blocking handles.  It is necessary to
  // create a new iterator each time because we remove from the handle
  // set when we cancel the Svc_Handler.
  ACE_HANDLE *handle = 0;
  while (1)
    {
      ACE_Unbounded_Set_Iterator<ACE_HANDLE>
        iterator (this->non_blocking_handles ());
      if (!iterator.next (handle))
        break;

      ACE_Event_Handler *handler =
        this->reactor ()->find_handler (*handle);
      if (handler == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%t: Connector::close h %d, no handler\n"),
                      *handle));
          // Remove handle from the set of non-blocking handles.
          this->non_blocking_handles ().remove (*handle);
          continue;
        }

      // find_handler() incremented handler's refcount; ensure it's decremented
      ACE_Event_Handler_var safe_handler (handler);
      NBCH *nbch = dynamic_cast<NBCH *> (handler);
      if (nbch == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("%t: Connector::close h %d handler %@ ")
                      ACE_TEXT ("not a legit handler\n"),
                      *handle,
                      handler));
          // Remove handle from the set of non-blocking handles.
          this->non_blocking_handles ().remove (*handle);
          continue;
        }
      SVC_HANDLER *svc_handler = nbch->svc_handler ();

      // Cancel the non-blocking connection.
      this->cancel (svc_handler);

      // Close the associated Svc_Handler.
      svc_handler->close (NORMAL_CLOSE_OPERATION);
    }

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::fini (void)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::fini");

  return this->close ();
}

// Hook called by the explicit dynamic linking facility.

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::init");
  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::suspend (void)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::suspend");
  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::resume (void)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::resume");
  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::info (ACE_TCHAR **strp, size_t length) const
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::info");
  ACE_TCHAR buf[BUFSIZ];

  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s\t %s"),
                   ACE_TEXT ("ACE_Connector"),
                   ACE_TEXT ("# connector factory\n"));

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, buf, length);
  return static_cast<int> (ACE_OS::strlen (buf));
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open (ACE_Reactor *r,
                                                                 int flags)
{
  ACE_TRACE ("ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open");
  return this->open (r, 0, 0, 0, flags);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open
(ACE_Reactor *r,
 ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
 ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> *conn_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 int flags)
{
  ACE_TRACE ("ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::open");

  this->reactor (r);

  // @@ Not implemented yet.
  // this->flags_ = flags;
  ACE_UNUSED_ARG (flags);

  // Initialize the creation strategy.

  // First we decide if we need to clean up.
  if (this->creation_strategy_ != 0 &&
      this->delete_creation_strategy_ &&
      cre_s != 0)
    {
      delete this->creation_strategy_;
      this->creation_strategy_ = 0;
      this->delete_creation_strategy_ = false;
    }

  if (cre_s != 0)
    this->creation_strategy_ = cre_s;
  else if (this->creation_strategy_ == 0)
    {
      ACE_NEW_RETURN (this->creation_strategy_,
                      CREATION_STRATEGY,
                      -1);
      this->delete_creation_strategy_ = true;
    }


  // Initialize the accept strategy.

  if (this->connect_strategy_ != 0 &&
      this->delete_connect_strategy_ &&
      conn_s != 0)
    {
      delete this->connect_strategy_;
      this->connect_strategy_ = 0;
      this->delete_connect_strategy_ = false;
    }

  if (conn_s != 0)
    this->connect_strategy_ = conn_s;
  else if (this->connect_strategy_ == 0)
    {
      ACE_NEW_RETURN (this->connect_strategy_,
                      CONNECT_STRATEGY,
                      -1);
      this->delete_connect_strategy_ = true;
    }

  // Initialize the concurrency strategy.

  if (this->concurrency_strategy_ != 0 &&
      this->delete_concurrency_strategy_ &&
      con_s != 0)
    {
      delete this->concurrency_strategy_;
      this->concurrency_strategy_ = 0;
      this->delete_concurrency_strategy_ = false;
    }

  if (con_s != 0)
    this->concurrency_strategy_ = con_s;
  else if (this->concurrency_strategy_ == 0)
    {
      ACE_NEW_RETURN (this->concurrency_strategy_,
                      CONCURRENCY_STRATEGY,
                      -1);
      this->delete_concurrency_strategy_ = true;
    }

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Strategy_Connector
(ACE_Reactor *reactor,
 ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
 ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> *conn_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 int flags)
  : creation_strategy_ (0),
    delete_creation_strategy_ (false),
    connect_strategy_ (0),
    delete_connect_strategy_ (false),
    concurrency_strategy_ (0),
    delete_concurrency_strategy_ (false)
{
  ACE_TRACE ("ACE_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::ACE_Strategy_Connector");

  if (this->open (reactor, cre_s, conn_s, con_s, flags) == -1)
    ACE_ERROR ((LM_ERROR,  ACE_TEXT ("%p\n"),  ACE_TEXT ("ACE_Strategy_Connector::ACE_Strategy_Connector")));
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Strategy_Connector (void)
{
  ACE_TRACE ("ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Strategy_Connector");

  // Close down
  this->close ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::close (void)
{
  if (this->delete_creation_strategy_)
    delete this->creation_strategy_;
  this->delete_creation_strategy_ = false;
  this->creation_strategy_ = 0;

  if (this->delete_connect_strategy_)
    delete this->connect_strategy_;
  this->delete_connect_strategy_ = false;
  this->connect_strategy_ = 0;

  if (this->delete_concurrency_strategy_)
    delete this->concurrency_strategy_;
  this->delete_concurrency_strategy_ = false;
  this->concurrency_strategy_ = 0;

  return SUPER::close ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::make_svc_handler (SVC_HANDLER *&sh)
{
  return this->creation_strategy_->make_svc_handler (sh);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  return this->connect_strategy_->connect_svc_handler (sh,
                                                       remote_addr,
                                                       timeout,
                                                       local_addr,
                                                       reuse_addr,
                                                       flags,
                                                       perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&sh,
 SVC_HANDLER *&sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  return this->connect_strategy_->connect_svc_handler (sh,
                                                       sh_copy,
                                                       remote_addr,
                                                       timeout,
                                                       local_addr,
                                                       reuse_addr,
                                                       flags,
                                                       perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::activate_svc_handler (SVC_HANDLER *svc_handler)
{
  return this->concurrency_strategy_->activate_svc_handler (svc_handler, this);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_Creation_Strategy<SVC_HANDLER> *
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::creation_strategy (void) const
{
  return this->creation_strategy_;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2> *
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_strategy (void) const
{
  return this->connect_strategy_;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_Concurrency_Strategy<SVC_HANDLER> *
ACE_Strategy_Connector<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::concurrency_strategy (void) const
{
  return this->concurrency_strategy_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CONNECTOR_C */
