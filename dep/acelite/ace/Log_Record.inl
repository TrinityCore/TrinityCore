// -*- C++ -*-
//
// $Id: Log_Record.inl 91764 2010-09-14 13:04:37Z johnnyw $

#include "ace/Global_Macros.h"
#include "ace/os_include/arpa/os_inet.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_Log_Record::~ACE_Log_Record (void)
{
  if (this->msg_data_)
    delete [] this->msg_data_;
}

ACE_INLINE ACE_UINT32
ACE_Log_Record::type (void) const
{
  ACE_TRACE ("ACE_Log_Record::type");
  return this->type_;
}

ACE_INLINE void
ACE_Log_Record::type (ACE_UINT32 t)
{
  ACE_TRACE ("ACE_Log_Record::type");
  this->type_ = t;
}

ACE_INLINE long
ACE_Log_Record::length (void) const
{
  ACE_TRACE ("ACE_Log_Record::length");
  return (long) this->length_;
}

ACE_INLINE void
ACE_Log_Record::length (long l)
{
  ACE_TRACE ("ACE_Log_Record::length");
  this->length_ = static_cast<ACE_UINT32> (l);
}

ACE_INLINE ACE_Time_Value
ACE_Log_Record::time_stamp (void) const
{
  ACE_TRACE ("ACE_Log_Record::time_stamp");
  return ACE_Time_Value (this->secs_, (long) this->usecs_);
}

ACE_INLINE void
ACE_Log_Record::time_stamp (const ACE_Time_Value &ts)
{
  ACE_TRACE ("ACE_Log_Record::time_stamp");
  this->secs_ = ts.sec ();
  this->usecs_ = (ACE_UINT32) ts.usec ();
}

ACE_INLINE long
ACE_Log_Record::pid (void) const
{
  ACE_TRACE ("ACE_Log_Record::pid");
  return (long) this->pid_;
}

ACE_INLINE void
ACE_Log_Record::pid (long p)
{
  ACE_TRACE ("ACE_Log_Record::pid");
  this->pid_ = (ACE_UINT32) p;
}

ACE_INLINE const ACE_TCHAR *
ACE_Log_Record::msg_data (void) const
{
  ACE_TRACE ("ACE_Log_Record::msg_data");
  return this->msg_data_;
}

ACE_INLINE size_t
ACE_Log_Record::msg_data_len (void) const
{
  ACE_TRACE ("ACE_Log_Record::msg_data_len");
  return ACE_OS::strlen (this->msg_data_) + 1;
}

ACE_END_VERSIONED_NAMESPACE_DECL
