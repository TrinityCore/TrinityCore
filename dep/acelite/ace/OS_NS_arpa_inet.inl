// -*- C++ -*-
// $Id: OS_NS_arpa_inet.inl 84249 2009-01-28 09:09:41Z johnnyw $

#include "ace/OS_NS_string.h"
#include "ace/OS_NS_errno.h"
#include "ace/OS_NS_stdio.h"

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE unsigned long
ACE_OS::inet_addr (const char *name)
{
  ACE_OS_TRACE ("ACE_OS::inet_addr");
#if defined (ACE_LACKS_INET_ADDR)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_HAS_NONCONST_INET_ADDR)
  return ::inet_addr (const_cast <char*> (name));
#else
  return ::inet_addr (name);
#endif /* ACE_HAS_NONCONST_INET_ADDR */
}

ACE_INLINE char *
ACE_OS::inet_ntoa (const struct in_addr addr)
{
  ACE_OS_TRACE ("ACE_OS::inet_ntoa");
#if defined (ACE_LACKS_INET_NTOA)
  ACE_UNUSED_ARG (addr);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::inet_ntoa (addr),
                     char *,
                     0);
#endif
}

ACE_INLINE const char *
ACE_OS::inet_ntop (int family, const void *addrptr, char *strptr, size_t len)
{
  ACE_OS_TRACE ("ACE_OS::inet_ntop");

#if defined (ACE_HAS_IPV6) && !defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::inet_ntop (family, addrptr, strptr, len), const char *, 0);
#else
  const u_char *p = reinterpret_cast<const u_char *> (addrptr);

  if (family == AF_INET)
    {
      char temp[INET_ADDRSTRLEN];

      // Stevens uses snprintf() in his implementation but snprintf()
      // doesn't appear to be very portable.  For now, hope that using
      // sprintf() will not cause any string/memory overrun problems.
      ACE_OS::sprintf (temp,
                       "%d.%d.%d.%d",
                       p[0], p[1], p[2], p[3]);

      if (ACE_OS::strlen (temp) >= len)
        {
          errno = ENOSPC;
          return 0; // Failure
        }

      ACE_OS::strcpy (strptr, temp);
      return strptr;
    }

  ACE_NOTSUP_RETURN(0);
#endif /* ACE_HAS_IPV6 */
}

ACE_INLINE int
ACE_OS::inet_pton (int family, const char *strptr, void *addrptr)
{
  ACE_OS_TRACE ("ACE_OS::inet_pton");

#if defined (ACE_HAS_IPV6) && !defined (ACE_WIN32)
  ACE_OSCALL_RETURN (::inet_pton (family, strptr, addrptr), int, -1);
#else
  if (family == AF_INET)
    {
      struct in_addr in_val;

      if (ACE_OS::inet_aton (strptr, &in_val))
        {
          ACE_OS::memcpy (addrptr, &in_val, sizeof (struct in_addr));
          return 1; // Success
        }

      return 0; // Input is not a valid presentation format
    }

  ACE_NOTSUP_RETURN(-1);
#endif  /* ACE_HAS_IPV6 */
}

ACE_END_VERSIONED_NAMESPACE_DECL
