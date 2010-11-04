// -*- C++ -*-
// $Id: OS_NS_wctype.inl 91781 2010-09-15 12:49:15Z johnnyw $

#if defined (ACE_LACKS_ISWCTYPE)
#include "ace/OS_NS_errno.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::ace_iswctype(wint_t c, wctype_t desc)
{
#if !defined (ACE_LACKS_ISWCTYPE)
  return iswctype (c, desc);
#else
  ACE_UNUSED_ARG (c);
  ACE_UNUSED_ARG (desc);
  ACE_NOTSUP_RETURN (-1);
#endif
}
#endif /* ACE_HAS_WCHAR */

ACE_END_VERSIONED_NAMESPACE_DECL
