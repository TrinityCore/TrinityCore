/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   config-win32.h
 *
 *  $Id: config-win32.h 92120 2010-10-01 12:00:01Z johnnyw $
 *
 *  @brief  Microsoft Windows configuration file.
 *
 *  This file is the ACE configuration file for all of Microsoft Windows
 *  platforms that ACE runs on.  Based on preprocessor definitions, it
 *  includes other more specific configuration files.
 *
 *  @author Darrell Brunsch <brunsch@cs.wustl.edu>
 */
//=============================================================================

#ifndef ACE_CONFIG_WIN32_H
#define ACE_CONFIG_WIN32_H
#include /**/ "ace/pre.h"

// NOTE: Please do not add anything besides #include's here.  Put other stuff
//       (definitions, etc.) in the included headers

// We need to ensure that for Borland vcl.h can be included before
// windows.h.  So we will not include config-win32-common.h from here,
// but instead let it be included at the appropriate place in
// config-win32-borland.h.
#if !defined (__BORLANDC__)
#    include "ace/config-win32-common.h"
#endif /* !__BORLANDC__ */

// Include the config-win32-* file specific to the compiler
#if defined (__BORLANDC__)
#    include "ace/config-win32-borland.h"
#elif defined (_MSC_VER)
#    include "ace/config-win32-msvc.h"
#elif defined (ACE_HAS_CEGCC) //need to be prior to MINGW32
#    include "ace/config-win32-cegcc.h"
#elif defined (__MINGW32__)
#    include "ace/config-win32-mingw.h"
#elif defined (__DMC__)
#    include "ace/config-win32-dmc.h"
#else
#    error Compiler is not supported
#endif

// gethostbyaddr does not handle IPv6-mapped-IPv4 addresses
#define ACE_HAS_BROKEN_GETHOSTBYADDR_V4MAPPED

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_H */

