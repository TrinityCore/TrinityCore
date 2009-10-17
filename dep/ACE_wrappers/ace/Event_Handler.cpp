// Event_Handler.cpp
// $Id: Event_Handler.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Event_Handler.h"
#include "ace/OS_Errno.h"
#include "ace/Reactor.h"
#include "ace/Thread_Manager.h"
/* Need to see if ACE_HAS_BUILTIN_ATOMIC_OP defined */
#include "ace/Atomic_Op.h"
#if !defined (__ACE_INLINE__)
#include "ace/Event_Handler.inl"
#endif /* __ACE_INLINE__ */
#include <algorithm>
ACE_RCSID(ace, Event_Handler, "$Id: Event_Handler.cpp 80826 2008-03-04 14:51:23Z wotte $")
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
// Implement conceptually abstract virtual functions in the base class
// so derived classes don't have to implement unused ones.
ACE_Event_Handler::ACE_Event_Handler (ACE_Reactor *r,
                                      int p)
  : reference_count_ (1),
    priority_ (p),
    reactor_ (r),
    reference_counting_policy_ (Reference_Counting_Policy::DISABLED)
{
  // ACE_TRACE ("ACE_Event_Handler::ACE_Event_Handler");
}
ACE_Event_Handler::~ACE_Event_Handler (void)
{
  // ACE_TRACE ("ACE_Event_Handler::~ACE_Event_Handler");
}
// Gets the file descriptor associated with this I/O device.
ACE_HANDLE
ACE_Event_Handler::get_handle (void) const
{
  ACE_TRACE ("ACE_Event_Handler::get_handle");
  return ACE_INVALID_HANDLE;
}
// Sets the file descriptor associated with this I/O device.
void
ACE_Event_Handler::set_handle (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::set_handle");
}
// Gets the priority of this handler.
int
ACE_Event_Handler::priority (void) const
{
  ACE_TRACE ("ACE_Event_Handler::priority");
  return this->priority_;
}
// Sets the priority
void
ACE_Event_Handler::priority (int priority)
{
  ACE_TRACE ("ACE_Event_Handler::priority");
  this->priority_ = priority;
}
// Called when the object is about to be removed from the Dispatcher
// tables.
int
ACE_Event_Handler::handle_close (ACE_HANDLE, ACE_Reactor_Mask)
{
  ACE_TRACE ("ACE_Event_Handler::handle_close");
  return -1;
}
// Called when input becomes available on fd.
int
ACE_Event_Handler::handle_input (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::handle_input");
  return -1;
}
// Called when output is possible on fd.
int
ACE_Event_Handler::handle_output (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::handle_output");
  return -1;
}
// Called when urgent data is available on fd.
int
ACE_Event_Handler::handle_exception (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::handle_exception");
  return -1;
}
// Called when timer expires, TV stores the current time.
int
ACE_Event_Handler::handle_timeout (const ACE_Time_Value &, const void *)
{
  ACE_TRACE ("ACE_Event_Handler::handle_timeout");
  return -1;
}
// Called when a monitored Process exits
int
ACE_Event_Handler::handle_exit (ACE_Process *)
{
  ACE_TRACE ("ACE_Event_Handler::handle_exit");
  return -1;
}
// Called when a registered signal occurs.
int
ACE_Event_Handler::handle_signal (int, siginfo_t *, ucontext_t *)
{
  ACE_TRACE ("ACE_Event_Handler::handle_signal");
  return -1;
}
int
ACE_Event_Handler::resume_handler (void)
{
  ACE_TRACE ("ACE_Event_Handler::resume_handler");
  // Return a default value and allow the reactor to take care of
  // resuming the handler
  return ACE_Event_Handler::ACE_REACTOR_RESUMES_HANDLER;
}

int
ACE_Event_Handler::handle_qos (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::handle_qos");
  return -1;
}
int
ACE_Event_Handler::handle_group_qos (ACE_HANDLE)
{
  ACE_TRACE ("ACE_Event_Handler::handle_group_qos");
  return -1;
}
void
ACE_Event_Handler::reactor (ACE_Reactor *reactor)
{
  ACE_TRACE ("ACE_Event_Handler::reactor");
  this->reactor_ = reactor;
}
ACE_Reactor *
ACE_Event_Handler::reactor (void) const
{
  ACE_TRACE ("ACE_Event_Handler::reactor");
  return this->reactor_;
}
ACE_Reactor_Timer_Interface *
ACE_Event_Handler::reactor_timer_interface (void) const
{
  ACE_TRACE ("ACE_Event_Handler::reactor_timer_interface");
  return this->reactor_;
}
ACE_Event_Handler::Reference_Count
ACE_Event_Handler::add_reference (void)
{
  bool const reference_counting_required =
    this->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;
  if (reference_counting_required)
    return ++this->reference_count_;
  else
    return 1;
}
ACE_Event_Handler::Reference_Count
ACE_Event_Handler::remove_reference (void)
{
  bool const reference_counting_required =
    this->reference_counting_policy ().value () ==
    ACE_Event_Handler::Reference_Counting_Policy::ENABLED;
  if (reference_counting_required)
    {
      Reference_Count result =
        --this->reference_count_;
      if (result == 0)
        delete this;
      return result;
    }
  else
    {
      return 1;
    }
}
ACE_Event_Handler::Policy::~Policy (void)
{
}
ACE_Event_Handler::Reference_Counting_Policy::Reference_Counting_Policy (Reference_Counting_Policy::Value value)
  : value_ (value)
{
}
ACE_Event_Handler::Reference_Counting_Policy::Value
ACE_Event_Handler::Reference_Counting_Policy::value (void) const
{
  return this->value_;
}
void
ACE_Event_Handler::Reference_Counting_Policy::value (ACE_Event_Handler::Reference_Counting_Policy::Value value)
{
  this->value_ = value;
}
ACE_Event_Handler::Reference_Counting_Policy &
ACE_Event_Handler::reference_counting_policy (void)
{
  return this->reference_counting_policy_;
}
//#if !defined (ACE_HAS_WINCE)
ACE_THR_FUNC_RETURN
ACE_Event_Handler::read_adapter (void *args)
{
  ACE_Event_Handler *this_ptr = static_cast<ACE_Event_Handler *> (args);
  ACE_Reactor *r = this_ptr->reactor ();
  while (this_ptr->handle_input (ACE_STDIN) != -1)
    continue;
  this_ptr->handle_close (ACE_STDIN, ACE_Event_Handler::READ_MASK);
  // It's possible for handle_close() to "delete this" so we need to
  // cache the reactor pointer and use it here.
  r->notify ();
  return 0;
}
int
ACE_Event_Handler::register_stdin_handler (ACE_Event_Handler *eh,
                                           ACE_Reactor *reactor,
                                           ACE_Thread_Manager *thr_mgr,
                                           int flags)
{
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (reactor);
  eh->reactor (reactor);
  return thr_mgr->spawn (&read_adapter, static_cast<void *> (eh), flags);
#else
  // Keep compilers happy.
  ACE_UNUSED_ARG (flags);
  ACE_UNUSED_ARG (thr_mgr);
  return reactor->register_handler (ACE_STDIN,
                                    eh,
                                    ACE_Event_Handler::READ_MASK);
#endif /* ACE_WIN32 */
}
int
ACE_Event_Handler::remove_stdin_handler (ACE_Reactor *reactor,
                                         ACE_Thread_Manager * /* thr_mgr */)
{
#if defined (ACE_WIN32)
  ACE_UNUSED_ARG (reactor);
  // What should we do here?
  ACE_NOTSUP_RETURN (-1);
#else
  return reactor->remove_handler (ACE_STDIN,
                                  ACE_Event_Handler::READ_MASK);
#endif /* ACE_WIN32 */
}
//#endif /* ACE_HAS_WINCE */
// ---------------------------------------------------------------------
ACE_Event_Handler_var::ACE_Event_Handler_var (void)
  : ptr_ (0)
{
}
ACE_Event_Handler_var::ACE_Event_Handler_var (ACE_Event_Handler *p)
  : ptr_ (p)
{
}
ACE_Event_Handler_var::ACE_Event_Handler_var (const ACE_Event_Handler_var &b)
  : ptr_ (b.ptr_)
{
  if (this->ptr_ != 0)
    {
      this->ptr_->add_reference ();
    }
}
ACE_Event_Handler_var::~ACE_Event_Handler_var (void)
{
  if (this->ptr_ != 0)
    {
      ACE_Errno_Guard eguard (errno);
      this->ptr_->remove_reference ();
    }
}
ACE_Event_Handler_var &
ACE_Event_Handler_var::operator= (ACE_Event_Handler *p)
{
  if (this->ptr_ != p)
    {
      ACE_Event_Handler_var tmp (p);
      std::swap (this->ptr_, tmp.ptr_);
    }
  return *this;
}
ACE_Event_Handler_var &
ACE_Event_Handler_var::operator= (const ACE_Event_Handler_var &b)
{
  ACE_Event_Handler_var tmp (b);
  std::swap (this->ptr_, tmp.ptr_);
  return *this;
}
ACE_Event_Handler *
ACE_Event_Handler_var::operator->() const
{
  return this->ptr_;
}
ACE_Event_Handler *
ACE_Event_Handler_var::handler (void) const
{
  return this->ptr_;
}
ACE_Event_Handler *
ACE_Event_Handler_var::release (void)
{
  ACE_Event_Handler * const old = this->ptr_;
  this->ptr_ = 0;
  return old;
}
void
ACE_Event_Handler_var::reset (ACE_Event_Handler *p)
{
  *this = p;
}
// ---------------------------------------------------------------------
ACE_Notification_Buffer::ACE_Notification_Buffer (void)
{
  ACE_TRACE ("ACE_Notification_Buffer::ACE_Notification_Buffer");
}
ACE_Notification_Buffer::ACE_Notification_Buffer (ACE_Event_Handler *eh,
                                                  ACE_Reactor_Mask mask)
  : eh_ (eh),
    mask_ (mask)
{
  ACE_TRACE ("ACE_Notification_Buffer::ACE_Notification_Buffer");
}
ACE_END_VERSIONED_NAMESPACE_DECL

