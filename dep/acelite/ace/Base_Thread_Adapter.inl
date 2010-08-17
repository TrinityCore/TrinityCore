// -*- C++ -*-
//
// $Id: Base_Thread_Adapter.inl 80826 2008-03-04 14:51:23Z wotte $

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE long
ACE_OS_Thread_Descriptor::flags (void) const
{
  return flags_;
}

ACE_INLINE
ACE_OS_Thread_Descriptor::ACE_OS_Thread_Descriptor (long flags)
  : flags_ (flags)
{
}

ACE_INLINE void
ACE_Base_Thread_Adapter::set_log_msg_hooks (
    ACE_INIT_LOG_MSG_HOOK init_hook,
    ACE_INHERIT_LOG_MSG_HOOK inherit_hook,
    ACE_CLOSE_LOG_MSG_HOOK close_hook,
    ACE_SYNC_LOG_MSG_HOOK sync_hook,
    ACE_THR_DESC_LOG_MSG_HOOK thr_desc_hook)
{
  ACE_Base_Thread_Adapter::init_log_msg_hook_      = init_hook;
  ACE_Base_Thread_Adapter::inherit_log_msg_hook_   = inherit_hook;
  ACE_Base_Thread_Adapter::close_log_msg_hook_     = close_hook;
  ACE_Base_Thread_Adapter::sync_log_msg_hook_      = sync_hook;
  ACE_Base_Thread_Adapter::thr_desc_log_msg_hook_  = thr_desc_hook;
}

ACE_INLINE ACE_THR_C_FUNC
ACE_Base_Thread_Adapter::entry_point (void)
{
  return this->entry_point_;
}

#ifdef ACE_USES_GPROF
ACE_INLINE itimerval*
ACE_Base_Thread_Adapter::timerval (void)
{
  return &(this->itimer_);
}
#endif // ACE_USES_GPROF

ACE_END_VERSIONED_NAMESPACE_DECL
