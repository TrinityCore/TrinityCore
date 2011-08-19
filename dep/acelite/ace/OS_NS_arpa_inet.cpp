// -*- C++ -*-
// $Id: OS_NS_arpa_inet.cpp 91781 2010-09-15 12:49:15Z johnnyw $

#include "ace/OS_NS_arpa_inet.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_arpa_inet.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

int
ACE_OS::inet_aton (const char *host_name, struct in_addr *addr)
{
#if defined (ACE_LACKS_INET_ATON)
#  if defined (ACE_WIN32)
  // Windows Server 2003 changed the behavior of a zero-length input
  // string to inet_addr(). It used to return 0 (INADDR_ANY) but now
  // returns -1 (INADDR_NONE). It will return INADDR_ANY for a 1-space
  // string, though, as do previous versions of Windows.
  if (host_name == 0 || host_name[0] == '\0')
    host_name = " ";
#  endif /* ACE_WIN32 */
  unsigned long ip_addr = ACE_OS::inet_addr (host_name);

  if (ip_addr == INADDR_NONE
      // Broadcast addresses are weird...
      && ACE_OS::strcmp (host_name, "255.255.255.255") != 0)
    return 0;
  else if (addr == 0)
    return 0;
  else
    {
      addr->s_addr = ip_addr;  // Network byte ordered
      return 1;
    }
#elif defined (ACE_VXWORKS) && (ACE_VXWORKS <= 0x680)
  // inet_aton() returns OK (0) on success and ERROR (-1) on failure.
  // Must reset errno first. Refer to WindRiver SPR# 34949, SPR# 36026
  ::errnoSet(0);
  int result = ERROR;
  ACE_OSCALL (::inet_aton (const_cast <char*>(host_name), addr), int, ERROR, result);
  return (result == ERROR) ? 0 : 1;
#else
  // inet_aton() returns 0 upon failure, not -1 since -1 is a valid
  // address (255.255.255.255).
  ACE_OSCALL_RETURN (::inet_aton (host_name, addr), int, 0);
#endif  /* ACE_LACKS_INET_ATON */
}

ACE_END_VERSIONED_NAMESPACE_DECL
