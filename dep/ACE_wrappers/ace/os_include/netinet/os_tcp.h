// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_tcp.h
 *
 *  definitions for the Internet Transmission Control Protocol (TCP)
 *
 *  $Id: os_tcp.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_NETINET_OS_TCP_H
#define ACE_OS_INCLUDE_NETINET_OS_TCP_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_NETINET_TCP_H)
# include /**/ <netinet/tcp.h>
#endif /* !ACE_LACKS_NETIINET_TCP_H */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

# if !defined (TCP_NODELAY)
#   define TCP_NODELAY 0x01
# endif /* TCP_NODELAY */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_NETINET_OS_TCP_H */
