
// -*- C++ -*-
// $Id: ACE_Compression_export.h 95545 2012-02-23 07:57:08Z johnnyw $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl ACE_Compression
// ------------------------------
#ifndef ACE_COMPRESSION_EXPORT_H
#define ACE_COMPRESSION_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ACE_COMPRESSION_HAS_DLL)
#  define ACE_COMPRESSION_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ACE_COMPRESSION_HAS_DLL */

#if !defined (ACE_COMPRESSION_HAS_DLL)
#  define ACE_COMPRESSION_HAS_DLL 1
#endif /* ! ACE_COMPRESSION_HAS_DLL */

#if defined (ACE_COMPRESSION_HAS_DLL) && (ACE_COMPRESSION_HAS_DLL == 1)
#  if defined (ACE_COMPRESSION_BUILD_DLL)
#    define ACE_Compression_Export ACE_Proper_Export_Flag
#    define ACE_COMPRESSION_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ACE_COMPRESSION_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ACE_COMPRESSION_BUILD_DLL */
#    define ACE_Compression_Export ACE_Proper_Import_Flag
#    define ACE_COMPRESSION_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ACE_COMPRESSION_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ACE_COMPRESSION_BUILD_DLL */
#else /* ACE_COMPRESSION_HAS_DLL == 1 */
#  define ACE_Compression_Export
#  define ACE_COMPRESSION_SINGLETON_DECLARATION(T)
#  define ACE_COMPRESSION_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ACE_COMPRESSION_HAS_DLL == 1 */

// Set ACE_COMPRESSION_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ACE_COMPRESSION_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ACE_COMPRESSION_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ACE_COMPRESSION_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ACE_COMPRESSION_NTRACE */

#if (ACE_COMPRESSION_NTRACE == 1)
#  define ACE_COMPRESSION_TRACE(X)
#else /* (ACE_COMPRESSION_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ACE_COMPRESSION_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ACE_COMPRESSION_NTRACE == 1) */

#endif /* ACE_COMPRESSION_EXPORT_H */

// End of auto generated file.
