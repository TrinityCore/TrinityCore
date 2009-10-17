// -*- C++ -*-
//
// $Id: Token.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/config-macros.h"
#if defined (ACE_HAS_THREADS)
#include "ace/Guard_T.h"
#include "ace/Time_Value.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_Token::queueing_strategy (void)
{
  return this->queueing_strategy_;
}
ACE_INLINE void
ACE_Token::queueing_strategy (int queueing_strategy)
{
  this->queueing_strategy_ = queueing_strategy == -1 ? -1 : 0;
}
ACE_INLINE int
ACE_Token::remove (void)
{
  ACE_TRACE ("ACE_Token::remove");
  // Don't have an implementation for this yet...
  ACE_NOTSUP_RETURN (-1);
}
ACE_INLINE int
ACE_Token::tryacquire (void)
{
  ACE_TRACE ("ACE_Token::tryacquire");
  return this->shared_acquire
    (0, 0, (ACE_Time_Value *) &ACE_Time_Value::zero, ACE_Token::WRITE_TOKEN);
}
ACE_INLINE int
ACE_Token::waiters (void)
{
  ACE_TRACE ("ACE_Token::waiters");
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, -1);
  int const ret = this->waiters_;
  return ret;
}
ACE_INLINE ACE_thread_t
ACE_Token::current_owner (void)
{
  ACE_TRACE ("ACE_Token::current_owner");
  ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, this->lock_, this->owner_);
  return this->owner_;
}
ACE_INLINE int
ACE_Token::acquire_read (void)
{
  ACE_TRACE ("ACE_Token::acquire_read");
  return this->shared_acquire
    (0, 0, 0, ACE_Token::READ_TOKEN);
}
ACE_INLINE int
ACE_Token::acquire_write (void)
{
  ACE_TRACE ("ACE_Token::acquire_write");
  return this->shared_acquire
    (0, 0, 0, ACE_Token::WRITE_TOKEN);
}
ACE_INLINE int
ACE_Token::tryacquire_read (void)
{
  ACE_TRACE ("ACE_Token::tryacquire_read");
  return this->shared_acquire
    (0, 0, (ACE_Time_Value *) &ACE_Time_Value::zero, ACE_Token::READ_TOKEN);
}
ACE_INLINE int
ACE_Token::acquire_read (void (*sleep_hook_func)(void *),
                         void *arg,
                         ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Token::acquire_read");
  return this->shared_acquire (sleep_hook_func, arg, timeout, ACE_Token::READ_TOKEN);
}
ACE_INLINE int
ACE_Token::tryacquire_write (void)
{
  ACE_TRACE ("ACE_Token::tryacquire_write");
  return this->shared_acquire
    (0, 0, (ACE_Time_Value *) &ACE_Time_Value::zero, ACE_Token::WRITE_TOKEN);
}
ACE_INLINE int
ACE_Token::tryacquire_write_upgrade (void)
{
  ACE_TRACE ("ACE_Token::tryacquire_write_upgrade");
  return 0;
}
ACE_INLINE int
ACE_Token::acquire_write (void (*sleep_hook_func)(void *),
                          void *arg,
                          ACE_Time_Value *timeout)
{
  ACE_TRACE ("ACE_Token::acquire_write");
  return this->shared_acquire (sleep_hook_func, arg, timeout, ACE_Token::WRITE_TOKEN);
}
ACE_INLINE int
ACE_Token::ACE_Token_Queue_Entry::wait (ACE_Time_Value *timeout, ACE_Thread_Mutex &lock)
{
#if defined (ACE_TOKEN_USES_SEMAPHORE)
  lock.release ();
  int const retv = (timeout == 0 ?
                    this->cv_.acquire () :
                    this->cv_.acquire (*timeout));
  lock.acquire ();
  return retv;
#else
  ACE_UNUSED_ARG (lock);
  return this->cv_.wait (timeout);
#endif /* ACE_TOKEN_USES_SEMAPHORE */
}
ACE_INLINE int
ACE_Token::ACE_Token_Queue_Entry::signal (void)
{
  return
#if defined (ACE_TOKEN_USES_SEMAPHORE)
    this->cv_.release ();
#else
    this->cv_.signal ();
#endif /* ACE_TOKEN_USES_SEMAPHORE */
}
ACE_END_VERSIONED_NAMESPACE_DECL
#endif /* ACE_HAS_THREADS */
/*****************************************************************************/
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_Noop_Token::queueing_strategy (void)
{
  return -1;
}
ACE_INLINE void
ACE_Noop_Token::queueing_strategy (int /* queueing_strategy */)
{
}
ACE_INLINE int
ACE_Noop_Token::renew (int, ACE_Time_Value *)
{
  return 0;
}
ACE_INLINE void
ACE_Noop_Token::dump (void) const
{
}
ACE_END_VERSIONED_NAMESPACE_DECL

