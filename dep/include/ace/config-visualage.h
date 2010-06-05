/* -*- C++ -*- */
// $Id: config-visualage.h 80826 2008-03-04 14:51:23Z wotte $

// This configuration file automatically includes the proper
// configurations for IBM's VisualAge C++ compiler on Win32 and AIX.

#ifndef CONFIG_VISUALAGE_H
#define CONFIG_VISUALAGE_H
#include /**/ "ace/pre.h"

#ifdef __TOS_WIN__
   #include "ace/config-win32.h"
#elif __TOS_AIX__
   #include "ace/config-aix-4.x.h"
#else
   #include "PLATFORM NOT SPECIFIED"
#endif /* __TOS_WIN__ */

#include /**/ "ace/post.h"
#endif //CONFIG_VISUALAGE_H

