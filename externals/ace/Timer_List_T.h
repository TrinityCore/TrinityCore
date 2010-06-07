/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    Timer_List_T.h
 *
 *  $Id: Timer_List_T.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TIMER_LIST_T_H
#define ACE_TIMER_LIST_T_H
#include /**/ "ace/pre.h"

#include "ace/Timer_Queue_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Forward declaration.
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_List_T;

/**
 * @class ACE_Timer_List_Iterator_T
 *
 * @brief Iterates over an ACE_Timer_List.
 *
 * This is a generic iterator that can be used to visit every
 * node of a timer queue.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_List_Iterator_T
: public ACE_Timer_Queue_Iterator_T <TYPE, FUNCTOR, ACE_LOCK>
{
public:
  typedef ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK> List;
  /// Constructor.
  ACE_Timer_List_Iterator_T (List& lst);

  /// Destructor.
  virtual ~ACE_Timer_List_Iterator_T (void);

  /// Positions the iterator at the earliest node in the Timer Queue
  virtual void first (void);

  /// Positions the iterator at the next node in the Timer Queue
  virtual void next (void);

  /// Returns true when there are no more nodes in the sequence
  virtual bool isdone (void) const;

  /// Returns the node at the current position in the sequence
  virtual ACE_Timer_Node_T<TYPE> *item (void);

protected:
  /// Pointer to the ACE_Timer_List that we are iterating over.
  List& list_;

  /// Current position in the ACE_Timer_List
  ACE_Timer_Node_T<TYPE>* current_node_;
};

/**
 * @class ACE_Timer_List_T
 *
 * @brief Provides a simple implementation of timers.
 *
 * This implementation uses a linked list of absolute times.
 * Therefore, in the average case, scheduling and canceling
 * timers is O(N) (where N is the total number of timers) and
 * expiring timers is O(K) (where K is the total number of timers
 * that are < the current time of day).
 * More clever implementations could use a delta-list, a heap,
 * or timing wheels, etc.  For instance, ACE_Timer_Heap
 * is a subclass of ACE_Timer_List that implements a
 * heap-based callout queue.  For most applications, the
 * ACE_Timer_Heap will perform substantially faster than the
 * ACE_Timer_List.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK>
class ACE_Timer_List_T : public ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK>
{
public:
  /// Type of iterator
  typedef ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> Iterator;

  /// Iterator is a friend
  friend class ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>;

  typedef ACE_Timer_Node_T<TYPE> Node;
  /// Type inherited from
  typedef ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK> Base;
  typedef ACE_Free_List<Node> FreeList;

  // = Initialization and termination methods.
  /**
   * Default constructor. @a upcall_functor is the instance of the
   * FUNCTOR to be used by the list. If @a upcall_functor is 0, a
   * default FUNCTOR will be created.  @a freelist is the freelist of
   * timer nodes.  If 0, then a default freelist will be created.
   */
  ACE_Timer_List_T (FUNCTOR* upcall_functor = 0, FreeList* freelist = 0);

  /// Destructor
  virtual ~ACE_Timer_List_T (void);

  /// True if queue is empty, else false.
  virtual bool is_empty (void) const;

  /// Returns the time of the earlier node in the ACE_Timer_List.
  /// Must be called on a non-empty queue.
  virtual const ACE_Time_Value& earliest_time (void) const;

  /**
   * Resets the interval of the timer represented by @a timer_id to
   * @a interval, which is specified in relative time to the current
   * <gettimeofday>.  If @a interval is equal to
   * ACE_Time_Value::zero, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   */
  virtual int reset_interval (long timer_id,
                              const ACE_Time_Value& interval);

  /**
   * Cancel all timers associated with @a type.  If dont_call_handle_close is 0
   * then the @a functor will be invoked.  Returns the number of timers
   * cancelled.
   */
  virtual int cancel (const TYPE& type,
                      int dont_call_handle_close = 1);

  /**
   * Cancel the single timer that matches the @a timer_id value (which
   * was returned from the <schedule> method).  If act is non-NULL
   * then it will be set to point to the ``magic cookie'' argument
   * passed in when the timer was registered.  This makes it possible
   * to free up the memory and avoid memory leaks.  If <dont_call> is
   * 0 then the <functor> will be invoked.  Returns 1 if cancellation
   * succeeded and 0 if the @a timer_id wasn't found.
   */
  virtual int cancel (long timer_id,
                      const void** act = 0,
                      int dont_call_handle_close = 1);

  /// Returns a pointer to this ACE_Timer_Queue's iterator.
  virtual ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>& iter (void);

  /// Removes the earliest node from the queue and returns it
  virtual ACE_Timer_Node_T<TYPE>* remove_first (void);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Reschedule an "interval" ACE_Timer_Node_T.  This should be private
  /// but for now it needs to be public for <ACE_Timer_Hash_T>
  virtual void reschedule (ACE_Timer_Node_T<TYPE> *);

  /// Reads the earliest node from the queue and returns it.
  virtual ACE_Timer_Node_T<TYPE>* get_first (void);

private:

  /**
   * Schedule @a type that will expire at @a future_time, which is
   * specified in absolute time.  If it expires then @a act is passed
   * in as the value to the <functor>.  If @a interval is != to
   * ACE_Time_Value::zero then it is used to reschedule the @a type
   * automatically, using relative time to the current <gettimeofday>.
   * This method returns a <timer_id> that uniquely identifies the the
   * @a type entry in an internal list.  This <timer_id> can be used to
   * cancel the timer before it expires.  The cancellation ensures
   * that <timer_ids> are unique up to values of greater than 2
   * billion timers.  As long as timers don't stay around longer than
   * this there should be no problems with accidentally deleting the
   * wrong timer.  Returns -1 on failure (which is guaranteed never to
   * be a valid <timer_id>).
   */
  virtual long schedule_i (const TYPE& type,
                           const void* act,
                           const ACE_Time_Value& future_time,
                           const ACE_Time_Value& interval);

  void schedule_i(ACE_Timer_Node_T<TYPE>* n, const ACE_Time_Value& exp);

  ACE_Timer_Node_T<TYPE>* find_node(long timer_id) const;

  void cancel_i (ACE_Timer_Node_T<TYPE>* n);

  void unlink (ACE_Timer_Node_T<TYPE>* n);

  ACE_Timer_Node_T<TYPE>* get_first_i(void) const;

private:

  /// Pointer to linked list of <ACE_Timer_Handles>.
  ACE_Timer_Node_T<TYPE>* head_;

  /// Iterator used to expire timers.
  Iterator* iterator_;

  /**
   * Keeps track of the timer id that uniquely identifies each timer.
   * This id can be used to cancel a timer via the <cancel(long)>
   * method.
   */
  long id_counter_;

  // = Don't allow these operations for now.
  ACE_UNIMPLEMENTED_FUNC (ACE_Timer_List_T (const ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK> &))
  ACE_UNIMPLEMENTED_FUNC (void operator= (const ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK> &))
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timer_List_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_List_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_LIST_T_H */
