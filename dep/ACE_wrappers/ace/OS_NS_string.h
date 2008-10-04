// -*- C++ -*-

//=============================================================================
/**
 *  @file   OS_NS_string.h
 *
 *  $Id: OS_NS_string.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Douglas C. Schmidt <schmidt@cs.wustl.edu>
 *  @author Jesper S. M|ller<stophph@diku.dk>
 *  @author and a cast of thousands...
 *
 *  Originally in OS.h.
 */
//=============================================================================

#ifndef ACE_OS_NS_STRING_H
#define ACE_OS_NS_STRING_H

# include /**/ "ace/pre.h"

# include "ace/config-lite.h"

# if !defined (ACE_LACKS_PRAGMA_ONCE)
#  pragma once
# endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ace/Basic_Types.h" // to get ACE_WCHAR_T,
                            // should be in os_stddef.h or not used like this.
#include /**/ "ace/ACE_export.h"

#if defined (ACE_EXPORT_MACRO)
#  undef ACE_EXPORT_MACRO
#endif
#define ACE_EXPORT_MACRO ACE_Export

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

namespace ACE_OS {

  /** @name Functions from <cstring>
   *
   *  Included are the functions defined in <cstring> and their <cwchar>
   *  equivalents.
   *
   *  @todo To be complete, we should add strcoll, and strxfrm.
   */
  //@{

  /// Finds characters in a buffer (const void version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const void *memchr (const void *s, int c, size_t len);

  /// Finds characters in a buffer (void version).
  ACE_NAMESPACE_INLINE_FUNCTION
  void *memchr (void *s, int c, size_t len);

#if defined (ACE_LACKS_MEMCHR)
  /// Emulated memchr - Finds a character in a buffer.
  extern ACE_Export
  const void *memchr_emulation (const void *s, int c, size_t len);
#endif /* ACE_LACKS_MEMCHR */

  /// Compares two buffers.
  ACE_NAMESPACE_INLINE_FUNCTION
  int memcmp (const void *t, const void *s, size_t len);

  /// Copies one buffer to another.
  ACE_NAMESPACE_INLINE_FUNCTION
  void *memcpy (void *t, const void *s, size_t len);

#if defined (ACE_HAS_MEMCPY_LOOP_UNROLL)
/*
 * Version of memcpy where the copy loop is unrolled.
 * On certain platforms this results in better performance.
 * This is determined and set via autoconf.
 */
  extern ACE_Export
  void *fast_memcpy (void *t, const void *s, size_t len);
#endif

  /// Moves one buffer to another.
  ACE_NAMESPACE_INLINE_FUNCTION
  void *memmove (void *t, const void *s, size_t len);

  /// Fills a buffer with a character value.
  ACE_NAMESPACE_INLINE_FUNCTION
  void *memset (void *s, int c, size_t len);

  /// Appends a string to another string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strcat (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Appends a string to another string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strcat (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a character in a string (const char
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const char *strchr (const char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a character in a string (const wchar_t
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const wchar_t *strchr (const wchar_t *s, wchar_t c);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a character in a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strchr (char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a character in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strchr (wchar_t *s, wchar_t c);
#endif /* ACE_HAS_WCHAR */

  /// Compares two strings (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  int strcmp (const char *s, const char *t);

  /// Compares two strings (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  int strcmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t);

  /// Copies a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strcpy (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Copies a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strcpy (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Searches for the first substring without any of the specified
  /// characters and returns the size of the substring (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strcspn (const char *s, const char *reject);

#if defined (ACE_HAS_WCHAR)
  /// Searches for the first substring without any of the specified
  /// characters and returns the size of the substring (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strcspn (const wchar_t *s, const wchar_t *reject);
#endif /* ACE_HAS_WCHAR */

  /// Returns a malloced duplicated string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strdup (const char *s);

#if (defined (ACE_LACKS_STRDUP) && !defined(ACE_STRDUP_EQUIVALENT)) \
  || defined (ACE_HAS_STRDUP_EMULATION)
  extern ACE_Export
  char *strdup_emulation (const char *s);
#endif

#if defined (ACE_HAS_WCHAR)
  /// Returns a malloced duplicated string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strdup (const wchar_t *s);

#if (defined (ACE_LACKS_WCSDUP) && !defined(ACE_WCSDUP_EQUIVALENT)) \
  || defined (ACE_HAS_WCSDUP_EMULATION)
  extern ACE_Export
  wchar_t *strdup_emulation (const wchar_t *s);
#endif
#endif /* ACE_HAS_WCHAR */

  /// Copies a string, but returns a pointer to the end of the
  /// copied region (char version).
  extern ACE_Export
  char *strecpy (char *des, const char *src);

#if defined (ACE_HAS_WCHAR)
  /// Copies a string, but returns a pointer to the end of the
  /// copied region (wchar_t version).
  extern ACE_Export
  wchar_t *strecpy (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /*
  ** Returns a system error message. If the supplied errnum is out of range,
  ** a string of the form "Unknown error %d" is used to format the string
  ** whose pointer is returned and errno is set to EINVAL.
  */
  extern ACE_Export
  char *strerror (int errnum);

#if defined (ACE_LACKS_STRERROR)
  /// Emulated strerror - Returns a system error message.
  extern ACE_Export
  char *strerror_emulation (int errnum);
#endif /* ACE_LACKS_STRERROR */

  /// Finds the length of a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strlen (const char *s);

  /// Finds the length of a string (ACE_WCHAR_T version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strlen (const ACE_WCHAR_T *s);

  /// Appends part of a string to another string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strncat (char *s, const char *t, size_t len);

  /// Appends part of a string to another string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_WCHAR_T *strncat (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Finds the first occurance of a character in an array (const char
  /// version).
  extern ACE_Export
  const char *strnchr (const char *s, int c, size_t len);

  /// Finds the first occurance of a character in an array (const ACE_WCHAR_T
  /// version).
  extern ACE_Export
  const ACE_WCHAR_T *strnchr (const ACE_WCHAR_T *s, ACE_WCHAR_T c, size_t len);

  /// Finds the first occurance of a character in an array (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strnchr (char *s, int c, size_t len);

  /// Finds the first occurance of a character in an array (ACE_WCHAR_T version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_WCHAR_T *strnchr (ACE_WCHAR_T *s, ACE_WCHAR_T c, size_t len);

  /// Compares two arrays (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  int strncmp (const char *s, const char *t, size_t len);

  /// Compares two arrays (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  int strncmp (const ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Copies an array (char version)
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strncpy (char *s, const char *t, size_t len);

  /// Copies an array (ACE_WCHAR_T version)
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_WCHAR_T *strncpy (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Finds the length of a limited-length string (char version).
  /**
   * @param s       The character string to find the length of.
   * @param maxlen  The maximum number of characters that will be
   *                scanned for the terminating nul character.
   *
   * @return The length of @arg s, if the terminating nul character
   *         is located, else @arg maxlen.
   */
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strnlen (const char *s, size_t maxlen);

  /// Finds the length of a limited-length string (ACE_WCHAR_T version).
  /**
   * @param s       The character string to find the length of.
   * @param maxlen  The maximum number of characters that will be
   *                scanned for the terminating nul character.
   *
   * @return The length of @arg s, if the terminating nul character
   *         is located, else @arg maxlen.
   */
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strnlen (const ACE_WCHAR_T *s, size_t maxlen);

  /// Finds the first occurance of a substring in an array (const char
  /// version).
  extern ACE_Export
  const char *strnstr (const char *s, const char *t, size_t len);

  /// Finds the first occurance of a substring in an array (const wchar_t
  /// version).
  extern ACE_Export
  const ACE_WCHAR_T *strnstr (const ACE_WCHAR_T *s,
                              const ACE_WCHAR_T *t,
                              size_t len);

  /// Finds the first occurance of a substring in an array (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strnstr (char *s, const char *t, size_t len);

  /// Finds the first occurance of a substring in an array (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  ACE_WCHAR_T *strnstr (ACE_WCHAR_T *s, const ACE_WCHAR_T *t, size_t len);

  /// Searches for characters in a string (const char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const char *strpbrk (const char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for characters in a string (const wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const wchar_t *strpbrk (const wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Searches for characters in a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strpbrk (char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for characters in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strpbrk (wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Finds the last occurance of a character in a string (const char
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const char *strrchr (const char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the last occurance of a character in a string (const wchar_t
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const wchar_t *strrchr (const wchar_t *s, wchar_t c);
#endif /* ACE_HAS_WCHAR */

  /// Finds the last occurance of a character in a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strrchr (char *s, int c);

#if defined (ACE_HAS_WCHAR)
  /// Finds the last occurance of a character in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strrchr (wchar_t *s, wchar_t c);
#endif /* ACE_HAS_WCHAR */

#if defined (ACE_LACKS_STRRCHR)
  /// Emulated strrchr (char version) - Finds the last occurance of a
  /// character in a string.
  extern ACE_Export
  char *strrchr_emulation (char *s, int c);

  /// Emulated strrchr (const char version) - Finds the last occurance of a
  /// character in a string.
  extern ACE_Export
  const char *strrchr_emulation (const char *s, int c);
#endif /* ACE_LACKS_STRRCHR */

  /// This is a "safe" c string copy function (char version).
  /**
   * Unlike strncpy() this function will always add a terminating '\0'
   * char if maxlen > 0.  So the user doesn't has to provide an extra
   * '\0' if the user wants a '\0' terminated dst.  The function
   * doesn't check for a 0 @a dst, because this will give problems
   * anyway.  When @a src is 0 an empty string is made.  We do not
   * "touch" * @a dst if maxlen is 0.  Returns @a dst.  Care should be
   * taken when replacing strncpy() calls, because in some cases a
   * strncpy() user is using the "not '\0' terminating" feature from
   * strncpy().  This happens most when the call to strncpy() was
   * optimized by using a maxlen which is 1 smaller than the size
   * because there's always written a '\0' inside this last position.
   * Very seldom it's possible that the '\0' padding feature from
   * strncpy() is needed.
   */
  extern ACE_Export
  char *strsncpy (char *dst,
                  const char *src,
                  size_t maxlen);

  /// This is a "safe" c string copy function (wchar_t version).
  /**
   * Unlike strncpy() this function will always add a terminating '\0'
   * char if maxlen > 0.  So the user doesn't has to provide an extra
   * '\0' if the user wants a '\0' terminated dst.  The function
   * doesn't check for a 0 @a dst, because this will give problems
   * anyway.  When @a src is 0 an empty string is made.  We do not
   * "touch" * @a dst if maxlen is 0.  Returns @a dst.  Care should be
   * taken when replacing strncpy() calls, because in some cases a
   * strncpy() user is using the "not '\0' terminating" feature from
   * strncpy().  This happens most when the call to strncpy() was
   * optimized by using a maxlen which is 1 smaller than the size
   * because there's always written a '\0' inside this last position.
   * Very seldom it's possible that the '\0' padding feature from
   * strncpy() is needed.
   */
  extern ACE_Export
  ACE_WCHAR_T *strsncpy (ACE_WCHAR_T *dst,
                         const ACE_WCHAR_T *src,
                         size_t maxlen);

  /// Searches for the first substring containing only the specified
  /// characters and returns the size of the substring (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strspn (const char *s1, const char *s2);

#if defined (ACE_HAS_WCHAR)
  /// Searches for the first substring containing only the specified
  /// characters and returns the size of the substring (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  size_t strspn (const wchar_t *s1, const wchar_t *s2);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a substring in a string (const char
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const char *strstr (const char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a substring in a string (const wchar_t
  /// version).
  ACE_NAMESPACE_INLINE_FUNCTION
  const wchar_t *strstr (const wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the first occurance of a substring in a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strstr (char *s, const char *t);

#if defined (ACE_HAS_WCHAR)
  /// Finds the first occurance of a substring in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strstr (wchar_t *s, const wchar_t *t);
#endif /* ACE_HAS_WCHAR */

  /// Finds the next token in a string (char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strtok (char *s, const char *tokens);

#if defined (ACE_HAS_WCHAR) && !defined (ACE_LACKS_WCSTOK)
  /// Finds the next token in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strtok (wchar_t *s, const wchar_t *tokens);
#endif /* ACE_HAS_WCHAR && !ACE_LACKS_WCSTOK */

  //@}

  /// Finds the next token in a string (safe char version).
  ACE_NAMESPACE_INLINE_FUNCTION
  char *strtok_r (char *s, const char *tokens, char **lasts);

#if defined (ACE_HAS_WCHAR)
  /// Finds the next token in a string (wchar_t version).
  ACE_NAMESPACE_INLINE_FUNCTION
  wchar_t *strtok_r (ACE_WCHAR_T *s, const ACE_WCHAR_T *tokens, ACE_WCHAR_T **lasts);
#endif  // ACE_HAS_WCHAR

#if !defined (ACE_HAS_REENTRANT_FUNCTIONS) || defined (ACE_LACKS_STRTOK_R)
  /// Emulated strtok_r.
  extern ACE_Export
  char *strtok_r_emulation (char *s, const char *tokens, char **lasts);
#endif /* !ACE_HAS_REENTRANT_FUNCTIONS */

# if defined (ACE_HAS_WCHAR) && defined(ACE_LACKS_WCSTOK)
  /// Emulated strtok_r (wchar_t version).
  extern ACE_Export
  wchar_t *strtok_r_emulation (ACE_WCHAR_T *s, const ACE_WCHAR_T *tokens, ACE_WCHAR_T **lasts);
# endif  // ACE_HAS_WCHAR && ACE_LACKS_WCSTOK

} /* namespace ACE_OS */

ACE_END_VERSIONED_NAMESPACE_DECL

# if defined (ACE_HAS_INLINED_OSCALLS)
#   if defined (ACE_INLINE)
#     undef ACE_INLINE
#   endif /* ACE_INLINE */
#   define ACE_INLINE inline
#   include "ace/OS_NS_string.inl"
# endif /* ACE_HAS_INLINED_OSCALLS */

# include /**/ "ace/post.h"
#endif /* ACE_OS_NS_STRING_H */
