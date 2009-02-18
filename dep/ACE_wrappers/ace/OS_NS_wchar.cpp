// $Id: OS_NS_wchar.cpp 80826 2008-03-04 14:51:23Z wotte $

#include "ace/OS_NS_wchar.h"

ACE_RCSID(ace, OS_NS_wchar, "$Id: OS_NS_wchar.cpp 80826 2008-03-04 14:51:23Z wotte $")

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_wchar.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#if defined (ACE_HAS_WCHAR)
#  include "ace/OS_NS_ctype.h"
#  include "ace/OS_NS_string.h"
#endif /* ACE_HAS_WCHAR */

// The following wcs*_emulation methods were created based on BSD code:
/*-
 * Copyright (c) 1991, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * James W. Williams of NASA Goddard Space Flight Center.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCAT)
wchar_t *
ACE_OS::wcscat_emulation (wchar_t *destination,
                          const wchar_t *source)
{
  wchar_t *save = destination;

  for (; *destination; ++destination);
  while ((*destination++ = *source++));
  return save;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCAT */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCHR)
wchar_t *
ACE_OS::wcschr_emulation (const wchar_t *string, wchar_t c)
{
  for (;*string ; ++string)
    if (*string == c)
      return const_cast<wchar_t *> (string);

  return 0;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCHR */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSCMP)
int
ACE_OS::wcscmp_emulation (const ACE_WCHAR_T *string1,
                          const ACE_WCHAR_T *string2)
{
  while (*string1 == *string2++)
    if (*string1++ == 0)
      return (0);
  return (*string1 - *--string2);
}
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCMP */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCPY)
wchar_t *
ACE_OS::wcscpy_emulation (wchar_t *destination,
                          const wchar_t *source)
{
  wchar_t *save = destination;

  for (; (*destination = *source); ++source, ++destination);
  return save;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCPY */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSCSPN)
size_t
ACE_OS::wcscspn_emulation (const wchar_t *s, const wchar_t *reject)
{
  const wchar_t *scan = 0;
  const wchar_t *rej_scan = 0;
  int count = 0;

  for (scan = s; *scan; scan++)
    {

      for (rej_scan = reject; *rej_scan; rej_scan++)
        if (*scan == *rej_scan)
          return count;

      count++;
    }

  return count;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSCSPN */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSICMP)
int
ACE_OS::wcsicmp_emulation (const wchar_t *s, const wchar_t *t)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;

  while (*scan1 != 0
         && ACE_OS::ace_towlower (*scan1)
            == ACE_OS::ace_towlower (*scan2))
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
    return ACE_OS::ace_tolower (*scan1) - ACE_OS::ace_towlower (*scan2);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSICMP */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSLEN)
size_t
ACE_OS::wcslen_emulation (const ACE_WCHAR_T *string)
{
  const ACE_WCHAR_T *s;

  for (s = string; *s; ++s)
    continue;

  return s - string;
}
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSLEN */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCAT)
ACE_WCHAR_T *
ACE_OS::wcsncat_emulation (ACE_WCHAR_T *destination,
                           const ACE_WCHAR_T *source,
                           size_t count)
{
  if (count != 0)
    {
      ACE_WCHAR_T *d = destination;
      const ACE_WCHAR_T *s = source;

      while (*d != 0)
        d++;

      do
        {
          if ((*d = *s++) == 0)
            break;

          d++;
        } while (--count != 0);

      *d = 0;
    }

  return destination;
}
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSCAT */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCMP)
int
ACE_OS::wcsncmp_emulation (const ACE_WCHAR_T *s1,
                           const ACE_WCHAR_T *s2,
                           size_t len)
{
  if (len == 0)
    return 0;

  do
    {
      if (*s1 != *s2++)
        return (*s1 - *--s2);
      if (*s1++ == 0)
        break;
    } while (--len != 0);

  return 0;
}
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCMP */

#if !defined (ACE_HAS_WCHAR) || defined (ACE_LACKS_WCSNCPY)
ACE_WCHAR_T *
ACE_OS::wcsncpy_emulation (ACE_WCHAR_T *destination,
                           const ACE_WCHAR_T *source,
                           size_t len)
{
  if (len != 0)
    {
      ACE_WCHAR_T *d = destination;
      const ACE_WCHAR_T *s = source;

      do
        {
          if ((*d++ = *s++) == 0)
            {
              // NUL pad the remaining n-1 bytes
              while (--len != 0)
                *d++ = 0;
              break;
            }
        } while (--len != 0);
    }

  return destination;
}
#endif /* !ACE_HAS_WCHAR || ACE_LACKS_WCSNCPY */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSNICMP)
int
ACE_OS::wcsnicmp_emulation (const wchar_t *s,
                            const wchar_t *t,
                            size_t len)
{
  const wchar_t *scan1 = s;
  const wchar_t *scan2 = t;
  size_t count = 0;

  while (count++ < len
         && *scan1 != 0
         && ACE_OS::ace_towlower (*scan1)
            == ACE_OS::ace_towlower (*scan2))
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
    return ACE_OS::ace_towlower (*scan1) - ACE_OS::ace_towlower (*scan2);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSNICMP */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSPBRK)
wchar_t *
ACE_OS::wcspbrk_emulation (const wchar_t *string,
                           const wchar_t *charset)
{
  const wchar_t *scanp;
  int c, sc;

  while ((c = *string++) != 0)
    {
      for (scanp = charset; (sc = *scanp++) != 0;)
        if (sc == c)
          return const_cast<wchar_t *> (string - 1);
    }

  return 0;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSPBRK */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSRCHR)
const wchar_t *
ACE_OS::wcsrchr_emulation (const wchar_t *s, wint_t c)
{
  const wchar_t *p = s + ACE_OS::strlen (s);

  while (*p != static_cast<wchar_t> (c))
    if (p == s)
      return 0;
    else
      p--;

  return p;
}

wchar_t *
ACE_OS::wcsrchr_emulation (wchar_t *s, wint_t c)
{
  wchar_t *p = s + ACE_OS::strlen (s);

  while (*p != static_cast<wchar_t> (c))
    if (p == s)
      return 0;
    else
      p--;

  return p;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSRCHR */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSSPN)
size_t
ACE_OS::wcsspn_emulation (const wchar_t *string,
                          const wchar_t *charset)
{
  const wchar_t *p = string;
  const wchar_t *spanp;
  wchar_t c, sc;

  // Skip any characters in charset, excluding the terminating \0.
cont:
  c = *p++;
  for (spanp = charset; (sc = *spanp++) != 0;)
    if (sc == c)
      goto cont;
  return (p - 1 - string);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSSPN */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSSTR)
wchar_t *
ACE_OS::wcsstr_emulation (const wchar_t *string,
                          const wchar_t *charset)
{
  wchar_t c, sc;
  size_t len;

  if ((c = *charset++) != 0)
    {
      len = ACE_OS::strlen (charset);
      do
        {
          do
            {
              if ((sc = *string++) == 0)
                return 0;
            } while (sc != c);
        } while (ACE_OS::strncmp (string, charset, len) != 0);
      string--;
    }

  return const_cast<wchar_t *> (string);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSSTR */

ACE_END_VERSIONED_NAMESPACE_DECL

