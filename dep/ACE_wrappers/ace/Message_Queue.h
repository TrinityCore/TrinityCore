// -*- C++ -*-

//=============================================================================
/**
 *  @file    Message_Queue.h
 *
 *  $Id: Message_Queue.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MESSAGE_QUEUE_H
#define ACE_MESSAGE_QUEUE_H
#include /**/ "ace/pre.h"

#include "ace/Message_Block.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/IO_Cntl_Msg.h"
#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
# include "ace/Synch_Traits.h"   /* Needed in ACE_Message_Queue_NT */
# include "ace/Thread_Mutex.h"   /* Needed in ACE_Message_Queue_NT */
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls.
class ACE_Notification_Strategy;
template <ACE_SYNCH_DECL> class ACE_Message_Queue_Iterator;
template <ACE_SYNCH_DECL> class ACE_Message_Queue_Reverse_Iterator;

/**
 * @class ACE_Message_Queue_Base
 *
 * @brief Base class for ACE_Message_Queue, which is the central
 * queueing facility for messages in the ACE framework.
 *
 * For all the ACE_Time_Value pointer parameters the caller will
 * block until action is possible if @a timeout == 0.  Otherwise, it
 * will wait until the absolute time specified in *@a timeout
 * elapses.
 *
 * A queue is always in one of three states:
 * . ACTIVATED
 * . DEACTIVATED
 * . PULSED
 */
class ACE_Export ACE_Message_Queue_Base
{
public:
  enum
  {
    // Default high and low watermarks.

    /// Default high watermark (16 K).
    DEFAULT_HWM = 16 * 1024,
    /// Default low watermark (same as high water mark).
    DEFAULT_LWM = 16 * 1024,

    // Queue states.  Before PULSED state was added, the activate()
    // and deactivate() methods returned WAS_INACTIVE or WAS_ACTIVE
    // to indicate the previous condition.  Now those methods
    // return the state the queue was previously in.  WAS_ACTIVE
    // and WAS_INACTIVE are defined to match previous semantics for
    // applications that don't use the PULSED state.

    /// @deprecated Use ACTIVATED instead.
    WAS_ACTIVE = 1,
    /// Message queue is active and processing normally
    ACTIVATED = 1,

    /// @deprecated Use DEACTIVATED instead.
    WAS_INACTIVE = 2,
    /// Queue is deactivated; no enqueue or dequeue operations allowed.
    DEACTIVATED = 2,

    /// Message queue was pulsed; enqueue and dequeue may proceed normally.
    PULSED = 3

  };

  ACE_Message_Queue_Base (void);

  /// Close down the message queue and release all resources.
  virtual int close (void) = 0;

  /// Close down the message queue and release all resources.
  virtual ~ACE_Message_Queue_Base (void);

  // = Enqueue and dequeue methods.

  /**
   * Retrieve the first ACE_Message_Block without removing it.  Note
   * that @a timeout uses <{absolute}> time rather than <{relative}>
   * time.  If the @a timeout elapses without receiving a message -1 is
   * returned and @c errno is set to @c EWOULDBLOCK.  If the queue is
   * deactivated -1 is returned and @c errno is set to <ESHUTDOWN>.
   * Otherwise, returns -1 on failure, else the number of items still
   * on the queue.
   */
  virtual int peek_dequeue_head (ACE_Message_Block *&first_item,
                                 ACE_Time_Value *timeout = 0) = 0;

  /**
   * Enqueue a <ACE_Message_Block *> into the tail of the queue.
   * Returns number of items in queue if the call succeeds or -1
   * otherwise.  These calls return -1 when queue is closed,
   * deactivated (in which case @c errno == <ESHUTDOWN>), when a signal
   * occurs (in which case @c errno == <EINTR>, or if the time
   * specified in timeout elapses (in which case @c errno ==
   * @c EWOULDBLOCK).
   */
  virtual int enqueue_tail (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0) = 0;
  virtual int enqueue (ACE_Message_Block *new_item,
                       ACE_Time_Value *timeout = 0) = 0;

  /**
   * Dequeue and return the <ACE_Message_Block *> at the head of the
   * queue.  Returns number of items in queue if the call succeeds or
   * -1 otherwise.  These calls return -1 when queue is closed,
   * deactivated (in which case @c errno == <ESHUTDOWN>), when a signal
   * occurs (in which case @c errno == <EINTR>, or if the time
   * specified in timeout elapses (in which case @c errno ==
   * @c EWOULDBLOCK).
   */
  virtual int dequeue_head (ACE_Message_Block *&first_item,
                            ACE_Time_Value *timeout = 0) = 0;
  virtual int dequeue (ACE_Message_Block *&first_item,
                       ACE_Time_Value *timeout = 0) = 0;

  // = Check if queue is full/empty.
  /// True if queue is full, else false.
  virtual bool is_full (void) = 0;

  /// True if queue is empty, else false.
  virtual bool is_empty (void) = 0;

  // = Queue statistic methods.

  /// Number of total bytes on the queue, i.e., sum of the message
  /// block sizes.
  virtual size_t message_bytes (void) = 0;

  /// Number of total length on the queue, i.e., sum of the message
  /// block lengths.
  virtual size_t message_length (void) = 0;

  /// Number of total messages on the queue.
  virtual size_t message_count (void) = 0;

  /// New value of the number of total bytes on the queue, i.e.,
  /// sum of the message block sizes.
  virtual void message_bytes (size_t new_size) = 0;

  /// New value of the number of total length on the queue, i.e.,
  /// sum of the message block lengths.
  virtual void message_length (size_t new_length) = 0;

  // = Activation control methods.

  /**
   * Deactivate the queue and wake up all threads waiting on the queue
   * so they can continue.  No messages are removed from the queue,
   * however.  Any other operations called until the queue is
   * activated again will immediately return -1 with @c errno
   * ESHUTDOWN.
   *
   * @retval  The queue's state before this call.
   */
  virtual int deactivate (void) = 0;

  /**
   * Reactivate the queue so that threads can enqueue and dequeue
   * messages again.
   *
   * @retval  The queue's state before this call.
   */
  virtual int activate (void) = 0;

  /**
   * Pulse the queue to wake up any waiting threads.  Changes the
   * queue state to PULSED; future enqueue/dequeue operations proceed
   * as in ACTIVATED state.
   *
   * @retval  The queue's state before this call.
   */
  virtual int pulse (void) = 0;

  /// Returns the current state of the queue.
  virtual int state (void);

  /// Returns 1 if the state of the queue is DEACTIVATED,
  /// and 0 if the queue's state is ACTIVATED or PULSED.
  virtual int deactivated (void) = 0;

  /// Get the notification strategy for the <Message_Queue>
  virtual ACE_Notification_Strategy *notification_strategy (void) = 0;

  /// Set the notification strategy for the <Message_Queue>
  virtual void notification_strategy (ACE_Notification_Strategy *s) = 0;

  // = Notification hook.

  /// Dump the state of an object.
  virtual void dump (void) const = 0;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:
  // = Disallow copying and assignment.
  ACE_Message_Queue_Base (const ACE_Message_Queue_Base &);
  void operator= (const ACE_Message_Queue_Base &);

protected:
  /// Indicates the state of the queue, which can be
  /// <ACTIVATED>, <DEACTIVATED>, or <PULSED>.
  int state_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

// Include the templates here.
#include "ace/Message_Queue_T.h"

#if defined (__ACE_INLINE__)
#include "ace/Message_Queue.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_MESSAGE_QUEUE_H */
