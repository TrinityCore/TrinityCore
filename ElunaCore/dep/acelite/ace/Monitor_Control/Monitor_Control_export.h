// -*- C++ -*-

//=============================================================================
/**
 *  @file    Monitor_Control_export.h
 *
 *  $Id: Monitor_Control_export.h 81753 2008-05-21 19:02:47Z parsons $
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 */
//=============================================================================

// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl
// ------------------------------
#ifndef MONITOR_CONTROL_EXPORT_H
#define MONITOR_CONTROL_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS)
# if !defined (MONITOR_CONTROL_HAS_DLL)
#   define MONITOR_CONTROL_HAS_DLL 0
# endif /* ! MONITOR_CONTROL_HAS_DLL */
#else
# if !defined (MONITOR_CONTROL_HAS_DLL)
#   define MONITOR_CONTROL_HAS_DLL 1
# endif /* ! MONITOR_CONTROL_HAS_DLL */
#endif /* ACE_AS_STATIC_LIB */

#if defined (MONITOR_CONTROL_HAS_DLL) && (MONITOR_CONTROL_HAS_DLL == 1)
#  if defined (MONITOR_CONTROL_BUILD_DLL)
#    define MONITOR_CONTROL_Export ACE_Proper_Export_Flag
#    define MONITOR_CONTROL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define MONITOR_CONTROL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* MONITOR_CONTROL_BUILD_DLL */
#    define MONITOR_CONTROL_Export ACE_Proper_Import_Flag
#    define MONITOR_CONTROL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define MONITOR_CONTROL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* MONITOR_CONTROL_BUILD_DLL */
#else /* MONITOR_CONTROL_HAS_DLL == 1 */
#  define MONITOR_CONTROL_Export
#  define MONITOR_CONTROL_SINGLETON_DECLARATION(T)
#  define MONITOR_CONTROL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* MONITOR_CONTROL_HAS_DLL == 1 */

#endif /* MONITOR_CONTROL_EXPORT_H */

// End of auto generated file.
