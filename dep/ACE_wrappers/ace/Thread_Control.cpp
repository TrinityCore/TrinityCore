// $Id: Thread_Control.cpp 80826 2008-03-04 14:51:23Z wotte $
// <HACK ON>
#include "ace/config-all.h"
#if defined (ACE_LEGACY_MODE)
// This silly include breaks a cycle when compiling in backwards
// compatibility mode
#  include "ace/Thread_Exit.h"
#endif  /* ACE_LEGACY_MODE */
// </HACK OFF>
#include "ace/Thread_Control.h"
#include "ace/Thread_Manager.h"
ACE_RCSID(ace, Thread_Control, "$Id: Thread_Control.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/Thread_Control.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
void
ACE_Thread_Control::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_OS_TRACE ("ACE_Thread_Control::dump");
#endif /* ACE_HAS_DUMP */
}
int
ACE_Thread_Control::insert (ACE_Thread_Manager *tm, int insert)
{
  ACE_OS_TRACE ("ACE_Thread_Control::insert");
  ACE_hthread_t t_id;
  ACE_OS::thr_self (t_id);
  this->tm_ = tm;
  if (insert)
    return this->tm_->insert_thr (ACE_OS::thr_self (), t_id);
  else
    return 0;
}
// Initialize the thread controller.
ACE_Thread_Control::ACE_Thread_Control (ACE_Thread_Manager *t,
                                        int insert)
  : tm_ (t),
    status_ (0)
{
  ACE_OS_TRACE ("ACE_Thread_Control::ACE_Thread_Control");
  if (this->tm_ != 0 && insert)
    {
      ACE_hthread_t t_id;
      ACE_OS::thr_self (t_id);
      this->tm_->insert_thr (ACE_OS::thr_self (), t_id);
    }
}
// Automatically kill thread on exit.
ACE_Thread_Control::~ACE_Thread_Control (void)
{
  ACE_OS_TRACE ("ACE_Thread_Control::~ACE_Thread_Control");
#if defined (ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS) || defined (ACE_HAS_TSS_EMULATION) || defined (ACE_WIN32)
  this->exit (this->status_, 0);
#else
  this->exit (this->status_, 1);
#endif /* ACE_HAS_RECURSIVE_THR_EXIT_SEMANTICS */
}
// Exit from thread (but clean up first).
ACE_THR_FUNC_RETURN
ACE_Thread_Control::exit (ACE_THR_FUNC_RETURN exit_status, int do_thr_exit)
{
  ACE_OS_TRACE ("ACE_Thread_Control::exit");
  if (this->tm_ != 0)
    return this->tm_->exit (exit_status, do_thr_exit);
  else
    {
#if !defined (ACE_HAS_TSS_EMULATION)
      // With ACE_HAS_TSS_EMULATION, we let ACE_Thread_Adapter::invoke ()
      // exit the thread after cleaning up TSS.
      ACE_OS::thr_exit (exit_status);
#endif /* ! ACE_HAS_TSS_EMULATION */
      return 0;
    }
}
ACE_END_VERSIONED_NAMESPACE_DECL

