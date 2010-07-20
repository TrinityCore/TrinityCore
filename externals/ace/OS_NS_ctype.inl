// -*- C++ -*-
//
// $Id: OS_NS_ctype.inl 85785 2009-06-24 18:20:42Z mitza $

#if defined (ACE_LACKS_ISCTYPE)
#include "ace/OS_NS_errno.h"
#endif

#if defined (ACE_USES_WCHAR) && defined (ACE_LACKS_ISWBLANK) && !defined (ACE_LACKS_ISWCTYPE)
#include "ace/OS_NS_wctype.h"
#endif

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_OS::ace_isalnum (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
# if defined (_MSC_VER)
  // For MSVC 7.x, we need to prevent "illegal" character getting into
  // isalnum, otherwise, it will crash the program.
  return c > 0 && c < 0xFF && iswalnum (c);
# else
  return iswalnum (c);
# endif /* _MSC_VER */
#else /* ACE_USES_WCHAR */
  return isalnum ((unsigned char) c);
#endif /* ACE_USES_WCHAR */
}

ACE_INLINE int
ACE_OS::ace_isascii (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
# if defined (ACE_LACKS_ISWASCII)
  if (c < 256)
    return isascii (static_cast<int> (c));
  else
    return c;
# else
  return iswascii (c);
# endif
#else /* ACE_USES_WCHAR */
# if defined (ACE_LACKS_ISASCII)
  return (static_cast<unsigned char>(c) <= 0x7F);
#else
  return isascii ((unsigned char) c);
#endif /* ACE_LACKS_ISASCII */
#endif /* ACE_USES_WCHAR */
}

ACE_INLINE int
ACE_OS::ace_isblank (ACE_TCHAR c)
{
#if defined (ACE_USES_WCHAR)
# if defined (ACE_LACKS_ISWBLANK)
#  if !defined (ACE_LACKS_ISWCTYPE)
  return ace_iswctype (c, _BLANK);
#  else
  return (c == 0x9) || (c == 0x20);
#  endif /* !ACE_LACKS_ISWCTYPE */
# else
   return iswblank (c);
# endif /* ACE_LACKS_ISWBLANK */
#elif defined (ACE_LACKS_ISBLANK)
  return (c == 0x9) || (c == 0x20);
#else /* ACE_USES_WCHAR */
  return isblank ((unsigned char) c);
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
# if defined (ACE_LACKS_CORRECT_ISWPRINT_TAB)
  /* The MS CRT has the bug that for tab (\t) iswprint returns true instead of
   * false.  This has been reported to Microsoft:
   * https://connect.microsoft.com/VisualStudio/feedback ID# 381915
   */
  if (c == 0x9)
    {
      return 0;
    }
# endif
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

ACE_INLINE int
ACE_OS::ace_isctype(int c, ctype_t desc)
{
#if defined (ACE_ISCTYPE_EQUIVALENT)
  return ACE_ISCTYPE_EQUIVALENT (c, desc);
#elif !defined (ACE_LACKS_ISCTYPE)
  return isctype (c, desc);
#else
  ACE_UNUSED_ARG (c);
  ACE_UNUSED_ARG (desc);
  ACE_NOTSUP_RETURN (-1);
#endif
}

ACE_END_VERSIONED_NAMESPACE_DECL
