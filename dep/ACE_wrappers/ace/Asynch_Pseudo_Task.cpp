// $Id: Asynch_Pseudo_Task.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Asynch_Pseudo_Task.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_signal.h"
ACE_RCSID(ace, Asynch_Pseudo_Task, "$Id: Asynch_Pseudo_Task.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_Asynch_Pseudo_Task::ACE_Asynch_Pseudo_Task ()
  : select_reactor_ (),               // should be initialized before reactor_
    reactor_ (&select_reactor_, 0)    // don't delete implementation
{
}
ACE_Asynch_Pseudo_Task::~ACE_Asynch_Pseudo_Task ()
{
  this->stop ();
}
int
ACE_Asynch_Pseudo_Task::start (void)
{
  if (this->reactor_.initialized () == 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%N:%l:%p\n"),
                       ACE_TEXT ("start reactor is not initialized")),
                       -1);
  return this->activate () == -1 ? -1 : 0;   // If started, return 0
}
int
ACE_Asynch_Pseudo_Task::stop (void)
{
  if (this->thr_count () == 0)  // already stopped
    return 0;
  if (this->reactor_.end_reactor_event_loop () == -1)
    return -1;
  this->wait ();
  this->reactor_.close ();
  return 0;
}
int
ACE_Asynch_Pseudo_Task::svc (void)
{
#if !defined (ACE_WIN32)
  sigset_t RT_signals;
  sigemptyset (&RT_signals);
  for (int si = ACE_SIGRTMIN; si <= ACE_SIGRTMAX; si++)
    sigaddset (&RT_signals, si);
  if (ACE_OS::pthread_sigmask (SIG_BLOCK, &RT_signals, 0) != 0)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("Error:(%P | %t):%p\n"),
                ACE_TEXT ("pthread_sigmask")));
#endif
  reactor_.owner (ACE_Thread::self ());
  reactor_.run_reactor_event_loop ();
  return 0;
}

int
ACE_Asynch_Pseudo_Task::register_io_handler (ACE_HANDLE handle,
                                             ACE_Event_Handler *handler,
                                             ACE_Reactor_Mask mask,
                                             int flg_suspend)
{
  // Register the handler with the reactor.
  if (-1 == this->reactor_.register_handler (handle, handler, mask))
    return -1;
  if (flg_suspend == 0)
    return 0;
  // Suspend the handle now. Enable only when the accept is issued
  // by the application.
  if (this->reactor_.suspend_handler (handle) == -1)
    {
      ACE_ERROR
        ((LM_ERROR,
          ACE_TEXT ("%N:%l:%p\n"),
          ACE_TEXT ("register_io_handler (suspended)")));
      this->reactor_.remove_handler (handle, ACE_Event_Handler::ALL_EVENTS_MASK
                                     | ACE_Event_Handler::DONT_CALL);
      return -1;
    }
  return 0;
}
int
ACE_Asynch_Pseudo_Task::remove_io_handler (ACE_HANDLE handle)
{
  return this->reactor_.remove_handler (handle,
                                        ACE_Event_Handler::ALL_EVENTS_MASK
                                        | ACE_Event_Handler::DONT_CALL);
}
int
ACE_Asynch_Pseudo_Task::remove_io_handler (ACE_Handle_Set &set)
{
  return this->reactor_.remove_handler (set, ACE_Event_Handler::ALL_EVENTS_MASK
                                        | ACE_Event_Handler::DONT_CALL);
}
int
ACE_Asynch_Pseudo_Task::suspend_io_handler (ACE_HANDLE handle)
{
  return this->reactor_.suspend_handler (handle);
}
int
ACE_Asynch_Pseudo_Task::resume_io_handler (ACE_HANDLE handle)
{
  return this->reactor_.resume_handler (handle);
}
ACE_END_VERSIONED_NAMESPACE_DECL

