// $Id: Message_Queue_T.cpp 82574 2008-08-08 19:35:06Z parsons $

#ifndef ACE_MESSAGE_QUEUE_T_CPP
#define ACE_MESSAGE_QUEUE_T_CPP

// #include Message_Queue.h instead of Message_Queue_T.h to avoid
// circular include problems.
#include "ace/Message_Queue.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_time.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Notification_Strategy.h"
#include "ace/Truncate.h"

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Monitor_Size.h"
#endif /* ACE_HAS_MONITOR_POINTS==1 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue)
ACE_ALLOC_HOOK_DEFINE(ACE_Dynamic_Message_Queue)
ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Ex)
ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Ex_N)

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dump");

  this->queue_.dump ();
#endif /* ACE_HAS_DUMP */
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_bytes (size_t new_value)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_bytes");

  this->queue_.message_bytes (new_value);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_length (size_t new_value)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_length");

  this->queue_.message_length (new_value);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::ACE_Message_Queue_Ex (size_t hwm,
                                                                             size_t lwm,
                                                                             ACE_Notification_Strategy *ns)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::ACE_Message_Queue_Ex");

  if (this->queue_.open (hwm, lwm, ns) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("ACE_Message_Queue_Ex")));
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::~ACE_Message_Queue_Ex (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::~ACE_Message_Queue_Ex");
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::open (size_t hwm,
                                                             size_t lwm,
                                                             ACE_Notification_Strategy *ns)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::open");

  return this->queue_.open (hwm, lwm, ns);
}

// Clean up the queue if we have not already done so!

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::close (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::close");

  return this->queue_.close ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::flush (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::flush");

  return this->queue_.flush ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::flush_i (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::flush_i");

  return this->queue_.flush_i ();
}

// Take a look at the first item without removing it.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::peek_dequeue_head (ACE_MESSAGE_TYPE *&first_item,
                                                                          ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::peek_dequeue_head");

  ACE_Message_Block *mb = 0;

  int const cur_count = this->queue_.peek_dequeue_head (mb, timeout);

  if (cur_count != -1)
    first_item  = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());

  return cur_count;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_head (ACE_MESSAGE_TYPE *new_item,
                                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_head");

  ACE_Message_Block *mb = 0;

  ACE_NEW_RETURN (mb,
                  ACE_Message_Block ((char *) new_item,
                                     sizeof (*new_item),
                                     ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::DEFAULT_PRIORITY),
                  -1);

  int const result = this->queue_.enqueue_head (mb, timeout);
  if (result == -1)
    // Zap the message.
    mb->release ();
  return result;
}

// Enqueue an <ACE_MESSAGE_TYPE *> into the <Message_Queue> in
// accordance with its <msg_priority> (0 is lowest priority).  Returns
// -1 on failure, else the number of items still on the queue.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue (ACE_MESSAGE_TYPE *new_item,
                                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue");

  return this->enqueue_prio (new_item, timeout);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_prio (ACE_MESSAGE_TYPE *new_item,
                                                                     ACE_Time_Value *timeout,
                                                                     unsigned long priority)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_prio");

  ACE_Message_Block *mb = 0;

  ACE_NEW_RETURN (mb,
                  ACE_Message_Block ((char *) new_item,
                                     sizeof (*new_item),
                                     priority),
                  -1);

  int const result = this->queue_.enqueue_prio (mb, timeout);
  if (result == -1)
    // Zap the message.
    mb->release ();

  return result;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_deadline (ACE_MESSAGE_TYPE *new_item,
                                                                         ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_deadline");

  ACE_Message_Block *mb = 0;

  ACE_NEW_RETURN (mb,
                  ACE_Message_Block ((char *) new_item,
                                     sizeof (*new_item),
                                     ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::DEFAULT_PRIORITY ),
                  -1);

  int const result = this->queue_.enqueue_deadline (mb, timeout);
  if (result == -1)
    // Zap the message.
    mb->release ();

  return result;
}

// Block indefinitely waiting for an item to arrive,
// does not ignore alerts (e.g., signals).

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_tail (ACE_MESSAGE_TYPE *new_item,
                                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_tail");

  ACE_Message_Block *mb = 0;

  ACE_NEW_RETURN (mb,
                  ACE_Message_Block ((char *) new_item,
                                     sizeof (*new_item),
                                     ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::DEFAULT_PRIORITY),
                  -1);

  int const result = this->queue_.enqueue_tail (mb, timeout);
  if (result == -1)
    // Zap the message.
    mb->release ();
  return result;
}

// Remove an item from the front of the queue.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_head (ACE_MESSAGE_TYPE *&first_item,
                                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_head");

  ACE_Message_Block *mb = 0;

  int const cur_count = this->queue_.dequeue_head (mb, timeout);

  // Dequeue the message.
  if (cur_count != -1)
    {
      first_item = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());
      // Delete the message block.
      mb->release ();
    }

  return cur_count;
}

// Remove the item with the lowest priority from the queue.  If timeout == 0
// block indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_prio (ACE_MESSAGE_TYPE *&dequeued,
                                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_prio");

  ACE_Message_Block *mb = 0;

  int const cur_count = this->queue_.dequeue_prio (mb, timeout);

  // Dequeue the message.
  if (cur_count != -1)
    {
      dequeued = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());
      // Delete the message block.
      mb->release ();
    }

  return cur_count;
}

// Remove an item from the end of the queue.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_tail (ACE_MESSAGE_TYPE *&dequeued,
                                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_tail");

  ACE_Message_Block *mb = 0;

  int const cur_count = this->queue_.dequeue_tail (mb, timeout);

  // Dequeue the message.
  if (cur_count != -1)
    {
      dequeued = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());
      // Delete the message block.
      mb->release ();
    }

  return cur_count;
}

// Remove an item with the lowest deadline time.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_deadline (ACE_MESSAGE_TYPE *&dequeued,
                                                                         ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue_deadline");

  ACE_Message_Block *mb = 0;

  int const cur_count = this->queue_.dequeue_deadline (mb, timeout);

  // Dequeue the message.
  if (cur_count != -1)
    {
      dequeued = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());
      // Delete the message block.
      mb->release ();
    }

  return cur_count;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notify (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notify");

  return this->queue_.notify ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::
ACE_Message_Queue_Ex_Iterator (ACE_Message_Queue_Ex <ACE_MESSAGE_TYPE, ACE_SYNCH_USE> & queue)
: iter_ (queue.queue_)
{

}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::
next (ACE_MESSAGE_TYPE *&entry)
{
  ACE_Message_Block * mb = 0;
  int retval = this->iter_.next (mb);

  if (retval == 1)
    entry = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());

  return retval;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::done (void) const
{
  return this->iter_.done ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::advance (void)
{
  return this->iter_.advance ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dump (void) const
{
  this->iter_.dump ();
}

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Ex_Iterator)

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::
ACE_Message_Queue_Ex_Reverse_Iterator (ACE_Message_Queue_Ex <ACE_MESSAGE_TYPE, ACE_SYNCH_USE> & queue)
: iter_ (queue.queue_)
{

}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::
next (ACE_MESSAGE_TYPE *&entry)
{
  ACE_Message_Block * mb = 0;
  int retval = this->iter_.next (mb);

  if (retval == 1)
    entry = reinterpret_cast<ACE_MESSAGE_TYPE *> (mb->base ());

  return retval;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::done (void) const
{
  return this->iter_.done ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::advance (void)
{
  return this->iter_.advance ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dump (void) const
{
  this->iter_.dump ();
}

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Ex_Reverse_Iterator)

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::ACE_Message_Queue_Ex_N
  (size_t high_water_mark,
   size_t low_water_mark,
   ACE_Notification_Strategy *ns):
    ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE> (high_water_mark,
                                                           low_water_mark,
                                                           ns)
{
  ACE_TRACE ("ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::ACE_Message_Queue_Ex_N");
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::~ACE_Message_Queue_Ex_N (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::~ACE_Message_Queue_Ex_N");
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_head
  (ACE_MESSAGE_TYPE *new_item,
   ACE_Time_Value   *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_head");

  // Create a chained ACE_Message_Blocks wrappers around the 'chained'
  // ACE_MESSAGE_TYPES.
  ACE_Message_Block *mb = this->wrap_with_mbs_i (new_item);
  if (0 == mb)
    {
      return -1;
    }

  int result = this->queue_.enqueue_head (mb, timeout);
  if (-1 == result)
    {
      // Zap the messages.
      mb->release ();
    }
  return result;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_tail
  (ACE_MESSAGE_TYPE *new_item,
   ACE_Time_Value   *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::enqueue_tail");

  // Create a chained ACE_Message_Blocks wrappers around the 'chained'
  // ACE_MESSAGE_TYPES.
  ACE_Message_Block *mb = this->wrap_with_mbs_i (new_item);
  if (0 == mb)
    {
      return -1;
    }

  int result = this->queue_.enqueue_tail (mb, timeout);
  if (-1 == result)
    {
      // Zap the message.
      mb->release ();
    }
  return result;
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> ACE_Message_Block *
ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::wrap_with_mbs_i
  (ACE_MESSAGE_TYPE *new_item)
{
  ACE_TRACE ("ACE_Message_Queue_Ex_N<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::wrap_with_mbs_i");

  // We need to keep a reference to the head of the chain
  ACE_Message_Block *mb_head = 0;

  ACE_NEW_RETURN (mb_head,
                  ACE_Message_Block ((char *) new_item,
                                     sizeof (*new_item),
                                     ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::DEFAULT_PRIORITY),
                  0);

  // mb_tail will point to the last ACE_Message_Block
  ACE_Message_Block *mb_tail = mb_head;

  // Run through rest of the messages and wrap them
  for (ACE_MESSAGE_TYPE *pobj = new_item->next (); pobj; pobj = pobj->next ())
    {
      ACE_Message_Block *mb_temp = 0;
      ACE_NEW_NORETURN (mb_temp,
                        ACE_Message_Block ((char *) pobj,
                                           sizeof (*pobj),
                                           ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::DEFAULT_PRIORITY));
      if (mb_temp == 0)
        {
          mb_head->release ();
          mb_head = 0;
          break;
        }

      mb_tail->next (mb_temp);
      mb_tail = mb_temp;
    }

  return mb_head;
}

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Reverse_Iterator)

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue (ACE_MESSAGE_TYPE *&first_item,
                                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::dequeue");

  return this->dequeue_head (first_item, timeout);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> ACE_Notification_Strategy *
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notification_strategy (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notification_strategy");

  return this->queue_.notification_strategy ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notification_strategy (ACE_Notification_Strategy *s)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::notification_strategy");

  this->queue_.notification_strategy (s);
}

// Check if queue is empty (holds locks).

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> bool
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::is_empty (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::is_empty");

  return this->queue_.is_empty ();
}

// Check if queue is full (holds locks).

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> bool
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::is_full (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::is_full");

  return this->queue_.is_full ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> size_t
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::high_water_mark (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::high_water_mark");

  return this->queue_.high_water_mark ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::high_water_mark (size_t hwm)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::high_water_mark");

  this->queue_.high_water_mark (hwm);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> size_t
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::low_water_mark (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::low_water_mark");

  return this->queue_.low_water_mark ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> void
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::low_water_mark (size_t lwm)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::low_water_mark");

  this->queue_.low_water_mark (lwm);
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> size_t
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_bytes (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_bytes");

  return this->queue_.message_bytes ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> size_t
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_length (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_length");

  return this->queue_.message_length ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> size_t
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_count (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::message_count");

  return this->queue_.message_count ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::deactivate (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::deactivate");

  return this->queue_.deactivate ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::activate (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::activate");

  return this->queue_.activate ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::pulse (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::pulse");

  return this->queue_.pulse ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::deactivated (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::deactivated");

  return this->queue_.deactivated ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> int
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::state (void)
{
  ACE_TRACE ("ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::state");

  return this->queue_.state ();
}

template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> ACE_SYNCH_MUTEX_T &
ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>::lock (void)
{
  return this->queue_.lock ();
}

template <ACE_SYNCH_DECL>
ACE_Message_Queue_Iterator<ACE_SYNCH_USE>::ACE_Message_Queue_Iterator (ACE_Message_Queue <ACE_SYNCH_USE> &q)
  : queue_ (q),
    curr_ (q.head_)
{
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Iterator<ACE_SYNCH_USE>::next (ACE_Message_Block *&entry)
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  if (this->curr_ != 0)
    {
      entry = this->curr_;
      return 1;
    }

  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Iterator<ACE_SYNCH_USE>::done (void) const
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  return this->curr_ == 0;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Iterator<ACE_SYNCH_USE>::advance (void)
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  if (this->curr_)
    this->curr_ = this->curr_->next ();
  return this->curr_ != 0;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue_Iterator<ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
#endif /* ACE_HAS_DUMP */
}

ACE_ALLOC_HOOK_DEFINE(ACE_Message_Queue_Iterator)

template <ACE_SYNCH_DECL>
ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>::ACE_Message_Queue_Reverse_Iterator (ACE_Message_Queue <ACE_SYNCH_USE> &q)
  : queue_ (q),
    curr_ (queue_.tail_)
{
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>::next (ACE_Message_Block *&entry)
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  if (this->curr_ != 0)
    {
      entry = this->curr_;
      return 1;
    }

  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>::done (void) const
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  return this->curr_ == 0;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>::advance (void)
{
  ACE_READ_GUARD_RETURN (ACE_SYNCH_MUTEX_T, m, this->queue_.lock_, -1)

  if (this->curr_)
    this->curr_ = this->curr_->prev ();
  return this->curr_ != 0;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
#endif /* ACE_HAS_DUMP */
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue (ACE_Message_Block *&first_item,
                                           ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue");
  return this->dequeue_head (first_item, timeout);
}

template <ACE_SYNCH_DECL> ACE_Notification_Strategy *
ACE_Message_Queue<ACE_SYNCH_USE>::notification_strategy (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::notification_strategy");

  return this->notification_strategy_;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::notification_strategy (ACE_Notification_Strategy *s)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::notification_strategy");

  this->notification_strategy_ = s;
}

// Check if queue is empty (does not hold locks).

template <ACE_SYNCH_DECL> bool
ACE_Message_Queue<ACE_SYNCH_USE>::is_empty_i (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::is_empty_i");
  return this->tail_ == 0;
}

// Check if queue is full (does not hold locks).

template <ACE_SYNCH_DECL> bool
ACE_Message_Queue<ACE_SYNCH_USE>::is_full_i (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::is_full_i");
  return this->cur_bytes_ >= this->high_water_mark_;
}

// Check if queue is empty (holds locks).

template <ACE_SYNCH_DECL> bool
ACE_Message_Queue<ACE_SYNCH_USE>::is_empty (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::is_empty");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, false);

  return this->is_empty_i ();
}

// Check if queue is full (holds locks).

template <ACE_SYNCH_DECL> bool
ACE_Message_Queue<ACE_SYNCH_USE>::is_full (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::is_full");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, false);

  return this->is_full_i ();
}

template <ACE_SYNCH_DECL> size_t
ACE_Message_Queue<ACE_SYNCH_USE>::high_water_mark (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::high_water_mark");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, 0);

  return this->high_water_mark_;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::high_water_mark (size_t hwm)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::high_water_mark");
  ACE_GUARD (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_);

  this->high_water_mark_ = hwm;
}

template <ACE_SYNCH_DECL> size_t
ACE_Message_Queue<ACE_SYNCH_USE>::low_water_mark (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::low_water_mark");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, 0);

  return this->low_water_mark_;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::low_water_mark (size_t lwm)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::low_water_mark");
  ACE_GUARD (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_);

  this->low_water_mark_ = lwm;
}

template <ACE_SYNCH_DECL> size_t
ACE_Message_Queue<ACE_SYNCH_USE>::message_bytes (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::message_bytes");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, 0);

  return this->cur_bytes_;
}

template <ACE_SYNCH_DECL> size_t
ACE_Message_Queue<ACE_SYNCH_USE>::message_length (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::message_length");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, 0);

  return this->cur_length_;
}

template <ACE_SYNCH_DECL> size_t
ACE_Message_Queue<ACE_SYNCH_USE>::message_count (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::message_count");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, 0);

  return this->cur_count_;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::deactivate ()
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::deactivate");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  return this->deactivate_i (0);   // Not a pulse
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::activate (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::activate");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  return this->activate_i ();
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::pulse ()
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::pulse");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  return this->deactivate_i (1);   // Just a pulse
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::deactivated (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::deactivated");

  return this->state_ == ACE_Message_Queue_Base::DEACTIVATED;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::state (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::state");

  return this->state_;
}

template <ACE_SYNCH_DECL> ACE_SYNCH_MUTEX_T &
ACE_Message_Queue<ACE_SYNCH_USE>::lock (void)
{
  return this->lock_;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  switch (this->state_)
    {
    case ACE_Message_Queue_Base::ACTIVATED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = ACTIVATED\n")));
      break;
    case ACE_Message_Queue_Base::DEACTIVATED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = DEACTIVATED\n")));
      break;
    case ACE_Message_Queue_Base::PULSED:
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("state = PULSED\n")));
      break;
    }
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("low_water_mark = %d\n")
              ACE_TEXT ("high_water_mark = %d\n")
              ACE_TEXT ("cur_bytes = %d\n")
              ACE_TEXT ("cur_length = %d\n")
              ACE_TEXT ("cur_count = %d\n")
              ACE_TEXT ("head_ = %u\n")
              ACE_TEXT ("tail_ = %u\n"),
              this->low_water_mark_,
              this->high_water_mark_,
              this->cur_bytes_,
              this->cur_length_,
              this->cur_count_,
              this->head_,
              this->tail_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("not_full_cond: \n")));
  not_full_cond_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("not_empty_cond: \n")));
  not_empty_cond_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::message_bytes (size_t new_value)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::message_bytes");
  ACE_GUARD (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_);

  this->cur_bytes_ = new_value;
}

template <ACE_SYNCH_DECL> void
ACE_Message_Queue<ACE_SYNCH_USE>::message_length (size_t new_value)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::message_length");
  ACE_GUARD (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_);

  this->cur_length_ = new_value;
}

template <ACE_SYNCH_DECL>
ACE_Message_Queue<ACE_SYNCH_USE>::ACE_Message_Queue (size_t hwm,
                                                     size_t lwm,
                                                     ACE_Notification_Strategy *ns)
  : not_empty_cond_ (lock_)
  , not_full_cond_ (lock_)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::ACE_Message_Queue");

  if (this->open (hwm, lwm, ns) == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("open")));

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE_NEW (this->monitor_,
           ACE::Monitor_Control::Size_Monitor);

  /// Make a unique name using our process id and hex address.
  char pid_buf[sizeof (int) + 1];
  ACE_OS::sprintf (pid_buf, "%d", ACE_OS::getpid ());
  pid_buf[sizeof (int)] = '\0';
  
  const int addr_nibbles = 2 * sizeof (ptrdiff_t);
  char addr_buf[addr_nibbles + 1];
  ACE_OS::sprintf (addr_buf, "%p", this);
  addr_buf[addr_nibbles] = '\0';
  
  ACE_CString name_str ("Message_Queue_");
  name_str += pid_buf;
  name_str += '_';
  name_str += addr_buf;
  this->monitor_->name (name_str.c_str ());
  this->monitor_->add_to_registry ();
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

template <ACE_SYNCH_DECL>
ACE_Message_Queue<ACE_SYNCH_USE>::~ACE_Message_Queue (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::~ACE_Message_Queue");
  if (this->head_ != 0 && this->close () == -1)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("close")));

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->remove_from_registry ();
  this->monitor_->remove_ref ();
#endif /* ACE_HAS_MONITOR_POINTS==1 */
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::flush_i (void)
{
  int number_flushed = 0;

  // Remove all the <ACE_Message_Block>s in the <ACE_Message_Queue>
  // and <release> their memory.
  for (this->tail_ = 0; this->head_ != 0; )
    {
      ++number_flushed;

      size_t mb_bytes = 0;
      size_t mb_length = 0;
      this->head_->total_size_and_length (mb_bytes,
                                          mb_length);
      // Subtract off all of the bytes associated with this message.
      this->cur_bytes_ -= mb_bytes;
      this->cur_length_ -= mb_length;
      --this->cur_count_;

      ACE_Message_Block *temp = this->head_;
      this->head_ = this->head_->next ();

      // Make sure to use <release> rather than <delete> since this is
      // reference counted.
      temp->release ();
    }

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  // The monitor should output only if the size has actually changed.
  if (number_flushed > 0)
    {
      this->monitor_->receive (this->cur_length_);
    }
#endif

  return number_flushed;
}

// Don't bother locking since if someone calls this function more than
// once for the same queue, we're in bigger trouble than just
// concurrency control!

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::open (size_t hwm,
                                        size_t lwm,
                                        ACE_Notification_Strategy *ns)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::open");
  this->high_water_mark_ = hwm;
  this->low_water_mark_  = lwm;
  this->state_ = ACE_Message_Queue_Base::ACTIVATED;
  this->cur_bytes_ = 0;
  this->cur_length_ = 0;
  this->cur_count_ = 0;
  this->tail_ = 0;
  this->head_ = 0;
  this->notification_strategy_ = ns;
  return 0;
}

// Implementation of the public deactivate() method
// (assumes locks are held).

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::deactivate_i (int pulse)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::deactivate_i");
  int const previous_state = this->state_;

  if (previous_state != ACE_Message_Queue_Base::DEACTIVATED)
    {
      // Wakeup all waiters.
      this->not_empty_cond_.broadcast ();
      this->not_full_cond_.broadcast ();

      if (pulse)
        this->state_ = ACE_Message_Queue_Base::PULSED;
      else
        this->state_ = ACE_Message_Queue_Base::DEACTIVATED;
    }
  return previous_state;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::activate_i (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::activate_i");
  int const previous_state = this->state_;
  this->state_ = ACE_Message_Queue_Base::ACTIVATED;
  return previous_state;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::flush (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::flush");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  // Free up the remaining messages on the queue.
  return this->flush_i ();
}

// Clean up the queue if we have not already done so!

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::close (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::close");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  int const result = this->deactivate_i ();

  // Free up the remaining messages on the queue.
  this->flush_i ();

  return result;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::signal_enqueue_waiters (void)
{
  if (this->not_full_cond_.signal () != 0)
    return -1;
  return 0;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::signal_dequeue_waiters (void)
{
  // Tell any blocked threads that the queue has a new item!
  if (this->not_empty_cond_.signal () != 0)
    return -1;
  return 0;
}

// Actually put the node at the end (no locking so must be called with
// locks held).

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_tail_i (ACE_Message_Block *new_item)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_tail_i");

  if (new_item == 0)
    return -1;

  // Update the queued size and length, taking into account any chained
  // blocks (total_size_and_length() counts all continuation blocks).
  // Keep count of how many blocks we're adding and, if there is a chain of
  // blocks, find the end in seq_tail and be sure they're properly
  // back-connected along the way.
  ACE_Message_Block *seq_tail = new_item;
  ++this->cur_count_;
  new_item->total_size_and_length (this->cur_bytes_,
                                   this->cur_length_);
  while (seq_tail->next () != 0)
    {
      seq_tail->next ()->prev (seq_tail);
      seq_tail = seq_tail->next ();
      ++this->cur_count_;
      seq_tail->total_size_and_length (this->cur_bytes_,
                                       this->cur_length_);
    }

  // List was empty, so build a new one.
  if (this->tail_ == 0)
    {
      this->head_ = new_item;
      this->tail_ = seq_tail;
      // seq_tail->next (0);   This is a condition of the while() loop above.
      new_item->prev (0);
    }
  // Link at the end.
  else
    {
      // seq_tail->next (0);   This is a condition of the while() loop above.
      this->tail_->next (new_item);
      new_item->prev (this->tail_);
      this->tail_ = seq_tail;
    }

  if (this->signal_dequeue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Actually put the node(s) at the head (no locking)

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_head_i (ACE_Message_Block *new_item)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_head_i");

  if (new_item == 0)
    return -1;

  // Update the queued size and length, taking into account any chained
  // blocks (total_size_and_length() counts all continuation blocks).
  // Keep count of how many blocks we're adding and, if there is a chain of
  // blocks, find the end in seq_tail and be sure they're properly
  // back-connected along the way.
  ACE_Message_Block *seq_tail = new_item;
  ++this->cur_count_;
  new_item->total_size_and_length (this->cur_bytes_,
                                   this->cur_length_);
  while (seq_tail->next () != 0)
    {
      seq_tail->next ()->prev (seq_tail);
      seq_tail = seq_tail->next ();
      ++this->cur_count_;
      seq_tail->total_size_and_length (this->cur_bytes_,
                                       this->cur_length_);
    }

  new_item->prev (0);
  seq_tail->next (this->head_);

  if (this->head_ != 0)
    this->head_->prev (seq_tail);
  else
    this->tail_ = seq_tail;

  this->head_ = new_item;

  if (this->signal_dequeue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Actually put the node at its proper position relative to its
// priority.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_i (ACE_Message_Block *new_item)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_i");

  if (new_item == 0)
    return -1;

  // Since this method uses enqueue_head_i() and enqueue_tail_i() for
  // special situations, and this method doesn't support enqueueing
  // chains of blocks off the 'next' pointer, make sure the new_item's
  // next pointer is 0.
  new_item->next (0);

  if (this->head_ == 0)
    // Check for simple case of an empty queue, where all we need to
    // do is insert <new_item> into the head.
    return this->enqueue_head_i (new_item);
  else
    {
      ACE_Message_Block *temp = 0;

      // Figure out where the new item goes relative to its priority.
      // We start looking from the lowest priority (at the tail) to
      // the highest priority (at the head).

      for (temp = this->tail_;
           temp != 0;
           temp = temp->prev ())
        if (temp->msg_priority () >= new_item->msg_priority ())
          // Break out when we've located an item that has
          // greater or equal priority.
          break;

      if (temp == 0)
        // Check for simple case of inserting at the head of the queue,
        // where all we need to do is insert <new_item> before the
        // current head.
        return this->enqueue_head_i (new_item);
      else if (temp->next () == 0)
        // Check for simple case of inserting at the tail of the
        // queue, where all we need to do is insert <new_item> after
        // the current tail.
        return this->enqueue_tail_i (new_item);
      else
        {
          // Insert the new message behind the message of greater or
          // equal priority.  This ensures that FIFO order is
          // maintained when messages of the same priority are
          // inserted consecutively.
          new_item->prev (temp);
          new_item->next (temp->next ());
          temp->next ()->prev (new_item);
          temp->next (new_item);
        }
    }

  // Make sure to count all the bytes in a composite message!!!
  new_item->total_size_and_length (this->cur_bytes_,
                                   this->cur_length_);
  ++this->cur_count_;

  if (this->signal_dequeue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Actually put the node at its proper position relative to its
// deadline time.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_deadline_i (ACE_Message_Block *new_item)
{
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_deadline_i");

  if (new_item == 0)
    return -1;

  // Since this method uses enqueue_head_i() and enqueue_tail_i() for
  // special situations, and this method doesn't support enqueueing
  // chains of blocks off the 'next' pointer, make sure the new_item's
  // next pointer is 0.
  new_item->next (0);

  if (this->head_ == 0)
    // Check for simple case of an empty queue, where all we need to
    // do is insert <new_item> into the head.
    return this->enqueue_head_i (new_item);
  else
    {
      ACE_Message_Block *temp = 0;

      // Figure out where the new item goes relative to its priority.
      // We start looking from the smallest deadline to the highest
      // deadline.

      for (temp = this->head_;
           temp != 0;
           temp = temp->next ())
        if (new_item->msg_deadline_time () < temp->msg_deadline_time ())
          // Break out when we've located an item that has
          // greater or equal priority.
          break;

      if (temp == 0 || temp->next () == 0)
        // Check for simple case of inserting at the tail of the queue,
        // where all we need to do is insert <new_item> after the
        // current tail.
        return this->enqueue_tail_i (new_item);
      else
        {
          // Insert the new message behind the message of
          // lesser or equal deadline time.  This ensures that FIFO order is
          // maintained when messages of the same priority are
          // inserted consecutively.
          new_item->prev (temp);
          new_item->next (temp->next ());
          temp->next ()->prev (new_item);
          temp->next (new_item);
        }
    }

  // Make sure to count all the bytes in a composite message!!!
  new_item->total_size_and_length (this->cur_bytes_,
                                   this->cur_length_);
  ++this->cur_count_;

  if (this->signal_dequeue_waiters () == -1)
    return -1;
  else
    return this->cur_count_;
#else
  return this->enqueue_tail_i (new_item);
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}

// Actually get the first ACE_Message_Block (no locking, so must be
// called with locks held).  This method assumes that the queue has at
// least one item in it when it is called.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_head_i (ACE_Message_Block *&first_item)
{
  if (this->head_ ==0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Attempting to dequeue from empty queue")),
                      -1);
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_head_i");
  first_item = this->head_;
  this->head_ = this->head_->next ();

  if (this->head_ == 0)
    this->tail_ = 0;
  else
    // The prev pointer of first message block must point to 0...
    this->head_->prev (0);

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  first_item->total_size_and_length (mb_bytes,
                                     mb_length);
  // Subtract off all of the bytes associated with this message.
  this->cur_bytes_ -= mb_bytes;
  this->cur_length_ -= mb_length;
  --this->cur_count_;

  if (this->cur_count_ == 0 && this->head_ == this->tail_)
    this->head_ = this->tail_ = 0;

  // Make sure that the prev and next fields are 0!
  first_item->prev (0);
  first_item->next (0);

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->cur_length_);
#endif

  // Only signal enqueueing threads if we've fallen below the low
  // water mark.
  if (this->cur_bytes_ <= this->low_water_mark_
      && this->signal_enqueue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Get the earliest (i.e., FIFO) ACE_Message_Block with the lowest
// priority (no locking, so must be called with locks held).  This
// method assumes that the queue has at least one item in it when it
// is called.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_prio_i (ACE_Message_Block *&dequeued)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_prio_i");

  if (this->head_ == 0)
    return -1;

  // Find the earliest (i.e., FIFO) message enqueued with the lowest
  // priority.
  ACE_Message_Block *chosen = 0;
  u_long priority = ULONG_MAX;

  for (ACE_Message_Block *temp = this->tail_;
       temp != 0;
       temp = temp->prev ())
    {
      // Find the first version of the earliest message (i.e.,
      // preserve FIFO order for messages at the same priority).
      if (temp->msg_priority () <= priority)
        {
          priority = temp->msg_priority ();
          chosen = temp;
        }
    }

  // If every message block is the same priority, pass back the first
  // one.
  if (chosen == 0)
    chosen = this->head_;

  // Patch up the queue.  If we don't have a previous then we are at
  // the head of the queue.
  if (chosen->prev () == 0)
    this->head_ = chosen->next ();
  else
    chosen->prev ()->next (chosen->next ());

  if (chosen->next () == 0)
    this->tail_ = chosen->prev ();
  else
    chosen->next ()->prev (chosen->prev ());

  // Pass back the chosen block
  dequeued = chosen;

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  dequeued->total_size_and_length (mb_bytes,
                                   mb_length);
  // Subtract off all of the bytes associated with this message.
  this->cur_bytes_ -= mb_bytes;
  this->cur_length_ -= mb_length;
  --this->cur_count_;

  if (this->cur_count_ == 0 && this->head_ == this->tail_)
    this->head_ = this->tail_ = 0;

  // Make sure that the prev and next fields are 0!
  dequeued->prev (0);
  dequeued->next (0);

  // Only signal enqueueing threads if we've fallen below the low
  // water mark.
  if (this->cur_bytes_ <= this->low_water_mark_
      && this->signal_enqueue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Actually get the last ACE_Message_Block (no locking, so must be
// called with locks held).  This method assumes that the queue has at
// least one item in it when it is called.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_tail_i (ACE_Message_Block *&dequeued)
{
  if (this->head_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Attempting to dequeue from empty queue")),
                      -1);
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_tail_i");
  dequeued = this->tail_;
  if (this->tail_->prev () == 0)
    {
      this->head_ = 0;
      this->tail_ = 0;
    }
  else
    {
      this->tail_->prev ()->next (0);
      this->tail_ = this->tail_->prev ();
    }

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  dequeued->total_size_and_length (mb_bytes,
                                   mb_length);
  // Subtract off all of the bytes associated with this message.
  this->cur_bytes_ -= mb_bytes;
  this->cur_length_ -= mb_length;
  --this->cur_count_;

  if (this->cur_count_ == 0 && this->head_ == this->tail_)
    this->head_ = this->tail_ = 0;

  // Make sure that the prev and next fields are 0!
  dequeued->prev (0);
  dequeued->next (0);

  // Only signal enqueueing threads if we've fallen below the low
  // water mark.
  if (this->cur_bytes_ <= this->low_water_mark_
      && this->signal_enqueue_waiters () == -1)
    return -1;
  else
    return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

// Actually get the ACE_Message_Block with the lowest deadline time
// (no locking, so must be called with locks held).  This method assumes
// that the queue has at least one item in it when it is called.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_deadline_i (ACE_Message_Block *&dequeued)
{
#if defined (ACE_HAS_TIMED_MESSAGE_BLOCKS)
  if (this->head_ == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("Attempting to dequeue from empty queue")),
                      -1);
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_deadline_i");

  // Find the last message enqueued with the lowest deadline time
  ACE_Message_Block* chosen = 0;
  ACE_Time_Value deadline = ACE_Time_Value::max_time;
  for (ACE_Message_Block *temp = this->head_; temp != 0; temp = temp->next ())
    if (temp->msg_deadline_time () < deadline)
      {
        deadline = temp->msg_deadline_time ();
        chosen = temp;
      }

  // If every message block is the same deadline time,
  // pass back the first one
  if (chosen == 0)
    chosen = this->head_;

  // Patch up the queue.  If we don't have a previous
  // then we are at the head of the queue.
  if (chosen->prev () == 0)
    this->head_ = chosen->next ();
  else
    chosen->prev ()->next (chosen->next ());

  if (chosen->next () == 0)
    this->tail_ = chosen->prev ();
  else
    chosen->next ()->prev (chosen->prev ());

  // Pass back the chosen block
  dequeued = chosen;

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  dequeued->total_size_and_length (mb_bytes,
                                   mb_length);
  // Subtract off all of the bytes associated with this message.
  this->cur_bytes_ -= mb_bytes;
  this->cur_length_ -= mb_length;
  --this->cur_count_;

  if (this->cur_count_ == 0 && this->head_ == this->tail_)
    this->head_ = this->tail_ = 0;

  // Make sure that the prev and next fields are 0!
  dequeued->prev (0);
  dequeued->next (0);

  // Only signal enqueueing threads if we've fallen below the low
  // water mark.
  if (this->cur_bytes_ <= this->low_water_mark_
      && this->signal_enqueue_waiters () == -1)
    return -1;
  else
    return this->cur_count_;
#else
  return this->dequeue_head_i (dequeued);
#endif /* ACE_HAS_TIMED_MESSAGE_BLOCKS */
}

// Take a look at the first item without removing it.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::peek_dequeue_head (ACE_Message_Block *&first_item,
                                                     ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::peek_dequeue_head");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  // Wait for at least one item to become available.

  if (this->wait_not_empty_cond (ace_mon, timeout) == -1)
    return -1;

  first_item = this->head_;
  return ACE_Utils::truncate_cast<int> (this->cur_count_);
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::wait_not_full_cond (ACE_Guard<ACE_SYNCH_MUTEX_T> &,
                                                      ACE_Time_Value *timeout)
{
  int result = 0;

  // Wait while the queue is full.

  while (this->is_full_i ())
    {
      if (this->not_full_cond_.wait (timeout) == -1)
        {
          if (errno == ETIME)
            errno = EWOULDBLOCK;
          result = -1;
          break;
        }
      if (this->state_ != ACE_Message_Queue_Base::ACTIVATED)
        {
          errno = ESHUTDOWN;
          result = -1;
          break;
        }
    }
  return result;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::wait_not_empty_cond
    (ACE_Guard<ACE_SYNCH_MUTEX_T> &, ACE_Time_Value *timeout)
{
  int result = 0;

  // Wait while the queue is empty.

  while (this->is_empty_i ())
    {
      if (this->not_empty_cond_.wait (timeout) == -1)
        {
          if (errno == ETIME)
            errno = EWOULDBLOCK;
          result = -1;
          break;
        }
      if (this->state_ != ACE_Message_Queue_Base::ACTIVATED)
        {
          errno = ESHUTDOWN;
          result = -1;
          break;
        }
    }
  return result;
}

// Block indefinitely waiting for an item to arrive, does not ignore
// alerts (e.g., signals).

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_head (ACE_Message_Block *new_item,
                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_head");
  int queue_count = 0;
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

    if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
      {
        errno = ESHUTDOWN;
        return -1;
      }

    if (this->wait_not_full_cond (ace_mon, timeout) == -1)
      return -1;

    queue_count = this->enqueue_head_i (new_item);

    if (queue_count == -1)
      return -1;

    this->notify ();
  }
  return queue_count;
}

// Enqueue an <ACE_Message_Block *> into the <Message_Queue> in
// accordance with its <msg_priority> (0 is lowest priority).  Returns
// -1 on failure, else the number of items still on the queue.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_prio (ACE_Message_Block *new_item,
                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_prio");
  int queue_count = 0;
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

    if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
      {
        errno = ESHUTDOWN;
        return -1;
      }

    if (this->wait_not_full_cond (ace_mon, timeout) == -1)
      return -1;

    queue_count = this->enqueue_i (new_item);

    if (queue_count == -1)
      return -1;

    this->notify ();
  }
  return queue_count;
}

// Enqueue an <ACE_Message_Block *> into the <Message_Queue> in
// accordance with its <msg_deadline_time>.  Returns
// -1 on failure, else the number of items still on the queue.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_deadline (ACE_Message_Block *new_item,
                                                    ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_deadline");
  int queue_count = 0;
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

    if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
      {
        errno = ESHUTDOWN;
        return -1;
      }

    if (this->wait_not_full_cond (ace_mon, timeout) == -1)
      return -1;

    queue_count = this->enqueue_deadline_i (new_item);

    if (queue_count == -1)
      return -1;

    this->notify ();
  }
  return queue_count;
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue (ACE_Message_Block *new_item,
                                           ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue");
  return this->enqueue_prio (new_item, timeout);
}

// Block indefinitely waiting for an item to arrive,
// does not ignore alerts (e.g., signals).

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_tail (ACE_Message_Block *new_item,
                                              ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::enqueue_tail");
  int queue_count = 0;
  {
    ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

    if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
      {
        errno = ESHUTDOWN;
        return -1;
      }

    if (this->wait_not_full_cond (ace_mon, timeout) == -1)
      return -1;

    queue_count = this->enqueue_tail_i (new_item);

    if (queue_count == -1)
      return -1;

    this->notify ();
  }
  return queue_count;
}

// Remove an item from the front of the queue.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_head (ACE_Message_Block *&first_item,
                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_head");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  if (this->wait_not_empty_cond (ace_mon, timeout) == -1)
    return -1;

  return this->dequeue_head_i (first_item);
}

// Remove item with the lowest priority from the queue.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_prio (ACE_Message_Block *&dequeued,
                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_prio");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  if (this->wait_not_empty_cond (ace_mon, timeout) == -1)
    return -1;

  return this->dequeue_prio_i (dequeued);
}

// Remove an item from the end of the queue.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_tail (ACE_Message_Block *&dequeued,
                                                ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_tail");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  if (this->wait_not_empty_cond (ace_mon, timeout) == -1)
    return -1;

  return this->dequeue_tail_i (dequeued);
}

// Remove an item with the lowest deadline time.  If timeout == 0 block
// indefinitely (or until an alert occurs).  Otherwise, block for upto
// the amount of time specified by timeout.

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_deadline (ACE_Message_Block *&dequeued,
                                                    ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::dequeue_deadline");
  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  if (this->wait_not_empty_cond (ace_mon, timeout) == -1)
    return -1;

  return this->dequeue_deadline_i (dequeued);
}

template <ACE_SYNCH_DECL> int
ACE_Message_Queue<ACE_SYNCH_USE>::notify (void)
{
  ACE_TRACE ("ACE_Message_Queue<ACE_SYNCH_USE>::notify");

#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  this->monitor_->receive (this->cur_length_);
#endif

  // By default, don't do anything.
  if (this->notification_strategy_ == 0)
    return 0;
  else
    return this->notification_strategy_->notify ();
}

// = Initialization and termination methods.
template <ACE_SYNCH_DECL>
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::ACE_Dynamic_Message_Queue (ACE_Dynamic_Message_Strategy & message_strategy,
                                                                     size_t hwm,
                                                                     size_t lwm,
                                                                     ACE_Notification_Strategy *ns)
  : ACE_Message_Queue<ACE_SYNCH_USE> (hwm, lwm, ns),
    pending_head_ (0),
    pending_tail_ (0),
    late_head_ (0),
    late_tail_ (0),
    beyond_late_head_ (0),
    beyond_late_tail_ (0),
    message_strategy_ (message_strategy)
{
  // Note, the ACE_Dynamic_Message_Queue assumes full responsibility
  // for the passed ACE_Dynamic_Message_Strategy object, and deletes
  // it in its own dtor
}

// dtor: free message strategy and let base class dtor do the rest.

template <ACE_SYNCH_DECL>
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::~ACE_Dynamic_Message_Queue (void)
{
  delete &this->message_strategy_;
}

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::remove_messages (ACE_Message_Block *&list_head,
                                                           ACE_Message_Block *&list_tail,
                                                           u_int status_flags)
{
  // start with an empty list
  list_head = 0;
  list_tail = 0;

  // Get the current time
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();

  // Refresh priority status boundaries in the queue.
  int result = this->refresh_queue (current_time);
  if (result < 0)
    return result;

  if (ACE_BIT_ENABLED (status_flags,
                       (u_int) ACE_Dynamic_Message_Strategy::PENDING)
      && this->pending_head_
      && this->pending_tail_)
    {
      // patch up pointers for the new tail of the queue
      if (this->pending_head_->prev ())
        {
          this->tail_ = this->pending_head_->prev ();
          this->pending_head_->prev ()->next (0);
        }
      else
        {
          // the list has become empty
          this->head_ = 0;
          this->tail_ = 0;
        }

      // point to the head and tail of the list
      list_head = this->pending_head_;
      list_tail = this->pending_tail_;

      // cut the pending messages out of the queue entirely
      this->pending_head_->prev (0);
      this->pending_head_ = 0;
      this->pending_tail_ = 0;
    }

  if (ACE_BIT_ENABLED (status_flags,
                       (u_int) ACE_Dynamic_Message_Strategy::LATE)
      && this->late_head_
      && this->late_tail_)
    {
      // Patch up pointers for the (possibly) new head and tail of the
      // queue.
      if (this->late_tail_->next ())
        this->late_tail_->next ()->prev (this->late_head_->prev ());
      else
        this->tail_ = this->late_head_->prev ();

      if (this->late_head_->prev ())
        this->late_head_->prev ()->next (this->late_tail_->next ());
      else
        this->head_ = this->late_tail_->next ();

      // put late messages behind pending messages (if any) being returned
      this->late_head_->prev (list_tail);
      if (list_tail)
        list_tail->next (this->late_head_);
      else
        list_head = this->late_head_;

      list_tail = this->late_tail_;

      this->late_tail_->next (0);
      this->late_head_ = 0;
      this->late_tail_ = 0;
    }

  if (ACE_BIT_ENABLED (status_flags,
      (u_int) ACE_Dynamic_Message_Strategy::BEYOND_LATE)
      && this->beyond_late_head_
      && this->beyond_late_tail_)
    {
      // Patch up pointers for the new tail of the queue
      if (this->beyond_late_tail_->next ())
        {
          this->head_ = this->beyond_late_tail_->next ();
          this->beyond_late_tail_->next ()->prev (0);
        }
      else
        {
          // the list has become empty
          this->head_ = 0;
          this->tail_ = 0;
        }

      // Put beyond late messages at the end of the list being
      // returned.
      if (list_tail)
        {
          this->beyond_late_head_->prev (list_tail);
          list_tail->next (this->beyond_late_head_);
        }
      else
        list_head = this->beyond_late_head_;

      list_tail = this->beyond_late_tail_;

      this->beyond_late_tail_->next (0);
      this->beyond_late_head_ = 0;
      this->beyond_late_tail_ = 0;
    }

  // Decrement message and size counts for removed messages.
  ACE_Message_Block *temp1;

  for (temp1 = list_head;
       temp1 != 0;
       temp1 = temp1->next ())
    {
      --this->cur_count_;

      size_t mb_bytes = 0;
      size_t mb_length = 0;
      temp1->total_size_and_length (mb_bytes,
                                    mb_length);
      // Subtract off all of the bytes associated with this message.
      this->cur_bytes_ -= mb_bytes;
      this->cur_length_ -= mb_length;
    }

  return result;
}

// Detach all messages with status given in the passed flags from the
// queue and return them by setting passed head and tail pointers to
// the linked list they comprise.  This method is intended primarily
// as a means of periodically harvesting messages that have missed
// their deadlines, but is available in its most general form.  All
// messages are returned in priority order, from head to tail, as of
// the time this method was called.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dequeue_head (ACE_Message_Block *&first_item,
                                                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dequeue_head");

  ACE_GUARD_RETURN (ACE_SYNCH_MUTEX_T, ace_mon, this->lock_, -1);

  if (this->state_ == ACE_Message_Queue_Base::DEACTIVATED)
    {
      errno = ESHUTDOWN;
      return -1;
    }

  int result;

  // get the current time
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();

  // refresh priority status boundaries in the queue
  result = this->refresh_queue (current_time);
  if (result < 0)
    return result;

  // *now* it's appropriate to wait for an enqueued item
  result = this->wait_not_empty_cond (ace_mon, timeout);
  if (result == -1)
    return result;

  // call the internal dequeue method, which selects an item from the
  // highest priority status portion of the queue that has messages
  // enqueued.
  result = this->dequeue_head_i (first_item);

  return result;
}

// Dequeue and return the <ACE_Message_Block *> at the (logical) head
// of the queue.

template <ACE_SYNCH_DECL> void
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Message_Queue<ACE_SYNCH_USE> (base class): \n")));
  this->ACE_Message_Queue<ACE_SYNCH_USE>::dump ();

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("pending_head_ = %u\n")
              ACE_TEXT ("pending_tail_ = %u\n")
              ACE_TEXT ("late_head_ = %u\n")
              ACE_TEXT ("late_tail_ = %u\n")
              ACE_TEXT ("beyond_late_head_ = %u\n")
              ACE_TEXT ("beyond_late_tail_ = %u\n"),
              this->pending_head_,
              this->pending_tail_,
              this->late_head_,
              this->late_tail_,
              this->beyond_late_head_,
              this->beyond_late_tail_));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("message_strategy_ : \n")));
  message_strategy_.dump ();

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}
  // dump the state of the queue

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_i (ACE_Message_Block *new_item)
{
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_i");

  if (new_item == 0)
    {
      return -1;
    }

  int result = 0;

  // Get the current time.
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();

  // Refresh priority status boundaries in the queue.

  result = this->refresh_queue (current_time);
  
  if (result < 0)
    {
      return result;
    }

  // Where we enqueue depends on the message's priority status.
  switch (message_strategy_.priority_status (*new_item,
                                             current_time))
    {
    case ACE_Dynamic_Message_Strategy::PENDING:
      if (this->pending_tail_ == 0)
        {
          // Check for simple case of an empty pending queue, where
          // all we need to do is insert <new_item> into the tail of
          // the queue.
          pending_head_ = new_item;
          pending_tail_ = pending_head_;
          return this->enqueue_tail_i (new_item);
        }
      else
        {
          // Enqueue the new message in priority order in the pending
          // sublist
          result = sublist_enqueue_i (new_item,
                                      current_time,
                                      this->pending_head_,
                                      this->pending_tail_,
                                      ACE_Dynamic_Message_Strategy::PENDING);
        }
      break;

    case ACE_Dynamic_Message_Strategy::LATE:
      if (this->late_tail_ == 0)
        {
          late_head_ = new_item;
          late_tail_ = late_head_;

          if (this->pending_head_ == 0)
            // Check for simple case of an empty pending queue,
            // where all we need to do is insert <new_item> into the
            // tail of the queue.
            return this->enqueue_tail_i (new_item);
          else if (this->beyond_late_tail_ == 0)
            // Check for simple case of an empty beyond late queue, where all
            // we need to do is insert <new_item> into the head of the queue.
            return this->enqueue_head_i (new_item);
          else
            {
              // Otherwise, we can just splice the new message in
              // between the pending and beyond late portions of the
              // queue.
              this->beyond_late_tail_->next (new_item);
              new_item->prev (this->beyond_late_tail_);
              this->pending_head_->prev (new_item);
              new_item->next (this->pending_head_);
            }
        }
      else
        {
          // Enqueue the new message in priority order in the late
          // sublist
          result = sublist_enqueue_i (new_item,
                                      current_time,
                                      this->late_head_,
                                      this->late_tail_,
                                      ACE_Dynamic_Message_Strategy::LATE);
        }
      break;

    case ACE_Dynamic_Message_Strategy::BEYOND_LATE:
      if (this->beyond_late_tail_ == 0)
        {
          // Check for simple case of an empty beyond late queue,
          // where all we need to do is insert <new_item> into the
          // head of the queue.
          beyond_late_head_ = new_item;
          beyond_late_tail_ = beyond_late_head_;
          return this->enqueue_head_i (new_item);
        }
      else
        {
          // all beyond late messages have the same (zero) priority,
          // so just put the new one at the end of the beyond late
          // messages
          if (this->beyond_late_tail_->next ())
            {
              this->beyond_late_tail_->next ()->prev (new_item);
            }
          else
            {
              this->tail_ = new_item;
            }

          new_item->next (this->beyond_late_tail_->next ());
          this->beyond_late_tail_->next (new_item);
          new_item->prev (this->beyond_late_tail_);
          this->beyond_late_tail_ = new_item;
        }

      break;

      // should never get here, but just in case...
    default:
      result = -1;
      break;
    }

  if (result < 0)
    {
      return result;
    }

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  new_item->total_size_and_length (mb_bytes,
                                   mb_length);
  this->cur_bytes_ += mb_bytes;
  this->cur_length_ += mb_length;
  ++this->cur_count_;

  if (this->signal_dequeue_waiters () == -1)
    {
      return -1;
    }
  else
    {
      return ACE_Utils::truncate_cast<int> (this->cur_count_);
    }
}

// Enqueue an <ACE_Message_Block *> in accordance with its priority.
// priority may be *dynamic* or *static* or a combination or *both* It
// calls the priority evaluation function passed into the Dynamic
// Message Queue constructor to update the priorities of all enqueued
// messages.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::sublist_enqueue_i (ACE_Message_Block *new_item,
                                                             const ACE_Time_Value &current_time,
                                                             ACE_Message_Block *&sublist_head,
                                                             ACE_Message_Block *&sublist_tail,
                                                             ACE_Dynamic_Message_Strategy::Priority_Status status)
{
  int result = 0;
  ACE_Message_Block *current_item = 0;

  // Find message after which to enqueue new item, based on message
  // priority and priority status.
  for (current_item = sublist_tail;
       current_item;
       current_item = current_item->prev ())
    {
      if (message_strategy_.priority_status (*current_item, current_time) == status)
        {
          if (current_item->msg_priority () >= new_item->msg_priority ())
            break;
        }
      else
        {
          sublist_head = new_item;
          break;
        }
    }

  if (current_item == 0)
    {
      // If the new message has highest priority of any, put it at the
      // head of the list (and sublist).
      new_item->prev (0);
      new_item->next (this->head_);
      if (this->head_ != 0)
        this->head_->prev (new_item);
      else
        {
          this->tail_ = new_item;
          sublist_tail = new_item;
        }
      this->head_ = new_item;
      sublist_head = new_item;
    }
  else
    {
      // insert the new item into the list
      new_item->next (current_item->next ());
      new_item->prev (current_item);

      if (current_item->next ())
        current_item->next ()->prev (new_item);
      else
        this->tail_ = new_item;

      current_item->next (new_item);

      // If the new item has lowest priority of any in the sublist,
      // move the tail pointer of the sublist back to the new item
      if (current_item == sublist_tail)
        sublist_tail = new_item;
    }

  return result;
}

// Enqueue a message in priority order within a given priority status
// sublist.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dequeue_head_i (ACE_Message_Block *&first_item)
{
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::dequeue_head_i");

  int result = 0;
  int last_in_subqueue = 0;

  // first, try to dequeue from the head of the pending list
  if (this->pending_head_)
    {
      first_item = this->pending_head_;

      if (0 == this->pending_head_->prev ())
        this->head_ = this->pending_head_->next ();
      else
        this->pending_head_->prev ()->next (this->pending_head_->next ());

      if (0 == this->pending_head_->next ())
        {
          this->tail_ = this->pending_head_->prev ();
          this->pending_head_ = 0;
          this->pending_tail_ = 0;
        }
      else
        {
          this->pending_head_->next ()->prev (this->pending_head_->prev ());
          this->pending_head_ = this->pending_head_->next ();
        }

      first_item->prev (0);
      first_item->next (0);
    }

  // Second, try to dequeue from the head of the late list
  else if (this->late_head_)
    {
      last_in_subqueue = this->late_head_ == this->late_tail_ ? 1 : 0;

      first_item = this->late_head_;

      if (0 == this->late_head_->prev ())
        this->head_ = this->late_head_->next ();
      else
        this->late_head_->prev ()->next (this->late_head_->next ());

      if (0 == this->late_head_->next ())
        this->tail_ = this->late_head_->prev ();
      else
        {
          this->late_head_->next ()->prev (this->late_head_->prev ());
          this->late_head_ = this->late_head_->next ();
        }

      if (last_in_subqueue)
        {
          this->late_head_ = 0;
          this->late_tail_ = 0;
        }

      first_item->prev (0);
      first_item->next (0);
    }
  // finally, try to dequeue from the head of the beyond late list
  else if (this->beyond_late_head_)
    {
      last_in_subqueue =
        (this->beyond_late_head_ == this->beyond_late_tail_) ? 1 : 0;

      first_item = this->beyond_late_head_;
      this->head_ = this->beyond_late_head_->next ();

      if (0 == this->beyond_late_head_->next ())
        {
          this->tail_ = this->beyond_late_head_->prev ();
        }
      else
        {
          this->beyond_late_head_->next ()->prev (this->beyond_late_head_->prev ());
          this->beyond_late_head_ = this->beyond_late_head_->next ();
        }

      if (last_in_subqueue)
        {
          this->beyond_late_head_ = 0;
          this->beyond_late_tail_ = 0;
        }

      first_item->prev (0);
      first_item->next (0);
    }
  else
    {
      // nothing to dequeue: set the pointer to zero and return an error code
      first_item = 0;
      result = -1;
    }

  if (result < 0)
    {
      return result;
    }

  size_t mb_bytes = 0;
  size_t mb_length = 0;
  first_item->total_size_and_length (mb_bytes,
                                     mb_length);
  // Subtract off all of the bytes associated with this message.
  this->cur_bytes_ -= mb_bytes;
  this->cur_length_ -= mb_length;
  --this->cur_count_;

  // Only signal enqueueing threads if we've fallen below the low
  // water mark.
  if (this->cur_bytes_ <= this->low_water_mark_
      && this->signal_enqueue_waiters () == -1)
    {
      return -1;
    }
  else
    {
      return ACE_Utils::truncate_cast<int> (this->cur_count_);
    }
}

// Dequeue and return the <ACE_Message_Block *> at the head of the
// logical queue.  Attempts first to dequeue from the pending portion
// of the queue, or if that is empty from the late portion, or if that
// is empty from the beyond late portion, or if that is empty just
// sets the passed pointer to zero and returns -1.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::refresh_queue (const ACE_Time_Value &current_time)
{
  int result;

  result = refresh_pending_queue (current_time);

  if (result != -1)
    result = refresh_late_queue (current_time);

  return result;
}

// Refresh the queue using the strategy specific priority status
// function.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::refresh_pending_queue (const ACE_Time_Value &current_time)
{
  ACE_Dynamic_Message_Strategy::Priority_Status current_status;

  // refresh priority status boundaries in the queue
  if (this->pending_head_)
    {
      current_status = message_strategy_.priority_status (*this->pending_head_,
                                                          current_time);
      switch (current_status)
        {
        case ACE_Dynamic_Message_Strategy::BEYOND_LATE:
          // Make sure the head of the beyond late queue is set (there
          // may not have been any beyond late messages previously)
          this->beyond_late_head_ = this->head_;

          // Zero out the late queue pointers, and set them only if
          // there turn out to be late messages in the pending sublist
          this->late_head_ = 0;
          this->late_tail_ = 0;

          // Advance through the beyond late messages in the pending queue
          do
            {
              this->pending_head_ = this->pending_head_->next ();

              if (this->pending_head_)
                current_status = message_strategy_.priority_status (*this->pending_head_,
                                                                    current_time);
              else
                break;  // do while

            }
          while (current_status == ACE_Dynamic_Message_Strategy::BEYOND_LATE);

          if (this->pending_head_)
            {
              // point tail of beyond late sublist to previous item
              this->beyond_late_tail_ = this->pending_head_->prev ();

              if (current_status == ACE_Dynamic_Message_Strategy::PENDING)
                // there are no late messages left in the queue
                break; // switch
              else if (current_status != ACE_Dynamic_Message_Strategy::LATE)
                {
                  // if we got here, something is *seriously* wrong with the queue
                  ACE_ERROR_RETURN ((LM_ERROR,
                                     ACE_TEXT ("Unexpected message priority status [%d] (expected LATE)"),
                                     (int) current_status),
                                    -1);
                }
              /* FALLTHRU */
            }
          else
            {
              // There are no pending or late messages left in the
              // queue.
              this->beyond_late_tail_ = this->tail_;
              this->pending_head_ = 0;
              this->pending_tail_ = 0;
              break; // switch
            }

        case ACE_Dynamic_Message_Strategy::LATE:
          // Make sure the head of the late queue is set (there may
          // not have been any late messages previously, or they may
          // have all become beyond late).
          if (this->late_head_ == 0)
            this->late_head_ = this->pending_head_;

          // advance through the beyond late messages in the pending queue
          do
            {
              this->pending_head_ = this->pending_head_->next ();

              if (this->pending_head_)
                current_status = message_strategy_.priority_status (*this->pending_head_,
                                                                    current_time);
              else
                break;  // do while

            }
          while (current_status == ACE_Dynamic_Message_Strategy::LATE);

          if (this->pending_head_)
            {
              if (current_status != ACE_Dynamic_Message_Strategy::PENDING)
                // if we got here, something is *seriously* wrong with the queue
                ACE_ERROR_RETURN((LM_ERROR,
                                  ACE_TEXT ("Unexpected message priority status [%d] (expected PENDING)"),
                                  (int) current_status),
                                 -1);

              // Point tail of late sublist to previous item
              this->late_tail_ = this->pending_head_->prev ();
            }
          else
            {
              // there are no pending messages left in the queue
              this->late_tail_ = this->tail_;
              this->pending_head_ = 0;
              this->pending_tail_ = 0;
            }

          break; // switch
        case ACE_Dynamic_Message_Strategy::PENDING:
          // do nothing - the pending queue is unchanged
          break; // switch
        default:
          // if we got here, something is *seriously* wrong with the queue
          ACE_ERROR_RETURN((LM_ERROR,
                            ACE_TEXT ("Unknown message priority status [%d]"),
                            (int) current_status),
                           -1);
        }
    }
  return 0;
}

// Refresh the pending queue using the strategy specific priority
// status function.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::refresh_late_queue (const ACE_Time_Value &current_time)
{
  ACE_Dynamic_Message_Strategy::Priority_Status current_status;

  if (this->late_head_)
    {
      current_status = message_strategy_.priority_status (*this->late_head_,
                                                          current_time);
      switch (current_status)
        {
        case ACE_Dynamic_Message_Strategy::BEYOND_LATE:

          // make sure the head of the beyond late queue is set
          // (there may not have been any beyond late messages previously)
          this->beyond_late_head_ = this->head_;

          // advance through the beyond late messages in the late queue
          do
            {
              this->late_head_ = this->late_head_->next ();

              if (this->late_head_)
                current_status = message_strategy_.priority_status (*this->late_head_,
                                                                    current_time);
              else
                break;  // do while

            }
          while (current_status == ACE_Dynamic_Message_Strategy::BEYOND_LATE);

          if (this->late_head_)
            {
              // point tail of beyond late sublist to previous item
              this->beyond_late_tail_ = this->late_head_->prev ();

              if (current_status == ACE_Dynamic_Message_Strategy::PENDING)
                {
                  // there are no late messages left in the queue
                  this->late_head_ = 0;
                  this->late_tail_ = 0;
                }
              else if (current_status != ACE_Dynamic_Message_Strategy::LATE)
                // if we got here, something is *seriously* wrong with the queue
                ACE_ERROR_RETURN ((LM_ERROR,
                                   ACE_TEXT ("Unexpected message priority status [%d] (expected LATE)"),
                                   (int) current_status),
                                  -1);
            }
          else
            {
              // there are no late messages left in the queue
              this->beyond_late_tail_ = this->tail_;
              this->late_head_ = 0;
              this->late_tail_ = 0;
            }

          break;  // switch

        case ACE_Dynamic_Message_Strategy::LATE:
          // do nothing - the late queue is unchanged
          break; // switch

        case ACE_Dynamic_Message_Strategy::PENDING:
          // if we got here, something is *seriously* wrong with the queue
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("Unexpected message priority status ")
                             ACE_TEXT ("[%d] (expected LATE or BEYOND_LATE)"),
                             (int) current_status),
                            -1);
        default:
          // if we got here, something is *seriously* wrong with the queue
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("Unknown message priority status [%d]"),
                             (int) current_status),
                            -1);
        }
    }

  return 0;
}

// Refresh the late queue using the strategy specific priority status
// function.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::peek_dequeue_head (ACE_Message_Block *&first_item,
                                                             ACE_Time_Value *timeout)
{
  return ACE_Message_Queue<ACE_SYNCH_USE>::peek_dequeue_head (first_item,
                                                              timeout);
}

// Private method to hide public base class method: just calls base
// class method.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_tail (ACE_Message_Block *new_item,
                                                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_tail");
  return this->enqueue_prio (new_item, timeout);
}

// Just call priority enqueue method: tail enqueue semantics for
// dynamic message queues are unstable: the message may or may not be
// where it was placed after the queue is refreshed prior to the next
// enqueue or dequeue operation.

template <ACE_SYNCH_DECL> int
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_head (ACE_Message_Block *new_item,
                                                        ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Dynamic_Message_Queue<ACE_SYNCH_USE>::enqueue_head");
  return this->enqueue_prio (new_item, timeout);
}

// Just call priority enqueue method: head enqueue semantics for
// dynamic message queues are unstable: the message may or may not be
// where it was placed after the queue is refreshed prior to the next
// enqueue or dequeue operation.

template <ACE_SYNCH_DECL>
ACE_Message_Queue<ACE_SYNCH_USE> *
ACE_Message_Queue_Factory<ACE_SYNCH_USE>::create_static_message_queue (size_t hwm,
                                                                       size_t lwm,
                                                                       ACE_Notification_Strategy *ns)
{
  ACE_Message_Queue<ACE_SYNCH_USE> *tmp = 0;

  ACE_NEW_RETURN (tmp,
                  ACE_Message_Queue<ACE_SYNCH_USE> (hwm, lwm, ns),
                  0);
  return tmp;
}

// Factory method for a statically prioritized ACE_Message_Queue.

template <ACE_SYNCH_DECL>
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *
ACE_Message_Queue_Factory<ACE_SYNCH_USE>::create_deadline_message_queue (size_t hwm,
                                                                         size_t lwm,
                                                                         ACE_Notification_Strategy *ns,
                                                                         u_long static_bit_field_mask,
                                                                         u_long static_bit_field_shift,
                                                                         u_long dynamic_priority_max,
                                                                         u_long dynamic_priority_offset)
{
  ACE_Deadline_Message_Strategy *adms = 0;

  ACE_NEW_RETURN (adms,
                  ACE_Deadline_Message_Strategy (static_bit_field_mask,
                                                 static_bit_field_shift,
                                                 dynamic_priority_max,
                                                 dynamic_priority_offset),
                  0);

  ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *tmp = 0;
  ACE_NEW_RETURN (tmp,
                  ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> (*adms, hwm, lwm, ns),
                  0);
  return tmp;
}

// Factory method for a dynamically prioritized (by time to deadline)
// ACE_Dynamic_Message_Queue.

template <ACE_SYNCH_DECL>
ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *
ACE_Message_Queue_Factory<ACE_SYNCH_USE>::create_laxity_message_queue (size_t hwm,
                                                                       size_t lwm,
                                                                       ACE_Notification_Strategy *ns,
                                                                       u_long static_bit_field_mask,
                                                                       u_long static_bit_field_shift,
                                                                       u_long dynamic_priority_max,
                                                                       u_long dynamic_priority_offset)
{
  ACE_Laxity_Message_Strategy *alms = 0;

  ACE_NEW_RETURN (alms,
                  ACE_Laxity_Message_Strategy (static_bit_field_mask,
                                               static_bit_field_shift,
                                               dynamic_priority_max,
                                               dynamic_priority_offset),
                  0);

  ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *tmp = 0;
  ACE_NEW_RETURN (tmp,
                  ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> (*alms, hwm, lwm, ns),
                  0);
  return tmp;
}

// Factory method for a dynamically prioritized (by laxity)
// <ACE_Dynamic_Message_Queue>.

#if defined (ACE_VXWORKS)

template <ACE_SYNCH_DECL>
ACE_Message_Queue_Vx *
ACE_Message_Queue_Factory<ACE_SYNCH_USE>::create_Vx_message_queue (size_t max_messages,
                                                                   size_t max_message_length,
                                                                   ACE_Notification_Strategy *ns)
{
  ACE_Message_Queue_Vx *tmp = 0;

  ACE_NEW_RETURN (tmp,
                  ACE_Message_Queue_Vx (max_messages, max_message_length, ns),
                  0);
  return tmp;
}
  // factory method for a wrapped VxWorks message queue

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)

template <ACE_SYNCH_DECL>
ACE_Message_Queue_NT *
ACE_Message_Queue_Factory<ACE_SYNCH_USE>::create_NT_message_queue (size_t max_threads)
{
  ACE_Message_Queue_NT *tmp = 0;

  ACE_NEW_RETURN (tmp,
                  ACE_Message_Queue_NT (max_threads);
                  0);
  return tmp;
}

#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */
#endif /* defined (ACE_VXWORKS) */

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* !ACE_MESSAGE_QUEUE_T_CPP */
