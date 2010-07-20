// $Id: Thread.cpp 84163 2009-01-15 07:57:27Z johnnyw $

#include "ace/Thread.h"

ACE_RCSID(ace,
          Thread,
          "$Id: Thread.cpp 84163 2009-01-15 07:57:27Z johnnyw $")

#if !defined (__ACE_INLINE__)
#include "ace/Thread.inl"
#endif /* !defined (__ACE_INLINE__) */

#if defined (ACE_HAS_THREADS)

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

size_t
ACE_Thread::spawn_n (size_t n,
                     ACE_THR_FUNC func,
                     void *arg,
                     long flags,
                     long priority,
                     void *stack[],
                     size_t stack_size[],
                     ACE_Thread_Adapter *thread_adapter,
                     const char* thr_name[])
{
  ACE_TRACE ("ACE_Thread::spawn_n");
  size_t i;

  for (i = 0; i < n; i++)
   {
      ACE_thread_t t_id;
      // Bail out if error occurs.
      if (ACE_OS::thr_create (func,
                              arg,
                              flags,
                              &t_id,
                              0,
                              priority,
                              stack == 0 ? 0 : stack[i],
                              stack_size == 0 ? ACE_DEFAULT_THREAD_STACKSIZE : stack_size[i],
                              thread_adapter,
                              thr_name == 0 ? 0 : &thr_name[i]) != 0)
        break;
   }

  return i;
}

size_t
ACE_Thread::spawn_n (ACE_thread_t thread_ids[],
                     size_t n,
                     ACE_THR_FUNC func,
                     void *arg,
                     long flags,
                     long priority,
                     void *stack[],
                     size_t stack_size[],
                     ACE_hthread_t thread_handles[],
                     ACE_Thread_Adapter *thread_adapter,
                     const char* thr_name[])
{
  ACE_TRACE ("ACE_Thread::spawn_n");
  size_t i = 0;

  for (i = 0; i < n; i++)
    {
      ACE_thread_t t_id;
      ACE_hthread_t t_handle;

      int const result =
        ACE_OS::thr_create (func,
                            arg,
                            flags,
                            &t_id,
                            &t_handle,
                            priority,
                            stack == 0 ? 0 : stack[i],
                            stack_size == 0 ? ACE_DEFAULT_THREAD_STACKSIZE : stack_size[i],
                            thread_adapter,
                            thr_name == 0 ? 0 : &thr_name[i]);

      if (result == 0)
        {
          if (thread_ids != 0)
            thread_ids[i] = t_id;
          if (thread_handles != 0)
            thread_handles[i] = t_handle;
        }
      else
        // Bail out if error occurs.
        break;
    }

  return i;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_THREADS */
