// $Id: Timer_Heap_T.cpp 84962 2009-03-24 15:16:25Z johnnyw $

#ifndef ACE_TIMER_HEAP_T_CPP
#define ACE_TIMER_HEAP_T_CPP

#include "ace/Timer_Heap_T.h"
#include "ace/Log_Msg.h"
#include "ace/Guard_T.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_string.h"
#include "ace/Numeric_Limits.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/*
** The ACE_Timer_Heap::max_size_ and array loops, checks, etc. are all size_t.
** The timer IDs are long, and since they are indices into the heap, we need
** to be sure that the timer heap size can fit in a long. Hence, when size
** is (re)set, limit it to the maximum long value. We use the C++ standard
** limits if available.
*/

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Define some simple inlined functions to clarify the code.
inline size_t
ACE_HEAP_PARENT (size_t X)
{
  return (X == 0 ? 0 : ((X - 1) / 2));
}

inline size_t
ACE_HEAP_LCHILD (size_t X)
{
  return X + X + 1;
}

// Constructor that takes in an <ACE_Timer_Heap_T> to iterate over.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Heap_Iterator_T (
  ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK> &heap)
  : timer_heap_ (heap)
{
  ACE_TRACE ("ACE_Timer_Heap_Iterator_T::ACE_Timer_Heap_Iterator");
  this->first ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::~ACE_Timer_Heap_Iterator_T (void)
{
}

// Positions the iterator at the first node in the heap array

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::first (void)
{
  this->position_ = 0;
}

// Positions the iterator at the next node in the heap array

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::next (void)
{
  if (this->position_ != this->timer_heap_.cur_size_)
    ++this->position_;
}

// Returns true the <position_> is at the end of the heap array

template <class TYPE, class FUNCTOR, class ACE_LOCK> bool
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::isdone (void) const
{
  return this->position_ == this->timer_heap_.cur_size_;
}

// Returns the node at the current position in the heap or 0 if at the end

template <class TYPE, class FUNCTOR, class ACE_LOCK> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Heap_Iterator_T<TYPE, FUNCTOR, ACE_LOCK>::item (void)
{
  if (this->position_ != this->timer_heap_.cur_size_)
    return this->timer_heap_.heap_[this->position_];
  return 0;
}

// Constructor
// Note that timer_ids_curr_ and timer_ids_min_free_ both start at 0.
// Since timer IDs are assigned by first incrementing the timer_ids_curr_
// value, the first ID assigned will be 1 (just as in the previous design).
// When it's time to wrap, the next ID given out will be 0.
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Heap_T (
  size_t size,
  bool preallocated,
  FUNCTOR *upcall_functor,
  ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist)
  : ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK> (upcall_functor, freelist),
    max_size_ (size),
    cur_size_ (0),
    cur_limbo_ (0),
    timer_ids_curr_ (0),
    timer_ids_min_free_ (0),
    preallocated_nodes_ (0),
    preallocated_nodes_freelist_ (0)
{
  ACE_TRACE ("ACE_Timer_Heap_T::ACE_Timer_Heap_T");

  // Possibly reduce size to fit in a long.
  if (size > static_cast<size_t> (ACE_Numeric_Limits<long>::max ()))
    {
      size = static_cast<size_t> (ACE_Numeric_Limits<long>::max ());
      this->max_size_ = size;
    }

  // Create the heap array.
  ACE_NEW (this->heap_,
           ACE_Timer_Node_T<TYPE> *[size]);

  // Create the parallel
  ACE_NEW (this->timer_ids_,
           ssize_t[size]);

  // Initialize the "freelist," which uses negative values to
  // distinguish freelist elements from "pointers" into the <heap_>
  // array.
  for (size_t i = 0; i < size; ++i)
    this->timer_ids_[i] = -1;

  if (preallocated)
    {
      ACE_NEW (this->preallocated_nodes_,
               ACE_Timer_Node_T<TYPE>[size]);

      // Add allocated array to set of such arrays for deletion on
      // cleanup.
      this->preallocated_node_set_.insert (this->preallocated_nodes_);

      // Form the freelist by linking the next_ pointers together.
      for (size_t j = 1; j < size; ++j)
        this->preallocated_nodes_[j - 1].set_next (&this->preallocated_nodes_[j]);

      // NULL-terminate the freelist.
      this->preallocated_nodes_[size - 1].set_next (0);

      // Assign the freelist pointer to the front of the list.
      this->preallocated_nodes_freelist_ =
        &this->preallocated_nodes_[0];
    }

  ACE_NEW (iterator_,
           HEAP_ITERATOR (*this));
}

// Note that timer_ids_curr_ and timer_ids_min_free_ both start at 0.
// Since timer IDs are assigned by first incrementing the timer_ids_curr_
// value, the first ID assigned will be 1 (just as in the previous design).
// When it's time to wrap, the next ID given out will be 0.
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Heap_T (
  FUNCTOR *upcall_functor,
  ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist)
  : ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK> (upcall_functor, freelist),
    max_size_ (ACE_DEFAULT_TIMERS),
    cur_size_ (0),
    cur_limbo_ (0),
    timer_ids_curr_ (0),
    timer_ids_min_free_ (0),
    preallocated_nodes_ (0),
    preallocated_nodes_freelist_ (0)
{
  ACE_TRACE ("ACE_Timer_Heap_T::ACE_Timer_Heap_T");

  // Possibly reduce size to fit in a long.
  if (this->max_size_ > static_cast<size_t> (ACE_Numeric_Limits<long>::max ()))
    this->max_size_ = static_cast<size_t> (ACE_Numeric_Limits<long>::max ());

  // Create the heap array.
    ACE_NEW (this->heap_,
             ACE_Timer_Node_T<TYPE> *[this->max_size_]);

  // Create the parallel array.
  ACE_NEW (this->timer_ids_,
           ssize_t[this->max_size_]);

  // Initialize the "freelist," which uses negative values to
  // distinguish freelist elements from "pointers" into the <heap_>
  // array.
  for (size_t i = 0; i < this->max_size_; ++i)
    this->timer_ids_[i] = -1;

  ACE_NEW (iterator_,
           HEAP_ITERATOR (*this));
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::~ACE_Timer_Heap_T (void)
{
  ACE_TRACE ("ACE_Timer_Heap_T::~ACE_Timer_Heap_T");

  delete iterator_;

  size_t current_size =
    this->cur_size_;

  // Clean up all the nodes still in the queue
  for (size_t i = 0; i < current_size; ++i)
    {
      // Grab the event_handler and act, then delete the node before calling
      // back to the handler. Prevents a handler from trying to cancel_timer()
      // inside handle_close(), ripping the current timer node out from
      // under us.
      TYPE eh = this->heap_[i]->get_type ();
      const void *act = this->heap_[i]->get_act ();
      this->free_node (this->heap_[i]);
      this->upcall_functor ().deletion (*this, eh, act);
    }

  delete [] this->heap_;
  delete [] this->timer_ids_;

  // clean up any preallocated timer nodes
  if (preallocated_nodes_ != 0)
    {
      ACE_Unbounded_Set_Iterator<ACE_Timer_Node_T<TYPE> *>
        set_iterator (this->preallocated_node_set_);

      for (ACE_Timer_Node_T<TYPE> **entry = 0;
           set_iterator.next (entry) !=0;
           set_iterator.advance ())
        delete [] *entry;
    }
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
long
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::pop_freelist (void)
{
  ACE_TRACE ("ACE_Timer_Heap_T::pop_freelist");

  // Scan for a free timer ID. Note that since this function is called
  // _after_ the check for a full timer heap, we are guaranteed to find
  // a free ID, even if we need to wrap around and start reusing freed IDs.
  // On entry, the curr_ index is at the previous ID given out; start
  // up where we left off last time.
  // NOTE - a timer_ids_ slot with -2 is out of the heap, but not freed.
  // It must be either freed (free_node) or rescheduled (reschedule).
  ++this->timer_ids_curr_;
  while (this->timer_ids_curr_ < this->max_size_ &&
         (this->timer_ids_[this->timer_ids_curr_] >= 0 ||
          this->timer_ids_[this->timer_ids_curr_] == -2  ))
    ++this->timer_ids_curr_;
  if (this->timer_ids_curr_ == this->max_size_)
    {
      ACE_ASSERT (this->timer_ids_min_free_ < this->max_size_);
      this->timer_ids_curr_ = this->timer_ids_min_free_;
      // We restarted the free search at min. Since min won't be
      // free anymore, and curr_ will just keep marching up the list
      // on each successive need for an ID, reset min_free_ to the
      // size of the list until an ID is freed that curr_ has already
      // gone past (see push_freelist).
      this->timer_ids_min_free_ = this->max_size_;
    }

  return static_cast<long> (this->timer_ids_curr_);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::push_freelist (long old_id)
{
  ACE_TRACE ("ACE_Timer_Heap_T::push_freelist");

  // Since this ID has already been checked by one of the public
  // functions, it's safe to cast it here.
  size_t oldid = static_cast<size_t> (old_id);

  // The freelist values in the <timer_ids_> are negative, so set the
  // freed entry back to 'free'. If this is the new lowest value free
  // timer ID that curr_ won't see on it's normal march through the list,
  // remember it.
  ACE_ASSERT (this->timer_ids_[oldid] >= 0 || this->timer_ids_[oldid] == -2);
  if (this->timer_ids_[oldid] == -2)
    --this->cur_limbo_;
  else
    --this->cur_size_;
  this->timer_ids_[oldid] = -1;
  if (oldid < this->timer_ids_min_free_ && oldid <= this->timer_ids_curr_)
    this->timer_ids_min_free_ = oldid;
  return;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
long
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::timer_id (void)
{
  ACE_TRACE ("ACE_Timer_Heap_T::timer_id");

  // Return the next item off the freelist and use it as the timer id.
  return this->pop_freelist ();
}

// Checks if queue is empty.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
bool
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::is_empty (void) const
{
  ACE_TRACE ("ACE_Timer_Heap_T::is_empty");
  return this->cur_size_ == 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> &
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::iter (void)
{
  this->iterator_->first ();
  return *this->iterator_;
}

// Returns earliest time in a non-empty queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK> const ACE_Time_Value &
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::earliest_time (void) const
{
  ACE_TRACE ("ACE_Timer_Heap_T::earliest_time");
  return this->heap_[0]->get_timer_value ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Timer_Heap_T::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmax_size_ = %d"), this->max_size_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ncur_size_ = %d"), this->cur_size_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ncur_limbo_= %d"), this->cur_limbo_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nids_curr_ = %d"),
              this->timer_ids_curr_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nmin_free_ = %d"),
              this->timer_ids_min_free_));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nheap_ =\n")));

  for (size_t i = 0; i < this->cur_size_; ++i)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%d\n"),
                  i));
      this->heap_[i]->dump ();
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntimer_ids_ =\n")));

  for (size_t j = 0; j < this->max_size_; ++j)
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%d\t%d\n"),
                j,
                this->timer_ids_[j]));

  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::copy (
  size_t slot,
  ACE_Timer_Node_T<TYPE> *moved_node)
{
  // Insert <moved_node> into its new location in the heap.
  this->heap_[slot] = moved_node;

  ACE_ASSERT (moved_node->get_timer_id () >= 0
              && moved_node->get_timer_id () < (int) this->max_size_);

  // Update the corresponding slot in the parallel <timer_ids_> array.
  this->timer_ids_[moved_node->get_timer_id ()] = static_cast<ssize_t> (slot);
}

// Remove the slot'th timer node from the heap, but do not reclaim its
// timer ID or change the size of this timer heap object. The caller of
// this function must call either free_node (to reclaim the timer ID
// and the timer node memory, as well as decrement the size of the queue)
// or reschedule (to reinsert the node in the heap at a new time).
template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Node_T<TYPE> *
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::remove (size_t slot)
{
  ACE_Timer_Node_T<TYPE> *removed_node =
    this->heap_[slot];

  // NOTE - the cur_size_ is being decremented since the queue has one
  // less active timer in it. However, this ACE_Timer_Node is not being
  // freed, and there is still a place for it in timer_ids_ (the timer ID
  // is not being relinquished). The node can still be rescheduled, or
  // it can be freed via free_node.
  --this->cur_size_;

  // Only try to reheapify if we're not deleting the last entry.

  if (slot < this->cur_size_)
    {
      ACE_Timer_Node_T<TYPE> *moved_node =
        this->heap_[this->cur_size_];

      // Move the end node to the location being removed and update
      // the corresponding slot in the parallel <timer_ids> array.
      this->copy (slot, moved_node);

      // If the <moved_node->time_value_> is great than or equal its
      // parent it needs be moved down the heap.
      size_t parent = ACE_HEAP_PARENT (slot);

      if (moved_node->get_timer_value ()
          >= this->heap_[parent]->get_timer_value ())
        this->reheap_down (moved_node,
                           slot,
                           ACE_HEAP_LCHILD (slot));
      else
        this->reheap_up (moved_node,
                         slot,
                         parent);
    }

  this->timer_ids_[removed_node->get_timer_id ()] = -2;
  ++this->cur_limbo_;
  return removed_node;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::reheap_down (
  ACE_Timer_Node_T<TYPE> *moved_node,
  size_t slot,
  size_t child)
{
  // Restore the heap property after a deletion.

  while (child < this->cur_size_)
    {
      // Choose the smaller of the two children.
      if (child + 1 < this->cur_size_
          && this->heap_[child + 1]->get_timer_value ()
          < this->heap_[child]->get_timer_value ())
        child++;

      // Perform a <copy> if the child has a larger timeout value than
      // the <moved_node>.
      if (this->heap_[child]->get_timer_value ()
          < moved_node->get_timer_value ())
        {
          this->copy (slot,
                      this->heap_[child]);
          slot = child;
          child = ACE_HEAP_LCHILD (child);
        }
      else
        // We've found our location in the heap.
        break;
    }

  this->copy (slot, moved_node);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::reheap_up (
  ACE_Timer_Node_T<TYPE> *moved_node,
  size_t slot,
  size_t parent)
{
  // Restore the heap property after an insertion.

  while (slot > 0)
    {
      // If the parent node is greater than the <moved_node> we need
      // to copy it down.
      if (moved_node->get_timer_value ()
          < this->heap_[parent]->get_timer_value ())
        {
          this->copy (slot, this->heap_[parent]);
          slot = parent;
          parent = ACE_HEAP_PARENT (slot);
        }
      else
        break;
    }

  // Insert the new node into its proper resting place in the heap and
  // update the corresponding slot in the parallel <timer_ids> array.
  this->copy (slot,
              moved_node);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::insert (
  ACE_Timer_Node_T<TYPE> *new_node)
{
  if (this->cur_size_ + this->cur_limbo_ + 2 >= this->max_size_)
    this->grow_heap ();

  this->reheap_up (new_node,
                   this->cur_size_,
                   ACE_HEAP_PARENT (this->cur_size_));
  this->cur_size_++;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::grow_heap (void)
{
  // All the containers will double in size from max_size_.
  size_t new_size = this->max_size_ * 2;

#if 0
  // Yikes - there's no way to flag a failure of going out of range of
  // a 'long' - this is a problem that should be addressed at some point.
  if (new_size > ACE_Numeric_Limits<long>::max ())
    new_size = ACE_Numeric_Limits<long>::max ();

  if (new_size <= this->max_size_)   // We are already at the limit
    {
      errno = ENOMEM;
      return -1;
    }
#endif /* 0 */

   // First grow the heap itself.

  ACE_Timer_Node_T<TYPE> **new_heap = 0;

  ACE_NEW (new_heap,
           ACE_Timer_Node_T<TYPE> *[new_size]);

  ACE_OS::memcpy (new_heap,
                  this->heap_,
                  this->max_size_ * sizeof *new_heap);
  delete [] this->heap_;
  this->heap_ = new_heap;

  // Grow the array of timer ids.

  ssize_t *new_timer_ids = 0;

  ACE_NEW (new_timer_ids,
           ssize_t[new_size]);

  ACE_OS::memcpy (new_timer_ids,
                  this->timer_ids_,
                  this->max_size_ * sizeof (ssize_t));

  delete [] timer_ids_;
  this->timer_ids_ = new_timer_ids;

  // And add the new elements to the end of the "freelist".
  for (size_t i = this->max_size_; i < new_size; ++i)
    this->timer_ids_[i] = -(static_cast<ssize_t> (i) + 1);

   // Grow the preallocation array (if using preallocation)
  if (this->preallocated_nodes_ != 0)
    {
      // Create a new array with max_size elements to link in to
      // existing list.
      ACE_NEW (this->preallocated_nodes_,
               ACE_Timer_Node_T<TYPE>[this->max_size_]);

      // Add it to the set for later deletion
      this->preallocated_node_set_.insert (this->preallocated_nodes_);

      // Link new nodes together (as for original list).
      for (size_t k = 1; k < this->max_size_; ++k)
        this->preallocated_nodes_[k - 1].set_next (&this->preallocated_nodes_[k]);

      // NULL-terminate the new list.
      this->preallocated_nodes_[this->max_size_ - 1].set_next (0);

      // Link new array to the end of the existling list.
      if (this->preallocated_nodes_freelist_ == 0)
        this->preallocated_nodes_freelist_ =
          &preallocated_nodes_[0];
      else
        {
          ACE_Timer_Node_T<TYPE> *previous =
            this->preallocated_nodes_freelist_;

          for (ACE_Timer_Node_T<TYPE> *current = this->preallocated_nodes_freelist_->get_next ();
               current != 0;
               current = current->get_next ())
            previous = current;

          previous->set_next (&this->preallocated_nodes_[0]);
        }
    }

  this->max_size_ = new_size;
  // Force rescan of list from beginning for a free slot (I think...)
  // This fixed Bugzilla #2447.
  this->timer_ids_min_free_ = this->max_size_;
}

// Reschedule a periodic timer.  This function must be called with the
// mutex lock held.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::reschedule (
  ACE_Timer_Node_T<TYPE> *expired)
{
  ACE_TRACE ("ACE_Timer_Heap_T::reschedule");

  // If we are rescheduling, then the most recent call was to
  // remove_first (). That called remove () to remove the node from the
  // heap, but did not free the timer ID. The ACE_Timer_Node still has
  // its assigned ID - just needs to be inserted at the new proper
  // place, and the heap restored properly.
  if (this->timer_ids_[expired->get_timer_id ()] == -2)
    --this->cur_limbo_;
  this->insert (expired);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Node_T<TYPE> *
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::alloc_node (void)
{
  ACE_Timer_Node_T<TYPE> *temp = 0;

  // Only allocate a node if we are *not* using the preallocated heap.
  if (this->preallocated_nodes_ == 0)
    ACE_NEW_RETURN (temp,
                    ACE_Timer_Node_T<TYPE>,
                    0);
  else
    {
      // check to see if the heap needs to grow
      if (this->preallocated_nodes_freelist_ == 0)
        this->grow_heap ();

      temp = this->preallocated_nodes_freelist_;

      // Remove the first element from the freelist.
      this->preallocated_nodes_freelist_ =
        this->preallocated_nodes_freelist_->get_next ();
    }
  return temp;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
void
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::free_node (
  ACE_Timer_Node_T<TYPE> *node)
{
  // Return this timer id to the freelist.
  this->push_freelist (node->get_timer_id ());

  // Only free up a node if we are *not* using the preallocated heap.
  if (this->preallocated_nodes_ == 0)
    delete node;
  else
    {
      node->set_next (this->preallocated_nodes_freelist_);
      this->preallocated_nodes_freelist_ = node;
    }
}

// Insert a new timer that expires at time future_time; if interval is
// > 0, the handler will be reinvoked periodically.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
long
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::schedule_i (
  const TYPE &type,
  const void *act,
  const ACE_Time_Value &future_time,
  const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Timer_Heap_T::schedule_i");

  if ((this->cur_size_ + this->cur_limbo_) < this->max_size_)
    {
      // Obtain the next unique sequence number.
      long const timer_id = this->timer_id ();

      // Obtain the memory to the new node.
      ACE_Timer_Node_T<TYPE> *temp = 0;

      ACE_ALLOCATOR_RETURN (temp,
                            this->alloc_node (),
                            -1);
      temp->set (type,
                 act,
                 future_time,
                 interval,
                 0,
                 timer_id);

      this->insert (temp);
      return timer_id;
    }
  else
    return -1;
}

// Locate and remove the single timer with a value of @a timer_id from
// the timer queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
int
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (long timer_id,
                                                   const void **act,
                                                   int dont_call)
{
  ACE_TRACE ("ACE_Timer_Heap_T::cancel");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  // Locate the ACE_Timer_Node that corresponds to the timer_id.

  // Check to see if the timer_id is out of range
  if (timer_id < 0
      || (size_t) timer_id > this->max_size_)
    return 0;

  ssize_t timer_node_slot = this->timer_ids_[timer_id];

  // Check to see if timer_id is still valid.
  if (timer_node_slot < 0)
    return 0;

  if (timer_id != this->heap_[timer_node_slot]->get_timer_id ())
    {
      ACE_ASSERT (timer_id == this->heap_[timer_node_slot]->get_timer_id ());
      return 0;
    }
  else
    {
      ACE_Timer_Node_T<TYPE> *temp =
        this->remove (timer_node_slot);

      // Call the close hooks.
      int cookie = 0;

      // cancel_type() called once per <type>.
      this->upcall_functor ().cancel_type (*this,
                                           temp->get_type (),
                                           dont_call,
                                           cookie);

      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            temp->get_type (),
                                            dont_call,
                                            cookie);

      if (act != 0)
        *act = temp->get_act ();

      this->free_node (temp);
      return 1;
    }
}

// Locate and update the inteval on the timer_id

template <class TYPE, class FUNCTOR, class ACE_LOCK>
int
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::reset_interval (long timer_id,
                                                           const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Timer_Heap_T::reset_interval");
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  // Locate the ACE_Timer_Node that corresponds to the timer_id.

  // Check to see if the timer_id is out of range
  if (timer_id < 0
      || (size_t) timer_id > this->max_size_)
    return -1;

  ssize_t timer_node_slot = this->timer_ids_[timer_id];

  // Check to see if timer_id is still valid.
  if (timer_node_slot < 0)
    return -1;

  if (timer_id != this->heap_[timer_node_slot]->get_timer_id ())
    {
      ACE_ASSERT (timer_id == this->heap_[timer_node_slot]->get_timer_id ());
      return -1;
    }
  else
    {
      // Reset the timer interval
      this->heap_[timer_node_slot]->set_interval (interval);
      return 0;
    }
}

// Locate and remove all values of @a type from the timer queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
int
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::cancel (const TYPE &type,
                                                   int dont_call)
{
  ACE_TRACE ("ACE_Timer_Heap_T::cancel");

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  int number_of_cancellations = 0;

  // Try to locate the ACE_Timer_Node that matches the timer_id.

  for (size_t i = 0; i < this->cur_size_; )
    {
      if (this->heap_[i]->get_type () == type)
        {
          ACE_Timer_Node_T<TYPE> *temp = this->remove (i);

          ++number_of_cancellations;

          this->free_node (temp);

          // We reset to zero so that we don't miss checking any nodes
          // if a reheapify occurs when a node is removed.  There
          // may be a better fix than this, however.
          i = 0;
        }
      else
        ++i;
    }

  // Call the close hooks.
  int cookie = 0;

  // cancel_type() called once per <type>.
  this->upcall_functor ().cancel_type (*this,
                                       type,
                                       dont_call,
                                       cookie);

  for (int j = 0;
       j < number_of_cancellations;
       ++j)
    {
      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            type,
                                            dont_call,
                                            cookie);
    }

  return number_of_cancellations;
}

// Returns the earliest node or returns 0 if the heap is empty.

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Node_T <TYPE> *
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::remove_first (void)
{
  ACE_TRACE ("ACE_Timer_Heap_T::remove_first");

  if (this->cur_size_ == 0)
    return 0;

  return this->remove (0);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Node_T <TYPE> *
ACE_Timer_Heap_T<TYPE, FUNCTOR, ACE_LOCK>::get_first (void)
{
  ACE_TRACE ("ACE_Timer_Heap_T::get_first");

  return this->cur_size_ == 0 ? 0 : this->heap_[0];
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TIMER_HEAP_T_CPP */
