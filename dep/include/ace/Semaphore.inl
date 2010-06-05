// -*- C++ -*-
//
// $Id: Semaphore.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE const ACE_sema_t &
ACE_Semaphore::lock (void) const
{
// ACE_TRACE ("ACE_Semaphore::lock");
  return this->semaphore_;
}

ACE_INLINE int
ACE_Semaphore::remove (void)
{
// ACE_TRACE ("ACE_Semaphore::remove");
  int result = 0;
  if (!this->removed_)
    {
      this->removed_ = true;
      result = ACE_OS::sema_destroy (&this->semaphore_);
    }
  return result;
}

ACE_INLINE int
ACE_Semaphore::acquire (void)
{
// ACE_TRACE ("ACE_Semaphore::acquire");
  return ACE_OS::sema_wait (&this->semaphore_);
}

ACE_INLINE int
ACE_Semaphore::acquire (ACE_Time_Value &tv)
{
// ACE_TRACE ("ACE_Semaphore::acquire");
  return ACE_OS::sema_wait (&this->semaphore_, tv);
}

ACE_INLINE int
ACE_Semaphore::acquire (ACE_Time_Value *tv)
{
// ACE_TRACE ("ACE_Semaphore::acquire");
  return ACE_OS::sema_wait (&this->semaphore_, tv);
}

ACE_INLINE int
ACE_Semaphore::tryacquire (void)
{
// ACE_TRACE ("ACE_Semaphore::tryacquire");
  return ACE_OS::sema_trywait (&this->semaphore_);
}

ACE_INLINE int
ACE_Semaphore::release (void)
{
// ACE_TRACE ("ACE_Semaphore::release");
  return ACE_OS::sema_post (&this->semaphore_);
}

ACE_INLINE int
ACE_Semaphore::release (unsigned int release_count)
{
// ACE_TRACE ("ACE_Semaphore::release");
  return ACE_OS::sema_post (&this->semaphore_, release_count);
}

// Acquire semaphore ownership.  This calls <acquire> and is only
// here to make the <ACE_Semaphore> interface consistent with the
// other synchronization APIs.

ACE_INLINE int
ACE_Semaphore::acquire_read (void)
{
  return this->acquire ();
}

// Acquire semaphore ownership.  This calls <acquire> and is only
// here to make the <ACE_Semaphore> interface consistent with the
// other synchronization APIs.

ACE_INLINE int
ACE_Semaphore::acquire_write (void)
{
  return this->acquire ();
}

// Conditionally acquire semaphore (i.e., won't block).  This calls
// <tryacquire> and is only here to make the <ACE_Semaphore>
// interface consistent with the other synchronization APIs.

ACE_INLINE int
ACE_Semaphore::tryacquire_read (void)
{
  return this->tryacquire ();
}

// Conditionally acquire semaphore (i.e., won't block).  This calls
// <tryacquire> and is only here to make the <ACE_Semaphore>
// interface consistent with the other synchronization APIs.

ACE_INLINE int
ACE_Semaphore::tryacquire_write (void)
{
  return this->tryacquire ();
}

// This is only here to make the <ACE_Semaphore> interface consistent
// with the other synchronization APIs.  Assumes the caller has
// already acquired the semaphore using one of the above calls, and
// returns 0 (success) always.
ACE_INLINE int
ACE_Semaphore::tryacquire_write_upgrade (void)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
