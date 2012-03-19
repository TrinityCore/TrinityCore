// -*- C++ -*-

//=============================================================================
/**
 *  @file    Message_Queue_NT.h
 *
 *  $Id: Message_Queue_NT.h 82723 2008-09-16 09:35:44Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_MESSAGE_QUEUE_NT_H
#define ACE_MESSAGE_QUEUE_NT_H
#include /**/ "ace/pre.h"

#include "ace/Message_Queue.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
# include "ace/Synch_Traits.h"   /* Needed in ACE_Message_Queue_NT */
# include "ace/Thread_Mutex.h"   /* Needed in ACE_Message_Queue_NT */
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
/**
 * @class ACE_Message_Queue_NT
 *
 * @brief Message Queue implementation using IO completion port on NT.
 *
 * Implementation of a strip-downed ACE_Message_Queue using NT's
 * IO completion port mechanism.
 * @note *Many* ACE_Message_Queue features are not supported with
 * this implementation, including:
 * * <open> method have different signatures.
 * * <dequeue_head> *requires* that the ACE_Message_Block
 * pointer argument point to an ACE_Message_Block that was
 * allocated by the caller.
 * * <peek_dequeue_head>.
 * * <ACE_Message_Queue_Iterators>.
 * * No flow control.
 */
class ACE_Export ACE_Message_Queue_NT : public ACE_Message_Queue_Base
{
public:
  // = Initialization and termination methods.
  ACE_Message_Queue_NT (DWORD max_threads = ACE_Message_Queue_Base::DEFAULT_HWM);

  /**
   * Initialize the Message Queue by creating a new NT I/O completion
   * port.  The first arguemnt specifies the number of threads
   * released by the MQ that are allowed to run concurrently.  Return
   * 0 when succeeds, -1 otherwise.
   */
  virtual int open (DWORD max_threads = ACE_Message_Queue_Base::DEFAULT_HWM);

  /// Close down the underlying I/O completion port.  You need to
  /// re-open the MQ after this function is executed.
  virtual int close (void);

  /// Close down the message queue and release all resources.
  virtual ~ACE_Message_Queue_NT (void);

  // = Enqueue and dequeue methods.

  /**
   * Enqueue an ACE_Message_Block * at the end of the queue.
   * Returns -1 on failure, else the number of items still on the
   * queue.
   */
  virtual int enqueue_tail (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);
  virtual int enqueue (ACE_Message_Block *new_item,
                       ACE_Time_Value *timeout = 0);

  /**
   * Dequeue and return the ACE_Message_Block * at the head of the
   * queue.  Returns -1 on failure, else the number of items still on
   * the queue.
   */
  virtual int dequeue_head (ACE_Message_Block *&first_item,
                            ACE_Time_Value *timeout = 0);
  virtual int dequeue (ACE_Message_Block *&first_item,
                       ACE_Time_Value *timeout = 0);

  // = Check if queue is full/empty.
  /**
   * Always return false.
   */

  virtual bool is_full (void);
  /**
   * True if queue is empty, else false.  Notice the return value is
   * only transient.
   */
  virtual bool is_empty (void);

  // = Queue statistic methods (transient.)
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

  /// Get the max concurrent thread number.
  virtual DWORD max_threads (void);

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
  virtual int deactivate (void);

  /**
   * Reactivate the queue so that threads can enqueue and dequeue
   * messages again.  Returns the state of the queue before the call.
   */
  virtual int activate (void);

  /**
   * Pulse the queue to wake up any waiting threads.  Changes the
   * queue state to PULSED; future enqueue/dequeue operations proceed
   * as in ACTIVATED state.
   *
   * @retval  The queue's state before this call.
   */
  virtual int pulse (void);

  /// Returns true if the state of the queue is <DEACTIVATED>,
  /// but false if the queue's is <ACTIVATED> or <PULSED>.
  virtual int deactivated (void);

  // = Not currently implemented...
  int peek_dequeue_head (ACE_Message_Block *&first_item,
                         ACE_Time_Value *timeout = 0);
  ACE_Notification_Strategy *notification_strategy (void);
  void notification_strategy (ACE_Notification_Strategy *s);

  // = Notification hook.

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Get the handle to the underlying completion port.
  virtual ACE_HANDLE completion_port (void);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  // Disallow copying and assignment.
  ACE_Message_Queue_NT (const ACE_Message_Queue_NT &);
  void operator= (const ACE_Message_Queue_NT &);

private:
  // = Internal states.

  /// Maximum threads that can be released (and run) concurrently.
  DWORD max_cthrs_;

  /// Current number of threads waiting to dequeue messages.
  DWORD cur_thrs_;

  /// Current number of bytes in queue.
  size_t cur_bytes_;

  /// Current length of messages in queue.
  size_t cur_length_;

  /// Current number of messages in the queue.
  size_t cur_count_;

  /**
   * Synchronizer.  This should really be an ACE_Recursive_Thread_Mutex
   * but since this class is only supported on NT, it's okay to use
   * ACE_Thread_Mutex here.
   */
  ACE_SYNCH_MUTEX lock_;

  /// Underlying NT IoCompletionPort.
  ACE_HANDLE completion_port_;

};
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Message_Queue_NT.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* ACE_MESSAGE_QUEUE_NT_H */
