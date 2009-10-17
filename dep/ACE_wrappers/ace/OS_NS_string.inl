// -*- C++ -*-
//
// $Id: OS_NS_string.inl 80826 2008-03-04 14:51:23Z wotte $
// OS_NS_wchar.h is only needed to get the emulation methods.
// Perhaps they should be moved.  dhinton
#include "ace/OS_NS_wchar.h"
#include "ace/os_include/os_string.h"
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
ACE_INLINE const void *
ACE_OS::memchr (const void *s, int c, size_t len)
{
#if !defined (ACE_LACKS_MEMCHR)
  return ::memchr (s, c, len);
#else /* ACE_LACKS_MEMCHR */
  return ACE_OS::memchr_emulation (s, c, len);
#endif /* !ACE_LACKS_MEMCHR */
}
ACE_INLINE void *
ACE_OS::memchr (void *s, int c, size_t len)
{
  return const_cast<void *> (ACE_OS::memchr (static_cast<const void *> (s),
                                             c,
                                             len));
}
ACE_INLINE int
ACE_OS::memcmp (const void *t, const void *s, size_t len)
{
  return ::memcmp (t, s, len);
}
ACE_INLINE void *
ACE_OS::memcpy (void *t, const void *s, size_t len)
{
#if defined (ACE_HAS_MEMCPY_LOOP_UNROLL)
  return fast_memcpy (t, s, len);
#else
  return ::memcpy (t, s, len);
#endif /* ACE_HAS_MEMCPY_LOOP_UNROLL */
}
ACE_INLINE void *
ACE_OS::memmove (void *t, const void *s, size_t len)
{
  return ::memmove (t, s, len);
}
ACE_INLINE void *
ACE_OS::memset (void *s, int c, size_t len)
{
#if defined (ACE_HAS_SLOW_MEMSET)
  // This section requires a high optimization level (-xO4 with SunCC)
  // in order to actually be inlined.
  char* ptr = static_cast<char*> (s);
  switch (len)
    {
    case 16:
      ptr[15] = c;
    case 15:
      ptr[14] = c;
    case 14:
      ptr[13] = c;
    case 13:
      ptr[12] = c;
    case 12:
      ptr[11] = c;
    case 11:
      ptr[10] = c;
    case 10:
      ptr[9] = c;
    case 9:
      ptr[8] = c;
    case 8:
      ptr[7] = c;
    case 7:
      ptr[6] = c;
    case 6:
      ptr[5] = c;
    case 5:
      ptr[4] = c;
    case 4:
      ptr[3] = c;
    case 3:
      ptr[2] = c;
    case 2:
      ptr[1] = c;
    case 1:
      ptr[0] = c;
      break;
    default:
      for (size_t i = 0; i < len; ++i)
        {
          ptr[i] = c;
        }
    }
  return s;
#else
  return ::memset (s, c, len);
#endif /* ACE_HAS_SLOW_MEMSET */
}
ACE_INLINE char *
ACE_OS::strcat (char *s, const char *t)
{
  return ::strcat (s, t);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strcat (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSCAT)
  return ACE_OS::wcscat_emulation (s, t);
#  else /* ACE_LACKS_WCSCAT */
  return ::wcscat (s, t);
#  endif /* ACE_LACKS_WCSCAT */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE const char *
ACE_OS::strchr (const char *s, int c)
{
  return const_cast <const char *> (::strchr (s, c));
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE const wchar_t *
ACE_OS::strchr (const wchar_t *s, wchar_t c)
{
#  if defined (ACE_LACKS_WCSCHR)
  return ACE_OS::wcschr_emulation (s, c);
#  else /* ACE_LACKS_WCSCHR */
  return ::wcschr (s, c);
#  endif /* ACE_LACKS_WCSCHR */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strchr (char *s, int c)
{
  return ::strchr (s, c);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strchr (wchar_t *s, wchar_t c)
{
  return
    const_cast<wchar_t *> (ACE_OS::strchr (const_cast<const wchar_t *> (s),
                                           c));
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE int
ACE_OS::strcmp (const char *s, const char *t)
{
  return ::strcmp (s, t);
}
ACE_INLINE int
ACE_OS::strcmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t)
{
#  if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSCMP)
  return ACE_OS::wcscmp_emulation (s, t);
#  else /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCMP */
  return ::wcscmp (s, t);
#  endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCMP */
}
ACE_INLINE char *
ACE_OS::strcpy (char *s, const char *t)
{
  return ::strcpy (s, t);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strcpy (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSCPY)
  return ACE_OS::wcscpy_emulation (s, t);
#  else /* ACE_LACKS_WCSCPY */
  return ::wcscpy (s, t);
#  endif /* ACE_LACKS_WCSCPY */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE size_t
ACE_OS::strcspn (const char *s, const char *reject)
{
  return ::strcspn (s, reject);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE size_t
ACE_OS::strcspn (const wchar_t *s, const wchar_t *reject)
{
#  if defined (ACE_LACKS_WCSCSPN)
  return ACE_OS::wcscspn_emulation (s, reject);
#  else /* ACE_LACKS_WCSCSPN */
  return ::wcscspn (s, reject);
#  endif /* ACE_LACKS_WCSCSPN */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strdup (const char *s)
{
#  if (defined (ACE_LACKS_STRDUP) && !defined(ACE_STRDUP_EQUIVALENT)) \
  || defined (ACE_HAS_STRDUP_EMULATION)
  return ACE_OS::strdup_emulation (s);
#  elif defined (ACE_STRDUP_EQUIVALENT)
  return ACE_STRDUP_EQUIVALENT (s);
#  elif defined (ACE_HAS_NONCONST_STRDUP)
  return ::strdup (const_cast<char *> (s));
#else
  return ::strdup (s);
#  endif /* (ACE_LACKS_STRDUP && !ACE_STRDUP_EQUIVALENT) || ... */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strdup (const wchar_t *s)
{
#  if (defined (ACE_LACKS_WCSDUP) && !defined (ACE_WCSDUP_EQUIVALENT)) \
  || defined (ACE_HAS_WCSDUMP_EMULATION)
  return ACE_OS::strdup_emulation (s);
#  elif defined (ACE_WCSDUP_EQUIVALENT)
  return ACE_WCSDUP_EQUIVALENT (s);
#  elif defined (ACE_HAS_NONCONST_WCSDUP)
  return ::wcsdup (const_cast<wchar_t*> (s));
#  else
  return ::wcsdup (s);
#  endif /* (ACE_LACKS_WCSDUP && !ACE_WCSDUP_EQUIVALENT) || ... */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE size_t
ACE_OS::strlen (const char *s)
{
  return ::strlen (s);
}
ACE_INLINE size_t
ACE_OS::strlen (const ACE_WCHAR_T *s)
{
# if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSLEN)
  return ACE_OS::wcslen_emulation (s);
# else  /* !ACE_HAS_WCHAR || ACE_LACKS_WCSLEN */
  return ::wcslen (s);
# endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSLEN */
}
ACE_INLINE char *
ACE_OS::strncat (char *s, const char *t, size_t len)
{
#if 0 /* defined (ACE_HAS_TR24731_2005_CRT) */
  strncat_s (s, len + 1, t, _TRUNCATE);
  return s;
#else
  return ::strncat (s, t, len);
#endif /* ACE_HAS_TR24731_2005_CRT */
}
ACE_INLINE ACE_WCHAR_T *
ACE_OS::strncat (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len)
{
#  if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCAT)
  return ACE_OS::wcsncat_emulation (s, t, len);
#  elif 0 /* defined (ACE_HAS_TR24731_2005_CRT) */
  wcsncat_s (s, len + 1, t, _TRUNCATE);
  return s;
#  else /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCAT */
  return ::wcsncat (s, t, len);
#  endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCAT */
}
ACE_INLINE char *
ACE_OS::strnchr (char *s, int c, size_t len)
{
  return const_cast<char *> (ACE_OS::strnchr (static_cast<const char *> (s),
                                              c,
                                              len));
}
ACE_INLINE ACE_WCHAR_T *
ACE_OS::strnchr (ACE_WCHAR_T *s, ACE_WCHAR_T c, size_t len)
{
  return
    const_cast<ACE_WCHAR_T *> (ACE_OS::strnchr (
                                 const_cast<const ACE_WCHAR_T *> (s),
                                 c,
                                 len));
}
ACE_INLINE int
ACE_OS::strncmp (const char *s, const char *t, size_t len)
{
  return ::strncmp (s, t, len);
}
ACE_INLINE int
ACE_OS::strncmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len)
{
#  if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCMP)
  return ACE_OS::wcsncmp_emulation (s, t, len);
#  else /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCMP */
  return ::wcsncmp (s, t, len);
#  endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCMP */
}
ACE_INLINE char *
ACE_OS::strncpy (char *s, const char *t, size_t len)
{
  return ::strncpy (s, t, len);
}
ACE_INLINE ACE_WCHAR_T *
ACE_OS::strncpy (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len)
{
#  if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCPY)
  return ACE_OS::wcsncpy_emulation (s, t, len);
#  else /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCPY */
  return ::wcsncpy (s, t, len);
#  endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCPY */
}
ACE_INLINE size_t
ACE_OS::strnlen (const char *s, size_t maxlen)
{
#if defined (ACE_HAS_STRNLEN)
  return ::strnlen (s, maxlen);
#else /* ACE_HAS_STRNLEN */
  size_t i;
  for (i = 0; i < maxlen; ++i)
    if (s[i] == '\0')
      break;
  return i;
#endif /* ACE_HAS_STRNLEN */
}
ACE_INLINE size_t
ACE_OS::strnlen (const ACE_WCHAR_T *s, size_t maxlen)
{
#if defined (ACE_HAS_WCHAR) && defined (ACE_HAS_WCSNLEN)
  return wcsnlen (s, maxlen);
#else /* ACE_HAS_WCSNLEN */
  size_t i;
  for (i = 0; i < maxlen; ++i)
    if (s[i] == '\0')
      break;
  return i;
#endif /* ACE_HAS_WCSNLEN */
}
ACE_INLINE char *
ACE_OS::strnstr (char *s, const char *t, size_t len)
{
  return
    const_cast <char *> (ACE_OS::strnstr (const_cast <const char *> (s), t, len));
}
ACE_INLINE ACE_WCHAR_T *
ACE_OS::strnstr (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len)
{
  return
    const_cast<ACE_WCHAR_T *> (ACE_OS::strnstr (
                                 static_cast<const ACE_WCHAR_T *> (s),
                                 t,
                                 len));
}
ACE_INLINE const char *
ACE_OS::strpbrk (const char *s1, const char *s2)
{
  return const_cast <const char *> (::strpbrk (s1, s2));
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE const wchar_t *
ACE_OS::strpbrk (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSPBRK)
  return ACE_OS::wcspbrk_emulation (s, t);
#  else /* ACE_LACKS_WCSPBRK */
  return ::wcspbrk (s, t);
#  endif /* ACE_LACKS_WCSPBRK */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strpbrk (char *s1, const char *s2)
{
  return ::strpbrk (s1, s2);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strpbrk (wchar_t *s, const wchar_t *t)
{
  return const_cast<wchar_t *> (ACE_OS::strpbrk (
                                  const_cast<const wchar_t *> (s), t));
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE const char *
ACE_OS::strrchr (const char *s, int c)
{
#if defined (ACE_LACKS_STRRCHR)
  return ACE_OS::strrchr_emulation (s, c);
#else  /* ! ACE_LACKS_STRRCHR */
  return (const char *) ::strrchr (s, c);
#endif /* ! ACE_LACKS_STRRCHR */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE const wchar_t *
ACE_OS::strrchr (const wchar_t *s, wchar_t c)
{
#if defined (ACE_LACKS_WCSRCHR)
  return ACE_OS::wcsrchr_emulation (s, c);
#else /* ! ACE_LACKS_WCSRCHR */
  return const_cast <const wchar_t *> (::wcsrchr (s, c));
#endif /* ! ACE_LACKS_WCSRCHR */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strrchr (char *s, int c)
{
#if defined (ACE_LACKS_STRRCHR)
  return ACE_OS::strrchr_emulation (s, c);
#else  /* ! ACE_LACKS_STRRCHR */
  return ::strrchr (s, c);
#endif /* ! ACE_LACKS_STRRCHR */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strrchr (wchar_t *s, wchar_t c)
{
  return const_cast<wchar_t *> (ACE_OS::strrchr (
                     const_cast<const wchar_t *> (s), c));
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE size_t
ACE_OS::strspn (const char *s, const char *t)
{
  return ::strspn (s, t);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE size_t
ACE_OS::strspn (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSPN)
  return ACE_OS::wcsspn_emulation (s, t);
#  else /* ACE_LACKS_WCSSPN */
  return ::wcsspn (s, t);
#  endif /* ACE_LACKS_WCSSPN */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE const char *
ACE_OS::strstr (const char *s, const char *t)
{
  return (const char *) ::strstr (s, t);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE const wchar_t *
ACE_OS::strstr (const wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSTR)
  return ACE_OS::wcsstr_emulation (s, t);
#  elif defined (HPUX)
  return const_cast <const wchar_t *> (::wcswcs (s, t));
#  else /* ACE_LACKS_WCSSTR */
  return const_cast <const wchar_t *> (::wcsstr (s, t));
#  endif /* ACE_LACKS_WCSSTR */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strstr (char *s, const char *t)
{
  return ::strstr (s, t);
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::strstr (wchar_t *s, const wchar_t *t)
{
#  if defined (ACE_LACKS_WCSSTR)
  return ACE_OS::wcsstr_emulation (s, t);
#  elif defined (HPUX)
  return ::wcswcs (s, t);
#  else /* ACE_LACKS_WCSSTR */
  return ::wcsstr (s, t);
#  endif /* ACE_LACKS_WCSSTR */
}
#endif /* ACE_HAS_WCHAR */
ACE_INLINE char *
ACE_OS::strtok (char *s, const char *tokens)
{
  return ::strtok (s, tokens);
}
#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOK)
ACE_INLINE wchar_t *
ACE_OS::strtok (wchar_t *s, const wchar_t *tokens)
{
#if defined (ACE_HAS_3_PARAM_WCSTOK)
  static wchar_t *lasts = 0;
  return ::wcstok (s, tokens, &lasts);
#else
  return ::wcstok (s, tokens);
#endif /* ACE_HAS_3_PARAM_WCSTOK */
}
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOK */
ACE_INLINE char *
ACE_OS::strtok_r (char *s, const char *tokens, char **lasts)
{
#if defined (ACE_HAS_TR24731_2005_CRT)
  return strtok_s (s, tokens, lasts);
#elif defined (ACE_HAS_REENTRANT_FUNCTIONS) && !defined (ACE_LACKS_STRTOK_R)
  return ::strtok_r (s, tokens, lasts);
#else
  return ACE_OS::strtok_r_emulation (s, tokens, lasts);
#endif /* (ACE_HAS_REENTRANT_FUNCTIONS) */
}
#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t*
ACE_OS::strtok_r (ACE_WCHAR_T *s, const ACE_WCHAR_T *tokens, ACE_WCHAR_T **lasts)
{
#if defined (ACE_HAS_TR24731_2005_CRT)
  return wcstok_s (s, tokens, lasts);
#elif defined (ACE_LACKS_WCSTOK)
  return ACE_OS::strtok_r_emulation (s, tokens, lasts);
#else
#  if defined (ACE_HAS_3_PARAM_WCSTOK)
  return ::wcstok (s, tokens, lasts);
#  else /* ACE_HAS_3_PARAM_WCSTOK */
  *lasts = ::wcstok (s, tokens);
  return *lasts;
#  endif /* ACE_HAS_3_PARAM_WCSTOK */
#endif  /* ACE_LACKS_WCSTOK */
}
#endif  // ACE_HAS_WCHAR
ACE_END_VERSIONED_NAMESPACE_DECL
