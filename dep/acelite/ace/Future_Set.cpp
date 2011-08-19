// $Id: Future_Set.cpp 91626 2010-09-07 10:59:20Z johnnyw $

#ifndef ACE_FUTURE_SET_CPP
#define ACE_FUTURE_SET_CPP

#include "ace/Future_Set.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class T>
ACE_Future_Set<T>::ACE_Future_Set (ACE_Message_Queue<ACE_SYNCH> *new_queue)
  : delete_queue_ (false)
{
  if (new_queue)
    this->future_notification_queue_ = new_queue;
  else
    {
      ACE_NEW (this->future_notification_queue_,
               ACE_Message_Queue<ACE_SYNCH>);
      this->delete_queue_ = true;
    }
}

template <class T>
ACE_Future_Set<T>::~ACE_Future_Set (void)
{
  // Detach ourselves from all remaining futures, if any, in our map.
  typename FUTURE_HASH_MAP::iterator iterator =
    this->future_map_.begin ();

  typename FUTURE_HASH_MAP::iterator end =
    this->future_map_.end ();

  for (;
       iterator != end;
       ++iterator)
    {
      FUTURE_HOLDER *future_holder = (*iterator).int_id_;
      future_holder->item_.detach (this);
      delete future_holder;
    }

  if (this->delete_queue_)
    delete this->future_notification_queue_;
}

template <class T> int
ACE_Future_Set<T>::is_empty () const
{
  return (((ACE_Future_Set<T>*)this)->future_map_.current_size () == 0 );
}

template <class T> int
ACE_Future_Set<T>::insert (ACE_Future<T> &future)
{
  FUTURE_HOLDER *future_holder;
  ACE_NEW_RETURN (future_holder,
                  FUTURE_HOLDER (future),
                  -1);

  FUTURE_REP *future_rep = future.get_rep ();
  int result = this->future_map_.bind (future_rep,
                                       future_holder);

  // If a new map entry was created, then attach to the future,
  // otherwise we were already attached to the future or some error
  // occurred so just delete the future holder.
  if (result == 0)
    // Attach ourself to the ACE_Futures list of observer
    future.attach (this);
  else
    delete future_holder;

  return result;
}

template <class T> void
ACE_Future_Set<T>::update (const ACE_Future<T> &future)
{
  ACE_Message_Block *mb = 0;
  FUTURE &local_future = const_cast<ACE_Future<T> &> (future);

  ACE_NEW (mb,
           ACE_Message_Block ((char *) local_future.get_rep (), 0));

  // Enqueue in priority order.
  this->future_notification_queue_->enqueue (mb, 0);
}

template <class T> int
ACE_Future_Set<T>::next_readable (ACE_Future<T> &future,
                                  ACE_Time_Value *tv)
{
  if (this->is_empty ())
    return 0;

  ACE_Message_Block *mb = 0;
  FUTURE_REP *future_rep = 0;

  // Wait for a "readable future" signal from the message queue.
  if (this->future_notification_queue_->dequeue_head (mb,
                                                      tv) != -1)
    {
      // Extract future rep from the message block.
      future_rep = reinterpret_cast<FUTURE_REP *> (mb->base ());

      // Delete the message block.
      mb->release ();
    }
  else
    return 0;

  // Remove the hash map entry with the specified future rep from our map.
  FUTURE_HOLDER *future_holder;
  if (this->future_map_.find (future_rep,
                              future_holder) != -1)
    {
      future = future_holder->item_;
      this->future_map_.unbind (future_rep);
      delete future_holder;
      return 1;
    }

  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
#endif /* ACE_FUTURE_SET_CPP */
