// $Id: UNIX_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/UNIX_Addr.h"

ACE_RCSID(ace, UNIX_Addr, "$Id: UNIX_Addr.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (ACE_LACKS_UNIX_DOMAIN_SOCKETS)

#if !defined (__ACE_INLINE__)
#include "ace/UNIX_Addr.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_UNIX_Addr)

// Set a pointer to the address.
void
ACE_UNIX_Addr::set_addr (void *addr, int len)
{
  ACE_TRACE ("ACE_UNIX_Addr::set_addr");

  this->ACE_Addr::base_set (AF_UNIX, len);
  ACE_OS::memcpy ((void *) &this->unix_addr_,
                  (void *) addr,
                  len);
}

// Return a pointer to the underlying address.

void *
ACE_UNIX_Addr::get_addr (void) const
{
  return (void *) &this->unix_addr_;
}

// Transform the string into the current addressing format.

int
ACE_UNIX_Addr::string_to_addr (const char addr[])
{
  ACE_OS::strsncpy (this->unix_addr_.sun_path, addr,
                    sizeof this->unix_addr_.sun_path);
  return 0;
}

// Transform the current address into string format.

int
ACE_UNIX_Addr::addr_to_string (ACE_TCHAR s[], size_t len) const
{
  ACE_OS::strsncpy (s,
                    ACE_TEXT_CHAR_TO_TCHAR (this->unix_addr_.sun_path),
                    len);
  return 0;
}

u_long
ACE_UNIX_Addr::hash (void) const
{
  return ACE::hash_pjw (this->unix_addr_.sun_path);
}

void
ACE_UNIX_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
#endif /* ACE_HAS_DUMP */
}

// Do nothing constructor.

ACE_UNIX_Addr::ACE_UNIX_Addr (void)
  : ACE_Addr (AF_UNIX, sizeof this->unix_addr_)
{
  (void) ACE_OS::memset ((void *) &this->unix_addr_,
                         0,
                         sizeof this->unix_addr_);

  this->unix_addr_.sun_family = AF_UNIX;
}

int
ACE_UNIX_Addr::set (const ACE_UNIX_Addr &sa)
{
  if (sa.get_type () == AF_ANY)
    (void) ACE_OS::memset ((void *) &this->unix_addr_,
                           0,
                           sizeof this->unix_addr_);
  else
    ACE_OS::strcpy (this->unix_addr_.sun_path,
                    sa.unix_addr_.sun_path);

  this->unix_addr_.sun_family = AF_UNIX;
  this->base_set (sa.get_type (), sa.get_size ());

  return 0;
}

// Copy constructor.

ACE_UNIX_Addr::ACE_UNIX_Addr (const ACE_UNIX_Addr &sa)
  : ACE_Addr (AF_UNIX, sa.get_size ())
{
  this->set (sa);
}

int
ACE_UNIX_Addr::set (const sockaddr_un *un, int len)
{
  (void) ACE_OS::memset ((void *) &this->unix_addr_, 0,
                   sizeof this->unix_addr_);
  this->unix_addr_.sun_family = AF_UNIX;
  ACE_OS::strcpy (this->unix_addr_.sun_path, un->sun_path);
  this->base_set (AF_UNIX, len);
  return 0;
}

ACE_UNIX_Addr::ACE_UNIX_Addr (const sockaddr_un *un, int len)
{
  this->set (un, len);
}

int
ACE_UNIX_Addr::set (const char rendezvous_point[])
{
  (void) ACE_OS::memset ((void *) &this->unix_addr_,
                         0,
                         sizeof this->unix_addr_);
  this->unix_addr_.sun_family = AF_UNIX;
  (void) ACE_OS::strsncpy (this->unix_addr_.sun_path,
                           rendezvous_point,
                           sizeof this->unix_addr_.sun_path);

  this->ACE_Addr::base_set (AF_UNIX,
                            sizeof this->unix_addr_ -
                            sizeof (this->unix_addr_.sun_path) +
                            ACE_OS::strlen (this->unix_addr_.sun_path));
  return 0;
}

// Create a ACE_Addr from a UNIX pathname.

ACE_UNIX_Addr::ACE_UNIX_Addr (const char rendezvous_point[])
{
  this->set (rendezvous_point);
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_LACKS_UNIX_DOMAIN_SOCKETS */

