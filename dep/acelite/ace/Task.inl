// -*- C++ -*-
//
// $Id: Task.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Get the current group id.
ACE_INLINE int
ACE_Task_Base::grp_id (void) const
{
  ACE_TRACE ("ACE_Task_Base::grp_id");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, const_cast <ACE_Thread_Mutex&>(this->lock_), -1));
  return this->grp_id_;
}

// Set the current group id.

ACE_INLINE void
ACE_Task_Base::grp_id (int identifier)
{
  ACE_TRACE ("ACE_Task_Base::grp_id");
  ACE_MT (ACE_GUARD (ACE_Thread_Mutex, ace_mon, this->lock_));

  // Cache the group id in the task and then set it in the
  // Thread_Manager, if there is one.
  this->grp_id_ = identifier;
  if (this->thr_mgr ())
    this->thr_mgr ()->set_grp (this, identifier);
}

ACE_INLINE ACE_Thread_Manager *
ACE_Task_Base::thr_mgr (void) const
{
  ACE_TRACE ("ACE_Task_Base::thr_mgr");
  return this->thr_mgr_;
}

ACE_INLINE void
ACE_Task_Base::thr_mgr (ACE_Thread_Manager *thr_mgr)
{
  ACE_TRACE ("ACE_Task_Base::thr_mgr");
  this->thr_mgr_ = thr_mgr;
}

ACE_INLINE int
ACE_Task_Base::is_reader (void) const
{
  ACE_TRACE ("ACE_Task_Base::is_reader");
  return (ACE_BIT_ENABLED (this->flags_, ACE_Task_Flags::ACE_READER));
}

ACE_INLINE int
ACE_Task_Base::is_writer (void) const
{
  ACE_TRACE ("ACE_Task_Base::is_writer");
  return (ACE_BIT_DISABLED (this->flags_, ACE_Task_Flags::ACE_READER));
}

// Return the count of the current number of threads.
ACE_INLINE size_t
ACE_Task_Base::thr_count (void) const
{
  ACE_TRACE ("ACE_Task_Base::thr_count");
  ACE_MT (ACE_GUARD_RETURN (ACE_Thread_Mutex, ace_mon, const_cast <ACE_Thread_Mutex&>(this->lock_), 0));

  return this->thr_count_;
}

// Return the thread ID of the last thread to exit svc().
ACE_INLINE ACE_thread_t
ACE_Task_Base::last_thread (void) const
{
  ACE_TRACE ("ACE_Task_Base::last_thread");
  return this->last_thread_id_;
}

ACE_END_VERSIONED_NAMESPACE_DECL
