//* -*- C++ -*- */
// $Id: config-vxworks6.6.h 85143 2009-04-22 09:15:08Z johnnyw $

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
# define ACE_HAS_TASKCPUAFFINITYSET
#endif

#define ACE_HAS_VXATOMICLIB
#define ACE_HAS_CPUSET_T
#define ACE_HAS_VXCPULIB

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_6_6_H */

