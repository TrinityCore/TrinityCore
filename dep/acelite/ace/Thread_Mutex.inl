// -*- C++ -*-
//
// $Id: Thread_Mutex.inl 89127 2010-02-22 19:58:18Z schmidt $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE const ACE_thread_mutex_t &
ACE_Thread_Mutex::lock (void) const
{
// ACE_TRACE ("ACE_Thread_Mutex::lock");
  return this->lock_;
}

ACE_INLINE ACE_thread_mutex_t &
ACE_Thread_Mutex::lock (void) 
{
// ACE_TRACE ("ACE_Thread_Mutex::lock");
  return this->lock_;
}

ACE_INLINE int
ACE_Thread_Mutex::acquire_read (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::acquire_read");
  return ACE_OS::thread_mutex_lock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::acquire_write (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::acquire_write");
  return ACE_OS::thread_mutex_lock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::tryacquire_read (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::tryacquire_read");
  return ACE_OS::thread_mutex_trylock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::tryacquire_write (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::tryacquire_write");
  return ACE_OS::thread_mutex_trylock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::tryacquire_write_upgrade (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::tryacquire_write_upgrade");
  return 0;
}

ACE_INLINE int
ACE_Thread_Mutex::acquire (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::acquire");
  return ACE_OS::thread_mutex_lock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::acquire (ACE_Time_Value &tv)
{
  // ACE_TRACE ("ACE_Thread_Mutex::acquire");
  return ACE_OS::thread_mutex_lock (&this->lock_, tv);
}

ACE_INLINE int
ACE_Thread_Mutex::acquire (ACE_Time_Value *tv)
{
  // ACE_TRACE ("ACE_Thread_Mutex::acquire");
  return ACE_OS::thread_mutex_lock (&this->lock_, tv);
}

ACE_INLINE int
ACE_Thread_Mutex::tryacquire (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::tryacquire");
  return ACE_OS::thread_mutex_trylock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::release (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::release");
  return ACE_OS::thread_mutex_unlock (&this->lock_);
}

ACE_INLINE int
ACE_Thread_Mutex::remove (void)
{
// ACE_TRACE ("ACE_Thread_Mutex::remove");
  int result = 0;
  if (!this->removed_)
    {
      this->removed_ = true;
      result = ACE_OS::thread_mutex_destroy (&this->lock_);
    }
  return result;
}

ACE_END_VERSIONED_NAMESPACE_DECL
