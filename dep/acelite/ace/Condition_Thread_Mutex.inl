// -*- C++ -*-
//
// $Id: Condition_Thread_Mutex.inl 92069 2010-09-28 11:38:59Z johnnyw $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Condition_Attributes::ACE_Condition_Attributes (int type)
{
  (void) ACE_OS::condattr_init (this->attributes_, type);
}

ACE_INLINE
ACE_Condition_Attributes::~ACE_Condition_Attributes (void)
{
  ACE_OS::condattr_destroy (this->attributes_);
}

ACE_INLINE int
ACE_Condition_Thread_Mutex::remove (void)
{
// ACE_TRACE ("ACE_Condition_Thread_Mutex::remove");

  // <cond_destroy> is called in a loop if the condition variable is
  // BUSY.  This avoids a condition where a condition is signaled and
  // because of some timing problem, the thread that is to be signaled
  // has called the cond_wait routine after the signal call.  Since
  // the condition signal is not queued in any way, deadlock occurs.

  int result = 0;

  if (!this->removed_)
    {
      this->removed_ = true;

      while ((result = ACE_OS::cond_destroy (&this->cond_)) == -1
             && errno == EBUSY)
        {
          ACE_OS::cond_broadcast (&this->cond_);
          ACE_OS::thr_yield ();
        }
    }
  return result;
}

ACE_INLINE ACE_Thread_Mutex &
ACE_Condition_Thread_Mutex::mutex (void)
{
// ACE_TRACE ("ACE_Condition_Thread_Mutex::mutex");
  return this->mutex_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
