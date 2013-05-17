//$Id: Cached_Connect_Strategy_T.cpp 95630 2012-03-22 13:04:47Z johnnyw $

#ifndef ACE_CACHED_CONNECT_STRATEGY_T_CPP
#define ACE_CACHED_CONNECT_STRATEGY_T_CPP

#include "ace/Cached_Connect_Strategy_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/ACE.h"
#include "ace/Service_Repository.h"
#include "ace/Service_Types.h"
#include "ace/Thread_Manager.h"
#include "ace/WFMO_Reactor.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX>
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::ACE_Cached_Connect_Strategy_Ex
(CACHING_STRATEGY &caching_s,
 ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 ACE_Recycling_Strategy<SVC_HANDLER> *rec_s,
 MUTEX *lock,
 int delete_lock)
  : CCSBASE (cre_s, con_s, rec_s, lock, delete_lock),
    connection_cache_ (caching_s)
{
  if (this->open (cre_s, con_s, rec_s) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%p\n"),
                ACE_TEXT ("ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>\n")));
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX>
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::~ACE_Cached_Connect_Strategy_Ex (void)
{
  cleanup ();
}


template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::check_hint_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 bool reuse_addr,
 int flags,
 int perms,
 ACE_Hash_Map_Entry<ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR>, std::pair<SVC_HANDLER *, ATTRIBUTES> > *&entry,
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
  CONNECTION_CACHE_ENTRY *possible_entry =
    (CONNECTION_CACHE_ENTRY *) sh->recycling_act ();

  // Check to see if the hint svc_handler has been closed down
  if (possible_entry->ext_id_.recycle_state () == ACE_RECYCLABLE_CLOSED)
    {
      // If close, decrement refcount
      if (possible_entry->ext_id_.decrement () == 0)
        {
          // If refcount goes to zero, close down the svc_handler
          possible_entry->int_id_.first->recycler (0, 0);
          possible_entry->int_id_.first->close ();
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

      //
      // Update the caching attributes directly since we don't do a
      // find() on the cache map.
      //

      // Indicates successful find.
      int find_result = 0;

      int result = this->caching_strategy ().notify_find (find_result,
                                                          possible_entry->int_id_.second);

      if (result == -1)
        return result;
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

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::find_or_create_svc_handler_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 bool reuse_addr,
 int flags,
 int perms,
 ACE_Hash_Map_Entry<ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR>, std::pair<SVC_HANDLER *, ATTRIBUTES> > *&entry,
 int &found)
{
  REFCOUNTED_HASH_RECYCLABLE_ADDRESS search_addr (remote_addr);

  // Try to find the address in the cache.  Only if we don't find it
  // do we create a new <SVC_HANDLER> and connect it with the server.
  while (this->find (search_addr, entry) != -1)
  {
    // We found a cached svc_handler.
    // Get the cached <svc_handler>
    sh = entry->int_id_.first;

    // Is the connection clean?
    int state_result =
      ACE::handle_ready (sh->peer ().get_handle (),
                         &ACE_Time_Value::zero,
                         1, // read ready
                         0, // write ready
                         1);// exception ready

    if (state_result == 1)
    {

      if (sh->close () == -1)
        return -1;

      sh = 0;

      // Cycle it once again..
    }
    else if ((state_result == -1) && (errno == ETIME))
    {
      // Found!!!
      // Set the flag
      found = 1;

      // Tell the <svc_handler> that it should prepare itself for
      // being recycled.
      if (this->prepare_for_recycling (sh) == -1)
        return -1;

      return 0;
    }
    else
    {
      return -1;
    }
  }

  // Not found...

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

  // Connect using the svc_handler.
  if (this->cached_connect (potential_handler,
                            remote_addr,
                            timeout,
                            local_addr,
                            reuse_addr,
                            flags,
                            perms) == -1)
    {
      // Close the svc handler.
      potential_handler->close (0);

      return -1;
    }
    else
    {
      // Insert the new SVC_HANDLER instance into the cache.
      if (this->connection_cache_.bind (search_addr,
                                        potential_handler,
                                        entry) == -1)
        {
          // Close the svc handler and reset <sh>.
          potential_handler->close (0);

          return -1;
        }

      // Everything succeeded as planned. Assign <sh> to
      // <potential_handler>.
      sh = potential_handler;

      // Set the recycler and the recycling act

      this->assign_recycler (sh, this, entry);
    }

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::cached_connect (SVC_HANDLER *&sh,
                                                        const ACE_PEER_CONNECTOR_ADDR &remote_addr,
                                                        ACE_Time_Value *timeout,
                                                        const ACE_PEER_CONNECTOR_ADDR &local_addr,
                                                        bool reuse_addr,
                                                        int flags,
                                                        int perms)
{
  // Actively establish the connection.  This is a timed blocking
  // connect.
  if (this->new_connection (sh,
                            remote_addr,
                            timeout,
                            local_addr,
                            reuse_addr,
                            flags,
                            perms) == -1)
    {
      // If connect() failed because of timeouts, we have to reject
      // the connection entirely. This is necessary since currently
      // there is no way for the non-blocking connects to complete and
      // for the <Connector> to notify the cache of the completion of
      // connect().

      if (errno == EWOULDBLOCK || errno == ETIMEDOUT)
        errno = ENOTSUP;
      else if (ACE::out_of_handles (errno) || errno == EADDRINUSE)
        {
          // If the connect failed due to the process running out of
          // file descriptors then, auto_purging of some connections
          // are done from the CONNECTION_CACHE. This frees the
          // descriptors which get used in the connect process and
          // hence the same method is called again!
          if (this->purge_connections () == -1)
            return -1;

          // Try connecting again.
          if (this->new_connection (sh,
                                    remote_addr,
                                    timeout,
                                    local_addr,
                                    reuse_addr,
                                    flags,
                                    perms) == -1)
            {
              if (errno == EWOULDBLOCK || errno == ETIMEDOUT)
                errno = ENOTSUP;
              return -1;
            }
        }
      else
        {
          return -1;
        }
    }

  return 0;

}


template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::connect_svc_handler_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 bool reuse_addr,
 int flags,
 int perms,
 int& found)
{
  CONNECTION_CACHE_ENTRY *entry = 0;

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

      // Increment the refcount
      entry->ext_id_.increment ();
    }

  if (entry)
    {
      // For all successful cases: mark the <svc_handler> in the cache
      // as being <in_use>.  Therefore recyclable is BUSY.
      entry->ext_id_.recycle_state (ACE_RECYCLABLE_BUSY);
    }

  return 0;
}


template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::cache_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  entry->ext_id_.recycle_state (ACE_RECYCLABLE_IDLE_AND_PURGABLE);

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::recycle_state_i (const void *recycling_act,
                                                         ACE_Recyclable_State new_state)
{
  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  entry->ext_id_.recycle_state (new_state);

  return 0;
}

template<class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> ACE_Recyclable_State
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::recycle_state_i (const void *recycling_act) const
{
  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as not being <in_use>.
  // Therefore recyclable is IDLE.
  return entry->ext_id_.recycle_state ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::purge_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  return this->connection_cache_.unbind (entry);
}


template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::mark_as_closed_i (const void *recycling_act)
{
  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  // Mark the <svc_handler> in the cache as CLOSED.
  entry->ext_id_.recycle_state (ACE_RECYCLABLE_CLOSED);

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::cleanup_hint_i (const void *recycling_act,
                                                        void **act_holder)
{
  // Reset the <*act_holder> in the confines and protection of the
  // lock.
  if (act_holder)
    *act_holder = 0;

  // The wonders and perils of ACT
  CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *) recycling_act;

  // Decrement the refcount on the <svc_handler>.
  int refcount = entry->ext_id_.decrement ();

  // If the svc_handler state is closed and the refcount == 0, call
  // close() on svc_handler.
  if (entry->ext_id_.recycle_state () == ACE_RECYCLABLE_CLOSED &&
      refcount == 0)
    {
      entry->int_id_.first->recycler (0, 0);
      entry->int_id_.first->close ();
      this->purge_i (entry);
    }

  return 0;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::purge_connections (void)
{
  return this->connection_cache_.purge ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> CACHING_STRATEGY &
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::caching_strategy (void)
{
  return this->connection_cache_.caching_strategy ();
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> int
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::find (ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR> &search_addr,
                                              ACE_Hash_Map_Entry<ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR>, std::pair<SVC_HANDLER *, ATTRIBUTES> > *&entry)
{
  typedef ACE_Hash_Map_Bucket_Iterator<REFCOUNTED_HASH_RECYCLABLE_ADDRESS,
                                       std::pair<SVC_HANDLER *, ATTRIBUTES>,
                                       ACE_Hash<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>,
                                       ACE_Equal_To<REFCOUNTED_HASH_RECYCLABLE_ADDRESS>,
                                       ACE_Null_Mutex>
    CONNECTION_CACHE_BUCKET_ITERATOR;

  CONNECTION_CACHE_BUCKET_ITERATOR iterator (this->connection_cache_.map (),
                                             search_addr);

  CONNECTION_CACHE_BUCKET_ITERATOR end (this->connection_cache_.map (),
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

      //
      // Update the caching attributes directly since we don't do a
      // find() on the cache map.
      //

      // Indicates successful find.
      int find_result = 0;

      int result = this->caching_strategy ().notify_find (find_result,
                                                          entry->int_id_.second);

      if (result == -1)
        return result;

      return 0;
    }

  return -1;
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX> void
ACE_Cached_Connect_Strategy_Ex<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::cleanup (void)
{
  // Excluded other threads from changing the cache while we cleanup
  ACE_GUARD (MUTEX, ace_mon, *this->lock_);

  // Close down all cached service handlers.
  typename CONNECTION_CACHE::ITERATOR iter = this->connection_cache_.begin ();
  while (iter != this->connection_cache_.end ())
    {
      if ((*iter).second () != 0)
        {
          // save entry for future use
          CONNECTION_CACHE_ENTRY *entry = (CONNECTION_CACHE_ENTRY *)
            (*iter).second ()->recycling_act ();

          // close handler
          (*iter).second ()->recycler (0, 0);
          (*iter).second ()->close ();

          // remember next iter
          typename CONNECTION_CACHE::ITERATOR next_iter = iter;
          ++next_iter;

          // purge the item from the hash
          this->purge_i (entry);

          // assign next iter
          iter  = next_iter;
        }
     else
       ++iter;
    }
}

ACE_ALLOC_HOOK_DEFINE(ACE_Cached_Connect_Strategy_Ex)
/////////////////////////////////////////////////////////////////////////

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX>
ACE_Bounded_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::ACE_Bounded_Cached_Connect_Strategy
(size_t max_size,
 CACHING_STRATEGY &caching_s,
 ACE_Creation_Strategy<SVC_HANDLER> *cre_s,
 ACE_Concurrency_Strategy<SVC_HANDLER> *con_s,
 ACE_Recycling_Strategy<SVC_HANDLER> *rec_s,
 MUTEX *lock,
 int delete_lock)
  : CCSEBASE (caching_s, cre_s, con_s, rec_s, lock, delete_lock),
    max_size_ (max_size)
{
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX>
ACE_Bounded_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::~ACE_Bounded_Cached_Connect_Strategy(void)
{
}

template <class SVC_HANDLER, ACE_PEER_CONNECTOR_1, class CACHING_STRATEGY, class ATTRIBUTES, class MUTEX>
int
ACE_Bounded_Cached_Connect_Strategy<SVC_HANDLER, ACE_PEER_CONNECTOR_2, CACHING_STRATEGY, ATTRIBUTES, MUTEX>::find_or_create_svc_handler_i
(SVC_HANDLER *&sh,
 const ACE_PEER_CONNECTOR_ADDR &remote_addr,
 ACE_Time_Value *timeout,
 const ACE_PEER_CONNECTOR_ADDR &local_addr,
 bool reuse_addr,
 int flags,
 int perms,
 ACE_Hash_Map_Entry<ACE_Refcounted_Hash_Recyclable<ACE_PEER_CONNECTOR_ADDR>,
 std::pair<SVC_HANDLER *, ATTRIBUTES> > *&entry,
 int &found)
{

  REFCOUNTED_HASH_RECYCLABLE_ADDRESS search_addr (remote_addr);

  // Try to find the address in the cache.  Only if we don't find it
  // do we create a new <SVC_HANDLER> and connect it with the server.
  while (this->find (search_addr, entry) != -1)
    {
      // We found a cached svc_handler.
      // Get the cached <svc_handler>
      sh = entry->int_id_.first ();

      // Is the connection clean?
      int state_result= ACE::handle_ready (sh->peer ().get_handle (),
                                           &ACE_Time_Value::zero,
                                           1, // read ready
                                           0, // write ready
                                           1);// exception ready

      if (state_result == 1)
        {
          // The connection was disconnected during idle.
          // close the svc_handler down.
          if (sh->close () == -1)
            {
              ACE_ASSERT (0);
              return -1;
            }
          sh = 0;
          // and rotate once more...
        }
      else if ((state_result == -1) && (errno == ETIME))
        {
          // Found!!!
          // Set the flag
          found = 1;

          // Tell the <svc_handler> that it should prepare itself for
          // being recycled.
          if (this->prepare_for_recycling (sh) == -1)
            {
              ACE_ASSERT (0);
              return -1;
            }

          return 0;
        }
      else  // some other return value or error...
        {
          ACE_ASSERT (0); // just to see it coming

          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("(%t)ACE_Bounded_Cached_Connect_Strategy<>::")
                      ACE_TEXT ("find_or_create_svc_handler_i - ")
                      ACE_TEXT ("error polling server socket state.\n")));

          return -1;
        }
    }

  // Not found...

  // Set the flag
  found = 0;

  // Check the limit of handlers...
  if ((this->max_size_ > 0) &&
      (this->connection_cache_.current_size () >= this->max_size_))
    {
      // Try to purge idle connections
      if (this->purge_connections () == -1)
        return -1;

      // Check limit again.
      if (this->connection_cache_.current_size () >= this->max_size_)
        // still too much!
        return -1;

      // OK, we have room now...
    }

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

  // Connect using the svc_handler.
  if (this->cached_connect (potential_handler,
                            remote_addr,
                            timeout,
                            local_addr,
                            reuse_addr,
                            flags,
                            perms) == -1)
    {
      // Close the svc handler.
      potential_handler->close (0);
      return -1;
    }
  else
    {
      // Insert the new SVC_HANDLER instance into the cache.
      if (this->connection_cache_.bind (search_addr,
                                        potential_handler,
                                        entry) == -1)
        {
          // Close the svc handler and reset <sh>.
          potential_handler->close (0);

          return -1;
        }

      // Everything succeeded as planned. Assign <sh> to
      // <potential_handler>.
      sh = potential_handler;

      // Set the recycler and the recycling act
      this->assign_recycler (sh, this, entry);
    }

  return 0;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Bounded_Cached_Connect_Strategy)

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_CACHED_CONNECT_STRATEGY_T_CPP */
