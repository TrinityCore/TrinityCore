//$Id: Timer_Queue_Iterator.h 96333 2012-11-23 08:08:31Z johnnyw $

#ifndef ACE_TIMER_QUEUE_ITERATOR_H
#define ACE_TIMER_QUEUE_ITERATOR_H

#include /**/ "ace/pre.h"

/**
 * @file Timer_Queue_Iterator.h
 *
 * Re-factored from Timer_Queue_T.h
 */

#include "ace/Time_Value.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Timer_Node_Dispatch_Info_T
 *
 * @brief Maintains generated dispatch information for Timer nodes.
 *
 */
template <class TYPE>
class ACE_Timer_Node_Dispatch_Info_T
{
public:
  /// The type of object held in the queue
  TYPE type_;

  /// Asynchronous completion token associated with the timer.
  const void *act_;

  /// Flag to check if the timer is recurring.
  int recurring_timer_;
};

/**
 * @class ACE_Timer_Node_T
 *
 * @brief Maintains the state associated with a Timer entry.
 */
template <class TYPE>
class ACE_Timer_Node_T
{
public:
  /// Default constructor
  ACE_Timer_Node_T (void);

  /// Destructor
  ~ACE_Timer_Node_T (void);

  /// Useful typedef ..
  typedef ACE_Timer_Node_Dispatch_Info_T <TYPE> DISPATCH_INFO;

  /// Singly linked list
  void set (const TYPE &type,
            const void *a,
            const ACE_Time_Value &t,
            const ACE_Time_Value &i,
            ACE_Timer_Node_T<TYPE> *n,
            long timer_id);

  /// Doubly linked list version
  void set (const TYPE &type,
            const void *a,
            const ACE_Time_Value &t,
            const ACE_Time_Value &i,
            ACE_Timer_Node_T<TYPE> *p,
            ACE_Timer_Node_T<TYPE> *n,
            long timer_id);

  // = Accessors

  /// Get the type.
  TYPE &get_type (void);

  /// Set the type.
  void set_type (TYPE &type);

  /// Get the asynchronous completion token.
  const void *get_act (void);

  /// Set the asynchronous completion token.
  void set_act (void *act);

  /// Get the timer value.
  const ACE_Time_Value &get_timer_value (void) const;

  /// Set the timer value.
  void set_timer_value (const ACE_Time_Value &timer_value);

  /// Get the timer interval.
  const ACE_Time_Value &get_interval (void) const;

  /// Set the timer interval.
  void set_interval (const ACE_Time_Value &interval);

  /// Get the previous pointer.
  ACE_Timer_Node_T<TYPE> *get_prev (void);

  /// Set the previous pointer.
  void set_prev (ACE_Timer_Node_T<TYPE> *prev);

  /// Get the next pointer.
  ACE_Timer_Node_T<TYPE> *get_next (void);

  /// Set the next pointer.
  void set_next (ACE_Timer_Node_T<TYPE> *next);

  /// Get the timer_id.
  long get_timer_id (void) const;

  /// Set the timer_id.
  void set_timer_id (long timer_id);

  /// Get the dispatch info. The dispatch information is got
  /// through @a info. This form helps us in preventing allocation and
  /// deleting data along the criticl path.
  /// @todo We may want to have a copying version too, so that our
  /// interface will be complete..
  void get_dispatch_info (ACE_Timer_Node_Dispatch_Info_T <TYPE> &info);

  /// Dump the state of an TYPE.
  void dump (void) const;

private:
  /// Type of object stored in the Queue
  TYPE type_;

  /// Asynchronous completion token associated with the timer.
  const void *act_;

  /// Time until the timer expires.
  ACE_Time_Value timer_value_;

  /// If this is a periodic timer this holds the time until the next
  /// timeout.
  ACE_Time_Value interval_;

  /// Pointer to previous timer.
  ACE_Timer_Node_T<TYPE> *prev_;

  /// Pointer to next timer.
  ACE_Timer_Node_T<TYPE> *next_;

  /// Id of this timer (used to cancel timers before they expire).
  long timer_id_;
};

/**
 * @class ACE_Timer_Queue_Iterator_T
 *
 * @brief Generic interface for iterating over a subclass of
 * ACE_Timer_Queue.
 *
 * This is a generic iterator that can be used to visit every
 * node of a timer queue.  Be aware that it isn't guaranteed
 * that the transversal will be in order of timeout values.
 */
template <class TYPE>
class ACE_Timer_Queue_Iterator_T
{
public:
  // = Initialization and termination methods.
  /// Constructor.
  ACE_Timer_Queue_Iterator_T (void);

  /// Destructor.
  virtual ~ACE_Timer_Queue_Iterator_T (void);

  /// Positions the iterator at the earliest node in the Timer Queue
  virtual void first (void) = 0;

  /// Positions the iterator at the next node in the Timer Queue
  virtual void next (void) = 0;

  /// Returns true when there are no more nodes in the sequence
  virtual bool isdone (void) const = 0;

  /// Returns the node at the current position in the sequence
  virtual ACE_Timer_Node_T<TYPE> *item (void) = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Timer_Queue_Iterator.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timer_Queue_Iterator.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_Queue_Iterator.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_QUEUE_ITERATOR_H */
