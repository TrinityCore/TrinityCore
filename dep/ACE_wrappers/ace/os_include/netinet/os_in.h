// -*- C++ -*-
//=============================================================================
/**
 *  @file    os_in.h
 *
 *  Internet address family
 *
 *  $Id: os_in.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================
#ifndef ACE_OS_INCLUDE_NETINET_OS_IN_H
#define ACE_OS_INCLUDE_NETINET_OS_IN_H
#include /**/ "ace/pre.h"
#include /**/ "ace/config-all.h"
#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */
#include "ace/os_include/os_inttypes.h"
#include "ace/os_include/sys/os_socket.h"
#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
#  include /**/ <ws2tcpip.h>
#endif /* ACE_HAS_WINSOCK2 */
#if !defined (ACE_LACKS_NETINET_IN_H)
#  if defined (ACE_HAS_STL_QUEUE_CONFLICT)
#    define queue _Queue_
#  endif /* ACE_HAS_STL_QUEUE_CONFLICT */
   extern "C" {
#  include /**/ <netinet/in.h>
   }
#  if defined (ACE_HAS_STL_QUEUE_CONFLICT)
#    undef queue
#  endif /* ACE_HAS_STL_QUEUE_CONFLICT */
#endif /* !ACE_LACKS_NETINET_IN_H */
// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
# if defined (ACE_HAS_PHARLAP_RT)
#   define ACE_IPPROTO_TCP SOL_SOCKET
# else
#   define ACE_IPPROTO_TCP IPPROTO_TCP
# endif /* ACE_HAS_PHARLAP_RT */
# if !defined (ACE_HAS_IP_MULTICAST)  &&  defined (ACE_LACKS_IP_ADD_MEMBERSHIP)
  // Even if ACE_HAS_IP_MULTICAST is not defined, if IP_ADD_MEMBERSHIP
  // is defined, assume that the ip_mreq struct is also defined
  // (presumably in netinet/in.h).
  struct ip_mreq
  {
    /// IP multicast address of group
    struct in_addr imr_multiaddr;
    /// Local IP address of interface
    struct in_addr imr_interface;
  };
# endif /* ! ACE_HAS_IP_MULTICAST  &&  ACE_LACKS_IP_ADD_MEMBERSHIP */
# if defined (ACE_LACKS_IN_ADDR)
  struct in_addr
    {
      u_long s_addr;
    };
# endif /* ACE_LACKS_IN_ADDR */
# if defined (ACE_LACKS_SOCKADDR_IN)
  struct sockaddr_in
  {
    short            sin_family;   // e.g. AF_INET
    unsigned short   sin_port;     // e.g. htons(3490)
    struct in_addr   sin_addr;     // see struct in_addr, below
    char             sin_zero[8];  // zero this if you want to
  };
# endif /* ACE_LACKS_SOCKADDR_IN */
# if defined (ACE_LACKS_SOCKADDR_UN)
  struct  sockaddr_un {
          u_char  sun_len;                /* sockaddr len including null */
          u_char  sun_family;             /* AF_UNIX */
          char    sun_path[104];          /* path name (gag) */
  };
#endif /* ACE_LACKS_SOCKADDR_UN */
# if defined (ACE_LACKS_IP_MREQ)
  struct ip_mreq
  {
    struct  in_addr imr_multiaddr;  /* IP multicast address of group */
    struct  in_addr imr_interface;  /* local IP address of interface */
  };
# endif /* ACE_LACKS_IP_MREQ */
#if !defined (IPPORT_RESERVED)
#  define IPPORT_RESERVED       1024
#endif /* !IPPORT_RESERVED */
#if !defined (IPPORT_USERRESERVED)
#  define IPPORT_USERRESERVED       5000
#endif /* !IPPORT_USERRESERVED */
// Define INET loopback address constant if it hasn't been defined
// Dotted Decimal 127.0.0.1 == Hexidecimal 0x7f000001
#if !defined (INADDR_LOOPBACK)
#  define INADDR_LOOPBACK ((ACE_UINT32) 0x7f000001)
#endif /* INADDR_LOOPBACK */
// The INADDR_NONE address is generally 255.255.255.255.
#if !defined (INADDR_NONE)
#  define INADDR_NONE ((ACE_UINT32) 0xffffffff)
#endif /* INADDR_NONE */
// Define INET string length constants if they haven't been defined
//
// for IPv4 dotted-decimal
#if !defined (INET_ADDRSTRLEN)
#  define INET_ADDRSTRLEN 16
#endif /* INET_ADDRSTRLEN */
//
// for IPv6 hex string
#if !defined (INET6_ADDRSTRLEN)
#  define INET6_ADDRSTRLEN 46
#endif /* INET6_ADDRSTRLEN */
# if !defined (IP_DROP_MEMBERSHIP)
#   define IP_DROP_MEMBERSHIP 0
# endif /* IP_DROP_MEMBERSHIP */
# if !defined (IP_ADD_MEMBERSHIP)
#   define IP_ADD_MEMBERSHIP 0
#   define ACE_LACKS_IP_ADD_MEMBERSHIP
# endif /* IP_ADD_MEMBERSHIP */
# if !defined (IP_DEFAULT_MULTICAST_TTL)
#   define IP_DEFAULT_MULTICAST_TTL 0
# endif /* IP_DEFAULT_MULTICAST_TTL */
# if !defined (IP_DEFAULT_MULTICAST_LOOP)
#   define IP_DEFAULT_MULTICAST_LOOP 0
# endif /* IP_DEFAULT_MULTICAST_LOOP */
# if !defined (IP_MULTICAST_IF)
#   define IP_MULTICAST_IF 0
# endif /* IP_MULTICAST_IF */
# if !defined (IP_MULTICAST_TTL)
#   define IP_MULTICAST_TTL 1
# endif /* IP_MULTICAST_TTL */
# if !defined (IP_MULTICAST_LOOP)
#   define IP_MULTICAST_LOOP 2
# endif /* IP_MULTICAST_LOOP */
# if !defined (IP_MAX_MEMBERSHIPS)
#   define IP_MAX_MEMBERSHIPS 0
# endif /* IP_MAX_MEMBERSHIP */
# if !defined (IPPROTO_IP)
#   define IPPROTO_IP 0
# endif /* IPPROTO_IP */
# if !defined (IPPROTO_TCP)
#   define IPPROTO_TCP 6
# endif /* IPPROTO_TCP */
# if !defined (INADDR_ANY)
#   define INADDR_ANY (u_long)0x00000000
# endif /* INADDR_ANY */
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_NETINET_OS_IN_H */

