//* -*- C++ -*- */
// $Id: config-vxworks6.8.h 87036 2009-10-10 18:21:39Z johnnyw $

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

#include /**/ "ace/post.h"
#endif /* ACE_CONFIG_VXWORKS_6_8_H */

