// -*- C++ -*-
//
// $Id: TLI.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/TLI.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE
int
ACE_TLI::look (void) const
{
  ACE_TRACE ("ACE_TLI::look");
  return ACE_OS::t_look (this->get_handle ());
}

ACE_INLINE
int
ACE_TLI::rcvdis (struct t_discon *discon) const
{
  ACE_TRACE ("ACE_TLI::rcvdis");
  return ACE_OS::t_rcvdis (this->get_handle (), discon);
}

ACE_INLINE
int
ACE_TLI::snddis (struct t_call *call) const
{
  ACE_TRACE ("ACE_TLI::snddis");
  return ACE_OS::t_snddis (this->get_handle (), call);
}

ACE_INLINE
int
ACE_TLI::rcvrel (void) const
{
  ACE_TRACE ("ACE_TLI::rcvrel");
  return ACE_OS::t_rcvrel (this->get_handle ());
}

ACE_INLINE
int
ACE_TLI::sndrel (void) const
{
  ACE_TRACE ("ACE_TLI::sndrel");
  return ACE_OS::t_sndrel (this->get_handle ());
}

ACE_END_VERSIONED_NAMESPACE_DECL
