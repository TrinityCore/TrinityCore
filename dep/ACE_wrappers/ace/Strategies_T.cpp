// $Id: Strategies_T.cpp 82294 2008-07-12 13:03:37Z johnnyw $

#ifndef ACE_STRATEGIES_T_CPP
#define ACE_STRATEGIES_T_CPP

#include "ace/Strategies_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Service_Repository.h"
#include "ace/Service_Types.h"
#include "ace/Thread_Manager.h"
#include "ace/WFMO_Reactor.h"
#include "ace/ACE.h"
#include "ace/OS_NS_dlfcn.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_Errno.h"
#include "ace/Svc_Handler.h"
#if defined (ACE_OPENVMS)
# include "ace/Lib_Find.h"
#endif

#if !defined (__ACE_INLINE__)
#include "ace/Strategies_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template<class SVC_HANDLER>
ACE_Recycling_Strategy<SVC_HANDLER>::~ACE_Recycling_Strategy (void)
{
}

template<class SVC_HANDLER> int
ACE_Recycling_Strategy<SVC_HANDLER>::assign_recycler (SVC_HANDLER *svc_handler,
                                                      ACE_Connection_Recycling_Strategy *recycler,
                                                      const void *recycling_act)
{
  svc_handler->recycler (recycler, recycling_act);
  return 0;
}

template<class SVC_HANDLER> int
ACE_Recycling_Strategy<SVC_HANDLER>::prepare_for_recycling (SVC_HANDLER *svc_handler)
{
  return svc_handler->recycle ();
}

template <class SVC_HANDLER>
ACE_Singleton_Strategy<SVC_HANDLER>::~ACE_Singleton_Strategy (void)
{
  ACE_TRACE ("ACE_Singleton_Strategy<SVC_HANDLER>::~ACE_Singleton_Strategy");
  if (this->delete_svc_handler_)
    delete this->svc_handler_;
}

// Create a Singleton SVC_HANDLER by always returning the same
// SVC_HANDLER.

template <class SVC_HANDLER> int
ACE_Singleton_Strategy<SVC_HANDLER>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_Singleton_Strategy<SVC_HANDLER>::make_svc_handler");
  sh = this->svc_handler_;
  return 0;
}

template <class SVC_HANDLER> int
ACE_Singleton_Strategy<SVC_HANDLER>::open (SVC_HANDLER *sh,
                                           ACE_Thread_Manager *)
{
  ACE_TRACE ("ACE_Singleton_Strategy<SVC_HANDLER>::open");

  if (this->delete_svc_handler_)
    delete this->svc_handler_;

  // If <sh> is NULL then create a new <SVC_HANDLER>.
  if (sh == 0)
    {
      ACE_NEW_RETURN (this->svc_handler_,
                      SVC_HANDLER,
                      -1);
      this->delete_svc_handler_ = true;
    }
  else
    {
      this->svc_handler_ = sh;
      this->delete_svc_handler_ = false;
    }

  return 0;
}

template <class SVC_HANDLER> int
ACE_DLL_Strategy<SVC_HANDLER>::open (const ACE_TCHAR dll_name[],
                                     const ACE_TCHAR factory_function[],
                                     const ACE_TCHAR svc_name[],
                                     ACE_Service_Repository *svc_rep,
                                     ACE_Thread_Manager *thr_mgr)
{
  ACE_TRACE ("ACE_DLL_Strategy<SVC_HANDLER>::open");
  this->inherited::open (thr_mgr);
  ACE_OS::strcpy (this->dll_name_, dll_name);
  ACE_OS::strcpy (this->factory_function_, factory_function);
  ACE_OS::strcpy (this->svc_name_, svc_name);
  this->svc_rep_ = svc_rep;
  return 0;
}

// Create a SVC_HANDLER by dynamically linking it from a DLL.

template <class SVC_HANDLER> int
ACE_DLL_Strategy<SVC_HANDLER>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_DLL_Strategy<SVC_HANDLER>::make_svc_handler");

  // Open the shared library.
  ACE_SHLIB_HANDLE handle = ACE_OS::dlopen (this->dll_name_);

  // Extract the factory function.
#if defined (ACE_OPENVMS)
  SVC_HANDLER *(*factory)(void) =
    (SVC_HANDLER *(*)(void)) ACE::ldsymbol (handle,
                                            this->factory_function_);
#else
  SVC_HANDLER *(*factory)(void) =
    (SVC_HANDLER *(*)(void)) ACE_OS::dlsym (handle,
                                            this->factory_function_);
#endif

  // Call the factory function to obtain the new SVC_Handler (should
  // use RTTI here when it becomes available...)
  SVC_HANDLER *svc_handler = 0;

  ACE_ALLOCATOR_RETURN (svc_handler, (*factory)(), -1);

  if (svc_handler != 0)
    {
      // Create an ACE_Service_Type containing the SVC_Handler and
      // insert into this->svc_rep_;

      ACE_Service_Type_Impl *stp = 0;
      ACE_NEW_RETURN (stp,
                      ACE_Service_Object_Type (svc_handler,
                                               this->svc_name_),
                      -1);

      ACE_Service_Type *srp = 0;

      ACE_NEW_RETURN (srp,
                      ACE_Service_Type (this->svc_name_,
                                        stp,
                                        handle,
                                        1),
                      -1);
      if (srp == 0)
        {
          delete stp;
          errno = ENOMEM;
          return -1;
        }

      if (this->svc_rep_->insert (srp) == -1)
        return -1;
      // @@ Somehow, we need to deal with this->thr_mgr_...
    }

  sh = svc_handler;
  return 0;
}

// Default behavior is to activate the SVC_HANDLER by calling it's
// open() method, which allows the SVC_HANDLER to determine its own
// concurrency strategy.

template <class SVC_HANDLER> int
ACE_Concurrency_Strategy<SVC_HANDLER>::activate_svc_handler (SVC_HANDLER *svc_handler,
                                                             void *arg)
{
  ACE_TRACE ("ACE_Concurrency_Strategy<SVC_HANDLER>::activate_svc_handler");

  int result = 0;

  // See if we should enable non-blocking I/O on the <svc_handler>'s
  // peer.
  if (ACE_BIT_ENABLED (this->flags_, ACE_NONBLOCK) != 0)
    {
      if (svc_handler->peer ().enable (ACE_NONBLOCK) == -1)
        result = -1;
    }
  // Otherwise, make sure it's disabled by default.
  else if (svc_handler->peer ().disable (ACE_NONBLOCK) == -1)
    result = -1;

  if (result == 0 && svc_handler->open (arg) == -1)
    result = -1;

  if (result == -1)
    // The connection was already made; so this close is a "normal" close
    // operation.
    svc_handler->close (NORMAL_CLOSE_OPERATION);

  return result;
}

template <class SVC_HANDLER> int
ACE_Reactive_Strategy<SVC_HANDLER>::open (ACE_Reactor *reactor,
                                          ACE_Reactor_Mask mask,
                                          int flags)
{
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::open");
  this->reactor_ = reactor;
  this->mask_ = mask;
  this->flags_ = flags;

  // Must have a <Reactor>
  if (this->reactor_ == 0)
    return -1;
  else
    return 0;
}

template <class SVC_HANDLER> int
ACE_Reactive_Strategy<SVC_HANDLER>::activate_svc_handler (SVC_HANDLER *svc_handler,
                                                          void *arg)
{
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::activate_svc_handler");

  int result = 0;

  if (this->reactor_ == 0)
    result = -1;

  // Register with the Reactor with the appropriate <mask>.
  else if (this->reactor_->register_handler (svc_handler, this->mask_) == -1)
    result = -1;

  // If the implementation of the reactor uses event associations
  else if (this->reactor_->uses_event_associations ())
    {
      // If we don't have non-block on, it won't work with
      // WFMO_Reactor
      // This maybe too harsh
      // if (!ACE_BIT_ENABLED (this->flags_, ACE_NONBLOCK))
      // goto failure;
      if (svc_handler->open (arg) != -1)
        return 0;
      else
        result = -1;
    }
  else
    // Call up to our parent to do the SVC_HANDLER initialization.
    return this->inherited::activate_svc_handler (svc_handler, arg);

  if (result == -1)
    // The connection was already made; so this close is a "normal" close
    // operation.
    svc_handler->close (NORMAL_CLOSE_OPERATION);

  return result;
}

template <class SVC_HANDLER> int
ACE_Thread_Strategy<SVC_HANDLER>::open (ACE_Thread_Manager *thr_mgr,
                                        long thr_flags,
                                        int n_threads,
                                        int flags)
{
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::open");
  this->thr_mgr_ = thr_mgr;
  this->n_threads_ = n_threads;
  this->thr_flags_ = thr_flags;
  this->flags_ = flags;

  // Must have a thread manager!
  if (this->thr_mgr_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("error: must have a non-NULL thread manager\n")),
                      -1);
  else
    return 0;
}

template <class SVC_HANDLER> int
ACE_Thread_Strategy<SVC_HANDLER>::activate_svc_handler (SVC_HANDLER *svc_handler,
                                                        void *arg)
{
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::activate_svc_handler");
  // Call up to our parent to do the SVC_HANDLER initialization.
  if (this->inherited::activate_svc_handler (svc_handler,
                                             arg) == -1)
    return -1;
  else
    // Turn the <svc_handler> into an active object (if it isn't
    // already one as a result of the first activation...)
    return svc_handler->activate (this->thr_flags_,
                                  this->n_threads_);
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::open
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr, int reuse_addr)
{
  this->reuse_addr_ = reuse_addr;
  this->peer_acceptor_addr_ = local_addr;
  if (this->peer_acceptor_.open (local_addr, reuse_addr) == -1)
    return -1;

  // Set the peer acceptor's handle into non-blocking mode.  This is a
  // safe-guard against the race condition that can otherwise occur
  // between the time when <select> indicates that a passive-mode
  // socket handle is "ready" and when we call <accept>.  During this
  // interval, the client can shutdown the connection, in which case,
  // the <accept> call can hang!
  this->peer_acceptor_.enable (ACE_NONBLOCK);
  return 0;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Accept_Strategy
  (const ACE_PEER_ACCEPTOR_ADDR &local_addr,
   int reuse_addr,
   ACE_Reactor *reactor)
    : reactor_ (reactor)
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::ACE_Accept_Strategy");

  if (this->open (local_addr, reuse_addr) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("open")));
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> int
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler
  (SVC_HANDLER *svc_handler)
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::accept_svc_handler");

  // Try to find out if the implementation of the reactor that we are
  // using requires us to reset the event association for the newly
  // created handle. This is because the newly created handle will
  // inherit the properties of the listen handle, including its event
  // associations.
  int reset_new_handle = this->reactor_->uses_event_associations ();

  if (this->peer_acceptor_.accept (svc_handler->peer (), // stream
                                   0, // remote address
                                   0, // timeout
                                   1, // restart
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

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler");

  return this->connector_.connect (sh->peer (),
                                   remote_addr,
                                   timeout,
                                   local_addr,
                                   reuse_addr,
                                   flags,
                                   perms);
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> int
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler
(SVC_HANDLER *&sh,
 SVC_HANDLER *&sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connect_svc_handler");

  int const result =
    this->connector_.connect (sh->peer (),
                              remote_addr,
                              timeout,
                              local_addr,
                              reuse_addr,
                              flags,
                              perms);
  sh_copy = sh;
  return result;
}

template <class SVC_HANDLER> int
ACE_Process_Strategy<SVC_HANDLER>::open (size_t n_processes,
                                         ACE_Event_Handler *acceptor,
                                         ACE_Reactor *reactor,
                                         int avoid_zombies)
{
  ACE_TRACE ("ACE_Process_Strategy<SVC_HANDLER>::open");
  this->n_processes_ = n_processes;
  this->acceptor_ = acceptor;
  this->reactor_ = reactor;
  this->flags_ = avoid_zombies;

  return 0;
}

template <class SVC_HANDLER> int
ACE_Process_Strategy<SVC_HANDLER>::activate_svc_handler (SVC_HANDLER *svc_handler,
                                                         void *arg)
{
  ACE_TRACE ("ACE_Process_Strategy<SVC_HANDLER>::activate_svc_handler");

  // If <flags_> is non-0 then we won't create zombies.
  switch (ACE::fork (ACE_TEXT ("child"), this->flags_))
    {
    case -1:
      {
        ACE_Errno_Guard error (errno);
        svc_handler->destroy ();
      }
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%p\n"),
                         ACE_TEXT ("fork")),
                        -1);
      /* NOTREACHED */
    case 0: // In child process.

      // Close down the SOCK_Acceptor's handle since we don't need to
      // keep it open.
      if (this->acceptor_ != 0)
        // Ignore the return value here...
        (void) this->reactor_->remove_handler (this->acceptor_,
                                               ACE_Event_Handler::ACCEPT_MASK);

      // Call up to our ancestor in the inheritance to do the
      // SVC_HANDLER initialization.
      return this->inherited::activate_svc_handler (svc_handler, arg);
      /* NOTREACHED */
    default: // In parent process.
      // We need to close down the <SVC_HANDLER> here because it's
      // running in the child.
      svc_handler->destroy ();
      return 0;
    }
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX>
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::ACE_Cached_Connect_Strategy
(creation_strategy_type *cre_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 ACE_Recycling_Strategy<SVC_HANDLER> *rec_s,
 MUTEX *lock,
 bool delete_lock)
  : lock_ (lock),
    delete_lock_ (delete_lock),
    reverse_lock_ (0),
    creation_strategy_ (0),
    delete_creation_strategy_ (false),
    concurrency_strategy_ (0),
    delete_concurrency_strategy_ (false),
    recycling_strategy_ (0),
    delete_recycling_strategy_ (false)
{
  // Create a new lock if necessary.
  if (this->lock_ == 0)
    {
      ACE_NEW (this->lock_,
               MUTEX);

      this->delete_lock_ = true;
    }

  ACE_NEW (this->reverse_lock_,
           REVERSE_MUTEX (*this->lock_));

  if (this->open (cre_s,
                  con_s,
                  rec_s) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Cached_Connect_Strategy::ACE_Cached_Connect_Strategy")));
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX>
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::~ACE_Cached_Connect_Strategy (void)
{
  if (this->delete_lock_)
    delete this->lock_;

  delete this->reverse_lock_;

  if (this->delete_creation_strategy_)
    delete this->creation_strategy_;
  this->delete_creation_strategy_ = false;
  this->creation_strategy_ = 0;

  if (this->delete_concurrency_strategy_)
    delete this->concurrency_strategy_;
  this->delete_concurrency_strategy_ = false;
  this->concurrency_strategy_ = 0;

  if (this->delete_recycling_strategy_)
    delete this->recycling_strategy_;
  this->delete_recycling_strategy_ = false;
  this->recycling_strategy_ = 0;

  // Close down all cached service handlers.
  CONNECTION_MAP_ENTRY *entry = 0;
  for (CONNECTION_MAP_ITERATOR iterator (connection_map_);
       iterator.next (entry);
       iterator.advance ())
    {
      entry->int_id_->recycler (0, 0);
      entry->int_id_->close ();
    }
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::open
(creation_strategy_type *cre_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 ACE_Recycling_Strategy<SVC_HANDLER> *rec_s)
{
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
                      CREATION_STRATEGY, -1);
      this->delete_creation_strategy_ = true;
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
                      CONCURRENCY_STRATEGY, -1);
      this->delete_concurrency_strategy_ = true;
    }

  // Initialize the recycling strategy.

  if (this->recycling_strategy_ != 0 &&
      this->delete_recycling_strategy_ &&
      rec_s != 0)
    {
      delete this->recycling_strategy_;
      this->recycling_strategy_ = 0;
      this->delete_recycling_strategy_ = false;
    }

  if (rec_s != 0)
    this->recycling_strategy_ = rec_s;
  else if (this->recycling_strategy_ == 0)
    {
      ACE_NEW_RETURN (this->recycling_strategy_,
                      RECYCLING_STRATEGY, -1);
      this->delete_recycling_strategy_ = true;
    }

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::make_svc_handler
  (SVC_HANDLER *&sh)
{
  return this->creation_strategy_->make_svc_handler (sh);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::activate_svc_handler
  (SVC_HANDLER *svc_handler)
{
  return this->concurrency_strategy_->activate_svc_handler (svc_handler);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::assign_recycler
  (SVC_HANDLER *svc_handler,
   ACE_Connection_Recycling_Strategy *recycler,
   const void *recycling_act)
{
  return this->recycling_strategy_->assign_recycler (svc_handler,
                                                     recycler,
                                                     recycling_act);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::prepare_for_recycling
  (SVC_HANDLER *svc_handler)
{
  return this->recycling_strategy_->prepare_for_recycling (svc_handler);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::check_hint_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms,
 CONNECTION_MAP_ENTRY *&entry,
 int &found)
{
  ACE_UNUSED_ARG (remote_addr);
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (local_addr);
  ACE_UNUSED_ARG (reuse_addr);
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (perms);

  found = 0;

  // Get the recycling act for the svc_handler
  CONNECTION_MAP_ENTRY *possible_entry = (CONNECTION_MAP_ENTRY *) sh->recycling_act ();

  // Check to see if the hint svc_handler has been closed down
  if (possible_entry->ext_id_.recycle_state () == ACE_RECYCLABLE_CLOSED)
    {
      // If close, decrement refcount
      if (possible_entry->ext_id_.decrement () == 0)
        {
          // If refcount goes to zero, close down the svc_handler
          possible_entry->int_id_->recycler (0, 0);
          possible_entry->int_id_->close ();
          this->purge_i (possible_entry);
        }

      // Hint not successful
      found = 0;

      // Reset hint
      sh = 0;
    }

  // If hint is not closed, see if it is connected to the correct
  // address and is recyclable
  else if ((possible_entry->ext_id_.recycle_state () == ACE_RECYCLABLE_IDLE_AND_PURGABLE ||
            possible_entry->ext_id_.recycle_state () == ACE_RECYCLABLE_IDLE_BUT_NOT_PURGABLE) &&
           possible_entry->ext_id_.subject () == remote_addr)
    {
      // Hint successful
      found = 1;

      // Tell the <svc_handler> that it should prepare itself for
      // being recycled.
      this->prepare_for_recycling (sh);
    }
  else
    {
      // This hint will not be used.
      possible_entry->ext_id_.decrement ();

      // Hint not successful
      found = 0;

      // If <sh> is not connected to the correct address or is busy,
      // we will not use it.
      sh = 0;
    }

  if (found)
    entry = possible_entry;

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::find_or_create_svc_handler_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms,
 CONNECTION_MAP_ENTRY *&entry,
 int &found)
{
  // Explicit type conversion
  REFCOUNTED_HASH_RECYCLABLE_ADDRESS search_addr (remote_addr);

  // Try to find the address in the cache.  Only if we don't find it
  // do we create a new <SVC_HANDLER> and connect it with the server.
  if (this->find (search_addr, entry) == -1)
    {
      // Set the flag
      found = 0;

      // We need to use a temporary variable here since we are not
      // allowed to change <sh> because other threads may use this
      // when we let go of the lock during the OS level connect.
      //
      // Note that making a new svc_handler, connecting remotely,
      // binding to the map, and assigning of the hint and recycler
      // should be atomic to the outside world.
      SVC_HANDLER *potential_handler = 0;

      // Create a new svc_handler
      if (this->make_svc_handler (potential_handler) == -1)
        return -1;

      // Actively establish the connection.  This is a timed blocking
      // connect.
      if (this->new_connection (potential_handler,
                                remote_addr,
                                timeout,
                                local_addr,
                                reuse_addr,
                                flags,
                                perms) == -1)
        {
          // If connect() failed because of timeouts, we have to
          // reject the connection entirely. This is necessary since
          // currently there is no way for the non-blocking connects
          // to complete and for the <Connector> to notify the cache
          // of the completion of connect().
          if (errno == EWOULDBLOCK)
            errno = ENOTSUP;

          // Close the svc handler.
          potential_handler->close (0);

          return -1;
        }
      else
        {
          // Insert the new SVC_HANDLER instance into the cache.
          if (this->connection_map_.bind (search_addr,
                                          potential_handler,
                                          entry) == -1)
            {
              // Close the svc handler.
              potential_handler->close (CLOSE_DURING_NEW_CONNECTION);

              return -1;
            }

          // Everything succeeded as planned. Assign <sh> to <potential_handler>.
          sh = potential_handler;

          // Set the recycler and the recycling act
          this->assign_recycler (sh, this, entry);
        }
    }
  else
    // We found a cached svc_handler.
    {
      // Set the flag
      found = 1;

      // Get the cached <svc_handler>
      sh = entry->int_id_;

      // Tell the <svc_handler> that it should prepare itself for
      // being recycled.
      this->prepare_for_recycling (sh);
    }

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::new_connection
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  // Yow, Reverse Guard!  Let go of the lock for the duration of the
  // actual connect.  This will allow other threads to hack on the
  // connection cache while this thread creates the new connection.
  ACE_GUARD_RETURN (REVERSE_MUTEX, ace_mon, *this->reverse_lock_, -1);

  return this->CONNECT_STRATEGY::connect_svc_handler (sh,
                                                      remote_addr,
                                                      timeout,
                                                      local_addr,
                                                      reuse_addr,
                                                      flags,
                                                      perms);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::connect_svc_handler
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  int found = 0;

  // This artificial scope is required since we need to let go of the
  // lock *before* registering the newly created handler with the
  // Reactor.
  {
    // Synchronization is required here as the setting of the
    // recyclable state must be done atomically with the finding and
    // binding of the service handler in the cache.
    ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

    int result = this->connect_svc_handler_i (sh,
                                              remote_addr,
                                              timeout,
                                              local_addr,
                                              reuse_addr,
                                              flags,
                                              perms,
                                              found);
    if (result != 0)
      return result;

  }

  // If it is a new connection, activate it.
  //
  // Note: This activation is outside the scope of the lock of the
  // cached connector.  This is necessary to avoid subtle deadlock
  // conditions with this lock and the Reactor lock.

  if (!found)
    {
      if (this->activate_svc_handler (sh) == -1)
        {
          // If an error occurs while activating the handler, the
          // <activate_svc_handler> method will close the handler.
          // This in turn will remove this entry from the internal
          // table.

          // Synchronization is required here as the setting of the
          // handler to zero must be done atomically with the users of
          // the cache.
          ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

          // Reset handler.
          sh = 0;

          return -1;
        }
    }

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::connect_svc_handler
(SVC_HANDLER *&sh,
 SVC_HANDLER *&sh_copy,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms)
{
  int found = 0;

  // This artificial scope is required since we need to let go of the
  // lock *before* registering the newly created handler with the
  // Reactor.
  {
    // Synchronization is required here as the setting of the
    // recyclable state must be done atomically with the finding and
    // binding of the service handler in the cache.
    ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

    int result = this->connect_svc_handler_i (sh,
                                              remote_addr,
                                              timeout,
                                              local_addr,
                                              reuse_addr,
                                              flags,
                                              perms,
                                              found);
    sh_copy = sh;

    if (result != 0)
      return result;

  }

  // If it is a new connection, activate it.
  //
  // Note: This activation is outside the scope of the lock of the
  // cached connector.  This is necessary to avoid subtle deadlock
  // conditions with this lock and the Reactor lock.

  if (!found)
    {
      if (this->activate_svc_handler (sh_copy) == -1)
        {
          // If an error occurs while activating the handler, the
          // <activate_svc_handler> method will close the handler.
          // This in turn will remove this entry from the internal
          // table.

          // Synchronization is required here as the setting of the
          // handler to zero must be done atomically with the users of
          // the cache.
          ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

          // Reset handler.
          sh = 0;
          sh_copy = 0;

          return -1;
        }
    }

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::connect_svc_handler_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 int reuse_addr,
 int flags,
 int perms,
 int& found)
{
  CONNECTION_MAP_ENTRY *entry = 0;

  // Check if the user passed a hint svc_handler
  if (sh != 0)
    {
      int result = this->check_hint_i (sh,
                                       remote_addr,
                                       timeout,
                                       local_addr,
                                       reuse_addr,
                                       flags,
                                       perms,
                                       entry,
                                       found);
      if (result != 0)
        return result;
    }

  // If not found
  if (!found)
    {
      int result = this->find_or_create_svc_handler_i (sh,
                                                       remote_addr,
                                                       timeout,
                                                       local_addr,
                                                       reuse_addr,
                                                       flags,
                                                       perms,
                                                       entry,
                                                       found);
      if (result != 0)
        return result;
    }

  // For all successful cases: mark the <svc_handler> in the cache
  // as being <in_use>.  Therefore recyclable is BUSY.
  entry->ext_id_.recycle_state (ACE_RECYCLABLE_BUSY);

  // And increment the refcount
  entry->ext_id_.increment ();

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::cache (const void *recycling_act)
{
  // Synchronization is required here as the setting of the recyclable
  // state must be done atomically with respect to other threads that
  // are querying the cache.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

  return this->cache_i (recycling_act);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::cache_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  entry->ext_id_.recycle_state (ACE_RECYCLABLE_IDLE_AND_PURGABLE);

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::recycle_state (const void *recycling_act,
                                                                                      ACE_Recyclable_State new_state)
{
  // Synchronization is required here as the setting of the recyclable
  // state must be done atomically with respect to other threads that
  // are querying the cache.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

  return this->recycle_state_i (recycling_act,
                                new_state);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::recycle_state_i (const void *recycling_act,
                                                                                        ACE_Recyclable_State new_state)
{
  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  entry->ext_id_.recycle_state (new_state);

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> ACE_Recyclable_State
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::recycle_state (const void *recycling_act) const
{
  // Const cast.
  SELF *fake_this = const_cast<SELF *> (this);

  // Synchronization is required here.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *fake_this->lock_, ACE_RECYCLABLE_UNKNOWN);

  return this->recycle_state_i (recycling_act);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> ACE_Recyclable_State
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::recycle_state_i (const void *recycling_act) const
{
  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  return entry->ext_id_.recycle_state ();
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::purge (const void *recycling_act)
{
  // Excluded other threads from changing cache while we take this
  // entry out.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

  return this->purge_i (recycling_act);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::purge_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  return this->connection_map_.unbind (entry);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::mark_as_closed (const void *recycling_act)
{
  // Excluded other threads from changing cache while we take this
  // entry out.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

  return this->mark_as_closed_i (recycling_act);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::mark_as_closed_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as CLOSED.
  entry->ext_id_.recycle_state (ACE_RECYCLABLE_CLOSED);

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::cleanup_hint (const void *recycling_act,
                                                                                     void **act_holder)
{
  // Excluded other threads from changing cache while we take this
  // entry out.
  ACE_GUARD_RETURN (MUTEX, ace_mon, *this->lock_, -1);

  return this->cleanup_hint_i (recycling_act,
                               act_holder);
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::cleanup_hint_i (const void *recycling_act,
                                                                                       void **act_holder)
{
  // Reset the <*act_holder> in the confines and protection of the
  // lock.
  if (act_holder)
    *act_holder = 0;

  // The wonders and perils of ACT
  CONNECTION_MAP_ENTRY *entry = (CONNECTION_MAP_ENTRY *) recycling_act;

  // Decrement the refcount on the <svc_handler>.
  int refcount = entry->ext_id_.decrement ();

  // If the svc_handler state is closed and the refcount == 0, call
  // close() on svc_handler.
  if (entry->ext_id_.recycle_state () == ACE_RECYCLABLE_CLOSED &&
      refcount == 0)
    {
      entry->int_id_->recycler (0, 0);
      entry->int_id_->close ();
      this->purge_i (entry);
    }

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> ACE_Creation_Strategy<SVC_HANDLER> *
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::creation_strategy (void) const
{
  return this->creation_strategy_;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> ACE_Recycling_Strategy<SVC_HANDLER> *
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::recycling_strategy (void) const
{
  return this->recycling_strategy_;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> ACE_Concurrency_Strategy<SVC_HANDLER> *
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::concurrency_strategy (void) const
{
  return this->concurrency_strategy_;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class MUTEX> int
ACE_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, MUTEX>::find (
  REFCOUNTED_HASH_RECYCLABLE_ADDRESS &search_addr,
  CONNECTION_MAP_ENTRY *&entry)
{
  typedef ACE_Hash_Map_Bucket_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDRESS,
                                       SVC_HANDLER *,
                                       ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>,
                                       ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>,
                                       ACE_Null_Mutex>
    CONNECTION_MAP_BUCKET_ITERATOR;

  CONNECTION_MAP_BUCKET_ITERATOR iterator (this->connection_map_,
                                           search_addr);

  CONNECTION_MAP_BUCKET_ITERATOR end (this->connection_map_,
                                      search_addr,
                                      1);

  for (;
       iterator != end;
       ++iterator)
    {
      REFCOUNTED_HASH_RECYCLABLE_ADDRESS &addr = (*iterator).ext_id_;

      if (addr.recycle_state () != ACE_RECYCLABLE_IDLE_AND_PURGABLE &&
          addr.recycle_state () != ACE_RECYCLABLE_IDLE_BUT_NOT_PURGABLE)
        continue;

      if (addr.subject () != search_addr.subject ())
        continue;

      entry = &(*iterator);
      return 0;
    }

  return -1;
}

template <class SVC_HANDLER> void
ACE_DLL_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_DLL_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Concurrency_Strategy<SVC_HANDLER>::~ACE_Concurrency_Strategy (void)
{
  ACE_TRACE ("ACE_Concurrency_Strategy<SVC_HANDLER>::~ACE_Concurrency_Strategy");
}


template <class SVC_HANDLER> void
ACE_Concurrency_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Concurrency_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Reactive_Strategy<SVC_HANDLER>::~ACE_Reactive_Strategy (void)
{
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::~ACE_Reactive_Strategy");
}


template <class SVC_HANDLER> void
ACE_Reactive_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Reactive_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Thread_Strategy<SVC_HANDLER>::~ACE_Thread_Strategy (void)
{
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::~ACE_Thread_Strategy");
}

template <class SVC_HANDLER> void
ACE_Thread_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Thread_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1>
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Accept_Strategy (void)
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::~ACE_Accept_Strategy");

  // Close the underlying acceptor.
  this->peer_acceptor_.close ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_HANDLE
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle (void) const
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::get_handle");
  return this->peer_acceptor_.get_handle ();
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> ACE_PEER_ACCEPTOR &
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor (void) const
{
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::acceptor");
  return (ACE_PEER_ACCEPTOR &) this->peer_acceptor_;
}

template <class SVC_HANDLER, ACE_PEER_ACCEPTOR_1> void
ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Accept_Strategy<SVC_HANDLER, ACE_PEER_ACCEPTOR_2>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1>
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Connect_Strategy (void)
{
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::~ACE_Connect_Strategy");
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> ACE_PEER_CONNECTOR &
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connector (void) const
{
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::connector");
  return (ACE_PEER_CONNECTOR &) this->connector_;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1> void
ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Process_Strategy<SVC_HANDLER>::~ACE_Process_Strategy (void)
{
  ACE_TRACE ("ACE_Process_Strategy<SVC_HANDLER>::~ACE_Process_Strategy");
}

template <class SVC_HANDLER> void
ACE_Process_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Process_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Scheduling_Strategy<SVC_HANDLER>::~ACE_Scheduling_Strategy (void)
{
  ACE_TRACE ("ACE_Scheduling_Strategy<SVC_HANDLER>::~ACE_Scheduling_Strategy");
}

template <class SVC_HANDLER> int
ACE_Scheduling_Strategy<SVC_HANDLER>::suspend (void)
{
  ACE_TRACE ("ACE_Scheduling_Strategy<SVC_HANDLER>::suspend");
  return -1;
}

template <class SVC_HANDLER> int
ACE_Scheduling_Strategy<SVC_HANDLER>::resume (void)
{
  ACE_TRACE ("ACE_Scheduling_Strategy<SVC_HANDLER>::resume");
  return -1;
}

template <class SVC_HANDLER> void
ACE_Scheduling_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Scheduling_Strategy<SVC_HANDLER>::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER> int
ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::suspend (void)
{
  ACE_TRACE ("ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::suspend");
  return this->reactor_->suspend_handlers ();
}

template <class SVC_HANDLER> int
ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::resume (void)
{
  ACE_TRACE ("ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::resume");
  return this->reactor_->resume_handlers ();
}

template <class SVC_HANDLER> void
ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Schedule_All_Reactive_Strategy<SVC_HANDLER>::dump");

  ACE_Scheduling_Strategy<SVC_HANDLER>::dump ();
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER> int
ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::suspend (void)
{
  ACE_TRACE ("ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::suspend");
  return this->thr_mgr_->suspend_all ();
}

template <class SVC_HANDLER> int
ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::resume (void)
{
  ACE_TRACE ("ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::resume");
  return this->thr_mgr_->resume_all ();
}

template <class SVC_HANDLER> void
ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Schedule_All_Threaded_Strategy<SVC_HANDLER>::dump");

  ACE_Scheduling_Strategy<SVC_HANDLER>::dump ();
#endif /* ACE_HAS_DUMP */
}

template <class T>
ACE_Refcounted_Hash_Recyclable<T>::~ACE_Refcounted_Hash_Recyclable (void)
{
}

template <class SVC_HANDLER> void
ACE_Singleton_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Singleton_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER>
ACE_Creation_Strategy<SVC_HANDLER>::~ACE_Creation_Strategy (void)
{
  ACE_TRACE ("ACE_Creation_Strategy<SVC_HANDLER>::~ACE_Creation_Strategy");
}

// Default behavior is to make a new SVC_HANDLER, passing in the
// Thread_Manager (if any).

template <class SVC_HANDLER> int
ACE_Creation_Strategy<SVC_HANDLER>::make_svc_handler (SVC_HANDLER *&sh)
{
  ACE_TRACE ("ACE_Creation_Strategy<SVC_HANDLER>::make_svc_handler");

  if (sh == 0)
    ACE_NEW_RETURN (sh, SVC_HANDLER (this->thr_mgr_), -1);
  sh->reactor (this->reactor_);
  return 0;
}

template <class SVC_HANDLER> void
ACE_Creation_Strategy<SVC_HANDLER>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Creation_Strategy<SVC_HANDLER>::dump");
#endif /* ACE_HAS_DUMP */
}

template <class SVC_HANDLER> int
ACE_NOOP_Creation_Strategy<SVC_HANDLER>::make_svc_handler (SVC_HANDLER *&)
{
  ACE_TRACE ("ACE_NOOP_Creation_Strategy<SVC_HANDLER>::make_svc_handler");
  return 0;
}

template <class SVC_HANDLER> int
ACE_NOOP_Concurrency_Strategy<SVC_HANDLER>::activate_svc_handler (SVC_HANDLER *,
                                                                  void *)
{
  ACE_TRACE ("ACE_NOOP_Concurrency_Strategy<SVC_HANDLER>::activate_svc_handler");
  return 0;
}


ACE_ALLOC_HOOK_DEFINE(ACE_Creation_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Singleton_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_DLL_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Concurrency_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Thread_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Connect_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Process_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Accept_Strategy)
ACE_ALLOC_HOOK_DEFINE(ACE_Thread_Strategy)

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_STRATEGIES_T_CPP */
