//* -*- C++ -*- */
// $Id: config-vxworks6.8.h 96050 2012-08-14 22:22:54Z mitza $

// The following configuration file is designed to work for VxWorks
// 6.8 platforms using one of these compilers:
// 1) The GNU g++ compiler that is shipped with VxWorks 6.8
// 2) The Diab compiler that is shipped with VxWorks 6.8

#ifndef ACE_CONFIG_VXWORKS_6_8_H
#define ACE_CONFIG_VXWORKS_6_8_H
#include /**/ "ace/pre.h"

#if !defined (ACE_VXWORKS)
# define ACE_VXWORKS 0x680
#endif /* ! ACE_VXWORKS */

#include "ace/config-vxworks6.7.h"

#ifndef ACE_LACKS_RAND_R
# define ACE_LACKS_RAND_R 1
#endif

#ifndef __RTP__
# define ACE_LACKS_STD_WSTRING
#endif

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_6_8_H */

