// -*- C++ -*-

//=============================================================================
/**
 *  @file    Message_Queue_Vx.h
 *
 *  $Id: Message_Queue_Vx.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MESSAGE_QUEUE_VX_H
#define ACE_MESSAGE_QUEUE_VX_H
#include /**/ "ace/pre.h"

#include "ace/Message_Block.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_VXWORKS)

// Include the templates here.
#include "ace/Message_Queue_T.h"

# include /**/ <msgQLib.h>
# include "ace/Null_Mutex.h"
# include "ace/Null_Condition.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Message_Queue_Vx
 *
 * @brief Wrapper for VxWorks message queues.
 *
 * Specialization of ACE_Message_Queue to simply wrap VxWorks
 * MsgQ.  It does not use any synchronization, because it relies
 * on the native MsgQ implementation to take care of that.  The
 * only system calls that it uses are VxWorks msgQLib calls, so
 * it is suitable for use in interrupt service routines.
 * @note *Many* ACE_Message_Queue features are not supported with
 * this specialization, including:
 * * The two size arguments to the constructor and <open> are
 * interpreted differently.  The first is interpreted as the
 * maximum number of bytes in a message.  The second is
 * interpreted as the maximum number of messages that can be
 * queued.
 * * <dequeue_head> *requires* that the ACE_Message_Block
 * pointer argument point to an ACE_Message_Block that was
 * allocated by the caller.  It must be big enough to support
 * the received message, without using continuation. The
 * pointer argument is not modified.
 * * Message priority.  MSG_Q_FIFO is hard-coded.
 * * enqueue method timeouts.
 * * <peek_dequeue_head>.
 * * <ACE_Message_Queue_Iterators>.
 * * The ability to change low and high water marks after creation.
 * * <Message_Block> chains.  The continuation field of ACE_Message_Block
 * *   is ignored; only the first block of a fragment chain is
 * *   recognized.
 */
class ACE_Message_Queue_Vx : public ACE_Message_Queue<ACE_NULL_SYNCH>
{
public:
  // = Initialization and termination methods.
  ACE_Message_Queue_Vx (size_t max_messages,
                        size_t max_message_length,
                        ACE_Notification_Strategy * = 0);

  // Create a message queue with all the defaults.
  /// Create a message queue with all the defaults.
  virtual int open (size_t max_messages,
                    size_t max_message_length,
                    ACE_Notification_Strategy * = 0);

  /// Close down the message queue and release all resources.
  virtual int close (void);

  /// Close down the message queue and release all resources.
  virtual ~ACE_Message_Queue_Vx (void);

  // = Queue statistic methods.
  /**
   * Number of total bytes on the queue, i.e., sum of the message
   * block sizes.
   */
  virtual size_t message_bytes (void);

  /**
   * Number of total length on the queue, i.e., sum of the message
   * block lengths.
   */
  virtual size_t message_length (void);

  /**
   * Number of total messages on the queue.
   */
  virtual size_t message_count (void);

  // = Manual changes to these stats (used when queued message blocks
  // change size or lengths).
  /**
   * New value of the number of total bytes on the queue, i.e., sum of
   * the message block sizes.
   */
  virtual void message_bytes (size_t new_size);
  /**
   * New value of the number of total length on the queue, i.e., sum
   * of the message block lengths.
   */
  virtual void message_length (size_t new_length);

  // = Flow control routines

  /// Get high watermark.
  virtual size_t high_water_mark (void);

  /// Set high watermark.
  virtual void high_water_mark (size_t hwm);

  /// Get low watermark.
  virtual size_t low_water_mark (void);

  /// Set low watermark.
  virtual void low_water_mark (size_t lwm);

  // = Activation control methods.

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

protected:
  /// Enqueue an <ACE_Message_Block *> in accordance with its priority.
  virtual int enqueue_i (ACE_Message_Block *new_item);

  /// Enqueue an <ACE_Message_Block *> in accordance with its deadline time.
  virtual int enqueue_deadline_i (ACE_Message_Block *new_item);

  /// Enqueue an <ACE_Message_Block *> at the end of the queue.
  virtual int enqueue_tail_i (ACE_Message_Block *new_item);

  /// Enqueue an <ACE_Message_Block *> at the head of the queue.
  virtual int enqueue_head_i (ACE_Message_Block *new_item);

  /// Dequeue and return the <ACE_Message_Block *> at the head of the
  /// queue.
  virtual int dequeue_head_i (ACE_Message_Block *&first_item);

  /// Dequeue and return the <ACE_Message_Block *> with the lowest
  /// priority.
  virtual int dequeue_prio_i (ACE_Message_Block *&dequeued);

  /// Dequeue and return the <ACE_Message_Block *> at the tail of the
  /// queue.
  virtual int dequeue_tail_i (ACE_Message_Block *&dequeued);

  /// Dequeue and return the <ACE_Message_Block *> that has the lowest
  /// deadline time.
  virtual int dequeue_deadline_i (ACE_Message_Block *&dequeued);

  // = Check the boundary conditions (assumes locks are held).
  /// True if queue is full, else false.
  virtual bool is_full_i (void);

  /// True if queue is empty, else false.
  virtual bool is_empty_i (void);

  // = Implementation of public <activate>/<deactivate> methods above.

  // These methods assume locks are held.

  // = Helper methods to factor out common #ifdef code.
  /// Wait for the queue to become non-full.
  virtual int wait_not_full_cond (ACE_Guard<ACE_Null_Mutex> &mon,
                                  ACE_Time_Value *tv);

  /// Wait for the queue to become non-empty.
  virtual int wait_not_empty_cond (ACE_Guard<ACE_Null_Mutex> &mon,
                                   ACE_Time_Value *tv);

  /// Inform any threads waiting to enqueue that they can procede.
  virtual int signal_enqueue_waiters (void);

  /// Inform any threads waiting to dequeue that they can procede.
  virtual int signal_dequeue_waiters (void);

  /// Access the underlying msgQ.
  MSG_Q_ID msgq (void);

private:

  // Disallow copying and assignment.
  ACE_Message_Queue_Vx (const ACE_Message_Queue_Vx &);
  void operator= (const ACE_Message_Queue_Vx &);

  ACE_UNIMPLEMENTED_FUNC (virtual int peek_dequeue_head
                            (ACE_Message_Block *&first_item,
                             ACE_Time_Value *tv = 0))

private:
  /// Maximum number of messages that can be queued.
  int max_messages_;

  /// Maximum message size, in bytes.
  int max_message_length_;

  /// Native message queue options.
  int options_;

};

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_VXWORKS */

#if defined (__ACE_INLINE__)
#include "ace/Message_Queue_Vx.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_MESSAGE_QUEUE_VX_H */
