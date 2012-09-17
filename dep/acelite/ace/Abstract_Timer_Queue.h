//$Id: Abstract_Timer_Queue.h 95368 2011-12-19 13:38:49Z mcorino $

#ifndef ACE_ABSTRACT_TIMER_QUEUE_H
#define ACE_ABSTRACT_TIMER_QUEUE_H

#include /**/ "ace/pre.h"
/**
 * @file Abstract_Timer_Queue.h
 *
 * @author Carlos O'Ryan <coryan@atdesk.com>
 *
 * Based on classes and files developed by Doug Schmidt, Darrell
 * Brunsch, Irfan Pyarali and a cast of thousands.
 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Forward declares
class ACE_Time_Value;
class ACE_Command_Base;
template<typename TYPE> class ACE_Timer_Queue_Iterator_T;
template<typename TYPE> class ACE_Timer_Node_T;

/**
 * @class ACE_Abstract_Timer_Queue
 *
 * @brief Base class for all timer queues of a single type.
 *
 * This is a base class for all the timer queues, regardless of
 * locking strategy, upcall mechanism, internal implementation, etc.
 * The class was motivated by bug 3706:
 *    http://bugzilla.dre.vanderbilt.edu/show_bug.cgi?id=3706
 * In short, the Reactor (and potentially other classes) want to refer
 * to timer queues regardless of the implementation internals.
 */
template<typename TYPE>
class ACE_Abstract_Timer_Queue
{
public:
  /// Destructor
  virtual ~ACE_Abstract_Timer_Queue (void) = 0;

  /// True if queue is empty, else false.
  virtual bool is_empty (void) const = 0;

  /// Returns the time of the earlier node in the Timer_Queue.  Must
  /// be called on a non-empty queue.
  virtual const ACE_Time_Value &earliest_time (void) const = 0;

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
  virtual long schedule (const TYPE &type,
                         const void *act,
                         const ACE_Time_Value &future_time,
                         const ACE_Time_Value &interval = ACE_Time_Value::zero) = 0;

  /**
   * Run the <functor> for all timers whose values are <= @a current_time.
   * This does not account for <timer_skew>.  Returns the number of
   * timers canceled.
   */
  virtual int expire (const ACE_Time_Value &current_time) = 0;

  /**
   * Run the <functor> for all timers whose values are <=
   * <ACE_OS::gettimeofday>.  Also accounts for <timer_skew>.
   *
   * Depending on the resolution of the underlying OS the system calls
   * like select()/poll() might return at time different than that is
   * specified in the timeout. Suppose the OS guarantees a resolution of t ms.
   * The timeline will look like
   *
   *             A                   B
   *             |                   |
   *             V                   V
   *  |-------------|-------------|-------------|-------------|
   *  t             t             t             t             t
   *
   *
   * If you specify a timeout value of A, then the timeout will not occur
   * at A but at the next interval of the timer, which is later than
   * that is expected. Similarly, if your timeout value is equal to B,
   * then the timeout will occur at interval after B. Now depending upon the
   * resolution of your timeouts and the accuracy of the timeouts
   * needed for your application, you should set the value of
   * <timer_skew>. In the above case, if you want the timeout A to fire
   * no later than A, then you should specify your <timer_skew> to be
   * A % t.
   *
   * The timeout value should be specified via the macro ACE_TIMER_SKEW
   * in your config.h file. The default value is zero.
   *
   * Things get interesting if the t before the timeout value B is zero
   * i.e your timeout is less than the interval. In that case, you are
   * almost sure of not getting the desired timeout behaviour. Maybe you
   * should look for a better OS :-)
   *
   *  Returns the number of timers canceled.
   */
  virtual int expire (void) = 0;

  /**
   * A couple of classes using Timer_Queues need to dispatch a single
   * event at a time.  But before they dispatch the event they need to
   * release a lock, signal other threads, etc.
   *
   * This member function should be used in that case.  The additional
   * operations to be called just before dispatching the event, and
   * only if an event will be dispatched, are encapsulated in the
   * ACE_Command_Base object.
   */
  virtual int expire_single(ACE_Command_Base & pre_dispatch_command) = 0;

  /**
   * Resets the interval of the timer represented by @a timer_id to
   * @a interval, which is specified in relative time to the current
   * <gettimeofday>.  If @a interval is equal to
   * ACE_Time_Value::zero, the timer will become a non-rescheduling
   * timer.  Returns 0 if successful, -1 if not.
   */
  virtual int reset_interval (long timer_id,
                              const ACE_Time_Value &interval) = 0;

  /**
   * Cancel all timer associated with @a type.  If
   * @a dont_call_handle_close is 0 then the <functor> will be invoked,
   * which typically invokes the <handle_close> hook.  Returns number
   * of timers cancelled.
   */
  virtual int cancel (const TYPE &type,
                      int dont_call_handle_close = 1) = 0;

  /**
   * Cancel the single timer that matches the @a timer_id value (which
   * was returned from the <schedule> method).  If act is non-NULL
   * then it will be set to point to the ``magic cookie'' argument
   * passed in when the timer was registered.  This makes it possible
   * to free up the memory and avoid memory leaks.  If
   * @a dont_call_handle_close is 0 then the <functor> will be invoked,
   * which typically calls the <handle_close> hook.  Returns 1 if
   * cancellation succeeded and 0 if the @a timer_id wasn't found.
   */
  virtual int cancel (long timer_id,
                      const void **act = 0,
                      int dont_call_handle_close = 1) = 0;

  /**
   * Close timer queue. Cancels all timers.
   */
  virtual int close (void) = 0;

  /**
   * Returns the current time of day.  This method allows different
   * implementations of the timer queue to use special high resolution
   * timers.
   */
  virtual ACE_Time_Value gettimeofday (void) = 0;

  /**
   * Allows applications to control how the timer queue gets the time
   * of day.
   * @deprecated Use TIME_POLICY support instead. See Timer_Queue_T.h
   */
  virtual void gettimeofday (ACE_Time_Value (*gettimeofday)(void)) = 0;

  /// Determine the next event to timeout.  Returns @a max if there are
  /// no pending timers or if all pending timers are longer than max.
  /// This method acquires a lock internally since it modifies internal state.
  virtual ACE_Time_Value *calculate_timeout (ACE_Time_Value *max) = 0;

  /**
   * Determine the next event to timeout.  Returns @a max if there are
   * no pending timers or if all pending timers are longer than max.
   * <the_timeout> should be a pointer to storage for the timeout value,
   * and this value is also returned.  This method does not acquire a
   * lock internally since it doesn't modify internal state.  If you
   * need to call this method when the queue is being modified
   * concurrently, however, you should make sure to acquire the <mutex()>
   * externally before making the call.
   */
  virtual ACE_Time_Value *calculate_timeout (ACE_Time_Value *max,
                                             ACE_Time_Value *the_timeout) = 0;

  /**
   * Return the current time, using the right time policy and any
   * timer skew defined in derived classes.
   */
  virtual ACE_Time_Value current_time() = 0;

  /// Type of Iterator.
  typedef ACE_Timer_Queue_Iterator_T<TYPE> ITERATOR;

  /// Returns a pointer to this ACE_Timer_Queue's iterator.
  virtual ITERATOR & iter (void) = 0;

  /// Removes the earliest node from the queue and returns it
  virtual ACE_Timer_Node_T<TYPE> *remove_first (void) = 0;

  /// Reads the earliest node from the queue and returns it.
  virtual ACE_Timer_Node_T<TYPE> *get_first (void) = 0;

  /// Dump the state of a object.
  virtual void dump (void) const = 0;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Abstract_Timer_Queue.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Abstract_Timer_Queue.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_ABSTRACT_TIMER_QUEUE_H */
