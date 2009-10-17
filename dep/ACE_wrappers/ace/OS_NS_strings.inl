// -*- C++ -*-
//
// $Id: OS_NS_strings.inl 80826 2008-03-04 14:51:23Z wotte $
#if defined (ACE_HAS_WCHAR)
#  include "ace/OS_NS_wchar.h"
#endif /* ACE_HAS_WCHAR */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_OS::strcasecmp (const char *s, const char *t)
{
#if defined (ACE_LACKS_STRCASECMP)
  return ACE_OS::strcasecmp_emulation (s, t);
#elif defined (ACE_STRCASECMP_EQUIVALENT)
  return ACE_STRCASECMP_EQUIVALENT (s, t);
#else /* ACE_LACKS_STRCASECMP */
  return ::strcasecmp (s, t);
#endif /* ACE_LACKS_STRCASECMP */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::strcasecmp (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSICMP)
  return ACE_OS::wcsicmp_emulation (s, t);
#  else  /* ACE_LACKS_WCSICMP */
  return ::_wcsicmp (s, t);
#  endif /* ACE_LACKS_WCSICMP */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE int
ACE_OS::strncasecmp (const char *s, const char *t, size_t len)
{
#if defined (ACE_LACKS_STRCASECMP)
  return ACE_OS::strncasecmp_emulation (s, t, len);
#elif defined (ACE_STRNCASECMP_EQUIVALENT)
  return ACE_STRNCASECMP_EQUIVALENT (s, t, len);
#else /* ACE_LACKS_STRCASECMP */
  return ::strncasecmp (s, t, len);
#endif /* ACE_LACKS_STRCASECMP */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::strncasecmp (const wchar_t *s, const wchar_t *t, size_t len)
{
#if defined (ACE_LACKS_WCSNICMP)
  return ACE_OS::wcsnicmp_emulation (s, t, len);
#else  /* ACE_LACKS_WCSNICMP */
  return ::_wcsnicmp (s, t, len);
#endif /* ACE_LACKS_WCSNICMP */
}
#endif /* ACE_HAS_WCHAR */
ACE_END_VERSIONED_NAMESPACE_DECL
