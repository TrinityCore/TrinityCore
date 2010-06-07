// $Id: OS_NS_stdlib.cpp 85363 2009-05-18 07:48:11Z johnnyw $

#include "ace/OS_NS_stdlib.h"

ACE_RCSID (ace,
           OS_NS_stdlib,
           "$Id: OS_NS_stdlib.cpp 85363 2009-05-18 07:48:11Z johnnyw $")

#include "ace/Default_Constants.h"

#if !defined (ACE_HAS_INLINED_OSCALLS)
# include "ace/OS_NS_stdlib.inl"
#endif /* ACE_HAS_INLINED_OSCALLS */

#include "ace/OS_Memory.h"

#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_ctype.h"

#if defined (ACE_LACKS_MKTEMP) \
    || defined (ACE_LACKS_MKSTEMP) \
    || defined (ACE_LACKS_REALPATH)
#  include "ace/OS_NS_stdio.h"
#  include "ace/OS_NS_sys_stat.h"
#endif /* ACE_LACKS_MKTEMP || ACE_LACKS_MKSTEMP || ACE_LACKS_REALPATH */

#if defined (ACE_LACKS_MKSTEMP)
# include "ace/OS_NS_fcntl.h"
# include "ace/OS_NS_ctype.h"
# include "ace/OS_NS_sys_time.h"
# include "ace/OS_NS_Thread.h"
# include "ace/Numeric_Limits.h"
#endif  /* ACE_LACKS_MKSTEMP */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_EXIT_HOOK ACE_OS::exit_hook_ = 0;

void *
ACE_OS::calloc (size_t elements, size_t sizeof_elements)
{
#if !defined (ACE_HAS_WINCE)
  return ACE_CALLOC_FUNC (elements, sizeof_elements);
#else
  // @@ This will probably not work since it doesn't consider
  // alignment properly.
  return ACE_MALLOC_FUNC (elements * sizeof_elements);
#endif /* ACE_HAS_WINCE */
}

void
ACE_OS::exit (int status)
{
  ACE_OS_TRACE ("ACE_OS::exit");

#if defined (ACE_HAS_NONSTATIC_OBJECT_MANAGER) && !defined (ACE_HAS_WINCE) && !defined (ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER)
  // Shut down the ACE_Object_Manager, if it had registered its exit_hook.
  // With ACE_HAS_NONSTATIC_OBJECT_MANAGER, the ACE_Object_Manager is
  // instantiated on the main's stack.  ::exit () doesn't destroy it.
  if (exit_hook_)
    (*exit_hook_) ();
#endif /* ACE_HAS_NONSTATIC_OBJECT_MANAGER && !ACE_HAS_WINCE && !ACE_DOESNT_INSTANTIATE_NONSTATIC_OBJECT_MANAGER */

#if defined (ACE_WIN32)
  ::ExitProcess ((UINT) status);
#else
  ::exit (status);
#endif /* ACE_WIN32 */
}

void
ACE_OS::free (void *ptr)
{
  ACE_FREE_FUNC (ACE_MALLOC_T (ptr));
}

// You may be asking yourself, why are we doing this?  Well, in winbase.h,
// MS didn't follow their normal Api_FunctionA and Api_FunctionW style,
// so we have to #undef their define to get access to the unicode version.
// And because we don't want to #undef this for the users code, we keep
// this method in the .cpp file.
#if defined (ACE_WIN32) && defined (UNICODE) && !defined (ACE_USES_TCHAR)
#undef GetEnvironmentStrings
#endif /* ACE_WIN32 && UNICODE !ACE_USES_TCHAR */

ACE_TCHAR *
ACE_OS::getenvstrings (void)
{
#if defined (ACE_LACKS_GETENVSTRINGS)
  ACE_NOTSUP_RETURN (0);
#elif defined (ACE_WIN32)
# if defined (ACE_USES_WCHAR)
  return ::GetEnvironmentStringsW ();
# else /* ACE_USES_WCHAR */
  return ::GetEnvironmentStrings ();
# endif /* ACE_USES_WCHAR */
#else /* ACE_WIN32 */
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_WIN32 */
}

// Return a dynamically allocated duplicate of <str>, substituting the
// environment variables of form $VAR_NAME.  Note that the pointer is
// allocated with <ACE_OS::malloc> and must be freed by
// <ACE_OS::free>.

ACE_TCHAR *
ACE_OS::strenvdup (const ACE_TCHAR *str)
{
#if defined (ACE_HAS_WINCE)
  // WinCE doesn't have environment variables so we just skip it.
  return ACE_OS::strdup (str);
#elif defined (ACE_LACKS_STRENVDUP)
  ACE_UNUSED_ARG (str);
  ACE_NOTSUP_RETURN (0);
#else
  const ACE_TCHAR * start = 0;
  if ((start = ACE_OS::strchr (str, ACE_TEXT ('$'))) != 0)
    {
      ACE_TCHAR buf[ACE_DEFAULT_ARGV_BUFSIZ];
      size_t var_len = ACE_OS::strcspn (&start[1],
        ACE_TEXT ("$~!#%^&*()-+=\\|/?,.;:'\"`[]{} \t\n\r"));
      ACE_OS::strncpy (buf, &start[1], var_len);
      buf[var_len++] = ACE_TEXT ('\0');
#  if defined (ACE_WIN32)
      // Always use the ACE_TCHAR for Windows.
      ACE_TCHAR *temp = ACE_OS::getenv (buf);
#  else
      // Use char * for environment on non-Windows.
      char *temp = ACE_OS::getenv (ACE_TEXT_ALWAYS_CHAR (buf));
#  endif /* ACE_WIN32 */
      size_t buf_len = ACE_OS::strlen (str) + 1;
      if (temp != 0)
        buf_len += ACE_OS::strlen (temp) - var_len;
      ACE_TCHAR * buf_p = buf;
      if (buf_len > ACE_DEFAULT_ARGV_BUFSIZ)
        {
          buf_p =
            (ACE_TCHAR *) ACE_OS::malloc (buf_len * sizeof (ACE_TCHAR));
          if (buf_p == 0)
            {
              errno = ENOMEM;
              return 0;
            }
        }
      ACE_TCHAR * p = buf_p;
      size_t len = start - str;
      ACE_OS::strncpy (p, str, len);
      p += len;
      if (temp != 0)
        {
#  if defined (ACE_WIN32)
          p = ACE_OS::strecpy (p, temp) - 1;
#  else
          p = ACE_OS::strecpy (p, ACE_TEXT_CHAR_TO_TCHAR (temp)) - 1;
#  endif /* ACE_WIN32 */
        }
      else
        {
          ACE_OS::strncpy (p, start, var_len);
          p += var_len;
          *p = ACE_TEXT ('\0');
        }
      ACE_OS::strcpy (p, &start[var_len]);
      return (buf_p == buf) ? ACE_OS::strdup (buf) : buf_p;
    }
  else
    return ACE_OS::strdup (str);
#endif /* ACE_HAS_WINCE */
}

#if !defined (ACE_HAS_ITOA)
char *
ACE_OS::itoa_emulation (int value, char *string, int radix)
{
  char *e = string;
  char *b = string;

  // Short circuit if 0

  if (value == 0)
    {
      string[0] = '0';
      string[1] = 0;
      return string;
    }

  // If negative and base 10, print a - and then do the
  // number.

  if (value < 0 && radix == 10)
    {
      string[0] = '-';
      ++b;
      ++e; // Don't overwrite the negative sign.
      value = -value; // Drop negative sign so character selection is correct.
    }

  // Convert to base <radix>, but in reverse order

  while (value != 0)
    {
      int mod = value % radix;
      value = value / radix;

      *e++ = (mod < 10) ? '0' + mod : 'a' + mod - 10;
    }

  *e-- = 0;

  // Now reverse the string to get the correct result

  while (e > b)
    {
      char temp = *e;
      *e = *b;
      *b = temp;
      ++b;
      --e;
    }

  return string;
}
#endif /* !ACE_HAS_ITOA */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_ITOW)
wchar_t *
ACE_OS::itow_emulation (int value, wchar_t *string, int radix)
{
  wchar_t *e = string;
  wchar_t *b = string;

  // Short circuit if 0

  if (value == 0)
    {
      string[0] = '0';
      string[1] = 0;
      return string;
    }

  // If negative and base 10, print a - and then do the
  // number.

  if (value < 0 && radix == 10)
    {
      string[0] = '-';
      b++;
    }

  // Convert to base <radix>, but in reverse order

  while (value != 0)
    {
      int mod = value % radix;
      value = value / radix;

      *e++ = (mod < 10) ? '0' + mod : 'a' + mod - 10;
    }

  *e-- = 0;

  // Now reverse the string to get the correct result

  while (e > b)
  {
    wchar_t temp = *e;
    *e = *b;
    *b = temp;
    ++b;
    --e;
  }

  return string;
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_ITOW */

void *
ACE_OS::malloc (size_t nbytes)
{
  return ACE_MALLOC_FUNC (nbytes);
}

#if defined (ACE_LACKS_MKTEMP)
ACE_TCHAR *
ACE_OS::mktemp (ACE_TCHAR *s)
{
  ACE_OS_TRACE ("ACE_OS::mktemp");
  if (s == 0)
    // check for null template string failed!
    return 0;
  else
    {
      ACE_TCHAR *xxxxxx = ACE_OS::strstr (s, ACE_TEXT ("XXXXXX"));

      if (xxxxxx == 0)
        // the template string doesn't contain "XXXXXX"!
        return s;
      else
        {
          ACE_TCHAR unique_letter = ACE_TEXT ('a');
          ACE_stat sb;

          // Find an unused filename for this process.  It is assumed
          // that the user will open the file immediately after
          // getting this filename back (so, yes, there is a race
          // condition if multiple threads in a process use the same
          // template).  This appears to match the behavior of the
          // SunOS 5.5 mktemp().
          ACE_OS::sprintf (xxxxxx,
                           ACE_TEXT ("%05d%c"),
                           ACE_OS::getpid (),
                           unique_letter);
          while (ACE_OS::stat (s, &sb) >= 0)
            {
              if (++unique_letter <= ACE_TEXT ('z'))
                ACE_OS::sprintf (xxxxxx,
                                 ACE_TEXT ("%05d%c"),
                                 ACE_OS::getpid (),
                                 unique_letter);
              else
                {
                  // maximum of 26 unique files per template, per process
                  ACE_OS::sprintf (xxxxxx, ACE_TEXT ("%s"), ACE_TEXT (""));
                  return s;
                }
            }
        }
      return s;
    }
}
#endif /* ACE_LACKS_MKTEMP */

void *
ACE_OS::realloc (void *ptr, size_t nbytes)
{
  return ACE_REALLOC_FUNC (ACE_MALLOC_T (ptr), nbytes);
}

#if defined (ACE_LACKS_REALPATH)
char *
ACE_OS::realpath (const char *file_name,
                  char *resolved_name)
{
  ACE_OS_TRACE ("ACE_OS::realpath");

  if (file_name == 0)
    {
      // Single Unix Specification V3:
      //   Return an error if parameter is a null pointer.
      errno = EINVAL;
      return 0;
    }

  if (*file_name == '\0')
    {
      // Single Unix Specification V3:
      //   Return an error if the file_name argument points
      //   to an empty string.
      errno = ENOENT;
      return 0;
    }

  char* rpath;

  if (resolved_name == 0)
    {
      // Single Unix Specification V3:
      //   Return an error if parameter is a null pointer.
      //
      // To match glibc realpath() and Win32 _fullpath() behavior,
      // allocate room for the return value if resolved_name is
      // a null pointer.
      rpath = static_cast<char*>(ACE_OS::malloc (PATH_MAX));
      if (rpath == 0)
        {
          errno = ENOMEM;
          return 0;
        }
    }
  else
    {
      rpath = resolved_name;
    }

  char* dest;

  if (*file_name != '/')
    {
      // file_name is relative path so CWD needs to be added
      if (ACE_OS::getcwd (rpath, PATH_MAX) == 0)
        {
          if (resolved_name == 0)
            ACE_OS::free (rpath);
          return 0;
        }
      dest = ACE_OS::strchr (rpath, '\0');
    }
  else
    {
      dest = rpath;
    }

#if !defined (ACE_LACKS_SYMLINKS)
  char expand_buf[PATH_MAX]; // Extra buffer needed to expand symbolic links
  int nlinks = 0;
#endif

  while (*file_name)
    {
      *dest++ = '/';

      // Skip multiple separators
      while (*file_name == '/')
        ++file_name;

      char* start = dest;

      // Process one path component
      while (*file_name && *file_name != '/')
        {
          *dest++ = *file_name++;
          if (dest - rpath > PATH_MAX)
            {
              errno = ENAMETOOLONG;
              if (resolved_name == 0)
                ACE_OS::free (rpath);
              return 0;
            }
        }

      if (start == dest) // Are we done?
        {
          if (dest - rpath > 1)
            --dest; // Remove trailing separator if not at root
          break;
        }
      else if (dest - start == 1 && *start == '.')
        {
          dest -= 2; // Remove "./"
        }
      else if (dest - start == 2 && *start == '.' && *(start +1) == '.')
        {
          dest -= 3; // Remove "../"
          if (dest > rpath) // Remove the last path component if not at root
            while (*--dest != '/')
              ;
        }
#  if !defined (ACE_LACKS_SYMLINKS)
      else
        {
          ACE_stat st;

          *dest = '\0';
          if (ACE_OS::lstat(rpath, &st) < 0)
            {
              if (resolved_name == 0)
              ACE_OS::free (rpath);
                return 0;
            }

          // Check if current path is a link
          if (S_ISLNK (st.st_mode))
            {
              if (++nlinks > MAXSYMLINKS)
                {
                  errno = ELOOP;
                  if (resolved_name == 0)
                    ACE_OS::free (rpath);
                  return 0;
                }

              char link_buf[PATH_MAX];

              ssize_t link_len = ACE_OS::readlink (rpath, link_buf, PATH_MAX);
              int tail_len = ACE_OS::strlen (file_name) + 1;

              // Check if there is room to expand link?
              if (link_len + tail_len > PATH_MAX)
                {
                  errno = ENAMETOOLONG;
                  if (resolved_name == 0)
                    ACE_OS::free (rpath);
                  return 0;
                }

              // Move tail and prefix it with expanded link
              ACE_OS::memmove (expand_buf + link_len, file_name, tail_len);
              ACE_OS::memcpy (expand_buf, link_buf, link_len);

              if (*link_buf == '/') // Absolute link?
                {
                  dest = rpath;
                }
              else // Relative link, remove expanded link component
                {
                  --dest;
                  while (*--dest != '/')
                    ;
                }
              file_name = expand_buf; // Source path is now in expand_buf
            }
        }
#  endif /* ACE_LACKS_SYMLINKS */
    }

  *dest = '\0';

  return rpath;
}
#endif /* ACE_LACKS_REALPATH */

#if defined (ACE_LACKS_STRTOL)
long
ACE_OS::strtol_emulation (const char *nptr, char **endptr, int base)
{
  register const char *s = nptr;
  register unsigned long acc;
  register int c;
  register unsigned long cutoff;
  register int neg = 0, any, cutlim;

  /*
   * Skip white space and pick up leading +/- sign if any.
   * If base is 0, allow 0x for hex and 0 for octal, else
   * assume decimal; if base is already 16, allow 0x.
   */
  do {
    c = *s++;
  } while (ACE_OS::ace_isspace(c));
  if (c == '-') {
    neg = 1;
    c = *s++;
  } else if (c == '+')
    c = *s++;
  if ((base == 0 || base == 16) &&
    c == '0' && (*s == 'x' || *s == 'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0)
    base = c == '0' ? 8 : 10;

  /*
   * Compute the cutoff value between legal numbers and illegal
   * numbers.  That is the largest legal value, divided by the
   * base.  An input number that is greater than this value, if
   * followed by a legal input character, is too big.  One that
   * is equal to this value may be valid or not; the limit
   * between valid and invalid numbers is then based on the last
   * digit.  For instance, if the range for longs is
   * [-2147483648..2147483647] and the input base is 10,
   * cutoff will be set to 214748364 and cutlim to either
   * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
   * a value > 214748364, or equal but the next digit is > 7 (or 8),
   * the number is too big, and we will return a range error.
   *
   * Set any if any `digits' consumed; make it negative to indicate
   * overflow.
   */
  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (ACE_OS::ace_isdigit(c))
      c -= '0';
    else if (ACE_OS::ace_isalpha(c))
      c -= ACE_OS::ace_isupper(c) ? 'A' - 10 : 'a' - 10;
    else
      break;
    if (c >= base)
      break;
    if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
    errno = ERANGE;
  } else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (char *)s - 1 : (char *)nptr;
  return (acc);
}
#endif /* ACE_LACKS_STRTOL */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSTOL)
long
ACE_OS::wcstol_emulation (const wchar_t *nptr,
        wchar_t **endptr,
        int base)
{
  register const wchar_t *s = nptr;
  register unsigned long acc;
  register int c;
  register unsigned long cutoff;
  register int neg = 0, any, cutlim;

  /*
   * Skip white space and pick up leading +/- sign if any.
   * If base is 0, allow 0x for hex and 0 for octal, else
   * assume decimal; if base is already 16, allow 0x.
   */
  do {
    c = *s++;
  } while (ACE_OS::ace_isspace(c));
  if (c == L'-') {
    neg = 1;
    c = *s++;
  } else if (c == L'+')
    c = *s++;
  if ((base == 0 || base == 16) &&
    c == '0' && (*s == L'x' || *s == L'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0)
    base = c == L'0' ? 8 : 10;

  /*
   * See strtol for comments as to the logic used.
   */
  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (ACE_OS::ace_isdigit(c))
      c -= L'0';
    else if (ACE_OS::ace_isalpha(c))
      c -= ACE_OS::ace_isupper(c) ? L'A' - 10 : L'a' - 10;
    else
      break;
    if (c >= base)
      break;
    if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
    errno = ERANGE;
  } else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (wchar_t *)s - 1 : (wchar_t *)nptr;
  return (acc);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSTOL */

#if defined (ACE_LACKS_STRTOUL)
unsigned long
ACE_OS::strtoul_emulation (const char *nptr,
                           char **endptr,
                           register int base)
{
  register const char *s = nptr;
  register unsigned long acc;
  register int c;
  register unsigned long cutoff;
  register int neg = 0, any, cutlim;

  /*
   * See strtol for comments as to the logic used.
   */
  do
    c = *s++;
  while (ACE_OS::ace_isspace(c));
  if (c == '-')
    {
      neg = 1;
      c = *s++;
    }
  else if (c == '+')
    c = *s++;
  if ((base == 0 || base == 16) &&
      c == '0' && (*s == 'x' || *s == 'X'))
    {
      c = s[1];
      s += 2;
      base = 16;
    }
  if (base == 0)
    base = c == '0' ? 8 : 10;
  cutoff = (unsigned long) ULONG_MAX / (unsigned long) base;
  cutlim = (unsigned long) ULONG_MAX % (unsigned long) base;

  for (acc = 0, any = 0;; c = *s++)
    {
      if (ACE_OS::ace_isdigit(c))
        c -= '0';
      else if (ACE_OS::ace_isalpha(c))
        c -= ACE_OS::ace_isupper(c) ? 'A' - 10 : 'a' - 10;
      else
        break;
      if (c >= base)
        break;
      if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
        any = -1;
      else
        {
          any = 1;
          acc *= base;
          acc += c;
        }
    }
  if (any < 0)
    {
      acc = ULONG_MAX;
      errno = ERANGE;
    }
  else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (char *) s - 1 : (char *) nptr;
  return (acc);
}
#endif /* ACE_LACKS_STRTOUL */


#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSTOUL)
unsigned long
ACE_OS::wcstoul_emulation (const wchar_t *nptr,
         wchar_t **endptr,
         int base)
{
  register const wchar_t *s = nptr;
  register unsigned long acc;
  register int c;
  register unsigned long cutoff;
  register int neg = 0, any, cutlim;

  /*
   * See strtol for comments as to the logic used.
   */
  do
    c = *s++;
  while (ACE_OS::ace_isspace(c));
  if (c == L'-')
    {
      neg = 1;
      c = *s++;
    }
  else if (c == L'+')
    c = *s++;
  if ((base == 0 || base == 16) &&
      c == L'0' && (*s == L'x' || *s == L'X'))
    {
      c = s[1];
      s += 2;
      base = 16;
    }
  if (base == 0)
    base = c == L'0' ? 8 : 10;
  cutoff = (unsigned long) ULONG_MAX / (unsigned long) base;
  cutlim = (unsigned long) ULONG_MAX % (unsigned long) base;

  for (acc = 0, any = 0;; c = *s++)
    {
      if (ACE_OS::ace_isdigit(c))
        c -= L'0';
      else if (ACE_OS::ace_isalpha(c))
        c -= ACE_OS::ace_isupper(c) ? L'A' - 10 : L'a' - 10;
      else
        break;
      if (c >= base)
        break;
      if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
        any = -1;
      else
        {
          any = 1;
          acc *= base;
          acc += c;
        }
    }
  if (any < 0)
    {
      acc = ULONG_MAX;
      errno = ERANGE;
    }
  else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (wchar_t *) s - 1 : (wchar_t *) nptr;
  return (acc);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSTOUL */

#if defined (ACE_LACKS_STRTOLL)
ACE_INT64
ACE_OS::strtoll_emulation (const char *nptr,
         char **endptr,
         register int base)
{
  register const char *s = nptr;
  register ACE_UINT64 acc;
  register int c;
  register ACE_UINT64 cutoff;
  register int neg = 0, any, cutlim;

  /*
   * Skip white space and pick up leading +/- sign if any.
   * If base is 0, allow 0x for hex and 0 for octal, else
   * assume decimal; if base is already 16, allow 0x.
   */
  do {
    c = *s++;
  } while (ACE_OS::ace_isspace(c));
  if (c == '-') {
    neg = 1;
    c = *s++;
  } else if (c == '+')
    c = *s++;
  if ((base == 0 || base == 16) &&
    c == '0' && (*s == 'x' || *s == 'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0)
    base = c == '0' ? 8 : 10;

  /*
   * See strtol for comments as to the logic used.
   */
  cutoff = neg ? -(ACE_UINT64)ACE_INT64_MIN : ACE_INT64_MAX;
  cutlim = cutoff % (ACE_UINT64)base;
  cutoff /= (ACE_UINT64)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (ACE_OS::ace_isdigit(c))
      c -= '0';
    else if (ACE_OS::ace_isalpha(c))
      c -= ACE_OS::ace_isupper(c) ? 'A' - 10 : 'a' - 10;
    else
      break;
    if (c >= base)
      break;
    if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? ACE_INT64_MIN : ACE_INT64_MAX;
    errno = ERANGE;
  } else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (char *)s - 1 : (char *)nptr;
  return (acc);
}
#endif /* ACE_LACKS_STRTOLL */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSTOLL)
ACE_INT64
ACE_OS::wcstoll_emulation (const wchar_t *nptr,
         wchar_t **endptr,
         int base)
{
  register const wchar_t *s = nptr;
  register ACE_UINT64 acc;
  register int c;
  register ACE_UINT64 cutoff;
  register int neg = 0, any, cutlim;

  /*
   * Skip white space and pick up leading +/- sign if any.
   * If base is 0, allow 0x for hex and 0 for octal, else
   * assume decimal; if base is already 16, allow 0x.
   */
  do {
    c = *s++;
  } while (ACE_OS::ace_isspace(c));
  if (c == L'-') {
    neg = 1;
    c = *s++;
  } else if (c == L'+')
    c = *s++;
  if ((base == 0 || base == 16) &&
    c == L'0' && (*s == L'x' || *s == L'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  if (base == 0)
    base = c == L'0' ? 8 : 10;

  /*
   * See strtol for comments as to the logic used.
   */
  cutoff = neg ? -(ACE_UINT64)ACE_INT64_MIN : ACE_INT64_MAX;
  cutlim = cutoff % (ACE_UINT64)base;
  cutoff /= (ACE_UINT64)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (ACE_OS::ace_isdigit(c))
      c -= L'0';
    else if (ACE_OS::ace_isalpha(c))
      c -= ACE_OS::ace_isupper(c) ? L'A' - 10 : L'a' - 10;
    else
      break;
    if (c >= base)
      break;
    if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? ACE_INT64_MIN : ACE_INT64_MAX;
    errno = ERANGE;
  } else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (wchar_t *)s - 1 : (wchar_t *)nptr;
  return (acc);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSTOLL */


#if defined (ACE_LACKS_STRTOULL)
ACE_UINT64
ACE_OS::strtoull_emulation (const char *nptr,
                            char **endptr,
                            register int base)
{
  register const char *s = nptr;
  register ACE_UINT64 acc;
  register int c;
  register ACE_UINT64 cutoff;
  register int neg = 0, any, cutlim;

  /*
   * See strtol for comments as to the logic used.
   */
  do
    c = *s++;
  while (ACE_OS::ace_isspace(c));
  if (c == '-')
    {
      neg = 1;
      c = *s++;
    }
  else if (c == '+')
    c = *s++;
  if ((base == 0 || base == 16) &&
      c == '0' && (*s == 'x' || *s == 'X'))
    {
      c = s[1];
      s += 2;
      base = 16;
    }
  if (base == 0)
    base = c == '0' ? 8 : 10;

  cutoff = (ACE_UINT64) ACE_UINT64_MAX / (ACE_UINT64) base;
  cutlim = (ACE_UINT64) ACE_UINT64_MAX % (ACE_UINT64) base;

  for (acc = 0, any = 0;; c = *s++)
    {
      if (ACE_OS::ace_isdigit(c))
        c -= '0';
      else if (ACE_OS::ace_isalpha(c))
        c -= ACE_OS::ace_isupper(c) ? 'A' - 10 : 'a' - 10;
      else
        break;
      if (c >= base)
        break;
      if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
        any = -1;
      else
        {
          any = 1;
          acc *= base;
          acc += c;
        }
    }
  if (any < 0)
    {
      acc = ACE_UINT64_MAX;
      errno = ERANGE;
    }
  else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (char *) s - 1 : (char *) nptr;
  return (acc);
}
#endif /* ACE_LACKS_STRTOULL */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_WCSTOULL)
ACE_UINT64
ACE_OS::wcstoull_emulation (const wchar_t *nptr,
          wchar_t **endptr,
          int base)
{
  register const wchar_t *s = nptr;
  register ACE_UINT64 acc;
  register int c;
  register ACE_UINT64 cutoff;
  register int neg = 0, any, cutlim;

  /*
   * See strtol for comments as to the logic used.
   */
  do
    c = *s++;
  while (ACE_OS::ace_isspace(c));
  if (c == L'-')
    {
      neg = 1;
      c = *s++;
    }
  else if (c == L'+')
    c = *s++;
  if ((base == 0 || base == 16) &&
      c == L'0' && (*s == L'x' || *s == L'X'))
    {
      c = s[1];
      s += 2;
      base = 16;
    }
  if (base == 0)
    base = c == L'0' ? 8 : 10;

  cutoff = (ACE_UINT64) ACE_UINT64_MAX / (ACE_UINT64) base;
  cutlim = (ACE_UINT64) ACE_UINT64_MAX % (ACE_UINT64) base;

  for (acc = 0, any = 0;; c = *s++)
    {
      if (ACE_OS::ace_isdigit(c))
        c -= L'0';
      else if (ACE_OS::ace_isalpha(c))
        c -= ACE_OS::ace_isupper(c) ? L'A' - 10 : L'a' - 10;
      else
        break;
      if (c >= base)
        break;
      if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
        any = -1;
      else
        {
          any = 1;
          acc *= base;
          acc += c;
        }
    }
  if (any < 0)
    {
      acc = ACE_UINT64_MAX;
      errno = ERANGE;
    }
  else if (neg)
    acc = -acc;
  if (endptr != 0)
    *endptr = any ? (wchar_t *) s - 1 : (wchar_t *) nptr;
  return (acc);
}
#endif /* ACE_HAS_WCHAR && ACE_LACKS_WCSTOULL */

#if defined (ACE_LACKS_MKSTEMP)
ACE_HANDLE
ACE_OS::mkstemp_emulation (ACE_TCHAR * s)
{
  if (s == 0)
    {
      errno = EINVAL;
      return ACE_INVALID_HANDLE;
    }

  // The "XXXXXX" template to be filled in.
  ACE_TCHAR * const t  = ACE_OS::strstr (s, ACE_TEXT ("XXXXXX"));

  if (t == 0)
    {
      errno = EINVAL;
      return ACE_INVALID_HANDLE;
    }

  static unsigned int const NUM_RETRIES = 50;
  static unsigned int const NUM_CHARS   = 6;  // Do not change!

  // Use ACE_Time_Value::msec(ACE_UINT64&) as opposed to
  // ACE_Time_Value::msec(void) to avoid truncation.
  ACE_UINT64 msec;

  // Use a const ACE_Time_Value to resolve ambiguity between
  // ACE_Time_Value::msec (long) and ACE_Time_Value::msec(ACE_UINT64&) const.
  ACE_Time_Value const now = ACE_OS::gettimeofday();
  now.msec (msec);

  // Add the process and thread ids to ensure uniqueness.
  msec += ACE_OS::getpid();
  msec += (size_t) ACE_OS::thr_self();

  // ACE_thread_t may be a char* (returned by ACE_OS::thr_self()) so
  // we need to use a C-style cast as a catch-all in order to use a
  // static_cast<> to an integral type.
  ACE_RANDR_TYPE seed = static_cast<ACE_RANDR_TYPE> (msec);

  // We only care about UTF-8 / ASCII characters in generated
  // filenames.  A UTF-16 or UTF-32 character could potentially cause
  // a very large space to be searched in the below do/while() loop,
  // greatly slowing down this mkstemp() implementation.  It is more
  // practical to limit the search space to UTF-8 / ASCII characters
  // (i.e. 127 characters).
  //
  // Note that we can't make this constant static since the compiler
  // may not inline the return value of ACE_Numeric_Limits::max(),
  // meaning multiple threads could potentially initialize this value
  // in parallel.
  float const MAX_VAL =
    static_cast<float> (ACE_Numeric_Limits<char>::max ());

  // Use high-order bits rather than low-order ones (e.g. rand() %
  // MAX_VAL).  See Numerical Recipes in C: The Art of Scientific
  // Computing (William  H. Press, Brian P. Flannery, Saul
  // A. Teukolsky, William T. Vetterling; New York: Cambridge
  // University Press, 1992 (2nd ed., p. 277).
  //
  // e.g.: MAX_VAL * rand() / (RAND_MAX + 1.0)

  // Factor out the constant coefficient.
  float const coefficient =
    static_cast<float> (MAX_VAL / (RAND_MAX + 1.0f));

  // @@ These nested loops may be ineffecient.  Improvements are
  //    welcome.
  for (unsigned int i = 0; i < NUM_RETRIES; ++i)
    {
      for (unsigned int n = 0; n < NUM_CHARS; ++n)
        {
          ACE_TCHAR r;

          // This do/while() loop allows this alphanumeric character
          // selection to work for EBCDIC, as well.
          do
            {
              r = static_cast<ACE_TCHAR> (coefficient * ACE_OS::rand_r (seed));
            }
          while (!ACE_OS::ace_isalnum (r));

          t[n] = r;
        }

      static int const perms =
#if defined (ACE_WIN32)
        0;      /* Do not share while open. */
#else
        0600;   /* S_IRUSR | S_IWUSR */
#endif  /* ACE_WIN32 */

      // Create the file with the O_EXCL bit set to ensure that we're
      // not subject to a symbolic link attack.
      //
      // Note that O_EXCL is subject to a race condition over NFS
      // filesystems.
      ACE_HANDLE const handle = ACE_OS::open (s,
                                              O_RDWR | O_CREAT | O_EXCL,
                                              perms);

      if (handle != ACE_INVALID_HANDLE)
        return handle;
    }

  errno = EEXIST;  // Couldn't create a unique temporary file.
  return ACE_INVALID_HANDLE;
}
#endif /* ACE_LACKS_MKSTEMP */

#if !defined (ACE_HAS_GETPROGNAME) && !defined (ACE_HAS_SETPROGNAME)
static const char *__progname = "";
#endif /* !ACE_HAS_GETPROGNAME && !ACE_HAS_SETPROGNAME */

#if !defined (ACE_HAS_GETPROGNAME)
const char*
ACE_OS::getprogname_emulation ()
{
    return __progname;
}
#endif /* !ACE_HAS_GETPROGNAME */

#if !defined (ACE_HAS_SETPROGNAME)
void
ACE_OS::setprogname_emulation (const char* progname)
{
  const char *p = ACE_OS::strrchr (progname, '/');
  if (p != 0)
    __progname = p + 1;
  else
    __progname = progname;
}
#endif /* !ACE_HAS_SETPROGNAME */

ACE_END_VERSIONED_NAMESPACE_DECL
