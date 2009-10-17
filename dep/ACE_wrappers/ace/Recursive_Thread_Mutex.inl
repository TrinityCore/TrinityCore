// -*- C++ -*-
//
// $Id: Recursive_Thread_Mutex.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE ACE_recursive_thread_mutex_t &
ACE_Recursive_Thread_Mutex::mutex (void)
{
  return lock_;
}

ACE_INLINE ACE_thread_mutex_t &
ACE_Recursive_Thread_Mutex::get_nesting_mutex (void)
{
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  return static_cast<ACE_thread_mutex_t &> (lock_);
#else
  return lock_.nesting_mutex_;
#endif /* ACE_HAS_RECURSIVE_MUTEXES */
}

ACE_INLINE void
ACE_Recursive_Thread_Mutex::set_thread_id (ACE_thread_t t)
{
// ACE_TRACE ("ACE_Recursive_Thread_Mutex::set_thread_id");
#if defined (ACE_HAS_RECURSIVE_MUTEXES)
  ACE_UNUSED_ARG (t);
#else  /* ! ACE_HAS_RECURSIVE_MUTEXES */
  this->lock_.owner_id_ = t;
#endif /* ! ACE_HAS_RECURSIVE_MUTEXES */
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::acquire (void)
{
  return ACE_OS::recursive_mutex_lock (&this->lock_);
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::release (void)
{
  return ACE_OS::recursive_mutex_unlock (&this->lock_);
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::tryacquire (void)
{
  return ACE_OS::recursive_mutex_trylock (&this->lock_);
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::acquire (ACE_Time_Value &tv)
{
  return ACE_OS::recursive_mutex_lock (&this->lock_, tv);
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::acquire (ACE_Time_Value *tv)
{
  return ACE_OS::recursive_mutex_lock (&this->lock_, tv);
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::acquire_read (void)
{
  return this->acquire ();
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::acquire_write (void)
{
  return this->acquire ();
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::tryacquire_read (void)
{
  return this->tryacquire ();
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::tryacquire_write (void)
{
  return this->tryacquire ();
}

ACE_INLINE int
ACE_Recursive_Thread_Mutex::tryacquire_write_upgrade (void)
{
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

