
// -*- C++ -*-
// $Id: etcl_parser_export.h 81640 2008-05-07 19:04:11Z parsons $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl
// ------------------------------
#ifndef ETCL_PARSER_EXPORT_H
#define ETCL_PARSER_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS)
#  if !defined (ETCL_PARSER_HAS_DLL)
#    define ETCL_PARSER_HAS_DLL 0
#  endif /* ! ETCL_PARSER_HAS_DLL */
#else
#  if !defined (ETCL_PARSER_HAS_DLL)
#    define ETCL_PARSER_HAS_DLL 1
#  endif /* ! ETCL_PARSER_HAS_DLL */
#endif

#if defined (ETCL_PARSER_HAS_DLL) && (ETCL_PARSER_HAS_DLL == 1)
#  if defined (ETCL_PARSER_BUILD_DLL)
#    define ETCL_Parser_Export ACE_Proper_Export_Flag
#    define ETCL_PARSER_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ETCL_PARSER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ETCL_PARSER_BUILD_DLL */
#    define ETCL_Parser_Export ACE_Proper_Import_Flag
#    define ETCL_PARSER_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ETCL_PARSER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ETCL_PARSER_BUILD_DLL */
#else /* ETCL_PARSER_HAS_DLL == 1 */
#  define ETCL_Parser_Export
#  define ETCL_PARSER_SINGLETON_DECLARATION(T)
#  define ETCL_PARSER_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ETCL_PARSER_HAS_DLL == 1 */

#endif /* ETCL_PARSER_EXPORT_H */

// End of auto generated file.
