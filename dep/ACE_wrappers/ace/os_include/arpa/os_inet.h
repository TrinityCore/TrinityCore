// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_inet.h
 *
 *  definitions for internet operations
 *
 *  $Id: os_inet.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_ARPA_OS_INET_H
#define ACE_OS_INCLUDE_ARPA_OS_INET_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/netinet/os_in.h"
#if !defined (ACE_LACKS_ARPA_INET_H)
   extern "C" {
#  include /**/ <arpa/inet.h>
   }
#endif /* !ACE_LACKS_ARPA_INET_H */
#if defined (ACE_VXWORKS)
#  include /**/ <inetLib.h>
#endif /* ACE_VXWORKS */
/**
 * In some environments it is useful to swap the bytes on write, for
 * instance: a fast server can be feeding a lot of slow clients that
 * happen to have the wrong byte order.
 * Because this is a rarely used feature we disable it by default to
 * minimize footprint.
 * This macro enables the functionality, but we still need a way to
 * activate it on a per-connection basis.
 */
// #define ACE_ENABLE_SWAP_ON_WRITE
/**
 * In some environements we never need to swap bytes when reading, for
 * instance embebbed systems (such as avionics) or homogenous
 * networks.
 * Setting this macro disables the capabilities to demarshall streams
 * in the wrong byte order.
 */
// #define ACE_DISABLE_SWAP_ON_READ
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#if defined (ACE_LACKS_INET_ATON_PROTOTYPE)
  int inet_aton (const char *, struct in_addr *);
#endif /* ACE_LACKS_INET_ATON_PROTOTYPE */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_ARPA_OS_INET_H */

