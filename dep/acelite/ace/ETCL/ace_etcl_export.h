
// -*- C++ -*-
// $Id: ace_etcl_export.h 81458 2008-04-28 11:31:49Z johnnyw $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl
// ------------------------------
#ifndef ACE_ETCL_EXPORT_H
#define ACE_ETCL_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS)
#  if !defined (ACE_ETCL_HAS_DLL)
#    define ACE_ETCL_HAS_DLL 0
#  endif /* ! ACE_ETCL_HAS_DLL */
#else
#  if !defined (ACE_ETCL_HAS_DLL)
#    define ACE_ETCL_HAS_DLL 1
#  endif /* ! ACE_ETCL_HAS_DLL */
#endif

#if defined (ACE_ETCL_HAS_DLL) && (ACE_ETCL_HAS_DLL == 1)
#  if defined (ACE_ETCL_BUILD_DLL)
#    define ACE_ETCL_Export ACE_Proper_Export_Flag
#    define ACE_ETCL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ACE_ETCL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ACE_ETCL_BUILD_DLL */
#    define ACE_ETCL_Export ACE_Proper_Import_Flag
#    define ACE_ETCL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ACE_ETCL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ACE_ETCL_BUILD_DLL */
#else /* ACE_ETCL_HAS_DLL == 1 */
#  define ACE_ETCL_Export
#  define ACE_ETCL_SINGLETON_DECLARATION(T)
#  define ACE_ETCL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ACE_ETCL_HAS_DLL == 1 */

#endif /* ACE_ETCL_EXPORT_H */

// End of auto generated file.
