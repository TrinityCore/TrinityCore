// -*- C++ -*-

//=============================================================================
/**
 *  @file    os_if.h
 *
 *  sockets local interfaces
 *
 *  $Id: os_if.h 80826 2008-03-04 14:51:23Z wotte $
 *
 *  @author Don Hinton <dhinton@dresystems.com>
 *  @author This code was originally in various places including ace/OS.h.
 */
//=============================================================================

#ifndef ACE_OS_INCLUDE_NET_OS_IF_H
#define ACE_OS_INCLUDE_NET_OS_IF_H

#include /**/ "ace/pre.h"

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (ACE_LACKS_NET_IF_H)
   // This part if to avoid STL name conflict with the map structure
   // in net/if.h.
#  if defined (ACE_HAS_STL_MAP_CONFLICT)
#    define map _Resource_Allocation_Map_
#  endif /* ACE_HAS_STL_MAP_CONFLICT */
   extern "C" {
#  include /**/ <net/if.h>
   }
#  if defined (ACE_HAS_STL_MAP_CONFLICT)
#    undef map
#  endif /* ACE_HAS_STL_MAP_CONFLICT */
#  if defined (HPUX) && defined (IOR)
   /* HP-UX 11.11 defines IOR in /usr/include/pa/inline.h
      and we don't want that definition.  See IOP_IORC.h.
      Thanks to Torsten Kopper <tkue_0931@fastmail.fm> for this patch.*/
#    undef IOR
#  endif /* HPUX && IOR */
#endif /* !ACE_LACKS_NET_IF_H */

#if defined (ACE_HAS_WINSOCK2) && (ACE_HAS_WINSOCK2 != 0)
#  include /**/ <ws2tcpip.h>
#endif /* ACE_HAS_WINSOCK2 */

// Place all additions (especially function declarations) within extern "C" {}
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#if defined (ACE_HAS_BROKEN_IF_HEADER)
   struct ifafilt;
#endif /* ACE_HAS_BROKEN_IF_HEADER */

#if defined (ACE_LACKS_IFREQ)
struct  ifreq {
#define IFNAMSIZ        16
        char    ifr_name[IFNAMSIZ];             /* if name, e.g. "en0" */
        union {
                struct  sockaddr ifru_addr;
                struct  sockaddr ifru_dstaddr;
                struct  sockaddr ifru_broadaddr;
                short   ifru_flags;
                int     ifru_metric;
                int     ifru_mtu;
                int     ifru_phys;
                int     ifru_media;
                caddr_t ifru_data;
                int     (*ifru_tap)(struct ifnet *, struct ether_header *, struct mbuf *);
        } ifr_ifru;
#define ifr_addr        ifr_ifru.ifru_addr      /* address */
#define ifr_dstaddr     ifr_ifru.ifru_dstaddr   /* other end of p-to-p link */
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr /* broadcast address */
#define ifr_flags       ifr_ifru.ifru_flags     /* flags */
#define ifr_metric      ifr_ifru.ifru_metric    /* metric */
#define ifr_mtu         ifr_ifru.ifru_mtu       /* mtu */
#define ifr_phys        ifr_ifru.ifru_phys      /* physical wire */
#define ifr_media       ifr_ifru.ifru_media     /* physical media */
#define ifr_data        ifr_ifru.ifru_data      /* for use by interface */
#define ifr_tap         ifr_ifru.ifru_tap       /* tap function */
};
#endif /* ACE_LACKS_IFREQ */

#if defined (ACE_LACKS_IFCONF)
struct  ifconf {
        int     ifc_len;
        union {
                caddr_t ifcu_buf;
                struct  ifreq *ifcu_req;
        } ifc_ifcu;
#define ifc_buf ifc_ifcu.ifcu_buf       /* buffer address */
#define ifc_req ifc_ifcu.ifcu_req       /* array of structures returned */
        };
#endif /* ACE_LACKS_IFCONF */

#if !defined (IFF_UP)
# define IFF_UP 0x1
#endif /* IFF_UP */

#if !defined (IFF_LOOPBACK)
# define IFF_LOOPBACK 0x8
#endif /* IFF_LOOPBACK */

#if !defined (IFF_BROADCAST)
# define IFF_BROADCAST 0x2
#endif /* IFF_BROADCAST */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#include /**/ "ace/post.h"
#endif /* ACE_OS_INCLUDE_NET_OS_IF_H */

