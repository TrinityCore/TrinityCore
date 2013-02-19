// -*- C++ -*-

//=============================================================================
/**
 *  @file    Timer_Queue_T.h
 *
 *  $Id: Timer_Queue_T.h 95362 2011-12-18 11:56:24Z johnnyw $
 *
 *  @author Doug Schmidt <schmidt@cs.wustl.edu>
 *  @author Irfan Pyarali <irfan@cs.wustl.edu> and
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_TIMER_QUEUE_T_H
#define ACE_TIMER_QUEUE_T_H
#include /**/ "ace/pre.h"

#include "ace/Free_List.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Time_Value.h"
#include "ace/Abstract_Timer_Queue.h"
#include "ace/Timer_Queue_Iterator.h"
#include "ace/Time_Policy.h"
#include "ace/Copy_Disabled.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class ACE_Timer_Queue_Upcall_Base
 *
 * Common base class for all timer queues with the same time source
 * policy.  This is really motivated by a single use-case in the code,
 * namely the ACE_Proactor needs to set a backpointer in the upcall
 * functor.
 */
template<typename TYPE, typename FUNCTOR>
class ACE_Timer_Queue_Upcall_Base
  : public ACE_Abstract_Timer_Queue<TYPE>
  , private ACE_Copy_Disabled
{
public:
  // Constructor
  explicit ACE_Timer_Queue_Upcall_Base(FUNCTOR * upcall_functor = 0);

  /// Destructor
  virtual ~ACE_Timer_Queue_Upcall_Base (void);

  /// Accessor to the upcall functor
  FUNCTOR & upcall_functor (void);

protected:
  /// Upcall functor
  FUNCTOR *upcall_functor_;

  /// To delete or not to delete is the question?
  bool const delete_upcall_functor_;
};

/**
 * @class ACE_Timer_Queue_T
 *
 * @brief Provides an interface to timers.
 *
 * This is an abstract base class that provides hook for
 * implementing specialized policies such as ACE_Timer_List
 * and ACE_Timer_Heap.
 */
template <class TYPE, class FUNCTOR, class ACE_LOCK, typename TIME_POLICY = ACE_Default_Time_Policy>
class ACE_Timer_Queue_T
  : public ACE_Timer_Queue_Upcall_Base<TYPE,FUNCTOR>
{
public:
  // = Initialization and termination methods.
  /**
   * Default constructor. @a upcall_functor is the instance of the
   * FUNCTOR to be used by the queue. If @a upcall_functor is 0, Timer
   * Queue will create a default FUNCTOR.  @a freelist the freelist of
   * timer nodes.  If 0, then a default freelist will be created.
   */
  ACE_Timer_Queue_T (FUNCTOR *upcall_functor = 0,
                    ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist = 0,
                    TIME_POLICY const & time_policy = TIME_POLICY());

  /// Destructor - make virtual for proper destruction of inherited
  /// classes.
  virtual ~ACE_Timer_Queue_T (void);

  /**
   * Implement ACE_Abstract_Timer_Queue<TYPE>::schedule () with the right
   * locking strategy.
   */
  virtual long schedule (const TYPE &type,
                         const void *act,
                         const ACE_Time_Value &future_time,
                         const ACE_Time_Value &interval = ACE_Time_Value::zero);

  //@{
  /**
   * Implement ACE_Abstract_Timer_Queue<TYPE>::expire () with the right
   * locking strategy.
   */
  virtual int expire (const ACE_Time_Value &current_time);
  virtual int expire (void);
  virtual int expire_single(ACE_Command_Base & pre_dispatch_command);
  //@}

  /**
   * Get the dispatch information for a timer whose value is <= @a current_time.
   * This does not account for <timer_skew>. Returns 1 if
   * there is a node whose value <= @a current_time else returns a 0.
   *
   */
  virtual int dispatch_info (const ACE_Time_Value &current_time,
                             ACE_Timer_Node_Dispatch_Info_T<TYPE> &info);



  //@{
  /**
   * Implement the gettimeofday() virtual function
   */
  virtual ACE_Time_Value gettimeofday (void);
  //@}

  /**
   * Allows applications to control how the timer queue gets the time
   * of day.
   * @deprecated Use TIME_POLICY support instead.
   *             This will only have effect when the TIME_POLICY used
   *             is ACE_FPointer_Time_Policy. Other standard ACE time
   *             policies will ignore this.
   */
  virtual void gettimeofday (ACE_Time_Value (*gettimeofday)(void));

  /// Implement an inlined, non-abstract version of gettimeofday(),
  /// through this  member function the internals of the class can
  /// make calls to  ACE_OS::gettimeofday() with zero overhead.
  ACE_Time_Value gettimeofday_static();

  /// Allows applications to control how the timer queue gets the time
  /// of day.
  void set_time_policy(TIME_POLICY const & time_policy);

  /// Determine the next event to timeout.  Returns @a max if there are
  /// no pending timers or if all pending timers are longer than max.
  /// This method acquires a lock internally since it modifies internal state.
  //@{
  /**
   * Implement calculate_timeout() using the right locking policy
   */
  virtual ACE_Time_Value *calculate_timeout (ACE_Time_Value *max);
  virtual ACE_Time_Value *calculate_timeout (ACE_Time_Value *max,
                                             ACE_Time_Value *the_timeout);
  virtual ACE_Time_Value current_time();
  //@}

  /// Set the timer skew for the Timer_Queue.
  void timer_skew (const ACE_Time_Value &skew);

  /// Get the timer skew for the Timer_Queue.
  const ACE_Time_Value &timer_skew (void) const;

  /// Synchronization variable used by the queue
  ACE_LOCK &mutex (void);

  /// Dump the state of a object.
  virtual void dump (void) const;

  /// Method used to return a timer node to the queue's ownership
  /// after it is returned by a method like <remove_first>.
  virtual void return_node (ACE_Timer_Node_T<TYPE> *);

  /// This method will call the preinvoke() on <functor>.
  void preinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                  const ACE_Time_Value &cur_time,
                  const void *&upcall_act);

  /// This method will call the timeout() on <functor>.
  void upcall (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
               const ACE_Time_Value &cur_time);

  /// This method will call the postinvoke() on <functor>.
  void postinvoke (ACE_Timer_Node_Dispatch_Info_T<TYPE> &info,
                   const ACE_Time_Value &cur_time,
                   const void *upcall_act);

protected:

  /// Schedule a timer.
  virtual long schedule_i (const TYPE &type,
                           const void *act,
                           const ACE_Time_Value &future_time,
                           const ACE_Time_Value &interval) = 0;

  /// Reschedule an "interval" ACE_Timer_Node.
  virtual void reschedule (ACE_Timer_Node_T<TYPE> *) = 0;

  /// Factory method that allocates a new node.
  virtual ACE_Timer_Node_T<TYPE> *alloc_node (void);

  /// Factory method that frees a previously allocated node.
  virtual void free_node (ACE_Timer_Node_T<TYPE> *);

  /// Non-locking version of dispatch_info ()
  virtual int dispatch_info_i (const ACE_Time_Value &current_time,
                               ACE_Timer_Node_Dispatch_Info_T<TYPE> &info);

  /// Recompute when the next time is that this interval timer should fire.
  void recompute_next_abs_interval_time (ACE_Timer_Node_T<TYPE>* expired,
                                         const ACE_Time_Value &cur_time);

  /// Synchronization variable for ACE_Timer_Queue.
  /// @note The right name would be lock_, but HP/C++ will choke on that!
  ACE_LOCK mutex_;

  /// Class that implements a free list
  ACE_Free_List<ACE_Timer_Node_T<TYPE> > *free_list_;

  /// The policy to return the current time of day
  TIME_POLICY time_policy_;

  /// Flag to delete only if the class created the <free_list_>
  bool const delete_free_list_;

private:

  /// Returned by <calculate_timeout>.
  ACE_Time_Value timeout_;

  /// Adjusts for timer skew in various clocks.
  ACE_Time_Value timer_skew_;
};

ACE_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "ace/Timer_Queue_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "ace/Timer_Queue_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("Timer_Queue_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"
#endif /* ACE_TIMER_QUEUE_T_H */
