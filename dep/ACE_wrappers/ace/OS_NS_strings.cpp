// $Id: OS_NS_strings.cpp 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_strings.h"
ACE_RCSID(ace, OS_NS_strings, "$Id: OS_NS_strings.cpp 80826 2008-03-04 14:51:23Z wotte $")
#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_strings.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */
#if defined (ACE_LACKS_STRCASECMP)
#  include "ace/OS_NS_ctype.h"
#endif /* ACE_LACKS_STRCASECMP */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_LACKS_STRCASECMP)
int
ACE_OS::strcasecmp_emulation (const char *s, const char *t)
{
  const char *scan1 = s;
  const char *scan2 = t;
  while (*scan1 != 0
         && ACE_OS::ace_tolower (*scan1)
            == ACE_OS::ace_tolower (*scan2))
    {
      ++scan1;
      ++scan2;
    }
  // The following case analysis is necessary so that characters which
  // look negative collate low against normal characters but high
  // against the end-of-string NUL.
  if (*scan1 == '\0' && *scan2 == '\0')
    return 0;
  else if (*scan1 == '\0')
    return -1;
  else if (*scan2 == '\0')
    return 1;
  else
    return ACE_OS::ace_tolower (*scan1) - ACE_OS::ace_tolower (*scan2);
}
#endif /* ACE_LACKS_STRCASECMP */
#if defined (ACE_LACKS_STRCASECMP)
int
ACE_OS::strncasecmp_emulation (const char *s,
                               const char *t,
                               size_t len)
{
  const char *scan1 = s;
  const char *scan2 = t;
  size_t count = 0;
  while (count++ < len
         && *scan1 != 0
         && ACE_OS::ace_tolower (*scan1)
            == ACE_OS::ace_tolower (*scan2))
    {
      ++scan1;
      ++scan2;
    }
  if (count > len)
    return 0;
  // The following case analysis is necessary so that characters which
  // look negative collate low against normal characters but high
  // against the end-of-string NUL.
  if (*scan1 == '\0' && *scan2 == '\0')
    return 0;
  else if (*scan1 == '\0')
    return -1;
  else if (*scan2 == '\0')
    return 1;
  else
    return ACE_OS::ace_tolower (*scan1) - ACE_OS::ace_tolower (*scan2);
}
#endif /* ACE_LACKS_STRCASECMP */
ACE_END_VERSIONED_NAMESPACE_DECL

