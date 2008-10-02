/**
 **	\file Ipv6Address.h
 **	\date  2006-09-21
 **	\author grymse@alhem.net
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
#ifndef _SOCKETS_Ipv6Address_H
#define _SOCKETS_Ipv6Address_H
#include "sockets-config.h"
#ifdef ENABLE_IPV6

#include "SocketAddress.h"
#ifdef IPPROTO_IPV6
#if defined( _WIN32) && !defined(__CYGWIN__)
typedef unsigned __int32 uint32_t;
#endif

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


/** Ipv6 address implementation.
	\ingroup basic */
class Ipv6Address : public SocketAddress
{
public:
	/** Create empty Ipv6 address structure.
		\param port Port number */
	Ipv6Address(port_t port = 0);
	/** Create Ipv6 address structure.
		\param a Socket address in network byte order
		\param port Port number in host byte order */
	Ipv6Address(struct in6_addr& a,port_t port);
	/** Create Ipv6 address structure.
		\param host Hostname to be resolved
		\param port Port number in host byte order */
	Ipv6Address(const std::string& host,port_t port);
	Ipv6Address(struct sockaddr_in6&);
	~Ipv6Address();

	// SocketAddress implementation

	operator struct sockaddr *();
	operator socklen_t();
	bool operator==(SocketAddress&);

	void SetPort(port_t port);
	port_t GetPort();

	void SetAddress(struct sockaddr *sa);
	int GetFamily();

	bool IsValid();
	std::auto_ptr<SocketAddress> GetCopy();

	/** Convert address struct to text. */
	std::string Convert(bool include_port = false);
	std::string Reverse();

	/** Resolve hostname. */
static	bool Resolve(const std::string& hostname,struct in6_addr& a);
	/** Reverse resolve (IP to hostname). */
static	bool Reverse(struct in6_addr& a,std::string& name);
	/** Convert address struct to text. */
static	std::string Convert(struct in6_addr& a,bool mixed = false);

	void SetFlowinfo(uint32_t);
	uint32_t GetFlowinfo();
#ifndef _WIN32
	void SetScopeId(uint32_t);
	uint32_t GetScopeId();
#endif

private:
	Ipv6Address(const Ipv6Address& ) {} // copy constructor
	Ipv6Address& operator=(const Ipv6Address& ) { return *this; } // assignment operator
	struct sockaddr_in6 m_addr;
	bool m_valid;
};




#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE {
#endif
#endif // IPPROTO_IPV6
#endif // ENABLE_IPV6
#endif // _SOCKETS_Ipv6Address_H

