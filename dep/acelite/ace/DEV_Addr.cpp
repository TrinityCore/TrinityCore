// $Id: DEV_Addr.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "ace/DEV_Addr.h"
#if !defined (__ACE_INLINE__)
#include "ace/DEV_Addr.inl"
#endif /* __ACE_INLINE__ */

#include "ace/Log_Msg.h"
#include "ace/OS_NS_string.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_ALLOC_HOOK_DEFINE(ACE_DEV_Addr)

// Transform the current address into string format.

int
ACE_DEV_Addr::addr_to_string (ACE_TCHAR *s, size_t len) const
{
  ACE_TRACE ("ACE_DEV_Addr::addr_to_string");

  ACE_OS::strsncpy (s, this->devname_, len);
  return 0;
}

// Return a pointer to the address.

void *
ACE_DEV_Addr::get_addr (void) const
{
  ACE_TRACE ("ACE_DEV_Addr::get_addr");

  return (void *) &this->devname_;
}

void
ACE_DEV_Addr::dump (void) const
{
#if defined (ACE_HAS_DUMP)
  ACE_TRACE ("ACE_DEV_Addr::dump");

  ACE_DEBUG ((LM_DEBUG, ACE_BEGIN_DUMP, this));
  ACE_DEBUG ((LM_DEBUG, ACE_TEXT ("devname_ = %s"), this->devname_));
  ACE_DEBUG ((LM_DEBUG, ACE_END_DUMP));
#endif /* ACE_HAS_DUMP */
}

// Do nothing constructor.

ACE_DEV_Addr::ACE_DEV_Addr (void)
  : ACE_Addr (AF_DEV, sizeof this->devname_)
{
  ACE_TRACE ("ACE_DEV_Addr::ACE_DEV_Addr");

  (void) ACE_OS::memset ((void *) &this->devname_,
                         0, sizeof this->devname_);
}

int
ACE_DEV_Addr::set (const ACE_DEV_Addr &sa)
{
  this->base_set (sa.get_type (), sa.get_size ());

  if (sa.get_type () == AF_ANY)
    (void) ACE_OS::memset ((void *) &this->devname_,
                           0,
                           sizeof this->devname_);
  else
    (void) ACE_OS::strsncpy (this->devname_,
                             sa.devname_,
                             ACE_DEV_Addr::DEVNAME_LENGTH);
  return 0;
}

// Copy constructor.

ACE_DEV_Addr::ACE_DEV_Addr (const ACE_DEV_Addr &sa)
  : ACE_Addr (AF_DEV, sizeof this->devname_)
{
  ACE_TRACE ("ACE_DEV_Addr::ACE_DEV_Addr");

  this->set (sa);
}

ACE_DEV_Addr::ACE_DEV_Addr (const ACE_TCHAR *devname)
  : ACE_Addr (AF_DEV, sizeof this->devname_)
{
  ACE_TRACE ("ACE_DEV_Addr::ACE_DEV_Addr");

  this->set (devname);
}

ACE_DEV_Addr &
ACE_DEV_Addr::operator= (const ACE_DEV_Addr &sa)
{
  ACE_TRACE ("ACE_DEV_Addr::operator=");

  if (this != &sa)
    this->set (sa);

  return *this;
}

ACE_END_VERSIONED_NAMESPACE_DECL
