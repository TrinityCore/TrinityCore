// -*- C++ -*-
//=============================================================================
/**
 *  @file    Activation_Queue.h
 *
 *  $Id: Activation_Queue.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Andres Kruse <Andres.Kruse@cern.ch>
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================
#ifndef ACE_ACTIVATION_QUEUE_H
#define ACE_ACTIVATION_QUEUE_H
#include /**/ "ace/pre.h"
#include /**/ "ace/ACE_export.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/Message_Queue.h"
#include "ace/Condition_Thread_Mutex.h"
/// Define to be compatible with the terminology in the POSA2 book!
#define ACE_Activation_List ACE_Activation_Queue
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
class ACE_Method_Request;
/**
 * @class ACE_Activation_Queue
 *
 * @brief Reifies a method into a request.  Subclasses typically
 * represent necessary state and behavior.
 *
 * Maintains a priority-ordered queue of ACE_Method_Request objects.
 * A scheduler class (often derived from ACE_Task) subsequently removes
 * each method request and invokes its @c call() method.
 *
 * This class is discussed in depth in the Active Object chapter
 * of POSA2. In that book, it is referred to as an Activation List.
 *
 * @sa ACE_Method_Request
 */
class ACE_Export ACE_Activation_Queue
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  /**
   * Initializes a new activation queue.
   *
   * @param new_queue The activation queue uses an ACE_Message_Queue to
   *                  queue and order the method requests. If this argument
   *                  is 0, a new ACE_Message_Queue is created for this
   *                  object's use and will be deleted when this object is
   *                  destroyed. If a non-zero pointer is supplied, the
   *                  passed object will be used and will not be deleted when
   *                  this object is destroyed. If an ACE_Task is being created
   *                  to act as the scheduler, for instance, its
   *                  ACE_Message_Queue pointer can be passed to this object.
   * @param alloc     Optional, the allocator to use when allocating
   *                  ACE_Message_Block instances that wrap the method requests
   *                  queued to this activation queue. Defaults to
   *                  ACE_Allocator::instance().
   * @param db_alloc  Optional, the allocator to use when allocating
   *                  data blocks for the ACE_Message_Block instances that
   *                  wrap the method requests queued to this activation queue.
   *                  Defaults to ACE_Allocator::instance().
   */
  ACE_Activation_Queue (ACE_Message_Queue<ACE_SYNCH> *new_queue = 0,
                        ACE_Allocator *alloc = 0,
                        ACE_Allocator *db_alloc = 0);
  /// Destructor.
  virtual ~ACE_Activation_Queue (void);
  // = Activate Queue operations.
  /// Dequeue the next available ACE_Method_Request.
  /**
   * @param tv  If 0, the method will block until a method request is
   *            available, else will wait until the absolute time specified
   *            in the referenced ACE_Time_Value.  This method will return,
   *            earlier, however, if queue is closed, deactivated, or when
   *            a signal occurs.
   *
   * @retval    Pointer to the dequeued ACE_Method_Request object.
   * @retval    0 an error occurs; errno contains further information. If
   *            the specified timeout elapses, errno will be @c EWOULDBLOCK.
   */
  ACE_Method_Request *dequeue (ACE_Time_Value *tv = 0);
  /// Enqueue the ACE_Method_Request in priority order.
  /**
   * The priority of the method request is obtained via the @c priority()
   * method of the queued method request. Priority ordering is determined
   * by the ACE_Message_Queue class; 0 is the lowest priority.
   *
   * @param new_method_request  Pointer to the ACE_Method_Request object to
   *            queue. This object's @c priority() method is called to obtain
   *            the priority.
   * @param tv  If 0, the method will block until the method request can
   *            be queued, else will wait until the absolute time specified
   *            in the referenced ACE_Time_Value.  This method will return,
   *            earlier, however, if queue is closed, deactivated, or when
   *            a signal occurs.
   *
   * @retval    >0 The number of method requests on the queue after adding
   *            the specified request.
   * @retval    -1 if an error occurs; errno contains further information. If
   *            the specified timeout elapses, errno will be @c EWOULDBLOCK.
   */
  int enqueue (ACE_Method_Request *new_method_request, ACE_Time_Value *tv = 0);
  /// Get the current number of method objects in the queue.
  size_t method_count (void) const;
  /// Returns 1 if the queue is empty, 0 otherwise.
  int is_empty (void) const;
  /// Returns 1 if the queue is full, 0 otherwise.
  int is_full (void) const;
  /// Dump the state of an request.
  void dump (void) const;
  /// Get a pointer to the underlying queue.
  ACE_Message_Queue<ACE_SYNCH> *queue (void) const;
  /// Set the pointer to the underlying queue.
  void queue (ACE_Message_Queue<ACE_SYNCH> *q);
  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
private:
  // = Prevent copying and assignment.
  ACE_Activation_Queue (const ACE_Activation_Queue &);
  void operator= (const ACE_Activation_Queue &);
protected:
  /// Stores the Method_Requests.
  ACE_Message_Queue<ACE_SYNCH> *queue_;
  /// Keeps track of whether we need to delete the queue.
  bool delete_queue_;
private:
  /// Allocation strategy of the queue.
  ACE_Allocator *allocator_;
  /// Allocation strategy of the message blocks.
  ACE_Allocator *data_block_allocator_;
};
ACE_END_VERSIONED_NAMESPACE_DECL
#if defined (__ACE_INLINE__)
#include "ace/Activation_Queue.inl"
#endif /* __ACE_INLINE__ */
#include /**/ "ace/post.h"
#endif /* ACE_ACTIVATION_QUEUE_H */

