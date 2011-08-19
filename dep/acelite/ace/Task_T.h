// -*- C++ -*-

//=============================================================================
/**
 *  @file    Task_T.h
 *
 *  $Id: Task_T.h 91688 2010-09-09 11:21:50Z johnnyw $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TASK_T_H
#define ACE_TASK_T_H
#include /**/ "ace/pre.h"

#include "ace/Message_Queue.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_Traits.h"
#include "ace/Task.h"
#include "ace/IO_Cntl_Msg.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls...
template <ACE_SYNCH_DECL> class ACE_Module;

/**
 * @class ACE_Task
 *
 * @brief Primary interface for application message processing, as well
 * as input and output message queueing.
 *
 * This class serves as the basis for passive and active objects
 * in ACE.
 */
template <ACE_SYNCH_DECL>
class ACE_Task : public ACE_Task_Base
{
public:
  friend class ACE_Module<ACE_SYNCH_USE>;
  friend class ACE_Module_Type;

  // = Initialization/termination methods.
  /**
   * Initialize a Task, supplying a thread manager and a message
   * queue.  If the user doesn't supply a ACE_Message_Queue pointer
   * then we'll allocate one dynamically.  Otherwise, we'll use the
   * one passed as a parameter.
   */
  ACE_Task (ACE_Thread_Manager *thr_mgr = 0,
            ACE_Message_Queue<ACE_SYNCH_USE> *mq = 0);

  /// Destructor.
  virtual ~ACE_Task (void);

  /// Gets the message queue associated with this task.
  ACE_Message_Queue<ACE_SYNCH_USE> *msg_queue (void);

  /// Sets the message queue associated with this task.
  void msg_queue (ACE_Message_Queue<ACE_SYNCH_USE> *);

public: // Should be protected:
  // = Message queue manipulation methods.

  // = Enqueue and dequeue methods.

  // For the following five method if @a timeout == 0, the caller will
  // block until action is possible, else will wait until the
  // <{absolute}> time specified in *@a timeout elapses).  These calls
  // will return, however, when queue is closed, deactivated, when a
  // signal occurs, or if the time specified in timeout elapses, (in
  // which case errno = EWOULDBLOCK).

  /// Insert message into the message queue.  Note that @a timeout uses
  /// <{absolute}> time rather than <{relative}> time.
  int putq (ACE_Message_Block *, ACE_Time_Value *timeout = 0);

  /**
   * Extract the first message from the queue (blocking).  Note that
   * @a timeout uses <{absolute}> time rather than <{relative}> time.
   * Returns number of items in queue if the call succeeds or -1 otherwise.
   */
  int getq (ACE_Message_Block *&mb, ACE_Time_Value *timeout = 0);

  /// Return a message to the queue.  Note that @a timeout uses
  /// <{absolute}> time rather than <{relative}> time.
  int ungetq (ACE_Message_Block *, ACE_Time_Value *timeout = 0);

  /**
   * Turn the message around, sending it in the opposite direction in
   * the stream. To do this, the message is put onto the task next in
   * the stream after this task's sibling.
   *
   * @param mb Pointer to the block that is used in the reply.
   * @param tv The absolute time at which the put operation used to
   *           send the message block to the next module in the stream
   *           will time out. If 0, this call blocks until it can be
   *           completed.
   */
  int reply (ACE_Message_Block *mb, ACE_Time_Value *tv = 0);

  /**
   * Transfer message to the adjacent ACE_Task in a ACE_Stream.  Note
   * that @a timeout uses <{absolute}> time rather than <{relative}>
   * time.
   */
  int put_next (ACE_Message_Block *msg, ACE_Time_Value *timeout = 0);

  // = ACE_Task utility routines to identify names et al.
  /// Return the name of the enclosing Module if there's one associated
  /// with the Task, else returns 0.
  const ACE_TCHAR *name (void) const;

  // = Pointers to next ACE_Task_Base (if ACE is part of an ACE_Stream).
  /// Get next Task pointer.
  ACE_Task<ACE_SYNCH_USE> *next (void);

  /// Set next Task pointer.
  void next (ACE_Task<ACE_SYNCH_USE> *);

  /// Return the Task's sibling if there's one associated with the
  /// Task's Module, else returns 0.
  ACE_Task<ACE_SYNCH_USE> *sibling (void);

  /// Return the Task's Module if there is one, else returns 0.
  ACE_Module<ACE_SYNCH_USE> *module (void) const;

  /**
   * Flush the task's queue, i.e., free all of the enqueued
   * message blocks and unblocks any threads waiting on the queue.
   * Note that if this conflicts with the C++ iostream <flush>
   * function, just rewrite the iostream function as ::<flush>.
   */
  int flush (u_long flag = ACE_Task_Flags::ACE_FLUSHALL);

  // = Special routines corresponding to certain message types.

  /// Manipulate watermarks.
  void water_marks (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds, size_t);

  /// Queue of messages on the ACE_Task..
  ACE_Message_Queue<ACE_SYNCH_USE> *msg_queue_;

  /// true if should delete Message_Queue, false otherwise.
  bool delete_msg_queue_;

  /// Back-pointer to the enclosing module.
  ACE_Module<ACE_SYNCH_USE> *mod_;

  /// Pointer to adjacent ACE_Task.
  ACE_Task<ACE_SYNCH_USE> *next_;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;

private:

  // = Disallow these operations.
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Task<ACE_SYNCH_USE> &))
  ACE_UNIMPLEMENTED_FUNC (ACE_Task (const ACE_Task<ACE_SYNCH_USE> &))
};

#if defined ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT
template class ACE_Export ACE_Task<ACE_MT_SYNCH>;
template class ACE_Export ACE_Task<ACE_NULL_SYNCH>;
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION_EXPORT */

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Task_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Task_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Task_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TASK_T_H */
