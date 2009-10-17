// -*- C++ -*-
//
// $Id: Process_Mutex.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if !defined (_ACE_USE_SV_SEM)
ACE_INLINE const ACE_mutex_t &
ACE_Process_Mutex::lock (void) const
{
// ACE_TRACE ("ACE_Process_Mutex::lock");
  return this->lock_.lock ();
}
#endif /* !_ACE_USE_SV_SEM */

// Explicitly destroy the mutex.
ACE_INLINE int
ACE_Process_Mutex::remove (void)
{
  return this->lock_.remove ();
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.acquire (0, SEM_UNDO);
#else
  return this->lock_.acquire ();
#endif // _ACE_USE_SV_SEM
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire (ACE_Time_Value &tv)
{
#if !defined (_ACE_USE_SV_SEM)
  return this->lock_.acquire (tv);
#else
  ACE_UNUSED_ARG (tv);
  ACE_NOTSUP_RETURN (-1);
#endif  /* !_ACE_USE_SV_SEM */
}

// Conditionally acquire lock (i.e., don't wait on queue).
ACE_INLINE int
ACE_Process_Mutex::tryacquire (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.tryacquire (0, SEM_UNDO);
#else
  return this->lock_.tryacquire ();
#endif // _ACE_USE_SV_SEM
}

// Release lock and unblock a thread at head of priority queue.
ACE_INLINE int
ACE_Process_Mutex::release (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.release (0, SEM_UNDO);
#else
  return this->lock_.release ();
#endif // _ACE_USE_SV_SEM
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire_read (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.acquire_read (0, SEM_UNDO);
#else
  return this->lock_.acquire_read ();
#endif // _ACE_USE_SV_SEM
}

// Acquire lock ownership (wait on priority queue if necessary).
ACE_INLINE int
ACE_Process_Mutex::acquire_write (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.acquire_write (0, SEM_UNDO);
#else
  return this->lock_.acquire_write ();
#endif // _ACE_USE_SV_SEM
}

// Conditionally acquire a lock (i.e., won't block).
ACE_INLINE int
ACE_Process_Mutex::tryacquire_read (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.tryacquire_read (0, SEM_UNDO);
#else
  return this->lock_.tryacquire_read ();
#endif // _ACE_USE_SV_SEM
}

// Conditionally acquire a lock (i.e., won't block).
ACE_INLINE int
ACE_Process_Mutex::tryacquire_write (void)
{
#if defined (_ACE_USE_SV_SEM)
  return this->lock_.tryacquire_write (0, SEM_UNDO);
#else
  return this->lock_.tryacquire_write ();
#endif // _ACE_USE_SV_SEM
}

ACE_INLINE int
ACE_Process_Mutex::tryacquire_write_upgrade (void)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL
