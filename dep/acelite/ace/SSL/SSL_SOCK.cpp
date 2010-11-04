// $Id: SSL_SOCK.cpp 91368 2010-08-16 13:03:34Z mhengstmengel $

#include "SSL_SOCK.h"

#if !defined (__ACE_INLINE__)
#include "SSL_SOCK.inl"
#endif /* __ACE_INLINE__ */

#include "ace/OS_NS_errno.h"
#include "ace/os_include/os_signal.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_SSL_SOCK::ACE_SSL_SOCK (void)
{
  ACE_TRACE ("ACE_SSL_SOCK::ACE_SSL_SOCK");
}

ACE_SSL_SOCK::~ACE_SSL_SOCK (void)
{
  ACE_TRACE ("ACE_SSL_SOCK::~ACE_SSL_SOCK");
}

int
ACE_SSL_SOCK::enable (int value) const
{
  ACE_TRACE ("ACE_SSL_SOCK::enable");

  switch (value)
    {
#ifdef SIGURG
    case SIGURG:
    case ACE_SIGURG:
#endif  /* SIGURG */
    case SIGIO:
    case ACE_SIGIO:
    case ACE_CLOEXEC:
      ACE_NOTSUP_RETURN (-1);
    case ACE_NONBLOCK:
      return ACE_IPC_SAP::enable (value);
    default:
      return -1;
    }
}

int
ACE_SSL_SOCK::disable (int value) const
{
  ACE_TRACE("ACE_SSL_SOCK::disable");
  switch (value)
    {
#ifdef SIGURG
    case SIGURG:
    case ACE_SIGURG:
#endif  /* SIGURG */
    case SIGIO:
    case ACE_SIGIO:
    case ACE_CLOEXEC:
      ACE_NOTSUP_RETURN (-1);
    case ACE_NONBLOCK:
      return ACE_IPC_SAP::disable (value);
    default:
      return -1;
    }
}

ACE_END_VERSIONED_NAMESPACE_DECL
