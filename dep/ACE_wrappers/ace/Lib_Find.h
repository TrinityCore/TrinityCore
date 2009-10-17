// -*- C++ -*-
//=============================================================================
/**
 *  @file   Lib_Find.h
 *
 *  All the static function calls needed to search and open shared
 *  libraries.
 *
 *  $Id: Lib_Find.h 80826 2008-03-04 14:51:23Z wotte $
 */
//=============================================================================
#ifndef ACE_LIB_FIND_H
#define ACE_LIB_FIND_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#include /**/ "ace/ACE_export.h"
#include "ace/os_include/os_stdio.h"
#if defined (ACE_OPENVMS)
# include "ace/OS_NS_dlfcn.h"
#endif
ACE_BEGIN_VERSIONED_NAMESPACE_DECL
namespace ACE
{
  // = Methods for searching and opening shared libraries.
  /**
   * Finds the file @a filename either using an absolute path or using
   * a relative path in conjunction with ACE_LD_SEARCH_PATH (e.g.,
   * $LD_LIBRARY_PATH on UNIX or the directories scaned by Win32 API
   * SearchPath on Win32).  This function will add appropriate suffix
   * (e.g., .dll on Win32 or .so on UNIX) according to the OS
   * platform.  In addition, this function will apply the appropriate
   * prefix (e.g., "lib" on UNIX and "" on Win32) if the @a filename
   * doesn't match directly.
   */
  extern ACE_Export int ldfind (const ACE_TCHAR* filename,
                                ACE_TCHAR pathname[],
                                size_t maxpathnamelen);
  /**
   * Uses @c ldfind to locate and open the appropriate @a filename and
   * returns a pointer to the file, else it returns a NULL
   * pointer. @a type specifies how the file should be open.
   */
  extern ACE_Export FILE *ldopen (const ACE_TCHAR *filename,
                                  const ACE_TCHAR *type);
  /**
   * Transforms @a entry_point into a form that can be located in a
   * dynamic library using <dlsym>. For example, with Win32/Borland
   * extern "C" functions which use the default calling convention
   * have a '_' prepended. Always returns a buffer that has been
   * dynamically allocated using <operator new>.
   */
  extern ACE_Export ACE_TCHAR *ldname (const ACE_TCHAR *entry_point);

#if defined (ACE_OPENVMS)
  /**
   * Registers an @a entry_point and its address for later retrieval
   * through the ACE::ldsymbol () method.
   * For use in cases where the OS compiler encodes long symbolnames.
   */
  extern ACE_Export void ldregister (const ACE_TCHAR *entry_point,
                                     void* entry_addr);
  /**
   * Looks up an @a entry_point address either from previously registered
   * symbols or through ACE_OS::dlsym ().
   * Returns 0 in case the entry_point is not found, otherwise nonzero.
   * For use in cases where the OS compiler encodes long symbolnames.
   */
  extern ACE_Export void *ldsymbol (ACE_SHLIB_HANDLE sh,
                                    const ACE_TCHAR *entry_point);
#endif
  /**
   * Returns the temporary directory including the trailing slash in
   * @a buffer.  Returns -1 for an error or if the buffer_len is not
   * long enough.
   */
  extern ACE_Export int get_temp_dir (ACE_TCHAR *buffer, size_t buffer_len);
  /// Opening the temp file.  File is automagically unlinked when it is
  /// closed.  This is useful for have temp files.
  extern ACE_Export ACE_HANDLE open_temp_file (const ACE_TCHAR *name,
                                               int mode,
                                               int perm = 0);
  // @@ Though the following functions dont come under the same category as
  // above, these are used only in the functions in this class. So it makes
  // more sense to move these functions too to this class.
  //
  /// Replace all instances of @a search in @a s with @a replace.  Returns
  /// the number of replacements made.
  extern ACE_Export size_t strrepl (char *s, char search, char replace);
  /**
   * Splits string <s> into pieces separated by the string <token>.
   * <next_start> is an opaque cookie handed back by the call to store
   * its state for the next invocation, thus making it re-entrant.
   * This operates very similar to Perl's <split> function except that
   * it returns pieces one at a time instead of into an array.
   */
  extern ACE_Export char *strsplit_r (char *s,
                                      const char *token,
                                      char *&next_start);
#if defined (ACE_HAS_WCHAR)
  /// As strrepl, but for wide characters.
  extern ACE_Export size_t strrepl (wchar_t *s,
                                    wchar_t search,
                                    wchar_t replace);
  /// As strsplit_r, but for wide characters.
  extern ACE_Export wchar_t *strsplit_r (wchar_t *s,
                                         const wchar_t *token,
                                         wchar_t *&next_start);
#endif /* ACE_HAS_WCHAR */
}
ACE_END_VERSIONED_NAMESPACE_DECL
#include /**/ "ace/post.h"
#endif  /* ACE_LIB_FIND_H */

