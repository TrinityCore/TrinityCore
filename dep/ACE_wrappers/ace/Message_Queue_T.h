/* -*- C++ -*- */
//=============================================================================
/**
 *  @file    Message_Queue_T.h
 *
 *  $Id: Message_Queue_T.h 82289 2008-07-11 08:12:09Z hillj $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_MESSAGE_QUEUE_T_H
#define ACE_MESSAGE_QUEUE_T_H
#include /**/ "ace/pre.h"
#include "ace/Message_Queue.h"
#include "ace/Dynamic_Message_Strategy.h"
#include "ace/Synch_Traits.h"
#include "ace/Guard_T.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_VXWORKS)
class ACE_Message_Queue_Vx;
#endif /* defined (ACE_VXWORKS) */
#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
class ACE_Message_Queue_NT;
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO*/
#if defined (ACE_HAS_MONITOR_POINTS) && ACE_HAS_MONITOR_POINTS == 1
namespace ACE
{
  namespace Monitor_Control
  {
    class Size_Monitor;
  }
}
#endif /* ACE_HAS_MONITOR_POINTS==1 */
/**
 * @class ACE_Message_Queue
 *
 * @brief A message queueing facility with parameterized synchronization
 * capability. ACE_Message_Queue is modeled after the queueing facilities
 * in System V STREAMs.
 *
 * ACE_Message_Queue is the primary queueing facility for
 * messages in the ACE framework.  It's one template argument parameterizes
 * the queue's synchronization. The argument specifies a synchronization
 * strategy. The two main strategies available for ACE_SYNCH_DECL are:
 *   -# ACE_MT_SYNCH: all operations are thread-safe
 *   -# ACE_NULL_SYNCH: no synchronization and no locking overhead
 *
 * All data passing through ACE_Message_Queue is in the form of
 * ACE_Message_Block objects. @sa ACE_Message_Block.
 */
template <ACE_SYNCH_DECL>
class ACE_Message_Queue : public ACE_Message_Queue_Base
{
public:
  friend class ACE_Message_Queue_Iterator<ACE_SYNCH_USE>;
  friend class ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>;
  // = Traits
  typedef ACE_Message_Queue_Iterator<ACE_SYNCH_USE>
          ITERATOR;
  typedef ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE>
          REVERSE_ITERATOR;
  /**
   * @name Initialization methods
   */
  //@{
  /**
   * Initialize an ACE_Message_Queue.
   *
   * @param hwm High water mark. Determines how many bytes can be stored in a
   *        queue before it's considered full.  Supplier threads must block
   *        until the queue is no longer full.
   * @param lwm Low water mark. Determines how many bytes must be in the queue
   *        before supplier threads are allowed to enqueue additional
   *        data.  By default, the @a hwm equals @a lwm, which means
   *        that suppliers will be able to enqueue new messages as soon as
   *        a consumer removes any message from the queue.  Making the low
   *        water mark smaller than the high water mark forces consumers to
   *        drain more messages from the queue before suppliers can enqueue
   *        new messages, which can minimize the "silly window syndrome."
   * @param ns Notification strategy. Pointer to an object conforming to the
   *        ACE_Notification_Strategy interface. If set, the object's
   *        notify(void) method will be called each time data is added to
   *        this ACE_Message_Queue. @see ACE_Reactor_Notification_Strategy.
   */
  ACE_Message_Queue (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                     size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                     ACE_Notification_Strategy *ns = 0);
  virtual int open (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                    size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                    ACE_Notification_Strategy *ns = 0);
  //@}
  /// Releases all resources from the message queue and marks it deactivated.
  /// @sa flush().
  ///
  /// @retval The number of messages released from the queue; -1 on error.
  virtual int close (void);
  /// Releases all resources from the message queue and marks it deactivated.
  virtual ~ACE_Message_Queue (void);
  /**
   * Releases all resources from the message queue but does not mark it
   * deactivated.  This method holds the queue lock during this operation.
   * @sa close().
   *
   * @return The number of messages flushed; -1 on error.
   */
  virtual int flush (void);
  /**
   * Release all resources from the message queue but do not mark it
   * as deactivated.
   *
   * @pre The caller must be holding the queue lock before calling this
   * method.
   *
   * @return The number of messages flushed.
   */
  virtual int flush_i (void);
  /** @name Enqueue and dequeue methods
   *
   * The enqueue and dequeue methods accept a timeout value passed as
   * an ACE_Time_Value *. In all cases, if the timeout pointer is 0,
   * the caller will block until action is possible. If the timeout pointer
   * is non-zero, the call will wait (if needed, subject to water mark
   * settings) until the absolute time specified in the referenced
   * ACE_Time_Value object is reached. If the time is reached before the
   * desired action is possible, the method will return -1 with errno set
   * to @c EWOULDBLOCK. Regardless of the timeout setting, however,
   * these methods will also fail and return -1 when the queue is closed,
   * deactivated, pulsed, or when a signal occurs.
   *
   * See C++NPv2 Section 6.2 and APG Section 12.3 for a fuller treatment of
   * ACE_Message_Queue, enqueueing, dequeueing, and how these operations are
   * affected by queue state transitions.
   */
  //@{
  /**
   * Retrieve a pointer to the first ACE_Message_Block in the queue
   * without removing it.
   *
   * @note Because the block whose pointer is returned is still on the queue,
   *       another thread may dequeue the referenced block at any time,
   *       including before the calling thread examines the peeked-at block.
   *       Be very careful with this method in multithreaded queueing
   *       situations.
   *
   * @param first_item  Reference to an ACE_Message_Block * that will
   *                    point to the first block on the queue.  The block
   *                    remains on the queue until this or another thread
   *                    dequeues it.
   * @param timeout     The absolute time the caller will wait until
   *                    for a block to be queued.
   *
   * @retval >0 The number of ACE_Message_Blocks on the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int peek_dequeue_head (ACE_Message_Block *&first_item,
                                 ACE_Time_Value *timeout = 0);
  /**
   * Enqueue an ACE_Message_Block into the queue in accordance with
   * the ACE_Message_Block's priority (0 is lowest priority).  FIFO
   * order is maintained when messages of the same priority are
   * inserted consecutively.
   *
   * @param new_item Pointer to an ACE_Message_Block that will be
   *                 added to the queue.  The block's @c msg_priority()
   *                 method will be called to obtain the queueing priority.
   * @param timeout  The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of ACE_Message_Blocks on the queue after adding
   *             the specified block.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_prio (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Enqueue an ACE_Message_Block into the queue in accordance with the
   * block's deadline time. FIFO order is maintained when messages of
   * the same deadline time are inserted consecutively.
   *
   * @param new_item Pointer to an ACE_Message_Block that will be
   *                 added to the queue.  The block's @c msg_deadline_time()
   *                 method will be called to obtain the relative queueing
   *                 position.
   * @param timeout  The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of ACE_Message_Blocks on the queue after adding
   *             the specified block.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_deadline (ACE_Message_Block *new_item,
                                ACE_Time_Value *timeout = 0);
  /**
   * @deprecated This is an alias for enqueue_prio().  It's only here for
   * backwards compatibility and will go away in a subsequent release.
   * Please use enqueue_prio() instead.
   */
  virtual int enqueue (ACE_Message_Block *new_item,
                       ACE_Time_Value *timeout = 0);
  /**
   * Enqueue one or more ACE_Message_Block objects at the tail of the queue.
   * If the @a new_item @c next() pointer is non-zero, it is assumed to be the
   * start of a series of ACE_Message_Block objects connected via their
   * @c next() pointers. The series of blocks will be added to the queue in
   * the same order they are passed in as.
   *
   * @param new_item Pointer to an ACE_Message_Block that will be
   *                 added to the queue. If the block's @c next() pointer
   *                 is non-zero, all blocks chained from the @c next()
   *                 pointer are enqueued as well.
   * @param timeout  The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of ACE_Message_Blocks on the queue after adding
   *             the specified block(s).
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_tail (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Enqueue one or more ACE_Message_Block objects at the head of the queue.
   * If the @a new_item @c next() pointer is non-zero, it is assumed to be the
   * start of a series of ACE_Message_Block objects connected via their
   * @c next() pointers. The series of blocks will be added to the queue in
   * the same order they are passed in as.
   *
   * @param new_item Pointer to an ACE_Message_Block that will be
   *                 added to the queue. If the block's @c next() pointer
   *                 is non-zero, all blocks chained from the @c next()
   *                 pointer are enqueued as well.
   * @param timeout  The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of ACE_Message_Blocks on the queue after adding
   *             the specified block(s).
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_head (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);
  /// This method is an alias for the dequeue_head() method.
  virtual int dequeue (ACE_Message_Block *&first_item,
                       ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the ACE_Message_Block at the head of the queue and return
   * a pointer to the dequeued block.
   *
   * @param first_item  Reference to an ACE_Message_Block * that will
   *                    be set to the address of the dequeued block.
   * @param timeout     The absolute time the caller will wait until
   *                    for a block to be dequeued.
   *
   * @retval >=0 The number of ACE_Message_Blocks remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_head (ACE_Message_Block *&first_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the ACE_Message_Block that has the lowest priority (preserves
   * FIFO order for messages with the same priority) and return a pointer
   * to the dequeued block.
   *
   * @param first_item  Reference to an ACE_Message_Block * that will
   *                    be set to the address of the dequeued block.
   * @param timeout     The absolute time the caller will wait until
   *                    for a block to be dequeued.
   *
   * @retval >=0 The number of ACE_Message_Blocks remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_prio (ACE_Message_Block *&first_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the ACE_Message_Block at the tail of the queue and return
   * a pointer to the dequeued block.
   *
   * @param dequeued  Reference to an ACE_Message_Block * that will
   *                  be set to the address of the dequeued block.
   * @param timeout   The absolute time the caller will wait until
   *                  for a block to be dequeued.
   *
   * @retval >=0 The number of ACE_Message_Blocks remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_tail (ACE_Message_Block *&dequeued,
                            ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the ACE_Message_Block with the earliest deadline time and return
   * a pointer to the dequeued block.
   *
   * @param dequeued  Reference to an ACE_Message_Block * that will
   *                  be set to the address of the dequeued block.
   * @param timeout   The absolute time the caller will wait until
   *                  for a block to be dequeued.
   *
   * @retval >=0 The number of ACE_Message_Blocks remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_deadline (ACE_Message_Block *&dequeued,
                                ACE_Time_Value *timeout = 0);
  //@}
  /** @name Queue statistics methods
   */
  //@{
  /// True if queue is full, else false.
  virtual bool is_full (void);
  /// True if queue is empty, else false.
  virtual bool is_empty (void);
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
  //@}

  /** @name Water mark (flow control) methods
   */
  //@{
  /**
   * Get high watermark.
   */
  virtual size_t high_water_mark (void);
  /**
   * Set the high watermark, which determines how many bytes can be
   * stored in a queue before it's considered "full."
   */
  virtual void high_water_mark (size_t hwm);
  /**
   * Get low watermark.
   */
  virtual size_t low_water_mark (void);
  /**
   * Set the low watermark, which determines how many bytes must be in
   * the queue before supplier threads are allowed to enqueue
   * additional ACE_Message_Blocks.
   */
  virtual void low_water_mark (size_t lwm);
  //@}
  /** @name Activation and queue state methods
   * See C++NPv2 Section 6.2 and APG Section 12.3 for a fuller treatment of
   * queue states and transitions and how the transitions affect message
   * enqueueing and dequeueing operations.
   */
  //@{
  /**
   * Deactivate the queue and wakeup all threads waiting on the queue
   * so they can continue.  No messages are removed from the queue,
   * however.  Any other operations called until the queue is
   * activated again will immediately return -1 with @c errno ==
   * ESHUTDOWN.  Returns WAS_INACTIVE if queue was inactive before the
   * call and WAS_ACTIVE if queue was active before the call.
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
   * @return The queue's state before this call.
   */
  virtual int pulse (void);
  /// Returns the current state of the queue, which can be one of
  /// ACTIVATED, DEACTIVATED, or PULSED.
  virtual int state (void);
  /// Returns true if the state of the queue is <DEACTIVATED>,
  /// but false if the queue's is <ACTIVATED> or <PULSED>.
  virtual int deactivated (void);
  //@}
  /** @name Notification strategy methods
   */
  //@{
  /**
   * This hook is automatically invoked by <enqueue_head>,
   * <enqueue_tail>, and <enqueue_prio> when a new item is inserted
   * into the queue.  Subclasses can override this method to perform
   * specific notification strategies (e.g., signaling events for a
   * <WFMO_Reactor>, notifying a <Reactor>, etc.).  In a
   * multi-threaded application with concurrent consumers, there is no
   * guarantee that the queue will be still be non-empty by the time
   * the notification occurs.
   */
  virtual int notify (void);
  /// Get the notification strategy for the <Message_Queue>
  virtual ACE_Notification_Strategy *notification_strategy (void);
  /// Set the notification strategy for the <Message_Queue>
  virtual void notification_strategy (ACE_Notification_Strategy *s);
  //@}
  /// Returns a reference to the lock used by the ACE_Message_Queue.
  virtual ACE_SYNCH_MUTEX_T &lock (void);
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  // = Routines that actually do the enqueueing and dequeueing.
  // These routines assume that locks are held by the corresponding
  // public methods.  Since they are virtual, you can change the
  // queueing mechanism by subclassing from ACE_Message_Queue.
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
  virtual int dequeue_tail_i (ACE_Message_Block *&first_item);
  /// Dequeue and return the <ACE_Message_Block *> with the lowest
  /// deadline time.
  virtual int dequeue_deadline_i (ACE_Message_Block *&first_item);
  // = Check the boundary conditions (assumes locks are held).
  /// True if queue is full, else false.
  virtual bool is_full_i (void);
  /// True if queue is empty, else false.
  virtual bool is_empty_i (void);
  // = Implementation of the public <activate> and <deactivate> methods.
  // These methods assume locks are held.
  /**
   * Notifies all waiting threads that the queue has been deactivated
   * so they can wakeup and continue other processing.
   * No messages are removed from the queue.
   *
   * @param pulse  If 0, the queue's state is changed to DEACTIVATED
   *               and any other operations called until the queue is
   *               reactivated will immediately return -1 with
   *               errno == ESHUTDOWN.
   *               If not zero, only the waiting threads are notified and
   *               the queue's state changes to PULSED.
   *
   * @return The state of the queue before the call.
   */
  virtual int deactivate_i (int pulse = 0);
  /// Activate the queue.
  virtual int activate_i (void);
  // = Helper methods to factor out common #ifdef code.
  /// Wait for the queue to become non-full.
  virtual int wait_not_full_cond (ACE_Guard<ACE_SYNCH_MUTEX_T> &mon,
                                  ACE_Time_Value *timeout);
  /// Wait for the queue to become non-empty.
  virtual int wait_not_empty_cond (ACE_Guard<ACE_SYNCH_MUTEX_T> &mon,
                                   ACE_Time_Value *timeout);
  /// Inform any threads waiting to enqueue that they can procede.
  virtual int signal_enqueue_waiters (void);
  /// Inform any threads waiting to dequeue that they can procede.
  virtual int signal_dequeue_waiters (void);
  /// Pointer to head of ACE_Message_Block list.
  ACE_Message_Block *head_;
  /// Pointer to tail of ACE_Message_Block list.
  ACE_Message_Block *tail_;
  /// Lowest number before unblocking occurs.
  size_t low_water_mark_;
  /// Greatest number of bytes before blocking.
  size_t high_water_mark_;
  /// Current number of bytes in the queue.
  size_t cur_bytes_;
  /// Current length of messages in the queue.
  size_t cur_length_;
  /// Current number of messages in the queue.
  size_t cur_count_;
  /// The notification strategy used when a new message is enqueued.
  ACE_Notification_Strategy *notification_strategy_;
  // = Synchronization primitives for controlling concurrent access.
  /// Protect queue from concurrent access.
  ACE_SYNCH_MUTEX_T lock_;
  /// Used to make threads sleep until the queue is no longer empty.
  ACE_SYNCH_CONDITION_T not_empty_cond_;
  /// Used to make threads sleep until the queue is no longer full.
  ACE_SYNCH_CONDITION_T not_full_cond_;
  /// Sends the size of the queue whenever it changes.
#if defined (ACE_HAS_MONITOR_POINTS) && (ACE_HAS_MONITOR_POINTS == 1)
  ACE::Monitor_Control::Size_Monitor *monitor_;
#endif
private:
  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Message_Queue<ACE_SYNCH_USE> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Message_Queue (const ACE_Message_Queue<ACE_SYNCH_USE> &))
};
// This typedef is used to get around a compiler bug in g++/vxworks.
typedef ACE_Message_Queue<ACE_SYNCH> ACE_DEFAULT_MESSAGE_QUEUE_TYPE;

/**
 * @class ACE_Message_Queue_Iterator
 *
 * @brief Iterator for the ACE_Message_Queue.
 */
template <ACE_SYNCH_DECL>
class ACE_Message_Queue_Iterator
{
public:
  // = Initialization method.
  ACE_Message_Queue_Iterator (ACE_Message_Queue <ACE_SYNCH_USE> &queue);
  // = Iteration methods.
  /// Pass back the @a entry that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Message_Block *&entry);
  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;
  /// Move forward by one element in the queue.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Message_Queue we are iterating over.
  ACE_Message_Queue <ACE_SYNCH_USE> &queue_;
  /// Keeps track of how far we've advanced...
  ACE_Message_Block *curr_;
};
/**
 * @class ACE_Message_Queue_Reverse_Iterator
 *
 * @brief Reverse Iterator for the ACE_Message_Queue.
 */
template <ACE_SYNCH_DECL>
class ACE_Message_Queue_Reverse_Iterator
{
public:
  // = Initialization method.
  ACE_Message_Queue_Reverse_Iterator (ACE_Message_Queue <ACE_SYNCH_USE> &queue);
  // = Iteration methods.
  /// Pass back the @a entry that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_Message_Block *&entry);
  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;
  /// Move forward by one element in the queue.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Message_Queue we are iterating over.
  ACE_Message_Queue <ACE_SYNCH_USE> &queue_;
  /// Keeps track of how far we've advanced...
  ACE_Message_Block *curr_;
};
/**
 * @class ACE_Dynamic_Message_Queue
 *
 * @brief A derived class which adapts the ACE_Message_Queue
 * class in order to maintain dynamic priorities for enqueued
 * <ACE_Message_Blocks> and manage the queue order according
 * to these dynamic priorities.
 *
 * The messages in the queue are managed so as to preserve
 * a logical ordering with minimal overhead per enqueue and
 * dequeue operation.  For this reason, the actual order of
 * messages in the linked list of the queue may differ from
 * their priority order.  As time passes, a message may change
 * from pending status to late status, and eventually to beyond
 * late status.  To minimize reordering overhead under this
 * design force, three separate boundaries are maintained
 * within the linked list of messages.  Messages are dequeued
 * preferentially from the head of the pending portion, then
 * the head of the late portion, and finally from the head
 * of the beyond late portion.  In this way, only the boundaries
 * need to be maintained (which can be done efficiently, as
 * aging messages maintain the same linked list order as they
 * progress from one status to the next), with no reordering
 * of the messages themselves, while providing correct priority
 * ordered dequeueing semantics.
 * Head and tail enqueue methods inherited from ACE_Message_Queue
 * are made private to prevent out-of-order messages from confusing
 * management of the various portions of the queue.  Messages in
 * the pending portion of the queue whose priority becomes late
 * (according to the specific dynamic strategy) advance into
 * the late portion of the queue.  Messages in the late portion
 * of the queue whose priority becomes later than can be represented
 * advance to the beyond_late portion of the queue.  These behaviors
 * support a limited schedule overrun, with pending messages prioritized
 * ahead of late messages, and late messages ahead of beyond late
 * messages.  These behaviors can be modified in derived classes by
 * providing alternative definitions for the appropriate virtual methods.
 * When filled with messages, the queue's linked list should look like:
 * H                                           T
 * |                                           |
 * B - B - B - B - L - L - L - P - P - P - P - P
 * |           |   |       |   |               |
 * BH          BT   LH     LT   PH             PT
 * Where the symbols are as follows:
 * H  = Head of the entire list
 * T  = Tail of the entire list
 * B  = Beyond late message
 * BH = Beyond late messages Head
 * BT = Beyond late messages Tail
 * L  = Late message
 * LH = Late messages Head
 * LT = Late messages Tail
 * P  = Pending message
 * PH = Pending messages Head
 * PT = Pending messages Tail
 * Caveat: the virtual methods enqueue_tail, enqueue_head,
 * and peek_dequeue_head have semantics for the static
 * message queues that cannot be guaranteed for dynamic
 * message queues.  The peek_dequeue_head method just
 * calls the base class method, while the two enqueue
 * methods call the priority enqueue method.  The
 * order of messages in the dynamic queue is a function
 * of message deadlines and how long they are in the
 * queues.  You can manipulate these in some cases to
 * ensure the correct semantics, but that is not a
 * very stable or portable approach (discouraged).
 */
template <ACE_SYNCH_DECL>
class ACE_Dynamic_Message_Queue : public ACE_Message_Queue<ACE_SYNCH_USE>
{
public:
  // = Initialization and termination methods.
  ACE_Dynamic_Message_Queue (ACE_Dynamic_Message_Strategy & message_strategy,
                             size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                             size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                             ACE_Notification_Strategy * = 0);
  /// Close down the message queue and release all resources.
  virtual ~ACE_Dynamic_Message_Queue (void);
  /**
   * Detach all messages with status given in the passed flags from
   * the queue and return them by setting passed head and tail pointers
   * to the linked list they comprise.  This method is intended primarily
   * as a means of periodically harvesting messages that have missed
   * their deadlines, but is available in its most general form.  All
   * messages are returned in priority order, from head to tail, as of
   * the time this method was called.
   */
  virtual int remove_messages (ACE_Message_Block *&list_head,
                               ACE_Message_Block *&list_tail,
                               u_int status_flags);
  /**
   * Dequeue and return the <ACE_Message_Block *> at the head of the
   * queue.  Returns -1 on failure, else the number of items still on
   * the queue.
   */
  virtual int dequeue_head (ACE_Message_Block *&first_item,
                            ACE_Time_Value *timeout = 0);
  /// Dump the state of the queue.
  virtual void dump (void) const;
  /**
   * Just call priority enqueue method: tail enqueue semantics for dynamic
   * message queues are unstable: the message may or may not be where
   * it was placed after the queue is refreshed prior to the next
   * enqueue or dequeue operation.
   */
  virtual int enqueue_tail (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Just call priority enqueue method: head enqueue semantics for dynamic
   * message queues are unstable: the message may or may not be where
   * it was placed after the queue is refreshed prior to the next
   * enqueue or dequeue operation.
   */
  virtual int enqueue_head (ACE_Message_Block *new_item,
                            ACE_Time_Value *timeout = 0);

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /**
   * Enqueue an <ACE_Message_Block *> in accordance with its priority.
   * priority may be *dynamic* or *static* or a combination or *both*
   * It calls the priority evaluation function passed into the Dynamic
   * Message Queue constructor to update the priorities of all
   * enqueued messages.
   */
  virtual int enqueue_i (ACE_Message_Block *new_item);
  /// Enqueue a message in priority order within a given priority status sublist
  virtual int sublist_enqueue_i (ACE_Message_Block *new_item,
                                 const ACE_Time_Value &current_time,
                                 ACE_Message_Block *&sublist_head,
                                 ACE_Message_Block *&sublist_tail,
                                 ACE_Dynamic_Message_Strategy::Priority_Status status);
  /**
   * Dequeue and return the <ACE_Message_Block *> at the head of the
   * logical queue.  Attempts first to dequeue from the pending
   * portion of the queue, or if that is empty from the late portion,
   * or if that is empty from the beyond late portion, or if that is
   * empty just sets the passed pointer to zero and returns -1.
   */
  virtual int dequeue_head_i (ACE_Message_Block *&first_item);
  /// Refresh the queue using the strategy
  /// specific priority status function.
  virtual int refresh_queue (const ACE_Time_Value & current_time);
  /// Refresh the pending queue using the strategy
  /// specific priority status function.
  virtual int refresh_pending_queue (const ACE_Time_Value & current_time);
  /// Refresh the late queue using the strategy
  /// specific priority status function.
  virtual int refresh_late_queue (const ACE_Time_Value & current_time);
  /// Pointer to head of the pending messages
  ACE_Message_Block *pending_head_;
  /// Pointer to tail of the pending messages
  ACE_Message_Block *pending_tail_;
  /// Pointer to head of the late messages
  ACE_Message_Block *late_head_;
  /// Pointer to tail of the late messages
  ACE_Message_Block *late_tail_;
  /// Pointer to head of the beyond late messages
  ACE_Message_Block *beyond_late_head_;
  /// Pointer to tail of the beyond late messages
  ACE_Message_Block *beyond_late_tail_;
  /// Pointer to a dynamic priority evaluation function.
  ACE_Dynamic_Message_Strategy &message_strategy_;
private:
  // = Disallow public access to these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Dynamic_Message_Queue (const ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> &))
  // provide definitions for these (just call base class method),
  // but make them private so they're not accessible outside the class
  /// Private method to hide public base class method: just calls base class method
  virtual int peek_dequeue_head (ACE_Message_Block *&first_item,
                                 ACE_Time_Value *timeout = 0);
};
/**
 * @class ACE_Message_Queue_Factory
 *
 * @brief ACE_Message_Queue_Factory is a static factory class template which
 * provides a separate factory method for each of the major kinds of
 * priority based message dispatching: static, earliest deadline first
 * (EDF), and minimum laxity first (MLF).
 *
 * The ACE_Dynamic_Message_Queue class assumes responsibility for
 * releasing the resources of the strategy with which it was
 * constructed: the user of a message queue constructed by
 * any of these factory methods is only responsible for
 * ensuring destruction of the message queue itself.
 */
template <ACE_SYNCH_DECL>
class ACE_Message_Queue_Factory
{
public:
  /// Factory method for a statically prioritized ACE_Message_Queue
  static ACE_Message_Queue<ACE_SYNCH_USE> *
    create_static_message_queue (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                                 size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                                 ACE_Notification_Strategy * = 0);
  /// Factory method for a dynamically prioritized (by time to deadline) ACE_Dynamic_Message_Queue
  static ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *
    create_deadline_message_queue (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                                   size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                                   ACE_Notification_Strategy * = 0,
                                   u_long static_bit_field_mask = 0x3FFUL,        // 2^(10) - 1
                                   u_long static_bit_field_shift = 10,            // 10 low order bits
                                   u_long dynamic_priority_max = 0x3FFFFFUL,      // 2^(22)-1
                                   u_long dynamic_priority_offset =  0x200000UL); // 2^(22-1)
  /// Factory method for a dynamically prioritized (by laxity) ACE_Dynamic_Message_Queue
  static ACE_Dynamic_Message_Queue<ACE_SYNCH_USE> *
    create_laxity_message_queue (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                                 size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                                 ACE_Notification_Strategy * = 0,
                                 u_long static_bit_field_mask = 0x3FFUL,        // 2^(10) - 1
                                 u_long static_bit_field_shift = 10,            // 10 low order bits
                                 u_long dynamic_priority_max = 0x3FFFFFUL,      // 2^(22)-1
                                 u_long dynamic_priority_offset =  0x200000UL); // 2^(22-1)

#if defined (ACE_VXWORKS)
  /// Factory method for a wrapped VxWorks message queue
  static ACE_Message_Queue_Vx *
    create_Vx_message_queue (size_t max_messages, size_t max_message_length,
                             ACE_Notification_Strategy *ns = 0);
#endif /* defined (ACE_VXWORKS) */
#if defined (ACE_HAS_WIN32_OVERLAPPED_IO)
  /// Factory method for a NT message queue.
  static ACE_Message_Queue_NT *
  create_NT_message_queue (size_t max_threads);
#endif /* ACE_HAS_WIN32_OVERLAPPED_IO */
};
// Forward decls.
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> class ACE_Message_Queue_Ex_Iterator;
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL> class ACE_Message_Queue_Ex_Reverse_Iterator;
/**
 * @class ACE_Message_Queue_Ex
 *
 * @brief A threaded message queueing facility, modeled after the
 *        queueing facilities in System V STREAMs.
 *
 * ACE_Message_Queue_Ex is a strongly-typed version of the
 * ACE_Message_Queue class. Rather than queueing in terms of ACE_Message_Block
 * objects, ACE_Message_Queue_Ex has a template argument to specify the
 * type of objects that are queued.
 *
 * The second template argument parameterizes the queue's synchronization.
 * The argument specifies a synchronization strategy. The two main
 * strategies available for ACE_SYNCH_DECL are:
 *   -# ACE_MT_SYNCH: all operations are thread-safe
 *   -# ACE_NULL_SYNCH: no synchronization and no locking overhead
 */
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
class ACE_Message_Queue_Ex
{
public:
  enum
  {
    /// Default priority value. This is the lowest priority.
    DEFAULT_PRIORITY = 0
  };
  friend class ACE_Message_Queue_Ex_Iterator <ACE_MESSAGE_TYPE, ACE_SYNCH_USE>;
  friend class ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>;
  // = Traits
  typedef ACE_Message_Queue_Ex_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>
          ITERATOR;
  typedef ACE_Message_Queue_Ex_Reverse_Iterator<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>
          REVERSE_ITERATOR;
  /**
   * @name Initialization methods
   */
  //@{
  /**
   * Initialize an ACE_Message_Queue_Ex.
   *
   * @param high_water_mark High water mark. Determines how many bytes can be
   *        stored in a queue before it's considered full.  Supplier threads
   *        must block until the queue is no longer full.
   * @param low_water_mark Low water mark. Determines how many bytes must be in
   *        the queue before supplier threads are allowed to enqueue additional
   *        data.  By default, the @a hwm equals @a lwm, which means
   *        that suppliers will be able to enqueue new messages as soon as
   *        a consumer removes any message from the queue.  Making the low
   *        water mark smaller than the high water mark forces consumers to
   *        drain more messages from the queue before suppliers can enqueue
   *        new messages, which can minimize the "silly window syndrome."
   * @param ns Notification strategy. Pointer to an object conforming to the
   *        ACE_Notification_Strategy interface. If set, the object's
   *        notify(void) method will be called each time data is added to
   *        this ACE_Message_Queue. @see ACE_Reactor_Notification_Strategy.
   */
  ACE_Message_Queue_Ex (size_t high_water_mark = ACE_Message_Queue_Base::DEFAULT_HWM,
                        size_t low_water_mark = ACE_Message_Queue_Base::DEFAULT_LWM,
                        ACE_Notification_Strategy * ns = 0);
  virtual int open (size_t hwm = ACE_Message_Queue_Base::DEFAULT_HWM,
                    size_t lwm = ACE_Message_Queue_Base::DEFAULT_LWM,
                    ACE_Notification_Strategy * = 0);
  //@}
  /// Releases all resources from the message queue and marks it deactivated.
  /// @sa flush().
  ///
  /// @retval The number of messages released from the queue; -1 on error.
  virtual int close (void);
  /// Releases all resources from the message queue and marks it deactivated.
  virtual ~ACE_Message_Queue_Ex (void);
  /**
   * Releases all resources from the message queue but does not mark it
   * deactivated.  This method holds the queue lock during this operation.
   * @sa close().
   *
   * @return The number of messages flushed; -1 on error.
   */
  virtual int flush (void);
  /**
   * Release all resources from the message queue but do not mark it
   * as deactivated.
   *
   * @pre The caller must be holding the queue lock before calling this
   * method.
   *
   * @return The number of messages flushed.
   */
  virtual int flush_i (void);
  /** @name Enqueue and dequeue methods
   *
   * The enqueue and dequeue methods accept a timeout value passed as
   * an ACE_Time_Value *. In all cases, if the timeout pointer is 0,
   * the caller will block until action is possible. If the timeout pointer
   * is non-zero, the call will wait (if needed, subject to water mark
   * settings) until the absolute time specified in the referenced
   * ACE_Time_Value object is reached. If the time is reached before the
   * desired action is possible, the method will return -1 with errno set
   * to @c EWOULDBLOCK. Regardless of the timeout setting, however,
   * these methods will also fail and return -1 when the queue is closed,
   * deactivated, pulsed, or when a signal occurs.
   *
   * The time parameters are handled the same as in ACE_Message_Queue, so
   * you can see C++NPv2 Section 6.2 and APG Section 12.3 for a fuller
   * treatment of ACE_Message_Queue, enqueueing, dequeueing, and how these
   * operations are affected by queue state transitions.
   */
  //@{
  /**
   * Retrieve a pointer to the first item in the queue without removing it.
   *
   * @note Because the item whose pointer is returned is still on the queue,
   *       another thread may dequeue that item at any time,
   *       including before the calling thread examines the peeked-at item.
   *       Be very careful with this method in multithreaded queueing
   *       situations.
   *
   * @param first_item  Reference to an ACE_MESSAGE_TYPE * that will
   *                    point to the first item on the queue.  The item
   *                    remains on the queue until this or another thread
   *                    dequeues it.
   * @param timeout     The absolute time the caller will wait until
   *                    for an item to be queued.
   *
   * @retval >0 The number of items on the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int peek_dequeue_head (ACE_MESSAGE_TYPE *&first_item,
                                 ACE_Time_Value *timeout = 0);
  /**
   * Enqueue an ACE_MESSAGE TYPE into the queue in accordance with
   * the specified priority (0 is lowest priority).  FIFO
   * order is maintained when items of the same priority are
   * inserted consecutively.
   *
   * @param new_item Pointer to an item that will be added to the queue.
   * @param timeout  The absolute time the caller will wait until
   *                 for the block to be queued.
   * @param priority The priority to use when enqueueing the item.
   *
   * @retval >0 The number of items on the queue after adding
   *             the specified item.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_prio (ACE_MESSAGE_TYPE *new_item,
                            ACE_Time_Value *timeout = 0,
                            unsigned long priority = DEFAULT_PRIORITY);
  /**
   * This method acts just like enqueue_tail(). There's no deadline
   * time associated with items.
   */
  virtual int enqueue_deadline (ACE_MESSAGE_TYPE *new_item,
                                ACE_Time_Value *timeout = 0);
  /**
   * @deprecated This is an alias for enqueue_prio().  It's only here for
   * backwards compatibility and will go away in a subsequent release.
   * Please use enqueue_prio() instead.
   */
  virtual int enqueue (ACE_MESSAGE_TYPE *new_item,
                       ACE_Time_Value *timeout = 0);
  /**
   * Enqueue an item at the tail of the queue.
   *
   * @param new_item Pointer to an item that will be added to the queue.
   * @param timeout  The absolute time the caller will wait until
   *                 for the item to be queued.
   *
   * @retval >0 The number of items on the queue after adding
   *             the specified item.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_tail (ACE_MESSAGE_TYPE *new_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Enqueue an item at the head of the queue.
   *
   * @param new_item Pointer to an item that will be added to the queue.
   * @param timeout  The absolute time the caller will wait until
   *                 for the item to be queued.
   *
   * @retval >0 The number of items on the queue after adding
   *             the specified item.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_head (ACE_MESSAGE_TYPE *new_item,
                            ACE_Time_Value *timeout = 0);
  /// This method is an alias for the following <dequeue_head> method.
  virtual int dequeue (ACE_MESSAGE_TYPE *&first_item,
                       ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the item at the head of the queue and return a pointer to it.
   *
   * @param first_item  Reference to an ACE_MESSAGE_TYPE * that will
   *                    be set to the address of the dequeued item.
   * @param timeout     The absolute time the caller will wait until
   *                    for an item to be dequeued.
   *
   * @retval >=0 The number of items remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_head (ACE_MESSAGE_TYPE *&first_item,
                            ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the item that has the lowest priority (preserves
   * FIFO order for items with the same priority) and return a pointer
   * to it.
   *
   * @param dequeued  Reference to an ACE_MESSAGE_TYPE * that will
   *                  be set to the address of the dequeued item.
   * @param timeout     The absolute time the caller will wait until
   *                    for an item to be dequeued.
   *
   * @retval >=0 The number of items remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_prio (ACE_MESSAGE_TYPE *&dequeued,
                            ACE_Time_Value *timeout = 0);
  /**
   * Dequeue the item at the tail of the queue and return a pointer to it.
   *
   * @param dequeued  Reference to an ACE_MESSAGE_TYPE * that will
   *                  be set to the address of the dequeued item.
   * @param timeout   The absolute time the caller will wait until
   *                  for an item to be dequeued.
   *
   * @retval >=0 The number of items remaining in the queue.
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int dequeue_tail (ACE_MESSAGE_TYPE *&dequeued,
                            ACE_Time_Value *timeout = 0);
  /**
   * Because there's deadline associated with enqueue_deadline(), this
   * method will behave just as dequeue_head().
   */
  virtual int dequeue_deadline (ACE_MESSAGE_TYPE *&dequeued,
                                ACE_Time_Value *timeout = 0);
  //@}
  /** @name Queue statistics methods
   */
  //@{
  /// True if queue is full, else false.
  virtual bool is_full (void);
  /// True if queue is empty, else false.
  virtual bool is_empty (void);
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
  //@}
  /** @name Water mark (flow control) methods
   */
  //@{
  /**
   * Get high watermark.
   */
  virtual size_t high_water_mark (void);
  /**
   * Set the high watermark, which determines how many bytes can be
   * stored in a queue before it's considered "full."
   */
  virtual void high_water_mark (size_t hwm);
  /**
   * Get low watermark.
   */
  virtual size_t low_water_mark (void);
  /**
   * Set the low watermark, which determines how many bytes must be in
   * the queue before supplier threads are allowed to enqueue
   * additional <ACE_MESSAGE_TYPE>s.
   */
  virtual void low_water_mark (size_t lwm);
  //@}
  /** @name Activation and queue state methods
   * See C++NPv2 Section 6.2 and APG Section 12.3 for a fuller treatment of
   * queue states and transitions and how the transitions affect message
   * enqueueing and dequeueing operations.
   */
  //@{
  /**
   * Deactivate the queue and wakeup all threads waiting on the queue
   * so they can continue.  No messages are removed from the queue,
   * however.  Any other operations called until the queue is
   * activated again will immediately return -1 with @c errno ==
   * ESHUTDOWN.  Returns WAS_INACTIVE if queue was inactive before the
   * call and WAS_ACTIVE if queue was active before the call.
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
  /// Returns the current state of the queue, which can be one of
  /// ACTIVATED, DEACTIVATED, or PULSED.
  virtual int state (void);
  /// Returns true if the state of the queue is DEACTIVATED,
  /// but false if the queue's state is ACTIVATED or PULSED.
  virtual int deactivated (void);
  //@}
  /** @name Notification strategy methods
   */
  //@{
  /**
   * This hook is automatically invoked by <enqueue_head>,
   * <enqueue_tail>, and <enqueue_prio> when a new item is inserted
   * into the queue.  Subclasses can override this method to perform
   * specific notification strategies (e.g., signaling events for a
   * <WFMO_Reactor>, notifying a <Reactor>, etc.).  In a
   * multi-threaded application with concurrent consumers, there is no
   * guarantee that the queue will be still be non-empty by the time
   * the notification occurs.
   */
  virtual int notify (void);
  /// Get the notification strategy for the <Message_Queue>
  virtual ACE_Notification_Strategy *notification_strategy (void);
  /// Set the notification strategy for the <Message_Queue>
  virtual void notification_strategy (ACE_Notification_Strategy *s);
  //@}
  /// Returns a reference to the lock used by the ACE_Message_Queue_Ex.
  virtual ACE_SYNCH_MUTEX_T &lock (void);
  /// Dump the state of an object.
  virtual void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /// Implement this via an ACE_Message_Queue.
  ACE_Message_Queue<ACE_SYNCH_USE> queue_;
};
/**
 * @class ACE_Message_Queue_Ex_Iterator
 *
 * @brief Iterator for the ACE_Message_Queue_Ex.
 */
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
class ACE_Message_Queue_Ex_Iterator
{
public:
  // = Initialization method.
  ACE_Message_Queue_Ex_Iterator (ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE> & queue);
  // = Iteration methods.
  /// Pass back the @a entry that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_MESSAGE_TYPE *&entry);
  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;
  /// Move forward by one element in the queue.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Implement this via the ACE_Message_Queue_Iterator
  ACE_Message_Queue_Iterator<ACE_SYNCH_USE> iter_;
};
/**
 * @class ACE_Message_Queue_Ex_Iterator
 *
 * @brief Reverse iterator for the ACE_Message_Queue_Ex.
 */
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
class ACE_Message_Queue_Ex_Reverse_Iterator
{
public:
  // = Initialization method.
  ACE_Message_Queue_Ex_Reverse_Iterator (ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE> & queue);
  // = Iteration methods.
  /// Pass back the @a entry that hasn't been seen in the queue.
  /// Returns 0 when all items have been seen, else 1.
  int next (ACE_MESSAGE_TYPE *&entry);
  /// Returns 1 when all items have been seen, else 0.
  int done (void) const;
  /// Move forward by one element in the queue.  Returns 0 when all the
  /// items in the set have been seen, else 1.
  int advance (void);
  /// Dump the state of an object.
  void dump (void) const;
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  /// Implement this via the ACE_Message_Queue_Reverse_Iterator
  ACE_Message_Queue_Reverse_Iterator<ACE_SYNCH_USE> iter_;
};
/**
 * @class ACE_Message_Queue_Ex_N
 *
 * @brief A threaded message queueing facility, modeled after the
 *        queueing facilities in System V STREAMs which can enqueue
 *        multiple messages in one call.
 *
 * As ACE_Message_Queue_Ex, ACE_Message_Queue_Ex_N is a strongly-typed
 * version of the ACE_Message_Queue. If @c ACE_SYNCH_DECL is @c ACE_MT_SYNCH
 * then all operations are thread-safe. Otherwise, if it's @c ACE_NULL_SYNCH
 * then there's no locking overhead.
 *
 * The @c ACE_MESSAGE_TYPE messages that are sent to this
 * queue can be chained. Messages are expected to have a
 * @c next method that returns the next message in the chain;
 * ACE_Message_Queue_Ex_N uses this method to run through
 * all the incoming messages and enqueue them in one call.
 */
template <class ACE_MESSAGE_TYPE, ACE_SYNCH_DECL>
class ACE_Message_Queue_Ex_N : public ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE>
{
public:
  // = Initialization and termination methods.
  /**
   * Initialize an ACE_Message_Queue_Ex_N.  The @a high_water_mark
   * determines how many bytes can be stored in a queue before it's
   * considered "full."  Supplier threads must block until the queue
   * is no longer full.  The @a low_water_mark determines how many
   * bytes must be in the queue before supplier threads are allowed to
   * enqueue additional messages.  By default, the @a high_water_mark
   * equals the @a low_water_mark, which means that suppliers will be
   * able to enqueue new messages as soon as a consumer removes any message
   * from the queue.  Making the @a low_water_mark smaller than the
   * @a high_water_mark forces consumers to drain more messages from the
   * queue before suppliers can enqueue new messages, which can minimize
   * the "silly window syndrome."
   */
  ACE_Message_Queue_Ex_N (size_t high_water_mark = ACE_Message_Queue_Base::DEFAULT_HWM,
                          size_t low_water_mark = ACE_Message_Queue_Base::DEFAULT_LWM,
                          ACE_Notification_Strategy * ns = 0);
  /// Close down the message queue and release all resources.
  virtual ~ACE_Message_Queue_Ex_N (void);
  /**
   * Enqueue one or more @c ACE_MESSAGE_TYPE objects at the head of the queue.
   * If the @a new_item @c next() pointer is non-zero, it is assumed to be the
   * start of a series of @c ACE_MESSAGE_TYPE objects connected via their
   * @c next() pointers. The series of blocks will be added to the queue in
   * the same order they are passed in as.
   *
   * @param new_item Pointer to an @c ACE_MESSAGE_TYPE that will be
   *                 added to the queue. If the block's @c next() pointer
   *                 is non-zero, all blocks chained from the @c next()
   *                 pointer are enqueued as well.
   * @param tv       The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of @c ACE_MESSAGE_TYPE objects on the queue after
   *             adding the specified block(s).
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_head (ACE_MESSAGE_TYPE *new_item, ACE_Time_Value *tv = 0);
  /**
   * Enqueue one or more @c ACE_MESSAGE_TYPE objects at the tail of the queue.
   * If the @a new_item @c next() pointer is non-zero, it is assumed to be the
   * start of a series of @c ACE_MESSAGE_TYPE objects connected via their
   * @c next() pointers. The series of blocks will be added to the queue in
   * the same order they are passed in as.
   *
   * @param new_item Pointer to an @c ACE_MESSAGE_TYPE that will be
   *                 added to the queue. If the block's @c next() pointer
   *                 is non-zero, all blocks chained from the @c next()
   *                 pointer are enqueued as well.
   * @param tv       The absolute time the caller will wait until
   *                 for the block to be queued.
   *
   * @retval >0 The number of @c ACE_MESSAGE_TYPE objects on the queue after
   *             adding the specified block(s).
   * @retval -1 On failure.  errno holds the reason. Common errno values are:
   *            - EWOULDBLOCK: the timeout elapsed
   *            - ESHUTDOWN: the queue was deactivated or pulsed
   */
  virtual int enqueue_tail (ACE_MESSAGE_TYPE *new_item, ACE_Time_Value *tv = 0);
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
protected:
  /**
   * An helper method that wraps the incoming chain messages
   * with ACE_Message_Blocks.
   */
  ACE_Message_Block *wrap_with_mbs_i (ACE_MESSAGE_TYPE *new_item);
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Message_Queue_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */
#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Message_Queue_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */
#include /**/ "ace/post.h"
#endif /* ACE_MESSAGE_QUEUE_T_H */

