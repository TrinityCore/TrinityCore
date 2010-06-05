// $Id: Netlink_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $

//=============================================================================
/**
 *  @file    Netlink_Addr.cpp
 *
 *  $Id: Netlink_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Robert Iakobashvilli <coroberti@gmail.com>
 *  @author Raz Ben Yehuda <raziebe@gmail.com>
 */
//=============================================================================

#include "ace/Netlink_Addr.h"

#ifdef ACE_HAS_NETLINK

#if !defined (__ACE_INLINE__)
#include "ace/Netlink_Addr.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_Netlink_Addr)

int ACE_Netlink_Addr::set (const ACE_Netlink_Addr &sa)
{
  ACE_OS::memset ((void *) &this->nl_,0,sizeof this->nl_);
  this->nl_.nl_family = AF_NETLINK;
  this->base_set (sa.get_type (), sa.get_size ());
  return 0;
}

// Copy constructor.

ACE_Netlink_Addr::ACE_Netlink_Addr (const ACE_Netlink_Addr &sa)
: ACE_Addr (AF_NETLINK, sa.get_size ())
{
  this->set (sa);
}

int ACE_Netlink_Addr::set (const sockaddr_nl *un, int len)
{
  (void) ACE_OS::memcpy ((void *) &this->nl_,un,len);
  return 0;
}

ACE_Netlink_Addr::ACE_Netlink_Addr (const sockaddr_nl *un, int len)
{
  this->set (un, len);
}

int
ACE_Netlink_Addr::get_pid (void) const
{
  return this->nl_.nl_pid;
}

int
ACE_Netlink_Addr::get_gid (void) const
{
  return this->nl_.nl_groups;
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif


