// $Id: Token.cpp 96024 2012-08-09 19:42:19Z schmidt $

#include "ace/Token.h"

#if !defined (__ACE_INLINE__)
# include "ace/Token.inl"
#endif /* __ACE_INLINE__ */



#if defined (ACE_HAS_THREADS)

#include "ace/Thread.h"
#include "ace/Log_Msg.h"

#if defined (ACE_TOKEN_DEBUGGING)
// FUZZ: disable check_for_streams_include
#include "ace/streams.h"
#endif /* ACE_TOKEN_DEBUGGING */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Token)

void
ACE_Token::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nthread = %d"), ACE_Thread::self ()));
  // @@ Is there a portable way to do this?
  // ACE_DEBUG ((LM_DEBUG, "\nowner_ = %d", (long) this->owner_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nowner_ addr = %x"), &this->owner_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nwaiters_ = %d"), this->waiters_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nin_use_ = %d"), this->in_use_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("\nnesting level = %d"), this->nesting_level_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Token::ACE_Token_Queue_Entry::ACE_Token_Queue_Entry (ACE_Thread_Mutex &m,
                                                         ACE_thread_t t_id)
  : next_ (0),
    thread_id_ (t_id),
#if defined (ACE_TOKEN_USES_SEMAPHORE)
    cv_ (0),
#else
    cv_ (m),
#endif /* ACE_TOKEN_USES_SEMAPHORE */
    runable_ (0)
{
#if defined (ACE_TOKEN_USES_SEMAPHORE)
  ACE_UNUSED_ARG (m);
#endif /* ACE_TOKEN_USES_SEMAPHORE */

  ACE_TRACE ("ACE_Token::ACE_Token_Queue_Entry::ACE_Token_Queue_Entry");
}

ACE_Token::ACE_Token_Queue_Entry::ACE_Token_Queue_Entry (ACE_Thread_Mutex &m,
                                                         ACE_thread_t t_id,
                                                         ACE_Condition_Attributes &attributes)
  : next_ (0),
    thread_id_ (t_id),
#if defined (ACE_TOKEN_USES_SEMAPHORE)
    cv_ (0),
#else
    cv_ (m, attributes),
#endif /* ACE_TOKEN_USES_SEMAPHORE */
    runable_ (0)
{
#if defined (ACE_TOKEN_USES_SEMAPHORE)
  ACE_UNUSED_ARG (m);
  ACE_UNUSED_ARG (attributes);
#endif /* ACE_TOKEN_USES_SEMAPHORE */

  ACE_TRACE ("ACE_Token::ACE_Token_Queue_Entry::ACE_Token_Queue_Entry");
}

ACE_Token::ACE_Token_Queue::ACE_Token_Queue (void)
  : head_ (0),
    tail_ (0)
{
  ACE_TRACE ("ACE_Token::ACE_Token_Queue::ACE_Token_Queue");
}

//
// Remove an entry from the list.  Must be called with locks held.
//
void
ACE_Token::ACE_Token_Queue::remove_entry (ACE_Token::ACE_Token_Queue_Entry *entry)
{
  ACE_TRACE ("ACE_Token::ACE_Token_Queue::remove_entry");
  ACE_Token_Queue_Entry *curr = 0;
  ACE_Token_Queue_Entry *prev = 0;

  if (this->head_ == 0)
    return;

  for (curr = this->head_;
       curr != 0 && curr != entry;
       curr = curr->next_)
    prev = curr;

  if (curr == 0)
    // Didn't find the entry...
    return;
  else if (prev == 0)
    // Delete at the head.
    this->head_ = this->head_->next_;
  else
    // Delete in the middle.
    prev->next_ = curr->next_;

  // We need to update the tail of the list if we've deleted the last
  // entry.
  if (curr->next_ == 0)
    this->tail_ = prev;
}

//
// Add an entry into the list.  Must be called with locks held.
//
void
ACE_Token::ACE_Token_Queue::insert_entry (ACE_Token::ACE_Token_Queue_Entry &entry,
                                          int requeue_position)
{
  if (this->head_ == 0)
    {
      // No other threads - just add me
      this->head_ = &entry;
      this->tail_ = &entry;
    }
  else if (requeue_position == -1)
    {
      // Insert at the end of the queue.
      this->tail_->next_ = &entry;
      this->tail_ = &entry;
    }
  else if (requeue_position == 0)
    {
      // Insert at head of queue.
      entry.next_ = this->head_;
      this->head_ = &entry;
    }
  else
    // Insert in the middle of the queue somewhere.
    {
      // Determine where our thread should go in the queue of waiters.

      ACE_Token::ACE_Token_Queue_Entry *insert_after = this->head_;
      while (requeue_position-- && insert_after->next_ != 0)
        insert_after = insert_after->next_;

      entry.next_ = insert_after->next_;

      if (entry.next_ == 0)
        this->tail_ = &entry;

      insert_after->next_ = &entry;
    }
}

ACE_Token::ACE_Token (const ACE_TCHAR *name, void *any)
  : lock_ (name, (ACE_mutexattr_t *) any),
    owner_ (ACE_OS::NULL_thread),
    in_use_ (0),
    waiters_ (0),
    nesting_level_ (0),
    attributes_ (USYNC_THREAD),
    queueing_strategy_ (FIFO)
{
//  ACE_TRACE ("ACE_Token::ACE_Token");
}

ACE_Token::~ACE_Token (void)
{
  ACE_TRACE ("ACE_Token::~ACE_Token");
}

int
ACE_Token::shared_acquire (void (*sleep_hook_func)(void *),
                           void *arg,
                           ACE_Time_Value *timeout,
                           ACE_Token_Op_Type op_type)
{
  ACE_TRACE ("ACE_Token::shared_acquire");
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1);

#if defined (ACE_TOKEN_DEBUGGING)
  this->dump ();
#endif /* ACE_TOKEN_DEBUGGING */

  ACE_thread_t const thr_id = ACE_Thread::self ();

  // Nobody holds the token.
  if (!this->in_use_)
    {
      // Its mine!
      this->in_use_ = op_type;
      this->owner_ = thr_id;
      return 0;
    }

  // Someone already holds the token.

  // Check if it is us.
  if (ACE_OS::thr_equal (thr_id, this->owner_))
    {
      ++this->nesting_level_;
      return 0;
    }

  // Do a quick check for "polling" behavior.
  if (timeout != 0 && *timeout == ACE_Time_Value::zero)
    {
      errno = ETIME;
      return -1;
    }

  //
  // We've got to sleep until we get the token.
  //

  // Which queue we should end up in...
  ACE_Token_Queue *queue = (op_type == ACE_Token::READ_TOKEN
                            ? &this->readers_
                            : &this->writers_);

  // Allocate queue entry on stack.  This works since we don't exit
  // this method's activation record until we've got the token.
  ACE_Token::ACE_Token_Queue_Entry my_entry (this->lock_,
                                             thr_id,
                                             this->attributes_);
  queue->insert_entry (my_entry, this->queueing_strategy_);
  ++this->waiters_;

  // Execute appropriate <sleep_hook> callback.  (@@ should these
  // methods return a success/failure status, and if so, what should
  // we do with it?)
  int ret = 0;
  if (sleep_hook_func)
    {
      (*sleep_hook_func) (arg);
      ++ret;
    }
  else
    {
      // Execute virtual method.
      this->sleep_hook ();
      ++ret;
    }

  bool timed_out = false;
  bool error = false;

  // Sleep until we've got the token (ignore signals).
  do
    {
      int const result = my_entry.wait (timeout, this->lock_);

      if (result == -1)
        {
          // Note, this should obey whatever thread-specific interrupt
          // policy is currently in place...
          if (errno == EINTR)
            continue;

#if defined (ACE_TOKEN_DEBUGGING)
          cerr << '(' << ACE_Thread::self () << ')'
               << " acquire: "
               << (errno == ETIME ? "timed out" : "error occurred")
               << endl;
#endif /* ACE_TOKEN_DEBUGGING */

          // We come here if a timeout occurs or some serious
          // ACE_Condition object error.
          if (errno == ETIME)
            timed_out = true;
          else
            error = true;

          // Stop the loop.
          break;
        }
    }
  while (!ACE_OS::thr_equal (thr_id, this->owner_));

  // Do this always and irrespective of the result of wait().
  --this->waiters_;
  queue->remove_entry (&my_entry);

#if defined (ACE_TOKEN_DEBUGGING)
  ACE_DEBUG ((LM_DEBUG, "(%t) ACE_Token::shared_acquire (UNBLOCKED)\n"));
#endif /* ACE_TOKEN_DEBUGGING */

  // If timeout occured
  if (timed_out)
    {
      // This thread was still selected to own the token.
      if (my_entry.runable_)
        {
          // Wakeup next waiter since this thread timed out.
          this->wakeup_next_waiter ();
        }

      // Return error.
     return -1;
    }
  else if (error)
    {
      // Return error.
      return -1;
    }

  // If this is a normal wakeup, this thread should be runnable.
  ACE_ASSERT (my_entry.runable_);

  return ret;
}

// By default this is a no-op.

/* virtual */
void
ACE_Token::sleep_hook (void)
{
  ACE_TRACE ("ACE_Token::sleep_hook");
}

int
ACE_Token::acquire (ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Token::acquire");
  return this->shared_acquire (0, 0, timeout, ACE_Token::WRITE_TOKEN);
}

// Acquire the token, sleeping until it is obtained or until <timeout>
// expires.

int
ACE_Token::acquire (void (*sleep_hook_func)(void *),
                    void *arg,
                    ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Token::acquire");
  return this->shared_acquire (sleep_hook_func, arg, timeout, ACE_Token::WRITE_TOKEN);
}

// Try to renew the token.

int
ACE_Token::renew (int requeue_position,
                  ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Token::renew");
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1);

#if defined (ACE_TOKEN_DEBUGGING)
  this->dump ();
#endif /* ACE_TOKEN_DEBUGGING */
  // ACE_ASSERT (ACE_OS::thr_equal (ACE_Thread::self (), this->owner_));

  // Check to see if there are any waiters worth giving up the lock
  // for.

  // If no writers and either we are a writer or there are no readers.
  if (this->writers_.head_ == 0 &&
      (this->in_use_ == ACE_Token::WRITE_TOKEN ||
       this->readers_.head_ == 0))
    // Immediate return.
    return 0;

  // We've got to sleep until we get the token again.

  // Determine which queue should this thread go to.
  ACE_Token::ACE_Token_Queue *this_threads_queue =
    this->in_use_ == ACE_Token::READ_TOKEN ?
    &this->readers_ : &this->writers_;

  ACE_Token::ACE_Token_Queue_Entry my_entry (this->lock_,
                                             this->owner_);

  this_threads_queue->insert_entry (my_entry,
                                    // if requeue_position == 0 then we want to go next,
                                    // otherwise use the queueing strategy, which might also
                                    // happen to be 0.
                                    requeue_position == 0 ? 0 : this->queueing_strategy_);
  ++this->waiters_;

  // Remember nesting level...
  int const save_nesting_level_ = this->nesting_level_;

  // Reset state for new owner.
  this->nesting_level_ = 0;

  // Wakeup waiter.
  this->wakeup_next_waiter ();

  bool timed_out = false;
  bool error = false;

  // Sleep until we've got the token (ignore signals).
  do
    {
      int const result = my_entry.wait (timeout, this->lock_);

      if (result == -1)
        {
          // Note, this should obey whatever thread-specific interrupt
          // policy is currently in place...
          if (errno == EINTR)
            continue;

#if defined (ACE_TOKEN_DEBUGGING)
          cerr << '(' << ACE_Thread::self () << ')'
               << " renew: "
               << (errno == ETIME ? "timed out" : "error occurred")
               << endl;
#endif /* ACE_TOKEN_DEBUGGING */

          // We come here if a timeout occurs or some serious
          // ACE_Condition object error.
          if (errno == ETIME)
            timed_out = true;
          else
            error = true;

          // Stop the loop.
          break;
        }
    }
  while (!ACE_OS::thr_equal (my_entry.thread_id_, this->owner_));

  // Do this always and irrespective of the result of wait().
  --this->waiters_;
  this_threads_queue->remove_entry (&my_entry);

#if defined (ACE_TOKEN_DEBUGGING)
  ACE_DEBUG ((LM_DEBUG, "(%t) ACE_Token::renew (UNBLOCKED)\n"));
#endif /* ACE_TOKEN_DEBUGGING */

  // If timeout occured
  if (timed_out)
    {
      // This thread was still selected to own the token.
      if (my_entry.runable_)
        {
          // Wakeup next waiter since this thread timed out.
          this->wakeup_next_waiter ();
        }

      // Return error.
     return -1;
    }
  else if (error)
    {
      // Return error.
      return -1;
    }

  // If this is a normal wakeup, this thread should be runnable.
  ACE_ASSERT (my_entry.runable_);

  // Reinstate nesting level.
  this->nesting_level_ = save_nesting_level_;

  return 0;
}

// Release the current holder of the token (which had
// better be the caller's thread!).

int
ACE_Token::release (void)
{
  ACE_TRACE ("ACE_Token::release");
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1);

#if defined (ACE_TOKEN_DEBUGGING)
  this->dump ();
#endif /* ACE_TOKEN_DEBUGGING */

  // Nested release...
  if (this->nesting_level_ > 0)
    --this->nesting_level_;
  else
    {
      //
      // Regular release...
      //

      // Wakeup waiter.
      this->wakeup_next_waiter ();
    }

  return 0;
}

void
ACE_Token::wakeup_next_waiter (void)
{
  ACE_TRACE ("ACE_Token::wakeup_next_waiter");

  // Reset state for new owner.
  this->owner_ = ACE_OS::NULL_thread;
  this->in_use_ = 0;

  // Any waiters...
  if (this->writers_.head_ == 0 &&
      this->readers_.head_ == 0)
    {
      // No more waiters...
      return;
    }

  // Wakeup next waiter.
  ACE_Token_Queue *queue = 0;

  // Writer threads get priority to run first.
  if (this->writers_.head_ != 0)
    {
      this->in_use_ = ACE_Token::WRITE_TOKEN;
      queue = &this->writers_;
    }
  else
    {
      this->in_use_ = ACE_Token::READ_TOKEN;
      queue = &this->readers_;
    }

  // Wake up waiter and make it runable.
  queue->head_->runable_ = 1;
  queue->head_->signal ();
  this->owner_ = queue->head_->thread_id_;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
