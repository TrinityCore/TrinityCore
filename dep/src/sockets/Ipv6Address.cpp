/**
 **	\file Ipv6Address.cpp
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
#include "Ipv6Address.h"
#ifdef ENABLE_IPV6

#include "Utility.h"
#include "Parse.h"
#ifndef _WIN32
#include <netdb.h>
#endif
#ifdef IPPROTO_IPV6

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif


Ipv6Address::Ipv6Address(port_t port) : m_valid(true)
{
	memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin6_family = AF_INET6;
	m_addr.sin6_port = htons( port );
}


Ipv6Address::Ipv6Address(struct in6_addr& a,port_t port) : m_valid(true)
{
	memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin6_family = AF_INET6;
	m_addr.sin6_port = htons( port );
	m_addr.sin6_addr = a;
}


Ipv6Address::Ipv6Address(const std::string& host,port_t port) : m_valid(false)
{
	memset(&m_addr, 0, sizeof(m_addr));
	m_addr.sin6_family = AF_INET6;
	m_addr.sin6_port = htons( port );
	{
		struct in6_addr a;
		if (Utility::u2ip(host, a))
		{
			m_addr.sin6_addr = a;
			m_valid = true;
		}
	}
}


Ipv6Address::Ipv6Address(struct sockaddr_in6& sa)
{
	m_addr = sa;
	m_valid = sa.sin6_family == AF_INET6;
}


Ipv6Address::~Ipv6Address()
{
}


Ipv6Address::operator struct sockaddr *()
{
	return (struct sockaddr *)&m_addr;
}


Ipv6Address::operator socklen_t()
{
	return sizeof(struct sockaddr_in6);
}


void Ipv6Address::SetPort(port_t port)
{
	m_addr.sin6_port = htons( port );
}


port_t Ipv6Address::GetPort()
{
	return ntohs( m_addr.sin6_port );
}


bool Ipv6Address::Resolve(const std::string& hostname,struct in6_addr& a)
{
	struct sockaddr_in6 sa;
	memset(&a, 0, sizeof(a));
	if (Utility::isipv6(hostname))
	{
		if (!Utility::u2ip(hostname, sa, AI_NUMERICHOST))
			return false;
		a = sa.sin6_addr;
		return true;
	}
	if (!Utility::u2ip(hostname, sa))
		return false;
	a = sa.sin6_addr;
	return true;
}


bool Ipv6Address::Reverse(struct in6_addr& a,std::string& name)
{
	struct sockaddr_in6 sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin6_family = AF_INET6;
	sa.sin6_addr = a;
	return Utility::reverse((struct sockaddr *)&sa, sizeof(sa), name);
}


std::string Ipv6Address::Convert(bool include_port)
{
	if (include_port)
		return Convert(m_addr.sin6_addr) + ":" + Utility::l2string(GetPort());
	return Convert(m_addr.sin6_addr);
}


std::string Ipv6Address::Convert(struct in6_addr& a,bool mixed)
{
	char slask[100]; // l2ip temporary
	*slask = 0;
	unsigned int prev = 0;
	bool skipped = false;
	bool ok_to_skip = true;
	if (mixed)
	{
		unsigned short x;
		unsigned short addr16[8];
		memcpy(addr16, &a, sizeof(addr16));
		for (size_t i = 0; i < 6; i++)
		{
			x = ntohs(addr16[i]);
			if (*slask && (x || !ok_to_skip || prev))
				strcat(slask,":");
			if (x || !ok_to_skip)
			{
				sprintf(slask + strlen(slask),"%x", x);
				if (x && skipped)
					ok_to_skip = false;
			}
			else
			{
				skipped = true;
			}
			prev = x;
		}
		x = ntohs(addr16[6]);
		sprintf(slask + strlen(slask),":%u.%u",x / 256,x & 255);
		x = ntohs(addr16[7]);
		sprintf(slask + strlen(slask),".%u.%u",x / 256,x & 255);
	}
	else
	{
		struct sockaddr_in6 sa;
		memset(&sa, 0, sizeof(sa));
		sa.sin6_family = AF_INET6;
		sa.sin6_addr = a;
		std::string name;
		Utility::reverse((struct sockaddr *)&sa, sizeof(sa), name, NI_NUMERICHOST);
		return name;
	}
	return slask;
}


void Ipv6Address::SetAddress(struct sockaddr *sa)
{
	memcpy(&m_addr, sa, sizeof(struct sockaddr_in6));
}


int Ipv6Address::GetFamily()
{
	return m_addr.sin6_family;
}


void Ipv6Address::SetFlowinfo(uint32_t x)
{
	m_addr.sin6_flowinfo = x;
}


uint32_t Ipv6Address::GetFlowinfo()
{
	return m_addr.sin6_flowinfo;
}


#ifndef _WIN32
void Ipv6Address::SetScopeId(uint32_t x)
{
	m_addr.sin6_scope_id = x;
}


uint32_t Ipv6Address::GetScopeId()
{
	return m_addr.sin6_scope_id;
}
#endif


bool Ipv6Address::IsValid()
{
	return m_valid;
}


bool Ipv6Address::operator==(SocketAddress& a)
{
	if (a.GetFamily() != GetFamily())
		return false;
	if ((socklen_t)a != sizeof(m_addr))
		return false;
	struct sockaddr *sa = a;
	struct sockaddr_in6 *p = (struct sockaddr_in6 *)sa;
	if (p -> sin6_port != m_addr.sin6_port)
		return false;
	if (memcmp(&p -> sin6_addr, &m_addr.sin6_addr, sizeof(struct in6_addr)))
		return false;
	return true;
}


std::auto_ptr<SocketAddress> Ipv6Address::GetCopy()
{
	return std::auto_ptr<SocketAddress>(new Ipv6Address(m_addr));
}


std::string Ipv6Address::Reverse()
{
	std::string tmp;
	Reverse(m_addr.sin6_addr, tmp);
	return tmp;
}


#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE {
#endif
#endif // IPPROTO_IPV6
#endif // ENABLE_IPV6

