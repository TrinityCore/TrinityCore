/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   config-win32.h
 *
 *  $Id: config-win32.h 80826 2008-03-04 14:51:23Z wotte $
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
// by derex ,I include the win32 specific header here,
// this violates the idea of this file a bit ;)
#define ACE_HAS_REACTOR_NOTIFICATION_QUEUE
// Max amount of connections for non-epoll platforms
#ifndef FD_SETSIZE
  #define FD_SETSIZE 4096
#endif
//disable some deprecate warnings on windows
#ifndef _CRT_NONSTDC_NO_WARNINGS
  #define _CRT_NONSTDC_NO_WARNINGS
#endif
#ifndef _CRT_SECURE_NO_WARNINGS
  #define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _CRT_SECURE_NO_DEPRECATE
  #define _CRT_SECURE_NO_DEPRECATE
#endif
#ifndef _CRT_NONSTDC_NO_DEPRECATE
  #define _CRT_NONSTDC_NO_DEPRECATE
#endif
#ifndef _WINDOWS
  #define _WINDOWS
#endif
// end custom config stuff

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
#elif defined (ghs)
#    include "ace/config-win32-ghs.h"
#elif defined (__MINGW32__)
#    include "ace/config-win32-mingw.h"
#elif defined (__DMC__)
#    include "ace/config-win32-dmc.h"
#else
#    error Compiler is not supported
#endif
// gethostbyaddr does not handle IPv6-mapped-IPv4 addresses
#define ACE_HAS_BROKEN_GETHOSTBYADDR_V4MAPPED
// TODO remove this at some point when we add ACE::init and ACE::fini
// by derex
#ifdef ACE_HAS_NONSTATIC_OBJECT_MANAGER
#undef ACE_HAS_NONSTATIC_OBJECT_MANAGER
#endif //ACE_HAS_NONSTATIC_OBJECT_MANAGER

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_WIN32_H */

