// -*- C++ -*-
//
// $Id: Service_Types.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/ACE.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE void *
ACE_Service_Type_Impl::object (void) const
{
  ACE_TRACE ("ACE_Service_Type_Impl::object");
  return this->obj_;
}

ACE_INLINE const ACE_TCHAR *
ACE_Service_Type_Impl::name (void) const
{
  ACE_TRACE ("ACE_Service_Type_Impl::name");
  return this->name_;
}

ACE_INLINE void
ACE_Service_Type_Impl::name (const ACE_TCHAR *n)
{
  ACE_TRACE ("ACE_Service_Type_Impl::name");

  ACE::strdelete (const_cast<ACE_TCHAR*> (this->name_));
  this->name_ = ACE::strnew (n);
}

ACE_END_VERSIONED_NAMESPACE_DECL
