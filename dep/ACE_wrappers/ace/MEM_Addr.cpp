// $Id: MEM_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $

// Defines the Internet domain address family address format.

#include "ace/MEM_Addr.h"

#if (ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1)

#if !defined (__ACE_INLINE__)
#include "ace/MEM_Addr.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_unistd.h"
#include "ace/os_include/os_netdb.h"

ACE_RCSID (ace,
           MEM_Addr,
           "$Id: MEM_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $")

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_MEM_Addr)

// Transform the current address into string format.

ACE_MEM_Addr::ACE_MEM_Addr (void)
  : ACE_Addr (AF_INET, sizeof (ACE_MEM_Addr))
{
  // ACE_TRACE ("ACE_MEM_Addr::ACE_MEM_Addr");
  this->initialize_local (0);
}

ACE_MEM_Addr::ACE_MEM_Addr (const ACE_MEM_Addr &sa)
  : ACE_Addr (AF_INET, sizeof (ACE_MEM_Addr))
{
  ACE_TRACE ("ACE_MEM_Addr::ACE_MEM_Addr");
  this->external_.set (sa.external_);
  this->internal_.set (sa.internal_);
}

ACE_MEM_Addr::ACE_MEM_Addr (const ACE_TCHAR port_number[])
  : ACE_Addr (AF_INET, sizeof (ACE_MEM_Addr))
{
  ACE_TRACE ("ACE_MEM_Addr::ACE_MEM_Addr");
  u_short pn = static_cast<u_short> (ACE_OS::strtoul (port_number,
                                                      0,
                                                      10));
  this->initialize_local (pn);
}

ACE_MEM_Addr::ACE_MEM_Addr (u_short port_number)
  : ACE_Addr (AF_INET, sizeof (ACE_MEM_Addr))
{
  ACE_TRACE ("ACE_MEM_Addr::ACE_MEM_Addr");
  this->initialize_local (port_number);
}

ACE_MEM_Addr::~ACE_MEM_Addr (void)
{
}

int
ACE_MEM_Addr::initialize_local (u_short port_number)
{
  ACE_TCHAR name[MAXHOSTNAMELEN + 1];
  if (ACE_OS::hostname (name, MAXHOSTNAMELEN+1) == -1)
    return -1;

  this->external_.set (port_number, name);
  this->internal_.set (port_number, ACE_TEXT ("localhost"));
  return 0;
}

int
ACE_MEM_Addr::same_host (const ACE_INET_Addr &sap)
{
  ACE_TRACE ("ACE_MEM_Addr::same_host");

  // ACE_INET_Addr::operator== takes port number into account, so get
  // the addresses without a port number and compare.
  ACE_INET_Addr me (this->external_);
  ACE_INET_Addr you (sap);
  me.set_port_number (0);
  you.set_port_number (0);
  return me == you;
}

int
ACE_MEM_Addr::addr_to_string (ACE_TCHAR s[],
                              size_t size,
                              int ipaddr_format) const
{
  ACE_TRACE ("ACE_MEM_Addr::addr_to_string");

  return this->external_.addr_to_string (s, size, ipaddr_format);
}

// Transform the string into the current addressing format.

int
ACE_MEM_Addr::string_to_addr (const ACE_TCHAR s[])
{
  ACE_TRACE ("ACE_MEM_Addr::string_to_addr");

  u_short pn = static_cast<u_short> (ACE_OS::strtoul (s,
                                                      0,
                                                      10));
  return this->set (pn);
}

// Return the address.

void *
ACE_MEM_Addr::get_addr (void) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_addr");
  return this->external_.get_addr ();
}

// Set a pointer to the address.
void
ACE_MEM_Addr::set_addr (void *addr, int len)
{
  ACE_TRACE ("ACE_MEM_Addr::set_addr");

  this->external_.set_addr (addr, len);
  this->internal_.set_port_number (this->external_.get_port_number ());
}

int
ACE_MEM_Addr::get_host_name (ACE_TCHAR hostname[],
                              size_t len) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_host_name");
  return this->external_.get_host_name (hostname, len);
}

// Return the character representation of the hostname.

const char *
ACE_MEM_Addr::get_host_name (void) const
{
  ACE_TRACE ("ACE_MEM_Addr::get_host_name");
  return this->external_.get_host_name ();
}

u_long
ACE_MEM_Addr::hash (void) const
{
  return this->external_.hash ();
}

void
ACE_MEM_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_MEM_Addr::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  this->external_.dump ();
  this->internal_.dump ();
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_HAS_POSITION_INDEPENDENT_POINTERS == 1 */

