/* -*- C++ -*- */
// $Id: config-irix6.x-sgic++.h 81935 2008-06-12 22:01:53Z jtc $
// Use this file for IRIX 6.[234] if you have the pthreads patches
// installed.
#ifndef ACE_CONFIG_H
#define ACE_CONFIG_H
#include /**/ "ace/pre.h"
#include "ace/config-irix6.x-common.h"
// This is the config file for IRIX 6.2, 6.4 and hopefully 6.3, using
// the SGI C++ compiler (7.1 or higher).
// The following three should be enabled/disabled together.
#if _COMPILER_VERSION < 720
#define ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA
#endif /* _COMPILER_VERSION < 720 */
#define ACE_TEMPLATES_REQUIRE_SOURCE
#define ACE_NEEDS_FUNC_DEFINITIONS
// Platform supports STREAM pipes (note that this is disabled by
// default, see the manual page on pipe(2) to find out how to enable
// it).
// #define ACE_HAS_STREAM_PIPES
#if defined (_COMPILER_VERSION)
# define ACE_CC_NAME ACE_TEXT ("SGI/MIPSPro")
# define ACE_CC_MAJOR_VERSION (_COMPILER_VERSION / 100)
# define ACE_CC_MINOR_VERSION (_COMPILER_VERSION % 100)
# define ACE_CC_BETA_VERSION  (0)
#endif /* _COMPILER_VERSION */
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_H */

