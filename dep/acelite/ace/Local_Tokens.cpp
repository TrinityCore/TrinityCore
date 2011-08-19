// $Id: Local_Tokens.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/Local_Tokens.h"

#if defined (ACE_HAS_TOKENS_LIBRARY)

#include "ace/Thread.h"
#include "ace/Token_Manager.h"
#include "ace/OS_NS_unistd.h"

#if !defined (__ACE_INLINE__)
#include "ace/Local_Tokens.inl"
#endif /* __ACE_INLINE__ */


ACE_BEGIN_VERSIONED_NAMESPACE_DECL

void
ACE_Tokens::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Tokens::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Tokens::dump:\n")
                        ACE_TEXT (" reference_cont_ = %d\n")
                        ACE_TEXT (" token_name_ = %s\n"),
                        reference_count_, token_name_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("waiters_\n")));
  this->waiters_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Tokens::ACE_Tokens (void)
  : visited_ (0),
    reference_count_ (0)
{
  ACE_TRACE ("ACE_Tokens::ACE_Tokens");
}

ACE_Tokens::~ACE_Tokens (void)
{
}

void
ACE_Tokens::make_owner (ACE_TPQ_Entry *caller)
{
  this->waiters_.remove (caller);
  this->waiters_.enqueue (caller, 0);
}

ACE_Token_Proxy_Queue *
ACE_Tokens::waiters ()
{
  ACE_TRACE ("ACE_Tokens::waiters");
  return &this->waiters_;
}

int
ACE_Tokens::no_of_waiters ()
{
  ACE_TRACE ("ACE_Tokens::no_of_waiters");
  return this->waiters_.size ();
}

#if defined (ACE_LACKS_INLINE_FUNCTIONS)
ACE_Null_Token::ACE_Null_Token (void)
{
}

ACE_Null_Token::~ACE_Null_Token (void)
{
}
#endif /* ACE_LACKS_INLINE_FUNCTIONS */

void
ACE_TPQ_Entry::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TPQ_Entry::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("ACE_TPQ_Entry::dump:\n")
              ACE_TEXT (" nesting_level_ = %d\n")
              ACE_TEXT (" client_id_ = %s\n"),
              nesting_level_,
              client_id_));

  if (next_ != 0)
    {
      ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("next:.\n")));
      next_->dump ();
    }

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_TPQ_Entry::dump end.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_TPQ_Entry::ACE_TPQ_Entry (const ACE_Token_Proxy *new_proxy,
                              const ACE_TCHAR *client_id)
  : cond_var_ (lock_),
    next_ (0),
    // This const typecast is safe.
    proxy_ ((ACE_Token_Proxy *) new_proxy),
    nesting_level_ (0),
    sleep_hook_ (0)
{
  ACE_TRACE ("ACE_TPQ_Entry::ACE_TPQ_Entry");

  if (client_id != 0)
    this->client_id (client_id);
  else
    {
      // Just make sure we have enough space.
      ACE_TCHAR host_name[MAXHOSTNAMELEN];
      ACE_TCHAR name[(sizeof host_name / sizeof (ACE_TCHAR)) + 256];
      ACE_OS::hostname (host_name, sizeof host_name);

      ACE_thread_t thread_id = ACE_Thread::self ();

      // The cast is an attempt to get this to compile (and run,
      // hopefully) regardless of the type of ACE_thread_t.
      ACE_OS::sprintf (name,
                       ACE_TEXT ("/%s/%u/%lu"),
                       host_name,
                       static_cast<u_int> (ACE_OS::getpid ()),
                       *reinterpret_cast<u_long *> (&thread_id));

      this->client_id (name);
    }
}

ACE_TPQ_Entry::ACE_TPQ_Entry (void)
  : cond_var_ (lock_),
    proxy_ (0),
    nesting_level_ (0),
    sleep_hook_ (0)
{
  ACE_TRACE ("ACE_TPQ_Entry::ACE_TPQ_Entry null const.");
}

ACE_TPQ_Entry::ACE_TPQ_Entry (const ACE_TPQ_Entry &rhs)
: cond_var_ (lock_)
{
  ACE_TRACE ("ACE_TPQ_Entry::ACE_TPQ_Entry copy const.");
  *this = rhs;
}

ACE_TPQ_Entry::~ACE_TPQ_Entry (void)
{
  ACE_TRACE ("ACE_TPQ_Entry::~ACE_TPQ_Entry");
}

void
ACE_TPQ_Entry::operator= (const ACE_TPQ_Entry& rhs)
{
  ACE_TRACE ("ACE_TPQ_Entry::operator=");
  if (&rhs == this)
    return;
  this->proxy_ = rhs.proxy ();
  this->nesting_level_ = rhs.nesting_level ();
  this->client_id (rhs.client_id ());
  this->sleep_hook_ = rhs.sleep_hook ();
}

void
ACE_TPQ_Entry::client_id (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_TPQ_Entry::client_id");

  if (id == 0)
    return;

  ACE_OS::strsncpy (this->client_id_,
                    (ACE_TCHAR *) id,
                    ACE_MAXCLIENTIDLEN);
}

ACE_TSS_TPQ_Entry::~ACE_TSS_TPQ_Entry (void)
{
}

void
ACE_TSS_TPQ_Entry::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TSS_TPQ_Entry::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_TSS_TPQ_Entry::dump:\n")
                        ACE_TEXT (" client_id_ = %s\n"),
                        client_id_ == 0 ? ACE_TEXT ("0") : client_id_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_TPQ_ENTRY::dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_TSS_TPQ_Entry::ACE_TSS_TPQ_Entry (const ACE_Token_Proxy *proxy,
                                      const ACE_TCHAR *client_id)
: proxy_ (proxy),
  client_id_ (client_id)
{
  ACE_TRACE ("ACE_TSS_TPQ_Entry::ACE_TSS_TPQ_Entry");
}

ACE_TPQ_Entry *
ACE_TSS_TPQ_Entry::make_TSS_TYPE (void) const
{
  ACE_TRACE ("ACE_TSS_TPQ_Entry::make_TSS_TYPE");
  ACE_TPQ_Entry *temp;

  ACE_NEW_RETURN (temp,
                  ACE_TPQ_Entry (this->proxy_,
                                 this->client_id_),
                  0);
  return temp;
}

ACE_TSS_TPQ_Entry::operator ACE_TPQ_Entry * (void)
{
#if !defined (ACE_NO_TSS_TOKENS)
  return  (ACE_TPQ_Entry *) (*((ACE_TSS<ACE_TPQ_Entry> *) this));
#else
  // Not sure this is the right thing to do, but it seems to work.
  // The base class ALSO has a proxy_ and client_id_ members (weird?)
  // which don't get initialised.  The following two lines make this
  // the same as the subclass, so that the slicing works .
  ACE_TPQ_ENTRY::proxy ((ACE_Token_Proxy *)(this->proxy_));
  ACE_TPQ_ENTRY::client_id (this->client_id_);
  return  (ACE_TPQ_Entry *) this;;
#endif /* !ACE_NO_TSS_TOKENS */
}

ACE_TPQ_Iterator::ACE_TPQ_Iterator (ACE_Token_Proxy_Queue &q)
  : current_ (q.head_)
{
  ACE_TRACE ("ACE_TPQ_Iterator::ACE_TPQ_Iterator");
}

int
ACE_TPQ_Iterator::next (ACE_TPQ_Entry *&next_item)
{
  ACE_TRACE ("ACE_TPQ_Iterator::next");

  next_item = this->current_;

  return current_ != 0;
}

int
ACE_TPQ_Iterator::done (void) const
{
  ACE_TRACE ("ACE_TPQ_Iterator::done");

  return this->current_ == 0;
}

void
ACE_TPQ_Iterator::advance (void)
{
  ACE_TRACE ("ACE_TPQ_Iterator::advance");

  if (current_ != 0)
    this->current_ = this->current_->next_;
}

void
ACE_TPQ_Iterator::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_TPQ_Iterator::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_TPQ_Iterator::dump:\n")
              ACE_TEXT (" current_ = %d\n"),
              (long) this->current_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("head_ and tail_\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

void
ACE_Token_Proxy_Queue::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token_Proxy_Queue::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Token_Proxy_Queue::dump:\n")
                        ACE_TEXT (" size_ = %d\n"),
                        size_));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("head_ and tail_\n")));
  if (this->head_ != 0)
    this->head_->dump ();

  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Token_Proxy_Queue::dump end.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Token_Proxy_Queue::ACE_Token_Proxy_Queue (void)
  : head_ (0),
    tail_ (0),
    size_ (0)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::ACE_Token_Proxy_Queue");
}

void
ACE_Token_Proxy_Queue::enqueue (ACE_TPQ_Entry *tpq,
                                int position)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::enqueue");
  tpq->next_ = 0;

  ++this->size_;

  if (this->head_ == 0)
    {
      // make tpq the entire list
      this->head_ = this->tail_ = tpq;
      return;
    }

  if (position == 0)
    {
      // make head of list
      tpq->next_ = this->head_;
      this->head_ = tpq;
      return;
    }

  if (position == -1)
    {
      // stick at back of list
      this->tail_->next_ = tpq;
      this->tail_ = tpq;
      return;
    }

  // walk through list to insertion point
  ACE_TPQ_Entry *temp = head_;

  for (int x = position;
       x > 1;
       --x)
    {
      // end of queue?
      if (temp->next_ == 0)
        break;
      // advance pointer
      else
        temp = temp->next_;
    }

  // insert new tpq after temp
  tpq->next_ = temp->next_;
  temp->next_ = tpq;
}

void
ACE_Token_Proxy_Queue::dequeue (void)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::dequeue");

  if (head_ == 0)
    return;

  ACE_TPQ_Entry *temp = this->head_;

  this->head_ = this->head_->next_;

  temp->next_ = 0;

  --this->size_;

  if (this->head_ == 0 && this->size_ != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("incorrect size = %d\n"),
                this->size_));
}

/*
int
ACE_Token_Proxy_Queue::member (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::member");

  for (ACE_TPQ_Entry *temp = this->head_;
       temp != 0;
       temp = temp->next_)
    if (ACE_OS::strcmp (temp->client_id (), id) == 0)
      // We found it!
      return 1;

  // We didn't find it :-(
  return 0;
}
*/

void
ACE_Token_Proxy_Queue::remove (const ACE_TPQ_Entry *remove_me)
{
  ACE_TRACE ("ACE_Token_Proxy_Queue::remove");
  // sanity
  if ((remove_me == 0) || (this->head_ == 0))
    return;

  // is it the head?
  if (this->head_ == remove_me) // pointer comparison.
    {
      this->head_ = this->head_->next_;
      if (this->head_ == 0)
        this->tail_ = 0;

      --this->size_;
      return;
    }

  ACE_TPQ_Entry *temp = this->head_;
  ACE_TPQ_Entry *previous = 0;

  // is it in the middle or tail?
  while (temp != 0)
    {
      if (temp == remove_me)
        {
          // previous should never be null since the first if
          // conditional should always be false
          previous->next_ = temp->next_;
          // is it the tail?
          if (this->tail_ == temp)
            this->tail_ = previous;

          --this->size_;
          return;
        }

      previous = temp;
      temp = temp->next_;
    }

  // it wasn't in the list.
  return;
}

void
ACE_Mutex_Token::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Mutex_Token::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Mutex_Token::dump:\n")));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("lock_\n")));
  lock_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Tokens::dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Mutex_Token::dump end.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_Mutex_Token::ACE_Mutex_Token (const ACE_TCHAR *name)
{
  ACE_TRACE ("ACE_Mutex_Token::ACE_Mutex_Token");

  ACE_OS::strsncpy (this->token_name_,
                    name,
                    ACE_MAXTOKENNAMELEN);
}

ACE_Mutex_Token::~ACE_Mutex_Token (void)
{
  ACE_TRACE ("ACE_Mutex_Token::~ACE_Mutex_Token");
}

int
ACE_Mutex_Token::acquire (ACE_TPQ_Entry *caller,
                          int ignore_deadlock,
                          int notify)
{
  ACE_TRACE ("ACE_Mutex_Token::acquire");
  // We need to acquire two locks. This one to ensure that only one
  // thread uses this token at a time.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon1, this->lock_, -1);
  // This one to ensure an atomic transaction across all tokens.  Note
  // that this order is crucial too.  It's resource coloring for other
  // threads which may be calling this same token.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon2, ACE_Token_Manager::instance ()->mutex (), -1);

  // Does _anyone_ own the token?
  if (this->owner () == 0)
    {
      // there are no waiters, so queue as the first waiter (the owner.)
      this->waiters_.enqueue (caller, -1);
      return 0;  // success
    }

  // Does the caller already own it?
  if (this->is_owner (caller->client_id ()))
    {
      // Recursive acquisition.
      caller->nesting_level (1);
      return 0; // success
    }

  // Check for deadlock.
  if (!ignore_deadlock
      && ACE_Token_Manager::instance ()->check_deadlock (caller->proxy ()) == 1)
    {
      errno = EDEADLK;
      ACE_RETURN (-1);
    }

  // Someone owns it. Sorry, you're getting queued up at the end of
  // the waiter queue.
  this->waiters_.enqueue (caller, -1);

  if (notify)
    this->owner ()->call_sleep_hook ();

  errno = EWOULDBLOCK;
  ACE_RETURN (-1);

  ACE_NOTREACHED (return -1);
}

int
ACE_Mutex_Token::tryacquire (ACE_TPQ_Entry *caller)
{
  ACE_TRACE ("ACE_Mutex_Token::tryacquire");
  // We need to acquire two locks. This one to ensure that only one
  // thread uses this token at a time.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon1, this->lock_, -1);
  // This one to ensure an atomic transaction across all tokens.  Note
  // that this order is crucial too.  It's resource coloring for other
  // threads which may be calling this same token.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon2, ACE_Token_Manager::instance ()->mutex (), -1);

  // Does _anyone_ own the token?
  if (this->owner () == 0)
    {
      this->waiters_.enqueue (caller, -1);
      return 0;  // success
    }
  // Does the caller already own it?
  if (this->is_owner (caller->client_id ()))
    {
      // recursive acquisition
      caller->nesting_level (1);
      return 0;  // success
    }
  else
    // Someone owns it.  Fail.
    {
      errno = EWOULDBLOCK;
      ACE_RETURN (-1);
    }

  ACE_NOTREACHED (return -1);
}

int
ACE_Mutex_Token::renew (ACE_TPQ_Entry *caller,
                        int requeue_position)
{
  ACE_TRACE ("ACE_Mutex_Token::renew");
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_, -1);

  // Verify that the caller is the owner.
  if (this->is_owner (caller->client_id ()) == 0)
    {
      errno = EACCES;
      ACE_RETURN (-1);
    }

  // The caller is the owner, so check to see if there are any
  // waiters.  If not, we just keep the token.  == 1 means that there
  // is only the owner.
  if (this->waiters_.size () == 1 || requeue_position == 0)
    return 0;

  // Requeue the caller.
  this->waiters_.dequeue ();

  this->waiters_.enqueue (caller, requeue_position);

  // Notify new owner.
  if (this->owner () != 0)
    this->owner ()->proxy ()->token_acquired (this->owner ());

  // Tell the caller that the operation would block.
  errno = EWOULDBLOCK;
  ACE_RETURN (-1);

  ACE_NOTREACHED (return -1);
}

// Release the current holder of the token (which had
// better be the caller's thread!).

int
ACE_Mutex_Token::release (ACE_TPQ_Entry *caller)
{
  ACE_TRACE ("ACE_Mutex_Token::release");
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_, -1);

  // Does anyone own the token?
  if (this->owner () == 0)
    {
      errno = EACCES;
      ACE_RETURN (-1);
    }

  // Is the caller the owner.
  if (this->is_owner (caller->client_id ()))
    {
      // Check the nesting level.
      if (caller->nesting_level () > 0)
        caller->nesting_level (-1);
      else
        {
          this->waiters_.dequeue ();
          // Notify new owner.
          if (this->owner () != 0)
            this->owner ()->proxy ()->token_acquired (this->owner ());
        }
    }
  else
    this->remove (caller);

  return 0;
}

int
ACE_Mutex_Token::owners (OWNER_STACK &stack,
                         const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_Mutex_Token::owners");
  if (this->owner () != 0)
    {
      stack.push (this->owner ());
      // If an <id> is specified, return whether it is the owner being
      // returned.
      if (id != 0)
        return this->owner ()->equal_client_id (id);
    }

  return 0;
}

int
ACE_Mutex_Token::is_waiting_for (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_Mutex_Token::is_waiting_for");
  // If there is no owner, or <id> is the owner, return false.
  if ((this->owner () == 0) || this->is_owner (id))
    return 0;

  // Step through each waiter looking for <id>.
  ACE_TPQ_Iterator iterator (waiters_);
  iterator.advance ();
  for (ACE_TPQ_Entry *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (temp->equal_client_id (id))
        return 1;
    }

  return 0;
}

int
ACE_Mutex_Token::is_owner (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_Mutex_Token::is_owner");
  // If there is an owner, return whether it is <id>.
  if ((this->owner () != 0) &&
      this->owner ()->equal_client_id (id))
    return 1;
  else
    return 0;
}

int
ACE_Mutex_Token::type (void) const
{
  ACE_TRACE ("ACE_Mutex_Token::type");
  return (int) ACE_Tokens::MUTEX;
}

// ************************************************************

int
ACE_RW_Token::type (void) const
{
  ACE_TRACE ("ACE_RW_Token::type");
  return (int) ACE_Tokens::RWLOCK;
}

void
ACE_RW_Token::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_RW_Token::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_RW_Token::dump:\n")
                        ACE_TEXT ("num_writers_ = %d\n"), num_writers_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("lock_\n")));
  this->lock_.dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("base:\n")));
  ACE_Tokens::dump ();
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_RW_Token::dump end.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_RW_Token::ACE_RW_Token (const ACE_TCHAR *name)
: num_writers_ (0)
{
  ACE_TRACE ("ACE_RW_Token::ACE_RW_Token");

  ACE_OS::strsncpy (this->token_name_,
                    name,
                    ACE_MAXTOKENNAMELEN);
}

ACE_RW_Token::~ACE_RW_Token (void)
{
  ACE_TRACE ("ACE_RW_Token::~ACE_RW_Token");
}

int
ACE_RW_Token::acquire (ACE_TPQ_Entry *caller,
                       int ignore_deadlock,
                       int notify)
{
  ACE_TRACE ("ACE_RW_Token::acquire");
  // We need to acquire two locks. This one to ensure that only one
  // thread uses this token at a time.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon1, this->lock_, -1);
  // This one to ensure an atomic transaction across all tokens.  Note
  // that this order is crucial too.  It's resource coloring for other
  // threads which may be calling this same token.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon2, ACE_Token_Manager::instance ()->mutex (), -1);

  if (caller->proxy ()->type () == ACE_RW_Token::WRITER)
    this->num_writers_++;

  // Does _anyone_ own the token?
  if (this->owner () == 0)
    {
      // There are no waiters, so queue as the first waiter (the owner).
      this->waiters_.enqueue (caller, -1);
      return 0;
    }

  // Check for recursive acquisition.
  if (this->is_owner (caller->client_id ()))
    {
      caller->nesting_level (1);
      return 0;  // Success.
    }

  // Reader.
  if (caller->proxy ()->type () == ACE_RW_Token::READER)
    {
      // Are there any writers?
      if (this->num_writers_ == 0)
        {
          // Queue the caller at the end of the queue.
          this->waiters_.enqueue (caller, -1);
          return 0;
        }
      // Else failure.
    }

  // Failure code.

  // Check for deadlock.
  if (!ignore_deadlock &&
      ACE_Token_Manager::instance ()->check_deadlock (caller->proxy ()) == 1)
    {
      if (caller->proxy ()->type () == ACE_RW_Token::WRITER)
        this->num_writers_--;
      errno = EDEADLK;
      ACE_RETURN (-1);
    }

  // Queue the caller at the end of the queue.
  this->waiters_.enqueue (caller, -1);

  if (notify)
    {
      // If it's a writer, just notify it.
      if (this->owner ()->proxy ()->type () == ACE_RW_Token::WRITER)
        this->owner ()->call_sleep_hook ();
      else
        {
          // Call back all reader owners.
          ACE_TPQ_Entry *temp = this->owner ();
          do
            {
              temp->call_sleep_hook ();
              temp = temp->next_;
            }
          while (temp != 0 &&
                 temp->proxy ()->type () == ACE_RW_Token::READER);
        }
    }

  errno = EWOULDBLOCK;
  ACE_RETURN (-1);

  ACE_NOTREACHED (return -1);
}

int
ACE_RW_Token::tryacquire (ACE_TPQ_Entry *caller)
{
  ACE_TRACE ("ACE_RW_Token::tryacquire");
  // We need to acquire two locks. This one to ensure that only one
  // thread uses this token at a time.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon1, this->lock_, -1);
  // This one to ensure an atomic transaction across all tokens.  Note
  // that this order is crucial too.  It's resource coloring for other
  // threads which may be calling this same token.
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon2, ACE_Token_Manager::instance ()->mutex (), -1);

  if (caller->proxy ()->type () == ACE_RW_Token::WRITER)
    {
      this->num_writers_++;
    }

  // Does _anyone_ own the token?
  if (this->owner () == 0)
    {
      // There are no waiters, so queue as the first waiter (the owner).
      this->waiters_.enqueue (caller, -1);
      return 0;
    }

  // Check for recursive acquisition.
  if (this->is_owner (caller->client_id ()))
    {
      caller->nesting_level (1);
      return 0;  // Success.
    }

  // Reader.
  if (caller->proxy ()->type () == ACE_RW_Token::READER)
    {
      // Are there any writers?
      if (this->num_writers_ == 0)
        {
          // queue the caller at the end of the queue.
          this->waiters_.enqueue (caller, -1);
          return 0;
        }
      // Else, fail.
    }
  else // Writer.
    // We're going to fail, so decrement the num_writers.
    {
      this->num_writers_--;
    }


  errno = EWOULDBLOCK;
  ACE_RETURN (-1);

  ACE_NOTREACHED (return -1);
}

int
ACE_RW_Token::renew (ACE_TPQ_Entry *caller,
                     int requeue_position)
{
  ACE_TRACE ("ACE_RW_Token::renew");
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_, -1);

  // Werify that the caller is the owner
  if (this->is_owner (caller->client_id ()) == 0)
    {
      errno = EACCES;
      ACE_RETURN (-1);
    }

  // The caller is the owner, so check to see if there are any
  // waiters.  If not, we just keep the token.
  if (this->waiters_.size () == 1 || requeue_position == 0)
    return 0;

  // There are waiters, so remove the caller.
  this->remove (caller);

  // Requeue the caller.
  this->waiters_.enqueue (caller, requeue_position);

  if (caller->proxy ()->type () == ACE_RW_Token::READER)
    {
      // If the caller got queued before any writers, the caller is
      // still the owner.
      if (this->is_owner (caller->client_id ()))
        return 0; // success
      // else fallthrough and return would block.
    }
  // Writers will always have to block since waiters_.size () == 1 or
  // requeue_position == 0.

  // Get a new owner.
  this->notify_new_owner (caller);

  // Tell the caller that the operation would block.
  errno = EWOULDBLOCK;
  ACE_RETURN (-1);

  ACE_NOTREACHED (return -1);
}

int
ACE_RW_Token::release (ACE_TPQ_Entry *caller)
{
  ACE_TRACE ("ACE_RW_Token::release");
  ACE_GUARD_RETURN (ACE_TOKEN_CONST::MUTEX, ace_mon, this->lock_, -1);

  // Check for errors.
  if ((this->owner () == 0) ||
      (this->is_owner (caller->client_id ()) == 0))
    {
      errno = EACCES;
      ACE_RETURN (-1);
    }

  if (caller->proxy ()->type () == ACE_RW_Token::WRITER)
    num_writers_--;

  // Recursive release.
  if (caller->nesting_level () > 0)
    {
      caller->nesting_level (-1);
      return 0;
    }

  // Remove the caller and notify the new owner(s).
  this->remove (caller);
  this->notify_new_owner (caller);

  return 0;
}

void
ACE_RW_Token::notify_new_owner (ACE_TPQ_Entry *old_owner)
{
  ACE_TRACE ("ACE_RW_Token::notify_new_owner");

  if (this->owner () == 0)
    return;

  if (this->owner ()->proxy ()->type () == ACE_RW_Token::READER)
    {
      if (old_owner->proxy ()->type () == ACE_RW_Token::READER)
        // the owners already know that they're owners
        return;

      // The current owner is a reader and the previous owner was a
      // writer, so notify all waiting readers up to the first writer.
      // call back all reader owners.
      ACE_TPQ_Iterator iterator (waiters_);
      for (ACE_TPQ_Entry *temp = 0;
           iterator.next (temp) != 0;
           iterator.advance ())
        {
          if (temp->proxy ()->type () == WRITER)
            // We've gone through all the readers.
            break;

          temp->proxy ()->token_acquired (temp);
        }
    }
  else // writer
    this->owner ()->proxy ()->token_acquired (this->owner ());
}


int
ACE_RW_Token::owners (OWNER_STACK &stack,
                      const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_RW_Token::owners");

  if (this->owner () == 0)
    return 0;

  int id_is_owner = 0;

  // The first waiter is a writer, so there is only one owner.
  if (this->owner ()->proxy ()->type () == WRITER)
    {
      stack.push (this->owner ());
      // If an <id> is specified, return whether it is the owner being
      // returned.
      if ((id != 0) &&
          (ACE_OS::strcmp (id, this->owner ()->client_id ()) == 0))
        id_is_owner = 1;
    }
  // The first waiter is a reader, so there can be multiple owning
  // readers.
  else
    {
      ACE_TPQ_Iterator iterator (waiters_);
      for (ACE_TPQ_Entry *temp = 0;
           iterator.next (temp) != 0;
           iterator.advance ())
        {
          if (temp->proxy ()->type () == WRITER)
            // We've gone through all the readers.
            break;

          stack.push (temp);

          if (!id_is_owner && (id != 0) &&
              (ACE_OS::strcmp (id, temp->client_id ()) == 0))
            id_is_owner = 1;
        }
    }

  return id_is_owner;
}

int
ACE_RW_Token::is_waiting_for (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_RW_Token::is_waiting_for");
  // If there is no owner, or <id> is the owner, return false.
  if ((this->owner () == 0) ||
      this->is_owner (id))
    return 0;

  // Step through each waiter looking for <id>.
  ACE_TPQ_Iterator iterator (waiters_);
  iterator.advance ();
  for (ACE_TPQ_Entry *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (temp->equal_client_id (id))
        return 1;
    }

  return 0;
}

int
ACE_RW_Token::is_owner (const ACE_TCHAR *id)
{
  ACE_TRACE ("ACE_RW_Token::is_owner");
  // If there is no owner, return false.
  if (this->owner () == 0)
    return 0;

  // A writer owns us.
  if (this->owner ()->proxy ()->type () == ACE_RW_Token::WRITER)
    return this->owner ()->equal_client_id (id);

  // Readers own us.
  // Step through each owning reader looking for <id>.
  ACE_TPQ_Iterator iterator (waiters_);
  for (ACE_TPQ_Entry *temp = 0;
       iterator.next (temp) != 0;
       iterator.advance ())
    {
      if (temp->proxy ()->type () != ACE_RW_Token::READER)
        break;

      if (temp->equal_client_id (id))
        return 1;
    }

  return 0;
}

void
ACE_Token_Proxy::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token_Proxy::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Token_Proxy::dump:\n")
                        ACE_TEXT (" type = %d\n")
                        ACE_TEXT (" ignore_deadlock_ = %d\n")
                        ACE_TEXT (" debug_ = %d\n"),
                        (int) this->type (), ignore_deadlock_, debug_));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("mutex_, and waiter_\n")));

  if (this->token_ != 0)
    this->token_->dump ();

  this->waiter_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("ACE_Token_Proxy::dump end.\n")));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

const ACE_TCHAR *
ACE_Token_Proxy::client_id (void) const
{
  ACE_TRACE ("ACE_Token_Proxy::client_id");
  // Thread-specific.
  const ACE_TPQ_Entry *temp = this->waiter_.operator->();
  const ACE_TCHAR *id = temp->client_id ();

  if (id == 0)
    return ACE_TEXT ("ERROR NO CLIENT ID");
  else
    return id;
}

void
ACE_Token_Proxy::client_id (const ACE_TCHAR *client_id)
{
  ACE_TRACE ("ACE_Token_Proxy::client_id");
  this->waiter_->client_id (client_id);
}

const ACE_TCHAR *
ACE_Token_Proxy::owner_id (void)
{
  ACE_TRACE ("ACE_Token_Proxy::owner_id");
  return this->token_->owner_id ();
}

const ACE_TCHAR *
ACE_Token_Proxy::name (void) const
{
  ACE_TRACE ("ACE_Token_Proxy::name");
  return this->token_->name ();
}

#if defined (ACE_WIN32_VC8)
#  pragma warning (push)
#  pragma warning (disable:4355)  /* Use of 'this' in initializer list */
#endif
ACE_Token_Proxy::ACE_Token_Proxy (void)
: token_ (0),
  waiter_ (this, 0)
{
  ACE_TRACE ("ACE_Token_Proxy::ACE_Token_Proxy");
}

// Notice the token_ (0).  Do *not* copy the token pointer.  This must
// be obtained through the token manager.  Also, we don't copy any
// waiter info.  A copied Proxy does *not* inherit client_id.

ACE_Token_Proxy::ACE_Token_Proxy (const ACE_Token_Proxy &)
  : token_ (0),
    waiter_ (this, 0)
{
  ACE_TRACE ("ACE_Token_Proxy::ACE_Token_Proxy");
}
#if defined (ACE_WIN32_VC8)
#  pragma warning (pop)
#endif

// @@ should I do a mutex_->release ()?
ACE_Token_Proxy::~ACE_Token_Proxy (void)
{
  ACE_TRACE ("ACE_Token_Proxy::~ACE_Token_Proxy");

  if (token_ != 0)
    // notify token manager that we are done with it so it can
    // free it if necessary
    ACE_Token_Manager::instance ()->release_token (token_);
}

int
ACE_Token_Proxy::open (const ACE_TCHAR *token_name,
                       int ignore_deadlock,
                       int debug)
{
  ACE_TRACE ("ACE_Token_Proxy::open");

  // Store some parameters.
  this->ignore_deadlock_ = ignore_deadlock;
  this->debug_ = debug;

  // Used in case a name was not specified.
  ACE_TCHAR name[BUFSIZ];

  // We must have a name.
  if (token_name == 0)
    {
      ACE_OS::sprintf (name, ACE_TEXT ("token %lx"),
                       reinterpret_cast<long> (this));
      token_name = name;
    }

  // Get or create the underlying token.  The Token Manager will call
  // us back to set token_.
  ACE_Token_Manager::instance ()->get_token (this, token_name);

  // Check for failed get or failed new.
  if (this->token_ == 0)
    {
      errno = ENOMEM;
      ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("Can't allocate mutex")), -1);
    }

  return 0;
}

int
ACE_Token_Proxy::acquire (int notify,
                          void (*sleep_hook)(void *),
                          ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Proxy::acquire");
  if (this->token_ == 0)
    {
      errno = ENOENT;
      ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("Not open.\n")), -1);
    }

  // Make sure no one calls our token_acquired until we have a chance
  // to sleep first!  If after we call an EWOULDBLOCK
  // mutex_->acquire() below, but before we enter handle_options to
  // wait on the cond_var, a thread tries to give take us off the
  // waiter queue and signal us, IT WILL FIRST HAVE TO ACQUIRE THIS
  // cond_var.mutex ().  _This_ is why we acquire it.
  this->waiter_->cond_var_.mutex ().acquire ();

  this->waiter_->sleep_hook (sleep_hook);

  if (this->token_->acquire (this->waiter_, this->ignore_deadlock_, notify) == -1)
    // acquire failed
    {
      switch (errno)
        {
        case EDEADLK :
          if (!ignore_deadlock_)
            {
              waiter_->cond_var_.mutex ().release ();
              errno = EDEADLK;
              ACE_RETURN (-1);
            }
          // Else, fallthrough and block!

        case EWOULDBLOCK :
          if (this->debug_)
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("(%t) waiting for %s, owner is %s, ")
                        ACE_TEXT ("total waiters == %d\n"),
                        this->name (),
                        this->token_->owner_id (),
                        token_->no_of_waiters ()));

          // no error, but would block, if error, return error (-1),
          // otherwise, return whether we called the holder or not.
          int return_value;
          if (this->handle_options (options,
                                    waiter_->cond_var_) == -1)
            return_value = -1;
          else
            return_value = notify == 1;

          errno = EWOULDBLOCK;
          ACE_RETURN (return_value);

        default :
          waiter_->cond_var_.mutex ().release ();
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%p\n"),
                             ACE_TEXT ("Token Proxy acquire.")),
                            -1);
        }
    }
  else
    // we have the token
    {
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("(%t) acquired %s\n"),
                    this->name ()));
      waiter_->cond_var_.mutex ().release ();
    }

  return 0;
}

int
ACE_Token_Proxy::tryacquire (void (*sleep_hook)(void *))
{
  ACE_TRACE ("ACE_Token_Proxy::tryacquire");
  if (this->token_ == 0)
    {
      errno = ENOENT;
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Not open.\n")),
                        -1);
    }

  this->waiter_->sleep_hook (sleep_hook);

  return this->token_->tryacquire (waiter_);
}

int
ACE_Token_Proxy::renew (int requeue_position,
                        ACE_Synch_Options &options)
{
  ACE_TRACE ("ACE_Token_Proxy::renew");
  if (this->token_ == 0)
    {
      errno = ENOENT;
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("Not open.\n")),
                        -1);
    }

  // Make sure no one calls our token_acquired until we have a chance
  // to sleep first!
  this->waiter_->cond_var_.mutex ().acquire ();

  if (this->token_->renew (this->waiter_, requeue_position) == -1)
    {
      // check for error
      if (errno != EWOULDBLOCK)
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%p renew failed\n"), ACE_TEXT ("ACE_Token_Proxy")), -1);

      if (this->debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) renew blocking for %s, owner is %s\n"),
                    this->name (),
                    token_->owner_id ()));

      // no error, but would block, so block or return
      return this->handle_options (options, waiter_->cond_var_);
    }
  else
    // we have the token
    {
      if (this->debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) renewed %s\n"),
                    this->name ()));
      waiter_->cond_var_.mutex ().release ();
      return 0;
    }
}

int
ACE_Token_Proxy::handle_options (ACE_Synch_Options &options,
                                 ACE_TOKEN_CONST::COND_VAR &cv)
{
  // Some operation failed with EWOULDBLOCK.
  ACE_TRACE ("ACE_Token_Proxy::handle_options");

  if (options[ACE_Synch_Options::USE_REACTOR] == 1)
    // Asynchronous.
    {
      // Save/restore errno.
      ACE_Errno_Guard error (errno);
      cv.mutex ().release ();
      ACE_RETURN (-1);
    }
  else
    // Synchronous.
    {
      // Block on condition variable.
      while (cv.wait ((ACE_Time_Value *) options.time_value ()) == -1)
        {
          // Note, this should obey whatever thread-specific
          // interrupt policy is currently in place...
          if (errno == EINTR)
            continue;
          // We come here if a timeout occurs or some serious
          // ACE_Condition object error.
          cv.mutex ().release ();
          ACE_ERROR_RETURN ((LM_ERROR, ACE_TEXT ("condition variable wait")
                             ACE_TEXT (" bombed.")), -1);
        }

      if (this->debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) unblocking %s.\n"),
                    this->client_id ()));
      cv.mutex ().release ();
      return 0;       // operation succeeded
    }
}

int
ACE_Token_Proxy::release (ACE_Synch_Options &)
{
  ACE_TRACE ("ACE_Token_Proxy::release");

  if (this->token_ == 0)
    {
      errno = ENOENT;
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("Must open before releasing.\n")));
      ACE_RETURN (-1);
    }

  if (this->token_->release (waiter_) != 0)
    {
      // Release failed.
      this->token_->remove (this->waiter_);
      if (debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) %p.\n"), ACE_TEXT ("release failed")));
      return -1;
    }
  else
    {
      if (this->debug_)
        ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("(%t) released %s, owner is %s\n"),
                    this->name (),
                    token_->owner_id ()));

      return 0;
    }
}

int
ACE_Token_Proxy::remove (ACE_Synch_Options &)
{
  ACE_TRACE ("ACE_Token_Proxy::remove");
  return 0;
}

void
ACE_Token_Proxy::sleep_hook (void)
{
  ACE_TRACE ("ACE_Token_Proxy::sleep_hook");
  // Somebody wants our token!  (Let'em wait...)
  return;
}

void
ACE_Token_Proxy::token_acquired (ACE_TPQ_Entry *e)
{
  ACE_TRACE ("ACE_Token_Proxy::token_acquired");
  e->cond_var_.mutex ().acquire ();
  // We've been taken off the waiters list and given the token!
  // This implementation signals the internal condition
  // variable. Thus, if asynchronous acquires are used, this must be
  // overriden to do something more useful!
  e->cond_var_.signal ();
  e->cond_var_.mutex ().release ();

  return;
}

int
ACE_Token_Proxy::type (void) const
{
  ACE_TRACE ("ACE_Token_Proxy::type");
  return 0;
}

int
ACE_Token_Proxy::acquire_read (int notify,
                               void (*sleep_hook)(void *),
                               ACE_Synch_Options &options)
{
  return this->acquire (notify,
                        sleep_hook,
                        options);
}

int
ACE_Token_Proxy::acquire_write (int notify,
                                void (*sleep_hook)(void *),
                                ACE_Synch_Options &options)
{
  return this->acquire (notify,
                        sleep_hook,
                        options);
}

int
ACE_Token_Proxy::tryacquire_read (void (*sleep_hook)(void *))
{
  return this->tryacquire (sleep_hook);
}

int
ACE_Token_Proxy::tryacquire_write (void (*sleep_hook)(void *))
{
  return this->tryacquire (sleep_hook);
}

ACE_Token_Name::ACE_Token_Name (const ACE_TCHAR *token_name)
{
  ACE_TRACE ("ACE_Token_Name::ACE_Token_Name");
  this->name (token_name);
}

ACE_Token_Name::ACE_Token_Name (const ACE_Token_Name &rhs)
{
  ACE_TRACE ("ACE_Token_Name::ACE_Token_Name");
  this->name (rhs.name ());
}

ACE_Token_Name::~ACE_Token_Name ()
{
  ACE_TRACE ("ACE_Token_Name::~ACE_Token_Name");
}

void
ACE_Token_Name::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Token_Name::dump");
  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG,  ACE_TEXT ("ACE_Token_Name::dump:\n")
                        ACE_TEXT (" token_name_ = %s\n"),
              token_name_ == 0 ? ACE_TEXT ("no name") : token_name_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// ************************************************************

ACE_Token_Proxy *
ACE_Local_Mutex::clone (void) const
{
  ACE_Token_Proxy *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Local_Mutex (token_->name (),
                                   ignore_deadlock_,
                                   debug_),
                  0);
  return temp;
}

ACE_Tokens *
ACE_Local_Mutex::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Mutex_Token (name),
                  0);
  return temp;
}

ACE_Local_Mutex::~ACE_Local_Mutex (void)
{
}

// ************************************************************

ACE_Local_RLock::~ACE_Local_RLock (void)
{
}

ACE_Tokens *
ACE_Local_RLock::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_RW_Token (name),
                  0);
  return temp;
}

int
ACE_Local_RLock::type (void) const
{
  return ACE_RW_Token::READER;
}

ACE_Token_Proxy *
ACE_Local_RLock::clone (void) const
{
  ACE_Token_Proxy *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Local_RLock (token_->name (),
                                   ignore_deadlock_,
                                   debug_),
                  0);
  return temp;
}

// ************************************************************

ACE_Local_WLock::~ACE_Local_WLock (void)
{
}

ACE_Tokens *
ACE_Local_WLock::create_token (const ACE_TCHAR *name)
{
  ACE_Tokens *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_RW_Token (name),
                  0);
  return temp;
}

int
ACE_Local_WLock::type (void) const
{
  return ACE_RW_Token::WRITER;
}

ACE_Token_Proxy *
ACE_Local_WLock::clone (void) const
{
  ACE_Token_Proxy *temp = 0;
  ACE_NEW_RETURN (temp,
                  ACE_Local_WLock (token_->name (),
                                   ignore_deadlock_,
                                   debug_),
                  0);
  return temp;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TOKENS_LIBRARY */
