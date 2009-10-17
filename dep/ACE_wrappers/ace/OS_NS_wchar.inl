// -*- C++ -*-
//
// $Id: OS_NS_wchar.inl 80826 2008-03-04 14:51:23Z wotte $
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wint_t
ACE_OS::fgetwc (FILE* fp)
{
#  if defined (ACE_LACKS_FGETWC)
  ACE_UNUSED_ARG (fp);
  ACE_NOTSUP_RETURN (0);
#  else
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::fgetwc (fp), wint_t, WEOF);
#  endif /* ACE_LACKS_FGETWC */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE u_int
ACE_OS::wslen (const WChar *s)
{
  u_int len = 0;
  while (*s++ != 0)
    len++;
  return len;
}
ACE_INLINE ACE_OS::WChar *
ACE_OS::wscpy (WChar *dest, const WChar *src)
{
  WChar *original_dest = dest;
  while ((*dest++ = *src++) != 0)
    continue;
  return original_dest;
}
ACE_INLINE int
ACE_OS::wscmp (const WChar *s, const WChar *t)
{
  const WChar *scan1 = s;
  const WChar *scan2 = t;
  while (*scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
    }
  return *scan1 - *scan2;
}
ACE_INLINE int
ACE_OS::wsncmp (const WChar *s, const WChar *t, size_t len)
{
  const WChar *scan1 = s;
  const WChar *scan2 = t;
  while (len != 0 && *scan1 != 0 && *scan1 == *scan2)
    {
      ++scan1;
      ++scan2;
      --len;
    }
  return len == 0 ? 0 : *scan1 - *scan2;
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wint_t
ACE_OS::ungetwc (wint_t c, FILE* fp)
{
#  if defined (ACE_LACKS_FGETWC)
  ACE_UNUSED_ARG (c);
  ACE_UNUSED_ARG (fp);
  ACE_NOTSUP_RETURN (0);
#  else
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::ungetwc (c, fp), wint_t, WEOF);
#  endif /* ACE_LACKS_FGETWC */
}
#endif /* ACE_HAS_WCHAR */
ACE_END_VERSIONED_NAMESPACE_DECL
