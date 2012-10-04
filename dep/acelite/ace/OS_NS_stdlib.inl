// -*- C++ -*-
//
// $Id: OS_NS_stdlib.inl 95761 2012-05-15 18:23:04Z johnnyw $

#include "ace/config-all.h"           /* Need ACE_TRACE */
#include "ace/Object_Manager_Base.h"
#include "ace/OS_NS_string.h"
#include "ace/Global_Macros.h"
#include "ace/os_include/os_errno.h"
#include "ace/os_include/os_search.h"

#if defined (ACE_WCHAR_IN_STD_NAMESPACE)
# define ACE_WCHAR_STD_NAMESPACE std
#else
# define ACE_WCHAR_STD_NAMESPACE ACE_STD_NAMESPACE
#endif /* ACE_WCHAR_IN_STD_NAMESPACE */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

// Doesn't need a macro since it *never* returns!

ACE_INLINE void
ACE_OS::_exit (int status)
{
  ACE_OS_TRACE ("ACE_OS::_exit");
#if defined (ACE_VXWORKS)
  ::exit (status);
#elif !defined (ACE_HAS_WINCE)
  ::_exit (status);
#else
  ::TerminateProcess (::GetCurrentProcess (), status);
#endif /* ACE_VXWORKS */
}

ACE_INLINE void
ACE_OS::abort (void)
{
#if !defined (ACE_LACKS_ABORT)
  ::abort ();
#else
  exit (1);
#endif /* !ACE_LACKS_ABORT */
}

ACE_INLINE int
ACE_OS::atexit (ACE_EXIT_HOOK func, const char* name)
{
  return ACE_OS_Object_Manager::instance ()->at_exit (func, name);
}

ACE_INLINE int
ACE_OS::atoi (const char *s)
{
  ACE_OSCALL_RETURN (::atoi (s), int, -1);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE int
ACE_OS::atoi (const wchar_t *s)
{
#if defined (ACE_WIN32) && defined (ACE_HAS_WTOI)
  ACE_OSCALL_RETURN (::_wtoi (s), int, -1);
#else /* ACE_WIN32 */
  return ACE_OS::atoi (ACE_Wide_To_Ascii (s).char_rep ());
#endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE long
ACE_OS::atol (const char *s)
{
  ACE_OSCALL_RETURN (::atol (s), long, -1);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE long
ACE_OS::atol (const wchar_t *s)
{
#if defined (ACE_WIN32) && defined (ACE_HAS_WTOL)
  ACE_OSCALL_RETURN (::_wtol (s), long, -1);
#else /* ACE_WIN32 */
  return ACE_OS::atol (ACE_Wide_To_Ascii (s).char_rep ());
#endif /* ACE_WIN32 */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE double
ACE_OS::atof (const char *s)
{
  ACE_OSCALL_RETURN (::atof (s), double, -1);
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE double
ACE_OS::atof (const wchar_t *s)
{
#if !defined (ACE_HAS_WTOF)
  return ACE_OS::atof (ACE_Wide_To_Ascii (s).char_rep ());
#elif defined (ACE_WTOF_EQUIVALENT)
  ACE_OSCALL_RETURN (ACE_WTOF_EQUIVALENT (s), double, -1);
#else /* ACE_HAS__WTOF */
  ACE_OSCALL_RETURN (::wtof (s), double, -1);
#endif /* ACE_HAS_WTOF */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE void *
ACE_OS::atop (const char *s)
{
  ACE_TRACE ("ACE_OS::atop");
#if defined (ACE_WIN64)
  intptr_t ip = ::_atoi64 (s);
#elif defined (ACE_OPENVMS)
#  if !defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64)
  int ip = ::atoi (s);
#  else
  intptr_t ip = ::atoi (s);
#  endif
#else
  intptr_t ip = ::atoi (s);
#endif /* ACE_WIN64 */
  void * p = reinterpret_cast<void *> (ip);
  return p;
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE void *
ACE_OS::atop (const wchar_t *s)
{
#  if defined (ACE_WIN64)
  intptr_t ip = ::_wtoi64 (s);
#  elif defined (ACE_OPENVMS)
#    if !defined (__INITIAL_POINTER_SIZE) || (__INITIAL_POINTER_SIZE < 64)
  int ip = ACE_OS::atoi (s);
#    else
  intptr_t ip = ACE_OS::atoi (s);
#    endif
#  else
  intptr_t ip = ACE_OS::atoi (s);
#  endif /* ACE_WIN64 */
  void * p = reinterpret_cast<void *> (ip);
  return p;
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE void *
ACE_OS::bsearch (const void *key,
                 const void *base,
                 size_t nel,
                 size_t size,
                 ACE_COMPARE_FUNC compar)
{
#if !defined (ACE_LACKS_BSEARCH)
  return ::bsearch (key, base, nel, size, compar);
#else
  ACE_UNUSED_ARG (key);
  ACE_UNUSED_ARG (base);
  ACE_UNUSED_ARG (nel);
  ACE_UNUSED_ARG (size);
  ACE_UNUSED_ARG (compar);
  ACE_NOTSUP_RETURN (0);
#endif /* ACE_LACKS_BSEARCH */
}

ACE_INLINE char *
ACE_OS::getenv (const char *symbol)
{
  ACE_OS_TRACE ("ACE_OS::getenv");
#if defined (ACE_LACKS_GETENV)
  ACE_UNUSED_ARG (symbol);
  ACE_NOTSUP_RETURN (0);
#else /* ACE_LACKS_GETENV */
  ACE_OSCALL_RETURN (::getenv (symbol), char *, 0);
#endif /* ACE_LACKS_GETENV */
}

#if defined (ACE_HAS_WCHAR) && defined (ACE_WIN32)
ACE_INLINE wchar_t *
ACE_OS::getenv (const wchar_t *symbol)
{
#if defined (ACE_LACKS_GETENV)
  ACE_UNUSED_ARG (symbol);
  ACE_NOTSUP_RETURN (0);
#else
  ACE_OSCALL_RETURN (::_wgetenv (symbol), wchar_t *, 0);
#endif /* ACE_LACKS_GETENV */
}
#endif /* ACE_HAS_WCHAR && ACE_WIN32 */

ACE_INLINE char *
ACE_OS::itoa (int value, char *string, int radix)
{
#if !defined (ACE_HAS_ITOA)
  return ACE_OS::itoa_emulation (value, string, radix);
#elif defined (ACE_ITOA_EQUIVALENT)
  return ACE_ITOA_EQUIVALENT (value, string, radix);
#else /* !ACE_HAS_ITOA */
  return ::itoa (value, string, radix);
#endif /* !ACE_HAS_ITOA */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::itoa (int value, wchar_t *string, int radix)
{
#if defined (ACE_LACKS_ITOW)
  return ACE_OS::itow_emulation (value, string, radix);
#else /* ACE_LACKS_ITOW */
  return ::_itow (value, string, radix);
#endif /* ACE_LACKS_ITOW */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE ACE_HANDLE
ACE_OS::mkstemp (char *s)
{
#if !defined (ACE_LACKS_MKSTEMP)
  return ::mkstemp (s);
#elif defined (ACE_USES_WCHAR)
  // For wide-char filesystems, we must convert the narrow-char input to
  // a wide-char string for mkstemp_emulation(), then convert the name
  // back to narrow-char for the caller.
  ACE_Ascii_To_Wide wide_s (s);
  const ACE_HANDLE fh = ACE_OS::mkstemp_emulation (wide_s.wchar_rep ());
  if (fh != ACE_INVALID_HANDLE)
    {
      ACE_Wide_To_Ascii narrow_s (wide_s.wchar_rep ());
      ACE_OS::strcpy (s, narrow_s.char_rep ());
    }
  return fh;
#else
  return ACE_OS::mkstemp_emulation (s);
#endif  /* !ACE_LACKS_MKSTEMP */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE ACE_HANDLE
ACE_OS::mkstemp (wchar_t *s)
{
#  if !defined (ACE_LACKS_MKSTEMP)
  // For wide-char filesystems, we must convert the wide-char input to
  // a narrow-char string for mkstemp(), then convert the name
  // back to wide-char for the caller.
  ACE_Wide_To_Ascii narrow_s (s);
  const ACE_HANDLE fh = ::mkstemp (narrow_s.char_rep ());
  if (fh != ACE_INVALID_HANDLE)
    {
      ACE_Ascii_To_Wide wide_s (narrow_s.char_rep ());
      ACE_OS::strcpy (s, wide_s.wchar_rep ());
    }
  return fh;
#  elif defined (ACE_USES_WCHAR)
  return ACE_OS::mkstemp_emulation (s);
#  else
  // For wide-char filesystems, we must convert the wide-char input to
  // a narrow-char string for mkstemp_emulation(), then convert the name
  // back to wide-char for the caller.
  ACE_Wide_To_Ascii narrow_s (s);
  const ACE_HANDLE fh = ACE_OS::mkstemp_emulation (narrow_s.char_rep ());
  if (fh != ACE_INVALID_HANDLE)
    {
      ACE_Ascii_To_Wide wide_s (narrow_s.char_rep ());
      ACE_OS::strcpy (s, wide_s.wchar_rep ());
    }
  return fh;
#  endif  /* !ACE_LACKS_MKSTEMP */
}
#endif /* ACE_HAS_WCHAR */

#if !defined (ACE_LACKS_MKTEMP)
ACE_INLINE char *
ACE_OS::mktemp (char *s)
{
# if defined (ACE_WIN32)
  return ::_mktemp (s);
# else /* ACE_WIN32 */
  return ::mktemp (s);
# endif /* ACE_WIN32 */
}

#  if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::mktemp (wchar_t *s)
{
#    if defined (ACE_WIN32)
  return ::_wmktemp (s);
#    else
  // For narrow-char filesystems, we must convert the wide-char input to
  // a narrow-char string for mktemp (), then convert the name back to
  // wide-char for the caller.
  ACE_Wide_To_Ascii narrow_s (s);
  if (::mktemp (narrow_s.char_rep ()) == 0)
    return 0;
  ACE_Ascii_To_Wide wide_s (narrow_s.char_rep ());
  ACE_OS::strcpy (s, wide_s.wchar_rep ());
  return s;
#    endif
}
#  endif /* ACE_HAS_WCHAR */

#endif /* !ACE_LACKS_MKTEMP */

ACE_INLINE int
ACE_OS::putenv (const char *string)
{
  ACE_OS_TRACE ("ACE_OS::putenv");
#if defined (ACE_LACKS_PUTENV) && defined (ACE_HAS_SETENV)
  int result = 0;
  char *sp = ACE_OS::strchr (const_cast <char *> (string), '=');
  if (sp)
    {
      char *stmp = ACE_OS::strdup (string);
      if (stmp)
        {
          stmp[sp - string] = '\0';
          result = ACE_OS::setenv (stmp, sp+sizeof (char), 1);
          ACE_OS::free (stmp);
        }
      else
        {
          errno = ENOMEM;
          result = -1;
        }
    }
  else
    {
      result = ACE_OS::setenv (string, "", 1);
    }

  return result;
#elif defined (ACE_LACKS_PUTENV)
  ACE_UNUSED_ARG (string);
  ACE_NOTSUP_RETURN (0);
#else /* ! ACE_HAS_WINCE */
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::putenv (const_cast <char *> (string)), int, -1);
#endif /* ACE_LACKS_PUTENV && ACE_HAS_SETENV */
}

ACE_INLINE int
ACE_OS::setenv(const char *envname, const char *envval, int overwrite)
{
#if defined (ACE_LACKS_SETENV)
  ACE_UNUSED_ARG (envname);
  ACE_UNUSED_ARG (envval);
  ACE_UNUSED_ARG (overwrite);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::setenv (envname, envval, overwrite), int, -1);
#endif
}

ACE_INLINE int
ACE_OS::unsetenv(const char *name)
{
#if defined (ACE_LACKS_UNSETENV)
  ACE_UNUSED_ARG (name);
  ACE_NOTSUP_RETURN (-1);
#else
# if defined (ACE_HAS_VOID_UNSETENV)
  ::unsetenv (name);
  return 0;
#else
  ACE_OSCALL_RETURN (ACE_STD_NAMESPACE::unsetenv (name), int, -1);
# endif /* ACE_HAS_VOID_UNSETENV */
#endif /* ACE_LACKS_UNSETENV */
}

#if defined (ACE_HAS_WCHAR) && defined (ACE_WIN32)
ACE_INLINE int
ACE_OS::putenv (const wchar_t *string)
{
  ACE_OS_TRACE ("ACE_OS::putenv");
#if defined (ACE_LACKS_PUTENV)
  ACE_UNUSED_ARG (string);
  ACE_NOTSUP_RETURN (-1);
#else
  ACE_OSCALL_RETURN (::_wputenv (string), int, -1);
#endif /* ACE_LACKS_PUTENV */
}
#endif /* ACE_HAS_WCHAR && ACE_WIN32 */

ACE_INLINE void
ACE_OS::qsort (void *base,
               size_t nel,
               size_t width,
               ACE_COMPARE_FUNC compar)
{
#if !defined (ACE_LACKS_QSORT)
  ::qsort (base, nel, width, compar);
#else
  ACE_UNUSED_ARG (base);
  ACE_UNUSED_ARG (nel);
  ACE_UNUSED_ARG (width);
  ACE_UNUSED_ARG (compar);
#endif /* !ACE_LACKS_QSORT */
}

ACE_INLINE int
ACE_OS::rand (void)
{
  ACE_OS_TRACE ("ACE_OS::rand");
  ACE_OSCALL_RETURN (::rand (), int, -1);
}

ACE_INLINE int
ACE_OS::rand_r (unsigned int *seed)
{
  ACE_OS_TRACE ("ACE_OS::rand_r");
#if defined (ACE_LACKS_RAND_R)
  long new_seed = (long) *seed;
  if (new_seed == 0)
    new_seed = 0x12345987;
  long temp = new_seed / 127773;
  new_seed = 16807 * (new_seed - temp * 127773) - 2836 * temp;
  if (new_seed < 0)
    new_seed += 2147483647;
  *seed = (unsigned int)new_seed;
  return (int) (new_seed & RAND_MAX);
#else
  return ::rand_r (seed);
# endif /* ACE_LACKS_RAND_R */
}

#  if !defined (ACE_LACKS_REALPATH)
ACE_INLINE char *
ACE_OS::realpath (const char *file_name,
                  char *resolved_name)
{
#    if defined (ACE_WIN32)
  return ::_fullpath (resolved_name, file_name, PATH_MAX);
#    else /* ACE_WIN32 */
  return ::realpath (file_name, resolved_name);
#    endif /* ! ACE_WIN32 */
}

#  if defined (ACE_HAS_WCHAR)
ACE_INLINE wchar_t *
ACE_OS::realpath (const wchar_t *file_name,
                  wchar_t *resolved_name)
{
#    if defined (ACE_WIN32)
  return ::_wfullpath (resolved_name, file_name, PATH_MAX);
#    else /* ACE_WIN32 */
  ACE_Wide_To_Ascii n_file_name (file_name);
  char n_resolved[PATH_MAX];
  if (0 != ACE_OS::realpath (n_file_name.char_rep (), n_resolved))
    {
      ACE_Ascii_To_Wide w_resolved (n_resolved);
      ACE_OS::strcpy (resolved_name, w_resolved.wchar_rep ());
      return resolved_name;
    }
  return 0;
#    endif /* ! ACE_WIN32 */
}
#  endif /* ACE_HAS_WCHAR */
#endif /* ACE_HAS_WINCE */

ACE_INLINE ACE_EXIT_HOOK
ACE_OS::set_exit_hook (ACE_EXIT_HOOK exit_hook)
{
  ACE_EXIT_HOOK old_hook = exit_hook_;
  exit_hook_ = exit_hook;
  return old_hook;
}

ACE_INLINE void
ACE_OS::srand (u_int seed)
{
  ACE_OS_TRACE ("ACE_OS::srand");
  ::srand (seed);
}

#if !defined (ACE_LACKS_STRTOD)
ACE_INLINE double
ACE_OS::strtod (const char *s, char **endptr)
{
  return ::strtod (s, endptr);
}
#endif /* !ACE_LACKS_STRTOD */

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOD)
ACE_INLINE double
ACE_OS::strtod (const wchar_t *s, wchar_t **endptr)
{
  return ACE_WCHAR_STD_NAMESPACE::wcstod (s, endptr);
}
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOD */

ACE_INLINE long
ACE_OS::strtol (const char *s, char **ptr, int base)
{
#if defined (ACE_LACKS_STRTOL)
  return ACE_OS::strtol_emulation (s, ptr, base);
#else  /* ACE_LACKS_STRTOL */
  return ::strtol (s, ptr, base);
#endif /* ACE_LACKS_STRTOL */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE long
ACE_OS::strtol (const wchar_t *s, wchar_t **ptr, int base)
{
#if defined (ACE_LACKS_WCSTOL)
  return ACE_OS::wcstol_emulation (s, ptr, base);
#else
  return ACE_WCHAR_STD_NAMESPACE::wcstol (s, ptr, base);
#endif /* ACE_LACKS_WCSTOL */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE unsigned long
ACE_OS::strtoul (const char *s, char **ptr, int base)
{
#if defined (ACE_LACKS_STRTOUL)
  return ACE_OS::strtoul_emulation (s, ptr, base);
#else /* ACE_LACKS_STRTOUL */
  return ::strtoul (s, ptr, base);
#endif /* ACE_LACKS_STRTOUL */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE unsigned long
ACE_OS::strtoul (const wchar_t *s, wchar_t **ptr, int base)
{
#if defined (ACE_LACKS_WCSTOUL)
  return ACE_OS::wcstoul_emulation (s, ptr, base);
#else
  return ACE_WCHAR_STD_NAMESPACE::wcstoul (s, ptr, base);
#endif /* ACE_LACKS_WCSTOUL */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE ACE_INT64
ACE_OS::strtoll (const char *s, char **ptr, int base)
{
#if defined (ACE_LACKS_STRTOLL)
  return ACE_OS::strtoll_emulation (s, ptr, base);
#elif defined (ACE_STRTOLL_EQUIVALENT)
  return ACE_STRTOLL_EQUIVALENT (s, ptr, base);
#else
  return ace_strtoll_helper (s, ptr, base);
#endif /* ACE_LACKS_STRTOLL */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE ACE_INT64
ACE_OS::strtoll (const wchar_t *s, wchar_t **ptr, int base)
{
#if defined (ACE_LACKS_WCSTOLL)
  return ACE_OS::wcstoll_emulation (s, ptr, base);
#elif defined (ACE_WCSTOLL_EQUIVALENT)
  return ACE_WCSTOLL_EQUIVALENT (s, ptr, base);
#else
  return ACE_WCHAR_STD_NAMESPACE::wcstoll (s, ptr, base);
#endif /* ACE_LACKS_WCSTOLL */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE ACE_UINT64
ACE_OS::strtoull (const char *s, char **ptr, int base)
{
#if defined (ACE_LACKS_STRTOULL)
  return ACE_OS::strtoull_emulation (s, ptr, base);
#elif defined (ACE_STRTOULL_EQUIVALENT)
  return ACE_STRTOULL_EQUIVALENT (s, ptr, base);
#else
  return ace_strtoull_helper (s, ptr, base);
#endif /* ACE_LACKS_STRTOULL */
}

#if defined (ACE_HAS_WCHAR)
ACE_INLINE ACE_UINT64
ACE_OS::strtoull (const wchar_t *s, wchar_t **ptr, int base)
{
#if defined (ACE_LACKS_WCSTOULL)
  return ACE_OS::wcstoull_emulation (s, ptr, base);
#elif defined (ACE_WCSTOULL_EQUIVALENT)
  return ACE_WCSTOULL_EQUIVALENT (s, ptr, base);
#else
  return ACE_WCHAR_STD_NAMESPACE::wcstoull (s, ptr, base);
#endif /* ACE_LACKS_WCSTOULL */
}
#endif /* ACE_HAS_WCHAR */

ACE_INLINE int
ACE_OS::system (const ACE_TCHAR *s)
{
  // ACE_OS_TRACE ("ACE_OS::system");
#if defined (ACE_LACKS_SYSTEM)
  ACE_UNUSED_ARG (s);
  ACE_NOTSUP_RETURN (-1);
#elif defined (ACE_WIN32) && defined (ACE_USES_WCHAR)
  ACE_OSCALL_RETURN (::_wsystem (s), int, -1);
#else
  ACE_OSCALL_RETURN (::system (ACE_TEXT_ALWAYS_CHAR (s)), int, -1);
#endif /* ACE_LACKS_SYSTEM */
}

ACE_INLINE const char*
ACE_OS::getprogname ()
{
#if defined (ACE_HAS_GETPROGNAME)
  return ::getprogname ();
#else
  return ACE_OS::getprogname_emulation ();
#endif /* ACE_HAS_GETPROGNAME */
}

ACE_INLINE void
ACE_OS::setprogname (const char* name)
{
#if defined (ACE_HAS_SETPROGNAME)
  ::setprogname (name);
#else
  ACE_OS::setprogname_emulation (name);
#endif /* ACE_HAS_SETPROGNAME */
}

ACE_END_VERSIONED_NAMESPACE_DECL
