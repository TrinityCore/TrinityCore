// $Id: Notification_Queue.cpp 81315 2008-04-10 07:14:15Z johnnyw $

#include "ace/Notification_Queue.h"

#if !defined (__ACE_INLINE__)
#include "ace/Notification_Queue.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Guard_T.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_Notification_Queue::
ACE_Notification_Queue()
  : ACE_Copy_Disabled()
  , alloc_queue_()
  , notify_queue_()
  , free_queue_()
{
}

ACE_Notification_Queue::
~ACE_Notification_Queue()
{
  reset();
}

int
ACE_Notification_Queue::
open()
{
  ACE_TRACE ("ACE_Notification_Queue::open");

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->notify_queue_lock_, -1);

  if (!this->free_queue_.is_empty ())
    return 0;

  return allocate_more_buffers();
}

void
ACE_Notification_Queue::
reset()
{
  ACE_TRACE ("ACE_Notification_Queue::reset");

  // Release all the event handlers still in the queue ...
  for (ACE_Notification_Queue_Node * node = notify_queue_.head();
       node != 0;
       node = node->next())
    {
      if (node->get().eh_ == 0)
        {
          continue;
        }
      (void) node->get().eh_->remove_reference();
    }

  // ... free up the dynamically allocated resources ...
  ACE_Notification_Queue_Node **b = 0;
  for (ACE_Unbounded_Queue_Iterator<ACE_Notification_Queue_Node *> alloc_iter (this->alloc_queue_);
       alloc_iter.next (b) != 0;
       alloc_iter.advance ())
    {
      delete [] *b;
      *b = 0;
    }

  // ... cleanup the list of allocated blocks ...
  this->alloc_queue_.reset ();

  // ... swap with empty lists to reset the contents ...
  Buffer_List().swap(notify_queue_);
  Buffer_List().swap(free_queue_);
}

int ACE_Notification_Queue::
allocate_more_buffers()
{
  ACE_TRACE ("ACE_Notification_Queue::allocate_more_buffers");

  ACE_Notification_Queue_Node *temp = 0;

  ACE_NEW_RETURN (temp,
                  ACE_Notification_Queue_Node[ACE_REACTOR_NOTIFICATION_ARRAY_SIZE],
                  -1);

  if (this->alloc_queue_.enqueue_head (temp) == -1)
    {
      delete [] temp;
      return -1;
    }

  for (size_t i = 0; i < ACE_REACTOR_NOTIFICATION_ARRAY_SIZE; ++i)
    {
      free_queue_.push_front(temp + i);
    }

  return 0;
}

int
ACE_Notification_Queue::
purge_pending_notifications(ACE_Event_Handler * eh,
                            ACE_Reactor_Mask mask)
{
  ACE_TRACE ("ACE_Notification_Queue::purge_pending_notifications");

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->notify_queue_lock_, -1);

  if (this->notify_queue_.is_empty ())
    return 0;

  int number_purged = 0;
  ACE_Notification_Queue_Node * node = notify_queue_.head();
  while(node != 0)
    {
      if (!node->matches_for_purging(eh))
        {
          // Easy case, skip to the next node
          node = node->next();
          continue;
        }

      if (!node->mask_disables_all_notifications(mask))
        {
          // ... another easy case, skip this node too, but clear the
          // mask first ...
          node->clear_mask(mask);
          node = node->next();
          continue;
        }

      // ... this is the more complicated case, we want to remove the
      // node from the notify_queue_ list.  First save the next node
      // on the list:
      ACE_Notification_Queue_Node * next = node->next();

      // ... then remove it ...
      notify_queue_.unsafe_remove(node);
      ++number_purged;

      // ... release resources ...
      ACE_Event_Handler *event_handler = node->get().eh_;
      event_handler->remove_reference ();

      // ... now this is a free node ...
      free_queue_.push_front(node);

      // ... go to the next node, if there is one ...
      node = next;
    }

  return number_purged;
}

int ACE_Notification_Queue::
push_new_notification(
  ACE_Notification_Buffer const & buffer)
{
  ACE_TRACE ("ACE_Notification_Queue::push_new_notification");

  bool notification_required = false;

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->notify_queue_lock_, -1);

  // No pending notifications.
  if (this->notify_queue_.is_empty ())
    notification_required = true;

  if (free_queue_.is_empty())
    {
      if (allocate_more_buffers() == -1)
        {
          return -1;
        }
    }

  ACE_Notification_Queue_Node * node =
    free_queue_.pop_front();

  ACE_ASSERT (node != 0);
  node->set(buffer);

  notify_queue_.push_back(node);

  if (!notification_required)
    {
      return 0;
    }

  return 1;
}

int
ACE_Notification_Queue::pop_next_notification(
  ACE_Notification_Buffer & current,
  bool & more_messages_queued,
  ACE_Notification_Buffer & next)
{
  ACE_TRACE ("ACE_Notification_Queue::pop_next_notification");

  more_messages_queued = false;

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX, mon, this->notify_queue_lock_, -1);

  if (notify_queue_.is_empty ())
    {
      return 0;
    }

  ACE_Notification_Queue_Node * node =
    notify_queue_.pop_front();

  current = node->get();
  free_queue_.push_front(node);

  if(!this->notify_queue_.is_empty())
    {
      more_messages_queued = true;
      next = notify_queue_.head()->get();
    }

  return 1;
}

ACE_END_VERSIONED_NAMESPACE_DECL

