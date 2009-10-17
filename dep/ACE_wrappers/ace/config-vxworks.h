//* -*- C++ -*- */
// $Id: config-vxworks.h 81046 2008-03-21 10:11:12Z johnnyw $
// The following configuration file is designed to work for VxWorks
// Based on ACE_VXWORKS it will select the correct config file
#ifndef ACE_CONFIG_VXWORKS_H
#define ACE_CONFIG_VXWORKS_H
#include /**/ "ace/pre.h"
// If ACE_VXWORKS is not defined try to figure out the VxWorks version
#if !defined (ACE_VXWORKS)
# include "vxWorks.h"
# if !defined (_WRS_VXWORKS_MAJOR) && !defined (_WRS_VXWORKS_MINOR)
#  error You must define ACE_VXWORKS
# else
#  if (_WRS_VXWORKS_MAJOR == 6)
#   if (_WRS_VXWORKS_MINOR == 0)
#    define ACE_VXWORKS 0x600
#   elif (_WRS_VXWORKS_MINOR == 1)
#    define ACE_VXWORKS 0x610
#   elif (_WRS_VXWORKS_MINOR == 2)
#    define ACE_VXWORKS 0x620
#   elif (_WRS_VXWORKS_MINOR == 3)
#    define ACE_VXWORKS 0x630
#   elif (_WRS_VXWORKS_MINOR == 4)
#    define ACE_VXWORKS 0x640
#   elif (_WRS_VXWORKS_MINOR == 5)
#    define ACE_VXWORKS 0x650
#   elif (_WRS_VXWORKS_MINOR == 6)
#    define ACE_VXWORKS 0x660
#   endif
#  endif
# endif
#endif /* ! ACE_VXWORKS */
#if (ACE_VXWORKS == 0x551)
# include "ace/config-vxworks5.x.h"
#elif (ACE_VXWORKS == 0x620)
# include "ace/config-vxworks6.2.h"
#elif (ACE_VXWORKS == 0x630)
# include "ace/config-vxworks6.3.h"
#elif (ACE_VXWORKS == 0x640)
# include "ace/config-vxworks6.4.h"
#elif (ACE_VXWORKS == 0x650)
# include "ace/config-vxworks6.5.h"
#elif (ACE_VXWORKS == 0x660)
# include "ace/config-vxworks6.6.h"
#else
#error Unknown VxWorks version
#endif
#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_H */

