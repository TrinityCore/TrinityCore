//* -*- C++ -*- */
// $Id: config-vxworks6.6.h 80826 2008-03-04 14:51:23Z wotte $

// The following configuration file is designed to work for VxWorks
// 6.6 platforms using one of these compilers:
// 1) The GNU g++ compiler that is shipped with VxWorks 6.6
// 2) The Diab compiler that is shipped with VxWorks 6.6

#ifndef ACE_CONFIG_VXWORKS_6_6_H
#define ACE_CONFIG_VXWORKS_6_6_H
#include /**/ "ace/pre.h"

#if !defined (ACE_VXWORKS)
# define ACE_VXWORKS 0x660
#endif /* ! ACE_VXWORKS */

#include "ace/config-vxworks6.5.h"

#if defined (ACE_HAS_PENTIUM)
# define ACE_LACKS_LOG2
#endif

#if !defined (__RTP__)
# undef ACE_HAS_IOCTL_INT_3_PARAM
#endif

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_6_6_H */


