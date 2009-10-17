// -*- C++ -*-
//
// $Id: Process_Semaphore.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_WIN32) || defined (ACE_HAS_POSIX_SEM)
ACE_INLINE const ACE_sema_t &
ACE_Process_Semaphore::lock (void) const
{
// ACE_TRACE ("ACE_Process_Semaphore::lock");
  return this->lock_.lock ();
}
#endif /* ACE_WIN32 || ACE_HAS_POSIX_SEM */
// Acquire semaphore ownership.  This calls <acquire> and is only here
// to make the ACE_Process_Semaphore interface consistent with the
// other synchronization APIs.
ACE_INLINE int
ACE_Process_Semaphore::acquire_read (void)
{
  return this->acquire ();
}
// Acquire semaphore ownership.  This calls <acquire> and is only here
// to make the ACE_Process_Semaphore interface consistent with the
// other synchronization APIs.
ACE_INLINE int
ACE_Process_Semaphore::acquire_write (void)
{
  return this->acquire ();
}
// Conditionally acquire semaphore (i.e., won't block).  This calls
// <tryacquire> and is only here to make the ACE_Process_Semaphore
// interface consistent with the other synchronization APIs.
ACE_INLINE int
ACE_Process_Semaphore::tryacquire_read (void)
{
  return this->tryacquire ();
}
// Conditionally acquire semaphore (i.e., won't block).  This calls
// <tryacquire> and is only here to make the ACE_Process_Semaphore
// interface consistent with the other synchronization APIs.
ACE_INLINE int
ACE_Process_Semaphore::tryacquire_write (void)
{
  return this->tryacquire ();
}
// This is only here to make the ACE_Process_Semaphore
// interface consistent with the other synchronization APIs.
// Assumes the caller has already acquired the semaphore using one of
// the above calls, and returns 0 (success) always.
ACE_INLINE int
ACE_Process_Semaphore::tryacquire_write_upgrade (void)
{
  return 0;
}
ACE_END_VERSIONED_NAMESPACE_DECL
