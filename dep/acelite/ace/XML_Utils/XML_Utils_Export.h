
// -*- C++ -*-
// $Id: XML_Utils_Export.h 95760 2012-05-15 13:46:19Z msmit $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl XML_Utils
// ------------------------------
#ifndef XML_UTILS_EXPORT_H
#define XML_UTILS_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (XML_UTILS_HAS_DLL)
#  define XML_UTILS_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && XML_UTILS_HAS_DLL */

#if !defined (XML_UTILS_HAS_DLL)
#  define XML_UTILS_HAS_DLL 1
#endif /* ! XML_UTILS_HAS_DLL */

#if defined (XML_UTILS_HAS_DLL) && (XML_UTILS_HAS_DLL == 1)
#  if defined (XML_UTILS_BUILD_DLL)
#    define XML_Utils_Export ACE_Proper_Export_Flag
#    define XML_UTILS_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define XML_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* XML_UTILS_BUILD_DLL */
#    define XML_Utils_Export ACE_Proper_Import_Flag
#    define XML_UTILS_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define XML_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* XML_UTILS_BUILD_DLL */
#else /* XML_UTILS_HAS_DLL == 1 */
#  define XML_Utils_Export
#  define XML_UTILS_SINGLETON_DECLARATION(T)
#  define XML_UTILS_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* XML_UTILS_HAS_DLL == 1 */

// Set XML_UTILS_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (XML_UTILS_NTRACE)
#  if (ACE_NTRACE == 1)
#    define XML_UTILS_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define XML_UTILS_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !XML_UTILS_NTRACE */

#if (XML_UTILS_NTRACE == 1)
#  define XML_UTILS_TRACE(X)
#else /* (XML_UTILS_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define XML_UTILS_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (XML_UTILS_NTRACE == 1) */

#endif /* XML_UTILS_EXPORT_H */

// End of auto generated file.
