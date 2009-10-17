/**
 ** \file SocketAddress.h
 ** \date  2006-09-21
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
#ifndef _SOCKETS_SocketAddress_H
#define _SOCKETS_SocketAddress_H

#include "sockets-config.h"
#include <string>
#include <memory>
#include "socket_include.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


/**
   This class and its subclasses is intended to be used as replacement
   for the internal data type 'ipaddr_t' and various implementations of
   IPv6 addressing found throughout the library.
   'ipaddr_t' is an IPv4 address in network byte order.
   'port_t' is the portnumber in host byte order.
   'struct in6_addr' is an IPv6 address.
   'struct in_addr' is an IPv4 address.
   \ingroup basic
*/
class SocketAddress
{
public:
    virtual ~SocketAddress() {}

    /** Get a pointer to the address struct. */
    virtual operator struct sockaddr *() = 0;

    /** Get length of address struct. */
    virtual operator socklen_t() = 0;

    /** Compare two addresses. */
    virtual bool operator==(SocketAddress&) = 0;

    /** Set port number.
        \param port Port number in host byte order */
    virtual void SetPort(port_t port) = 0;

    /** Get port number.
        \return Port number in host byte order. */
    virtual port_t GetPort() = 0;

    /** Set socket address.
        \param sa Pointer to either 'struct sockaddr_in' or 'struct sockaddr_in6'. */
    virtual void SetAddress(struct sockaddr *sa) = 0;

    /** Convert address to text. */
    virtual std::string Convert(bool include_port) = 0;

    /** Reverse lookup of address. */
    virtual std::string Reverse() = 0;

    /** Get address family. */
    virtual int GetFamily() = 0;

    /** Address structure is valid. */
    virtual bool IsValid() = 0;

    /** Get a copy of this SocketAddress object. */
    virtual std::auto_ptr<SocketAddress> GetCopy() = 0;
};




#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE {
#endif
#endif // _SOCKETS_SocketAddress_H


