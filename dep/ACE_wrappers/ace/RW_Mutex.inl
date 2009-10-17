// -*- C++ -*-
//
// $Id: RW_Mutex.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE const ACE_rwlock_t &
ACE_RW_Mutex::lock (void) const
{
// ACE_TRACE ("ACE_RW_Mutex::lock");
  return this->lock_;
}

ACE_INLINE int
ACE_RW_Mutex::remove (void)
{
// ACE_TRACE ("ACE_RW_Mutex::remove");
  int result = 0;
  if (this->removed_ == 0)
    {
      this->removed_ = 1;
      result = ACE_OS::rwlock_destroy (&this->lock_);
    }
  return result;
}

ACE_INLINE int
ACE_RW_Mutex::acquire_read (void)
{
// ACE_TRACE ("ACE_RW_Mutex::acquire_read");
  return ACE_OS::rw_rdlock (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::acquire_write (void)
{
// ACE_TRACE ("ACE_RW_Mutex::acquire_write");
  return ACE_OS::rw_wrlock (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::acquire (void)
{
// ACE_TRACE ("ACE_RW_Mutex::acquire");
  return ACE_OS::rw_wrlock (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::tryacquire_read (void)
{
// ACE_TRACE ("ACE_RW_Mutex::tryacquire_read");
  return ACE_OS::rw_tryrdlock (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::tryacquire_write (void)
{
// ACE_TRACE ("ACE_RW_Mutex::tryacquire_write");
  return ACE_OS::rw_trywrlock (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::tryacquire_write_upgrade (void)
{
// ACE_TRACE ("ACE_RW_Mutex::tryacquire_write_upgrade");
  return ACE_OS::rw_trywrlock_upgrade (&this->lock_);
}

ACE_INLINE int
ACE_RW_Mutex::tryacquire (void)
{
// ACE_TRACE ("ACE_RW_Mutex::tryacquire");
  return this->tryacquire_write ();
}

ACE_INLINE int
ACE_RW_Mutex::release (void)
{
// ACE_TRACE ("ACE_RW_Mutex::release");
  return ACE_OS::rw_unlock (&this->lock_);
}

ACE_END_VERSIONED_NAMESPACE_DECL
