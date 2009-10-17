/**
 ** \file Ipv4Address.cpp
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
#include "Ipv4Address.h"
#include "Utility.h"
#include "Parse.h"
#ifndef _WIN32
#include <netdb.h>
#endif

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif

Ipv4Address::Ipv4Address(port_t port) : m_valid(true)
{
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons( port );
}

Ipv4Address::Ipv4Address(ipaddr_t a,port_t port) : m_valid(true)
{
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons( port );
    memcpy(&m_addr.sin_addr, &a, sizeof(struct in_addr));
}

Ipv4Address::Ipv4Address(struct in_addr& a,port_t port) : m_valid(true)
{
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons( port );
    m_addr.sin_addr = a;
}

Ipv4Address::Ipv4Address(const std::string& host,port_t port) : m_valid(false)
{
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons( port );
    {
        ipaddr_t a;
        if (Utility::u2ip(host, a))
        {
            memcpy(&m_addr.sin_addr, &a, sizeof(struct in_addr));
            m_valid = true;
        }
    }
}

Ipv4Address::Ipv4Address(struct sockaddr_in& sa)
{
    m_addr = sa;
    m_valid = sa.sin_family == AF_INET;
}

Ipv4Address::~Ipv4Address()
{
}

Ipv4Address::operator struct sockaddr *()
{
    return (struct sockaddr *)&m_addr;
}

Ipv4Address::operator socklen_t()
{
    return sizeof(struct sockaddr_in);
}

void Ipv4Address::SetPort(port_t port)
{
    m_addr.sin_port = htons( port );
}

port_t Ipv4Address::GetPort()
{
    return ntohs( m_addr.sin_port );
}

bool Ipv4Address::Resolve(const std::string& hostname,struct in_addr& a)
{
    struct sockaddr_in sa;
    memset(&a, 0, sizeof(a));
    if (Utility::isipv4(hostname))
    {
        if (!Utility::u2ip(hostname, sa, AI_NUMERICHOST))
            return false;
        a = sa.sin_addr;
        return true;
    }
    if (!Utility::u2ip(hostname, sa))
        return false;
    a = sa.sin_addr;
    return true;
}

bool Ipv4Address::Reverse(struct in_addr& a,std::string& name)
{
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr = a;
    return Utility::reverse((struct sockaddr *)&sa, sizeof(sa), name);
}

std::string Ipv4Address::Convert(bool include_port)
{
    if (include_port)
        return Convert(m_addr.sin_addr) + ":" + Utility::l2string(GetPort());
    return Convert(m_addr.sin_addr);
}

std::string Ipv4Address::Convert(struct in_addr& a)
{
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr = a;
    std::string name;
    Utility::reverse((struct sockaddr *)&sa, sizeof(sa), name, NI_NUMERICHOST);
    return name;
}

void Ipv4Address::SetAddress(struct sockaddr *sa)
{
    memcpy(&m_addr, sa, sizeof(struct sockaddr_in));
}

int Ipv4Address::GetFamily()
{
    return m_addr.sin_family;
}

bool Ipv4Address::IsValid()
{
    return m_valid;
}

bool Ipv4Address::operator==(SocketAddress& a)
{
    if (a.GetFamily() != GetFamily())
        return false;
    if ((socklen_t)a != sizeof(m_addr))
        return false;
    struct sockaddr *sa = a;
    struct sockaddr_in *p = (struct sockaddr_in *)sa;
    if (p -> sin_port != m_addr.sin_port)
        return false;
    if (memcmp(&p -> sin_addr, &m_addr.sin_addr, 4))
        return false;
    return true;
}

std::auto_ptr<SocketAddress> Ipv4Address::GetCopy()
{
    return std::auto_ptr<SocketAddress>(new Ipv4Address(m_addr));
}

std::string Ipv4Address::Reverse()
{
    std::string tmp;
    Reverse(m_addr.sin_addr, tmp);
    return tmp;
}

#ifdef SOCKETS_NAMESPACE
} // namespace SOCKETS_NAMESPACE {
#endif

