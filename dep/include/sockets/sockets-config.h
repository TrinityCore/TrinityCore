/**
 ** \file sockets-config.h
 ** \date  2007-04-14
 ** \author grymse@alhem.net
**/
/*
Copyright (C) 2007  Anders Hedstrom

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef _SOCKETS_CONFIG_H
#define _SOCKETS_CONFIG_H

#ifndef _RUN_DP
/* First undefine symbols if already defined. */
#undef HAVE_OPENSSL
#undef ENABLE_IPV6
#undef USE_SCTP
#undef NO_GETADDRINFO
#undef ENABLE_POOL
#undef ENABLE_SOCKS4
#undef ENABLE_RESOLVER
#undef ENABLE_RECONNECT
#undef ENABLE_DETACH
#undef ENABLE_TRIGGERS
#undef ENABLE_EXCEPTIONS
#endif // _RUN_DP

// define MACOSX for internal socket library checks
#if defined(__APPLE__) && defined(__MACH__) && !defined(MACOSX)
#define MACOSX
#endif

/* OpenSSL support. */
//#define HAVE_OPENSSL


/* Ipv6 support. */
//#define ENABLE_IPV6


/* SCTP support. */
//#define USE_SCTP


/* Define NO_GETADDRINFO if your operating system does not support
   the "getaddrinfo" and "getnameinfo" function calls. */
#define NO_GETADDRINFO


/* Connection pool support. */
#define ENABLE_POOL


/* Socks4 client support. */
//#define ENABLE_SOCKS4


/* Asynchronous resolver. */
#define ENABLE_RESOLVER


/* Enable TCP reconnect on lost connection.
    Socket::OnReconnect
    Socket::OnDisconnect
*/
#define ENABLE_RECONNECT


/* Enable socket thread detach functionality. */
#define ENABLE_DETACH


/* Enable socket to socket triggers. Not yet in use. */
//#define ENABLE_TRIGGERS


/* Enabled exceptions. */
//#define ENABLE_EXCEPTIONS


/* Resolver uses the detach function so either enable both or disable both. */
#ifndef ENABLE_DETACH
#undef ENABLE_RESOLVER
#endif


#endif // _SOCKETS_CONFIG_H


