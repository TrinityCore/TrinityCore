// -*- C++ -*-
//
// $Id: Log_Record.inl 80826 2008-03-04 14:51:23Z wotte $

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

ACE_INLINE void
ACE_Log_Record::encode (void)
{
  ACE_TRACE ("ACE_Log_Record::encode");
#if !defined (ACE_LACKS_HTONL)
  this->length_ = htonl (this->length_);
  this->type_ = htonl (this->type_);
  // Make sure we don't enclose the sec() and usec() fields until
  // they've been normalized.
  // secs_ is commented out because it can be 64 bits. This method is
  // deprecated; use the CDR operations instead.
  //  this->secs_ = htonl (this->secs_);
  this->usecs_ = htonl (this->usecs_);
  this->pid_ = htonl (this->pid_);
#endif /* ACE_LACKS_HTONL */
}

ACE_INLINE void
ACE_Log_Record::decode (void)
{
  ACE_TRACE ("ACE_Log_Record::decode");
#if !defined (ACE_LACKS_NTOHL)
  ACE_Time_Value tv (this->secs_,
                     ntohl (this->usecs_));

  this->secs_ = tv.sec ();
  this->usecs_ = tv.usec ();
  this->type_ = ntohl (this->type_);
  this->pid_ = ntohl (this->pid_);
  this->length_ = ntohl (this->length_);
#endif /* ACE_LACKS_NTOHL */
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
