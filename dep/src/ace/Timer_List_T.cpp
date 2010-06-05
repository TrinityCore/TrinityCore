// $Id: Timer_List_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_TIMER_LIST_T_C
#define ACE_TIMER_LIST_T_C

#include "ace/Timer_List_T.h"
#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

ACE_RCSID(ace, Timer_List_T, "$Id: Timer_List_T.cpp 80826 2008-03-04 14:51:23Z wotte $")

// Default Constructor

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_List_Iterator_T (List& lst)
  : list_ (lst)
{
  this->first();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::~ACE_Timer_List_Iterator_T (void)
{
}

// Positions the iterator at the node right after the dummy node

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::first (void)
{
  this->current_node_ = this->list_.get_first();
}

// Positions the iterator at the next node in the Timer Queue

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::next (void)
{
  // Make sure that if we are at the end, we don't wrap around
  if (! this->isdone())
    this->current_node_ = this->current_node_->get_next ();
  if (this->current_node_  == this->list_.head_)
    this->current_node_ = 0;
}

// Returns true when we are at <head_>

template <class TYPE, class FUNCTOR, class ACE_LOCK> bool
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::isdone (void) const
{
  return this->current_node_ == 0;
}

// Returns the node at <position_> or 0 if we are at the end

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_List_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::item (void)
{
  if (! this->isdone())
    return this->current_node_;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Return our instance of the iterator

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> &
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::iter (void)
{
  this->iterator_->first ();
  return *this->iterator_;
}

// Create an empty list.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_List_T (FUNCTOR* uf, FreeList* fl)
  : Base(uf, fl)
  , head_ (new ACE_Timer_Node_T<TYPE>)
  , id_counter_ (0)
{
  ACE_TRACE ("ACE_Timer_List_T::ACE_Timer_List_T");

  this->head_->set_next (this->head_);
  this->head_->set_prev (this->head_);

  ACE_NEW (iterator_, Iterator(*this));
}


// Checks if list is empty.

template <class TYPE, class FUNCTOR, class ACE_LOCK> bool
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::is_empty (void) const
{
  ACE_TRACE ("ACE_Timer_List_T::is_empty");
  return this->get_first_i() == 0;
}


// Returns earliest time in a non-empty list.

template <class TYPE, class FUNCTOR, class ACE_LOCK> const ACE_Time_Value &
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::earliest_time (void) const
{
  ACE_TRACE ("ACE_Timer_List_T::earliest_time");
  ACE_Timer_Node_T<TYPE>* first = this->get_first_i();
  if (first != 0)
    return first->get_timer_value ();
  return ACE_Time_Value::zero;
}


// Remove all remaining items in the list.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::~ACE_Timer_List_T (void)
{
  ACE_TRACE ("ACE_Timer_List_T::~ACE_Timer_List_T");
  ACE_MT (ACE_GUARD (ACE_LOCK, ace_mon, this->mutex_));

  delete iterator_;

  if (!this->is_empty())
    {
      for (ACE_Timer_Node_T<TYPE>* n = this->get_first();
           n != this->head_;
           )
        {
          this->upcall_functor ().deletion (*this,
                                            n->get_type(),
                                            n->get_act());

          ACE_Timer_Node_T<TYPE> *next =
            n->get_next ();

          this->free_node (n);

          n = next;
        }
    }

  // delete the dummy node
  delete this->head_;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Timer_List_T::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  int count = 0;

  ACE_Timer_Node_T<TYPE>* n = this->get_first_i();
  if (n != 0) {
    for (; n != this->head_; n = n->get_next()) {
      ++count;
    }
  }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nsize_ = %d"), count));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}


// Reschedule a periodic timer.  This function must be called with the
// lock held.

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::reschedule (ACE_Timer_Node_T<TYPE>* n)
{
  ACE_TRACE ("ACE_Timer_List_T::reschedule");
  this->schedule_i(n, n->get_timer_value());
}


// Insert a new handler that expires at time future_time; if interval
// is > 0, the handler will be reinvoked periodically.

template <class TYPE, class FUNCTOR, class ACE_LOCK> long
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::schedule_i (const TYPE &type,
                                                       const void *act,
                                                       const ACE_Time_Value &future_time,
                                                       const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Timer_List_T::schedule_i");

  ACE_Timer_Node_T<TYPE>* n = this->alloc_node();

  if (n != 0)
  {
    long id = this->id_counter_++;

    if (id != -1) {
      n->set (type, act, future_time, interval, 0, 0, id);
      this->schedule_i (n, future_time);
    }
    return id;
  }

  // Failure return
  errno = ENOMEM;
  return -1;
}

/// The shared scheduling functionality between schedule() and reschedule()
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::schedule_i (ACE_Timer_Node_T<TYPE>* n,
                                                       const ACE_Time_Value& expire)
{
  if (this->is_empty()) {
    n->set_prev(this->head_);
    n->set_next(this->head_);
    this->head_->set_prev(n);
    this->head_->set_next(n);
    return;
  }

  // We always want to search backwards from the tail of the list, because
  // this minimizes the search in the extreme case when lots of timers are
  // scheduled for exactly the same time, and it also assumes that most of
  // the timers will be scheduled later than existing timers.
  ACE_Timer_Node_T<TYPE>* p = this->head_->get_prev();
  while (p != this->head_ && p->get_timer_value() > expire)
    p = p->get_prev();

  // insert after
  n->set_prev(p);
  n->set_next(p->get_next());
  p->get_next()->set_prev(n);
  p->set_next(n);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Node_T<TYPE>*
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::find_node (long timer_id) const
{
  ACE_Timer_Node_T<TYPE>* n = this->get_first_i();
  if (n == 0)
    return 0;

  for (; n != this->head_; n = n->get_next()) {
    if (n->get_timer_id() == timer_id) {
      return n;
    }
  }
  return 0;
}

// Locate and update the inteval on the timer_id
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::reset_interval (long timer_id,
                                                           const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Timer_List_T::reset_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
  ACE_Timer_Node_T<TYPE>* n = this->find_node(timer_id);
  if (n != 0) {
    n->set_interval(interval); // The interval will take effect the next time this node is expired.
    return 0;
  }
  return -1;
}

// Locate and remove the single <ACE_Event_Handler> with a value of
// @a timer_id from the timer queue.
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (long timer_id,
                                                   const void **act,
                                                   int skip_close)
{
  ACE_TRACE ("ACE_Timer_List_T::cancel");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
  ACE_Timer_Node_T<TYPE>* n = this->find_node(timer_id);
  if (n != 0)
    {
      if (act != 0)
        *act = n->get_act ();

      // Call the close hooks.
      int cookie = 0;

      // cancel_type() called once per <type>.
      this->upcall_functor ().cancel_type (*this,
                                           n->get_type (),
                                           skip_close,
                                           cookie);

      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            n->get_type (),
                                            skip_close,
                                            cookie);

      this->cancel_i (n);

      return 1;
    }

  return 0;
}

// Locate and remove all values of <handler> from the timer queue.
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (const TYPE &type, int skip_close)
{
  ACE_TRACE ("ACE_Timer_List_T::cancel");

  int num_canceled = 0; // Note : Technically this can overflow.

  int cookie = 0;

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  if (!this->is_empty ())
    {
      for (ACE_Timer_Node_T<TYPE>* n = this->get_first();
           n != this->head_;
           )
        {
          if (n->get_type() == type) // Note: Typically Type is an ACE_Event_Handler*
            {
              ++num_canceled;

              ACE_Timer_Node_T<TYPE>* tmp = n;
              n = n->get_next();

              this->cancel_i (tmp);
            }
          else
            {
              n = n->get_next();
            }
        }
    }

  // Call the close hooks.

  // cancel_type() called once per <type>.
  this->upcall_functor ().cancel_type (*this,
                                       type,
                                       skip_close,
                                       cookie);

  for (int i = 0;
       i < num_canceled;
       ++i)
    {
      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            type,
                                            skip_close,
                                            cookie);
    }

  return num_canceled;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::unlink (ACE_Timer_Node_T<TYPE>* n)
{
  n->get_prev()->set_next(n->get_next());
  n->get_next()->set_prev(n->get_prev());
  n->set_prev(0);
  n->set_next(0);
}

/// Shared subset of the two cancel() methods.
template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::cancel_i (ACE_Timer_Node_T<TYPE>* n)
{
  this->unlink (n);
  this->free_node (n);
}

// Reads the first node on the list and returns it.
template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::get_first (void)
{
  ACE_TRACE ("ACE_Timer_List_T::get_first");
  return this->get_first_i();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::get_first_i (void) const
{
  ACE_TRACE ("ACE_Timer_List_T::get_first_i");
  ACE_Timer_Node_T<TYPE>* first = this->head_->get_next();
  if (first != this->head_) // Note : is_empty() uses get_first()
    return first;
  return 0;
}


// Removes the first node on the list and returns it.

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_List_T<TYPE, FUNCTOR, ACE_LOCK>::remove_first (void)
{
  ACE_TRACE ("ACE_Timer_List_T::remove_first");
  ACE_Timer_Node_T<TYPE>* first = this->get_first();
  if (first != 0) {
    this->unlink(first);
    return first;
  }
  return 0;
}

#endif /* ACE_TIMER_LIST_T_C */

