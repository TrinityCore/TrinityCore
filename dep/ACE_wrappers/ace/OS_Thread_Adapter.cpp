// $Id: OS_Thread_Adapter.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_Thread_Adapter.h"

ACE_RCSID (ace,
           OS_Thread_Adapter,
           "$Id: OS_Thread_Adapter.cpp 80826 2008-03-04 14:51:23Z wotte $")

#include "ace/Thread_Hook.h"
#include "ace/Object_Manager_Base.h"
#include "ace/Global_Macros.h"
#include "ace/OS_NS_Thread.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_OS_Thread_Adapter::ACE_OS_Thread_Adapter (
     ACE_THR_FUNC user_func
     , void *arg
     , ACE_THR_C_FUNC entry_point
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
     , ACE_SEH_EXCEPT_HANDLER selector
     , ACE_SEH_EXCEPT_HANDLER handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
     )
  : ACE_Base_Thread_Adapter (user_func, arg, entry_point
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
                             , 0
                             , selector
                             , handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
                             )
{
}

ACE_OS_Thread_Adapter::~ACE_OS_Thread_Adapter (void)
{
}

ACE_THR_FUNC_RETURN
ACE_OS_Thread_Adapter::invoke (void)
{
  // Inherit the logging features if the parent thread has an
  // ACE_Log_Msg instance in thread-specific storage.
  this->inherit_log_msg ();

  // Extract the arguments.
  ACE_THR_FUNC_INTERNAL func =
    reinterpret_cast<ACE_THR_FUNC_INTERNAL> (this->user_func_);
  void *arg = this->arg_;

  // Delete ourselves since we don't need <this> anymore.  Make sure
  // not to access <this> anywhere below this point.
  delete this;

#if defined (ACE_NEEDS_LWP_PRIO_SET)
  // On SunOS, the LWP priority needs to be set in order to get
  // preemption when running in the RT class.  This is the ACE way to
  // do that . . .
  ACE_hthread_t thr_handle;
  ACE_OS::thr_self (thr_handle);
  int prio;

  // thr_getprio () on the current thread should never fail.
  ACE_OS::thr_getprio (thr_handle, prio);

  // ACE_OS::thr_setprio () has the special logic to set the LWP priority,
  // if running in the RT class.
  ACE_OS::thr_setprio (prio);

#endif /* ACE_NEEDS_LWP_PRIO_SET */

  ACE_THR_FUNC_RETURN status = 0;

  ACE_SEH_TRY
    {
      ACE_SEH_TRY
        {
          ACE_Thread_Hook *hook =
            ACE_OS_Object_Manager::thread_hook ();

          if (hook)
            // Invoke the start hook to give the user a chance to
            // perform some initialization processing before the
            // <func> is invoked.
            status = hook->start (reinterpret_cast<ACE_THR_FUNC> (func),
                                  arg);
          else
            {
              // Call thread entry point.
              status = (*func) (arg);
            }
        }

#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
      ACE_SEH_EXCEPT (ACE_OS_Object_Manager::seh_except_selector ()(
                          (void *) GetExceptionInformation ()))
        {
          ACE_OS_Object_Manager::seh_except_handler ()(0);
        }
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
    }

  ACE_SEH_FINALLY
    {
      // If we changed this to 1, change the respective if in
      // Task::svc_run to 0.
#if 0
      // Call the <Task->close> hook.
      if (func == reinterpret_cast<ACE_THR_FUNC_INTERNAL> (ACE_Task_Base::svc_run))
        {
          ACE_Task_Base *task_ptr = (ACE_Task_Base *) arg;
          ACE_Thread_Manager *thr_mgr_ptr = task_ptr->thr_mgr ();

          // This calls the Task->close () hook.
          task_ptr->cleanup (task_ptr, 0);

          // This prevents a second invocation of the cleanup code
          // (called later by <ACE_Thread_Manager::exit>.
          thr_mgr_ptr->at_exit (task_ptr, 0, 0);
        }
#endif /* 0 */

#if defined (ACE_WIN32) || defined (ACE_HAS_TSS_EMULATION)
      // Call TSS destructors.
      ACE_OS::cleanup_tss (0 /* not main thread */);

# if defined (ACE_WIN32)
      // Exit the thread.  Allow CWinThread-destructor to be invoked
      // from AfxEndThread.  _endthreadex will be called from
      // AfxEndThread so don't exit the thread now if we are running
      // an MFC thread.
#   if defined (ACE_HAS_MFC) && (ACE_HAS_MFC != 0)
      // Not spawned by ACE_Thread_Manager, use the old buggy
      // version.  You should seriously consider using
      // ACE_Thread_Manager to spawn threads.  The following code
      // is know to cause some problem.
      CWinThread *pThread = ::AfxGetThread ();

      if (!pThread || pThread->m_nThreadID != ACE_OS::thr_self ())
        ACE_ENDTHREADEX (status);
      else
        ::AfxEndThread (status);
#   else
      ACE_ENDTHREADEX (status);
#   endif /* ACE_HAS_MFC && ACE_HAS_MFS != 0*/
# endif /* ACE_WIN32 */
#endif /* ACE_WIN32 || ACE_HAS_TSS_EMULATION */
    }

  return status;
}

ACE_END_VERSIONED_NAMESPACE_DECL
