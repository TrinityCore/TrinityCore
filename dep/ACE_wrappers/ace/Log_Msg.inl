// -*- C++ -*-
//
// $Id: Log_Msg.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
u_long
ACE_Log_Msg::priority_mask (MASK_TYPE mask_type)
{
  return mask_type == THREAD
    ? this->priority_mask_
    :  ACE_Log_Msg::process_priority_mask_;
}

ACE_INLINE
int
ACE_Log_Msg::log_priority_enabled (ACE_Log_Priority log_priority)
{
  return ACE_BIT_ENABLED (this->priority_mask_ |
                          ACE_Log_Msg::process_priority_mask_,
                          log_priority);
}

ACE_INLINE
void
ACE_Log_Msg::op_status (int status)
{
  this->status_ = status;
}

ACE_INLINE
int
ACE_Log_Msg::op_status (void) const
{
  return this->status_;
}

ACE_INLINE
void
ACE_Log_Msg::restart (int r)
{
  this->restart_ = r;
}

ACE_INLINE
int
ACE_Log_Msg::restart (void) const
{
  return this->restart_;
}

ACE_INLINE
int
ACE_Log_Msg::errnum (void) const
{
  return this->errnum_;
}

ACE_INLINE
void
ACE_Log_Msg::errnum (int e)
{
  this->errnum_ = e;
}

ACE_INLINE
int
ACE_Log_Msg::linenum (void) const
{
  return this->linenum_;
}

ACE_INLINE
void
ACE_Log_Msg::linenum (int l)
{
  this->linenum_ = l;
}

ACE_INLINE
int
ACE_Log_Msg::inc (void)
{
  return this->trace_depth_++;
}

ACE_INLINE
int
ACE_Log_Msg::dec (void)
{
  return this->trace_depth_ == 0 ? 0 : --this->trace_depth_;
}

ACE_INLINE
int
ACE_Log_Msg::trace_depth (void) const
{
  return this->trace_depth_;
}

ACE_INLINE
void
ACE_Log_Msg::trace_depth (int depth)
{
  this->trace_depth_ = depth;
}

ACE_INLINE
bool
ACE_Log_Msg::trace_active (void) const
{
  return this->trace_active_;
}

ACE_INLINE
void
ACE_Log_Msg::trace_active (bool value)
{
  this->trace_active_ = value;
}

ACE_INLINE
ACE_Thread_Descriptor *
ACE_Log_Msg::thr_desc (void) const
{
  return this->thr_desc_;
}

/// Enable the tracing facility on a per-thread basis.
ACE_INLINE
void
ACE_Log_Msg::start_tracing (void)
{
  this->tracing_enabled_ = true;
}

/// Disable the tracing facility on a per-thread basis.
ACE_INLINE
void
ACE_Log_Msg::stop_tracing (void)
{
  this->tracing_enabled_ = false;
}

ACE_INLINE
bool
ACE_Log_Msg::tracing_enabled (void) const
{
  return this->tracing_enabled_;
}

ACE_INLINE
const char *
ACE_Log_Msg::file (void)
{
  return this->file_;
}

ACE_INLINE
void
ACE_Log_Msg::file (const char *s)
{
  ACE_OS::strsncpy (this->file_, s, sizeof this->file_);
}

ACE_INLINE
const ACE_TCHAR *
ACE_Log_Msg::msg (void)
{
  return this->msg_ + ACE_Log_Msg::msg_off_;
}

ACE_INLINE
void
ACE_Log_Msg::msg (const ACE_TCHAR *m)
{
  ACE_OS::strsncpy (this->msg_, m,
                    ((ACE_MAXLOGMSGLEN+1) / sizeof (ACE_TCHAR)));
}

ACE_INLINE
ACE_Log_Msg_Callback *
ACE_Log_Msg::msg_callback (void) const
{
  return this->msg_callback_;
}

ACE_INLINE
ACE_Log_Msg_Callback *
ACE_Log_Msg::msg_callback (ACE_Log_Msg_Callback *c)
{
  ACE_Log_Msg_Callback *old = this->msg_callback_;
  this->msg_callback_ = c;
  return old;
}

ACE_INLINE
ACE_OSTREAM_TYPE *
ACE_Log_Msg::msg_ostream (void) const
{
  return this->ostream_;
}

ACE_INLINE
void
ACE_Log_Msg::msg_ostream (ACE_OSTREAM_TYPE *m)
{
  this->ostream_ = m;
}

ACE_INLINE
const ACE_TCHAR *
ACE_Log_Msg::local_host (void) const
{
  return ACE_Log_Msg::local_host_;
}

ACE_INLINE
pid_t
ACE_Log_Msg::getpid (void) const
{
  if (ACE_Log_Msg::pid_ == -2)
    ACE_Log_Msg::pid_ = ACE_OS::getpid ();

  return ACE_Log_Msg::pid_;
}



ACE_END_VERSIONED_NAMESPACE_DECL

