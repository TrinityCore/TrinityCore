// $Id: Base_Thread_Adapter.cpp 81239 2008-04-04 22:28:48Z iliyan $

#include "ace/Base_Thread_Adapter.h"

ACE_RCSID (ace,
           Base_Thread_Adapter,
           "$Id: Base_Thread_Adapter.cpp 81239 2008-04-04 22:28:48Z iliyan $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/Base_Thread_Adapter.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#if defined (ACE_HAS_TSS_EMULATION)
#  include "ace/OS_NS_Thread.h"
#endif /* ACE_HAS_TSS_EMULATION */

#include "ace/Service_Config.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INIT_LOG_MSG_HOOK     ACE_Base_Thread_Adapter::init_log_msg_hook_ = 0;
ACE_INHERIT_LOG_MSG_HOOK  ACE_Base_Thread_Adapter::inherit_log_msg_hook_ = 0;
ACE_CLOSE_LOG_MSG_HOOK    ACE_Base_Thread_Adapter::close_log_msg_hook_ = 0;
ACE_SYNC_LOG_MSG_HOOK     ACE_Base_Thread_Adapter::sync_log_msg_hook_ = 0;
ACE_THR_DESC_LOG_MSG_HOOK ACE_Base_Thread_Adapter::thr_desc_log_msg_hook_ = 0;

ACE_Base_Thread_Adapter::ACE_Base_Thread_Adapter (
     ACE_THR_FUNC user_func,
     void *arg,
     ACE_THR_C_FUNC entry_point,
     ACE_OS_Thread_Descriptor *td
#if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
     , ACE_SEH_EXCEPT_HANDLER selector
     , ACE_SEH_EXCEPT_HANDLER handler
#endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
   )
  : user_func_ (user_func)
  , arg_ (arg)
  , entry_point_ (entry_point)
  , thr_desc_ (td)
  , ctx_ (ACE_Service_Config::current())
{
  ACE_OS_TRACE ("ACE_Base_Thread_Adapter::ACE_Base_Thread_Adapter");

  if (ACE_Base_Thread_Adapter::init_log_msg_hook_ != 0)
    (*ACE_Base_Thread_Adapter::init_log_msg_hook_) (
          this->log_msg_attributes_
# if defined (ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS)
          , selector
          , handler
# endif /* ACE_HAS_WIN32_STRUCTURAL_EXCEPTIONS */
          );
#ifdef ACE_USES_GPROF
  getitimer (ITIMER_PROF, &itimer_);
#endif // ACE_USES_GPROF
}

ACE_Base_Thread_Adapter::~ACE_Base_Thread_Adapter (void)
{
}

void
ACE_Base_Thread_Adapter::inherit_log_msg (void)
{
  if (ACE_Base_Thread_Adapter::inherit_log_msg_hook_ != 0)
    (*ACE_Base_Thread_Adapter::inherit_log_msg_hook_)(
           this->thr_desc_,
           this->log_msg_attributes_);

  // Initialize the proper configuration context for the new thread
  // Placed here since inherit_log_msg() gets called from any of our
  // descendants (before self-destructing)
  ACE_Service_Config::current (this->ctx_);
}

void
ACE_Base_Thread_Adapter::close_log_msg (void)
{
  if (ACE_Base_Thread_Adapter::close_log_msg_hook_ != 0)
    (*ACE_Base_Thread_Adapter::close_log_msg_hook_) ();
}

void
ACE_Base_Thread_Adapter::sync_log_msg (const ACE_TCHAR *prg)
{
  if (ACE_Base_Thread_Adapter::sync_log_msg_hook_ != 0)
    (*ACE_Base_Thread_Adapter::sync_log_msg_hook_) (prg);
}

ACE_OS_Thread_Descriptor *
ACE_Base_Thread_Adapter::thr_desc_log_msg (void)
{
  if (ACE_Base_Thread_Adapter::thr_desc_log_msg_hook_ != 0)
    return (*ACE_Base_Thread_Adapter::thr_desc_log_msg_hook_) ();
  return 0;
}

ACE_END_VERSIONED_NAMESPACE_DECL

// Run the thread entry point for the <ACE_Thread_Adapter>.  This must
// be an extern "C" to make certain compilers happy...

extern "C" ACE_THR_FUNC_RETURN
ACE_THREAD_ADAPTER_NAME (void *args)
{
  ACE_OS_TRACE ("ACE_THREAD_ADAPTER_NAME");

#if defined (ACE_HAS_TSS_EMULATION)
  // As early as we can in the execution of the new thread, allocate
  // its local TS storage.  Allocate it on the stack, to save dynamic
  // allocation/dealloction.
  void *ts_storage[ACE_TSS_Emulation::ACE_TSS_THREAD_KEYS_MAX];
  ACE_TSS_Emulation::tss_open (ts_storage);
#endif /* ACE_HAS_TSS_EMULATION */

  ACE_Base_Thread_Adapter * const thread_args =
    static_cast<ACE_Base_Thread_Adapter *> (args);

#ifdef ACE_USES_GPROF
  setitimer (ITIMER_PROF, thread_args->timerval (), 0);
#endif // ACE_USES_GPROF

  // Invoke the user-supplied function with the args.
  ACE_THR_FUNC_RETURN status = thread_args->invoke ();

  return status;
}

