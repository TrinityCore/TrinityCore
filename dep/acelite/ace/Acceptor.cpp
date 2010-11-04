// $Id: Acceptor.cpp 91623 2010-09-06 09:30:59Z sma $

#ifndef ACE_ACCEPTOR_CPP
#define ACE_ACCEPTOR_CPP

#include "ace/ACE.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Acceptor.h"
#include "ace/Svc_Handler.h"
#include "ace/WFMO_Reactor.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Acceptor)

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> void
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->peer_acceptor_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR & () const
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR &");
  return (ACE_PEER_ACCEPTOR &) this->peer_acceptor_;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_PEER_ACCEPTOR &
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor (void) const
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor");
  return const_cast<ACE_PEER_ACCEPTOR &> (this->peer_acceptor_);
}

// Returns ACE_HANDLE of the underlying Acceptor_Strategy.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_HANDLE
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle (void) const
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle");
  return this->peer_acceptor_.get_handle ();
}

// Initialize the appropriate strategies for creation, passive
// connection acceptance, and concurrency, and then register <this>
// with the Reactor and listen for connection requests at the
// designated <local_addr>.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   ACE_Reactor *reactor,
   int flags,
   int use_select,
   int reuse_addr)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open");
  this->flags_ = flags;
  this->use_select_ = use_select;
  this->reuse_addr_ = reuse_addr;
  this->peer_acceptor_addr_ = local_addr;

  // Must supply a valid Reactor to Acceptor::open()...

  if (reactor == 0)
    {
      errno = EINVAL;
      return -1;
    }

  if (this->peer_acceptor_.open (local_addr, reuse_addr) == -1)
    return -1;

  // Set the peer acceptor's handle into non-blocking mode.  This is a
  // safe-guard against the race condition that can otherwise occur
  // between the time when <select> indicates that a passive-mode
  // socket handle is "ready" and when we call <accept>.  During this
  // interval, the client can shutdown the connection, in which case,
  // the <accept> call can hang!
  (void) this->peer_acceptor_.enable (ACE_NONBLOCK);

  int const result = reactor->register_handler (this,
                                                ACE_Event_Handler::ACCEPT_MASK);
  if (result != -1)
    this->reactor (reactor);
  else
    this->peer_acceptor_.close ();

  return result;
}

// Simple constructor.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Acceptor (ACE_Reactor *reactor,
                                                              int use_select)
  :flags_ (0),
   use_select_ (use_select),
   reuse_addr_ (1)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Acceptor");

  this->reactor (reactor);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Acceptor
  (const ACE_PEER_ACCEPTOR_ADDR &addr,
   ACE_Reactor *reactor,
   int flags,
   int use_select,
   int reuse_addr)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Acceptor");

  if (this->open (addr,
                  reactor,
                  flags,
                  use_select,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Acceptor::ACE_Acceptor")));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Acceptor (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Acceptor");
  this->handle_close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini");
  return ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close ();
}

// Hook called by the explicit dynamic linking facility.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::init");
  return -1;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::info (ACE_TCHAR **strp,
                                                      size_t length) const
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::info");
  ACE_TCHAR buf[BUFSIZ];
  ACE_TCHAR addr_str[BUFSIZ];
  ACE_PEER_ACCEPTOR_ADDR addr;

  if (this->acceptor ().get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (addr_str, sizeof addr_str) == -1)
    return -1;

  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s\t %s %s"),
                   ACE_TEXT ("ACE_Acceptor"),
                   addr_str,
                   ACE_TEXT ("# acceptor factory\n"));

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, buf, length);
  return static_cast<int> (ACE_OS::strlen (buf));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend");
  return this->reactor ()->suspend_handler (this);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume");
  return this->reactor ()->resume_handler (this);
}

// Perform termination activities when <this> is removed from the
// <reactor>.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::close (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::close");
  return this->handle_close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_accept_error (void)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_accept_error");
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close (ACE_HANDLE,
                                                              ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close");
  // Guard against multiple closes.
  if (this->reactor () != 0)
    {
      ACE_HANDLE handle = this->get_handle ();

      this->reactor ()->remove_handler
        (handle,
         // We must pass the DONT_CALL flag here to avoid infinite
         // recursion.
         ACE_Event_Handler::ACCEPT_MASK | ACE_Event_Handler::DONT_CALL);

      // Shut down the listen socket to recycle the handles.
      if (this->peer_acceptor_.close () == -1)
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("close\n")));
      // Set the Reactor to 0 so that we don't try to close down
      // again.
      this->reactor (0);
    }
  return 0;
}

// Bridge method for creating a SVC_HANDLER.  The strategy for
// creating a SVC_HANDLER are configured into the Acceptor via it's
// <creation_strategy_>.  The default is to create a new SVC_HANDLER.
// However, subclasses can override this strategy to perform
// SVC_HANDLER creation in any way that they like (such as creating
// subclass instances of SVC_HANDLER, using a singleton, dynamically
// linking the handler, etc.).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::make_svc_handler");

  if (sh == 0)
    ACE_NEW_RETURN (sh,
                    SVC_HANDLER,
                    -1);

  // Set the reactor of the newly created <SVC_HANDLER> to the same
  // reactor that this <ACE_Acceptor> is using.
  sh->reactor (this->reactor ());
  return 0;
}

// Bridge method for accepting the new connection into the
// <svc_handler>.  The default behavior delegates to the
// <PEER_ACCEPTOR::accept> in the Acceptor_Strategy.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler");

  // Try to find out if the implementation of the reactor that we are
  // using requires us to reset the event association for the newly
  // created handle. This is because the newly created handle will
  // inherit the properties of the listen handle, including its event
  // associations.

  ACE_Reactor *reactor = this->reactor ();
  bool reset_new_handle;

  if (reactor)
    reset_new_handle = reactor->uses_event_associations ();
  else
    {
      // Acceptor is closed, so reject this call
      errno = EINVAL;
      return -1;
    }

  if (this->acceptor ().accept (svc_handler->peer (), // stream
                                0, // remote address
                                0, // timeout
                                true, // restart
                                reset_new_handle  // reset new handler
                                ) == -1)
    {
      // Ensure that errno is preserved in case the svc_handler
      // close() method resets it
      ACE_Errno_Guard error(errno);

      // Close down handler to avoid memory leaks.
      svc_handler->close (CLOSE_DURING_NEW_CONNECTION);

      return -1;
    }
  else
    return 0;
}

// Bridge method for activating a <svc_handler> with the appropriate
// concurrency strategy.  The default behavior of this method is to
// activate the SVC_HANDLER by calling its open() method (which allows
// the SVC_HANDLER to define its own concurrency strategy).  However,
// subclasses can override this strategy to do more sophisticated
// concurrency activations (such as creating the SVC_HANDLER as an
// "active object" via multi-threading or multi-processing).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler");

  int result = 0;

  // See if we should enable non-blocking I/O on the <svc_handler>'s
  // peer.
  if (ACE_BIT_ENABLED (this->flags_,
                       ACE_NONBLOCK))
    {
      if (svc_handler->peer ().enable (ACE_NONBLOCK) == -1)
        result = -1;
    }
  // Otherwise, make sure it's disabled by default.
  else if (svc_handler->peer ().disable (ACE_NONBLOCK) == -1)
    result = -1;

  if (result == 0 && svc_handler->open ((void *) this) == -1)
    result = -1;

  if (result == -1)
    // The connection was already made; so this close is a "normal" close
    // operation.
    svc_handler->close (NORMAL_CLOSE_OPERATION);

  return result;
}

// Template Method that makes a SVC_HANDLER (using the appropriate
// creation strategy), accept the connection into the SVC_HANDLER, and
// then activate the SVC_HANDLER.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_input (ACE_HANDLE listener)
{
  ACE_TRACE ("ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_input");

  // Default is "timeout (0, 0)," which means "poll."
  ACE_Time_Value timeout;

  // Accept connections from clients.  Note that a loop is used for two
  // reasons:
  //
  // 1. It allows us to accept all pending connections without an
  //    extra trip through the ACE_Reactor and without having to use
  //    non-blocking I/O...
  //
  // 2. It allows the TLI_SAP::ACE_Acceptor class to work correctly (don't
  //    ask -- TLI is *horrible*...).

  // Ensure that errno is preserved in case the ACE::handle_read_ready()
  // method resets it in the loop bellow. We are actually supposed to
  // ignore any errors from this loop, hence the return 0 following it.
  ACE_Errno_Guard error (errno);

  // @@ What should we do if any of the substrategies fail?  Right
  // now, we just print out a diagnostic message if <ACE::debug>
  // returns > 0 and return 0 (which means that the Acceptor remains
  // registered with the Reactor)...
  do
    {
      // Create a service handler, using the appropriate creation
      // strategy.

      SVC_HANDLER *svc_handler = 0;

      if (this->make_svc_handler (svc_handler) == -1)
        {
          if (ACE::debug ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("make_svc_handler")));
            }
          return 0;
        }
      // Accept connection into the Svc_Handler.
      else if (this->accept_svc_handler (svc_handler) == -1)
        {
          // Note that <accept_svc_handler> closes the <svc_handler>
          // on failure.
          if (ACE::debug ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("accept_svc_handler")));
            }
          const int ret = this->handle_accept_error ();
          if (ret == -1)
            {
              // Ensure that the errno from the above call propegates.
              error = errno;
            }
          return ret;
        }
      // Activate the <svc_handler> using the designated concurrency
      // strategy (note that this method becomes responsible for
      // handling errors and freeing up the memory if things go
      // awry...).
      else if (this->activate_svc_handler (svc_handler) == -1)
        {
          // Note that <activate_svc_handler> closes the <svc_handler>
          // on failure.

          if (ACE::debug ())
            {
              ACE_DEBUG ((LM_DEBUG,
                          ACE_TEXT ("%p\n"),
                          ACE_TEXT ("activate_svc_handler")));
            }
          return 0;
        }
      // Now, check to see if there is another connection pending and
      // break out of the loop if there is none.
    } while (this->use_select_ &&
             ACE::handle_read_ready (listener, &timeout) == 1);
  return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Strategy_Acceptor)

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend (void)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend");

  // First suspend the SVC_HANDLER's we've created.
  if (this->scheduling_strategy_->suspend () == -1)
    return -1;
  else   // Then suspend ourselves.
    return ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume (void)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume");

  // First resume ourselves.
  if (ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume () == -1)
    return -1;
  else // Then resume the SVC_HANDLER's we've created.
    return this->scheduling_strategy_->resume ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> void
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump ();
  this->creation_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("delete_creation_strategy_ = %d"), delete_creation_strategy_));
  this->accept_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("delete_accept_strategy_ = %d"), delete_accept_strategy_));
  this->concurrency_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("delete_concurrency_strategy_ = %d"), delete_concurrency_strategy_));
  this->scheduling_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("delete_scheduling_strategy_ = %d"), delete_scheduling_strategy_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nservice_name_ = %s"),
              this->service_name_ == 0 ? ACE_TEXT ("<unknown>") : this->service_name_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nservice_description_ = %s"),
              this->service_description_ == 0 ? ACE_TEXT ("<unknown>") : this->service_description_));
  this->service_addr_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_PEER_ACCEPTOR &
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor (void) const
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor");
  return this->accept_strategy_->acceptor ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR & () const
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR &");
  return this->accept_strategy_->acceptor ();
}

// Returns ACE_HANDLE of the underlying Acceptor_Strategy.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_HANDLE
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle (void) const
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle");
  return this->accept_strategy_->get_handle ();
}

// Initialize the appropriate strategies for creation, passive
// connection acceptance, and concurrency, and then register <this>
// with the Reactor and listen for connection requests at the
// designated <local_addr>.
template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   ACE_Reactor *reactor,
   int /* flags unused */,
   int use_select,
   int reuse_addr)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open");
  return this->open
    (local_addr, reactor, 0, 0, 0, 0, 0, 0, use_select, reuse_addr);
}


template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   ACE_Reactor *reactor,
   ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
   ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2> *acc_s,
   ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
   ACE_Scheduling_Strategy<SVC_HANDLER> *sch_s,
   const ACE_TCHAR *service_name,
   const ACE_TCHAR *service_description,
   int use_select,
   int reuse_addr)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open");

  if (this->service_name_ == 0 && service_name != 0)
    ACE_ALLOCATOR_RETURN (this->service_name_,
                          ACE_OS::strdup (service_name),
                          -1);
  if (this->service_description_ == 0 && service_description != 0)
    ACE_ALLOCATOR_RETURN (this->service_description_,
                          ACE_OS::strdup (service_description),
                          -1);
  this->reactor (reactor);

  // Must supply a valid Reactor to Acceptor::open()...
  if (reactor == 0)
    {
      errno = EINVAL;
      return -1;
    }

  // Initialize the creation strategy.

  if (cre_s == 0)
    {
      ACE_NEW_RETURN (cre_s,
                      CREATION_STRATEGY,
                      -1);
      this->delete_creation_strategy_ = true;
    }
  this->creation_strategy_ = cre_s;

  // Initialize the accept strategy.

  if (acc_s == 0)
    {
      ACE_NEW_RETURN (acc_s,
                      ACCEPT_STRATEGY (this->reactor ()),
                      -1);
      this->delete_accept_strategy_ = true;
    }
  this->accept_strategy_ = acc_s;

  if (this->accept_strategy_->open (local_addr, reuse_addr) == -1)
    return -1;

  // Set the peer acceptor's handle into non-blocking mode.  This is a
  // safe-guard against the race condition that can otherwise occur
  // between the time when <select> indicates that a passive-mode
  // socket handle is "ready" and when we call <accept>.  During this
  // interval, the client can shutdown the connection, in which case,
  // the <accept> call can hang!
  if (this->accept_strategy_->acceptor ().enable (ACE_NONBLOCK) != 0)
    return -1;

  // Initialize the concurrency strategy.

  if (con_s == 0)
    {
      ACE_NEW_RETURN (con_s,
                      CONCURRENCY_STRATEGY,
                      -1);
      this->delete_concurrency_strategy_ = true;
    }
  this->concurrency_strategy_ = con_s;

  // Initialize the scheduling strategy.

  if (sch_s == 0)
    {
      ACE_NEW_RETURN (sch_s,
                      SCHEDULING_STRATEGY,
                      -1);
      this->delete_scheduling_strategy_ = true;
    }
  this->scheduling_strategy_ = sch_s;

  this->use_select_ = use_select;

  return this->reactor ()->register_handler
    (this,
     ACE_Event_Handler::ACCEPT_MASK);
}

// Simple constructor.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Strategy_Acceptor
  (const ACE_TCHAR service_name[],
   const ACE_TCHAR service_description[],
   int use_select,
   int reuse_addr)
    : creation_strategy_ (0),
      delete_creation_strategy_ (false),
      accept_strategy_ (0),
      delete_accept_strategy_ (false),
      concurrency_strategy_ (0),
      delete_concurrency_strategy_ (false),
      scheduling_strategy_ (0),
      delete_scheduling_strategy_ (false),
      service_name_ (0),
      service_description_ (0)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Strategy_Acceptor");

  if (service_name != 0)
    ACE_ALLOCATOR (this->service_name_,
                   ACE_OS::strdup (service_name));
  if (service_description != 0)
    ACE_ALLOCATOR (this->service_description_,
                   ACE_OS::strdup (service_description));
  this->use_select_ = use_select;
  this->reuse_addr_ = reuse_addr;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Strategy_Acceptor
  (const ACE_PEER_ACCEPTOR_ADDR &addr,
   ACE_Reactor *reactor,
   ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
   ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2> *acc_s,
   ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
   ACE_Scheduling_Strategy<SVC_HANDLER> *sch_s,
   const ACE_TCHAR service_name[],
   const ACE_TCHAR service_description[],
   int use_select,
   int reuse_addr)
    : creation_strategy_ (0),
      delete_creation_strategy_ (false),
      accept_strategy_ (0),
      delete_accept_strategy_ (false),
      concurrency_strategy_ (0),
      delete_concurrency_strategy_ (false),
      scheduling_strategy_ (0),
      delete_scheduling_strategy_ (false),
      service_name_ (0),
      service_description_ (0)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Strategy_Acceptor");

  if (this->open (addr,
                  reactor,
                  cre_s,
                  acc_s,
                  con_s,
                  sch_s,
                  service_name,
                  service_description,
                  use_select,
                  reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Strategy_Acceptor::ACE_Strategy_Acceptor")));
}

// Perform termination activities when <this> is removed from the
// <ACE_Reactor>.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close (ACE_HANDLE,
                                                                       ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close");
  // Guard against multiple closes.
  if (this->reactor () != 0)
    {
      ACE_HANDLE handle = this->get_handle ();

      if (this->delete_creation_strategy_)
        delete this->creation_strategy_;
      this->delete_creation_strategy_ = false;
      this->creation_strategy_ = 0;

      if (this->delete_accept_strategy_)
        delete this->accept_strategy_;
      this->delete_accept_strategy_ = false;
      this->accept_strategy_ = 0;

      if (this->delete_concurrency_strategy_)
        delete this->concurrency_strategy_;
      this->delete_concurrency_strategy_ = false;
      this->concurrency_strategy_ = 0;

      if (this->delete_scheduling_strategy_)
        delete this->scheduling_strategy_;
      this->delete_scheduling_strategy_ = false;
      this->scheduling_strategy_ = 0;

      // We must use the <handle> obtained *before* we deleted the
      // accept_strategy_...

      this->reactor ()->remove_handler
        (handle,
         ACE_Event_Handler::ACCEPT_MASK | ACE_Event_Handler::DONT_CALL);

      // Set the Reactor to 0 so that we don't try to close down
      // again.
      this->reactor (0);
    }
  return 0;
}

// Bridge method for creating a <SVC_HANDLER>.  The strategy for
// creating a <SVC_HANDLER> are configured into the Acceptor via it's
// <creation_strategy_>.  The default is to create a new
// <SVC_HANDLER>.  However, subclasses can override this strategy to
// perform <SVC_HANDLER> creation in any way that they like (such as
// creating subclass instances of <SVC_HANDLER>, using a singleton,
// dynamically linking the handler, etc.).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::make_svc_handler");
  return this->creation_strategy_->make_svc_handler (sh);
}

// Bridge method for accepting the new connection into the
// <svc_handler>.  The default behavior delegates to the
// <Strategy_Acceptor::accept> in the Acceptor_Strategy.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler");
  return this->accept_strategy_->accept_svc_handler (svc_handler);
}

// Bridge method for activating a <svc_handler> with the appropriate
// concurrency strategy.  The default behavior of this method is to
// activate the SVC_HANDLER by calling its open() method (which allows
// the SVC_HANDLER to define its own concurrency strategy).  However,
// subclasses can override this strategy to do more sophisticated
// concurrency activations (such as creating the SVC_HANDLER as an
// "active object" via multi-threading or multi-processing).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler");
  return this->concurrency_strategy_->activate_svc_handler
    (svc_handler,
     (void *) this);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Strategy_Acceptor (void)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Strategy_Acceptor");
  ACE_OS::free ((void *) this->service_name_);
  ACE_OS::free ((void *) this->service_description_);
  this->handle_close ();
}

// Signal the server to shutdown gracefully.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_signal (int, siginfo_t *, ucontext_t *)
{
  ACE_Reactor::instance()->end_reactor_event_loop ();
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::info (ACE_TCHAR **strp,
                                                               size_t length) const
{
  ACE_TRACE ("ACE_Strategy_Acceptor::info");

  ACE_TCHAR buf[BUFSIZ];
  ACE_TCHAR service_addr_str[BUFSIZ];
  ACE_PEER_ACCEPTOR_ADDR addr;

  if (this->acceptor ().get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (service_addr_str,
                                sizeof service_addr_str) == -1)
    return -1;

  // @@ Should add the protocol in...
  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s\t %s #%s\n"),
                   this->service_name_ == 0
                   ? ACE_TEXT ("<unknown>")
                   : this->service_name_,
                   service_addr_str,
                   this->service_description_ == 0
                   ? ACE_TEXT ("<unknown>")
                   : this->service_description_);

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, buf, length);
  return static_cast<int> (ACE_OS::strlen (buf));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini (void)
{
  ACE_TRACE ("ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini");
  return this->ACE_Strategy_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close ();
}

ACE_ALLOC_HOOK_DEFINE(ACE_Oneshot_Acceptor)

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> void
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nsvc_handler_ = %x"), this->svc_handler_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("\nrestart_ = %d"), this->restart_));
  this->peer_acceptor_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("delete_concurrency_strategy_ = %d"),
              delete_concurrency_strategy_));
  this->concurrency_strategy_->dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   ACE_Reactor *reactor,
   ACE_Concurrency_Strategy<SVC_HANDLER> *con_s)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open");
  this->reactor (reactor);

  // Initialize the concurrency strategy.

  if (con_s == 0)
    {
      ACE_NEW_RETURN (con_s,
                      ACE_Concurrency_Strategy<SVC_HANDLER>,
                      -1);
      this->delete_concurrency_strategy_ = true;
    }
  this->concurrency_strategy_ = con_s;

  // Reuse the addr, even if it is already in use...!
  return this->peer_acceptor_.open (local_addr, 1);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Oneshot_Acceptor (void)
  : delete_concurrency_strategy_ (false)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Oneshot_Acceptor");
  this->reactor (0);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Oneshot_Acceptor
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   ACE_Reactor *reactor,
   ACE_Concurrency_Strategy<SVC_HANDLER> *cs)
    : delete_concurrency_strategy_ (false)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Oneshot_Acceptor");
  if (this->open (local_addr, reactor, cs) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Oneshot_Acceptor::ACE_Oneshot_Acceptor")));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Oneshot_Acceptor (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Oneshot_Acceptor");
  this->handle_close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::close (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::close");
  return this->handle_close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close (ACE_HANDLE,
                                                                      ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_close");

  // Guard against multiple closes.
  if (this->delete_concurrency_strategy_)
    {
      delete this->concurrency_strategy_;
      this->delete_concurrency_strategy_ = false;
      this->concurrency_strategy_ = 0;
    }
  // Note that if we aren't actually registered with the
  // ACE_Reactor then it's ok for this call to fail...

  if (this->reactor ())
    this->reactor ()->remove_handler
      (this,
       ACE_Event_Handler::ACCEPT_MASK | ACE_Event_Handler::DONT_CALL);

  if (this->peer_acceptor_.close () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("close\n")));
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_timeout
  (const ACE_Time_Value &tv,
   const void *arg)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_timeout");
  errno = ETIME;

  if (this->svc_handler_->handle_timeout (tv, arg) == -1)
    this->svc_handler_->handle_close (this->svc_handler_->get_handle (),
                                      ACE_Event_Handler::TIMER_MASK);

  // Since we aren't necessarily registered with the Reactor, don't
  // bother to check the return value here...
  if (this->reactor ())
    this->reactor ()->remove_handler (this,
                                      ACE_Event_Handler::ACCEPT_MASK);
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::cancel (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::cancel");
  return this->reactor () && this->reactor ()->cancel_timer (this);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::register_handler
  (SVC_HANDLER *svc_handler,
   const ACE_Synch_Options &synch_options,
   bool restart)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::register_handler");
  // Can't do this if we don't have a Reactor.
  if (this->reactor () == 0)
    {
      errno = EINVAL;
      return -1;
    }
  else
    {
      this->svc_handler_ = svc_handler;
      this->restart_ = restart;
      ACE_Time_Value *tv = (ACE_Time_Value *) synch_options.time_value ();

      if (tv != 0
          && this->reactor ()->schedule_timer (this,
                                               synch_options.arg (),
                                               *tv) == 0)
        return -1;
      else
        return this->reactor ()->register_handler
          (this,
           ACE_Event_Handler::ACCEPT_MASK);
    }
}

// Bridge method for activating a <svc_handler> with the appropriate
// concurrency strategy.  The default behavior of this method is to
// activate the SVC_HANDLER by calling its open() method (which allows
// the SVC_HANDLER to define its own concurrency strategy).  However,
// subclasses can override this strategy to do more sophisticated
// concurrency activations (such as creating the SVC_HANDLER as an
// "active object" via multi-threading or multi-processing).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::activate_svc_handler");
  return this->concurrency_strategy_->activate_svc_handler
    (svc_handler,
     (void *) this);
}

// Factors out the code shared between the <accept> and <handle_input>
// methods.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::shared_accept
  (SVC_HANDLER *svc_handler,
   ACE_PEER_ACCEPTOR_ADDR *remote_addr,
   ACE_Time_Value *timeout,
   bool restart,
   bool reset_new_handle)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::shared_accept");
  if (svc_handler == 0)
    return -1;

  // Accept connection into the Svc_Handler.
  else if (this->peer_acceptor_.accept (svc_handler->peer (), // stream
                                        remote_addr, // remote address
                                        timeout, // timeout
                                        restart, // restart
                                        reset_new_handle // reset new handle
                                        ) == -1)
    {
      // Check whether we just timed out or whether we failed...
      if (!(errno == EWOULDBLOCK || errno == ETIME))
        // Close down handler to avoid memory leaks.
        svc_handler->close (CLOSE_DURING_NEW_CONNECTION);
      return -1;
    }
  // Activate the <svc_handler> using the designated concurrency
  // strategy (note that this method becomes responsible for handling
  // errors and freeing up the memory if things go awry...)
  else
    return this->activate_svc_handler (svc_handler);
}

// Make a SVC_HANDLER, accept the connection into the SVC_HANDLER, and
// then activate the SVC_HANDLER.  Note that SVC_HANDLER::open()
// decides what type of concurrency strategy to use.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept
  (SVC_HANDLER *svc_handler,
   ACE_PEER_ACCEPTOR_ADDR *remote_addr,
   const ACE_Synch_Options &synch_options,
   bool restart,
   bool reset_new_handle)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept");
  // Note that if timeout == ACE_Time_Value (x, y) where (x > 0 || y >
  // 0) then this->connector_.connect() will block synchronously.  If
  // <use_reactor> is set then we don't want this to happen (since we
  // want the ACE_Reactor to do the timeout asynchronously).
  // Therefore, we'll force this->connector_ to use ACE_Time_Value (0,
  // 0) in this case...

  ACE_Time_Value *timeout;
  int use_reactor = synch_options[ACE_Synch_Options::USE_REACTOR];

  if (use_reactor)
    timeout = (ACE_Time_Value *) &ACE_Time_Value::zero;
  else
    timeout = (ACE_Time_Value *) synch_options.time_value ();

  if (this->shared_accept (svc_handler, // stream
                           remote_addr, // remote address
                           timeout, // timeout
                           restart, // restart
                           reset_new_handle // reset new handler
                           ) == -1)
    {
      if (use_reactor && errno == EWOULDBLOCK)
        // We couldn't accept right away, so let's wait in the
        // <ACE_Reactor>.
        this->register_handler (svc_handler,
                                synch_options,
                                restart);
      return -1;
    }
  return 0;
}

// Accepts one pending connection from a client (since we're the
// "oneshot" Acceptor).

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_input (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::handle_input");
  int result = 0;

  // Cancel any timer that might be pending.
  this->cancel ();

  // Try to find out if the implementation of the reactor that we are
  // using requires us to reset the event association for the newly
  // created handle.  This is because the newly created handle will
  // inherit the properties of the listen handle, including its event
  // associations.
  bool const reset_new_handle = this->reactor ()->uses_event_associations ();

  // There is a use-case whereby this object will be gone upon return
  // from shared_accept - if the Svc_Handler deletes this Oneshot_Acceptor
  // during the shared_accept/activation steps. So, do whatever we need
  // to do with this object before calling shared_accept.
  if (this->reactor ())
    this->reactor ()->remove_handler
      (this,
       ACE_Event_Handler::ACCEPT_MASK | ACE_Event_Handler::DONT_CALL);

  if (this->shared_accept (this->svc_handler_, // stream
                           0, // remote address
                           0, // timeout
                           this->restart_, // restart
                           reset_new_handle // reset new handle
                           ) == -1)
    result = -1;

  return result;
}

// Hook called by the explicit dynamic linking facility.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::init (int, ACE_TCHAR *[])
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::init");
  return -1;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::fini");
  return this->handle_close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::info (ACE_TCHAR **strp,
                                                              size_t length) const
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::info");
  ACE_TCHAR buf[BUFSIZ];
  ACE_TCHAR addr_str[BUFSIZ];
  ACE_PEER_ACCEPTOR_ADDR addr;

  if (this->peer_acceptor_.get_local_addr (addr) == -1)
    return -1;
  else if (addr.addr_to_string (addr_str, sizeof addr_str) == -1)
    return -1;

  ACE_OS::sprintf (buf,
                   ACE_TEXT ("%s\t %s %s"),
                   ACE_TEXT ("ACE_Oneshot_Acceptor"),
                   addr_str,
                   ACE_TEXT ("#oneshot acceptor factory\n"));

  if (*strp == 0 && (*strp = ACE_OS::strdup (buf)) == 0)
    return -1;
  else
    ACE_OS::strsncpy (*strp, buf, length);
  return static_cast<int> (ACE_OS::strlen (buf));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::suspend");
  return this->reactor () && this->reactor ()->suspend_handler (this);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume (void)
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::resume");
  return this->reactor () && this->reactor ()->resume_handler (this);
}

// Returns ACE_HANDLE of the underlying peer_acceptor.

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_HANDLE
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle (void) const
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle");
  return this->peer_acceptor_.get_handle ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_PEER_ACCEPTOR &
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor (void) const
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor");
  return (ACE_PEER_ACCEPTOR &) this->peer_acceptor_;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR & () const
{
  ACE_TRACE ("ACE_Oneshot_Acceptor<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::operator ACE_PEER_ACCEPTOR &");
  return (ACE_PEER_ACCEPTOR &) this->peer_acceptor_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_ACCEPTOR_CPP */
