// -*- C++ -*-
//
// $Id: OS_NS_regex.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/OS_NS_errno.h"
#include "ace/os_include/os_regex.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE char *
ACE_OS::compile (const char *instring, char *expbuf, char *endbuf)
{
  ACE_OS_TRACE ("ACE_OS::compile");
#if defined (ACE_HAS_REGEX)
  ACE_OSCALL_RETURN (::compile (instring, expbuf, endbuf), char *, 0);
#else
  ACE_UNUSED_ARG (instring);
  ACE_UNUSED_ARG (expbuf);
  ACE_UNUSED_ARG (endbuf);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_HAS_REGEX */
}
ACE_INLINE int
ACE_OS::step (const char *str, char *expbuf)
{
  ACE_OS_TRACE ("ACE_OS::step");
#if defined (ACE_HAS_REGEX)
  ACE_OSCALL_RETURN (::step (str, expbuf), int, -1);
#else
  ACE_UNUSED_ARG (str);
  ACE_UNUSED_ARG (expbuf);
  ACE_NOTSUP_RETURN (-1);
#endif /* ACE_HAS_REGEX */
}
ACE_END_VERSIONED_NAMESPACE_DECL
