// -*- C++ -*-
// $Id: ACE_export.h 80826 2008-03-04 14:51:23Z wotte $
// Definition for Win32 Export directives.
// This file is generated automatically by
// generate_export_file.pl
// ------------------------------

#ifndef ACE_EXPORT_H
#define ACE_EXPORT_H

#include "ace/config-lite.h"

#if defined (ACE_AS_STATIC_LIBS)

# if !defined (ACE_HAS_DLL)
#   define ACE_HAS_DLL 0
# endif /* ! ACE_HAS_DLL */
#else
# if !defined (ACE_HAS_DLL)
#   define ACE_HAS_DLL 1
# endif /* ! ACE_HAS_DLL */
#endif /* ACE_AS_STATIC_LIB */

#if defined (ACE_HAS_DLL)
#  if (ACE_HAS_DLL == 1)
#    if defined (ACE_BUILD_DLL)
#      define ACE_Export ACE_Proper_Export_Flag
#      define ACE_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#      define ACE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    else
#      define ACE_Export ACE_Proper_Import_Flag
#      define ACE_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#      define ACE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#    endif /* ACE_BUILD_DLL */
#  else
#    define ACE_Export
#    define ACE_SINGLETON_DECLARATION(T)
#    define ACE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif   /* ! ACE_HAS_DLL == 1 */
#else
#  define ACE_Export
#  define ACE_SINGLETON_DECLARATION(T)
#  define ACE_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif     /* ACE_HAS_DLL */

// Added by hand to help with ACE_OS namespace
#if defined (__TANDEM) && defined (USE_EXPLICIT_EXPORT)
#define ACE_NAMESPACE_STORAGE_CLASS ACE_EXPORT_MACRO extern
#else
#define ACE_NAMESPACE_STORAGE_CLASS extern ACE_EXPORT_MACRO
#endif

#if defined (__ACE_INLINE__)
#  if defined (_MSC_VER) || defined (__MINGW32__) || defined (CYGWIN32) || \
      (defined (__SUNPRO_CC) && __SUNPRO_CC >= 0x560) || \
      (defined (__HP_aCC) && (__HP_aCC >= 60500)) || \
      (defined (__sgi) && \
       defined (_COMPILER_VERSION) && _COMPILER_VERSION <= 730)
#    define ACE_NAMESPACE_INLINE_FUNCTION inline
#  else
#    define ACE_NAMESPACE_INLINE_FUNCTION ACE_NAMESPACE_STORAGE_CLASS inline
#  endif
#  define ACE_INLINE_TEMPLATE_FUNCTION inline
#else
#  define ACE_NAMESPACE_INLINE_FUNCTION ACE_NAMESPACE_STORAGE_CLASS
// Microsoft Visual C++ will accept 'extern'; others refuse.
#  if defined (_MSC_VER) || defined (__BORLANDC__)
#    define ACE_INLINE_TEMPLATE_FUNCTION ACE_Export
#  else
#    define ACE_INLINE_TEMPLATE_FUNCTION
#  endif
#endif

#endif     /* ACE_EXPORT_H */

// End of auto generated file.
