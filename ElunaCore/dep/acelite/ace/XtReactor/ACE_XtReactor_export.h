
// -*- C++ -*-
// $Id: ACE_XtReactor_export.h 80826 2008-03-04 14:51:23Z wotte $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl -s ACE_XtReactor
// ------------------------------
#ifndef ACE_XTREACTOR_EXPORT_H
#define ACE_XTREACTOR_EXPORT_H

#include /**/ "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (ACE_XTREACTOR_HAS_DLL)
#  define ACE_XTREACTOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && ACE_XTREACTOR_HAS_DLL */

#if !defined (ACE_XTREACTOR_HAS_DLL)
#  define ACE_XTREACTOR_HAS_DLL 1
#endif /* ! ACE_XTREACTOR_HAS_DLL */

#if defined (ACE_XTREACTOR_HAS_DLL) && (ACE_XTREACTOR_HAS_DLL == 1)
#  if defined (ACE_XTREACTOR_BUILD_DLL)
#    define ACE_XtReactor_Export ACE_Proper_Export_Flag
#    define ACE_XTREACTOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define ACE_XTREACTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* ACE_XTREACTOR_BUILD_DLL */
#    define ACE_XtReactor_Export ACE_Proper_Import_Flag
#    define ACE_XTREACTOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define ACE_XTREACTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* ACE_XTREACTOR_BUILD_DLL */
#else /* ACE_XTREACTOR_HAS_DLL == 1 */
#  define ACE_XtReactor_Export
#  define ACE_XTREACTOR_SINGLETON_DECLARATION(T)
#  define ACE_XTREACTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* ACE_XTREACTOR_HAS_DLL == 1 */

// Set ACE_XTREACTOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (ACE_XTREACTOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define ACE_XTREACTOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define ACE_XTREACTOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !ACE_XTREACTOR_NTRACE */

#if (ACE_XTREACTOR_NTRACE == 1)
#  define ACE_XTREACTOR_TRACE(X)
#else /* (ACE_XTREACTOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define ACE_XTREACTOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (ACE_XTREACTOR_NTRACE == 1) */

#endif /* ACE_XTREACTOR_EXPORT_H */

// End of auto generated file.
