// -*- C++ -*-
//
// $Id: Thread.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_string.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Allocates a <keyp> that is used to identify data that is specific
// to each thread in the process.  The key is global to all threads in
// the process.
ACE_INLINE int
ACE_Thread::keycreate (ACE_thread_key_t *keyp,
#if defined (ACE_HAS_THR_C_DEST)
                       ACE_THR_C_DEST destructor,
#else
                       ACE_THR_DEST destructor,
#endif /* ACE_HAS_THR_C_DEST */
                       void *inst)
{
  // ACE_TRACE ("ACE_Thread::keycreate");
  return ACE_OS::thr_keycreate (keyp, destructor, inst);
}
// Free up the key so that other threads can reuse it.
ACE_INLINE int
ACE_Thread::keyfree (ACE_thread_key_t key)
{
  ACE_TRACE ("ACE_Thread::keyfree");
  return ACE_OS::thr_keyfree (key);
}
// Bind value to the thread-specific data key, <key>, for the calling
// thread.
ACE_INLINE int
ACE_Thread::setspecific (ACE_thread_key_t key, void *value)
{
  // ACE_TRACE ("ACE_Thread::setspecific");
  return ACE_OS::thr_setspecific (key, value);
}
// Stores the current value bound to <key> for the calling thread
// into the location pointed to by <valuep>.
ACE_INLINE int
ACE_Thread::getspecific (ACE_thread_key_t key, void **valuep)
{
  // ACE_TRACE ("ACE_Thread::getspecific");
  return ACE_OS::thr_getspecific (key, valuep);
}
ACE_INLINE ACE_thread_t
ACE_Thread::self (void)
{
//  ACE_TRACE ("ACE_Thread::self");
  return ACE_OS::thr_self ();
}
ACE_INLINE void
ACE_Thread::exit (ACE_THR_FUNC_RETURN status)
{
  ACE_TRACE ("ACE_Thread::exit");
  ACE_OS::thr_exit (status);
}
ACE_INLINE void
ACE_Thread::yield (void)
{
  ACE_TRACE ("ACE_Thread::yield");
  ACE_OS::thr_yield ();
}
ACE_INLINE int
ACE_Thread::spawn (ACE_THR_FUNC func,
                   void *arg,
                   long flags,
                   ACE_thread_t *t_id,
                   ACE_hthread_t *t_handle,
                   long priority,
                   void *thr_stack,
                   size_t thr_stack_size,
                   ACE_Thread_Adapter *thread_adapter,
                   const char** thr_name)
{
  ACE_TRACE ("ACE_Thread::spawn");
  return ACE_OS::thr_create (func,
                             arg,
                             flags,
                             t_id,
                             t_handle,
                             priority,
                             thr_stack,
                             thr_stack_size,
                             thread_adapter,
                             thr_name);
}
ACE_INLINE int
ACE_Thread::resume (ACE_hthread_t t_id)
{
  ACE_TRACE ("ACE_Thread::resume");
  return ACE_OS::thr_continue (t_id);
}
ACE_INLINE int
ACE_Thread::suspend (ACE_hthread_t t_id)
{
  ACE_TRACE ("ACE_Thread::suspend");
  return ACE_OS::thr_suspend (t_id);
}
ACE_INLINE int
ACE_Thread::kill (ACE_thread_t t_id, int signum)
{
  ACE_TRACE ("ACE_Thread::kill");
  return ACE_OS::thr_kill (t_id, signum);
}
ACE_INLINE int
ACE_Thread::join (ACE_thread_t wait_for,
                  ACE_thread_t *departed,
                  ACE_THR_FUNC_RETURN *status)
{
  ACE_TRACE ("ACE_Thread::join");
  return ACE_OS::thr_join (wait_for, departed, status);
}
ACE_INLINE int
ACE_Thread::join (ACE_hthread_t wait_for,
                  ACE_THR_FUNC_RETURN *status)
{
  ACE_TRACE ("ACE_Thread::join");
  return ACE_OS::thr_join (wait_for, status);
}
ACE_INLINE int
ACE_Thread::getconcurrency (void)
{
  ACE_TRACE ("ACE_Thread::getconcurrency");
  return ACE_OS::thr_getconcurrency ();
}
ACE_INLINE int
ACE_Thread::setconcurrency (int new_level)
{
  ACE_TRACE ("ACE_Thread::setconcurrency");
  return ACE_OS::thr_setconcurrency (new_level);
}
ACE_INLINE int
ACE_Thread::sigsetmask (int how,
                        const sigset_t *sigset,
                        sigset_t *osigset)
{
  ACE_TRACE ("ACE_Thread::sigsetmask");
  return ACE_OS::thr_sigsetmask (how, sigset, osigset);
}
ACE_INLINE int
ACE_Thread::disablecancel (struct cancel_state *old_state)
{
  ACE_TRACE ("ACE_Thread::disablecancel");
  int old_cstate = 0;
  int result = ACE_OS::thr_setcancelstate (THR_CANCEL_DISABLE,
                                           &old_cstate);
  if (result == 0 && old_state != 0)
    {
      ACE_OS::memset (old_state,
                      0,
                      sizeof (old_state));
      old_state->cancelstate = old_cstate;
    }
  return result;
}
ACE_INLINE int
ACE_Thread::enablecancel (struct cancel_state *old_state,
                          int flag)
{
  ACE_TRACE ("ACE_Thread::enablecancel");
  int old_cstate = 0;
  int old_ctype = 0;
  int result;
  result = ACE_OS::thr_setcancelstate (THR_CANCEL_ENABLE,
                                       &old_cstate);
  if (result != 0)
    return result;
  result = ACE_OS::thr_setcanceltype (flag,
                                      &old_ctype);
  if (result != 0)
    return result;
  if (old_state != 0)
    {
      old_state->cancelstate = old_cstate;
      old_state->canceltype = old_ctype;
    }
  return 0;
}
ACE_INLINE int
ACE_Thread::setcancelstate (struct cancel_state &new_state,
                            struct cancel_state *old_state)
{
  ACE_TRACE ("ACE_Thread::setcancelstate");
  int old_cstate = 0;
  int old_ctype = 0;
  if (new_state.cancelstate != 0
      && ACE_OS::thr_setcancelstate (new_state.cancelstate,
                                     &old_cstate) != 0)
    return -1;
  if (new_state.canceltype != 0
      && ACE_OS::thr_setcanceltype (new_state.canceltype,
                                    &old_ctype) != 0)
    {
      int o_cstate;
      ACE_OS::thr_setcancelstate (old_cstate,
                                  &o_cstate);
      return -1;
    }
  if (old_state != 0)
    {
      old_state->cancelstate = old_cstate;
      old_state->canceltype = old_ctype;
    }
  return 0;
}
ACE_INLINE int
ACE_Thread::cancel (ACE_thread_t t_id)
{
  ACE_TRACE ("ACE_Thread::cancel");
  return ACE_OS::thr_cancel (t_id);
}
ACE_INLINE void
ACE_Thread::testcancel (void)
{
  ACE_TRACE ("ACE_Thread::testcancel");
  ACE_OS::thr_testcancel ();
}
ACE_INLINE void
ACE_Thread::self (ACE_hthread_t &t_id)
{
//  ACE_TRACE ("ACE_Thread::self");
  ACE_OS::thr_self (t_id);
}
ACE_INLINE int
ACE_Thread::getprio (ACE_hthread_t ht_id, int &priority)
{
  ACE_TRACE ("ACE_Thread::getprio");
  return ACE_OS::thr_getprio (ht_id, priority);
}
ACE_INLINE int
ACE_Thread::getprio (ACE_hthread_t ht_id, int &priority, int &policy)
{
  ACE_TRACE ("ACE_Thread::getprio");
  return ACE_OS::thr_getprio (ht_id, priority, policy);
}
ACE_INLINE int
ACE_Thread::setprio (ACE_hthread_t ht_id, int priority, int policy)
{
  ACE_TRACE ("ACE_Thread::setprio");
  return ACE_OS::thr_setprio (ht_id, priority, policy);
}
ACE_END_VERSIONED_NAMESPACE_DECL
