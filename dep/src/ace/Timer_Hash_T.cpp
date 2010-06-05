// $Id: Timer_Hash_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_TIMER_HASH_T_CPP
#define ACE_TIMER_HASH_T_CPP

#include "ace/Timer_Hash_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/OS_NS_sys_time.h"
#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"

ACE_RCSID(ace,
          Timer_Hash_T,
          "$Id: Timer_Hash_T.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TYPE>
class Hash_Token
{
public:
  // This constructor is required by ACE_Locked_Free_List::alloc.
  Hash_Token (void)
  {}

  Hash_Token<TYPE> *get_next (void)
  {
    return this->next_;
  }

  void set_next (Hash_Token<TYPE> *next)
  {
    this->next_ = next;
  }

  void set (const void *act,
            size_t pos,
            long orig_id,
            const TYPE &type)
  {
    this->act_ = act;
    this->pos_ = pos;
    this->orig_id_ = orig_id;
    this->type_ = type;
    this->next_ = 0;
  }

  const void *act_;
  size_t pos_;
  long orig_id_;
  TYPE type_;
  /// Pointer to next token.
  Hash_Token<TYPE> *next_;
};

// Default constructor

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Hash_Upcall (void)
  : timer_hash_ (0)
{
  // Nothing
}

// Constructor that specifies a Timer_Hash to call up to

template <class TYPE, class FUNCTOR, class ACE_LOCK>
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::ACE_Timer_Hash_Upcall (
  ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK> *timer_hash)
  : timer_hash_ (timer_hash)
{
  // Nothing
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::registration (
  TIMER_QUEUE &,
  ACE_Event_Handler *,
  const void *)
{
  // Registration will be handled by the upcall functor of the timer
  // hash.
  return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::preinvoke (TIMER_QUEUE &,
                                                           ACE_Event_Handler *,
                                                           const void *,
                                                           int,
                                                           const ACE_Time_Value &,
                                                           const void *&)
{
  // This method should never be invoked since we don't invoke
  // expire() on the buckets.
  ACE_ASSERT (0);
  return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::postinvoke (
  TIMER_QUEUE &,
  ACE_Event_Handler *,
  const void *,
  int,
  const ACE_Time_Value &,
  const void *)
{
  // This method should never be invoked since we don't invoke
  // expire() on the buckets.
  ACE_ASSERT (0);
  return 0;
}

// Calls up to timer_hash's upcall functor
template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::timeout (
  TIMER_QUEUE &,
  ACE_Event_Handler *,
  const void *,
  int,
  const ACE_Time_Value &)
{
  // This method should never be invoked since we don't invoke
  // expire() on the buckets.
  ACE_ASSERT (0);
  return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::cancel_type (
  TIMER_QUEUE &,
  ACE_Event_Handler *,
  int,
  int &)
{
  // Cancellation will be handled by the upcall functor of the timer
  // hash.
  return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::cancel_timer (
  TIMER_QUEUE &,
  ACE_Event_Handler *,
  int,
  int)
{
  // Cancellation will be handled by the upcall functor of the timer
  // hash.
  return 0;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK> int
ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>::deletion (
  TIMER_QUEUE &,
  ACE_Event_Handler *event_handler,
  const void *arg)
{
  // Call up to the upcall functor of the timer hash since the timer
  // hash does not invoke deletion() on its upcall functor directly.
  Hash_Token<TYPE> *h =
    reinterpret_cast<Hash_Token<TYPE> *> (const_cast<void *> (arg));

  int result =
    this->timer_hash_->upcall_functor ().
    deletion (*this->timer_hash_,
              event_handler,
              h->act_);

  return result;
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Hash_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::ACE_Timer_Hash_Iterator_T (ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET> &hash)
  : timer_hash_ (hash)
{
  this->first ();
  // Nothing
}

// Positions the iterator at the first node in the timing hash table

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> void
ACE_Timer_Hash_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::first (void)
{
  for (this->position_ = 0;
       this->position_ < this->timer_hash_.table_size_;
       ++this->position_)
    {
      // Check for an empty entry
      if (!this->timer_hash_.table_[this->position_]->is_empty ())
        {
          this->iter_ = &this->timer_hash_.table_[this->position_]->iter ();
          this->iter_->first ();
          return;
        }
    }

  // Didn't find any
  this->iter_ = 0;
}

// Positions the iterator at the next node in the bucket or goes to the next
// bucket

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> void
ACE_Timer_Hash_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::next (void)
{
  if (this->isdone ())
    return;

  // If there is no more in the current bucket, go to the next
  if (this->iter_->isdone ())
    {
      for (++this->position_;
           this->position_ < this->timer_hash_.table_size_;
           ++this->position_)
        {
          // Check for an empty entry
          if (!this->timer_hash_.table_[this->position_]->is_empty ())
            {
              this->iter_ = &this->timer_hash_.table_[this->position_]->iter ();
              this->iter_->first ();
              return;
            }
        }

      // Didn't find any.
      this->iter_ = 0;
    }
  else
    this->iter_->next ();
}

// Returns true when we are at the end (when bucket_item_ == 0)

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> bool
ACE_Timer_Hash_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::isdone (void) const
{
  return this->iter_ == 0;
}

// Returns the node at the current position in the sequence

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Node_T<TYPE> *
ACE_Timer_Hash_Iterator_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::item (void)
{
  if (this->isdone ())
    return 0;

  return this->iter_->item ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Queue_Iterator_T<TYPE, FUNCTOR, ACE_LOCK> &
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::iter (void)
{
  this->iterator_->first ();
  return *this->iterator_;
}

// Create an empty queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::ACE_Timer_Hash_T (
  size_t table_size,
  FUNCTOR *upcall_functor,
  ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist)
  : ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK> (upcall_functor, freelist),
    size_ (0),
    table_size_ (table_size),
    table_functor_ (this),
    earliest_position_ (0)
#if defined (ACE_WIN64)
  , pointer_base_ (0)
#endif /* ACE_WIN64 */
  , token_list_ ()
{
  ACE_TRACE ("ACE_Timer_Hash_T::ACE_Timer_Hash_T");

  ACE_NEW (table_,
           BUCKET *[table_size]);

  this->gettimeofday (ACE_OS::gettimeofday);

  for (size_t i = 0;
       i < table_size;
       ++i)
    {
      ACE_NEW (this->table_[i],
               BUCKET (&this->table_functor_,
                       this->free_list_));
      this->table_[i]->gettimeofday (ACE_OS::gettimeofday);
    }

  ACE_NEW (iterator_,
           HASH_ITERATOR (*this));
}


template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::ACE_Timer_Hash_T (
  FUNCTOR *upcall_functor,
  ACE_Free_List<ACE_Timer_Node_T <TYPE> > *freelist)
  : ACE_Timer_Queue_T<TYPE, FUNCTOR, ACE_LOCK> (upcall_functor, freelist),
    size_ (0),
    table_size_ (ACE_DEFAULT_TIMER_HASH_TABLE_SIZE),
    table_functor_ (this),
    earliest_position_ (0)
#if defined (ACE_WIN64)
  , pointer_base_ (0)
#endif /* ACE_WIN64 */
  , token_list_ ()
{
  ACE_TRACE ("ACE_Timer_Hash_T::ACE_Timer_Hash_T");

  ACE_NEW (table_,
           BUCKET *[ACE_DEFAULT_TIMER_HASH_TABLE_SIZE]);


  this->gettimeofday (ACE_OS::gettimeofday);

  for (size_t i = 0;
       i < this->table_size_;
       ++i)
    {
      ACE_NEW (this->table_[i],
               BUCKET (&this->table_functor_,
                       this->free_list_));
      this->table_[i]->gettimeofday (ACE_OS::gettimeofday);
    }

  ACE_NEW (iterator_,
           HASH_ITERATOR (*this));
}

// Remove all remaining items in the Queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::~ACE_Timer_Hash_T (void)
{
  ACE_TRACE ("ACE_Timer_Hash_T::~ACE_Timer_Hash_T");
  ACE_MT (ACE_GUARD (ACE_LOCK, ace_mon, this->mutex_));

  delete iterator_;

  for (size_t i = 0;
       i < this->table_size_;
       ++i)
    delete this->table_[i];

  delete [] this->table_;
}

// Checks if queue is empty.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> bool
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::is_empty (void) const
{
  ACE_TRACE ("ACE_Timer_Hash_T::is_empty");
  return this->table_[this->earliest_position_]->is_empty ();
}

// Returns earliest time in a non-empty bucket

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
const ACE_Time_Value &
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::earliest_time (void) const
{
  ACE_TRACE ("ACE_Timer_Hash_T::earliest_time");
  return this->table_[this->earliest_position_]->earliest_time ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> void
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Timer_Hash_T::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\ntable_size_ = %d"), this->table_size_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nearliest_position_ = %d"), this->earliest_position_));

  for (size_t i = 0; i < this->table_size_; ++i)
    if (!this->table_[i]->is_empty ())
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nBucket %d contains nodes"), i));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Reschedule a periodic timer.  This function must be called with the
// mutex lock held.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
void
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::reschedule (
  ACE_Timer_Node_T<TYPE> *expired)
{
  ACE_TRACE ("ACE_Timer_Hash_T::reschedule");

  Hash_Token<TYPE> *h =
    reinterpret_cast<Hash_Token<TYPE> *> (
      const_cast<void *> (expired->get_act ()));

  // Don't use ACE_Utils::truncate_cast<> here.  A straight
  // static_cast<>  will provide more unique results when the number
  // of seconds is greater than std::numeric_limits<size_t>::max().
  size_t const secs_hash_input =
    static_cast<size_t> (expired->get_timer_value ().sec ());
  h->pos_ = secs_hash_input % this->table_size_;

  h->orig_id_ =
    this->table_[h->pos_]->schedule (expired->get_type (),
                                     h,
                                     expired->get_timer_value (),
                                     expired->get_interval ());
  ACE_ASSERT (h->orig_id_ != -1);

#if 0
  ACE_DEBUG ((LM_DEBUG, "Hash::reschedule() resets %d in slot %d where it's id is %d and token is %x\n",
              expired->get_timer_value ().msec (),
              h->pos_,
              h->orig_id_,
              h));
#endif

  // Since schedule() above will allocate a new node
  // then here schedule <expired> for deletion. Don't call
  // this->free_node() because that will invalidate <h>
  // and that's what user have as timer_id.
  ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK>::free_node (expired);

  if (this->table_[this->earliest_position_]->is_empty ()
      || this->table_[h->pos_]->earliest_time ()
      < this->table_[this->earliest_position_]->earliest_time ())
    this->earliest_position_ = h->pos_;
}

// Insert a new handler that expires at time future_time; if interval
// is > 0, the handler will be reinvoked periodically.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
long
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::schedule_i (
  const TYPE &type,
  const void *act,
  const ACE_Time_Value &future_time,
  const ACE_Time_Value &interval)
{
  ACE_TRACE ("ACE_Timer_Hash_T::schedule_i");

  // Don't use ACE_Utils::truncate_cast<> here.  A straight
  // static_cast<>  will provide more unique results when the number
  // of seconds is greater than std::numeric_limits<size_t>::max().
  size_t const secs_hash_input = static_cast<size_t> (future_time.sec ());
  size_t const position = secs_hash_input % this->table_size_;

  // Don't create Hash_Token directly. Instead we get one from Free_List
  // and then set it properly.
  Hash_Token<TYPE> *h = this->token_list_.remove ();
  h->set (act, position, 0, type);

  h->orig_id_ =
    this->table_[position]->schedule (type,
                                      h,
                                      future_time,
                                      interval);
  ACE_ASSERT (h->orig_id_ != -1);

#if 0
  ACE_DEBUG ((LM_DEBUG, "Hash::schedule() placing %d in slot %d where it's id is %d and token is %x\n",
              future_time.msec (),
              position,
              h->orig_id_,
              h));
#endif

  if (this->table_[this->earliest_position_]->is_empty ()
      || this->table_[position]->earliest_time ()
      < this->table_[this->earliest_position_]->earliest_time ())
    this->earliest_position_ = position;

  ++this->size_;

#if defined (ACE_WIN64)
  // This is a Win64 hack, necessary because of the original (bad) decision
  // to use a pointer as the timer ID. This class doesn't follow the usual
  // timer expiration rules (see comments in header file) and is probably
  // not used much. The dynamic allocation of Hash_Tokens without
  // recording them anywhere is a large problem for Win64 since the
  // size of a pointer is 64 bits, but a long is 32. Since this class
  // is not much used, I'm hacking this, at least for now. If it becomes
  // an issue, I'll look at it again then.
  intptr_t hi = reinterpret_cast<intptr_t> (h);
  if (this->pointer_base_ == 0)
    this->pointer_base_ = hi & 0xffffffff00000000;
  return static_cast<long> (hi & 0xffffffff);
#else
  return reinterpret_cast<long> (h);
#endif
}

// Locate and update the inteval on the timer_id

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::reset_interval (
  long timer_id,
  const ACE_Time_Value & interval)
{
  ACE_TRACE ("ACE_Timer_Hash_T::reset_interval");

  // Make sure we are getting a valid <timer_id>, not an error
  // returned by <schedule>.
  if (timer_id == -1)
    return -1;

#if defined (ACE_WIN64)
  unsigned long const timer_offset =
    static_cast<unsigned long> (timer_id);

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  Hash_Token<TYPE> * const h =
    reinterpret_cast<Hash_Token<TYPE> *> (this->pointer_base_ + timer_offset);
#else
  Hash_Token<TYPE> * const h =
    reinterpret_cast<Hash_Token<TYPE> *> (timer_id);

  // Grab the lock before accessing the table.  We don't need to do so
  // before this point since no members are accessed until now.
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
#endif /* ACE_WIN64 */

  return this->table_[h->pos_]->reset_interval (h->orig_id_,
                                                interval);
}

// Locate and remove the single <ACE_Event_Handler> with a value of
// @a timer_id from the correct table timer queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::cancel (long timer_id,
                                                           const void **act,
                                                           int dont_call)
{
  ACE_TRACE ("ACE_Timer_Hash_T::cancel");

  // Make sure we are getting a valid <timer_id>, not an error
  // returned by <schedule>.
  if (timer_id == -1)
    return 0;

#if defined (ACE_WIN64)
  unsigned long const timer_offset =
    static_cast<unsigned long> (timer_id);

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  Hash_Token<TYPE> * const h =
    reinterpret_cast<Hash_Token<TYPE> *> (this->pointer_base_ + timer_offset);
#else
  Hash_Token<TYPE> * const h =
    reinterpret_cast<Hash_Token<TYPE> *> (timer_id);

  // Grab the lock before accessing the table.  We don't need to do so
  // before this point since no members are accessed until now.
  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));
#endif /* ACE_WIN64 */

  int const result = this->table_[h->pos_]->cancel (h->orig_id_,
                                                    0,
                                                    dont_call);

  if (result == 1)
    {
      // Call the close hooks.
      int cookie = 0;

      // cancel_type() called once per <type>.
      this->upcall_functor ().cancel_type (*this,
                                           h->type_,
                                           dont_call,
                                           cookie);

      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            h->type_,
                                            dont_call,
                                            cookie);

      if (h->pos_ == this->earliest_position_)
        this->find_new_earliest ();

      if (act != 0)
        *act = h->act_;

      // We could destruct Hash_Token explicitly but we better
      // schedule it for destruction. In this case next
      // token_list_.remove () will use it.
      this->token_list_.add (h);

      --this->size_;
    }

  return result;
}

// Locate and remove all values of <type> from the timer queue.

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET>
int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::cancel (const TYPE &type,
                                                           int dont_call)
{
  ACE_TRACE ("ACE_Timer_Hash_T::cancel");

  size_t i; // loop variable.

  Hash_Token<TYPE> **timer_ids = 0;
  size_t pos = 0;

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  ACE_NEW_RETURN (timer_ids,
                  Hash_Token<TYPE> *[this->size_],
                  -1);

  for (i = 0;
       i < this->table_size_;
       ++i)
    {
      ACE_Timer_Queue_Iterator_T<TYPE,
                                 ACE_Timer_Hash_Upcall<TYPE, FUNCTOR, ACE_LOCK>,
                                 ACE_Null_Mutex> &iter =
        this->table_[i]->iter ();

      for (iter.first ();
           !iter.isdone ();
           iter.next ())
        if (iter.item ()->get_type () == type)
          timer_ids[pos++] =
            reinterpret_cast<Hash_Token<TYPE> *> (
              const_cast<void *> (iter.item ()->get_act ()));
    }

  if (pos > this->size_)
    return -1;

  for (i = 0; i < pos; ++i)
    {
      int const result =
        this->table_[timer_ids[i]->pos_]->cancel (timer_ids[i]->orig_id_,
                                                  0,
                                                  dont_call);
      ACE_ASSERT (result == 1);
      ACE_UNUSED_ARG (result);

      // We could destruct Hash_Token explicitly but we better
      // schedule it for destruction.
      this->token_list_.add (timer_ids[i]);

      --this->size_;
    }

  delete [] timer_ids;

  this->find_new_earliest ();

  // Call the close hooks.
  int cookie = 0;

  // cancel_type() called once per <type>.
  this->upcall_functor ().cancel_type (*this,
                                       type,
                                       dont_call,
                                       cookie);

  for (i = 0;
       i < pos;
       ++i)
    {
      // cancel_timer() called once per <timer>.
      this->upcall_functor ().cancel_timer (*this,
                                            type,
                                            dont_call,
                                            cookie);
    }

  return static_cast<int> (pos);
}

// Removes the earliest node and finds the new earliest position

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::remove_first (void)
{
  if (this->is_empty ())
    return 0;

  ACE_Timer_Node_T<TYPE> *temp =
    this->table_[this->earliest_position_]->remove_first ();

  this->find_new_earliest ();

  --this->size_;

  return temp;
}

// Finds a new earliest position

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> void
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::find_new_earliest (void)
{
  for (size_t i = 0; i < this->table_size_; ++i)
    if (!this->table_[i]->is_empty ())
      if (this->table_[this->earliest_position_]->is_empty ()
          || this->earliest_time () == ACE_Time_Value::zero
          || this->table_[i]->earliest_time () <= this->earliest_time ())
          this->earliest_position_ = i;
}

// Returns the earliest node without removing it

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> ACE_Timer_Node_T<TYPE> *
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::get_first (void)
{
  ACE_TRACE ("ACE_Timer_Hash_T::get_first");

  if (this->is_empty ())
    return 0;

  return this->table_[this->earliest_position_]->get_first ();
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> void
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::free_node (ACE_Timer_Node_T<TYPE> *node)
{
  ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK>::free_node (node);

  Hash_Token<TYPE> *h =
    reinterpret_cast<Hash_Token<TYPE> *> (const_cast<void *> (node->get_act ()));
  this->token_list_.add (h);
}

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::dispatch_info_i (const ACE_Time_Value &cur_time,
                                                                    ACE_Timer_Node_Dispatch_Info_T<TYPE> &info)
{
  int const result =
    ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK>::dispatch_info_i (cur_time,
                                                               info);

  if (result == 1)
    {
      Hash_Token<TYPE> *h =
        reinterpret_cast<Hash_Token<TYPE> *> (const_cast<void *> (info.act_));

      info.act_ = h->act_;
    }

  return result;
}

// Dummy version of expire to get rid of warnings in Sun CC 4.2

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::expire ()
{
  return ACE_Timer_Queue_T<TYPE,FUNCTOR,ACE_LOCK>::expire();
}

// Specialized expire for Timer Hash

template <class TYPE, class FUNCTOR, class ACE_LOCK, class BUCKET> int
ACE_Timer_Hash_T<TYPE, FUNCTOR, ACE_LOCK, BUCKET>::expire (const ACE_Time_Value &cur_time)
{
  ACE_TRACE ("ACE_Timer_Hash_T::expire");

  int number_of_timers_expired = 0;

  ACE_Timer_Node_T<TYPE> *expired = 0;

  ACE_MT (ACE_GUARD_RETURN (ACE_LOCK, ace_mon, this->mutex_, -1));

  // Go through the table and expire anything that can be expired

  for (size_t i = 0;
       i < this->table_size_;
       ++i)
    {
      while (!this->table_[i]->is_empty ()
             && this->table_[i]->earliest_time () <= cur_time)
        {
          expired = this->table_[i]->remove_first ();
          const void *act = expired->get_act ();
          bool reclaim = true;

          Hash_Token<TYPE> *h =
            reinterpret_cast<Hash_Token<TYPE> *> (const_cast<void *> (act));

          ACE_ASSERT (h->pos_ == i);

#if 0
          ACE_DEBUG ((LM_DEBUG, "Hash::expire() expiring %d in slot %d where it's id is %d and token is %x\n",
                      expired->get_timer_value ().msec (),
                      h->pos_,
                      h->orig_id_,
                      h));
#endif

          // Check if this is an interval timer.
          if (expired->get_interval () > ACE_Time_Value::zero)
            {
              // Make sure that we skip past values that have already
              // "expired".
              do
                expired->set_timer_value (expired->get_timer_value ()
                                          + expired->get_interval ());
              while (expired->get_timer_value () <= cur_time);

              // Since this is an interval timer, we need to
              // reschedule it.
              this->reschedule (expired);
              reclaim = false;
            }
          else
            {
              this->free_node (expired);
            }

          ACE_Timer_Node_Dispatch_Info_T<TYPE> info;

          // Get the dispatch info
          expired->get_dispatch_info (info);

          info.act_ = h->act_;

          const void *upcall_act = 0;

          this->preinvoke (info, cur_time, upcall_act);

          this->upcall (info, cur_time);

          this->postinvoke (info, cur_time, upcall_act);

          if (reclaim)
            {
              --this->size_;
            }

          ++number_of_timers_expired;
         }
    }

  if (number_of_timers_expired > 0)
    this->find_new_earliest ();

  return number_of_timers_expired;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_TIMER_HASH_T_CPP */

