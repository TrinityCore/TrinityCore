// -*- C++ -*-
//
// $Id: OS_NS_poll.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/Time_Value.h"
#include "ace/OS_NS_errno.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_OS::poll (struct pollfd *pollfds,
              unsigned long len,
              const ACE_Time_Value *timeout)
{
  ACE_OS_TRACE ("ACE_OS::poll");
#if defined (ACE_HAS_POLL)
  int to = timeout == 0 ? -1 : int (timeout->msec ());
  ACE_OSCALL_RETURN (::poll (pollfds, len, to), int, -1);
#else
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (pollfds);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_POLL */
}
ACE_INLINE int
ACE_OS::poll (struct pollfd *pollfds,
              unsigned long len,
              const ACE_Time_Value &timeout)
{
  ACE_OS_TRACE ("ACE_OS::poll");
#if defined (ACE_HAS_POLL)
  ACE_OSCALL_RETURN (::poll (pollfds, len, int (timeout.msec ())), int, -1);
#else
  ACE_UNUSED_ARG (timeout);
  ACE_UNUSED_ARG (len);
  ACE_UNUSED_ARG (pollfds);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_POLL */
}
ACE_END_VERSIONED_NAMESPACE_DECL
