// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_ifaddrs.h
 *
 *  os_ifaddrs.h include
 *
 *  $Id: os_ifaddrs.h 93622 2011-03-22 15:45:57Z johnnyw $
 *
 *  @author Johnny Willemsen  <jwillemsen@remedy.nl>
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_OS_IFADDRS_H
#define ACE_OS_INCLUDE_OS_IFADDRS_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if defined (ACE_VXWORKS)
#  include /**/ <net/ifaddrs.h>
#else
#  include /**/ <ifaddrs.h>
#endif /*ACE_VXWORKS */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_OS_IFADDRS_H */
