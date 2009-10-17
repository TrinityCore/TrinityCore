// -*- C++ -*-
//
// $Id: MEM_Addr.inl 80826 2008-03-04 14:51:23Z wotte $

#include "ace/Global_Macros.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Set the port number.

ACE_INLINE void
ACE_MEM_Addr::set_port_number (u_short port_number,
                                int encode)
{
  ACE_TRACE ("ACE_MEM_Addr::set_port_number");

  this->external_.set_port_number (port_number, encode);
  this->internal_.set_port_number (port_number, encode);
}

ACE_INLINE int
ACE_MEM_Addr::set (u_short port_number, int encode)
{
  ACE_TRACE ("ACE_MEM_Addr::set");
  this->set_port_number (port_number, encode);
  return 0;
}

ACE_INLINE int
ACE_MEM_Addr::set (const ACE_TCHAR port_number[])
{
  ACE_TRACE ("ACE_MEM_Addr::set");
  return this->string_to_addr (port_number);
}

// Return the port number.

ACE_INLINE u_short
ACE_MEM_Addr::get_port_number (void) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_port_number");
  return this->internal_.get_port_number ();
}

// Return the dotted Internet address.

ACE_INLINE const char *
ACE_MEM_Addr::get_host_addr (void) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_host_addr");
  return this->internal_.get_host_addr ();
}

// Return the 4-byte IP address, converting it into host byte order.

ACE_INLINE ACE_UINT32
ACE_MEM_Addr::get_ip_address (void) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_ip_address");
  return this->external_.get_ip_address ();
}

ACE_INLINE const ACE_INET_Addr &
ACE_MEM_Addr::get_local_addr (void) const
{
  return this->internal_;
}

ACE_INLINE const ACE_INET_Addr &
ACE_MEM_Addr::get_remote_addr (void) const
{
  return this->external_;
}

// Compare two addresses for equality.

ACE_INLINE bool
ACE_MEM_Addr::operator == (const ACE_MEM_Addr &sap) const
{
  ACE_TRACE ("ACE_MEM_Addr::operator ==");

  return this->external_ == sap.external_ &&
    this->internal_ == sap.internal_;
}

ACE_INLINE bool
ACE_MEM_Addr::operator == (const ACE_INET_Addr &sap) const
{
  ACE_TRACE ("ACE_MEM_Addr::operator ==");

  return this->external_ == sap;
}

// Compare two addresses for inequality.

ACE_INLINE bool
ACE_MEM_Addr::operator != (const ACE_MEM_Addr &sap) const
{
  ACE_TRACE ("ACE_MEM_Addr::operator !=");
  return !((*this) == sap);
}

ACE_INLINE bool
ACE_MEM_Addr::operator != (const ACE_INET_Addr &sap) const
{
  ACE_TRACE ("ACE_MEM_Addr::operator !=");
  return !((*this) == sap);
}

ACE_END_VERSIONED_NAMESPACE_DECL
