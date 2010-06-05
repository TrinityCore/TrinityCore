// -*- C++ -*-
//
// $Id: SV_Message.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Global_Macros.h"
#include "ace/config-all.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
ACE_SV_Message::ACE_SV_Message (long t)
  : type_ (t)
{
  ACE_TRACE ("ACE_SV_Message::ACE_SV_Message");
}

ACE_INLINE
ACE_SV_Message::~ACE_SV_Message (void)
{
  ACE_TRACE ("ACE_SV_Message::~ACE_SV_Message");
}

ACE_INLINE long
ACE_SV_Message::type (void) const
{
  ACE_TRACE ("ACE_SV_Message::type");
  return this->type_;
}

ACE_INLINE void
ACE_SV_Message::type (long t)
{
  ACE_TRACE ("ACE_SV_Message::type");
  this->type_ = t;
}

ACE_END_VERSIONED_NAMESPACE_DECL
