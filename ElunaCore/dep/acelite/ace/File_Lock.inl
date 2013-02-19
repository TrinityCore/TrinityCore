// -*- C++ -*-
//
// $Id: File_Lock.inl 87213 2009-10-23 13:11:34Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_File_Lock::acquire_read (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::acquire_read");
  return ACE_OS::flock_rdlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::tryacquire_read (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::tryacquire_read");
  return ACE_OS::flock_tryrdlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::tryacquire_write (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::tryacquire_write");
  return ACE_OS::flock_trywrlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::tryacquire_write_upgrade (short whence,
                                         ACE_OFF_T start,
                                         ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::tryacquire_write_upgrade");
  return ACE_OS::flock_trywrlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::tryacquire (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::tryacquire");
  return this->tryacquire_write (whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::acquire_write (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::acquire_write");
  return ACE_OS::flock_wrlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::acquire (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::acquire");
  return this->acquire_write (whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::release (short whence, ACE_OFF_T start, ACE_OFF_T len)
{
// ACE_TRACE ("ACE_File_Lock::release");
  return ACE_OS::flock_unlock (&this->lock_, whence, start, len);
}

ACE_INLINE int
ACE_File_Lock::remove (bool unlink_file)
{
// ACE_TRACE ("ACE_File_Lock::remove");

  int result = 0;

  if (!this->removed_)
    {
      this->removed_ = true;
      result = ACE_OS::flock_destroy (&this->lock_,
                                      unlink_file);
    }
  return result;
}

ACE_INLINE ACE_HANDLE
ACE_File_Lock::get_handle (void) const
{
// ACE_TRACE ("ACE_File_Lock::get_handle");
  return this->lock_.handle_;
}

ACE_INLINE void
ACE_File_Lock::set_handle (ACE_HANDLE h)
{
// ACE_TRACE ("ACE_File_Lock::set_handle");
  this->lock_.handle_ = h;
  this->removed_ = false;
}

ACE_END_VERSIONED_NAMESPACE_DECL
