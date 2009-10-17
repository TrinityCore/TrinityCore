// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_stdlib.h
 *
 *  $Id: OS_NS_stdlib.h 81804 2008-05-29 16:12:07Z vzykov $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_STDLIB_H
# define ACE_OS_NS_STDLIB_H

# include /**/ "ace/pre.h"

# include "ace/config-all.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/os_include/os_stdlib.h"
#include /**/ "ace/ACE_export.h"

#include "ace/Basic_Types.h"  /* ACE_UINT64 and intptr_t in inl file */

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

# if defined (ACE_HAS_BROKEN_R_ROUTINES)
#   undef rand_r
# endif /* ACE_HAS_BROKEN_R_ROUTINES */

// We need this for MVS... as well as Linux, etc...
// On Windows, we explicitly set this up as __cdecl so it's correct even
// if building with another calling convention, such as __stdcall.
#if defined (ACE_WIN32) && defined (_MSC_VER)
extern "C" {
  typedef int (__cdecl *ACE_COMPARE_FUNC)(const void *, const void *);
}
#else
extern "C" {
  typedef int (*ACE_COMPARE_FUNC)(const void *, const void *);
}
#endif /* ACE_WIN32 && _MSC_VER */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS {

  /** @name Non-standard functions
   *
   *  These functions aren't in the standard.
   *
   */
  //@{

  ACE_NAMESPACE_INLINE_FUNCTION
  void _exit (int status = 0);

  ACE_NAMESPACE_INLINE_FUNCTION
  void abort (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int atexit (ACE_EXIT_HOOK func);

  ACE_NAMESPACE_INLINE_FUNCTION
  int atoi (const char *s);

# if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  int atoi (const wchar_t *s);
# endif /* ACE_HAS_WCHAR */

  // atop not in spec
# if defined (atop)
#   undef atop
# endif /* atop */

  ACE_NAMESPACE_INLINE_FUNCTION
  void *atop (const char *s);

# if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  void *atop (const wchar_t *s);
# endif /* ACE_HAS_WCHAR */

  ACE_NAMESPACE_INLINE_FUNCTION
  void *bsearch (const void *key,
                 const void *base,
                 size_t nel,
                 size_t size,
                 ACE_COMPARE_FUNC);

  extern ACE_Export
  void *calloc (size_t elements, size_t sizeof_elements);

  extern ACE_Export
  void exit (int status = 0);

  extern ACE_Export
  void free (void *);

  ACE_NAMESPACE_INLINE_FUNCTION
  char *getenv (const char *symbol);

#   if defined (ACE_HAS_WCHAR) && defined (ACE_WIN32)
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *getenv (const wchar_t *symbol);
#   endif /* ACE_HAS_WCHAR && ACE_WIN32 */

  // not in spec
  extern ACE_Export
  ACE_TCHAR *getenvstrings (void);

  // itoa not in spec
  /// Converts an integer to a string.
  ACE_NAMESPACE_INLINE_FUNCTION
  char *itoa (int value, char *string, int radix);

#if defined (ACE_HAS_WCHAR)
  /// Converts an integer to a string.
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *itoa (int value, wchar_t *string, int radix);
#endif /* ACE_HAS_WCHAR */

#if !defined (ACE_HAS_ITOA)
  /// Emulated itoa - Converts an integer to a string.
  extern ACE_Export
  char *itoa_emulation (int value, char *string, int radix);
#endif /* !ACE_HAS_ITOA */

#if defined (ACE_HAS_WCHAR) && defined (ACE_LACKS_ITOW)
  /// Emulated itow - Converts an integer to a string.
  extern ACE_Export
  wchar_t *itow_emulation (int value, wchar_t *string, int radix);
#endif /* ACE_HAS_WCHAR && ACE_LACKS_ITOW */

  extern ACE_Export
  void *malloc (size_t);

  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE mkstemp (char *s);

#  if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_HANDLE mkstemp (wchar_t *s);
#  endif /* ACE_HAS_WCHAR */

#if defined (ACE_LACKS_MKSTEMP)
  extern ACE_Export
  ACE_HANDLE mkstemp_emulation (ACE_TCHAR * s);
#endif /* ACE_LACKS_MKSTEMP */

#if !defined (ACE_LACKS_MKTEMP)
  ACE_NAMESPACE_INLINE_FUNCTION
  char *mktemp (char *s);

#  if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *mktemp (wchar_t *s);
#  endif /* ACE_HAS_WCHAR */
#else
  extern ACE_Export
  ACE_TCHAR *mktemp (ACE_TCHAR *s);
#endif /* !ACE_LACKS_MSTEMP */

  ACE_NAMESPACE_INLINE_FUNCTION
  int putenv (const char *string);

#if defined (ACE_HAS_WCHAR) && defined (ACE_WIN32)
  // Windows is the only platform that supports a wchar_t environment.
  // Since other platforms make @a string part of the environment, it's
  // a certain memory leak to copy and transform wchar_t to char for
  // emulating this, so it's not attempted.
  ACE_NAMESPACE_INLINE_FUNCTION
  int putenv (const wchar_t *string);
#endif /* ACE_HAS_WCHAR && ACE_WIN32 */

  ACE_NAMESPACE_INLINE_FUNCTION
  void qsort (void *base,
              size_t nel,
              size_t width,
              ACE_COMPARE_FUNC);

  ACE_NAMESPACE_INLINE_FUNCTION
  int rand (void);

  ACE_NAMESPACE_INLINE_FUNCTION
  int rand_r (ACE_RANDR_TYPE &seed);

  extern ACE_Export
  void *realloc (void *, size_t);

#if !defined (ACE_HAS_WINCE)
#  if !defined (ACE_LACKS_REALPATH)
  ACE_NAMESPACE_INLINE_FUNCTION
#  else
  extern ACE_Export
#  endif /* !ACE_LACKS_REALPATH */
  char *realpath (const char *file_name, char *resolved_name);

#  if defined (ACE_HAS_WCHAR)
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *realpath (const wchar_t *file_name, wchar_t *resolved_name);
#  endif /* ACE_HAS_WCHAR */
#endif /* ACE_HAS_WINCE */

  // exit_hook and set_exit_hook not in spec
  /// Function that is called by <ACE_OS::exit>, if non-null.
  extern ACE_Export ACE_EXIT_HOOK exit_hook_;

  /// For use by ACE_Object_Manager only, to register its exit hook..
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_EXIT_HOOK set_exit_hook (ACE_EXIT_HOOK hook);

  ACE_NAMESPACE_INLINE_FUNCTION
  void srand (u_int seed);

  // not in spec
  extern ACE_Export
  ACE_TCHAR *strenvdup (const ACE_TCHAR *str);

#if !defined (ACE_LACKS_STRTOD)
  /// Converts a string to a double value (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  double strtod (const char *s, char **endptr);
#endif /* !ACE_LACKS_STRTOD */

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOD)
  /// Converts a string to a double value (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  double strtod (const wchar_t *s, wchar_t **endptr);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOD */

  /// Converts a string to a long value (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  long strtol (const char *s, char **ptr, int base);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOL)
  /// Converts a string to a long value (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  long strtol (const wchar_t *s, wchar_t **ptr, int base);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOL */

#if defined (ACE_LACKS_STRTOL)
  extern ACE_Export
  long strtol_emulation (const char *nptr, char **endptr, int base);
#endif /* ACE_LACKS_STRTOL */

  /// Converts a string to an unsigned long value (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  unsigned long strtoul (const char *s, char **ptr, int base);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOUL)
  /// Converts a string to an unsigned long value (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  unsigned long strtoul (const wchar_t *s, wchar_t **ptr, int base);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOUL */

#if defined (ACE_LACKS_STRTOUL)
  extern ACE_Export
  unsigned long strtoul_emulation (const char *nptr,
                                   char **endptr,
                                   int base);
#endif /* ACE_LACKS_STRTOUL */

  /// Converts a string to a 64 bit int value (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_UINT64 strtoull (const char *s, char **ptr, int base);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOULL)
  /// Converts a string to a 64 bit int value (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_UINT64 strtoull (const wchar_t *s, wchar_t **ptr, int base);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOUL */

#if defined (ACE_LACKS_STRTOULL)
  extern ACE_Export
  ACE_UINT64 strtoull_emulation (const char *nptr,
                                 char **endptr,
                                 int base);
#endif /* ACE_LACKS_STRTOULL */

  ACE_NAMESPACE_INLINE_FUNCTION
  int system (const ACE_TCHAR *s);

  /// Get the name of the current program
  ///
  /// Originally from NetBSD, now found in *BSD, Cygwin, Darwin, etc.
  ACE_NAMESPACE_INLINE_FUNCTION
  const char *getprogname ();

#if !defined (ACE_HAS_GETPROGNAME)
  extern ACE_Export
  const char *getprogname_emulation ();
#endif /* !ACE_HAS_GETPROGNAME */

  /// Set the name of the current program
  ///
  /// Originally from NetBSD, now found in *BSD, Cygwin, Darwin, etc.
  ACE_NAMESPACE_INLINE_FUNCTION
  void setprogname (const char* name);

#if !defined (ACE_HAS_SETPROGNAME)
  extern ACE_Export
  void setprogname_emulation (const char* name);
#endif /* !ACE_HAS_SETPROGNAME */

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_stdlib.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_STDLIB_H */

