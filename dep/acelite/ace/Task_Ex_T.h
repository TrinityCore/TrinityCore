// -*- C++ -*-

//=============================================================================
/**
 *  @file    Task_Ex_T.h
 *
 *  $Id: Task_Ex_T.h 96061 2012-08-16 09:36:07Z mcorino $
 *
 *  @author Kobi Cohen-Arazi <kobi-co@barak-online.net>
 */
//=============================================================================

#ifndef ACE_TASK_EX_T_H
#define ACE_TASK_EX_T_H
#include /**/ "ace/pre.h"

#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Synch_Traits.h"
#include "ace/Task.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward decls...
template <ACE_SYNCH_DECL, class TIME_POLICY> class ACE_Module;

/**
 * @class ACE_Task_Ex
 *
 * @brief Primary interface for application message processing, as well
 * as input and output message queueing.
 *
 * Unlike ACE_Task, these class doesn't have the ability to be a part of
 * a Stream chain. I.e. You cannot (yet) chain modules based on ACE_Task_Ex.
 *
 * @todo: We can merge ACE_Task and ACE_Task_Ex to be one class.
 * something like that:
 * template <ACE_SYNCH_DECL, ACE_MESSAGE_TYPE = ACE_Message_Block>
 * class ACE_Task : public ACE_Task_Base
 * {
 *  // use here the code from ACE_Task_Ex using ACE_Message_Queue_Ex
 * };
 *
 * Now specialized version of ACE_Task with ACE_Message_Block as its
 * ACE_MESSAGE_TYPE...
 *
 * template <ACE_SYNCH_DECL>
 * class ACE_Task <ACE_SYNCH_USE, ACE_Message_Block> : public ACE_Task_Base
 * {
 *   // put here the good old ACE_Task code
 * };
 *
 * When User (and legacy code) write ACE_Task<ACE_MT_SYNCH>, specialized ACE_Task
 * code is in action.
 */
template <ACE_SYNCH_DECL, class ACE_MESSAGE_TYPE, class TIME_POLICY = ACE_System_Time_Policy>
class ACE_Task_Ex : public ACE_Task_Base,
                    private ACE_Copy_Disabled
{
public:
  friend class ACE_Module<ACE_SYNCH_USE, TIME_POLICY>;
  friend class ACE_Module_Type;
  typedef ACE_Message_Queue_Ex<ACE_MESSAGE_TYPE, ACE_SYNCH_USE, TIME_POLICY> MESSAGE_QUEUE_EX;

  // = Initialization/termination methods.
  /**
   * Initialize a Task, supplying a thread manager and a message
   * queue.  If the user doesn't supply a ACE_Message_Queue pointer
   * then we'll allocate one dynamically.  Otherwise, we'll use the
   * one passed as a parameter.
   */
  ACE_Task_Ex (ACE_Thread_Manager *thr_mgr = 0,
            MESSAGE_QUEUE_EX *mq = 0);

  /// Destructor.
  virtual ~ACE_Task_Ex (void);

  /// Gets the message queue associated with this task.
  MESSAGE_QUEUE_EX *msg_queue (void);

  /// Sets the message queue associated with this task.
  void msg_queue (MESSAGE_QUEUE_EX *);

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
  int putq (ACE_MESSAGE_TYPE *, ACE_Time_Value *timeout = 0);

  /**
   * Extract the first message from the queue (blocking).  Note that
   * @a timeout uses <{absolute}> time rather than <{relative}> time.
   * Returns number of items in queue if the call succeeds or -1 otherwise.
   */
  int getq (ACE_MESSAGE_TYPE *&mb, ACE_Time_Value *timeout = 0);

  /// Return a message to the queue.  Note that @a timeout uses
  /// <{absolute}> time rather than <{relative}> time.
  int ungetq (ACE_MESSAGE_TYPE *, ACE_Time_Value *timeout = 0);

  /**
   * Turn the message around and send it back down the Stream.  Note
   * that @a timeout uses <{absolute}> time rather than <{relative}>
   * time.
   */
  int reply (ACE_MESSAGE_TYPE *, ACE_Time_Value *timeout = 0);

  /**
   * Transfer message to the adjacent ACE_Task_Ex in a ACE_Stream.  Note
   * that @a timeout uses <{absolute}> time rather than <{relative}>
   * time.
   */
  int put_next (ACE_MESSAGE_TYPE *msg, ACE_Time_Value *timeout = 0);

  // = ACE_Task utility routines to identify names et al.
  /// Return the name of the enclosing Module if there's one associated
  /// with the Task, else returns 0.
  const ACE_TCHAR *name (void) const;

  // = Pointers to next ACE_Task_Base (if ACE is part of an ACE_Stream).
  /// Get next Task pointer.
  ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *next (void);

  /// Set next Task pointer.
  void next (ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *);

  /// Alwasy return 0. @todo FIXME
  ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *sibling (void);

  /// Return the Task's Module if there is one, else returns 0.
  ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *module (void) const;

  /**
   * Flush the task's queue, i.e., free all of the enqueued
   * message blocks and releases any threads blocked on the queue.
   * Note that if this conflicts with the C++ iostream <flush>
   * function, just rewrite the iostream function as ::<flush>.
   */
  int flush (u_long flag = ACE_Task_Flags::ACE_FLUSHALL);

  // = Special routines corresponding to certain message types.

  /// Manipulate watermarks.
  void water_marks (ACE_IO_Cntl_Msg::ACE_IO_Cntl_Cmds, size_t);

  /// Queue of messages on the ACE_Task..
  MESSAGE_QUEUE_EX *msg_queue_;

  /// true if should delete Message_Queue, false otherwise.
  bool delete_msg_queue_;

  /// Back-pointer to the enclosing module.
  ACE_Module<ACE_SYNCH_USE, TIME_POLICY> *mod_;

  /// Pointer to adjacent ACE_Task.
  ACE_Task<ACE_SYNCH_USE, TIME_POLICY> *next_;

  /// Dump the state of an object.
  void dump (void) const;

  /// Declare the dynamic allocation hooks.
  ACE_ALLOC_HOOK_DECLARE;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Task_Ex_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Task_Ex_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Task_Ex_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TASK_EX_H */
