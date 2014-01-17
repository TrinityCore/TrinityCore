// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timer_Wheel_T.h
 *
 *  $Id: Timer_Wheel_T.h 95368 2011-12-19 13:38:49Z mcorino $
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TIMER_WHEEL_T_H
#define ACE_TIMER_WHEEL_T_H
#include /**/ "ace/pre.h"

#include "ace/Timer_Queue_T.h"
#include "ace/Copy_Disabled.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declaration
template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY>
class ACE_Timer_Wheel_T;

/**
 * @class ACE_Timer_Wheel_Iterator_T
 *
 * @brief Iterates over an ACE_Timer_Wheel.
 *
 * This is a generic iterator that can be used to visit every
 * node of a timer queue.  Be aware that it doesn't traverse
 * in the order of timeout values.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY = ACE_Default_Time_Policy>
class ACE_Timer_Wheel_Iterator_T
  : public ACE_Timer_Queue_Iterator_T <TYPE>
{
public:
  typedef ACE_Timer_Wheel_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY> Wheel;
  typedef ACE_Timer_Node_T<TYPE> Node;

  /// Constructor
  ACE_Timer_Wheel_Iterator_T (Wheel &);

  /// Destructor
  virtual ~ACE_Timer_Wheel_Iterator_T (void);

  /// Positions the iterator at the earliest node in the Timer Queue
  virtual void first (void);

  /// Positions the iterator at the next node in the Timer Queue
  virtual void next (void);

  /// Returns true when there are no more nodes in the sequence
  virtual bool isdone (void) const;

  /// Returns the node at the current position in the sequence
  virtual ACE_Timer_Node_T<TYPE>* item (void);

protected:
  /// Pointer to the ACE_Timer_List that we are iterating over.
  Wheel& timer_wheel_;

  /// Current position in the timing wheel
  u_int spoke_;

  /// Pointer to the position in the the <pos_>th list
  ACE_Timer_Node_T<TYPE>* current_node_;
private:
  void goto_next(u_int start_spoke);
};

/**
 * @class ACE_Timer_Wheel_T
 *
 * @brief Provides a Timing Wheel version of ACE_Timer_Queue.
 *
 * This implementation uses a hash table of ordered doubly-
 * linked lists of absolute times.  The enhancements over the
 * @c ACE_Timer_List include adding a free list and the ability
 * to preallocate nodes.  Timer Wheel is based on the timing
 * wheel implementation used in Adam M. Costello and
 * George Varghese's paper "Redesigning the BSD Callout and
 * Timer Facilities"
 * (http://dworkin.wustl.edu/~varghese/PAPERS/newbsd.ps.Z)
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY = ACE_Default_Time_Policy>
class ACE_Timer_Wheel_T
  : public ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>
{
public:
  /// Type of iterator
  typedef ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY> Iterator;
  /// Iterator is a friend
  friend class ACE_Timer_Wheel_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY>;
  typedef ACE_Timer_Node_T<TYPE> Node;
  /// Type inherited from
  typedef ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK, TIME_POLICY> Base_Timer_Queue;
  typedef ACE_Free_List<Node> FreeList;

  /// Default constructor
  ACE_Timer_Wheel_T (FUNCTOR* upcall_functor = 0, FreeList* freelist = 0,
                     TIME_POLICY const & time_policy = TIME_POLICY());

  /// Constructor with opportunities to set the wheelsize and resolution
  ACE_Timer_Wheel_T (u_int spoke_count,
                     u_int resolution,
                     size_t prealloc = 0,
                     FUNCTOR* upcall_functor = 0,
                     FreeList* freelist = 0,
                     TIME_POLICY const & time_policy = TIME_POLICY());

  /// Destructor
  virtual ~ACE_Timer_Wheel_T (void);

  /// True if queue is empty, else false.
  virtual bool is_empty (void) const;

  /// Returns the time of the earlier node in the ACE_Timer_Wheel.
  /// Must be called on a non-empty queue.
  virtual const ACE_Time_Value& earliest_time (void) const;

  /// Changes the interval of a timer (and can make it periodic or non
  /// periodic by setting it to ACE_Time_Value::zero or not).
  virtual int reset_interval (long timer_id,
                              const ACE_Time_Value& interval);

  /// Cancel all timer associated with @a type.  If @a dont_call_handle_close is
  /// 0 then the <functor> will be invoked.  Returns number of timers
  /// cancelled.
  virtual int cancel (const TYPE& type,
                      int dont_call_handle_close = 1);

  // Cancel a timer, storing the magic cookie in act (if nonzero).
  // Calls the functor if dont_call_handle_close is 0 and returns 1
  // on success
  virtual int cancel (long timer_id,
                      const void** act = 0,
                      int dont_call_handle_close = 1);

  /**
   * Destroy timer queue. Cancels all timers.
   */
  virtual int close (void);

  /// Run the <functor> for all timers whose values are <=
  /// <ACE_OS::gettimeofday>.  Also accounts for <timer_skew>.  Returns
  /// the number of timers canceled.
  virtual int expire (void);

  // Run the <functor> for all timers whose values are <= @a current_time.
  // This does not account for <timer_skew>.  Returns the number of
  // timers canceled.
  int expire (const ACE_Time_Value& current_time);

  /// Returns a pointer to this <ACE_Timer_Queue_T>'s iterator.
  virtual ACE_Timer_Queue_Iterator_T<TYPE> & iter (void);

  /// Removes the earliest node from the queue and returns it
  virtual ACE_Timer_Node_T<TYPE>* remove_first (void);

  /// Dump the state of an object.
  virtual void dump (void) const;

  /// Reads the earliest node from the queue and returns it.
  virtual ACE_Timer_Node_T<TYPE>* get_first (void);

protected:

  /// Schedules a timer.
  virtual long schedule_i (const TYPE& type,
                           const void* act,
                           const ACE_Time_Value& future_time,
                           const ACE_Time_Value& interval);

private:
  // The following are documented in the .cpp file.
  ACE_Timer_Node_T<TYPE>* get_first_i (void) const;
  ACE_Timer_Node_T<TYPE>* remove_first_expired (const ACE_Time_Value& now);
  void open_i (size_t prealloc, u_int spokes, u_int res);
  virtual void reschedule (ACE_Timer_Node_T<TYPE> *);
  ACE_Timer_Node_T<TYPE>* find_spoke_node(u_int spoke, long timer_id) const;
  ACE_Timer_Node_T<TYPE>* find_node(long timer_id) const;
  u_int calculate_spoke(const ACE_Time_Value& expire) const;
  long generate_timer_id(u_int spoke);
  void schedule_i (ACE_Timer_Node_T<TYPE>* n, u_int spoke, const ACE_Time_Value& expire);
  void cancel_i (ACE_Timer_Node_T<TYPE>* n);
  void unlink (ACE_Timer_Node_T<TYPE>* n);
  void recalc_earliest(const ACE_Time_Value& last);

private:
  int power2bits (int n, int min_bits, int max_bits);

  /// Timing Wheel.
  ACE_Timer_Node_T<TYPE>** spokes_;
  /// Size of the timing wheel.
  u_int spoke_count_;
  /// Number of timer_id bits used for the spoke
  int spoke_bits_;
  /// Maximum number of timers per spoke
  u_int max_per_spoke_;
  /// Resolution (in microsoconds) of the timing wheel.
  int res_bits_;
  /// Index of the list with the earliest time
  u_int earliest_spoke_;
  /// Iterator used to expire timers.
  Iterator* iterator_;
  /// The total amount of time in one iteration of the wheel. (resolution * spoke_count)
  ACE_Time_Value wheel_time_;
  /// The total number of timers currently scheduled.
  u_int timer_count_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timer_Wheel_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_Wheel_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_WHEEL_T_H */
