// -*- C++ -*-
//
// $Id: OS_NS_ctype.inl 80826 2008-03-04 14:51:23Z wotte $
#include "ace/os_include/os_ctype.h"
#if defined ACE_HAS_WCHAR
# include "ace/os_include/os_wctype.h"
#endif /* ACE_HAS_WCHAR */
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE int
ACE_OS::ace_isalnum (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
# if defined (_MSC_VER) && (_MSC_VER >= 1300)
  // For MSVC 7.x, we need to prevent "illegal" character getting into
  // isalnum, otherwise, it will crash the program.
  return c > 0 && c < 256 && iswalnum (c);
# else
  return iswalnum (c);
# endif /* _MSC_VER && _MSC_VER >= 1300 */
#else /* ACE_USES_WCHAR */
  return isalnum ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isalpha (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswalpha (c);
#else /* ACE_USES_WCHAR */
  return isalpha ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_iscntrl (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswcntrl (c);
#else /* ACE_USES_WCHAR */
  return iscntrl ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isdigit (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswdigit (c);
#else /* ACE_USES_WCHAR */
  return isdigit ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isgraph (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswgraph (c);
#else /* ACE_USES_WCHAR */
  return isgraph ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_islower (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswlower (c);
#else /* ACE_USES_WCHAR */
  return islower ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isprint (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswprint (c);
#else /* ACE_USES_WCHAR */
  return isprint ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_ispunct (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswpunct (c);
#else /* ACE_USES_WCHAR */
  return ispunct ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isspace (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswspace (c);
#else /* ACE_USES_WCHAR */
  return isspace ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isupper (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswupper (c);
#else /* ACE_USES_WCHAR */
  return isupper ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_isxdigit (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
  return iswxdigit (c);
#else /* ACE_USES_WCHAR */
  return isxdigit ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}
ACE_INLINE int
ACE_OS::ace_tolower (int c)
{
  return tolower (c);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wint_t
ACE_OS::ace_towlower (wint_t c)
{
#if defined (ACE_LACKS_TOWLOWER)
  if (c < 256)
    return tolower (static_cast<int> (c));
  else
    return c;
#else
  return towlower (c);
#endif /* ACE_LACKS_TOWLOWER */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE int
ACE_OS::ace_toupper (int c)
{
  return toupper (c);
}
#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_TOWUPPER)
ACE_INLINE wint_t
ACE_OS::ace_towupper (wint_t c)
{
  return towupper (c);
}
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_TOWUPPER */
ACE_END_VERSIONED_NAMESPACE_DECL
