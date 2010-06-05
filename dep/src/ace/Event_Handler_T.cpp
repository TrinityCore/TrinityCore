// Event_Handler_T.cpp
//
// $Id: Event_Handler_T.cpp 80826 2008-03-04 14:51:23Z wotte $

#ifndef ACE_EVENT_HANDLER_T_CPP
#define ACE_EVENT_HANDLER_T_CPP

#include "ace/Event_Handler_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_HAS_TEMPLATE_TYPEDEFS)

#if !defined (__ACE_INLINE__)
#include "ace/Event_Handler_T.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Event_Handler_T)

template <class T> void
ACE_Event_Handler_T<T>::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_Event_Handler_T<T>::dump");
#endif /* ACE_HAS_DUMP */
}

template<class T>
ACE_Event_Handler_T<T>::~ACE_Event_Handler_T (void)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::~ACE_Event_Handler_T");
  if (this->delete_handler_)
    delete this->op_handler_;
}

template <class T>
ACE_Event_Handler_T<T>::ACE_Event_Handler_T (T *op_handler, int delete_handler,
                                             GET_HANDLE get_handle,
                                             IO_HANDLER input_h,
                                             CL_HANDLER close_h,
                                             SIG_HANDLER sig_h,
                                             TO_HANDLER timeout_h,
                                             IO_HANDLER output_h,
                                             SET_HANDLE set_handle,
                                             IO_HANDLER except_h)
  : op_handler_ (op_handler),
    input_handler_ (input_h),
    output_handler_ (output_h),
    except_handler_ (except_h),
    to_handler_ (timeout_h),
    cl_handler_ (close_h),
    sig_handler_ (sig_h),
    delete_handler_ (delete_handler),
    set_handle_ (set_handle),
    get_handle_ (get_handle)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::ACE_Event_Handler_T");
}

template<class T> ACE_HANDLE
ACE_Event_Handler_T<T>::get_handle (void) const
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::get_handle");
  return this->get_handle_ == 0 ? ACE_INVALID_HANDLE : (this->op_handler_->*get_handle_) ();
}

template<class T> void
ACE_Event_Handler_T<T>::set_handle (ACE_HANDLE h)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::set_handle");
  if (this->set_handle_ != 0)
    (this->op_handler_->*set_handle_) (h);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_input (ACE_HANDLE fd)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_input");
  return this->input_handler_ == 0 ? 0 : (this->op_handler_->*input_handler_) (fd);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_output (ACE_HANDLE fd)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_output");
  return this->output_handler_ == 0 ? 0 : (this->op_handler_->*output_handler_) (fd);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_exception (ACE_HANDLE fd)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_exception");
  return this->except_handler_ == 0 ? 0 : (this->op_handler_->*except_handler_) (fd);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_timeout (const ACE_Time_Value &tv, const void *arg)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_timeout");
  return this->to_handler_ == 0 ? 0 : (this->op_handler_->*to_handler_) (tv, arg);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_close (ACE_HANDLE fd, ACE_Reactor_Mask close_mask)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_close");
  return this->cl_handler_ == 0 ? 0 : (this->op_handler_->*cl_handler_) (fd, close_mask);
}

template<class T> int
ACE_Event_Handler_T<T>::handle_signal (int signum, siginfo_t *s, ucontext_t *u)
{
  ACE_TRACE ("ACE_Event_Handler_T<T>::handle_signal");
  return this->sig_handler_ == 0 ? 0 : (this->op_handler_->*sig_handler_) (signum, s, u);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_TEMPLATE_TYPEDEFS */

#endif /* ACE_EVENT_HANDLER_T_CPP */

